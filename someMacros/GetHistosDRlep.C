// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>
#include <map>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

// CMS3
#include "CMS3.cc"

//MT2 variants
//#include "stop_variables/Davismt2.h"
//#include "stop_variables/topness.h"
//#include "stop_variables/MT2_implementations.h"
#include "stop_variables/JetUtil.h"
//#include "stop_variables/mt2w.h"
//#include "stop_variables/mt2w_bisect.h"

using namespace std;
using namespace tas;

inline float getMT(LorentzVector lep,LorentzVector met){
  // From cmssw reco::deltaPhi()
  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(JetUtil::deltaPhi(lep,met) ) ) );
}

inline float dot(LorentzVector a,LorentzVector b){
  // From cmssw reco::deltaPhi()
  return a.Px()*b.Px()+a.Py()*b.Py()+a.Pz()*b.Pz();
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  bool useE = true;

  map<string, TH1F*> h1d; //massive
  vector<string> hnam; hnam.clear();
  vector<int> hn; hn.clear();
  vector<double> hl; hl.clear();
  vector<double> hu; hu.clear();
  map<string, float> value;

  map<string, TH2F*> h2d; //massive
  vector<string> hnam2d; hnam2d.clear();
  vector<bool> xp,yp; xp.clear(), yp.clear();
  vector<int> hnx; hnx.clear();
  vector<double> hlx; hlx.clear();
  vector<double> hux; hux.clear();
  vector<int> hny; hny.clear();
  vector<double> hly; hly.clear();
  vector<double> huy; huy.clear();
  hnam.push_back("GenJetMatch");     hn.push_back(20); hl.push_back(0.); hu.push_back(20.);
  hnam.push_back("DR");     hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);
  hnam.push_back("GenjDR"); hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);
  hnam.push_back("GenqDR"); hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);
  hnam.push_back("boost500DR");     hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);
  hnam.push_back("boost500GenjDR"); hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);
  hnam.push_back("boost500GenqDR"); hn.push_back(64); hl.push_back(0.); hu.push_back(6.4);

  hnam2d.push_back("DPtVsDR");    hnx.push_back(60); hlx.push_back(0.); hux.push_back(3.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false); 
  hnam2d.push_back("LepptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("JetptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("LepjetptVsDR"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(750.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenjDPtVsDR");    hnx.push_back(60); hlx.push_back(0.); hux.push_back(3.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenjLepptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenjJetptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenjLepjetptVsDR"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(750.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenqDPtVsDR");    hnx.push_back(60); hlx.push_back(0.); hux.push_back(3.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenqLepptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenqJetptVsDR");    hnx.push_back(50); hlx.push_back(0.); hux.push_back(500.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenqLepjetptVsDR"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(750.); hny.push_back(64); hly.push_back(0.); huy.push_back(6.4); xp.push_back(false); yp.push_back(false);
  
  hnam2d.push_back("GenLepGenQ_DRvsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DRvsQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DRvsLepQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DPvsQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DPvsLepQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DRvsPD"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(50000); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DRvsPD_boostedLep"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(200000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQ_DRvsPD_boostedQ"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(250000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQ_DR0p4_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQ_DR0p4_DPvsQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQ_DR0p4_DPvsLepQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQAdded_DRvsLepQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQAdded_DPvsQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenQAdded_DPvsLepQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsPD"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(50000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsPD_boostedLep"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(200000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsPD_boostedQ"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(250000);  xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsPD_boostedLepQ"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(300000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DR0p4_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DR0p4_DPvsQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DR0p4_DPvsLepQE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQ_DPdivLE2vsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DPdivLE2vsQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DPdivLE2vsLepQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQ_DRvsPDdivLE2"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(64); hly.push_back(0.); huy.push_back(64); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenQAdded_DPdivLE2vsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DPdivLE2vsQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DPdivLE2vsLepQE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenQAdded_DRvsPDdivLE2"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(64); hly.push_back(0.); huy.push_back(64); xp.push_back(false); yp.push_back(false);
  
  hnam2d.push_back("GenLepGenJet_DRvsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DRvsJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DRvsLepJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DPvsJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DPvsLepJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DRvsPD"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(100000); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DRvsPD_boostedLep"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(150000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DRvsPD_boostedJet"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(250000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DRvsPD_boostedJetSubtr"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(200000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DR0p4_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DR0p4_DPvsJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DR0p4_DPvsLepJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsLepJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DPvsJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DPvsLepJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsPD"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(50000); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsPD_boostedLep"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(150000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsPD_boostedJet"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(200000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsPD_boostedJetSubtr"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(50); hly.push_back(0.); huy.push_back(200000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DR0p4_DPvsLepE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DR0p4_DPvsJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DR0p4_DPvsLepJetE"); hnx.push_back(50); hlx.push_back(0.); hux.push_back(50000.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(false);
  hnam2d.push_back("GenLepGenJet_DPdivLE2vsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DPdivLE2vsJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DPdivLE2vsLepJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJet_DRvsPDdivLE2"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(64); hly.push_back(0.); huy.push_back(64); xp.push_back(false); yp.push_back(false);
  hnam2d.push_back("GenLepGenJetSubtr_DPdivLE2vsLepE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(false); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DPdivLE2vsJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(750); xp.push_back(true); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DPdivLE2vsLepJetE"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(64.); hny.push_back(50); hly.push_back(0.); huy.push_back(1000); xp.push_back(false); yp.push_back(true);
  hnam2d.push_back("GenLepGenJetSubtr_DRvsPDdivLE2"); hnx.push_back(64); hlx.push_back(0.); hux.push_back(6.4); hny.push_back(64); hly.push_back(0.); huy.push_back(64); xp.push_back(true); yp.push_back(false);


  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    for(unsigned int i = 0; i<hnam.size(); ++i){
      string mapname;
      mapname = hnam[i] + "_"+samplename;
      //cout << mapname << endl;
      if(h1d.count(mapname) == 0 ) h1d[mapname] = new TH1F(mapname.c_str(), "", hn[i], hl[i], hu[i]);
      h1d[mapname]->Sumw2(); h1d[mapname]->SetDirectory(rootdir);
      value[hnam[i] ] = -1;
    }
    for(unsigned int i = 0; i<hnam2d.size(); ++i){
      string mapname;
     mapname = hnam2d[i] + "_"+samplename;
     //cout << mapname << endl;
      if(h2d.count(mapname) == 0 ) h2d[mapname] = new TH2F(mapname.c_str(), "", hnx[i], hlx[i], hux[i], hny[i], hly[i], huy[i]);
      h2d[mapname]->Sumw2(); h2d[mapname]->SetDirectory(rootdir);
      value[hnam2d[i] ] = -1;
    }
  }
  int c1vtx(0), c1l(0), cno2l(0), cno2track(0), cnotau(0), c2j(0), c1b(0), cmet(0);
  int cmt(0), cmdphi(0), cchi(0);

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("t");
    if(fast) TTreeCache::SetLearnEntries(10);
    if(fast) tree->SetCacheSize(128*1024*1024);
    cms3.Init(tree);
    
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
      CMS3::progress( nEventsTotal, nEventsChain );

      double weight = scale1fb()*10.;

      string samplename = skimFilePrefix;
      if(skimFilePrefix=="TTbar"){
	if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==2) samplename = "TTbar2l";
	else if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==1) samplename = "TTbar1l";
	else samplename = "TTbarH";
	//if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==2) samplename = "TTbar2l";
	//else if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==1) samplename = "TTbar1l";
	//else samplename = "TTbarH";
      }
      // Analysis Code
      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1;
      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&fabs(cms3.lep1_d0())<0.02&&fabs(cms3.lep1_dz())<0.1&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&cms3.lep1_is_phys14_medium_noIso()&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      }
      if(lep2_is_mu()){
	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&fabs(cms3.lep2_d0())<0.02&&fabs(cms3.lep2_dz())<0.1&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; if(l1!=1) l1 = 2; else l1=-2; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&cms3.lep2_is_phys14_medium_noIso()&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
      }
      NGLeps = ngoodleps();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      if(l1==1) leplv = lep1_p4();
      else if(l1==2) leplv = lep2_p4();

      float METx = pfmet()*TMath::Cos(pfmet_phi());
      float METy = pfmet()*TMath::Sin(pfmet_phi());
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(METx,METy,0.,pfmet());

      //if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
      //NGLeps = NLeps;
      vector<int> jind;
      vector<int> bind;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jsumlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > bjetlv;
      vector<float> btag;
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	jind.push_back(nj);
	jetlv.push_back(ak4pfjets_p4()[nj]);
	btag.push_back(ak4pfjets_CSV()[nj]);
	++NGJets;
	if(ak4pfjets_CSV()[nj]>0.814) {++NGBJets; bind.push_back(nj); bjetlv.push_back(ak4pfjets_p4()[nj]);}
      }

      if(nvtxs()<0) continue; ++c1vtx;
      if(NGLeps!=1) continue; ++c1l;
      if(NSLeps!=1) continue; ++cno2l;
      if(!PassTrackVeto()) continue; ++cno2track;
      if(!PassTauVeto()) continue; ++cnotau;
      //if(NGJets<4) continue; ++c2j;
      //if(NGBJets<1) continue; ++c1b;
      //if(pfmet()<100) continue; ++cmet;
      //if(mt_met_lep()<120) continue; ++cmt;

      for(unsigned int i = 0; i<hnam.size(); ++i){
	value[hnam[i] ] = -1;//reset values
      }
	    
      float minDR(99), mingenjDR(99), mingenqDR(99);
      float bminDR(99), bmingenjDR(99), bmingenqDR(99);
      //closest jet to lepton
      //closest gen-quark to lepton
      //2d plot of lepton pt vs DR
      //2d plot of jet pt vs DR
      //2d plot of lepton+jet pt vs DR
      for(unsigned int j =0; j<ak4pfjets_p4().size();++j){
	float DR = JetUtil::deltaR(ak4pfjets_p4()[j],leplv);
	float DPtPt = TMath::Abs(ak4pfjets_p4()[j].Pt()-leplv.Pt())/leplv.Pt();
	if(DR<0.01 && DPtPt<0.01) continue;
	h2d["DPtVsDR_"+samplename]->Fill(DPtPt,DR,weight);
	h2d["LepptVsDR_"+samplename]->Fill(leplv.Pt(),DR,weight);
	h2d["JetptVsDR_"+samplename]->Fill(ak4pfjets_p4()[j].Pt(),DR,weight);
	h2d["LepjetptVsDR_"+samplename]->Fill((ak4pfjets_p4()[j]+leplv).Pt(),DR,weight);
	if(DR<minDR) minDR = DR;
	if(ak4pfjets_p4()[j].Pt()>500 && DR<bminDR) bminDR = DR;
      }
      h1d["DR_"+samplename]->Fill(minDR,weight);
      if(bminDR<90.) h1d["boost500DR_"+samplename]->Fill(bminDR,weight);
      for(unsigned int j =0; j<ak4genjets_p4().size();++j){
	float DR = JetUtil::deltaR(ak4genjets_p4()[j],leplv);
	float DPtPt = TMath::Abs(ak4genjets_p4()[j].Pt()-leplv.Pt())/leplv.Pt();
	if(DR<0.01 && DPtPt<0.01) continue;
	h2d["GenjDPtVsDR_"+samplename]->Fill(DPtPt,DR,weight);
	h2d["GenjLepptVsDR_"+samplename]->Fill(leplv.Pt(),DR,weight);
	h2d["GenjJetptVsDR_"+samplename]->Fill(ak4genjets_p4()[j].Pt(),DR,weight);
	h2d["GenjLepjetptVsDR_"+samplename]->Fill((ak4genjets_p4()[j]+leplv).Pt(),DR,weight);
	if(DR<mingenjDR) mingenjDR = DR;
	if(ak4genjets_p4()[j].Pt()>500 && DR<bmingenjDR) bmingenjDR = DR;
      }
      h1d["GenjDR_"+samplename]->Fill(mingenjDR,weight);
      if(bmingenjDR<90.) h1d["boost500GenjDR_"+samplename]->Fill(bmingenjDR,weight);
      for(unsigned int j=0; j<genbs_p4().size();++j){
	if(TMath::Abs(genbs_motherid()[j])<26||(TMath::Abs(genbs_motherid()[j])>1000000&&TMath::Abs(genbs_motherid()[j])<2000016) ){
	  float DR = JetUtil::deltaR(genbs_p4()[j],leplv);
	  float DPtPt = TMath::Abs(genbs_p4()[j].Pt()-leplv.Pt())/leplv.Pt();
	  if(DR<0.01 && DPtPt<0.01) continue;
	  h2d["GenqDPtVsDR_"+samplename]->Fill(DPtPt,DR,weight);
	  h2d["GenqLepptVsDR_"+samplename]->Fill(leplv.Pt(),DR,weight);
	  h2d["GenqJetptVsDR_"+samplename]->Fill(genbs_p4()[j].Pt(),DR,weight);
	  h2d["GenqLepjetptVsDR_"+samplename]->Fill((genbs_p4()[j]+leplv).Pt(),DR,weight);
	  if(DR<mingenqDR) mingenqDR = DR;  
	  if(genbs_p4()[j].Pt()>500 && DR<bmingenqDR) bmingenqDR = DR;
	  }
      }
      for(unsigned int j=0; j<genqs_p4().size();++j){
	if(TMath::Abs(genqs_motherid()[j])<26||(TMath::Abs(genqs_motherid()[j])>1000000&&TMath::Abs(genqs_motherid()[j])<2000016) ){
	  float DR = JetUtil::deltaR(genqs_p4()[j],leplv);
	  float DPtPt = TMath::Abs(genqs_p4()[j].Pt()-leplv.Pt())/leplv.Pt();
	  if(DR<0.01 && DPtPt<0.01) continue;
	  h2d["GenqDPtVsDR_"+samplename]->Fill(DPtPt,DR,weight);
	  h2d["GenqLepptVsDR_"+samplename]->Fill(leplv.Pt(),DR,weight);
	  h2d["GenqJetptVsDR_"+samplename]->Fill(genqs_p4()[j].Pt(),DR,weight);
	  h2d["GenqLepjetptVsDR_"+samplename]->Fill((genqs_p4()[j]+leplv).Pt(),DR,weight);
	  if(DR<mingenqDR) mingenqDR = DR;  
	  if(genqs_p4()[j].Pt()>500 && DR<bmingenqDR) bmingenqDR = DR;
	  }
      }
      h1d["GenqDR_"+samplename]->Fill(mingenqDR,weight);
      if(bmingenqDR<90.) h1d["boost500GenqDR_"+samplename]->Fill(bmingenqDR,weight);
      
      for(unsigned int i=0; i<ak4genjets_p4().size(); ++i){
	if(ak4genjets_p4()[i].Pt()<30) continue;
	if(fabs(ak4genjets_p4()[i].Eta())>2.5) continue;
	  LorentzVector reduce = ak4genjets_p4()[i]-leplv;
	  LorentzVector genjet = ak4genjets_p4()[i];
	  if(JetUtil::deltaR(leplv,genjet)>0.5) continue;
	  bool matchedtoq = false; bool matchedtoqp = false;
	  bool matchedtol = false; bool matchedtolp = false;
	  for(unsigned int j =0; j<genbs_p4().size(); ++j){
	    if( (JetUtil::deltaR(genbs_p4()[j],genjet)<0.1) && (TMath::Abs(genbs_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtoq = true;
	    }
	    if( (JetUtil::deltaR(genbs_p4()[j],reduce)<0.1) && (TMath::Abs(genbs_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtoqp = true;
	    }
	  }
	  for(unsigned int j =0; j<genqs_p4().size(); ++j){
	    if( (JetUtil::deltaR(genqs_p4()[j],genjet)<0.1) && (TMath::Abs(genqs_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtoq = true;
	    }
	    if( (JetUtil::deltaR(genqs_p4()[j],reduce)<0.1) && (TMath::Abs(genqs_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtoqp = true;
	    }
	  }
	  for(unsigned int j =0; j<genels_p4().size(); ++j){
	    if( (JetUtil::deltaR(genels_p4()[j],genjet)<0.1) && (TMath::Abs(genels_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtol = true;
	    }
	    if( (JetUtil::deltaR(genels_p4()[j],reduce)<0.1) && (TMath::Abs(genels_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtolp = true;
	    }
	  }
	  for(unsigned int j =0; j<genmus_p4().size(); ++j){
	    if( (JetUtil::deltaR(genmus_p4()[j],genjet)<0.1) && (TMath::Abs(genmus_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtol = true;
	    }
	    if( (JetUtil::deltaR(genmus_p4()[j],reduce)<0.1) && (TMath::Abs(genmus_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtolp = true;
	    }
	  }
	  for(unsigned int j =0; j<genleptau_els_p4().size(); ++j){
	    if( (JetUtil::deltaR(genleptau_els_p4()[j],genjet)<0.1) && (TMath::Abs(genleptau_els_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtol = true;
	    }
	    if( (JetUtil::deltaR(genleptau_els_p4()[j],reduce)<0.1) && (TMath::Abs(genleptau_els_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtolp = true;
	    }
	  }
	  for(unsigned int j =0; j<genleptau_mus_p4().size(); ++j){
	    if( (JetUtil::deltaR(genleptau_mus_p4()[j],genjet)<0.1) && (TMath::Abs(genleptau_mus_p4()[j].Pt()-genjet.Pt())<0.1*genjet.Pt() ) ){
	      matchedtol = true;
	    }
	    if( (JetUtil::deltaR(genleptau_mus_p4()[j],reduce)<0.1) && (TMath::Abs(genleptau_mus_p4()[j].Pt()-reduce.Pt())<0.1*reduce.Pt() ) ){
	      matchedtolp = true;
	    }
	  }
	  float fillindex = -1;
	  //genjet matched to
	  //  quark                           lepton
	  //genjet - lepton matched to
	  //                       quark                         lepton
	  if(!matchedtoq && !matchedtoqp && !matchedtol && !matchedtolp) fillindex =  1;
	  else if(!matchedtoq && !matchedtoqp && !matchedtol &&  matchedtolp) fillindex =  2;
	  else if(!matchedtoq && !matchedtoqp &&  matchedtol && !matchedtolp) fillindex =  3;
	  else if(!matchedtoq &&  matchedtoqp && !matchedtol && !matchedtolp) fillindex =  4;
	  else if( matchedtoq && !matchedtoqp && !matchedtol && !matchedtolp) fillindex =  5;
	  else if(!matchedtoq && !matchedtoqp &&  matchedtol &&  matchedtolp) fillindex =  6;
	  else if(!matchedtoq &&  matchedtoqp && !matchedtol &&  matchedtolp) fillindex =  7;
	  else if(!matchedtoq &&  matchedtoqp &&  matchedtol && !matchedtolp) fillindex =  8;
	  else if( matchedtoq && !matchedtoqp && !matchedtol &&  matchedtolp) fillindex =  9;
	  else if( matchedtoq && !matchedtoqp &&  matchedtol && !matchedtolp) fillindex = 10;
	  else if( matchedtoq &&  matchedtoqp && !matchedtol && !matchedtolp) fillindex = 11;
	  else if(!matchedtoq &&  matchedtoqp &&  matchedtol &&  matchedtolp) fillindex = 12;
	  else if( matchedtoq && !matchedtoqp &&  matchedtol &&  matchedtolp) fillindex = 13;
	  else if( matchedtoq &&  matchedtoqp && !matchedtol &&  matchedtolp) fillindex = 14;
	  else if( matchedtoq &&  matchedtoqp &&  matchedtol && !matchedtolp) fillindex = 15;
	  else if( matchedtoq &&  matchedtoqp &&  matchedtol &&  matchedtolp) fillindex = 16;
	  else  fillindex = 19;
	  h1d["GenJetMatch_"+samplename]->Fill(fillindex,weight);
      }
      
      LorentzVector mygenlep; mygenlep.SetPxPyPzE(0.,0.,0.,0.);
      for(unsigned int j =0; j<genels_p4().size(); ++j){
	if(mygenlep.E()==0){
	  mygenlep.SetPxPyPzE(genels_p4()[j].Px(),genels_p4()[j].Py(),genels_p4()[j].Pz(),genels_p4()[j].E() );
	} else{
	  if(JetUtil::deltaR(genels_p4()[j],leplv)>JetUtil::deltaR(mygenlep,leplv)) continue;
	  mygenlep.SetPxPyPzE(genels_p4()[j].Px(),genels_p4()[j].Py(),genels_p4()[j].Pz(),genels_p4()[j].E() );
	}
      }
      for(unsigned int j =0; j<genmus_p4().size(); ++j){
	if(mygenlep.E()==0){
	  mygenlep.SetPxPyPzE(genmus_p4()[j].Px(),genmus_p4()[j].Py(),genmus_p4()[j].Pz(),genmus_p4()[j].E() );
	} else{
	  if(JetUtil::deltaR(genmus_p4()[j],leplv)>JetUtil::deltaR(mygenlep,leplv)) continue;
	  mygenlep.SetPxPyPzE(genmus_p4()[j].Px(),genmus_p4()[j].Py(),genmus_p4()[j].Pz(),genmus_p4()[j].E() );
	}
      }    
      for(unsigned int j =0; j<genleptau_els_p4().size(); ++j){
	if(mygenlep.E()==0){
	  mygenlep.SetPxPyPzE(genleptau_els_p4()[j].Px(),genleptau_els_p4()[j].Py(),genleptau_els_p4()[j].Pz(),genleptau_els_p4()[j].E() );
	} else{
	  if(JetUtil::deltaR(genleptau_els_p4()[j],leplv)>JetUtil::deltaR(mygenlep,leplv)) continue;
	  mygenlep.SetPxPyPzE(genleptau_els_p4()[j].Px(),genleptau_els_p4()[j].Py(),genleptau_els_p4()[j].Pz(),genleptau_els_p4()[j].E() );
	}
      }
      for(unsigned int j =0; j<genleptau_mus_p4().size(); ++j){
	if(mygenlep.E()==0){
	  mygenlep.SetPxPyPzE(genleptau_mus_p4()[j].Px(),genleptau_mus_p4()[j].Py(),genleptau_mus_p4()[j].Pz(),genleptau_mus_p4()[j].E() );
	} else{
	  if(JetUtil::deltaR(genleptau_mus_p4()[j],leplv)>JetUtil::deltaR(mygenlep,leplv)) continue;
	  mygenlep.SetPxPyPzE(genleptau_mus_p4()[j].Px(),genleptau_mus_p4()[j].Py(),genleptau_mus_p4()[j].Pz(),genleptau_mus_p4()[j].E() );
	}
      }
      float myboost = 400.;
      //2d plots vs LepE, Jet/QE, (Lep+Q/Jet)E
	for(unsigned int j =0; j<genbs_p4().size(); ++j){
	  float DR = JetUtil::deltaR(genbs_p4()[j],mygenlep);
	  float DP = dot(genbs_p4()[j],mygenlep);
	  LorentzVector mysum = genbs_p4()[j]+mygenlep;
	  float mysumpt = mysum.Pt();
	  float mysumsumpt = (mysum+mygenlep).Pt();
	  float myqpt = genbs_p4()[j].Pt();
	  float mylpt = mygenlep.Pt();
	  float mylpt2 = pow(mygenlep.Pt(),2);
	  if(useE){
	    mysumpt = mysum.E();
	    mysumsumpt = (mysum+mygenlep).E();
	    myqpt = genbs_p4()[j].E();
	    mylpt = mygenlep.E();
	    mylpt2 = pow(mygenlep.E(),2);
	  }
	  h2d["GenLepGenQ_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenQ_DRvsQE_"+samplename]->Fill(DR,myqpt,weight);
	  h2d["GenLepGenQ_DRvsLepQE_"+samplename]->Fill(DR,mysumpt,weight);
	  h2d["GenLepGenQ_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenQ_DPvsQE_"+samplename]->Fill(DP,myqpt,weight);
	  h2d["GenLepGenQ_DPvsLepQE_"+samplename]->Fill(DP,mysumpt,weight);
	  h2d["GenLepGenQ_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenQ_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenQ_DPdivLE2vsQE_"+samplename]->Fill(DP/mylpt2,myqpt,weight);
	  h2d["GenLepGenQ_DPdivLE2vsLepQE_"+samplename]->Fill(DP/mylpt2,mysumpt,weight);
	  h2d["GenLepGenQ_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt2,weight);
	  if(mylpt>myboost) h2d["GenLepGenQ_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost) h2d["GenLepGenQ_DRvsPD_boostedQ_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenQ_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenQ_DR0p4_DPvsQE_"+samplename]->Fill(DP,myqpt,weight);
	    h2d["GenLepGenQ_DR0p4_DPvsLepQE_"+samplename]->Fill(DP,mysumpt,weight);
	  }
	  DR = JetUtil::deltaR(mysum,mygenlep);
	  DP = dot(mysum,mygenlep);
	  h2d["GenLepGenQAdded_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenQAdded_DRvsQE_"+samplename]->Fill(DR,mysumpt,weight);
	  h2d["GenLepGenQAdded_DRvsLepQE_"+samplename]->Fill(DR,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenQAdded_DPvsQE_"+samplename]->Fill(DP,mysumpt,weight);
	  h2d["GenLepGenQAdded_DPvsLepQE_"+samplename]->Fill(DP,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsQE_"+samplename]->Fill(DP/mylpt,mysumpt,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsLepQE_"+samplename]->Fill(DP/mylpt,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt,weight);
	  if(mylpt>myboost)   h2d["GenLepGenQAdded_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(mysumpt>myboost) h2d["GenLepGenQAdded_DRvsPD_boostedLepQ_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost)   h2d["GenLepGenQAdded_DRvsPD_boostedQ_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenQAdded_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenQAdded_DR0p4_DPvsQE_"+samplename]->Fill(DP,mysumpt,weight);
	    h2d["GenLepGenQAdded_DR0p4_DPvsLepQE_"+samplename]->Fill(DP,mysumsumpt,weight);
	  }
	}
	for(unsigned int j =0; j<genqs_p4().size(); ++j){
	  float DR = JetUtil::deltaR(genqs_p4()[j],mygenlep);
	  float DP = dot(genqs_p4()[j],mygenlep);
	  LorentzVector mysum = genqs_p4()[j]+mygenlep;
	  float mysumpt = mysum.Pt();
	  float mysumsumpt = (mysum+mygenlep).Pt();
	  float myqpt = genqs_p4()[j].Pt();
	  float mylpt = mygenlep.Pt();
	  float mylpt2 = pow(mygenlep.Pt(),2);
	  if(useE){
	    mysumpt = mysum.E();
	    mysumsumpt = (mysum+mygenlep).E();
	    myqpt = genqs_p4()[j].E();
	    mylpt = mygenlep.E();
	    mylpt2 = pow(mygenlep.E(),2);
	  }
	  h2d["GenLepGenQ_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenQ_DRvsQE_"+samplename]->Fill(DR,myqpt,weight);
	  h2d["GenLepGenQ_DRvsLepQE_"+samplename]->Fill(DR,mysumpt,weight);
	  h2d["GenLepGenQ_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenQ_DPvsQE_"+samplename]->Fill(DP,myqpt,weight);
	  h2d["GenLepGenQ_DPvsLepQE_"+samplename]->Fill(DP,mysumpt,weight);
	  h2d["GenLepGenQ_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenQ_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenQ_DPdivLE2vsQE_"+samplename]->Fill(DP/mylpt2,myqpt,weight);
	  h2d["GenLepGenQ_DPdivLE2vsLepQE_"+samplename]->Fill(DP/mylpt2,mysumpt,weight);
	  h2d["GenLepGenQ_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt2,weight);
	  if(mylpt>myboost) h2d["GenLepGenQ_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost) h2d["GenLepGenQ_DRvsPD_boostedQ_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenQ_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenQ_DR0p4_DPvsQE_"+samplename]->Fill(DP,myqpt,weight);
	    h2d["GenLepGenQ_DR0p4_DPvsLepQE_"+samplename]->Fill(DP,mysumpt,weight);
	  }
	  DR = JetUtil::deltaR(mysum,mygenlep);
	  DP = dot(mysum,mygenlep);
	  h2d["GenLepGenQAdded_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenQAdded_DRvsQE_"+samplename]->Fill(DR,mysumpt,weight);
	  h2d["GenLepGenQAdded_DRvsLepQE_"+samplename]->Fill(DR,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenQAdded_DPvsQE_"+samplename]->Fill(DP,mysumpt,weight);
	  h2d["GenLepGenQAdded_DPvsLepQE_"+samplename]->Fill(DP,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsQE_"+samplename]->Fill(DP/mylpt,mysumpt,weight);
	  h2d["GenLepGenQAdded_DPdivLE2vsLepQE_"+samplename]->Fill(DP/mylpt,mysumsumpt,weight);
	  h2d["GenLepGenQAdded_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt,weight);
	  if(mylpt>myboost)   h2d["GenLepGenQAdded_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(mysumpt>myboost) h2d["GenLepGenQAdded_DRvsPD_boostedLepQ_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost)   h2d["GenLepGenQAdded_DRvsPD_boostedQ_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenQAdded_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenQAdded_DR0p4_DPvsQE_"+samplename]->Fill(DP,mysumpt,weight);
	    h2d["GenLepGenQAdded_DR0p4_DPvsLepQE_"+samplename]->Fill(DP,mysumsumpt,weight);
	  }
	}
	for(unsigned int j=0; j<ak4genjets_p4().size(); ++j){
	  LorentzVector mygenjet = ak4genjets_p4()[j] - mygenlep;
	  float DR = JetUtil::deltaR(ak4genjets_p4()[j],mygenlep);
	  float DP = dot(ak4genjets_p4()[j],mygenlep);
	  LorentzVector mysum = ak4genjets_p4()[j]+mygenlep;
	  float mysumpt = mysum.Pt();
	  float mydiffpt = mygenjet.Pt();
	  float mydiffsumpt = (mygenjet+mygenlep).Pt();
	  float myqpt = ak4genjets_p4()[j].Pt();
	  float mylpt = mygenlep.Pt();
	  float mylpt2 = pow(mygenlep.Pt(),2);
	  if(useE){
	    mysumpt = mysum.E();
	    mydiffpt = mygenjet.E();
	    mydiffsumpt = (mygenjet+mygenlep).E();
	    myqpt = ak4genjets_p4()[j].E();
	    mylpt = mygenlep.E();
	    mylpt2 = pow(mygenlep.E(),2);
	  }
	  h2d["GenLepGenJet_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenJet_DRvsJetE_"+samplename]->Fill(DR,myqpt,weight);
	  h2d["GenLepGenJet_DRvsLepJetE_"+samplename]->Fill(DR,mysumpt,weight);
	  h2d["GenLepGenJet_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenJet_DPvsJetE_"+samplename]->Fill(DP,myqpt,weight);
	  h2d["GenLepGenJet_DPvsLepJetE_"+samplename]->Fill(DP,mysumpt,weight);
	  h2d["GenLepGenJet_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenJet_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenJet_DPdivLE2vsJetE_"+samplename]->Fill(DP/mylpt2,myqpt,weight);
	  h2d["GenLepGenJet_DPdivLE2vsLepJetE_"+samplename]->Fill(DP/mylpt2,mysumpt,weight);
	  h2d["GenLepGenJet_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt2,weight);
	  if(mylpt>myboost)    h2d["GenLepGenJet_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost)    h2d["GenLepGenJet_DRvsPD_boostedJet_"+samplename]->Fill(DR,DP,weight);
	  if(mydiffpt>myboost) h2d["GenLepGenJet_DRvsPD_boostedJetSubtr_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenJet_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenJet_DR0p4_DPvsJetE_"+samplename]->Fill(DP,myqpt,weight);
	    h2d["GenLepGenJet_DR0p4_DPvsLepJetE_"+samplename]->Fill(DP,(mygenlep+ak4genjets_p4()[j]).Pt(),weight);
	  }
	  DR = JetUtil::deltaR(mygenjet,mygenlep);
	  DP = dot(mygenjet,mygenlep);
	  h2d["GenLepGenJetSubtr_DRvsLepE_"+samplename]->Fill(DR,mylpt,weight);
	  h2d["GenLepGenJetSubtr_DRvsJetE_"+samplename]->Fill(DR,mydiffpt,weight);
	  h2d["GenLepGenJetSubtr_DRvsLepJetE_"+samplename]->Fill(DR,mydiffsumpt,weight);
	  h2d["GenLepGenJetSubtr_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	  h2d["GenLepGenJetSubtr_DPvsJetE_"+samplename]->Fill(DP,mydiffpt,weight);
	  h2d["GenLepGenJetSubtr_DPvsLepJetE_"+samplename]->Fill(DP,mydiffsumpt,weight);
	  h2d["GenLepGenJetSubtr_DRvsPD_"+samplename]->Fill(DR,DP,weight);
	  h2d["GenLepGenJetSubtr_DPdivLE2vsLepE_"+samplename]->Fill(DP/mylpt2,mylpt,weight);
	  h2d["GenLepGenJetSubtr_DPdivLE2vsJetE_"+samplename]->Fill(DP/mylpt2,mydiffpt,weight);
	  h2d["GenLepGenJetSubtr_DPdivLE2vsLepJetE_"+samplename]->Fill(DP/mylpt2,mydiffsumpt,weight);
	  h2d["GenLepGenJetSubtr_DRvsPDdivLE2_"+samplename]->Fill(DR,DP/mylpt2,weight);
	  if(mylpt>myboost)    h2d["GenLepGenJetSubtr_DRvsPD_boostedLep_"+samplename]->Fill(DR,DP,weight);
	  if(myqpt>myboost)    h2d["GenLepGenJetSubtr_DRvsPD_boostedJet_"+samplename]->Fill(DR,DP,weight);
	  if(mydiffpt>myboost) h2d["GenLepGenJetSubtr_DRvsPD_boostedJetSubtr_"+samplename]->Fill(DR,DP,weight);
	  if(DR<0.4){
	    h2d["GenLepGenJetSubtr_DR0p4_DPvsLepE_"+samplename]->Fill(DP,mylpt,weight);
	    h2d["GenLepGenJetSubtr_DR0p4_DPvsJetE_"+samplename]->Fill(DP,mydiffpt,weight);
	    h2d["GenLepGenJetSubtr_DR0p4_DPvsLepJetE_"+samplename]->Fill(DP,mydiffsumpt,weight);
	  }
	}      
	/*
      if(bmingenjDR<0.25 || bmingenqDR<0.25){
	cout << "Print out generator information: ";
	cout << "Event has j-l DR " << bmingenjDR << "(j-pt>500 GeV), q-l DR " << bmingenqDR << "(q-pt>500 GeV)." << endl;
	for(unsigned int j =0; j<genels_p4().size(); ++j){
	  cout << "genelectron    " << j << " with id " << genels_id()[j] << ", charge " << genels_charge()[j] << ", and status " << genels_status()[j] << " has " << endl;
	  cout << "   Pt " << genels_p4()[j].Pt() << ", eta " << genels_p4()[j].Eta() << ", phi " << genels_p4()[j].Phi() << ", mass " << genels_p4()[j].M();
	  cout << "   iso " << genels_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(genels_p4()[j],leplv) << endl;
	  cout << "   motherid " << genels_motherid()[j] << ", charge " << genels_mothercharge()[j] << ", status " << genels_motherstatus()[j] << endl;
	  cout << "   motherpt " << genels_motherp4()[j].Pt() << ", eta " << genels_motherp4()[j].Eta() << ", phi " << genels_motherp4()[j].Phi() << ", mass " << genels_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<genmus_p4().size(); ++j){
	  cout << "genmuon        " << j << " with id " << genmus_id()[j] << ", charge " << genmus_charge()[j] << ", and status " << genmus_status()[j] << " has " << endl;
	  cout << "   Pt " << genmus_p4()[j].Pt() << ", eta " << genmus_p4()[j].Eta() << ", phi " << genmus_p4()[j].Phi() << ", mass " << genmus_p4()[j].M();
	  cout << "   iso " << genmus_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(genmus_p4()[j],leplv) << endl;
	  cout << "   motherid " << genmus_motherid()[j] << ", charge " << genmus_mothercharge()[j] << ", status " << genmus_motherstatus()[j] << endl;
	  cout << "   motherpt " << genmus_motherp4()[j].Pt() << ", eta " << genmus_motherp4()[j].Eta() << ", phi " << genmus_motherp4()[j].Phi() << ", mass " << genmus_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<genleptau_els_p4().size(); ++j){
	  cout << "genelectrontau " << j << " with id " << genleptau_els_id()[j] << ", charge " << genleptau_els_charge()[j] << ", and status " << genleptau_els_status()[j] << " has " << endl;
	  cout << "   Pt " << genleptau_els_p4()[j].Pt() << ", eta " << genleptau_els_p4()[j].Eta() << ", phi " << genleptau_els_p4()[j].Phi() << ", mass " << genleptau_els_p4()[j].M();
	  cout << "   iso " << genleptau_els_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(genleptau_els_p4()[j],leplv) << endl;
	  cout << "   motherid " << genleptau_els_motherid()[j] << ", charge " << genleptau_els_mothercharge()[j] << ", status " << genleptau_els_motherstatus()[j] << endl;
	  cout << "   motherpt " << genleptau_els_motherp4()[j].Pt() << ", eta " << genleptau_els_motherp4()[j].Eta() << ", phi " << genleptau_els_motherp4()[j].Phi() << ", mass " << genleptau_els_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<genleptau_mus_p4().size(); ++j){
	  cout << "genmuontau     " << j << " with id " << genleptau_mus_id()[j] << ", charge " << genleptau_mus_charge()[j] << ", and status " << genleptau_mus_status()[j] << " has " << endl;
	  cout << "   Pt " << genleptau_mus_p4()[j].Pt() << ", eta " << genleptau_mus_p4()[j].Eta() << ", phi " << genleptau_mus_p4()[j].Phi() << ", mass " << genleptau_mus_p4()[j].M();
	  cout << "   iso " << genleptau_mus_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(genleptau_mus_p4()[j],leplv) << endl;
	  cout << "   motherid " << genleptau_mus_motherid()[j] << ", charge " << genleptau_mus_mothercharge()[j] << ", status " << genleptau_mus_motherstatus()[j] << endl;
	  cout << "   motherpt " << genleptau_mus_motherp4()[j].Pt() << ", eta " << genleptau_mus_motherp4()[j].Eta() << ", phi " << genleptau_mus_motherp4()[j].Phi() << ", mass " << genleptau_mus_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<gentaus_p4().size(); ++j){
	  cout << "gentau         " << j << " with id " << gentaus_id()[j] << ", charge " << gentaus_charge()[j] << ", and status " << gentaus_status()[j] << " has " << endl;
	  cout << "   Pt " << gentaus_p4()[j].Pt() << ", eta " << gentaus_p4()[j].Eta() << ", phi " << gentaus_p4()[j].Phi() << ", mass " << gentaus_p4()[j].M();
	  cout << "   iso " << gentaus_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(gentaus_p4()[j],leplv) << endl;
	  cout << "   motherid " << gentaus_motherid()[j] << ", charge " << gentaus_mothercharge()[j] << ", status " << gentaus_motherstatus()[j] << endl;
	  cout << "   motherpt " << gentaus_motherp4()[j].Pt() << ", eta " << gentaus_motherp4()[j].Eta() << ", phi " << gentaus_motherp4()[j].Phi() << ", mass " << gentaus_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<gennus_p4().size(); ++j){
	  cout << "genneutrino    " << j << " with id " << gennus_id()[j] << ", charge " << gennus_charge()[j] << ", and status " << gennus_status()[j] << " has " << endl;
	  cout << "   Pt " << gennus_p4()[j].Pt() << ", eta " << gennus_p4()[j].Eta() << ", phi " << gennus_p4()[j].Phi() << ", mass " << gennus_p4()[j].M();
	  cout << "   iso " << gennus_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(gennus_p4()[j],leplv) << endl;
	  cout << "   motherid " << gennus_motherid()[j] << ", charge " << gennus_mothercharge()[j] << ", status " << gennus_motherstatus()[j] << endl;
	  cout << "   motherpt " << gennus_motherp4()[j].Pt() << ", eta " << gennus_motherp4()[j].Eta() << ", phi " << gennus_motherp4()[j].Phi() << ", mass " << gennus_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<genbs_p4().size(); ++j){
	  cout << "genb           " << j << " with id " << genbs_id()[j] << ", charge " << genbs_charge()[j] << ", and status " << genbs_status()[j] << " has " << endl;
	  cout << "   Pt " << genbs_p4()[j].Pt() << ", eta " << genbs_p4()[j].Eta() << ", phi " << genbs_p4()[j].Phi() << ", mass " << genbs_p4()[j].M();
	  cout << "   iso " << genbs_iso()[j] << endl;// << " DR(sel.lep) " << JetUtil::deltaR(genbs_p4()[j],leplv) << endl;
	  float DR = JetUtil::deltaR(genbs_p4()[j],leplv)/100.;
	  cout << "   DR(sel.lep) " << DR*100. << " DR'*Ptl " << DR*leplv.Pt() << " DR'*Ptj " << DR*genbs_p4()[j].Pt() << " DR'*Pt(l+j) " << DR*(genbs_p4()[j]+leplv).Pt() << endl;
	  cout << "   jet*lep " << dot(genbs_p4()[j],leplv) << " (jet*lep)/lPt " << dot(genbs_p4()[j],leplv)/leplv.Pt() << " (jet*lep)/jPt " << dot(genbs_p4()[j],leplv)/genbs_p4()[j].Pt() << " (jet*lep)/ljPt " << dot(genbs_p4()[j],leplv)/(genbs_p4()[j]+leplv).Pt() << endl;
	  cout << "   motherid " << genbs_motherid()[j] << ", charge " << genbs_mothercharge()[j] << ", status " << genbs_motherstatus()[j] << endl;
	  cout << "   motherpt " << genbs_motherp4()[j].Pt() << ", eta " << genbs_motherp4()[j].Eta() << ", phi " << genbs_motherp4()[j].Phi() << ", mass " << genbs_motherp4()[j].M() << endl;
	}
	for(unsigned int j =0; j<genqs_p4().size(); ++j){
	  cout << "genq           " << j << " with id " << genqs_id()[j] << ", charge " << genqs_charge()[j] << ", and status " << genqs_status()[j] << " has " << endl;
	  cout << "   Pt " << genqs_p4()[j].Pt() << ", eta " << genqs_p4()[j].Eta() << ", phi " << genqs_p4()[j].Phi() << ", mass " << genqs_p4()[j].M();
	  cout << "   iso " << genqs_iso()[j] << endl;// << " DR(sel.lep) " << JetUtil::deltaR(genqs_p4()[j],leplv) << endl;
	  float DR = JetUtil::deltaR(genqs_p4()[j],leplv)/100.;
	  cout << "   DR(sel.lep) " << DR*100. << " DR'*Ptl " << DR*leplv.Pt() << " DR'*Ptj " << DR*genqs_p4()[j].Pt() << " DR'*Pt(l+j) " << DR*(genqs_p4()[j]+leplv).Pt() << endl;
	  cout << "   jet*lep " << dot(genqs_p4()[j],leplv) << " (jet*lep)/lPt " << dot(genqs_p4()[j],leplv)/leplv.Pt() << " (jet*lep)/jPt " << dot(genqs_p4()[j],leplv)/genqs_p4()[j].Pt() << " (jet*lep)/ljPt " << dot(genqs_p4()[j],leplv)/(genqs_p4()[j]+leplv).Pt() << endl;
	  cout << "   motherid " << genqs_motherid()[j] << ", charge " << genqs_mothercharge()[j] << ", status " << genqs_motherstatus()[j] << endl;
	  cout << "   motherpt " << genqs_motherp4()[j].Pt() << ", eta " << genqs_motherp4()[j].Eta() << ", phi " << genqs_motherp4()[j].Phi() << ", mass " << genqs_motherp4()[j].M() << endl;
	}
	//for(unsigned int j =0; j<gents_p4().size(); ++j){
	//  cout << "gentop          " << j << " with id " << gents_id()[j] << ", charge " << gents_charge()[j] << ", and status " << gents_status()[j] << " has " << endl;
	//  cout << "   Pt " << gents_p4()[j].Pt() << ", eta " << gents_p4()[j].Eta() << ", phi " << gents_p4()[j].Phi() << ", mass " << gents_p4()[j].M();
	//  cout << "   iso " << gents_iso()[j] << " DR(sel.lep) " << JetUtil::deltaR(gents_p4()[j],leplv) << endl;
	//  cout << "   motherid " << gents_motherid()[j] << ", charge " << gents_mothercharge()[j] << ", status " << gents_motherstatus()[j] << endl;
	//  cout << "   motherpt " << gents_motherp4()[j].Pt() << ", eta " << gents_motherp4()[j].Eta() << ", phi " << gents_motherp4()[j].Phi() << ", mass " << gents_motherp4()[j].M() << endl;
	//}
	for(unsigned int j=0; j<ak4genjets_p4().size(); ++j){
	  float DR = JetUtil::deltaR(ak4genjets_p4()[j],leplv)/100.;
	  //if(DR*100.>0.5) continue;
	  cout << "genjet " << j << " Pt " << ak4genjets_p4()[j].Pt() << ", eta " << ak4genjets_p4()[j].Eta() << ", phi " << ak4genjets_p4()[j].Phi() << ", mass " << ak4genjets_p4()[j].M();
	  cout << " DR(sel.lep) " << JetUtil::deltaR(ak4genjets_p4()[j],leplv) << endl;
	  cout << "   DR(sel.lep) " << DR*100. << " DR'*Ptl " << DR*leplv.Pt() << " DR'*Ptj " << DR*ak4genjets_p4()[j].Pt() << " DR'*Pt(l+j) " << DR*(ak4genjets_p4()[j]+leplv).Pt() << endl;
	  cout << "   jet*lep " << dot(ak4genjets_p4()[j],leplv) << " (jet*lep)/lPt " << dot(ak4genjets_p4()[j],leplv)/leplv.Pt() << " (jet*lep)/jPt " << dot(ak4genjets_p4()[j],leplv)/ak4genjets_p4()[j].Pt() << " (jet*lep)/ljPt " << dot(ak4genjets_p4()[j],leplv)/(ak4genjets_p4()[j]+leplv).Pt() << endl;
	  LorentzVector reduce = ak4genjets_p4()[j]-leplv;
	  cout << "reduce " << j << " Pt " << reduce.Pt() << ", eta " << reduce.Eta() << ", phi " << reduce.Phi() << ", mass " << reduce.M();
	  cout << " DR(sel.lep) " << JetUtil::deltaR(reduce,leplv) << endl;
	  DR = JetUtil::deltaR(reduce,leplv)/100.;
	  cout << "   DR(sel.lep) " << DR*100. << " DR'*Ptl " << DR*leplv.Pt() << " DR'*Ptj " << DR*reduce.Pt() << " DR'*Pt(l+j) " << DR*(reduce+leplv).Pt() << endl;
	  cout << "   jet*lep " << dot(reduce,leplv) << " (jet*lep)/lPt " << dot(reduce,leplv)/leplv.Pt() << " (jet*lep)/jPt " << dot(reduce,leplv)/ak4genjets_p4()[j].Pt() << " (jet*lep)/ljPt " << dot(reduce,leplv)/(reduce+leplv).Pt() << endl;
	}
	if(l1==1){
	  cout << "My jets are:" << endl;
	  for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	    if(ak4pfjets_p4()[nj].Pt()<30) continue;
	    if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	    if(ak4pfjets_loose_pfid()[nj]==false) continue;
	    if(JetUtil::deltaR(ak4pfjets_p4()[nj],leplv)>0.5) continue;
	    cout << "jet " << nj << " Pt " << ak4pfjets_p4()[nj].Pt() << " Eta " << ak4pfjets_p4()[nj].Eta() << " Phi " << ak4pfjets_p4()[nj].Phi() << " Mass " << ak4pfjets_p4()[nj].M() << " DR(sel-lep) " << JetUtil::deltaR(ak4pfjets_p4()[nj],leplv);
	    if(ak4pfjets_CSV()[nj]>0.814) cout << " and is b-tagged";
	    cout << endl;
	  }
	  cout << "My recolepton is ";
	  if(lep1_is_el()) cout << " an electron";
	  if(lep1_is_mu()) cout << " a muon";
	  cout << " with charge " << lep1_charge();
	  if(lep1_is_phys14_loose_noIso()) cout << " passing looseID";
	  if(lep1_is_phys14_medium_noIso()) cout << " passing mediumID";
	  if(lep1_is_phys14_tight_noIso()) cout << " passing tightID";
	  cout << endl << "  Pt " << lep1_p4().Pt() << " eta " << lep1_p4().Eta() << " phi " << lep1_p4().Phi() << " mass " << lep1_p4().M() << endl;
	  cout << "  miniIso " << lep1_MiniIso() << " minirelIsoDB " << lep1_miniRelIsoDB() << " relIso03DB " << lep1_relIso03DB() << " relIso04DB " << lep1_relIso04DB() << " pfIso03 " <<  lep1_pfiso03() << endl;
	  cout << endl;
	}
      }
      */

      //for(unsigned int i = 0; i<hnam.size(); ++i){
      //string d = "_";
      //string mname;
      //mname= hnam[i]+d+samplename;
      //h[mname]->Fill(value[hnam[i] ],weight);
      //}
      for(unsigned int i = 0; i<hnam.size(); ++i){
	value[hnam[i] ] = -1;//reset values
      }
      if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
      if(chi2()>5) continue; ++cchi;
    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Hgrams
  // sampleh->Draw();

  for(map<string,TH1F*>::iterator h=h1d.begin(); h!=h1d.end();++h){
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
  }

  for(map<string,TH2F*>::iterator h=h2d.begin(); h!=h2d.end();++h){
    for(int by = 1; by<=h->second->GetNbinsY();++by){
      h->second->SetBinContent(h->second->GetNbinsX(), by, h->second->GetBinContent(h->second->GetNbinsX(),by)+ h->second->GetBinContent(h->second->GetNbinsX()+1,by) );
      h->second->SetBinError(h->second->GetNbinsX(), by, sqrt(pow(h->second->GetBinError(h->second->GetNbinsX(),by),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1,by),2) ) );
    }
    for(int bx = 1; bx<=h->second->GetNbinsX();++bx){
      h->second->SetBinContent(bx, h->second->GetNbinsY(), h->second->GetBinContent(bx, h->second->GetNbinsY() )+ h->second->GetBinContent(bx, h->second->GetNbinsY()+1) );
      h->second->SetBinError(bx, h->second->GetNbinsY(), sqrt(pow(h->second->GetBinError(bx, h->second->GetNbinsY() ),2)+pow(h->second->GetBinError(bx, h->second->GetNbinsY()+1),2) ) );
    }
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetNbinsY(), 
			     h->second->GetBinContent(h->second->GetNbinsX(),h->second->GetNbinsY() )+ h->second->GetBinContent(h->second->GetNbinsX()+1,h->second->GetNbinsY()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), h->second->GetNbinsY(), 
			   sqrt(pow(h->second->GetBinError(h->second->GetNbinsX(),h->second->GetNbinsY() ),2)+
				pow(h->second->GetBinError(h->second->GetNbinsX()+1,h->second->GetNbinsY()+1),2) ) );
  }

  map<string, TProfile*> prof; //massive
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    for(unsigned int i = 0; i<hnam2d.size(); ++i){
      string mapname, mname;
      mapname = hnam2d[i] + "_"+samplename;
      mname = "PX_"+ hnam2d[i] + "_"+samplename;
      if(xp[i] == true){
	if(prof.count(mname) == 0 ) prof[mname] = h2d[mapname]->ProfileX(mname.c_str());
      }
      mname = "PY_"+ hnam2d[i] + "_"+samplename;
      if(yp[i] == true){
	if(prof.count(mname) == 0 ) prof[mname] = h2d[mapname]->ProfileY(mname.c_str());
      }  
    }
  }
  
  string filename = "rootfiles/DRHistos/Pt/Histos_"+skimFilePrefix+".root";
  if(useE) filename = "rootfiles/DRHistos/E/Histos_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,    TH1F*>::iterator h=    h1d.begin(); h!=    h1d.end();++h) h->second->Write();
  for(map<string,    TH2F*>::iterator h=    h2d.begin(); h!=    h2d.end();++h) h->second->Write();
  for(map<string,TProfile*>::iterator h=   prof.begin(); h!=   prof.end();++h) h->second->Write();
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
