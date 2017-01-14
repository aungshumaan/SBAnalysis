

////PLEASE DON'T CHANGE THIS CODE!!!!!


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
#include "stackStyle.h"
#include "makerHelper.h"
#include "doVariableBinHisto.h"

#define DEBUG 1

void shapeCompWithSignal_tmp(){
  ////shape comparison with ttbar, W+jets, signal SM and signal aQGC

  bool doMerge =true;
  //if (!doMerge){
  //const int nFlav=4;TString flavorName[nFlav]={"em","ep","mm","mp"};
    //}else{
    //const int nFlav=2;TString flavorName[nFlav]={"e","m"};
  const int nFlav=1;TString flavorName[nFlav]={"m"};
    //}
  //else{  const int nFlav=1;TString flavorName[nFlav]={"l"};}
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  TH1F *h_WV_0_03, *h_WV_0_01;
  
  //TCanvas *c2 = new TCanvas();
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  
  //c2->Print("plots_shape_withSig.pdf[");
  
  
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.0.root"); //&&&& for mjjTagged kinematics. no QCD
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_all97.root");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_smw_noSeparateWjetsEWK.root"); //&&&& shape comparison plots
  TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK.root");
  
            
  
  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};
  //const int nCut=3;TString cutName[nCut]={"CR_Wjj","SR","SRfatOnly"};
  //const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ","SR","SRfatOnly"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"SR"};


  //const int nType=1;TString typeName[nType]={"VVptBalance"};
  //const int nType=2;TString typeName[nType]={"mjjTagged","dEtaTaggedJets"};
  //const int nType=4;TString typeName[nType]={"mjjTagged","mTWV","dEtaTaggedJets","bosonCentrality"};
  //const int nType=4;TString typeName[nType]={"mjjTagged","dEtaTaggedJets","vbfjet1_eta","vbfjet2_eta"}; //&&&& mjjTagged kinematics plots
  //const int nType=8;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  
  const int nType=11;TString typeName[nType]={"ptwjj","ptwlep","Mlvjj","mTWV","VVptBalance","mjjTagged","dEtaTaggedJets", "bosonCentrality","lepCentrality","cosThetaWDecay","cosThetaWlep"}; //&&&& shape comparison plots
  
  //const int nType=1;TString typeName[nType]={"ptwjj"};


  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iFlavor=0;iFlavor<nFlav;++iFlavor){

	if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}

	bool logy=false;
	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptlvjj")|| typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("MET_et") || typeName[itype].Contains("lep_pt")  || typeName[itype].Contains("mTWV")){
	  logy = true;
	}
	if (!doMerge){
	  h_data = (TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets= (TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson= (TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop= (TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar= (TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
     
	  h_qcd= (TH1F*)f2->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

      
      
	  //h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  //h_WV_0_01=(TH1F*)f->Get(Form("H_VBS_WV_0_01_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_WV_0_03=(TH1F*)f->Get(Form("H_VBS_WV_0_03_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  //h_WV_03_0=(TH1F*)f->Get(Form("H_VBS_WV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));      
	  // h_ZV_0_0=(TH1F*)f->Get(Form("H_VBS_ZV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      
	  // h_ZV_0_02=(TH1F*)f->Get(Form("H_VBS_ZV_0_02_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  // h_ZV_03_0=(TH1F*)f->Get(Form("H_VBS_ZV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	}else{

	  double s =1.; //add or subtract negative charge
	  
   
	  h_data=(TH1F*)f->Get(Form("H_Data_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_data->Add((TH1F*)f->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  if (DEBUG){
	    cout<<h_data->GetName()<<endl;
	    cout<<h_data->GetNbinsX()<<endl;
	    TH1F *h2_data =(TH1F*)f->Get(Form("H_Data_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	    cout<<h2_data->GetNbinsX()<<endl;
	  }

	  h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

      
	  h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  h_qcd=(TH1F*)f2->Get(Form("H_QCD_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_qcd->Add((TH1F*)f2->Get(Form("H_QCD_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);


      
	  
	  h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_WV_0_0->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

	  //h_WV_0_01=(TH1F*)f->Get(Form("H_VBS_WV_0_01_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  //h_WV_0_01->Add((TH1F*)f->Get(Form("H_VBS_WV_0_01_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);
	  h_WV_0_03=(TH1F*)f->Get(Form("H_VBS_WV_0_03_%sp_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  h_WV_0_03->Add((TH1F*)f->Get(Form("H_VBS_WV_0_03_%sm_WBF_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data())),s);

  
	}	
      
           
	h_data->SetLineColor(kCyan);
	h_Wjets->SetLineColor(kBlack);
	h_Zjets->SetLineColor(kBlue-2);
	h_diboson->SetLineColor(kMagenta+2);
	h_singleTop->SetLineColor(kRed);
	h_ttbar->SetLineColor(kMagenta);
	h_qcd->SetLineColor(kGreen);

	h_WV_0_0->SetLineColor(kBlue);
	h_WV_0_03->SetLineColor(kRed);

	int rebin =1;
	int rebinFac =1;

	if (!(typeName[itype].Contains("Njet"))){
	  //if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){

	  rebinFac = getRebinFactor(typeName[itype]);
	  rebin *=rebinFac;
	
	  h_data->Rebin(rebin);
	  h_Wjets->Rebin(rebin);
	  h_Zjets->Rebin(rebin);
	  h_diboson->Rebin(rebin);
	  h_singleTop->Rebin(rebin);
	  h_ttbar->Rebin(rebin);
	  h_qcd->Rebin(rebin);

	  h_WV_0_0->Rebin(rebin);
	  h_WV_0_03->Rebin(rebin);

	}
   
	doVariableBinHisto(h_data);
	doVariableBinHisto(h_Wjets);
	doVariableBinHisto(h_Zjets);
	doVariableBinHisto(h_diboson);
	doVariableBinHisto(h_singleTop);
	doVariableBinHisto(h_ttbar);
	doVariableBinHisto(h_qcd);
	doVariableBinHisto(h_WV_0_0);
	doVariableBinHisto(h_WV_0_03);
    
	
	c2->SetLogy(logy);
     
	h_data->SetMarkerStyle(20);
	h_data->SetMarkerSize(0.4);
   
      
      
	h_Wjets->SetTitle( "" );

      
	h_Wjets->GetYaxis()->SetLabelSize(0.06);
	h_Wjets->GetYaxis()->SetTitleSize(0.06);

	if (h_Wjets->GetBinWidth(1)== h_Wjets->GetBinWidth(h_Wjets->GetNbinsX())){
	  h_Wjets-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_Wjets->GetBinWidth(1)  )  );
	}else{
	  h_Wjets-> GetYaxis()->SetTitle(  "Entries / GeV"  );
	}
      
	h_Wjets->GetYaxis()->SetTitleOffset(1.4);
	//h_Wjets->GetYaxis()->CenterTitle();
	
	h_Wjets->GetXaxis()->SetLabelSize(0.05);
	h_Wjets->GetXaxis()->SetTitleSize(0.06);
	//h_Wjets->GetXaxis()->SetTitleSize(0.15); //when bottom margin of pad is set to 0.3
	//h_Wjets->GetXaxis()->SetTitleOffset(1.2);


	h_data->Scale(1/h_data->Integral());
	h_Wjets->Scale(1/h_Wjets->Integral());
         
	//double maxi=h_data->GetBinContent(h_data->GetMaximumBin());

	double maxi=h_Wjets->GetBinContent(h_Wjets->GetMaximumBin());
	//cout<<maxi<<endl;
	double tmp=0.;
      
	tmp=h_Wjets->GetBinContent(h_Wjets->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	h_Zjets->Scale(1/h_Zjets->Integral());
	tmp=h_Zjets->GetBinContent(h_Zjets->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	h_diboson->Scale(1/h_diboson->Integral());
	tmp=h_diboson->GetBinContent(h_diboson->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	h_singleTop->Scale(1/h_singleTop->Integral());
	tmp=h_singleTop->GetBinContent(h_singleTop->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	h_ttbar->Scale(1/h_ttbar->Integral());
	tmp=h_ttbar->GetBinContent(h_ttbar->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	
	h_qcd->Scale(1/h_qcd->Integral());
	tmp=h_qcd->GetBinContent(h_qcd->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	
      
	// double maxi=0;
	// double tmp=0.;

	h_WV_0_0->Scale(1/h_WV_0_0->Integral());
	tmp=h_WV_0_0->GetBinContent(h_WV_0_0->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	// h_WV_0_02->Scale(1/h_WV_0_02->Integral());
	// tmp=h_WV_0_02->GetBinContent(h_WV_0_02->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	h_WV_0_03->Scale(1/h_WV_0_03->Integral());
	tmp=h_WV_0_03->GetBinContent(h_WV_0_03->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	// h_ZV_0_0->Scale(1/h_ZV_0_0->Integral());
	// tmp=h_ZV_0_0->GetBinContent(h_ZV_0_0->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	// h_ZV_0_02->Scale(1/h_ZV_0_02->Integral());
	// tmp=h_ZV_0_02->GetBinContent(h_ZV_0_02->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	// h_ZV_03_0->Scale(1/h_ZV_03_0->Integral());
	// tmp=h_ZV_03_0->GetBinContent(h_ZV_03_0->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;

	if(!logy){
	  //h_Wjets->SetMaximum(maxi*1.5);
	  h_Wjets->GetYaxis()->SetRangeUser(0,maxi*2.0);
	}else{
	  h_Wjets->SetMaximum(maxi*200);
	  h_Wjets->SetMinimum(1e-4);
	  //h_Wjets->GetYaxis()->SetRangeUser(1e-4,maxi*200);
	}

	float xstart=h_Wjets->GetBinLowEdge(1);
	float xend=h_Wjets->GetBinLowEdge(h_Wjets->GetNbinsX()+1);

	//cout<<xstart<<","<<xend<<endl;
      
	GetXaxisRange(  h_Wjets , xstart, xend );

	//cout<<"After GetXaxisRange: "<<xstart<<","<<xend<<endl;

	h_Wjets->GetXaxis()->SetRangeUser(xstart,xend);
      
      
	//if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_Wjets->GetXaxis()->SetRangeUser(65,95);}
	//if ( typeName[itype].Contains("Mwjj")) {h_Wjets->GetXaxis()->SetRangeUser(60,110);}
	if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_Wjets->GetXaxis()->SetRangeUser(60,110);}
      
	// h_WV_0_0->SetMaximum(maxi*1.5);
	// h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
	// /*

	h_Wjets->Draw();

      
	if (typeName[itype].Contains("MET_et"))h_Wjets-> GetXaxis()->SetRangeUser( 0,200 );
      
	//h_Wjets->Draw("same ");
	//h_Zjets->Draw("same  ");
	//h_diboson->Draw("same ");
	//h_singleTop->Draw("same ");
	h_ttbar->Draw("same ");
	h_qcd->Draw("same ");
	h_WV_0_0 ->Draw("same ");
	h_WV_0_03->Draw("same ");
  


	h_Wjets->SetLineWidth(1);
	h_Zjets->SetLineWidth(1);
	h_diboson->SetLineWidth(1);
	h_singleTop->SetLineWidth(1);
	h_ttbar->SetLineWidth(1);
	h_qcd->SetLineWidth(1);

	h_WV_0_0 ->SetLineWidth(1);
	h_WV_0_03->SetLineWidth(1);

	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
	//TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	TLegend *leg = new TLegend(0.5, 0.55, 0.95, 0.80) ;
	
	leg->SetNColumns(2);
      
	// leg->AddEntry(h_data,"Data","p");
	leg->AddEntry(h_Wjets,"W+jets","l");
	//leg->AddEntry(h_Zjets,"Z+jets","l");
	//leg->AddEntry(h_diboson,"Di-boson","l");
	//leg->AddEntry(h_singleTop,"single top","l");
	leg->AddEntry(h_ttbar,"ttbar","l");
	leg->AddEntry(h_qcd,"QCD","l");
	leg->AddEntry(h_WV_0_0,"WV SM","l");
	leg->AddEntry(h_WV_0_03,"WV (0,0.3)","l");
	leg->Draw();
	
	
	TLatex l;
	l.SetTextSize(0.04); 
	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	l.SetTextColor(1); //black
	//l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
	l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Preliminary}");
	//l.DrawLatex(0.18 , 0.84,"ATLAS #bf{work in progress}");
	l.DrawLatex(0.18 , 0.74,"#int Ldt = 20.2 fb^{-1}"); //new lumi

	TString latexFlav("");
	if(!doMerge){
	
	  if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
	  else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
	  else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
	  else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
      
	
	}else{
	  if (flavorName[iFlavor] == "e") { latexFlav = "e";}
	  else if (flavorName[iFlavor] == "m") { latexFlav = "#mu";}
	  latexFlav ="l"; //&&&& hard coded
	}
	l.DrawLatex(0.18 , 0.64,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), cutName[icut].Data()) );
      
	c2->SetBottomMargin(0.14);
	c2->SetLeftMargin(0.16);
	c2->SetRightMargin(0.12);
	
    
	  
	gStyle->SetOptStat(0);

	  
      
      
	//c2->Print(Form("plots_shape_withSig.pdf" ),Form("Title:%s_%s_%s",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
	c2->Print(Form("PDF_syst_band/%s_%s_%s.pdf",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()) );
      
      }
    }
  }
      
  f->Close();
  //f1->Close();
  

  //c2->Print("plots_shape_withSig.pdf]");
}
