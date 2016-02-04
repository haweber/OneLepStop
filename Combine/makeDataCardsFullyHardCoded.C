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

//string inputdir = "inputfiles/";
string inputdir = "../SignalAnalysisCode/rootfiles/signalyields/";
string outputdir = "datacards2p3fbinv/";
bool nosigunc = false;
bool nobkgunc = false;
bool updateplottinghisto = true;

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}

void makeDataCardsFullyHardCodedOneBin(int bin=0, TString signaltype="T2tt", int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllBins(TString signaltype="T2tt", int stop=100, int lsp=0, int charg=-1, float xval=-1, bool fakedata=false, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedOneScan(TString signaltype="T2tt", bool fakedata=false, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);
void makeDataCardsFullyHardCodedAllScans(bool fakedata, bool nosyst=false, int xsecupdown=-1, int compressed=0, bool dropsigcont=false);

double getSignalUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bx, int by, int bz, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins);
double getBGUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins);
double getBGError(double origyield, TString errshape, TFile *file, int bin);
double getBGErrorRel(double origyield, TString errshape, TFile *file, int bin);
//double getBGUncertainty(double origyield, TString upshape, TString downshape, TString filename, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins);

int GetLLBin(int b);
int GetTTZBin(int b);

void makeDataCardsFullyHardCodedAllScans(bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){
  makeDataCardsFullyHardCodedOneScan("T2tt",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2tb",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2bW_x0p75",fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  makeDataCardsFullyHardCodedOneScan("T2bW_x0p25",fakedata, nosyst, xsecupdown, compressed, dropsigcont);

}

void makeDataCardsFullyHardCodedOneScan(TString signaltype, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){
  float chargLow = -1;
  for(int t = 0; t<=1000; t+=25){
    for(int l = 0; l<=450; l+=25){
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
  else { maxbin = 9; startbin = 1; }
  for(int bin = startbin; bin < (startbin+maxbin); ++bin){
    makeDataCardsFullyHardCodedOneBin(bin,signaltype, stop, lsp, charg, xval, fakedata, nosyst, xsecupdown, compressed, dropsigcont);
  }
}



void makeDataCardsFullyHardCodedOneBin(int bin,TString signaltype, int stop, int lsp, int charg, float xval, bool fakedata, bool nosyst, int xsecupdown, int compressed, bool dropsigcont){

  if(compressed==0&&bin<1) return;
  if(compressed==0&&bin>9) return;
  if(compressed==1&&bin<11) return;
  if(compressed==1&&bin>12) return;
  int minbin = 1;//run only baseline analysis
  int maxbin = 9;//run only baseline analysis
  if(compressed==1){
    minbin = 11;
    maxbin = 12;
  }
  if(stop<lsp) return;
  int nbgs = 0;
  int nnuis = 0;
  TString filename = inputdir + "Histos_Signal_" + signaltype + "_All.root";
  ifstream infileSig(filename.Data());
  if(!(infileSig.good() ) ) return;
  TFile *fsig = new TFile(filename,"READ");
  if(fsig->IsZombie()) {
    fsig->Close();
    delete fsig;
    cout << "No Signal file - exit" << endl;
    return;
    exit(0);
  }
  filename = inputdir + "histos__diLepton_Bkg_Estimate_25ns.root";
  //filename = inputdir + "Background_2l.root";
  ifstream infileLL(filename.Data());
  if(!(infileLL.good() ) ) return;
  TFile *f2l = new TFile(filename,"READ");
  if(f2l->IsZombie()) {
    f2l->Close();
    delete f2l;
    cout << "No 2l file - exit" << endl;
    return;
  }
  // XXX
  filename = inputdir + "Background_1l_dummy.root";
  ifstream infile0b(filename.Data());
  if(!(infile0b.good() ) ) return;
  TFile *f1l = new TFile(filename,"READ");
  if(f1l->IsZombie()) {
    f1l->Close();
    delete f1l;
    cout << "No 1l file - exit" << endl;
    return;
  }
  //filename = inputdir + "Background_1ltop_dummy.root";
  filename = inputdir + "TT1lyield2p3fbinv.root";
  ifstream infile1lt(filename.Data());
  if(!(infile1lt.good() ) ) return;
  TFile *f1ltop = new TFile(filename,"READ");
  if(f1ltop->IsZombie()) {
    f1ltop->Close();
    delete f1ltop;
    cout << "No 1ltop file - exit" << endl;
    return;
  }
  //filename = inputdir + "Background_ttz.root";
  filename = inputdir + "hFile_rare_Syst_correctSum_finalRelUnc_hists_0201_allfixJES_modtopness_with_toppt_reweight.root";
  ifstream infilettz(filename.Data());
  if(!(infilettz.good() ) ) return;
  TFile *fznunu = new TFile(filename,"READ");
  if(fznunu->IsZombie()) {
    fznunu->Close();
    delete fznunu;
    cout << "No Znunu file - exit" << endl;
    return;
  }
  // XXX
  TFile *fdata;
  if(!fakedata) {
    filename= inputdir + "DATAyield2p3fbinv.root";
    ifstream infileData(filename.Data());
    if(!(infileData.good() ) ) return;
    fdata = new TFile(filename,"READ");
    if(fdata->IsZombie()) {
      fdata->Close();
      delete fdata;
      cout << "No Data file - exit" << endl;
      return;
    }
  }
  else fdata = (TFile*)f2l->Clone("Data.root");

  double sig(0.), sigerr(0.);
  double origsig(0.), origsigerr(0.);//keep original without signal contamination
  double data(0.), dataerr(0.);
  double bg2l(0.), bg2lerr(0.), bg1l(0.), bg1lerr(0.), bg1ltop(0.), bg1ltoperr(0.), bgznunu(0.), bgznunuerr(0.);
  TH1D *h;
  TH3D *h3;
  int b,b3;
  b = bin;//need to use bin = 1 - 6 for main analysis - this is not binlowedge - i.e. cannot use find bin
  //if(compressed==1) b = bin+5;//check if needed - probably no
  TString histname;
  histname = "SRyield"; h3 = (TH3D*)fsig->Get(histname);
  int bx,by,bz;
  bx = h3->GetXaxis()->FindBin(stop);
  by = h3->GetYaxis()->FindBin(lsp);
  bz = h3->GetZaxis()->FindBin(b);
  //cout << "bin:stop:lsp " << bin << ":" << stop << ":" << lsp << " bz,bx,by " << bz << "," << bx << "," << by
  //     << " xrange " << h3->GetXaxis()->GetBinLowEdge(bx) << "-" << h3->GetXaxis()->GetBinLowEdge(bx)+h3->GetXaxis()->GetBinWidth(bx)
  //     << " yrange " << h3->GetYaxis()->GetBinLowEdge(by) << "-" << h3->GetYaxis()->GetBinLowEdge(by)+h3->GetYaxis()->GetBinWidth(by)
  //     << " zrange " << h3->GetZaxis()->GetBinLowEdge(bz) << "-" << h3->GetZaxis()->GetBinLowEdge(bz)+h3->GetZaxis()->GetBinWidth(bz)
  //     << endl;
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
  b3 = h3->FindBin(stop,lsp,b);
  if(b3!=h3->GetBin(bx,by,bz)) cout << "Check this " << "b:stop:lsp " << b << ":" << stop << ":" << lsp << " are bins " << bx << ":"<<by<<":"<<bz <<" are global bin " << h3->GetBin(bx,by,bz) << " and also should be findbin b3 " << b3 << endl;
  int bLL = GetLLBin(b);
  int bTTZ = GetTTZBin(b);
  
  //get all yields and statistical uncertainties - also signal contamination
  sig = h3->GetBinContent(b3);
  bool bogussignal = false;
  if(sig<=0) {
    //  cout << "There is no signal (" << signaltype <<"_"<<stop<<"_"<<lsp << ") in this bin (" << bin << ") - no datacard is made!!!!!!!!" << endl;
    bogussignal = true;
    sig = 1;
    //  return;
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
  double cont1; double cont2;
  if(!dropsigcont){
    histname = "CR1l_sigcontamination"; h3 = (TH3D*)fsig->Get(histname);
    double temp = h3->GetBinContent(b3); sig = TMath::Max(0., sig-temp); cont1 = temp;
    histname = "CR2l_sigcontamination"; h3 = (TH3D*)fsig->Get(histname);
    temp = h3->GetBinContent(b3); sig = TMath::Max(0., sig-temp); cont2 = temp;
    //if(!bogussignal) cout << "orig " << origsig << " CR1l_cont " << cont1 << " CR2l_cont " << cont2 << endl;
  }
  histname = "Data";
  if(fakedata) histname = "CR2lyield";
  h = (TH1D*)fdata->Get(histname);
  //if(h->GetBin(bz)!=b) cout << "Check this " << "b " << b << " bz " << bz << endl;

  if(!fakedata) data = h->GetBinContent(b);
  //else data = h->GetBinContent(bLL); //dataerr = 1.+h->GetBinError(b)/data;//do I need the data err;
  histname = "CR2lyield"; h = (TH1D*)f2l->Get(histname);
  //cout << "bin " << bin << " b " << b << " bz " << bz << endl;
  //cout << "h->GetBinLowEdge(bin) " << h->GetBinLowEdge(bin) << endl;
  bg2l = h->GetBinContent(bLL); ++nbgs;
  //cout << "sig vs bg " << sig << " vs " << bg2l << endl;
  if(bg2l>0) { bg2lerr = 1.+((h->GetBinError(bLL))/bg2l); ++nnuis;}
  //histname = "CR2lstat"; h = (TH1D*)f2l->Get(histname);
  //if(bg2l>0) {bg2lerr = 1.+((h->GetBinContent(b))/bg2l); ++nnuis;}
  // XXX
  histname = "CR0b_est"; h = (TH1D*)f1l->Get(histname);
  bg1l = h->GetBinContent(b); ++nbgs;
  //histname = "CR1lstat"; h = (TH1D*)f1l->Get(histname);
  //if(bg1l>0) {bg1lerr = 1.+((h->GetBinContent(b))/bg1l); ++nnuis;}
  if(bg1l>0) {bg1lerr = 1.+((h->GetBinError(b))/bg1l); ++nnuis;}
  histname = "CRtt1l_yield"; h = (TH1D*)f1ltop->Get(histname);
  bg1ltop = h->GetBinContent(b); ++nbgs;
  //if(bg1ltop>0) { bg1ltoperr = 1.+h->GetBinError(b)/bg1ltop; ++nnuis;}
  if(bg1ltop>0) { bg1ltoperr = 2.; ++nnuis;}//100%
  //histname = "CRttz_est"; h = (TH1D*)fznunu->Get(histname);
  histname = "h_signal_bins_rare"; h = (TH1D*)fznunu->Get(histname);
  bgznunu = h->GetBinContent(bTTZ); ++nbgs;
  if(bgznunu>0) { bgznunuerr = 1.+h->GetBinError(bTTZ)/bgznunu; ++nnuis; }
  // XXX
  if(nbgs!=4) cout << "Check your background" << endl;
  if(sig<=0 || (bg2l+bg1l+bg1ltop+bgznunu)<=0) {
    //cout << "Am here (" << signaltype <<"_"<<stop<<"_"<<lsp << ") in this bin (" << bin << ")" << endl;
    //cout << "sig " << sig << " bg2l " << bg2l << " bg1l " << bg1l << " bg1ltop " << bg1ltop << " bgznunu " << bgznunu << endl;
    //cout << "origsig " << origsig << " cont1 " << cont1 << " cont2 " << cont2 << endl;
    bogussignal = true;
    h->Delete();
    h3->Delete();
    fsig->Close();
    f2l->Close();
    f1l->Close();
    f1ltop->Close();
    fznunu->Close();
    fdata->Close();
    delete fznunu;
    delete f1ltop;
    delete f1l;
    delete f2l;
    delete fsig;
    delete fdata;
    return;//empty datacard - probably empty point
  }
  //cout << "Nuis before sig " << nnuis << endl;
  //get signal uncertainties
  double sigbsfhf(1.), sigbsflf(1.), sigjes(1.), sigmurf(1.), sigisr(1.), sigpu(1.), siglepeff(1.), sigleffFS(1.);
  double sigtrig(1.), siglum(1.), sigleffveto(1.);
  vector<int> corrbins; corrbins.clear();
  if(!nosigunc){
    sigbsfhf  = getSignalUncertainty(origsig, "SR_Bup_HF",     "SR_Bdown_HF",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigbsfhf !=1.) ++nnuis;
    sigbsflf  = getSignalUncertainty(origsig, "SR_Bup_LF",     "SR_Bdown_LF",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigbsflf !=1.) ++nnuis;
    sigjes    = getSignalUncertainty(origsig, "SR_JESup",      "SR_JESdown",      fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigjes   !=1.) ++nnuis;
    sigmurf   = getSignalUncertainty(origsig, "SR_muRFup",     "SR_muRFdown",     fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigmurf  !=1.) ++nnuis;
    sigisr    = getSignalUncertainty(origsig, "SR_ISRup",      "SR_ISRdown",    fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigisr   !=1.) ++nnuis;
    //sigpu     = getSignalUncertainty(origsig, "SR_PUup",       "SR_PUdown",     fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigpu    !=1.) ++nnuis;
    siglepeff = getSignalUncertainty(origsig, "SR_LepEffup",   "SR_LepEffdown",   fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(siglepeff!=1.) ++nnuis;
    sigleffFS = getSignalUncertainty(origsig, "SR_LepEffFSup", "SR_LepEffFSdown", fsig, bx,by,bz,b3,  true, minbin, maxbin, corrbins); if(sigleffFS!=1.) ++nnuis;
  }
  sigtrig   = 1.01;  ++nnuis;
  siglum    = 1.046; ++nnuis;
  sigleffveto = 1.03; ++nnuis;
  //cout << "Nuis after sig " << nnuis << endl;
  //get bg2l uncertainties
  double bg2lbsfhf(1.), bg2lbsflf(1.), bg2llepeff(1.), bg2ltoppt(1.), bg2lnjets(1.), bg2lpdf(1.), bg2lalphas(1.), bg2lmurf(1.), bg2ljes(1.), bg2lmet(1.);
  if(!nobkgunc){
    bg2lbsfhf  = getBGUncertainty(bg2l, "CR2l_Bup_HF",    "CR2l_Bdown_HF",    f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lbsfhf !=1.) ++nnuis;
    bg2lbsflf  = getBGUncertainty(bg2l, "CR2l_Bup_LF",    "CR2l_Bdown_LF",    f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lbsflf !=1.) ++nnuis;
    bg2llepeff = getBGUncertainty(bg2l, "CR2l_LepEffup",  "CR2l_LepEffdown",  f2l, bLL, true, minbin, maxbin, corrbins); if(bg2llepeff!=1.) ++nnuis;
    bg2ltoppt  = getBGUncertainty(bg2l, "CR2l_TopPtup",   "CR2l_TopPtdown",   f2l, bLL, true, minbin, maxbin, corrbins); if(bg2ltoppt !=1.) ++nnuis;
    bg2lnjets  = getBGUncertainty(bg2l, "CR2l_nJetsSFup", "CR2l_nJetsSFdown", f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lnjets !=1.) ++nnuis;
    bg2lpdf    = getBGUncertainty(bg2l, "CR2l_PDFup",     "CR2l_PDFdown",     f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lpdf   !=1.) ++nnuis;
    bg2lalphas = getBGUncertainty(bg2l, "CR2l_Alphasup",  "CR2l_Alphasdown",  f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lalphas!=1.) ++nnuis;
    bg2lmurf   = getBGUncertainty(bg2l, "CR2l_muRFup",    "CR2l_muRFdown",    f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lmurf  !=1.) ++nnuis;
    bg2ljes    = getBGUncertainty(bg2l, "CR2l_JESup",     "CR2l_JESdown",     f2l, bLL, true, minbin, maxbin, corrbins); if(bg2ljes   !=1.) ++nnuis;
    bg2lmet    = getBGUncertainty(bg2l, "CR2l_metResup",  "CR2l_metResdown",  f2l, bLL, true, minbin, maxbin, corrbins); if(bg2lmet   !=1.) ++nnuis;
  }
  //cout << "Nuis after bg2l " << nnuis << endl;
  //get bg1l uncertainties
  double bg1lmc(1.), bg1lcont(1.), bg1lmet(1.), bg1lbsf(1.);
  if(!nobkgunc){
    bg1lmc   = getBGError(bg1l, "CR0b_MCstats", f1l, b); if(bg1lmc   !=1.) ++nnuis;
    bg1lcont = getBGError(bg1l, "CR0b_Cont",    f1l, b); if(bg1lcont !=1.) ++nnuis;
    bg1lmet  = getBGError(bg1l, "CR0b_TFMET",   f1l, b); if(bg1lmet  !=1.) ++nnuis;
    bg1lbsf  = getBGError(bg1l, "CR0b_TFBSF",   f1l, b); if(bg1lbsf  !=1.) ++nnuis;
  }
  //cout << "Nuis after bg1l " << nnuis << endl;
  //get bg1ltop uncertainties
  //get bgZnunu uncertainties
  double bgzpu(1.), bgzleff(1.), bgzjes(1.), bgzbsf(1.), bgztpt(1.), bgzpdf(1.), bgzqsq(1.);
  if(!nobkgunc){
    //bgzpu   = getBGError(bgznunu, "CRttz_PU",   fznunu, bTTZ); if(bgzpu   !=1.) ++nnuis;
    //bgzleff = getBGError(bgznunu, "CRttz_LEff", fznunu, bTTZ); if(bgzleff !=1.) ++nnuis;
    //bgzjes  = getBGError(bgznunu, "CRttz_JES",  fznunu, bTTZ); if(bgzjes  !=1.) ++nnuis;
    //bgzbsf  = getBGError(bgznunu, "CRttz_BSF",  fznunu, bTTZ); if(bgzbsf  !=1.) ++nnuis;
    //bgztpt  = getBGError(bgznunu, "CRttz_QSq",  fznunu, bTTZ); if(bgztpt  !=1.) ++nnuis;
    //bgzpdf  = getBGError(bgznunu, "CRttz_PDF",  fznunu, bTTZ); if(bgzpdf  !=1.) ++nnuis;
    bgzpu   = getBGErrorRel(bgznunu, "h_relUnc_PU",          fznunu, bTTZ); if(bgzpu   !=1.) ++nnuis;
    bgzleff = getBGErrorRel(bgznunu, "h_relUnc_lepSF",       fznunu, bTTZ); if(bgzleff !=1.) ++nnuis;
    bgzjes  = getBGErrorRel(bgznunu, "h_relUnc_JES",         fznunu, bTTZ); if(bgzjes  !=1.) ++nnuis;
    bgzbsf  = getBGErrorRel(bgznunu, "h_relUnc_BTagSF",      fznunu, bTTZ); if(bgzbsf  !=1.) ++nnuis;
    bgztpt  = getBGErrorRel(bgznunu, "h_relUnc_ttbar_pt",    fznunu, bTTZ); if(bgztpt  !=1.) ++nnuis;
    bgzpdf  = getBGErrorRel(bgznunu, "h_relUnc_th_PDF_total",fznunu, bTTZ); if(bgzpdf  !=1.) ++nnuis;
    bgzqsq  = getBGErrorRel(bgznunu, "h_relUnc_th_Scale",    fznunu, bTTZ); if(bgzqsq  !=1.) ++nnuis;
  }
  //cout << "Nuis after bgz " << nnuis << endl;
  //now ready to make the data card
  std::ostringstream* fLogStream     = 0;
  fLogStream = new std::ostringstream();
  string binstring = "b" + std::to_string(b);
  TString signalname = signaltype + "_" + std::to_string(stop) + "_" + std::to_string(lsp);

  
  *fLogStream << "# My significance experiment" << endl
	      << "imax  " << 1     << "  number of channels" << endl//single bin
	      << "jmax  " << nbgs  << "  number of backgrounds" << endl
	      << "kmax "  << nnuis << "  number of nuisance parameters" << endl;
  *fLogStream << "------------" << endl << "# observations " << endl;
  *fLogStream << "bin         " << b << endl;
  if(fakedata) *fLogStream << "observation " << int(bg2l+bg1l+bg1ltop+bgznunu) << endl;//use int if one uses fake data
  else *fLogStream << "observation " << int(data) << endl;//use int if one uses fake data
  *fLogStream << "------------" << endl;
  *fLogStream << "#now we list all expected number of events" << endl;
  *fLogStream << "bin          " << b << "       " << b << "       " << b << "       " << b << "       " << b << "       " << endl;
  *fLogStream << "process     sig       2l       1l       1ltop       znunu" << endl;
  *fLogStream << "process      0     1    2    3       4" << endl;
  *fLogStream << "rate        " << sig << "  " << bg2l << "  " << bg1l << "  " << bg1ltop << "  " << bgznunu << endl;
  *fLogStream << "------------" << endl;
  //next ALL control region statistical uncertainties
  if(!nosigunc && sig    >0) *fLogStream << "SigStat"     << b << "     lnN "             << sigerr     << "  -  -  -  -" << endl;
  if(!nosigunc && bg2l   >0) *fLogStream << "Bg2lStat"    << b << "     lnN -  "          << bg2lerr    << "  -  -  -"    << endl;
  if(!nosigunc && bg1l   >0) *fLogStream << "Bg1lStat"    << b << "     lnN -  -  "       << bg1lerr    << "  -  -"       << endl;
  if(!nosigunc && bg1ltop>0) *fLogStream << "Bg1lTopStat" << b << "     lnN -  -  -  "    << bg1ltoperr << "  -"          << endl;
  if(!nosigunc && bgznunu>0) *fLogStream << "BgZnunuStat" << b << "     lnN -  -  -  -  " << bgznunuerr                   << endl;
  //signal systematic uncertainties (or general - therefore add no "Sig" prefix)
  if(sigtrig  !=1)    *fLogStream << " TrigSyst        lnN " << sigtrig   << "  -  - " << sigtrig << "  " << sigtrig << endl;//add znunu ttbar1l
  if(siglum   !=1)    *fLogStream << " LumSyst         lnN " << siglum    << "  -  - " << siglum  << "  " << siglum  << endl;//add znunu ttbar1l
  if(!nosigunc){
    if(sigbsflf !=1)  *fLogStream << " BLFSyst         lnN " << sigbsflf  << " -  -  -  -" << endl;//add all
    if(sigbsfhf !=1)  *fLogStream << " BHFSyst         lnN " << sigbsfhf  << " -  -  -  -" << endl;//add all
    if(sigjes   !=1)  *fLogStream << " JESSyst         lnN " << sigjes    << " -  -  -  -" << endl;//add all
    if(sigisr   !=1)  *fLogStream << " ISRSyst         lnN " << sigisr    << " -  -  -  -" << endl;//add all
    if(sigmurf  !=1)  *fLogStream << " MuRFSyst        lnN " << sigmurf   << " -  -  -  -" << endl;//add all
    //if(sigpu    !=1)  *fLogStream << " PUSyst            lnN " << sigpu     << " -  -  -  -" << endl;//add all
    if(siglepeff!=1)  *fLogStream << " LEffSyst        lnN " << siglepeff << " -  -  -  -" << endl;//add all
    if(sigleffFS!=1)  *fLogStream << " LEffFSSyst      lnN " << sigleffFS << " -  -  -  -" << endl;//add all
                      *fLogStream << " LVetoSyst" << b <<"       lnN " << sigleffveto << " -  -  -  -" << endl;//add all
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
    if(bg2lmet   !=1) *fLogStream << " METSyst2l       lnN  - "<< bg2lmet     << " -  -  -" << endl;
    //bg1l
    if(bg1lmc   !=1) *fLogStream << " MCSyst1l" << b <<"        lnN  -  - "<< bg1lmc   << "  -  -" << endl;
    if(bg1lcont !=1) *fLogStream << " ContSyst1l" << b <<"      lnN  -  - "<< bg1lcont << "  -  -" << endl;
    if(bg1lmet  !=1) *fLogStream << " METSyst1l" << b <<"       lnN  -  - "<< bg1lmet  << "  -  -" << endl;
    if(bg1lbsf  !=1) *fLogStream << " BSFSyst1l" << b <<"       lnN  -  - "<< bg1lbsf  << "  -  -" << endl;
    //bg1ltop
    //bgznunu
    if(bgzpu   !=1) *fLogStream << " PUSystZ         lnN  -  -  -  - "<< bgzpu   << endl;
    if(bgzleff !=1) *fLogStream << " LEffSystZ       lnN  -  -  -  - "<< bgzleff << endl;
    if(bgzjes  !=1) *fLogStream << " JESSystZ        lnN  -  -  -  - "<< bgzjes  << endl;
    if(bgzbsf  !=1) *fLogStream << " BSFSystZ        lnN  -  -  -  - "<< bgzbsf  << endl;
    if(bgztpt  !=1) *fLogStream << " TPtSystZ" << b <<"        lnN  -  -  -  - "<< bgztpt  << endl;
    if(bgzpdf  !=1) *fLogStream << " PDFSystZ" << b <<"        lnN  -  -  -  - "<< bgzpdf  << endl;
    if(bgzqsq  !=1) *fLogStream << " QsqSystZ" << b <<"        lnN  -  -  -  - "<< bgzqsq  << endl;
  }
  *fLogStream << endl;

  TString myoutputdir = outputdir;
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  //myoutputdir = myoutputdir + "nocorrelations/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir+ "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir+ "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  if(dropsigcont) myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  MakeOutputDir(myoutputdir);
  TString logname = myoutputdir + "datacard_" + signalname + "_" + binstring + ".txt";
  if(!bogussignal) {
    ofstream f_log (logname.Data(), ios::trunc);
    f_log << fLogStream->str();
    cout << "wrote results into  " << logname <<  " (old file replaced)" << endl;
  }
  delete fLogStream;

  if(updateplottinghisto){
    bool updatesignal = false;
    TString uname = inputdir;
    if(compressed==1) uname = uname + "compressed/";
    //myoutputdir = uname + "uname/";
    if(nosigunc&&nobkgunc) uname = uname+ "nounc/";
    else if(nosigunc) uname = uname+ "nosigunc/";
    else if(nobkgunc) uname = uname + "nobkgunc/";
    if(dropsigcont) uname = uname + "dropsigcont/";
    if(fakedata)   uname = uname + "fakedata/";
    MakeOutputDir(uname);
    uname = uname + "ResultPlotTable.root";
    TFile *updatefile = new TFile(uname,"update");
    updatefile->cd();
    TH1D *rpt_Data  = (TH1D*)updatefile->Get("rpt_Data");
    TH1D *rpt_LLest = (TH1D*)updatefile->Get("rpt_LLest");
    TH1D *rpt_0best = (TH1D*)updatefile->Get("rpt_0best");
    TH1D *rpt_tt1l  = (TH1D*)updatefile->Get("rpt_tt1l");
    TH1D *rpt_znunu = (TH1D*)updatefile->Get("rpt_znunu");
    TH1D *rpt_sig;
    if(     signalname=="T2tt_750_50" ){ updatesignal = true; rpt_sig = (TH1D*)updatefile->Get("rpt_T2tt_750_50" ); }
    else if(signalname=="T2tt_600_250"){ updatesignal = true; rpt_sig = (TH1D*)updatefile->Get("rpt_T2tt_600_250"); }
    else if(signalname=="T2tt_500_100"){ updatesignal = true; rpt_sig = (TH1D*)updatefile->Get("rpt_T2tt_500_100"); }
    else if(signalname=="T2tt_300_200"){ updatesignal = true; rpt_sig = (TH1D*)updatefile->Get("rpt_T2tt_300_200"); }
   rpt_Data->SetBinContent(b,int(data)); rpt_Data->SetBinError(b,sqrt(data));
    rpt_LLest->SetBinContent(b,bg2l); rpt_LLest->SetBinError(b,bg2l*sqrt(pow(1.-bg2lerr,2) + pow(1.-bg2lbsfhf,2)+pow(1.-bg2lbsflf,2)+pow(1.-bg2llepeff,2)+pow(1.-bg2ltoppt,2)+pow(1.-bg2lnjets,2)+pow(1.-bg2lpdf,2)+pow(1.-bg2lalphas,2)+pow(1.-bg2lmurf,2)+pow(1.-bg2ljes,2)+pow(1.-bg2lmet,2) ) );
    rpt_0best->SetBinContent(b,bg1l); rpt_0best->SetBinError(b,bg1l*sqrt( pow(1.-bg1lerr,2)+pow(1.-bg1lmc,2)+pow(1.-bg1lcont,2)+pow(1.-bg1lmet,2)+pow(1.-bg1lbsf,2) ) );
    rpt_tt1l->SetBinContent(b,bg1ltop); rpt_tt1l->SetBinError(b,bg1ltop*(1.-bg1ltoperr) );
    rpt_znunu->SetBinContent(b,bgznunu); rpt_znunu->SetBinError(b,bgznunu*sqrt(pow(1.-bgznunuerr,2)+pow(1.-bgzpu,2)+pow(1.-bgzleff,2)+pow(1.-bgzjes,2)+pow(1.-bgzbsf,2)+pow(1.-bgztpt,2)+pow(1.-bgzpdf,2) ) );
    if(updatesignal){
      rpt_sig->SetBinContent(b,sig); rpt_sig->SetBinError(b,sig*sqrt(pow(1.-sigerr,2) + pow(1.-sigtrig,2)+pow(1.-siglum,2)+pow(1.-sigbsflf,2)+pow(1.-sigbsfhf,2)+pow(1.-sigjes,2)+pow(1.-sigmurf,2)+pow(1.-siglepeff,2)+pow(1.-sigleffFS,2)+pow(1.-sigleffveto,2) ) );
    }
    updatefile->cd();
    rpt_Data ->Write(rpt_Data ->GetName(),TObject::kOverwrite);//see TObject
    rpt_LLest->Write(rpt_LLest->GetName(),TObject::kOverwrite);
    rpt_0best->Write(rpt_0best->GetName(),TObject::kOverwrite);
    rpt_tt1l ->Write(rpt_tt1l ->GetName(),TObject::kOverwrite);
    rpt_znunu->Write(rpt_znunu->GetName(),TObject::kOverwrite);
    if(updatesignal) rpt_sig  ->Write(rpt_sig  ->GetName(),TObject::kOverwrite);
    updatefile->Close();
    //rpt_Data ->Delete();
    //rpt_LLest->Delete();
    //rpt_0best->Delete();
    //rpt_tt1l ->Delete();
    //rpt_znunu->Delete();
    //if(updatesignal) rpt_sig->Delete();
    delete updatefile;
  }
  
  h->Delete();
  h3->Delete();
  fsig->Close();
  f2l->Close();
  // XXX
  f1l->Close();
  f1ltop->Close();
  fznunu->Close();
  // XXX
  fdata->Close();
  // XXX
  delete fznunu;
  delete f1ltop;
  delete f1l;
  // XXX
  delete f2l;
  delete fsig;
  delete fdata;
  TList *files = (TList*)gDirectory->GetListOfKeys();
  TListIter next(files);
  TObject *obj;
  while ((obj = next()))
    cout << obj->GetName() << endl;
  

}

double getSignalUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bx, int by, int bz, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  //cout << "I want shape " << upshape << "/" << downshape << " for original yield " << origyield << " from file " << file->GetName() << endl;
  double upshapeerr=0; double downshapeerr=0;
  TH3D *h3u = (TH3D*)file->Get(upshape);
  TH3D *h3l = (TH3D*)file->Get(downshape);
  if(correlated){
    if(corrbins.size()==0){
      for(int i = minbin; i<=maxbin; ++i){
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
    upshapeerr   = TMath::Abs(origyield-h3u->GetBinContent(bin))/origyield;
    downshapeerr = TMath::Abs(origyield-h3l->GetBinContent(bin))/origyield;
  }
  double upcontent   = h3u->GetBinContent(bin);
  double downcontent = h3l->GetBinContent(bin);
  //if("SR_JESup"==upshape&&origyield!=1) cout << "orig " << origyield << " up " << upcontent << " down " << downcontent << endl;
  //h3u->Delete();
  //h3l->Delete();
    double tmp;
  if(upshapeerr>downshapeerr) tmp = 1.+(origyield-  upcontent)/origyield;
  else                        tmp = 1.+(origyield-downcontent)/origyield;
  if(tmp<0) tmp = 0.0001;
  else if (tmp>2) tmp = 2;
  return tmp;
}

//up and down variations given
double getBGUncertainty(double origyield, TString upshape, TString downshape, TFile *file, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins){
//double getBGUncertainty(double origyield, TString upshape, TString downshape, TString filename, int bin, bool correlated, int minbin, int maxbin, vector<int> corrbins){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  double upshapeerr=0; double downshapeerr=0;
  //TFile *file = new TFile(filename,"read");
  //cout << "I want shape " << upshape << "/" << downshape << " for original yield " << origyield << " from file " << file->GetName() << endl;
  TH1D *hu = (TH1D*)file->Get(upshape);
  TH1D *hl = (TH1D*)file->Get(downshape);
  if(correlated){
    if(corrbins.size()==0){
      for(int i = minbin; i<=maxbin; ++i){
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
    upshapeerr   = TMath::Abs(origyield-hu->GetBinContent(bin))/origyield;
    downshapeerr = TMath::Abs(origyield-hl->GetBinContent(bin))/origyield;
  }
  double upcontent   = hu->GetBinContent(bin);
  double downcontent = hl->GetBinContent(bin);
  //file->Close();
  //delete file;
  hu->Delete();
  hl->Delete();
  double tmp;
  if(upshapeerr>downshapeerr) tmp = 1.+(origyield-  upcontent)/origyield;
  else                        tmp = 1.+(origyield-downcontent)/origyield;
  if(tmp<0) tmp = 0.0001;
  else if (tmp>2) tmp = 2;
  return tmp;
}

//absolute error is given
double getBGError(double origyield, TString errshape, TFile *file, int bin){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  double err=0; 
  TH1D *h = (TH1D*)file->Get(errshape);
  err   = TMath::Abs(origyield+h->GetBinContent(bin))/origyield;

  h->Delete();
  if(err<0) err = 0.0001;
  else if (err>2) err = 2;
  return err;
}

//relative error is given
double getBGErrorRel(double origyield, TString errshape, TFile *file, int bin){
  if(origyield <= 0){
    cout << "This uncertainty should not exists, as there is no yield at all - returning 1." << endl;
    return 1.;
  }
  double err=0; 
  TH1D *h = (TH1D*)file->Get(errshape);
  err   = 1+h->GetBinContent(bin);

  h->Delete();
  if(err<0) err = 0.0001;
  else if (err>2) err = 2;
  return err;
}

int GetLLBin(int b){
  if(b==1) return 8;//2j,MET250
  if(b==2) return 9;//2j,MET350
  if(b==3) return 6;//3j,MET250
  if(b==4) return 7;//3j,MET350
  if(b==5) return 1;//lDM,MET250
  if(b==6) return 2;//lDM,MET325
  if(b==7) return 3;//hDM,MET250
  if(b==8) return 4;//hDM,MET350
  if(b==9) return 5;//hDM,MET450
  cout << "This should not happen return -1" << endl;
  return -1;
}

int GetTTZBin(int b){
  if(b<1) {
    cout << "This should not happen return -1" << endl;
    return -1;
  }
  if(b>9){
    cout << "This should not happen return -1" << endl;
    return -1;
  }
  return b+1;//TTZ file has preselection as bin 1
}

//root [0] RooStats::PValueToSignificance(0.0762011)
//(Double_t) 1.431098e+00
//root [1] RooStats::SignificanceToPValue(1.4311)
//(Double_t) 7.620078e-02
