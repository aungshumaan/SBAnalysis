{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Nov 12 14:09:30 2014) by ROOT version5.34/19
   TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
   c1->Range(-6.375001,-12177.14,67.375,109594.2);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);

   //TH1::SetDefaultSumw2();

   TFile *_file0 = TFile::Open("../hwwlvqq_az_alpgenWjets.root");
   //electron
   // TH1D *h=_file0->Get("CutFlow/147025_CutFlow");
   // TH1D *h1=_file0->Get("CutFlow/147026_CutFlow");
   // TH1D *h2=_file0->Get("CutFlow/147027_CutFlow");
   // TH1D *h3=_file0->Get("CutFlow/147028_CutFlow");
   // TH1D *h4=_file0->Get("CutFlow/147029_CutFlow");
   // TH1D *h5=_file0->Get("CutFlow/147030_CutFlow");

   //mu
   TH1D *h=_file0->Get("CutFlow/147033_CutFlow");
   TH1D *h1=_file0->Get("CutFlow/147034_CutFlow");
   TH1D *h2=_file0->Get("CutFlow/147035_CutFlow");
   TH1D *h3=_file0->Get("CutFlow/147036_CutFlow");
   TH1D *h4=_file0->Get("CutFlow/147037_CutFlow");
   TH1D *h5=_file0->Get("CutFlow/147038_CutFlow");

   TH1D *hh = new TH1D ("hh","hh",10,0.,10.);
   //hh->Sumw2(kTRUE);
   // for(int i=1;i<h->GetNbinsX();i++){
   //   cout<<"bin["<<i <<"] = "<<h->GetBinContent(i)<<endl;
   //   cout<<"sqrt bin content["<<i <<"] = "<<sqrt(h->GetBinContent(i))<<endl;
   //   cout<<"bin error ["<<i <<"] = "<<h->GetBinError(i)<<endl;
   //   cout<<"scale ="<<h->GetBinError(i)/sqrt(h->GetBinContent(i))<<endl;
   //   //cout<<"electron = "<<h->GetBinContent(1)+h->GetBinContent(11)<<endl;
   //   //cout<<"muon = "<<h->GetBinContent(21)+h->GetBinContent(31)<<endl;
   //   }

   //PRESELECT level
   // cout<<"electron = "<<h->GetBinContent(1)+h->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h->GetBinContent(21)+h->GetBinContent(31)<<endl;
   // hh->SetBinContent(1,h->GetBinContent(1)+h->GetBinContent(11));
   // //hh->SetBinError(1,sqrt(h->GetBinContent(1)+h->GetBinContent(11)));
   // hh->SetBinError(1,sqrt(h->GetBinContent(1)+h->GetBinContent(11)));
   // cout<<"electron = "<<h1->GetBinContent(1)+h1->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h1->GetBinContent(21)+h1->GetBinContent(31)<<endl;
   // hh->SetBinContent(2,h1->GetBinContent(1)+h1->GetBinContent(11));
   // hh->SetBinError(2,sqrt(h1->GetBinContent(1)+h1->GetBinContent(11)));
   // cout<<"electron = "<<h2->GetBinContent(1)+h2->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h2->GetBinContent(21)+h2->GetBinContent(31)<<endl;
   // hh->SetBinContent(3,h2->GetBinContent(1)+h2->GetBinContent(11));
   // hh->SetBinError(3,sqrt(h2->GetBinContent(1)+h2->GetBinContent(11)));
   // cout<<"electron = "<<h3->GetBinContent(1)+h3->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h3->GetBinContent(21)+h3->GetBinContent(31)<<endl;
   // hh->SetBinContent(4,h3->GetBinContent(1)+h3->GetBinContent(11));
   // hh->SetBinError(4,sqrt(h3->GetBinContent(1)+h3->GetBinContent(11)));
   // cout<<"electron = "<<h4->GetBinContent(1)+h4->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h4->GetBinContent(21)+h4->GetBinContent(31)<<endl;
   // hh->SetBinContent(5,h4->GetBinContent(1)+h4->GetBinContent(11));
   // hh->SetBinError(5,sqrt(h4->GetBinContent(1)+h4->GetBinContent(11)));
   // cout<<"electron = "<<h5->GetBinContent(1)+h5->GetBinContent(11)<<endl;
   // cout<<"muon = "<<h5->GetBinContent(21)+h5->GetBinContent(31)<<endl;
   // hh->SetBinContent(6,h5->GetBinContent(1)+h5->GetBinContent(11));
   // hh->SetBinError(6,sqrt(h5->GetBinContent(1)+h5->GetBinContent(11)));

   //WJET level 
   // cout<<"electron = "<<h->GetBinContent(4)+h->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h->GetBinContent(24)+h->GetBinContent(34)<<endl;
   // cout<<"electron = "<<h1->GetBinContent(4)+h1->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h1->GetBinContent(24)+h1->GetBinContent(34)<<endl;
   // cout<<"electron = "<<h2->GetBinContent(4)+h2->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h2->GetBinContent(24)+h2->GetBinContent(34)<<endl;
   // cout<<"electron = "<<h3->GetBinContent(4)+h3->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h3->GetBinContent(24)+h3->GetBinContent(34)<<endl;
   // cout<<"electron = "<<h4->GetBinContent(4)+h4->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h4->GetBinContent(24)+h4->GetBinContent(34)<<endl;
   // cout<<"electron = "<<h5->GetBinContent(4)+h5->GetBinContent(14)<<endl;
   // cout<<"muon = "<<h5->GetBinContent(24)+h5->GetBinContent(34)<<endl;

   //electron
   // hh->SetBinContent(1,h->GetBinContent(4)+h->GetBinContent(14));
   // hh->SetBinError(1,sqrt(h->GetBinError(4)*h->GetBinError(4)+h->GetBinError(14)*h->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(1,"WenuNp0");
 
   // hh->SetBinContent(2,h1->GetBinContent(4)+h1->GetBinContent(14));
   // hh->SetBinError(2,sqrt(h1->GetBinError(4)*h1->GetBinError(4)+h1->GetBinError(14)*h1->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(2,"WenuNp1");
 
   // hh->SetBinContent(3,h2->GetBinContent(4)+h2->GetBinContent(14));
   // hh->SetBinError(3,sqrt(h2->GetBinError(4)*h2->GetBinError(4)+h2->GetBinError(14)*h2->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(3,"WenuNp2");
  
   // hh->SetBinContent(4,h3->GetBinContent(4)+h3->GetBinContent(14));
   // hh->SetBinError(4,sqrt(h3->GetBinError(4)*h3->GetBinError(4)+h3->GetBinError(14)*h3->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(4,"WenuNp3");
 
   // hh->SetBinContent(5,h4->GetBinContent(4)+h4->GetBinContent(14));
   // hh->SetBinError(5,sqrt(h4->GetBinError(4)*h4->GetBinError(4)+h4->GetBinError(14)*h4->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(5,"WenuNp4");

   // hh->SetBinContent(6,h5->GetBinContent(4)+h5->GetBinContent(14));
   // hh->SetBinError(6,sqrt(h5->GetBinError(4)*h5->GetBinError(4)+h5->GetBinError(14)*h5->GetBinError(14)));
   // hh->GetXaxis()->SetBinLabel(6,"WenuNp5");

   //mu
   hh->SetBinContent(1,h->GetBinContent(24)+h->GetBinContent(34));
   hh->SetBinError(1,sqrt(h->GetBinError(24)*h->GetBinError(24)+h->GetBinError(34)*h->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(1,"WmunuNp0");
 
   hh->SetBinContent(2,h1->GetBinContent(24)+h1->GetBinContent(34));
   hh->SetBinError(2,sqrt(h1->GetBinError(24)*h1->GetBinError(24)+h1->GetBinError(34)*h1->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(2,"WmunuNp1");
 
   hh->SetBinContent(3,h2->GetBinContent(24)+h2->GetBinContent(34));
   hh->SetBinError(3,sqrt(h2->GetBinError(24)*h2->GetBinError(24)+h2->GetBinError(34)*h2->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(3,"WmunuNp2");
  
   hh->SetBinContent(4,h3->GetBinContent(24)+h3->GetBinContent(34));
   hh->SetBinError(4,sqrt(h3->GetBinError(24)*h3->GetBinError(24)+h3->GetBinError(34)*h3->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(4,"WmunuNp3");
 
   hh->SetBinContent(5,h4->GetBinContent(24)+h4->GetBinContent(34));
   hh->SetBinError(5,sqrt(h4->GetBinError(24)*h4->GetBinError(24)+h4->GetBinError(34)*h4->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(5,"WmunuNp4");

   hh->SetBinContent(6,h5->GetBinContent(24)+h5->GetBinContent(34));
   hh->SetBinError(6,sqrt(h5->GetBinError(24)*h5->GetBinError(24)+h5->GetBinError(34)*h5->GetBinError(34)));
   hh->GetXaxis()->SetBinLabel(6,"WmunuNp5");
   
   
    // cout<<"electron bincontent = "<<(h->GetBinContent(4))<<endl;
    // cout<<"electron error = "<<h->GetBinError(4)<<endl;
    // cout<<"electron sqrt(bincontent) = "<<sqrt(h->GetBinContent(4))<<endl;
   
     
   // h->GetXaxis()->SetLabelFont(42);
   // h->GetXaxis()->SetLabelSize(0.035);
   // h->GetXaxis()->SetTitleSize(0.035);
   // h->GetXaxis()->SetTitleFont(42);
   // h->GetYaxis()->SetLabelFont(42);
   // h->GetYaxis()->SetLabelSize(0.035);
   // h->GetYaxis()->SetTitleSize(0.035);
   // h->GetYaxis()->SetTitleFont(42);
   // h->GetZaxis()->SetLabelFont(42);
   // h->GetZaxis()->SetLabelSize(0.035);
   // h->GetZaxis()->SetTitleSize(0.035);
   // h->GetZaxis()->SetTitleFont(42);
   hh->Draw("E1");
   
   

   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->Print("plots_nevents_np.pdf");
}
