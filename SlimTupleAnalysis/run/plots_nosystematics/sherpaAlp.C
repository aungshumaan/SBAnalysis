{
  //=========Macro generated from canvas: c1/c1
  //=========  (Sat Jun  7 21:43:18 2014) by ROOT version5.34/18

  ///this code was originally for comparing Alpgen and sherpa samples (or powheg and mcnlo). It can be used to compare any two files
#include <TLatex.h>
  bool DEBUG =false;
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_sherpaAlp.pdf[","pdf");

#include "rebin.h"
#include "stackStyle.h"
#include "doVariableBinHisto.h"
#include "makerHelper.h"
  

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_WV_MCatNLO.caf4.2.lv4_NEWcutflow.root"); //no reweighting
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WV_m0p3_1p0_0p3_rw.caf4.2.lv4_NEWcutflow.root"); //reweighted to aTGC points
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WV_SM_rw.caf4.2.lv4.4_NEWcutflow.root"); //reweighted to SM
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WV_0_0_0p3_rw.caf4.2.lv4.4_NEWcutflow.root"); //reweighted to aTGC point (0.1,0,0)
  
  
  //TFile *f1=TFile::Open("../hwwlvqq.185722.CST.root");
  //TFile *f2=TFile::Open("../hwwlvqq.185722.TST.root");

  //TFile *f1=TFile::Open("../fakeEstimation/lvqqNoMetSignalRegion.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass.root");
  
  //TFile *f1=TFile::Open("../hwwlvqq.185726.Nominal.root");
  //TFile *f2=TFile::Open("../hwwlvqq.185726.JMSUp.root");
  //TFile *f3=TFile::Open("../hwwlvqq.185726.JMSDown.root");
  //TFile *f2=TFile::Open("../hwwlvqq.185726.FatJPTRUp.root");
  //TFile *f3=TFile::Open("../hwwlvqq.185726.FatJMRUp.root");
  
   /*
  TFile *f1=TFile::Open("../hwwlvqq.Nominal_new.ttbar.root");
  TFile *f2=TFile::Open("../hwwlvqq.JMSUp_old.ttbar.root");
  TFile *f3=TFile::Open("../hwwlvqq.JMSUp_new.ttbar.root");
  //TFile *f2=TFile::Open("../hwwlvqq.FatJPTRUp_new.ttbar.root");
  //TFile *f3=TFile::Open("../hwwlvqq.FatJMRUp_new.ttbar.root");
   */
  //////////////////////////
  //TFile *f1=TFile::Open("../hwwlvqq.Nominal.ttbar.lv4_fmw40_140_mjjT0.root");
  //TFile *f2=TFile::Open("../hwwlvqq.JMSUp.ttbar.lv4_fmw40_140_mjjT0.root");
  //TFile *f3=TFile::Open("../hwwlvqq.JMSDown.ttbar.lv4_fmw40_140_mjjT0.root");
  /////////////////////////////

  //TFile *f1=TFile::Open("../hwwlvqq_njet0.root");
  //TFile *f1=TFile::Open("../HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst/hwwlvqq.Nominal.small.root");
  //TFile *f2=TFile::Open("../fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW_10.root");
  //TFile *f2=TFile::Open("../hwwlvqq.root");
  //TFile *f2=TFile::Open("../hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_cutflow.root");
  
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_bchNom.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_bchUp.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.bJESUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.Nominal.small.root");

  
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_nocutAwv.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_nocutAwv/hwwlvqq.JERUp.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_smw_MjjTag200/hwwlvqq.Nominal.caf4.2.lv4_smw_MjjTag200.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_smw_MjjTag200/hwwlvqq.FatJESUp.root");

  
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass_old/hwwlvqq.Nominal.small.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.FatJESUp.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.JMSUp.root");
  
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.FatJESUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.JMSUp.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass_old/hwwlvqq.FatJESUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.FatJESUp.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass_old/hwwlvqq.JMSUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.JMSUp.root");
  

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.ttbar.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.FatJESUp.ttbar.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.JMSUp.ttbar.root");
  
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.ttbar_nofatptcut.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.FatJESDown.ttbar_nofatptcut.root");
  //TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.JMSDown.ttbar_nofatptcut.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.FatJESDown.ttbar_nofatptcut.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.JMSDown.ttbar_nofatptcut.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.FatJESUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.JMSUp.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_ttbar.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_10_April30/hwwlvqq.JERUp.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst_lumi20.2/hwwlvqq.JERUp.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_smw_10_April30/lvqqCombQCD_plots.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK_WjetsSF0.82.root");

  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_10_April30/lvqqCombQCD_plots.root");
  //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185721.April30.root");
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185726.noPRW.root");
  TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185726.PRW.root");
  
  //  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW/hwwlvqq.WjetsTruthSyst.root");
  
  //const int nSample =6; TString sampleName[nSample] = {"Data", "Wjets", "Zjets" ,"Ttbar","SingleTop", "WZZZWg"};
  //const int nSample =7; TString sampleName[nSample] = {"Data","QCD","Wjets", "Zjets" ,"Ttbar","SingleTop", "WZZZWg"};
  //const int nSample =9; TString sampleName[nSample] = {"Data","QCD","Wjets", "WjetsEWKSherpa", "WjetsScaled","Zjets" ,"Ttbar","SingleTop", "WZZZWg"};
  //const int nSample =1; TString sampleName[nSample] = {"Zjets"};
  //const int nSample =3; TString sampleName[nSample] = {"Wjets","Zjets","WZZZWg"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","WW","WZ"};
  const int nSample =1; TString sampleName[nSample] = {"VBS_WV_01_0"};
  //const int nSample =2; TString sampleName[nSample] = {"Zjets","Wjets"};
  //const int nSample =6; TString sampleName[nSample] = { "WjetsInc","Wjets_40","Wjets_70","Wjets_140","Wjets_280","Wjets_500"};

  //const int nRegion =3; TString regionName[nRegion] = {"STARTPOINT","LooseMjjTag","JetSelectResolve"};
  //const int nRegion =3; TString regionName[nRegion] = {"LooseMjjTag","SR","SRfatOnly"};
  //const int nRegion =5; TString regionName[nRegion] = {"LooseMjjTag","CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  //const int nRegion =3; TString regionName[nRegion] = {"LooseMjjTag","SRFJ","SRfatOnly"};
  //const int nRegion =6; TString regionName[nRegion] = {"STARTPOINT","LooseMjjTag","CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  //const int nRegion =1; TString regionName[nRegion] = {"LooseVBSfatOnly"};
  //const int nRegion =1; TString regionName[nRegion] = {"JetSelectFat"};
  //const int nRegion =3; TString regionName[nRegion] = {"JetSelectFat","LooseVBSfatOnly","CR_TopFJ"};
  //const int nRegion =1; TString regionName[nRegion] = {"SR"};
  //const int nRegion =1; TString regionName[nRegion] = {"SRFJ"};
  // const int nRegion =2; TString regionName[nRegion] = {"CR_TopFJ","SRFJ"};
  //const int nRegion =5; TString regionName[nRegion] = {"JetSelectResolve","LooseVBSResolved","CR_Top","CR_Wjj","SR"};
  //const int nRegion =2; TString regionName[nRegion] = {"STARTPOINT","PRESELECT"};
  //const int nRegion =7; TString regionName[nRegion] = {"STARTPOINT","PRESELECT","JetSelectResolve","LooseVBSResolved", "CR_Top","CR_Wjj","SR"};
  //const int nRegion =4; TString regionName[nRegion] = {"STARTPOINT","OneLep","TwoLep","Njet0"};
  //const int nRegion =3; TString regionName[nRegion] = {"STARTPOINT","JetSelectResolve","SR"};
  //const int nRegion =3; TString regionName[nRegion] = {"SR","SR0tag","SR1tag"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_Top","CR_TopfatOnly","SR","SRfatOnly"};
  const int nRegion =6; TString regionName[nRegion] = {"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  //const int nRegion =8; TString regionName[nRegion] = {"LooseVBSResolved","LooseVBSfatOnly", "CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  //const int nRegion =4; TString regionName[nRegion] = {"LooseVBSfatOnly", "CR_TopFJ","CR_WjjFJ","SRFJ"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  //const int nRegion =3; TString regionName[nRegion] = {"CR_Top0tag","CR_Top1tag","CR_Top2tag"};
  //const int nRegion =3; TString regionName[nRegion] = {"CR_Top","CR_Wjj","SR"};

  //const int nPoint =1; TString pointName[nPoint] = {"WV_0_0"};
  //const int nPoint =3; TString pointName[nPoint] = {"WV_0_0","WV_0_02","WV_03_0"};

  //const int nFlavor =1; TString flavorName[nFlavor] = { "m"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};
  //const int nFlavor =4; TString flavorName[nFlavor] = {"ep","em", "mp","mm"};
  const int nFlavor =2; TString flavorName[nFlavor] = {"ep","mp" };

  //const int nHist =2 ;TString histName[nHist]={"dPhilepMET","MET_et"};
  //const int nHist =2 ;TString histName[nHist]={"Njet","MET_et"};
  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist =2 ;TString histName[nHist]={"fatjet_pt","fatjet_M"};
  //const int nHist =3 ;TString histName[nHist]={"fatjet_pt","fatjet_eta", "fatjet_M"};
  //const int nHist =4 ;TString histName[nHist]={"mTWV","fatjet_pt","fatjet_eta", "fatjet_M"};
  
  //////const int nHist =8 ;TString histName[nHist]={"lep_pt","MET_et","MET_ST_et","MET_jet_et", "dPhilepMET","mT","mjjTagged","mTWV"};
  //////const int nHist =10 ;TString histName[nHist]={"MET_et","MET_phi","MET_ST_et","MET_ST_phi","MET_jet_et", "MET_jet_phi","MET_jetST_et","dPhilepMET","mT","mTWV"};
  //const int nHist =13 ;TString histName[nHist]={"lep_pt","MET_et","mjjTagged","ptwlep","ptwjj","Mwjj","mTWV","Mlvjj","vbfjet1_eta","cosThetaWDecay","cosThetaWlep", "bosonCentrality","VVptBalance"}; 
  //const int nHist =4 ;TString histName[nHist]={"MET_et","vbfjet1_pt","Mwjj","Mlvjj"};
  //const int nHist =7 ;TString histName[nHist]={"lep_pt","MET_et","mjjTagged","ptwlep","Mwjj","Mlvjj","mT"};

  //const int nHist =27;TString histName[nHist]={"Njet","Mlvjj","Mwjj","ptlvjj","ptwjj","mT","mjjTagged","ptjjTagged","dEtaTaggedJets","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptwlep","ptBalance","etaX","etaY","cosThetaWDecay","cosThetaWlep","lep_pt","MET_et","dRWjets","lepCentrality", "bosonCentrality","mTWV","VVptBalance","VVvecptdiff"};
  //const int nHist=13;TString histName[nHist]={"mjjTagged","ptwlep","ptwjj","Mwjj","Mlvjj","vbfjet1_eta","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVvecptdiff","VVptBalance"};
  //const int nHist=7;TString histName[nHist]={"mTWV","mjjTagged","ptwjj","Mwjj","Mlvjj","ptwlep","MET_et"};

  bool doThree = 0;
  for (int iRegion=0;iRegion<nRegion;iRegion++){	  
  for (int iHist=0;iHist<nHist;iHist++){
    for (int iSample=0;iSample<nSample;iSample++){
      
      for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){

	TH1F* h1=(TH1F*)f1->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	TH1F* h2=(TH1F*)f2->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	if (doThree )TH1F* h3=(TH1F*)f3->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );

	//TH1F* h1=(TH1F*)f1->Get(Form("H_Ttbar_%s_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	//TH1F* h2=(TH1F*)f1->Get(Form("H_TtbarAcerMCDown_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  

	  //TH1F* h1=(TH1F*)f1->Get(Form("H_Wjets_%s_WBF_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH1F* h2=(TH1F*)f1->Get(Form("H_TruthWjetsrenorm4_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH1F* h3=(TH1F*)f1->Get(Form("H_TruthWjetsrenorm025_%s_WBF_%s_%s",  flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );

      //TH1F* h1=(TH1F*)f1->Get(Form("H_%s_ep_WBF_%s_%s", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
      //h1->Add((TH1F*)f1->Get(Form("H_%s_em_WBF_%s_%s", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
      //TH1F* h2=(TH1F*)f1->Get(Form("H_%s_mp_WBF_%s_%s", sampleName[iSample].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
      //h2->Add((TH1F*)f1->Get(Form("H_%s_mm_WBF_%s_%s", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	  
	  int rebin =1;
	  int rebinFac =1;
	  
	  if (!(histName[iHist].Contains("Njet"))){
	    //if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	    
	    rebinFac = getRebinFactor(histName[iHist]);
	    rebin *=rebinFac;
	    
	    
	    //h1->Rebin(rebin);
	    //h2->Rebin(rebin);
	    //if (doThree ) h3->Rebin(rebin);
	    	    
	  }

	  AddOverflowBinToLastBin(h1);
	  AddOverflowBinToLastBin(h2);
	  if (doThree ) AddOverflowBinToLastBin(h3);
     
	  doVariableBinHisto(h1);
	  doVariableBinHisto(h2);
	  if (doThree )doVariableBinHisto(h3);
	  
	  bool logy=false;
	  
	  //double padRatio =0.01;// just p1
	  double padRatio =0.35;
	  TPad* p1 = new TPad("p1","p1",0.01, padRatio ,0.99,0.99);
	  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, padRatio);
	  p1->Draw();
	  p2->Draw();
	  p1->cd();
	  if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("mTWV") || histName[iHist].Contains("MET_et") ||  histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") ){
	    logy = true;
	  }
	  logy = false;
	  // cout<<logy<<endl;
	  p1->SetLogy(logy); 

	  //cout<<"Hello!!"<<endl;
	  h1->SetLineColor(kBlack);
	  //h1->Scale(1/h1->Integral());
	  
	  //h1->SetTitle(Form("%s_%s_%s", flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  //h1->SetTitle(Form("%s_%s_%s", sampleName[iSample].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	 
	  h1->Draw();
	  if (histName[iHist].Contains("MET_et"))h1-> GetXaxis()->SetRangeUser( 0,200 );
	  //if (histName[iHist].Contains("fatjet_pt") )h1-> GetXaxis()->SetRangeUser( 200,500 ); //&&&&
	  //if (histName[iHist].Contains("fatjet_pt") )h1-> GetXaxis()->SetRangeUser( 0,500 ); //&&&&
   
	  h2->SetLineColor(kRed);
	  //h2->Scale(1/h2->Integral());
	  //h2->Scale(h1->Integral()/h2->Integral());
	  h2->Draw("same");

	  // /*
	  if (doThree ) {
	    h3->SetLineColor(kBlue);
	  //h3->Scale(1/h2->Integral());
	  h3->Draw("same");
	  }
	  //  */
	  
	  Double_t ks= h1->KolmogorovTest(h2);
	  TLatex lat; //l.SetTextAlign(12); 
	  lat.SetTextSize(0.04); 
	  lat.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	  lat.SetTextColor(1);
	  //lat.DrawLatex(0.2,0.87,Form("KS %f",ks));
	  
	  
	  
	  
	  double maxi= h1->GetBinContent(h1->GetMaximumBin());
	  if (maxi <h2->GetBinContent(h2->GetMaximumBin())){
	    maxi=h2->GetBinContent(h2->GetMaximumBin());
	  }
	  // /*
	  if (doThree ){
	  if (maxi <h3->GetBinContent(h3->GetMaximumBin())){
	     maxi=h3->GetBinContent(h3->GetMaximumBin());
	   }
	  }
	  //   */
	  if (logy)
	    {h1->SetMaximum(maxi*100);}
	  else
	    {h1->SetMaximum(maxi*1.5);}
     
	  TLegend *l=new TLegend(0.6,0.75,0.9,0.9);
	  
	  l.SetTextSize(0.03);
	  
	  //l->AddEntry(h1,"Nominal","l");
	  //l->AddEntry(h2,"syst","l");

	  l->AddEntry(h1,"no PRW","l");
	  l->AddEntry(h2,"PRW","l");

	  //l->AddEntry(h1,"Powheg+Pythia ttbar","l");
	  //l->AddEntry(h2,"AcerMC up ttbar","l");
	  //l->AddEntry(h2,"AcerMC down ttbar","l");

	  //l->AddEntry(h1,"W+jets nominal ","l");
	  //l->AddEntry(h2,"W+jets renorm 4","l");
	  //l->AddEntry(h3,"W+jets renorm 0.25","l");

	  //l->AddEntry(h1,"Nominal ","l");
	  //l->AddEntry(h1,"JPTS Up old","l");
	  //l->AddEntry(h2,"JPTS Up new","l");

	  //l->AddEntry(h1,"JMS Up old","l");
	  //l->AddEntry(h2,"JMS Up new","l");

	  //l->AddEntry(h1,"no cut on Njet ","l");
	  //l->AddEntry(h2,"Njet >=2","l");
	  //if (doThree ) l->AddEntry(h3,"JMS Down ","l");
	  
	  //l->AddEntry(h1,"electron ","l");
	  //l->AddEntry(h2,"muon ","l");
	  
	  
	  
     
	  l->Draw();

	  double xstart=h1->GetBinLowEdge(1);
	  double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);


	  
	  p2->cd();
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist = (TH1F*)h2->Clone();
	  ratioHist->Divide(h1);
	  if (histName[iHist].Contains("MET_et"))ratioHist-> GetXaxis()->SetRangeUser( 0,200 );
	  //if (histName[iHist].Contains("fatjet_pt") )ratioHist-> GetXaxis()->SetRangeUser( 200,500 ); //&&&&
	  //if (histName[iHist].Contains("fatjet_pt") )ratioHist-> GetXaxis()->SetRangeUser( 0,500 ); //&&&&
	  ratioHist->GetYaxis()->SetRangeUser(0.3, 2.);
	  //ratioHist->GetYaxis()->SetRangeUser(0.8, 1.4);
	  //ratioHist->GetYaxis()->SetRangeUser(0.95, 1.05);
	  //ratioHist->GetYaxis()->SetRangeUser(0., 5.);
	  //double maxi2 = ratioHist->GetBinContent(ratioHist->GetMaximumBin()) < 10 ? ratioHist->GetBinContent(ratioHist->GetMaximumBin()): 10 ;
	  //ratioHist->GetYaxis()->SetRangeUser(0., 1.2 * maxi2 );
	  //ratioHist->GetYaxis()->SetRangeUser(0., 2.);
	  ratioHist->SetMarkerStyle(20);
	  setRatioPlotStyle (ratioHist);
	  ratioHist->SetMarkerColor(h2->GetLineColor());
	  ratioHist->Draw();
	  // /*
	  if (doThree ){
	  TH1F *ratioHist2 = (TH1F*)h3->Clone();
	  ratioHist2->Divide(h1);
	  //ratioHist2->GetYaxis()->SetRangeUser(0.3, 2.);
	  ratioHist2->GetYaxis()->SetRangeUser(0.7, 1.2);
	  //ratioHist2->GetYaxis()->SetRangeUser(0.95, 1.05);
	  //ratioHist2->GetYaxis()->SetRangeUser(0., 5.);
	  //ratioHist2->GetYaxis()->SetRangeUser(0., 2.);
	  ratioHist2->SetMarkerStyle(20);
	  setRatioPlotStyle (ratioHist2);
	  ratioHist2->SetMarkerColor(h3->GetLineColor());
	  ratioHist2->Draw("same");
	  }
	  //  */
	  ratioHist->SetTitle("ratio");

	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
   
	  //c1->Print("plots_sherpaAlp.pdf",Form("Title:%s",  histName[iHist].Data()));
	  //c1->Print("plots_sherpaAlp.pdf",Form("Title:%s_%s_%s", flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  c1->Print("plots_sherpaAlp.pdf",Form("Title:%s_%s_%s", sampleName[iSample].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  //c1->Print("plots_sherpaAlp.pdf",Form( "Title:%s_%s_%s_%s",sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data() ) );
	  
	  p1->Clear();
	  p2->Clear();
	  
	  c1->cd();

	  
	  }
	}
      }
  }
  //f1->Close();
  //f2->Close();
   
  c1->Print("plots_sherpaAlp.pdf]","pdf");
}
