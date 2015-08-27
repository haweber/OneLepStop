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

// do this more correctly - want this as global variables
const int bgsize = 5;
TString sample_type[bgsize] = {"TTbar2l","TTbar1l", "WJets", "SingleTop", "TTV"};
int sample_id[bgsize] = {1, 2, 3, 4, 5};
const int maxsignal = 9;
unsigned int binnumbertranslate[maxsignal] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
TString binname[maxsignal] = {"met250_mt2w0", "met250_mt2w200", "met300_mt2w0", "met300_mt2w200", "met350_mt2w0", "met350_mt2w200", "met400_mt2w0", "met400_mt2w200", "met500_mt2w200"};
//unsigned int binnumbertranslate[maxsignal] = {1, 3, 5, 7, 2, 4, 6, 8, 9};
//TString binname[maxsignal] = {"met250_mt2w0", "met300_mt2w0", "met350_mt2w0", "met400_mt2w0", "met250_mt2w200", "met300_mt2w200", "met350_mt2w200", "met400_mt2w200", "met500_mt2w200"};

// READ in txt files - lnN
//
//
// PROCESS BIN YIELD BIN YIELD BIN
// SYSTNAME BIN REL.UNC BIN REL.UNC BIN
//
//Example
//  TTbar1lSR 1 24.4 2 12.4 3 3.2
//  TTbar1lCR 1 24 2 12 3 3 #if background is estimated from a control region - values must be integers !
//  TTbar1lNorm1 1 1.1
//  TTbar1lNorm2 2 1.2 //NEED different name
//  TTbar1lParticalCor 1 1.1 3 2.1
//  TTbar1lTotalCor 1 1.1 2 -1.2 3 2.1//Minus sign means anti-correlated

//TO DO:
//Possibility of READ IN ROOT FILES instead of TEXT FILES
//Possibility of a CR to be the estimate of different SR (i.e. correlated CR)
//Possibility of creating multiple data cards in one batch (especially if we use a grid) - here rootfiles for reading in numbers might be helpful (is not necessary)

struct entry{
  entry() : sample(""), sampleid(-1), bin(-1), value(-999.), valueCR(-999.), alpha(-999.), uncertname(), uncert() {}
  TString sample;
  int sampleid;
  int bin;
  double value;
  double valueCR;
  double alpha;
  vector<TString> uncertname;
  vector<double>  uncert;
};


int setsampleid(TString sample);
bool SortEntrybyBin(entry const& lhs, entry const& rhs);
bool SortEntrybyBinAndProcess(entry const& lhs, entry const& rhs);
double rnd(double d);
void makeDataCards(int bin, TString signaltype, TString signalname, bool overrightdatawithBG=false, bool overrightdatawithBGplusSIG=false);
entry load(unsigned int bin, string filedir, string sample, bool issignal=false, string signalname="");
void makeDataCardsScan(TString signaltype="T2tt", bool overrightdatawithBG=false, bool overrightdatawithBGplusSIG=false, int stoplow=100, int stophigh=1000, int stopstep=25, int LSPlow=0, int LSPhigh=500, int LSPstep=25, int chargLow=-1, int chargHigh=-1, int chargStep=-1, double xval=-1);

