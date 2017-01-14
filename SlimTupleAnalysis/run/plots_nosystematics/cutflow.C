{
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_fat12_noveto.root"); //bkg
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_fat12_noveto_signalOnly.root"); //signal
  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_fat12_veto.root"); //bkg
  //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_fat12_veto_signalOnly.root"); //signal

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.2.root"); 
  TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.2.root");

 


  f1->cd("CutFlow");
  TH1F* h2=(TH1F*) gDirectory -> Get("VBS_WV_0_0_CutFlow" );

  f->cd("CutFlow");
  
  //gDirectory->ls();
  TH1F* h1=(TH1F*) gDirectory -> Get("Ttbar_CutFlow" );
  TH1F* h3=(TH1F*) gDirectory -> Get("SingleTop_CutFlow" );
  TH1F* h4=(TH1F*) gDirectory -> Get("Wjets_CutFlow" );
  TH1F* h5=(TH1F*) gDirectory -> Get("Zjets_CutFlow" );
  TH1F* h6=(TH1F*) gDirectory -> Get("WZZZWg_CutFlow" );
  
  
  std::ofstream os("out.log");
  
  // cout<<"Ttbar  : "<<h1->GetXaxis()->GetBinLabel(6)<<" = "<<h1->GetBinContent(6)<<endl;
  // cout<<"       : "<<h1->GetXaxis()->GetBinLabel(7)<<" = "<<h1->GetBinContent(7)<<endl;
  // //cout<<"         ratio = "<<h1->GetBinContent(7)*100/h1->GetBinContent(6)<<" %"<<endl;
  // cout<<"signal : "<<h2->GetXaxis()->GetBinLabel(6)<<" = "<<h2->GetBinContent(6)<<endl;
  // cout<<"       : "<<h2->GetXaxis()->GetBinLabel(7)<<" = "<<h2->GetBinContent(7)<<endl;
  // //cout<<"         ratio = "<<h2->GetBinContent(7)*100/h2->GetBinContent(6)<<" %"<<endl;
  
  // cout<<"Ttbar  : "<<h1->GetXaxis()->GetBinLabel(14)<<" = "<<h1->GetBinContent(14)<<endl;
  // cout<<"       : "<<h1->GetXaxis()->GetBinLabel(15)<<" = "<<h1->GetBinContent(15)<<endl;
  // //cout<<"         ratio = "<<h1->GetBinContent(15)*100/h1->GetBinContent(14)<<" %"<<endl;
  // cout<<"signal : "<<h2->GetXaxis()->GetBinLabel(14)<<" = "<<h2->GetBinContent(14)<<endl;
  // cout<<"       : "<<h2->GetXaxis()->GetBinLabel(15)<<" = "<<h2->GetBinContent(15)<<endl;
  // //cout<<"         ratio = "<<h2->GetBinContent(15)*100/h2->GetBinContent(14)<<" %"<<endl;

  // cout<<"Ttbar  : "<<h1->GetXaxis()->GetBinLabel(22)<<" = "<<h1->GetBinContent(22)<<endl;
  // cout<<"       : "<<h1->GetXaxis()->GetBinLabel(23)<<" = "<<h1->GetBinContent(23)<<endl;
  // //cout<<"         ratio = "<<h1->GetBinContent(23)*100/h1->GetBinContent(22)<<" %"<<endl;
  // cout<<"signal : "<<h2->GetXaxis()->GetBinLabel(22)<<" = "<<h2->GetBinContent(22)<<endl;
  // cout<<"       : "<<h2->GetXaxis()->GetBinLabel(23)<<" = "<<h2->GetBinContent(23)<<endl;
  // //cout<<"         ratio = "<<h2->GetBinContent(23)*100/h2->GetBinContent(22)<<" %"<<endl;
  
  // cout<<"Ttbar  : "<<h1->GetXaxis()->GetBinLabel(30)<<" = "<<h1->GetBinContent(30)<<endl;
  // cout<<"       : "<<h1->GetXaxis()->GetBinLabel(31)<<" = "<<h1->GetBinContent(31)<<endl;
  // //cout<<"         ratio = "<<h1->GetBinContent(31)*100/h1->GetBinContent(30)<<" %"<<endl;
  // cout<<"signal : "<<h2->GetXaxis()->GetBinLabel(30)<<" = "<<h2->GetBinContent(30)<<endl;
  // cout<<"       : "<<h2->GetXaxis()->GetBinLabel(31)<<" = "<<h2->GetBinContent(31)<<endl;
  // //cout<<"         ratio = "<<h2->GetBinContent(31)*100/h2->GetBinContent(30)<<" %"<<endl;

  // os<<"Ttbar  : "<<h1->GetXaxis()->GetBinLabel(6)<<" = "<<h1->GetBinContent(6)<<endl;
  // os<<"       : "<<h1->GetXaxis()->GetBinLabel(7)<<" = "<<h1->GetBinContent(7)<<endl;
  // os<<"         ratio = "<<h1->GetBinContent(7)*100/h1->GetBinContent(6)<<" %"<<endl;
  // os<<"signal : "<<h2->GetXaxis()->GetBinLabel(6)<<" = "<<h2->GetBinContent(6)<<endl;
  // os<<"       : "<<h2->GetXaxis()->GetBinLabel(7)<<" = "<<h2->GetBinContent(7)<<endl;
  // os<<"         ratio = "<<h2->GetBinContent(7)*100/h2->GetBinContent(6)<<" %"<<endl;

  // os.close();


  //&&& getting em.ep.mm.mp for calculating s/sqrt(b)

  cout<<"signal "<<h2->GetXaxis()->GetBinLabel(8)<<" "<<h2->GetBinContent(8)<<endl;
  cout<<"       "<<h2->GetXaxis()->GetBinLabel(16)<<" "<<h2->GetBinContent(16)<<endl;
  cout<<"       "<<h2->GetXaxis()->GetBinLabel(24)<<" "<<h2->GetBinContent(24)<<endl;
  cout<<"       "<<h2->GetXaxis()->GetBinLabel(32)<<" "<<h2->GetBinContent(32)<<endl;
  
  cout<<"ttbar  "<<h1->GetXaxis()->GetBinLabel(8)<<" "<<h1->GetBinContent(8)<<endl;
  cout<<"       "<<h1->GetXaxis()->GetBinLabel(16)<<" "<<h1->GetBinContent(16)<<endl;
  cout<<"       "<<h1->GetXaxis()->GetBinLabel(24)<<" "<<h1->GetBinContent(24)<<endl;
  cout<<"       "<<h1->GetXaxis()->GetBinLabel(32)<<" "<<h1->GetBinContent(32)<<endl;

  cout<<"singleTop "<<h3->GetXaxis()->GetBinLabel(8)<<" "<<h3->GetBinContent(8)<<endl;
  cout<<"       "<<h3->GetXaxis()->GetBinLabel(16)<<" "<<h3->GetBinContent(16)<<endl;
  cout<<"       "<<h3->GetXaxis()->GetBinLabel(24)<<" "<<h3->GetBinContent(24)<<endl;
  cout<<"       "<<h3->GetXaxis()->GetBinLabel(32)<<" "<<h3->GetBinContent(32)<<endl;
  
  cout<<"W+jets "<<h4->GetXaxis()->GetBinLabel(8)<<" "<<h4->GetBinContent(8)<<endl;
  cout<<"       "<<h4->GetXaxis()->GetBinLabel(16)<<" "<<h4->GetBinContent(16)<<endl;
  cout<<"       "<<h4->GetXaxis()->GetBinLabel(24)<<" "<<h4->GetBinContent(24)<<endl;
  cout<<"       "<<h4->GetXaxis()->GetBinLabel(32)<<" "<<h4->GetBinContent(32)<<endl;

  cout<<"Z+jets  "<<h5->GetXaxis()->GetBinLabel(8)<<" "<<h5->GetBinContent(8)<<endl;
  cout<<"       "<<h5->GetXaxis()->GetBinLabel(16)<<" "<<h5->GetBinContent(16)<<endl;
  cout<<"       "<<h5->GetXaxis()->GetBinLabel(24)<<" "<<h5->GetBinContent(24)<<endl;
  cout<<"       "<<h5->GetXaxis()->GetBinLabel(32)<<" "<<h5->GetBinContent(32)<<endl;
  
  cout<<"Diboson "<<h6->GetXaxis()->GetBinLabel(8)<<" "<<h6->GetBinContent(8)<<endl;
  cout<<"       "<<h6->GetXaxis()->GetBinLabel(16)<<" "<<h6->GetBinContent(16)<<endl;
  cout<<"       "<<h6->GetXaxis()->GetBinLabel(24)<<" "<<h6->GetBinContent(24)<<endl;
  cout<<"       "<<h6->GetXaxis()->GetBinLabel(32)<<" "<<h6->GetBinContent(32)<<endl;

  f->Close();
  f1->Close();

}
