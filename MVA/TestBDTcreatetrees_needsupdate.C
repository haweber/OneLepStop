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
#include "TSystem.h"
#include "TInterpreter.h"
#include "TTree.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
// needs to be included when makecint runs (ACLIC)
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#endif

// CMS3
#include "CMS3.cc"

//MT2 variants
#include "stop_variables/Davismt2.h"
#include "stop_variables/topness.h"
#include "stop_variables/MT2_implementations.h"
#include "stop_variables/JetUtil.h"
#include "stop_variables/mt2w.h"
#include "stop_variables/mt2w_bisect.h"

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
  /*
   // This loads the library
   TMVA::Tools::Instance();

   // to get access to the GUI and all tmva macros
   TString thisdir = gSystem->DirName(gInterpreter->GetCurrentMacroName());
   gROOT->SetMacroPath(thisdir + ":" + gROOT->GetMacroPath());
   gROOT->ProcessLine(".L TMVAGui.C");
*/

  map<string, TH1F*> histos; //massive
  vector<string> histonames; histonames.clear();
  vector<string> histonameshelp; histonameshelp.clear();
  vector<int> histobinn; histobinn.clear();
  vector<double> histobinl; histobinl.clear();
  vector<double> histobinu; histobinu.clear();
  map<string, float> value;

  histonames.push_back("MT2W");               histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(500.);
  //histonames.push_back("MT2_b_b");            histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("MT2_lb_b");           histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("MT2_lb_bq");          histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("MT2_lb_bqq");         histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(1000.);
  //histonames.push_back("MT2_l_q");            histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(300.);
  histonames.push_back("MT2_lb_b_mless");     histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("MT2_lb_bq_mless");    histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("MT2_lb_bqq_mless");   histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("MT2_l_qq_mless");     histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("Mlb");                histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("Mlbb");               histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(1000.);
  histonames.push_back("M3b");                histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(1000.);
  histonames.push_back("MTb");                histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("MTq");                histobinn.push_back(20); histobinl.push_back(0.); histobinu.push_back(500.);
  histonames.push_back("MTqmax");             histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(1500.);
  //histonames.push_back("MTq_boostmax");       histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(1500.);
  //histonames.push_back("MTq_boost300");       histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(1500.);
  histonames.push_back("MTq_boostLeadJet");   histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(1500.);
  //histonames.push_back("MTqq");               histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("Topness");            histobinn.push_back(30); histobinl.push_back(-15.); histobinu.push_back(15.);
  histonames.push_back("MT");                 histobinn.push_back(40); histobinl.push_back(0.); histobinu.push_back(400.);
  histonames.push_back("MET");                histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("HT");                 histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(1000.);
  histonames.push_back("METoverSqrtHT");      histobinn.push_back(20); histobinl.push_back(0.); histobinu.push_back(40.);
  histonames.push_back("HTratio");            histobinn.push_back(20); histobinl.push_back(0.); histobinu.push_back(1.);
  histonames.push_back("dRLepBJet");          histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(10.);
  histonames.push_back("dRbb");               histobinn.push_back(25); histobinl.push_back(0.); histobinu.push_back(10.);
  histonames.push_back("chi2");               histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(30.);
  histonames.push_back("NBJets");             histobinn.push_back( 5); histobinl.push_back(0.); histobinu.push_back(5.);
  histonames.push_back("NJets");              histobinn.push_back(10); histobinl.push_back(0.); histobinu.push_back(10.);
  //histonames.push_back("minDPhi");            histobinn.push_back(32); histobinl.push_back(0.); histobinu.push_back(3.2);
  histonames.push_back("minDPhiJ3");          histobinn.push_back(32); histobinl.push_back(0.); histobinu.push_back(3.2);
  //histonames.push_back("minDPhiB");           histobinn.push_back(32); histobinl.push_back(0.); histobinu.push_back(3.2);
  //histonames.push_back("pTlb");               histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(600.);
  histonames.push_back("pTlbb");              histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(600.);
  histonames.push_back("pTl");                histobinn.push_back(27); histobinl.push_back(0.); histobinu.push_back(405.);
  histonames.push_back("pTleadj");            histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("pTleadb");            histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("pTtrailb");           histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  //histonames.push_back("sumak8prunedmass");   histobinn.push_back(30); histobinl.push_back(0.); histobinu.push_back(750.);
  histonames.push_back("DeltaPhiWl");         histobinn.push_back(32); histobinl.push_back(0.); histobinu.push_back(3.2);

  TFile *outfile[3];
  TTree *outtree[3];
  for(unsigned int b = 0; b<histonames.size(); ++b){
    value[histonames[b] ] = -99;
    histonameshelp.push_back(histonames[b]+(string)"/F");
  }
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    TString fileName = "rootfiles/TestmysmallBDTvartree_"+samplename+".root";
    outfile[b] = new TFile(fileName,"RECREATE");
    outtree[b] = new TTree(samplename.c_str(),"");
    for(unsigned int a = 0; a<histonames.size(); ++a){
      outtree[b]->Branch(histonames[a].c_str(), &value[histonames[a] ], histonameshelp[a].c_str() );
    }
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

      int sampleid = 0;
      string samplename = skimFilePrefix;
      if(skimFilePrefix=="TTbar"){
	if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==2) { samplename = "TTbar2l"; sampleid=1; }
	else if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==1) { samplename = "TTbar1l"; sampleid=0; }
	else { samplename = "TTbarH"; sampleid=2; }
      }
      // Analysis Code
      float weight = cms3.scale1fb()*10.;
      int NLeps = cms3.ngoodlep();
      string ds = cms3.dataset();
      float MET = cms3.pfmet();
      float METPhi = cms3.pfmet_phi();
      float METx = MET*TMath::Cos(METPhi);
      float METy = MET*TMath::Sin(METPhi);
      float MT2W = cms3.MT2W_lep1();
      float MT = cms3.MT_MET_lep1();
      float dRLepBJet = cms3.dR_lep1_leadb();
      float chi2 = cms3.chi2();
      //float genmet = cms3.genmet();
      //int NJets = cms3.ak4GoodPFJets();
      //int NBJets = cms3.ak4_nBTags_Med();
      float HT = cms3.ak4_HT();
      float HTratio = cms3.ak4_htratiom();
      int nvtxs = cms3.nvtxs();
      float minDPhi = cms3.mindphi_met_j1_j2();
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_btag_disc();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();
      float lep1pt = cms3.lep1_pt();
      float lep1eta = cms3.lep1_eta();
      //float lep1dr03isoDB = cms3.lep1_relIso03DB();
      bool lep1eIDl = cms3.lep1_is_eleid_loose();
      bool lep1eIDm = cms3.lep1_is_eleid_medium();
      bool lep1mIDt = cms3.lep1_is_muoid_tight();
      bool lep1ismu = cms3.lep1_is_mu();
      bool lep1isel = cms3.lep1_is_el();
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep2lv = cms3.lep1_p4();
      float lep2pt = cms3.lep2_pt();
      float lep2eta = cms3.lep2_eta();
      //float lep2dr03isoDB = cms3.lep2_relIso03DB();
      bool lep2eIDl = cms3.lep2_is_eleid_loose();
      bool lep2eIDm = cms3.lep2_is_eleid_medium();
      bool lep2mIDt = cms3.lep2_is_muoid_tight();
      bool lep2ismu = cms3.lep2_is_mu();
      bool lep2isel = cms3.lep2_is_el();
      
      bool trackveto = cms3.PassTrackVeto();
      bool tauveto = cms3.PassTauVeto();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1;
      if(lep1ismu){
	//if(lep1pt>20&&fabs(lep1eta)<99&&lep1mIDt) ++NGLeps;
	//if(lep1pt>25&&fabs(lep1eta)<2.1&&lep1mIDt&&lep1dr03isoDB*lep1pt<TMath::Min(5.,0.15*lep1pt)) {++NSLeps; l1 = 1;}
	if(lep1pt>30&&fabs(lep1eta)<2.1&&fabs(cms3.lep1_d0())<0.02&&fabs(cms3.lep1_dz())<0.1&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      } else if (lep1isel){
	//if(lep1pt>20&&fabs(lep1eta)<99&&lep1eIDl) ++NGLeps;
	//if(lep1pt>30&&fabs(lep1eta)<1.442&&lep1eIDm&&lep1dr03isoDB*lep1pt<TMath::Min(5.,0.15*lep1pt)) {++NSLeps; l1 = 1;}
	if(lep1pt>40&&fabs(lep1eta)<2.1&&cms3.lep1_is_phys14_medium_noIso()&&cms3.lep1_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; }
      }
      if(lep2ismu){
	//if(lep2pt>20&&fabs(lep2eta)<99&&lep2mIDt) ++NGLeps;
	//if(lep2pt>25&&fabs(lep2eta)<2.1&&lep2mIDt&&lep2dr03isoDB*lep2pt<TMath::Min(5.,0.15*lep2pt)) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
	if(lep2pt>30&&fabs(lep2eta)<2.1&&fabs(cms3.lep2_d0())<0.02&&fabs(cms3.lep2_dz())<0.1&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; l1 = 1; if(l1!=1) l1 = 2; else l1=-2; }
      } else if (lep2isel){
	//if(lep2pt>20&&fabs(lep2eta)<99&&lep2eIDl) ++NGLeps;
	//if(lep2pt>30&&fabs(lep2eta)<1.442&&lep2eIDm&&lep2dr03isoDB*lep2pt<TMath::Min(5.,0.15*lep2pt)) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
	if(lep2pt>40&&fabs(lep2eta)<2.1&&cms3.lep2_is_phys14_medium_noIso()&&cms3.lep2_miniRelIsoDB()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
      }
      NGLeps = NLeps;

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      if(l1==1) leplv = lep1lv;
      else if(l1==2) leplv = lep2lv;

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(METx,METy,0.,MET);

      //if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
      //NGLeps = NLeps;
      vector<int> jind;
      vector<int> bind;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jsumlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > boostjetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > bjetlv;
      vector<float> btag;
      int jj1(-1), jj2(-1), jj3(-1);// j1(-1), j2(-1), jm(-1);
      float jj1d(-1), jj2d(-1), jj3d(-1);// jjmm(-1);
      for(unsigned int nj = 0; nj<jetsbtag.size(); ++nj){
	if(jetslv[nj].Pt()<30) continue;
	if(fabs(jetslv[nj].Eta())>2.4) continue;
	if(jetsID[nj]==false) continue;
	jind.push_back(nj);
	jetlv.push_back(jetslv[nj]);
	if(jetslv[nj].Pt()>250) boostjetlv.push_back(jetslv[nj]);
	btag.push_back(jetsbtag[nj]);
	++NGJets;
	if(jetsbtag[nj]>0.814) {++NGBJets; bind.push_back(nj); bjetlv.push_back(jetslv[nj]);}
	if(jetslv[nj].Pt()>jj1d){
	  jj3d = jj2d; jj2d = jj1d; jj1d = jetslv[nj].Pt();
	  jj3 = jj2; jj2 = jj1; jj1 = nj;
	} else if(jetslv[nj].Pt()>jj2d){
	  jj3d = jj2d; jj2d = jetslv[nj].Pt();
	  jj3 = jj2; jj2 = nj;
	} else if(jetslv[nj].Pt()>jj3d){
	  jj3d = jetslv[nj].Pt();
	  jj3 = nj;
	}
      }

      if(nvtxs<0) continue; 
      if(NGLeps!=1) continue; 
      if(NSLeps!=1) continue; 
      if(!trackveto) continue; 
      if(!tauveto) continue; 
      if(NGJets<4) continue;
      //if(NGBJets<1) continue; 
      if(MET<30) continue; 
      //if(MT>80) continue;

      for(unsigned int i = 0; i<histonames.size(); ++i){
	value[histonames[i] ] = -99;//reset values
      }
      //vector<LorentzVector > btaggedjets = JetUtil::BJetSelector(jetlv,btag,0.814,2,3,1);
      vector<LorentzVector > btaggedjets = JetUtil::BJetSelector(jetlv,btag,0.814,2,2,2);

      vector<LorentzVector > dummybjets;dummybjets.clear();
      LorentzVector dummybjet; dummybjet.SetPxPyPzE(0.,0.,0.,0.); dummybjets.push_back(dummybjet);dummybjets.push_back(dummybjet);
      
      //value["MT2W"]                  = CalculateMT2W_(btaggedjets,leplv,MET,METPhi,true);
      value["MT2W"] = MT2W;
      value["Topness"]               = Gettopness_(MET,METPhi,leplv,btaggedjets,1);
      value["MT2_b_b"]               = MT2_b_b_(MET,METPhi,btaggedjets,true, 0);
      value["MT2_lb_b_mless"]        = MT2_lb_b_(MET,METPhi,leplv,btaggedjets,false,0);
      value["MT2_lb_b"]              = MT2_lb_b_(MET,METPhi,leplv,btaggedjets,true ,0);
      value["MT2_lb_bq_mless"]       = MT2_lb_bq_( MET,METPhi,leplv,btaggedjets,jetlv,false,0);
      value["MT2_lb_bq"]             = MT2_lb_bq_( MET,METPhi,leplv,btaggedjets,jetlv,true ,0);
      value["MT2_lb_bqq_mless"]      = MT2_lb_bqq_(MET,METPhi,leplv,btaggedjets,jetlv,false,0);
      value["MT2_lb_bqq"]            = MT2_lb_bqq_(MET,METPhi,leplv,btaggedjets,jetlv,true ,0);
      value["MT2_l_q"]               = MT2_lb_bq_( MET,METPhi,leplv,dummybjets,jetlv,true ,0);
      value["MT2_l_qq_mless"]        = MT2_lb_bqq_(MET,METPhi,leplv,dummybjets,jetlv,true ,0);

      int leadb(-1), trailb(-1);
      for(unsigned int n = 0; n<btaggedjets.size();++n){
	if(leadb<0) leadb = n;
	else if(trailb<0) trailb = n;
	else if(btaggedjets[n].Pt() > btaggedjets[leadb].Pt()){ trailb = leadb; leadb = n; }
	else if(btaggedjets[n].Pt() > btaggedjets[trailb].Pt()){ trailb = n; }
	LorentzVector temp = btaggedjets[n]+leplv;
	if(temp.M()<value["Mlb"]) value["Mlb"] = temp.M();  else if(value["Mlb"]<0) value["Mlb"] = temp.M();
	if(temp.Pt()<value["pTlb"]) value["pTlb"] = temp.Pt();  else if(value["pTlb"]<0) value["pTlb"] = temp.Pt();
	float tmp = getMT(btaggedjets[n],metlv);
	if(tmp<value["MTb"]) value["MTb"] = tmp;  else if(value["MTb"]<0) value["MTb"] = tmp;
	tmp = JetUtil::deltaR(btaggedjets[n],leplv);
	tmp = JetUtil::deltaPhi(btaggedjets[n],metlv);
	if(tmp<value["minDPhiB"]) value["minDPhiB"] = tmp;  else if(value["minDPhiB"]<0) value["minDPhiB"] = tmp;
	for(unsigned int m = n+1; m<btaggedjets.size();++m){
	  temp = btaggedjets[n]+btaggedjets[m]+leplv;
	  if(temp.M()<value["Mlbb"]) value["Mlbb"] = temp.M();  else if(value["Mlbb"]<0) value["Mlbb"] = temp.M();
	  if(temp.Pt()<value["pTlbb"]) value["pTlbb"] = temp.Pt();  else if(value["pTlbb"]<0) value["pTlbb"] = temp.Pt();
	  tmp = JetUtil::deltaR(btaggedjets[n],btaggedjets[m]);
	  if(tmp<value["dRbb"]) value["dRbb"] = tmp;  else if(value["dRbb"]<0) value["dRbb"] = tmp;
	}
      }
      float myleadjpt = -1.;
      int bj1(-1), bj2(-1),bj3(-1);
      for(unsigned int n = 0; n<jetlv.size();++n){
	float tmp = getMT(jetlv[n],metlv);
  	if(tmp<value["MTq"]) value["MTq"] = tmp;  else if(value["MTq"]<0) value["MTq"] = tmp;
  	if(tmp>value["MTqmax"]) value["MTqmax"] = tmp;  else if(value["MTqmax"]<0) value["MTqmax"] = tmp;
	if(jetlv[n].Pt()>250.){ if(tmp>value["MTq_boostmax"]) value["MTq_boostmax"] = tmp;  else if(value["MTq_boostmax"]<0) value["MTq_boostmax"] = tmp; }
	if(jetlv[n].Pt()>300.){ if(tmp<value["MTq_boost300"]) value["MTq_boost300"] = tmp;  else if(value["MTq_boost300"]<0) value["MTq_boost300"] = tmp; }
	if(jetlv[n].Pt()>myleadjpt){ value["MTq_boostLeadJet"] = tmp; myleadjpt = jetlv[n].Pt(); }// else if(value["MTq_boostLeadJet"]<0) value["MTq_boostLeadJet"] = tmp;
	for(unsigned int m = n+1; m<jetlv.size();++m){
	  tmp = getMT(jetlv[n]+jetlv[m],metlv);
	  if(tmp<value["MTqq"]) value["MTqq"] = tmp;  else if(value["MTqq"]<0) value["MTqq"] = tmp;
	}
	if(n<3){
	  tmp = JetUtil::deltaPhi(jetlv[n],metlv);
	  if(tmp<value["minDPhiJ3"]) value["minDPhiJ3"] = tmp;  else if(value["minDPhiJ3"]<0) value["minDPhiJ3"] = tmp;
	}
	float dP1l(-1), dP2l(-1), dP3l(-1);
	if(bj1>0) dP1l = JetUtil::deltaPhi(jetlv[bj1],leplv);
	if(bj2>0) dP2l = JetUtil::deltaPhi(jetlv[bj2],leplv);
	if(bj3>0) dP3l = JetUtil::deltaPhi(jetlv[bj3],leplv);
	if(JetUtil::deltaPhi(jetlv[n],leplv)>dP1l){ bj3 = bj2; bj2 = bj1; bj1 = n;}
	else if(JetUtil::deltaPhi(jetlv[n],leplv)>dP2l){ bj3 = bj2; bj2 = n;}
	else if(JetUtil::deltaPhi(jetlv[n],leplv)>dP3l){ bj3 = n;}
      }

      LorentzVector bjsumlep = jetlv[bj1] + jetlv[bj2] + jetlv[bj3];
      value["M3b"] = bjsumlep.M();

      float prune=0.;
      for(unsigned int n = 0; n<cms3.ak8pfjets_pruned_mass().size();++n) prune += cms3.ak8pfjets_pruned_mass()[n];
      
      //cout << __LINE__<<endl;
      value["sumak8prunedmass"]   = prune;
      value["MT"] = MT;
      value["MET"] = MET;
      value["HT"] = HT;
      if(HT>0) {
	value["METoverSqrtHT"] = MET/TMath::Sqrt(HT);
      }
      value["HTratio"] = HTratio;
      value["dRLepBJet"] = dRLepBJet;
      value["chi2"] = chi2;
      value["NBJets"] = NGBJets;
      value["NJets"] = NGJets;
      value["minDPhi"] = minDPhi;
      value["pTl"] = leplv.Pt();
      value["pTleadj"] = myleadjpt;
      value["pTleadb"] = btaggedjets[leadb].Pt();
      value["pTtrailb"] = btaggedjets[trailb].Pt();
      value["DeltaPhiWl"] = JetUtil::deltaPhi(leplv,metlv+leplv);

      outtree[sampleid]->Fill();


      for(unsigned int i = 0; i<histonames.size(); ++i){
	value[histonames[i] ] = -99;//reset values
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

  for(unsigned int b = 0; b<3; ++b){
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    outfile[b]->cd();
    outtree[b]->Write();
    outfile[b]->Close();
    cout << "Tree for making BDT saved in " << outfile[b]->GetName() << endl;
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
