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

void MakePlotsDataTTZ(){

  
  bool  logy   = false; //should the y axis being plotted in logarithmic scale (true) or linear scale (false)
  bool  data   = true;//set this to false - we don't look at data
  float lumi   = 42.0; //check what luminosity was put into the weight in ExampleLooper
  bool  addgen = false; //average reco and genMET signal samples
    int year = -1;

    if(year==2016) lumi = 35.9;
    if(year==2017) lumi = 41.9;
    if(year==2018) lumi = 58.8;
    if(year==-1)   lumi = 136.6;

  vector<string> histonames;
  vector<string> histox;
  vector<string> selecttitle;
  vector<string> bgnames;
  vector<string> signames;
  vector<string> bgleg;
  vector<string> sigleg;
  vector<Color_t> bgcol;
  vector<Color_t> sigcol;
  vector<string> cutnames;

  map<string, TH1F*> hist;
  map<string, THStack*> stack;
/*
  bgnames.push_back("Znunu");        
  bgcol.push_back(kMagenta-5);
  bgleg.push_back("Z#rightarrow#nu#bar{#nu}");
*/
  bgnames.push_back("WJets");        
  bgcol.push_back(kOrange-2);
  bgleg.push_back("1#font[12]{l} not from top");

  bgnames.push_back("TT1l");       
  bgcol.push_back(kRed-7);
  bgleg.push_back("1#font[12]{l} from top");

  bgnames.push_back("LostLep");
  bgcol.push_back(kCyan-3);
  bgleg.push_back("Lost Lepton");
    
    bgnames.push_back("TTZ");
    bgcol.push_back(kGreen+1);
    bgleg.push_back("t#bar{t}Z");
    
    bgnames.push_back("WZ");
    bgcol.push_back(kGreen+2);
    bgleg.push_back("WZ");

    vector<string> lsel, lname;
    lsel.push_back("");          lname.push_back("");
    lsel.push_back("_emutrig");  lname.push_back("| e#mu triggered");
    lsel.push_back("_etrig");    lname.push_back("| single-e triggered");
    lsel.push_back("_mutrig");   lname.push_back("| single-#mu triggered");
    
    vector<string> Zsel, Zname;
    Zsel.push_back("");          Zname.push_back("");
    Zsel.push_back("_leadlepZ"); Zname.push_back("| l1+l2=Z");
    
    vector<string> hsel, hname;
    hsel.push_back("MT");        hname.push_back("M_{T} [GeV]");
    hsel.push_back("MET");       hname.push_back("E_{T}^{miss} [GeV]");
    hsel.push_back("MET_rl");    hname.push_back("E_{T}^{miss}-rl [GeV]");
    hsel.push_back("Ngoodleps"); hname.push_back("N_{leptons}");
    hsel.push_back("Nleps");     hname.push_back("N_{veto-leptons}");
    hsel.push_back("NBJets");    hname.push_back("N_{B}");
    hsel.push_back("NJets");     hname.push_back("N_{J}");
    hsel.push_back("MinDPhi");   hname.push_back("min#Delta#phi(E_{T}^{miss},j_{1,2})");
    hsel.push_back("ElPt1");     hname.push_back("p_{T}(e_{1}) [GeV]");
    hsel.push_back("ElPt2");     hname.push_back("p_{T}(e_{2}) [GeV]");
    hsel.push_back("MuPt1");     hname.push_back("p_{T}(#mu_{1}) [GeV]");
    hsel.push_back("MuPt2");     hname.push_back("p_{T}(#mu_{2}) [GeV]");
    hsel.push_back("Nlooseleps");hname.push_back("N_{loose-leptons}");
    hsel.push_back("NBJets_3goodlep");    hname.push_back("N_{B} | 3 good leptons");
    hsel.push_back("NBJets_3vetolep");    hname.push_back("N_{B} | 3 loose leptons");
    hsel.push_back("NBJets_3g3vlep");     hname.push_back("N_{B} | 3 loose/2 good leptons");
    for(unsigned int i = 0; i<hname.size(); ++i){
        for(unsigned int j =0; j <Zsel.size(); ++j){
            for(unsigned int l =0; l <lsel.size(); ++l){
                histonames.push_back(hsel[i] + lsel[l] + Zsel[j]);
                histox.push_back(hname[i] + lname[l] + Zname[j]);
            }
        }
    }
  //histonames.push_back("MT2_l_l_23j1b");                     histox.push_back("M_{T2}(l,l) [GeV] | 2-3j");
  //histonames.push_back("MT2_l_l_ge4j1b");                    histox.push_back("M_{T2}(l,l) [GeV] | #geq4j");
  //histonames.push_back("MT2_l_l_ge5j1b");                    histox.push_back("M_{T2}(l,l) [GeV] | #geq5j");
  //histonames.push_back("passMT2_l_l_23j1b");                 histox.push_back("pass M_{T2}(l,l) | 2-3j");
  //histonames.push_back("passMT2_l_l_ge4j1b");                histox.push_back("pass M_{T2}(l,l) | #geq4j");
  //histonames.push_back("passMT2_l_l_ge5j1b");                histox.push_back("pass M_{T2}(l,l) | #geq5j");

  int numHistos = histonames.size();


  /*
  signames.push_back("Signal_T2tt_betweencorridor");       
  sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (compressed)");
  sigcol.push_back(kGreen+2);

  signames.push_back("Signal_T2tt_highMStop");     
  sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (high M_{#tilde{t}})");
  sigcol.push_back(kBlue+1);

  signames.push_back("Signal_T2bW_highMLSP"); 
  sigleg.push_back("#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (high M_{#tilde{#chi}})"); 
  sigcol.push_back(kYellow+1);

  signames.push_back("Signal_T2bW_highMStop");          
  sigleg.push_back("#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (high M_{#tilde{t}})");   
  sigcol.push_back(kMagenta+1);

  signames.push_back("Signal_T2tb_compressed");          
  sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}/b#tilde{#chi}^{#pm}_{1} (compressed)");   
  sigcol.push_back(kRed);

  signames.push_back("Signal_T2tb_highMLSP");          
  sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}/b#tilde{#chi}^{#pm}_{1} (high M_{#tilde{#chi}})");   
  sigcol.push_back(kOrange+1);
*/
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

    TFile *f;
    if(year==2016) f = new TFile("rootfiles/TTZNBfit_2016.root","READ");
    if(year==2017) f = new TFile("rootfiles/TTZNBfit_2017.root","READ");
    if(year==2018) f = new TFile("rootfiles/TTZNBfit_2018.root","READ");
    if(year==  -1) f = new TFile("rootfiles/TTZNBfit_combined.root","READ");


  for (int i = 0; i < histonames.size(); ++i){
    if(data) {
      string mapname  = histonames[i] + "_Data";
      string mapnameX = histonames[i] + "_X";
      hist[mapnameX ]=(TH1F*)f->Get(mapname.c_str());
      hist[mapnameX]->SetName(mapnameX.c_str());
      hist[mapname] = new TH1F(mapname.c_str(),"",hist[mapnameX]->GetNbinsX(), hist[mapnameX]->GetXaxis()->GetBinLowEdge(1), hist[mapnameX]->GetXaxis()->GetBinLowEdge(hist[mapnameX]->GetNbinsX()+1));
      hist[mapname]->SetBinErrorOption(TH1::kPoisson);
      for(int i = 1; i<=hist[mapname]->GetNbinsX(); ++i){
        for(int n = 1; n<=hist[mapnameX]->GetBinContent(i); ++n){
          hist[mapname]->Fill(hist[mapnameX]->GetXaxis()->GetBinCenter(i),1);
        }
      }
      
      //hist[mapname ]=(TH1F*)f->Get(mapname.c_str());
      hist[mapname]->SetLineColor(kBlack);
      hist[mapname]->SetLineWidth(2);
      hist[mapname]->SetMarkerStyle(20);
    }
    for (int b = 0; b < bgnames.size(); ++b){
      string mapname =  histonames[i] + "_" + bgnames[b];
      string bgname = "bgsum" + histonames[i];
			 
      if (b == 0){

	hist[mapname] = (TH1F*)f -> Get(mapname.c_str());
    //      cout << __LINE__ << " " <<mapname << endl;
    //      cout<<hist[mapname]->Integral()<<endl;
	hist[bgname] = (TH1F*)hist[mapname] -> Clone(bgname.c_str());
  hist[bgname]->SetFillStyle(3544);
  hist[bgname]->SetFillColor(1);
  hist[bgname]->SetLineColor(1);
	hist[mapname]->SetLineColor(bgcol[b]);
	hist[mapname]->SetMarkerColor(bgcol[b]);
	hist[mapname]->SetFillColor(bgcol[b]);
	hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
	hist[bgname]->GetXaxis()->SetTitle(histox[i].c_str());
      }

      else{
	
	hist[mapname] = (TH1F*)f -> Get(mapname.c_str());
    //      cout << __LINE__ << " " <<mapname << endl;
    //      cout<<hist[mapname]->Integral()<<endl;
	hist[bgname]-> Add(hist[mapname]);
	hist[mapname]->SetLineColor(bgcol[b]);
	hist[mapname]->SetMarkerColor(bgcol[b]);
	hist[mapname]->SetFillColor(bgcol[b]);
	hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());

	}
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
    hist[h->first]->GetXaxis()->SetTitleOffset(0.9);
    hist[h->first]->GetXaxis()->SetTitleFont(42);
    hist[h->first]->GetXaxis()->SetNdivisions(505);
    
    if(hist[h->first]->GetYaxis()->GetBinWidth(1)==1){
      hist[h->first]->GetYaxis()->SetTitle("events");
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

    string bgname = "bgsum" + histonames[i];
 
    float maximum = 0; float minimum = 0;
    string stackname = histonames[i];
    string axisname = histonames[i] + "_axis";
    stack[stackname] = new THStack();
    stack[stackname] -> SetName(stackname.c_str());

    for (int b = 0; b<bgnames.size(); ++b){

      string mapname =  histonames[i] + "_" + bgnames[b];
      stack[stackname] -> Add(hist[mapname]);
      if(hist[mapname] -> GetMinimum()>0) minimum += hist[mapname]->GetMinimum();
      if(hist[mapname] -> GetMaximum()>0) maximum += hist[mapname]->GetMaximum();

    }
      if(hist[histonames[i] + "_Data"]->GetMaximum()>maximum) maximum = hist[histonames[i] + "_Data"]->GetMaximum();
      if(hist[histonames[i] + "_Data"]->GetMinimum()<minimum) minimum = hist[histonames[i] + "_Data"]->GetMinimum();

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
    hist[bgname]->SetMaximum(maximum);
    hist[bgname]->SetMinimum(minimum);
    stack[stackname]->SetMaximum(maximum);
    stack[stackname]->SetMinimum(minimum);
    stack[stackname]->SetHistogram(hist[bgname]);
  }

    for(unsigned int i = 0; i<histonames.size(); ++i){
        if(hist[histonames[i]+"_Data"]->Integral()==0) continue;
        if(histonames[i]=="Nlooseleps" || histonames[i]=="Nlooseleps_emutrig" || histonames[i]=="Nlooseleps_etrig" || histonames[i]=="Nlooseleps_mutrig"){
            cout << year << " " << histonames[i] << " data " << hist[histonames[i]+"_Data"]->Integral() << " MC " << hist["bgsum"+histonames[i] ]->Integral() << " data/MC ratio " << hist[histonames[i]+"_Data"]->Integral()/hist["bgsum"+histonames[i] ]->Integral() << endl;
        }

      //now we are ready to draw the pretty picture - first define all needed quantities and then Draw
      TCanvas *c1 = new TCanvas("c1", "",334,192,600,600);//plots are done on a canvas
      c1->SetFillColor(0);
      c1->SetBorderMode(0);
      c1->SetBorderSize(2);
      //if(logy) c1->SetLogy();    // Log y
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
    
      TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0,0.165,1,1);//0,0.18,1,1);
      plotpad->Draw();
      plotpad->cd();
      plotpad->Range(-85.71429,-3.864499,628.5714,6.791402);//(133.1169,-3.101927,782.4675,0.7583922);
      plotpad->SetFillColor(0);
      plotpad->SetBorderMode(0);
      plotpad->SetBorderSize(2);
      if(logy) plotpad->SetLogy();
      plotpad->SetTickx(1);
      plotpad->SetTicky(1);
      plotpad->SetLeftMargin(0.12);
      plotpad->SetRightMargin(0.04);
      plotpad->SetTopMargin(0.05);
      // plotpad->SetBottomMargin(0.15);
      plotpad->SetFrameFillStyle(0);
      plotpad->SetFrameBorderMode(0);
      plotpad->SetFrameFillStyle(0);
      plotpad->SetFrameBorderMode(0);
    
      plotpad->cd();
      //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
      string ls = Form("%f",lumi);//luminosity of the samples - see in ExampleLooper --> weight
      ls.erase ( ls.find_last_not_of('0') + 1, std::string::npos );
      ls.erase ( ls.find_last_not_of('.') + 1, std::string::npos );
      TLatex *tLumi = new TLatex(0.95,0.954,Form("%s fb^{-1} (13 TeV)",ls.c_str()));
      //TLatex *tLumi = new TLatex(0.95,0.944,"(13 TeV)");
      tLumi->SetNDC();
      tLumi->SetTextAlign(31);
      tLumi->SetTextFont(42);
      tLumi->SetTextSize(0.042);
      tLumi->SetLineWidth(2);
      TLatex *tECM = new TLatex(0.95,0.954,"(13 TeV)");
      //TLatex *tECM = new TLatex(0.95,0.944,"(13 TeV)");
      tECM->SetNDC();
      tECM->SetTextAlign(31);
      tECM->SetTextFont(42);
      tECM->SetTextSize(0.042);
      tECM->SetLineWidth(2);
      //tLumi->Draw();
      TLatex *tCMS = new TLatex(0.12,0.954,"CMS");
      tCMS->SetNDC();
      tCMS->SetTextAlign(11);
      tCMS->SetTextFont(61);
      tCMS->SetTextSize(0.0525);
      tCMS->SetLineWidth(2);
      //tCMS->Draw();
      TLatex *tSim = new TLatex(0.225,0.954,"Supplementary");
      tSim->SetNDC();
      tSim->SetTextAlign(11);
      tSim->SetTextFont(52);
      tSim->SetTextSize(0.042);
      tSim->SetLineWidth(2);
      TLatex *tPrel = new TLatex(0.225,0.954,"Preliminary");
      tPrel->SetNDC();
      tPrel->SetTextAlign(11);
      tPrel->SetTextFont(52);
      tPrel->SetTextSize(0.042);
      tPrel->SetLineWidth(2);
      TLegend *leg1 = new TLegend(0.2,0.735,0.5,0.925,NULL,"brNDC");//legend is always important so that reader knows what color/samples belong together
      leg1->SetBorderSize(0);
      leg1->SetTextSize(0.035);
      leg1->SetLineColor(1);
      leg1->SetLineStyle(1);
      leg1->SetLineWidth(2);
      leg1->SetFillColor(0);
      leg1->SetFillStyle(1001);

      for(unsigned int i = 0; i<bgnames.size(); ++i){
        leg1->AddEntry(hist[histonames[0]+"_"+bgnames[i] ], bgnames[i].c_str(),"f");
      }
      if(data) leg1->AddEntry(hist[histonames[0]+"_Data" ], "Data","ep");
      string stackname = histonames[i];
      stack[stackname] -> Draw("hist");
      hist["bgsum"+histonames[i] ] -> Draw("sameE2");
      if(data) hist[histonames[i]+"_Data" ]->Draw("sameE0X0");
      string bgname = "bgsum" + histonames[i];
      double err,err2;
      int numBins = hist[bgname] -> GetNbinsX();
      double yield  = hist[bgname] -> IntegralAndError(1, numBins, err);
      double yield2 = hist[bgname] -> IntegralAndError(1, 1, err2);
        //cout << bgname << " tot yield " << yield << " +/- " << err << " pass yield " << yield2 << " +/- " << err2 << " pass fraction " << yield2/yield << endl;

      TLegend *leg2 = new TLegend(0.5,0.735,0.85,0.925,NULL,"brNDC");//have 2 legends - one for background, another for signal+data(if available)
      leg2->SetBorderSize(0);
      leg2->SetTextSize(0.035);
      leg2->SetLineColor(1);
      leg2->SetLineStyle(1);
      leg2->SetLineWidth(2);
      leg2->SetFillColor(0);
      leg2->SetFillStyle(1001);

      for(unsigned int j = 0; j<signames.size(); ++j){
        string signame = histonames[i] + "_" + signames[j];
        double err,err2;
        int numBins = hist[signame] -> GetNbinsX();
        double yield  = hist[signame] -> IntegralAndError(1, numBins, err);
        double yield2 = hist[signame] -> IntegralAndError(1, 1, err2);
        cout << signame << " tot yield " << yield << " +/- " << err << " pass yield " << yield2 << " +/- " << err2 << " pass fraction " << yield2/yield << endl;
        hist[histonames[i] + "_" + signames[j] ] -> Draw("histsame");
        leg2 -> AddEntry(hist[histonames[i] + "_" + signames[j] ], sigleg[j].c_str(),"f");
      }
    


      //hist[stackname]->Draw("sameaxis");
      leg1->Draw();
      leg2->Draw();
      tCMS->Draw();
      tPrel->Draw();
      tLumi->Draw();
      
      c1->cd();
      TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0,1,0.16); //0,0,1,0.26);
      ratiopad->Draw();
      ratiopad->cd();
      //ratiopad->Range(-85.71429,-0.4,628.5714,2.266667);  //(133.1169,0.06923079,782.4675,1.607692);
      ratiopad->SetFillColor(0);
      ratiopad->SetBorderMode(0);
      ratiopad->SetBorderSize(2);
      ratiopad->SetTickx(1);
      ratiopad->SetTicky(1);
      ratiopad->SetLeftMargin(0.12);
      ratiopad->SetRightMargin(0.04);
      //  ratiopad->SetTopMargin(0.04);
      ratiopad->SetBottomMargin(0.2);
      ratiopad->SetFrameFillStyle(0);
      ratiopad->SetFrameBorderMode(0);
      ratiopad->SetFrameFillStyle(0);
      ratiopad->SetFrameBorderMode(0);
      float ratiomax = 0;
      if(data){
        hist[histonames[i] + "_Ratio" ]  = (TH1F*)hist["bgsum" + histonames[i] ]->Clone((histonames[i] + "_Ratio").c_str());
        hist[histonames[i] + "_Ratio" ]->Divide(hist["bgsum" + histonames[i] ]);
        hist[histonames[i] + "_Ratio" ]->GetYaxis()->SetLabelSize(0.14);
        hist[histonames[i] + "_Ratio" ]->GetYaxis()->SetNdivisions(504);
        hist[histonames[i] + "_Ratio" ]->GetYaxis()->SetTitle("data/bg");
        hist[histonames[i] + "_Ratio" ]->GetYaxis()->SetTitleSize(0.14);
        hist[histonames[i] + "_Ratio" ]->GetYaxis()->SetTitleOffset(0.28);
        hist[histonames[i] + "_Ratio" ]->GetXaxis()->SetLabelSize(0.0);
        hist[histonames[i] + "_Ratio" ]->GetXaxis()->SetTitleSize(0.0);
        hist[histonames[i] + "_Ratio" ]->SetMinimum(0);
        //hist[histonames[i] + "_Ratio" ]->SetMaximum(TMath::Min( hist[histonames[i] + "_Ratio" ]->GetMaximum()*1.2,1.));
        hist[histonames[i] + "_Ratio" ]->SetMaximum(2.);
        
        hist[histonames[i] + "_Data_Ratio" ]  = (TH1F*)hist[histonames[i] + "_Data" ]->Clone((histonames[i] + "_Data_Ratio").c_str());
        hist[histonames[i] + "_Data_Ratio" ]->Divide(hist["bgsum" + histonames[i] ]);
        hist[histonames[i] + "_Data_Ratio" ]->GetYaxis()->SetLabelSize(0.14);
        hist[histonames[i] + "_Data_Ratio" ]->GetYaxis()->SetNdivisions(504);
        hist[histonames[i] + "_Data_Ratio" ]->GetYaxis()->SetTitle("data/bg");
        hist[histonames[i] + "_Data_Ratio" ]->GetYaxis()->SetTitleSize(0.14);
        hist[histonames[i] + "_Data_Ratio" ]->GetYaxis()->SetTitleOffset(0.28);
        hist[histonames[i] + "_Data_Ratio" ]->GetXaxis()->SetLabelSize(0.0);
        hist[histonames[i] + "_Data_Ratio" ]->GetXaxis()->SetTitleSize(0.0);
        hist[histonames[i] + "_Data_Ratio" ]->SetMinimum(0);
        //hist[histonames[i] + "_Data_Ratio" ]->SetMaximum(TMath::Min( hist[histonames[i] + "_Data_Ratio" ]->GetMaximum()*1.2,1.));
        hist[histonames[i] + "_Data_Ratio" ]->SetMaximum(2.);
        TLine *line = new TLine(hist[histonames[i] + "_Data_Ratio" ]->GetXaxis()->GetBinLowEdge(1),1,hist[histonames[i] + "_Data_Ratio" ]->GetXaxis()->GetBinLowEdge(hist[histonames[i] + "_Data_Ratio" ]->GetNbinsX()+1),1);
        line->SetLineWidth(2);
        line->SetLineColor(kRed);
        line->SetLineStyle(7);
        hist[histonames[i] + "_Ratio" ]->Draw("E2");
        line->Draw();
        hist[histonames[i] + "_Data_Ratio" ]->Draw("sameE0X0");
      }
      else {
        for(unsigned int j = 0; j<signames.size(); ++j){
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]  = (TH1F*)hist[histonames[i] + "_" + signames[j] ]->Clone((histonames[i] + "_" + signames[j]+"_Ratio").c_str());
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->Divide(hist["bgsum" + histonames[i] ]);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->SetMinimum(0);
          if(hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetMaximum()>ratiomax) ratiomax = hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetMaximum();
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetYaxis()->SetLabelSize(0.14);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetYaxis()->SetNdivisions(504);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetYaxis()->SetTitle("sig/bg");
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetYaxis()->SetTitleSize(0.14);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetYaxis()->SetTitleOffset(0.28);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetXaxis()->SetLabelSize(0.0);
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->GetXaxis()->SetTitleSize(0.0);

        }
        for(unsigned int j = 0; j<signames.size(); ++j){
          hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->SetMaximum(TMath::Min(ratiomax*1.2,1.));
          if(j==0) hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->Draw("hist");
          else     hist[histonames[i] + "_" + signames[j]+"_Ratio" ]->Draw("histsame");
        }
      }
        string outname;
        if(year==2016) outname = "Plots/2016/" + stackname + ".pdf";
        if(year==2017) outname = "Plots/2017/" + stackname + ".pdf";
        if(year==2018) outname = "Plots/2018/" + stackname + ".pdf";
        if(year==  -1) outname = "Plots/combined/" + stackname + ".pdf";
      c1->cd();
      c1->SaveAs(outname.c_str());//save the pretty picture
      c1->Clear();
        
      /*
        delete leg1;
        delete leg2;
        delete tLumi;
        delete tECM;
        delete tCMS;
        delete tSim;
        delete tPrel;
        delete ratiopad;
        delete plotpad;
        delete c1;
      */
  }

} //end function
