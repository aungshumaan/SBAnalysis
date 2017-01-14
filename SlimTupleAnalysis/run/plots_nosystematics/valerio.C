{
  const int nsyst =21; 
  TString systName[nsyst]={"Nominal.small","JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"};
  //const int nsyst =2;
  //TString systName[nsyst]={"Nominal.small","JERUp"};

  const int nsample = 6; TString sampleName[nsample]={"Ttbar","Wjets","SingleTop","WZZZWg","Zjets","VBS_WV_0_0"};
  const int nflav = 4; TString flavName[nflav]={"ep","em","mp","mm"};
  
  //gDirectory->ls();
  
  //const int nhist = 2; TString histName[nhist]={"mjjTagged","MET_et"};
  const int nhist = 1; TString histName[nhist]={"mjjTagged"};
  for (int isample=0;isample<nsample;isample++){
    for (int iflav=0;iflav<nflav;iflav++){
	TFile* fout = TFile::Open(Form("valerio/%s_%s.root",sampleName[isample].Data(), flavName[iflav].Data()),"RECREATE");
	cout<<"Hello"<<endl;

	for (int isyst=0;isyst<nsyst;isyst++){
	  TFile* f = TFile::Open(Form("../HWWLVQQ.caf4.2.lv4/hwwlvqq.%s.root",systName[isyst].Data()));
	  //cout<<Form("hwwlvqq_%s.root",systName[isyst].Data())<<endl;

	  for (int ihist=0;ihist<nhist;ihist++){
	    TH1F* h = (TH1F*) f->Get(Form("H_%s_%s_WBF_SR_%s",sampleName[isample].Data(), flavName[iflav].Data(),histName[ihist].Data()));
	    if (systName[isyst]=="Nominal.small"){
	      cout<<systName[isyst]<<endl;
	      TH1F* hout= h->Clone(Form("H_%s_Nominal",histName[ihist].Data()));
	    }else{
	      TH1F* hout= h->Clone(Form("H_%s_%s",histName[ihist].Data(),systName[isyst].Data()));
	    }
	    fout->cd();
	    hout->Write();
	  }
	}
	fout->Close();
    }
  }



}
