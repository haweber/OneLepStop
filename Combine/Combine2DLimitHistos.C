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

TString inputdir = "/hadoop/cms/store/user/haweber/condor/limits2017_36p6fbinv_SUS16051/";
TString outputdir = "rootfiles2017_36p6fbinv_SUS16051/";

void Combine2DLimitHistos(TString signaltype, TString combine1, TString combine2, float DM2choice, bool prefit=false, bool fakedata=false, bool nosigunc=false, bool nobkgunc=false, bool dropsigcont=false, bool correlated=true);
TH2F* InterpolateThisHistogram(TH2F *hold);
TGraph2D* GetInterpolatingGraph(TH2F *hold);
TH2F* PassThisHistogram(TH2F *hold);
TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec);
TGraph* GetContour(TGraph2D *g, TString name, TGraph *gempty);
TGraph* GetContour2(TGraph2D *g, TString name, TGraph *gempty);

void Combine2DLimitHistos(TString signaltype, TString combine1, TString combine2, float DM2choice, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, bool dropsigcont, bool correlated){

  TH1D *hxsec;
  TFile *fxsec = new TFile("xsec_stop_13TeV.root","READ");
  if(fxsec->IsZombie()) {
    std::cout << "Somehow xsec_stop_13TeV.root is corrupted. Exit..." << std::endl;
    exit(0);
  }
  hxsec = (TH1D*)fxsec->Get("stop");
  
  int mStopLow  = 100;
  int mStopHigh = 1250;
  int mStopStep = 25;
  int mLSPLow   = 0;
  int mLSPHigh  = 700;
  int mLSPStep  = 25;
  int nbinsx = (mStopHigh - mStopLow)/mStopStep;
  int nbinsy = (mLSPHigh - mLSPLow)/mLSPStep;
  
  TString myoutputdir = outputdir;
  if(correlated) myoutputdir = myoutputdir + "correlated/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  if(dropsigcont) myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  //cout << "make directory " << myoutputdir << endl;//already exists
  //MakeOutputDir(myoutputdir);

  TString inputfile1 = myoutputdir + "Limits2DHistograms_"+combine1+"_"+signaltype+"_prefit.root";
  TString inputfile2 = myoutputdir + "Limits2DHistograms_"+combine2+"_"+signaltype+"_prefit.root";
  if(!prefit){
    inputfile1 = myoutputdir + "Limits2DHistograms_"+combine1+"_"+signaltype+"_postfit.root";
    inputfile2 = myoutputdir + "Limits2DHistograms_"+combine2+"_"+signaltype+"_postfit.root";    
  }
  TFile *f1 = TFile::Open(inputfile1);
  TH2F *hExpOrg_t1   = (TH2F*)f1->Get("hExpOrg");   hExpOrg_t1  ->SetName("hExpOrg_t1");
  TH2F *hObsOrg_t1   = (TH2F*)f1->Get("hObsOrg");   hObsOrg_t1  ->SetName("hObsOrg_t1");
  TH2F *hObs1pOrg_t1 = (TH2F*)f1->Get("hObs1pOrg"); hObs1pOrg_t1->SetName("hObs1pOrg_t1");
  TH2F *hObs1mOrg_t1 = (TH2F*)f1->Get("hObs1mOrg"); hObs1mOrg_t1->SetName("hObs1mOrg_t1");
  TH2F *hExp1mOrg_t1 = (TH2F*)f1->Get("hExp1mOrg"); hExp1mOrg_t1->SetName("hExp1mOrg_t1");
  TH2F *hExp2mOrg_t1 = (TH2F*)f1->Get("hExp2mOrg"); hExp2mOrg_t1->SetName("hExp2mOrg_t1");
  TH2F *hExp1pOrg_t1 = (TH2F*)f1->Get("hExp1pOrg"); hExp1pOrg_t1->SetName("hExp1pOrg_t1");
  TH2F *hExp2pOrg_t1 = (TH2F*)f1->Get("hExp2pOrg"); hExp2pOrg_t1->SetName("hExp2pOrg_t1");
  TFile *f2 = TFile::Open(inputfile2);
  TH2F *hExpOrg_t2   = (TH2F*)f2->Get("hExpOrg");   hExpOrg_t2  ->SetName("hExpOrg_t2");
  TH2F *hObsOrg_t2   = (TH2F*)f2->Get("hObsOrg");   hObsOrg_t2  ->SetName("hObsOrg_t2");
  TH2F *hObs1pOrg_t2 = (TH2F*)f2->Get("hObs1pOrg"); hObs1pOrg_t2->SetName("hObs1pOrg_t2");
  TH2F *hObs1mOrg_t2 = (TH2F*)f2->Get("hObs1mOrg"); hObs1mOrg_t2->SetName("hObs1mOrg_t2");
  TH2F *hExp1mOrg_t2 = (TH2F*)f2->Get("hExp1mOrg"); hExp1mOrg_t2->SetName("hExp1mOrg_t2");
  TH2F *hExp2mOrg_t2 = (TH2F*)f2->Get("hExp2mOrg"); hExp2mOrg_t2->SetName("hExp2mOrg_t2");
  TH2F *hExp1pOrg_t2 = (TH2F*)f2->Get("hExp1pOrg"); hExp1pOrg_t2->SetName("hExp1pOrg_t2");
  TH2F *hExp2pOrg_t2 = (TH2F*)f2->Get("hExp2pOrg"); hExp2pOrg_t2->SetName("hExp2pOrg_t2");
  cout << f1->GetName() << " " << f2->GetName() << endl;
  //establish that histos can be combined easily
  if(hExpOrg_t1->GetNbinsX()!=nbinsx){ cout << "nbinsX different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hExpOrg_t2->GetNbinsX()!=nbinsx){ cout << "nbinsX different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hExpOrg_t1->GetNbinsY()!=nbinsy){ cout << "nbinsY different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hExpOrg_t2->GetNbinsY()!=nbinsy){ cout << "nbinsY different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t1->GetXaxis()->GetBinLowEdge(1)!=mStopLow){ cout << "starting bin X different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t2->GetXaxis()->GetBinLowEdge(1)!=mStopLow){ cout << "starting bin X different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t1->GetYaxis()->GetBinLowEdge(1)!=mLSPLow){ cout << "starting bin Y different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t2->GetYaxis()->GetBinLowEdge(1)!=mLSPLow){ cout << "starting bin Y different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t1->GetXaxis()->GetBinWidth(1)!=mStopStep){ cout << "bin width X different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t2->GetXaxis()->GetBinWidth(1)!=mStopStep){ cout << "bin width X different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t1->GetYaxis()->GetBinWidth(1)!=mLSPStep){ cout << "bin width Y different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hExpOrg_t2->GetYaxis()->GetBinWidth(1)!=mLSPStep){ cout << "bin width Y different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }

  
  TString outfilename = myoutputdir + "Limits2DHistograms_combined_"+signaltype+"_prefit.root";
  if(!prefit) outfilename = myoutputdir + "Limits2DHistograms_combined_"+signaltype+"_postfit.root";
  TFile *file = new TFile(outfilename, "recreate");
  file->cd();
  TH2F *hBestAnalysis   = new TH2F("hBestAnalysis",   "hBestAnalysis"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
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
  for(int x = 1; x<=nbinsx; ++x){
    for(int y = 1; y<=nbinsx; ++y){
      if(hExpOrg->GetXaxis()->GetBinLowEdge(x)<hExpOrg->GetYaxis()->GetBinLowEdge(y)) continue;
      int whichanalysis = -1;
      if(DM2choice<0){//choose on better expected limit
	if(hExpOrg_t1->GetBinContent(x,y)<hExpOrg_t2->GetBinContent(x,y)) whichanalysis = 1;
	else whichanalysis = 2;
      } else {
	float stop = hExpOrg->GetXaxis()->GetBinLowEdge(x);//should I use low edge or bin center?
	float lsp = hExpOrg->GetYaxis()->GetBinLowEdge(y);//should I use low edge or bin center?
	if((stop-lsp)>DM2choice) whichanalysis = 1;
	else whichanalysis = 2;
      }
      cout << hExpOrg->GetXaxis()->GetBinLowEdge(x) << "-" << hExpOrg->GetYaxis()->GetBinLowEdge(y) << " uses analysis " << whichanalysis << endl;
      if(whichanalysis==1){
	hObsOrg      ->SetBinContent(x,y,hObsOrg_t1  ->GetBinContent(x,y));
	hObs1pOrg    ->SetBinContent(x,y,hObs1pOrg_t1->GetBinContent(x,y));
	hObs1mOrg    ->SetBinContent(x,y,hObs1mOrg_t1->GetBinContent(x,y));
	hExpOrg      ->SetBinContent(x,y,hExpOrg_t1  ->GetBinContent(x,y));
	hExp1mOrg    ->SetBinContent(x,y,hExp1mOrg_t1->GetBinContent(x,y));
	hExp2mOrg    ->SetBinContent(x,y,hExp2mOrg_t1->GetBinContent(x,y));
	hExp1pOrg    ->SetBinContent(x,y,hExp1pOrg_t1->GetBinContent(x,y));
	hExp2pOrg    ->SetBinContent(x,y,hExp2pOrg_t1->GetBinContent(x,y));
	hBestAnalysis->SetBinContent(x,y,1);
      } else if(whichanalysis==2){
	hObsOrg      ->SetBinContent(x,y,hObsOrg_t2  ->GetBinContent(x,y));
	hObs1pOrg    ->SetBinContent(x,y,hObs1pOrg_t2->GetBinContent(x,y));
	hObs1mOrg    ->SetBinContent(x,y,hObs1mOrg_t2->GetBinContent(x,y));
	hExpOrg      ->SetBinContent(x,y,hExpOrg_t2  ->GetBinContent(x,y));
	hExp1mOrg    ->SetBinContent(x,y,hExp1mOrg_t2->GetBinContent(x,y));
	hExp2mOrg    ->SetBinContent(x,y,hExp2mOrg_t2->GetBinContent(x,y));
	hExp1pOrg    ->SetBinContent(x,y,hExp1pOrg_t2->GetBinContent(x,y));
	hExp2pOrg    ->SetBinContent(x,y,hExp2pOrg_t2->GetBinContent(x,y));
	hBestAnalysis->SetBinContent(x,y,2);
      }
    }//y
  }//x

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
  TGraph *gEmpty = new TGraph();//empty graph for suppressing obs in limit plots
  gEmpty->SetName("gEmpty");
  gEmpty->SetPoint(0,-100,-100);
  gEmpty->SetPoint(1,-200,-200);
  
  cout << "Get contours" << endl;
  TGraph *gExp_c   = (TGraph*)GetContour(g2Exp, "gExp", gEmpty);
  TGraph *gExp2m_c = (TGraph*)GetContour(g2Exp2m, "gExp2m", gEmpty);
  TGraph *gExp1m_c = (TGraph*)GetContour(g2Exp1m, "gExp1m", gEmpty);
  TGraph *gExp1p_c = (TGraph*)GetContour(g2Exp1p, "gExp1p", gEmpty);
  TGraph *gExp2p_c = (TGraph*)GetContour(g2Exp2p, "gExp2p", gEmpty);
  TGraph *gObs_c   = (TGraph*)GetContour(g2Obs, "gObs", gEmpty);
  TGraph *gObs1m_c = (TGraph*)GetContour(g2Obs1m, "gObs1m", gEmpty);
  TGraph *gObs1p_c = (TGraph*)GetContour(g2Obs1p, "gObs1p", gEmpty);
  TGraph *gExp_c2   = (TGraph*)GetContour2(g2Exp, "gExp_2", gEmpty);
  TGraph *gExp2m_c2 = (TGraph*)GetContour2(g2Exp2m, "gExp2m_2", gEmpty);
  TGraph *gExp1m_c2 = (TGraph*)GetContour2(g2Exp1m, "gExp1m_2", gEmpty);
  TGraph *gExp1p_c2 = (TGraph*)GetContour2(g2Exp1p, "gExp1p_2", gEmpty);
  TGraph *gExp2p_c2 = (TGraph*)GetContour2(g2Exp2p, "gExp2p_2", gEmpty);
  TGraph *gObs_c2   = (TGraph*)GetContour2(g2Obs, "gObs_2", gEmpty);
  TGraph *gObs1m_c2 = (TGraph*)GetContour2(g2Obs1m, "gObs1m_2", gEmpty);
  TGraph *gObs1p_c2 = (TGraph*)GetContour2(g2Obs1p, "gObs1p_2", gEmpty);

  
  file->cd();
  hBestAnalysis->Write();
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
  gExp_c2   ->Write();
  gObs_c2   ->Write();
  gObs1m_c2 ->Write();
  gObs1p_c2 ->Write();
  gExp1m_c2 ->Write();
  gExp2m_c2 ->Write();
  gExp1p_c2 ->Write();
  gExp2p_c2 ->Write();
  gEmpty->Write();
  file->Close();
  cout << "Saved all histos in  " << file->GetName() << endl;

  f1->Close();
  f2->Close();
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
  TH2F *h = new TH2F(name.Data(),hold->GetTitle(),hnew->GetNbinsX(),g->GetXmin()-binsize,g->GetXmax()-binsize,hnew->GetNbinsY(),g->GetYmin()-binsize,g->GetYmax()-binsize);
  for(unsigned int x = 1; x<=hnew->GetNbinsX(); ++x){
    for(unsigned int y = 1; y<=hnew->GetNbinsY(); ++y){
      h->SetBinContent(x,y,hnew->GetBinContent(x,y));
    }
  }
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
      float xsec = hxsec->GetBinContent(hxsec->FindBin(mstop));
      hnew->SetBinContent(x,y,val*xsec);
    }
  }
  return hnew;
}

