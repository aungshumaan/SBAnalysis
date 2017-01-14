{
  ////shape comparison of different flavors (positive and negative)

  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_WjetsEWK,*h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;

  TH1F *h_em,*h_ep,*h_mm,*h_mp;
  
  TCanvas *c2 = new TCanvas();
  
  
  c2->Print("plots_shape_withQCD.pdf[");
  
  
  
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4.root");
  
  //const int nFlav=4;TString flavName[nFlav]={"em","ep","mm","mp"};
  //const int nSamp=5;TString sampName[nSamp]={"Data","Wjets","Ttbar","Zjets","QCD"};
  const int nSamp=2;TString sampName[nSamp]={"Wjets","WjetsEWKSherpa"};
            
  //const int nCut=3;TString cutName[nCut]={"CR_Wjj","SR","CR_Top"};
  const int nCut=1;TString cutName[nCut]={"CR_Wjj"};

  const int nType=1;TString typeName[nType]={"MET_et"};
  //const int nType=5;TString typeName[nType]={"MET_et","lep_pt","lep_eta","lep_phi","ptwlep"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  

  //const int nType =5 ;TString typeName[nType] = { "Mwjj","fatjetM_pt150","fatjetM_pt200","fatjetM_pt250","fatjetM_pt300"};
  

      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      //for (int iflav=0;iflav<nFlav;++iflav){
      for (int isamp=0;isamp<nSamp;++isamp){
      
      //THStack *hs = new THStack("hs","");

      bool logy=false;
      // if ( typeName[itype].Contains("MET_et") || typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
      // 	logy = true;
      // }
      
      h_em=(TH1F*)f->Get(Form("H_%s_em_WBF_%s_%s",sampName[isamp].Data(), cutName[icut].Data(),typeName[itype].Data()));

      h_ep=(TH1F*)f->Get(Form("H_%s_ep_WBF_%s_%s",sampName[isamp].Data(), cutName[icut].Data(),typeName[itype].Data()));

      h_mm=(TH1F*)f->Get(Form("H_%s_mm_WBF_%s_%s",sampName[isamp].Data(), cutName[icut].Data(),typeName[itype].Data()));

      h_mp=(TH1F*)f->Get(Form("H_%s_mp_WBF_%s_%s",sampName[isamp].Data(), cutName[icut].Data(),typeName[itype].Data()));

   

      

	

           
      h_em->SetLineColor(kBlack);
      h_ep->SetLineColor(kCyan);
      h_mm->SetLineColor(kBlue);
      h_mp->SetLineColor(kRed);
   

      int rebin =1;

      if (!(typeName[itype].Contains("Njet"))){
	//if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	h_em->Rebin(rebin);
	h_ep->Rebin(rebin);
	h_mm->Rebin(rebin);
	h_mp->Rebin(rebin);

      }
   

      if ( typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("ptwlep") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
      	logy = true;
      }
      // cout<<logy<<endl;
      c2->SetLogy(logy);   
    
	
    
     
      h_mm->SetMarkerStyle(20);
      h_mm->SetMarkerSize(0.4);
   
      h_mm->GetYaxis()->SetTitleOffset(0.7);
      h_mm->GetYaxis()->CenterTitle();
	
 
      h_mm-> GetXaxis()->SetTitle( "" );
      h_mm->SetTitle(Form("%s_%s_%s",sampName[isamp].Data(),cutName[icut].Data(), typeName[itype].Data()) );

   

      h_em->Scale(1/h_em->Integral());
         
      double maxi=h_em->GetBinContent(h_em->GetMaximumBin());
      //cout<<maxi<<endl;
      double tmp=0.;
      h_ep->Scale(1/h_ep->Integral());
      tmp=h_ep->GetBinContent(h_ep->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_mm->Scale(1/h_mm->Integral());
      tmp=h_mm->GetBinContent(h_mm->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      h_mp->Scale(1/h_mp->Integral());
      tmp=h_mp->GetBinContent(h_mp->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
  
      if(!logy){
      	//h_em->SetMaximum(maxi*1.5);
      	//h_em->GetYaxis()->SetRangeUser(0,maxi*1.5);
	h_mm->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
      	//h_em->SetMaximum(maxi*500);
	h_mm->SetMaximum(maxi*500);
      	
      }
      //if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_em->GetXaxis()->SetRangeUser(65,95);}
      //if ( typeName[itype].Contains("Mwjj")) {h_em->GetXaxis()->SetRangeUser(60,110);}
      if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_mm->GetXaxis()->SetRangeUser(60,110);}
      
      // h_WV_0_0->SetMaximum(maxi*1.5);
      // h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      // /*


      //h_em->Draw("");
      if (typeName[itype].Contains("MET_et"))h_mm-> GetXaxis()->SetRangeUser( 0,200 );
      
      //h_ep->Draw("same ");
      
      //h_mm->Draw("same  ");
      h_mm->Draw();
      h_mp->Draw("same ");
  

      
      // */
      // h_WV_0_0->Draw("same");
      // h_WV_0_02->Draw("same");
      // h_WV_03_0->Draw("same");

      // h_ZV_0_0->Draw("same");
      // h_ZV_0_02->Draw("same");
      // h_ZV_03_0->Draw("same");



      //      h_em->SetLineWidth(1);
      h_ep->SetLineWidth(1);
      h_mm->SetLineWidth(1);
      h_mp->SetLineWidth(1);
  

  
   
	
  

      // Double_t ks= h_MC->KolmogorovTest(h_em);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
      leg->SetNColumns(2);
    
      //leg->AddEntry(h_em,"em","l");
      //leg->AddEntry(h_ep,"ep","l");
      leg->AddEntry(h_mm,"mm","l");
      leg->AddEntry(h_mp,"mp","l");
   
      
      leg->Draw();
	
	
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
      double xstart=h_em->GetBinLowEdge(1);
      double xend=h_em->GetBinLowEdge(h_em->GetNbinsX()+1);
	  
      gStyle->SetOptStat(0);

   
      
      
      
      c2->Print("plots_shape_withQCD.pdf");
         
      c2->cd();
	 }
    }
  }
      
  f->Close();
  //f1->Close();
  

  c2->Print("plots_shape_withQCD.pdf]");
}
