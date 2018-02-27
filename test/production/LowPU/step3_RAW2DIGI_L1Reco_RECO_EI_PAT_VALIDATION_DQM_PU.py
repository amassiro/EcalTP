# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step3 --conditions 92X_upgrade2017_realistic_Candidate_forECALStudies --pileup_input das:/RelValMinBias_13/CMSSW_9_2_3-92X_upgrade2017_realistic_v1_earlyBS2017-v1/GEN-SIM -n 10 --era Run2_2017 --eventcontent RECOSIM,MINIAODSIM,DQM --runUnscheduled -s RAW2DIGI,L1Reco,RECO,EI,PAT,VALIDATION:@standardValidation+@miniAODValidation,DQM:@standardDQM+@miniAODDQM --datatier GEN-SIM-RECO,MINIAODSIM,DQMIO --pileup AVE_35_BX_25ns --geometry DB:Extended
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('RECO',eras.Run2_2017)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
#process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('CommonTools.ParticleFlow.EITopPAG_cff')
process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
process.load('Configuration.StandardSequences.PATMC_cff')
process.load('Configuration.StandardSequences.Validation_cff')
process.load('DQMOffline.Configuration.DQMOfflineMC_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step2_DIGI_L1_DIGI2RAW_HLT.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step3 nevts:10'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-RECO'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_EI_PAT_VALIDATION_DQM_PU.root'),
    outputCommands = process.RECOSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

process.MINIAODSIMoutput = cms.OutputModule("PoolOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(4),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('MINIAODSIM'),
        filterName = cms.untracked.string('')
    ),
    dropMetaData = cms.untracked.string('ALL'),
    eventAutoFlushCompressedSize = cms.untracked.int32(15728640),
    fastCloning = cms.untracked.bool(False),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_EI_PAT_VALIDATION_DQM_PU_inMINIAODSIM.root'),
    outputCommands = process.MINIAODSIMEventContent.outputCommands,
    overrideInputFileSplitLevels = cms.untracked.bool(True)
)

process.DQMoutput = cms.OutputModule("DQMRootOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('DQMIO'),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_EI_PAT_VALIDATION_DQM_PU_inDQM.root'),
    outputCommands = process.DQMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.digitizers = cms.PSet(process.theDigitizersValid)

#process.mix.input.nbPileupEvents.averageNumber = cms.double(35.000000)
#process.mix.bunchspace = cms.int32(25)
#process.mix.minBunch = cms.int32(-12)
#process.mix.maxBunch = cms.int32(3)
#process.mix.input.fileNames = cms.untracked.vstring(['/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/04C3C427-914F-E711-AF53-0CC47A4D7600.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/1C211F06-974F-E711-BFE6-0025905A613C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/66295681-924F-E711-8E47-0025905B8598.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/6CB75CB0-914F-E711-8675-0CC47A78A478.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/945A0CD0-924F-E711-910F-0025905A613C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/CC41BBE9-964F-E711-BE15-0CC47A4C8E96.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/E24452B2-914F-E711-8F1C-0CC47A4D75EC.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/E63C4321-954F-E711-BD43-0CC47A4C8F0C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/F2834728-914F-E711-ABAB-003048FFCBB2.root'])
#process.mix.playback = True
#process.mix.digitizers = cms.PSet()
#for a in process.aliases: delattr(process, a)
#process.RandomNumberGeneratorService.restoreStateLabel=cms.untracked.string("randomEngineStateProducer")

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_A_alpha', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_C_chi_v1', '')


from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '94X_mc2017_realistic_v10', '')

#   
#    Run H
#     
#    EcalPedestals_Run2017H_307017  (mean 200, noise run 307017)
#    EcalLaserAPDPNRatios_Run2017H_307017  
#    EcalTPGLinearizationConst_Run2017H_307017
#    EcalTPGPedestals_Run2017H_307017
#    EcalTPGPhysicsConst_Run2017H_307017_EB_2.5_1.5_EE_2.5_1.5
#    EcalTPGLutIdMap_Run2017H_307017_EB_2.5_1.5_EE_2.5_1.5

   


