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
  c1->Print("plots_syst_response.pdf[","pdf");


  const int nsyst =1;
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};

  TString systname[nsyst]={"NP_Special1JES"}
  
 

  TFile *fsyst=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_NP_Special1JES.test2.root");
  
  TH1F *hsystup =(TH1F*)fsyst->Get("H_VBS_WV_0_0_ep_WBF_SR_jet1_pt_systUp" );
  TH1F *hsystdown =(TH1F*)fsyst->Get("H_VBS_WV_0_0_ep_WBF_SR_jet1_pt_systDown" );
  TH1F *hnom =(TH1F*)fsyst->Get("H_VBS_WV_0_0_ep_WBF_SR_jet1_pt_Nominal" );

  // TH1F *ratioHistUp =(TH1F*)fsyst->Get("H_VBS_WV_0_0_ep_WBF_SR_jet1_pt_systUp" );
  // TH1F *ratioHistDown =(TH1F*)fsyst->Get("H_VBS_WV_0_0_ep_WBF_SR_jet1_pt_systDown" );

  TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
  p1->Draw();
  p2->Draw();
  p1->cd();


  hnom->SetLineColor(kBlack);
  hnom->Draw();
  
  hsystup->SetLineColor(kRed);
    
  hsystup->Draw("same");
  
  hsystdown->SetLineColor(kBlue);
  hsystdown->Draw("same");

  hnom->SetBinContent(hnom->GetNbinsX(),hnom->GetBinContent(hnom->GetNbinsX())+hnom->GetBinContent(hnom->GetNbinsX()+1));
  hsystup->SetBinContent(hsystup->GetNbinsX(),hsystup->GetBinContent(hsystup->GetNbinsX())+hsystup->GetBinContent(hsystup->GetNbinsX()+1));
  hsystdown->SetBinContent(hsystdown->GetNbinsX(),hsystdown->GetBinContent(hsystdown->GetNbinsX())+hsystdown->GetBinContent(hsystdown->GetNbinsX()+1));
 
  
  cout<<"hnom nevent = "<<hnom->Integral()<<endl;
  cout<<"hsystup nevent = "<<hsystup->Integral()<<endl;
  cout<<"hsystdown nevent = "<<hsystdown->Integral()<<endl;
  
  
  double maxi=hnom->GetBinContent(hnom->GetMaximumBin());
  
  hnom->SetMaximum(maxi*1.5);
  
  TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
  l->AddEntry(hsystup,"JESUp","l");
  l->AddEntry(hsystdown,"JESDown","l");
  l->AddEntry(hnom,"Nominal","l");
  
  l->Draw();

  double xstart=hnom->GetBinLowEdge(1);
  double xend=hnom->GetBinLowEdge(hnom->GetNbinsX()+1);
	    
  p2->cd();
  gStyle->SetOptStat(0);

  TH1F* ratioHistUp= hsystup->Clone("ratioUp");
  ratioHistUp->Divide(hnom);
  TH1F* ratioHistDown= hsystdown->Clone("ratioDown");
  ratioHistDown->Divide(hnom);

  
 
  ratioHistUp->Draw("hist][");
  //ratioHistUp->GetYaxis()->SetRangeUser(0.5,1.5);
  ratioHistUp->GetYaxis()->SetRangeUser(0.98,1.02);
 
  //ratioHist->SetMarkerStyle(20);
  
  ratioHistUp->GetYaxis()->SetLabelSize(0.07);
  ratioHistUp->GetXaxis()->SetLabelSize(0.07);

  ratioHistDown->Draw("hist][ same");
  

	    

  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
  horiz_line->SetLineStyle(2);
  horiz_line->DrawLine(xstart,1.0,xend,1.0);
	    
  c1->Print("plots_syst_response.pdf");
  p1->Close();
  p2->Close();
  
  
  c1->Print("plots_syst_response.pdf]","pdf");
}
