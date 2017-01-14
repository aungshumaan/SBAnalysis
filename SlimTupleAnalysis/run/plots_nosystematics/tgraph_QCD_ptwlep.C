{
  TCanvas *c1 = new TCanvas("","",0,0,750,700);
 
  TGraphErrors *gr;
  Double_t x[7] ={0,20,40,60,100,120,150}; //&&&& hard coded
  Double_t ex[7] =0;
  //Double_t x[4] ={ 0 ,30 ,60 ,90};
  //Double_t ex[4] ={0 ,0, 0, 0};
  
  TGraphErrors *gr_extrap;
  Double_t x_extrap[3] ={50,100,150};  //&&&& hard coded
  Double_t ex_extrap[3] =0;
  //Double_t x_extrap[6] ={0,30,60, 90, 120, 150};
  //Double_t ex_extrap[6] ={0,0,0,0,0,0};

  ///*
  //Method 2: put ptwlep cut, do MET fit directly
  TFile* f0 =TFile::Open("ptwlep_efficiency_0.root");
  TFile* f1 =TFile::Open("ptwlep_efficiency_20.root");
  TFile* f2 =TFile::Open("ptwlep_efficiency_40.root");
  TFile* f3 =TFile::Open("ptwlep_efficiency_60.root");
  TFile* f4 =TFile::Open("ptwlep_efficiency_100.root");
  TFile* f5 =TFile::Open("ptwlep_efficiency_120.root");
  TFile* f6 =TFile::Open("ptwlep_efficiency_150.root");

  //Method 1: remove ptwlep cut, do MET fit. After fit use ptwlep cut efficiency to calculate yield
  TFile* ff0 =TFile::Open("ptwlep_efficiency_0to50_new.root");
  TFile* ff1 =TFile::Open("ptwlep_efficiency_0to100_new.root");
  TFile* ff2 =TFile::Open("ptwlep_efficiency_0to150_new.root");
  //*/
  
   /*
  //Method 2: put ptwlep cut, do MET fit directly
  TFile* f0 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method2_0.root");
  TFile* f1 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method2_30.root");
  TFile* f2 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method2_60.root");
  TFile* f3 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method2_90.root");


  //Method 1: remove ptwlep cut, do MET fit. After fit use ptwlep cut efficiency to calculate yield
  TFile* ff0 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_0.root");
  TFile* ff1 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_30.root");
  TFile* ff2 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_60.root");
  TFile* ff3 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_90.root");
  TFile* ff4 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_120.root");
  TFile* ff5 =TFile::Open("ptwlep_efficiency.caf4.2.lv8_smw_wp20_NEW.method1_150.root");
   */

  //c1->Print("plots_fitQCDptwlep.pdf[" );
  
  const int nFlav =4; TString flavorName[nFlav]={"ep","em","mp","mm"};
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"};
  
  for  (int iRegion=0;iRegion<nRegion;iRegion++){
    
    for (int iFlav=0;iFlav<nFlav;iFlav++){
      
      TString histName = Form("H_QCD_%s_WBF_%s",flavorName[iFlav].Data(), regionName[iRegion].Data());

      TH1F* h0 = (TH1F*)f0->Get(histName);
      TH1F* h1 = (TH1F*)f1->Get(histName);
      TH1F* h2 = (TH1F*)f2->Get(histName);
      TH1F* h3 = (TH1F*)f3->Get(histName);
      // /*
      TH1F* h4 = (TH1F*)f4->Get(histName); 
      TH1F* h5 = (TH1F*)f5->Get(histName);
      TH1F* h6 = (TH1F*)f6->Get(histName);
      // */

      TH1F* hh0 = (TH1F*)ff0->Get(histName);
      TH1F* hh1 = (TH1F*)ff1->Get(histName);
      TH1F* hh2 = (TH1F*)ff2->Get(histName);
      /*
      TH1F* hh3 = (TH1F*)ff3->Get(histName);
      TH1F* hh4 = (TH1F*)ff4->Get(histName);
      TH1F* hh5 = (TH1F*)ff5->Get(histName);
      */
	    
      //Double_t data[4] ={669,639,553,464}; //test
      cout<<"1: "<<h0->GetBinContent(1)<<endl;
      cout<<"2: "<<h1->GetBinContent(1)<<endl;
      cout<<"3: "<<h2->GetBinContent(1)<<endl;
      cout<<"4: "<<h3->GetBinContent(1)<<endl;
      //cout<<"5: "<<h4->GetBinContent(1)<<endl;
      //cout<<"6: "<<h5->GetBinContent(1)<<endl;
      //cout<<"7: "<<h6->GetBinContent(1)<<endl;

      // /*
      Double_t data[7] ={h0->GetBinContent(1),h1->GetBinContent(1),h2->GetBinContent(1),h3->GetBinContent(1),h4->GetBinContent(1),h5->GetBinContent(1),h6->GetBinContent(1)};
      Double_t err_data[7] ={h0->GetBinError(1),h1->GetBinError(1),h2->GetBinError(1),h3->GetBinError(1),h4->GetBinError(1),h5->GetBinError(1),h6->GetBinError(1)};

      Double_t data_extrap[3] ={hh0->GetBinContent(1),hh1->GetBinContent(1),hh2->GetBinContent(1)};
      Double_t err_data_extrap[3] ={hh0->GetBinError(1),hh1->GetBinError(1),hh2->GetBinError(1)};
      // */
      /*
      Double_t data[4] ={h0->GetBinContent(1),h1->GetBinContent(1),h2->GetBinContent(1),h3->GetBinContent(1)};
      Double_t err_data[4] ={h0->GetBinError(1),h1->GetBinError(1),h2->GetBinError(1),h3->GetBinError(1)};

      Double_t data_extrap[6] ={hh0->GetBinContent(1),hh1->GetBinContent(1),hh2->GetBinContent(1), hh3->GetBinContent(1),hh4->GetBinContent(1),hh5->GetBinContent(1)};
      Double_t err_data_extrap[6] ={hh0->GetBinError(1),hh1->GetBinError(1),hh2->GetBinError(1), hh3->GetBinError(1), hh4->GetBinError(1), hh5->GetBinError(1)};
      */ 
      
      gr = new TGraphErrors(7,x,data, ex, err_data );
      //gr = new TGraphErrors(4,x,data, ex, err_data );
      gr->GetXaxis()->SetTitle("ptwlep cut");
      gr->GetYaxis()->SetTitle("QCD yield");
      //gr->GetYaxis()->SetTitle("(WW+WZ)/sqrt(Wg)");
      gr->GetXaxis()->SetLimits(-5,165);
      //gr->GetYaxis()->SetMinimum(0.);
      gr->SetMinimum(0.);
      gr->SetName("gr");

      gr_extrap = new TGraphErrors(3,x_extrap,data_extrap, ex_extrap, err_data_extrap );
      //gr_extrap = new TGraphErrors(6,x_extrap,data_extrap, ex_extrap, err_data_extrap );
      gr_extrap->SetName("gr_extrap");

      TF1 *fitFcn = new TF1("fitFcn","[0]+[1]*x+[2]*x**2",0,200); //quadratic
      //TF1 *fitFcn = new TF1("fitFcn","[0]+[1]*x",-10,200); //linear
      fitFcn->SetParameter(0,1);
      fitFcn->SetParameter(1,1);
      fitFcn->SetLineWidth(4);
      fitFcn->SetLineColor(kMagenta);
      ////fitFcn->Draw();  

      TFitResultPtr r = gr->Fit("fitFcn","0");//option "S" means the result is stored in the TFitResultPtr. The fit function is drawn automatically
      Double_t chi2   = r->Chi2();
      Double_t Chi2 = fitFcn->GetChisquare()/fitFcn->GetNDF();;
      
      cout<<"####Chi2= "<<chi2<<" "<<Chi2<<endl;

      
      
      //gr->Draw("AC*");
      //gr->Draw("A*");
      gr->Draw("A*");
      gr->SetMarkerStyle(21);
      gr->SetMarkerSize(0.5);
      gr->SetTitle("");

      //gr->Draw("same *");

      //gr_extrap->Draw("same *");
      gr_extrap->Draw(" *");
      gr_extrap->SetMarkerColor(kBlue);
      gr_extrap->SetMarkerSize(0.5);
      gr_extrap->SetLineColor(kBlue);

      gr->Draw("same *");

      
      //fitFcn->Draw("same");
      
      TLegend *leg = new TLegend(0.56, 0.70, 0.85, 0.88) ;
      //leg->SetHeader("blah");
      leg->AddEntry("gr","template fitting","lep");
      leg->AddEntry("gr_extrap", "ptwlep extrapolation","lep");
      leg->Draw();
      
      TLatex l;
      l.SetTextSize(0.03); 
      l.SetNDC();///NDC stands for normalized coordinate system where (0,0) corresponds to the bottom-left corner of the pad
      l.SetTextColor(1); //black

      TString latexFlav("");
      if (flavorName[iFlav] == "ep") { latexFlav = "e^{+}";}
      else if (flavorName[iFlav] == "em") { latexFlav = "e^{-}";}
      else if (flavorName[iFlav] == "mp") {  latexFlav = "#mu^{+}";}
      else if (flavorName[iFlav] == "mm") {  latexFlav = "#mu^{-}";}
      
      //l.DrawLatex(0.20 , 0.94,"ATLAS #bf{Internal}");
      //l.DrawLatex(0.20 , 0.84,Form("#bf{%s, %s, reduced #chi^{2} = %.2f}",flavorName[iFlav].Data(), regionName[iRegion].Data(),Chi2));

      //l.DrawLatex(0.20 , 0.84,Form("ATLAS #bf{Internal}, #bf{%s, %s}",latexFlav.Data(), regionName[iRegion].Data()));
      l.DrawLatex(0.20 , 0.84,Form("ATLAS #bf{Preliminary}, #bf{%s, %s}",latexFlav.Data(), regionName[iRegion].Data()));

      //c1->Print("plots_fitQCDptwlep.pdf",Form("Title:%s_%s",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      c1->Print(Form("PDF_syst_band/plots_fitQCDptwlep_%s_%s.pdf",flavorName[iFlav].Data(), regionName[iRegion].Data()));
    }
  }

  //c1->Print("plots_fitQCDptwlep.pdf]");
 
}