TGraph* GetContour(TGraph2D *g, TString name, TGraph *gempty){
  TGraph *gnew;
  TH2D *temp = (TH2D*)g->GetHistogram();//need this for list to work?
  //g->Draw("alp");//need this for list to work?
  TList *glist = (TList*)g->GetContourList(1.0);
  if(glist == nullptr) {gnew = (TGraph*)gempty->Clone(name); return gnew; }
  if(glist->GetSize()==0) {gnew = (TGraph*)gempty->Clone(name); return gnew; }
  int max_points = -1;
  int nn = glist->GetSize();
  for(int i = 0; i<glist->GetSize(); ++i){
    TGraph *gtemp = (TGraph*)glist->At(i);
    int Npoints = gtemp->GetN();
    if(Npoints>max_points){
      gnew = (TGraph*)gtemp->Clone(name);
      max_points = Npoints;
      if(gnew->GetN()>0){
	double x,y;
	gnew->GetPoint(0,x,y);
	if(y<13.) gnew->SetPoint(0,x,0);
	gnew->GetPoint(gnew->GetN()-1,x,y);
	if(y<13.) { gnew->SetPoint(gnew->GetN(),x,0); }//they way ROOT does the interpolation the LSP = 0 strip becomes empty
      }
    }
  }
  return gnew;
}

