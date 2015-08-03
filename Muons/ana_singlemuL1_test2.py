import FWCore.ParameterSet.Config as cms

process = cms.Process('HLTANALYZER')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.load('TrigAnalyzer.DilepTrigAnalyzer.singleMuTrigAnalyzerL1RECO_cfi')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring('file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_1.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_2.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_3.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_4.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_5.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_6.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_7.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_8.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_9.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_10.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_11.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_12.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_13.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_14.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_15.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_16.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_17.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_18.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_19.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_20.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_21.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_22.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_23.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_24.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_25.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_26.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_27.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_28.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_29.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_30.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_31.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_32.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_33.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_34.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_35.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_36.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_37.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_38.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_39.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_30.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_41.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_42.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_43.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_44.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_45.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_46.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_47.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_48.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_49.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_50.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_51.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_52.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_53.root',
                                     'file:/hadoop/cms/store/user/haweber/pickevents/runsOtherGt251561__failingTkIsoMuTrigger/pickevents_54.root'),
)


process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('RelVal nevts:100'),
    name = cms.untracked.string('Applications')
)

# Output definition

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('histos_test2.root')
                                   )

### analyzer configuration

process.singleMuTrigAnalyzerL1RECO.triggerName = cms.string("HLT_IsoTkMu20_v2")
process.singleMuTrigAnalyzerL1RECO.printL1MuonScales = cms.bool(False)
process.singleMuTrigAnalyzerL1RECO.verbose = cms.bool(False)

process.GlobalTag.globaltag = "74X_dataRun2_Prompt_v0"

# Path and EndPath definitions
process.HLTanalyzers = cms.Path(process.singleMuTrigAnalyzerL1RECO)
