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

#include "makerHelper.h" //for AddOverflowBinToLastBin function

void stackPlotWithQCD(){
  ////stack plots
  //bool doEl=true; //electron plots
  bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}

   
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WjetsEWK;

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  //c2->Print(Form("plots_stack_withQCD_%s.pdf[",lepName.Data() ));

   c2->Print("plots_stack_withQCD.pdf[","pdf");

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.1.lv4_looseGoodLepton1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.1.lv7.1_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.1.lv7.root");

   //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.1.lv4_looseBadLep4.root");
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.WjetsEWKSherpa.root");
   
   //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7_looseBadLep4.root");
   //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_jetmass.root");
   TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutAwv.root");
   
   const int nCut=3;TString cutName[nCut]={"CR_Wjj","CR_Top","SR"};
   //const int nCut=1;TString cutName[nCut]={"SR"};
   
   //const int nflav=2;TString flavorName[nflav]={"e","m"}; 
  const int nflav=4;TString flavorName[nflav]={"ep","em","mp","mm"};
  //const int nflav=2;TString flavorName[nflav]={"ep","em"};
  //const int nflav=2;TString flavorName[nflav]={"mp","mm"}; 

  ///const int nType=1;TString typeName[nType]={"jet1_mass"};
  const int nType=3;TString typeName[nType]={ "ptwlep","mTWV","MET_et"};
  //const int nType =24 ;TString typeName[nType] = { "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Mwjj","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "dRWjets","lep_pt","lep_eta","MET_et","mT","Njet"};
  //const int nType=27;TString typeName[nType]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVvecptdiff","VVptBalance"};

  //const int nType=4;TString typeName[nType]={"elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0"};
  //const int nType=4;TString typeName[nType]={"muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0"};
  //const int nType=8;TString typeName[nType]={"elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0","muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0"};
        
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iflav=0;iflav<nflav;++iflav){//loops over flavor

	if (cutName[icut] =="SRfatOnly" && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	if ( (flavorName[iflav] =="em" || flavorName[iflav] =="ep") && typeName[itype].Contains("mu")){cout<<"Hello"<<endl;continue;}

	if ( (flavorName[iflav] =="mm" || flavorName[iflav] =="mp") && (typeName[itype].Contains("elRel") || typeName[itype].Contains("eld0") || typeName[itype].Contains("elz0") ) ){cout<<"Hello"<<endl;continue;}

	cout<<Form("%s_%s_%s", flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())<<endl;

	THStack *hs = new THStack("hs","");

	bool logy=false;
	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("MET_et")){
	  logy = true;
	}
      
	double s =1.; //add or subtract negative charge

	// h_data=(TH1F*)f->Get(Form("H_Data_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_data->Add((TH1F*)f->Get(Form("H_Data_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// //h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// //h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_Wjets=(TH1F*)f->Get(Form("H_WjetsScaled_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_Wjets->Add((TH1F*)f->Get(Form("H_WjetsScaled_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	// h_qcd=(TH1F*)f->Get(Form("H_QCD_%sp_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	// h_qcd->Add((TH1F*)f->Get(Form("H_QCD_%sm_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())),s);


	h_data=(TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	//h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_Wjets=(TH1F*)f->Get(Form("H_WjetsScaled_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_qcd=(TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));

	
	h_WjetsEWK=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_%s_WBF_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));
          

	h_data->SetLineColor(kBlack);
	h_Wjets->SetFillColor(kCyan);
	h_Zjets->SetFillColor(kBlue);
	h_diboson->SetFillColor(kMagenta+2);
	h_singleTop->SetFillColor(kYellow-5);
	h_ttbar->SetFillColor(kYellow);
	h_qcd->SetFillColor(kGreen);

	h_WjetsEWK->SetFillColor(kRed);

	int rebin =2;
      
	if (!(typeName[itype].Contains("Njet"))&&!(typeName[itype].Contains("Mwjj"))){
	  h_data->Rebin(rebin);
	  h_Wjets->Rebin(rebin);
	  h_Zjets->Rebin(rebin);
	  h_diboson->Rebin(rebin);
	  h_singleTop->Rebin(rebin);
	  h_ttbar->Rebin(rebin);
	  h_qcd->Rebin(rebin);

	  h_WjetsEWK->Rebin(rebin);

	}

	AddOverflowBinToLastBin(h_data);
	AddOverflowBinToLastBin(h_Wjets);
	AddOverflowBinToLastBin(h_Zjets);
	AddOverflowBinToLastBin(h_diboson);
	AddOverflowBinToLastBin(h_singleTop);
	AddOverflowBinToLastBin(h_ttbar);
	AddOverflowBinToLastBin(h_qcd);
	
	AddOverflowBinToLastBin(h_WjetsEWK);

	hs->Add(h_diboson);
	hs->Add(h_Zjets);	
	hs->Add(h_Wjets);
	hs->Add(h_ttbar);
	hs->Add(h_singleTop);
	hs->Add(h_qcd);

	hs->Add(h_WjetsEWK);

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
	//p1->cd()->SetLogx(1); 
	
	double maxi = h_data->GetBinContent(h_data->GetMaximumBin());
	if (hs->GetMaximum()>maxi) maxi = hs->GetMaximum();
	hs->SetMaximum(maxi*1.8);
	if (logy)hs->SetMaximum(maxi*200.);
	hs->SetMinimum(1);
	
	hs->Draw("hist");
    

	hs->SetTitle(Form("%s_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(), typeName[itype].Data()) );
	std::cout<<Form("%s_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(), typeName[itype].Data())<<endl;
      
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
      
	h_data->Draw("same");
 

      	
	h_MC=(TH1F*)h_Wjets->Clone();
	h_MC->Add(h_Zjets);
	h_MC->Add(h_diboson);
	h_MC->Add(h_singleTop);
	h_MC->Add(h_ttbar);
	h_MC->Add(h_qcd);

	h_MC->Add(h_WjetsEWK);

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
	leg->AddEntry(h_qcd,"QCD","f");
      
	leg->AddEntry(h_WjetsEWK,"W+jets EWK","f");
 
	leg->Draw();
      
	TLatex l;
	l.SetTextSize(0.04); 
	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	l.SetTextColor(1); //black
	l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
	double xstart=h_data->GetBinLowEdge(1);
	double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);
	  
	p2->cd();
	//p2->SetLogx(1); 
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h_data->Clone();
	ratioHist->Divide(h_MC);
	ratioHist->GetYaxis()->SetRangeUser(0.3, 1.9);
	ratioHist->Draw();
	ratioHist->SetTitle("");
	TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	horiz_line->SetLineStyle(2);
	horiz_line->DrawLine(xstart,1.0,xend,1.0);

  
	//c2->Print(Form("plots_stack_withQCD_%s.pdf",lepName.Data() ),Form("Title:%s",typeName[itype].Data()));
	c2->Print("plots_stack_withQCD.pdf",Form("Title:%s_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));

	cout<<Form("%s_%s_%s",flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())<<endl;
      
	p1->Clear();
	p2->Clear();
      
	c2->cd();
	delete hs;
      
      }
    }
  }
  
  f->Close();

   
  //c2->Print(Form("plots_stack_withQCD_%s.pdf]",lepName.Data() ));
  c2->Print("plots_stack_withQCD.pdf]","pdf");
}
