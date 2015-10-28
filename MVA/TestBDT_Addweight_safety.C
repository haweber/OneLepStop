/**********************************************************************************
 * Project   : TMVA - a Root-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Exectuable: TMVAClassificationApplication                                      *
 *                                                                                *
 * This macro provides a simple example on how to use the trained classifiers     *
 * within an analysis module                                                      *
 **********************************************************************************/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#endif

using namespace TMVA;

void TestBDT_Addweight(TString file, TString sig);
void TestBDT_AddweightAll(TString file);

void TestBDT_AddweightAll(TString file){
  vector<TString> sig;
  TestBDT_Addweight(file,"T2bw_600_187p5_50");
  TestBDT_Addweight(file,"T2bw_600_325_50");
  TestBDT_Addweight(file,"T2bw_600_462p5_50");
  TestBDT_Addweight(file,"T2bw_700_250_100");
  TestBDT_Addweight(file,"T2bw_700_400_100");
  TestBDT_Addweight(file,"T2bw_700_550_100");
  TestBDT_Addweight(file,"T2tb_700_250_100");
  TestBDT_Addweight(file,"T2tb_700_400_100");
  TestBDT_Addweight(file,"T2tb_700_550_100");
  TestBDT_Addweight(file,"T2tt_425_325");
  TestBDT_Addweight(file,"T2tt_500_325");
  TestBDT_Addweight(file,"T2tt_650_325");
  TestBDT_Addweight(file,"T2tt_850_100");
}

void TestBDT_Addweight(TString file, TString sig) 
{   
#ifdef __CINT__
   gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT
#endif

   //---------------------------------------------------------------

   // This loads the library
   TMVA::Tools::Instance();

   TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );    

   vector<TString> histonamesBDT; histonamesBDT.clear();
   vector<TString> histonames; histonames.clear();
   map<string, float> valueBDT;
   vector<float> valueBDTx;
   map<string, float> value;
   vector<float> inputvalue;

   histonamesBDT.push_back("MT2W");             
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
   //histonamesBDT.push_back("dR_lep_leadb");        
   //histonamesBDT.push_back("hadronic_top_chi2");             
   //histonamesBDT.push_back("ngoodbtags");           
   histonamesBDT.push_back("ngoodjets");            
   histonamesBDT.push_back("mindphi_met_j1_j2");        
   histonamesBDT.push_back("lep1_pt");
   histonamesBDT.push_back("ak4pfjets_leadMEDbjet_p4_Pt"); 
   // Create a set of variables and declare them to the reader
   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
   for(unsigned int i = 0; i<histonamesBDT.size();++i){
     //valueBDTx.push_back(0.);
     reader->AddVariable( histonamesBDT[i].Data(), &valueBDT[histonamesBDT[i].Data() ]);
     //reader->AddVariable( histonamesBDT[i].Data(), &valueBDTx[i]);
   }

   // Spectator variables declared in the training have to be added to the reader, too
   //Float_t spec1,spec2;
   //reader->AddSpectator( "spec1 := var1*2",   &spec1 );
   //reader->AddSpectator( "spec2 := var1*3",   &spec2 );

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
   histonames.push_back("ak4pfjets_leadMEDbjet_p4_Pt"); 

   // --- Book the MVA methods

   TString dir    = "weights/";
   TString prefix = "TMVAClassification";

   // Book method(s)
   TString methodName = TString("BDT method");
   TString weightfile = TString("/home/users/haweber/StopAnalysis/AnalysisCode/weights/weightsTMVA_") + sig + TString("VsTTbar2l_BDT.weights.xml");
   reader->BookMVA( methodName, weightfile ); 
   cout << "test " << reader->EvaluateMVA( "BDT method") << endl;

   // Prepare input tree (this must be replaced by your data source)
   // in this example, there is a toy tree with signal and one with background events
   // we'll later on use only the "signal" events for the test in this example.
   //   
   TFile *input(0);
   //TString fname = "/hadoop/cms/store/user/haweber/forBDT/toadd/"+file+".root";   
   TString fname = "/home/users/haweber/StopAnalysis/AnalysisCode/"+file+".root";   
   if (!gSystem->AccessPathName( fname )) {
     //input = TFile::Open( fname ); // check if file in local directory exists
     input = new TFile( fname, "update" );
   } else {
     std::cout << "ERROR: could not open data file " << fname << std::endl;
     exit(1);
   }
   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;
   
   // --- Event loop

   // Prepare the event tree
   // - here the variable names have to corresponds to your tree
   // - you can use the same variables as above which is slightly faster,
   //   but of course you can use different ones and copy the values inside the event loop
   //
   std::cout << "--- Select signal sample" << std::endl;
   TTree* theTree = (TTree*)input->Get("t");
   for(unsigned int i = 0; i<histonames.size();++i){
     theTree->SetBranchAddress(histonames[i], &value[histonames[i].Data() ]);
   }
   TString newbranchname = "BDToutput_"+sig;
   TString newbranchnamehelp = "BDToutput_"+sig+"/F";
   float BDToutput;
   TBranch *newbranch = theTree->Branch(newbranchname.Data(),&BDToutput,newbranchnamehelp.Data());
   newbranchname = "BDToutput_"+sig;
   TString newbranchnameerr = "BDToutputErr_"+sig;
   TString newbranchnamehelperr = "BDToutputErr_"+sig+"/F";
   float BDToutputerr;
   TBranch *newbrancherr = theTree->Branch(newbranchnameerr.Data(),&BDToutputerr,newbranchnamehelperr.Data());
   std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   for (Long64_t ievt=0; ievt<theTree->GetEntries();ievt++) {

      if (ievt%10000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

      theTree->GetEntry(ievt);

      valueBDT["MT2W"] = value["MT2W"];             
      valueBDT["Mlb_lead_bdiscr"] = value["Mlb_lead_bdiscr"];             
      valueBDT["pfmet"] = value["pfmet"];             
      valueBDT["ngoodjets"] = value["ngoodjets"];             
      valueBDT["mindphi_met_j1_j2"] = value["mindphi_met_j1_j2"];             
      valueBDT["lep1_pt"] = value["lep1_pt"];             
      valueBDT["ak4pfjets_leadMEDbjet_p4_Pt"] = value["ak4pfjets_leadMEDbjet_p4_Pt"];             
      
      // --- Return the MVA outputs and fill into histograms
      BDToutput =  reader->EvaluateMVA( "BDT method");
      BDToutputerr   = reader->GetMVAError();
      //if (ievt%10000 == 0) cout << BDToutput << endl;
      newbranch->Fill();
      newbrancherr->Fill();

   }
   theTree->Write();

   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: "; sw.Print();


   // --- Write histograms

   TFile *target  = new TFile( "TMVApp.root","RECREATE" );


   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;
  
   delete reader;
   delete input;
    
   std::cout << "==> TMVAClassificationApplication is done!" << endl << std::endl;
} 
