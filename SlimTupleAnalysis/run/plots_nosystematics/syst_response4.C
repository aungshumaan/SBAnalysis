{
  ///////////<<< If you are reading ratio  directly from file rather than calculate it from Nominal and systematics, please don't do rebinning or merging of channels. Because the ratio plots do not know about this from the nominal or systematic plots.
  ////Adding Overflow bin to last bin at his macro level also would not work. You need to do it while creating the ratio root file.

#include <TLatex.h>
#include "makerHelper.h" //for AddOverflowBinToLastBin and GetXaxisRange function
#include "rebin.h"
  bool debug =false;
  
  
  //TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  TCanvas *c1 = new TCanvas("c1", "c1",0,0,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_syst_response.pdf[","pdf");

  

 
  Int_t color_index[8] ={600,632,416,616,920,432,800,840};
  //enum EColor { kWhite =0,   kBlack =1,   kGray=920,
  //kRed   =632, kGreen =416, kBlue=600, kYellow=400, kMagenta=616, kCyan=432,
  //kOrange=800, kSpring=820, kTeal=840, kAzure =860, kViolet =880, kPink=900 };

  //const int nsyst =2;
  //TString systname[nsyst]={"FatJESUp","FatJPTRUp"};

  const int nsyst =4;
  TString systname[nsyst]={"FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"};
  

  //const int nsyst =8;
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp"};
  //TString systname[nsyst]={"HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systname[nsyst]={"ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard"};
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"JERUp","NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};
  


  TFile *fsyst [nsyst];

  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F *ratioHist2[nsyst],*ratioHistdown2[nsyst];
  TH1F* hnom;

  for (int isyst=0;isyst<nsyst;isyst++){
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv7/ratio_%s.caf4.2.lv7.root",systname[isyst].Data()));
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf3.lv7/ratio_%s.caf3.lv7.root",systname[isyst].Data()));
    
    
  }
  
  
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_0_0"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_02","VBS_WV_03_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  const int nSample =1; TString sampleName[nSample] = {"Wjets"};
  
  //const int nRegion =1; TString regionName[nRegion] = {"SRfatOnly"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  
  //const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  const int nFlavor =4; TString flavorName[nFlavor] = {"ep", "em","mp","mm"};

  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist =6 ;TString histName[nHist]={"vbfjet1_pt","ptwjj","ptwlep","Mlvjj","ptlvjj", "Mwjj"};

  //const int nHist =19 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}
  //const int nHist =21 ;TString histName[nHist] ={ "lep_pt","MET_et","ptwlep","jet1_pt","jet2_pt","vbfjet1_pt","vbfjet1_eta","vbfjet2_pt","vbfjet2_eta","Mlvjj","Mwjj","ptlvjj","ptwjj","etaX","etaY","mT","dEtaTaggedJets","mjjTagged","cosThetaWlep","cosThetaWDecay","ptBalance"}

  //const int nHist =7;TString histName[nHist]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};

  int rebin=1;
  int rebinFac =1;

  for (int iHist=0;iHist<nHist;iHist++){
    for (int iRegion=0;iRegion<nRegion;iRegion++){	  
      for (int iSample=0;iSample<nSample;iSample++){
      	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	  
	  if (( regionName[iRegion].Contains("fatOnly") || regionName[iRegion].Contains("FJ")) && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}

	  bool logy=false;
	  if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("Mlvjj") || histName[iHist].Contains("ptlvjj")|| histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") || histName[iHist].Contains("MET_et") || histName[iHist].Contains("lep_pt") || histName[iHist].Contains("mTWV")){
	    logy = true;
	  }
	  ///Get the histograms
	  // hnom =      (TH1F*)fsyst[0]->Get(Form("H_%s_%sp_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  // hnom ->Add( (TH1F*)fsyst[0]->Get(Form("H_%s_%sm_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ));

	  hnom =      (TH1F*)fsyst[0]->Get(Form("H_%s_%s_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  

	  //AddOverflowBinToLastBin(hnom);

	  rebin =1; rebinFac=1;

	  rebinFac = getRebinFactor(histName[iHist]);
	  rebin *=rebinFac;
	  //hnom->Rebin(rebin);
	  

	  for (int isyst=0;isyst<nsyst;isyst++){

	    // hsyst[isyst] =     (TH1F*)fsyst[isyst]->Get(Form("H_%s_%sp_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    // hsyst[isyst]->Add( (TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data() ) ) );

	    hsyst[isyst] =     (TH1F*)fsyst[isyst]->Get(Form("H_%s_%s_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    

	    //AddOverflowBinToLastBin(hsyst[isyst]);
	    //hsyst[isyst]->Rebin(rebin);
	    
	    hsyst[isyst]->SetLineColor(color_index[isyst]);

	
	    
	    ///ratio calculated by the ratioError4.py macro &&&&
	    // /*
	    // ratioHist2[isyst] =     (TH1F*)fsyst[isyst]->Get(Form("H_%s_%sp_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    // ratioHist2[isyst]->Add( (TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );
	    // ratioHist2[isyst]->Scale(0.5); //WRONG!!! Adding two channels, so divide by 2 to get the reasonable number, but this is not correct because the normalization is differnt for positive and negative channels.


	    ratioHist2[isyst] =     (TH1F*)fsyst[isyst]->Get(Form("H_%s_%s_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );

	    //AddOverflowBinToLastBin(ratioHist2[isyst]); //for ratio plots overflow bin cannot be added like this
	    //cout<<"rebin = "<<rebin<<endl;
	    //ratioHist2[isyst]->Rebin(rebin);ratioHist2[isyst]->Scale(1/double(rebin)); //WRONG!! you are merging histogram bins containing ratios instead of taking ratio of merged bins. Divide by the number of bins to get back the ratio of merged bins. But this is not correct if the bins we are merging have different bin contents. 

	    ratioHist2[isyst]->SetLineColor(color_index[isyst]);

	    // */
	    
	    //ratio calculated by Divide method in this macro
	    // /*
	    ratioHist[isyst] = (TH1F*)hsyst[isyst]->Clone("ratioHist");
	    ratioHist[isyst] ->Divide(hnom);
	    //ratioHist[isyst] ->Divide(ratioHist2[isyst]); //&&&&

	    ratioHist[isyst]->SetLineColor(color_index[isyst]-5);

	    // */
	  }
	  
	  float ratio_size = 0.35 ;
	  TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
	  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);
	  p1->Draw();
	  p1->SetBottomMargin(0.00);
	  p1->SetRightMargin(0.12);
	  p2->Draw();
	  p2->SetTopMargin(0.00);
	  p2->SetBottomMargin(0.31);
	  p2->SetRightMargin(0.12);
	  p1->cd();
	  p1->cd()->SetLogy(logy);


	  float xstart=hnom->GetBinLowEdge(1);
	  float xend=hnom->GetBinLowEdge(hnom->GetNbinsX()+1);
	  
	  //cout<<xstart<<","<<xend<<endl;
	  
	  hsyst[0]->SetTitle("");
	  hsyst[0]->Draw("e0 p");
	  GetXaxisRange(hsyst[0],xstart,xend);


	  hsyst[0]->GetXaxis()->SetRangeUser(xstart,xend);


	  hnom->SetMarkerStyle(20);
	  hnom->SetMarkerSize(1);
	  hnom->SetLineColor(kBlack);
	  hnom->SetLineWidth(2);
	  hnom->Draw("same e0 p0");
	  
	  for (int isyst=0;isyst<nsyst;isyst++){
	    	    
	    if(isyst==0){
	      //hsyst[isyst]->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	      //hsyst[isyst]->SetTitle("");
	      //hsyst[isyst]->Draw("e0 p");
	      //GetXaxisRange(hsyst[isyst],xstart,xend);

	      
	      //hsyst[isyst]->GetXaxis()->SetRangeUser(xstart,xend);
	      

	    }else{
	      hsyst[isyst]->Draw("same e0 p0");
	    }
	    
	  }

	  //cout<<"After GetXaxisRange: "<<xstart<<","<<xend<<endl;

	  /*
	  hnom->SetMarkerStyle(20);
	  hnom->SetMarkerSize(1);
	  hnom->SetLineColor(kBlack);
	  hnom->SetLineWidth(2);
	  hnom->Draw("same e0 p");
	  */

	  double maxi= 0;
	  for (int isyst=0;isyst<nsyst;isyst++){
	    if (hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin())>maxi){
	      maxi=hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin());
	    }
	  }
	  hsyst[0]->SetMaximum(maxi*1.5);
	  if (logy)
	    {
	      hsyst[0]->SetMaximum(maxi*200.);
	      hsyst[0]->SetMinimum(1.e-2);
	    }


	  hsyst[0]->SetTitle("");
	  hsyst[0]-> GetYaxis()->SetTitle( Form( "Entries / %.1f", hsyst[0]->GetBinWidth(1)  )  );
	  
	 
	  //TLegend *leg=new TLegend(0.7,0.7,0.9,0.9);
	  TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
	  leg->SetNColumns(2);
	  for (int isyst=0;isyst<nsyst;isyst++){
	    leg->AddEntry(hsyst[isyst],Form("%s",systname[isyst].Data()),"l");
	  }
	  leg->AddEntry(hnom,"Nominal","p");
	  
	  leg->Draw();
	  
	  
	  TLatex l;
	  l.SetTextSize(0.055); 
	  l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	  l.SetTextColor(1); //black
	  l.DrawLatex(0.20 , 0.84,"ATLAS #bf{Internal}");
	  l.DrawLatex(0.20 , 0.72,"#int Ldt = 20.3 fb^{-1}");

	  TString latexFlav("");
	  if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
	  else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
	  else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
	  else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
	  //if (flavorName[iFlavor] == "e") { latexFlav = "e";}
	  //else if (flavorName[iFlavor] == "m") {  latexFlav = "#mu";}
	  
	  l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow %s#nu , %s, %s}", latexFlav.Data(), regionName[iRegion].Data(), sampleName[iSample].Data()) );
	  
	  
	  

	    
	  p2->cd();
	  gStyle->SetOptStat(0);

	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    if(isyst==0){
	      //ratioHist2[isyst]->Draw("hist][");
	      ratioHist2[isyst]->Draw("e0 p0");
	      
	      
	      ratioHist2[isyst]->SetTitle("");
	      ratioHist2[isyst]->GetYaxis()->SetTitle("Systematic/Nominal");
	      ratioHist2[isyst]->GetYaxis()->SetLabelSize(0.1);
	      ratioHist2[isyst]->GetYaxis()->SetTitleSize(0.08);
	      ratioHist2[isyst]->GetYaxis()->SetTitleOffset(0.5);
	      ratioHist2[isyst]->GetYaxis()->CenterTitle();
	      ratioHist2[isyst]->GetXaxis()->SetTitle(histName[iHist]);
	      //cout<< hnom->GetXaxis()->GetTitle() <<endl;
	      ratioHist2[isyst]->GetXaxis()->SetLabelSize(0.1);
	      ratioHist2[isyst]->GetXaxis()->SetTitleSize(0.15); 
	      
	      
	      ratioHist2[isyst]->GetYaxis()->SetRangeUser(0.6, 2.);
	      //ratioHist2[isyst]->GetYaxis()->SetRangeUser(-1., 3);
	      ratioHist2[isyst]->GetXaxis()->SetRangeUser(xstart, xend);

	      //ratioHist[isyst]->Draw("hist][ same");
	      //ratioHist[isyst]->Draw("hist][");

	      //ratioHist[isyst]->Draw("ep same");
	      //ratioHist[isyst]->Draw("e0 p");
	      

	      //ratioHist[isyst]->SetLineColor(kRed);
	      
	    }else{
	      //ratioHist2[isyst]->Draw("hist][ same");
	      ratioHist2[isyst]->Draw("e0 p0  same");
	      
	    }
	    
	  }
	    
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);
	  
	  //c1->Print("plots_syst_response.pdf",Form("Title:%s", histName[iHist].Data()));
	  c1->Print("plots_syst_response.pdf",Form("Title:%s_%s_%s_%s",sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  //sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()
	  p1->Close();
	  p2->Close();
	  
	  
	}
      }
    }
  }
 
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]->Close();

  }
  c1->Print("plots_syst_response.pdf]","pdf");
}
