#include <TLegend.h>
#include <TStyle.h>
#include <TKey.h>
#include <TLine.h>
#include <TH2.h>
#include <TFile.h>
#include <TCanvas.h>

#include <iostream>
//#include <MyCommonTools.cc>


const int nLepList=9;
TString myLepList[nLepList] = {"ep","em","mp","mm","pos","neg","elec","muon","all"};
TString dataName = "Data";

const int nSamples=9;
//W+jets should be FIRST in this list
TString sampleName[nSamples] = {"Wjets","WjetsEWKSherpa","Zjets","Ttbar","SingleTop","WZZZWg","VBS_WV_0_0","VBS_ZV_0_0","QCD"};

//assumed systematic uncertainty on the bkg yields.
double systFrac[nSamples] = {-10000, 0.5, 0.2, 0.2, 0.2, 0.3, 1.0, 1.0, 1.0};


void GetYieldAndError(double& value, double& error, double& syst, TFile* file, TString component, 
		      TString lepton, TString selection, TString var){
  

  assert(sampleName[8]=="QCD");  //function won't work if QCD name is changed.

  value = 0;
  error = 0;
  syst = 0;
  
  int myIndex=-2;
  if(component==dataName){
    myIndex=-1;
  }

  for(int ii=0; ii<nSamples; ii++){
    if(sampleName[ii] == component){
      myIndex=ii;
      break;
    }
  }
  if(myIndex==-2){
    cout<<"don't recognize component "<<component<<endl;
    assert(0);
  }

  
  TString myLeps[4] = {"","","",""};
  int nLeps=1;
  if(lepton=="pos"){
    myLeps[0] = "ep";
    myLeps[1] = "mp";
    nLeps=2;
  }
  else if(lepton=="neg"){
    myLeps[0] = "em";
    myLeps[1] = "mm";
    nLeps=2;
  }
  else if(lepton=="elec"){
    myLeps[0] = "ep";
    myLeps[1] = "em";
    nLeps=2;
  }
  else if(lepton=="muon"){
    myLeps[0] = "mp";
    myLeps[1] = "mm";
    nLeps=2;
  }
  else if(lepton=="all"){
    myLeps[0] = "ep";
    myLeps[1] = "em";
    myLeps[2] = "mp";
    myLeps[3] = "mm";
    nLeps=4;
  }
  else{
    myLeps[0] = lepton;
    nLeps=1;
  }
  
  for(int mm=0; mm<nLeps; mm++){
    

    TH1* h1 = (TH1*)file->Get(TString("H_" + component + "_" + myLeps[mm] + "_WBF_" + selection + "_" + var));
    if(!h1){
      //cout<<"WARNING!!  Unable to find "<<component<<" , "<<selection<<" , "<<var<<" in file! Calculating without this component!"<<endl;
    }
    else{
      //cout<<component<<" "<<" "<<myLeps[mm]<<":" <<h1->Integral()<<endl;
      value +=  h1->Integral();
      //cout<<component<<" "<<": " <<value<<endl;
      
      if(component!="QCD"){ //don't include stat uncertainty on QCD.  (Instead, just have a flat 100% systematic uncertainty)
	
	for(int ii=0; ii<=h1->GetNbinsX(); ii++){
	  error += (h1->GetBinError(ii) * h1->GetBinError(ii)) ;
	}
	
      }
      
      //cout<<"before mm = "<<mm<<" ;  syst = "<<syst<<endl;
      
      if(myIndex>=0 && component=="QCD"){  //QCD uncertainty is assumed to be uncorrelated between channels.
	//	cout<<"adding syst with val = "<<value<<" because lepton = "<<myLeps[mm]<<endl;
	syst += systFrac[myIndex]*systFrac[myIndex]*value * value;
      }
      //  cout<<"end mm = "<<mm<<" ;  syst = "<<syst<<endl;
      
    }
    
  }//end loop over mm
  
  cout<<component<<" Total : " <<value<<endl;
  
  if(myIndex>=0 && component!="QCD"){  //non-QCD uncertainties are assumed to be correlated between channels.
    syst += systFrac[myIndex]*systFrac[myIndex]*value * value;

  }

  //cout<<"before sqrt, syst = "<<syst<<endl;

  error = sqrt(error);    
  syst = sqrt(syst);

  //cout<<component<<" ; "<<error<<" , "<<syst<<endl;

}







