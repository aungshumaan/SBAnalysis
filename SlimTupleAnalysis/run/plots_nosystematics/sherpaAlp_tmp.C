{

  ///this code compares Sherpa and Alpgen. Error band is calculated by varying renormalization-factrization and CKKW scale in SHERPA
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
  c1->Print("plots_sherpaAlp_tmp.pdf[","pdf");

#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"


 
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw_NEWcutflow.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4.WjetsAlp_smw_NEWcutflow.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsTruthSyst.caf4.2.lv4.4_smw_NEWcutflow.root");

  // TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_all97.root");
  // TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW.WjetsAlp.root");
  // TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.WjetsTruthSyst.root");
  

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_all97.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20.WjetsAlp.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.WjetsTruthSyst.root");


  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_ptWlep90.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsAlp_ptwlep90.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsTruthSyst_ptwlep90.root");

  TFile *f1=TFile::Open("~azaman/Cnalysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_ptwlep150.WjetsSherpa.root");
  TFile *f2=TFile::Open("~azaman/Cnalysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_ptwlep150.WjetsAlp.root");
  TFile *f3=TFile::Open("~azaman/Cnalysis5/SlimTupleAnalysis/run/hwwlvqq.caf4.2.lv4.4_ptwlep150.WjetsTruthSyst.root");

 
  //const int nRegion =1; TString regionName[nRegion] = {"LooseMjjTag"};
  const int nRegion =4; TString regionName[nRegion] = {"CR_Wjj","SR","CR_WjjfatOnly","SRfatOnly"};
  //const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","CR_WjjfatOnly"};
  //const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","SR"};

 

 

  //const int nFlavor =1; TString flavorName[nFlavor] = { "m"};
  const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};
  //const int nFlavor =4; TString flavorName[nFlavor] = {"ep","em", "mp","mm"};
  //const int nFlavor =2; TString flavorName[nFlavor] = {"ep","em" };

  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist =6 ;TString histName[nHist]={"mjjTagged","ptwlep","mTWV","cosThetaWDecay", "bosonCentrality","VVptBalance"}; 
  //const int nHist =4 ;TString histName[nHist]={"MET_et","vbfjet1_pt","Mwjj","Mlvjj"};
  //const int nHist =7 ;TString histName[nHist]={"lep_pt","MET_et","mjjTagged","ptwlep","Mwjj","Mlvjj","mT"};



  for (int iRegion=0;iRegion<nRegion;iRegion++){	  
    for (int iHist=0;iHist<nHist;iHist++){
      for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	
	
	TH1F* h1=(TH1F*)f1->Get(Form("H_Wjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	h1->Add( (TH1F*)f1->Get(Form("H_Wjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );
	TH1F* h2=(TH1F*)f2->Get(Form("H_WjetsAlp_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	h2->Add( (TH1F*)f2->Get(Form("H_WjetsAlp_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );
	/*
	TH1F* h2=(TH1F*)f1->Get(Form("H_Data_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	h2->Add( (TH1F*)f1->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );
	h2->Add( (TH1F*)f1->Get(Form("H_Ttbar_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_Ttbar_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_Zjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_Zjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_SingleTop_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_SingleTop_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_WZZZWg_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_WZZZWg_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	h2->Add( (TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ),-1 );
	*/
	
	TH1F* hnom=(TH1F*)f3->Get(Form("H_Wjets_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	hnom   ->Add( (TH1F*)f3->Get(Form("H_Wjets_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	
	TH1F* hfac=(TH1F*)f3->Get(Form("H_TruthWjetsfac4_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	hfac   ->Add( (TH1F*)f3->Get(Form("H_TruthWjetsfac4_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	
	TH1F* hrenorm=(TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	hrenorm->Add( (TH1F*)f3->Get(Form("H_TruthWjetsrenorm4_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	
	TH1F* hckkw=(TH1F*)f3->Get(Form("H_TruthWjetsckkw30_ep_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) );
	hckkw->Add( (TH1F*)f3->Get(Form("H_TruthWjetsckkw30_em_WBF_%s_%s",  regionName[iRegion].Data(), histName[iHist].Data()) ) );
	  

	  
	int rebin =1;
	int rebinFac =1;
	/*
	if (!(histName[iHist].Contains("Njet"))){
	  //if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	  
	  rebinFac = getRebinFactor(histName[iHist]);
	  rebin *=rebinFac;

	 	  
	  //h0->Rebin(rebin);
	  h1->Rebin(rebin);
	  h2->Rebin(rebin);

	  hnom->Rebin(rebin);
	  hfac->Rebin(rebin);
	  hrenorm->Rebin(rebin);
	  hckkw->Rebin(rebin);
	    
	}
	*/
	//After rebinning, set negative bins to zero
	int nbins = h1->GetNbinsX();
	for (int ibin =1; ibin <=nbins; ibin++){
	  if (h2->GetBinContent(ibin)<0) h2->SetBinContent(ibin,10e-12);
	}


	//doVariableBinHisto(h0);
	doVariableBinHisto(h1);
	doVariableBinHisto(h2);


	
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
	

	
	//h1->SetTitle(Form("%s_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	h1->SetTitle("");

	//h1-> GetYaxis()->SetTitleSize(0.07);
	h1-> GetXaxis()->SetTitleSize(0.05);

	if (h1->GetBinWidth(1)== h1->GetBinWidth(h1->GetNbinsX())){
	  if (h1->GetBinWidth(1)<0.1)h1-> GetYaxis()->SetTitle( Form( "Entries / %.2f", h1->GetBinWidth(1)  )  );
	  else h1-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h1->GetBinWidth(1)  )  );
	}else{
	  h1-> GetYaxis()->SetTitle(  "Entries / GeV"  );
	}
	
	  
	h1->Draw();
	
   
	h2->SetLineColor(kRed);
	//h2->Scale(1/h2->Integral());
	h2->Draw("same");
	
	//Kolmagarov-Smirnov quality of fit
	// Double_t ks= h1->KolmogorovTest(h2);
	// TLatex lat; //l.SetTextAlign(12); 
	// lat.SetTextSize(0.04); 
	// lat.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	// lat.SetTextColor(1);
	// lat.DrawLatex(0.2,0.87,Form("KS %f",ks));
	


	  
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

	TString latexFlav("");
	if (flavorName[iFlavor] == "e") { latexFlav = "e";}
	else if (flavorName[iFlavor] == "m") { latexFlav = "#mu";}
	l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Internal}");
	l.DrawLatex(0.15 , 0.76,Form("#int Ldt = 20.3 fb^{-1}, #bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(),regionName[iRegion].Data()));
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
	//TH1F *hSystBandHi = h1->Clone("hdataMCratio");
	TH1F *hSystBandHi = new TH1F("","", nbins,xstart,xend);
	

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
	hSystBandHi->GetYaxis()->SetRangeUser(0., 3.);
	hSystBandHi->SetMarkerSize(0);
	setRatioPlotStyle (hSystBandHi);
	
	//hSystBandHi->Draw("e2 same");
	hSystBandHi->Draw("e2");

	ratioHist->Draw("same");
	
	ratioHist->SetTitle("ratio");
	

	  
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);


	  //c1->Print(Form("PDF_syst_band/%s_%s_%s.pdf",flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data() ) );	  
	  c1->Print("plots_sherpaAlp_tmp.pdf",Form("Title:%s_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  
	  
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
      //}
  }
  f1->Close();
  f2->Close();
  f3->Close();
   
  c1->Print("plots_sherpaAlp_tmp.pdf]","pdf");
}
