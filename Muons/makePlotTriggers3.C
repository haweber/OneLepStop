#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include <vector>
#include <string>
#include "TString.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TROOT.h"
#include "TF1.h"
#include "TLatex.h"
#include <sstream>
#include <fstream>

using namespace std;

void makePlotTriggers3(){
    
    bool DCSonly = false;//always false

    string whichdata = "SingleMuon";
    //string whichdata = "DoubleMuon";
    //string whichdata = "MuonEG";
    //string whichdata = "SingleElectron";

  
  //  vector<char*> bgnames, signames;
  vector<string> bgstrings, sigstrings;
  vector<Color_t> colors;
  const unsigned int datasetsize = 4;//12
  const unsigned int bgsetsize = 4;//8
  const unsigned int sigsetsize = datasetsize-bgsetsize;
  string datasets[datasetsize]={"TTbar_amcnlo_50ns","WJets_50ns","DY_M50_50ns","DY_M10_50ns"};
  //char* dataset[datasetsize]={"TTbar1l","TTbar2l","SingleT","VJets","Rare","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  const Color_t mccolor[datasetsize]={kBlue+1,kGreen+1,kMagenta+1,kMagenta-2};//
  
  string outputdir = "../plots/first_20150727/";
  string  inputdir = "../rootfiles/first_20150727/";
    if(DCSonly) outputdir = "../plots/first_20150727/DCSonly/";
  
  for(unsigned int n=0; n<bgsetsize; ++n) {
    //bgnames.push_back(dataset[n]);
    bgstrings.push_back(datasets[n]);
    colors.push_back(mccolor[n]);
  }
  for(unsigned int n=bgsetsize; n<datasetsize; ++n) {
    //signames.push_back(dataset[n]);
    sigstrings.push_back(datasets[n]);
    colors.push_back(mccolor[n]);
  }
  TFile *fbg[bgsetsize];

    vector<string> histonames;
    vector<string> histonames1;
    vector<string> histonames2;
    vector<float> fithisto;
    vector<string> xt;
    vector<string> yt;


    //histonames.push_back("TriggerEff__Mu50_Pt"); fithisto.push_back(52);
    //histonames1.push_back("Trigger__Mu50Tag_Pt");
    //histonames2.push_back("Trigger__Mu50Probe_Pt");
    histonames.push_back("TriggerEff_IsoMu27_Pt"); fithisto.push_back(29);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_Pt");
    histonames2.push_back("Trigger_IsoMu27Probe_Pt");
    histonames.push_back("TriggerEff_IsoMu27_Eta"); fithisto.push_back(-1);          xt.push_back("muon #eta"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_Eta");
    histonames2.push_back("Trigger_IsoMu27Probe_Eta");
    histonames.push_back("TriggerEff_IsoMu27_RelIso03"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_RelIso03");
    histonames2.push_back("Trigger_IsoMu27Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoMu27_RelIso03EA"); fithisto.push_back(-1);          xt.push_back("muon rel.iso-EA"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_RelIso03EA");
    histonames2.push_back("Trigger_IsoMu27Probe_RelIso03EA");
    histonames.push_back("TriggerEff_IsoMu27_RelIso03DB"); fithisto.push_back(-1);      xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoMu27Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoMu27_miniiso"); fithisto.push_back(-1);         xt.push_back("muon rel.miniiso"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_miniiso");
    histonames2.push_back("Trigger_IsoMu27Probe_miniiso");
    histonames.push_back("TriggerEff_IsoMu27_miniisoDB"); fithisto.push_back(-1);       xt.push_back("muon rel.miniiso-DB"); yt.push_back("Efficiency(IsoMu27||IsoTkMu27)");
    histonames1.push_back("Trigger_IsoMu27Tag_miniisoDB");
    histonames2.push_back("Trigger_IsoMu27Probe_miniisoDB");
    histonames.push_back("TriggerEff_IsoMu20_Pt"); fithisto.push_back(22);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_Pt");
    histonames2.push_back("Trigger_IsoMu20Probe_Pt");
    histonames.push_back("TriggerEff_IsoMu20_Eta"); fithisto.push_back(-1);          xt.push_back("muon #eta"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_Eta");
    histonames2.push_back("Trigger_IsoMu20Probe_Eta");
    histonames.push_back("TriggerEff_IsoMu20_RelIso03"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_RelIso03");
    histonames2.push_back("Trigger_IsoMu20Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoMu20_RelIso03EA"); fithisto.push_back(-1);         xt.push_back("muon rel.iso-EA"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_RelIso03EA");
    histonames2.push_back("Trigger_IsoMu20Probe_RelIso03EA");
    histonames.push_back("TriggerEff_IsoMu20_RelIso03DB"); fithisto.push_back(-1);      xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoMu20Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoMu20_miniiso"); fithisto.push_back(-1);        xt.push_back("muon rel.miniiso"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_miniiso");
    histonames2.push_back("Trigger_IsoMu20Probe_miniiso");
    histonames.push_back("TriggerEff_IsoMu20_miniisoDB"); fithisto.push_back(-1);     xt.push_back("muon rel.miniiso-DB"); yt.push_back("Efficiency(IsoMu20||IsoTkMu20)");
    histonames1.push_back("Trigger_IsoMu20Tag_miniisoDB");
    histonames2.push_back("Trigger_IsoMu20Probe_miniisoDB");
    //histonames.push_back("TriggerEff__Mu45eta2p1_Pt"); fithisto.push_back(47);
    //histonames1.push_back("Trigger__Mu45eta2p1Tag_Pt");
    //histonames2.push_back("Trigger__Mu45eta2p1Probe_Pt");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_Pt"); fithisto.push_back(26);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_Pt");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_Pt");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_Eta");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_Eta");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_RelIso03EA"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03EA");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03EA");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_miniiso"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_miniiso");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_miniiso");
    histonames.push_back("TriggerEff_IsoMu24eta2p1_miniisoDB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoMu24eta2p1Tag_miniisoDB");
    histonames2.push_back("Trigger_IsoMu24eta2p1Probe_miniisoDB");
    histonames.push_back("TriggerEff_DiMu_LeadPt"); fithisto.push_back(20);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_DiMuTag_LeadPt");
    histonames2.push_back("Trigger_DiMuProbe_LeadPt");
    histonames.push_back("TriggerEff_DiMu_TrailPt"); fithisto.push_back(10);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_DiMuTag_TrailPt");
    histonames2.push_back("Trigger_DiMuProbe_TrailPt");
 
    histonames.push_back("TriggerEff_PureIsoMu20_Pt"); fithisto.push_back(22);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_Pt");
    histonames2.push_back("Trigger_PureIsoMu20Probe_Pt");
    histonames.push_back("TriggerEff_PureIsoMu20_Eta"); fithisto.push_back(-1);         xt.push_back("muon #eta"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_Eta");
    histonames2.push_back("Trigger_PureIsoMu20Probe_Eta");
    histonames.push_back("TriggerEff_PureIsoMu20_Phi"); fithisto.push_back(-1);         xt.push_back("muon #phi"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_Phi");
    histonames2.push_back("Trigger_PureIsoMu20Probe_Phi");
    histonames.push_back("TriggerEff_PureIsoMu20_RelIso03"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_RelIso03");
    histonames2.push_back("Trigger_PureIsoMu20Probe_RelIso03");
    histonames.push_back("TriggerEff_PureIsoMu20_RelIso03DB"); fithisto.push_back(-1);          xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_RelIso03DB");
    histonames2.push_back("Trigger_PureIsoMu20Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoTkMu20_Pt"); fithisto.push_back(22);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_Pt");
    histonames2.push_back("Trigger_IsoTkMu20Probe_Pt");
    histonames.push_back("TriggerEff_IsoTkMu20_Eta"); fithisto.push_back(-1);         xt.push_back("muon #eta"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_Eta");
    histonames2.push_back("Trigger_IsoTkMu20Probe_Eta");
    histonames.push_back("TriggerEff_IsoTkMu20_Phi"); fithisto.push_back(-1);         xt.push_back("muon #phi"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_Phi");
    histonames2.push_back("Trigger_IsoTkMu20Probe_Phi");
    histonames.push_back("TriggerEff_IsoTkMu20_RelIso03"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_RelIso03");
    histonames2.push_back("Trigger_IsoTkMu20Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoTkMu20_RelIso03DB"); fithisto.push_back(-1);          xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoTkMu20Probe_RelIso03DB");
    
    histonames.push_back("TriggerEff_PureIsoMu20_Pt_etarestrict"); fithisto.push_back(22);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_Pt_etarestrict");
    histonames2.push_back("Trigger_PureIsoMu20Probe_Pt_etarestrict");
    histonames.push_back("TriggerEff_PureIsoMu20_Phi_etarestrict"); fithisto.push_back(-1);         xt.push_back("muon #phi"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_Phi_etarestrict");
    histonames2.push_back("Trigger_PureIsoMu20Probe_Phi_etarestrict");
    histonames.push_back("TriggerEff_IsoTkMu20_Pt_etarestrict"); fithisto.push_back(22);          xt.push_back("muon p_{T} [GeV]"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_Pt_etarestrict");
    histonames2.push_back("Trigger_IsoTkMu20Probe_Pt_etarestrict");
    histonames.push_back("TriggerEff_IsoTkMu20_Phi_etarestrict"); fithisto.push_back(-1);       xt.push_back("muon #phi"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_Phi_etarestrict");
    histonames2.push_back("Trigger_IsoTkMu20Probe_Phi_etarestrict");
    histonames.push_back("TriggerEff_PureIsoMu20_RelIso03_etarestrict"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_RelIso03_etarestrict");
    histonames2.push_back("Trigger_PureIsoMu20Probe_RelIso03_etarestrict");
    histonames.push_back("TriggerEff_PureIsoMu20_RelIso03DB_etarestrict"); fithisto.push_back(-1);          xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoMu20)");
    histonames1.push_back("Trigger_PureIsoMu20Tag_RelIso03DB_etarestrict");
    histonames2.push_back("Trigger_PureIsoMu20Probe_RelIso03DB_etarestrict");
    histonames.push_back("TriggerEff_IsoTkMu20_RelIso03_etarestrict"); fithisto.push_back(-1);          xt.push_back("muon rel.iso"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_RelIso03_etarestrict");
    histonames2.push_back("Trigger_IsoTkMu20Probe_RelIso03_etarestrict");
    histonames.push_back("TriggerEff_IsoTkMu20_RelIso03DB_etarestrict"); fithisto.push_back(-1);          xt.push_back("muon rel.iso-DB"); yt.push_back("Efficiency(IsoTkMu20)");
    histonames1.push_back("Trigger_IsoTkMu20Tag_RelIso03DB_etarestrict");
    histonames2.push_back("Trigger_IsoTkMu20Probe_RelIso03DB_etarestrict");
    
    histonames.push_back("TriggerEff_PureIsoMu27_Pt"); fithisto.push_back(29);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu27Tag_Pt");
    histonames2.push_back("Trigger_PureIsoMu27Probe_Pt");
    histonames.push_back("TriggerEff_PureIsoMu27_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu27Tag_Eta");
    histonames2.push_back("Trigger_PureIsoMu27Probe_Eta");
    histonames.push_back("TriggerEff_PureIsoMu27_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu27Tag_Phi");
    histonames2.push_back("Trigger_PureIsoMu27Probe_Phi");
    histonames.push_back("TriggerEff_PureIsoMu27_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu27Tag_RelIso03");
    histonames2.push_back("Trigger_PureIsoMu27Probe_RelIso03");
    histonames.push_back("TriggerEff_PureIsoMu27_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu27Tag_RelIso03DB");
    histonames2.push_back("Trigger_PureIsoMu27Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoTkMu27_Pt"); fithisto.push_back(29);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu27Tag_Pt");
    histonames2.push_back("Trigger_IsoTkMu27Probe_Pt");
    histonames.push_back("TriggerEff_IsoTkMu27_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu27Tag_Eta");
    histonames2.push_back("Trigger_IsoTkMu27Probe_Eta");
    histonames.push_back("TriggerEff_IsoTkMu27_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu27Tag_Phi");
    histonames2.push_back("Trigger_IsoTkMu27Probe_Phi");
    histonames.push_back("TriggerEff_IsoTkMu27_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu27Tag_RelIso03");
    histonames2.push_back("Trigger_IsoTkMu27Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoTkMu27_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu27Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoTkMu27Probe_RelIso03DB");
    
    histonames.push_back("TriggerEff_PureIsoMu24eta2p1_Pt"); fithisto.push_back(26);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu24eta2p1Tag_Pt");
    histonames2.push_back("Trigger_PureIsoMu24eta2p1Probe_Pt");
    histonames.push_back("TriggerEff_PureIsoMu24eta2p1_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu24eta2p1Tag_Eta");
    histonames2.push_back("Trigger_PureIsoMu24eta2p1Probe_Eta");
    histonames.push_back("TriggerEff_PureIsoMu24eta2p1_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu24eta2p1Tag_Phi");
    histonames2.push_back("Trigger_PureIsoMu24eta2p1Probe_Phi");
    histonames.push_back("TriggerEff_PureIsoMu24eta2p1_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu24eta2p1Tag_RelIso03");
    histonames2.push_back("Trigger_PureIsoMu24eta2p1Probe_RelIso03");
    histonames.push_back("TriggerEff_PureIsoMu24eta2p1_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_PureIsoMu24eta2p1Tag_RelIso03DB");
    histonames2.push_back("Trigger_PureIsoMu24eta2p1Probe_RelIso03DB");
    histonames.push_back("TriggerEff_IsoTkMu24eta2p1_Pt"); fithisto.push_back(25);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu24eta2p1Tag_Pt");
    histonames2.push_back("Trigger_IsoTkMu24eta2p1Probe_Pt");
    histonames.push_back("TriggerEff_IsoTkMu24eta2p1_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu24eta2p1Tag_Eta");
    histonames2.push_back("Trigger_IsoTkMu24eta2p1Probe_Eta");
    histonames.push_back("TriggerEff_IsoTkMu24eta2p1_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu24eta2p1Tag_Phi");
    histonames2.push_back("Trigger_IsoTkMu24eta2p1Probe_Phi");
    histonames.push_back("TriggerEff_IsoTkMu24eta2p1_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu24eta2p1Tag_RelIso03");
    histonames2.push_back("Trigger_IsoTkMu24eta2p1Probe_RelIso03");
    histonames.push_back("TriggerEff_IsoTkMu24eta2p1_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_IsoTkMu24eta2p1Tag_RelIso03DB");
    histonames2.push_back("Trigger_IsoTkMu24eta2p1Probe_RelIso03DB");
    
    histonames.push_back("TriggerEff_Mu50_Pt"); fithisto.push_back(52);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu50Tag_Pt");
    histonames2.push_back("Trigger_Mu50Probe_Pt");
    histonames.push_back("TriggerEff_Mu50_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu50Tag_Eta");
    histonames2.push_back("Trigger_Mu50Probe_Eta");
    histonames.push_back("TriggerEff_Mu50_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu50Tag_Phi");
    histonames2.push_back("Trigger_Mu50Probe_Phi");
    histonames.push_back("TriggerEff_Mu50_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu50Tag_RelIso03");
    histonames2.push_back("Trigger_Mu50Probe_RelIso03");
    histonames.push_back("TriggerEff_Mu50_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu50Tag_RelIso03DB");
    histonames2.push_back("Trigger_Mu50Probe_RelIso03DB");

    histonames.push_back("TriggerEff_Mu45eta2p1_Pt"); fithisto.push_back(47);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu45eta2p1Tag_Pt");
    histonames2.push_back("Trigger_Mu45eta2p1Probe_Pt");
    histonames.push_back("TriggerEff_Mu45eta2p1_Eta"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu45eta2p1Tag_Eta");
    histonames2.push_back("Trigger_Mu45eta2p1Probe_Eta");
    histonames.push_back("TriggerEff_Mu45eta2p1_Phi"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu45eta2p1Tag_Phi");
    histonames2.push_back("Trigger_Mu45eta2p1Probe_Phi");
    histonames.push_back("TriggerEff_Mu45eta2p1_RelIso03"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu45eta2p1Tag_RelIso03");
    histonames2.push_back("Trigger_Mu45eta2p1Probe_RelIso03");
    histonames.push_back("TriggerEff_Mu45eta2p1_RelIso03DB"); fithisto.push_back(-1);        xt.push_back(histonames.back()); yt.push_back("Efficiency");
    histonames1.push_back("Trigger_Mu45eta2p1Tag_RelIso03DB");
    histonames2.push_back("Trigger_Mu45eta2p1Probe_RelIso03DB");
    
    TString fdataname = (inputdir+"Histos3Trigger_"+whichdata+".root");
    if(DCSonly) fdataname = (inputdir+"Histos3TriggerDCS_"+whichdata+".root");
    TFile *fdata = TFile::Open(fdataname.Data());



    TCanvas *c1 = new TCanvas("c1", "",477,41,750,500);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    c1->SetTickx(1);
    c1->SetTicky(1);
    c1->SetLeftMargin(0.18);
    c1->SetRightMargin(0.05);
    c1->SetTopMargin(0.07);
    c1->SetBottomMargin(0.15);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);    float scale;
    for(unsigned int i = 0; i<histonames1.size();++i){
        for(unsigned int j = 0; j<7;++j){
            string prefix = "";
            if(j==1) prefix = "Run251244_";
            else if(j==2) prefix = "Run251251_";
            else if(j==3) prefix = "Run251252_";
            else if(j==4) prefix = "RunPre251561_";
            else if(j==5) prefix = "RunAllPre251561_";
            else if(j>=6) prefix = "RunAfter251561_";
            //if(j==5 && !(histonames1[i]=="TriggerEff_PureIsoMu20_Pt"||histonames1[i]=="TriggerEff_PureIsoMu20_Phi"||histonames1[i]=="TriggerEff_PureIsoMu20_Eta"||
            //             histonames1[i]=="TriggerEff_IsoTkMu20_Pt"  ||histonames1[i]=="TriggerEff_IsoTkMu20_Phi"  ||histonames1[i]=="TriggerEff_IsoTkMu20_Eta")) continue;
            //if(j!=5) continue;
            string name = prefix + histonames1[i]+"_"+whichdata;
            TH1F *hdatatag = (TH1F*)fdata->Get(name.c_str());
            name = prefix + histonames2[i]+"_"+whichdata;
            TH1F *hdataprobe = (TH1F*)fdata->Get(name.c_str());
            name = prefix + histonames[i]+"_"+whichdata;
            float xup = hdatatag->GetBinLowEdge(hdatatag->GetNbinsX())+hdatatag->GetBinWidth(hdatatag->GetNbinsX());
            TH1F *ht = (TH1F*)hdatatag->Clone("ht");
            TH1F *hp = (TH1F*)hdataprobe->Clone("hp");
            if(ht->Integral()<=0) continue;
            TEfficiency *tdataeff = new TEfficiency((*hp),(*ht));
            TH1F *hdataeff = new TH1F(name.c_str(),"",hdatatag->GetNbinsX(), hdatatag->GetBinLowEdge(1), xup);
            //hdataeff->Divide(hdataprobe,hdatatag);
            //hdataeff->GetYaxis()->SetTitle("Efficiency");
            //hdataeff->GetXaxis()->SetTitle(histonames[i].c_str());
            hdataeff->GetYaxis()->SetTitle(yt[i].c_str());
            hdataeff->GetXaxis()->SetTitle(xt[i].c_str());
            hdataeff->Draw();
            hdataeff->GetYaxis()->SetRangeUser(0.,1.2);
            hdataeff->SetMinimum(0.);
            hdataeff->SetMaximum(1.2);
            c1->Clear();
            c1->cd();
            hdataeff->Draw("axis");
            tdataeff->Draw("same");
            //TGraphAsymmErrors *gdataeff = new TGraphAsymmErrors();
            //for(unsigned int i = )
            TGraphAsymmErrors *gdataeff = (TGraphAsymmErrors*)tdataeff->CreateGraph();
            hdataeff->Draw("axis");
            gdataeff->Draw("P");
            c1->Update();
            string outname = outputdir +whichdata + "/" + prefix+ histonames[i] + ".pdf";
            c1->SaveAs(outname.c_str());
            if(fithisto[i]>0){
                name = name + "_fit";
                TF1 *fitfunc = new TF1(name.c_str(),"[0]",fithisto[i],xup);
                //hdataeff->Fit(fitfunc,"R");
                //gdataeff->Fit(fitfunc,"WR");
                gdataeff->Fit(fitfunc,"R");
                c1->Update();
                fitfunc->Draw("same");
                outname = outputdir +whichdata + "/" + prefix + histonames[i] + "_fitted.pdf";
                c1->SaveAs(outname.c_str());
                //std::ostringstream Stream;
                //Stream << "Fit = " << fitfunc->GetParameter(0);
                //TString fitnumber = Stream.str().c_str();
                //TLatex *   tex = new TLatex(0.328859,0.95,fitnumber.Data());
                //tex->SetNDC();
                //tex->SetTextFont(42);
                //tex->SetTextSize(0.04181185);
                //tex->SetLineWidth(2);
                //tex->Draw();
            }
        }
    }
}
