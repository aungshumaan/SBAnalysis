void RunQGCFitHandler(){
  
  gROOT->ProcessLine(".L QGCInterpolator.cc+");

  
  gROOT->ProcessLine(".L QGCFitHandler.cc+");
  
  
  //QGCFitHandler a("aqgcTemplates_Fullnice_v1.root");
  // QGCFitHandler a("hQGCFitTemplates_test23Jan2015.root");
  //  QGCFitHandler a("hQGCFitTemplates_test13Feb2015.root");
  // QGCFitHandler a("hQGCFitTemplates_test21Apr2015.root");
  // QGCFitHandler a("aqgcTemplates_Fullnice_v2.root"); //this has full set of JES/JER systematics in it, from Aungshuman.

  //  QGCFitHandler a("hRGSCutsFitmTWV2_nice.root");

  // QGCFitHandler a("hAllRGSPoint1_nice.root");
  // QGCFitHandler a("hAllRGSPt2_nice.root");
  //  QGCFitHandler a("hAllRGSPoint1fitMjj_nice.root");
  
  // QGCFitHandler a("hQGCFitTemplates_test31Jul2015.root");

  //QGCFitHandler a("hQGCFitTemplates_test31Jul2015_allAQGCPoints.root");
  //QGCFitHandler a("hQGCFitTemplates_test31Jul2015_allAQGCPoints.root.tmp.OLD");
  //  QGCFitHandler a("hQGCFitTemplates_test31Jul2015_allAQGCPoints.root.tmp");
  
  

  

  // QGCFitHandler a("hwwlvqq.mytest.root.0.4bkg.linearfit2Full"); //got b-tag systs added

  // QGCFitHandler a("hwwlvqq.mytest.root.0.4bkg.linearfit4Full");
  
  //   QGCFitHandler a("hwwlvqq.mytest.root");
  
  //   QGCFitHandler a("hwwlvqq.mytest.root.0.4bkg.coarsefit1Full");
  
  //  QGCFitHandler a("hwwlvqq.mytest.root.linearfit3NoNegFull");
  
  //  QGCFitHandler a("hwwlvqq.mytest.root.linearfit4Full");
  // QGCFitHandler a("hwwlvqq.mytest.root.linearfit5Full");
  
  //    QGCFitHandler a("hwwlvqq.mytest.root.linearfit6Full");
  
  // QGCFitHandler a("hwwlvqq.mytest.root.coarseBin6Full");

  //  QGCFitHandler a("hwwlvqq.mytest.root.0.2bkg.coarseBin8Full");


  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.coarseBin9Full");

  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.coarseBin10Full");

  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.linearfit8Full");

  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.linearfit10Full");

  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.linearfit11Full");
  
  //  QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.linearfit12Full");


  //  QGCFitHandler a("hwwlvqq.mytest.root.0.2bkg.linearfit12Full");
  

  // QGCFitHandler a("hwwlvqq.mytest.root");

  QGCFitHandler a("hwwlvqq.mytest.root.Official.01Feb2016");

  //QGCFitHandler a("hwwlvqq.mytest.root.0.4bkg.linearfit12Full");
  
  
  // QGCFitHandler a("hwwlvqq.mytest.root.0.2bkg.coarseBin11Full");
  
  // QGCFitHandler a("hwwlvqq.mytest.root.0.1bkg.mixedBSmooth1Full");
  
  
  // QGCFitHandler a("hwwlvqq.mytest.root.linearfit2");  //for non-detector systematics, normalizing linearfit results to original syst.

    // QGCFitHandler a("hwwlvqq.mytest.root.0.4bkg.linearfit3Full");
  
  
  a.setSigBBBinCov(false); //set to false for config files for running frequentist limits.
  
  a.setFitVar("mTWV");
  // a.setFitVar("bosonCentrality");
  // a.setFitVar("mjjTagged");
  
  
  //another way of merging em and mm, for example, might be to create a category called "WBF_SRfat", and then
  //add "Ttbar_em" and "Ttbar_mm" as two different backgrounds.  This would probably give more flexibility
  //regarding the addition of systematics that affect em and mm independently.
  
  a.addCat("mm_WBF_SRfatOnly","em_WBF_SRfatOnly","mp_WBF_SRfatOnly","ep_WBF_SRfatOnly"); 
  
  a.addCat("mp_WBF_SR","ep_WBF_SR");
  a.addCat("mm_WBF_SR","em_WBF_SR");
  

  

  //   a.addCat("mp_WBF_SRfatOnly","ep_WBF_SRfatOnly"); 
  //   a.addCat("mm_WBF_SRfatOnly","em_WBF_SRfatOnly");
  //    a.addCat("mp_WBF_SR","ep_WBF_SR","mm_WBF_SR","em_WBF_SR");
  
  
//    a.addCat("mp_WBF_SRFJ","ep_WBF_SRFJ","mm_WBF_SRFJ","em_WBF_SRFJ"); 
//    a.addCat("mp_WBF_SRresolveOnly","ep_WBF_SRresolveOnly","mm_WBF_SRresolveOnly","em_WBF_SRresolveOnly");
   
//   a.addCat("mp_WBF_SRFJ","ep_WBF_SRFJ");
//   a.addCat("mm_WBF_SRFJ","em_WBF_SRFJ"); 
//   a.addCat("mp_WBF_SRresolveOnly","ep_WBF_SRresolveOnly","mm_WBF_SRresolveOnly","em_WBF_SRresolveOnly");

  
//   a.addCat("mp_WBF_SRFJ","ep_WBF_SRFJ");
//   a.addCat("mm_WBF_SRFJ","em_WBF_SRFJ"); 
//   a.addCat("mp_WBF_SRresolveOnly","ep_WBF_SRresolveOnly");
//   a.addCat("mm_WBF_SRresolveOnly","em_WBF_SRresolveOnly");



//   a.addCat("mp_WBF_SRfatOnly","ep_WBF_SRfatOnly"); 
//   a.addCat("mm_WBF_SRfatOnly","em_WBF_SRfatOnly");
//   a.addCat("mp_WBF_SR","ep_WBF_SR");
//   a.addCat("mm_WBF_SR","em_WBF_SR");


    
    //  a.addCat("mm_WBF_SRfatOnly","em_WBF_SRfatOnly","mp_WBF_SRfatOnly","ep_WBF_SRfatOnly"); 
    //    a.addCat("mp_WBF_SR","ep_WBF_SR","mm_WBF_SR","em_WBF_SR");
    
    
    // a.addCat("mp_WBF_SRFJ","ep_WBF_SRFJ");  
    //  a.addCat("mm_WBF_SRFJ","em_WBF_SRFJ"); 
    //    a.addCat("mp_WBF_SRresolveOnly","ep_WBF_SRresolveOnly","mm_WBF_SRresolveOnly","em_WBF_SRresolveOnly");
    



  
  
  //HAVE TO DO setFitVar and ADDCAT BEFORE DOING INITIALIZE!!
  //This function will reset the binning!!!
  a.initialize();
  
  // /*
  bool doQcdSyst=true;
  bool doTtbarRateSyst=true;
  bool doOtherBkgRateSyst=true;
  bool doVjetGenSyst=true;
  bool doSigGenSyst=true;
  bool doTtbarGenSyst=true;
  bool doVjetSFSyst=true;
  bool doJetSmallRSyst=true;
  bool doJetLargeRSyst=true;
  bool doOtherDetSyst=true;
  bool doLumiSyst=true;
 
 // */

  /*
  bool doQcdSyst=false;
  bool doTtbarRateSyst=false;
  bool doOtherBkgRateSyst=false;
  bool doVjetGenSyst=false;
  bool doSigGenSyst=false; 
  bool doTtbarGenSyst=false;
  bool doVjetSFSyst=false;
  bool doJetSmallRSyst=false;
  bool doJetLargeRSyst=false;
  bool doOtherDetSyst=false;
  */

  //comment out for making plots, if you only want to plot shape systematics in the systematic bands.
  
//   a.addRateSyst("qcd","0",0.20);
//   a.addRateSyst("qcd","1",0.20);
//   a.addRateSyst("qcd","2",0.20);
//   a.addRateSyst("qcd","3",0.20);

//   a.addRateSyst("wjet","0,1,2,3",0.20);
//   a.addRateSyst("top","0,1,2,3",0.15);
  
  if(doQcdSyst){
    
    //should include these!!
    a.addRateSyst("qcd","0",1.0);
    a.addRateSyst("qcd","1",1.0);
    a.addRateSyst("qcd","2",1.0);
    a.addRateSyst("qcd","3",1.0);
  }
  
  if(doTtbarRateSyst){
    //should include this!!!
    a.addRateSyst("ttbar","0,1,2,3",0.055);  //This is from twiki: https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO.  xsec = 252.89 {+13.3} {-14.5} pb
    
  }

  if(doOtherBkgRateSyst){
    //should include this!!!
    a.addRateSyst("stop","0,1,2,3",0.5);  
    a.addRateSyst("diboson","0,1,2,3",0.5); 
    a.addShapeSyst("wjet","0,1,2","wjetEWKUp","wjetEWKUp"); 
  }
  
  if(doLumiSyst){
    a.addRateSyst("ttbar,stop,diboson,zjet,sig","0,1,2",0.019);  //don't apply to wjet or QCD, since those have data-driven normalizations.
  }
  


  //////// a.addRateSyst("sig","0,1,2,3",0.1);  //probably not needed at all (double-counted with scale variation?)
  
  // */
  
  
  ///////// a.addRateSyst("sig","2",0.3); 
  //  */
  
  
  //   
  
  
  
  // shape systematics are in principle coded up, but not tested
  
  if(doVjetGenSyst){

    //V+jets Sherpa modeling
    a.addShapeSyst("wjet,zjet","0,1,2","fac025","fac4");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("wjet,zjet","0,1,2","ckkw15","ckkw30");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("wjet,zjet","0,1,2","renorm025","renorm4");  //code will automatically choose to symmetrize one of them
  }
  

  if(doVjetSFSyst){
    
    ///////////a.addShapeSyst("wjet","0,1,2","wjetSFup","wjetSFup");  //code will automatically choose to symmetrize one of them
    
    //W+jets SF uncorrelated between channels to be conservative
    a.addShapeSyst("wjet","0","wjetSFup","wjetSFup");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("wjet","1","wjetSFup","wjetSFup");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("wjet","2","wjetSFup","wjetSFup");  //code will automatically choose to symmetrize one of them
  }  

  if(doSigGenSyst){
    
    //signal
    a.addShapeSyst("sig","0,1,2","Herwigpp","Herwigpp");  
    a.addShapeSyst("sig","0,1,2","cteq6","cteq6");  
    a.addShapeSyst("sig","0,1,2","scale_20_20","scale_05_05");
  }  
  
  if(doTtbarGenSyst){
    
    //ttbar
    a.addShapeSyst("ttbar","0,1,2","McnloVsPowheg","McnloVsPowheg");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("ttbar","0,1,2","HerwigVsPythia","HerwigVsPythia");  //code will automatically choose to symmetrize one of them
    a.addShapeSyst("ttbar","0,1,2","AcerMCUpDown","AcerMCUpDown");  //code will automatically choose to symmetrize one of them
  }


  if(doJetSmallRSyst){
    
    //big systs:  JERUp, NP_Special1JESUp, Eta_ModellingJESUp, FlavCompJESUp FlavRespJESUp
    
    
    //JER
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","JERUp","JERUp");  
    
    //JES (small-R jets)
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special1JESUp","NP_Special1JESUp");  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special2JESUp","NP_Special2JESUp");  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special3JESUp","NP_Special3JESUp"); 
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special4JESUp","NP_Special4JESUp");  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special5JESUp","NP_Special5JESUp");  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NP_Special6JESUp","NP_Special6JESUp");  
    
    
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","Eta_ModellingJESUp","Eta_ModellingJESUp");  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","Eta_TotStatJESUp","Eta_TotStatJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","HighPtJESUp","HighPtJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","PunchThroughJESUp","PunchThroughJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NonClosure_AFIIJESUp","NonClosure_AFIIJESUp");
    
    
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","MuJESUp","MuJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","NPVJESUp","NPVJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","PilePtJESUp","PilePtJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","PileRhoJESUp","PileRhoJESUp");
    

    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","FlavCompJESUp","FlavCompJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","FlavRespJESUp","FlavRespJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","bJESUp","bJESUp");
    
  }

  if(doOtherDetSyst){
    
    //electrons  
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","ElecScaleUp","ElecScaleUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","ElecResolutionUp","ElecResolutionUp");
    
    //muons
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","MSUP","MSUP");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","IDUP","IDUP");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","MUONSCALEUP","MUONSCALEUP");
    
    //MET
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","ResoSoftTermsUp_ptHard","ResoSoftTermsUp_ptHard");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","ResoSoftTermsUpDown_ptHard","ResoSoftTermsUpDown_ptHard");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","ScaleSoftTermsUp_ptHard","ScaleSoftTermsUp_ptHard");
    
    //btag
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","btagforB","btagforB");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","btagforLight","btagforLight");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","btagforC","btagforC");
    
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","muSFUp","muSFUp"); 
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","elIDUp","elIDUp"); 
    
  }

  if(doJetLargeRSyst){
    
    //JES/JER/JMR/JMS (large-R jets)
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","FatJESUp","FatJESUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","JMSUp","JMSUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","FatJPTRUp","FatJPTRUp");
    a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0,1,2","FatJMRUp","FatJMRUp");
    
  }
  
  
  
  //////////////
  //////////////
  //my hack test 
  //////////////
  //////////////

 

  /* 

  //big systs:  JERUp, NP_Special1JESUp, Eta_ModellingJESUp, FlavCompJESUp FlavRespJESUp

 
  //JER
  a.addShapeSyst("sig,wjet","0,1,2","JERUp","JERUp");  

  
 
  
  
  //JES (small-R jets)
  a.addShapeSyst("sig,wjet","0,1,2","NP_Special1JESUp","NP_Special1JESUp");  
  a.addShapeSyst("sig,wjet","0,1,2","NP_Special2JESUp","NP_Special2JESUp");  
  a.addShapeSyst("sig,wjet","0,1,2","NP_Special3JESUp","NP_Special3JESUp"); 
  a.addShapeSyst("sig,wjet","0,1,2","NP_Special4JESUp","NP_Special4JESUp");  
  a.addShapeSyst("sig,wjet","0,1,2","NP_Special5JESUp","NP_Special5JESUp");  
  //where is in-situ 6?
  

  a.addShapeSyst("sig,wjet","0,1,2","Eta_ModellingJESUp","Eta_ModellingJESUp");  
  a.addShapeSyst("sig,wjet","0,1,2","Eta_TotStatJESUp","Eta_TotStatJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","HighPtJESUp","HighPtJESUp");



  
  
  //where is MC non-closure?
  a.addShapeSyst("sig,wjet","0,1,2","MuJESUp","MuJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","NPVJESUp","NPVJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","PilePtJESUp","PilePtJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","PileRhoJESUp","PileRhoJESUp");
  
  a.addShapeSyst("sig,wjet","0,1,2","FlavCompJESUp","FlavCompJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","FlavRespJESUp","FlavRespJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","bJESUp","bJESUp");
  //where is push-through??
  




   
  //JES/JER/JMR/JMS (large-R jets)
  a.addShapeSyst("sig,wjet","0,1,2","FatJESUp","FatJESUp");
  a.addShapeSyst("sig,wjet","0,1,2","JMSUp","JMSUp");
  a.addShapeSyst("sig,wjet","0,1,2","FatJPTRUp","FatJPTRUp");
  a.addShapeSyst("sig,wjet","0,1,2","FatJMRUp","FatJMRUp");
  

  //electrons  
  a.addShapeSyst("sig,wjet","0,1,2","ElecScaleUp","ElecScaleUp");
  a.addShapeSyst("sig,wjet","0,1,2","ElecResolutionUp","ElecResolutionUp");
  
  //muons
  a.addShapeSyst("sig,wjet","0,1,2","MSUP","MSUP");
  a.addShapeSyst("sig,wjet","0,1,2","IDUP","IDUP");
  a.addShapeSyst("sig,wjet","0,1,2","MUONSCALEUP","MUONSCALEUP");
  
  //MET
  a.addShapeSyst("sig,wjet","0,1,2","ResoSoftTermsUp_ptHard","ResoSoftTermsUp_ptHard");
  a.addShapeSyst("sig,wjet","0,1,2","ResoSoftTermsUpDown_ptHard","ResoSoftTermsUpDown_ptHard");
  a.addShapeSyst("sig,wjet","0,1,2","ScaleSoftTermsUp_ptHard","ScaleSoftTermsUp_ptHard");
  
  //btag
  a.addShapeSyst("sig,wjet","0,1,2","btagforB","btagforB");
  a.addShapeSyst("sig,wjet","0,1,2","btagforLight","btagforLight");
  a.addShapeSyst("sig,wjet","0,1,2","btagforC","btagforC");
  
  */
  









  //////////////
  //////////////
  //my hack test for only 2 categories
  //////////////
  //////////////

 





 
  //////////////
  //////////////
  //my hack test for only 1 category
  //////////////
  //////////////

  /*
  
  //V+jets Sherpa modeling
  a.addShapeSyst("wjet,zjet","0","fac025","fac4");  //code will automatically choose to symmetrize one of them
  a.addShapeSyst("wjet,zjet","0","ckkw15","ckkw30");  //code will automatically choose to symmetrize one of them
  a.addShapeSyst("wjet,zjet","0","renorm025","renorm4");  //code will automatically choose to symmetrize one of them
  
  
  //signal
  a.addShapeSyst("sig","0","Herwigpp","Herwigpp");  
  a.addShapeSyst("sig","0","cteq6","cteq6");  
  a.addShapeSyst("sig","0","scale_20_20","scale_05_05");
  
 
  //ttbar
   a.addShapeSyst("ttbar","0","McnloVsPowheg","McnloVsPowheg");  //code will automatically choose to symmetrize one of them
  a.addShapeSyst("ttbar","0","HerwigVsPythia","HerwigVsPythia");  //code will automatically choose to symmetrize one of them
  a.addShapeSyst("ttbar","0","AcerMCUpDown","AcerMCUpDown");  //code will automatically choose to symmetrize one of them
 

  //big systs:  JERUp, NP_Special1JESUp, Eta_ModellingJESUp, FlavCompJESUp FlavRespJESUp

 
 
  //JER
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","JERUp","JERUp");  
  
  
  
  //JES (small-R jets)
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NP_Special1JESUp","NP_Special1JESUp");  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NP_Special2JESUp","NP_Special2JESUp");  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NP_Special3JESUp","NP_Special3JESUp"); 
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NP_Special4JESUp","NP_Special4JESUp");  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NP_Special5JESUp","NP_Special5JESUp");  
  //where is in-situ 6?
  

  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","Eta_ModellingJESUp","Eta_ModellingJESUp");  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","Eta_TotStatJESUp","Eta_TotStatJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","HighPtJESUp","HighPtJESUp");
  
  
  
  //where is MC non-closure?
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","MuJESUp","MuJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","NPVJESUp","NPVJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","PilePtJESUp","PilePtJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","PileRhoJESUp","PileRhoJESUp");
  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","FlavCompJESUp","FlavCompJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","FlavRespJESUp","FlavRespJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","bJESUp","bJESUp");
  //where is push-through??
  
  
  
  
  //JES/JER/JMR/JMS (large-R jets)
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","FatJESUp","FatJESUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","JMSUp","JMSUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","FatJPTRUp","FatJPTRUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","FatJMRUp","FatJMRUp");
  

  //electrons  
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","ElecScaleUp","ElecScaleUp");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","ElecResolutionUp","ElecResolutionUp");
  
  //muons
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","MSUP","MSUP");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","IDUP","IDUP");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","MUONSCALEUP","MUONSCALEUP");
  
  //MET
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","ResoSoftTermsUp_ptHard","ResoSoftTermsUp_ptHard");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","ResoSoftTermsUpDown_ptHard","ResoSoftTermsUpDown_ptHard");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","ScaleSoftTermsUp_ptHard","ScaleSoftTermsUp_ptHard");
  
  //btag
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","btagforB","btagforB");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","btagforLight","btagforLight");
  a.addShapeSyst("sig,wjet,ttbar,stop,diboson,zjet","0","btagforC","btagforC");
  

  */





  
  
  //  */
  
  
  /*  
  //ptwlep
   a.setBinning(0,"1,21,31,41,51,81");
   a.setBinning(1,"1,21,31,36,81");
   a.setBinning(2,"1,21,31,41,81");
    */


  //  /*
  //VVvecptdiff  or mTWV
  // a.setBinning(0,"1,31,51,61,71,81,101,151");  //FJ
  //  a.setBinning(1,"1,31,51,61,71,81,101,151");
  // a.setBinning(2,"1,21,41,51,61,71,151");  //resolved
  //  a.setBinning(0,"1,31,51,61,71,151");  //resolved




  
  //This is what I've been using for my 14-bin fit, with SRfatOnly, SR+, SR-
  //for 10-GeV bins

  //a.setBinning(0,"1,61,71,81,151");  //SRfatOnly.  Optimized.
   ///////   //a.setBinning(1,"1,61,71,81,151");  //SRfatOnly.  Optimized.
  // a.setBinning(1,"1,31,51,61,71,151");  //SR. Optimized
  // a.setBinning(2,"1,31,51,61,71,151");  //SR. Optimized
  
  //for 100-GeV bins for optimized cuts for 40% systematics (also seems to be ~optimal for 10% systs):
  
  //a.setBinning(0,"1,7,8,9,16");  //SRfatOnly.  Optimized.

  a.setBinning(0,"4,7,8,9,16");  //SRfatOnly.  Optimized.
  a.setBinning(1,"1,4,6,7,8,16");  //SR. Optimized
  a.setBinning(2,"1,4,6,7,8,16");  //SR. Optimized
  
  


  
  // //for 100-GeV bins, for optimized cuts for 10% systematics:
