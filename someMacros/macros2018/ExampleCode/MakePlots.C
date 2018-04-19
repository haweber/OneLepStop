#include "TList.h"
#include "TMath.h"
#include "TString.h"
#include "TObject.h"
#include "TFile.h"
#include "TPad.h"
#include "TDirectory.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TH3F.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMap.h"
#include "TStopwatch.h"
#include "TColor.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLine.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <cmath>

using namespace std;

//this function uses the histograms created with ExampleLooper.C and puts them into pretty plots
void MakePlots(){
    
  bool  logy   = true; //should the y axis being plotted in logarithmic scale (true) or linear scale (false)
  bool  data   = false;//set this to false - we don't look at data
  float lumi   = 150.; //check what luminosity was put into the weight in ExampleLooper
  bool  addgen = true; //average reco and genMET signal samples

  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
    
  map<string, TH1F*> hist;
  map<string, THStack*> stack;
  vector<string> histonames;
  vector<string> histox;
  vector<string> selecttitle;
  vector<string> bgnames;
  vector<string> signames;
  vector<string> bgleg;
  vector<string> sigleg;
  vector<Color_t> bgcol;
  vector<Color_t> sigcol;
  //get all the histograms and how to display the axis label  - to do: display selection
  histonames.push_back("MT_NJge2");               histox.push_back("M_{T} [GeV]");          selecttitle.push_back("#geq2 jets");
  histonames.push_back("MT_NJge4_METge250");      histox.push_back("M_{T} [GeV]");          selecttitle.push_back("#geq4 jets, p_{T}^{miss} #geq 250 GeV");
  histonames.push_back("MinDeltaRLepJet_NJge2");  histox.push_back("min#DeltaR(jet,lep)");  selecttitle.push_back("#geq2 jets");
  histonames.push_back("SignalRegionYields");     histox.push_back("signal region");        selecttitle.push_back("");

  //define background samples and its style color
  bgnames.push_back("LostLepton"); bgleg.push_back("Lost lepton");                bgcol.push_back(kCyan-3);
  bgnames.push_back("TT1l");       bgleg.push_back("1#font[12]{l} from top");     bgcol.push_back(kRed-7);
  bgnames.push_back("WJets");      bgleg.push_back("1#font[12]{l} not from top"); bgcol.push_back(kOrange-2);
  bgnames.push_back("Znunu");      bgleg.push_back("Z#rightarrow#nu#bar{#nu}");   bgcol.push_back(kMagenta-5);

  //define signal samples (to be coded - how to average SignalGen into them) and its style color
  signames.push_back("Signal_T2tt_Wcorridor");       sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (W corridor)");       sigcol.push_back(kGreen+2);
  signames.push_back("Signal_T2tt_topcorridor");     sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (t corridor)");       sigcol.push_back(kBlue+1);
  signames.push_back("Signal_T2tt_betweencorridor"); sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (between corridor)"); sigcol.push_back(kYellow+1);
  signames.push_back("Signal_T2tt_highDM");          sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (above corridor)");   sigcol.push_back(kMagenta+1);

  //this is the rootfile containing the histograms
  TFile *f = new TFile("rootfiles/Examplefile.root","READ");

  for(unsigned int i = 0; i<histonames.size(); ++i) {
    //first get histogram and set still for plotting (like color for each background sample)
    if(data){
      string mapname = histonames[i] + "_Data";
      hist[mapname] = (TH1F*)f->Get(mapname.c_str());//get histogram
      hist[mapname]->SetLineWidth(2);
      hist[mapname]->SetLineColor(kBlack);
      hist[mapname]->SetMarkerStyle(20);
      hist[mapname]->SetMarkerColor(kBlack);
      hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
    }
    for(unsigned int b = 0; b<bgnames.size();++b){
      string mapname = histonames[i] + "_" + bgnames[b];
      hist[mapname] = (TH1F*)f->Get(mapname.c_str());//get histogram
      hist[mapname]->SetLineColor(bgcol[b]);
      hist[mapname]->SetMarkerColor(bgcol[b]);
      hist[mapname]->SetFillColor(bgcol[b]);
      hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
    }
    for(unsigned int b = 0; b<signames.size();++b){
      string mapname = histonames[i] + "_" + signames[b];
      hist[mapname] = (TH1F*)f->Get(mapname.c_str());//get histogram
      if(addgen){
        string signamegen = signames[b];
        signamegen.replace(0,6,"SignalGen");
        string mapname2 =  histonames[i] + "_" + signamegen;
        hist[mapname2] = (TH1F*)f->Get(mapname2.c_str());//get histogram
        hist[mapname]->Add(hist[mapname2],1.);
        hist[mapname]->Scale(0.5);
      }
      hist[mapname]->SetLineWidth(3);
      hist[mapname]->SetLineStyle(7);
      hist[mapname]->SetLineColor(sigcol[b]);
      hist[mapname]->SetMarkerColor(sigcol[b]);
      hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
    }
  }
  for(map<string,TH1F*>::iterator h=    hist.begin(); h!=    hist.end();++h) {
    //here do common styles
    hist[h->first]->GetXaxis()->SetLabelFont(42);
    hist[h->first]->GetXaxis()->SetLabelSize(0.04);
    hist[h->first]->GetXaxis()->SetTitleSize(0.05);
    hist[h->first]->GetXaxis()->SetTitleFont(42);
    hist[h->first]->GetXaxis()->SetNdivisions(505);
    if(hist[h->first]->GetYaxis()->GetBinWidth(1)==1){
      hist[h->first]->GetYaxis()->SetTitle("events");
    } else {
      string temp = "";//general variables plotted --> can make plot more correct by adding the Events / XX GeV
      if(h->first.find(string("MT"))    != string::npos) temp = " GeV";
      if(h->first.find(string("Mlb"))   != string::npos) temp = " GeV";
      if(h->first.find(string("MET"))   != string::npos) temp = " GeV";
      if(h->first.find(string("LepPt")) != string::npos) temp = " GeV";
      string y = "events / " + std::to_string(hist[h->first]->GetYaxis()->GetBinWidth(1)) + temp;
    }
    hist[h->first]->GetYaxis()->SetLabelFont(42);
    hist[h->first]->GetYaxis()->SetLabelSize(0.04);
    hist[h->first]->GetYaxis()->SetTitleSize(0.05);
    hist[h->first]->GetYaxis()->SetTitleOffset(1.2);
    hist[h->first]->GetYaxis()->SetTitleFont(42);
    hist[h->first]->GetZaxis()->SetLabelFont(42);
    hist[h->first]->GetZaxis()->SetLabelSize(0.035);
    hist[h->first]->GetZaxis()->SetTitleSize(0.035);
    hist[h->first]->GetZaxis()->SetTitleFont(42);
    //if(logy) hist[h->first]->SetMaximum(2.5*hist[h->first]->GetMaximum());
    //else     hist[h->first]->SetMaximum(1.25*hist[h->first]->GetMaximum());
    //cout << h->first << endl;
  }
  for(unsigned int i = 0; i<histonames.size(); ++i) {
    float maximum = 0; float minimum = 0;
    string stackname = histonames[i];
    string axisname = histonames[i] + "_axis";
    stack[stackname] = new THStack();//all backgrounds are stacked together (i.e. plotted on top of each other) in a THStack so to see total background
    stack[stackname]->SetName(stackname.c_str());
    for(int b = bgnames.size()-1; b>=0;--b){
      string mapname = histonames[i] + "_" + bgnames[b];
      if(b==0){
        string stacktitle = (string)";" + (string)hist[mapname]->GetXaxis()->GetTitle() + (string)";" + (string)hist[mapname]->GetYaxis()->GetTitle();
        stack[stackname]->SetTitle(stacktitle.c_str());
        hist[stackname] = (TH1F*)hist[mapname]->Clone(axisname.c_str());
      }
      stack[stackname]->Add(hist[mapname],"");
      if(hist[mapname]->GetMinimum()>0) minimum += hist[mapname]->GetMinimum();
      if(hist[mapname]->GetMaximum()>0) maximum += hist[mapname]->GetMaximum();
    }
    if(logy){//for plotting - define minimum maximum of y axis range
      minimum *=0.9;
      maximum *=100.;
      minimum = pow(10.0, floor(log10(minimum)));
      maximum = pow(10.0, ceil(log10(maximum)));
      if(minimum==0) minimum = 0.02;
      if(minimum>1&&minimum<=5) minimum = 0.2;
      if(minimum>5) minimum = 2;
    } else {
      minimum *=0.;
      maximum *=2.;
    }
    hist[stackname]->SetMaximum(maximum);
    hist[stackname]->SetMinimum(minimum);
    stack[stackname]->SetMaximum(maximum);
    stack[stackname]->SetMinimum(minimum);
    stack[stackname]->SetHistogram(hist[stackname]);
  }

  //now we are ready to draw the pretty picture - first define all needed quantities and then Draw
  TCanvas *c1 = new TCanvas("c1", "",334,192,600,600);//plots are done on a canvas
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  if(logy) c1->SetLogy();    // Log y
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetLeftMargin(0.18);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.07);
  c1->SetBottomMargin(0.15);
  c1->SetFrameFillStyle(0);
  c1->SetFrameBorderMode(0);
  c1->SetFrameFillStyle(0);
  c1->SetFrameBorderMode(0);
  //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
  string ls = Form("%f",lumi);//luminosity of the samples - see in ExampleLooper --> weight
  ls.erase ( ls.find_last_not_of('0') + 1, std::string::npos );
  ls.erase ( ls.find_last_not_of('.') + 1, std::string::npos );
  TLatex *tLumi = new TLatex(0.95,0.944,Form("%s fb^{-1} (13 TeV)",ls.c_str()));
  //TLatex *tLumi = new TLatex(0.95,0.944,"(13 TeV)");
  tLumi->SetNDC();
  tLumi->SetTextAlign(31);
  tLumi->SetTextFont(42);
  tLumi->SetTextSize(0.042);
  tLumi->SetLineWidth(2);
  TLatex *tECM = new TLatex(0.95,0.944,"(13 TeV)");
  //TLatex *tECM = new TLatex(0.95,0.944,"(13 TeV)");
  tECM->SetNDC();
  tECM->SetTextAlign(31);
  tECM->SetTextFont(42);
  tECM->SetTextSize(0.042);
  tECM->SetLineWidth(2);
  //tLumi->Draw();
  TLatex *tCMS = new TLatex(0.185,0.944,"CMS");
  tCMS->SetNDC();
  tCMS->SetTextAlign(11);
  tCMS->SetTextFont(61);
  tCMS->SetTextSize(0.0525);
  tCMS->SetLineWidth(2);
  //tCMS->Draw();
  TLatex *tSim = new TLatex(0.295,0.944,"Supplementary");
  tSim->SetNDC();
  tSim->SetTextAlign(11);
  tSim->SetTextFont(52);
  tSim->SetTextSize(0.042);
  tSim->SetLineWidth(2);
  TLatex *tPrel = new TLatex(0.295,0.944,"Preliminary");
  tPrel->SetNDC();
  tPrel->SetTextAlign(11);
  tPrel->SetTextFont(52);
  tPrel->SetTextSize(0.042);
  tPrel->SetLineWidth(2);
  TLegend *leg1 = new TLegend(0.2,0.67,0.5,0.89,NULL,"brNDC");//legend is always important so that reader knows what color/samples belong together
  leg1->SetBorderSize(0);
  leg1->SetTextSize(0.035);
  leg1->SetLineColor(1);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  for(unsigned int i = 0; i<bgnames.size(); ++i)
    leg1->AddEntry(hist[histonames[0]+"_"+bgnames[i] ], bgleg[i].c_str(),"f");

  //finally drawing - draw stack, data, signal
  for(unsigned int i  = 0; i<histonames.size(); ++i) {
    string stackname = histonames[i];
    stack[stackname]->Draw("hist");

    TLegend *leg2 = new TLegend(0.5,0.67,0.85,0.89,NULL,"brNDC");//have 2 legends - one for background, another for signal+data(if available)
    leg2->SetBorderSize(0);
    leg2->SetTextSize(0.035);
    leg2->SetLineColor(1);
    leg2->SetLineStyle(1);
    leg2->SetLineWidth(2);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(1001);
    if(data){
      TH1F *h = new TH1F("hData","",hist[stackname + "_Data"]->GetNbinsX(),hist[stackname + "_Data"]->GetXaxis()->GetBinLowEdge(1),hist[stackname + "_Data"]->GetXaxis()->GetBinLowEdge(hist[stackname + "_Data"]->GetNbinsX()+1));
      h->SetBinErrorOption(TH1::kPoisson);
      h->SetLineWidth(2);
      h->SetLineColor(kBlack);
      h->SetMarkerStyle(20);
      h->SetMarkerColor(kBlack);
      for(int i = 1; i<=h->GetNbinsX(); ++i){
        for(int n = 1; n<=hist[stackname + "_Data"]->GetBinContent(i); ++n){
          h->Fill(h->GetXaxis()->GetBinCenter(i),1);//do this to get poisson uncertainty on data instead of Gaussian
        }
      }
      h->Draw("sameE0X0");
      //hist[stackname + "_Data"]->Draw("sameE0X0");
      leg2->AddEntry(h, "Data", "ep");
    }
    for(unsigned int j = 0; j<signames.size(); ++j){
      hist[histonames[i] + "_"+signames[j] ]->Draw("histsame");
      leg2->AddEntry(hist[histonames[i]+"_"+signames[j] ], sigleg[j].c_str(),"f");
    }
    hist[stackname]->Draw("sameaxis");
    leg1->Draw();
    leg2->Draw();
    tCMS->Draw();
    tPrel->Draw();
    tLumi->Draw();
    string outname;
    if(logy) outname = "Log_" + stackname;
    else     outname = "Lin_" + stackname;
    outname = "plots/" + outname + ".pdf";
    c1->SaveAs(outname.c_str());//save the pretty picture
    c1->Clear();
  }

}
 