//filename - of rootfile
//only for signal we need to specify the masses
//note: this function determines correlations by setting the uncertname
entry load(unsigned int bin, string filedir, string sample, bool issignal, string signalname){

  //int mybin = binnumbertranslate[bin-1];//until it gets fixed
  //cout << bin << " " << filedir << " " << sample << " " << issignal << " " << signalname << endl;
  entry result;
  result.sample = sample;
  if(issignal) result.sample = "signal";
  result.sampleid = setsampleid(result.sample);
  //result.bin = mybin;//until it gets fixed
  result.bin = bin;

  string filename = filedir + sample + ".root";
  if(issignal) filename = filedir + "Signal_" + sample + ".root";//MODIFY INPUT HERE?
  TFile *f = new TFile(filename.c_str(),"READ");
  if(f->IsZombie()) {
    f->Close();
    delete f;
    result.sample = "FAILED_" + result.sample;
    return result;
  }
  f->cd();
  string samplename = sample;
  if(issignal) samplename = "Signal_" + signalname;//MODIFY INPUT HERE?
  map<string, TH1F*> histos;
  string mapname;
  mapname = "SRyield_"+samplename; histos[mapname] = (TH1F*)f->Get(mapname.c_str());
  mapname = "CRyield_"+samplename; histos[mapname] = (TH1F*)f->Get(mapname.c_str());
  mapname = "StatUnc_"+samplename; histos[mapname] = (TH1F*)f->Get(mapname.c_str());
  mapname = "SystUnc_"+samplename; histos[mapname] = (TH1F*)f->Get(mapname.c_str());
  
  if(histos["SRyield_"+samplename]->Integral()<=0) {
    f->Close();
    delete f;
    return result;//don't run over samples that are empty, i.e. no uncertainties set
  }
  result.value = histos["SRyield_"+samplename]->GetBinContent(bin);
  if(histos["CRyield_"+samplename]->Integral()>0) result.valueCR = histos["CRyield_"+samplename]->GetBinContent(bin);//only if there is any CR with data use this
  //result.alpha = histos["Alpha_"+samplename]->GetBinContent(bin);
  if(result.valueCR>0) result.alpha = result.value/result.valueCR; else if(result.valueCR==0) result.alpha = 1.;
  //string binstring = std::to_string(mybin);//until it gets fixed
  string binstring = std::to_string(bin);
  string uncertname;
  if(!issignal&&result.value>=0&&histos["StatUnc_"+samplename]->GetBinContent(bin)>=0){//add statistical uncertainty only if there has been some entries
    uncertname= result.sample + "Stat" + binstring;
    result.uncertname.push_back(uncertname);
    result.uncert.push_back(1.+histos["StatUnc_"+samplename]->GetBinContent(bin));//1.+ rel.unc.
  }
  uncertname= result.sample + "Syst" + binstring;//fully uncorrelated
  ///if(issignal)  uncertname= result.sample + "Syst";
  //uncertname= result.sample + "Syst";//correlated for each background source
  //uncertname= "BGSyst";//correlated for all backgrounds (need here an if statement to exclude signal)
  //uncertname = "Syst";//fully correlated among signal and background
  result.uncertname.push_back(uncertname);
  result.uncert.push_back(1.+histos["SystUnc_"+samplename]->GetBinContent(bin));//1.+ rel.unc.
  ///result.uncertname.push_back("TestUnc");
  ///result.uncert.push_back(1.5);
  //mapname = "SRyield_"+samplename; histos[mapname]->Delete();
  //mapname = "CRyield_"+samplename; histos[mapname]->Delete();
  //mapname = "StatUnc_"+samplename; histos[mapname]->Delete();
  //mapname = "SystUnc_"+samplename; histos[mapname]->Delete();
  f->Close();
  //f->Delete();
  delete f;
    
  return result;
  
}

