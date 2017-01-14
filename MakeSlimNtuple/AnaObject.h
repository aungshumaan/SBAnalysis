//-*- C++ -*-

#ifndef ANAOBJECT_H
#define ANAOBJECT_H

#include "TLorentzVector.h"




class Lepton : public TLorentzVector //Class Lepton inherits from TLorentzVector
{
  
public :
  Lepton(){}; 
  virtual ~Lepton(){}; 

public : 
  int   pdgID  ;
  int   tight ;
  int   medium ; 

  bool isGood;
  bool trigMatch;

} ; 



class Muon : public Lepton { }; //Class Muon and Electron inherits from Lepton
class Electron : public Lepton { }; 


class Jet : public TLorentzVector 
{
  
public :
  Jet(){}; 
  virtual ~Jet(){}; 

public : 
  float SV0     ; 
  float IP3DSV1 ;
  float CombNN  ;
  
  bool IsBjet ;
  
  int truthFlavor ;


  //float btagWeight;
  
  float MV1_EventWeight; 
  float MV1_VetoEventWeight;
  float MV1_EventWeight_60; //&&&& 8/31/15
  float MV1_VetoEventWeight_60; //&&&& 8/31/15
  float Jet_MV1; ///added 8/20/14
  float Jet_Emfrac; ///added 10/5/14
  float Jet_JVF;
  
} ; 

//class MET : public TLorentzVector {} ; 


class METObj 
{
public :
  
  float etx    ;
  float ety    ;
  float et     ;
  float sumet  ;
  float phi    ;
  
} ;


class SFObj 
{

public :
  
  float SF     ; 
  float SFUp   ;
  float SFDOWN ; 

} ;

class BtagSFObj 
{

public :
  BtagSFObj(){
    BJetSF           = 1. ; 
    BJetSFUp         = 1. ; 
    BJetSFDown       = 1. ; 

    CTJetSF          = 1. ; 
    CTJetSFUp        = 1. ; 
    CTJetSFDown      = 1. ; 

    MisTagSF       = 1. ; 
    MisTagSFUp     = 1. ; 
    MisTagSFDown   = 1. ; 
  
  }; 

public : 
  
  float BJetSF ; 
  float BJetSFUp ; 
  float BJetSFDown ; 

  float CTJetSF ; 
  float CTJetSFUp ; 
  float CTJetSFDown ; 

  float MisTagSF ; 
  float MisTagSFUp ; 
  float MisTagSFDown ; 
  
  
} ;




#endif // end ANAOBJECT_H
