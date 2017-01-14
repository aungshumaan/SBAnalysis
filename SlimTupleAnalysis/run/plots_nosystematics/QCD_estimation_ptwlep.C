#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TLine.h"
#include <iostream>
#include <math.h>


void QCD_estimation_ptwlep(){
  ///this is to get yield for a particular control region for different samples

  bool doMerge =false;
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
    
  TFile *f=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7.1_looseBadLep4.root");
  //TFile *f=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7.1_ptwlep20.root");
  
  if (!doMerge){  const int nFlav=4;TString flavorName[nFlav]={"ep","em","mp","mm"};
  }//else{  const int nFlav=2;TString flavorName[nFlav]={"e","m"};}
  else{  const int nFlav=1;TString flavorName[nFlav]={"l"};}
            
  
  //const int nCut=4;TString cutName[nCut]={"CR_Top","CR_TopfatOnly","CR_Wjj","CR_WjjfatOnly"};
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  

  
  const int nType=1;TString typeName[nType]={"Njet"};


  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iFlavor=0;iFlavor<nFlav;++iFlavor){



	if (!doMerge){
	  h_data = (TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets= (TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson= (TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop= (TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar= (TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));
     
	  h_qcd= (TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iFlavor].Data(), cutName[icut].Data(),typeName[itype].Data()));

      
      
	  
	}else{

	  double s =1.; //add or subtract negative charge
   
	  h_data=(TH1F*)f->Get(Form("H_Data_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_data->Add((TH1F*)f->Get(Form("H_Data_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_data->Add((TH1F*)f->Get(Form("H_Data_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_data->Add((TH1F*)f->Get(Form("H_Data_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_Wjets=(TH1F*)f->Get(Form("H_Wjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
      
	  h_Zjets=(TH1F*)f->Get(Form("H_Zjets_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_qcd=(TH1F*)f->Get(Form("H_QCD_ep_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data()));
	  h_qcd->Add((TH1F*)f->Get(Form("H_QCD_em_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_qcd->Add((TH1F*)f->Get(Form("H_QCD_mp_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);
	  h_qcd->Add((TH1F*)f->Get(Form("H_QCD_mm_WBF_%s_%s", cutName[icut].Data(),typeName[itype].Data())),s);

	  
	}	
      
           

	TH1F* hMC = (TH1F* ) h_Wjets->Clone();
	hMC->Add(h_Zjets);
	hMC->Add(h_ttbar);
	hMC->Add(h_singleTop);
	hMC->Add(h_diboson);
	
	cout.precision(3);
	//cout<<h_WV_0_0->Integral()<<" "<<h_WV_0_03->Integral()<<" "<<h_ZV_0_0->Integral()<<" "<<h_ZV_0_03->Integral()<<" "<<h_ttbar->Integral()<<" "<<h_Wjets->Integral()<<" "<<h_data->Integral()<<endl;
	cout<<h_qcd->Integral()<<" "<<h_ttbar->Integral()<<" "<<h_Wjets->Integral()<<" "<<h_data->Integral()<<endl; 


   
    
	//std::cout<<"h_Wjets XaxisName = "<<h_Wjets->GetXaxis()->GetTitle()<<endl;
	//std::cout<<"h_Wjets YaxisName = "<<h_Wjets->GetYaxis()->GetTitle()<<endl;
      


	// Double_t ks= h_MC->KolmogorovTest(h_data);
	// cout<<"KolmogorovTest result= "<<ks<<endl;
	
    
	  
      
      }
    }
  }
      
  f->Close();
  //f1->Close();
  


}
