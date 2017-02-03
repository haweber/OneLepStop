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
#include <sstream>
#include <iostream>
#include <fstream>

// CMS3
//#include "CMS3_old20150505.cc"
//#include "CMS3_fuckingsync.cc"
#include "CMS3_Moriond17.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
#include "/home/users/haweber/CORE/Tools/goodrun.h"
#include "/home/users/haweber/CORE/Tools/goodrun.cc"

//MT2 variants

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float dPhibetweenVectors(float phi1,float phi2 ){                                                                                                              
  return fabs(std::min(float(fabs(phi1-phi2)),float(2*M_PI-fabs(phi1-phi2))));
}

float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

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

  histonames.push_back("SR_Data");        hbins.push_back(27); hlow.push_back(  0.); hup.push_back(27);
  histonames.push_back("cSR_Data");       hbins.push_back( 4); hlow.push_back(  0.); hup.push_back( 4);

  std::ostringstream* fLogStreamSR1     = 0;
  fLogStreamSR1 = new std::ostringstream();
  std::ostringstream* fLogStreamSR2     = 0;
  fLogStreamSR2 = new std::ostringstream();
  std::ostringstream* fLogStreamSR3     = 0;
  fLogStreamSR3 = new std::ostringstream();

  std::ostringstream* fLogStreamcSR1     = 0;
  fLogStreamcSR1 = new std::ostringstream();
  std::ostringstream* fLogStreamcSR2     = 0;
  fLogStreamcSR2 = new std::ostringstream();
  std::ostringstream* fLogStreamcSR3     = 0;
  fLogStreamcSR3 = new std::ostringstream();

  std::ostringstream* tfLogStreamSR1     = 0;
  tfLogStreamSR1 = new std::ostringstream();
  std::ostringstream* tfLogStreamSR2     = 0;
  tfLogStreamSR2 = new std::ostringstream();
  std::ostringstream* tfLogStreamSR3     = 0;
  tfLogStreamSR3 = new std::ostringstream();

  std::ostringstream* tfLogStreamcSR1     = 0;
  tfLogStreamcSR1 = new std::ostringstream();
  std::ostringstream* tfLogStreamcSR2     = 0;
  tfLogStreamcSR2 = new std::ostringstream();
  std::ostringstream* tfLogStreamcSR3     = 0;
  tfLogStreamcSR3 = new std::ostringstream();

  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

  const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  set_goodrun_file_json(json_file);


  unsigned int nEventsRunning = 0;
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

      if( is_data() && !goodrun(run(), ls()) ) continue;
      float weight = 1;

  
      if(nvtxs()<0)               continue;
      if(ngoodleps()!=1)          continue;
      if(nvetoleps()!=1)          continue;
      if(!PassTrackVeto())        continue;
      if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      if(ngoodbtags()<1)          continue;
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.5) continue;
      //if(lep1_is_mu())         ++something;
      //else                     ++somethingelse;

      if(is_data()) weight = 1.;
      if(is_data()){
	//if(!(HLT_MET()||HLT_SingleEl()||HLT_SingleMu())) continue;
	if(abs(lep1_pdgid())==11){
	  if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleEl())) continue;
	  //if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleEl())) continue;
	}
	if(abs(lep1_pdgid())==13){
	  if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleMu())) continue;
	  //if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleMu())) continue;
	}
      }
      if( is_data() ) {
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      if(is_data()){
	//if(filt_met()&&filt_badChargedCandidateFilter()&&filt_jetWithBadMuon()&&filt_pfovercalomet()) continue;
	  if(!filt_met()) continue;
	  if(!filt_badChargedCandidateFilter()) continue;
	  if(!filt_jetWithBadMuon()) continue;
	  if(!filt_pfovercalomet()) continue;
      }
      
      int SR = -1;
      int cSR = -1;
      if(mindphi_met_j1_j2()>0.8){
	if(ngoodjets()<=3&&topnessMod()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>600) SR = 4;
	    else if(pfmet()>450) SR = 3;
	    else if(pfmet()>350) SR = 2;
	    else if(pfmet()>250) SR = 1;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>600) SR = 7;
	    else if(pfmet()>450) SR = 6;
	    else if(pfmet()>250) SR = 5;
	  }
	} else if(ngoodjets()>=4&&topnessMod()<=0.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>650) SR = 12;
	    else if(pfmet()>550) SR = 11;
	    else if(pfmet()>450) SR = 10;
	    else if(pfmet()>350) SR = 9;
	    else if(pfmet()>250) SR = 8;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>550) SR = 16;
	    else if(pfmet()>450) SR = 15;
	    else if(pfmet()>350) SR = 14;
	    else if(pfmet()>250) SR = 13;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>0.&&topnessMod()<=10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>550) SR = 19;
	    else if(pfmet()>350) SR = 18;
	    else if(pfmet()>250) SR = 17;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>450) SR = 21;
	    else if(pfmet()>250) SR = 20;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>600) SR = 25;
	    else if(pfmet()>450) SR = 24;
	    else if(pfmet()>350) SR = 23;
	    else if(pfmet()>250) SR = 22;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>450) SR = 27;
	    else if(pfmet()>250) SR = 26;
	  }
	}
      }
      if(ngoodjets()>=5&&lep1_p4().Pt()<150.&&dPhibetweenVectors(pfmet_phi(),float(lep1_p4().Phi()))<2.0){
	if(     pfmet()>550) cSR = 4;
	else if(pfmet()>450) cSR = 3;
	else if(pfmet()>350) cSR = 2;
	else if(pfmet()>250) cSR = 1;	
      }
      if( SR>0) histos[ "SR_Data"]->Fill( SR-1);
      if(cSR>0) histos["cSR_Data"]->Fill(cSR-1);

      /*
      if(SR>0){
	if(pfmet()>450){
	  *fLogStreamSR3 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamSR3 << run() << ":" << ls() << ":" << evt() << " SR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	} else if(pfmet()>350){
	  *fLogStreamSR2 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamSR2 << run() << ":" << ls() << ":" << evt() << " SR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	} else if(pfmet()>250){
	  *fLogStreamSR1 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamSR1 << run() << ":" << ls() << ":" << evt() << " SR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	}
      }
      if(cSR>0){
	if(pfmet()>450){
	  *fLogStreamcSR3 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamcSR3 << run() << ":" << ls() << ":" << evt() << " cSR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	} else if(pfmet()>350){
	  *fLogStreamcSR2 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamcSR2 << run() << ":" << ls() << ":" << evt() << " cSR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	} else if(pfmet()>250){
	  *fLogStreamcSR1 << run() << ":" << ls() << ":" << evt() << endl;
	  *tfLogStreamcSR1 << run() << ":" << ls() << ":" << evt() << " cSR " << SR << " NJ:Mlb:tmod:MET:lepid " << ngoodjets() << ":" << Mlb_closestb() << ":" << topnessMod() << ":" << pfmet() << lep1_pdgid() << " " <<  currentFile->GetTitle() << endl;
	}
      }
      */
      /*
      if((run()==275311&&ls()==270&&evt()==344823933)||(run()==276831&&ls()==500&&evt()==863140218)||(run()==276870&&ls()==477&&evt()==767383604)||(run()==277096&&ls()==43&&evt()==80694131)||(run()==277096&&ls()==1977&&evt()==3390424116)||(run()==278018&&ls()==315&&evt()==585146502)||(run()==279715&&ls()==225&&evt()==296491244)||(run()==277127&&ls()==152&&evt()==291272708)||(run()==283353&&ls()==798&&evt()==1296209652)){
	cout << "run:ls:evt " << run() << ":" << ls() << ":" << evt() <<  " SRbin " << SR << endl;
	cout << "Triggered? " << "MET " << HLT_MET() << " Ele " << HLT_SingleEl() << " Muo " << HLT_SingleMu() << endl;
	cout << "NJ " << ngoodjets() << " NB " << ngoodbtags() << " nvetoleps " << nvetoleps() << " MDPhi(MET,j12) " << mindphi_met_j1_j2() << " tmod " << topnessMod() << " Mlb " << Mlb_closestb() << " MT " << mt_met_lep() <<  " pfMET " << pfmet() << " (phi " << pfmet_phi() << ") caloMET " << calomet() << " (phi " << calomet_phi() << ")" << endl;
	cout << "Lep ID " << lep1_pdgid() << " Pt " << lep1_p4().Pt() << " Eta " << lep1_p4().Eta() << " Phi " << lep1_p4().Phi() << endl;
	cout << "    passVeto/Loose/Medium/Tight " << lep1_passVeto() << "/" << lep1_passLooseID() << "/" << lep1_passMediumID() << "/" << lep1_passTightID() << endl;
	for(unsigned int j = 0; j<ak4pfjets_p4().size();++j){
	  cout << "jet" << j+1 << " Pt " << ak4pfjets_p4()[j].Pt() << " Eta " << ak4pfjets_p4()[j].Eta() << " Phi " << ak4pfjets_p4()[j].Phi() << " CSV " << ak4pfjets_CSV()[j] << endl;
	}
	cout << endl;
      }
      */
      /*
      if((run()==273725&&ls()==584&&evt()==892006781)){
      //if(SR>0){
	cout << "run:ls:evt " << run() << ":" << ls() << ":" << evt() <<  " SRbin " << SR << endl;
	cout << "Triggered? " << "MET " << HLT_MET() << " Ele " << HLT_SingleEl() << " Muo " << HLT_SingleMu() << endl;
	cout << "NJ " << ngoodjets() << " NB " << ngoodbtags() << " nvetoleps " << nvetoleps() << " MDPhi(MET,j12) " << mindphi_met_j1_j2() << " tmod " << topnessMod() << " Mlb " << Mlb_closestb() << " MT " << mt_met_lep() <<  " pfMET " << pfmet() << " (phi " << pfmet_phi() << ") caloMET " << calomet() << " (phi " << calomet_phi() << ")" << endl;
	cout << "Lep ID " << lep1_pdgid() << " Pt " << lep1_p4().Pt() << " Eta " << lep1_p4().Eta() << " Phi " << lep1_p4().Phi() << " M " << lep1_p4().M() << endl;
	cout << "Lep ID " << lep1_pdgid() << " Px " << lep1_p4().Px() << " Py " << lep1_p4().Py() << " Pz " << lep1_p4().Pz() << " E " << lep1_p4().E() << endl;
	cout << "    passVeto/Loose/Medium/Tight " << lep1_passVeto() << "/" << lep1_passLooseID() << "/" << lep1_passMediumID() << "/" << lep1_passTightID() << endl;
	for(unsigned int j = 0; j<ak4pfjets_p4().size();++j){
	  cout << "jet" << j+1 << " Pt " << ak4pfjets_p4()[j].Pt() << " Eta " << ak4pfjets_p4()[j].Eta() << " Phi " << ak4pfjets_p4()[j].Phi() << " M " << ak4pfjets_p4()[j].M() << " CSV " << ak4pfjets_CSV()[j] << endl;
	  cout << "jet" << j+1 << " Px " << ak4pfjets_p4()[j].Px() << " Py " << ak4pfjets_p4()[j].Py() << " Pz " << ak4pfjets_p4()[j].Pz() << " E " << ak4pfjets_p4()[j].E() << " CSV " << ak4pfjets_CSV()[j] << endl;
	}
	cout << endl;
	}
      */
      /*
      if((run()==278167&&ls()==2148&&evt()==3802320550)||(run()==279715&&ls()==213&&evt()==271744185)||(run()==277127&&ls()==100&&evt()==190758468)) {
	cout << "run:ls:evt " << run() << ":" << ls() << ":" << evt() <<  " SRbin " << SR << endl;
	cout << "Triggered? " << "MET " << HLT_MET() << " Ele " << HLT_SingleEl() << " Muo " << HLT_SingleMu() << endl;
	cout << "NJ " << ngoodjets() << " NB " << ngoodbtags() << " nvetoleps " << nvetoleps() << " MDPhi(MET,j12) " << mindphi_met_j1_j2() << " tmod " << topnessMod() << " Mlb " << Mlb_closestb() << " MT " << mt_met_lep() <<  " pfMET " << pfmet() << " (phi " << pfmet_phi() << ") caloMET " << calomet() << " (phi " << calomet_phi() << ")" << endl;
	cout << "Lep ID " << lep1_pdgid() << " Pt " << lep1_p4().Pt() << " Eta " << lep1_p4().Eta() << " Phi " << lep1_p4().Phi() << " M " << lep1_p4().M() << endl;
	cout << "Lep ID " << lep1_pdgid() << " Px " << lep1_p4().Px() << " Py " << lep1_p4().Py() << " Pz " << lep1_p4().Pz() << " E " << lep1_p4().E() << endl;
	cout << "    passVeto/Loose/Medium/Tight " << lep1_passVeto() << "/" << lep1_passLooseID() << "/" << lep1_passMediumID() << "/" << lep1_passTightID() << endl;
	for(unsigned int j = 0; j<ak4pfjets_p4().size();++j){
	  cout << "jet" << j+1 << " Pt " << ak4pfjets_p4()[j].Pt() << " Eta " << ak4pfjets_p4()[j].Eta() << " Phi " << ak4pfjets_p4()[j].Phi() << " M " << ak4pfjets_p4()[j].M() << " CSV " << ak4pfjets_CSV()[j] << endl;
	  cout << "jet" << j+1 << " Px " << ak4pfjets_p4()[j].Px() << " Py " << ak4pfjets_p4()[j].Py() << " Pz " << ak4pfjets_p4()[j].Pz() << " E " << ak4pfjets_p4()[j].E() << " CSV " << ak4pfjets_CSV()[j] << endl;
	}
	cout << endl;
	}
      */
      //if(SR==8) cout << run() << ":" << ls() << ":" << evt() << endl;
    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  string filename = "rootfiles/DataSR.root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  /*
  TString logname = "tempfiles/SRevts_MET250.txt";
  ofstream f_log1 (logname.Data(), ios::trunc);
  f_log1 << fLogStreamSR1->str();
  logname = "tempfiles/detailedSRevts_MET250.txt";
  ofstream f_log1t (logname.Data(), ios::trunc);
  f_log1t << tfLogStreamSR1->str();
  logname = "tempfiles/SRevts_MET350.txt";
  ofstream f_log2 (logname.Data(), ios::trunc);
  f_log2 << fLogStreamSR2->str();
  logname = "tempfiles/detailedSRevts_MET350.txt";
  ofstream f_log2t (logname.Data(), ios::trunc);
  f_log2t << tfLogStreamSR2->str();
  logname = "tempfiles/SRevts_MET450.txt";
  ofstream f_log3 (logname.Data(), ios::trunc);
  f_log3 << fLogStreamSR3->str();
  logname = "tempfiles/detailedSRevts_MET450.txt";
  ofstream f_log3t (logname.Data(), ios::trunc);
  f_log3t << tfLogStreamSR3->str();
  logname = "tempfiles/cSRevts_MET250.txt";
  ofstream cf_log1 (logname.Data(), ios::trunc);
  cf_log1 << fLogStreamcSR1->str();
  logname = "tempfiles/detailedcSRevts_MET250.txt";
  ofstream cf_log1t (logname.Data(), ios::trunc);
  cf_log1t << tfLogStreamcSR1->str();
  logname = "tempfiles/cSRevts_MET350.txt";
  ofstream cf_log2 (logname.Data(), ios::trunc);
  cf_log2 << fLogStreamcSR2->str();
  logname = "tempfiles/detailedcSRevts_MET350.txt";
  ofstream cf_log2t (logname.Data(), ios::trunc);
  cf_log2t << tfLogStreamcSR2->str();
  logname = "tempfiles/cSRevts_MET450.txt";
  ofstream cf_log3 (logname.Data(), ios::trunc);
  cf_log3 << fLogStreamcSR3->str();
  logname = "tempfiles/detailedcSRevts_MET450.txt";
  ofstream cf_log3t (logname.Data(), ios::trunc);
  cf_log3t << tfLogStreamcSR3->str();
  */
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
