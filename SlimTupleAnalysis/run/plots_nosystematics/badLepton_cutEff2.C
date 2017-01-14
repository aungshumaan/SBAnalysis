#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <pair>
#include <string>
//using namespace std;
//#include "../fakeEstimation/makeCombHist.C"

//*************************************************************************************
//Method 2: This code is used principally to get the final QCD yield table for .  "cutbin" defines the cut to put in the ptwlep distribution. has no purpose in this code and should always be 1 (consider full spectrum of ptwlep)
//ptwlep_efficiency.root is created for checking the validity of ptwlep extrapolation. The files can be for different ptwlep cuts. It will contain SR and SRfatonly region H_QCD histograms. Those histos can be used to get QCD yield and error. tgraph_QCD_ptwlep.C can be used to make graphs showing comparison between ptwlep extrapolation or direct MET template fit. 

//While creating the ptwlep_efficiency.tex files you are using QCDSF files. Be sure to use the right SF file
///********** Instructions ***
//0. If the QCDSF do not have SRfatOnly SF, manually modify it. There is a script called modify.py in fakeEstimation/output directory 
//1. Use the lvqqCombQCD file to get yields and errors for QCD, data , W+jets and other samples.
//2. Read the SF from some QCDSF...txt file  to get the fit error in QCD estimation because QCD error is not equal to QCD histogram error 
//*************************************************************************************

void findQcdSfMap(std::map< string, pair<float,float> > &qcdsfmap, std::map< string, pair<float,float> > &mcsfmap) 
{   
  //&&&&
  
  //string inFileName = "../fakeEstimation/output/QCDSF.caf4.2.lv8.1_smw_separateWjetsEWK4_merged.txt";
  //string inFileName = "../fakeEstimation/output/QCDSF.caf4.2.lv8.1_smw_wp20_modified.txt";  
  string inFileName = "../fakeEstimation/output/QCDSF.caf4.2.lv8_smw_wp20_NEW_ptwlep90_modified.txt";  //&&&&
  

  ifstream inFile(inFileName.c_str());
    
  string _channel; 
  float _qcd_sf, _qcd_err, _mc_sf , _mc_err ;
    
  if ( inFile.is_open() ) {
      
    string line ;
    getline( inFile, line );
      
    while( inFile.good() ){
      if (line.find("//")!=line.npos || line.size()==0) { getline(inFile,line); continue; }
	
      istringstream info_line(line);
      info_line >> _channel  >> _qcd_sf >> _qcd_err >> _mc_sf >> _mc_err;  ///an example of a line: em_WBF_SR  1.449382 0.033393 0.925511 0.015871
      qcdsfmap[_channel].first = _qcd_sf ; 
      qcdsfmap[_channel].second = fabs(_qcd_err);
      mcsfmap[_channel].first = _mc_sf ; 
      mcsfmap[_channel].second = fabs(_mc_err);
   
      cout<<_channel<<" "<<qcdsfmap[_channel].first<<" "<<qcdsfmap[_channel].second<<endl;
      //cout<<_channel<<" "<<mcsfmap[_channel].first<<" "<<mcsfmap[_channel].second<<endl;
      getline (inFile,line);
    }
  }
  
  inFile.close();
  return;
}


