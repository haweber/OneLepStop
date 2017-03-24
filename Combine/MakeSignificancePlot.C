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

//bool killlowdiag = true;

void MakeSignificancePlot(string scan="T2tt", int exp=0){

    
    int NRGBs = 5;
    int NCont = 255;
    double stops[5] {0.00, 0.34, 0.61, 0.84, 1.00};
    double red[5] = {0.50, 0.50, 1.00, 1.00, 1.00};
    double green[5] = {0.50, 1.00, 1.00, 0.60, 0.50};
    double blue[5] = {1.00, 1.00, 0.50, 0.40, 0.50};
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
    //gStyle->SetPalette(kLightTemperature);
    //gStyle->SetPalette(kBird);
    
    
    bool pval = false;
    bool T2tt = false;
    bool T2tb = false;
    bool T2bW = false;
    string filename = "Significances2DHistograms_" + scan + ".root";
    if(scan.find("T2tt")!=string::npos){
        cout << "is T2tt" << endl;
        T2tt = true;
    }
    if(scan.find("T2tb")!=string::npos){
        cout << "is T2tb" << endl;
        T2tb = true;
    }
    if(scan.find("T2bW")!=string::npos){
        cout << "is T2bW" << endl;
        T2bW = true;
    }
    if(!T2tt&&!T2bW&&!T2tb) exit(0);
    TFile *f = TFile::Open(filename.c_str());
    cout << filename << endl;
    TH2F *h;
    if(pval){
        if(exp==0) h = (TH2F*)f->Get("hpObs");
        else if(exp==1) h = (TH2F*)f->Get("hpExpPosteriori");
        else if(exp==2) h = (TH2F*)f->Get("hpExpPriori");
    }
    else {
        if(exp==0) h = (TH2F*)f->Get("hObs");
        else if(exp==1) h = (TH2F*)f->Get("hExpPosteriori");
        else if(exp==2) h = (TH2F*)f->Get("hExpPriori");
    }
    cout << h->Integral() << endl;
    h->GetXaxis()->SetTitle("m_{#tilde{t}} [GeV]");
    h->GetXaxis()->SetLabelFont(42);
    h->GetXaxis()->SetLabelSize(0.035);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetTitleOffset(1.2);
    h->GetXaxis()->SetTitleFont(42);
    h->GetXaxis()->SetNdivisions(507);
    h->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
    h->GetYaxis()->SetLabelFont(42);
    h->GetYaxis()->SetLabelSize(0.035);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleOffset(1.35);
    h->GetYaxis()->SetTitleFont(42);
    double maximum = h->GetMaximum();
    double minimum = h->GetMinimum();
    double sigmin = 99; int sigminx=-1; int sigminy=-1; if(pval) sigmin = -99;
    h->GetZaxis()->SetRangeUser(minimum,maximum);
    for(int x = 1; x<=h->GetNbinsX();++x){
        for(int y = 1; y<=h->GetNbinsX();++y){
            if(!pval&&h->GetBinContent(x,y)<sigmin){ sigmin =h->GetBinContent(x,y); sigminx = x; sigminy = y; }
            if( pval&&h->GetBinContent(x,y)>sigmin){ sigmin =h->GetBinContent(x,y); sigminx = x; sigminy = y; }
            if(T2tt&&!pval&&h->GetXaxis()->GetBinLowEdge(x)<h->GetYaxis()->GetBinLowEdge(y)+75) h->SetBinContent(x,y,-999);
            if(T2tb&&!pval&&h->GetXaxis()->GetBinLowEdge(x)<h->GetYaxis()->GetBinLowEdge(y)+200) h->SetBinContent(x,y,-999);
            if(T2bW&&!pval&&h->GetXaxis()->GetBinLowEdge(x)<h->GetYaxis()->GetBinLowEdge(y)+200) h->SetBinContent(x,y,-999);
            //if(h->GetXaxis()->GetBinLowEdge(x)<374) continue;
            //if(h->GetXaxis()->GetBinLowEdge(x)>424) continue;
            //if(h->GetYaxis()->GetBinLowEdge(y)<199) continue;
            //if(h->GetYaxis()->GetBinLowEdge(y)>249) continue;
            //if(!pval&&h->GetBinContent(x,y)>0.3) h->SetBinContent(x,y,0.05);
        }
    }
    //h->GetZaxis()->SetRangeUser(minimum,maximum);
    h->GetZaxis()->SetRangeUser(-2.5,2.5);
    if(T2tt&&exp==0) h->GetZaxis()->SetRangeUser(-3,3);
    //if(T2tt&&exp==0) h->GetZaxis()->SetRangeUser(-1.5,1.5);//compressed
    if(T2tb&&exp==0) h->GetZaxis()->SetRangeUser(-3,3);
    if(T2bW&&exp==0) h->GetZaxis()->SetRangeUser(-3,3);
    if(T2tt&&exp==1) h->GetZaxis()->SetRangeUser(0.,9.);
    //if(T2tt&&exp==1) h->GetZaxis()->SetRangeUser(0.,6.);//compressed
    if(T2tb&&exp==1) h->GetZaxis()->SetRangeUser(0.,9.);
    if(T2bW&&exp==1) h->GetZaxis()->SetRangeUser(0.,9.);
    if(T2tt&&exp==2) h->GetZaxis()->SetRangeUser(0.,11.);
    //if(T2tt&&exp==2) h->GetZaxis()->SetRangeUser(0.,7.);//compressed
    if(T2tb&&exp==2) h->GetZaxis()->SetRangeUser(0.,11.);
    if(T2bW&&exp==2) h->GetZaxis()->SetRangeUser(0.,11.);
    if(!pval) cout << "minimal significance " << sigmin << " at " << h->GetXaxis()->GetBinLowEdge(sigminx) << "-" << h->GetYaxis()->GetBinLowEdge(sigminy) << endl;
    else cout << "maximal p- value " << sigmin << " at " << h->GetXaxis()->GetBinLowEdge(sigminx) << "-" << h->GetYaxis()->GetBinLowEdge(sigminy) << endl;
    
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
//   c1->SetRightMargin(0.05);
    c1->SetRightMargin(0.15);
   c1->SetTopMargin(0.07);
   c1->SetBottomMargin(0.15);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   gStyle->SetHatchesLineWidth(0);

    TH1F *hSum;
    if(T2tt) hSum = new TH1F("hSum","",10,150,1200);
    if(T2bW) hSum = new TH1F("hSum","",10,200,1200);
    if(T2tb) hSum = new TH1F("hSum","",10,200,1200);
   hSum->SetMinimum(0.);
   hSum->SetMaximum(700);
   hSum->SetDirectory(0);
   hSum->SetStats(0);
    hSum->Draw();
    if(T2tt){
        hSum->GetYaxis()->SetRangeUser(0,800);
        hSum->GetXaxis()->SetRangeUser(150,1200);
    }
    if(T2tb){
        hSum->GetYaxis()->SetRangeUser(0,800);
        hSum->GetXaxis()->SetRangeUser(200,1200);
    }
    if(T2bW){
        hSum->GetYaxis()->SetRangeUser(0,800);
        hSum->GetXaxis()->SetRangeUser(200,1200);
    }

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
   hSum->GetXaxis()->SetNdivisions(507);
   hSum->GetYaxis()->SetTitle("m_{#tilde{#chi}}_{1}^{0} [GeV]");
   hSum->GetYaxis()->SetLabelFont(42);
   //hSum->GetYaxis()->SetLabelOffset(0.007);
   hSum->GetYaxis()->SetLabelSize(0.035);
   hSum->GetYaxis()->SetTitleSize(0.05);
   hSum->GetYaxis()->SetTitleOffset(1.3);
   hSum->GetYaxis()->SetTitleFont(42);
    
   /*
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
    */
    
    TGraph* graphWhite = new TGraph(5);
    graphWhite->SetName("white");
    graphWhite->SetTitle("white");
    graphWhite->SetFillColor(kWhite);
    graphWhite->SetFillStyle(1001);
    graphWhite->SetLineColor(kBlack);
    graphWhite->SetLineStyle(1);
    graphWhite->SetLineWidth(3);
    if(T2tt){
        graphWhite->SetPoint(0,150,  800);
        graphWhite->SetPoint(1,1200, 800);
        graphWhite->SetPoint(2,1200, 800*0.75);
        graphWhite->SetPoint(3,150,  800*0.75);
        graphWhite->SetPoint(4,150,  800);
    }
    if(T2bW){
        graphWhite->SetPoint(0,200,  800);
        graphWhite->SetPoint(1,1200, 800);
        graphWhite->SetPoint(2,1200, 800*0.75);
        graphWhite->SetPoint(3,200,  800*0.75);
        graphWhite->SetPoint(4,200,  800);
    }
    if(T2tb){
        graphWhite->SetPoint(0,200,  800);
        graphWhite->SetPoint(1,1200, 800);
        graphWhite->SetPoint(2,1200, 800*0.75);
        graphWhite->SetPoint(3,200,  800*0.75);
        graphWhite->SetPoint(4,200,  800);
    }

    Float_t diagX[4] = {262.5,287.5,200,150};
    Float_t diagY[4] = {112.5,87.5,0,0};
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
//    if(killlowdiag){
//        l2->SetX1(200); l2->SetY1(0); l2->SetX2(600); l2->SetY2(400);
//    }
    TLatex *t2 = new TLatex(300, 300-72.5,"m_{#tilde{t}} = m_{W} + m_{#tilde{#chi}_{1}^{0}}");
    //t2->SetTextAngle(TMath::RadToDeg()*TMath::ATan(float(800)/float(500)));
    t2->SetTextAngle(56.31);
    t2->SetTextColor(kGray+2);
    t2->SetTextAlign(11);
    t2->SetTextSize(0.025);
    
    

    hSum->Draw("axis");
    h->Draw("COLZsame");
    hSum->Draw("axissame");

    if(T2tt||T2tb) gdiagonal->Draw("FSAME");
    //ldiagonal->Draw("LSAME");
    //l2->Draw();
//    if(!killlowdiag) t2->Draw();
    //tdiagonal->Draw("SAME");
    graphWhite->Draw("FSAME");
    graphWhite->Draw("LSAME");

    string textstring = "observed";
    if(exp!=0) textstring = "expected";
    TLatex* textOE= new TLatex(0.175,0.791,textstring.c_str() );
    textOE->SetNDC();
    textOE->SetTextAlign(13);
    textOE->SetTextFont(42);
    textOE->SetTextSize(0.042);
    textOE->Draw();
    

   TLatex* textModelLabel;
    if(T2tt) textModelLabel = new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}");
    if(T2bW) textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1}, #tilde{#chi}^{#pm}_{1} #rightarrow W^{#pm} #tilde{#chi}^{0}_{1}");
    if(T2tb) textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1} / #tilde{t} #rightarrow b #tilde{#chi}^{#pm}_{1}, #tilde{#chi}^{#pm}_{1} #rightarrow W^{#pm} #tilde{#chi}^{0}_{1}");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"pp #rightarrow #tilde{t} #tilde{t}*, #tilde{t} #rightarrow t #tilde{#chi}^{0}_{1}");
    //TLatex* textModelLabel= new TLatex(0.175,0.92,"#tilde{#chi} ");
    textModelLabel->SetNDC();
    textModelLabel->SetTextAlign(13);
    textModelLabel->SetTextFont(42);
    textModelLabel->SetTextSize(0.042);
    textModelLabel->Draw();
    TLatex* textlLabel= new TLatex(0.175,0.85,"NLO+NLL significance");
    textlLabel->SetNDC();
    textlLabel->SetTextAlign(13);
    textlLabel->SetTextFont(42);
    textlLabel->SetTextSize(0.042);
    textlLabel->Draw();
    
    TLatex* textMass;
    if(T2bW) textMass = new TLatex(0.577,0.85,"m_{#tilde{#chi}_{1}^{#pm}}#scale[0.5]{ }=#scale[0.5]{ }(m_{#tilde{t}} + m_{#tilde{#chi}_{1}^{0}})/2");
    if(T2tb) textMass = new TLatex(0.577,0.85,"m_{#tilde{#chi}_{1}^{#pm}}#scale[0.5]{ }=#scale[0.5]{ }m_{#tilde{#chi}_{1}^{0}}#scale[0.5]{ }+#scale[0.5]{ }5#scale[0.5]{ }GeV");
    if(T2bW||T2tb){
        textMass->SetNDC();
        textMass->SetTextAlign(13);
        textMass->SetTextFont(42);
        textMass->SetTextSize(0.042);
    }
    if(T2tb||T2bW) textMass->Draw();
    
    if(T2tb){
        TLatex *textBR = new TLatex(0.375,0.8,"BR(#tilde{t}#scale[0.5]{ }#rightarrow#scale[0.5]{ }t#tilde{#chi}^{0}_{1})#scale[0.5]{ }=#scale[0.5]{ }BR(#tilde{t}#scale[0.5]{ }#rightarrow#scale[0.5]{ }b#tilde{#chi}^{#pm}_{1})#scale[0.5]{ }=#scale[0.5]{ }0.5");
        textBR->SetNDC();
        textBR->SetTextAlign(13);
        textBR->SetTextFont(42);
        textBR->SetTextSize(0.042);
        textBR->Draw();
    }
    
    string psig = "significance [#sigma]";
    if(pval) psig = "p-value";
    TLatex * ztex = new TLatex(0.985,0.92,psig.c_str() );
    ztex->SetNDC();
    ztex->SetTextAlign(31);
    ztex->SetTextFont(42);
    ztex->SetTextSize(0.045);
    ztex->SetTextAngle(90);
    ztex->SetLineWidth(2);
    ztex->Draw();
    

    //final CMS style
    //TLatex *tLumi = new TLatex(0.846,0.944,"36.6 fb^{-1} (13 TeV)");
    TLatex *tLumi = new TLatex(0.846,0.944,"35.9 fb^{-1} (13 TeV)");
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
    string outname = "Significance_" + scan;
    if(exp==0) outname += "_Observed.eps";
    if(exp==1) outname += "_ExpPosteriori.eps";
    if(exp==2) outname += "_ExpPriori.eps";

    c1->SaveAs(outname.c_str());
}
