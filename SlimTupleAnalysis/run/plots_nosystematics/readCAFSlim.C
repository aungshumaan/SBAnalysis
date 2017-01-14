#include <cmath>
#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TLeaf.h>
#include "TCanvas.h"
#include "TLegend.h"
#include <iostream>
#include <fstream>
#include <sstream> 


vector<TString> fileNames;

void getFileNames(const char *file) { 
  std::ifstream is(file);
  TString s("");
  while(is>>s)
    {
      fileNames.push_back(s);
      //cout<<s<<endl;
    }
  
  cout << "Read "<< fileNames.size() << " files.\n\n";
}

void readCAFSlim(){

  getFileNames("input.txt"); //input.txt will contain the list of files to be read

  

  //TChain *mychain = new TChain("HWWTree_lvqq");
  TChain *mychain = new TChain("HWWlvqq_mini"); //slim ntuples &&&&
 
  cout<<"filenames in input.txt are:\n";
  for ( unsigned int i_nFname=0; i_nFname<fileNames.size(); i_nFname++){
    if(! (fileNames[i_nFname].Contains('#')) ){ //comment out slimntuples by putting a '#' in front.
      mychain  -> Add( fileNames[i_nFname] ); ///adding all the files in a chain
      cout<<fileNames[i_nFname]<<endl;
      
    }
  }
  
  TFile   *foutput = TFile::Open("output.root","recreate");
  
  
  TH1F* h_jet0_pt     = new TH1F ("h_jet0_pt","h_jet0_pt",50, 0., 300.);
  
  TH1F* h_lepID       = new TH1F ("h_lepID","h_lepID",34, -17., 17.);
  TH1F* h_lepEtCone30 = new TH1F ("h_lepEtCone30","h_lepEtCone30",100,-20., 80.);
  TH1F* h_lepPtCone30 = new TH1F ("h_lepPtCone30","h_lepPtCone30",100, 0., 50.);
  TH1F* h_lepz0sinth  = new TH1F ("h_lepz0sinth","h_lepz0sinth",100, 0.0, 2.);
  TH1F* h_lepd0sigd0  = new TH1F ("h_lepd0sigd0","h_lepd0sigd0",100, 0., 10.);
  TH1F* h_lepPt       = new TH1F ("h_lepPt","h_lepPt",50, 0., 400.);
  TH1F* h_etIsolation = new TH1F ("h_etIsolation","h_etIsolation",50, 0., 0.25);
  TH1F* h_ptIsolation = new TH1F ("h_ptIsolation","h_ptIsolation",50, 0., 0.25);

  TH1F* h_MET         = new TH1F ("h_MET","h_MET",40, 0., 200.);

  int nentries = mychain->GetEntries();
  cout<<nentries<<endl;
 
  
  UInt_t          runNumber;
  UInt_t          eventNumber;
  Double_t mcEventWeight;
  Int_t njets, tentry;
  vector<float> *jetpt;
  vector<int> *lep_ID;

  Float_t lepEtCone30;
  Float_t lepPtCone30;
  Float_t lepz0sinth;
  Float_t lepd0sigd0;  
  Float_t lepPt;
  Float_t MET;

  TBranch* b_eventNumber;
  TBranch* b_runNumber;
  TBranch* b_mcEventWeight;
  TBranch* b_njets;
  TBranch* b_jetpt;
  TBranch* b_lep_ID;

  TBranch* b_lepEtCone30;
  TBranch* b_lepPtCone30;
  TBranch* b_lepz0sinth;
  TBranch* b_lepd0sigd0;  
  TBranch* b_lepPt;
  TBranch* b_MET;
  

  eventNumber=0;
  runNumber=0;
  mcEventWeight=0.;
  njets=0;
  jetpt=0;
  lep_ID=0;

  lepEtCone30=0.;
  lepPtCone30=0.;
  lepz0sinth=0.;
  lepd0sigd0=0.;  
  lepPt=0.;
  MET=0.;
  

  mychain->SetBranchAddress("EventNumber",&eventNumber,&b_eventNumber); //setting the address of already existing branch named "EventNumber" in the input mychain to the TBranch pointer we have initialized
  mychain->SetBranchAddress("RunNumber",&runNumber,&b_runNumber);
  mychain->SetBranchAddress("mcEventWeight",&mcEventWeight,&b_mcEventWeight);

  //for CAF
  //mychain->SetBranchAddress("m_jet_n",&njets,&b_njets);
  //mychain->SetBranchAddress("m_jet_pt",&jetpt,&b_jetpt);

  mychain->SetBranchAddress("jet_n",&njets,&b_njets);
  mychain->SetBranchAddress("jet_pt",&jetpt,&b_jetpt);
  mychain->SetBranchAddress("lep_ID",&lep_ID,&b_lep_ID);

  mychain->SetBranchAddress("leptonEtCone30",&lepEtCone30,&b_lepEtCone30);
  mychain->SetBranchAddress("leptonPtCone30",&lepPtCone30,&b_lepPtCone30);
  mychain->SetBranchAddress("leptonz0sinth",&lepz0sinth,&b_lepz0sinth);
  mychain->SetBranchAddress("leptond0sigd0",&lepd0sigd0,&b_lepd0sigd0);
  mychain->SetBranchAddress("leptonPt",&lepPt,&b_lepPt);
  mychain->SetBranchAddress("MET",&MET,&b_MET);
 



  int count=0;
  for (int i=0;i<nentries;++i){
    //for (int i=0;i<100;++i){
    count++;
    if(!(i%1000))cout<<"event "<<i<<endl;
    //if (count>10)break;
    tentry = mychain->LoadTree(i); //TChain::LoadtTree(entry) =>find the tree which contains entry, and set it as the current tree. returns the entry number in that tree. 
    mychain->GetEntry(tentry);


    string lepflavor="e";   if (abs(lep_ID->at(0))==13 ) {lepflavor="m";}
    string lepcharge="m";   if (    lep_ID->at(0)<0 )    {lepcharge="p";}///electron pdgId is 11 and positron is -11. 
    
 
 
    // cout<<tentry<<" : ";
    // cout   <<" RunNumber = "<<runNumber<<" , EventNumber = "<<eventNumber<<", mcEventWeight = "<<mcEventWeight<<endl;
    // cout   <<" number of jets= "<<njets<<" , ";
    //if(jetpt->size()>1)cout<<" jetpt0 = "<<jetpt->at(0)/1000<<" "<<" and jetpt1 = "<<jetpt->at(1)/1000<<endl;

    if(jetpt->size()>1){

      //if(abs(lep_ID->at(0))==13){
      if(1){
      //if(!(i%100))cout<<MET/1000<<endl;
      //if(MET/1000 <25.){
      if(1){
	h_jet0_pt ->Fill(jetpt->at(0)/1000,mcEventWeight);
      
	h_lepID       ->Fill(lep_ID->at(0),mcEventWeight);
	h_lepEtCone30 ->Fill(lepEtCone30/1000,mcEventWeight);
	h_lepPtCone30 ->Fill(lepPtCone30/1000,mcEventWeight);
	h_lepz0sinth  ->Fill(lepz0sinth,mcEventWeight);
	h_lepd0sigd0  ->Fill(lepd0sigd0,mcEventWeight);
	h_lepPt       ->Fill(lepPt/1000,mcEventWeight);
	h_MET         ->Fill( MET/1000,mcEventWeight);

	h_etIsolation ->Fill(lepEtCone30/lepPt,mcEventWeight);
	h_ptIsolation ->Fill(lepPtCone30/lepPt,mcEventWeight);
   
	}
      }
    }
  } //loop ends

  foutput->Write();
  foutput->Close();


  
  
}
