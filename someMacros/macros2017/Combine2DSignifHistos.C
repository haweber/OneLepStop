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
#include "RooStats/RooStatsUtils.h"

using namespace std;

TString inputdir = "/hadoop/cms/store/user/haweber/condor/significances_12p7fbinv/";
TString outputdir = "rootfiles2016_12p7fbinv/";

void Combine2DSignifHistos(TString signaltype, TString combine1, TString combine2, float DM2choice, bool fakedata=false, bool nosigunc=false, bool nobkgunc=false, bool dropsigcont=false, bool correlated=true);
TH2F* InterpolateThisHistogram(TH2F *hold);
TGraph2D* GetInterpolatingGraph(TH2F *hold);
TH2F* PassThisHistogram(TH2F *hold);
TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec);
TGraph* GetContour(TGraph2D *g, TString name);

//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02

void Combine2DSignifHistos(TString signaltype, TString combine1, TString combine2, float DM2choice, bool fakedata=false, bool nosigunc=false, bool nobkgunc=false, bool dropsigcont=false, bool correlated=true){

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
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  if(dropsigcont) myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  //cout << "make directory " << myoutputdir << endl;
  //MakeOutputDir(myoutputdir);

  TString inputfile1 = myoutputdir + "Significances2DHistograms_"+combine1+"_"+signaltype+".root";
  TString inputfile2 = myoutputdir + "Significances2DHistograms_"+combine2+"_"+signaltype+".root";
  TFile *f1 = TFile::Open(inputfile1);
  TH2F *hExpPosterioriOrg_t1   = (TH2F*)f1->Get("hExpPosterioriOrg");   hExpPosterioriOrg_t1  ->SetName("hExpPosterioriOrg_t1");
  TH2F *hExpPrioriOrg_t1       = (TH2F*)f1->Get("hExpPrioriOrg");       hExpPrioriOrg_t1      ->SetName("hExpPrioriOrg_t1");
  TH2F *hObsOrg_t1             = (TH2F*)f1->Get("hObsOrg");             hObsOrg_t1            ->SetName("hObsOrg_t1");
  TFile *f2 = TFile::Open(inputfile2);
  TH2F *hExpPosterioriOrg_t2   = (TH2F*)f2->Get("hExpPosterioriOrg");   hExpPosterioriOrg_t2  ->SetName("hExpPosterioriOrg_t2");
  TH2F *hExpPrioriOrg_t2       = (TH2F*)f2->Get("hExpPrioriOrg");       hExpPrioriOrg_t2      ->SetName("hExpPrioriOrg_t2");
  TH2F *hObsOrg_t2             = (TH2F*)f2->Get("hObsOrg");             hObsOrg_t2            ->SetName("hObsOrg_t2");
  if(hObsOrg_t1->GetNbinsX()!=nbinsx){ cout << "nbinsX different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hObsOrg_t2->GetNbinsX()!=nbinsx){ cout << "nbinsX different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hObsOrg_t1->GetNbinsY()!=nbinsy){ cout << "nbinsY different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if(hObsOrg_t2->GetNbinsY()!=nbinsy){ cout << "nbinsY different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t1->GetXaxis()->BinLowEdge(1)!=mStopLow){ cout << "starting bin X different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t2->GetXaxis()->BinLowEdge(1)!=mStopLow){ cout << "starting bin X different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t1->GetYaxis()->BinLowEdge(1)!=mLSPLow){ cout << "starting bin Y different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t2->GetYaxis()->BinLowEdge(1)!=mLSPLow){ cout << "starting bin Y different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t1->GetXaxis()->BinWidth(1)!=mStopStep){ cout << "bin width X different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t2->GetXaxis()->BinWidth(1)!=mStopStep){ cout << "bin width X different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t1->GetYaxis()->BinWidth(1)!=mLSPStep){ cout << "bin width Y different for input1 - exit"; f1->Close(); f2->Close(); exit(0); }
  if((int)hObsOrg_t2->GetYaxis()->BinWidth(1)!=mLSPStep){ cout << "bin width Y different for input2 - exit"; f1->Close(); f2->Close(); exit(0); }


  TString outfilename = myoutputdir + "Significances2DHistograms_combined_"+signaltype+".root";
  TFile *file = new TFile(outfilename, "recreate");
  file->cd();
  TH2F *hBestAnalysis       = new TH2F("hBestAnalysis",      "hBestAnalysis"     , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPosterioriOrg   = new TH2F("hExpPosterioriOrg",  "hExpPosterioriOrg" , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPrioriOrg       = new TH2F("hExpPrioriOrg",      "hExpPrioriOrg"     , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsOrg             = new TH2F("hObsOrg",            "hObsOrg"           , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpExpPosterioriOrg  = new TH2F("hpExpPosterioriOrg", "hpExpPosterioriOrg", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpExpPrioriOrg      = new TH2F("hpExpPrioriOrg",     "hpExpPrioriOrg"    , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpObsOrg            = new TH2F("hpObsOrg",           "hpObsOrg"          , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPosteriori   = new TH2F("hExpPosteriori",  "hExpPosteriori" , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPriori       = new TH2F("hExpPriori",      "hExpPriori"     , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs             = new TH2F("hObs",            "hObs"           , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpExpPosteriori  = new TH2F("hpExpPosteriori", "hpExpPosteriori", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpExpPriori      = new TH2F("hpExpPriori",     "hpExpPriori"    , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hpObs            = new TH2F("hpObs",           "hpObs"          , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);

  cout << "First create 2d limit histograms" << endl;
  for(int x = 1; x<=nbinsx; ++x){
    for(int y = 1; y<=nbinsx; ++y){
      int whichanalysis = -1;
      if(DM2choice<0){//choose on better expected limit
	if(hExpPrioriOrg_t1->GetBinContent(x,y)>hExpPrioriOrg_t2->GetBinContent(x,y)) whichanalysis = 1;
	else whichanalysis = 2;
      } else {
	float stop = hExpPrioriOrg->GetXaxis()->GetBinLowCenter(x);//should I use low edge or bin center?
	float lsp = hExpPrioriOrg->GetXaxis()->GetBinLowCenter(y);//should I use low edge or bin center?
	if((stop-lsp)>DM2choice) whichanalysis = 1;
	else whichanalysis = 2;
      }
      if(whichanalysis==1){
	hExpPosterioriOrg ->SetBinContent(x,y,hExpPosterioriOrg_t1->GetBinContent(x,y));
	hExpPrioriOrg     ->SetBinContent(x,y,hExpPrioriOrg_t1    ->GetBinContent(x,y));
	hObsOrg           ->SetBinContent(x,y,hObsOrg_t1          ->GetBinContent(x,y));
	hBestAnalysis->SetBinContent(x,y,1);
      } else if(whichanalysis==2){
	hExpPosterioriOrg ->SetBinContent(x,y,hExpPosterioriOrg_t2->GetBinContent(x,y));
	hExpPrioriOrg     ->SetBinContent(x,y,hExpPrioriOrg_t2    ->GetBinContent(x,y));
	hObsOrg           ->SetBinContent(x,y,hObsOrg_t2          ->GetBinContent(x,y));
	hBestAnalysis->SetBinContent(x,y,2);
      }
      hpExpPosterioriOrg->SetBinContent(x,y,RooStats::SignificanceToPValue(hExpPosterioriOrg->GetBinContent(x,y)));
      hpExpPrioriOrg    ->SetBinContent(x,y,RooStats::SignificanceToPValue(hExpPrioriOrg    ->GetBinContent(x,y)));
      hpObsOrg          ->SetBinContent(x,y,RooStats::SignificanceToPValue(hObsOrg          ->GetBinContent(x,y)));
    }//y
  }//x

 
  cout << "Now interpolate these histograms" << endl;  
  hpExpPriori     = (TH2F*)InterpolateThisHistogram(hpExpPrioriOrg);
  hpExpPosteriori = (TH2F*)InterpolateThisHistogram(hpExpPosterioriOrg);
  hpObs           = (TH2F*)InterpolateThisHistogram(hpObsOrg);
  hExpPriori      = (TH2F*)InterpolateThisHistogram(hExpPrioriOrg);
  hExpPosteriori  = (TH2F*)InterpolateThisHistogram(hExpPosterioriOrg);
  hObs            = (TH2F*)InterpolateThisHistogram(hObsOrg);
  file->cd();
  hBestAnalysis     ->Write();
  hpExpPriori       ->Write();
  hpExpPosteriori   ->Write();
  hpObs             ->Write();
  hExpPriori        ->Write();
  hExpPosteriori    ->Write();
  hObs              ->Write();
  hpExpPrioriOrg    ->Write();
  hpExpPosterioriOrg->Write();
  hpObsOrg          ->Write();
  hExpPrioriOrg     ->Write();
  hExpPosterioriOrg ->Write();
  hObsOrg           ->Write();


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
  //cout << g->GetXmax() << " " << g->GetXmin() << " " << g->GetYmax() << " " << g->GetYmin() << " " << binsize << endl;
  g->SetNpx(int(g->GetXmax()-g->GetXmin())/binsize);
  g->SetNpy(int(g->GetYmax()-g->GetYmin())/binsize);
  TH2F *hnew = (TH2F*)g->GetHistogram();
  //TH2F *htemp = (TH2F*)hnew->Clone(name);
  //name.ReplaceAll("YXZ","");
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
