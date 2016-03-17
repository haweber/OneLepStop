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


using namespace std;

void makePlotsPAS(bool linear=false){
    
    const unsigned int datasetsize = 28;
    const unsigned int bgsetsize = 5;
    //                              0       1           2       3       4       5               6           7               8               9                   10          11
    //          12              13                  14
    //      15              16          17              18          19
    //      20              21          22
    //      23              24          25              26          27
    string datasets[datasetsize]={"TTbar2l","TTbar1l","tW","WJets","Rare", "T2tb_425_225","T2tb_650_325","T2tb_850_100", "T2tt_275_100","T2tt_300_200","T2tt_600_250","T2tt_700_50", "T2bw_700_250_100","T2bw_700_400_100","T2bw_700_550_100",
        "T2tb_300_150","T2tb_600_50","T2tb_500_200","T2tb_700_50","T2tb_600_200",
        "T2tt_300_150","T2tt_500_200","T2tt_600_50",
        "T2bW_700_50","T2bW_600_50","T2bW_600_200","T2bW_500_200","T2bW_300_150",
    };
    //Color_t mycolor[datasetsize] = {kCyan-3,kRed-7,kBlue-7,kOrange-2,kMagenta-5, kAzure+5,kSpring-2,kMagenta-4, kYellow-2,kAzure+5,kSpring-2,kMagenta-4, kAzure+5,kSpring-2,kMagenta-4};
    Color_t mycolor[datasetsize] = {kCyan-3,kRed-7,kBlue-7,kOrange-2,kMagenta-5,
        kOrange+4,kSpring-2,kMagenta-4, kYellow-2,kOrange+4,kSpring-2,kMagenta-4, kOrange+4,kSpring-2,kMagenta-4,
        kMagenta-4,kSpring-2,kOrange+4,kSpring-2,kOrange+4,
        kOrange+4,kSpring-2,kMagenta-4,
        kOrange+4,kOrange+4,kMagenta-4,kMagenta-4,kSpring-2
    };
    string dataname[datasetsize] = {"t#bar{t}#rightarrow2#font[12]{l}","t#bar{t}#rightarrow1#font[12]{l}","tW", "W+jets","Rare",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (425,225)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (650,325)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (850,100)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (275,100)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (300,200)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (600,250)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (700,50)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (700,250,100)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (700,400,100)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (700,550,100)",
        
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (300,150)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (600,50)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (500,200)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (700,50)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0}/#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (600,200)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (300,150)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (500,200)",
        "#tilde{t}#rightarrow t#tilde{#chi}_{1}^{0} (600,50)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (700,50)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (600,50)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (600,200)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (500,200)",
        "#tilde{t}#rightarrow b#tilde{#chi}_{1}^{#pm} (300,150)"
    
    
    };

    vector<string> histonames;
    histonames.push_back("MT");
    histonames.push_back("MT2W");        
    histonames.push_back("MT2W_4j");     
    histonames.push_back("MET");         
    histonames.push_back("MET_3j");      
    histonames.push_back("MET_4j");      
    histonames.push_back("MET_hMT2W");   
    histonames.push_back("MET_hMT2W_4j");
    histonames.push_back("MinDPhi");     
    histonames.push_back("MinDPhi_3j");  
    histonames.push_back("MinDPhi_4j");  
    histonames.push_back("NJets");       
    histonames.push_back("NJets_hard");  
    histonames.push_back("tMod");
    histonames.push_back("tMod_2j");
 //   histonames.push_back("t");
 //   histonames.push_back("t_2j");
    
    vector<string> xlabel;
    vector<string> ylabel;
    xlabel.push_back("M_{T} [GeV]");
    xlabel.push_back("M_{T2}^{W} [GeV]");
    xlabel.push_back("M_{T2}^{W} [GeV]");
    xlabel.push_back("E_{T}^{miss} [GeV]");
    xlabel.push_back("E_{T}^{miss} [GeV]");
    xlabel.push_back("E_{T}^{miss} [GeV]");
    xlabel.push_back("E_{T}^{miss} [GeV]");
    xlabel.push_back("E_{T}^{miss} [GeV]");
    xlabel.push_back("min#Delta#phi(j_{1,2},E_{T}^{miss})");
    xlabel.push_back("min#Delta#phi(j_{1,2},E_{T}^{miss})");
    xlabel.push_back("min#Delta#phi(j_{1,2},E_{T}^{miss})");
    xlabel.push_back("number of jets");
    xlabel.push_back("number of jets");
    xlabel.push_back("t_{mod}");
    xlabel.push_back("t_{mod}");
