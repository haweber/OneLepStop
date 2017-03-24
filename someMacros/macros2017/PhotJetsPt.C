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
#include "CMS3_photon.cc"
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
  
  if(       abs(eta) < 1.0   ){ EA = 0.0360;
  }else if( abs(eta) < 1.479 ){ EA = 0.0377;
  }else if( abs(eta) < 2.0   ){ EA = 0.0306;
  }else if( abs(eta) < 2.2   ){ EA = 0.0283;
  }else if( abs(eta) < 2.3   ){ EA = 0.0254;
  }else if( abs(eta) < 2.4   ){ EA = 0.0217;
  }else if( abs(eta) > 2.4   ){ EA = 0.0167;
  }
  
  return EA;
}
float photon_NHEA03( int photonIdx )
{
  float eta = ph_eta()[photonIdx];
  float EA = -999;
  
  if(       abs(eta) < 1.0   ){ EA = 0.0597;
  }else if( abs(eta) < 1.479 ){ EA = 0.0807;
  }else if( abs(eta) < 2.0   ){ EA = 0.0629;
  }else if( abs(eta) < 2.2   ){ EA = 0.0197;
  }else if( abs(eta) < 2.3   ){ EA = 0.0184;
  }else if( abs(eta) < 2.4   ){ EA = 0.0284;
  }else if( abs(eta) > 2.4   ){ EA = 0.0591;
  }
  
  return EA;
}
float photon_EMEA03( int photonIdx )
{
  float eta = ph_eta()[photonIdx];
  float EA = -999;
  
  if(       abs(eta) < 1.0   ){ EA = 0.1210;
  }else if( abs(eta) < 1.479 ){ EA = 0.1107;
  }else if( abs(eta) < 2.0   ){ EA = 0.0699;
  }else if( abs(eta) < 2.2   ){ EA = 0.1056;
  }else if( abs(eta) < 2.3   ){ EA = 0.1457;
  }else if( abs(eta) < 2.4   ){ EA = 0.1719;
  }else if( abs(eta) > 2.4   ){ EA = 0.1998;
  }
  
  return EA;
}
bool photon_tightid( int photonIdx )
{
  //if(!ph_idCutBased()[photonIdx]) return false;
  if(ph_pt()[photonIdx]<25) return false;
  if(fabs(ph_eta()[photonIdx])>1.44&&fabs(ph_eta()[photonIdx])<1.56) return false;
  if(fabs(ph_eta()[photonIdx])>2.5) return false;
  float phnhiso = TMath::Max(float(ph_nhiso()[photonIdx]-photon_NHEA03(photonIdx)*EA_fixgridfastjet_all_rho()),float(0.));//manual EA correction is not fully correct, but what can you do ...
  float phphiso = TMath::Max(float(ph_phiso()[photonIdx]-photon_EMEA03(photonIdx)*EA_fixgridfastjet_all_rho()),float(0.));//manual EA correction is not fully correct, but what can you do ...
  float phchiso = TMath::Max(float(ph_chiso()[photonIdx]-photon_CHEA03(photonIdx)*EA_fixgridfastjet_all_rho()),float(0.));//manual EA correction is not fully correct, but what can you do ...
  if(fabs(ph_eta()[photonIdx])<1.44){
    if(ph_hOverE()[photonIdx]>0.0269) return false;
    if(ph_sigmaIEtaEta_fill5x5()[photonIdx]>0.00994) return false;
    if(phchiso>0.202) return false;
    if(phnhiso>(0.264 + 0.0148*ph_pt()[photonIdx] + 0.000017*pow(ph_pt()[photonIdx],2))) return false;
    if(phphiso>(2.362 + 0.0047*ph_pt()[photonIdx])) return false;
    return true;
  }
  else {
    if(ph_hOverE()[photonIdx]>0.0213) return false;
    if(ph_sigmaIEtaEta_fill5x5()[photonIdx]>0.03) return false;
    if(phchiso>0.034) return false;
    if(phnhiso>(0.586 + 0.0163*ph_pt()[photonIdx] + 0.000014*pow(ph_pt()[photonIdx],2))) return false;
    if(phphiso>(2.617 + 0.0034*ph_pt()[photonIdx])) return false;
    return true;
  }
}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float dPhibetweenVectors(float vec1,float vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1 - vec2), 2 * M_PI - fabs(vec1 - vec2));

  return sqrt(dphi*dphi);
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

    TH1F *fac = new TH1F("fac","",30,2000,17000);
    fac->SetBinContent( 1, 1);//2000
    fac->SetBinContent( 2, 1);
    fac->SetBinContent( 3, 1);
    fac->SetBinContent( 4, 1);
    fac->SetBinContent( 5, 1);
    fac->SetBinContent( 6, 1);
    fac->SetBinContent( 7, 1);//5000
    fac->SetBinContent( 8, 0.975);
    fac->SetBinContent( 9, 0.95);
    fac->SetBinContent(10, 0.925);
    fac->SetBinContent(11, 0.9);
    fac->SetBinContent(12, 0.9);//7500
    fac->SetBinContent(13, 0.88);//1.
    fac->SetBinContent(14, 0.85);//1.
    fac->SetBinContent(15, 1.);//1.
    fac->SetBinContent(16, 0.99);
    fac->SetBinContent(17, 0.975);//10000
    fac->SetBinContent(18, 0.975);
    fac->SetBinContent(19, 0.96);
    fac->SetBinContent(20, 0.95);
    fac->SetBinContent(21, 0.94);
    fac->SetBinContent(22, 0.925);//12500
    fac->SetBinContent(23, 0.92);
    fac->SetBinContent(24, 0.905);
    fac->SetBinContent(25, 0.9);
    fac->SetBinContent(26, 0.89);
    fac->SetBinContent(27, 0.875);//15000
    fac->SetBinContent(28, 0.87);
    fac->SetBinContent(29, 0.86);
    fac->SetBinContent(30, 0.85);
  
  histonames.push_back("PhotPt_MET150_23j");                 hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000);
  histonames.push_back("PhotPt_MET150_4j");                  hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000); 
  histonames.push_back("PhotPt_MET150_5j");                  hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000); 
  histonames.push_back("PhotMETDPhi_MET30_23j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET30_4j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET30_5j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET60_23j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET60_4j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET60_5j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET100_23j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET100_4j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotMETDPhi_MET100_5j");                   hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2); 
  histonames.push_back("PhotNJets_MET150");                   hbins.push_back(7); hlow.push_back(  0.); hup.push_back(7); 
  histonames.push_back("PhotNJetsP_MET150");                   hbins.push_back(7); hlow.push_back(  0.); hup.push_back(7); 
  histonames.push_back("PhotHT_MET150");                   hbins.push_back(40); hlow.push_back(  0.); hup.push_back(800); 
  histonames.push_back("PhotE_MET150");                   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000); 
  histonames.push_back("PhotEmod_MET150");                   hbins.push_back(100); hlow.push_back(  0.); hup.push_back(1000); 

  for(unsigned int i = 0; i<histonames.size(); ++i){
    string samplename = skimFilePrefix;
    string mapname = histonames[i] + "_"+samplename;
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

  const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  set_goodrun_file_json(json_file);

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
      float weight = cms3.scale1fb()*36.8;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;
  
      if(nvtxs()<0)                  continue;
      if(ngoodleps()!=0)             continue;
      if(nvetoleps()!=0)             continue;
      if(!PassTrackVeto())           continue;
      if(!PassTauVeto())             continue;
      if(ph_ngoodjets()<2)           continue;
      if(ph_ngoodbtags()!=0)         continue;
      if(ph_met()<150)               continue;
      if(ph_mindphi_met_j1_j2()<0.8) continue;
      if(ph_selectedidx()<0)         continue;
      if(is_data()&&filt_badMuonFilter()!=1) continue;
      if(is_data()&&filt_badChargedCandidateFilter()!=1) continue;
      if(is_data()&&filt_met()!=1) continue;
      if(is_data()&&filt_hcallaser()!=1) continue;
      if(is_data()&&filt_jetWithBadMuon()!=1) continue;
      if(is_data()&&filt_pfovercalomet()!=1) continue;
      
      if( is_data() && !goodrun(run(), ls()) ) continue;

      float PhotPt = ph_pt()[ph_selectedidx()];
      if(PhotPt<55) continue;
      if(photon_tightid(ph_selectedidx() )==false) continue;

      TString currentfilename = currentFile->GetTitle();
      if(currentfilename.Contains("GJets_DR0p4_HT")) { if(ph_drMinParton()[ph_selectedidx()]< 0.4) continue; }
      if(currentfilename.Contains("GJets_HT"))       { if(ph_drMinParton()[ph_selectedidx()]>=0.4) continue; }
      //if(currentfilename.Contains("GJets_HT")&&!currentfilename.Contains("GJets_HT400to600_25ns"))       { if(ph_drMinParton()[ph_selectedidx()]>=0.4) continue; }
      if(currentfilename.Contains("GJets_HT600toInf_ext1_25ns")) weight *= 2280002./(2280002.+2382062.);
      if(currentfilename.Contains("GJets_HT600toInf_25ns")     ) weight *= 2382062./(2280002.+2382062.);

      if(is_data()) weight = 1.;
      int trigscal = 0;
      if(PhotPt>600&&HLT_CaloJet500_NoJetID()>0)              trigscal = HLT_CaloJet500_NoJetID();
      else if(PhotPt>270&&HLT_Photon250_NoHE()>0)             trigscal = HLT_Photon250_NoHE();
      else if(PhotPt>185&&HLT_Photon175()>0)                  trigscal = HLT_Photon175();
      else if(PhotPt>170&&HLT_Photon165_HE10()>0)             trigscal = HLT_Photon165_HE10();
      else if(PhotPt>170&&HLT_Photon165_R9Id90_HE10_IsoM()>0) trigscal = HLT_Photon165_R9Id90_HE10_IsoM();
      else if(PhotPt>125&&HLT_Photon120_R9Id90_HE10_IsoM()>0) trigscal = HLT_Photon120_R9Id90_HE10_IsoM();
      else if(PhotPt>95 &&HLT_Photon90_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon90_R9Id90_HE10_IsoM();
      else if(PhotPt>80 &&HLT_Photon75_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon75_R9Id90_HE10_IsoM();
      else if(PhotPt>55 &&HLT_Photon50_R9Id90_HE10_IsoM()>0 ) trigscal = HLT_Photon50_R9Id90_HE10_IsoM();
      else if(PhotPt>125 &&HLT_Photon120()>0 )                trigscal = HLT_Photon120();
      //if(is_data()) cout << "photpt " << PhotPt << " trigger " << trigscal << endl;
      if(is_data()&&trigscal<=0) continue;
      if(is_data()) weight = weight * (float)trigscal;
      //if(run()==283933&&ls()==139&&evt()==112841398) cout << currentFile->GetTitle() << endl;
      if( is_data() ) {
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	//if (is_duplicate(id) ) cout << "Event gets removed " << run() << ":" << ls() << ":" << evt() << endl;
	if (is_duplicate(id) ) continue;
      }
      if(weight>500) cout << "R:L:E " << run() << ":" << ls() << ":" << evt() << " " << weight << endl;
      //if(weight>1000) continue;//this is dangerous.

      histos["PhotNJets_MET150_" +samplename]->Fill(ph_ngoodjets(),weight);
      histos["PhotNJetsP_MET150_" +samplename]->Fill(ngoodjets(),weight);
      histos["PhotHT_MET150_" +samplename]->Fill(ph_HT(),weight);

      //if(is_data()) cout << run() << ":" << ls() << ":" << evt() << ph_ngoodjets() << " " << PhotPt << " " << weight << endl;
      
      if(ph_ngoodjets()<=3) histos["PhotPt_MET150_23j_" +samplename]->Fill(PhotPt,weight);
      else                  histos["PhotPt_MET150_4j_"  +samplename]->Fill(PhotPt,weight);
      if(ph_ngoodjets()>=5) histos["PhotPt_MET150_5j_"  +samplename]->Fill(PhotPt,weight);

      if(PhotPt>55&&pfmet()>30){
	if(ph_ngoodjets()<=3) histos["PhotMETDPhi_MET30_23j_" +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	else                  histos["PhotMETDPhi_MET30_4j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	if(ph_ngoodjets()>=5) histos["PhotMETDPhi_MET30_5j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
      }
      if(PhotPt>55&&pfmet()>60){
	if(ph_ngoodjets()<=3) histos["PhotMETDPhi_MET60_23j_" +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	else                  histos["PhotMETDPhi_MET60_4j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	if(ph_ngoodjets()>=5) histos["PhotMETDPhi_MET60_5j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
      }
      if(PhotPt>55&&pfmet()>100){
	if(ph_ngoodjets()<=3) histos["PhotMETDPhi_MET100_23j_" +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	else                  histos["PhotMETDPhi_MET100_4j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
	if(ph_ngoodjets()>=5) histos["PhotMETDPhi_MET100_5j_"  +samplename]->Fill(dPhibetweenVectors(pfmet_phi(),ph_p4()[ph_selectedidx()].Phi()),weight);
      }
      if(fabs(ph_p4()[ph_selectedidx()].Eta()<1.444)){
	histos["PhotE_MET150_" +samplename]->Fill(ph_p4()[ph_selectedidx()].E(),weight);
	float oldadc = ph_p4()[ph_selectedidx()].E()*0.7/0.04;
	float newadc = oldadc;
	if(newadc>17000) newadc/=0.8;
	else newadc /=fac->GetBinContent(fac->FindBin(oldadc));
	float newe = ph_p4()[ph_selectedidx()].E() + (newadc-oldadc)*0.04;
	histos["PhotEmod_MET150_" +samplename]->Fill(newe,weight);
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
    //add underfloe
    h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  string filename = "rootfiles/PhotonMETResolution/PhotPt_"+skimFilePrefix+".root";
  //string filename = "rootfiles/PhotonMETResolution_reminiAOD/PhotPt_"+skimFilePrefix+".root";
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
