Plot
====


    r99t rawtoworld-zee.relval.root  rawtoworld-zeedata.root            drawCompare.cxx
    r99t rawtoworld-zee.relval.OLD.root  rawtoworld-zeedata.root            drawCompare.cxx

    
    r99t rawtoworld-nugun.badOldTag.root  rawtoworld-nugun.LCfewFB.root      drawCompareOldNew.cxx
    r99t rawtoworld-nugun.relval.root  rawtoworld-nugun.LCfewFB.root      drawCompareOldNew.cxx
    r99t rawtoworld-nugun.relval.root  rawtoworld-nugun.LCfewFB.bigfile.root      drawCompareOldNew.cxx
        
    r99t  rawtoworld-nugun.badOldTag.root     rawtoworld-nugun.relval.root     drawCompareOldNew.cxx
    
    
    
    
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0C197E9F-D193-E711-A52D-0025905A610A.root    maxEvents=-1   outputFile=rawtoworld-zee.relval.root

    
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:production/step3_RAW2DIGI_L1Reco_RECO_EI_PAT_VALIDATION_DQM_PU_inMINIAODSIM.root   maxEvents=-1   outputFile=rawtoworld-zeeMC.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:production/step2_DIGI_L1_DIGI2RAW_HLT.root   maxEvents=-1   outputFile=rawtoworld-zeeMC.root

    r99t rawtoworld-zeeMC.root
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)>=27", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)<27", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)<17", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)>=17", "colz");
    
    tree ->Draw("TPflag:2*TPonlineETADC>>h(100,0,12,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)>=27", "colz");
    tree ->Draw("TPflag:2*TPonlineETADC>>h(100,0,12,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)<27", "colz");
      
    tree ->Draw("TPonlineIeta:etaEE", "TPonlineETADC>-1 && etaEE > -99", "colz");
      

      
Test for 2017

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:production/Year2017/step2_DIGI_L1_DIGI2RAW_HLT.root   maxEvents=-1   outputFile=rawtoworld-zeeMC-2017.root

     
Test for 2017 low pu run

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:production/LowPU/step2_DIGI_L1_DIGI2RAW_HLT.root   maxEvents=-1   outputFile=rawtoworld-zeeMC-2017-lowPU.root

    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)>=27", "colz");


      
Test for SR@PF with weights and multifit at the same time

    cmsRun runRawtoRecoAndDumpData.weightsVsMF.py             inputFiles=file:production/step2_DIGI_L1_DIGI2RAW_HLT.root    maxEvents=-1   outputFile=rawtoworld-zeedata.compareWeightsVsMF-weights-and-multifit.root


    r99t rawtoworld-zeedata.compareWeightsVsMF-weights-and-multifit.root
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE:etaEE",           "etaEE>-80 && onlineEnergyEE > 3", "colz");
    tree ->Draw("onlineEnergyEE_weights_inRechit/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE > 3", "colz");
    tree ->Draw("onlineEnergyEE_weights_inRechit/onlineEnergyEE_weights:etaEE", "etaEE>-80 && onlineEnergyEE_weights > 3", "colz");

    tree ->Draw("onlineEnergyEE_weights_inRechit/onlineEnergyEE_weights", "etaEE>-80 && onlineEnergyEE_weights > 3");
    tree ->Draw("onlineEnergyEB_weights_inRechit/onlineEnergyEB_weights", "etaEB>-80 && onlineEnergyEB_weights > 3");

 
Test online vs offline 

    r99t rawtoworld-zee.relval.root  rawtoworld-zeedata.root            drawCompare.cxx

    source /cvmfs/cms.cern.ch/crab3/crab.sh
    voms-proxy-init --voms cms
    xrdcp root://cms-xrd-global.cern.ch//store/data/Run2017B/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/297/047/00000/1CA3695B-6456-E711-A8AE-02163E0140DA.root /tmp/amassiro/
    
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/1CA3695B-6456-E711-A8AE-02163E0140DA.root   maxEvents=-1   outputFile=rawtoworld-zeedata.root

    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0C197E9F-D193-E711-A52D-0025905A610A.root    maxEvents=-1   outputFile=rawtoworld-zee.relval.root


    
    
