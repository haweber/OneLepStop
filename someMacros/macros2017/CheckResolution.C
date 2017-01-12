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
#include "TRandom3.h"
//#include "TDatime.h"

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_Oct16.cc"

//MT2 variants

//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/Davismt2.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
//#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"
#include "/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/topness.h"

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

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  //TDatime *randomizer = new TDatime();
  TRandom3 *rndm = new TRandom3(1508);
  TRandom3 *rndm2 = new TRandom3(1986);
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

  histonames.push_back("MET_23j_lMlb");
  histonames.push_back("MET_23j_hMlb");
  histonames.push_back("MET_4j_ltmod_lMlb");
  histonames.push_back("MET_4j_ltmod_hMlb");
  histonames.push_back("MET_4j_mtmod_lMlb");
  histonames.push_back("MET_4j_mtmod_hMlb");
  histonames.push_back("MET_4j_htmod_lMlb");
  histonames.push_back("MET_4j_htmod_hMlb");
  histonames.push_back("MET_5j");

  for(unsigned int b = 0; b<4; ++b){
    string prefix;
    if(b==0) prefix = "res0";
    if(b==1) prefix = "res10";
    if(b==2) prefix = "res20";
    if(b==3) prefix = "floatres";
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname;
      mapname = histonames[i] + "_" + prefix;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 10, 250, 750);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);    
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

      // Analysis Code
      float weight = cms3.scale1fb()*36.6;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      if(!is1lepFromTop()) continue;

      
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_CSV();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep2lv = cms3.lep2_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      leplv = lep1lv;

      //     if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
      //NGLeps = NLeps;
      vector<int> jind;
      vector<int> bind;
      vector<int> bindT;
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
	//++NGJets;
	if(ak4pfjets_CSV()[nj]>0.8484) {/*++NGBJets;*/ bind.push_back(nj); bjetlv.push_back(ak4pfjets_p4()[nj]);}
	if(ak4pfjets_CSV()[nj]>0.9535) { bindT.push_back(nj); }
	else njetlv.push_back(ak4pfjets_p4()[nj]);
      }

      if(nvtxs()<0)        continue;
      if(ngoodleps()!=1)        continue;
      if(nvetoleps()!=1)        continue;
      if(ngoodjets()<2)         continue;
      if(ngoodbtags()<1)        continue;
      if(!PassTrackVeto())     continue;
      if(!PassTauVeto())          continue;
      //if(pfmet()<100) continue;//met increases by max 20%
      //if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
    

      float METx = pfmet()*TMath::Cos(pfmet_phi());
      float METy = pfmet()*TMath::Sin(pfmet_phi());
      float gMETx = genmet()*TMath::Cos(genmet_phi());
      float gMETy = genmet()*TMath::Sin(genmet_phi());

      float floatresX, floatresY;
      if(pfmet()<250){
	floatresX = rndm->Gaus(1.10,0.015);
	floatresY = rndm2->Gaus(1.10,0.015);
      } else if(pfmet()<350){
	floatresX = rndm2->Gaus(1.05,0.0075);
	floatresY = rndm->Gaus(1.05,0.0075);
      } else if(pfmet()<450){
	floatresX = rndm->Gaus(0.90,0.025);
	floatresY = rndm2->Gaus(0.90,0.025);
      } else if(pfmet()<550){
	floatresX = rndm->Gaus(0.85,0.0375);
	floatresY = rndm2->Gaus(0.85,0.0375);
      } else if(pfmet()<650){
	floatresX = rndm->Gaus(0.75,0.055);
	floatresY = rndm2->Gaus(0.75,0.055);
      } else {
	floatresX = rndm2->Gaus(0.55,0.05);
	floatresY = rndm->Gaus(0.55,0.05);
      }

      float METresX = METx - gMETx;
      float METresY = METy - gMETy;
      float METx_res10 = gMETx + rndm->Gaus(1.10,0.10)*METresX;//try this instead of just 1.10
      float METy_res10 = gMETy + rndm2->Gaus(1.10,0.10)*METresY;
      float METx_res20 = gMETx + rndm->Gaus(1.20,0.20)*METresX;
      float METy_res20 = gMETy + rndm2->Gaus(1.20,0.20)*METresY;
      float METx_floatres = gMETx + floatresX*METresX;
      float METy_floatres = gMETy + floatresX*METresY;  
      LorentzVector METlv;
      LorentzVector METlvres10;
      LorentzVector METlvres15;
      LorentzVector METlvres20;
      LorentzVector METlvfloatres;
      METlv.SetPxPyPzE(     METx ,METy ,0,sqrt(METx *METx  + METy *METy ));
      METlvres10.SetPxPyPzE(METx_res10,METy_res10,0,sqrt(METx_res10*METx_res10 + METy_res10*METy_res10));
      METlvres20.SetPxPyPzE(METx_res20,METy_res20,0,sqrt(METx_res20*METx_res20 + METy_res20*METy_res20));
      METlvfloatres.SetPxPyPzE(METx_floatres,METy_floatres,0,sqrt(METx_floatres*METx_floatres + METy_floatres*METy_floatres));
      if(METlv.Pt()<250 && METlvres10.Pt()<250 && METlvres20.Pt()<250 && METlvfloatres.Pt()<250) continue;
      float MT = calculateMt(leplv,METlv);
      if(TMath::Abs(MT-mt_met_lep())>1) cout << "MT " << MT << " mt_met_lep " << mt_met_lep() << endl;
      float MTres10 = calculateMt(leplv,METlvres10);
      float MTres15 = calculateMt(leplv,METlvres15);
      float MTres20 = calculateMt(leplv,METlvres20);
      float MTfloatres = calculateMt(leplv,METlvfloatres);
      if(MT<150 && MTres10<150 && MTres20<150 && MTfloatres<150) continue;

      float minDPhi = TMath::Min(DPhi_met_lep(jetlv[0],METlv),DPhi_met_lep(jetlv[1],METlv) );
      if(TMath::Abs(minDPhi-mindphi_met_j1_j2())>0.1){
	cout << "minDPhi " << minDPhi << " mindphi_met_j1_j2 " << mindphi_met_j1_j2() << endl;
      }
      float minDPhires10 = TMath::Min(DPhi_met_lep(jetlv[0],METlvres10),DPhi_met_lep(jetlv[1],METlvres10) );
      float minDPhires20 = TMath::Min(DPhi_met_lep(jetlv[0],METlvres20),DPhi_met_lep(jetlv[1],METlvres20) );
      float minDPhifloatres = TMath::Min(DPhi_met_lep(jetlv[0],METlvfloatres),DPhi_met_lep(jetlv[1],METlvfloatres) );
      if(minDPhi<0.5 && minDPhires10<0.5 && minDPhires20<0.5 && minDPhifloatres<0.5) continue;

      float DPhiMETlep = DPhi_met_lep(lep1_p4(),METlv);
      float DPhiMETlepres10 = DPhi_met_lep(lep1_p4(),METlvres10);
      float DPhiMETlepres20 = DPhi_met_lep(lep1_p4(),METlvres20);
      float DPhiMETlepfloatres = DPhi_met_lep(lep1_p4(),METlvfloatres);
      
      vector<int> jetIndexSortedCSV = JetUtil::JetIndexCSVsorted(ak4pfjets_CSV(),ak4pfjets_p4(),ak4pfjets_loose_pfid(),30.,2.4,true);
      vector<LorentzVector> mybjets; vector<LorentzVector> myaddjets;
      vector<LorentzVector> myjets;
      for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){
	if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.8484) mybjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	else if(mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<3) myaddjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
      }
       //
      // ADD TOPMOD_ HERE
      //
      float topmod_ =  CalcTopness_(1,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets);
      if(TMath::Abs(topmod_-topnessMod() )>1) cout << "topmod " << topmod_ << " topnessMod() " << topnessMod() << endl;
      float topmodres10 =  CalcTopness_(1,METlvres10.Pt(),METlvres10.Phi(),lep1_p4(),mybjets,myaddjets);
      float topmodres20 =  CalcTopness_(1,METlvres20.Pt(),METlvres20.Phi(),lep1_p4(),mybjets,myaddjets);
      float topmodfloatres =  CalcTopness_(1,METlvfloatres.Pt(),METlvfloatres.Phi(),lep1_p4(),mybjets,myaddjets);
      
      if(nEventsCount%100000==0){
	cout << "genMET " << genmet() << " MET " << pfmet() << " res00 " << METlv.Pt() << " res10 " << METlvres10.Pt() << " res20 " << METlvres20.Pt() << " floatres " << METlvfloatres.Pt() << endl;
	cout << "MT " << MT << " res10 " << MTres10 << " res20 " << MTres20 << endl;
	cout << "mDPhi " << minDPhi << " res10 " << minDPhires10 << " res20 " << minDPhires20 << endl;
      }
      ++nEventsCount;

      if(ngoodjets()<=3){
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    > 10. && Mlb_closestb()<=175) histos["MET_23j_lMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    > 10. && Mlb_closestb()> 175) histos["MET_23j_hMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10> 10. && Mlb_closestb()<=175) histos["MET_23j_lMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10> 10. && Mlb_closestb()> 175) histos["MET_23j_hMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20> 10. && Mlb_closestb()<=175) histos["MET_23j_lMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20> 10. && Mlb_closestb()> 175) histos["MET_23j_hMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres> 10. && Mlb_closestb()<=175) histos["MET_23j_lMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);	 
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres> 10. && Mlb_closestb()> 175) histos["MET_23j_hMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);	 
      }
      if(ngoodjets()>=4){
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    <= 0. && Mlb_closestb()<=175) histos["MET_23j_ltmod_lMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    <= 0. && Mlb_closestb()> 175) histos["MET_23j_ltmod_hMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10<= 0. && Mlb_closestb()<=175) histos["MET_23j_ltmod_lMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10<= 0. && Mlb_closestb()> 175) histos["MET_23j_ltmod_hMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20<= 0. && Mlb_closestb()<=175) histos["MET_23j_ltmod_lMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20<= 0. && Mlb_closestb()> 175) histos["MET_23j_ltmod_hMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres<= 0. && Mlb_closestb()<=175) histos["MET_23j_ltmod_lMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);	 
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres<= 0. && Mlb_closestb()> 175) histos["MET_23j_ltmod_hMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);

	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    >0.&&topmod_    <=10. && Mlb_closestb()<=175) histos["MET_23j_mtmod_lMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    >0.&&topmod_    <=10. && Mlb_closestb()> 175) histos["MET_23j_mtmod_hMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10>0.&&topmodres10<=10. && Mlb_closestb()<=175) histos["MET_23j_mtmod_lMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10>0.&&topmodres10<=10. && Mlb_closestb()> 175) histos["MET_23j_mtmod_hMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20>0.&&topmodres20<=10. && Mlb_closestb()<=175) histos["MET_23j_mtmod_lMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20>0.&&topmodres20<=10. && Mlb_closestb()> 175) histos["MET_23j_mtmod_hMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres>0.&&topmodfloatres<=10. && Mlb_closestb()<=175) histos["MET_23j_mtmod_lMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);	 
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres>0.&&topmodfloatres<=10. && Mlb_closestb()> 175) histos["MET_23j_mtmod_hMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);
	
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    > 10. && Mlb_closestb()<=175) histos["MET_23j_htmod_lMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MT     >150.&&minDPhi     >0.8&&METlv.Pt()     >250.&&topmod_    > 10. && Mlb_closestb()> 175) histos["MET_23j_htmod_hMlb_res0"]->Fill(METlv.Pt()     ,weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10> 10. && Mlb_closestb()<=175) histos["MET_23j_htmod_lMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres10>150.&&minDPhires10>0.8&&METlvres10.Pt()>250.&&topmodres10> 10. && Mlb_closestb()> 175) histos["MET_23j_htmod_hMlb_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20> 10. && Mlb_closestb()<=175) histos["MET_23j_htmod_lMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.8&&METlvres20.Pt()>250.&&topmodres20> 10. && Mlb_closestb()> 175) histos["MET_23j_htmod_hMlb_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres> 10. && Mlb_closestb()<=175) histos["MET_23j_htmod_lMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);	 
	if(MTfloatres>150.&&minDPhifloatres>0.8&&METlvfloatres.Pt()>250.&&topmodfloatres> 10. && Mlb_closestb()> 175) histos["MET_23j_htmod_hMlb_floatres"]->Fill(METlvfloatres.Pt(),weight);
      }
      if(ngoodjets()>=5&&lep1_p4().Pt()<150.){
	if(MT     >150.&&minDPhi     >0.5&&METlv.Pt()     >250.&&DPhiMETlep     <2.) histos["MET_5j_res0"]->Fill(METlv.Pt()     ,weight);
	if(MTres10>150.&&minDPhires10>0.5&&METlvres10.Pt()>150.&&DPhiMETlepres10<2.) histos["MET_5j_res10"]->Fill(METlvres10.Pt(),weight);
	if(MTres20>150.&&minDPhires20>0.5&&METlvres20.Pt()>150.&&DPhiMETlepres20<2.) histos["MET_5j_res20"]->Fill(METlvres20.Pt(),weight);
	if(MTfloatres>150.&&minDPhifloatres>0.5&&METlvfloatres.Pt()>150.&& DPhiMETlepfloatres<2.) histos["MET_5j_floatres"]->Fill(METlvfloatres.Pt(),weight);
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
  string filename = "rootfiles/PhotonMETResolution/CheckResolutionTT1l.root";

  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;

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
