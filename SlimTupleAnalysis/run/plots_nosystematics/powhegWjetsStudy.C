{
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
  c1->Print("plots_powhegWjets.pdf[");
  
  
  TFile *f1 = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsPow.root");

  
  const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","SR"};
  const int nFlavor =2; TString flavorName[nFlavor] = {"e","m"};
  const int nHist =5; TString histName[nHist] = {"ptwlep","ptwjj","Mwjj","mjjTagged","Mlvjj"};

  for (int iHist=0;iHist<nHist;iHist++){
    for (int iRegion=0;iRegion<nRegion;iRegion++){
      for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
      
	c1->SetLogy(1);
 
  
     
	TH1F *h_alp= (TH1F*)f1->Get(Form("H_WjetsPow_%sp_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data()));
	h_alp->Add( (TH1F*)f1->Get(Form("H_WjetsPow_%sm_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data())) );
    
	TH1F *h= (TH1F*)f1->Get(Form("H_Wjets_%sp_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data()));
	h->Add( (TH1F*)f1->Get(Form("H_Wjets_%sm_WBF_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data())));
 
  
 
	// h->Scale(1/h->Integral());

	h->Draw();
 
	double maxi=h->GetBinContent(h->GetMaximumBin());
	//h->SetMaximum(1.5* maxi);
	h->SetMaximum(100* maxi);
	h->SetTitle(Form("%s_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data()) );
      
	h->SetLineColor(kRed);
	h_alp->Draw("same");
	h_alp->SetLineColor(kBlack);
  

	TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	l->AddEntry(h,"Sherpa","l");
 
	l->AddEntry(h_alp,"Powheg","l");
  
	l->Draw();

	c1->Print("plots_powhegWjets.pdf");
	c1->SetLogy(1);

	TH1F *h_err= (TH1F*) h->Clone("h_err");
 

	TH1F *h_alp_err= (TH1F*) h_alp->Clone("h_alp_err");
  

	for(int i=1;i<h->GetNbinsX();i++){
	  h_err->SetBinContent(i,h->GetBinError(i));
	  h_alp_err->SetBinContent(i,h_alp->GetBinError(i));
	}

	double maxi=h_err->GetBinContent(h_err->GetMaximumBin());
	double tmp =h_alp_err->GetBinContent(h_alp_err->GetMaximumBin());
	if(tmp>maxi){maxi=tmp;}
 

	h_err->Draw("hist");
	h_err->SetMaximum(100* maxi);
	h_err->SetTitle(Form("StatError %s_%s_%s",flavorName[iFlavor].Data(),regionName[iRegion].Data(),histName[iHist].Data(),histName[iHist].Data()));
      
	h_err->SetLineColor(kRed);



	h_alp_err->Draw("hist same");
	h_alp_err->SetLineColor(kBlack);

	TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	l->AddEntry(h_err,"Sherpa","l");
 
	l->AddEntry(h_alp_err,"Powheg","l");

  
	l->Draw();

	c1->Print("plots_powhegWjets.pdf");
      }
    }
  }
  c1->Print("plots_powhegWjets.pdf]");

}
