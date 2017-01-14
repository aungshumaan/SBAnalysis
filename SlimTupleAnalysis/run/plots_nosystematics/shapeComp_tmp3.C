{
  ////shape comparison

  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_qcd, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_02, *h_WV_03_0, *h_ZV_0_0, *h_ZV_0_02 , *h_ZV_03_0 ;
  
  TCanvas *c2 = new TCanvas();
  
  
  c2->Print("plots_shape_withQCD.pdf[");
  
  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2.scaled.root"); //Sherpa
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.5.2.scaled.root"); //Powheg
  
  
  const int nFlav=4;TString flavName[nFlav]={"em","ep","mm","mp"};
  //const int nFlav=1;TString flavName[nFlav]={"em"};
            
  const int nCut=3;TString cutName[nCut]={"CR_Wjj","SR","CR_Top"};
  //const int nCut=1;TString cutName[nCut]={"CR_Wjj"};

  //const int nSamp=5;TString sampName[nSamp]={"Data","Wjets","Ttbar","Zjets","QCD"};
  const int nSamp=1;TString sampName[nSamp]={"Wjets"};
  
  const int nType=1;TString typeName[nType]={"MET_et"};
  //const int nType=8;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  

  //const int nType =5 ;TString typeName[nType] = { "Mwjj","fatjetM_pt150","fatjetM_pt200","fatjetM_pt250","fatjetM_pt300"};
  

      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      
      for (int isamp=0;isamp<nSamp;++isamp){
	for (int iflav=0;iflav<nFlav;++iflav){

	  bool logy=false;
	  // if ( typeName[itype].Contains("MET_et") || typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
	  // 	logy = true;
	  // }
      
	  h_sherpa=(TH1F*)f->Get(Form("H_%s_%s_WBF_%s_%s", sampName[isamp].Data(), flavName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));

	  h_powheg=(TH1F*)f1->Get(Form("H_%s_%s_WBF_%s_%s", sampName[isamp].Data(), flavName[iflav].Data(), cutName[icut].Data(),typeName[itype].Data()));

           
	  h_sherpa->SetLineColor(kBlack);
	  h_powheg->SetLineColor(kCyan);


  
	  
	  int rebin =1;
	  
	  if (!(typeName[itype].Contains("Njet"))){
	    //if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){
	    h_sherpa->Rebin(rebin);
	    h_powheg->Rebin(rebin);

	    
	  }
   
    
	
	  c2->SetLogy(logy);
	  	  
     
	  h_sherpa->SetMarkerStyle(20);
	  h_sherpa->SetMarkerSize(0.4);
   
	  h_sherpa->GetYaxis()->SetTitleOffset(0.7);
	  h_sherpa->GetYaxis()->CenterTitle();
	
 
	  h_sherpa-> GetXaxis()->SetTitle( "" );
	  h_sherpa->SetTitle(Form("%s_%s_%s_%s",sampName[isamp].Data(),flavName[iflav].Data(),cutName[icut].Data(), typeName[itype].Data()) );


	  

	  //cout<< h_sherpa->Integral(1,h_sherpa->GetNbinsX())<<endl;

	  h_sherpa->Scale(1/h_sherpa->Integral());
	  
	  //cout<< h_sherpa->GetBinContent(5)<<endl;
	  
         
	  double maxi=h_sherpa->GetBinContent(h_sherpa->GetMaximumBin());
	  //cout<<maxi<<endl;
	  double tmp=0.;
	  h_powheg->Scale(1/h_powheg->Integral());
	  //cout<< h_powheg->Integral()<<endl;
	  //cout<< h_powheg->GetBinContent(5)<<endl;
		  
	  tmp=h_powheg->GetBinContent(h_powheg->GetMaximumBin());
	  if(tmp>maxi)maxi=tmp;

	  //cout<<h_sherpa->GetNbinsX()<<endl;
	  int ibin =0;
	  double nSherpa(0.),nPow(0.);
	  for(ibin=0;ibin<=h_sherpa->GetNbinsX()+1;ibin++){
	    //cout<<"Sherpa bin["<<ibin<<"] ="<< h_sherpa->GetBinContent(ibin)<<endl;
	    nSherpa+=h_sherpa->GetBinContent(ibin);
	    //cout<<"Powheg bin["<<ibin<<"] ="<< h_powheg->GetBinContent(ibin)<<endl;
	    nPow+=h_powheg->GetBinContent(ibin);
	    //if(h_sherpa->GetBinContent(ibin)!=h_powheg->GetBinContent(ibin))cout<<"SCREAM!!!!!"<<endl;
	  }
	  //cout<<"nSherpa = "<<nSherpa<<" "<<"nPow = "<<nPow<<endl;

	  if(!logy){
	    //h_sherpa->SetMaximum(maxi*1.5);
	    h_sherpa->GetYaxis()->SetRangeUser(0,maxi*1.5);
	  }else{
	    h_sherpa->SetMaximum(maxi*500);
	    //h_sherpa->GetYaxis()->SetRangeUser(1,maxi*500);
	  }
	  //if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_sherpa->GetXaxis()->SetRangeUser(65,95);}
	  //if ( typeName[itype].Contains("Mwjj")) {h_sherpa->GetXaxis()->SetRangeUser(60,110);}
	  if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_sherpa->GetXaxis()->SetRangeUser(60,110);}
      
	  // h_WV_0_0->SetMaximum(maxi*1.5);
	  // h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
	  // /*


	  h_sherpa->Draw();
	  if (typeName[itype].Contains("MET_et"))h_sherpa-> GetXaxis()->SetRangeUser( 0,200 );
      

	  h_powheg->Draw("same ");


	  h_powheg->SetLineWidth(1);

	
  

	  // Double_t ks= h_MC->KolmogorovTest(h_sherpa);
	  // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
	  TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
	  leg->SetNColumns(2);

	  leg->AddEntry(h_sherpa,"Sherpa","p");
	  leg->AddEntry(h_powheg,"Powheg","l");


	  leg->Draw();
	
	
	  TLatex l;
	  l.SetTextSize(0.04); 
	  l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	  l.SetTextColor(1); //black
	  l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
	  double xstart=h_sherpa->GetBinLowEdge(1);
	  double xend=h_sherpa->GetBinLowEdge(h_sherpa->GetNbinsX()+1);
	  
	  gStyle->SetOptStat(0);

	  
      
      
      
	  c2->Print("plots_shape_withQCD.pdf");
         
	  c2->cd();
	}
      }
    }
  }
      
  f->Close();
  f1->Close();
  

  c2->Print("plots_shape_withQCD.pdf]");
}
