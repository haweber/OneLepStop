#include "TEfficiency.h"
#include "TEventList.h"
#include "TLorentzVector.h"
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
#include "TCut.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TH3F.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TAxis.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TMap.h"
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

inline TString MakeOutputDir(TString dir){
    if(!dir.EndsWith("/")) dir += "/";
    // Create directory if needed
    //  >> NOTE: This function needs to be called before the booking functions!
    char cmd[100];
    sprintf(cmd,"mkdir -p %s", dir.Data());
    system(cmd);
    return dir;
}

void PlotROCs(){
    
    bool logscales = false;
    
  int pf=0;
  string prefix = "";
  if(pf==0)  prefix = "";
  if(pf==1)  prefix = "MET300";
  if(pf==2)  prefix = "chi210";
  if(pf==3)  prefix = "MT2W200";
    
    //string signame = "Stop_850_100";
    //string signame = "Stop_650_325";
    //string signame = "Stop_500_325";
    //string signame = "Stop_425_325";
    vector<string> signame; signame.clear();
    signame.push_back("Stop_850_100");
    signame.push_back("Stop_650_325");
    signame.push_back("Stop_500_325");
    signame.push_back("Stop_425_325");
  
    map<string, TGraphAsymmErrors*> histos; //massive
    map<string, TGraphAsymmErrors*> histosSP; //massive
  vector<string> histonames; histonames.clear();
    
    
    string outfilename = "j3Compare";
    /*
    histonames.push_back("MET_noMETsqrtHT");            
    histonames.push_back("MET_METsqrtHT14");            
    histonames.push_back("METsqrtHT_MET150");           
    histonames.push_back("METsqrtHT_noMET");            
    histonames.push_back("METsqrtHTlpt_MET150");        
    histonames.push_back("METsqrtHTlpt_noMET");         
    */
    /**/
    histonames.push_back("MT2W3j");
    //histonames.push_back("MT2W4j");
    //histonames.push_back("MT2W3j4j");
    //histonames.push_back("MT2W3j_noord");
    //histonames.push_back("MT2W4j_noord");
    //histonames.push_back("MT2W3j4j_noord");
    
    histonames.push_back("Topness3j");
    //histonames.push_back("Topness4j");
    //histonames.push_back("Topness3j4j");
    //histonames.push_back("Topness3j_noord");
    //histonames.push_back("Topness4j_noord");
    //histonames.push_back("Topness3j4j_noord");
    
    histonames.push_back("TopnessMod3j");
    //histonames.push_back("TopnessMod4j");
    //histonames.push_back("TopnessMod3j4j");
    //histonames.push_back("TopnessMod3j_noord");
    //histonames.push_back("TopnessMod4j_noord");
    //histonames.push_back("TopnessMod3j4j_noord");
    
    //histonames.push_back("MT2lbb3j");
    //histonames.push_back("MT2lbb4j");
    //histonames.push_back("MT2lbb3j4j");
    //histonames.push_back("MT2lbb3j_noord");
    //histonames.push_back("MT2lbb4j_noord");
    //histonames.push_back("MT2lbb3j4j_noord");
    
    //histonames.push_back("MT2lbbqq3j");
    //histonames.push_back("MT2lbbqq4j");
    //histonames.push_back("MT2lbbqq3j4j");
    //histonames.push_back("MT2lbbqq3j_noord");
    //histonames.push_back("MT2lbbqq4j_noord");
    //histonames.push_back("MT2lbbqq3j4j_noord");
    
    //histonames.push_back("mMT2lbb3j");
    //histonames.push_back("mMT2lbb4j");
    //histonames.push_back("mMT2lbb3j4j");
    //histonames.push_back("mMT2lbb3j_noord");
    //histonames.push_back("mMT2lbb4j_noord");
    //histonames.push_back("mMT2lbb3j4j_noord");

    //histonames.push_back("mMT2lbbqq3j");
    //histonames.push_back("mMT2lbbqq4j");
    //histonames.push_back("mMT2lbbqq3j4j");
    //histonames.push_back("mMT2lbbqq3j_noord");
    //histonames.push_back("mMT2lbbqq4j_noord");
    //histonames.push_back("mMT2lbbqq3j4j_noord");
/**/
    TLegend *leg = new TLegend(0.1997315,0.6993844,0.399396,0.9005316,NULL,"brNDC");
    //TLegend *leg = new TLegend(0.1997315,0.5993844,0.399396,0.9005316,NULL,"brNDC");
    leg->SetBorderSize(0);
    leg->SetTextFont(62);
    leg->SetTextSize(0.03181185);
    //leg->SetTextSize(0.02581185);
    leg->SetTextFont(42);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(1001);
    
    string rootname = "TGraphsFurtherChecks.root";
    if(pf>0)  rootname = "TGraphs"+prefix+"_FurtherChecks.root";
    TFile *fin = TFile::Open(rootname.c_str());
    fin->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
        for(unsigned int j = 0; j<signame.size(); ++j){
            string mapname = histonames[i] + "_"+signame[j];
            if(histos.count(mapname) == 0 ) histos[mapname] = (TGraphAsymmErrors*)fin->Get(mapname.c_str());
            histos[mapname]->GetXaxis()->SetTitle("#varepsilon_{sig}"); histos[mapname]->GetYaxis()->SetTitle("#varepsilon_{bkg}");
            if(i==0)     { histos[mapname]->SetLineColor(kBlue);     histos[mapname]->SetMarkerColor(kBlue);     if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==1){ histos[mapname]->SetLineColor(kRed);      histos[mapname]->SetMarkerColor(kRed);      if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==2){ histos[mapname]->SetLineColor(kMagenta);  histos[mapname]->SetMarkerColor(kMagenta);  if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==3){ histos[mapname]->SetLineColor(kGreen+1);  histos[mapname]->SetMarkerColor(kGreen+1);  if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==4){ histos[mapname]->SetLineColor(kCyan+1);   histos[mapname]->SetMarkerColor(kCyan+1);   if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==5){ histos[mapname]->SetLineColor(kYellow+1); histos[mapname]->SetMarkerColor(kYellow+1); if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else if(i==6){ histos[mapname]->SetLineColor(kOrange-3); histos[mapname]->SetMarkerColor(kOrange-3); if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
            else         { histos[mapname]->SetLineColor(4+i);       histos[mapname]->SetMarkerColor(4+i);       if(j==0) leg->AddEntry(histos[mapname], histonames[i].c_str(), "lp"); }
        }
    }
    for(unsigned int i = 0; i<histonames.size(); ++i){
        for(unsigned int j = 0; j<signame.size(); ++j){
            string mapname = histonames[i] + "_"+signame[j];
            string loadmapname = histonames[i] + "_"+signame[j] + "SP";
            if(histosSP.count(mapname) == 0 ) histosSP[mapname] = (TGraphAsymmErrors*)fin->Get(loadmapname.c_str());
            histosSP[mapname]->GetXaxis()->SetTitle("#varepsilon_{sig}"); histosSP[mapname]->GetYaxis()->SetTitle("#varepsilon_{bkg}");
            if(i==0)     { histosSP[mapname]->SetLineColor(kBlue);     histosSP[mapname]->SetMarkerColor(kBlue);     histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==1){ histosSP[mapname]->SetLineColor(kRed);      histosSP[mapname]->SetMarkerColor(kRed);      histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==2){ histosSP[mapname]->SetLineColor(kMagenta);  histosSP[mapname]->SetMarkerColor(kMagenta);  histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==3){ histosSP[mapname]->SetLineColor(kGreen+1);  histosSP[mapname]->SetMarkerColor(kGreen+1);  histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==4){ histosSP[mapname]->SetLineColor(kCyan+1);   histosSP[mapname]->SetMarkerColor(kCyan+1);   histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==5){ histosSP[mapname]->SetLineColor(kYellow+1); histosSP[mapname]->SetMarkerColor(kYellow+1); histosSP[mapname]->SetMarkerStyle(20); }
            else if(i==6){ histosSP[mapname]->SetLineColor(kOrange-3); histosSP[mapname]->SetMarkerColor(kOrange-3); histosSP[mapname]->SetMarkerStyle(20); }
            else         { histosSP[mapname]->SetLineColor(4+i);       histosSP[mapname]->SetMarkerColor(4+i);       histosSP[mapname]->SetMarkerStyle(20); }
        }
    }

    TCanvas *c1 = new TCanvas("c1", "",565,86,600,602);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    c1->Range(0,0,1,1);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    c1->SetTickx(1);
    c1->SetTicky(1);
    c1->SetLeftMargin(0.18);
    c1->SetRightMargin(0.05);
    c1->SetTopMargin(0.07);
    c1->SetBottomMargin(0.15);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    if(logscales) {
        c1->SetLogy(1);
        c1->SetLogx(1);
    }
    c1->cd();
    for(unsigned int j = 0; j<signame.size(); ++j){
        c1->Clear();
        for(unsigned int i = 0; i<histonames.size(); ++i){
            string mapname = histonames[i] + "_"+signame[j];
            if(i==0) histos[mapname]->Draw("alX");
            else histos[mapname]->Draw("lX");
            histosSP[mapname]->Draw("pX");
        }
        leg->Draw("same");
        TString outname = "../../plots/MassVariableStudies/furtherchecks/ROCcurves/";
        if(pf>0)outname = outname + prefix + "/";
        //outname = outname + signame + "/";
        MakeOutputDir(outname);
        if(logscales) outname = outname + "Log_" + outfilename + "_"+signame[j]+".pdf";
        else outname = outname + outfilename + "_"+signame[j]+".pdf";
        c1->Update();
        c1->SaveAs(outname.Data());
    }

}
