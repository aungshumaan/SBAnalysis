//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct  6 11:19:49 2013 by ROOT version 5.34/08
// from TTree HWWTree_lvqq/HWW lvqq Ntuple
// found on file: group.phys-higgs.393560_032808._00001.HWWSkimmedNTUP_lvqq.root
//////////////////////////////////////////////////////////

#ifndef foo_h
#define foo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>


using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class foo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Bool_t          isE;
   Bool_t          isM;
   Bool_t          isJ;
   Float_t         higgsPt;
   Float_t         MT;
   Float_t         MTrans;
   Float_t         Pttot;
   Float_t         Mjj;
   Float_t         Ptjj;
   Float_t         DPhijj;
   Float_t         DRjj;
   Float_t         DEtajj;
   Float_t         DYjj;
   Float_t         smt_muon_pt;
   Float_t         smt_muon_sf;
   Float_t         smt_muon_mistag_sf_up;
   Float_t         smt_muon_mistag_sf_dw;
   Float_t         smt_muon_chi2_sf_up;
   Float_t         smt_muon_chi2_sf_dw;
   Float_t         smt_muon_id_sf_up;
   Float_t         smt_muon_id_sf_dw;
   vector<float>   *smt_muon_pts;
   vector<float>   *smt_muon_etas;
   vector<float>   *smt_muon_phis;
   vector<float>   *smt_muon_charges;
   Float_t         BLayer_hit0;
   Float_t         conv0;
   Int_t           RandomRunNumber;
   Float_t         MinDPhi;
   Float_t         MinDPhi_noJVF;
   Float_t         MET;
   Float_t         MET_x;
   Float_t         MET_y;
   Float_t         MET_phi;
   Float_t         METRel;
   Float_t         METRel_x;
   Float_t         METRel_y;
   Float_t         METRel_noJets;
   Float_t         MET_default;
   Float_t         MET_default_x;
   Float_t         MET_default_y;
   Float_t         MinDPhi_STVF;
   Float_t         MinDPhi_noJVF_STVF;
   Float_t         MT_STVF;
   Float_t         MTrans_STVF;
   Float_t         Pttot_STVF;
   Float_t         MET_STVF;
   Float_t         MET_x_STVF;
   Float_t         MET_y_STVF;
   Float_t         MET_phi_STVF;
   Float_t         METRel_STVF;
   Float_t         METRel_x_STVF;
   Float_t         METRel_y_STVF;
   Float_t         METRel_noJets_STVF;
   Float_t         MET_default_STVF;
   Float_t         MET_default_x_STVF;
   Float_t         MET_default_y_STVF;
   Float_t         MET_TrackHWW;
   Float_t         MET_x_TrackHWW;
   Float_t         MET_y_TrackHWW;
   Float_t         MET_phi_TrackHWW;
   Float_t         MinDPhi_TrackHWW;
   Float_t         MinDPhi_noJVF_TrackHWW;
   Float_t         METRel_TrackHWW;
   Float_t         METRel_x_TrackHWW;
   Float_t         METRel_y_TrackHWW;
   Float_t         DPhi_CaloTrackHWW;
   Float_t         MT_TrackHWW;
   Float_t         PtTrack_TrackHWW;
   Float_t         MTrans_TrackHWW;
   Float_t         Pttot_TrackHWW;
   Float_t         METRel_noJets_TrackHWW;
   Float_t         MET_TrackHWW_Cl;
   Float_t         MET_x_TrackHWW_Cl;
   Float_t         MET_y_TrackHWW_Cl;
   Float_t         MET_phi_TrackHWW_Cl;
   Float_t         MinDPhi_TrackHWW_Cl;
   Float_t         MinDPhi_noJVF_TrackHWW_Cl;
   Float_t         METRel_TrackHWW_Cl;
   Float_t         METRel_x_TrackHWW_Cl;
   Float_t         METRel_y_TrackHWW_Cl;
   Float_t         DPhi_CaloTrackHWW_Cl;
   Float_t         MT_TrackHWW_Cl;
   Float_t         PtTrack_TrackHWW_Cl;
   Float_t         MTrans_TrackHWW_Cl;
   Float_t         Pttot_TrackHWW_Cl;
   Float_t         METRel_noJets_TrackHWW_Cl;
   Float_t         MET_TrackHWW_Clj;
   Float_t         MET_x_TrackHWW_Clj;
   Float_t         MET_y_TrackHWW_Clj;
   Float_t         MET_phi_TrackHWW_Clj;
   Float_t         MinDPhi_TrackHWW_Clj;
   Float_t         MinDPhi_noJVF_TrackHWW_Clj;
   Float_t         METRel_TrackHWW_Clj;
   Float_t         METRel_x_TrackHWW_Clj;
   Float_t         METRel_y_TrackHWW_Clj;
   Float_t         DPhi_CaloTrackHWW_Clj;
   Float_t         MT_TrackHWW_Clj;
   Float_t         PtTrack_TrackHWW_Clj;
   Float_t         MTrans_TrackHWW_Clj;
   Float_t         Pttot_TrackHWW_Clj;
   Float_t         METRel_noJets_TrackHWW_Clj;
   Float_t         lepID;
   vector<bool>    *isMPP_ele;
   vector<bool>    *isTPP_ele;
   vector<bool>    *isIso_ele;
   vector<bool>    *isD0_muon;
   vector<bool>    *isIso_muon;
   vector<bool>    *isIsoJet_muon;
   vector<bool>    *isIsoJet_muon_EM;
   //   Bool_t          lepMatch_EF_mu24i_tight_0;
   //  Bool_t          lepMatch_EF_mu36_tight_0;
   //  Bool_t          lepMatch_EF_e24vhi_medium1_0;
   //   Bool_t          lepMatch_EF_e60_medium1_0;
   vector<bool>    *lepMatch_EF_mu24i_tight;
   vector<bool>    *lepMatch_EF_mu36_tight;
   vector<bool>    *lepMatch_EF_e24vhi_medium1;
   vector<bool>    *lepMatch_EF_e60_medium1;
   Bool_t          elec_trigger24;
   Bool_t          elec_trigger60;
   Bool_t          muon_trigger24;
   Bool_t          muon_trigger36;
   Double_t        vertexEventWeight;
   Double_t        vertexEventWeight_Pu1;
   Double_t        vertexEventWeight_Pu088;
   Double_t        pileupEventWeight;
   Double_t        pileupEventWeight_094;
   Double_t        pileupEventWeight_080;
   Double_t        pileupEventWeight_090;
   Double_t        pileupEventWeight_088;
   Double_t        pileupEventWeight_075;
   Double_t        pileupEventWeight_103;
   Double_t        higgsPtEventWeight;
   Double_t        higgsMEventWeight;
   Double_t        higgsPtError;
   Double_t        didEJoverlap;
   Double_t        didMJoverlap;
   Double_t        mcEventWeight;
   Double_t        mcEventWeightUp;
   Double_t        mcEventWeightDown;
   Double_t        tauPolWeight;
   Double_t        mcWeightOrg;
   Double_t        trigEventWeight;
   Double_t        lepTrigSFEventWeight;
   Double_t        lepTrigSFEventWeightUp;
   Double_t        lepTrigSFEventWeightDown;
   vector<float>        *lepSFEventWeight;
   vector<float>        *lepSFError;
   vector<float>        *lepSFErrorReco;
   vector<float>        *lepSFErrorIso;
   vector<float>        *lepSFErrorSys;
   vector<double>  *MV1_value;
   vector<double>  *MV1_EventWeight;
   vector<double>  *MV1_EventWeightUp;
   vector<double>  *MV1_EventWeightDown;
   vector<double>  *MV1_VetoEventWeight;
   vector<double>  *MV1_VetoEventWeightUp;
   vector<double>  *MV1_VetoEventWeightDown;
   //&&&&
   vector<double>  *MV1_EventWeight_60;
   vector<double>  *MV1_EventWeightUp_60;
   vector<double>  *MV1_EventWeightDown_60;
   vector<double>  *MV1_VetoEventWeight_60;
   vector<double>  *MV1_VetoEventWeightUp_60;
   vector<double>  *MV1_VetoEventWeightDown_60;
   
   Double_t        InterferenceW_cen[19];
   Double_t        InterferenceW_ErrUp[19];
   Double_t        InterferenceW_ErrDown[19];
   Double_t        SMWidthWeight[19];
   Int_t           truth_evtNumber;
   Float_t         truth_l_pt;
   Float_t         truth_nu_pt;
   Float_t         truth_j0_pt;
   Float_t         truth_j1_pt;
   Float_t         truth_W0_pt;
   Float_t         truth_W1_pt;
   Float_t         truth_H_pt;
   Float_t         truth_l_eta;
   Float_t         truth_nu_eta;
   Float_t         truth_j0_eta;
   Float_t         truth_j1_eta;
   Float_t         truth_W0_eta;
   Float_t         truth_W1_eta;
   Float_t         truth_H_eta;
   Float_t         truth_l_phi;
   Float_t         truth_nu_phi;
   Float_t         truth_j0_phi;
   Float_t         truth_j1_phi;
   Float_t         truth_W0_phi;
   Float_t         truth_W1_phi;
   Float_t         truth_H_phi;
   Float_t         truth_W0_m;
   Float_t         truth_W1_m;
   Float_t         truth_l_m;
   Float_t         truth_nu_m;
   Float_t         truth_j0_m;
   Float_t         truth_j1_m;
   Float_t         truth_H_m;
   Int_t           truth_l_pdgId;
   Int_t           truth_j0_pdgId;
   Int_t           truth_j1_pdgId;
   Int_t           truth_W0_pdgId;
   Int_t           truth_W1_pdgId;
   Bool_t          truth_W0_leptonic;
   Int_t           Nvxp;
   Int_t           bpos;
   Int_t           blen;
   Int_t           bgap;
   Float_t         ttbarWeight;
   Float_t         truth_sherpa_Wpt;
   Float_t         truth_sherpa_Zpt;
   vector<int>     *mctruth_pdgId;
   vector<float>   *mctruth_pt;
   vector<float>   *mctruth_eta;
   vector<float>   *mctruth_phi;
   vector<float>   *mctruth_m;
   vector<int>     *mctruth_parent;
   vector<float>   *truthStable_el_pt;
   vector<float>   *truthStable_el_eta;
   vector<float>   *truthStable_el_phi;
   vector<float>   *truthStable_mu_pt;
   vector<float>   *truthStable_mu_eta;
   vector<float>   *truthStable_mu_phi;
   vector<float>   *truthStable_ph_pt;
   vector<float>   *truthStable_ph_eta;
   vector<float>   *truthStable_ph_phi;
   Float_t         MET_truth_nonint;
   Float_t         MET_truth_nonint_x;
   Float_t         MET_truth_nonint_y;
   UInt_t          RunNumber;
   UInt_t          EventNumber;

   bool            IsBadMediumBCH;
   bool            IsBadMediumBCHUp; 
   bool            IsBadMediumBCHDown;
   bool            IsBadTightBCH;


   UInt_t          lbn;
   UInt_t          bcid;
   Float_t         actualIntPerXing;
   Float_t         averageIntPerXing;
   UInt_t          mc_channel_number;
   UInt_t          larError;
   Int_t           m_el_n;
   vector<float>   *m_el_E;
   vector<float>   *m_el_pt;
   vector<float>   *m_el_eta;
   vector<float>   *m_el_phi;
   vector<float>   *m_el_charge;
   vector<float>   *m_el_trackd0pv;
   vector<float>   *m_el_tracksigd0pv;
   vector<float>   *m_el_etcone30;
   vector<float>   *m_el_ptcone30;
   vector<float>   *m_el_z0sinth;

   Int_t           m_mu_n;
   vector<float>   *m_mu_E;
   vector<float>   *m_mu_pt;
   vector<float>   *m_mu_eta;
   vector<float>   *m_mu_phi;
   vector<float>   *m_mu_charge;
   vector<float>   *m_mu_matchchi2;
   vector<int>     *m_mu_matchndof;
   vector<float>   *m_mu_energyLossPar;
   vector<float>   *m_mu_etCore;
   vector<float>   *m_mu_id_d0_exPV;
   vector<float>   *m_mu_id_theta_exPV;
   vector<float>   *m_mu_id_qoverp_exPV;
   vector<float>   *m_mu_me_theta_exPV;
   vector<float>   *m_mu_me_qoverp_exPV;
   vector<float>   *m_mu_id_cov_d0_exPV;
   vector<float>   *m_mu_trackd0pv;
   vector<float>   *m_mu_tracksigd0pv;
   vector<float>   *m_mu_etcone30;
   vector<float>   *m_mu_ptcone30;
   vector<float>   *m_mu_z0sinth;
   
   Int_t           m_jetTruth_n;
   vector<float>   *m_jetTruth_pt;
   vector<float>   *m_jetTruth_eta;
   Int_t           m_mfcajet_n;
   vector<float>   *m_mfcajet_E;
   vector<float>   *m_mfcajet_pt;
   vector<float>   *m_mfcajet_m;
   vector<float>   *m_mfcajet_eta;
   vector<float>   *m_mfcajet_phi;
   Int_t           m_jet_n;
   vector<float>   *m_jet_E;
   vector<float>   *m_jet_pt;
   vector<float>   *m_jet_eta;
   vector<float>   *m_jet_phi;
   vector<float>   *m_jet_LArQuality;
   vector<float>   *m_jet_sumPtTrk;
   vector<float>   *m_jet_jvtxf;
   vector<float>   *m_jet_flavor_weight_JetFitterCharm;
   vector<float>   *m_jet_flavor_weight_MV1;
   vector<int>     *m_jet_flavor_truth_label;
   vector<float>   *m_jet_emfrac;
   Int_t           m_jet_EM_n;
   vector<float>   *m_jet_EM_E;
   vector<float>   *m_jet_EM_pt;
   vector<float>   *m_jet_EM_eta;
   vector<float>   *m_jet_EM_phi;
   vector<float>   *m_jet_EM_LArQuality;
   vector<float>   *m_jet_EM_sumPtTrk;
   vector<float>   *m_jet_EM_jvtxf;
   vector<float>   *m_jet_EM_flavor_weight_MV1;
   vector<int>     *m_jet_EM_flavor_truth_label;
   Int_t           m_vxp_n;
   vector<int>     *m_vxp_nTracks;
   vector<int>     *m_mcevt_pdf_id1;
   vector<int>     *m_mcevt_pdf_id2;
   vector<double>  *m_mcevt_pdf_x1;
   vector<double>  *m_mcevt_pdf_x2;
   vector<double>  *m_mcevt_pdf_scale;

   // List of branches
   TBranch        *b_isE;   //!
   TBranch        *b_isM;   //!
   TBranch        *b_isJ;   //!
   TBranch        *b_higgsPt;   //!
   TBranch        *b_MT;   //!
   TBranch        *b_MTrans;   //!
   TBranch        *b_Pttot;   //!
   TBranch        *b_Mjj;   //!
   TBranch        *b_Ptjj;   //!
   TBranch        *b_DPhijj;   //!
   TBranch        *b_DRjj;   //!
   TBranch        *b_DEtajj;   //!
   TBranch        *b_DYjj;   //!
   TBranch        *b_smt_muon_pt;   //!
   TBranch        *b_smt_muon_sf;   //!
   TBranch        *b_smt_muon_mistag_sf_up;   //!
   TBranch        *b_smt_muon_mistag_sf_dw;   //!
   TBranch        *b_smt_muon_chi2_sf_up;   //!
   TBranch        *b_smt_muon_chi2_sf_dw;   //!
   TBranch        *b_smt_muon_id_sf_up;   //!
   TBranch        *b_smt_muon_id_sf_dw;   //!
   TBranch        *b_smt_muon_pts;   //!
   TBranch        *b_smt_muon_etas;   //!
   TBranch        *b_smt_muon_phis;   //!
   TBranch        *b_smt_muon_charges;   //!
   TBranch        *b_BLayer_hit0;   //!
   TBranch        *b_conv0;   //!
   TBranch        *b_RandomRunNumber;   //!
   TBranch        *b_MinDPhi;   //!
   TBranch        *b_MinDPhi_noJVF;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_MET_x;   //!
   TBranch        *b_MET_y;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_METRel;   //!
   TBranch        *b_METRel_x;   //!
   TBranch        *b_METRel_y;   //!
   TBranch        *b_METRel_noJets;   //!
   TBranch        *b_MET_default;   //!
   TBranch        *b_MET_default_x;   //!
   TBranch        *b_MET_default_y;   //!
   TBranch        *b_MinDPhi_STVF;   //!
   TBranch        *b_MinDPhi_noJVF_STVF;   //!
   TBranch        *b_MT_STVF;   //!
   TBranch        *b_MTrans_STVF;   //!
   TBranch        *b_Pttot_STVF;   //!
   TBranch        *b_MET_STVF;   //!
   TBranch        *b_MET_x_STVF;   //!
   TBranch        *b_MET_y_STVF;   //!
   TBranch        *b_MET_phi_STVF;   //!
   TBranch        *b_METRel_STVF;   //!
   TBranch        *b_METRel_x_STVF;   //!
   TBranch        *b_METRel_y_STVF;   //!
   TBranch        *b_METRel_noJets_STVF;   //!
   TBranch        *b_MET_default_STVF;   //!
   TBranch        *b_MET_default_x_STVF;   //!
   TBranch        *b_MET_default_y_STVF;   //!
   TBranch        *b_MET_TrackHWW;   //!
   TBranch        *b_MET_x_TrackHWW;   //!
   TBranch        *b_MET_y_TrackHWW;   //!
   TBranch        *b_MET_phi_TrackHWW;   //!
   TBranch        *b_MinDPhi_TrackHWW;   //!
   TBranch        *b_MinDPhi_noJVF_TrackHWW;   //!
   TBranch        *b_METRel_Track_HWW;   //!
   TBranch        *b_METRel_x_TrackHWW;   //!
   TBranch        *b_METRel_y_TrackHWW;   //!
   TBranch        *b_DPhi_CaloTrackHWW;   //!
   TBranch        *b_MT_TrackHWW;   //!
   TBranch        *b_PtTrack_TrackHWW;   //!
   TBranch        *b_MTrans_TrackHWW;   //!
   TBranch        *b_Pttot_TrackHWW;   //!
   TBranch        *b_METRel_noJets_TrackHWW;   //!
   TBranch        *b_MET_TrackHWW_Cl;   //!
   TBranch        *b_MET_x_TrackHWW_Cl;   //!
   TBranch        *b_MET_y_TrackHWW_Cl;   //!
   TBranch        *b_MET_phi_TrackHWW_Cl;   //!
   TBranch        *b_MinDPhi_TrackHWW_Cl;   //!
   TBranch        *b_MinDPhi_noJVF_TrackHWW_Cl;   //!
   TBranch        *b_METRel_Track_HWW_Cl;   //!
   TBranch        *b_METRel_x_TrackHWW_Cl;   //!
   TBranch        *b_METRel_y_TrackHWW_Cl;   //!
   TBranch        *b_DPhi_CaloTrackHWW_Cl;   //!
   TBranch        *b_MT_TrackHWW_Cl;   //!
   TBranch        *b_PtTrack_TrackHWW_Cl;   //!
   TBranch        *b_MTrans_TrackHWW_Cl;   //!
   TBranch        *b_Pttot_TrackHWW_Cl;   //!
   TBranch        *b_METRel_noJets_TrackHWW_Cl;   //!
   TBranch        *b_MET_TrackHWW_Clj;   //!
   TBranch        *b_MET_x_TrackHWW_Clj;   //!
   TBranch        *b_MET_y_TrackHWW_Clj;   //!
   TBranch        *b_MET_phi_TrackHWW_Clj;   //!
   TBranch        *b_MinDPhi_TrackHWW_Clj;   //!
   TBranch        *b_MinDPhi_noJVF_TrackHWW_Clj;   //!
   TBranch        *b_METRel_Track_HWW_Clj;   //!
   TBranch        *b_METRel_x_TrackHWW_Clj;   //!
   TBranch        *b_METRel_y_TrackHWW_Clj;   //!
   TBranch        *b_DPhi_CaloTrackHWW_Clj;   //!
   TBranch        *b_MT_TrackHWW_Clj;   //!
   TBranch        *b_PtTrack_TrackHWW_Clj;   //!
   TBranch        *b_MTrans_TrackHWW_Clj;   //!
   TBranch        *b_Pttot_TrackHWW_Clj;   //!
   TBranch        *b_METRel_noJets_TrackHWW_Clj;   //!
   TBranch        *b_lepID0;   //!
   TBranch        *b_isMPP_ele;   //!
   TBranch        *b_isTPP_ele;   //!
   TBranch        *b_isIso_ele;   //!
   TBranch        *b_isD0_muon;   //!
   TBranch        *b_isIso_muon;   //!
   TBranch        *b_isIsoJet_muon;   //!
   TBranch        *b_isIsoJet_muon_EM;   //!
   //   TBranch        *b_lepMatch_EF_mu24i_tight_0;   //!
   //  TBranch        *b_lepMatch_EF_mu36_tight_0;   //!
   //  TBranch        *b_lepMatch_EF_e24vhi_medium1_0;   //!
   //  TBranch        *b_lepMatch_EF_e60_medium1_0;   //!
   TBranch        *b_lepMatch_EF_mu24i_tight;   //!
   TBranch        *b_lepMatch_EF_mu36_tight;   //!
   TBranch        *b_lepMatch_EF_e24vhi_medium1;   //!
   TBranch        *b_lepMatch_EF_e60_medium1;   //!
   TBranch        *b_elec_trigger24;   //!
   TBranch        *b_elec_trigger60;   //!
   TBranch        *b_muon_trigger24;   //!
   TBranch        *b_muon_trigger36;   //!
   TBranch        *b_vertexEventWeight;   //!
   TBranch        *b_vertexEventWeight_Pu1;   //!
   TBranch        *b_vertexEventWeight_Pu088;   //!
   TBranch        *b_pileupEventWeight;   //!
   TBranch        *b_pileupEventWeight_094;   //!
   TBranch        *b_pileupEventWeight_080;   //!
   TBranch        *b_pileupEventWeight_090;   //!
   TBranch        *b_pileupEventWeight_088;   //!
   TBranch        *b_pileupEventWeight_075;   //!
   TBranch        *b_pileupEventWeight_103;   //!
   TBranch        *b_higgsPtEventWeight;   //!
   TBranch        *b_higgsMEventWeight;   //!
   TBranch        *b_higgsPtError;   //!
   TBranch        *b_didEJOverlap;   //!
   TBranch        *b_didMJOverlap;   //!
   TBranch        *b_mcEventWeight;   //!
   TBranch        *b_mcEventWeightUp;   //!
   TBranch        *b_mcEventWeightDown;   //!
   TBranch        *b_tauPolWeight;   //!
   TBranch        *b_mcWeightOrg;   //!
   TBranch        *b_trigEventWeight;   //!
   TBranch        *b_lepTrigSFEventWeight;   //!
   TBranch        *b_lepTrigSFEventWeightUp;   //!
   TBranch        *b_lepTrigSFEventWeightDown;   //!
   TBranch        *b_lepSFEventWeight;   //!
   TBranch        *b_lepSFError;   //!
   TBranch        *b_lepSFErrorReco;   //!
   TBranch        *b_lepSFErrorIso;   //!
   TBranch        *b_lepSFErrorSys;   //!
   TBranch        *b_MV1_value;   //!
   TBranch        *b_MV1_EventWeight;   //!
   TBranch        *b_MV1_EventWeightUp;   //!
   TBranch        *b_MV1_EventWeightDown;   //!
   TBranch        *b_MV1_VetoEventWeight;   //!
   TBranch        *b_MV1_VetoEventWeightUp;   //!
   TBranch        *b_MV1_VetoEventWeightDown;   //!
   //&&&&
   TBranch        *b_MV1_EventWeight_60;   //!
   TBranch        *b_MV1_EventWeightUp_60;   //!
   TBranch        *b_MV1_EventWeightDown_60;   //!
   TBranch        *b_MV1_VetoEventWeight_60;   //!
   TBranch        *b_MV1_VetoEventWeightUp_60;   //!
   TBranch        *b_MV1_VetoEventWeightDown_60;   //!
   
   TBranch        *b_InterferenceW_cen;   //!
   TBranch        *b_InterferenceW_ErrUp;   //!
   TBranch        *b_InterferenceW_ErrDown;   //!
   TBranch        *b_SMWidthWeight;   //!
   TBranch        *b_truth_evtNumber;   //!
   TBranch        *b_truth_l_pt;   //!
   TBranch        *b_truth_nu_pt;   //!
   TBranch        *b_truth_j0_pt;   //!
   TBranch        *b_truth_j1_pt;   //!
   TBranch        *b_truth_W0_pt;   //!
   TBranch        *b_truth_W1_pt;   //!
   TBranch        *b_truth_H_pt;   //!
   TBranch        *b_truth_l_eta;   //!
   TBranch        *b_truth_nu_eta;   //!
   TBranch        *b_truth_j0_eta;   //!
   TBranch        *b_truth_j1_eta;   //!
   TBranch        *b_truth_W0_eta;   //!
   TBranch        *b_truth_W1_eta;   //!
   TBranch        *b_truth_H_eta;   //!
   TBranch        *b_truth_l_phi;   //!
   TBranch        *b_truth_nu_phi;   //!
   TBranch        *b_truth_j0_phi;   //!
   TBranch        *b_truth_j1_phi;   //!
   TBranch        *b_truth_W0_phi;   //!
   TBranch        *b_truth_W1_phi;   //!
   TBranch        *b_truth_H_phi;   //!
   TBranch        *b_truth_W0_m;   //!
   TBranch        *b_truth_W1_m;   //!
   TBranch        *b_truth_l_m;   //!
   TBranch        *b_truth_nu_m;   //!
   TBranch        *b_truth_j0_m;   //!
   TBranch        *b_truth_j1_m;   //!
   TBranch        *b_truth_H_m;   //!
   TBranch        *b_truth_l_pdgId;   //!
   TBranch        *b_truth_j0_pdgId;   //!
   TBranch        *b_truth_j1_pdgId;   //!
   TBranch        *b_truth_W0_pdgId;   //!
   TBranch        *b_truth_W1_pdgId;   //!
   TBranch        *b_truth_W0_leptonic;   //!
   TBranch        *b_Nvxp;   //!
   TBranch        *b_bpos;   //!
   TBranch        *b_blen;   //!
   TBranch        *b_bgap;   //!
   TBranch        *b_ttbarWeight;   //!
   TBranch        *b_truth_sherpa_Wpt;   //!
   TBranch        *b_truth_sherpa_Zpt;   //!
   TBranch        *b_mctruth_pdgId;   //!
   TBranch        *b_mctruth_pt;   //!
   TBranch        *b_mctruth_eta;   //!
   TBranch        *b_mctruth_phi;   //!
   TBranch        *b_mctruth_m;   //!
   TBranch        *b_mctruth_parent;   //!
   TBranch        *b_truthStable_el_pt;   //!
   TBranch        *b_truthStable_el_eta;   //!
   TBranch        *b_truthStable_el_phi;   //!
   TBranch        *b_truthStable_mu_pt;   //!
   TBranch        *b_truthStable_mu_eta;   //!
   TBranch        *b_truthStable_mu_phi;   //!
   TBranch        *b_truthStable_ph_pt;   //!
   TBranch        *b_truthStable_ph_eta;   //!
   TBranch        *b_truthStable_ph_phi;   //!
   TBranch        *b_MET_truth_nonint;   //!
   TBranch        *b_MET_truth_nonint_x;   //!
   TBranch        *b_MET_truth_nonint_y;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_IsBadMediumBCH;   //!
   TBranch        *b_IsBadMediumBCHUp;   //!
   TBranch        *b_IsBadMediumBCHDown;   //!
   TBranch        *b_IsBadTightBCH;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_actualIntPerXing;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_larError;   //!
   TBranch        *b_m_el_n;   //!
   TBranch        *b_m_el_E;   //!
   TBranch        *b_m_el_pt;   //!
   TBranch        *b_m_el_eta;   //!
   TBranch        *b_m_el_phi;   //!
   TBranch        *b_m_el_charge;   //!
   TBranch        *b_m_el_trackd0pv;   //!
   TBranch        *b_m_el_tracksigd0pv;   //!
   TBranch        *b_m_el_ptcone30;   //!
   TBranch        *b_m_el_etcone30;   //!
   TBranch        *b_m_el_z0sinth;   //!
   TBranch        *b_m_mu_n;   //!
   TBranch        *b_m_mu_E;   //!
   TBranch        *b_m_mu_pt;   //!
   TBranch        *b_m_mu_eta;   //!
   TBranch        *b_m_mu_phi;   //!
   TBranch        *b_m_mu_charge;   //!
   TBranch        *b_m_mu_matchchi2;   //!
   TBranch        *b_m_mu_matchndof;   //!
   TBranch        *b_m_mu_energyLossPar;   //!
   TBranch        *b_m_mu_etCore;   //!
   TBranch        *b_m_mu_id_d0_exPV;   //!
   TBranch        *b_m_mu_id_theta_exPV;   //!
   TBranch        *b_m_mu_id_qoverp_exPV;   //!
   TBranch        *b_m_mu_me_theta_exPV;   //!
   TBranch        *b_m_mu_me_qoverp_exPV;   //!
   TBranch        *b_m_mu_id_cov_d0_exPV;   //!
   TBranch        *b_m_mu_etcone30;   //!
   TBranch        *b_m_mu_ptcone30;   //!
   TBranch        *b_m_mu_trackd0pv;   //!
   TBranch        *b_m_mu_tracksigd0pv;   //!
   TBranch        *b_m_mu_z0sinth;   //!
      
   TBranch        *b_m_jetTruth_n;   //!
   TBranch        *b_m_jetTruth_pt;   //!
   TBranch        *b_m_jetTruth_eta;   //!
   TBranch        *b_m_mfcajet_n;   //!
   TBranch        *b_m_mfcajet_E;   //!
   TBranch        *b_m_mfcajet_pt;   //!
   TBranch        *b_m_mfcajet_m;   //!
   TBranch        *b_m_mfcajet_eta;   //!
   TBranch        *b_m_mfcajet_phi;   //!
   TBranch        *b_m_jet_n;   //!
   TBranch        *b_m_jet_E;   //!
   TBranch        *b_m_jet_pt;   //!
   TBranch        *b_m_jet_eta;   //!
   TBranch        *b_m_jet_phi;   //!
   TBranch        *b_m_jet_LArQuality;   //!
   TBranch        *b_m_jet_sumPtTrk;   //!
   TBranch        *b_m_jet_jvtxf;   //!
   TBranch        *b_m_jet_flavor_weight_JetFitterCharm;   //!
   TBranch        *b_m_jet_flavor_weight_MV1;   //!
   TBranch        *b_m_jet_flavor_truth_label;   //!
   TBranch        *b_m_jet_emfrac;   //!
   TBranch        *b_m_jet_EM_n;   //!
   TBranch        *b_m_jet_EM_E;   //!
   TBranch        *b_m_jet_EM_pt;   //!
   TBranch        *b_m_jet_EM_eta;   //!
   TBranch        *b_m_jet_EM_phi;   //!
   TBranch        *b_m_jet_EM_LArQuality;   //!
   TBranch        *b_m_jet_EM_sumPtTrk;   //!
   TBranch        *b_m_jet_EM_jvtxf;   //!
   TBranch        *b_m_jet_EM_flavor_weight_MV1;   //!
   TBranch        *b_m_jet_EM_flavor_truth_label;   //!
   TBranch        *b_m_vxp_n;   //!
   TBranch        *b_m_vxp_nTracks;   //!
   TBranch        *b_m_mcevt_pdf_id1;   //!
   TBranch        *b_m_mcevt_pdf_id2;   //!
   TBranch        *b_m_mcevt_pdf_x1;   //!
   TBranch        *b_m_mcevt_pdf_x2;   //!
   TBranch        *b_m_mcevt_pdf_scale;   //!

   foo(TTree *tree=0);
   virtual ~foo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef foo_cxx
