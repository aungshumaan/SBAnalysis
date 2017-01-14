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

void get(TString histfilename,TString treename,Int_t event){
  TFile* thedatafile = TFile::Open(histfilename);
  TTree* tree=(TTree*)thedatafile->Get(treename);
  int nentries = tree->GetEntries();
  cout<<nentries<<endl;
  //tree->SetScanField(0);
  //tree->Scan("RunNumber:EventNumber:jet_AntiKt4LCTopo_n:jet_AntiKt4LCTopo_pt[0]:jet_AntiKt4LCTopo_eta[0]:el_n:el_pt[0]:el_eta[0]:MET_RefFinal_et","EventNumber>0 && EventNumber<=10");
 
  
  UInt_t          runNumber;
  UInt_t          eventNumber;
  Int_t njets, tentry;
  vector<float> *jetpt;

  TBranch* b_eventNumber;
  TBranch* b_runNumber;
  TBranch* b_njets;
  TBranch* b_jetpt;

  eventNumber=0;
  runNumber=0;
  njets=0;
  jetpt=0;

  tree->SetBranchAddress("EventNumber",&eventNumber,&b_eventNumber);
  tree->SetBranchAddress("RunNumber",&runNumber,&b_runNumber);
  // tree->SetBranchAddress("jet_AntiKt4LCTopo_n",&njets,&b_njets);
  // tree->SetBranchAddress("jet_AntiKt4LCTopo_pt",&jetpt,&b_jetpt);
  tree->SetBranchAddress("jet_n",&njets,&b_njets);
  tree->SetBranchAddress("jet_pt",&jetpt,&b_jetpt);


  // tentry = tree->LoadTree(0);
  // cout<<tentry<<endl;
  // tree->GetEntry(tentry);

  // cout   <<" number of jets= "<<njets<<endl;
  // if(jetpt->size()>1)cout<<" jetpt0 = "<<jetpt->at(0)<<" "<<" and jetpt1 = "<<jetpt->at(1)<<endl;

  int count=0;
  for (int i=0;i<nentries;++i){
  //for (int i=0;i<100;++i){
    count++;
    //if (count>10)break;
    tentry = tree->LoadTree(i); //TChain::LoadtTree(entry) =>find the tree which contains entry, and set it as the current tree. returns the entry number in that tree. 
    tree->GetEntry(tentry);
    
    if (eventNumber==event){
      // if (1){
 
	cout<<tentry<<" : ";
	cout   <<" RunNumber = "<<runNumber<<" , EventNumber = "<<eventNumber<<endl;
	cout   <<" number of jets= "<<njets<<" , ";
	if(jetpt->size()>1)cout<<" jetpt0 = "<<jetpt->at(0)/1000<<" "<<" and jetpt1 = "<<jetpt->at(1)/1000<<endl;
    }
  }
  
}
void print_events2(){
    
  // get("/export/scratch1/azaman/AlpgenCAFProduction/mc12_8TeV.147030.AlpgenPythia_Auto_P2011C_WenuNp5incl.merge.NTUP_SMWZ.e1879_s1581_s1586_r3658_r3549_p1328_tid01254622_00/NTUP_SMWZ.01254622._000001.root.1","physics",1);
  // get("/export/scratch1/azaman/AlpgenCAFProduction/mc12_8TeV.147030.AlpgenPythia_Auto_P2011C_WenuNp5incl.merge.NTUP_COMMON.e1879_s1581_s1586_r3658_r3549_p1575_tid01344348_00/NTUP_COMMON.01344348._000001.root.1","physics",1);

  ///this works (verified on 2/18/15)
  get("/export/home/azaman/haifeng4/makeSlimNtuples_files/periodA.physics_Egamma.PhysCont.NTUP_COMMON.VBS_2.42_CAF_0.10_Nominal.lvqqMiniNtuple.root","HWWlvqq_mini",23942913);
  get("/export/home/azaman/haifeng4/makeSlimNtuples_files/periodA.physics_Egamma.PhysCont.NTUP_SMWZ.HWW_2.29_lvqq_0.10_0_Nominal.lvqqMiniNtuple.root","HWWlvqq_mini",23942913);

  

    
}
