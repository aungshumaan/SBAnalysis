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


void cutflow_CAF_blah(){

  
  
  //std::ifstream file("/export/home/azaman/110101_VBS3.1_CAF.txt");
  std::ifstream file("/export/home/azaman/147774.test_VBS3.22_CAF.txt");
  
  
  std::size_t count = std::distance(std::istream_iterator<std::string>(file), 
                                  std::istream_iterator<std::string>());
  cout<<"Number of files "<<count<<endl;
  

  TString histName[count];

  //std::ifstream file1("/export/home/azaman/110101_VBS3.1_CAF.txt");
  std::ifstream file1("/export/home/azaman/147774.test_VBS3.22_CAF.txt");
  
  
  
  if (file1.is_open())
    {
      
      for (int i=0;i<count;++i)

  	{
  	  file1>> histName[i];
  	  cout<< histName[i]<<endl;
  	}
    }

 
  int countEmptyFiles =0;
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Range(-6.375001,-12177.14,67.375,109594.2);
  c1->Print("plots_cutflow_CAF_blah.pdf[");
    
  TFile *f = TFile::Open(histName[0]);
  //f->Close();
  TH1D *h=(TH1D*)f->Get("l_channel"); //combined lepton
  std::cout<<"l_channel events = "<<h->GetBinContent(1)<<endl;
  TH1D *h2=(TH1D*)f->Get("e_channel"); //e_channel
  TH1D *h3=(TH1D*)f->Get("m_channel"); // m_channel
  for (int i=1;i<count;i++){
    TFile *f1 = TFile::Open(histName[i]);
    std::cout<<"reading "<<histName[i]<<" ..."<<endl;
    TH1D *htmp=(TH1D*)f1->Get("l_channel");
    if(htmp->GetBinContent(1)==0){countEmptyFiles++;}
    h->Add((TH1D*)f1->Get("l_channel"));
    std::cout<<"l_channel events = "<<h->GetBinContent(1)<<endl;
    h2->Add((TH1D*)f1->Get("e_channel"));
    h3->Add((TH1D*)f1->Get("m_channel"));
    
    f1->Close();
  }

  std::cout<<"l_channel total events = "<<h->GetBinContent(1)<<endl;
  std::cout<<"Number of empty files is "<<countEmptyFiles<<" out of "<<count<<" files."<<endl;
  

  // //l_channel
  h->Draw();  //SMWZ

  c1->Print("plots_cutflow_CAF_blah.pdf");

  // //e_channel
  // h2->Draw();

  // c1->Print("plots_cutflow_CAF_blah.pdf");

  // //m_channel
  // h3->Draw();

  //c1->Print("plots_cutflow_CAF_blah.pdf");

  // for (int ibin=1;ibin<h->GetNbinsX();ibin++){
  //   cout<<"COMMON ,"<<h->GetXaxis()->GetBinLabel(ibin)<<", "<<h->GetBinContent(ibin)<<endl;
    
  // }


   c1->Print("plots_cutflow_CAF_blah.pdf]");
  f->Close();
  
  
}

