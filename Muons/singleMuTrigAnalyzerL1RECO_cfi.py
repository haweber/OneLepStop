import FWCore.ParameterSet.Config as cms

singleMuTrigAnalyzerL1RECO = cms.EDAnalyzer("SingleMuTrigAnalyzerL1RECO",
    processName = cms.string("HLT"),
    triggerName = cms.string("HLT_IsoTkMu20_v2"),
    triggerResults = cms.InputTag("TriggerResults","","HLT"),
    triggerEvent = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
    muonsInputTag = cms.InputTag("muons"),
    vtxInputTag = cms.InputTag("offlinePrimaryVertices"),
    l1Muons = cms.InputTag("l1extraParticles"),
    printL1MuonScales = cms.bool(False),
    verbose = cms.bool(False)
)
