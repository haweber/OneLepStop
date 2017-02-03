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

string tablefragment (TH1D *h, int b, bool data=false){
    stringstream ss;
    if(data) ss << (int)h->GetBinContent(b);
    else if(h->GetBinContent(b)<0.005) return "---";
    else if(h->GetBinContent(b)>=99.95) ss << fixed << setprecision(0) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    else if(h->GetBinContent(b)>=0.995) ss << fixed << setprecision(1) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    else ss << fixed << setprecision(2) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    return ss.str();
}

string tableline(string firstbin, int b, TH1D *hLL, TH1D *htt1l, TH1D *h0b, TH1D *hZ, TH1D *hbg, TH1D *hdata){
    stringstream ss;
    ss << firstbin << " & " << tablefragment(hLL,b) << " & " << tablefragment(htt1l,b) << " & " << tablefragment(h0b,b) << " & " << tablefragment(hZ,b) << " & " << tablefragment(hbg,b) << " & " << tablefragment(hdata,b,true) << " \\\\" << endl;
    return ss.str();
}

void MakeMacroRegionsTableAndResults(){
    
    TFile *f = new TFile("ResultRootFileMoriond17.root");
  f->cd();
  TH1D *tData = (TH1D*)f->Get("rpt_Data");
  TH1D *tLL   = (TH1D*)f->Get("rpt_LLest");
  TH1D *tW1l  = (TH1D*)f->Get("rpt_0best");
  TH1D *ttt1l = (TH1D*)f->Get("rpt_tt1l");
    TH1D *tttz  = (TH1D*)f->Get("rpt_znunu");
    TH1D *tbg  = (TH1D*)f->Get("rpt_bg");

  //TH1D *Data = (TH1D*)tData  ->Clone("Data");
  TH1D *LL   = new TH1D("LLest","",6,0,6);
  TH1D *W1l  = new TH1D("0best","",6,0,6);
  TH1D *tt1l = new TH1D("tt1l","",6,0,6);
    TH1D *ttz= new TH1D("znunu","",6,0,6);
    TH1D *bg = new TH1D("bg","",6,0,6);
    LL->SetBinContent(1,tLL->GetBinContent(4)+tLL->GetBinContent(7));
    LL->SetBinError(1,sqrt(pow(tLL->GetBinError(4),2)+pow(tLL->GetBinError(7),2)));
    LL->SetBinContent(2,tLL->GetBinContent(11)+tLL->GetBinContent(12));
    LL->SetBinError(2,sqrt(pow(tLL->GetBinError(11),2)+pow(tLL->GetBinError(12),2)));
    LL->SetBinContent(3,tLL->GetBinContent(24)+tLL->GetBinContent(25));
    LL->SetBinError(3,sqrt(pow(tLL->GetBinError(24),2)+pow(tLL->GetBinError(25),2)));
    LL->SetBinContent(4,tLL->GetBinContent(15)+tLL->GetBinContent(16));
    LL->SetBinError(4,sqrt(pow(tLL->GetBinError(15),2)+pow(tLL->GetBinError(16),2)));
    LL->SetBinContent(5,tLL->GetBinContent(21)+tLL->GetBinContent(27));
    LL->SetBinError(5,sqrt(pow(tLL->GetBinError(21),2)+pow(tLL->GetBinError(27),2)));
    LL->SetBinContent(6,tLL->GetBinContent(30)+tLL->GetBinContent(31));
    LL->SetBinError(6,sqrt(pow(tLL->GetBinError(30),2)+pow(tLL->GetBinError(31),2)));
    W1l->SetBinContent(1,tW1l->GetBinContent(4)+tW1l->GetBinContent(7));
    W1l->SetBinError(1,sqrt(pow(tW1l->GetBinError(4),2)+pow(tW1l->GetBinError(7),2)));
    W1l->SetBinContent(2,tW1l->GetBinContent(11)+tW1l->GetBinContent(12));
    W1l->SetBinError(2,sqrt(pow(tW1l->GetBinError(11),2)+pow(tW1l->GetBinError(12),2)));
    W1l->SetBinContent(3,tW1l->GetBinContent(24)+tW1l->GetBinContent(25));
    W1l->SetBinError(3,sqrt(pow(tW1l->GetBinError(24),2)+pow(tW1l->GetBinError(25),2)));
    W1l->SetBinContent(4,tW1l->GetBinContent(15)+tW1l->GetBinContent(16));
    W1l->SetBinError(4,sqrt(pow(tW1l->GetBinError(15),2)+pow(tW1l->GetBinError(16),2)));
    W1l->SetBinContent(5,tW1l->GetBinContent(21)+tW1l->GetBinContent(27));
    W1l->SetBinError(5,sqrt(pow(tW1l->GetBinError(21),2)+pow(tW1l->GetBinError(27),2)));
    W1l->SetBinContent(6,tW1l->GetBinContent(30)+tW1l->GetBinContent(31));
    W1l->SetBinError(6,sqrt(pow(tW1l->GetBinError(30),2)+pow(tW1l->GetBinError(31),2)));
    tt1l->SetBinContent(1,ttt1l->GetBinContent(4)+ttt1l->GetBinContent(7));
    tt1l->SetBinError(1,sqrt(pow(ttt1l->GetBinError(4),2)+pow(ttt1l->GetBinError(7),2)));
    tt1l->SetBinContent(2,ttt1l->GetBinContent(11)+ttt1l->GetBinContent(12));
    tt1l->SetBinError(2,sqrt(pow(ttt1l->GetBinError(11),2)+pow(ttt1l->GetBinError(12),2)));
    tt1l->SetBinContent(3,ttt1l->GetBinContent(24)+ttt1l->GetBinContent(25));
    tt1l->SetBinError(3,sqrt(pow(ttt1l->GetBinError(24),2)+pow(ttt1l->GetBinError(25),2)));
    tt1l->SetBinContent(4,ttt1l->GetBinContent(15)+ttt1l->GetBinContent(16));
    tt1l->SetBinError(4,sqrt(pow(ttt1l->GetBinError(15),2)+pow(ttt1l->GetBinError(16),2)));
    tt1l->SetBinContent(5,ttt1l->GetBinContent(21)+ttt1l->GetBinContent(27));
    tt1l->SetBinError(5,sqrt(pow(ttt1l->GetBinError(21),2)+pow(ttt1l->GetBinError(27),2)));
    tt1l->SetBinContent(6,ttt1l->GetBinContent(30)+ttt1l->GetBinContent(31));
    tt1l->SetBinError(6,sqrt(pow(ttt1l->GetBinError(30),2)+pow(ttt1l->GetBinError(31),2)));
    ttz->SetBinContent(1,tttz->GetBinContent(4)+tttz->GetBinContent(7));
    ttz->SetBinError(1,sqrt(pow(tttz->GetBinError(4),2)+pow(tttz->GetBinError(7),2)));
    ttz->SetBinContent(2,tttz->GetBinContent(11)+tttz->GetBinContent(12));
    ttz->SetBinError(2,sqrt(pow(tttz->GetBinError(11),2)+pow(tttz->GetBinError(12),2)));
    ttz->SetBinContent(3,tttz->GetBinContent(24)+tttz->GetBinContent(25));
    ttz->SetBinError(3,sqrt(pow(tttz->GetBinError(24),2)+pow(tttz->GetBinError(25),2)));
    ttz->SetBinContent(4,tttz->GetBinContent(15)+tttz->GetBinContent(16));
    ttz->SetBinError(4,sqrt(pow(tttz->GetBinError(15),2)+pow(tttz->GetBinError(16),2)));
    ttz->SetBinContent(5,tttz->GetBinContent(21)+tttz->GetBinContent(27));
    ttz->SetBinError(5,sqrt(pow(tttz->GetBinError(21),2)+pow(tttz->GetBinError(27),2)));
    ttz->SetBinContent(6,tttz->GetBinContent(30)+tttz->GetBinContent(31));
    ttz->SetBinError(6,sqrt(pow(tttz->GetBinError(30),2)+pow(tttz->GetBinError(31),2)));
    bg->SetBinContent(1,tbg->GetBinContent(4)+tbg->GetBinContent(7));
    bg->SetBinError(1,sqrt(pow(tbg->GetBinError(4),2)+pow(tbg->GetBinError(7),2)));
    bg->SetBinContent(2,tbg->GetBinContent(11)+tbg->GetBinContent(12));
    bg->SetBinError(2,sqrt(pow(tbg->GetBinError(11),2)+pow(tbg->GetBinError(12),2)));
    bg->SetBinContent(3,tbg->GetBinContent(24)+tbg->GetBinContent(25));
    bg->SetBinError(3,sqrt(pow(tbg->GetBinError(24),2)+pow(tbg->GetBinError(25),2)));
    bg->SetBinContent(4,tbg->GetBinContent(15)+tbg->GetBinContent(16));
    bg->SetBinError(4,sqrt(pow(tbg->GetBinError(15),2)+pow(tbg->GetBinError(16),2)));
    bg->SetBinContent(5,tbg->GetBinContent(21)+tbg->GetBinContent(27));
    bg->SetBinError(5,sqrt(pow(tbg->GetBinError(21),2)+pow(tbg->GetBinError(27),2)));
    bg->SetBinContent(6,tbg->GetBinContent(30)+tbg->GetBinContent(31));
    bg->SetBinError(6,sqrt(pow(tbg->GetBinError(30),2)+pow(tbg->GetBinError(31),2)));
    
    TH1D *Data = new TH1D("Data","",6,0,6);
    Data->SetBinErrorOption(TH1::kPoisson);
    for(int n = 1; n<=tData->GetBinContent(4); ++n) Data->Fill(0.5,1);
    for(int n = 1; n<=tData->GetBinContent(7); ++n) Data->Fill(0.5,1);
    for(int n = 1; n<=tData->GetBinContent(11); ++n) Data->Fill(1.5,1);
    for(int n = 1; n<=tData->GetBinContent(12); ++n) Data->Fill(1.5,1);
    for(int n = 1; n<=tData->GetBinContent(24); ++n) Data->Fill(2.5,1);
    for(int n = 1; n<=tData->GetBinContent(25); ++n) Data->Fill(2.5,1);
    for(int n = 1; n<=tData->GetBinContent(15); ++n) Data->Fill(3.5,1);
    for(int n = 1; n<=tData->GetBinContent(16); ++n) Data->Fill(3.5,1);
    for(int n = 1; n<=tData->GetBinContent(21); ++n) Data->Fill(4.5,1);
    for(int n = 1; n<=tData->GetBinContent(27); ++n) Data->Fill(4.5,1);
    for(int n = 1; n<=tData->GetBinContent(30); ++n) Data->Fill(5.5,1);
    for(int n = 1; n<=tData->GetBinContent(31); ++n) Data->Fill(5.5,1);
    
    TFile *fsig = new TFile("../Interpretation/SignalDistribution_forresult.root","READ");
    TH1D *ttt900  = (TH1D*)fsig->Get("T2tt_900_300_gencontcorr");
    TH1D *ttb600  = (TH1D*)fsig->Get("T2tb_600_300_gencontcorr");
    TH1D *tbW900  = (TH1D*)fsig->Get("T2bW_900_50_gencontcorr");
    TH1D *tt900   = new TH1D("T2tt_900_300","",6,0,6);
    TH1D *tb600   = new TH1D("T2tb_600_300","",6,0,6);
    TH1D *bW900   = new TH1D("T2bW_900_50","",6,0,6);
    tt900->SetBinContent(1,ttt900->GetBinContent(4)+ttt900->GetBinContent(7));
    tt900->SetBinError(1,sqrt(pow(ttt900->GetBinError(4),2)+pow(ttt900->GetBinError(7),2)));
    tt900->SetBinContent(2,ttt900->GetBinContent(11)+ttt900->GetBinContent(12));
    tt900->SetBinError(2,sqrt(pow(ttt900->GetBinError(11),2)+pow(ttt900->GetBinError(12),2)));
    tt900->SetBinContent(3,ttt900->GetBinContent(24)+ttt900->GetBinContent(25));
    tt900->SetBinError(3,sqrt(pow(ttt900->GetBinError(24),2)+pow(ttt900->GetBinError(25),2)));
    tt900->SetBinContent(4,ttt900->GetBinContent(15)+ttt900->GetBinContent(16));
    tt900->SetBinError(4,sqrt(pow(ttt900->GetBinError(15),2)+pow(ttt900->GetBinError(16),2)));
    tt900->SetBinContent(5,ttt900->GetBinContent(21)+ttt900->GetBinContent(27));
    tt900->SetBinError(5,sqrt(pow(ttt900->GetBinError(21),2)+pow(ttt900->GetBinError(27),2)));
    tt900->SetBinContent(6,ttt900->GetBinContent(30)+ttt900->GetBinContent(31));
    tt900->SetBinError(6,sqrt(pow(ttt900->GetBinError(30),2)+pow(ttt900->GetBinError(31),2)));
    tb600->SetBinContent(1,ttb600->GetBinContent(4)+ttb600->GetBinContent(7));
    tb600->SetBinError(1,sqrt(pow(ttb600->GetBinError(4),2)+pow(ttb600->GetBinError(7),2)));
    tb600->SetBinContent(2,ttb600->GetBinContent(11)+ttb600->GetBinContent(12));
    tb600->SetBinError(2,sqrt(pow(ttb600->GetBinError(11),2)+pow(ttb600->GetBinError(12),2)));
    tb600->SetBinContent(3,ttb600->GetBinContent(24)+ttb600->GetBinContent(25));
    tb600->SetBinError(3,sqrt(pow(ttb600->GetBinError(24),2)+pow(ttb600->GetBinError(25),2)));
    tb600->SetBinContent(4,ttb600->GetBinContent(15)+ttb600->GetBinContent(16));
    tb600->SetBinError(4,sqrt(pow(ttb600->GetBinError(15),2)+pow(ttb600->GetBinError(16),2)));
    tb600->SetBinContent(5,ttb600->GetBinContent(21)+ttb600->GetBinContent(27));
    tb600->SetBinError(5,sqrt(pow(ttb600->GetBinError(21),2)+pow(ttb600->GetBinError(27),2)));
    tb600->SetBinContent(6,ttb600->GetBinContent(30)+ttb600->GetBinContent(31));
    tb600->SetBinError(6,sqrt(pow(ttb600->GetBinError(30),2)+pow(ttb600->GetBinError(31),2)));
    bW900->SetBinContent(1,tbW900->GetBinContent(4)+tbW900->GetBinContent(7));
    bW900->SetBinError(1,sqrt(pow(tbW900->GetBinError(4),2)+pow(tbW900->GetBinError(7),2)));
    bW900->SetBinContent(2,tbW900->GetBinContent(11)+tbW900->GetBinContent(12));
    bW900->SetBinError(2,sqrt(pow(tbW900->GetBinError(11),2)+pow(tbW900->GetBinError(12),2)));
    bW900->SetBinContent(3,tbW900->GetBinContent(24)+tbW900->GetBinContent(25));
    bW900->SetBinError(3,sqrt(pow(tbW900->GetBinError(24),2)+pow(tbW900->GetBinError(25),2)));
    bW900->SetBinContent(4,tbW900->GetBinContent(15)+tbW900->GetBinContent(16));
    bW900->SetBinError(4,sqrt(pow(tbW900->GetBinError(15),2)+pow(tbW900->GetBinError(16),2)));
    bW900->SetBinContent(5,tbW900->GetBinContent(21)+tbW900->GetBinContent(27));
    bW900->SetBinError(5,sqrt(pow(tbW900->GetBinError(21),2)+pow(tbW900->GetBinError(27),2)));
    bW900->SetBinContent(6,tbW900->GetBinContent(30)+tbW900->GetBinContent(31));
    bW900->SetBinError(6,sqrt(pow(tbW900->GetBinError(30),2)+pow(tbW900->GetBinError(31),2)));
    
    //TCanvas *c1 = new TCanvas("c1", "c1",50,50,950,650);
    TCanvas *c1 = new TCanvas("c1", "c1",50,50,1000,750);
    //TCanvas *c1 = new TCanvas("c1", "c1",50,50,1500,1125);
    //TCanvas *c1 = new TCanvas("c1", "c1",50,50,667,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetErrorX(0.5); 
   //c1->Range(-6.311689,-1.891383,28.75325,4.56342);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   //c1->SetLogy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.15);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
    //c1->SetBottomMargin(0.15);
    c1->SetBottomMargin(0.15);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   gStyle->SetHatchesLineWidth(0);
    TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0.,0.21,1,1);
    plotpad->Draw();
    plotpad->cd();
    plotpad->SetFillColor(0);
    plotpad->SetBorderMode(0);
    plotpad->SetBorderSize(2);
    //plotpad->SetLogy();
    plotpad->SetTickx(1);
    plotpad->SetTicky(1);
    plotpad->SetLeftMargin(0.10);
    plotpad->SetRightMargin(0.05);
    plotpad->SetTopMargin(0.07);
    plotpad->SetBottomMargin(0.16);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);

   THStack *Sum = new THStack();
   Sum->SetName("Sum");
   //Sum->SetTitle(";Signal region;Events");
   Sum->SetTitle(";E_{T}^{miss} [GeV];Events");
   Sum->SetMinimum(0);
   Sum->SetMaximum(20.);//get's me to 40
   TH1F *hSum = new TH1F("hSum","",6,0,6);
   hSum->SetMinimum(0);
   hSum->SetMaximum(20.);
   hSum->SetDirectory(0);
   hSum->SetStats(0);
   // hSum->Draw();
   // hSum->GetYaxis()->SetRangeUser(0.,35.);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   hSum->SetLineColor(ci);
   hSum->SetLineStyle(0);
   hSum->SetMarkerStyle(20);
   hSum->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
    hSum->GetXaxis()->SetBinLabel( 1,"#geq#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel( 2,"#geq#scale[0.5]{ }550");
    hSum->GetXaxis()->SetBinLabel( 3,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel( 4,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel( 5,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel( 6,"#geq#scale[0.5]{ }450");
    //hSum->GetXaxis()->SetBit(TAxis::kLabelsVert);
    //hSum->GetXaxis()->SetBit(TAxis::kLabelsDown);
   hSum->GetXaxis()->SetLabelFont(42);
    //hSum->GetXaxis()->SetLabelOffset(0.007);
    hSum->GetXaxis()->SetLabelOffset(0.004);
    //hSum->GetXaxis()->SetLabelSize(0.05);
    hSum->GetXaxis()->SetLabelSize(0.0);//0.055
   hSum->GetXaxis()->SetTitleSize(0.0);
    //hSum->GetXaxis()->SetTitleOffset(1.15);
    hSum->GetXaxis()->SetTitleOffset(2.12);
   hSum->GetXaxis()->SetTitleFont(42);
   hSum->GetYaxis()->SetTitle("Events");
   hSum->GetYaxis()->SetLabelFont(42);
   hSum->GetYaxis()->SetLabelOffset(0.007);
   hSum->GetYaxis()->SetLabelSize(0.04);
   hSum->GetYaxis()->SetTitleSize(0.06);
   hSum->GetYaxis()->SetTitleOffset(0.775);
   hSum->GetYaxis()->SetTitleFont(42);
   hSum->GetZaxis()->SetLabelFont(42);
   hSum->GetZaxis()->SetLabelOffset(0.007);
   hSum->GetZaxis()->SetLabelSize(0.05);
   hSum->GetZaxis()->SetTitleSize(0.06);
   hSum->GetZaxis()->SetTitleFont(42);
   Sum->SetHistogram(hSum);
    
    //TLegend *leg = new TLegend(0.4992416,0.4811189,0.898906,0.7503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.4992416,0.4811189,0.698906,0.7503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.6992416,0.2811189,0.898906,0.4503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.6992416,0.3311189,0.898906,0.7903497,NULL,"brNDC");
    TLegend *leg = new TLegend(0.125,0.74,0.585,0.9,NULL,"brNDC");
    leg-> SetNColumns(2);
   leg->SetBorderSize(0);
    leg->SetTextSize(0.04);
    //leg->SetTextSize(0.03475);
    leg->SetTextFont(42);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(2);
    leg->SetFillColor(0);
    leg->SetFillStyle(1001);
/*
    TLegend *legs = new TLegend(0.4402416,0.788,0.606,0.8988,NULL,"brNDC");
    legs-> SetNColumns(2);
    legs-> SetColumnSeparation(1.);
    legs->SetBorderSize(0);
    legs->SetTextSize(0.0325);
    legs->SetTextFont(42);
    legs->SetLineColor(1);
    legs->SetLineStyle(1);
    legs->SetLineWidth(2);
    legs->SetFillColor(0);
    legs->SetFillStyle(1001);
    */
    //TLegend *legd = new TLegend(0.7835,0.829,0.912,0.908,NULL,"brNDC");
    TLegend *legd = new TLegend(0.595,0.74,0.7,0.9,NULL,"brNDC");
    //leg-> SetNColumns(2);
    legd->SetBorderSize(0);
    legd->SetTextSize(0.04);
    //leg->SetTextSize(0.03475);
    legd->SetTextFont(42);
    legd->SetLineColor(1);
    legd->SetLineStyle(1);
    legd->SetLineWidth(2);
    legd->SetFillColor(0);
    legd->SetFillStyle(1001);
 
    //orig kCyan-3
    //tried kCyan+2
   LL->SetFillColor(  kCyan+2);
   LL->SetMarkerColor(kCyan+2);
   LL->SetLineColor(  kCyan+2);
   LL->SetMarkerStyle(1);
   LL->SetLineStyle(0);
   Sum->Add(LL,"");

    //orig: kRed-7
    //tried kRed-6
   tt1l->SetFillColor(  kRed-6);
   tt1l->SetMarkerColor(kRed-6);
   tt1l->SetLineColor(  kRed-6);
   tt1l->SetMarkerStyle(1);
   tt1l->SetLineStyle(0);
   Sum->Add(tt1l,"");
    //leg->AddEntry(tt1l, "t#bar{t}#rightarrow1#font[12]{l}", "f");
   // leg->AddEntry(tt1l, "t{t}\\to1\\ell", "f");

    Data->SetLineStyle(0);
    Data->SetLineWidth(2);
    Data->SetLineColor(1);
    Data->SetMarkerStyle(20);
    //Data->Draw("sameE");
    //Data->Draw("sameE0X0");

    //orig: kOrange-2
    //tried kOrange-3
   W1l->SetFillColor(  kOrange-3);
   W1l->SetMarkerColor(kOrange-3);
   W1l->SetLineColor(  kOrange-3);
   W1l->SetMarkerStyle(1);
   W1l->SetLineStyle(0);
   Sum->Add(W1l,"");
    //leg->AddEntry(W1l, "1#font[12]{l} (not from t)", "f");
   // leg->AddEntry(W1l, "\\text{1}\\ell\\text{ (not from t)}", "f");

    //orig: kMagenta-5
    //tried kMagenta-2
   ttz->SetFillColor(  kMagenta-2);
   ttz->SetMarkerColor(kMagenta-2);
   ttz->SetLineColor(  kMagenta-2);
   ttz->SetMarkerStyle(1);
   ttz->SetLineStyle(0);
   Sum->Add(ttz,"");
   // leg->AddEntry(ttz, "\\text{Z}\\to\\nu\\nu", "f");


   Sum->Draw("hist");

    gStyle->SetHatchesLineWidth(1);
    gStyle->SetHatchesSpacing(3);
    bg->SetFillColor(14);
    //bg->SetFillStyle(3013);
    bg->SetFillStyle(3144);
    //bg->SetFillStyle(3144);
    //bg->SetFillStyle(3244);
    bg->SetLineColor(0);
    bg->SetLineWidth(0);
    bg->SetLineStyle(0);
    bg->SetMarkerStyle(0);
    bg->Draw("sameE2");
    
   Data->SetLineStyle(0);
   Data->SetLineWidth(2);
   Data->SetLineColor(1);
   Data->SetMarkerStyle(20);
    //Data->Draw("sameE");
    Data->Draw("sameE0X0");
    //leg->AddEntry(Data, "Data", "ep");
    
    tb600->SetLineStyle(2);
    tb600->SetLineWidth(3);
    tb600->SetLineColor(  kMagenta-4);
    tb600->SetMarkerColor(kMagenta-4);
    tb600->Draw("samehist");
    
    bW900->SetLineStyle(2);
    bW900->SetLineWidth(3);
    bW900->SetLineColor(  kSpring-2);
    bW900->SetMarkerColor(kSpring-2);
    bW900->Draw("samehist");
    
    tt900->SetLineStyle(2);
    tt900->SetLineWidth(3);
    tt900->SetLineColor(  kAzure+6);
    tt900->SetMarkerColor(kAzure+6);
    tt900->Draw("samehist");
    
    leg->AddEntry(LL, "Lost Lepton", "f");
    leg->AddEntry(W1l, "1#font[12]{l} (not from t)", "f");
    leg->AddEntry(ttz, "Z#rightarrow#nu#bar{#nu}", "f");
    leg->AddEntry(bg, "Total uncertainty", "f");
    leg->AddEntry(tt1l, "t#bar{t}#rightarrow1#font[12]{l}", "f");
    leg->AddEntry(Data, "Data", "ep");

    legd->AddEntry(tt900, " #tilde{t}#rightarrow t#tilde{#chi}_{1} (900,300)", "l");
    legd->AddEntry(bW900, " #tilde{t}#rightarrow b#tilde{#chi}_{1} (900,50)", "l");
    legd->AddEntry(tb600, " #tilde{t}#rightarrow t#tilde{#chi}_{1} / #tilde{t}#rightarrow b#tilde{#chi}_{1} (600,300)", "l");
    
    leg->Draw();
    //legs->Draw();
    legd->Draw();

    TLatex *tA1 = new TLatex(0.1067,0.15,"#leq#scale[0.5]{ }3#scale[0.5]{ }jets, t_{mod}#scale[0.5]{ }>#scale[0.5]{ }10");
    tA1->SetNDC();tA1->SetTextAlign(13);tA1->SetTextFont(42);tA1->SetTextSize(0.035);tA1->SetLineWidth(2);
    tA1->Draw();
    TLatex *tA2 = new TLatex(0.1067,0.1,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }600#scale[0.5]{ }GeV");
    tA2->SetNDC();tA2->SetTextAlign(13);tA2->SetTextFont(42);tA2->SetTextSize(0.035);tA2->SetLineWidth(2);
    tA2->Draw();
    //TLatex *tA3 = new TLatex(0.1067,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }600#scale[0.5]{ }GeV");
    //tA3->SetNDC();tA3->SetTextAlign(13);tA3->SetTextFont(42);tA3->SetTextSize(0.035);tA3->SetLineWidth(2);
    //tA3->Draw();
    TLatex *tB1 = new TLatex(0.2485,0.15,"#geq#scale[0.5]{ }4#scale[0.5]{ }jets, t_{mod}#scale[0.5]{ }#leq#scale[0.5]{ }0");
    tB1->SetNDC();tB1->SetTextAlign(13);tB1->SetTextFont(42);tB1->SetTextSize(0.035);tB1->SetLineWidth(2);
    tB1->Draw();
    TLatex *tB2 = new TLatex(0.2485,0.1,"M_{#font[12]{l}b}#scale[0.5]{ }#leq#scale[0.5]{ }175#scale[0.5]{ }GeV");
    tB2->SetNDC();tB2->SetTextAlign(13);tB2->SetTextFont(42);tB2->SetTextSize(0.035);tB2->SetLineWidth(2);
    tB2->Draw();
    TLatex *tB3 = new TLatex(0.2485,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }550#scale[0.5]{ }GeV");
    tB3->SetNDC();tB3->SetTextAlign(13);tB3->SetTextFont(42);tB3->SetTextSize(0.035);tB3->SetLineWidth(2);
    tB3->Draw();
    TLatex *tC1 = new TLatex(0.39,0.15,"#geq#scale[0.5]{ }4#scale[0.5]{ }jets, t_{mod}#scale[0.5]{ }>#scale[0.5]{ }10");
    tC1->SetNDC();tC1->SetTextAlign(13);tC1->SetTextFont(42);tC1->SetTextSize(0.035);tC1->SetLineWidth(2);
    tC1->Draw();
    TLatex *tC2 = new TLatex(0.39,0.1,"M_{#font[12]{l}b}#scale[0.5]{ }#leq#scale[0.5]{ }175#scale[0.5]{ }GeV");
    tC2->SetNDC();tC2->SetTextAlign(13);tC2->SetTextFont(42);tC2->SetTextSize(0.035);tC2->SetLineWidth(2);
    tC2->Draw();
    TLatex *tC3 = new TLatex(0.39,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }450#scale[0.5]{ }GeV");
    tC3->SetNDC();tC3->SetTextAlign(13);tC3->SetTextFont(42);tC3->SetTextSize(0.035);tC3->SetLineWidth(2);
    tC3->Draw();
    TLatex *tD1 = new TLatex(0.538,0.15,"#geq#scale[0.5]{ }4#scale[0.5]{ }jets, t_{mod}#scale[0.5]{ }#leq#scale[0.5]{ }0");
    tD1->SetNDC();tD1->SetTextAlign(13);tD1->SetTextFont(42);tD1->SetTextSize(0.035);tD1->SetLineWidth(2);
    tD1->Draw();
    TLatex *tD2 = new TLatex(0.538,0.1,"M_{#font[12]{l}b}#scale[0.5]{ }>#scale[0.5]{ }175#scale[0.5]{ }GeV");
    tD2->SetNDC();tD2->SetTextAlign(13);tD2->SetTextFont(42);tD2->SetTextSize(0.035);tD2->SetLineWidth(2);
    tD2->Draw();
    TLatex *tD3 = new TLatex(0.538,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }450#scale[0.5]{ }GeV");
    tD3->SetNDC();tD3->SetTextAlign(13);tD3->SetTextFont(42);tD3->SetTextSize(0.035);tD3->SetLineWidth(2);
    tD3->Draw();
    TLatex *tE1 = new TLatex(0.682,0.15,"#geq#scale[0.5]{ }4#scale[0.5]{ }jets, t_{mod}#scale[0.5]{ }>#scale[0.5]{ }0");
    tE1->SetNDC();tE1->SetTextAlign(13);tE1->SetTextFont(42);tE1->SetTextSize(0.035);tE1->SetLineWidth(2);
    tE1->Draw();
    TLatex *tE2 = new TLatex(0.682,0.1,"M_{#font[12]{l}b}#scale[0.5]{ }>#scale[0.5]{ }175#scale[0.5]{ }GeV");
    tE2->SetNDC();tE2->SetTextAlign(13);tE2->SetTextFont(42);tE2->SetTextSize(0.035);tE2->SetLineWidth(2);
    tE2->Draw();
    TLatex *tE3 = new TLatex(0.682,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }550#scale[0.5]{ }GeV");
    tE3->SetNDC();tE3->SetTextAlign(13);tE3->SetTextFont(42);tE3->SetTextSize(0.035);tE3->SetLineWidth(2);
    tE3->Draw();
    TLatex *tF1 = new TLatex(0.828,0.15,"compressed");
    tF1->SetNDC();tF1->SetTextAlign(13);tF1->SetTextFont(42);tF1->SetTextSize(0.035);tF1->SetLineWidth(2);
    tF1->Draw();
    TLatex *tF2 = new TLatex(0.828,0.1,"region");
    tF2->SetNDC();tF2->SetTextAlign(13);tF2->SetTextFont(42);tF2->SetTextSize(0.035);tF2->SetLineWidth(2);
    tF2->Draw();
    TLatex *tF3 = new TLatex(0.828,0.05,"E_{T}^{miss}#scale[0.5]{ }>#scale[0.5]{ }450#scale[0.5]{ }GeV");
    tF3->SetNDC();tF3->SetTextAlign(13);tF3->SetTextFont(42);tF3->SetTextSize(0.035);tF3->SetLineWidth(2);
    tF3->Draw();
    /*
    TLine *l1 = new TLine(1,0.8,1,0.01);
    l1->SetLineWidth(2);
    l1->SetLineStyle(7);
    l1->Draw();
    TLine *l2 = new TLine(2,0.8,2,0.01);
    l2->SetLineWidth(2);
    l2->SetLineStyle(7);
    l2->Draw();
    TLine *l3 = new TLine(3,0.8,3,0.01);
    l3->SetLineWidth(2);
    l3->SetLineStyle(7);
    l3->Draw();
    TLine *l4 = new TLine(4,0.8,4,0.01);
    l4->SetLineWidth(2);
    l4->SetLineStyle(7);
    l4->Draw();
    TLine *l5 = new TLine(5,0.8,5,0.01);
    l5->SetLineWidth(2);
    l5->SetLineStyle(7);
    l5->Draw();
     */
    
    TMathText *mt = new TMathText();
    mt->SetNDC();
    mt->SetTextAlign(23);
    mt->SetTextSize(0.042);
    mt->SetTextColor(1);
    //mt->DrawMathText(0.246,0.787,"\\ell");
    //mt->DrawMathText(0.404,0.891,"\\ell");
    TLatex *tlx = new TLatex();
    tlx->SetTextFont(42);
    tlx->SetNDC();
    tlx->SetTextAlign(23);
    tlx->SetTextSize(0.026);
    tlx->SetTextColor(1);
    tlx->DrawLatex(0.683,0.787,"\\pm");
    tlx->DrawLatex(0.763,0.785,"0");
    tlx->DrawLatex(0.688,0.838,"\\pm");
    tlx->DrawLatex(0.684,0.888,"0");

    //final CMS style
    //TLatex *tLumi = new TLatex(0.95,0.944,"18.1 fb^{-1} (13 TeV)");
    TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
    tLumi->SetNDC();
    tLumi->SetTextAlign(31);
    tLumi->SetTextFont(42);
    tLumi->SetTextSize(0.042);
    tLumi->SetLineWidth(2);
    tLumi->Draw();
    TLatex *tCMS = new TLatex(0.1,0.944,"CMS");
    tCMS->SetNDC();
    tCMS->SetTextAlign(11);
    tCMS->SetTextFont(61);
    tCMS->SetTextSize(0.0525);
    tCMS->SetLineWidth(2);
    tCMS->Draw();
    TLatex *tPrel = new TLatex(0.185,0.944,"Preliminary");
    tPrel->SetNDC();
    tPrel->SetTextAlign(11);
    tPrel->SetTextFont(52);
    tPrel->SetTextSize(0.042);
    tPrel->SetLineWidth(2);
    tPrel->Draw();
    hSum->Draw("sameaxis");
    
    c1->cd();
    TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.01863354,1,0.2069441);
    ratiopad->Draw();
    ratiopad->cd();
    //ratiopad->SetLogy();
    //ratiopad->Range(71.42856,0.5346154,785.7143,1.303846);
    ratiopad->SetFillColor(0);
    ratiopad->SetBorderMode(0);
    ratiopad->SetBorderSize(2);
    ratiopad->SetTickx(1);
    ratiopad->SetTicky(1);
    ratiopad->SetLeftMargin(0.1);
    ratiopad->SetRightMargin(0.05);
    ratiopad->SetTopMargin(0.07);
    ratiopad->SetBottomMargin(0.28);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    
    TH1D *hMCrat = (TH1D*)bg->Clone("MCrat");
    hMCrat->Divide(bg);
    
    TH1D *hbgtemp =(TH1D*)bg->Clone("hbgtemp");
    for(int i = 1; i<=Data->GetNbinsX(); ++i) hbgtemp->SetBinError(i,0);

    
    TH1D *hDatarat = (TH1D*)Data->Clone("Datarat");
    hDatarat->SetBinErrorOption(TH1::kPoisson);
    hDatarat->Divide(hbgtemp);
    for(int i = 1; i<=Data->GetNbinsX(); ++i) { if(hDatarat->GetBinContent(i)==0) hDatarat->SetBinContent(i,-1); }

    hMCrat->SetFillColor(14);
    //hMCrat->SetFillStyle(3013);
    hMCrat->SetFillStyle(3144);
    hMCrat->SetMinimum(0.33);
    hMCrat->SetMaximum(1.67);
    ratiopad->cd();
    hMCrat->GetXaxis()->SetTitle("Aggregated signal regions");
    hMCrat->GetXaxis()->SetLabelFont(42);
    hMCrat->GetXaxis()->SetLabelSize(0);
    hMCrat->GetXaxis()->SetTitleSize(0.2);
    hMCrat->GetXaxis()->SetTickLength(0.09);
    hMCrat->GetXaxis()->SetTitleOffset(0.5);
    hMCrat->GetXaxis()->SetTitleFont(42);
    hMCrat->GetXaxis()->SetNdivisions(505);
    hMCrat->GetYaxis()->SetTitle("Data / pred.");
    hMCrat->GetYaxis()->SetNdivisions(303);
    hMCrat->GetYaxis()->SetLabelFont(42);
    hMCrat->GetYaxis()->SetLabelSize(0.17);
    hMCrat->GetYaxis()->SetLabelOffset(0.005);
    hMCrat->GetYaxis()->SetTitleSize(0.18);
    hMCrat->GetYaxis()->SetTitleOffset(0.26);
    hMCrat->GetYaxis()->SetTitleFont(42);
    hMCrat->GetZaxis()->SetLabelFont(42);
    hMCrat->GetZaxis()->SetLabelSize(0.035);
    hMCrat->GetZaxis()->SetTitleSize(0.035);
    hMCrat->GetZaxis()->SetTitleFont(42);
    hMCrat->Draw("E2");
    TLine *rline = new TLine(0,1,6,1);
    rline->SetLineWidth(2);
    rline->SetLineStyle(7);
    rline->Draw();
    hDatarat->Draw("sameE0X0");
    /*
    TLatex *texlu = new TLatex(-0.155,2.27064,"3");
    texlu->SetTextFont(42);
    texlu->SetTextSize(0.17);
    texlu->SetLineWidth(2);
    texlu->Draw();
    TLatex *texld = new TLatex(-0.3,0.2336995,"0.3");
    texld->SetTextFont(42);
    texld->SetTextSize(0.17);
    texld->SetLineWidth(2);
    texld->Draw();
     */
    hMCrat->Draw("sameaxis");

    c1->cd();
   c1->Modified();
   c1->cd();
    c1->Update();
   c1->SetSelected(c1);
    c1->SaveAs("AggregatedRegions_Moriond2017.eps");
    
    cout << "\\begin{table}[htb]" << endl;
    cout << "\\centering" << endl;
    cout << "\\small" << endl;
    cout << "\\begin{tabular}{|r|r|r|r|c|c|c|c|c|c|}" << endl;
    cout << "\\hline" << endl;
    cout << " \\multirow{2}{*}{$N_\\mathrm{J}$} & \\multirow{2}{*}{$t_\\mathrm{mod}$} & $M_\\mathrm{\\ell b}$ & $E_\\mathrm{T}^\\mathrm{miss}$ & Lost  & \\multirow{2}{*}{1$\\ell$ (top)} & 1$\\ell$ (not & \\multirow{2}{*}{$Z\\rightarrow\\nu\\bar{\\nu}$} & Total & \\multirow{2}{*}{Data} \\\\" << endl;
    cout << "  &  &  [GeV] &  [GeV] &  lepton &  &  top) &  & background &  \\\\" << endl;
    cout << "\\hline" << endl;
    cout << tableline("$\\leq3$ &    $>10$ &            &    $>600$", 1,LL,tt1l,W1l,ttz,bg,Data);
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ &    $>550$", 2,LL,tt1l,W1l,ttz,bg,Data);
    cout << tableline("$\\geq4$ &    $>10$ & $\\leq175$ &    $>450$", 3,LL,tt1l,W1l,ttz,bg,Data);
    cout << tableline("$\\geq4$ & $\\leq0$ &     $>175$ &    $>450$", 4,LL,tt1l,W1l,ttz,bg,Data);
    cout << tableline("$\\geq4$ &     $>0$ &     $>175$ &    $>450$", 5,LL,tt1l,W1l,ttz,bg,Data);
    cout << "\\hline" << endl;
    cout << tableline("\\multicolumn{3}{|l|}{compressed region} &    $>450$",6,LL,tt1l,W1l,ttz,bg,Data);
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;


}
