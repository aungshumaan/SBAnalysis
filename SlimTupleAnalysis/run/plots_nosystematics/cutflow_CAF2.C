#include <TFile.h>
#include <TApplication.h> 
#include <TRint.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TBranch.h>
#include <TH1.h>

#include <string>
#include <iostream>
#include <fstream>
#include <TCanvas.h>
using namespace std;

void cutflow_CAF2(TString name=""){

  //name of the text file listing all the CAF files
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.3.3_sbahead/list.183735.JMSUp.txt"; //HARD CODED
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.list.3.29/list.167740.Nominal.txt";
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.4.1_sbahead/list.periodL.physics_Egamma.Nominal.txt";
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.4.1_sbahead/list.periodA.physics_Egamma.Nominal.txt";
  //  TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.4.2/list.periodA.physics_Egamma.Nominal.new.txt";
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/list.periodL.physics_Muons.Nominal.txt";
  //TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/list.185894.Nominal.txt";
  TString fname ="/export/home/azaman/Analysis5/MakeSlimNtuple/input.notrig_noNjet/list.185721.Nominal.txt";

  /////Give the DS ID as argument
  //TString fname =Form("/export/home/azaman/Analysis5/MakeSlimNtuple/input.list.3.25/list.%s.Nominal.txt",name.Data());
  //TString fname =Form("/export/home/azaman/Analysis5/MakeSlimNtuple/input.list.3.3/list.%s.Nominal.txt",name.Data());
  //TString fname =Form("/export/home/azaman/Analysis5/MakeSlimNtuple/bla/list.%s.Nominal.txt",name.Data());
  //TString fname =Form("/export/home/azaman/Analysis5/MakeSlimNtuple/input.list.3.25_sbahead/list.%s.Nominal.txt",name.Data());


  //TString fname =Form("/export/home/azaman/Analysis5/MakeSlimNtuple/list.%s.NP_Special1JESDown.txt",name.Data());//test
  
  //TString fname =("/export/home/azaman/Analysis5/MakeSlimNtuple/list.185721.Nominal.txt");
  //TString fname =("/export/home/azaman/Analysis5/MakeSlimNtuple/input.3.25.SBAHEAD/list.145161.Nominal.txt");

  //TString fname ="/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/list.periodA.physics_Muons_VBS_3.25_sbahead_small.txt";
  //TString fname ="/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/list.periodL_VBS_3.25.txt";
  //TString fname ="/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/list.periodL_VBS_3.25_sbahead.txt";
  
  std::cout<<name<<endl;
  
 
  std::ifstream ifs(fname);
  
  
  std::size_t count = std::distance(std::istream_iterator<std::string>(ifs), 
                                  std::istream_iterator<std::string>());
  cout<<"Number of files "<<count<<endl;

  TString histName[count];
 
  //std::ifstream file("/export/scratch1/azaman/CAF/test/183736.Sherpa_WWtomunuqq_2.52_CAF.txt");
  std::ifstream file(fname);

  if (file.is_open())
    {
      
      for (int i=0;i<count;++i)

  	{
  	  file>> histName[i];
  	  //cout<< histName[i]<<endl;
  	}
    }


  ////////TFile  *foutput = new TFile("cutflow_"+name+".root","RECREATE");
 
  // /*
   TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
   c1->Range(-6.375001,-12177.14,67.375,109594.2);
   c1->Print("plots_cutflow_CAF2.pdf[");
  // */
    
  TFile *f = TFile::Open(histName[0]);
  
  TH1D *h=(TH1D*)f->Get("l_channel"); //combined lepton
  
  TH1D *h2=(TH1D*)f->Get("e_channel"); //e_channel
  //TH1D *h2=(TH1D*)f->Get("electronCutflow"); //e_channel
  TH1D *h3=(TH1D*)f->Get("m_channel"); // m_channel
  for (int i=1;i<count;i++){
    TFile *f1 = TFile::Open(histName[i]);
    h->Add((TH1D*)f1->Get("l_channel"));
    h2->Add((TH1D*)f1->Get("e_channel"));
    //h2->Add((TH1D*)f1->Get("electronCutflow"));
    h3->Add((TH1D*)f1->Get("m_channel"));
    f1->Close();
  }

 
  
  // /*
  //l_channel
  h->Draw();  

  c1->Print("plots_cutflow_CAF2.pdf");


  //e_channel
  //h2->Draw();

  //c1->Print("plots_cutflow_CAF2.pdf");


  //m_channel
  ///h3->Draw();

  c1->Print("plots_cutflow_CAF2.pdf");
  // */
  ////
   for (int ibin=1;ibin<h->GetNbinsX();ibin++){
     //cout<<h->GetXaxis()->GetBinLabel(ibin)<<" --> "<<h->GetBinContent(ibin)<<" \n";
     cout<<h->GetBinContent(ibin)<<" \n";
   }

   cout<<"\n\n";
   ////
   //cout<<h->GetXaxis()->GetBinLabel(1)<<" --& "<<h->GetBinContent(1)<<" \n";
    
  c1->Print("plots_cutflow_CAF2.pdf]");
 
  /*  /////////////
  foutput->cd();

  h->Write();
  h2->Write();
  h3->Write();

  foutput->Close();
  */  ///////////
  f->Close();
  
  
   
}
