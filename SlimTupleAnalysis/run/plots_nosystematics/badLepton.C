{
#include <fstream>

  ofstream outFile("ptwlep_efficiency.txt");
  
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


   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4.root"); // fake muon: d0>3 && isolated
   TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqNoMetFakeRegion.caf4.1.lv4_looseBadMuon1.root"); // fake muon: d0>3
   //TFile *f1=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqWithMetFakeRegion.caf4.1.lv4_looseBadMuon1.root"); // fake muon: d0>3
   
   
   //const int nFlav =4; TString flavorName[nFlav]={"ep","em","mp","mm"};
   const int nFlav =2; TString flavorName[nFlav]={"mp","mm"};
   //const int nFlav =2; TString flavorName[nFlav]={"ep","em"};
   
   //const int nHist =23 ;TString histName[nHist]={ "dEtaTaggedJets","dRTaggedJets","dPhiTaggedJets","dPhiWjets", "mjjTagged","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT"};


   const int nRegion =3; TString regionName[nRegion] = {"CR_Wjj","SR","SRfatOnly"};
   
   const int nHist=1;TString histName[nHist]={"MET_et"};
   //const int nHist=1;TString histName[nHist]={"ptwlep"};
   //const int nHist=9;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};
   // const int nHist=10;TString histName[nHist]={"MET_et","mTWV","mT","cosThetaWlep","cosThetaWDecay","dPhilepMET","ptwlep","mjjTagged","bosonCentrality","VVptBalance"};

   for (int iHist=0;iHist<nHist;iHist++){
     for (int iRegion=0;iRegion<nRegion;iRegion++){	  
       for (int iFlav=0;iFlav<nFlav;iFlav++){

	 if (regionName[iRegion] =="SRfatOnly" && histName[iHist] == "cosThetaWDecay"){cout<<"Hello"<<endl;continue;}
	 TH1F* h1=(TH1F*)f1->Get(Form("H_Data_%s_WBF_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(), histName[iHist].Data()));
	 
	 
	 h1->Add((TH1F*)f1->Get(Form("H_Wjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_Ttbar_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_SingleTop_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_Zjets_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 h1->Add((TH1F*)f1->Get(Form("H_WZZZWg_%s_WBF_%s_%s",flavorName[iFlav].Data(),regionName[iRegion].Data(), histName[iHist].Data())),-1);
	 
	 
	 
	 for(int k=0; k<=h1->GetNbinsX(); k++){
	   if(h1->GetBinContent(k)<0.) {
	     h1->SetBinContent(k,0.);
	     h1->SetBinError(k,0.);
	   }
	 }
	 
	 outFile<< h1->GetName() <<endl;
	 double nbins = h1->GetNbinsX();
	 double total = h1->Integral();
	 outFile<< "Total "<<h1->Integral()<<endl;
	 outFile<< h1->GetBinLowEdge(4) <<" "<<h1->Integral(4, nbins)<<endl;  //ptwlep cut 150
	 outFile<< "Efficiency  "<<h1->Integral(4, nbins) /total<<endl;
	 /*
	   for (int ibin =1; ibin<=nbins ;ibin++){
	   cout<< h1->GetBinLowEdge(ibin) <<"-->"<<h1->Integral(ibin, nbins)<<endl;
	   cout<< "Efficiency -->"<<h1->Integral(ibin, nbins) /total<<endl;
	 }
	 */
	 bool logy=false;
	 if ( histName[iHist].Contains("mjjTagged") || histName[iHist].Contains("ptwjj") || histName[iHist].Contains("ptwlep") || histName[iHist].Contains("vbfjet1_pt") || histName[iHist].Contains("vbfjet2_pt") ){
	   logy = true;
	 }
	 // cout<<logy<<endl;
	 c1->SetLogy(logy); 
	 
	 h1->SetLineColor(kBlue);
	 h1->Scale(1/h1->Integral());
	 h1->Draw();
	 
	 h1->SetTitle(Form("%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));
	 
	 double maxi = h1->GetBinContent(h1->GetMaximumBin());

	 if (!logy){ h1->SetMaximum(maxi*1.5);}
	 else {h1->SetMaximum(maxi*100);}
	 
	 TLegend *l=new TLegend(0.7,0.7,0.9,0.9);
	 //l->AddEntry(h1,"d0sig>3 and isolated ","l");
	 l->AddEntry(h1,"dosig>3","l");
	 
     
	 l->Draw();
	 
	 double xstart=h1->GetBinLowEdge(1);
	 double xend=h1->GetBinLowEdge(h1->GetNbinsX()+1);
	 
	 //c1->Print("plots_badLep.pdf",Form("Title:%s",  histName[iHist].Data()));
	 c1->Print("plots_badLep.pdf",Form("Title:%s_%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data(),histName[iHist].Data()));

	 //c1->Print("plots_badLep.pdf","pdf");
	 

	 
       }
     }
   }
   outFile.close();
   
   c1->Print("plots_badLep.pdf]","pdf");
}
