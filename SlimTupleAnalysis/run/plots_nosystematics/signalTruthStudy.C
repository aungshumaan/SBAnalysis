{
  ////modified from shapeCompWithQCD.C
  //bool doEl=true; //electron plots
  bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}
  
  
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  TH1F *h_WV_01_0, *h_WV_m01_0, *h_WV_005_0, *h_WV_m005_0, *h_WV_m03_0 ;
  
  TCanvas *c2 = new TCanvas();
  
  
  c2->Print(Form("plots_signalTruthStudy_%s.pdf[",lepName.Data() ));
  
  
  TFile *f1=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq.root");
  //TFile *f1=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.1_signalOnly.root");
  //TFile *f1=TFile::Open("~azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.1_signalOnly_noMETcorrection.root");
  
 
            
  const int nCut=1;TString cutName[nCut]={"SR"};
 
 
  //const int nHist =11 ;TString histName[nHist] = {"lep_pt","pt_trueLep","pt_lepTrueLep","MET_et","Et_trueNu", "Et_METtrueNu","dPhilepMET", "dPhilv_true","mT","mT_true" ,"mlv_true" };
  const int nHist =8 ;TString histName[nHist] = {"mT","mT_true","mT_dPhilepMET_lt14","mT_dPhilepMET_gt14" ,"mT_ptwlep_lt50","mT_ptwlep_50_100" ,"mT_ptwlep_100_150", "mT_ptwlep_gt150"};
  

      
  for (int ihist=0;ihist<nHist;++ihist){
    for (int icut=0;icut<nCut;++icut){
      

      bool logy=false;
      // if ( histName[ihist].Contains("MET_et") || histName[ihist].Contains("mjjTagged") || histName[ihist].Contains("ptwjj") || histName[ihist].Contains("vbfjet1_pt") || histName[ihist].Contains("vbfjet2_pt") ){
      // 	logy = true;
      // }
      
      

      h_WV_0_0=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_WV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));
	
      h_WV_0_02=(TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_WV_0_02->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));
	
      h_WV_03_0=(TH1F*)f1->Get(Form("H_VBS_WV_03_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_WV_03_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_03_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));
	
      h_ZV_0_0=(TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_ZV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));
	
      h_ZV_0_02=(TH1F*)f1->Get(Form("H_VBS_ZV_0_02_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_ZV_0_02->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_02_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));
	
      h_ZV_03_0=(TH1F*)f1->Get(Form("H_VBS_ZV_03_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_ZV_03_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_03_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));

      h_WV_01_0=(TH1F*)f1->Get(Form("H_VBS_WV_01_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_WV_01_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_01_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));

      h_WV_005_0=(TH1F*)f1->Get(Form("H_VBS_WV_005_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data()));
      h_WV_005_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_005_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),histName[ihist].Data())));      

      

      h_WV_0_0->SetLineColor(kRed);
   
      h_WV_0_02->SetLineColor(kOrange);
    
      h_WV_03_0->SetLineColor(kBlue-2);
   
      h_ZV_0_0->SetLineColor(kRed-2);
      
      h_ZV_0_02->SetLineColor(kViolet);
      
      h_ZV_03_0->SetLineColor(kAzure+6);

      h_WV_01_0->SetLineColor(kYellow);
      h_WV_005_0->SetLineColor(kGreen);

      if (!(histName[ihist].Contains("Njet")) && !(histName[ihist].Contains("Mwjj"))){


	// h_WV_0_0->Rebin(2);
	// h_WV_0_02->Rebin(2);
	// h_WV_03_0->Rebin(2);

	// h_ZV_0_0->Rebin(2);
	// h_ZV_0_02->Rebin(2);
	// h_ZV_03_0->Rebin(2);
      }
   

    
	
      c2->SetLogy(logy);
           
   
      
      double maxi=0;
      double tmp=0.;
      h_WV_0_0->Scale(1/h_WV_0_0->Integral());
      tmp=h_WV_0_0->GetBinContent(h_WV_0_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      //h_WV_0_02->Scale(1/h_WV_0_02->Integral());
      //tmp=h_WV_0_02->GetBinContent(h_WV_0_02->GetMaximumBin());
      //if(tmp>maxi)maxi=tmp;
      h_WV_03_0->Scale(1/h_WV_03_0->Integral());
      tmp=h_WV_03_0->GetBinContent(h_WV_03_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      /*h_ZV_0_0->Scale(1/h_ZV_0_0->Integral());
      tmp=h_ZV_0_0->GetBinContent(h_ZV_0_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_ZV_0_02->Scale(1/h_ZV_0_02->Integral());
      tmp=h_ZV_0_02->GetBinContent(h_ZV_0_02->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_ZV_03_0->Scale(1/h_ZV_03_0->Integral());
      tmp=h_ZV_03_0->GetBinContent(h_ZV_03_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      */
      h_WV_01_0->Scale(1/h_WV_01_0->Integral());
      tmp=h_WV_01_0->GetBinContent(h_WV_01_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;

      h_WV_005_0->Scale(1/h_WV_005_0->Integral());
      tmp=h_WV_005_0->GetBinContent(h_WV_005_0->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;

      
      if(!logy){
      
      	h_WV_0_0->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
      	h_WV_0_0->SetMaximum(maxi*500);
      
      }
      if ( histName[ihist].Contains("Mwjj") && cutName[icut]=="SR"){h_WV_0_0->GetXaxis()->SetRangeUser(65,95);}
      h_WV_0_0->SetMaximum(maxi*1.5);
      h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), histName[ihist].Data()) );

   
      
      h_WV_0_0->Draw();
      //h_WV_0_02->Draw("same");
      h_WV_03_0->Draw("same");

      // h_ZV_0_0->Draw("same");
      // h_ZV_0_02->Draw("same");
      // h_ZV_03_0->Draw("same");

      h_WV_01_0->Draw("same");
      h_WV_005_0->Draw("same");

      
      h_WV_0_0->SetLineWidth(3);
      //h_WV_0_02->SetLineWidth(3);
      h_WV_03_0->SetLineWidth(3);

      // h_ZV_0_0->SetLineWidth(2);
      // h_ZV_0_02->SetLineWidth(2);
      // h_ZV_03_0->SetLineWidth(2);

      h_WV_01_0->SetLineWidth(3);
      h_WV_005_0->SetLineWidth(3);
   
      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
    
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
      leg->SetNColumns(2);
   
      leg->AddEntry(h_WV_0_0,"WV(0,0)","l");
      //leg->AddEntry(h_WV_0_02,"WV(0,0.2)","l");
      leg->AddEntry(h_WV_005_0,"WV(0.05,0)","l");
      leg->AddEntry(h_WV_01_0,"WV(0.1,0)","l");
      leg->AddEntry(h_WV_03_0,"WV(0.3,0)","l");
      // leg->AddEntry(h_ZV_0_0,"ZV(0,0)","l");
      // leg->AddEntry(h_ZV_0_02,"ZV(0,0.2)","l");
      // leg->AddEntry(h_ZV_03_0,"ZV(0.3,0)","l");

      
      
      leg->Draw();
	
	
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
      double xstart=h_WV_0_0->GetBinLowEdge(1);
      double xend=h_WV_0_0->GetBinLowEdge(h_WV_0_0->GetNbinsX()+1);
	  
      gStyle->SetOptStat(0);

	  
      
      
      c2->Print(Form("plots_signalTruthStudy_%s.pdf",lepName.Data() ));
         
      c2->cd();
      
      // TH1F* h=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_lep_pt",lep.Data(), cutName[icut].Data()));
      // h->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_lep_pt",lep.Data(), cutName[icut].Data())));
      // h->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_pt_trueLep",lep.Data(), cutName[icut].Data())),-1);
      // h->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_pt_trueLep",lep.Data(), cutName[icut].Data())),-1);

      // TH1F* h2=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_MET_et",lep.Data(), cutName[icut].Data()));
      // h2->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_MET_et",lep.Data(), cutName[icut].Data())));
      // h2->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_Et_trueNu",lep.Data(), cutName[icut].Data())),-1);
      // h2->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_Et_trueNu",lep.Data(), cutName[icut].Data())),-1);

      // h->Draw();
      // h->SetTitle(Form("%s_%s_lep_pt",lepName.Data(),cutName[icut].Data()) );
      // c2->Print(Form("plots_signalTruthStudy_%s.pdf",lepName.Data() ));
      // h2->Draw();
      // h2->SetTitle(Form("%s_%s_MET_et",lepName.Data(),cutName[icut].Data()) );
      // c2->Print(Form("plots_signalTruthStudy_%s.pdf",lepName.Data() ));
            
    }
  }
  
      
  f1->Close();
  c2->Print(Form("plots_signalTruthStudy_%s.pdf]",lepName.Data() ));
}
