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
#include "CMS3.cc"

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  int jes = 0;
  TString jestester = skimFilePrefix;
  if(jestester.Contains("JESup")){
    jes = 1;
  } else if(jestester.Contains("JESdown")){
    jes = -1;
  } else {
    cout << "You did not provide a JES specific sample - quit." << endl;
    return 0;
  }
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH3D*> histos;//use D histos as weights can vary a lot among the signal
  vector<string> histonames; histonames.clear();
  //  vector<int> hbins; hbins.clear();
  //  vector<float> hlow; hlow.clear();
  //  vector<float> hup; hup.clear();

  //lumi, trigger, stats done - define all histos, but fill only JESup/JESdown - good for using hadd afterwards
  histonames.push_back("SRyield");
  histonames.push_back("SR_Bup_HF");
  histonames.push_back("SR_Bdown_HF");
  histonames.push_back("SR_Bup_LF");
  histonames.push_back("SR_Bdown_LF");
  histonames.push_back("SR_JESup");
  histonames.push_back("SR_JESdown");
  histonames.push_back("SR_muRFup");
  histonames.push_back("SR_muRFdown");
  histonames.push_back("SR_PDFup");
  histonames.push_back("SR_PDFdown");
  histonames.push_back("SR_ISRup");
  histonames.push_back("SR_ISRdown");
  histonames.push_back("SR_PUup");
  histonames.push_back("SR_PUdown");
  histonames.push_back("SR_LepEffup");
  histonames.push_back("SR_LepEffdown");
  histonames.push_back("CR1l_sigcontamination");//scaled to signalreg yield
  histonames.push_back("CR2l_sigcontamination");//scaled to signalreg yield


  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH3D(mapname.c_str(), "", 37,99,1024, 19,-1,474, 13, -0.5,12.5);
    //mStop 100-1000, mLSP 0-450, SR 1-12, 9200 bins, SR 0 is non-SR - in case it it needed!!
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }

  
  
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  //get the reweighting histograms
  TIter fileIterFirst(listOfFiles);
  TFile *currentFileFirst = 0;
  TH3D* counterhistSig;
  TH2F* histNEvts;
  bool thisisfirst = true;
  // File Loop for adding correct histograms
  while ( (currentFileFirst = (TFile*)fileIterFirst.Next()) ) {
    TFile *file = new TFile( currentFileFirst->GetTitle() );
    file->cd();
    if(thisisfirst){
      counterhistSig = (TH3D*)file->Get("h_counterSMS");
      counterhistSig->SetDirectory(0); 
      histNEvts = (TH2F*)file->Get("histNEvts");
      histNEvts->SetDirectory(0);
      thisisfirst = false;
    } else {
      TH3D *tempcounterhistSig = (TH3D*)file->Get("h_counterSMS");
      tempcounterhistSig->SetDirectory(0); 
      TH2F *temphistNEvts = (TH2F*)file->Get("histNEvts");
      temphistNEvts->SetDirectory(0);
      counterhistSig->Add(tempcounterhistSig);
      histNEvts->Add(temphistNEvts);
      tempcounterhistSig->Delete();
      temphistNEvts->Delete();
    }
    file->Close();
    delete file;
  }

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

      // Analysis Code

      float mStop = mass_stop();
      float mLSP = mass_lsp();
      float mCharg = mass_chargino();
      //float xVal = mass_lsp();
      int Nevts = histNEvts->GetBinContent(histNEvts->FindBin(mStop,mLSP));
      //float weight = cms3.scale1fb()*2.11;
      double PUweight     = puWeight    ->GetBinContent(puWeight    ->FindBin(pu_ntrue() ) );
      double PUweightUp   = puWeightUp  ->GetBinContent(puWeightUp  ->FindBin(pu_ntrue() ) );
      double PUweightDown = puWeightDown->GetBinContent(puWeightDown->FindBin(pu_ntrue() ) );
      PUweightUp = 1; PUweightDown = PUweight; PUweight = 1; //now PU syst is applying vs not applying
      double ISRnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,19));
      double ISRnormup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,20));
      double ISRnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,21));
      double ISRweight = weight_ISR();
      double BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,14));
      double BSFnormHup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,15));
      double BSFnormLup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,16));
      double BSFnormHdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,17));
      double BSFnormLdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,18));
      double BSFweight = weight_btagsf();
      double muRFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,1));
      double muRFup = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,5));
      double muRFdown = counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,9));
      if(ISRnorm>0) ISRweight*=nevts/ISRnorm;
      if(ISRnorm<=0||ISRnormup<=0||ISRnormdown<=0){ ISRnormdown=1.; ISRnormup=1.; ISRnorm=1.;}
      if(ISRweight!=weight_ISR()) cout << "ISRw " << ISRweight << " wISR " << weight_ISR() << " nevts " << nevts << " ISRn " << ISRnorm << endl;
      if(BSFnorm>0) BSFweight *=nevts/BSFnorm;
      if(BSFnorm<0||BSFnormHup<0||BSFnormLup<0||BSFnormHdown<0||BSFnormLdown<0){
	BSFnorm=1; BSFnormHup=1; BSFnormLup=1; BSFnormHdown=1; BSFnormLdown=1;
      }
      if(muRFnorm<0||muRFup<0||muRFdown<0){ muRFdown=1; muRFup=1; muRFnorm=1; }
      //lepSF is done below
      double weight = xsec()*2226./Nevts*PUweight*ISRweight*BSFweight;//xsec given in pb
      //float weight = cms3.xsec()*2226./Nevts;//xsec given in pb
      
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      int NSLeps = 0;
      if(lep1_is_mu()){
	if(lep1_pt()>20&&fabs(lep1_eta())<2.4) {++NSLeps;}
      } else if (lep1_is_el()){
	if(lep1_pt()>20&&fabs(lep1_eta())<1.4442) {++NSLeps; }
      } if(lep2_is_mu()){
	if(lep2_pt()>20&&fabs(lep2_eta())<2.4) {++NSLeps;}
      } else if (lep2_is_el()){
	if(lep2_pt()>20&&fabs(lep2_eta())<1.4442) {++NSLeps; }
      }
      if(NSLeps!=1) continue;//temp
      
      if(nvtxs()<0)               continue;
      if(ngoodleps()!=1)          continue;
      if(nvetoleps()!=1)          continue;
      if(!PassTrackVeto_v3())     continue;
      if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      if(ngoodbtags()<1)          continue;
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;

      int SR = -1;
      int compressedSR = -1;
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto_v3()&&PassTauVeto()&&ngoodbtags()>=1){//basis for SR 1l, >=1b
	if(ngoodjets()>=4){
	  if(MT2W()<=200){
	    if(pfmet()>325) SR = 2;
	    else SR = 1;
	  } else { //high MT2W
	    if(pfmet()>450) SR = 5;
	    else if(pfmet()>350) SR = 4;
	    else SR = 3;
	  }
	} else if(ngoodjets()==3 && MT2W()>200 && pfmet()>350) {
	  SR = 6;
	} else if(MT2W()>200&&topnessMod()>(-3)) { //2 or 3 jets
	  if(ngoodbtags()==1){
	    if(pfmet()>400) SR = 8;
	    else SR = 7;
	  } else {//ge2 jets
	    if(pfmet()>400) SR = 10;
	    else SR = 9;
	  }
	}
	//compressed region (jets are sorted by pt
	if(ngoodjets()>=5&&ak4pfjets_passMEDbtag()[0]==false&&ak4pfjets_pt()[0]>200.){
	  if(MT2W()<=200) compressedSR = 11;
	  else compressedSR = 12;
	}
      }

      if(SR==(-1)&&compressedSR==(-1)) continue;

      if(SR>0){
	//finally - do signal regions!
	if(jes==1){
	  histos["SR_JESup"]->Fill(mStop,mLSP,SR,weight);
	} else if(jes==(-1)){
	  histos["SR_JESdown"]->Fill(mStop,mLSP,SR,weight);
	}
      }
      if(compressedSR>0){
	//compressedSR is defined to not overlap with SR - can use same histogram!
	if(jes==1){
	  histos["SR_JESup"]->Fill(mStop,mLSP,compressedSR,weight);
	} else if(jes==(-1)){
	  histos["SR_JESdown"]->Fill(mStop,mLSP,compressedSR,weight);
	}
      }      

    }//event
    delete tree;
    file->Close();
    delete file;
  }//currentfile

  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Histograms
  // samplehisto->Draw();

  /*
  for(map<string,TH3D*>::iterator h=histos.begin(); h!=histos.end();++h){
    //add overflow
    //h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    //h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
    //add underfloe
    //h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    //h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
  }
  */
  string filename = "rootfiles/signalyields/Histos_"+skimFilePrefix+".root";//skimFilePrefix has JESup/down in its name - use hadd then.
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH3D*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
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
}//ScanChain
