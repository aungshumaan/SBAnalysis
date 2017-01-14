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

//#include "makerHelper.h" //for AddOverflowBinToLastBin function


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

void readD3PD(){

  TH1F::SetDefaultSumw2(kTRUE);

  getFileNames("input_d3pd.txt"); //input.txt will contain the list of files to be read

  

  //TChain *mychain = new TChain("HWWTree_lvqq"); //caf file
  TChain *mychain = new TChain("physics"); //d3pd file
   
  cout<<"filenames in input.txt are:\n";
  for ( unsigned int i_nFname=0; i_nFname<fileNames.size(); i_nFname++){
    if(! (fileNames[i_nFname].Contains('#')) ){ //comment out slimntuples by putting a '#' in front.
      mychain  -> Add( fileNames[i_nFname] ); ///adding all the files in a chain
      cout<<fileNames[i_nFname]<<endl;
      
    }
  }
  
  //TFile   *foutput = TFile::Open("output_d3pd.2.root","recreate");
  
  
  TH1F* h_truthStable_em_pt     = new TH1F ("h_truthStable_em_pt","h_truthStable_em_pt",20, 0., 300.);
  TH1F* h_truthStable_em_eta     = new TH1F ("h_truthStable_em_eta","h_truthStable_em_eta", 15, -3, 3);
  TH1F* h_truthStable_em_phi     = new TH1F ("h_truthStable_em_phi","h_truthStable_em_phi",20, -4, 4);
  TH1F* h_truthStable_em_mcEvtWeight    = new TH1F ("h_truthStable_em_mcEvtWeight","h_truthStable_em_mcEvtWeight",150, -500, 1000);

  TH1F* h_truthStable_ep_pt     = new TH1F ("h_truthStable_ep_pt","h_truthStable_ep_pt",20, 0., 300.);
  TH1F* h_truthStable_ep_eta     = new TH1F ("h_truthStable_ep_eta","h_truthStable_ep_eta", 15, -3, 3);
  TH1F* h_truthStable_ep_phi     = new TH1F ("h_truthStable_ep_phi","h_truthStable_ep_phi",20, -4, 4);
  TH1F* h_truthStable_ep_mcEvtWeight    = new TH1F ("h_truthStable_ep_mcEvtWeight","h_truthStable_ep_mcEvtWeight",150, -500, 1000);

  TH1F* h_truthStable_mm_pt     = new TH1F ("h_truthStable_mm_pt","h_truthStable_mm_pt",20, 0., 300.);
  TH1F* h_truthStable_mm_eta     = new TH1F ("h_truthStable_mm_eta","h_truthStable_mm_eta", 15, -3, 3);
  TH1F* h_truthStable_mm_phi     = new TH1F ("h_truthStable_mm_phi","h_truthStable_mm_phi",20, -4, 4);
  TH1F* h_truthStable_mm_mcEvtWeight    = new TH1F ("h_truthStable_mm_mcEvtWeight","h_truthStable_mm_mcEvtWeight",150, -500, 1000);

  TH1F* h_truthStable_mp_pt     = new TH1F ("h_truthStable_mp_pt","h_truthStable_mp_pt",20, 0., 300.);
  TH1F* h_truthStable_mp_eta     = new TH1F ("h_truthStable_mp_eta","h_truthStable_mp_eta", 15, -3, 3);
  TH1F* h_truthStable_mp_phi     = new TH1F ("h_truthStable_mp_phi","h_truthStable_mp_phi",20, -4, 4);
  TH1F* h_truthStable_mp_mcEvtWeight    = new TH1F ("h_truthStable_mp_mcEvtWeight","h_truthStable_mp_mcEvtWeight",150, -500, 1000);
  
  TH1F* h_mcEvtWeight    = new TH1F ("h_mcEvtWeight","h_mcEvtWeight",150, -500, 1000);
  TH1F* h_truth_pdgId    = new TH1F ("h_truth_pdgId","h_truth_pdgId",60, -30, 30);
  
  
   

  int nentries = mychain->GetEntries();
  cout<<"nentries = "<<nentries<<endl;
 
  

  
  Int_t  tentry;

  vector< vector<double> > *mcEventWeight;

  vector<float> *truthStable_lep_pt;
  vector<float> *truthStable_lep_eta;
  vector<float> *truthStable_lep_phi;
  


  vector<int> *truth_pdgId;
  vector<int> *truth_status;


 
  TBranch* b_mcEventWeight;
 
  TBranch* b_truthStable_lep_pt;
  TBranch* b_truthStable_lep_eta;
  TBranch* b_truthStable_lep_phi;



  TBranch* b_truth_pdgId;
  TBranch* b_truth_status;
 
  


  mcEventWeight=0;
   
  truthStable_lep_pt=0;
  truthStable_lep_eta=0;
  truthStable_lep_phi=0;

  truth_pdgId =0;
  truth_status =0;
  

  
  mychain->SetBranchAddress("mcevt_weight",&mcEventWeight,&b_mcEventWeight);

  mychain->SetBranchAddress("mc_pt" , &truthStable_lep_pt  , &b_truthStable_lep_pt);
  mychain->SetBranchAddress("mc_eta", &truthStable_lep_eta , &b_truthStable_lep_eta);
  mychain->SetBranchAddress("mc_phi", &truthStable_lep_phi , &b_truthStable_lep_phi);
  
  mychain->SetBranchAddress("mc_pdgId", &truth_pdgId , &b_truth_pdgId);
  mychain->SetBranchAddress("mc_status", &truth_status , &b_truth_status);

 



  int count=0;
  int weight1000 =0;
  int weight10k =0;
  int weight100k =0;
  int weight1M =0;
  double maxWeight =0;
  for (int i=0;i<nentries;++i){
    //  for (int i=0;i<100;++i){
    count++;
    if(!(i%1000))cout<<"event "<<i<<endl;
    //if (count>10)break;
    //tentry = mychain->LoadTree(i); //TChain::LoadtTree(entry) =>find the tree which contains entry, and set it as the current tree. returns the entry number in that tree. 
    //mychain->GetEntry(tentry);
    mychain->GetEntry(i);

    //cout<<"mcEventWeight = "<<(mcEventWeight->at(0))[0]<<endl;
    double weight = (mcEventWeight->at(0))[0];

    if (weight >1000){
      weight1000++;
      //cout<<weight<<endl;
    }

    if (weight >1e04){
      weight10k++;
      //cout<<weight<<endl;
      //continue;
    }
    if (weight >1e05){
      weight100k++;
      cout<<weight<<endl;
      //continue;
    }
    if (weight >1e06){
      weight1M++;
      //cout<<weight<<endl;
    }
      
    if (weight> maxWeight){
      maxWeight = weight;
    }

    //if (weight<0 || weight > 1000.)continue;

    int n_mc = truth_pdgId->size();
    //cout<<"mc_pdgId size = "<<truth_pdgId->size()<<endl;
    //cout<<"mc_pt size = "<<truthStable_lep_pt->size()<<endl;
    //cout<<"mc_eta size = "<<truthStable_lep_eta->size()<<endl;

    if(n_mc >0){
      for (int ilep =0; ilep<n_mc; ilep++){
      
	if (truth_status->at(ilep)!=1)continue; //stable particles have status 1

	if (truth_pdgId->at(ilep)== 11  ){
	  if (truthStable_lep_pt->at(ilep)/1000 < 30.)continue;
	  //cout<<"lepton found"<<endl;
	  h_truthStable_em_pt->Fill(truthStable_lep_pt->at(ilep)/1000, weight );
	  h_truthStable_em_eta->Fill(truthStable_lep_eta->at(ilep), weight );
	  h_truthStable_em_phi->Fill(truthStable_lep_phi->at(ilep), weight );
	  h_truthStable_em_mcEvtWeight->Fill(weight );

	  // h_truthStable_em_pt->Fill(truthStable_lep_pt->at(ilep)/1000, 1. );
	  // h_truthStable_em_eta->Fill(truthStable_lep_eta->at(ilep), 1.);
	  // h_truthStable_em_phi->Fill(truthStable_lep_phi->at(ilep), 1. );
	
	}

	if (truth_pdgId->at(ilep)== -11  ){
	  if (truthStable_lep_pt->at(ilep)/1000 < 30.)continue;
	  //cout<<"lepton found"<<endl;
	  h_truthStable_ep_pt->Fill(truthStable_lep_pt->at(ilep)/1000, weight );
	  h_truthStable_ep_eta->Fill(truthStable_lep_eta->at(ilep), weight );
	  h_truthStable_ep_phi->Fill(truthStable_lep_phi->at(ilep), weight );
	  h_truthStable_ep_mcEvtWeight->Fill(weight );

	  // h_truthStable_ep_pt->Fill(truthStable_lep_pt->at(ilep)/1000, 1. );
	  // h_truthStable_ep_eta->Fill(truthStable_lep_eta->at(ilep), 1.);
	  // h_truthStable_ep_phi->Fill(truthStable_lep_phi->at(ilep), 1. );
	
	}
	if (truth_pdgId->at(ilep)== 13  ){
	  if (truthStable_lep_pt->at(ilep)/1000 < 30.)continue;
	  //cout<<"lepton found"<<endl;
	  h_truthStable_mm_pt->Fill(truthStable_lep_pt->at(ilep)/1000, weight );
	  h_truthStable_mm_eta->Fill(truthStable_lep_eta->at(ilep), weight );
	  h_truthStable_mm_phi->Fill(truthStable_lep_phi->at(ilep), weight );
	  h_truthStable_mm_mcEvtWeight->Fill(weight );
	  
	  // h_truthStable_mm_pt->Fill(truthStable_lep_pt->at(ilep)/1000, 1. );
	  // h_truthStable_mm_eta->Fill(truthStable_lep_eta->at(ilep), 1.);
	  // h_truthStable_mm_phi->Fill(truthStable_lep_phi->at(ilep), 1. );
	  
	}

	if (truth_pdgId->at(ilep)== -13  ){
	  if (truthStable_lep_pt->at(ilep)/1000 < 30.)continue;
	  //cout<<"lepton found"<<endl;
	  h_truthStable_mp_pt->Fill(truthStable_lep_pt->at(ilep)/1000, weight );
	  h_truthStable_mp_eta->Fill(truthStable_lep_eta->at(ilep), weight );
	  h_truthStable_mp_phi->Fill(truthStable_lep_phi->at(ilep), weight );
	  h_truthStable_mp_mcEvtWeight->Fill(weight );
	  
	  // h_truthStable_mp_pt->Fill(truthStable_lep_pt->at(ilep)/1000, 1. );
	  // h_truthStable_mp_eta->Fill(truthStable_lep_eta->at(ilep), 1.);
	  // h_truthStable_mp_phi->Fill(truthStable_lep_phi->at(ilep), 1. );
	  
	}
      }
    }
 
    h_mcEvtWeight -> Fill(weight);

     
  } //loop ends
  cout<<"Number of events  --> "<<count<<endl;
  cout<<"Number of events with weight > 1000 --> "<<weight1000<<endl;
  cout<<"Number of events with weight > 10k --> "<<weight10k<<endl;
  cout<<"Number of events with weight > 100k --> "<<weight100k<<endl;
  cout<<"Number of events with weight > 1M--> "<<weight1M<<endl;
  cout<<"Max weight --> "<<maxWeight<<endl;

  foutput->Write();
  foutput->Close();


  
  
}
