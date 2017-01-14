{
  #include "makeFitBin_mTWV2.h"
  
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  c2->Print("plots_ttbarAcerMC2.pdf["); //&&&&
  gStyle->SetOptStat(0);
  TFile *f=TFile::Open("../hwwlvqq.Nominal.caf4.2.lv8_smw_separateWjetsEWK.root");
  //gDirectory->ls();
  //const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};

  //for (int itype=0;itype<nType;++itype){
  // TH1F* httbar = (TH1F*)f -> Get("H_Ttbar_mp_WBF_SR_mTWV");
  // TH1F* httbarAMCup = (TH1F*)f -> Get("H_TtbarAcerMCUp_mp_WBF_SR_mTWV");
  // TH1F* httbarAMCdown = (TH1F*)f -> Get("H_TtbarAcerMCDown_mp_WBF_SR_mTWV");

  TH1F* hin = (TH1F*)f -> Get("H_Ttbar_mp_WBF_SR_mTWV");
  TH1F* hin_fat = (TH1F*)f -> Get("H_Ttbar_mp_WBF_SRfatOnly_mTWV");

  // Float_t bins[]= {0., 300., 500., 600., 700., 1500.};
  
  // Int_t binnum = sizeof(bins)/sizeof(Float_t) -1;

  // Float_t bins_fat[]= {300., 600., 700., 800.,  1500.};
  
  // Int_t binnum_fat = sizeof(bins_fat)/sizeof(Float_t) -1;

  TH1F* httbar =makeFitBin_mTWV_resolve( hin);
  TH1F* httbar_fat =makeFitBin_mTWV_merge( hin_fat);
  
  hin->Draw();
  c2->Print("plots_ttbarAcerMC2.pdf");
  makeFitBin_mTWV_resolve( hin);
  c2->SetLogy();
  httbar->Draw();
  c2->Print("plots_ttbarAcerMC2.pdf");

  c2->SetLogy(0);
  hin_fat->Draw();
  c2->Print("plots_ttbarAcerMC2.pdf");
  makeFitBin_mTWV_merge( hin_fat);
  c2->SetLogy();
  httbar_fat->Draw();
  c2->Print("plots_ttbarAcerMC2.pdf");

  // TLegend *leg = new TLegend(0.6, 0.70, 0.9, 0.88) ;
  // leg->SetNColumns(2);
  
  
  // leg->AddEntry(httbarAMCup,"AcerMC up","l");
  // leg->AddEntry(httbarAMCdown,"AcerMC down","l");

  // leg->AddEntry(httbar,"ttbar","l");

  // leg->Draw();


  c2->Print("plots_ttbarAcerMC2.pdf]"); //&&&&
  //}
}
