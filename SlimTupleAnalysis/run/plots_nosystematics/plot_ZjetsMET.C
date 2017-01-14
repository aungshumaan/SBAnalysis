{

#include <TLatex.h>
  bool DEBUG =false;
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_sherpaAlp.pdf[","pdf");

#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"
  //#include "makerHelper.h"
  
  bool doThree =0;

  //TFile *f1=TFile::Open("../hwwlvqq_njet0.root");
  TFile *f1=TFile::Open("../hwwlvqq_njet0TST.root");
  //TFile *f1=TFile::Open("../HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst/hwwlvqq.Nominal.small.root");
  //TFile *f2=TFile::Open("../fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW_10.root");
  //TFile *f2=TFile::Open("../hwwlvqq_njet2.root");
  //TFile *f2=TFile::Open("../hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_cutflow.root");
  
  
  
  
  TH1F* h1=(TH1F*)f1->Get("H_Zjets_ep_WBF_OneGoodLep0jet_MET_et");
  TH1F* h2=(TH1F*)f1->Get("H_Zjets_ep_WBF_OneGoodLep1jet_MET_et");
  TH1F* h3=(TH1F*)f1->Get("H_Zjets_ep_WBF_OneGoodLep2jet_MET_et");
  //TH1F* h1=(TH1F*)f1->Get("H_Zjets_ep_WBF_TwoGoodLep0jet_MET_et");
  //TH1F* h2=(TH1F*)f1->Get("H_Zjets_ep_WBF_TwoGoodLep1jet_MET_et");
  //TH1F* h3=(TH1F*)f1->Get("H_Zjets_ep_WBF_TwoGoodLep2jet_MET_et");
  
	
  //AddOverflowBinToLastBin(h1);
  //AddOverflowBinToLastBin(h2);
    
  //doVariableBinHisto(h1);
  //doVariableBinHisto(h2);
  	
  bool logy=false;
  
  double padRatio =0.01;// 0.35;
  TPad* p1 = new TPad("p1","p1",0.01, padRatio ,0.99,0.99);
  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, padRatio);
  p1->Draw();
  //p2->Draw();
  p1->cd();
  logy = false;
  
  p1->SetLogy(logy); 
  
  //cout<<"Hello!!"<<endl;
  h1->SetLineColor(kBlack);
  h1->Scale(1/h1->Integral());

  //h1->SetTitle("");
  
  h1->Draw();
    
  h2->SetLineColor(kRed);
  h2->Scale(1/h2->Integral());
  //h2->Scale(h1->Integral()/h2->Integral());
  h2->Draw("same");
  
  h3->SetLineColor(kBlue);
  h3->Scale(1/h3->Integral());
  //h3->Scale(h1->Integral()/h3->Integral());
  h3->Draw("same");
    
    
  //cout<<"Hello2!!"<<endl;
  
	  
  double maxi= h1->GetBinContent(h1->GetMaximumBin());
  if (maxi <h2->GetBinContent(h2->GetMaximumBin())){
    maxi=h2->GetBinContent(h2->GetMaximumBin());
  }
  if (logy)
    {h1->SetMaximum(maxi*100);}
  else
    {h1->SetMaximum(maxi*1.5);}
  
  TLegend *l=new TLegend(0.2,0.75,0.9,0.9);
  
  l.SetTextSize(0.03);
  
  
  //l->AddEntry(h1,"no cut on Njet ","l");
  //l->AddEntry(h2,"Njet >=2","l");

  l->AddEntry(h1,"","l");
  l->AddEntry(h2,"","l");
  l->AddEntry(h3,"","l");
    
  
  l->Draw();
  
  	  
  p2->cd();
  gStyle->SetOptStat(0);
  TH1F *ratioHist = (TH1F*)h2->Clone();
  ratioHist->Divide(h1);
    
  ratioHist->GetYaxis()->SetRangeUser(0.3, 2.);
  
  //ratioHist->SetMarkerStyle(20);
  //setRatioPlotStyle (ratioHist);
  ratioHist->SetMarkerColor(h2->GetLineColor());
  ratioHist->Draw();

  ratioHist->SetTitle("ratio");
  
  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
  horiz_line->SetLineStyle(2);
  horiz_line->DrawLine(0.,1.0,20. ,1.0);
   
  c1->Print("plots_sherpaAlp.pdf");
    
  p1->Clear();
  p2->Clear();
  
  c1->cd();
  
  


  //f1->Close();
  //f2->Close();
  
  c1->Print("plots_sherpaAlp.pdf]","pdf");
}
