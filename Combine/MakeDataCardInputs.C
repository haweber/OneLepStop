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

using namespace std;
using namespace tas;



int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  float MEDBTAG = 0.890;
  
  int toplow   = 425; int topup   = 850; int topstep   = 25; 
  int charglow = 100; int chargup = 550; int chargstep = 25; 
  int lsplow   =  50; int lspup   = 325; int lspstep   = 25;
  
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
  vector<bool> storeh; storeh.clear();

  //AllBGCorr
  //CorrName1Name2Name3 with NameX being sampleX
  //CorrAllBG CorrAll means correlated among all backgrounds, or everything (bg+sig)
  histonames.push_back("SRyield");    hbins.push_back(5); hlow.push_back(  0.5); hup.push_back(5.5); storeh.push_back(true);
  histonames.push_back("CRyield");    hbins.push_back(5); hlow.push_back(  0.5); hup.push_back(5.5); storeh.push_back(true);
  histonames.push_back("StatUnc");    hbins.push_back(5); hlow.push_back(  0.5); hup.push_back(5.5); storeh.push_back(true);
  histonames.push_back("SystUnc");    hbins.push_back(5); hlow.push_back(  0.5); hup.push_back(5.5); storeh.push_back(true);
 
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    //cout << helper << endl;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    string mapname;
    if(helper.Contains("Signal")){
      for(int t = toplow; t<=topup; t+=topstep){
	for(int c = charglow; c<=chargup; c+=chargstep){
	  if(helper.Contains("T2tt")&&c!=charglow) continue;
	  if(!helper.Contains("T2tt")&&c>t) continue;
	  for(int l = lsplow; l<=lspup; l+=lspstep){
	    if(l>t) continue;
	    if(!helper.Contains("T2tt")&&l>c) continue;
	    TString signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);//%s contains x0p5 etc
	    if(!helper.Contains("T2tt") && !helper.Contains("x") ) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    //if(helper.Contains("x")) signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);
	    //else if(!helper.Contains("T2tt")) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    for(unsigned int i = 0; i<histonames.size();++i){
	      mapname = histonames[i] + "_" + signalname.Data();
	      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
	      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
	    }
	  }
	}
      }
    } else {
      for(unsigned int i = 0; i<histonames.size();++i){
	mapname = histonames[i] + "_" + samplename;
	if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
	histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
	//cout << mapname << endl;
      }
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
      
      string samplename = skimFilePrefix;
      if(skimFilePrefix=="TTbar"){
	if(genlepsfromtop() ==2) samplename = "TTbar2l";
	else if(genlepsfromtop() ==1) samplename = "TTbar1l";
	else { samplename = "TTbarH"; }// cout << "no gen lep" << " " << genlepsfromtop() << endl; }
      }
      TString helper = TString(samplename);
      
      if(helper.Contains("Signal")){
	if(helper.Contains("T2tt") || helper.Contains("x") ){
	  TString signalname = Form("%s_%d_%d",samplename.c_str(),(int)mass_stop(),(int)mass_lsp());
	  samplename = signalname.Data();
	} else {
	  TString signalname = Form("%s_%d_%d_%d",samplename.c_str(),(int)mass_stop(), (int)mass_chargino(),(int)mass_lsp());
	  samplename = signalname.Data();
	}
      }
      
      // Analysis Code
      float weight = cms3.scale1fb()*2.;
      if(samplename == "Data") weight = 1.;
      if(is_data()) weight = 1.;
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;
      //bool trackveto = cms3.PassTrackVeto();
      //bool tauveto = cms3.PassTauVeto();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NSLeps; }
	//if(lep1_pt()>30&&fabs(lep1_eta())<2.4&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NGLeps; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&lep1_MiniIso()<0.1) {++NSLeps; }
	//if(lep1_pt()>40&&fabs(lep1_eta())<2.5&&lep1_is_phys14_medium_noIso()&&lep1_MiniIso()<0.1) {++NGLeps; }
      }
      if(lep2_is_mu()){
       	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&lep2_passMediumID()&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NSLeps; }
      	//if(lep2_pt()>30&&fabs(lep2_eta())<2.4&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NGLeps; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&lep2_passMediumID()&&lep2_MiniIso()<0.1) {++NSLeps; }
	//if(lep2_pt()>40&&fabs(lep2_eta())<2.5&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NGLeps; }
      }
      NGLeps = nvetoleps();
      
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	++NGJets;

	if(ak4pfjets_CSV()[nj]>MEDBTAG) {++NGBJets; }
      }

      if(nvtxs()<0)                continue;
      if(nvetoleps()!=1)           continue;
      //if(NSLeps!=1)              continue;
      if(ngoodleps()!=1)           continue;
      if(!PassTrackVeto_v3())      continue;
      if(!PassTauVeto())           continue;
      if(ngoodjets()<4)            continue;
      if(ngoodbtags()<1)           continue;
      //if(NGJets<4)               continue;
      //if(NGBJets<1)              continue;
      if(mindphi_met_j1_j2()<0.8)  continue;
      //if(hadronic_top_chi2()>10) continue;
      if(pfmet()<250)              continue;
      if(mt_met_lep()<150)         continue;

    
      float mybin = -1;
      if(MT2W()<200){
	if(     pfmet()<325) mybin = 1;
	else                 mybin = 2;
      } else {
	if(     pfmet()<350) mybin = 3;
	else if(pfmet()<450) mybin = 4;
	else                 mybin = 5;
      }

      /*
      if(MT2W()<200){
	if(     pfmet()<300) mybin = 1;
	else if(pfmet()<350) mybin = 3;
	else if(pfmet()<400) mybin = 5;
	else                 mybin = 7;
      }
      else {
	if(     pfmet()<300) mybin = 2;
	else if(pfmet()<350) mybin = 4;
	else if(pfmet()<400) mybin = 6;
	else if(pfmet()<500) mybin = 8;
	else                 mybin = 9;
      }
      */
      histos["SRyield_" + samplename]->Fill(mybin,weight);
    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  //do all postrunning modifications here - maybe need some additional code if running over additional types of babies
  //i.e.if we have additional babies, run extra, hadd files and do further modifications (note you might need to store additional histos)
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    string mapname;
    if(helper.Contains("Signal")){
      for(int t = toplow; t<=topup; t+=topstep){
	for(int c = charglow; c<=chargup; c+=chargstep){
	  if(helper.Contains("T2tt")&&c!=charglow) continue;
	  if(!helper.Contains("T2tt")&&c>t) continue;
	  for(int l = lsplow; l<=lspup; l+=lspstep){
	    if(l>t) continue;
	    if(!helper.Contains("T2tt")&&l>c) continue;
	    TString signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);//%s contains x0p5 etc
	    if(!helper.Contains("T2tt") && !helper.Contains("x") ) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    //if(helper.Contains("x")) signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);
	    //else if(!helper.Contains("T2tt")) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    samplename = signalname.Data();
	    //cout << samplename << endl;
	    for(int i = 1; i<=histos["SRyield_"+samplename]->GetNbinsX();++i){
	      if(histos["SRyield_"+samplename]->Integral()>0) {
		if(histos["SRyield_"+samplename]->GetBinContent(i)>0){
		  //cout << "SRyield_" << samplename << " " << i << " " << histos["SRyield_"+samplename]->GetBinContent(i) << endl;
		  histos["StatUnc_"+samplename]->SetBinContent(i, histos["SRyield_"+samplename]->GetBinError(i)/histos["SRyield_"+samplename]->GetBinContent(i));
		}
		else histos["StatUnc_"+samplename]->SetBinContent(i, -999);
		histos["SystUnc_"+samplename]->SetBinContent(i, 0.3);
	      }
	    }
	  }
	}
      }
    } else {
      for(int i = 1; i<=histos["SRyield_"+samplename]->GetNbinsX();++i){
	if(histos["SRyield_"+samplename]->Integral()>0) {
	  if(histos["SRyield_"+samplename]->GetBinContent(i)>0){
	    histos["StatUnc_"+samplename]->SetBinContent(i, histos["SRyield_"+samplename]->GetBinError(i)/histos["SRyield_"+samplename]->GetBinContent(i));
	  }
	  else histos["StatUnc_"+samplename]->SetBinContent(i, -999);
	  histos["SystUnc_"+samplename]->SetBinContent(i, 0.3);
	}
      }
    }  
  }

  //save all relevant histograms into some rootfiles
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) continue;
    string filename = "inputfiles/"+samplename+".root";
    TFile *f = new TFile(filename.c_str(),"RECREATE");
    f->cd();
    string mapname;
    if(helper.Contains("Signal")){
      for(int t = toplow; t<=topup; t+=topstep){
	for(int c = charglow; c<=chargup; c+=chargstep){
	  if(helper.Contains("T2tt")&&c!=charglow) continue;
	  if(!helper.Contains("T2tt")&&c>t) continue;
	  for(int l = lsplow; l<=lspup; l+=lspstep){
	    if(l>t) continue;
	    if(!helper.Contains("T2tt")&&l>c) continue;
	    TString signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);//%s contains x0p5 etc
	    if(!helper.Contains("T2tt") && !helper.Contains("x") ) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    //if(helper.Contains("x")) signalname = Form("%s_%d_%d",skimFilePrefix.c_str(),t,l);
	    //else if(!helper.Contains("T2tt")) signalname = Form("%s_%d_%d_%d",skimFilePrefix.c_str(),t,c,l);
	    for(unsigned int i = 0; i<histonames.size();++i){
	      mapname = histonames[i] + "_" + signalname.Data();
	      if(storeh[i]) histos[mapname]->Write();
	    }
	  }
	}
      }
    } else {
      for(unsigned int i = 0; i<histonames.size();++i){
	mapname = histonames[i] + "_" + samplename;
	if(storeh[i]) histos[mapname]->Write();
      }
    }
    f->Close();
    cout << "Saved histos in " << f->GetName() << endl;
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
