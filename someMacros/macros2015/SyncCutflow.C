// Usage:
// > root -b doAll.C

// C++
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

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

//MT2 variants
#include "StopAnalysis/StopBabyMaker/stop_variables/JetUtil.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/Topness.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/Davismt2.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/topness.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.h"
//#include "StopAnalysis/StopBabyMaker/stop_variables/chi2.h"

using namespace std;
using namespace tas;

inline double DeltaPhi(double phi1, double phi2){
  // From cmssw reco::deltaPhi()
  double result = phi1 - phi2;
  while( result >   TMath::Pi() ) result -= TMath::TwoPi();
  while( result <= -TMath::Pi() ) result += TMath::TwoPi();
  return TMath::Abs(result);
}

struct PrintOut{
  int Run;
  int LS;
  unsigned int Evt;
  float leppt;
  float lepminiIso;
  int leppdgid;
  float met;
  float mt;
  int njets;
  int nvetoleps;
  int nbjets;
  int ngenleps;
  float DPhiWlep;
  float htssm;
  float Mlb_cb;
  float Mjjj;
  float mt2w;
  float Topness;
  float chi2;
  bool trackveto;
  bool tauveto;
};
bool SortPrintOut(PrintOut const& lhs, PrintOut const& rhs) {
    if (lhs.Run != rhs.Run)
        return lhs.Run < rhs.Run;
    if (lhs.LS != rhs.LS)
        return lhs.LS < rhs.LS;
    return lhs.Evt < rhs.Evt;
}

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  /*
  map<string, TH1F*> histos; //massive
  vector<string> histonames; histonames.clear();
  for(unsigned int b = 0; b<3; ++b){
    string samplename = skimFilePrefix;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname;
      mapname = histonames[i] + "_"+samplename;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", 50, 0, 750);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
    }
  }
  */

  vector <PrintOut> POel; POel.clear();
  vector <PrintOut> POmu; POmu.clear();
  bool fWriteToFile = true;
  bool fAppend = false;
  TString outputdir = "/home/users/haweber/StopAnalysis/AnalysisCode/syncfiles/dummy/";
  std::ostringstream* fLogStreamEl     = 0;
  fLogStreamEl = new std::ostringstream();
  std::ostringstream* fLogStreamMu     = 0;
  fLogStreamMu = new std::ostringstream();

  
  int c1vtx(0), c1l(0), cno2l(0), cno2track(0), cnotau(0), c2j(0), c1b(0), cmet(0);
  int cmt(0), cmdphi(0), cchi(0);

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
	if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==2) samplename = "TTbar2l";
	else if(cms3.gen_nfromtmus_() + cms3.gen_nfromtels_() + cms3.gen_nfromttaus_() ==1) samplename = "TTbar1l";
	else samplename = "TTbarH";
	//if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==2) samplename = "TTbar2l";
	//else if(cms3.gen_nmus_() + cms3.gen_nels_() + cms3.gen_ntaus_() ==1) samplename = "TTbar1l";
	//else samplename = "TTbarH";
      }

      // Analysis Code
      bool print = false;

      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetslv = cms3.ak4pfjets_p4();
      vector<float> jetsbtag = cms3.ak4pfjets_CSV();
      vector<bool> jetsID = cms3.ak4pfjets_loose_pfid();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep1lv = cms3.lep1_p4();

      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > lep2lv = cms3.lep2_p4();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      int l1=-1; bool lele = false; bool lmuo = false; int lpdg = -1; float lpt = -1;
      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NSLeps; l1 = 1; }
	if(lep1_pt()>30&&fabs(lep1_eta())<2.4&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NGLeps; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&lep1_is_phys14_medium_noIso()&&lep1_MiniIso()<0.1) {++NSLeps; l1 = 1; }
	if(lep1_pt()>40&&fabs(lep1_eta())<2.5&&lep1_is_phys14_medium_noIso()&&lep1_MiniIso()<0.1) {++NGLeps; }
      }
      if(lep2_is_mu()){
	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NSLeps; l1 = 1; if(l1!=1) l1 = 2; else l1=-2; }
	if(lep2_pt()>30&&fabs(lep2_eta())<2.4&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NGLeps; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NSLeps; if(l1!=1) l1 = 2; else l1=-2;}
	if(lep2_pt()>40&&fabs(lep2_eta())<2.5&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NGLeps; }
      }
      NGLeps = nvetoleps();


      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > leplv;
      if(l1==1) { leplv = lep1lv; lele  = lep1_is_el(); lmuo = lep1_is_mu(); lpdg = lep1_pdgid(); lpt = lep1_pt(); }
      else if(l1==2) { leplv = lep2lv; lele  = lep2_is_el(); lmuo = lep2_is_mu(); lpdg = lep2_pdgid(); lpt = lep2_pt(); }

      //     if(NGLeps != NLeps) cout << "NGLeps = " << NGLeps << " NLeps = " << NLeps << endl;
      //NGLeps = NLeps;
      vector<int> jind;
      vector<int> bind;
      ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jsumlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jetlv;
      vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > bjetlv;
      vector<float> btag;
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	jind.push_back(nj);
	jetlv.push_back(ak4pfjets_p4()[nj]);
	btag.push_back(ak4pfjets_CSV()[nj]);
	++NGJets;
	if(ak4pfjets_CSV()[nj]>0.814) {++NGBJets; bind.push_back(nj); bjetlv.push_back(ak4pfjets_p4()[nj]);}
      }

      int a = ls(); int b = evt();
      if(
	 //(a==1&&b==42)||(a==1&&b==87)||(a==235&&b==23442)||(a==236&&b==23524)||(a==229&&b==22838)||(a==27&&b==2603)||(a==27&&b==2686)||
	 //(a==1&&b==78)||(a==2&&b==181)||(a==4&&b==381)||(a==236&&b==23527)||(a==305&&b==30452)||(a==305&&b==30493)||(a==67&&b==6661)||
	 //(a==28&&b==2747)||(a==226&&b==22541)||(a==227&&b==22689)||(a==228&&b==22791)||
	 //(a==347&&b==34634)||(a==8&&b==701)||(a==933&&b==93279)||(a==935&&b==93442)||(a==936&&b==93512)||
	 //(a==2&&b==136)||(a==1&&b==94)||(a==3&&b==210)||
	 //(a==1021&&b==102029)||(a==1032&&b==103150)||(a==1035&&b==103451)||(a==1044&&b==104373)||(a==1050&&b==104986)||(a==1055&&b==105412)||(a==1078&b==107747)
	 //(a==1105&&b==110404)||(a==1209&&b==120830)||(a==1386&&b==138514)||(a==1469&&b==146833)||(a==1474&&b==147379)||(a==1572&&b==157167)||(a==1762&&b==176116)||(a==178&&b==17722)||(a==1940&&b==193990)||
	 //(a==1920&&b==191970)||(a==1593&&b==159285)||(a==3565&&b==156451)||(a==3577&&b==157693)||(a==2940&&b==93991)||(a==3853&&b==185236)||(a==406&&b==40507)||(a==4075&&b==7435)||(a==4094&&b==9307)||(a==534&&b==53348)||(a==750&&b==74986)||
	 //(a==1051&&b==105088)||(a==1406&&b==140575)||(a==1695&&b==169498)||(a==2739&&b==73822)||(a==2756&&b==75567)||(a==2786&&b==78531)||(a==2860&&b==85995)||(a==4131&&b==13072)||(a==4771&&b==77053)||(a==953&&b==95223)||
	 //(a==1105&&b==110404)||(a==1469&&b==146833)||(a==1940&&b==193990)||(a==2552&&b==55114)||(a==2923&&b==92267)||(a==3898&&b==189772)||
	 //(a==1023&&b==102258)||(a==1059&&b==105880)||(a==1087&&b==108632)||(a==1156&&b==115509)||(a==1231&&b==123064)||(a==1239&&b==123855)||(a==132&&b==13167)||
	 //(a==1153&&b==115261)||(a==1203&&b==120217)||(a==1236&&b==123583)||(a==1600&&b==159906)||(a==1682&&b==168142)||(a==1703&&b==170241)||(a==1746&&b==174546)||
	 //(a==1023&&b==102258)||(a==1059&&b==105880)||(a==1087&&b==108632)||(a==1156&&b==115509)||(a==1231&&b==123064)||(a==1239&&b==123855)||(a==132&&b==13167)||(a==1492&&b==149163)||(a==1577&&b==157696)||(a==1613&&b==161208)||(a==1910&&b==190979)||
	 //(a==103&&b==10215)||(a==1061&&b==106069)||(a==1064&&b==106353)||(a==1103&&b==110203)||(a==1167&&b==116615)||(a==1170&&b==116989)||(a==1249&&b==124813)||(a==126&&b==12582)||(a==1358&&b==135770)||(a==1484&&b==148362)||(a==1488&&b==148753)||
	 //(a==3693&&b==169236)||(a==44&&b==4361)||(a==2602&&b==60194)||(a==4536&&b==53508)||(a==976&&b==97559)||
	 //(a==2139&&b==13875)||(a==3149&&b==114842)||(a==4319&&b==31883)||(a==2902&&b==90139)||
	 //(a==3507&&b==150679)||(a==3862&&b==186156)||(a==4900&&b==89942)||(a==335&&b==33493)||(a==2030&&b==2981)||(a==1349&&b==134812)||(a==2523&&b==52203)||(a==2911&&b==91082)||
	 //(a==4212&&b==21104)||(a==1805&&b==180463)||(a==3507&&b==150679)||(a==3737&&b==173695)||(a==4159&&b==15898)||(a==4885&&b==88454)||(a==3462&&b==146108)||
	 //(a==4332&&b==33138)||(a==2255&&b==25458)||(a==4900&&b==89942)||(a==1510&&b==150939)||(a==3881&&b==188026)||(a==4680&&b==67995)||
	 //(a==1085&&b==108468)||(a==1777&&b==177612)||(a==1805&&b==180463)||(a==2249&&b==24854)||(a==3017&&b==101609)||
	 //(a==3152&&b==115111)||(a==3507&&b==150679)||(a==3737&&b==173695)||(a==3797&&b==179676)||(a==4159&&b==15898)||(a==4885&&b==88454)||
	 //(a==3507&&b==150679)||(a==3862&&b==186156)||(a==4900&&b==89942)||
	 //(a==234&&b==23332)||
	 //(a==1834&&b==183340)||(a==3105&&b==110402)||//lost events in 650_mu
	 //(a==2139&&b==13875)||(a==3149&&b==114842)||(a==3269&&b==126882)||(a==3642&&b==164156)||//lost events in 850_mu
	 //(a==1060&&b==105970)||(a==1086&&b==108568)||(a==1228&&b==122707)||(a==1229&&b==122809)||(a==1231&&b==123025)||(a==1236&&b==123583)||
	 //(a==1248&&b==124725)||(a==1255&&b==125458)||(a==1343&&b==134213)||(a==1352&&b==135160)||(a==1359&&b==135826)||
	 //(a==1005&&b==100402)||(a==110&&b==10923)||(a==1134&&b==113379)||(a==1204&&b==120350)||(a==1229&&b==122809)||(a==1283&&b==128294)||(a==136&&b==13540)||(a==1451&&b==145096)||
	 //(a==1464&&b==146375)||(a==1481&&b==148058)||(a==1497&&b==149647)||(a==1580&&b==157930)||(a==1701&&b==170085)||(a==1726&&b==172594)||(a==1736&&b==173591)||(a==1775&&b==177427)||
	 //(a==191&&b==19027)||(a==1940&&b==193907)||(a==1967&&b==196689)||(a==2018&&b==1753)||(a==204&&b==20371)||(a==2205&&b==20411)||(a==2257&&b==25651)||(a==226&&b==22541)||
	 //(a==2379&&b==37815)||(a==2429&&b==42828)||
	 //(a==772&&b==77136)||(a==4103&&b==10256)||(a==432&&b==43147)||(a==740&&b==73904)||
	 //(a==1834&&b==183340)||(a==3105&&b==110402)||(a==4951&&b==95018)||(a==2940&&b==93991)||(a==1834&&b==183392)||(a==1766&&b==176590)||(a==2562&&b==56182)||(a==4625&&b==62469)||
	 //(a==4513&&b==51296)||(a==4980&&b==97993)||(a==65&&b==6420)||(a==65&&b==6434)||(a==574&&b==57375)||(a==1556&&b==155560)||(a==347&&b==34634)||(a==3091&&b==109088)||
	 //(a==4998&&b==99764)||(a==28&&b==2731)||(a==765&&b==76436)||(a==281&&b==28075)||(a==1325&&b==132473)||(a==470&&b==46916)||(a==504&&b==50367)||
	 //(a==4574&&b==57302)||(a==1879&&b==187868)||(a==2673&&b==67201)||
	 //(a==2280&&b==27929)||(a==1025&&b==102473)||(a==3138&&b==113782)||(a==4266&&b==26570)||(a==1730&&b==172902)||(a==4517&&b==51656)||(a==4927&&b==92655)||(a==3914&&b==191341)||(a==4041&&b==4100)||(a==473&&b==47240)||
	 //(a==3873&&b==187285)||(a==2950&&b==94995)||(a==1087&&b==108632)||(a==1239&&b==123855)||(a==900&&b==89927)||(a==3830&&b==182969)||(a==2818&&b==81711)||(a==4442&&b==44148)||(a==1055&&b==105412)||(a==4066&&b==6560)||
	 //(a==3482&&b==148111)||(a==1834&&b==183340)||(a==3105&&b==110402)||(a==2822&&b==82102)||(a==4418&&b==41731)||(a==289&&b==28878)||(a==2068&&b==6794)||(a==4135&&b==13456)||
	 //(a==1663&&b==166293)||(a==3412&&b==141142)||(a==2853&&b==85226)||(a==2404&&b==40312)||(a==4460&&b==45931)||(a==2152&&b==15171)||(a==4234&&b==23351)||
	 (a==2756&&b==75567)||(a==1695&&b==169498)||(a==4771&&b==77053)||(a==1051&&b==105088)||(a==1469&&b==146833)||
	 (a==-1&&b==-1)
         ){
      	print = true;
      }
					  
      if(print){
	cout << "My Event dump: run:ls:evt " << run() << ":" << ls() << ":" << evt() << endl;
	cout << "nvtxs " << nvtxs() << endl;
	cout << "lepton 1: pt " << lep1_pt() << " eta " << lep1_eta() << " phi " << lep1_phi() << " mass " << lep1_mass() << endl;
	cout << "          pdgID " << lep1_pdgid() << " passVeto " << lep1_passVeto() << " passMedium " << lep1_passMediumID() << " (note true="<<true << ")" << endl;
	cout << "          dz " << lep1_dz() << " d0 " << lep1_d0() << " MiniIso " << lep1_MiniIso() << endl;
	//cout << "          relIso03DB " << lep1_relIso03DB() << " relIso04DB " << lep1_relIso04DB() << " muontight " << lep1_is_muoid_tight() << " PF? " << lep1_is_pfmu() << endl;
	if(lep2_pt()>0){
	  cout << "lepton 2: pt " << lep2_pt() << " eta " << lep2_eta() << " phi " << lep2_phi() << " mass " << lep2_mass() << endl;
	  cout << "          pdgID " << lep2_pdgid() << " passVeto " << lep2_passVeto() << " passMedium " << lep2_passMediumID() << " (note true="<<true << ")" << endl;
	  cout << "          dz " << lep2_dz() << " d0 " << lep2_d0() << " MiniIso " << lep2_MiniIso() << endl;
	  //cout << "          relIso03DB " << lep2_relIso03DB() << " relIso04DB " << lep2_relIso04DB() << " muontight " << lep1_is_muoid_tight() << " PF? " << lep1_is_pfmu() << endl;
	}
	for(unsigned int j = 0; j<ak4pfjets_pt().size();++j){
	  cout << "jet " << j+1 << ": pt " << ak4pfjets_pt()[j] << " eta " << ak4pfjets_eta()[j] << " phi " << ak4pfjets_phi()[j] << " mass " << ak4pfjets_mass()[j] << endl;
	  cout << "       CSV " << ak4pfjets_CSV()[j] << " ID " << ak4pfjets_loose_pfid()[j] << " PUid " << ak4pfjets_puid()[j] << " metDPhi " << dphi_ak4pfjet_met()[j]
	       << " lep1DPhi " << JetUtil::deltaPhi(ak4pfjets_p4()[j],lep1_p4()) << " lep1DR " << JetUtil::deltaR(ak4pfjets_p4()[j],lep1_p4()) << endl;
	  cout << "       CHF " <<  ak4pfjets_chf()[j] << " NHF " << ak4pfjets_nhf()[j] << " CEF " << ak4pfjets_cef()[j] << " NEF " << ak4pfjets_nef()[j] << " MUF " << ak4pfjets_muf()[j] << " CM " << ak4pfjets_cm()[j] << " NM " <<  ak4pfjets_nm()[j] << endl;
	}
	if(ak4pfjet_overlep1_p4().Pt()>0) cout << "overlapjet1: pt " << ak4pfjet_overlep1_p4().Pt() << " eta " << ak4pfjet_overlep1_p4().Eta() << " phi " << ak4pfjet_overlep1_p4().Phi() << " mass " << ak4pfjet_overlep1_p4().M() << " CSV " << ak4pfjet_overlep1_CSV() << endl;
	else cout << "no overlapjet1" << endl;
	if(ak4pfjet_overlep2_p4().Pt()>0) cout << "overlapjet2: pt " << ak4pfjet_overlep2_p4().Pt() << " eta " << ak4pfjet_overlep2_p4().Eta() << " phi " << ak4pfjet_overlep2_p4().Phi() << " mass " << ak4pfjet_overlep2_p4().M() << " CSV " << ak4pfjet_overlep2_CSV() << endl;
	else cout << "no overlapjet2" << endl;
	cout << "PassTrackVeto " << PassTrackVeto() << " PassTauVeto " << PassTauVeto() << " rho " << ak4pfjets_rho() << " MET " << pfmet() << " METphi " << pfmet_phi() << endl;
	cout << "MT " << mt_met_lep() << " NJets " << ngoodjets() << " NBJets " << ngoodbtags() << " NLeps " << ngoodleps() << " NVetoLeps " << nvetoleps() << " NGenLeps " << genlepsfromtop() << endl;
	cout << "MT2W " << MT2W() << " chi2 " << hadronic_top_chi2() << " topness " << topness() << " dphi_Wlep " << dphi_Wlep() << " HT " << ak4_HT() << " HTssm " << ak4_htssm() << " HTosm " << ak4_htosm() << endl;
	cout << "Mlb_closestb " << Mlb_closestb() << " Mlb_lead_bdiscr " << Mlb_lead_bdiscr() << " Mjjj " << Mjjj() << " dR_lep_leadb " << dR_lep_leadb() << endl;
	cout << "HLT_SingleMu " << HLT_SingleMu() << " HLT_SingleEl " << HLT_SingleEl() << " scale1fb " << scale1fb() << " mass_stop " << mass_stop() << " mass_lsp " << mass_lsp() << " mass_chargino " << mass_chargino() << endl;
	cout << "firstGoodVertex " << firstGoodVtxIdx() << " 1stVtx-fake " << firstVtx_isfake() << " 1stVtx-ndof " << firstVtx_ndof() << " 1stVtx-posRho " << firstVtx_posRho() << " 1stVtx-posZ " << firstVtx_posZ() << endl;
	for(unsigned int j = 0; j<isoTracks_p4().size();++j){
	  if(isoTracks_isVetoTrack()[j]==true) {
	    cout << "Track pt " << isoTracks_p4()[j].Pt() << " eta " << isoTracks_p4()[j].Eta() << " dz " << isoTracks_dz()[j] << " pdgid " << isoTracks_pdgId()[j] << " absIso " << isoTracks_absIso()[j] << " " << isoTracks_charge()[j] << " DeltaR " << JetUtil::deltaR(isoTracks_p4()[j], lep1_p4()) << endl;
	  }
	  else{ float dddddd;
	    cout << "NonIsoTrack pt " << isoTracks_p4()[j].Pt() << " eta " << isoTracks_p4()[j].Eta() << " dz " << isoTracks_dz()[j] << " pdgid " << isoTracks_pdgId()[j] << " absIso " << isoTracks_absIso()[j] << " " << isoTracks_charge()[j] << " DeltaR " << JetUtil::deltaR(isoTracks_p4()[j], lep1_p4()) << endl;
	  }
	}
	cout << endl;
	/*for(unsigned int j = 0; j<ak4pfjets_pt().size();++j){
	  for(unsigned int jj = j+1; jj<ak4pfjets_pt().size();++jj){
	    for(unsigned int jjj = jj+1; jjj<ak4pfjets_pt().size();++jjj){
	      cout << "Combining jet" << (j+1) << " jet" << (jj+1) << " and jet" << (jjj+1) << " yields Mjjj " << (ak4pfjets_p4()[j]+ak4pfjets_p4()[jj]+ak4pfjets_p4()[jjj]).M() << endl;
	    }
	  }
	  }*/
      }
      
      if(print){
	vector<int> jetIndexSortedCSV = JetUtil::JetIndexCSVsorted(ak4pfjets_CSV(),ak4pfjets_p4(),ak4pfjets_loose_pfid(),30.,2.4,true);
	vector<LorentzVector> mybjets; vector<LorentzVector> myaddjets;
	vector<bool> passMEDbtag;
	vector<LorentzVector> myjets;
	for(unsigned int idx = 0; idx<jetIndexSortedCSV.size(); ++idx){
	  if(ak4pfjets_CSV().at(jetIndexSortedCSV[idx])>0.814) mybjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	  else if(mybjets.size()<=1 && (mybjets.size()+myaddjets.size())<3) myaddjets.push_back(ak4pfjets_p4().at(jetIndexSortedCSV[idx]) );
	}
	for(unsigned int idx = 0; idx<ak4pfjets_p4().size(); ++idx){
	  if(ak4pfjets_CSV().at(idx)>0.814) passMEDbtag.push_back(true);
	  else passMEDbtag.push_back(false);
	  myjets.push_back(ak4pfjets_p4().at(idx));
	}
	//MT2W
	//float myMT2W = CalcMT2W_(mybjets,myaddjets,lep1_p4(),pfmet(), pfmet_phi());
	//cout << "MT2W " << myMT2W << endl;
	//Topness
	//float mytopness = CalcTopness_(0,pfmet(),pfmet_phi(),lep1_p4(),mybjets,myaddjets);
	//cout << "topness " << mytopness << endl;
	/*
	vector<float> dummy_sigma;
	for (size_t idx = 0; idx < ak4pfjets_p4().size(); ++idx){
	  dummy_sigma.push_back(0.1);
	} 
	float myhadronic_top_chi2 = calculateChi2(myjets, dummy_sigma, passMEDbtag);
	cout << endl << endl;
	*/
	}
      
      if(nvtxs()<0)        continue; ++c1vtx;
      if(NGLeps!=1)        continue; ++c1l;
      if(NSLeps!=1)        continue; ++cno2l;
      //if(!PassTrackVeto()) continue; ++cno2track;
      //if(!PassTauVeto())   continue; ++cnotau;
      if(NGJets<4)         continue; ++c2j;
      if(NGBJets<1)        continue; ++c1b;
      if(pfmet()<80)       continue; ++cmet;

      // if(lele!=lep1_is_el()) cout << "lep1_is_el "   << lep1_is_el() << " lele " << lele << " lep2_is_el "   << lep2_is_el() << endl;
      //if(lmuo!=lep1_is_mu()) cout << "lep1_is_mu "   << lep1_is_mu() << " lmuo " << lmuo << " lep2_is_mu "   << lep2_is_mu() << endl;
      //if(lpdg!=lep1_pdgid()) cout << "lep1_pdgid() " << lep1_pdgid() << " lpdg " << lpdg << " lep2_pdgid() " << lep2_pdgid() << endl;
      //if(lpt!=lep1_pt())     cout << "lep1_pt() "    << lep1_pt()    << " lpt "  << lpt  << " lep2_pt() "    << lep2_pt()    << endl;
      if(lep1_miniRelIsoDB()!=lep1_MiniIso() ) cout << "lep1_miniRelIsoDB() "    << lep1_miniRelIsoDB()    << " lep1_MiniIso() "  << lep1_MiniIso()  << endl;

      PrintOut PO;
      PO.Run = run(); PO.LS = ls(); PO.Evt = evt(); PO.leppt = lep1_pt(); PO.leppdgid = lep1_pdgid(); PO.met = pfmet(); PO.mt = mt_met_lep(); PO.njets = ngoodjets(); PO.nbjets = ngoodbtags(); PO.ngenleps = genlepsfromtop();
      PO.DPhiWlep = dphi_Wlep(); PO.htssm = ak4_htssm(); PO.Mlb_cb = Mlb_closestb(); PO.Mjjj = Mjjj(); PO.mt2w = MT2W(); PO.Topness = topness(); PO.chi2 = hadronic_top_chi2();
      PO.nvetoleps = nvetoleps(); PO.trackveto = PassTrackVeto(); PO.tauveto = PassTauVeto();
      PO.lepminiIso = lep1_MiniIso();
      //Print out (4 digits after comma - as agreed in meeting) run:ls:evt:lep1_pt:lep1_pdgid:pfmet:mt_met_lep:ngoodjets:ngoodbtags:genlepsfromtop:dphi_Wlep:ak4_htssm:Mlb_leadb:M3b:MT2W:topness:hadronic_top_chi2 - v2
      if(lele){
	POel.push_back(PO);
	//	cout << "TEST Ele " << fixed << setprecision(4) << run() << " " << evt() << " " << lpt << " " << lpdg << endl;
	//*fLogStreamEl << " " << fixed << setprecision(4) << run() << " " << ls() << " " << evt() << " " << lep1_pt() << " " << lep1_pdgid() << " " << pfmet() << " " << mt_met_lep() << " " << ngoodjets() << " " << ngoodbtags() 
	//	      << " " << genlepsfromtop() << " " << dphi_Wlep() << " " << ak4_htssm() << " " << Mlb_closestb() << " " << M3b() << " " << MT2W() << " " << topness() << " " << hadronic_top_chi2() << endl;
	//*fLogStreamEl << " " << fixed << setprecision(4) << run() << " " << setw(4) << ls() << " " << setw(7) << evt() << " " << setw(8) << lep1_pt() << " " << setw(3) << lep1_pdgid() << " " << setw(9)
	//	      << pfmet() << " " << setw(9) << mt_met_lep() << " " << setw(2) << ngoodjets() << " " << setw(1) << ngoodbtags() << " " << setw(1) << genlepsfromtop() << " " << setw(6)
	//	      << dphi_Wlep() << " " << setw(9) << ak4_htssm() << " " << setw(9) << Mlb_closestb() << " " << setw(9) << M3b() << " " << setw(9) << MT2W() << " " << setw(9) << topness() << " " << setw(9) << hadronic_top_chi2() << endl;
      }
      if(lmuo){
	POmu.push_back(PO);
	//	cout << "TEST Muo " << fixed << setprecision(4) << run() << " " << evt() << " " << lpt << " " << lpdg << endl;
	//*fLogStreamMu << " " << fixed << setprecision(4) << run() << " " << ls() << " " << evt() << " " << lep1_pt() << " " << lep1_pdgid() << " " << pfmet() << " " << mt_met_lep() << " " << ngoodjets() << " " << ngoodbtags() 
	//	      << " " << genlepsfromtop() << " " << dphi_Wlep() << " " << ak4_htssm() << " " << Mlb_closestb() << " " << M3b() << " " << MT2W() << " " << topness() << " " << hadronic_top_chi2() << endl;
	//*fLogStreamMu << " " << fixed << setprecision(4) << run() << " " << setw(4) << ls() << " " << setw(7) << evt() << " " << setw(8) << lep1_pt() << " " << setw(3) << lep1_pdgid() << " " << setw(9)
	//	      << pfmet() << " " << setw(9) << mt_met_lep() << " " << setw(2) << ngoodjets() << " " << setw(1) << ngoodbtags() << " " << setw(1) << genlepsfromtop() << " " << setw(6)
	//	      << dphi_Wlep() << " " << setw(9) << ak4_htssm() << " " << setw(9) << Mlb_closestb() << " " << setw(9) << M3b() << " " << setw(9) << MT2W() << " " << setw(9) << topness() << " " << setw(9) << hadronic_top_chi2() << endl;
      }
      if(mt_met_lep()<120) continue; ++cmt;
      if(mindphi_met_j1_j2()<0.8) continue; ++cmdphi;
      if(hadronic_top_chi2()>5) continue; ++cchi;


    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  //std::sort(POel.begin(), POel.end(), &SortPrintOut);
  //std::sort(POmu.begin(), POmu.end(), &SortPrintOut);

  for(unsigned int n=0; n<POel.size();++n){
    PrintOut p = POel[n];
    *fLogStreamEl << " " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
      //<< " " << setw(8) << p.lepminiIso
		  << " " << setw(3) << p.leppdgid << " " << setw(9)
		  << p.met << " " << setw(9) << p.mt
		  << " " << setw(1) << p.trackveto
		  << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
		  << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
  }
    for(unsigned int n=0; n<POmu.size();++n){
    PrintOut p = POmu[n];
    *fLogStreamMu << " " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
      //<< " " << setw(8) << p.lepminiIso
		  << " " << setw(3) << p.leppdgid << " " << setw(9)
		  << p.met << " " << setw(9) << p.mt
		  << " " << setw(1) << p.trackveto
		  << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
		  << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
  }
    
  //for(unsigned int n=0; n<10;++n){
  //  PrintOut p = POel[n];
  //  cout << " " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(7) << p.Evt << " " << setw(8) << p.leppt << " " << setw(3) << p.leppdgid << " " << setw(9)
  //	 << p.met << " " << setw(9) << p.mt << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
  //	 << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
  //}

  if(fWriteToFile && fAppend){
    TString lognameEl =outputdir + skimFilePrefix+"_el_SnT.txt"; 
    ofstream f_logEl (lognameEl.Data(), ios::app);
    f_logEl << fLogStreamEl->str();
    cout << "wrote results into  " << lognameEl << " (appended at the end of old file)" << endl;
    TString lognameMu =outputdir +skimFilePrefix+"_mu_SnT.txt"; 
    ofstream f_logMu (lognameMu.Data(), ios::app);
    f_logEl << fLogStreamMu->str();
    cout << "wrote results into  " << lognameMu << " (appended at the end of old file)" << endl;
  }else if(fWriteToFile){
    TString lognameEl =outputdir + skimFilePrefix+"_el_SnT.txt"; 
    ofstream f_logEl (lognameEl.Data(), ios::trunc);
    f_logEl << fLogStreamEl->str();
    cout << "wrote results into  " << lognameEl <<  " (old file replaced)" << endl;
    TString lognameMu =outputdir + skimFilePrefix+"_mu_SnT.txt"; 
    ofstream f_logMu (lognameMu.Data(), ios::trunc);
    f_logMu << fLogStreamMu->str();
    cout << "wrote results into  " << lognameMu <<  " (old file replaced)" << endl;
  } else{
    cout << "Electron events:" << endl;
    cout << fLogStreamEl->str();
    cout << endl << "Muon events:" << endl;
    cout << fLogStreamMu->str();
  }
  delete fLogStreamEl;
  delete fLogStreamMu;
  
  // Example Histograms
  // samplehisto->Draw();
  /*
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    h->second->SetBinContent(h->second->GetNbinsX(), h->second->GetBinContent(h->second->GetNbinsX() )+ h->second->GetBinContent(h->second->GetNbinsX()+1) );
    h->second->SetBinError(h->second->GetNbinsX(), sqrt(pow(h->second->GetBinError(h->second->GetNbinsX() ),2)+pow(h->second->GetBinError(h->second->GetNbinsX()+1),2) ) );
  }
  string filename = "rootfiles/MT2MTMassStudies/TestMT2input/HistosFine_"+skimFilePrefix+".root";
  TFile *f = new TFile(filename.c_str(),"RECREATE");
  f->cd();
  for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
  f->Close();
  cout << "Saved histos in " << f->GetName() << endl;
*/
  cout << "For " << skimFilePrefix << ":" << endl;
  cout << "Events passing NVtx>=1: " << c1vtx << endl;
  cout << "Events with one good lepton: " << c1l << endl;
  cout << "Events with one selection lepton: " << cno2l << endl;
  cout << "Events passing track veto: " << cno2track << endl;
  cout << "Events passing tau veto: " << cnotau << endl;
  cout << "Events with at least 4 jets: " << c2j << endl;
  cout << "Events with at least 1 b-jet: " << c1b << endl;
  cout << "Events with MET>80: " << cmet << endl;
  cout << "Events with MT>120: " << cmt << endl;
  cout << "Events with minDPhi>0.8: " << cmdphi << endl;
  cout << "Events with chi2<5: " << cchi << endl;
  
  //cout << endl << "Cutflow" << endl;
  //cout << "Events " << cevtcf << endl << "NVtx>0 " << cvtxcf << endl << "MET>30 " << cmetcf << endl << "NLeps>0 " << cnlepcf << endl << "NJets>1 " << cnjetcf << endl;

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
