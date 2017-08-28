Run
====


    cmsRun runDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-RECO/93X_mc2017_realistic_v1-v1/00000/4C897441-5A86-E711-9AA1-0025905B85A0.root
    cmsRun runDump.py             inputFiles=file:/tmp/amassiro/4C897441-5A86-E711-9AA1-0025905B85A0.root
    
    

    
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValNuGun/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/049A21E4-5586-E711-B126-0025905B85AA.root
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/049A21E4-5586-E711-B126-0025905B85AA.root

    
    
    cp /eos/cms/store/relval/CMSSW_9_3_0_pre4/RelValSingleElectronPt10/GEN-SIM-DIGI-RAW/93X_mc2017_realistic_v1-v1/00000/D438441B-4786-E711-A65E-0CC47A4D7694.root /tmp/amassiro/
    cmsRun runRawtoRecoAndDump.py             inputFiles=file:/tmp/amassiro/D438441B-4786-E711-A65E-0CC47A4D7694.root
 
    
    cmsDriver.py step2 --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 92X_upgrade2017_realistic_v10 --step RAW2DIGI,RECO,EI --nThreads 4 --era Run2_2017  --fileout file:step1.root
    
    