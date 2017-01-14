{
  ////Before and after reweighting comparison of ttbar sample     
  TH1F *h[50];
  TCanvas *c2 = new TCanvas();
  c2->Print("plots_reweight.pdf[","pdf");
  
  //TFile *f_beforeRW=TFile::Open("~azaman/haifeng2/reader/run/plots_nosystematics/bkgTemplate_afterRW.root");
  TFile *f_beforeRW=TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40.root");
  
            
  const int nCut=1;TString cutName[nCut]={"CR_Top"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","SR","CR_Wjj","BTAG"};
  const int nType=7;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et"};
  
      
      
      
  //TString flavorName[2]={"e","m"}; //electron and muon
  TString flavorName[2]={"em","ep"}; //electron and positron
  //TString flavorName[2]={"mm","mp"}; //muon and anti-muon
      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iflav=0;iflav<2;++iflav){//loops over flavor

	////electron vs muon
	//ttbar 
	//h[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Ttbar_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	//h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Ttbar_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())));

	//data-all bkg except ttbar
	// h[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Data_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Wjets_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Zjets_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_SingleTop_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_QCD_%sm_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);


	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Data_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())));
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Wjets_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Zjets_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_SingleTop_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	// h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_QCD_%sp_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);

	    
	//// electron vs positron or muon vs anti-muon
	// ttbar
	//h[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));

	//data-all bkg except ttbar 
	h[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
	h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);

      }
      float ratio_size = 0.35 ;
      TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
      p1->Draw();
      //p1->SetBottomMargin(0.00);
      //p1->SetRightMargin(0.12);
	  	  
      p2->Draw();
      //p2->SetTopMargin(0.00);
      //p2->SetBottomMargin(0.25);
      //p2->SetRightMargin(0.12);p1->Draw();

      p1->cd();
      h[0]->Scale(1/h[0]->Integral());
      h[0]->Draw();
      h[0]->SetLineColor(kBlue);
	  
      //h[0]->SetTitle(Form("ttbar_%s_%s",cutName[icut].Data(),typeName[itype].Data()));
      //h[0]->SetTitle(Form("data-bkg except ttbar: %s_%s",cutName[icut].Data(),typeName[itype].Data()));
      //h[0]->SetTitle(Form("%s vs %s: ttbar_%s_%s",flavorName[0].Data(),flavorName[1].Data(),cutName[icut].Data(),typeName[itype].Data()));
      h[0]->SetTitle(Form("%s vs %s: data-bkg except ttbar:  %s_%s",flavorName[0].Data(),flavorName[1].Data(),cutName[icut].Data(),typeName[itype].Data()));	  
      h[1]->Scale(1/h[1]->Integral());
      h[1]->Draw("same");
      h[1]->SetLineColor(kRed);
      
      double maxi= 0;
      if (h[0]->GetBinContent(h[0]->GetMaximumBin())>h[1]->GetBinContent(h[1]->GetMaximumBin())){
	maxi=h[0]->GetBinContent(h[0]->GetMaximumBin());
      }else{
	maxi=h[1]->GetBinContent(h[1]->GetMaximumBin());
      };
      h[0]->SetMaximum(maxi*1.2);

      TLegend* l=new TLegend(0.7,0.7,0.9,0.9);
      // l->AddEntry(h[0],"el","l");
      // l->AddEntry(h[1],"mu","l");
      l->AddEntry(h[0],flavorName[0],"l");
      l->AddEntry(h[1],flavorName[1],"l");
      l->Draw();
	  
      double xstart=h[0]->GetBinLowEdge(1);
      double xend=h[0]->GetBinLowEdge(h[0]->GetNbinsX()+1);
	  
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h[0]->Clone();
      ratioHist->Divide(h[1]);
      ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
      ratioHist->Draw();
      ratioHist->SetTitle("ratio");
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      horiz_line->DrawLine(xstart,1.0,xend,1.0);
	  
      //c2->Print("plots_vbsTruth.pdf","pdf");
      c2->Print("plots_reweight.pdf","pdf");
      p1->Clear();
      p2->Clear();
	  
      c2->cd();
    }
  }
      
  /*
    const int nFlav=4;TString flavorName[nFlav]={"em","ep","mm","mp"}; //data vs ttbar
    for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
    for (int iflav=0;iflav<nFlav;++iflav){
	    	    
    h[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
    h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
    h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
    h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
    h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);
    h[iflav]->Add((TH1F*)f_beforeRW->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data())),-1);

    h2[iflav]=(TH1F*)f_beforeRW->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	  
    float ratio_size = 0.35 ;
    TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
    TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
    p1->Draw();
    //p1->SetBottomMargin(0.00);
    //p1->SetRightMargin(0.12);
	    
    p2->Draw();
    //p2->SetTopMargin(0.00);
    //p2->SetBottomMargin(0.25);
    //p2->SetRightMargin(0.12);p1->Draw();
	    
    p1->cd();
    h[iflav]->Scale(1/h[iflav]->Integral());
    h[iflav]->Draw();
    h[iflav]->SetLineColor(kBlue);
    h[iflav]->SetTitle(Form("Data vs ttbar: %s_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
    h2[iflav]->Scale(1/h2[iflav]->Integral());
    h2[iflav]->Draw("same");
    h2[iflav]->SetLineColor(kRed);
    double maxi= std::max(h[iflav]->GetBinContent(h[iflav]->GetMaximumBin()),h2[iflav]->GetBinContent(h2[iflav]->GetMaximumBin()));
    h[iflav]->SetMaximum(maxi*1.2);
    TLegend* l=new TLegend(0.7,0.7,0.9,0.9);
    l->AddEntry(h[iflav],"Data-all bkg except ttbar","l");
    l->AddEntry(h2[iflav],"ttbar","l");
    l->Draw();
    //cout<<h[iflav]->GetNbinsX()<<endl;
    double xstart=h[iflav]->GetBinLowEdge(1);
    double xend=h[iflav]->GetBinLowEdge(h[iflav]->GetNbinsX()+1);
    //cout<<xstart<<" "<<xend<<endl;
    p2->cd();
    gStyle->SetOptStat(0);
    TH1F *ratioHist = (TH1F*)h[iflav]->Clone();
    ratioHist->Divide(h2[iflav]);
    ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
    ratioHist->Draw();
    ratioHist->SetTitle("ratio");
    TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
    horiz_line->SetLineStyle(2);
    horiz_line->DrawLine(xstart,1.0,xend,1.0);
	    	    
    c2->Print("plots_vbsTruth.pdf","pdf");
    p1->Clear();
    p2->Clear();
	    
    c2->cd();
    }
    }
    }
  */
  f_beforeRW->Close();
  c2->Print("plots_reweight.pdf]","pdf");
}
