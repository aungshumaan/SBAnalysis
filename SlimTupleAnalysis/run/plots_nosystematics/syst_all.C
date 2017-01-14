#include <TLatex.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TLine.h>
#include <TStyle.h>
#include <TPDF.h>

#include <stdlib.h>
#include <iostream>

//void syst_all(){
void plot(TString syst){
  //=========Macro generated from canvas: c1/c1
  //=========  (Sat Jun  7 21:43:18 2014) by ROOT version5.34/18

  ///this code was originally for comparing Alpgen and sherpa samples (or powheg and mcnlo). It can be used to compare any two files

  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);


  c1->Print(Form("syst_comparioson/plots_syst_%s.pdf[",syst.Data()),"pdf");

  
  TString filename2 = Form("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.%s.sig1.root",syst.Data());
  std::cout<<filename2<<endl;
  
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.sig1.root");
  TFile *f2=TFile::Open(filename2);
  
 

  
  //const int nHist =20 ;TString histName[nHist]={"dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt" };
  //const int nHist =25 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT","ptBalance","Njet"};
  //const int nHist =11 ;TString histName[nHist] = {"lep_pt","pt_trueLep","pt_lepTrueLep","MET_et","Et_trueNu", "Et_METtrueNu","dPhilepMET", "dPhilv_true","mT","mT_true" ,"mlv_true" };
  //const int nHist =8 ;TString histName[nHist] = {"mT","mT_true","mT_dPhilepMET_lt14","mT_dPhilepMET_gt14" ,"mT_ptwlep_lt50","mT_ptwlep_50_100" ,"mT_ptwlep_100_150", "mT_ptwlep_gt150"};

  
  const int nSample =1; TString sampleName[nSample] = { "VBS_WV_02_m03"};
  //const int nSample =3; TString sampleName[nSample] = {"Wjets","Zjets" , "WZZZWg"};

  const int nRegion =4; TString regionName[nRegion] = {"CR_Top","SR","CR_TopFJ","SRFJ"};
  //const int nRegion =6; TString regionName[nRegion] = {"BTAG","CR_Top","CR_Wjj","SR","CR_TopFJ","SRFJ"};
  //const int nRegion =6; TString regionName[nRegion] = {"PRESELECT","WJET","BTAG","CR_Top","CR_Wjj","SR"};

  //const int nPoint =1; TString pointName[nPoint] = {"WV_0_0"};
  //const int nPoint =3; TString pointName[nPoint] = {"WV_0_0","WV_0_02","WV_03_0"};

  const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nHist =2 ;TString histName[nHist]={"mjjTagged","Mwjj"}; 
  const int nHist =12 ;TString histName[nHist]={"mjjTagged","ptjjTagged","dEtaTaggedJets","Mwjj","ptwjj","ptwlep","Mlvjj","Njet","jet1_pt","jet2_pt","jet3_pt","jet4_pt"}; //RunNumber
  //const int nHist =25 ;TString histName[nHist]={ "Mwjj","dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "dRWjets","lep_pt","lep_eta","MET_et","mT","ptBalance","Njet"};
  
  //const int nHist =20 ;TString histName[nHist]={ "mjjTagged","ptjjTagged","dEtaTaggedJets","Mwjj","ptwjj","ptwlep","Mlvjj","dRWjets", "Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","MET_et","mT","ptBalance","etaY","cosThetaWDecay","Njet"};
  //const int nHist =4 ;TString histName[nHist]={ "vbfjet1_eta","vbfjet2_eta" ,"Wjet1_eta","Wjet2_eta"};

  for (int iHist=0;iHist<nHist;iHist++){
    for (int iSample=0;iSample<nSample;iSample++){
      for (int iRegion=0;iRegion<nRegion;iRegion++){
	
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){	
	  

	  TH1F* h1=(TH1F*)f1->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1->Add((TH1F*)f1->Get(Form("H_%s_%sm_WBF_%s_%s",  sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	  TH1F* h2=(TH1F*)f2->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h2->Add((TH1F*)f2->Get(Form("H_%s_%sm_WBF_%s_%s",   sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));


	  	  
	  TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	  p1->Draw();
	  p2->Draw();
	  p1->cd();
     
	  h1->SetLineColor(kBlack);
	  //h1->Scale(1/h1->Integral());
	  TString histTitle = Form("%s_%s_%s_%s",  sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data());
	  //h1->SetTitle(Form("%s_%s_%s_%s",  sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1->SetTitle( histTitle );
	  
        
	  h2->SetLineColor(kGreen);
	  //h2->Scale(1/h2->Integral());
	  

	  if(histName[iHist]!="Njet"){
	    h1->Rebin(5);
	    h2->Rebin(5);
	  }
	  
	  h1->Draw();
	  h2->Draw("same");
	  
	  double maxi= 0;
	  if (maxi<h1->GetBinContent(h1->GetMaximumBin())){
	    maxi=h1->GetBinContent(h1->GetMaximumBin());
	  }
	  if (maxi<h2->GetBinContent(h2->GetMaximumBin())) {
	    maxi=h2->GetBinContent(h2->GetMaximumBin());
	  }
	  h1->SetMaximum(maxi*1.5);

	  TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    

	  l->AddEntry(h1,"Nominal","l");
	  l->AddEntry(h2,syst.Data(),"l");
	  l->Draw();

	  double xstart=h1->GetBinLowEdge(1);
	  double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);

	  p2->cd();
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist = (TH1F*)h2->Clone();
	  ratioHist->Divide(h1);
	  ratioHist->GetYaxis()->SetRangeUser(0.3, 2.5);
	  ratioHist->SetMarkerStyle(20);
	  ratioHist->Draw();
	  ratioHist->SetTitle("JER/Nominal");

	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
	  
	  


	  //c1->Print(Form("syst_comparioson/plots_syst_%s.pdf",syst.Data()),"pdf");
	  c1->Print(Form("syst_comparioson/plots_syst_%s.pdf",syst.Data()),Form("Title:%s",histName[iHist].Data()));
	  
	  
	  p1->Clear();
	  p2->Clear();
	  
	  c1->cd();
	  
	  


	  //}
	}
      }
    }
  }
  f1->Close();
  f2->Close();
   
  
  c1->Print(Form("syst_comparioson/plots_syst_%s.pdf]",syst.Data()),"pdf");

}  

void syst_all(){
  //const int nsys=16;TString s[nsys]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  const int nsys=1;TString s[nsys]={"JERUp"};
  
  for (int i_sys=0;i_sys<nsys;i_sys++){
    plot(s[i_sys]);
  }
}
