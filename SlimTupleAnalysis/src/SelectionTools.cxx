#include <iostream>
#include "SelectionTools.h"
using namespace constants;

namespace SelectionTools{

  
  bool getTruePartonVectors(const foo* h1, TLorentzVector& true_Vjj, vector<TLorentzVector>& true_Vjets, vector<TLorentzVector>& true_otherjets, int& trueVpdgId){

    trueVpdgId=0;
    true_Vjets.clear();
    true_otherjets.clear();

    int mc_n= h1->mctruth_pdgId->size();
    
    for(int i=0;i<mc_n;i++){
      
      if ( abs(h1->mctruth_pdgId->at(i)) == 23 || abs(h1->mctruth_pdgId->at(i)) == 24 ){ //Z or W (these are the hadronic decays)                             
	true_Vjj.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*GeV,
				h1->mctruth_eta ->at(i)  ,
				h1->mctruth_phi ->at(i)  ,
				h1->mctruth_m ->at(i)*GeV  );
	
	trueVpdgId=h1->mctruth_pdgId->at(i);
      }

      int parId = h1->mctruth_parent->at(i);

      if ( parId>=0 && ( abs(h1->mctruth_pdgId->at(parId)) ==23 || abs(h1->mctruth_pdgId->at(parId))== 24 ) ){ //quarks from Z or W                           
	TLorentzVector thisPart;
	thisPart.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*GeV,
				h1->mctruth_eta ->at(i)  ,
				h1->mctruth_phi ->at(i)  ,
				h1->mctruth_m ->at(i)*GeV  );
	
	true_Vjets.push_back(thisPart);
      }
      
      if( (abs(h1->mctruth_pdgId->at(i)) >0 && abs(h1->mctruth_pdgId->at(i))<7 )  && parId<0 ){ //quarks not coming from Z or W                               	
	TLorentzVector thisPart;
	thisPart.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*GeV,
				h1->mctruth_eta ->at(i)  ,
				h1->mctruth_phi ->at(i)  ,
				h1->mctruth_m ->at(i)*GeV  );
	
	true_otherjets.push_back(thisPart);
	
      }
      
      
    }//end loop over truth particles                                                                                                                          
    
    bool isTrueSigEvent=false;
    if(true_Vjets.size()>0){
      isTrueSigEvent=true;
    }
    
    return isTrueSigEvent;
    
  }
  
  
  bool isDoubleCountedVWZ(const foo* h1){
    
    TLorentzVector true_Vjj;
    vector<TLorentzVector> true_Vjets; 
    vector<TLorentzVector> true_otherjets;
    int trueVpdgId;
    
    bool isTrueSignal =  getTruePartonVectors(h1, true_Vjj, true_Vjets, true_otherjets, trueVpdgId);
    
    bool isDoubleCounted=false;

    if(isTrueSignal){
      
      if(true_otherjets.size()!=2){ cout<<"SCREEEEEEEEAM!!"<<endl;}
      TLorentzVector qqPair = true_otherjets[0] + true_otherjets[1];
      
      if(abs(trueVpdgId)==23){ //is a Z ->jj
	double deltaVVW = qqPair.M() - MassW;
	if( fabs(deltaVVW)< 4 ){
	  isDoubleCounted=true;  // is a V(leptonic)Z(jj)X event, with X consistent with W mass.
	}
      }
   
    }
    
    return isDoubleCounted;

  }
  
  
  
} //end of namespace

