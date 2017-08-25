# test reco and dump into a tree

import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.parseArguments()

process = cms.Process('AdvancedMultifit')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
)

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(10000)

process.TFileService = cms.Service("TFileService",
     fileName = cms.string(options.outputFile)
)

process.options = cms.untracked.PSet(
#    SkipEvent = cms.untracked.vstring('ProductNotFound'),
)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('reco nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '92X_dataRun2_Prompt_v8', '')
process.GlobalTag = GlobalTag(process.GlobalTag, '90X_upgrade2017_realistic_v20', '')



process.load('RecoLocalCalo.EcalRecProducers.ecalMultiFitUncalibRecHit_cfi')
process.ecalMultiFitUncalibRecHit.EBdigiCollection = cms.InputTag("selectDigi","selectedEcalEBDigiCollection")
process.ecalMultiFitUncalibRecHit.EEdigiCollection = cms.InputTag("selectDigi","selectedEcalEEDigiCollection")
process.ecalMultiFitUncalibRecHit.algoPSet.useLumiInfoRunHeader = cms.bool(False)


process.TreeProducer = cms.EDAnalyzer('TreeProducer',

                           EBDigiCollection = cms.InputTag("selectDigi","selectedEcalEBDigiCollection"),
                           EEDigiCollection = cms.InputTag("selectDigi","selectedEcalEEDigiCollection"),

                           EcalUncalibRecHitsEBCollection = cms.InputTag("ecalMultiFitUncalibRecHit","EcalUncalibRecHitsEB"),
                           EcalUncalibRecHitsEECollection = cms.InputTag("ecalMultiFitUncalibRecHit","EcalUncalibRecHitsEE"),
                           #EcalUncalibRecHitsEBCollection = cms.InputTag("ecalRecHit",  "EcalRecHitsEB"),
                           #EcalUncalibRecHitsEECollection = cms.InputTag("ecalRecHit",  "EcalRecHitsEE"),

                           )

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(50)

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(options.inputFiles),
                                secondaryFileNames = cms.untracked.vstring()
                                )
                                                    

process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction)

process.ecalDigis_step = cms.Path(process.ecalDigis)
process.multifit = cms.Path(process.ecalMultiFitUncalibRecHit)


process.TreeProducer_step = cms.Path(process.TreeProducer)
process.endjob_step = cms.EndPath(process.endOfProcess)


process.schedule = cms.Schedule(
                                process.raw2digi_step, 
                                process.reconstruction_step, 
                                process.ecalDigis_step,
                                process.multifit,
                                process.TreeProducer_step, 
                                process.endjob_step
                                )




