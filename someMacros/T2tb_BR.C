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
#include "TGraph.h"
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

void T2tb_BR(bool obs=true, bool killmore=true){

    TGraph *g100;
    TGraph *g75;
    TGraph *g67;
    TGraph *g50;
    TGraph *g33;
    TGraph *g25;

    TGraph *g_2;

    //TFile *f100 = TFile::Open("Limits2DHistograms_T2tb_100_0_postfit.root");
    TFile *f100 = TFile::Open("Limits2DHistograms_T2tt_postfit.root");
    TFile *f75 = TFile::Open("Limits2DHistograms_T2tb_75_25_postfit.root");
    TFile *f67 = TFile::Open("Limits2DHistograms_T2tb_67_33_postfit.root");
    TFile *f50 = TFile::Open("Limits2DHistograms_T2tb_postfit.root");
    TFile *f33 = TFile::Open("Limits2DHistograms_T2tb_33_67_postfit.root");
    TFile *f25 = TFile::Open("Limits2DHistograms_T2tb_25_75_postfit.root");
    
    TGraph *g;
    if(obs){
        f100->cd();
        g = (TGraph*)f100->Get("gObs");
        g100 = (TGraph*)g->Clone("Obs100");
        f75->cd();
        g = (TGraph*)f75->Get("gObs");
        g75 = (TGraph*)g->Clone("Obs75");
        //g100_2 = (TGraph*)f75->Get("gObs_2");
        f67->cd();
        g = (TGraph*)f67->Get("gObs");
        g67 = (TGraph*)g->Clone("Obs67");
        f50->cd();
        g = (TGraph*)f50->Get("gObs");
        g50 = (TGraph*)g->Clone("Obs50");
        f33->cd();
        g = (TGraph*)f33->Get("gObs");//special
        g33 = (TGraph*)g->Clone("Obs33");
        f25->cd();
        g = (TGraph*)f25->Get("gObs");
        g25 = (TGraph*)g->Clone("Obs25");
        g = (TGraph*)f25->Get("gObs_2");
        g_2 = (TGraph*)g->Clone("Obs25_2");
    } else {
        f100->cd();
        g = (TGraph*)f100->Get("gExp");
        g100 = (TGraph*)g->Clone("Exp100");
        if(killmore){
            for(int i = g100->GetN(); i>=0; --i){
                double x,y;
                g100->GetPoint(i,x,y);
                if((x-y)<100) g100->RemovePoint(i);
            }
        }
        g = (TGraph*)f100->Get("gExp_2");
        g_2 = (TGraph*)g->Clone("Exp100_2");
        f75->cd();
        g = (TGraph*)f75->Get("gExp");
        g75 = (TGraph*)g->Clone("Exp75");
        f67->cd();
        g = (TGraph*)f67->Get("gExp");
        g67 = (TGraph*)g->Clone("Exp67");
        f50->cd();
        g = (TGraph*)f50->Get("gExp");
        g50 = (TGraph*)g->Clone("Exp50");
        f33->cd();
        g = (TGraph*)f33->Get("gExp");
        g33 = (TGraph*)g->Clone("Exp33");
        f25->cd();
        g = (TGraph*)f25->Get("gExp");
        g25 = (TGraph*)g->Clone("Exp25");
    }
    g100->SetLineStyle(1);
    g100->SetLineWidth(2);
    g75->SetLineStyle(1);
    g75->SetLineWidth(2);
    g67->SetLineStyle(1);
    g67->SetLineWidth(2);
    g50->SetLineStyle(1);
    g50->SetLineWidth(2);
    g33->SetLineStyle(1);
    g33->SetLineWidth(2);
    g25->SetLineStyle(1);
    g25->SetLineWidth(2);
    g_2->SetLineStyle(1);
    g_2->SetLineWidth(2);
    
    g100->SetLineColor(kRed-4);
    g75->SetLineColor(kGreen+1);
    g67->SetLineColor(kBlue-4);
    g50->SetLineColor(kBlack);
    g33->SetLineColor(kCyan+1);
    g25->SetLineColor(kMagenta+1);
    if(obs) g_2->SetLineColor(kMagenta+1);
    else    g_2->SetLineColor(kRed-4);


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

   TH1F *hSum = new TH1F("hSum","",10,200,800);
   hSum->SetMinimum(0.);
   hSum->SetMaximum(550);
   hSum->SetDirectory(0);
   hSum->SetStats(0);
    hSum->Draw();
    hSum->GetYaxis()->SetRangeUser(0,475);
    hSum->GetXaxis()->SetRangeUser(200,800);

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
    TLegend *legE = new TLegend(0.17,0.68,0.85,0.815,NULL,"brNDC");
    legE-> SetNColumns(3);
    legE->SetBorderSize(0);
    legE->SetTextSize(0.04);
    legE->SetTextFont(42);
    legE->SetLineColor(1);
    legE->SetLineStyle(1);
    legE->SetLineWidth(2);
    legE->SetFillColor(0);
    legE->SetFillStyle(1001);
    /*
    legE->SetHeader("BR(#tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}) : BR(#tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1}) [%]");
    legE->AddEntry(g100, "100 : 0","l");
    legE->AddEntry(g75, "75 : 25","l");
    legE->AddEntry(g67, "66.#bar{6} : 33.#bar{3}","l");
    legE->AddEntry(g50, "50 : 50","l");
    legE->AddEntry(g33, "33.#bar{3} : 66.#bar{6}","l");
    legE->AddEntry(g25, "25 : 75","l");
     */
    legE->SetHeader("BR(#tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}) : BR(#tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1}) [fractions]");
    legE->AddEntry(g100, "1 : 0","l");
    legE->AddEntry(g75, "#scale[0.8]{#lower[-0.25]{3}}/#scale[0.8]{#lower[0.25]{4}} : #scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{4}}","l");
    legE->AddEntry(g67, "#scale[0.8]{#lower[-0.25]{2}}/#scale[0.8]{#lower[0.25]{3}} : #scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{3}}","l");
    legE->AddEntry(g50, "#scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{2}} : #scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{2}}","l");
    legE->AddEntry(g33, "#scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{3}} : #scale[0.8]{#lower[-0.25]{2}}/#scale[0.8]{#lower[0.25]{3}}","l");
    legE->AddEntry(g25, "#scale[0.8]{#lower[-0.25]{1}}/#scale[0.8]{#lower[0.25]{4}} : #scale[0.8]{#lower[-0.25]{3}}/#scale[0.8]{#lower[0.25]{4}}","l");


    
    TGraph* graphWhite = new TGraph(5);
    graphWhite->SetName("white");
    graphWhite->SetTitle("white");
    graphWhite->SetFillColor(kWhite);
    graphWhite->SetFillStyle(1001);
    graphWhite->SetLineColor(kBlack);
    graphWhite->SetLineStyle(1);
    graphWhite->SetLineWidth(3);
    graphWhite->SetPoint(0,200, 475);
    graphWhite->SetPoint(1,800, 475);
    graphWhite->SetPoint(2,800, 475*0.6666666667);
    graphWhite->SetPoint(3,200, 475*0.6666666667);
    graphWhite->SetPoint(4,200, 475);
    
    Float_t diagX[4] = {175.+25.,175.+25.+5000,175.-25.+5000,175.-25.};
    Float_t diagY[4] = {0,5000,5000,0};
    //if(killmore) { diagX[3] = 175-150;  }
    Float_t diagX2[7] = {200.,650.,450.,225.,215.,200.,200.};
    Float_t diagY2[7] = {0.,450.,450.,225.,65.,50.,0.};
    TGraph *gdiagonal;
    if(killmore) gdiagonal = new TGraph(7, diagX2, diagY2);
    else gdiagonal = new TGraph(4, diagX, diagY);
    gdiagonal->SetName("MtopDiagonal");
    gdiagonal->SetFillColor(kWhite);
    //#gdiagonal->SetFillColor(18);
    TLine* ldiagonal = new TLine(200,25.,650-25.,475);
    ldiagonal->SetLineColor(kGray);
    ldiagonal->SetLineStyle(2);
    TLatex* tdiagonal = new TLatex(300-2.5, 300-172.5,"m_{#tilde{t}} = m_{t} + m_{#tilde{#chi}_{1}^{0}}");
    //tdiagonal->SetTextAngle(TMath::RadToDeg()*TMath::ATan(float(800)/float(487.5)));
    tdiagonal->SetTextAngle(51.5);
    tdiagonal->SetTextColor(kGray+2);
    tdiagonal->SetTextAlign(11);
    tdiagonal->SetTextSize(0.025);
    TLine* l2 = new TLine(200,75,575,475);
    l2->SetLineColor(kGray);
    l2->SetLineStyle(2);
    if(killmore) { l2->SetX1(200); l2->SetY1(0); l2->SetX2(600); l2->SetY2(400); }
    TLatex* t2 = new TLatex(300, 300-72.5,"m_{#tilde{t}} = m_{W} + m_{#tilde{#chi}_{1}^{0}}");
    //t2->SetTextAngle(TMath::RadToDeg()*TMath::ATan(float(800)/float(500)));
    t2->SetTextAngle(56.31);
    t2->SetTextColor(kGray+2);
    t2->SetTextAlign(11);
    t2->SetTextSize(0.025);


    hSum->Draw("axis");
    
    //g_2->Draw("l");
    g25->Draw("c");
    g33->Draw("c");
    g50->Draw("c");
    g67->Draw("c");
    g75->Draw("c");
    g100->Draw("c");
    g_2->Draw("c");

    gdiagonal->Draw("FSAME");
    ldiagonal->Draw("LSAME");
    tdiagonal->Draw("SAME");
    //t2->Draw();
    l2->Draw();
    graphWhite->Draw("FSAME");
    graphWhite->Draw("LSAME");
    hSum->Draw("sameaxis");

    legE->Draw();
    
    TLatex* textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*,     #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}  or  #tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1} #rightarrow bW* #tilde{#chi}^{0}_{1} ");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"#tilde{#chi} ");
    textModelLabel->SetNDC();
    textModelLabel->SetTextAlign(13);
    textModelLabel->SetTextFont(42);
    textModelLabel->SetTextSize(0.042);
    textModelLabel->Draw();
    TLatex* textlLabel= new TLatex(0.175,0.86,"NLO+NLL exclusion");
    textlLabel->SetNDC();
    textlLabel->SetTextAlign(13);
    textlLabel->SetTextFont(42);
    textlLabel->SetTextSize(0.042);
    textlLabel->Draw();
    string obsstr = "observed";
    if(!obs) obsstr = "expected";
    TLatex* obsLabel= new TLatex(0.2,0.6625,obsstr.c_str());
    obsLabel->SetNDC();
    obsLabel->SetTextAlign(13);
    obsLabel->SetTextFont(32);
    obsLabel->SetTextSize(0.042);
    obsLabel->Draw();
    
    TLatex* Label= new TLatex(0.925,0.6625,"m_{#tilde{#chi}_{1}^{#pm}} #minus m_{#tilde{#chi}_{1}^{0}} = 5 GeV");
    Label->SetNDC();
    Label->SetTextAlign(33);
    Label->SetTextFont(42);
    Label->SetTextSize(0.042);
    Label->Draw();
    
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
