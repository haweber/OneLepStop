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
#include "TDirectory.h"
#include "TF1.h"
#include "TLatex.h"
#include <sstream>
#include <fstream>

using namespace std;

void makePlotL1Trigger(){
    
   
  string outputdir = "../plots/first_20150727/SingleMuon/L1checks/";
  string  inputdir = "/Users/haweber/sshclientfiles/";
  

    vector<string> histonames1;
    vector<string> histonames2;
    histonames1.push_back("h_pt_l1");
    histonames1.push_back("h_pt_reco");
    histonames1.push_back("h_eta_l1");
    histonames1.push_back("h_eta_reco");
    histonames1.push_back("h_eta_l1_fine");
    histonames1.push_back("h_eta_reco_fine");
    histonames1.push_back("h_phi_l1");
    histonames1.push_back("h_phi_reco");
    histonames1.push_back("h_dR_l1reco");
    histonames1.push_back("h_deta_l1reco");
    histonames1.push_back("h_dphi_l1reco");
    histonames1.push_back("h_goodptphi_deta_l1reco");
    histonames1.push_back("h_verygoodptphi_deta_l1reco");
    histonames1.push_back("h_dR_l1reco_etarestrict");
    histonames1.push_back("h_deta_l1reco_etarestrict");
    histonames1.push_back("h_goodptphi_deta_l1reco_etarestrict");
    histonames1.push_back("h_verygoodptphi_deta_l1reco_etarestrict");

    histonames2.push_back("h_l1pt_recopt");
    histonames2.push_back("h_l1eta_recoeta");
    histonames2.push_back("h_l1phi_recophi");
    histonames2.push_back("h_goodptphi_l1eta_recoeta");
    histonames2.push_back("h_verygoodptphi_l1eta_recoeta");
    histonames2.push_back("h_deta_dphi_l1reco");
    histonames2.push_back("h_deta_dphi_accept");
    histonames2.push_back("h_deta_dphi_accept_etarestrict");
    histonames2.push_back("h_l1pt_recopt_etarestrict");
    histonames2.push_back("h_l1eta_recoeta_etarestrict");
    histonames2.push_back("h_l1phi_recophi_etarestrict");
    histonames2.push_back("h_goodptphi_l1eta_recoeta_etarestrict");
    histonames2.push_back("h_verygoodptphi_l1eta_recoeta_etarestrict");
    histonames2.push_back("h_deta_dphi_l1reco_etarestrict");

    TString fdataname = (inputdir+"histos_testANDtest2.root");
    TFile *fdata = TFile::Open(fdataname.Data());

    TDirectory *dir = (TDirectory*)fdata->Get("singleMuTrigAnalyzerL1RECO");
    dir->cd();

    TCanvas *c1 = new TCanvas("c1", "",477,41,750,500);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
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
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    for(unsigned int i = 0; i<histonames1.size();++i){
        TH1F *h = (TH1F*)dir->Get(histonames1[i].c_str());
        c1->Clear();
        c1->cd();
        h->GetYaxis()->SetTitle("N_{unmatched probes}(IsoTk20)");
        h->Draw("");
        c1->Update();
        string outname = outputdir + histonames1[i] + ".pdf";
        c1->SaveAs(outname.c_str());
        c1->Clear();
        c1->cd();
    }
    TCanvas *c2 = new TCanvas("c2", "c2",247,22,600,600);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    //c2->Range(-350.6494,-288.4615,1597.403,1634.615);
    c2->SetFillColor(0);
    c2->SetBorderMode(0);
    c2->SetBorderSize(2);
    //c2->SetLogz();
    c2->SetTickx(1);
    c2->SetTicky(1);
    c2->SetLeftMargin(0.14);
    c2->SetRightMargin(0.19);
    c2->SetTopMargin(0.08);
    c2->SetBottomMargin(0.14);
    c2->SetFrameBorderMode(0);
    c2->SetFrameFillStyle(0);
    c2->SetFrameBorderMode(0);
    c2->SetFrameFillStyle(0);
    c2->SetFrameBorderMode(0);
    TLine *l = new TLine();
    l->SetLineStyle(2); l->SetLineColor(kGray);
    for(unsigned int i = 0; i<histonames2.size();++i){
        TH2F *h = (TH2F*)dir->Get(histonames2[i].c_str());
        c2->Clear();
        c2->cd();
        float xlow =h->GetXaxis()->GetBinLowEdge(1);
        float xup =h->GetXaxis()->GetBinUpEdge(h->GetXaxis()->GetNbins());
        float ylow =h->GetYaxis()->GetBinLowEdge(1);
        float yup =h->GetYaxis()->GetBinUpEdge(h->GetYaxis()->GetNbins());
        if(histonames2[i]=="h_deta_dphi_l1reco_etarestrict"||histonames2[i]=="h_deta_dphi_l1reco"){
            h->GetXaxis()->SetRangeUser(-0.5,0.5);
            h->GetYaxis()->SetRangeUser(-0.25,0.25);
            xlow = -0.5; xup = 0.5; ylow = -0.25; yup = 0.25;
        }
        if(histonames2[i]=="h_goodptphi_l1eta_recoeta_etarestrict"||histonames2[i]=="h_goodptphi_l1eta_recoeta"||histonames2[i]=="h_l1eta_recoeta_etarestrict"||histonames2[i]=="h_l1eta_recoeta"||histonames2[i]=="h_verygoodptphi_l1eta_recoeta_etarestrict"||histonames2[i]=="h_verygoodptphi_l1eta_recoeta"){
            h->GetXaxis()->SetRangeUser(-1,0.5);
            h->GetYaxis()->SetRangeUser(-1,0.5);
            xlow = -1; xup = 0.5; ylow = -1; yup = 0.5;
        }
        h->Draw("COLZ");
        h->SetMarkerSize(2);
        if(histonames2[i]=="h_deta_dphi_accept"||histonames2[i]=="h_deta_dphi_accept_etarestrict") {
            h->SetNdivisions(102,"X");
            h->SetNdivisions(102,"Y");
            h->Draw("COLZtext");
        }
        if(histonames2[i]=="h_goodptphi_l1eta_recoeta_etarestrict"||histonames2[i]=="h_goodptphi_l1eta_recoeta"||histonames2[i]=="h_l1eta_recoeta_etarestrict"||histonames2[i]=="h_l1eta_recoeta"||histonames2[i]=="h_verygoodptphi_l1eta_recoeta_etarestrict"||histonames2[i]=="h_verygoodptphi_l1eta_recoeta"||histonames2[i]=="h_l1pt_recopt"||histonames2[i]=="h_l1pt_recopt_etarestrict"||histonames2[i]=="h_l1phi_recophi"||histonames2[i]=="h_l1phi_recophi_etarestrict"){
            l->DrawLine(xlow,ylow,xup,yup);
        }
        c2->Update();
        string outname = outputdir + histonames2[i] + ".pdf";
        c2->SaveAs(outname.c_str());
        c2->Clear();
        c2->cd();
    }
}
