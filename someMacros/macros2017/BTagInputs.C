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
#include "TH2F.h"
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


  map<string, TH2D*> histos;
  vector<string> histonames; histonames.clear();

  histonames.push_back("AllBJets");
  histonames.push_back("AllLooseBTaggedBJets");
  histonames.push_back("AllMediumBTaggedBJets");
  histonames.push_back("AllTightBTaggedBJets");
  histonames.push_back("AllCJets");
  histonames.push_back("AllLooseBTaggedCJets");
  histonames.push_back("AllMediumBTaggedCJets");
  histonames.push_back("AllTightBTaggedCJets");
  histonames.push_back("AllLJets");
  histonames.push_back("AllLooseBTaggedLJets");
  histonames.push_back("AllMediumBTaggedLJets");
  histonames.push_back("AllTightBTaggedLJets");
  histonames.push_back("LooseBEfficiency");
  histonames.push_back("LooseCEfficiency");
  histonames.push_back("LooseLEfficiency");
  histonames.push_back("MediumBEfficiency");
  histonames.push_back("MediumCEfficiency");
  histonames.push_back("MediumLEfficiency");
  histonames.push_back("TightBEfficiency");
  histonames.push_back("TightCEfficiency");
  histonames.push_back("TightLEfficiency");


  double xbins[11] = {20.,30.,50.,70.,100.,140.,200.,300.,450.,700.,1000};
  double ybins[4] = {0.,0.8,1.6,2.5};
  
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname = histonames[i];
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH2D(mapname.c_str(), "", 10, xbins, 3, ybins);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

  unsigned int nEventsRunning = 0;
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  TH2F* histNEvts;
  bool issignal = false;
  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TString blacurrentfilename = currentFile->GetTitle();
    if(blacurrentfilename.Contains("Signal")){
      histNEvts = (TH2F*)file->Get("histNEvts");
      histNEvts->SetDirectory(0);
      issignal = true;
    }
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

       // Analysis Code
       float weight = cms3.scale1fb()*36.6;//actually doesn't matter really
       TString currentfilename = currentFile->GetTitle();
       if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_25ns")) weight *= 5.77109e+06/(5.77109e+06 + 2.34556e+07);
       if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_ext1_25ns")) weight *= 2.34556e+07/(5.77109e+06 + 2.34556e+07);
       if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_25ns")) weight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07);
       if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns")) weight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07);
       if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns")) weight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07);
       if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns")) weight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07);
       if(issignal){
	 if(mass_stop()>1000) continue;
	 if(mass_lsp()>425) continue;
	 int Nevts = histNEvts->GetBinContent(histNEvts->FindBin( mass_stop(),mass_lsp()));
	 weight = 36600.*xsec()/(float)Nevts;
       }
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;

      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)           continue;
      if(nvetoleps()<1)           continue;
      if(ngoodjets()<2)           continue;
      //if(ngoodbtags()<1)          continue;
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;

      for(unsigned int j = 0; j<ak4pfjets_p4().size(); ++j){
	if(fabs(ak4pfjets_p4()[j].Pt())<20) continue;
	if(fabs(ak4pfjets_p4()[j].Eta())>2.4) continue;
	if(!(ak4pfjets_loose_pfid()[j])) continue;
	bool isloose = (ak4pfjets_CSV()[j]>0.5426);
	bool ismedium = (ak4pfjets_CSV()[j]>0.8484);
	bool istight  = (ak4pfjets_CSV()[j]>0.9535);
	bool isb = (abs(ak4pfjets_hadron_flavor()[j])==5);
	bool isc = (abs(ak4pfjets_hadron_flavor()[j])==4);
	bool isl = true;
	if(isc||isb) isl = false;
	float pt = TMath::Min(ak4pfjets_p4()[j].Pt(),(float)999.);
	float eta = fabs(ak4pfjets_p4()[j].Eta());
	if(isb){
	  histos["AllBJets"]->Fill(pt,eta,weight);
	  if(isloose)  histos["AllLooseBTaggedBJets"]->Fill(pt,eta,weight);
	  if(ismedium) histos["AllMediumBTaggedBJets"]->Fill(pt,eta,weight);
	  if(istight)  histos["AllTightBTaggedBJets"]->Fill(pt,eta,weight);
	}
	if(isc){
	  histos["AllCJets"]->Fill(pt,eta,weight);
	  if(isloose ) histos["AllLooseBTaggedCJets"]->Fill(pt,eta,weight);
	  if(ismedium) histos["AllMediumBTaggedCJets"]->Fill(pt,eta,weight);
	  if(istight)  histos["AllTightBTaggedCJets"]->Fill(pt,eta,weight);
	}
	if(isl){
	  histos["AllLJets"]->Fill(pt,eta,weight);
	  if(isloose)  histos["AllLooseBTaggedLJets"]->Fill(pt,eta,weight);
	  if(ismedium) histos["AllMediumBTaggedLJets"]->Fill(pt,eta,weight);
	  if(istight)  histos["AllTightBTaggedLJets"]->Fill(pt,eta,weight);
	}
      }//j
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

  histos["LooseBEfficiency"]->Divide(histos["AllLooseBTaggedBJets"],histos["AllBJets"]);
  histos["LooseCEfficiency"]->Divide(histos["AllLooseBTaggedCJets"],histos["AllCJets"]);
  histos["LooseLEfficiency"]->Divide(histos["AllLooseBTaggedLJets"],histos["AllLJets"]);
  histos["MediumBEfficiency"]->Divide(histos["AllMediumBTaggedBJets"],histos["AllBJets"]);
  histos["MediumCEfficiency"]->Divide(histos["AllMediumBTaggedCJets"],histos["AllCJets"]);
  histos["MediumLEfficiency"]->Divide(histos["AllMediumBTaggedLJets"],histos["AllLJets"]);
  histos["TightBEfficiency"]->Divide(histos["AllTightBTaggedBJets"],histos["AllBJets"]);
  histos["TightCEfficiency"]->Divide(histos["AllTightBTaggedCJets"],histos["AllCJets"]);
  histos["TightLEfficiency"]->Divide(histos["AllTightBTaggedLJets"],histos["AllLJets"]);

  string filename = "rootfiles/BTaggingInput_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH2D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
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
