/** \class SingleMuTrigAnalyzerL1RECO
 *
 * See header file for documentation
 *
 *  $Date: 2012/01/30 09:40:35 $
 *  $Revision: 1.1 $
 *
 *  \author Dominick Olivito
 *
 */

#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"
#include "TrigAnalyzer/DilepTrigAnalyzer/interface/SingleMuTrigAnalyzerL1RECO.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/MuonReco/interface/MuonPFIsolation.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"

#include "CondFormats/L1TObjects/interface/L1MuTriggerScales.h"
#include "CondFormats/DataRecord/interface/L1MuTriggerScalesRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuTriggerPtScale.h"
#include "CondFormats/DataRecord/interface/L1MuTriggerPtScaleRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuGMTScales.h"
#include "CondFormats/DataRecord/interface/L1MuGMTScalesRcd.h"

// ROOT includes
#include "TVector2.h"
#include "TMath.h"
#include "Math/VectorUtil.h"

#include <cassert>

using namespace reco;
using namespace edm;

//
// constructors and destructor
//
//____________________________________________________________________________
SingleMuTrigAnalyzerL1RECO::SingleMuTrigAnalyzerL1RECO(const edm::ParameterSet& ps) : 
  processName_(ps.getParameter<std::string>("processName")),
  triggerName_(ps.getParameter<std::string>("triggerName")),
  triggerResultsTag_(ps.getParameter<edm::InputTag>("triggerResults")),
  triggerEventTag_(ps.getParameter<edm::InputTag>("triggerEvent")),
  muonsInputTag_(ps.getParameter<edm::InputTag>("muonsInputTag")),
  vtxInputTag_(ps.getParameter<edm::InputTag>("vtxInputTag")),
  l1MuonsTag_(ps.getParameter<edm::InputTag>("l1Muons")),
  printL1MuonScales_(ps.getParameter<bool>("printL1MuonScales")),
  verbose_(ps.getParameter<bool>("verbose"))
{
  using namespace std;
  using namespace edm;

  cout << "SingleMuTrigAnalyzerL1RECO configuration: " << endl
       << "   ProcessName = " << processName_ << endl
       << "   triggerName = " << triggerName_ << endl
       << "   TriggerResultsTag = " << triggerResultsTag_.encode() << endl
       << "   TriggerEventTag = " << triggerEventTag_.encode() << endl
       << "   MuonsInputTag = " << muonsInputTag_.encode() << endl
       << "   VtxInputTag = " << vtxInputTag_.encode() << endl
       << "   L1MuonsTag = " << l1MuonsTag_.encode() << endl
       << "   PrintL1MuonScales = " << printL1MuonScales_ << endl
       << "   Verbose = " << verbose_ << endl;

  // histogram setup
  edm::Service<TFileService> fs;
  hists_1d_["h_pt_l1"] = fs->make<TH1F>("h_pt_l1" , "; L1 p_{T} [GeV]" , 25, 0.,100. );
  hists_1d_["h_pt_reco"] = fs->make<TH1F>("h_pt_reco" , "; reco p_{T} [GeV]" , 25, 0.,100. );
  hists_1d_["h_eta_l1"] = fs->make<TH1F>("h_eta_l1" , "; L1 #eta" , 25, -2.5,2.5 );
  hists_1d_["h_eta_reco"] = fs->make<TH1F>("h_eta_reco" , "; reco #eta" , 25, -2.5,2.5 );
  hists_1d_["h_eta_l1_fine"] = fs->make<TH1F>("h_eta_l1_fine" , "; L1 #eta" , 200, -2.5,2.5 );
  hists_1d_["h_eta_reco_fine"] = fs->make<TH1F>("h_eta_reco_fine" , "; reco #eta" , 200, -2.5,2.5 );
  hists_1d_["h_phi_l1"] = fs->make<TH1F>("h_phi_l1" , "; L1 #phi" , 32., -3.2,3.2 );
  hists_1d_["h_phi_reco"] = fs->make<TH1F>("h_phi_reco" , "; reco #phi" , 32., -3.2,3.2 );
  
  hists_1d_["h_dR_l1reco"] = fs->make<TH1F>("h_dR_l1reco" , "; L1-reco #Delta{R}" , 44., 0,1.1 );
  //hists_1d_["h_deta_l1reco"] = fs->make<TH1F>("h_deta_l1reco" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  hists_1d_["h_deta_l1reco"] = fs->make<TH1F>("h_deta_l1reco" , "; L1 #eta - reco #eta" , 70., -1.05,1.05 );
  hists_1d_["h_dphi_l1reco"] = fs->make<TH1F>("h_dphi_l1reco" , "; L1 #phi - reco #phi" , 50., -1.,1. );
  //hists_1d_["h_goodptphi_deta_l1reco"] = fs->make<TH1F>("h_goodptphi_dphi_l1reco" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  //hists_1d_["h_verygoodptphi_deta_l1reco"] = fs->make<TH1F>("h_verygoodptphi_dphi_l1reco" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  hists_1d_["h_goodptphi_deta_l1reco"] = fs->make<TH1F>("h_goodptphi_deta_l1reco" , "; L1 #eta - reco #eta" , 70., -1.05,1.05 );
  hists_1d_["h_verygoodptphi_deta_l1reco"] = fs->make<TH1F>("h_verygoodptphi_deta_l1reco" , "; L1 #eta - reco #eta" , 70., -1.05,1.05 );
  
  hists_2d_["h_l1pt_recopt"] = fs->make<TH2F>("h_l1pt_recopt" , "; L1 p_{T} [GeV]; reco p_{T} [GeV]" , 50 , 0. , 100., 50, 0., 100. );
  hists_2d_["h_l1eta_recoeta"] = fs->make<TH2F>("h_l1eta_recoeta" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  hists_2d_["h_l1phi_recophi"] = fs->make<TH2F>("h_l1phi_recophi" , "; L1 #phi; reco #phi" , 120 , -3.5 , 3.5, 120, -3.5, 3.5 );
  hists_2d_["h_goodptphi_l1eta_recoeta"] = fs->make<TH2F>("h_goodptphi_l1eta_recoeta" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  hists_2d_["h_verygoodptphi_l1eta_recoeta"] = fs->make<TH2F>("h_verygoodptphi_l1eta_recoeta" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  //hists_2d_["h_deta_dphi_l1reco"] = fs->make<TH2F>("h_deta_dphi_l1reco" , "; L1 #eta - reco #eta; L1 #phi - reco #phi" , 50., -1.,1., 50., -1.,1. );
  hists_2d_["h_deta_dphi_l1reco"] = fs->make<TH2F>("h_deta_dphi_l1reco" , "; L1 #eta - reco #eta; L1 #phi - reco #phi" , 70., -1.05,1.05, 50., -1.,1. );
  hists_2d_["h_deta_dphi_accept"] = fs->make<TH2F>("h_deta_dphi_accept" , "; pass #Delta(L1 #eta,reco #eta)<0.15; pass #Delta(L1 #phi,reco #phi)<0.2" , 2,0.,2.,2,0.,2. );
  hists_2d_["h_deta_dphi_accept_etarestrict"] = fs->make<TH2F>("h_deta_dphi_accept_etarestrict" , "; pass #Delta(L1 #eta,reco #eta)<0.15; pass #Delta(L1 #phi,reco #phi)<0.2" , 2,0.,2.,2,0.,2. );

  hists_1d_["h_dR_l1reco_etarestrict"] = fs->make<TH1F>("h_dR_l1reco_etarestrict" , "; L1-reco #Delta{R}" , 44., 0,1.1 );
  //hists_1d_["h_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_deta_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  hists_1d_["h_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_deta_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  hists_1d_["h_dphi_l1reco_etarestrict"] = fs->make<TH1F>("h_dphi_l1reco_etarestrict" , "; L1 #phi - reco #phi" , 50., -1.,1. );
  //hists_1d_["h_goodptphi_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_goodptphi_dphi_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  //hists_1d_["h_verygoodptphi_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_verygoodptphi_dphi_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 50., -1.,1. );
  hists_1d_["h_goodptphi_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_goodptphi_deta_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 70., -1.05,1.05 );
  hists_1d_["h_verygoodptphi_deta_l1reco_etarestrict"] = fs->make<TH1F>("h_verygoodptphi_deta_l1reco_etarestrict" , "; L1 #eta - reco #eta" , 70., -1.05,1.05 );

  hists_2d_["h_l1pt_recopt_etarestrict"] = fs->make<TH2F>("h_l1pt_recopt_etarestrict" , "; L1 p_{T} [GeV]; reco p_{T} [GeV]" , 50 , 0. , 100., 50, 0., 100. );
  hists_2d_["h_l1eta_recoeta_etarestrict"] = fs->make<TH2F>("h_l1eta_recoeta_etarestrict" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  hists_2d_["h_l1phi_recophi_etarestrict"] = fs->make<TH2F>("h_l1phi_recophi_etarestrict" , "; L1 #phi; reco #phi" , 120 , -3.5 , 3.5, 120, -3.5, 3.5 );
  hists_2d_["h_goodptphi_l1eta_recoeta_etarestrict"] = fs->make<TH2F>("h_goodptphi_l1eta_recoeta_etarestrict" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  hists_2d_["h_verygoodptphi_l1eta_recoeta_etarestrict"] = fs->make<TH2F>("h_verygoodptphi_l1eta_recoeta_etarestrict" , "; L1 #eta; reco #eta" , 120 , -3. , 3., 120, -3., 3. );
  //hists_2d_["h_deta_dphi_l1reco_etarestrict"] = fs->make<TH2F>("h_deta_dphi_l1reco_etarestrict" , "; L1 #eta - reco #eta; L1 #phi - reco #phi" , 50., -1.,1., 50., -1.,1. );
  hists_2d_["h_deta_dphi_l1reco_etarestrict"] = fs->make<TH2F>("h_deta_dphi_l1reco_etarestrict" , "; L1 #eta - reco #eta; L1 #phi - reco #phi" , 70., -1.05,1.05, 50., -1.,1. );

}

//____________________________________________________________________________
SingleMuTrigAnalyzerL1RECO::~SingleMuTrigAnalyzerL1RECO()
{
}

//
// member functions
//
//____________________________________________________________________________
void
SingleMuTrigAnalyzerL1RECO::beginRun(edm::Run const & iRun, edm::EventSetup const& iSetup)
{
  using namespace std;
  using namespace edm;

  bool changed(true);
  if (hltConfig_.init(iRun,iSetup,processName_,changed)) {
    if (changed) {
      const unsigned int n(hltConfig_.size());
      // check if trigger names in (new) config
      unsigned int triggerIndex(hltConfig_.triggerIndex(triggerName_));
      if (triggerIndex>=n) {
	cout << "SingleMuTrigAnalyzerL1RECO::analyze:"
	     << " TriggerName " << triggerName_ 
	     << " not available in (new) config!" << endl;
      }
    } // if changed
  } else {
    cout << "SingleMuTrigAnalyzerL1RECO::analyze:"
	 << " config extraction failure with process name "
	 << processName_ << endl;
  }

}

//____________________________________________________________________________
// ------------ method called to produce the data  ------------
void
SingleMuTrigAnalyzerL1RECO::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace std;
  using namespace edm;

  if (verbose_) cout << endl;

  // get event products
  iEvent.getByLabel(triggerResultsTag_,triggerResultsHandle_);
  if (!triggerResultsHandle_.isValid()) {
    cout << "SingleMuTrigAnalyzerL1RECO::analyze: Error in getting TriggerResults product from Event!" << endl;
    return;
  }
  iEvent.getByLabel(triggerEventTag_,triggerEventHandle_);
  if (!triggerEventHandle_.isValid()) {
    cout << "SingleMuTrigAnalyzerL1RECO::analyze: Error in getting TriggerEvent product from Event!" << endl;
    return;
  }

  // sanity check
  assert(triggerResultsHandle_->size()==hltConfig_.size());

  // retrieve necessary containers
  iEvent.getByLabel(vtxInputTag_, vertexHandle_);
  iEvent.getByLabel( muonsInputTag_ , musHandle_ );
  iEvent.getByLabel(l1MuonsTag_, l1MuonsHandle_);
  
  analyzeTrigger(iEvent, iSetup, triggerName_);
  
  if (printL1MuonScales_) {

    const char* detnam[]={ "DT", "RPC barrel", "CSC", "RPC forward" };

    ESHandle< L1MuTriggerScales > l1muscales ;
    iSetup.get< L1MuTriggerScalesRcd >().get( l1muscales ) ;

    ESHandle< L1MuTriggerPtScale > l1muptscale ;
    iSetup.get< L1MuTriggerPtScaleRcd >().get( l1muptscale ) ;

    cout << "**** L1 Mu Pt Scale print *****************************************" << endl;
    printScale(l1muptscale->getPtScale());

    cout << "**** L1 Mu Phi Scale print *****************************************" << endl;
    printScale(l1muscales->getPhiScale());

    cout << "**** L1 Mu GMT eta Scale print *************************************" << endl;
    printScale(l1muscales->getGMTEtaScale());

    for(int i=0; i<4; i++) {

      cout << "**** L1 Mu " << detnam[i] << " eta Scale print **************************************" << endl;
      printScale(l1muscales->getRegionalEtaScale(i));

    }

    ESHandle< L1MuGMTScales > l1gmtscales ;
    iSetup.get< L1MuGMTScalesRcd >().get( l1gmtscales ) ;

    for(int i=0; i<4; i++) {

      cout << "**** L1 GMT " << detnam[i] << " reduced eta Scale print **************************************" << endl;
      printScale(l1gmtscales->getReducedEtaScale(i));

    }

    cout << "**** L1 GMT delta eta Scale print *************************************" << endl;
    printScale(l1gmtscales->getDeltaEtaScale(0));

    cout << "**** L1 GMT delta phi Scale print *************************************" << endl;
    printScale(l1gmtscales->getDeltaPhiScale());

    for(int i=0; i<4; i++) {

      cout << "**** L1 GMT " << detnam[i] << " overlap eta Scale print **************************************" << endl;
      printScale(l1gmtscales->getOvlEtaScale(i));

    }
  } // if printL1MuonScales

  // loop over L1 muons and dump eta information

  // loop over offline muons and dump info
  
  if (verbose_) cout << endl;

  return;
}

//____________________________________________________________________________

bool SingleMuTrigAnalyzerL1RECO::analyzeTrigger(const edm::Event& iEvent, const edm::EventSetup& iSetup, const std::string& triggerName) {
  
  using namespace std;
  using namespace edm;
  using namespace reco;
  using namespace trigger;
  using namespace l1extra;

  if (verbose_) cout << endl;

  const unsigned int ntrigs(hltConfig_.size());
  const unsigned int triggerIndex(hltConfig_.triggerIndex(triggerName));
  assert(triggerIndex==iEvent.triggerNames(*triggerResultsHandle_).triggerIndex(triggerName));

  // abort on invalid trigger name
  if (triggerIndex>=ntrigs) {
    cout << "SingleMuTrigAnalyzerL1RECO::analyzeTrigger: path "
	 << triggerName << " - not found!" << endl;
    return false;
  }

  if (verbose_) {
    cout << "SingleMuTrigAnalyzerL1RECO::analyzeTrigger: path "
	 << triggerName << " [" << triggerIndex << "]" << endl;
  }
  // modules on this trigger path
  const unsigned int m(hltConfig_.size(triggerIndex));
  const vector<string>& moduleLabels(hltConfig_.moduleLabels(triggerIndex));

  bool wasRun = triggerResultsHandle_->wasrun(triggerIndex);
  bool accept = triggerResultsHandle_->accept(triggerIndex);
  bool error = triggerResultsHandle_->error(triggerIndex);
  const unsigned int moduleIndex(triggerResultsHandle_->index(triggerIndex));
  // Results from TriggerResults product
  if (verbose_) {
    cout << " Trigger path status:"
	 << " WasRun=" << wasRun
	 << " Accept=" << accept
	 << " Error =" << error
	 << endl;
    cout << " Last active module - label/type: "
	 << moduleLabels[moduleIndex] << "/" << hltConfig_.moduleType(moduleLabels[moduleIndex])
	 << " [" << moduleIndex << " out of 0-" << (m-1) << " on this path]"
	 << endl;
  }
  assert (moduleIndex<m);

  //  if (!wasRun || !accept || error) return false;
  if (!wasRun || error) return false;

  // loop over trigger and reco objects, match, make plots

  // first, get trigger objects from last filter

  //------------------------------------
  //  hlt objects
  //------------------------------------

  bool foundMuons = false;
  std::vector<LorentzVector> trigMuons;
  std::vector<LorentzVector> trigMuons2;

    // --------- code for triggerEvent, instead of triggerEventWithRefs -------------------

  for (unsigned int j=moduleIndex; j!=0; --j) {
    const string& moduleLabel(moduleLabels[j]);
    const string  moduleType(hltConfig_.moduleType(moduleLabel));
    // check whether the module is packed up in TriggerEvent product
    const unsigned int filterIndex(triggerEventHandle_->filterIndex(InputTag(moduleLabel,"",processName_)));
    if (filterIndex>=triggerEventHandle_->sizeFilters()) continue;
    //if (filterIndex>=triggerEventHandle_->size()) continue;
    if (verbose_) {
      cout << " 'L3' filter in slot " << j << " - label/type " << moduleLabel << "/" << moduleType << endl
	   << " Filter packed up at: " << filterIndex << endl;
    }
    if (moduleLabel == "hltBoolEnd") continue;
    const Vids& VIDS (triggerEventHandle_->filterIds(filterIndex));
    const Keys& KEYS(triggerEventHandle_->filterKeys(filterIndex));
    const size_type nI(VIDS.size());
    const size_type nK(KEYS.size());
    assert(nI==nK);
    const size_type n(max(nI,nK));
    if (verbose_) cout << "   " << n  << " accepted 'L3' objects found: " << endl;
    const TriggerObjectCollection& TOC(triggerEventHandle_->getObjects());
    for (size_type i=0; i!=n; ++i) {
      const TriggerObject& TO(TOC[KEYS[i]]);
      LorentzVector lv( TO.particle().p4() );

      // muons
      if (!foundMuons && (VIDS[i] == 83)) {
	trigMuons.push_back(lv);
      } // hlt muons

      if (verbose_) {
    	cout << "   " << i << " " << VIDS[i] << "/" << KEYS[i] << ": "
    	     << TO.id() << " " << TO.pt() << " " << TO.eta() << " " << TO.phi() << " " << TO.mass()
    	     << endl;
      }
    } // loop on trig objects

    if (trigMuons.size() > 0) {
      foundMuons = true;
    }

    if (foundMuons) break;
  } // backwards loop on modules

  if (accept && trigMuons.size() == 0) {
    cout << "SingleMuTrigAnalyzerL1RECO::analyzeTrigger: WARNING!! no valid trigger leptons!" << endl;
  }

  //-------------------------------------
  //   reco vertices
  //-------------------------------------

  // find vertex 0 in vertex container
  const VertexCollection* vertexCollection = vertexHandle_.product();
  VertexCollection::const_iterator firstGoodVertex = vertexCollection->end();
  int nvtx = 0;
  for ( VertexCollection::const_iterator vtx = vertexCollection->begin(); vtx != vertexCollection->end(); ++vtx ) {
    if (  !vtx->isFake() && vtx->ndof()>=4. && vtx->position().Rho()<=2.0 && fabs(vtx->position().Z())<=24.0 ) {
      if (firstGoodVertex == vertexCollection->end()) firstGoodVertex = vtx;
      ++nvtx;
    }
  } // loop on vertices

  if (firstGoodVertex == vertexCollection->end()) {
    cout << "SingleMuTrigAnalyzerRECO::analyzeTrigger: didn't find any good offline vertices!! size: " 
	 << vertexCollection->size() << std::endl;
    return accept;
  }

  //-------------------------------------
  //   reco muons 
  //-------------------------------------

  const float dr_trigmatch = 0.2;

  MuonCollection muons_good;
  MuonCollection muons_dup;

  // loop first to remove duplicate muons..
  unsigned int muonIndex = 0;
  MuonCollection::const_iterator muons_end = musHandle_->end();  // Iterator

  for ( MuonCollection::const_iterator muon = musHandle_->begin(); muon != muons_end; ++muon, ++muonIndex ) {
    LorentzVector lv(muon->p4());

    bool pass_tight = muon::isTightMuon(*muon,*firstGoodVertex);
    //    float trkiso = muon->pfIsolationR03().sumChargedHadronPt;
    float pfiso = muonPFiso(*muon);
    bool pass_iso_tight = bool(pfiso/lv.pt() < 0.15);

    // require Tight + Iso + pt > 25
    if (lv.pt() < 25. || !pass_tight || !pass_iso_tight) continue;
    
    // check match to trigger objects
    bool trigmatch = false;
    //    int trigmatch_idx = -1;
    if (accept) {
      for (unsigned int itrig=0; itrig < trigMuons.size(); ++itrig) {
	if (ROOT::Math::VectorUtil::DeltaR(lv,trigMuons.at(itrig)) < dr_trigmatch) {
	  trigmatch = true;
	  //	  trigmatch_idx = itrig;
	}
      } // loop over trig muons
    } // trigger accept

    // make plots for muons that pass offline cuts and fail trigger
    if (trigmatch) continue;

    // find closest L1 muon using L1 extra particles (may need GMT candidates?)
    L1MuonParticleCollection::const_iterator l1mus_end = l1MuonsHandle_->end();
    float mindr_l1 = 99.;
    //    int index_match_l1 = -1;
    int index_l1 = 0;
    LorentzVector lv_l1;
    for ( L1MuonParticleCollection::const_iterator l1mu = l1MuonsHandle_->begin(); l1mu != l1mus_end; ++l1mu ) {
      // check L1 pt
      //      if (l1mu->pt() < 15.) continue;
      float dr = ROOT::Math::VectorUtil::DeltaR(lv,l1mu->p4());
      if (dr < mindr_l1) {
	mindr_l1 = dr;
	//	index_match_l1 = index_l1;
	lv_l1 = l1mu->p4();
      }
      ++index_l1;
    } // loop over l1mus

    if (mindr_l1 < 1.0) {

      hists_1d_["h_pt_l1"]->Fill(lv_l1.pt());
      hists_1d_["h_pt_reco"]->Fill( lv.pt());
      hists_1d_["h_eta_l1"]->Fill(lv_l1.eta());
      hists_1d_["h_eta_reco"]->Fill( lv.eta());
      hists_1d_["h_eta_l1_fine"]->Fill(lv_l1.eta());
      hists_1d_["h_eta_reco_fine"]->Fill( lv.eta());
      hists_1d_["h_phi_l1"]->Fill(lv_l1.phi());
      hists_1d_["h_phi_reco"]->Fill( lv.phi());
      
      float dr = ROOT::Math::VectorUtil::DeltaR(lv,lv_l1);
      hists_1d_["h_dR_l1reco"]->Fill(dr);

      float dphi = TVector2::Phi_mpi_pi(lv_l1.phi() - lv.phi());

      hists_1d_["h_deta_l1reco"]->Fill(lv_l1.eta() - lv.eta());
      hists_1d_["h_dphi_l1reco"]->Fill(dphi);

      hists_2d_["h_l1pt_recopt"]->Fill(lv_l1.pt(),lv.pt());
      hists_2d_["h_l1eta_recoeta"]->Fill(lv_l1.eta(),lv.eta());
      hists_2d_["h_l1phi_recophi"]->Fill(lv_l1.phi(),lv.phi());
      hists_2d_["h_deta_dphi_l1reco"]->Fill(lv_l1.eta() - lv.eta(),dphi);//new
      if(fabs(dphi)<0.2&&fabs(lv_l1.eta() - lv.eta())<0.15) hists_2d_["h_deta_dphi_accept"]->Fill(1.5,1.5);
      else if(fabs(dphi)<0.2) hists_2d_["h_deta_dphi_accept"]->Fill(0.5,1.5);
      else if(fabs(lv_l1.eta() - lv.eta())<0.15) hists_2d_["h_deta_dphi_accept"]->Fill(1.5,0.5);
      else hists_2d_["h_deta_dphi_accept"]->Fill(0.5,0.5);
      if(lv.Pt()>24.&&lv.Eta()>=(-0.4)&&lv.Eta()<=0.){
	hists_1d_["h_dR_l1reco_etarestrict"]->Fill(dr);
	hists_1d_["h_deta_l1reco_etarestrict"]->Fill(lv_l1.eta() - lv.eta());
	hists_1d_["h_dphi_l1reco_etarestrict"]->Fill(dphi);
	hists_2d_["h_l1pt_recopt_etarestrict"]->Fill(lv_l1.pt(),lv.pt());
	hists_2d_["h_l1eta_recoeta_etarestrict"]->Fill(lv_l1.eta(),lv.eta());
	hists_2d_["h_l1phi_recophi_etarestrict"]->Fill(lv_l1.phi(),lv.phi());
	hists_2d_["h_deta_dphi_l1reco_etarestrict"]->Fill(lv_l1.eta() - lv.eta(),dphi);//new
	if(fabs(dphi)<0.2&&fabs(lv_l1.eta() - lv.eta())<0.15) hists_2d_["h_deta_dphi_accept_etarestrict"]->Fill(1.5,1.5);
	else if(fabs(dphi)<0.2) hists_2d_["h_deta_dphi_accept_etarestrict"]->Fill(0.5,1.5);
	else if(fabs(lv_l1.eta() - lv.eta())<0.15) hists_2d_["h_deta_dphi_accept_etarestrict"]->Fill(1.5,0.5);
	else hists_2d_["h_deta_dphi_accept_etarestrict"]->Fill(0.5,0.5);
	if (lv_l1.pt() > 15. && fabs(dphi) < 0.2) {
	  hists_2d_["h_goodptphi_l1eta_recoeta_etarestrict"]->Fill(lv_l1.eta(),lv.eta());
	  hists_1d_["h_goodptphi_deta_l1reco_etarestrict"]->Fill(lv_l1.eta() - lv.eta());
	}
	if ( (lv_l1.pt()/lv.pt()) > (2./3.) && (lv_l1.pt()/lv.pt()) < 1.5 && fabs(dphi) < 0.2) {
	  hists_2d_["h_verygoodptphi_l1eta_recoeta_etarestrict"]->Fill(lv_l1.eta(),lv.eta());
	  hists_1d_["h_verygoodptphi_deta_l1reco_etarestrict"]->Fill(lv_l1.eta() - lv.eta());
	}
      }

      // check l1mu pt and dphi
      if (lv_l1.pt() > 15. && fabs(dphi) < 0.2) {
	hists_2d_["h_goodptphi_l1eta_recoeta"]->Fill(lv_l1.eta(),lv.eta());
	hists_1d_["h_goodptphi_deta_l1reco"]->Fill(lv_l1.eta() - lv.eta());
      }
      if ( (lv_l1.pt()/lv.pt()) > (2./3.) && (lv_l1.pt()/lv.pt()) < 1.5 && fabs(dphi) < 0.2) {
	hists_2d_["h_verygoodptphi_l1eta_recoeta"]->Fill(lv_l1.eta(),lv.eta());
	hists_1d_["h_verygoodptphi_deta_l1reco"]->Fill(lv_l1.eta() - lv.eta());
      }
    }
    
  } // loop on reco muons

  // //-------------------------------------
  // //   compare to gen level
  // //-------------------------------------

  // const float dr_trigmatch = 0.2;

  // GenParticleCollection::const_iterator genps_end = genParticlesHandle_->end();  // Iterator
  // for ( GenParticleCollection::const_iterator genp = genParticlesHandle_->begin(); genp != genps_end; ++genp ) {
  //   // can use status 3 for pythia 6
  //   //      if (genp->status() != 3) continue;
  //   // allow status 23 for pythia 8
  //   if ((genp->status() != 1) && (genp->status() != 23)) continue;
  //   if (abs(genp->pdgId()) != 11) continue;
  //   // W mother
  //   if (abs(genp->mother()->pdgId()) != 24) continue;

  //   // pt, eta acceptance cuts
  //   if ((genp->pt() > genPt_) && (fabs(genp->eta()) < genEta_)) {

  //     LorentzVector lv(genp->p4());

  //     bool trigmatch = false;
  //     if (accept) {
  // 	for (unsigned int itrig=0; itrig < trigMuons.size(); ++itrig) {
  // 	  if (ROOT::Math::VectorUtil::DeltaR(lv,trigMuons.at(itrig)) < dr_trigmatch) trigmatch = true;
  // 	}
  //     }

  //     fillHistsGen(lv,"gen");
  //     if (trigmatch) {
  // 	fillHistsGen(lv,"gen_match");
  //     } else {
  // 	fillHistsGen(lv,"gen_nomatch");
  //     }

  //   } // in acceptance

  // } // loop over genps

  return accept;
}

//____________________________________________________________________________
void SingleMuTrigAnalyzerL1RECO::printScale(const L1MuScale* l1muscale) {

  std::cout << l1muscale->print();

}

//____________________________________________________________________________
float SingleMuTrigAnalyzerL1RECO::muonPFiso(const reco::Muon& muon) {

  reco::MuonPFIsolation pfStructR03 = muon.pfIsolationR03();
  float chiso = pfStructR03.sumChargedHadronPt;
  float nhiso = pfStructR03.sumNeutralHadronEt;
  float emiso = pfStructR03.sumPhotonEt;
  float deltaBeta = pfStructR03.sumPUPt;

  //  float absiso = chiso + nhiso + emiso;
  float absiso = chiso + std::max(0.0, nhiso + emiso - 0.5 * deltaBeta);
  return absiso;

}
