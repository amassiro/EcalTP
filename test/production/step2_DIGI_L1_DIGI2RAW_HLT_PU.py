# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step2 --conditions auto:phase1_2017_realistic --pileup_input das:/RelValMinBias_13/CMSSW_9_2_3-92X_upgrade2017_realistic_v1_earlyBS2017-v1/GEN-SIM -n 10 --era Run2_2017 --eventcontent FEVTDEBUGHLT -s DIGI:pdigi_valid,L1,DIGI2RAW,HLT:@relval2017 --datatier GEN-SIM-DIGI-RAW --pileup AVE_35_BX_25ns --geometry DB:Extended
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('HLT',eras.Run2_2017)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
#process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_2e34v22_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')





process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("PoolSource",
    dropDescendantsOfDroppedBranches = cms.untracked.bool(False),
    fileNames = cms.untracked.vstring('file:ZEE_13TeV_TuneCUETP8M1_cfi_GEN_SIM.root'),
    inputCommands = cms.untracked.vstring('keep *', 
        'drop *_genParticles_*_*', 
        'drop *_genParticlesForJets_*_*', 
        'drop *_kt4GenJets_*_*', 
        'drop *_kt6GenJets_*_*', 
        'drop *_iterativeCone5GenJets_*_*', 
        'drop *_ak4GenJets_*_*', 
        'drop *_ak7GenJets_*_*', 
        'drop *_ak8GenJets_*_*', 
        'drop *_ak4GenJetsNoNu_*_*', 
        'drop *_ak8GenJetsNoNu_*_*', 
        'drop *_genCandidatesForMET_*_*', 
        'drop *_genParticlesForMETAllVisible_*_*', 
        'drop *_genMetCalo_*_*', 
        'drop *_genMetCaloAndNonPrompt_*_*', 
        'drop *_genMetTrue_*_*', 
        'drop *_genMetIC5GenJs_*_*'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step2 nevts:10'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.FEVTDEBUGHLToutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-DIGI-RAW'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(10485760),
    fileName = cms.untracked.string('step2_DIGI_L1_DIGI2RAW_HLT.root'),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.digitizers = cms.PSet(process.theDigitizersValid)

#process.mix.input.nbPileupEvents.averageNumber = cms.double(0.000000)
#process.mix.bunchspace = cms.int32(25)
#process.mix.minBunch = cms.int32(-12)
#process.mix.maxBunch = cms.int32(3)
#process.mix.input.fileNames = cms.untracked.vstring(['/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/04C3C427-914F-E711-AF53-0CC47A4D7600.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/1C211F06-974F-E711-BFE6-0025905A613C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/66295681-924F-E711-8E47-0025905B8598.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/6CB75CB0-914F-E711-8675-0CC47A78A478.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/945A0CD0-924F-E711-910F-0025905A613C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/CC41BBE9-964F-E711-BE15-0CC47A4C8E96.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/E24452B2-914F-E711-8F1C-0CC47A4D75EC.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/E63C4321-954F-E711-BD43-0CC47A4C8F0C.root', '/store/relval/CMSSW_9_2_3/RelValMinBias_13/GEN-SIM/92X_upgrade2017_realistic_v1_earlyBS2017-v1/10000/F2834728-914F-E711-ABAB-003048FFCBB2.root'])
#process.mix.digitizers = cms.PSet(process.theDigitizersValid)

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '92X_upgrade2017_realistic_Candidate_forECALStudies', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_A_alpha', '')
process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_C_chi_v1', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_A_alpha_v1', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_B_beta_0fb_v1', '')  # ok, it works
#process.GlobalTag = GlobalTag(process.GlobalTag, '100X_upgrade2018_realistic_forECAL_B_beta_60fb_v1', '')  # ok, it works




#process.GlobalTag = GlobalTag(process.GlobalTag, '94X_mc2017_realistic_v10', '')


process.GlobalTag.toGet = cms.VPSet(

     cms.PSet(record = cms.string("EcalLaserAPDPNRatiosRcd"),
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_30fb_bycr_v5"),   # --> not working
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_30fb_bycr_v4"),    # --> ok, working
                     
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_100fb_bycr_v4"),   #  ok
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_60fb_bycr_v4"),     # ok 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_30fb_bycr_v4"),     # ok 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_0fb_bycr_v4"),   # ok
 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_0fb_bycr_run_v1"),     # no 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_0fb_bycr_run_v2"),     # ok 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_30fb_bycr_run_v2"),     # ok 
                   #tag = cms.string("EcalLaserAPDPNRatios_2018_mc_60fb_bycr_run_v2"),     # no
                   tag = cms.string("EcalLaserAPDPNRatios_2018_mc_60fb_bycr_run_v2c"),     # ok
                   
                    
                   
                   
                   
                   
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),

 ##cms.PSet(record = cms.string("EcalPedestalsRcd"),
                   ##tag = cms.string("EcalPedestals_2018extrap_30fb_mc"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),

 #cms.PSet(record = cms.string("EcalPedestalsRcd"),
                   ##tag = cms.string("EcalPedestals_2018extrap_0fb_mc"),
                   ##tag = cms.string("EcalPedestals_2018extrap_30fb_mc"),
                   #tag = cms.string("EcalPedestals_2018extrap_60fb_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),

   ##cms.PSet(record = cms.string("EcalSRSettingsRcd"),
                   ##tag = cms.string("EcalSRSettings_beam2018_option1_mc"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),

   ##cms.PSet(record = cms.string("EcalTPGLinearizationConstRcd"),
                   ##tag = cms.string("EcalTPGLinearizationConst_2018_mc_30fb_bycr"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),

   #cms.PSet(record = cms.string("EcalTPGLinearizationConstRcd"),
                   ##tag = cms.string("EcalTPGLinearizationConst_2018_mc_0fb_bycr"),
                   ##tag = cms.string("EcalTPGLinearizationConst_2018_mc_30fb_bycr"),
                   #tag = cms.string("EcalTPGLinearizationConst_2018_mc_60fb_bycr"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),


 
   #cms.PSet(record = cms.string("EcalTPGPedestalsRcd"),
                   ##tag = cms.string("EcalTPGPedestals_2018_mc_0fb_bycr"),
                   ##tag = cms.string("EcalTPGPedestals_2018_mc_30fb_bycr"),
                   #tag = cms.string("EcalTPGPedestals_2018_mc_60fb_bycr"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
 
 
 ##cms.PSet(record = cms.string("EcalTPGPedestalsRcd"),
                   ##tag = cms.string("EcalTPGPedestals_2018_mc_30fb_bycr"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),

   ##cms.PSet(record = cms.string("EcalTPGPhysicsConstRcd"),
                   ##tag = cms.string("EcalTPGPhysicsConst_2018_mc_EB_4.0_2.0_EE_4.0_2.0"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),
   ##cms.PSet(record = cms.string("EcalTPGLutIdMapRcd"),
                   ##tag = cms.string("EcalTPGLutIdMap_2018_mc_EB_4.0_2.0_EE_4.0_2.0"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),




   #cms.PSet(record = cms.string("EcalTPGLutIdMapRcd"),
                   #tag = cms.string("EcalTPGLutIdMap_2018_mc_EB_4.0_2.0_EE_3.5_2.0"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),

   #cms.PSet(record = cms.string("EcalTPGPhysicsConstRcd"),
                   #tag = cms.string("EcalTPGPhysicsConst_2018_mc_EB_4.0_2.0_EE_3.5_2.0"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),


   ##cms.PSet(record = cms.string("EcalTPGLutIdMapRcd"),
                   ##tag = cms.string("EcalTPGLutIdMap_2018_mc_EB_3.0_1.5_EE_3.5_2.0"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),


   ##cms.PSet(record = cms.string("EcalTPGLutIdMapRcd"),
                   ##tag = cms.string("EcalTPGLutIdMap_2018_mc_EB_3.0_1.5_EE_4.5_2.5"),
                   ##connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),



  ##
  ##
  ##

   #cms.PSet(record = cms.string("EcalTPGFineGrainEBGroupRcd"),
                   #tag = cms.string("EcalTPGFineGrainEBGroup_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),

   #cms.PSet(record = cms.string("EcalTPGFineGrainEBIdMapRcd"),
                   #tag = cms.string("EcalTPGFineGrainEBIdMap_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),

   #cms.PSet(record = cms.string("EcalTPGFineGrainStripEERcd"),
                   #tag = cms.string("EcalTPGFineGrainStripEE_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
   #cms.PSet(record = cms.string("EcalTPGFineGrainTowerEERcd"),
                   #tag = cms.string("EcalTPGFineGrainTowerEE_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
   cms.PSet(record = cms.string("EcalTPGLutGroupRcd"),
                   #tag = cms.string("EcalTPGLutGroup_2018_mc"),
                   tag = cms.string("EcalTPGLutGroup_2018_mc_EB_EE"),
                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
                  
                  
   #cms.PSet(record = cms.string("EcalTPGSlidingWindowRcd"),
                   #tag = cms.string("EcalTPGSlidingWindow_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
   #cms.PSet(record = cms.string("EcalTPGSpikeRcd"),
                   #tag = cms.string("EcalTPGSpike_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
   #cms.PSet(record = cms.string("EcalTPGWeightGroupRcd"),
                   #tag = cms.string("EcalTPGWeightGroup_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
   #cms.PSet(record = cms.string("EcalTPGWeightIdMapRcd"),
                   #tag = cms.string("EcalTPGWeightIdMap_2018_mc"),
                   #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),



)



# Path and EndPath definitions
process.digitisation_step = cms.Path(process.pdigi_valid)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)


# Schedule definition
process.schedule = cms.Schedule(process.digitisation_step,process.L1simulation_step,process.digi2raw_step)
#process.schedule.extend(process.HLTSchedule)
process.schedule.extend([process.endjob_step,process.FEVTDEBUGHLToutput_step])
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
#from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforMC 

#call to customisation function customizeHLTforMC imported from HLTrigger.Configuration.customizeHLTforMC
#process = customizeHLTforMC(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
