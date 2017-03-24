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

void RestructureMLFIT(){

    TFile *f = new TFile("mlfit_std.root","read");
    TFile *fc = new TFile("mlfit_compressed.root","read");
  if(f->IsZombie()) {
    f->Close();
    delete f;
    //cout << "file " << inputfile << " is zombie - exit" << endl;
    return;
  }
  f->cd();
    TFile *fdata = new TFile("../Results/ResultRootFileMoriond17.root","read");
    if(fdata->IsZombie()) {
        fdata->Close();
        delete fdata;
        //cout << "file " << datafile << " is zombie - exit" << endl;
        return;
    }
    fdata->cd();

    TFile *fout = new TFile("PreAndPostfit_36p6fbinv.root","RECREATE");
    fout->cd();
  TH1F *prefit  = new TH1F("PrefitBG","",31,0,31);
  TH1F *postfit = new TH1F("PostfitBG","",31,0,31);
    f->cd();
    TH1F *h;
    h = (TH1F*)f->Get("shapes_prefit/ch1/total_background");
    prefit->SetBinContent(1,h->GetBinContent(1));
    prefit->SetBinError  (1,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch2/total_background");
    prefit->SetBinContent(2,h->GetBinContent(1));
    prefit->SetBinError  (2,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch3/total_background");
    prefit->SetBinContent(3,h->GetBinContent(1));
    prefit->SetBinError  (3,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch4/total_background");
    prefit->SetBinContent(4,h->GetBinContent(1));
    prefit->SetBinError  (4,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch5/total_background");
    prefit->SetBinContent(5,h->GetBinContent(1));
    prefit->SetBinError  (5,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch6/total_background");
    prefit->SetBinContent(6,h->GetBinContent(1));
    prefit->SetBinError  (6,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch7/total_background");
    prefit->SetBinContent(7,h->GetBinContent(1));
    prefit->SetBinError  (7,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch8/total_background");
    prefit->SetBinContent(8,h->GetBinContent(1));
    prefit->SetBinError  (8,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch9/total_background");
    prefit->SetBinContent(9,h->GetBinContent(1));
    prefit->SetBinError  (9,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch10/total_background");
    prefit->SetBinContent(10,h->GetBinContent(1));
    prefit->SetBinError  (10,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch11/total_background");
    prefit->SetBinContent(11,h->GetBinContent(1));
    prefit->SetBinError  (11,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch12/total_background");
    prefit->SetBinContent(12,h->GetBinContent(1));
    prefit->SetBinError  (12,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch13/total_background");
    prefit->SetBinContent(13,h->GetBinContent(1));
    prefit->SetBinError  (13,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch14/total_background");
    prefit->SetBinContent(14,h->GetBinContent(1));
    prefit->SetBinError  (14,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch15/total_background");
    prefit->SetBinContent(15,h->GetBinContent(1));
    prefit->SetBinError  (15,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch16/total_background");
    prefit->SetBinContent(16,h->GetBinContent(1));
    prefit->SetBinError  (16,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch17/total_background");
    prefit->SetBinContent(17,h->GetBinContent(1));
    prefit->SetBinError  (17,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch18/total_background");
    prefit->SetBinContent(18,h->GetBinContent(1));
    prefit->SetBinError  (18,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch19/total_background");
    prefit->SetBinContent(19,h->GetBinContent(1));
    prefit->SetBinError  (19,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch20/total_background");
    prefit->SetBinContent(20,h->GetBinContent(1));
    prefit->SetBinError  (20,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch21/total_background");
    prefit->SetBinContent(21,h->GetBinContent(1));
    prefit->SetBinError  (21,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch22/total_background");
    prefit->SetBinContent(22,h->GetBinContent(1));
    prefit->SetBinError  (22,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch23/total_background");
    prefit->SetBinContent(23,h->GetBinContent(1));
    prefit->SetBinError  (23,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch24/total_background");
    prefit->SetBinContent(24,h->GetBinContent(1));
    prefit->SetBinError  (24,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch25/total_background");
    prefit->SetBinContent(25,h->GetBinContent(1));
    prefit->SetBinError  (25,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch25/1l");
    prefit->SetBinError  (25,sqrt(pow(prefit->GetBinError(25),2)-pow(h->GetBinError(1),2)+pow(0.38,2)));
    cout << h->GetBinError(1) << " " << h->GetBinContent(1) << endl;
    h = (TH1F*)f->Get("shapes_prefit/ch26/total_background");
    prefit->SetBinContent(26,h->GetBinContent(1));
    prefit->SetBinError  (26,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_prefit/ch27/total_background");
    prefit->SetBinContent(27,h->GetBinContent(1));
    prefit->SetBinError  (27,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_prefit/ch1/total_background");
    prefit->SetBinContent(28,h->GetBinContent(1));
    prefit->SetBinError  (28,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_prefit/ch2/total_background");
    prefit->SetBinContent(29,h->GetBinContent(1));
    prefit->SetBinError  (29,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_prefit/ch3/total_background");
    prefit->SetBinContent(30,h->GetBinContent(1));
    prefit->SetBinError  (30,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_prefit/ch4/total_background");
    prefit->SetBinContent(31,h->GetBinContent(1));
    prefit->SetBinError  (31,h->GetBinError(1));
    
    h = (TH1F*)f->Get("shapes_fit_b/ch1/total_background");
    postfit->SetBinContent(1,h->GetBinContent(1));
    postfit->SetBinError  (1,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch2/total_background");
    postfit->SetBinContent(2,h->GetBinContent(1));
    postfit->SetBinError  (2,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch3/total_background");
    postfit->SetBinContent(3,h->GetBinContent(1));
    postfit->SetBinError  (3,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch4/total_background");
    postfit->SetBinContent(4,h->GetBinContent(1));
    postfit->SetBinError  (4,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch5/total_background");
    postfit->SetBinContent(5,h->GetBinContent(1));
    postfit->SetBinError  (5,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch6/total_background");
    postfit->SetBinContent(6,h->GetBinContent(1));
    postfit->SetBinError  (6,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch7/total_background");
    postfit->SetBinContent(7,h->GetBinContent(1));
    postfit->SetBinError  (7,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch8/total_background");
    postfit->SetBinContent(8,h->GetBinContent(1));
    postfit->SetBinError  (8,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch9/total_background");
    postfit->SetBinContent(9,h->GetBinContent(1));
    postfit->SetBinError  (9,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch10/total_background");
    postfit->SetBinContent(10,h->GetBinContent(1));
    postfit->SetBinError  (10,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch11/total_background");
    postfit->SetBinContent(11,h->GetBinContent(1));
    postfit->SetBinError  (11,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch12/total_background");
    postfit->SetBinContent(12,h->GetBinContent(1));
    postfit->SetBinError  (12,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch13/total_background");
    postfit->SetBinContent(13,h->GetBinContent(1));
    postfit->SetBinError  (13,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch14/total_background");
    postfit->SetBinContent(14,h->GetBinContent(1));
    postfit->SetBinError  (14,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch15/total_background");
    postfit->SetBinContent(15,h->GetBinContent(1));
    postfit->SetBinError  (15,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch16/total_background");
    postfit->SetBinContent(16,h->GetBinContent(1));
    postfit->SetBinError  (16,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch17/total_background");
    postfit->SetBinContent(17,h->GetBinContent(1));
    postfit->SetBinError  (17,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch18/total_background");
    postfit->SetBinContent(18,h->GetBinContent(1));
    postfit->SetBinError  (18,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch19/total_background");
    postfit->SetBinContent(19,h->GetBinContent(1));
    postfit->SetBinError  (19,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch20/total_background");
    postfit->SetBinContent(20,h->GetBinContent(1));
    postfit->SetBinError  (20,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch21/total_background");
    postfit->SetBinContent(21,h->GetBinContent(1));
    postfit->SetBinError  (21,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch22/total_background");
    postfit->SetBinContent(22,h->GetBinContent(1));
    postfit->SetBinError  (22,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch23/total_background");
    postfit->SetBinContent(23,h->GetBinContent(1));
    postfit->SetBinError  (23,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch24/total_background");
    postfit->SetBinContent(24,h->GetBinContent(1));
    postfit->SetBinError  (24,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch25/total_background");
    postfit->SetBinContent(25,h->GetBinContent(1));
    postfit->SetBinError  (25,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch26/total_background");
    postfit->SetBinContent(26,h->GetBinContent(1));
    postfit->SetBinError  (26,h->GetBinError(1));
    h = (TH1F*)f->Get("shapes_fit_b/ch27/total_background");
    postfit->SetBinContent(27,h->GetBinContent(1));
    postfit->SetBinError  (27,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_fit_b/ch1/total_background");
    postfit->SetBinContent(28,h->GetBinContent(1));
    postfit->SetBinError  (28,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_fit_b/ch2/total_background");
    postfit->SetBinContent(29,h->GetBinContent(1));
    postfit->SetBinError  (29,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_fit_b/ch3/total_background");
    postfit->SetBinContent(30,h->GetBinContent(1));
    postfit->SetBinError  (30,h->GetBinError(1));
    h = (TH1F*)fc->Get("shapes_fit_b/ch4/total_background");
    postfit->SetBinContent(31,h->GetBinContent(1));
    postfit->SetBinError  (31,h->GetBinError(1));

    fdata->cd();
  TH1D *tData = (TH1D*)fdata->Get("rpt_Data");
    TH1D *Data = new TH1D("Data","",27,0,27);
    Data->SetBinErrorOption(TH1::kPoisson);
    for(int i = 1; i<=Data->GetNbinsX(); ++i){
        cout << tData->GetBinContent(i) << endl;
        for(int n = 1; n<=tData->GetBinContent(i); ++n){
            Data->Fill(i-0.5,1);
        }
    }
    fout->cd();
    Data->Write();
    prefit->Write();
    postfit->Write();
    fout->Close();
}
