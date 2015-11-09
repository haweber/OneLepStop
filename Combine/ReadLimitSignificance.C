#include "TFile.h"
#include "TTree.h"
#include "TFile.h"
#include "RooStats/HypoTestCalculator.h"
#include "RooStats/RooStatsUtils.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

//read in correct file
//  what sample
//  what working point
//what do I want:
//  limit/significance
//  expected/observed
//  with or without toys
//  pre/post fit
//where to save/printout

double GetMedian(vector<double> vec);
double GetSignificance(double pvalue){ return RooStats::PValueToSignificance(pvalue);}
double GetPvalue(double significance){ return RooStats::SignificanceToPValue(significance);}
Double_t ReadoutLimit(TString filename, float quantile=-1., bool limiterr=false);
Double_t readoutLimit(TFile* f, float quantile=-1., bool limiterr=false);
Double_t readoutlimit(TString sample, TString prefix="Obs", TString method="ProfileLikelihood", TString directory=".", int seed=-1, bool islimit=false, float quantile=-1., bool limiterr=false);
Double_t ReadoutLimit(TString sample, int mstop, int mlsp, int mcharg=-1, double x=-1, TString prefix="Obs", TString method="ProfileLikelihood", TString directory=".", int seed=-1, bool islimit=false, float quantile=-1., bool limiterr=false);
void ReadoutLimitScan(TString sample, int stoplow=100, int stophigh=1000, int stopstep=25, int LSPlow=0, int LSPhigh=500, int LSPstep=25, int chargLow=-1, int chargHigh=-1, int chargStep=-1, double xval=-1, TString prefix="Obs", TString method="ProfileLikelihood", TString directory=".", int seed=-1., bool islimit=false, float quantile=-1., bool limiterr=false, bool overrightdatawithBGplusSIG=false, bool overrightdatawithBG=false);


double GetMedian(vector<double> vec){
  double median;
  size_t size = vec.size();
  sort(vec.begin(), vec.end());
  if (size  % 2 == 0){
      median = (vec[size / 2 - 1] + vec[size / 2]) / 2;
  } else {
      median = vec[size / 2];
  }
  return median;
}

Double_t ReadoutLimit(TString sample, int mstop, int mlsp, int mcharg, double xval, TString prefix, TString method, TString directory, int seed, bool islimit, float quantile, bool limiterr){

  TString signalname;
  if(mcharg>=0) signalname = Form("%s_%d_%d_%d",sample.Data(),mstop,mcharg,mlsp);
  /*else if(xval>=0){
    string s = to_string(xval);
    while(s[s.size()-1] == '0'){
      s.erase(s.end()-1);
    }
    signalname = Form("%s_%d_%d_",sample.Data(),mstop,mlsp)+s;
    signalname.ReplaceAll(".","p");
  }*/
  else signalname = Form("%s_%d_%d",sample.Data(),mstop,mlsp);

  return readoutlimit(signalname, prefix, method, directory, seed, islimit, quantile, limiterr);
}


Double_t readoutlimit(TString sample, TString prefix, TString method, TString directory, int seed, bool islimit, float quantile, bool limiterr){

  TString slimit = "Signif";
  if(islimit) slimit = "Limits";
  TString filename;
  //if(seed!=-1)
  filename = Form("%s/%s_%s_%s_%s.root", directory.Data(),slimit.Data(),method.Data(),prefix.Data(),sample.Data());
  //else filename = Form("%s/%s_%s_%s_%s.root", directory.Data(),slimit.Data(),method.Data(),prefix.Data(),sample.Data());//Currently rename sample without seed number

  //cout << filename << endl;
  Double_t output = -9999.;
  ifstream ifile(filename.Data());
  if(ifile){
    //TFile *limit_file = TFile::Open(filename.Data());
    TFile *limit_file = new TFile(filename.Data(),"READ");
    if(limit_file->IsZombie()) {
      delete limit_file;
      return -7999.99;
    }
    output = readoutLimit(limit_file, quantile, limiterr);
    delete limit_file;
    return output;
  }
  else return -6999.99;
}

Double_t ReadoutLimit(TString filename, float quantile, bool limiterr){

  TFile *limit_file = TFile::Open(filename.Data());
  return readoutLimit(limit_file, quantile, limiterr);
  
}

Double_t readoutLimit(TFile* f, float quantile, bool limiterr){

  //quantile: "obs" -1, "exp": 0.5, "exp+/-1sigma" 0.16,0.84, "exp+/-2sigma" 0.025,0.975
  //limiterr only for quantile -1
  //with toys - get mean for output

  double sum = 0;
  double counter = 0;
  vector<double> entries; entries.clear();

  //f->Open();
  f->cd();
  TTree *limit_tree = (TTree*)f->Get("limit");
  Long64_t nentries = limit_tree->GetEntries();
  Double_t limitval = -1.0;
  Double_t limiterrval = -1.0;
  Float_t quantileval = -1.0;
  limit_tree->SetBranchAddress("limit", &limitval);
  limit_tree->SetBranchAddress("limitErr", &limiterrval);
  limit_tree->SetBranchAddress("quantileExpected", &quantileval);

  for (Long64_t i=0;i<nentries;++i) {
    limit_tree->GetEntry(i);
    if(fabs(quantileval-quantile)>0.001) continue;
    if(limiterr) {
      sum +=limiterrval;
      entries.push_back(limiterrval);//this doesn't make sense if final counter>1
    }
    else {
      sum += limitval;
      entries.push_back(limitval);
    }
    ++counter;
  }
  f->Close();

  if(counter==0) return -999.;
  //return sum/(double)counter;//return mean
  return GetMedian(entries);//return median
}

