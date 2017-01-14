//-*- C++ -*-

#ifndef TCUTCLASS_H
#define TCUTCLASS_H

#include <TLorentzVector.h>
#include <vector>
#include <iostream>

using namespace std;

class TCutClass 
{

 public :
  TCutClass(){};
  ~TCutClass(){};

 public :
  template <class T>
  bool orderObjectsByPt(vector<T>* v_object, Bool_t DEBUG );
   
  template <class T1, class T2>
  bool  RemoveOverlap( vector<T1>* v_first, vector<T2>* v_second, float deltaR , Bool_t DEBUG ) ; 

  template <class T>
  bool  RemoveOverlap( vector<T>* v_first,  float deltaR , Bool_t DEBUG ); 

};



/*
  Template function for pT ordering. 
  All the classes derived from TLorentzVector can be used to create an instantiation function
*/

template <class T>
bool TCutClass::orderObjectsByPt(vector<T>* v_object, Bool_t DEBUG )
{
  
  T tempSelect;
  for (unsigned int i = 0; i < (*v_object).size(); i++) {
    for (unsigned int j = 0; j < (*v_object).size(); j++) {
      if (i == j) continue;
      if ((*v_object)[j].Pt() < (*v_object)[i].Pt()){
	tempSelect = (*v_object)[i];
	(*v_object)[i] = (*v_object)[j];
	(*v_object)[j] = tempSelect;
      }
    }
  }
  
  return true ;
}


/*
  Template function to remove overlap using delta R match. 
  It will remove the second container if there are overlap. 
*/

template <class T1, class T2>
bool  TCutClass::RemoveOverlap( vector<T1>* v_first, vector<T2>* v_second, float deltaR , Bool_t DEBUG ){
 
  if ( (*v_second).size() == 0  )   return true ; 
  
  for (unsigned int i_f=0; i_f < (*v_first).size(); i_f ++){
    for (unsigned int i_s=0; i_s < (*v_second).size(); i_s++){
      float rdeltaR = (*v_first)[i_f].DeltaR( (*v_second)[i_s] ) ;
      if (DEBUG) cout << "DEBUG : delataR = "<< rdeltaR << endl;
      if(  rdeltaR  <  deltaR ) {
       (*v_second).erase((*v_second).begin()+i_s);
       i_s--;
      }
      if (DEBUG) cout << "DEBUG : Have removed "<< endl; ; 
    }
    
  }
  return true ; 
}


/*
  Template function to remove Low pT objects if there are overlap ( self-matching )
*/

template <class T>
bool  TCutClass::RemoveOverlap( vector<T>* v_first,  float deltaR , Bool_t DEBUG ){

  if ( (*v_first).size() < 2  ){ return true ;  }
  
  TCutClass::orderObjectsByPt(v_first, false );

  for (unsigned int i_f=0; i_f < (*v_first).size(); i_f ++){
    
    for (unsigned int i_s=i_f+1; i_s < (*v_first).size(); i_s++){
    
      float rdeltaR =   (*v_first)[i_f].DeltaR( (*v_first)[i_s] ) ;
      
      if (DEBUG) cout << "DEBUG : delataR = "<< rdeltaR << endl;
      if(  rdeltaR  <  deltaR ) {
	(*v_first).erase((*v_first).begin()+i_s);
	i_s--;
	if (DEBUG) cout << "DEBUG : Have removed "<< endl; 
      }

    }
  }
  

  return true ; 
}





#endif // end TCUTCLASS_H




