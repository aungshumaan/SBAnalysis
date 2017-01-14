{
  TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
  TH1F *h1,*h2,*h3;
  TGraph *gr;
  TFile *f1= TFile::Open("~azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lep30_met30_mjj0_mt40_diboson_emfrac.root");

  h1=(TH1F*)f1->Get("H_WW_mp_WBF_SR_jet_emfrac" );
  
  h1->Add( (TH1F*)f1->Get("H_WW_mm_WBF_SR_jet_emfrac" ) );

  h2=(TH1F*)f1->Get("H_WZ_mp_WBF_SR_jet_emfrac" );
  h2->Add( (TH1F*)f1->Get("H_WZ_mm_WBF_SR_jet_emfrac" ) );

  h3=(TH1F*)f1->Get("H_Wgamma_mp_WBF_SR_jet_emfrac" );
  h3->Add( (TH1F*)f1->Get("H_Wgamma_mm_WBF_SR_jet_emfrac" ) );

  //h1->Draw();

  Int_t lastbin=0; //150 means all, 120--> 1.0, 119-->0.99 etc
 

  Double_t x[200], y[200];
 
  for ( lastbin=50;lastbin<=125;lastbin++) {

    //cout<<h1->GetXaxis()->GetBinLowEdge(lastbin+1)<<endl;
    //cout<<h1->Integral(1,lastbin)<<" "<<h2->Integral(1,lastbin)<<" "<<h3->Integral(1,lastbin)<<endl;
    x[lastbin-50] = h1->GetXaxis()->GetBinLowEdge(lastbin+1);
    //if (sqrt(h3->Integral(1,lastbin))==0){y[lastbin-50] =0.;}
    // else{  y[lastbin-50] =  ( h1->Integral(1,lastbin)+h2->Integral(1,lastbin) )/sqrt(h3->Integral(1,lastbin));}
     if (h3->Integral(1,lastbin)==0){y[lastbin-50] =0.;}
     else{  y[lastbin-50] =  ( h1->Integral(1,lastbin)+h2->Integral(1,lastbin) )/h3->Integral(1,lastbin);}
    cout<<lastbin<<"-->"<<x[lastbin-50]<<":"<<y[lastbin-50]<<endl;
  }
  gr = new TGraph(75,x,y);
  gr->GetXaxis()->SetTitle("em fraction cut");
  gr->GetYaxis()->SetTitle("(WW+WZ)/(Wg)");
  //gr->GetYaxis()->SetTitle("(WW+WZ)/sqrt(Wg)");
 
  gr->Draw("AC*");

  c1->Print("c1.pdf","pdf");
  f1->Close();
}
