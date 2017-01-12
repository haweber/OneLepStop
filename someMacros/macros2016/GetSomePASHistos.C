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
#include "TH1D.h"
#include "TH2D.h"

// CMS3
#include "CMS3_Data.cc"

//#include "/home/users/haweber/CORE/Tools/goodrun.h"
//#include "/home/users/haweber/CORE/Tools/goodrun.cc"
//#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
//#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
//#include "/home/users/haweber/CORE/Tools/badEventFilter.h"
//#include "/home/users/haweber/CORE/Tools/badEventFilter.cc"

//MT2 variants

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins;  hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup;  hup.clear();

  histonames.push_back("MT");                       hbins.push_back(18); hlow.push_back( 50.); hup.push_back(500);
  histonames.push_back("MT_harder");                hbins.push_back(18); hlow.push_back( 50.); hup.push_back(500);
  histonames.push_back("MT2W");                     hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("MT2W_4j");                  hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("MET");                      hbins.push_back(26); hlow.push_back(100.); hup.push_back(750);
  histonames.push_back("MET_3j");                   hbins.push_back(26); hlow.push_back(100.); hup.push_back(750);
  histonames.push_back("MET_4j");                   hbins.push_back(26); hlow.push_back(100.); hup.push_back(750);
  histonames.push_back("MET_hMT2W");                hbins.push_back(26); hlow.push_back(100.); hup.push_back(750);
  histonames.push_back("MET_hMT2W_4j");             hbins.push_back(26); hlow.push_back(100.); hup.push_back(750);
  histonames.push_back("MinDPhi");                  hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MinDPhi_harder");           hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MinDPhi_3j");               hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MinDPhi_4j");               hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("NJets");                    hbins.push_back(6 ); hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("NJets_hard");               hbins.push_back(6 ); hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("NJets_harder");             hbins.push_back(6 ); hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("tMod");                     hbins.push_back(30); hlow.push_back(-15.); hup.push_back(15);
  histonames.push_back("tMod_2j");                  hbins.push_back(30); hlow.push_back(-15.); hup.push_back(15);

  for(unsigned int b = 0; b<2; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
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
  
  TH1D* counterhist;
  double count1(0), count2(0);
  double count3(0), count4(0);

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


      if(nvtxs()<0)               continue;
      if(ngoodleps()!=1)          continue;
      if(nvetoleps()!=1)          continue;
      if(!PassTrackVeto_v3())     continue;
      if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      if(ngoodbtags()<1)          continue;
      if(pfmet()<100)             continue;
      if(mt_met_lep()< 50)        continue;
      //if(pfmet()<250)             continue;
      //if(mt_met_lep()<150)        continue;
      //if(mindphi_met_j1_j2()<0.8) continue;

      string samplename = skimFilePrefix;
      if(skimFilePrefix=="TTbar"){
	if(is2lep() ) samplename = "TTbar2l";
	else if(is1lepFromTop() ) samplename = "TTbar1l";
	else continue;
      }

      if(ngoodjets()>=2 && mindphi_met_j1_j2()>0.8 && pfmet()>250) histos["MT_"+samplename]->Fill(mt_met_lep(),weight);
      if(ngoodjets()>=2 && mindphi_met_j1_j2()>0.8 && pfmet()>350) histos["MT_harder_"+samplename]->Fill(mt_met_lep(),weight);
      if(ngoodjets()>=3 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150) histos["MT2W_"+samplename]->Fill(MT2W(),weight);
      if(ngoodjets()>=4 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150) histos["MT2W_4j_"+samplename]->Fill(MT2W(),weight);
      if(ngoodjets()>=2 && mindphi_met_j1_j2()>0.8 && mt_met_lep()>150) histos["MET_"+samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=3 && mindphi_met_j1_j2()>0.8 && mt_met_lep()>150) histos["MET_3j_"+samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=4 && mindphi_met_j1_j2()>0.8 && mt_met_lep()>150) histos["MET_4j_"+samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=3 && mindphi_met_j1_j2()>0.8 && mt_met_lep()>150 && MT2W()>200) histos["MET_hMT2W_"+samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=4 && mindphi_met_j1_j2()>0.8 && mt_met_lep()>150 && MT2W()>200) histos["MET_hMT2W_4j_"+samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=2 && pfmet()>250 && mt_met_lep()>150) histos["MinDPhi_"+samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(ngoodjets()>=2 && pfmet()>350 && mt_met_lep()>150) histos["MinDPhi_harder_"+samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(ngoodjets()>=3 && pfmet()>250 && mt_met_lep()>150) histos["MinDPhi_3j_"+samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(ngoodjets()>=4 && pfmet()>250 && mt_met_lep()>150) histos["MinDPhi_4j_"+samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(ngoodjets()>=2 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150) histos["NJets_"+samplename]->Fill(ngoodjets(),weight);
      if(ngoodjets()==2 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150 && topnessMod()>6.4) histos["NJets_hard_"+samplename]->Fill(ngoodjets(),weight);
      if(ngoodjets()>=3 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150 && MT2W()>200)       histos["NJets_hard_"+samplename]->Fill(ngoodjets(),weight);
      if(ngoodjets()==2 && mindphi_met_j1_j2()>0.8 && pfmet()>350 && mt_met_lep()>150 && topnessMod()>6.4) histos["NJets_harder_"+samplename]->Fill(ngoodjets(),weight);
      if(ngoodjets()>=3 && mindphi_met_j1_j2()>0.8 && pfmet()>350 && mt_met_lep()>150 && MT2W()>200)       histos["NJets_harder_"+samplename]->Fill(ngoodjets(),weight);
      if(ngoodjets()>=2 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150) histos["tMod_"+samplename]->Fill(topnessMod(),weight);
      if(ngoodjets()==2 && mindphi_met_j1_j2()>0.8 && pfmet()>250 && mt_met_lep()>150) histos["tMod_2j_"+samplename]->Fill(topnessMod(),weight);

    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  string filename = "rootfiles/PASfigure.root";
  TFile *f = new TFile(filename.c_str(),"update");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  delete f;
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
