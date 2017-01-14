{
  
  cout.precision(3);
  
  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.aTGC/hwwlvqq.WV_SM_rw.caf4.2.lv7_NEWcutflow.root"); 
  TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.aTGC/hwwlvqq.WV_0p1_0_0_rw.caf4.2.lv7_NEWcutflow.root");

  //TFile *f1=TFile::Open("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.root");




  f1->cd("CutFlow");
  
  //gDirectory->ls();
  TH1F* h1=(TH1F*) gDirectory -> Get("WWSM_CutFlow" );
  TH1F* h2=(TH1F*) gDirectory -> Get("WWaTGC_CutFlow" );
 
  
 


  //&&& getting em.ep.mm.mp for calculating s/sqrt(b)

  for (int i =1; i<100;i++){
    //  cout<<"  "<<h1->GetXaxis()->GetBinLabel(i)<<" "<<h1->GetBinContent(i)<<endl;
    //if (h2->GetXaxis()->GetBinLabel(i)=="m")cout<<"  "<<h2->GetXaxis()->GetBinLabel(i)<<" "<<h2->GetBinContent(i)<<"  "<< h2->GetBinError(i)<<endl;
    //cout<<h2->GetBinContent(i)<<"  "<< h2->GetBinError(i)<<endl;

    std::string str = h1->GetXaxis()->GetBinLabel(i);
    //cout<<str<<endl;
    if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h1->GetXaxis()->GetBinLabel(i)<<" "<<h1->GetBinContent(i)<<"  "<<h1->GetBinError(i)<<endl;
    //if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h2->GetBinContent(i)<<"  "<<h2->GetBinError(i)<<endl;
    //if (str.find("MJJResolve")!=-1 || str.find("OLRemovalFat")!=-1)  cout<<h2->GetBinError(i)<<endl;
  }
 
  //f->Close();
  //f1->Close();

}
