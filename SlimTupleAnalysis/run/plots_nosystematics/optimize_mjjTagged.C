{
  //optimize mjjTagged cut for SM limit setting
  const int nCut=2;TString cutName[nCut]={"SR","SRfatOnly"};
  const int nflav=4;TString flavorName[nflav]={"ep","em","mp","mm"};
  //const int nflav=1;TString flavorName[nflav]={"ep"};

  for (int iflav=0;iflav<nflav;++iflav){//loops over flavor
    for (int icut=0;icut<nCut;++icut){
    
      
      //TFile* f1= TFile::Open("../hwwlvqq.Nominal.caf4.2.lv7_all81.root");
      //TFile* f1= TFile::Open("../hwwlvqq.Nominal.caf4.2.lm0.root");
      TFile* f1= TFile::Open("../fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4_smw_MjjTag200.root");
      TH1F* hsigWV=(TH1F* )  f1->Get(Form("H_VBS_WV_0_0_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hsigZV=(TH1F* )  f1->Get(Form("H_VBS_ZV_0_0_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hWjets=(TH1F* )  f1->Get(Form("H_Wjets_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* httbar=(TH1F* )  f1->Get(Form("H_Ttbar_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hsingTop=(TH1F* )f1->Get(Form("H_SingleTop_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hdiboson=(TH1F* )f1->Get(Form("H_WZZZWg_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hZjets=(TH1F* )  f1->Get(Form("H_Zjets_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hQCD=(TH1F* )  f1->Get(Form("H_QCD_%s_WBF_%s_mjjTagged",flavorName[iflav].Data(), cutName[icut].Data()));
      TH1F* hMC = (TH1F* ) hWjets->Clone();
      hMC->Add(hZjets);
      hMC->Add(httbar);
      hMC->Add(hsingTop);
      hMC->Add(hdiboson);
      hMC->Add(hQCD);
      
      cout.precision(3);
      //cout<<hsigWV->Integral(1,31)<<" "<<hsigZV->Integral(1,31)<<" "<<hMC->Integral(1,31)<<endl; //no cut
      
      //cout<<hsigWV->Integral(11,31)<<" "<<hsigZV->Integral(11,31)<<" "<<hMC->Integral(11,31)<<endl; //mjjTagged>500
      //cout<<hsigWV->Integral(13,31)<<" "<<hsigZV->Integral(13,31)<<" "<<hMC->Integral(13,31)<<endl; //mjjTagged>600
      //cout<<hsigWV->Integral(14,31)<<" "<<hsigZV->Integral(14,31)<<" "<<hMC->Integral(14,31)<<endl; //mjjTagged>700
      //cout<<hsigWV->Integral(15,31)<<" "<<hsigZV->Integral(15,31)<<" "<<hMC->Integral(15,31)<<endl; //mjjTagged>800
      //cout<<hsigWV->Integral(16,31)<<" "<<hsigZV->Integral(16,31)<<" "<<hMC->Integral(16,31)<<endl; //mjjTagged>900
      cout<<hsigWV->Integral(17,31)<<" "<<hsigZV->Integral(17,31)<<" "<<hMC->Integral(17,31)<<endl;   //mjjTagged>1000
      //cout<<hsigWV->Integral(18,31)<<" "<<hsigZV->Integral(18,31)<<" "<<hMC->Integral(18,31)<<endl;   //mjjTagged>1100
      //cout<<hsigWV->Integral(19,31)<<" "<<hsigZV->Integral(19,31)<<" "<<hMC->Integral(19,31)<<endl;   //mjjTagged>1200
      //cout<<hsigWV->Integral(20,31)<<" "<<hsigZV->Integral(20,31)<<" "<<hMC->Integral(20,31)<<endl;   //mjjTagged>1300
      //cout<<hsigWV->Integral(21,31)<<" "<<hsigZV->Integral(21,31)<<" "<<hMC->Integral(21,31)<<endl;   //mjjTagged>1400
      //cout<<hsigWV->Integral(22,31)<<" "<<hsigZV->Integral(22,31)<<" "<<hMC->Integral(22,31)<<endl; //mjjTagged>1500
      

    }
  }
  
  
}
