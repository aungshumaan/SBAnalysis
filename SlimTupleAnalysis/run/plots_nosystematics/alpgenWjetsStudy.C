{
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Print("plots_alpgenWjets.pdf[");
  
  TFile *f = TFile::Open("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_individualWjetsNpSamples.root");
  TFile *f1 = TFile::Open("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_az_alpgenWjets.root");

  
  const int nRegion =4; TString regionName[nRegion] = {"BTAG","CR_Top","CR_Wjj","SR"};

  for (int iRegion=0;iRegion<nRegion;iRegion++){
    c1->SetLogy(0);
 
  
    //el
    TH1F *h_alp= (TH1F*)f1->Get(Form("H_Wjets_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h_alp->Add( (TH1F*)f1->Get(Form("H_Wjets_em_WBF_%s_ptwlep",regionName[iRegion].Data())) );
    
    TH1F *h= (TH1F*)f->Get(Form("H_WNp0_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h->Add( (TH1F*)f->Get(Form("H_WNp0_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
    TH1F *h1= (TH1F*)f->Get(Form("H_WNp1_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h1->Add( (TH1F*)f->Get(Form("H_WNp1_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
    TH1F *h2= (TH1F*)f->Get(Form("H_WNp2_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h2->Add( (TH1F*)f->Get(Form("H_WNp2_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
    TH1F *h3= (TH1F*)f->Get(Form("H_WNp3_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h3->Add( (TH1F*)f->Get(Form("H_WNp3_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
    TH1F *h4= (TH1F*)f->Get(Form("H_WNp4_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h4->Add( (TH1F*)f->Get(Form("H_WNp4_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
    TH1F *h5= (TH1F*)f->Get(Form("H_WNp5_ep_WBF_%s_ptwlep",regionName[iRegion].Data()));
    h5->Add( (TH1F*)f->Get(Form("H_WNp5_em_WBF_%s_ptwlep",regionName[iRegion].Data())));
  
    //mu
    // TH1F *h_alp= (TH1F*)f1->Get(Form("H_Wjets_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h_alp->Add( (TH1F*)f1->Get(Form("H_Wjets_mm_WBF_%s_ptwlep",regionName[iRegion].Data())) );
    
    // TH1F *h= (TH1F*)f->Get(Form("H_WNp0_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h->Add( (TH1F*)f->Get(Form("H_WNp0_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));
    // TH1F *h1= (TH1F*)f->Get(Form("H_WNp1_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h1->Add( (TH1F*)f->Get(Form("H_WNp1_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));
    // TH1F *h2= (TH1F*)f->Get(Form("H_WNp2_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h2->Add( (TH1F*)f->Get(Form("H_WNp2_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));
    // TH1F *h3= (TH1F*)f->Get(Form("H_WNp3_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h3->Add( (TH1F*)f->Get(Form("H_WNp3_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));
    // TH1F *h4= (TH1F*)f->Get(Form("H_WNp4_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h4->Add( (TH1F*)f->Get(Form("H_WNp4_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));
    // TH1F *h5= (TH1F*)f->Get(Form("H_WNp5_mp_WBF_%s_ptwlep",regionName[iRegion].Data()));
    // h5->Add( (TH1F*)f->Get(Form("H_WNp5_mm_WBF_%s_ptwlep",regionName[iRegion].Data())));

    // h4->Scale(1/h4->Integral());
    // h5->Scale(1/h5->Integral());
    // h3->Scale(1/h3->Integral());
    // h2->Scale(1/h2->Integral());
    // h1->Scale(1/h1->Integral());
    // h->Scale(1/h->Integral());

    h4->Draw();
    //double maxi=h->GetBinContent(h->GetMaximumBin());
    double maxi=h4->GetBinContent(h4->GetMaximumBin());
    h4->SetMaximum(1.5* maxi);
    h4->SetTitle(Form("electron_%s_ptWlep",regionName[iRegion].Data()) );
    //h4->SetTitle(Form("mu_%s_ptWlep",regionName[iRegion].Data()) );  
    h4->SetLineColor(kBlue);
    h5->Draw("same");
    h5->SetLineColor(kViolet);
    h3->Draw("same");
    h3->SetLineColor(kGreen);
    h2->Draw("same");
    h2->SetLineColor(kRed);
    h1->Draw("same");
    h1->SetLineColor(kOrange);
    h->Draw("same");
    h->SetLineColor(kYellow);

    TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    l->AddEntry(h,"Np0","l");
    l->AddEntry(h1,"Np1","l");
    l->AddEntry(h2,"Np2","l");
    l->AddEntry(h3,"Np3","l");
    l->AddEntry(h4,"Np4","l");
    l->AddEntry(h5,"Np5incl","l");
  
    l->Draw();

    c1->Print("plots_alpgenWjets.pdf");
    c1->SetLogy(1);

    TH1F *h_err= (TH1F*) h->Clone("h_err");
    TH1F *h1_err= (TH1F*) h1->Clone("h1_err");
    TH1F *h2_err= (TH1F*) h2->Clone("h2_err");
    TH1F *h3_err= (TH1F*) h3->Clone("h2_err");
    TH1F *h4_err= (TH1F*) h4->Clone("h2_err");
    TH1F *h5_err= (TH1F*) h5->Clone("h2_err");

    TH1F *h_alp_err= (TH1F*) h_alp->Clone("h_alp_err");
  

    for(int i=1;i<h->GetNbinsX();i++){
      h_err->SetBinContent(i,h->GetBinError(i));
      h1_err->SetBinContent(i,h1->GetBinError(i));
      h2_err->SetBinContent(i,h2->GetBinError(i));
      h3_err->SetBinContent(i,h3->GetBinError(i));
      h4_err->SetBinContent(i,h4->GetBinError(i));
      h5_err->SetBinContent(i,h5->GetBinError(i));

      h_alp_err->SetBinContent(i,h_alp->GetBinError(i));
    }

    double maxi=h2_err->GetBinContent(h2_err->GetMaximumBin());
    double tmp =h_err->GetBinContent(h_err->GetMaximumBin());
    if(tmp>maxi){maxi=tmp;}
    tmp=h3_err->GetBinContent(h3_err->GetMaximumBin());
    if(tmp>maxi){maxi=tmp;}
    tmp=h4_err->GetBinContent(h4_err->GetMaximumBin());
    if(tmp>maxi){maxi=tmp;}
    tmp=h5_err->GetBinContent(h5_err->GetMaximumBin());
    if(tmp>maxi){maxi=tmp;}
    tmp=h_alp_err->GetBinContent(h_alp_err->GetMaximumBin());
    if(tmp>maxi){maxi=tmp;}

    h2_err->Draw("hist");
    h2_err->SetMaximum(100* maxi);
    h2_err->SetTitle(Form("StatError electron_%s_ptWlep",regionName[iRegion].Data()));
    //h2_err->SetTitle(Form("StatError mu_%s_ptWlep",regionName[iRegion].Data()));
    h2_err->SetLineColor(kRed);

    h_err->Draw("hist same");
    h_err->SetLineColor(kYellow);
    h1_err->Draw("hist same");
    h1_err->SetLineColor(kOrange);
    h3_err->Draw("hist same");
    h3_err->SetLineColor(kGreen);
    h4_err->Draw("hist same");
    h4_err->SetLineColor(kBlue);
    h5_err->Draw("hist same");
    h5_err->SetLineColor(kViolet);

    h_alp_err->Draw("hist same");
    h_alp_err->SetLineColor(kBlack);

    TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    l->AddEntry(h_err,"Np0","l");
    l->AddEntry(h1_err,"Np1","l");
    l->AddEntry(h2_err,"Np2","l");
    l->AddEntry(h3_err,"Np3","l");
    l->AddEntry(h4_err,"Np4","l");
    l->AddEntry(h5_err,"Np5","l");
    l->AddEntry(h_alp_err,"Total","l");

  
    l->Draw();

    c1->Print("plots_alpgenWjets.pdf");
  }
  

  c1->Print("plots_alpgenWjets.pdf]");

}