TGraph* GetContour2(TGraph2D *g, TString name, TGraph *gempty){
  TGraph *gnew;
  TH2D *temp = (TH2D*)g->GetHistogram();//need this for list to work?
  //g->Draw("alp");//need this for list to work?
  TList *glist = (TList*)g->GetContourList(1.0);
  if(glist == nullptr) {gnew = (TGraph*)gempty->Clone(name); return gnew; }
  if(glist->GetSize()==0) {gnew = (TGraph*)gempty->Clone(name); return gnew; }
  int max_points = -1;
  int nn = glist->GetSize();
  int noti = -1;
  //cout << "number of entries in list " << nn << endl;
  for(int i = 0; i<glist->GetSize(); ++i){
    TGraph *gtemp = (TGraph*)glist->At(i);
    int Npoints = gtemp->GetN();
    if(Npoints>max_points){
      gnew = (TGraph*)gtemp->Clone(name);
      max_points = Npoints;
      noti = i;
      if(gnew->GetN()>0){
	double x,y;
	gnew->GetPoint(0,x,y);
	if(y<13.) gnew->SetPoint(0,x,0);
	gnew->GetPoint(gnew->GetN()-1,x,y);
	if(y<13.) { gnew->SetPoint(gnew->GetN(),x,0);}//they way ROOT does the interpolation the LSP = 0 strip becomes empty
      }
    }
  }
  max_points = -1;
  for(int i = 0; i<glist->GetSize(); ++i){
    if(i==noti&&glist->GetSize()>1) continue;
    TGraph *gtemp = (TGraph*)glist->At(i);
    int Npoints = gtemp->GetN();
    if(Npoints>max_points){
      gnew = (TGraph*)gtemp->Clone(name);
      max_points = Npoints;
      if(gnew->GetN()>0){
	double x,y;
	gnew->GetPoint(0,x,y);
	if(y<13.) gnew->SetPoint(0,x,0);
	gnew->GetPoint(gnew->GetN()-1,x,y);
	if(y<13.) { gnew->SetPoint(gnew->GetN(),x,0);}//they way ROOT does the interpolation the LSP = 0 strip becomes empty
      }
    }
  }
  return gnew;
}
