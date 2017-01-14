{
  TCanvas *c2 = new TCanvas("","",0,0,750,700);
  //c2->Print("plots_histfitter_shape.pdf"); //&&&&
  gStyle->SetOptStat(0);
  TFile *f=TFile::Open("/export/home/azaman/HistFitterTutorial/data/MyShapeFitExample_mine.root");
  //gDirectory->ls();
  TH1F* httbar = (TH1F*)f -> Get("httbarNom_SR_obs_mjjTagged");
  TH1F* hwjets = (TH1F*)f -> Get("hWjetsNom_SR_obs_mjjTagged");
  TH1F* hzjets = (TH1F*)f -> Get("hZjetsNom_SR_obs_mjjTagged");
  TH1F* hsingletop = (TH1F*)f -> Get("hsingletopNom_SR_obs_mjjTagged");
  TH1F* hdiboson = (TH1F*)f -> Get("hdibosonNom_SR_obs_mjjTagged");
  TH1F* hsig = (TH1F*)f -> Get("hsigNom_SR_obs_mjjTagged");
  
  httbar->Draw();
  httbar->SetLineColor(kYellow);
  httbar->Scale(1/httbar->Integral());

  hwjets->Draw("same");
  hwjets->SetLineColor(kCyan);
  hwjets->Scale(1/hwjets->Integral());
    
  hzjets->Draw("same");
  hzjets->SetLineColor(kBlue);
  hzjets->Scale(1/hzjets->Integral());

  hdiboson->Draw("same");
  hdiboson->SetLineColor(kMagenta+2);
  hdiboson->Scale(1/hdiboson->Integral());

  hsingletop->Draw("same");
  hsingletop->SetLineColor(kYellow-5);
  hsingletop->Scale(1/hsingletop->Integral());

  hsig->Draw("same");
  hsig->SetLineColor(kRed);
  hsig->Scale(1/hsig->Integral());

  TLegend *leg = new TLegend(0.6, 0.70, 0.9, 0.88) ;
  leg->SetNColumns(2);
  
  
  leg->AddEntry(hwjets,"W+jets","l");
  leg->AddEntry(hzjets,"Z+jets","l");
  leg->AddEntry(hdiboson,"Di-boson","l");
  leg->AddEntry(hsingletop,"single top","l");
  leg->AddEntry(httbar,"ttbar","l");

  leg->Draw();


  c2->Print("plots_histfitter_shape.pdf"); //&&&&
}