//   a.setBinning(0,"1,7,8,9,10,16");  //SRfatOnly.  Optimized.
//   a.setBinning(1,"1,4,6,7,8,16");  //SR. Optimized
//   a.setBinning(2,"1,4,6,7,8,16");  //SR. Optimized









   //1-bin fit
  //a.setBinning(0,"9,16");  //SRfatOnly.  Optimized.
  //  a.setBinning(1,"8,16");  //SR. Optimized
  // a.setBinning(2,"8,16");  //SR. Optimized







   // a.setBinning(0,"1,7,8,9,16");  //SRfatOnly.  Optimized.
  // a.setBinning(0,"1,4,6,7,8,16");  //SR. Optimized
  // a.setBinning(1,"1,4,6,7,8,16");  //SR. Optimized

  //a.setBinning(2,"1,4,6,7,8,16");  //SR. Optimized









   //1-bin fit
//     a.setBinning(0,"81,151");  //SRfatOnly.  
//     a.setBinning(1,"71,151");  //SR. 
//     a.setBinning(2,"71,151");  //SR. 




  // a.setBinning(0,"61,151"); //resolved 1-bin
  
  //  */

//   a.setBinning(0,"16,18,20,22,24,26,36");
//   a.setBinning(1,"16,18,20,22,24,26,36");
//   a.setBinning(2,"16,18,20,22,24,26,36");

 



  //Njet
  //  a.setBinning(0,"5,7,9,10");
