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
#include "StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"
#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"

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
  
  histonames.push_back("MET_noMETsqrtHT");         hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("MET_METsqrtHT14");         hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("MET_METsqrtHT10");         hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("METsqrtHT_MET150");        hbins.push_back(25); hlow.push_back(  0.); hup.push_back(50.);
  histonames.push_back("METsqrtHT_noMET");         hbins.push_back(25); hlow.push_back(  0.); hup.push_back(50.);
  histonames.push_back("METsqrtHTlpt_MET150");     hbins.push_back(25); hlow.push_back(  0.); hup.push_back(50.);
  histonames.push_back("METsqrtHTlpt_noMET");      hbins.push_back(25); hlow.push_back(  0.); hup.push_back(50.);

  histonames.push_back("MT2W3j");                   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2W4j");                   hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2W3j4j");                 hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2W3j_noord");               hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2W4j_noord");             hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);
  histonames.push_back("MT2W3j4j_noord");           hbins.push_back(20); hlow.push_back(  0.); hup.push_back(500.);

  histonames.push_back("Topness3j");                   hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("Topness4j");                   hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("Topness3j4j");                 hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("Topness3j_noord");               hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("Topness4j_noord");             hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("Topness3j4j_noord");           hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);

  histonames.push_back("TopnessMod3j");                   hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod4j");                   hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod3j4j");                 hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod3j_noord");               hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod4j_noord");             hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);
  histonames.push_back("TopnessMod3j4j_noord");           hbins.push_back(25); hlow.push_back(-10.); hup.push_back(15.);

  histonames.push_back("MT2lbb3j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbb4j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbb3j4j");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbb3j_noord");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbb4j_noord");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbb3j4j_noord");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);

  histonames.push_back("MT2lbbqq3j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbbqq4j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbbqq3j4j");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbbqq3j_noord");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbbqq4j_noord");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("MT2lbbqq3j4j_noord");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);

  histonames.push_back("mMT2lbb3j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbb4j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbb3j4j");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbb3j_noord");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbb4j_noord");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbb3j4j_noord");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);

  histonames.push_back("mMT2lbbqq3j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbbqq4j");                   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbbqq3j4j");                 hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbbqq3j_noord");               hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbbqq4j_noord");             hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);
  histonames.push_back("mMT2lbbqq3j4j_noord");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750.);

 

  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    //cout << b << " " << samplename << endl;
    for(unsigned int c = 0; c<26; ++c){
      string prestring = "";
      if(c==1||c==3||c==5||c==7||c==9||c==11||c==13||c==15||c==17||c==19||c==21||c==23||c==25) prestring = "Print_";
      for(unsigned int i = 0; i<histonames.size(); ++i){
	int nbins = hbins[i];
	if(c==1||c==3||c==5||c==7||c==9||c==11||c==13||c==15||c==17||c==19||c==21||c==23||c==25) nbins *=20;
	string mapname;
	mapname = prestring + histonames[i] + "_"+samplename;
	if(c==2||c==3) mapname = prestring + "MET300_" + histonames[i] + "_"+samplename;
	if(c==4||c==5) mapname = prestring + "chi210_" + histonames[i] + "_"+samplename;
	if(c==6||c==7) mapname = prestring + "MT2W200_" + histonames[i] + "_"+samplename;
	if(c==8||c==9) mapname = prestring + "MET400_" + histonames[i] + "_"+samplename;
	if(c==10||c==11) mapname = prestring + "MTleadj750_" + histonames[i] + "_"+samplename;
	if(c==12||c==13) mapname = prestring + "MTleadj600_" + histonames[i] + "_"+samplename;
	if(c==14||c==15) mapname = prestring + "RM0p8_" + histonames[i] + "_"+samplename;
	if(c==16||c==17) mapname = prestring + "RM0p7_" + histonames[i] + "_"+samplename;
	if(c==18||c==19) mapname = prestring + "MT2Wle200nochi2_" + histonames[i] + "_"+samplename;
	if(c==20||c==21) mapname = prestring + "MT2W200nochi2_" + histonames[i] + "_"+samplename;
	if(c==22||c==23) mapname = prestring + "TopnessMod7_" + histonames[i] + "_"+samplename;
	if(c==24||c==25) mapname = prestring + "TopnessMod0_" + histonames[i] + "_"+samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", nbins, hlow[i], hup[i]);
	//cout << mapname << endl;
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
          if(mt_met_lep()<150)  continue; ++cmt;

      map<string, float> val;
      for(unsigned int i = 0; i<histonames.size(); ++i) val[histonames[i] ] = 9999;

      val["MET_noMETsqrtHT"] = pfmet();
      val["MET_METsqrtHT14"] = pfmet();
      val["MET_METsqrtHT10"] = pfmet();
      if( pfmet()/sqrt(ak4_HT())<14) val["MET_METsqrtHT14"] = 99999;
      if( pfmet()/sqrt(ak4_HT())<10) val["MET_METsqrtHT10"] = 99999;
      val["METsqrtHT_MET150"] = pfmet()/sqrt(ak4_HT());
      val["METsqrtHTlpt_MET150"] = pfmet()/sqrt(ak4_HT()+leplv.Pt());
      val["METsqrtHT_noMET"] = pfmet()/sqrt(ak4_HT());
      val["METsqrtHTlpt_noMET"] = pfmet()/sqrt(ak4_HT()+leplv.Pt());
      if(pfmet()<150){
	val["METsqrtHT_MET150"] = 99999;
	val["METsqrtHTlpt_MET150"] = 99999;
      }

      for(unsigned int i = 0; i<7;++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos[histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      //if(pfmet()>300){
	for(unsigned int i = 0; i<7;++i){
	  if(fabs(val[histonames[i] ])>9990.) continue;
	  histos["MET300_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  histos["Print_MET300_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	}
	float mymtt = calculateMt(jetlv[0],metlv);
	if(jetlv[0].Pt()>300&&mymtt>750){
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["MTleadj750_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_MTleadj750_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}
	if(jetlv[0].Pt()>300&&mymtt>600){
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["MTleadj600_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_MTleadj600_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}
	float myrm = pfmet()/jetlv[0].Pt();
	if(jetlv[0].Pt()>300&&myrm>0.7){
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["RM0p7_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_RM0p7_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}
	if(jetlv[0].Pt()>300&&myrm>0.8){
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["RM0p8_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_RM0p8_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}
	if(hadronic_top_chi2()<10) {
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["chi210_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_chi210_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	  if(MT2W()>200) {
	    for(unsigned int i = 0; i<7;++i){
	      if(fabs(val[histonames[i] ])>9990.) continue;
	      histos["MT2W200_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	      histos["Print_MT2W200_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    }
	  }
	  //}
      }
	if(MT2W()>200) {
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["MT2W200nochi2_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_MT2W200nochi2_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    if(samplename=="SingleT" && pfmet()>250&&i==0&&pfmet()<=350){
	      cout << "highDM run:ls:evt " << run() << ":" << ls() << ":" << evt() << " weight " << weight << " MT2W " << MT2W() << " MET " << pfmet() << endl;
	    }
	  }
	}
	if(MT2W()<=200){
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["MT2Wle200nochi2_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_MT2Wle200nochi2_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    if(samplename=="SingleT" && pfmet()>250&&i==0&&pfmet()<=350){
	      cout << "lowDM  run:ls:evt " << run() << ":" << ls() << ":" << evt() << " weight " << weight << " MT2W " << MT2W() << " MET " << pfmet() << endl;
	    }
	  }
	}
	if(topnessMod()>7) {
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["TopnessMod7_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_TopnessMod7_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}
	if(topnessMod()>0) {
	  for(unsigned int i = 0; i<7;++i){
	    if(fabs(val[histonames[i] ])>9990.) continue;
	    histos["TopnessMod0_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	    histos["Print_TopnessMod0_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  }
	}

      if(pfmet()<200)       continue;



      vector<int> jetIndexSortedCSV = JetUtil::JetIndexCSVsorted(ak4pfjets_CSV(),ak4pfjets_p4(),ak4pfjets_loose_pfid(),30.,2.4,true);
      vector<LorentzVector> mybjetsdef; vector<LorentzVector> myaddjetsdef;
      vector<LorentzVector> mybjetsdefMod; vector<LorentzVector> myaddjetsdefMod;
      vector<LorentzVector> mybjets4; vector<LorentzVector> myaddjets4;
      vector<LorentzVector> mybjets4Mod; vector<LorentzVector> myaddjets4Mod;
      vector<LorentzVector> mybjetsComb; vector<LorentzVector> myaddjetsComb;
      vector<LorentzVector> mybjetsCombMod; vector<LorentzVector> myaddjetsCombMod;
      vector<LorentzVector> myjets;
      for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){	
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjetsdef.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjetsdef.size()<=1 && (mybjetsdef.size()+myaddjetsdef.size())<3) myaddjetsdef.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) {
	  mybjetsdefMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	  myaddjetsdefMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	}
	else if(mybjetsdefMod.size()<=1 && (myaddjetsdefMod.size())<3) myaddjetsdefMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );

	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjets4.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjets4.size()<=1 && (mybjets4.size()+myaddjets4.size())<4) myaddjets4.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) {
	  mybjets4Mod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	  myaddjets4Mod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	}
	else if(mybjets4Mod.size()<=1 && (myaddjets4Mod.size())<4) myaddjets4Mod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );

	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjetsComb.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjetsComb.size()<=1 && (mybjetsComb.size()+myaddjetsComb.size())<4) myaddjetsComb.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjetsComb.size()<=2 && (mybjetsComb.size()+myaddjetsComb.size())<3) myaddjetsComb.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) {
	  mybjetsCombMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	  myaddjetsCombMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	}
	else if(mybjetsCombMod.size()<=1 && (myaddjetsCombMod.size())<4) myaddjetsCombMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjetsCombMod.size()<=2 && (myaddjetsCombMod.size())<3) myaddjetsCombMod.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
      }
      mybjetsdefMod.clear(); mybjetsdefMod = myaddjetsdefMod; myaddjetsdefMod.clear();
      mybjets4Mod.clear(); mybjets4Mod = myaddjets4Mod; myaddjets4Mod.clear();
      mybjetsCombMod.clear(); mybjetsCombMod = myaddjetsCombMod; myaddjetsCombMod.clear();

      string vn;
      val["MT2W3j"]         = CalcMT2W_(mybjetsdef,    myaddjetsdef,    lep1_p4(),pfmet(), pfmet_phi());
      val["MT2W4j"]         = CalcMT2W_(mybjets4,      myaddjets4,      lep1_p4(),pfmet(), pfmet_phi());
      val["MT2W3j4j"]       = CalcMT2W_(mybjetsComb,   myaddjetsComb,   lep1_p4(),pfmet(), pfmet_phi());
      val["MT2W3j_noord"]   = CalcMT2W_(mybjetsdefMod, myaddjetsdefMod, lep1_p4(),pfmet(), pfmet_phi());
      val["MT2W4j_noord"]   = CalcMT2W_(mybjets4Mod,   myaddjets4Mod,   lep1_p4(),pfmet(), pfmet_phi());
      val["MT2W3j4j_noord"] = CalcMT2W_(mybjetsCombMod,myaddjetsCombMod,lep1_p4(),pfmet(), pfmet_phi());

      val["Topness3j"]         = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef);
      val["Topness4j"]         = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4);
      val["Topness3j4j"]       = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb);
      val["Topness3j_noord"]   = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod);
      val["Topness4j_noord"]   = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod);
      val["Topness3j4j_noord"] = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod);

      val["TopnessMod3j"]         = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef);
      val["TopnessMod4j"]         = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4);
      val["TopnessMod3j4j"]       = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb);
      val["TopnessMod3j_noord"]   = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod);
      val["TopnessMod4j_noord"]   = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod);
      val["TopnessMod3j4j_noord"] = CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod);

      val["MT2lbb3j"]         = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef,    0,true);
      val["MT2lbb4j"]         = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4,      0,true);
      val["MT2lbb3j4j"]       = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb,   0,true);
      val["MT2lbb3j_noord"]   = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod, 0,true);
      val["MT2lbb4j_noord"]   = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod,   0,true);
      val["MT2lbb3j4j_noord"] = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod,0,true);

      val["mMT2lbb3j"]         = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef,    0,false);
      val["mMT2lbb4j"]         = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4,      0,false);
      val["mMT2lbb3j4j"]       = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb,   0,false);
      val["mMT2lbb3j_noord"]   = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod, 0,false);
      val["mMT2lbb4j_noord"]   = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod,   0,false);
      val["mMT2lbb3j4j_noord"] = CalcMT2_lb_b_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod,0,false);

      val["MT2lbbqq3j"]         = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef,    jetlv,0,true);
      val["MT2lbbqq4j"]         = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4,      jetlv,0,true);
      val["MT2lbbqq3j4j"]       = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb,   jetlv,0,true);
      val["MT2lbbqq3j_noord"]   = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod, jetlv,0,true);
      val["MT2lbbqq4j_noord"]   = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod,   jetlv,0,true);
      val["MT2lbbqq3j4j_noord"] = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod,jetlv,0,true);

      val["mMT2lbbqq3j"]         = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdef,    myaddjetsdef,    jetlv,0,false);
      val["mMT2lbbqq4j"]         = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4,      myaddjets4,      jetlv,0,false);
      val["mMT2lbbqq3j4j"]       = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsComb,   myaddjetsComb,   jetlv,0,false);
      val["mMT2lbbqq3j_noord"]   = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsdefMod, myaddjetsdefMod, jetlv,0,false);
      val["mMT2lbbqq4j_noord"]   = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjets4Mod,   myaddjets4Mod,   jetlv,0,false);
      val["mMT2lbbqq3j4j_noord"] = CalcMT2_lb_bqq_(pfmet(),pfmet_phi(),lep1_p4(),mybjetsCombMod,myaddjetsCombMod,jetlv,0,false);


      for(unsigned int i = 7; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos[histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(pfmet()<300) continue;
      for(unsigned int i = 7; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["MET300_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_MET300_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(pfmet()>400){
	for(unsigned int i = 7; i<histonames.size();++i){
	  if(fabs(val[histonames[i] ])>9990.) continue;
	  histos["MET400_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	  histos["Print_MET400_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	}
      }
      if(hadronic_top_chi2()>10) continue; ++cchi;
      for(unsigned int i = 7; i<histonames.size();++i){
	if(fabs(val[histonames[i] ])>9990.) continue;
	histos["chi210_"+ histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
	histos["Print_chi210_" + histonames[i] + "_" + samplename]->Fill(val[histonames[i] ],weight);
      }
      if(MT2W()<200) continue; ++cmt2w;
      for(unsigned int i = 7; i<histonames.size();++i){
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
  string filename = "rootfiles/MassVariableStudies/HistosFurtherChecks_"+skimFilePrefix+".root";
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
