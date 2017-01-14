{
  TFile *f = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.28Apr2016.root");

  //TFile *f1 = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW_10.root");
  TFile *f1 = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_ttbar.root");

  // TH1F *hnom = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV");
  // // TH1F *hfac4 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_fac4");
  // // TH1F *hfac025 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_fac025");
  // //TH1F *hfac4 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_renorm4");
  // //TH1F *hfac025 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_renorm025");
  // TH1F *hfac4 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_ckkw30");
  // TH1F *hfac025 = f->Get("H_Wjets_ep_WBF_CR_WjjfatOnly_mTWV_ckkw15");

  //TH1F *hnom = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV");
  //TH1F *hfac4 = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV_McnloVsPowheg");
  //TH1F *hfac025 = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV_HerwigVsPythia");

  

  //TH1F *hnom = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV_McnloVsPowheg"); //compare MC@NLO
  //TH1F *hfac4 = f1->Get("H_TtbarMCatNLO_ep_WBF_CR_Top_mTWV");

  //TH1F *hnom = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV_HerwigVsPythia");//compare PowHeg+Herwig
  //TH1F *hfac4 = f1->Get("H_TtbarPowHer_ep_WBF_CR_Top_mTWV");
  
  TH1F *hnom = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV_AcerMCUpDown"); //compare AcerMC
  TH1F *hfac4 = f1->Get("H_TtbarAcerMCUp_ep_WBF_CR_Top_mTWV");

  //TH1F *hnom = f->Get("H_Ttbar_ep_WBF_CR_Top_mTWV");
  //TH1F *hfac4 = f1->Get("H_Ttbar_ep_WBF_CR_Top_mTWV");


  TCanvas *c1 = new TCanvas("","",0,0,750,700);
  c1->cd();

  //hfac4->Scale(hnom->Integral()/hfac4->Integral());
  //hfac025->Scale(hnom->Integral()/hfac025->Integral());
  hnom->Draw("hist");
  hfac4->Draw("same");
  hfac4->SetLineColor(kRed);
  //hfac025->Draw("same");
  //hfac025->SetLineColor(kGreen);
  int nbins = hnom->GetNbinsX();
  double fracerr =0;
  double fracerr2 =0;
  cout<<nbins<<endl;
  for(int ibin = 1; ibin < nbins; ibin++){
    fracerr = (hnom->GetBinContent(ibin)-hfac4->GetBinContent(ibin))/hnom->GetBinContent(ibin);
    //fracerr2 = (hnom->GetBinContent(ibin)-hfac025->GetBinContent(ibin))/hnom->GetBinContent(ibin);
    //cout<<ibin<<" : "<<fracerr<<", "<<fracerr2<<endl;
  }
  
  c1->Print("plots_blah.pdf");

}
