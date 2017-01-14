{
  

  gStyle->SetOptStat(0);

  TH1F *h1, *h2;
    
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  
  c2->Print("plots_mTstudy.pdf[");
  
  //TFile *f1=TFile::Open("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
  TFile *f1=TFile::Open("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.1.2.root");
  //TFile *f1=TFile::Open("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.1.root");
   
  //const int nCut=1;TString cutName[nCut]={"SR"};
  const int nCut=6;TString cutName[nCut]={"PRESELECT","WJET","BTAG","CR_Top","CR_Wjj","SR"};

  //const int nReg=1;TString regName[nReg]={"Data"};
  const int nReg=6;TString regName[nReg]={"Data","Zjets","WZZZWg","SingleTop","Ttbar","Wjets"};
  
  const int nHist =8 ;TString histName[nHist] = {"lep_pt","mT","mT_dPhilepMET_lt14","mT_dPhilepMET_gt14" ,"mT_ptwlep_lt50","mT_ptwlep_50_100" ,"mT_ptwlep_100_150", "mT_ptwlep_gt150"};

  for (int ireg=0;ireg<nReg;ireg++){
    for (int ihist=0;ihist<nHist;ihist++){
  
    for (int icut=0;icut<nCut;icut++){
      
	h1=(TH1F*)f1->Get(Form("H_%s_em_WBF_%s_%s",regName[ireg].Data(),cutName[icut].Data(),histName[ihist].Data()));
      h1->Add( (TH1F*)f1->Get(Form("H_%s_ep_WBF_%s_%s",regName[ireg].Data(),cutName[icut].Data(),histName[ihist].Data())) );

      h2=(TH1F*)f1->Get(Form("H_%s_mm_WBF_%s_%s",regName[ireg].Data(),cutName[icut].Data(),histName[ihist].Data()));
      h2->Add( (TH1F*)f1->Get(Form("H_%s_mp_WBF_%s_%s",regName[ireg].Data(),cutName[icut].Data(),histName[ihist].Data())) );

      TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
      TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
      p1->Draw();
      p2->Draw();
      p1->cd();
  
      
      //shape
      
      h1->Scale(1/(h1->Integral()));
      h2->Scale(1/(h2->Integral()));
      
      //Set y-axis range
      double maxi= h1->GetBinContent(h1->GetMaximumBin());
      h1->SetMaximum(maxi*1.5);
      //set title
      //h1->SetTitle(  );
      
      //set line color
      h1->SetLineColor(kBlue);
      h2->SetLineColor(kRed);
      
      //set line width
      
      
      h1->Draw();
      h2->Draw("same");
      
      
      TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
      l->AddEntry(h1,"electron","l");
      l->AddEntry(h2,"muon","l");
      
      l->Draw();

      double xstart=h1->GetBinLowEdge(1);
      double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);
      
      p2->cd();
      gStyle->SetOptStat(0);
      TH1F *ratioHist = (TH1F*)h1->Clone();
      ratioHist->Divide(h2); //ratioHist =el/mu
      ratioHist->GetYaxis()->SetRangeUser(0.5, 5.);
      ratioHist->SetMarkerStyle(20);
      ratioHist->Draw();
      ratioHist->SetTitle("el/mu");
      TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
      horiz_line->SetLineStyle(2);
      horiz_line->DrawLine(xstart,1.0,xend,1.0);
   
      c2->Print("plots_mTstudy.pdf"); 
      
      
      p1->Clear();
      p2->Clear();
      
      c2->cd();


    }
  }
  }      
  
  f1->Close();
   
  c2->Print("plots_mTstudy.pdf]");
}
