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
#include "Math/VectorUtil.h"

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_PU.cc"

//MT2 variants
//#include "StopAnalysis/StopBabyMaker/stop_variables/Davismt2.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"

using namespace std;
using namespace tas;

//inline float getMT(LorentzVector lep,LorentzVector met){
//  // From cmssw reco::deltaPhi()
//  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(ROOT::Math::VectorUtil::deltaPhi(lep,met) ) ) );
//}

float getMT(LorentzVector p4, LorentzVector met){
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

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH2F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();

  const int pssize = 6;
  string prestring[pssize] = {"PreselMT120MET150","PreselMT120","Preselection","MET300","chi210","MT2W200"};

  histonames.push_back("DeltaPhiWl");               hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MT");                       hbins.push_back(24); hlow.push_back(  0.); hup.push_back(600);
  histonames.push_back("MET");                      hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("chi2");                     hbins.push_back(25); hlow.push_back(  0.); hup.push_back(25.);
  histonames.push_back("MT2W");                     hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2_lb_b");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_b_mless");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_mless");         hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
 histonames.push_back("MTq_max");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(1500.);
  histonames.push_back("MTq_leadj300");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(1500.);
  histonames.push_back("METsqrtHT");                hbins.push_back(20); hlow.push_back(  0.); hup.push_back(50.);
  //RM = MET/ptLeadJet
  histonames.push_back("RM300");                    hbins.push_back(20); hlow.push_back(  0.); hup.push_back(2.);
  histonames.push_back("MT2_l_q");                  hbins.push_back(25); hlow.push_back(  0.); hup.push_back(250.);
  histonames.push_back("MT2_l_qq");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_l_qq_mless");           hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("Topness");                  hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod");               hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);

  histonames.push_back("NJets");                     hbins.push_back(15); hlow.push_back(  4.); hup.push_back(19.);
  histonames.push_back("NBJets");                    hbins.push_back(5); hlow.push_back(  1.); hup.push_back(6.);
  histonames.push_back("LepMiniIso");                hbins.push_back(20); hlow.push_back(  0.); hup.push_back(0.2);
  histonames.push_back("LepPt");                     hbins.push_back(28); hlow.push_back( 30.); hup.push_back(450.);
  histonames.push_back("LepEta");                    hbins.push_back(25); hlow.push_back( -2.5); hup.push_back(2.5);
  histonames.push_back("J1Pt");                      hbins.push_back(28); hlow.push_back( 30.); hup.push_back(590.);
  histonames.push_back("J2Pt");                      hbins.push_back(28); hlow.push_back( 30.); hup.push_back(590.);
  histonames.push_back("J3Pt");                      hbins.push_back(28); hlow.push_back( 30.); hup.push_back(590.);
  histonames.push_back("J4Pt");                      hbins.push_back(28); hlow.push_back( 30.); hup.push_back(590.);
  histonames.push_back("B1Pt");                      hbins.push_back(28); hlow.push_back( 30.); hup.push_back(590.);
  histonames.push_back("JPt");                       hbins.push_back(50); hlow.push_back( 30.); hup.push_back(780.);
  histonames.push_back("BPt");                       hbins.push_back(50); hlow.push_back( 30.); hup.push_back(780.);
  histonames.push_back("JEta");                      hbins.push_back(25); hlow.push_back( -2.5); hup.push_back(2.5);
  histonames.push_back("BEta");                      hbins.push_back(25); hlow.push_back( -2.5); hup.push_back(2.5);

  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(b==0) samplename = skimFilePrefix + "_2l";
    else if(b==1) samplename = skimFilePrefix + "_1l";
    else continue;// samplename = skimFilePrefix + "_H";
    //if(skimFilePrefix!="TTbar"&&b>0) continue;
    //if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    //if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    //if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    for(unsigned int c = 0; c<pssize; ++c){
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string mapname;
	mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH2F(mapname.c_str(), "", hbins[i], hlow[i], hup[i], 50, 0, 50);
	histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
	mapname = prestring[c] +"_"+ histonames[i] + "_vsNPUInt_"+samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH2F(mapname.c_str(), "", hbins[i], hlow[i], hup[i], 50, 0, 50);
	histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
	mapname = prestring[c] +"_"+ histonames[i] + "_vsNPV_"+samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH2F(mapname.c_str(), "", hbins[i], hlow[i], hup[i], 50, 0, 50);
	histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
	//cout << mapname << endl;
      }
    }
  }

  int c1vtx(0), c1l(0), cno2l(0), cno2track(0), cnotau(0), c2j(0), c1b(0), cmet(0);
  int cmt(0), cmdphi(0), cchi(0), cmt2w(0);

  int mystart(0), mylep(0), myveto(0), myjet(0), mybjet(0), mymet(0), mymt(0), mydphi(0), mychi2(0), mymt2w(0);
  int mystart1(0), mylep1(0), myveto1(0), myjet1(0), mybjet1(0), mymet1(0), mymt1(0), mydphi1(0), mychi21(0), mymt2w1(0);
  int mystart2(0), mylep2(0), myveto2(0), myjet2(0), mybjet2(0), mymet2(0), mymt2(0), mydphi2(0), mychi22(0), mymt2w2(0);

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

      int ng = 0;

      string samplename = skimFilePrefix;
      //if(skimFilePrefix=="TTbar"){
      if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==2) samplename = skimFilePrefix+"_2l";
      else if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==1) samplename = skimFilePrefix+"_1l";
      else continue;//samplename = skimFilePrefix+"_H";
      

      // Analysis Code
      float weight = cms3.scale1fb()*10.;
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_CSV();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep2lv = cms3.lep2_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());
      
      //bool trackveto = cms3.PassTrackVeto();
      //bool tauveto = cms3.PassTauVeto();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1; //bool lele = false; bool lmuo = false; int lpdg = -1; float lpt = -1;
      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NSLeps; l1 = 1; }
	//if(lep1_pt()>30&&fabs(lep1_eta())<2.4&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NGLeps; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&lep1_MiniIso()<0.1) {++NSLeps; l1 = 1; }
	//if(lep1_pt()>40&&fabs(lep1_eta())<2.5&&lep1_is_phys14_medium_noIso()&&lep1_MiniIso()<0.1) {++NGLeps; }
      }
      NGLeps = nvetoleps();


      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      if(l1==1) leplv = lep1lv;
      else if(l1==2) leplv = lep2lv;

      //     if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
      //NGLeps = NLeps;
      vector<int> jind;
      vector<int> bind;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jsumlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > bjetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > njetlv;
      vector<float> btag;
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	jind.push_back(nj);
	jetlv.push_back(ak4pfjets_p4()[nj]);
	btag.push_back(ak4pfjets_CSV()[nj]);
	++NGJets;
	if(ak4pfjets_CSV()[nj]>0.814) {++NGBJets; bind.push_back(nj); bjetlv.push_back(ak4pfjets_p4()[nj]);}
	else njetlv.push_back(ak4pfjets_p4()[nj]);
      }

      ng =0;
      for(unsigned int n = 0; n< gennus_id().size(); ++n){
	if(abs(gennus_id()[n])!=12&&abs(gennus_id()[n])!=14&&abs(gennus_id()[n])!=16) continue;
	if(abs(gennus_motherid()[n])!=24) continue;
	++ng;
      }
      
      if(nvtxs()>=0&&NSLeps>=1&&NGJets>=2&&pfmet()>30){
	++mystart; if(ng==1) ++mystart1; if(ng==2) ++mystart2;
	if(NSLeps==1){ ++mylep; if(ng==1) ++mylep1; if(ng==2) ++mylep2;
	  if(NGLeps==1){ ++myveto; if(ng==1) ++myveto1; if(ng==2) ++myveto2;
	    if(NGJets>=4) {++myjet; if(ng==1) ++myjet1; if(ng==2) ++myjet2;
	      if(NGBJets>=1){ ++mybjet; if(ng==1) ++mybjet1; if(ng==2) ++mybjet2;
		if(pfmet()>200){ ++mymet; if(ng==1) ++mymet1; if(ng==2) ++mymet2;
		  if(mt_met_lep()>150){ ++mymt; if(ng==1) ++mymt1; if(ng==2) ++mymt2;
		    if(mindphi_met_j1_j2()>0.8) { ++mydphi; if(ng==1) ++mydphi1; if(ng==2) ++mydphi2;
		      if(hadronic_top_chi2()<10) {++mychi2; if(ng==1) ++mychi21; if(ng==2) ++mychi22;
			if(MT2W()>200) {++mymt2w; if(ng==1) ++mymt2w1; if(ng==2) ++mymt2w2;
			}}}}}}}}}}

      if(nvtxs()<0)        continue; ++c1vtx;
      if(NGLeps!=1)        continue; ++c1l;
      if(NSLeps!=1)        continue; ++cno2l;
      //if(!PassTrackVeto()) continue; ++cno2track;
      //if(!PassTauVeto())   continue; ++cnotau;
      if(NGJets<4)         continue; ++c2j;
      if(NGBJets<1)        continue; ++c1b;
      if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
      //if(hadronic_top_chi2()>10) continue; ++cchi;

      int NPUV   = pu_nvtxs();
      int NPUInt = pu_ntrue();
      int NPV    = nvtxs();
      
      //MET
      if(mt_met_lep()>120) {
	histos["PreselMT120MET150_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	histos["PreselMT120MET150_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	histos["PreselMT120MET150_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	histos["PreselMT120_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	histos["PreselMT120_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	histos["PreselMT120_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	if(mt_met_lep()>150) {
	  histos["Preselection_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	  histos["Preselection_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	  histos["Preselection_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	  histos["MET300_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	  histos["MET300_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	  histos["MET300_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	  if(hadronic_top_chi2()<10){
	    histos["chi210_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	    histos["chi210_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	    histos["chi210_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	    if(MT2W()>200){
	      histos["MT2W200_MET_vsNPUV_"+samplename]->Fill(pfmet(),NPUV,weight);
	      histos["MT2W200_MET_vsNPUInt_"+samplename]->Fill(pfmet(),NPUInt,weight);
	      histos["MT2W200_MET_vsNPV_"+samplename]->Fill(pfmet(),NPV,weight);
	    }}}}

      if(pfmet()<150)       continue;

      histos["PreselMT120MET150_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
      histos["PreselMT120MET150_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
      histos["PreselMT120MET150_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
      histos["PreselMT120MET150_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
      histos["PreselMT120MET150_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
      histos["PreselMT120MET150_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
      histos["PreselMT120_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
      histos["PreselMT120_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
      histos["PreselMT120_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
      histos["PreselMT120_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
      histos["PreselMT120_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
      histos["PreselMT120_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
      if(pfmet()>200){
	histos["Preselection_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
	histos["Preselection_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
	histos["Preselection_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
	histos["Preselection_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
	histos["Preselection_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
	histos["Preselection_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
	if(pfmet()>300){
	  histos["MET300_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
	  histos["MET300_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
	  histos["MET300_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
	  histos["MET300_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
	  histos["MET300_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
	  histos["MET300_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
	  if(hadronic_top_chi2()<10){
	    histos["chi210_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
	    histos["chi210_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
	    histos["chi210_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
	    histos["chi210_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
	    histos["chi210_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
	    histos["chi210_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
	    if(MT2W()>200){
	      histos["MT2W200_MT_vsNPUV_"+samplename]->Fill(mt_met_lep(),NPUV,weight);
	      histos["MT2W200_MT_vsNPUInt_"+samplename]->Fill(mt_met_lep(),NPUInt,weight);
	      histos["MT2W200_MT_vsNPV_"+samplename]->Fill(mt_met_lep(),NPV,weight);
	      histos["MT2W200_DeltaPhiWl_vsNPUV_"+samplename]->Fill(dphi_Wlep(),NPUV,weight);
	      histos["MT2W200_DeltaPhiWl_vsNPUInt_"+samplename]->Fill(dphi_Wlep(),NPUInt,weight);
	      histos["MT2W200_DeltaPhiWl_vsNPV_"+samplename]->Fill(dphi_Wlep(),NPV,weight);
	    }}}}




      if(mt_met_lep()<120)  continue;

      map<string, float> val;
      for(unsigned int i = 3; i<histonames.size()-4; ++i) val[histonames[i] ] = 9999;
      val["chi2"] = hadronic_top_chi2();
      val["MT2W"] = MT2W();
      val["MT2_lb_b"] = MT2_lb_b_mass();
      val["MT2_lb_bqq"] = MT2_lb_bqq_mass();
      val["MT2_lb_b_mless"] = MT2_lb_b();
      val["MT2_lb_bqq_mless"] = MT2_lb_bqq();
      if(jetlv[0].Pt()>300) val["MTq_leadj300"] = getMT(jetlv[0],metlv);
      val["MTq_max"] = -9999.;
      for(unsigned int n = 0; n<jetlv.size();++n){
	float tmp = getMT(jetlv[n],metlv);
  	if(tmp>val["MTq_max"]) val["MTq_max"] = tmp;
      }
      if(jetlv[0].Pt()>300) val["RM300"] = pfmet()/jetlv[0].Pt();
      if(ak4_HT()>0) val["METsqrtHT"] = MET_over_sqrtHT();
      val["Topness"] = topness();
      val["TopnessMod"] = topnessMod();
      val["NJets"] = NGJets;
      val["NBJets"] = NGBJets;
      val["LepMiniIso"] = lep1_MiniIso();
      val["LepPt"] = lep1_p4().Pt();
      val["LepEta"] = lep1_p4().Eta();
      if( jetlv.size()>0) val["J1Pt"] =  jetlv[0].Pt();
      if( jetlv.size()>1) val["J2Pt"] =  jetlv[1].Pt();
      if( jetlv.size()>2) val["J3Pt"] =  jetlv[2].Pt();
      if( jetlv.size()>3) val["J4Pt"] =  jetlv[3].Pt();
      if(bjetlv.size()>0) val["B1Pt"] = bjetlv[0].Pt();

      map<string, vector<float> > valv;
     for(unsigned int i = histonames.size()-4; i<histonames.size(); ++i) valv[histonames[i] ].clear();
      for(unsigned int j = 0; j<jetlv.size();++j){
	valv["JPt"].push_back(jetlv[j].Pt());
	valv["JEta"].push_back(jetlv[j].Eta());
      }
      for(unsigned int j = 0; j<bjetlv.size();++j){
	valv["BPt"].push_back(bjetlv[j].Pt());
	valv["BEta"].push_back(bjetlv[j].Eta());
      }

      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["PreselMT120MET150_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["PreselMT120MET150_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["PreselMT120MET150_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["PreselMT120MET150_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["PreselMT120MET150_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["PreselMT120MET150_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
      }
      
      if(pfmet()<200)       continue;

      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["PreselMT120_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["PreselMT120_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["PreselMT120_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["PreselMT120_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["PreselMT120_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["PreselMT120_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
      }

      if(mt_met_lep()<150)  continue; ++cmt;
	    
      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["Preselection_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["Preselection_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["Preselection_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["Preselection_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["Preselection_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["Preselection_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
      }
      /*
      histos["Preselection_chi2_vsNPUV_"+samplename]->Fill(hadronic_top_chi2(),NPUV,weight);
      histos["Preselection_chi2_vsNPUInt_"+samplename]->Fill(hadronic_top_chi2(),NPUInt,weight);
      histos["Preselection_chi2_vsNPV_"+samplename]->Fill(hadronic_top_chi2(),NPV,weight);
      histos["Preselection_MT2W_vsNPUV_"+samplename]->Fill(MT2W(),NPUV,weight);
      histos["Preselection_MT2W_vsNPUInt_"+samplename]->Fill(MT2W(),NPUInt,weight);
      histos["Preselection_MT2W_vsNPV_"+samplename]->Fill(MT2W(),NPV,weight);
      histos["Preselection_MT2_lb_b_vsNPUV_"+samplename]->Fill(MT2_lb_b_mass(),NPUV,weight);
      histos["Preselection_MT2_lb_b_vsNPUInt_"+samplename]->Fill(MT2_lb_b_mass(),NPUInt,weight);
      histos["Preselection_MT2_lb_b_vsNPV_"+samplename]->Fill(MT2_lb_b_mass(),NPV,weight);
      histos["Preselection_MT2_lb_bqq_vsNPUV_"+samplename]->Fill(MT2_lb_bqq_mass(),NPUV,weight);
      histos["Preselection_MT2_lb_bqq_vsNPUInt_"+samplename]->Fill(MT2_lb_bqq_mass(),NPUInt,weight);
      histos["Preselection_MT2_lb_bqq_vsNPV_"+samplename]->Fill(MT2_lb_bqq_mass(),NPV,weight);
      */
      if(pfmet()<300)       continue; ++cmet; 

      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["MET300_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["MET300_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["MET300_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["MET300_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["MET300_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["MET300_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
      }
      
      if(hadronic_top_chi2()>10) continue; ++cchi;

      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["chi210_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["chi210_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["chi210_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["chi210_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["chi210_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["chi210_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
      }
      
      if(MT2W()<200)       continue;

      for(unsigned int i = 3; i<histonames.size()-4;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["MT2W200_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill(val[histonames[i] ],NPUV,  weight);
	histos["MT2W200_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill(val[histonames[i] ],NPUInt,weight);
	histos["MT2W200_"+histonames[i] + "_vsNPV_"    + samplename]->Fill(val[histonames[i] ],NPV,   weight);
      }
      for(unsigned int i = histonames.size()-4; i<histonames.size();++i){
	for(unsigned int j = 0; j< valv[histonames[i] ].size();++j){
	  histos["MT2W200_"+histonames[i] + "_vsNPUV_"   + samplename]->Fill((valv[histonames[i] ])[j],NPUV,  weight);
	  histos["MT2W200_"+histonames[i] + "_vsNPUInt_" + samplename]->Fill((valv[histonames[i] ])[j],NPUInt,weight);
	  histos["MT2W200_"+histonames[i] + "_vsNPV_"    + samplename]->Fill((valv[histonames[i] ])[j],NPV,   weight);
	}
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

  for(map<string,TH2F*>::iterator h=histos.begin(); h!=histos.end();++h){
    //h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    //h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
    for(unsigned int y = 1; y<=h->second->GetNbinsY();++y){
      h->second->SetBinContent(h->second->GetNbinsX(), y, h->second->GetBinContent(h->second->GetNbinsX(),y )+ h->second->GetBinContent(h->second->GetNbinsX()+1,y) );
      h->second->SetBinError(h->second->GetNbinsX(), y, sqrt(pow(h->second->GetBinError(h->second->GetNbinsX(),y ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1,y),2) ) );
    }
    for(unsigned int x = 1; x<=h->second->GetNbinsX();++x){
      h->second->SetBinContent(x, h->second->GetNbinsY(), h->second->GetBinContent(x, h->second->GetNbinsY() )+ h->second->GetBinContent(x, h->second->GetNbinsY()+1) );
      h->second->SetBinError(x, h->second->GetNbinsY(), sqrt(pow(h->second->GetBinError(x, h->second->GetNbinsY() ),2)+pow(h->second->GetBinError(x,h->second->GetNbinsY()+1),2) ) );
    }
  }
  string filename = "rootfiles/PUStudies/Histos_"+skimFilePrefix+".root";

  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH2F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
  /*
  cout << "For " << skimFilePrefix << ":" << endl;
  cout << "Events passing NVtx>=1: " << c1vtx << endl;
  cout << "Events with one good lepton: " << c1l << endl;
  cout << "Events with one selection lepton: " << cno2l << endl;
  cout << "Events passing track veto: " << cno2track << endl;
  cout << "Events passing tau veto: " << cnotau << endl;
  cout << "Events with at least 4 jets: " << c2j << endl;
  cout << "Events with at least 1 b-jet: " << c1b << endl;
  cout << "Events with MET>200: " << cmet << endl;
  cout << "Events with MT>150: " << cmt << endl;
  cout << "Events with minDPhi>0.8: " << cmdphi << endl;
  cout << "Events with chi2<10: " << cchi << endl;

  cout << ">=1vtx, >=1selection lep, >=2jets, MET>30: " << mystart << endl;
  cout << "==1 selection lep:" << mylep << " (" << (float)mylep/(float)mystart*100. << " %)" << endl;
  cout << "==1 veto lep: " << myveto << " (" << (float)myveto/(float)mylep*100. << "%)" << endl;
  cout << ">=4 jets: " << myjet << " (" << (float)myjet/(float)myveto*100. << "%)" << endl;
  cout << ">=1 bjet: " << mybjet << " (" << (float)mybjet/(float)myjet*100. << "%)" << endl;
  cout << "MET>300: " << mymet << " (" << (float)mymet/(float)mybjet*100. << "%)" << endl;
  cout << "MT>150: " << mymt << " (" << (float)mymt/(float)mymet*100. << "%)" << endl;
  cout << "MinDPhi>0.8: " << mydphi << " (" << (float)mydphi/(float)mymt*100. << "%)" << endl;
  cout << "chi2<10: " << mychi2 << " (" << (float)mychi2/(float)mydphi*100. << "%)" << endl;
  cout << "MT2W>200: " << mymt2w << " (" << (float)mymt2w/(float)mychi2*100. << "%)" << endl; 

  cout << "1 genlep" << endl;
  cout << ">=1vtx, >=1selection lep, >=2jets, MET>30: " << mystart1 << endl;
  cout << "==1 selection lep:" << mylep1 << " (" << (float)mylep1/(float)mystart1*100. << "%)" << endl;
  cout << "==1 veto lep: " << myveto1 << " (" << (float)myveto1/(float)mylep1*100. << "%)" << endl;
  cout << ">=4 jets: " << myjet1 << " (" << (float)myjet1/(float)myveto1*100. << "%)" << endl;
  cout << ">=1 bjet: " << mybjet1 << " (" << (float)mybjet1/(float)myjet1*100. << "%)" << endl;
  cout << "MET>300: " << mymet1 << " (" << (float)mymet1/(float)mybjet1*100. << "%)" << endl;
  cout << "MT>150: " << mymt1 << " (" << (float)mymt1/(float)mymet1*100. << "%)" << endl;
  cout << "MinDPhi>0.8: " << mydphi1 << " (" << (float)mydphi1/(float)mymt1*100. << "%)" << endl;
  cout << "chi2<10: " << mychi21 << " (" << (float)mychi21/(float)mydphi1*100. << "%)" << endl;
  cout << "MT2W>200: " << mymt2w1 << " (" << (float)mymt2w1/(float)mychi21*100. << "%)" << endl; 

  cout << "2 genlep" << endl;
  cout << ">=1vtx, >=1selection lep, >=2jets, MET>30: " << mystart2 << endl;
  cout << "==1 selection lep:" << mylep2 << " (" << (float)mylep2/(float)mystart2*100. << "%)" << endl;
  cout << "==1 veto lep: " << myveto2 << " (" << (float)myveto2/(float)mylep2*100. << "%)" << endl;
  cout << ">=4 jets: " << myjet2 << " (" << (float)myjet2/(float)myveto2*100. << "%)" << endl;
  cout << ">=1 bjet: " << mybjet2 << " (" << (float)mybjet2/(float)myjet2*100. << "%)" << endl;
  cout << "MET>300: " << mymet2 << " (" << (float)mymet2/(float)mybjet2*100. << "%)" << endl;
  cout << "MT>150: " << mymt2 << " (" << (float)mymt2/(float)mymet2*100. << "%)" << endl;
  cout << "MinDPhi>0.8: " << mydphi2 << " (" << (float)mydphi2/(float)mymt2*100. << "%)" << endl;
  cout << "chi2<10: " << mychi22 << " (" << (float)mychi22/(float)mydphi2*100. << "%)" << endl;
  cout << "MT2W>200: " << mymt2w2 << " (" << (float)mymt2w2/(float)mychi22*100. << "%)" << endl; 
  */
  //cout << endl << "Cutflow" << endl;
  //cout << "Events " << cevtcf << endl << "NVtx>0 " << cvtxcf << endl << "MET>30 " << cmetcf << endl << "NLeps>0 " << cnlepcf << endl << "NJets>1 " << cnjetcf << endl;

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
