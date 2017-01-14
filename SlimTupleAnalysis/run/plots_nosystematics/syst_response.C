{

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

  

  const int nsyst =1;
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};

  TString systname[nsyst]={"JMSUp"}




  TFile *fsyst [nsyst];
  TFile *fsyst2 [nsyst];
  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F *hFromRatio[nsyst];
  TH1F* hnom;

  for (int isyst=0;isyst<nsyst;isyst++){
    
    //fsyst2[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv7/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst [isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv7/ratio_%s.caf4.2.lv7.root",systname[isyst].Data()));

    //fsyst2[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4.4_smw/hwwlvqq.%s.root",systname[isyst].Data()));
    //fsyst2[isyst]=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw/hwwlvqq.Nominal.small.root");
    //fsyst [isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw/ratio_%s.caf4.2.lv8_smw.root",systname[isyst].Data()));

    //TEST
    fsyst2[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.test/hwwlvqq.%s.root",systname[isyst].Data()));
    fsyst [isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_%s.caf4.2_test.root",systname[isyst].Data()));
  }
  
  
  const int nSample =1; TString sampleName[nSample] = {"Wjets"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_02","VBS_WV_03_0"};
  //const int nSample =9; TString sampleName[nSample] = {"Ttbar","Wjets","WjetsEWKSherpa","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  
  //const int nSample =2; TString sampleName[nSample] = {"Wjets","Ttbar"};

  //const int nRegion =1; TString regionName[nRegion] = {"SR"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  
  //const int nFlavor =1; TString flavorName[nFlavor] = { "em"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "em","ep"};
  const int nFlavor =4; TString flavorName[nFlavor] = { "em","ep","mm","mp"};

  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist =6 ;TString histName[nHist]={"vbfjet1_pt","ptwjj","ptwlep","Mlvjj","ptlvjj", "Mwjj"};

  //const int nHist =19 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  
  //const int nHist =21 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","jet1_pt","jet2_pt","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  //const int nHist =7;TString histName[nHist]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};



  for (int iHist=0;iHist<nHist;iHist++){
    for (int iRegion=0;iRegion<nRegion;iRegion++){	  
      for (int iSample=0;iSample<nSample;iSample++){
      	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	  
	  

	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    hsyst[isyst] =(TH1F*)fsyst2[isyst]->Get(Form("H_%s_%s_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );


	    ///rebin
	    
	    hsyst[isyst]->Rebin(5);
	    
	    
	    
	    
	    ///ratio calculated by the ratioError4.py macro &&&&
	    ///*
	    //hFromRatio[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%s_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hFromRatio[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%s_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    
	    //*/
	    
	    //ratio calculated by Divide method in this macro
	    // /*
	    ratioHist[isyst] = (TH1F*)hFromRatio[isyst]->Clone("ratioHist");
	    ratioHist[isyst] ->Divide(hsyst[isyst]);
	    //ratioHist[isyst] ->Divide(hFromRatio[isyst]); //&&&&
	    //ratioHistdown[isyst] = (TH1F*)hsystdown[isyst]->Clone("ratioHistdown");
	    //ratioHistdown[isyst] ->Divide(hnom);
	    //ratioHistdown[isyst] ->Divide(ratioHistdown2[isyst]); //&&&&
	    //*/

	    TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	    TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	    p1->Draw();
	    p2->Draw();
	    p1->cd();
	    if(histName[iHist]=="Mlvjj" || histName[iHist]=="ptlvjj" || histName[iHist]=="ptwjj" || histName[iHist]=="ptwlep" ){
	      p1->SetLogy();
	    }

	    

	    hsyst[isyst]->SetLineColor(kBlue);
	    
	    hsyst[isyst]->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	    
	    hsyst[isyst]->Draw("e1");
	    
	  
	    
	    hFromRatio[isyst]->SetLineColor(kBlack);
	    hFromRatio[isyst]->Draw("same");

	    
	    
	    	    
	    /*
	    double maxi= 0;
	    if (hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin())>hFromRatio[isyst]->GetBinContent(hFromRatio[isyst]->GetMaximumBin())){
	      maxi=hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin());
	    }else{
	      maxi=hFromRatio[isyst]->GetBinContent(hFromRatio[isyst]->GetMaximumBin());
	    };
	    hsyst[isyst]->SetMaximum(maxi*1.5);
	    */
	    
	    TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	    l->AddEntry(hsyst[isyst],Form("from %s histo",systname[isyst].Data()),"l");
	    l->AddEntry(hFromRatio[isyst],"From ratio histo","l");
	   	    
	    l->Draw();


	 


	    float xstart=ratioHist[isyst]->GetBinLowEdge(1);
	    float xend=ratioHist[isyst]->GetBinLowEdge(ratioHist[isyst]->GetNbinsX()+1);
	    
	    p2->cd();
	    gStyle->SetOptStat(0);

	    
	    ///* ///// &&&&
	    ratioHist[isyst]->Draw("hist][ ");
	    ratioHist[isyst]->GetYaxis()->SetRangeUser(0.,2.);
	    //*/ /////
	    
	    TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	    horiz_line->SetLineStyle(2);
	    if(histName[iHist]=="Mwjj"){
	      horiz_line->DrawLine(40,1.0,120,1.0);   //hard coded
	    }else{
	      horiz_line->DrawLine(xstart,1.0,xend,1.0);
	    }
	    
	    c1->Print("plots_syst_response.pdf",Form("Title:%s", histName[iHist].Data()));
	    p1->Close();
	    p2->Close();
	    
	  }
	  
	   
	    

	}
      }
    }
  }
 
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]->Close();
    //fsyst2[isyst]->Close();
  }
  c1->Print("plots_syst_response.pdf]","pdf");
}
