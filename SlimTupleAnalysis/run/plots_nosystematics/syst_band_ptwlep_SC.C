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
#include "getHighestDeviationForSyst.h"

void syst_band_ptwlep_SC(){ //SC == separate charge
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>
  

  //const int nsyst =20;
  const int nsyst =31;
  //const int nsyst =1;  
  TH1F *h_data_ori,*h_Wjets_ori,*h_WjetsScaled_ori,*h_WjetsEWK_ori,*h_Zjets_ori,*h_diboson_ori,*h_singleTop_ori, *h_ttbar_ori, *h_qcd_ori, *h_MC_ori, *h_MCN_ori;
  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_WjetsEWK,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.
  
  TH1F *h_WjetsS_ori[nsyst],*h_WjetsEWKS_ori[nsyst],*h_ZjetsS_ori[nsyst],*h_dibosonS_ori[nsyst],*h_singleTopS_ori[nsyst], *h_ttbarS_ori[nsyst], *h_qcdS_ori[nsyst], *h_MCS_ori[nsyst]; 
  TH1F *h_WjetsS[nsyst],*h_WjetsEWKS[nsyst],*h_ZjetsS[nsyst],*h_dibosonS[nsyst],*h_singleTopS[nsyst], *h_ttbarS[nsyst], *h_qcdS[nsyst], *h_MCS[nsyst]; //h_MCS  are sum of systematic MC samples
  
  TH1F *h_ttbarMCatNLO, *h_ttbarPowHer, *h_ttbarAcerMCUp, *h_ttbarAcerMCDown;
  TH1F *h_Wjetsnom, *h_Wjetsfac, *h_Wjetsrenorm, *h_Wjetsckkw;  

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print("plots_syst_band.pdf["); //&&&&

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv4_looseBadMuon1.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7_looseBadLep4.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.41.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK_WjetsSF0.82.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_separateWjetsEWK.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutAwv.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutBosonCen.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutCosThStar.root");
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_ptwlep0.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_MjjTag200.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass.root");
  
  TFile *fsyst [nsyst]; //hard coded
  TFile *fsystPow [nsyst];
  //TString systname[nsyst]={"bJESUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"};
  
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp"};
  for (int isyst=0;isyst<nsyst;isyst++){ 
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf3.lv4/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_separateWjetsEWK_bugfixed/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_smw/hwwlvqq.%s.root",systname[isyst].Data()));

    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutAwv/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutBosonCen/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutCosThetaStar/hwwlvqq.%s.root",systname[isyst].Data()));
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutPtwlep/hwwlvqq.%s.root",systname[isyst].Data()));

    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0/hwwlvqq.%s.root",systname[isyst].Data()));
  }

  //TFile* fsyst_ttbar =TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_ttbar.root");
  //TFile* fsyst_wjets =TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.WjetsTruthSyst.root");
				  
  //const int nCut=1;TString cutName[nCut]={"CR_Top"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  //const int nCut=3;TString cutName[nCut]={"CR_Top","CR_TopFJ","CR_TopfatOnly"};
  //const int nCut=4;TString cutName[nCut]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  //const int nCut=6;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  
  //const int nFlavor =2; TString flavorName[nFlavor] = { "mp","mm"};
  const int nFlavor =4; TString flavorName[nFlavor] = { "em","ep","mm","mp"};
  

 
  const int nType=1;TString typeName[nType]={"ptwlep"};
  
  
  //const int nType=4;TString typeName[nType]={"bosonCentrality","cosThetaWDecay","VVptBalance","mjjTagged"};

  //const int nType=5;TString typeName[nType]={"MET_et","mjjTagged","Mwjj","mTWV","ptwlep"}
  //const int nType=27;TString typeName[nType]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVptBalance","VVvecptdiff"};
  
  //const int nType=14;TString typeName[nType]={"lep_pt","MET_et","mT","Mwjj","mjjTagged","ptwlep","ptwjj","Mlvjj","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVptBalance"};
  //const int nType=9;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep","MET_et","mT"}; //&&&& these are the ones needed for the note
  //const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"}; //&&&& these are the ones needed for the note
 
 
  
  for (int icut=0;icut<nCut;++icut){
    for (int itype=0;itype<nType;++itype){
      
      for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){

	if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	
	THStack *hs = new THStack("hs","");

	bool logy=false;
	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
	  logy = true;
	}

	//<<<< From fakeEstimation root file >>>>
   
	h_data_ori=(TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	h_Wjets_ori=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	h_WjetsEWK_ori=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));


	h_WjetsScaled_ori=(TH1F*)f->Get(Form("H_WjetsScaled_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

      
	h_Zjets_ori=(TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	
	h_diboson_ori=(TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	h_singleTop_ori=(TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	h_ttbar_ori=(TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	h_qcd_ori=(TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	

	///*
	///HARD CODING VARIABLE BINS  &&&&
	Double_t bins_ptwlep[11]= {0.,50.,100.,150.,200.,250.,300.,400.,600.,800.,1000.};
	
	
	//if ( typeName[itype].Contains("ptwlep") ){
	h_data = (TH1F*) h_data_ori-> Rebin(10, "h_data", bins_ptwlep);
	h_Wjets = (TH1F*)  h_Wjets_ori-> Rebin(10, "h_Wjets", bins_ptwlep);
	h_WjetsEWK = (TH1F*)  h_WjetsEWK_ori-> Rebin(10, "h_WjetsEWK", bins_ptwlep);
	h_WjetsScaled = (TH1F*)  h_WjetsScaled_ori-> Rebin(10, "h_WjetsScaled", bins_ptwlep);
	h_Zjets = (TH1F*)  h_Zjets_ori-> Rebin(10, "h_Zjets", bins_ptwlep);
	h_diboson = (TH1F*)  h_diboson_ori-> Rebin(10, "h_diboson", bins_ptwlep);
	h_singleTop = (TH1F*)  h_singleTop_ori-> Rebin(10, "h_singleTop", bins_ptwlep);
	h_ttbar = (TH1F*)  h_ttbar_ori-> Rebin(10, "h_ttbar", bins_ptwlep);
	h_qcd = (TH1F*)  h_qcd_ori-> Rebin(10, "h_qcd", bins_ptwlep);
	//}
	//*/
	
	
	/*
	////ttbar systematics
	h_ttbarMCatNLO=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarMCatNLO_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarPowHer=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarPowHer_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarAcerMCUp=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCUp_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarAcerMCDown=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCDown_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	 */

	 /*
	////W+jets systematics (only electron is available)
	h_Wjetsnom  = (TH1F*)fsyst_wjets->Get(Form("H_Wjets_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsfac  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsrenorm  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsckkw  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()) ) ;
	 */
	/*
	//positron flavor used everywhere &&&&
	h_Wjetsnom  = (TH1F*)fsyst_wjets->Get(Form("H_Wjets_ep_WBF_%s_%s",   cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsfac  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_ep_WBF_%s_%s",   cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsrenorm  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_ep_WBF_%s_%s",  cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsckkw  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_ep_WBF_%s_%s",   cutName[icut].Data(),typeName[itype].Data()) ) ;
	*/
	
	//<<<< From systematics root file >>>>

	for (int i=0;i<nsyst;i++){
	  h_WjetsS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_WjetsEWKS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_WjetsEWKSherpa_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  

	  h_ZjetsS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	  h_dibosonS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	  h_singleTopS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

	  h_ttbarS_ori[i]=(TH1F*)fsyst[i]->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));


	  h_WjetsS[i] = (TH1F*)  h_WjetsS_ori[i]-> Rebin(10, "h_Wjets", bins_ptwlep);
	  h_WjetsEWKS[i] = (TH1F*)  h_WjetsEWKS_ori[i]-> Rebin(10, "h_WjetsEWK", bins_ptwlep);
	  h_ZjetsS[i] = (TH1F*)  h_ZjetsS_ori[i]-> Rebin(10, "h_Zjets", bins_ptwlep);
	  h_dibosonS[i] = (TH1F*)  h_dibosonS_ori[i]-> Rebin(10, "h_diboson", bins_ptwlep);
	  h_singleTopS[i] = (TH1F*)  h_singleTopS_ori[i]-> Rebin(10, "h_singleTop", bins_ptwlep);
	  h_ttbarS[i] = (TH1F*)  h_ttbarS_ori[i]-> Rebin(10, "h_ttbar", bins_ptwlep);
	
	}

	
	/////
          

	h_data->SetLineColor(kBlack);
	h_Wjets->SetFillColor(kCyan);
	h_WjetsEWK->SetFillColor(kRed);
	h_WjetsScaled->SetFillColor(kCyan);
	h_Zjets->SetFillColor(kBlue);
	h_diboson->SetFillColor(kMagenta+2);
	h_singleTop->SetFillColor(kYellow-5);
	h_ttbar->SetFillColor(kYellow);
	h_qcd->SetFillColor(kGreen-8);

	///Overflow bin

	AddOverflowBinToLastBin(h_data);
	AddOverflowBinToLastBin(h_Wjets);
	AddOverflowBinToLastBin(h_WjetsEWK);
	AddOverflowBinToLastBin(h_WjetsScaled);
	AddOverflowBinToLastBin(h_Zjets);
	AddOverflowBinToLastBin(h_diboson);
	AddOverflowBinToLastBin(h_singleTop);
	AddOverflowBinToLastBin(h_ttbar);
	AddOverflowBinToLastBin(h_qcd);

	/*
	int rebin=1;
      	int rebinFac =1;

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
	*/
	// /*
	doVariableBinHisto(h_data);
	doVariableBinHisto(h_Wjets);
	doVariableBinHisto(h_WjetsEWK);
	doVariableBinHisto(h_WjetsScaled);
	doVariableBinHisto(h_Zjets);
	doVariableBinHisto(h_diboson);
	doVariableBinHisto(h_singleTop);
	doVariableBinHisto(h_ttbar);
	doVariableBinHisto(h_qcd);

	for (int i=0;i<nsyst;i++){

	  AddOverflowBinToLastBin(h_WjetsS[i]);
	  AddOverflowBinToLastBin(h_WjetsEWKS[i]);
	  AddOverflowBinToLastBin(h_ZjetsS[i]);
	  AddOverflowBinToLastBin(h_dibosonS[i]);
	  AddOverflowBinToLastBin(h_singleTopS[i]);
	  AddOverflowBinToLastBin(h_ttbarS[i]);
	  
	  doVariableBinHisto(h_WjetsS[i]);
	  doVariableBinHisto(h_WjetsEWKS[i]);
	  doVariableBinHisto(h_ZjetsS[i]);
	  doVariableBinHisto(h_dibosonS[i]);
	  doVariableBinHisto(h_singleTopS[i]);
	  doVariableBinHisto(h_ttbarS[i]);
	}
	//  */
	

	hs->Add(h_diboson);
	hs->Add(h_Zjets);	
	//hs->Add(h_Wjets);
	//hs->Add(h_WjetsEWK);
	h_WjetsScaled->Add(h_WjetsEWK); //&&&& W+jets EWL is not plotted separately
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
	p2->SetBottomMargin(0.31);
	p2->SetRightMargin(0.12);
	
	p1->cd();
	///// pad1

	p1->cd()->SetLogy(logy); 
	
	// hs->SetMaximum(hs->GetMaximum()*1.5);
	// if (logy)hs->SetMaximum(hs->GetMaximum()*200.);
	// //hs->SetMinimum(1);
	// hs->SetMinimum(1.e-3);
	
	 hs->Draw("hist");
    

	//hs->SetTitle(Form("%s_%s_%s",flavorName[iFlavor].Data(),cutName[icut].Data(), typeName[itype].Data()) );
	std::cout<<Form("%s_%s_%s", flavorName[iFlavor].Data(),cutName[icut].Data(), typeName[itype].Data())<<endl;
      
	hs->SetTitle("");
	//hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
	if (h_data->GetBinWidth(1)== h_data->GetBinWidth(h_data->GetNbinsX())){
	  if (h_data->GetBinWidth(1)<0.1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.2f", h_data->GetBinWidth(1)  )  );
	  else hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f", h_data->GetBinWidth(1)  )  );
	}else{
	  hs-> GetYaxis()->SetTitle(  "Entries / GeV"  );
	}
	
	//cout<<hs-> GetYaxis()->GetTitleSize();
	// hs-> GetYaxis()->SetLabelSize(0.05);
	// hs-> GetYaxis()->SetTitleOffset(1);
	
	// h_data->SetMarkerStyle(20);
	// h_data->SetMarkerSize(1);
	
	setStackStyle (hs);

	h_data->SetMarkerStyle(20);
	h_data->SetMarkerSize(1);

	//h_MC is used to get data/MC ratio
	
	//h_MC=(TH1F*)h_Wjets->Clone();
	h_MC=(TH1F*)h_WjetsScaled->Clone();
	//h_MC->Add(h_WjetsEWK); //&&&& already added in h_WjetsScaled
	h_MC->Add(h_Zjets);
	h_MC->Add(h_diboson);
	h_MC->Add(h_singleTop);
	h_MC->Add(h_ttbar);
	h_MC->Add(h_qcd); //For data-MC comparison, add QCD. For systematic band h_MC should not include QCD, we define a new histo called h_MCN for that purpose.
	
	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// std::cout<<"KolmogorovTest result= "<<ks<<endl;
	
	
	// if ( typeName[itype].Contains("Mwjj") ){
	//   if ( cutName[icut]=="CR_Top" || cutName[icut]=="SR"){
	//     h_data->GetXaxis()->SetRangeUser(75,95);
	//     hs->GetXaxis()->SetRangeUser(75,95);
	//   }else if (  cutName[icut]=="CR_TopFJ" || cutName[icut]=="SRFJ"  || cutName[icut]=="CR_TopfatOnly" || cutName[icut]=="SRfatOnly"){
	//     h_data->GetXaxis()->SetRangeUser(60,110);
	//     hs->GetXaxis()->SetRangeUser(60,110);
	//   }
	// }

	// double xstart=h_data->GetBinLowEdge(1);
	// double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);

	float xstart(0.), xend(10.);

	GetXaxisRange(h_MC   , xstart  , xend    );

	//cout<<"xstart = "<<xstart<<endl;
	//cout<<"xend = "<<xend<<endl;
	
	h_data->GetXaxis()->SetRangeUser(xstart,xend);
	hs->GetXaxis()->SetRangeUser(xstart,xend);

	double maxi = hs->GetMaximum();
	double tmp = h_data->GetBinContent(h_data->GetMaximumBin());
	if (maxi < tmp) maxi =tmp;
	
	hs->SetMaximum(maxi *1.7);
	if (logy)hs->SetMaximum( maxi *200.);
	//hs->SetMinimum(1);
	hs->SetMinimum(1.e-3);
	
	hs->Draw("hist");

	h_data->Draw("same");


      	
 
      
	TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	leg->SetNColumns(2);
      
	leg->AddEntry(h_data,"Data","p");
	//leg->AddEntry(h_Wjets,"W+jets","f");
	leg->AddEntry(h_WjetsScaled,"W+jets","f");
	//leg->AddEntry(h_WjetsEWK,"W+jets EWK","f"); //&&&&
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
	// if (lepName=="electron"){
	//   l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow e#nu , %s}", cutName[icut].Data() ) );
	// }else if (lepName=="muon"){
	//   l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow #mu#nu , %s}", cutName[icut].Data() ) );
	// }
	TString latexFlav("");
	if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
	else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
	else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
	else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
	
	l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), cutName[icut].Data()) );
      
	// double xstart=h_data->GetBinLowEdge(1);
	// double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);

	// //range of horizontal line
	// if ( typeName[itype].Contains("Mwjj") ){
	//   if ( cutName[icut]=="CR_Top" || cutName[icut]=="SR"){
	//     xstart = 75.; xend =95.; //hard coded
	//   }else if (  cutName[icut]=="CR_TopFJ" || cutName[icut]=="SRFJ"  || cutName[icut]=="CR_TopfatOnly" || cutName[icut]=="SRfatOnly"){
	//     xstart = 60.; xend =110.; //hard coded
	//   }
	// }


	


      
	  
	p2->cd();
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h_data->Clone();
	ratioHist->Divide(h_MC);

	// ratioHist->SetMaximum(2.);
	// ratioHist->GetYaxis()->SetRangeUser(0.3, 1.9);
	//ratioHist->GetYaxis()->SetRangeUser(0., 2.);
      
      
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
	ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
	//ratioHist->GetYaxis()->SetRangeUser(0.5, 1.5);
	
	//ratioHist->Draw();
      
	TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	horiz_line->SetLineStyle(2);
	//horiz_line->DrawLine(xstart,1.0,xend,1.0);

	////<<<<<<<<<< systematics band >>>>>>>>>>>>>

	h_MCN =(TH1F*)h_MC->Clone();
	h_MCN ->Add(h_qcd,-1);
	/// <<<< use unscaled W+jets for systematic bands because in systematic samples the W+jets is unscaled >>>>
	h_MCN ->Add(h_WjetsScaled,-1);  //&&&&
	h_MCN ->Add(h_WjetsEWK);  //&&&& h_WjetsScaled contained h_WjetsEWK, so need to add it back
	h_MCN ->Add(h_Wjets);

	for (int i=0;i<nsyst;i++){ 
	  h_MCS[i]=(TH1F*)h_WjetsS[i]->Clone();
	  h_MCS[i]->SetName(Form("%s_%s", h_WjetsS[i]->GetName(),systname[i].Data()));
	  h_MCS[i]->Add(h_WjetsEWKS[i]);
	  h_MCS[i]->Add(h_ZjetsS[i]);
	  h_MCS[i]->Add(h_dibosonS[i]);
	  h_MCS[i]->Add(h_singleTopS[i]);
	  h_MCS[i]->Add(h_ttbarS[i]);

	  //if ( typeName[itype].Contains("mTWV") )getHighestDeviationForSyst(h_MCN,h_MCS[i]);
	}

	
      
	TH1F* hSystBandHi = (TH1F*)ratioHist->Clone("hdataMCratio");
	//TH1D* hSystBandLo = (TH1D*)ratioHist->Clone("hdataMCratio");

	hSystBandHi->SetMinimum(0.0);
	 hSystBandHi->SetMaximum(2.5);
	//hSystBandHi->SetMinimum(0.5);
	// hSystBandHi->SetMaximum(1.5);
	hSystBandHi->SetTitle("");
	hSystBandHi->GetYaxis()->SetTitle("Data/SM");
	hSystBandHi->GetYaxis()->SetTitleSize(0.16);
	hSystBandHi->GetYaxis()->SetTitleOffset(0.3);
	hSystBandHi->GetYaxis()->SetLabelSize(0.1);

	//hSystBandHi -> GetXaxis()->SetTitle("m(J) [GeV]");  //&&&&

	hSystBandHi->GetXaxis()->SetTitleSize(0.16);
	hSystBandHi->GetXaxis()->SetTitleOffset(1.0);
	hSystBandHi->GetXaxis()->SetLabelSize(0.12);

	int nbins = hSystBandHi->GetNbinsX();
	for (int ibin =1;ibin<=nbins;ibin++){
	  double fracErr = 0;
	  for (int i=0;i<nsyst;i++){ 
	    if (h_MCN->GetBinContent(ibin)!=0){
	      fracErr+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    }
	  }
	  //fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsfac->GetBinContent(ibin))/h_Wjetsnom->GetBinContent(ibin),2);
	  //fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsrenorm->GetBinContent(ibin))/h_Wjetsnom->GetBinContent(ibin),2);
	  //fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsckkw->GetBinContent(ibin))/h_Wjetsnom->GetBinContent(ibin),2);

	  //fracErr+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarMCatNLO->GetBinContent(ibin))/h_ttbar->GetBinContent(ibin),2);
	  //fracErr+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarPowHer->GetBinContent(ibin))/h_ttbar->GetBinContent(ibin),2);
	  //fracErr+=pow((h_ttbarAcerMCUp->GetBinContent(ibin)-h_ttbarAcerMCDown->GetBinContent(ibin))/(2*h_ttbarAcerMCUp->GetBinContent(ibin)),2);
	  
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
	//hSystBandHi->Draw("e2 same");
	//   hSystBandLo->Draw("same");

	hSystBandHi->Draw("e2");
	ratioHist->Draw("same"); //
	//ratioHist->Draw(); //&&&& no systematics band
	horiz_line->DrawLine(xstart,1.0,xend,1.0);
  
      
	c2->Print("plots_syst_band.pdf",Form("Title:%s_%s_%s",flavorName[iFlavor].Data(),cutName[icut].Data(), typeName[itype].Data()));
	//c2->Print(Form("PDF_syst_band/%s_%s_%s.pdf",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()) );
      
	p1->Clear();
	p2->Clear();
      
	c2->cd();
	delete hs;
      }
    }
  }
  
  f->Close();


  for (int isyst=0;isyst<nsyst;isyst++){ 
    fsyst[isyst]->Close();
  }
  
   
  c2->Print("plots_syst_band.pdf]");
}

