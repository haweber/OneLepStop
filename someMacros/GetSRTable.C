#include "dataMCplotMaker.h"
#include "TFile.h"
#include "TH1F.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TString.h"

using namespace std;

void GetSRTable(){

  //  vector<char*> bgnames, signames;
  vector<string> bgstrings, sigstrings;
  const unsigned int datasetsize = 10;//12
  const unsigned int bgsetsize = 6;//8
  const unsigned int sigsetsize = datasetsize-bgsetsize;
  //string datasets[datasetsize]={"TTbar","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //char* dataset[datasetsize]={"TTbar","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //string datasets[datasetsize]={"TTbar1l","TTbar2l","TTbarH","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //char* dataset[datasetsize]={"TTbar1l","TTbar2l","TTbarH","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  // string datasets[datasetsize]={"TTbar1l","TTbar2l","SingleT","TTV","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //char* dataset[datasetsize]={"TTbar1l","TTbar2l","SingleT","TTV","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  string datasets[datasetsize]={"TTbar2l","TTbar1l","TTbarH","SingleT","Rare","WJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  string datasetL[datasetsize]={"$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow \\ell\\ell$","$1\\ell$ Top","$0\\ell$ Top","single Top","Rare","W + jets","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (425,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (500,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (650,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (850,100)"};
  char* dataset[datasetsize]={"TTbar2l","TTbar1l","TTbarH","SingleT","Rare","WJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  bool skipping[datasetsize]={false,false,false,false,false,false,false,false,false,false};
  const unsigned int poststringsize = 7;
  string poststring[poststringsize] = {""};

  for(unsigned int n=0; n<bgsetsize; ++n) {
    if(skipping[n]) continue;
    //bgnames.push_back(dataset[n]);
    bgstrings.push_back(dataset[n]);
  }
  for(unsigned int n=bgsetsize; n<datasetsize; ++n) {
    if(skipping[n]) continue;
    //signames.push_back(dataset[n]);
    sigstrings.push_back(dataset[n]);
  }
  TFile *fbg[bgsetsize];
  for(unsigned int n=0; n<bgsetsize; ++n) {
    if(skipping[n]) continue;
    string datasetstring = datasets[n];
    if(n==0) datasetstring = "TTbar";
    else if(n==1) continue;
    else if(n==2) continue;
    TString x = ("rootfiles/CutflowExtra"+datasetstring+".root");
    cout << x << endl;
      fbg[n] = TFile::Open(x);
      //  cout << fbg[n].IsZombie();
  }
  TFile *fsig[sigsetsize];
  for(unsigned int n=0; n<sigsetsize; ++n) {
     if(skipping[bgsetsize+n]) continue;
   string datasetstring = datasets[bgsetsize+n];
    TString x = ("rootfiles/CutflowExtra"+datasetstring+".root");
    cout << x << endl;
    fsig[n] = TFile::Open(x);
  }
  string outputdir = "rootfiles/CutPlots/CutFlow/";

  vector<string> histonames;

  histonames.push_back("NEventsPerSR");               

  TH1D* null = new TH1D("","",1,0,1);
  cout << __LINE__ << endl;
    for(unsigned int i = 0; i<histonames.size();++i){
      vector<TH1D*> bghist; bghist.clear();
      vector<TH1D*> sighist; sighist.clear();
      for(unsigned int n=0; n<bgsetsize; ++n){
	//cout << n << " " << __LINE__ << endl;
	if(skipping[n]) continue;
	int fileidentifier = n;
	if(n==1) fileidentifier = 0;//TTbar2l
	if(n==2) fileidentifier = 0;//TTbarH
	fbg[fileidentifier]->cd();
	string name = histonames[i]+"_"+bgstrings[n];
	//cout << fbg[fileidentifier]->GetName() << " " << name << endl;
	TH1D *h = (TH1D*)fbg[fileidentifier]->Get(name.c_str());
	//cout << __LINE__<< " " << h->Integral() << endl;
	bghist.push_back(h);
      }
      for(unsigned int n=0; n<sigsetsize; ++n){
	//cout << n << " " << __LINE__ << endl;
	if(skipping[bgsetsize+n]) continue;
	fsig[n]->cd();
	string name = histonames[i]+"_"+sigstrings[n];
	TH1D *h = (TH1D*)fsig[n]->Get(name.c_str());
	//cout << fsig[n]->GetName() << " " << name << endl;
	//cout << __LINE__<< " " << h->Integral() << endl;
	h->Scale(1.);
	sighist.push_back(h);
      }
      TH1D *bgsum = (TH1D*)bghist[0]->Clone("bgsum");
      for(unsigned int n=1; n<bgsetsize; ++n){
	cout << n << " " << __LINE__ << endl;
	if(skipping[n]) continue;
	bgsum->Add(bghist[n],1.);
      }
      //HACK!!!
      bghist[4]->Add(bghist[2],1);
      //HACK!!

      //cout << __LINE__<< " " << bghist[0]->GetBinContent(1) << " " <<bgsum->GetBinContent(1) << " " << sighist[1]->GetBinContent(1) << endl;
      //std::ostringstream* fLogStream     = 0;
      std::ostringstream* fLogStream = new std::ostringstream();

      *fLogStream << "*********************************************************************" << endl;
      *fLogStream << "\%BEGINLATEX\%"             << endl;
      *fLogStream << "\\begin{table}"             << endl
		  << "\\begin{center}"            << endl
		  << "\\small"                    << endl;
      *fLogStream << "\\begin{tabular}{lcccc}"    << endl;	     
      *fLogStream << "\\hline"                    << endl;
      *fLogStream << " Sample & $E_\\mathrm{T}^\\mathrm{miss} > 150$ GeV & $E_\\mathrm{T}^\\mathrm{miss} > 200$ GeV & $E_\\mathrm{T}^\\mathrm{miss} > 250$ GeV & $E_\\mathrm{T}^\\mathrm{miss} > 300$ GeV \\\\" << endl;
      *fLogStream << "\\hline" << endl;
      *fLogStream << "Low $\\Delta M$ selection & & & & \\\\" << endl;
      for(int n=0; n<bgsetsize; ++n){
	if(skipping[n]) continue;
	if(n==2) continue;//HACK!!
	*fLogStream << datasetL[n] << " & $" 
		    << bghist[n]->GetBinContent(1) << " \\pm " << bghist[n]->GetBinError(1) 
		    << "$ & $" << bghist[n]->GetBinContent(2) << " \\pm " << bghist[n]->GetBinError(2) 
		    << "$ & $" << bghist[n]->GetBinContent(3) << " \\pm " << bghist[n]->GetBinError(3) 
		    << "$ & $" << bghist[n]->GetBinContent(4) << " \\pm " << bghist[n]->GetBinError(4) 
		    << "$ \\\\" << endl;
      }
      *fLogStream << "Total & $"
		  << bgsum->GetBinContent(1) << " \\pm " << bgsum->GetBinError(1) 
		  << "$ & $" << bgsum->GetBinContent(2) << " \\pm " << bgsum->GetBinError(2) 
		  << "$ & $" << bgsum->GetBinContent(3) << " \\pm " << bgsum->GetBinError(3) 
		  << "$ & $" << bgsum->GetBinContent(4) << " \\pm " << bgsum->GetBinError(4) 
		  << "$ \\\\" << endl;
      for(int n=0; n<sigsetsize; ++n){
	if(skipping[bgsetsize+n]) continue;
	*fLogStream << datasetL[bgsetsize+n] << " & $" 
		    << sighist[n]->GetBinContent(1) << " \\pm " << sighist[n]->GetBinError(1) 
		    << "$ & $" << sighist[n]->GetBinContent(2) << " \\pm " << sighist[n]->GetBinError(2) 
		    << "$ & $" << sighist[n]->GetBinContent(3) << " \\pm " << sighist[n]->GetBinError(3) 
		    << "$ & $" << sighist[n]->GetBinContent(4) << " \\pm " << sighist[n]->GetBinError(4) 
		    << "$ \\\\" << endl;
      }
      *fLogStream << "\\hline" << endl;
      *fLogStream << "High $\\Delta M$ selection & & & & \\\\" << endl;
      for(int n=0; n<bgsetsize; ++n){
	if(skipping[n]) continue;
	if(n==2) continue;//HACK!!
	*fLogStream << datasetL[n] << " & $" 
		    << bghist[n]->GetBinContent(5) << " \\pm " << bghist[n]->GetBinError(5) 
		    << "$ & $" << bghist[n]->GetBinContent(6) << " \\pm " << bghist[n]->GetBinError(6) 
		    << "$ & $" << bghist[n]->GetBinContent(7) << " \\pm " << bghist[n]->GetBinError(7) 
		    << "$ & $" << bghist[n]->GetBinContent(8) << " \\pm " << bghist[n]->GetBinError(8) 
		    << "$ \\\\" << endl;
      }
      *fLogStream << "Total & $"
		  << bgsum->GetBinContent(5) << " \\pm " << bgsum->GetBinError(5) 
		  << "$ & $" << bgsum->GetBinContent(6) << " \\pm " << bgsum->GetBinError(6) 
		  << "$ & $" << bgsum->GetBinContent(7) << " \\pm " << bgsum->GetBinError(7) 
		  << "$ & $" << bgsum->GetBinContent(8) << " \\pm " << bgsum->GetBinError(8) 
		  << "$ \\\\" << endl;
      for(int n=0; n<sigsetsize; ++n){
	if(skipping[bgsetsize+n]) continue;
	*fLogStream << datasetL[bgsetsize+n] << " & $" 
		    << sighist[n]->GetBinContent(5) << " \\pm " << sighist[n]->GetBinError(5) 
		    << "$ & $" << sighist[n]->GetBinContent(6) << " \\pm " << sighist[n]->GetBinError(6) 
		    << "$ & $" << sighist[n]->GetBinContent(7) << " \\pm " << sighist[n]->GetBinError(7) 
		    << "$ & $" << sighist[n]->GetBinContent(8) << " \\pm " << sighist[n]->GetBinError(8) 
		    << "$ \\\\" << endl;
      }
      *fLogStream << "\\hline\\hline" << endl
		  << "\\end{tabular}" << endl
		  << "\\end{center}"  << endl
		  << "\\end{table}"   << endl
		  << "\%ENDLATEX\%"   << endl
		  << endl;
      cout << fLogStream->str();
    }
} 
