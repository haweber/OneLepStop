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
#include "TH1D.h"
#include "TH3D.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "Math/LorentzVector.h"
//#include "TDatime.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_reminiAOD.cc"

//MT2 variants

//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/Davismt2.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/topness.h"
#include "/home/users/haweber/StopAnalysisMoriond2017/testTopness/JetUtil.cc"
#include "/home/users/haweber/StopAnalysisMoriond2017/testTopness/topnessNext.cc"

using namespace std;
using namespace tas;

inline float getMT(LorentzVector lep,LorentzVector met){
  // From cmssw reco::deltaPhi()
  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(JetUtil::deltaPhi(lep,met) ) ) );
}

float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

float DPhi_W_lep(LorentzVector metlv, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(metlv.x(),metlv.y(),0);
  const TVector3 w = lep+met;
  double dphi = fabs(w.DeltaPhi(lep));
  return dphi;
}
float DPhi_met_lep(LorentzVector metlv, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(metlv.x(),metlv.y(),0);
  double dphi = fabs(met.DeltaPhi(lep));
  return dphi;
}
float dRbetweenVectors(LorentzVector vec1,LorentzVector vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}


int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  map<string, TH1F*> histos;
  map<string, bool> checktopness;
  vector<string> histonames; histonames.clear();
  vector<string> histonames2; histonames2.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();

  histonames.push_back("topness_2j1b");
  histonames.push_back("tMod_2j1b");
  histonames.push_back("topness_4j1b");
  histonames.push_back("tMod_4j1b");
  
  histonames.push_back("WLTM_topness_2j1b");//tmod terms only
  histonames.push_back("WLTM_topness_4j1b");//tmod terms only
  histonames.push_back("allterms_tmod_2j1b");//all t terms 
  histonames.push_back("allterms_tmod_4j1b");//all t terms 

  histonames.push_back("test1_tmod_2j1b"); 
  histonames.push_back("test2_tmod_2j1b"); 
  histonames.push_back("test3_tmod_2j1b"); 
  histonames.push_back("testA_tmod_2j1b"); 
  histonames.push_back("testB_tmod_2j1b"); 
  histonames.push_back("testC_tmod_2j1b"); 
  histonames.push_back("testD_tmod_2j1b"); 
  histonames.push_back("testE_tmod_2j1b"); 
  histonames.push_back("testF_tmod_2j1b"); 

  //W(lnu) term only
  histonames.push_back("WL_topness_2j1b");
  histonames.push_back("WL_tMod_2j1b");
  histonames.push_back("WL_topness_4j1b");
  histonames.push_back("WL_tMod_4j1b");

  //t(blnu) term only
  histonames.push_back("TL_topness_2j1b");
  histonames.push_back("TL_tMod_2j1b");//not part of fit
  histonames.push_back("TL_topness_4j1b");
  histonames.push_back("TL_tMod_4j1b");//not part of fit
  //t(blost) term only
  histonames.push_back("TM_topness_2j1b");
  histonames.push_back("TM_tMod_2j1b");
  histonames.push_back("TM_topness_4j1b");
  histonames.push_back("TM_tMod_4j1b");
  
  //CM term only
  histonames.push_back("CM_topness_2j1b");
  histonames.push_back("CM_tMod_2j1b");//not part of fit
  histonames.push_back("CM_topness_4j1b");
  histonames.push_back("CM_tMod_4j1b");//not part of fit
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 160, -15,25);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      checktopness[mapname] = true;
      //cout << mapname << endl;
    }
  }
  histonames2.push_back("Nup4_diffFit_tVstmod_2j1b");
  histonames2.push_back("Nup4_diffFit_tVstmod_4j1b");
  histonames2.push_back("NupT_diffFit_tVstmod_2j1b");
  histonames2.push_back("NupT_diffFit_tVstmod_4j1b");
  histonames2.push_back("Nup4_diffFit_tVstruth_2j1b");
  histonames2.push_back("Nup4_diffFit_tVstruth_4j1b");
  histonames2.push_back("NupT_diffFit_tVstruth_2j1b");
  histonames2.push_back("NupT_diffFit_tVstruth_4j1b");
  histonames2.push_back("Nup4_diffFit_tmodVstruth_2j1b");
  histonames2.push_back("Nup4_diffFit_tmodVstruth_4j1b");
  histonames2.push_back("NupT_diffFit_tmodVstruth_2j1b");
  histonames2.push_back("NupT_diffFit_tmodVstruth_4j1b");
  for(unsigned int i = 0; i<histonames2.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames2[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 150, 0.,1500);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      checktopness[mapname] = true;
      //cout << mapname << endl;
    }
  }

  // Loop over events to Analyze
  unsigned int nEventsCount = 0;
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
  TH3D* counterhistSig;
  TH1D* counterhist;
  
  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    if(skimFilePrefix.find(string("Signal")) != string::npos){
      counterhistSig = (TH3D*)file->Get("h_counterSMS");
      counterhistSig->SetDirectory(0);
    } else { 
      counterhist = (TH1D*)file->Get("h_counter");
      counterhist->SetDirectory(0);
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
      float weight = cms3.scale1fb()*35.9;
      if(!is_data() && skimFilePrefix.find(string("Signal")) == string::npos) {
	int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(14));
	if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(37));
	double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
	weight = cms3.scale1fb()*35.9;
	weight = 0.5071*0.574*35900./nevts;//TTH
	//weight = 0.7826*35900./nevts;//TTZ
	//cout << "weight " << weight << " BSF " << BSFweight << " lepSF " << lepSFweight << endl;
	if(BSFweight>=0) weight *= BSFweight;
	if(lepSFweight>=0) weight *= lepSFweight;
      } else if(!is_data()){
	string tempsignal = skimFilePrefix;
	int mStop, mLSP;
	std::replace( tempsignal.begin(), tempsignal.end(), '_', ' ');
	sscanf(tempsignal.c_str(), "Signal %*s %i %i", &mStop, &mLSP);
	int Nevts = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,36));
	if(mStop!=(int)mass_stop()) continue;
	if(mLSP==0){
	  if((int)mass_stop()<0||(int)mass_stop()>1) continue;
	}
	else if(mLSP!=(int)mass_lsp()) continue;	
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
	if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	double lepSFweight = weight_lepSF()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
	double lepFSweight = weight_lepSF_fastSim()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
	weight = xsec()*36600/nevts;
	if(BSFweight>=0) weight *= BSFweight;
	if(lepSFweight>=0) weight *= lepSFweight;
	if(lepFSweight>=0) weight *= lepFSweight;
	if(!filt_fastsimjets() )     continue;
      }
      if(is_data()) continue;

      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      //if(!is1lepFromTop()) continue;

      
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_CSV();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      leplv = lep1lv;


      if(nvtxs()<0)        continue;
      if(ngoodleps()!=1)        continue;
      if(nvetoleps()!=1)        continue;
      if(ngoodjets()<2)         continue;
      if(ngoodbtags()<1)        continue;
      if(!PassTrackVeto())     continue;
      if(!PassTauVeto())          continue;
      if(pfmet()<150) continue;
      if(mt_met_lep()<150) continue;
      //if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;

      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(is1lepFromTop()) samplename = "TT1l";
	else samplename = "TT2l";
      }
      
      int NJ = ngoodjets();
      int NB = ngoodbtags();

      float METx = pfmet()*TMath::Cos(pfmet_phi());
      float METy = pfmet()*TMath::Sin(pfmet_phi());
      float gMETx = genmet()*TMath::Cos(genmet_phi());
      float gMETy = genmet()*TMath::Sin(genmet_phi());
      LorentzVector METlv;
      METlv.SetPxPyPzE(     METx ,METy ,0,sqrt(METx *METx  + METy *METy ));
 
      //cout << __LINE__ << endl;
      vector<int> jetIndexSortedCSV = JetUtil::JetIndexCSVsorted(ak4pfjets_CSV(),ak4pfjets_p4(),ak4pfjets_loose_pfid(),30.,2.4,true);
      //cout << __LINE__ << endl;
      vector<LorentzVector> mybjets; vector<LorentzVector> myaddjets; vector<LorentzVector> myaddjets2; vector<LorentzVector> myaddjets4;
      vector<LorentzVector> myaddjetsvB; vector<LorentzVector> myaddjetsvB2; vector<LorentzVector> myaddjetsvB4;
      for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.8484) mybjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=1 && (mybjets.size()+myaddjets.size()    )<3) myaddjets.push_back( ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	//if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=1 && (mybjets.size()+myaddjets2.size()   )<2) myaddjets2.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	//if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=1 && (mybjets.size()+myaddjets4.size()   )<4) myaddjets4.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	//if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=2 && (mybjets.size()+myaddjetsvB.size()  )<3) myaddjetsvB.push_back( ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	//if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=2 && (mybjets.size()+myaddjetsvB2.size() )<2) myaddjetsvB2.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	//if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])<=0.8484&&mybjets.size()<=2 && (mybjets.size()+myaddjetsvB4.size() )<4) myaddjetsvB4.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
      }
      //if(myaddjets.size()!=myaddjetsvB.size()){
      //cout << "NB " <<  mybjets.size() << " NaddjA " << myaddjets.size() << " NaddjB " << myaddjetsvB.size() << endl;
      //}

      
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu; mygennu.SetPxPyPzE(0.,0.,0.,0.);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu2; mygennu2.SetPxPyPzE(0.,0.,0.,0.);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu3; mygennu3.SetPxPyPzE(0.,0.,0.,0.);
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mygennu4; mygennu4.SetPxPyPzE(0.,0.,0.,0.);
      int nuflav(0), nuflav2(0), nuflav3(0), nuflav4(0);
      bool nutau(0), nutau2(0), nutau3(0), nutau4(0);
      int Widx(-1), Widx2(-1), Widx3(-1), Widx4(-1);
      int ngm = 0;
      //at most 4 neutrinos, tt--> 2l, with both tau leptonic
      for(unsigned int n = 0; n< gennus_id().size(); ++n){
	if(gennus_status()[n]!=1) continue;
	if(abs(gennus_id()[n])!=12&&abs(gennus_id()[n])!=14&&abs(gennus_id()[n])!=16) continue;
	if(abs(gennus_motherid()[n])!=24&&(abs(gennus_motherid()[n])!=15&&abs(gennus_gmotherid()[n])!=24)) continue;
	if(ngm==0){       mygennu  = gennus_p4()[n]; nuflav  = gennus_id()[n]; nutau  = ((abs(gennus_motherid()[n])==24) ? false : true);
	  Widx  = ((abs(gennus_motherid()[n])==24) ? gennus_motheridx()[n] : gennus_gmotheridx()[n]);  }
	else if(ngm==1) { mygennu2 = gennus_p4()[n]; nuflav2 = gennus_id()[n]; nutau2 = ((abs(gennus_motherid()[n])==24) ? false : true);
	  Widx2 = ((abs(gennus_motherid()[n])==24) ? gennus_motheridx()[n] : gennus_gmotheridx()[n]); }
	else if(ngm==2) { mygennu3 = gennus_p4()[n]; nuflav3 = gennus_id()[n]; nutau3 = ((abs(gennus_motherid()[n])==24) ? false : true);
	  Widx3 = ((abs(gennus_motherid()[n])==24) ? gennus_motheridx()[n] : gennus_gmotheridx()[n]); }
	else if(ngm==3) { mygennu4 = gennus_p4()[n]; nuflav4 = gennus_id()[n]; nutau4 = ((abs(gennus_motherid()[n])==24) ? false : true);
	  Widx4 = ((abs(gennus_motherid()[n])==24) ? gennus_motheridx()[n] : gennus_gmotheridx()[n]); }
	++ngm;
      }
      int recoWidx(-1), minDR(999);
      for(unsigned int n = 0; n< genleps_id().size(); ++n){
	if(genleps_status()[n]!=1) continue;
	if(abs(genleps_id()[n])!=11&&abs(genleps_id()[n])!=13) continue;
	if(abs(genleps_motherid()[n])!=24&&(abs(genleps_motherid()[n])!=15&&abs(genleps_gmotherid()[n])!=24)) continue;
	if(genleps_id()[n]!=lep1_pdgid()) continue;
	if(dRbetweenVectors(genleps_p4()[n],lep1_p4())>0.1) continue;
	if(minDR>dRbetweenVectors(genleps_p4()[n],lep1_p4())){
	  minDR = dRbetweenVectors(genleps_p4()[n],lep1_p4());
	  recoWidx  = ((abs(genleps_motherid()[n])==24) ? genleps_motheridx()[n] : genleps_gmotheridx()[n]);
	}
      }
      LorentzVector nup4; nup4.SetPxPyPzE(0.,0.,0.,0.);
      bool nufound = false;
      if(recoWidx>=0){
	if(recoWidx==Widx ) { nup4 = nup4 + mygennu;  nufound = true; }
	if(recoWidx==Widx2) { nup4 = nup4 + mygennu2; nufound = true; }
	if(recoWidx==Widx3) { nup4 = nup4 + mygennu3; nufound = true; }
	if(recoWidx==Widx4) { nup4 = nup4 + mygennu4; nufound = true; }
      }
      //
      // ADD TOPMOD_ HERE
      //
      float tmod, topness;
      double WLt(-999), TLt(-999), TMt(-999), CMt(-999);
      double WLtmod(-999), TLtmod(-999), TMtmod(-999), CMtmod(-999);
      double pWzt(0), pnxt(0), pnyt(0), pnzt(0);
      double pWztmod(0), pnxtmod(0), pnytmod(0), pnztmod(0);
      //cout << __LINE__ << endl;
      tmod    =  CalcTopness_(CMtmod,TMtmod,WLtmod,TLtmod,pnxtmod,pnytmod,pnztmod,pWztmod, 1,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,5.,15.,1000.,false,false);
      //cout << "main " << tmod << " " << CMtmod << " " << TMtmod << " " << WLtmod << " " << TLtmod << endl;
      //cout << __LINE__ << endl;
      topness =  CalcTopness_(CMt,TMt,WLt,TLt,pnxt,pnyt,pnzt,pWzt, 0,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,5.,15.,1000.,false,false);
      //cout << __LINE__ << endl;
      if(NJ>=2&&NB>=1) histos["topness_2j1b_" + samplename]->Fill(topness,weight);
      if(NJ>=2&&NB>=1) histos[   "tMod_2j1b_" + samplename]->Fill(tmod   ,weight);
      if(NJ>=4&&NB>=1) histos["topness_4j1b_" + samplename]->Fill(topness,weight);
      if(NJ>=4&&NB>=1) histos[   "tMod_4j1b_" + samplename]->Fill(tmod   ,weight);

      if(NJ>=2&&NB>=1) histos["WLTM_topness_2j1b_" + samplename]->Fill(log(WLt+TMt),weight);
      if(NJ>=4&&NB>=1) histos["WLTM_topness_4j1b_" + samplename]->Fill(log(WLt+TMt),weight);
      if(NJ>=2&&NB>=1) histos["allterms_tmod_2j1b_" + samplename]->Fill(log(WLtmod+TMtmod+TLtmod+CMtmod),weight);
      if(NJ>=4&&NB>=1) histos["allterms_tmod_4j1b_" + samplename]->Fill(log(WLtmod+TMtmod+TLtmod+CMtmod),weight);
      if(NJ>=2&&NB>=1) histos["test1_tmod_2j1b_" + samplename]->Fill(log(WLtmod+TMtmod),weight);
      if(NJ>=2&&NB>=1) histos["test2_tmod_2j1b_" + samplename]->Fill(log(CMtmod+TLtmod),weight);
      if(NJ>=2&&NB>=1) histos["test3_tmod_2j1b_" + samplename]->Fill(tmod,weight);
      if(NJ>=2&&NB>=1) histos["testA_tmod_2j1b_" + samplename]->Fill(log(WLtmod+CMtmod),weight);
      if(NJ>=2&&NB>=1) histos["testB_tmod_2j1b_" + samplename]->Fill(log(TLtmod+CMtmod),weight);
      if(NJ>=2&&NB>=1) histos["testC_tmod_2j1b_" + samplename]->Fill(log(TMtmod+CMtmod),weight);
      if(NJ>=2&&NB>=1) histos["testD_tmod_2j1b_" + samplename]->Fill(log(WLtmod+TMtmod),weight);
      if(NJ>=2&&NB>=1) histos["testE_tmod_2j1b_" + samplename]->Fill(log(WLtmod+TLtmod),weight);
      if(NJ>=2&&NB>=1) histos["testF_tmod_2j1b_" + samplename]->Fill(log(TLtmod+TMtmod),weight);

      if(NJ>=2&&NB>=1) histos["WL_topness_2j1b_" + samplename]->Fill(log(WLt),   weight);
      if(NJ>=2&&NB>=1) histos[   "WL_tMod_2j1b_" + samplename]->Fill(log(WLtmod),weight);
      if(NJ>=4&&NB>=1) histos["WL_topness_4j1b_" + samplename]->Fill(log(WLt),   weight);
      if(NJ>=4&&NB>=1) histos[   "WL_tMod_4j1b_" + samplename]->Fill(log(WLtmod),weight);

      if(NJ>=2&&NB>=1) histos["TL_topness_2j1b_" + samplename]->Fill(log(TLt),   weight);
      if(NJ>=2&&NB>=1) histos[   "TL_tMod_2j1b_" + samplename]->Fill(log(TLtmod),weight);
      if(NJ>=4&&NB>=1) histos["TL_topness_4j1b_" + samplename]->Fill(log(TLt),   weight);
      if(NJ>=4&&NB>=1) histos[   "TL_tMod_4j1b_" + samplename]->Fill(log(TLtmod),weight);

      if(NJ>=2&&NB>=1) histos["TM_topness_2j1b_" + samplename]->Fill(log(TMt),   weight);
      if(NJ>=2&&NB>=1) histos[   "TM_tMod_2j1b_" + samplename]->Fill(log(TMtmod),weight);
      if(NJ>=4&&NB>=1) histos["TM_topness_4j1b_" + samplename]->Fill(log(TMt),   weight);
      if(NJ>=4&&NB>=1) histos[   "TM_tMod_4j1b_" + samplename]->Fill(log(TMtmod),weight);

      if(NJ>=2&&NB>=1) histos["CM_topness_2j1b_" + samplename]->Fill(log(CMt),   weight);
      if(NJ>=2&&NB>=1) histos[   "CM_tMod_2j1b_" + samplename]->Fill(log(CMtmod),weight);
      if(NJ>=4&&NB>=1) histos["CM_topness_4j1b_" + samplename]->Fill(log(CMt),   weight);
      if(NJ>=4&&NB>=1) histos[   "CM_tMod_4j1b_" + samplename]->Fill(log(CMtmod),weight);
      if(nufound){
	LorentzVector nufitt, nufittmod;
	nufitt.SetPxPyPzE(pnxt,pnyt,pnzt,sqrt(pow(pnxt,2)+pow(pnyt,2)+pow(pnzt,2)));
	nufittmod.SetPxPyPzE(pnxtmod,pnytmod,pnztmod,sqrt(pow(pnxtmod,2)+pow(pnytmod,2)+pow(pnztmod,2)));
	LorentzVector nufittdiff    = nufitt - nup4;
	LorentzVector nufittmoddiff = nufittmod - nup4;
	LorentzVector nufitdiff     = nufitt - nufittmod;
	if(NJ>=2&&NB>=1) histos["Nup4_diffFit_tVstmod_2j1b_" + samplename]->Fill(nufitdiff.P(),weight);
	if(NJ>=4&&NB>=1) histos["Nup4_diffFit_tVstmod_4j1b_" + samplename]->Fill(nufitdiff.P(),weight);
	if(NJ>=2&&NB>=1) histos["NupT_diffFit_tVstmod_2j1b_" + samplename]->Fill(nufitdiff.Pt(),weight);
	if(NJ>=4&&NB>=1) histos["NupT_diffFit_tVstmod_4j1b_" + samplename]->Fill(nufitdiff.Pt(),weight);
	if(NJ>=2&&NB>=1) histos["Nup4_diffFit_tVstruth_2j1b_" + samplename]->Fill(nufittdiff.P(),weight);
	if(NJ>=4&&NB>=1) histos["Nup4_diffFit_tVstruth_4j1b_" + samplename]->Fill(nufittdiff.P(),weight);
	if(NJ>=2&&NB>=1) histos["NupT_diffFit_tVstruth_2j1b_" + samplename]->Fill(nufittdiff.Pt(),weight);
	if(NJ>=4&&NB>=1) histos["NupT_diffFit_tVstruth_4j1b_" + samplename]->Fill(nufittdiff.Pt(),weight);
	if(NJ>=2&&NB>=1) histos["Nup4_diffFit_tmodVstruth_2j1b_" + samplename]->Fill(nufittmoddiff.P(),weight);
	if(NJ>=4&&NB>=1) histos["Nup4_diffFit_tmodVstruth_4j1b_" + samplename]->Fill(nufittmoddiff.P(),weight);
	if(NJ>=2&&NB>=1) histos["NupT_diffFit_tmodVstruth_2j1b_" + samplename]->Fill(nufittmoddiff.Pt(),weight);
	if(NJ>=4&&NB>=1) histos["NupT_diffFit_tmodVstruth_4j1b_" + samplename]->Fill(nufittmoddiff.Pt(),weight);
      }
  
    }
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Histograms
  // samplehisto->Draw();

  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
  }
  string filename = "rootfiles/TestTopnessNext.root";

  TFile *f = new TFile(filename.c_str(),"UPDATE");
  f->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames[i] + "_"+samplename;
      histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
      cout << mapname << " " << histos[mapname]->Integral() << endl;
    }
  }
  for(unsigned int i = 0; i<histonames2.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames2[i] + "_"+samplename;
      histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
      cout << mapname << " " << histos[mapname]->Integral() << endl;
    }
  }
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
