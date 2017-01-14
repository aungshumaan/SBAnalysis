{
  //=========Macro generated from canvas: c1/c1
  //=========  (Sat Jun  7 21:43:18 2014) by ROOT version5.34/18

  ///this code was originally for comparing Alpgen and sherpa samples (or powheg and mcnlo). It can be used to compare any two files
#include <TLatex.h>
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_JER_BaseJES.pdf[","pdf");


  
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_2.46_Nominal3.root");
  TFile *f2=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_2.46_JER3.root");
  TFile *f3=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_2.46_JESUp3.root");
  TFile *f4=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_2.46_JESDown3.root");

  
  //const int nHist =20 ;TString histName[nHist]={"dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt" };
  //const int nHist =25 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT","ptBalance","Njet"};
  //const int nHist =11 ;TString histName[nHist] = {"lep_pt","pt_trueLep","pt_lepTrueLep","MET_et","Et_trueNu", "Et_METtrueNu","dPhilepMET", "dPhilv_true","mT","mT_true" ,"mlv_true" };
  //const int nHist =8 ;TString histName[nHist] = {"mT","mT_true","mT_dPhilepMET_lt14","mT_dPhilepMET_gt14" ,"mT_ptwlep_lt50","mT_ptwlep_50_100" ,"mT_ptwlep_100_150", "mT_ptwlep_gt150"};

  
  const int nSample =1; TString sampleName[nSample] = { "Ttbar"};
  //const int nSample =5; TString sampleName[nSample] = {"Ttbar","SingleTop", "Wjets","Zjets" , "WZZZWg"};

  //const int nRegion =2; TString regionName[nRegion] = {"CR_TopFJ","SRFJ"};
  const int nRegion =6; TString regionName[nRegion] = {"BTAG","CR_Top","CR_Wjj","SR","CR_TopFJ","SRFJ"};
  //const int nRegion =6; TString regionName[nRegion] = {"PRESELECT","WJET","BTAG","CR_Top","CR_Wjj","SR"};

  //const int nPoint =1; TString pointName[nPoint] = {"WV_0_0"};
  //const int nPoint =3; TString pointName[nPoint] = {"WV_0_0","WV_0_02","WV_03_0"};

  const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  const int nHist =1 ;TString histName[nHist]={"mjjTagged"}; 
  //const int nHist =6 ;TString histName[nHist]={"Njet","jet1_pt","jet2_pt","jet3_pt","jet4_pt","lep_pt"}; //RunNumber
  //const int nHist =25 ;TString histName[nHist]={ "Mwjj","dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "dRWjets","lep_pt","lep_eta","MET_et","mT","ptBalance","Njet"};
  //const int nHist =20 ;TString histName[nHist]={ "mjjTagged","ptjjTagged","dEtaTaggedJets","ptwjj","ptwlep","Mlvjj","Mwjj","dRWjets", "Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","MET_et","mT","ptBalance","etaY","cosThetaWDecay","Njet"};
  //const int nHist =4 ;TString histName[nHist]={ "vbfjet1_eta","vbfjet2_eta" ,"Wjet1_eta","Wjet2_eta"};

  for (int iHist=0;iHist<nHist;iHist++){
    for (int iSample=0;iSample<nSample;iSample++){
      for (int iRegion=0;iRegion<nRegion;iRegion++){
	
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){	
	  

	  TH1F* h1=(TH1F*)f1->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1->Add((TH1F*)f1->Get(Form("H_%s_%sm_WBF_%s_%s",  sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	  TH1F* h2=(TH1F*)f2->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h2->Add((TH1F*)f2->Get(Form("H_%s_%sm_WBF_%s_%s",   sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	  TH1F* h3=(TH1F*)f3->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h3->Add((TH1F*)f3->Get(Form("H_%s_%sm_WBF_%s_%s",   sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	  TH1F* h4=(TH1F*)f4->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h4->Add((TH1F*)f4->Get(Form("H_%s_%sm_WBF_%s_%s",   sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) ));

	  	  
	  TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	  p1->Draw();
	  p2->Draw();
	  p1->cd();
     
	  h1->SetLineColor(kBlack);
	  //h1->Scale(1/h1->Integral());
	  h1->SetTitle(Form("%s_%s_%s_%s",  sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	  h1->Rebin(5);
    
        
	  h2->SetLineColor(kGreen);
	  //h2->Scale(1/h2->Integral());
	  h2->Rebin(5);
	  
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
	  l->AddEntry(h2,"JER","l");
	  l->Draw();

	  double xstart=h1->GetBinLowEdge(1);
	  double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);

	  p2->cd();
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist = (TH1F*)h2->Clone();
	  ratioHist->Divide(h1);
	  ratioHist->GetYaxis()->SetRangeUser(0.3, 2.5.);
	  ratioHist->SetMarkerStyle(20);
	  ratioHist->Draw();
	  ratioHist->SetTitle("JER/Nominal");

	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
	  
	  
	  c1->Print("plots_JER_BaseJES.pdf","pdf");
	  
	  p1->Clear();
	  p2->Clear();
	  
	  c1->cd();
	  
	  
	  /////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	  TPad* p3 = new TPad("p3","p3",0.01, 0.35 ,0.99,0.99);
	  TPad* p4 = new TPad("p4","p4",0.01,0.01,0.99, 0.35);
	  p3->Draw();
	  p4->Draw();
	  p3->cd();
     

	  h3->SetLineColor(kRed);
	  //h3->Scale(1/h3->Integral());
	  h3->Rebin(5);
	  
	  h4->SetLineColor(kBlue);
	  //h4->Scale(1/h4->Integral());
	  h4->Rebin(5);
 
	  h1->Draw();
	  h3->Draw("same");
	  h4->Draw("same");
	  	  
	  
	  if (maxi<h3->GetBinContent(h3->GetMaximumBin())){
	    maxi=h3->GetBinContent(h3->GetMaximumBin());
	  }
	  if (maxi<h4->GetBinContent(h4->GetMaximumBin())){
	    maxi=h4->GetBinContent(h4->GetMaximumBin());
	  }
	  h1->SetMaximum(maxi*1.5);
     
	  TLegend *l2=new TLegend(0.7,0.7,0.9,0.9);
	  l2->AddEntry(h1,"Nominal","l");
	  l2->AddEntry(h3,"BaseJESUp","l");
	  l2->AddEntry(h4,"BaseJESDown","l");
	  l2->Draw();

	  p4->cd();
	  gStyle->SetOptStat(0);
	  TH1F *ratioHist2 = (TH1F*)h3->Clone();
	  ratioHist2->Divide(h1);
	  ratioHist2->GetYaxis()->SetRangeUser(0.3, 2.5.);
	  ratioHist2->SetMarkerStyle(20);
	  ratioHist2->SetMarkerColor(kRed);
	  ratioHist2->Draw();
	  ratioHist2->SetTitle("Syst/Nominal");	  

	  TH1F *ratioHist3 = (TH1F*)h4->Clone();
	  ratioHist3->Divide(h1);
	  ratioHist3->SetMarkerStyle(20);
	  ratioHist3->SetMarkerColor(kBlue);
	  ratioHist3->Draw("same");


	  TLine* horiz_line2 = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line2->SetLineStyle(2);
	  horiz_line2->DrawLine(xstart,1.0,xend,1.0);
	  
	  
	  c1->Print("plots_JER_BaseJES.pdf","pdf");
	  
	  p3->Clear();
	  p4->Clear();
	  
	  c1->cd();
	  
	 

	  //}
	}
      }
    }
  }
  f1->Close();
  f2->Close();
   
  c1->Print("plots_JER_BaseJES.pdf]","pdf");
}
