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
#include "TH3D.h"
#include "TH2F.h"

// CMS3
#include "CMS3_Jan17.cc"

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  //float sumB=0; float suml=0; float sumL=0; float sumN=0; float sumW = 0; float sumR = 0;
  bool isT2tt = false;
  bool isT2bW = false;
  bool isT2tb = false;
  string testerT2 = "T2tt";
  if (skimFilePrefix.find(testerT2) != std::string::npos) isT2tt = true;
  testerT2 = "T2tb";
  if (skimFilePrefix.find(testerT2) != std::string::npos) isT2tb = true;
  testerT2 = "T2bW";
  if (skimFilePrefix.find(testerT2) != std::string::npos) isT2bW = true;
  if(!(isT2tt||isT2tb||isT2bW)) { cout << "I couldn't find what scan you are running - sample is " << skimFilePrefix << " existing" << endl; return 0;}
  cout << "isT2tt " << isT2tt << " isT2bW " << " isT2tb " << isT2tb << endl;

  
  //load PUweights
  
  TFile *fPU = new TFile("rootfiles/puWeights_2016data_36p6fbinv.root","READ");
  TH1D *puWeight     = (TH1D*)fPU->Get("puWeight");
  TH1D *puWeightUp   = (TH1D*)fPU->Get("puWeightUp");
  TH1D *puWeightDown = (TH1D*)fPU->Get("puWeightDown");
  
  TFile *fxsec = new TFile("/home/users/haweber/StopAnalysis/SignalAnalysisCode/xsec_stop_13TeV.root","READ");
  TH1D *hxsec     = (TH1D*)fxsec->Get("stop");
  
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH3D*> histos;//use D histos as weights can vary a lot among the signal
  vector<string> histonames; histonames.clear();
  map<string, TH3D*> histos2;//use D histos as weights can vary a lot among the signal
  vector<string> histonames2; histonames2.clear();
  //  vector<int> hbins; hbins.clear();
  //  vector<float> hlow; hlow.clear();
  //  vector<float> hup; hup.clear();

  //lumi, trigger, stats done
  histonames.push_back("SRyield");
  histonames.push_back("SRyield_gen");
  histonames.push_back("SR_Bup_HF");
  histonames.push_back("SR_Bdown_HF");
  histonames.push_back("SR_Bup_LF");
  histonames.push_back("SR_Bdown_LF");
  histonames.push_back("SR_Bup_FS");
  histonames.push_back("SR_Bdown_FS");
  histonames.push_back("SR_JESup");
  histonames.push_back("SR_JESdown");
  histonames.push_back("SR_muRFup");
  histonames.push_back("SR_muRFdown");
  histonames.push_back("SR_ISRup");
  histonames.push_back("SR_ISRdown");
  histonames.push_back("SR_PUup");
  histonames.push_back("SR_PUdown");
  histonames.push_back("SR_LepEffup");
  histonames.push_back("SR_LepEffdown");
  histonames.push_back("SR_LepEffFSup");
  histonames.push_back("SR_LepEffFSdown");
  histonames.push_back("SR_Xsecup");
  histonames.push_back("SR_Xsecdown");
  histonames.push_back("CR1l_sigcontamination");
  histonames.push_back("CR2l_sigcontamination");
  histonames.push_back("CR1l_sigcontamination_gen");
  histonames.push_back("CR2l_sigcontamination_gen");
  
  histonames2.push_back("eventsum");
  histonames2.push_back("rawweightsum");
  histonames2.push_back("totweightsum");
  histonames2.push_back("ISRsum");
  histonames2.push_back("BSFsum");
  histonames2.push_back("PUweightsum");
  histonames2.push_back("xsecsum");
  histonames2.push_back("nevtsum");
  histonames2.push_back("lepsum");
  histonames2.push_back("lepSFsum");
  
  vector<string> postfix;
  if(isT2bW) postfix.push_back("");
  if(isT2tb) { postfix.push_back("_tLSP"); postfix.push_back("_bCharg"); postfix.push_back("_mixed"); }
  if(isT2tt) { postfix.push_back(""); postfix.push_back("_polL"); postfix.push_back("_polR"); }

  for(unsigned int b = 0; b<postfix.size(); ++b){
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname = histonames[i] + postfix[b];
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH3D(mapname.c_str(), "", 61,-12.5,1512.5, 41,-12.5,1012.5, 27, 0.5,27.5);
      //mStop 100-1000, mLSP 0-450, SR 1-12, 9200 bins, SR 0 is non-SR - in case it it needed!!
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      mapname = "c" + histonames[i] + postfix[b];
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH3D(mapname.c_str(), "", 61,-12.5,1512.5, 41,-12.5,1012.5, 4, 0.5,4.5);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }
    for(unsigned int i = 0; i<histonames2.size(); ++i){
      string mapname = histonames2[i] + postfix[b];
      if(histos2.count(mapname) == 0 ) histos2[mapname] = new TH3D(mapname.c_str(), "", 45,99,1224, 27,-1,674, 15, 0.5,15.5);
      //mStop 100-1000, mLSP 0-450, SR 1-12, 9200 bins, SR 0 is non-SR - in case it it needed!!
      histos2[mapname]->Sumw2(); histos2[mapname]->SetDirectory(rootdir);
    }
  }
  
  
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  TH3D* counterhistSig;
  TH2F* histNEvts;
  bool thisisfirst = true;
  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    if(thisisfirst){
      file->cd();
      counterhistSig = (TH3D*)file->Get("h_counterSMS");
      counterhistSig->SetDirectory(0); 
      histNEvts = (TH2F*)file->Get("histNEvts");
      histNEvts->SetDirectory(0);
      thisisfirst = false;
    }
    file->cd();
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

      float mStop = mass_stop();
      float mLSP = mass_lsp();
      float mCharg = mass_chargino();
      //float xVal = mass_lsp();
      int Nevts = histNEvts->GetBinContent(histNEvts->FindBin(mStop,mLSP));
      Nevts = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,36));//i got lucky
      double nevts = double(Nevts);
      //float weight = cms3.scale1fb()*2.11;
      double PUweight     = puWeight    ->GetBinContent(puWeight    ->FindBin(pu_ntrue() ) );
      double PUweightUp   = puWeightUp  ->GetBinContent(puWeightUp  ->FindBin(pu_ntrue() ) );
      double PUweightDown = puWeightDown->GetBinContent(puWeightDown->FindBin(pu_ntrue() ) );
      //PUweightUp = 1; PUweightDown = PUweight; PUweight = 1; //now PU syst is applying vs not applying
      double ISRnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,24));
      double ISRnormup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,25));
      double ISRnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,26));
      double ISRweight = weight_ISRnjets();//updated
      double BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      double BSFnormHup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,15));
      double BSFnormLup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,16));
      double BSFnormHdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,17));
      double BSFnormLdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,18));
      double BSFnormFSup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,22));//new
      double BSFnormFSdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,23));//new
      double BSFweight = weight_btagsf();
      double muRFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,1));
      double muRFnormup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,5));
      double muRFnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,9));
      double lepSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
      double lepSFnormup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,28));
      double lepSFnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,29));
      double lepFSSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
      double lepFSSFnormup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,34));
      double lepFSSFnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,35));
      double lepSFweight = weight_lepSF();
      double lepFSSFweight = weight_lepSF_fastSim();
      if(lepFSSFweight<0) cout << "WTF lepFSSFweight " << lepFSSFweight << endl;
      if(ISRnorm>0) ISRweight*=nevts/ISRnorm;
      if(ISRnorm<=0||ISRnormup<=0||ISRnormdown<=0){ ISRnormdown=1.; ISRnormup=1.; ISRnorm=1.;}
      if(BSFnorm>0) BSFweight *=nevts/BSFnorm;
      if(BSFnorm<=0||BSFnormHup<=0||BSFnormLup<=0||BSFnormHdown<=0||BSFnormLdown<=0){ BSFnorm=1; BSFnormHup=1; BSFnormLup=1; BSFnormHdown=1; BSFnormLdown=1; }
      if(muRFnorm<=0||muRFnormup<=0||muRFnormdown<=0){ muRFnormdown=1; muRFnormup=1; muRFnorm=1; }
      if(lepSFnorm>0) lepSFweight *= nevts/lepSFnorm;
      if(lepFSSFnorm>0) lepFSSFweight *= nevts/lepFSSFnorm;
      if(lepSFnorm<=0||lepSFnormup<=0||lepSFnormdown<=0){lepSFnorm=1; lepSFnormup=1; lepSFnormdown=1;}
      if(lepFSSFnorm<=0||lepFSSFnormup<=0||lepFSSFnormdown<=0){lepFSSFnorm=1; lepFSSFnormup=1; lepFSSFnormdown=1;}
      //lepSF is done below
      double xsection = hxsec->GetBinContent(hxsec->FindBin(mStop));
      double xsectionerr = hxsec->GetBinError(hxsec->FindBin(mStop));
     double mylumi = 36600.;
      double rawweight = xsection*mylumi/nevts;
      double weight = xsection*mylumi/nevts*PUweight*ISRweight*BSFweight*lepSFweight*lepFSSFweight;//xsec given in pb
      //if(nEventsTotal%1000==0) cout << "mstop " << mStop << " " <<xsection << " " << weight << " " << nevts << " " << counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,36)) << endl;
      //did put ISRweight which should be ==1
      //if(ISRweight!=1) cout << "ISRw " << ISRweight << endl;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;
      
      
      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)           continue;//accomodate 2l-CR
      if(nvetoleps()<1)           continue;//accomodate 2l-CR
    //if(!PassTrackVeto())     continue;//accomodate 2l-CR
    //if(!PassTauVeto())          continue;//accomodate 2l-CR
      //if(ngoodjets()<2)           continue;
      //if(ngoodbtags()<0)          continue;//accomodate 1l-CR
      //if(pfmet()<250)             continue;
      //if(mt_met_lep()<150)        continue;
      //if(mindphi_met_j1_j2()<0.5) continue;
      if(!filt_fastsimjets() )    continue;//THIS IS SO ON NEW BABIES
      //if(filt_fastsimjets() )     continue;//this is on old babies
      //remove all above for JES up/down

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
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150){
	if(     pfmet()>550) cSR = 4;
	else if(pfmet()>450) cSR = 3;
	else if(pfmet()>350) cSR = 2;
	else if(pfmet()>250) cSR = 1;
      }
      int SRu = -1; int cSRu = -1;
      int SRd = -1; int cSRd = -1;
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jup_ngoodbtags()>=1&&mindphi_met_j1_j2_jup()>0.8&&pfmet_jup()>=250&&mt_met_lep_jup()>150) { //basis for SR 1l, >=1b
	if(jup_ngoodjets()>=2&&jup_ngoodjets()<=3&&topnessMod_jup()>10.){
	  if(Mlb_closestb_jup()<=175){
	    if(     pfmet_jup()>600) SRu = 4;
	    else if(pfmet_jup()>450) SRu = 3;
	    else if(pfmet_jup()>350) SRu = 2;
	    else if(pfmet_jup()>250) SRu = 1;
	  } else if(jup_ntightbtags()>=1&&Mlb_closestb_jup()>175.) {
	    if(     pfmet_jup()>600) SRu = 7;
	    else if(pfmet_jup()>450) SRu = 6;
	    else if(pfmet_jup()>250) SRu = 5;
	  }
	} else if(jup_ngoodjets()>=4&&topnessMod_jup()<=0.){
	  if(Mlb_closestb_jup()<=175){
	    if(     pfmet_jup()>650) SRu = 12;
	    else if(pfmet_jup()>550) SRu = 11;
	    else if(pfmet_jup()>450) SRu = 10;
	    else if(pfmet_jup()>350) SRu = 9;
	    else if(pfmet_jup()>250) SRu = 8;
	  } else if(jup_ntightbtags()>=1&&Mlb_closestb_jup()>175.) {
	    if(     pfmet_jup()>550) SRu = 16;
	    else if(pfmet_jup()>450) SRu = 15;
	    else if(pfmet_jup()>350) SRu = 14;
	    else if(pfmet_jup()>250) SRu = 13;
	  }
	} else if(jup_ngoodjets()>=4&&topnessMod_jup()>0.&&topnessMod_jup()<=10.){
	  if(Mlb_closestb_jup()<=175){
	    if(     pfmet_jup()>550) SRu = 19;
	    else if(pfmet_jup()>350) SRu = 18;
	    else if(pfmet_jup()>250) SRu = 17;
	  } else if(jup_ntightbtags()>=1&&Mlb_closestb_jup()>175.) {
	    if(     pfmet_jup()>450) SRu = 21;
	    else if(pfmet_jup()>250) SRu = 20;
	  }
	} else if(jup_ngoodjets()>=4&&topnessMod_jup()>10.){
	  if(Mlb_closestb_jup()<=175){
	    if(     pfmet_jup()>600) SRu = 25;
	    else if(pfmet_jup()>450) SRu = 24;
	    else if(pfmet_jup()>350) SRu = 23;
	    else if(pfmet_jup()>250) SRu = 22;
	  } else if(jup_ntightbtags()>=1&&Mlb_closestb_jup()>175.){
	    if(     pfmet_jup()>450) SRu = 27;
	    else if(pfmet_jup()>250) SRu = 26;
	  }
	}
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jup_ngoodbtags()>=1&&jup_ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_jup()<2.0&&mindphi_met_j1_j2_jup()>0.5&&pfmet_jup()>=250&&mt_met_lep_jup()>150){
	if(     pfmet_jup()>550) cSRu = 4;
	else if(pfmet_jup()>450) cSRu = 3;
	else if(pfmet_jup()>350) cSRu = 2;
	else if(pfmet_jup()>250) cSRu = 1;
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jdown_ngoodbtags()>=1&&mindphi_met_j1_j2_jdown()>0.8&&pfmet_jdown()>=250&&mt_met_lep_jdown()>150) { //basis for SR 1l, >=1b
	if(jdown_ngoodjets()>=2&&jdown_ngoodjets()<=3&&topnessMod_jdown()>10.){
	  if(Mlb_closestb_jdown()<=175){
	    if(     pfmet_jdown()>600) SRd = 4;
	    else if(pfmet_jdown()>450) SRd = 3;
	    else if(pfmet_jdown()>350) SRd = 2;
	    else if(pfmet_jdown()>250) SRd = 1;
	  } else if(jdown_ntightbtags()>=1&&Mlb_closestb_jdown()>175.) {
	    if(     pfmet_jdown()>600) SRd = 7;
	    else if(pfmet_jdown()>450) SRd = 6;
	    else if(pfmet_jdown()>250) SRd = 5;
	  }
	} else if(jdown_ngoodjets()>=4&&topnessMod_jdown()<=0.){
	  if(Mlb_closestb_jdown()<=175){
	    if(     pfmet_jdown()>650) SRd = 12;
	    else if(pfmet_jdown()>550) SRd = 11;
	    else if(pfmet_jdown()>450) SRd = 10;
	    else if(pfmet_jdown()>350) SRd = 9;
	    else if(pfmet_jdown()>250) SRd = 8;
	  } else if(jdown_ntightbtags()>=1&&Mlb_closestb_jdown()>175.) {
	    if(     pfmet_jdown()>550) SRd = 16;
	    else if(pfmet_jdown()>450) SRd = 15;
	    else if(pfmet_jdown()>350) SRd = 14;
	    else if(pfmet_jdown()>250) SRd = 13;
	  }
	} else if(jdown_ngoodjets()>=4&&topnessMod_jdown()>0.&&topnessMod_jdown()<=10.){
	  if(Mlb_closestb_jdown()<=175){
	    if(     pfmet_jdown()>550) SRd = 19;
	    else if(pfmet_jdown()>350) SRd = 18;
	    else if(pfmet_jdown()>250) SRd = 17;
	  } else if(jdown_ntightbtags()>=1&&Mlb_closestb_jdown()>175.) {
	    if(     pfmet_jdown()>450) SRd = 21;
	    else if(pfmet_jdown()>250) SRd = 20;
	  }
	} else if(jdown_ngoodjets()>=4&&topnessMod_jdown()>10.){
	  if(Mlb_closestb_jdown()<=175){
	    if(     pfmet_jdown()>600) SRd = 25;
	    else if(pfmet_jdown()>450) SRd = 24;
	    else if(pfmet_jdown()>350) SRd = 23;
	    else if(pfmet_jdown()>250) SRd = 22;
	  } else if(jdown_ntightbtags()>=1&&Mlb_closestb_jdown()>175.){
	    if(     pfmet_jdown()>450) SRd = 27;
	    else if(pfmet_jdown()>250) SRd = 26;
	  }
	}
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jdown_ngoodbtags()>=1&&jdown_ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_jdown()<2.0&&mindphi_met_j1_j2_jdown()>0.5&&pfmet_jdown()>=250&&mt_met_lep_jdown()>150){
	if(     pfmet_jdown()>550) cSRd = 4;
	else if(pfmet_jdown()>450) cSRd = 3;
	else if(pfmet_jdown()>350) cSRd = 2;
	else if(pfmet_jdown()>250) cSRd = 1;
      }
      
      //CR-1l
      int CR1l = -1;
      int cCR1l = -1;
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ntightbtags()==0&&mindphi_met_j1_j2()>0.8&&pfmet()>=250&&mt_met_lep()>150) { //basis for SR 1l, >=1b
	if(ngoodjets()>=2&&ngoodjets()<=3&&topnessMod()>10.){
	  if(Mlb_lead_bdiscr()<=175&&ngoodbtags()==0){
	    if(     pfmet()>600) CR1l = 4;
	    else if(pfmet()>450) CR1l = 3;
	    else if(pfmet()>350) CR1l = 2;
	    else if(pfmet()>250) CR1l = 1;
	  } else if(ntightbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    if(     pfmet()>600) CR1l = 7;
	    else if(pfmet()>450) CR1l = 6;
	    else if(pfmet()>250) CR1l = 5;
	  }
	} else if(ngoodjets()>=4&&topnessMod()<=0.){
	  if(Mlb_lead_bdiscr()<=175&&ngoodbtags()==0){
	    if(     pfmet()>650) CR1l = 12;
	    else if(pfmet()>550) CR1l = 11;
	    else if(pfmet()>450) CR1l = 10;
	    else if(pfmet()>350) CR1l = 9;
	    else if(pfmet()>250) CR1l = 8;
	  } else if(ngoodbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    if(     pfmet()>550) CR1l = 16;
	    else if(pfmet()>450) CR1l = 15;
	    else if(pfmet()>350) CR1l = 14;
	    else if(pfmet()>250) CR1l = 13;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>0.&&topnessMod()<=10.){
	  if(Mlb_lead_bdiscr()<=175&&ngoodbtags()==0){
	    if(     pfmet()>550) CR1l = 19;
	    else if(pfmet()>350) CR1l = 18;
	    else if(pfmet()>250) CR1l = 17;
	  } else if(ngoodbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    if(     pfmet()>450) CR1l = 21;
	    else if(pfmet()>250) CR1l = 20;
	  }
	} else if(ngoodjets()>=4&&topnessMod()>10.){
	  if(Mlb_lead_bdiscr()<=175&&ngoodbtags()==0){
	    if(     pfmet()>600) CR1l = 25;
	    else if(pfmet()>450) CR1l = 24;
	    else if(pfmet()>350) CR1l = 23;
	    else if(pfmet()>250) CR1l = 22;
	  } else if(ntightbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    if(     pfmet()>450) CR1l = 27;
	    else if(pfmet()>250) CR1l = 26;
	  }
	}
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()==0&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150){
	if(     pfmet()>550) cCR1l = 4;
	else if(pfmet()>450) cCR1l = 3;
	else if(pfmet()>350) cCR1l = 2;
	else if(pfmet()>250) cCR1l = 1;
      }

      float SF_CR1l = 1.0;
      float SF_cCR1l = 1.0;
      if(CR1l== 1) SF_CR1l = 0.1199;
      if(CR1l== 2) SF_CR1l = 0.1065;
      if(CR1l== 3) SF_CR1l = 0.1111;
      if(CR1l== 4) SF_CR1l = 0.0664;
      if(CR1l== 5) SF_CR1l = 0.0375;
      if(CR1l== 6) SF_CR1l = 0.0494;
      if(CR1l== 7) SF_CR1l = 0.0430;
      if(CR1l== 8) SF_CR1l = 0.2275;
      if(CR1l== 9) SF_CR1l = 0.2070;
      if(CR1l==10) SF_CR1l = 0.2476;
      if(CR1l==11) SF_CR1l = 0.2521;
      if(CR1l==12) SF_CR1l = 0.2487;
      if(CR1l==13) SF_CR1l = 0.1729;
      if(CR1l==14) SF_CR1l = 0.1443;
      if(CR1l==15) SF_CR1l = 0.1038;
      if(CR1l==16) SF_CR1l = 0.0885;
      if(CR1l==17) SF_CR1l = 0.2573;
      if(CR1l==18) SF_CR1l = 0.1860;
      if(CR1l==19) SF_CR1l = 0.1647;
      if(CR1l==20) SF_CR1l = 0.1205;
      if(CR1l==21) SF_CR1l = 0.1039;
      if(CR1l==22) SF_CR1l = 0.2737;
      if(CR1l==23) SF_CR1l = 0.4228;
      if(CR1l==24) SF_CR1l = 0.3089;
      if(CR1l==25) SF_CR1l = 0.1037;
      if(CR1l==26) SF_CR1l = 0.1041;
      if(CR1l==27) SF_CR1l = 0.1012;
      if(cCR1l==1) SF_cCR1l = 0.141;
      if(cCR1l==2) SF_cCR1l = 0.144;
      if(cCR1l==3) SF_cCR1l = 0.167;
      if(cCR1l==4) SF_cCR1l = 0.127;
      
      //CR2l = -1;
      int lepind = -1;
      if(ngoodleps()>2) lepind = 5;
      else if(ngoodleps()==2) lepind = 4;//exactly two leptons,CR4
      else if(ngoodleps()==1&&nvetoleps()>=2&&lep2_p4().Pt()>=10) lepind = 3;//one lepton, but more than 1 add. loose,1l,>2l
      else if(ngoodleps()==1&&nvetoleps()==1&&(!PassTrackVeto()||!PassTauVeto())) lepind = 1;//exactly one lepton, but do not pass track/tau veto - i.e. one additional track or tau, CR6
      //CHECK with John about CR definition
      int CR2l = -1;
      int cCR2l = -1;
      if(lepind>=3&&ngoodbtags()>=1&&mindphi_met_j1_j2_rl()>0.8&&pfmet_rl()>=250&&mt_met_lep_rl()>150) { //basis for SR 1l, >=1b
	if(ngoodjets()>=2&&ngoodjets()<=3&&topnessMod_rl()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet_rl()>600) CR2l = 4;
	    else if(pfmet_rl()>450) CR2l = 3;
	    else if(pfmet_rl()>350) CR2l = 2;
	    else if(pfmet_rl()>250) CR2l = 1;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet_rl()>600) CR2l = 5;
	    else if(pfmet_rl()>450) CR2l = 5;
	    else if(pfmet_rl()>250) CR2l = 5;
	  }
	} else if(ngoodjets()>=4&&topnessMod_rl()<=0.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet_rl()>650) CR2l = 12;
	    else if(pfmet_rl()>550) CR2l = 11;
	    else if(pfmet_rl()>450) CR2l = 10;
	    else if(pfmet_rl()>350) CR2l = 9;
	    else if(pfmet_rl()>250) CR2l = 8;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet_rl()>550) CR2l = 16;
	    else if(pfmet_rl()>450) CR2l = 15;
	    else if(pfmet_rl()>350) CR2l = 14;
	    else if(pfmet_rl()>250) CR2l = 13;
	  }
	} else if(ngoodjets()>=4&&topnessMod_rl()>0.&&topnessMod_rl()<=10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet_rl()>550) CR2l = 18;
	    else if(pfmet_rl()>350) CR2l = 18;
	    else if(pfmet_rl()>250) CR2l = 17;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet_rl()>450) CR2l = 20;
	    else if(pfmet_rl()>250) CR2l = 20;
	  }
	} else if(ngoodjets()>=4&&topnessMod_rl()>10.){
	  if(Mlb_closestb()<=175){
	    if(     pfmet_rl()>600) CR2l = 25;
	    else if(pfmet_rl()>450) CR2l = 24;
	    else if(pfmet_rl()>350) CR2l = 23;
	    else if(pfmet_rl()>250) CR2l = 22;
	  } else if(ntightbtags()>=1&&Mlb_closestb()>175.) {
	    if(     pfmet_rl()>450) CR2l = 26;
	    else if(pfmet_rl()>250) CR2l = 26;
	  }
	}
      }
      if(lepind>=3&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_rl()<2.0&&mindphi_met_j1_j2_rl()>0.5&&pfmet_rl()>=250&&mt_met_lep_rl()>150){
	if(     pfmet_rl()>550) cCR2l = 4;
	else if(pfmet_rl()>450) cCR2l = 3;
	else if(pfmet_rl()>350) cCR2l = 2;
	else if(pfmet_rl()>250) cCR2l = 1;
      }

      float SF_CR2l = 1.;
      float SF_cCR2l = 1.;
      float SF_CR2l_2 = 1.;
      float SF_CR2l_3 = 1.;
      int hCR2 = -1;
      int hCR3 = -1;
      if(CR2l== 1) SF_CR2l = 0.23;
      if(CR2l== 2) SF_CR2l = 0.19;
      if(CR2l== 3) SF_CR2l = 0.15;
      if(CR2l== 4) SF_CR2l = 0.08;
      if(CR2l== 5) SF_CR2l = 0.13*0.92;
      if(CR2l== 5) { SF_CR2l_2 = 0.13*0.01; hCR2 = 6; }
      if(CR2l== 5) { SF_CR2l_3 = 0.13*0.07; hCR3 = 7; }
      if(CR2l== 8) SF_CR2l = 0.50;
      if(CR2l== 9) SF_CR2l = 0.41;
      if(CR2l==10) SF_CR2l = 0.37;
      if(CR2l==11) SF_CR2l = 0.40;
      if(CR2l==12) SF_CR2l = 0.49;
      if(CR2l==13) SF_CR2l = 0.37;
      if(CR2l==14) SF_CR2l = 0.39;
      if(CR2l==15) SF_CR2l = 0.47;
      if(CR2l==16) SF_CR2l = 0.45;
      if(CR2l==17) SF_CR2l = 0.37;
      if(CR2l==18) SF_CR2l = 0.33*0.98;
      if(CR2l==18) { SF_CR2l_2 = 0.33*0.02; hCR2 = 19; }
      if(CR2l==20) SF_CR2l = 0.19*0.99;
      if(CR2l==20) { SF_CR2l_2 = 0.19*0.01; hCR2 = 21; }
      if(CR2l==22) SF_CR2l = 0.28;
      if(CR2l==23) SF_CR2l = 0.26;
      if(CR2l==24) SF_CR2l = 0.19;
      if(CR2l==25) SF_CR2l = 0.36;
      if(CR2l==26) SF_CR2l = 0.07*0.74;
      if(CR2l==26) { SF_CR2l_2 = 0.07*26; hCR2 = 27; }
      if(cCR2l==1) SF_cCR2l = 0.655;
      if(cCR2l==2) SF_cCR2l = 0.454;
      if(cCR2l==3) SF_cCR2l = 0.614;
      if(cCR2l==4) SF_cCR2l = 0.460;

      if(SR==(-1)&&CR1l==(-1)&&CR2l==(-1)&&SRu==(-1)&&SRd==(-1)&&cSR==(-1)&&cCR1l==(-1)&&cCR2l==(-1)&&cSRu==(-1)&&cSRd==(-1)) continue;
      
      int T2tb_BRselection = -1;
      if(isT2tb){
	int tLSP = 0;
	int bCharg = 0;
	for(unsigned int i = 0; i<gensusy_id().size(); ++i){
	  if(abs(gensusy_id()[i])!=1000022) continue;
	  if(gensusy_status()[i]!=1) continue;
	  if(abs(gensusy_motherid()[i])==1000024) ++bCharg;
	  if(abs(gensusy_motherid()[i])==1000006) ++tLSP;
	}
	if((tLSP+bCharg)!=2) cout << "This should not happen, have " << tLSP << " stop decays to tLSP, and " << bCharg << " stop decays to bChargino" << endl;
	if(tLSP==2) T2tb_BRselection = 1;
	if(tLSP==1&&bCharg==1) T2tb_BRselection = 2;
	if(bCharg==2) T2tb_BRselection = 3;
      }
      string T2tbhelper = "";
      if(T2tb_BRselection==1) T2tbhelper = "_tLSP";
      if(T2tb_BRselection==2) T2tbhelper = "_mixed";
      if(T2tb_BRselection==3) T2tbhelper = "_bCharg";
 
      //add here polarization weights
      double weight_pol_L(1), weight_pol_R(1);
      if(isT2tt){
	if(mStop-mLSP>=170){
	  LorentzVector tl1, tl2;
	  //LorentzVector tW1, tW2;
	  LorentzVector tt1, tt2;
	  LorentzVector tst1, tst2;
	  for(unsigned int i = 0; i<gensusy_id().size(); ++i){
	    if(gensusy_status()[i]!=1) continue;
	    if((gensusy_id()[i])==1000022&&(gensusy_motherid()[i])==1000006) {  tst1 = gensusy_motherp4()[i]; }//mother of LSP - safer
	    if((gensusy_id()[i])==1000022&&(gensusy_motherid()[i])==-1000006) { tst2 = gensusy_motherp4()[i]; }
	  }
	  for(unsigned int i = 0; i<genleps_id().size(); ++i){
	    if(genleps_status()[i] != 23 && genleps_status()[i] != 22 && genleps_status()[i] != 1) continue;
	    if(abs(genleps_motherid()[i])!=24) continue;
	    if((genleps_gmotherid()[i])==6&&genleps_gmotherid()[i]*genleps_id()[i]<0) { tt1 = genleps_gmotherp4()[i]; tl1 = genleps_p4()[i]; }
	    if((genleps_gmotherid()[i])==-6&&genleps_gmotherid()[i]*genleps_id()[i]<0) { tt2 = genleps_gmotherp4()[i]; tl2 = genleps_p4()[i]; }
	  }
	  for(unsigned int i = 0; i<gennus_id().size(); ++i){
	    if(gennus_status()[i] != 23 && gennus_status()[i] != 22 && gennus_status()[i] != 1) continue;
	    if(abs(gennus_motherid()[i])!=24) continue;
	    if((gennus_gmotherid()[i])==6&&gennus_gmotherid()[i]*gennus_id()[i]<0) { tt1 = gennus_gmotherp4()[i]; tl1 = gennus_p4()[i]; }
	    if((gennus_gmotherid()[i])==-6&&gennus_gmotherid()[i]*gennus_id()[i]<0) { tt2 = gennus_gmotherp4()[i]; tl2 = gennus_p4()[i]; }

	  }
	  for(unsigned int i = 0; i<genqs_id().size(); ++i){
	    if(genqs_status()[i] != 23 && genqs_status()[i] != 22 && genqs_status()[i] != 1) continue;
	    if(abs(genqs_motherid()[i])!=24) continue;
	    if((genqs_gmotherid()[i])==6&&genqs_gmotherid()[i]*genqs_id()[i]<0) { tt1 = genqs_gmotherp4()[i]; tl1 = genqs_p4()[i]; }
	    if((genqs_gmotherid()[i])==-6&&genqs_gmotherid()[i]*genqs_id()[i]<0) { tt2 = genqs_gmotherp4()[i]; tl2 = genqs_p4()[i]; }
	  }

	  TLorentzVector st1; st1.SetPxPyPzE(tst1.Px(),tst1.Py(),tst1.Pz(),tst1.E());
	  TLorentzVector st2; st2.SetPxPyPzE(tst2.Px(),tst2.Py(),tst2.Pz(),tst2.E());
	  TVector3 bV1(-st1.Px()/st1.Energy(),-st1.Py()/st1.Energy(),-st1.Pz()/st1.Energy());
	  TVector3 bV2(-st2.Px()/st2.Energy(),-st2.Py()/st2.Energy(),-st2.Pz()/st2.Energy());
	  TLorentzVector t1; t1.SetPxPyPzE(tt1.Px(),tt1.Py(),tt1.Pz(),tt1.E());
	  TLorentzVector t2; t2.SetPxPyPzE(tt2.Px(),tt2.Py(),tt2.Pz(),tt2.E());
	  TLorentzVector l1; l1.SetPxPyPzE(tl1.Px(),tl1.Py(),tl1.Pz(),tl1.E());
	  TLorentzVector l2; l2.SetPxPyPzE(tl2.Px(),tl2.Py(),tl2.Pz(),tl2.E());
	  t1.Boost(bV1);
	  t2.Boost(bV2);
	  l1.Boost(bV1);
	  l2.Boost(bV2);
	  if(t1.P()>0&&l1.P()>0){
	    double costh = (t1.Px()*l1.Px()+t1.Py()*l1.Py()+t1.Pz()*l1.Pz())/t1.P()/l1.P();
	    double weight_L = (t1.Energy()+t1.P())*(1-costh);
	    double weight_R = (t1.Energy()-t1.P())*(1+costh);
	    weight_pol_L *= 2*weight_L/(weight_R+weight_L);
	    weight_pol_R *= 2*weight_R/(weight_R+weight_L);
	  }
	  if(t2.P()>0&&l2.P()>0){
	    double costh = (t2.Px()*l2.Px()+t2.Py()*l2.Py()+t2.Pz()*l2.Pz())/t2.P()/l2.P();
	    double weight_L = (t2.Energy()+t2.P())*(1-costh);
	    double weight_R = (t2.Energy()-t2.P())*(1+costh);
	    weight_pol_L *= 2*weight_L/(weight_R+weight_L);
	    weight_pol_R *= 2*weight_R/(weight_R+weight_L);
	  }
	}
      }
	      
      //implement some sanity checks
      //if(CR1l!=(-1)&&CR2l!=(-1)) cout << "WTF CR1l " << CR1l << " CR2l " << CR2l << endl;
      //if(SR!=(-1)&&CR1l!=(-1)) cout << "WTF SR " << SR << " CR1l " << CR1l << endl;
      //if(SR!=(-1)&&CR2l!=(-1)) cout << "WTF SR " << SR << " CR2l " << CR2l << endl;

      //ISR reweighting, get stop pair using last copy:
      double ISRup = weight_ISRnjets_UP()/weight_ISRnjets()*ISRnorm/ISRnormup;
      double ISRdown = weight_ISRnjets_DN()/weight_ISRnjets()*ISRnorm/ISRnormdown;
      //double XSup = (xsec()+xsec_uncert())/xsec();
      //double XSdown = (xsec()-xsec_uncert())/xsec();
      double XSup = (xsection+xsectionerr)/xsection;
      double XSdown = (xsection-xsectionerr)/xsection;
      double PUup = PUweightUp/PUweight;
      double PUdown = PUweightDown/PUweight;
      double lEffup = weight_lepSF_up()/weight_lepSF()*lepSFnorm/lepSFnormup;
      double lEffdown = weight_lepSF_down()/weight_lepSF()*lepSFnorm/lepSFnormdown;
      double lEffFSup = weight_lepSF_fastSim_up()/weight_lepSF_fastSim()*lepFSSFnorm/lepFSSFnormup;
      double lEffFSdown = weight_lepSF_fastSim_down()/weight_lepSF_fastSim()*lepFSSFnorm/lepFSSFnormdown;
      if(weight_lepSF_fastSim()==0||lepFSSFnormup==0) lEffFSup = lepFSSFweight;
      if(weight_lepSF_fastSim()==0||lepFSSFnormdown==0) lEffFSdown = lepFSSFweight;
      double muRFup   = 1; if(genweights().size()>=9) muRFup   = genweights().at(5)/genweights().at(1)*muRFnorm/muRFnormup;
      double muRFdown = 1; if(genweights().size()>=9) muRFdown = genweights().at(9)/genweights().at(1)*muRFnorm/muRFnormdown;
      double BSFHup = weight_btagsf_heavy_UP()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFLup = weight_btagsf_light_UP()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFHdown = weight_btagsf_heavy_DN()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFLdown = weight_btagsf_light_DN()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFFSup = weight_btagsf_fastsim_UP()/weight_btagsf()*BSFnorm/BSFnormFSup;
      double BSFFSdown = weight_btagsf_fastsim_DN()/weight_btagsf()*BSFnorm/BSFnormFSdown;
      if((SR>=5&&SR<=7)||(SR>=13&&SR<=16)||(SR>=20&&SR<=21)||(SR>=26&&SR<=27)||CR2l==5||(CR2l>=13&&CR2l<=16)||CR2l==20||CR2l==26||(CR1l>=5&&CR1l<=7)||(CR1l>=26&&CR1l<=27)){
	if(BSFweight>0) weight /= BSFweight;
	BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	BSFnormHup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,38));
	BSFnormLup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,39));
	BSFnormHdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,40));
	BSFnormLdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,41));
	BSFnormFSup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,42));
	BSFnormFSdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,43));
	BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	BSFHup = weight_tightbtagsf_heavy_UP()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFLup = weight_tightbtagsf_light_UP()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFHdown = weight_tightbtagsf_heavy_DN()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFLdown = weight_tightbtagsf_light_DN()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFFSup = weight_tightbtagsf_fastsim_UP()/weight_tightbtagsf()*BSFnorm/BSFnormFSup;
	BSFFSdown = weight_tightbtagsf_fastsim_DN()/weight_tightbtagsf()*BSFnorm/BSFnormFSdown;
	if(BSFweight>0)  weight *= BSFweight;
      }
      //cout << "muRFnorm " << muRFnorm << " muRFnormup " << muRFnormup << " muRFnormdown " << muRFnormdown << " weight1 " << genweights().at(1) << " weight5 " << genweights().at(5) << " weight9 " << genweights().at(9) << " muRFup " << muRFup << " muRFdown " << muRFdown << endl;
      //cout << "check weight0 " << genweights().at(0) << " weight4 " << genweights().at(4) << " weight8 " << genweights().at(8) << endl;
      ////for(int k = 0; k<genweights().size(); ++k) cout << "weight" << k << " " << genweights()[k] << ", "; cout << endl;
      
      if(CR1l>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(ntightbtags()>=1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR1l>= 1) histos["CR1l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,CR1l,weight*SF_CR1l);
	if(isT2tt){
	  if(CR1l>=1) histos["CR1l_sigcontamination_polL"]->Fill(mStop,mLSP,CR1l,weight*weight_pol_L*SF_CR1l);
	  if(CR1l>=1) histos["CR1l_sigcontamination_polR"]->Fill(mStop,mLSP,CR1l,weight*weight_pol_R*SF_CR1l);
	}
      } else if(CR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR2l>=1) histos["CR2l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,CR2l,weight*SF_CR2l);
	if(hCR2>=1) histos["CR2l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,hCR2,weight*SF_CR2l_2);
	if(hCR3>=1) histos["CR2l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,hCR3,weight*SF_CR2l_3);
	if(isT2tt){
	  if(CR2l>=1) histos["CR2l_sigcontamination_polL"]->Fill(mStop,mLSP,CR2l,weight*weight_pol_L*SF_CR2l);
	  if(hCR2>=1) histos["CR2l_sigcontamination_polL"]->Fill(mStop,mLSP,hCR2,weight*weight_pol_L*SF_CR2l_2);
	  if(hCR3>=1) histos["CR2l_sigcontamination_polL"]->Fill(mStop,mLSP,hCR3,weight*weight_pol_L*SF_CR2l_2);
	  if(CR2l>=1) histos["CR2l_sigcontamination_polR"]->Fill(mStop,mLSP,CR2l,weight*weight_pol_R*SF_CR2l);
	  if(hCR2>=1) histos["CR2l_sigcontamination_polR"]->Fill(mStop,mLSP,hCR2,weight*weight_pol_R*SF_CR2l_2);
	  if(hCR3>=1) histos["CR2l_sigcontamination_polR"]->Fill(mStop,mLSP,hCR3,weight*weight_pol_R*SF_CR2l_2);
	}
      }
      else if(SR>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(!PassTrackVeto())  cout << __LINE__ << endl;
	if(!PassTauVeto())  cout << __LINE__ << endl;
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	
	histos2["eventsum"+T2tbhelper]    ->Fill(mStop,mLSP,SR,1.);
	histos2["rawweightsum"+T2tbhelper]->Fill(mStop,mLSP,SR,rawweight);
	histos2["totweightsum"+T2tbhelper]->Fill(mStop,mLSP,SR,weight);
	histos2["ISRsum"+T2tbhelper]      ->Fill(mStop,mLSP,SR,ISRweight);
	histos2["BSFsum"+T2tbhelper]      ->Fill(mStop,mLSP,SR,BSFweight);
	histos2["PUweightsum"+T2tbhelper] ->Fill(mStop,mLSP,SR,PUweight);
	histos2["xsecsum"+T2tbhelper]     ->Fill(mStop,mLSP,SR,xsection);
	histos2["nevtsum"+T2tbhelper]     ->Fill(mStop,mLSP,SR,nevts);
	histos2["lepsum"+T2tbhelper]      ->Fill(mStop,mLSP,SR,weight_lepSF());
	histos2["lepSFsum"+T2tbhelper]    ->Fill(mStop,mLSP,SR,weight_lepSF_fastSim());
	
	//finally - do signal regions!
	histos["SRyield"        +T2tbhelper]->Fill(mStop,mLSP,SR,weight);
	histos["SR_ISRup"       +T2tbhelper]->Fill(mStop,mLSP,SR,weight*ISRup);
	histos["SR_ISRdown"     +T2tbhelper]->Fill(mStop,mLSP,SR,weight*ISRdown);
	histos["SR_Xsecup"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*XSup);
	histos["SR_Xsecdown"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*XSdown);
	histos["SR_PUup"        +T2tbhelper]->Fill(mStop,mLSP,SR,weight*PUup);
	histos["SR_PUdown"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*PUdown);
	histos["SR_Bup_HF"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFHup);
	histos["SR_Bup_LF"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFLup);
	histos["SR_Bdown_HF"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFHdown);
	histos["SR_Bdown_LF"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFLdown);
	histos["SR_Bup_FS"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFFSup);
	histos["SR_Bdown_FS"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*BSFFSdown);
	histos["SR_LepEffup"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*lEffup);
	histos["SR_LepEffdown"  +T2tbhelper]->Fill(mStop,mLSP,SR,weight*lEffdown);
	histos["SR_LepEffFSup"  +T2tbhelper]->Fill(mStop,mLSP,SR,weight*lEffFSup);
	histos["SR_LepEffFSdown"+T2tbhelper]->Fill(mStop,mLSP,SR,weight*lEffFSdown);
	histos["SR_muRFup"      +T2tbhelper]->Fill(mStop,mLSP,SR,weight*muRFup/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,1))*counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,2)));
	histos["SR_muRFdown"    +T2tbhelper]->Fill(mStop,mLSP,SR,weight*muRFdown/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,1))*counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,2)));
	if(isT2tt){
	  histos["SRyield_polL"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_L);
	  histos["SR_ISRup_polL"]       ->Fill(mStop,mLSP,SR,weight*weight_pol_L*ISRup);
	  histos["SR_ISRdown_polL"]     ->Fill(mStop,mLSP,SR,weight*weight_pol_L*ISRdown);
	  histos["SR_Xsecup_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*XSup);
	  histos["SR_Xsecdown_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*XSdown);
	  histos["SR_PUup_polL"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_L*PUup);
	  histos["SR_PUdown_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*PUdown);
	  histos["SR_Bup_HF_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFHup);
	  histos["SR_Bup_LF_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFLup);
	  histos["SR_Bdown_HF_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFHdown);
	  histos["SR_Bdown_LF_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFLdown);
	  histos["SR_Bup_FS_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFFSup);
	  histos["SR_Bdown_FS_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*BSFFSdown);
	  histos["SR_LepEffup_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*lEffup);
	  histos["SR_LepEffdown_polL"]  ->Fill(mStop,mLSP,SR,weight*weight_pol_L*lEffdown);
	  histos["SR_LepEffFSup_polL"]  ->Fill(mStop,mLSP,SR,weight*weight_pol_L*lEffFSup);
	  histos["SR_LepEffFSdown_polL"]->Fill(mStop,mLSP,SR,weight*weight_pol_L*lEffFSdown);
	  histos["SR_muRFup_polL"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_L*muRFup);
	  histos["SR_muRFdown_polL"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_L*muRFdown);

	  histos["SRyield_polR"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_R);
	  histos["SR_ISRup_polR"]       ->Fill(mStop,mLSP,SR,weight*weight_pol_R*ISRup);
	  histos["SR_ISRdown_polR"]     ->Fill(mStop,mLSP,SR,weight*weight_pol_R*ISRdown);
	  histos["SR_Xsecup_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*XSup);
	  histos["SR_Xsecdown_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*XSdown);
	  histos["SR_PUup_polR"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_R*PUup);
	  histos["SR_PUdown_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*PUdown);
	  histos["SR_Bup_HF_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFHup);
	  histos["SR_Bup_LF_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFLup);
	  histos["SR_Bdown_HF_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFHdown);
	  histos["SR_Bdown_LF_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFLdown);
	  histos["SR_Bup_FS_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFFSup);
	  histos["SR_Bdown_FS_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*BSFFSdown);
	  histos["SR_LepEffup_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*lEffup);
	  histos["SR_LepEffdown_polR"]  ->Fill(mStop,mLSP,SR,weight*weight_pol_R*lEffdown);
	  histos["SR_LepEffFSup_polR"]  ->Fill(mStop,mLSP,SR,weight*weight_pol_R*lEffFSup);
	  histos["SR_LepEffFSdown_polR"]->Fill(mStop,mLSP,SR,weight*weight_pol_R*lEffFSdown);
	  histos["SR_muRFup_polR"]      ->Fill(mStop,mLSP,SR,weight*weight_pol_R*muRFup);
	  histos["SR_muRFdown_polR"]    ->Fill(mStop,mLSP,SR,weight*weight_pol_R*muRFdown);
	}
      }
      if(BSFweight>0) weight /= BSFweight;
      BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      BSFweight = weight_btagsf()*nevts/BSFnorm;
      if(BSFweight>0)  weight *= BSFweight;
      if(cCR1l>0){
	if(ngoodbtags()!=0) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR1l>= 1) histos["cCR1l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,cCR1l,weight*SF_cCR1l);
	if(isT2tt){
	  if(cCR1l>=1) histos["cCR1l_sigcontamination_polL"]->Fill(mStop,mLSP,cCR1l,weight*weight_pol_L*SF_cCR1l);
	  if(cCR1l>=1) histos["cCR1l_sigcontamination_polR"]->Fill(mStop,mLSP,cCR1l,weight*weight_pol_R*SF_cCR1l);
	}
      } else if(cCR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR2l>=1) histos["cCR2l_sigcontamination"+T2tbhelper]->Fill(mStop,mLSP,cCR2l,weight*SF_cCR2l);
	if(isT2tt){
	  if(cCR2l>=1) histos["cCR2l_sigcontamination_polL"]->Fill(mStop,mLSP,cCR2l,weight*weight_pol_L*SF_cCR2l);
	  if(cCR2l>=1) histos["cCR2l_sigcontamination_polR"]->Fill(mStop,mLSP,cCR2l,weight*weight_pol_R*SF_cCR2l);
	}
      }
      else if(cSR>0){
	histos["cSRyield"        +T2tbhelper]->Fill(mStop,mLSP,cSR,weight);
	histos["cSR_ISRup"       +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*ISRup);
	histos["cSR_ISRdown"     +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*ISRdown);
	histos["cSR_Xsecup"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*XSup);
	histos["cSR_Xsecdown"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*XSdown);
	histos["cSR_PUup"        +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*PUup);
	histos["cSR_PUdown"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*PUdown);
	histos["cSR_Bup_HF"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFHup);
	histos["cSR_Bup_LF"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFLup);
	histos["cSR_Bdown_HF"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFHdown);
	histos["cSR_Bdown_LF"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFLdown);
	histos["cSR_Bup_FS"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFFSup);
	histos["cSR_Bdown_FS"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*BSFFSdown);
	histos["cSR_LepEffup"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*lEffup);
	histos["cSR_LepEffdown"  +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*lEffdown);
	histos["cSR_LepEffFSup"  +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*lEffFSup);
	histos["cSR_LepEffFSdown"+T2tbhelper]->Fill(mStop,mLSP,cSR,weight*lEffFSdown);
	histos["cSR_muRFup"      +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*muRFup);
	histos["cSR_muRFdown"    +T2tbhelper]->Fill(mStop,mLSP,cSR,weight*muRFdown);
	if(isT2tt){
	  histos["cSRyield_polL"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_L);
	  histos["cSR_ISRup_polL"]       ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*ISRup);
	  histos["cSR_ISRdown_polL"]     ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*ISRdown);
	  histos["cSR_Xsecup_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*XSup);
	  histos["cSR_Xsecdown_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*XSdown);
	  histos["cSR_PUup_polL"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*PUup);
	  histos["cSR_PUdown_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*PUdown);
	  histos["cSR_Bup_HF_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFHup);
	  histos["cSR_Bup_LF_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFLup);
	  histos["cSR_Bdown_HF_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFHdown);
	  histos["cSR_Bdown_LF_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFLdown);
	  histos["cSR_Bup_FS_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFFSup);
	  histos["cSR_Bdown_FS_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*BSFFSdown);
	  histos["cSR_LepEffup_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*lEffup);
	  histos["cSR_LepEffdown_polL"]  ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*lEffdown);
	  histos["cSR_LepEffFSup_polL"]  ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*lEffFSup);
	  histos["cSR_LepEffFSdown_polL"]->Fill(mStop,mLSP,cSR,weight*weight_pol_L*lEffFSdown);
	  histos["cSR_muRFup_polL"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*muRFup);
	  histos["cSR_muRFdown_polL"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_L*muRFdown);

	  histos["cSRyield_polR"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_R);
	  histos["cSR_ISRup_polR"]       ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*ISRup);
	  histos["cSR_ISRdown_polR"]     ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*ISRdown);
	  histos["cSR_Xsecup_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*XSup);
	  histos["cSR_Xsecdown_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*XSdown);
	  histos["cSR_PUup_polR"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*PUup);
	  histos["cSR_PUdown_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*PUdown);
	  histos["cSR_Bup_HF_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFHup);
	  histos["cSR_Bup_LF_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFLup);
	  histos["cSR_Bdown_HF_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFHdown);
	  histos["cSR_Bdown_LF_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFLdown);
	  histos["cSR_Bup_FS_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFFSup);
	  histos["cSR_Bdown_FS_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*BSFFSdown);
	  histos["cSR_LepEffup_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*lEffup);
	  histos["cSR_LepEffdown_polR"]  ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*lEffdown);
	  histos["cSR_LepEffFSup_polR"]  ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*lEffFSup);
	  histos["cSR_LepEffFSdown_polR"]->Fill(mStop,mLSP,cSR,weight*weight_pol_R*lEffFSdown);
	  histos["cSR_muRFup_polR"]      ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*muRFup);
	  histos["cSR_muRFdown_polR"]    ->Fill(mStop,mLSP,cSR,weight*weight_pol_R*muRFdown);
	}
      }
      if(cSRu>0){
	histos["cSR_JESup"+T2tbhelper]->Fill(mStop,mLSP,SRu,weight);
	if(isT2tt){
	histos["cSR_JESup_polL"]->Fill(mStop,mLSP,cSRu,weight*weight_pol_L);
	histos["cSR_JESup_polR"]->Fill(mStop,mLSP,cSRu,weight*weight_pol_R);
	}
      }
      if(cSRd>0){
	histos["cSR_JESdown"+T2tbhelper]->Fill(mStop,mLSP,SRu,weight);
	if(isT2tt){
	histos["cSR_JESdown_polL"]->Fill(mStop,mLSP,cSRd,weight*weight_pol_L);
	histos["cSR_JESdown_polR"]->Fill(mStop,mLSP,cSRd,weight*weight_pol_R);
	}
      }
      if(SRu>0){
	if((SRu>=5&&SRu<=7)||(SRu>=13&&SRu<=16)||(SRu>=20&&SRu<=21)||(SRu>=26&&SRu<=27)){
	  if(BSFweight>0) weight /= BSFweight;
	  BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	  BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	  if(BSFweight>0)  weight *= BSFweight;
	}
	histos["SR_JESup"+T2tbhelper]->Fill(mStop,mLSP,SRu,weight);
	if(isT2tt){
	  histos["cSR_JESup_polL"]->Fill(mStop,mLSP,SRu,weight*weight_pol_L);
	  histos["cSR_JESup_polR"]->Fill(mStop,mLSP,SRu,weight*weight_pol_R);
	}
      }
      if(BSFweight>0) weight /= BSFweight;
      BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      BSFweight = weight_btagsf()*nevts/BSFnorm;
      if(BSFweight>0)  weight *= BSFweight;
      if(SRd>0){
	if((SRd>=5&&SRd<=7)||(SRd>=13&&SRd<=16)||(SRd>=20&&SRd<=21)||(SRd>=26&&SRd<=27)){
	  if(BSFweight>0) weight /= BSFweight;
	  BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	  BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	  if(BSFweight>0)  weight *= BSFweight;
	}
	histos["SR_JESdown"+T2tbhelper]->Fill(mStop,mLSP,SRd,weight);
	if(isT2tt){
	  histos["SR_JESdown_polL"]->Fill(mStop,mLSP,SRd,weight*weight_pol_L);
	  histos["SR_JESdown_polR"]->Fill(mStop,mLSP,SRd,weight*weight_pol_R);
	}
      }
      
    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Histograms
  // samplehisto->Draw();

  //cout << "avgBSF " << sumB/sumN << " avgLSF " << suml/sumN << " avgLFS " << sumL/sumN << " raw " << sumR << " all " << sumW << endl;

  //STD ANALYSIS
  string filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_nogenmet.root";
  if(isT2tt||isT2bW){
    TFile *f = new TFile(filename.c_str(),"RECREATE");
    f->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname = histonames[i];
      histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
    }
    f->Close();
    cout << "saved histos in " << f->GetName() << endl;
  }
  if(isT2tt){
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_lefthanded_nogenmet.root";
    TFile *fL = new TFile(filename.c_str(),"RECREATE");
    fL->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_polL";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fL->Close();
    cout << "saved histos in " << fL->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_righthanded_nogenmet.root";
    TFile *fR = new TFile(filename.c_str(),"RECREATE");
    fR->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_polR";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fR->Close();
    cout << "saved histos in " << fR->GetName() << endl;
  }
  if(isT2tb){
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_tLSP_nogenmet.root";
    TFile *f1 = new TFile(filename.c_str(),"RECREATE");
    f1->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_tLSP";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f1->Close();
    cout << "saved histos in " << f1->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_bCharg_nogenmet.root";
    TFile *f2 = new TFile(filename.c_str(),"RECREATE");
    f2->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_bCharg";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f2->Close();
    cout << "saved histos in " << f2->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_mixed_nogenmet.root";
    TFile *f3 = new TFile(filename.c_str(),"RECREATE");
    f3->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_mixed";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f3->Close();
    cout << "saved histos in " << f3->GetName() << endl;
  }


  //COMPRESSED ANALYSIS
  filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_nogenmet.root";
  if(isT2tt||isT2bW){
    TFile *f = new TFile(filename.c_str(),"RECREATE");
    f->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname = "c" + histonames[i];
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f->Close();
    cout << "saved histos in " << f->GetName() << endl;
  }
  if(isT2tt){
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_lefthanded_nogenmet.root";
    TFile *fL = new TFile(filename.c_str(),"RECREATE");
    fL->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_polL";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fL->Close();
    cout << "saved histos in " << fL->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_righthanded_nogenmet.root";
    TFile *fR = new TFile(filename.c_str(),"RECREATE");
    fR->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_polR";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fR->Close();
    cout << "saved histos in " << fR->GetName() << endl;
  }
  if(isT2tb){
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_tLSP_nogenmet.root";
    TFile *f1 = new TFile(filename.c_str(),"RECREATE");
    f1->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_tLSP";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f1->Close();
    cout << "saved histos in " << f1->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_bCharg_nogenmet.root";
    TFile *f2 = new TFile(filename.c_str(),"RECREATE");
    f2->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_bCharg";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f2->Close();
    cout << "saved histos in " << f2->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_mixed_nogenmet.root";
    TFile *f3 = new TFile(filename.c_str(),"RECREATE");
    f3->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_mixed";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f3->Close();
    cout << "saved histos in " << f3->GetName() << endl;
  }

  string filenamec = "rootfiles/signalyields/CheckHistos_std_"+skimFilePrefix+".root";
  TFile *fc = new TFile(filenamec.c_str(),"RECREATE");
  fc->cd();
  for(map<string,TH3D*>::iterator h=    histos2.begin(); h!=    histos2.end();++h) h->second->Write();
  fc->Close();
  cout << "Saved histos in " << fc->GetName() << endl;
  
  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  delete fPU;//delete PU file
  return 0;
}
