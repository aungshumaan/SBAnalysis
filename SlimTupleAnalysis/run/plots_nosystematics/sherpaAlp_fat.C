{
  //*********DO NOT MODIFY CODE***************************
  ///this code compares Sherpa and Alpgen variable bin mTWV distributions. Error band is calculated by varying renormalization-factrization and CKKW scale in SHERPA
  //########################SOMETHING WAS WRONG:  Incorrect assignment error happens while calculating error band. Resolved after initializing it instead of using Clone().
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
  //c1->Print("plots_sherpaAlp_tmp.pdf[","pdf");

#include "rebin.h"
#include "stackStyle.h"


  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_ptWlep90.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsAlp_ptwlep90.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsTruthSyst_ptwlep90.root");

  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_ptwlep0.WjetsSherpa.root");
  TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_ptwlep0.WjetsAlp.root");
  TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.caf4.2.lv4.4_ptwlep0.WjetsTruthSyst.root");

 

  //const int nRegion =2; TString regionName[nRegion] = {"CR_WjjfatOnly","SRfatOnly"};
  const int nRegion =1; TString regionName[nRegion] = {"CR_WjjfatOnly"};
  //const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","SR"};

 

 

  //const int nFlavor =1; TString flavorName[nFlavor] = { "m"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};
  //const int nFlavor =4; TString flavorName[nFlavor] = {"ep","em", "mp","mm"};
  //const int nFlavor =2; TString flavorName[nFlavor] = {"ep","em" };

  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  
  
  



  for (int iRegion=0;iRegion<nRegion;iRegion++){	  
    for (int iHist=0;iHist<nHist;iHist++){

	
	
	  TH1F* h1_ori=(TH1F*)f1->Get(Form("H_Wjets_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1_ori->Add( (TH1F*)f1->Get(Form("H_Wjets_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  h1_ori->Add( (TH1F*)f1->Get(Form("H_Wjets_mp_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  h1_ori->Add( (TH1F*)f1->Get(Form("H_Wjets_mm_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  TH1F* h2_ori=(TH1F*)f2->Get(Form("H_WjetsAlp_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	  h2_ori->Add( (TH1F*)f2->Get(Form("H_WjetsAlp_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  h2_ori->Add( (TH1F*)f2->Get(Form("H_WjetsAlp_mp_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  h2_ori->Add( (TH1F*)f2->Get(Form("H_WjetsAlp_mm_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  
	  
	  TH1F* hnom_ori=(TH1F*)f3->Get(Form("H_Wjets_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	  hnom_ori   ->Add( (TH1F*)f3->Get(Form("H_Wjets_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hnom_ori   ->Add( (TH1F*)f3->Get(Form("H_Wjets_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hnom_ori   ->Add( (TH1F*)f3->Get(Form("H_Wjets_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  
	  TH1F* hfac_ori=(TH1F*)f3->Get(Form("H_TruthWjetsfac4_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	  hfac_ori   ->Add( (TH1F*)f3->Get(Form("H_TruthWjetsfac4_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hfac_ori   ->Add( (TH1F*)f3->Get(Form("H_TruthWjetsfac4_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hfac_ori   ->Add( (TH1F*)f3->Get(Form("H_TruthWjetsfac4_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  
	  TH1F* hrenorm_ori=(TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_ep_WBF_%s_%s", regionName[iRegion].Data(), histName[iHist].Data()) );
	  hrenorm_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_em_WBF_%s_%s", regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hrenorm_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_ep_WBF_%s_%s", regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hrenorm_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_em_WBF_%s_%s", regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  
	  TH1F* hckkw_ori=(TH1F*)f3->Get(Form("H_TruthWjetsckkw30_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	  hckkw_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsckkw30_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hckkw_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsckkw30_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  hckkw_ori->Add( (TH1F*)f3->Get(Form("H_TruthWjetsckkw30_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	
	  
	///HARD CODING VARIABLE BINS  &&&&
	Double_t bins[6]= {0., 300., 500., 600., 700., 1500.};
	Double_t bins_fat[5]= {300., 600., 700., 800.,  1500.};  
	

	if (!(regionName[iRegion].Contains("fatOnly")) ){
	  h1 = h1_ori-> Rebin(5, "h1", bins);
	  h2 = h2_ori-> Rebin(5, "h2", bins);
	  hnom = hnom_ori-> Rebin(5, "hnom", bins);
	  hfac = hfac_ori-> Rebin(5, "hfac", bins);
	  hrenorm = hrenorm_ori-> Rebin(5, "hrenorm", bins);
	  hckkw = hckkw_ori-> Rebin(5, "hckkw", bins);
	}else{
	  h1 = h1_ori-> Rebin(4, "h1", bins_fat);
	  h2 = h2_ori-> Rebin(4, "h2", bins_fat);
	  hnom = hnom_ori-> Rebin(4, "hnom", bins_fat);
	  hfac = hfac_ori-> Rebin(4, "hfac", bins_fat);
	  hrenorm = hrenorm_ori-> Rebin(4, "hrenorm", bins_fat);
	  hckkw = hckkw_ori-> Rebin(4, "hckkw", bins_fat);
	}

	int nbins = h1->GetNbinsX();
	cout<<"nbins = "<<nbins<<endl;
	
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
	

	

	h1->SetTitle("");

	//h1-> GetYaxis()->SetTitleSize(0.07);
	h1-> GetXaxis()->SetTitleSize(0.05);

	if (h1->GetBinWidth(1)== h1->GetBinWidth(h1->GetNbinsX())){
	  if (h1->GetBinWidth(1)<0.1)h1-> GetYaxis()->SetTitle( Form( "Entries / %.2f", h1->GetBinWidth(1)  )  );
	  else h1-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h1->GetBinWidth(1)  )  );
	}else{
	  h1-> GetYaxis()->SetTitle(  "Entries / GeV"  );
	}
	
	h1->Scale(1/h1->Integral());
	h1->Draw();
	
   
	h2->SetLineColor(kRed);
	h2->Scale(1/h2->Integral());
	h2->Draw("same");
	
	//Kolmagarov-Smirnov quality of fit
	Double_t ks= h1->KolmogorovTest(h2);
	TLatex lat; //l.SetTextAlign(12); 
	lat.SetTextSize(0.04); 
	lat.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	lat.SetTextColor(1);
	//lat.DrawLatex(0.1,0.95,Form("KS %f",ks));
	


	  
	double maxi= 0;
	if (h1->GetBinContent(h1->GetMaximumBin())>h2->GetBinContent(h2->GetMaximumBin())){
	  maxi=h1->GetBinContent(h1->GetMaximumBin());
	}else{
	  maxi=h2->GetBinContent(h2->GetMaximumBin());
	};
	if (logy)
	  {h1->SetMaximum(maxi*100);}
	else
	  {h1->SetMaximum(maxi*1.5);}
	
	TLegend *leg=new TLegend(0.6,0.75,0.9,0.9);
	
	leg.SetTextSize(0.05);
	//leg->AddEntry(h2,"Data", "l");
	leg->AddEntry(h1,"Sherpa W+jets", "l");
	leg->AddEntry(h2,"Alpgen W+jets", "l");

	  
	leg->Draw();

	TLatex l;
	l.SetTextSize(0.05 ); 
	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	l.SetTextColor(1); //black


	//l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Internal}");
	l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Preliminary}");
	l.DrawLatex(0.15 , 0.76,Form("#int Ldt = 20.2 fb^{-1}, #bf{ W#rightarrow l#nu , %s}", regionName[iRegion].Data()));
	//DrawLatex(0.20 , 0.76,"#int Ldt = 20.3 fb^{-1}");
	
	//DrawLatex(0.20 , 0.66,"#bf{ W#rightarrow e#nu }" );

	
	double xstart=h1->GetBinLowEdge(1);
	double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);
	

	  
	p2->cd();
	gStyle->SetOptStat(0);
	
	TH1F *ratioHist = (TH1F*)h1->Clone();
	//cout<<"ratioHist nbins = "<<ratioHist->GetNbinsX()<<endl;
	ratioHist->Divide(h2);

	//ratioHist->GetYaxis()->SetRangeUser(0., 3.);
	ratioHist->SetMarkerStyle(20);
	//setRatioPlotStyle (ratioHist);
	//ratioHist->Draw();
	
	//First draw the systematic band
	//TH1F *hSystBandHi = h1->Clone("hdataMCratio"); //CRASHES
	//HARD CODING &&&&
	if (!(regionName[iRegion].Contains("fatOnly")) ){
	  TH1F *hSystBandHi = new TH1F("","", nbins,bins);
	}else {
	  TH1F *hSystBandHi = new TH1F("","", nbins,bins_fat);
	}

	for (int ibin =1;ibin<=nbins;ibin++){
	  double fracErr = 0;
	  //for (int i=0;i<nsyst;i++){ //hard coded
	  if (hnom->GetBinContent(ibin)!=0){
	    fracErr+=pow((hnom->GetBinContent(ibin)-hfac->GetBinContent(ibin))/hnom->GetBinContent(ibin),2);
	    fracErr+=pow((hnom->GetBinContent(ibin)-hrenorm->GetBinContent(ibin))/hnom->GetBinContent(ibin),2);
	    fracErr+=pow((hnom->GetBinContent(ibin)-hckkw->GetBinContent(ibin))/hnom->GetBinContent(ibin),2);
	  }
	  //}
	  fracErr =sqrt(fracErr);
	  //if (ibin<11)cout<<fracErr<<" ////"<<endl;
	  hSystBandHi->SetBinContent(ibin, 1);
	  hSystBandHi->SetBinError(ibin, fracErr);
	}

	gStyle->SetHatchesLineWidth(1);
	gStyle->SetHatchesSpacing(0.8);
	hSystBandHi->SetFillStyle(3354);
	hSystBandHi->SetFillColor(kRed);
	hSystBandHi->SetLineColor(0);
	//hSystBandHi->GetYaxis()->SetRangeUser(0., 3.);
	hSystBandHi->GetYaxis()->SetRangeUser(0.5, 1.5);
	hSystBandHi->SetMarkerSize(0);
	setRatioPlotStyle (hSystBandHi);
	
	//hSystBandHi->Draw("e2 same");
	hSystBandHi->Draw("e2");

	ratioHist->Draw("same");
	
	ratioHist->SetTitle("ratio");
	

	  
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);


	  //c1->Print("plots_sherpaAlp_tmp.pdf",Form("Title:l_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()));
	  c1->Print(Form("PDF_syst_band/sherpaAlp_l_%s_%s_ptwlep0.pdf", regionName[iRegion].Data(), histName[iHist].Data() ) );	  
	  
	  
	  p1->Clear();
	  p2->Clear();
	  
	  c1->cd();
	  
	  
	  // delete h1;
	  // delete h2;
	  // delete hnom;
	  // delete hfac;
	  // delete hrenorm;
	  // delete hckkw;
	  

      }

  }
  f1->Close();
  f2->Close();
  f3->Close();
   
  //c1->Print("plots_sherpaAlp_tmp.pdf]","pdf");
}
