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
#include "TH2F.h"

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_HLT.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
#include "/home/users/haweber/CORE/Tools/goodrun.h"
#include "/home/users/haweber/CORE/Tools/goodrun.cc"
//MT2 variants

using namespace std;
using namespace tas;


float photon_CHEA03( int photonIdx )
{
  float eta = ph_eta()[photonIdx];
  float EA = -999;
  
  if(       abs(eta) < 1.0   ){ EA = 0.0157;
  }else if( abs(eta) < 1.479 ){ EA = 0.0143;
  }else if( abs(eta) < 2.0   ){ EA = 0.0115;
  }else if( abs(eta) < 2.2   ){ EA = 0.0094;
  }else if( abs(eta) < 2.3   ){ EA = 0.0095;
  }else if( abs(eta) < 2.4   ){ EA = 0.0068;
  }else if( abs(eta) > 2.4   ){ EA = 0.0053;
  }
  
  return EA;
}

float photon_NHEA03( int photonIdx )
{
  float eta = ph_eta()[photonIdx];
  float EA = -999;
  
  if(       abs(eta) < 1.0   ){ EA = 0.0143;
  }else if( abs(eta) < 1.479 ){ EA = 0.0210;
  }else if( abs(eta) < 2.0   ){ EA = 0.0148;
  }else if( abs(eta) < 2.2   ){ EA = 0.0082;
  }else if( abs(eta) < 2.3   ){ EA = 0.0124;
  }else if( abs(eta) < 2.4   ){ EA = 0.0186;
  }else if( abs(eta) > 2.4   ){ EA = 0.0320;
  }
  
  return EA;
}

