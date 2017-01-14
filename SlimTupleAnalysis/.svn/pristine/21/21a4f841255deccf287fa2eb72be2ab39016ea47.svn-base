// This is  -*- C++ -*-
#ifndef ASCIIRUN_H
#define ASCIIRUN_H


#include <TROOT.h>
#include <TString.h>
#include <vector>
#include <string.h>
#include <assert.h>
#include <map>
#include <iostream>
#include <fstream>

#include "SelectionTools.h"

using namespace std ;

class AsciiRun {

public :

  ofstream textFile;
  TString fileName;
  
  AsciiRun(TString Name, bool onlyMLL ) { 

    if(Name.Contains("/")){
      cout<<"Error!! filename "<<Name<<" may not include '/'"<<endl;
      cout<<"The directory name should instead be set in AsciiRun.h"<<endl;
      assert(0);
    }

    TString outputDir="TXT/";
    if( !dirExists(outputDir) ){
      cout<<"Error!!  trying to output Ascii files to "<<outputDir<<" but directory doesn't exist.  Need to create it!"<<endl;
      assert(0);
    }

    fileName = outputDir+Name + ".txt";
    textFile.open (fileName);
    
    if(constants::writeAsciiMode==0){
      textFile<<"RunNumber/F:EventNumber/F:eventWeight/F:lep_pt/F:lep_phi/F:lep_eta/F:METx/F:METy/F:MET_et/F:ptwlep/F:Njet/F:jet1_pt/F:jet2_pt/F:vbfjet1_pt/F:vbfjet1_phi/F:vbfjet1_eta/F:vbfjet2_pt/F:vbfjet2_phi/F:vbfjet2_eta/F:Mlvjj/F:Mwjj/F:ptlvjj/F:ptwjj/F:avgEtaTagged/F:mlvj0/F:sumPt/F:etaX/F:etaY/F:mT/F:cosdPhi_wjjwlep/F:scaldiff_ptwj1_ptwj2/F:dR_vbfwwaxes/F:dEta_vbfwwaxes/F:dPhi_vbfwwaxes/F:dEtaTaggedJets/F:dPhiTaggedJets/F:dRTaggedJets/F:mjjTagged/F:ptjjTagged/F:diff_ptww_ptjjtag/F:cosThetaWlep/F:lepCentrality/F:bosonCentrality/F:VVvecptdiff/F:mTWV/F:VVptBalance/F:dRWjets/F:dPhiWjets/F:dEtaWjets/F:Wjet1_pt/F:Wjet1_eta/F:Wjet1_phi/F:Wjet2_pt/F:Wjet2_eta/F:Wjet2_phi/F:cosThetaWDecay/F:ptBalance/F\n";  //Aungshuman  
    }
    else if(constants::writeAsciiMode==1){
      textFile<<"weight/F:leppt/F:MET/F:ptwlep:tagj1pt/F:tagj1eta/F:tagj2pt/F:tagj2eta/F:mlvjj/F:mwjj/F:ptlvjj/F:ptwjj/F:avgEtaTag/F:mjjTagged/F:lepCentrality/F:bosonCentrality/F:VVptSum/F:VVvecptdiff/F:mTWV/F:VVptBalance/F:ptBalance/F:min_dR_lepjet/F:dEtaTaggedJets/F:cosThetaWlep/F:dRWjets/F:wj1pt/F:wj2pt/F:cosThetaWDec/F\n";  // BL
    }
    
    cout<<"Created file "<<fileName<<endl;
  
  }
  
  ~AsciiRun(){
    //cout<<"Closing ascii file"<<endl;
    textFile.close();
  }

  bool dirExists(TString dirName){
    
    if(dirName==""){
      return true;
    }
    else{

      struct stat checkTool;

      if (stat(dirName, &checkTool) == 0 && S_ISDIR(checkTool.st_mode)){
	return true;
      }
      else{
	return false; 
      }
    }
    
  }



} ;


#endif // ASCIIRUN_H