//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"Obs","ProfileLikelihood","outputfiles/fakedata/dataisbg",-1,false,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"ExpPriori","ProfileLikelihood","outputfiles/fakedata/dataisbg",-1,false,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"ExpPrioriToys200","ProfileLikelihood","outputfiles/fakedata/dataisbg",-1,false,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"ExpPosteriori","ProfileLikelihood","outputfiles/fakedata/dataisbg",-1,false,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"ExpPosterioriToys200","ProfileLikelihood","outputfiles/fakedata/dataisbg",-1,false,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"PreFit","Asymptotic","outputfiles/fakedata/dataisbg",-1,true,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"PostFit","Asymptotic","outputfiles/fakedata/dataisbg",-1,true,-1.,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"PreFit","Asymptotic","outputfiles/fakedata/dataisbg",-1,true,0.5,false,false,true)
//ReadoutLimitScan("T2tt",425,850,25,100,325,25,-1,-1,-1,-1,"PostFit","Asymptotic","outputfiles/fakedata/dataisbg",-1,true,0.5,false,false,true)
void ReadoutLimitScan(TString sample, int stoplow, int stophigh, int stopstep, int LSPlow, int LSPhigh, int LSPstep, int chargLow, int chargHigh, int chargStep, double xval, TString prefix, TString method, TString directory, int seed, bool islimit, float quantile, bool limiterr, bool overrightdatawithBGplusSIG, bool overrightdatawithBG){

  if(overrightdatawithBGplusSIG) overrightdatawithBG=true;

  std::ostringstream* fLogStream     = 0;
  fLogStream = new std::ostringstream();
  
  TString slimit = "Signif";
  if(islimit) slimit = "Limits";
  
  for(int t = stoplow; t<=stophigh; t+=stopstep){
    for(int l = LSPlow; l<=LSPhigh; l+=LSPstep){
      TString signalname;
      double myval = -9999.;
      if(chargLow>=0){
	for(int c = chargLow; c<=chargHigh; c+=chargStep){
	  signalname = Form("%s_%d_%d_%d",sample.Data(),t,c,l);
	  myval = readoutlimit(signalname, prefix, method, directory, seed, islimit, quantile, limiterr);
	  if(myval>=0) *fLogStream << "Method " << method << " Type " << prefix << " Sample " << signalname << " obtained" << slimit << " " << myval << endl;
	}
      } else if(xval>=0){
	string s = to_string(xval);
	while(s[s.size()-1] == '0'){
	  s.erase(s.end()-1);
	}
	signalname = Form("%s_%d_%d_",sample.Data(),t,l)+s;
	signalname.ReplaceAll(".","p");
	myval = readoutlimit(signalname, prefix, method, directory, seed, islimit, quantile, limiterr);
	if(myval>=0) *fLogStream << "Method " << method << " Type " << prefix << " Sample " << signalname << " obtained" << slimit << " " << myval << endl;
      } else {
	signalname = Form("%s_%d_%d",sample.Data(),t,l);
	myval = readoutlimit(signalname, prefix, method, directory, seed, islimit, quantile, limiterr);
	if(myval>=0) *fLogStream << "Method " << method << " Type " << prefix << " Sample " << signalname << " obtained" << slimit << " " << myval << endl;
      }
    }
  }
  TString logname = "outputfiles/Results_" + slimit + "_" + method + "_" + prefix + "_" + sample + ".txt";
  if(overrightdatawithBGplusSIG) logname = "outputfiles/fakedata/dataisbgsig/Results_" + slimit + "_" + method + "_" + prefix + "_" + sample + ".txt";
  else if(overrightdatawithBG) logname = "outputfiles/fakedata/dataisbg/Results_" + slimit + "_" + method + "_" + prefix + "_" + sample + ".txt";
  if(islimit){
    if(fabs(quantile+1.0)<0.001){
      logname = "outputfiles/Results_" + slimit + "_" + method + "_Obs" + prefix + "_" + sample + ".txt";
      if(overrightdatawithBGplusSIG) logname = "outputfiles/fakedata/dataisbgsig/Results_" + slimit + "_" + method + "_Obs" + prefix + "_" + sample + ".txt";
      else if(overrightdatawithBG) logname = "outputfiles/fakedata/dataisbg/Results_" + slimit + "_" + method + "_Obs" + prefix + "_" + sample + ".txt";
    }
    else if(fabs(quantile-0.5)<0.001){
      logname = "outputfiles/Results_" + slimit + "_" + method + "_Exp" + prefix + "_" + sample + ".txt";
      if(overrightdatawithBGplusSIG) logname = "outputfiles/fakedata/dataisbgsig/Results_" + slimit + "_" + method + "_Exp" + prefix + "_" + sample + ".txt";
      else if(overrightdatawithBG) logname = "outputfiles/fakedata/dataisbg/Results_" + slimit + "_" + method + "_Exp" + prefix + "_" + sample + ".txt";
    }
    else{
      string qstring = std::to_string(quantile);
      logname = "outputfiles/Results_" + slimit + "_" + method + "_Quantile" + qstring + prefix + "_" + sample + ".txt";
      if(overrightdatawithBGplusSIG) logname = "outputfiles/fakedata/dataisbgsig/Results_" + slimit + "_" + method + "_Quantile" + qstring + prefix + "_" + sample + ".txt";
      else if(overrightdatawithBG) logname = "outputfiles/fakedata/dataisbg/Results_" + slimit + "_" + method + "_Quantile" + qstring + prefix + "_" + sample + ".txt";
    }
  }
  ofstream f_log (logname.Data(), ios::trunc);
  f_log << fLogStream->str();
  cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;

}

