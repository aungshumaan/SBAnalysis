{
  gROOT->Reset();
  TFile *f = new TFile("basic2_fat.root","RECREATE");

  //const int nsyst=1;TString systName [nsyst]={"NP_Special1JESUp"};
  //const int nsyst=2;TString systName [nsyst]={"JERUp","NP_Special1JESUp"};
  const int nsyst=20; TString systName[nsyst]={"JERUp","NP_Special1JESUp","NP_Special2JESUp","NP_Special3JESUp","NP_Special4JESUp","NP_Special5JESUp","Eta_ModellingJESUp","Eta_TotStatJESUp","HighPtJESUp","MuJESUp","NPVJESUp","PilePtJESUp","PileRhoJESUp","FlavCompJESUp","FlavRespJESUp","bJESUp","FatJESUp","FatJPTRUp","JMSUp","FatJMRUp"};
  

  TTree *T_Data = new TTree("Data","Data from ascii file");
  Long64_t nlines = T_Data->ReadFile("../TXT.caf4.2.lm0/txt_Data_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_Data->Write();
  T_Data->Delete();

  TTree *T_ttbar = new TTree("ttbar_NoSys","ttbar Nominal from ascii file");
  Long64_t nlines = T_ttbar->ReadFile("../TXT.caf4.2.lm0/txt_Ttbar_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_ttbar->Write();
  T_ttbar->Delete();

  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_ttbar = new TTree(Form("ttbar_%s",systName[isyst].Data()),Form("ttbar %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_ttbar->ReadFile(Form("../TXT.caf4.2.lm0/txt_Ttbar_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_ttbar->Write();
  }
  T_ttbar->Delete();

  
  // /*

  TTree *T_singleTop = new TTree("singletop_NoSys","single top from ascii file");
  Long64_t nlines = T_singleTop->ReadFile("../TXT.caf4.2.lm0/txt_SingleTop_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_singleTop->Write();
  T_singleTop->Delete();
    
  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_singleTop = new TTree(Form("singletop_%s",systName[isyst].Data()),Form("single top %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_singleTop->ReadFile(Form("../TXT.caf4.2.lm0/txt_SingleTop_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_singleTop->Write();
  }
  T_singleTop->Delete();
  

  TTree *T_Wjets = new TTree("Wjets_NoSys","Wjets from ascii file");
  Long64_t nlines = T_Wjets->ReadFile("../TXT.caf4.2.lm0/txt_Wjets_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_Wjets->Write();
  T_Wjets->Delete();

  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_Wjets = new TTree(Form("Wjets_%s",systName[isyst].Data()),Form("Wjets %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_Wjets->ReadFile(Form("../TXT.caf4.2.lm0/txt_Wjets_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_Wjets->Write();
  }
  T_Wjets->Delete();
  
  
  TTree *T_Zjets = new TTree("Zjets_NoSys","Zjets from ascii file");
  Long64_t nlines = T_Zjets->ReadFile("../TXT.caf4.2.lm0/txt_Zjets_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_Zjets->Write();
  T_Zjets->Delete();
  
  for (int isyst=0;isyst<nsyst;isyst++){
  TTree *T_Zjets = new TTree(Form("Zjets_%s",systName[isyst].Data()),Form("Zjets %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_Zjets->ReadFile(Form("../TXT.caf4.2.lm0/txt_Zjets_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_Zjets->Write();
  
  }
  T_Zjets->Delete();

  TTree *T_diboson = new TTree("diboson_NoSys","Diboson from ascii file");
  Long64_t nlines = T_diboson->ReadFile("../TXT.caf4.2.lm0/txt_WZZZWg_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_diboson->Write();
  T_diboson->Delete();
  
  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_diboson = new TTree(Form("diboson_%s",systName[isyst].Data()),Form("Diboson %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_diboson->ReadFile(Form("../TXT.caf4.2.lm0/txt_WZZZWg_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_diboson->Write();
  
  }
  T_diboson->Delete();
  // */
  
  TTree *T_sigWV = new TTree("sig_NoSys","signal WV from ascii file");
  Long64_t nlines = T_sigWV->ReadFile("../TXT.caf4.2.lm0/txt_VBS_WV_0_0_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_sigWV->Write();
  T_sigWV->Delete();

  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_sigWV = new TTree(Form("sig_%s",systName[isyst].Data()),Form("signal WV %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_sigWV->ReadFile(Form("../TXT.caf4.2.lm0/txt_VBS_WV_0_0_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_sigWV->Write();
  }
  
  T_sigWV->Delete();

  TTree *T_sigZV = new TTree("sigZV_NoSys","signal ZV from ascii file");
  Long64_t nlines = T_sigZV->ReadFile("../TXT.caf4.2.lm0/txt_VBS_ZV_0_0_mp_WBF_SRfatOnly_Nominal.txt");
  printf(" found %lld points\n",nlines);
  T_sigZV->Write();
  T_sigZV->Delete();

  for (int isyst=0;isyst<nsyst;isyst++){
    TTree *T_sigZV = new TTree(Form("sigZV_%s",systName[isyst].Data()),Form("signal ZV %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_sigZV->ReadFile(Form("../TXT.caf4.2.lm0/txt_VBS_ZV_0_0_mp_WBF_SRfatOnly_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_sigZV->Write();
  }
  
  T_sigZV->Delete();

  /*
  for (int isyst=0;isyst<nsyst;isyst++){
    
    TTree *T_ttbar = new TTree(Form("ttbar_%s",systName[isyst].Data()),Form("ttbar %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_ttbar->ReadFile(Form("../TXT.caf4.2.lm0/txt_Ttbar_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_ttbar->Write();
    //T_ttbar->Delete();

      
    TTree *T_singleTop = new TTree(Form("singletop_%s",systName[isyst].Data()),Form("single top %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_singleTop->ReadFile(Form("../TXT.caf4.2.lm0/txt_SingleTop_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_singleTop->Write();
    //T_singleTop->Delete();
    
    
    TTree *T_Wjets = new TTree(Form("Wjets_%s",systName[isyst].Data()),Form("Wjets %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_Wjets->ReadFile(Form("../TXT.caf4.2.lm0/txt_Wjets_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_Wjets->Write();
    //T_Wjets->Delete();
    
    TTree *T_Zjets = new TTree(Form("Zjets_%s",systName[isyst].Data()),Form("Zjets %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_Zjets->ReadFile(Form("../TXT.caf4.2.lm0/txt_Zjets_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_Zjets->Write();
    //T_Zjets->Delete();
    
    TTree *T_diboson = new TTree(Form("diboson_%s",systName[isyst].Data()),Form("Diboson %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_diboson->ReadFile(Form("../TXT.caf4.2.lm0/txt_WZZZWg_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_diboson->Write();
    //T_diboson->Delete();
     

    
    TTree *T_sigSM = new TTree(Form("sig_%s",systName[isyst].Data()),Form("signal %s from ascii file",systName[isyst].Data()));
    Long64_t nlines = T_sigSM->ReadFile(Form("../TXT.caf4.2.lm0/txt_VBS_WV_0_0_mp_WBF_SR_%s.txt",systName[isyst].Data()));
    printf(" found %lld points\n",nlines);
    T_sigSM->Write();
    //T_sigSM->Delete();

  
  }
  */
 
}



//Long64_t TTree::ReadFile(const char *filename, const char *branchDescriptor)
