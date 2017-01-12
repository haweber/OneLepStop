

// C++
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TString.h"
#include "TCanvas.h"
#include "TPad.h"


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

void CompareShapes(){
    
    bool logy = true;
    
    string lepsel = "1l";
    //string lepsel = "2l";
    
    string metric = "NPUV";
    //string metric = "NPUInt";
    //string metric = "NPV";
    

    map<string, TH1D*> hist;
    map<string, TH1D*> histRat;
    map<string, TH1D*> histSum;
    vector<string> histonames; histonames.clear();
    
    const int pssize = 6;
    string prestring[pssize] = {"PreselMT120MET150","PreselMT120","Preselection","MET300","chi210","MT2W200"};
    
    //const int ssize = 8;
    //string samplestring[ssize] = {"normalTTbar_25ns_2l", "normalTTbar_25ns_1l", "normalTTbar_50ns_2l", "normalTTbar_50ns_1l", "puppiTTbar_25ns_2l", "puppiTTbar_25ns_1l", "puppiTTbar_50ns_2l", "puppiTTbar_50ns_1l"};
    
    const int ssize = 4;
    string samplestring[ssize] = {"normalTTbar_25ns", "normalTTbar_50ns", "puppiTTbar_25ns", "puppiTTbar_50ns"};
    Color_t color[ssize] = {kBlue+1, kRed+1, kGreen+1, kMagenta+1};
    int style[ssize] = {22, 21, 20, 23};
    
    const int PUbinsize = 5;
    string PUbin[PUbinsize] = {"0to10","11to15","16to20","21to25","25toInf"};
    
    //const int Pjsize = 2;
    //string projstring[Pjsize] = {"ProjVar", "ProjPU"};
    
    histonames.push_back("DeltaPhiWl");               
    histonames.push_back("MT");                       
    histonames.push_back("MET");                      
    histonames.push_back("chi2");                     
    histonames.push_back("MT2W");                     
    histonames.push_back("MT2_lb_b");                 
    histonames.push_back("MT2_lb_bqq");               
    histonames.push_back("MT2_lb_b_mless");           
    histonames.push_back("MT2_lb_bqq_mless");         
    histonames.push_back("MTq_max");                  
    histonames.push_back("MTq_leadj300");             
    histonames.push_back("METsqrtHT");                
    //RM = MET/ptLeadJet
    histonames.push_back("RM300");                    
    //histonames.push_back("MT2_l_q");
    //histonames.push_back("MT2_l_qq");
    //histonames.push_back("MT2_l_qq_mless");
    histonames.push_back("Topness");                  
    histonames.push_back("TopnessMod");
    
    histonames.push_back("NJets");                     
    histonames.push_back("NBJets");                    
    histonames.push_back("LepMiniIso");                
    histonames.push_back("LepPt");                     
    histonames.push_back("LepEta");                    
    histonames.push_back("J1Pt");                      
    histonames.push_back("J2Pt");                      
    histonames.push_back("J3Pt");                      
    histonames.push_back("J4Pt");                      
    histonames.push_back("B1Pt");                      
    histonames.push_back("JPt");                       
    histonames.push_back("BPt");                       
    histonames.push_back("JEta");                      
    histonames.push_back("BEta");

    TLegend *leg = new TLegend(0.7097315,0.6993844,0.909396,0.9005316,NULL,"brNDC");
    leg->SetBorderSize(0);
    leg->SetTextFont(62);
    leg->SetTextSize(0.04181185);
    leg->SetTextFont(42);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(1001);
    for(unsigned int b = 0; b<ssize; ++b){
        string fname = "PUbinHistos_" + samplestring[b] /*+ "_" + lepsel*/ + ".root";
        TFile *f = TFile::Open(fname.c_str());
        f->cd();
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    string newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring[b] + "_" + lepsel;
                    if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)f->Get(newname.c_str());
                    string tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[b] + "_" + lepsel;
                    if(a==0){
                        histSum[tmp] = (TH1D*)hist[newname]->Clone(tmp.c_str());
                        histSum[tmp]->SetMarkerColor(color[b]); histSum[tmp]->SetLineColor(color[b]); histSum[tmp]->SetMarkerStyle(style[b]);
                        if(i==0&&c==0) leg->AddEntry(histSum[tmp],samplestring[b].c_str(),"lp");
                    } else{
                        histSum[tmp]->Add(hist[newname]);
                    }
                }
                string tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[b] + "_" + lepsel;
                string tmpRat = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[b] + "_" + lepsel + "_Rat";
                string tmp0 = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[0] + "_" + lepsel;
                histRat[tmp] = (TH1D*)histSum[tmp]->Clone(tmpRat.c_str());
                histRat[tmp]->Scale(1./histRat[tmp]->Integral());
                //histRat[tmp]->Divide(histRat[tmp0]);
            }
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
    //if(logy) c1->SetLogy(1);
    
    c1->cd();

    
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                //if(i!=0||c!=0) continue;
                TH1D *haxis;
                TH1D *haxisRat;
                c1->cd();
                c1->Clear();
                string tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[0] + "_" + lepsel;
                haxis = (TH1D*)histSum[tmp]->Clone("haxis");
                haxis->GetYaxis()->SetTitle("a.u.");
                haxis->GetXaxis()->SetTitle(histonames[i].c_str());
                haxis->SetMinimum(0);
                haxis->SetMaximum(1.2);
                haxis->GetYaxis()->SetRangeUser(0.,1.2);
                haxis->GetXaxis()->SetLabelFont(42);
                haxis->GetXaxis()->SetLabelOffset(0.007);
                haxis->GetXaxis()->SetLabelSize(0.05);
                haxis->GetXaxis()->SetTitleSize(0.06);
                haxis->GetXaxis()->SetTitleOffset(0.9);
                haxis->GetXaxis()->SetTitleFont(42);
                haxis->GetYaxis()->SetTitle("a.u.");
                haxis->GetYaxis()->SetLabelFont(42);
                haxis->GetYaxis()->SetLabelOffset(0.007);
                haxis->GetYaxis()->SetLabelSize(0.05);
                haxis->GetYaxis()->SetTitleSize(0.06);
                haxis->GetYaxis()->SetTitleOffset(1.25);
                haxis->GetYaxis()->SetTitleFont(42);
                if(logy){
                    haxis->SetMinimum(0.001);
                    haxis->SetMaximum(2.);
                    haxis->GetYaxis()->SetRangeUser(0.001,2.);
                }
                TPad *uppad = new TPad("uppad", "Pad containing the overlay plot",0,0.211838,1,1);
                uppad->Draw();
                uppad->cd();
                uppad->Range(71.42856,-0.09615385,785.7143,0.5448718);
                uppad->SetFillColor(0);
                uppad->SetBorderMode(0);
                uppad->SetBorderSize(2);
                uppad->SetTickx(1);
                uppad->SetTicky(1);
                uppad->SetLeftMargin(0.18);
                uppad->SetRightMargin(0.05);
                uppad->SetTopMargin(0.07);
                uppad->SetBottomMargin(0.15);
                uppad->SetFrameFillStyle(0);
                uppad->SetFrameBorderMode(0);
                uppad->SetFrameFillStyle(0);
                uppad->SetFrameBorderMode(0);
                if(logy) uppad->SetLogy(1);
                haxis->Draw("axis");
                leg->Draw("same");
                for(unsigned int b = 0; b<ssize; ++b){
                    string temp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[b] + "_"+lepsel;
                    histSum[temp]->DrawNormalized("sameE");
                }
                //string tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[0] + "_" + lepsel;
                haxisRat = (TH1D*)histRat[tmp]->Clone("haxisRat");
                haxisRat->GetYaxis()->SetTitle("ratio to total");
                //    haxisRat->GetXaxis()->SetTitle(histonames[i]);
                haxisRat->GetXaxis()->SetLabelFont(42);
                haxisRat->GetXaxis()->SetLabelSize(0);
                haxisRat->GetXaxis()->SetTitleSize(0.18);
                haxisRat->GetXaxis()->SetTickLength(0.09);
                haxisRat->GetXaxis()->SetTitleOffset(0.6);
                haxisRat->GetXaxis()->SetTitleFont(42);
                haxisRat->GetYaxis()->SetNdivisions(2);
                haxisRat->GetYaxis()->SetLabelFont(42);
                haxisRat->GetYaxis()->SetLabelSize(0.16);
                haxisRat->GetYaxis()->SetTitleSize(0.18);
                haxisRat->GetYaxis()->SetTitleOffset(0.43);
                haxisRat->GetYaxis()->SetTitleFont(42);
                haxisRat->SetMinimum(0);
                haxisRat->SetMaximum(2.0);
                haxisRat->GetYaxis()->SetRangeUser(0.,2.0);
                c1->cd();
                TPad *downpad = new TPad("downpad", "Pad containing the ratio",0,0,1,0.2089441);
                downpad->Draw();
                downpad->cd();
                //downpad->Range(71.42856,0.5346154,785.7143,1.303846);
                downpad->SetFillColor(0);
                downpad->SetBorderMode(0);
                downpad->SetBorderSize(2);
                downpad->SetTickx(1);
                downpad->SetTicky(1);
                downpad->SetLeftMargin(0.18);
                downpad->SetRightMargin(0.05);
                downpad->SetTopMargin(0.07);
                downpad->SetBottomMargin(0.28);
                downpad->SetFrameFillStyle(0);
                downpad->SetFrameBorderMode(0);
                downpad->SetFrameFillStyle(0);
                downpad->SetFrameBorderMode(0);
                haxisRat->Draw("axis");
                //string temp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring;
                string temp0 = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[0] + "_"+lepsel;
                TH1D *clone = (TH1D*)histRat[temp0]->Clone("DividingClone");
                for(unsigned int b = 0; b<ssize; ++b){
                    string temp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring[b] + "_"+lepsel;
                    histRat[temp]->Divide(clone);
                    histRat[temp]->Draw("sameE");
                }
                c1->cd();
                TString outputdir = "../../plots/PUstudies/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + "compareSamples" + "/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + prestring[c] + "/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + lepsel + "/";
                MakeOutputDir(outputdir);
                TString outputfilename = outputdir + "/" +histonames[i] +".pdf";
                c1->SaveAs(outputfilename.Data());
                c1->Clear();
                //delete uppad;
                //delete downpad;
            }
        }
    
}