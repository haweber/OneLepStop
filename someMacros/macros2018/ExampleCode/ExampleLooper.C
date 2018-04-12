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
#include "CMS3.cc"
#include "Tools/dorky.h"
#include "Tools/dorky.cc"
#include "Tools/goodrun.h"
#include "Tools/goodrun.cc"

//MT2 variants

using namespace std;
using namespace tas;

//calculates Delta R between two vectors
float dRbetweenVectors(LorentzVector vec1,LorentzVector vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

//calculates Delta Phi between two vectors
float dPhibetweenVectors(float phi1,float phi2 ){                                                                                                              
  return fabs(std::min(float(fabs(phi1-phi2)),float(2*M_PI-fabs(phi1-phi2))));
}

//calculates MT between two vectors
float calculateMt(LorentzVector p4, LorentzVector met){
  float phi1 = p4.Phi();
  float phi2 = met.Phi();
  float Et1  = p4.Et();
  float Et2  = met.Et();

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

//this is the looper function that checks all events in the chain (samples) of its properties
//this function is called in runMacro.C
int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  //start booking histograms - in those we store kinematic distribution
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();
  vector<int> hbins; hbins.clear();
  vector<float> hlow; hlow.clear();
  vector<float> hup; hup.clear();
  map<string, set<int> > Nsignalpoints;

  //define histograms of distributions we want to check (as well as the binning of the histograms)
  histonames.push_back("MT_NJge2");              hbins.push_back(20); hlow.push_back( 0. ); hup.push_back(500);//histogram for 0 <= MT < 500, with bin size 25 GeV = 500/20, cut is NJ>=2
  histonames.push_back("MT_NJge4_METge250");     hbins.push_back(20); hlow.push_back( 0. ); hup.push_back(500);//same as above with cuts NJ>=4, MET>=250
  histonames.push_back("MinDeltaRLepJet_NJge2"); hbins.push_back(20); hlow.push_back( 0. ); hup.push_back(5.0);//minimal Delta R(lep-p4,any jet-p4)
  histonames.push_back("SignalRegionYields");    hbins.push_back( 4); hlow.push_back( 0.5); hup.push_back(4.5);//yields per (dummy) signal region

  //now let's actually book the histogram - note that some samples like signal are splitted into categories here
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<4; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("LostLeptonAndTop")) != string::npos){
        if(b==0)      samplename = "LostLepton";
        else if(b==1) samplename = "TT1l";
        else          continue;
      }
      else if(samplename.find(string("Signal_T2tt")) != string::npos){
        if(b==0) samplename = "Signal_T2tt_Wcorridor";      //DeltaM(stop,LSP) < 99 GeV ~ mW (lowest possible value - usually mW = 87 GeV)
        if(b==1) samplename = "Signal_T2tt_topcorridor";    //DeltaM(stop,LSP) = 166-183 ~ mtop (i.e. mtop +/- 8 GeV - reason for +/- is the way we do normalization :-/ -> to be reconsidered)
        if(b==2) samplename = "Signal_T2tt_betweencorridor";//DeltaM(stop,LSP) = 100-150 GeV
        if(b==3) samplename = "Signal_T2tt_highDM";         //DeltaM(stop,LSP) = 200-250 GeV //we don't care about higher DeltaM for this study
        set<int> dummy;
        Nsignalpoints[samplename] = dummy;//initialize with an empty set;
      }
      else if(samplename.find(string("SignalGen_T2tt")) != string::npos){//for genMET histograms
        if(b==0) samplename = "SignalGen_T2tt_Wcorridor";      
        if(b==1) samplename = "SignalGen_T2tt_topcorridor";    
        if(b==2) samplename = "SignalGen_T2tt_betweencorridor";
        if(b==3) samplename = "SignalGen_T2tt_highDM";         
        set<int> dummy;
        Nsignalpoints[samplename] = dummy;
      }
      else if(b>=1) continue;//for all other samples, we don't need splitting
      string mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", hbins[i], hlow[i], hup[i]);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      //cout << mapname << endl;
    }
  }
  //this won't be needed for optimization but for your information: we check for each event if the detector was in a good state - that information is stored in the JSON file.
  if(skimFilePrefix.find(string("Data")) != string::npos){
    const char* json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
    set_goodrun_file_json(json_file);
  }
  

  unsigned int nEventsRunning = 0;
  //Goal: Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
  TH3D* counterhistSig;
  TH1D* counterhist;

  // File Loop - loop over all files in the TChain
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    cout << "Running over file " << currentFile->GetTitle() << endl;
    // Get File Content - load counter histograms and the tree containing all events
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
    
    // Loop over Events from the tree of the current file
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
 
      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      cms3.GetEntry(event);//load branches (needed in C++)
      ++nEventsTotal;
      //if(nEventsTotal>=10000) break;
    
      // Progress
      CMS3::progress( nEventsTotal, nEventsChain );

      if( is_data() && !goodrun(run(), ls()) ) continue;//see JSON file above
      float weight = 1;

      //define what type of sample it
      string samplename = skimFilePrefix;
      if(samplename.find(string("LostLeptonAndTop")) != string::npos){
        if(is1lepFromTop()) samplename = "TT1l";
        else                samplename = "LostLepton";
      }
      else if(samplename.find(string("Signal_T2tt")) != string::npos){
        if(mass_lsp()<100.) continue;//don't trust these signals for fastsim only
        if(     (mass_stop()-mass_lsp())<  98.)                                 samplename = "Signal_T2tt_Wcorridor";
        else if((mass_stop()-mass_lsp())> 165.&&(mass_stop()-mass_lsp())< 185.) samplename = "Signal_T2tt_topcorridor";
        else if((mass_stop()-mass_lsp())>= 99.&&(mass_stop()-mass_lsp())<=150.) samplename = "Signal_T2tt_betweencorridor";
        else if((mass_stop()-mass_lsp())>=199.&&(mass_stop()-mass_lsp())<=250.) samplename = "Signal_T2tt_highDM";
        else continue; //not of interest for our study
      }
      else if(samplename.find(string("SignalGen_T2tt")) != string::npos){
        if(mass_lsp()<100.) continue;//don't trust these signals for fastsim only
        if(     (mass_stop()-mass_lsp())<  98.)                                 samplename = "SignalGen_T2tt_Wcorridor";
        else if((mass_stop()-mass_lsp())> 165.&&(mass_stop()-mass_lsp())< 185.) samplename = "SignalGen_T2tt_topcorridor";
        else if((mass_stop()-mass_lsp())>= 99.&&(mass_stop()-mass_lsp())<=150.) samplename = "SignalGen_T2tt_betweencorridor";
        else if((mass_stop()-mass_lsp())>=199.&&(mass_stop()-mass_lsp())<=250.) samplename = "SignalGen_T2tt_highDM";
        else continue; //not of interest for our study
      }

      //get correct event weight!
      //expected event number (for real data) N = cross section * Luminosity
      //if we generate M simulated events, we need to normalize M to the correctly expected event yield: N = weight * M
      //--> weight = N / M = cross section * luminosity / M
      //in our ntuples: scale1fb = cross section * 1 fb^-1 / M --> can scale to any expected data set size
      if(!is_data() && skimFilePrefix.find(string("Signal")) == string::npos) {//this is all background
        int Nevts = counterhist->GetBinContent(counterhist->FindBin(22));//this is the total number of events in the unskimmed/generated sample
        double nevts = double(Nevts);
        weight = scale1fb()*150.;//this is the event weight
        double lepSFweight = weight_lepSF()*nevts/counterhist->GetBinContent(counterhist->FindBin(28));
        if(lepSFweight>=0&&!std::isinf(lepSFweight)&&!std::isnan(lepSFweight)) weight *= lepSFweight;
      } else if(!is_data()){
        int Nevts = counterhistSig->GetBinContent(counterhistSig->FindBin(mass_stop(),mass_lsp(),36));
        Nsignalpoints[samplename].insert(counterhistSig->FindBin(mass_stop(),mass_lsp(),36));//this is a unique identifier for the signal point
        double nevts = double(Nevts);
        double lepSFweight = weight_lepSF()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mass_stop(),mass_lsp(),27));
        double lepFSweight = weight_lepSF_fastSim()*nevts/counterhistSig->GetBinContent(counterhistSig->FindBin(mass_stop(),mass_lsp(),33));//the signal is produced with FastSimulation - needs an additional scale factor between fast simulation and full simulation
        weight = xsec()*150000/nevts;//xsec is given in pb, not fb
        if(lepSFweight>=0&&!std::isinf(lepSFweight)&&!std::isnan(lepSFweight)) weight *= lepSFweight;
        if(lepFSweight>=0&&!std::isinf(lepFSweight)&&!std::isnan(lepFSweight)) weight *= lepFSweight;
        if(!filt_fastsimjets() )     continue;
        //cout << "Nevts " << nevts << " xsec " << xsec() << " lepSF(FS) " << lepSFweight << "(" << lepFSweight <<") --> weight " << weight << endl;
      }
      TString currentfilename = currentFile->GetTitle();

      //have 2 ttbar-->2l2nu samples that model same thing - combined event weight must be take into account
      if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_25ns")) weight *= 5.77109e+06/(5.77109e+06 + 2.34556e+07);
      if(currentfilename.Contains("ttbar_diLept_madgraph_pythia8_ext1_25ns")) weight *= 2.34556e+07/(5.77109e+06 + 2.34556e+07);
      //if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_25ns")) weight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07);
      //if(currentfilename.Contains("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns")) weight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07);
      //if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns")) weight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07);
      //if(currentfilename.Contains("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns")) weight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07);
      
      //inclusive WJets sample contains also events with nu-pT > 200, but we have an extra sample for that - veto the double counting 
      if(skimFilePrefix.find(string("WJets")) != string::npos){
        if(currentfilename.Contains("nupT200")){ if(nupt()<200) continue; }
        else { if(nupt()>=200) continue; }
      }

      //this is our preselection: exactly one good lepton (and no secondary loose lepton/track/hadronic tau), at least 2 jets, high MET and MT.
      if(nvtxs()<0)               continue;
      if(ngoodleps()!=1)          continue;
      if(nvetoleps()!=1)          continue;
      if(!PassTrackVeto())        continue;
      if(!PassTauVeto())          continue;
      if(ngoodjets()<2)           continue;
      //if(ngoodbtags()<1)          continue;
      if(pfmet()<250)             continue;
      if(mt_met_lep()<150)        continue;
      if(mindphi_met_j1_j2()<0.5) continue;

      if(is_data()) weight = 1.;
      //data needs to be triggered/selected (and saved) by the detector
      if(is_data()){
        if(abs(lep1_pdgid())==11){
          if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleEl())) continue;
        }
        if(abs(lep1_pdgid())==13){
          if(!(HLT_MET()||HLT_MET100_MHT100()||HLT_MET110_MHT110()||HLT_MET120_MHT120()||HLT_SingleMu())) continue;
        }
      }
      //as we loop over multiple 'datasets' (group of data events), an event could appear in two of them - make sure that we don't count such an event twice
      if( is_data() ) {
        duplicate_removal::DorkyEventIdentifier id(run(), evt(), ls());
        if (is_duplicate(id) ) continue;
      }
      //sometimes unexpected noise (from wrongly recorded detector pulses) happen - filter those out
      if(is_data()){
        if(!filt_met()) continue;
        if(!filt_badMuonFilter()) continue;
        if(!filt_badChargedCandidateFilter()) continue;
        if(!filt_jetWithBadMuon()) continue;
        if(!filt_pfovercalomet()) continue;
        if(filt_duplicatemuons()) continue;
        if(filt_badmuons()) continue;
      }
      //here begins the core of this looper - we have no our baseline events - let's investigate those
      
      int SR = -1;
      if(ngoodleps()==1&&nvetoleps()==1&&PassTrackVeto()&&PassTauVeto()&&ngoodbtags()>=1&&ngoodjets()>=5&&lep1_p4().Pt()<150.&&lep1_dphiMET()<2.0&&mindphi_met_j1_j2()>0.5&&pfmet()>=250&&mt_met_lep()>150&&ak4pfjets_passMEDbtag()[0]==false){
        if(     pfmet()>550) SR = 4;
        else if(pfmet()>450) SR = 3;
        else if(pfmet()>350) SR = 2;
        else if(pfmet()>250) SR = 1;
      }
      //now we fill histograms
      //these are dummy signal region - based on 2016 data compressed search
      if(SR>0) histos["SignalRegionYields_" + samplename]->Fill(SR,weight);
      //note that MT is already precalculated in our ntuples, also from above we already have a preselection for >=2j
      histos["MT_NJge2_"+samplename]->Fill(mt_met_lep(),weight);
      //here we want some additional selection
      if(ngoodjets()>=4&&pfmet()>=250.) histos["MT_NJge4_METge250_"+samplename]->Fill(mt_met_lep(),weight);
      //let's look at a variable that is not precalculated - so we need to do it 'by hand'
      float minDRlj = 999.;//ridicoulously large value
      for(unsigned int i = 0; i<ak4pfjets_p4().size();++i){
        //although we store only a subset of jets, for educational purposes, apply selection here for the ith jet
        if(ak4pfjets_p4()[i].Pt()<30.)        continue;//jet has to have at least pT>30 GeV
        if(fabs(ak4pfjets_p4()[i].Eta())>2.4) continue;//jet-|eta|<2.4
        if(!ak4pfjets_loose_pfid()[i])        continue;//some quality criteria
        if(minDRlj>dRbetweenVectors(ak4pfjets_p4()[i],lep1_p4())){
          //first: we have on the very top a function defined dRbetweenVectors to help us - this one I actually use frequently
          //second: we have found a jet-lepton pair with smaller DR - save this as current smallest DR
          minDRlj = dRbetweenVectors(ak4pfjets_p4()[i],lep1_p4());
        }
      }
      //now have found that variable, let's fill it.
      histos["MinDeltaRLepJet_NJge2_"+samplename]->Fill(minDRlj,weight);
      
    }//event loop
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }//file loop
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  //now we filled all histograms - we still need to save them into a file
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    //add overflow
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
    //add underflow
    h->second->SetBinContent(1, h->second->GetBinContent(1)+ h->second->GetBinContent(0) );
    h->second->SetBinError(1, sqrt(pow(h->second->GetBinError(1),2)+pow(h->second->GetBinError(0),2) ) );
    //for signal only - normalize the signal yield to what we expect from a single event point (i.e. get averaged yield per point)
    if(h->first.find("Signal_T2tt_Wcorridor")      !=string::npos) h->second->Scale(1./Nsignalpoints["Signal_T2tt_Wcorridor"]      .size());
    if(h->first.find("Signal_T2tt_topcorridor")    !=string::npos) h->second->Scale(1./Nsignalpoints["Signal_T2tt_topcorridor"]    .size());
    if(h->first.find("Signal_T2tt_betweencorridor")!=string::npos) h->second->Scale(1./Nsignalpoints["Signal_T2tt_betweencorridor"].size());
    if(h->first.find("Signal_T2tt_highDM")         !=string::npos) h->second->Scale(1./Nsignalpoints["Signal_T2tt_highDM"]         .size());
    if(h->first.find("SignalGen_T2tt_Wcorridor")      !=string::npos) h->second->Scale(1./Nsignalpoints["SignalGen_T2tt_Wcorridor"]      .size());
    if(h->first.find("SignalGen_T2tt_topcorridor")    !=string::npos) h->second->Scale(1./Nsignalpoints["SignalGen_T2tt_topcorridor"]    .size());
    if(h->first.find("SignalGen_T2tt_betweencorridor")!=string::npos) h->second->Scale(1./Nsignalpoints["SignalGen_T2tt_betweencorridor"].size());
    if(h->first.find("SignalGen_T2tt_highDM")         !=string::npos) h->second->Scale(1./Nsignalpoints["SignalGen_T2tt_highDM"]         .size());
  }

  string filename = "rootfiles/Examplefile.root";//note this will fail saving if directory rootfiles does not exist

  //now we actually save the files
  TFile *f = new TFile(filename.c_str(),"UPDATE");//use "Update" as we store several 'chains' into one file. Note, we need to be careful in our histogram names, because if we are not, we might overwrite a previous histogram.
  f->cd();
  for(unsigned int i = 0; i<histonames.size(); ++i){
    for(unsigned int b = 0; b<4; ++b){
      string samplename = skimFilePrefix;
      if(samplename.find(string("Top")) != string::npos){
        if(b==0)      samplename = "LostLepton";
        else if(b==1) samplename = "TT1l";
        else          continue;
      }
      else if(samplename.find(string("Signal_T2tt")) != string::npos){
        if(b==0) samplename = "Signal_T2tt_Wcorridor";
        if(b==1) samplename = "Signal_T2tt_topcorridor";
        if(b==2) samplename = "Signal_T2tt_betweencorridor";
        if(b==3) samplename = "Signal_T2tt_highDM";
      }
      else if(samplename.find(string("SignalGen_T2tt")) != string::npos){
        if(b==0) samplename = "SignalGen_T2tt_Wcorridor";
        if(b==1) samplename = "SignalGen_T2tt_topcorridor";
        if(b==2) samplename = "SignalGen_T2tt_betweencorridor";
        if(b==3) samplename = "SignalGen_T2tt_highDM";
      }
      else if(b==1) continue;
      string mapname = histonames[i] + "_"+samplename;
      histos[mapname]->Write(mapname.c_str(),TObject::kOverwrite);//note, that we overwrite files - but that is ok, because we have unique histogram names for each chain
    }
  }  f->Close();
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
