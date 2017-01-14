// This is  -*- C++ -*-
#ifndef HISTRUN_H
#define HISTRUN_H


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std ;

class HistRun {

public :

  TH1F *PtLL ;
  TH1F *MLL ;
  TH1F *FineMLL ;
  TH1F *deltaPhi;
  TH1F *MET_et ;
  TH1F *MetRel ;
  TH1F *lep_pt;
  TH1F *lep_phi;
  TH1F *lep_eta;

  TH1F *elRelEtCone30;
  TH1F *elRelPtCone30;
  TH1F *log_elRelEtCone30;
  TH1F *log_elRelPtCone30;
  TH1F *MET_elRelPtCone30_lt02;
  TH1F *elz0sinth;
  TH1F *eld0sigd0;
  TH1F *muRelEtCone30;
  TH1F *muRelPtCone30;
  TH1F *log_muRelEtCone30;
  TH1F *log_muRelPtCone30;
  TH1F *MET_muRelPtCone30_lt02;
  TH1F *muz0sinth;
  TH1F *mud0sigd0;

  TH1F *mll;
  TH1F *ptll;
  TH1F *lep2_pt;


  TH1F *WT ;
  TH1F *Njet ;
  TH1F *Nfatjet ;

  TH1F *nJetsOverlapPh ;
  TH1F *METdiff ;
  TH1F *nTrueB ;
  TH1F *nTrueC ;

  TH1F *dRfatjetV;
  TH1F *truthMatchedfatjetM;
  TH1F *matchedDijetM;

  TH1F *trueVpt;
  TH1F *trueVptMatched;
  TH1F *trueVptDijetMatched;
  TH1F *trueVptDijetWjetMatched;
  TH1F *trueVeta;
  TH1F *trueVetaMatched;
  TH1F *trueVjMaxEta;
  TH1F *trueVjMinPt;
  TH1F *trueVjjDR;
  TH1F *trueVjjCosTh;
  TH1F *trueDeltaVVW;
  TH1F *trueDeltaVVZ;

  TH1F *runNumber;
  
  TH1F *MET_phi       ;

  TH1F *jet_emfrac;
  
  TH1F *jet1_pt       ;
  TH1F *jet1_eta      ;
  TH1F *jet1_phi      ;
  TH1F *jet1_CombNN   ;

  TH1F *jet2_pt       ;
  TH1F *jet2_eta      ;
  TH1F *jet2_phi      ;
  
  TH1F *jet3_pt       ;
  TH1F *jet3_eta      ;
  TH1F *jet3_phi      ;

  TH1F *jet4_pt       ;
  TH1F *jet4_eta      ;
  TH1F *jet4_phi      ;

  TH1F *Wjet1_pt       ;
  TH1F *Wjet2_pt       ;

  TH1F *fatjet_pt       ;
  TH1F *fatjet_eta      ;
  TH1F *fatjet_phi      ;
  TH1F *fatjet_M      ;

  TH1F *fatjetM_pt150      ;
  TH1F *fatjetM_pt200      ;
  TH1F *fatjetM_pt250      ;
  TH1F *fatjetM_pt300      ;
  

  //TH1F *dEtajj  ; 
  TH1F *Mjj     ;
  //TH1F *EtaJ1EtaJ2 ; 


  TH1F *NVertex ; 
  TH2F *MLL_METrel ;


  TH1F *TotalPt ; 


  TH1F *Mlvjj; //, *MlvjjWD;
  TH1F *Mwjj ; //, *MwjjWD ;

  TH1F *ptlvjj; 
  TH1F *ptwjj ; 

  TH1F *mT ;
  TH1F *mjjTagged ;
  TH1F *ptjjTagged ;
  TH1F *vbfjet1_pt;
  TH1F *vbfjet2_pt;
  TH1F *vbfjet1_eta;
  TH1F *vbfjet2_eta;
  TH1F *vbfjet1_phi;
  TH1F *vbfjet2_phi;
  TH1F *vbfjets_etaProduct;
  TH1F *dEtaMax;
  TH1F *ptjjMax;
  TH1F *min_dEta_Wlepjet;//dEta between Wlep and the closest jet
  TH1F *min_dR_lepjet;//dR between the lepton and the closest jet
  TH1F *min_dR_lepfatjet;//dR between the lepton and the closest fatjet
  TH1F *min_dR_FJ_jet;//dR between the fatjet and the closest jet
  TH1F *dR_FJ_jets;
  TH1F *dRlepFJ;
  ///signal truth investigation
  TH1F *dR_lepTrueLep;
  TH1F *dPhi_METtrueNu;
  TH1F *pt_trueLep;
  TH1F *Et_trueNu;
  TH1F *pt_lepTrueLep;
  TH1F *Et_METtrueNu;
  TH1F *dPhilv_true;
  TH1F *mT_true;
  TH1F *mlv_true;

  ///
  TH1F *AvgPt_Wjets;
  TH1F *ptwlep;
  TH1F *ptBalance;
  TH1F *VVptBalance;
  TH1F *VVptSum;
  TH1F *VVvecptdiff;
  TH1F *mTWV;
  TH1F *diff_ptww_ptjjTagged;
  TH1F *sumPt;
  TH1F *diff_etawjj_avgEtaTagged;//etaWjj
  TH1F *etaX;
  TH1F *etaY;
  TH1F *lepCentrality;
  TH1F *bosonCentrality;
  TH1F *dEtaTaggedJets;
  TH1F *dPhiTaggedJets;
  TH1F *dRTaggedJets;
  TH1F *dEtaWjets;
  TH1F *dPhiWjets;
  TH1F *cosThetaWlep;