void badLepton_cutEff2(){


  ofstream outFile("ptwlep_efficiency.txt");
  ofstream outLatex("ptwlep_efficiency.tex");
  TFile *fout =TFile::Open("ptwlep_efficiency.root","RECREATE");


 

  map<string, std::pair<float,float> > qcdsfmap; 
  map<string, std::pair<float,float> > mcsfmap; 
  findQcdSfMap(qcdsfmap, mcsfmap);  //read the SF from the QCDSF...txt file
  
  //TH1::SetDefaultSumw2(1);

  
  int  count =0;

  

  ////slimntuples without ptwlep cut &&&&
  //This file is used to get yield for data and non-QCD samples
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_noSeparateWjetsEWK.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_NEWcutflow.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_looseBadLep4.root"); 
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4_ptwlep120.root"); //hard coded
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv4.4.root"); //ptwlep> 150
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv7.1_looseBadLep4.root");  
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_noSeparateWjetsEWK.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_separateWjetsEWK4.root");//
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_separateWjetsEWK4_merged.root");
  //TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_wp20.root");

  TFile *f=TFile::Open("~azaman/Analysis5/SlimTupleAnalysis/run/fakeEstimation/lvqqCombQCD_plots.caf4.2.lv8_smw_ptwlep90.root");   //&&&&
  
  
  const int nFlav =4; TString flavorName[nFlav]={"ep","em","mp","mm"};
  //const int nFlav =1; TString flavorName[nFlav]={"mm"};
   
  
  const int nRegion =2; TString regionName[nRegion] = {"SR","SRfatOnly"}; //two regions in one table.
  //const int nRegion =2; TString regionName[nRegion] = {"CR_Wjj","CR_WjjfatOnly"}

   
  double qcd_fitErrRatio(1.),  mc_fitErrRatio(1.);
  vector <float> vec_data, vec_ttbar, vec_Wjets, vec_Zjets, vec_singleTop, vec_diboson, vec_WjetsEWK, vec_qcd, vec_qcdErr;
  vector <float>  vec_ttbarErr, vec_WjetsErr, vec_ZjetsErr, vec_singleTopErr, vec_dibosonErr, vec_WjetsEWKErr ;

  //TH1F *h_out = new TH1F("h_out","h_out",1,0,1);

  for (int iRegion=0;iRegion<nRegion;iRegion++){

    for (int iFlav=0;iFlav<nFlav;iFlav++){

      TString channel = flavorName[iFlav]+"_WBF_"+regionName[iRegion];
      cout<<channel<<endl;
 

      //&&&& hack!!! if value is zero you cannot take error/value. Temporary hack is setting error/value = error. 
      if ( fabs(qcdsfmap[channel.Data()].first)> 0.0001){qcd_fitErrRatio = qcdsfmap[channel.Data()].second /qcdsfmap[channel.Data()].first;}
      else{qcd_fitErrRatio = qcdsfmap[channel.Data()].second;}
      if ( fabs(mcsfmap[channel.Data()].first)> 0.0001){mc_fitErrRatio = mcsfmap[channel.Data()].second / mcsfmap[channel.Data()].first;}
      else{mc_fitErrRatio = mcsfmap[channel.Data()].second;}
      //hack end
      cout<<"QCD SF "<<qcdsfmap[channel.Data()].first<<endl;
      cout<<"QCD SF error "<<qcdsfmap[channel.Data()].second<<endl;
      cout<<"QCD SF error ratio "<<qcd_fitErrRatio<<endl;
      //cout<<mc_fitErrRatio<<endl;
      
	 

      //Get QCD and W+jets ptwlep (&&&& HARD CODED) distribution (without any cut) 
      TH1F* hQCD=(TH1F*)f->Get(Form("H_QCD_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));  //hQCD is QCD from signal region (without ptwlep cut) . For negative yield histogram integral will give zero
      
      //THIS IS NOT USED IN THE YIELD TABLE
      TH1F* hWjetsScaled=(TH1F*)f->Get(Form("H_WjetsScaled_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data())); //scaled W+jets in signal region, without ptwlep cut
      
 
      
      ///Get yield from data and other bkgs for without ptwlep cut.
      TH1F* hData=(TH1F*)f->Get(Form("H_Data_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      TH1F* hTtbar=(TH1F*)f->Get(Form("H_Ttbar_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));  
      TH1F* hWjets=(TH1F*)f->Get(Form("H_Wjets_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      TH1F* hZjets=(TH1F*)f->Get(Form("H_Zjets_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      TH1F* hSingleTop=(TH1F*)f->Get(Form("H_SingleTop_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      TH1F* hDiboson=(TH1F*)f->Get(Form("H_WZZZWg_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      TH1F* hWjetsEWK=(TH1F*)f->Get(Form("H_WjetsEWKSherpa_%s_WBF_%s_ptwlep",flavorName[iFlav].Data(), regionName[iRegion].Data()));
      hWjets->Add(hWjetsEWK); //&&&&

      outFile<< flavorName[iFlav]<<"_"<< regionName[iRegion] <<endl;
      
	 
      double nbins_ptwlep = hQCD->GetNbinsX();
      

      outFile<< "QCD_before_ptwlep_sigReg "<<hQCD->Integral(1, nbins_ptwlep+1)<<endl;
      outFile<< "WjetsScaled_before_ptwlep "<<hWjetsScaled->Integral(1, nbins_ptwlep+1)<<endl;

      

      ////This is direct MET fitting, not ptwlep extrapolation . Should be no cut on ptwlep => cutbin =1
      //&&&& cutbin HARD CODED

      //new ptwlep binning (2/18/16) 0, 10,20,30,40,50,60,70,80,90, 100, 120, 150,...
      int cutbin =1; //ptwlep> 0
  
      
      double QCD_eps =1.; //QCD cut efficiency
    
      
      //THIS IS NOT USED IN THE YIELD TABLE
      double Wjets_eps =1.;
    

      double N = hQCD->Integral(1, nbins_ptwlep+1); //number of QCD events without cut
      //cout<<"qcd before cut, N "<<N<<endl;
      
   
      double QCDfinal = hQCD->Integral(1, nbins_ptwlep+1);
      double WjetsScaledfinal = hWjetsScaled->Integral(1, nbins_ptwlep+1);
      //cout<<"qcd after ptwelp cut, QCDfinal  "<<QCDfinal <<endl;
      
      
      //outFile<<"QCD error ratio "<<qcd_fitErrRatio<<endl;
      //outFile<<"Wjets error ratio "<<mc_fitErrRatio<<endl;
      
      double QCDfinalErr =0.;
  
      if (QCDfinal!=0){
	
	QCDfinalErr =fabs(QCDfinal*qcd_fitErrRatio) ; 
      }
      else {QCDfinalErr =fabs(qcd_fitErrRatio) ;} //&&&& Temporary hack was setting error/value = error for when value <0.0001. We are keeping the error unchanged which is conservative.

      //cout<<"QCDfinalErr = "<< QCDfinalErr <<endl;
      //cout<<"QCDfinalErr previous = "<< QCDfinal*qcd_fitErrRatio <<endl;
	 
      double WjetsScaledfinalErr =fabs(WjetsScaledfinal* mc_fitErrRatio) ;


      TH1F* h_QCDYield= new TH1F(Form("H_QCD_%s_WBF_%s",flavorName[iFlav].Data(), regionName[iRegion].Data()),Form("H_QCD_%s_WBF_%s",flavorName[iFlav].Data(), regionName[iRegion].Data()),1,0,1);
      //cout<<count<<endl;
      count++;
      
      fout->cd();
      h_QCDYield->SetBinContent(1,QCDfinal);
      h_QCDYield->SetBinError(1,QCDfinalErr);
      h_QCDYield->Write();


      //Fill out vectors with yield and error for different samples. 
      Double_t error =0.;
      Double_t errorRatio =0.;
   

     
      errorRatio = calculateErrorRatio(hData,cutbin);
      outFile<< "Data "<< hData->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hData->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_data.push_back(hData->Integral(cutbin, nbins_ptwlep+1) );

      errorRatio = calculateErrorRatio(hTtbar,cutbin);
      outFile<< "ttbar "<< hTtbar->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hTtbar->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_ttbar.push_back(hTtbar->Integral(cutbin, nbins_ptwlep+1) );
      vec_ttbarErr.push_back(errorRatio*hTtbar->Integral(cutbin, nbins_ptwlep+1) );

      errorRatio = calculateErrorRatio(hZjets,cutbin);
      outFile<< "Zjets "<< hZjets->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hZjets->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_Zjets.push_back(hZjets->Integral(cutbin, nbins_ptwlep+1) );
      vec_ZjetsErr.push_back(errorRatio*hZjets->Integral(cutbin, nbins_ptwlep+1) );
       // vec_Zjets.push_back(1.) ;
       // vec_ZjetsErr.push_back(1. );

      errorRatio = calculateErrorRatio(hSingleTop,cutbin);
      outFile<< "single_top "<< hSingleTop->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hSingleTop->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_singleTop.push_back(hSingleTop->Integral(cutbin, nbins_ptwlep+1) );
      vec_singleTopErr.push_back(errorRatio*hSingleTop->Integral(cutbin, nbins_ptwlep+1) );

      errorRatio = calculateErrorRatio(hDiboson,cutbin);
      outFile<< "diboson "<< hDiboson->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hDiboson->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_diboson.push_back(hDiboson->Integral(cutbin, nbins_ptwlep+1) );
      vec_dibosonErr.push_back(errorRatio*hDiboson->Integral(cutbin, nbins_ptwlep+1) );
      
      // errorRatio = calculateErrorRatio(hWjetsEWK,cutbin);
      // outFile<< "Wjets_EWK "<< hWjetsEWK->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hWjetsEWK->Integral(cutbin, nbins_ptwlep+1) <<endl;
      // vec_WjetsEWK.push_back(hWjetsEWK->Integral(cutbin, nbins_ptwlep+1) );
      // vec_WjetsEWKErr.push_back(errorRatio*hWjetsEWK->Integral(cutbin, nbins_ptwlep+1) );


      errorRatio = calculateErrorRatio(hWjets,cutbin);
      outFile<< "Wjets "<< hWjets->Integral(cutbin, nbins_ptwlep+1) <<" "<<errorRatio*hWjets->Integral(cutbin, nbins_ptwlep+1) <<endl;
      vec_Wjets.push_back(hWjets->Integral(cutbin, nbins_ptwlep+1) );
      vec_WjetsErr.push_back(errorRatio*hWjets->Integral(cutbin, nbins_ptwlep+1) );


   
			 
      

      outFile<< "WjetsScaled_final  "<< WjetsScaledfinal<<" " << WjetsScaledfinalErr <<endl;
      outFile<< "QCD_final  "<< QCDfinal <<" " << QCDfinalErr <<endl;
	 

      outFile << "========" <<endl;


	 
      vec_qcd.push_back(QCDfinal);
      vec_qcdErr.push_back(QCDfinalErr);
		 
      /*
	for (int ibin =1; ibin<=nbins ;ibin++){
	cout<< h1->GetBinLowEdge(ibin) <<"-->"<<h1->Integral(ibin, nbins)<<endl;
	cout<< "Efficiency -->"<<h1->Integral(ibin, nbins) /total<<endl;
	}
      */
	 	 
	 
	 	 
    }
       
  }
  outFile.close();

  //Write the tex file

  //SR and SRfatOnly in one table
   outLatex<<"\\begin{tabular}{|l|r|r|r|r||r|r|r|r|} \\hline"<<endl;
   outLatex<<" \\multirow{2}{*}{} & \\multicolumn{4}{c||}{SR resolved}    &   \\multicolumn{4}{c|}{SR merged}     \\\\  \\hline"<<endl;
   //outLatex<<"  & \\multicolumn{4}{c|}{SR resolved}    &   \\multicolumn{4}{c|}{SR merged}     \\\\  \\hline"<<endl;
   outLatex<<"   &   $e^{+}$  &   $e^{-}$  &  $\\mu^{+}$  &  $\\mu^{-}$  &    $e^{+}$  &   $e^{-}$  &  $\\mu^{+}$  &  $\\mu^{-}$   \\\\ \\hline"<<endl;

  //outLatex<<"\\begin{tabular}{|l|r|r|r|r|} \\hline"<<endl;
  //outLatex<<"   &   $e^{+}$  &   $e^{-}$  &  $\\mu^{+}$  &  $\\mu^{+}$    \\\\ \\hline"<<endl;
   
  outLatex<<"Data";
  for (int i =0; i< vec_data.size();i++){
    outLatex<<"  &  "<<vec_data[i] ;
    //if (i==4)outLatex<<"  &  ";
  }
  outLatex<<"\\\\"<<endl;
  outLatex<<"W+jets";
  for (int i =0; i< vec_data.size();i++){
    outLatex<<"  &  "<<fixed<<setprecision(1)<<vec_Wjets[i] << "$\\pm$"<< vec_WjetsErr[i];
  }
  outLatex<<"\\\\"<<endl;
  // outLatex<<"W+jets EWK";
  // for (int i =0; i< vec_WjetsEWK.size();i++){
  //   outLatex<<"  &  "<<vec_WjetsEWK[i] << "$\\pm$"<< vec_WjetsEWKErr[i];
  // }
  // outLatex<<"\\\\"<<endl;
  //outLatex<<"$\\ttbar$"; //worked for note.tex but not for baseTemplate.tex
  outLatex<<"$t\\bar{t}$"; //worked for baseTemplate.tex
  for (int i =0; i< vec_data.size();i++){
    outLatex<<"  &  "<<vec_ttbar[i]<< "$\\pm$"<< vec_ttbarErr[i] ;
  }
  outLatex<<"\\\\"<<endl;
  outLatex<<"Z+jets";
  for (int i =0; i< vec_data.size();i++){
    outLatex<<"  &  "<<vec_Zjets[i]<< "$\\pm$"<< vec_ZjetsErr[i] ;
  }
  outLatex<<"\\\\"<<endl;
  outLatex<<"single top";
  for (int i =0; i< vec_data.size();i++){
    outLatex<<"  &  "<<vec_singleTop[i]<< "$\\pm$"<< vec_singleTopErr[i] ;
  }
  outLatex<<"\\\\"<<endl;
  outLatex<<"Diboson";
  for (int i =0; i< vec_diboson.size();i++){
    outLatex<<"  &  "<<vec_diboson[i] << "$\\pm$"<< vec_dibosonErr[i];
  }
  outLatex<<"\\\\"<<endl;
  outLatex<<"QCD";
  for (int i =0; i< vec_qcd.size();i++){
    outLatex<<"  &  "<<vec_qcd[i] << "$\\pm$"<<vec_qcdErr[i] ;
  }
  outLatex<<"\\\\ \\hline \\hline"<<endl;
  outLatex<<"\\end{tabular}"<<endl;
   
  outLatex.close();
}


float calculateErrorRatio(TH1* h, const int cutbin) {
  
  int nbins = h->GetNbinsX();
  Double_t histerror(0.), N_err(0.);
  
  float N = h->IntegralAndError(1, nbins+1, N_err); //total yield and uncertainty before cut
  float N_errorRatio = 1;
  if (N>0.0001){
    N_errorRatio = N_err/N;
  }else {
    N_errorRatio = N_err; //&&&& hack! If Nevent to start with is zero, N_err is also zero (because read from histogram), setting ratio to zero. (N_err =0 does not sound right!!)
  }
  //cout<<"Inside calculateErrorRatio "<<N_err<<" "<<N<<" "<<N_errorRatio <<endl;

  float cutyield = h->IntegralAndError(cutbin, nbins+1,histerror); //histerror is a curiosity, we are not using it anywhere.
  float eps =1.; //no cut
  float eps_err =0.;
  //if (N>0.0001){        //&&&& hack!
  //eps = cutyield/N;   //cut efficiency
  // eps_err = sqrt(fabs(eps*(1-eps)/N)); //uncertainty in cut efficiency
  //}
  //cout<<"Inside calculateErrorRatio: Yield before cut "<<N<<", yield error before cut "<<N_err<<", Yield after cut "<<cutyield<<", Cutbin error "<<histerror<<", cut eff "<<eps<<", cut eff error  "<<eps_err <<endl;
  
  float total_errRatio = 1.;
  total_errRatio =  N_errorRatio ; //N_errorRatio = Sigma_N/N.  For N =0, our hack ensures  N_errorRatio = N_err
  //cout<<"Inside calculateErrorRatio: N_errorRatio "<<N_errorRatio<<", eps_err/eps "<<eps_err/eps<<", total_errRatio "<<total_errRatio<<endl;
  
  return total_errRatio;

}
