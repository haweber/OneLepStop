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

void MakeResultPlots2017_MoriondwSignal(){
    
    TFile *f = new TFile("ResultRootFileMoriond17.root");
  f->cd();
  TH1D *tData = (TH1D*)f->Get("rpt_Data");
  TH1D *tLL   = (TH1D*)f->Get("rpt_LLest");
  TH1D *tW1l  = (TH1D*)f->Get("rpt_0best");
  TH1D *ttt1l = (TH1D*)f->Get("rpt_tt1l");
    TH1D *tttz  = (TH1D*)f->Get("rpt_znunu");
    TH1D *tbg  = (TH1D*)f->Get("rpt_bg");

  //TH1D *Data = (TH1D*)tData  ->Clone("Data");
  TH1D *LL   = (TH1D*)tLL  ->Clone("LLest");
  TH1D *W1l  = (TH1D*)tW1l ->Clone("0best");
  TH1D *tt1l = (TH1D*)ttt1l->Clone("tt1l");
    TH1D *ttz  = (TH1D*)tttz ->Clone("znunu");
    TH1D *bg  = (TH1D*)tbg ->Clone("bg");
    
    TH1D *Data = new TH1D("Data","",27,0,27);
    Data->SetBinErrorOption(TH1::kPoisson);
    for(int i = 1; i<=Data->GetNbinsX(); ++i){
        cout << tData->GetBinContent(i) << endl;
        for(int n = 1; n<=tData->GetBinContent(i); ++n){
            Data->Fill(i-0.5,1);
        }
    }
    TFile *fsig = new TFile("../Interpretation/SignalDistribution_forresult.root","READ");
    TH1D *ttt900  = (TH1D*)fsig->Get("T2tt_900_300_gencontcorr");
    TH1D *ttb600  = (TH1D*)fsig->Get("T2tb_600_300_gencontcorr");
    TH1D *tbW900  = (TH1D*)fsig->Get("T2bW_900_50_gencontcorr");
    TH1D *tt900 = (TH1D*)ttt900->Clone("T2tt_900_300");
    TH1D *tb600 = (TH1D*)ttb600->Clone("T2tb_600_300");
    TH1D *bW900 = (TH1D*)tbW900->Clone("T2tt_900_50");

  
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
    TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0.,0.21,0.775,1);
    plotpad->Draw();
    plotpad->cd();
    plotpad->SetFillColor(0);
    plotpad->SetBorderMode(0);
    plotpad->SetBorderSize(2);
    plotpad->SetLogy();
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
   Sum->SetMinimum(0.4);
   Sum->SetMaximum(20000);//get's me to 40
   TH1F *hSum = new TH1F("hSum","",27,0,27);
   hSum->SetMinimum(0.4);
   hSum->SetMaximum(20000);
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
    hSum->GetXaxis()->SetBinLabel( 1,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");//this looks stupid but does the job
    hSum->GetXaxis()->SetBinLabel( 2,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel( 3,"450#scale[0.7]{ }#minus#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel( 4,"#geq#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel( 5,"250#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel( 6,"450#scale[0.7]{ }#minus#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel( 7,"#geq#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel( 8,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
    hSum->GetXaxis()->SetBinLabel( 9,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(10,"450#scale[0.7]{ }#minus#scale[0.5]{ }550");
    hSum->GetXaxis()->SetBinLabel(11,"550#scale[0.7]{ }#minus#scale[0.5]{ }650");
    hSum->GetXaxis()->SetBinLabel(12,"#geq#scale[0.5]{ }650");
    hSum->GetXaxis()->SetBinLabel(13,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
    hSum->GetXaxis()->SetBinLabel(14,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(15,"450#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(16,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(17,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
    hSum->GetXaxis()->SetBinLabel(18,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(19,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(20,"250#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(21,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(22,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
    hSum->GetXaxis()->SetBinLabel(23,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(24,"450#scale[0.7]{ }#minus#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel(25,"#geq#scale[0.5]{ }600");
    hSum->GetXaxis()->SetBinLabel(26,"250#scale[0.7]{ }#minus#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBinLabel(27,"#geq#scale[0.5]{ }450");
    hSum->GetXaxis()->SetBit(TAxis::kLabelsVert);
    //hSum->GetXaxis()->SetBit(TAxis::kLabelsDown);
   hSum->GetXaxis()->SetLabelFont(42);
    //hSum->GetXaxis()->SetLabelOffset(0.007);
    hSum->GetXaxis()->SetLabelOffset(0.004);
    //hSum->GetXaxis()->SetLabelSize(0.05);
    hSum->GetXaxis()->SetLabelSize(0.055);
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
    leg->AddEntry(W1l, "1   (not from t)", "f");
    leg->AddEntry(ttz, "Z#rightarrow#nu#bar{#nu}", "f");
    leg->AddEntry(bg, "Total uncertainty", "f");
    leg->AddEntry(tt1l, "t#bar{t}#rightarrow1", "f");
    leg->AddEntry(Data, "Data", "ep");

    legd->AddEntry(tt900, " #tilde{t}#rightarrow t#tilde{#chi}_{1} (900,300)", "l");
    legd->AddEntry(bW900, " #tilde{t}#rightarrow b#tilde{#chi}_{1} (900,50)", "l");
    legd->AddEntry(tb600, " #tilde{t}#rightarrow t#tilde{#chi}_{1} / #tilde{t}#rightarrow b#tilde{#chi}_{1} (600,300)", "l");
    
    leg->Draw();
    //legs->Draw();
    legd->Draw();


    
    TLine *l1 = new TLine( 4,0, 4,1100);
    l1->SetLineStyle(2);
    l1->SetLineWidth(2);
    l1->Draw();
    TLine *l2 = new TLine( 7,0, 7,1100);
    l2->SetLineStyle(2);
    l2->SetLineWidth(2);
    l2->Draw();
    TLine *l3 = new TLine(12,0,12,1100);
    l3->SetLineStyle(2);
    l3->SetLineWidth(2);
    l3->Draw();
    TLine *l4 = new TLine(16,0,16,1100);
    l4->SetLineStyle(2);
    l4->SetLineWidth(2);
    l4->Draw();
    TLine *l5 = new TLine(19,0,19,1100);
    l5->SetLineStyle(2);
    l5->SetLineWidth(2);
    l5->Draw();
    TLine *l6 = new TLine(21,0,21,1100);
    l6->SetLineStyle(2);
    l6->SetLineWidth(2);
    l6->Draw();
    TLine *l7 = new TLine(25,0,25,1100);
    l7->SetLineStyle(2);
    l7->SetLineWidth(2);
    l7->Draw();
    
    TLatex *tA = new TLatex(0.155,0.7,"A");
    tA->SetNDC();tA->SetTextAlign(13);tA->SetTextFont(42);tA->SetTextSize(0.045);tA->SetLineWidth(2);
    tA->Draw();
    TLatex *tB = new TLatex(0.2625,0.7,"B");
    tB->SetNDC();tB->SetTextAlign(13);tB->SetTextFont(42);tB->SetTextSize(0.045);tB->SetLineWidth(2);
    tB->Draw();
    TLatex *tC = new TLatex(0.3925,0.7,"C");
    tC->SetNDC();tC->SetTextAlign(13);tC->SetTextFont(42);tC->SetTextSize(0.045);tC->SetLineWidth(2);
    tC->Draw();
    TLatex *tD = new TLatex(0.53,0.7,"D");
    tD->SetNDC();tD->SetTextAlign(13);tD->SetTextFont(42);tD->SetTextSize(0.045);tD->SetLineWidth(2);
    tD->Draw();
    TLatex *tE = new TLatex(0.64,0.7,"E");
    tE->SetNDC();tE->SetTextAlign(13);tE->SetTextFont(42);tE->SetTextSize(0.045);tE->SetLineWidth(2);
    tE->Draw();
    TLatex *tF = new TLatex(0.72,0.7,"F");
    tF->SetNDC();tF->SetTextAlign(13);tF->SetTextFont(42);tF->SetTextSize(0.045);tF->SetLineWidth(2);
    tF->Draw();
    TLatex *tG = new TLatex(0.8125,0.7,"G");
    tG->SetNDC();tG->SetTextAlign(13);tG->SetTextFont(42);tG->SetTextSize(0.045);tG->SetLineWidth(2);
    tG->Draw();
    TLatex *tH = new TLatex(0.905,0.7,"H");
    tH->SetNDC();tH->SetTextAlign(13);tH->SetTextFont(42);tH->SetTextSize(0.045);tH->SetLineWidth(2);
    tH->Draw();
    
    TMathText *mt = new TMathText();
    mt->SetNDC();
    mt->SetTextAlign(23);
    mt->SetTextSize(0.042);
    mt->SetTextColor(1);
    mt->DrawMathText(0.246,0.787,"\\ell");
    mt->DrawMathText(0.404,0.891,"\\ell");
    TLatex *tlx = new TLatex();
    tlx->SetTextFont(42);
    tlx->SetNDC();
    tlx->SetTextAlign(23);
    tlx->SetTextSize(0.026);
    tlx->SetTextColor(1);
    tlx->DrawLatex(0.804,0.787,"\\pm");
    tlx->DrawLatex(0.702,0.785,"0");
    tlx->DrawLatex(0.708,0.838,"\\pm");
    tlx->DrawLatex(0.702,0.888,"0");

    //final CMS style
    //TLatex *tLumi = new TLatex(0.95,0.944,"18.1 fb^{-1} (13 TeV)");
    //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
    TLatex *tLumi = new TLatex(0.95,0.944,"36.8 fb^{-1} (13 TeV)");
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
    
    c1->cd();
    TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.01863354,0.775,0.2069441);
    ratiopad->Draw();
    ratiopad->cd();
    ratiopad->SetLogy();
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
    hMCrat->SetMinimum(0.25);
    hMCrat->SetMaximum(4.);
    ratiopad->cd();
    hMCrat->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
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
    hMCrat->GetYaxis()->SetLabelOffset(-0.002);
    hMCrat->GetYaxis()->SetTitleSize(0.18);
    hMCrat->GetYaxis()->SetTitleOffset(0.26);
    hMCrat->GetYaxis()->SetTitleFont(42);
    hMCrat->GetZaxis()->SetLabelFont(42);
    hMCrat->GetZaxis()->SetLabelSize(0.035);
    hMCrat->GetZaxis()->SetTitleSize(0.035);
    hMCrat->GetZaxis()->SetTitleFont(42);
    hMCrat->Draw("E2");
    TLine *rline = new TLine(0,1,27,1);
    rline->SetLineWidth(2);
    rline->SetLineStyle(7);
    rline->Draw();
    hDatarat->Draw("sameE0X0");
    
    TLatex *texlu = new TLatex(-0.875,2.27064,"3");
    texlu->SetTextFont(42);
    texlu->SetTextSize(0.17);
    texlu->SetLineWidth(2);
    texlu->Draw();
    TLatex *texld = new TLatex(-1.7,0.2336995,"0.3");
    texld->SetTextFont(42);
    texld->SetTextSize(0.17);
    texld->SetLineWidth(2);
    texld->Draw();
    
    c1->cd();
    TPad *textpad = new TPad("textpad", "Pad containing the text",0.75,0.01863354,0.999,0.999);
    textpad->Draw();
    textpad->cd();
    textpad->SetLogy();
    //textpad->Range(71.42856,0.5346154,785.7143,1.303846);
    textpad->SetFillColor(0);
    textpad->SetBorderMode(0);
    textpad->SetBorderSize(2);
    textpad->SetTickx(1);
    textpad->SetTicky(1);
    textpad->SetLeftMargin(0.15);
    textpad->SetRightMargin(0.05);
    textpad->SetTopMargin(0.07);
    textpad->SetBottomMargin(0.28);
    textpad->SetFrameFillStyle(0);
    textpad->SetFrameBorderMode(0);
    textpad->SetFrameFillStyle(0);
    textpad->SetFrameBorderMode(0);
    /*
    TLatex *txA = new TLatex(0.01,0.945,"#splitline{A: N_{J} #leq 3, t_{mod} > 10,}{     M_{lb} #leq 175 GeV}");
    txA->SetNDC();txA->SetTextAlign(13);txA->SetTextFont(42);txA->SetTextSize(0.1);txA->SetLineWidth(2);
    txA->Draw();
    TLatex *txB = new TLatex(0.01,0.85,"#splitline{B: N_{J} #leq 3, t_{mod} > 10,}{     M_{lb} > 175 GeV}");
    txB->SetNDC();txB->SetTextAlign(13);txB->SetTextFont(42);txB->SetTextSize(0.1);txB->SetLineWidth(2);
    txB->Draw();
    TLatex *txC = new TLatex(0.01,0.755,"#splitline{C: N_{J} #geq 4, t_{mod} #leq 0,}{     M_{lb} #leq 175 GeV}");
    txC->SetNDC();txC->SetTextAlign(13);txC->SetTextFont(42);txC->SetTextSize(0.1);txC->SetLineWidth(2);
    txC->Draw();
    TLatex *txD = new TLatex(0.01,0.66,"#splitline{D: N_{J} #geq 4, t_{mod} #leq 0,}{     M_{lb} > 175 GeV}");
    txD->SetNDC();txD->SetTextAlign(13);txD->SetTextFont(42);txD->SetTextSize(0.1);txD->SetLineWidth(2);
    txD->Draw();
    TLatex *txE = new TLatex(0.01,0.565,"#splitline{E: N_{J} #geq 4, 0 < t_{mod} #leq 10,}{     M_{lb} #leq 175 GeV}");
    txE->SetNDC();txE->SetTextAlign(13);txE->SetTextFont(42);txE->SetTextSize(0.1);txE->SetLineWidth(2);
    txE->Draw();
    TLatex *txF = new TLatex(0.01,0.47,"#splitline{F: N_{J} #geq 4, 0 < t_{mod} #leq 10,}{     M_{lb} > 175 GeV}");
    txF->SetNDC();txF->SetTextAlign(13);txF->SetTextFont(42);txF->SetTextSize(0.1);txF->SetLineWidth(2);
    txF->Draw();
    TLatex *txG = new TLatex(0.01,0.375,"#splitline{G: N_{J} #geq 4, t_{mod} > 10,}{     M_{lb} #leq 175 GeV}");
    txG->SetNDC();txG->SetTextAlign(13);txG->SetTextFont(42);txG->SetTextSize(0.1);txG->SetLineWidth(2);
    txG->Draw();
    TLatex *txH = new TLatex(0.01,0.28,"#splitline{H: N_{J} #geq 4, t_{mod} > 10,}{     M_{lb} > 175 GeV}");
    txH->SetNDC();txH->SetTextAlign(13);txH->SetTextFont(42);txH->SetTextSize(0.1);txH->SetLineWidth(2);
    txH->Draw();
    */
    
    TLatex *txA = new TLatex(0.01,0.945,"#splitline{A: N_{J} #leq 3, t_{mod} > 10,}{     M_{  b} #leq 175 GeV}");
    txA->SetNDC();txA->SetTextAlign(13);txA->SetTextFont(42);txA->SetTextSize(0.1);txA->SetLineWidth(2);
    txA->Draw();
    TLatex *txB = new TLatex(0.01,0.85,"#splitline{B: N_{J} #leq 3, t_{mod} > 10,}{     M_{  b} > 175 GeV}");
    txB->SetNDC();txB->SetTextAlign(13);txB->SetTextFont(42);txB->SetTextSize(0.1);txB->SetLineWidth(2);
    txB->Draw();
    TLatex *txC = new TLatex(0.01,0.755,"#splitline{C: N_{J} #geq 4, t_{mod} #leq 0,}{     M_{  b} #leq 175 GeV}");
    txC->SetNDC();txC->SetTextAlign(13);txC->SetTextFont(42);txC->SetTextSize(0.1);txC->SetLineWidth(2);
    txC->Draw();
    TLatex *txD = new TLatex(0.01,0.66,"#splitline{D: N_{J} #geq 4, t_{mod} #leq 0,}{     M_{  b} > 175 GeV}");
    txD->SetNDC();txD->SetTextAlign(13);txD->SetTextFont(42);txD->SetTextSize(0.1);txD->SetLineWidth(2);
    txD->Draw();
    TLatex *txE = new TLatex(0.01,0.565,"#splitline{E: N_{J} #geq 4, 0 < t_{mod} #leq 10,}{     M_{  b} #leq 175 GeV}");
    txE->SetNDC();txE->SetTextAlign(13);txE->SetTextFont(42);txE->SetTextSize(0.1);txE->SetLineWidth(2);
    txE->Draw();
    TLatex *txF = new TLatex(0.01,0.47,"#splitline{F: N_{J} #geq 4, 0 < t_{mod} #leq 10,}{     M_{  b} > 175 GeV}");
    txF->SetNDC();txF->SetTextAlign(13);txF->SetTextFont(42);txF->SetTextSize(0.1);txF->SetLineWidth(2);
    txF->Draw();
    TLatex *txG = new TLatex(0.01,0.375,"#splitline{G: N_{J} #geq 4, t_{mod} > 10,}{     M_{  b} #leq 175 GeV}");
    txG->SetNDC();txG->SetTextAlign(13);txG->SetTextFont(42);txG->SetTextSize(0.1);txG->SetLineWidth(2);
    txG->Draw();
    TLatex *txH = new TLatex(0.01,0.28,"#splitline{H: N_{J} #geq 4, t_{mod} > 10,}{     M_{  b} > 175 GeV}");
    txH->SetNDC();txH->SetTextAlign(13);txH->SetTextFont(42);txH->SetTextSize(0.1);txH->SetLineWidth(2);
    txH->Draw();
    TMathText *tmt = new TMathText();
    tmt->SetNDC();
    tmt->SetTextAlign(23);
    tmt->SetTextSize(0.07);
    tmt->SetTextColor(1);
    tmt->DrawMathText(0.2225,0.879,"\\ell");
    tmt->DrawMathText(0.2225,0.785,"\\ell");
    tmt->DrawMathText(0.2225,0.688,"\\ell");
    tmt->DrawMathText(0.2225,0.594,"\\ell");
    tmt->DrawMathText(0.2225,0.499,"\\ell");
    tmt->DrawMathText(0.2225,0.405,"\\ell");
    tmt->DrawMathText(0.2225,0.307,"\\ell");
    tmt->DrawMathText(0.2225,0.214,"\\ell");
    
   c1->Modified();
   c1->cd();
    c1->Update();
   c1->SetSelected(c1);
    c1->SaveAs("ResultPlot_Moriond2017.eps");
    
    /*
    cout << "\\begin{table}[htb]" << endl
    << "\\centering" << endl
    << "\\caption{\\label{resulttable}Comparison between data of 12.9\\fbinv collected by the CMS experiment and background estimations. Various signal hypotheses are overlaid.}" << endl
    << "\\begin{tabular}{|r|r@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}l|r@{\\,$\\pm$\\,}l|r|}" << endl
    << "\\hline" << endl
    << "\\multirow{2}{*}{\\MET [GeV]} &  \\multicolumn{2}{c|}{\\multirow{2}{*}{Lost Lepton}} & \\multicolumn{2}{c|}{$1\\ell$ (not}  &  \\multicolumn{2}{c|}{\\multirow{2}{*}{$\\ttbar\\to1\\ell$}} &  \\multicolumn{2}{c|}{\\multirow{2}{*}{$\\cPZ\\to\\cPgn\\cPagn$}} & \\multicolumn{2}{c|}{Total} & \\multirow{2}{*}{Data} \\\\" << endl
    << " & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{from top)} & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{background} &  \\\\" << endl
    << "\\hline" << endl
    << " & \\multicolumn{11}{l|}{2 jets, $t_\\mathrm{mod} > 6.4$} \\\\" << endl
    << "\\hline" << endl;
    cout << "$250-350$ & " << fixed << setprecision(2) <<  LL->GetBinContent(1) << " & " << LL->GetBinError(1) << " & " << W1l->GetBinContent(1) << " & " << W1l->GetBinError(1) << " & " << tt1l->GetBinContent(1) << " & " << tt1l->GetBinError(1) << " & " <<ttz->GetBinContent(1) << " & " << ttz->GetBinError(1) << " & " << bg->GetBinContent(1) << " & " << bg->GetBinError(1) << " & " << (int)Data->GetBinContent(1) << " \\\\" << endl;
    cout << "$350-450$ & " << fixed << setprecision(2) <<  LL->GetBinContent(2) << " & " << LL->GetBinError(2) << " & " << W1l->GetBinContent(2) << " & " << W1l->GetBinError(2) << " & " << tt1l->GetBinContent(2) << " & " << tt1l->GetBinError(2) << " & " <<ttz->GetBinContent(2) << " & " << ttz->GetBinError(2) << " & " << bg->GetBinContent(2) << " & " << bg->GetBinError(2) << " & " << (int)Data->GetBinContent(2) << " \\\\" << endl;
    cout << "$>450$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(3) << " & " << LL->GetBinError(3) << " & " << W1l->GetBinContent(3) << " & " << W1l->GetBinError(3) << " & " << tt1l->GetBinContent(3) << " & " << tt1l->GetBinError(3) << " & " <<ttz->GetBinContent(3) << " & " << ttz->GetBinError(3) << " & " << bg->GetBinContent(3) << " & " << bg->GetBinError(3) << " & " << (int)Data->GetBinContent(3) << " \\\\" << endl;
    cout << "\\hline" << endl;
    cout << " & \\multicolumn{11}{l|}{3 jets, $M_\\mathrm{T2}^\\mathrm{W} > 200\\GeV$} \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "$250-350$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(4) << " & " << LL->GetBinError(4) << " & " << W1l->GetBinContent(4) << " & " << W1l->GetBinError(4) << " & " << tt1l->GetBinContent(4) << " & " << tt1l->GetBinError(4) << " & " <<ttz->GetBinContent(4) << " & " << ttz->GetBinError(4) << " & " << bg->GetBinContent(4) << " & " << bg->GetBinError(4) << " & " << (int)Data->GetBinContent(4) << " \\\\" << endl;
    cout << "$350-450$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(5) << " & " << LL->GetBinError(5) << " & " << W1l->GetBinContent(5) << " & " << W1l->GetBinError(5) << " & " << tt1l->GetBinContent(5) << " & " << tt1l->GetBinError(5) << " & " <<ttz->GetBinContent(5) << " & " << ttz->GetBinError(5) << " & " << bg->GetBinContent(5) << " & " << bg->GetBinError(5) << " & " << (int)Data->GetBinContent(5) << " \\\\" << endl;
    cout << "$450-550$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(6) << " & " << LL->GetBinError(6) << " & " << W1l->GetBinContent(6) << " & " << W1l->GetBinError(6) << " & " << tt1l->GetBinContent(6) << " & " << tt1l->GetBinError(6) << " & " <<ttz->GetBinContent(6) << " & " << ttz->GetBinError(6) << " & " << bg->GetBinContent(6) << " & " << bg->GetBinError(6) << " & " << (int)Data->GetBinContent(6) << " \\\\" << endl;
    cout << "$>550$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(7) << " & " << LL->GetBinError(7) << " & " << W1l->GetBinContent(7) << " & " << W1l->GetBinError(7) << " & " << tt1l->GetBinContent(7) << " & " << tt1l->GetBinError(7) << " & " <<ttz->GetBinContent(7) << " & " << ttz->GetBinError(7) << " & " << bg->GetBinContent(7) << " & " << bg->GetBinError(7) << " & " << (int)Data->GetBinContent(7) << " \\\\" << endl;
    cout << "\\hline" << endl;
    cout << " & \\multicolumn{11}{l|}{$\\geq4$ jets, $M_\\mathrm{T2}^\\mathrm{W} \\leq 200\\GeV$} \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "$250-350$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(8) << " & " << LL->GetBinError(8) << " & " << W1l->GetBinContent(8) << " & " << W1l->GetBinError(8) << " & " << tt1l->GetBinContent(8) << " & " << tt1l->GetBinError(8) << " & " <<ttz->GetBinContent(8) << " & " << ttz->GetBinError(8) << " & " << bg->GetBinContent(8) << " & " << bg->GetBinError(8) << " & " << (int)Data->GetBinContent(8) << " \\\\" << endl;
    cout << "$350-450$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(9) << " & " << LL->GetBinError(9) << " & " << W1l->GetBinContent(9) << " & " << W1l->GetBinError(9) << " & " << tt1l->GetBinContent(9) << " & " << tt1l->GetBinError(9) << " & " <<ttz->GetBinContent(9) << " & " << ttz->GetBinError(9) << " & " << bg->GetBinContent(9) << " & " << bg->GetBinError(9) << " & " << (int)Data->GetBinContent(9) << " \\\\" << endl;
    cout << "$>450$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(10) << " & " << LL->GetBinError(10) << " & " << W1l->GetBinContent(10) << " & " << W1l->GetBinError(10) << " & " << tt1l->GetBinContent(10) << " & " << tt1l->GetBinError(10) << " & " <<ttz->GetBinContent(10) << " & " << ttz->GetBinError(10) << " & " << bg->GetBinContent(10) << " & " << bg->GetBinError(10) << " & " << (int)Data->GetBinContent(10) << " \\\\" << endl;
    cout << "\\hline" << endl;
    cout << " & \\multicolumn{11}{l|}{$\\geq4$ jets, $M_\\mathrm{T2}^\\mathrm{W} > 200\\GeV$} \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "$250-350$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(11) << " & " << LL->GetBinError(11) << " & " << W1l->GetBinContent(11) << " & " << W1l->GetBinError(11) << " & " << tt1l->GetBinContent(11) << " & " << tt1l->GetBinError(11) << " & " <<ttz->GetBinContent(11) << " & " << ttz->GetBinError(11) << " & " << bg->GetBinContent(11) << " & " << bg->GetBinError(11) << " & " << (int)Data->GetBinContent(11) << " \\\\" << endl;
    cout << "$350-450$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(12) << " & " << LL->GetBinError(12) << " & " << W1l->GetBinContent(12) << " & " << W1l->GetBinError(12) << " & " << tt1l->GetBinContent(12) << " & " << tt1l->GetBinError(12) << " & " <<ttz->GetBinContent(12) << " & " << ttz->GetBinError(12) << " & " << bg->GetBinContent(12) << " & " << bg->GetBinError(12) << " & " << (int)Data->GetBinContent(12) << " \\\\" << endl;
    cout << "$450-550$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(13) << " & " << LL->GetBinError(13) << " & " << W1l->GetBinContent(13) << " & " << W1l->GetBinError(13) << " & " << tt1l->GetBinContent(13) << " & " << tt1l->GetBinError(13) << " & " <<ttz->GetBinContent(13) << " & " << ttz->GetBinError(13) << " & " << bg->GetBinContent(13) << " & " << bg->GetBinError(13) << " & " << (int)Data->GetBinContent(13) << " \\\\" << endl;
    cout << "$550-650$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(14) << " & " << LL->GetBinError(14) << " & " << W1l->GetBinContent(14) << " & " << W1l->GetBinError(14) << " & " << tt1l->GetBinContent(14) << " & " << tt1l->GetBinError(14) << " & " <<ttz->GetBinContent(14) << " & " << ttz->GetBinError(14) << " & " << bg->GetBinContent(14) << " & " << bg->GetBinError(14) << " & " << (int)Data->GetBinContent(14) << " \\\\" << endl;
    cout << "$>650$ & " << fixed << setprecision(2)  <<  LL->GetBinContent(15) << " & " << LL->GetBinError(15) << " & " << W1l->GetBinContent(15) << " & " << W1l->GetBinError(15) << " & " << tt1l->GetBinContent(15) << " & " << tt1l->GetBinError(15) << " & " <<ttz->GetBinContent(15) << " & " << ttz->GetBinError(15) << " & " << bg->GetBinContent(15) << " & " << bg->GetBinError(15) << " & " << (int)Data->GetBinContent(15) << " \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;
    */

}
