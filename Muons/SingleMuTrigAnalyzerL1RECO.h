#ifndef HLTcore_SingleMuTrigAnalyzerL1RECO_h
#define HLTcore_SingleMuTrigAnalyzerL1RECO_h

/** \class SingleMuTrigAnalyzerL1RECO
 *
 *  
 *  This class is an EDAnalyzer analyzing the HLT information for AOD
 *    for single electron triggers (based on HLTEventAnalyzerAOD)
 *
 *  $Date: 2012/01/30 09:40:35 $
 *  $Revision: 1.1 $
 *
 *  \author Dominick Olivito
 *
 */

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TH1.h"
#include "TH2.h"

class L1MuScale;

//
// class declaration
//
class SingleMuTrigAnalyzerL1RECO : public edm::EDAnalyzer {
  
  typedef math::XYZTLorentzVectorF LorentzVector;

 public:
  explicit SingleMuTrigAnalyzerL1RECO(const edm::ParameterSet&);
  ~SingleMuTrigAnalyzerL1RECO();

  virtual void beginRun(edm::Run const &, edm::EventSetup const&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  bool analyzeTrigger(const edm::Event&, const edm::EventSetup&, const std::string& triggerName);

 private:

  void printScale(const L1MuScale*);
  float muonPFiso(const reco::Muon& mu);
  
  /// module config parameters
  std::string   processName_;
  std::string   triggerName_;
  edm::InputTag triggerResultsTag_;
  edm::InputTag triggerEventTag_;
  edm::InputTag muonsInputTag_;
  edm::InputTag vtxInputTag_;
  edm::InputTag l1MuonsTag_;
  bool printL1MuonScales_;
  bool verbose_;

  /// additional class data memebers
  edm::Handle<edm::TriggerResults>           triggerResultsHandle_;
  edm::Handle<trigger::TriggerEvent> triggerEventHandle_;
  HLTConfigProvider hltConfig_;
  edm::Handle<reco::MuonCollection> musHandle_;
  edm::Handle<reco::VertexCollection> vertexHandle_;
  edm::Handle<l1extra::L1MuonParticleCollection> l1MuonsHandle_;

  std::map<std::string,TH1F*> hists_1d_;
  std::map<std::string,TH2F*> hists_2d_;

};
#endif
