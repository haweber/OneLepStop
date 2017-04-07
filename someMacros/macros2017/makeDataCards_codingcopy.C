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
#include <algorithm> 

using namespace std;

//to load:
//root -l -b
//.L makeDataCards.C+
//your favorite function, look for "these are the 7 wrappers to produce datacards"

// signal scans hardcoded in "allscans" wrappers: T2tt, T2tt_lefthanded, T2tt_righthanded, T2bW, T2tb, T2tb_0_100, T2tb_25_75, T2tb_33_67, T2tb_50_50, T2tb_67_33, T2tb_75_25, T2tb_100_0
//analyses hardcoded in "allanalyses" wrappers: 0 (std analysis from 8 TeV)

//define base directories as global variables
string inputdir = "rootfiles/";
string outputdir = "datacardsMoriond17_36p6fbinv/";

//defined steps in lsp/stop mass - 25 GeV is fine for everything
const int step = 25;

//define maximum number of processes global as it is used by correlation testing functions outside main function
const int maxnprocess = 5;

//define number of analyses - shouldn't make this global ...
int nanalyses = 1;//currently one analysis exists

//all tfiles TH*D are global so that they are easily seen by all functions
//files with backgrounds, data and signals.
TString lastsignalname = "";//check if signal changes - need to load new file and clean histograms.
TFile *fsig;
TFile *f2l;
TFile *f1l;
TFile *f1ltop;
TFile *fznunu;
TFile *fdata;
bool signalhistosloaded = false;
bool otherhistossloaded = false;
//histograms for all
map<string, TH3D*> histSig;//check for signal to clean
map<string, TH1D*> hist2l;
map<string, TH1D*> hist1l;
map<string, TH1D*> hist1ltop;
map<string, TH1D*> histZnunu;
map<string, TH1D*> histData;

//ATTENTION:
// main function makeDataCardsOneBinBasis has a lof of hardcoded stuff
//histograms are defined in checkbin, UpdatePlottingHisto, loadSignalHistos, loadDataBGHistos
//tfiles defined in loadSignalFile, loadDataBGFiles
//check GetTTZBin,GetLLBin,GetLLCRBin,Get0bCRBin

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}

//get max/min stop/lsp masses depending on scan
int minstopmass(TString signaltype="T2tt");
int maxstopmass(TString signaltype="T2tt");
int minlspmass(TString signaltype="T2tt");
int maxlspmass(TString signaltype="T2tt");

//get nuisance parameter lines in datacard - correlated or not - with two helper functions for checking which process adds to the correlation
bool checkIfPos(double *d);
int addCorrelatedUnc(std::ostringstream *fLogStream, string name, double *d, double *u, int bin, string unctype);
int addOneUnc(std::ostringstream *fLogStream, string name, double d, double u, int process, int bin, string unctype);
void resetArray(double *a);

//get all uncertainties
int getSigUncertainty(double &errup, double &errdown, double origyield, TH3D *hup, TH3D *hdown, int bin);
int getSigUncertaintyOneSided(double &err, double origyield, TH3D *h, int bin);
int getSigError(double &err, double origyield, TH3D *h, int bin);
int getSigErrorRel(double &err, double origyield, TH3D* h, int bin);
int getBGUncertainty(double &errup, double &errdown, double origyield, TH1D *hup, TH1D *hdown, int bin);
int getBGUncertaintyOneSided(double &err, double origyield, TH1D *h, int bin);
int getBGError(double &err, double origyield, TH1D *h, int bin);
int getBGErrorRel(double &err, double origyield, TH1D* h, int bin);

//wrapper to load all TFiles and TH*D
bool loadAll(TString signaltype="T2tt", bool fakedata=false, int analysis=0);
//wrapper to close/delete all TFiles and TH*D
bool closeAll(bool fakedata=false);
//closing/deleting signal TFile and TH3D's - reload them from a new signal
bool reloadSignal(TString signaltype, int analysis=0);
//loading signal, background/data files and histograms - split into 2 functions as signal might be reloaded
bool loadDataBGFiles(bool fakedata=false, int analysis=0);
bool loadSignalFile(TString signaltype="T2tt", int analysis=0);
bool loadDataBGHistos(bool fakedata=false, int analysis=0);
bool loadSignalHistos(int analysis=0);

//check if the bin I want to use is a valid bin for this signal (i.e. there is signal) in the analysis
int checkbin(int analysis, int bin, double stop, double lsp, bool dropsigcont);
//all the analyses identifiers
int analysismaxbin(int analysis);
int analysisbinoffset(int analysis);
string analysisname(int analysis);
int analysisID(string analysisname);
bool validanalysis(int analysis);

//bin of histograms, as people didn't seem to care about conventions
int GetLLBin(int b);
int GetTTZBin(int b);
int GetLLCRBin(int b);
int Get0bCRBin(int b);

//for final result plot - this is the easiest way - although waste of computing time.
void UpdatePlottingHisto(int analysis, TString signalname, int b, int data, double sig, double sigerr, map<string, double> vSig, double bg2l, double bg2lerr, map<string, double> v2l, double bg1l, double bg1lerr, map<string, double> v1l, double bg1ltop, double bg1ltoperr, map<string, double> v1ltop, double bgznunu, double bgznunuerr, map<string, double> vZnunu, bool nosigsyst, bool nobgsyst, bool dropsigcont, bool fakedata);

//this is the code that makes the datacards
void makeDataCardsOneBinBasis(int bin=0, TString signaltype="T2tt", int analysis=0, bool dropsigcont=false, bool correlated=true, int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//these are the 7 wrappers to produce datacards
//wrapper around Basis - makes the datacard for one specific bin for one analysis and one scan
void makeDataCardsOneBin(int bin=0, TString signaltype="T2tt", int analysis=0, bool dropsigcont=false, bool correlated=true, int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//makes datacards for all analysis bins of a given analysis for one specific signal mass point
void makeDataCardsAllBins(TString signaltype="T2tt", int analysis=0, bool dropsigcont=false, bool correlated=true, int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//makes datacards for all analysis bins of a given analysis for one full signalscan
void makeDataCardsOneScan(TString signaltype="T2tt", int analysis=0, bool dropsigcont=false, bool correlated=true, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//makes datacards for all analysis bins for all analyses for one full signal scan
void makeDataCardsAllBinsAllAnalyses(TString signaltype="T2tt", bool dropsigcont=false, bool correlated=true, int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//makes datacards for all analysis bins for all analyses for one signal mass point
void makeDataCardsOneScanAllAnalyses(TString signaltype="T2tt", bool dropsigcont=false, bool correlated=true, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//makes datacards for all analysis bins for a given analysis for all scans - in old version that was unstable for CPU
void makeDataCardsAllScans(int analysis=0, bool dropsigcont=false, bool correlated=true, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);
//master functionmakes datacards for all analysis bins for all analyses analysis for all scans - new function
void makeDataCardsAllScansAllAnalyses(bool dropsigcont=false, bool correlated=true, bool fakedata=false, bool nosigsyst=false, bool nobgsyst=false);



//master functionmakes datacards for all analysis bins for all analyses analysis for all scans - new function
void makeDataCardsAllScansAllAnalyses(bool dropsigcont, bool correlated, bool fakedata, bool nosigsyst, bool nobgsyst){

  for(unsigned int i = 0; i<12;++i){
    TString signaltype="";
    if(i== 0)      signaltype = "T2tt";
    else if(i== 1) signaltype = "T2tt_lefthanded";
    else if(i== 2) signaltype = "T2tt_righthanded";
    else if(i== 3) signaltype = "T2bW";
    else if(i== 4) signaltype = "T2tb";
    else if(i== 5) signaltype = "T2tb_50_50";
    else if(i== 6) signaltype = "T2tb_0_100";
    else if(i== 7) signaltype = "T2tb_100_0";
    else if(i== 8) signaltype = "T2tb_75_25";
    else if(i== 9) signaltype = "T2tb_25_75";
    else if(i==10) signaltype = "T2tb_67_33";
    else if(i==11) signaltype = "T2tb_33_67";

    int minStopMass = minstopmass(signaltype);
    if(minStopMass<0) return;
    int maxStopMass = maxstopmass(signaltype);
    int minLSPMass  = minlspmass(signaltype);
    int maxLSPMass  = maxlspmass(signaltype);
    bool loaded = false;
    if(i==0) loaded = loadAll(signaltype, fakedata,0);
    else     loaded = reloadSignal(signaltype,0);
    if(loaded){
      for(int analysis = 0; analysis<nanalyses; ++analysis){
	if(!validanalysis(analysis)) continue;
	int anmaxbin = analysismaxbin(analysis);
	if(anmaxbin<1) return;
	for(int stop = minStopMass; stop<=maxStopMass; stop+=step){
	  for(int lsp = minLSPMass; lsp<=maxLSPMass; lsp+=step){
	    for(int bin = 1; bin<=anmaxbin; ++bin){
	      //careful - currently no charg or xval has been set
	      makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, -1, -1, fakedata, nosigsyst, nobgsyst);
	    }
	  }
	}
      }
    }
  }
  closeAll(fakedata);
}

//makes datacards for all analysis bins for a given analysis for all scans - in old version that was unstable for CPU
void makeDataCardsAllScans(int analysis, bool dropsigcont, bool correlated, bool fakedata, bool nosigsyst, bool nobgsyst){
  if(!validanalysis(analysis)) exit(0);
  for(unsigned int i = 0; i<12;++i){
    TString signaltype="";
    if(i== 0)      signaltype = "T2tt";
    else if(i== 1) signaltype = "T2tt_lefthanded";
    else if(i== 2) signaltype = "T2tt_righthanded";
    else if(i== 3) signaltype = "T2bW";
    else if(i== 4) signaltype = "T2tb";
    else if(i== 5) signaltype = "T2tb_50_50";
    else if(i== 6) signaltype = "T2tb_0_100";
    else if(i== 7) signaltype = "T2tb_100_0";
    else if(i== 8) signaltype = "T2tb_75_25";
    else if(i== 9) signaltype = "T2tb_25_75";
    else if(i==10) signaltype = "T2tb_67_33";
    else if(i==11) signaltype = "T2tb_33_67";

    int anmaxbin = analysismaxbin(analysis);
    if(anmaxbin<1) return;
    int minStopMass = minstopmass(signaltype);
    if(minStopMass<0) return;
    int maxStopMass = maxstopmass(signaltype);
    int minLSPMass  = minlspmass(signaltype);
    int maxLSPMass  = maxlspmass(signaltype);
    bool loaded = false;
    if(i==0) loaded = loadAll(signaltype, fakedata,analysis);
    else     loaded = reloadSignal(signaltype,analysis);
    if(loaded){
      for(int stop = minStopMass; stop<=maxStopMass; stop+=step){
	for(int lsp = minLSPMass; lsp<=maxLSPMass; lsp+=step){
	  for(int bin = 1; bin<=anmaxbin; ++bin){
	    //careful - currently no charg or xval has been set
	    makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, -1, -1, fakedata, nosigsyst, nobgsyst);
	  }
	}
      }
    }
  }
  closeAll(fakedata);
}

//makes datacards for all analysis bins for all analyses for one signal mass point
void makeDataCardsOneScanAllAnalyses(TString signaltype, bool dropsigcont, bool correlated, bool fakedata, bool nosigsyst, bool nobgsyst){
  int minStopMass = minstopmass(signaltype);
  if(minStopMass<0) return;
  int maxStopMass = maxstopmass(signaltype);
  int minLSPMass  = minlspmass(signaltype);
  int maxLSPMass  = maxlspmass(signaltype);
  bool loaded = loadAll(signaltype, fakedata,0);
  if(loaded){
    for(int analysis = 0; analysis<nanalyses; ++analysis){
      if(!validanalysis(analysis)) continue;
     int anmaxbin = analysismaxbin(analysis);
      if(anmaxbin<1) return;
      for(int stop = minStopMass; stop<=maxStopMass; stop+=step){
	for(int lsp = minLSPMass; lsp<=maxLSPMass; lsp+=step){
	  for(int bin = 1; bin<=anmaxbin; ++bin){
	    //careful - currently no charg or xval has been set
	    makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, -1, -1, fakedata, nosigsyst, nobgsyst);
	  }
	}
      }
    }
  }
  closeAll(fakedata);
}

//makes datacards for all analysis bins for all analyses for one full signal scan
void makeDataCardsAllBinsAllAnalyses(TString signaltype, bool dropsigcont, bool correlated, int stop, int lsp, int charg, float xval, bool fakedata, bool nosigsyst, bool nobgsyst){
  bool loaded = loadAll(signaltype, fakedata,0);
  if(loaded){
    for(int analysis = 0; analysis<nanalyses; ++analysis){
      if(!validanalysis(analysis)) continue;
      int anmaxbin = analysismaxbin(analysis);
      if(anmaxbin<1) return;
      for(int bin = 1; bin<=anmaxbin; ++bin){
	makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, charg, xval, fakedata, nosigsyst, nobgsyst);
      }
    }
  }
  closeAll(fakedata);
}

//makes datacards for all analysis bins of a given analysis for one full signalscan
void makeDataCardsOneScan(TString signaltype, int analysis, bool dropsigcont, bool correlated, bool fakedata, bool nosigsyst, bool nobgsyst){
  if(!validanalysis(analysis)) exit(0);
  int anmaxbin = analysismaxbin(analysis);
  if(anmaxbin<1) return;
  int minStopMass = minstopmass(signaltype);
  if(minStopMass<0) return;
  int maxStopMass = maxstopmass(signaltype);
  int minLSPMass  = minlspmass(signaltype);
  int maxLSPMass  = maxlspmass(signaltype);
  cout << __LINE__ << endl;
  bool loaded = loadAll(signaltype, fakedata,analysis);
  cout << __LINE__ << " " << loaded << endl;
  if(loaded){
    for(int stop = minStopMass; stop<=maxStopMass; stop+=step){
      for(int lsp = minLSPMass; lsp<=maxLSPMass; lsp+=step){
	for(int bin = 1; bin<=anmaxbin; ++bin){
	  //careful - currently no charg or xval has been set
	  makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, -1, -1, fakedata, nosigsyst, nobgsyst);
	}
      }
    }
  }
  closeAll(fakedata);
}

//makes datacards for all analysis bins of a given analysis for one specific signal mass point
void makeDataCardsAllBins(TString signaltype, int analysis, bool dropsigcont, bool correlated, int stop, int lsp, int charg, float xval, bool fakedata, bool nosigsyst, bool nobgsyst){

  if(!validanalysis(analysis)) exit(0);
  int anmaxbin = analysismaxbin(analysis);
  if(anmaxbin<1) return;
  bool loaded = loadAll(signaltype, fakedata,analysis);
  if(loaded){
    for(int bin = 1; bin<=anmaxbin; ++bin){
      makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, charg, xval, fakedata, nosigsyst, nobgsyst);
    }
  }
  closeAll(fakedata);  
}

