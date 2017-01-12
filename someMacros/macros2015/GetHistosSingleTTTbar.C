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
#include "CMS3.cc"

//MT2 variants
#include "StopAnalysis/StopBabyMaker/stop_variables/Davismt2.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"

using namespace std;
using namespace tas;

inline float getMT(LorentzVector lep,LorentzVector met){
  // From cmssw reco::deltaPhi()
  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(JetUtil::deltaPhi(lep,met) ) ) );
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

  int bsel = 1;
  //1: 1b, //2: 2b, //-1: 1j, //-2: 2j

 
  histonames.push_back("MW");                       hbins.push_back(32); hlow.push_back(  0.); hup.push_back(160);
  histonames.push_back("PtW");                      hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("PtTop");                    hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMET");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("NgenB");                    hbins.push_back(5); hlow.push_back(  0.); hup.push_back(5);
  histonames.push_back("genBDR");                   hbins.push_back(50); hlow.push_back(  0.); hup.push_back(5);
  histonames.push_back("Bsource");                  hbins.push_back(31); hlow.push_back( -10.); hup.push_back(21);
  histonames.push_back("genMT");                    hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("genDPhiWl");                hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("genBPt");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBPt_top");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBPt_notop");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBEta");                  hbins.push_back(50); hlow.push_back(-5.); hup.push_back(5);
  histonames.push_back("genBAcc");                  hbins.push_back(2); hlow.push_back(  0.); hup.push_back(2);
  histonames.push_back("PtW_top");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("PtW_nottop");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMT_neutrino");           hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("gennuPt");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMETPhi");                hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("gennuPhi");                 hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);

  histonames.push_back("MW_tail");                       hbins.push_back(32); hlow.push_back(  0.); hup.push_back(160);
  histonames.push_back("PtW_tail");                      hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("PtTop_tail");                    hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMET_tail");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("NgenB_tail");                    hbins.push_back(5); hlow.push_back(  0.); hup.push_back(5);
  histonames.push_back("genBDR_tail");                   hbins.push_back(50); hlow.push_back(  0.); hup.push_back(5);
  histonames.push_back("Bsource_tail");                  hbins.push_back(31); hlow.push_back( -10.); hup.push_back(21);
  histonames.push_back("genMT_tail");                    hbins.push_back(25); hlow.push_back( -10.); hup.push_back(500);
  histonames.push_back("genDPhiWl_tail");                hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("genBPt_tail");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBPt_top_tail");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBPt_notop_tail");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("genBEta_tail");                  hbins.push_back(50); hlow.push_back(-5.); hup.push_back(5);
  histonames.push_back("genBAcc_tail");                  hbins.push_back(2); hlow.push_back(  0.); hup.push_back(2);
  histonames.push_back("PtW_top_tail");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("PtW_nottop_tail");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMT_neutrino_tail");           hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500);
  histonames.push_back("gennuPt_tail");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genMETPhi_tail");                hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);
  histonames.push_back("gennuPhi_tail");                 hbins.push_back(64); hlow.push_back(-3.2); hup.push_back(3.2);

  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&skimFilePrefix!="SingleT"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    if(skimFilePrefix=="SingleT"&&b==0) samplename = "SingleT1l";
    if(skimFilePrefix=="SingleT"&&b==1) samplename = "SingleT2l";
    if(skimFilePrefix=="SingleT"&&b==2) samplename = "SingleT";
    //cout << b << " " << samplename << endl;
    for(unsigned int c = 0; c<1; ++c){
      string prestring = "";
      if(c==1||c==3) prestring = "Print_";
      for(unsigned int i = 0; i<histonames.size(); ++i){
	int nbins = hbins[i];
	if(c==1) nbins *=5;
	string mapname;
	mapname = prestring + histonames[i] + "_"+samplename;
	if(c==2||c==3) mapname = prestring + "MET300_" + histonames[i] + "_"+samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", nbins, hlow[i], hup[i]);
	histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);

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
    int mycounter = 0;
    
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
      if(skimFilePrefix=="TTbar"){
	if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==2) samplename = "TTbar2l";
	else if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==1) samplename = "TTbar1l";
	else samplename = "TTbarH";
	//if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==2) samplename = "TTbar2l";
	//else if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==1) samplename = "TTbar1l";
	//else samplename = "TTbarH";
      }

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
      /*if(lep2_is_mu()){
	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NSLeps; l1 = 1; if(l1!=1) l1 = 2; else l1=-2; }
	//if(lep2_pt()>30&&fabs(lep2_eta())<2.4&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NGLeps; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
	//if(lep2_pt()>40&&fabs(lep2_eta())<2.5&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NGLeps; }
      }
      */
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

      //if(nvtxs()>=0 && nvetoleps()==1 && ngoodleps()==1&&ngoodjets()>=4&&ngoodbtags()>=1&&mindphi_met_j1_j2()>0.8&&hadronic_top_chi2()<10&&pfmet()>300&&mt_met_lep()>150&&MT2W()>200){
      //histos["MyVal_" + samplename]->Fill(1.,weight);
      //histos["Print_MyVal_" + samplename]->Fill(1.,weight);
      //}

      ng =0;
      vector<LorentzVector> W;
      vector<int> Wid;
      vector<bool> fromTop;
      vector<int> tid;
      for(unsigned int n = 0; n< gents_id().size(); ++n){
	tid.push_back(gents_id()[n]);
      }
      for(unsigned int n = 0; n< gennus_id().size(); ++n){
	if(abs(gennus_id()[n])!=12&&abs(gennus_id()[n])!=14&&abs(gennus_id()[n])!=16) continue;
	if(abs(gennus_motherid()[n])!=24) continue;
	W.push_back(gennus_motherp4()[n]);
	Wid.push_back(gennus_motherid()[n]);
	bool Wtop = false;
	for(unsigned int m = 0; m< gents_id().size(); ++m){
	  //t -> b W+, tbar -> bbar W-, i.e. 6->5 24, -6 -> -5 -24
	  if(gennus_motherid()[n]==24&&gents_id()[m]==6) Wtop = true;
	  if(gennus_motherid()[n]==-24&&gents_id()[m]==-6) Wtop = true;
	}
	fromTop.push_back(Wtop);
	++ng;
      }
      for(unsigned int n = 0; n< gents_id().size(); ++n){
	tid.push_back(gents_id()[n]);
      }
     if(skimFilePrefix=="SingleT"){
	if(ng==2) samplename = "SingleT2l";
	else if(ng==1) samplename = "SingleT1l";
	else samplename = "SingleT";
      }

      if(nvtxs()>=0&&NSLeps>=1&&NGJets>=2&&pfmet()>30){
	++mystart; if(ng==1) ++mystart1; if(ng==2) ++mystart2;
	if(NSLeps==1){ ++mylep; if(ng==1) ++mylep1; if(ng==2) ++mylep2;
	  if(NGLeps==1){ ++myveto; if(ng==1) ++myveto1; if(ng==2) ++myveto2;
	    if(NGJets>=4) {++myjet; if(ng==1) ++myjet1; if(ng==2) ++myjet2;
	      if(NGBJets>=1){ ++mybjet; if(ng==1) ++mybjet1; if(ng==2) ++mybjet2;
		if(pfmet()>300){ ++mymet; if(ng==1) ++mymet1; if(ng==2) ++mymet2;
		  if(mt_met_lep()>150){ ++mymt; if(ng==1) ++mymt1; if(ng==2) ++mymt2;
		    if(mindphi_met_j1_j2()>0.8) { ++mydphi; if(ng==1) ++mydphi1; if(ng==2) ++mydphi2;
		      if(hadronic_top_chi2()<10) {++mychi2; if(ng==1) ++mychi21; if(ng==2) ++mychi22;
			if(MT2W()>200) {++mymt2w; if(ng==1) ++mymt2w1; if(ng==2) ++mymt2w2;
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
      
      if(nvtxs()<0)        continue; ++c1vtx;
      if(NGLeps!=1)        continue; ++c1l;
      if(NSLeps!=1)        continue; ++cno2l;
      //if(!PassTrackVeto()) continue; ++cno2track;
      //if(!PassTauVeto())   continue; ++cnotau;

      float thegenlepDR = 9999.;
      LorentzVector thegenlep;
      LorentzVector thegennu;
      LorentzVector thegentaunu;
      int thegenlepid;
      bool thegenlepfromtau = false;
      for(unsigned int n = 0; n< genmus_p4().size(); ++n) {
	if(genmus_p4()[n].Pt()<1) continue;
	float DR = JetUtil::deltaR(leplv,genmus_p4()[n]);
	if(DR<thegenlepDR){
	  thegenlepDR = DR;
	  thegenlep = genmus_p4()[n];
	  thegenlepid = genmus_id()[n];
	}
      }
      for(unsigned int n = 0; n< genels_p4().size(); ++n) {
	if(genels_p4()[n].Pt()<1) continue;
	float DR = JetUtil::deltaR(leplv,genels_p4()[n]);
	if(DR<thegenlepDR){
	  thegenlepDR = DR;
	  thegenlep = genels_p4()[n];
	  thegenlepid = genels_id()[n];
	}
      }
      for(unsigned int n = 0; n< genleptau_mus_p4().size(); ++n) {
	if(genleptau_mus_p4()[n].Pt()<1) continue;
	float DR = JetUtil::deltaR(leplv,genleptau_mus_p4()[n]);
	if(DR<thegenlepDR){
	  thegenlepDR = DR;
	  thegenlep = genleptau_mus_p4()[n];
	  thegenlepid = genleptau_mus_id()[n];
	  thegenlepfromtau = true;
	}
      }
      for(unsigned int n = 0; n< genleptau_els_p4().size(); ++n) {
	if(genleptau_els_p4()[n].Pt()<1) continue;
	float DR = JetUtil::deltaR(leplv,genleptau_els_p4()[n]);
	if(DR<thegenlepDR){
	  thegenlepDR = DR;
	  thegenlep = genleptau_els_p4()[n];
	  thegenlepid = genleptau_els_id()[n];
	  thegenlepfromtau = true;
	}
      }
      for(unsigned int n = 0; n< gennus_id().size(); ++n){
	if(abs(gennus_id()[n])!=12&&abs(gennus_id()[n])!=14&&abs(gennus_id()[n])!=16) continue;
	if(thegenlepid==11&&gennus_id()[n]==-12) thegennu = gennus_p4()[n];
	if(thegenlepid==-11&&gennus_id()[n]==12) thegennu = gennus_p4()[n];
	if(thegenlepid==13&&gennus_id()[n]==-14) thegennu = gennus_p4()[n];
	if(thegenlepid==-13&&gennus_id()[n]==14) thegennu = gennus_p4()[n];
	if(thegenlepfromtau){
	if(thegenlepid==11&&gennus_id()[n]==16) thegentaunu = gennus_p4()[n];
	if(thegenlepid==-11&&gennus_id()[n]==-16) thegentaunu = gennus_p4()[n];
	if(thegenlepid==13&&gennus_id()[n]==16) thegentaunu = gennus_p4()[n];
	if(thegenlepid==-13&&gennus_id()[n]==-16) thegentaunu = gennus_p4()[n];
	}
      }
      if(thegenlepfromtau) thegennu = thegennu+thegentaunu;

      float myMT = sqrt(2.*genmet()*thegenlep.Et()*(1.-TMath::Cos(JetUtil::DeltaPhi(genmet_phi(),thegenlep.Phi() ) ) ) );
      float myMTn = sqrt(2.*thegennu.Et()*thegenlep.Et()*(1.-TMath::Cos(JetUtil::DeltaPhi(thegennu.Phi(),thegenlep.Phi() ) ) ) );

      for(unsigned int n = 0; n<W.size(); ++n){
	histos["MW_"+samplename]->Fill(W[n].M(),weight);
	histos["PtW_"+samplename]->Fill(W[n].Pt(),weight);
	if(fromTop[n]) histos["PtW_top_"+samplename]->Fill(W[n].Pt(),weight);
	else histos["PtW_nottop_"+samplename]->Fill(W[n].Pt(),weight);
      }
      for(unsigned int n = 0; n<gents_p4().size(); ++n){
	histos["PtTop_"+samplename]->Fill(gents_p4()[n].Pt(),weight);
      }
      for(unsigned int n = 0; n<genbs_p4().size(); ++n){
	int mymother = genbs_motherid()[n];
	if(mymother==-2212) mymother = -19;
	if(mymother==2212) mymother = 19;
	histos["Bsource_"+samplename]->Fill(mymother,weight);
	histos["genBPt_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	if(TMath::Abs(mymother)==6) histos["genBPt_top_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	else  histos["genBPt_notop_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	histos["genBEta_"+samplename]->Fill(genbs_p4()[n].Eta(),weight);
	if(genbs_p4()[n].Pt()>30&&fabs(genbs_p4()[n].Eta())<2.4) histos["genBAcc_"+samplename]->Fill(1.,weight);
	else histos["genBAcc_"+samplename]->Fill(0.,weight);
      }
      if(genbs_p4().size()>=2) histos["genBDR_"+samplename]->Fill(JetUtil::deltaR(genbs_p4()[0], genbs_p4()[1]), weight);
      histos["NgenB_"+samplename]->Fill(genbs_p4().size(),weight);
      histos["genMET_"+samplename]->Fill(genmet(),weight);
      histos["gennuPt_"+samplename]->Fill(thegennu.Pt(),weight);
      histos["genMETPhi_"+samplename]->Fill(genmet_phi(),weight);
      histos["gennuPhi_"+samplename]->Fill(thegennu.Phi(),weight);
      histos["genMT_"+samplename]->Fill(myMT,weight);
      histos["genMT_neutrino_"+samplename]->Fill(myMTn,weight);
      histos["genDPhiWl_"+samplename]->Fill(JetUtil::DeltaPhi(pfmet_phi(),thegenlep.Phi() ),weight);

      if(NGJets<4)         continue; ++c2j;
      if(NGBJets<1)        continue; ++c1b;
      //if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
      //if(hadronic_top_chi2()>10) continue; ++cchi;
  
      //if(mt_met_lep()<150)  continue; ++cmt;

      if(pfmet()<300) continue;

            for(unsigned int n = 0; n<W.size(); ++n){
	histos["MW_tail_"+samplename]->Fill(W[n].M(),weight);
	histos["PtW_tail_"+samplename]->Fill(W[n].Pt(),weight);
	if(fromTop[n]) histos["PtW_top_tail_"+samplename]->Fill(W[n].Pt(),weight);
	else histos["PtW_nottop_tail_"+samplename]->Fill(W[n].Pt(),weight);
      }
      for(unsigned int n = 0; n<gents_p4().size(); ++n){
	histos["PtTop_tail_"+samplename]->Fill(gents_p4()[n].Pt(),weight);
      }
      for(unsigned int n = 0; n<genbs_p4().size(); ++n){
	int mymother = genbs_motherid()[n];
	if(mymother==-2212) mymother = -19;
	if(mymother==2212) mymother = 19;
	histos["Bsource_tail_"+samplename]->Fill(mymother,weight);
	histos["genBPt_tail_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	if(TMath::Abs(mymother)==6) histos["genBPt_top_tail_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	else  histos["genBPt_notop_tail_"+samplename]->Fill(genbs_p4()[n].Pt(),weight);
	histos["genBEta_tail_"+samplename]->Fill(genbs_p4()[n].Eta(),weight);
	if(genbs_p4()[n].Pt()>30&&fabs(genbs_p4()[n].Eta())<2.4) histos["genBAcc_tail_"+samplename]->Fill(1.,weight);
	else histos["genBAcc_tail_"+samplename]->Fill(0.,weight);
      }
      if(genbs_p4().size()>=2) histos["genBDR_tail_"+samplename]->Fill(JetUtil::deltaR(genbs_p4()[0], genbs_p4()[1]), weight);
      histos["NgenB_tail_"+samplename]->Fill(genbs_p4().size(),weight);
      histos["genMET_tail_"+samplename]->Fill(genmet(),weight);
      histos["gennuPt_tail_"+samplename]->Fill(thegennu.Pt(),weight);
      histos["genMETPhi_tail_"+samplename]->Fill(genmet_phi(),weight);
      histos["gennuPhi_tail_"+samplename]->Fill(thegennu.Phi(),weight);
      histos["genMT_tail_"+samplename]->Fill(myMT,weight);
      histos["genDPhiWl_tail_"+samplename]->Fill(JetUtil::DeltaPhi(pfmet_phi(),thegenlep.Phi() ),weight);
      histos["genMT_neutrino_tail_"+samplename]->Fill(myMTn,weight);

      if(hadronic_top_chi2()>10) continue; ++cchi;

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
  string filename = "rootfiles/MassVariableStudies/HistosSingleTTTbar_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;

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
