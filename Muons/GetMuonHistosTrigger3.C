// Usage:
// > root -b doAll.C

// C++
#include <sstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TH2F.h"

// CMS3
//#include "CMS3_v003.cc"
#include "CMS3.cc"
#include "/home/users/haweber/Software/makeCMS3ClassFiles/vecUtils.h"
#include "/home/users/haweber/Tools/goodrun.h"
#include "/home/users/haweber/Tools/goodrun.cc"

#include "LoadStruct.h"

using namespace std;
using namespace tas;

bool SortPrintOut(myevt const& lhs, myevt const& rhs) {
    if (lhs.evt_run != rhs.evt_run)
        return lhs.evt_run < rhs.evt_run;
    if (lhs.evt_lumiBlock != rhs.evt_lumiBlock)
        return lhs.evt_lumiBlock < rhs.evt_lumiBlock;
    return lhs.evt_event < rhs.evt_event;
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  vector<myevt> pop; pop.clear();
  vector<myevt> pot; pot.clear();
  
  int currentrun = -1;
  bool DCSonly = false;//KEEP THIS FALSE!!!!
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  bool printlogstream = true;
  std::ostringstream* fLogStream     = 0;
  fLogStream = new std::ostringstream();

  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();

  map<string, TH2F*> histos2D;
  vector<string> histonames2D; histonames2D.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();
  //histonames.push_back("Trigger__Mu50Tag_Pt");                   if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  //histonames.push_back("Trigger__Mu50Probe_Pt");                 if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_IsoMu27Tag_Pt");                 if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_IsoMu27Probe_Pt");               if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_IsoMu27Tag_Eta");                hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu27Probe_Eta");              hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu27Tag_RelIso03");           hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Probe_RelIso03");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Tag_RelIso03EA");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Probe_RelIso03EA");       hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Tag_RelIso03DB");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Probe_RelIso03DB");       hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Tag_miniiso");            hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Probe_miniiso");          hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Tag_miniisoDB");          hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu27Probe_miniisoDB");        hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Tag_Pt");                 if(DCSonly) hbins.push_back(30); else hbins.push_back(15); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoMu20Probe_Pt");               if(DCSonly) hbins.push_back(30); else hbins.push_back(15); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoMu20Tag_Eta");                hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu20Probe_Eta");              hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu20Tag_RelIso03");           hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Probe_RelIso03");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Tag_RelIso03EA");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Probe_RelIso03EA");       hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Tag_RelIso03DB");         hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Probe_RelIso03DB");       hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Tag_miniiso");            hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Probe_miniiso");          hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Tag_miniisoDB");          hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu20Probe_miniisoDB");        hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  //histonames.push_back("Trigger__Mu45eta2p1Tag_Pt");             if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  //histonames.push_back("Trigger__Mu45eta2p1Probe_Pt");           if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_Pt");           if(DCSonly) hbins.push_back(44); else hbins.push_back(22); hlow.push_back( 18); hup.push_back(40);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_Pt");         if(DCSonly) hbins.push_back(44); else hbins.push_back(22); hlow.push_back( 18); hup.push_back(40);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_Eta");          hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_Eta");        hbins.push_back(25); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03");     hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03");   hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03EA");   hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03EA"); hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03DB");   hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03DB"); hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_miniiso");      hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_miniiso");    hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Tag_miniisoDB");    hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_IsoMu24eta2p1Probe_miniisoDB");  hbins.push_back(13); hlow.push_back(  0); hup.push_back(0.52);
  histonames.push_back("Trigger_DiMuTag_LeadPt");                if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 10); hup.push_back(30);
  histonames.push_back("Trigger_DiMuProbe_LeadPt");              if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 10); hup.push_back(30);
  histonames.push_back("Trigger_DiMuTag_TrailPt");               if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back(  0); hup.push_back(20);
  histonames.push_back("Trigger_DiMuProbe_TrailPt");             if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back(  0); hup.push_back(20);

  histonames.push_back("Trigger_PureIsoMu20Tag_Pt");    if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_PureIsoMu20Probe_Pt");  if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_PureIsoMu20Tag_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu20Probe_Eta"); hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu20Tag_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu20Probe_Phi"); hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu20Tag_Pt");      if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoTkMu20Probe_Pt");    if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoTkMu20Tag_Eta");     hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu20Probe_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu20Tag_Phi");     hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu20Probe_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu20Tag_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Probe_RelIso03");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Tag_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Probe_RelIso03DB");     hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Tag_RelIso03");           hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Probe_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Tag_RelIso03DB");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Probe_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);

  histonames.push_back("Trigger_PureIsoMu20Tag_Pt_etarestrict");    if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_PureIsoMu20Probe_Pt_etarestrict");  if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_PureIsoMu20Tag_Phi_etarestrict");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu20Probe_Phi_etarestrict"); hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu20Tag_Pt_etarestrict");      if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoTkMu20Probe_Pt_etarestrict");    if(DCSonly) hbins.push_back(60); else hbins.push_back(30); hlow.push_back( 15); hup.push_back(30);
  histonames.push_back("Trigger_IsoTkMu20Tag_Phi_etarestrict");     hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu20Probe_Phi_etarestrict");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu20Tag_RelIso03_etarestrict");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Probe_RelIso03_etarestrict");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Tag_RelIso03_etarestrict");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Probe_RelIso03_etarestrict");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Tag_RelIso03DB_etarestrict");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu20Probe_RelIso03DB_etarestrict");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Tag_RelIso03DB_etarestrict");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu20Probe_RelIso03DB_etarestrict");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  
  histonames.push_back("Trigger_PureIsoMu27Tag_Pt");    if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_PureIsoMu27Probe_Pt");  if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_PureIsoMu27Tag_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu27Probe_Eta"); hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu27Tag_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu27Probe_Phi"); hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu27Tag_Pt");      if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_IsoTkMu27Probe_Pt");    if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_IsoTkMu27Tag_Eta");     hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu27Probe_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu27Tag_Phi");     hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu27Probe_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu27Tag_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu27Probe_RelIso03");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu27Tag_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu27Probe_RelIso03DB");     hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu27Tag_RelIso03");           hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu27Probe_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu27Tag_RelIso03DB");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu27Probe_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  
  histonames.push_back("Trigger_PureIsoMu24eta2p1Tag_Pt");    if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Probe_Pt");  if(DCSonly) hbins.push_back(40); else hbins.push_back(20); hlow.push_back( 20); hup.push_back(40);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Tag_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Probe_Eta"); hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Tag_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Probe_Phi"); hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Tag_Pt");      if(DCSonly) hbins.push_back(88); else hbins.push_back(44); hlow.push_back( 18); hup.push_back(40);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Probe_Pt");    if(DCSonly) hbins.push_back(88); else hbins.push_back(44); hlow.push_back( 18); hup.push_back(40);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Tag_Eta");     hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Probe_Eta");   hbins.push_back(75); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Tag_Phi");     hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Probe_Phi");   hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Tag_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Probe_RelIso03");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Tag_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_PureIsoMu24eta2p1Probe_RelIso03DB");     hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Tag_RelIso03");           hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Probe_RelIso03");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Tag_RelIso03DB");         hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_IsoTkMu24eta2p1Probe_RelIso03DB");       hbins.push_back(25); hlow.push_back(  0); hup.push_back(0.5);

  histonames.push_back("Trigger_Mu50Tag_Pt");                    if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_Mu50Probe_Pt");                  if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_Mu50Tag_Eta");                   hbins.push_back(50); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_Mu50Probe_Eta");                 hbins.push_back(50); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_Mu50Tag_Phi");                   hbins.push_back(48); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_Mu50Probe_Phi");                 hbins.push_back(48); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_Mu50Tag_RelIso03");              hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu50Probe_RelIso03");            hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu50Tag_RelIso03DB");            hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu50Probe_RelIso03DB");          hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu45eta2p1Tag_Pt");              if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_Mu45eta2p1Probe_Pt");            if(DCSonly) hbins.push_back(80); else hbins.push_back(40); hlow.push_back( 35); hup.push_back(75);
  histonames.push_back("Trigger_Mu45eta2p1Tag_Eta");             hbins.push_back(50); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_Mu45eta2p1Probe_Eta");           hbins.push_back(50); hlow.push_back(-2.5); hup.push_back(2.5);
  histonames.push_back("Trigger_Mu45eta2p1Tag_Phi");             hbins.push_back(48); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_Mu45eta2p1Probe_Phi");           hbins.push_back(48); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("Trigger_Mu45eta2p1Tag_RelIso03");        hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu45eta2p1Probe_RelIso03");      hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu45eta2p1Tag_RelIso03DB");      hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);
  histonames.push_back("Trigger_Mu45eta2p1Probe_RelIso03DB");    hbins.push_back(20); hlow.push_back(  0); hup.push_back(0.5);

  histonames2D.push_back("Trigger_PureIsoMu20Tag_EtavsPhi");
  histonames2D.push_back("Trigger_PureIsoMu20Probe_EtavsPhi");
  histonames2D.push_back("Trigger_IsoTkMu20Tag_EtavsPhi");
  histonames2D.push_back("Trigger_IsoTkMu20Probe_EtavsPhi");
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    int nbins = hbins[i];
    string mapname;
    for(unsigned int j = 0; j<7;++j){
      string prefix = "";
      if(j==1) prefix = "Run251244_";
      else if(j==2) prefix = "Run251251_";
      else if(j==3) prefix = "Run251252_";
      else if(j==4) prefix = "RunPre251561_";
      else if(j==5) prefix = "RunAllPre251561_";      
      else if(j>=6) prefix = "RunAfter251561_";      
      mapname = prefix + histonames[i]+"_"+skimFilePrefix;
      //cout << mapname << endl;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", nbins, hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }
  }
  for(unsigned int i = 0; i<histonames2D.size(); ++i){
    string mapname;
    for(unsigned int j = 0; j<7;++j){
      string prefix = "";
      if(j==1) prefix = "Run251244_";
      else if(j==2) prefix = "Run251251_";
      else if(j==3) prefix = "Run251252_";
      else if(j==4) prefix = "RunPre251561_";
      else if(j==5) prefix = "RunAllPre251561_";      
      else if(j>=6) prefix = "RunAfter251561_";      
      mapname = prefix + histonames2D[i]+"_"+skimFilePrefix;
      //cout << mapname << endl;
      if(histos2D.count(mapname) == 0 ) histos2D[mapname] = new TH2F(mapname.c_str(), "", 48, -2.4, 2.4, 64, -3.2, 3.2);
      histos2D[mapname]->Sumw2(); histos2D[mapname]->SetDirectory(rootdir);
    }
  }

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  //load json file
  const char* json_fileDCS = "myjsons/json_DCSONLY_Run2015B_snt.txt";
  const char* json_file = "myjsons/json_Golden_246908-251883_snt.txt";
  if(DCSonly) set_goodrun_file(json_fileDCS);
  else        set_goodrun_file(json_file);

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("t");
    if(fast) TTreeCache::SetLearnEntries(10);
    if(fast) tree->SetCacheSize(128*1024*1024);
    cms3.Init(tree);

    myevt p;//previous event
    myevt c;//current event

    resetEvent(p);
    resetEvent(c);
    vector<myevt> evt; evt.clear();

    // Loop over Events in current file
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
    
      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
    
      // Progress
      CMS3::progress(nEventsTotal, nEventsChain );
      if((evt_isRealData()&& !goodrun(evt_run(), evt_lumiBlock())) ||(((nEventsChain==nEventsTotal)) && evt.size()>=2)) continue;
      //if(evt_run()==251168) continue;

      //load my struct
      c.evt_pfmet   = evt_pfmet();
      c.evt_pfmetPhi   = evt_pfmetPhi();
      c.evt_trackmet   = evt_trackmet();
      c.evt_trackmetPhi   = evt_trackmetPhi();
      c.evt_pfsumet   = evt_pfsumet();
      c.evt_pfmetSig   = evt_pfmetSig();
      c.evt_event   = evt_event();
      c.evt_lumiBlock   = evt_lumiBlock();
      c.evt_run   = evt_run();
      c.filt_csc   = filt_csc();
      c.filt_hbhe   = filt_hbhe();
      c.filt_hcallaser   = filt_hcallaser();
      c.filt_ecaltp   = filt_ecaltp();
      c.filt_trkfail   = filt_trkfail();
      c.filt_eebadsc   = filt_eebadsc();
      c.evt_isRealData   = evt_isRealData(); 
      c.scale1fb   = scale1fb();
      c.evt_xsec_incl   = evt_xsec_incl();
      c.evt_kfactor   = evt_kfactor();
      c.gen_met   = gen_met();
      c.gen_metPhi   = gen_metPhi();
      c.njets   = njets();
      c.ht   = ht();
      c.jets  = jets();
      c.jets_disc  = jets_disc();
      c.sample  = sample();
      c.nvtx   = nvtx();
      c.HLT_Mu8_TrkIsoVVL   = HLT_Mu8_TrkIsoVVL();
      c.HLT_Mu17_TrkIsoVVL   = HLT_Mu17_TrkIsoVVL();
      c.HLT_Mu24_TrkIsoVVL   = HLT_Mu24_TrkIsoVVL();
      c.HLT_Mu34_TrkIsoVVL   = HLT_Mu34_TrkIsoVVL();
      c.HLT_Mu8   = HLT_Mu8();
      c.HLT_Mu17   = HLT_Mu17();
      c.HLT_Mu24   = HLT_Mu24();
      c.HLT_Mu34   = HLT_Mu34();
      c.HLT_Mu10_CentralPFJet30_BTagCSV0p5PF   = HLT_Mu10_CentralPFJet30_BTagCSV0p5PF();
      c.HLT_IsoMu24_eta2p1   = HLT_IsoMu24_eta2p1();
      c.HLT_IsoTkMu24_eta2p1   = HLT_IsoTkMu24_eta2p1(); 
      c.HLT_IsoMu27   = HLT_IsoMu27();
      c.HLT_IsoTkMu27   = HLT_IsoTkMu27(); 
      c.HLT_Mu45_eta2p1   = HLT_Mu45_eta2p1(); 
      c.HLT_Mu50   = HLT_Mu50();
      c.HLT_Ele8_CaloIdM_TrackIdM_PFJet30   = HLT_Ele8_CaloIdM_TrackIdM_PFJet30();
      c.HLT_Ele12_CaloIdM_TrackIdM_PFJet30   = HLT_Ele12_CaloIdM_TrackIdM_PFJet30();
      c.HLT_Ele18_CaloIdM_TrackIdM_PFJet30   = HLT_Ele18_CaloIdM_TrackIdM_PFJet30();
      c.HLT_Ele23_CaloIdM_TrackIdM_PFJet30   = HLT_Ele23_CaloIdM_TrackIdM_PFJet30();
      c.HLT_Ele33_CaloIdM_TrackIdM_PFJet30   = HLT_Ele33_CaloIdM_TrackIdM_PFJet30();
      c.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30   = HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30();
      c.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30   = HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30();
      c.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30   = HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30();
      c.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30   = HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30();
      c.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF   = HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF();
      c.HLT_Ele27_eta2p1_WP75_Gsf   = HLT_Ele27_eta2p1_WP75_Gsf();
      c.HLT_Ele27_WP85_Gsf   = HLT_Ele27_WP85_Gsf();
      c.HLT_Ele27_eta2p1_WPLoose_Gsf   = HLT_Ele27_eta2p1_WPLoose_Gsf();
      c.HLT_Ele27_eta2p1_WPTight_Gsf   = HLT_Ele27_eta2p1_WPTight_Gsf();
      c.HLT_Ele32_eta2p1_WP75_Gsf   = HLT_Ele32_eta2p1_WP75_Gsf();
      c.HLT_Ele32_eta2p1_WPLoose_Gsf   = HLT_Ele32_eta2p1_WPLoose_Gsf();
      c.HLT_Ele32_eta2p1_WPTight_Gsf   = HLT_Ele32_eta2p1_WPTight_Gsf();
      c.HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300   = HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300();
      c.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL   = HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
      c.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL   = HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
      c.HLT_DoubleMu8_Mass8_PFHT300   = HLT_DoubleMu8_Mass8_PFHT300();
      c.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL   = HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
      c.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL   = HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL(); 
      c.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ   = HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
      c.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ   = HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ(); 
      c.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300   = HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300();
      c.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ   = HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
      c.pid_PFMuon   = pid_PFMuon();
      c.gfit_chi2   = gfit_chi2();
      c.gfit_ndof   = gfit_ndof();
      c.gfit_validSTAHits   = gfit_validSTAHits();
      c.numberOfMatchedStations   = numberOfMatchedStations();
      c.validPixelHits   = validPixelHits();
      c.nlayers   = nlayers();
      c.chi2LocalPosition   = chi2LocalPosition();
      c.trkKink   = trkKink();
      c.validHits   = validHits(); 
      c.lostHits   = lostHits();
      c.exp_outerlayers   = exp_outerlayers();
      c.segmCompatibility   = segmCompatibility();
      c.exp_innerlayers   = exp_innerlayers();
      c.passes_POG_vetoID   = passes_POG_vetoID();
      c.passes_POG_looseID   = passes_POG_looseID();
      c.passes_POG_mediumID   = passes_POG_mediumID();
      c.passes_POG_tightID   = passes_POG_tightID();
      c.ip3d   = ip3d();
      c.ip3derr   = ip3derr(); 
      c.type   = type();
      c.mt   = mt();
      c.ptrelv0   = ptrelv0();
      c.ptrelv1   = ptrelv1();
      c.miniiso   = miniiso();
      c.miniisoDB   = miniisoDB(); 
      c.reliso04   = reliso04();
      c.annulus04   = annulus04();
      c.p4  = p4();
      c.tag_p4  = tag_p4();
      c.dilep_p4  = dilep_p4();
      c.mc_p4  = mc_p4();
      c.mc_motherp4  = mc_motherp4();
      c.id   = id();
      c.idx   = idx();
      c.dxyPV   = dxyPV();
      c.dZ   = dZ();
      c.dxyPV_err   = dxyPV_err();
      c.motherID   = motherID();
      c.mc_id   = mc_id();
      c.RelIso03   = RelIso03();
      c.RelIso03EA   = RelIso03EA();
      c.RelIso03DB   = RelIso03DB();
      c.HLT_IsoMu20   = HLT_IsoMu20();
      c.HLT_IsoTkMu20   = HLT_IsoTkMu20();
      c.iso03sumPt = iso03sumPt();
      c.iso03emEt = iso03emEt();
      c.iso03hadEt = iso03hadEt();
      c.tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg();
      c.tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg();
      c.tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg();
      c.tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg();
      c.probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg();
      c.probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg();
      c.probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg();
      c.probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg();

      float weight = p.scale1fb*0.0403;
      if(skimFilePrefix=="DY_M10_50ns") //weight *= 1.11;
      if(p.evt_isRealData) weight = 1.;
      // Analysis Code
      weight = 1;

      int nleps = 1;
      if(sameEvent(p,c)) { ++nleps; }

      if(((!sameEvent(p,c))||(nEventsChain==nEventsTotal)) && evt.size()>=2) {
	string prefix = "";
	if(p.evt_run == 251244) prefix = "Run251244_";
	else if(p.evt_run == 251251) prefix = "Run251251_";
	else if(p.evt_run == 251252) prefix = "Run251252_";
	else if(p.evt_run <= 251561) prefix = "RunPre251561_";
	else prefix = "RunAfter251561_";
	if(prefix=="RunPre251561_" && p.evt_run != 251561) cout << prefix << "   " << p.evt_run << endl;
	vector<int> tagv;
	vector<int> probev;
	//int tag = -1;
	//int probe = -1;
	for(unsigned int i = 0; i<evt.size();++i){
	  if(evt[i].evt_run!=p.evt_run) cout << " " << evt[i].evt_run << "   " << p.evt_run << endl;
	  if(/*evt[i].passes_SS_tight_v3 &&*/ passTightID(evt[i]) && abs(evt[i].id)==13&&evt[i].p4.Pt()>25&&fabs(evt[i].p4.Eta())<2.4&&evt[i].RelIso03<0.12&&
	     (evt[i].HLT_IsoMu20==1||evt[i].HLT_IsoTkMu20==1)) { tagv.push_back(i); }
	}
	for(unsigned int i = 0; i<evt.size();++i){
	  if(passTightID(evt[i]) && abs(evt[i].id)==13&&fabs(evt[i].p4.Eta())<2.4/*&&evt[i].RelIso03<0.12*/) {probev.push_back(i); }
	}
	float Zmass = -1;
	//cout << __LINE__ << " tag " << tag << " probe " << probe << endl;
    for(unsigned int i = 0; i<tagv.size(); ++i){
      for(unsigned int j = 0; j<probev.size(); ++j){
	int tag = tagv[i];
	int probe = probev[j];
	if(tag==probe) continue;
	if(tag>=0&&probe>=0&&tag!=probe) Zmass = (evt[tag].p4+evt[probe].p4).M();
	if(tag>=0&&probe>=0&&evt[probe].RelIso03<0.12&&Zmass>75.&&Zmass<105.){
	  histos[prefix+"Trigger_IsoMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos[prefix+"Trigger_IsoMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	  }
	  histos["Trigger_IsoMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos["Trigger_IsoMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	  }
	  histos[prefix+"Trigger_PureIsoMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos[prefix+"Trigger_PureIsoMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos[prefix+"Trigger_PureIsoMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos["Trigger_PureIsoMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos["Trigger_PureIsoMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos["Trigger_PureIsoMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos[prefix+"Trigger_IsoTkMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos[prefix+"Trigger_IsoTkMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos[prefix+"Trigger_IsoTkMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos["Trigger_IsoTkMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>24){
	    histos["Trigger_IsoTkMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos["Trigger_IsoTkMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);// XXX - make versions without prefix like this one
	  }
	  if(p.evt_run <= 251561){
	    histos["RunAllPre251561_Trigger_IsoTkMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>24){
	      histos["RunAllPre251561_Trigger_IsoTkMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos["RunAllPre251561_Trigger_IsoTkMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    histos["RunAllPre251561_Trigger_PureIsoMu20Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>24){
	      histos["RunAllPre251561_Trigger_PureIsoMu20Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos["RunAllPre251561_Trigger_PureIsoMu20Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	  }
	  if(evt[probe].p4.Eta()>(-0.4)&&evt[probe].p4.Eta()<0.){
	    histos[prefix+"Trigger_PureIsoMu20Tag_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    histos["Trigger_PureIsoMu20Tag_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    histos[prefix+"Trigger_IsoTkMu20Tag_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    histos["Trigger_IsoTkMu20Tag_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_Pt_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>24){
	      histos[prefix+"Trigger_PureIsoMu20Tag_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      histos["Trigger_PureIsoMu20Tag_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      histos[prefix+"Trigger_IsoTkMu20Tag_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      histos["Trigger_IsoTkMu20Tag_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_Phi_etarestrict_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      else if(p.evt_run>251561) {
		if(p.evt_run!=evt[probe].evt_run) cout << "ERROR1" << endl;
		if(p.evt_lumiBlock!=evt[probe].evt_lumiBlock) cout << "ERROR2" << endl;
		if(p.evt_event!=evt[probe].evt_event) cout << "ERROR3" << endl;
		pop.push_back(evt[probe]);
		pot.push_back(evt[tag]);
		//*fLogStream << "run:LS:evt " << evt[probe].evt_run << ":" << evt[probe].evt_lumiBlock << ":" << evt[probe].evt_event << "             (HLT_IsoTkMu20 match " << evt[probe].HLT_IsoTkMu20 << ")" << ": muon pt/eta/phi " << evt[probe].p4.Pt() << "/" << evt[probe].p4.Eta() << "/" << evt[probe].p4.Phi() << " (tag muon " << evt[tag].p4.Pt() << "/" << evt[tag].p4.Eta() << "/" << evt[tag].p4.Phi() << " match IsoTkMu20 " << evt[tag].HLT_IsoTkMu20 << " IsoMu20 " << evt[tag].HLT_IsoMu20 << ")" << endl;
	      }
	    }
	  }
	  if(evt[probe].p4.Pt()>24){
	    histos2D[prefix+"Trigger_PureIsoMu20Tag_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    histos2D["Trigger_PureIsoMu20Tag_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoMu20==1){
	      histos2D[prefix+"Trigger_PureIsoMu20Probe_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	      histos2D["Trigger_PureIsoMu20Probe_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    }
	    histos2D[prefix+"Trigger_IsoTkMu20Tag_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    histos2D["Trigger_IsoTkMu20Tag_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoTkMu20==1){
	      histos2D[prefix+"Trigger_IsoTkMu20Probe_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	      histos2D["Trigger_IsoTkMu20Probe_EtavsPhi_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),evt[probe].p4.Phi(),weight);
	    }
	  }
	  
	  histos[prefix+"Trigger_IsoMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos[prefix+"Trigger_IsoMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	  }
	  histos[prefix+"Trigger_PureIsoMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu27==1) histos[prefix+"Trigger_PureIsoMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos[prefix+"Trigger_PureIsoMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu27==1) histos[prefix+"Trigger_PureIsoMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos[prefix+"Trigger_PureIsoMu27Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoMu27==1) histos[prefix+"Trigger_PureIsoMu27Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos[prefix+"Trigger_IsoTkMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoTkMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos[prefix+"Trigger_IsoTkMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoTkMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos[prefix+"Trigger_IsoTkMu27Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoTkMu27Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos["Trigger_IsoMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos["Trigger_IsoMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	  }
	  histos["Trigger_PureIsoMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoMu27==1) histos["Trigger_PureIsoMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos["Trigger_PureIsoMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoMu27==1) histos["Trigger_PureIsoMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos["Trigger_PureIsoMu27Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoMu27==1) histos["Trigger_PureIsoMu27Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos["Trigger_IsoTkMu27Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoTkMu27Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>31){
	    histos["Trigger_IsoTkMu27Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoTkMu27Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos["Trigger_IsoTkMu27Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoTkMu27Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  //histos[prefix+"Trigger__Mu50Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  //if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger__Mu50Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  histos[prefix+"Trigger_Mu50Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger_Mu50Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>54){
	    histos[prefix+"Trigger_Mu50Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger_Mu50Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos[prefix+"Trigger_Mu50Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger_Mu50Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  histos["Trigger_Mu50Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].HLT_Mu50==1) histos["Trigger_Mu50Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].p4.Pt()>54){
	    histos["Trigger_Mu50Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    if(evt[probe].HLT_Mu50==1) histos["Trigger_Mu50Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    histos["Trigger_Mu50Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    if(evt[probe].HLT_Mu50==1) histos["Trigger_Mu50Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	  }
	  if(fabs(evt[probe].p4.Eta())<2.1){
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos[prefix+"Trigger_IsoMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    }
	    histos[prefix+"Trigger_PureIsoMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos[prefix+"Trigger_PureIsoMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos[prefix+"Trigger_PureIsoMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1) histos[prefix+"Trigger_PureIsoMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos[prefix+"Trigger_PureIsoMu24eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1) histos[prefix+"Trigger_PureIsoMu24eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    histos[prefix+"Trigger_IsoTkMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoTkMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos[prefix+"Trigger_IsoTkMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoTkMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos[prefix+"Trigger_IsoTkMu24eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoTkMu24eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    histos["Trigger_IsoMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos["Trigger_IsoMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	    }
	    histos["Trigger_PureIsoMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos["Trigger_PureIsoMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos["Trigger_PureIsoMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1) histos["Trigger_PureIsoMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos["Trigger_PureIsoMu24eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoMu24_eta2p1==1) histos["Trigger_PureIsoMu24eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    histos["Trigger_IsoTkMu24eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoTkMu24eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>28){
	      histos["Trigger_IsoTkMu24eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoTkMu24eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos["Trigger_IsoTkMu24eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoTkMu24eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    //histos[prefix+"Trigger__Mu45eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    //if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger__Mu45eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    histos[prefix+"Trigger_Mu45eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger_Mu45eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>49){
	      histos[prefix+"Trigger_Mu45eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger_Mu45eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos[prefix+"Trigger_Mu45eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger_Mu45eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	    histos["Trigger_Mu45eta2p1Tag_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos["Trigger_Mu45eta2p1Probe_Pt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	    if(evt[probe].p4.Pt()>49){
	      histos["Trigger_Mu45eta2p1Tag_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      if(evt[probe].HLT_Mu45_eta2p1==1) histos["Trigger_Mu45eta2p1Probe_Eta_"+skimFilePrefix]->Fill(evt[probe].p4.Eta(),weight);
	      histos["Trigger_Mu45eta2p1Tag_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	      if(evt[probe].HLT_Mu45_eta2p1==1) histos["Trigger_Mu45eta2p1Probe_Phi_"+skimFilePrefix]->Fill(evt[probe].p4.Phi(),weight);
	    }
	  }
	}
	if(tag>=0&&probe>=0&&Zmass>75.&&Zmass<105.){
	  if(evt[probe].p4.Pt()>24){
	    histos[prefix+"Trigger_IsoMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoMu20Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos[prefix+"Trigger_IsoMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoMu20Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos[prefix+"Trigger_IsoMu20Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoMu20Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos[prefix+"Trigger_PureIsoMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_PureIsoMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoTkMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoTkMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoMu20Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos["Trigger_IsoMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu20Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos["Trigger_IsoMu20Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu20==1||evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoMu20Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos["Trigger_PureIsoMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_PureIsoMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoTkMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoTkMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(p.evt_run <= 251561){
	      histos["RunAllPre251561_Trigger_PureIsoMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos["RunAllPre251561_Trigger_PureIsoMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      histos["RunAllPre251561_Trigger_IsoTkMu20Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos["RunAllPre251561_Trigger_IsoTkMu20Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    }
	    if(evt[probe].p4.Eta()>(-0.4)&&evt[probe].p4.Eta()<0.){
	      histos[prefix+"Trigger_PureIsoMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos[prefix+"Trigger_PureIsoMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos[prefix+"Trigger_PureIsoMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      histos[prefix+"Trigger_IsoTkMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos[prefix+"Trigger_IsoTkMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos[prefix+"Trigger_IsoTkMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      histos["Trigger_PureIsoMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos["Trigger_PureIsoMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoMu20==1) histos["Trigger_PureIsoMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      histos["Trigger_IsoTkMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	      histos["Trigger_IsoTkMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(evt[probe].HLT_IsoTkMu20==1) histos["Trigger_IsoTkMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      if(p.evt_run <= 251561){
		histos["RunAllPre251561_Trigger_PureIsoMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
		if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
		histos["RunAllPre251561_Trigger_PureIsoMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
		if(evt[probe].HLT_IsoMu20==1) histos["RunAllPre251561_Trigger_PureIsoMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
		histos["RunAllPre251561_Trigger_IsoTkMu20Tag_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
		if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_RelIso03_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
		histos["RunAllPre251561_Trigger_IsoTkMu20Tag_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
		if(evt[probe].HLT_IsoTkMu20==1) histos["RunAllPre251561_Trigger_IsoTkMu20Probe_RelIso03DB_etarestrict_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	      }
	    }
	  }
	  if(evt[probe].p4.Pt()>31){
	    histos[prefix+"Trigger_IsoMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoMu27Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos[prefix+"Trigger_IsoMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoMu27Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos[prefix+"Trigger_IsoMu27Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoMu27Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos[prefix+"Trigger_PureIsoMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu27==1) histos[prefix+"Trigger_PureIsoMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_PureIsoMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu27==1) histos[prefix+"Trigger_PureIsoMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoTkMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoTkMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoTkMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos[prefix+"Trigger_IsoTkMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoMu27Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos["Trigger_IsoMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu27Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos["Trigger_IsoMu27Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu27==1||evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoMu27Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos["Trigger_PureIsoMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu27==1) histos["Trigger_PureIsoMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_PureIsoMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu27==1) histos["Trigger_PureIsoMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoTkMu27Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoTkMu27Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoTkMu27Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu27==1) histos["Trigger_IsoTkMu27Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	  }
	  if(fabs(evt[probe].p4.Eta())<2.1&&evt[probe].p4.Pt()>28){
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos[prefix+"Trigger_IsoMu24eta2p1Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoMu24eta2p1Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos[prefix+"Trigger_PureIsoMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos[prefix+"Trigger_PureIsoMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_PureIsoMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos[prefix+"Trigger_PureIsoMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos[prefix+"Trigger_IsoTkMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoTkMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_IsoTkMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos[prefix+"Trigger_IsoTkMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoMu24eta2p1Tag_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_RelIso03EA_"+skimFilePrefix]->Fill(evt[probe].RelIso03EA,weight);
	    histos["Trigger_IsoMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoMu24eta2p1Tag_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_miniiso_"+skimFilePrefix]->Fill(evt[probe].miniiso,weight);
	    histos["Trigger_IsoMu24eta2p1Tag_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1 || evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoMu24eta2p1Probe_miniisoDB_"+skimFilePrefix]->Fill(evt[probe].miniisoDB,weight);
	    histos["Trigger_PureIsoMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos["Trigger_PureIsoMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_PureIsoMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoMu24_eta2p1==1) histos["Trigger_PureIsoMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_IsoTkMu24eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoTkMu24eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_IsoTkMu24eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_IsoTkMu24_eta2p1==1) histos["Trigger_IsoTkMu24eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	  }
	  if(evt[probe].p4.Pt()>54){
	    histos[prefix+"Trigger_Mu50Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger_Mu50Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_Mu50Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_Mu50==1) histos[prefix+"Trigger_Mu50Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_Mu50Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_Mu50==1) histos["Trigger_Mu50Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_Mu50Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_Mu50==1) histos["Trigger_Mu50Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	  }
	  if(fabs(evt[probe].p4.Eta())<2.1&&evt[probe].p4.Pt()>49){
	    histos[prefix+"Trigger_Mu45eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger_Mu45eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos[prefix+"Trigger_Mu45eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos[prefix+"Trigger_Mu45eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    histos["Trigger_Mu45eta2p1Tag_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos["Trigger_Mu45eta2p1Probe_RelIso03_"+skimFilePrefix]->Fill(evt[probe].RelIso03,weight);
	    histos["Trigger_Mu45eta2p1Tag_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	    if(evt[probe].HLT_Mu45_eta2p1==1) histos["Trigger_Mu45eta2p1Probe_RelIso03DB_"+skimFilePrefix]->Fill(evt[probe].RelIso03DB,weight);
	  }
	}
      }}
    tagv.clear();
    probev.clear();
	for(unsigned int i = 0; i<evt.size();++i){
	  if(/*evt[i].passes_SS_tight_v3 &&*/ passTightID(evt[i]) && abs(evt[i].id)==13&&evt[i].p4.Pt()>25&&fabs(evt[i].p4.Eta())<2.4&&evt[i].RelIso03<0.12&&
	     (evt[i].HLT_IsoMu27==1||evt[i].HLT_IsoTkMu27==1)&&
	     (evt[i].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg==1||evt[i].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg==1)) { tagv.push_back(i); }
	}
	for(unsigned int i = 0; i<evt.size();++i){
	  if(passTightID(evt[i]) && abs(evt[i].id)==13&&fabs(evt[i].p4.Eta())<2.4/*&&evt[i].RelIso03<0.12*/) { probev.push_back(i); }
	}
      for(unsigned int i = 0; i<tagv.size(); ++i){
      for(unsigned int j = 0; j<probev.size(); ++j){
	int tag = tagv[i];
	int probe = probev[j];
	if(tag==probe) continue;
	if(tag>=0&&probe>=0&&tag!=probe) Zmass = (evt[tag].p4+evt[probe].p4).M();
	if(tag>=0&&probe>=0&&evt[probe].RelIso03<0.12&&Zmass>75.&&Zmass<105.){
	  histos[prefix+"Trigger_DiMuTag_TrailPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg==1||evt[probe].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg==1) histos[prefix+"Trigger_DiMuProbe_TrailPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  histos["Trigger_DiMuTag_TrailPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg==1||evt[probe].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg==1) histos["Trigger_DiMuProbe_TrailPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	}
      }}
      tagv.clear();
    probev.clear();
	for(unsigned int i = 0; i<evt.size();++i){
	  if(/*evt[i].passes_SS_tight_v3 &&*/ passTightID(evt[i]) && abs(evt[i].id)==13&&evt[i].p4.Pt()>25&&fabs(evt[i].p4.Eta())<2.4&&evt[i].RelIso03<0.12&&
	     (evt[i].HLT_IsoMu27==1||evt[i].HLT_IsoTkMu27==1)&&
	     (evt[i].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg==1||evt[i].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg==1)) { tagv.push_back(i); }
	}
	for(unsigned int i = 0; i<evt.size();++i){
	  if(passTightID(evt[i]) && abs(evt[i].id)==13&&fabs(evt[i].p4.Eta())<2.4/*&&evt[i].RelIso03<0.12*/) { probev.push_back(i); }
	}
      for(unsigned int i = 0; i<tagv.size(); ++i){
      for(unsigned int j = 0; j<probev.size(); ++j){
	int tag = tagv[i];
	int probe = probev[j];
	if(tag==probe) continue;
	if(tag>=0&&probe>=0&&tag!=probe) Zmass = (evt[tag].p4+evt[probe].p4).M();
	if(tag>=0&&probe>=0&&evt[probe].RelIso03<0.12&&Zmass>75.&&Zmass<105.){
	  histos[prefix+"Trigger_DiMuTag_LeadPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg==1||evt[probe].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg==1) histos[prefix+"Trigger_DiMuProbe_LeadPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  histos["Trigger_DiMuTag_LeadPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	  if(evt[probe].probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg==1||evt[probe].probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg==1) histos["Trigger_DiMuProbe_LeadPt_"+skimFilePrefix]->Fill(evt[probe].p4.Pt(),weight);
	}
      }}
      }
      if(!sameEvent(p,c)){
	//finally start new event.
	evt.clear();
      }
      if(currentrun!=c.evt_run) { cout << "This is run " << c.evt_run << endl; currentrun = c.evt_run; }
      bool skip = false;
      //if(c.evt_run!=251244&&c.evt_run!=251251&&c.evt_run!=251252) skip = true;
      if(abs(c.id)!=13) skip = true;
      else if(c.p4.Pt()<10.) skip = true;
      else if(fabs(c.p4.Eta())>2.4) skip = true;
      else if(fabs(c.dZ)>0.5) skip = true;
      else if(fabs(c.dxyPV)>0.2) skip = true;
      if(!skip) evt.push_back(c);

      p = c;
      resetEvent(c);
    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  std::sort(pop.begin(), pop.end(), &SortPrintOut);
  std::sort(pot.begin(), pot.end(), &SortPrintOut);
  for(unsigned int p = 0; p<pop.size();++p){
    *fLogStream << "run:LS:evt " << pop[p].evt_run << ":" << pop[p].evt_lumiBlock << ":" << pop[p].evt_event << "             (HLT_IsoTkMu20 match " << pop[p].HLT_IsoTkMu20 << ")" << ": muon pt/eta/phi " << pop[p].p4.Pt() << "/" << pop[p].p4.Eta() << "/" << pop[p].p4.Phi() << " (tag muon " << pot[p].p4.Pt() << "/" << pot[p].p4.Eta() << "/" << pot[p].p4.Phi() << " match IsoTkMu20 " << pot[p].HLT_IsoTkMu20 << " IsoMu20 " << pot[p].HLT_IsoMu20 << ")" << endl;
  }

  if(printlogstream) cout << fLogStream->str();

  
  // Example Histograms
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
  }
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    h->second->SetBinContent(1, h->second->GetBinContent(1 )+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1 ),2)+pow(h->second->GetBinError(0),2) ) );
  }
  //string filename = "rootfiles/test/Histos_"+skimFilePrefix+".root";
  string filename = "rootfiles/first_20150727/Histos3Trigger_"+skimFilePrefix+".root";
  if(DCSonly) filename = "rootfiles/first_20150727/Histos3TriggerDCS_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  for(map<string,TH2F*>::iterator h=  histos2D.begin(); h!=  histos2D.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;  
  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}
