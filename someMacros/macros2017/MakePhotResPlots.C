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

void MakePhotResPlots(){
 
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    /*
    map<string, TH1F*> htt1l;
    TFile *ftt1l = TFile::Open("CheckResolutionTT1l.root");
    TIter itertt1l(ftt1l->GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)itertt1l())) {
        TH1F *h = (TH1F*)key->ReadObj();
        htt1l[h->GetName()] = h;
    }
    for(map<string,TH1F*>::iterator h=    htt1l.begin(); h!=    htt1l.end();++h) {
        TString temp = h->first;
        if(temp.Contains("4j_mtmod")||temp.Contains("4j_htmod")){
            if(temp.Contains("res0")) {
                if(htt1l.count("MET_4j_tmodgt0_res0")==0)  htt1l["MET_4j_tmodgt0_res0"] = (TH1F*)h->second->Clone("MET_4j_tmodgt0_res0");
                else htt1l["MET_4j_tmodgt0_res0"]->Add(h->second);
            }
            if(temp.Contains("floatres")) {
                if(htt1l.count("MET_4j_tmodgt0_floatres")==0)  htt1l["MET_4j_tmodgt0_floatres"] = (TH1F*)h->second->Clone("MET_4j_tmodgt0_floatres");
                else htt1l["MET_4j_tmodgt0_floatres"]->Add(h->second);
            }
            if(temp.Contains("floatworseres")) {
                if(htt1l.count("MET_4j_tmodgt0_floatworseres")==0)  htt1l["MET_4j_tmodgt0_floatworseres"] = (TH1F*)h->second->Clone("MET_4j_tmodgt0_floatworseres");
                else htt1l["MET_4j_tmodgt0_floatworseres"]->Add(h->second);
            }
        }
        
    }
    for(map<string,TH1F*>::iterator h=    htt1l.begin(); h!=    htt1l.end();++h) {
        TString temp = h->first;
        if(temp.Contains("res0")){
            htt1l[h->first]->SetLineColor(kGreen+1); htt1l[h->first]->SetMarkerColor(kGreen+1);     htt1l[h->first]->SetMarkerStyle(23); htt1l[h->first]->SetLineWidth(2);
        }
        if(temp.Contains("floatworseres")||temp.Contains("floatres")){
            htt1l[h->first]->SetLineColor(kMagenta+1); htt1l[h->first]->SetMarkerColor(kMagenta+1);     htt1l[h->first]->SetMarkerStyle(22); htt1l[h->first]->SetLineWidth(2);
        }
        htt1l[h->first]->Rebin(2);
        htt1l[h->first]->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
        htt1l[h->first]->GetXaxis()->SetLabelFont(42);
        htt1l[h->first]->GetXaxis()->SetLabelSize(0.04);
        htt1l[h->first]->GetXaxis()->SetTitleSize(0.05);
        htt1l[h->first]->GetXaxis()->SetTitleFont(42);
        htt1l[h->first]->GetXaxis()->SetNdivisions(505);
        htt1l[h->first]->GetYaxis()->SetTitle("events / 100 GeV");
        htt1l[h->first]->GetYaxis()->SetLabelFont(42);
        htt1l[h->first]->GetYaxis()->SetLabelSize(0.04);
        htt1l[h->first]->GetYaxis()->SetTitleSize(0.05);
        htt1l[h->first]->GetYaxis()->SetTitleOffset(1.2);
        htt1l[h->first]->GetYaxis()->SetTitleFont(42);
        htt1l[h->first]->GetZaxis()->SetLabelFont(42);
        htt1l[h->first]->GetZaxis()->SetLabelSize(0.035);
        htt1l[h->first]->GetZaxis()->SetTitleSize(0.035);
        htt1l[h->first]->GetZaxis()->SetTitleFont(42);
        //htt1l[h->first]->SetMaximum(2.5);   //Log y
        //htt1l[h->first]->SetMaximum(1.25);   //Linear y
        htt1l[h->first]->SetMaximum(2.5*htt1l[h->first]->GetMaximum());
        cout << h->first << endl;
    }
    TCanvas *c1 = new TCanvas("c1", "",334,192,600,600);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    //c1->SetLogy();    // Log y
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
     TLatex *tLumi = new TLatex(0.95,0.944,"36.8 fb^{-1} (13 TeV)");
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
    TLatex *tSim = new TLatex(0.295,0.944,"Simulation");
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
    TLegend *leg1 = new TLegend(0.39,0.777,0.725,0.89,NULL,"brNDC");
    leg1->SetBorderSize(0);
    leg1->SetTextSize(0.042);
    leg1->SetLineColor(1);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    leg1->AddEntry(htt1l["MET_4j_tmodgt0_res0"],"normal E_{T}^{miss} resolution", "lp");
    leg1->AddEntry(htt1l["MET_4j_tmodgt0_floatworseres"],"modified E_{T}^{miss} resolution", "lp");
    
    
    htt1l["MET_4j_tmodgt0_res0"]->Draw();
    htt1l["MET_4j_tmodgt0_floatworseres"]->Draw("same");
    //htt1l["MET_4j_tmodgt0_floatres"]->Draw("same");
    leg1->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tSim->Draw();
    TLatex *t4jh = new TLatex(0.48,0.7,"#geq4 jets, t_{mod} > 0");
    t4jh->SetNDC();
    t4jh->SetTextAlign(11);
    t4jh->SetTextFont(42);
    t4jh->SetTextSize(0.042);
    t4jh->SetLineWidth(2);
    t4jh->Draw();
    c1->SaveAs("MET_tt1l_4j_tmodgt0_resolution.eps");
    c1->Clear();
    
    htt1l["MET_4j_ltmod_lMlb_res0"]->Draw();
    htt1l["MET_4j_ltmod_lMlb_floatworseres"]->Draw("same");
    //htt1l["MET_4j_ltmod_lMlb_floatres"]->Draw("same");
    leg1->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tSim->Draw();
    TLatex *t4jll = new TLatex(0.48,0.68,"#splitline{#geq4 jets, t_{mod} #leq 0,}{M_{#font[12]{l}b} #leq 175 GeV}");
    t4jll->SetNDC();
    t4jll->SetTextAlign(11);
    t4jll->SetTextFont(42);
    t4jll->SetTextSize(0.042);
    t4jll->SetLineWidth(2);
    t4jll->Draw();
    TMathText *tmt = new TMathText();
    tmt->SetNDC();
    tmt->SetTextAlign(23);
    tmt->SetTextSize(0.025);
    tmt->SetTextColor(1);
    //tmt->DrawMathText(0.52,0.6625,"\\ell");
    c1->SaveAs("MET_tt1l_4j_ltmod_lMlb_resolution.eps");
    c1->Clear();
    
    htt1l["MET_4j_ltmod_hMlb_res0"]->Draw();
    htt1l["MET_4j_ltmod_hMlb_floatworseres"]->Draw("same");
    //htt1l["MET_4j_ltmod_hMlb_floatres"]->Draw("same");
    leg1->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tSim->Draw();
    TLatex *t4jlh = new TLatex(0.48,0.68,"#splitline{#geq4 jets, t_{mod} #leq 0,}{M_{#font[12]{l}b} > 175 GeV}");
    t4jlh->SetNDC();
    t4jlh->SetTextAlign(11);
    t4jlh->SetTextFont(42);
    t4jlh->SetTextSize(0.042);
    t4jlh->SetLineWidth(2);
    t4jlh->Draw();
    //tmt->DrawMathText(0.52,0.6625,"\\ell");
    c1->SaveAs("MET_tt1l_4j_ltmod_hMlb_resolution.eps");
    c1->Clear();
    
    htt1l["MET_5j_res0"]->SetMaximum(60);
    htt1l["MET_5j_res0"]->Draw();
    //htt1l["MET_5j_floatres"]->Draw("same");
    htt1l["MET_5j_floatworseres"]->Draw("same");
    leg1->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tSim->Draw();
    TLatex *t5j = new TLatex(0.48,0.7,"compressed signal region");
    t5j->SetNDC();
    t5j->SetTextAlign(11);
    t5j->SetTextFont(42);
    t5j->SetTextSize(0.042);
    t5j->SetLineWidth(2);
    t5j->Draw();
    c1->SaveAs("MET_tt1l_5j_resolution.eps");
    //c1->Clear();
*/

/*
    cout << __LINE__ << endl;
    map<string, TH1F*> hphsim;
    TFile *fphsim = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonMC.root");
    TKey *key;
    TIter iterphsim(fphsim->GetListOfKeys());
    while ((key = (TKey*)iterphsim())) {
        TH1F *h = (TH1F*)key->ReadObj();
        cout << h->GetName() << endl;
        hphsim[h->GetName()] = h;
    }
    cout << __LINE__ << endl;
    map<string, TH1F*> hphdata;
    TFile *fphdata = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonData.root");
    TIter iterphdata(fphdata->GetListOfKeys());
    while ((key = (TKey*)iterphdata())) {
        TH1F *h = (TH1F*)key->ReadObj();
        hphdata[h->GetName()] = h;
    }
    cout << __LINE__ << endl;
    //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
    TLatex *tLumi = new TLatex(0.95,0.944,"36.8 fb^{-1} (13 TeV)");
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
        TLatex *tSim = new TLatex(0.295,0.944,"Simulation");
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

    for(map<string,TH1F*>::iterator h=    hphsim.begin(); h!=    hphsim.end();++h) {
        TString temp = h->first;
        cout << temp << endl;
        if(temp.Contains("htmod")){
            hphsim[h->first]->SetLineColor(kGreen+1); hphsim[h->first]->SetMarkerColor(kGreen+1);     hphsim[h->first]->SetMarkerStyle(23); hphsim[h->first]->SetLineWidth(2);
        }
        if(temp.Contains("ltmod")||temp.Contains("5j")){
            hphsim[h->first]->SetLineColor(kMagenta+1); hphsim[h->first]->SetMarkerColor(kMagenta+1);     hphsim[h->first]->SetMarkerStyle(22); hphsim[h->first]->SetLineWidth(2);
        }
        if(temp.Contains("noweight")){
            hphsim[h->first]->SetLineColor(kBlue+1); hphsim[h->first]->SetMarkerColor(kBlue+1);     hphsim[h->first]->SetMarkerStyle(20); hphsim[h->first]->SetLineWidth(2);
        }
        hphsim[h->first]->Rebin(2);
        hphsim[h->first]->GetXaxis()->SetTitle("");
        //hphsim[h->first]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss} [GeV]");
        hphsim[h->first]->GetXaxis()->SetLabelFont(42);
        hphsim[h->first]->GetXaxis()->SetLabelSize(0.04);
        hphsim[h->first]->GetXaxis()->SetTitleSize(0.05);
        hphsim[h->first]->GetXaxis()->SetTitleFont(42);
        hphsim[h->first]->GetXaxis()->SetNdivisions(505);
        hphsim[h->first]->GetYaxis()->SetTitle("a.u. / 100 GeV");
        hphsim[h->first]->GetYaxis()->SetLabelFont(42);
        hphsim[h->first]->GetYaxis()->SetLabelSize(0.04);
        hphsim[h->first]->GetYaxis()->SetTitleSize(0.05);
        hphsim[h->first]->GetYaxis()->SetTitleOffset(1.2);
        hphsim[h->first]->GetYaxis()->SetTitleFont(42);
        hphsim[h->first]->Scale(1./hphsim[h->first]->Integral());
        //hphsim[h->first]->SetMaximum(2.5);   //Log y
        //hphsim[h->first]->SetMaximum(1.25);   //Linear y
        hphsim[h->first]->SetMaximum(3.5*hphsim[h->first]->GetMaximum());
    }
    TH1F *hrat1, *hrat2;
    
    TLegend *leg2 = new TLegend(0.475,0.725,0.725,0.9,NULL,"brNDC");
    leg2->SetBorderSize(0);
    leg2->SetTextSize(0.042);
    leg2->SetLineColor(1);
    leg2->SetLineStyle(1);
    leg2->SetLineWidth(2);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(1001);
    leg2->AddEntry(hphsim["PhotMET_5j_noweight_PhotonMC"],"unweighted", "lp");
    //leg2->AddEntry(hphsim["PhotMET_5j_2l_PhotonMC"],"reweighted", "lp");
    leg2->AddEntry(hphsim["PhotMET_23j_ltmod_2l_PhotonMC"],"reweighted, t_{mod} #leq 0", "lp");
    leg2->AddEntry(hphsim["PhotMET_23j_htmod_2l_PhotonMC"],"reweighted, t_{mod} > 0", "lp");
    
    TCanvas *c2 = new TCanvas("c2", "",334,192,600,700);
    c2->SetFillColor(0);
    c2->SetBorderMode(0);
    c2->SetBorderSize(2);
    //c2->SetLogy();    // Log y
    c2->SetTickx(1);
    c2->SetTicky(1);
    c2->SetLeftMargin(0.18);
    c2->SetRightMargin(0.05);
    c2->SetTopMargin(0.07);
    c2->SetBottomMargin(0.15);
    c2->SetFrameFillStyle(0);
    c2->SetFrameBorderMode(0);
    c2->SetFrameFillStyle(0);
    c2->SetFrameBorderMode(0);
    TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0.,0.18,1.,1);
    plotpad->Draw();
    plotpad->cd();
    plotpad->SetFillColor(0);
    plotpad->SetBorderMode(0);
    plotpad->SetBorderSize(2);
    plotpad->SetLogy();
    plotpad->SetTickx(1);
    plotpad->SetTicky(1);
    plotpad->SetLeftMargin(0.18);
    plotpad->SetRightMargin(0.05);
    plotpad->SetTopMargin(0.07);
    plotpad->SetBottomMargin(0.15);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    c2->cd();
    plotpad->cd();
    double max = TMath::Max(hphsim["PhotMET_5j_noweight_PhotonMC"]->GetMaximum(),hphsim["PhotMET_5j_2l_PhotonMC"]->GetMaximum());
    double min = TMath::Min(hphsim["PhotMET_5j_noweight_PhotonMC"]->GetMinimum(),hphsim["PhotMET_5j_2l_PhotonMC"]->GetMinimum());
    hphsim["PhotMET_5j_noweight_PhotonMC"]->SetMaximum(max);
    hphsim["PhotMET_5j_2l_PhotonMC"]->SetMaximum(max);
    hphsim["PhotMET_5j_noweight_PhotonMC"]->SetMinimum(min);
    hphsim["PhotMET_5j_2l_PhotonMC"]->SetMinimum(min);
    //double max = TMath::Max(TMath::Max(hphsim["PhotMET_23j_noweight_PhotonMC"]->GetMaximum(),hphsim["PhotMET_23j_ltmod_2l_PhotonMC"]->GetMaximum()),hphsim["PhotMET_23j_htmod_2l_PhotonMC"]->GetMaximum());
    //double min = TMath::Min(TMath::Min(hphsim["PhotMET_23j_noweight_PhotonMC"]->GetMinimum(),hphsim["PhotMET_23j_ltmod_2l_PhotonMC"]->GetMinimum()),hphsim["PhotMET_23j_htmod_2l_PhotonMC"]->GetMinimum());
    //hphsim["PhotMET_23j_noweight_PhotonMC"]->SetMaximum(max);
    //hphsim["PhotMET_23j_ltmod_2l_PhotonMC"]->SetMaximum(max);
    //hphsim["PhotMET_23j_htmod_2l_PhotonMC"]->SetMaximum(max);
    //hphsim["PhotMET_23j_noweight_PhotonMC"]->SetMinimum(min);
    //hphsim["PhotMET_23j_ltmod_2l_PhotonMC"]->SetMinimum(min);
    //hphsim["PhotMET_23j_htmod_2l_PhotonMC"]->SetMinimum(min);
 
    hphsim["PhotMET_5j_noweight_PhotonMC"]->Draw();
    hphsim["PhotMET_5j_2l_PhotonMC"]->Draw("same");
    //hphsim["PhotMET_4j_ltmod_2l_PhotonMC"]->Draw("same");
    //hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->Draw("same");
    leg2->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tSim->Draw();
    TLatex *tex = new TLatex(0.225,0.87125,"compressed");
    //TLatex *tex = new TLatex(0.225,0.87125,"#leq3 jets");
    tex->SetNDC();
    tex->SetTextAlign(11);
    tex->SetTextFont(42);
    tex->SetTextSize(0.042);
    tex->SetLineWidth(2);
    tex->Draw();
    c2->cd();
    TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.0,1.,0.26);
    ratiopad->Draw();
    ratiopad->cd();
    //ratiopad->SetLogy();
    //ratiopad->Range(71.42856,0.5346154,785.7143,1.303846);
    ratiopad->SetFillColor(0);
    ratiopad->SetBorderMode(0);
    ratiopad->SetBorderSize(2);
    ratiopad->SetTickx(1);
    ratiopad->SetTicky(1);
    ratiopad->SetLeftMargin(0.18);
    ratiopad->SetRightMargin(0.05);
    ratiopad->SetTopMargin(0.07);
    ratiopad->SetBottomMargin(0.28);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    hrat1 = (TH1F*)hphsim["PhotMET_5j_2l_PhotonMC"]->Clone("hrat1");
    //hrat1 = (TH1F*)hphsim["PhotMET_5j_ltmod_2l_PhotonMC"]->Clone("hrat1");
    //hrat2 = (TH1F*)hphsim["PhotMET_5j_htmod_2l_PhotonMC"]->Clone("hrat2");
    hrat1->Divide(hphsim["PhotMET_5j_noweight_PhotonMC"]);
    //hrat2->Divide(hphsim["PhotMET_5j_noweight_PhotonMC"]);
    hrat1->SetMinimum(0);
    hrat1->SetMaximum(2);
    hrat1->GetXaxis()->SetTitle("#left|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss}#right| [GeV]");
    hrat1->GetXaxis()->SetLabelFont(42);
    hrat1->GetXaxis()->SetLabelSize(0);
    hrat1->GetXaxis()->SetTitleSize(0.125);
    hrat1->GetXaxis()->SetTitleOffset(0.9);
    hrat1->GetXaxis()->SetTitleFont(42);
    hrat1->GetXaxis()->SetNdivisions(505);
    hrat1->GetYaxis()->SetTitle("wgt / ungwgt");
    hrat1->GetYaxis()->SetLabelFont(42);
    hrat1->GetYaxis()->SetLabelSize(0.125);
    hrat1->GetYaxis()->SetTitleSize(0.15);
    hrat1->GetYaxis()->SetTitleOffset(0.4);
    hrat1->GetYaxis()->SetTitleFont(42);
    hrat1->GetYaxis()->SetNdivisions(503);
    hrat1->Draw();
    hrat1->Draw("same");
    //hrat2->Draw("same");
    TLine *l1 = new TLine(250,1,750,1); l1->SetLineStyle(2); l1->SetLineColor(kGray+2);
    l1->Draw();
    c2->SaveAs("PhotMET_5j_PhotonMC_WgtVsUnwgt.eps");

    //plot 23j noweight vs ltmod vs htmod
    //plot 4j noweight vs ltmod vs htmod
    //plot 5j noweight vs ltmod vs htmod
*/
 


 map<string, TH1F*> hphsim;
 TFile *fphsim = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonMC.root");
 TKey *key;
 TIter iterphsim(fphsim->GetListOfKeys());
 while ((key = (TKey*)iterphsim())) {
 TH1F *h = (TH1F*)key->ReadObj();
 cout << h->GetName() << endl;
 hphsim[h->GetName()] = h;
 }
 cout << __LINE__ << endl;
 map<string, TH1F*> hphdata;
 TFile *fphdata = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonData.root");
 TIter iterphdata(fphdata->GetListOfKeys());
 while ((key = (TKey*)iterphdata())) {
 TH1F *h = (TH1F*)key->ReadObj();
 hphdata[h->GetName()] = h;
 }
 cout << __LINE__ << endl;
 //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
 TLatex *tLumi = new TLatex(0.95,0.944,"36.8 fb^{-1} (13 TeV)");
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
 TLatex *tSim = new TLatex(0.295,0.944,"Simulation");
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
 
 for(map<string,TH1F*>::iterator h=    hphsim.begin(); h!=    hphsim.end();++h) {
 TString temp = h->first;
 cout << temp << endl;
 hphsim[h->first]->SetLineColor(kGreen+1); hphsim[h->first]->SetMarkerColor(kGreen+1);     hphsim[h->first]->SetMarkerStyle(23); hphsim[h->first]->SetLineWidth(2);
 hphsim[h->first]->Rebin(2);
 hphsim[h->first]->GetXaxis()->SetTitle("");
 //hphsim[h->first]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss} [GeV]");
 hphsim[h->first]->GetXaxis()->SetLabelFont(42);
 hphsim[h->first]->GetXaxis()->SetLabelSize(0.04);
 hphsim[h->first]->GetXaxis()->SetTitleSize(0.05);
 hphsim[h->first]->GetXaxis()->SetTitleFont(42);
 hphsim[h->first]->GetXaxis()->SetNdivisions(505);
 hphsim[h->first]->GetYaxis()->SetTitle("a.u. / 100 GeV");
 hphsim[h->first]->GetYaxis()->SetLabelFont(42);
 hphsim[h->first]->GetYaxis()->SetLabelSize(0.04);
 hphsim[h->first]->GetYaxis()->SetTitleSize(0.05);
 hphsim[h->first]->GetYaxis()->SetTitleOffset(1.2);
 hphsim[h->first]->GetYaxis()->SetTitleFont(42);
 hphsim[h->first]->Scale(1./hphsim[h->first]->Integral());
 //hphsim[h->first]->SetMaximum(2.5);   //Log y
 //hphsim[h->first]->SetMaximum(1.25);   //Linear y
     hphsim[h->first]->SetMaximum(3.5*hphsim[h->first]->GetMaximum());
     hphsim[h->first]->SetMinimum(0.5*hphsim[h->first]->GetMinimum());
 }
    for(map<string,TH1F*>::iterator h=    hphdata.begin(); h!=    hphdata.end();++h) {
        TString temp = h->first;
        cout << temp << endl;
        hphdata[h->first]->SetLineColor(kBlack); hphdata[h->first]->SetMarkerColor(kBlack);     hphdata[h->first]->SetMarkerStyle(20); hphdata[h->first]->SetLineWidth(2);
        hphdata[h->first]->Rebin(2);
        hphdata[h->first]->GetXaxis()->SetTitle("");
        //hphdata[h->first]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss} [GeV]");
        hphdata[h->first]->GetXaxis()->SetLabelFont(42);
        hphdata[h->first]->GetXaxis()->SetLabelSize(0.04);
        hphdata[h->first]->GetXaxis()->SetTitleSize(0.05);
        hphdata[h->first]->GetXaxis()->SetTitleFont(42);
        hphdata[h->first]->GetXaxis()->SetNdivisions(505);
        hphdata[h->first]->GetYaxis()->SetTitle("a.u. / 100 GeV");
        hphdata[h->first]->GetYaxis()->SetLabelFont(42);
        hphdata[h->first]->GetYaxis()->SetLabelSize(0.04);
        hphdata[h->first]->GetYaxis()->SetTitleSize(0.05);
        hphdata[h->first]->GetYaxis()->SetTitleOffset(1.2);
        hphdata[h->first]->GetYaxis()->SetTitleFont(42);
        hphdata[h->first]->Scale(1./hphdata[h->first]->Integral());
        //hphdata[h->first]->SetMaximum(2.5);   //Log y
        //hphdata[h->first]->SetMaximum(1.25);   //Linear y
        hphdata[h->first]->SetMaximum(3.5*hphdata[h->first]->GetMaximum());
        hphdata[h->first]->SetMinimum(0.5*hphdata[h->first]->GetMinimum());
    }
 TH1F *hrat;
 
 TLegend *leg3 = new TLegend(0.475,0.725,0.725,0.9,NULL,"brNDC");
 leg3->SetBorderSize(0);
 leg3->SetTextSize(0.042);
 leg3->SetLineColor(1);
 leg3->SetLineStyle(1);
 leg3->SetLineWidth(2);
 leg3->SetFillColor(0);
 leg3->SetFillStyle(1001);
    leg3->AddEntry(hphdata["PhotMET_23j_2l_PhotonData"],"Data","ep");
    leg3->AddEntry(hphsim["PhotMET_23j_2l_PhotonMC"],"Simulation","lp");
    
    TCanvas *c3 = new TCanvas("c3", "",334,192,600,700);
    c3->SetFillColor(0);
    c3->SetBorderMode(0);
    c3->SetBorderSize(2);
    //c3->SetLogy();    // Log y
    c3->SetTickx(1);
    c3->SetTicky(1);
    c3->SetLeftMargin(0.18);
    c3->SetRightMargin(0.05);
    c3->SetTopMargin(0.07);
    c3->SetBottomMargin(0.15);
    c3->SetFrameFillStyle(0);
    c3->SetFrameBorderMode(0);
    c3->SetFrameFillStyle(0);
    c3->SetFrameBorderMode(0);
    TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0.,0.18,1.,1);
    plotpad->Draw();
    plotpad->cd();
    plotpad->SetFillColor(0);
    plotpad->SetBorderMode(0);
    plotpad->SetBorderSize(2);
    plotpad->SetLogy();
    plotpad->SetTickx(1);
    plotpad->SetTicky(1);
    plotpad->SetLeftMargin(0.18);
    plotpad->SetRightMargin(0.05);
    plotpad->SetTopMargin(0.07);
    plotpad->SetBottomMargin(0.15);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    c3->cd();
    plotpad->cd();
    double max = TMath::Max(hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->GetMaximum(),hphdata["PhotMET_4j_htmod_2l_PhotonData"]->GetMaximum());
    double min = TMath::Min(hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->GetMinimum(),hphdata["PhotMET_4j_htmod_2l_PhotonData"]->GetMinimum());
    hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->SetMaximum(max);
    hphdata["PhotMET_4j_htmod_2l_PhotonData"]->SetMaximum(max);
    hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->SetMinimum(min);
    hphdata["PhotMET_4j_htmod_2l_PhotonData"]->SetMinimum(min);
    hphdata["PhotMET_4j_htmod_2l_PhotonData"]->Draw("EX");
    hphsim["PhotMET_4j_htmod_2l_PhotonMC"]->Draw("same");
    //double max = TMath::Max(hphsim["PhotMET_5j_2l_PhotonMC"]->GetMaximum(),hphdata["PhotMET_5j_2l_PhotonData"]->GetMaximum());
    //double min = TMath::Min(hphsim["PhotMET_5j_2l_PhotonMC"]->GetMinimum(),hphdata["PhotMET_5j_2l_PhotonData"]->GetMinimum());
    //hphsim["PhotMET_5j_2l_PhotonMC"]->SetMaximum(max);
    //hphdata["PhotMET_5j_2l_PhotonData"]->SetMaximum(max);
    //hphsim["PhotMET_5j_2l_PhotonMC"]->SetMinimum(min);
    //hphdata["PhotMET_5j_2l_PhotonData"]->SetMinimum(min);
    //hphdata["PhotMET_5j_2l_PhotonData"]->Draw("EX");
    //hphsim["PhotMET_5j_2l_PhotonMC"]->Draw("same");
    leg3->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tPrel->Draw();
    TLatex *tex = new TLatex(0.225,0.87125,"#geq4 jets, t_{mod} > 0");
    //TLatex *tex = new TLatex(0.225,0.87125,"compressed");
    tex->SetNDC();
    tex->SetTextAlign(11);
    tex->SetTextFont(42);
    tex->SetTextSize(0.042);
    tex->SetLineWidth(2);
    tex->Draw();
    c3->cd();
    TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.0,1.,0.26);
    ratiopad->Draw();
    ratiopad->cd();
    //ratiopad->SetLogy();
    //ratiopad->Range(71.42856,0.5346154,785.7143,1.303846);
    ratiopad->SetFillColor(0);
    ratiopad->SetBorderMode(0);
    ratiopad->SetBorderSize(2);
    ratiopad->SetTickx(1);
    ratiopad->SetTicky(1);
    ratiopad->SetLeftMargin(0.18);
    ratiopad->SetRightMargin(0.05);
    ratiopad->SetTopMargin(0.07);
    ratiopad->SetBottomMargin(0.28);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    hrat = (TH1F*)hphdata["PhotMET_4j_htmod_2l_PhotonData"]->Clone("hrat1");
    hrat->Divide(hphsim["PhotMET_4j_htmod_2l_PhotonMC"]);
    //hrat = (TH1F*)hphdata["PhotMET_5j_2l_PhotonData"]->Clone("hrat1");
    //hrat->Divide(hphsim["PhotMET_5j_2l_PhotonMC"]);    hrat->SetMinimum(0);
    hrat->SetMaximum(2);
    hrat->GetXaxis()->SetTitle("#left|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss}#right| [GeV]");
    hrat->GetXaxis()->SetLabelFont(42);
    hrat->GetXaxis()->SetLabelSize(0);
    hrat->GetXaxis()->SetTitleSize(0.125);
    hrat->GetXaxis()->SetTitleOffset(0.9);
    hrat->GetXaxis()->SetTitleFont(42);
    hrat->GetXaxis()->SetNdivisions(505);
    hrat->GetYaxis()->SetTitle("Data / sim.");
    hrat->GetYaxis()->SetLabelFont(42);
    hrat->GetYaxis()->SetLabelSize(0.125);
    hrat->GetYaxis()->SetTitleSize(0.15);
    hrat->GetYaxis()->SetTitleOffset(0.4);
    hrat->GetYaxis()->SetTitleFont(42);
    hrat->GetYaxis()->SetNdivisions(503);
    hrat->Draw();
    hrat->Draw("sameEX0");
    //hrat2->Draw("same");
    TLine *l1 = new TLine(250,1,750,1); l1->SetLineStyle(2); l1->SetLineColor(kGray+2);
    l1->Draw();
    c3->SaveAs("PhotMET_4j_ltmod_DataVsSim.eps");
    //c3->SaveAs("PhotMET_5j_DataVsSim.eps");
    
    //plot 23j htmod data vs sim    23j_htmod
    //plot 4j ltmod data vs sim     4j_ltmod
    //plot 4j htmod data vs sim     4j_htmod
    //plot 5j data vs sim:          5j
 
   /*
    //PAS figure
    map<string, TH1F*> hphsim;
    TFile *fphsim = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonMC.root");
    TKey *key;
    TIter iterphsim(fphsim->GetListOfKeys());
    while ((key = (TKey*)iterphsim())) {
        TH1F *h = (TH1F*)key->ReadObj();
        cout << h->GetName() << endl;
        hphsim[h->GetName()] = h;
    }
    cout << __LINE__ << endl;
    map<string, TH1F*> hphdata;
    TFile *fphdata = TFile::Open("PhotMETDistribution2ndTry_NuorNuNuPtweighted_PhotonData.root");
    TIter iterphdata(fphdata->GetListOfKeys());
    while ((key = (TKey*)iterphdata())) {
        TH1F *h = (TH1F*)key->ReadObj();
        hphdata[h->GetName()] = h;
    }
    cout << __LINE__ << endl;
    //TLatex *tLumi = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
    TLatex *tLumi = new TLatex(0.95,0.944,"36.8 fb^{-1} (13 TeV)");
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
    TLatex *tSim = new TLatex(0.295,0.944,"Simulation");
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
    TH1F *hSim, *hData;
    bool first = true;
    
    for(map<string,TH1F*>::iterator h=    hphsim.begin(); h!=    hphsim.end();++h) {
        TString temp = h->first;
        cout << temp << endl;
        hphsim[h->first]->SetLineColor(kGreen+1); hphsim[h->first]->SetMarkerColor(kGreen+1);     hphsim[h->first]->SetMarkerStyle(23); hphsim[h->first]->SetLineWidth(2);
        hphsim[h->first]->Rebin(2);
        hphsim[h->first]->GetXaxis()->SetTitle("");
        //hphsim[h->first]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss} [GeV]");
        hphsim[h->first]->GetXaxis()->SetLabelFont(42);
        hphsim[h->first]->GetXaxis()->SetLabelSize(0.04);
        hphsim[h->first]->GetXaxis()->SetTitleSize(0.05);
        hphsim[h->first]->GetXaxis()->SetTitleFont(42);
        hphsim[h->first]->GetXaxis()->SetNdivisions(505);
        hphsim[h->first]->GetYaxis()->SetTitle("a.u. / 100 GeV");
        hphsim[h->first]->GetYaxis()->SetLabelFont(42);
        hphsim[h->first]->GetYaxis()->SetLabelSize(0.04);
        hphsim[h->first]->GetYaxis()->SetTitleSize(0.05);
        hphsim[h->first]->GetYaxis()->SetTitleOffset(1.2);
        hphsim[h->first]->GetYaxis()->SetTitleFont(42);
        if(h->first.find(string("_1ltop_"))!=string::npos&&h->first.find(string("_5j_"))==string::npos){
            if(!first){
                hSim->Add(hphsim[h->first]);
            }
            else if(first){
                cout << "clone " << temp << endl;
                hSim = (TH1F*)hphsim[h->first]->Clone("hSim");
                first = false;
            }
        }
        hphsim[h->first]->Scale(1./hphsim[h->first]->Integral());
        //hphsim[h->first]->SetMaximum(2.5);   //Log y
        //hphsim[h->first]->SetMaximum(1.25);   //Linear y
        hphsim[h->first]->SetMaximum(3.5*hphsim[h->first]->GetMaximum());
        hphsim[h->first]->SetMinimum(0.5*hphsim[h->first]->GetMinimum());
    }
    first = true;
    for(map<string,TH1F*>::iterator h=    hphdata.begin(); h!=    hphdata.end();++h) {
        TString temp = h->first;
        cout << temp << endl;
        hphdata[h->first]->SetLineColor(kBlack); hphdata[h->first]->SetMarkerColor(kBlack);     hphdata[h->first]->SetMarkerStyle(20); hphdata[h->first]->SetLineWidth(2);
        hphdata[h->first]->Rebin(2);
        hphdata[h->first]->GetXaxis()->SetTitle("");
        //hphdata[h->first]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss} [GeV]");
        hphdata[h->first]->GetXaxis()->SetLabelFont(42);
        hphdata[h->first]->GetXaxis()->SetLabelSize(0.04);
        hphdata[h->first]->GetXaxis()->SetTitleSize(0.05);
        hphdata[h->first]->GetXaxis()->SetTitleFont(42);
        hphdata[h->first]->GetXaxis()->SetNdivisions(505);
        hphdata[h->first]->GetYaxis()->SetTitle("a.u. / 100 GeV");
        hphdata[h->first]->GetYaxis()->SetLabelFont(42);
        hphdata[h->first]->GetYaxis()->SetLabelSize(0.04);
        hphdata[h->first]->GetYaxis()->SetTitleSize(0.05);
        hphdata[h->first]->GetYaxis()->SetTitleOffset(1.2);
        hphdata[h->first]->GetYaxis()->SetTitleFont(42);
        if(h->first.find(string("_1ltop_"))!=string::npos&&h->first.find(string("_5j_"))==string::npos){
            if(!first){
                hData->Add(hphdata[h->first]);
            }
            else if(first){
                cout << "clone " << temp << endl;
                hData = (TH1F*)hphdata[h->first]->Clone("hSim");
                first = false;
            }
        }
        hphdata[h->first]->Scale(1./hphdata[h->first]->Integral());
        //hphdata[h->first]->SetMaximum(2.5);   //Log y
        //hphdata[h->first]->SetMaximum(1.25);   //Linear y
        hphdata[h->first]->SetMaximum(3.5*hphdata[h->first]->GetMaximum());
        hphdata[h->first]->SetMinimum(0.5*hphdata[h->first]->GetMinimum());
    }
    cout << __LINE__ << endl;
    hSim->Scale(1./hSim->Integral());
    hSim->SetMaximum(3.5*hSim->GetMaximum());
    hSim->SetMinimum(3.5*hSim->GetMinimum());
    hData->Scale(1./hData->Integral());
    hData->SetMaximum(3.5*hData->GetMaximum());
    hData->SetMinimum(3.5*hData->GetMinimum());
    TH1F *hrat;
    
    TLegend *leg3 = new TLegend(0.475,0.775,0.725,0.9,NULL,"brNDC");
    leg3->SetBorderSize(0);
    leg3->SetTextSize(0.042);
    leg3->SetLineColor(1);
    leg3->SetLineStyle(1);
    leg3->SetLineWidth(2);
    leg3->SetFillColor(0);
    leg3->SetFillStyle(1001);
    leg3->AddEntry(hphdata["PhotMET_23j_2l_PhotonData"],"Data","ep");
    leg3->AddEntry(hphsim["PhotMET_23j_2l_PhotonMC"],"Simulation","lp");
    cout << __LINE__ << endl;
    
    TCanvas *c3 = new TCanvas("c3", "",334,192,600,700);
    c3->SetFillColor(0);
    c3->SetBorderMode(0);
    c3->SetBorderSize(2);
    //c3->SetLogy();    // Log y
    c3->SetTickx(1);
    c3->SetTicky(1);
    c3->SetLeftMargin(0.18);
    c3->SetRightMargin(0.05);
    c3->SetTopMargin(0.07);
    c3->SetBottomMargin(0.15);
    c3->SetFrameFillStyle(0);
    c3->SetFrameBorderMode(0);
    c3->SetFrameFillStyle(0);
    c3->SetFrameBorderMode(0);
    TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0.,0.18,1.,1);
    plotpad->Draw();
    plotpad->cd();
    plotpad->SetFillColor(0);
    plotpad->SetBorderMode(0);
    plotpad->SetBorderSize(2);
    plotpad->SetLogy();
    plotpad->SetTickx(1);
    plotpad->SetTicky(1);
    plotpad->SetLeftMargin(0.18);
    plotpad->SetRightMargin(0.05);
    plotpad->SetTopMargin(0.07);
    plotpad->SetBottomMargin(0.15);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    plotpad->SetFrameFillStyle(0);
    plotpad->SetFrameBorderMode(0);
    c3->cd();
    plotpad->cd();
    cout << __LINE__ << endl;
    double max = TMath::Max(hSim->GetMaximum(),hData->GetMaximum());
    double min = TMath::Min(hSim->GetMinimum(),hData->GetMinimum());
    min = 0.003;
    cout << __LINE__ << endl;
    hSim->SetMaximum(max);
    hData->SetMaximum(max);
    hSim->SetMinimum(min);
    hData->SetMinimum(min);
    hData->Draw("EX");
    hSim->Draw("same");
    //hphsim["PhotMET_23j_ltmod_2l_PhotonMC"]->Draw("same");
    //hphsim["PhotMET_23j_htmod_2l_PhotonMC"]->Draw("same");
    leg3->Draw();
    tLumi->Draw();
    tCMS->Draw();
    tPrel->Draw();
    TLatex *tex = new TLatex(0.5,0.715,"#geq2 jets, 0 b-jets");
    tex->SetNDC();
    tex->SetTextAlign(11);
    tex->SetTextFont(42);
    tex->SetTextSize(0.042);
    tex->SetLineWidth(2);
    tex->Draw();
    TLatex *tex2 = new TLatex(0.5,0.655,"#gamma-p_{T} spectrum reweighted");
    tex2->SetNDC();
    tex2->SetTextAlign(11);
    tex2->SetTextFont(42);
    tex2->SetTextSize(0.042);
    tex2->SetLineWidth(2);
    tex2->Draw();
    TLatex *tex3 = new TLatex(0.5,0.605,"to #nu-p_{T} spectrum of t#bar{t}#rightarrow1#font[12]{l}");
    tex3->SetNDC();
    tex3->SetTextAlign(11);
    tex3->SetTextFont(42);
    tex3->SetTextSize(0.042);
    tex3->SetLineWidth(2);
    tex3->Draw();
    //TMathText *mt = new TMathText();
    //mt->SetNDC();
    //mt->SetTextAlign(11);
    //mt->SetTextSize(0.042);
    //mt->SetTextColor(1);
    //mt->DrawMathText(0.90,0.605,"\\ell");
    c3->cd();
    TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.0,1.,0.26);
    ratiopad->Draw();
    ratiopad->cd();
    //ratiopad->SetLogy();
    //ratiopad->Range(71.42856,0.5346154,785.7143,1.303846);
    ratiopad->SetFillColor(0);
    ratiopad->SetBorderMode(0);
    ratiopad->SetBorderSize(2);
    ratiopad->SetTickx(1);
    ratiopad->SetTicky(1);
    ratiopad->SetLeftMargin(0.18);
    ratiopad->SetRightMargin(0.05);
    ratiopad->SetTopMargin(0.07);
    ratiopad->SetBottomMargin(0.28);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    ratiopad->SetFrameFillStyle(0);
    ratiopad->SetFrameBorderMode(0);
    hrat = (TH1F*)hData->Clone("hrat1");
    hrat->Divide(hSim);
    hrat->SetMinimum(0.5);
    hrat->SetMaximum(1.5);
    hrat->GetXaxis()->SetTitle("#left|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss}#right| [GeV]");
    hrat->GetXaxis()->SetLabelFont(42);
    hrat->GetXaxis()->SetLabelSize(0);
    hrat->GetXaxis()->SetTitleSize(0.125);
    hrat->GetXaxis()->SetTitleOffset(0.8);
    hrat->GetXaxis()->SetTitleFont(42);
    hrat->GetXaxis()->SetNdivisions(505);
    hrat->GetYaxis()->SetTitle("Data / sim.");
    hrat->GetYaxis()->SetLabelFont(42);
    hrat->GetYaxis()->SetLabelSize(0.125);
    hrat->GetYaxis()->SetTitleSize(0.15);
    hrat->GetYaxis()->SetTitleOffset(0.4);
    hrat->GetYaxis()->SetTitleFont(42);
    hrat->GetYaxis()->SetNdivisions(503);
    hrat->Draw();
    hrat->Draw("sameEX0");
    //hrat2->Draw("same");
    TLine *l1 = new TLine(250,1,750,1); l1->SetLineStyle(2); l1->SetLineColor(kGray+2);
    l1->Draw();
    c3->SaveAs("PhotMET_ge2j_DataVsSim.eps");
*/
    


}