  TH1F *diffptwj1ptwj2;
  TH1F *cosThetaWDecay;
  TH1F *cosDPhiwjjwlep;
  TH1F *dRvbfwwaxes;
  TH1F *dEtavbfwwaxes;
  TH1F *dPhivbfwwaxes;  


  TH1F *dPhilepMET;
  TH1F *dRWjets;
  TH1F *mass_lnuj0;
  TH1F *mass_j0j1j2;
  TH1F *mT_dPhilepMET_lt14;
  TH1F *mT_dPhilepMET_gt14;
  TH1F *mT_ptwlep_lt50;
  TH1F *mT_ptwlep_50_100;
  TH1F *mT_ptwlep_100_150;
  TH1F *mT_ptwlep_gt150;
  TH2F *mT_ptwlep; //2D histogram of mT and ptwlep
  
  TH1F *ttbarWeight;
  TH2F *ptwjj_ptwlep; //2D histogram of ptwjj and ptwlep
  TH2F *mTWV_Mlvjj;
  TH2F *mTWV_VVvecptdiff;
  TH2F *mTWV_ptwlep; //2D histogram of mT and ptwlep
  TH2F *mjjTagged_MET ; 
  
  TH1F *MV1;

  
  TH1F *topRWEventWeight;
  TH1F *wjetsRWEventWeight;
  TH1F *mcEventWeight;
  TH1F *EventWeight;
  