foo::foo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("group.phys-higgs.393560_032808._00001.HWWSkimmedNTUP_lvqq.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("group.phys-higgs.393560_032808._00001.HWWSkimmedNTUP_lvqq.root");
      }
      f->GetObject("HWWTree_lvqq",tree);

   }
   Init(tree);
}

foo::~foo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t foo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t foo::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void foo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   smt_muon_pts = 0;
   smt_muon_etas = 0;
   smt_muon_phis = 0;
   smt_muon_charges = 0;
   isMPP_ele = 0;
   isTPP_ele = 0;
   isIso_ele = 0;
   isD0_muon = 0;
   isIso_muon = 0;
   isIsoJet_muon = 0;
   isIsoJet_muon_EM = 0;
   lepMatch_EF_mu24i_tight = 0;
   lepMatch_EF_mu36_tight = 0;
   lepMatch_EF_e24vhi_medium1 = 0;
   lepMatch_EF_e60_medium1 = 0;
   lepSFEventWeight =0;
   lepSFError =0;
   lepSFErrorReco =0;
   lepSFErrorIso =0;
   lepSFErrorSys =0;  
   MV1_value = 0;
   MV1_EventWeight = 0;
   MV1_EventWeightUp = 0;
   MV1_EventWeightDown = 0;
   MV1_VetoEventWeight = 0;
   MV1_VetoEventWeightUp = 0;
   MV1_VetoEventWeightDown = 0;
   //&&&&
   MV1_EventWeight_60 = 0;
   MV1_EventWeightUp_60 = 0;
   MV1_EventWeightDown_60 = 0;
   MV1_VetoEventWeight_60 = 0;
   MV1_VetoEventWeightUp_60 = 0;
   MV1_VetoEventWeightDown_60 = 0;
   
   mctruth_pdgId = 0;
   mctruth_pt = 0;
   mctruth_eta = 0;
   mctruth_phi = 0;
   mctruth_m = 0;
   mctruth_parent = 0;
   truthStable_el_pt = 0;
   truthStable_el_eta = 0;
   truthStable_el_phi = 0;
   truthStable_mu_pt = 0;
   truthStable_mu_eta = 0;
   truthStable_mu_phi = 0;
   truthStable_ph_pt = 0;
   truthStable_ph_eta = 0;
   truthStable_ph_phi = 0;
   m_el_E = 0;
   m_el_pt = 0;
   m_el_eta = 0;
   m_el_phi = 0;
   m_el_charge = 0;
   m_el_trackd0pv = 0;
   m_el_tracksigd0pv = 0;
   m_el_ptcone30 = 0;
   m_el_etcone30 = 0;
   m_el_z0sinth = 0;
   m_mu_E = 0;
   m_mu_pt = 0;
   m_mu_eta = 0;
   m_mu_phi = 0;
   m_mu_charge = 0;
   m_mu_matchchi2 = 0;
   m_mu_matchndof = 0;
   m_mu_energyLossPar = 0;
   m_mu_etCore = 0;
   m_mu_id_d0_exPV = 0;
   m_mu_id_theta_exPV = 0;
   m_mu_id_qoverp_exPV = 0;
   m_mu_me_theta_exPV = 0;
   m_mu_me_qoverp_exPV = 0;
   m_mu_id_cov_d0_exPV = 0;
   m_mu_trackd0pv = 0;
   m_mu_tracksigd0pv = 0;
   m_mu_ptcone30 = 0;
   m_mu_etcone30 = 0;
   m_mu_z0sinth = 0;
   m_jetTruth_pt = 0;
   m_jetTruth_eta = 0;
   m_mfcajet_E = 0;
   m_mfcajet_pt = 0;
   m_mfcajet_m = 0;
   m_mfcajet_eta = 0;
   m_mfcajet_phi = 0;
   m_jet_E = 0;
   m_jet_pt = 0;
   m_jet_eta = 0;
   m_jet_phi = 0;
   m_jet_LArQuality = 0;
   m_jet_sumPtTrk = 0;
   m_jet_jvtxf = 0;
   m_jet_flavor_weight_JetFitterCharm = 0;
   m_jet_flavor_weight_MV1 = 0;
   m_jet_flavor_truth_label = 0;
   m_jet_emfrac = 0;
   m_jet_EM_E = 0;
   m_jet_EM_pt = 0;
   m_jet_EM_eta = 0;
   m_jet_EM_phi = 0;
   m_jet_EM_LArQuality = 0;
   m_jet_EM_sumPtTrk = 0;
   m_jet_EM_jvtxf = 0;
   m_jet_EM_flavor_weight_MV1 = 0;
   m_jet_EM_flavor_truth_label = 0;
   m_vxp_nTracks = 0;
   m_mcevt_pdf_id1 = 0;
   m_mcevt_pdf_id2 = 0;
   m_mcevt_pdf_x1 = 0;
   m_mcevt_pdf_x2 = 0;
   m_mcevt_pdf_scale = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("isE", &isE, &b_isE);
   fChain->SetBranchAddress("isM", &isM, &b_isM);
   fChain->SetBranchAddress("isJ", &isJ, &b_isJ);
   fChain->SetBranchAddress("higgsPt", &higgsPt, &b_higgsPt);
   fChain->SetBranchAddress("MT", &MT, &b_MT);
   fChain->SetBranchAddress("MTrans", &MTrans, &b_MTrans);
   fChain->SetBranchAddress("Pttot", &Pttot, &b_Pttot);
   fChain->SetBranchAddress("Mjj", &Mjj, &b_Mjj);
   fChain->SetBranchAddress("Ptjj", &Ptjj, &b_Ptjj);
   fChain->SetBranchAddress("DPhijj", &DPhijj, &b_DPhijj);
   fChain->SetBranchAddress("DRjj", &DRjj, &b_DRjj);
   fChain->SetBranchAddress("DEtajj", &DEtajj, &b_DEtajj);
   fChain->SetBranchAddress("DYjj", &DYjj, &b_DYjj);
   fChain->SetBranchAddress("smt_muon_pt", &smt_muon_pt, &b_smt_muon_pt);
   fChain->SetBranchAddress("smt_muon_sf", &smt_muon_sf, &b_smt_muon_sf);
   fChain->SetBranchAddress("smt_muon_mistag_sf_up", &smt_muon_mistag_sf_up, &b_smt_muon_mistag_sf_up);
   fChain->SetBranchAddress("smt_muon_mistag_sf_dw", &smt_muon_mistag_sf_dw, &b_smt_muon_mistag_sf_dw);
   fChain->SetBranchAddress("smt_muon_chi2_sf_up", &smt_muon_chi2_sf_up, &b_smt_muon_chi2_sf_up);
   fChain->SetBranchAddress("smt_muon_chi2_sf_dw", &smt_muon_chi2_sf_dw, &b_smt_muon_chi2_sf_dw);
   fChain->SetBranchAddress("smt_muon_id_sf_up", &smt_muon_id_sf_up, &b_smt_muon_id_sf_up);
   fChain->SetBranchAddress("smt_muon_id_sf_dw", &smt_muon_id_sf_dw, &b_smt_muon_id_sf_dw);
   fChain->SetBranchAddress("smt_muon_pts", &smt_muon_pts, &b_smt_muon_pts);
   fChain->SetBranchAddress("smt_muon_etas", &smt_muon_etas, &b_smt_muon_etas);
   fChain->SetBranchAddress("smt_muon_phis", &smt_muon_phis, &b_smt_muon_phis);
   fChain->SetBranchAddress("smt_muon_charges", &smt_muon_charges, &b_smt_muon_charges);
   fChain->SetBranchAddress("BLayer_hit0", &BLayer_hit0, &b_BLayer_hit0);
   fChain->SetBranchAddress("conv0", &conv0, &b_conv0);
   fChain->SetBranchAddress("RandomRunNumber", &RandomRunNumber, &b_RandomRunNumber);
   fChain->SetBranchAddress("MinDPhi", &MinDPhi, &b_MinDPhi);
   fChain->SetBranchAddress("MinDPhi_noJVF", &MinDPhi_noJVF, &b_MinDPhi_noJVF);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("MET_x", &MET_x, &b_MET_x);
   fChain->SetBranchAddress("MET_y", &MET_y, &b_MET_y);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("METRel", &METRel, &b_METRel);
   fChain->SetBranchAddress("METRel_x", &METRel_x, &b_METRel_x);
   fChain->SetBranchAddress("METRel_y", &METRel_y, &b_METRel_y);
   fChain->SetBranchAddress("METRel_noJets", &METRel_noJets, &b_METRel_noJets);
   fChain->SetBranchAddress("MET_default", &MET_default, &b_MET_default);
   fChain->SetBranchAddress("MET_default_x", &MET_default_x, &b_MET_default_x);
   fChain->SetBranchAddress("MET_default_y", &MET_default_y, &b_MET_default_y);
   fChain->SetBranchAddress("MinDPhi_STVF", &MinDPhi_STVF, &b_MinDPhi_STVF);
   fChain->SetBranchAddress("MinDPhi_noJVF_STVF", &MinDPhi_noJVF_STVF, &b_MinDPhi_noJVF_STVF);
   fChain->SetBranchAddress("MT_STVF", &MT_STVF, &b_MT_STVF);
   fChain->SetBranchAddress("MTrans_STVF", &MTrans_STVF, &b_MTrans_STVF);
   fChain->SetBranchAddress("Pttot_STVF", &Pttot_STVF, &b_Pttot_STVF);
   fChain->SetBranchAddress("MET_STVF", &MET_STVF, &b_MET_STVF);
   fChain->SetBranchAddress("MET_x_STVF", &MET_x_STVF, &b_MET_x_STVF);
   fChain->SetBranchAddress("MET_y_STVF", &MET_y_STVF, &b_MET_y_STVF);
   fChain->SetBranchAddress("MET_phi_STVF", &MET_phi_STVF, &b_MET_phi_STVF);
   fChain->SetBranchAddress("METRel_STVF", &METRel_STVF, &b_METRel_STVF);
   fChain->SetBranchAddress("METRel_x_STVF", &METRel_x_STVF, &b_METRel_x_STVF);
   fChain->SetBranchAddress("METRel_y_STVF", &METRel_y_STVF, &b_METRel_y_STVF);
   fChain->SetBranchAddress("METRel_noJets_STVF", &METRel_noJets_STVF, &b_METRel_noJets_STVF);
   fChain->SetBranchAddress("MET_default_STVF", &MET_default_STVF, &b_MET_default_STVF);
   fChain->SetBranchAddress("MET_default_x_STVF", &MET_default_x_STVF, &b_MET_default_x_STVF);
   fChain->SetBranchAddress("MET_default_y_STVF", &MET_default_y_STVF, &b_MET_default_y_STVF);
   fChain->SetBranchAddress("MET_TrackHWW", &MET_TrackHWW, &b_MET_TrackHWW);
   fChain->SetBranchAddress("MET_x_TrackHWW", &MET_x_TrackHWW, &b_MET_x_TrackHWW);
   fChain->SetBranchAddress("MET_y_TrackHWW", &MET_y_TrackHWW, &b_MET_y_TrackHWW);
   fChain->SetBranchAddress("MET_phi_TrackHWW", &MET_phi_TrackHWW, &b_MET_phi_TrackHWW);
   fChain->SetBranchAddress("MinDPhi_TrackHWW", &MinDPhi_TrackHWW, &b_MinDPhi_TrackHWW);
   fChain->SetBranchAddress("MinDPhi_noJVF_TrackHWW", &MinDPhi_noJVF_TrackHWW, &b_MinDPhi_noJVF_TrackHWW);
   fChain->SetBranchAddress("METRel_TrackHWW", &METRel_TrackHWW, &b_METRel_Track_HWW);
   fChain->SetBranchAddress("METRel_x_TrackHWW", &METRel_x_TrackHWW, &b_METRel_x_TrackHWW);
   fChain->SetBranchAddress("METRel_y_TrackHWW", &METRel_y_TrackHWW, &b_METRel_y_TrackHWW);
   fChain->SetBranchAddress("DPhi_CaloTrackHWW", &DPhi_CaloTrackHWW, &b_DPhi_CaloTrackHWW);
   fChain->SetBranchAddress("MT_TrackHWW", &MT_TrackHWW, &b_MT_TrackHWW);
   fChain->SetBranchAddress("PtTrack_TrackHWW", &PtTrack_TrackHWW, &b_PtTrack_TrackHWW);
   fChain->SetBranchAddress("MTrans_TrackHWW", &MTrans_TrackHWW, &b_MTrans_TrackHWW);
   fChain->SetBranchAddress("Pttot_TrackHWW", &Pttot_TrackHWW, &b_Pttot_TrackHWW);
   fChain->SetBranchAddress("METRel_noJets_TrackHWW", &METRel_noJets_TrackHWW, &b_METRel_noJets_TrackHWW);
   fChain->SetBranchAddress("MET_TrackHWW_Cl", &MET_TrackHWW_Cl, &b_MET_TrackHWW_Cl);
   fChain->SetBranchAddress("MET_x_TrackHWW_Cl", &MET_x_TrackHWW_Cl, &b_MET_x_TrackHWW_Cl);
   fChain->SetBranchAddress("MET_y_TrackHWW_Cl", &MET_y_TrackHWW_Cl, &b_MET_y_TrackHWW_Cl);
   fChain->SetBranchAddress("MET_phi_TrackHWW_Cl", &MET_phi_TrackHWW_Cl, &b_MET_phi_TrackHWW_Cl);
   fChain->SetBranchAddress("MinDPhi_TrackHWW_Cl", &MinDPhi_TrackHWW_Cl, &b_MinDPhi_TrackHWW_Cl);
   fChain->SetBranchAddress("MinDPhi_noJVF_TrackHWW_Cl", &MinDPhi_noJVF_TrackHWW_Cl, &b_MinDPhi_noJVF_TrackHWW_Cl);
   fChain->SetBranchAddress("METRel_TrackHWW_Cl", &METRel_TrackHWW_Cl, &b_METRel_Track_HWW_Cl);
   fChain->SetBranchAddress("METRel_x_TrackHWW_Cl", &METRel_x_TrackHWW_Cl, &b_METRel_x_TrackHWW_Cl);
   fChain->SetBranchAddress("METRel_y_TrackHWW_Cl", &METRel_y_TrackHWW_Cl, &b_METRel_y_TrackHWW_Cl);
   fChain->SetBranchAddress("DPhi_CaloTrackHWW_Cl", &DPhi_CaloTrackHWW_Cl, &b_DPhi_CaloTrackHWW_Cl);
   fChain->SetBranchAddress("MT_TrackHWW_Cl", &MT_TrackHWW_Cl, &b_MT_TrackHWW_Cl);
   fChain->SetBranchAddress("PtTrack_TrackHWW_Cl", &PtTrack_TrackHWW_Cl, &b_PtTrack_TrackHWW_Cl);
   fChain->SetBranchAddress("MTrans_TrackHWW_Cl", &MTrans_TrackHWW_Cl, &b_MTrans_TrackHWW_Cl);
   fChain->SetBranchAddress("Pttot_TrackHWW_Cl", &Pttot_TrackHWW_Cl, &b_Pttot_TrackHWW_Cl);
   fChain->SetBranchAddress("METRel_noJets_TrackHWW_Cl", &METRel_noJets_TrackHWW_Cl, &b_METRel_noJets_TrackHWW_Cl);
   fChain->SetBranchAddress("MET_TrackHWW_Clj", &MET_TrackHWW_Clj, &b_MET_TrackHWW_Clj);
   fChain->SetBranchAddress("MET_x_TrackHWW_Clj", &MET_x_TrackHWW_Clj, &b_MET_x_TrackHWW_Clj);
   fChain->SetBranchAddress("MET_y_TrackHWW_Clj", &MET_y_TrackHWW_Clj, &b_MET_y_TrackHWW_Clj);
   fChain->SetBranchAddress("MET_phi_TrackHWW_Clj", &MET_phi_TrackHWW_Clj, &b_MET_phi_TrackHWW_Clj);
   fChain->SetBranchAddress("MinDPhi_TrackHWW_Clj", &MinDPhi_TrackHWW_Clj, &b_MinDPhi_TrackHWW_Clj);
   fChain->SetBranchAddress("MinDPhi_noJVF_TrackHWW_Clj", &MinDPhi_noJVF_TrackHWW_Clj, &b_MinDPhi_noJVF_TrackHWW_Clj);
   fChain->SetBranchAddress("METRel_TrackHWW_Clj", &METRel_TrackHWW_Clj, &b_METRel_Track_HWW_Clj);
   fChain->SetBranchAddress("METRel_x_TrackHWW_Clj", &METRel_x_TrackHWW_Clj, &b_METRel_x_TrackHWW_Clj);
   fChain->SetBranchAddress("METRel_y_TrackHWW_Clj", &METRel_y_TrackHWW_Clj, &b_METRel_y_TrackHWW_Clj);
   fChain->SetBranchAddress("DPhi_CaloTrackHWW_Clj", &DPhi_CaloTrackHWW_Clj, &b_DPhi_CaloTrackHWW_Clj);
   fChain->SetBranchAddress("MT_TrackHWW_Clj", &MT_TrackHWW_Clj, &b_MT_TrackHWW_Clj);
   fChain->SetBranchAddress("PtTrack_TrackHWW_Clj", &PtTrack_TrackHWW_Clj, &b_PtTrack_TrackHWW_Clj);
   fChain->SetBranchAddress("MTrans_TrackHWW_Clj", &MTrans_TrackHWW_Clj, &b_MTrans_TrackHWW_Clj);
   fChain->SetBranchAddress("Pttot_TrackHWW_Clj", &Pttot_TrackHWW_Clj, &b_Pttot_TrackHWW_Clj);
   fChain->SetBranchAddress("METRel_noJets_TrackHWW_Clj", &METRel_noJets_TrackHWW_Clj, &b_METRel_noJets_TrackHWW_Clj);
   fChain->SetBranchAddress("lepID", &lepID, &b_lepID0);
   fChain->SetBranchAddress("isMPP_ele", &isMPP_ele, &b_isMPP_ele);
   fChain->SetBranchAddress("isTPP_ele", &isTPP_ele, &b_isTPP_ele);
   fChain->SetBranchAddress("isIso_ele", &isIso_ele, &b_isIso_ele);
   fChain->SetBranchAddress("isD0_muon", &isD0_muon, &b_isD0_muon);
   fChain->SetBranchAddress("isIso_muon", &isIso_muon, &b_isIso_muon);
   fChain->SetBranchAddress("isIsoJet_muon", &isIsoJet_muon, &b_isIsoJet_muon);
   fChain->SetBranchAddress("isIsoJet_muon_EM", &isIsoJet_muon_EM, &b_isIsoJet_muon_EM);
   //   fChain->SetBranchAddress("lepMatch_EF_mu24i_tight_0", &lepMatch_EF_mu24i_tight_0, &b_lepMatch_EF_mu24i_tight_0);
   //  fChain->SetBranchAddress("lepMatch_EF_mu36_tight_0", &lepMatch_EF_mu36_tight_0, &b_lepMatch_EF_mu36_tight_0);
   //   fChain->SetBranchAddress("lepMatch_EF_e24vhi_medium1_0", &lepMatch_EF_e24vhi_medium1_0, &b_lepMatch_EF_e24vhi_medium1_0);
   //   fChain->SetBranchAddress("lepMatch_EF_e60_medium1_0", &lepMatch_EF_e60_medium1_0, &b_lepMatch_EF_e60_medium1_0);
   fChain->SetBranchAddress("lepMatch_EF_mu24i_tight", &lepMatch_EF_mu24i_tight, &b_lepMatch_EF_mu24i_tight);
   fChain->SetBranchAddress("lepMatch_EF_mu36_tight", &lepMatch_EF_mu36_tight, &b_lepMatch_EF_mu36_tight);
   fChain->SetBranchAddress("lepMatch_EF_e24vhi_medium1", &lepMatch_EF_e24vhi_medium1, &b_lepMatch_EF_e24vhi_medium1);
   fChain->SetBranchAddress("lepMatch_EF_e60_medium1", &lepMatch_EF_e60_medium1, &b_lepMatch_EF_e60_medium1);
   fChain->SetBranchAddress("elec_trigger24", &elec_trigger24, &b_elec_trigger24);
   fChain->SetBranchAddress("elec_trigger60", &elec_trigger60, &b_elec_trigger60);
   fChain->SetBranchAddress("muon_trigger24", &muon_trigger24, &b_muon_trigger24);
   fChain->SetBranchAddress("muon_trigger36", &muon_trigger36, &b_muon_trigger36);
   fChain->SetBranchAddress("vertexEventWeight", &vertexEventWeight, &b_vertexEventWeight);
   fChain->SetBranchAddress("vertexEventWeight_Pu1", &vertexEventWeight_Pu1, &b_vertexEventWeight_Pu1);
   fChain->SetBranchAddress("vertexEventWeight_Pu088", &vertexEventWeight_Pu088, &b_vertexEventWeight_Pu088);
   fChain->SetBranchAddress("pileupEventWeight", &pileupEventWeight, &b_pileupEventWeight);
   fChain->SetBranchAddress("pileupEventWeight_094", &pileupEventWeight_094, &b_pileupEventWeight_094);
   fChain->SetBranchAddress("pileupEventWeight_080", &pileupEventWeight_080, &b_pileupEventWeight_080);
   fChain->SetBranchAddress("pileupEventWeight_090", &pileupEventWeight_090, &b_pileupEventWeight_090);
   fChain->SetBranchAddress("pileupEventWeight_088", &pileupEventWeight_088, &b_pileupEventWeight_088);
   fChain->SetBranchAddress("pileupEventWeight_075", &pileupEventWeight_075, &b_pileupEventWeight_075);
   fChain->SetBranchAddress("pileupEventWeight_103", &pileupEventWeight_103, &b_pileupEventWeight_103);
   fChain->SetBranchAddress("higgsPtEventWeight", &higgsPtEventWeight, &b_higgsPtEventWeight);
   fChain->SetBranchAddress("higgsMEventWeight", &higgsMEventWeight, &b_higgsMEventWeight);
   fChain->SetBranchAddress("higgsPtError", &higgsPtError, &b_higgsPtError);
   fChain->SetBranchAddress("didEJoverlap", &didEJoverlap, &b_didEJOverlap);
   fChain->SetBranchAddress("didMJoverlap", &didMJoverlap, &b_didMJOverlap);
   fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
   fChain->SetBranchAddress("mcEventWeightUp", &mcEventWeightUp, &b_mcEventWeightUp);
   fChain->SetBranchAddress("mcEventWeightDown", &mcEventWeightDown, &b_mcEventWeightDown);
   fChain->SetBranchAddress("tauPolWeight", &tauPolWeight, &b_tauPolWeight);
   fChain->SetBranchAddress("mcWeightOrg", &mcWeightOrg, &b_mcWeightOrg);
   fChain->SetBranchAddress("trigEventWeight", &trigEventWeight, &b_trigEventWeight);
   fChain->SetBranchAddress("lepTrigSFEventWeight", &lepTrigSFEventWeight, &b_lepTrigSFEventWeight);
   fChain->SetBranchAddress("lepTrigSFEventWeightUp", &lepTrigSFEventWeightUp, &b_lepTrigSFEventWeightUp);
   fChain->SetBranchAddress("lepTrigSFEventWeightDown", &lepTrigSFEventWeightDown, &b_lepTrigSFEventWeightDown);
   fChain->SetBranchAddress("lepSFEventWeight", &lepSFEventWeight, &b_lepSFEventWeight);
   fChain->SetBranchAddress("lepSFError", &lepSFError, &b_lepSFError);
   fChain->SetBranchAddress("lepSFErrorReco", &lepSFErrorReco, &b_lepSFErrorReco);
   fChain->SetBranchAddress("lepSFErrorIso", &lepSFErrorIso, &b_lepSFErrorIso);
   fChain->SetBranchAddress("lepSFErrorSys", &lepSFErrorSys, &b_lepSFErrorSys);
   fChain->SetBranchAddress("MV1_value", &MV1_value, &b_MV1_value);
   fChain->SetBranchAddress("MV1_EventWeight", &MV1_EventWeight, &b_MV1_EventWeight);
   fChain->SetBranchAddress("MV1_EventWeightUp", &MV1_EventWeightUp, &b_MV1_EventWeightUp);
   fChain->SetBranchAddress("MV1_EventWeightDown", &MV1_EventWeightDown, &b_MV1_EventWeightDown);
   fChain->SetBranchAddress("MV1_VetoEventWeight", &MV1_VetoEventWeight, &b_MV1_VetoEventWeight);
   fChain->SetBranchAddress("MV1_VetoEventWeightUp", &MV1_VetoEventWeightUp, &b_MV1_VetoEventWeightUp);
   fChain->SetBranchAddress("MV1_VetoEventWeightDown", &MV1_VetoEventWeightDown, &b_MV1_VetoEventWeightDown);
   ////&&&&
   fChain->SetBranchAddress("MV1_EventWeight_60", &MV1_EventWeight_60, &b_MV1_EventWeight_60);
   fChain->SetBranchAddress("MV1_EventWeightUp_60", &MV1_EventWeightUp_60, &b_MV1_EventWeightUp_60);
   fChain->SetBranchAddress("MV1_EventWeightDown_60", &MV1_EventWeightDown_60, &b_MV1_EventWeightDown_60);
   fChain->SetBranchAddress("MV1_VetoEventWeight_60", &MV1_VetoEventWeight_60, &b_MV1_VetoEventWeight_60);
   fChain->SetBranchAddress("MV1_VetoEventWeightUp_60", &MV1_VetoEventWeightUp_60, &b_MV1_VetoEventWeightUp_60);
   fChain->SetBranchAddress("MV1_VetoEventWeightDown_60", &MV1_VetoEventWeightDown_60, &b_MV1_VetoEventWeightDown_60);
   
   fChain->SetBranchAddress("InterferenceW_cen", InterferenceW_cen, &b_InterferenceW_cen);
   fChain->SetBranchAddress("InterferenceW_ErrUp", InterferenceW_ErrUp, &b_InterferenceW_ErrUp);
   fChain->SetBranchAddress("InterferenceW_ErrDown", InterferenceW_ErrDown, &b_InterferenceW_ErrDown);
   fChain->SetBranchAddress("SMWidthWeight", SMWidthWeight, &b_SMWidthWeight);
   fChain->SetBranchAddress("truth_evtNumber", &truth_evtNumber, &b_truth_evtNumber);
   fChain->SetBranchAddress("truth_l_pt", &truth_l_pt, &b_truth_l_pt);
   fChain->SetBranchAddress("truth_nu_pt", &truth_nu_pt, &b_truth_nu_pt);
   fChain->SetBranchAddress("truth_j0_pt", &truth_j0_pt, &b_truth_j0_pt);
   fChain->SetBranchAddress("truth_j1_pt", &truth_j1_pt, &b_truth_j1_pt);
   fChain->SetBranchAddress("truth_W0_pt", &truth_W0_pt, &b_truth_W0_pt);
   fChain->SetBranchAddress("truth_W1_pt", &truth_W1_pt, &b_truth_W1_pt);
   fChain->SetBranchAddress("truth_H_pt", &truth_H_pt, &b_truth_H_pt);
   fChain->SetBranchAddress("truth_l_eta", &truth_l_eta, &b_truth_l_eta);
   fChain->SetBranchAddress("truth_nu_eta", &truth_nu_eta, &b_truth_nu_eta);
   fChain->SetBranchAddress("truth_j0_eta", &truth_j0_eta, &b_truth_j0_eta);
   fChain->SetBranchAddress("truth_j1_eta", &truth_j1_eta, &b_truth_j1_eta);
   fChain->SetBranchAddress("truth_W0_eta", &truth_W0_eta, &b_truth_W0_eta);
   fChain->SetBranchAddress("truth_W1_eta", &truth_W1_eta, &b_truth_W1_eta);
   fChain->SetBranchAddress("truth_H_eta", &truth_H_eta, &b_truth_H_eta);
   fChain->SetBranchAddress("truth_l_phi", &truth_l_phi, &b_truth_l_phi);
   fChain->SetBranchAddress("truth_nu_phi", &truth_nu_phi, &b_truth_nu_phi);
   fChain->SetBranchAddress("truth_j0_phi", &truth_j0_phi, &b_truth_j0_phi);
   fChain->SetBranchAddress("truth_j1_phi", &truth_j1_phi, &b_truth_j1_phi);
   fChain->SetBranchAddress("truth_W0_phi", &truth_W0_phi, &b_truth_W0_phi);
   fChain->SetBranchAddress("truth_W1_phi", &truth_W1_phi, &b_truth_W1_phi);
   fChain->SetBranchAddress("truth_H_phi", &truth_H_phi, &b_truth_H_phi);
   fChain->SetBranchAddress("truth_W0_m", &truth_W0_m, &b_truth_W0_m);
   fChain->SetBranchAddress("truth_W1_m", &truth_W1_m, &b_truth_W1_m);
   fChain->SetBranchAddress("truth_l_m", &truth_l_m, &b_truth_l_m);
   fChain->SetBranchAddress("truth_nu_m", &truth_nu_m, &b_truth_nu_m);
   fChain->SetBranchAddress("truth_j0_m", &truth_j0_m, &b_truth_j0_m);
   fChain->SetBranchAddress("truth_j1_m", &truth_j1_m, &b_truth_j1_m);
   fChain->SetBranchAddress("truth_H_m", &truth_H_m, &b_truth_H_m);
   fChain->SetBranchAddress("truth_l_pdgId", &truth_l_pdgId, &b_truth_l_pdgId);
   fChain->SetBranchAddress("truth_j0_pdgId", &truth_j0_pdgId, &b_truth_j0_pdgId);
   fChain->SetBranchAddress("truth_j1_pdgId", &truth_j1_pdgId, &b_truth_j1_pdgId);
   fChain->SetBranchAddress("truth_W0_pdgId", &truth_W0_pdgId, &b_truth_W0_pdgId);
   fChain->SetBranchAddress("truth_W1_pdgId", &truth_W1_pdgId, &b_truth_W1_pdgId);
   fChain->SetBranchAddress("truth_W0_leptonic", &truth_W0_leptonic, &b_truth_W0_leptonic);
   fChain->SetBranchAddress("Nvxp", &Nvxp, &b_Nvxp);
   fChain->SetBranchAddress("bpos", &bpos, &b_bpos);
   fChain->SetBranchAddress("blen", &blen, &b_blen);
   fChain->SetBranchAddress("bgap", &bgap, &b_bgap);
   fChain->SetBranchAddress("ttbarWeight", &ttbarWeight, &b_ttbarWeight);
   fChain->SetBranchAddress("truth_sherpa_Wpt", &truth_sherpa_Wpt, &b_truth_sherpa_Wpt);
   fChain->SetBranchAddress("truth_sherpa_Zpt", &truth_sherpa_Zpt, &b_truth_sherpa_Zpt);
   fChain->SetBranchAddress("mctruth_pdgId", &mctruth_pdgId, &b_mctruth_pdgId);
   fChain->SetBranchAddress("mctruth_pt", &mctruth_pt, &b_mctruth_pt);
   fChain->SetBranchAddress("mctruth_eta", &mctruth_eta, &b_mctruth_eta);
   fChain->SetBranchAddress("mctruth_phi", &mctruth_phi, &b_mctruth_phi);
   fChain->SetBranchAddress("mctruth_m", &mctruth_m, &b_mctruth_m);
   fChain->SetBranchAddress("mctruth_parent", &mctruth_parent, &b_mctruth_parent);
   fChain->SetBranchAddress("truthStable_el_pt", &truthStable_el_pt, &b_truthStable_el_pt);
   fChain->SetBranchAddress("truthStable_el_eta", &truthStable_el_eta, &b_truthStable_el_eta);
   fChain->SetBranchAddress("truthStable_el_phi", &truthStable_el_phi, &b_truthStable_el_phi);
   fChain->SetBranchAddress("truthStable_mu_pt", &truthStable_mu_pt, &b_truthStable_mu_pt);
   fChain->SetBranchAddress("truthStable_mu_eta", &truthStable_mu_eta, &b_truthStable_mu_eta);
   fChain->SetBranchAddress("truthStable_mu_phi", &truthStable_mu_phi, &b_truthStable_mu_phi);
   fChain->SetBranchAddress("truthStable_ph_pt", &truthStable_ph_pt, &b_truthStable_ph_pt);
   fChain->SetBranchAddress("truthStable_ph_eta", &truthStable_ph_eta, &b_truthStable_ph_eta);
   fChain->SetBranchAddress("truthStable_ph_phi", &truthStable_ph_phi, &b_truthStable_ph_phi);
   fChain->SetBranchAddress("MET_truth_nonint", &MET_truth_nonint, &b_MET_truth_nonint);
   fChain->SetBranchAddress("MET_truth_nonint_x", &MET_truth_nonint_x, &b_MET_truth_nonint_x);
   fChain->SetBranchAddress("MET_truth_nonint_y", &MET_truth_nonint_y, &b_MET_truth_nonint_y);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("IsBadMediumBCH", &IsBadMediumBCH, &b_IsBadMediumBCH);
   fChain->SetBranchAddress("IsBadMediumBCHUp", &IsBadMediumBCHUp, &b_IsBadMediumBCHUp);
   fChain->SetBranchAddress("IsBadMediumBCHDown", &IsBadMediumBCHDown, &b_IsBadMediumBCHDown);
   fChain->SetBranchAddress("IsBadTightBCH", &IsBadTightBCH, &b_IsBadTightBCH);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("larError", &larError, &b_larError);
   fChain->SetBranchAddress("m_el_n", &m_el_n, &b_m_el_n);
   fChain->SetBranchAddress("m_el_E", &m_el_E, &b_m_el_E);
   fChain->SetBranchAddress("m_el_pt", &m_el_pt, &b_m_el_pt);
   fChain->SetBranchAddress("m_el_eta", &m_el_eta, &b_m_el_eta);
   fChain->SetBranchAddress("m_el_phi", &m_el_phi, &b_m_el_phi);
   fChain->SetBranchAddress("m_el_charge", &m_el_charge, &b_m_el_charge);
   fChain->SetBranchAddress("m_el_trackd0pv", &m_el_trackd0pv, &b_m_el_trackd0pv);
   fChain->SetBranchAddress("m_el_tracksigd0pv", &m_el_tracksigd0pv, &b_m_el_tracksigd0pv);
   fChain->SetBranchAddress("m_el_ptcone30", &m_el_ptcone30, &b_m_el_ptcone30);
   fChain->SetBranchAddress("m_el_etcone30", &m_el_etcone30, &b_m_el_etcone30);
   fChain->SetBranchAddress("m_el_z0sinth", &m_el_z0sinth, &b_m_el_z0sinth);
   fChain->SetBranchAddress("m_mu_n", &m_mu_n, &b_m_mu_n);
   fChain->SetBranchAddress("m_mu_E", &m_mu_E, &b_m_mu_E);
   fChain->SetBranchAddress("m_mu_pt", &m_mu_pt, &b_m_mu_pt);
   fChain->SetBranchAddress("m_mu_eta", &m_mu_eta, &b_m_mu_eta);
   fChain->SetBranchAddress("m_mu_phi", &m_mu_phi, &b_m_mu_phi);
   fChain->SetBranchAddress("m_mu_charge", &m_mu_charge, &b_m_mu_charge);
   fChain->SetBranchAddress("m_mu_matchchi2", &m_mu_matchchi2, &b_m_mu_matchchi2);
   fChain->SetBranchAddress("m_mu_matchndof", &m_mu_matchndof, &b_m_mu_matchndof);
   fChain->SetBranchAddress("m_mu_energyLossPar", &m_mu_energyLossPar, &b_m_mu_energyLossPar);
   fChain->SetBranchAddress("m_mu_etCore", &m_mu_etCore, &b_m_mu_etCore);
   fChain->SetBranchAddress("m_mu_id_d0_exPV", &m_mu_id_d0_exPV, &b_m_mu_id_d0_exPV);
   fChain->SetBranchAddress("m_mu_id_theta_exPV", &m_mu_id_theta_exPV, &b_m_mu_id_theta_exPV);
   fChain->SetBranchAddress("m_mu_id_qoverp_exPV", &m_mu_id_qoverp_exPV, &b_m_mu_id_qoverp_exPV);
   fChain->SetBranchAddress("m_mu_me_theta_exPV", &m_mu_me_theta_exPV, &b_m_mu_me_theta_exPV);
   fChain->SetBranchAddress("m_mu_me_qoverp_exPV", &m_mu_me_qoverp_exPV, &b_m_mu_me_qoverp_exPV);
   fChain->SetBranchAddress("m_mu_id_cov_d0_exPV", &m_mu_id_cov_d0_exPV, &b_m_mu_id_cov_d0_exPV);
   fChain->SetBranchAddress("m_mu_trackd0pv", &m_mu_trackd0pv, &b_m_mu_trackd0pv);
   fChain->SetBranchAddress("m_mu_tracksigd0pv", &m_mu_tracksigd0pv, &b_m_mu_tracksigd0pv);
   fChain->SetBranchAddress("m_mu_ptcone30", &m_mu_ptcone30, &b_m_mu_ptcone30);
   fChain->SetBranchAddress("m_mu_etcone30", &m_mu_etcone30, &b_m_mu_etcone30);
   fChain->SetBranchAddress("m_mu_z0sinth", &m_mu_z0sinth, &b_m_mu_z0sinth);
   fChain->SetBranchAddress("m_jetTruth_n", &m_jetTruth_n, &b_m_jetTruth_n);
   fChain->SetBranchAddress("m_jetTruth_pt", &m_jetTruth_pt, &b_m_jetTruth_pt);
   fChain->SetBranchAddress("m_jetTruth_eta", &m_jetTruth_eta, &b_m_jetTruth_eta);
   fChain->SetBranchAddress("m_mfcajet_n", &m_mfcajet_n, &b_m_mfcajet_n);
   fChain->SetBranchAddress("m_mfcajet_E", &m_mfcajet_E, &b_m_mfcajet_E);
   fChain->SetBranchAddress("m_mfcajet_pt", &m_mfcajet_pt, &b_m_mfcajet_pt);
   fChain->SetBranchAddress("m_mfcajet_m", &m_mfcajet_m, &b_m_mfcajet_m);
   fChain->SetBranchAddress("m_mfcajet_eta", &m_mfcajet_eta, &b_m_mfcajet_eta);
   fChain->SetBranchAddress("m_mfcajet_phi", &m_mfcajet_phi, &b_m_mfcajet_phi);
   fChain->SetBranchAddress("m_jet_n", &m_jet_n, &b_m_jet_n);
   fChain->SetBranchAddress("m_jet_E", &m_jet_E, &b_m_jet_E);
   fChain->SetBranchAddress("m_jet_pt", &m_jet_pt, &b_m_jet_pt);
   fChain->SetBranchAddress("m_jet_eta", &m_jet_eta, &b_m_jet_eta);
   fChain->SetBranchAddress("m_jet_phi", &m_jet_phi, &b_m_jet_phi);
   fChain->SetBranchAddress("m_jet_LArQuality", &m_jet_LArQuality, &b_m_jet_LArQuality);
   fChain->SetBranchAddress("m_jet_sumPtTrk", &m_jet_sumPtTrk, &b_m_jet_sumPtTrk);
   fChain->SetBranchAddress("m_jet_jvtxf", &m_jet_jvtxf, &b_m_jet_jvtxf);
   fChain->SetBranchAddress("m_jet_flavor_weight_JetFitterCharm", &m_jet_flavor_weight_JetFitterCharm, &b_m_jet_flavor_weight_JetFitterCharm);
   fChain->SetBranchAddress("m_jet_flavor_weight_MV1", &m_jet_flavor_weight_MV1, &b_m_jet_flavor_weight_MV1);
   fChain->SetBranchAddress("m_jet_flavor_truth_label", &m_jet_flavor_truth_label, &b_m_jet_flavor_truth_label);
   fChain->SetBranchAddress("m_jet_emfrac", &m_jet_emfrac, &b_m_jet_emfrac);
   fChain->SetBranchAddress("m_jet_EM_n", &m_jet_EM_n, &b_m_jet_EM_n);
   fChain->SetBranchAddress("m_jet_EM_E", &m_jet_EM_E, &b_m_jet_EM_E);
   fChain->SetBranchAddress("m_jet_EM_pt", &m_jet_EM_pt, &b_m_jet_EM_pt);
   fChain->SetBranchAddress("m_jet_EM_eta", &m_jet_EM_eta, &b_m_jet_EM_eta);
   fChain->SetBranchAddress("m_jet_EM_phi", &m_jet_EM_phi, &b_m_jet_EM_phi);
   fChain->SetBranchAddress("m_jet_EM_LArQuality", &m_jet_EM_LArQuality, &b_m_jet_EM_LArQuality);
   fChain->SetBranchAddress("m_jet_EM_sumPtTrk", &m_jet_EM_sumPtTrk, &b_m_jet_EM_sumPtTrk);
   fChain->SetBranchAddress("m_jet_EM_jvtxf", &m_jet_EM_jvtxf, &b_m_jet_EM_jvtxf);
   fChain->SetBranchAddress("m_jet_EM_flavor_weight_MV1", &m_jet_EM_flavor_weight_MV1, &b_m_jet_EM_flavor_weight_MV1);
   fChain->SetBranchAddress("m_jet_EM_flavor_truth_label", &m_jet_EM_flavor_truth_label, &b_m_jet_EM_flavor_truth_label);
   fChain->SetBranchAddress("m_vxp_n", &m_vxp_n, &b_m_vxp_n);
   fChain->SetBranchAddress("m_vxp_nTracks", &m_vxp_nTracks, &b_m_vxp_nTracks);
   fChain->SetBranchAddress("m_mcevt_pdf_id1", &m_mcevt_pdf_id1, &b_m_mcevt_pdf_id1);
   fChain->SetBranchAddress("m_mcevt_pdf_id2", &m_mcevt_pdf_id2, &b_m_mcevt_pdf_id2);
   fChain->SetBranchAddress("m_mcevt_pdf_x1", &m_mcevt_pdf_x1, &b_m_mcevt_pdf_x1);
   fChain->SetBranchAddress("m_mcevt_pdf_x2", &m_mcevt_pdf_x2, &b_m_mcevt_pdf_x2);
   fChain->SetBranchAddress("m_mcevt_pdf_scale", &m_mcevt_pdf_scale, &b_m_mcevt_pdf_scale);
   Notify();
}

Bool_t foo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void foo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t foo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef foo_cxx
