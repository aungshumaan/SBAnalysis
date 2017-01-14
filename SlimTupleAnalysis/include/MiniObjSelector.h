// This is  -*- C++ -*-
#ifndef MINIOBJSELECTOR_H
#define MINIOBJSELECTOR_H

// C++
#include <vector>
#include <string.h>

// ROOT
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <TLorentzVector.h> 

// Local
#include "foo.hh"
#include "CutFlowTool.h"

using namespace std ;


class MiniObjSelector {

 public : 
  
  MiniObjSelector( foo* thisfoo = 0, CutFlowTool* thisct=0, const TString& option = "");
  virtual ~MiniObjSelector();

  float SelectBtagEfficiencyScale(); 
  //float ReDoEventPileupReweight();
  bool FirstIsBJet() ; 
  bool SecondIsBJet() ;

  int getVVcharges();
  bool passHiggsMLL( const int &mass ) ;
  bool passHiggsDPhiLL( const int &mass ) ;
  bool passHiggsHwwMT( const int &mass ) ; 
  float getZttMassFromBillQ() ;
  float TotalPt() ;

  void findVBFTaggingJets(vector<TLorentzVector> *m_jets,  std::pair<int, int> *vbfjetsIndex, const std::pair<int, int> *WjetsIndex, float jetpTCut, float min_mjj, float min_dyjj, float leadingJetPt, vector<TLorentzVector> *m_fatjets, float ptfatjet_Cut, float fatjet_minm, float fatjet_maxm, bool doFJ);

  double vbfFOM(TLorentzVector jet1, TLorentzVector jet2);
  void SetNeutrinoPz();

  //  void findWJets( vector<TLorentzVector> *m_jets, vector<TLorentzVector> *m_fatjets,
  //		  const std::pair<int, int> *vbfjetsIndex, std::pair<int, int> *WjetsIndex, 
  //		  float jetpTCut, float leadingJetPt) ;

  bool findWJetsNew( vector<TLorentzVector> *m_jets, vector<TLorentzVector> *m_fatjets,
		     const std::pair<int, int> *vbfjetsIndex, std::pair<int, int> *WjetsIndex, 
		     float jetpTCut, //float leadingJetPt,
		     float ptfatjet_Cut, float fatjet_minm, float fatjet_maxm,
		     bool &useFJ) ;
 private :

  bool m_useCombNN    ;
  bool m_useIP3DSV1   ; 
  bool m_useSV0       ;
  
  TString m_option ;
  CutFlowTool* m_ct ;
  foo* h1 ;

 
};







#endif // END MINIOBJSELECTOR_H
