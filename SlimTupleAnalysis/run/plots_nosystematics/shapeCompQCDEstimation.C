#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TLine.h"
#include <iostream>
#include <math.h>

#include "rebin.h"

void shapeCompQCDEstimation(){
  ///compare the shapes that go into QCD estimation fitting
  //&&&& If QCD histogram has negative bincontents bincontent is set to 1e-7, but if there are only negative and zero bins in the histogram, those negative bins will show up in the shape plot just like any positive bin, which is misleading because we want them to be zero. For histograms like this, for now, I am not plotting QCD (e.g. muon fatOnly plots) (12/17/15)

  //bool doMerge =true;
  bool doMerge =false;
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_dataFake,*h_WjetsFake,*h_ZjetsFake,*h_dibosonFake,*h_singleTopFake, *h_ttbarFake;
  TH1F *h_wvFake,*h_zvFake;

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
    
  //c2->Print("plots_shapeCompQCDEstimation.pdf["); 

  //TString version ="caf4.1.lv7.1_looseBadLep4";
  //TString version ="caf4.2.lv4_looseBadLep4";
  //TString version ="caf4.2.lv7.1_looseBadLep4";
  //TString version ="caf4.2.lv8.1.f100";
  //TString version ="caf4.2.lv8.1_smw_noSeparateWjetsEWK";
  TString version ="caf4.2.lv8.1_smw_wp20";
  //TString version ="caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass";
  

  TFile *ffake=TFile::Open(Form("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.%s.root",version.Data()) );
  TFile *fsignal=TFile::Open(Form( "/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetSignalRegion.%s.root",version.Data()) );

  
  if (!doMerge){  
    const int nFlav=4;TString flavorName[nFlav]={"ep","em","mp","mm"};
    //const int nFlav=2;TString flavorName[nFlav]={"mp","mm"};
  }else{
    const int nFlav=2;TString flavorName[nFlav]={"e","m"};
  }

            
  //const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjfatOnly","CR_Top","CR_TopfatOnly","SR","SRfatOnly"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"SR"};
  //const int nCut=2;TString cutName[nCut]={"PRESELECT","SR"};
  //const int nCut=3;TString cutName[nCut]={"STARTPOINT","JetSelectResolve","SR"};
  

  
  const int nType=1;TString typeName[nType]={"MET_et"};
  //const int nType=2;TString typeName[nType]={"MET_et","mT"};
  //const int nType=3;TString typeName[nType]={"MET_et","mT","lep_pt"};


  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iflav=0;iflav<nFlav;++iflav){

	bool logy=false;
	
	if (!doMerge){
	  h_dataFake = (TH1F*)ffake->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_WjetsFake=(TH1F*)ffake->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_ZjetsFake= (TH1F*)ffake->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_dibosonFake= (TH1F*)ffake->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTopFake= (TH1F*)ffake->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbarFake= (TH1F*)ffake->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_wvFake= (TH1F*)ffake->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_zvFake= (TH1F*)ffake->Get(Form("H_VBS_ZV_0_0_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));

	  h_data = (TH1F*)fsignal->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets=(TH1F*)fsignal->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets= (TH1F*)fsignal->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson= (TH1F*)fsignal->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop= (TH1F*)fsignal->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar= (TH1F*)fsignal->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  
	  
	  
	  
	  
	  
	}else{

	  double s =1.; //add or subtract negative charge
	  
	  h_dataFake=(TH1F*)ffake->Get(Form("H_Data_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_dataFake->Add((TH1F*)ffake->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_WjetsFake=(TH1F*)ffake->Get(Form("H_Wjets_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_WjetsFake->Add((TH1F*)ffake->Get(Form("H_Wjets_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

      
	  h_ZjetsFake=(TH1F*)ffake->Get(Form("H_Zjets_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_ZjetsFake->Add((TH1F*)ffake->Get(Form("H_Zjets_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_dibosonFake=(TH1F*)ffake->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_dibosonFake->Add((TH1F*)ffake->Get(Form("H_WZZZWg_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_singleTopFake=(TH1F*)ffake->Get(Form("H_SingleTop_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTopFake->Add((TH1F*)ffake->Get(Form("H_SingleTop_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_ttbarFake=(TH1F*)ffake->Get(Form("H_Ttbar_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbarFake->Add((TH1F*)ffake->Get(Form("H_Ttbar_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  h_wvFake=(TH1F*)ffake->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_wvFake->Add((TH1F*)ffake->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  h_zvFake=(TH1F*)ffake->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_zvFake->Add((TH1F*)ffake->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  

	  h_data=(TH1F*)fsignal->Get(Form("H_Data_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_data->Add((TH1F*)fsignal->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  
	  h_Wjets=(TH1F*)fsignal->Get(Form("H_Wjets_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets->Add((TH1F*)fsignal->Get(Form("H_Wjets_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

      
	  h_Zjets=(TH1F*)fsignal->Get(Form("H_Zjets_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets->Add((TH1F*)fsignal->Get(Form("H_Zjets_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_diboson=(TH1F*)fsignal->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson->Add((TH1F*)fsignal->Get(Form("H_WZZZWg_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_singleTop=(TH1F*)fsignal->Get(Form("H_SingleTop_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop->Add((TH1F*)fsignal->Get(Form("H_SingleTop_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_ttbar=(TH1F*)fsignal->Get(Form("H_Ttbar_%sp_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar->Add((TH1F*)fsignal->Get(Form("H_Ttbar_%sm_WBF_%s_%s", flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  

	  
	}	

	
	h_qcd= (TH1F*)h_dataFake->Clone("h_qcd");
	h_qcd ->Add(h_WjetsFake,-1);
	h_qcd ->Add(h_ZjetsFake,-1);
	h_qcd ->Add(h_dibosonFake,-1);
	h_qcd ->Add(h_ttbarFake,-1);
	h_qcd ->Add(h_singleTopFake,-1);
	h_qcd ->Add(h_wvFake,-1);
	h_qcd ->Add(h_zvFake,-1);
	

	//&&&& Setting negative bincontent to zero
	for (int ibin =1; ibin<h_qcd->GetNbinsX();++ibin){
	  //cout<< ibin<<" "<< h_qcd->GetBinContent(ibin)<<endl;
	  if (h_qcd->GetBinContent(ibin)<0)
	    {
	      cout<<"Hello"<<endl;
	      h_qcd->SetBinContent(ibin,1e-7);
	    }
	}

	TH1F* hMC = (TH1F* ) h_Wjets->Clone();
	hMC->Add(h_Zjets);
	hMC->Add(h_ttbar);
	hMC->Add(h_singleTop);
	hMC->Add(h_diboson);
	
	h_data->SetLineColor(kBlack);
	h_Wjets->SetLineColor(kCyan);
	h_Zjets->SetLineColor(kBlue);
	h_diboson->SetLineColor(kYellow);
	h_singleTop->SetLineColor(kOrange);
	h_ttbar->SetLineColor(kRed);
	h_qcd->SetLineColor(kGreen);

	int rebin =1;
	//int rebinFac =1;
	
	//rebinFac = getRebinFactor(typeName[itype]);
	//rebin *=rebinFac;
	
	rebin =2;

	h_data->Rebin(rebin);
	h_Wjets->Rebin(rebin);
	h_Zjets->Rebin(rebin);
	h_diboson->Rebin(rebin);
	h_singleTop->Rebin(rebin);
	h_ttbar->Rebin(rebin);
	
	h_qcd->Rebin(rebin);

	h_Wjets->Scale(1/h_Wjets->Integral());
	h_data->Scale(1/h_data->Integral());
	h_Zjets->Scale(1/h_Zjets->Integral());
	h_diboson->Scale(1/h_diboson->Integral());
	h_singleTop->Scale(1/h_singleTop->Integral());
	h_ttbar->Scale(1/h_ttbar->Integral());
	h_qcd->Scale(1/h_qcd->Integral());
	
	double maxi=h_Wjets->GetBinContent(h_Wjets->GetMaximumBin());
	
	double tmp=0.;

	
	tmp=h_data->GetBinContent(h_data->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
      
	
	tmp=h_Zjets->GetBinContent(h_Zjets->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;

	tmp=h_diboson->GetBinContent(h_diboson->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;

	tmp=h_singleTop->GetBinContent(h_singleTop->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	
	tmp=h_ttbar->GetBinContent(h_ttbar->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	
	tmp=h_qcd->GetBinContent(h_qcd->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;

	// cout<<flavorName[iflav].Data()<<"_"<<cutName[icut].Data()<<endl;
	// //cout<<"h_qcd->Integral() "<<h_qcd->Integral()<<endl;
	// for (int ibin =1; ibin<h_qcd->GetNbinsX();++ibin){
	//   cout<< ibin<<" "<< h_qcd->GetBinContent(ibin)<<endl;
	// }

	
	h_Zjets->GetYaxis()->SetRangeUser(0,maxi*1.5);
	h_Zjets->GetXaxis()->SetRangeUser(0,200);

	
	h_Zjets->SetTitle( "" );	
	
	/*
	h_Zjets->Draw();
	h_singleTop->Draw("same");
	h_diboson->Draw("same");
	h_ttbar->Draw("same");
	h_Wjets->Draw("same");
	h_qcd->Draw("same");
	*/

	h_data->SetMarkerStyle(20);
	
	h_Zjets->Draw("hist");
	h_data->Draw("same");
	h_singleTop->Draw("hist same");
	h_diboson->Draw("hist same");
	h_ttbar->Draw("hist same");
	h_Wjets->Draw("hist same");
	h_qcd->Draw("hist same");

	TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
	leg->SetNColumns(2);
	
	leg->AddEntry(h_data,"Data","p");
	leg->AddEntry(h_Wjets,"W+jets","l");
	leg->AddEntry(h_Zjets,"Z+jets","l");
	leg->AddEntry(h_diboson,"Di-boson","l");
	leg->AddEntry(h_singleTop,"single top","l");
	leg->AddEntry(h_ttbar,"ttbar","l");
	leg->AddEntry(h_qcd,"QCD","l");
	
	leg->Draw();


	TLatex l;
	l.SetTextSize(0.04); 
	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	l.SetTextColor(1); //black
	//l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Internal}");
	l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Preliminary}");
	l.DrawLatex(0.15 , 0.76,"#int Ldt = 20.2 fb^{-1}");
	TString latexFlav("");
	if (flavorName[iflav] == "ep") { latexFlav = "e^{+}";}
	else if (flavorName[iflav] == "em") { latexFlav = "e^{-}";}
	else if (flavorName[iflav] == "mp") {  latexFlav = "#mu^{+}";}
	else if (flavorName[iflav] == "mm") {  latexFlav = "#mu^{-}";}
	l.DrawLatex(0.15 , 0.68,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(),cutName[icut].Data() ) );

	gStyle->SetOptStat(0);
      
	
	//c2->Print(Form("plots_shapeCompQCDEstimation.pdf" ),Form("Title:%s_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	c2->Print(Form("PDF_syst_band/shapeComp_%s_WBF_%s.pdf",flavorName[iflav].Data(),cutName[icut].Data()));

	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// cout<<"KolmogorovTest result= "<<ks<<endl;
	
    
	  
      
      }
    }
  }
      
  ffake->Close();
  fsignal->Close();
  //f1->Close();
  
  //c2->Print("plots_shapeCompQCDEstimation.pdf]"); 

}
