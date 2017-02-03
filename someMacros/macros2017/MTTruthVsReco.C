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
#include "Math/VectorUtil.h"

// CMS3
//#include "CMS3_old20150505.cc"
//#include "CMS3_fuckingsync.cc"
#include "CMS3_Oct16.cc"
//#include "CMS3_temp.cc"

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

float calculateMT(LorentzVector p4, float met, float metphi){
  float phi1 = p4.Phi();
  float phi2 = metphi;
  float Et1  = p4.Et();
  float Et2  = met;

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  float SRevts(0), SRevtsMuF(0), SRevtsCalo(0),  CR2levts(0), CR2levtsMuF(0), CR2levtsCalo(0),  CR0bevts(0), CR0bevtsMuF(0), CR0bevtsCalo(0);
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1D*> histos;
  vector<string> histonames; histonames.clear();

  histonames.push_back("recoMT_MET50");
  histonames.push_back("recoMT_MET100");
  histonames.push_back("recoMT_MET150");
  histonames.push_back("recoMT_MET200");
  histonames.push_back("recoMT_MET250");
  histonames.push_back("truthMT_MET50");
  histonames.push_back("truthMT_MET100");
  histonames.push_back("truthMT_MET150");
  histonames.push_back("truthMT_MET200");
  histonames.push_back("truthMT_MET250");
  


  double xbins[11] = {20.,30.,50.,70.,100.,140.,200.,300.,450.,700.,1000};
  double ybins[4] = {0.,0.8,1.6,2.5};
  
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    //for(unsigned int b = 0; b<3; ++b){
      //string mysample;
      //if(b==0) mysample = "TT1l";
      //else if(b==1) mysample = "TT2l";
      //else mysample = "W";
      string mapname = histonames[i] + "_" + skimFilePrefix;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1D(mapname.c_str(), "", 50, 0,500);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      //}
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
      //if(pfmet()<175)             continue;//relaxed for MC
      //if(mt_met_lep()<120)        continue;//relaxed for MC
      //if(mindphi_met_j1_j2()<0.8) continue;

      LorentzVector genlep; genlep.SetPxPyPzE(0,0,0,0);
      for(unsigned int n = 0; n< genleps_id().size(); ++n){
	//if(genleps_status()[n]!=1) continue;
	//if((abs(genleps_id()[n])==11||abs(genleps_id()[n])==13)&&nEventsTotal%100000==0)
	//  cout << "id " << genleps_id()[n] << " status " << genleps_status()[n] << " last copy " << genleps_isLastCopy()[n] << " mid " << genleps_motherid()[n] << "gmid " << genleps_gmotherid()[n] << " DR true lep " << ROOT::Math::VectorUtil::DeltaR(genleps_p4()[n], lep1_p4()) << " Pt " << genleps_p4()[n].Pt() << endl;
	 if( !genleps_isLastCopy()[n] ) continue;
	 if(abs(genleps_id()[n])!=11&&abs(genleps_id()[n])!=13) continue;
	 if(!(abs(genleps_motherid()[n])==24||(abs(genleps_motherid()[n])==13&&abs(genleps_gmotherid()[n])==24)) ) continue;
	 if( ROOT::Math::VectorUtil::DeltaR(genleps_p4()[n], lep1_p4())>0.4 ) continue;
	 if(genleps_p4()[n].Pt()<2) continue;
	 genlep = genleps_p4()[n];
	 break;
      }
      //if(nEventsTotal%100000==0) cout << endl;
      

      if(pfmet()<50) continue;
      histos["recoMT_MET50_"+skimFilePrefix]->Fill(calculateMT(lep1_p4(),pfmet(),pfmet_phi()),weight);
      if(genlep.Pt()>0) histos["truthMT_MET50_"+skimFilePrefix]->Fill(calculateMT(genlep,genmet(),genmet_phi()),weight);
      if(pfmet()<100) continue;
      histos["recoMT_MET100_"+skimFilePrefix]->Fill(calculateMT(lep1_p4(),pfmet(),pfmet_phi()),weight);
      if(genlep.Pt()>0) histos["truthMT_MET100_"+skimFilePrefix]->Fill(calculateMT(genlep,genmet(),genmet_phi()),weight);
      if(pfmet()<150) continue;
      histos["recoMT_MET150_"+skimFilePrefix]->Fill(calculateMT(lep1_p4(),pfmet(),pfmet_phi()),weight);
      if(genlep.Pt()>0) histos["truthMT_MET150_"+skimFilePrefix]->Fill(calculateMT(genlep,genmet(),genmet_phi()),weight);
      if(pfmet()<200) continue;
      histos["recoMT_MET200_"+skimFilePrefix]->Fill(calculateMT(lep1_p4(),pfmet(),pfmet_phi()),weight);
      if(genlep.Pt()>0) histos["truthMT_MET200_"+skimFilePrefix]->Fill(calculateMT(genlep,genmet(),genmet_phi()),weight);
      if(pfmet()<250) continue;
      histos["recoMT_MET250_"+skimFilePrefix]->Fill(calculateMT(lep1_p4(),pfmet(),pfmet_phi()),weight);
      if(genlep.Pt()>0) histos["truthMT_MET250_"+skimFilePrefix]->Fill(calculateMT(genlep,genmet(),genmet_phi()),weight);


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

  string filename = "rootfiles/MThistosforPaper.root";
  TFile *f = new TFile(filename.c_str(),"UPDATE");
  f->cd();
  for(map<string,TH1D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write(h->first.c_str(),TObject::kOverwrite);
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
