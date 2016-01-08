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
bool nosigunc = false;
bool nobkgunc = false;

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}

void makeDataCardsFullyHardCodedOneBin(int bin=0,TString signaltype="T2tt", int stop=100; int lsp=0, int charg=-1, float xval=-1, bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllBins(TString signaltype="T2tt", int stop=100; int lsp=0, int charg=-1, float xval=-1, bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedOneScan(TString signaltype="T2tt", bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllScans(bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);

double getSignalUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bx, int by, int bz, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins);
double getBGUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins);

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
}



void makeDataCardsFullyHardCodedOneBin(int bin,TString signaltype, int stop, int lsp, int charg, float xval, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){

  if(compressed==0&&bin<1) return;
  if(compressed==0&&bin>6) return;
  if(compressed==1&&bin<11) return;
  if(compressed==1&&bin>12) return;
  int minbin = 1;//run only baseline analysis
  int maxbin = 6;//run only baseline analysis
  if(compressed==1){
    minbin = 11;
    maxbin = 12;
  }
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
  filename = inputdir + "Background_2l.root";
  //filename = inputdir + "Background_2l.root";
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
  if(!fakedata) {
    filename= inputdir + "Data.root";
    TFile *fdata = new TFile(filename,"READ");
    if(fdata->IsZombie()) {
      fdata->Close();
      delete fdata;
      cout << "No Data file - exit" << endl;
      return;
    }
  }
  else fdata = (TFile*)f2l->Clone("Data.root");

  double sig, sigerr;
  double origsig, origsigerr;//keep original without signal contamination
  double data, dataerr;
  double bg2l, bg2lerr, bg1l, bg1lerr, bg1ltop, bg1ltoperr, bgznunu, bgznunuerr;
  TH1D *h;
  TH3D *h3;
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
  sig = h3->GetBinContent(b3);
  if(sig<=0) {
    cout << "There is no signal (" << signaltype <<"_"<<stop<<"_"<<lsp << ") in this bin (" << bin << ") - no datacard is made!!!!!!!!"
      return;
  }
  sigerr = 1.+h3->GetBinError(b3)/sig; ++nnuis;
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
  histname = "Data"; h = (TH1D*)fdata->Get(histname);
  data = h->GetBinContent(b); //dataerr = 1.+h->GetBinError(b)/data;//do I need the data err;
  histname = "CR2lyield"; h = (TH1D*)f2l->Get(histname);
  bg2l = h->GetBinContent(b); ++nbgs;
  if(bg2l>0) { bg2lerr = 1.+((h->GetBinError(b))/bg2l); ++nnuis;}
  //histname = "CR2lstat"; h = (TH1D*)f2l->Get(histname);
  //if(bg2l>0) {bg2lerr = 1.+((h->GetBinContent(b))/bg2l); ++nnuis;}
  histname = "CR1lest"; h = (TH1D*)f1l->Get(histname);
  bg1l = h->GetBinContent(b); ++nbgs;
  histname = "CR1lstat"; h = (TH1D*)f1l->Get(histname);
  if(bg1l>0) {bg1lerr = 1.+((h->GetBinContent(b))/bg1l); ++nnuis;}
  histname = "CR1ltopest"; h = (TH1D*)f1ltop->Get(histname);
  bg1ltop = h->GetBinContent(b); ++nbgs;
  if(bg1ltop>0) { bg1ltoperr = 1.+h->GetBinError(b)/bg1ltop; ++nnuis;}
  histname = "CRznunuest"; h = (TH1D*)fznunu->Get(histname);
  bgznunu = h->GetBinContent(b);
  if(bgznunu>0) { bgznunuerr = 1.+h->GetBinError(b)/bgznunu; ++nbgs; ++nnuis; }
  if(sig<=0 || (bg2l+bg1l+bg1ltop+bgznunu)<=0) return;//empty datacard - probably empty point
  //get signal uncertainties
  double sigbsfhf, sigbsflf, sigjes, sigmurf, sigisr, sigpu, siglepeff, sigleffFS;
  double sigtrig, siglum;
  vector<int> corrbins; corrbins.clear();
  if(!nosigunc){
    sigbsfhf  = getSignalUncertainty(origsig, "SR_Bup_HF",     "SR_Bdown_HF",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigbsfhf !=1.) ++nnuis;
    sigbsflf  = getSignalUncertainty(origsig, "SR_Bup_LF",     "SR_Bdown_LF",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigbsflf !=1.) ++nnuis;
    sigjes    = getSignalUncertainty(origsig, "SR_JESup",      "SR_JESup",      fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigjes   !=1.) ++nnuis;
    sigmurf   = getSignalUncertainty(origsig, "SR_muRFup",     "SR_muRFup",     fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigmurf  !=1.) ++nnuis;
    sigisr    = getSignalUncertainty(origsig, "SR_ISRup",      "SR_ISRdown",    fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigisr   !=1.) ++nnuis;
    sigpu     = getSignalUncertainty(origsig, "SR_PUup",       "SR_PUdown",     fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigpu    !=1.) ++nnuis;
    siglepeff = getSignalUncertainty(origsig, "SR_LepEffup",   "SR_LepEffup",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(siglepeff!=1.) ++nnuis;
    sigleffFS = getSignalUncertainty(origsig, "SR_LepEffFSup", "SR_LepEffFSup", fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigleffFS!=1.) ++nnuis;
  }
  sigtrig   = 1.01;  ++nnuis;
  siglum    = 1.046; ++nnuis;
  //get bg2l uncertainties
  double bg2lbsfhf, bg2lbsflf, bg2llepeff, bg2ltoppt, bg2lnjets, bg2lpdf, bg2lalphas, bg2lmurf, bg2ljes;
  if(!nobkgunc){
    bg2lbsfhf  = getBGUncertainty(bg2l, "CR2l_Bup_HF",    "CR2l_Bdown_HF",    f2l, b, true, minbin, maxbin, corrbins) if(bg2lbsfhf !=1.) ++nnuis;
    bg2lbsflf  = getBGUncertainty(bg2l, "CR2l_Bup_LF",    "CR2l_Bdown_LF",    f2l, b, true, minbin, maxbin, corrbins) if(bg2lbsflf !=1.) ++nnuis;
    bg2llepeff = getBGUncertainty(bg2l, "CR2l_LepEffup",  "CR2l_LepEffdown",  f2l, b, true, minbin, maxbin, corrbins) if(bg2llepeff!=1.) ++nnuis;
    bg2ltoppt  = getBGUncertainty(bg2l, "CR2l_TopPtup",   "CR2l_TopPtdown",   f2l, b, true, minbin, maxbin, corrbins) if(bg2ltoppt !=1.) ++nnuis;
    bg2lnjets  = getBGUncertainty(bg2l, "CR2l_njetsSFup", "CR2l_njetsSFdown", f2l, b, true, minbin, maxbin, corrbins) if(bg2lnjets !=1.) ++nnuis;
    bg2lpdf    = getBGUncertainty(bg2l, "CR2l_PDFup",     "CR2l_PDFdown",     f2l, b, true, minbin, maxbin, corrbins) if(bg2lpdf   !=1.) ++nnuis;
    bg2lalphas = getBGUncertainty(bg2l, "CR2l_Alphasup",  "CR2l_Alphasdown",  f2l, b, true, minbin, maxbin, corrbins) if(bg2lalphas!=1.) ++nnuis;
    bg2lmurf   = getBGUncertainty(bg2l, "CR2l_muRFup",    "CR2l_muRFdown",    f2l, b, true, minbin, maxbin, corrbins) if(bg2lmurf  !=1.) ++nnuis;
    bg2ljes    = getBGUncertainty(bg2l, "CR2l_JESup",     "CR2l_JESdown",     f2l, b, true, minbin, maxbin, corrbins) if(bg2ljes   !=1.) ++nnuis;
  }
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
  if(!nosigunc && sig    >0) *fLogStream << "SigStat" << b << "     lnN "             << sigerr     << "  -  -  -  -" << endl;
  if(!nosigunc && bg2l   >0) *fLogStream << "Bg2lStat" << b << "    lnN -  "          << bg2lerr    << "  -  -  -"    << endl;
  if(!nosigunc && bg1l   >0) *fLogStream << "Bg1lStat" << b << "    lnN -  -  "       << bg1lerr    << "  -  -"       << endl;
  if(!nosigunc && bg1ltop>0) *fLogStream << "Bg1lTopStat" << b << " lnN -  -  -  "    << bg1ltoperr << "  -"          << endl;
  if(!nosigunc && znunu  >0) *fLogStream << "BgZnunuStat" << b << " lnN -  -  -  -  " << bgznunuerr                   << endl;
  //signal systematic uncertainties (or general - therefore add no "Sig" prefix)
  if(sigtrig  !=1)    *fLogStream << " TrigSyst        lnN " << sigtrig   << "  -  -  -  -" << endl;//add znunu ttbar1l
  if(siglum   !=1)    *fLogStream << " LumSyst         lnN " << siglum    << "  -  -  -  -" << endl;//add znunu ttbar1l
  if(!nosigunc){
    if(sigbfslf !=1)  *fLogStream << " BLFSyst         lnN " << sigbfslf  << " -  -  -  -" << endl;//add all
    if(sigbfshf !=1)  *fLogStream << " BHFSyst         lnN " << sigbfshf  << " -  -  -  -" << endl;//add all
    if(sigjes   !=1)  *fLogStream << " JESSyst         lnN " << sigjes    << " -  -  -  -" << endl;//add all
    if(sigmurf  !=1)  *fLogStream << " MuRFSyst        lnN " << sigmurf   << " -  -  -  -" << endl;//add all
    //if(sigpu    !=1)  *fLogStream << " PUSyst            lnN " << sigpu     << " -  -  -  -" << endl;//add all
    if(siglepeff!=1)  *fLogStream << " LEffSyst        lnN " << siglepeff << " -  -  -  -" << endl;//add all
  }
  if(!nobkgunc){
    //bg2l
    if(bg2lbsfhf !=1) *fLogStream << " BHFSyst2l       lnN  - "<< bg2lbsfhf   << " -  -  -" << endl;
    if(bg2lbsflf !=1) *fLogStream << " BLFSyst2l       lnN  - "<< bg2lbsflf   << " -  -  -" << endl;
    if(bg2llepeff!=1) *fLogStream << " LEffSyst2l      lnN  - "<< bg2llepeff  << " -  -  -" << endl;
    if(bg2ltoppt !=1) *fLogStream << " TopPtSyst2l     lnN  - "<< bg2ltoppt   << " -  -  -" << endl;
    if(bg2lnjets !=1) *fLogStream << " NJSyst2l        lnN  - "<< bg2lnjets   << " -  -  -" << endl;
    if(bg2lpdf   !=1) *fLogStream << " PDFSyst2l       lnN  - "<< bg2lpdf     << " -  -  -" << endl;
    if(bg2lalphas!=1) *fLogStream << " AsSyst2l        lnN  - "<< bg2lalphas  << " -  -  -" << endl;
    if(bg2lmurf  !=1) *fLogStream << " muRFSyst2l      lnN  - "<< bg2lmurf    << " -  -  -" << endl;
    if(bg2ljes   !=1) *fLogStream << " JESSyst2l       lnN  - "<< bg2ljes     << " -  -  -" << endl;
  }
  *fLogStream << endl;

  if(fakedata)   outputdir = outputdir + "fakedata/";
  if(compressed==1) outputdir = outputdir + "compressed/";
  //outputdir = outputdir + "nocorrelations/";
  if(nosigunc&&nobkgunc) outputdir = "nounc/";
  else if(nosigunc) outputdir = "nosigunc/";
  else if(nobkgunc) outputdir = "nobkgunc/";
  MakeOutputDir(outputdir);
  TString logname = outputdir + "datacard_" + signalname + "_" + binstring + ".txt";
  ofstream f_log (logname.Data(), ios::trunc);
  f_log << fLogStream->str();
  cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;
  delete fLogStream;

}

double getSignalUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bx, int by, int bz, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  double upshapeerr=0; double downshapeerr=0;
  TH3D *h3u = (TH3D*)file->Get(upshape);
  TH3D *h3l = (TH3D*)file->Get(downshape);
  if(correlated){
    if(corrbins.size()==0){
      for(unsigned int i = minbin; i<=maxbin; ++i){
	upshapeerr   += pow(TMath::Abs(origyield-h3u->GetBinContent(bx,by,i))/origyield,2);
	downshapeerr += pow(TMath::Abs(origyield-h3l->GetBinContent(bx,by,i))/origyield,2);
      }
    } else {
      for(unsigned int i = 0; i<=corrbins.size(); ++i){
	if(corrbins[i]<minbin) continue;
	if(corrbins[i]>maxbin) continue;
	upshapeerr   += pow(TMath::Abs(origyield-h3u->GetBinContent(bx,by,corrbins[i] ))/origyield,2);
      	downshapeerr += pow(TMath::Abs(origyield-h3l->GetBinContent(bx,by,corrbins[i] ))/origyield,2);
      }
    }
  } else {
    upshapeerr   = TMath::Abs(origyield-h3u->GetBinContent(bin))/origsig;
    downshapeerr = TMath::Abs(origyield-h3l->GetBinContent(bin))/origyield;
  }
  if(upshapeerr>downshapeerr) return 1.+(origyield-h3u->GetBinContent(bin))/origyield;
  else                        return 1.+(origyield-h3l->GetBinContent(bin))/origyield;
}

double getBGUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  double upshapeerr=0; double downshapeerr=0;
  TH1D *hu = (TH1D*)file->Get(upshape);
  TH1D *hl = (TH1D*)file->Get(downshape);
  if(correlated){
    if(corrbins.size()==0){
      for(unsigned int i = minbin; i<=maxbin; ++i){
	upshapeerr   += pow(TMath::Abs(origyield-hu->GetBinContent(i))/origyield,2);
	downshapeerr += pow(TMath::Abs(origyield-hl->GetBinContent(i))/origyield,2);
      }
    } else {
      for(unsigned int i = 0; i<=corrbins.size(); ++i){
	if(corrbins[i]<minbin) continue;
	if(corrbins[i]>maxbin) continue;
	upshapeerr   += pow(TMath::Abs(origyield-hu->GetBinContent(corrbins[i] ))/origyield,2);
      	downshapeerr += pow(TMath::Abs(origyield-hl->GetBinContent(corrbins[i] ))/origyield,2);
      }
    }
  } else {
    upshapeerr   = TMath::Abs(origyield-hu->GetBinContent(bin))/origsig;
    downshapeerr = TMath::Abs(origyield-hl->GetBinContent(bin))/origyield;
  }
  if(upshapeerr>downshapeerr) return 1.+(origyield-hu->GetBinContent(bin))/origyield;
  else                        return 1.+(origyield-hl->GetBinContent(bin))/origyield;
}


//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02
