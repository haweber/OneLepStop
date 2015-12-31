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

string inputdir = "inputfiles/";
string outputdir = "datacards/";


void makeDataCardsFullyHardCodedOneBin(int bin=0,TString signaltype="T2tt", int stop=100; int lsp=0, int charg=-1, float xval=-1, bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllBins(TString signaltype="T2tt", int stop=100; int lsp=0, int charg=-1, float xval=-1, bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedOneScan(TString signaltype="T2tt", bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllScans(bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);

void makeDataCardsFullyHardCodedAllScans(bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){
  makeDataCardsFullyHardCodedOneScan("T2tt",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2tb",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2bW_x0p75",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2bW_x0p25",fakedata, nosyst, xsecupdown, compressed, dropsigcont);

}

void makeDataCardsFullyHardCodedOneScan(TString signaltype, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){
  float chargLow = -1;
  for(int t = 0; t<=1000; t+=25){
    for(int l = 0; l<=500; l+=25){
      if(l>t) continue;
      int stop = t;
      int lsp = l;
      //if(l==0) lsp = 1;//maybe
      makeDataCardsFullyHardCodedAllBins(signaltype,stop,lsp,-1,-1.,fakedata, nosyst, xsecupdown, compressed, dropsigcont);
    }
  }
}

void makeDataCardsFullyHardCodedAllBins(TString signaltype, int stop, int lsp, int charg, float xval, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){
  int maxbin = -1;
  int startbin = -1;
  if(compressed == 1) { maxbin = 2; startbin = 11; }
  else { maxbin = 5; startbin = 1; }
  for(unsigned int bin = startbin; bin < (startbin+maxbin); ++bin){
    makeDataCardsFullyHardCodedOneBin(bin,signaltype, stop, lsp, charg, xval, fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  }



void makeDataCardsFullyHardCodedOneBin(int bin,TString signaltype, int stop, int lsp, int charg, float xval, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){

  if(stop<lsp) continue;
  int nbgs = 0;
  int nnuis = 0;
  TString filename = inputdir + "Signal_" + signaltype + ".root";
  TFile *fsig = new TFile(filename,"READ");
  if(fsig->IsZombie()) {
    fsig->Close();
    delete fsig;
    cout << "No Signal file - exit" << endl;
    return;
  }
  if(fakedata) filename= inputdir + "Background_2l.root";
  else filename= inputdir + "Data.root";
  TFile *fdata = new TFile(filename,"READ");
  if(fdata->IsZombie()) {
    fdata->Close();
    delete fdata;
    cout << "No Data file - exit" << endl;
    return;
  }
  filename = inputdir + "Background_2l.root";
  TFile *f2l = new TFile(filename,"READ");
  if(f2l->IsZombie()) {
    f2l->Close();
    delete f2l;
    cout << "No 2l file - exit" << endl;
    return;
  }
  filename = inputdir + "Background_1l.root";
  TFile *f1l = new TFile(filename,"READ");
  if(f1l->IsZombie()) {
    f1l->Close();
    delete f1l;
    cout << "No 1l file - exit" << endl;
    return;
  }
  filename = inputdir + "Background_1ltop.root";
  TFile *f1ltop = new TFile(filename,"READ");
  if(f1ltop->IsZombie()) {
    f1ltop->Close();
    delete f1ltop;
    cout << "No 1ltop file - exit" << endl;
    return;
  }
  filename = inputdir + "Background_Znunu.root";
  TFile *fznunu = new TFile(filename,"READ");
  if(fznunu->IsZombie()) {
    fznunu->Close();
    delete fznunu;
    cout << "No Znunu file - exit" << endl;
    return;
  }

  double temp, temperr;//for any bullshit
  double sig, sigerr;
  double origsig, origsigerr;//keep original without signal contamination
  double data, dataerr;
  double bg2l, bg2lerr, bg1l, bg1lerr, bg1ltop, bg1ltoperr, bgznunu, bgznunuerr;
  TH1D *h,*hl,*hu;
  TH3D *h3, *h3l, *h3u;
  int b,b3;
  b = bin;
  //if(compressed==1) b = bin+5;//check if needed - probably no
  TString histname;
  histname = "SRyield"; h3 = (TH3D*)fsig->Get(histname);
  int bx,by,bz;
  bx = h3->GetXaxis()->FindBin(b);
  by = h3->GetYaxis()->FindBin(stop);
  bz = h3->GetZaxis()->FindBin(lsp);
  if(bx>h3->GetXaxis()->GetNbins()){
    cout << "xaxis out of range - exit" << endl;
    return;
  }
  if(by>h3->GetYaxis()->GetNbins()){
    cout << "yaxis out of range - exit" << endl;
    return;
  }
  if(bz>h3->GetZaxis()->GetNbins()){
    cout << "zaxis out of range - exit" << endl;
    return;
  }
  b3 = h3->FindBin(b,stop,lsp);
  if(b3!=h3->GetBin(bx,by,bz)) cout << "Check this " << "b:stop:lsp " << b << ":" << stop << ":" << lsp << " are bins " << bx << ":"<<by<<":"<<bz <<" are global bin " << h3->GetBin(bx,by,bz) << " and also should be findbin b3 " << b3 << endl;

  //get all yields and statistical uncertainties - also signal contamination
  sig = h3->GetBinContent(b3); sigerr = 1.+h3->GetBinError(b3)/sig; ++nnuis;
  origsig = sig; origsigerr = sigerr;
  if(xsecupdown==1){
    histname = "SR_Xsecup"; h3 = (TH3D*)fsig->Get(histname);
    sig = h3->GetBinContent(b3); sigerr = 1.+h3->GetBinError(b3)/sig;
  } else if(xsecupdown==(-1)){
    histname = "SR_Xsecdown"; h3 = (TH3D*)fsig->Get(histname);
    sig = h3->GetBinContent(b3); sigerr = 1.+h3->GetBinError(b3)/sig;
  }
  if(!dropsigcont){
    histname = "CR1l_sigcontamination"; h3 = (TH3D*)fsig->Get(histname);
    temp = h3->GetBinContent(b3); sig = TMath::Max(0., sig-temp);
    histname = "CR2l_sigcontamination"; h3 = (TH3D*)fsig->Get(histname);
    temp = h3->GetBinContent(b3); sig = TMath::Max(0., sig-temp);
  }
  histname = "SRobs"; h = (TH1D*)fdata->Get(histname);
  data = h->GetBinContent(b); dataerr = 1.+h->GetBinError(b)/data;//do I need the data err;
  histname = "CR2lest"; h = (TH1D*)f2l->Get(histname);
  bg2l = h->GetBinContent(b); ++nbgs;
  histname = "CR2lstat"; h = (TH1D*)f2l->Get(histname);
  bg2lerr = 1.+((h->GetBinContent(b))/bg2l); ++nnuis;
  histname = "CR1lest"; h = (TH1D*)f1l->Get(histname);
  bg1l = h->GetBinContent(b); ++nbgs;
  histname = "CR1lstat"; h = (TH1D*)f1l->Get(histname);
  bg1lerr = 1.+((h->GetBinContent(b))/bg1l); ++nnuis;
  histname = "CR1ltopest"; h = (TH1D*)f1ltop->Get(histname);
  bg1ltop = h->GetBinContent(b); bg1ltoperr = 1.+h->GetBinError(b)/bg1ltop; ++nbgs; ++nnuis;
  histname = "CRznunuest"; h = (TH1D*)fznunu->Get(histname);
  bgznunu = h->GetBinContent(b); bgznunuerr = 1.+h->GetBinError(b)/bgznunu; ++nbgs; ++nnuis;
  if(sig<=0 || (bg2l+bg1l+bg1ltop+bgznunu)<=0) return;//empty datacard - probably empty point
  //get signal uncertainties
  double sigbsflf, sigbsfhv, sigjes, sigmurf, sigisr, sigpu, siglepeff, sigtrig, siglum;
  histname = "SR_Bup_HF";     h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_Bdown_HF";   h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigbsfhf  = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_Bup_LF";     h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_Bdown_LF";   h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigbsflf  = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_JESup";      h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_JESdown";    h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigjes    = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_muRFup";     h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_muRFdown";   h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigmurf   = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_ISRup";      h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_ISRdown";    h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigisr    = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_PUup";       h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_PUdown";     h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  sigpu     = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  histname = "SR_LepEffup";   h3 = (TH3D*)fsig->Get(histname); temp    = h3->GetBinContent(b3);
  histname = "SR_LepEffdown"; h3 = (TH3D*)fsig->Get(histname); temperr = h3->GetBinContent(b3);
  siglepeff = 1.+TMath::Max(TMath::Abs(origsig-temp),TMath::Abs(origsig-temperr))/origsig; ++nnuis;
  sigtrig   = 1.01;
  siglum    = 1.046;
  //get bg2l uncertainties
  //get bg1l uncertainties
  //get bg1ltop uncertainties
  //get bgZnunu uncertainties


  //now ready to make the data card
  std::ostringstream* fLogStream     = 0;
  fLogStream = new std::ostringstream();
  string binstring = "b" + std::to_string(bin);

  
  *fLogStream << "# My significance experiment" << endl
	      << "imax  " << 1     << "  number of channels" << endl//single bin
	      << "jmax  " << nbgs  << "  number of backgrounds" << endl
	      << "kmax "  << nnuis << "  number of nuisance parameters" << endl;
  *fLogStream << "------------" << endl << "# observations " << endl;
  *fLogStream << "bin         " << b << endl;
  *fLogStream << "observation " << data << endl;
  *fLogStream << "------------" << endl;
  *fLogStream << "#now we list all expected number of events" << endl;
  *fLogStream << "bin          " << b << "       " << b << "       " << b << "       " << b << "       " << b << "       " << endl;
  *fLogStream << "process     sig       2l       1l       1ltop       znunu" << endl;
  *fLogStream << "process      0     1    2    3       4" << endl;
  *fLogStream << "rate        " << sig << "  " << bg2l << "  " << bg1l << "  " << bg1ltop << "  " << znunu << endl;
  *fLogStream << "------------" << endl;
  //next ALL control region statistical uncertainties
  *fLogStream << "SigStat" << b << "     lnN "             << sigerr     << "  -  -  -  -" << endl;
  *fLogStream << "Bg2lStat" << b << "    lnN -  "          << bg2lerr    << "  -  -  -"    << endl;
  *fLogStream << "Bg1lStat" << b << "    lnN -  -  "       << bg1lerr    << "  -  -"       << endl;
  *fLogStream << "Bg1lTopStat" << b << " lnN -  -  -  "    << bg1ltoperr << "  -"          << endl;
  *fLogStream << "BgZnunuStat" << b << " lnN -  -  -  -  " << bgznunuerr                   << endl;
  //signal systematic uncertainties (or general - therefore add no "Sig" prefix)
  *fLogStream << " TrigSyst     lnN " << sigtrig   << "  -  -  -  -" << endl;//add znunu ttbar1l
  *fLogStream << " LumSyst      lnN " << siglum    << "  -  -  -  -" << endl;//add znunu ttbar1l
  *fLogStream << " BLFSyst      lnN " << sigbfslf  << " -  -  -  -" << endl;//add all
  *fLogStream << " BHFSyst      lnN " << sigbfshf  << " -  -  -  -" << endl;//add all
  *fLogStream << " JESSyst      lnN " << sigjes    << " -  -  -  -" << endl;//add all
  *fLogStream << " MuRFSyst     lnN " << sigmurf   << " -  -  -  -" << endl;//add all
  *fLogStream << " PUSyst       lnN " << sigpu     << " -  -  -  -" << endl;//add all
  *fLogStream << " LEffSyst     lnN " << siglepeff << " -  -  -  -" << endl;//add all
  *fLogStream << endl;

  if(fakedata)   outputdir = outputdir + "fakedata/";
  if(compressed==1) outputdir = outputdir + "compressed/";
  TString logname = outputdir + "datacard_" + signalname + "_" + binstring + ".txt";
  ofstream f_log (logname.Data(), ios::trunc);
  f_log << fLogStream->str();
  cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;
  delete fLogStream;

}

//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02
