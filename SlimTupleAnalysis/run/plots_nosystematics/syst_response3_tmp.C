{
  //=========Macro generated from canvas: c1/c1
  //=========  (Sat Jun  7 21:43:18 2014) by ROOT version5.34/18

  ///this code was originally for comparing Alpgen and sherpa samples (or powheg and mcnlo). It can be used to compare any two files
#include <TLatex.h>
#include "makerHelper.h" //for AddOverflowBinToLastBin and GetXaxisRange function
#include "rebin.h"
  
  bool debug =false;
  
  //  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  TCanvas *c1 = new TCanvas("c1", "c1",0,0,750,700);
  gStyle->SetOptStat(0);
  c1->Range(-1,-55.99637,9,503.9673);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->Print("plots_syst_response.pdf[","pdf");

  

  const int nsyst=8;

  Int_t color_index[nsyst] ={600,632,416,920,616,432,800,840};
  //enum EColor { kWhite =0,   kBlack =1,   kGray=920,
  //kRed   =632, kGreen =416, kBlue=600, kYellow=400, kMagenta=616, kCyan=432,
  //kOrange=800, kSpring=820, kTeal=840, kAzure =860, kViolet =880, kPink=900 };
  
  TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp"};
  //TString systname[nsyst]={"HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"}
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"JERUp","NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};

  
  //TFile *fnom=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.4.2_variableBin.root");//&&&& reading from the slimntuples, ratio error will be wrong

  //TFile *fnom=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf3.2.lv4_looseBadMuon1.1.root");
  TFile *fnom=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_separateWjetsEWK.root");

  
  TFile *fsyst [nsyst];
  
  TH1F *hsyst[nsyst], *ratioHist[nsyst];
  TH1F* hnom;

  for (int isyst=0;isyst<nsyst;isyst++){
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.%s.root",systname[isyst].Data())); //&&&&
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_%s.2.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.4.2/hwwlvqq.%s.4.2_variableBin.root",systname[isyst].Data()));

    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf3.lv4/hwwlvqq.%s.root",systname[isyst].Data()));
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_separateWjetsEWK_bugfixed/hwwlvqq.%s.root",systname[isyst].Data()));
  }
  
  
  const int nSample =1; TString sampleName[nSample] = {"Wjets"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets" ,"SingleTop", "WZZZWg","VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};

  //const int nFlavor =1; TString flavorName[nFlavor] = { "e"};
  const int nFlavor =2; TString flavorName[nFlavor] = { "e","m"};

  //const int nRegion =1; TString regionName[nRegion] = {"CR_Wjj"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  //const int nRegion =4; TString regionName[nRegion] = {"CR_Top","SR","CR_TopFJ","SRFJ"};
  //const int nRegion =1; TString regionName[nRegion] = {"PRESELECT"};
  //const int nRegion=4;TString regionName[nRegion]={"CR_Wjj","CR_WjjFJ","CR_Top","CR_TopFJ"};

 
  //const int nHist =1 ;TString histName[nHist]={"Mwjj"}; 
  //const int nHist =5 ;TString histName[nHist]={"ptwjj","ptwlep","Mlvjj","ptlvjj", "Mwjj"}; 
  //const int nHist =17 ;TString histName[nHist]={ "dEtaTaggedJets","mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","MET_et","mT","ptBalance","Njet"};

  const int nHist =7;TString histName[nHist]={"mjjTagged","Mwjj","bosonCentrality","cosThetaWDecay","mTWV","VVptBalance","ptwlep"};

   
  int rebin=1;
  int rebinFac =1;

  for (int iHist=0;iHist<nHist;iHist++){
    for (int iRegion=0;iRegion<nRegion;iRegion++){	  
      for (int iSample=0;iSample<nSample;iSample++){
	
	for (int iFlavor=0;iFlavor<nFlavor;iFlavor++){
	  
	  if (( regionName[iRegion].Contains("fatOnly") || regionName[iRegion].Contains("FJ")) && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	   
	  
	  bool logy=false;
	  if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("Mlvjj") || histName[iHist].Contains("ptlvjj")|| histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") || histName[iHist].Contains("MET_et") || histName[iHist].Contains("lep_pt")){
	    logy = true;
	  }
	  
	  hnom =(TH1F*)fnom->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ); //&&&&
	  hnom->Add((TH1F*)fnom->Get( Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );

	  //hnom =(TH1F*)fsyst[0]->Get(Form("H_%s_%sp_WBF_%s_%s_Nominal", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );


	  AddOverflowBinToLastBin(hnom);

	  rebin =1; rebinFac=1;

	  if (!(histName[iHist].Contains("Njet") || histName[iHist].Contains("Mwjj"))){
	    rebinFac = getRebinFactor(histName[iHist]);
	    rebin *=rebinFac;
	
	    hnom->Rebin(rebin);
	  }

	  


	  for (int isyst=0;isyst<nsyst;isyst++){
	    //cout<<">>>>>>>>>>>>>>>>>>> "<<isyst<<endl;
	    //&&&& reading from the slimntuples, ratio error will be wrong
	    hsyst[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sp_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    hsyst[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_%sm_WBF_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) ) );
	    hsyst[isyst]->SetLineColor(color_index[isyst]);

	    AddOverflowBinToLastBin(hsyst[isyst]);
	    hsyst[isyst]->Rebin(rebin);
	    
	    ratioHist[isyst] = (TH1F*)hsyst[isyst]->Clone("ratioHist");
	    ratioHist[isyst] ->Divide(hnom); //&&&& This ratio is not right because of correlation

	    //hsyst[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sp_WBF_%s_%s_syst", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    //hsyst[isyst]->SetLineColor(color_index[isyst]);
	    //ratioHist[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_%sp_WBF_%s_%s_ratio", sampleName[iSample].Data(), flavorName[iFlavor].Data(), regionName[iRegion].Data(), histName[iHist].Data()) );
	    //ratioHist[isyst]->SetLineColor(color_index[isyst]);
	    
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

	  for (int isyst=0;isyst<nsyst;isyst++){
	    	    
	    if(isyst==0){
	      //hsyst[isyst]->SetTitle(Form("%s_%s_%s_%s", sampleName[iSample].Data(), flavorName[iFlavor].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	      hsyst[isyst]->SetTitle("");
	      hsyst[isyst]->Draw();
	      GetXaxisRange(hsyst[isyst],xstart,xend);

	      
	      hsyst[isyst]->GetXaxis()->SetRangeUser(xstart,xend);
	      

	    }else{
	      hsyst[isyst]->Draw("same");
	    }
	    
	  }

	  //cout<<"After GetXaxisRange: "<<xstart<<","<<xend<<endl;
	    
	  hnom->SetMarkerStyle(20);
	  hnom->SetMarkerSize(0.5);
	  hnom->Draw("same");


	  // if ( histName[iHist].Contains("Mwjj") ){
	  //   if ( regionName[iRegion]=="CR_Top" || regionName[iRegion]=="SR"){
	  //     hnom->GetXaxis()->SetRangeUser(75,95);
	  //     //hsyst[isyst]->GetXaxis()->SetRangeUser(75,95);
	  //   }else if (  regionName[iRegion]=="CR_TopFJ" || regionName[iRegion]=="SRFJ"  || regionName[iRegion]=="CR_TopfatOnly" || regionName[iRegion]=="SRfatOnly"){
	  //     hnom->GetXaxis()->SetRangeUser(60,110);
	  //     //hsyst[isyst]->GetXaxis()->SetRangeUser(60,110);
	  //   }
	  // }
	  
	  
	  double maxi= 0;
	  for (int isyst=0;isyst<nsyst;isyst++){
	    if (hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin())>maxi){
	      maxi=hsyst[isyst]->GetBinContent(hsyst[isyst]->GetMaximumBin());
	    }
	  }
	  hsyst[0]->SetMaximum(maxi*1.5);
	  if (logy)hsyst[0]->SetMaximum(maxi*200.);
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
	  // if (flavorName[iFlavor] == "ep") { latexFlav = "e^{+}";}
	  // else if (flavorName[iFlavor] == "em") { latexFlav = "e^{-}";}
	  // else if (flavorName[iFlavor] == "mp") {  latexFlav = "#mu^{+}";}
	  // else if (flavorName[iFlavor] == "mm") {  latexFlav = "#mu^{-}";}
	  if (flavorName[iFlavor] == "e") { latexFlav = "e";}
	  else if (flavorName[iFlavor] == "m") {  latexFlav = "#mu";}
	  
	  l.DrawLatex(0.20 , 0.60,Form("#bf{ W#rightarrow %s#nu , %s, %s}", latexFlav.Data(), regionName[iRegion].Data(), sampleName[iSample].Data()) );
	 


	
	    
	  p2->cd();
	  gStyle->SetOptStat(0);

	  for (int isyst=0;isyst<nsyst;isyst++){
	      
	    if(isyst==0){
	      ratioHist[isyst]->Draw("hist][");


	      ratioHist[isyst]->SetTitle("");
	      ratioHist[isyst]->GetYaxis()->SetTitle("Data/SM");
	      ratioHist[isyst]->GetYaxis()->SetLabelSize(0.1);
	      ratioHist[isyst]->GetYaxis()->SetTitleSize(0.08);
	      ratioHist[isyst]->GetYaxis()->SetTitleOffset(0.5);
	      ratioHist[isyst]->GetYaxis()->CenterTitle();
	      ratioHist[isyst]->GetXaxis()->SetLabelSize(0.1);
	      ratioHist[isyst]->GetXaxis()->SetTitleSize(0.15); 
	      
	      
	      //ratioHist[isyst]->GetYaxis()->SetLabelSize(0.07);
	      //ratioHist[isyst]->GetXaxis()->SetLabelSize(0.07);
	      ratioHist[isyst]->GetYaxis()->SetRangeUser(0.6, 2.);
	      ratioHist[isyst]->GetXaxis()->SetRangeUser(xstart, xend);
	      
	    }else{
	      ratioHist[isyst]->Draw("hist][ same");
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
