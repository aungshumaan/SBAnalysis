{
  
  TH1F *h_data,*h_Wjets,*h_Zjets,*h_diboson,*h_singleTop, *h_ttbar,*h_QCD, *h_MC;
  TCanvas *c2 = new TCanvas();
  c2->Print("plots_dataMC.pdf[","pdf");
  
  
  
  TFile *f=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.root");
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.WjetsPow.root");
            
  const int nCut=1;TString cutName[nCut]={"CR_Top"};
  //const int nflav=1;TString flavorName[nflav]={"em"};
  //const int nType=1;TString typeName[nType]={"dEtaTaggedJets"};
  //const int nCut=3;TString cutName[nCut]={"CR_Top","CR_Wjj","SR"};
  //const int nCut=4;TString cutName[nCut]={"CR_Top","SR","CR_Wjj","BTAG"};
  //const int nType=7;TString typeName[nType]={"dEtaTaggedJets","dRTaggedJets","mjjTagged", "ptwjj","ptwlep","Mlvjj","MET_et"};

  const int nType =14 ;TString typeName[nType]={ "mjjTagged","ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dEtaTaggedJets", "vbfjet1_pt","vbfjet2_pt", "lep_pt","MET_et","mT","ptBalance","Njet"};
  

  const int nflav=1;
  //TString flavorName[nflav]={"e","m"}; //electron and muon
  TString flavorName[nflav]={"em"}; //electron and positron
  //TString flavorName[nflav]={"mm","mp"}; //muon and anti-muon
      
  for (int itype=0;itype<nType;++itype){
    for (int icut=0;icut<nCut;++icut){
      for (int iflav=0;iflav<nflav;++iflav){//loops over flavor


	TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;


	h_data=(TH1F*)f->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_Wjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_Zjets=(TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_diboson=(TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_singleTop=(TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_ttbar=(TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));
	h_QCD=(TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_%s",flavorName[iflav].Data(),cutName[icut].Data(),typeName[itype].Data()));

	h_data->SetLineColor(kBlack);
	// h_Wjets->SetFillColor(kCyan);
	// h_Zjets->SetFillColor(kBlue);
	// h_diboson->SetFillColor(kMagenta+2);
	// h_singleTop->SetFillColor(kYellow-5);
	// h_ttbar->SetFillColor(kYellow);

	

	h_data->SetMarkerStyle(20);
	h_data->SetMarkerSize(1);
	h_data->Draw();
	//h_data->Scale(1/h_data->Integral());
	h_data->SetMaximum(h_data->GetBinContent(h_data->GetMaximumBin())*1.5);

	
	h_MC=(TH1F*)h_Wjets->Clone();
	h_MC->Add((TH1F*)h_Zjets);
	h_MC->Add(h_diboson);
	h_MC->Add(h_singleTop);
	h_MC->Add(h_ttbar);
	h_MC->Add(h_QCD);
	h_MC->SetLineColor(kRed);
	//h_MC->Scale(1/h_MC->Integral());
	h_MC->Draw("same");

	Double_t ks= h_MC->KolmogorovTest(h_data);
	//cout<<"KolmogorovTest result= "<<ks<<endl;
	
      
      //float ratio_size = 0.35 ;
      // TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
      // TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
      // p1->Draw();
  
	  	  
      // p2->Draw();
  

      // p1->cd();
 
      gStyle->SetOptStat(0);
      TLegend* leg=new TLegend(0.7,0.7,0.9,0.9);
      leg->SetHeader(Form("KS= %f",ks));
      leg->AddEntry(h_data,"Data","l");
      // leg->AddEntry(h_Wjets,"W+jets","f");
      // leg->AddEntry(h_Zjets,"Z+jets","f");
      // leg->AddEntry(h_diboson,"Di-boson","f");
      // leg->AddEntry(h_singleTop,"single top","f");
      // leg->AddEntry(h_ttbar,"ttbar","f");
      leg->AddEntry(h_MC,"MC","l");
      leg->Draw();
	  
      //double xstart=h[0]->GetBinLowEdge(1);
      //double xend=h[0]->GetBinLowEdge(h[0]->GetNbinsX()+1);
	  
      // p2->cd();
      // gStyle->SetOptStat(0);
      // TH1F *ratioHist = (TH1F*)h->Clone();
      // ratioHist->Divide(h_MC);
      // ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
      // ratioHist->Draw();
      // ratioHist->SetTitle("ratio");
      // TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      // horiz_line->SetLineStyle(2);
      // horiz_line->DrawLine(xstart,1.0,xend,1.0);
	  
      //c2->Print("plots_vbsTruth.pdf","pdf");
      c2->Print("plots_dataMC.pdf","pdf");
      // p1->Clear();
      // p2->Clear();
	  
      //c2->cd();
      }
    }
  }
      
  f->Close();
  c2->Print("plots_dataMC.pdf]","pdf");
}