  HistRun(TString Name, bool reduced ) { 

    TH1::SetDefaultSumw2();
    
    
    
    //Mlvjj         = new TH1F(Name+"_Mlvjj",   Name+"_Mlvjj", 150,  0., 1500.); //You have to give the first part of the histName, e.g. H_Top_em_WBF_CR_Top

    Float_t bins_mlvjj[]= {0.,50.,100.,150.,200.,250.,300.,350.,400.,450.,500.,550.,600.,700.,800.,900.,1000.,1250.,1500.,1750.,2000.};
    Int_t binnum_mlvjj = sizeof(bins_mlvjj)/sizeof(Float_t) -1;
    Mlvjj         = new TH1F(Name+"_Mlvjj",   Name+"_Mlvjj", binnum_mlvjj, bins_mlvjj);
    Mlvjj -> GetXaxis()->SetTitle("M(l#nujj) [GeV]");
    
    Mwjj          = new TH1F(Name+"_Mwjj",    Name+"_Mwjj",  40,  0., 200.);
    Mwjj -> GetXaxis()->SetTitle("M_{jj}(W) [GeV]");

 

    //ptlvjj         = new TH1F(Name+"_ptlvjj",   Name+"_ptlvjj", 60,  0., 600.);
    Float_t bins_ptlvjj[]= {0.,50.,100.,150.,200.,250.,300.,350.,400.,450.,500.,550.,600.,700.,800.,900.,1000.,1250.,1500.};
    Int_t binnum_ptlvjj = sizeof(bins_ptlvjj)/sizeof(Float_t) -1;
    ptlvjj         = new TH1F(Name+"_ptlvjj",   Name+"_ptlvjj", binnum_ptlvjj, bins_ptlvjj );
    ptlvjj -> GetXaxis()->SetTitle("p_{T}(l#nujj) [GeV]");
    
    //ptwjj          = new TH1F(Name+"_ptwjj",    Name+"_ptwjj",  80,  0., 800.);
    Float_t bins_ptwjj[]= {0.,50.,100.,150.,200.,250.,300.,400.,600.,800.,1000.};
    Int_t binnum_ptwjj = sizeof(bins_ptwjj)/sizeof(Float_t) -1;
    ptwjj          = new TH1F(Name+"_ptwjj",    Name+"_ptwjj",  binnum_ptwjj, bins_ptwjj ); //variable bin width
    ptwjj -> GetXaxis()->SetTitle("p_{T}(W(jj)) [GeV]");
    
    mT              = new TH1F(Name+"_mT",   Name+"_mT", 30, 0., 150.);
    mT -> GetXaxis()->SetTitle("m_{T} [GeV]");
    
    //mjjTagged              = new TH1F(Name+"_mjjTagged",   Name+"_mjjTagged", 75, 0., 3000.);
    Float_t bins_mjjtag[]= {0.,50.,100.,150.,200.,250.,300.,350.,400.,450.,500.,550.,600.,700.,800.,900.,1000.,1100.,1200.,1300.,1400.,1500.,1600.,1700.,1800.,1900.,2000.,2250.,2500.,2750.,3000. };
    Int_t binnum_mjjtag = sizeof(bins_mjjtag)/sizeof(Float_t) -1;
    mjjTagged              = new TH1F(Name+"_mjjTagged",   Name+"_mjjTagged", binnum_mjjtag  , bins_mjjtag );
    mjjTagged -> GetXaxis()->SetTitle("m_{jj}(tagging) [GeV]");

    ptjjTagged              = new TH1F(Name+"_ptjjTagged",   Name+"_ptjjTagged", 40, 0., 400.);
    ptjjTagged -> GetXaxis()->SetTitle("p_{T,jj}(tagging) [GeV]");
    dEtaTaggedJets= new TH1F(Name+"_dEtaTaggedJets",   Name+"_dEtaTaggedJets", 40,0.,8.);
    dEtaTaggedJets -> GetXaxis()->SetTitle("#Delta#eta_{jj}(tagging) ");

    vbfjet1_pt              = new TH1F(Name+"_vbfjet1_pt",   Name+"_vbfjet1_pt", 60, 0., 600.);
    vbfjet1_pt -> GetXaxis()->SetTitle("tagging jet1 p_{T} [GeV]");
    vbfjet2_pt              = new TH1F(Name+"_vbfjet2_pt",   Name+"_vbfjet2_pt", 60, 0., 600.);
    vbfjet2_pt -> GetXaxis()->SetTitle("tagging jet2 p_{T} [GeV]");
    vbfjet1_eta              = new TH1F(Name+"_vbfjet1_eta",   Name+"_vbfjet1_eta", 20, -5., 5.);
    vbfjet1_eta -> GetXaxis()->SetTitle("tagging jet1 #eta");
    vbfjet2_eta              = new TH1F(Name+"_vbfjet2_eta",   Name+"_vbfjet2_eta", 20, -5., 5.);
    vbfjet2_eta -> GetXaxis()->SetTitle("tagging jet2 #eta");
    
    //ptwlep = new TH1F(Name+"_ptwlep",   Name+"_ptwlep", 80, 0., 800.);
    ptwlep = new TH1F(Name+"_ptwlep",   Name+"_ptwlep", binnum_ptwjj, bins_ptwjj ); //variable bin width, same as ptwjj
    ptwlep -> GetXaxis()->SetTitle("p_{T} (W#rightarrow l#nu) [GeV]");
    
    ptBalance = new TH1F(Name+"_ptBalance",   Name+"_ptBalance", 50, 0., 0.5);
    ptBalance -> GetXaxis()->SetTitle("p_{T} balance(l#nu + diwjets+divbfjets) [GeV]");
     
    VVptBalance = new TH1F(Name+"_VVptBalance",   Name+"_VVptBalance", 100, 0., 1.0);
    VVptBalance -> GetXaxis()->SetTitle("p_{T} balance(l#nu + diwjets) [GeV]");
    
    VVptSum = new TH1F(Name+"_VVptSum",   Name+"_VVptSum", 150, 0., 1500.);
    VVptSum -> GetXaxis()->SetTitle("p_{T}(W#rightarrowl#nu)+ p_{T}(W#rightarrowjj) [GeV]");
    
    VVvecptdiff = new TH1F(Name+"_VVvecptdiff",   Name+"_VVvecptdiff", 150, 0., 1500.);
    VVvecptdiff -> GetXaxis()->SetTitle("p_{T} (diwjets - leptonic W) [GeV]");
    
    mTWV = new TH1F(Name+"_mTWV",   Name+"_mTWV", 150, 0., 1500.);
    mTWV -> GetXaxis()->SetTitle("m_{T} (diwjets, leptonic W) [GeV]");
    
    etaX= new TH1F(Name+"_etaX",   Name+"_etaX", 35,-2.,5.);
    etaX -> GetXaxis()->SetTitle("etaX");
    
    etaY= new TH1F(Name+"_etaY",   Name+"_etaY", 35,-2.,5.);
    etaY -> GetXaxis()->SetTitle("etaY");
    
    lepCentrality= new TH1F(Name+"_lepCentrality",   Name+"_lepCentrality", 75,-10.,5.);
    lepCentrality-> GetXaxis()->SetTitle("lepton centrality");
    
    bosonCentrality= new TH1F(Name+"_bosonCentrality",   Name+"_bosonCentrality", 75,-10.,5.);
    bosonCentrality-> GetXaxis()->SetTitle("boson centrality");
    
    cosThetaWDecay = new TH1F(Name+"_cosThetaWDecay",   Name+"_cosThetaWDecay", 20,0.0,1.0);
    cosThetaWDecay -> GetXaxis()->SetTitle("cos #theta* (W jet1, diwjets)");
    
    cosThetaWlep = new TH1F(Name+"_cosThetaWlep",   Name+"_cosThetaWlep", 40,-1.0,1.0);
    cosThetaWlep -> GetXaxis()->SetTitle("cos #theta* (lep, leptonic W)");

    lep_pt     = new TH1F(Name+"_lep_pt", Name+"_lep_pt"  , 50, 0., 500.);
    lep_pt->GetXaxis()->SetTitle("lepton p_{T} [GeV]");

    //MET_et        = new TH1F(Name+"_MET_et" ,Name+"_MET_et", 100, 0., 500.);
    Float_t bins_met[]= {0.,5.,10.,15.,20.,25.,30.,35.,40.,45.,50.,55.,60.,65.,70.,75.,80.,85.,90.,95.,100.,105.,110.,115.,120.,125.,130.,135.,140.,145.,150.,155.,160.,165.,170.,175.,180.,185.,190.,195.,200.,205.,210.,215.,220.,225.,230.,235.,240.,245.,250.,260.,270.,280.,290.,300.,325.,350.,375.,400.,425.,450.,475.,500.};
    Int_t binnum_met = sizeof(bins_met)/sizeof(Float_t) -1;
    MET_et        = new TH1F(Name+"_MET_et" ,Name+"_MET_et", binnum_met, bins_met  );//variable bin width
    MET_et -> GetXaxis()->SetTitle("MET [GeV]");

    Njet      = new TH1F(Name+"_Njet",Name+"_Njet" , 11, -0.5, 10.5 );
    Njet -> GetXaxis()->SetTitle("N_{Jet}");
    
    dRWjets= new TH1F(Name+"_dRWjets",   Name+"_dRWjets", 40,0.,8.);
    dRWjets -> GetXaxis()->SetTitle("#DeltaR(W-jets)");
    
    ptwjj_ptwlep= new TH2F (Name+"_ptwjj_ptwlep",   Name+"_ptwjj_ptwlep", 16, 0., 800., 16, 0., 800. );
    ptwjj_ptwlep-> GetXaxis()->SetTitle("p_{T}(W(jj)) [GeV]");
    ptwjj_ptwlep-> GetYaxis()->SetTitle("p_{T} (W#rightarrow l#nu) [GeV]");
    
    mTWV_Mlvjj = new TH2F (Name+"_mTWV_Mlvjj",   Name+"_mTWV_Mlvjj", 30, 0., 1500., 30, 0., 1500. );
    mTWV_Mlvjj-> GetXaxis()->SetTitle("m_{T} (diwjets, leptonic W) [GeV]");
    mTWV_Mlvjj-> GetYaxis()->SetTitle("M(l#nujj) [GeV]");
    
    mTWV_VVvecptdiff = new TH2F (Name+"_mTWV_VVvecptdiff",   Name+"_mTWV_VVvecptdiff", 30, 0., 1500., 16, 0., 800. );
    mTWV_VVvecptdiff-> GetXaxis()->SetTitle("m_{T} (diwjets, leptonic W) [GeV]");
    mTWV_VVvecptdiff-> GetYaxis()->SetTitle("p_{T} (diwjets - leptonic W) [GeV]");

    mTWV_ptwlep = new TH2F (Name+"_mTWV_ptwlep",   Name+"_mTWV_ptwlep", 30, 0., 1500., 16, 0., 800. );
    mTWV_ptwlep-> GetXaxis()->SetTitle("m_{T} (diwjets, leptonic W) [GeV]");
    mTWV_ptwlep-> GetYaxis()->SetTitle("p_{T} (W#rightarrow l#nu) [GeV]");
    

    mjjTagged_MET = new TH2F (Name+"_mjjTagged_MET",   Name+"_mjjTagged_MET", 60, 0., 3000., 25, 0., 500. );
    mjjTagged_MET-> GetXaxis()->SetTitle("m_{jj}(tagging) [GeV]");
    mjjTagged_MET-> GetYaxis()->SetTitle("MET [GeV]");
    
    cosDPhiwjjwlep = new TH1F(Name+"_cosDPhiwjjwlep",   Name+"_cosDPhiwjjwlep", 100, -1.0, 1.0);
    cosDPhiwjjwlep-> GetXaxis()->SetTitle("cos#Delta#phi(diwjets, leptonic W)");
    
    dPhilepMET= new TH1F (Name+"_dPhilepMET", Name+"_dPhilepMET", 31, -3.142 ,3.142);

    
    runNumber      = new TH1F(Name+"_runNumber",Name+"_runNumber" , 1000, 0., 1000000.);


    ////
    elRelEtCone30     = new TH1F(Name+"_elRelEtCone30", Name+"_elRelEtCone30"  , 100, -0.3, 0.7);
    elRelEtCone30->GetXaxis()->SetTitle("relative el etcone30");
    
    elRelPtCone30     = new TH1F(Name+"_elRelPtCone30", Name+"_elRelPtCone30"  , 100, 0, 1.0 );
    elRelPtCone30->GetXaxis()->SetTitle("relative el ptcone30");
    
    log_elRelEtCone30     = new TH1F(Name+"_log_elRelEtCone30", Name+"_log_elRelEtCone30"  , 20, -5, 0 );
    log_elRelEtCone30->GetXaxis()->SetTitle("log (relative el etcone30)");
    
    log_elRelPtCone30     = new TH1F(Name+"_log_elRelPtCone30", Name+"_log_elRelPtCone30"  , 20, -5 ,0 );
    log_elRelPtCone30->GetXaxis()->SetTitle("log (relative el ptcone30)");

    MET_elRelPtCone30_lt02     = new TH1F(Name+"_MET_elRelPtCone30_lt02", Name+"_MET_elRelPtCone30_lt02"  , 100, 0., 500.);
    MET_elRelPtCone30_lt02->GetXaxis()->SetTitle("MET given ptcone30/pt <0.2 [GeV]");

       
    elz0sinth     = new TH1F(Name+"_elz0sinth", Name+"_elz0sinth"  , 100, 0, 0.5);
    elz0sinth->GetXaxis()->SetTitle("el z0 sin #theta [mm]");
    
    eld0sigd0     = new TH1F(Name+"_eld0sigd0", Name+"_eld0sigd0"  , 50, 0, 10.);
    eld0sigd0->GetXaxis()->SetTitle("el d_{0}/#sigma(d_{0})");
    
    muRelEtCone30     = new TH1F(Name+"_muRelEtCone30", Name+"_muRelEtCone30"  , 100, -0.3, 0.7);
    muRelEtCone30->GetXaxis()->SetTitle("relative mu etcone30");
    
    muRelPtCone30     = new TH1F(Name+"_muRelPtCone30", Name+"_muRelPtCone30"  , 100, 0., 1.0);
    muRelPtCone30->GetXaxis()->SetTitle("relative mu ptcone30");
    
    log_muRelEtCone30     = new TH1F(Name+"_log_muRelEtCone30", Name+"_log_muRelEtCone30"  , 20, -5, 0 );
    log_muRelEtCone30->GetXaxis()->SetTitle("log (relative mu etcone30)");
    
    log_muRelPtCone30     = new TH1F(Name+"_log_muRelPtCone30", Name+"_log_muRelPtCone30"  , 20, -5 ,0 );
    log_muRelPtCone30->GetXaxis()->SetTitle("log (relative mu ptcone30)");

    MET_muRelPtCone30_lt02     = new TH1F(Name+"_MET_muRelPtCone30_lt02", Name+"_MET_muRelPtCone30_lt02"  , 100, 0., 500.);
    MET_muRelPtCone30_lt02->GetXaxis()->SetTitle("MET given ptcone30/pt <0.2 [GeV]");
    
    muz0sinth     = new TH1F(Name+"_muz0sinth", Name+"_muz0sinth"  , 100, 0, 0.5);
    muz0sinth->GetXaxis()->SetTitle("mu z0 sin #theta [mm]");
    
    mud0sigd0     = new TH1F(Name+"_mud0sigd0", Name+"_mud0sigd0"  , 50, 0, 10.);
    mud0sigd0->GetXaxis()->SetTitle("mu d_{0}/#sigma(d_{0})");
    ////
    
    
    if ( !reduced ){

      min_dR_lepjet     = new TH1F(Name+"_min_dR_lepjet",   Name+"_min_dR_lepjet", 50, 0., 5.);
      min_dR_lepjet  -> GetXaxis()->SetTitle("#DeltaR_{min}(lep,jet)");
      
      min_dR_lepfatjet     = new TH1F(Name+"_min_dR_lepfatjet",   Name+"_min_dR_lepfatjet", 50, 0., 5.);
      min_dR_lepfatjet  -> GetXaxis()->SetTitle("#DeltaR_{min}(lep,fat jet)");
      
      min_dR_FJ_jet     = new TH1F(Name+"_min_dR_FJ_jet",   Name+"_min_dR_FJ_jet", 50, 0., 5.);
      min_dR_FJ_jet  -> GetXaxis()->SetTitle("#DeltaR_{min}(W-fatjet,jet)");
      
      dR_FJ_jets     = new TH1F(Name+"_dR_FJ_jets",   Name+"_dR_FJ_jets", 50, 0., 5.);
      dR_FJ_jets  -> GetXaxis()->SetTitle("#DeltaR(W-fatjet,jets)");

      vbfjets_etaProduct              = new TH1F(Name+"_vbfjets_etaProduct",   Name+"_vbfjets_etaProduct", 60, -15., 15.);
      vbfjets_etaProduct -> GetXaxis()->SetTitle("#eta product (vbf jets)"); 
	
      dEtaMax              = new TH1F(Name+"_dEtaMax",   Name+"_dEtaMax", 50, 0., 10.);
      dEtaMax  ->  GetXaxis()->SetTitle("#Delta#eta_{max} (j,j)");
      
      ptjjMax              = new TH1F(Name+"_ptjjMax",   Name+"_ptjjMax", 50, 0., 500.);
      ptjjMax -> GetXaxis()->SetTitle("p_{T,max}(j,j) [GeV]");
      
      dRlepFJ     = new TH1F(Name+"_dRlepFJ",   Name+"_dRlepFJ", 60, 0., 6.);
      dRlepFJ -> GetXaxis()->SetTitle("#DeltaR(lep, fat jet)");
      
      min_dEta_Wlepjet     = new TH1F(Name+"_min_dEta_Wlepjet",   Name+"_min_dEta_Wlepjet", 50, 0., 10.);
      min_dEta_Wlepjet -> GetXaxis()->SetTitle("#Delta#eta_{min}(leptonic W, jet)");      
      
      dR_lepTrueLep     = new TH1F(Name+"_dR_lepTrueLep",   Name+"_dR_lepTrueLep", 50, 0., 5.);
      dR_lepTrueLep -> GetXaxis()->SetTitle("#DeltaR(l, true l)");
      
      dPhi_METtrueNu    = new TH1F(Name+"_dPhi_METtrueNu",   Name+"_dPhi_METtrueNu", 31, -3.142, 3.142);
      pt_trueLep        = new TH1F(Name+"_pt_trueLep",   Name+"_pt_trueLep",100, 0., 500. );
      Et_trueNu         = new TH1F(Name+"_Et_trueNu",   Name+"_Et_trueNu", 50, 0., 200.);
      pt_lepTrueLep        = new TH1F(Name+"_pt_lepTrueLep",   Name+"_pt_lepTrueLep",25, -50., 50. );
      Et_METtrueNu         = new TH1F(Name+"_Et_METtrueNu",   Name+"_Et_METtrueNu", 50, -100., 100.);
      dPhilv_true       = new TH1F(Name+"_dPhilv_true",   Name+"_dPhilv_true", 31, -3.142, 3.142);
      mT_true           = new TH1F(Name+"_mT_true",   Name+"_mT_true", 30, 0., 150.);
      mlv_true          = new TH1F(Name+"_mlv_true",   Name+"_mlv_true", 50, 0., 200.);
      

      vbfjet1_phi              = new TH1F(Name+"_vbfjet1_phi",   Name+"_vbfjet1_phi", 31, -3.142, 3.142);
      vbfjet1_phi -> GetXaxis()->SetTitle("tagging jet1 #phi ");
      vbfjet2_phi              = new TH1F(Name+"_vbfjet2_phi",   Name+"_vbfjet2_phi", 31, -3.142, 3.142);
      vbfjet2_phi -> GetXaxis()->SetTitle("tagging jet2 #phi ");
      
      AvgPt_Wjets = new TH1F(Name+"_AvgPt_Wjets",   Name+"_AvgPt_Wjets", 60, 0., 300.);
      AvgPt_Wjets -> GetXaxis()->SetTitle("Average of W-jets p_{T} [GeV]");
      
      diff_ptww_ptjjTagged= new TH1F(Name+"_diff_ptww_ptjjTagged",   Name+"_diff_ptww_ptjjTagged", 40,-200.,200.);
      sumPt= new TH1F(Name+"_sumPt",   Name+"_sumPt", 150,0.,1500.);
      diff_etawjj_avgEtaTagged= new TH1F(Name+"_diff_etawjj_avgEtaTagged",   Name+"_diff_etawjj_avgEtaTagged", 30,0.,3.);
      
      

      dPhiTaggedJets= new TH1F(Name+"_dPhiTaggedJets",   Name+"_dPhiTaggedJets", 31,-3.142 ,3.142);
      dPhiTaggedJets-> GetXaxis()->SetTitle("#Delta#phi(vbf j1, vbf j2)");
      
      dRTaggedJets= new TH1F(Name+"_dRTaggedJets",   Name+"_dRTaggedJets", 80,0.,8.);
      dRTaggedJets-> GetXaxis()->SetTitle("#DeltaR(vbf j1, vbf j2)");
      
      dEtaWjets= new TH1F(Name+"_dEtaWjets",   Name+"_dEtaWjets", 80,0.,8.);
      dEtaWjets-> GetXaxis()->SetTitle("#Delta#eta(W j1, W j2)");
      
      dPhiWjets= new TH1F(Name+"_dPhiWjets",   Name+"_dPhiWjets", 31,-3.142 ,3.142);
      dPhiWjets-> GetXaxis()->SetTitle("#Delta#phi(W j1, W j2)");
            
      
      diffptwj1ptwj2 = new TH1F(Name+"_diffptwj1ptwj2",   Name+"_diffptwj1ptwj2", 80,0.,400.);
      

      dRvbfwwaxes = new TH1F(Name+"_dRvbfwwaxes",   Name+"_dRvbfwwaxes", 50, 0, 10);
      dEtavbfwwaxes = new TH1F(Name+"_dEtavbfwwaxes",   Name+"_dEtavbfwwaxes", 50, 0, 10);
      dPhivbfwwaxes = new TH1F(Name+"_dPhivbfwwaxes",   Name+"_dPhivbfwwaxes", 31, -3.142, 3.142);
      

      
      mass_lnuj0= new TH1F (Name+"_mass_lnuj0",   Name+"_mass_lnuj0", 40,0.,1000.);
      mass_j0j1j2= new TH1F (Name+"_mass_j0j1j2",   Name+"_mass_j0j1j2", 80,0.,2000.);
      
      mT_dPhilepMET_lt14 = new TH1F ( Name+"_mT_dPhilepMET_lt14",   Name+"_mT_dPhilepMET_lt14", 30,0.,150.);
      mT_dPhilepMET_gt14 = new TH1F ( Name+"_mT_dPhilepMET_gt14",   Name+"_mT_dPhilepMET_gt14", 30,0.,150.);
      mT_ptwlep_lt50     = new TH1F ( Name+"_mT_ptwlep_lt50",       Name+"_mT_ptwlep_lt50",     30,0.,150.);
      mT_ptwlep_50_100  = new TH1F ( Name+"_mT_ptwlep_50_100",    Name+"_mT_ptwlep_50_100",  30,0.,150.);
      mT_ptwlep_100_150  = new TH1F ( Name+"_mT_ptwlep_100_150",    Name+"_mT_ptwlep_100_150",  30,0.,150.);
      mT_ptwlep_gt150    = new TH1F ( Name+"_mT_ptwlep_gt150",      Name+"_mT_ptwlep_gt150",    30,0.,150.);
      
      // mT_ptwlep= new TH2F (Name+"_mT_ptwlep",   Name+"_mT_ptwlep", 20, 0., 160., 5, 0., 800. );
      // mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
      // mT_ptwlep->GetYaxis()->SetTitle("W(lv) p_{T} [GeV]");
      
      //MV1 =  new TH1F (Name+"_MV1",   Name+"_MV1", 20, 0., 1.0);
      MV1 =  new TH1F (Name+"_MV1",   Name+"_MV1", 100, 0., 1.0);
      
      lep_eta    = new TH1F(Name+"_lep_eta",Name+"_lep_eta" , 26, -2.6, 2.6);
      lep_eta->GetXaxis()->SetTitle("lepton #eta");
      lep_phi    = new TH1F(Name+"_lep_phi",Name+"_lep_phi" , 20, -3.142, 3.142);
      lep_phi->GetXaxis()->SetTitle("lepton #phi");
      
      //	mll     = new TH1F(Name+"_mll", Name+"_mll"  , 25, 70., 120.);
      mll     = new TH1F(Name+"_mll", Name+"_mll"  , 250, 0., 500.);
      ptll     = new TH1F(Name+"_ptll", Name+"_ptll"  , 100, 0., 500.);
      lep2_pt     = new TH1F(Name+"_lep2_pt", Name+"_lep2_pt"  , 60, 0., 300.);	
      
      Nfatjet      = new TH1F(Name+"_Nfatjet",Name+"_Nfatjet" , 6, -0.5, 5.5 ); 
      Nfatjet -> GetXaxis()->SetTitle("N_{fatjet}");
      
      nJetsOverlapPh      = new TH1F(Name+"_nJetsOverlapPh",Name+"_nJetsOverlapPh" , 4, -0.5, 3.5 );
      nJetsOverlapPh -> GetXaxis()->SetTitle("N_{Jet} close to #gamma");
      
      METdiff      = new TH1F(Name+"_METdiff",Name+"_METdiff" , 40, -100, 100 );
      METdiff -> GetXaxis()->SetTitle("MET - MET_truth");
      
      nTrueB      = new TH1F(Name+"_nTrueB",Name+"_nTrueB" , 6, -0.5, 5.5);
      nTrueB -> GetXaxis()->SetTitle("Number of true b-quarks");
      
      nTrueC      = new TH1F(Name+"_nTrueC",Name+"_nTrueC" , 6, -0.5, 5.5);
      nTrueC -> GetXaxis()->SetTitle("Number of true c-quarks");
      
      dRfatjetV      = new TH1F(Name+"_dRfatjetV",Name+"_dRfatjetV" , 30, 0, 3);
      dRfatjetV -> GetXaxis()->SetTitle("#Delta R(true V, fatjet)");
      
      matchedDijetM      = new TH1F(Name+"_matchedDijetM",Name+"_matchedDijetM" , 200, 0, 200);
      matchedDijetM -> GetXaxis()->SetTitle("m(jj) for jets matched to V->jj [GeV]");
      
      trueVpt      = new TH1F(Name+"_trueVpt",Name+"_trueVpt" , 16, 0, 800);
      trueVpt -> GetXaxis()->SetTitle("pT(true V->jj) [GeV]");
	
      trueVptMatched      = new TH1F(Name+"_trueVptMatched",Name+"_trueVptMatched" , 16, 0, 800);
      trueVptMatched -> GetXaxis()->SetTitle("pT(true V->jj matched to fatjet) [GeV]");
      
      trueVptDijetMatched      = new TH1F(Name+"_trueVptDijetMatched",Name+"_trueVptDijetMatched" , 16, 0, 800);
      trueVptDijetMatched -> GetXaxis()->SetTitle("pT(true V->jj matched to dijet) [GeV]");
      
      trueVptDijetWjetMatched      = new TH1F(Name+"_trueVptDijetWjetMatched",Name+"_trueVptDijetWjetMatched" , 16, 0, 800);
      trueVptDijetWjetMatched -> GetXaxis()->SetTitle("pT(true V->jj matched to W-jets) [GeV]");
	
      trueVeta      = new TH1F(Name+"_trueVeta",Name+"_trueVeta" , 90, -4.5, 4.5);
      trueVeta -> GetXaxis()->SetTitle("eta(true V->jj)");
      
      trueVetaMatched      = new TH1F(Name+"_trueVetaMatched",Name+"_trueVetaMatched" , 90, -4.5, 4.5);
      trueVetaMatched -> GetXaxis()->SetTitle("eta(true V->jj matched to fatjet)");
      
      
      trueVjMaxEta      = new TH1F(Name+"_trueVjMaxEta",Name+"_trueVjMaxEta" , 60, 0, 6);
      trueVjMinPt      = new TH1F(Name+"_trueVjMinPt",Name+"_trueVjMinPt" , 40, 0, 200);
      trueVjjDR      = new TH1F(Name+"_trueVjjDR",Name+"_trueVjjDR" , 50, 0, 5);
      trueVjjCosTh      = new TH1F(Name+"_trueVjjCosTh",Name+"_trueVjjCosTh" , 20, 0.0, 1.0);	
      trueDeltaVVW      = new TH1F(Name+"_trueDeltaVVW",Name+"_trueDeltaVVW" , 300, -100., 200.);
      trueDeltaVVZ      = new TH1F(Name+"_trueDeltaVVZ",Name+"_trueDeltaVVZ" , 300, -100., 200.);



      

      
      jet_emfrac     = new TH1F(Name+"_jet_emfrac", Name+"_jet_emfrac"  , 20, -0.5, 1.5);
      jet_emfrac->GetXaxis()->SetTitle("jet em fraction");
      
      jet1_pt     = new TH1F(Name+"_jet1_pt", Name+"_jet1_pt"  , 60, 0., 600.);
      jet1_pt -> GetXaxis()->SetTitle("leading jet p_{T} [GeV]");
      
      jet2_pt     = new TH1F(Name+"_jet2_pt", Name+"_jet2_pt"  , 40, 0., 400.);
      jet2_pt -> GetXaxis()->SetTitle("sub-leading jet p_{T} [GeV]");
      
      jet3_pt     = new TH1F(Name+"_jet3_pt", Name+"_jet2_pt"  , 20, 0., 200.);
      jet3_pt -> GetXaxis()->SetTitle("third leading jet p_{T} [GeV]");
      
      jet4_pt     = new TH1F(Name+"_jet4_pt", Name+"_jet2_pt"  , 15, 0., 150.);
      jet4_pt -> GetXaxis()->SetTitle("fourth leading jet p_{T} [GeV]");
      
      Wjet1_pt     = new TH1F(Name+"_Wjet1_pt", Name+"_Wjet1_pt"  , 30, 0., 300.);
      Wjet1_pt -> GetXaxis()->SetTitle("W-jet1 p_{T} [GeV]");
      
      Wjet2_pt     = new TH1F(Name+"_Wjet2_pt", Name+"_Wjet2_pt"  , 30, 0., 300.);
      Wjet2_pt -> GetXaxis()->SetTitle("W-jet2 p_{T} [GeV]");
      
      fatjet_pt     = new TH1F(Name+"_fatjet_pt", Name+"_fatjet_pt"  , 30, 0., 300.);
      fatjet_pt -> GetXaxis()->SetTitle("fatjet p_{T} [GeV]");
      
      jet1_eta    = new TH1F(Name+"_jet1_eta",Name+"_jet1_eta" , 50, -5., 5.);
      jet1_eta -> GetXaxis()->SetTitle("leading jet #eta");
      
      jet1_phi    = new TH1F(Name+"_jet1_phi",Name+"_jet1_phi" , 62, -3.142, 3.142);
      jet1_phi -> GetXaxis()->SetTitle("leading jet #phi");
      
      jet2_eta    = new TH1F(Name+"_jet2_eta",Name+"_jet2_eta" , 50, -5., 5.);
      jet2_eta -> GetXaxis()->SetTitle("sub-leading jet #eta");

      jet2_phi    = new TH1F(Name+"_jet2_phi",Name+"_jet2_phi" , 62, -3.142, 3.142);
      jet2_phi -> GetXaxis()->SetTitle("sub-leading jet #phi");
      
      jet3_eta    = new TH1F(Name+"_jet3_eta",Name+"_jet3_eta" , 50, -5., 5.);
      jet3_eta -> GetXaxis()->SetTitle("third jet #eta");
      
      jet3_phi    = new TH1F(Name+"_jet3_phi",Name+"_jet3_phi" , 62, -3.142, 3.142);
      jet3_phi -> GetXaxis()->SetTitle("third jet #phi");
      
      jet4_eta    = new TH1F(Name+"_jet4_eta",Name+"_jet4_eta" , 50, -5., 5.);
      jet4_eta -> GetXaxis()->SetTitle("fourth jet #eta");
      
      jet4_phi    = new TH1F(Name+"_jet4_phi",Name+"_jet4_phi" , 62, -3.142, 3.142);
      jet4_phi -> GetXaxis()->SetTitle("fourht jet #phi");
            
      fatjet_eta     = new TH1F(Name+"_fatjet_eta", Name+"_fatjet_eta"  ,50, -5., 5. );
      fatjet_eta -> GetXaxis()->SetTitle("fatjet #eta");
      
      fatjet_phi     = new TH1F(Name+"_fatjet_phi", Name+"_fatjet_phi"  , 62, -3.142, 3.142);
      fatjet_phi -> GetXaxis()->SetTitle("fatjet #phi");
      
      fatjet_M     = new TH1F(Name+"_fatjet_M", Name+"_fatjet_M"  ,50, 0., 500. );
      fatjet_M -> GetXaxis()->SetTitle("fatjet mass [GeV]");


      truthMatchedfatjetM      = new TH1F(Name+"_truthMatchedfatjetM",Name+"_truthMatchedfatjetM" , 200, 0, 200);
      truthMatchedfatjetM -> GetXaxis()->SetTitle("truth matched fat jet m [GeV]");
      
      fatjetM_pt150     = new TH1F(Name+"_fatjetM_pt150", Name+"_fatjetM_pt150"  ,100, 0., 200. );
      fatjetM_pt200     = new TH1F(Name+"_fatjetM_pt200", Name+"_fatjetM_pt200"  ,100, 0., 200. );
      fatjetM_pt250     = new TH1F(Name+"_fatjetM_pt250", Name+"_fatjetM_pt250"  ,100, 0., 200. );
      fatjetM_pt300     = new TH1F(Name+"_fatjetM_pt300", Name+"_fatjetM_pt300"  ,100, 0., 200. );
      
      
//	PtLL          = new TH1F(Name+"_PtLL",    Name+"_PtLL", 50, 0., 200.);
//	NVertex       = new TH1F(Name+"_NVertex",Name+"_NVertex", 40, 0., 40.) ;

//	
//	deltaPhi      = new TH1F(Name+"_deltaPhi",Name+"_deltaPhi",  10, 0., 3.);
//	WT            = new TH1F (Name+"_WT",Name+"_WT" ,  50, 0., 300.  );
//	
//
//	MET_phi       = new TH1F(Name+"_MET_phi",Name+"_MET_phi", 20, -3.2, 3.2);
//	MetRel        = new TH1F(Name+"_MetRel" ,Name+"_MetRel", 50, 0., 200.);
//	
//
//
//
	
//	jet1_CombNN  = new TH1F(Name+"_jet1_CombNN", Name+"_jet1_CombNN"  , 50, -6., 8.);
//	
//    
//	dEtajj     = new TH1F(Name+"_dEtajj",     Name+"_dEtajj",     20, 0., 10.   )  ; 
//	Mjj        = new TH1F(Name+"_Mjj",        Name+"_Mjj",        50, 0., 2000. )  ;  
//	EtaJ1EtaJ2 = new TH1F(Name+"_EtaJ1EtaJ2", Name+"_EtaJ1EtaJ2", 50, -25., 25. )  ; 
//	
//
//	
//	MLL_METrel  = new TH2F(Name+"_MLL_METrel", Name+"_MLL_METrel", 50, 0., 250., 50, 0., 80.) ;
//	
//	TotalPt    = new TH1F(Name+"_TotalPt",Name+"_TotalPt", 16, 0., 80. );

      ttbarWeight = new TH1F(Name+"_ttbarWeight",Name+"_ttbarWeight" , 40, -2., 2.);
      topRWEventWeight = new TH1F(Name+"_topRWEventWeight",Name+"_topRWEventWeight" , 40, -2., 2.);
      wjetsRWEventWeight = new TH1F(Name+"_wjetsRWEventWeight",Name+"_wjetsRWEventWeight" , 40, -2., 2.);
      mcEventWeight = new TH1F(Name+"_mcEventWeight",Name+"_mcEventWeight" , 40, -2., 2.);
      EventWeight = new TH1F(Name+"_EventWeight",Name+"_EventWeight" , 40, -2., 2.);
    }

    mT_ptwlep= new TH2F (Name+"_mT_ptwlep",   Name+"_mT_ptwlep", 20, 0., 160., 5, 0., 800. );
    mT_ptwlep->GetXaxis()->SetTitle("m_{T} [GeV]");
    mT_ptwlep->GetYaxis()->SetTitle("W(lv) p_{T} [GeV]");
  
  }

  

} ;


#endif // HISTRUN_H

