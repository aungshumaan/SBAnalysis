

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



void shapeCompWithSignal_tmp2(){
  ////Special purpose code. PLEASE DON'T CHANGE IT!!!!!
  //shape comparison between different signal points

  bool debug =0;

  bool doMerge =true;
  //if (!doMerge){ //don't comment out. flavorName will go out of scope
  //const int nFlav=4;TString flavorName[nFlav]={"em","ep","mm","mp"};
  // }else{
  const int nFlav=2;TString flavorName[nFlav]={"e","m"};
  //}


  //TH1F *h_WV_0_0;
  
  
  //TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  
  TH1F *h_WV_0_0, *h_WV_0_01, *h_WV_0_02, *h_WV_0_03, *h_ZV_0_0, *h_ZV_0_01, *h_ZV_0_02 , *h_ZV_0_03 ;
  TH1F *h_WV_01_0, *h_WV_005_0, *h_WV_03_0, *h_ZV_01_0, *h_ZV_02_0 , *h_ZV_03_0 ;
  
  //TCanvas *c2 = new TCanvas();
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  
  //c2->Print("plots_shape_withSig_tmp2.pdf[");
  

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_all97.root");
  


  
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"SRfatOnly"};


  const int nType=1;TString typeName[nType]={"mTWV"};

  
  

  if (debug) cout<<"Hello1"<<endl;

  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iFlavor=0;iFlavor<nFlav;++iFlavor){

  	if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}

  	bool logy=false;
  	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptlvjj")|| typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("MET_et") || typeName[itype].Contains("lep_pt")  || typeName[itype].Contains("mTWV")){
  	  logy = true;
  	}
	if (!doMerge){

      
      
  	  h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_01=(TH1F*)f->Get(Form("H_VBS_WV_0_01_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_02=(TH1F*)f->Get(Form("H_VBS_WV_0_02_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_03=(TH1F*)f->Get(Form("H_VBS_WV_0_03_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

  	  h_WV_01_0=(TH1F*)f->Get(Form("H_VBS_WV_01_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_005_0=(TH1F*)f->Get(Form("H_VBS_WV_005_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_03_0=(TH1F*)f->Get(Form("H_VBS_WV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

  	  
  	  // h_ZV_0_0=(TH1F*)f->Get(Form("H_VBS_ZV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      	  // h_ZV_0_01=(TH1F*)f->Get(Form("H_VBS_ZV_0_01_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  // h_ZV_0_02=(TH1F*)f->Get(Form("H_VBS_ZV_0_02_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  // h_ZV_0_03=(TH1F*)f->Get(Form("H_VBS_ZV_0_03_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  
	  // h_ZV_01_0=(TH1F*)f->Get(Form("H_VBS_ZV_01_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  // h_ZV_03_0=(TH1F*)f->Get(Form("H_VBS_ZV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	}
	//	/*
  	else{

  	  double s =1.; //add or subtract negative charge
   
  

      
      
  	  h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_0->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  	  h_WV_0_01=(TH1F*)f->Get(Form("H_VBS_WV_0_01_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_01->Add((TH1F*)f->Get(Form("H_VBS_WV_0_01_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  	  h_WV_0_02=(TH1F*)f->Get(Form("H_VBS_WV_0_02_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_02->Add((TH1F*)f->Get(Form("H_VBS_WV_0_02_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  	  h_WV_0_03=(TH1F*)f->Get(Form("H_VBS_WV_0_03_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_0_03->Add((TH1F*)f->Get(Form("H_VBS_WV_0_03_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);

  	  h_WV_01_0=(TH1F*)f->Get(Form("H_VBS_WV_01_0_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_01_0->Add((TH1F*)f->Get(Form("H_VBS_WV_01_0_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  	  h_WV_005_0=(TH1F*)f->Get(Form("H_VBS_WV_005_0_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_005_0->Add((TH1F*)f->Get(Form("H_VBS_WV_005_0_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  	  h_WV_03_0=(TH1F*)f->Get(Form("H_VBS_WV_03_0_%sp_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
  	  h_WV_03_0->Add((TH1F*)f->Get(Form("H_VBS_WV_03_0_%sm_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
  
  	}
	//	*/	
      
  	if (debug) cout<<"Hello2"<<endl;
	
	h_WV_0_0->SetLineColor(kBlue);
  	h_WV_0_01->SetLineColor(kGreen);
  	h_WV_0_02->SetLineColor(kMagenta);
  	h_WV_0_03->SetLineColor(kRed);

  	h_WV_01_0->SetLineColor(kGreen);
  	h_WV_005_0->SetLineColor(kMagenta);
  	h_WV_03_0->SetLineColor(kRed);

  	int rebin =1;
  	int rebinFac =1;

  	if (!(typeName[itype].Contains("Njet"))){
	 

  	  rebinFac = getRebinFactor(typeName[itype]);
  	  rebin *=rebinFac;
	  
  	  h_WV_0_0->Rebin(rebin);
  	  h_WV_0_01->Rebin(rebin);
  	  h_WV_0_02->Rebin(rebin);
  	  h_WV_0_03->Rebin(rebin);

  	  h_WV_01_0->Rebin(rebin);
  	  h_WV_005_0->Rebin(rebin);
  	  h_WV_03_0->Rebin(rebin);

  	}
	
  	if (debug) cout<<"Hello3"<<endl;

	
  	doVariableBinHisto(h_WV_0_0);
  	doVariableBinHisto(h_WV_0_01);
  	doVariableBinHisto(h_WV_0_02);
  	doVariableBinHisto(h_WV_0_03);

  	doVariableBinHisto(h_WV_01_0);
  	doVariableBinHisto(h_WV_005_0);
  	doVariableBinHisto(h_WV_03_0);
    
	
	c2->SetLogy(logy);
     
	
   
	//if (debug) cout<<"Hello3"<<endl;
	
	h_WV_0_0->SetTitle( "" );
    
    	h_WV_0_0->GetYaxis()->SetLabelSize(0.05);
  	h_WV_0_0->GetYaxis()->SetTitleSize(0.05);

  	if (h_WV_0_0->GetBinWidth(1)== h_WV_0_0->GetBinWidth(h_WV_0_0->GetNbinsX())){
  	  h_WV_0_0-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_WV_0_0->GetBinWidth(1)  )  );
  	}else{
  	  h_WV_0_0-> GetYaxis()->SetTitle(  "Entries / GeV"  );
  	}
      
  	h_WV_0_0->GetYaxis()->SetTitleOffset(1);
  	//h_WV_0_0->GetYaxis()->CenterTitle();
	
  	h_WV_0_0->GetXaxis()->SetLabelSize(0.05);
  	h_WV_0_0->GetXaxis()->SetTitleSize(0.05);
  	//h_WV_0_0->GetXaxis()->SetTitleSize(0.15); //when bottom margin of pad is set to 0.3
  	//h_WV_0_0->GetXaxis()->SetTitleOffset(1.2);


  
  	h_WV_0_0->Scale(1/h_WV_0_0->Integral());
         


  	double maxi=h_WV_0_0->GetBinContent(h_WV_0_0->GetMaximumBin());
  	//cout<<maxi<<endl;
  	double tmp=0.;
      
   	// /* //&&&&
  	h_WV_0_01->Scale(1/h_WV_0_01->Integral());
  	tmp=h_WV_0_01->GetBinContent(h_WV_0_01->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
  	h_WV_0_02->Scale(1/h_WV_0_02->Integral());
  	tmp=h_WV_0_02->GetBinContent(h_WV_0_02->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
  	h_WV_0_03->Scale(1/h_WV_0_03->Integral());
  	tmp=h_WV_0_03->GetBinContent(h_WV_0_03->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
  	// */
  	/* //&&&&
  	h_WV_01_0->Scale(1/h_WV_01_0->Integral());
  	tmp=h_WV_01_0->GetBinContent(h_WV_01_0->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
  	h_WV_005_0->Scale(1/h_WV_005_0->Integral());
  	tmp=h_WV_005_0->GetBinContent(h_WV_005_0->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
  	h_WV_03_0->Scale(1/h_WV_03_0->Integral());
  	tmp=h_WV_03_0->GetBinContent(h_WV_03_0->GetMaximumBin());
  	if(tmp>maxi)maxi=tmp;
	*/

  	if(!logy){
  	  //h_WV_0_0->SetMaximum(maxi*1.5);
  	  h_WV_0_0->GetYaxis()->SetRangeUser(0,maxi*1.5);
  	}else{
  	  h_WV_0_0->SetMaximum(maxi*200);
  	  h_WV_0_0->SetMinimum(1e-4);
  	  //h_WV_0_0->GetYaxis()->SetRangeUser(1e-4,maxi*200);
  	}

  	float xstart=h_WV_0_0->GetBinLowEdge(1);
  	float xend=h_WV_0_0->GetBinLowEdge(h_WV_0_0->GetNbinsX()+1);

  	//cout<<xstart<<","<<xend<<endl;
      
  	GetXaxisRange(  h_WV_0_0 , xstart, xend );

  	//cout<<"After GetXaxisRange: "<<xstart<<","<<xend<<endl;

  	h_WV_0_0->GetXaxis()->SetRangeUser(xstart,xend);
      
      
  	//if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_WV_0_0->GetXaxis()->SetRangeUser(65,95);}
  	//if ( typeName[itype].Contains("Mwjj")) {h_WV_0_0->GetXaxis()->SetRangeUser(60,110);}
  	if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_WV_0_0->GetXaxis()->SetRangeUser(60,110);}
      
  	// h_WV_0_0->SetMaximum(maxi*1.5);
  	// h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
  

  	h_WV_0_0->Draw();
	h_WV_0_0 ->SetLineWidth(1);
 
	// /*
	h_WV_0_01 ->Draw("same ");
	h_WV_0_02 ->Draw("same ");
	h_WV_0_03->Draw("same ");
	h_WV_0_01 ->SetLineWidth(1);	
	h_WV_0_02 ->SetLineWidth(1);
	h_WV_0_03->SetLineWidth(1);
	// */
  	
	/*
  	h_WV_01_0 ->Draw("same ");
  	h_WV_005_0 ->Draw("same ");
  	h_WV_03_0->Draw("same ");
	h_WV_01_0 ->SetLineWidth(1);	
	h_WV_005_0 ->SetLineWidth(1);
	h_WV_03_0->SetLineWidth(1);
  	 */
	
	
	
  	TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
  	leg->SetNColumns(2);
      

  	leg->AddEntry(h_WV_0_0,"WV SM","l");
  	// /*
  	leg->AddEntry(h_WV_0_01,"WV (0,0.1)","l");
  	leg->AddEntry(h_WV_0_02,"WV (0,0.2)","l");
  	leg->AddEntry(h_WV_0_03,"WV (0,0.3)","l");
  	// */
  	 /*
  	leg->AddEntry(h_WV_005_0,"WV (0.05,0)","l");
  	leg->AddEntry(h_WV_01_0,"WV (0.1,0)","l");
  	leg->AddEntry(h_WV_03_0,"WV (0.3,0)","l");
  	 */
  	leg->Draw();
	
	
  	TLatex l;
  	l.SetTextSize(0.04); 
  	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
  	l.SetTextColor(1); //black
  	l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Preliminary}");
  	l.DrawLatex(0.20 , 0.74,"#int Ldt = 20.2 fb^{-1}");

  	TString latexFlav("");
  	if(!doMerge){
	
  	  if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
  	  else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
  	  else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
  	  else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
      
	
  	}else{
  	  if (flavorName[iFlavor] == "e") { latexFlav = "e";}
  	  else if (flavorName[iFlavor] == "m") { latexFlav = "#mu";}

  	}
  	l.DrawLatex(0.20 , 0.64,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), cutName[icut].Data()) );
      
	
    
	  
  	gStyle->SetOptStat(0);

	  
      
      
  	//c2->Print(Form("plots_shape_withSig_tmp2.pdf" ),Form("Title:%s_%s_%s",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
  	c2->Print(Form("PDF_syst_band/%s_%s_%s_alpha5.pdf",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()) );
      
      }
    }
  }
      
  f->Close();
  //f1->Close();
  

  //c2->Print("plots_shape_withSig_tmp2.pdf]");
}
