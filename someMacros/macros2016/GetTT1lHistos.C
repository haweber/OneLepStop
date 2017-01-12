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
  TFile *f_el_SF       = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/kinematicBinSFele.root", "read");
  TFile *f_mu_SF_id    = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/TnP_MuonID_NUM_MediumID_DENOM_generalTracks_VAR_map_pt_eta.root", "read");
  TFile *f_mu_SF_iso   = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/TnP_MuonID_NUM_MiniIsoTight_DENOM_LooseID_VAR_map_pt_eta.root");
  TFile *f_mu_SF_veto_id  = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/TnP_MuonID_NUM_LooseID_DENOM_generalTracks_VAR_map_pt_eta.root", "read");
  TFile *f_mu_SF_veto_iso = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/TnP_MuonID_NUM_MiniIsoTight_DENOM_LooseID_VAR_map_pt_eta.root");
  //TFile *f_mu_SF_veto_iso = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/TnP_MuonID_NUM_MiniIsoLoose_DENOM_LooseID_VAR_map_pt_eta.root");
  //TFile *f_vetoLep_eff = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/lepeff__ttbar_powheg_pythia8_25ns.root", "read");
  TFile *f_vetoLep_eff = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/lepeff__ttbar_powheg_pythia8_25ns__SRcuts.root", "read");  
  TH2D *h_el_SF_id_temp      = (TH2D*)f_el_SF->Get("CutBasedMedium");
  TH2D *h_el_SF_iso_temp     = (TH2D*)f_el_SF->Get("MiniIso0p1_vs_AbsEta");
  TH2D *h_el_SF_veto_id_temp  = (TH2D*)f_el_SF->Get("CutBasedVeto");
  TH2D *h_el_SF_veto_iso_temp = (TH2D*)f_el_SF->Get("MiniIso0p4_vs_AbsEta");
  TH2D *h_mu_SF_id_temp      = (TH2D*)f_mu_SF_id->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_tag_IsoMu20_pass");
  TH2D *h_mu_SF_iso_temp     = (TH2D*)f_mu_SF_iso->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_PF_pass_&_tag_IsoMu20_pass");
  TH2D *h_mu_SF_veto_id_temp  = (TH2D*)f_mu_SF_veto_id->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_tag_IsoMu20_pass");
  TH2D *h_mu_SF_veto_iso_temp = (TH2D*)f_mu_SF_veto_iso->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_PF_pass_&_tag_IsoMu20_pass");
  //TH2D *h_el_vetoLepEff_temp = (TH2D*)f_vetoLep_eff->Get("h2_lepEff_vetoSel_Eff_el");
  //TH2D *h_mu_vetoLepEff_temp = (TH2D*)f_vetoLep_eff->Get("h2_lepEff_vetoSel_Eff_mu");
  TH2D *h_el_vetoLepEff_temp = (TH2D*)f_vetoLep_eff->Get("h2_lepEff_vetoSel_rebin_Eff_el");
  TH2D *h_mu_vetoLepEff_temp = (TH2D*)f_vetoLep_eff->Get("h2_lepEff_vetoSel_rebin_Eff_mu");
  TH2D *h_el_SF_id  = (TH2D*)h_el_SF_id_temp->Clone("h_el_SF_id");
  TH2D *h_el_SF_iso = (TH2D*)h_el_SF_iso_temp->Clone("h_el_SF_iso");
  TH2D *h_mu_SF_id  = (TH2D*)h_mu_SF_id_temp->Clone("h_mu_SF_id");
  TH2D *h_mu_SF_iso = (TH2D*)h_mu_SF_iso_temp->Clone("h_mu_SF_iso");
  TH2D *h_el_SF_veto_id  = (TH2D*)h_el_SF_veto_id_temp->Clone("h_el_SF_veto_id");
  TH2D *h_el_SF_veto_iso = (TH2D*)h_el_SF_veto_iso_temp->Clone("h_el_SF_veto_iso");
  TH2D *h_mu_SF_veto_id  = (TH2D*)h_mu_SF_veto_id_temp->Clone("h_mu_SF_veto_id");
  TH2D *h_mu_SF_veto_iso = (TH2D*)h_mu_SF_veto_iso_temp->Clone("h_mu_SF_veto_iso");
  //This is are the important ones
  TH2D *h_el_vetoLepEff = (TH2D*)h_el_vetoLepEff_temp->Clone("h_el_vetoLepEff");
  TH2D *h_mu_vetoLepEff = (TH2D*)h_mu_vetoLepEff_temp->Clone("h_mu_vetoLepEff");
  TH2D *h_el_SF = (TH2D*)h_el_SF_id->Clone("h_el_SF");
  h_el_SF->Multiply(h_el_SF_iso);
  TH2D *h_el_SF_veto = (TH2D*)h_el_SF_veto_id->Clone("h_el_SF_veto");
  TH2D *h_mu_SF = (TH2D*)h_mu_SF_id->Clone("h_mu_SF");
  h_mu_SF->Multiply(h_mu_SF_iso);
  TH2D *h_mu_SF_veto = (TH2D*)h_mu_SF_veto_id->Clone("h_mu_SF_veto");
  h_mu_SF_veto->Multiply(h_mu_SF_veto_iso);
  TFile *f_el_FS_ID       = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/sf_el_mediumCB.root", "read");
  TFile *f_el_FS_Iso      = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/sf_el_mini01.root", "read");
  TFile *f_mu_FS_ID       = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/sf_mu_mediumID.root", "read");
  TFile *f_mu_FS_Iso      = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/lepsf/sf_mu_mini02.root", "read");
  TH2D *h_el_FS_ID_temp  = (TH2D*)f_el_FS_ID ->Get("histo2D");
  //TH2D *h_el_FS_ID       = (TH2D*)h_el_FS_ID_temp ->Clone("h_el_FS_ID");
  TH2D *h_el_FS          = (TH2D*)h_el_FS_ID_temp ->Clone("h_el_FS");
  TH2D *h_el_FS_Iso_temp = (TH2D*)f_el_FS_Iso->Get("histo2D");
  //TH2D *h_el_FS_Iso      = (TH2D*)h_el_FS_Iso_temp->Clone("h_el_FS_Iso");
  h_el_FS->Multiply(h_el_FS_Iso_temp);
  TH2D *h_mu_FS_ID_temp  = (TH2D*)f_mu_FS_ID ->Get("histo2D");
  //TH2D *h_mu_FS_ID       = (TH2D*)h_mu_FS_ID_temp ->Clone("h_mu_FS_ID");
  TH2D *h_mu_FS          = (TH2D*)h_mu_FS_ID_temp ->Clone("h_mu_FS");
  TH2D *h_mu_FS_Iso_temp = (TH2D*)f_mu_FS_Iso->Get("histo2D");
  //TH2D *h_mu_FS_Iso      = (TH2D*)h_mu_FS_Iso_temp->Clone("h_mu_FS_ID");
  h_mu_FS->Multiply(h_mu_FS_Iso_temp);

  
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1D*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins;  hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup;  hup.clear();

  histonames.push_back("CRtt1l_yield");       hbins.push_back(9); hlow.push_back(  0.); hup.push_back(9.5);
  histonames.push_back("LepSF");       hbins.push_back(200); hlow.push_back(  0.); hup.push_back(2);
  histonames.push_back("BSF");       hbins.push_back(200); hlow.push_back(  0.); hup.push_back(2);


  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1D(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
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

    counterhist = (TH1D*)file->Get("h_counter");
    counterhist->SetDirectory(0);
    double BSFnorm = counterhist->GetBinContent(counterhist->FindBin(14));
    double norm = counterhist->GetBinContent(counterhist->FindBin(22));
      
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
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;
      bool istt1l = is1lepFromTop();
      if(istt1l) count2 += weight;
      else count1 += weight;
      if(is1lep()) count3 += weight;
      if(is2lep()) count4 += weight;
      
      
      if(!is1lepFromTop()) continue;

      float lepSF_pt_cutoff = 100.0;
      float lepSF_pt_min    = 10.0;
      double lepSF    = 1.0;
      double lepSF_Up = 1.0;
      double lepSF_Dn = 1.0;
      float lepSF_FS_pt_cutoff = 200.0;
      double lepSF_FS    = 1.0;
      double lepSF_FS_Up = 1.0;
      double lepSF_FS_Dn = 1.0;	
      if(lep1_is_el()){
	int binX = h_el_SF->GetXaxis()->FindBin( std::min(lepSF_pt_cutoff, (float)lep1_p4().Pt()) );
	int binY = h_el_SF->GetYaxis()->FindBin( fabs(lep1_p4().Eta()) );
	lepSF    = h_el_SF->GetBinContent( binX, binY );
	lepSF_Up = lepSF + h_el_SF->GetBinError( binX, binY );
	lepSF_Dn = lepSF - h_el_SF->GetBinError( binX, binY );
      }
      if(lep1_is_mu()){
	int binX = h_mu_SF->GetXaxis()->FindBin( std::min(lepSF_pt_cutoff, (float)lep1_p4().Pt()) );
	int binY = h_mu_SF->GetYaxis()->FindBin( fabs(lep1_p4().Eta()) );
	lepSF    = h_mu_SF->GetBinContent( binX, binY );
	lepSF_Up = lepSF + h_mu_SF->GetBinError( binX, binY );
	lepSF_Dn = lepSF - h_mu_SF->GetBinError( binX, binY );
      }
      double BSFweight = weight_btagsf();
      if(BSFnorm>0) BSFweight *=norm/BSFnorm;

      weight *= (BSFweight * lepSF);
      histos["LepSF"]->Fill(lepSF);
      histos["BSF"]->Fill(BSFweight);
      
      int SR = -1;
      if(ngoodjets()>=4){
	if(MT2W()<=200){
	  if(pfmet()>325) SR = 6;
	  else SR = 5;
	} else { //high MT2W
	  if(pfmet()>450) SR = 9;
	  else if(pfmet()>350) SR = 8;
	  else SR = 7;
	}
      } else if(ngoodjets()==3 && MT2W()>200) {
	if(pfmet()>350) SR = 4;
	else SR = 3;
      } else if(ngoodjets()==2&&topnessMod()>6.4) { //2 or 3 jets
	if(pfmet()>350) SR = 2;
	else SR = 1;
      }

      if(     SR==1) weight *= 1.032;
      else if(SR==2) weight *= 0.913;
      else if(SR==3) weight *= 1.032;
      else if(SR==4) weight *= 0.928;
      else if(SR==5) weight *= 1.048;
      else if(SR==6) weight *= 0.944;
      else if(SR==7) weight *= 1.050;
      else if(SR==8) weight *= 0.910;
      else if(SR==9) weight *= 0.924;

      if(SR>=0){
	histos["CRtt1l_yield"]->Fill(SR,weight);
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
  
  string filename = "rootfiles/TT1lyield2p3fbinv.root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  cout << "all tt " << count1 << " tt1l " << count2 << endl;
  cout << "all 1l " << count3 << " 2l " << count4 << endl;

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
