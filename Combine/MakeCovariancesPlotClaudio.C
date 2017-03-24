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

void MakeCovariancesPlotClaudio(){
    
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetPaintTextFormat(".1f");

    
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
     

    TFile *f = new TFile("CorrelationCovariance_datacard_std_T2tt_900_50.root");
  f->cd();
    TH2D *std = (TH2D*)f->Get("covarianceMatrix");
    std->SetName("std");
    TFile *f2 = new TFile("CorrelationCovariance_datacard_compressed_T2tt_900_50.root");
    //TFile *f2 = new TFile("CorrelationCovariance_datacard_compressed_T2tt_300_150.root");
    f2->cd();
    TH2D *compressed = (TH2D*)f2->Get("covarianceMatrix");
    compressed->SetName("compressed");
    

    // This is the correlation matrix for the standard analysis
    TH2D *correlation = new TH2D("covarianceMatrix","",27,0,27,27,0,27);
    TH2D *correlationtext = new TH2D("covarianceMatrix","",27,0,27,27,0,27);
    for(int x = 1; x<=27;++x){
        for(int y = 1; y<=27; ++y){
	  correlation->SetBinContent(x,y,std->GetBinContent(x,y));
	  correlationtext->SetBinContent(x,y,std->GetBinContent(x,y));
      //    if (x==y) correlationtext->SetBinContent(x,y,100);
	  // force rounding to at least 1 for display purposes
      //      if (correlationtext->GetBinContent(x,y) < 0.5 && correlationtext->GetBinContent(x,y)>=0) correlationtext->SetBinContent(x,y,1);
      //      else if (correlationtext->GetBinContent(x,y) > -0.5 && correlationtext->GetBinContent(x,y)<=0) correlationtext->SetBinContent(x,y,-1);
        }
    }

    // This is the correlation matrix for the compressed analysis
    TH2D *correlationComp = new TH2D("correlationMatrixCompressed","",4,0,4,4,0,4);
    TH2D *correlationtextComp = new TH2D("correlationMatrixCompressed","",4,0,4,4,0,4);
    for(int x = 1; x<=4;++x){
        for(int y = 1; y<=4; ++y){
	  correlationComp->SetBinContent(x,y,compressed->GetBinContent(x,y));
	  correlationtextComp->SetBinContent(x,y,compressed->GetBinContent(x,y));
      //    if (x==y) correlationtextComp->SetBinContent(x,y,100);
	  // force rounding to at least 1 for display purposes
	  //if (correlationtextComp->GetBinContent(x,y) < 0.5) correlationtext->SetBinContent(x,y,1);
      //else if (correlationtextComp->GetBinContent(x,y) > -0.5 && correlationtextComp->GetBinContent(x,y)<=0) correlationtextComp->SetBinContent(x,y,-1);
        }
    }

    correlationComp->GetXaxis()->SetBinLabel(1,"I1");
    correlationComp->GetXaxis()->SetBinLabel(2,"I2");
    correlationComp->GetXaxis()->SetBinLabel(3,"I3");
    correlationComp->GetXaxis()->SetBinLabel(4,"I4");
    correlationComp->GetYaxis()->SetBinLabel(1,"I1");
    correlationComp->GetYaxis()->SetBinLabel(2,"I2");
    correlationComp->GetYaxis()->SetBinLabel(3,"I3");
    correlationComp->GetYaxis()->SetBinLabel(4,"I4");
    //correlationComp->GetXaxis()->SetBit(TAxis::kLabelsVert);
    correlationComp->GetXaxis()->SetLabelSize(0.08);
    correlationComp->GetYaxis()->SetLabelSize(0.08);
    correlationComp->GetXaxis()->SetTitle("signal region");
    correlationComp->GetXaxis()->SetTitleOffset(1.2);
    correlationComp->GetYaxis()->SetTitleOffset(0.9);
    correlationComp->GetXaxis()->SetTitleSize(0.05);
    correlationComp->GetYaxis()->SetTitleSize(0.05);
    correlationComp->GetYaxis()->SetTitle("signal region");
    correlationComp->GetZaxis()->SetTitle("covariance");
    correlationComp->GetZaxis()->SetTitleSize(0.05);
    correlationComp->GetZaxis()->SetLabelSize(0.05);
    correlationComp->GetZaxis()->SetNdivisions(505);

    correlation->GetXaxis()->SetBinLabel(1,"A1");
    correlation->GetXaxis()->SetBinLabel(2,"A2");
    correlation->GetXaxis()->SetBinLabel(3,"A3");
    correlation->GetXaxis()->SetBinLabel(4,"A4");
    correlation->GetXaxis()->SetBinLabel(5,"B1");
    correlation->GetXaxis()->SetBinLabel(6,"B2");
    correlation->GetXaxis()->SetBinLabel(7,"B3");
    correlation->GetXaxis()->SetBinLabel(8,"C1");
    correlation->GetXaxis()->SetBinLabel(9,"C2");
    correlation->GetXaxis()->SetBinLabel(10,"C3");
    correlation->GetXaxis()->SetBinLabel(11,"C4");
    correlation->GetXaxis()->SetBinLabel(12,"C5");
    correlation->GetXaxis()->SetBinLabel(13,"D1");
    correlation->GetXaxis()->SetBinLabel(14,"D2");
    correlation->GetXaxis()->SetBinLabel(15,"D3");
    correlation->GetXaxis()->SetBinLabel(16,"D4");
    correlation->GetXaxis()->SetBinLabel(17,"E1");
    correlation->GetXaxis()->SetBinLabel(18,"E2");
    correlation->GetXaxis()->SetBinLabel(19,"E3");
    correlation->GetXaxis()->SetBinLabel(20,"F1");
    correlation->GetXaxis()->SetBinLabel(21,"F2");
    correlation->GetXaxis()->SetBinLabel(22,"G1");
    correlation->GetXaxis()->SetBinLabel(23,"G2");
    correlation->GetXaxis()->SetBinLabel(24,"G3");
    correlation->GetXaxis()->SetBinLabel(25,"G4");
    correlation->GetXaxis()->SetBinLabel(26,"H1");
    correlation->GetXaxis()->SetBinLabel(27,"H2");
    correlation->GetXaxis()->SetBit(TAxis::kLabelsVert);
    correlation->GetXaxis()->SetLabelSize(0.06);

    correlation->GetYaxis()->SetBinLabel(1,"A1");
    correlation->GetYaxis()->SetBinLabel(2,"A2");
    correlation->GetYaxis()->SetBinLabel(3,"A3");
    correlation->GetYaxis()->SetBinLabel(4,"A4");
    correlation->GetYaxis()->SetBinLabel(5,"B1");
    correlation->GetYaxis()->SetBinLabel(6,"B2");
    correlation->GetYaxis()->SetBinLabel(7,"B3");
    correlation->GetYaxis()->SetBinLabel(8,"C1");
    correlation->GetYaxis()->SetBinLabel(9,"C2");
    correlation->GetYaxis()->SetBinLabel(10,"C3");
    correlation->GetYaxis()->SetBinLabel(11,"C4");
    correlation->GetYaxis()->SetBinLabel(12,"C5");
    correlation->GetYaxis()->SetBinLabel(13,"D1");
    correlation->GetYaxis()->SetBinLabel(14,"D2");
    correlation->GetYaxis()->SetBinLabel(15,"D3");
    correlation->GetYaxis()->SetBinLabel(16,"D4");
    correlation->GetYaxis()->SetBinLabel(17,"E1");
    correlation->GetYaxis()->SetBinLabel(18,"E2");
    correlation->GetYaxis()->SetBinLabel(19,"E3");
    correlation->GetYaxis()->SetBinLabel(20,"F1");
    correlation->GetYaxis()->SetBinLabel(21,"F2");
    correlation->GetYaxis()->SetBinLabel(22,"G1");
    correlation->GetYaxis()->SetBinLabel(23,"G2");
    correlation->GetYaxis()->SetBinLabel(24,"G3");
    correlation->GetYaxis()->SetBinLabel(25,"G4");
    correlation->GetYaxis()->SetBinLabel(26,"H1");
    correlation->GetYaxis()->SetBinLabel(27,"H2");
    correlation->GetYaxis()->SetLabelSize(0.05);
    correlation->GetXaxis()->SetTitle("signal region");
    correlation->GetXaxis()->SetTitleOffset(1.5);
    correlation->GetYaxis()->SetTitle("signal region");
    correlation->GetZaxis()->SetTitle("covariance");
    correlation->GetZaxis()->SetTitleSize(0.05);
    correlation->GetZaxis()->SetLabelSize(0.05);
    correlation->GetZaxis()->SetRangeUser(0.01,500);


    TLatex *tLumi = new TLatex(0.904,0.920,"35.9 fb^{-1} (13 TeV)");
    tLumi->SetNDC();
    tLumi->SetTextAlign(31);
    tLumi->SetTextFont(42);
    tLumi->SetTextSize(0.042);
    tLumi->SetLineWidth(2);
    TLatex *tCMS = new TLatex(0.095,0.920,"CMS");
    tCMS->SetNDC();
    tCMS->SetTextAlign(11);
    tCMS->SetTextFont(61);
    tCMS->SetTextSize(0.0525);
    tCMS->SetLineWidth(2);
    //TLatex *tPrel = new TLatex(0.172,0.920,"Supplementary");
    TLatex *tPrel = new TLatex(0.172,0.920,"Preliminary");
    tPrel->SetNDC();
    tPrel->SetTextAlign(11);
    tPrel->SetTextFont(52);
    tPrel->SetTextSize(0.042);
    tPrel->SetLineWidth(2);

    gStyle->SetTextFont(42);
    TCanvas * c1 = new TCanvas("c1","",100,100,750,500);
    c1->SetLogz();
    //c1->SetLeftMargin(0.15);
    c1->SetRightMargin(0.15);
    //c1->SetTopMargin(0.07);
    //c1->SetBottomMargin(0.15);
    c1->SetBottomMargin(0.125);
    //correlation->GetZaxis()->SetRangeUser(std::min(0.,correlation->GetMinimum()),100.);
    correlation->Draw("colz");
    //correlationtext->SetMarkerSize(1.65);
    correlationtext->Draw("textsame");
    tLumi->Draw();
    tCMS->Draw();
    tPrel->Draw();
    c1->Print("CovariancePlotStandard.pdf","pdf");

   TCanvas * c2 = new TCanvas("c2","",100,100,750,500);
    c2->SetLogz();
    //c2->SetLeftMargin(0.15);
    c2->SetRightMargin(0.15);
    //c2->SetTopMargin(0.07);
    //c2->SetBottomMargin(0.15);
    c2->SetBottomMargin(0.125);
    //correlationComp->GetZaxis()->SetRangeUser(std::min(0.,correlationComp->GetMinimum()),100.);
    correlationComp->Draw("colz");
    correlationtextComp->SetMarkerSize(2.5);
    correlationtextComp->Draw("textsame");
    tLumi->Draw();
    tCMS->Draw();
    tPrel->Draw();
    c2->Print("CovariancePlotCompressed.pdf","pdf");

}
