#include <iostream>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TLegend.h>
#include <TLine.h>
#include <TStyle.h>

using namespace std;

#define doShape 0
#define doMuon 0

void Wgamma(){
  
  ///this code is for investigation of Wgamma  samples

  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_Wgamma.pdf[","pdf");

  TH1F *h1,*h2,*h3;
  TH2F *h;
  
  TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac.root");
  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac0.95.root");
  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac0.98.root");
  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac0.99.root");
    
  //const int nRegion=4; TString regionName[nRegion]={"WBF_PRESELECT","WBF_WJET","WBF_BTAG","WBF_SR"};
  //const int nRegion=3; TString regionName[nRegion]={"WBF_WJET","WBF_BTAG","WBF_SR"};
  const int nRegion=1; TString regionName[nRegion]={"WBF_WJET"};
  
  //const int nHist =3 ;TString histName[nHist]={"Njet","min_dR_lepjet","jet_emfrac"};
  //const int nHist =2 ;TString histName[nHist]={"jet1_pt","jet_emfrac"};
  //const int nHist =5 ;TString histName[nHist]={"jet_emfrac","jet1_emfrac","jet2_emfrac","wjet1_emfrac","wjet2_emfrac"};
  //const int nHist =4 ;TString histName[nHist]={"jet1_pt","jet1_eta","jet_jvtxf_emfrac_pass","jet_jvtxf_emfrac_fail" } ;
  const int nHist =6 ;TString histName[nHist]={"jet_jvtxf_jetpt_gt50","jet_emfrac_jetpt_gt50", "jet_jvtxf_jeteta_gt24","jet_emfrac_jeteta_gt24", "jet_jvtxf_jvfregion","jet_emfrac_jvfregion" };
  //const int nHist =1 ;TString histName[nHist]={"jet1_pt"};
  
  for (int iRegion=0;iRegion<nRegion;iRegion++){
    for (int iHist=0;iHist<nHist;iHist++){
      //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
#if doMuon
      h1=(TH1F*)f1->Get(Form("H_WW_mp_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h1->Add( (TH1F*)f1->Get(Form("H_WW_mm_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );
      h2=(TH1F*)f1->Get(Form("H_WZ_mp_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h2->Add( (TH1F*)f1->Get(Form("H_WZ_mm_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );
      
      h3=(TH1F*)f1->Get(Form("H_Wgamma_mp_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h3->Add( (TH1F*)f1->Get(Form("H_Wgamma_mm_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );

      h1->SetTitle(Form("muon_%s_%s",regionName[iRegion].Data(), histName[iHist].Data()) );
#else
      h1=(TH1F*)f1->Get(Form("H_WW_ep_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h1->Add( (TH1F*)f1->Get(Form("H_WW_em_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );
      h2=(TH1F*)f1->Get(Form("H_WZ_ep_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h2->Add( (TH1F*)f1->Get(Form("H_WZ_em_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );

      h3=(TH1F*)f1->Get(Form("H_Wgamma_ep_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) );
      h3->Add( (TH1F*)f1->Get(Form("H_Wgamma_em_%s_%s",regionName[iRegion].Data(),histName[iHist].Data()) ) );

      h1->SetTitle(Form("electron_%s_%s",regionName[iRegion].Data(), histName[iHist].Data()) );
#endif

#if !doShape
      TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
      p1->Draw();
      p2->Draw();
      p1->cd();
#endif
      h1->SetLineColor(kBlue);
#if doShape
      h1->Scale(1/h1->Integral());
#endif
      h1->SetLineWidth(2);
      
        
      h1->Draw();
    
      h2->SetLineColor(kRed);
#if doShape
      h2->Scale(1/h2->Integral());
#endif
      h2->SetLineWidth(2);
      h2->Draw("same");
      
      h3->SetLineColor(kBlack);
#if doShape
      h3->Scale(1/h3->Integral());
#endif
      h3->SetLineWidth(2);
      h3->Draw("same");

      double maxi= 0;
      
      if (h1->GetBinContent(h1->GetMaximumBin())> maxi){
	maxi =h1->GetBinContent(h1->GetMaximumBin());
      }
      if (h2->GetBinContent(h2->GetMaximumBin())> maxi){
	maxi =h2->GetBinContent(h2->GetMaximumBin());
      }
      if (h3->GetBinContent(h3->GetMaximumBin())> maxi){
	maxi =h3->GetBinContent(h3->GetMaximumBin());
      }
      h1->SetMaximum(maxi*1.5);
     
      TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
      l->AddEntry(h1,"WW","l");
      l->AddEntry(h2,"WZ","l");
      l->AddEntry(h3,"Wgamma","l");
     
      l->Draw();

      /////cout
      //std::cout<<regionName[iRegion]<<"_"<<histName[iHist]<<" ";
      //std::cout<<h1->Integral(1,h1->GetNbinsX()+1)<<" "<<h2->Integral(1,h2->GetNbinsX()+1)<<" "<<h3->Integral(1,h3->GetNbinsX()+1)<<endl;
      //int lastbin=150; //150 means all, 120--> 1.0, 119-->0.99 etc
      //cout<<h1->GetXaxis()->GetBinLowEdge(lastbin+1)<<endl;
      //std::cout<<h1->Integral(1,lastbin)<<" "<<h2->Integral(1,lastbin)<<" "<<h3->Integral(1,lastbin)<<endl;
      

      //optimizaing emfraction cut
      // int optimumBin=0;
      // double min = 1.0 ;//this is the maximum possible value for tmp_fraction
      // for(int ibin=1; ibin<h1->GetNbinsX();ibin++){
      // 	double tmp_WW= h1->Integral(1,ibin);
      // 	double tmp_WZ= h2->Integral(1,ibin);
      // 	double tmp_Wg= h3->Integral(1,ibin);
      // 	if (tmp_WW>0 || tmp_WZ>0){
      // 	  double tmp_fraction=tmp_Wg/(tmp_Wg+tmp_WW+tmp_WZ);
      // 	  cout<<"tmp_fraction = "<<tmp_fraction <<endl;
	  
      // 	  if (tmp_fraction < min && tmp_fraction >0){
      // 	    cout<<" min = "<< min <<endl;
      // 	    min = tmp_fraction;
      // 	    cout<<" min = "<< min <<endl;
      // 	    optimumBin=ibin;
      // 	  }
      // 	}
      // }
      // cout<<"optimumBin = "<<optimumBin<<endl;
      // cout<<"optimumCut = "<<h1->GetBinLowEdge(1)+h1->GetBinWidth(1)*optimumBin<<endl;
      ////////////

#if !doShape
      double xstart=h1->GetBinLowEdge(1);
      double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);
      
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h3->Clone();
      TH1F *denominator = (TH1F*)h1->Clone();
      
      denominator->Add(h2);
      denominator->Add(h3);
      
      ratioHist->Divide(denominator); // ratioHist=(WW+WZ)/Wgamma
      
      ratioHist->GetYaxis()->SetRangeUser(0., 1.5);
      ratioHist->SetMarkerStyle(20);
      ratioHist->Draw();
      ratioHist->SetTitle("Wg/(WW+WZ+Wg)");
      TLine* horiz_line = new TLine(0.01,0.5,1.99,0.5);
      horiz_line->SetLineStyle(2);
      horiz_line->DrawLine(xstart,0.5,xend,0.5);
#endif
      
      c1->Print("plots_Wgamma.pdf","pdf");
      
#if !doShape
      p1->Clear();
      p2->Clear();
      
      c1->cd();
#endif      
      
    }
  }

  if(1){
    const int nhist=4;TString hist[nhist]={"emfrac_jvtxf", "emfrac_jvtxf_jetpt_gt50","emfrac_jvtxf_jeteta_gt24", "emfrac_jvtxf_jvfregion"};
    const int nsamp=3;TString samp[nsamp]={"WW","WZ","Wgamma"};
    for (int i=0; i<nhist; i++){
      for (int isamp=0; isamp<nsamp; isamp++){
#if doMuon
	h=(TH2F*)f1->Get(Form("H_%s_mp_WBF_SR_%s",samp[isamp].Data(),hist[i].Data()) );
	h->Add ( (TH2F*)f1->Get(Form ("H_%s_mm_WBF_SR_%s",samp[isamp].Data(),hist[i].Data()) ) );
	h->SetTitle(Form("%s_muon_SR_%s",samp[isamp].Data(),hist[i].Data()));
#else
	h=(TH2F*)f1->Get(Form("H_%s_ep_WBF_SR_%s",samp[isamp].Data(),hist[i].Data()) );
	h->Add ( (TH2F*)f1->Get(Form ("H_%s_em_WBF_SR_%s",samp[isamp].Data(),hist[i].Data()) ) );
	h->SetTitle(Form("%s_electron_SR_%s",samp[isamp].Data(),hist[i].Data()));
#endif
	h->Draw("colz");
	c1->Print("plots_Wgamma.pdf","pdf");
      }
      /*
      h=(TH2F*)f1->Get(Form("H_WZ_mp_WBF_SR_%s",hist[i].Data()) );
      h->Add ( (TH2F*)f1->Get(Form ("H_WZ_mm_WBF_SR_%s",hist[i].Data()) ) );
      h->SetTitle(Form("WZ_muon_SR_%s",hist[i].Data()));
      h->Draw("colz");
      c1->Print("plots_Wgamma.pdf","pdf");
      
      h=(TH2F*)f1->Get(Form("H_Wgamma_mp_WBF_SR_%s",hist[i].Data()) );
      h->Add ( (TH2F*)f1->Get(Form ("H_Wgamma_mm_WBF_SR_%s",hist[i].Data()) ) );
      h->SetTitle(Form("Wg_muon_SR_%s",hist[i].Data()));
      h->Draw("colz");
      c1->Print("plots_Wgamma.pdf","pdf");
      */
    }
  }
  f1->Close();
  
  c1->Print("plots_Wgamma.pdf]","pdf");
}
