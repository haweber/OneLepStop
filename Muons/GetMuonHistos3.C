// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"

// CMS3
#include "CMS3_v003.cc"
#include "/home/users/haweber/Software/makeCMS3ClassFiles/vecUtils.h"
#include "/home/users/haweber/Tools/goodrun.h"
#include "/home/users/haweber/Tools/goodrun.cc"

#include "LoadStruct.h"

using namespace std;
using namespace tas;

float deltaR(LorentzVector jet1, LorentzVector jet2){
  // From cmssw reco::deltaPhi()
  float dphi = jet1.Phi() - jet2.Phi();
  while( dphi >   TMath::Pi() ) dphi -= TMath::TwoPi();
  while( dphi <= -TMath::Pi() ) dphi += TMath::TwoPi();
  return TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(jet1.Eta()-jet2.Eta(),2));
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  int currentrun = -1;
  bool DCSonly = false;//KEEP THIS FALSE
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();
  histonames.push_back("Mll");                       hbins.push_back(75); hlow.push_back(  15.); hup.push_back(390);
  histonames.push_back("Mud0");                      hbins.push_back(40); hlow.push_back( -0.4); hup.push_back(0.4);
  histonames.push_back("MudZ");                      hbins.push_back(40); hlow.push_back(  -1.); hup.push_back(1. );
  histonames.push_back("MuIP3d");                    hbins.push_back(40); hlow.push_back( -0.5); hup.push_back(0.5);
  histonames.push_back("MuRelIso03");                hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso03EA");              hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso03DB");              hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuMiniIsoEA");               hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuMiniIsoDB");               hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso04");                hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuAnnulus04");               hbins.push_back(25); hlow.push_back(   0.); hup.push_back(1. );
  histonames.push_back("MuRelIso03_MT30");           hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso03EA_MT30");         hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso03DB_MT30");         hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuMiniIsoEA_MT30");          hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuMiniIsoDB_MT30");          hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuRelIso04_MT30");           hbins.push_back(50); hlow.push_back(   0.); hup.push_back(2. );
  histonames.push_back("MuAnnulus04_MT30");          hbins.push_back(25); hlow.push_back(   0.); hup.push_back(1. );
  histonames.push_back("MuID");                      hbins.push_back( 7); hlow.push_back(  -1.); hup.push_back(6. );
  histonames.push_back("MuvalidFraction");           hbins.push_back(25); hlow.push_back(   0.); hup.push_back(1. );
  histonames.push_back("MuisPF");                    hbins.push_back( 5); hlow.push_back(  -1.); hup.push_back(4. );
  histonames.push_back("Mugfit_normchi2");           hbins.push_back(40); hlow.push_back(   0.); hup.push_back(20.);
  histonames.push_back("Mugfit_validSTAHits");       hbins.push_back(10); hlow.push_back(   0.); hup.push_back(10.);
  histonames.push_back("MunumberOfMatchedStations"); hbins.push_back(10); hlow.push_back(   0.); hup.push_back(10.);
  histonames.push_back("Munlayers");                 hbins.push_back(20); hlow.push_back(   0.); hup.push_back(20.);
  histonames.push_back("Muchi2LocalPosition");       hbins.push_back(40); hlow.push_back(   0.); hup.push_back(40.);
  histonames.push_back("MutrkKink");                 hbins.push_back(50); hlow.push_back(   0.); hup.push_back(50.);
  histonames.push_back("MusegmCompatibility");       hbins.push_back(35); hlow.push_back(   0.); hup.push_back(1.4);
  histonames.push_back("MuvalidPixelHits");          hbins.push_back( 5); hlow.push_back(   0.); hup.push_back(5. );
  histonames.push_back("MuPt");                      hbins.push_back(30); hlow.push_back(   0.); hup.push_back(600);
  histonames.push_back("MuEta");                     hbins.push_back(60); hlow.push_back(   3.); hup.push_back(3. );
  histonames.push_back("MuPhi");                     hbins.push_back(32); hlow.push_back( -3.2); hup.push_back(3.2);
  histonames.push_back("MuCharge");                  hbins.push_back( 6); hlow.push_back(  -2.); hup.push_back(4. );
  histonames.push_back("MT");                        hbins.push_back(45); hlow.push_back(   0.); hup.push_back(450);
  histonames.push_back("ZPt");                       hbins.push_back(30); hlow.push_back(   0.); hup.push_back(600);
  histonames.push_back("Z_Pt");                      hbins.push_back(30); hlow.push_back(   0.); hup.push_back(600);
  histonames.push_back("ZEta");                      hbins.push_back(50); hlow.push_back(  -5.); hup.push_back(5. );
  histonames.push_back("ZPhi");                      hbins.push_back(32); hlow.push_back( -3.2); hup.push_back(3.2);
  histonames.push_back("DPhill");                    hbins.push_back(32); hlow.push_back(   0.); hup.push_back(3.2);
  histonames.push_back("DEtall");                    hbins.push_back(50); hlow.push_back(   0.); hup.push_back(5. );
  histonames.push_back("DRll");                      hbins.push_back(32); hlow.push_back(   0.); hup.push_back(6.4);
  histonames.push_back("MyMuPt");                      hbins.push_back(30); hlow.push_back(   0.); hup.push_back(600);
  histonames.push_back("MyMuEta");                     hbins.push_back(60); hlow.push_back(   3.); hup.push_back(3. );
  histonames.push_back("MyMuPhi");                     hbins.push_back(32); hlow.push_back( -3.2); hup.push_back(3.2);
  histonames.push_back("MyMuCharge");                  hbins.push_back( 6); hlow.push_back(  -2.); hup.push_back(4. );
  histonames.push_back("MET");                      hbins.push_back(40); hlow.push_back(   0.); hup.push_back(200);
  histonames.push_back("HT");                      hbins.push_back(40); hlow.push_back(   0.); hup.push_back(400);
  histonames.push_back("NJets");                      hbins.push_back(10); hlow.push_back(   0.); hup.push_back(10);
  histonames.push_back("NBJets");                      hbins.push_back(5); hlow.push_back(   0.); hup.push_back(5);
	      
  for(unsigned int i = 0; i<histonames.size(); ++i){
    int nbins = hbins[i];
    string mapname;
    for(unsigned int j = 0; j<11; ++j){
      string prefix = "";
      if(j==1) prefix = "NJ0_";
      else if(j==2) prefix = "NJ1_";
      else if(j==3) prefix = "NJ2_";
      else if(j==4) prefix = "NJge3_";
      else if(j==5) prefix = "NB0_";
      else if(j==6) prefix = "NBge1_";
      else if(j==7) prefix = "HTge100_";
      else if(j==8) prefix = "METge50_";
      else if(j==9) prefix = "METge25_";
      else if(j==10) prefix = "HTge150_";
      mapname = prefix + histonames[i]+"_"+skimFilePrefix;
      //cout << mapname << endl;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", nbins, hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
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

    int nleps = 1;
    myevt p;//previous event
    myevt c;//current event
    resetEvent(p);
    resetEvent(c);
    vector<myevt> mu; mu.clear();

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
      if(evt_isRealData()&& !goodrun(evt_run(), evt_lumiBlock()) ) continue;

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
      c.dilep_mass   = dilep_mass();
      c.dilep_p4   = dilep_p4();
      c.passes_SS_tight_noiso_v3 = passes_SS_tight_noiso_v3();
      c.passes_SS_fo_noiso_v3 = passes_SS_fo_noiso_v3();
      c.passes_POG_looseID = passLooseID(c);
      c.passes_POG_mediumID = passMediumID(c);
      c.passes_POG_tightID = passTightID(c);
     

      float weight = p.scale1fb*0.0403;
      if(skimFilePrefix=="DY_M10_50ns") weight *= 1.11;
      if(p.evt_isRealData) weight = 1.;
      if((skimFilePrefix=="SingleMuon"||skimFilePrefix=="DoubleMuon")&&fabs(weight-1.)>=0.001) cout <<__LINE__<< endl;
      // Analysis Code

      if(sameEvent(p,c)) { ++nleps; }


      if(((!sameEvent(p,c))||(nEventsChain==nEventsTotal)) && mu.size()>0) {

	int nbs = 0;
	int njs = 0;
	float HT = 0;
	double muovind[mu.size()];
	for(unsigned int i = 0; i<mu.size();++i){
	  muovind[i] = -1;
	  float minDR = 9999;
	  if(mu[i].jets.size()!=p.jets.size()) cout << "ERROR " << mu[i].jets.size() << " " << p.jets.size() << endl;
	  for(unsigned int j = 0; j<p.jets.size();++j){
	    float myDR = deltaR(mu[i].p4,p.jets[j]);
	    if(myDR<0.4 && myDR<minDR){
	      minDR = myDR;
	      muovind[i] = j;
	    }
	  }
	}
	for(unsigned int i = 0; i<p.jets.size();++i){
	  bool isoverlap = false;
	  for(unsigned int j = 0; j<mu.size();++j){
	    if(muovind[j]==i){
	      isoverlap = true;
	      break;
	    }
	  }
	  if(isoverlap) continue;
	  if(p.jets[i].Pt()<30) continue;
	  if(fabs(p.jets[i].Eta()>2.4)) continue;
	  ++njs;
	  HT += p.jets[i].Pt();
	  if(p.jets_disc[i]>0.890) ++nbs;
	}
      
	bool triggerbool2mu = false;
	bool triggerbool1mu = false;
	//now I reached full event!
	if(mu.size()>1) mu = sortbypt(mu);
	for(unsigned int i = 0; i<mu.size();++i){
	  if(mu[i].evt_isRealData) triggerbool2mu = triggerbool2mu || mu[i].HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ || mu[i].HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
	  if(mu[i].evt_isRealData) triggerbool1mu = triggerbool1mu || mu[i].HLT_IsoMu24_eta2p1 || mu[i].HLT_IsoTkMu24_eta2p1 || mu[i].HLT_IsoMu27 || mu[i].HLT_IsoTkMu27 || mu[i].HLT_IsoMu20 || mu[i].HLT_IsoMu20;
	}
	if(!p.evt_isRealData){ triggerbool2mu = true; triggerbool1mu = true;}
	if(mu.size()==2){
	  triggerbool2mu = triggerbool2mu&&mu[0].p4.Pt()>20.&&fabs(mu[0].p4.Eta())<2.1&&mu[0].p4.Pt()>20.&&fabs(mu[0].p4.Eta())<2.1;//two muons passing nominal trigger w/o iso and dZ
	  triggerbool1mu = triggerbool1mu&&((mu[0].p4.Pt()>30.&&fabs(mu[0].p4.Eta())<2.1)||(mu[1].p4.Pt()>30.&&fabs(mu[1].p4.Eta())<2.1));//one muon passing nominal trigger w/o iso
	  LorentzVector Z = (mu[0].p4+mu[1].p4);
	  if((triggerbool1mu||triggerbool2mu)&& mu[0].passes_POG_tightID&&mu[1].passes_POG_tightID&&mu[0].miniisoDB<0.2&&mu[1].miniisoDB<0.2&&
	      fabs(mu[0].dZ)<0.1&&fabs(mu[1].dZ)<0.1&&fabs(mu[0].dxyPV)<0.02&&fabs(mu[1].dxyPV)<0.02){
	    //cout << "have a dilepton event: Z pt " << Z.Pt() << " and mass " << Z.M() << endl;
	    histos["Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(njs==0) histos["NJ0_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    else if(njs==1) histos["NJ1_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    else if(njs==2) histos["NJ2_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    else histos["NJge3_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(nbs==0)  histos["NB0_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    else  histos["NBge1_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(HT>100.) histos["HTge100_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(HT>150.) histos["HTge150_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(p.evt_pfmet>50.) histos["METge50_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(p.evt_pfmet>25.) histos["METge25_Mll_"+skimFilePrefix]->Fill(Z.M(),weight);
	    if(Z.M()>75.&&Z.M()<105){
	      histos["ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
	      histos["ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
	      histos["ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
	      histos["DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
	      histos["DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
	      histos["DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      histos["MET_"+skimFilePrefix]->Fill(p.evt_pfmet,weight);
	      histos["HT_"+skimFilePrefix]->Fill(HT,weight);
	      histos["NJets_"+skimFilePrefix]->Fill(njs,weight);
	      histos["NBJets_"+skimFilePrefix]->Fill(nbs,weight);
	      if(njs==0){
		histos["NJ0_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NJ0_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NJ0_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NJ0_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NJ0_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NJ0_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } else if(njs==1){
		histos["NJ1_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NJ1_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NJ1_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NJ1_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NJ1_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NJ1_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } else if(njs==2){
		histos["NJ2_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NJ2_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NJ2_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NJ2_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NJ2_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NJ2_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } else {
		histos["NJge3_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NJge3_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NJge3_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NJge3_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NJge3_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NJge3_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } if(nbs==0){
		histos["NB0_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NB0_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NB0_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NB0_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NB0_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NB0_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } else {
		histos["NBge1_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["NBge1_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["NBge1_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["NBge1_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["NBge1_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["NBge1_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } if(HT>100.){
		histos["HTge100_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["HTge100_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["HTge100_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["HTge100_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["HTge100_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["HTge100_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } if(HT>150.){
		histos["HTge150_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["HTge150_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["HTge150_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["HTge150_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["HTge150_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["HTge150_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } if(p.evt_pfmet>50.){
		histos["METge50_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["METge50_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["METge50_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["METge50_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["METge50_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["METge50_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);
	      } if(p.evt_pfmet>25.){
		histos["METge25_ZPt_"+skimFilePrefix]->Fill(Z.Pt(),weight);
		histos["METge25_ZEta_"+skimFilePrefix]->Fill(Z.Eta(),weight);
		histos["METge25_ZPhi_"+skimFilePrefix]->Fill(Z.Phi(),weight);
		histos["METge25_DPhill_"+skimFilePrefix]->Fill(getdphi(mu[0].p4.Phi(),mu[1].p4.Phi()),weight);
		histos["METge25_DEtall_"+skimFilePrefix]->Fill(fabs(mu[0].p4.Eta()-mu[1].p4.Eta()),weight);
		histos["METge25_DRll_"+skimFilePrefix]->Fill(dRbetweenVectors(mu[0].p4,mu[1].p4),weight);	
	      }
	      for(unsigned int i = 0; i<mu.size(); ++i){
		float mucharge = 0; if(mu[i].id==13) mucharge = -1; else if(mu[i].id==-13) mucharge = +1; 
		histos["MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		histos["MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		histos["MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		histos["MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		if(njs==0){
		  histos["NJ0_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NJ0_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NJ0_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NJ0_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} else if(njs==1){
		  histos["NJ1_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NJ1_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NJ1_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NJ1_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} else if(njs==2){
		  histos["NJ2_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NJ2_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NJ2_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NJ2_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} else {
		  histos["NJge3_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NJge3_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NJge3_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NJge3_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} if(nbs==0){
		  histos["NB0_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NB0_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NB0_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NB0_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} else {
		  histos["NBge1_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["NBge1_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["NBge1_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["NBge1_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} if(HT>100.){
		  histos["HTge100_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["HTge100_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["HTge100_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["HTge100_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} if(HT>150.){
		  histos["HTge150_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["HTge150_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["HTge150_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["HTge150_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} if(p.evt_pfmet>50.){
		  histos["METge50_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["METge50_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["METge50_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["METge50_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		} if(p.evt_pfmet>25.){
		  histos["METge25_MuPt_"+skimFilePrefix]->Fill(mu[i].p4.Pt(),weight);
		  histos["METge25_MuEta_"+skimFilePrefix]->Fill(mu[i].p4.Eta(),weight);
		  histos["METge25_MuPhi_"+skimFilePrefix]->Fill(mu[i].p4.Phi(),weight);
		  histos["METge25_MuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
		}
	      }
	    }
	  }
	  if((triggerbool1mu||triggerbool2mu)&& mu[0].passes_POG_tightID&&mu[1].passes_POG_tightID&&fabs(mu[0].dZ)<0.1&&fabs(mu[1].dZ)<0.1&&fabs(mu[0].dxyPV)<0.02&&fabs(mu[1].dxyPV)<0.02){
	    if(Z.M()>75.&&Z.M()<105){
	      for(unsigned int i = 0; i<mu.size(); ++i){
		histos["MuRelIso03_"+skimFilePrefix]->Fill(mu[i].RelIso03,weight);
		histos["MuRelIso03EA_"+skimFilePrefix]->Fill(mu[i].RelIso03EA,weight);
		histos["MuRelIso03DB_"+skimFilePrefix]->Fill(mu[i].RelIso03DB,weight);
		histos["MuMiniIsoEA_"+skimFilePrefix]->Fill(mu[i].miniiso,weight);
		histos["MuMiniIsoDB_"+skimFilePrefix]->Fill(mu[i].miniisoDB,weight);
		histos["MuRelIso04_"+skimFilePrefix]->Fill(mu[i].reliso04,weight);
		histos["MuAnnulus04_"+skimFilePrefix]->Fill(mu[i].annulus04,weight);
		if(mu[0].mt>30&&mu[0].mt>30){
		  histos["MuRelIso03_MT30_"+skimFilePrefix]->Fill(mu[i].RelIso03,weight);
		  histos["MuRelIso03EA_MT30_"+skimFilePrefix]->Fill(mu[i].RelIso03EA,weight);
		  histos["MuRelIso03DB_MT30_"+skimFilePrefix]->Fill(mu[i].RelIso03DB,weight);
		  histos["MuMiniIsoEA_MT30_"+skimFilePrefix]->Fill(mu[i].miniiso,weight);
		  histos["MuMiniIsoDB_MT30_"+skimFilePrefix]->Fill(mu[i].miniisoDB,weight);
		  histos["MuRelIso04_MT30_"+skimFilePrefix]->Fill(mu[i].reliso04,weight);
		  histos["MuAnnulus04_MT30_"+skimFilePrefix]->Fill(mu[i].annulus04,weight);
		}
	      }
	    }
	  }
	  if((triggerbool1mu||triggerbool2mu)&& mu[0].passes_POG_tightID&&mu[1].passes_POG_tightID&&mu[0].miniisoDB<0.2&&mu[1].miniisoDB<0.2){
	    if(Z.M()>75.&&Z.M()<105){
	      for(unsigned int i = 0; i<mu.size(); ++i){
		histos["Mud0_"+skimFilePrefix]->Fill(mu[i].dxyPV,weight);
		histos["MudZ_"+skimFilePrefix]->Fill(mu[i].dZ,weight);
		histos["MuIP3d_"+skimFilePrefix]->Fill(mu[i].ip3d,weight);
	      }
	    }
	  }
	  if((triggerbool1mu||triggerbool2mu)&& mu[0].passes_POG_looseID&&mu[1].passes_POG_looseID&&mu[0].miniisoDB<0.2&&mu[1].miniisoDB<0.2&&
	      fabs(mu[0].dZ)<0.1&&fabs(mu[1].dZ)<0.1&&fabs(mu[0].dxyPV)<0.02&&fabs(mu[1].dxyPV)<0.02){
	    if(Z.M()>75.&&Z.M()<105){
	      for(unsigned int i = 0; i<mu.size(); ++i){
		if(mu[i].passes_POG_tightID) histos["MuID_"+skimFilePrefix]->Fill(3.,weight);
		else if(mu[i].passes_POG_mediumID) histos["MuID_"+skimFilePrefix]->Fill(2.,weight);
		else if(mu[i].passes_POG_looseID) histos["MuID_"+skimFilePrefix]->Fill(1.,weight);
		histos["MuvalidFraction_"+skimFilePrefix]->Fill((float)mu[i].validHits/((float)(mu[i].validHits+mu[i].lostHits+mu[i].exp_innerlayers+mu[i].exp_outerlayers)),weight);
		if(mu[i].gfit_ndof>0) histos["Mugfit_normchi2_"+skimFilePrefix]->Fill(mu[i].gfit_chi2/mu[i].gfit_ndof, weight);
		histos["Mugfit_validSTAHits_"+skimFilePrefix]->Fill(mu[i].gfit_validSTAHits,weight);
		histos["MunumberOfMatchedStations_"+skimFilePrefix]->Fill(mu[i].numberOfMatchedStations,weight);
		histos["MuvalidPixelHits_"+skimFilePrefix]->Fill(mu[i].validPixelHits,weight);
		histos["Munlayers_"+skimFilePrefix]->Fill(mu[i].nlayers,weight);
		histos["Muchi2LocalPosition_"+skimFilePrefix]->Fill(mu[i].chi2LocalPosition,weight);
		histos["MutrkKink_"+skimFilePrefix]->Fill(mu[i].trkKink,weight);
		histos["MusegmCompatibility_"+skimFilePrefix]->Fill(mu[i].segmCompatibility,weight);
	      }
	    }
	  }
	}//2 muons
	else if(mu.size()==1){
	  triggerbool1mu = triggerbool1mu&&((mu[0].p4.Pt()>30.&&fabs(mu[0].p4.Eta())<2.1));//one muon passing nominal trigger w/o iso
	  if(triggerbool1mu&&mu[0].passes_POG_tightID&&mu[0].miniisoDB<0.2&&fabs(mu[0].dZ)<0.1&&fabs(mu[0].dxyPV)<0.02&&mu[0].mt>40){//1 mu events.
	    float mucharge = 0; if(mu[0].id==13) mucharge = -1; else if(mu[0].id==-13) mucharge = +1; 
	    histos["MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	    histos["MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	    histos["MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	    histos["MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	    histos["MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
	    if(njs==0){
	      histos["NJ0_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NJ0_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NJ0_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NJ0_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NJ0_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);
	    } else if(njs==1){
	      histos["NJ1_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NJ1_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NJ1_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NJ1_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NJ1_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } else if(njs==2){
	      histos["NJ2_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NJ2_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NJ2_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NJ2_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NJ2_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } else {
	      histos["NJge3_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NJge3_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NJge3_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NJge3_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NJge3_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } if(nbs==0){
	      histos["NB0_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NB0_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NB0_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NB0_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NB0_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } else {
	      histos["NBge1_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["NBge1_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["NBge1_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["NBge1_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["NBge1_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } if(HT>100.){
	      histos["HTge100_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["HTge100_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["HTge100_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["HTge100_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["HTge100_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } if(HT>150.){
	      histos["HTge150_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["HTge150_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["HTge150_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["HTge150_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["HTge150_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } if(p.evt_pfmet>50.){
	      histos["METge50_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["METge50_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["METge50_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["METge50_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["METge50_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    } if(p.evt_pfmet>25.){
	      histos["METge25_MT_"+skimFilePrefix]->Fill(mu[0].mt,weight);
	      histos["METge25_MyMuPt_"+skimFilePrefix]->Fill(mu[0].p4.Pt(),weight);
	      histos["METge25_MyMuEta_"+skimFilePrefix]->Fill(mu[0].p4.Eta(),weight);
	      histos["METge25_MyMuPhi_"+skimFilePrefix]->Fill(mu[0].p4.Phi(),weight);
	      histos["METge25_MyMuCharge_"+skimFilePrefix]->Fill(mucharge,weight);	      
	    }
	  }
	}
      }
      if(!sameEvent(p,c)){
	//finally start new event.
	if(abs(p.id)==13&&p.passes_POG_tightID&&p.miniisoDB<0.2&&fabs(p.dZ)<0.1&&fabs(p.dxyPV)<0.02&&p.dilep_mass>75.&&p.dilep_mass<105&&p.p4.Pt()>20&&fabs(p.p4.Eta())<2.1) {
	  if((p.evt_isRealData&&(p.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ || p.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ || p.HLT_IsoMu24_eta2p1 || p.HLT_IsoTkMu24_eta2p1 || p.HLT_IsoMu27 || p.HLT_IsoTkMu27 || p.HLT_IsoMu20 || p.HLT_IsoMu20))||(!p.evt_isRealData)){
	    histos["Z_Pt_"+skimFilePrefix]->Fill(p.dilep_p4.Pt(),weight);
	  }
	}
	mu.clear();
	nleps = 1;
      }
      if(currentrun!=c.evt_run) { cout << "This is run " << c.evt_run << endl; currentrun = c.evt_run; }
      bool skip = false;
      //if(c.evt_run!=251244&&c.evt_run!=251251&&c.evt_run!=251252) skip = true;
      if(abs(c.id)!=13) skip = true;
      else if(c.p4.Pt()<20.) skip = true;
      else if(fabs(c.p4.Eta())>2.1) skip = true;
      else if(!c.passes_POG_looseID) skip = true;
      //else if(fabs(c.dZ)>0.5) skip = true;
      //else if(fabs(c.dxyPV)>0.2) skip = true;
      //else if(c.miniisoDB>0.5) skip = true;
      if(!skip) { mu.push_back(c); }
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
  string filename = "rootfiles/first_20150727/Histos3_"+skimFilePrefix+".root";
  if(DCSonly) filename = "rootfiles/first_20150727/Histos3DCS_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
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