//make single bin datacard
void makeDataCardsOneBin(int bin, TString signaltype, int analysis, bool dropsigcont, bool correlated, int stop, int lsp, int charg, float xval, bool fakedata, bool nosigsyst, bool nobgsyst){

  if(!validanalysis(analysis)) exit(0);
  bool loaded = loadAll(signaltype, fakedata,analysis);
  if(loaded) makeDataCardsOneBinBasis(bin, signaltype, analysis, dropsigcont, correlated, stop, lsp, charg, xval, fakedata, nosigsyst, nobgsyst);
  closeAll(fakedata);
}

//wrapper to make single bin datacard
void makeDataCardsOneBinBasis(int bin, TString signaltype, int analysis, bool dropsigcont, bool correlated, int stop, int lsp, int charg, float xval, bool fakedata, bool nosigsyst, bool nobgsyst){
  //cout << __LINE__ << endl;
  int b = checkbin(analysis, bin, stop, lsp, dropsigcont);//kills bins with no signal
  //cout << b << endl;
  if(b<0) return;
  int b3 = histSig["SRyield"]->FindBin(stop,lsp,b);

  int nbgs = 0;
  //int nnuis = 0;//don't use this anymore
  
  int bLL = GetLLBin(b);  //if wrong bin number in histograms
  int bTTZ = GetTTZBin(b);//if wrong bin number in histograms
  int bW = b;

  //these are only uncertainties!
  map<string, double> vSig;
  map<string, double> v2l;
  map<string, double> v1l;
  map<string, double> v1ltop;
  map<string, double> vZnunu;
  //these are the yields and statistical uncertainties
  double sig(0.), sigerr(1.);
  double sig1(0.), sig2(1.), sig1err(1.), sig2err(1.);
  double osig(0.);//keep original without signal contamination correction
  double data(0.);
  double bg2l(0.), bg2lerr(1.), bg1l(0.), bg1lerr(1.), bg1ltop(0.), bg1ltoperr(1.), bgznunu(0.), bgznunuerr(1.);

  //cout << __LINE__ << endl;
  sig = histSig["SRyield"]->GetBinContent(b3); sig1 = sig;
  sig2 = histSig["SRyield_gen"]->GetBinContent(b3);
  sigerr = 1 + histSig["SRyield"]->GetBinError(b3) / sig;
  osig = sig;//I need this for uncertainties
  //I didn't use this - drop it?
  /*
  if(xsecupdown==1){
    sig = histSig["SR_Xsecup"]->GetBinContent(b3);
    sigerr = 1. + histSig["SR_Xsecup"]->GetBinError(b3) / sig;
  } else if(xsecupdown==(-1)){
    sig = histSig["SR_Xsecdown"]->GetBinContent(b3);
    sigerr = 1. + histSig["SR_Xsecdown"]->GetBinError(b3) / sig;
  }
  */
  if(!dropsigcont){
    double temp = histSig["CR1l_sigcontamination"]->GetBinContent(b3);
    double oldSig = sig;
    sig = TMath::Max(0., oldSig-temp);
    oldSig = sig;//is this parnoia :D
    temp = histSig["CR2l_sigcontamination"]->GetBinContent(b3);
    sig = TMath::Max(0., oldSig-temp);
    sig1=sig;
    temp = histSig["CR1l_sigcontamination_gen"]->GetBinContent(b3);
    double oldSig2 = sig2;
    sig2 = TMath::Max(0., oldSig2-temp);
    oldSig = sig2;//is this parnoia :D
    temp = histSig["CR2l_sigcontamination_gen"]->GetBinContent(b3);
    sig2 = TMath::Max(0., oldSig2-temp);
  }
  //this is the genmet procedure;
  sig = (sig1+sig2)/2.;
  //sigerr = sqrt(pow(sig1err/2,2)+pow(sig2err/2,2));//don't do this, don't know correlation
  double genmetunc = 1. + TMath::Abs((sig1-sig)/2.)/sig;
  if(fabs(TMath::Abs((sig1-sig)/2.)-TMath::Abs((sig2-sig)/2.))>0.001) cout << "This should not happen " << TMath::Abs((sig1-sig)/2.) << " " << TMath::Abs((sig2-sig)/2.) << endl;

  if(osig==0) { sig = 0; genmetunc = -1; sig = -1; }
  //cout <<sig << " " << osig << endl;
  data = histData["SR_Data"]->GetBinContent(b);
  //cout << "Bin " << b << " " << data << endl;

  bg2l = hist2l["CR2l_yield"]->GetBinContent(bLL);
  ++nbgs;
  if(bg2l>0) { bg2lerr = 1.+(TMath::Max(bg2l-hist2l["CR2l_dataStatsDn"]->GetBinContent(bLL),hist2l["CR2l_dataStatsUp"]->GetBinContent(bLL)-bg2l)/bg2l); }
  bg1l = hist1l["CR1lyield"]->GetBinContent(bW);
  ++nbgs;
  if(bg1l>0) { bg1lerr = 1.+(TMath::Max(bg1l-hist1l["dataStats_Up"]->GetBinContent(bW),hist1l["dataStats_Dn"]->GetBinContent(bW)-bg1l)/bg1l); }
  bg1ltop = hist1ltop["SR_Top"]->GetBinContent(bW);
  //bg1ltop = hist1ltop["ee1lep_fromTop_yield"]->GetBinContent(bW);
  ++nbgs;
  if(bg1ltop>0) { bg1ltoperr = 2.; } //- no statistical uncertainty on 1ltop !!!
  bgznunu = histZnunu["yield"]->GetBinContent(bTTZ);
  ++nbgs;
  if(bgznunu>0) { bgznunuerr = 1.+(TMath::Max(bgznunu-histZnunu["normalizationDN"]->GetBinContent(bTTZ),histZnunu["normalizationUP"]->GetBinContent(bTTZ)-bgznunu)/bgznunu); }
  bool up = false; bool down = false;
  //cout << __LINE__ << endl;
  if(!nosigsyst&&sig>0){
    getSigUncertainty(vSig["SR_Bup_HF"],     vSig["SR_Bdown_HF"],     osig, histSig["SR_Bup_HF"],     histSig["SR_Bdown_HF"],     b3);
    getSigUncertainty(vSig["SR_Bup_LF"],     vSig["SR_Bdown_LF"],     osig, histSig["SR_Bup_LF"],     histSig["SR_Bdown_LF"],     b3);
    getSigUncertainty(vSig["SR_Bup_FS"],     vSig["SR_Bdown_FS"],     osig, histSig["SR_Bup_FS"],     histSig["SR_Bdown_FS"],     b3);
    getSigUncertainty(vSig["SR_JESup"],      vSig["SR_JESdown"],      osig, histSig["SR_JESup"],      histSig["SR_JESdown"],      b3);
    getSigUncertainty(vSig["SR_muRFup"],     vSig["SR_muRFdown"],     osig, histSig["SR_muRFup"],     histSig["SR_muRFdown"],     b3);
    getSigUncertainty(vSig["SR_ISRup"],      vSig["SR_ISRdown"],      osig, histSig["SR_ISRup"],      histSig["SR_ISRdown"],      b3);
    getSigUncertainty(vSig["SR_LepEffup"],   vSig["SR_LepEffdown"],   osig, histSig["SR_LepEffup"],   histSig["SR_LepEffdown"],   b3);
    getSigUncertainty(vSig["SR_LepEffFSup"], vSig["SR_LepEffFSdown"], osig, histSig["SR_LepEffFSup"], histSig["SR_LepEffFSdown"], b3);
    //getSigUncertainty(vSig["SR_PUup"],       vSig["SR_PUdown"],       osig, histSig["SR_PUup"],       histSig["SR_PUdown"],       b3);
    vSig["SR_PUup"] = 1.05; vSig["SR_PUdown"] = 0.95;
    if(analysis==1&&b>=3){ vSig["SR_PUup"] = 1.10; vSig["SR_PUdown"] = 0.9; }
    if(analysis==0&&(b==4||b==7||b==1||b==12||b==16||b==19||b==21||b==25||b==27)){ vSig["SR_PUup"] = 1.10; vSig["SR_PUup"] = 0.9; }
    //vSig["SR_PUerr"]        = 1.05;// new now
    vSig["SR_LEffVetoerr"]  = 1.03;
  }
  vSig["triggerrDn"]        = 0.98; if(b==1||b==4||b==8||b==11) vSig["triggerrDn"]        = 0.95; vSig["triggerrUp"]        = 1.00;//also on any other simulation
  vSig["lumierr"]         = 1.026; //also on any other simulation

  //cout << __LINE__ << endl;
  if(!nobgsyst){
    getBGUncertainty(v2l["CR2l_bTagEffHFUp"],  v2l["CR2l_bTagEffHFDn"],  bg2l, hist2l["CR2l_bTagEffHFUp"],  hist2l["CR2l_bTagEffHFDn"],  bLL);
    getBGUncertainty(v2l["CR2l_bTagEffLFUp"],  v2l["CR2l_bTagEffLFDn"],  bg2l, hist2l["CR2l_bTagEffLFUp"],  hist2l["CR2l_bTagEffLFDn"],  bLL);
    getBGUncertainty(v2l["CR2l_lepSFUp"],      v2l["CR2l_lepSFDn"],      bg2l, hist2l["CR2l_lepSFUp"],      hist2l["CR2l_lepSFDn"],      bLL);
    //getBGUncertainty(v2l["CR2l_ttbarSysPtUp"], v2l["CR2l_ttbarSysPtDn"], bg2l, hist2l["CR2l_ttbarSysPtUp"], hist2l["CR2l_ttbarSysPtDn"], bLL);
    getBGUncertainty(v2l["CR2l_mcStatsUp"],    v2l["CR2l_mcStatsDn"],    bg2l, hist2l["CR2l_mcStatsUp"],    hist2l["CR2l_mcStatsDn"],    bLL);
    getBGUncertainty(v2l["CR2l_ISRUp"],        v2l["CR2l_ISRDn"],        bg2l, hist2l["CR2l_ISRUp"],        hist2l["CR2l_ISRDn"],        bLL);
    getBGUncertainty(v2l["CR2l_alphasUp"],     v2l["CR2l_alphasDn"],     bg2l, hist2l["CR2l_alphasUp"],     hist2l["CR2l_alphasDn"],     bLL);
    getBGUncertainty(v2l["CR2l_q2Up"],         v2l["CR2l_q2Dn"],         bg2l, hist2l["CR2l_q2Up"],         hist2l["CR2l_q2Dn"],         bLL);
    getBGUncertainty(v2l["CR2l_jesUp"],        v2l["CR2l_jesDn"],        bg2l, hist2l["CR2l_jesUp"],        hist2l["CR2l_jesDn"],        bLL);//XXX
    getBGUncertainty(v2l["CR2l_cr2lTriggerSFUp"],v2l["CR2l_cr2lTriggerSFDn"],bg2l,hist2l["CR2l_cr2lTriggerSFUp"],hist2l["CR2l_cr2lTriggerSFDn"],bLL);
    getBGUncertainty(v2l["CR2l_metResUp"],     v2l["CR2l_metResDn"],     bg2l, hist2l["CR2l_metResUp"],     hist2l["CR2l_metResDn"],        bLL);
    getBGUncertainty(v2l["CR2l_pileupUp"],     v2l["CR2l_pileupDn"],     bg2l, hist2l["CR2l_pileupUp"],     hist2l["CR2l_pileupDn"],        bLL);
    getBGUncertainty(v2l["CR2l_tauSFUp"],     v2l["CR2l_tauSFDn"],     bg2l, hist2l["CR2l_tauSFUp"],     hist2l["CR2l_tauSFDn"],        bLL);
    getBGUncertainty(v2l["CR2l_metTTbarUp"],     v2l["CR2l_metTTbarDn"],     bg2l, hist2l["CR2l_metTTbarUp"],     hist2l["CR2l_metTTbarDn"],        bLL);
    
    //cout << __LINE__ << endl;
    getBGUncertainty(v1l["mcStats_Up"],      v1l["mcStats_Dn"],      bg1l, hist1l["mcStats_Up"],      hist1l["mcStats_Dn"],      bW);
    getBGUncertainty(v1l["Wb_Up"],      v1l["Wb_Dn"],      bg1l, hist1l["Wb_Up"],      hist1l["Wb_Dn"],      bW);
    getBGUncertainty(v1l["bTagEffHF_Up"], v1l["bTagEffHF_Dn"], bg1l, hist1l["bTagEffHF_Up"], hist1l["bTagEffHF_Dn"], bW);
    getBGUncertainty(v1l["bTagEffLF_Up"], v1l["bTagEffLF_Dn"], bg1l, hist1l["bTagEffLF_Up"], hist1l["bTagEffLF_Dn"], bW);
    getBGUncertainty(v1l["pdf_Up"],     v1l["pdf_Dn"],     bg1l, hist1l["pdf_Up"],     hist1l["pdf_Dn"],     bW);
    getBGUncertainty(v1l["q2_Up"],      v1l["q2_Dn"],      bg1l, hist1l["q2_Up"],      hist1l["q2_Dn"],      bW);
    getBGUncertainty(v1l["JES_Up"],     v1l["JES_Dn"],     bg1l, hist1l["JES_Up"],     hist1l["JES_Dn"],     bW);
    getBGUncertainty(v1l["CRCont_Up"],  v1l["CRCont_Dn"],  bg1l, hist1l["CRCont_Up"],  hist1l["CRCont_Dn"],  bW);
    //getBGUncertainty(v1l["metres_Up"],  v1l["metres_Down"],  bg1l, hist1l["metres_Up"],  hist1l["metres_Down"],  bW);
    //getBGUncertainty(v1l["W_width_Up"], v1l["W_width_Down"], bg1l, hist1l["W_width_Up"], hist1l["W_width_Down"], bW);
    //getBGUncertainty(v1l["nu_pT_Up"],   v1l["nu_pT_Down"],   bg1l, hist1l["nu_pT_Up"],   hist1l["nu_pT_Down"],   bW);
    
    //cout << __LINE__ << endl;
    if(bg1ltop>0) v1ltop["tt1lyielderr"] = 2.; else v1ltop["tt1lyielderr"] = 1.;
    //if(bg1ltop>0) v1ltop["SR_Top"] = 2.; else v1ltop["SR_Top"] = 1.;
    
    //cout << __LINE__ << endl;
    getBGUncertainty(vZnunu["mcStatsUP"],   vZnunu["mcStatsDN"],   bgznunu, histZnunu["mcStatsUP"],   histZnunu["mcStatsDN"],   bTTZ);
    getBGUncertainty(vZnunu["lepSFUP"],     vZnunu["lepSFDN"],     bgznunu, histZnunu["lepSFUP"],     histZnunu["lepSFDN"],     bTTZ);
    getBGUncertainty(vZnunu["btagLightUP"], vZnunu["btagLightDN"], bgznunu, histZnunu["btagLightUP"], histZnunu["btagLightDN"], bTTZ);
    getBGUncertainty(vZnunu["btagHeavyUP"], vZnunu["btagHeavyDN"], bgznunu, histZnunu["btagHeavyUP"], histZnunu["btagHeavyDN"], bTTZ);
    getBGUncertainty(vZnunu["PUup"],        vZnunu["PUdown"],      bgznunu, histZnunu["PUup"],        histZnunu["PUdown"],      bTTZ);
    getBGUncertainty(vZnunu["pdfUP"],       vZnunu["pdfDN"],       bgznunu, histZnunu["pdfUP"],       histZnunu["pdfDN"],       bTTZ);
    getBGUncertainty(vZnunu["alphaSUP"],    vZnunu["alphaSDN"],    bgznunu, histZnunu["alphaSUP"],    histZnunu["alphaSDN"],    bTTZ);
    getBGUncertainty(vZnunu["Q2UP"],        vZnunu["Q2DN"],        bgznunu, histZnunu["Q2UP"],        histZnunu["Q2DN"],        bTTZ);
    getBGUncertainty(vZnunu["jesUP"],       vZnunu["jesDN"],       bgznunu, histZnunu["jesUP"],       histZnunu["jesDN"],       bTTZ);
    getBGUncertainty(vZnunu["ISRnjetsUp"],  vZnunu["ISRnjetsDown"],bgznunu, histZnunu["ISRnjetsUp"],  histZnunu["ISRnjetsDown"],bTTZ);
  }//if(!nobgsyst)
  //this needs to be checked, probably want also up/down errors for statistical uncertainties...
  //cout << __LINE__ << endl;

  //now the important part - get the datacard
  std::ostringstream* fLogStream     = 0;
  std::ostringstream* fLogStreamHeader     = 0;
  fLogStream = new std::ostringstream();
  fLogStreamHeader = new std::ostringstream();
  string binstring = "b" + std::to_string(b);
  TString signalname = signaltype + "_" + std::to_string(int(stop)) + "_" + std::to_string(int(lsp));

  double uperr[maxnprocess];
  double dnerr[maxnprocess];
  for(int i = 0; i<maxnprocess; ++i){ uperr[i] = -1; dnerr[i] = -1; }

  double lc = 1.0;//allow for change in luminosity from last pixel calibration
  int numnuis = 0;
  //recalculated nuissances later
  //*fLogStream << "# My significance experiment" << endl
  //	      << "imax  " << 1     << "  number of channels" << endl//single bin
  //	      << "jmax  " << nbgs  << "  number of backgrounds" << endl
  //	      << "kmax "  << nnuis << "  number of nuisance parameters" << endl;
  *fLogStream << "------------" << endl << "# observations " << endl;
  *fLogStream << "bin         " << b << endl;
  if(fakedata) *fLogStream << "observation " << int(bg2l+bg1l+bg1ltop+bgznunu) << endl;//use int if one uses fake data
  else *fLogStream << "observation " << int(data) << endl;//use int if one uses fake data
  *fLogStream << "------------" << endl;
  *fLogStream << "#now we list all expected number of events" << endl;
  *fLogStream << "bin          " << b << "       " << b << "       " << b << "       " << b << "       " << b << "       " << endl;
  *fLogStream << "process     sig       2l       1l       1ltop       znunu" << endl;
  *fLogStream << "process      0        1         2       3           4" << endl;
  *fLogStream << "rate        " << (sig>0 ? sig*lc : 0) << "  " << bg2l << "  " << bg1l << "  " << bg1ltop*lc << "  " << bgznunu*lc << endl;// - DELETE *lc XXX
  *fLogStream << "------------" << endl;
  //next ALL control region statistical uncertainties
  int bWst = Get0bCRBin(b);
  int btt2l = GetLLCRBin(b);
  //statistical uncertainties
  if(!nosigsyst && genmetunc!=1&&genmetunc>0){
    *fLogStream << "SigGenMETunc"/*<<b*/ << "   lnU " << genmetunc << " -  -  -  -" << endl;//stupid genmet stuff
    ++numnuis;
  }
  if(!nosigsyst && sig   >0) numnuis += addOneUnc(fLogStream, "SigStat",     sigerr,     -1, 0, b,     "lnN");
  if(!nobgsyst && bg2l   >0) numnuis += addOneUnc(fLogStream, "Bg2lStat",    bg2lerr,    -1, 1, btt2l, "lnN");
  if(bW>7&&bW<11) bg1lerr = 2;
  if(!nobgsyst && bg1l   >0) numnuis += addOneUnc(fLogStream, "Bg1lStat",    bg1lerr,    -1, 2, bWst,  "lnN");
  if(!nobgsyst && bgznunu>0) numnuis += addOneUnc(fLogStream, "BgZnunuStat", bgznunuerr, -1, 4, -1,  "lnN");
  //if(!nobgsyst && bg1ltop>0) *fLogStream << "Bg1lTopStat" << b     << "     lnN -  -  -  "    << bg1ltoperr << "  -"          << endl;
  //general uncertainties
  if(!nobgsyst && bg1ltop>0) numnuis += addOneUnc(fLogStream, "Bg1lTopSyst", v1ltop["tt1lyielderr"], -1, 3, b, "lnN");
  if(sig>0) dnerr[0] = vSig["triggerrDn"]; dnerr[3] = vSig["triggerrDn"]; /*dnerr[4] = vSig["triggerrDn"];*/ dnerr[1] = v2l["CR2l_cr2lTriggerSFUp"];//obviously need to swap CR2l eff
  if(sig>0) uperr[0] = vSig["triggerrUp"]; uperr[3] = vSig["triggerrUp"]; /*uperr[4] = vSig["triggerrUp"];*/ uperr[1] = v2l["CR2l_cr2lTriggerSFDn"];
  numnuis += addCorrelatedUnc(fLogStream, "TrigSyst", dnerr, uperr, -1, "lnN");
  if(sig>0) dnerr[0] = vSig["lumierr"]; dnerr[3] = vSig["lumierr"]; /*dnerr[4] = vSig["lumierr"];*/
  numnuis += addCorrelatedUnc(fLogStream, "LumiSyst", dnerr, uperr, -1, "lnN");
  if(!nosigsyst&& sig    >0){
    //signal systematic uncertainties (or general - therefore add no "Sig" prefix)
    numnuis += addOneUnc(fLogStream, "PUSyst",     vSig["SR_PUdown"],       vSig["SR_PUup"],       0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "BLFSyst",    vSig["SR_Bdown_LF"],     vSig["SR_Bup_LF"],     0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "BHFSyst",    vSig["SR_Bdown_HF"],     vSig["SR_Bup_HF"],     0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "BFSSyst",    vSig["SR_Bdown_FS"],     vSig["SR_Bup_FS"],     0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "JESSyst",    vSig["SR_JESdown"],      vSig["SR_JESup"],      0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "ISRSyst",    vSig["SR_ISRdown"],      vSig["SR_ISRup"],      0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "MuRFSyst",   vSig["SR_muRFdown"],     vSig["SR_muRFup"],     0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "LEffSyst",   vSig["SR_LepEffdown"],   vSig["SR_LepEffup"],   0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "LEffFSSyst", vSig["SR_LepEffFSdown"], vSig["SR_LepEffFSup"], 0, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "LVetoSyst",  vSig["SR_LEffVetoerr"],  -1,                    0,  b, "lnN");
  }
  if(!nobgsyst){
    //correlated
    if(correlated){
      dnerr[1] = v2l["CR2l_bTagEffHFDn"]; dnerr[2] = v1l["bTagEffHF_Dn"]; dnerr[4] = vZnunu["btagHeavyDN"];
      uperr[1] = v2l["CR2l_bTagEffHFUp"];   uperr[2] = v1l["bTagEffHF_Up"]; uperr[4] = vZnunu["btagHeavyUP"];
      numnuis += addCorrelatedUnc(fLogStream, "BHFSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_bTagEffLFDn"]; dnerr[2] = v1l["bTagEffLF_Dn"]; dnerr[4] = vZnunu["btagLightDN"];
      uperr[1] = v2l["CR2l_bTagEffLFUp"];   uperr[2] = v1l["bTagEffLF_Up"]; uperr[4] = vZnunu["btagLightUP"];
      numnuis += addCorrelatedUnc(fLogStream, "BLFSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_lepSFDn"]; dnerr[4] = vZnunu["lepSFDN"];
      uperr[1] = v2l["CR2l_lepSFUp"]; uperr[4] = vZnunu["lepSFUP"];
      numnuis += addCorrelatedUnc(fLogStream, "LEffSystBg", dnerr, uperr, -1, "lnN");
      /*dnerr[1] = v2l["CR2l_PDFdown"];*/ dnerr[2] = v1l["pdf_Dn"]; dnerr[4] = vZnunu["pdfDN"];
      /*uperr[1] = v2l["CR2l_PDFup"];*/   uperr[2] = v1l["pdf_Up"];   uperr[4] = vZnunu["pdfUP"];
      numnuis += addCorrelatedUnc(fLogStream, "PDFSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_q2Dn"]; dnerr[2] = v1l["q2_Dn"]; dnerr[4] = vZnunu["Q2DN"];
      uperr[1] = v2l["CR2l_q2Up"];  uperr[2] = v1l["q2_Up"];  uperr[4] = vZnunu["Q2UP"];
      numnuis += addCorrelatedUnc(fLogStream, "QsqSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_jesDn"]; dnerr[2] = v1l["JES_Dn"]; dnerr[4] = vZnunu["jesDN"];   //XXX
      uperr[1] = v2l["CR2l_jesUp"];   uperr[2] = v1l["JES_Up"]; dnerr[4] = vZnunu["jesUP"];  //XXX
      numnuis += addCorrelatedUnc(fLogStream, "JESSystBg", dnerr, uperr, -1, "lnN"); //XXX
      //dnerr[1] = v2l["CR2l_metResdown"]; dnerr[2] = v1l["metres_Down"];
      //uperr[1] = v2l["CR2l_metResup"];   uperr[2] = v1l["metres_Up"];
      //numnuis += addCorrelatedUnc(fLogStream, "METSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_alphasDn"]; dnerr[4] = vZnunu["alphaSDN"];
      uperr[1] = v2l["CR2l_alphasUp"]; uperr[4] = vZnunu["alphaSUP"];
      numnuis += addCorrelatedUnc(fLogStream, "AsSystBg", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_ISRDn"]; dnerr[4] = vZnunu["ISRnjetsDown"];
      uperr[1] = v2l["CR2l_ISRUp"]; uperr[4] = vZnunu["ISRnjetsUp"];
      numnuis += addCorrelatedUnc(fLogStream, "ISRSystBG", dnerr, uperr, -1, "lnN");
      dnerr[1] = v2l["CR2l_pileupDn"]; dnerr[4] = vZnunu["PUdown"];
      uperr[1] = v2l["CR2l_pileupUp"]; uperr[4] = vZnunu["PUup"];
      numnuis += addCorrelatedUnc(fLogStream, "PUSystBG", dnerr, uperr, -1, "lnN"); 
    }
    else {//uncorrelated
      //bg2l
      numnuis += addOneUnc(fLogStream, "BHFSyst2l",  v2l["CR2l_bTagEffHFDn"], v2l["CR2l_bTagEffHFUp"], 1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "BLFSyst2l",  v2l["CR2l_bTagEffLFDn"], v2l["CR2l_bTagEffLFUp"], 1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "LEffSyst2l", v2l["CR2l_lepSFDn"],     v2l["CR2l_lepSFUp"],     1, -1, "lnN");
      ////numnuis += addOneUnc(fLogStream, "PDFSyst2l",  v2l["CR2l_PDFdown"],    v2l["CR2l_PDFup"],    1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "muRFSyst2l", v2l["CR2l_q2Dn"],        v2l["CR2l_q2Up"],        1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "JESSyst2l",  v2l["CR2l_jesDn"],       v2l["CR2l_jesUp"],       1, -1, "lnN");//XXX
      numnuis += addOneUnc(fLogStream, "AsSyst2l",  v2l["CR2l_alphasDn"],     v2l["CR2l_alphasUp"],     1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "ISRSyst2l", v2l["CR2l_ISRDn"],        v2l["CR2l_ISRUp"],     1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "PU2l", v2l["CR2l_pileupDn"],        v2l["CR2l_pileupUp"],     1, -1, "lnN");
      //bg1l
      numnuis += addOneUnc(fLogStream, "BHFSyst1l",  v1l["btag_HF_Down"], v1l["btag_HF_Up"], 2, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "BLFSyst1l",  v1l["btag_LF_Down"], v1l["btag_LF_Up"], 2, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "PDFSyst1l",  v1l["pdf_Dn"],     v1l["pdf_Up"],     2, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "muRFSyst1l", v1l["q2_Dn"],      v1l["q2_Up"],      2, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "JESSysy1l",  v1l["JES_Down"],     v1l["JES_Up"],     2, -1, "lnN");//XXX
      //numnuis += addOneUnc(fLogStream, "METSyst1l",  v1l["metres_Down"],  v1l["metres_Up"],  2, -1, "lnN");
      //bgznunu
      numnuis += addOneUnc(fLogStream, "BHFSFSystZ",vZnunu["btagHeavyDN"], vZnunu["btagHeavyUP"], 4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "BLFSFSystZ",vZnunu["btagLightDN"], vZnunu["btagLightUP"], 4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "LEffSystZ", vZnunu["lepSFDN"],     vZnunu["lepSFUP"],     4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "JESSystZ",  vZnunu["jesDN"],   vZnunu["jesUP"],       4, -1, "lnN");//XXX
      numnuis += addOneUnc(fLogStream, "PDFSystZ",  vZnunu["pdfDN"],       vZnunu["pdfUP"],       4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "QsqSystZ",  vZnunu["Q2DN"],        vZnunu["Q2UP"],        4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "AsSystZ",   vZnunu["alphaSDN"],    vZnunu["alphaSUP"],    4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "ISRSystZ",  vZnunu["ISRnjetsDown"], vZnunu["ISRnjetsUp"], 4, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "PUSystZ",  vZnunu["PUdown"],    vZnunu["PUup"],      4, -1, "lnN");
    }
    //bg2l
    //numnuis += addOneUnc(fLogStream, "TPtSyst2l", v2l["CR2l_ttbarSysPtDn"], v2l["CR2l_ttbarSysPtUp"], 1, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "MCSyst2l",  v2l["CR2l_mcStatsUp"],    v2l["CR2l_mcStatsDn"],    1, b, "lnN");
      numnuis += addOneUnc(fLogStream, "METSyst2l",  v2l["CR2l_metResdown"], v2l["CR2l_metResup"], 1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "TauSF2l", v2l["CR2l_tauSFDn"],        v2l["CR2l_tauSFUp"],     1, -1, "lnN");
      numnuis += addOneUnc(fLogStream, "TTPt2l", v2l["CR2l_metTTbarDn"],        v2l["CR2l_metTTbarUp"],     1, -1, "lnN");
      //cout << v2l["CR2l_metTTbarDn"] << " " << v2l["CR2l_metTTbarUp"] << endl;
    //bg1l
    
    numnuis += addOneUnc(fLogStream, "MCSyst1l",     v1l["mcStats_Dn"],      v1l["mcStats_Up"],      2,  b, "lnN");
    numnuis += addOneUnc(fLogStream, "WbxsSyst1l",   v1l["Wb_Dn"],      v1l["Wb_Up"],      2, -1, "lnN");
    //numnuis += addOneUnc(fLogStream, "WwidthSyst1l", v1l["W_width_Down"], v1l["W_width_Up"], 2, -1, "lnN");
    numnuis += addOneUnc(fLogStream, "ContSyst1l",   v1l["CRCont_Dn"],  v1l["CRCont_Up"],  2, -1, "lnN");
    //numnuis += addOneUnc(fLogStream, "NuPtSyst1l",   v1l["nu_pT_Down"],   v1l["nu_pT_Up"],   2, -1, "lnN");
    //numnuis += addOneUnc(fLogStream, "METSyst1l",  v1l["metres_Down"],  v1l["metres_Up"],  2, -1, "lnN");

    //bgznunu
    numnuis += addOneUnc(fLogStream, "MCstatsZ", vZnunu["mcStatsDN"], vZnunu["mcStatsUP"], 4,  b, "lnN");
  }
  *fLogStream << endl;
  //now correctly counted nuisances
  *fLogStreamHeader << "# My significance experiment" << endl
		    << "imax  " << 1     << "  number of channels" << endl//single bin
		    << "jmax  " << nbgs  << "  number of backgrounds" << endl
		    << "kmax "  << numnuis << "  number of nuisance parameters" << endl;
  //*fLogStreamFull << *fLogStream;
  //write out the datacard
  TString myoutputdir = outputdir;
  if(correlated)         myoutputdir = myoutputdir + "correlated/";
  if(nosigsyst&&nobgsyst) myoutputdir = myoutputdir + "nounc/";
  else if(nosigsyst)      myoutputdir = myoutputdir + "nosigsyst/";
  else if(nobgsyst)      myoutputdir = myoutputdir + "nobgsyst/";
  if(dropsigcont)        myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)           myoutputdir = myoutputdir + "fakedata/";
  MakeOutputDir(myoutputdir);
  TString anName = (TString)analysisname(analysis);
  TString logname = myoutputdir + "datacard_" + anName + "_" + signalname + "_" + binstring + ".txt";
  ofstream f_log (logname.Data(), ios::trunc);
  f_log << fLogStreamHeader->str();
  f_log << fLogStream->str();
  cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;
  delete fLogStream;

  //do this extra
  //comment out for now if code crashes: that happens if histograms and the file do not exist yet - still need to be fixed
  if(!fakedata&&!nosigsyst&&!nobgsyst&&!dropsigcont) UpdatePlottingHisto(analysis, signalname, b, data, sig, sigerr, vSig, bg2l, bg2lerr, v2l, bg1l, bg1lerr, v1l, bg1ltop, -1, v1ltop, bgznunu, bgznunuerr, vZnunu, nosigsyst, nobgsyst, dropsigcont, fakedata);

}

