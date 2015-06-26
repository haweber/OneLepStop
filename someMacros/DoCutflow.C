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
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

// CMS3
#include "CMS3.cc"

//MT2 variants
//#include "stop_variables/Davismt2.h"
//#include "stop_variables/topness.h"
//#include "stop_variables/MT2_implementations.h"
#include "stop_variables/JetUtil.h"
//#include "stop_variables/mt2w.h"
//#include "stop_variables/mt2w_bisect.h"

using namespace std;
using namespace tas;

inline float getMT(LorentzVector lep,LorentzVector met){
  // From cmssw reco::deltaPhi()
  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(JetUtil::deltaPhi(lep,met) ) ) );
}

inline float dot(LorentzVector a,LorentzVector b){
  // From cmssw reco::deltaPhi()
  return a.Px()*b.Px()+a.Py()*b.Py()+a.Pz()*b.Pz();
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

 map<string, TH1D*> histos;

  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";

    string histoname = "NEventsPerSR_" + samplename;
    histos[histoname] = new TH1D(histoname.c_str(),"",8,0,8);
    histos[histoname]->Sumw2(); histos[histoname]->SetDirectory(rootdir);
    histos[histoname]->GetYaxis()->SetTitle("Events");
    histos[histoname]->GetXaxis()->SetBinLabel(1,"MET>150,lDM");
    histos[histoname]->GetXaxis()->SetBinLabel(2,"MET>200,lDM");
    histos[histoname]->GetXaxis()->SetBinLabel(3,"MET>250,lDM");
    histos[histoname]->GetXaxis()->SetBinLabel(4,"MET>300,lDM");
    histos[histoname]->GetXaxis()->SetBinLabel(5,"MET>150,hDM");
    histos[histoname]->GetXaxis()->SetBinLabel(6,"MET>200,hDM");
    histos[histoname]->GetXaxis()->SetBinLabel(7,"MET>250,hDM");
    histos[histoname]->GetXaxis()->SetBinLabel(8,"MET>300,hDM");
    histoname = "CutflowLowDM_" + samplename;
    histos[histoname] = new TH1D(histoname.c_str(),"",15,0,15);
    histos[histoname]->Sumw2(); histos[histoname]->SetDirectory(rootdir);
    histos[histoname]->GetYaxis()->SetTitle("Events");
    histos[histoname]->GetXaxis()->SetBinLabel(1,"NVtx");
    histos[histoname]->GetXaxis()->SetBinLabel(2,"GLeps");
    histos[histoname]->GetXaxis()->SetBinLabel(3,"SLeps");
    histos[histoname]->GetXaxis()->SetBinLabel(4,"track");
    histos[histoname]->GetXaxis()->SetBinLabel(5,"tau");
    histos[histoname]->GetXaxis()->SetBinLabel(6,"NJ");
    histos[histoname]->GetXaxis()->SetBinLabel(7,"NB");
    //histos[histoname]->GetXaxis()->SetBinLabel(1,"Preselection");
    histos[histoname]->GetXaxis()->SetBinLabel(8,"$M_{T}>120$");
    histos[histoname]->GetXaxis()->SetBinLabel(9,"$E_{T}^{miss}>100$");
    histos[histoname]->GetXaxis()->SetBinLabel(10,"min#Delta#phi>0.8");
    histos[histoname]->GetXaxis()->SetBinLabel(11,"#chi^{2}<5");
    histos[histoname]->GetXaxis()->SetBinLabel(12,"E_{T}^{miss}>150");
    histos[histoname]->GetXaxis()->SetBinLabel(13,"E_{T}^{miss}>200");
    histos[histoname]->GetXaxis()->SetBinLabel(14,"E_{T}^{miss}>250");
    histos[histoname]->GetXaxis()->SetBinLabel(15,"E_{T}^{miss}>300");
    histoname = "CutflowHighDM_" + samplename;
    histos[histoname] = new TH1D(histoname.c_str(),"",16,0,16);
    histos[histoname]->Sumw2(); histos[histoname]->SetDirectory(rootdir);
    histos[histoname]->GetYaxis()->SetTitle("Events");
    histos[histoname]->GetXaxis()->SetBinLabel(1,"NVtx");
    histos[histoname]->GetXaxis()->SetBinLabel(2,"GLeps");
    histos[histoname]->GetXaxis()->SetBinLabel(3,"SLeps");
    histos[histoname]->GetXaxis()->SetBinLabel(4,"track");
    histos[histoname]->GetXaxis()->SetBinLabel(5,"tau");
    histos[histoname]->GetXaxis()->SetBinLabel(6,"NJ");
    histos[histoname]->GetXaxis()->SetBinLabel(7,"NB");
    //histos[histoname]->GetXaxis()->SetBinLabel(1,"Preselection");
    histos[histoname]->GetXaxis()->SetBinLabel(8,"$M_{T}>120$");
    histos[histoname]->GetXaxis()->SetBinLabel(9,"$E_{T}^{miss}>100$");
    histos[histoname]->GetXaxis()->SetBinLabel(10,"min#Delta#phi>0.8");
    histos[histoname]->GetXaxis()->SetBinLabel(11,"#chi^{2}<5");
    histos[histoname]->GetXaxis()->SetBinLabel(12,"M_{T2}^{W}>200");
    histos[histoname]->GetXaxis()->SetBinLabel(13,"E_{T}^{miss}>150");
    histos[histoname]->GetXaxis()->SetBinLabel(14,"E_{T}^{miss}>200");
    histos[histoname]->GetXaxis()->SetBinLabel(15,"E_{T}^{miss}>250");
    histos[histoname]->GetXaxis()->SetBinLabel(16,"E_{T}^{miss}>300");
  }
  
  int c1vtx(0), c1l(0), cno2l(0), cno2track(0), cnotau(0), c2j(0), c1b(0), cmet(0);
  int cmt(0), cmdphi(0), cchi(0);

  int c1vtxel(0), c1lel(0), cno2lel(0), cno2trackel(0), cnotauel(0), c2jel(0), c1bel(0), cmetel(0);
  int cmtel(0), cmdphiel(0), cchiel(0);
  int c1vtxmu(0), c1lmu(0), cno2lmu(0), cno2trackmu(0), cnotaumu(0), c2jmu(0), c1bmu(0), cmetmu(0);
  int cmtmu(0), cmdphimu(0), cchimu(0);

  int l1c1vtx(0), l1c1l(0), l1cno2l(0), l1cno2track(0), l1cnotau(0), l1c2j(0), l1c1b(0), l1cmet(0);
  int l1cmt(0), l1cmdphi(0), l1cchi(0);
  int l1c1vtxel(0), l1c1lel(0), l1cno2lel(0), l1cno2trackel(0), l1cnotauel(0), l1c2jel(0), l1c1bel(0), l1cmetel(0);
  int l1cmtel(0), l1cmdphiel(0), l1cchiel(0);
  int l1c1vtxmu(0), l1c1lmu(0), l1cno2lmu(0), l1cno2trackmu(0), l1cnotaumu(0), l1c2jmu(0), l1c1bmu(0), l1cmetmu(0);
  int l1cmtmu(0), l1cmdphimu(0), l1cchimu(0);
  int l2c1vtx(0), l2c1l(0), l2cno2l(0), l2cno2track(0), l2cnotau(0), l2c2j(0), l2c1b(0), l2cmet(0);
  int l2cmt(0), l2cmdphi(0), l2cchi(0);
  int l2c1vtxel(0), l2c1lel(0), l2cno2lel(0), l2cno2trackel(0), l2cnotauel(0), l2c2jel(0), l2c1bel(0), l2cmetel(0);
  int l2cmtel(0), l2cmdphiel(0), l2cchiel(0);
  int l2c1vtxmu(0), l2c1lmu(0), l2cno2lmu(0), l2cno2trackmu(0), l2cnotaumu(0), l2c2jmu(0), l2c1bmu(0), l2cmetmu(0);
  int l2cmtmu(0), l2cmdphimu(0), l2cchimu(0);

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

      double weight = scale1fb()*10.;

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
      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1; int myleppdgid = -1;
      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&fabs(cms3.lep1_d0())<0.02&&fabs(cms3.lep1_dz())<0.1&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; myleppdgid = 13;}
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&cms3.lep1_is_phys14_medium_noIso()&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; myleppdgid = 11; }
      }
      if(lep2_is_mu()){
	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&fabs(cms3.lep2_d0())<0.02&&fabs(cms3.lep2_dz())<0.1&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&cms3.lep2_is_phys14_medium_noIso()&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
      }
      NGLeps = ngoodleps();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      if(l1==1) leplv = lep1_p4();
      else if(l1==2) leplv = lep2_p4();

      float METx = pfmet()*TMath::Cos(pfmet_phi());
      float METy = pfmet()*TMath::Sin(pfmet_phi());
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(METx,METy,0.,pfmet());

      //if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
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

      double weighttemp = weight;
      if(nvtxs()>=1){
	histos["CutflowLowDM_" +samplename]->Fill(0.5,weighttemp);
	histos["CutflowHighDM_"+samplename]->Fill(0.5,weighttemp);
	if(NGLeps==1){
	  histos["CutflowLowDM_" +samplename]->Fill(1.5,weighttemp);
	  histos["CutflowHighDM_"+samplename]->Fill(1.5,weighttemp);
	  if(NSLeps==1){
	    histos["CutflowLowDM_" +samplename]->Fill(2.5,weighttemp);
	    histos["CutflowHighDM_"+samplename]->Fill(2.5,weighttemp);
	    if(PassTrackVeto()){
	      histos["CutflowLowDM_" +samplename]->Fill(3.5,weighttemp);
	      histos["CutflowHighDM_"+samplename]->Fill(3.5,weighttemp);
	      if(PassTauVeto()){
		histos["CutflowLowDM_" +samplename]->Fill(4.5,weighttemp);
		histos["CutflowHighDM_"+samplename]->Fill(4.5,weighttemp);
		if(NGJets>=4){
		  histos["CutflowLowDM_" +samplename]->Fill(5.5,weighttemp);
		  histos["CutflowHighDM_"+samplename]->Fill(5.5,weighttemp);
		  if(NGBJets>=1){
		    histos["CutflowLowDM_" +samplename]->Fill(6.5,weighttemp);
		    histos["CutflowHighDM_"+samplename]->Fill(6.5,weighttemp);
		    if(mt_met_lep()>120){
		      histos["CutflowLowDM_" +samplename]->Fill(7.5,weighttemp);
		      histos["CutflowHighDM_"+samplename]->Fill(7.5,weighttemp);
		      if(pfmet()>100){
			histos["CutflowLowDM_" +samplename]->Fill(8.5,weighttemp);
			histos["CutflowHighDM_"+samplename]->Fill(8.5,weighttemp);
			if(mindphi_met_j1_j2()>0.8){
			  histos["CutflowLowDM_" +samplename]->Fill(9.5,weighttemp);
			  histos["CutflowHighDM_"+samplename]->Fill(9.5,weighttemp);
			  if(hadronic_top_chi2()<5){
			    histos["CutflowLowDM_" +samplename]->Fill(10.5,weighttemp);
			    histos["CutflowHighDM_"+samplename]->Fill(10.5,weighttemp);
			    if(pfmet()>150) histos["CutflowLowDM_"+samplename] ->Fill(11.5,weighttemp);
			    if(pfmet()>200) histos["CutflowLowDM_"+samplename] ->Fill(12.5,weighttemp);
			    if(pfmet()>250) histos["CutflowLowDM_"+samplename] ->Fill(13.5,weighttemp);
			    if(pfmet()>300) histos["CutflowLowDM_"+samplename] ->Fill(14.5,weighttemp);
			    if(MT2W()>200){
			      histos["CutflowHighDM_"+samplename]->Fill(11.5,weight);
			      if(pfmet()>150) histos["CutflowHighDM_"+samplename] ->Fill(12.5,weighttemp);
			      if(pfmet()>200) histos["CutflowHighDM_"+samplename] ->Fill(13.5,weighttemp);
			      if(pfmet()>250) histos["CutflowHighDM_"+samplename] ->Fill(14.5,weighttemp);
			      if(pfmet()>300) histos["CutflowHighDM_"+samplename] ->Fill(15.5,weighttemp);
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
	}
      }

      
      if(samplename!="TTbar1l"&&samplename!="TTbar2l"){
	if(nvtxs()<0) continue; ++c1vtx;                  if(myleppdgid==11) ++c1vtxel;     if(myleppdgid==13) ++c1vtxmu;
	if(NGLeps!=1) continue; ++c1l;                    if(myleppdgid==11) ++c1lel;       if(myleppdgid==13) ++c1lmu;
	if(NSLeps!=1) continue; ++cno2l;                  if(myleppdgid==11) ++cno2lel;     if(myleppdgid==13) ++cno2lmu;
	if(!PassTrackVeto()) continue; ++cno2track;       if(myleppdgid==11) ++cno2trackel; if(myleppdgid==13) ++cno2trackmu;
	if(!PassTauVeto()) continue; ++cnotau;            if(myleppdgid==11) ++cnotauel;    if(myleppdgid==13) ++cnotaumu;
	if(NGJets<4) continue; ++c2j;                     if(myleppdgid==11) ++c2jel;       if(myleppdgid==13) ++c2jmu;
	if(NGBJets<1) continue; ++c1b;                    if(myleppdgid==11) ++c1bel;       if(myleppdgid==13) ++c1bmu;
	if(pfmet()<100) continue; ++cmet;                 if(myleppdgid==11) ++cmetel;      if(myleppdgid==13) ++cmetmu;
	if(mt_met_lep()<120) continue; ++cmt;             if(myleppdgid==11) ++cmtel;       if(myleppdgid==13) ++cmtmu;
	if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;   if(myleppdgid==11) ++cmdphiel;    if(myleppdgid==13) ++cmdphimu;
	if(hadronic_top_chi2()>5) continue; ++cchi;       if(myleppdgid==11) ++cchiel;      if(myleppdgid==13) ++cchimu;
      } else if (samplename=="TTbar1l"){
	if(nvtxs()<0) continue; ++l1c1vtx;                  if(myleppdgid==11) ++l1c1vtxel;     if(myleppdgid==13) ++l1c1vtxmu;
	if(NGLeps!=1) continue; ++l1c1l;                    if(myleppdgid==11) ++l1c1lel;       if(myleppdgid==13) ++l1c1lmu;
	if(NSLeps!=1) continue; ++l1cno2l;                  if(myleppdgid==11) ++l1cno2lel;     if(myleppdgid==13) ++l1cno2lmu;
	if(!PassTrackVeto()) continue; ++l1cno2track;       if(myleppdgid==11) ++l1cno2trackel; if(myleppdgid==13) ++l1cno2trackmu;
	if(!PassTauVeto()) continue; ++l1cnotau;            if(myleppdgid==11) ++l1cnotauel;    if(myleppdgid==13) ++l1cnotaumu;
	if(NGJets<4) continue; ++l1c2j;                     if(myleppdgid==11) ++l1c2jel;       if(myleppdgid==13) ++l1c2jmu;
	if(NGBJets<1) continue; ++l1c1b;                    if(myleppdgid==11) ++l1c1bel;       if(myleppdgid==13) ++l1c1bmu;
	if(pfmet()<100) continue; ++l1cmet;                 if(myleppdgid==11) ++l1cmetel;      if(myleppdgid==13) ++l1cmetmu;
	if(mt_met_lep()<120) continue; ++l1cmt;             if(myleppdgid==11) ++l1cmtel;       if(myleppdgid==13) ++l1cmtmu;
	if(mindphi_met_j1_j2()<0.8) continue; ++l1cmdphi;   if(myleppdgid==11) ++l1cmdphiel;    if(myleppdgid==13) ++l1cmdphimu;
	if(hadronic_top_chi2()>5) continue; ++l1cchi;       if(myleppdgid==11) ++l1cchiel;      if(myleppdgid==13) ++l1cchimu;
      } else if (samplename=="TTbar2l"){
	if(nvtxs()<0) continue; ++l2c1vtx;                  if(myleppdgid==11) ++l2c1vtxel;     if(myleppdgid==13) ++l2c1vtxmu;
	if(NGLeps!=1) continue; ++l2c1l;                    if(myleppdgid==11) ++l2c1lel;       if(myleppdgid==13) ++l2c1lmu;
	if(NSLeps!=1) continue; ++l2cno2l;                  if(myleppdgid==11) ++l2cno2lel;     if(myleppdgid==13) ++l2cno2lmu;
	if(!PassTrackVeto()) continue; ++l2cno2track;       if(myleppdgid==11) ++l2cno2trackel; if(myleppdgid==13) ++l2cno2trackmu;
	if(!PassTauVeto()) continue; ++l2cnotau;            if(myleppdgid==11) ++l2cnotauel;    if(myleppdgid==13) ++l2cnotaumu;
	if(NGJets<4) continue; ++l2c2j;                     if(myleppdgid==11) ++l2c2jel;       if(myleppdgid==13) ++l2c2jmu;
	if(NGBJets<1) continue; ++l2c1b;                    if(myleppdgid==11) ++l2c1bel;       if(myleppdgid==13) ++l2c1bmu;
	if(pfmet()<100) continue; ++l2cmet;                 if(myleppdgid==11) ++l2cmetel;      if(myleppdgid==13) ++l2cmetmu;
	if(mt_met_lep()<120) continue; ++l2cmt;             if(myleppdgid==11) ++l2cmtel;       if(myleppdgid==13) ++l2cmtmu;
	if(mindphi_met_j1_j2()<0.8) continue; ++l2cmdphi;   if(myleppdgid==11) ++l2cmdphiel;    if(myleppdgid==13) ++l2cmdphimu;
	if(hadronic_top_chi2()>5) continue; ++l2cchi;       if(myleppdgid==11) ++l2cchiel;      if(myleppdgid==13) ++l2cchimu;
      }
      if(pfmet()>150) histos["NEventsPerSR_"+samplename]  ->Fill(0.5,weight);
      if(pfmet()>200) histos["NEventsPerSR_"+samplename]  ->Fill(1.5,weight);
      if(pfmet()>250) histos["NEventsPerSR_"+samplename]  ->Fill(2.5,weight);
      if(pfmet()>300) histos["NEventsPerSR_"+samplename]  ->Fill(3.5,weight);
      if(MT2W()>200){
	if(pfmet()>150) histos["NEventsPerSR_"+samplename]  ->Fill(4.5,weight);
	if(pfmet()>200) histos["NEventsPerSR_"+samplename]  ->Fill(5.5,weight);
	if(pfmet()>250) histos["NEventsPerSR_"+samplename]  ->Fill(6.5,weight);
	if(pfmet()>300) histos["NEventsPerSR_"+samplename]  ->Fill(7.5,weight);
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
  
  string filename = "rootfiles/CutflowExtra"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;



  // Example Hgrams
  // sampleh->Draw();
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
  cout << "Electron events:" << endl;
  cout << "Events passing NVtx>=1: " << c1vtxel << endl;
  cout << "Events with one good lepton: " << c1lel << endl;
  cout << "Events with one selection lepton: " << cno2lel << endl;
  cout << "Events passing track veto: " << cno2trackel << endl;
  cout << "Events passing tau veto: " << cnotauel << endl;
  cout << "Events with at least 4 jets: " << c2jel << endl;
  cout << "Events with at least 1 b-jet: " << c1bel << endl;
  cout << "Events with MET>100: " << cmetel << endl;
  cout << "Events with MT>120: " << cmtel << endl;
  cout << "Events with minDPhi>0.8: " << cmdphiel << endl;
  cout << "Events with chi2<5: " << cchiel << endl;
  cout << "Muon events:" << endl;
  cout << "Events passing NVtx>=1: " << c1vtxmu << endl;
  cout << "Events with one good lepton: " << c1lmu << endl;
  cout << "Events with one selection lepton: " << cno2lmu << endl;
  cout << "Events passing track veto: " << cno2trackmu << endl;
  cout << "Events passing tau veto: " << cnotaumu << endl;
  cout << "Events with at least 4 jets: " << c2jmu << endl;
  cout << "Events with at least 1 b-jet: " << c1bmu << endl;
  cout << "Events with MET>100: " << cmetmu << endl;
  cout << "Events with MT>120: " << cmtmu << endl;
  cout << "Events with minDPhi>0.8: " << cmdphimu << endl;
  cout << "Events with chi2<5: " << cchimu << endl;
  if(skimFilePrefix=="TTbar"){
    cout << "For TTbar1l:" << endl;
    cout << "Events passing NVtx>=1: " << l1c1vtx << endl;
    cout << "Events with one good lepton: " << l1c1l << endl;
    cout << "Events with one selection lepton: " << l1cno2l << endl;
    cout << "Events passing track veto: " << l1cno2track << endl;
    cout << "Events passing tau veto: " << l1cnotau << endl;
    cout << "Events with at least 4 jets: " << l1c2j << endl;
    cout << "Events with at least 1 b-jet: " << l1c1b << endl;
    cout << "Events with MET>100: " << l1cmet << endl;
    cout << "Events with MT>120: " << l1cmt << endl;
    cout << "Events with minDPhi>0.8: " << l1cmdphi << endl;
    cout << "Events with chi2<5: " << l1cchi << endl;
    cout << "Electron events:" << endl;
    cout << "Events passing NVtx>=1: " << l1c1vtxel << endl;
    cout << "Events with one good lepton: " << l1c1lel << endl;
    cout << "Events with one selection lepton: " << l1cno2lel << endl;
    cout << "Events passing track veto: " << l1cno2trackel << endl;
    cout << "Events passing tau veto: " << l1cnotauel << endl;
    cout << "Events with at least 4 jets: " << l1c2jel << endl;
    cout << "Events with at least 1 b-jet: " << l1c1bel << endl;
    cout << "Events with MET>100: " << l1cmetel << endl;
    cout << "Events with MT>120: " << l1cmtel << endl;
    cout << "Events with minDPhi>0.8: " << l1cmdphiel << endl;
    cout << "Events with chi2<5: " << l1cchiel << endl;
    cout << "Muon events:" << endl;
    cout << "Events passing NVtx>=1: " << l1c1vtxmu << endl;
    cout << "Events with one good lepton: " << l1c1lmu << endl;
    cout << "Events with one selection lepton: " << l1cno2lmu << endl;
    cout << "Events passing track veto: " << l1cno2trackmu << endl;
    cout << "Events passing tau veto: " << l1cnotaumu << endl;
    cout << "Events with at least 4 jets: " << l1c2jmu << endl;
    cout << "Events with at least 1 b-jet: " << l1c1bmu << endl;
    cout << "Events with MET>100: " << l1cmetmu << endl;
    cout << "Events with MT>120: " << l1cmtmu << endl;
    cout << "Events with minDPhi>0.8: " << l1cmdphimu << endl;
    cout << "Events with chi2<5: " << l1cchimu << endl;
    cout << "For TTbar2l:" << endl;
    cout << "Events passing NVtx>=1: " << l2c1vtx << endl;
    cout << "Events with one good lepton: " << l2c1l << endl;
    cout << "Events with one selection lepton: " << l2cno2l << endl;
    cout << "Events passing track veto: " << l2cno2track << endl;
    cout << "Events passing tau veto: " << l2cnotau << endl;
    cout << "Events with at least 4 jets: " << l2c2j << endl;
    cout << "Events with at least 1 b-jet: " << l2c1b << endl;
    cout << "Events with MET>100: " << l2cmet << endl;
    cout << "Events with MT>120: " << l2cmt << endl;
    cout << "Events with minDPhi>0.8: " << l2cmdphi << endl;
    cout << "Events with chi2<5: " << l2cchi << endl;
    cout << "Electron events:" << endl;
    cout << "Events passing NVtx>=1: " << l2c1vtxel << endl;
    cout << "Events with one good lepton: " << l2c1lel << endl;
    cout << "Events with one selection lepton: " << l2cno2lel << endl;
    cout << "Events passing track veto: " << l2cno2trackel << endl;
    cout << "Events passing tau veto: " << l2cnotauel << endl;
    cout << "Events with at least 4 jets: " << l2c2jel << endl;
    cout << "Events with at least 1 b-jet: " << l2c1bel << endl;
    cout << "Events with MET>100: " << l2cmetel << endl;
    cout << "Events with MT>120: " << l2cmtel << endl;
    cout << "Events with minDPhi>0.8: " << l2cmdphiel << endl;
    cout << "Events with chi2<5: " << l2cchiel << endl;
    cout << "Muon events:" << endl;
    cout << "Events passing NVtx>=1: " << l2c1vtxmu << endl;
    cout << "Events with one good lepton: " << l2c1lmu << endl;
    cout << "Events with one selection lepton: " << l2cno2lmu << endl;
    cout << "Events passing track veto: " << l2cno2trackmu << endl;
    cout << "Events passing tau veto: " << l2cnotaumu << endl;
    cout << "Events with at least 4 jets: " << l2c2jmu << endl;
    cout << "Events with at least 1 b-jet: " << l2c1bmu << endl;
    cout << "Events with MET>100: " << l2cmetmu << endl;
    cout << "Events with MT>120: " << l2cmtmu << endl;
    cout << "Events with minDPhi>0.8: " << l2cmdphimu << endl;
    cout << "Events with chi2<5: " << l2cchimu << endl;
  }

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
