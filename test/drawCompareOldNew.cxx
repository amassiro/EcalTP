{
  #include <iostream>
  
  TTree* tree = (TTree*) _file0->Get("TreeProducer/tree");
  TTree* tre1 = (TTree*) _file1->Get("TreeProducer/tree");
  
  TCanvas* ccRatio = new TCanvas ("ccRatio", "", 800, 600);
  tree->Draw("TPCalibOfflineET/TPonlineETADC>> h4(100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>0 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h4->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h4->Scale (1./h4->Integral());
  h4->SetLineWidth(2);

  tre1->Draw("TPCalibOfflineET/TPonlineETADC>> h4_1(100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>0 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h4_1->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h4_1->SetLineWidth(2);
  h4_1->Scale (1./h4_1->Integral());
  h4_1->SetMarkerColor(2);
  h4_1->SetLineColor(2);
  
  h4->Draw("hist");
  h4_1->Draw("P same");
  

  TLegend* leg = new TLegend (0.65,0.75,0.90,0.90);
  leg -> AddEntry (h4,    "Old",   "L");
  leg -> AddEntry (h4_1,  "New", "PL");
  leg -> Draw();
  
  
  TCanvas* ccRatioHigh = new TCanvas ("ccRatioHigh", "", 800, 600);
  tree->Draw("TPCalibOfflineET/TPonlineETADC>> h3(100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>5 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h3->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h3->SetLineWidth(2);
  h3->Scale (1./h3->Integral());
  
  tre1->Draw("TPCalibOfflineET/TPonlineETADC>> h3_1(100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>5 && TPCalibOfflineET/TPonlineETADC<10", "colz");
  h3_1->GetXaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h3_1->SetLineWidth(2);
  h3_1->Scale (1./h3_1->Integral());
  h3_1->SetMarkerColor(2);
  h3_1->SetLineColor(2);
  h3->Draw("hist");
  h3_1->Draw("P same");
  leg -> Draw();
  
  
  TCanvas* ccRatioVsET = new TCanvas ("ccRatioVsET", "", 900, 600);
  ccRatioVsET->Divide(1,2);
 
  ccRatioVsET->cd(1);
  tree->Draw("TPCalibOfflineET/TPonlineETADC:TPCalibOfflineET >> h2(100,0,50, 100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>0", "colz");
  h2->SetTitle("Old");
  h2->GetXaxis()->SetTitle("E_{T} offline [GeV]");
  h2->GetYaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h2->Draw("colz");
 
  ccRatioVsET->cd(2);
  tre1->Draw("TPCalibOfflineET/TPonlineETADC:TPCalibOfflineET >> h2_1(100,0,50, 100, 0, 10)", "TPonlineETADC>0 && TPCalibOfflineET>0", "colz");
  h2_1->SetTitle("New");
  h2_1->GetXaxis()->SetTitle("E_{T} offline [GeV]");
  h2_1->GetYaxis()->SetTitle("E_{T} offline / E_{T} TP");
  h2_1->Draw("colz");
  
  
  
  TCanvas* ccFlag = new TCanvas ("ccFlag", "", 800, 600);
  
  tree ->Draw("TPflag*(TPflag<2)+(TPflag>=2)*2>>h(3,0,3)", "TPonlineETADC>-1", "colz");
  h->GetXaxis()->SetTitle("TP flag");
  h->Scale (1./h->Integral());
  h->SetLineWidth(2);


  tre1 ->Draw("TPflag*(TPflag<2)+(TPflag>=2)*2>>h_1(3,0,3)", "TPonlineETADC>-1", "colz");
  h_1->GetXaxis()->SetTitle("TP flag");
  h_1->Scale (1./h_1->Integral());
  h_1->SetLineWidth(2);
  h_1->SetMarkerColor(2);
  h_1->SetLineColor(2);
  h->Draw("hist");
  h_1->Draw("P same");
  leg -> Draw();
  
  std::cout << " TP flags " << std::endl;
  
 
  float flag_perc_LI = h->GetBinContent (1) *100 ;
  float flag_perc_MI = h->GetBinContent (2) *100 ;
  float flag_perc_HI = h->GetBinContent (3) *100 ;
  
  float flag_perc_LI_1 = h_1->GetBinContent (1) *100 ;
  float flag_perc_MI_1 = h_1->GetBinContent (2) *100 ;
  float flag_perc_HI_1 = h_1->GetBinContent (3) *100 ;
  
                                 
  std::cout << "              Old                    New        " << std::endl;
  std::cout << " LI = " << flag_perc_LI << " % ->   " << flag_perc_LI_1 << " % " << std::endl ;
  std::cout << " MI = " << flag_perc_MI << " % ->   " << flag_perc_MI_1 << " % " << std::endl ;
  std::cout << " HI = " << flag_perc_HI << " % ->   " << flag_perc_HI_1 << " % " << std::endl ;
                                                                                    
  
  
  
  
  TCanvas* ccFlagVsEt = new TCanvas ("ccFlagVsEt", "", 800, 600);
  
  tree ->Draw("TPflag:TPonlineETADC>>hflaget(120,0,6,6,0,6)", "TPonlineETADC>-1", "colz");
  hflaget->GetYaxis()->SetTitle("TP flag");
  hflaget->GetXaxis()->SetTitle("E_{T} [GeV]");
  hflaget->SetLineWidth(3);
  hflaget->SetLineStyle(2);
  hflaget->SetMarkerColor(1);
  hflaget->SetLineColor(1);
  
  
  tre1  ->Draw("TPflag:TPonlineETADC>>hflaget_1(1200,0,6,6,0,6)", "TPonlineETADC>-1", "colz");
  hflaget_1->GetYaxis()->SetTitle("TP flag");
  hflaget_1->GetXaxis()->SetTitle("E_{T} [GeV]");
  hflaget_1->SetLineWidth(2);
  hflaget_1->SetMarkerColor(2);
  hflaget_1->SetLineColor(2);
  hflaget  ->Draw("box");
  hflaget_1->Draw("box same");
  
  leg -> Draw();
  
  
  
}


