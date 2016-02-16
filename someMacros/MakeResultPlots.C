#include "TList.h"
#include "TMath.h"
#include "TString.h"
#include "TObject.h"
#include "TFile.h"
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

void MakeResultPlots(TString inputfile){

  ifstream infile(inputfile.Data());
  if(!(infile.good() ) ) {
    cout << "file " << inputfile << " does not exist - exit" << endl;
    return;
  }
  TFile *f = new TFile(inputfile,"read");
  if(f->IsZombie()) {
    f->Close();
    delete f;
    cout << "file " << inputfile << " is zombie - exit" << endl;
    return;
  }
  f->cd();

  TH1D *tData = (TH1D*)f->Get("rpt_Data");
  TH1D *tLL   = (TH1D*)f->Get("rpt_LLest");
  TH1D *tW1l  = (TH1D*)f->Get("rpt_0best");
  TH1D *ttt1l = (TH1D*)f->Get("rpt_tt1l");
  TH1D *tttz  = (TH1D*)f->Get("rpt_znunu");
  TH1D *ts750 = (TH1D*)f->Get("rpt_T2tt_750_50" );
  TH1D *ts600 = (TH1D*)f->Get("rpt_T2tt_600_250");
  TH1D *ts500 = (TH1D*)f->Get("rpt_T2tt_500_100");
  TH1D *ts300 = (TH1D*)f->Get("rpt_T2tt_300_200");
/*
    TH1D *Data = new TH1D("Data","",9,0,9);
    TH1D *LL   = new TH1D("LL"  ,"",9,0,9);
    TH1D *W1l  = new TH1D("W1l" ,"",9,0,9);
    TH1D *tt1l = new TH1D("tt1l","",9,0,9);
    TH1D *ttz  = new TH1D("ttz" ,"",9,0,9);
    TH1D *s750 = new TH1D("s750","",9,0,9);
    TH1D *s600 = new TH1D("s600","",9,0,9);
    TH1D *s500 = new TH1D("s500","",9,0,9);
    TH1D *s300 = new TH1D("s300","",9,0,9);
  */
  //TH1D *Data = (TH1D*)tData  ->Clone("Data");
  TH1D *LL   = (TH1D*)tLL  ->Clone("LLest");
  TH1D *W1l  = (TH1D*)tW1l ->Clone("0best");
  TH1D *tt1l = (TH1D*)ttt1l->Clone("tt1l");
  TH1D *ttz  = (TH1D*)tttz ->Clone("znunu");
  TH1D *s750 = (TH1D*)ts750->Clone("T2tt_750_50" );
  TH1D *s600 = (TH1D*)ts600->Clone("T2tt_600_250");
  TH1D *s500 = (TH1D*)ts500->Clone("T2tt_500_100");
  TH1D *s300 = (TH1D*)ts300->Clone("T2tt_300_200");
  
    //Data->SetBinContent(5,14);
    TH1D *Data = new TH1D("Data","",9,0,9);
    Data->SetBinErrorOption(TH1::kPoisson);
    for(int i = 1; i<=Data->GetNbinsX(); ++i){
        cout << tData->GetBinContent(i) << endl;
        for(int n = 1; n<=tData->GetBinContent(i); ++n){
            Data->Fill(i-0.5,1);
        }
    }
/*
  for(int i = 1; i<=Data->GetNbinsX(); ++i){
    int j;
    if(i<=5) j = i+1;
    if(i>=6) j = i-5;
    Data->SetBinContent(j, tData->GetBinContent(i)); Data->SetBinError(j, tData->GetBinError(i));
    //Data->SetBinContent(j, tLL->GetBinContent(i)); Data->SetBinError(j, tLL->GetBinError(i));
    LL  ->SetBinContent(j, tLL  ->GetBinContent(i)); LL  ->SetBinError(j, tLL  ->GetBinError(i));
    W1l ->SetBinContent(j, tW1l ->GetBinContent(i)); W1l ->SetBinError(j, tW1l ->GetBinError(i));
    tt1l->SetBinContent(j, ttt1l->GetBinContent(i)); tt1l->SetBinError(j, ttt1l->GetBinError(i));
    ttz ->SetBinContent(j, tttz ->GetBinContent(i)); ttz ->SetBinError(j, tttz ->GetBinError(i));
    s750->SetBinContent(j, ts750->GetBinContent(i)); s750->SetBinError(j, ts750->GetBinError(i));
    s600->SetBinContent(j, ts600->GetBinContent(i)); s600->SetBinError(j, ts600->GetBinError(i));
    s500->SetBinContent(j, ts500->GetBinContent(i)); s500->SetBinError(j, ts500->GetBinError(i));
    s300->SetBinContent(j, ts300->GetBinContent(i)); s300->SetBinError(j, ts300->GetBinError(i));
  }
 */
  TH1D *bg   = (TH1D*)LL->Clone("rpt_bg"); bg->Sumw2();
  //bg->Add(W1l);//don't do that - I don't know if errors are somed correctly
  for(int i = 1; i<=bg->GetNbinsX(); ++i){
    bg->SetBinContent(i, LL->GetBinContent(i) + W1l->GetBinContent(i) + tt1l->GetBinContent(i) + ttz->GetBinContent(i) );
    bg->SetBinError(i, sqrt(pow(LL->GetBinError(i),2) + pow(W1l->GetBinError(i),2) + pow(tt1l->GetBinError(i),2) + pow(ttz->GetBinError(i),2) ) );
      cout << bg->GetBinContent(i) << " +/- " << bg->GetBinError(i) << endl;
  }
  
   TCanvas *c1 = new TCanvas("c1", "c1",50,50,950,650);
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
   c1->SetBottomMargin(0.15);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   gStyle->SetHatchesLineWidth(0);

   THStack *Sum = new THStack();
   Sum->SetName("Sum");
   //Sum->SetTitle(";Signal region;Events");
   Sum->SetTitle(";E_{T}^{miss} [GeV];Events");
   Sum->SetMinimum(0);
   Sum->SetMaximum(38.1);//get's me to 40
   TH1F *hSum = new TH1F("hSum","",9,0,9);
   hSum->SetMinimum(0.);
   hSum->SetMaximum(38.1);
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
   hSum->GetXaxis()->SetBinLabel(1,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");//this looks stupid but does the job
   hSum->GetXaxis()->SetBinLabel(2,"#geq#scale[0.5]{ }350");
   hSum->GetXaxis()->SetBinLabel(3,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
   hSum->GetXaxis()->SetBinLabel(4,"#geq#scale[0.5]{ }350");
   hSum->GetXaxis()->SetBinLabel(5,"250#scale[0.7]{ }#minus#scale[0.5]{ }325");
   hSum->GetXaxis()->SetBinLabel(6,"#geq#scale[0.5]{ }325");
   hSum->GetXaxis()->SetBinLabel(7,"250#scale[0.7]{ }#minus#scale[0.5]{ }350");
   hSum->GetXaxis()->SetBinLabel(8,"350#scale[0.7]{ }#minus#scale[0.5]{ }450");
   hSum->GetXaxis()->SetBinLabel(9,"#geq#scale[0.5]{ }450");
   //hSum->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hSum->GetXaxis()->SetLabelFont(42);
   hSum->GetXaxis()->SetLabelOffset(0.007);
   hSum->GetXaxis()->SetLabelSize(0.05);
   hSum->GetXaxis()->SetTitleSize(0.06);
   hSum->GetXaxis()->SetTitleOffset(1.15);
   hSum->GetXaxis()->SetTitleFont(42);
   hSum->GetYaxis()->SetTitle("Events");
   hSum->GetYaxis()->SetLabelFont(42);
   hSum->GetYaxis()->SetLabelOffset(0.007);
   hSum->GetYaxis()->SetLabelSize(0.04);
   hSum->GetYaxis()->SetTitleSize(0.06);
   hSum->GetYaxis()->SetTitleOffset(1.0);
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
    TLegend *leg = new TLegend(0.6872416,0.6688,0.925,0.8224,NULL,"brNDC");
    leg-> SetNColumns(2);
   leg->SetBorderSize(0);
    leg->SetTextSize(0.03475);
    leg->SetTextFont(42);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(2);
    leg->SetFillColor(0);
    leg->SetFillStyle(1001);
    
    TLegend *legs = new TLegend(0.6872416,0.526,0.80,0.6688,NULL,"brNDC");
    //legs-> SetNColumns(2);
    legs->SetBorderSize(0);
    legs->SetTextSize(0.0325);
    legs->SetTextFont(42);
    legs->SetLineColor(1);
    legs->SetLineStyle(1);
    legs->SetLineWidth(2);
    legs->SetFillColor(0);
    legs->SetFillStyle(1001);
 
    //orig kCyan-3
    //tried kCyan+2
   LL->SetFillColor(  kCyan+2);
   LL->SetMarkerColor(kCyan+2);
   LL->SetLineColor(  kCyan+2);
   LL->SetMarkerStyle(1);
   LL->SetLineStyle(0);
   Sum->Add(LL,"");
    leg->AddEntry(LL, "Lost Lepton", "f");

    //orig: kRed-7
    //tried kRed-6
   tt1l->SetFillColor(  kRed-6);
   tt1l->SetMarkerColor(kRed-6);
   tt1l->SetLineColor(  kRed-6);
   tt1l->SetMarkerStyle(1);
   tt1l->SetLineStyle(0);
   Sum->Add(tt1l,"");
    leg->AddEntry(tt1l, "t#bar{t}#rightarrow1#font[12]{l}", "f");
   // leg->AddEntry(tt1l, "t{t}\\to1\\ell", "f");

    //orig: kOrange-2
    //tried kOrange-3
   W1l->SetFillColor(  kOrange-3);
   W1l->SetMarkerColor(kOrange-3);
   W1l->SetLineColor(  kOrange-3);
   W1l->SetMarkerStyle(1);
   W1l->SetLineStyle(0);
   Sum->Add(W1l,"");
    leg->AddEntry(W1l, "1#font[12]{l} (not from t)", "f");
   // leg->AddEntry(W1l, "\\text{1}\\ell\\text{ (not from t)}", "f");

    //orig: kMagenta-5
    //tried kMagenta-2
   ttz->SetFillColor(  kMagenta-2);
   ttz->SetMarkerColor(kMagenta-2);
   ttz->SetLineColor(  kMagenta-2);
   ttz->SetMarkerStyle(1);
   ttz->SetLineStyle(0);
   Sum->Add(ttz,"");
    leg->AddEntry(ttz, "Z#rightarrow#nu#bar{#nu}", "f");
   // leg->AddEntry(ttz, "\\text{Z}\\to\\nu\\nu", "f");


   Sum->Draw("hist");

   Data->SetLineStyle(0);
   Data->SetLineWidth(2);
   Data->SetLineColor(1);
   Data->SetMarkerStyle(20);
    //Data->Draw("sameE");
    Data->Draw("sameE0X0");
    leg->AddEntry(Data, "Data", "ep");


   bg->SetFillColor(1);
   bg->SetFillStyle(3013);
   // bg->SetFillStyle(3144);
   // bg->SetFillStyle(3244);
   bg->SetLineColor(1);
   bg->SetLineStyle(0);
   bg->SetMarkerStyle(0);
   bg->Draw("sameE2");
    
    /*
    TLegend *legs = new TLegend(0.6992416,0.4811189,0.898906,0.7503497,NULL,"brNDC");
    legs->SetBorderSize(0);
    legs->SetTextSize(0.04);
    legs->SetTextFont(42);
    legs->SetLineColor(1);
    legs->SetLineStyle(1);
    legs->SetLineWidth(2);
    legs->SetFillColor(0);
    legs->SetFillStyle(1001);
    */
    
    s750->SetLineStyle(4);
    s750->SetLineWidth(4);
    //s750->SetLineColor(  kViolet+9);//orig
    //s750->SetMarkerColor(kViolet+9);//orig
    s750->SetLineColor(  kMagenta-4);
    s750->SetMarkerColor(kMagenta-4);
    s750->Draw("samehist");
    //legs->AddEntry(s750, "M_{#tilde{t}} = 750 GeV, M_{#tilde{#chi}_{1}^{0}} = 50 GeV", "l");
    legs->AddEntry(s750, " #tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (750,50)", "l");

    s600->SetLineStyle(5);
    s600->SetLineWidth(4);
    //s600->SetLineColor(  kRed+1);//orig
    //s600->SetMarkerColor(kRed+1);//orig
    s600->SetLineColor(  kSpring-2);
    s600->SetMarkerColor(kSpring-2);
    s600->Draw("samehist");
    legs->AddEntry(s600, " #tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (600,250)", "l");
    /*
    s500->SetLineStyle(4);
    s500->SetLineWidth(4);
    s500->SetLineColor(  kYellow-2);
    s500->SetMarkerColor(kYellow-2);
    s500->Draw("samehist");
    legs->AddEntry(s500, " #tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (500,100)", "l");
    */
    s300->SetLineStyle(8);
    s300->SetLineWidth(4);
    //s300->SetLineColor(  kYellow-1);//orig
    //s300->SetMarkerColor(kYellow-1);//orig
    s300->SetLineColor(  kAzure+6);
    s300->SetMarkerColor(kAzure+6);
    s300->Draw("samehist");
    legs->AddEntry(s300, " #tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (300,200)", "l");
    
    leg->Draw();
    legs->Draw();
    
    //regions
    TLatex *tcmp = new TLatex(0.174,0.891,"#splitline{Compressed}{      #tilde{#chi}_{1}^{#pm} - #tilde{#chi}_{1}^{0}}");
    tcmp->SetNDC();
    tcmp->SetTextAlign(13);
    tcmp->SetTextFont(42);
    tcmp->SetTextSize(0.042);
    tcmp->SetLineWidth(2);
    tcmp->Draw();
    TLine *l1 = new TLine(2,0,2,40);
    l1->SetLineStyle(2);
    l1->SetLineWidth(2);
    l1->Draw();
    TLatex *tbDM = new TLatex(0.375,0.891,"#splitline{Boosted}{High #DeltaM}");
    tbDM->SetNDC();
    tbDM->SetTextAlign(13);
    tbDM->SetTextFont(42);
    tbDM->SetTextSize(0.042);
    tbDM->SetLineWidth(2);
    tbDM->Draw();
    TLine *l2 = new TLine(4,0,4,40);
    l2->SetLineStyle(2);
    l2->SetLineWidth(2);
    l2->Draw();
    TLatex *tlDM = new TLatex(0.56,0.891,"Low #DeltaM");
    tlDM->SetNDC();
    tlDM->SetTextAlign(13);
    tlDM->SetTextFont(42);
    tlDM->SetTextSize(0.042);
    tlDM->SetLineWidth(2);
    tlDM->Draw();
    TLine *l3 = new TLine(6,0,6,40);
    l3->SetLineStyle(2);
    l3->SetLineWidth(2);
    l3->Draw();
    TLatex *thDM = new TLatex(0.768,0.891,"High #DeltaM");
    thDM->SetNDC();
    thDM->SetTextAlign(13);
    thDM->SetTextFont(42);
    thDM->SetTextSize(0.042);
    thDM->SetLineWidth(2);
    thDM->Draw();
    
    //final CMS style
    TLatex *tLumi = new TLatex(0.95,0.944,"2.3 fb^{-1} (13 TeV)");
    tLumi->SetNDC();
    tLumi->SetTextAlign(31);
    tLumi->SetTextFont(42);
    tLumi->SetTextSize(0.042);
    tLumi->SetLineWidth(2);
    tLumi->Draw();
    TLatex *tCMS = new TLatex(0.152,0.944,"CMS");
    tCMS->SetNDC();
    tCMS->SetTextAlign(11);
    tCMS->SetTextFont(61);
    tCMS->SetTextSize(0.0525);
    tCMS->SetLineWidth(2);
    tCMS->Draw();
    TLatex *tPrel = new TLatex(0.227,0.944,"Preliminary");
    tPrel->SetNDC();
    tPrel->SetTextAlign(11);
    tPrel->SetTextFont(52);
    tPrel->SetTextSize(0.042);
    tPrel->SetLineWidth(2);
    tPrel->Draw();
    
   c1->Modified();
   c1->cd();
    c1->Update();
   c1->SetSelected(c1);

}
