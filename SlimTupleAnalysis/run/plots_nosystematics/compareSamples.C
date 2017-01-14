{
  //=========Macro generated from canvas: c1/c1
  //=========  (Sat Jun  7 21:43:18 2014) by ROOT version5.34/18

  ///this code was originally for comparing Alpgen and sherpa samples (or powheg and mcnlo). It can be used to compare any two files
#include <TLatex.h>
#include "rebin.h"
  
  bool DEBUG =false;
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_compareSamples.pdf[","pdf");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_WW_WjetsEWK_SMsig_v4.2.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_WW_vs_SMsig_v6.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_ttbar_v4.2.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_diboson_MCNLO_aTGC_v4.2.root");

  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.ttbar.caf4.1_looseBadLep4.root");



  //const int nSample =3; TString sampleName[nSample] = {"Ttbar","TtbarMCatNLO", "TtbarPowHer"}
  //const int nSample =5; TString sampleName[nSample] = {"Ttbar","SingleTop", "Zjets" , "Wjets","WZZZWg"};
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_0_0"};
  //const int nSample =4; TString sampleName[nSample] = {"VBS_WV_0_0","WW","WZ","WjetsPow"};
  //const int nSample =6; TString sampleName[nSample] = { "WjetsInc","Wjets_40","Wjets_70","Wjets_140","Wjets_280","Wjets_500"};

  //const int nRegion =1; TString regionName[nRegion] = {"SRFJ"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_Top","SR","CR_TopFJ","SRFJ"};
  const int nRegion =6; TString regionName[nRegion] = {"CR_Top", "CR_Wjj","SR","CR_TopfatOnly","CR_WjjfatOnly","SRfatOnly"};
  //const int nRegion =1; TString regionName[nRegion] = {"PRESELECT"};

  //const int nPoint =1; TString pointName[nPoint] = {"WV_0_0"};
  //const int nPoint =3; TString pointName[nPoint] = {"WV_0_0","WV_0_02","WV_03_0"};

  //const int nFlavor =1; TString flavorName[nFlavor] = { "m"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};
  //const int nFlavor =2; TString flavorName[nFlavor] = {"ep","em"};
  const int nFlavor =4; TString flavorName[nFlavor] = {"ep","em","mp","mm"};

  //const int nHist =1 ;TString histName[nHist]={"MV1"}; 
  //const int nHist =4 ;TString histName[nHist]={"MET_et","vbfjet1_pt","Mwjj","Mlvjj"};
  //const int nHist =6 ;TString histName[nHist]={"lep_pt","MET_et","ptwlep","Mwjj","Mlvjj","mT"};

  const int nHist=7;TString histName[nHist]={"mTWV","mjjTagged","ptwjj","Mwjj","Mlvjj","ptwlep","MET_et"};

  //const int nHist =27;TString histName[nHist]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVptBalance","VVvecptdiff"};
  //const int nHist=13;TString histName[nHist]={"mjjTagged","ptwlep","ptwjj","Mwjj","Mlvjj","vbfjet1_eta","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVvecptdiff","VVptBalance"};
  

  
  for (int iHist=0;iHist<nHist;iHist++){
    //for (int iSample=0;iSample<nSample;iSample++){
      for (int iRegion=0;iRegion<nRegion;iRegion++){	  
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){


	  TH1F* h1=(TH1F*)f1->Get(Form("H_Ttbar_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  TH1F* h2=(TH1F*)f1->Get(Form("H_TtbarMCatNLO_%s_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  TH1F* h3=(TH1F*)f1->Get(Form("H_TtbarPowHer_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH1F* h4=(TH1F*)f1->Get(Form("H_WjetsPow_%s_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH1F* h4=(TH1F*)f2->Get(Form("H_Ttbar_%s_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH1F* h4=(TH1F*)f2->Get(Form("H_WWSM_%s_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  
	  



	  double rebin =1;
	  int rebinFac =1;
	  
	  
	  //if (! ( histName[iHist]=="Njet" ) ){
	  //h1->Rebin(rebin);
	  // h2->Rebin(rebin);
	  //}
	  
	  if (!(histName[iHist].Contains("Njet") || histName[iHist].Contains("Mwjj"))){
	    rebinFac = getRebinFactor(histName[iHist]);
	    rebin *=rebinFac;
	    
	    h1->Rebin(rebin);
	    h2->Rebin(rebin);
	    h3->Rebin(rebin);
	    //h4->Rebin(rebin);
	  }
	  
	  
	  bool logy=false;
	  
	  
	  TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	  p1->Draw();
	  p2->Draw();
	  p1->cd();
	  if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") ){
	    logy = true;
	  }
	  // cout<<logy<<endl;
	  p1->SetLogy(logy); 
     
	  h1->SetLineColor(kBlue);
	  h1->Scale(1/h1->Integral());
	  
	  h1->SetTitle(Form("%s_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  //h1->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	 
	  h1->Draw();
	  if (histName[iHist].Contains("MET_et"))h1-> GetXaxis()->SetRangeUser( 0,200 );
	  
   
	  h2->SetLineColor(kRed);
	  h2->Scale(1/h2->Integral());
	  h2->Draw("same");


	  h3->SetLineColor(kOrange);
	  h3->Scale(1/h3->Integral());
	  h3->Draw("same");


	  // h4->SetLineColor(kGreen);
	  // h4->Scale(1/h4->Integral());
	  // h4->Draw("same");

	  
	  double maxi=h1->GetBinContent(h1->GetMaximumBin());
	  //cout<<maxi<<endl;
	  double tmp=0.;
	  tmp=h2->GetBinContent(h2->GetMaximumBin());
	  if(tmp>maxi)maxi=tmp;
	  tmp=h3->GetBinContent(h3->GetMaximumBin());
	  if(tmp>maxi)maxi=tmp;
	  // tmp=h4->GetBinContent(h4->GetMaximumBin());
	  // if(tmp>maxi)maxi=tmp;
		  
	  if (logy)
	    {h1->SetMaximum(maxi*100);}
	  else
	    {h1->SetMaximum(maxi*1.5);}
     
	  TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    
	   
	  
	  l->AddEntry(h1,"ttbar Powheg-Pyhtia6","l");
	  l->AddEntry(h2,"ttbar MC@NLO","l");
	  l->AddEntry(h3,"ttbar Powheg-Herwig","l");
	  //l->AddEntry(h4,"EWK VBF W", "l");
	  //l->AddEntry(h4,"Ttbar", "l");
	  //l->AddEntry(h4,"WW MC@NLO", "l");
     
	  l->Draw();

	  double xstart=h1->GetBinLowEdge(1);
	  double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);


	  
	  p2->cd();
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist = (TH1F*)h2->Clone();
	  ratioHist->Divide(h1);
	  //ratioHist->GetYaxis()->SetRangeUser(0.3, 2.);
	  //ratioHist->GetYaxis()->SetRangeUser(0.8, 1.2);
	  ratioHist->GetYaxis()->SetRangeUser(0., 5.);
	  ratioHist->SetMarkerStyle(20);

	  ratioHist->Draw();

	  TH1F *ratioHist2 = (TH1F*)h3->Clone();
	  ratioHist2->Divide(h1);
	  ratioHist2->Draw("same");

	  // TH1F *ratioHist3 = (TH1F*)h4->Clone();
	  // ratioHist3->Divide(h1);
	  // ratioHist3->Draw("same");
	  
	  ratioHist->SetTitle("Bkg/SM signal ratio");

	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
   
 
	  c1->Print("plots_compareSamples.pdf",Form("Title:%s", histName[iHist].Data()));

	  p1->Clear();
	  p2->Clear();
	  
	  c1->cd();

	  
	}
      }
      //}
  }
  f1->Close();
  //f2->Close();
   
  c1->Print("plots_compareSamples.pdf]","pdf");
}
