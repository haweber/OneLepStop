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

  histonames.push_back("MT_2j");           hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("MT_4j");           hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("MT_2j_tmod0");     hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("MT_4j_tmod0");     hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("tmod_2j");         hbins.push_back(15); hlow.push_back(-15.); hup.push_back(15);
  histonames.push_back("tmod_4j");         hbins.push_back(15); hlow.push_back(-15.); hup.push_back(15);
  histonames.push_back("MDPhi_2j");        hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MDPhi_4j");        hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MDPhi_2j_tmod0");  hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("MDPhi_4j_tmod0");  hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  histonames.push_back("Mlb_2j");          hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("Mlb_4j");          hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("Mlb_2j_tmod0");    hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("Mlb_4j_tmod0");    hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);
  histonames.push_back("Mlb_tb_2j");       hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);//requires tight b for high Mlb
  histonames.push_back("Mlb_tb_4j");       hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);//requires tight b for high Mlb
  histonames.push_back("Mlb_tb_2j_tmod0"); hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);//requires tight b for high Mlb
  histonames.push_back("Mlb_tb_4j_tmod0"); hbins.push_back(16); hlow.push_back(  0.); hup.push_back(400);//requires tight b for high Mlb
  histonames.push_back("MET_2j");               hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_4j");               hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_2j_tmod0");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_4j_tmod0");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_2j_lMlb");          hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_4j_lMlb");          hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_2j_lMlb_tmod0");    hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_4j_lMlb_tmod0");    hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("MET_2j_hMlb");          hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);//requires tight b for high Mlb
  histonames.push_back("MET_4j_hMlb");          hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);//requires tight b for high Mlb
  histonames.push_back("MET_2j_hMlb_tmod0");    hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);//requires tight b for high Mlb
  histonames.push_back("MET_4j_hMlb_tmod0");    hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);//requires tight b for high Mlb
  histonames.push_back("MET_5j");         hbins.push_back(10); hlow.push_back(250.); hup.push_back(750);
  histonames.push_back("NJ");             hbins.push_back(6);  hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("NJ_compressed");  hbins.push_back(6);  hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("NJ_tmod0");       hbins.push_back(6);  hlow.push_back(  2.); hup.push_back(8);
  histonames.push_back("LepPt");          hbins.push_back(19); hlow.push_back( 25.); hup.push_back(500);
  histonames.push_back("DPhiMETLep");     hbins.push_back(16); hlow.push_back(  0.); hup.push_back(3.2);
  
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<2; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
	if(b==0) samplename = "TT2l";
	if(b==1) samplename = "TT1l";
      } else if(b==1) continue;
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      cout << mapname << endl;
    }
  }

  const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  set_goodrun_file_json(json_file);


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
      if(!is_data() && skimFilePrefix.find(string("Signal")) == string::npos) {
	int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(14));
	if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(37));
	double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
	weight = cms3.scale1fb()*36.8;
	//cout << "weight " << weight << " BSF " << BSFweight << " lepSF " << lepSFweight << endl;
	if(BSFweight>=0) weight *= BSFweight;
	if(lepSFweight>=0) weight *= lepSFweight;
      } else if(!is_data()){
	string tempsignal = skimFilePrefix;
	int mStop, mLSP;
	std::replace( tempsignal.begin(), tempsignal.end(), '_', ' ');
	sscanf(tempsignal.c_str(), "Signal %*s %i %i", &mStop, &mLSP);
	int Nevts = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,36));
	if(mStop!=(int)mass_stop()) continue;
	if(mLSP==0){
	  if((int)mass_stop()<0||(int)mass_stop()>1) continue;
	}
	else if(mLSP!=(int)mass_lsp()) continue;	
	double nevts = double(Nevts);
	double BSFweight = weight_btagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
	if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	double lepSFweight = weight_lepSF()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
	double lepFSweight = weight_lepSF_fastSim()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
	weight = xsec()*36600/nevts;
	if(BSFweight>=0) weight *= BSFweight;
	if(lepSFweight>=0) weight *= lepSFweight;
	if(lepFSweight>=0) weight *= lepFSweight;
	if(!filt_fastsimjets() )     continue;
      }
      //cout << __LINE__ << endl;
      TString currentfilename = currentFile->GetTitle();
      
      if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_25ns")) weight *= 5.77109e+06/(5.77109e+06 + 2.34556e+07);
      if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_ext1_25ns")) weight *= 2.34556e+07/(5.77109e+06 + 2.34556e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_25ns")) weight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns")) weight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns")) weight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07);
      if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns")) weight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07);
            

      if(skimFilePrefix.find(string("WJets")) != string::npos){
	if(currentfilename.Contains("nupT200")){ if(nupt()<200) continue; }
	else { if(nupt()>=200) continue; }
      }

      i1 += weight;
      if(nvtxs()<0)               continue;
      i2 += weight;
      if(ngoodleps()!=1)          continue;
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


      if(is_data()) weight = 1.;
      if(is_data()){
	//if(!(HLT_MET()||HLT_SingleEl()||HLT_SingleMu())) continue;
	if(abs(lep1_pdgid())==11){
	  //if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_SingleEl())) continue;
	  if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleEl())) continue;
	}
	if(abs(lep1_pdgid())==13){
	  //if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_SingleMu())) continue;
	  if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleMu())) continue;
	}
      }
      if( is_data() ) {
	duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
	if (is_duplicate(id) ) continue;
      }
      if(is_data()){
	  if(!filt_met()) continue;
	  if(!filt_badMuonFilter()) continue;
	  if(!filt_badChargedCandidateFilter()) continue;
	  if(!filt_jetWithBadMuon()) continue;
	  if(!filt_pfovercalomet()) continue;
	  if(filt_duplicatemuons()) continue;
	  if(filt_badmuons()) continue;
      }
      i10 += weight;
      //cout << __LINE__ << endl;

      //make histos here
      if(mindphi_met_j1_j2()>0.8){
	histos["MT_2j_" + samplename]->Fill(mt_met_lep(),weight);
	if(ngoodjets()>=4) histos["MT_4j_" + samplename]->Fill(mt_met_lep(),weight);
	if(topnessMod()>0){
	  histos["MT_2j_tmod0_" + samplename]->Fill(mt_met_lep(),weight);
	  if(ngoodjets()>=4) histos["MT_4j_tmod0_" + samplename]->Fill(mt_met_lep(),weight);
	}
      }
      if(mt_met_lep()<150)        continue;
      i11 += weight;
      histos["MDPhi_2j_" + samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(ngoodjets()>=4) histos["MDPhi_4j_" + samplename]->Fill(mindphi_met_j1_j2(),weight);
      if(topnessMod()>0){
	histos["MDPhi_2j_tmod0_" + samplename]->Fill(mindphi_met_j1_j2(),weight);
	if(ngoodjets()>=4) histos["MDPhi_4j_tmod0_" + samplename]->Fill(mindphi_met_j1_j2(),weight);
      }
      if(mindphi_met_j1_j2()<0.5) continue;
      if(lep1_p4().Pt()<150&&lep1_dphiMET()<2) histos["NJ_compressed_" + samplename]->Fill(ngoodjets(),weight);
      if(lep1_p4().Pt()<150&&ngoodjets()>=5.)  histos["DPhiMETLep_" + samplename]->Fill(lep1_dphiMET(),weight);
      if(lep1_dphiMET()<2.0&&ngoodjets()>=5.)  histos["LepPt_" + samplename]->Fill(lep1_p4().Pt(),weight);
      if(lep1_p4().Pt()<150&&lep1_dphiMET()<2.0&&ngoodjets()>=5.)  histos["MET_5j_" + samplename]->Fill(pfmet(),weight);
      if(mindphi_met_j1_j2()<0.8) continue;
      i12 += weight;
      histos["NJ_" + samplename]->Fill(ngoodjets(),weight);
      if(topnessMod()>0) histos["NJ_tmod0_" + samplename]->Fill(ngoodjets(),weight);
      histos["tmod_2j_" + samplename]->Fill(topnessMod(),weight);
      if(ngoodjets()>=4) histos["tmod_4j_" + samplename]->Fill(topnessMod(),weight);
      histos["Mlb_2j_" + samplename]->Fill(Mlb_closestb(),weight);
      if(ngoodjets()>=4) histos["Mlb_4j_" + samplename]->Fill(Mlb_closestb(),weight);
      if(topnessMod()>0){
	histos["Mlb_2j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
	if(ngoodjets()>=4) histos["Mlb_4j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
      }
      if(Mlb_closestb()<175){
	histos["Mlb_tb_2j_" + samplename]->Fill(Mlb_closestb(),weight);
	if(ngoodjets()>=4) histos["Mlb_tb_4j_" + samplename]->Fill(Mlb_closestb(),weight);
	if(topnessMod()>0){
	  histos["Mlb_tb_2j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
	  if(ngoodjets()>=4) histos["Mlb_tb_4j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
	}
      } else if(ntightbtags()>=1){
	histos["Mlb_tb_2j_" + samplename]->Fill(Mlb_closestb(),weight);
	if(ngoodjets()>=4) histos["Mlb_tb_4j_" + samplename]->Fill(Mlb_closestb(),weight);
	if(topnessMod()>0){
	  histos["Mlb_tb_2j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
	  if(ngoodjets()>=4) histos["Mlb_tb_4j_tmod0_" + samplename]->Fill(Mlb_closestb(),weight);
	}
      }
      histos["MET_2j_" + samplename]->Fill(pfmet(),weight);
      if(ngoodjets()>=4) histos["MET_4j_" + samplename]->Fill(pfmet(),weight);
      if(topnessMod()>0){
	histos["MET_2j_tmod0_" + samplename]->Fill(pfmet(),weight);
	if(ngoodjets()>=4) histos["MET_4j_tmod0_" + samplename]->Fill(pfmet(),weight);
      }
      if(Mlb_closestb()<175){
	histos["MET_2j_lMlb_" + samplename]->Fill(pfmet(),weight);
	if(ngoodjets()>=4) histos["MET_4j_lMlb_" + samplename]->Fill(pfmet(),weight);
	if(topnessMod()>0){
	  histos["MET_2j_lMlb_tmod0_" + samplename]->Fill(pfmet(),weight);
	  if(ngoodjets()>=4) histos["MET_4j_lMlb_tmod0_" + samplename]->Fill(pfmet(),weight);
	}
      } else if(ntightbtags()>=1){
	histos["MET_2j_hMlb_" + samplename]->Fill(pfmet(),weight);
	if(ngoodjets()>=4) histos["MET_4j_hMlb_" + samplename]->Fill(pfmet(),weight);
	if(topnessMod()>0){
	  histos["MET_2j_hMlb_tmod0_" + samplename]->Fill(pfmet(),weight);
	  if(ngoodjets()>=4) histos["MET_4j_hMlb_tmod0_" + samplename]->Fill(pfmet(),weight);
	}
      }
      i13 += weight;
      
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
  
  string filename = "rootfiles/PublicPlotHistos_reminiAOD.root";
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

  cout <<  i1 << "  " <<  i2 << "  " <<  i3 << "  " <<  i4 << "  " <<  i5 << "  " <<  i6 << "  " <<  i7 << "  " <<  i8 << "  " <<  i9 << "  " <<  i10 << "  " <<  i11 << "  " <<  i12 << "  " <<  i13 << "  " << endl;
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
