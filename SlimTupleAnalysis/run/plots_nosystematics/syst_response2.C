{

  //Compares Up against Down type syst. Reads ratio...root files, so error bars will be correct on the ratio of syst to Nominal.
  
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
  //const int nsyst =26;
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"JERUp","NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};
  
  TString systname[nsyst]={"NP_Special1JESUp"}
  TString systdown[nsyst]={"NP_Special1JESDown"}
  
  //TString systname[nsyst] ={"NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp", "JMSUp", "ElecScaleUp","ElecResolutionUp", "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard","PunchThroughJESUp","NonClosure_AFIIJESUp"};
  //TString systdown[nsyst] ={"NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","NP_Special6JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown","FatJESDown", "JMSDown", "ElecScaleDown","ElecResolutionDown", "MUONSCALELOW", "ResoSoftTermsDown_ptHard", "ResoSoftTermsDownUp_ptHard","ScaleSoftTermsDown_ptHard","PunchThroughJESDown","NonClosure_AFIIJESDown"};
  
  

  TFile *fsyst [nsyst];
  TFile *fsystdown [nsyst];
  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F *ratioHist2[nsyst],*ratioHistdown2[nsyst];
  TH1F* hnom;

  for (int isyst=0;isyst<nsyst;isyst++){
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.4/ratio_%s.4.root",systname[isyst].Data()));
    //fsystdown[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.4/ratio_%s.4.root",systdown[isyst].Data()));


    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_bugfixed/ratio_%s.caf4.2_lv8_smw_wp20.root",systname[isyst].Data()));
    fsystdown[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_bugfixed/ratio_%s.caf4.2_lv8_smw_wp20.root",systdown[isyst].Data()));
  }
  
  
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_0_0"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_02","VBS_WV_03_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_ZV_0_0","VBS_WV_01_0"};
  const int nSample =3; TString sampleName[nSample] = {"Ttbar","Wjets","VBS_WV_0_0"};
  //const int nSample =1; TString sampleName[nSample] = {"Wjets"};
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_01_0"};

  //const int nRegion =1; TString regionName[nRegion] = {"SR"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  
  //const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nHist =1 ;TString histName[nHist]={"vbfjet1_pt"};
  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist =6 ;TString histName[nHist]={"vbfjet1_pt","ptwjj","ptwlep","Mlvjj","ptlvjj", "Mwjj"};
  //const int nHist =4 ;TString histName[nHist]={"mTWV","mjjTagged","ptwlep", "Mwjj"};

  //const int nHist =19 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  
  //const int nHist =21 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","jet1_pt","jet2_pt","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  //const int nHist =7;TString histName[nHist]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};



  for (int iHist=0;iHist<nHist;iHist++){
    for (int iRegion=0;iRegion<nRegion;iRegion++){	  
      for (int iSample=0;iSample<nSample;iSample++){
      	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	  
	  

	  for (int isyst=0;isyst<nsyst;isyst++){
	    hsyst[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hsystdown[isyst] =(TH1F*)fsystdown[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hnom =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    


	    ///rebin
	    /*
	    hsyst[isyst]->Rebin(4);
	    hsystdown[isyst]->Rebin(4);
	    hnom->Rebin(4);
	    */
	    
	    ///ratio calculated by the ratioError4.py macro &&&&
	    ///*
	    ratioHist2[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    ratioHistdown2[isyst] =(TH1F*)fsystdown[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    //*/
	    
	    //ratio calculated by Divide method in this macro
	     /*
	    ratioHist[isyst] = (TH1F*)hsyst[isyst]->Clone("ratioHist");
	    ratioHist[isyst] ->Divide(hnom);
	    //ratioHist[isyst] ->Divide(ratioHist2[isyst]); //&&&&
	    //ratioHistdown[isyst] = (TH1F*)hsystdown[isyst]->Clone("ratioHistdown");
	    //ratioHistdown[isyst] ->Divide(hnom);
	    //ratioHistdown[isyst] ->Divide(ratioHistdown2[isyst]); //&&&&
	    */

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
	    
	    if(histName[iHist]=="Mwjj"){ 
	      hsyst[isyst]->GetXaxis()->SetRangeUser(60, 120); //hard coded
	      ratioHist2[isyst]->GetXaxis()->SetRangeUser(60, 120);
	      ratioHistdown2[isyst]->GetXaxis()->SetRangeUser(60, 120);
	    }

	    hsyst[isyst]->SetLineColor(kBlue);
	    
	    hsyst[isyst]->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	    
	    hsyst[isyst]->Draw("e1");

	    hsystdown[isyst]->SetLineColor(kRed);
	    
	    hsystdown[isyst]->Draw("e1 same");
	    
	  
	    
	    hnom->SetLineColor(kBlack);
	    hnom->Draw("same");

	    //hsystdown[isyst]->SetLineColor(kRed);
	    //hsystdown[isyst]->Draw("same");
	    
	    if (DEBUG){
	      if (histName[iHist]=="Njet"){
		hsyst[isyst]->SetMinimum(0.);
		//hsyst[isyst]->Rebin(10);
		//hnom->Rebin(10);
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


	 


	    float xstart=hnom->GetBinLowEdge(1);
	    float xend=hnom->GetBinLowEdge(hnom->GetNbinsX()+1);
	    
	    p2->cd();
	    gStyle->SetOptStat(0);

	    /*
	    ratioHist[isyst]->Draw("hist][");
	    ratioHist[isyst]->SetLineWidth(3);
	    //ratioHist[isyst]->GetYaxis()->SetRangeUser(0., 2);
	    ratioHist[isyst]->GetYaxis()->SetRangeUser(0.7, 1.3);
	    //if(histName[iHist]=="Mwjj"){ratioHist[isyst]->GetXaxis()->SetRangeUser(60, 120);}
	    //ratioHist[isyst]->SetMarkerStyle(20);

	    ratioHist[isyst]->SetLineColor(kBlue);	    
	    ratioHist[isyst]->GetYaxis()->SetLabelSize(0.07);
	    ratioHist[isyst]->GetXaxis()->SetLabelSize(0.07);

	    //ratioHistdown[isyst]->Draw("hist][ same");
	    //ratioHistdown[isyst]->SetLineColor(kRed);
	    */
	    ///* ///// &&&&
	    //ratioHist2[isyst]->Draw("hist][ ");
	    ratioHist2[isyst]->Draw(" ");
	    ratioHist2[isyst]->SetLineColor(kBlue);
	    ratioHist2[isyst]->GetYaxis()->SetRangeUser(0.5, 1.5);
	    //ratioHistdown2[isyst]->Draw("hist][ same");
	    ratioHistdown2[isyst]->Draw("same");
	    ratioHistdown2[isyst]->SetLineColor(kRed);
	    //*/ /////
	    
	    TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	    horiz_line->SetLineStyle(2);
	    if(histName[iHist]=="Mwjj"){
	      horiz_line->DrawLine(40,1.0,120,1.0);   //hard coded
	    }else{
	      horiz_line->DrawLine(xstart,1.0,xend,1.0);
	    }
	    
	    c1->Print("plots_syst_response.pdf",  Form("Title:%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
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
