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

void stackPlotWithSignal(){
  ////stack plots
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}


  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print(Form("plots_stack_withSignal_%s.pdf[",lepName.Data() ));

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.Nominal.2.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots_test2.fatjetpt100.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.Nominal.root");
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");

  

  ////Signal 
  //TFile *f1=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10_signalOnly.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.sig_all.2.root");
  ////

  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.4.2_variableBin.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.4.2_variableBin.root");

  
  const int nCut=2;TString cutName[nCut]={"CR_Wjj","SR"};
  //const int nCut=2;TString cutName[nCut]={"SR","SRFJ"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopFJ","SR","SRFJ"};
  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};

  //const int nType=1;TString typeName[nType]={"Njet"};
  //const int nType=6;TString typeName[nType]={"cosThetaWlep","cosThetaWDecay","lepCentrality", "bosonCentrality","mTWV","VVvecptdiff"};
  //const int nType=7;TString typeName[nType]={"dEtaTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  //const int nType =18;  TString typeName[nType]   = { "dEtaTaggedJets","dRTaggedJets","mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptjjTagged","ptwjj","ptwlep","Mlvjj","Mwjj","fatjet_pt","lep_pt","MET_et","mT","Njet"};
  const int nType=26;TString typeName[nType]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVvecptdiff"};
        
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      
      THStack *hs = new THStack("hs","");

      bool logy=false;
      if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("mTWV") || typeName[itype].Contains("VVvecptdiff") ){
	logy = true;
      }
      if ( (typeName[itype].Contains("cosThetaWDecay") || typeName[itype].Contains("dRWjets")) && cutName[icut].Contains("FJ") ){continue;} 

      double s =-1.; //add or subtract negative charge
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
      h_qcd=(TH1F*)f->Get(Form("H_QCD_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_qcd->Add((TH1F*)f->Get(Form("H_QCD_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);

      ////&&&&
      h_WV_0_0=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s", lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s", lep.Data(), cutName[icut].Data(), typeName[itype].Data())),s);

      //h_WV_0_02=(TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sp_WBF_%s_%s", lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      //h_WV_0_02->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sm_WBF_%s_%s", lep.Data(), cutName[icut].Data(), typeName[itype].Data())),s);

      h_WV_03_0=(TH1F*)f1->Get(Form("H_VBS_WV_03_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_03_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_03_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);

      h_ZV_0_0=(TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ZV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);

      //h_ZV_0_02=(TH1F*)f1->Get(Form("H_VBS_ZV_0_02_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      //h_ZV_0_02->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_02_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);

      h_ZV_03_0=(TH1F*)f1->Get(Form("H_VBS_ZV_03_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ZV_03_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_03_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);

     
      /////
          

      h_data->SetLineColor(kBlack);
      h_Wjets->SetFillColor(kCyan);
      h_Zjets->SetFillColor(kBlue);
      h_diboson->SetFillColor(kMagenta+2);
      h_singleTop->SetFillColor(kYellow-5);
      h_ttbar->SetFillColor(kYellow);
      h_qcd->SetFillColor(kGreen);
      ///&&&&
      h_WV_0_0->SetLineColor(kRed);
      h_WV_0_0->SetLineWidth(3);

      //h_WV_0_02->SetLineColor(kOrange);
      //h_WV_0_02->SetLineWidth(3);

      h_WV_03_0->SetLineColor(kViolet);
      h_WV_03_0->SetLineWidth(3);

      h_ZV_0_0->SetLineColor(kRed-2);
      h_ZV_0_0->SetLineWidth(3);

      //h_ZV_0_02->SetLineColor(kYellow+2);
      //h_ZV_0_02->SetLineWidth(3);

      h_ZV_03_0->SetLineColor(kBlue-4);
      h_ZV_03_0->SetLineWidth(3);

      double rebin =4;
      if (!(typeName[itype].Contains("Njet"))&&!(typeName[itype].Contains("Mwjj"))){
      	h_data->Rebin(rebin);
      	h_Wjets->Rebin(rebin);
      	h_Zjets->Rebin(rebin);
      	h_diboson->Rebin(rebin);
      	h_singleTop->Rebin(rebin);
      	h_ttbar->Rebin(rebin);
	      	h_qcd->Rebin(rebin);

      	h_WV_0_0->Rebin(rebin);
      	//h_WV_0_02->Rebin(rebin);
      	h_WV_03_0->Rebin(rebin);
      	h_ZV_0_0->Rebin(rebin);
      	//h_ZV_0_02->Rebin(rebin);
      	h_ZV_03_0->Rebin(rebin);

      }
    


      hs->Add(h_diboson);
      hs->Add(h_Zjets);	
      hs->Add(h_Wjets);
      hs->Add(h_ttbar);
      hs->Add(h_singleTop);
            hs->Add(h_qcd);

      /////Setup the two pads before drawing histograms
      float ratio_size = 0.35 ;
      TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
      p1->Draw();
      p1->SetBottomMargin(0.00);
      p1->SetRightMargin(0.12);
		
      p2->Draw();
      p2->SetTopMargin(0.00);
      p2->SetBottomMargin(0.25);
      p2->SetRightMargin(0.12);
		
      p1->cd();
      ///// pad1

      p1->cd()->SetLogy(logy); 
	
      // hs->SetMaximum(hs->GetMaximum()*1.5);
      // if (logy)hs->SetMaximum(hs->GetMaximum()*200.);
      // hs->SetMinimum(1);
	
      hs->Draw("hist");
    

      hs->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      std::cout<<Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data())<<endl;
      
      //hs->SetTitle("");
      h_data->SetMarkerStyle(20);
      h_data->SetMarkerSize(1);
	
	
      h_data->GetYaxis()->SetLabelSize(0.1);
      //h_data->GetYaxis()->SetTitleSize(0.1);
      //h_data->GetYaxis()->SetLabelSize(0.3);
      //h_data->GetYaxis()->SetTitleSize(0.3);
      h_data->GetYaxis()->SetTitleOffset(0.7);
      h_data->GetYaxis()->CenterTitle();
	
      //h_data->GetXaxis()->SetLabelSize(0.1);
      //h_data->GetXaxis()->SetTitleSize(0.1);
      h_data->GetXaxis()->SetLabelSize(0.15);
      h_data->GetXaxis()->SetTitleSize(0.3);
      h_data->GetXaxis()->SetTitleOffset(1.2);
      h_data-> GetXaxis()->SetTitle( "" );
      //hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
      hs-> GetYaxis()->SetLabelSize(0.05);

  
      if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){
	h_data->GetXaxis()->SetRangeUser(65,95);
	hs->GetXaxis()->SetRangeUser(65,95);
      }
      if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SRFJ"){
	h_data->GetXaxis()->SetRangeUser(60,110);
	hs->GetXaxis()->SetRangeUser(60,110);
      }

      h_data->Draw("same");

      ////&&&&
      h_WV_0_0->Scale(100);
      //h_WV_0_02->Scale(100);
      h_WV_03_0->Scale(100);

      h_ZV_0_0->Scale(100);
      //h_ZV_0_02->Scale(100);
      h_ZV_03_0->Scale(100);

      h_WV_0_0->Draw("hist same");
      //h_WV_0_02->Draw("same");
      h_WV_03_0->Draw("hist same");

      h_ZV_0_0->Draw("hist same");
      //h_ZV_0_02->Draw("same");
      h_ZV_03_0->Draw("hist same");

      double maxi=hs->GetMaximum();
      if (h_WV_03_0->GetBinContent(h_WV_03_0->GetMaximumBin())> maxi){maxi =h_WV_03_0->GetBinContent(h_WV_03_0->GetMaximumBin());}
      hs->SetMaximum(maxi*1.8);
      if (logy)hs->SetMaximum(maxi*200.);
      hs->SetMinimum(1);

      
      	
      h_MC=(TH1F*)h_Wjets->Clone();
      h_MC->Add(h_Zjets);
      h_MC->Add(h_diboson);
      h_MC->Add(h_singleTop);
      h_MC->Add(h_ttbar);
            h_MC->Add(h_qcd);

      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // std::cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      TLegend *leg = new TLegend(0.5, 0.60, 0.85, 0.88) ;
      leg->SetNColumns(2);
      
      leg->AddEntry(h_data,"Data","p");
      leg->AddEntry(h_WV_0_0,"WV(0,0)*100");
      leg->AddEntry(h_Wjets,"W+jets","f");
      //leg->AddEntry(h_WV_0_02,"WV(0,0.2)*100");
      leg->AddEntry(h_WV_03_0,"WV(0.3,0)*100");
      leg->AddEntry(h_Zjets,"Z+jets","f");
      leg->AddEntry(h_ZV_0_0,"ZV(0,0)*100","l");
      leg->AddEntry(h_diboson,"Di-boson","f");
      leg->AddEntry(h_ZV_03_0,"ZV(0.3,0)*100","l");
      leg->AddEntry(h_singleTop,"single top","f");
      //leg->AddEntry(h_ZV_0_02,"ZV(0,0.2)*100","l");
      leg->AddEntry(h_ttbar,"ttbar","f");
            leg->AddEntry(h_qcd,"QCD","f");
      
      leg->Draw();
      
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
      double xstart=h_data->GetBinLowEdge(1);
      double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);
	  
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h_data->Clone();
      ratioHist->Divide(h_MC);
      ratioHist->GetYaxis()->SetRangeUser(0.3, 1.9);
      ratioHist->Draw();
      ratioHist->SetTitle("");
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      horiz_line->DrawLine(xstart,1.0,xend,1.0);

  
      c2->Print(Form("plots_stack_withSignal_%s.pdf",lepName.Data() ),Form("Title:%s_%s_%s",lep.Data(),cutName[icut].Data(),typeName[itype].Data()));
      
      p1->Clear();
      p2->Clear();
      
      c2->cd();
      delete hs;
      
    }
  }
  
  f->Close();
  f1->Close();
   
  c2->Print(Form("plots_stack_withSignal_%s.pdf]",lepName.Data() ));
}
