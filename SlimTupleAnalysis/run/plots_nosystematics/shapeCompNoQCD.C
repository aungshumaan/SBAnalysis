{
  ////shape comparison
  bool doEl=true; //electron plots
  //bool doEl=false;//muon plots

  TString lep, lepName;
  if (doEl){lep="e";lepName="electron";}
  else{lep="m";lepName="muon";}
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar, *h_MC;
  TH1F *h_WV_0_0, *h_WV_0_01, *h_WV_01_0, *h_ZV_0_0, *h_ZV_0_01 , *h_ZV_01_0 ;
  
  TCanvas *c2 = new TCanvas();
  
  
  //c2->Print(Form("plots_shape_noQCD_%s.pdf[",lepName.Data() ));
  bool pdfforNote = 0;
  if (!pdfforNote)c2->Print(Form("plots_shape_noQCD_%s.pdf[",lepName.Data() ));
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.4.2_variableBin.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.4.2_variableBin.root");
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_all81.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4_all81.root");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.2.lv8_smw_wp20.root"); //bad lepton with new isolation
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1_looseBadMuon1.1.lv8_smw_wp20.root"); //bad lepton without isolation

  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_jetpt40_cutflow.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_jetpt40_cutflow.root");

  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw_wp20_NEW.root");
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw_wp20_NEW.root");
            
  //const int nCut=2;TString cutName[nCut]={"CR_TopFJ","SRFJ"};
  //const int nCut=3;TString cutName[nCut]={"CR_Top","SR","CR_Wjj"};
  const int nCut=1;TString cutName[nCut]={"SR"};

  const int nType=1;TString typeName[nType]={"mTWV"};
  //const int nType=3;TString typeName[nType]={"vbfjet1_eta","Wjet1_eta","Wjet2_eta"};
  //const int nType=11;TString typeName[nType]={"ptwjj","ptwlep","Mlvjj","mTWV","VVptBalance","mjjTagged","dEtaTaggedJets", "bosonCentrality","lepCentrality","cosThetaWDecay","cosThetaWlep"};
  //const int nType=8;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et","Njet"};
  
  //const int nType =21 ;TString typeName[nType] = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  

  //const int nType =5 ;TString typeName[nType] = { "Mwjj","fatjetM_pt150","fatjetM_pt200","fatjetM_pt250","fatjetM_pt300"};
  

      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      
      //THStack *hs = new THStack("hs","");

      bool logy=false;
      if ( typeName[itype].Contains("MET_et") || typeName[itype].Contains("mjjTagged") || typeName[itype].Contains("ptwjj") || typeName[itype].Contains("vbfjet1_pt") || typeName[itype].Contains("vbfjet2_pt") ){
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
     
        /*

      h_WV_0_0=(TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	
      h_WV_0_01=(TH1F*)f1->Get(Form("H_VBS_WV_0_01_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_0_01->Add((TH1F*)f1->Get(Form("H_VBS_WV_0_01_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	
      h_WV_01_0=(TH1F*)f1->Get(Form("H_VBS_WV_01_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_WV_01_0->Add((TH1F*)f1->Get(Form("H_VBS_WV_01_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	
      h_ZV_0_0=(TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ZV_0_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	
      h_ZV_0_01=(TH1F*)f1->Get(Form("H_VBS_ZV_0_01_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ZV_0_01->Add((TH1F*)f1->Get(Form("H_VBS_ZV_0_01_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));
	
      h_ZV_01_0=(TH1F*)f1->Get(Form("H_VBS_ZV_01_0_%sm_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data()));
      h_ZV_01_0->Add((TH1F*)f1->Get(Form("H_VBS_ZV_01_0_%sp_WBF_%s_%s",lep.Data(), cutName[icut].Data(),typeName[itype].Data())));

        */

           
      h_data->SetLineColor(kBlack);
       h_Wjets->SetLineColor(kCyan);
       h_Zjets->SetLineColor(kBlue);
       h_diboson->SetLineColor(kMagenta+2);
       h_singleTop->SetLineColor(kYellow-5);
       h_ttbar->SetLineColor(kViolet);
       /*
      h_WV_0_0->SetLineColor(kRed);
      h_WV_0_01->SetLineColor(kOrange);
      h_WV_01_0->SetLineColor(kBlue-2);
      h_ZV_0_0->SetLineColor(kRed-2);
      h_ZV_0_01->SetLineColor(kViolet);
      h_ZV_01_0->SetLineColor(kAzure+6);
       */
      double rebin =1;
      
      if (!(typeName[itype].Contains("Njet"))){
	//if (!(typeName[itype].Contains("Njet") || typeName[itype].Contains("Mwjj") || typeName[itype].Contains("fatjetM_"))){

	 h_data->Rebin(rebin);
	 h_Wjets->Rebin(rebin);
	 h_Zjets->Rebin(rebin);
	 h_diboson->Rebin(rebin);
	 h_singleTop->Rebin(rebin);
	 h_ttbar->Rebin(rebin);

	 	 /*
	h_WV_0_0->Rebin(rebin);
	h_WV_0_01->Rebin(rebin);
	h_WV_01_0->Rebin(rebin);

	h_ZV_0_0->Rebin(rebin);
	h_ZV_0_01->Rebin(rebin);
	h_ZV_01_0->Rebin(rebin);
	 */
      }
   

    
	
      c2->SetLogy(logy);
     
      h_data->SetMarkerStyle(20);
      h_data->SetMarkerSize(1);
      
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
      
      h_Wjets->Scale(1/h_Wjets->Integral());
      tmp=h_Wjets->GetBinContent(h_Wjets->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      // h_Zjets->Scale(1/h_Zjets->Integral());
      // tmp=h_Zjets->GetBinContent(h_Zjets->GetMaximumBin());
      // if(tmp>maxi)maxi=tmp;
      // h_diboson->Scale(1/h_diboson->Integral());
      // tmp=h_diboson->GetBinContent(h_diboson->GetMaximumBin());
      // if(tmp>maxi)maxi=tmp;
      // h_singleTop->Scale(1/h_singleTop->Integral());
      // tmp=h_singleTop->GetBinContent(h_singleTop->GetMaximumBin());
      // if(tmp>maxi)maxi=tmp;
      h_ttbar->Scale(1/h_ttbar->Integral());
      tmp=h_ttbar->GetBinContent(h_ttbar->GetMaximumBin());
      if(tmp>maxi)maxi=tmp;
      
       /*
	
	h_WV_0_0->Scale(1/h_WV_0_0->Integral());
	
	tmp=h_WV_0_0->GetBinContent(h_WV_0_0->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	// h_WV_0_01->Scale(1/h_WV_0_01->Integral());
	// tmp=h_WV_0_01->GetBinContent(h_WV_0_01->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	h_WV_01_0->Scale(1/h_WV_01_0->Integral());
	tmp=h_WV_01_0->GetBinContent(h_WV_01_0->GetMaximumBin());
	if(tmp>maxi)maxi=tmp;
	// h_ZV_0_0->Scale(1/h_ZV_0_0->Integral());
	// tmp=h_ZV_0_0->GetBinContent(h_ZV_0_0->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	// h_ZV_0_01->Scale(1/h_ZV_0_01->Integral());
	// tmp=h_ZV_0_01->GetBinContent(h_ZV_0_01->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	// h_ZV_01_0->Scale(1/h_ZV_01_0->Integral());
	// tmp=h_ZV_01_0->GetBinContent(h_ZV_01_0->GetMaximumBin());
	// if(tmp>maxi)maxi=tmp;
	 */
      
      if(!logy){
	h_data->SetMaximum(maxi*1.5);
       	//h_data->GetYaxis()->SetRangeUser(0,maxi*1.5);
	//h_Wjets->GetYaxis()->SetRangeUser(0,maxi*1.5);
      }else{
	h_data->SetMaximum(maxi*500);
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
      //h_Wjets->Draw();
      h_Wjets->Draw("same");
      //h_Zjets->Draw("same");
      //h_diboson->Draw("same");
      //h_singleTop->Draw("same");
      h_ttbar->Draw("same");

       
      //h_WV_0_0->Draw("same");
       //  */
       // /*
       //h_WV_0_0->Draw();
       //h_WV_0_01->Draw("same");
      //h_WV_01_0->Draw("same");

      //h_ZV_0_0->Draw("same");
      //h_ZV_0_01->Draw("same");
      //h_ZV_01_0->Draw("same");
      // */


       h_Wjets->SetLineWidth(1);
       h_Zjets->SetLineWidth(1);
       h_diboson->SetLineWidth(1);
       h_singleTop->SetLineWidth(1);
       h_ttbar->SetLineWidth(1);

         /*
      h_WV_0_0->SetLineWidth(1);
      h_WV_0_01->SetLineWidth(1);
      h_WV_01_0->SetLineWidth(1);

      h_ZV_0_0->SetLineWidth(1);
      h_ZV_0_01->SetLineWidth(1);
      h_ZV_01_0->SetLineWidth(1);

        */
	
  

      // Double_t ks= h_MC->KolmogorovTest(h_data);
      // cout<<"KolmogorovTest result= "<<ks<<endl;

      
  
 
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	
      leg->SetNColumns(2);
      // /*
      leg->AddEntry(h_data,"Data","p");
      leg->AddEntry(h_Wjets,"W+jets","l");
      //leg->AddEntry(h_Zjets,"Z+jets","l");
      //leg->AddEntry(h_diboson,"Di-boson","l");
      //leg->AddEntry(h_singleTop,"single top","l");
      leg->AddEntry(h_ttbar,"ttbar","l");

      // */
      // /*
      //leg->AddEntry(h_WV_0_0,"WV(0,0)","l");
      //leg->AddEntry(h_WV_0_01,"WV(0,0.1)","l");
      //leg->AddEntry(h_WV_01_0,"WV(0.1,0)","l");
      //leg->AddEntry(h_ZV_0_0,"ZV(0,0)","l");
      //leg->AddEntry(h_ZV_0_01,"ZV(0,0.1)","l");
      //leg->AddEntry(h_ZV_01_0,"ZV(0.1,0)","l");
      //  */
      
      leg->Draw();
	
	
      TLatex l;
      l.SetTextSize(0.04); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black
      l.DrawLatex(0.20 , 0.82,"#int Ldt = 20.3 fb^{-1}");
      
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
  
  c2->Print(Form("plots_shape_noQCD_%s.pdf]",lepName.Data() ));
}