void makeDataCards(int bin, TString signaltype, TString signalname, bool overrightdatawithBG, bool overrightdatawithBGplusSIG){
  //signal type is like T2tt
  //signal name is like T2tt_850_100

  //int mybin = binnumbertranslate[bin-1];//until it gets fixed

  bool loadData = true;
  if(overrightdatawithBG||overrightdatawithBGplusSIG) loadData=false;
  entry tempentry;
  vector<entry> backgrounds;
  entry data;
  entry signal;
  //string inputdir = "/home/users/haweber/StopAnalysis/CombineCode/inputfiles/";//need slash at the end
  string inputdir = "inputfiles/";//need slash at the end
  if(loadData){
    data = load(bin,inputdir,"Data",false,"");
    if(data.sample.Contains("FAILED")) cout << "Failed to load input for making datacard for bin " << bin << " and sample Data -- break" << endl;
    return;
  }
  signal = load(bin,inputdir,signaltype.Data(),true,signalname.Data());
  if(signal.sample.Contains("FAILED")) {
    cout << "Failed to load input for making datacard for bin " << bin << " and sample " << signalname << " -- break" << endl;
    return;
  }
  if(signal.value<0) return;//if using scans, don't write files where signal does not exist
  for(unsigned int i = 0; i<bgsize;++i){//bg is sorted
    tempentry = load(bin,inputdir, sample_type[i].Data(),false,"");
    if(!tempentry.sample.Contains("FAILED")) {
      backgrounds.push_back(tempentry);
    } else{
      cout << "Failed to load data for making datacard for bin " << bin << " and sample " << sample_type[i] << endl;
    }
  }
  if(overrightdatawithBG&&!overrightdatawithBGplusSIG){
    data.value = 0;
    for(unsigned int j = 0; j<backgrounds.size(); ++j){
      data.value += backgrounds[j].value;
    }
    data.value = rnd(data.value);
  }
  if(overrightdatawithBGplusSIG){
    data.value = 0;
    for(unsigned int j = 0; j<backgrounds.size(); ++j){
      data.value += backgrounds[j].value;
    }
    data.value += signal.value;
    data.value = rnd(data.value);
  }
  
  vector<TString> uncertstring; uncertstring.clear();//store all independent uncertainties into a vector not counting CR statistics
  unsigned int nCR = 0;//N CR statistics
  for(unsigned int i = 0; i<signal.uncertname.size(); ++i){
    if ( find(uncertstring.begin(), uncertstring.end(), signal.uncertname[i])==uncertstring.end() ) uncertstring.push_back(signal.uncertname[i]);
  }
  for(unsigned int j = 0; j<backgrounds.size(); ++j){
    if(backgrounds[j].alpha>0) ++nCR;
    for(unsigned int i = 0; i<backgrounds[j].uncertname.size(); ++i){
      if ( find(uncertstring.begin(), uncertstring.end(), backgrounds[j].uncertname[i])==uncertstring.end() ) uncertstring.push_back(backgrounds[j].uncertname[i]);
    }
  }
  
  std::ostringstream* fLogStream     = 0;
  fLogStream = new std::ostringstream();

  unsigned int imax = 1;          //Number of signal regions //bin by bin
  unsigned int jmax = backgrounds.size();   //Number of background types
  unsigned int kmax = uncertstring.size() + nCR; //Number of independent uncertainties + counting CR with alpha
  //CONTINUE HERE

  *fLogStream << "# My significance experiment" << endl
	      << "imax " << imax << "  number of channels" << endl
	      << "jmax " << jmax << "  number of backgrounds" << endl
	      << "kmax " << kmax << "  number of nuisance parameters" << endl;
  *fLogStream << "------------" << endl << "# observations " << endl;
  //*fLogStream << setw(30) << left << "bin" << " " << setw(10) << left << mybin;//until it gets fixed
  *fLogStream << setw(30) << left << "bin" << " " << setw(10) << left << bin;
  *fLogStream << endl << setw(30) << left << "observation" << " " << setw(10) << left << data.value;
  *fLogStream << endl << "------------" << endl;
  *fLogStream << "#now we list all expected number of events" << endl;
  *fLogStream << setw(30) << left << "bin";
  //*fLogStream << " " << setw(12) << left << mybin;//signal//until it gets fixed
  *fLogStream << " " << setw(12) << left << bin;//signal
  for(unsigned int j =0; j< jmax; ++j){
    //*fLogStream << " " << setw(12) << left << mybin;//until it gets fixed
    *fLogStream << " " << setw(12) << left << bin;
  }
  *fLogStream << endl << setw(30) << left << "process" << " " << setw(12) << "signal";//process names
  for(unsigned int j =0; j< jmax; ++j){
    *fLogStream << " " << setw(12) << left << backgrounds[j].sample;
  }
  *fLogStream << endl << setw(30) << left << "process";//process IDs
  *fLogStream << " " << setw(12) << 0;
  for(unsigned int j =0; j< jmax; ++j){
    *fLogStream << " " << setw(12) << j+1;
  }
  *fLogStream << endl << setw(30) << left << "rate";
  if(signal.value==0) signal.value = 10e-5;
  *fLogStream << " " << setw(12) << left << fixed << setprecision(5) << signal.value;
  for(unsigned int j =0; j< jmax; ++j){
    *fLogStream << " " << setw(12) << left << fixed << setprecision(5) << backgrounds[j].value;
  }
  *fLogStream << endl << "------------" << endl;
  //next ALL control region statistical uncertainties
  //still to do: implement if in such a way if I use the same control region for several signal regions
  for(unsigned int jj = 0; jj<jmax; ++jj){
    if(backgrounds[jj].alpha<=0) continue;
    *fLogStream << setw(20) << left << backgrounds[jj].sample << "CR" <<  bin << " gmN" << " " << setw(5) << backgrounds[jj].valueCR;
    *fLogStream << " " << setw(12) << left << "-";//signal has no CR
    for(unsigned int j = 0; j<jmax; ++j){
      if(j==jj) *fLogStream << " " << setw(12) << left << fixed << setprecision(5) << backgrounds[jj].alpha;
      else *fLogStream << " " << setw(12) << left << "-";
    }
    *fLogStream << endl;
  }
  //next: the rest uncertainties
  for(unsigned int jj = 0; jj<uncertstring.size();++jj){
    char* buffer;
    //sprintf(buffer, "%-25s %-4s", uncertstring[jj].Data(), "lnN");
    //*fLogStream <<  boost::format("%25s%5s") % uncertstring[jj].Data() % "lnN";
    *fLogStream << setw(20) << left << uncertstring[jj]  << setw(10) << " lnN";
    //*fLogStream << buffer;
    //check signal first
    bool uncfound = false;
    for(unsigned int k = 0; k<signal.uncert.size(); ++k){
      if(!(signal.uncertname[k].EqualTo(uncertstring[jj]))) continue;
      *fLogStream << " " << setw(12) << left << fixed << setprecision(5) << signal.uncert[k];
      uncfound = true;
    }
    if(!uncfound) *fLogStream << " " << setw(12) << "-";
    for(unsigned int j = 0; j<jmax; ++j){
      uncfound = false;
      for(unsigned int k = 0; k<backgrounds[j].uncert.size(); ++k){
	if(!(backgrounds[j].uncertname[k].EqualTo(uncertstring[jj]))) continue;
	*fLogStream << " " << setw(12) << left << fixed << setprecision(5) << backgrounds[j].uncert[k];
	uncfound = true;
      }
      if(!uncfound) *fLogStream << " " << setw(12) << left << "-";
    }
    *fLogStream << endl;
  }
  //string binstring = std::to_string(bin);
  string binstring = binname[bin-1].Data();
  //TString logname = "datacards/data/datacard_" + signalname + "_bin" + binstring + ".txt";
  //if(overrightdatawithBGplusSIG) logname = "datacards/fakedata/dataisbgsig/datacard_" + signalname + "_bin" + binstring + ".txt";
  //else if(overrightdatawithBG) logname = "datacards/fakedata/dataisbg/datacard_" + signalname + "_bin" + binstring + ".txt";
  TString logname = "datacards/data/" + signalname + "_" + binstring + ".txt";
  if(overrightdatawithBGplusSIG) logname = "datacards/fakedata/dataisbgsig/" + signalname + "_" + binstring + ".txt";
  else if(overrightdatawithBG) logname = "datacards/fakedata/dataisbg/" + signalname + "_" + binstring + ".txt";
  //logname = "temp/datacard_" + signalname + "_bin" + binstring + ".txt";
  ofstream f_log (logname.Data(), ios::trunc);
  f_log << fLogStream->str();
  cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;
  //cout << "This is for bin " << bin << " which has binID " << mybin << " and name " << binstring << endl;
  delete fLogStream;

}

