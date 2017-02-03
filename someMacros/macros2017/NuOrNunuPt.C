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
#include "TMath.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

// CMS3
//#include "CMS3_old20150505.cc"
//#include "CMS3_fuckingsync.cc"
#include "CMS3_Oct16.cc"

//MT2 variants

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float dPhibetweenVectors(float phi1,float phi2 ){                                                                                                              

  return sqrt(pow(TMath::Min(float(fabs(phi1-phi2)),float(2*M_PI-fabs(phi1-phi2)) ),2));
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

  histonames.push_back("NuOrNunuPt_MET150_23j_MT120");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT120");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT120");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT150");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT150");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT150");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT120_tmodle0");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT120_tmodle0");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT150_tmodle0");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT150_tmodle0");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT120_tmodgt0");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT120_tmodgt0");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT150_tmodgt0");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT150_tmodgt0");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT120_Mlble175");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT120_Mlble175");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT150_Mlble175");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT150_Mlble175");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT120_Mlbgt175");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT120_Mlbgt175");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_23j_MT150_Mlbgt175");     hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_4j_MT150_Mlbgt175");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);

  histonames.push_back("NuOrNunuPt_MET150_5j_MT120_leppTle150");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT120_DPhiLepMETle2");   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT150_leppTle150");      hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT150_DPhiLepMETle2");   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT120_DPhiLepMETle2_leppTle150");   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("NuOrNunuPt_MET150_5j_MT150_DPhiLepMETle2_leppTle150");   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);

  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<3; ++b){
      string samplename = "";
      if(b==0) samplename = "2l";
      if(b==1) samplename = "1l";
      if(b==2) samplename = "1ltop";
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }
  }

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

      int ngenold = 0;
      int ngennew = 0;

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygenlep;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu; mygennu.SetPxPyPzE(0.,0.,0.,0.);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu2; mygennu2.SetPxPyPzE(0.,0.,0.,0.);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygenW;
      int gennuflav = -1;
      int gennuflav2 = -1;

      //string samplename = skimFilePrefix;
      int ngm = 0;
       for(unsigned int n = 0; n< gennus_id().size(); ++n){
	 if(gennus_status()[n]!=1) continue;
	 if(abs(gennus_id()[n])!=12&&abs(gennus_id()[n])!=14&&abs(gennus_id()[n])!=16) continue;
	 if(abs(gennus_motherid()[n])!=24) continue;
	 if((ngm)==0){ mygennu = gennus_p4()[n]; }
	 else { mygennu2 = gennus_p4()[n]; }
	 ++ngm;
      }
       // Analysis Code
       float weight = cms3.scale1fb()*31;//actually doesn't matter really
       TString currentfilename = currentFile->GetTitle();
       if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_25ns")) weight *= 5.77109e+06/(5.77109e+06 + 2.34556e+07);
       if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_ext1_25ns")) weight *= 2.34556e+07/(5.77109e+06 + 2.34556e+07);
       //if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_25ns")) weight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07);
       //if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns")) weight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07);
       //if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns")) weight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07);
       //if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns")) weight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07);      

      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;

      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)           continue;
      if(nvetoleps()<1)           continue;
      if(ngoodjets()<2)           continue;
      //if(ngoodbtags()<1)          continue;
      if(pfmet()<150)             continue;
      if(mt_met_lep()<120)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;

      bool reco1l = ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto();
      bool reco2l = (ngoodleps()==2)||(nvetoleps()==2);
      int NJ = ngoodjets();
      int NB = ngoodbtags();

      bool onel = is1lepFromW();
      bool oneltop = is1lepFromTop();
      bool dilep = is2lep();
      if((dilep&&oneltop)||(dilep&&onel)||(onel&&oneltop)) cout << __LINE__ << " " << onel << " " << oneltop << " " << dilep << endl;

      if((onel||oneltop)&&reco2l) continue;
      if(dilep&&reco1l) continue;
      
      if(!onel&&!oneltop&&!dilep) { cout << " " << currentFile->GetTitle() << endl; continue; }
      
      float NuOrNunuPt = -1;
      if(onel||oneltop) NuOrNunuPt = mygennu.Pt();
      if(dilep) NuOrNunuPt = (mygennu+mygennu2).Pt();
      if(NuOrNunuPt<55) continue;

      if(genmet()<=0) cout << "WTF" << endl;

      string samplename;
      if(dilep)   samplename = "2l";
      else if(oneltop) samplename = "1ltop";
      else if(onel)    samplename = "1l";

      float Mlb = Mlb_closestb();
      if(Mlb<0){
	int leadb = 0;
	for(unsigned int i = 1; i<=ak4pfjets_CSV().size(); ++i){
	  if(ak4pfjets_CSV()[leadb]<ak4pfjets_CSV()[i]) leadb = i;
	}
	Mlb = (ak4pfjets_p4()[leadb]+lep1_p4()).M();
      }

      if(mt_met_lep()>120){
	if(NJ<=3){
	  histos["NuOrNunuPt_MET150_23j_MT120_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(topnessMod()<=0) histos["NuOrNunuPt_MET150_23j_MT120_tmodle0_"+samplename]->Fill(NuOrNunuPt,weight);
	  else                histos["NuOrNunuPt_MET150_23j_MT120_tmodgt0_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(Mlb<=175) histos["NuOrNunuPt_MET150_23j_MT120_Mlble175_"+samplename]->Fill(NuOrNunuPt,weight);
	  else         histos["NuOrNunuPt_MET150_23j_MT120_Mlbgt175_"+samplename]->Fill(NuOrNunuPt,weight);
	}
	else {
	  histos["NuOrNunuPt_MET150_4j_MT120_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(topnessMod()<=0) histos["NuOrNunuPt_MET150_4j_MT120_tmodle0_"+samplename]->Fill(NuOrNunuPt,weight);
	  else                histos["NuOrNunuPt_MET150_4j_MT120_tmodgt0_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(Mlb<=175) histos["NuOrNunuPt_MET150_4j_MT120_Mlble175_"+samplename]->Fill(NuOrNunuPt,weight);
	  else         histos["NuOrNunuPt_MET150_4j_MT120_Mlbgt175_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(NJ>=5) {
	    histos["NuOrNunuPt_MET150_5j_MT120_"+samplename]->Fill(NuOrNunuPt,weight);
	    if(dPhibetweenVectors(lep1_p4().Phi(),pfmet_phi())<=2) {
	      histos["NuOrNunuPt_MET150_5j_MT120_DPhiLepMETle2_"+samplename]->Fill(NuOrNunuPt,weight);
	      if(lep1_p4().Pt()<=150) histos["NuOrNunuPt_MET150_5j_MT120_DPhiLepMETle2_leppTle150_"+samplename]->Fill(NuOrNunuPt,weight);
	    }
	    if(lep1_p4().Pt()<=150) histos["NuOrNunuPt_MET150_5j_MT120_leppTle150_"+samplename]->Fill(NuOrNunuPt,weight);
	  }
	}
      }
      if(mt_met_lep()>150){
	if(NJ<=3){
	  histos["NuOrNunuPt_MET150_23j_MT150_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(topnessMod()<=0) histos["NuOrNunuPt_MET150_23j_MT150_tmodle0_"+samplename]->Fill(NuOrNunuPt,weight);
	  else                histos["NuOrNunuPt_MET150_23j_MT150_tmodgt0_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(Mlb<=175) histos["NuOrNunuPt_MET150_23j_MT150_Mlble175_"+samplename]->Fill(NuOrNunuPt,weight);
	  else         histos["NuOrNunuPt_MET150_23j_MT150_Mlbgt175_"+samplename]->Fill(NuOrNunuPt,weight);
	}
	else {
	  histos["NuOrNunuPt_MET150_4j_MT150_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(topnessMod()<=0) histos["NuOrNunuPt_MET150_4j_MT150_tmodle0_"+samplename]->Fill(NuOrNunuPt,weight);
	  else                histos["NuOrNunuPt_MET150_4j_MT150_tmodgt0_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(Mlb<=175) histos["NuOrNunuPt_MET150_4j_MT150_Mlble175_"+samplename]->Fill(NuOrNunuPt,weight);
	  else         histos["NuOrNunuPt_MET150_4j_MT150_Mlbgt175_"+samplename]->Fill(NuOrNunuPt,weight);
	  if(NJ>=5) {
	    histos["NuOrNunuPt_MET150_5j_MT150_"+samplename]->Fill(NuOrNunuPt,weight);
	    if(dPhibetweenVectors(lep1_p4().Phi(),pfmet_phi())<=2) {
	      histos["NuOrNunuPt_MET150_5j_MT150_DPhiLepMETle2_"+samplename]->Fill(NuOrNunuPt,weight);
	      if(lep1_p4().Pt()<=150) histos["NuOrNunuPt_MET150_5j_MT150_DPhiLepMETle2_leppTle150_"+samplename]->Fill(NuOrNunuPt,weight);
	    }
	    if(lep1_p4().Pt()<=150) histos["NuOrNunuPt_MET150_5j_MT150_leppTle150_"+samplename]->Fill(NuOrNunuPt,weight);
	  }
	}
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
  
  // Example Histograms
  // samplehisto->Draw();

  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    //add overflow
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
    //add underflow
    h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  string filename = "rootfiles/PhotonMETResolution/NuOrNunuPt.root";
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