Continue
    
    
    source /cvmfs/cms.cern.ch/crab3/crab.sh
    voms-proxy-init --voms cms
    xrdcp root://cms-xrd-global.cern.ch//store/data/Run2017B/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/297/047/00000/1CA3695B-6456-E711-A8AE-02163E0140DA.root /tmp/amassiro/
    
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/1CA3695B-6456-E711-A8AE-02163E0140DA.root   maxEvents=-1   outputFile=rawtoworld-zeedata.root
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/1CA3695B-6456-E711-A8AE-02163E0140DA.root   maxEvents=-1   outputFile=rawtoworld-zeedata.weights.root


    /DoubleEG/Run2017C-ZElectron-PromptReco-v1/RAW-RECO
    xrdcp  root://cms-xrd-global.cern.ch//store/data/Run2017C/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/299/368/00000/1CAF1B6A-856D-E711-8719-02163E011F58.root  /tmp/amassiro/
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/1CAF1B6A-856D-E711-8719-02163E011F58.root   maxEvents=-1   outputFile=rawtoworld-zeedata.weights.RunC.root
    
    
    /DoubleEG/Run2017D-ZElectron-PromptReco-v1/RAW-RECO
    xrdcp  root://cms-xrd-global.cern.ch//store/data/Run2017D/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/302/031/00000/0C65658E-1D8F-E711-9CB8-02163E0128F2.root   /tmp/amassiro/
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/0C65658E-1D8F-E711-9CB8-02163E0128F2.root   maxEvents=-1   outputFile=rawtoworld-zeedata.weights.RunD.root
    
    
    
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre1/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_v7-v1/00000/08A6C93D-8761-E711-9FD1-003048FFCBB2.root   maxEvents=-1   outputFile=rawtoworld-nugun.badOldTag.root

    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/54F5AEB3-A493-E711-AC7F-0025905B8586.root   maxEvents=-1   outputFile=rawtoworld-nugun.relval.root
    
    cmsRun runRawtoRecoAndDumpNewTag.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170911.root   maxEvents=-1   outputFile=rawtoworld-nugun.LCfewFB.root
    

    
    /RelValZEE_13/CMSSW_9_3_0_pre3-PUpmx25ns_92X_upgrade2017_realistic_v10_resub2-v1/GEN-SIM-DIGI-RAW-HLTDEBUG
    /store/relval/CMSSW_9_3_0_pre3/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_v10_resub2-v1/00000/080F4E90-9185-E711-80DE-0CC47A4C8EE2.root
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre3/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_v10_resub2-v1/00000/080F4E90-9185-E711-80DE-0CC47A4C8EE2.root   maxEvents=-1   outputFile=rawtoworld-zee.relval.OLD.root
    
    
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0C197E9F-D193-E711-A52D-0025905A610A.root    maxEvents=-1   outputFile=rawtoworld-zee.relval.test.root
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170926.root   maxEvents=-1   outputFile=rawtoworld-zee.FullReadout.root


    Standard
    
 > ebrechits->size() = 1105
 > eerechits->size() = 251
 ~~ 
Begin processing the 46th record. Run 1, Event 5942, LumiSection 60 at 28-Sep-2017 11:48:27.780 CEST
 ~~ 
 > ebrechits->size() = 1576
 > eerechits->size() = 947
 ~~ 
Begin processing the 47th record. Run 1, Event 5948, LumiSection 60 at 28-Sep-2017 11:48:28.274 CEST
 ~~ 
 > ebrechits->size() = 1488
 > eerechits->size() = 451


 
    FullReadout
 
 > ebrechits->size() = 61200
 > eerechits->size() = 14430

 
 
 
 