//   a.setBinning(1,"5,7,9,10");
//   a.setBinning(2,"5,7,9,10");



  /*
  //Mlvjj
  a.setBinning(0,"1,61,91,121,151");
  a.setBinning(1,"1,61,91,121,151");
  a.setBinning(2,"1,61,91,121,151");
  */


  
  /*
//MET
  a.setBinning(0,"1,31,41,51");
  a.setBinning(1,"1,31,41,51");
  a.setBinning(2,"1,31,41,51");
  */

   /*
//Mwjj
  a.setBinning(0,"13,14,15,16,17,18,19,20,21,22,23");
  //  a.setBinning(1,"14,15,16,17,18,19,20,21");
  //  a.setBinning(2,"14,15,16,17,18,19,20,21");
   */


  /*
  //mjjTagged
  a.setBinning(0,"8,16,26,41,76");  //SRfatOnly
  a.setBinning(1,"8,16,26,41,76");  //SRfatOnly
  //a.setBinning(2,"8,16,26,41,76"); //SR
  */

//   //etaY
//   a.setBinning(0,"11,16,19,21,23,30");
//   a.setBinning(1,"11,16,19,21,24,27,30");
//   a.setBinning(2,"11,16,19,21,23,26,30");
  
/*
 //bosonCentrality
  a.setBinning(0,"35,56,61,64,76");  //SRfatOnly
  a.setBinning(1,"35,56,61,64,76");  //SRfatOnly
  a.setBinning(2,"35,51,56,61,64,76"); //SR
  
*/

  /*
  a.setBinning(0,"35,56,61,64,76");  //SRfatOnly
  a.setBinning(1,"35,56,61,64,76");  //SRfatOnly
  a.setBinning(2,"35,51,56,61,64,76"); //SR
  */



/*
 //mT
  a.setBinning(0,"2,5,9,13,17,21,25,29");
  a.setBinning(1,"2,5,9,13,17,21,25,29");
  a.setBinning(2,"2,5,9,13,17,21,25,29");

  */



//    a.setBinning(2,"1,21,31,36,81");
  
  a.rebin();
  
  cout<<"Done rebinning"<<endl;
  
  a.enableQGC(1);
  //  a.enableQGC(1,2);   //for doing a 2D limit
  
  
  a.print(-1);
  
  //    a.plot(true,"pdf");
  a.plot(true,"pdfinclData");
  
  a.plotInterpolation();
  
  
  a.printNormSystematics(-1);  //summed over all categories
  
  a.printNormSystematics(0);  //individual category (SRfatOnly, etc)
  a.printNormSystematics(1); //individual category (SRfatOnly, etc)
  a.printNormSystematics(2);  //individual category (SRfatOnly, etc)
  
  

  a.plotCovMatrix(-1,2);
  a.plotSystematic(-1, false);
  
}


