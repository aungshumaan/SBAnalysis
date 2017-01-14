{
  #include "TLatex.h"
  ////2D plots
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}

  gStyle->SetOptStat(0);
  TH2F *h_data_bosonCen_dEta,*h_WV_0_0_bosonCen_dEta, *h_WV_0_01_bosonCen_dEta, *h_WV_03_0_bosonCen_dEta, *h_ZV_0_0_bosonCen_dEta, *h_ZV_0_01_bosonCen_dEta , *h_ZV_03_0_bosonCen_dEta ;
  TH2F *h_ttbar_bosonCen_dEta, *h_Wjets_bosonCen_dEta;  
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  //c2->Print(Form("plots_bosonCen_dEta_%s.pdf[",lepName.Data() ));
  
  //TFile *f=TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqCombQCD_plots.root");
  //TFile *f=TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10.1.root");
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_smw_2.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_smw_dEtaTag3p0_2.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_smw_bosonCen0p9_2.root");

  
  

              
  //const int nCut=1;TString cutName[nCut]={"SR"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  
  for (int icut =0; icut<nCut; icut++){
    /*
    //h_data_bosonCen_dEta=(TH2F*)f1->Get(Form("H_Data_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    //h_data_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Data_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_ttbar_bosonCen_dEta=(TH2F*)f1->Get(Form("H_Ttbar_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    h_ttbar_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Ttbar_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_Wjets_bosonCen_dEta=(TH2F*)f1->Get(Form("H_Wjets_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    h_Wjets_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Wjets_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_WV_0_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data() ));
    h_WV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_WV_0_01_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_WV_0_01_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    h_WV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_01_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    //h_WV_03_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_WV_03_0_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    //h_WV_03_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_03_0_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_ZV_0_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    h_ZV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    h_ZV_0_01_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_ZV_0_01_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    h_ZV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_01_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    //h_ZV_03_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_ZV_03_0_%sm_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data()));
    //h_ZV_03_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_03_0_%sp_WBF_%s_bosonCen_dEta",lep.Data(),cutName[icut].Data())) );
    */
    /////
    
    h_ttbar_bosonCen_dEta=(TH2F*)f1->Get(Form("H_Ttbar_ep_WBF_%s_bosonCen_dEta",cutName[icut].Data()));
    h_ttbar_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Ttbar_em_WBF_%s_bosonCen_dEta", cutName[icut].Data())) );
    h_ttbar_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Ttbar_mp_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ttbar_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Ttbar_mm_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );

    h_Wjets_bosonCen_dEta=(TH2F*)f1->Get(Form("H_Wjets_em_WBF_%s_bosonCen_dEta", cutName[icut].Data()));
    h_Wjets_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Wjets_ep_WBF_%s_bosonCen_dEta", cutName[icut].Data())) );
    h_Wjets_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Wjets_mp_WBF_%s_bosonCen_dEta", cutName[icut].Data())) );
    h_Wjets_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_Wjets_mm_WBF_%s_bosonCen_dEta", cutName[icut].Data())) );

    h_WV_0_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_WV_0_0_ep_WBF_%s_bosonCen_dEta",cutName[icut].Data() ));
    h_WV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_0_em_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_WV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_0_mp_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_WV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_0_mm_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_WV_0_01_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_WV_0_01_ep_WBF_%s_bosonCen_dEta",cutName[icut].Data()));
    h_WV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_01_em_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_WV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_01_mp_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_WV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_WV_0_01_mm_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );	

    h_ZV_0_0_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_ZV_0_0_ep_WBF_%s_bosonCen_dEta",cutName[icut].Data()));
    h_ZV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_0_em_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ZV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_0_mp_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ZV_0_0_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_0_mm_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ZV_0_01_bosonCen_dEta=(TH2F*)f1->Get(Form("H_VBS_ZV_0_01_ep_WBF_%s_bosonCen_dEta",cutName[icut].Data()));
    h_ZV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_01_em_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ZV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_01_mp_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
    h_ZV_0_01_bosonCen_dEta->Add( (TH2F*)f1->Get(Form("H_VBS_ZV_0_01_mm_WBF_%s_bosonCen_dEta",cutName[icut].Data())) );
          
    //h_data_bosonCen_dEta->Draw("colz");
    //h_data_bosonCen_dEta->SetTitle(Form("Data_%s boson centrality vs dEta",lepName.Data()) );
    //c2->Print(Form("plots_mTvsptwlep_%s.pdf",lepName.Data() ));   

    h_ttbar_bosonCen_dEta->Draw("colz");
    h_ttbar_bosonCen_dEta->SetTitle("");
    TLine* line5 = new TLine(0.,0., 4.0 ,8.0);
    //line5->SetLineColor(kRed);
    line5->SetLineWidth(3);
    line5->DrawLine(0.,0., 4.0 ,8.0);
  
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:ttbar_l_%s",cutName[icut].Data()));

    h_Wjets_bosonCen_dEta->Draw("colz");
    h_Wjets_bosonCen_dEta->SetTitle("");
    TLine* line6 = new TLine(0.,0., 4.0 ,8.0);
    line6->SetLineWidth(3);
    line6->DrawLine(0.,0., 4.0 ,8.0);
    TLatex l;
    l.SetTextSize(0.035); 
    l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
    l.SetTextColor(1); //black
    //l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
    l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Preliminary}");
    l.DrawLatex(0.20 , 0.78,"#int Ldt = 20.2 fb^{-1}");
    l.DrawLatex(0.20 , 0.72,Form("#bf{ W#rightarrow l#nu , %s}", cutName[icut].Data() ) );
    
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:Wjets_l_%s",cutName[icut].Data()));
    c2->Print(Form("PDF_syst_band/plots_bosonCen_dEta_%s.pdf",cutName[icut].Data() ));

    h_WV_0_0_bosonCen_dEta->Draw("colz");
    h_WV_0_0_bosonCen_dEta->SetTitle("" );
    TLine* line = new TLine(0.,0., 4.0 ,8.0);
    line->SetLineWidth(3);
    line->DrawLine(0.,0., 4.0 ,8.0);
    
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:WVSM_l_%s",cutName[icut].Data()));

    h_WV_0_01_bosonCen_dEta->Draw("colz");
    h_WV_0_01_bosonCen_dEta->SetTitle("");
    TLine* line2 = new TLine(0.,0., 4.0 ,8.0);
    line2->SetLineWidth(3);
    line2->DrawLine(0.,0., 4.0 ,8.0);
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:WV_0_0.1_l_%s",cutName[icut].Data()));
  
    /*
      h_WV_03_0_bosonCen_dEta->Draw("colz");
      h_WV_03_0_bosonCen_dEta->SetTitle(Form("WV(0.3,0)_%s boson centrality vs dEta",lepName.Data()) );
      c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ));
    */
    h_ZV_0_0_bosonCen_dEta->Draw("colz");
    h_ZV_0_0_bosonCen_dEta->SetTitle("");
    TLine* line3 = new TLine(0.,0., 4.0 ,8.0);
    line3->SetLineWidth(3);
    line3->DrawLine(0.,0., 4.0 ,8.0);
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:ZVSM_l_%s",cutName[icut].Data()));
  

    h_ZV_0_01_bosonCen_dEta->Draw("colz");
    h_ZV_0_01_bosonCen_dEta->SetTitle("");
    TLine* line4 = new TLine(0.,0., 4.0 ,8.0);
    line4->SetLineWidth(3);
    line4->DrawLine(0.,0., 4.0 ,8.0);
    //c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ),Form("Title:ZV_0_0.1_l_%s",cutName[icut].Data()));
  
    /*
      h_ZV_03_0_bosonCen_dEta->Draw("colz");
      h_ZV_03_0_bosonCen_dEta->SetTitle(Form("ZV(0.3,0)_%s boson centrality vs dEta",lepName.Data()) );
      c2->Print(Form("plots_bosonCen_dEta_%s.pdf",lepName.Data() ));	
    */
  }
  //f->Close();
  f1->Close();
   
  //c2->Print(Form("plots_bosonCen_dEta_%s.pdf]",lepName.Data() ));
}
