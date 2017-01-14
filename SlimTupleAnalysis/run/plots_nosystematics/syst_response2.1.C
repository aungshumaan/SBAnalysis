{
  //Very similar to syst_response2.C. Compares Up against Down syst. Reads histograms from hwwlvqq files. So error bars will be wrong on the ratio of syst to Nominal. But often we are only interested in the ratio but not on the error on the ratio, and this macro does enough in that case.


#include <TLatex.h>
  bool DEBUG =false;
  
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_syst_response.pdf[","pdf");

  //double maxi= 0;

  const int nsyst =1;
  //const int nsyst =15;
  
  //TString systname[nsyst]={"NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};
  
  TString systname[nsyst]={"NP_Special1JESUp"}
  TString systdown[nsyst]={"NP_Special1JESDown"}


  TFile *fsyst [nsyst],*fsystdown [nsyst];
  
  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F* hnom;

  /*
  //TFile* fnom=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4/hwwlvqq.Nominal.small.4.root");
  
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4/hwwlvqq.%s.4.root",systname[isyst].Data()));
    fsystdown[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4/hwwlvqq.%s.4.root",systdown[isyst].Data()));
    
  }
  */
  /*
  TFile* fnom=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.Nominal.small.root");
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.%s.root",systname[isyst].Data()));
    fsystdown[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_bugfixed/hwwlvqq.%s.root",systdown[isyst].Data()));
  */
  
  TFile* fnom=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185726.Nominal.root");
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185726.NP_Special1JESUp.root");
    fsystdown[isyst]=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185726.NP_Special1JESDown.root");
    
  }


  
  const int nSample =1; TString sampleName[nSample] = {"VBS_WV_01_0"};
  //const int nSample =3; TString sampleName[nSample] = {"Wjets","Ttbar","VBS_WV_0_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  //const int nSample =1; TString sampleName[nSample] = {"Ttbar"};

  //const int nRegion =1; TString regionName[nRegion] = {"SR"};
  //const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  const int nRegion =1; TString regionName[nRegion] = {"LooseMjjTag"};
  
  const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nHist =1 ;TString histName[nHist]={"vbfjet1_pt"};
  const int nHist =1 ;TString histName[nHist]={"mjjTagged"};


  //const int nHist =19 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  //const int nHist =21 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","jet1_pt","jet2_pt","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}



  for (int iHist=0;iHist<nHist;iHist++){
    for (int iSample=0;iSample<nSample;iSample++){
      for (int iRegion=0;iRegion<nRegion;iRegion++){	  
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	  
	  

	  for (int isyst=0;isyst<nsyst;isyst++){
	    hsyst[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hsystdown[isyst] =(TH1F*)fsystdown[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hnom =(TH1F*)fnom->Get(Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    
	    ratioHist[isyst] = (TH1F*)hsyst[isyst]->Clone("ratioHist");
	    ratioHist[isyst] ->Divide(hnom); 
	    ratioHistdown[isyst] =(TH1F*)hsystdown[isyst]->Clone("ratioHistdown");
	    ratioHistdown[isyst] ->Divide(hnom); 

	    TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	    TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	    p1->Draw();
	    p2->Draw();
	    p1->cd();
	    if(histName[iHist]=="Mlvjj" || histName[iHist]=="ptlvjj" || histName[iHist]=="ptwjj" || histName[iHist]=="ptwlep" ){
	      p1->SetLogy();
	    }else{
	      //hsyst[isyst]->Rebin(10);
	      //hsystdown[isyst]->Rebin(10);
	      //hnom->Rebin(10);
	  
	    }

	    if(histName[iHist]=="Mwjj"){hsyst[isyst]->GetXaxis()->SetRangeUser(60, 120);}

	    hsyst[isyst]->SetLineColor(kBlue);
	    
	    hsyst[isyst]->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	    
	    hsyst[isyst]->Draw();
	    
	    hsystdown[isyst]->SetLineColor(kRed);
	    hsystdown[isyst]->Draw("same");
	    
	    hnom->SetLineColor(kBlack);
	    hnom->Draw("same");
	    if (DEBUG){
	      if (histName[iHist]=="Njet"){
		hsyst[isyst]->SetMinimum(0.);
		hsyst[isyst]->Rebin(10);
		hnom->Rebin(10);
	      }
	    }
	    
	  
	    double maxi= 0;
	    if (hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin())>hnom->GetBinContent(hnom->GetMaximumBin())){
	      maxi=hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin());
	    }else{
	      maxi=hnom->GetBinContent(hnom->GetMaximumBin());
	    };
	    hsyst[isyst]->SetMaximum(maxi*1.5);
	    
	    TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	    l->AddEntry(hsyst[isyst],Form("%s",systname[isyst].Data()),"l");
	    l->AddEntry(hsystdown[isyst],Form("%s",systdown[isyst].Data()),"l");
	    l->AddEntry(hnom,"Nominal","l");
	   	    
	    l->Draw();


	 


	    double xstart=hnom->GetBinLowEdge(1);
	    double xend=hnom->GetBinLowEdge(hnom->GetNbinsX()+1);
	    
	    p2->cd();
	    gStyle->SetOptStat(0);

	    

	    ratioHist[isyst]->Draw("hist][");
	    //ratioHist[isyst]->GetYaxis()->SetRangeUser(0., 2);
	    ratioHist[isyst]->GetYaxis()->SetRangeUser(0.5, 1.5);
	    if(histName[iHist]=="Mwjj"){ratioHist[isyst]->GetXaxis()->SetRangeUser(60, 120);}
	    //ratioHist[isyst]->SetMarkerStyle(20);

	    ratioHist[isyst]->SetLineColor(kBlue);	    
	    ratioHist[isyst]->GetYaxis()->SetLabelSize(0.07);
	    ratioHist[isyst]->GetXaxis()->SetLabelSize(0.07);

	    ratioHistdown[isyst]->Draw("hist][ same");
	    ratioHistdown[isyst]->SetLineColor(kRed);

	    

	    TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	    horiz_line->SetLineStyle(2);
	    horiz_line->DrawLine(xstart,1.0,xend,1.0);
	    
	    c1->Print("plots_syst_response.pdf",Form("Title:%s_%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data(),systname[isyst].Data()));
	    p1->Close();
	    p2->Close();
	    
	  }
	  
	   
	    

	}
      }
    }
  }

  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]->Close();
    fsystdown[isyst]->Close();
  }
  c1->Print("plots_syst_response.pdf]","pdf");
}
