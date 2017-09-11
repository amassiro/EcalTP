// -*- C++ -*-
//
// Package:    AdvancedMultifitCMSSW/TreeProducer
// Class:      TreeProducer
// 
/**\class TreeProducer TreeProducer.cc AdvancedMultifitCMSSW/TreeProducer/plugins/TreeProducer.cc

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

class TreeProducer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit TreeProducer(const edm::ParameterSet&);
      ~TreeProducer();

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
      
      edm::EDGetTokenT<EcalTrigPrimDigiCollection> _token_tpCollection;
      edm::EDGetTokenT<EcalTrigPrimDigiCollection> _token_tpEmuCollection;
      
      
      TTree *outTree;
      
      UInt_t _run;
      UShort_t _lumi;
      UShort_t _bx;
      UShort_t _event;      
      int _flagEB[61200];
      float _onlineEnergyEB[61200];
      int _flagEE[14648];
      float _onlineEnergyEE[14648];
      
      float _TPflag[4032];
      float _TPonlineEnergyADC[4032];
      float _TPonlineEnergyTowerADC[4032];
      float _TPonlineETADC[4032];
      float _TPOfflineEnergy[4032];
      int   _TPOfflineNxtals[4032];
      
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
TreeProducer::TreeProducer(const edm::ParameterSet& iConfig)

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
   
   _token_tpCollection    = consumes<EcalTrigPrimDigiCollection>(iConfig.getParameter<edm::InputTag>("TPCollection")) ;
   _token_tpEmuCollection = consumes<EcalTrigPrimDigiCollection>(iConfig.getParameter<edm::InputTag>("TPEmuCollection")) ;
   
    
   
   outTree = fs->make<TTree>("tree","tree");
   
   outTree->Branch("run",               &_run,             "run/i");
   outTree->Branch("lumi",              &_lumi,            "lumi/s");
   outTree->Branch("bx",                &_bx,              "bx/s");
   outTree->Branch("event",             &_event,           "event/i");
   outTree->Branch("flagEB",               _flagEB,            "flagEB[61200]/F");
   outTree->Branch("onlineEnergyEB",       _onlineEnergyEB,    "onlineEnergyEB[61200]/F");
   outTree->Branch("flagEE",               _flagEE,            "flagEE[14648]/F");
   outTree->Branch("onlineEnergyEE",       _onlineEnergyEE,    "onlineEnergyEE[14648]/F");
   
   
   
   outTree->Branch("TPflag",                _TPflag,             "TPflag[4032]/F");
   outTree->Branch("TPonlineEnergyADC",                _TPonlineEnergyADC,             "TPonlineEnergyADC[4032]/F");
   outTree->Branch("TPonlineEnergyTowerADC",       _TPonlineEnergyTowerADC,    "TPonlineEnergyTowerADC[4032]/F");
   outTree->Branch("TPonlineETADC",       _TPonlineETADC,    "TPonlineETADC[4032]/F");
   outTree->Branch("TPOfflineEnergy",     _TPOfflineEnergy,  "TPOfflineEnergy[4032]/F");
   outTree->Branch("TPOfflineNxtals",     _TPOfflineNxtals,  "TPOfflineNxtals[4032]/I");
   
   
   
   outTree->Branch("TPEmuflag",                _TPEmuflag,             "TPEmuflag[4032]/F");
   outTree->Branch("TPEmuonlineEnergyADC",                _TPEmuonlineEnergyADC,             "TPEmuonlineEnergyADC[4032]/F");
   
   
   
   
   
}


TreeProducer::~TreeProducer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TreeProducer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  
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
  
  
  //---- rechits
  
  edm::Handle<EcalUncalibratedRecHitCollection> ebrechithandle;
  const EcalUncalibratedRecHitCollection *ebrechits = NULL;
  edm::Handle<EcalUncalibratedRecHitCollection> eerechithandle;
  const EcalUncalibratedRecHitCollection *eerechits = NULL;
  
  iEvent.getByToken(_token_ebrechits,ebrechithandle);
  ebrechits = ebrechithandle.product();
  iEvent.getByToken(_token_eerechits,eerechithandle);
  eerechits = eerechithandle.product();
  
  
  
  //---- fill information
  
  for (int ixtal=0; ixtal < 61200; ixtal++) {
    //---- Fill flag for this crystal
    _flagEB[ixtal] = -99;
    _onlineEnergyEB[ixtal] = -99;
  }
  for (int ixtal=0; ixtal < 14648; ixtal++) {
    //---- Fill flag for this crystal
    _flagEE[ixtal] = -99;
    _onlineEnergyEE[ixtal] = -99;
  }
  
  
//   std::cout << " > ebrechits->size() = " << ebrechits->size() << std::endl;
//   std::cout << " > eerechits->size() = " << eerechits->size() << std::endl;
//   std::cout << " ~~ " << std::endl;
  
  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = ebrechits->begin(); itrechit != ebrechits->end(); itrechit++ ) {
    _onlineEnergyEB[EBDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();
//     std::cout << "EB = " << itrechit->amplitude() << std::endl;
//     std::cout << "EB = " << itrechit->id().subdetId() << " -- " << itrechit->id().rawId() << " -- "  << std::endl;
//     std::cout << "   = " << EBDetId(itrechit->id()).hashedIndex() << " -- "  << std::endl;

//     const EcalTrigTowerDetId towid = EBDetId(itrechit->id()).tower();
    
    
  }

  
  for (EcalUncalibratedRecHitCollection::const_iterator itrechit = eerechits->begin(); itrechit != eerechits->end(); itrechit++ ) {
    _onlineEnergyEE[EEDetId(itrechit->id()).hashedIndex()] =  itrechit->amplitude();
//     std::cout << "EE = " << itrechit->amplitude() << std::endl;
//     std::cout << "EE = " << itrechit->id().subdetId() << " -- " << itrechit->id().rawId() << " -- "  << std::endl;
//     std::cout << "   = " << EEDetId(itrechit->id()).hashedIndex() << " -- "  << std::endl;
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
    _TPOfflineNxtals[iTP] = -99;
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
      if(towerId.subDet() == EcalBarrel) {
        for (EcalUncalibratedRecHitCollection::const_iterator itrechit = ebrechits->begin(); itrechit != ebrechits->end(); itrechit++ ) {
          int thisXtalTowidHI = (EBDetId(itrechit->id()).tower()).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->amplitude();
          }
        }
        _TPOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
      }
      else {
        for (EcalUncalibratedRecHitCollection::const_iterator itrechit = eerechits->begin(); itrechit != eerechits->end(); itrechit++ ) {
          
          int thisXtalTowidHI = EcalTrigTowerDetId( EEDetId(itrechit->id()).zside(),EcalEndcap, EEDetId(itrechit->id()).ix(), EEDetId(itrechit->id()).iy()  );
          //             int thisXtalTowidHI = (EEDetId(itrechit->id()).tower()).hashedIndex();
          if (thisXtalTowidHI==thisTowerHI) {
            numberXtal++;
            towerEnergy = towerEnergy + itrechit->amplitude();
          }
        }
        _TPOfflineEnergy [ TPtowid.hashedIndex() ] = towerEnergy;
        _TPOfflineNxtals [ TPtowid.hashedIndex() ] = numberXtal;
        //         std::cout << "# xtals = " << numberXtal << ", towerEnergy = " << towerEnergy << std::endl;
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
TreeProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TreeProducer::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TreeProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TreeProducer);
