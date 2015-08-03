//
//  makePlotTrigger2D.c
//  
//
//  Created by Hannsjoerg Weber on 28/07/15.
//
//

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include <iostream>
#include <vector>
#include <string>
#include "TString.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TROOT.h"
#include "TF1.h"
#include "TLatex.h"
#include <sstream>
#include <fstream>

void makePlotTrigger2D(){
    
    string whichdata = "SingleMuon";
    //string whichdata = "DoubleMuon";
    
    map<string, TH2F*> histos2D;
    vector<string> histonames2Dtag; histonames2Dtag.clear();
    vector<string> histonames2Dprobe; histonames2Dprobe.clear();
    vector<string> histonames2Deff; histonames2Deff.clear();
    
    histonames2Dtag.push_back("Trigger_PureIsoMu20Tag_EtavsPhi");
    histonames2Dprobe.push_back("Trigger_PureIsoMu20Probe_EtavsPhi");
    histonames2Deff.push_back("Trigger_PureIsoMu20Eff_EtavsPhi");
    histonames2Dtag.push_back("Trigger_IsoTkMu20Tag_EtavsPhi");
    histonames2Dprobe.push_back("Trigger_IsoTkMu20Probe_EtavsPhi");
    histonames2Deff.push_back("Trigger_IsoTkMu20Eff_EtavsPhi");
    
    
    string outputdir = "../plots/first_20150727/";
    string  inputdir = "../rootfiles/first_20150727/";
    TString fdataname = (inputdir+"Histos3Trigger_"+whichdata+".root");
    TFile *fdata = TFile::Open(fdataname.Data());
    
    TCanvas *c1 = new TCanvas("c1", "c1",247,22,600,600);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    //c1->Range(-350.6494,-288.4615,1597.403,1634.615);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    //c1->SetLogz();
    c1->SetTickx(1);
    c1->SetTicky(1);
    c1->SetLeftMargin(0.14);
    c1->SetRightMargin(0.19);
    c1->SetTopMargin(0.08);
    c1->SetBottomMargin(0.14);
    c1->SetFrameBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    
    for(unsigned int i = 0; i<histonames2Dtag.size(); ++i){
        for(unsigned int j = 0; j<6;++j){
            string prefix = "";
            if(j==1) prefix = "Run251244_";
            else if(j==2) prefix = "Run251251_";
            else if(j==3) prefix = "Run251252_";
            else if(j==4) prefix = "RunPre251561_";
            else if(j>=5) prefix = "RunAfter251561_";
            string mapnamet = prefix + histonames2Dtag[i]+"_"+whichdata;
            if(histos2D.count(mapnamet) == 0 ) histos2D[mapnamet] = (TH2F*)fdata->Get(mapnamet.c_str());
            histos2D[mapnamet]->Rebin2D(2,2);
            string mapnamep = prefix + histonames2Dprobe[i]+"_"+whichdata;
            if(histos2D.count(mapnamep) == 0 ) histos2D[mapnamep] = (TH2F*)fdata->Get(mapnamep.c_str());
            histos2D[mapnamep]->Rebin2D(2,2);
            string mapnamee = prefix + histonames2Deff[i]+"_"+whichdata;
            if(histos2D.count(mapnamee) == 0 ) histos2D[mapnamee] = (TH2F*)histos2D[mapnamep]->Clone(mapnamee.c_str());
            histos2D[mapnamee]->Divide(histos2D[mapnamet]);
            histos2D[mapnamee]->GetXaxis()->SetTitle("#eta");
            histos2D[mapnamee]->GetYaxis()->SetTitle("#phi");
            histos2D[mapnamee]->GetXaxis()->SetLabelFont(42);
            //   histos2D[mapnamee]->GetXaxis()->SetLabelOffset(1.2);
            histos2D[mapnamee]->GetXaxis()->SetLabelSize(0.04);
            histos2D[mapnamee]->GetXaxis()->SetTitleSize(0.05);
            histos2D[mapnamee]->GetXaxis()->SetTitleOffset(1.2);
            histos2D[mapnamee]->GetXaxis()->SetTitleFont(42);
            histos2D[mapnamee]->GetYaxis()->SetLabelFont(42);
            //  histos2D[mapnamee]->GetYaxis()->SetLabelOffset(0.007);
            histos2D[mapnamee]->GetYaxis()->SetLabelSize(0.04);
            histos2D[mapnamee]->GetYaxis()->SetTitleSize(0.05);
            histos2D[mapnamee]->GetYaxis()->SetTitleOffset(1.35);
            histos2D[mapnamee]->GetYaxis()->SetTitleFont(42);
            c1->cd();
            histos2D[mapnamee]->Draw("COLZ");
            TLatex *   tex = new TLatex(0.253356,0.95,mapnamee.c_str());
            tex->SetNDC();
            tex->SetTextFont(42);
            tex->SetTextSize(0.04181185);
            tex->SetLineWidth(2);
            tex->Draw();
            c1->Update();
            string outname = outputdir + whichdata + "/" + mapnamee + ".pdf";
            c1->SaveAs(outname.c_str());
            c1->Clear();
            delete tex;
        }
    }
    
}
