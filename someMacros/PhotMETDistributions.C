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

  TFile *fw = new TFile("rootfiles/PhotonMETResolution/NuOrNunuPtVsPhotPt.root","RECREATE");
  fw->cd();
  TH1F* hrat_data_23j_lMlb_1ltop = (TH1F*)fw->Get("NuPtVsPhotPt_23j_lMlb_1ltopVsData");
  TH1F* hrat_data_23j_hMlb_1ltop = (TH1F*)fw->Get("NuPtVsPhotPt_23j_hMlb_1ltopVsData");
  TH1F* hrat_data_4j_lMlb_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_4j_lMlb_1ltopVsData");
  TH1F* hrat_data_4j_hMlb_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_4j_hMlb_1ltopVsData");
  TH1F* hrat_sim_23j_lMlb_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_23j_lMlb_1ltopVsSim");
  TH1F* hrat_sim_23j_hMlb_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_23j_hMlb_1ltopVsSim");
  TH1F* hrat_sim_4j_lMlb_1ltop   = (TH1F*)fw->Get("NuPtVsPhotPt_4j_lMlb_1ltopVsSim");
  TH1F* hrat_sim_4j_hMlb_1ltop   = (TH1F*)fw->Get("NuPtVsPhotPt_4j_hMlb_1ltopVsSim");
  TH1F* hrat_data_23j_ltmod_2l = (TH1F*)fw->Get("NuNuPtVsPhotPt_23j_ltmod_2lVsData");
  TH1F* hrat_data_23j_htmod_2l = (TH1F*)fw->Get("NuNuPtVsPhotPt_23j_htmod_2lVsData");
  TH1F* hrat_data_4j_ltmod_2l  = (TH1F*)fw->Get("NuNuPtVsPhotPt_4j_ltmod_2lVsData");
  TH1F* hrat_data_4j_htmod_2l  = (TH1F*)fw->Get("NuNuPtVsPhotPt_4j_htmod_2lVsData");
  TH1F* hrat_sim_23j_ltmod_2l  = (TH1F*)fw->Get("NuNuPtVsPhotPt_23j_ltmod_2lVsSim");
  TH1F* hrat_sim_23j_htmod_2l  = (TH1F*)fw->Get("NuNuPtVsPhotPt_23j_htmod_2lVsSim");
  TH1F* hrat_sim_4j_ltmod_2l   = (TH1F*)fw->Get("NuNuPtVsPhotPt_4j_ltmod_2lVsSim");
  TH1F* hrat_sim_4j_htmod_2l   = (TH1F*)fw->Get("NuNuPtVsPhotPt_4j_htmod_2lVsSim");
  TH1F* hrat_data_23j_1ltop = (TH1F*)fw->Get("NuPtVsPhotPt_23j_1ltopVsData");
  TH1F* hrat_data_4j_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_4j_1ltopVsData");
  TH1F* hrat_data_23j_2l    = (TH1F*)fw->Get("NuPtVsPhotPt_23j_2lVsData");
  TH1F* hrat_data_4j_2l     = (TH1F*)fw->Get("NuPtVsPhotPt_4j_2lVsData");
  TH1F* hrat_sim_23j_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_23j_1ltopVsSim");
  TH1F* hrat_sim_4j_1ltop   = (TH1F*)fw->Get("NuPtVsPhotPt_4j_1ltopVsSim");
  TH1F* hrat_sim_23j_2l     = (TH1F*)fw->Get("NuPtVsPhotPt_23j_2lVsSim");
  TH1F* hrat_sim_4j_2l      = (TH1F*)fw->Get("NuPtVsPhotPt_4j_2lVsSim");
  TH1F* hrat_data_5j_1ltop  = (TH1F*)fw->Get("NuPtVsPhotPt_5j_1ltopVsData");
  TH1F* hrat_data_5j_2l     = (TH1F*)fw->Get("NuPtVsPhotPt_5j_2lVsData");
  TH1F* hrat_sim_5j_1ltop   = (TH1F*)fw->Get("NuPtVsPhotPt_5j_1ltopVsSim");
  TH1F* hrat_sim_5j_2l      = (TH1F*)fw->Get("NuPtVsPhotPt_5j_2lVsSim");
  //TFile *feff = TFile::Open("rootfiles/PhotonMETResolution/phot_eff.root");
  //TH1D *heff = (TH1D*)feff->Get("eff");


  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();

  histonames.push_back("PhotMET_23j_1ltop");             hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_1ltop");              hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_23j_lMlb_1ltop");        hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_lMlb_1ltop");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_23j_hMlb_1ltop");        hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_hMlb_1ltop");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_5j_1ltop");              hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);

  histonames.push_back("PhotMET_23j_2l");              hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_2l");               hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_23j_ltmod_2l");        hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_ltmod_2l");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_23j_htmod_2l");        hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_htmod_2l");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_5j_2l");               hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);

  histonames.push_back("PhotMET_23j_noweight");             hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_4j_noweight");              hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("PhotMET_5j_noweight");              hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);

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
      float weight = cms3.scale1fb()*31;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      if(nvtxs()<0)                  continue;
      if(ngoodleps()!=0)             continue;
      if(nvetoleps()!=0)             continue;
      if(!PassTrackVeto())           continue;
      if(!PassTauVeto())             continue;
      if(ph_ngoodjets()<2)           continue;
      if(ph_ngoodbtags()!=0)         continue;
      if(ph_met()<250)               continue;
      if(ph_mindphi_met_j1_j2()<0.8) continue;
      if(ph_selectedidx()<0)         continue;

      float PhotPt = ph_pt()[ph_selectedidx()];
      if(PhotPt<55) continue;
      if(photon_tightid(ph_selectedidx() )==false) continue;

      TString currentfilename = currentFile->GetTitle();
      if(currentfilename.Contains("GJets_DR0p4_HT")) { if(ph_drMinParton()[selectedidx]< 0.4) continue; }
      if(currentfilename.Contains("GJets_HT"))       { if(ph_drMinParton()[selectedidx]>=0.4) continue; }

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
      else if(PhotPt>125 &&HLT_Photon120()>0 )                trigscal = HLTPhoton120();
      if(is_data()&&trigscal<=0) continue;
      if(is_data()) weight = weight * (float)trigscal;
      if( is_data() ) {
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      if(weight>500) cout << "R:L:E " << run() << ":" << ls() << ":" << evt() << " " << weight << endl;
      //if(weight>1000) continue;//this is dangerous.

      float weight2lltmod = -1;
      float weight2lhtmod = -1;
      float weight1llMlb = -1;
      float weight1lhMlb = -1;
      float weight2l = -1;
      float weight1l = -1;
      float weight2l5j = -1;
      float weight1l5j = -1;
      int NJ = ph_ngoodjets();

      if(isdata()){
	if(ph_ngoodjets()<=3){
	  weight2lltmod = hrat_data_23j_ltmod_2l->GetBinContent(hrat_data_23j_ltmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2lhtmod = hrat_data_23j_htmod_2l->GetBinContent(hrat_data_23j_htmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2l      = hrat_data_23j_2l      ->GetBinContent(hrat_data_23j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1llMlb  = hrat_data_23j_lMlb_1ltop->GetBinContent(hrat_data_23j_lMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1lhMlb  = hrat_data_23j_hMlb_1ltop->GetBinContent(hrat_data_23j_hMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1l      = hrat_data_23j_1ltop     ->GetBinContent(hrat_data_23j_1ltop     ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	} else {
	  weight2lltmod = hrat_data_4j_ltmod_2l->GetBinContent(hrat_data_4j_ltmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2lhtmod = hrat_data_4j_htmod_2l->GetBinContent(hrat_data_4j_htmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2l      = hrat_data_4j_2l      ->GetBinContent(hrat_data_4j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1llMlb  = hrat_data_4j_lMlb_1ltop->GetBinContent(hrat_data_4j_lMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1lhMlb  = hrat_data_4j_hMlb_1ltop->GetBinContent(hrat_data_4j_hMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1l      = hrat_data_4j_1ltop     ->GetBinContent(hrat_data_4j_1ltop     ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	}
	weight2l5j      = hrat_data_5j_2l      ->GetBinContent(hrat_data_5j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	weight1l5j      = hrat_data_5j_1ltop   ->GetBinContent(hrat_data_5j_1ltop   ->FindBin(TMath::Min(PhotPt,(float)999.99)));

      } else {
	if(ph_ngoodjets()<=3){
	  weight2lltmod = hrat_sim_23j_ltmod_2l->GetBinContent(hrat_sim_23j_ltmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2lhtmod = hrat_sim_23j_htmod_2l->GetBinContent(hrat_sim_23j_htmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2l      = hrat_sim_23j_2l      ->GetBinContent(hrat_sim_23j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1llMlb  = hrat_sim_23j_lMlb_1ltop->GetBinContent(hrat_sim_23j_lMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1lhMlb  = hrat_sim_23j_hMlb_1ltop->GetBinContent(hrat_sim_23j_hMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1l      = hrat_sim_23j_1ltop     ->GetBinContent(hrat_sim_23j_1ltop     ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	} else {
	  weight2lltmod = hrat_sim_4j_ltmod_2l->GetBinContent(hrat_sim_4j_ltmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2lhtmod = hrat_sim_4j_htmod_2l->GetBinContent(hrat_sim_4j_htmod_2l->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight2l      = hrat_sim_4j_2l      ->GetBinContent(hrat_sim_4j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1llMlb  = hrat_sim_4j_lMlb_1ltop->GetBinContent(hrat_sim_4j_lMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1lhMlb  = hrat_sim_4j_hMlb_1ltop->GetBinContent(hrat_sim_4j_hMlb_1ltop->FindBin(TMath::Min(PhotPt,(float)999.99)));
	  weight1l      = hrat_sim_4j_1ltop     ->GetBinContent(hrat_sim_4j_1ltop     ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	}
 	weight2l5j      = hrat_sim_5j_2l      ->GetBinContent(hrat_sim_5j_2l      ->FindBin(TMath::Min(PhotPt,(float)999.99)));
	weight1l5j      = hrat_sim_5j_1ltop   ->GetBinContent(hrat_sim_5j_1ltop   ->FindBin(TMath::Min(PhotPt,(float)999.99)));
      }

      if(ph_ngoodjets()<=3){
	histos["PhotMET_23j_noweight_"  +samplename]->Fill(ph_met(),weight);
	histos["PhotMET_23j_1ltop_"     +samplename]->Fill(ph_met(),weight*weight1l);
	histos["PhotMET_23j_lMlb_1ltop_"+samplename]->Fill(ph_met(),weight*weight1llMlb);
	histos["PhotMET_23j_hMlb_1ltop_"+samplename]->Fill(ph_met(),weight*weight1lhMlb);
	histos["PhotMET_23j_2l_"        +samplename]->Fill(ph_met(),weight*weight2l);
	histos["PhotMET_23j_ltmod_2l_"  +samplename]->Fill(ph_met(),weight*weight2lltmod);
	histos["PhotMET_23j_htmod_2l_"  +samplename]->Fill(ph_met(),weight*weight2lhtmod);
      }
      else {
	histos["PhotMET_4j_noweight_"  +samplename]->Fill(ph_met(),weight);
	histos["PhotMET_4j_1ltop_"     +samplename]->Fill(ph_met(),weight*weight1l);
	histos["PhotMET_4j_lMlb_1ltop_"+samplename]->Fill(ph_met(),weight*weight1llMlb);
	histos["PhotMET_4j_hMlb_1ltop_"+samplename]->Fill(ph_met(),weight*weight1lhMlb);
	histos["PhotMET_4j_2l_"        +samplename]->Fill(ph_met(),weight*weight2l);
	histos["PhotMET_4j_ltmod_2l_"  +samplename]->Fill(ph_met(),weight*weight2lltmod);
	histos["PhotMET_4j_htmod_2l_"  +samplename]->Fill(ph_met(),weight*weight2lhtmod);
	if(ph_ngoodjets()>=5){
	  histos["PhotMET_5j_noweight_"  +samplename]->Fill(ph_met(),weight);
	  histos["PhotMET_5j_1ltop_"     +samplename]->Fill(ph_met(),weight*weight1l5j);
	  histos["PhotMET_5j_2l_"        +samplename]->Fill(ph_met(),weight*weight2l5j);
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
    //add underfloe
    //h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    //h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  string filename = "rootfiles/PhotonMETResolution/PhotMETDistribution_NuorNuNuPtweighted_"+skimFilePrefix+".root";
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
