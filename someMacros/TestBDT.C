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


using namespace std;

int TestBDT(TString sig, TString bkg) {

   // This loads the library
   TMVA::Tools::Instance();

   // to get access to the GUI and all tmva macros
   TString thisdir = gSystem->DirName(gInterpreter->GetCurrentMacroName());
   gROOT->SetMacroPath(thisdir + ":" + gROOT->GetMacroPath());
   //gROOT->ProcessLine(".L TMVAGui.C");
   TString outfileName( "rootfiles/smallTMVA_"+sig+"Vs"+bkg+".root" );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );
   TMVA::Factory *factory = new TMVA::Factory( "myBDTtest", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar");

  vector<TString> histonames; histonames.clear();
  map<string, float> value;

  histonames.push_back("MT2W");               
  //histonames.push_back("MT2_b_b");            
  histonames.push_back("MT2_lb_b");           
  //histonames.push_back("MT2_lb_bq");          
  histonames.push_back("MT2_lb_bqq");         
  //histonames.push_back("MT2_l_q");            
  histonames.push_back("MT2_lb_b_mless");     
  //histonames.push_back("MT2_lb_bq_mless");    
  histonames.push_back("MT2_lb_bqq_mless");   
  //histonames.push_back("MT2_l_qq_mless");     
  histonames.push_back("Mlb");                
  //histonames.push_back("Mlbb");               
  histonames.push_back("M3b");                
  histonames.push_back("MTb");                
  //histonames.push_back("MTq");                
  histonames.push_back("MTqmax");             
  //histonames.push_back("MTq_boostmax");       
  //histonames.push_back("MTq_boost300");       
  histonames.push_back("MTq_boostLeadJet");   
  // histonames.push_back("MTqq");               
  histonames.push_back("Topness");            
  histonames.push_back("MT");                 
  histonames.push_back("MET");                
  histonames.push_back("HT");                 
  histonames.push_back("METoverSqrtHT");      
  histonames.push_back("HTratio");            
  histonames.push_back("dRLepBJet");          
  histonames.push_back("dRbb");               
  histonames.push_back("chi2");               
  histonames.push_back("NBJets");             
  histonames.push_back("NJets");              
  //histonames.push_back("minDPhi");            
  histonames.push_back("minDPhiJ3");          
  //histonames.push_back("minDPhiB");           
  //histonames.push_back("pTlb");               
  histonames.push_back("pTlbb");              
  histonames.push_back("pTl");                
  histonames.push_back("pTleadj");            
  histonames.push_back("pTleadb");            
  //histonames.push_back("pTtrailb");           
  //histonames.push_back("sumak8prunedmass");   
  histonames.push_back("DeltaPhiWl");     

  for(unsigned int b = 0; b<histonames.size(); ++b){
    factory->AddVariable(histonames[b], 'F' );
  }

  TString signame = "rootfiles/TestmysmallBDTvartree_"+sig+".root";
  TString bkgname = "rootfiles/TestmysmallBDTvartree_"+bkg+".root";
  TFile *inputSig = TFile::Open( signame );
  TFile *inputBkg = TFile::Open( bkgname );
  TTree *signal     = (TTree*)inputSig->Get(sig);
  TTree *background = (TTree*)inputBkg->Get(bkg);

   // global event weights per tree (see below for setting event-wise weights)
   Double_t signalWeight     = 1.0;
   Double_t backgroundWeight = 1.0;
   
   // You can add an arbitrary number of signal or background trees
   factory->AddSignalTree    ( signal,     signalWeight     );
   factory->AddBackgroundTree( background, backgroundWeight );

   //factory->SetBackgroundWeightExpression( "weight" );
   // Apply additional cuts on the signal and background samples (can be different)
   TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
   TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";
   factory->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );
   factory->BookMethod( TMVA::Types::kBDT, "BDT",
			"!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );
   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;

   // Launch the GUI for the root macros
   //if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName );

  return 0;
}
