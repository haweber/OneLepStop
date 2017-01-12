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
#include "Math/VectorUtil.h"

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_M3b.cc"

//MT2 variants

using namespace std;
using namespace tas;

inline double DeltaPhi(double phi1, double phi2){
  // From cmssw reco::deltaPhi()
  double result = phi1 - phi2;
  while( result >   TMath::Pi() ) result -= TMath::TwoPi();
  while( result <= -TMath::Pi() ) result += TMath::TwoPi();
  return TMath::Abs(result);
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1F*> histos; //massive
  vector<string> histonames; histonames.clear();
  
  histonames.push_back("RecoEleMatchedGenEle");
  histonames.push_back("RecoEleMatchedGenLep");
  histonames.push_back("RecoEleMatchedGenPart");
  histonames.push_back("RecoMuoMatchedGenMuo");
  histonames.push_back("RecoMuoMatchedGenLep");
  histonames.push_back("RecoMuoMatchedGenPart");
  histonames.push_back("RecoTauMatchedGenTau");
  histonames.push_back("RecoTauMatchedGenTau1p");
  histonames.push_back("RecoTauMatchedGenTau3p");
  histonames.push_back("RecoTauMatchedGenLep");
  histonames.push_back("RecoTauMatchedGenPart");

  histonames.push_back("GenEleMatchedRecoEle");
  histonames.push_back("GenEleMatchedRecoLep");//incl.tau
  histonames.push_back("GenEleMatchedIsoTrack");
  histonames.push_back("GenEleMatchedRecoLepTrack");
  histonames.push_back("GenMuoMatchedRecoMuo");
  histonames.push_back("GenMuoMatchedRecoLep");//incl.tau
  histonames.push_back("GenMuoMatchedIsoTrack");
  histonames.push_back("GenMuoMatchedRecoLepTrack");
  histonames.push_back("GenTauMatchedRecoTau");
  histonames.push_back("GenTauMatchedRecoLep");//incl.tau
  histonames.push_back("GenTauMatchedIsoTrack");
  histonames.push_back("GenTauMatchedRecoLepTrack");
  histonames.push_back("GenTau1pMatchedRecoTau");
  histonames.push_back("GenTau1pMatchedRecoLep");//incl.tau
  histonames.push_back("GenTau1pMatchedIsoTrack");
  histonames.push_back("GenTau1pMatchedRecoLepTrack");
  histonames.push_back("GenTau3pMatchedRecoTau");
  histonames.push_back("GenTau3pMatchedRecoLep");//incl.tau
  histonames.push_back("GenTau3pMatchedIsoTrack");
  histonames.push_back("GenTau3pMatchedRecoLepTrack");
  
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname;
      mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 2, 0, 2);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }
  }

  int c1vtx(0), c1l(0), cno2l(0), cno2track(0), cnotau(0), c2j(0), c1b(0), cmet(0);
  int cmt(0), cmdphi(0), cchi(0);

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
      int NLeps = cms3.ngoodleps();
      string ds = cms3.dataset();
      float MET = cms3.pfmet();
      float METPhi = cms3.pfmet_phi();
      float METx = MET*TMath::Cos(METPhi);
      float METy = MET*TMath::Sin(METPhi);
      int nvtxs = cms3.nvtxs();

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_CSV();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep2lv = cms3.lep2_p4();

      
      bool trackveto = cms3.PassTrackVeto();
      bool tauveto = cms3.PassTauVeto();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1;
      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&fabs(cms3.lep1_d0())<0.02&&fabs(cms3.lep1_dz())<0.1&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&cms3.lep1_is_phys14_medium_noIso()&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      }
      if(lep2_is_mu()){
	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&fabs(cms3.lep2_d0())<0.02&&fabs(cms3.lep2_dz())<0.1&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; if(l1!=1) l1 = 2; else l1=-2; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&cms3.lep2_is_phys14_medium_noIso()&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
      }
      NGLeps = ngoodleps();


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
      }
      if(nvtxs<0) continue; ++c1vtx;
      /*if(NGLeps!=1) continue; ++c1l;
      if(NSLeps!=1) continue; ++cno2l;
      if(!trackveto) continue; ++cno2track;
      if(!tauveto) continue; ++cnotau;
      if(NGJets<4) continue; ++c2j;
      if(NGBJets<1) continue; ++c1b;
      //if(MET<100) continue; ++cmet;
      if(MET<200) continue; ++cmet;
      */
      //if(MT<120) continue; ++cmt;

      //if(minDPhi<0.8) continue; ++cmdphi;
      //if(chi2>5) continue; ++cchi;

      if(NGLeps<1) continue;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > muolv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > elelv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > taulv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > leptonlv;

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > genelelv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > genmuolv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > gentaulv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > gentau1plv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > gentau3plv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > genlepplv;

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > trackslv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > tracksleplv;

      if(lep1_is_mu()&& lep1_p4().Pt()>5){
	muolv.push_back(lep1_p4());
	leptonlv.push_back(lep1_p4());
	tracksleplv.push_back(lep1_p4());
      } if(lep2_is_mu()&& lep2_p4().Pt()>5){
	muolv.push_back(lep2_p4());
	leptonlv.push_back(lep2_p4());
	tracksleplv.push_back(lep2_p4());
      }  if(lep1_is_el()&& lep1_p4().Pt()>5){
	elelv.push_back(lep1_p4());
	leptonlv.push_back(lep1_p4());
	tracksleplv.push_back(lep1_p4());
      }  if(lep2_is_el()&& lep2_p4().Pt()>5){
	elelv.push_back(lep2_p4());
	leptonlv.push_back(lep2_p4());
	tracksleplv.push_back(lep2_p4());
      } for(unsigned int n = 0; n<tau_p4().size(); ++n){
	if(tau_p4()[n].Pt()<5) continue;
	taulv.push_back(tau_p4()[n]);
	leptonlv.push_back(tau_p4()[n]);
	tracksleplv.push_back(tau_p4()[n]);
      } for(unsigned int n = 0; n<isoTracks_p4().size(); ++n){
	if(isoTracks_p4()[n].Pt()<5) continue;
	tracksleplv.push_back(isoTracks_p4()[n]);
	trackslv.push_back(isoTracks_p4()[n]);
      } for(unsigned int n = 0; n<genels_p4().size(); ++n){
	if(genels_p4()[n].Pt()<5) continue;
	genelelv.push_back(genels_p4()[n]);
	genlepplv.push_back(genels_p4()[n]);
      } for(unsigned int n = 0; n<genmus_p4().size(); ++n){
	if(genmus_p4()[n].Pt()<5) continue;
	genmuolv.push_back(genmus_p4()[n]);
	genlepplv.push_back(genmus_p4()[n]);
      } for(unsigned int n = 0; n<genleptau_els_p4().size(); ++n){
	if(genleptau_els_p4()[n].Pt()<5) continue;
	genelelv.push_back(genleptau_els_p4()[n]);
	genlepplv.push_back(genleptau_els_p4()[n]);
      } for(unsigned int n = 0; n<genleptau_mus_p4().size(); ++n){
	if(genleptau_mus_p4()[n].Pt()<5) continue;
	genmuolv.push_back(genleptau_mus_p4()[n]);
	genlepplv.push_back(genleptau_mus_p4()[n]);
      } for(unsigned int n = 0; n<gentaus_p4().size(); ++n){
	if(gentaus_p4()[n].Pt()<5) continue;
	gentaulv.push_back(gentaus_p4()[n]);
	genlepplv.push_back(gentaus_p4()[n]);
	if(gentaus_gentaudecay()[n]==3) gentau1plv.push_back(gentaus_p4()[n]);
	if(gentaus_gentaudecay()[n]==4) gentau3plv.push_back(gentaus_p4()[n]);
      }
      float myDR = 0.1;
      for(unsigned int n = 0; n<muolv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<genmuolv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(muolv[n],genmuolv[m])<myDR){ match = true; break; }
	}
	histos["RecoMuoMatchedGenMuo_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<genlepplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(muolv[n],genlepplv[m])<myDR){ match = true; break; }
	}
	histos["RecoMuoMatchedGenLep_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<elelv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<genelelv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(elelv[n],genelelv[m])<myDR){ match = true; break; }
	}
	histos["RecoEleMatchedGenEle_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<genlepplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(elelv[n],genlepplv[m])<myDR){ match = true; break; }
	}
	histos["RecoEleMatchedGenLep_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<taulv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<gentaulv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(taulv[n],gentaulv[m])<myDR){ match = true; break; }
	}
	histos["RecoTauMatchedGenTau_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<gentau3plv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(taulv[n],gentau3plv[m])<myDR){ match = true; break; }
	}
	histos["RecoTauMatchedGenTau3p_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<gentau1plv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(taulv[n],gentau1plv[m])<myDR){ match = true; break; }
	}
	histos["RecoTauMatchedGenTau1p_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<genlepplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(taulv[n],genlepplv[m])<myDR){ match = true; break; }
	}
	histos["RecoTauMatchedGenLep_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<genelelv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<elelv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genelelv[n],elelv[m])<myDR){ match = true; break; }
	}
	histos["GenEleMatchedRecoEle_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<leptonlv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genelelv[n],leptonlv[m])<myDR){ match = true; break; }
	}
	histos["GenEleMatchedRecoLep_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<trackslv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genelelv[n],trackslv[m])<myDR){ match = true; break; }
	}
	histos["GenEleMatchedIsoTrack_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<tracksleplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genelelv[n],tracksleplv[m])<myDR){ match = true; break; }
	}
	histos["GenEleMatchedRecoLepTrack_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<genmuolv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<muolv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genmuolv[n],muolv[m])<myDR){ match = true; break; }
	}
	histos["GenMuoMatchedRecoMuo_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<leptonlv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genmuolv[n],leptonlv[m])<myDR){ match = true; break; }
	}
	histos["GenMuoMatchedRecoLep_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<trackslv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genmuolv[n],trackslv[m])<myDR){ match = true; break; }
	}
	histos["GenMuoMatchedIsoTrack_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<tracksleplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(genmuolv[n],tracksleplv[m])<myDR){ match = true; break; }
	}
	histos["GenMuoMatchedRecoLepTrack_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<gentaulv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<taulv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentaulv[n],taulv[m])<myDR){ match = true; break; }
	}
	histos["GenTauMatchedRecoTau_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<leptonlv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentaulv[n],leptonlv[m])<myDR){ match = true; break; }
	}
	histos["GenTauMatchedRecoLep_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<trackslv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentaulv[n],trackslv[m])<myDR){ match = true; break; }
	}
	histos["GenTauMatchedIsoTrack_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<tracksleplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentaulv[n],tracksleplv[m])<myDR){ match = true; break; }
	}
	histos["GenTauMatchedRecoLepTrack_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<gentau1plv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<taulv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau1plv[n],taulv[m])<myDR){ match = true; break; }
	}
	histos["GenTau1pMatchedRecoTau_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<leptonlv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau1plv[n],leptonlv[m])<myDR){ match = true; break; }
	}
	histos["GenTau1pMatchedRecoLep_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<trackslv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau1plv[n],trackslv[m])<myDR){ match = true; break; }
	}
	histos["GenTau1pMatchedIsoTrack_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<tracksleplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau1plv[n],tracksleplv[m])<myDR){ match = true; break; }
	}
	histos["GenTau1pMatchedRecoLepTrack_"+samplename]->Fill((int)match,weight);
      }
      for(unsigned int n = 0; n<gentau3plv.size();++n){
	bool match;
	match = false;
	for(unsigned int m = 0; m<taulv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau3plv[n],taulv[m])<myDR){ match = true; break; }
	}
	histos["GenTau3pMatchedRecoTau_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<leptonlv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau3plv[n],leptonlv[m])<myDR){ match = true; break; }
	}
	histos["GenTau3pMatchedRecoLep_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<trackslv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau3plv[n],trackslv[m])<myDR){ match = true; break; }
	}
	histos["GenTau3pMatchedIsoTrack_"+samplename]->Fill((int)match,weight);
	match = false;
	for(unsigned int m = 0; m<tracksleplv.size();++m){
	  if(ROOT::Math::VectorUtil::DeltaR(gentau3plv[n],tracksleplv[m])<myDR){ match = true; break; }
	}
	histos["GenTau3pMatchedRecoLepTrack_"+samplename]->Fill((int)match,weight);
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

  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) {
    cout << h->first << ": " << fixed << setprecision(2) << (h->second->GetBinContent(2)/(h->second->GetBinContent(1)+h->second->GetBinContent(2) )*100) << "\%" << endl;
  }

  string filename = "rootfiles/TestGenMatch/Histos_"+skimFilePrefix+".root";
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
  cout << "Events with MET>100: " << cmet << endl;
  cout << "Events with MT>120: " << cmt << endl;
  cout << "Events with minDPhi>0.8: " << cmdphi << endl;
  cout << "Events with chi2<5: " << cchi << endl;
  
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
