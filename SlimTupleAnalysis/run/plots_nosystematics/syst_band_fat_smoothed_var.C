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
#include "redoPtwlepHist.h"

void syst_band_fat_smoothed_var(){ 
  
  ////<<<<<<<<<<<< stack plots >>>>>>>>>>>>>

  bool DEBUG =0;
  //const int nsyst =32;

  const int nsyst =33;
  //const int nsyst =23;
  //const int nsyst =10;


  TH1F *h_ori_data,*h_ori_Wjets,*h_ori_WjetsScaled,*h_ori_WjetsEWK, *h_ori_Zjets,*h_ori_diboson,*h_ori_singleTop, *h_ori_ttbar, *h_ori_qcd, *h_ori_MC, *h_ori_MCN;//h_ori_MC and h_ori_MCN are sum of nominal bkg samples with and without QCD respectively.
  TH1F *h_ori_sigSM;
  TH1F *h_ori_WjetsS[nsyst], *h_ori_WjetsEWKS[nsyst], *h_ori_ZjetsS[nsyst],*h_ori_dibosonS[nsyst],*h_ori_singleTopS[nsyst], *h_ori_ttbarS[nsyst], *h_ori_qcdS[nsyst], *h_ori_MCS[nsyst]; //h_ori_MCS  are sum of systematic MC samples
  TH1F *h_ori_sigSMS[nsyst];
  TH1F *h_ori_ttbarMCatNLO, *h_ori_ttbarPowHer, *h_ori_ttbarAcerMCUp, *h_ori_ttbarAcerMCDown;
  TH1F *h_ori_Wjetsnom, *h_ori_Wjetsfac, *h_ori_Wjetsrenorm, *h_ori_Wjetsckkw;
  TH1F *h_ori_Wjetsfac025, *h_ori_Wjetsrenorm025, *h_ori_Wjetsckkw15;  
  

  
  TH1F *h_data,*h_Wjets,*h_WjetsScaled,*h_WjetsEWK, *h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_MCN;//h_MC and h_MCN are sum of nominal bkg samples with and without QCD respectively.
  TH1F *h_sigSM;
  TH1F *h_WjetsS[nsyst], *h_WjetsEWKS[nsyst], *h_ZjetsS[nsyst],*h_dibosonS[nsyst],*h_singleTopS[nsyst], *h_ttbarS[nsyst], *h_qcdS[nsyst], *h_MCS[nsyst]; //h_MCS  are sum of systematic MC samples
  TH1F *h_sigSMS[nsyst];
  TH1F *h_ttbarMCatNLO, *h_ttbarPowHer, *h_ttbarAcerMCUp, *h_ttbarAcerMCDown;
  TH1F *h_Wjetsnom, *h_Wjetsfac, *h_Wjetsrenorm, *h_Wjetsckkw;
  TH1F *h_Wjetsfac025, *h_Wjetsrenorm025, *h_Wjetsckkw15;  



  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  

  bool pdfforNote = 1;
  if (!pdfforNote)c2->Print("plots_syst_band_fatOnly_smoothed.pdf[");

  bool dovertline =1;

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
  //TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.ptwlepN-1.smoothed.1June2016.root");
  //TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutPtwlep_10_April30/lvqqCombQCD_plots.root");
  //
  TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.mjjTaggedN-1.smoothed.1June2016.root");
  TFile *f0=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_MjjTag200_10_April30/lvqqCombQCD_plots.root");
  

  TFile *fsyst [nsyst]; //hard coded
  //TString systname[nsyst]={"bJESUp"};

  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp","muSFUp","elIDUp"}; //32 components, JMSUp missing
  
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","JMSUp", "FatJPTRUp", "FatJMRUp" ,  "ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "PunchThroughJESUp","NonClosure_AFIIJESUp","muSFUp","elIDUp"};
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","PunchThroughJESUp","NonClosure_AFIIJESUp","FatJESUp", "JMSUp","FatJPTRUp", "FatJMRUp" };
  //TString systname[nsyst]={"ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard", "muSFUp","elIDUp"};

  //TFile* fsyst_ttbar =TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.26May2016.root");
  //TFile* fsyst_wjets =TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.26May2016.root");
  
  
  //const int nCut=1;TString cutName[nCut]={"SRfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"CR_TopfatOnly"};
  //const int nCut=1;TString cutName[nCut]={"CR_WjjfatOnly"};
  //const int nCut=2;TString cutName[nCut]={"CR_TopfatOnly","CR_WjjfatOnly"};
  //const int nCut=5;TString cutName[nCut]={"CR_TopfatOnly","CR_TopFJ","CR_WjjfatOnly","SRfatOnly","SRFJ"};
  //const int nCut=1;TString cutName[nCut]={"CR_TopFJ"};

  const int nCut=1;TString cutName[nCut]={"SR"};
  //const int nCut=2;TString cutName[nCut]={"CR_Top","CR_Wjj"};

  //const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  
  //const int nType=1;TString typeName[nType]={"ptwlep"};
  const int nType=1;TString typeName[nType]={"mjjTagged"};
  
  
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
   
	h_ori_data=(TH1F*)f0->Get(Form("H_Data_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_data->Add((TH1F*)f0->Get(Form("H_Data_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_ori_data->Add((TH1F*)f0->Get(Form("H_Data_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_data->Add((TH1F*)f0->Get(Form("H_Data_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));

	
	h_ori_sigSM=(TH1F*)f->Get(Form("H_VBS_WV_0_0_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_ep_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_em_WBF_%s_%s",cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_sigSM->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));

	
        h_ori_Wjets=(TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())); 
	h_ori_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()))); 
	h_ori_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	
	

	h_ori_WjetsScaled = (TH1F*) h_ori_Wjets->Clone(); //already scaled, will add EWK to it
	TString name2 =TString(h_ori_Wjets->GetName());
	name2 = name2.ReplaceAll("Wjets","WjetsScaled");
	h_ori_WjetsScaled ->SetName(name2);
	//cout<<name2<<endl;
	
	
	h_ori_WjetsEWK=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())); 
	h_ori_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()))); 
	h_ori_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_WjetsEWK->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	
	
	h_ori_Zjets=(TH1F*)f->Get(Form("H_Zjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_ori_diboson=(TH1F*)f->Get(Form("H_WZZZWg_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_ori_singleTop=(TH1F*)f->Get(Form("H_SingleTop_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_ori_ttbar=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	h_ori_qcd=(TH1F*)f->Get(Form("H_QCD_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_qcd->Add((TH1F*)f->Get(Form("H_QCD_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_qcd->Add((TH1F*)f->Get(Form("H_QCD_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_qcd->Add((TH1F*)f->Get(Form("H_QCD_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())));


	
	// /*
	////ttbar systematics
	h_ori_ttbarMCatNLO=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarMCatNLO->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_McnloVsPowheg", cutName[icut].Data(),typeName[itype].Data())));
	
	h_ori_ttbarPowHer=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarPowHer->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_HerwigVsPythia", cutName[icut].Data(),typeName[itype].Data())));
	
	h_ori_ttbarAcerMCUp=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data()));
	h_ori_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	h_ori_ttbarAcerMCUp->Add ( (TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_AcerMCUpDown", cutName[icut].Data(),typeName[itype].Data())));
	
	// */

	//	 /*
	////W+jets systematics (only electron is available) so use mp->ep, mm->em
		
	h_ori_Wjetsfac  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_ori_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_ori_Wjetsfac  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac4"  , cutName[icut].Data(),typeName[itype].Data())) );
	
	h_ori_Wjetsrenorm  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsrenorm  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm4"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	
	h_ori_Wjetsckkw  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsckkw  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw30"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	// */
	///&&&&
	///*
	h_ori_Wjetsfac025  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_ori_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	h_ori_Wjetsfac025  ->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_fac025"  , cutName[icut].Data(),typeName[itype].Data())) );
	
	
	h_ori_Wjetsrenorm025  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsrenorm025  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_renorm025"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	
	
	h_ori_Wjetsckkw15  = (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) ;
	h_ori_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	h_ori_Wjetsckkw15  ->Add( (TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_ckkw15"  , cutName[icut].Data(),typeName[itype].Data()) ) );
	// */
	
	


	//<<<< From systematics root file >>>>
	
	for (int i=0;i<nsyst;i++){
	  h_ori_WjetsS[i]=(TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_WjetsS[i]->Add((TH1F*)f->Get(Form("H_Wjets_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_ori_WjetsEWKS[i]=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_WjetsEWKS[i]->Add((TH1F*)f->Get(Form("H_WjetsEWKSherpa_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_ori_ZjetsS[i]=(TH1F*)f->Get(Form("H_Zjets_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_ZjetsS[i]->Add((TH1F*)f->Get(Form("H_Zjets_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));

	  h_ori_dibosonS[i]=(TH1F*)f->Get(Form("H_WZZZWg_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_dibosonS[i]->Add((TH1F*)f->Get(Form("H_WZZZWg_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  
	  h_ori_singleTopS[i]=(TH1F*)f->Get(Form("H_SingleTop_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_singleTopS[i]->Add((TH1F*)f->Get(Form("H_SingleTop_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  
	  h_ori_ttbarS[i]=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data()));
	  h_ori_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));
	  h_ori_ttbarS[i]->Add((TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(), systname[i].Data())));



	  h_ori_sigSMS[i]=(TH1F*)f->Get(Form("H_VBS_WV_0_0_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data()));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_WV_0_0_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_ep_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_em_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mp_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	  h_ori_sigSMS[i]->Add((TH1F*)f->Get(Form("H_VBS_ZV_0_0_mm_WBF_%s_%s_%s", cutName[icut].Data(),typeName[itype].Data(),systname[i].Data())));
	}
     
	/////
          
	
	
	

	int N = h_ori_data->GetNbinsX();
	double lowestBinWidth = h_ori_data->GetBinWidth(1);
	bool variableBin=false;
	for (int ibin=N; ibin>1; ibin--){
	  //cout<<h->GetBinWidth(ibin)<<endl;
	  if (h_ori_data->GetBinWidth(1) != h_ori_data->GetBinWidth(ibin)){
	    variableBin =true;
	    //cout<<"variable bin!!" <<endl;
	    break;
	    
	  }
	}
	
	if (variableBin){
	  //cout<<"Hello"<<endl;
	  for (int jbin=1; jbin<=N; jbin++){
	    if ( h_ori_data->GetBinWidth(jbin)< lowestBinWidth ) lowestBinWidth =  h_ori_data->GetBinWidth(jbin);
	  }
	}
	//cout<<"lowestBinWidth = "<<lowestBinWidth <<endl;
	///

		
	///Overflow bin
	AddOverflowBinToLastBin(h_ori_data);
	AddOverflowBinToLastBin(h_ori_Wjets);
	AddOverflowBinToLastBin(h_ori_WjetsScaled);
	AddOverflowBinToLastBin(h_ori_WjetsEWK);
	AddOverflowBinToLastBin(h_ori_Zjets);
	AddOverflowBinToLastBin(h_ori_diboson);
	AddOverflowBinToLastBin(h_ori_singleTop);
	AddOverflowBinToLastBin(h_ori_ttbar);
	AddOverflowBinToLastBin(h_ori_qcd);
	AddOverflowBinToLastBin(h_ori_sigSM);

	AddOverflowBinToLastBin(h_ori_ttbarMCatNLO);
	AddOverflowBinToLastBin(h_ori_ttbarPowHer);
	AddOverflowBinToLastBin(h_ori_ttbarAcerMCUp);

	AddOverflowBinToLastBin(h_ori_Wjetsfac);
	AddOverflowBinToLastBin(h_ori_Wjetsrenorm);
	AddOverflowBinToLastBin(h_ori_Wjetsckkw);

	AddOverflowBinToLastBin(h_ori_Wjetsfac025);
	AddOverflowBinToLastBin(h_ori_Wjetsrenorm025);
	AddOverflowBinToLastBin(h_ori_Wjetsckkw15);

	for (int i=0;i<nsyst;i++){
	  AddOverflowBinToLastBin(h_ori_WjetsS[i]);
	  AddOverflowBinToLastBin(h_ori_WjetsEWKS[i]);
	  AddOverflowBinToLastBin(h_ori_ZjetsS[i]);
	  AddOverflowBinToLastBin(h_ori_dibosonS[i]);
	  AddOverflowBinToLastBin(h_ori_singleTopS[i]);
	  AddOverflowBinToLastBin(h_ori_ttbarS[i]);
	  AddOverflowBinToLastBin(h_ori_sigSMS[i]);
	}
	
	
	//&&&& change the last bin
	if (typeName[itype] == "ptwlep"){
	  h_data = redoPtwlepHist(h_ori_data);
	  h_Wjets = redoPtwlepHist(h_ori_Wjets);
	  h_WjetsScaled = redoPtwlepHist(h_ori_WjetsScaled);
	  h_WjetsEWK = redoPtwlepHist(h_ori_WjetsEWK);
	  h_Zjets = redoPtwlepHist(h_ori_Zjets);
	  h_diboson = redoPtwlepHist(h_ori_diboson);
	  h_singleTop = redoPtwlepHist(h_ori_singleTop);
	  h_ttbar = redoPtwlepHist(h_ori_ttbar);
	  h_qcd = redoPtwlepHist(h_ori_qcd);
	  h_sigSM = redoPtwlepHist(h_ori_sigSM);
	  
	  h_ttbarMCatNLO = redoPtwlepHist(h_ori_ttbarMCatNLO);
	  h_ttbarPowHer = redoPtwlepHist(h_ori_ttbarPowHer);
	  h_ttbarAcerMCUp = redoPtwlepHist(h_ori_ttbarAcerMCUp);
	  
	  h_Wjetsfac = redoPtwlepHist(h_ori_Wjetsfac);
	  h_Wjetsrenorm = redoPtwlepHist(h_ori_Wjetsrenorm);
	  h_Wjetsckkw = redoPtwlepHist(h_ori_Wjetsckkw);
	  
	  h_Wjetsfac025 = redoPtwlepHist(h_ori_Wjetsfac025);
	  h_Wjetsrenorm025 = redoPtwlepHist(h_ori_Wjetsrenorm025);
	  h_Wjetsckkw15 = redoPtwlepHist(h_ori_Wjetsckkw15);
	  
	  for (int i=0;i<nsyst;i++){
	    h_WjetsS[i] = redoPtwlepHist(h_ori_WjetsS[i]);
	    h_WjetsEWKS[i] = redoPtwlepHist(h_ori_WjetsEWKS[i]);
	    h_ZjetsS[i] = redoPtwlepHist(h_ori_ZjetsS[i]);
	    h_dibosonS[i] = redoPtwlepHist(h_ori_dibosonS[i]);
	    h_singleTopS[i] = redoPtwlepHist(h_ori_singleTopS[i]);
	    h_ttbarS[i] = redoPtwlepHist(h_ori_ttbarS[i]);
	    h_sigSMS[i] = redoPtwlepHist(h_ori_sigSMS[i]);
	  }
	} else if (typeName[itype] == "mjjTagged"){
	  h_data = redoMjjTagHist(h_ori_data);
	  h_Wjets = redoMjjTagHist(h_ori_Wjets);
	  h_WjetsScaled = redoMjjTagHist(h_ori_WjetsScaled);
	  h_WjetsEWK = redoMjjTagHist(h_ori_WjetsEWK);
	  h_Zjets = redoMjjTagHist(h_ori_Zjets);
	  h_diboson = redoMjjTagHist(h_ori_diboson);
	  h_singleTop = redoMjjTagHist(h_ori_singleTop);
	  h_ttbar = redoMjjTagHist(h_ori_ttbar);
	  h_qcd = redoMjjTagHist(h_ori_qcd);
	  h_sigSM = redoMjjTagHist(h_ori_sigSM);
	  
	  h_ttbarMCatNLO = redoMjjTagHist(h_ori_ttbarMCatNLO);
	  h_ttbarPowHer = redoMjjTagHist(h_ori_ttbarPowHer);
	  h_ttbarAcerMCUp = redoMjjTagHist(h_ori_ttbarAcerMCUp);
	  
	  h_Wjetsfac = redoMjjTagHist(h_ori_Wjetsfac);
	  h_Wjetsrenorm = redoMjjTagHist(h_ori_Wjetsrenorm);
	  h_Wjetsckkw = redoMjjTagHist(h_ori_Wjetsckkw);
	  
	  h_Wjetsfac025 = redoMjjTagHist(h_ori_Wjetsfac025);
	  h_Wjetsrenorm025 = redoMjjTagHist(h_ori_Wjetsrenorm025);
	  h_Wjetsckkw15 = redoMjjTagHist(h_ori_Wjetsckkw15);
	  
	  for (int i=0;i<nsyst;i++){
	    h_WjetsS[i] = redoMjjTagHist(h_ori_WjetsS[i]);
	    h_WjetsEWKS[i] = redoMjjTagHist(h_ori_WjetsEWKS[i]);
	    h_ZjetsS[i] = redoMjjTagHist(h_ori_ZjetsS[i]);
	    h_dibosonS[i] = redoMjjTagHist(h_ori_dibosonS[i]);
	    h_singleTopS[i] = redoMjjTagHist(h_ori_singleTopS[i]);
	    h_ttbarS[i] = redoMjjTagHist(h_ori_ttbarS[i]);
	    h_sigSMS[i] = redoMjjTagHist(h_ori_sigSMS[i]);
	  }
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
	
	for (int i=0;i<nsyst;i++){
	  doVariableBinHisto(h_WjetsS[i]);
	  doVariableBinHisto(h_WjetsEWKS[i]);
	  doVariableBinHisto(h_ZjetsS[i]);
	  doVariableBinHisto(h_dibosonS[i]);
	  doVariableBinHisto(h_singleTopS[i]);
	  doVariableBinHisto(h_ttbarS[i]);
	  doVariableBinHisto(h_sigSMS[i]);
	}

	// */
	// /*
	int rebin=1;
      	if (typeName[itype] == "mjjTagged") rebin =2;
	
	
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

	lowestBinWidth*=rebin;


	// */
	

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
	float ratio_size = 0.35 ;
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
	
		
	hs->Draw("hist");
    

	//hs->SetTitle(Form("%s_%s_%s",cutName[icut].Data(), typeName[itype].Data()) );
	//std::cout<<Form("%s_%s", cutName[icut].Data(), typeName[itype].Data())<<endl;
	
	hs->SetTitle("");
	TString GeV="GeV";
	if (typeName[itype].Contains("bosonCentrality")||typeName[itype].Contains("cosThetaWDecay") || typeName[itype].Contains("VVptBalance")  ) { GeV ="";}

	///
	
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
	
		
	setStackStyle (hs);

	//hs->GetYaxis()->SetNdivisions(210); //&&&&

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
	
	if (DEBUG){
	cout<<"h_Wjets ->"<<h_Wjets->Integral()<<endl;
	cout<<"h_WjetsEWK ->"<<h_WjetsEWK->Integral()<<endl;
	cout<<"h_WjetsScaled ->"<<h_WjetsScaled->Integral()<<endl;
	cout<<"h_ttbar ->"<<h_ttbar->Integral()<<endl;
	cout<<"h_Zjets ->"<<h_Zjets->Integral()<<endl;
	cout<<"h_singleTop ->"<<h_singleTop->Integral()<<endl;
	cout<<"h_diboson ->"<<h_diboson->Integral()<<endl;
	cout<<"h_sigSM ->"<<h_sigSM->Integral()<<endl;
	cout<<"h_qcd ->"<<h_qcd->Integral()<<endl;
	}
	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// std::cout<<"KolmogorovTest result= "<<ks<<endl;
	
	std::cout<<"===="<<Form("%s_%s", cutName[icut].Data(),typeName[itype].Data())<<": h_MC->Integral() = "<<h_MC->Integral()<<endl;
	
	

	// double xstart=h_data->GetBinLowEdge(1);
	// double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);

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
	

	if (typeName[itype].Contains("bosonCentrality") ){  //&&&&
	  h_data->GetXaxis()->SetRangeUser(-2,4);
	  hs->GetXaxis()->SetRangeUser(-2,4);
	}
	
	double maxi = hs->GetMaximum();
        double tmp = h_data->GetBinContent(h_data->GetMaximumBin());
        if (maxi < tmp) maxi =tmp;

        hs->SetMaximum(maxi *2.);
        if (logy)hs->SetMaximum( maxi *200.);
        if (typeName[itype].Contains("mjjTagged") && !cutName[icut].Contains("fatOnly") ){
	  hs->SetMinimum(1); //resolved mjjTagged
	} else {
	  hs->SetMinimum(1.e-1); //&&&&+ resolved ptwlep and both fat
	}
	//hs->SetMinimum(1.e-3);

        //hs->Draw("hist");

	h_data->Draw("same");


 
      
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
	leg->AddEntry(h_singleTop,"Single-top","f");
	leg->AddEntry(h_diboson,"Diboson","f");
	leg->AddEntry(h_Zjets,"Z+jets","f");
	leg->AddEntry(h_qcd,"Multijet","f");
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
	  //ymax *= 4.; //fat ptwlep //&&&&
	  ymax *= 1.5; //resolved ptwlep
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
	ar1->SetLineWidth(2);
	ar1->SetLineColor(kRed+1);
	ar1->SetFillColor(kRed+1);

	if(dovertline) ar1->Draw();
	///
      
	  
	p2->cd();
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h_data->Clone();
	ratioHist->Divide(h_MC);
	if ( typeName[itype].Contains("Mwjj") && ( cutName[icut].Contains("FJ") || cutName[icut].Contains("fatOnly") )) { ratioHist->GetXaxis()->SetTitle("M(J) [GeV]");}
	if ( typeName[itype].Contains("VVptBalance") ) { ratioHist->GetXaxis()->SetTitle("A_{WV} ");}
	if ( typeName[itype].Contains("cosThetaWDecay") ) { ratioHist->GetXaxis()->SetTitle("cos(#theta^{*}_{j}) ");}
	if ( typeName[itype].Contains("bosonCentrality") ) { ratioHist->GetXaxis()->SetTitle("Boson centrality");}

	setRatioPlotStyle (ratioHist);
	ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
	//ratioHist->GetYaxis()->SetRangeUser(0.5, 1.7);
	
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

	  //if ( typeName[itype].Contains("mTWV") )getHighestDeviationForSyst(h_MCN,h_MCS[i]);
	}

	
      
	TH1F* hSystBandHi = (TH1F*)ratioHist->Clone("hdataMCratio");
	//TH1D* hSystBandLo = (TH1D*)ratioHist->Clone("hdataMCratio");

	gStyle->SetHatchesLineWidth(1);
	gStyle->SetHatchesSpacing(0.8);
	
	hSystBandHi->SetMinimum(0.01);
	hSystBandHi->SetMaximum(2.5);   //&&&&
	//hSystBandHi->SetMaximum(5.);   //&&&&
        //hSystBandHi->SetMinimum(0.5);
        // hSystBandHi->SetMaximum(1.5);

	
	setBandStyle(hSystBandHi);
	
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
	      fracErr+=pow((h_MCN->GetBinContent(ibin)-h_MCS[i]->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
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
	    
	    fracErr += pow( h_Wjets->GetBinContent(ibin)*0.18/h_MCN->GetBinContent(ibin) , 2); //W+jets SF uncertainty (18%)
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
	      //fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsfac->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //W+jets scale uncertainty
	      //fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsrenorm->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsckkw->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsfac025->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsrenorm025->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	      //fracErrWjetsMod+=pow((h_Wjets->GetBinContent(ibin)-h_Wjetsckkw15->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    
	    // */
	    fracErr+=fracErrWjetsMod;
	    //cout<<"W+jets syst --> "<<sqrt(fracErrWjetsMod)<<endl;
	    // /*
	    
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarMCatNLO->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2); //ttbar theoretical uncertainty
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarPowHer->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);
	    fracErrTtbarMod+=pow((h_ttbar->GetBinContent(ibin)-h_ttbarAcerMCUp->GetBinContent(ibin))/h_MCN->GetBinContent(ibin),2);

	    fracErr+=fracErrTtbarMod;
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
	
	if ( typeName[itype].Contains("Mwjj") && ( cutName[icut].Contains("FJ") || cutName[icut].Contains("fatOnly") )){
	  horiz_line->DrawLine(45.,1.0,140.,1.0);
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
	  c2->Print("plots_syst_band_fatOnly_smoothed.pdf",Form("Title:%s_%s",cutName[icut].Data(), typeName[itype].Data()));
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


    
   
  if (!pdfforNote) c2->Print("plots_syst_band_fatOnly_smoothed.pdf]");
}