process.GlobalTag.toGet = cms.VPSet(

     cms.PSet(record = cms.string("EcalLaserAPDPNRatiosRcd"),
                   tag = cms.string("EcalLaserAPDPNRatios_Run2017H_307017"),   
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),

 ##cms.PSet(record = cms.string("EcalPedestalsRcd"),
                   ##tag = cms.string("EcalPedestals_2018extrap_30fb_mc"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),

 cms.PSet(record = cms.string("EcalPedestalsRcd"),
                   tag = cms.string("EcalPedestals_Run2017H_307017"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),

   cms.PSet(record = cms.string("EcalTPGLinearizationConstRcd"),
                   tag = cms.string("EcalTPGLinearizationConst_Run2017H_307017"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
 
   cms.PSet(record = cms.string("EcalTPGPedestalsRcd"),
                   tag = cms.string("EcalTPGPedestals_Run2017H_307017"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),

   cms.PSet(record = cms.string("EcalTPGPhysicsConstRcd"),
                   tag = cms.string("EcalTPGPhysicsConst_Run2017H_307017_EB_2.5_1.5_EE_2.5_1.5"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
   cms.PSet(record = cms.string("EcalTPGLutIdMapRcd"),
                   tag = cms.string("EcalTPGLutIdMap_Run2017H_307017_EB_2.5_1.5_EE_2.5_1.5"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),

)


     
# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.eventinterpretaion_step = cms.Path(process.EIsequence)
process.Flag_trackingFailureFilter = cms.Path(process.goodVertices+process.trackingFailureFilter)
process.Flag_goodVertices = cms.Path(process.primaryVertexFilter)
process.Flag_CSCTightHaloFilter = cms.Path(process.CSCTightHaloFilter)
process.Flag_trkPOGFilters = cms.Path(process.trkPOGFilters)
process.Flag_HcalStripHaloFilter = cms.Path(process.HcalStripHaloFilter)
process.Flag_trkPOG_logErrorTooManyClusters = cms.Path(~process.logErrorTooManyClusters)
process.Flag_EcalDeadCellTriggerPrimitiveFilter = cms.Path(process.EcalDeadCellTriggerPrimitiveFilter)
process.Flag_ecalLaserCorrFilter = cms.Path(process.ecalLaserCorrFilter)
process.Flag_globalSuperTightHalo2016Filter = cms.Path(process.globalSuperTightHalo2016Filter)
process.Flag_eeBadScFilter = cms.Path(process.eeBadScFilter)
process.Flag_METFilters = cms.Path(process.metFilters)
process.Flag_chargedHadronTrackResolutionFilter = cms.Path(process.chargedHadronTrackResolutionFilter)
process.Flag_globalTightHalo2016Filter = cms.Path(process.globalTightHalo2016Filter)
process.Flag_CSCTightHaloTrkMuUnvetoFilter = cms.Path(process.CSCTightHaloTrkMuUnvetoFilter)
process.Flag_HBHENoiseIsoFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseIsoFilter)
process.Flag_BadChargedCandidateSummer16Filter = cms.Path(process.BadChargedCandidateSummer16Filter)
process.Flag_hcalLaserEventFilter = cms.Path(process.hcalLaserEventFilter)
process.Flag_BadPFMuonFilter = cms.Path(process.BadPFMuonFilter)
process.Flag_HBHENoiseFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseFilter)
process.Flag_trkPOG_toomanystripclus53X = cms.Path(~process.toomanystripclus53X)
process.Flag_EcalDeadCellBoundaryEnergyFilter = cms.Path(process.EcalDeadCellBoundaryEnergyFilter)
process.Flag_BadChargedCandidateFilter = cms.Path(process.BadChargedCandidateFilter)
process.Flag_trkPOG_manystripclus53X = cms.Path(~process.manystripclus53X)
process.Flag_BadPFMuonSummer16Filter = cms.Path(process.BadPFMuonSummer16Filter)
process.Flag_muonBadTrackFilter = cms.Path(process.muonBadTrackFilter)
process.Flag_CSCTightHalo2015Filter = cms.Path(process.CSCTightHalo2015Filter)
process.prevalidation_step = cms.Path(process.prevalidation)
process.prevalidation_step1 = cms.Path(process.prevalidationMiniAOD)
process.validation_step = cms.EndPath(process.validation)
process.validation_step1 = cms.EndPath(process.validationMiniAOD)
process.dqmoffline_step = cms.EndPath(process.DQMOffline)
process.dqmoffline_1_step = cms.EndPath(process.DQMOfflineMiniAOD)
process.dqmofflineOnPAT_step = cms.EndPath(process.PostDQMOffline)
process.dqmofflineOnPAT_1_step = cms.EndPath(process.PostDQMOfflineMiniAOD)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)
process.MINIAODSIMoutput_step = cms.EndPath(process.MINIAODSIMoutput)
process.DQMoutput_step = cms.EndPath(process.DQMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.eventinterpretaion_step,process.Flag_HBHENoiseFilter,process.Flag_HBHENoiseIsoFilter,process.Flag_CSCTightHaloFilter,process.Flag_CSCTightHaloTrkMuUnvetoFilter,process.Flag_CSCTightHalo2015Filter,process.Flag_globalTightHalo2016Filter,process.Flag_globalSuperTightHalo2016Filter,process.Flag_HcalStripHaloFilter,process.Flag_hcalLaserEventFilter,process.Flag_EcalDeadCellTriggerPrimitiveFilter,process.Flag_EcalDeadCellBoundaryEnergyFilter,process.Flag_goodVertices,process.Flag_eeBadScFilter,process.Flag_ecalLaserCorrFilter,process.Flag_trkPOGFilters,process.Flag_chargedHadronTrackResolutionFilter,process.Flag_muonBadTrackFilter,process.Flag_BadChargedCandidateFilter,process.Flag_BadPFMuonFilter,process.Flag_BadChargedCandidateSummer16Filter,process.Flag_BadPFMuonSummer16Filter,process.Flag_trkPOG_manystripclus53X,process.Flag_trkPOG_toomanystripclus53X,process.Flag_trkPOG_logErrorTooManyClusters,process.Flag_METFilters,process.prevalidation_step,process.prevalidation_step1,process.validation_step,process.validation_step1,process.dqmoffline_step,process.dqmoffline_1_step,process.dqmofflineOnPAT_step,process.dqmofflineOnPAT_1_step,process.RECOSIMoutput_step,process.MINIAODSIMoutput_step,process.DQMoutput_step)
process.schedule.associate(process.patTask)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from SimGeneral.MixingModule.fullMixCustomize_cff
from SimGeneral.MixingModule.fullMixCustomize_cff import setCrossingFrameOn 

#call to customisation function setCrossingFrameOn imported from SimGeneral.MixingModule.fullMixCustomize_cff
process = setCrossingFrameOn(process)

# End of customisation functions
#do not add changes to your config after this point (unless you know what you are doing)
from FWCore.ParameterSet.Utilities import convertToUnscheduled
process=convertToUnscheduled(process)

# customisation of the process.

# Automatic addition of the customisation function from PhysicsTools.PatAlgos.slimming.miniAOD_tools
from PhysicsTools.PatAlgos.slimming.miniAOD_tools import miniAOD_customizeAllMC 

#call to customisation function miniAOD_customizeAllMC imported from PhysicsTools.PatAlgos.slimming.miniAOD_tools
process = miniAOD_customizeAllMC(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