Run
====

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/cmkuo/20180130_NuGun_1000/step3_RAW2DIGI_L1Reco_RECO_RECOSIM_1000pre3_new.root 

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_10_0_0/RelValZEE_13/GEN-SIM-DIGI-RAW-RECO/PU25ns_100X_upgrade2018_realistic_v7_HS-v1/10000/0025CDE5-C900-E811-AB38-0CC47A4C8ED8.root   maxEvents=10   outputFile=rawtoworldtest.root
    
    

     
    
    

    cmsRun runDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-RECO/93X_mc2017_realistic_v1-v1/00000/4C897441-5A86-E711-9AA1-0025905B85A0.root
    cmsRun runDump.py             inputFiles=file:/tmp/amassiro/4C897441-5A86-E711-9AA1-0025905B85A0.root
    
    

    
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/049A21E4-5586-E711-B126-0025905B85AA.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/049A21E4-5586-E711-B126-0025905B85AA.root

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/049A21E4-5586-E711-B126-0025905B85AA.root   maxEvents=-1   outputFile=rawtoworld-nugun.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/0A709BE3-5586-E711-A7C4-0025905A608E.root   maxEvents=-1   outputFile=rawtoworld-nugun.2.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/562922D0-5086-E711-B4B5-0CC47A4C8E1E.root   maxEvents=-1   outputFile=rawtoworld-nugun.3.root

    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/0A709BE3-5586-E711-A7C4-0025905A608E.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/562922D0-5086-E711-B4B5-0CC47A4C8E1E.root
    
    
    source /cvmfs/cms.cern.ch/crab3/crab.sh
    voms-proxy-init --voms cms
    xrdcp root://cms-xrd-global.cern.ch//store/data/Run2017B/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/297/047/00000/1CA3695B-6456-E711-A8AE-02163E0140DA.root /tmp/amassiro/
    
    cmsRun runRawtoRecoAndDumpData.py             inputFiles=file:/tmp/amassiro/1CA3695B-6456-E711-A8AE-02163E0140DA.root   maxEvents=-1   outputFile=rawtoworld-zeedata.root


    
    Dataset: /RelValZEE_13/CMSSW_9_3_0_pre3-PU25ns_92X_upgrade2017_realistic_v10_resub-v1/GEN-SIM-DIGI-RAW
    xrdcp root://cms-xrd-global.cern.ch//store/relval/CMSSW_9_3_0_pre3/RelValZEE_13/GEN-SIM-DIGI-RAW/PU25ns_92X_upgrade2017_realistic_v10_resub-v1/00000/50E5E113-947F-E711-991B-0CC47A4D764A.root  /tmp/amassiro/
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/50E5E113-947F-E711-991B-0CC47A4D764A.root   maxEvents=-1   outputFile=rawtoworld-zeeMC.root

    
    

    Fixed MC
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170901.root   maxEvents=-1   outputFile=rawtoworld-nugun.FIXED.root

        
    Fixed MC - A     EcalTPGLutGroup_2017_mc 
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170904A.root   maxEvents=-1   outputFile=rawtoworld-nugun.FIXED.A.root
    Fixed MC - B     EcalTPGLutIdMap_2017_mc
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170904B.root   maxEvents=-1   outputFile=rawtoworld-nugun.FIXED.B.root
    Fixed MC - C     EcalTPGPhysicsConst_2017_mc
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170904C.root   maxEvents=-1   outputFile=rawtoworld-nugun.FIXED.C.root
    
    
    
    /RelValZEE_13/CMSSW_9_2_9-PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/GEN-SIM-DIGI-RAW-HLTDEBUG
    
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0A050AAC-D193-E711-AE72-0025905A6066.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0C197E9F-D193-E711-A52D-0025905A610A.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/18900595-D193-E711-9858-0CC47A7C3628.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/4E24D19F-D193-E711-ACD8-0CC47A7C3408.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/A6A121AC-D193-E711-AED4-0CC47A7C3458.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/C4226C90-D193-E711-9760-0CC47A4C8F06.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/D45738AC-D193-E711-96F4-0025905A605E.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/DA78D7B3-D193-E711-B86E-0CC47A4D768E.root
/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/F86FA1AC-D193-E711-9BCD-0CC47A7C34B0.root


    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValZEE_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/0C197E9F-D193-E711-A52D-0025905A610A.root    maxEvents=-1   outputFile=rawtoworld-zee.relval.root



    /RelValNuGun/CMSSW_9_2_9-PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/GEN-SIM-DIGI-RAW-HLTDEBUG
 
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/1C43A8DF-9693-E711-ACD8-0025905B8586.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/2C580A87-CC93-E711-A14F-0025905A610A.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/4843B37C-D193-E711-8DB8-0CC47A4D7616.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/48E69BCB-CE93-E711-95BD-0025905B8586.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/520199E1-9693-E711-921B-0025905A6082.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/54F5AEB3-A493-E711-AC7F-0025905B8586.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/64352D6E-D093-E711-87A9-0CC47A7C340E.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/646E16DE-9D93-E711-91D7-0025905B8586.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/6A1D1D93-CD93-E711-8D0F-0025905A6082.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/82727471-D093-E711-8076-0CC47A7C3412.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/8AB400E9-CD93-E711-89D4-0CC47A7C3424.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/A66898AA-A493-E711-AC76-0025905A6082.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/AE161841-AB93-E711-9EB8-0025905B8586.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/B87459EB-9D93-E711-8BFF-0025905A6082.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/C23BDE50-AB93-E711-88EB-0025905A6082.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/CA3F27D0-CC93-E711-BA26-0CC47A7C34E6.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/DE690088-D093-E711-ABBD-0CC47A4D7664.root
/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/E209908E-CD93-E711-B7B4-0CC47A4D7628.root

    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_2_9/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_Candidate_forECALStudies-v1/00000/54F5AEB3-A493-E711-AC7F-0025905B8586.root   maxEvents=-1   outputFile=rawtoworld-nugun.relval.root
    
    
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170911.root   maxEvents=-1   outputFile=rawtoworld-nugun.LCfewFB.root
    cmsRun runRawtoRecoAndDumpNewTag.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170911.root   maxEvents=-1   outputFile=rawtoworld-nugun.LCfewFB.root
    


    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre1/RelValNuGun/GEN-SIM-DIGI-RAW-HLTDEBUG/PUpmx25ns_92X_upgrade2017_realistic_v7-v1/00000/08A6C93D-8761-E711-9FD1-003048FFCBB2.root   maxEvents=-1   outputFile=rawtoworld-nugun.badOldTag.root

    


    
    
    
    
    cmsRun runRawtoRecoAndDump.py    inputFiles=file:/eos/cms/store/group/dpg_ecal/comm_ecal/test/ming/step2_DIGIPREMIX_S2_DATAMIX_L1_DIGI2RAW_HLT_new_PU_20170926.root   maxEvents=-1   outputFile=rawtoworld-zee.FullReadout.root

    r99t  rawtoworld-zee.relval.root    rawtoworld-zee.FullReadout.root    drawCompareOldNew.cxx
    
    
    
    
    
    
    
    
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/afs/cern.ch/user/a/amassiro/work/ECAL/Pulses/CMSSW_9_2_9/src/step2_DIGI_L1_DIGI2RAW_HLT.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/afs/cern.ch/user/a/amassiro/work/ECAL/Pulses/CMSSW_9_2_9/src/step2_DIGI_L1_DIGI2RAW_HLT.root.withNOnoise.root
 
    
    
    
    

    
    
    cp /eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValSingleElectronPt10/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/D438441B-4786-E711-A65E-0CC47A4D7694.root /tmp/amassiro/
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/D438441B-4786-E711-A65E-0CC47A4D7694.root
 
    
    cmsDriver.py step2 --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 92X_upgrade2017_realistic_v10 --step RAW2DIGI,RECO,EI --nThreads 4 --era Run2_2017  --fileout file:step1.root
    
    
    
    
    
    cmsRun runTPG_example.py
    
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag*(TPflag<2)+(TPflag>=2)*2>>h(3,0,3", "TPonlineETADC>-1", "colz");
    h->GetXaxis()->SetTitle("TP flag");
    h->Scale (1./h->Integral());
    h->SetLineWidth(2);
    h->Draw("hist");
    h->GetBinContent (1)
    h->GetBinContent (2)
    h->GetBinContent (3)
    
    
    r99t rawtoworld-zeedata.root 
    r99t rawtoworld-zeedata.weights.root 
    r99t rawtoworld-zeedata.weights.RunC.root
    r99t rawtoworld-zeedata.weights.RunD.root
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("offlineEnergyEE:etaEE", "etaEE>-80 && offlineEnergyEE < 20 && offlineEnergyEE>0 && flagEE==0", "colz");
    tree ->Draw("offlineEnergyEE:etaEE", "etaEE>-80 && offlineEnergyEE < 20 && offlineEnergyEE>0 && flagEE==1", "colz");
    tree ->Draw("offlineEnergyEE:etaEE", "etaEE>-80 && offlineEnergyEE < 20 && offlineEnergyEE>0 && flagEE==2", "colz");
    
    tree ->Draw("onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE < 30 && onlineEnergyEE>0 && flagEE==0", "colz");
    tree ->Draw("onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE < 30 && onlineEnergyEE>0 && flagEE==1", "colz");
    tree ->Draw("onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE < 30 && onlineEnergyEE>0 && flagEE==2", "colz");
    
    tree ->Draw("onlineEnergyEE:flagEE", "etaEE>-80 && onlineEnergyEE < 30 && onlineEnergyEE>0", "colz");
    tree ->Draw("onlineEnergyEB:flagEB", "etaEB>-80 && onlineEnergyEB < 30 && onlineEnergyEB>0", "colz");
    
    
    tree ->Draw("offlineEnergyEE/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE>20", "colz");

    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPCalibOfflineET/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineET>0", "colz");
    tree ->Draw("TPCalibOfflineET/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineET>2", "colz");

    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");
    tree ->Draw("TPCalibOfflineEnergy/TPCalibOfflineET", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");

    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1", "colz");
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1 && abs(TPonlineIeta)>=27", "colz");
    
    
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,10)", "TPonlineETADC>-1", "colz");
    
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPOfflineEnergy/TPonlineETADC>>h(100,0,3)", "TPonlineETADC>0 && TPOfflineEnergy>0", "colz");
    tree ->Draw("TPOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPOfflineEnergy>0", "colz");
    tree ->Draw("TPOfflineEnergy", "TPOfflineEnergy>0", "colz");
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");
    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>1", "colz");
    

    
Check difference between weights and MF:

    source /cvmfs/cms.cern.ch/crab3/crab.sh
    voms-proxy-init --voms cms
    xrdcp root://cms-xrd-global.cern.ch//store/data/Run2017B/DoubleEG/RAW-RECO/ZElectron-PromptReco-v1/000/297/047/00000/1CA3695B-6456-E711-A8AE-02163E0140DA.root /tmp/amassiro/
    
    cmsRun runRawtoRecoAndDumpData.weightsVsMF.py             inputFiles=file:/tmp/amassiro/1CA3695B-6456-E711-A8AE-02163E0140DA.root   maxEvents=-1   outputFile=rawtoworld-zeedata.compareWeightsVsMF.root

    
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE > 3", "colz");
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE > 1 && onlineEnergyEE_weights/onlineEnergyEE < 10", "colz");
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE > 1 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0 && flagEE>=1", "colz");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB:etaEB", "etaEB>-80 && onlineEnergyEB > 1 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0 && flagEB>=1", "colz");
        
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE:etaEE", "etaEE>-80 && onlineEnergyEE > 1 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "colz");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB:etaEB", "etaEB>-80 && onlineEnergyEB > 1 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "colz");
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE > 1 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB > 1 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE > 10 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB > 10 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE > 5 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB > 5 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    
    tree ->Draw("onlineEnergyEE_weights:onlineEnergyEE", "etaEE>-80 && onlineEnergyEE_weights > 5 && onlineEnergyEE_weights < 20  && onlineEnergyEE > 5 && onlineEnergyEE < 20 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "colz");
    tree ->Draw("onlineEnergyEB_weights:onlineEnergyEB", "etaEB>-80 && onlineEnergyEB_weights > 5 && onlineEnergyEB_weights < 20  && onlineEnergyEB > 5 && onlineEnergyEB < 20 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "colz");
    TF1 f("f","x",0,20)
    f.Draw("L same")
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE_weights > 5 && onlineEnergyEE_weights < 20  && onlineEnergyEE > 5 && onlineEnergyEE < 20 && onlineEnergyEE_weights/onlineEnergyEE < 10 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB_weights > 5 && onlineEnergyEB_weights < 20  && onlineEnergyEB > 5 && onlineEnergyEB < 20 && onlineEnergyEB_weights/onlineEnergyEB < 10 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE_weights > 3 && onlineEnergyEE_weights < 6  && onlineEnergyEE > 3 && onlineEnergyEE < 6 && onlineEnergyEE_weights/onlineEnergyEE < 6 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB_weights > 3 && onlineEnergyEB_weights < 6  && onlineEnergyEB > 3 && onlineEnergyEB < 6 && onlineEnergyEB_weights/onlineEnergyEB < 6 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    
    tree ->Draw("onlineEnergyEE_weights/onlineEnergyEE", "etaEE>-80 && onlineEnergyEE_weights > 3 && onlineEnergyEE_weights < 6  && onlineEnergyEE_weights/onlineEnergyEE < 6 && onlineEnergyEE_weights/onlineEnergyEE > 0", "");
    tree ->Draw("onlineEnergyEB_weights/onlineEnergyEB", "etaEB>-80 && onlineEnergyEB_weights > 3 && onlineEnergyEB_weights < 6  && onlineEnergyEB_weights/onlineEnergyEB < 6 && onlineEnergyEB_weights/onlineEnergyEB > 0", "");
    