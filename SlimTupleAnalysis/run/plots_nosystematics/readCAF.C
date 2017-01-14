#include <cmath>
#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TLeaf.h>
#include "TCanvas.h"
#include "TLegend.h"
#include <iostream>

void readCAF(){
  TFile* thedatafile = TFile::Open("/export/scratch1/azaman/CAF/test/user.auzaman.185721.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_0_a5_0.AF2.VBS_2.51_CAF_0.10_Nominal_HWWSkimmedNTUP_lvqq.root.11276591/user.auzaman.4476825._000001.HWWSkimmedNTUP_lvqq.root");

    
  TTree* tree=(TTree*)thedatafile->Get("HWWTree_lvqq");

  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Range(-6.375001,-12177.14,67.375,109594.2);
  c1->Print("plots_readCAF.pdf[");
  
  TH1F* h_jet0_pt = new TH1F ("h_jet0_pt","h_jet0_pt",50, 0., 300.);

  TH1F* h_lepEtCone30 = new TH1F ("h_lepEtCone30","h_lepEtCone30",100,-20., 180.);
  TH1F* h_lepPtCone30 = new TH1F ("h_lepPtCone30","h_lepPtCone30",100, 0., 100.);
  TH1F* h_lepz0sinth = new TH1F ("h_lepz0sinth","h_lepz0sinth",100, 0.0, 0.2);
  TH1F* h_lepd0sigd0 = new TH1F ("h_lepd0sigd0","h_lepd0sigd0",100, 0., 25.);
  TH1F* h_lepPt = new TH1F ("h_lepPt","h_lepPt",50, 0., 400.);
  TH1F* h_etIsolation = new TH1F ("h_etIsolation","h_etIsolation",50, 0., 0.25);
  TH1F* h_ptIsolation = new TH1F ("h_ptIsolation","h_ptIsolation",50, 0., 0.25);

  int nentries = tree->GetEntries();
  cout<<nentries<<endl;
 
  
  UInt_t          runNumber;
  UInt_t          eventNumber;
  Double_t mcEventWeight;
  Int_t njets, tentry;
  vector<float> *jetpt;

  Float_t lepEtCone30;
  Float_t lepPtCone30;
  Float_t lepz0sinth;
  Float_t lepd0sigd0;  
  Float_t lepPt;

  TBranch* b_eventNumber;
  TBranch* b_runNumber;
  TBranch* b_mcEventWeight;
  TBranch* b_njets;
  TBranch* b_jetpt;

  TBranch* b_lepEtCone30;
  TBranch* b_lepPtCone30;
  TBranch* b_lepz0sinth;
  TBranch* b_lepd0sigd0;  
  TBranch* b_lepPt;
  

  eventNumber=0;
  runNumber=0;
  mcEventWeight=0.;
  njets=0;
  jetpt=0;

  lepEtCone30=0.;
  lepPtCone30=0.;
  lepz0sinth=0.;
  lepd0sigd0=0.;  
  lepPt=0.;
  

  tree->SetBranchAddress("EventNumber",&eventNumber,&b_eventNumber); //setting the address of already existing branch named "EventNumber" in the input tree to the TBranch pointer we have initialized
  tree->SetBranchAddress("RunNumber",&runNumber,&b_runNumber);
  tree->SetBranchAddress("mcEventWeight",&mcEventWeight,&b_mcEventWeight);
  
  tree->SetBranchAddress("m_jet_n",&njets,&b_njets);
  tree->SetBranchAddress("m_jet_pt",&jetpt,&b_jetpt);

  tree->SetBranchAddress("leptonEtCone30",&lepEtCone30,&b_lepEtCone30);
  tree->SetBranchAddress("leptonPtCone30",&lepPtCone30,&b_lepPtCone30);
  tree->SetBranchAddress("leptonz0sinth",&lepz0sinth,&b_lepz0sinth);
  tree->SetBranchAddress("leptond0sigd0",&lepd0sigd0,&b_lepd0sigd0);
  tree->SetBranchAddress("leptonPt",&lepPt,&b_lepPt);
 



  int count=0;
  for (int i=0;i<nentries;++i){
    //for (int i=0;i<100;++i){
    count++;
    //if (count>10)break;
    tentry = tree->LoadTree(i); //TChain::LoadtTree(entry) =>find the tree which contains entry, and set it as the current tree. returns the entry number in that tree. 
    tree->GetEntry(tentry);
    
 
 
    // cout<<tentry<<" : ";
    // cout   <<" RunNumber = "<<runNumber<<" , EventNumber = "<<eventNumber<<", mcEventWeight = "<<mcEventWeight<<endl;
    
    // cout   <<" number of jets= "<<njets<<" , ";
    
    //if(jetpt->size()>1)cout<<" jetpt0 = "<<jetpt->at(0)/1000<<" "<<" and jetpt1 = "<<jetpt->at(1)/1000<<endl;

    if(jetpt->size()>1){
      h_jet0_pt ->Fill(jetpt->at(0)/1000,mcEventWeight);
      
      h_lepEtCone30 ->Fill(lepEtCone30/1000,mcEventWeight);
      h_lepPtCone30 ->Fill(lepPtCone30/1000,mcEventWeight);
      h_lepz0sinth ->Fill(lepz0sinth,mcEventWeight);
      h_lepd0sigd0 ->Fill(lepd0sigd0,mcEventWeight);
      h_lepPt ->Fill(lepPt/1000,mcEventWeight);

      h_etIsolation->Fill(lepEtCone30/lepPt,mcEventWeight);
      h_ptIsolation->Fill(lepPtCone30/lepPt,mcEventWeight);
   
    }
  }

  h_jet0_pt->Draw();
  c1->Print("plots_readCAF.pdf");
  h_lepEtCone30->Draw();
  c1->Print("plots_readCAF.pdf");
  h_lepPtCone30->Draw();
  c1->Print("plots_readCAF.pdf");
  h_lepz0sinth->Draw();
  c1->Print("plots_readCAF.pdf");
  h_lepd0sigd0->Draw();
  c1->Print("plots_readCAF.pdf");
  h_lepPt->Draw();
  c1->Print("plots_readCAF.pdf");
  h_etIsolation->Draw();
  c1->Print("plots_readCAF.pdf");
  h_ptIsolation->Draw();
  c1->Print("plots_readCAF.pdf");
  
  c1->Print("plots_readCAF.pdf]");
  
}
