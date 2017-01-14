{
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_New_all97.root");
  TFile *f = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_10_April30/lvqqCombQCD_plots.root");
  
  //TString region = "SRfatOnly";
  //TString region = "SR";
  //TString region = "CR_Wjj";
  TString region = "CR_WjjfatOnly";
    

  //TString sample = "VBS_ZV_0_0";
  //TString sample = "VBS_WV_0_0";
    
  //TString sample = "WjetsScaled";
  //TString sample = "Ttbar";
  //TString sample = "Zjets";
  //TString sample = "SingleTop";
  //TString sample = "WZZZWg";
  TString sample = "QCD";

  TH1F *h1 = f->Get(Form("H_%s_mp_WBF_%s_Njet",sample.Data(),region.Data()));
  TH1F *h2 = f->Get(Form("H_%s_mm_WBF_%s_Njet",sample.Data(),region.Data()));
  TH1F *h3 = f->Get(Form("H_%s_ep_WBF_%s_Njet",sample.Data(),region.Data()));
  TH1F *h4 = f->Get(Form("H_%s_em_WBF_%s_Njet",sample.Data(),region.Data()));
  
  /*
  cout<<h1->Integral()<<endl;
  cout<<h2->Integral()<<endl;
  cout<<h3->Integral()<<endl;
  cout<<h4->Integral()<<endl;
  */

  cout<<h1->Integral()+h2->Integral()+h3->Integral()+h4->Integral()<<endl;
}
