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

void syst_band_fat_systeffect(){ 
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>

  bool DEBUG =0;
  //const int nsyst =32;

  const int nsyst =33;
  //const int nsyst =23;
  //const int nsyst =10;
  
  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_WjetsEWK, *h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.
  TH1F *h_sigSM;
  TH1F *h_WjetsS[nsyst], *h_WjetsEWKS[nsyst], *h_ZjetsS[nsyst],*h_dibosonS[nsyst],*h_singleTopS[nsyst], *h_ttbarS[nsyst], *h_qcdS[nsyst], *h_MCS[nsyst+6]; //h_MCS  are sum of systematic MC samples
  TH1F *h_MC_ori;
  TH1F *h_sigSMS[nsyst];
  TH1F *h_ttbarMCatNLO, *h_ttbarPowHer, *h_ttbarAcerMCUp, *h_ttbarAcerMCDown;
  TH1F *h_Wjetsnom, *h_Wjetsfac, *h_Wjetsrenorm, *h_Wjetsckkw;
  TH1F *h_Wjetsfac025, *h_Wjetsrenorm025, *h_Wjetsckkw15;  

  TH1F *ratioSystNom[nsyst+6];
  
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  

  bool pdfforNote = 0;
  if (!pdfforNote)c2->Print("plots_syst_band_fatOnly_systeffect.pdf["); 

  bool dovertline =0;

  ////Data and bkg
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK_WjetsSF0.82.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutAwv.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutBosonCen.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutCosThStar.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_ptwlep0.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_MjjTag200.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass.root");

  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.28Apr2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW.root");

  //Optimized cuts
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.26May2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_10_April30/lvqqCombQCD_plots.root");
  //
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.AwvN-1.smoothed.1June2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutAwv_10_April30/lvqqCombQCD_plots.root");
  //
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.bosonCentralityN-1.smoothed.1June2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutBosonCen_10_April30/lvqqCombQCD_plots.root");
  //
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.cosThetaStarN-1.smoothed.1June2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutCosThetaStar_10_April30/lvqqCombQCD_plots.root");
  //
  TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.ptwlepN-1.smoothed.1June2016.root");
  TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutPtwlep_10_April30/lvqqCombQCD_plots.root");
  //
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.mjjTaggedN-1.smoothed.1June2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_MjjTag200_10_April30/lvqqCombQCD_plots.root");
  

  TFile *fsyst [nsyst]; //hard coded
  //TString systname[nsyst]={"bJESUp"};

  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp","muSFUp","elIDUp"}; //32 components, JMSUp missing
  
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp","muSFUp","elIDUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","PunchThroughJESUp","NonClosure_AFIIJESUp","FatJESUp", "JMSUp","FatJPTRUp", "FatJMRUp" };
  //TString systname[nsyst]={"ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "muSFUp","elIDUp"};

  //TFile* fsyst_ttbar =TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.26May2016.root");
  //TFile* fsyst_wjets =TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.26May2016.root");
  
  
  const int nCut=1;TString cutName[nCut]={"SRfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"CR_TopfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"CR_WjjfatOnly"};
  //const int nCut=2;TString cutName[nCut]={"CR_TopfatOnly","CR_WjjfatOnly"};
  //const int nCut=5;TString cutName[nCut]={"CR_TopfatOnly","CR_TopFJ","CR_WjjfatOnly","SRfatOnly","SRFJ"};
  //const int nCut=1;TString cutName[nCut]={"CR_TopFJ"};

  //const int nCut=1;TString cutName[nCut]={"SR"};
  //const int nCut=1;TString cutName[nCut]={"CR_Top"};
  //const int nCut=2;TString cutName[nCut]={"CR_Top","CR_Wjj"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_Wjj","CR_TopfatOnly","CR_WjjfatOnly"};
    
  //const int nType=1;TString typeName[nType]={"VVptBalance"}; //Awv
  //const int nType=1;TString typeName[nType]={"bosonCentrality"};
  //const int nType=1;TString typeName[nType]={"cosThetaWDecay"};
  const int nType=1;TString typeName[nType]={"ptwlep"};
  //const int nType=1;TString typeName[nType]={"mjjTagged"};
  //const int nType=1;TString typeName[nType]={"Mwjj"};
  
  const int nType=1;TString typeName[nType]={"mTWV"};
  //const int nType=1;TString typeName[nType]={"Mwjj"};
  
  //const int nType=4;TString typeName[nType]={"bosonCentrality","cosThetaWDecay","VVptBalance","mjjTagged"};
  //const int nType=3;TString typeName[nType]={"Mwjj","MET_et","mTWV"};
  //const int nType=14;TString typeName[nType]={"lep_pt","MET_et","mT","Mwjj","mjjTagged","ptwlep","ptwjj","Mlvjj","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVptBalance"};
  //const int nType=7;TString typeName[nType]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"}; //&&&& these are the ones needed for the note
 
 
 
  
  for (int icut=0;icut<nCut;++icut){
    for (int itype=0;itype<nType;++itype){
      
  
	if ((cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	
	THStack *hs = new THStack("hs","");

	bool logy=false;
	if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("Mlvjj") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
	  logy = true;
	}
	//if (typeName[itype].Contains("mTWV") ) logy = true; //&&&&
	
	//<<<< From fakeEstimation root file >>>>
   
	h_data=(TH1F*)f0->Get(Form("H_Data_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_data->Add((TH1F*)f0->Get(Form("H_Data_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_data->Add((TH1F*)f0->Get(Form("H_Data_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_data->Add((TH1F*)f0->Get(Form("H_Data_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));

	
	h_sigSM=(TH1F*)f->Get(Form("H_VBS_WV_0_0_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_ep_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));

	
        h_Wjets=(TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())); 
	h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()))); 
	h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	
	

	h_WjetsScaled = (TH1F*) h_Wjets->Clone(); //already scaled, will add EWK to it
	
	
	
	h_WjetsEWK=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())); 
	h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()))); 
	h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	
	
	h_Zjets=(TH1F*)f->Get(Form("H_Zjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_qcd=(TH1F*)f->Get(Form("H_QCD_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_qcd->Add((TH1F*)f->Get(Form("H_QCD_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_qcd->Add((TH1F*)f->Get(Form("H_QCD_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_qcd->Add((TH1F*)f->Get(Form("H_QCD_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	
	
	///&&&&
	
	
	


	//<<<< From systematics root file >>>>
	
	for (int i=0;i<nsyst;i++){
	  h_WjetsS[i]=(TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_WjetsEWKS[i]=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_ZjetsS[i]=(TH1F*)f->Get(Form("H_Zjets_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_dibosonS[i]=(TH1F*)f->Get(Form("H_WZZZWg_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  
	  h_singleTopS[i]=(TH1F*)f->Get(Form("H_SingleTop_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  
	  h_ttbarS[i]=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));



	  h_sigSMS[i]=(TH1F*)f->Get(Form("H_VBS_WV_0_0_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data()));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	}


	// /*
	////ttbar systematics
	h_ttbarMCatNLO=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	
	h_ttbarPowHer=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	
	h_ttbarAcerMCUp=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data()));
	h_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	h_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	
	// */

	//	 /*
	////W+jets systematics (only electron is available) so use mp->ep, mm->em
		
	h_Wjetsfac  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	
	h_Wjetsrenorm  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	
	h_Wjetsckkw  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	// */
	///*
	h_Wjetsfac025  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	
	
	h_Wjetsrenorm025  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	
	
	h_Wjetsckkw15  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	// */
	/////
	
	
	h_data->SetLineColor(kBlack);
	h_Wjets->SetFillColor(kCyan);
	h_WjetsScaled->SetFillColor(kCyan);
	h_WjetsEWK->SetFillColor(kPink+10);
	h_Zjets->SetFillColor(kBlue);
	h_diboson->SetFillColor(kMagenta+2);
	h_singleTop->SetFillColor(kYellow-5);
	h_ttbar->SetFillColor(kYellow);
	h_qcd->SetFillColor(kGreen-8);
	h_sigSM->SetFillColor(kRed);

	for (int i=0;i<nsyst;i++){
	  h_WjetsS[i]->SetLineColor(kCyan);
	  h_WjetsEWKS[i]->SetLineColor(kPink+10);
	  h_ZjetsS[i]->SetLineColor(kBlue);
	  h_dibosonS[i]->SetLineColor(kMagenta+2);
	  h_singleTopS[i]->SetLineColor(kYellow-5);
	  h_ttbarS[i]->SetLineColor(kYellow);
	  h_sigSMS[i]->SetLineColor(kRed);
	}
	
	int N = h_data->GetNbinsX();
	double lowestBinWidth = h_data->GetBinWidth(1);
	bool variableBin=false;
	for (int ibin=N; ibin>1; ibin--){
	  //cout<<h->GetBinWidth(ibin)<<endl;
	  if (h_data->GetBinWidth(1) != h_data->GetBinWidth(ibin)){
	    variableBin =true;
	    //cout<<"variable bin!!" <<endl;
	    break;
	    
	  }
	}

	h_MC_ori=(TH1F*)h_WjetsScaled->Clone();
        h_MC_ori->Add(h_WjetsEWK); //&&&& This is before h_WjetsEWK added to h_WjetsScaled
	h_MC_ori->Add(h_Zjets);
        h_MC_ori->Add(h_diboson);
        h_MC_ori->Add(h_singleTop);
        h_MC_ori->Add(h_ttbar);
	h_MC_ori->Add(h_sigSM);
        h_MC_ori->Add(h_qcd);
	cout<<h_MC_ori->Integral()<<endl;
	cout<<h_data->Integral()<<endl;
	double chi2 =0.;
	for(int ibin =1 ; ibin <= N; ibin++){
	  
	  if (h_MC_ori->GetBinContent(ibin) >0){
	    cout<<"ibin = "<<ibin<<endl;
	    cout<<"h_data = "<<h_data->GetBinContent(ibin)<<endl;
	    cout<<"h_MC_ori = "<<h_MC_ori->GetBinContent(ibin)<<endl;
	    chi2 += (h_data->GetBinContent(ibin)-h_MC_ori->GetBinContent(ibin))*(h_data->GetBinContent(ibin)-h_MC_ori->GetBinContent(ibin))/h_MC_ori->GetBinContent(ibin);
	    cout<<"chi2 = "<<chi2<<endl;
	  }
	}
	cout<<"chi2 = "<<chi2<<endl;	
	
	if (variableBin){
	  //cout<<"Hello"<<endl;
	  for (int jbin=1; jbin<=N; jbin++){
	    if ( h_data->GetBinWidth(jbin)< lowestBinWidth ) lowestBinWidth =  h_data->GetBinWidth(jbin);
	  }
	}
	//cout<<"lowestBinWidth = "<<lowestBinWidth <<endl;
	///

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

	AddOverflowBinToLastBin(h_Wjetsfac);
	AddOverflowBinToLastBin(h_Wjetsrenorm);
	AddOverflowBinToLastBin(h_Wjetsckkw);

	AddOverflowBinToLastBin(h_Wjetsfac025);
	AddOverflowBinToLastBin(h_Wjetsrenorm025);
	AddOverflowBinToLastBin(h_Wjetsckkw15);

	for (int i=0;i<nsyst;i++){
	  AddOverflowBinToLastBin(h_WjetsS[i]);
	  AddOverflowBinToLastBin(h_WjetsEWKS[i]);
	  AddOverflowBinToLastBin(h_ZjetsS[i]);
	  AddOverflowBinToLastBin(h_dibosonS[i]);
	  AddOverflowBinToLastBin(h_singleTopS[i]);
	  AddOverflowBinToLastBin(h_ttbarS[i]);
	  AddOverflowBinToLastBin(h_sigSMS[i]);
	}
	
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

	  AddLastBinsTo1TeVbin(h_Wjetsfac);
	  AddLastBinsTo1TeVbin(h_Wjetsrenorm);
	  AddLastBinsTo1TeVbin(h_Wjetsckkw);	  

	  AddLastBinsTo1TeVbin(h_Wjetsfac025);
	  AddLastBinsTo1TeVbin(h_Wjetsrenorm025);
	  AddLastBinsTo1TeVbin(h_Wjetsckkw15);

	  for (int i=0;i<nsyst;i++){
	    AddLastBinsTo1TeVbin(h_WjetsS[i]);
	    AddLastBinsTo1TeVbin(h_WjetsEWKS[i]);
	    AddLastBinsTo1TeVbin(h_ZjetsS[i]);
	    AddLastBinsTo1TeVbin(h_dibosonS[i]);
	    AddLastBinsTo1TeVbin(h_singleTopS[i]);
	    AddLastBinsTo1TeVbin(h_ttbarS[i]);
	    AddLastBinsTo1TeVbin(h_sigSMS[i]);
	  }
	}
	
		
	int rebin=1;
      	int rebinFac =1;
	
	rebinFac = getRebinFactor(typeName[itype]);
	rebin *=rebinFac;

	//if (variableBin){rebin =1.;} //do not rebin for variable bin histograms
	
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

	h_Wjetsfac->Rebin(rebin);
	h_Wjetsrenorm->Rebin(rebin);
	h_Wjetsckkw->Rebin(rebin);

	h_Wjetsfac025->Rebin(rebin);
	h_Wjetsrenorm025->Rebin(rebin);
	h_Wjetsckkw15->Rebin(rebin);

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
	
	doVariableBinHisto(h_Wjetsfac);
	doVariableBinHisto(h_Wjetsrenorm);
	doVariableBinHisto(h_Wjetsckkw);

	doVariableBinHisto(h_Wjetsfac025);
	doVariableBinHisto(h_Wjetsrenorm025);
	doVariableBinHisto(h_Wjetsckkw15);
	
	//systematics histograms
	for (int i=0;i<nsyst;i++){

	  doVariableBinHisto(h_WjetsS[i]);
	  doVariableBinHisto(h_WjetsEWKS[i]);
	  doVariableBinHisto(h_ZjetsS[i]);
	  doVariableBinHisto(h_dibosonS[i]);
	  doVariableBinHisto(h_singleTopS[i]);
	  doVariableBinHisto(h_ttbarS[i]);
	  doVariableBinHisto(h_sigSMS[i]);
	}
	//  */
	

	//Build the stack

	hs->Add(h_sigSM); 
	hs->Add(h_qcd);
	hs->Add(h_Zjets);
	hs->Add(h_diboson);
	hs->Add(h_singleTop);
	hs->Add(h_ttbar);
	// hs->Add(h_Wjets);
	h_WjetsScaled->Add(h_WjetsEWK); //&&&& Don't show W+jets EWK in the plots separately
	hs->Add(h_WjetsScaled);
	//hs->Add(h_WjetsEWK); //&&&& show W+jets EWK in the plots separately
	//hs->Add(h_sigSM); 
	
	
	/////Setup the two pads before drawing histograms
	float ratio_size = 0.55 ;
	TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
	TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);

	setFirstPadStyle(p1);
	p1->Draw();

	setRatioPadStyle(p2);
	p2->Draw();
	
	
	p1->cd();
	///// pad1


	//logy = true;
	p1->cd()->SetLogy(logy);
	
	
	//hs->SetMaximum(hs->GetMaximum()*1.5);
	//if (logy)hs->SetMaximum(hs->GetMaximum()*200.);
	//hs->SetMinimum(1);
	//hs->SetMinimum(1.e-3);
	
	hs->Draw("hist");
    

	//hs->SetTitle(Form("%s_%s_%s",cutName[icut].Data(), typeName[itype].Data()) );
	//std::cout<<Form("%s_%s", cutName[icut].Data(), typeName[itype].Data())<<endl;

	hs->SetTitle("");
	
	//Y-axis label for stack
	TString GeV="GeV";
	if (typeName[itype].Contains("bosonCentrality")||typeName[itype].Contains("cosThetaWDecay")  || typeName[itype].Contains("VVptBalance") ) { GeV ="";}


	if (!variableBin){ //same bin width 
	  if (h_data->GetBinWidth(1)<0.1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.2f %s", h_data->GetBinWidth(1) , GeV.Data() )  );
	  else if (h_data->GetBinWidth(1)<1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f %s", h_data->GetBinWidth(1), GeV.Data()  )  );
	  else hs-> GetYaxis()->SetTitle( Form( "Entries / %.0f %s", h_data->GetBinWidth(1), GeV.Data()  )  ); //&&&&
	  
	} else{ //variable bin width
	  if (lowestBinWidth<0.1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.2f %s", lowestBinWidth , GeV.Data() )  );
	  else if (lowestBinWidth<1)hs-> GetYaxis()->SetTitle( Form( "Entries / %.1f %s", lowestBinWidth, GeV.Data()  )  );
	  else hs-> GetYaxis()->SetTitle( Form( "Entries / %.0f %s", lowestBinWidth, GeV.Data()  )  ); //&&&&
	  
	  //hs-> GetYaxis()->SetTitle( Form( "Entries /%.0f %s" , lowestBinWidth, GeV.Data())  );

	  
	}

	
			
	//cout<<hs-> GetYaxis()->GetTitleSize();
	// hs-> GetYaxis()->SetLabelSize(0.05);
	// hs-> GetYaxis()->SetTitleOffset(1);
	
	// h_data->SetMarkerStyle(20);
	// h_data->SetMarkerSize(1);
	
	setStackStyle (hs);

	hs->GetYaxis()->SetNdivisions(210); //&&&&

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
	
	

	
	
	
	
	float xstart(0.), xend(10.);

	GetXaxisRange(h_MC   , xstart  , xend    );
	

	//cout<<"xstart = "<<xstart<<endl;
	//cout<<"xend = "<<xend<<endl;
	
	if ( (cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")) && typeName[itype].Contains("Mwjj") ){
	  h_data-> GetXaxis()->SetRangeUser( 45, 140 );
	  hs-> GetXaxis()->SetRangeUser( 45, 140 );
	} else {
	  h_data->GetXaxis()->SetRangeUser(xstart,xend);
	  hs->GetXaxis()->SetRangeUser(xstart,xend);
	}
	if (typeName[itype].Contains("mTWV") ){  //&&&& REQUIRED. Last bins added to 1TeV bin
	  h_data->GetXaxis()->SetRangeUser(xstart,1000);
	  hs->GetXaxis()->SetRangeUser(xstart,1000);
	}

	if (typeName[itype].Contains("bosonCentrality") ){  //&&&&
	  if (cutName[icut].Contains("SRfatOnly")) {
	    h_data->GetXaxis()->SetRangeUser(-2,4); //-2 for fat, -4 for resolved
	    hs->GetXaxis()->SetRangeUser(-2,4);
	  }else {
	    h_data->GetXaxis()->SetRangeUser(-4,4); //-2 for fat, -4 for resolved
            hs->GetXaxis()->SetRangeUser(-4,4);
	  }
	}
	
	double maxi = hs->GetMaximum();
        double tmp = h_data->GetBinContent(h_data->GetMaximumBin());
        if (maxi < tmp) maxi =tmp;

        hs->SetMaximum(maxi *2.);
        if (logy)hs->SetMaximum( maxi *200.);
        //hs->SetMinimum(1);
        //hs->SetMinimum(1.e-1); //&&&&
	hs->SetMinimum(1.e-4);
	if (logy)hs->SetMinimum(1.e-1);
        //hs->Draw("hist");

	h_data->Draw("same");

	//for (int i=0;i<nsyst;i++){ //&&&&+
	//for (int i=0;i<1;i++){
	  //h_MCS[i]->Draw("same");
	//}
      
	//TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ; //too small
	TLegend *leg = new TLegend(0.53, 0.60, 0.87, 0.89) ;
	//TLegend *leg = new TLegend(0.5, 0.50, 0.95, 0.95) ; //big box, appropriate for presentations
	leg->SetNColumns(2);
	leg->SetBorderSize(0);  // no border for the legend box


	leg->AddEntry(h_data,"Data","lep");
	//leg->AddEntry(h_sigSM,"SM EWK WV","f");
	//leg->AddEntry(h_Wjets,"W+jets","f");
	leg->AddEntry(h_WjetsScaled,"W+jets","f");
	//leg->AddEntry(h_WjetsEWK,"W+jets EWK","f"); //&&&&
	leg->AddEntry(h_ttbar,"t#bar{t}","f");
	leg->AddEntry(h_singleTop,"single-top","f");
	leg->AddEntry(h_diboson,"Diboson","f");
	leg->AddEntry(h_Zjets,"Z+jets","f");
	leg->AddEntry(h_qcd,"multijet","f");
	leg->AddEntry(h_sigSM,"SM EWK WV","f");

	//leg->Draw(); //Draw later with systematics as one of the legends
      
	TLatex l;
	setLatexStyle(&l); //add the common ATLAS internal and luminosity
	
	TString latexFlav("l");
	
	//l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), cutName[icut].Data()) );
	
	TString latexCut("");
	if (cutName[icut].Contains("CR_Top")) { latexCut = "Top VR";}
	else if (cutName[icut].Contains("CR_Wjj") ) { latexCut = "W+jets VR";}
	else if (cutName[icut].Contains("SR") ) { latexCut = "SR";}
	
	l.SetTextSize(0.05); 
	if (cutName[icut].Contains("fatOnly") || cutName[icut].Contains("FJ")){
	  l.DrawLatex(0.18 , 0.60,Form("#bf{ W#rightarrow %s#nu, V#rightarrowJ, %s}", latexFlav.Data(), latexCut.Data()) );
	}else{
	  l.DrawLatex(0.18 , 0.60,Form("#bf{ W#rightarrow %s#nu, V#rightarrowjj, %s}", latexFlav.Data(), latexCut.Data()) );
	}	

	////
	TLine* vert_line = new TLine(0.0,0.0,1.0,1.0);

	double xcut = 0;
	int xbin = -1;
	double ymax = maxi;
	
        if (logy) {
	  //ymax *= 4.;
	  ymax *= 1.5;
	}else {
	  ymax *= 1.3;
	  //ymax *= 1.;
	}
	if (maxi <1)ymax =1.;
	//cout<<xcut<<endl;
	//cout<<ymax<<endl;

	/*
	if ( typeName[itype].Contains("ptwlep") ){
	  xbin = h_data->GetXaxis()->FindBin(149.);
	} else if ( typeName[itype].Contains("mjjTagged" ) ){
	  xbin = h_data->GetXaxis()->FindBin(899.);
	} else if ( typeName[itype].Contains("cosThetaWDecay") ){
	  xbin = h_data->GetXaxis()->FindBin(0.49);
	} else if ( typeName[itype].Contains("bosonCentrality") ){
	  xbin = h_data->GetXaxis()->FindBin(0.89);
	} else if ( typeName[itype].Contains("VVptBalance") ){
	  xbin = h_data->GetXaxis()->FindBin(0.299);
	} else xbin =-1; 
	//cout<<"xbin ="<<xbin<<endl;
	xcut = h_data->GetBinLowEdge(xbin+1);
	*/
	
	if ( typeName[itype].Contains("ptwlep") ){
	  xcut = 150.;
	} else if ( typeName[itype].Contains("mjjTagged" ) ){
	  xcut = 900.;
	} else if ( typeName[itype].Contains("cosThetaWDecay") ){
	  xcut = 0.5;
	} else if ( typeName[itype].Contains("bosonCentrality") ){
	  xcut = 0.9;
	} else if ( typeName[itype].Contains("VVptBalance") ){
	  xcut = 0.3;
	} else xcut =-1; 
	
	vert_line->SetLineStyle(2);
	vert_line->SetLineColor(kRed+1);
	vert_line->SetLineWidth(3);
	
	if (dovertline){
	  vert_line->DrawLine(xcut,0,xcut, ymax);
	}

	TArrow *ar1 = new TArrow(xcut,ymax*(0.7),xcut*(1.2),ymax*(0.7),0.02,"|>");
	//TArrow *ar1 = new TArrow(xcut,ymax*(0.95),xcut*(1.2),ymax*(0.95),0.02,"|>");
	//TArrow *ar1 = new TArrow(xcut,ymax*(0.95),xcut*(0.8),ymax*(0.95),0.02,"|>");  //cosThetaStar
	ar1->SetLineWidth(2);	

	if (dovertline)ar1->Draw();
	///
	  
	p2->cd();
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h_data->Clone();
	ratioHist->Divide(h_MC);
	if ( typeName[itype].Contains("Mwjj") && ( cutName[icut].Contains("FJ") || cutName[icut].Contains("fatOnly") )) { ratioHist->GetXaxis()->SetTitle("M(J) [GeV]");}
	if ( typeName[itype].Contains("VVptBalance") ) { ratioHist->GetXaxis()->SetTitle("A_{WV} ");}
	if ( typeName[itype].Contains("cosThetaWDecay") ) { ratioHist->GetXaxis()->SetTitle("cos(#theta_{j}*) ");}

	//double chi2 = h_data->Chi2Test(h_MC, "P");
	
	setRatioPlotStyle (ratioHist);
	ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
	//ratioHist->GetYaxis()->SetRangeUser(0.5, 1.7);

	ratioHist->GetYaxis()->SetNdivisions(505); //&&&&
	
	//ratioHist->Draw();
      
	TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	horiz_line->SetLineStyle(2);


	////<<<<<<<<<< systematics band >>>>>>>>>>>>>

	h_MCN =(TH1F*)h_MC->Clone();
	h_MCN ->Add(h_qcd,-1);

	

	
	for (int i=0;i<nsyst;i++){
	  h_MCS[i]=(TH1F*)h_WjetsS[i]->Clone();
	  h_MCS[i]->SetName(Form("%s_%s", h_WjetsS[i]->GetName(),systname[i].Data()));
	  h_MCS[i]->Add(h_WjetsEWKS[i]);
	  h_MCS[i]->Add(h_ZjetsS[i]);
	  h_MCS[i]->Add(h_dibosonS[i]);
	  h_MCS[i]->Add(h_singleTopS[i]);
	  h_MCS[i]->Add(h_ttbarS[i]);
	  h_MCS[i]->Add(h_sigSMS[i]);
	  if (i==0 || i==6  || i==12 || i==18 || i==24 || i==30)h_MCS[i]->SetLineColor(kBlue);
	  if (i==1 || i==7  || i==13 || i==19 || i==25 || i==31)h_MCS[i]->SetLineColor(kOrange);
	  if (i==2 || i==8  || i==14 || i==20 || i==26 || i==32)h_MCS[i]->SetLineColor(kGreen);
	  if (i==3 || i==9  || i==15 || i==21 || i==27 )h_MCS[i]->SetLineColor(kMagenta);
	  if (i==4 || i==10 || i==16 || i==22 || i==28)h_MCS[i]->SetLineColor(kCyan);
	  if (i==5 || i==11 || i==17 || i==23 || i==29)h_MCS[i]->SetLineColor(kViolet);
	  
	  //if ( typeName[itype].Contains("mTWV") )getHighestDeviationForSyst(h_MCN,h_MCS[i]);
	}

	for (int i =0; i<3;i++){
	  h_MCS[nsyst+i]=(TH1F*)h_MCN->Clone();
	  //cout<<h_MCN->Integral()<<endl;
	  h_MCS[nsyst+i]->Add(h_Wjets,-1);
	  if (i==0){
	    h_MCS[nsyst+i]->Add(h_Wjetsckkw);
	    h_MCS[nsyst+i]->SetLineColor(kBlue);
	  }else if (i==1){
	    h_MCS[nsyst+i]->Add(h_Wjetsfac025);
	    h_MCS[nsyst+i]->SetLineColor(kOrange);
	  }else if (i==2){
	    h_MCS[nsyst+i]->Add(h_Wjetsrenorm025);
	    h_MCS[nsyst+i]->SetLineColor(kGreen);
	  }
	  
	}

	for (int i =0; i<3;i++){
	  h_MCS[nsyst+3+i]=(TH1F*)h_MCN->Clone();
	  cout<<h_MCN->Integral()<<endl;
	  h_MCS[nsyst+3+i]->Add(h_ttbar,-1);
	  
	  if (i==0){
	    h_MCS[nsyst+3+i]->Add(h_ttbarMCatNLO);
	    h_MCS[nsyst+3+i]->SetLineColor(kBlue);
	  }else if (i==1){
	    h_MCS[nsyst+3+i]->Add(h_ttbarPowHer);
	    h_MCS[nsyst+3+i]->SetLineColor(kOrange);
	  }else if (i==2){
	    h_MCS[nsyst+3+i]->Add(h_ttbarAcerMCUp);
	    h_MCS[nsyst+3+i]->SetLineColor(kGreen);
	  }
	}
	
		
      
	TH1F* hSystBandHi = (TH1F*)ratioHist->Clone("hdataMCratio");
	//TH1D* hSystBandLo = (TH1D*)ratioHist->Clone("hdataMCratio");

	gStyle->SetHatchesLineWidth(1);
	gStyle->SetHatchesSpacing(0.8);
	
	hSystBandHi->SetMinimum(0.01);
	hSystBandHi->SetMaximum(2.5);   //&&&&
	//hSystBandHi->SetMaximum(5.);   //&&&&
        //hSystBandHi->SetMinimum(0.5);
	//hSystBandHi->SetMaximum(1.5);
	//hSystBandHi->SetMaximum(2.);

	
	setBandStyle(hSystBandHi);
	hSystBandHi->GetYaxis()->SetTitleSize(0.08);
	hSystBandHi->GetYaxis()->SetTitleOffset(0.5);
	hSystBandHi->GetYaxis()->SetLabelSize(0.08);
	
	hSystBandHi->GetXaxis()->SetTitleSize(0.09);
	//hSystBandHi->GetXaxis()->SetTitleOffset(1.0); //&&&&
	//hSystBandHi->GetXaxis()->SetTitleOffset(0.85); // was 0.9, j of cos(#theta_{j}*) is cut off  
	hSystBandHi->GetXaxis()->SetLabelSize(0.08);
  
	
	
	int nbins = hSystBandHi->GetNbinsX();
	for (int ibin =1;ibin<=nbins;ibin++){
	  double fracErr = 0;
	  double fracErrJES = 0;
	  double fracErrOther = 0;
	  double fracErrLimMC = 0;
	  double fracErrWjetsSF = 0;
	  double fracErrTtbarMod = 0;
	  double fracErrWjetsMod = 0;
	  if (DEBUG)cout<<"Nominal without QCD -> "<<h_MCN->GetBinContent(ibin)<<endl;
	  for (int i=0;i<nsyst;i++){ 
	    if (h_MCN->GetBinContent(ibin)!=0){
	      if (i<23){ //&&&& HARD CODED
		fracErrJES+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      }else {
		fracErrOther+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      }
	      //fracErr+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    }
	    //if (DEBUG) cout<<systname[i]<<" -> "<<h_MCS[i]->GetBinContent(ibin)<<endl;
	  }
	  //cout<<"JES fracErr --> "<<sqrt(fracErrJES)<<endl;
	  //cout<<"Other det. --> "<<sqrt(fracErrOther)<<endl;
	  //&&&&
	  if(h_MCN->GetBinContent(ibin) !=0.){	  
	    fracErr += pow( h_MCN->GetBinError(ibin)/h_MCN->GetBinContent(ibin) , 2); //bin-by-bin uncertainty due to limited statistics in MC (no QCD)
	    fracErrLimMC += pow( h_MCN->GetBinError(ibin)/h_MCN->GetBinContent(ibin) , 2); 
	    //cout<<"Limited MC --> "<<sqrt(fracErrLimMC)<<endl;
	    
	    //fracErr += pow( h_Wjets->GetBinContent(ibin)*0.18/h_MCN->GetBinContent(ibin) , 2); //W+jets SF uncertainty (18%)
	    fracErrWjetsSF+= pow( h_Wjets->GetBinContent(ibin)*0.18/h_MCN->GetBinContent(ibin) , 2); //W+jets SF uncertainty (18%)
	    //cout<<"W+jets SF --> "<<sqrt(fracErrWjetsSF)<<endl;
	    	    
	    // /*
	      if (DEBUG){
	      cout<<"h_MCN->GetBinContent(ibin)= "<<h_MCN->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjets->GetBinContent(ibin)= "<<h_Wjets->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsfac->GetBinContent(ibin)= "<<h_Wjetsfac->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsfac025->GetBinContent(ibin)= "<<h_Wjetsfac025->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsrenorm->GetBinContent(ibin)= "<<h_Wjetsrenorm->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsrenorm025->GetBinContent(ibin)= "<<h_Wjetsrenorm025->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsckkw->GetBinContent(ibin)= "<<h_Wjetsckkw->GetBinContent(ibin)<<endl;
	      cout<<"h_Wjetsckkw15->GetBinContent(ibin)= "<<h_Wjetsckkw15->GetBinContent(ibin)<<endl;
	      
	        }

	      //SR used fac025, renorm025,ckkw30 by BL --5/26/16
	      ////fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsfac->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //W+jets scale uncertainty
	      ////fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsrenorm->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsckkw->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsfac025->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsrenorm025->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      ////fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsckkw15->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    
	    // */
	    //fracErr+=fracErrWjetsMod;
	    //cout<<"W+jets syst --> "<<sqrt(fracErrWjetsMod)<<endl;
	    // /*
	    
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarMCatNLO->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //ttbar theoretical uncertainty
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarPowHer->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarAcerMCUp->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);

	    //fracErr+=fracErrTtbarMod;
	    //cout<<"ttbar syst --> "<<sqrt(fracErrTtbarMod)<<endl;
	    //cout<<"total syst --> "<<sqrt(fracErr)<<endl;

	  }
	  
	  // */
	  
	  fracErr =sqrt(fracErr);

	  //if (typeName[itype].Contains("Mwjj") && h_MCN->GetBinContent(ibin)==0){fracErr =0;} //&&&&
	  if (h_MCN->GetBinContent(ibin)==0){fracErr =0;} //&&&&
	  hSystBandHi->SetBinContent(ibin, 1);
	  hSystBandHi->SetBinError(ibin, fracErr);

	  
	}

	
	//hSystBandHi->Draw("e2 same");
	//hSystBandLo->Draw("same");

	hSystBandHi->Draw("e2");
	ratioHist->Draw("same");


	//TLegend *leg2 = new TLegend(0.7, 0.35, 0.87, 0.55) ;
	//TLegend *leg2 = new TLegend(0.13, 0.35, 0.3, 0.55) ;
	TLegend *leg2 = new TLegend(0.23, 0.7, 0.4, 0.9) ;
	leg2->SetNColumns(2);
	leg2->SetBorderSize(0);  // no border for the legend box
	
	for (int i=0;i<nsyst+6;i++){ 
	  ratioSystNom[i] = (TH1F*)h_MCS[i]->Clone();
	  ratioSystNom[i]->Divide(h_MCN);
	  //if (i>=0 && i<6){  //&&&&+
	  //if (i>=6 && i<12){
	  //if (i>=12 && i<18){
	  //if (i>=18 && i<24){
	  //if (i>=24 && i<30){
	  //if (i>=30 && i<33){
	  if (i>=33 && i<36){
	  //if (i>=36 && i<39){
	    ratioSystNom[i]->Draw("same");
	    //cout<<systname[nsyst]<<endl;
	    if (i<nsyst)leg2->AddEntry(h_MCS[i],systname[i],"l");
	    else if (i==nsyst)leg2->AddEntry(h_MCS[i],"W+jets CKKW","l");
	    else if (i==nsyst+1)leg2->AddEntry(h_MCS[i],"W+jets fac","l");
	    else if (i==nsyst+2)leg2->AddEntry(h_MCS[i],"W+jets renorm","l");
	    else if (i==nsyst+3)leg2->AddEntry(h_MCS[i],"ttbar MC@NLO","l");
	    else if (i==nsyst+4)leg2->AddEntry(h_MCS[i],"ttbar Herwig","l");
	    else if (i==nsyst+5)leg2->AddEntry(h_MCS[i],"ttbar AcerMC","l");
	    
	  }
	}
	leg2->Draw();
		
	if ( typeName[itype].Contains("mTWV") ) {
	  horiz_line->DrawLine(xstart,1.0,1000.,1.0); 
	}else if ( typeName[itype].Contains("Mwjj") && ( cutName[icut].Contains("FJ") || cutName[icut].Contains("fatOnly") )){
	  horiz_line->DrawLine(45.,1.0,140.,1.0);
	}else if (typeName[itype].Contains("bosonCentrality") ){  //&&&&
	  if (cutName[icut].Contains("SRfatOnly")) {
	    horiz_line->DrawLine(-2,1.0,4,1.0); //-2 for fatOnly, -4 for resolved
	  } else {
	    horiz_line->DrawLine(-4,1.0,4,1.0);
	  }
	}else{
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
	}
	
	//if (dovertline){
	//  vert_line->DrawLine(xcut,0,xcut,2.5 );
	//}
	
	p1->cd();
	leg->AddEntry(hSystBandHi,"Uncertainty","f");
	leg->Draw();

	
	if (!pdfforNote) {
	  c2->Print("plots_syst_band_fatOnly_systeffect.pdf",Form("Title:%s_%s",cutName[icut].Data(), typeName[itype].Data()));
	}else{
	  c2->Print(Form("PDF_syst_band/l_%s_%s.pdf",cutName[icut].Data(),typeName[itype].Data()) );
	}
	
	p1->Clear();
	p2->Clear();
	
	c2->cd();
	delete hs;
    }
  }
  
  f->Close();


    
   
  if (!pdfforNote) c2->Print("plots_syst_band_fatOnly_systeffect.pdf]");
}

