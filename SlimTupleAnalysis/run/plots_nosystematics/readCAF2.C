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

void readCAF2(){

  TH1F::SetDefaultSumw2(kTRUE);

  getFileNames("input.txt"); //input.txt will contain the list of files to be read

  

  TChain *mychain = new TChain("HWWTree_lvqq");
  //TChain *mychain = new TChain("HWWlvqq_mini"); //slim ntuples
 
  cout<<"filenames in input.txt are:\n";
  for ( unsigned int i_nFname=0; i_nFname<fileNames.size(); i_nFname++){
    if(! (fileNames[i_nFname].Contains('#')) ){ //comment out slimntuples by putting a '#' in front.
      mychain  -> Add( fileNames[i_nFname] ); ///adding all the files in a chain
      cout<<fileNames[i_nFname]<<endl;
      
    }
  }
  
  TFile   *foutput = TFile::Open("output.root","recreate");
  
  
  TH1F* h_truthStable_el_pt     = new TH1F ("h_truthStable_el_pt","h_truthStable_el_pt",20, 0., 500.);
  TH1F* h_truthStable_el_eta     = new TH1F ("h_truthStable_el_eta","h_truthStable_el_eta", 15, -3, 3);
  TH1F* h_truthStable_el_phi     = new TH1F ("h_truthStable_el_phi","h_truthStable_el_phi",20, -4, 4);

  TH1F* h_truthStable_mu_pt     = new TH1F ("h_truthStable_mu_pt","h_truthStable_mu_pt",20, 0., 500.);
  TH1F* h_truthStable_mu_eta     = new TH1F ("h_truthStable_mu_eta","h_truthStable_mu_eta", 15, -3, 3);
  TH1F* h_truthStable_mu_phi     = new TH1F ("h_truthStable_mu_phi","h_truthStable_mu_phi",20, -4, 4);

  TH1F* h_mcEvtWeight    = new TH1F ("h_mcEvtWeight","h_mcEvtWeight",1000, 0, 1000);
  
  
   

  int nentries = mychain->GetEntries();
  cout<<"nentries = "<<nentries<<endl;
 
  
  UInt_t          runNumber;
  UInt_t          eventNumber;
  Double_t mcEventWeight;
  Int_t  tentry;

  vector<float> *truthStable_el_pt;
  vector<float> *truthStable_el_eta;
  vector<float> *truthStable_el_phi;
  
  vector<float> *truthStable_mu_pt;
  vector<float> *truthStable_mu_eta;
  vector<float> *truthStable_mu_phi;

 


  TBranch* b_eventNumber;
  TBranch* b_runNumber;
  TBranch* b_mcEventWeight;
  

  TBranch* b_truthStable_el_pt;
  TBranch* b_truthStable_el_eta;
  TBranch* b_truthStable_el_phi;

  TBranch* b_truthStable_mu_pt;
  TBranch* b_truthStable_mu_eta;
  TBranch* b_truthStable_mu_phi;

 
  

  eventNumber=0;
  runNumber=0;
  mcEventWeight=0.;
  
  
 
  truthStable_el_pt=0;
  truthStable_el_eta=0;
  truthStable_el_phi=0;

  truthStable_mu_pt=0;
  truthStable_mu_eta=0;
  truthStable_mu_phi=0;


  

  mychain->SetBranchAddress("EventNumber",&eventNumber,&b_eventNumber); //setting the address of already existing branch named "EventNumber" in the input mychain to the TBranch pointer we have initialized
  mychain->SetBranchAddress("RunNumber",&runNumber,&b_runNumber);
  mychain->SetBranchAddress("mcEventWeight",&mcEventWeight,&b_mcEventWeight);

  //for CAF
 
  mychain->SetBranchAddress("truthStable_el_pt" , &truthStable_el_pt  , &b_truthStable_el_pt);
  mychain->SetBranchAddress("truthStable_el_eta", &truthStable_el_eta , &b_truthStable_el_eta);
  mychain->SetBranchAddress("truthStable_el_phi", &truthStable_el_phi , &b_truthStable_el_phi);

  mychain->SetBranchAddress("truthStable_mu_pt" , &truthStable_mu_pt  , &b_truthStable_mu_pt);
  mychain->SetBranchAddress("truthStable_mu_eta", &truthStable_mu_eta , &b_truthStable_mu_eta);
  mychain->SetBranchAddress("truthStable_mu_phi", &truthStable_mu_phi , &b_truthStable_mu_phi);
  
  


 



  int count=0;
  int weight1000 =0;
  int weight10k =0;
  int weight100k =0;
  int weight1M =0;
  double maxWeight =0;
  for (int i=0;i<nentries;++i){
    //for (int i=0;i<100;++i){
    count++;
    if(!(i%1000))cout<<"event "<<i<<endl;
    //if (count>10)break;
    //tentry = mychain->LoadTree(i); //TChain::LoadtTree(entry) =>find the tree which contains entry, and set it as the current tree. returns the entry number in that tree. 
    //mychain->GetEntry(tentry);
    mychain->GetEntry(i);

    if (mcEventWeight >1000){
      weight1000++;
      //cout<<mcEventWeight<<endl;
    }

    if (mcEventWeight >1e04){
      weight10k++;
      //cout<<mcEventWeight<<endl;
    }
    if (mcEventWeight >1e05){
      weight100k++;
      cout<<mcEventWeight<<endl;
      continue;
    }
    // if (mcEventWeight >1e06){
    //   weight1M++;
    //   //cout<<mcEventWeight<<endl;
    // }
      
    if (mcEventWeight> maxWeight){
      maxWeight = mcEventWeight;
    }
    if(truthStable_el_pt->size()>0){
      h_truthStable_el_pt->Fill(truthStable_el_pt->at(0)/1000, mcEventWeight );
      h_truthStable_el_eta->Fill(truthStable_el_eta->at(0), mcEventWeight );
      h_truthStable_el_phi->Fill(truthStable_el_phi->at(0), mcEventWeight );
    }
    
    if(truthStable_mu_pt->size()>0){
      h_truthStable_mu_pt->Fill(truthStable_mu_pt->at(0)/1000, mcEventWeight );
      h_truthStable_mu_eta->Fill(truthStable_mu_eta->at(0), mcEventWeight );
      h_truthStable_mu_phi->Fill(truthStable_mu_phi->at(0), mcEventWeight );
    }
    h_mcEvtWeight -> Fill(mcEventWeight);
 
  } //loop ends
  cout<<"Number of events  --> "<<count<<endl;
  cout<<"Number of events with mcEventWeight > 1000 --> "<<weight1000<<endl;
  cout<<"Number of events with mcEventWeight > 10k --> "<<weight10k<<endl;
  cout<<"Number of events with mcEventWeight > 100k --> "<<weight100k<<endl;
  //cout<<"Number of events with mcEventWeight > 1M--> "<<weight1M<<endl;
  cout<<"Max weight --> "<<maxWeight<<endl;

  foutput->Write();
  foutput->Close();


  
  
}
