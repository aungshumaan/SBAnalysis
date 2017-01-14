//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul  9 15:00:57 2013 by ROOT version 5.32/04
// from TTree HWWlvqq_mini/HWWlvqq_mini
// found on file: /data/haifeng/lvqq/HWW_2.19_lvqq_0.08_0_Nominal/user.haifeng.167779.Sherpa_CT10_WenuMassiveCBPt280_500_BFilter_HWW_2.19_lvqq_0.08_0_Nominal.lhf02.130705182415.merge/user.haifeng.010060._00001.merge.lvqqMiniNtuple.root
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

  //WjetsIndex1,WjetsIndex2,MET_z, etc. are user variables that are needed for minihbb.cxx although not present in the mini ntuples.  These variables should NOT be included in the fChain->SetBranchAddress lines (otherwhise, you will get harmless warning messages).
  Int_t WjetsIndex1;
  Int_t WjetsIndex2;
  Int_t vbfjetsIndex1;
  Int_t vbfjetsIndex2;
  Double_t dEtaMax ;
  Double_t ptjjMax ; 
  Double_t        topRWEventWeight;
  Double_t        wjetsRWEventWeight;
  Double_t        EventWeight;
  Float_t         MET_z;

  //now we list the actual members of the mini ntuples.

  UInt_t          RunNumber;
  UInt_t          EventNumber;
  UInt_t          mc_channel_number;
  Double_t        mcEventWeight; //for old slim ntuples;  also for new aQGC new sample  
  Double_t        pileupEventWeight; //for old slim ntuples 
  //Float_t         mcEventWeight; //new slim ntuples, 7/23/14 , not for new aQGC samples???
  //Float_t         pileupEventWeight;//new slim ntuples, 7/23/14
  Float_t         ttbarWeight; //new slim ntuples from Haifeng , 8/14/14
  Double_t        runweight; ///added 4/24/15
  Double_t        btagWeight; ///added 4/24/15

  bool          IsBadMediumBCH;
  bool          IsBadMediumBCHUp;
  bool          IsBadMediumBCHDown;
  bool          IsBadTightBCH;

  Float_t         MET;
  Float_t         MET_x;
  Float_t         MET_y;
  Float_t         MET_phi;
  Float_t         truth_sherpa_Wpt;
  Float_t         truth_sherpa_Zpt;
  Int_t           jet_n;
  vector<float>   *jet_E;
  vector<float>   *jet_pt;
  vector<float>   *jet_eta;
  vector<float>   *jet_phi;
  vector<float>   *jet_isbtag;
  vector<float>   *jet_MV1;
  vector<float>   *jet_BtagWeight;//new slim ntuples, 8/14/14
  vector<float>   *jet_VetoBtagWeight;//new slim ntuples, 8/14/14
  vector<float>   *jet_BtagWeight_60;//&&&& 8/31/15
  vector<float>   *jet_VetoBtagWeight_60;//8/31/15
  vector<float>   *jet_emfrac;
  vector<float>   *jet_jvtxf;


  Int_t           fatjet_n;
  vector<float>   *fatjet_E;
  vector<float>   *fatjet_pt;
  vector<float>   *fatjet_eta;
  vector<float>   *fatjet_phi;
  vector<float>   *fatjet_m;


  Int_t           lep_n;
  vector<float>   *lep_E;
  vector<float>   *lep_pt;
  vector<float>   *lep_eta;
  vector<float>   *lep_phi;
  vector<int>     *lep_ID;
  vector<int>     *lep_isGood;

  float   el_etcone30_0;
  float   el_ptcone30_0;
  float   el_z0sinth_0;
  float   el_d0_0;
  float   el_sigd0_0;

  float   mu_etcone30_0;
  float   mu_ptcone30_0;
  float   mu_z0sinth_0;
  float   mu_d0_0;
  float   mu_sigd0_0;

  vector<int>     *mctruth_pdgId;
  vector<int>     *mctruth_parent;
  vector<float>   *mctruth_pt;
  vector<float>   *mctruth_eta;
  vector<float>   *mctruth_phi;
  vector<float>   *mctruth_m;
  Int_t           mctruth_Nbquarks;
  Int_t           mctruth_VVmode;
  Int_t           mctruth_lepdecay;
  Int_t           mctruth_haddecay;
  
  
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
  

  // List of branches
  TBranch        *b_RunNumber;   //!
  TBranch        *b_EventNumber;   //!
  TBranch        *b_mc_channel_number;   //!
  TBranch        *b_mcEventWeight;   //!
  TBranch        *b_pileupEventWeight;   //!
  TBranch        *b_ttbarWeight;  //!
  TBranch        *b_runweight;  //!
  TBranch        *b_btagWeight;  //!
  TBranch        *b_jet_BtagWeight;  //!
  TBranch        *b_jet_VetoBtagWeight;  //!
  TBranch        *b_jet_BtagWeight_60;  //!
  TBranch        *b_jet_VetoBtagWeight_60;  //!
  TBranch        *b_IsBadMediumBCH;  //!
  TBranch        *b_IsBadMediumBCHUp;  //!
  TBranch        *b_IsBadMediumBCHDown;  //!
  TBranch        *b_IsBadTightBCH;  //!
  TBranch        *b_MET;   //!
  TBranch        *b_MET_x;   //!
  TBranch        *b_MET_y;   //!
  TBranch        *b_MET_phi;   //!
  TBranch        *b_truth_sherpa_Wpt;   //!
  TBranch        *b_truth_sherpa_Zpt;   //!
  TBranch        *b_jet_n;   //!
  TBranch        *b_jet_E;   //!
  TBranch        *b_jet_pt;   //!
  TBranch        *b_jet_eta;   //!
  TBranch        *b_jet_phi;   //!
  TBranch        *b_jet_isbtag;   //!
  TBranch        *b_jet_MV1;   //!
  TBranch        *b_jet_emfrac;   //!
  TBranch        *b_jet_jvtxf;   //!

  TBranch        *b_fatjet_n;   //!
  TBranch        *b_fatjet_E;   //!
  TBranch        *b_fatjet_pt;   //!
  TBranch        *b_fatjet_eta;   //!
  TBranch        *b_fatjet_phi;   //!
  TBranch        *b_fatjet_m;   //!

  TBranch        *b_lep_n;   //!
  TBranch        *b_lep_E;   //!
  TBranch        *b_lep_pt;   //!
  TBranch        *b_lep_eta;   //!
  TBranch        *b_lep_phi;   //!
  TBranch        *b_lep_ID;   //!
  TBranch        *b_lep_isGood;   //!

  TBranch        *b_el_etcone30_0;   //!
  TBranch        *b_el_ptcone30_0;   //!
  TBranch        *b_el_z0sinth_0;   //!
  TBranch        *b_el_d0_0;   //!
  TBranch        *b_el_sigd0_0;   //!

  TBranch        *b_mu_etcone30_0;   //!
  TBranch        *b_mu_ptcone30_0;   //!
  TBranch        *b_mu_z0sinth_0;   //!
  TBranch        *b_mu_d0_0;   //!
  TBranch        *b_mu_sigd0_0;   //!

  TBranch        *b_mctruth_Nbquarks;  //!
  TBranch        *b_mctruth_pdgId;   //!
  TBranch        *b_mctruth_parent;   //!
  TBranch        *b_mctruth_pt;   //!
  TBranch        *b_mctruth_eta;   //!
  TBranch        *b_mctruth_phi;   //!
  TBranch        *b_mctruth_m;   //!
  TBranch        *b_mctruth_VVmode;   //!  
  TBranch        *b_mctruth_lepdecay;   //!  
  TBranch        *b_mctruth_haddecay;   //!  




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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data/haifeng/lvqq/HWW_2.19_lvqq_0.08_0_Nominal/user.haifeng.167779.Sherpa_CT10_WenuMassiveCBPt280_500_BFilter_HWW_2.19_lvqq_0.08_0_Nominal.lhf02.130705182415.merge/user.haifeng.010060._00001.merge.lvqqMiniNtuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data/haifeng/lvqq/HWW_2.19_lvqq_0.08_0_Nominal/user.haifeng.167779.Sherpa_CT10_WenuMassiveCBPt280_500_BFilter_HWW_2.19_lvqq_0.08_0_Nominal.lhf02.130705182415.merge/user.haifeng.010060._00001.merge.lvqqMiniNtuple.root");
      }
      f->GetObject("HWWlvqq_mini",tree);

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
   jet_E = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_isbtag = 0;
   jet_MV1 = 0;
   jet_BtagWeight = 0;
   jet_VetoBtagWeight = 0;
   jet_BtagWeight_60 = 0;
   jet_VetoBtagWeight_60 = 0;
   jet_emfrac = 0;
   jet_jvtxf = 0;
   
   fatjet_E = 0;
   fatjet_pt = 0;
   fatjet_eta = 0;
   fatjet_phi = 0;
   fatjet_m   = 0;

   lep_E = 0;
   lep_pt = 0;
   lep_eta = 0;
   lep_phi = 0;
   lep_ID = 0;
   lep_isGood = 0;


   mctruth_pdgId=0;
   mctruth_parent=0;
   mctruth_pt=0;
   mctruth_eta=0;
   mctruth_phi=0;
   mctruth_m=0;

   truthStable_el_pt = 0;
   truthStable_el_eta = 0;
   truthStable_el_phi = 0;
   truthStable_mu_pt = 0;
   truthStable_mu_eta = 0;
   truthStable_mu_phi = 0;
   truthStable_ph_pt = 0;
   truthStable_ph_eta = 0;
   truthStable_ph_phi = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);


   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber); //"RunNumber" is a already present branch in slim ntuples, we are setting Int_t RunNumber's address to it.
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
   fChain->SetBranchAddress("pileupEventWeight", &pileupEventWeight, &b_pileupEventWeight);
   fChain->SetBranchAddress("ttbarWeight",&ttbarWeight, &b_ttbarWeight);
   fChain->SetBranchAddress("runweight",&runweight, &b_runweight);
   fChain->SetBranchAddress("btagWeight",&btagWeight, &b_btagWeight);
   fChain->SetBranchAddress("jet_BtagWeight",&jet_BtagWeight, &b_jet_BtagWeight);
   fChain->SetBranchAddress("jet_VetoBtagWeight",&jet_VetoBtagWeight, &b_jet_VetoBtagWeight);
   fChain->SetBranchAddress("jet_BtagWeight_60",&jet_BtagWeight_60, &b_jet_BtagWeight_60); //&&&&
   fChain->SetBranchAddress("jet_VetoBtagWeight_60",&jet_VetoBtagWeight_60, &b_jet_VetoBtagWeight_60);
   fChain->SetBranchAddress("IsBadMediumBCH", &IsBadMediumBCH, &b_IsBadMediumBCH);
   fChain->SetBranchAddress("IsBadMediumBCHUp", &IsBadMediumBCHUp, &b_IsBadMediumBCHUp);
   fChain->SetBranchAddress("IsBadMediumBCHDown", &IsBadMediumBCHDown, &b_IsBadMediumBCHDown);
   fChain->SetBranchAddress("IsBadTightBCH", &IsBadTightBCH, &b_IsBadTightBCH);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("MET_x", &MET_x, &b_MET_x);
   fChain->SetBranchAddress("MET_y", &MET_y, &b_MET_y);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("truth_sherpa_Wpt", &truth_sherpa_Wpt, &b_truth_sherpa_Wpt);
   fChain->SetBranchAddress("truth_sherpa_Zpt", &truth_sherpa_Zpt, &b_truth_sherpa_Zpt);
   fChain->SetBranchAddress("jet_n", &jet_n, &b_jet_n);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_isbtag", &jet_isbtag, &b_jet_isbtag);
   fChain->SetBranchAddress("jet_MV1", &jet_MV1, &b_jet_MV1);
   fChain->SetBranchAddress("jet_emfrac", &jet_emfrac, &b_jet_emfrac);
   fChain->SetBranchAddress("jet_jvtxf", &jet_jvtxf, &b_jet_jvtxf);
   
   fChain->SetBranchAddress("fatjet_n", &fatjet_n, &b_fatjet_n);
   fChain->SetBranchAddress("fatjet_E", &fatjet_E, &b_fatjet_E);
   fChain->SetBranchAddress("fatjet_pt", &fatjet_pt, &b_fatjet_pt);
   fChain->SetBranchAddress("fatjet_eta", &fatjet_eta, &b_fatjet_eta);
   fChain->SetBranchAddress("fatjet_phi", &fatjet_phi, &b_fatjet_phi);
   fChain->SetBranchAddress("fatjet_m", &fatjet_m, &b_fatjet_m);


   fChain->SetBranchAddress("lep_n", &lep_n, &b_lep_n);
   fChain->SetBranchAddress("lep_E", &lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_pt", &lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_ID", &lep_ID, &b_lep_ID);
   fChain->SetBranchAddress("lep_isGood", &lep_isGood, &b_lep_isGood);

   fChain->SetBranchAddress("el_etcone30_0", &el_etcone30_0, &b_el_etcone30_0);
   fChain->SetBranchAddress("el_ptcone30_0", &el_ptcone30_0, &b_el_ptcone30_0);
   fChain->SetBranchAddress("el_z0sinth_0", &el_z0sinth_0, &b_el_z0sinth_0);
   fChain->SetBranchAddress("el_d0_0", &el_d0_0, &b_el_d0_0);
   fChain->SetBranchAddress("el_sigd0_0", &el_sigd0_0, &b_el_sigd0_0);

   fChain->SetBranchAddress("mu_etcone30_0", &mu_etcone30_0, &b_mu_etcone30_0);
   fChain->SetBranchAddress("mu_ptcone30_0", &mu_ptcone30_0, &b_mu_ptcone30_0);
   fChain->SetBranchAddress("mu_z0sinth_0", &mu_z0sinth_0, &b_mu_z0sinth_0);
   fChain->SetBranchAddress("mu_d0_0", &mu_d0_0, &b_mu_d0_0);
   fChain->SetBranchAddress("mu_sigd0_0", &mu_sigd0_0, &b_mu_sigd0_0);

   fChain->SetBranchAddress("mctruth_pdgId", &mctruth_pdgId, &b_mctruth_pdgId);
   fChain->SetBranchAddress("mctruth_parent", &mctruth_parent, &b_mctruth_parent);
   fChain->SetBranchAddress("mctruth_pt", &mctruth_pt, &b_mctruth_pt);
   fChain->SetBranchAddress("mctruth_eta", &mctruth_eta, &b_mctruth_eta);
   fChain->SetBranchAddress("mctruth_phi", &mctruth_phi, &b_mctruth_phi);
   fChain->SetBranchAddress("mctruth_m", &mctruth_m, &b_mctruth_m);
   fChain->SetBranchAddress("mctruth_Nbquarks", &mctruth_Nbquarks, &b_mctruth_Nbquarks);
   fChain->SetBranchAddress("mctruth_VVmode", &mctruth_VVmode, &b_mctruth_VVmode);
   fChain->SetBranchAddress("mctruth_lepdecay", &mctruth_lepdecay, &b_mctruth_lepdecay);
   fChain->SetBranchAddress("mctruth_haddecay", &mctruth_haddecay, &b_mctruth_haddecay);
   
   


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
