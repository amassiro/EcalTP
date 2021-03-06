// -*- C++ -*-
//
// Package:    AdvancedMultifitCMSSW/TreeProducerComparison
// Class:      TreeProducerComparison
// 
/**\class TreeProducerComparison TreeProducerComparison.cc AdvancedMultifitCMSSW/TreeProducerComparison/plugins/TreeProducerComparison.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrea Massironi
//         Created:  Thu, 17 Nov 2016 10:09:05 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"



// ECAL specific

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbService.h"
#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbRecord.h"
#include "CondFormats/EcalObjects/interface/EcalADCToGeVConstant.h"
#include "CondFormats/DataRecord/interface/EcalADCToGeVConstantRcd.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstantsMC.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsRcd.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsMCRcd.h"


#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"

#include "DataFormats/EcalRecHit/interface/EcalUncalibratedRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"



#include "FWCore/Framework/interface/ESHandle.h"



#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"   //     ----> CLHEP/Geometry/Point3D.h issue
// #include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"    ----> CLHEP/Geometry/Point3D.h issue
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
// #include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"      ----> CLHEP/Geometry/Point3D.h issue
// #include "Geometry/EcalAlgo/interface/EcalEndcapGeometry.h"      ----> CLHEP/Geometry/Point3D.h issue




// #include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
// #include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "CondFormats/EcalObjects/interface/EcalMGPAGainRatio.h"
#include "CondFormats/EcalObjects/interface/EcalGainRatios.h"
#include "CondFormats/DataRecord/interface/EcalGainRatiosRcd.h"


#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"







//---- for TP

#include "CondFormats/EcalObjects/interface/EcalTPGLutIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLutGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGPhysicsConst.h"
#include "CondFormats/DataRecord/interface/EcalTPGLutIdMapRcd.h"
#include "CondFormats/DataRecord/interface/EcalTPGLutGroupRcd.h"
#include "CondFormats/DataRecord/interface/EcalTPGPhysicsConstRcd.h"


#include "Geometry/CaloTopology/interface/EcalTrigTowerConstituentsMap.h"






#include "TTree.h"




//---- for Zee part
#include "DataFormats/PatCandidates/interface/Electron.h"






//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class TreeProducerComparison : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit TreeProducerComparison(const edm::ParameterSet&);
      ~TreeProducerComparison();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      
      edm::EDGetTokenT<EBDigiCollection> _token_ebdigis;
      edm::EDGetTokenT<EEDigiCollection> _token_eedigis;
      
      edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_ebrechits;
      edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_eerechits;

      edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_ebrechits_weights;
      edm::EDGetTokenT<EcalUncalibratedRecHitCollection> _token_eerechits_weights;
      
      edm::EDGetTokenT<EcalRecHitCollection> _token_ebrechits_calib;
      edm::EDGetTokenT<EcalRecHitCollection> _token_eerechits_calib;
      
      edm::EDGetTokenT<EcalTrigPrimDigiCollection> _token_tpCollection;
      edm::EDGetTokenT<EcalTrigPrimDigiCollection> _token_tpEmuCollection;
      
      
      TTree *outTree;
      
      UInt_t _run;
      UShort_t _lumi;
      UShort_t _bx;
      UShort_t _event;      
      float _onlineEnergyEB[61200];
      float _onlineEnergyEE[14648];
      int _flagEB[61200];
      int _flagEE[14648];
      // new float in rechits
      float _onlineEnergyEB_weights_inRechit[61200];
      float _onlineEnergyEE_weights_inRechit[14648];
      
      float _onlineEnergyEB_weights[61200];
      float _onlineEnergyEE_weights[14648];
      int _flagEB_weights[61200];
      int _flagEE_weights[14648];

      
      float _offlineEnergyEB[61200];
      float _offlineEnergyEE[14648];
      float _etaEB[61200];
      float _etaEE[14648];
            
      float _TPflag[4032];
      float _TPonlineEnergyADC[4032];
      float _TPonlineEnergyTowerADC[4032];
      float _TPonlineETADC[4032];
      int   _TPonlineIeta[4032];
      int   _TPonlineIphi[4032];
      float _TPOfflineEnergy[4032];
      float _TPOfflineET[4032];
      int   _TPOfflineNxtals[4032];
      float _TPCalibOfflineEnergy[4032];
      float _TPCalibOfflineET[4032];
      int   _TPCalibOfflineNxtals[4032];
      
      float _TPEmuflag[4032];
      float _TPEmuonlineEnergyADC[4032];
      
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TreeProducerComparison::TreeProducerComparison(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");
   
   
   //now do what ever initialization is needed
   usesResource("TFileService");
   edm::Service<TFileService> fs;
   
   _token_ebdigis = consumes<EBDigiCollection>(iConfig.getParameter<edm::InputTag>("EBDigiCollection"));
   _token_eedigis = consumes<EEDigiCollection>(iConfig.getParameter<edm::InputTag>("EEDigiCollection"));
   
   _token_ebrechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEBCollection"));
   _token_eerechits = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsEECollection"));
   
   _token_ebrechits_weights = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsWeightsEBCollection"));
   _token_eerechits_weights = consumes<EcalUncalibratedRecHitCollection>(iConfig.getParameter<edm::InputTag>("EcalUncalibRecHitsWeightsEECollection"));
   
   _token_ebrechits_calib = consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EBRecHitCollectionLabel"));
   _token_eerechits_calib = consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EERecHitCollectionLabel"));
   
   
   _token_tpCollection    = consumes<EcalTrigPrimDigiCollection>(iConfig.getParameter<edm::InputTag>("TPCollection")) ;
   _token_tpEmuCollection = consumes<EcalTrigPrimDigiCollection>(iConfig.getParameter<edm::InputTag>("TPEmuCollection")) ;
   
    
   
   outTree = fs->make<TTree>("tree","tree");
   
   outTree->Branch("run",               &_run,             "run/i");
   outTree->Branch("lumi",              &_lumi,            "lumi/s");
   outTree->Branch("bx",                &_bx,              "bx/s");
   outTree->Branch("event",             &_event,           "event/i");
   outTree->Branch("onlineEnergyEB",       _onlineEnergyEB,    "onlineEnergyEB[61200]/F");
   outTree->Branch("onlineEnergyEE",       _onlineEnergyEE,    "onlineEnergyEE[14648]/F");
   outTree->Branch("onlineEnergyEB_weights_inRechit",       _onlineEnergyEB_weights_inRechit,    "onlineEnergyEB_weights_inRechit[61200]/F");
   outTree->Branch("onlineEnergyEE_weights_inRechit",       _onlineEnergyEE_weights_inRechit,    "onlineEnergyEE_weights_inRechit[14648]/F");
   
   
   
   outTree->Branch("onlineEnergyEB_weights",       _onlineEnergyEB_weights,    "onlineEnergyEB_weights[61200]/F");
   outTree->Branch("onlineEnergyEE_weights",       _onlineEnergyEE_weights,    "onlineEnergyEE_weights[14648]/F");
   
   outTree->Branch("offlineEnergyEB",       _offlineEnergyEB,    "offlineEnergyEB[61200]/F");
   outTree->Branch("offlineEnergyEE",       _offlineEnergyEE,    "offlineEnergyEE[14648]/F");
   outTree->Branch("etaEB",       _etaEB,    "etaEB[61200]/F");
   outTree->Branch("etaEE",       _etaEE,    "etaEE[14648]/F");
   outTree->Branch("flagEB",       _flagEB,    "flagEB[61200]/I");
   outTree->Branch("flagEE",       _flagEE,    "flagEE[14648]/I");
   
   outTree->Branch("flagEB_weights",       _flagEB_weights,    "flagEB_weights[61200]/I");
   outTree->Branch("flagEE_weights",       _flagEE_weights,    "flagEE_weights[14648]/I");
   
   
   
   outTree->Branch("TPflag",                _TPflag,             "TPflag[4032]/F");
   outTree->Branch("TPonlineEnergyADC",                _TPonlineEnergyADC,             "TPonlineEnergyADC[4032]/F");
   outTree->Branch("TPonlineEnergyTowerADC",       _TPonlineEnergyTowerADC,    "TPonlineEnergyTowerADC[4032]/F");
   outTree->Branch("TPonlineETADC",       _TPonlineETADC,    "TPonlineETADC[4032]/F");
   outTree->Branch("TPOfflineEnergy",     _TPOfflineEnergy,  "TPOfflineEnergy[4032]/F");
   outTree->Branch("TPOfflineET",     _TPOfflineET,  "TPOfflineET[4032]/F");
   outTree->Branch("TPOfflineNxtals",     _TPOfflineNxtals,  "TPOfflineNxtals[4032]/I");
   outTree->Branch("TPonlineIeta",     _TPonlineIeta,  "TPonlineIeta[4032]/I");
   outTree->Branch("TPonlineIphi",     _TPonlineIphi,  "TPonlineIphi[4032]/I");
   
   
   outTree->Branch("TPCalibOfflineEnergy",     _TPCalibOfflineEnergy,  "TPCalibOfflineEnergy[4032]/F");
   outTree->Branch("TPCalibOfflineET",     _TPCalibOfflineET,  "TPCalibOfflineET[4032]/F");
   outTree->Branch("TPCalibOfflineNxtals",     _TPCalibOfflineNxtals,  "TPCalibOfflineNxtals[4032]/I");
   
   
   outTree->Branch("TPEmuflag",                _TPEmuflag,             "TPEmuflag[4032]/F");
   outTree->Branch("TPEmuonlineEnergyADC",                _TPEmuonlineEnergyADC,             "TPEmuonlineEnergyADC[4032]/F");
   
   
   
   
   
}


TreeProducerComparison::~TreeProducerComparison()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TreeProducerComparison::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  
  _run = iEvent.eventAuxiliary().run();
  _lumi = iEvent.eventAuxiliary().luminosityBlock();
  _bx = iEvent.eventAuxiliary().bunchCrossing();
  _event = iEvent.eventAuxiliary().event();
  
  
  //---- digi 
  
//   edm::Handle<EBDigiCollection> ebdigihandle;
//   edm::Handle<EEDigiCollection> eedigihandle;
//     
//   iEvent.getByToken(_token_ebdigis,ebdigihandle);
//   auto ebdigis = ebdigihandle.product();
// //   for (uint i=0; i<ebdigis->size(); i++) 
// //     FillDigi((*ebdigis)[i],ebrechits,w_ebrechits);
//   iEvent.getByToken(_token_eedigis,eedigihandle);
//   auto eedigis = eedigihandle.product();
// //   for (uint i=0; i<eedigis->size(); i++)
// //     FillDigi((*eedigis)[i],eerechits,w_eerechits);
  
  
  //---- rechits multifit
  edm::Handle<EcalUncalibratedRecHitCollection> ebrechithandle;
  const EcalUncalibratedRecHitCollection *ebrechits = NULL;
  edm::Handle<EcalUncalibratedRecHitCollection> eerechithandle;
  const EcalUncalibratedRecHitCollection *eerechits = NULL;
  
  iEvent.getByToken(_token_ebrechits,ebrechithandle);
  ebrechits = ebrechithandle.product();
  iEvent.getByToken(_token_eerechits,eerechithandle);
  eerechits = eerechithandle.product();
  
  
  
  //---- rechits with weights
  edm::Handle<EcalUncalibratedRecHitCollection> ebrechit_weights_handle;
  const EcalUncalibratedRecHitCollection *ebrechits_weights = NULL;
  edm::Handle<EcalUncalibratedRecHitCollection> eerechit_weights_handle;
  const EcalUncalibratedRecHitCollection *eerechits_weights = NULL;
  
  iEvent.getByToken(_token_ebrechits_weights,ebrechit_weights_handle);
  ebrechits_weights = ebrechit_weights_handle.product();
  iEvent.getByToken(_token_eerechits_weights,eerechit_weights_handle);
  eerechits_weights = eerechit_weights_handle.product();
  
  
  
  //---- calibrated rechits  
  edm::Handle<EcalRecHitCollection> calib_ebrechithandle;
  const EcalRecHitCollection *calib_ebrechits = NULL;
  edm::Handle<EcalRecHitCollection> calib_eerechithandle;
  const EcalRecHitCollection *calib_eerechits = NULL;
  
  iEvent.getByToken(_token_ebrechits_calib,calib_ebrechithandle);
  calib_ebrechits = calib_ebrechithandle.product();
  iEvent.getByToken(_token_eerechits_calib,calib_eerechithandle);
  calib_eerechits = calib_eerechithandle.product();
  

  
  //---- fill information
   
  for (int ixtal=0; ixtal < 61200; ixtal++) {
    //---- Fill flag for this crystal
    _flagEB[ixtal] = -99;
    _onlineEnergyEB[ixtal] = -99;
    _onlineEnergyEB_weights_inRechit[ixtal] = -99;
    _flagEB_weights[ixtal] = -99;
    _onlineEnergyEB_weights[ixtal] = -99;
    _etaEB[ixtal] = -99;
    _offlineEnergyEB[ixtal] = -99;
  }
  for (int ixtal=0; ixtal < 14648; ixtal++) {
    //---- Fill flag for this crystal
    _flagEE[ixtal] = -99;
    _onlineEnergyEE[ixtal] = -99;
    _onlineEnergyEE_weights_inRechit[ixtal] = -99;
    _flagEE_weights[ixtal] = -99;
    _onlineEnergyEE_weights[ixtal] = -99;
    _etaEE[ixtal] = -99;
    _offlineEnergyEE[ixtal] = -99;
  }
  
  
  std::cout << " ~~ " << std::endl;
  std::cout << " > ebrechits->size() = " << ebrechits->size() << std::endl;
  std::cout << " > eerechits->size() = " << eerechits->size() << std::endl;
  std::cout << " > ebrechits_weights->size() = " << ebrechits_weights->size() << std::endl;
  std::cout << " > eerechits_weights->size() = " << eerechits_weights->size() << std::endl;
  std::cout << " ~~ " << std::endl;
  
  edm::ESHandle<CaloGeometry> pGeometry;
  iSetup.get<CaloGeometryRecord>().get(pGeometry);
  const CaloGeometry *geometry = pGeometry.product();
  
  
  edm::ESHandle<EcalTrigTowerConstituentsMap> eTTmap;
  iSetup.get<IdealGeometryRecord>().get(eTTmap);
  
  
  
  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = ebrechits->begin(); itrechit != ebrechits->end(); itrechit++ ) {
    _onlineEnergyEB[EBDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();    
//     _onlineEnergyEB_weights_inRechit[EBDetId(itrechit->id()).hashedIndex()] =  itrechit->secondAmplitude();     //---- NB: only on test branch this will compile and work! 
  }

  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = eerechits->begin(); itrechit != eerechits->end(); itrechit++ ) {
    _onlineEnergyEE[EEDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();
//     _onlineEnergyEE_weights_inRechit[EEDetId(itrechit->id()).hashedIndex()] =  itrechit->secondAmplitude();     //---- NB: only on test branch this will compile and work! 
  }

  
  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = ebrechits_weights->begin(); itrechit != ebrechits_weights->end(); itrechit++ ) {
    _onlineEnergyEB_weights[EBDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();    
  }
  
  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = eerechits_weights->begin(); itrechit != eerechits_weights->end(); itrechit++ ) {
    _onlineEnergyEE_weights[EEDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();
  }
  
  
  
  for (EcalRecHitCollection::const_iterator itrechit = calib_ebrechits->begin(); itrechit != calib_ebrechits->end(); itrechit++ ) { 
    _etaEB[EBDetId(itrechit->id()).hashedIndex()]           = (EBDetId(itrechit->id()).ieta());
    _offlineEnergyEB[EBDetId(itrechit->id()).hashedIndex()] = itrechit->energy();
  }
  
  for (EcalRecHitCollection::const_iterator itrechit = calib_eerechits->begin(); itrechit != calib_eerechits->end(); itrechit++ ) { 
    GlobalPoint mycell = geometry -> getPosition(DetId(itrechit->id()));
    _etaEE[EEDetId(itrechit->id()).hashedIndex()]           = mycell.eta();
    _offlineEnergyEE[EEDetId(itrechit->id()).hashedIndex()] = itrechit->energy();
  }
  
  
  
  
  //----
  //---- kindly borrowed from
  //----     https://gitlab.cern.ch/ECALPFG/EcalTPGAnalysis/blob/master/TriggerAnalysis/plugins/EcalTPGAnalyzer.cc#L860
  //----     thanks ETT!
  //----
  
    
  edm::Handle<EcalTrigPrimDigiCollection> tphandle;
  iEvent.getByToken(_token_tpCollection,tphandle);
  
  
  for (int iTP=0; iTP < 4032; iTP++) {
    _TPflag[iTP] = -99;
    _TPonlineEnergyADC[iTP] = -99;
    _TPonlineEnergyTowerADC[iTP] = -99;
    _TPonlineETADC[iTP] = -99;
    _TPOfflineEnergy[iTP] = -99;
    _TPOfflineET[iTP] = -99;
    _TPOfflineNxtals[iTP] = -99;
    _TPCalibOfflineEnergy[iTP] = -99;
    _TPCalibOfflineET[iTP] = -99;
    _TPCalibOfflineNxtals[iTP] = -99;
    _TPonlineIeta[iTP] = -99;
    _TPonlineIphi[iTP] = -99;
  }
  
//   std::cout << " tphandle.product()->size() = " << tphandle.product()->size() << std::endl;
  
  
  
  edm::ESHandle<EcalTPGLutGroup> lutGrpHandle;
  iSetup.get<EcalTPGLutGroupRcd>().get( lutGrpHandle );
  const EcalTPGGroups::EcalTPGGroupsMap & lutGrpMap = lutGrpHandle.product()->getMap() ;  
  
  edm::ESHandle<EcalTPGPhysicsConst> physHandle;
  iSetup.get<EcalTPGPhysicsConstRcd>().get( physHandle );
  const EcalTPGPhysicsConstMap & physMap = physHandle.product()->getMap() ;
 
  edm::ESHandle<EcalTPGLutIdMap> lutMapHandle;
  iSetup.get<EcalTPGLutIdMapRcd>().get( lutMapHandle );
  const EcalTPGLutIdMap::EcalTPGLutMap & lutMap = lutMapHandle.product()->getMap() ;  
  
  
  EcalTPGPhysicsConstMapIterator ebItr(physMap.find(DetId(DetId::Ecal,EcalBarrel).rawId()));
  double lsb10bitsEB(ebItr == physMap.end() ? 0. : ebItr->second.EtSat / 1024.);
  EcalTPGPhysicsConstMapIterator eeItr(physMap.find(DetId(DetId::Ecal,EcalEndcap).rawId()));
  double lsb10bitsEE(eeItr == physMap.end() ? 0. : eeItr->second.EtSat / 1024.);
  
  
    
  for (unsigned int i=0;i<tphandle.product()->size();i++) {
    EcalTriggerPrimitiveDigi d = (*(tphandle.product()))[i];
    const EcalTrigTowerDetId TPtowid = d.id();
//     towerEner tE ;
//     //tE.TCCid_= theMapping_->TCCid(TPtowid);
//     //tE.TowerInTCC_ = theMapping_->iTT(TPtowid);
//     //      const EcalTriggerElectronicsId elId = theMapping_->getTriggerElectronicsId(id) ;
//     //tE.strip_ = 0;//elId.pseudoStripId() ;
//     
//     tE.iphi_ = TPtowid.iphi() ;
//     tE.ieta_ = TPtowid.ieta() ;
//     tE.ttFlag_ = d[0].ttFlag();
//     tE.tpgADC_ = (d[0].raw()&0xfff) ;
//     tE.twrADC = (d[0].raw()&0xff) ;
//     tE.sFGVB = (d[0].sFGVB());
//     mapTower[TPtowid] = tE ;

//     std::cout << " TPtowid.hashedIndex() = " << TPtowid.hashedIndex() << std::endl;
//     std::cout << "        -> " <<  (d[0].raw() & 0xfff) << std::endl;
//     std::cout << "        -> " <<  (d[0].raw() & 0xff ) << std::endl;
    if (TPtowid.hashedIndex() < 4032) {
      _TPflag[  TPtowid.hashedIndex() ] = (d[0].ttFlag());
      _TPonlineEnergyADC[ TPtowid.hashedIndex() ] = (d[0].raw() & 0xfff);  //---- 0xfff = 4095
      _TPonlineEnergyTowerADC[ TPtowid.hashedIndex() ] = (d[0].raw() & 0xff);   //---- 0xff = 255
//       _TPonlineETADC[ TPtowid.hashedIndex() ] = (d[0].compressedEt()); 
      
      
      _TPonlineIeta[ TPtowid.hashedIndex() ] = TPtowid.ieta();
      _TPonlineIphi[ TPtowid.hashedIndex() ] = TPtowid.iphi();
      
      
      EcalTrigTowerDetId const& towerId(d.id());
      unsigned int ADC = d[0].compressedEt();
      
      double lsb10bits(0.);
      if(towerId.subDet() == EcalBarrel) lsb10bits = lsb10bitsEB;
      else if(towerId.subDet() == EcalEndcap) lsb10bits = lsb10bitsEE;
      
      int tpg10bits = 0 ;
      EcalTPGGroups::EcalTPGGroupsMapItr itgrp = lutGrpMap.find(towerId.rawId()) ;
      uint32_t lutGrp = 999 ;
      if (itgrp != lutGrpMap.end()) lutGrp = itgrp->second ;
      
      EcalTPGLutIdMap::EcalTPGLutMapItr itLut = lutMap.find(lutGrp) ;
      if (itLut != lutMap.end()) {
        const unsigned int * lut = (itLut->second).getLut() ;
        for (unsigned int i=0 ; i<1024 ; i++)
          if (ADC == (0xff & lut[i])) {
            tpg10bits = i ;
            break ;
          }
      }
      
      float tpEt = lsb10bits * tpg10bits;
      
      
      _TPonlineETADC[ TPtowid.hashedIndex() ] = tpEt; 
      
      
      
      
    
//     tE.iphi_ = TPtowid.iphi() ;
//     tE.ieta_ = TPtowid.ieta() ;
//     tE.ttFlag_ = d[0].ttFlag();
//     tE.tpgADC_ = (d[0].raw()&0xfff) ;
//     tE.twrADC = (d[0].raw()&0xff) ;
//     tE.sFGVB = (d[0].sFGVB());
//     mapTower[TPtowid] = tE ;
    
    
    
      //----
      //---- loop over the crystals and if the TT is matching the one under exam, 
      //---- save the energy and count the number of crystals associated with the TT
      //----
      
      int thisTowerHI = towerId.hashedIndex();
      float numberXtal  = 0;
      float towerEnergy = 0.;
      float towerET = 0.;
      if(towerId.subDet() == EcalBarrel) {
        for (EcalUncalibratedRecHitCollection::const_iterator itrechit = ebrechits->begin(); itrechit != ebrechits->end(); itrechit++ ) {
          int thisXtalTowidHI = (EBDetId(itrechit->id()).tower()).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->amplitude();
            
            GlobalPoint mycell = geometry -> getPosition(DetId(itrechit->id()));
//             float theta = mycell.theta();
//             towerET = towerET + itrechit->amplitude() * sin (theta);
            towerET = towerET + itrechit->amplitude() * mycell.perp()/mycell.mag();
            
          }
        }
        _TPOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPOfflineET     [ TPtowid.hashedIndex() ] = towerET;
        _TPOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
      }
      else {
        for (EcalUncalibratedRecHitCollection::const_iterator itrechit = eerechits->begin(); itrechit != eerechits->end(); itrechit++ ) {
          const EcalTrigTowerDetId towid = (*eTTmap).towerOf( EEDetId(itrechit->id()) );
          int thisXtalTowidHI = towid.hashedIndex();
//           int thisXtalTowidHI = EcalTrigTowerDetId( EEDetId(itrechit->id()).zside(),EcalEndcap, EEDetId(itrechit->id()).ix(), EEDetId(itrechit->id()).iy()  ).hashedIndex();
          //             int thisXtalTowidHI = (EEDetId(itrechit->id()).tower()).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->amplitude();

            GlobalPoint mycell = geometry -> getPosition(DetId(itrechit->id()));
//             float theta = mycell.theta();
//             towerET = towerET + itrechit->amplitude() * sin (theta);
            towerET = towerET + itrechit->amplitude() * mycell.perp()/mycell.mag();
          }
        }
        _TPOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPOfflineET     [ TPtowid.hashedIndex() ] = towerET;
        _TPOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
        //         std::cout << "# xtals = " << numberXtal << ", towerEnergy = " << towerEnergy << std::endl;
      }
      
      
      //--------------------------------
      //---- now calibrated rechits ----
      numberXtal  = 0;
      towerEnergy = 0.;
      towerET     = 0.;
      if(towerId.subDet() == EcalBarrel) {
        for (EcalRecHitCollection::const_iterator itrechit = calib_ebrechits->begin(); itrechit != calib_ebrechits->end(); itrechit++ ) {
          int thisXtalTowidHI = (EBDetId(itrechit->id()).tower()).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->energy();
            
            GlobalPoint mycell = geometry -> getPosition(DetId(itrechit->id()));
//             float theta = mycell.theta();
//             towerET = towerET + itrechit->energy() * sin (theta);
            towerET = towerET + itrechit->energy() * mycell.perp()/mycell.mag();
            
            _flagEB[EBDetId(itrechit->id()).hashedIndex()] = (d[0].ttFlag());
            _flagEB_weights[EBDetId(itrechit->id()).hashedIndex()] = (d[0].ttFlag());
            
          }
        }
        _TPCalibOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPCalibOfflineET     [ TPtowid.hashedIndex() ] = towerET;
        _TPCalibOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
      }
      else {
        for (EcalRecHitCollection::const_iterator itrechit = calib_eerechits->begin(); itrechit != calib_eerechits->end(); itrechit++ ) {
          const EcalTrigTowerDetId towid = (*eTTmap).towerOf( EEDetId(itrechit->id()) );
          int thisXtalTowidHI = towid.hashedIndex();
//           int thisXtalTowidHI = EcalTrigTowerDetId( EEDetId(itrechit->id()).zside(),EcalEndcap, EEDetId(itrechit->id()).ix(), EEDetId(itrechit->id()).iy()  ).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->energy();
            
            GlobalPoint mycell = geometry -> getPosition(DetId(itrechit->id()));
//             float theta = mycell.theta();
//             towerET = towerET + itrechit->energy() * sin (theta);
            towerET = towerET + itrechit->energy() * mycell.perp()/mycell.mag();  
            
            _flagEE[EEDetId(itrechit->id()).hashedIndex()] = (d[0].ttFlag());
            _flagEE_weights[EEDetId(itrechit->id()).hashedIndex()] = (d[0].ttFlag());
            
          }
        }
        _TPCalibOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPCalibOfflineET     [ TPtowid.hashedIndex() ] = towerET;
        _TPCalibOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
      }
      
      
      
      
      
    }
    
  }
  
  
  
  
  
  
  edm::Handle<EcalTrigPrimDigiCollection> tpEmuHandle;
  iEvent.getByToken(_token_tpEmuCollection,tpEmuHandle);
  
  
  for (int iTP=0; iTP < 4032; iTP++) {
    _TPEmuflag[iTP] = -99;
    _TPEmuonlineEnergyADC[iTP] = -99;
  }
  
//   std::cout << " tpEmuHandle.product()->size() = " << tpEmuHandle.product()->size() << std::endl;
  
  for (unsigned int i=0;i<tpEmuHandle.product()->size();i++) {
    EcalTriggerPrimitiveDigi d = (*(tpEmuHandle.product()))[i];
    const EcalTrigTowerDetId TPtowid = d.id();
       if (TPtowid.hashedIndex() < 4032) {
      _TPEmuflag[  TPtowid.hashedIndex() ] = (d[0].ttFlag());
      _TPEmuonlineEnergyADC[ TPtowid.hashedIndex() ] = (d[0].raw() & 0xfff);
//       std::cout << " (d[0].raw() & 0xfff) = " << (d[0].raw() & 0xfff) << std::endl;
      //       std::cout << " (d[0].raw()) = " << (d[0].raw()) << std::endl;
//       std::cout << "   (d[0].raw() & 0xfff) = " << (d[0].raw() & 0xfff);         std::cout << "   (d[0].raw()) = " << (d[0].raw() );
//       std::cout << "   (d[1].raw() & 0xfff) = " << (d[1].raw() & 0xfff);         std::cout << "   (d[1].raw()) = " << (d[1].raw() );
//       std::cout << "   (d[0].raw() & 0xfff) = " << (d[0].raw() & 0xfff);         std::cout << "   (d[0].raw()) = " << (d[0].raw() );
//       std::cout << "   (d[3].raw() & 0xfff) = " << (d[3].raw() & 0xfff);         std::cout << "   (d[3].raw()) = " << (d[3].raw() );
//       std::cout << "   (d[4].raw() & 0xfff) = " << (d[4].raw() & 0xfff);         std::cout << "   (d[4].raw()) = " << (d[4].raw() );
      
//       std::cout << std::endl;
       }    
  }
  
  
  
  
  
  
  
  
  
  
//   for (unsigned int i=0;i<digiEB.product()->size();i++) {
//     const EBDataFrame & df = (*(digiEB.product()))[i];    
//     const EBDetId & id = df.id();
//     const EcalTrigTowerDetId towid = id.tower();
//     itTT = mapTower.find(towid) ;
//     if (itTT != mapTower.end()) {
//       (itTT->second).nbXtal_++ ;
//       bool fill(false) ;
//       if (((itTT->second).tpgADC_ & 0xff)>0) fill = true ;   
//       for (int j=0 ; j<5 ; j++) if (((itTT->second).tpgEmul_[j] & 0xff)>8) fill = true ;                  
//       if (fill) {
//         if(print_) cout<<"TP="<<((itTT->second).tpgADC_ & 0xff)<<" eta="<<towid.ieta()<<" phi="<<towid.iphi()<<endl ;
//         if (print_) for (int j=0 ; j<5 ; j++) if (((itTT->second).tpgEmul_[j] & 0xff)>8) cout << "tp emul "<<  j << " " << ((itTT->second).tpgEmul_[j] & 0xff)<< endl;
//         treeVariablesShape_.ieta = towid.ieta() ;
//         treeVariablesShape_.iphi = towid.iphi() ;
//         treeVariablesShape_.ixXtal = id.iphi() ;
//         treeVariablesShape_.iyXtal = id.ieta() ;
//         treeVariablesShape_.TCCid = theMapping_->TCCid(towid);
//         treeVariablesShape_.TowerInTCC = theMapping_->iTT(towid);
//         const EcalTriggerElectronicsId elId = theMapping_->getTriggerElectronicsId(id) ;
//         treeVariablesShape_.strip = elId.pseudoStripId() ;
//         treeVariablesShape_.nbOfSamples = df.size() ;
//         for (int s=0 ; s<df.size() ; s++) treeVariablesShape_.samp[s] = df[s].adc() ; 
//         treeShape_->Fill() ;
//       }
//     }
//   }
  
  
  
  
  
  //   _multifit[j] = (j==5) ? it->amplitude() : it->outOfTimeAmplitude(j);

//   
//   
//   
//   auto detid = DetId(_id);
//   
//   for (int j=0; j<10; j++) _multifit[j] = 0;
//   _amplitude_weight = 0;
//   auto subGeom =  geometry->getSubdetectorGeometry(detid);
//   auto cellGeom = subGeom->getGeometry(detid);
//   _eta = cellGeom->getPosition().eta();
//   _phi = cellGeom->getPosition().phi();
//   auto it = rechits->find(detid);
//   if (it==rechits->end()) std::cout << "Warning: rechit (multifit) not found" << std::endl;
//   else {
//     
//     for (int j=0; j<10; j++) _multifit[j] = (j==5) ? it->amplitude() : it->outOfTimeAmplitude(j);
//     
//     _chi2 = it->chi2();
//     _jitter = it->jitter();
//     _jitterError = it->jitterError();
//     _amplitudeError = it->amplitudeError();
//     _recoflags = it->flags();
//     
//     
//   }
//   
  
  
   
  outTree->Fill();
  
   
}




// ------------ method called once each job just before starting event loop  ------------
void 
TreeProducerComparison::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TreeProducerComparison::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TreeProducerComparison::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TreeProducerComparison);
