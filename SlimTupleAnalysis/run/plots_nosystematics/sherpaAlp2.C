{

  ///this code is for comparing W+jets bkg against data-other bkg
#include <TLatex.h>
#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_sherpaAlp2.pdf[","pdf");



  // TFile *f1=TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10.1_COMMON.root"); //sherpa inclusive and pt sliced samples starting from 40GeV.
  // TFile *f3=TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root"); //includes sherpa pt0 and other pt sliced samples
  // TFile *f2=TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_Wjets_Alpgen.root"); //Alpgen 
  
  
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_NEWcutflow.root");
  TFile *f2=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7.WjetsAlp_NEWcutflow.root");
  
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_WW_WjetsEWK_SMsig_v4.2.root");

  //const int nRegion =2; TString regionName[nRegion] = {"SR","SRFJ"};
  //const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","SR"};
  const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","CR_WjjfatOnly"};
  //const int nRegion =4; TString regionName[nRegion] = {"BTAG","CR_Top","CR_Wjj","SR"};
  //const int nRegion =6; TString regionName[nRegion] = {"PRESELECT","WJET","BTAG","CR_Top","CR_Wjj","SR"};



  const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nHist =1 ;TString histName[nHist]={"mjjTagged"}; 
  //const int nHist =5 ;TString histName[nHist]={"Njet","jet1_pt","jet2_pt","jet3_pt","jet4_pt"}; //RunNumber

  //const int nHist =8 ;TString histName[nHist] = {"mT","mT_true","mT_dPhilepMET_lt14","mT_dPhilepMET_gt14" ,"mT_ptwlep_lt50","mT_ptwlep_50_100" ,"mT_ptwlep_100_150", "mT_ptwlep_gt150"};
  //const int nHist =14 ;TString histName[nHist] = { "mjjTagged","ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dEtaTaggedJets", "vbfjet1_pt","vbfjet2_pt", "lep_pt","MET_et","mT","ptBalance","Njet"};
  const int nHist=13;TString histName[nHist]={"mjjTagged","ptwlep","ptwjj","Mwjj","Mlvjj","vbfjet1_eta","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVvecptdiff","VVptBalance"};

  
  for (int iRegion=0;iRegion<nRegion;iRegion++){
    
    for (int iHist=0;iHist<nHist;iHist++){
      for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){

	TH1F* h1=(TH1F*)f1->Get(Form("H_Wjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	h1->Add((TH1F*)f1->Get(Form("H_Wjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	//TH1F* h2=(TH1F*)f2->Get(Form("H_WjetsPow_%sp_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	//h2->Add((TH1F*)f2->Get(Form("H_WjetsPow_%sm_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));
	TH1F* h2=(TH1F*)f2->Get(Form("H_WjetsAlp_%sp_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	h2->Add((TH1F*)f2->Get(Form("H_WjetsAlp_%sm_WBF_%s_%s",  flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));
	//data - other bkg
	TH1F* h3=(TH1F*)f1->Get(Form("H_Data_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	h3->Add((TH1F*)f1->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())));
	h3->Add((TH1F*)f1->Get(Form("H_Ttbar_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_Ttbar_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_SingleTop_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_SingleTop_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_Zjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_Zjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_WZZZWg_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	h3->Add((TH1F*)f1->Get(Form("H_WZZZWg_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	//h3->Add((TH1F*)f1->Get(Form("H_QCD_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);
	//h3->Add((TH1F*)f1->Get(Form("H_QCD_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data())), -1);

	// TH1F* h4=(TH1F*)f3->Get(Form("H_%s_%sp_WBF_%s_%s",sampleName[iSample].Data(),flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	// h4->Add((TH1F*)f3->Get(Form("H_%s_%sm_WBF_%s_%s",  sampleName[iSample].Data(),flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));


	// int rebin=1;
	
	// if (!(histName[iHist].Contains("Njet"))){
	//   h1->Rebin(rebin);
	//   h2->Rebin(rebin);
	//   h3->Rebin(rebin);
	// }

	int rebin =1;
	int rebinFac =1;
	  
	if (!(histName[iHist].Contains("Njet"))){
	  //if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	    
	  rebinFac = getRebinFactor(histName[iHist]);
	  rebin *=rebinFac;
	    
	    
	  h1->Rebin(rebin);
	  h2->Rebin(rebin);
	  h3->Rebin(rebin);
	    	    
	}

	doVariableBinHisto(h1);
	doVariableBinHisto(h2);
	doVariableBinHisto(h3);
	  	  
	TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	p1->Draw();
	p2->Draw();
	p1->cd();
     
	h1->SetLineColor(kBlue);  //sherpa inclusive + pt sliced samples starting from 40GeV.
	//h1->Scale(1/h1->Integral());
	h1->SetTitle(Form("%s_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );

	h1->Draw();
    
     
   
	h2->SetLineColor(kRed); //Alpgen
	//h2->Scale(1/h2->Integral());
	h2->Draw("same");

	// h4->SetLineColor(kGreen); //sherpa pt0+ other pt sliced samples
	// h4->Scale(1/h4->Integral());
	// h4->Draw("same");

	h3->SetMarkerStyle(20); //data-other bkg (QCD estimated using sherpa inclusive+pt sliced)
	//h3->Scale(1/h3->Integral());
	h3->Draw("same");

	Double_t ks_sherpaIncl= h1->KolmogorovTest(h3);
	Double_t ks_alp= h2->KolmogorovTest(h3);
	//Double_t ks_sherpaPt0= h4->KolmogorovTest(h3);
	//cout<<ks_sherpa<<endl;
	//cout<<ks_alp<<endl;
	  
	//void myText(Double_t x,Double_t y,Color_t color, const char *text, Double_t size) { 
	//myText(0.20 , 0.82, 1 , Form( "#int Ldt = %s fb^{-1}, (%s)", Lumi.Data(), flavor.Data()) , 0.04);
	TLatex lat; //l.SetTextAlign(12); 
	lat.SetTextSize(0.04); 
	lat.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	lat.SetTextColor(1);
	lat.DrawLatex(0.2,0.87,Form("Sherpa  KS %f",ks_sherpaIncl));
	//lat.DrawLatex(0.2,0.82,Form("Sherpa Pt0 KS %f",ks_sherpaPt0));
	lat.DrawLatex(0.2,0.77,Form("Alpgen KS %f",ks_alp));
	  
	double maxi= 0;
	if (h1->GetBinContent(h1->GetMaximumBin())>h2->GetBinContent(h2->GetMaximumBin())){
	  maxi=h1->GetBinContent(h1->GetMaximumBin());
	}else{
	  maxi=h2->GetBinContent(h2->GetMaximumBin());
	};
	h1->SetMaximum(maxi*1.5);
     
	TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    

	l->AddEntry(h1,"Sherpa W+jets","l");
	//l->AddEntry(h4,"Sherpa pt0 W+jets","l");
	l->AddEntry(h2,"Alpgen W+jets","l");
	l->AddEntry(h3,"Data-other bkg","p");
     
	l->Draw();

	double xstart=h1->GetBinLowEdge(1);
	double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);

	p2->cd();
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h3->Clone();
	ratioHist->Divide(h1);
	ratioHist->GetYaxis()->SetRangeUser(0.3, 2.5.);
	ratioHist->SetMarkerColor(kBlue);ratioHist->SetMarkerStyle(20);
	setRatioPlotStyle (ratioHist);
	ratioHist->Draw();
	ratioHist->SetTitle("Data/MC ratio");
	TH1F *ratioHist2 = (TH1F*)h3->Clone();
	ratioHist2->Divide(h2);
	ratioHist2->SetMarkerColor(kRed);ratioHist2->SetMarkerStyle(20);
	setRatioPlotStyle (ratioHist2);
	ratioHist2->Draw("same");
	// TH1F *ratioHist3 = (TH1F*)h4->Clone();
	// ratioHist3->Divide(h3);
	// ratioHist3->SetMarkerColor(kGreen);ratioHist3->SetMarkerStyle(20);
	// ratioHist3->Draw("same");
	TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	horiz_line->SetLineStyle(2);
	horiz_line->DrawLine(xstart,1.0,xend,1.0);
   
 
	//c1->Print("plots_sherpaAlp2.pdf","pdf");
	c1->Print("plots_sherpaAlp2.pdf",Form("Title:%s_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));

	p1->Clear();
	p2->Clear();
	  
	c1->cd();

	//}

      }
    }
  }
  f1->Close();
  f2->Close();
   
  c1->Print("plots_sherpaAlp2.pdf]","pdf");
}
