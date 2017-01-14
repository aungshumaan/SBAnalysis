{

  //TFile *f = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_NEWcutflow.root");
  TFile *f = TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_all97.root");
  
  
  f->cd("CutFlow");
  //gDirectory->ls();
  TH1F* h1=(TH1F*) gDirectory -> Get("VBS_WV_0_0_CutFlow" );
  TH1F* h2=(TH1F*) gDirectory -> Get("VBS_WV_0_01_CutFlow" );
  TH1F* h3=(TH1F*) gDirectory -> Get("Ttbar_CutFlow" );
  TH1F* h4=(TH1F*) gDirectory -> Get("Wjets_CutFlow" );
  
  //TH1F* h1 = (TH1F*)f->Get("CutFlow/VBS_WV_0_0_CutFlow");
  //h1->Draw();
  //TFile *fout =TFile::Open("fout.root","recreate");
  //fout->cd();
  //h1->Write();
  //TH1* h2 = (TH1*)h1->Clone("h");
  //fout->cd();
  //h2->Write();
  
  
  for (int i =1; i<100;i++){
    //  cout<<"  "<<h1->GetXaxis()->GetBinLabel(i)<<" "<<h1->GetBinContent(i)<<endl;
    //if (h2->GetXaxis()->GetBinLabel(i)=="m")cout<<"  "<<h2->GetXaxis()->GetBinLabel(i)<<" "<<h2->GetBinContent(i)<<"  "<< h2->GetBinError(i)<<endl;
    //cout<<h2->GetBinContent(i)<<"  "<< h2->GetBinError(i)<<endl;
    
    std::string str = h1->GetXaxis()->GetBinLabel(i);
    //cout<<str<<endl;
    //if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h1->GetXaxis()->GetBinLabel(i)<<" "<<h1->GetBinContent(i)<<"  "<<h1->GetBinError(i)<<endl;
    //if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h1->GetBinContent(i)<<"  "<<h1->GetBinError(i)<<"  "<<h2->GetBinContent(i)<<endl;
    if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h3->GetBinContent(i)<<"  "<<h3->GetBinError(i)<<"  "<<h4->GetBinContent(i)<<" "<<h4->GetBinError(i)<<endl;
    //if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h2->GetBinError(i)<<endl;
  }
  
}
