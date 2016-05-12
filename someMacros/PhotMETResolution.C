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
//#include "CMS3_old20150505.cc"
#include "CMS3_forphotstud.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"

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

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  bool usettbar = true;
  TFile *fhelp;
  TH1F *hDataweight1b; TH1F *hDataweight0b; TH1F *hMCweight1b; TH1F *hMCweight0b;
  if(!usettbar){
    fhelp = TFile::Open("rootfiles/PhotonWResolution/NewWeights_NuPtVsPhotPt.root");
    fhelp->cd();
    //hDataweight1b = (TH1F*)fhelp->Get("NuPtPhotPtWeight1bData");
    hDataweight0b = (TH1F*)fhelp->Get("NuPtPhotPtWeight0bData");
    //hMCweight1b = (TH1F*)fhelp->Get("NuPtPhotPtWeight1bMC");
    hMCweight0b = (TH1F*)fhelp->Get("NuPtPhotPtWeight0bMC");
  }
  if(usettbar) {
    fhelp = TFile::Open("rootfiles/PhotonWResolution/NewWeights_NuNuPtVsPhotPt.root");
    fhelp->cd();
    //hDataweight1b = (TH1F*)fhelp->Get("NuNuPtPhotPtWeight1bData");
    hDataweight0b = (TH1F*)fhelp->Get("NuNuPtPhotPtWeight0bData");
    //hMCweight1b = (TH1F*)fhelp->Get("NuNuPtPhotPtWeight1bMC");
    hMCweight0b = (TH1F*)fhelp->Get("NuNuPtPhotPtWeight0bMC");
    //hDataweight1b = (TH1F*)hDataweight0b->Clone("NuNuPtPhotPtWeight1bData");
    //hMCweight1b = (TH1F*)hMCweight0b->Clone("NuNuPtPhotPtWeight1bMC");
  }

  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();

  //changed ge3j to 3j
  histonames.push_back("PhotMET_ge4j0b");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_2j0b");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_3j0b");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_ge4jge1b");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_2jge1b");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_3jge1b");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("RecoMET_PhotMET150_ge4j0b");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_2j0b");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_3j0b");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_ge4jge1b"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_2jge1b"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_3jge1b"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);

  histonames.push_back("PhotMET_ge4j0b_unwgt");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_2j0b_unwgt");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_3j0b_unwgt");              hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_ge4jge1b_unwgt");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_2jge1b_unwgt");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("PhotMET_3jge1b_unwgt");            hbins.push_back(24); hlow.push_back(150.); hup.push_back(750);
  histonames.push_back("RecoMET_PhotMET150_ge4j0b_unwgt");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_2j0b_unwgt");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_3j0b_unwgt");   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_ge4jge1b_unwgt"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_2jge1b_unwgt"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("RecoMET_PhotMET150_3jge1b_unwgt"); hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500);

  histonames.push_back("PhotHT_MET250_ge4j0b");              hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);
  histonames.push_back("PhotHT_MET250_2j0b");              hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);
  histonames.push_back("PhotHT_MET250_3j0b");              hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);
  histonames.push_back("PhotHT_MET250_ge4jge1b");            hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);
  histonames.push_back("PhotHT_MET250_2jge1b");            hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);
  histonames.push_back("PhotHT_MET250_3jge1b");            hbins.push_back(100); hlow.push_back(0.); hup.push_back(1000);

  for(unsigned int i = 0; i<histonames.size(); ++i){
    string samplename = skimFilePrefix;
    string mapname = histonames[i] + "_"+samplename;
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
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

      // Analysis Code
      float weight = cms3.scale1fb()*2.11;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genmetlv;
      genmetlv.SetPxPyPzE(genmet()*TMath::Cos(genmet_phi()),genmet()*TMath::Sin(genmet_phi()),0.,genmet());
      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

  
      if(nvtxs()<0)               continue;
      //if((nge+ngm+ngt)!=0)        continue;
      //if((ngt)!=0)                continue;
      if(ngoodleps()!=0)          continue;
      if(nvetoleps()!=0)          continue;
      if(!PassTrackVeto_v3())     continue;
      if(!PassTauVeto())          continue;
      if(ph_ngoodjets()<2)        continue;
      //if(ngoodbtags()<1)          continue;
      if(ph_met()<250)            continue;
      //if(mt_met_lep()<120)        continue;
      if(ph_mindphi_met_j1_j2()<0.8) continue;
      if(ph_selectedidx()<0) continue;

      int g = ph_selectedidx();
      float phnhiso = TMath::Max(float(ph_nhiso()[g]-photon_NHEA03(g)*EA_centralneutral_rho()),float(0.));//manual EA correction
      float phphiso = TMath::Max(float(ph_phiso()[g]-photon_EMEA03(g)*EA_centralneutral_rho()),float(0.));//manual EA correction
      if(ph_pt().size()!=1) continue;//some loose photons
      if(!ph_idCutBased()[g]) continue;
      //now tight ID
      if(ph_pt()[g]<25) continue;
      if(fabs(ph_eta()[g])>1.44&&fabs(ph_eta()[g])<1.56) continue;
      if(fabs(ph_eta()[g])>2.4) continue;
      if(ph_hOverE()[g]>0.05) continue;
      if(fabs(ph_eta()[g])<1.44){
	if(ph_sigmaIEtaEta_fill5x5()[g]>0.01) continue;
	if(ph_chiso()[g]>0.76) continue;
	if(phnhiso>(0.97 + 0.014*ph_pt()[g] + 0.000019*pow(ph_pt()[g],2))) continue;
	if(phphiso>(0.08 + 0.0053*ph_pt()[g])) continue;
      } else if(fabs(ph_eta()[g])>1.56){
	if(ph_sigmaIEtaEta_fill5x5()[g]>0.0268) continue;
	if(ph_chiso()[g]>0.56) continue;
	if(phnhiso>(2.09 + 0.0139*ph_pt()[g] + 0.000025*pow(ph_pt()[g],2))) continue;
	if(phphiso>(0.16 + 0.0034*ph_pt()[g])) continue;	
      }
      
      float PhotPt = ph_pt()[ph_selectedidx()];

      if(is_data()) weight = 1.;
      int trigscal = 0;
      if(PhotPt>185&&HLT_Photon175()>0) trigscal = HLT_Photon175();
      else if(PhotPt>170&&HLT_Photon165_HE10()>0) trigscal = HLT_Photon165_HE10();
      else if(PhotPt>170&&HLT_Photon165_R9Id90_HE10_IsoM()>0) trigscal = HLT_Photon165_R9Id90_HE10_IsoM();
      else if(PhotPt>125&&HLT_Photon120_R9Id90_HE10_IsoM()>0) trigscal = HLT_Photon120_R9Id90_HE10_IsoM();
      else if(PhotPt>95 &&HLT_Photon90_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon90_R9Id90_HE10_IsoM();
      else if(PhotPt>80 &&HLT_Photon75_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon75_R9Id90_HE10_IsoM();
      else if(PhotPt>55 &&HLT_Photon50_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon50_R9Id90_HE10_IsoM();
      else if(PhotPt>40 &&HLT_Photon36_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon36_R9Id90_HE10_IsoM();
      else if(PhotPt>35 &&HLT_Photon30_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon30_R9Id90_HE10_IsoM();
      else if(PhotPt>25 &&HLT_Photon22_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon22_R9Id90_HE10_IsoM();
      if(trigscal<=0) continue;
      weight = weight * (float)trigscal;
      if( is_data() ) {
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      if(weight>500) cout << "R:L:E " << run() << ":" << ls() << ":" << evt() << " " << weight << endl;
      //if(weight>1000) continue;//this is dangerous.
      if(run()==258177&&ls()==1514&&evt()==2104954776) continue;//weight 800
      if(run()==260627&&ls()==216&&evt()==363792754) continue;//weight 2000

      float weightPt = -1;
      if(is_data() && ph_ngoodbtags()>=1) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else if(is_data() && ph_ngoodbtags()==0) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else if(!is_data() && ph_ngoodbtags()>=1) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else if(!is_data() && ph_ngoodbtags()==0) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else cout << "WTF" << endl;
      /*
      if(is_data() && ph_ngoodbtags()>=1) weightPt = hDataweight0b->GetBinContent(hDataweight0b->FindBin(PhotPt));
      else if(is_data() && ph_ngoodbtags()==0) weightPt = hDataweight0b->GetBinContent(hDataweight0b->FindBin(PhotPt));
      else if(!is_data() && ph_ngoodbtags()>=1) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else if(!is_data() && ph_ngoodbtags()==0) weightPt = hMCweight0b->GetBinContent(hMCweight0b->FindBin(PhotPt));
      else cout << "WTF" << endl;
      */
      bool NB = false;
      if(ph_ngoodbtags()>=1) NB = true;
      int NJ = ph_ngoodjets();
      //bool NJ = false;
      //if(ph_ngoodjets()>=4) NJ = true;
 
      if(NJ>=4&&!NB) histos["PhotMET_ge4j0b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ==3&&!NB) histos["PhotMET_3j0b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ==2&&!NB) histos["PhotMET_2j0b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ>=4&& NB) histos["PhotMET_ge4jge1b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ==3&& NB) histos["PhotMET_3jge1b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ==2&& NB) histos["PhotMET_2jge1b_unwgt_"+samplename]->Fill(ph_met(),weight);
      if(NJ>=4&&!NB) histos["RecoMET_PhotMET150_ge4j0b_unwgt_"+samplename]->Fill(pfmet(),weight);
      if(NJ==3&&!NB) histos["RecoMET_PhotMET150_3j0b_unwgt_"+samplename]->Fill(pfmet(),weight);
      if(NJ==2&&!NB) histos["RecoMET_PhotMET150_2j0b_unwgt_"+samplename]->Fill(pfmet(),weight);
      if(NJ>=4&& NB) histos["RecoMET_PhotMET150_ge4jge1b_unwgt_"+samplename]->Fill(pfmet(),weight);
      if(NJ==3&& NB) histos["RecoMET_PhotMET150_3jge1b_unwgt_"+samplename]->Fill(pfmet(),weight);
      if(NJ==2&& NB) histos["RecoMET_PhotMET150_2jge1b_unwgt_"+samplename]->Fill(pfmet(),weight);

      if(weightPt<0) { cout << "WTF" << endl; continue;}
      weight = weight*weightPt;

      if(NJ>=4&&!NB) histos["PhotMET_ge4j0b_"+samplename]->Fill(ph_met(),weight);
      if(NJ==3&&!NB) histos["PhotMET_3j0b_"+samplename]->Fill(ph_met(),weight);
      if(NJ==2&&!NB) histos["PhotMET_2j0b_"+samplename]->Fill(ph_met(),weight);
      if(NJ>=4&& NB) histos["PhotMET_ge4jge1b_"+samplename]->Fill(ph_met(),weight);
      if(NJ==3&& NB) histos["PhotMET_3jge1b_"+samplename]->Fill(ph_met(),weight);
      if(NJ==2&& NB) histos["PhotMET_2jge1b_"+samplename]->Fill(ph_met(),weight);
      if(NJ>=4&&!NB) histos["RecoMET_PhotMET150_ge4j0b_"+samplename]->Fill(pfmet(),weight);
      if(NJ==3&&!NB) histos["RecoMET_PhotMET150_3j0b_"+samplename]->Fill(pfmet(),weight);
      if(NJ==2&&!NB) histos["RecoMET_PhotMET150_2j0b_"+samplename]->Fill(pfmet(),weight);
      if(NJ>=4&& NB) histos["RecoMET_PhotMET150_ge4jge1b_"+samplename]->Fill(pfmet(),weight);
      if(NJ==3&& NB) histos["RecoMET_PhotMET150_3jge1b_"+samplename]->Fill(pfmet(),weight);
      if(NJ==2&& NB) histos["RecoMET_PhotMET150_2jge1b_"+samplename]->Fill(pfmet(),weight);

      if(ph_met()<250) continue;

      if(NJ>=4&&!NB) histos["PhotHT_MET250_ge4j0b_"+samplename]->Fill(ph_HT(),weight);
      if(NJ==3&&!NB) histos["PhotHT_MET250_3j0b_"+samplename]->Fill(ph_HT(),weight);
      if(NJ==2&&!NB) histos["PhotHT_MET250_2j0b_"+samplename]->Fill(ph_HT(),weight);
      if(NJ>=4&& NB) histos["PhotHT_MET250_ge4jge1b_"+samplename]->Fill(ph_HT(),weight);
      if(NJ==3&& NB) histos["PhotHT_MET250_3jge1b_"+samplename]->Fill(ph_HT(),weight);
      if(NJ==2&& NB) histos["PhotHT_MET250_2jge1b_"+samplename]->Fill(ph_HT(),weight);
      
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
    //add underfloe
    //h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    //h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  string filename = "rootfiles/PhotonWResolution/NewPhotMETResolutionIncl2jkilllow_"+skimFilePrefix+".root";
  if(usettbar) filename = "rootfiles/PhotonWResolution/NewPhotMETResolutionTTIncl2j_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  delete f;
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h) delete h->second;


  fhelp->Close();
  delete fhelp;
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
