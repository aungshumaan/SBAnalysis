{
  

  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_iso_eff.pdf[","pdf");


  TFile *f1=TFile::Open("../hwwlvqq_isoStudy_nominal.root");
  TFile *f2=TFile::Open("../hwwlvqq_isoStudy_QCD.root"); //MET<25GeV

  // TFile *f1=TFile::Open("../hwwlvqq_isoStudy_ptIsoFloat_lvjj.root");
  // TFile *f2=TFile::Open("../hwwlvqq_isoStudy_QCD_ptIsoFloat_lvjj.root"); //MET<25GeV
   
  
  //const int nHist =1 ;TString histName[nHist]={"lepd0sigd0"};
  const int nHist =4 ;TString histName[nHist]={"lepz0sinth","lepd0sigd0","etIso","ptIso"};

  //const int nFlav =1 ;TString flavName[nFlav]={"m"}; //electron and muon
  const int nFlav =2 ;TString flavName[nFlav]={"e","m"}; //electron and muon

  for (int iHist=0;iHist<nHist;iHist++){  
    for (int iFlav=0;iFlav<nFlav;iFlav++){
    

      TH1F* h1=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) );
      h1->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) ));
      
    
      TH1F* h2=(TH1F*)f2->Get(Form("H_Data_%sm_WBF_PRESELECT_%s",  flavName[iFlav].Data(), histName[iHist].Data()) );
      h2->Add((TH1F*)f2->Get(Form("H_Data_%sp_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) ));
      
            

      //optimizing iso and impact parameter cuts

      TH1F *sig_eff = h1->Clone("sig_eff");
      TH1F *qcd_eff = h2->Clone("qcd_eff");

      double tot_sig = h1->Integral(1,h1->GetNbinsX());
      double tot_qcd = h2->Integral(1,h2->GetNbinsX());
  
      for(int ibin=1; ibin<=h1->GetNbinsX();ibin++){
      	double tmp_sig= h1->Integral(1,ibin);
	
	sig_eff->SetBinContent(ibin,tmp_sig/tot_sig);
      	double tmp_qcd= h2->Integral(1,ibin);
      	qcd_eff->SetBinContent(ibin,tmp_qcd/tot_qcd);
   
	//cout<<"sig: "<<histName[iHist].Data()<<"<"<< h1->GetXaxis()->GetBinLowEdge(ibin+1)<<" = "<<tmp_sig <<endl;
	//cout<<"QCD: "<<histName[iHist].Data()<<"<"<< h2->GetXaxis()->GetBinLowEdge(ibin+1)<<" = "<<tmp_qcd <<endl;
	//cout<<"QCD: "<<histName[iHist].Data()<<"<"<< h2->GetXaxis()->GetBinLowEdge(ibin+1)<<" = "<<tmp_qcd <<", total = " <<tot_qcd<<" efficiency e= "<<tmp_qcd/tot_qcd <<endl;
	  

   
      }
      
      sig_eff->SetLineColor(kBlue);
      
      sig_eff->SetTitle(Form("%s_%s", flavName[iFlav].Data(), histName[iHist].Data()) );

      sig_eff->Draw("hist");
    
     
   
      qcd_eff->SetLineColor(kRed);
    
      qcd_eff->Draw("same hist");
    
      double maxi= 0;
      if (sig_eff->GetBinContent(sig_eff->GetMaximumBin())>qcd_eff->GetBinContent(qcd_eff->GetMaximumBin())){
	maxi=sig_eff->GetBinContent(sig_eff->GetMaximumBin());
      }else{
	maxi=qcd_eff->GetBinContent(qcd_eff->GetMaximumBin());
      };
      sig_eff->SetMaximum(maxi*1.5);
     
      TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    

      l->AddEntry(sig_eff,"VBS signal efficiency","l");
      l->AddEntry(qcd_eff,"QCD efficiency","l");
      
    
     
      l->Draw();


   
 
      c1->Print("plots_iso_eff.pdf","pdf");
      
      //cout<<"----"<<endl;
      

    }
  }
  f1->Close();
  f2->Close();
   
  c1->Print("plots_iso_eff.pdf]","pdf");
}
