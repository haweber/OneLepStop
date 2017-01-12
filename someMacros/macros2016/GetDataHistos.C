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
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

// CMS3
//#include "CMS3_Data.cc"
#include "CMS3_dataFU.cc"

#include "/home/users/haweber/CORE/Tools/goodrun.h"
#include "/home/users/haweber/CORE/Tools/goodrun.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
#include "/home/users/haweber/CORE/Tools/badEventFilter.h"
#include "/home/users/haweber/CORE/Tools/badEventFilter.cc"

//MT2 variants

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  int count = 0; int badcount = 0;
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1D*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins;  hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup;  hup.clear();

  histonames.push_back("Data");       hbins.push_back(9); hlow.push_back(  0.); hup.push_back(9.5);
  histonames.push_back("Data_el");       hbins.push_back(9); hlow.push_back(  0.); hup.push_back(9.5);
  histonames.push_back("Data_mu");       hbins.push_back(9); hlow.push_back(  0.); hup.push_back(9.5);


  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1D(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

  const char* json_file = "json_files/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_v2.txt";
  set_goodrun_file_json(json_file);

  //metfilters
  eventFilter metFilterTxt; 
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_MET_csc2015.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_SingleElectron_csc2015.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_SingleMuon_csc2015.txt");
  // new lists: supposed to include above but do not always
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/MET_csc2015.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleElectron_csc2015.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleMuon_csc2015.txt");
  // not all samples have events which failed the ecal SC filter
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/MET_ecalscn1043093.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleElectron_ecalscn1043093.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleMuon_ecalscn1043093.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/csc2015_Dec01.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/ecalscn1043093_Dec01.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/badResolutionTrack_Jan13.txt");
  metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/muonBadTrack_Jan13.txt");
  //metFilterTxt.loadBadEventList("badResolutionTrack_Jan13.txt");
  //metFilterTxt.loadBadEventList("muonBadTrack_Jan13.txt");
    
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

      bool triggered = false;
      if(HLT_MET170()>0) triggered = true;
      if(lep1_is_el() && HLT_SingleEl23()>0) triggered = true;
      if(lep1_is_mu() && HLT_SingleMu20()>0) triggered = true;
      if(!triggered) continue;//trigger requirement

      if( is_data() && !goodrun(run(), ls()) ) continue;
      if( is_data() ) {//remove duplicates
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      
      float weight = cms3.scale1fb()*2.26;
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;

      //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      //metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());
      int NSLeps = 0;
      int NAddVetoLeps = 0;
      if(lep1_is_mu()){
	if(lep1_pt()>20&&fabs(lep1_eta())<2.4) {++NSLeps;}
      } else if (lep1_is_el()){
	if(lep1_pt()>20&&fabs(lep1_eta())<1.4442) {++NSLeps; }
      } if(lep2_is_mu()){
	if(lep2_pt()>20&&fabs(lep2_eta())<2.4) {++NSLeps;}
      } else if (lep2_is_el()){
	if(lep2_pt()>20&&fabs(lep2_eta())<1.4442) {++NSLeps; }
      }
      if(lep2_is_mu()){
	if(lep2_pt()>10&&fabs(lep2_eta())<2.4) {++NAddVetoLeps;}
      } else if (lep2_is_el()){
	if(lep2_pt()>10&&fabs(lep2_eta())<2.4) {++NAddVetoLeps; }
      }

      bool filt_badevents = false;
      filt_badevents = !(metFilterTxt.eventFails(run(), ls(), evt()));
      bool filter_badevents = false;
      if(!filt_badevents)     filter_badevents = true;
      /*
      if(!filt_cscbeamhalo()) filter_badevents = true;
      if(!filt_eebadsc())     filter_badevents = true;
      if(!filt_goodvtx())     filter_badevents = true;
      if(!filt_ecallaser())   filter_badevents = true;
      if(!filt_ecaltp())      filter_badevents = true;
      if(!filt_hcallaser())   filter_badevents = true;
      if(!filt_met())         filter_badevents = true;
      //if(!filt_trkfail())     filter_badevents = true;
      if(!filt_trkPOG())      filter_badevents = true;
      if(!filt_trkPOG_tmc())  filter_badevents = true;
      if(!filt_trkPOG_tms())  filter_badevents = true;
      if(!filt_hbhenoise())   filter_badevents = true;
      */
      if(!filt_hbhenoise())   filter_badevents = true;
      if(!filt_cscbeamhalo()) filter_badevents = true;
      if(!filt_goodvtx())     filter_badevents = true;
      if(!filt_eebadsc())     filter_badevents = true;

      /*
      if((run()==260431&&ls()==72&&evt()==123209001)||(run()==258712&&ls()==484&&evt()==758826409)||(run()==260538&&ls()==196&&evt()==330855682)){
	cout << run() << ":" << ls() << ":" << evt() << " " << "filt_badevents " << filt_badevents << " filt_cscbeamhalo " << filt_cscbeamhalo() << " filt_eebadsc " << filt_eebadsc() << " filt_goodvtx " << filt_goodvtx() << " filt_goodvtx " << filt_goodvtx() << " filt_hbhenoise " << filt_hbhenoise() << endl;
	cout << "NJ " << ngoodjets() << " NB " << ngoodbtags() << " NLeps " << ngoodleps() << " nveto " << nvetoleps() << " track " << PassTrackVeto_v3() << " tau " << PassTauVeto() << " MT " << mt_met_lep() << " MET " << pfmet() << " MDPhi " << mindphi_met_j1_j2() << " MT2W " << MT2W() << " tmod " << topnessMod() << endl;
	for(int i = 0; i<ngoodjets(); ++i){
	  cout << "Pt " << ak4pfjets_pt()[i] << " Eta " << ak4pfjets_eta()[i] << " Phi " << ak4pfjets_phi()[i] << " M " << ak4pfjets_mass()[i] << endl;
	}
      }
      */
      if((run()==259685&&ls()==408&&evt()==724276930)||(run()==259686&&ls()==104&&evt()==193933611)||(run()==260576&&ls()==328&&evt()==675758481)){
	cout << run() << ":" << ls() << ":" << evt() << " " << "filt_badevents " << filt_badevents << " filt_cscbeamhalo " << filt_cscbeamhalo() << " filt_eebadsc " << filt_eebadsc() << " filt_goodvtx " << filt_goodvtx() << " filt_goodvtx " << filt_goodvtx() << " filt_hbhenoise " << filt_hbhenoise() << endl;
	cout << "NJ " << ngoodjets() << " NB " << ngoodbtags() << " NLeps " << ngoodleps() << " nveto " << nvetoleps() << " track " << PassTrackVeto_v3() << " tau " << PassTauVeto() << " MT " << mt_met_lep() << " MET " << pfmet() << " MDPhi " << mindphi_met_j1_j2() << " MT2W " << MT2W() << " tmod " << topnessMod() << endl;
	for(int i = 0; i<ngoodjets(); ++i){
	  cout << "Pt " << ak4pfjets_pt()[i] << " Eta " << ak4pfjets_eta()[i] << " Phi " << ak4pfjets_phi()[i] << " M " << ak4pfjets_mass()[i] << endl;
	}
	cout << "triggered MET " << HLT_MET170() << " el " << HLT_SingleEl23() << " mu " << HLT_SingleMu20() << endl;
      }



      //cout << "filt_badevents " << filt_badevents << " filt_cscbeamhalo " << filt_cscbeamhalo() << " filt_eebadsc " << filt_eebadsc() << " filt_goodvtx " << filt_goodvtx() << " filt_goodvtx " << filt_goodvtx() << " filt_ecallaser " << filt_ecallaser() << " filt_ecaltp " << filt_ecaltp() << " filt_hcallaser " << filt_hcallaser() << " filt_met " << filt_met() << " filt_trkfail " << filt_trkfail() << " filt_trkPOG_tmc " << filt_trkPOG_tmc() << " filt_trkPOG_tms " << filt_trkPOG_tms() << " filt_hbhenoise " << filt_hbhenoise() << endl;

      if(filter_badevents) continue;
      
      if(nvtxs()<0)               continue;
      if(ngoodleps()!=1)          continue;
      if(nvetoleps()!=1)          continue;
      if(!PassTrackVeto_v3())     continue;
      if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      if(ngoodbtags()<1)          continue;
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;

      int SR = -1;
      if(ngoodjets()>=4){
	if(MT2W()<=200){
	  if(pfmet()>325) SR = 6;
	  else SR = 5;
	} else { //high MT2W
	  if(pfmet()>450) SR = 9;
	  else if(pfmet()>350) SR = 8;
	  else SR = 7;
	}
      } else if(ngoodjets()==3 && MT2W()>200) {
	if(pfmet()>350) SR = 4;
	else SR = 3;
      } else if(ngoodjets()==2&&topnessMod()>6.4) { //2 or 3 jets
	if(pfmet()>350) SR = 2;
	else SR = 1;
      }

      if(SR>=0){
	if(filt_hbheisonoise()) { cout <<"good event " << run() << ":" << ls() << ":" << evt() << endl; ++count;}
	if(!filt_hbheisonoise()){ cout << "this event is additionally filtered: ";
	  cout << run() << ":" << ls() << ":" << evt() << " SR " << SR << " is " << (lep1_is_mu() ? "mu" : "el") << endl; ++badcount;
	continue;}
	histos["Data"]->Fill(SR,1);
	if(lep1_is_mu()) histos["Data_mu"]->Fill(SR,1);
	if(lep1_is_el()) histos["Data_el"]->Fill(SR,1);
      }

    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  string filename = "rootfiles/DATAyield_2p3fbinv_.root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  cout << count << " " << badcount << endl;

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
