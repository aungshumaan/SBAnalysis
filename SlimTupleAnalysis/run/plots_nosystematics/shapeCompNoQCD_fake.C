{
  ////shape comparison
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_MC;
  TH1F *h_data2,*h_Wjets2,*h_Zjets2,*h_diboson2,*h_singleTop2, *h_ttbar2;
  TH1F *h_WV_0_0, *h_WV_0_01, *h_WV_01_0, *h_ZV_0_0, *h_ZV_0_01 , *h_ZV_01_0 ;
  
  TCanvas *c2 = new TCanvas();
  
  
  //c2->Print(Form("plots_shape_noQCD_%s.pdf[",lepName.Data() ));
  bool pdfforNote = 0;
  if (!pdfforNote)c2->Print(Form("plots_shape_noQCD_%s.pdf[",lepName.Data() ));
  


  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.2.lv8_smw_wp20.root"); //bad lepton with new isolation
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1_looseBadMuon1.1.lv8_smw_wp20.root"); //bad lepton without isolation

  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};
  const int nCut=1;TString cutName[nCut]={"SR"};

  const int nType=1;TString typeName[nType]={"mTWV"};

  //const int nType=11;TString typeName[nType]={"ptwjj","ptwlep","Mlvjj","mTWV","VVptBalance","mjjTagged","dEtaTaggedJets", "bosonCentrality","lepCentrality","cosThetaWDecay","cosThetaWlep"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  


      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      
      //THStack *hs = new THStack("hs","");

      bool logy=false;
      if ( typeName[itype].Contains("MET_et") || typeName[itype].Contains("mTWV") || typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
	logy = true;
      }
      
       h_data=(TH1F*)f->Get(Form("H_Data_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_data->Add((TH1F*)f->Get(Form("H_Data_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_Wjets->Add((TH1F*)f->Get(Form("H_Wjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_Zjets->Add((TH1F*)f->Get(Form("H_Zjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_diboson->Add((TH1F*)f->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_singleTop->Add((TH1F*)f->Get(Form("H_SingleTop_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_ttbar->Add((TH1F*)f->Get(Form("H_Ttbar_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
     
        

       //h_WV_0_0=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       //h_WV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));

	
       //h_ZV_0_0=(TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       //h_ZV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	

       h_data2=(TH1F*)f1->Get(Form("H_Data_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_data2->Add((TH1F*)f1->Get(Form("H_Data_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_Wjets2=(TH1F*)f1->Get(Form("H_Wjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_Wjets2->Add((TH1F*)f1->Get(Form("H_Wjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_Zjets2=(TH1F*)f1->Get(Form("H_Zjets_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_Zjets2->Add((TH1F*)f1->Get(Form("H_Zjets_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_diboson2=(TH1F*)f1->Get(Form("H_WZZZWg_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_diboson2->Add((TH1F*)f1->Get(Form("H_WZZZWg_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_singleTop2=(TH1F*)f1->Get(Form("H_SingleTop_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_singleTop2->Add((TH1F*)f1->Get(Form("H_SingleTop_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       h_ttbar2=(TH1F*)f1->Get(Form("H_Ttbar_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
       h_ttbar2->Add((TH1F*)f1->Get(Form("H_Ttbar_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
       
       h_data->Add(h_Wjets,-1);
       h_data->Add(h_Zjets,-1);
       h_data->Add(h_diboson,-1);
       h_data->Add(h_singleTop,-1);
       h_data->Add(h_ttbar,-1);

       h_data2->Add(h_Wjets2,-1);
       h_data2->Add(h_Zjets2,-1);
       h_data2->Add(h_diboson2,-1);
       h_data2->Add(h_singleTop2,-1);
       h_data2->Add(h_ttbar2,-1);
       
       h_data->SetLineColor(kBlue);
       h_data2->SetLineColor(kRed);
      
       /*
      h_WV_0_0->SetLineColor(kRed);
      h_ZV_0_0->SetLineColor(kRed-2);

       */
      double rebin =2;
      
      if (!(typeName[itype].Contains("Njet"))){
	//if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){

	h_data->Rebin(rebin);
	h_data2->Rebin(rebin);


	 	 /*
	h_WV_0_0->Rebin(rebin);

	h_ZV_0_0->Rebin(rebin);

	 */
      }
   

    
	
      c2->SetLogy(logy);
     
      //h_data->SetMarkerStyle(20);
      //h_data->SetMarkerSize(1);
      
      h_data->GetYaxis()->SetTitleOffset(0.7);
      h_data->GetYaxis()->CenterTitle();
      
      
      //h_data-> GetXaxis()->SetTitle( "" );
      //h_data->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      h_data->SetTitle("");
      
      h_data->Scale(1/h_data->Integral());
      
      double maxi= 0.;
      double tmp=0.;
      
      maxi=h_data->GetBinContent(h_data->GetMaximumBin());
      //cout<<maxi<<endl;
      

      h_data2->Scale(1/h_data2->Integral());
      tmp=h_data2->GetBinContent(h_data2->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;

      
      if(!logy){
	h_data->SetMaximum(maxi*1.5);
       	//h_data->GetYaxis()->SetRangeUser(0,maxi*1.5);
	//h_Wjets->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
	h_data->SetMaximum(maxi*20);
	//h_Wjets->SetMaximum(maxi*500);
	//h_data->SetMinimum(1.e-2);
	//h_data->GetYaxis()->SetRangeUser(1,maxi*500);
      }
      //if ( typeName[itype].Contains("Mwjj") && cutName[icut]=="SR"){h_data->GetXaxis()->SetRangeUser(65,95);}
      //if ( typeName[itype].Contains("Mwjj")) {h_data->GetXaxis()->SetRangeUser(60,110);}
      if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_data->GetXaxis()->SetRangeUser(60,110);}
      
       /*
      if(!logy){
	h_WV_0_0->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
      	h_WV_0_0->SetMaximum(maxi*500);
      }
       */
      //if ( typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_") ) {h_WV_0_0->GetXaxis()->SetRangeUser(60,110);}
      
      
      // h_WV_0_0->SetMaximum(maxi*1.5);
      // h_WV_0_0->SetTitle(Form("%s_%s_%s",lepName.Data(),cutName[icut].Data(), typeName[itype].Data()) );
      // /*
      h_data->Draw();

      h_data2->Draw("same");


  

      // Double_t ks= h_data2->KolmogorovTest(h_data);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      //TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
      TLegend *leg = new TLegend(0.46, 0.70, 0.88, 0.88) ;
	
      //leg->SetNColumns(2);
      //leg->AddEntry(h_data,"With isolation","l");
      leg->AddEntry(h_data,"#Sigma E_{T}Cone30/p_{T} >0.04 and #\Sigma p_{T}Cone30/p_{T} <0.5","l");
      leg->AddEntry(h_data2,"No isolation","l");

      
      leg->Draw();
	
	
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
      l.DrawLatex(0.20 , 0.76,"#int Ldt = 20.3 fb^{-1}");
      
       double xstart=h_data->GetBinLowEdge(1);
       double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);

       //double xstart=h_WV_0_0->GetBinLowEdge(1);
       //double xend=h_WV_0_0->GetBinLowEdge(h_WV_0_0->GetNbinsX()+1);
	  
      gStyle->SetOptStat(0);

	  
      
      
      //c2->Print(Form("plots_shape_noQCD_%s.pdf",lepName.Data() ));
      if (!pdfforNote) {
	c2->Print(Form("plots_shape_noQCD_%s.pdf",lepName.Data() ));
      }else{
	c2->Print(Form("PDF_syst_band/plots_shape_noQCD_%s_%s_%s.pdf",lepName.Data(), cutName[icut].Data(), typeName[itype].Data() ));
      }
         
      c2->cd();
            
    }
  }
      
  f->Close();
  f1->Close();
  
  if (!pdfforNote)  c2->Print(Form("plots_shape_noQCD_%s.pdf]",lepName.Data() ));
}
