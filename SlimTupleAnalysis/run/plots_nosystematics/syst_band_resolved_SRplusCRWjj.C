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
#include "addLastBinsTo1TeVbin.h"

void syst_band_resolved_SRplusCRWjj(){ 
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>
  

 
  const int nsyst =31;

  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_WjetsEWK, *h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd,*h_sigSM, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.
  TH1F *h_WjetsS[nsyst],*h_WjetsEWKS[nsyst], *h_ZjetsS[nsyst],*h_dibosonS[nsyst],*h_singleTopS[nsyst], *h_ttbarS[nsyst], *h_qcdS[nsyst],*h_sigSMS[nsyst], *h_MCS[nsyst]; //h_MCS  are sum of systematic MC samples
  TH1F *h_ttbarMCatNLO, *h_ttbarPowHer, *h_ttbarAcerMCUp, *h_ttbarAcerMCDown;
  TH1F *h_Wjetsnom, *h_Wjetsfac, *h_Wjetsrenorm, *h_Wjetsckkw;  

  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  bool pdfforNote = 1;
  if (!pdfforNote)c2->Print("plots_syst_band_resolved.pdf["); 

  

  ////Data and bkg
 
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_fmw40_140.root");
  
  TFile *fsyst [nsyst]; //hard coded
  TFile *fsystPow [nsyst];
 
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp"};
 
  for (int isyst=0;isyst<nsyst;isyst++)
    { 
       fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_fmw40_140/hwwlvqq.%s.root",systname[isyst].Data()));
    }

 

  TFile* fsyst_ttbar =TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_fmw40_140/hwwlvqq.ttbar.root");
  TFile* fsyst_wjets =TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_fmw40_140/hwwlvqq.WjetsTruthSyst.root");
  
  

  const int nFlavor =2; TString flavorName[nFlavor] = { "p", "m"};  //positive and negative
  
   
  //const int nType=1;TString typeName[nType]={"VVptBalance"};
  //const int nType=1;TString typeName[nType]={"bosonCentrality"};
  //const int nType=1;TString typeName[nType]={"cosThetaWDecay"};
  //const int nType=1;TString typeName[nType]={"ptwlep"};
  //const int nType=1;TString typeName[nType]={"mjjTagged"};
  const int nType=1;TString typeName[nType]={"Mwjj"};

  //const int nType=1;TString typeName[nType]={"mTWV"};
  //const int nType=2;TString typeName[nType]={"Wjet1_eta","Wjet2_eta"};
  
  //const int nType=4;TString typeName[nType]={"bosonCentrality","cosThetaWDecay","VVptBalance","mjjTagged"};
  //const int nType=3;TString typeName[nType]={"Mwjj","MET_et","mTWV"};
  //const int nType=14;TString typeName[nType]={"lep_pt","MET_et","mT","Mwjj","mjjTagged","ptwlep","ptwjj","Mlvjj","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVptBalance"};
  //const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"}; //&&&& these are the ones needed for the note
 
 
  
 
  for (int itype=0;itype<nType;++itype){
      
    for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){

      //if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	
      THStack *hs = new THStack("hs","");

      bool logy=false;
      if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
	logy = true;
      }
      if (typeName[itype].Contains("mTWV") ) logy = true; //&&&&

      //<<<< From fakeEstimation root file >>>>

	
	
      h_data=(TH1F*)f->Get(Form("H_Data_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_data->Add((TH1F*)f->Get(Form("H_Data_m%s_WBF_SR_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_data->Add((TH1F*)f->Get(Form("H_Data_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_data->Add((TH1F*)f->Get(Form("H_Data_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));


      h_sigSM=(TH1F*)f->Get(Form("H_VBS_WV_0_0_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_m%s_WBF_SR_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_e%s_WBF_SR_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_m%s_WBF_SR_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(), typeName[itype].Data())));

	
	

      h_Wjets=(TH1F*)f->Get(Form("H_Wjets_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())); 
      h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()))); 
	

	
      h_WjetsScaled=(TH1F*)f->Get(Form("H_WjetsScaled_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_WjetsScaled->Add((TH1F*)f->Get(Form("H_WjetsScaled_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_WjetsScaled->Add((TH1F*)f->Get(Form("H_WjetsScaled_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_WjetsScaled->Add((TH1F*)f->Get(Form("H_WjetsScaled_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	
	

      h_WjetsEWK=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())); 
      h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()))); 
	
	
	
	
      h_Zjets=(TH1F*)f->Get(Form("H_Zjets_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	


      h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	


      h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	


      h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));



      h_qcd=(TH1F*)f->Get(Form("H_QCD_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
      h_qcd->Add((TH1F*)f->Get(Form("H_QCD_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_qcd->Add((TH1F*)f->Get(Form("H_QCD_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
      h_qcd->Add((TH1F*)f->Get(Form("H_QCD_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	
	
      // /*
      ////ttbar systematics
      h_ttbarMCatNLO=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarMCatNLO_e%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data()));
      h_ttbarMCatNLO->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarMCatNLO_m%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarMCatNLO->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarMCatNLO_e%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarMCatNLO->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarMCatNLO_m%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
	
	
      h_ttbarPowHer=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarPowHer_e%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data()));
      h_ttbarPowHer->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarPowHer_m%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarPowHer->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarPowHer_e%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarPowHer->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarPowHer_m%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));

	
      h_ttbarAcerMCUp=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCUp_e%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data()));
      h_ttbarAcerMCUp->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCUp_m%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarAcerMCUp->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCUp_e%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarAcerMCUp->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCUp_m%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
	

      h_ttbarAcerMCDown=(TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCDown_e%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data()));
      h_ttbarAcerMCDown->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCDown_m%s_WBF_SR_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarAcerMCDown->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCDown_e%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));
      h_ttbarAcerMCDown->Add ( (TH1F*)fsyst_ttbar->Get(Form("H_TtbarAcerMCDown_m%s_WBF_CR_Wjj_%s",flavorName[iFlavor].Data(), typeName[itype].Data())));

      // */

      //	 /*
      ////W+jets systematics (only electron is available) so use mp->ep, mm->em
      h_Wjetsnom  = (TH1F*)fsyst_wjets->Get(Form("H_Wjets_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) ;
      h_Wjetsnom  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_Wjets_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsnom  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_Wjets_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsnom  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_Wjets_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
	
	
      h_Wjetsfac  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) ;
      h_Wjetsfac  ->Add((TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data())) );
      h_Wjetsfac  ->Add((TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data())) );
      h_Wjetsfac  ->Add((TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsfac4_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data())) );
	
	
      h_Wjetsrenorm  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) ;
      h_Wjetsrenorm  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsrenorm  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsrenorm  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsrenorm4_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );

	
      h_Wjetsckkw  = (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) ;
      h_Wjetsckkw  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_e%s_WBF_SR_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsckkw  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
      h_Wjetsckkw  ->Add( (TH1F*)fsyst_wjets->Get(Form("H_TruthWjetsckkw30_e%s_WBF_CR_Wjj_%s",  flavorName[iFlavor].Data(), typeName[itype].Data()) ) );
	
	
      //	 */
	
	
	

      //<<<< From systematics root file >>>>

      for (int i=0;i<nsyst;i++){
	h_WjetsS[i]=(TH1F*)fsyst[i]->Get(Form("H_Wjets_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_WjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Wjets_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_WjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Wjets_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_WjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Wjets_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  

	h_WjetsEWKS[i]=(TH1F*)fsyst[i]->Get(Form("H_WjetsEWKSherpa_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_WjetsEWKS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WjetsEWKSherpa_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_WjetsEWKS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WjetsEWKSherpa_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_WjetsEWKS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WjetsEWKSherpa_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  
	  

	h_ZjetsS[i]=(TH1F*)fsyst[i]->Get(Form("H_Zjets_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_ZjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Zjets_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_ZjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Zjets_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_ZjetsS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Zjets_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  

	h_dibosonS[i]=(TH1F*)fsyst[i]->Get(Form("H_WZZZWg_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_dibosonS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WZZZWg_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_dibosonS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WZZZWg_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_dibosonS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_WZZZWg_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  
	  
	  
	h_singleTopS[i]=(TH1F*)fsyst[i]->Get(Form("H_SingleTop_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_singleTopS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_SingleTop_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_singleTopS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_SingleTop_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_singleTopS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_SingleTop_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  
	  
	  
	h_ttbarS[i]=(TH1F*)fsyst[i]->Get(Form("H_Ttbar_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_ttbarS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Ttbar_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_ttbarS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Ttbar_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_ttbarS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_Ttbar_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	
	h_sigSMS[i]=(TH1F*)fsyst[i]->Get(Form("H_VBS_WV_0_0_e%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data()));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_WV_0_0_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_WV_0_0_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_WV_0_0_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_ZV_0_0_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_ZV_0_0_m%s_WBF_SR_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_ZV_0_0_e%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	h_sigSMS[i]->Add((TH1F*)fsyst[i]->Get(Form("H_VBS_ZV_0_0_m%s_WBF_CR_Wjj_%s", flavorName[iFlavor].Data(),  typeName[itype].Data())));
	  

      }
     
      /////
          

      h_data->SetLineColor(kBlack);
      h_Wjets->SetFillColor(kCyan);
      h_WjetsScaled->SetFillColor(kCyan);
      h_WjetsEWK->SetFillColor(kRed);
      h_Zjets->SetFillColor(kBlue);
      h_diboson->SetFillColor(kMagenta+2);
      h_singleTop->SetFillColor(kYellow-5);
      h_ttbar->SetFillColor(kYellow);
      h_qcd->SetFillColor(kGreen-8);
      h_sigSM->SetFillColor(kRed);

      ///Overflow bin

      AddOverflowBinToLastBin(h_data);
      AddOverflowBinToLastBin(h_Wjets);
      AddOverflowBinToLastBin(h_WjetsScaled);
      AddOverflowBinToLastBin(h_WjetsEWK);
      AddOverflowBinToLastBin(h_Zjets);
      AddOverflowBinToLastBin(h_diboson);
      AddOverflowBinToLastBin(h_singleTop);
      AddOverflowBinToLastBin(h_ttbar);
      AddOverflowBinToLastBin(h_qcd);
      AddOverflowBinToLastBin(h_sigSM);

      AddOverflowBinToLastBin(h_ttbarMCatNLO);
      AddOverflowBinToLastBin(h_ttbarPowHer);
      AddOverflowBinToLastBin(h_ttbarAcerMCUp);
      AddOverflowBinToLastBin(h_ttbarAcerMCDown);
      AddOverflowBinToLastBin(h_Wjetsnom);
      AddOverflowBinToLastBin(h_Wjetsfac);
      AddOverflowBinToLastBin(h_Wjetsrenorm);
      AddOverflowBinToLastBin(h_Wjetsckkw);

      //&&&&
      if (typeName[itype].Contains("mTWV") ){
	AddLastBinsTo1TeVbin(h_data);
	AddLastBinsTo1TeVbin(h_Wjets);
	AddLastBinsTo1TeVbin(h_WjetsScaled);
	AddLastBinsTo1TeVbin(h_WjetsEWK);
	AddLastBinsTo1TeVbin(h_Zjets);
	AddLastBinsTo1TeVbin(h_diboson);
	AddLastBinsTo1TeVbin(h_singleTop);
	AddLastBinsTo1TeVbin(h_ttbar);
	AddLastBinsTo1TeVbin(h_qcd);	
	AddLastBinsTo1TeVbin(h_sigSM);
	
	AddLastBinsTo1TeVbin(h_ttbarMCatNLO);
	AddLastBinsTo1TeVbin(h_ttbarPowHer);
	AddLastBinsTo1TeVbin(h_ttbarAcerMCUp);
	AddLastBinsTo1TeVbin(h_ttbarAcerMCDown);
	AddLastBinsTo1TeVbin(h_Wjetsnom);
	AddLastBinsTo1TeVbin(h_Wjetsfac);
	AddLastBinsTo1TeVbin(h_Wjetsrenorm);
	AddLastBinsTo1TeVbin(h_Wjetsckkw);	    
      }

  
	
      int rebin =1;
      int rebinFac =2;

      //rebinFac = getRebinFactor(typeName[itype]);
      rebin *=rebinFac;

      h_data->Rebin(rebin);
      h_Wjets->Rebin(rebin);
      h_WjetsScaled->Rebin(rebin);
      h_WjetsEWK->Rebin(rebin);
      h_Zjets->Rebin(rebin);
      h_diboson->Rebin(rebin);
      h_singleTop->Rebin(rebin);
      h_ttbar->Rebin(rebin);
      h_qcd->Rebin(rebin);
      h_sigSM->Rebin(rebin);
      
      h_ttbarMCatNLO->Rebin(rebin);
      h_ttbarPowHer->Rebin(rebin);
      h_ttbarAcerMCUp->Rebin(rebin);
      h_ttbarAcerMCDown->Rebin(rebin);
      h_Wjetsnom->Rebin(rebin);
      h_Wjetsfac->Rebin(rebin);
      h_Wjetsrenorm->Rebin(rebin);
      h_Wjetsckkw->Rebin(rebin);
      
      for (int i=0;i<nsyst;i++){
	h_WjetsS[i]->Rebin(rebin);
	h_WjetsEWKS[i]->Rebin(rebin);
	h_ZjetsS[i]->Rebin(rebin);
	h_dibosonS[i]->Rebin(rebin);
	h_singleTopS[i]->Rebin(rebin);
	h_ttbarS[i]->Rebin(rebin);
	h_sigSMS[i]->Rebin(rebin);
      }

      // /*
      doVariableBinHisto(h_data);
      doVariableBinHisto(h_Wjets);
      doVariableBinHisto(h_WjetsScaled);
      doVariableBinHisto(h_WjetsEWK);
      doVariableBinHisto(h_Zjets);
      doVariableBinHisto(h_diboson);
      doVariableBinHisto(h_singleTop);
      doVariableBinHisto(h_ttbar);
      doVariableBinHisto(h_qcd);
      doVariableBinHisto(h_sigSM);
      
      doVariableBinHisto(h_ttbarMCatNLO);
      doVariableBinHisto(h_ttbarPowHer);
      doVariableBinHisto(h_ttbarAcerMCUp);
      doVariableBinHisto(h_ttbarAcerMCDown);
      doVariableBinHisto(h_Wjetsnom);
      doVariableBinHisto(h_Wjetsfac);
      doVariableBinHisto(h_Wjetsrenorm);
      doVariableBinHisto(h_Wjetsckkw);
	
      for (int i=0;i<nsyst;i++){
	AddOverflowBinToLastBin(h_WjetsS[i]);
	AddOverflowBinToLastBin(h_WjetsEWKS[i]);
	AddOverflowBinToLastBin(h_ZjetsS[i]);
	AddOverflowBinToLastBin(h_dibosonS[i]);
	AddOverflowBinToLastBin(h_singleTopS[i]);
	AddOverflowBinToLastBin(h_ttbarS[i]);
	AddOverflowBinToLastBin(h_sigSMS[i]);

	//&&&& mTWV plot should finish at 1TeV (not more)
	if (typeName[itype].Contains("mTWV") ){
	  AddLastBinsTo1TeVbin(h_WjetsS[i]);
	  AddLastBinsTo1TeVbin(h_WjetsEWKS[i]);
	  AddLastBinsTo1TeVbin(h_ZjetsS[i]);
	  AddLastBinsTo1TeVbin(h_dibosonS[i]);
	  AddLastBinsTo1TeVbin(h_singleTopS[i]);
	  AddLastBinsTo1TeVbin(h_ttbarS[i]);
	  AddLastBinsTo1TeVbin(h_sigSMS[i]);
	}

	doVariableBinHisto(h_WjetsS[i]);
	doVariableBinHisto(h_WjetsEWKS[i]);
	doVariableBinHisto(h_ZjetsS[i]);
	doVariableBinHisto(h_dibosonS[i]);
	doVariableBinHisto(h_singleTopS[i]);
	doVariableBinHisto(h_ttbarS[i]);
	doVariableBinHisto(h_sigSMS[i]);
      }
      //  */

      
      //hs->Add(h_sigSM); 
      // //hs->Add(h_Wjets);
	
      h_WjetsScaled->Add(h_WjetsEWK); //&&&& Don't show W+jets EWK in the plots separately
      //hs->Add(h_WjetsEWK); //&&&& show W+jets EWK in the plots separately
      
      hs->Add(h_sigSM); 
      hs->Add(h_qcd);
      hs->Add(h_Zjets);
      hs->Add(h_diboson);
      hs->Add(h_singleTop);
      hs->Add(h_ttbar);
      hs->Add(h_WjetsScaled);
      

      /////Setup the two pads before drawing histograms
      float ratio_size = 0.35 ;
      TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
      //p1->SetBottomMargin(0.00); //default
      // p1->SetRightMargin(0.12);
      p1->SetBottomMargin(0.005);
      p1->SetRightMargin(0.12);
      p1->SetLeftMargin(0.12);
      p1->Draw();
      
      
      p2->Draw();
      //p2->SetTopMargin(0.00); //default
      p2->SetTopMargin(0.05); 
      p2->SetBottomMargin(0.31);
      p2->SetRightMargin(0.12);
      p2->SetLeftMargin(0.12);
      
      
      p1->cd();
      ///// pad1
      
      p1->cd()->SetLogy(logy); 
	
      //hs->SetMaximum(hs->GetMaximum()*1.5);
      //if (logy)hs->SetMaximum(hs->GetMaximum()*200.);
      //hs->SetMinimum(1);
      //hs->SetMinimum(1.e-3);
	
      hs->Draw("hist");
    

      //hs->SetTitle(Form("%s_%s_%s",cutName[icut].Data(), typeName[itype].Data()) );
      //std::cout<<Form("%s_%s", cutName[icut].Data(), typeName[itype].Data())<<endl;
      
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
      //h_MC->Add(h_WjetsEWK); //&&&& h_WjetsScaled already contains h_WjetsEWK
      h_MC->Add(h_Zjets);
      h_MC->Add(h_diboson);
      h_MC->Add(h_singleTop);
      h_MC->Add(h_ttbar);
      h_MC->Add(h_sigSM);
      h_MC->Add(h_qcd); //For data-MC comparison, add QCD. For systematic band h_MC should not include QCD, we define a new histo called h_MCN for that purpose.
       
					  
      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // std::cout<<"KolmogorovTest result= "<<ks<<endl;
	
	
	


      float xstart(0.), xend(10.);

      GetXaxisRange(h_MC   , xstart  , xend    );
      if(typeName[itype].Contains("mjjTagged")){ //&&&& mjjTag n-1 plot
	xstart = 200; 
	xend = 2500; 
      }
      
      //cout<<"xstart = "<<xstart<<endl;
      //cout<<"xend = "<<xend<<endl;
      h_data->GetXaxis()->SetRangeUser(xstart,xend);  
      hs->GetXaxis()->SetRangeUser(xstart,xend);
      if (typeName[itype].Contains("mTWV") ){  //&&&&
	h_data->GetXaxis()->SetRangeUser(xstart,1000);
	hs->GetXaxis()->SetRangeUser(xstart,1000);
      }
      if (typeName[itype].Contains("bosonCentrality") ){  //&&&&
	h_data->GetXaxis()->SetRangeUser(-4,4);
	hs->GetXaxis()->SetRangeUser(-4,4);
      }

      //h_data->GetXaxis()->SetRangeUser(-6,6); //boson centrality
      //hs->GetXaxis()->SetRangeUser(-6,6);

      double maxi = hs->GetMaximum();
      double tmp = h_data->GetBinContent(h_data->GetMaximumBin());
      if (maxi < tmp) maxi =tmp;

      hs->SetMaximum(maxi *1.7);
      if (logy)hs->SetMaximum( maxi *200.);
      //hs->SetMinimum(1);
      //hs->SetMinimum(1.e-3);
      hs->SetMinimum(1.e-2); //&&&&

      //hs->Draw("hist");

      h_data->Draw("same");



      //TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
      TLegend *leg = new TLegend(0.53, 0.60, 0.87, 0.89) ;
      leg->SetNColumns(2);

      leg->SetBorderSize(0);  // no border for the legend box      

      // /*
      leg->AddEntry(h_data,"Data","lep");
      //leg->AddEntry(h_Wjets,"W+jets","f");
      leg->AddEntry(h_WjetsScaled,"W+jets","f");
      //leg->AddEntry(h_WjetsEWK,"W+jets EWK","f"); //&&&&
      leg->AddEntry(h_ttbar,"t#bar{t}","f");
      leg->AddEntry(h_singleTop,"Single-top","f");
      leg->AddEntry(h_diboson,"Diboson","f");
      leg->AddEntry(h_Zjets,"Z+jets","f");
      leg->AddEntry(h_qcd,"Multijet","f");
      leg->AddEntry(h_sigSM,"SM EWK WV","f");

      // */
      /*
      leg->AddEntry(h_data,"Data","p");
      //leg->AddEntry(h_Wjets,"W+jets","f");
      leg->AddEntry(h_WjetsScaled,"W+jets","f");
      //leg->AddEntry(h_WjetsEWK,"W+jets EWK","f"); //&&&&
      leg->AddEntry(h_Zjets,"Z+jets","f");
      leg->AddEntry(h_diboson,"Di-boson","f");
      leg->AddEntry(h_singleTop,"single top","f");
      leg->AddEntry(h_ttbar,"ttbar","f");
      leg->AddEntry(h_qcd,"QCD","f");
      leg->AddEntry(h_sigSM,"SM signal","f");
      */
      //leg->Draw();  //Draw later with systematics as one of the legends
      
      TLatex l;
      
      setLatexStyle(&l); //add the common ATLAS internal and luminosity

      //l.SetTextSize(0.055); 
      //l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      //l.SetTextColor(1); //black
      //l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
      //l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Preliminary}");
      //l.DrawLatex(0.20 , 0.72,"#int Ldt = 20.2 fb^{-1}");
      // if (lepName=="electron"){
      //   l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow e#nu , %s}", cutName[icut].Data() ) );
      // }else if (lepName=="muon"){
      //   l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow #mu#nu , %s}", cutName[icut].Data() ) );
      // }
      TString latexFlav("l");
      if (flavorName[iFlavor] == "p") { latexFlav = "l^{+}";}
      else if (flavorName[iFlavor] == "m") { latexFlav = "l^{-}";}
	
	
      l.DrawLatex(0.18 , 0.60,Form("#bf{ W#rightarrow %s#nu , SR+CR_Wjj}", latexFlav.Data() ) );
      


      
	  
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h_data->Clone();
      ratioHist->Divide(h_MC);

	
      setRatioPlotStyle (ratioHist);
      ratioHist->GetYaxis()->SetRangeUser(0., 2.9);
      //ratioHist->GetYaxis()->SetRangeUser(0., 5);
      //ratioHist->GetYaxis()->SetRangeUser(0., 10);
	
	
      //ratioHist->Draw();
      
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      //horiz_line->DrawLine(xstart,1.0,xend,1.0);

      ////<<<<<<<<<< systematics band >>>>>>>>>>>>>

      h_MCN =(TH1F*)h_MC->Clone();
      h_MCN ->Add(h_qcd,-1);
      /// <<<< use unscaled W+jets for systematic bands because in systematic samples the W+jets is unscaled >>>>
      h_MCN ->Add(h_WjetsScaled,-1);  //&&&& h_WjetsScaled contains h_WjetsEWK, so after subtracting h_WjetsScaled, we need to add back h_WjetsEWK.
      h_MCN ->Add(h_WjetsEWK);
      h_MCN ->Add(h_Wjets);  //h_MCN is sum of all MC (without QCD).

      for (int i=0;i<nsyst;i++){ 
	h_MCS[i]=(TH1F*)h_WjetsS[i]->Clone();
	h_MCS[i]->SetName(Form("%s_%s", h_WjetsS[i]->GetName(),systname[i].Data()));
	h_MCS[i]->Add(h_WjetsEWKS[i]);
	h_MCS[i]->Add(h_ZjetsS[i]);
	h_MCS[i]->Add(h_dibosonS[i]);
	h_MCS[i]->Add(h_singleTopS[i]);
	h_MCS[i]->Add(h_ttbarS[i]);
	h_MCS[i]->Add(h_sigSMS[i]);

	//if ( typeName[itype].Contains("mTWV") )getHighestDeviationForSyst(h_MCN,h_MCS[i]);
      }

	
      
      TH1F* hSystBandHi = (TH1F*)ratioHist->Clone("hdataMCratio");
      //TH1D* hSystBandLo = (TH1D*)ratioHist->Clone("hdataMCratio");

      hSystBandHi->SetMinimum(0.0);
      hSystBandHi->SetMaximum(2.5);   //&&&&
      //hSystBandHi->SetMaximum(5); 
      //hSystBandHi->SetMinimum(0.5);
      // hSystBandHi->SetMaximum(1.5);

	hSystBandHi->SetTitle("");
	hSystBandHi->GetYaxis()->SetTitle("Data/SM");
	hSystBandHi->GetYaxis()->SetTitleSize(0.12);
	hSystBandHi->GetYaxis()->SetTitleOffset(0.5);
	hSystBandHi->GetYaxis()->SetLabelSize(0.13);

	hSystBandHi->GetXaxis()->SetTitleSize(0.16);
	hSystBandHi->GetXaxis()->SetTitleOffset(1.0);
	hSystBandHi->GetXaxis()->SetLabelSize(0.12);

      int nbins = hSystBandHi->GetNbinsX();
      for (int ibin =1;ibin<=nbins;ibin++){
	double fracErr = 0;
	for (int i=0;i<nsyst;i++){ 
	  if (h_MCN->GetBinContent(ibin)!=0){
	    fracErr+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //?? h_MCN (MC, no QCD) used to calculate deviation but shouldn't we devide by MC+QCD?
	  }
	}

	fracErr += pow( h_MCN->GetBinError(ibin)/h_MCN->GetBinContent(ibin) , 2); //bin-by-bin uncertainty due to limited statistics in MC (no QCD)
	//cout<<"Limited MC --> "<<sqrt(fracErr)<<endl;
	  
	fracErr += pow( h_Wjets->GetBinContent(ibin)*0.18/h_MCN->GetBinContent(ibin) , 2); //W+jets SF uncertainty (18%)

	// /*
	if(h_MCN->GetBinContent(ibin) !=0.){
	  fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsfac->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //W+jets scale uncertainty
	  fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsrenorm->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	  fracErr+=pow((h_Wjetsnom->GetBinContent(ibin)-h_Wjetsckkw->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	}
	// */
	//cout<<"W+jets syst --> "<<sqrt(fracErr)<<endl;
	// /*
	if(h_MCN->GetBinContent(ibin) !=0.){  
	  fracErr+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarMCatNLO->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //ttbar theoretical uncertainty
	  fracErr+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarPowHer->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	  fracErr+=pow((h_ttbarAcerMCUp->GetBinContent(ibin)-h_ttbarAcerMCDown->GetBinContent(ibin))/(2 * h_MCN->GetBinContent(ibin)),2);
	}
	//if (h_ttbarAcerMCUp->GetBinContent(ibin)+h_ttbarAcerMCDown->GetBinContent(ibin) != 0.){
	//fracErr+=pow((h_ttbarAcerMCUp->GetBinContent(ibin)-h_ttbarAcerMCDown->GetBinContent(ibin))/(h_ttbarAcerMCUp->GetBinContent(ibin)+h_ttbarAcerMCDown->GetBinContent(ibin)),2);
	//}
	// */
	//cout<<"ttbar syst --> "<<sqrt(fracErr)<<endl;
	fracErr =sqrt(fracErr);
	if (h_MCN->GetBinContent(ibin)==0){fracErr =0;} //&&&&
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
      //hSystBandLo->Draw("same");

      hSystBandHi->Draw("e2");
      ratioHist->Draw("same");
      if (typeName[itype].Contains("bosonCentrality") ){  //&&&&
	horiz_line->DrawLine(-4,1.0,4,1.0);
      }else{
	horiz_line->DrawLine(xstart,1.0,xend,1.0);
      }
      
      //horiz_line->DrawLine(xstart,1.0,1000.,1.0); //&&&&
      //horiz_line->DrawLine(-6,1.0,6,1.0);

      p1->cd();
      leg->AddEntry(hSystBandHi,"Uncertainty","f");
      leg->Draw();
      
      //c2->Print("plots_syst_band_resolved.pdf",Form("Title:%s_%s_%s",flavorName[iFlavor].Data(),  cutName[icut].Data(), typeName[itype].Data()));
      //c2->Print(Form("PDF_syst_band/%s_%s_%s.pdf",flavorName[iFlavor].Data(),cutName[icut].Data(),typeName[itype].Data()) );

      if (!pdfforNote) {
	c2->Print("plots_syst_band_resolved.pdf",Form("Title:%s_%s",flavorName[iFlavor].Data(),  typeName[itype].Data()));
      }else{
	c2->Print(Form("PDF_syst_band/%s_%s.pdf",flavorName[iFlavor].Data(), typeName[itype].Data()) );
      }
      
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
  
   
  if (!pdfforNote) c2->Print("plots_syst_band_resolved.pdf]");
}

