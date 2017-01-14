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

#include "makerHelper.h" //for AddOverflowBinToLastBin function
#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"

//void addOverFlowBin(TH1*); //Not necessary anymore.
void syst_band_test(){

  //gROOT->LoadMacro("atlasstyle-00-03-05/AtlasStyle.C");
  //SetAtlasStyle();
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>
  
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots
  
  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}

  const int nsyst =20;  
  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.


  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print(Form("plots_syst_band_%s.pdf[",lepName.Data() )); //&&&&

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.41.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4_smw_mlj_NEWcutflow.root");
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw_NEWcutflow.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv4_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv7_looseBadMuon1.1.root");
  
  
   
   

  //const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};    
  const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjfatOnly","CR_Top","CR_TopfatOnly","SR","SRfatOnly"};
  //const int nCut=4;TString cutName[nCut]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  //const int nCut=5;TString cutName[nCut]={"CR_Top","CR_TopFJ","CR_Wjj","SR","SRfatOnly"};
  //const int nCut=2;TString cutName[nCut]={ "CR_Wjj","SR"};


  const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};
  
  for (int icut=0;icut<nCut;++icut){
    for (int itype=0;itype<nType;++itype){

      if (( cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
      
      THStack *hs = new THStack("hs","");

      bool logy=false;
      if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptlvjj")|| typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("MET_et") || typeName[itype].Contains("lep_pt")){
	logy = true;
      }
      //<<<< From fakeEstimation root file >>>>

      double s =1.; //add or subtract negative charge
   
      h_data=(TH1F*)f->Get(Form("H_Data_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_data->Add((TH1F*)f->Get(Form("H_Data_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
      h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);


      
      h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
      h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
      h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
      h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);



  
     
      /////
          

      h_data->SetLineColor(kBlack);
      h_Wjets->SetFillColor(kCyan);

      h_Zjets->SetFillColor(kBlue);
      h_diboson->SetFillColor(kMagenta+2);
      h_singleTop->SetFillColor(kYellow-5);
      h_ttbar->SetFillColor(kYellow);


      ///Overflow bin
  
      AddOverflowBinToLastBin(h_data);
      AddOverflowBinToLastBin(h_Wjets);
      AddOverflowBinToLastBin(h_Zjets);
      AddOverflowBinToLastBin(h_diboson);
      AddOverflowBinToLastBin(h_singleTop);
      AddOverflowBinToLastBin(h_ttbar);

      
      
      int rebin=1;

      int rebinFac =1;
      rebinFac = getRebinFactor(typeName[itype]);
      rebin *=rebinFac;
	
      h_data->Rebin(rebin);
      h_Wjets->Rebin(rebin);
      h_Zjets->Rebin(rebin);
      h_diboson->Rebin(rebin);
      h_singleTop->Rebin(rebin);
      h_ttbar->Rebin(rebin);



      doVariableBinHisto(h_data);
      doVariableBinHisto(h_Wjets);
      doVariableBinHisto(h_Zjets);
      doVariableBinHisto(h_diboson);
      doVariableBinHisto(h_singleTop);
      doVariableBinHisto(h_ttbar);


  
      

      hs->Add(h_diboson);
      hs->Add(h_Zjets);	
      hs->Add(h_Wjets);
      hs->Add(h_ttbar);
      hs->Add(h_singleTop);


      /////Setup the two pads before drawing histograms
      float ratio_size = 0.35 ;
      TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
      p1->Draw();
      p1->SetBottomMargin(0.00);
      p1->SetRightMargin(0.12);
		
      p2->Draw();
      p2->SetTopMargin(0.00);
      //p2->SetBottomMargin(0.25);
      p2->SetBottomMargin(0.31);
      p2->SetRightMargin(0.12);
		
      p1->cd();
      ///// pad1

      p1->cd()->SetLogy(logy); 
	
      hs->SetMaximum(hs->GetMaximum()*1.5);
      if (logy)hs->SetMaximum(hs->GetMaximum()*200.);
      //hs->SetMinimum(1);
      hs->SetMinimum(1.e-2);
	
      hs->Draw("hist");
    

      //hs->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      std::cout<<Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data())<<endl;
      
      // hs->SetTitle("");
      //hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
      if (h_data->GetBinWidth(1)== h_data->GetBinWidth(h_data->GetNbinsX())){
	if (h_data->GetBinWidth(1)<0.1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.2f", h_data->GetBinWidth(1)  )  );
	else hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
      }else{
	hs-> GetYaxis()->SetTitle(  "Entries / GeV"  );
      }
      // hs-> GetYaxis()->SetTitleSize(0.05);

      // //cout<<hs-> GetYaxis()->GetTitleSize();
      // hs-> GetYaxis()->SetLabelSize(0.05);
      // hs-> GetYaxis()->SetTitleOffset(1);

      setStackStyle (hs);
      
      
      h_data->SetMarkerStyle(20);
      h_data->SetMarkerSize(1);
	
	
  
     

  
      if ( typeName[itype].Contains("Mwjj") ){
	  if ( cutName[icut]=="CR_Top" || cutName[icut]=="SR"){
	    h_data->GetXaxis()->SetRangeUser(60,100); //hard coded
	    hs->GetXaxis()->SetRangeUser(60,100);
	  }else if (  cutName[icut]=="CR_TopFJ" || cutName[icut]=="SRFJ"  || cutName[icut]=="CR_TopfatOnly" || cutName[icut]=="SRfatOnly"){
	    h_data->GetXaxis()->SetRangeUser(60,100); //hard coded
	    hs->GetXaxis()->SetRangeUser(60,100);
	  }
      }
      
      h_data->Draw("same");


      	

      h_MC=(TH1F*)h_Wjets->Clone();
      h_MC->Add(h_Zjets);
      h_MC->Add(h_diboson);
      h_MC->Add(h_singleTop);
      h_MC->Add(h_ttbar);

      
      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // std::cout<<"KolmogorovTest result= "<<ks<<endl;

 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
      leg->SetNColumns(2);
      
      leg->AddEntry(h_data,"Data","p");
      leg->AddEntry(h_Wjets,"W+jets","f");
      leg->AddEntry(h_Zjets,"Z+jets","f");
      leg->AddEntry(h_diboson,"Di-boson","f");
      leg->AddEntry(h_singleTop,"single top","f");
      leg->AddEntry(h_ttbar,"ttbar","f");

      


      leg->Draw();
      
      TLatex l;
      l.SetTextSize(0.055); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
      l.DrawLatex(0.20 , 0.72,"#int Ldt = 20.3 fb^{-1}");
      if (lepName=="electron"){
	l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow e#nu , %s}", cutName[icut].Data() ) );
      }else if (lepName=="muon"){
	l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow #mu#nu , %s}", cutName[icut].Data() ) );
      }
      
      double xstart=h_data->GetBinLowEdge(1);
      double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);

      //range of horizontal line
      if ( typeName[itype].Contains("Mwjj") ){
	  if ( cutName[icut]=="CR_Top" || cutName[icut]=="SR"){
	    xstart = 60.; xend =100.; //hard coded
	  }else if (  cutName[icut]=="CR_TopFJ" || cutName[icut]=="SRFJ"  || cutName[icut]=="CR_TopfatOnly" || cutName[icut]=="SRfatOnly"){
	    xstart = 60.; xend =100.; //hard coded
	  }
      }

      
	  
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h_data->Clone();
      ratioHist->Divide(h_MC);
       
  

      setRatioPlotStyle (ratioHist);
      ratioHist->GetYaxis()->SetRangeUser(0., 2.9);

      ratioHist->Draw();
      
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      horiz_line->DrawLine(xstart,1.0,xend,1.0);

 
       
      
  
      c2->Print(Form("plots_syst_band_%s.pdf",lepName.Data() ),Form("Title:%s_%s_%s",lep.Data(),cutName[icut].Data(),typeName[itype].Data())); //&&&&
      //c2->Print(Form("PDF_syst_band/%s_%s_%s.pdf",lepName.Data(),cutName[icut].Data(),typeName[itype].Data()) );
      
      p1->Clear();
      p2->Clear();
      
      c2->cd();
      delete hs;
      
    }
  }
  
  f->Close();


  
   
  c2->Print(Form("plots_syst_band_%s.pdf]",lepName.Data() )); //&&&&
}



