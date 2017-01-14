{
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Print("plots_ptWlepStudy.pdf[");

  TFile *f  = TFile::Open("../hwwlvqq_az.2.root");
  TFile *f1 = TFile::Open("../hwwlvqq_az_alpgenWjets.root");
  TFile *f2 = TFile::Open("../hwwlvqq_lhf06.root");
  
  TH1F *h= (TH1F*)f->Get("H_Wjets_ep_WBF_WJET_ptwlep"); //sherpa W+jets
  h->Add( (TH1F*)f->Get("H_Wjets_em_WBF_WJET_ptwlep"));

  TH1F *h1= (TH1F*)f1->Get("H_Wjets_ep_WBF_WJET_ptwlep"); //Alpgen W+jets
  h1->Add( (TH1F*)f1->Get("H_Wjets_em_WBF_WJET_ptwlep"));

  TH1F *h2= (TH1F*)f2->Get("H_Data_ep_WBF_WJET_ptwlep"); //Data
  h2->Add( (TH1F*)f2->Get("H_Data_em_WBF_WJET_ptwlep"));

  //TH1F *h_error=SetBinContent();

 
  // h2->Scale(1/h2->Integral());
  // h1->Scale(1/h1->Integral());
  // h->Scale(1/h->Integral());

  h2->Draw();
  double maxi=h2->GetBinContent(h2->GetMaximumBin());
  h2->SetMaximum(1.5* maxi);
  h2->SetTitle("electron_WJET_ptWlep");
  //h->SetTitle("mu_WJET_ptWlep");  
  h->SetLineColor(kBlue);

  h->Draw("same");
  h->SetLineColor(kGreen);
  h1->Draw("same");
  h1->SetLineColor(kRed);


  TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
  l->AddEntry(h,"W+jets Sherpa","l");
  l->AddEntry(h1,"W+jets Alpgen","l");
  l->AddEntry(h2,"Data","l");

  
  l->Draw();
  
  c1->Print("plots_ptWlepStudy.pdf");

  
  TH1F *h_err= (TH1F*) h->Clone("h_err");
  TH1F *h1_err= (TH1F*) h1->Clone("h1_err");
  TH1F *h2_err= (TH1F*) h2->Clone("h2_err");
  for(int i=1;i<h->GetNbinsX();i++){
    h_err->SetBinContent(i,h->GetBinError(i));
    h1_err->SetBinContent(i,h1->GetBinError(i));
    h2_err->SetBinContent(i,h2->GetBinError(i));
  }

  h2_err->Draw("hist");
  double maxi=h2_err->GetBinContent(h2_err->GetMaximumBin());
  h2_err->SetMaximum(1.5* maxi);
  h2_err->SetTitle("StatError electron_WJET_ptWlep");
  //h->SetTitle("StatError mu_WJET_ptWlep");  
  h2_err->SetLineColor(kBlue);

  h_err->Draw("hist same");
  h_err->SetLineColor(kGreen);
  h1_err->Draw("hist same");
  h1_err->SetLineColor(kRed);

  TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
  l->AddEntry(h_err,"W+jets Sherpa","l");
  l->AddEntry(h1_err,"W+jets Alpgen","l");
  l->AddEntry(h2_err,"Data","l");

  
  l->Draw();

  c1->Print("plots_ptWlepStudy.pdf");
  
  c1->Print("plots_ptWlepStudy.pdf]");
}
