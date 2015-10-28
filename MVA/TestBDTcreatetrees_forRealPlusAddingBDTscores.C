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
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#endif

// CMS3
#include "CMS3_fuckingsync.cc"

using namespace std;
using namespace tas;

float deltaPhi(LorentzVector jet1, LorentzVector jet2){
  // From cmssw reco::deltaPhi()
  float result = jet1.Phi() - jet2.Phi();
  while( result >   TMath::Pi() ) result -= TMath::TwoPi();
  while( result <= -TMath::Pi() ) result += TMath::TwoPi();
  return TMath::Abs(result);
}

inline float getMT(LorentzVector lep,LorentzVector met){
  // From cmssw reco::deltaPhi()
  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(deltaPhi(lep,met) ) ) );
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {


  vector<TString> sig;
  sig.push_back("T2bw_600_187p5_50");
  sig.push_back("T2bw_600_325_50");
  sig.push_back("T2bw_600_462p5_50");
  sig.push_back("T2bw_700_250_100");
  sig.push_back("T2bw_700_400_100");
  sig.push_back("T2bw_700_550_100");
  sig.push_back("T2tb_700_250_100");
  sig.push_back("T2tb_700_400_100");
  sig.push_back("T2tb_700_550_100");
  sig.push_back("T2tt_425_325");
  sig.push_back("T2tt_500_325");
  sig.push_back("T2tt_650_325");
  sig.push_back("T2tt_850_100");
  TMVA::Tools::Instance();
   const unsigned int n = sig.size(); 

   TMVA::Reader* reader[n];
   for(unsigned int j = 0;j<n;++j) reader[j] = new TMVA::Reader( "!Color:!Silent" );    

  vector<TString> histonamesBDT; histonamesBDT.clear();
  map<TString, float> valueBDT;

  //histonamesBDT.push_back("MT2W");             
  //histonamesBDT.push_back("MT2_lb_b");         
  //histonamesBDT.push_back("MT2_lb_bqq");       
  //histonamesBDT.push_back("MT2_lb_b_mass");   
  //histonamesBDT.push_back("MT2_lb_bqq_mass"); 
  histonamesBDT.push_back("Mlb_lead_bdiscr");              
  //histonamesBDT.push_back("Mjjj");              
  //histonamesBDT.push_back("topness");          
  //histonamesBDT.push_back("topnessMod");          
  histonamesBDT.push_back("pfmet");              
  //histonamesBDT.push_back("ak4_HT");               
  //histonamesBDT.push_back("MET_over_sqrtHT");    
  //histonamesBDT.push_back("ak4_htratiom");          
  histonamesBDT.push_back("dR_lep_leadb");        
  //histonamesBDT.push_back("hadronic_top_chi2");             
  //histonamesBDT.push_back("ngoodbtags");           
  histonamesBDT.push_back("ngoodjets");            
  //histonamesBDT.push_back("mindphi_met_j1_j2");        
  //histonamesBDT.push_back("lep1_pt");
  histonamesBDT.push_back("ak4pfjets_leadMEDbjet_p4_Pt"); 
  // Create a set of variables and declare them to the reader
  // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
  for(unsigned int i = 0; i<histonamesBDT.size();++i){
    for(unsigned int j = 0;j<n;++j) reader[j]->AddVariable( histonamesBDT[i].Data(), &valueBDT[histonamesBDT[i].Data() ]);
  }
  TString dir    = "weights/";
  TString prefix = "TMVAClassification";
  
  // Book method(s)
  TString methodName = TString("BDT method");
  for(unsigned int j = 0;j<n;++j) {
    TString weightfile = TString("/home/users/haweber/StopAnalysis/AnalysisCode/weights/weightsTMVA_") + sig[j] + TString("VsTTbar2l_BDT.weights.xml");
    reader[j]->BookMVA( methodName, weightfile ); 
  }

  
  
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
  map<string, float> value;

  histonames.push_back("scale1fb");             
  histonames.push_back("MT2W");             
  histonames.push_back("MT2_lb_b");         
  histonames.push_back("MT2_lb_bqq");       
  histonames.push_back("MT2_lb_b_mass");   
  histonames.push_back("MT2_lb_bqq_mass"); 
  histonames.push_back("Mlb_lead_bdiscr");              
  histonames.push_back("Mjjj");              
  histonames.push_back("topness");          
  histonames.push_back("topnessMod");          
  histonames.push_back("pfmet");              
  histonames.push_back("ak4_HT");               
  histonames.push_back("MET_over_sqrtHT");    
  histonames.push_back("ak4_htratiom");          
  histonames.push_back("dR_lep_leadb");        
  histonames.push_back("hadronic_top_chi2");             
  histonames.push_back("ngoodbtags");           
  histonames.push_back("ngoodjets");            
  histonames.push_back("mindphi_met_j1_j2");        
  histonames.push_back("lep1_pt");              

  histonames.push_back("NJets100");            
  histonames.push_back("ak4pfjets_pt_0");          
  histonames.push_back("NBJetsTight");           
  histonames.push_back("NBJetsLoose"); 
  histonames.push_back("ak4pfjets_leadMEDbjet_p4_Pt");          
  histonames.push_back("leadJisB");       
  histonames.push_back("MTj300");           
  histonames.push_back("RM300");
  
  histonames.push_back("mt_met_lep");
  histonames.push_back("nvtxs");
  histonames.push_back("nvetoleps");
  histonames.push_back("ngoodleps");
  histonames.push_back("PassTrackVeto_v3");
  histonames.push_back("PassTauVeto");


  TFile *outfile[3];
  TTree *outtree[3];
  for(unsigned int b = 0; b<histonames.size(); ++b){
    value[histonames[b] ] = -99;
    if(b<histonames.size()-5) histonameshelp.push_back(histonames[b]+(string)"/F");
    else if(b<histonames.size()-2) histonameshelp.push_back(histonames[b]+(string)"/I");
    else histonameshelp.push_back(histonames[b]+(string)"/O");
  }
  float BDToutput[n]/*[3]*/;
  //TBranch *newbranch[n][3];
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    //TString fileName = "/hadoop/cms/store/user/haweber/forBDT/"+samplename+".root";
    TString fileName = "/nfs-7/userdata/stopRun2/testMVA/standardsamples/"+samplename+".root";
    outfile[b] = new TFile(fileName,"RECREATE");
    outtree[b] = new TTree("t","");
    for(unsigned int a = 0; a<histonames.size(); ++a){
      outtree[b]->Branch(histonames[a].c_str(), &value[histonames[a] ], histonameshelp[a].c_str() );
    }
    for(unsigned int j = 0;j<n;++j) {
      TString newbranchname = "BDToutput_"+sig[j];
      TString newbranchnamehelp = "BDToutput_"+sig[j]+"/F";
      /*newbranch[j][b] = */outtree[b]->Branch(newbranchname.Data(),&BDToutput[j],newbranchnamehelp.Data());
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
    TString curname = currentFile->GetTitle();



    
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
      float weight = cms3.scale1fb()*3.;
      if(curname.EqualTo("/nfs-7/userdata/stopRun2/CMS3_V07-04-XX/v7.4.x_v5/TTJets_DiLept_madgraph_25ns_1.root")){
	weight *= 5977821./(5977821.+24521141.);
	if(event==0) cout << "Reweighted TTJets_DiLept_madgraph_25ns_1 (" << tree->GetEntries() << " entries) by " << (5977821./(5977821.+24521141.)) << endl;
      }
      if(curname.EqualTo("/nfs-7/userdata/stopRun2/CMS3_V07-04-XX/v7.4.x_v5/TTJets_DiLept_madgraph_25ns_2.root")){
	weight *= 24521141./(5977821.+24521141.);
	if(event==0) cout << "Reweighted TTJets_DiLept_madgraph_25ns_2 (" << tree->GetEntries() << " entries) by " << (24521141./(5977821.+24521141.)) << endl;
      }
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
      metlv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0.,pfmet());
      
      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGJets100 = 0;
      int NGBJets = 0;
      int NLBJets = 0;
      int NTBJets = 0;

      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NSLeps; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&lep1_MiniIso()<0.1) {++NSLeps; }
      }
      NGLeps = nvetoleps();

      float MYBTAG = 0.890;
      float MYBTAGLOOSE = 0.605;
      float MYBTAGTIGHT = 0.970;
      bool leadb = false; int cj = 0;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leadCSVlv; float leadCSV = -1.;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > bjetlv;
      vector<float> btag;
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	if(cj==0&&ak4pfjets_CSV()[nj]>MYBTAG) leadb=true; ++cj;
	jetlv.push_back(ak4pfjets_p4()[nj]);
	btag.push_back(ak4pfjets_CSV()[nj]);
	++NGJets;
	if(ak4pfjets_p4()[nj].Pt()>30) ++NGJets100;
	if(ak4pfjets_CSV()[nj]>leadCSV) { leadCSV = ak4pfjets_CSV()[nj]; leadCSVlv = ak4pfjets_p4()[nj]; }
	if(ak4pfjets_CSV()[nj]>MYBTAG) {++NGBJets; bjetlv.push_back(ak4pfjets_p4()[nj]);}
	if(ak4pfjets_CSV()[nj]>MYBTAGLOOSE) {++NLBJets;}
	if(ak4pfjets_CSV()[nj]>MYBTAGTIGHT) {++NTBJets;}
      }

      if(nvtxs()<0)           continue;
      if(nvetoleps()!=1)      continue;
      if(ngoodleps()!=1)      continue;
      if(!PassTrackVeto_v3()) continue;
      if(!PassTauVeto())      continue;
      if(NGJets<3)            continue;
      if(NGBJets<1)           continue;
      if(pfmet()<250)         continue;
      if(mt_met_lep()<150)    continue;
      if(mindphi_met_j1_j2()<0.8) continue;
      if(MT2W()<200)         continue;

      for(unsigned int i = 0; i<histonames.size(); ++i){
	value[histonames[i] ] = -99;//reset values
      }
      
      value["scale1fb"] = scale1fb();
      value["MT2W"] = MT2W();
      value["MT2_lb_b"] = MT2_lb_b();
      value["MT2_lb_bqq"] = MT2_lb_bqq();
      value["MT2_lb_b_mass"] = MT2_lb_b_mass();
      value["MT2_lb_bqq_mass"] = MT2_lb_bqq_mass();
      value["Mlb_lead_bdiscr"] = Mlb_lead_bdiscr(); 
      value["Mjjj"] = Mjjj();
      value["topness"] = topness();
      value["topnessMod"] = topnessMod();
      value["pfmet"] = pfmet();
      value["ak4_HT"] = ak4_HT();
      value["MET_over_sqrtHT"] = MET_over_sqrtHT();
      value["ak4_htratiom"] = ak4_htratiom();
      value["dR_lep_leadb"] = dR_lep_leadb();
      value["hadronic_top_chi2"] = hadronic_top_chi2();
      value["ngoodbtags"] = ngoodbtags();
      value["ngoodjets"] = ngoodjets();
      value["mindphi_met_j1_j2"] = mindphi_met_j1_j2();
      value["lep1_pt"] = lep1_pt();
      
      value["NJets100"] = NGJets100;
      value["ak4pfjets_pt_0"] = jetlv[0].Pt();
      value["NBJetsTight"] = NLBJets;
      value["NBJetsLoose"] = NTBJets;
      value["ak4pfjets_leadMEDbjet_p4_Pt"] = ak4pfjets_leadMEDbjet_p4().Pt();
      value["leadJisB"] = leadb ? 1 : 0;
      value["MTj300"] = jetlv[0].Pt()>300 ? getMT(jetlv[0],metlv) : 0;
      value["RM300"] = jetlv[0].Pt()>300 ? pfmet()/jetlv[0].Pt() : 0;

      value["mt_met_lep"] = mt_met_lep();
      value["nvtxs"] = nvtxs();
      value["nvetoleps"] = nvetoleps();
      value["ngoodleps"] = ngoodleps();
      value["PassTrackVeto_v3"] = PassTrackVeto_v3();
      value["PassTauVeto"] = PassTauVeto();

      valueBDT["Mlb_lead_bdiscr"] = value["Mlb_lead_bdiscr"];             
      valueBDT["pfmet"] = value["pfmet"];             
      valueBDT["ngoodjets"] = value["ngoodjets"];             
      valueBDT["dR_lep_leadb"] = value["dR_lep_leadb"];             
      valueBDT["ak4pfjets_leadMEDbjet_p4_Pt"] = value["ak4pfjets_leadMEDbjet_p4_Pt"];             
      
      // --- Return the MVA outputs and fill into histograms
      for(unsigned int j = 0;j<n;++j) {
	BDToutput[j] =  reader[j]->EvaluateMVA( "BDT method");
      }

      outtree[sampleid]->Fill();


      for(unsigned int i = 0; i<histonames.size(); ++i){
	value[histonames[i] ] = -99;//reset values
      }
      for(unsigned int i = 0; i<histonamesBDT.size(); ++i){
	valueBDT[histonamesBDT[i] ] = -99;//reset values
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
