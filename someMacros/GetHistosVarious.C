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

  int bsel = -2;
  //1: 1b, //2: 2b, //-1: 1j, //-2: 2j

  //histonames.push_back("MyVal");          hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("DeltaPhiWl_noMT");          hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MT");                       hbins.push_back(24); hlow.push_back(  0.); hup.push_back(600);
  histonames.push_back("MET");                      hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("chi2");                     hbins.push_back(25); hlow.push_back(  0.); hup.push_back(25.);
  histonames.push_back("MT2W");                     hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("DeltaPhiWl");               hbins.push_back(32); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MT2_b_b");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_b");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bq");                hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_b_mless");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bq_mless");          hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_mless");         hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_Mjjj");          hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb");       hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MTq_max");                  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(1500.);
  histonames.push_back("MTq_leadj300");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(1500.);
  histonames.push_back("MTq_leadj");                hbins.push_back(30); hlow.push_back(  0.); hup.push_back(1500.);
  histonames.push_back("METsqrtHT");                hbins.push_back(20); hlow.push_back(  0.); hup.push_back(50.);
  //RM = MET/ptLeadJet
  histonames.push_back("RM");                       hbins.push_back(20); hlow.push_back(  0.); hup.push_back(2.);
  histonames.push_back("RM300");                    hbins.push_back(20); hlow.push_back(  0.); hup.push_back(2.);
  histonames.push_back("RM500");                    hbins.push_back(20); hlow.push_back(  0.); hup.push_back(2.);
  histonames.push_back("RM700");                    hbins.push_back(20); hlow.push_back(  0.); hup.push_back(2.);
  histonames.push_back("MT2_l_q");                  hbins.push_back(25); hlow.push_back(  0.); hup.push_back(250.);
  histonames.push_back("MT2_l_qq");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2_l_qq_mless");           hbins.push_back(25); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("Topness");                  hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod");               hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);


  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    //cout << b << " " << samplename << endl;
    for(unsigned int c = 0; c<8; ++c){
      string prestring = "";
      if(c==1||c==3||c==5||c==7) prestring = "Print_";
      for(unsigned int i = 0; i<histonames.size(); ++i){
	int nbins = hbins[i];
	if(c==1||c==3||c==5||c==7) nbins *=5;
	string mapname;
	mapname = prestring + histonames[i] + "_"+samplename;
	if(c==2||c==3) mapname = prestring + "MET300_" + histonames[i] + "_"+samplename;
	if(c==4||c==5) mapname = prestring + "chi210_" + histonames[i] + "_"+samplename;
	if(c==6||c==7) mapname = prestring + "MT2W200_" + histonames[i] + "_"+samplename;
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
      if(NGJets<4)         continue; ++c2j;
      if(NGBJets<1)        continue; ++c1b;
      if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
      //if(hadronic_top_chi2()>10) continue; ++cchi;
    
      map<string, float> val;
      for(unsigned int i = 0; i<histonames.size(); ++i) val[histonames[i] ] = 9999;

      val["DeltaPhiWl"] = dphi_Wlep();
      val["MET"] = pfmet();
      val["MT"] = mt_met_lep();

      histos["MET_" + samplename]->Fill(val["MET" ],weight);
      histos["Print_MET_" + samplename]->Fill(val["MET" ],weight);

      if(pfmet()<200)       continue;

      histos["MT_" + samplename]->Fill(mt_met_lep(),weight);
      histos["Print_MT_" + samplename]->Fill(mt_met_lep(),weight);
      histos["DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
      histos["Print_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
      if(pfmet()>300){
	 ++cmet;
	histos["MET300_MT_" + samplename]->Fill(val["MT" ],weight);
	histos["Print_MET300_MT_" + samplename]->Fill(val["MT" ],weight);
	histos["MET300_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	histos["Print_MET300_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	if(hadronic_top_chi2()<10){
	  histos["chi210_MT_" + samplename]->Fill(val["MT" ],weight);
	  histos["Print_chi210_MT_" + samplename]->Fill(val["MT" ],weight);
	  histos["chi210_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	  histos["Print_chi210_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	  if(MT2W()>200){
	    histos["MT2W200_MT_" + samplename]->Fill(val["MT" ],weight);
	    histos["Print_MT2W200_MT_" + samplename]->Fill(val["MT" ],weight);
	    histos["MT2W200_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	    histos["Print_MT2W200_DeltaPhiWl_noMT_" + samplename]->Fill(val["DeltaPhiWl" ],weight);
	  }
	}
      }

      if(mt_met_lep()<150)  continue; ++cmt;


      vector<int> jetIndexSortedCSV = JetUtil::JetIndexCSVsorted(ak4pfjets_CSV(),ak4pfjets_p4(),ak4pfjets_loose_pfid(),30.,2.4,true);
      vector<LorentzVector> mybjets; vector<LorentzVector> myaddjets;
      vector<LorentzVector> myjets;
      for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(bsel ==2 && mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<3) myaddjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(bsel ==1 && mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<2) myaddjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
      }
      if(bsel == -1 || bsel == -2){
	for(unsigned int idx = 0; idx<=njetlv.size();++idx) {
	  if(bsel ==-2 && mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<3) myaddjets.push_back(njetlv[idx]);
	  else if(bsel ==-1 && mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<2) myaddjets.push_back(njetlv[idx]);
	}
      }

      float minDR1 = 99.; int minDRi = -1.; //minDR for closest b in Mlb
      int jb1 = -1; int jb2 = -1; int jb3 = -1;//jet indices for Mjjj(lep1)
      for (unsigned int idx = 0; idx < jetlv.size(); ++idx){
	float myDR = JetUtil::DeltaPhi(jetlv.at(idx).Phi(),lep1_p4().Phi());
	float myDR1 = -1; float myDR2 = -2; float myDR3 = -3;//is actually DPhi now
	if(jb1>=0) myDR1 = JetUtil::DeltaPhi(jetlv.at(jb1).Phi(),lep1_p4().Phi());
	if(jb2>=0) myDR2 = JetUtil::DeltaPhi(jetlv.at(jb2).Phi(),lep1_p4().Phi());
	if(jb3>=0) myDR3 = JetUtil::DeltaPhi(jetlv.at(jb3).Phi(),lep1_p4().Phi());
	if(myDR>myDR1){ jb3 =jb2; jb2 = jb1; jb1 = idx; }
	else if(myDR>myDR2){ jb3 = jb2; jb2 = idx; }
	else if(myDR>myDR3){ jb3 = idx; }
	if(btag.at(idx)<0.814 ) continue;
	myDR = JetUtil::deltaR(jetlv.at(idx),lep1_p4());
	if(myDR<minDR1) {
	  minDRi = idx;
	  minDR1 =myDR;
	}
      }
      vector<LorentzVector> mybjetsMjjjp; vector<LorentzVector> myaddjetsMjjjp;
      if(jb3>=0){
	myaddjetsMjjjp.push_back(jetlv[jb1]);
	myaddjetsMjjjp.push_back(jetlv[jb2]);
	myaddjetsMjjjp.push_back(jetlv[jb3]);
	for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){
	  if(JetUtil::CompareLV(ak4pfjets_p4().at(jetIndexSortedCSV[idx]),jetlv[jb1])) continue;
	  if(JetUtil::CompareLV(ak4pfjets_p4().at(jetIndexSortedCSV[idx]),jetlv[jb2])) continue;
	  if(JetUtil::CompareLV(ak4pfjets_p4().at(jetIndexSortedCSV[idx]),jetlv[jb3])) continue;
	  if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjetsMjjjp.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	  else if(mybjetsMjjjp.size()==0) mybjetsMjjjp.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	}
      }
      vector<LorentzVector> mybjetsMjjj; vector<LorentzVector> myaddjetsMjjj;
      int jc1 = -1; int jc2 = -1; int jc3 = -1;//jet indices for Mjjj(lep1)
      for (unsigned int idx = 0; idx < jetlv.size(); ++idx){
	if(minDRi==idx) continue;
	float myDR = JetUtil::DeltaPhi(jetlv.at(idx).Phi(),lep1_p4().Phi());
	float myDR1 = -1; float myDR2 = -2; float myDR3 = -3;//is actually DPhi now
	if(jc1>=0) myDR1 = JetUtil::DeltaPhi(jetlv.at(jb1).Phi(),lep1_p4().Phi());
	if(jc2>=0) myDR2 = JetUtil::DeltaPhi(jetlv.at(jb2).Phi(),lep1_p4().Phi());
	if(jc3>=0) myDR3 = JetUtil::DeltaPhi(jetlv.at(jb3).Phi(),lep1_p4().Phi());
	if(myDR>myDR1){ jc3 =jc2; jc2 = jc1; jc1 = idx; }
	else if(myDR>myDR2){ jc3 = jc2; jc2 = idx; }
	else if(myDR>myDR3){ jc3 = idx; }
      }
      if(jc3>=0) {
	mybjetsMjjj.push_back(jetlv[minDRi]);
	myaddjetsMjjj.push_back(jetlv[jc1]);
	myaddjetsMjjj.push_back(jetlv[jc2]);
	myaddjetsMjjj.push_back(jetlv[jc2]);
      }

      string vn;
      vn = "MT2W";             val[vn] = CalcMT2W_(mybjets,myaddjets,lep1_p4(),pfmet(), pfmet_phi());
      vn = "Topness";          val[vn] = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets);
      vn = "TopnessMod";       val[vn] = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets);
      vn = "MT2_b_b";          val[vn] = CalcMT2_b_b_(pfmet(),pfmet_phi(),mybjets,myaddjets,0,true);
      vn = "MT2_lb_b_mless";   val[vn] = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,0,false);
      vn = "MT2_lb_b";         val[vn] = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,0,true);
      vn = "MT2_lb_bq_mless";  val[vn] = CalcMT2_lb_bq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,jetlv,0,false);
      vn = "MT2_lb_bq";        val[vn] = CalcMT2_lb_bq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,jetlv,0,true);
      vn = "MT2_lb_bqq_mless"; val[vn] = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,jetlv,0,false);
      vn = "MT2_lb_bqq";       val[vn] = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets,jetlv,0,true);
      LorentzVector pa = lep1_p4()+mybjetsMjjj[0]; LorentzVector pb = myaddjetsMjjj[0]+myaddjetsMjjj[1]+myaddjetsMjjj[2];
      vn = "MT2_lb_bqq_MjjjMlb"; val[vn] = CalcMT2_(pfmet(),pfmet_phi(),pa,pb,true,0);
      vn = "MT2_lb_bqq_MjjjMlb_mless"; val[vn] = CalcMT2_(pfmet(),pfmet_phi(),pa,pb,false,0);
      for(unsigned int i = 0; i<mybjetsMjjjp.size(); ++i){
	pb = myaddjetsMjjjp[0]+myaddjetsMjjjp[1]+myaddjetsMjjjp[2];
	pa = lep1_p4()+mybjetsMjjj[i];
	vn = "MT2_lb_bqq_Mjjj";
	float tMT2 = CalcMT2_(pfmet(),pfmet_phi(),pa,pb,true,0);
	if(tMT2<val[vn]) val[vn] = tMT2;
	vn = "MT2_lb_bqq_Mjjj_mless";
	tMT2 = CalcMT2_(pfmet(),pfmet_phi(),pa,pb,false,0);
	if(tMT2<val[vn]) val[vn] = tMT2;
      }
      for(unsigned int i = 0; i<jetlv.size(); ++i){
	float tMT2 = CalcMT2_(pfmet(),pfmet_phi(),lep1_p4(),jetlv[i],true,0);
	vn = "MT2_l_q";
	if(tMT2<val[vn]) val[vn] = tMT2;
	for(unsigned int j = i+1; j<jetlv.size(); ++j){
	  pb = jetlv[i]+jetlv[j];
	  tMT2 = CalcMT2_(pfmet(),pfmet_phi(),lep1_p4(),jetlv[i],true,0);
	  vn = "MT2_l_qq";
	  if(tMT2<val[vn]) val[vn] = tMT2;
	  tMT2 = CalcMT2_(pfmet(),pfmet_phi(),lep1_p4(),jetlv[i],false,0);
	  vn = "MT2_l_qq_mless";
	  if(tMT2<val[vn]) val[vn] = tMT2;
	}
      }
      val["MTq_leadj"] = getMT(jetlv[0],metlv);
      if(jetlv[0].Pt()>300) val["MTq_leadj300"] = getMT(jetlv[0],metlv);
      val["MTq_max"] = -9999.;
      for(unsigned int n = 0; n<jetlv.size();++n){
	float tmp = getMT(jetlv[n],metlv);
  	if(tmp>val["MTq_max"]) val["MTq_max"] = tmp;
      }
      val["RM"] = pfmet()/jetlv[0].Pt();
      if(jetlv[0].Pt()>300) val["RM300"] = pfmet()/jetlv[0].Pt();
      if(jetlv[0].Pt()>500) val["RM500"] = pfmet()/jetlv[0].Pt();
      if(jetlv[0].Pt()>700) val["RM700"] = pfmet()/jetlv[0].Pt();
      if(ak4_HT()>0) val["METsqrtHT"] = MET_over_sqrtHT();
      val["chi2"] = hadronic_top_chi2();

      val["DeltaPhiWl_noMT"] = 9999;
      val["MT"] = 9999;
      val["MET"] = 9999;
      for(unsigned int i = 0; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos[histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(pfmet()<300) continue;
      for(unsigned int i = 0; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["MET300_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_MET300_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(hadronic_top_chi2()>10) continue; ++cchi;
      for(unsigned int i = 0; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["chi210_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_chi210_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(MT2W()<200) continue; ++cmt2w;
      for(unsigned int i = 0; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["MT2W200_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_MT2W200_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
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
  string filename = "rootfiles/MassVariableStudies/Histos_"+skimFilePrefix+".root";
  if(bsel == 1) filename = "rootfiles/MassVariableStudies/add1b/Histos_"+skimFilePrefix+".root";
  if(bsel ==-1) filename = "rootfiles/MassVariableStudies/add1j/Histos_"+skimFilePrefix+".root";
  if(bsel == 2) filename = "rootfiles/MassVariableStudies/add2b/Histos_"+skimFilePrefix+".root";
  if(bsel ==-2) filename = "rootfiles/MassVariableStudies/add2j/Histos_"+skimFilePrefix+".root";
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
