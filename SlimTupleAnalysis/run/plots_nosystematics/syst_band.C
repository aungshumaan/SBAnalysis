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


void syst_band(){ //electron and positron (muon and anti-muon) merged

  //gROOT->LoadMacro("atlasstyle-00-03-05/AtlasStyle.C");
  //SetAtlasStyle();
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>
  
  //bool doEl=true; //electron plots
  bool doEl=false;//muon plots
  
  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}

  const int nsyst =20;  
  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.
  TH1F *h_WjetsS[nsyst],*h_ZjetsS[nsyst],*h_dibosonS[nsyst],*h_singleTopS[nsyst], *h_ttbarS[nsyst], *h_MCS[nsyst]; //h_MCS  are sum of systematic MC samples

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print(Form("plots_syst_band_%s.pdf[",lepName.Data() )); //&&&&

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.41.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4_smw_mlj_NEWcutflow.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4_smw_NEWcutflow.root");
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv4_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv7_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.scaled_variableBin.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.5.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.scaled_variableBin.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.WjetsScaled.root");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_WjetsSF0.82.root");
  
  TFile *fsyst [nsyst]; 
  //TFile *fsystPow [nsyst]; //Systematic files with Powheg W+jets

  //TString systname[nsyst]={"bJESUp"};
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"};

  for (int isyst=0;isyst<nsyst;isyst++){ 
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4/hwwlvqq.%s.4.root",systname[isyst].Data()));
    ////fsystPow[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.5/hwwlvqq.%s.PowhegWjetsOnly.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4.2/hwwlvqq.%s.4.2_variableBin.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf3.lv4_test/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4.4/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4.41/hwwlvqq.%s.root",systname[isyst].Data()));
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.%s.root",systname[isyst].Data()));
	
  }
  

  //const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};    
  const int nCut=6;TString cutName[nCut]={"CR_Wjj","CR_WjjfatOnly","CR_Top","CR_TopfatOnly","SR","SRfatOnly"};
  //const int nCut=4;TString cutName[nCut]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  //const int nCut=6;TString cutName[nCut]={"CR_Top","CR_TopFJ","CR_Wjj","CR_WjjFJ","SR","SRfatOnly"};
  //const int nCut=2;TString cutName[nCut]={ "CR_Wjj","SR"};
  //const int nCut=3;TString cutName[nCut]={ "CR_Top","CR_Wjj","SR"};

  const int nType=1;TString typeName[nType]={"mTWV"};
  //const int nType=6;TString typeName[nType]={"mjjTagged","Mwjj","Njet","ptwlep","ptwjj","Mlvjj"};
  //const int nType=7;TString typeName[nType]={"dEtaTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  //const int nType=2;TString typeName[nType]={"mjjTagged","mTWV"};
  //const int nType=27;TString typeName[nType]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVptBalance","VVvecptdiff"};
  
  //const int nType=14;TString typeName[nType]={"lep_pt","MET_et","mT","Mwjj","mjjTagged","ptwlep","ptwjj","Mlvjj","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVptBalance"};
  //const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};
  
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

      h_WjetsScaled=(TH1F*)f->Get(Form("H_WjetsScaled_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WjetsScaled->Add((TH1F*)f->Get(Form("H_WjetsScaled_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
      
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


      //<<<< From systematics root file >>>>

      for (int i=0;i<nsyst;i++){
	h_WjetsS[i]=(TH1F*)fsyst[i]->Get(Form("H_Wjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_WjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Wjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	//h_WjetsS[i]=(TH1F*)fsystPow[i]->Get(Form("H_Wjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	//h_WjetsS[i]->Add((TH1F*)fsystPow[i]->Get(Form("H_Wjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	
	h_ZjetsS[i]=(TH1F*)fsyst[i]->Get(Form("H_Zjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ZjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Zjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	h_dibosonS[i]=(TH1F*)fsyst[i]->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_dibosonS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	h_singleTopS[i]=(TH1F*)fsyst[i]->Get(Form("H_SingleTop_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_singleTopS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_SingleTop_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	h_ttbarS[i]=(TH1F*)fsyst[i]->Get(Form("H_Ttbar_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Ttbar_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())),s);
	
      }
     
      /////
          

      h_data->SetLineColor(kBlack);
      //h_Wjets->SetFillColor(kCyan);
      h_WjetsScaled->SetFillColor(kCyan);
      h_Zjets->SetFillColor(kBlue);
      h_diboson->SetFillColor(kMagenta+2);
      h_singleTop->SetFillColor(kYellow-5);
      h_ttbar->SetFillColor(kYellow);
      h_qcd->SetFillColor(kGreen-8);

      ///Overflow bin
  
      AddOverflowBinToLastBin(h_data);
      AddOverflowBinToLastBin(h_WjetsScaled);
      AddOverflowBinToLastBin(h_Zjets);
      AddOverflowBinToLastBin(h_diboson);
      AddOverflowBinToLastBin(h_singleTop);
      AddOverflowBinToLastBin(h_ttbar);
      AddOverflowBinToLastBin(h_qcd);
      
      
      int rebin=1;

      int rebinFac =1;
      
      //if (typeName[itype].Contains("mTWV") || typeName[itype].Contains("VVvecptdiff")){rebin=2;}
      // if (typeName[itype].Contains("mTWV") || typeName[itype].Contains("bosonCentrality") || typeName[itype].Contains("lepCentrality") || typeName[itype].Contains("VVptBalance") || typeName[itype].Contains("VVvecptdiff")){rebin=4;}

      
      
      
      rebinFac = getRebinFactor(typeName[itype]);
      rebin *=rebinFac;
	
      h_data->Rebin(rebin);
      h_Wjets->Rebin(rebin);
      h_WjetsScaled->Rebin(rebin);
      h_Zjets->Rebin(rebin);
      h_diboson->Rebin(rebin);
      h_singleTop->Rebin(rebin);
      h_ttbar->Rebin(rebin);
      h_qcd->Rebin(rebin);
      for (int i=0;i<nsyst;i++){
	h_WjetsS[i]->Rebin(rebin);
	h_ZjetsS[i]->Rebin(rebin);
	h_dibosonS[i]->Rebin(rebin);
	h_singleTopS[i]->Rebin(rebin);
	h_ttbarS[i]->Rebin(rebin);
      }
   

      // /*
      doVariableBinHisto(h_data);
      doVariableBinHisto(h_Wjets);
      doVariableBinHisto(h_WjetsScaled);
      doVariableBinHisto(h_Zjets);
      doVariableBinHisto(h_diboson);
      doVariableBinHisto(h_singleTop);
      doVariableBinHisto(h_ttbar);
      doVariableBinHisto(h_qcd);

      for (int i=0;i<nsyst;i++){
	doVariableBinHisto(h_WjetsS[i]);
	doVariableBinHisto(h_ZjetsS[i]);
	doVariableBinHisto(h_dibosonS[i]);
	doVariableBinHisto(h_singleTopS[i]);
	doVariableBinHisto(h_ttbarS[i]);
      }
      //  */
      

      hs->Add(h_diboson);
      hs->Add(h_Zjets);	
      //hs->Add(h_Wjets);
      hs->Add(h_WjetsScaled);
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
      
      
	
      //h_data->GetYaxis()->SetLabelSize(0.1);
      //h_data->GetYaxis()->SetTitleSize(0.1);
      //h_data->GetYaxis()->SetLabelSize(0.3);
      ////h_data->GetYaxis()->SetTitleSize(0.3);
      ////h_data->GetYaxis()->SetTitleOffset(0.7);
      //h_data->GetYaxis()->CenterTitle();
      //h_data->GetYaxis()->SetTitle("Data/SM");
	
      //h_data->GetXaxis()->SetLabelSize(0.1);
      //h_data->GetXaxis()->SetTitleSize(0.1);
      ////h_data->GetXaxis()->SetTitleSize(0.3);
      //h_data->GetXaxis()->SetTitleOffset(1.2);
      //h_data-> GetXaxis()->SetTitle( "" );
     

  
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


      	
      //h_MC=(TH1F*)h_Wjets->Clone();
      h_MC=(TH1F*)h_WjetsScaled->Clone();
      h_MC->Add(h_Zjets);
      h_MC->Add(h_diboson);
      h_MC->Add(h_singleTop);
      h_MC->Add(h_ttbar);
      h_MC->Add(h_qcd); //For data-MC comparison, add QCD. For systematic band h_MC should not include QCD, we define a new histo called h_MCN for that purpose.
      
      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // std::cout<<"KolmogorovTest result= "<<ks<<endl;

 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
      leg->SetNColumns(2);
      
      leg->AddEntry(h_data,"Data","p");
      //leg->AddEntry(h_Wjets,"W+jets","f");
      leg->AddEntry(h_WjetsScaled,"W+jets","f");
      leg->AddEntry(h_Zjets,"Z+jets","f");
      leg->AddEntry(h_diboson,"Di-boson","f");
      leg->AddEntry(h_singleTop,"single top","f");
      leg->AddEntry(h_ttbar,"ttbar","f");
      leg->AddEntry(h_qcd,"QCD","f");
      


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
      
      
      // ratioHist->SetMaximum(2.);
      //ratioHist->GetYaxis()->SetRangeUser(0.3, 1.9);
      
      // //ratioHist->GetYaxis()->SetRangeUser(0., 2.);
      
      
      // ratioHist->SetTitle("");

      // ratioHist->GetYaxis()->SetTitle("Data/SM");
      // //std::cout<<"ratioHist XaxisName = "<<ratioHist->GetXaxis()->GetTitle()<<endl;
      // //std::cout<<"ratioHist YaxisName = "<<ratioHist->GetYaxis()->GetTitle()<<endl;
      
      // ratioHist->GetYaxis()->SetLabelSize(0.1);
      // ratioHist->GetYaxis()->SetTitleSize(0.08);
      // //ratioHist->GetYaxis()->SetLabelSize(0.3);
      // //ratioHist->GetYaxis()->SetTitleSize(0.3);
      // ratioHist->GetYaxis()->SetTitleOffset(0.5);
      // ratioHist->GetYaxis()->CenterTitle();
	
      // ratioHist->GetXaxis()->SetLabelSize(0.1);
      // //ratioHist->GetXaxis()->SetTitleSize(0.1);
      // ratioHist->GetXaxis()->SetTitleSize(0.15); //when bottom margin of pad is set to 0.3
      // //ratioHist->GetXaxis()->SetTitleOffset(1.2);

      setRatioPlotStyle (ratioHist);
      ratioHist->GetYaxis()->SetRangeUser(0., 2.9);

      // ratioHist->Draw();
      
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      //horiz_line->DrawLine(xstart,1.0,xend,1.0);

      ////<<<<<<<<<< systematics band >>>>>>>>>>>>>

      h_MCN =(TH1F*)h_MC->Clone();
      h_MCN ->Add(h_qcd,-1);
      /// <<<< use unscaled W+jets for systematic bands because in systematic samples the W+jets is unscaled >>>>
      h_MCN ->Add(h_WjetsScaled,-1); 
      h_MCN ->Add(h_Wjets);

      for (int i=0;i<nsyst;i++){ 
	h_MCS[i]=(TH1F*)h_WjetsS[i]->Clone();
	h_MCS[i]->Add(h_ZjetsS[i]);
	h_MCS[i]->Add(h_dibosonS[i]);
	h_MCS[i]->Add(h_singleTopS[i]);
	h_MCS[i]->Add(h_ttbarS[i]);
      }
       
      
      TH1F* hSystBandHi = (TH1F*)ratioHist->Clone("hdataMCratio");
      //TH1D* hSystBandLo = (TH1D*)ratioHist->Clone("hdataMCratio");

      //hSystBandHi->SetMinimum(0.0);
      //hSystBandHi->SetMaximum(3.5);
      ////hSystBandHi->SetMaximum(5.);
       
   

      int nbins = hSystBandHi->GetNbinsX();
      for (int ibin =1;ibin<=nbins;ibin++){
	double fracErr = 0;
	for (int i=0;i<nsyst;i++){ //hard coded
	  if (h_MCN->GetBinContent(ibin)!=0){
	    fracErr+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	  }
	}
	fracErr =sqrt(fracErr);
	hSystBandHi->SetBinContent(ibin, 1);
	hSystBandHi->SetBinError(ibin, fracErr);
      }

      gStyle->SetHatchesLineWidth(1);
      gStyle->SetHatchesSpacing(0.8);
      hSystBandHi->SetFillStyle(3354);
      hSystBandHi->SetFillColor(kRed);
      hSystBandHi->SetLineColor(0);
      
      hSystBandHi->SetMarkerSize(0);
      // hSystBandHi->Draw("e2 same");
      //   hSystBandLo->Draw("same");

      hSystBandHi->Draw("e2");
      ratioHist->Draw("same");
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


  for (int isyst=0;isyst<nsyst;isyst++){ 
    fsyst[isyst]->Close();
  }
  
   
  c2->Print(Form("plots_syst_band_%s.pdf]",lepName.Data() )); //&&&&
}



