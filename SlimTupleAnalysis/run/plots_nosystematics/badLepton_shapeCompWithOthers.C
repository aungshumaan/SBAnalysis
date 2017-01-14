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

   
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetSignalRegion.caf4.1.lv4_looseBadMuon1.root"); //good muon.
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4.root"); 
   //TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadMuon1.root");

   TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv4.root"); 
   TFile *f2=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1.lv4_looseBadMuon1.root");

   
   
   
   //const int nFlav =4; TString flavorName[nFlav]={"em","ep","mm","mp"};
   const int nFlav =2; TString flavorName[nFlav]={"mm","mp"};
   
   //const int nHist =23 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT"};


   const int nRegion =3; TString regionName[nRegion] = {"CR_Wjj","SR","SRfatOnly"};

   //const int nHist=1;TString histName[nHist]={"MET_et"}
   //const int nHist=10;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","cosThetaWDecay","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};
   const int nHist=8;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};

   for (int iHist=0;iHist<nHist;iHist++){
     for (int iRegion=0;iRegion<nRegion;iRegion++){	  
       for (int iFlav=0;iFlav<nFlav;iFlav++){

	 if (regionName[iRegion] =="SRfatOnly" && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
		 
	 TH1F* h_data=(TH1F*)f1->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h_qcd=(TH1F*)f2->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 
	 TH1F* h_Wjets = (TH1F*)f1->Get( Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()) );
	 TH1F* h_ttbar =(TH1F*)f1->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h_stop =(TH1F*)f1->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h_Zjets =(TH1F*)f1->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 TH1F* h_diboson =(TH1F*)f1->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data()));
	 
	 h_qcd->Add((TH1F*)f2->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h_qcd->Add((TH1F*)f2->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h_qcd->Add((TH1F*)f2->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h_qcd->Add((TH1F*)f2->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h_qcd->Add((TH1F*)f2->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);


	 
	 for(int k=0; k<=h_qcd->GetNbinsX(); k++){
	   if(h_qcd->GetBinContent(k)<0.) {
	     h_qcd->SetBinContent(k,0.);
	     h_qcd->SetBinError(k,0.);
	   }
	 }

	 /*
	 TPad* p1 = new TPad("p1","p1",0.01, 0.35 ,0.99,0.99);
	 TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, 0.35);
	 
	 p1->Draw();
	 p2->Draw();
	 p1->cd();
	 */
	 bool logy=false;
	 if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") ){
	   logy = true;
	 }
	 // cout<<logy<<endl;
	 //p1->SetLogy(logy);
	 c1->SetLogy(logy);

	 double rebin =2;
	 if ( histName[iHist].Contains("VVptBalance") ) rebin =5;
	 
	 h_data->Rebin(rebin);
	 h_Wjets->Rebin(rebin);
	 h_Zjets->Rebin(rebin);
	 h_qcd->Rebin(rebin);
	 h_ttbar->Rebin(rebin);


	 
	 h_data->SetLineColor(kBlack);
	 h_data->SetLineWidth(2);
	 h_data->Scale(1/h_data->Integral());
	 h_data->Draw();

	 h_data->SetTitle(Form("%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));
	 cout<<(Form("%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()))<<endl;
	 
	 h_ttbar->SetLineColor(kRed);
	 h_ttbar->SetLineWidth(2);
	 h_ttbar->Scale(1/h_ttbar->Integral());
	 h_ttbar->Draw("same");
	
	 //h_Zjets->SetLineColor(kBlue);
	 //h_Zjets->SetLineWidth(2);
	 //h_Zjets->Scale(1/h_Zjets->Integral());
	 //h_Zjets->Draw("same");


	 h_Wjets->SetLineColor(kCyan);
	 h_Wjets->SetLineWidth(2);
	 h_Wjets->Scale(1/h_Wjets->Integral());
	 h_Wjets->Draw("same");
	 	 
	 h_qcd->SetLineColor(kGreen);
	 h_qcd->SetLineWidth(2);
	 h_qcd->Scale(1/h_qcd->Integral());
	 h_qcd->Draw("same");
	 
	 double maxi= 0;
	 if (h_data->GetBinContent(h_data->GetMaximumBin())>h_qcd->GetBinContent(h_qcd->GetMaximumBin())){
	   maxi=h_data->GetBinContent(h_data->GetMaximumBin());
	 }else{
	   maxi=h_qcd->GetBinContent(h_qcd->GetMaximumBin());
	 };
	 h_data->SetMaximum(maxi*1.5);
	 
	 TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	 l->AddEntry(h_data,"data","l");
	 l->AddEntry(h_qcd,"QCD","l");
	 l->AddEntry(h_Wjets,"W+jets","l");
	 //l->AddEntry(h_Zjets,"Z+jets","l");
	 l->AddEntry(h_ttbar,"ttbar","l");
	 
	 //l->AddEntry(h_data,"d0sig<3 and isolated ","l");
	 //l->AddEntry(h_data,"d0sig>3 and isolated ","l");
	 //l->AddEntry(h_qcd,"dosig>3","l");
	 
     
	 l->Draw();

	 /*
	 double xstart=h_data->GetBinLowEdge(1);
	 double xend=h_data->GetBinLowEdge(h_data->GetNbinsX()+1);
	 
	 p2->cd();
	 gStyle->SetOptStat(0);
	 TH1F *ratioHist = (TH1F*)h_data->Clone();
	 ratioHist->Divide(h_qcd);
	 ratioHist->GetYaxis()->SetRangeUser(0.5, 1.5);
	 ratioHist->Draw();
	 ratioHist->SetTitle("ratio");
	 TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
	 horiz_line->SetLineStyle(2);
	 horiz_line->DrawLine(xstart,1.0,xend,1.0);
	 ratioHist->SetMarkerStyle(20);
	 */
	 //c1->Print("plots_badLep.pdf",Form("Title:%s",  histName[iHist].Data()));
	 c1->Print("plots_badLep.pdf",Form("Title:%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));

	 //c1->Print("plots_badLep.pdf","pdf");
	 
	 //p1->Clear();
	 //p2->Clear();
	 
	 //c1->cd();
	 
	 // hist_new->Draw();
	 // hist_new->SetLineColor(kBlue);
	 // hist_new2->Draw("same");
	 // hist_new2->SetLineColor(kRed);
	 // c1->Print("sherpaAlp.pdf","pdf");
	 // hist_new->Reset();
	 // hist_new2->Reset();
	 
       }
     }
   }
   c1->Print("plots_badLep.pdf]","pdf");
}
