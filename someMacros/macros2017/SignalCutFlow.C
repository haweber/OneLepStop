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
#include "TH3D.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include <sstream>
#include <iostream>
#include <fstream>

// CMS3
//#include "CMS3_old20150505.cc"
//#include "CMS3_fuckingsync.cc"
#include "CMS3_Jan17.cc"
//#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
//#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
//#include "/home/users/haweber/CORE/Tools/goodrun.h"
//#include "/home/users/haweber/CORE/Tools/goodrun.cc"

//MT2 variants

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float dPhibetweenVectors(float phi1,float phi2 ){                                                                                                              
  return fabs(std::min(float(fabs(phi1-phi2)),float(2*M_PI-fabs(phi1-phi2))));
}

float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
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

  histonames.push_back("SignalCutFlow");
  // 1: preselection: >=1lep, >=2 jets, MET>150 GeV
  // 2: + MT > 150 GeV
  // 3: + >=1 b-tags
  // 4: + 2nd lep veto
  // 5: + tau/track veto
  // 6: + MDPhi > 0.8
  // 7: + MET > 250 GeV
  // 8: 7) + tmod > 0
  // 9: 7) + tmod > 10
  //10: 7) + Mlb > 175 GeV
  //11: 7) + Mlb < 175 GeV
  //12: all SR
  //13-39: each SR separately
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i] + "_"+skimFilePrefix;
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 43, 0.5, 43.5);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }

  //const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  //set_goodrun_file_json(json_file);


  unsigned int nEventsRunning = 0;
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
  TH3D* counterhistSig;
  TH1D* counterhist;

  
  string samplename = skimFilePrefix;
  string tempsignal = skimFilePrefix;
  int mStop, mLSP;
  std::replace( tempsignal.begin(), tempsignal.end(), '_', ' ');
  sscanf(tempsignal.c_str(), "Signal %*s %i %i", &mStop, &mLSP);
  cout << "Signal working points are " << mStop << " " << mLSP << endl;
    
  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    //if(skimFilePrefix.find(string("Signal")) != string::npos){
    counterhistSig = (TH3D*)file->Get("h_counterSMS");
    counterhistSig->SetDirectory(0);
    //} else { 
    //  counterhist = (TH1D*)file->Get("h_counter");
    //  counterhist->SetDirectory(0);
    //}

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

      //if( is_data() && !goodrun(run(), ls()) ) continue;
      float weight = 1;

      int Nevts = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,36));
      if(mStop!=(int)mass_stop()) continue;
      if(mLSP==0){
	if((int)mass_stop()<0||(int)mass_stop()>1) continue;
      }
      else if(mLSP!=(int)mass_lsp()) continue;	
      double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
	double BSFweighttight = weight_tightbtagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	double lepSFweight = weight_lepSF()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
	double lepFSweight = weight_lepSF_fastSim()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
	if(BSFweighttight<0) BSFweighttight = BSFweight;
	weight = xsec()*35900/nevts;
	if(BSFweight>=0) weight *= BSFweight;
	if(lepSFweight>=0) weight *= lepSFweight;
	if(lepFSweight>=0) weight *= lepFSweight;
	//}
	if(weight==0) cout << xsec() << " " << nevts << " " << BSFweight << " " << lepSFweight << " " << lepFSweight << endl;

      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)          continue;
      //if(nvetoleps()!=1)          continue;
      //if(!PassTrackVeto())        continue;
      //if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      //if(ngoodbtags()<1)          continue;
      //if(pfmet()<250)             continue;
      //if(mt_met_lep()<150)        continue;
      //if(mindphi_met_j1_j2()<0.5) continue;
      if(!filt_fastsimjets() )    continue;//THIS IS SO ON NEW BABIES
      int SR = -1;
      int cSR = -1;
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()>=1&&mindphi_met_j1_j2()>0.8&&pfmet()>=250&&mt_met_lep()>150) { //basis for SR 1l, >=1b
	if(ngoodjets()>=2&&ngoodjets()<=3&&topnessMod()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>600) SR = 4;
	    else if(pfmet()>450) SR = 3;
	    else if(pfmet()>350) SR = 2;
	    else if(pfmet()>250) SR = 1;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>600) SR = 7;
	    else if(pfmet()>450) SR = 6;
	    else if(pfmet()>250) SR = 5;
	  }
	} else if(ngoodjets()>=4&&topnessMod()<=0.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>650) SR = 12;
	    else if(pfmet()>550) SR = 11;
	    else if(pfmet()>450) SR = 10;
	    else if(pfmet()>350) SR = 9;
	    else if(pfmet()>250) SR = 8;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>550) SR = 16;
	    else if(pfmet()>450) SR = 15;
	    else if(pfmet()>350) SR = 14;
	    else if(pfmet()>250) SR = 13;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>0.&&topnessMod()<=10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>550) SR = 19;
	    else if(pfmet()>350) SR = 18;
	    else if(pfmet()>250) SR = 17;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>450) SR = 21;
	    else if(pfmet()>250) SR = 20;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet()>600) SR = 25;
	    else if(pfmet()>450) SR = 24;
	    else if(pfmet()>350) SR = 23;
	    else if(pfmet()>250) SR = 22;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet()>450) SR = 27;
	    else if(pfmet()>250) SR = 26;
	  }
	}
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150&&ak4pfjets_passMEDbtag()[0]==false){
	if(     pfmet()>550) cSR = 4;
	else if(pfmet()>450) cSR = 3;
	else if(pfmet()>350) cSR = 2;
	else if(pfmet()>250) cSR = 1;
      }
      if(cSR>0) {cSR +=12; cSR +=27;}
      if(cSR>0) {/* cout << "cSR " << cSR << endl;*/ histos["SignalCutFlow_"+skimFilePrefix]->Fill(cSR,weight); }

      //cout << "pfmet " << pfmet() << " SR " << SR << " SignalCutFlow_"<<skimFilePrefix << " " << histos["SignalCutFlow_"+skimFilePrefix]->Integral() << " " << weight << endl;
      if(SR>0) SR += 12;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(1,weight);
      if(mt_met_lep()<150) continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(2,weight);
      if(ngoodbtags()<1) continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(3,weight);
      if(ngoodleps()!=1) continue;
      if(nvetoleps()!=1) continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(4,weight);
      if(!PassTrackVeto())        continue;
      if(!PassTauVeto())          continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(5,weight);
      if(mindphi_met_j1_j2()<0.8) continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(6,weight);
      if(pfmet()<250) continue;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(7,weight);
      if(topnessMod()> 0)    histos["SignalCutFlow_"+skimFilePrefix]->Fill( 8,weight);
      if(topnessMod()>10)    histos["SignalCutFlow_"+skimFilePrefix]->Fill( 9,weight);
      if(Mlb_closestb()>175&&ntightbtags()>=1) histos["SignalCutFlow_"+skimFilePrefix]->Fill(10,weight/BSFweight*BSFweighttight);//should I also apply tight b
      if(Mlb_closestb()<175) histos["SignalCutFlow_"+skimFilePrefix]->Fill(11,weight);
      if(SR<=0) continue;
      if(Mlb_closestb()>175) weight *= BSFweighttight/BSFweight;
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(12,weight);
      histos["SignalCutFlow_"+skimFilePrefix]->Fill(SR,weight);
      //cout << "SR " << SR << endl;
      
    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  string filename = "rootfiles/SignalCutFlow_reco.root";
  //string filename = "rootfiles/SignalCutFlow_gen.root";
  TFile *f = new TFile(filename.c_str(),"UPDATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;

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
