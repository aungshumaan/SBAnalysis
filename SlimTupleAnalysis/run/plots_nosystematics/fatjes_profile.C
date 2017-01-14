{
  #include "TLatex.h"
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  c2->Print("plots_jesSf.pdf[");
  gStyle->SetOptStat(0);
  
  TFile *f = TFile::Open("~azaman/CAFProd/HWWlvqqCode/external/UJInput2012.root");
  TH3F *h3_pts = (TH3F*) f->Get("CamKt12LCTopoSplitFilteredmassFraction67minSplitR0_pT");
  TH3F *h3_ms  = (TH3F*) f->Get("CamKt12LCTopoSplitFilteredmassFraction67minSplitR0_m");
  
  /*
  int nbinsx =h3_pts ->GetXaxis()->GetNbins();
  int nbinsy =h3_pts ->GetYaxis()->GetNbins();
  int nbinsz =h3_pts ->GetZaxis()->GetNbins();
  //cout<<h3_pts ->GetXaxis()->GetNbins()<<endl;
  //cout<<h3_pts ->GetYaxis()->GetNbins()<<endl;
  //cout<<h3_pts ->GetZaxis()->GetNbins()<<endl;
  cout<<h3_ms ->GetXaxis()->GetNbins()<<endl;
  cout<<h3_ms ->GetYaxis()->GetNbins()<<endl;
  cout<<h3_ms ->GetZaxis()->GetNbins()<<endl;

  //cout<<h3_pts ->GetNbinsX()<<endl;
  // cout<<h3_pts ->GetNbinsY()<<endl;
  //cout<<h3_pts ->GetNbinsZ()<<endl;
  
  // TH1D* h_pts= (TH1D*)h3_pts-> ProjectionX ("h_pts",1,nbinsy,1,nbinsz);
  //TProfile* h_ms= (TProfile*)h3_ms-> ProfileX ("h_ms");

  //h_pts -> Draw();
  
    
  h3_pts -> Draw("colz");
  h3_pts -> GetXaxis()->SetRangeUser(0,1000.);
  h3_pts -> GetYaxis()->SetRangeUser(0,1.);
  h3_pts -> GetZaxis()->SetRangeUser(0,1.2);
  //c2->Print("plots_jesSf.pdf");   

  TH2F* hxy_pts =(TH2F*)h3_pts->Project3D("yx");
  hxy_pts->GetXaxis()->SetRangeUser(0,1000.);
  hxy_pts->GetYaxis()->SetRangeUser(0,1.);
  hxy_pts ->Draw("colz");
  //c2->Print("plots_jesSf.pdf");   
  
  TH1F* hx_pts =(TH1F*)h3_pts->Project3D("xe");
  hx_pts ->Draw();
  hx_pts->GetXaxis()->SetRangeUser(0,1000.);
  //c2->Print("plots_jesSf.pdf");
  TH1F* hy_pts =(TH1F*)h3_pts->Project3D("ye");
  hy_pts ->Draw();
  hy_pts->GetXaxis()->SetRangeUser(0,1.);
  //c2->Print("plots_jesSf.pdf");
  TH1F* hz_pts =(TH1F*)h3_pts->Project3D("ze");
  hz_pts->GetXaxis()->SetRangeUser(0.,1.2);
  hz_pts ->Draw();
  //c2->Print("plots_jesSf.pdf");   
  */


  TH1F* hprojx_pts =(TH1F*)h3_pts->ProjectionX("_x",0.,1.,0.,1.2);
  //TH1F* hprojx_pts =(TH1F*)h3_pts->ProjectionX();
  hprojx_pts ->Draw();
  hprojx_pts->GetXaxis()->SetRangeUser(0,1000.);
  hprojx_pts->GetXaxis()->SetTitle("fatjet p_{t} [GeV] ");
  c2->Print("plots_jesSf.pdf");
  //cout<<"hprojx_pts "<<hprojx_pts->Integral()<<endl;
  cout<<"bin width "<<hprojx_pts->GetBinWidth(1)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(1)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(2)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(2)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(3)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(3)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(4)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(4)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(5)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(5)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(6)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(6)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(7)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(7)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(8)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(8)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(9)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(9)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(10)<<endl;
  cout<<"hprojx_pts "<<hprojx_pts->GetBinContent(10)<<endl;
    cout<<"bin width "<<hprojx_pts->GetBinWidth(11)<<endl;

    cout<<"hprojx_pts integral  "<<hprojx_pts->Integral()<<endl;
  //cout<<"hprojx_pts bin content "<<hprojy_pts->GetBinContent(3)<<endl;
  
    cout<<"h3_pts integral "<<h3_pts->Integral()<<endl;
  int nx= h3_pts->GetNbinsX();
  int ny= h3_pts->GetNbinsY();
  int nz= h3_pts->GetNbinsZ();
  double integ =0.;
  for (int iz =1; iz<= nz; iz++){
    for (int iy =1; iy<= ny; iy++){
      //for (int ix =1; ix<= nx; ix++){
	integ += h3_pts->GetBinContent(3,iy,iz);
	//cout<< h3_pts->GetBinContent(1,iy,iz) <<endl;
	//}
    }
  }
  cout<<"Summing "<<integ<<endl;
  cout<<"Average "<<integ/(ny*nz)<<endl;
  

  TH1F* hprojy_pts =(TH1F*)h3_pts->ProjectionY("_y",0.,1000.,0.,1.2);
  //TH1F* hprojy_pts =(TH1F*)h3_pts->ProjectionY();
  hprojy_pts ->Draw();
  hprojy_pts->GetXaxis()->SetRangeUser(0,1.);
  hprojy_pts->GetXaxis()->SetTitle("fatjet mass [TeV] ");
  c2->Print("plots_jesSf.pdf");
  //cout<<"hprojy_pts integral  "<<hprojy_pts->Integral()<<endl;
  //cout<<"hprojy_pts bin content "<<hprojy_pts->GetBinContent(3)<<endl;

  //TH1F* hprojz_pts =(TH1F*)h3_pts->ProjectionZ("_z",0.,1000.,0.,1.);
  TH1F* hprojz_pts =(TH1F*)h3_pts->ProjectionZ();
  hprojz_pts ->Draw();
  hprojz_pts->GetXaxis()->SetRangeUser(0,1.2);
  hprojz_pts->GetXaxis()->SetTitle("fatjet #eta ");
  c2->Print("plots_jesSf.pdf");
  //cout<<"hprojz_pts "<<hprojz_pts->Integral()<<endl;
  
  /*
  h3_pts -> Draw("colz");
  h3_pts -> GetXaxis()->SetRangeUser(0,1000.);
  h3_pts -> GetYaxis()->SetRangeUser(0,1.);
  h3_pts -> GetZaxis()->SetRangeUser(0,1.2);
  //c2->Print("plots_jesSf.pdf");   
  */

  TH1F* hprojx_ms =(TH1F*)h3_ms->ProjectionX("_x",0.,1.,0.,1.2);
  hprojx_ms ->Draw();
  hprojx_ms->GetXaxis()->SetRangeUser(0,1000.);
  hprojx_ms->GetXaxis()->SetTitle("fatjet p_{t} [GeV] ");
  c2->Print("plots_jesSf.pdf");
  
  TH1F* hprojy_ms =(TH1F*)h3_ms->ProjectionY("_y",0.,1000.,0.,1.2);
  hprojy_ms ->Draw();
  hprojy_ms->GetXaxis()->SetRangeUser(0,1.);
  hprojy_ms->GetXaxis()->SetTitle("fatjet mass [TeV] ");
  c2->Print("plots_jesSf.pdf");
  
  TH1F* hprojz_ms =(TH1F*)h3_ms->ProjectionZ("_z",0.,1000.,0.,1.);
  hprojz_ms ->Draw();
  hprojz_ms->GetXaxis()->SetRangeUser(0,1.2);
  hprojz_ms->GetXaxis()->SetTitle("fatjet #eta ");
  c2->Print("plots_jesSf.pdf");
  
  
  
  c2->Print("plots_jesSf.pdf]");   
  
}
