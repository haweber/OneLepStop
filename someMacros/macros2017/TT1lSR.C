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

  cout <<__LINE__<< endl;
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
  cout <<__LINE__<< endl;

  histonames.push_back("SR_Top");        hbins.push_back(27); hlow.push_back(  0.); hup.push_back(27);
  histonames.push_back("cSR_Top");       hbins.push_back( 4); hlow.push_back(  0.); hup.push_back( 4);

  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }
  cout <<__LINE__<< endl;

  unsigned int nEventsRunning = 0;
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  cout << __LINE__ << endl;
  // File Loop
  TH1D* counterhist;
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    file->cd();
      counterhist = (TH1D*)file->Get("h_counter");
      counterhist->SetDirectory(0); 
  cout << __LINE__ << endl;
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

      double nevts = counterhist->GetBinContent(22);
      double PUweight     = weight_PU();
      double ISRnorm = counterhist->GetBinContent(25);
      double ISRweight = weight_ISRnjets();//updated
      double BSFnorm = counterhist->GetBinContent(14);
      double BSFweight = weight_btagsf();
      double BSFtnorm = counterhist->GetBinContent(37);
      double BSFtweight = weight_tightbtagsf();
      double lepSFnorm = counterhist->GetBinContent(28);
      double lepSFweight = weight_lepSF();
      if(ISRnorm>0) ISRweight*=nevts/ISRnorm;
      if(BSFnorm>0) BSFweight *=nevts/BSFnorm;
      if(BSFtnorm>0) BSFtweight *=nevts/BSFtnorm;
      if(lepSFnorm>0) lepSFweight *= nevts/lepSFnorm;
      //double weight = xsection*mylumi/nevts*PUweight*ISRweight*BSFweight*lepSFweight*lepFSSFweight;//xsec given in pb
      double rawweight = 35.9*scale1fb()*ISRweight*lepSFweight;//xsec given in pb

      TString currentfilename = currentFile->GetTitle();
      if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_25ns")) rawweight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns")) rawweight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns")) rawweight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns")) rawweight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07);

      
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

      double weight = rawweight * BSFweight;
      if(cSR>0) histos["cSR_Top"]->Fill(cSR-1,weight);
      if((SR>=5&&SR<=7)||(SR>=13&&SR<=16)||(SR>=20&&SR<=21)||(SR>=26&&SR<=27)) weight = rawweight*BSFtweight;
      if( SR>0) histos[ "SR_Top"]->Fill( SR-1,weight);


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
    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  string filename = "rootfiles/TT1lSR.root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
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
