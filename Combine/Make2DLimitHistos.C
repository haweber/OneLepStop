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

TString inputdir = "/hadoop/cms/store/user/haweber/condor/limits/";
TString outputdir = "rootfiles/";

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}

void Make2DLimitHistos(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont);


void Make2DLimitHistos(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont){

  TH1D *hxsec;
  TFile *fxsec = new TFile("xsec_stop_13TeV.root","READ");
  if(fxsec->IsZombie()) {
    std::cout << "Somehow xsec_stop_13TeV.root is corrupted. Exit..." << std::endl;
    exit(0);
  }
  hxsec = (TH1D*)fxsec->Get("stop");
  
  int mStopLow  = 100;
  int mStopHigh = 1000;
  int mStopStep = 25;
  int mLSPLow   = 0;
  int mLSPHigh  = 500;
  int mLSPStep  = 25;
  int nbinsx = (mStopHigh - mStopLow)/mStopStep;
  int nbinsy = (mLSPHigh - mLSPLow)/mLSPStep;
  
  TString myoutputdir = outputdir;
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  MakeOutputDir(myoutputdir);
  TString myinputdir = inputdir;
  if(fakedata)   myinputdir = myinputdir + "fakedata/";
  if(compressed==1) myinputdir = myinputdir + "compressed/";
  if(nosigunc&&nobkgunc) myinputdir = myinputdir + "nounc/";
  else if(nosigunc) myinputdir = myinputdir + "nosigunc/";
  else if(nobkgunc) myinputdir = myinputdir + "nobkgunc/";
  
  TString outfilename = myoutputdir + "Limits2DHistograms.root";
  TFile *file = new TFile(outfilename, "recreate");
  file->cd();
  TH2F *hExp   = new TH2F("hExp",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs   = new TH2F("hObs",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1m = new TH2F("hExp1m", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2m = new TH2F("hExp2m", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1p = new TH2F("hExp1p", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2p = new TH2F("hExp2p", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpXsec   = new TH2F("hExpXsec",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsXsec   = new TH2F("hObsXsec",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mXsec = new TH2F("hExp1mXsec", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mXsec = new TH2F("hExp2mXsec", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pXsec = new TH2F("hExp1pXsec", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pXsec = new TH2F("hExp2pXsec", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPass   = new TH2F("hExpPass",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsPass   = new TH2F("hObsPass",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mPass = new TH2F("hExp1mPass", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mPass = new TH2F("hExp2mPass", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pPass = new TH2F("hExp1pPass", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pPass = new TH2F("hExp2pPass", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);

  for(int stop = mStopLow; stop<=mStopHigh; stop += mStopStep){
    for(int lsp = mLSPLow; lsp<=mLSPHigh; lsp += mLSPStep){
      TString limitfile = "Limits_Asymptotic_";
      if(prefit) limitfile = limitfile + "PreFit_";
      TString signalname = signaltype + "_" + std::to_string(stop) + "_" + std::to_string(lsp);
      limitfile = myinputdir + limitfile + signalname + ".root";
      cout << limitfile << endl;
      ifstream infile(limitfile.Data());
      bool exists = infile.good();
      if(!exists) {
	//cout << "No limit name for " << signalname << " - exit" << endl;
	continue;
      }
      cout << "Limit file exists for " << signalname << endl;
      double obs    = -1.0; //observed limit
      double expm2s = -1.0; //expected - 2 sigma
      double expm1s = -1.0; //expected - 1 sigma
      double exp    = -1.0; //expected limit
      double expp1s = -1.0; //expected + 1 sigma
      double expp2s = -1.0; //expected + 2 sigma
      
      TFile *flimit;
      flimit = new TFile(limitfile,"READ");
      if(flimit->IsZombie()) {
	flimit->Close();
	delete flimit;
	cout << "No limit file for " << signalname << " - exit" << endl;
	continue;
      }
      double xsec = hxsec->GetBinContent(hxsec->FindBin(stop));
      //so flimit exists
      flimit->cd();
      TTree *tlimit = (TTree*)flimit->Get("limit");
      double value = -1.0;
      tlimit->SetBranchAddress("limit", &value);
            
      for(int i=0; i< 6; i++){
	tlimit->GetEntry(i);
	if(i==0)      expm2s = value;
	else if(i==1) expm1s = value;
	else if(i==2) exp    = value;
	else if(i==3) expp1s = value;
	else if(i==4) expp2s = value;
	else if(i==5) obs    = value;
      }
      delete tlimit;
      flimit->Close();
      delete flimit;

      file->cd();
      hExp  ->Fill(stop,lsp,exp   );
      hExp2m->Fill(stop,lsp,expm2s);
      hExp1m->Fill(stop,lsp,expm1s);
      hExp1p->Fill(stop,lsp,expp1s);
      hExp2p->Fill(stop,lsp,expp2s);
      hObs  ->Fill(stop,lsp,obs   );
      hExpXsec  ->Fill(stop,lsp,xsec*exp   );
      hExp2mXsec->Fill(stop,lsp,xsec*expm2s);
      hExp1mXsec->Fill(stop,lsp,xsec*expm1s);
      hExp1pXsec->Fill(stop,lsp,xsec*expp1s);
      hExp2pXsec->Fill(stop,lsp,xsec*expp2s);
      hObsXsec  ->Fill(stop,lsp,xsec*obs   );
      if(exp   <1.) hExpPass  ->Fill(stop,lsp,1.);
      else          hExpPass  ->Fill(stop,lsp,0.);
      if(expm2s<1.) hExp2mPass->Fill(stop,lsp,1.);
      else          hExp2mPass->Fill(stop,lsp,0.);
      if(expm1s<1.) hExp1mPass->Fill(stop,lsp,1.);
      else          hExp1mPass->Fill(stop,lsp,0.);
      if(expp1s<1.) hExp1pPass->Fill(stop,lsp,1.);
      else          hExp1pPass->Fill(stop,lsp,0.);
      if(expp2s<1.) hExp2pPass->Fill(stop,lsp,1.);
      else          hExp2pPass->Fill(stop,lsp,0.);
      if(obs   <1.) hObsPass  ->Fill(stop,lsp,1.);
      else          hObsPass  ->Fill(stop,lsp,0.);
      
    }//lsp
  }//stop

  //based on h*Pass histograms get TGraphs

  file->cd();
  hExp   ->Write();
  hObs   ->Write();
  hExp1m ->Write();
  hExp2m ->Write();
  hExp1p ->Write();
  hExp2p ->Write();
  hExpXsec   ->Write();
  hObsXsec   ->Write();
  hExp1mXsec ->Write();
  hExp2mXsec ->Write();
  hExp1pXsec ->Write();
  hExp2pXsec ->Write();
  hExpPass   ->Write();
  hObsPass   ->Write();
  hExp1mPass ->Write();
  hExp2mPass ->Write();
  hExp1pPass ->Write();
  hExp2pPass ->Write();
  file->Close();

  fxsec->Close();
  delete fxsec;
  
}