int setsampleid(TString sample){
  if(sample=="signal") return 0;
  for(int i = 0; i<bgsize; ++i){ 
    if(sample==sample_type[i]) return i+1;
  }
  return -1;
}

double rnd(double d){
  return floor(d + 0.5);
}

bool SortEntrybyBin(entry const& lhs, entry const& rhs) {
  return lhs.bin < rhs.bin;
}

bool SortEntrybyBinAndProcess(entry const& lhs, entry const& rhs) {
  if(lhs.bin!=rhs.bin)
    return lhs.bin < rhs.bin;
  return lhs.sampleid < rhs.sampleid;
}

void makeDataCardsAllBins(TString signaltype, TString signalname, bool overrightdatawithBG, bool overrightdatawithBGplusSIG){

  for(unsigned int i = 1; i<=maxsignal; ++i){
    makeDataCards(i,signaltype,signalname,overrightdatawithBG,overrightdatawithBGplusSIG);
  }
  
}

void makeDataCardsScan(TString signaltype, bool overrightdatawithBG, bool overrightdatawithBGplusSIG, int stoplow, int stophigh, int stopstep, int LSPlow, int LSPhigh, int LSPstep, int chargLow, int chargHigh, int chargStep, double xval){

  // if x<0 and charginos < 0 parse
  // Signal_SIGNALTYPE_MSTOP_MLSP
  // if charginos>=0 parse
  // Signal_SIGNALTYPE_MSTOP_MCHARG_MLSP
  // else if x>0 parse
  // Sginal_SIGNALTYPE_MSTOP_MLSP_X
  
  for(int t = stoplow; t<=stophigh; t+=stopstep){
    for(int l = LSPlow; l<=LSPhigh; l+=LSPstep){
      if(l>t) continue;
      TString signalname;
      if(chargLow>=0){
	for(int c = chargLow; c<=chargHigh; c+=chargStep){
	  if(c>t) continue;
	  if(l>c) continue;
	  signalname = Form("%s_%d_%d_%d",signaltype.Data(),t,c,l);
	  //cout << signalname << endl;
	  makeDataCardsAllBins(signaltype,signalname,overrightdatawithBG,overrightdatawithBGplusSIG);
	}
      } else if(xval>=0){
	string s = to_string(xval);
	while(s[s.size()-1] == '0'){
	  s.erase(s.end()-1);
	}
	signalname = Form("%s_%d_%d_",signaltype.Data(),t,l)+s;
	signalname.ReplaceAll(".","p");
	//cout << signalname << endl;
	makeDataCardsAllBins(signaltype,signalname,overrightdatawithBG,overrightdatawithBGplusSIG);
      } else {
	signalname = Form("%s_%d_%d",signaltype.Data(),t,l);
	//cout << signalname << endl;
	makeDataCardsAllBins(signaltype,signalname,overrightdatawithBG,overrightdatawithBGplusSIG);
      }
    }
  }
  
}
  
//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02
