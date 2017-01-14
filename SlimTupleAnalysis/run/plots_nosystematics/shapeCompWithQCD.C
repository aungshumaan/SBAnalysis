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

void shapeCompWithQCD(){
  ////shape comparison

  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_0_03,*h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  
  //TCanvas *c2 = new TCanvas();
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  
  c2->Print("plots_shape_withQCD.pdf[");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv4.4_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");
  
  
  const int nFlav=4;TString flavorName[nFlav]={"em","ep","mm","mp"};
  //const int nFlav=2;TString flavorName[nFlav]={"e","m"};
            
  
  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};
  //const int nCut=3;TString cutName[nCut]={"CR_Wjj","SR","SRfatOnly"};
  //const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ","SR","SRfatOnly"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};


  //const int nType=2;TString typeName[nType]={"MET_et","mjjTagged"};
  //const int nType=8;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  
  const int nType=11;TString typeName[nType]={"ptwjj","ptwlep","Mlvjj","mTWV","VVptBalance","mjjTagged","dEtaTaggedJets", "bosonCentrality","lepCentrality","cosThetaWDecay","cosThetaWlep"};
  


  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
    for (int iFlavor=0;iFlavor<nFlav;++iFlavor){

      if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}

      bool logy=false;
      if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptlvjj")|| typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("MET_et") || typeName[itype].Contains("lep_pt")  || typeName[itype].Contains("mTWV")){
       	logy = true;
      }
      
      h_data = (TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_Zjets= (TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_diboson= (TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_singleTop= (TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ttbar= (TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
     
      h_qcd= (TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

      
      
      h_WV_0_0=(TH1F*)f->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_0_03=(TH1F*)f->Get(Form("H_VBS_WV_0_03_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      //h_WV_03_0=(TH1F*)f->Get(Form("H_VBS_WV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));      
      // h_ZV_0_0=(TH1F*)f->Get(Form("H_VBS_ZV_0_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      
      // h_ZV_0_02=(TH1F*)f->Get(Form("H_VBS_ZV_0_02_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      // h_ZV_03_0=(TH1F*)f->Get(Form("H_VBS_ZV_03_0_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
      

 	
      
           
      h_data->SetLineColor(kBlack);
      h_Wjets->SetLineColor(kCyan);
      h_Zjets->SetLineColor(kBlue);
      h_diboson->SetLineColor(kMagenta+2);
      h_singleTop->SetLineColor(kRed);
      h_ttbar->SetLineColor(kOrange);
      h_qcd->SetLineColor(kGreen-8);

      h_WV_0_0->SetLineColor(kRed);
      h_WV_0_03->SetLineColor(kBlue-2);

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
   

    
	
      c2->SetLogy(logy);
     
      h_data->SetMarkerStyle(20);
      h_data->SetMarkerSize(0.4);
   
      
      
      h_Wjets->SetTitle( "" );
    
      //std::cout<<"h_Wjets XaxisName = "<<h_Wjets->GetXaxis()->GetTitle()<<endl;
      //std::cout<<"h_Wjets YaxisName = "<<h_Wjets->GetYaxis()->GetTitle()<<endl;
      
      h_Wjets->GetYaxis()->SetLabelSize(0.05);
      h_Wjets->GetYaxis()->SetTitleSize(0.05);

      //h_Wjets->GetYaxis()->SetLabelSize(0.3);
      //h_Wjets->GetYaxis()->SetTitleSize(0.3);

      if (h_Wjets->GetBinWidth(1)== h_Wjets->GetBinWidth(h_Wjets->GetNbinsX())){
	h_Wjets-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_Wjets->GetBinWidth(1)  )  );
      }else{
	h_Wjets-> GetYaxis()->SetTitle(  "Entries / GeV"  );
      }
      
      h_Wjets->GetYaxis()->SetTitleOffset(1);
      //h_Wjets->GetYaxis()->CenterTitle();
	
      h_Wjets->GetXaxis()->SetLabelSize(0.05);
      h_Wjets->GetXaxis()->SetTitleSize(0.05);
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
      	h_Wjets->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
      	h_Wjets->SetMaximum(maxi*200);
	h_Wjets->SetMinimum(1e-4);
      	//h_Wjets->GetYaxis()->SetRangeUser(1e-4,maxi*200);
      }
      //if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_Wjets->GetXaxis()->SetRangeUser(65,95);}
      //if ( typeName[itype].Contains("Mwjj")) {h_Wjets->GetXaxis()->SetRangeUser(60,110);}
      if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_Wjets->GetXaxis()->SetRangeUser(60,110);}
      
      // h_WV_0_0->SetMaximum(maxi*1.5);
      // h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      // /*

      h_Wjets->Draw();

      //h_data->Draw();
      //h_data->Draw("same");

      
      if (typeName[itype].Contains("MET_et"))h_Wjets-> GetXaxis()->SetRangeUser( 0,200 );
      
      //h_Zjets->Draw("same  ");
      //h_diboson->Draw("same ");
      //h_singleTop->Draw("same ");
      h_ttbar->Draw("same ");
      //h_Wjets->Draw("same ");
      h_qcd->Draw("same ");
      h_WV_0_0 ->Draw("same ");
      h_WV_0_03->Draw("same ");
  


      h_Wjets->SetLineWidth(1);
      h_Zjets->SetLineWidth(1);
      h_diboson->SetLineWidth(1);
      h_singleTop->SetLineWidth(1);
      h_ttbar->SetLineWidth(1);
      h_qcd->SetLineWidth(1);

      h_WV_0_0 ->SetLineWidth(2);
      h_WV_0_03->SetLineWidth(2);

      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
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
      l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
      l.DrawLatex(0.20 , 0.74,"#int Ldt = 20.3 fb^{-1}");

      TString latexFlav("");
      if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
      else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
      else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
      else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
      
      l.DrawLatex(0.20 , 0.64,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), cutName[icut].Data()) );
	
      double xstart=h_data->GetBinLowEdge(1);
      double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);
	  
      gStyle->SetOptStat(0);

	  
      
      
      

      c2->Print(Form("plots_shape_withQCD.pdf" ),Form("Title:%s_%s_%s",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()));
      //c2->Print(Form("PDF_syst_band/%s_%s_%s.pdf",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()) );
         
      c2->cd();

    }
  }
  }
      
  f->Close();
  //f1->Close();
  

  c2->Print("plots_shape_withQCD.pdf]");
}
