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
#include "TH1D.h"
#include "TH2F.h"
#include "TH3D.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "Math/LorentzVector.h"
//#include "TDatime.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_2018.cc"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.h"
#include "/home/users/haweber/CORE/Tools/dorky/dorky.cc"
#include "/home/users/haweber/CORE/Tools/goodrun.h"
#include "/home/users/haweber/CORE/Tools/goodrun.cc"

using namespace std;
using namespace tas;

//inline float getMT(LorentzVector lep,LorentzVector met){
//  // From cmssw reco::deltaPhi()
//  return TMath::Sqrt(2*met.Et()*lep.Et()*(1-TMath::Cos(JetUtil::deltaPhi(lep,met) ) ) );
//}

float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

float DPhi_W_lep(LorentzVector metlv, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(metlv.x(),metlv.y(),0);
  const TVector3 w = lep+met;
  double dphi = fabs(w.DeltaPhi(lep));
  return dphi;
}
float DPhi_met_lep(LorentzVector metlv, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(metlv.x(),metlv.y(),0);
  double dphi = fabs(met.DeltaPhi(lep));
  return dphi;
}
float dRbetweenVectors(LorentzVector vec1,LorentzVector vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}


int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test", int year = 2016) {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  map<string, TH1F*> histos;
  map<string, TH2F*> histos2;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();
  vector<string> selection; selection.clear();
  vector<string> lepselection; lepselection.clear();
  vector<string> jetselection; jetselection.clear();

  lepselection.push_back("");
  lepselection.push_back("_emutrig");
  lepselection.push_back("_etrig");
  lepselection.push_back("_mutrig");
  
  selection.push_back("");
  selection.push_back("_leadlepZ");
    
  histonames.push_back("MT");         hbins.push_back(18); hlow.push_back(  0); hup.push_back(900);
  histonames.push_back("MET");        hbins.push_back(18); hlow.push_back(  0); hup.push_back(900);
  histonames.push_back("MET_rl");     hbins.push_back(18); hlow.push_back(  0); hup.push_back(900);
  histonames.push_back("Ngoodleps");  hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("Nleps");      hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("Nlooseleps"); hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("NBJets");     hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("NJets");      hbins.push_back( 7); hlow.push_back(  0); hup.push_back(  7);
  histonames.push_back("MinDPhi");    hbins.push_back(16); hlow.push_back(  0); hup.push_back(3.2);
  histonames.push_back("ElPt1");      hbins.push_back(15); hlow.push_back(  0); hup.push_back( 75);
  histonames.push_back("ElPt2");      hbins.push_back(15); hlow.push_back(  0); hup.push_back( 75);
  histonames.push_back("MuPt1");      hbins.push_back(15); hlow.push_back(  0); hup.push_back( 75);
  histonames.push_back("MuPt2");      hbins.push_back(15); hlow.push_back(  0); hup.push_back( 75);

  histonames.push_back("NBJets_3goodlep");     hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("NBJets_3vetolep");     hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);
  histonames.push_back("NBJets_3g3vlep");      hbins.push_back( 5); hlow.push_back(  0); hup.push_back(  5);

  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int j =0; j <selection.size(); ++j){
      for(unsigned int l =0; l <lepselection.size(); ++l){
        for(unsigned int b = 0; b<2; ++b){
          string samplename = skimFilePrefix;
          if(samplename.find(string("Top")) != string::npos){
            if(b==0) samplename = "LostLep";
            if(b==1) samplename = "TT1l";
          } else if(b==1) continue;
          string mapname = histonames[i] + lepselection[l] + selection[j] + "_"+samplename;
          if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i],hup[i]);
          histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
          //cout << mapname << endl;
        }
      }
    }
  }

  //if(is_data()){
  //if(skimFilePrefix.find(string("Data")) != string::npos){
  const char* json_file_2016 = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  const char* json_file_2017 = "Cert_294927-306462_13TeV_EOY2017ReReco_Collisions17_JSON.txt";
  const char* json_file_2018 = "Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.txt";
  if(year==2016) set_goodrun_file_json(json_file_2016);
  if(year==2017) set_goodrun_file_json(json_file_2017);
  if(year==2018) set_goodrun_file_json(json_file_2018);
  //  }
  
  // Loop over events to Analyze
  unsigned int nEventsCount = 0;
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
  TH3D* counterhistSig;
  TH1D* counterhist;
  int counterNum = 0;
  
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
    cout << "nEvents " << nEventsTree << " in filename " << currentFile->GetTitle() << endl;
    for( unsigned int event = 0; event < nEventsTree; ++event) {

      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;

      // Progress
      CMS3::progress( nEventsTotal, nEventsChain );

      // Analysis Code
      float lumi = 136.6;
      if(year==2016) lumi = 35.9;
      if(year==2017) lumi = 41.86;
      if(year==2018) lumi = 58.83;
      float weight = cms3.scale1fb()*lumi;
      if(!is_data() && skimFilePrefix.find(string("Signal")) == string::npos) {
        int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));
        double nevts = double(Nevts);
        double BSFweight = weight_btagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(14));
        //if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhist->GetBinContent(counterhist->FindBin(37));
        double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
        weight = cms3.scale1fb()*lumi;
        //weight = 0.5071*0.574*120000./nevts;//TTH
        //weight = 0.7826*35900./nevts;//TTZ
        //if(nEventsTotal%10000==0) cout << "weight " << weight << " BSF " << BSFweight << " lepSF " << lepSFweight << endl;
        if(BSFweight>=0) weight *= BSFweight;
        if(lepSFweight>=0) weight *= lepSFweight;
        //weight *= weight_PU();
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
        //if(Mlb_closestb()>175.) BSFweight = weight_tightbtagsf()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,37));
        double lepSFweight = weight_lepSF()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,27));
        double lepFSweight = weight_lepSF_fastSim()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mStop,mLSP,33));
        weight = xsec()*lumi*1000./nevts;
        if(BSFweight>=0) weight *= BSFweight;
        if(lepSFweight>=0) weight *= lepSFweight;
        if(lepFSweight>=0) weight *= lepFSweight;
        if(!filt_fastsimjets() )     continue;
      }
      if(is_data()) weight = 1.;
      TString fname = currentFile->GetTitle();
      float sf = 1.;
      if (fname.Contains("TTJets_2lep_s16v3_ext1"))
        sf = 24767666.0 / (24767666.0+6068369.0);
      else if (fname.Contains("TTJets_2lep_s16v3_ext0"))
        sf =  6068369.0 / (24767666.0+6068369.0);
      else if (fname.Contains("TTJets_1lep_t_s16v3_ext1"))
        sf = 49664175.0 / (49664175.0+11957043.0);
      else if (fname.Contains("TTJets_1lep_t_s16v3_ext0"))
        sf = 11957043.0 / (49664175.0+11957043.0);
      else if (fname.Contains("TTJets_1lep_tbar_s16v3_ext1"))
        sf = 48387865.0 / (48387865.0+11955887.0);
      else if (fname.Contains("TTJets_1lep_tbar_s16v3_ext0"))
        sf = 11955887.0 / (48387865.0+11955887.0);
      else if (fname.Contains("DYJetsToLL_M50_s16v3_ext2"))
        sf = 96531428.0 / (96531428.0+49748967.0);
      else if (fname.Contains("DYJetsToLL_M50_s16v3_ext1"))
        sf = 49748967.0 / (96531428.0+49748967.0);
      if (fname.Contains("WWToLNuQQ_f17v2_ext1"))
        sf = 9643134.0 / (9643134.0+8330285.0);
      else if (fname.Contains("WWToLNuQQ_f17v2"))
        sf = 8330285.0 / (9643134.0+8330285.0);
      else if (fname.Contains("DYJetsToLL_M50_f17v2_ext1"))
        sf = 49125561.0 / (49125561.0+48675378.0);
      else if (fname.Contains("DYJetsToLL_M50_f17v2"))
        sf = 48675378.0 / (49125561.0+48675378.0);
      weight *= sf;

      //if(!is1lepFromTop()) continue;
      

      if(nvtxs()<0)               continue;
      if(ngoodleps()<1)           continue;
      if(nvetoleps()<2)           continue;
      //if(ngoodjets()<2)           continue;
      if(ngoodbtags()<0)          continue;
      //if(!PassTrackVeto())        continue;
      //if(!PassTauVeto())          continue;
      if(pfmet()<150)             continue;
      //if(mt_met_lep()<150)        continue;
      //if(mindphi_met_j1_j2()<0.8) continue;

      float trigSF = 1.;
      //offline trigger
       vector<string> currenttrigger; currenttrigger.clear();
       currenttrigger.push_back("");
      if(abs(lep1_pdgid())==11 && abs(lep2_pdgid())==11){
        if(lep1_p4().Pt()<35.) continue;
        if(lep2_p4().Pt()<10.) continue;
       //if(lep1_p4().Pt()<25.) continue;
        //if(lep2_p4().Pt()<15.) continue;
        currenttrigger.push_back("_etrig");
        if(year==2016) trigSF = 0.567134;
        if(year==2017) trigSF = 0.786101;
        if(year==2018) trigSF = 0.687716;
      }
      if(abs(lep1_pdgid())==11 && abs(lep2_pdgid())==13){
        if(lep1_p4().Pt()<25.) continue;
        if(lep2_p4().Pt()<10.) continue;
        currenttrigger.push_back("_emutrig");
        if(year==2016) trigSF = 0.398183;
        if(year==2017) trigSF = 0.744035;
        if(year==2018) trigSF = 0.639073;
      }
      if(abs(lep1_pdgid())==13 && abs(lep2_pdgid())==11){
        if(lep1_p4().Pt()<25.) continue;
        if(lep2_p4().Pt()<15.) continue;
        currenttrigger.push_back("_emutrig");
        if(year==2016) trigSF = 0.398183;
        if(year==2017) trigSF = 0.744035;
        if(year==2018) trigSF = 0.639073;
      }
      if(abs(lep1_pdgid())==13 && abs(lep2_pdgid())==13){
        if(lep1_p4().Pt()<30.) continue;
        if(lep2_p4().Pt()<10.) continue;
        //if(lep1_p4().Pt()<20.) continue;
        //if(lep2_p4().Pt()<10.) continue;
        currenttrigger.push_back("_mutrig");
        if(year==2016) trigSF = 0.479207;
        if(year==2017) trigSF = 0.91658;
        if(year==2018) trigSF = 0.756938;
      }
      //data
      if(is_data()){
        if( !goodrun(tas::run(), tas::ls()) ) continue;
        duplicate_removal::DorkyEventIdentifier id(tas::run(), tas::evt(), tas::ls());
        if( is_duplicate(id) )                  continue; 
        if(filt_met()!=1) continue;
        if(abs(lep1_pdgid())==11 && abs(lep2_pdgid())==11){
          //if(!HLT_DiEl()) continue;
          if(!HLT_SingleEl()) continue;
        }
        if(abs(lep1_pdgid())==11 && abs(lep2_pdgid())==13){
          if(!HLT_MuE()) continue;
        }
        if(abs(lep1_pdgid())==13 && abs(lep2_pdgid())==11){
          if(!HLT_MuE()) continue;
        }
        if(abs(lep1_pdgid())==13 && abs(lep2_pdgid())==13){
          if(!HLT_SingleMu()) continue;
        }
      }
      ++counterNum;
      /*
      if(counterNum%100000==0) {
        cout << lep1_pdgid() << " " << lep2_pdgid() << endl;
        cout << HLT_SingleEl() << " " << HLT_MuE() << " " << HLT_SingleMu() << endl;
        for(int i = 0; i<currenttrigger.size(); ++i ) cout << currenttrigger[i] << endl;
      }
      */
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
        if(is1lepFromTop()) samplename = "TT1l";
        else samplename = "LostLep";
      }
      //if(!is_data()) weight *= trigSF;
      if(skimFilePrefix.find(string("WJets")) != string::npos){
        if(TString(currentFile->GetTitle()).Contains("nupT200")){ if(nupt()<200) continue; }
        else { if(nupt()>=200) continue; }
      }

      float Mll = -1;
      if(lep1_pdgid()==(-lep2_pdgid())) Mll = (lep1_p4()+lep2_p4()).M();
      
      
      vector<string> currentselection; currentselection.clear();
      currentselection.push_back("");
      if(fabs(Mll-90.)<20.) currentselection.push_back("_leadlepZ");

      for(unsigned int l = 0; l<currenttrigger.size(); ++l){
        for(unsigned int j = 0; j<currentselection.size(); ++j){
          string helper = currenttrigger[l] + currentselection[j] + "_"+samplename;
          if(abs(lep1_pdgid())==11) histos["ElPt1"+helper]->Fill(lep1_p4().Pt(),weight);
          if(abs(lep2_pdgid())==11) histos["ElPt2"+helper]->Fill(lep2_p4().Pt(),weight);
          if(abs(lep1_pdgid())==13) histos["MuPt1"+helper]->Fill(lep1_p4().Pt(),weight);
          if(abs(lep2_pdgid())==13) histos["MuPt2"+helper]->Fill(lep2_p4().Pt(),weight);
          histos["MT"+helper]->Fill(mt_met_lep(),weight);
          histos["MET"+helper]->Fill(pfmet(),weight);
          histos["MET_rl"+helper]->Fill(pfmet_rl(),weight);
          histos["Ngoodleps"+helper]->Fill(ngoodleps(),weight);
          histos["Nlooseleps"+helper]->Fill(nlooseleps(),weight);
          histos["Nleps"+helper]->Fill(nvetoleps(),weight);
          histos["NBJets"+helper]->Fill(ngoodbtags(),weight);
          histos["NJets"+helper]->Fill(ngoodjets(),weight);
          histos["MinDPhi"+helper]->Fill(mindphi_met_j1_j2(),weight);
          if(ngoodleps()==3) histos["NBJets_3goodlep"+helper]->Fill(ngoodbtags(),weight);
          if(ngoodleps()>=2&&nvetoleps()==3) histos["NBJets_3g3vlep"+helper]->Fill(ngoodbtags(),weight);
          if(nvetoleps()==3) histos["NBJets_3vetolep"+helper]->Fill(ngoodbtags(),weight);
        }
      }
    }
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  // Example Histograms
  // samplehisto->Draw();

  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    
    h->second->SetBinContent(1, h->second->GetBinContent(1 )+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1 ),2)+pow(h->second->GetBinError(0),2) ) );
    
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
  }
  string filename;
  if(year==2016) filename = "rootfiles/TTZNBfit_2016.root";
  if(year==2017) filename = "rootfiles/TTZNBfit_2017.root";
  if(year==2018) filename = "rootfiles/TTZNBfit_2018.root";

  TFile *f = new TFile(filename.c_str(),"UPDATE");
  f->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int j =0; j <selection.size(); ++j){
      for(unsigned int l =0; l <lepselection.size(); ++l){
        for(unsigned int b = 0; b<2; ++b){
          string samplename = skimFilePrefix;
          if(samplename.find(string("Top")) != string::npos){
            if(b==0) samplename = "LostLep";
            if(b==1) samplename = "TT1l";
          } else if(b==1) continue;
          string mapname = histonames[i] + lepselection[l] + selection[j] + "_"+samplename;
          histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);
          //cout << mapname << " " << histos[mapname]->Integral() << endl;
        }
      }
    }
  }
  f->Close();
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h) h->second->Delete();

  
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
