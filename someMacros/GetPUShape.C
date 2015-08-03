

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

void GetPUShape(){
    
    bool logy = true;
    
    //string mysample = "normalTTbar_25ns";
    //string mysample = "normalTTbar_50ns";
    //string mysample = "puppiTTbar_25ns";
    string mysample = "puppiTTbar_50ns";
    
    //string metric = "NPUV";
    //string metric = "NPUInt";
    string metric = "NPV";
    

    map<string, TH1D*> hist;
    map<string, TH1D*> histRat;
    map<string, TH1D*> histSum;
    //map<string, TProfile*> histPj;
    vector<string> histonames; histonames.clear();
    
    const int pssize = 6;
    string prestring[pssize] = {"PreselMT120MET150","PreselMT120","Preselection","MET300","chi210","MT2W200"};
    
    //const int ssize = 8;
    //string samplestring[ssize] = {"normalTTbar_25ns_2l", "normalTTbar_25ns_1l", "normalTTbar_50ns_2l", "normalTTbar_50ns_1l", "puppiTTbar_25ns_2l", "puppiTTbar_25ns_1l", "puppiTTbar_50ns_2l", "puppiTTbar_50ns_1l"};
    
    const int PUbinsize = 5;
    string PUbin[PUbinsize] = {"0to10","11to15","16to20","21to25","25toInf"};
    Color_t color[PUbinsize] = {kYellow+1 , kBlue+1, kRed+1, kGreen+1, kMagenta+1};
    int style[PUbinsize] = {29 , 22, 21, 20, 23};
    
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
    
    string fname = "PUbinHistos_" + mysample + ".root";
    TFile *f = TFile::Open(fname.c_str());
    


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
    for(unsigned int b = 0; b<2; ++b){
        string samplestring = mysample;
        if(b==0) samplestring = mysample + "_2l";
        if(b==1) samplestring = mysample + "_1l";
        f->cd();
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    string newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring;
                    if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)f->Get(newname.c_str());
                    hist[newname]->SetMarkerColor(color[a]); hist[newname]->SetLineColor(color[a]); hist[newname]->SetMarkerStyle(style[a]);
                    string tmp = newname + "_Rat"; histRat[newname] = (TH1D*)hist[newname]->Clone(tmp.c_str());
                    if(a==0){
                        tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring;
                        histSum[tmp] = (TH1D*)hist[newname]->Clone(tmp.c_str());
                        histSum[tmp]->SetMarkerColor(kBlack); histSum[tmp]->SetLineColor(kBlack); histSum[tmp]->SetMarkerStyle(3);
                    } else{
                        tmp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring;
                        histSum[tmp]->Add(hist[newname]);
                    }
                    if(i==0&&b==0&&c==0) leg->AddEntry(hist[newname],PUbin[a].c_str(),"lp");
                }
                /*
                //prepare draw
                string temp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring;
                if(histSum[temp]->Integral()>0) histSum[temp]->Scale(1./histSum[temp]->Integral());
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    if(i!=0||c!=0||b!=0||a!=2) continue;
                    string newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring;
                    if(histRat[newname]->Integral()>0) histRat[newname]->Scale(1./histRat[newname]->Integral());
                    //cout <<histRat[newname]->Integral() << " " <<histSum[temp]->Integral() << endl;
                    if(histSum[temp]->Integral()>0) histRat[newname]->Divide(histSum[temp]);
                    //histRat[newname]->Draw();
                }
                */
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
    
    
    for(unsigned int b = 0; b<2; ++b){
        string samplestring = mysample;
        if(b==0) samplestring = mysample + "_2l";
        if(b==1) samplestring = mysample + "_1l";
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                //if(i!=0||c!=0||b!=0) continue;
                TH1D *haxis;
                TH1D *haxisRat;
                c1->cd();
                c1->Clear();
                string newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[0]+"_"+samplestring;
                haxis = (TH1D*)hist[newname]->Clone("haxis");
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
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring;
                    hist[newname]->DrawNormalized("sameE");
                }
                string temp = prestring[c] + "_"+ histonames[i] + "_"+metric+"_"+samplestring;
                histSum[temp]->DrawNormalized("sameE");
                newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[0]+"_"+samplestring;
                haxisRat = (TH1D*)histRat[newname]->Clone("haxisRat");
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
                if(histSum[temp]->Integral()>0) histSum[temp]->Scale(1./histSum[temp]->Integral());
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring;
                    if(histRat[newname]->Integral()>0) histRat[newname]->Scale(1./histRat[newname]->Integral());
                    if(histSum[temp]->Integral()>0) histRat[newname]->Divide(histSum[temp]);
                    histRat[newname]->Draw("sameE");
                    //newname = prestring[c] + "_"+ histonames[i] + "_"+metric+PUbin[a]+"_"+samplestring;
                    //histRat[newname]->Draw("sameE");
                }
                c1->cd();
                TString outputdir = "../../plots/PUstudies/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + metric + "/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + samplestring + "/";
                MakeOutputDir(outputdir);
                outputdir = outputdir + prestring[c] + "/";
                MakeOutputDir(outputdir);
                TString outputfilename = outputdir + "/" +histonames[i] +".pdf";
                c1->SaveAs(outputfilename.Data());
                //c1->Clear();
                //delete uppad;
                //delete downpad;
            }
        }
    }
    
}