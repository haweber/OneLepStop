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
//#include "CMS3_Moriond17.cc"
#include "CMS3_reminiAOD.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
#include "/home/users/haweber/CORE/Tools/goodrun.h"
#include "/home/users/haweber/CORE/Tools/goodrun.cc"

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

  int numTTZ = 0; int numTTZnunu = 0;
  double i1(0), i2(0), i3(0), i4(0), i5(0), i6(0), i7(0), i8(0), i9(0), i10(0), i11(0), i12(0), i13(0), i15(0), i16(0);
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

  histonames.push_back("NLeps");        hbins.push_back( 4); hlow.push_back(  0.); hup.push_back(4);
  histonames.push_back("genMET");       hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("MET");          hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("MT");           hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genHiggsZpT");  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genttbarpT");   hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  histonames.push_back("genttbarXpT");  hbins.push_back(30); hlow.push_back(  0.); hup.push_back(750);
  for(unsigned int i = 0; i<histonames.size(); ++i){
      string samplename = skimFilePrefix;
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      cout << mapname << endl;
  }


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

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    if(skimFilePrefix.find(string("Signal")) != string::npos){
      counterhistSig = (TH3D*)file->Get("h_counterSMS");
      counterhistSig->SetDirectory(0);
    } else { 
      counterhist = (TH1D*)file->Get("h_counter");
      counterhist->SetDirectory(0);
    }

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

      if( is_data() && !goodrun(run(), ls()) ) continue;
      float weight = 1;

      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(is1lepFromTop()) samplename = "TT1l";
	else samplename = "TT2l";
      }
      if(!is_data() && skimFilePrefix.find(string("ttH")) != string::npos) {
	int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(14));
	//if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(37));
	double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
	weight = cms3.scale1fb()*35.9;
	weight = 0.5071*0.574*35900./nevts;//TTH
	//weight = 0.7826*35900./nevts;//TTZ
	//cout << "weight " << weight << " BSF " << BSFweight << " lepSF " << lepSFweight << endl;
	//if(BSFweight>=0) weight *= BSFweight;
	//if(lepSFweight>=0) weight *= lepSFweight;
      }
      if(!is_data() && skimFilePrefix.find(string("ttZ")) != string::npos) {
	int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(14));
	//if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(37));
	double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
	weight = cms3.scale1fb()*35.9;
	//weight = 0.5071*0.574*35900./nevts;//TTH
	weight = 0.7826*35900./nevts;//TTZ
	//cout << "weight " << weight << " BSF " << BSFweight << " lepSF " << lepSFweight << endl;
	//if(BSFweight>=0) weight *= BSFweight;
	//if(lepSFweight>=0) weight *= lepSFweight;
      }
      //cout << __LINE__ << endl;
      TString currentfilename = currentFile->GetTitle();
     

      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)          continue;
      /*
      i3 += weight;
      if(nvetoleps()!=1)          continue;
      i4 += weight;
      if(!PassTrackVeto())        continue;
      i5 += weight;
      if(!PassTauVeto())          continue;
      i6 += weight;
      if(ngoodjets()<2)           continue;
      i7 += weight;
      if(ngoodbtags()<1)          continue;
      i8 += weight;
      if(pfmet()<250)             continue;
      i9 += weight;
      //if(mt_met_lep()<150)        continue;
      //if(mindphi_met_j1_j2()<0.5) continue;
      */

      LorentzVector Z(0,0,0,0); bool isZ = false;
      ++numTTZ;
      for(unsigned int i = 0; i<gennus_id().size(); ++i){
	if(!gennus_isLastCopy()[i]) continue;
	if(abs(gennus_motherid()[i])!=23) continue;
	if(abs(gennus_gmotherid()[i])==25) continue;
	//cout << "Higgs decay into leptons " << genleps_id()[i] << endl;
	Z = gennus_motherp4()[i];
	isZ = true;
	++numTTZnunu;
	break;
      }
      if(isZ&&skimFilePrefix.find(string("ttH")) != string::npos){ cout << skimFilePrefix << " has Ztonunu" << endl; }
      if(!isZ&&skimFilePrefix.find(string("ttZ")) != string::npos) continue;

      LorentzVector H(0,0,0,0); bool isH = false;
      for(unsigned int i = 0; i<gennus_id().size(); ++i){
	if(!gennus_isLastCopy()[i]) continue;
	if(abs(gennus_motherid()[i])!=23) continue;
	if(abs(gennus_gmotherid()[i])!=25) continue;
	//cout << "Higgs decay into leptons " << genleps_id()[i] << endl;
	H = gennus_gmotherp4()[i];
	isH = true;
	break;
      }
      LorentzVector t(0,0,0,0); bool ist = false;
      LorentzVector tbar(0,0,0,0); bool istbar = false;
      for(unsigned int i = 0; i<genqs_id().size(); ++i){
	if(!genqs_isLastCopy()[i]) continue;
	if(abs(genqs_id()[i])!=6) continue;
	if(!ist&&genqs_id()[i]==6){ ist = true; t = genqs_p4()[i]; }
	if(!istbar&&genqs_id()[i]==(-6)){ istbar = true; tbar = genqs_p4()[i]; }
	if(ist&&istbar)	break;
      }
      if(isH&&skimFilePrefix.find(string("ttZ")) != string::npos){ cout << skimFilePrefix << " has Htoinvisible" << endl; }
      if(!isH&&skimFilePrefix.find(string("ttH")) != string::npos) {cout << "This should not happen" << endl; continue; }

      histos["NLeps_"+skimFilePrefix]->Fill(nvetoleps(),weight);
      histos["MET_"+skimFilePrefix]->Fill(pfmet(),weight);
      histos["genMET_"+skimFilePrefix]->Fill(genmet(),weight);
      histos["MT_"+skimFilePrefix]->Fill(mt_met_lep(),weight);
      if(ist&&istbar) histos["genttbarpT_"+skimFilePrefix]->Fill((t+tbar).Pt(),weight);
      if(ist&&istbar&&isH) histos["genttbarXpT_"+skimFilePrefix]->Fill((t+tbar+H).Pt(),weight);
      if(ist&&istbar&&isZ) histos["genttbarXpT_"+skimFilePrefix]->Fill((t+tbar+Z).Pt(),weight);
      if(isH) histos["genHiggsZpT_"+skimFilePrefix]->Fill(H.Pt(),weight);
      if(isZ) histos["genHiggsZpT_"+skimFilePrefix]->Fill(Z.Pt(),weight);

    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    //add overflow
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
    //add underflow
    h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  
  //string filename = "rootfiles/PublicPlotHistos_reminiAOD.root";
  string filename = "rootfiles/ComparettZttH.root";//TTH

  TFile *f = new TFile(filename.c_str(),"UPDATE");
  f->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames[i] + "_"+samplename;
      histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
    }
  }  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;

  cout << "Num ttZ-->nunu " << numTTZnunu << "/" << numTTZ << " " << float(numTTZnunu)/float(numTTZ) << endl;

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
