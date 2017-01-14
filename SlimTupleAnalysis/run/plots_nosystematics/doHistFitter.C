#include <Riostream.h>
#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TArrow.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TString.h"
#include "TLegend.h"
#include "TLatex.h"
#include "THStack.h"
#include "TGraph.h"
#include "TList.h"
#include "TStyle.h"

#include <map>
//#include "newstyle.C"
//#include "styling.C"
//#include <algorithm>//for std::max

//#include <string.h>
using namespace std;
void doHistFitter(){
  
  gStyle->SetOptStat(0);
  TH1::SetDefaultSumw2(kTRUE);

  TH1F* h_data, *h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC, *h_signal;
  
  TString histName ="ptwlep";
  TFile *f = new TFile("../hwwlvqq.Nominal.4.2_variableBin.root");
  TFile *f1 = new TFile("../fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root"); //for QCD
    
  TFile *myTemplate= new TFile("template_histFitter.root", "RECREATE");

  
  h_data=(TH1F*)f->Get("H_Data_em_WBF_CR_Top_"+histName);
  h_data->SetName("hdat");
  h_ttbar=(TH1F*)f->Get("H_Ttbar_em_WBF_CR_Top_"+histName);
  h_ttbar->SetName("ttbar");
  h_Wjets=(TH1F*)f->Get("H_Wjets_em_WBF_CR_Top_"+histName);
  h_Wjets->SetName("Wjets");
  h_Zjets=(TH1F*)f->Get("H_Zjets_em_WBF_CR_Top_"+histName);
  h_Zjets->SetName("Zjets");
  h_singleTop=(TH1F*)f->Get("H_SingleTop_em_WBF_CR_Top_"+histName);
  h_singleTop->SetName("singleTop");
  h_diboson=(TH1F*)f->Get("H_WZZZWg_em_WBF_CR_Top_"+histName);
  h_diboson->SetName("diboson");
  h_qcd=(TH1F*)f1->Get("H_QCD_em_WBF_CR_Top_"+histName);
  h_qcd->SetName("QCD");
  h_signal=(TH1F*)f->Get("H_VBS_WV_0_0_em_WBF_CR_Top_"+histName);
  h_signal->SetName("signal_EW");

  h_data->Write();
  h_ttbar->Write();
  h_Wjets->Write();
  h_Zjets->Write();
  h_singleTop->Write();
  h_diboson->Write();
  h_qcd->Write();
  h_signal->Write();

  

  myTemplate->Close();

 

}

