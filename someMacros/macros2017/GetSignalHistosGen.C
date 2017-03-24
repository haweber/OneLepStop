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

  
  //load PUweights
  
  TFile *fPU = new TFile("rootfiles/puWeights_2016data_36p6fbinv.root","READ");
  TH1D *puWeight     = (TH1D*)fPU->Get("puWeight");
  TH1D *puWeightUp   = (TH1D*)fPU->Get("puWeightUp");
  TH1D *puWeightDown = (TH1D*)fPU->Get("puWeightDown");
  
  TFile *fxsec = new TFile("xsec_stop_13TeV.root","READ");
  TH1D *hxsec     = (TH1D*)fxsec->Get("stop");
  
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH3D*> histos;//use D histos as weights can vary a lot among the signal
  vector<string> histonames; histonames.clear();

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
      thisisfirst = true;
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
      if(Nevts !=  histNEvts->GetBinContent(histNEvts->FindBin(mStop,mLSP))) cout << "WTF " << __LINE__ << " " << Nevts << " " << histNEvts->GetBinContent(histNEvts->FindBin(mStop,mLSP)) << endl;
      double nevts = double(Nevts);
      double PUweight     = puWeight    ->GetBinContent(puWeight    ->FindBin(pu_ntrue() ) );
      double ISRnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,24));
      double ISRweight = weight_ISRnjets();//updated
      double BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      double BSFweight = weight_btagsf();
      double lepSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
      double lepFSSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
      double lepSFweight = weight_lepSF();
      double lepFSSFweight = weight_lepSF_fastSim();
      if(ISRnorm>0) ISRweight*=nevts/ISRnorm;
      if(BSFnorm>0) BSFweight *=nevts/BSFnorm;
      if(lepSFnorm>0) lepSFweight *= nevts/lepSFnorm;
      if(lepFSSFnorm>0) lepFSSFweight *= nevts/lepFSSFnorm;
      //lepSF is done below
      double xsection = hxsec->GetBinContent(hxsec->FindBin(mStop));
      double xsectionerr = hxsec->GetBinError(hxsec->FindBin(mStop));
      //double rawweight = xsec()*2260./nevts;
      //double weight = xsec()*2260./nevts*PUweight*ISRweight*BSFweight;//xsec given in pb
      double mylumi = 35900.;
      double rawweight = xsection*mylumi/nevts;
      //double weight = xsection*mylumi/nevts*PUweight*ISRweight*BSFweight*lepSFweight*lepFSSFweight;//xsec given in pb
      double weight = xsection*mylumi/nevts*ISRweight*BSFweight*lepSFweight*lepFSSFweight;//xsec given in pb
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
	    //} else if(ngoodbtags()==0&&Mlb_lead_bdiscr()>175.) {
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
	  //} else if(ngoodbtags()==0&&Mlb_lead_bdiscr()>175.) {
	  } else if(ntightbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    if(     pfmet()>450) CR1l = 27;
	    else if(pfmet()>250) CR1l = 26;
	  }
	}
      }
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()==0&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150&&ak4pfjets_passMEDbtag()[0]==false){
	if(     pfmet()>550) cCR1l = 4;
	else if(pfmet()>450) cCR1l = 3;
	else if(pfmet()>350) cCR1l = 2;
	else if(pfmet()>250) cCR1l = 1;
      }
      //added protection for cases with =0 tight CR (high Mlb), but >=2 medium SR (low Mlb)
      if(SR>0) CR1l = -1;
      
      float SF_CR1l = 1.0;
      float SF_cCR1l = 1.0;
      if(CR1l== 1) SF_CR1l = 0.076*0.68;
      if(CR1l== 2) SF_CR1l = 0.085*0.72;
      if(CR1l== 3) SF_CR1l = 0.076*0.77;
      if(CR1l== 4) SF_CR1l = 0.087*0.82;
      if(CR1l== 5) SF_CR1l = 0.033*0.80;
      if(CR1l== 6) SF_CR1l = 0.043*0.78;
      if(CR1l== 7) SF_CR1l = 0.040*0.84;
      if(CR1l== 8) SF_CR1l = 0.199*0.41;
      if(CR1l== 9) SF_CR1l = 0.150*0.48;
      if(CR1l==10) SF_CR1l = 0.210*0.41;
      if(CR1l==11) SF_CR1l = 0.160*0.61;
      if(CR1l==12) SF_CR1l = 0.272*0.59;
      if(CR1l==13) SF_CR1l = 0.091*0.68;
      if(CR1l==14) SF_CR1l = 0.094*0.70;
      if(CR1l==15) SF_CR1l = 0.125*0.65;
      if(CR1l==16) SF_CR1l = 0.075*0.65;
      if(CR1l==17) SF_CR1l = 0.186*0.59;
      if(CR1l==18) SF_CR1l = 0.169*0.68;
      if(CR1l==19) SF_CR1l = 0.245*0.57;
      if(CR1l==20) SF_CR1l = 0.073*0.74;
      if(CR1l==21) SF_CR1l = 0.073*0.69;
      if(CR1l==22) SF_CR1l = 0.306*0.45;
      if(CR1l==23) SF_CR1l = 0.167*0.71;
      if(CR1l==24) SF_CR1l = 0.253*0.64;
      if(CR1l==25) SF_CR1l = 0.229*0.71;
      if(CR1l==26) SF_CR1l = 0.181*0.82;
      if(CR1l==27) SF_CR1l = 0.096*0.73;
      if(cCR1l==1) SF_cCR1l = 0.207*0.506;
      if(cCR1l==2) SF_cCR1l = 0.142*0.545;
      if(cCR1l==3) SF_cCR1l = 0.199*0.424;
      if(cCR1l==4) SF_cCR1l = 0.145*0.564;
      
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
      if(lepind>=3&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_rl()<2.0&&mindphi_met_j1_j2_rl()>0.5&&pfmet_rl()>=250&&mt_met_lep_rl()>150&&ak4pfjets_passMEDbtag()[0]==false){
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
      if(CR2l== 1) SF_CR2l = 0.25;
      if(CR2l== 2) SF_CR2l = 0.19;
      if(CR2l== 3) SF_CR2l = 0.12;
      if(CR2l== 4) SF_CR2l = 0.18;
      if(CR2l== 5) SF_CR2l = 0.15;
      if(CR2l== 6) { SF_CR2l_2 = 0.01*0.67; /*hCR2 = 6;*/ }
      if(CR2l== 6) { SF_CR2l_3 = 0.01*0.33; hCR2 = 7; }
      if(CR2l== 8) SF_CR2l = 0.50;
      if(CR2l== 9) SF_CR2l = 0.43;
      if(CR2l==10) SF_CR2l = 0.44;
      if(CR2l==11) SF_CR2l = 0.47;
      if(CR2l==12) SF_CR2l = 0.70;
      if(CR2l==13) SF_CR2l = 0.35;
      if(CR2l==14) SF_CR2l = 0.42;
      if(CR2l==15) SF_CR2l = 0.41;
      if(CR2l==16) SF_CR2l = 0.52;
      if(CR2l==17) SF_CR2l = 0.35;
      if(CR2l==18) SF_CR2l = 0.29*0.91;
      if(CR2l==18) { SF_CR2l_2 = 0.29*0.09; hCR2 = 19; }
      if(CR2l==20) SF_CR2l = 0.26*0.96;
      if(CR2l==20) { SF_CR2l_2 = 0.26*0.04; hCR2 = 21; }
      if(CR2l==22) SF_CR2l = 0.32;
      if(CR2l==23) SF_CR2l = 0.26;
      if(CR2l==24) SF_CR2l = 0.25;
      if(CR2l==25) SF_CR2l = 0.34;
      if(CR2l==26) SF_CR2l = 0.20*0.64;
      if(CR2l==26) { SF_CR2l_2 = 0.20*0.36; hCR2 = 27; }
      if(cCR2l==1) SF_cCR2l = 0.568;
      if(cCR2l==2) SF_cCR2l = 0.534;
      if(cCR2l==3) SF_cCR2l = 0.599;
      if(cCR2l==4) SF_cCR2l = 0.705;

      if(SR==(-1)&&CR1l==(-1)&&CR2l==(-1)&&cSR==(-1)&&cCR1l==(-1)&&cCR2l==(-1)) continue;


      int T2tb_BRselection = -1;
      // T2tb_BRselection = -1;
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
      if(CR1l!=(-1)&&CR2l!=(-1)) cout << "WTF CR1l " << CR1l << " CR2l " << CR2l << endl;
      if(SR!=(-1)&&CR1l!=(-1)) { cout << "WTF SR " << SR << " CR1l " << CR1l << endl;
		cout << "NJ " << ngoodjets() << " NB_m " << ngoodbtags() << " NB_t " << ntightbtags() << " tmod " << topnessMod() << " Mlb_SR " << Mlb_closestb() << " Mlb_CR0b " << Mlb_lead_bdiscr() << " MET " << pfmet() << endl;
      }
      if(SR!=(-1)&&CR2l!=(-1)) cout << "WTF SR " << SR << " CR2l " << CR2l << endl;

      if((SR>=5&&SR<=7)||(SR>=13&&SR<=16)||(SR>=20&&SR<=21)||(SR>=26&&SR<=27)||CR2l==5||(CR2l>=13&&CR2l<=16)||CR2l==20||CR2l==26||(CR1l>=5&&CR1l<=7)||(CR1l>=26&&CR1l<=27)){
	if(BSFweight>0) weight /= BSFweight;
	BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
	BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	if(BSFweight>0)  weight *= BSFweight;
      }

            if(CR1l>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(ntightbtags()>=1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR1l>= 1) histos["CR1l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,CR1l,weight*SF_CR1l);
	if(isT2tt){
	  if(CR1l>=1) histos["CR1l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,CR1l,weight*weight_pol_L*SF_CR1l);
	  if(CR1l>=1) histos["CR1l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,CR1l,weight*weight_pol_R*SF_CR1l);
	}
      } else if(CR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR2l>=1) histos["CR2l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,CR2l,weight*SF_CR2l);
	if(hCR2>=1) histos["CR2l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,hCR2,weight*SF_CR2l_2);
	if(hCR3>=1) histos["CR2l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,hCR3,weight*SF_CR2l_3);
	if(isT2tt){
	  if(CR2l>=1) histos["CR2l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,CR2l,weight*weight_pol_L*SF_CR2l);
	  if(hCR2>=1) histos["CR2l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,hCR2,weight*weight_pol_L*SF_CR2l_2);
	  if(hCR3>=1) histos["CR2l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,hCR3,weight*weight_pol_L*SF_CR2l_2);
	  if(CR2l>=1) histos["CR2l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,CR2l,weight*weight_pol_R*SF_CR2l);
	  if(hCR2>=1) histos["CR2l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,hCR2,weight*weight_pol_R*SF_CR2l_2);
	  if(hCR3>=1) histos["CR2l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,hCR3,weight*weight_pol_R*SF_CR2l_2);
	}
      }
      else if(SR>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(!PassTrackVeto())  cout << __LINE__ << endl;
	if(!PassTauVeto())  cout << __LINE__ << endl;
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	histos["SRyield_gen"        +T2tbhelper]->Fill(mStop,mLSP,SR,weight);
	if(isT2tt){
	  histos["SRyield_gen_polL"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_L);
	  histos["SRyield_gen_polR"]        ->Fill(mStop,mLSP,SR,weight*weight_pol_R);
	}
      }
      if(BSFweight>0) weight /= BSFweight;
      BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      BSFweight = weight_btagsf()*nevts/BSFnorm;
      if(BSFweight>0)  weight *= BSFweight;
      if(cCR1l>0){
	if(ngoodbtags()!=0) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR1l>= 1) histos["cCR1l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,cCR1l,weight*SF_cCR1l);
	if(isT2tt){
	  if(cCR1l>=1) histos["cCR1l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,cCR1l,weight*weight_pol_L*SF_cCR1l);
	  if(cCR1l>=1) histos["cCR1l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,cCR1l,weight*weight_pol_R*SF_cCR1l);
	}
      } else if(cCR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR2l>=1) histos["cCR2l_sigcontamination_gen"+T2tbhelper]->Fill(mStop,mLSP,cCR2l,weight*SF_cCR2l);
	if(isT2tt){
	  if(cCR2l>=1) histos["cCR2l_sigcontamination_gen_polL"]->Fill(mStop,mLSP,cCR2l,weight*weight_pol_L*SF_cCR2l);
	  if(cCR2l>=1) histos["cCR2l_sigcontamination_gen_polR"]->Fill(mStop,mLSP,cCR2l,weight*weight_pol_R*SF_cCR2l);
	}
      }
      else if(cSR>0){
	histos["cSRyield_gen"        +T2tbhelper]->Fill(mStop,mLSP,cSR,weight);
	if(isT2tt){
	  histos["cSRyield_gen_polL"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_L);
	  histos["cSRyield_gen_polR"]        ->Fill(mStop,mLSP,cSR,weight*weight_pol_R);
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
  string filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_onlygenmet.root";
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
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_lefthanded_onlygenmet.root";
    TFile *fL = new TFile(filename.c_str(),"RECREATE");
    fL->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_polL";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fL->Close();
    cout << "saved histos in " << fL->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_righthanded_onlygenmet.root";
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
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_tLSP_onlygenmet.root";
    TFile *f1 = new TFile(filename.c_str(),"RECREATE");
    f1->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_tLSP";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f1->Close();
    cout << "saved histos in " << f1->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_bCharg_onlygenmet.root";
    TFile *f2 = new TFile(filename.c_str(),"RECREATE");
    f2->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = histonames[i] + "_bCharg";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f2->Close();
    cout << "saved histos in " << f2->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+"_mixed_onlygenmet.root";
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
  filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_onlygenmet.root";
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
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_lefthanded_onlygenmet.root";
    TFile *fL = new TFile(filename.c_str(),"RECREATE");
    fL->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_polL";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    fL->Close();
    cout << "saved histos in " << fL->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_righthanded_onlygenmet.root";
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
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_tLSP_onlygenmet.root";
    TFile *f1 = new TFile(filename.c_str(),"RECREATE");
    f1->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_tLSP";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f1->Close();
    cout << "saved histos in " << f1->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_bCharg_onlygenmet.root";
    TFile *f2 = new TFile(filename.c_str(),"RECREATE");
    f2->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string savename = histonames[i];
      string mapname  = "c" + histonames[i] + "_bCharg";
      histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
    }
    f2->Close();
    cout << "saved histos in " << f2->GetName() << endl;
    filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+"_mixed_onlygenmet.root";
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
