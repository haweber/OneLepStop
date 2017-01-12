#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TColor.h"
#include "TPad.h"
#include "TF1.h"
#include "TLine.h"
#include "TLatex.h"


void MakeMTMETResPlots(){
    
    string myMT[6] = {"MT0", "MT50", "MT80", "MT100", "MT120", "MT150"};
    Color_t mycol[6] = {kBlack, kMagenta-3, kGreen+1, kCyan+1, kOrange-3, kRed};
    int mysty[6] = {2, 1, 1, 1, 1, 2};
    
    string myMET[2] = {"MET150","MET250"};
    //string myNJ[2]  = {"3j",    "ge4j"};
    string myNJ[3]  = {"2j", "3j",    "ge4j"};
    string myhist[3] = {"PFMETminusGenMET", "PFMEToverGenMET", "PFMETminusGenMEToverGenMET"};
   map<string, TH1F*> histos;
    vector<string> histonames;
    vector<string> histonamesreduced;
    for(unsigned int i = 0; i<3;++i){
        for(unsigned int j = 0; j<2;++j){
            //for(unsigned int k = 0; k<2; ++k){
            for(unsigned int k = 0; k<3; ++k){
                histonamesreduced.push_back(myhist[i] + "_" + myMET[j] + myNJ[k] + "0b");
            }
        }
    }
   
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT150_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT150_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT150_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT120_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT120_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT120_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT100_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT100_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT100_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT80_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT80_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT80_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT50_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT50_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT50_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET250ge4j0bMT0_WJetsMC");             
    histonames.push_back("PFMEToverGenMET_MET250ge4j0bMT0_WJetsMC");              
    histonames.push_back("PFMETminusGenMEToverGenMET_MET250ge4j0bMT0_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT150_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT150_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT150_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT120_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT120_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT120_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT100_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT100_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT100_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT80_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT80_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT80_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT50_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT50_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT50_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET2503j0bMT0_WJetsMC");             
    histonames.push_back("PFMEToverGenMET_MET2503j0bMT0_WJetsMC");              
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2503j0bMT0_WJetsMC");
    
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT150_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT150_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT150_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT120_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT120_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT120_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT100_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT100_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT100_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT80_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT80_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT80_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT50_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT50_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT50_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET2502j0bMT0_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET2502j0bMT0_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET2502j0bMT0_WJetsMC");
    
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT150_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT150_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT150_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT120_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT120_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT120_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT100_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT100_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT100_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT80_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT80_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT80_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT50_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT50_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT50_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET150ge4j0bMT0_WJetsMC");             
    histonames.push_back("PFMEToverGenMET_MET150ge4j0bMT0_WJetsMC");              
    histonames.push_back("PFMETminusGenMEToverGenMET_MET150ge4j0bMT0_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT150_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT150_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT150_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT120_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT120_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT120_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT100_WJetsMC");           
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT100_WJetsMC");            
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT100_WJetsMC"); 
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT80_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT80_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT80_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT50_WJetsMC");            
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT50_WJetsMC");             
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT50_WJetsMC");  
    histonames.push_back("PFMETminusGenMET_MET1503j0bMT0_WJetsMC");             
    histonames.push_back("PFMEToverGenMET_MET1503j0bMT0_WJetsMC");              
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1503j0bMT0_WJetsMC");
    
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT150_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT150_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT150_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT120_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT120_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT120_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT100_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT100_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT100_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT80_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT80_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT80_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT50_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT50_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT50_WJetsMC");
    histonames.push_back("PFMETminusGenMET_MET1502j0bMT0_WJetsMC");
    histonames.push_back("PFMEToverGenMET_MET1502j0bMT0_WJetsMC");
    histonames.push_back("PFMETminusGenMEToverGenMET_MET1502j0bMT0_WJetsMC");
    cout << __LINE__<<endl;
   TFile *file = TFile::Open("WJetsPt_WJetsMC.root");
   file->cd();
    for(unsigned int i = 0; i<histonames.size();++i) {
        cout << histonames[i] << endl;
        histos[histonames[i] ] = (TH1F*)file->Get(histonames[i].c_str());
        cout << histonames[i] << endl;
        for(int n = 1; n<histos[histonames[i] ]->GetNbinsX(); ++n){
            if(histos[histonames[i] ]->GetBinContent(n)<0){
                histos[histonames[i] ]->SetBinContent(n,0);
                histos[histonames[i] ]->SetBinError(n,0);
            }
        }
        histos[histonames[i] ]->Scale(1./histos[histonames[i] ]->Integral(1,histos[histonames[i] ]->GetNbinsX() ) );
    }
    cout << __LINE__<<endl;

    TCanvas *c1 = new TCanvas("c1", "",250,250,600,600);
    c1->cd();
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
    
    c1->cd();
    for(unsigned int j = 0; j<histonamesreduced.size() ; ++j){
        string first =histonamesreduced[j] + "MT0_WJetsMC";
        TString firstT =histonamesreduced[j];
        string selh = "";
        if(firstT.Contains("MET250")) selh = "E_{T}^{miss} > 250 GeV";
        else selh = "E_{T}^{miss} > 150 GeV";
        if(firstT.Contains("2j")) selh = selh + ", 2 jets";
        else if(firstT.Contains("3j")) selh = selh + ", 3 jets";
        else selh = selh + ", #geq4 jets";
        histos[first ]->SetFillColor(mycol[0]);
        histos[first ]->SetLineColor(mycol[0]);
        histos[first ]->SetLineWidth(mysty[0]);
        histos[first ]->SetMarkerColor(mycol[0]);
        histos[first ]->GetXaxis()->SetTitle("");//no title here
        histos[first ]->GetXaxis()->SetLabelFont(42);
        histos[first ]->GetXaxis()->SetLabelOffset(0.007);
        histos[first ]->GetXaxis()->SetLabelSize(0.05);
        histos[first ]->GetXaxis()->SetTitleSize(0.05);
        //histos[first ]->GetXaxis()->SetTitleOffset(0.9);
        histos[first ]->GetXaxis()->SetTitleOffset(1.2);
        histos[first ]->GetXaxis()->SetTitleFont(42);
        histos[first ]->GetXaxis()->SetNdivisions(505);
        histos[first ]->GetYaxis()->SetTitle("a.u.");
        histos[first ]->GetYaxis()->SetLabelFont(42);
        histos[first ]->GetYaxis()->SetLabelOffset(0.007);
        histos[first ]->GetYaxis()->SetLabelSize(0.05);
        histos[first ]->GetYaxis()->SetTitleSize(0.06);
        histos[first ]->GetYaxis()->SetTitleOffset(1.25);
        histos[first ]->GetYaxis()->SetTitleFont(42);
        histos[first ]->GetYaxis()->SetNdivisions(505);
        histos[first ]->GetZaxis()->SetLabelFont(42);
        histos[first ]->GetZaxis()->SetLabelOffset(0.007);
        histos[first ]->GetZaxis()->SetLabelSize(0.05);
        histos[first ]->GetZaxis()->SetTitleSize(0.06);
        histos[first ]->GetZaxis()->SetTitleFont(42);
        histos[first ]->SetStats(0);
        histos[first ]->SetMinimum(0.);
        if(firstT.Contains("PFMETminusGenMEToverGenMET")){
            histos[first ]->GetXaxis()->SetTitle("signed |reco-#vec{E}_{T}^{miss}-gen-#vec{E}_{T}^{miss}| / gen-E_{T}^{miss}");
            histos[first ]->GetYaxis()->SetTitle("a.u. / 0.2");
            histos[first ]->SetMaximum(0.6);
        } else if(firstT.Contains("PFMEToverGenMET")){
            histos[first ]->GetXaxis()->SetTitle("reco-E_{T}^{miss} / gen-E_{T}^{miss}");
            histos[first ]->GetYaxis()->SetTitle("a.u. / 0.1");
            histos[first ]->SetMaximum(0.6);
        } else if(firstT.Contains("PFMETminusGenMET")){
            histos[first ]->GetXaxis()->SetTitle("signed |reco-#vec{E}_{T}^{miss}-gen-#vec{E}_{T}^{miss}| [GeV]");
            histos[first ]->GetYaxis()->SetTitle("a.u. / 20 GeV");
            histos[first ]->SetMaximum(0.6);
        }
        string second = histonamesreduced[j] + "MT50_WJetsMC";
        histos[second ]->SetFillColor(  mycol[1]);
        histos[second ]->SetLineColor(  mycol[1]);
        histos[second ]->SetLineWidth(  mysty[1]);
        histos[second ]->SetMarkerColor(mycol[1]);
        string third  = histonamesreduced[j] + "MT80_WJetsMC";
        histos[third  ]->SetFillColor(  mycol[2]);
        histos[third  ]->SetLineColor(  mycol[2]);
        histos[third  ]->SetLineWidth(  mysty[2]);
        histos[third  ]->SetMarkerColor(mycol[2]);
        string fourth = histonamesreduced[j] + "MT100_WJetsMC";
        histos[fourth ]->SetFillColor(  mycol[3]);
        histos[fourth ]->SetLineColor(  mycol[3]);
        histos[fourth ]->SetLineWidth(  mysty[3]);
        histos[fourth ]->SetMarkerColor(mycol[3]);
        string fifth  = histonamesreduced[j] + "MT120_WJetsMC";
        histos[fifth  ]->SetFillColor(  mycol[4]);
        histos[fifth  ]->SetLineColor(  mycol[4]);
        histos[fifth  ]->SetLineWidth(  mysty[4]);
        histos[fifth  ]->SetMarkerColor(mycol[4]);
        string sixth  = histonamesreduced[j] + "MT150_WJetsMC";
        histos[sixth  ]->SetFillColor(  mycol[5]);
        histos[sixth  ]->SetLineColor(  mycol[5]);
        histos[sixth  ]->SetLineWidth(  mysty[5]);
        histos[sixth  ]->SetMarkerColor(mycol[5]);
        
        histos[first ]->Draw("E1");
        histos[second]->Draw("sameE1");
        histos[third ]->Draw("sameE1");
        histos[fourth]->Draw("sameE1");
        histos[fifth ]->Draw("sameE1");
        histos[sixth ]->Draw("sameE1");
        TLegend *leg = new TLegend(0.55,0.667,0.7,0.9,NULL,"brNDC");
        leg->SetBorderSize(0);  leg->SetTextSize(0.042);    leg->SetTextFont(42);   leg->SetLineColor(1);
        leg->SetLineStyle(1);   leg->SetLineWidth(2);   leg->SetFillColor(0);   leg->SetFillStyle(1001);
        leg->AddEntry(histos[first ], "all M_{T}"      , "lep");
        leg->AddEntry(histos[second],  "M_{T} > 50 GeV", "lep");
        leg->AddEntry(histos[third ],  "M_{T} > 80 GeV", "lep");
        leg->AddEntry(histos[fourth], "M_{T} > 100 GeV", "lep");
        leg->AddEntry(histos[fifth ], "M_{T} > 120 GeV", "lep");
        leg->AddEntry(histos[sixth ], "M_{T} > 150 GeV", "lep");
        leg->Draw();
        TLatex *tex1 = new TLatex(0.6,0.6,selh.c_str());
        tex1->SetNDC();  tex1->SetTextAlign(11);
        tex1->SetTextFont(42);   tex1->SetTextSize(0.035); tex1->SetLineWidth(2);
        tex1->Draw();
        //TLatex *tex2 = new TLatex(0.45,0.667,typeh[i].c_str());
        //tex2->SetNDC();  tex2->SetTextAlign(11);
        //tex2->SetTextFont(42);   tex2->SetTextSize(0.0385);   tex2->SetLineWidth(2);
        //tex2->Draw();
        TLatex *tex3 = new TLatex(0.95,0.944,"(13 TeV)");
        tex3->SetNDC();  tex3->SetTextAlign(31);
        tex3->SetTextFont(42);   tex3->SetTextSize(0.042);    tex3->SetLineWidth(2);
        tex3->Draw();
        TLatex *tex4 = new TLatex(0.21465,0.9027,"CMS");
        tex4->SetNDC();  tex4->SetTextAlign(13);
        tex4->SetTextFont(61);   tex4->SetTextSize(0.0525);   tex4->SetLineWidth(2);
        tex4->Draw();
        TLatex *tex5 = new TLatex(0.21465,0.8397,"Simulation");
        tex5->SetNDC();  tex5->SetTextAlign(13);
        tex5->SetTextFont(52);   tex5->SetTextSize(0.0399);   tex5->SetLineWidth(2);
        tex5->Draw();
        TLatex *texf = new TLatex();
        texf->SetNDC();  texf->SetTextAlign(11); texf->SetTextColor(mycol[0]);
        texf->SetTextFont(42);   texf->SetTextSize(0.035);   texf->SetLineWidth(2);
        TLatex *texe = new TLatex();
        texe->SetNDC();  texe->SetTextAlign(11); texe->SetTextColor(mycol[5]);
        texe->SetTextFont(42);   texe->SetTextSize(0.035);   texe->SetLineWidth(2);
        std::ostringstream ss1;
        ss1 << fixed << setprecision(2) << "mean = " << histos[first ]->GetMean() << " #pm " << histos[first ]->GetStdDev();;
        texf->DrawLatex(0.6,0.56,ss1.str().c_str());
        std::ostringstream ss2;
        ss2 << fixed << setprecision(2) << "mean = " << histos[fifth ]->GetMean() << " #pm " << histos[fifth ]->GetStdDev();;
        texe->DrawLatex(0.6,0.525,ss2.str().c_str());

        c1->cd();
        c1->Modified();
        c1->cd();
        string savename = "WJetsPlots/" + histonamesreduced[j] + ".pdf";
        c1->SaveAs(savename.c_str() );
        c1->Clear();
        //delete line;
        //delete lineff;
        delete leg;
        delete tex1;
        //delete tex2;
        delete tex3;
        delete tex4;
        delete tex5;
        delete texf;
        delete texe;
    }
    //delete c1;

}
