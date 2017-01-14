{
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_cutflow.root");
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_New_all97.root");

  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_sig4/hwwlvqq.JERUp.root");
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NEW_10/hwwlvqq.Nominal.small.root");
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20_NEW_10.root");

  TFile *f=TFile::Open("/export/home/blindqui/analysis/VBS/ForAungshuman/hwwlvqq.Nominal.TopCRandWjetsCR.smoothed.28Apr2016.root");

  TIter next(f->GetListOfKeys());
  TKey *key;
  TCanvas c1;
  //c1.Print("hsimple.pdf[");
  while ((key = (TKey*)next())) {
    TClass *cl = gROOT->GetClass(key->GetClassName());
    if (!cl->InheritsFrom("TH1")) continue;
    TH1 *h = (TH1*)key->ReadObj();
    TString NAME = h->GetName();
    //if(  NAME.Contains("H_VBS_WV_0_0_ep")  ) cout<<h->GetName()<<endl;
    //if(  NAME.Contains("H_Ttbar_ep_WBF_CR_WjjfatOnly_mTWV") ) cout<<h->GetName()<<endl;
    //if(  NAME.Contains("H_VBS_WV_0_0_ep_WBF_CR_Top_") ) cout<<h->GetName()<<endl;
    if( NAME.Contains("H_Ttbar_ep") && NAME.Contains("CR_Top_")) cout<<h->GetName()<<endl;
    //cout<<TString (h->GetName()) <<endl;
    /*
    int nbin = h->GetNbinsX();
    //cout<<nbin<<endl;
    
      for (int ibin =1; ibin< nbin; ibin++){
	//if (h->GetBinContent(ibin) !=0) {
	//if (TString(h->GetName()) =="145161_CutFlow") {
	//if (TString(h->GetXaxis()->GetBinLabel(ibin)) =="mp_WBF_STARTPOINT") {
	  if (TString(h->GetXaxis()->GetBinLabel(ibin)) =="mp_WBF_PRESELECT") {
	  
	  cout<<h->GetName()<<" "<<h->GetXaxis()->GetBinLabel(ibin)<<" : ";
	  cout<<h->GetBinContent(ibin)<<endl;
	  break;
	  }
	  //}
    }
    */
    //h->Draw();
    //c1.Print("hsimple.pdf");
  }
  //c1.Print("hsimple.pdf]");
}
