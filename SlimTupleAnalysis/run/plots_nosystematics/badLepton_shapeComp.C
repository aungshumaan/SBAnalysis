{

  ///this code is for comparing QCD in QCD enriched region, before and after bad lepton bug fix. 7/29/14 
  TCanvas *c1 = new TCanvas("c1", "c1",15,49,750,700);
  //TCanvas *c1 = new TCanvas("c1", "c1",15,49,700,500);
   gStyle->SetOptStat(0);
   c1->Range(-1,-55.99637,9,503.9673);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   c1->Print("plots_badLep.pdf[","pdf");

   //TFile *f1= TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqNoMetFakeRegion_lep30_met30_mjj0_mt40.root");
   //TFile *f2= TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqNoMetFakeRegion.root");
   //TFile *f2= TFile::Open("~azaman/haifeng2/reader/run/fakeEstimation/lvqqNoMetFakeRegion_lep30_met30_mjj0_mt40_AlpgenInclWjets_common.root");

   
   
   
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4_looseBadMuon1.root"); 
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadMuon1.root");

   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4.root"); 
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1.lv4_looseBadMuon1.root");

   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadMuon1.1.root");
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4.root");
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadLep3.root");

   TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetSignalRegion.caf4.1.lv4_looseGoodLepton1.1.root"); //good muon.
   TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadLep4.root");
   TFile *f3=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadMuon1.1.root");
 
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4_looseGoodLepton1.1.root"); 
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1.lv4_looseBadLep4.root");

 
   
   
   const int nFlav =4; TString flavorName[nFlav]={"ep","em","mp","mm"};
   //const int nFlav =2; TString flavorName[nFlav]={"ep","em"};
   
   //const int nHist =23 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT"};


   const int nRegion =3; TString regionName[nRegion] = {"CR_Wjj","SR","SRfatOnly"};
   
   const int nHist=10;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","cosThetaWDecay","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};
   //const int nHist=9;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};
   //const int nHist=2;TString histName[nHist]={"MET_et","ptwlep"};

   for (int iHist=0;iHist<nHist;iHist++){
     for (int iRegion=0;iRegion<nRegion;iRegion++){	  
       for (int iFlav=0;iFlav<nFlav;iFlav++){

	 if (regionName[iRegion] =="SRfatOnly" && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
		 
	 TH1F* h1=(TH1F*)f1->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h2=(TH1F*)f2->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h3=(TH1F*)f3->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())); ////
	 
	 h1->Add((TH1F*)f1->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 
	 h2->Add((TH1F*)f2->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h2->Add((TH1F*)f2->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h2->Add((TH1F*)f2->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h2->Add((TH1F*)f2->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h2->Add((TH1F*)f2->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);

	 ////
	 h3->Add((TH1F*)f3->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h3->Add((TH1F*)f3->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h3->Add((TH1F*)f3->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h3->Add((TH1F*)f3->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h3->Add((TH1F*)f3->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 ////

	 for(int k=0; k<=h1->GetNbinsX(); k++){
	   if(h1->GetBinContent(k)<0.) {
	     h1->SetBinContent(k,0.);
	     h1->SetBinError(k,0.);
	   }
	 }
	 
	 for(int k=0; k<=h2->GetNbinsX(); k++){
	   if(h2->GetBinContent(k)<0.) {
	     h2->SetBinContent(k,0.);
	     h2->SetBinError(k,0.);
	   }
	 }


	 ////
	 for(int k=0; k<=h3->GetNbinsX(); k++){
	   if(h3->GetBinContent(k)<0.) {
	     h3->SetBinContent(k,0.);
	     h3->SetBinError(k,0.);
	   }
	 }
	 ////

	 TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	 TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	 
	 p1->Draw();
	 p2->Draw();
	 p1->cd();

	 bool logy=false;
	 if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") ){
	   logy = true;
	 }
	 // cout<<logy<<endl;
	 p1->SetLogy(logy); 
	 
	 h1->SetLineColor(kBlue);
	 h1->Scale(1/h1->Integral());
	 h1->Draw();
	 h1-> GetYaxis()->SetLabelSize(0.05);
	 h1-> GetXaxis()->SetLabelSize(0.04);
	       
	 h1->SetTitle(Form("%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));
	 
	 
	 h2->SetLineColor(kRed);
	 h2->Scale(1/h2->Integral());
	 h2->Draw("same");

	 ////
	 h3->SetLineColor(kGreen);
	 h3->Scale(1/h3->Integral());
	 h3->Draw("same");
	 ////
	 
	 double maxi= 0;
	 if (h1->GetBinContent(h1->GetMaximumBin())>h2->GetBinContent(h2->GetMaximumBin())){
	   maxi=h1->GetBinContent(h1->GetMaximumBin());
	 }else{
	   maxi=h2->GetBinContent(h2->GetMaximumBin());
	 };
	 h1->SetMaximum(maxi*1.5);
	 
	 TLegend *l=new TLegend(0.6,0.7,0.95,0.9);

	 l->AddEntry(h1,"good lep: no isolation","l");
	 l->AddEntry(h2,"bad lep: iso5","l");
	 l->AddEntry(h3,"bad lep: no isolation","l");
	 
	 
	 //l->AddEntry(h1,"bad lep: no isolation","l");
	 //l->AddEntry(h2,"bad lep: tight isolation","l");
	 //l->AddEntry(h2,"bad lep: pt iso < 0.2","l");
	 
	 //l->AddEntry(h1,"d0sig<3 and isolated ","l");
	 //l->AddEntry(h1,"d0sig>3 and isolated ","l");
	 //l->AddEntry(h2,"dosig>3","l");
	 l->SetTextSize(0.05);
     
	 l->Draw();
	 
	 double xstart=h1->GetBinLowEdge(1);
	 double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);
	 
	 p2->cd();
	 gStyle->SetOptStat(0);
	 TH1F *ratioHist = (TH1F*)h1->Clone();
	 ratioHist->Divide(h2);
	 ratioHist->GetYaxis()->SetRangeUser(0.5, 1.5);
	 ratioHist->GetYaxis()->SetLabelSize(0.07);
	 ratioHist->GetXaxis()->SetLabelSize(0.1);
	 ratioHist->GetYaxis()->SetTitleSize(0.1);
	 ratioHist->Draw();
	 ratioHist->SetTitle("ratio");

	 ////
	 TH1F *ratioHist2 = (TH1F*)h1->Clone();
	 ratioHist2->Divide(h3);
	 ratioHist2->GetYaxis()->SetRangeUser(0.5, 1.5);
	 ratioHist2->GetYaxis()->SetLabelSize(0.07);
	 ratioHist2->GetXaxis()->SetLabelSize(0.1);
	 ratioHist2->GetYaxis()->SetTitleSize(0.1);
	 ratioHist2->SetLineColor(kGreen);
	 ratioHist2->Draw("same");
	 ////
	 
	 TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	 horiz_line->SetLineStyle(2);
	 horiz_line->DrawLine(xstart,1.0,xend,1.0);
	 ratioHist->SetMarkerStyle(20);

	 //c1->Print("plots_badLep.pdf",Form("Title:%s",  histName[iHist].Data()));
	 c1->Print("plots_badLep.pdf",Form("Title:%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));

	 //c1->Print("plots_badLep.pdf","pdf");
	 
	 p1->Clear();
	 p2->Clear();
	 
	 c1->cd();
	 
		 
       }
     }
   }
   c1->Print("plots_badLep.pdf]","pdf");
}