//    xlabel.push_back("t");
//    xlabel.push_back("t");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 25 GeV");
    ylabel.push_back("Events / 0.1");
    ylabel.push_back("Events / 0.1");
    ylabel.push_back("Events / 0.1");
    ylabel.push_back("Events / 1");
    ylabel.push_back("Events / 1");
    ylabel.push_back("Events / 1");
    ylabel.push_back("Events / 1");
 //   ylabel.push_back("Events / 1");
 //   ylabel.push_back("Events / 1");

    TH1F* null = new TH1F("","",1,0,1);
    string outputdir = "plotstemp2/";
    map<string, TH1F*> histos;
    TFile *f = TFile::Open("PASfigure.root");
    bool addoverflow = true;
    for(unsigned int i = 0; i<histonames.size();++i){
        for(unsigned int n=0; n<datasetsize; ++n){
            string name =histonames[i] + "_" +datasets[n];
            histos[name] = (TH1F*)f->Get(name.c_str());
            if(addoverflow){
                histos[name]->SetBinContent(histos[name]->GetNbinsX(), histos[name]->GetBinContent(histos[name]->GetNbinsX())+histos[name]->GetBinContent(histos[name]->GetNbinsX()+1) );
                histos[name]->SetBinError(histos[name]->GetNbinsX(), sqrt(pow(histos[name]->GetBinContent(histos[name]->GetNbinsX()),2)+pow(histos[name]->GetBinContent(histos[name]->GetNbinsX()+1),2) ) );
            }
        }
    }


    for(unsigned int i = 0; i<histonames.size();++i){
        vector<TH1F*> bghist; bghist.clear();
        vector<string> bgstring; bgstring.clear();
        vector<TH1F*> sighist; sighist.clear();
        vector<string> sigstring; sigstring.clear();
        string outname = outputdir + histonames[i] + ".pdf";
        if(linear) outname = outputdir + histonames[i] + "linear.pdf";
        string options = "--outputName " + outputdir + histonames[i] + " --xAxisOverride " + xlabel[i] + " --yAxisOverride " + ylabel[i] + " --energy 13 --lumi 2.3 --legendTextSize 0.02 --preserveBackgroundOrder --legendUp 0.04 --sigError --noBlackLines";
        if(linear) options = "--outputName " + outputdir + histonames[i] + "linear" + " --xAxisOverride " + xlabel[i] + " --yAxisOverride " + ylabel[i] + " --energy 13 --lumi 2.3 --legendTextSize 0.02 --preserveBackgroundOrder --legendUp 0.04 --sigError --isLinear --noBlackLines";
        for(int n=bgsetsize-1; n>=0; --n){
            string name =histonames[i] + "_" +datasets[n];
            histos[name]->SetLineColor(mycolor[n]);
            histos[name]->SetMarkerColor(mycolor[n]);
            histos[name]->SetFillColor(mycolor[n]);
            bghist.push_back(histos[name]);
            bgstring.push_back(dataname[n]);
            //hcolors.push_back(mycolor[n]);
            if(i>13) cout << name << " " << histos[name]->Integral() << endl;
        }
        for(unsigned int n=bgsetsize; n<datasetsize; ++n){
            //if(i==0  && (n!= 9&&n!= 6&&n!=11) ) continue;//MT
            if(i==0  && (n!=20&&n!=22&&n!=16) ) continue;//MT
            //if(i==1  && (n!= 9&&n!=10&&n!=11) ) continue;//MT2W
            if(i==1  && (n!=22&&n!=20&&n!=21) ) continue;//MT2W
            //if(i==2  && (n!= 9&&n!=10&&n!=11) ) continue;//MT2W 4j
            if(i==2  && (n!=20&&n!=22&&n!=21) ) continue;//MT
            //if(i==3  && (n!= 9&&n!= 6&&n!=11) ) continue;//MET
            if(i==3  && (n!=20&&n!=22&&n!=16) ) continue;//MT
            if(i==4  && (n!= 9&&n!= 6&&n!=11) ) continue;//MET 3j
            if(i==5  && (n!= 9&&n!= 6&&n!=11) ) continue;//MET 4j
            if(i==6  && (n!= 9&&n!=10&&n!=11) ) continue;//MET hMT2W
            if(i==7  && (n!= 9&&n!=10&&n!=11) ) continue;//MET hMT2W 4j
            if(i==8  && (n!= 9&&n!= 6&&n!=11) ) continue;//MDPhi
            if(i==9  && (n!= 9&&n!= 6&&n!=11) ) continue;//MDPhi 3j
            if(i==10 && (n!= 9&&n!= 6&&n!=11) ) continue;//MDPhi 4j
            if(i==11 && (n!= 9&&n!= 6&&n!=11) ) continue;//nj
            if(i==12 && (n!= 9&&n!= 6&&n!=11) ) continue;//nj
            //if(i==13 && (n!=11&&n!= 6&&n!= 7) ) continue;//tmod
            //if(i==14 && (n!=11&&n!= 6&&n!= 7) ) continue;//tmod 2j
            if(i==13 && (n!=15&&n!=16&&n!=17) ) continue;//t
            if(i==14 && (n!=15&&n!=16&&n!=17) ) continue;//t 2j
            string name =histonames[i] + "_" +datasets[n];
            histos[name]->SetLineColor(mycolor[n]);
            histos[name]->SetMarkerColor(mycolor[n]);
            if(n==11&&i>=13){
                histos[name]->SetMarkerColor(mycolor[5]);
                histos[name]->SetLineColor(mycolor[5]);
            }
            //histos[name]->SetFillColor(mycolor[n]);
            histos[name]->SetLineWidth(3);
            //histos[name]->SetLineStyle(5+sighist.size());
            histos[name]->SetLineStyle(7);
            histos[name]->SetMarkerStyle(21+sighist.size());
            sighist.push_back(histos[name]);
            sigstring.push_back(dataname[n]);
            //hcolors.push_back(mycolor[n]);
            //if(i>13) cout << name << " " << histos[name]->Integral() << endl;
        }

        //my own function
        TCanvas *c1 = new TCanvas("c1", "c1",50,50,650,650);
        gStyle->SetOptFit(1);
        gStyle->SetOptStat(0);
        gStyle->SetOptTitle(0);
        gStyle->SetErrorX(0.5);
        //c1->Range(-6.311689,-1.891383,28.75325,4.56342);
        c1->SetFillColor(0);
        c1->SetBorderMode(0);
        c1->SetBorderSize(2);
        if(!linear) c1->SetLogy();
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
        
        THStack *Sum = new THStack();
        Sum->SetName("Sum");
        //Sum->SetTitle(";Signal region;Events");
        string stacktitle = ";" + xlabel[i] + ";" + ylabel[i];
        Sum->SetTitle(stacktitle.c_str());
        //Sum->SetMinimum(0);
        //Sum->SetMaximum(27.5);
        TH1F *hSum = (TH1F*)bghist[0]->Clone("hSum");
        //hSum->SetMinimum(0.);
        //hSum->SetMaximum(27.5);
        hSum->SetDirectory(0);
        hSum->SetStats(0);
        
        Int_t ci;   // for color index setting
        ci = TColor::GetColor("#000099");
        hSum->SetLineColor(ci);
        hSum->SetLineStyle(0);
        hSum->SetMarkerStyle(20);
        hSum->GetXaxis()->SetTitle(xlabel[i].c_str());
        //hSum->GetXaxis()->SetBit(TAxis::kLabelsVert);
        hSum->GetXaxis()->SetLabelFont(42);
        hSum->GetXaxis()->SetLabelOffset(0.005);
        hSum->GetXaxis()->SetLabelSize(0.05);
        hSum->GetXaxis()->SetTitleSize(0.06);
        hSum->GetXaxis()->SetTitleOffset(1.15);
        hSum->GetXaxis()->SetTitleFont(42);
        hSum->GetXaxis()->SetNdivisions(507);
        hSum->GetYaxis()->SetTitle(ylabel[i].c_str());
        hSum->GetYaxis()->SetLabelFont(42);
        hSum->GetYaxis()->SetLabelOffset(0.007);
        hSum->GetYaxis()->SetLabelSize(0.05);
        hSum->GetYaxis()->SetTitleSize(0.06);
        hSum->GetYaxis()->SetTitleOffset(1.0);
        hSum->GetYaxis()->SetTitleFont(42);
        hSum->GetZaxis()->SetLabelFont(42);
        hSum->GetZaxis()->SetLabelOffset(0.007);
        hSum->GetZaxis()->SetLabelSize(0.05);
        hSum->GetZaxis()->SetTitleSize(0.06);
        hSum->GetZaxis()->SetTitleFont(42);
        
        double minimum = 0.;
        double maximum = 10.;
        
        //TLegend *leg = new TLegend(0.54,0.765,0.90,0.905,NULL,"brNDC");
        TLegend *leg = new TLegend(0.415,0.79,0.90,0.90,NULL,"brNDC");
        //TLegend *leg = new TLegend(0.7,0.62,0.92,0.9,NULL,"brNDC");
        //leg-> SetNColumns(2);
        leg->SetBorderSize(0);
        leg->SetTextSize(0.05);
        leg->SetTextFont(42);
        leg->SetLineColor(1);
        leg->SetLineStyle(1);
        leg->SetLineWidth(2);
        leg->SetFillColor(0);
        leg->SetFillStyle(1001);
        leg-> SetNColumns(3);
        for(unsigned int n=0; n<bghist.size(); ++n){
            Sum->Add(bghist[n],"");
            if(bghist[n]->GetMinimum()>0) minimum += bghist[n]->GetMinimum();
            if(bghist[n]->GetMaximum()>0) maximum += bghist[n]->GetMaximum();
            //cout << n << " " << minimum << " " << maximum << endl;
        }
        for(int n=bghist.size()-1; n>=0; --n){
            leg->AddEntry(bghist[n], bgstring[n].c_str(), "f");
        }
        if(linear){
            minimum *=0.9;
            maximum *=1.25;
        } else {
            minimum *=0.9;
            maximum *=20.;
            //if(histonames[i]=="MT2W_4j") maximum *= 10;
            //if(histonames[i]=="NJets") maximum *=1.2;
            if(histonames[i]=="tMod") maximum *=2.5;
            cout << minimum << " " << maximum << endl;
            minimum = pow(10.0, floor(log10(minimum)));
            maximum = pow(10.0, ceil(log10(maximum)));
            //cout << minimum << " " << maximum << endl;
            if(minimum==0) minimum = 0.02;
            if(histonames[i]=="MT") minimum *=0.5;

        }
        
        
        hSum->SetMinimum(minimum);
        hSum->SetMaximum(maximum);
        Sum->SetMinimum(minimum);
        Sum->SetMaximum(maximum);
        Sum->SetHistogram(hSum);
        Sum->Draw("hist");

        //TLegend *legs = new TLegend(0.54,0.606,0.74,0.765,NULL,"brNDC");
        TLegend *legs;
        if(histonames[i]=="MT2W_4j"||histonames[i]=="MT2W") legs = new TLegend(0.525,0.575,0.725,0.775,NULL,"brNDC");
        else legs = new TLegend(0.42,0.575,0.62,0.775,NULL,"brNDC");
        //TLegend *leg = new TLegend(0.7,0.62,0.92,0.9,NULL,"brNDC");
        //leg-> SetNColumns(2);
        legs->SetBorderSize(0);
        legs->SetTextSize(0.0475);
        legs->SetTextFont(42);
        legs->SetLineColor(1);
        legs->SetLineStyle(1);
        legs->SetLineWidth(2);
        legs->SetFillColor(0);
        legs->SetFillStyle(1001);
        //legs-> SetNColumns(2);
        for(unsigned int n=0; n<sighist.size(); ++n){
            legs->AddEntry(sighist[n], sigstring[n].c_str(), "ep");
            sighist[n]->Draw("sameEX0");

        }
        leg->Draw();
        legs->Draw();
        
        //final CMS style
        TLatex *tLumi = new TLatex(0.95,0.944,"2.3 fb^{-1} (13 TeV)");
        tLumi->SetNDC();
        tLumi->SetTextAlign(31);
        tLumi->SetTextFont(42);
        tLumi->SetTextSize(0.042);
        tLumi->SetLineWidth(2);
        tLumi->Draw();
        TLatex *tCMS = new TLatex(0.18,0.9027,"CMS");
        tCMS->SetNDC();
        tCMS->SetTextAlign(13);
        tCMS->SetTextFont(61);
        tCMS->SetTextSize(0.0525);
        tCMS->SetLineWidth(2);
        tCMS->Draw();
        //TLatex *tPrel = new TLatex(0.18,0.8397,"Preliminary");
        TLatex *tPrel = new TLatex(0.18,0.8397,"Simulation");
        tPrel->SetNDC();
        tPrel->SetTextAlign(13);
        tPrel->SetTextFont(52);
        tPrel->SetTextSize(0.04);
        tPrel->SetLineWidth(2);
        tPrel->Draw();
        
        c1->Modified();
        c1->cd();
        c1->Update();
        c1->SetSelected(c1);
        c1->SaveAs(outname.c_str());
  /*
        delete tLumi;
        delete tCMS;
        delete tPrel;
        delete Sum;
        delete leg;
        delete c1;
  */
        
    }
    
}