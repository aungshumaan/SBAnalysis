{
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_cutflow.root");
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_New_all97.root");

  TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst_lumi20.2/hwwlvqq.cutflow.root");
  //TFile *f = TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst_lumi20.2/hwwlvqq.all97.root");
  TDirectory *d2 =f->GetDirectory("CutFlow");
  //d2->ls();
  TIter next(d2->GetListOfKeys());
  TKey *key;
  TCanvas c1;
  //c1.Print("hsimple.pdf[");
  while ((key = (TKey*)next())) {
    TClass *cl = gROOT->GetClass(key->GetClassName());
    if (!cl->InheritsFrom("TH1")) continue;
    TH1 *h = (TH1*)key->ReadObj();
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
    //h->Draw();
    //c1.Print("hsimple.pdf");
  }
  //c1.Print("hsimple.pdf]");
}
