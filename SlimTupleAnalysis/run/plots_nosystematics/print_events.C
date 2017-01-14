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
#include <cstdlib>
#include <map>

void get(TString histfilename,TString treename,Int_t event){
  TFile* thedatafile = TFile::Open(histfilename);
  TTree* tree=(TTree*)thedatafile->Get(treename);
  int nentries = tree->GetEntries();
  const float GeV =0.001;
  
  //cout<<nentries<<endl;
  //cout<<"event = "<<event<<endl;
  //tree->SetScanField(0);
  //tree->Scan("RunNumber:EventNumber:jet_AntiKt4LCTopo_n:jet_AntiKt4LCTopo_pt[0]:jet_AntiKt4LCTopo_eta[0]:el_n:el_pt[0]:el_eta[0]:MET_RefFinal_et","EventNumber>0 && EventNumber<=10");
  
  //tree->Scan("EventNumber:jet_AntiKt4LCTopo_pt[0]:jet_AntiKt4LCTopo_eta[0]:el_pt[0]:el_eta[0]:MET_RefFinal_et",Form("EventNumber == %d ",event));

  
  
  TBranch* branch_eventNumber;
  TBranch* branch_njets;
  TBranch* branch_jetpt;
  //TBranch* branch_jeteta;
  //TBranch* branch_met;
  UInt_t eventNumber;
  Int_t njets, tentry;
  std::vector<float>* jetpt;
  //std::vector<float>* jeteta;
  //Float_t met;
  


 
  //tree->SetBranchStatus("*",0);
  //tree->SetBranchStatus("jet_AntiKt4LCTopo_pt",1);
  //tree->SetBranchStatus("jet_AntiKt4LCTopo_n",1);

  
  tree->SetBranchAddress("EventNumber",&eventNumber,&branch_eventNumber);
  tree->SetBranchAddress("jet_AntiKt4LCTopo_n",&njets,&branch_njets);
  tree->SetBranchAddress("jet_AntiKt4LCTopo_pt",&jetpt,&branch_jetpt);
  //tree->SetBranchAddress("jet_AntiKt4LCTopo_eta",&jeteta,&branch_jeteta);  
  //tree->SetBranchAddress("MET_RefFinal_et",&met,&branch_met);
    
  
  for (int i=0;i<nentries;++i){
    //if (i>10) break;
    tentry = tree->LoadTree(i);
    
    branch_eventNumber->GetEntry(tentry);

    //branch_eventNumber= tree->GetBranch("EventNumber");
    //branch_eventNumber->GetEntry(i);
    //eventNumber=branch_eventNumber->GetLeaf("EventNumber")->GetValue(); //this method does not work for jet_pt,el_pt etc which are vectors

    //if (eventNumber>=0 && eventNumber<=10){
    
    if (eventNumber==event){
   
      cout<<"EventNumber = "<<eventNumber<<": ";

      branch_njets->GetEntry(tentry);
      branch_jetpt->GetEntry(tentry);
      //branch_jeteta->GetEntry(tentry);
      //branch_met->GetEntry(tentry);

      
      //cout << tentry << endl;
      //cout << "jetsize = " << njets <<endl;
      // for (int j=0;j<njets;j++ ){
      // 	cout << "jet_pt = " << jetpt[0][j] <<endl;
      // }
      //cout << "leading jet_pt = " << jetpt[0][0]*GeV <<endl; //GeV
      cout << jetpt[0][0]*GeV <<endl; //GeV
      //cout << jetpt[0][0] <<endl; //MeV
      //cout << jeteta[0][0] <<endl;
      //cout << jetpt[0][0]*GeV <<" "<<jeteta[0][0] <<endl; ///Together crashes
      //cout << met*GeV <<endl; //GeV

      //number= jetpt[0][0]*GeV;
      
      //jetpt->clear();
      //jeteta->clear();
      
      // for (int ijet=0;ijet<njets;++ijet){
      // 	branch_jetpt= tree->GetBranch("jet_AntiKt4LCTopo_pt");
      // 	branch_jetpt->GetEntry(i);
      // 	jetpt = branch_jetpt->GetLeaf("jet_AntiKt4LCTopo_pt")->GetValue(ijet);
      // 	cout<<"jet["<<ijet<<"] pt = "<<jetpt<<endl;
      // }
    }
  }
  
}
void print_events(){

  for (int i=1;i<10;i++){

    //TH1F* h=new TH1F ("h","h",20,0,200);
    //Float_t number=0.;

    get("/export/scratch1/azaman/AlpgenCAFProduction/mc12_8TeV.147030.AlpgenPythia_Auto_P2011C_WenuNp5incl.merge.NTUP_SMWZ.e1879_s1581_s1586_r3658_r3549_p1328_tid01254622_00/NTUP_SMWZ.01254622._000001.root.1","physics",i);
  }
  // for (int i=1;i<10;i++){
  //   get("/export/scratch1/azaman/AlpgenCAFProduction/mc12_8TeV.147030.AlpgenPythia_Auto_P2011C_WenuNp5incl.merge.NTUP_COMMON.e1879_s1581_s1586_r3658_r3549_p1575_tid01344348_00/NTUP_COMMON.01344348._000001.root.1","physics",i);

        
  // }


}
