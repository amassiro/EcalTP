Plot
====


    r99t rawtoworld-zee.relval.root  rawtoworld-zeedata.root            drawCompare.cxx

    r99t rawtoworld-nugun.badOldTag.root  rawtoworld-nugun.LCfewFB.root      drawCompareOldNew.cxx
    r99t rawtoworld-nugun.relval.root  rawtoworld-nugun.LCfewFB.root      drawCompareOldNew.cxx
    r99t rawtoworld-nugun.relval.root  rawtoworld-nugun.LCfewFB.bigfile.root      drawCompareOldNew.cxx
    
    
    r99t  rawtoworld-nugun.badOldTag.root     rawtoworld-nugun.relval.root     drawCompareOldNew.cxx
    
    
    

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
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPCalibOfflineET/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineET>0", "colz");
    tree ->Draw("TPCalibOfflineET/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineET>2", "colz");

    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");
    tree ->Draw("TPCalibOfflineEnergy/TPCalibOfflineET", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");

    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,6", "TPonlineETADC>-1", "colz");
    
    
    tree ->Draw("TPflag:TPonlineETADC>>h(100,0,6,100,0,10)", "TPonlineETADC>-1", "colz");
    
    
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPOfflineEnergy/TPonlineETADC>>h(100,0,3)", "TPonlineETADC>0 && TPOfflineEnergy>0", "colz");
    tree ->Draw("TPOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPOfflineEnergy>0", "colz");
    tree ->Draw("TPOfflineEnergy", "TPOfflineEnergy>0", "colz");
    
    TTree* tree = (TTree*) _file0->Get("TreeProducer/tree")
    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>0", "colz");
    tree ->Draw("TPCalibOfflineEnergy/TPonlineETADC", "TPonlineETADC>0 && TPCalibOfflineEnergy>1", "colz");
    
    
    
    