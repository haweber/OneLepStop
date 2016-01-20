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
#include "TGraph.h"
#include "TGraph2D.h"
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

void Make2DLimitHistos(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont);
TH2F* InterpolateThisHistogram(TH2F *hold);
TGraph2D* GetInterpolatingGraph(TH2F *hold);
TH2F* PassThisHistogram(TH2F *hold);
TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec);
TGraph* GetContour(TGraph2D *g, TString name);
inline TString MakeOutputDir(TString dir);

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}


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
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  if(dropsigcont) myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  cout << "make directory " << myoutputdir << endl;
  MakeOutputDir(myoutputdir);
  TString myinputdir = inputdir;
  if(compressed==1) myinputdir = myinputdir + "compressed/";
  if(nosigunc&&nobkgunc) myinputdir = myinputdir + "nounc/";
  else if(nosigunc) myinputdir = myinputdir + "nosigunc/";
  else if(nobkgunc) myinputdir = myinputdir + "nobkgunc/";
  if(dropsigcont) myinputdir = myinputdir + "dropsigcont/";
  if(fakedata)   myinputdir = myinputdir + "fakedata/";
  cout << "inputs from " << myinputdir << endl;

  TString outfilename = myoutputdir + "Limits2DHistograms.root";
  TFile *file = new TFile(outfilename, "recreate");
  file->cd();
  TH2F *hExpOrg   = new TH2F("hExpOrg",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsOrg   = new TH2F("hObsOrg",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pOrg = new TH2F("hObs1pOrg", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mOrg = new TH2F("hObs1mOrg", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mOrg = new TH2F("hExp1mOrg", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mOrg = new TH2F("hExp2mOrg", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pOrg = new TH2F("hExp1pOrg", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pOrg = new TH2F("hExp2pOrg", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpXsecOrg   = new TH2F("hExpXsecOrg",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsXsecOrg   = new TH2F("hObsXsecOrg",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pXsecOrg = new TH2F("hObs1pXsecOrg", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mXsecOrg = new TH2F("hObs1mXsecOrg", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mXsecOrg = new TH2F("hExp1mXsecOrg", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mXsecOrg = new TH2F("hExp2mXsecOrg", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pXsecOrg = new TH2F("hExp1pXsecOrg", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pXsecOrg = new TH2F("hExp2pXsecOrg", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPassOrg   = new TH2F("hExpPassOrg",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsPassOrg   = new TH2F("hObsPassOrg",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pPassOrg = new TH2F("hObs1pPassOrg", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mPassOrg = new TH2F("hObs1mPassOrg", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mPassOrg = new TH2F("hExp1mPassOrg", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mPassOrg = new TH2F("hExp2mPassOrg", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pPassOrg = new TH2F("hExp1pPassOrg", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pPassOrg = new TH2F("hExp2pPassOrg", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp   = new TH2F("hExp",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs   = new TH2F("hObs",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1p = new TH2F("hObs1p", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1m = new TH2F("hObs1m", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1m = new TH2F("hExp1m", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2m = new TH2F("hExp2m", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1p = new TH2F("hExp1p", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2p = new TH2F("hExp2p", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpXsec   = new TH2F("hExpXsec",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsXsec   = new TH2F("hObsXsec",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pXsec = new TH2F("hObs1pXsec", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mXsec = new TH2F("hObs1mXsec", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mXsec = new TH2F("hExp1mXsec", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mXsec = new TH2F("hExp2mXsec", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pXsec = new TH2F("hExp1pXsec", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pXsec = new TH2F("hExp2pXsec", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPass   = new TH2F("hExpPass",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsPass   = new TH2F("hObsPass",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pPass = new TH2F("hObs1pPass", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mPass = new TH2F("hObs1mPass", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mPass = new TH2F("hExp1mPass", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mPass = new TH2F("hExp2mPass", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pPass = new TH2F("hExp1pPass", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pPass = new TH2F("hExp2pPass", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  

  cout << "First create 2d limit histograms" << endl;
  for(int stop = mStopLow; stop<=mStopHigh; stop += mStopStep){
    for(int lsp = mLSPLow; lsp<=mLSPHigh; lsp += mLSPStep){
      TString limitfilebase = "Limits_Asymptotic_";
      if(prefit) limitfilebase = limitfilebase + "PreFit_";
      TString signalname = signaltype + "_" + std::to_string(stop) + "_" + std::to_string(lsp);
      TString limitfile = myinputdir + limitfilebase + signalname + ".root";
      //cout << limitfile << endl;
      ifstream infile(limitfile.Data());
      bool exists = infile.good();
      if(!exists) {
	//cout << "No limit name for " << signalname << " - exit" << endl;
	continue;
      }
      cout << "Limit file exists for " << signalname << endl;
      double obs    = -1.0; //observed limit
      double obsm1s  = -1.0; //observed limit - 1 sigma theory
      double obsp1s = -1.0; //observed limit + 1 sigma theory
      double expm2s = -1.0; //expected - 2 sigma
      double expm1s = -1.0; //expected - 1 sigma
      double exp    = -1.0; //expected limit
      double expp1s = -1.0; //expected + 1 sigma
      double expp2s = -1.0; //expected + 2 sigma
      
      double xsec = hxsec->GetBinContent(hxsec->FindBin(stop));
      double xsecunc = hxsec->GetBinError(hxsec->FindBin(stop));
      TFile *flimit;
      flimit = new TFile(limitfile,"READ");
      if(flimit->IsZombie()) {
	flimit->Close();
	delete flimit;
	cout << "No limit file for " << signalname << " - exit" << endl;
	continue;
      }
      //so flimit exists
      flimit->cd();
      TTree *tlimit = (TTree*)flimit->Get("limit");
      double value = -1.0;
      tlimit->SetBranchAddress("limit", &value);
      
      for(int i=0; i< 6; i++){
	tlimit->GetEntry(i);
	//cout << "stop " << stop << " lsp " << lsp << " i " << i << " value " << value << endl;
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
      hExpOrg  ->Fill(stop,lsp,exp   );
      hExp2mOrg->Fill(stop,lsp,expm2s);
      hExp1mOrg->Fill(stop,lsp,expm1s);
      hExp1pOrg->Fill(stop,lsp,expp1s);
      hExp2pOrg->Fill(stop,lsp,expp2s);
      hObsOrg  ->Fill(stop,lsp,obs   );
      //xsecupdown
      hObs1pOrg->Fill(stop,lsp,obs*xsec/(xsec+xsecunc)   );
      hObs1mOrg->Fill(stop,lsp,obs*xsec/(xsec-xsecunc)   );
    }//lsp
  }//stop
  cout << "Now interpolate these histograms" << endl;  
  hExp   = (TH2F*)InterpolateThisHistogram(hExpOrg);
  hExp2m = (TH2F*)InterpolateThisHistogram(hExp2mOrg);
  hExp1m = (TH2F*)InterpolateThisHistogram(hExp1mOrg);
  hExp1p = (TH2F*)InterpolateThisHistogram(hExp1pOrg);
  hExp2m = (TH2F*)InterpolateThisHistogram(hExp2mOrg);
  hObs   = (TH2F*)InterpolateThisHistogram(hObsOrg);
  hObs1m = (TH2F*)InterpolateThisHistogram(hObs1mOrg);
  hObs1p = (TH2F*)InterpolateThisHistogram(hObs1pOrg);

  TGraph2D *g2Exp   = (TGraph2D*)GetInterpolatingGraph(hExpOrg);
  TGraph2D *g2Exp2m = (TGraph2D*)GetInterpolatingGraph(hExp2mOrg);
  TGraph2D *g2Exp1m = (TGraph2D*)GetInterpolatingGraph(hExp1mOrg);
  TGraph2D *g2Exp1p = (TGraph2D*)GetInterpolatingGraph(hExp1pOrg);
  TGraph2D *g2Exp2p = (TGraph2D*)GetInterpolatingGraph(hExp2pOrg);
  TGraph2D *g2Obs   = (TGraph2D*)GetInterpolatingGraph(hObsOrg);
  TGraph2D *g2Obs1m = (TGraph2D*)GetInterpolatingGraph(hObs1mOrg);
  TGraph2D *g2Obs1p = (TGraph2D*)GetInterpolatingGraph(hObs1pOrg);
  
  cout << "Now get pass/fail histograms" << endl;
  hExpPass   = (TH2F*)PassThisHistogram(hExp);
  hExp2mPass = (TH2F*)PassThisHistogram(hExp2m);
  hExp1mPass = (TH2F*)PassThisHistogram(hExp1m);
  hExp1pPass = (TH2F*)PassThisHistogram(hExp1p);
  hExp2pPass = (TH2F*)PassThisHistogram(hExp2p);
  hObsPass   = (TH2F*)PassThisHistogram(hObs);
  hObs1mPass = (TH2F*)PassThisHistogram(hObs1m);
  hObs1pPass = (TH2F*)PassThisHistogram(hObs1p);
  hExpPassOrg   = (TH2F*)PassThisHistogram(hExpOrg);
  hExp2mPassOrg = (TH2F*)PassThisHistogram(hExp2mOrg);
  hExp1mPassOrg = (TH2F*)PassThisHistogram(hExp1mOrg);
  hExp1pPassOrg = (TH2F*)PassThisHistogram(hExp1pOrg);
  hExp2pPassOrg = (TH2F*)PassThisHistogram(hExp2pOrg);
  hObsPassOrg   = (TH2F*)PassThisHistogram(hObsOrg);
  hObs1mPassOrg = (TH2F*)PassThisHistogram(hObs1mOrg);
  hObs1pPassOrg = (TH2F*)PassThisHistogram(hObs1pOrg);
  cout << "Now get cross section histograms" << endl;
  hExpXsec   = (TH2F*)XsecThisHistogram(hExp, hxsec);
  hExp2mXsec = (TH2F*)XsecThisHistogram(hExp2m, hxsec);
  hExp1mXsec = (TH2F*)XsecThisHistogram(hExp1m, hxsec);
  hExp1pXsec = (TH2F*)XsecThisHistogram(hExp1p, hxsec);
  hExp2pXsec = (TH2F*)XsecThisHistogram(hExp2p, hxsec);
  hObsXsec   = (TH2F*)XsecThisHistogram(hObs, hxsec);
  hObs1mXsec = (TH2F*)XsecThisHistogram(hObs1m, hxsec);
  hObs1pXsec = (TH2F*)XsecThisHistogram(hObs1p, hxsec);
  hExpXsecOrg   = (TH2F*)XsecThisHistogram(hExpOrg, hxsec);
  hExp2mXsecOrg = (TH2F*)XsecThisHistogram(hExp2mOrg, hxsec);
  hExp1mXsecOrg = (TH2F*)XsecThisHistogram(hExp1mOrg, hxsec);
  hExp1pXsecOrg = (TH2F*)XsecThisHistogram(hExp1pOrg, hxsec);
  hExp2pXsecOrg = (TH2F*)XsecThisHistogram(hExp2pOrg, hxsec);
  hObsXsecOrg   = (TH2F*)XsecThisHistogram(hObsOrg, hxsec);
  hObs1mXsecOrg = (TH2F*)XsecThisHistogram(hObs1mOrg, hxsec);
  hObs1pXsecOrg = (TH2F*)XsecThisHistogram(hObs1pOrg, hxsec);
  //this is stupid, but I don't want empty 0 axis
  for(unsigned int i = 1; i<=hExpXsec->GetNbinsX(); ++i){
    if(hExpXsec->GetBinContent(i,1)==0 && hExpXsec->GetBinContent(i,2)>0) hExpXsec->SetBinContent(i,1,hExpXsec->GetBinContent(i,2));
  }
  for(unsigned int i = 1; i<=hExpXsec->GetNbinsY(); ++i){
    if(hExpXsec->GetBinContent(1,i)==0 && hExpXsec->GetBinContent(2,i)>0) hExpXsec->SetBinContent(1,i,hExpXsec->GetBinContent(2,i));
  }
  cout << "Get contours" << endl;
  TGraph *gExp_c   = (TGraph*)GetContour(g2Exp, "gExp");
  //cout << "gExp_c " << gExp_c->GetName() << " " << gExp_c->GetN() << endl;
  TGraph *gExp2m_c = (TGraph*)GetContour(g2Exp2m, "gExp2m");
  TGraph *gExp1m_c = (TGraph*)GetContour(g2Exp1m, "gExp1m");
  TGraph *gExp1p_c = (TGraph*)GetContour(g2Exp1p, "gExp1p");
  TGraph *gExp2p_c = (TGraph*)GetContour(g2Exp2p, "gExp2p");
  TGraph *gObs_c   = (TGraph*)GetContour(g2Obs, "gObs");
  TGraph *gObs1m_c = (TGraph*)GetContour(g2Obs1m, "gObs1m");
  TGraph *gObs1p_c = (TGraph*)GetContour(g2Obs1p, "gObs1p");

  TGraph *gEmpty = new TGraph();//empty graph for suppressing obs in limit plots
  gEmpty->SetName("gEmpty");
  gEmpty->SetPoint(0,-100,-100);
  gEmpty->SetPoint(1,-200,-200);
  
  
  file->cd();
  hExpOrg   ->Write();
  hObsOrg   ->Write();
  hObs1mOrg ->Write();
  hObs1pOrg ->Write();
  hExp1mOrg ->Write();
  hExp2mOrg ->Write();
  hExp1pOrg ->Write();
  hExp2pOrg ->Write();
  hExpXsecOrg   ->Write();
  hObsXsecOrg   ->Write();
  hObs1mXsecOrg ->Write();
  hObs1pXsecOrg ->Write();
  hExp1mXsecOrg ->Write();
  hExp2mXsecOrg ->Write();
  hExp1pXsecOrg ->Write();
  hExp2pXsecOrg ->Write();
  hExpPassOrg   ->Write();
  hObsPassOrg   ->Write();
  hObs1mPassOrg ->Write();
  hObs1pPassOrg ->Write();
  hExp1mPassOrg ->Write();
  hExp2mPassOrg ->Write();
  hExp1pPassOrg ->Write();
  hExp2pPassOrg ->Write();
  hExp   ->Write();
  hObs   ->Write();
  hObs1m ->Write();
  hObs1p ->Write();
  hExp1m ->Write();
  hExp2m ->Write();
  hExp1p ->Write();
  hExp2p ->Write();
  hExpXsec   ->Write();
  hObsXsec   ->Write();
  hObs1mXsec ->Write();
  hObs1pXsec ->Write();
  hExp1mXsec ->Write();
  hExp2mXsec ->Write();
  hExp1pXsec ->Write();
  hExp2pXsec ->Write();
  hExpPass   ->Write();
  hObsPass   ->Write();
  hObs1mPass ->Write();
  hObs1pPass ->Write();
  hExp1mPass ->Write();
  hExp2mPass ->Write();
  hExp1pPass ->Write();
  hExp2pPass ->Write();

  g2Exp   ->Write();
  g2Obs   ->Write();
  g2Obs1m ->Write();
  g2Obs1p ->Write();
  g2Exp1m ->Write();
  g2Exp2m ->Write();
  g2Exp1p ->Write();
  g2Exp2p ->Write();
  gExp_c   ->Write();
  gObs_c   ->Write();
  gObs1m_c ->Write();
  gObs1p_c ->Write();
  gExp1m_c ->Write();
  gExp2m_c ->Write();
  gExp1p_c ->Write();
  gExp2p_c ->Write();
  gEmpty->Write();
  file->Close();
  cout << "Saved all histos in  " << file->GetName() << endl;

  fxsec->Close();
  delete fxsec;
  
}


TH2F* InterpolateThisHistogram(TH2F *hold/*, TH2F* hnew*/){
  float binsize = hold->GetXaxis()->GetBinWidth(1)/2.;
  TString name = hold->GetName();
  name.ReplaceAll("Org","");
  TGraph2D *g = new TGraph2D(hold);
  g->SetNpx(int(g->GetXmax()-g->GetXmin())/binsize);
  g->SetNpy(int(g->GetYmax()-g->GetYmin())/binsize);
  TH2F *hnew = (TH2F*)g->GetHistogram();
  TH2F *h = (TH2F*)hnew->Clone(name);
  delete g;
  return h;
}

TGraph2D* GetInterpolatingGraph(TH2F *hold){
  float binsize = hold->GetXaxis()->GetBinWidth(1)/2.;
  TString name = hold->GetName();
  name.ReplaceAll("Org","");
  TGraph2D *g = new TGraph2D(hold);
  g->SetNpx(int(g->GetXmax()-g->GetXmin())/binsize);
  g->SetNpy(int(g->GetYmax()-g->GetYmin())/binsize);
  //cout << "name " << g->GetN() << " " << hold->Integral() << endl;
  return g;
}

TH2F* PassThisHistogram(TH2F *hold){
  TString name = hold->GetName() + (TString)"Pass";
  TH2F *hnew = (TH2F*)hold->Clone(name);
  for(int x = 1; x<=hnew->GetNbinsX(); ++x){
    for(int y = 1; y<=hnew->GetNbinsY(); ++y){
      float val = hnew->GetBinContent(x,y);
      float pass = 0;
      if(val>1) pass = 0.001;
      else if(val>0) pass = 1;
      hnew->SetBinContent(x,y,pass);
    }
  }
  return hnew;
}

TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec){
  TString name = hold->GetName() + (TString)"Xsec";
  TH2F *hnew = (TH2F*)hold->Clone(name);
  for(int x = 1; x<=hnew->GetNbinsX(); ++x){
    for(int y = 1; y<=hnew->GetNbinsY(); ++y){
      float val = hnew->GetBinContent(x,y);
      float mstop = hnew->GetXaxis()->GetBinLowEdge(x);
      //cout << "check " << "bin " << x << " gets me mstop " << mstop << endl;
      float xsec = hxsec->GetBinContent(hxsec->FindBin(mstop));
      hnew->SetBinContent(x,y,val*xsec);
    }
  }
  return hnew;
}

TGraph* GetContour(TGraph2D *g, TString name){
  TGraph *gnew;
  //cout << g->GetName() << " " << g->GetN() << endl;
  TH2D *temp = (TH2D*)g->GetHistogram();//need this for list to work?
  //g->Draw("alp");//need this for list to work?
  TList *glist = (TList*)g->GetContourList(1.0);
  if(glist == nullptr) return gnew;
  int max_points = -1;
  int nn = glist->GetSize();
  //cout << "number of entries in list " << nn << endl;
  for(int i = 0; i<glist->GetSize(); ++i){
    TGraph *gtemp = (TGraph*)glist->At(i);
    int Npoints = gtemp->GetN();
    if(Npoints>max_points){
      gnew = (TGraph*)gtemp->Clone(name);
      max_points = Npoints;
    }
  }
  return gnew;
}