float photon_EMEA03( int photonIdx )
{
  float eta = ph_eta()[photonIdx];
  float EA = -999;
  
  if(       abs(eta) < 1.0   ){ EA = 0.0725;
  }else if( abs(eta) < 1.479 ){ EA = 0.0604;
  }else if( abs(eta) < 2.0   ){ EA = 0.0320;
  }else if( abs(eta) < 2.2   ){ EA = 0.0512;
  }else if( abs(eta) < 2.3   ){ EA = 0.0766;
  }else if( abs(eta) < 2.4   ){ EA = 0.0949;
  }else if( abs(eta) > 2.4   ){ EA = 0.1160;
  }
  
  return EA;
}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  unsigned int counter = 0;
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  map<string, TH2F*> histos;
  vector<string> histonames2D; histonames2D.clear();

  //changed ge3j to 3j
  histonames2D.push_back("Tag_el");
  histonames2D.push_back("Tag_mu");
  histonames2D.push_back("Probe_elel");
  histonames2D.push_back("Probe_mumu");
  histonames2D.push_back("Probe_elMET");
  histonames2D.push_back("Probe_muMET");
  histonames2D.push_back("Probe_elMHT");
  histonames2D.push_back("Probe_muMHT");
  histonames2D.push_back("Probe_elelMET");
  histonames2D.push_back("Probe_mumuMET");
  histonames2D.push_back("Probe_elelMHT");
  histonames2D.push_back("Probe_mumuMHT");
  histonames2D.push_back("Probe_elMETMHT");
  histonames2D.push_back("Probe_muMETMHT");
  histonames2D.push_back("Probe_elelMETMHT");
  histonames2D.push_back("Probe_mumuMETMHT");
  
  histonames2D.push_back("Tag2l_el");
  histonames2D.push_back("Tag2l_mu");
  histonames2D.push_back("Probe2l_elel");
  histonames2D.push_back("Probe2l_mumu");
  histonames2D.push_back("Probe2l_elMET");
  histonames2D.push_back("Probe2l_muMET");
  histonames2D.push_back("Probe2l_elMHT");
  histonames2D.push_back("Probe2l_muMHT");
  histonames2D.push_back("Probe2l_elelMET");
  histonames2D.push_back("Probe2l_mumuMET");
  histonames2D.push_back("Probe2l_elelMHT");
  histonames2D.push_back("Probe2l_mumuMHT");
  histonames2D.push_back("Probe2l_elMETMHT");
  histonames2D.push_back("Probe2l_muMETMHT");
  histonames2D.push_back("Probe2l_elelMETMHT");
  histonames2D.push_back("Probe2l_mumuMETMHT");

  histonames2D.push_back("Eff_elel");
  histonames2D.push_back("Eff_mumu");
  histonames2D.push_back("Eff_elMET");
  histonames2D.push_back("Eff_muMET");
  histonames2D.push_back("Eff_elMHT");
  histonames2D.push_back("Eff_muMHT");
  histonames2D.push_back("Eff_elelMET");
  histonames2D.push_back("Eff_mumuMET");
  histonames2D.push_back("Eff_elelMHT");
  histonames2D.push_back("Eff_mumuMHT");
  histonames2D.push_back("Eff_elMETMHT");
  histonames2D.push_back("Eff_muMETMHT");
  histonames2D.push_back("Eff_elelMETMHT");
  histonames2D.push_back("Eff_mumuMETMHT");
  histonames2D.push_back("Eff2l_elel");
  histonames2D.push_back("Eff2l_mumu");
  histonames2D.push_back("Eff2l_elMET");
  histonames2D.push_back("Eff2l_muMET");
  histonames2D.push_back("Eff2l_elMHT");
  histonames2D.push_back("Eff2l_muMHT");
  histonames2D.push_back("Eff2l_elelMET");
  histonames2D.push_back("Eff2l_mumuMET");
  histonames2D.push_back("Eff2l_elelMHT");
  histonames2D.push_back("Eff2l_mumuMHT");
  histonames2D.push_back("Eff2l_elMETMHT");
  histonames2D.push_back("Eff2l_muMETMHT");
  histonames2D.push_back("Eff2l_elelMETMHT");
  histonames2D.push_back("Eff2l_mumuMETMHT");

  double xbins[10] = {10.,12.5,15.,17.5,20.,22.5,25.,30.,40.,50.};
  double ybins[9] = {175.,200.,225.,250.,275.,300.,350.,400.,500.};

  const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  set_goodrun_file_json(json_file);


  for(unsigned int i = 0; i<histonames2D.size(); ++i){
    //string samplename = skimFilePrefix;
    string mapname = histonames2D[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH2F(mapname.c_str(), "", 9, xbins, 8, ybins);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

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

      string samplename = skimFilePrefix;

      //cout << __LINE__<< endl;
      //cout <<  " filename " << currentFile->GetTitle() << endl;
      if( is_data() ) {//remove duplicates
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      if( is_data() && !goodrun(run(), ls()) ) continue;
      // Analysis Code
      float weight = 1;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      if(nvtxs()<0)               continue;
      //if((nge+ngm+ngt)!=0)        continue;
      //if((ngt)!=0)                continue;
      if(ngoodleps()==0)          continue;
      //if(nvetoleps()!=0)          continue;
      //if(!PassTrackVeto())     continue;
      //if(!PassTauVeto())          continue;
      if(ngoodjets()<2)        continue;
      //if(ngoodbtags()<1)          continue;
      //if(met()<250)            continue;
      //if(mt_met_lep()<120)        continue;
      //if(mindphi_met_j1_j2()<0.8) continue;

      bool ele = false;
      bool muo = false;
      if(abs(lep1_pdgid())==11) ele = true;
      if(abs(lep1_pdgid())==13) muo = true;
      if(!ele&&!muo) { cout << "WTF " << lep1_pdgid() << endl; }

      bool dilep = nvetoleps()>1;
	

      bool tag = HLT_PFHT_prescaled()>0 || HLT_PFHT_unprescaled()>0 /*|| HLT_CaloJet500_NoJetID() > 0*/;
      int met = HLT_MET();
      int el  = HLT_SingleEl();
      int mu  = HLT_SingleMu();
      int mht = 0; if(HLT_MET120_MHT120()>0) mht = HLT_MET120_MHT120(); else if(HLT_MET110_MHT110()>0) mht = HLT_MET110_MHT110(); else if(HLT_MET100_MHT100()>0) mht = HLT_MET100_MHT100();

      if(!tag) continue;
      ++counter;

      if(ele){
	histos["Tag_el"]->Fill(lep1_p4().Pt(), pfmet());
	if(el>0)  histos["Probe_elel" ]->Fill(lep1_p4().Pt(), pfmet());
	if(met>0) histos["Probe_elMET"]->Fill(lep1_p4().Pt(), pfmet());
	if(mht>0) histos["Probe_elMHT"]->Fill(lep1_p4().Pt(), pfmet());
	if(el>0||met>0) histos["Probe_elelMET" ]->Fill(lep1_p4().Pt(), pfmet());
	if(el>0||mht>0) histos["Probe_elelMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(met>0||mht>0) histos["Probe_elMETMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(el>0||met>0||mht>0) histos["Probe_elelMETMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(dilep){
	  histos["Tag2l_el"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(el>0)  histos["Probe2l_elel" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(met>0) histos["Probe2l_elMET"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mht>0) histos["Probe2l_elMHT"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(el>0||met>0) histos["Probe2l_elelMET" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(el>0||mht>0) histos["Probe2l_elelMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(met>0||mht>0) histos["Probe2l_elMETMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(el>0||met>0||mht>0) histos["Probe2l_elelMETMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	}
      }
      if(muo){
	histos["Tag_mu"]->Fill(lep1_p4().Pt(), pfmet());
	if(mu>0)  histos["Probe_mumu" ]->Fill(lep1_p4().Pt(), pfmet());
	if(met>0) histos["Probe_muMET"]->Fill(lep1_p4().Pt(), pfmet());
	if(mht>0) histos["Probe_muMHT"]->Fill(lep1_p4().Pt(), pfmet());
	if(mu>0||met>0) histos["Probe_mumuMET" ]->Fill(lep1_p4().Pt(), pfmet());
	if(mu>0||mht>0) histos["Probe_mumuMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(met>0||mht>0) histos["Probe_muMETMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(mu>0||met>0||mht>0) histos["Probe_mumuMETMHT" ]->Fill(lep1_p4().Pt(), pfmet());
	if(dilep){
	  histos["Tag2l_mu"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mu>0)  histos["Probe2l_mumu" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(met>0) histos["Probe2l_muMET"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mht>0) histos["Probe2l_muMHT"]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mu>0||met>0) histos["Probe2l_mumuMET" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mu>0||mht>0) histos["Probe2l_mumuMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(met>0||mht>0) histos["Probe2l_muMETMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
	  if(mu>0||met>0||mht>0) histos["Probe2l_mumuMETMHT" ]->Fill(lep1_p4().Pt(), pfmet_rl());
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

  //do it 2d!!!!
  for(map<string,TH2F*>::iterator h=histos.begin(); h!=histos.end();++h){

    for(int y = 1; y<=h->second->GetNbinsY()+1;++y){
      //add overflow
      h->second->SetBinContent(h->second->GetNbinsX(),y, h->second->GetBinContent(h->second->GetNbinsX(),y )+ h->second->GetBinContent(h->second->GetNbinsX()+1,y) );
      h->second->SetBinError(h->second->GetNbinsX(),y, sqrt(pow(h->second->GetBinError(h->second->GetNbinsX(),y ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1,y),2) ) );
      //add underfloe
      h->second->SetBinContent(1,y, h->second->GetBinContent(1,y)+ h->second->GetBinContent(0,y) );
      h->second->SetBinError(1,y, sqrt(pow(h->second->GetBinError(1,y),2)+pow(h->second->GetBinError(0,y),2) ) );
    }
    for(int x = 1; x<h->second->GetNbinsX()+1;++x){
      //add overflow
      h->second->SetBinContent(x,h->second->GetNbinsY(), h->second->GetBinContent(x,h->second->GetNbinsY() )+ h->second->GetBinContent(x,h->second->GetNbinsY()+1) );
      h->second->SetBinError(x,h->second->GetNbinsY(), sqrt(pow(h->second->GetBinError(x,h->second->GetNbinsY() ),2)+pow(h->second->GetBinError(x,h->second->GetNbinsY()+1),2) ) );
      //add underfloe
      h->second->SetBinContent(x,1, h->second->GetBinContent(x,1)+ h->second->GetBinContent(x,0) );
      h->second->SetBinError(x,1, sqrt(pow(h->second->GetBinError(x,1),2)+pow(h->second->GetBinError(x,0),2) ) );
    }
  }
  cout << counter << " events " << endl;

  histos["Eff_elel"]      ->Divide(histos["Probe_elel"]      ,histos["Tag_el"]);
  histos["Eff_elMET"]     ->Divide(histos["Probe_elMET"]     ,histos["Tag_el"]);
  histos["Eff_elMHT"]     ->Divide(histos["Probe_elMHT"]     ,histos["Tag_el"]);
  histos["Eff_elMETMHT"]  ->Divide(histos["Probe_elMETMHT"]  ,histos["Tag_el"]);
  histos["Eff_elelMET"]   ->Divide(histos["Probe_elelMET"]   ,histos["Tag_el"]);
  histos["Eff_elelMHT"]   ->Divide(histos["Probe_elelMHT"]   ,histos["Tag_el"]);
  histos["Eff_elelMETMHT"]->Divide(histos["Probe_elelMETMHT"],histos["Tag_el"]);
  histos["Eff2l_elel"]      ->Divide(histos["Probe2l_elel"]      ,histos["Tag2l_el"]);
  histos["Eff2l_elMET"]     ->Divide(histos["Probe2l_elMET"]     ,histos["Tag2l_el"]);
  histos["Eff2l_elMHT"]     ->Divide(histos["Probe2l_elMHT"]     ,histos["Tag2l_el"]);
  histos["Eff2l_elMETMHT"]  ->Divide(histos["Probe2l_elMETMHT"]  ,histos["Tag2l_el"]);
  histos["Eff2l_elelMET"]   ->Divide(histos["Probe2l_elelMET"]   ,histos["Tag2l_el"]);
  histos["Eff2l_elelMHT"]   ->Divide(histos["Probe2l_elelMHT"]   ,histos["Tag2l_el"]);
  histos["Eff2l_elelMETMHT"]->Divide(histos["Probe2l_elelMETMHT"],histos["Tag2l_el"]);
  histos["Eff_mumu"]      ->Divide(histos["Probe_mumu"]      ,histos["Tag_mu"]);
  histos["Eff_muMET"]     ->Divide(histos["Probe_muMET"]     ,histos["Tag_mu"]);
  histos["Eff_muMHT"]     ->Divide(histos["Probe_muMHT"]     ,histos["Tag_mu"]);
  histos["Eff_muMETMHT"]  ->Divide(histos["Probe_muMETMHT"]  ,histos["Tag_mu"]);
  histos["Eff_mumuMET"]   ->Divide(histos["Probe_mumuMET"]   ,histos["Tag_mu"]);
  histos["Eff_mumuMHT"]   ->Divide(histos["Probe_mumuMHT"]   ,histos["Tag_mu"]);
  histos["Eff_mumuMETMHT"]->Divide(histos["Probe_mumuMETMHT"],histos["Tag_mu"]);
  histos["Eff2l_mumu"]      ->Divide(histos["Probe2l_mumu"]      ,histos["Tag2l_mu"]);
  histos["Eff2l_muMET"]     ->Divide(histos["Probe2l_muMET"]     ,histos["Tag2l_mu"]);
  histos["Eff2l_muMHT"]     ->Divide(histos["Probe2l_muMHT"]     ,histos["Tag2l_mu"]);
  histos["Eff2l_muMETMHT"]  ->Divide(histos["Probe2l_muMETMHT"]  ,histos["Tag2l_mu"]);
  histos["Eff2l_mumuMET"]   ->Divide(histos["Probe2l_mumuMET"]   ,histos["Tag2l_mu"]);
  histos["Eff2l_mumuMHT"]   ->Divide(histos["Probe2l_mumuMHT"]   ,histos["Tag2l_mu"]);
  histos["Eff2l_mumuMETMHT"]->Divide(histos["Probe2l_mumuMETMHT"],histos["Tag2l_mu"]);
  cout << __LINE__ << endl;
  string filename = "rootfiles/TriggerEff.root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH2F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  //delete f;
  //for(map<string,TH2F*>::iterator h=histos.begin(); h!=histos.end();++h) delete h->second;


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
