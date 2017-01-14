{

  //reads ratio...root files, so error bars will be correct on the ratio of syst to Nominal. plots only systematic/Nominal ratio
  
#include <TLatex.h>
#include "makerHelper.h" //for AddOverflowBinToLastBin and GetXaxisRange function
#include "rebin.h"
#include "calculateRatioError.h"

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

  bool pdfforNote = 1;
  if (!pdfforNote)  c1->Print("plots_syst_response.pdf[","pdf");
  
  

  
  
  Int_t color_index[8] ={600,632,416,616,432,800,1,920};
  //enum EColor { kWhite =0,   kBlack =1,   kGray=920,
  //kRed   =632, kGreen =416, kBlue=600, kYellow=400, kMagenta=616, kCyan=432,
  //kOrange=800, kSpring=820, kTeal=840, kAzure =860, kViolet =880, kPink=900 };

  //const int nsyst =7;
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","NP_Special6JESUp"};
  //TString systname[nsyst]={"Eta_ModellingJESUp","Eta_TotStatJESUp", "HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp"};
  //const int nsyst =5;
  //TString systname[nsyst]={"FlavCompJESUp","FlavRespJESUp","bJESUp","PunchThroughJESUp","NonClosure_AFIIJESUp"};
  const int nsyst =8;
  TString systname[nsyst]={"ElecScaleUp","ElecResolutionUp","MSUP","IDUP",  "MUONSCALEUP", "ResoSoftTermsUp_ptHard", "ResoSoftTermsUpDown_ptHard","ScaleSoftTermsUp_ptHard"};
  //const int nsyst =4;
  //TString systname[nsyst]={"FatJESUp","JMSUp","FatJPTRUp","FatJMRUp"};
  
  //const int nsyst =1;
  //TString systname[nsyst]={"noPRW"};
  
  

  //const int nsyst =2;
  //TString systname[nsyst]={"FatJESUp","JMSUp"};
  //TString systname[nsyst]={"JMSUp","FatJPTRUp"};
  //TString systname[nsyst]={"JMSUp","JMSUp"};
  
  //TString systname[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp"};
  //TString systdown[nsyst]={"JERUp","NP_Special1JESDown","NP_Special2JESDown","NP_Special3JESDown","NP_Special4JESDown","NP_Special5JESDown","Eta_ModellingJESDown","Eta_TotStatJESDown","HighPtJESDown","MuJESDown","NPVJESDown","PilePtJESDown","PileRhoJESDown","FlavCompJESDown","FlavRespJESDown","bJESDown"};
  


  TFile *fsyst [nsyst];

  TH1F *hsyst[nsyst], *hsystdown[nsyst],*ratioHist[nsyst],*ratioHistdown[nsyst];
  TH1F *ratioHist2[nsyst],*ratioHistdown2[nsyst];
  TH1F *h_Nom[nsyst], *h_Syst[nsyst], *h_both[nsyst], *h_NomOnly[nsyst], *h_SystOnly[nsyst];
  TH1F *h_Nom_ori[nsyst], *h_Syst_ori[nsyst], *h_both_ori[nsyst], *h_NomOnly_ori[nsyst], *h_SystOnly_ori[nsyst];

  for (int isyst=0;isyst<nsyst;isyst++){
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv4/ratio_%s.caf4.2.lv4.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf3.lv7/ratio_%s.caf3.lv7.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv4_fatwindow40_140_mjjTag0/ratio_%s.caf4.2.lv4_fatwindow40_140_mjjTag0.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_NEW/ratio_%s.caf4.2_lv8_smw_wp20_NEW.root",systname[isyst].Data()));
    fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_NEW/ratio_%s.caf4.2_lv8_smw_wp20.root",systname[isyst].Data()));
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_New/ratio_%s.root",systname[isyst].Data())); //&&&&
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_NEW_10_PRW/ratio_%s.root",systname[isyst].Data())); //Pileup reweighting plots
    //cout<<Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_New/ratio_%s.root",systname[isyst].Data())<<endl;
    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_%s.caf4.2.lv4_fatwindow40_140_mjjTag0.root",systname[isyst].Data()));

    //fsyst[isyst]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/ratio_%s.caf4.2_test.root",systname[isyst].Data()));
    
  }
  //fsyst[0]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_New/ratio_JMSUp.root",systname[isyst].Data()));
  //fsyst[1]=TFile::Open(Form("~azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/RATIO.caf4.2.lv8_smw_wp20_New/ratio_JMSUp.root",systname[isyst].Data()));
  
  //const int nSample =1; TString sampleName[nSample] = {"VBS_WV_0_0"};
  //const int nSample =3; TString sampleName[nSample] = {"VBS_WV_0_0","VBS_WV_0_02","VBS_WV_03_0"};
  //const int nSample =8; TString sampleName[nSample] = {"Ttbar","Wjets","Zjets","SingleTop","WZZZWg", "VBS_WV_0_0","VBS_WV_0_03","VBS_WV_03_0"};
  const int nSample =1; TString sampleName[nSample] = {"Wjets"};
  //const int nSample =3; TString sampleName[nSample] = {"Ttbar","Wjets","VBS_WV_01_0"};

  const int nRegion =1; TString regionName[nRegion] = {"SR"};
  //const int nRegion =1; TString regionName[nRegion] = {"SRfatOnly"};
  //const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  

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
	
	  
	  if (( regionName[iRegion].Contains("fatOnly") || regionName[iRegion].Contains("FJ")) && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}


	  
	  
	  
	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    ///ratio calculated by the ratioError4.py macro &&&&
	    ///*
	    //ratioHist2[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_ratio", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	  
	    //////AddOverflowBinToLastBin(ratioHist2[isyst]); //for ratio plots overflow bin cannot be added like this
	    //cout<<"rebin = "<<rebin<<endl;
	    //ratioHist2[isyst]->Rebin(rebin);ratioHist2[isyst]->Scale(1/double(rebin)); //WRONG!! you are merging histogram bins containing ratios instead of taking ratio of merged bins. Dividing by the number of bins to get back the ratio of merged bins will not work because the bins did not have same number of events to start with.
	    
	    h_Nom_ori[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_Nominal", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	    h_Nom_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_em_WBF_%s_%s_Nominal", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_Nom_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mp_WBF_%s_%s_Nominal", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_Nom_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mm_WBF_%s_%s_Nominal", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    
	    h_Syst_ori[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_syst", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	    h_Syst_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_em_WBF_%s_%s_syst", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_Syst_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mp_WBF_%s_%s_syst", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_Syst_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mm_WBF_%s_%s_syst", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));

	    h_both_ori[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_both", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	    h_both_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_em_WBF_%s_%s_both", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_both_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mp_WBF_%s_%s_both", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_both_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mm_WBF_%s_%s_both", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));	
   
	    h_NomOnly_ori[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_NominalOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	    h_NomOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_em_WBF_%s_%s_NominalOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_NomOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mp_WBF_%s_%s_NominalOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_NomOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mm_WBF_%s_%s_NominalOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));

	    h_SystOnly_ori[isyst] =(TH1F*)fsyst[isyst]->Get(Form("H_%s_ep_WBF_%s_%s_systOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) );
	    h_SystOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_em_WBF_%s_%s_systOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_SystOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mp_WBF_%s_%s_systOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    h_SystOnly_ori[isyst] ->Add((TH1F*)fsyst[isyst]->Get(Form("H_%s_mm_WBF_%s_%s_systOnly", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()) ));
	    
	    h_Nom_ori[isyst]->Rebin(rebin);
	    h_Syst_ori[isyst]->Rebin(rebin);
	    h_both_ori[isyst]->Rebin(rebin);
	    h_NomOnly_ori[isyst]->Rebin(rebin);
	    h_SystOnly_ori[isyst]->Rebin(rebin);
	    
	    cout<<h_Nom_ori[isyst]->GetName()<<endl;
	    
	    // /* //rebinning to final fit binning  &&&&
	    int nbin = 5; //5 for resolved, 4 for fat
	    Double_t bins_mtwv[nbin+1]= {0., 300., 500., 600., 700., 1500.}; //resolved
	    //Double_t bins_mtwv[nbin+1]= {300., 600., 700., 800.,  1500.};  //fat
	    	    
	    h_Nom[isyst] = (TH1F*) h_Nom_ori[isyst]-> Rebin(nbin, Form("%s_new",h_Nom_ori[isyst]->GetName()), bins_mtwv);
	    h_Syst[isyst] = (TH1F*) h_Syst_ori[isyst]-> Rebin(nbin, Form("%s_new",h_Syst_ori[isyst]->GetName()), bins_mtwv);
	    h_both[isyst] = (TH1F*) h_both_ori[isyst]-> Rebin(nbin, Form("%s_new",h_both_ori[isyst]->GetName()), bins_mtwv);
	    h_NomOnly[isyst] = (TH1F*) h_NomOnly_ori[isyst]-> Rebin(nbin, Form("%s_new",h_NomOnly_ori[isyst]->GetName()), bins_mtwv);
	    h_SystOnly[isyst] = (TH1F*) h_SystOnly_ori[isyst]-> Rebin(nbin, Form("%s_new",h_SystOnly_ori[isyst]->GetName()), bins_mtwv);
	    // */
	    /* //regular binning
	    h_Nom[isyst] = (TH1F*)h_Nom_ori[isyst]->Clone();
	    h_Syst[isyst] = (TH1F*)h_Syst_ori[isyst]->Clone();
	    h_both[isyst] = (TH1F*)h_both_ori[isyst]->Clone();
	    h_NomOnly[isyst] = (TH1F*)h_NomOnly_ori[isyst]->Clone();
	    h_SystOnly[isyst] = (TH1F*)h_SystOnly_ori[isyst]->Clone();
	    */
	    ratioHist2[isyst] = (TH1F*) h_Syst[isyst]->Clone(Form("%s_%s",h_Syst[isyst]->GetName(),systname[isyst].Data()));
	    ratioHist2[isyst] ->Divide(h_Nom[isyst]);
	    
	    /*
	    /////
	    //cout<<"h_Syst "<<h_Syst[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Nom "<<h_Nom[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Nom+h_Syst  "<< h_Syst[isyst]->GetBinContent(4)/h_Nom[isyst]->GetBinContent(4)<<endl;
	    //cout<<"ratioHist2 "<<ratioHist2[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Syst err "<<h_Syst[isyst]->GetBinError(4)<<endl;
	    //cout<<"h_Nom err "<<h_Nom[isyst]->GetBinError(4)<<endl;
	    //cout<<"h_Nom+h_Syst err "<< (h_Syst[isyst]->GetBinContent(4)/h_Nom[isyst]->GetBinContent(4)) * sqrt( pow(h_Nom[isyst]->GetBinError(4)/h_Nom[isyst]->GetBinContent(4),2)  +  pow(h_Syst[isyst]->GetBinError(4)/h_Syst[isyst]->GetBinContent(4),2) )<<endl;

	    cout<<"ratioHist2 err "<<ratioHist2[isyst]->GetBinError(4)<<endl;

	    cout<<"h_both "<<h_both[isyst]->GetBinContent(4)<<endl;
	    cout<<"h_SystOnly "<<h_SystOnly[isyst]->GetBinContent(4)<<endl;
	    cout<<"h_NomOnly "<<h_NomOnly[isyst]->GetBinContent(4)<<endl;
	    
	    cout<<"h_both err "<<h_both[isyst]->GetBinError(4)<<endl;
	    cout<<"h_SystOnly err "<<h_SystOnly[isyst]->GetBinError(4)<<endl;
	    cout<<"h_NomOnly err "<<h_NomOnly[isyst]->GetBinError(4)<<endl;
	    ////
	    */
	    calculateRatioError( h_both[isyst],h_NomOnly[isyst],h_SystOnly[isyst], ratioHist2[isyst]);
	    ratioHist2[isyst]->SetLineColor(color_index[isyst]);

	    /*
	    cout<<"#############"<<endl;
	    //cout<<"h_Syst "<<h_Syst[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Nom "<<h_Nom[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Nom+h_Syst  "<< h_Syst[isyst]->GetBinContent(4)/h_Nom[isyst]->GetBinContent(4)<<endl;
	    //cout<<"ratioHist2 "<<ratioHist2[isyst]->GetBinContent(4)<<endl;
	    //cout<<"h_Syst err "<<h_Syst[isyst]->GetBinError(4)<<endl;
	    //cout<<"h_Nom err "<<h_Nom[isyst]->GetBinError(4)<<endl;
	    //cout<<"h_Nom+h_Syst err "<< (h_Syst[isyst]->GetBinContent(4)/h_Nom[isyst]->GetBinContent(4)) * sqrt( pow(h_Nom[isyst]->GetBinError(4)/h_Nom[isyst]->GetBinContent(4),2)  +  pow(h_Syst[isyst]->GetBinError(4)/h_Syst[isyst]->GetBinContent(4),2) )<<endl;
	    cout<<"ratioHist2 err "<<ratioHist2[isyst]->GetBinError(4)<<endl;
	    cout<<"h_both "<<h_both[isyst]->GetBinContent(4)<<endl;
	    cout<<"h_SystOnly "<<h_SystOnly[isyst]->GetBinContent(4)<<endl;
	    cout<<"h_NomOnly "<<h_NomOnly[isyst]->GetBinContent(4)<<endl;
	    
	    cout<<"h_both err "<<h_both[isyst]->GetBinError(4)<<endl;
	    cout<<"h_SystOnly err "<<h_SystOnly[isyst]->GetBinError(4)<<endl;
	    cout<<"h_NomOnly err "<<h_NomOnly[isyst]->GetBinError(4)<<endl;
	    cout<<"=============="<<endl;
	    */
	    
	    
	    
	  
	  }
	  

	  /*
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
	  */
	  
	  
	  
	  

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
	  //cout<< h_Nom->GetXaxis()->GetTitle() <<endl;
	  ratioHist2[0]->GetXaxis()->SetLabelSize(0.05);
	  ratioHist2[0]->GetXaxis()->SetTitleSize(0.05); 
	  ratioHist2[0]->SetMarkerStyle(20);
	  ratioHist2[0]->SetMarkerSize(0.6);
	  ratioHist2[0]->SetMarkerColor(ratioHist2[0]->GetLineColor());	  
	  
	  ratioHist2[0]->GetYaxis()->SetRangeUser(0.4, 2);
	  //ratioHist2[0]->GetYaxis()->SetRangeUser(0., 3);
	  //ratioHist2[0]->GetYaxis()->SetRangeUser(-0.5, 4);
	  ////ratioHist2[0]->GetYaxis()->SetRangeUser(0.8*(1-absmaxi),1.5*(1+absmaxi));
	  //ratioHist2[0]->GetYaxis()->SetRangeUser(1- 1.1*absmaxi, 1+ 2* absmaxi );
	  if (histName[iHist].Contains("fatjet_eta")){
	    ratioHist2[0]->GetXaxis()->SetRangeUser(-1.2,1.2);
	  }else {
	    ratioHist2[0]->GetXaxis()->SetRangeUser(xstart, xend);
	  }
	  
	  //cout<<xstart<<","<<xend<<endl;
	  //gStyle->SetOptStat(0);

	  for (int isyst=0;isyst<nsyst;isyst++){
	    
	    if(isyst==0){

	      
	    }else{
	      //ratioHist2[isyst]->Draw("hist][ same");
	      ratioHist2[isyst]->Draw("e0 p same");
	      ratioHist2[isyst]->SetMarkerStyle(20);
	      ratioHist2[isyst]->SetMarkerSize(0.6);
	      ratioHist2[isyst]->SetMarkerColor(ratioHist2[isyst]->GetLineColor());
	    }
	    
	  }
	    
	  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	  horiz_line->SetLineStyle(2);
	  horiz_line->DrawLine(xstart,1.0,xend,1.0);

	  
	  TLegend *leg = new TLegend(0.4, 0.70, 0.89, 0.89) ;
	  leg->SetTextSize(0.02);
	  leg->SetNColumns(2);
	  for (int isyst=0;isyst<nsyst;isyst++){
	    if (systname[isyst].Contains("_ptHard")) systname[isyst].ReplaceAll("_ptHard","");
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

	  TString latexSamp("");
	  	  
	  if (sampleName[iSample] == "Ttbar"){  latexSamp = "#it{t#bar{t}}";}
	  else if (sampleName[iSample] == "Wjets"){  latexSamp = "W+jets";}
	  else if (sampleName[iSample] == "Zjets"){  latexSamp = "Z+jets";}
	  else if (sampleName[iSample] == "SingleTop"){  latexSamp = "Single top";}
	  else if (sampleName[iSample] == "WZZZWg"){  latexSamp = "Di-boson";}
	  else if (sampleName[iSample] == "VBS_WV_0_0"){  latexSamp = "SM signal";}
	  else if (sampleName[iSample] == "VBS_WV_01_0"){  latexSamp = "WV(0.1,0)";}
	  else if (sampleName[iSample] == "VBS_WV_0_03"){  latexSamp = "WV(0,0.3)";}//"VBS_WV_0_03","VBS_WV_03_0"
	  else if (sampleName[iSample] == "VBS_WV_03_0"){  latexSamp = "WV(0.3,0)";}
	  
	  l.DrawLatex(0.15 , 0.75,Form("#bf{ W#rightarrow l#nu , %s}", regionName[iRegion].Data()) );
	  l.DrawLatex(0.15 , 0.70,Form(" %s",  latexSamp.Data()) );
	  
	  
	  if (!pdfforNote) {
	    c1->Print("plots_syst_response.pdf",Form("Title:%s_l_%s_%s",sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data()));
	  }else{
	    c1->Print(Form("PDF_syst_band/response_%s_l_%s_%s_%s.pdf", sampleName[iSample].Data(),  regionName[iRegion].Data(), histName[iHist].Data(), systname[0].Data()));
	  }
	  
	  	  
	  
	  //p1->Close();
	  //p2->Close();
	  
	  
	
      }
    }
  }
 
  for (int isyst=0;isyst<nsyst;isyst++){
    fsyst[isyst]->Close();

  }
  if (!pdfforNote) c1->Print("plots_syst_response.pdf]","pdf");
}
