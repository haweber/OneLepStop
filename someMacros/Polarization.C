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

bool killlowdiag = true;

void Polarization(){

    TGraph *gObs;
    TGraph *gExp;
    TGraph *gObsL;
    TGraph *gExpL;
    TGraph *gObsR;
    TGraph *gExpR;
    
    TFile *fc = TFile::Open("Limits2DHistograms_T2tt_postfit.root");
    TFile *fl = TFile::Open("Limits2DHistograms_T2tt_lefthanded_postfit.root");
    TFile *fr = TFile::Open("Limits2DHistograms_T2tt_righthanded_postfit.root");
    
    TGraph *g;
    fc->cd();
    g = (TGraph*)fc->Get("gObs");
    gObs = (TGraph*)g->Clone("Obs");
    g = (TGraph*)fc->Get("gExp");
    gExp = (TGraph*)g->Clone("Exp");
    fl->cd();
    g = (TGraph*)fl->Get("gObs_2");
    gObsL = (TGraph*)g->Clone("ObsL");
    g = (TGraph*)fl->Get("gExp_2");
    gExpL = (TGraph*)g->Clone("ExpL");
    fr->cd();
    g = (TGraph*)fr->Get("gObs");
    gObsR = (TGraph*)g->Clone("ObsR");
    g = (TGraph*)fr->Get("gExp");
    gExpR = (TGraph*)g->Clone("ExpR");
    
    gObs->SetLineWidth(4);
    gExp->SetLineWidth(4);
    gObsL->SetLineWidth(2);
    gExpL->SetLineWidth(2);
    gObsR->SetLineWidth(2);
    gExpR->SetLineWidth(2);
    gObs->SetLineStyle(1);
    gExp->SetLineStyle(7);
    gObsL->SetLineStyle(1);
    gExpL->SetLineStyle(7);
    gObsR->SetLineStyle(1);
    gExpR->SetLineStyle(7);
    gObs->SetLineColor(kBlack);
    gExp->SetLineColor(kBlack);
    gObsL->SetLineColor(kBlue);
    gExpL->SetLineColor(kBlue);
    gObsR->SetLineColor(kRed);
    gExpR->SetLineColor(kRed);
    if(killlowdiag){
    for( int i = gObs->GetN()-1; i>=0;--i){
        double x,y;
        gObs->GetPoint(i,x,y);
        if(x-y<172.5) gObs->RemovePoint(i);
    }
    for( int i = gExp->GetN()-1; i>=0;--i){
        double x,y;
        gExp->GetPoint(i,x,y);
        if(x-y<172.5) gExp->RemovePoint(i);
    }
    }
    for( int i = gObsL->GetN()-1; i>=0;--i){
        double x,y;
        gObsL->GetPoint(i,x,y);
        if(x-y<172.5) gObsL->RemovePoint(i);
    }
    for( int i = gObsR->GetN()-1; i>=0;--i){
        double x,y;
        gObsR->GetPoint(i,x,y);
        if(x-y<172.5) gObsR->RemovePoint(i);
    }
    for( int i = gExpL->GetN()-1; i>=0;--i){
        double x,y;
        gExpL->GetPoint(i,x,y);
        if(x-y<172.5) gExpL->RemovePoint(i);
    }
    for( int i = gExpR->GetN()-1; i>=0;--i){
        double x,y;
        gExpR->GetPoint(i,x,y);
        if(x-y<172.5) gExpR->RemovePoint(i);
    }

    
   TCanvas *c1 = new TCanvas("c1", "c1",50,50,600,600);
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

   TH1F *hSum = new TH1F("hSum","",10,150,950);
   hSum->SetMinimum(0.);
   hSum->SetMaximum(550);
   hSum->SetDirectory(0);
   hSum->SetStats(0);
    hSum->Draw();
    hSum->GetYaxis()->SetRangeUser(0,500);
    hSum->GetXaxis()->SetRangeUser(150,950);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   hSum->SetLineColor(ci);
   hSum->SetLineStyle(0);
   hSum->SetMarkerStyle(20);
   hSum->GetXaxis()->SetTitle("m_{#tilde{t}} [GeV]");
   //hSum->GetXaxis()->SetBit(TAxis::kLabelsVert);
   hSum->GetXaxis()->SetLabelFont(42);
   //hSum->GetXaxis()->SetLabelOffset(0.005);
   hSum->GetXaxis()->SetLabelSize(0.035);
   hSum->GetXaxis()->SetTitleSize(0.06);
   hSum->GetXaxis()->SetTitleOffset(1.2);
   hSum->GetXaxis()->SetTitleFont(42);
   hSum->GetYaxis()->SetTitle("m_{#tilde{#chi}}_{1}^{0} [GeV]");
   hSum->GetYaxis()->SetLabelFont(42);
   //hSum->GetYaxis()->SetLabelOffset(0.007);
   hSum->GetYaxis()->SetLabelSize(0.035);
   hSum->GetYaxis()->SetTitleSize(0.05);
   hSum->GetYaxis()->SetTitleOffset(1.3);
   hSum->GetYaxis()->SetTitleFont(42);
    
    //TLegend *leg = new TLegend(0.4992416,0.4811189,0.898906,0.7503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.4992416,0.4811189,0.698906,0.7503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.6992416,0.2811189,0.898906,0.4503497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.6992416,0.3311189,0.898906,0.7903497,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.7582416,0.4211189,0.912,0.8043497,NULL,"brNDC");
    TLegend *legE = new TLegend(0.51,0.675,0.81,0.855,NULL,"brNDC");
    //leg-> SetNColumns(2);
    legE->SetBorderSize(0);
    legE->SetTextSize(0.04);
    legE->SetTextFont(42);
    legE->SetLineColor(1);
    legE->SetLineStyle(1);
    legE->SetLineWidth(2);
    legE->SetFillColor(0);
    legE->SetFillStyle(1001);
    legE->SetHeader("Expected");
    legE->AddEntry(gExp, "unpolarized","l");
    legE->AddEntry(gExpR, "right-handed","l");
    legE->AddEntry(gExpL, "left-handed","l");
    
    TLegend *legO = new TLegend(0.175,0.675,0.50,0.855,NULL,"brNDC");
    //legO-> SetNColumns(2);
    legO->SetBorderSize(0);
    legO->SetTextSize(0.04);
    legO->SetTextFont(42);
    legO->SetLineColor(1);
    legO->SetLineStyle(1);
    legO->SetLineWidth(2);
    legO->SetFillColor(0);
    legO->SetFillStyle(1001);
    legO->SetHeader("Observed");
    legO->AddEntry(gObs, "unpolarized","l");
    legO->AddEntry(gObsR, "right-handed","l");
    legO->AddEntry(gObsL, "left-handed","l");
    
    
    TGraph* graphWhite = new TGraph(5);
    graphWhite->SetName("white");
    graphWhite->SetTitle("white");
    graphWhite->SetFillColor(kWhite);
    graphWhite->SetFillStyle(1001);
    graphWhite->SetLineColor(kBlack);
    graphWhite->SetLineStyle(1);
    graphWhite->SetLineWidth(3);
    graphWhite->SetPoint(0,150, 500);
    graphWhite->SetPoint(1,950, 500);
    graphWhite->SetPoint(2,950, 500*0.6666666667);
    graphWhite->SetPoint(3,150, 500*0.6666666667);
    graphWhite->SetPoint(4,150, 500);
    
    Float_t diagX[4] = {175.+25.,175.+25.+5000,175.-25.+5000,175.-25.};
    Float_t diagY[4] = {0,5000,5000,0};
    TGraph *gdiagonal = new TGraph(4, diagX, diagY);
    gdiagonal->SetName("MtopDiagonal");
    gdiagonal->SetFillColor(kWhite);
    //#gdiagonal->SetFillColor(18);
    TLine* ldiagonal = new TLine(175,0.,650-25.,450);
    //TLine* ldiagonal = new TLine(175.,25,175+500,500);
    ldiagonal->SetLineColor(kGray);
    ldiagonal->SetLineStyle(2);
    TLatex* tdiagonal = new TLatex(400-2.5, 400-172.5,"m_{#tilde{t}} = m_{t} + m_{#tilde{#chi}_{1}^{0}}");
    //tdiagonal->SetTextAngle(TMath::RadToDeg()*TMath::ATan(float(800)/float(500)));
    tdiagonal->SetTextAngle(56.31);
    tdiagonal->SetTextColor(kGray+2);
    tdiagonal->SetTextAlign(11);
    tdiagonal->SetTextSize(0.025);

    TLine* l2 = new TLine(150,75,585,500);
    l2->SetLineColor(kGray);
    l2->SetLineStyle(2);
    if(killlowdiag){
        l2->SetX1(200); l2->SetY1(0); l2->SetX2(600); l2->SetY2(400);
    }
    TLatex *t2 = new TLatex(300, 300-72.5,"m_{#tilde{t}} = m_{W} + m_{#tilde{#chi}_{1}^{0}}");
    //t2->SetTextAngle(TMath::RadToDeg()*TMath::ATan(float(800)/float(500)));
    t2->SetTextAngle(56.31);
    t2->SetTextColor(kGray+2);
    t2->SetTextAlign(11);
    t2->SetTextSize(0.025);

    hSum->Draw("axis");
    
    gExpR->Draw("c");
    gExpL->Draw("c");
    gExp->Draw("c");
    gObsR->Draw("c");
    gObsL->Draw("c");
    gObs->Draw("c");

    gdiagonal->Draw("FSAME");
    ldiagonal->Draw("LSAME");
    l2->Draw();
    if(!killlowdiag) t2->Draw();
    tdiagonal->Draw("SAME");
    graphWhite->Draw("FSAME");
    graphWhite->Draw("LSAME");

    legE->Draw();
    legO->Draw();
    
    TLatex* textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}  NLO+NLL exclusion");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"#tilde{#chi} ");
    textModelLabel->SetNDC();
    textModelLabel->SetTextAlign(13);
    textModelLabel->SetTextFont(42);
    textModelLabel->SetTextSize(0.042);
    textModelLabel->Draw();
    
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
    TLatex *tPrel = new TLatex(0.265,0.944,"Preliminary");
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