void SimpleWjetSF(TFile* file, int nSamp, TString* sampName, TString lepton, TString region, TString var, TString plotName, TCanvas* canv){
  
  const int NSAMP = nSamp;
  double val[NSAMP];
  double err[NSAMP];
  double systerr[NSAMP];

  //cout<<"****************************************************************"<<endl;


  for(int ii=0; ii<NSAMP; ii++){
    
    TString thisSample = sampName[ii];
    //cout<<"looking for "<<thisSample<<endl;
    
    GetYieldAndError(val[ii], err[ii], systerr[ii], file, sampName[ii], lepton, region, var);
    //cout<<thisSample<<" yield = "<<val[ii]<<" +/- "<<err[ii]<<endl;
    

  }

  double dataVal = 0;
  double dataErr = 0;
  double dummy = 0;
  GetYieldAndError(dataVal, dataErr, dummy, file, dataName, lepton, region, var);
  //cout<<"data yield = "<<dataVal<<" +/- "<<dataErr<<endl;

  double bkgSubYield = dataVal;
  double bkgSubErr = dataErr*dataErr;
  
  for(int ii=1; ii<NSAMP; ii++){
    //subtract everything except W+jets
    bkgSubYield -= val[ii];
    bkgSubErr += err[ii]*err[ii];
    bkgSubErr += systerr[ii]*systerr[ii];

  }


  //Now add in systematic uncertainties on bkg-sum.
  //for(int ii=1; ii<NSAMP; ii++){
    //subtract everything except W+jets
  // bkgSubErr += systFrac[ii]*systFrac[ii]*val[ii]*val[ii];
  // }

  bkgSubErr = sqrt(bkgSubErr);


  //cout<<"Scale-Factor calculation for "<<lepton<<"_"<<region<<endl;
  //cout<<"bkg-subtracted yield = "<<bkgSubYield<<" +/- "<<bkgSubErr<<endl;
  
  double WSF = bkgSubYield/val[0];
  double WSFerr =  (bkgSubErr*bkgSubErr)/(bkgSubYield*bkgSubYield) + (err[0]*err[0])/(val[0]*val[0]);
  WSFerr = sqrt(WSFerr);
  WSFerr = fabs(WSF) * WSFerr;

  //cout.precision(2);
  //cout<<"W+jets SF = "<<WSF<<" +/- "<<WSFerr<<endl;
  cout<<lepton<<"_"<<region<<"  "<<WSF<<"  "<<WSFerr<<endl;
  
  //cout<<"****************************************************************"<<endl<<endl;


}
   


void ExtractSimpleWjetsSF(){


  bool doSubPad=true;

  bool plotSignal=true;

  bool normalizeEqual=true;
  
  // gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  
  //TString filename1 = "~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_separateWjetsEWK4.root";
  //TString filename1 = "~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7_looseBadLep4.root";
  //TString filename1 = "~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4_smw_NEWcutflow.root";
  TString filename1 = "~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_smw_noSeparateWjetsEWK.root";
  //&&&&TString filename2 = "~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/hwwlvqq.Nominal.caf4.2.lv4_smw_SeparateWjetsEWK.root";
  
  TFile* f1 = new TFile(filename1);
  //TFile* f2 = new TFile(filename2);
  
  
  
  //TString select = "SR";
  //TString select = "SRfatOnly";
  TString select = "CR_Wjj";
  //TString select = "CR_WjjfatOnly";  
  
  // TString select = "CR_TopfatOnly";
  //  TString select = "CR_Top";
  
  

  
  TString myVar = "mTWV";
  // TString myVar = "mjjTagged";
  
  
  TString plotName = "finalSystematics.pdf";
  
  TCanvas* c3 = new TCanvas("myc3","myc3",700,675);  //700 x 500 is default.
  
  //c3->Print(plotName+"[");
  
  for(int mm=0; mm<nLepList; mm++){
    
    TString lepMode = myLepList[mm];
    //cout<<"looking into "<<lepMode<<endl;
    SimpleWjetSF(f1, nSamples, sampleName, lepMode, select, myVar, plotName, c3);
    
    
    
  }
  

  //c3->Print(plotName+"]");


}


