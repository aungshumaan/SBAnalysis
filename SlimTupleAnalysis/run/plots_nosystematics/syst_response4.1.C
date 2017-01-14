{

  //reads ratio...root files, so error bars will be correct on the ratio of syst to Nominal. plots only systematic/Nominal ratio
  
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
  //c1->Print("plots_syst_response.pdf[","pdf");

  

  
  
  Int_t color_index[8] ={600,632,416,616,432,800,1,920};
  //enum EColor { kWhite =0,   kBlack =1,   kGray=920,
  //kRed   =632, kGreen =416, kBlue=600, kYellow=400, kMagenta=616, kCyan=432,
  //kOrange=800, kSpring=820, kTeal=840, kAzure =860, kViolet =880, kPink=900 };

  const int nsyst =8;
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp"};
  TString systname[nsyst]={"HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systname[nsyst]={"ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard"};
  //const int nsyst =4;
  //TString systname[nsyst]={"FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"}
  //TString systname[nsyst]={"FatJESUp"}
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"JERUp","NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};
  


  TFile *fsyst [nsyst];

  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F *ratioHist2[nsyst],*ratioHistdown2[nsyst];
  TH1F* hnom;

  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.OLD/RATIO.caf4.2.lv4/ratio_%s.caf4.2.lv4.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf3.lv7/ratio_%s.caf3.lv7.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv4_fatwindow40_140_mjjTag0/ratio_%s.caf4.2.lv4_fatwindow40_140_mjjTag0.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_NEW/ratio_%s.caf4.2_lv8_smw_wp20_NEW.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_NEW/ratio_%s.caf4.2_lv8_smw_wp20.root",systname[isyst].Data()));

    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_%s.caf4.2.lv4_fatwindow40_140_mjjTag0.root",systname[isyst].Data()));
    
  }
  
  
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_0_0"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_02","VBS_WV_03_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  const int nSample =1; TString sampleName[nSample] = {"Wjets"};

  //const int nRegion =1; TString regionName[nRegion] = {"SRfatOnly"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  
  //const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  //const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nFlavor =1; TString flavorName[nFlavor] = { "ep"};
  const int nFlavor =4; TString flavorName[nFlavor] = { "ep","em","mp","mm"};

  const int nHist =1 ;TString histName[nHist]={"mTWV"};
  //const int nHist = 3 ;TString histName[nHist]={"mTWV","fatjet_pt","fatjet_eta"};
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



	  rebin =1; rebinFac=1;

	  rebinFac = getRebinFactor(histName[iHist]);
	  rebin *=rebinFac;
	
	  
	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    ///ratio calculated by the ratioError4.py macro &&&&
	    ///*
	    ratioHist2[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%s_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	  
	    //////AddOverflowBinToLastBin(ratioHist2[isyst]); //for ratio plots overflow bin cannot be added like this
	    //cout<<"rebin = "<<rebin<<endl;
	    //ratioHist2[isyst]->Rebin(rebin);ratioHist2[isyst]->Scale(1/double(rebin)); //WRONG!! you are merging histogram bins containing ratios instead of taking ratio of merged bins. Dividing by the number of bins to get back the ratio of merged bins will not work because the bins did not have same number of events to start with.
	  
	    ratioHist2[isyst]->SetLineColor(color_index[isyst]);
	  
	  
	  }
	  

	  
	  //range of y-axis
	  double maxi(1.), mini(100), absmaxi (0);
	  for (int isyst=0;isyst<nsyst;isyst++){
	    if (ratioHist2[isyst]->GetBinContent(ratioHist2[isyst]->GetMaximumBin())>maxi){
	      maxi=ratioHist2[isyst]->GetBinContent(ratioHist2[isyst]->GetMaximumBin());
	    }
	  }
	  for (int isyst=0;isyst<nsyst;isyst++){
	    //cout<<"mini= "<<ratioHist2[isyst]->GetBinContent(ratioHist2[isyst]->GetMinimumBin())<<endl;
	    if (ratioHist2[isyst]->GetBinContent(ratioHist2[isyst]->GetMinimumBin())<mini){
	      mini=ratioHist2[isyst]->GetBinContent(ratioHist2[isyst]->GetMinimumBin());
	    }
	  }
	  absmaxi =maxi-1.; //greatest deviation from 1.
	  if ( (absmaxi )< fabs(1.-mini)) {absmaxi =  fabs(1.-mini);}

	  //cout<<"maxi-1 = "<<maxi-1.<<", 1-mini= "<<1.-mini<<",
	  //cout<<"absmaxi = "<<absmaxi<<endl;
	   
	  
	  
	  
	  

	  float xstart=ratioHist2[0]->GetBinLowEdge(1);
	  float xend=ratioHist2[0]->GetBinLowEdge(ratioHist2[0]->GetNbinsX()+1);

	  GetXaxisRange(ratioHist2[0] , xstart, xend);

	  //ratioHist2[0]->Draw("hist][");
	  ratioHist2[0]->Draw("e0 p");
	      
	      
	  ratioHist2[0]->SetTitle("");
	  ratioHist2[0]->GetYaxis()->SetTitle("Systematics/Nominal");
	  ratioHist2[0]->GetYaxis()->SetLabelSize(0.05);
	  ratioHist2[0]->GetYaxis()->SetTitleSize(0.04);
	  ratioHist2[0]->GetYaxis()->SetTitleOffset(1.2);
	  //ratioHist2[0]->GetYaxis()->CenterTitle();
	  ratioHist2[0]->GetXaxis()->SetTitle(histName[iHist]);
	  //cout<< hnom->GetXaxis()->GetTitle() <<endl;
	  ratioHist2[0]->GetXaxis()->SetLabelSize(0.05);
	  ratioHist2[0]->GetXaxis()->SetTitleSize(0.05); 
	  
	  
	  //ratioHist2[0]->GetYaxis()->SetRangeUser(0.4, 2);
	  ratioHist2[0]->GetYaxis()->SetRangeUser(0., 3);
	  ////ratioHist2[0]->GetYaxis()->SetRangeUser(0.8*(1-absmaxi),1.5*(1+absmaxi));
	  //ratioHist2[0]->GetYaxis()->SetRangeUser(1- 1.1*absmaxi, 1+ 2* absmaxi );
	  ratioHist2[0]->GetXaxis()->SetRangeUser(xstart, xend);
	  
	  //cout<<xstart<<","<<xend<<endl;
	  //gStyle->SetOptStat(0);

	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    if(isyst==0){

	      
	    }else{
	      //ratioHist2[isyst]->Draw("hist][ same");
	      ratioHist2[isyst]->Draw("e0 p same");
	    }
	    
	  }
	    
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);

	  
	  TLegend *leg = new TLegend(0.4, 0.70, 0.89, 0.89) ;
	  leg->SetTextSize(0.02);
	  leg->SetNColumns(2);
	  for (int isyst=0;isyst<nsyst;isyst++){
	    leg->AddEntry(ratioHist2[isyst],Form("%s",systname[isyst].Data()),"l");
	  }
	  
	  
	  leg->Draw();
	  
	  
	  TLatex l;
	  l.SetTextSize(0.03); 
	  l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
	  l.SetTextColor(1); //black
	  //l.DrawLatex(0.15 , 0.85,"ATLAS #bf{Internal}");
	  l.DrawLatex(0.15 , 0.85,"ATLAS #bf{Preliminary}");
	  l.DrawLatex(0.15 , 0.80,"#int Ldt = 20.2 fb^{-1}");

	  TString latexFlav("");
	  TString latexSamp("");
	  if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
	  else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
	  else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
	  else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
	  //if (flavorName[iFlavor] == "e") { latexFlav = "e";}
	  //else if (flavorName[iFlavor] == "m") {  latexFlav = "#mu";}
	  
	  if (sampleName[iSample] == "Ttbar"){  latexSamp = "#it{t#bar{t}}";}
	  else if (sampleName[iSample] == "Wjets"){  latexSamp = "W+jets";}
	  else if (sampleName[iSample] == "Zjets"){  latexSamp = "Z+jets";}
	  else if (sampleName[iSample] == "SingleTop"){  latexSamp = "Single top";}
	  else if (sampleName[iSample] == "WZZZWg"){  latexSamp = "Di-boson";}
	  else if (sampleName[iSample] == "VBS_WV_0_0"){  latexSamp = "SM signal";}
	  else if (sampleName[iSample] == "VBS_WV_0_03"){  latexSamp = "WV(0,0.3)";}//"VBS_WV_0_03","VBS_WV_03_0"
	  else if (sampleName[iSample] == "VBS_WV_03_0"){  latexSamp = "WV(0.3,0)";}
	  
	  l.DrawLatex(0.15 , 0.75,Form("#bf{ W#rightarrow %s#nu , %s}", latexFlav.Data(), regionName[iRegion].Data()) );
	  l.DrawLatex(0.15 , 0.70,Form(" %s",  latexSamp.Data()) );
	  
	  
	  
	  
	  //c1->Print("plots_syst_response.pdf",Form("Title:%s_%s_%s_%s",sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  
	  c1->Print(Form("PDF_syst_band/response_%s_%s_%s_%s_2.pdf", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	  
	  //p1->Close();
	  //p2->Close();
	  
	  
	}
      }
    }
  }
 
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]->Close();

  }
  //c1->Print("plots_syst_response.pdf]","pdf");
}
