#include "TH1.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TLorentzVector.h> 
#include <THStack.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TLine.h>
#include <TStyle.h>
#include <TMath.h>
#include <TString.h>

// C++
#include <iostream>
#include <fstream>
#include <sstream>

void truthQCDWgamma(){
  //9/6/14
  ///modified from sherpaAlp.C
  //#include <TStyle.h>
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  // TStyle *ts= new TStyle("","");
  // ts->SetPadGridY(kTRUE);
  //gStyle->SetPadGridY(kTRUE);
  
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_truthQCDWgamma.pdf[","pdf");

  //TFile *f1= TFile::Open("/export/home/azaman/vbsStudy/run/sigBkg_lep30_met30_jet60.60.30_mjj500_mt40/hist-WplnuWmjjjj_notop_QCD.root");
  TFile *f1= TFile::Open("/export/home/azaman/vbsStudy/run/submitDir/hist-WplnuWmjjjj_notop_QCD.root");
  TFile *f2= TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10_diboson.root");

  //const int nHist =23 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT"};
  const int nHist =19 ;TString histName[nHist]={"mjjTagged","Mwjj", "ptwjj","ptwlep","Mlvjj","MET_et","mT","dRWjets","dEtaMax","ptjjMax","jet1_pt","jet2_pt","jet3_pt","jet4_pt","jet1_eta","jet2_eta","jet3_eta","jet4_eta","lep_pt"};

  for (int iHist=0;iHist<nHist;iHist++){
    // TH1F* h1=(TH1F*)f1->Get("H_Wjets_em_WBF_CR_Wjj_"+histName[iHist]);
    // TH1F* h2=(TH1F*)f2->Get("H_Wjets_em_WBF_CR_Wjj_"+histName[iHist]);

    //TH1F* h1=(TH1F*)f1->Get("H_Ttbar_ep_WBF_CR_Top_"+histName[iHist]);
    //TH1F* h2=(TH1F*)f2->Get("H_Ttbar_ep_WBF_CR_Top_"+histName[iHist]);

    TH1F* h1=(TH1F*)f1->Get("hist_"+histName[iHist]); //truth for electron channel
    float lumi=20000;//in pb-1
    float cs_QCD=1.634;
    unsigned int nevents_QCD_8TeV=90000;
    float scale_QCD_8TeV=lumi*cs_QCD/nevents_QCD_8TeV;
    h1->Scale(scale_QCD_8TeV);
    TH1F* h2=(TH1F*)f2->Get("H_Wgamma_em_WBF_SR_"+histName[iHist]);
    h2->Add((TH1F*)f2->Get("H_Wgamma_ep_WBF_SR_"+histName[iHist]));

    TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
    TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
    p1->Draw();
    p2->Draw();
    p1->cd();
     
    h1->SetLineColor(kBlue);
    h1->Scale(1/h1->Integral());
    h1->Draw();
   
 
  
   
    h2->SetLineColor(kRed);
    h2->Scale(1/h2->Integral());
    h2->Draw("same");

    double maxi= 0;
    if (h1->GetBinContent(h1->GetMaximumBin())>h2->GetBinContent(h2->GetMaximumBin())){
      maxi=h1->GetBinContent(h1->GetMaximumBin());
    }else{
      maxi=h2->GetBinContent(h2->GetMaximumBin());
    };
    h1->SetMaximum(maxi*1.2);
     
    TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
  
    l->AddEntry(h1,"truth QCD","l");
    l->AddEntry(h2,"Wgamma","l");
     
    l->Draw();

    double xstart=h1->GetBinLowEdge(1);
    double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);

    p2->cd();
    //gStyle->SetOptStat(0);
    //gStyle->SetPadGridY(kTRUE);
    // TStyle *ts= new TStyle("","");
    // ts->SetPadGridY(kTRUE);
    //c1->SetGridY(kTRUE);
    TH1F *ratioHist = (TH1F*)h1->Clone();
    ratioHist->Divide(h2);
    ratioHist->GetYaxis()->SetRangeUser(0., 2.);
    ratioHist->SetMarkerStyle(20);
    ratioHist->Draw();
    ratioHist->SetTitle("ratio");
    TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
    horiz_line->SetLineStyle(2);
    //horiz_line->DrawLine(xstart,1.0,xend,1.0);
   
 
    c1->Print("plots_truthQCDWgamma.pdf","pdf");

    p1->Clear();
    p2->Clear();
	  
    c1->cd();

    }
   
  c1->Print("plots_truthQCDWgamma.pdf]","pdf");
}
