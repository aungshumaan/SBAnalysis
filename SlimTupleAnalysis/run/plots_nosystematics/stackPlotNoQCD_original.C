{
#include "makerHelper.h" //for AddOverflowBinToLastBin function
#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"
  
  bool drawTwoPads = false ;
  
  //gROOT->LoadMacro("atlasstyle-00-03-05/AtlasStyle.C");
  //SetAtlasStyle();
  
  ////stack plots without QCD
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_MC;
  TCanvas *c2 = new TCanvas("","",0,0,750,700);

  c2->Print("plots_stack_noQCD.pdf[","pdf"); //&&&&

  
  
  //TFile *f=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40.root");
  // TFile *f=TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
 
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4_looseBadLep4.root");

  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.4.2_variableBin.root");
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetSignalRegion.caf4.1.lv4_looseBadLep4.root");
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw_NEWcutflow.root");

  
  
  //const int nCut=1;TString cutName[nCut]={"CR_Top"};
  //const int nflav=1;TString flavorName[nflav]={"em"};
  
  //const int nCut=2;TString cutName[nCut]={ "SR", "SRfatOnly"};
  //const int nCut=4;TString cutName[nCut]={"CR_Wjj","CR_WjjfatOnly", "SR", "SRfatOnly"};
  //const int nCut=2;TString cutName[nCut]={"CR_Top","SR"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","SR","CR_TopFJ","SRFJ"};
  const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjfatOnly","CR_Top","CR_TopfatOnly","SR","SRfatOnly"};

  //const int nType=1;TString typeName[nType]={"MET_et"};
  //const int nType=4;TString typeName[nType]={"MET_et","mTWV","mT","cosThetaWlep"};
  //const int nType=10;TString typeName[nType]={"MET_et","mTWV","mT","cosThetaWlep","cosThetaWDecay","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};


  const int nType=9;TString typeName[nType]={"mTWV","mjjTagged","cosThetaWlep","cosThetaWDecay","ptwlep","mjjTagged","bosonCentrality","VVptBalance","Mwjj"};  
  //const int nType=18;TString typeName[nType]={"MET_et","mTWV","mT","cosThetaWlep","cosThetaWDecay","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance","elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0","muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0"};  
  //const int nType=5;TString typeName[nType]={"cosThetaWlep","lepCentrality", "bosonCentrality","mTWV","VVvecptdiff"};
  //const int nType=1;TString typeName[nType]={"ptwlep"};
  //const int nType=3;TString typeName[nType]={"MET_et","ptwlep","mTWV"};
    
  //const int nType=5;TString typeName[nType]={"MET_et","elRelPtCone30","muRelPtCone30","MET_elRelPtCone30_lt02","MET_muRelPtCone30_lt02"};
  //const int nType=8;TString typeName[nType]={"elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0","muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0"};
  //const int nType=12;TString typeName[nType]={"elRelEtCone30","elRelPtCone30","log_elRelEtCone30","log_elRelPtCone30","elz0sinth","eld0sigd0","muRelEtCone30","muRelPtCone30","log_muRelEtCone30","log_muRelPtCone30","muz0sinth","mud0sigd0"};
  //const int nType=2;TString typeName[nType]={"elRelPtCone30","muRelPtCone30"};
  //const int nType=4;TString typeName[nType]={"elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0"};
  //const int nType=4;TString typeName[nType]={"muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0"};
  
  //const int nflav=1;TString flavorName[nflav]={"em"}; 
  //const int nflav=2;TString flavorName[nflav]={"ep","em"}; //electron and positron
  //const int nflav=2;TString flavorName[nflav]={"mp","mm"}; //muon and anti-muon
  const int nflav=4;TString flavorName[nflav]={"ep","em","mp","mm"}; 
      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iflav=0;iflav<nflav;++iflav){//loops over flavor

	if (cutName[icut] =="SRfatOnly" && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	if ( (flavorName[iflav] =="em" || flavorName[iflav] =="ep") && typeName[itype].Contains("mu")){cout<<"Hello"<<endl;continue;}

	if ( (flavorName[iflav] =="mm" || flavorName[iflav] =="mp") && (typeName[itype].Contains("elRel") || typeName[itype].Contains("eld0") || typeName[itype].Contains("elz0") ) ){cout<<"Hello"<<endl;continue;}

	cout<<Form("%s_%s_%s", flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data())<<endl;

	THStack *hs = new THStack("hs","");
	
	bool logy=false;
	//bool logy=true;
	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") || typeName[itype].Contains("mTWV") || typeName[itype].Contains("VVvecptdiff") || typeName[itype].Contains("elRelEtCone30") || typeName[itype].Contains("elRelPtCone30") || typeName[itype].Contains("muRelEtCone30") || typeName[itype].Contains("muRelPtCone30")){
	  logy = true;
	}
	if ( typeName[itype].Contains("MET_elRel") || typeName[itype].Contains("MET_muRel"))logy = false;

	     
	h_data=(TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	

	h_data->SetLineColor(kBlack);
	h_Wjets->SetFillColor(kCyan);
	h_Zjets->SetFillColor(kBlue);
	h_diboson->SetFillColor(kMagenta+2);
	h_singleTop->SetFillColor(kYellow-5);
	h_ttbar->SetFillColor(kYellow);


	int rebin =1;
	int rebinFac =1;
	rebinFac = getRebinFactor(typeName[itype]);
	rebin *=rebinFac;
	//if (typeName[itype].Contains("ptwlep"))rebin =1;
	h_data->Rebin(rebin);
	h_Wjets->Rebin(rebin);
	h_Zjets->Rebin(rebin);
	h_diboson->Rebin(rebin);
	h_singleTop->Rebin(rebin);
	h_ttbar->Rebin(rebin);

	// doVariableBinHisto(h_data);
	// doVariableBinHisto(h_Wjets);
	// doVariableBinHisto(h_Zjets);
	// doVariableBinHisto(h_diboson);
	// doVariableBinHisto(h_singleTop);
	// doVariableBinHisto(h_ttbar);
		

	AddOverflowBinToLastBin(h_data);
	AddOverflowBinToLastBin(h_Wjets);
	AddOverflowBinToLastBin(h_Zjets);
	AddOverflowBinToLastBin(h_diboson);
	AddOverflowBinToLastBin(h_singleTop);
	AddOverflowBinToLastBin(h_ttbar);



	hs->Add(h_diboson);
	hs->Add(h_Zjets);	
	hs->Add(h_Wjets);
	hs->Add(h_ttbar);
	hs->Add(h_singleTop);


	if (drawTwoPads){

	/////Setup the two pads before drawing histograms
	float ratio_size = 0.35 ;
	//float ratio_size = 0.05 ;
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

	} //drawTwoPads

	if (!drawTwoPads){
	  c2->cd()->SetLogy(logy);
	}
	
	double maxi = h_data->GetBinContent(h_data->GetMaximumBin());
	if (hs->GetMaximum()>maxi) maxi = hs->GetMaximum();
	hs->SetMaximum(maxi*1.8);
	if (logy)hs->SetMaximum(maxi*200.);
	hs->SetMinimum(1);

	
	hs->Draw("hist");
	//hs->SetTitle(Form("%s_%s_%s", flavorName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()) ); //&&&&
	hs->SetTitle("");
	
	h_data->SetMarkerStyle(20);
	h_data->SetMarkerSize(1);
	
	

	hs->GetYaxis()->SetTitleOffset(1.2);
	if (drawTwoPads){hs->GetYaxis()->SetLabelSize(0.06);}
	else{hs->GetYaxis()->SetLabelSize(0.04);}
	//hs->GetYaxis()->CenterTitle();

	hs->GetXaxis()->SetTitleOffset(1.2);
	if (!drawTwoPads){ hs->GetXaxis()->SetTitle(h_data->GetXaxis()->GetTitle());}
	hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );

	h_data->Draw("same");

	// h_data->Draw();
	// hs->Draw("hist same");
	// hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
	
	h_MC=(TH1F*)h_Wjets->Clone();
	h_MC->Add(h_Zjets);
	h_MC->Add(h_diboson);
	h_MC->Add(h_singleTop);
	h_MC->Add(h_ttbar);

	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      	TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
	leg->SetNColumns(2);
	leg->AddEntry(h_data,"Data","p");
	leg->AddEntry(h_Wjets,"W+jets","f");
	leg->AddEntry(h_Zjets,"Z+jets","f");
	leg->AddEntry(h_diboson,"Di-boson","f");
	leg->AddEntry(h_singleTop,"single top","f");
	leg->AddEntry(h_ttbar,"ttbar","f");

	//leg->Paint("NB");
	leg->Draw();
	
	
	TLatex l;
	l.SetTextSize(0.04); 
	l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	l.SetTextColor(1); //black
	l.DrawLatex(0.15 , 0.84,"ATLAS #bf{Internal}");
	l.DrawLatex(0.15 , 0.76,"#int Ldt = 20.3 fb^{-1}");
	TString latexFlav("");
	if (flavorName[iflav] == "ep") { latexFlav = "e^{+}";}
	else if (flavorName[iflav] == "em") { latexFlav = "e^{-}";}
	else if (flavorName[iflav] == "mp") {  latexFlav = "#mu^{+}";}
	else if (flavorName[iflav] == "mm") {  latexFlav = "#mu^{-}";}
	//l.DrawLatex(0.15 , 0.68,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(),cutName[icut].Data() ) );
	l.DrawLatex(0.15 , 0.68,Form("#bf{ W#rightarrow %s#nu }", latexFlav.Data() ) );



      

	if (drawTwoPads){

	  double xstart=h_data->GetBinLowEdge(1);
	  double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);
	  
	  p2->cd();
	  //p2->SetLogx(1); 
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist = (TH1F*)h_data->Clone();
	  ratioHist->Divide(h_MC);
	  ratioHist->GetYaxis()->SetRangeUser(0.3, 1.9);
	  ratioHist->GetYaxis()->SetLabelSize(0.1);
	  ratioHist->GetXaxis()->SetTitleSize(0.1);
	  ratioHist->GetXaxis()->SetLabelSize(0.1);
	  ratioHist->Draw();
	  ratioHist->SetTitle("");
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);

	} //drawTwoPads  
      
	c2->Print("plots_stack_noQCD.pdf",Form("Title:%s_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())); //&&&&
	//c2->Print(Form("EPS/stack_noQCD_%s_WBF_%s_%s.pdf",flavorName[iflav].Data(), cutName[icut].Data(), typeName[itype].Data() ));

	if (drawTwoPads){
	  p1->Clear();
	  p2->Clear();
	  
	  c2->cd();
	} //drawTwoPads


	
	delete hs;
      }
    }
  }
      
  f->Close();
  //f2->Close();
  c2->Print("plots_stack_noQCD.pdf]","pdf"); //&&&&
}
