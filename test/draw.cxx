{
  #include <iostream>
  
  TTree* tree = (TTree*) _file0->Get("TreeProducer/tree");
  
  TCanvas* ccRatio = new TCanvas ("ccRatio", "", 800, 600);
  tree->Draw("TPCalibOfflineET/TPonlineETADC>> h4(100, 0, 3)", "TPonlineETADC>0 && TPCalibOfflineET>0 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h4->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h4->SetLineWidth(2);
  h4->Draw("hist");
  
  
  TCanvas* ccRatioHigh = new TCanvas ("ccRatioHigh", "", 800, 600);
  tree->Draw("TPCalibOfflineET/TPonlineETADC>> h3(100, 0, 3)", "TPonlineETADC>0 && TPCalibOfflineET>5 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h3->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h3->SetLineWidth(2);
  h3->Draw("hist");
  
  
  TCanvas* ccRatioVsET = new TCanvas ("ccRatioVsET", "", 800, 600);
  tree->Draw("TPCalibOfflineET/TPonlineETADC:TPCalibOfflineET >> h2(100,0,50, 100, 0, 3)", "TPonlineETADC>0 && TPCalibOfflineET>0", "colz");
  h2->GetXaxis()->SetTitle("E_{T} offline [GeV]");
  h2->GetYaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h2->Draw("colz");
  
  
  
  TCanvas* ccFlag = new TCanvas ("ccFlag", "", 800, 600);
  
  tree ->Draw("TPflag*(TPflag<2)+(TPflag>=2)*2>>h(3,0,3)", "TPonlineETADC>-1", "colz");
  h->GetXaxis()->SetTitle("TP flag");
  h->Scale (1./h->Integral());
  h->SetLineWidth(2);
  h->Draw("hist");
  
  std::cout << " TP flags " << std::endl;
  
  float flag_perc_LI = h->GetBinContent (1) *100 ;
  float flag_perc_MI = h->GetBinContent (2) *100 ;
  float flag_perc_HI = h->GetBinContent (3) *100 ;
  
  std::cout << " LI = " << flag_perc_LI << " % " << std::endl ;
  std::cout << " MI = " << flag_perc_MI << " % " << std::endl ;
  std::cout << " HI = " << flag_perc_HI << " % " << std::endl ;
  
  
}

  
  