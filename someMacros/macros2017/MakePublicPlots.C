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

void MakePublicPlots(){
    
    bool logy = true;
 
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
    histonames.push_back("MT_2j");
    histonames.push_back("MT_4j");
    histonames.push_back("MT_2j_tmod0");
    histonames.push_back("MT_4j_tmod0");
    histonames.push_back("tmod_2j");
    histonames.push_back("tmod_4j");
    histonames.push_back("MDPhi_2j");
    histonames.push_back("MDPhi_4j");
    histonames.push_back("MDPhi_2j_tmod0");
    histonames.push_back("MDPhi_4j_tmod0");//9
    histonames.push_back("Mlb_2j");
    histonames.push_back("Mlb_4j");
    histonames.push_back("Mlb_2j_tmod0");
    histonames.push_back("Mlb_4j_tmod0");
    histonames.push_back("Mlb_tb_2j");
    histonames.push_back("Mlb_tb_4j");
    histonames.push_back("Mlb_tb_2j_tmod0");
    histonames.push_back("Mlb_tb_4j_tmod0");
    histonames.push_back("MET_2j");//18
    histonames.push_back("MET_4j");
    histonames.push_back("MET_2j_tmod0");
    histonames.push_back("MET_4j_tmod0");
    histonames.push_back("MET_2j_lMlb");//22
    histonames.push_back("MET_4j_lMlb");
    histonames.push_back("MET_2j_lMlb_tmod0");
    histonames.push_back("MET_4j_lMlb_tmod0");
    histonames.push_back("MET_2j_hMlb");//26
    histonames.push_back("MET_4j_hMlb");
    histonames.push_back("MET_2j_hMlb_tmod0");
    histonames.push_back("MET_4j_hMlb_tmod0");
    histonames.push_back("MET_5j");//30
    histonames.push_back("NJ");//31
    histonames.push_back("NJ_compressed");//32
    histonames.push_back("NJ_tmod0");//33
    histonames.push_back("LepPt");
    histonames.push_back("DPhiMETLep");     
    histox.push_back("M_{T} [GeV]");
    histox.push_back("M_{T} [GeV]");
    histox.push_back("M_{T} [GeV]");
    histox.push_back("M_{T} [GeV]");
    histox.push_back("t_{mod}");
    histox.push_back("t_{mod}");
    histox.push_back("min#Delta#phi(E_{T}^{miss}, j_{1,2})");
    histox.push_back("min#Delta#phi(E_{T}^{miss}, j_{1,2})");
    histox.push_back("min#Delta#phi(E_{T}^{miss}, j_{1,2})");
    histox.push_back("min#Delta#phi(E_{T}^{miss}, j_{1,2})");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    //histox.push_back("M_{  b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("M_{#font[12]{l}b} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("E_{T}^{miss} [GeV]");
    histox.push_back("N_{J}");
    histox.push_back("N_{J}");
    histox.push_back("N_{J}");
    //histox.push_back("  -p_{T} [GeV]");
    histox.push_back("#font[12]{l}-p_{T} [GeV]");
    //histox.push_back("#Delta#phi(E_{T}^{miss},  )");
    histox.push_back("#Delta#phi(E_{T}^{miss},#font[12]{l})");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets");
    selecttitle.push_back("#geq4 jets");
    selecttitle.push_back("#geq2 jets, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, t_{mod} > 0");
    //selecttitle.push_back("#geq2 jets, M_{  b} #leq 175 GeV");
    //selecttitle.push_back("#geq4 jets, M_{  b} #leq 175 GeV");
    //selecttitle.push_back("#geq2 jets, M_{  b} #leq 175 GeV, t_{mod} > 0");
    //selecttitle.push_back("#geq4 jets, M_{  b} #leq 175 GeV, t_{mod} > 0");
    //selecttitle.push_back("#geq2 jets, M_{  b} > 175 GeV");
    //selecttitle.push_back("#geq4 jets, M_{  b} > 175 GeV");
    //selecttitle.push_back("#geq2 jets, M_{  b} > 175 GeV, t_{mod} > 0");
    //selecttitle.push_back("#geq4 jets, M_{  b} > 175 GeV, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets, M_{#font[12]{l}b} #leq 175 GeV");
    selecttitle.push_back("#geq4 jets, M_{#font[12]{l}b} #leq 175 GeV");
    selecttitle.push_back("#geq2 jets, M_{#font[12]{l}b} #leq 175 GeV, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, M_{#font[12]{l}b} #leq 175 GeV, t_{mod} > 0");
    selecttitle.push_back("#geq2 jets, M_{#font[12]{l}b} > 175 GeV");
    selecttitle.push_back("#geq4 jets, M_{#font[12]{l}b} > 175 GeV");
    selecttitle.push_back("#geq2 jets, M_{#font[12]{l}b} > 175 GeV, t_{mod} > 0");
    selecttitle.push_back("#geq4 jets, M_{#font[12]{l}b} > 175 GeV, t_{mod} > 0");
    selecttitle.push_back("compressed selection");
    selecttitle.push_back("");
    //selecttitle.push_back("  -p_{T} < 150 GeV, #Delta#phi(E_{T}^{miss},  )<2.0");
    selecttitle.push_back("#font[12]{l}-p_{T} < 150 GeV, #Delta#phi(E_{T}^{miss},#font[12]{l})<2.0");
    selecttitle.push_back("t_{mod} > 0");
    //selecttitle.push_back("N_{J} #geq 5, #Delta#phi(E_{T}^{miss},  )<2.0");
    //selecttitle.push_back("N_{J} #geq 5,   -p_{T} < 150 GeV");
    selecttitle.push_back("N_{J} #geq 5, #Delta#phi(E_{T}^{miss},#font[12]{l})<2.0");
    selecttitle.push_back("N_{J} #geq 5, #font[12]{l}-p_{T} < 150 GeV");

    bgnames.push_back("TT2l");
    bgnames.push_back("TT1l");
    bgnames.push_back("WJets");
    bgnames.push_back("Znunu");
    bgleg.push_back("Lost lepton");
    //bgleg.push_back("1   from top");
    //bgleg.push_back("1   not from top");
    bgleg.push_back("1#font[12]{l} from top");
    bgleg.push_back("1#font[12]{l} not from top");
    bgleg.push_back("Z#rightarrow#nu#bar{#nu}");
    bgcol.push_back(kCyan-3);
    bgcol.push_back(kRed-7);
    bgcol.push_back(kOrange-2);
    bgcol.push_back(kMagenta-5);
    signames.push_back("Signal_T2bW_850_50");
    signames.push_back("Signal_T2bW_850_300");
    signames.push_back("Signal_T2bW_500_300");
    signames.push_back("Signal_T2tb_900_50");
    signames.push_back("Signal_T2tb_850_300");
    signames.push_back("Signal_T2tb_500_300");
    signames.push_back("Signal_T2tt_950_50");
    signames.push_back("Signal_T2tt_950_300");
    signames.push_back("Signal_T2tt_600_400");
    signames.push_back("Signal_T2tt_425_300");
    signames.push_back("Signal_T2tt_425_250");
    signames.push_back("Signal_T2tt_350_250");
    sigleg.push_back("#tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (850,50)");
    sigleg.push_back("#tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (850,300)");
    sigleg.push_back("#tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (500,300)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} / #tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (900,50)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} / #tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (850,300)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} / #tilde{t}#rightarrowb#tilde{#chi#}^{#pm}_{1} (500,300)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,50)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,300)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (600,400)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (425,300)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (425,250)");
    sigleg.push_back("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (350,250)");
    sigcol.push_back(kGreen+2);
    sigcol.push_back(kBlue+1);
    sigcol.push_back(kYellow+1);
    sigcol.push_back(kMagenta+1);
    sigcol.push_back(kYellow+1);
    sigcol.push_back(kGreen+2);
    sigcol.push_back(kRed);
    sigcol.push_back(kOrange+7);
    sigcol.push_back(kBlue+1);
    sigcol.push_back(kGreen+2);
    sigcol.push_back(kMagenta+1);
    sigcol.push_back(kYellow+1);
    
    //TFile *f = new TFile("PublicPlotHistos.root","READ");
    TFile *f = new TFile("PublicPlotHistos_reminiAOD.root","READ");

    for(unsigned int i = 0; i<histonames.size(); ++i) {
        string mapname = histonames[i] + "_Data";
        hist[mapname] = (TH1F*)f->Get(mapname.c_str());
        hist[mapname]->SetLineWidth(2);
        hist[mapname]->SetLineColor(kBlack);
        hist[mapname]->SetMarkerStyle(20);
        hist[mapname]->SetMarkerColor(kBlack);
        hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
        for(unsigned int b = 0; b<bgnames.size();++b){
            string mapname = histonames[i] + "_" + bgnames[b];
            hist[mapname] = (TH1F*)f->Get(mapname.c_str());
            hist[mapname]->SetLineColor(bgcol[b]);
            hist[mapname]->SetMarkerColor(bgcol[b]);
            hist[mapname]->SetFillColor(bgcol[b]);
            hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
        }
        for(unsigned int b = 0; b<signames.size();++b){
            string mapname = histonames[i] + "_" + signames[b];
            hist[mapname] = (TH1F*)f->Get(mapname.c_str());
            hist[mapname]->SetLineWidth(3);
            hist[mapname]->SetLineStyle(7);
            hist[mapname]->SetLineColor(sigcol[b]);
            hist[mapname]->SetMarkerColor(sigcol[b]);
            hist[mapname]->GetXaxis()->SetTitle(histox[i].c_str());
        }
    }
    for(map<string,TH1F*>::iterator h=    hist.begin(); h!=    hist.end();++h) {
        hist[h->first]->GetXaxis()->SetLabelFont(42);
        hist[h->first]->GetXaxis()->SetLabelSize(0.04);
        hist[h->first]->GetXaxis()->SetTitleSize(0.05);
        hist[h->first]->GetXaxis()->SetTitleFont(42);
        hist[h->first]->GetXaxis()->SetNdivisions(505);
        if(hist[h->first]->GetYaxis()->GetBinWidth(1)==1){
            hist[h->first]->GetYaxis()->SetTitle("events");
        } else {
            string temp = "";
            if(h->first.find(string("MT")) != string::npos) temp = " GeV";
            if(h->first.find(string("Mlb")) != string::npos) temp = " GeV";
            if(h->first.find(string("MET")) != string::npos) temp = " GeV";
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
        stack[stackname] = new THStack();
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
        if(logy){
            minimum *=0.9;
            maximum *=100.;
            minimum = pow(10.0, floor(log10(minimum)));
            maximum = pow(10.0, ceil(log10(maximum)));
            if(minimum==0) minimum = 0.02;
            if(minimum>1&&minimum<5) minimum = 0.2;
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

    TCanvas *c1 = new TCanvas("c1", "",334,192,600,600);
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
    TLatex *tLumi = new TLatex(0.95,0.944,"35.9 fb^{-1} (13 TeV)");
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
    TLegend *leg1 = new TLegend(0.2,0.67,0.5,0.89,NULL,"brNDC");
    leg1->SetBorderSize(0);
    leg1->SetTextSize(0.035);
    leg1->SetLineColor(1);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    bgleg.push_back("Lost lepton");
    //bgleg.push_back("1   from top");
    //bgleg.push_back("1   not from top");
    bgleg.push_back("1#font[12]{l} from top");
    bgleg.push_back("1#font[12]{l} not from top");
    bgleg.push_back("Z#rightarrow#nu#bar{#nu}");
    leg1->AddEntry(hist["MET_4j_TT2l"] ,"Lost lepton", "f");
    //leg1->AddEntry(hist["MET_4j_TT1l"] ,"1   from top", "f");
    //leg1->AddEntry(hist["MET_4j_WJets"],"1   not from top", "f");
    leg1->AddEntry(hist["MET_4j_TT1l"] ,"1#font[12]{l} from top", "f");
    leg1->AddEntry(hist["MET_4j_WJets"],"1#font[12]{l} not from top", "f");
    leg1->AddEntry(hist["MET_4j_Znunu"],"Z#rightarrow#nu#bar{#nu}", "f");
    
    for(unsigned int i  = 0; i<histonames.size(); ++i) {
        string stackname = histonames[i];
        stack[stackname]->Draw("hist");
        TH1F *h = new TH1F("hData","",hist[stackname + "_Data"]->GetNbinsX(),hist[stackname + "_Data"]->GetXaxis()->GetBinLowEdge(1),hist[stackname + "_Data"]->GetXaxis()->GetBinLowEdge(hist[stackname + "_Data"]->GetNbinsX()+1));
        h->SetBinErrorOption(TH1::kPoisson);
        h->SetLineWidth(2);
        h->SetLineColor(kBlack);
        h->SetMarkerStyle(20);
        h->SetMarkerColor(kBlack);
        for(int i = 1; i<=h->GetNbinsX(); ++i){
            for(int n = 1; n<=hist[stackname + "_Data"]->GetBinContent(i); ++n){
                h->Fill(h->GetXaxis()->GetBinCenter(i),1);
            }
        }
        h->Draw("sameE0X0");
        //hist[stackname + "_Data"]->Draw("sameE0X0");
        TLegend *leg2 = new TLegend(0.5,0.67,0.85,0.89,NULL,"brNDC");
        leg2->SetBorderSize(0);
        leg2->SetTextSize(0.035);
        leg2->SetLineColor(1);
        leg2->SetLineStyle(1);
        leg2->SetLineWidth(2);
        leg2->SetFillColor(0);
        leg2->SetFillStyle(1001);
        leg2->AddEntry(h, "Data", "ep");
        if((i<22||i==31||i==33)&&stackname.find(string("2j"))!=string::npos){
            //plot signal all three types
            hist[histonames[i] + "_Signal_T2bW_850_50"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tb_900_50"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_950_50"]->Draw("histsame");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_950_50"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,50)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tb_900_50"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} / #tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (900,50)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2bW_850_50"], "#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (850,50)", "l");
        } else if (((i<22&&i!=7)||i==31||i==33)&&stackname.find(string("4j"))!=string::npos){
            //plot T2bW and T2tt, with high DM T2tt
            hist[histonames[i] + "_Signal_T2bW_850_50"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_950_300"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_950_50"]->Draw("histsame");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_950_50"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,50)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_950_300"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,300)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2bW_850_50"], "#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (850,50)", "l");
        } else if(i>=22&&i<26){
            //plot T2tt + 1 T2tb
            hist[histonames[i] + "_Signal_T2tb_900_50"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_950_300"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_950_50"]->Draw("histsame");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_950_50"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,50)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_950_300"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (950,300)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tb_900_50"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} / #tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (900,50)", "l");
        } else if(i>=26&&i<30){
            //plot T2bW
            hist[histonames[i] + "_Signal_T2bW_500_300"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2bW_850_300"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2bW_850_50"]->Draw("histsame");
            leg2->AddEntry(hist["MET_2j_Signal_T2bW_850_50"], "#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (850,50)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2bW_850_300"], "#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (850,300)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2bW_500_300"], "#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1} (500,300)", "l");
        } else {
            //plot compressed T2tt
            hist[histonames[i] + "_Signal_T2tt_350_250"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_425_250"]->Draw("histsame");
            hist[histonames[i] + "_Signal_T2tt_425_300"]->Draw("histsame");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_425_300"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (425,300)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_425_250"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (425,250)", "l");
            leg2->AddEntry(hist["MET_2j_Signal_T2tt_350_250"], "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (350,250)", "l");
        }
        hist[stackname]->Draw("sameaxis");
        leg1->Draw();
        leg2->Draw();
        tCMS->Draw();
        tPrel->Draw();
        tLumi->Draw();
        string outname = stackname + ".eps";
        if(logy) outname = "Log_" + outname;
        else     outname = "Lin_" + outname;
        c1->SaveAs(outname.c_str());
        c1->Clear();
    }
        //plot 23j htmod data vs sim
    //plot 4j ltmod data vs sim
    //plot 4j htmod data vs sim
    //plot 5j data vs sim
 

}