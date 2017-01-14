#include <iostream>
#include <TCanvas.h>
#include <TH1F.h>
#include <TFile.h>
#include <TLegend.h>
#include <TLine.h>
#include <TStyle.h>

using namespace std;

void Wgamma_eff(){
  
  ///this code is for investigation of cut efficiency of emfraction

  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_Wgamma_eff.pdf[","pdf");

  TH1F *h1,*h2;

  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
  TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac0.99.root");
  //TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac0.95.root");
  TFile *f2= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac.root");
  
    
  const int nRegion=3; TString regionName[nRegion]={"WBF_WJET","WBF_BTAG","WBF_SR"};
  //const int nRegion=1; TString regionName[nRegion]={"WBF_WJET"};
  
  //const int nHist =3 ;TString histName[nHist]={"Njet","min_dR_lepjet","jet_emfrac"};
  //const int nHist =2 ;TString histName[nHist]={"jet1_pt","jet_emfrac"};
  //const int nHist =5 ;TString histName[nHist]={"jet_emfrac","jet1_emfrac","jet2_emfrac","wjet1_emfrac","wjet2_emfrac"};
  //const int nHist =2 ;TString histName[nHist]={"jet1_pt","jet1_eta"};
  const int nHist =1 ;TString histName[nHist]={"jet1_eta"};

  const int nSample =3 ;TString sampleName[nSample]={"WW","WZ","Wgamma"};

  
  for (int iRegion=0;iRegion<nRegion;iRegion++){
    for (int iSample=0;iSample<nSample;iSample++){
      for (int iHist=0;iHist<nHist;iHist++){
	
	h1=(TH1F*)f1->Get(Form("H_%s_mp_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(),histName[iHist].Data()) );
	h1->Add( (TH1F*)f1->Get(Form("H_%s_mm_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(),histName[iHist].Data()) ) );
     


	h2=(TH1F*)f2->Get(Form("H_%s_mp_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(),histName[iHist].Data()) );
	h2->Add( (TH1F*)f2->Get(Form("H_%s_mm_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(),histName[iHist].Data()) ) );
      

    
	TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	p1->Draw();
	p2->Draw();
	p1->cd();
     
	h1->SetLineColor(kBlue);
	//h1->Scale(1/h1->Integral());
	h1->SetLineWidth(2);
      
	//h1->SetTitle(Form("electron_%s_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	h1->SetTitle(Form("muon_%s_%s_%s",sampleName[iSample].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	h1->Draw();
    
	h2->SetLineColor(kRed);
	//h2->Scale(1/h2->Integral());
	h2->SetLineWidth(2);
	h2->Draw("same");
      


	double maxi= 0;
      
	if (h1->GetBinContent(h1->GetMaximumBin())> maxi){
	  maxi =h1->GetBinContent(h1->GetMaximumBin());
	}
	if (h2->GetBinContent(h2->GetMaximumBin())> maxi){
	  maxi =h2->GetBinContent(h2->GetMaximumBin());
	}

	h1->SetMaximum(maxi*1.5);
     
	TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	l->AddEntry(h1,"with cut","l");
	l->AddEntry(h2,"no cut","l");
	
     
	l->Draw();

	/////cout
	std::cout<<sampleName[iSample]<<"_"<<regionName[iRegion]<<"_"<<histName[iHist]<<":";
	std::cout<<h1->Integral()<<":"<<h2->Integral()<<endl;

	////////////
      
	double xstart=h1->GetBinLowEdge(1);
	double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);

	p2->cd();
	gStyle->SetOptStat(0);
	TH1F *ratioHist = (TH1F*)h1->Clone();
	      
	      
	ratioHist->Divide(h2); // ratioHist=with cut/ no cut
      
	ratioHist->GetYaxis()->SetRangeUser(0., 1.5);
	ratioHist->SetMarkerStyle(20);
	ratioHist->Draw();
	ratioHist->SetTitle("cut efficiency");
	TLine* horiz_line = new TLine(0.01,0.5,1.99,0.5);
	horiz_line->SetLineStyle(2);
	horiz_line->DrawLine(xstart,1.,xend,1.);
   
 
	c1->Print("plots_Wgamma_eff.pdf","pdf");

	p1->Clear();
	p2->Clear();
	  
	c1->cd();

	//f1->Close();
      }
    }
  }
  f1->Close();
   
  c1->Print("plots_Wgamma_eff.pdf]","pdf");
}
