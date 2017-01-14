{
  ////2D plots
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}

  gStyle->SetOptStat(0);
  TH2F *h_data_mT_ptwlep,*h_WV_0_0_mT_ptwlep, *h_WV_0_02_mT_ptwlep, *h_WV_03_0_mT_ptwlep, *h_ZV_0_0_mT_ptwlep, *h_ZV_0_02_mT_ptwlep , *h_ZV_03_0_mT_ptwlep ;
    
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print(Form("plots_mTvsptwlep_%s.pdf[",lepName.Data() ));
  
  //TFile *f=TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqCombQCD_plots.root");
  //TFile *f=TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10.1.root");
  TFile *f1=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq.root");

              
  const int nCut=1;TString cutName[nCut]={"SR"};
  
        
  //h_data_mT_ptwlep=(TH2F*)f->Get(Form("H_Data_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  //h_data_mT_ptwlep->Add( (TH2F*)f->Get(Form("H_Data_%p_WBF_SR_mT_ptwlep",lep.Data())) );
  h_WV_0_0_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_WV_0_0_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  h_WV_0_02_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_WV_0_02_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_WV_0_02_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_02_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  h_WV_03_0_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_WV_03_0_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_WV_03_0_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_WV_03_0_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  h_ZV_0_0_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_ZV_0_0_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  h_ZV_0_02_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_ZV_0_02_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_ZV_0_02_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_02_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  h_ZV_03_0_mT_ptwlep=(TH2F*)f1->Get(Form("H_VBS_ZV_03_0_%sm_WBF_SR_mT_ptwlep",lep.Data()));
  h_ZV_03_0_mT_ptwlep->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_03_0_%sp_WBF_SR_mT_ptwlep",lep.Data())) );
  
  
  /////
          
  //h_data_mT_ptwlep->Draw("colz");
  //h_data_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  //h_data_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  //h_data_mT_ptwlep->SetTitle(Form("Data_%s mT vs lep pt",lepName.Data()) );
  //c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));   

  h_WV_0_0_mT_ptwlep->Draw("colz");
  h_WV_0_0_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_WV_0_0_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_WV_0_0_mT_ptwlep->SetTitle(Form("WV(0,0)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));

  h_WV_0_02_mT_ptwlep->Draw("colz");
  h_WV_0_02_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_WV_0_02_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_WV_0_02_mT_ptwlep->SetTitle(Form("WV(0,0.2)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));

  h_WV_03_0_mT_ptwlep->Draw("colz");
  h_WV_03_0_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_WV_03_0_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_WV_03_0_mT_ptwlep->SetTitle(Form("WV(0.3,0)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));

  h_ZV_0_0_mT_ptwlep->Draw("colz");
  h_ZV_0_0_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_ZV_0_0_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_ZV_0_0_mT_ptwlep->SetTitle(Form("ZV(0,0)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));

  h_ZV_0_02_mT_ptwlep->Draw("colz");
  h_ZV_0_02_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_ZV_0_02_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_ZV_0_02_mT_ptwlep->SetTitle(Form("ZV(0,0.2)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));

  h_ZV_03_0_mT_ptwlep->Draw("colz");
  h_ZV_03_0_mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
  h_ZV_03_0_mT_ptwlep->GetYaxis()->SetTitle("lepton p_{T} [GeV]");
  h_ZV_03_0_mT_ptwlep->SetTitle(Form("ZV(0.3,0)_%s mT vs ptWlep",lepName.Data()) );
  c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));	
 
     
  //f->Close();
  f1->Close();
   
  c2->Print(Form("plots_mTvsptwlep_%s.pdf]",lepName.Data() ));
}
