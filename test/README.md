Run
====


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
    
    
    
    
    cp /eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValSingleElectronPt10/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/D438441B-4786-E711-A65E-0CC47A4D7694.root /tmp/amassiro/
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/D438441B-4786-E711-A65E-0CC47A4D7694.root
 
    
    cmsDriver.py step2 --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 92X_upgrade2017_realistic_v10 --step RAW2DIGI,RECO,EI --nThreads 4 --era Run2_2017  --fileout file:step1.root
    
    
    
    
    
    cmsRun runTPG_example.py
    
    
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1", "colz");
    
    
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,10)", "TPonlineETADC>-1", "colz");
    
    
    
    