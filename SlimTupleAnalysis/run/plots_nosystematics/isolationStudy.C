{
  

  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_isoStudy_sigVqcd.pdf[","pdf");


  TFile *f1=TFile::Open("../hwwlvqq_isoStudy_nominal.root");
  TFile *f2=TFile::Open("../hwwlvqq_isoStudy_QCD.root"); //MET<25GeV
   


  //const int nHist =1 ;TString histName[nHist]={"etIso"};
  const int nHist =6 ;TString histName[nHist]={"lepEtCone30","lepPtCone30","lepz0sinth","lepd0sigd0","etIso","ptIso"};

  //const int nFlav =4 ;TString flavName[nFlav]={"em","ep","mm","mp"};
  const int nFlav =2 ;TString flavName[nFlav]={"e","m"}; //electron and muon
    
  for (int iHist=0;iHist<nHist;iHist++){  
    for (int iFlav=0;iFlav<nFlav;iFlav++){
      
      
      // TH1F* h1=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%s_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) );
    
      // TH1F* h2=(TH1F*)f2->Get(Form("H_Data_%s_WBF_PRESELECT_%s",  flavName[iFlav].Data(), histName[iHist].Data()) );

      TH1F* h1=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) );
      h1->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) ));
      
    
      TH1F* h2=(TH1F*)f2->Get(Form("H_Data_%sm_WBF_PRESELECT_%s",  flavName[iFlav].Data(), histName[iHist].Data()) );
      h2->Add((TH1F*)f2->Get(Form("H_Data_%sp_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) ));

      TH1F* h3=(TH1F*)f1->Get(Form("H_WZZZWg_%sm_WBF_PRESELECT_%s",  flavName[iFlav].Data(), histName[iHist].Data()) );
      h3->Add((TH1F*)f1->Get(Form("H_WZZZWg_%sp_WBF_PRESELECT_%s", flavName[iFlav].Data(),  histName[iHist].Data()) ));


        
      h1->SetLineColor(kBlue);
      h1->SetMarkerColor(kBlue);
      h1->SetMarkerStyle(20);
      h1->Scale(1/h1->Integral());
      h1->SetTitle(Form("%s_%s", flavName[iFlav].Data(), histName[iHist].Data()) );

      h1->Draw();
    
     
      h2->SetLineColor(kRed);
      h2->SetMarkerColor(kRed);
      h2->SetMarkerStyle(20);
      h2->Scale(1/h2->Integral());
      h2->Draw("same");

      h3->SetLineColor(kGreen);
      h3->SetMarkerColor(kGreen);
      h3->SetMarkerStyle(20);
      h3->Scale(1/h3->Integral());
      h3->Draw("same");
    
      double maxi= 0;
      
      if (h1->GetBinContent(h1->GetMaximumBin())>maxi){
	maxi=h1->GetBinContent(h1->GetMaximumBin());
      }
     
      if(h2->GetBinContent(h2->GetMaximumBin())>maxi){
	maxi=h2->GetBinContent(h2->GetMaximumBin());
      }
      if(h3->GetBinContent(h3->GetMaximumBin())>maxi){
	maxi=h3->GetBinContent(h3->GetMaximumBin());
      }
      h1->SetMaximum(maxi*1.5);
     
      TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
    

      l->AddEntry(h1,"VBS signal","l");
      l->AddEntry(h3,"WW","l");
      l->AddEntry(h2,"data with MET<25","l");
          

     
      l->Draw();


   
 
      c1->Print("plots_isoStudy_sigVqcd.pdf","pdf");


    }
  }
  f1->Close();
  f2->Close();
   
  c1->Print("plots_isoStudy_sigVqcd.pdf]","pdf");
}
