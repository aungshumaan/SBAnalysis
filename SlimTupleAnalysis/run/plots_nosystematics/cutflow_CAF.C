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


void cutflow_CAF(){
  
  std::ifstream file("/export/scratch1/azaman/CAF/HWW_2.29_lvqq_0.10_0_Nominal/periodD_Egamma_SMWZ_CAF.txt");
  //std::ifstream file("/export/scratch1/azaman/CAF/HWW_2.29_lvqq_0.10_0_Nominal/periodL_Muons_SMWZ_CAF.txt");
  
  std::size_t count = std::distance(std::istream_iterator<std::string>(file), 
                                  std::istream_iterator<std::string>());
  cout<<"Number of SMWZ files "<<count<<endl;

  TString histName[count];

  
  std::ifstream file1("/export/scratch1/azaman/CAF/HWW_2.29_lvqq_0.10_0_Nominal/periodD_Egamma_SMWZ_CAF.txt");
  //std::ifstream file1("/export/scratch1/azaman/CAF/HWW_2.29_lvqq_0.10_0_Nominal/periodL_Muons_SMWZ_CAF.txt");
  
  
  if (file1.is_open())
    {
      
      for (int i=0;i<count;++i)

  	{
  	  file1>> histName[i];
  	  //cout<< histName[i]<<endl;
  	}
    }

  //std::ifstream file2("/export/scratch1/azaman/CAF/test/periodA_Egamma_COMMON_CAF.txt");
  std::ifstream file2("/export/scratch1/azaman/CAF/new/periodD_Egamma_COMMON_CAF.txt");
  //std::ifstream file2("/export/scratch1/azaman/CAF/new/periodL_Muons_COMMON_CAF.txt");

  std::size_t count_common = std::distance(std::istream_iterator<std::string>(file2), 
				    std::istream_iterator<std::string>());
  cout<<"number of COMMON files "<<count_common<<endl; //number of files
  
  TString histname_common[count_common];

  //std::ifstream file3("/export/scratch1/azaman/CAF/test/periodA_Egamma_COMMON_CAF.txt");
  std::ifstream file3("/export/scratch1/azaman/CAF/new/periodD_Egamma_COMMON_CAF.txt");
  //std::ifstream file3("/export/scratch1/azaman/CAF/new/periodL_Muons_COMMON_CAF.txt");

 
  if (file3.is_open())
    {
      
      for (int i=0;i<count_common;++i)
	
  	{
  	  file3>> histname_common[i];
  	  //cout<< histname_common[i]<<endl;
  	}
    }
  
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Range(-6.375001,-12177.14,67.375,109594.2);
  c1->Print("plots_cutflow_CAF.pdf[");
    
  TFile *f = TFile::Open(histName[0]);
  //f->Close();
  TH1D *h=(TH1D*)f->Get("l_channel"); //combined lepton
  TH1D *h2=(TH1D*)f->Get("e_channel"); //e_channel
  TH1D *h3=(TH1D*)f->Get("m_channel"); // m_channel
  for (int i=1;i<count;i++){
    TFile *f1 = TFile::Open(histName[i]);
    h->Add((TH1D*)f1->Get("l_channel"));
    h2->Add((TH1D*)f1->Get("e_channel"));
    h3->Add((TH1D*)f1->Get("m_channel"));
    f1->Close();
  }

  TFile *f2 = TFile::Open(histname_common[0]);
  //f2->Close();
  TH1D *h_common=(TH1D*)f2->Get("l_channel");
  TH1D *h2_common=(TH1D*)f2->Get("e_channel");
  TH1D *h3_common=(TH1D*)f2->Get("m_channel"); 
  for (int i=1;i<count_common;i++){
    TFile *f3 = TFile::Open(histname_common[i]);
    h_common->Add((TH1D*)f3->Get("l_channel"));
    h2_common->Add((TH1D*)f3->Get("e_channel"));
    h3_common->Add((TH1D*)f3->Get("m_channel"));
    f3->Close();
  }
  

  //l_channel
  h->Draw();  //SMWZ
  h_common->Draw("same");  //COMMON
  h_common->SetLineColor(kRed);  
  c1->Print("plots_cutflow_CAF.pdf");

  //e_channel
  h2->Draw();
  h2_common->Draw("same"); 
  h2_common->SetLineColor(kRed);
  c1->Print("plots_cutflow_CAF.pdf");

  //m_channel
  h3->Draw();
  h3_common->Draw("same");  
  h3_common->SetLineColor(kRed);
  c1->Print("plots_cutflow_CAF.pdf");

  for (int ibin=1;ibin<h->GetNbinsX();ibin++){
    cout<<"SMWZ,COMMON ,"<<h->GetXaxis()->GetBinLabel(ibin)<<", "<<h->GetBinContent(ibin)<<" , ";
    cout<<h_common->GetBinContent(ibin)<<endl;
    }
  c1->Print("plots_cutflow_CAF.pdf]");
  f->Close();
  f2->Close();
  
}