//up and down variations given - safe both, don't need to worry which one is bigger
//note: don't allow for >100% uncertainties for each source
int getSigUncertainty(double &errup, double &errdown, double origyield, TH3D *hup, TH3D *hdown, int bin){
  // upshape   = origyield + upvariation   --> want 1 + upvariation   / origyield
  // downshape = origyield + downvariation --> want 1 + downvariation / origyield, where downvariation < 0
  if(origyield<0){ errup = 1; errdown = 1; return 0; }
  errup = hup->GetBinContent(bin) / origyield;
  errdown = hdown->GetBinContent(bin) / origyield;
  if(errdown>0&&errup<=0) {cout << "switched for " << hup->GetName() << " uncertainties " << errup << " to " << -1 << endl; errup = -1;  }
  bool onereturn = false;
  if(std::isnan(errup)) { errup = -1; onereturn = true; }
  if(std::isnan(errdown)) { errdown = -1; onereturn = true; }
  if(onereturn) return -1;
  if(errup<0&&errup!=-1) errup = 0.0001;
  else if (errup>2) errup = 2;
  if(errdown<0&&errdown!=-1) errdown = 0.0001;
  else if (errdown>2) errdown = 2;
  if(errup==1&&errdown==1) return 0;
  return 1;
}
//up/down variations is given, but only one of the two
int getSigUncertaintyOneSided(double &err, double origyield, TH3D *h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = h->GetBinContent(bin) / origyield;
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//absolute error is given
int getSigError(double &err, double origyield, TH3D *h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = TMath::Abs(origyield+h->GetBinContent(bin))/origyield;
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//relative error is given
int getSigErrorRel(double &err, double origyield, TH3D* h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = 1+h->GetBinContent(bin);
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//up and down variations given - safe both, don't need to worry which one is bigger
int getBGUncertainty(double &errup, double &errdown, double origyield, TH1D *hup, TH1D *hdown, int bin){
  // upshape   = origyield + upvariation   --> want 1 + upvariation   / origyield
  // downshape = origyield + downvariation --> want 1 + downvariation / origyield, where downvariation < 0
  if(origyield<0){ errup = 1; errdown = 1; return 0; }
  bool onereturn = false;
  errup = hup->GetBinContent(bin) / origyield;
  errdown = hdown->GetBinContent(bin) / origyield;
  //why does this happen!!!! - make it one sided
  if(errdown>0&&errup==0) {/*cout << "switched for " << hup->GetName() << " uncertainties " << errup << " to " << -1 << endl;*/ errup = -1;  }
  if(std::isnan(errup)) { errup = -1; onereturn = true; }
  if(std::isnan(errdown)) { errdown = -1; onereturn = true; }
  if(onereturn) return -1;
  if(errup<0&&errup!=-1) errup = 0.0001;
  else if (errup>2) errup = 2;
  if(errdown<0&&errdown!=-1) errdown = 0.0001;
  else if (errdown>2) errdown = 2;
  if(errup==1&&errdown==1) return 0;
  return 1;
}
//up/down variations is given, but only one of the two
int getBGUncertaintyOneSided(double &err, double origyield, TH1D *h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = h->GetBinContent(bin) / origyield;
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//absolute error is given
int getBGError(double &err, double origyield, TH1D *h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = TMath::Abs(origyield+h->GetBinContent(bin))/origyield;
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//relative error is given
int getBGErrorRel(double &err, double origyield, TH1D* h, int bin){
  if(origyield<0){ err = 1; return 0; }
  err = 1+h->GetBinContent(bin);
  if(std::isnan(err)) { err = -1; return -1;}
  if(err<0&&err!=-1) err = 0.0001;
  else if (err>2) err = 2;
  if(err==1) return 0;
  return 1;
}

//get binnumber for LostLepton histograms, because people don't respect my bin numbering
//currently correct
int GetLLBin(int b){
  return b;
  cout << "This should not happen return -1" << endl;
  return -1;
}
//get 2l-CR bin corresponding to signal bin b (needed to respect statistical correlations)
// two bins are extrapolated - statistical uncertainty correlated!
int GetLLCRBin(int b){
  int btt2l = b;
  /* //this is now done in signal histo creation
  if(b==27) btt2l = 26;
  if(b==21) btt2l = 20;
  if(b==19) btt2l = 17;
  if(b==18) btt2l = 17;
  if(b==7) btt2l = 5;
  if(b==6) btt2l = 5;
  */
  return btt2l;
}
//get 0b-CR bin corresponding to signal bin b (needed to respect statistical correlations)
//no merged CR bins
int Get0bCRBin(int b){
  int bWst = b;
  return bWst;
}

//get binnumber for Znunu histograms, because people don't respect my bin numbering
int GetTTZBin(int b){
  return b;
  //return b+1;//TTZ file has preselection as bin 1
}

//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02

//clear - returns false if loading of at least one file failed (i.e. file non existing)
bool loadDataBGFiles(bool fakedata, int analysis){
  //cout << __LINE__ << endl;

  TString filename;
  f2l = new TFile();
  f1l = new TFile();
  f1ltop = new TFile();
  fznunu = new TFile();
  fdata = new TFile();
  string anname = analysisname(analysis);
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  if(!f2l->IsZombie()&&f2l->IsOpen()){
    cout << "Not opening 2l file - is already opened with name " << f2l->GetName() << endl;
    } else {
    filename = inputdir + "resultfiles/bkgEst_lostLepton__mlb_v2_bins__histos.root";
    if(analysis==1) filename = inputdir + "resultfiles/LostLepton_BkgEst_compressed.root";
    //cout << __LINE__ << " " << filename << endl;
  ifstream infileLL(filename.Data());
    if(!(infileLL.good() ) ) return false;
    //cout << __LINE__ << endl;
   f2l = TFile::Open(filename);
    if(f2l->IsZombie()) {
      f2l->Close();
      //delete f2l;
      cout << "No 2l file - exit" << endl;
      return false;
    }
  }
  if(f1l->IsOpen()){
    cout << "Not opening 1l file - is already opened with name " << f1l->GetName() << endl;
  } else {
    filename = inputdir + "resultfiles/Wjets.root";
    if(analysis==1) filename = inputdir + "resultfiles/WJets_BkgEst_compressed.root";
    //cout << __LINE__ << endl;
  ifstream infile0b(filename.Data());
    if(!(infile0b.good() ) ) return false;
    //cout << __LINE__ << endl;
   f1l = TFile::Open(filename);
    if(f1l->IsZombie()) {
      f1l->Close();
      //delete f1l;
      cout << "No 1l file - exit" << endl;
      return false;
    }
  }
  if(f1ltop->IsOpen()){
    cout << "Not opening 1ltop file - is already opened with name " << f1ltop->GetName() << endl;
  } else {
    //filename = inputdir + "resultfiles/bkgEst_1lepFromTop__mlb_v2_bins__histos.root";
    filename = inputdir + "resultfiles/TT1lSR.root";
    if(analysis==1) filename = inputdir + "resultfiles/TT1l_BkgEst_compressed.root";
    //cout << __LINE__ << endl;
   ifstream infile1lt(filename.Data());
    if(!(infile1lt.good() ) ) return false;
    //cout << __LINE__ << endl;
   f1ltop = TFile::Open(filename);
    if(f1ltop->IsZombie()) {
      f1ltop->Close();
      //delete f1ltop;
      cout << "No 1ltop file - exit" << endl;
      return false;
    }
  }
  if(fznunu->IsOpen()){
    cout << "Not opening znunu file - is already opened with name " << fznunu->GetName() << endl;
  } else {
    filename = inputdir + "resultfiles/Znunu_BkgEst_"+anname+".root";
    //cout << __LINE__ << endl;
    ifstream infilettz(filename.Data());
    if(!(infilettz.good() ) ) return false;
    //cout << __LINE__ << endl;
   fznunu = TFile::Open(filename);
    if(fznunu->IsZombie()) {
      fznunu->Close();
      //delete fznunu;
      cout << "No Znunu file - exit" << endl;
      return false;
    }
  }
  if(fdata->IsOpen()){
    cout << "Not opening data file - is already opened with name " << fdata->GetName() << endl;
  } else {
    if(!fakedata) {
      filename= inputdir + "resultfiles/DataSR.root";
    if(analysis==1) filename = inputdir + "resultfiles/DataSR_compressed.root";
    //cout << __LINE__ << endl;
      ifstream infileData(filename.Data());
      if(!(infileData.good() ) ) return false;
      //cout << __LINE__ << endl;
      fdata = TFile::Open(filename);
      if(fdata->IsZombie()) {
	fdata->Close();
	//delete fdata;
	cout << "No Data file - exit" << endl;
	return false;
      }
    }
    else fdata = (TFile*)f2l->Clone("FakeDataFile.root");
  }

  return true;
}

//clear - returns false if loading of at least one file failed (i.e. file non existing)
bool loadSignalFile(TString signaltype, int analysis){

  fsig = new TFile();
  TString filename;
  string anname = analysisname(analysis);
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  if(signaltype==lastsignalname){//if already open, don't reopen
    if(fsig->IsOpen()){
      cout << "Not opening signal file - is already opened with name " << fsig->GetName() << endl;
    } else {
      filename = inputdir + "signalyields/Histos_"+anname+"_Signal_" + signaltype + ".root";
      ifstream infileSig(filename.Data());
      if(!(infileSig.good() ) ) return false;
      fsig = TFile::Open(filename);
      if(fsig->IsZombie()) {
	fsig->Close();
	//delete fsig;
	cout << "No Signal file - exit" << endl;
	return false;
      }
    }
  } else {
    if(!fsig->IsZombie() && fsig->IsOpen()){
      cout << "Closing previous signal file " << fsig->GetName() << endl;
      fsig->Close();
      delete fsig;
    }
    filename = inputdir + "signalyields/Histos_"+anname + "_Signal_" + signaltype + ".root";
    ifstream infileSig(filename.Data());
    if(!(infileSig.good() ) ) return false;
    fsig = TFile::Open(filename);
    if(fsig->IsZombie()) {
      fsig->Close();
      //delete fsig;
      cout << "No Signal file - exit" << endl;
      return false;
    }
  }
  lastsignalname = signaltype;
  return true;
}

//clear - returns false if loading of at least one histograms failed (i.e. histogram non existing)
bool loadDataBGHistos(bool fakedata, int analysis){
  cout << __LINE__ << endl;

  hist2l["CR2l_yield"];
  hist2l["CR2l_bTagEffHFUp"];
  hist2l["CR2l_bTagEffHFDn"];
  hist2l["CR2l_bTagEffLFUp"];
  hist2l["CR2l_bTagEffLFDn"];
  hist2l["CR2l_lepSFUp"];
  hist2l["CR2l_lepSFDn"];
  hist2l["CR2l_tauSFUp"];
  hist2l["CR2l_tauSFDn"];
  hist2l["CR2l_pileupUp"];
  hist2l["CR2l_pileupDn"];
  //hist2l["CR2l_ttbarSysPtUp"];
  //hist2l["CR2l_ttbarSysPtDn"];
  hist2l["CR2l_ISRUp"];
  hist2l["CR2l_ISRDn"];
  hist2l["CR2l_mcStatsUp"];
  hist2l["CR2l_mcStatsDn"];
  hist2l["CR2l_dataStatsDn"];
  hist2l["CR2l_dataStatsUp"];
  ////hist2l["CR2l_PDFup"];
  ////hist2l["CR2l_PDFdown"];
  hist2l["CR2l_alphasUp"];
  hist2l["CR2l_alphasDn"];
  hist2l["CR2l_q2Dn"];
  hist2l["CR2l_q2Up"];
  hist2l["CR2l_jesUp"];//XXX
  hist2l["CR2l_jesDn"];//XXX
  hist2l["CR2l_cr2lTriggerSFUp"];
  hist2l["CR2l_cr2lTriggerSFDn"];
  hist2l["CR2l_metResUp"];
  hist2l["CR2l_metResDn"];
  hist2l["CR2l_metTTbarUp"];
  hist2l["CR2l_metTTbarDn"];
  cout << __LINE__ << " " << f2l->GetName() << endl;
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  for(map<string,TH1D*>::iterator h=hist2l.begin(); h!=hist2l.end();++h){
    if(f2l->GetListOfKeys()->Contains(h->first.c_str())) {
      h->second = (TH1D*)f2l->Get(h->first.c_str());
    } else {
      cout << "histogram " << h->first << " seems not to be in " << f2l->GetName() << " - please check. returning false;" << endl;
      return false;
    }
  }
  
  hist1l["CR1lyield"];
  hist1l["mcStats_Up"];
  hist1l["mcStats_Dn"];
  hist1l["Wb_Up"];
  hist1l["Wb_Dn"];
  hist1l["bTagEffHF_Up"];
  hist1l["bTagEffHF_Dn"];
  hist1l["bTagEffLF_Up"];
  hist1l["bTagEffLF_Dn"];
  hist1l["pdf_Up"];
  hist1l["pdf_Dn"];
  hist1l["q2_Up"];
  hist1l["q2_Dn"];
  hist1l["JES_Up"];
  hist1l["JES_Dn"];
  hist1l["CRCont_Up"];
  hist1l["CRCont_Dn"];
  //hist1l["metres_Up"];
  //hist1l["metres_Down"];
  //hist1l["W_width_Up"];
  //hist1l["W_width_Down"];
  //hist1l["nu_pT_Up"];
  //hist1l["nu_pT_Down"];
  hist1l["dataStats_Up"];
  hist1l["dataStats_Dn"];
  
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  cout << __LINE__ << " " << f1l->GetName() << endl;
  for(map<string,TH1D*>::iterator h=hist1l.begin(); h!=hist1l.end();++h){
    if(f1l->GetListOfKeys()->Contains(h->first.c_str())) {
      h->second = (TH1D*)f1l->Get(h->first.c_str());
    } else {
      cout << "histogram " << h->first << " seems not to be in " << f1l->GetName() << " - please check. returning false;" << endl;
      return false;
    }
  }
  cout << __LINE__ << " " << f1ltop->GetName() << endl;
  //hist1ltop["ee1lep_fromTop_yield"];
  hist1ltop["SR_Top"];
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  for(map<string,TH1D*>::iterator h=hist1ltop.begin(); h!=hist1ltop.end();++h){
    if(f1ltop->GetListOfKeys()->Contains(h->first.c_str())) {
      h->second = (TH1D*)f1ltop->Get(h->first.c_str());
    } else {
      cout << "histogram " << h->first << " seems not to be in " << f1ltop->GetName() << " - please check. returning false;" << endl;
      return false;
    }
  }
  histZnunu["yield"];
  histZnunu["mcStatsDN"];
  histZnunu["mcStatsUP"];
  histZnunu["Q2DN"];
  histZnunu["Q2UP"];
  histZnunu["pdfDN"];
  histZnunu["pdfUP"];
  histZnunu["btagLightDN"];
  histZnunu["btagLightUP"];
  histZnunu["btagHeavyDN"];
  histZnunu["btagHeavyUP"];
  histZnunu["alphaSDN"];
  histZnunu["alphaSUP"];
  histZnunu["PUdown"];
  histZnunu["PUup"];
  histZnunu["jesDN"];
  histZnunu["jesUP"];
  histZnunu["normalizationDN"];
  histZnunu["normalizationUP"];
  histZnunu["lepSFDN"];
  histZnunu["lepSFUP"];
  histZnunu["ISRnjetsDown"];
  histZnunu["ISRnjetsUp"];
  cout << __LINE__ << " " << fznunu->GetName() << endl;
  //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  for(map<string,TH1D*>::iterator h=histZnunu.begin(); h!=histZnunu.end();++h){
    if(fznunu->GetListOfKeys()->Contains(h->first.c_str())) {
      h->second = (TH1D*)fznunu->Get(h->first.c_str());
    } else {
      cout << "histogram " << h->first << " seems not to be in " << fznunu->GetName() << " - please check. returning false;" << endl;
      return false;
    }
  }
  histData["SR_Data"];
   //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
 if(fakedata) { histData["SR_Data"] = (TH1D*)hist2l["CR2l_yield"]->Clone("SR_Data"); }
  else {
    for(map<string,TH1D*>::iterator h=histData.begin(); h!=histData.end();++h){
      if(fdata->GetListOfKeys()->Contains(h->first.c_str())) {
	h->second = (TH1D*)fdata->Get(h->first.c_str());
      } else {
	cout << "histogram " << h->first << " seems not to be in " << fdata->GetName() << " - please check. returning false;" << endl;
	return false;
      }
    }
  }
  
  return true;

}

//clear - returns false if loading of at least one histograms failed (i.e. histogram non existing)
bool loadSignalHistos(int analysis){
  //cout << __LINE__ << endl;

  histSig["SRyield"];
  histSig["SRyield_gen"];
  histSig["SR_Xsecup"];
  histSig["SR_Xsecdown"];
  histSig["CR1l_sigcontamination"];
  histSig["CR2l_sigcontamination"];
  histSig["CR1l_sigcontamination_gen"];
  histSig["CR2l_sigcontamination_gen"];
  histSig["SR_Bup_HF"];
  histSig["SR_Bdown_HF"];
  histSig["SR_Bup_LF"];
  histSig["SR_Bdown_LF"];
  histSig["SR_Bup_FS"];
  histSig["SR_Bdown_FS"];
  histSig["SR_JESup"];
  histSig["SR_JESdown"];
  histSig["SR_muRFup"];
  histSig["SR_muRFdown"];
  histSig["SR_ISRup"];
  histSig["SR_ISRdown"];
  histSig["SR_PUup"];
  histSig["SR_PUdown"];
  histSig["SR_LepEffup"];
  histSig["SR_LepEffdown"];
  histSig["SR_LepEffFSup"];
  histSig["SR_LepEffFSdown"];
   //XAX - change file name based on analysis
  //XBX - change histogram name based on analysis
  for(map<string,TH3D*>::iterator h=histSig.begin(); h!=histSig.end();++h){
    if(fsig->GetListOfKeys()->Contains(h->first.c_str())) {
      h->second = (TH3D*)fsig->Get(h->first.c_str());
    } else {
      cout << "histogram " << h->first << " seems not to be in " << fsig->GetName() << " - please check. returning false;" << endl;
      return false;
    }
  }
  return true;

}

//helper function for addCorrelatedUnc:check if there is at least one good uncertainty
bool checkIfPos(double *d){

  for(unsigned int i = 0; i<maxnprocess; ++i){
 	if(d[i]>=0&&d[i]!=1) return true;
  }
  return false;
}
 
void resetArray(double *a){
  for(unsigned int i = 0; i<maxnprocess; ++i) a[i] = -1;
}
//helper function to make one line in datacard for correlated uncertainties
//please note, that the arrays d,u get reset with default values of -1
int addCorrelatedUnc(std::ostringstream *fLogStream, string name, double *d, double *u, int bin, string unctype){
  if(unctype.find(string("gmN")) != string::npos){
    for(unsigned int i = 0; i<maxnprocess; ++i){
      if(u[i]<0) {
	resetArray(d);
	resetArray(u);
	return 0;//all defined u's have to be >=0
      }
    }
  }
  if(!checkIfPos(d)) {
    resetArray(d);
    resetArray(u);
    return 0;
  }
  bool allfalse = true;
  for(int i = 0; i<maxnprocess; ++i){
    if(unctype.find(string("gmN")) != string::npos) allfalse = false;
    else if(d[i]>=0&&u[i] <0) allfalse = false;
    else if(fabs(d[i])<10e-10&&fabs(u[i])<10e-10) ;
    else if(fabs(d[i]-1.)<10e-10&&fabs(u[i]-1.)<10e-10) ;
    else if(d[i]>=0&&u[i]>=0) allfalse = false;
  }
  if(allfalse) {
    resetArray(d);
    resetArray(u);
    return 0;
  }
 *fLogStream << " " << setw(15) << name;
 if(bin>0) *fLogStream << bin;
 *fLogStream << "    " << unctype << " ";
 bool isgmN = false;
 if(unctype.find(string("gmN")) != string::npos) {
	*fLogStream << int(d[0]) << " ";
	isgmN = true;
 }

 for(int i = 0; i<maxnprocess; ++i){
   if(isgmN)                 *fLogStream << u[i] << " ";
   else if(fabs(d[i])<10e-10&&fabs(u[i])<10e-10) *fLogStream << "- ";
   else if(fabs(d[i]-1.)<10e-10&&fabs(u[i]-1.)<10e-10) *fLogStream << "- ";
   else if(d[i]>=0&&u[i] <0) {
     if(d[i]>=1) *fLogStream << d[i] << " ";
     else        *fLogStream << 2.-d[i] << " ";
   }
   else if(u[i]>=0&&u[i]==d[i]) {
     if(u[i]>=1) *fLogStream << u[i] << " ";
     else        *fLogStream << 2.-u[i] << " ";
   }
   else if(d[i]>=0&&u[i]>=0) {
     if(d[i]>=1&&u[i]>=1)     *fLogStream << TMath::Min(1.999,d[i]) << "/" << TMath::Min(1.999,u[i]) << " ";
     else if(d[i]>=1&&u[i]<1) *fLogStream << TMath::Min(1.999,d[i]) << "/" << TMath::Max(0.001,1./(2.-u[i])) << " ";
     else if(d[i]<1&&u[i]>=1) *fLogStream << TMath::Max(0.001,1./(2.-d[i])) << "/" << TMath::Min(1.999,u[i]) << " ";
     else                     *fLogStream << TMath::Max(0.001,1./(2.-d[i])) << "/" << TMath::Max(0.001,1./(2.-u[i])) << " ";
   }
   else                      *fLogStream << "- ";
 }
 //for(int i = 0; i<maxnprocess; ++i){
 //  if(isgmN)                 *fLogStream << u[i] << " ";
 //  else if(d[i]>=0&&u[i] <0) *fLogStream << d[i] << " ";
 //  else if(fabs(d[i])<10e-10&&fabs(u[i])<10e-10) *fLogStream << "- ";
 //  else if(fabs(d[i]-1.)<10e-10&&fabs(u[i]-1.)<10e-10) *fLogStream << "- ";
 //  else if(u[i]>=0&&u[i]==d[i]) *fLogStream << u[i] << " ";
 //  else if(d[i]>=0&&u[i]>=0) *fLogStream << TMath::Max(0.001,d[i]) << "/" << TMath::Min(1.999,u[i]) << " ";
 //  else                      *fLogStream << "- ";
 //}
 *fLogStream << endl;
 resetArray(d);
 resetArray(u);
 return 1;
}
 
//helper function to make one line in datacard for uncorrelated uncertainties
int addOneUnc(std::ostringstream *fLogStream, string name, double d, double u, int process, int bin, string unctype){
  if(fabs(d)<10e-10) return 0;
  //if(d>0&&u==0) cout << name << " " << d << " " << u << endl;//return;
  if(fabs(d)<10e-10&&fabs(u)<10e-10) return 0;
  if(fabs(d-1.)<10e-10&&fabs(u-1.)<10e-10) return 0;
  if(fabs(d-1.)<10e-10&&u<0) return 0;
  if(unctype.find(string("gmN")) != string::npos && u<0) return 0;
  *fLogStream << " " << setw(15) << name;
  if(bin>0) *fLogStream << bin;
  *fLogStream << " " << setw(6) << unctype << " ";
  if(unctype.find(string("gmN")) != string::npos) {
    *fLogStream << int(d) << " ";
    d = -1;
  }
  for(int i = 0; i<process; ++i) *fLogStream << "- ";
  //if(d==0){ d = 0.001; }
  //if(d<0)      *fLogStream << u << " ";//gmN
  //else if(u<0) *fLogStream << d << " ";//only one uncertainty
  //else if(u==d)*fLogStream << d << " ";
  //else         *fLogStream << TMath::Max(0.001,d) << "/" << TMath::Min(1.999,u) << " ";
  if(d==0){ d = 2.0; }
  if(d<0)      *fLogStream << u << " ";//gmN
  else if(u<0){
    if(d>=1) *fLogStream << d << " ";//only one uncertainty
    else     *fLogStream << 2.-d << " ";//only one uncertainty
  }
  else if(u==d){
    if(d>=1) *fLogStream << d << " ";//only one uncertainty
    else     *fLogStream << 2.-d << " ";//only one uncertainty 
  }
  else {
    if(d>=1&&u>=1)     *fLogStream << TMath::Min(1.999,d) << "/" << TMath::Min(1.999,u) << " ";
    else if(d>=1&&u<1) *fLogStream << TMath::Min(1.999,d) << "/" << TMath::Max(0.001,1./(2.-u)) << " ";
    else if(d<1&&u>=1) *fLogStream << TMath::Max(0.001,1./(2.-d)) << "/" << TMath::Min(1.999,u) << " ";
    else               *fLogStream << TMath::Max(0.001,1./(2.-d)) << "/" << TMath::Max(0.001,1./(2.-u)) << " ";
  }
  for(int i = process + 1; i<maxnprocess; ++i) *fLogStream << "- ";
  *fLogStream << endl;
  return 1;
}


//define histograms and tfiles at beginning of datacard maker
bool loadAll(TString signaltype, bool fakedata, int analysis){
  
  bool l1 = loadDataBGFiles(fakedata,analysis);
  bool l2 = loadSignalFile(signaltype,analysis);
  bool l3 = loadDataBGHistos(fakedata,analysis);
  bool l4 = loadSignalHistos(analysis);
  cout << l1 << " " << l2 << " " << l3 << " " << l4 << endl;
  return (l1&&l2&&l3&&l4);
}

//if switching signal - reload it
bool reloadSignal(TString signaltype, int analysis){

  for(map<string,TH3D*>::iterator h=histSig.begin(); h!=histSig.end();++h) h->second->Delete();
  fsig->Close();
  delete fsig;
  bool l2 = loadSignalFile(signaltype, analysis);
  bool l4 = loadSignalHistos(analysis);
  return (l2&&l4);
}

//delete histograms and TFiles at the end of datacard maker
bool closeAll(bool fakedata){

  for(map<string,TH3D*>::iterator h=histSig.begin(); h!=histSig.end();++h) h->second->Delete();
  fsig->Close();
  if(!fakedata){
    for(map<string,TH1D*>::iterator h=histData.begin(); h!=histData.end();++h) h->second->Delete();
    fdata->Close();
  }
  for(map<string,TH1D*>::iterator h=histZnunu.begin(); h!=histZnunu.end();++h) h->second->Delete();
  fznunu->Close();
  for(map<string,TH1D*>::iterator h=hist1ltop.begin(); h!=hist1ltop.end();++h) h->second->Delete();
  f1ltop->Close();
  for(map<string,TH1D*>::iterator h=hist1l.begin(); h!=hist1l.end();++h) h->second->Delete();
  f1l->Close();
  for(map<string,TH1D*>::iterator h=hist2l.begin(); h!=hist2l.end();++h) h->second->Delete();
  f2l->Close();

  delete fsig;
  if(!fakedata) delete fdata;
  delete fznunu;
  delete f1ltop;
  delete f1l;
  delete f2l;
  return true;
}

int analysismaxbin(int analysis){
  if(analysis==0) return 27;
  if(analysis==1) return 4;
  else return -1;
}
int analysisbinoffset(int analysis){
  if(analysis==0) return 0;
  if(analysis==1) return 0;
  else return -1;
}

string analysisname(int analysis){
  if(analysis==0) return "std";//standard 
  if(analysis==1) return "compressed";//compressed 
  else return "BS";
}
bool validanalysis(int analysis){
  if(analysis<0) return false;
  if(analysis>1) return false;
  return true;
}
int analysisID(string analysisname){
  if(analysisname.find(string("std")) != string::npos) return 0;
  if(analysisname.find(string("compressed")) != string::npos) return 1;
  else return -1;
}


int minstopmass(TString signaltype){
  if(signaltype.Contains("T2tt")) return 150;
  if(signaltype.Contains("T2tb")) return 200;
  if(signaltype.Contains("T2bW")) return 200;
  return -1;
}
int maxstopmass(TString signaltype){
  if(signaltype.Contains("T2tt")) return 1200;
  if(signaltype.Contains("T2tb")) return 1200;
  if(signaltype.Contains("T2bW")) return 1200;
  return -1;
}
int minlspmass(TString signaltype){
  if(signaltype.Contains("T2tt")) return 0;
  if(signaltype.Contains("T2tb")) return 0;
  if(signaltype.Contains("T2bW")) return 0;
  return -1;
}
int maxlspmass(TString signaltype){
  if(signaltype.Contains("T2tt")) return 650;
  if(signaltype.Contains("T2tb")) return 650;
  if(signaltype.Contains("T2bW")) return 650;
  return -1;
}

 
//returns binnumber of 1 dimensional histogram and checks if bin is valid, if not valid return -1 
int checkbin(int analysis, int bin, double stop, double lsp, bool dropsigcont){

  //cout << analysis << " " << bin << " " << stop << " " << lsp << " " << endl;
  if(stop<lsp) return -1;
  if(bin<=0) return -1;
  if(stop<0) return -1;
  if(lsp<0)  return -1;
  if(analysis==0){
    if(bin>27) return -1;
  }
  else if(analysis==1){
    if(bin>4) return -1;
  }
  else return -1;

  int b,b3;
  b = bin;
  if(analysis!=0) b += analysisbinoffset(analysis);
  int bx,by,bz;
  bx = histSig["SRyield"]->GetXaxis()->FindBin(stop);
  by = histSig["SRyield"]->GetYaxis()->FindBin(lsp);
  bz = histSig["SRyield"]->GetZaxis()->FindBin(b);
  if(bx>histSig["SRyield"]->GetXaxis()->GetNbins()){
    cout << "xaxis out of range - exit" << endl;
    return -1;
  }
  if(by>histSig["SRyield"]->GetYaxis()->GetNbins()){
    cout << "yaxis out of range - exit" << endl;
    return -1;
  }
  if(bz>histSig["SRyield"]->GetZaxis()->GetNbins()){
    cout << "zaxis out of range - exit" << endl;
    return -1;
  }
  b3 = histSig["SRyield"]->FindBin(stop,lsp,b);
  if(b3!=histSig["SRyield"]->GetBin(bx,by,bz)) cout << "Check this " << "b:stop:lsp " << b << ":" << stop << ":" << lsp << " are bins " << bx << ":"<<by<<":"<<bz <<" are global bin " << histSig["SRyield"]->GetBin(bx,by,bz) << " and also should be findbin b3 " << b3 << endl;
  int bLL = GetLLBin(b);
  int bTTZ = GetTTZBin(b);
  int bW = b;
  //cout << bLL << " " << bTTZ << " " << bW << endl;
  if(bLL>hist2l["CR2l_yield"]->GetNbinsX()) return -1;
  if(bW>hist1l["CR1lyield"]->GetNbinsX()) return -1;
  //if(bW>hist1ltop["ee1lep_fromTop_yield"]->GetNbinsX()) return -1;
  if(bW>hist1ltop["SR_Top"]->GetNbinsX()) return -1;
  if(bTTZ>histZnunu["yield"]->GetNbinsX()) return -1;
  if(b>histData["SR_Data"]->GetNbinsX()) return -1;
  //get all yields and statistical uncertainties - also signal contamination
  double sig = histSig["SRyield"]->GetBinContent(b3);
  //cout << "sig " << sig << endl;
  if(sig<0) return -1;
  if(!dropsigcont){
    double temp = histSig["CR1l_sigcontamination"]->GetBinContent(b3); sig = TMath::Max(0., sig-temp);
    temp = histSig["CR2l_sigcontamination"]->GetBinContent(b3); sig = TMath::Max(0., sig-temp);
  }
  double sig2 = histSig["SRyield_gen"]->GetBinContent(b3);
  if(sig2<0) return -1;
  if(!dropsigcont){
    double temp = histSig["CR1l_sigcontamination_gen"]->GetBinContent(b3); sig2 = TMath::Max(0., sig2-temp);
    temp = histSig["CR2l_sigcontamination_gen"]->GetBinContent(b3); sig2 = TMath::Max(0., sig2-temp);
  }
  //cout << sig << " " << sig2 << endl;
  if((sig+sig2)/2.<0) return -1;
  bool signalexists = false;
  for(int z = 1; z<=histSig["SRyield"]->GetNbinsZ();++z){
    if(histSig["SRyield"]->GetBinContent(histSig["SRyield"]->FindBin(stop,lsp,z))>0){
      signalexists = true;
      break;
    }
  }
  if(!signalexists) return -1;//make sure to run on actual signal points
  if(hist2l["CR2l_yield"]->GetBinContent(bLL)<0) return -1;
  if(hist1l["CR1lyield"]->GetBinContent(bW)<0) return -1;
  //if(hist1ltop["ee1lep_fromTop_yield"]->GetBinContent(bW)<0) return -1;
  if(hist1ltop["SR_Top"]->GetBinContent(bW)<0) return -1;
  if(histZnunu["yield"]->GetBinContent(bTTZ)<0) return -1;
  if(histData["SR_Data"]->GetBinContent(b)<0) return -1;

  return b;
}

//a and b are relative uncertainties in notation 1 +/- unc
double add2(double a, double b){
  if(a<=0&&b<=0) return -1;
  if(a<0) return pow(b-1.,2);
  if(b<0) return pow(a-1.,2);
  //use arithmetic mean
  //return pow((fabs(a-1.) + fabs(b-1.) ) / 2.,2);
  //use geometric mean
  //return pow(sqrt(fabs(a-1.) * fabs(b-1.)),2);
  //use arithmetic-geometric mean
  double a1 = (fabs(a-1.) + fabs(b-1.) ) / 2.;
  double g1 = sqrt(fabs(a-1.)*fabs(b-1.));
  //arit
  while(fabs(a1-g1)>0.01*a1){
    //iterate until we get 1% agreement
    double aold = a1; double gold = g1;
    a1 = (aold+gold)/2.;
    g1 = sqrt(aold*gold);
  }
  return pow((a1+g1)/2.,2);
}


//creates histograms for plotting and making table
//currently buggy: will crash if either file or one histogram does not exist - still needs to be fixed
//data poisson statistics not done correctly - do that downstream
void UpdatePlottingHisto(int analysis, TString signalname, int b, int data, double sig, double sigerr, map<string, double> vSig, double bg2l, double bg2lerr, map<string, double> v2l, double bg1l, double bg1lerr, map<string, double> v1l, double bg1ltop, double bg1ltoperr, map<string, double> v1ltop, double bgznunu, double bgznunuerr, map<string, double> vZnunu, bool nosigsyst, bool nobgsyst, bool dropsigcont, bool fakedata){
  bool addthissignal = false;
  if(     signalname== "T2tt_850_50") addthissignal = true;
  else if(signalname=="T2tt_600_300") addthissignal = true;
  else if(signalname=="T2tt_400_200") addthissignal = true;
  else if(signalname=="T2tt_300_200") addthissignal = true;
  else if(signalname== "T2bW_850_50") addthissignal = true;
  else if(signalname=="T2bW_600_300") addthissignal = true;
  else if(signalname=="T2bW_400_200") addthissignal = true;
  else if(signalname=="T2bW_300_200") addthissignal = true;
  else if(signalname=="T2bW_550_300") addthissignal = true;
  else if(signalname=="T2bW_750_50") addthissignal = true;

  if(!addthissignal) return;
  //for background this is fine

  TString uname = inputdir;
  if(nosigsyst&&nobgsyst) uname = uname + "nounc/";
  else if(nosigsyst)      uname = uname + "nosigsyst/";
  else if(nobgsyst)      uname = uname + "nobgsyst/";
  if(dropsigcont)        uname = uname + "dropsigcont/";
  if(fakedata)           uname = uname + "fakedata/";
  MakeOutputDir(uname);
  TString ananame = "";
  ananame = analysisname(analysis);
  if(ananame=="") uname = uname + "ResultPlotTable.root";
  else uname = uname + "ResultPlotTable_" + ananame + ".root";
  TFile *updatefile = new TFile(uname,"update");
  updatefile->cd();
  TH1D *rpt_Data;
  TH1D *rpt_LLest;
  TH1D *rpt_0best;
  TH1D *rpt_tt1l;
  TH1D *rpt_znunu;
  TH1D *rpt_sig;
  const int maxbin = analysismaxbin(analysis);
  double upborder  = double(analysismaxbin(analysis));
  bool udata(false), uLL(false), u0b(false), utt1l(false), uZ(false),usig(false);
  if(updatefile->GetListOfKeys()->Contains("rpt_Data")) { udata=true; rpt_Data = (TH1D*)updatefile->Get("rpt_Data"); }
  else rpt_Data = new TH1D("rpt_Data","",maxbin,0,upborder);
  if(updatefile->GetListOfKeys()->Contains("rpt_LLest")) { uLL=true; rpt_LLest = (TH1D*)updatefile->Get("rpt_LLest"); }
  else rpt_LLest = new TH1D("rpt_LLest","",maxbin,0,upborder);
  if(updatefile->GetListOfKeys()->Contains("rpt_0best")) { u0b=true; rpt_0best = (TH1D*)updatefile->Get("rpt_0best"); }
  else rpt_0best = new TH1D("rpt_0best","",maxbin,0,upborder);
  if(updatefile->GetListOfKeys()->Contains("rpt_tt1l")) { utt1l=true; rpt_tt1l = (TH1D*)updatefile->Get("rpt_tt1l"); }
  else rpt_tt1l = new TH1D("rpt_tt1l","",maxbin,0,upborder);
  if(updatefile->GetListOfKeys()->Contains("rpt_znunu")) { uZ=true; rpt_znunu = (TH1D*)updatefile->Get("rpt_znunu"); }
  else rpt_znunu = new TH1D("rpt_znunu","",maxbin,0,upborder);
  TString sigtemp = "rpt_" + signalname;
  if(updatefile->GetListOfKeys()->Contains(sigtemp.Data())) { usig=true; rpt_sig = (TH1D*)updatefile->Get(sigtemp.Data() ); }
  else rpt_sig = new TH1D(sigtemp.Data(),"",maxbin,0,upborder);
   

  rpt_Data->SetBinErrorOption(TH1::kPoisson);
  rpt_Data->SetBinContent(b,data);//rpt_Data->SetBinError(b,0); //redo data later
  //for(int n = 1; n<=int(data); ++n) rpt_Data->Fill(bt,1);//make sure you got correct poissonian error
  double err2 = 0;
  rpt_LLest->SetBinContent(b,bg2l);
  rpt_LLest->SetBinError(b, bg2l * sqrt(add2(bg2lerr,-1) + add2(v2l["CR2l_bTagEffHFUp"],v2l["CR2l_bTagEffHFDn"]) + add2(v2l["CR2l_bTagEffLFUp"],v2l["CR2l_bTagEffLFDn"]) + add2(v2l["CR2l_lepSFUp"],v2l["CR2l_lepSFDn"]) + /*add2(v2l["CR2l_ttbarSysPtUp"],v2l["CR2l_ttbarSysPtDn"])+*/add2(v2l["CR2l_mcStatsUp"],v2l["CR2l_mcStatsDn"])+add2(v2l["CR2l_alphasUp"],v2l["CR2l_alphasDn"]) + add2(v2l["CR2l_q2Up"],v2l["CR2l_q2Dn"]) + add2(v2l["CR2l_jesUp"],v2l["CR2l_jesDn"]) + add2(v2l["CR2l_cr2lTriggerSFUp"],v2l["CR2l_cr2lTriggerSFDn"]) /*+ add2(v2l["CR2l_muRFup"],v2l["CR2l_muRFdown"]) + add2(v2l["CR2l_jesup"],v2l["CR2l_jesdown"]) + add2(v2l["CR2l_metResup"],v2l["CR2l_metResdown"])*/ ) );
  //define add2 xxxxyyyyZZZZ
  //cout << "b " << b << " LLyield " << rpt_LLest->GetBinContent(b) << " +/- " << rpt_LLest->GetBinError(b) << endl;  rpt_0best->SetBinContent(b,bg1l);
  if(b<=7||b>=11) rpt_0best->SetBinError(b,bg1l*sqrt(add2(bg1lerr,-1) + add2(v1l["MC_Up"],v1l["MC_Down"]) + add2(v1l["Wb_Up"],v1l["Wb_Down"]) + add2(v1l["btag_HF_Up"],v1l["btag_HF_Down"]) + add2(v1l["btag_LF_Up"],v1l["btag_LF_Down"]) + add2(v1l["PDF_Up"],v1l["PDF_Down"]) + add2(v1l["Q2_Up"],v1l["Q2_Down"]) + add2(v1l["JES_Up"],v1l["JES_Down"]) + add2(v1l["CRCont_Up"],v1l["CRCont_Down"]) + add2(v1l["metres_Up"],v1l["metres_Down"]) /*+ add2(v1l["W_width_Up"],v1l["W_width_Down"]) + add2(v1l["nu_pT_Up"], v1l["nu_pT_Down"])*/ ) );
  else rpt_0best->SetBinError(b,bg1l);
  rpt_tt1l->SetBinContent(b,bg1ltop);
  rpt_tt1l->SetBinError(b,bg1ltop*sqrt(add2(v1ltop["tt1lyielderr"],-1) ) );
  rpt_znunu->SetBinContent(b,bgznunu);
  rpt_znunu->SetBinError(b,bgznunu*sqrt(add2(bgznunuerr,-1) + add2(vZnunu["PU"],-1) + add2(vZnunu["JES"],-1) + add2(vZnunu["Top"], -1) + add2(vZnunu["BTagH"],-1) + add2(vZnunu["BTagL"],-1) + add2(vZnunu["PDF"],-1) + add2(vZnunu["Scale"],-1) + add2(vZnunu["Lep"],-1) + add2(vSig["triggerrUp"],vSig["triggerrDn"]) + add2(vSig["lumierr"],-1) ) );
  rpt_sig->SetBinContent(b,sig);
  rpt_sig->SetBinError(b,sig*sqrt(add2(sigerr,-1) + add2(vSig["SR_Bup_HF"],vSig["SR_Bdown_HF"]) + add2(vSig["SR_Bup_LF"],vSig["SR_Bdown_LF"]) + add2(vSig["SR_JESup"],vSig["SR_JESdown"]) + add2(vSig["SR_muRFup"], vSig["SR_muRFdown"]) + add2(vSig["SR_ISRup"],vSig["SR_ISRdown"]) + add2(vSig["SR_LepEffup"], vSig["SR_LepEffdown"]) + add2(vSig["SR_LepEffFSup"],vSig["SR_LepEffFSdown"]) + add2(vSig["triggerrUp"],vSig["triggerrDn"]) + add2(vSig["lumierr"],-1) + add2(vSig["SR_PUup"],vSig["SR_PUdown"]) + add2(vSig["SR_LEffVetoerr"],-1) ) );
  updatefile->cd();
  rpt_Data ->Write(rpt_Data ->GetName(),TObject::kOverwrite);//see TObject
  rpt_LLest->Write(rpt_LLest->GetName(),TObject::kOverwrite);
  rpt_0best->Write(rpt_0best->GetName(),TObject::kOverwrite);
  rpt_tt1l ->Write(rpt_tt1l ->GetName(),TObject::kOverwrite);
  rpt_znunu->Write(rpt_znunu->GetName(),TObject::kOverwrite);
  rpt_sig  ->Write(rpt_sig  ->GetName(),TObject::kOverwrite);
  updatefile->Close();
  //deleting those results in crashes ...
  
  if(!udata) delete rpt_Data;
  if(!uLL  ) delete rpt_LLest;
  if(!u0b  ) delete rpt_0best;
  if(!utt1l) delete rpt_tt1l;
  if(!uZ   ) delete rpt_znunu;
  //if(!usig ) delete rpt_sig;//cannot delete as it will be reused by other signals

  delete updatefile;
  return;
}

