// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

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
#include "CMS3_reminiAOD.cc"
#include "HinvCrossSections.h"

using namespace std;
using namespace tas;


float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

int first_numberstring(std::string const & str)
{
  std::size_t const n = str.find_first_of("0123456789");
  if (n != std::string::npos)
  {
    std::size_t const m = str.find_first_not_of("0123456789", n);
    string numberstring = str.substr(n, m != std::string::npos ? m-n : m);
    istringstream ss(numberstring);
    int result;
    ss >> result;
    return result;
  }
  return -1;
}



int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  int production = -1;
  //0 ttH, 1: ggH, 2: VBFH, 3: WH, 4: ZH, 5: bbH, 6: tH(t), 7: tH(s); 10: W+H, 11: W-H, 12: ZeeH, 13: ZmmH, 14: ZttH, 15: ZqqH, 16: ZnnH, 17: tH(t), 18: tbarH(s), 19: tH(t), 20: tbarH(t)
  if(     skimFilePrefix.find("ttH")    !=string::npos) production =  0;
  else if(skimFilePrefix.find("ggH")    !=string::npos) production =  1;//1 is NNNLO, 99 is NNLO+NNLL
  else if(skimFilePrefix.find("VBFH")   !=string::npos) production =  2;
  else if(skimFilePrefix.find("WH")     !=string::npos) production =  3;
  else if(skimFilePrefix.find("WplusH") !=string::npos) production = 10;
  else if(skimFilePrefix.find("WminusH")!=string::npos) production = 11;
  else if(skimFilePrefix.find("ZH")     !=string::npos) production =  4;
  else if(skimFilePrefix.find("ZeeH")   !=string::npos) production = 12;
  else if(skimFilePrefix.find("ZmmH")   !=string::npos) production = 13;
  else if(skimFilePrefix.find("ZttH")   !=string::npos) production = 14;
  else if(skimFilePrefix.find("ZqqH")   !=string::npos) production = 15;
  else if(skimFilePrefix.find("ZnnH")   !=string::npos) production = 16;
  else if(skimFilePrefix.find("bbH")    !=string::npos) production =  5;
  else if(skimFilePrefix.find("tH_t")   !=string::npos) production =  6;
  else if(skimFilePrefix.find("topH_t") !=string::npos) production = 17;
  else if(skimFilePrefix.find("tbarH_t")!=string::npos) production = 18;
  else if(skimFilePrefix.find("tH_s")   !=string::npos) production =  7;
  else if(skimFilePrefix.find("topH_s") !=string::npos) production = 19;
  else if(skimFilePrefix.find("tbarH_s")!=string::npos) production = 20;
  else {
    cout << "You did not specify correctly the type of H(inv) production - exit." << endl;
    return -1;
  }
  int signalmass = first_numberstring(skimFilePrefix);
  if(signalmass<0){
    cout << "I could not extract the signal mass - you need to put the sample name like ttH_125 for this code to work - you used " << skimFilePrefix << endl;
    return -1;
  };
  float crosssection = Hxsec(production, signalmass, true);
  float Qsqxsuprel = 1.+HxsecUnc(production, signalmass, true, 1,true);
  float Qsqxsdnrel = 1.-HxsecUnc(production, signalmass, true,-1,true);
  float PDFxsuprel = 1.+HxsecUnc(production, signalmass, true, 0,true);
  float PDFxsdnrel = 1.-HxsecUnc(production, signalmass, true, 0,true);
  if(production==1){
    Qsqxsuprel     = 1.+HxsecUnc(production, signalmass, true, 4,true);
    Qsqxsdnrel     = 1.-HxsecUnc(production, signalmass, true, 4,true);
  }
  
  //load PUweights  
  TFile *fPU = new TFile("rootfiles/puWeights_2016data_36p6fbinv.root","READ");
  TH1D *puWeight     = (TH1D*)fPU->Get("puWeight");
  TH1D *puWeightUp   = (TH1D*)fPU->Get("puWeightUp");
  TH1D *puWeightDown = (TH1D*)fPU->Get("puWeightDown");
  

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1D*> histos;//use D histos as weights can vary a lot among the signal
  vector<string> histonames; histonames.clear();

  //lumi, trigger, stats done
  histonames.push_back("SRyield");
  histonames.push_back("SR_Qsqxsup");
  histonames.push_back("SR_Qsqxsdown");
  histonames.push_back("SR_PDFxsup");
  histonames.push_back("SR_PDFxsdown");
  histonames.push_back("SR_PDFup");
  histonames.push_back("SR_PDFdown");
  histonames.push_back("SR_aSup");
  histonames.push_back("SR_aSdown");
  histonames.push_back("SR_Bup_HF");
  histonames.push_back("SR_Bdown_HF");
  histonames.push_back("SR_Bup_LF");
  histonames.push_back("SR_Bdown_LF");
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
  //histonames.push_back("SR_Xsecup");
  //histonames.push_back("SR_Xsecdown");
  histonames.push_back("CR1l_sigcontamination");
  histonames.push_back("CR2l_sigcontamination");
  //histonames.push_back("CR1l_sigcontamination_gen");
  //histonames.push_back("CR2l_sigcontamination_gen");

  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1D(mapname.c_str(), "", 27, 0.5,27.5);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    mapname = "c" + histonames[i];
    if(histos.count(mapname) == 0 ) histos[mapname] = new TH1D(mapname.c_str(), "", 4, 0.5,4.5);
    histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
  }
 
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  TH1D* counterhistSig;
  bool thisisfirst = true;
  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    if((string(currentFile->GetTitle())).find("tth_Private80X")!=string::npos) crosssection *=0.547;

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    if(thisisfirst){
      file->cd();
      counterhistSig = (TH1D*)file->Get("h_counter");
      counterhistSig->SetDirectory(0); 
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
      int Nevts           = counterhistSig->GetBinContent(counterhistSig->FindBin(22));//i got lucky
      double nevts        = double(Nevts);
      //float weight = cms3.scale1fb()*2.11;
      double PUweight     = puWeight    ->GetBinContent(puWeight    ->FindBin(pu_ntrue() ) );
      double PUweightUp   = puWeightUp  ->GetBinContent(puWeightUp  ->FindBin(pu_ntrue() ) );
      double PUweightDown = puWeightDown->GetBinContent(puWeightDown->FindBin(pu_ntrue() ) );
      //PUweightUp = 1; PUweightDown = PUweight; PUweight = 1; //now PU syst is applying vs not applying
      double ISRnorm       = counterhistSig->GetBinContent(counterhistSig->FindBin(25));
      double ISRnormup     = counterhistSig->GetBinContent(counterhistSig->FindBin(26));
      double ISRnormdown   = counterhistSig->GetBinContent(counterhistSig->FindBin(27));
      double ISRweight     = weight_ISRnjets();//updated
      double BSFnorm       = counterhistSig->GetBinContent(counterhistSig->FindBin(14));
      double BSFnormHup    = counterhistSig->GetBinContent(counterhistSig->FindBin(15));
      double BSFnormLup    = counterhistSig->GetBinContent(counterhistSig->FindBin(16));
      double BSFnormHdown  = counterhistSig->GetBinContent(counterhistSig->FindBin(17));
      double BSFnormLdown  = counterhistSig->GetBinContent(counterhistSig->FindBin(18));
      double BSFweight     = weight_btagsf();
      double muRFnorm      = counterhistSig->GetBinContent(counterhistSig->FindBin(1));
      double muRFnormup    = counterhistSig->GetBinContent(counterhistSig->FindBin(5));
      double muRFnormdown  = counterhistSig->GetBinContent(counterhistSig->FindBin(9));
      double PDFnormup     = counterhistSig->GetBinContent(counterhistSig->FindBin(10));
      double PDFnormdown   = counterhistSig->GetBinContent(counterhistSig->FindBin(11));
      double aSnormup      = counterhistSig->GetBinContent(counterhistSig->FindBin(12));
      double aSnormdown    = counterhistSig->GetBinContent(counterhistSig->FindBin(13));
      double lepSFnorm     = counterhistSig->GetBinContent(counterhistSig->FindBin(28));
      double lepSFnormup   = counterhistSig->GetBinContent(counterhistSig->FindBin(29));
      double lepSFnormdown = counterhistSig->GetBinContent(counterhistSig->FindBin(30));
      double lepSFweight   = weight_lepSF();
      if(ISRnorm>0) ISRweight*=nevts/ISRnorm;
      if(ISRnorm<=0||ISRnormup<=0||ISRnormdown<=0){ ISRnormdown=1.; ISRnormup=1.; ISRnorm=1.;}
      if(BSFnorm>0) BSFweight *=nevts/BSFnorm;
      if(BSFnorm<=0||BSFnormHup<=0||BSFnormLup<=0||BSFnormHdown<=0||BSFnormLdown<=0){ BSFnorm=1; BSFnormHup=1; BSFnormLup=1; BSFnormHdown=1; BSFnormLdown=1; }
      if(muRFnorm<=0||muRFnormup<=0||muRFnormdown<=0){ muRFnormdown=1; muRFnormup=1; muRFnorm=1; }
      if(lepSFnorm>0) lepSFweight *= nevts/lepSFnorm;
      if(lepSFnorm<=0||lepSFnormup<=0||lepSFnormdown<=0){lepSFnorm=1; lepSFnormup=1; lepSFnormdown=1;}
      //lepSF is done below
      double xsection = 0.5071*0.547;
      //double xsectionerr = 0.0452;
      double mylumi = 35900.;
      //double rawweight = xsection*mylumi/nevts;
      double rawweight = crosssection*mylumi/nevts;
      //double weight = rawweight*ISRweight*BSFweight*lepSFweight;//xsec given in pb
      double weight = rawweight*BSFweight*lepSFweight;//xsec given in pb
      if(event==0) cout << " " <<xsection << " " << weight << " " << nevts << " " << counterhistSig->GetBinContent(counterhistSig->FindBin(22)) << " " << PUweight << " " << ISRweight << " " << BSFweight << " " << lepSFweight << endl;
      if(event==0) cout << "weight " << weight << " nEvents " << nEventsTree << " filename " << currentFile->GetTitle() << endl;

      if(event==0) cout << "xsec " << xsection/0.5071*4.987E-01 << " cross section " << crosssection << " scale1fb " << scale1fb() << " xsec1fb " << xsection/nevts << " crosssection1fb " << crosssection/nevts << endl;
      
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
      //if(!filt_fastsimjets() )    continue;//THIS IS SO ON NEW BABIES
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
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150&&ak4pfjets_passMEDbtag()[0]==false){
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
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jup_ngoodbtags()>=1&&jup_ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_jup()<2.0&&mindphi_met_j1_j2_jup()>0.5&&pfmet_jup()>=250&&mt_met_lep_jup()>150&&jup_ak4pfjets_passMEDbtag()[0]==false){
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
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&jdown_ngoodbtags()>=1&&jdown_ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET_jdown()<2.0&&mindphi_met_j1_j2_jdown()>0.5&&pfmet_jdown()>=250&&mt_met_lep_jdown()>150&&jdown_ak4pfjets_passMEDbtag()[0]==false){
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
	    //} else if(ngoodbtags()==0&&Mlb_lead_bdiscr()>175.) {
	  } else if(ntightbtags()==0&&Mlb_lead_bdiscr()>175.) {
	    //if(ngoodbtags()!=0) cout << "WTF" << endl;
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

      if(SR==(-1)&&CR1l==(-1)&&CR2l==(-1)&&SRu==(-1)&&SRd==(-1)&&cSR==(-1)&&cCR1l==(-1)&&cCR2l==(-1)&&cSRu==(-1)&&cSRd==(-1)) continue;

      //ISR reweighting, get stop pair using last copy:
      double ISRup     = weight_ISRnjets_UP()/weight_ISRnjets()*ISRnorm/ISRnormup;
      double ISRdown   = weight_ISRnjets_DN()/weight_ISRnjets()*ISRnorm/ISRnormdown;
      //double XSup = (xsection+xsectionerr)/xsection;
      //double XSdown = (xsection-xsectionerr)/xsection;
      double PUup      = PUweightUp/PUweight;
      double PUdown    = PUweightDown/PUweight;
      double lEffup    = weight_lepSF_up()/weight_lepSF()*lepSFnorm/lepSFnormup;
      double lEffdown  = weight_lepSF_down()/weight_lepSF()*lepSFnorm/lepSFnormdown;
      double muRFup    = 1; if(genweights().size()>  9) muRFup   = genweights().at(4)  /genweights().at(0)*muRFnorm/muRFnormup;
      double muRFdown  = 1; if(genweights().size()>  9) muRFdown = genweights().at(8)  /genweights().at(0)*muRFnorm/muRFnormdown;
      double PDFup     = 1; if(genweights().size()>  0) PDFup    = pdf_up_weight()     /genweights().at(0)*muRFnorm/PDFnormup;
      double PDFdown   = 1; if(genweights().size()>  0) PDFdown  = pdf_down_weight()   /genweights().at(0)*muRFnorm/PDFnormdown;
      double aSup      = 1; if(genweights().size()>111) aSup     = genweights().at(109)/genweights().at(0)*muRFnorm/aSnormup;
      double aSdown    = 1; if(genweights().size()>111) aSdown   = genweights().at(110)/genweights().at(0)*muRFnorm/aSnormdown;
      //cout << "weight central " << genweights().at(1) << " or " << genweights().at(0) << " PDFup/down " << pdf_up_weight() << "/" << pdf_down_weight();
      //cout << " alphaSup/down " << genweights().at(109) << "/" << genweights().at(110);
      //cout << " norm PDF " << PDFnormup << "/" << PDFnormdown << " alphaS " << aSnormup << "/" << aSnormdown << " normnorm " << muRFnorm;
      //cout << " --> " << PDFup << "/" << PDFdown << ", " << aSup << "/" << aSdown << endl;
      double BSFHup    = weight_btagsf_heavy_UP()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFLup    = weight_btagsf_light_UP()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFHdown  = weight_btagsf_heavy_DN()/weight_btagsf()*BSFnorm/BSFnormHup;
      double BSFLdown  = weight_btagsf_light_DN()/weight_btagsf()*BSFnorm/BSFnormHup;
      if((SR>=5&&SR<=7)||(SR>=13&&SR<=16)||(SR>=20&&SR<=21)||(SR>=26&&SR<=27)||CR2l==5||(CR2l>=13&&CR2l<=16)||CR2l==20||CR2l==26/*||(CR1l>=5&&CR1l<=7)||(CR1l>=26&&CR1l<=27)*/){
	if(BSFweight>0) weight /= BSFweight;
	BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(37));
	BSFnormHup = counterhistSig->GetBinContent(counterhistSig->FindBin(38));
	BSFnormLup = counterhistSig->GetBinContent(counterhistSig->FindBin(39));
	BSFnormHdown = counterhistSig->GetBinContent(counterhistSig->FindBin(40));
	BSFnormLdown = counterhistSig->GetBinContent(counterhistSig->FindBin(41));
	BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	BSFHup = weight_tightbtagsf_heavy_UP()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFLup = weight_tightbtagsf_light_UP()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFHdown = weight_tightbtagsf_heavy_DN()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	BSFLdown = weight_tightbtagsf_light_DN()/weight_tightbtagsf()*BSFnorm/BSFnormHup;
	if(BSFweight>0)  weight *= BSFweight;
      }

      if(CR1l>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(ntightbtags()>=1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR1l>= 1) histos["CR1l_sigcontamination"]->Fill(CR1l,weight*SF_CR1l);
      } else if(CR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(CR2l>=1) histos["CR2l_sigcontamination"]->Fill(CR2l,weight*SF_CR2l);
	if(hCR2>=1) histos["CR2l_sigcontamination"]->Fill(hCR2,weight*SF_CR2l_2);
	if(hCR3>=1) histos["CR2l_sigcontamination"]->Fill(hCR3,weight*SF_CR2l_3);
      }
      else if(SR>0){
	if(ngoodleps()!=1) cout << __LINE__ << " " << ngoodleps() << endl;
	if(nvetoleps()!=1) cout << __LINE__ << " " << nvetoleps() << endl;
	if(!PassTrackVeto())  cout << __LINE__ << endl;
	if(!PassTauVeto())  cout << __LINE__ << endl;
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	
	//finally - do signal regions!
	histos["SRyield"        ]->Fill(SR,weight);
	histos["SR_Qsqxsup"     ]->Fill(SR,weight*Qsqxsuprel);
	histos["SR_Qsqxsdown"   ]->Fill(SR,weight*Qsqxsdnrel);
	histos["SR_PDFxsup"     ]->Fill(SR,weight*PDFxsuprel);
	histos["SR_PDFxsdown"   ]->Fill(SR,weight*PDFxsdnrel);
	histos["SR_PDFup"       ]->Fill(SR,weight*PDFup);
	histos["SR_PDFdown"     ]->Fill(SR,weight*PDFdown);
	histos["SR_aSup"        ]->Fill(SR,weight*aSup);
	histos["SR_aSdown"      ]->Fill(SR,weight*aSdown);
	histos["SR_ISRup"       ]->Fill(SR,weight*ISRup);
	histos["SR_ISRdown"     ]->Fill(SR,weight*ISRdown);
	//histos["SR_Xsecup"      ]->Fill(SR,weight*XSup);
	//histos["SR_Xsecdown"    ]->Fill(SR,weight*XSdown);
	histos["SR_PUup"        ]->Fill(SR,weight*PUup);
	histos["SR_PUdown"      ]->Fill(SR,weight*PUdown);
	histos["SR_Bup_HF"      ]->Fill(SR,weight*BSFHup);
	histos["SR_Bup_LF"      ]->Fill(SR,weight*BSFLup);
	histos["SR_Bdown_HF"    ]->Fill(SR,weight*BSFHdown);
	histos["SR_Bdown_LF"    ]->Fill(SR,weight*BSFLdown);
	histos["SR_LepEffup"    ]->Fill(SR,weight*lEffup);
	histos["SR_LepEffdown"  ]->Fill(SR,weight*lEffdown);
	histos["SR_muRFup"      ]->Fill(SR,weight*muRFup);
	histos["SR_muRFdown"    ]->Fill(SR,weight*muRFdown);
      }
      if(BSFweight>0) weight /= BSFweight;
      BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(14));
      BSFweight = weight_btagsf()*nevts/BSFnorm;
      if(BSFweight>0)  weight *= BSFweight;
      if(cCR1l>0){
	if(ngoodbtags()!=0) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR1l>= 1) histos["cCR1l_sigcontamination"]->Fill(cCR1l,weight*SF_cCR1l);
      } else if(cCR2l>0){
	if(ngoodbtags()<1) cout << __LINE__ << " " << ngoodbtags() << endl;
	if(cCR2l>=1) histos["cCR2l_sigcontamination"]->Fill(cCR2l,weight*SF_cCR2l);
      }
      else if(cSR>0){
	histos["cSRyield"        ]->Fill(cSR,weight);
	histos["cSR_ISRup"       ]->Fill(cSR,weight*ISRup);
	histos["cSR_ISRdown"     ]->Fill(cSR,weight*ISRdown);
	histos["cSR_Qsqxsup"     ]->Fill(SR,weight*Qsqxsuprel);
	histos["cSR_Qsqxsdown"   ]->Fill(SR,weight*Qsqxsdnrel);
	histos["cSR_PDFxsup"     ]->Fill(SR,weight*PDFxsuprel);
	histos["cSR_PDFxsdown"   ]->Fill(SR,weight*PDFxsdnrel);
	histos["cSR_PDFup"       ]->Fill(SR,weight*PDFup);
	histos["cSR_PDFdown"     ]->Fill(SR,weight*PDFdown);
	histos["cSR_aSup"        ]->Fill(SR,weight*aSup);
	histos["cSR_aSdown"      ]->Fill(SR,weight*aSdown);
	//histos["cSR_Xsecup"      ]->Fill(cSR,weight*XSup);
	//histos["cSR_Xsecdown"    ]->Fill(cSR,weight*XSdown);
	histos["cSR_PUup"        ]->Fill(cSR,weight*PUup);
	histos["cSR_PUdown"      ]->Fill(cSR,weight*PUdown);
	histos["cSR_Bup_HF"      ]->Fill(cSR,weight*BSFHup);
	histos["cSR_Bup_LF"      ]->Fill(cSR,weight*BSFLup);
	histos["cSR_Bdown_HF"    ]->Fill(cSR,weight*BSFHdown);
	histos["cSR_Bdown_LF"    ]->Fill(cSR,weight*BSFLdown);
	histos["cSR_LepEffup"    ]->Fill(cSR,weight*lEffup);
	histos["cSR_LepEffdown"  ]->Fill(cSR,weight*lEffdown);
	histos["cSR_muRFup"      ]->Fill(cSR,weight*muRFup);
	histos["cSR_muRFdown"    ]->Fill(cSR,weight*muRFdown);
      }
      if(cSRu>0){
	histos["cSR_JESup"]->Fill(SRu,weight);
      }
      if(cSRd>0){
	histos["cSR_JESdown"]->Fill(SRu,weight);
      }
      if(SRu>0){
	if((SRu>=5&&SRu<=7)||(SRu>=13&&SRu<=16)||(SRu>=20&&SRu<=21)||(SRu>=26&&SRu<=27)){
	  if(BSFweight>0) weight /= BSFweight;
	  BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(37));
	  BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	  if(BSFweight>0)  weight *= BSFweight;
	}
	histos["SR_JESup"]->Fill(SRu,weight);
      }
      if(BSFweight>0) weight /= BSFweight;
      BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(14));
      BSFweight = weight_btagsf()*nevts/BSFnorm;
      if(BSFweight>0)  weight *= BSFweight;
      if(SRd>0){
	if((SRd>=5&&SRd<=7)||(SRd>=13&&SRd<=16)||(SRd>=20&&SRd<=21)||(SRd>=26&&SRd<=27)){
	  if(BSFweight>0) weight /= BSFweight;
	  BSFnorm = counterhistSig->GetBinContent(counterhistSig->FindBin(37));
	  BSFweight = weight_tightbtagsf()*nevts/BSFnorm;
	  if(BSFweight>0)  weight *= BSFweight;
	}
	histos["SR_JESdown"]->Fill(SRd,weight);
      }
      
    }//event loop
    if((string(currentFile->GetTitle())).find("tth_Private80X")!=string::npos) crosssection /=0.547;

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
  string filename = "rootfiles/signalyields/Histos_std_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    string mapname = histonames[i];
    histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
  }
  f->Close();
  cout << "saved histos in " << f->GetName() << endl;

  //COMPRESSED ANALYSIS
  filename = "rootfiles/signalyields/Histos_compressed_"+skimFilePrefix+".root";
  TFile *fc = new TFile(filename.c_str(),"RECREATE");
  fc->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    string savename = histonames[i];
    string mapname = "c" + histonames[i];
    histos[mapname]->Write(savename.c_str(),TObject::kOverwrite);
  }
  fc->Close();
  cout << "saved histos in " << fc->GetName() << endl;



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
