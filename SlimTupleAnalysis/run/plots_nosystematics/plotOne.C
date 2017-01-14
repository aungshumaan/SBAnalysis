{
  #include "makerHelper.h" //for AddOverflowBinToLastBin function

  
       
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.8.root");
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4_looseBadMuon1.1_isolation.root");
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv7_looseBadMuon1.1.root");
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1.lv4b_looseBadLep3.root");
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/lvqqWithMetFakeRegion.root");
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_jetpt40_cutflow.root");
  
  c1->Print("plotOne.pdf[","pdf");
  
  
  const int nSample =1; TString sampleName[nSample] = { "VBS_WV_0_0"};
  //const int nSample =8; TString sampleName[nSample] = { "Data","Wjets","Zjets","Ttbar","SingleTop","WZZZWg","VBS_WV_0_0","VBS_WV_0_03"}
  //const int nSample =7; TString sampleName[nSample] = { "Data","Wjets","Zjets","Ttbar","WZZZWg","VBS_WV_0_0","VBS_WV_0_03"};
  
  const int nRegion =1; TString regionName[nRegion] = {"CR_Wjj"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_Wjj","CR_WjjfatOnly","SR","SRfatOnly"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_WjjMJJ200","CR_WjjMJJ400","CR_WjjMJJ600","CR_WjjMJJ800"};
  
  
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};
  const int nFlavor =4; TString flavorName[nFlavor] = { "ep","em","mp","mm"};
  
  
  //const int nHist =4 ;TString histName[nHist]={ "min_dR_lepjet","min_dR_lepfatjet","min_dR_FJ_jet" ,"dR_FJ_jets" };
  //const int nHist =1 ;TString histName[nHist]={ "mjjTagged_MET" };
  //const int nHist =1 ;TString histName[nHist]={ "mTWV_ptwlep" };
  //const int nHist =8 ;TString histName[nHist]={ "elRelEtCone30","elRelPtCone30","elz0sinth","eld0sigd0","muRelEtCone30","muRelPtCone30","muz0sinth","mud0sigd0" };
  const int nHist =1 ;TString histName[nHist]={ "Wjet1_eta"};
  
  for (int iHist=0;iHist<nHist;iHist++){
    for (int iSample=0;iSample<nSample;iSample++){
      for (int iRegion=0;iRegion<nRegion;iRegion++){
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){	
	
	  //TH1F* h1=(TH1F*)f1->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //h1->Add((TH1F*)f1->Get(Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ));
	  //TH1F* h1=(TH1F*)f1->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //TH2F* h1=(TH2F*)f1->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  ////
	  // /*
	  TH2F* h0=(TH2F*)f1->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  //cout<<h0->GetName()<<endl;
	  TString name = h0->GetName();
	  TProfile* h1= (TProfile*)h0-> ProfileX (name+"_prof");
	  //h1->SetMaximum(200);
	  h1->GetYaxis()->SetRangeUser(0,200);
	  // */
	  /////
	
	  h1->Draw("colz");
	  AddOverflowBinToLastBin(h1);
	  //c1->SetLogy();
	  
	  //h1->SetTitle(" ");
	  //h1->Draw("colz");
	  //h1->Scale(1/h1->Integral());
	  //h2->Draw("same");
	  //h2->SetLineColor(kRed);
	  //h2->Scale(1/h2->Integral());
	  //h1->SetMaximum(1.7*h1->GetBinContent(h1->GetMaximumBin()));
	  
	  //TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	  
	  //l->AddEntry(h1,"CR_Top","l");
	  //l->AddEntry(h2,"SR","l");
	  //l->Draw();
	  
	  //double corr =h1->GetCorrelationFactor() ;
	  //double corr =h0->GetCorrelationFactor() ;
	  
	  //TString latexString = Form("correlation = %f",corr);
	  //cout<<latexString<<endl;
	  
	  gStyle->SetOptStat(0);
	  TLatex l;
	  l.SetTextSize(0.04); 
	  l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	  l.SetTextColor(1); //black
	  //l.DrawLatex(0.20 , 0.82, latexString);
	  
	  
	  //c1->Print("plotOne.pdf","pdf");
	  c1->Print("plotOne.pdf",Form("Title:%s_%s_%s_%s",sampleName[iSample].Data(),flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	}
      }
    }
  }
  
  c1->Print("plotOne.pdf]","pdf");
  
}
