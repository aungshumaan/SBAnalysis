{
  ////shape comparison
  //bool doEl=true; //electron plots
  //bool doEl=false;//muon plots
  /*
  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}
  */
  
  TH1F *h_qcd200,*h_qcd400,*h_qcd600,*h_qcd800;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  
  TCanvas *c2 = new TCanvas();
  
  
  //c2->Print(Form("plots_shape_withQCD_%s.pdf[",lepName.Data() ));
  c2->Print("plots_shape_qcdfit.pdf[");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.8.1.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.5.scaled.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_signalOnly.root");
  
  
 
  //const int nCut=4;TString cutName[nCut]={"CR_WjjMJJ200","CR_WjjMJJ400","CR_WjjMJJ600","CR_WjjMJJ800"};
  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};

  const int nType=1;TString typeName[nType]={"MET_et"};
  //const int nType=14;TString typeName[nType]={"MET_et","mjjTagged","ptwlep","ptwjj","Mwjj","Mlvjj","vbfjet1_eta","cosThetaWDecay","cosThetaWlep", "bosonCentrality","lepCentrality","mTWV","VVvecptdiff","VVptBalance"};
  

  
  const  int nlep =2; TString lep[nlep] ={"e","m"};

      
  for (int itype=0;itype<nType;++itype){
    for (int ilep=0; ilep < nlep ; ++ilep){
      
      //THStack *hs = new THStack("hs","");
      
      bool logy=false;
      // if ( typeName[itype].Contains("MET_et") || typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
      // 	logy = true;
      // }
      
      h_qcd200=(TH1F*)f->Get(Form("H_QCD_%sm_WBF_CR_WjjMJJ200_%s",lep[ilep].Data(), typeName[itype].Data()));
      h_qcd200->Add((TH1F*)f->Get(Form("H_QCD_%sp_WBF_CR_WjjMJJ200_%s",lep[ilep].Data(), typeName[itype].Data())));
      h_qcd400=(TH1F*)f->Get(Form("H_QCD_%sm_WBF_CR_WjjMJJ400_%s",lep[ilep].Data(), typeName[itype].Data()));
      h_qcd400->Add((TH1F*)f->Get(Form("H_QCD_%sp_WBF_CR_WjjMJJ400_%s",lep[ilep].Data(), typeName[itype].Data())));
      h_qcd600=(TH1F*)f->Get(Form("H_QCD_%sm_WBF_CR_WjjMJJ600_%s",lep[ilep].Data(), typeName[itype].Data()));
      h_qcd600->Add((TH1F*)f->Get(Form("H_QCD_%sp_WBF_CR_WjjMJJ600_%s",lep[ilep].Data(), typeName[itype].Data())));
      h_qcd800=(TH1F*)f->Get(Form("H_QCD_%sm_WBF_CR_WjjMJJ800_%s",lep[ilep].Data(), typeName[itype].Data()));
      h_qcd800->Add((TH1F*)f->Get(Form("H_QCD_%sp_WBF_CR_WjjMJJ800_%s",lep[ilep].Data(), typeName[itype].Data())));

      ///h_qcd800=(TH1F*)f->Get(Form("H_QCD_em_WBF_CR_WjjMJJ800_%s", typeName[itype].Data()));
      ///h_qcd800->Add((TH1F*)f->Get(Form("H_QCD_ep_WBF_CR_WjjMJJ800_%s", typeName[itype].Data())));

	
      // h_WV_0_02=(TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sm_WBF_%s_%s",lep[ilep].Data(), typeName[itype].Data()));
      // h_WV_0_02->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_02_%sp_WBF_%s_%s",lep[ilep].Data(), typeName[itype].Data())));
	
      h_qcd200->SetLineColor(kBlack);
      h_qcd400->SetLineColor(kRed);
      h_qcd600->SetLineColor(kBlue);
      h_qcd800->SetLineColor(kGreen);

      double rebin = 2;
      //if (!(typeName[itype].Contains("Njet"))){
      if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	h_qcd200->Rebin(rebin);
	h_qcd400->Rebin(rebin);
	h_qcd600->Rebin(rebin);
	h_qcd800->Rebin(rebin);

      }
   

    
	
      c2->SetLogy(logy);
     
      h_qcd200->SetMarkerStyle(20);
      h_qcd200->SetMarkerSize(0.1);
   
      h_qcd200->GetYaxis()->SetTitleOffset(0.7);
      h_qcd200->GetYaxis()->CenterTitle();
	
 
      h_qcd200-> GetXaxis()->SetTitle( "" );
      h_qcd200->SetTitle(Form("%s_%s",lep[ilep].Data(), typeName[itype].Data()) );

      if (typeName[itype].Contains("MET_et"))h_qcd200-> GetXaxis()->SetRangeUser( 0,200 );

      h_qcd200->Scale(1/h_qcd200->Integral());
         
      double maxi=h_qcd200->GetBinContent(h_qcd200->GetMaximumBin());
      //cout<<maxi<<endl;
      double tmp=0.;
      h_qcd400->Scale(1/h_qcd400->Integral());
      tmp=h_qcd400->GetBinContent(h_qcd400->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_qcd600->Scale(1/h_qcd600->Integral());
      tmp=h_qcd600->GetBinContent(h_qcd600->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_qcd800->Scale(1/h_qcd800->Integral());
      tmp=h_qcd800->GetBinContent(h_qcd800->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;

      if(!logy){
      	//h_qcd200->SetMaximum(maxi*1.5);
      	h_qcd200->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
      	h_qcd200->SetMaximum(maxi*500);
      	//h_qcd200->GetYaxis()->SetRangeUser(1,maxi*500);
      }
      //if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_qcd200->GetXaxis()->SetRangeUser(65,95);}
      //if ( typeName[itype].Contains("Mwjj")) {h_qcd200->GetXaxis()->SetRangeUser(60,110);}
      if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_qcd200->GetXaxis()->SetRangeUser(60,110);}
      
      // h_WV_0_0->SetMaximum(maxi*1.5);
      // h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(), typeName[itype].Data()) );
      // /*


      h_qcd200->Draw("hist");

      h_qcd400->Draw("same hist");
      h_qcd600->Draw("same hist ");
      h_qcd800->Draw("same hist");


      h_qcd400->SetLineWidth(1);
      h_qcd600->SetLineWidth(1);
      h_qcd800->SetLineWidth(1);
  

      // Double_t ks= h_MC->KolmogorovTest(h_qcd200);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
      leg->SetNColumns(2);
      // /*
      leg->AddEntry(h_qcd200,"200<mjj<400","p");
      leg->AddEntry(h_qcd400,"400<mjj<600","l");
      leg->AddEntry(h_qcd600,"600<mjj<800","l");
      leg->AddEntry(h_qcd800,"mjj> 800","l");
            
      leg->Draw();
	
	
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
      double xstart=h_qcd200->GetBinLowEdge(1);
      double xend=h_qcd200->GetBinLowEdge(h_qcd200->GetNbinsX()+1);
	  
      gStyle->SetOptStat(0);

	  
      
      
      //c2->Print(Form("plots_shape_withQCD_%s.pdf",lepName.Data() ));
      c2->Print("plots_shape_qcdfit.pdf");
      
      c2->cd();
            
      
    }
  }
      
  f->Close();
  //f1->Close();
  
  //c2->Print(Form("plots_shape_withQCD_%s.pdf]",lepName.Data() ));
  c2->Print("plots_shape_qcdfit.pdf]");
}
