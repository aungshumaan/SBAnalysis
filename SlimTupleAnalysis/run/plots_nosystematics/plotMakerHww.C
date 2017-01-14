#include "makerHelper.h"

#include "TFile.h"
#include "TH1.h"
#include <TFile.h>
#include <TApplication.h> 
#include <TRint.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TLorentzVector.h> 
#include <TStyle.h>
#include <TCanvas.h>
#include "TROOT.h"

#include <iostream>


using namespace std;

#define test 0
#define wide 0

#define doReweightTtbar  0 ///added by auzaman, gets the ttbar sample reweightFactors using  dEtaTaggedJets plot in CR_Top. Should be set to 0 normally
#define doReweightWjets  0


TH1* mergeForReweighting(TFile* , TString ,TString , TString );

void plotReweightFactor(TCanvas* , TPad* , TPad* , TH1* , TH1* , const TString );

void plotMakerHww()
{
  bool drawTwoPads = true ;
  //bool drawTwoPads = false ;
  
  gStyle->SetOptStat(kFALSE);
  
  //TString fileName="../hwwlvqq.root"; ///this is for plotting without QCD


  //TString fileName="../fakeEstimation/lvqqNoMetFakeRegion.root";///This is for QCD control region
  //TString fileName="../fakeEstimation/lvqqNoMetFakeRegion_onlyem_shapeRW.root";
  
  TString fileName="../fakeEstimation/lvqqCombQCD_plots.root"; ///this is for plotting with QCD
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10.1_COMMON.root";
  //TString fileName="../fakeEstimation/lvqqNoMetFakeRegion_lep30_met30_mjj0_mt40_v10.1_COMMON.root";

  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10.root";
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_v10_noTtbarOrBtagWeight.root";
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40.root";//before any reweighting
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_AlpgenInclWjets.root";//before any reweighting
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_lep30_met30_mjj0_mt40_PowPythTtbar.root";//before any reweighting
  
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_merged_WjetsshapeRW.root";
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_merged_TopWjetsshapeRW.root";
  //TString fileName="../fakeEstimation/lvqqCombQCD_plots_merged_WjetsAfterTopshapeRW.root";
  
  TFile *finput = new TFile(fileName) ;
  if (finput->IsZombie()) { cout << "Error : can not find file " << fileName << endl; exit(1); }


#if !test
  
  //const int NFlavors   = 1 ;  std::string flavorChannel[NFlavors]= {"em"} ;
  //const int NFlavors   = 2 ;  std::string flavorChannel[NFlavors]= {"em","ep"} ;
  const int NFlavors   = 4 ;  std::string flavorChannel[NFlavors]= {"em", "ep", "mm", "mp"} ;
  const int nCuts = 2 ;
  std::string cuts[nCuts]  = { 
    //"WBF_JetSelectResolve",
    //"WBF_JetSelectFat",
   
    //"WBF_BTAG", //Added this for plots with no mass window enforced
    //"WBF_CR_Wjj",
    
    // "WBF_CR_Top",
    // "WBF_CR_TopfatOnly",
     "WBF_CR_TopFJ",
    // "WBF_CR_TopresolveOnly",
    
    //"WBF_SR",
    //"WBF_SRfatOnly",
    "WBF_SRFJ",
    //"WBF_SRresolveOnly",
  } ;


  //const int nHistType = 4 ;  std::string histType[nHistType]   = { "Mlvjj", "Mwjj", "Njet", "MET_et" } ;
  //const int nHistType = 4 ;  std::string histType[nHistType]   = { "Mlvjj", "Mwjj", "MET_et","mjjTagged" } ;
  //const int nHistType = 3 ;  std::string histType[nHistType]   = { "dEtaTaggedJets","topRWEventWeight","EventWeight"};
  //const int nHistType = 35 ;  std::string histType[nHistType]   = { "jet1_pt","jet2_pt","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi","vbfjets_etaProduct","lep_pt","lep_eta","lep_phi","Njet", "MET_et","mT","Mlvjj", "Mwjj","ptlvjj","ptwjj", "mjjTagged","ptjjTagged","AvgPt_Wjets","ptwlep","ptBalance","diff_ptww_ptjjTagged","sumPt","diff_etawjj_avgEtaTagged","etaX","etaY", "dRTaggedJets","dRWjets", "mass_lnuj0", "mass_j0j1j2"} ;
  //const int nHistType = 37 ;  std::string histType[nHistType]   = { "dEtaTaggedJets","jet1_pt","jet2_pt","jet3_pt","jet4_pt","jet1_eta","jet2_eta","jet3_eta","jet4_eta","jet1_phi","jet2_phi","jet3_phi","jet4_phi","Wjet1_pt","Wjet2_pt","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta","vbfjet1_phi","vbfjet2_phi", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","Njet", "lep_pt","lep_eta","MET_et","mT","mjjTagged","dPhiTaggedJets","dRTaggedJets", "dEtaMax","ptjjMax"} ;
  //const int nHistType = 20 ;  std::string histType[nHistType]   = {"dEtaTaggedJets","dRTaggedJets","mjjTagged", "jet1_pt","jet2_pt","jet3_pt","jet4_pt","jet1_eta","jet2_eta","jet3_eta","jet4_eta","lep_pt","lep_eta","Mwjj","ptwjj","ptwlep","Mlvjj","dRWjets","dEtaMax","ptjjMax"} ; //for aQGC limit estimation 

  
  
  //const int nHistType =22;  std::string histType[nHistType]   = { "dEtaTaggedJets","dPhiTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","vbfjet1_eta","vbfjet2_eta", "ptjjTagged","ptwjj","ptwlep","Mlvjj", "Mwjj","dRWjets","lep_pt","lep_eta","MET_et","mT","Njet","Nfatjet","fatjet_pt","fatjet_eta"};
  const int nHistType =5;  std::string histType[nHistType]   = { "Mwjj","fatjetM_pt150","fatjetM_pt200","fatjetM_pt250","fatjetM_pt300"};
  

  //const int nHistType =11 ;  std::string histType[nHistType]   = { "dEtaTaggedJets","dRTaggedJets", "mjjTagged","vbfjet1_pt","vbfjet2_pt","Wjet1_pt","Wjet2_pt","ptjjTagged", "Mwjj","MET_et", "Mlvjj"} ;
  
#else
  const int NFlavors   = 1 ; std::string flavorChannel[NFlavors]= {"em"} ;
  const int nCuts      = 1 ; std::string cuts[nCuts]  = { "WBF_CR_Top" };
  const int nHistType  = 1 ; std::string histType[nHistType]   = { "MET_et" } ;
#endif

 

  
  std::vector<Sample> vs; 
  vs.push_back(Sample("Data"          , kBlack     , "Data"        ));
  vs.push_back(Sample("WZZZWg"   , kMagenta+2 , "Diboson" ));
  vs.push_back(Sample("Zjets"   , kBlue , "Z+jets" ));
  vs.push_back(Sample("Wjets"         , kCyan      , "W+jets"      ));
  vs.push_back(Sample("Ttbar"           , kYellow    , "ttbar"         ));
  vs.push_back(Sample("SingleTop"           , kYellow-5    , "single Top"         ));
  

  vs.push_back(Sample("QCD"        , kGreen     , "QCD"      ));

  


  bool useSF = false;//true;


  int crx = 800; 
  int cry = 580;

#if wide
  crx = 1000;
#endif 
  if ( drawTwoPads ){   crx= 750; cry = 700;         }


  TString channelName("");
  int canvasIndex = 0 ; 

  TString histName("");
  
  const int range = 700; 
  TCanvas *cr[range];


  int NCanvasToOpen    = nCuts * nHistType * NFlavors; 


  if (  range < NCanvasToOpen ){  
    cout << "Error : You have to increase the number of [range] to more than " << NCanvasToOpen+1 << endl;       
    exit(2);
  }

  for (int i=0; i<NCanvasToOpen; i++){
    cr[i] = new TCanvas(Form("c%i",i), Form("c%i",i) , 0, 0, crx, cry );
  }

  
  TString lumi = "20.3" ;
  TFile *bkgTemplate= new TFile("bkgTemplate.root", "RECREATE");

  for (int icut=0; icut<nCuts; icut++) 
    {
      for ( int itype=0; itype<nHistType; itype++)
	{
	  for ( int iflavor=0 ; iflavor< NFlavors; iflavor++)
	    {
	      
	      channelName = flavorChannel[iflavor] + "_" + cuts[icut] + "_" + histType[itype];
	      cout << "\n > Starting " << channelName  << "  index "<< canvasIndex  <<endl;
	      makeOnePlot( finput, cr[canvasIndex], channelName, cuts[icut] , drawTwoPads, lumi, histType[itype], &vs , useSF);
	      cr[canvasIndex]->Print(Form("EPS/plot_%s.eps",channelName.Data() ));
	      cr[canvasIndex]->Print(Form("EPS/plot_%s.pdf",channelName.Data() ));
	      
	      cout << "end plotting " << channelName  << "  index "<< canvasIndex  <<endl;
	      canvasIndex++ ;
	    }
	}
    }

  bkgTemplate->Close();
  
  ///latex file for presentations

  FILE *  pFile = fopen( "./EPS/includeplotsforbeamer.tex" , "w");
  //FILE *  pFileNew = fopen( "./EPS/includeplotsforbeamerNew.tex" , "w");

  //fprintf( pFile, "\\section{Plots for H$\\rightarrow WW \\rightarrow \\ell\\nu jj $}\n" );
  

  TString flavorForTex("");
  TString histNameForTex("");
  //TString FrameStart(""); 
  
  for ( int itype=0; itype<nHistType; itype++){
    
    
    for (int icut=0; icut<nCuts ; icut++) {
    
      TString FrameStart(""); 
      
      for ( int iflavor=0 ; iflavor<NFlavors ; iflavor++){ 
	
	
	  TString thiscut = cuts[icut];
	  thiscut = thiscut.ReplaceAll("WBF_", ""); //remove the unnecessary WBF	  
	  thiscut = thiscut.ReplaceAll("_", "\\_");	  
	  channelName = flavorChannel[iflavor] + "_" + cuts[icut];
	  flavorForTex = flavorChannel[iflavor]; 
	  flavorForTex = flavorForTex.ReplaceAll("u", "\\mu");
	  histName= histType[itype];
	  histNameForTex= histType[itype];
	  histNameForTex= histNameForTex.ReplaceAll("_", "\\_");

	  //-------------------------------------------
	  // /*
	  FrameStart += Form( "\\begin{frame}\n") ;
	  FrameStart += Form( "\\footnotesize{\\frametitle{Plot of %s for %s Channel in %s}} \n",histNameForTex.Data(), flavorForTex.Data(), thiscut.Data() ); 
	  FrameStart += Form( "\\begin{figure}\n") ;
	 
	  FrameStart += Form( "{\\includegraphics[width=0.7\\textwidth]{/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/EPS/plot_%s_%s.pdf}}\n",channelName.Data(),histName.Data()); //Don't use ForTex here
	  
	  FrameStart += Form( "\\end{figure}\n") ;
	  FrameStart += Form( "\\end{frame}\n") ;

	  // */
	  //------------------------------------------
	  /*
	  //comparison
	  FrameStart += Form( "\\begin{frame}\n") ;
	  FrameStart += Form( "\\footnotesize{\\frametitle{Plot of %s for %s Channel in %s}} \n",histNameForTex.Data(), flavorForTex.Data(), thiscut.Data() ); 
	  FrameStart += Form( "\\begin{figure}\n") ;
	  FrameStart += Form( "\\begin{subfigure}\n") ;
	  //FrameStart += Form( "\\begin{subfigure}[b]{0.45\\textwidth}\n") ;
	  FrameStart += Form( "{\\includegraphics[width=0.45\\textwidth]{/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/EPS/plot_%s_%s.pdf}}\n",channelName.Data(),histName.Data()); //Don't use ForTex here
	  //FrameStart += Form( "\\caption{Before}\n") ;
	  FrameStart += Form( "\\end{subfigure}\n") ;

	  FrameStart += Form( "\\begin{subfigure}\n") ;
	  //FrameStart += Form( "\\begin{subfigure}[b]{0.45\\textwidth}\n") ;
	  FrameStart += Form( "{\\includegraphics[width=0.45\\textwidth]{/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/EPS_lep30_met30_mjj0_mt40_common_RW/plot_%s_%s.pdf}}\n",channelName.Data(),histName.Data()); //Don't use ForTex here
	  //FrameStart += Form( "\\caption{After}\n") ;
	  FrameStart += Form( "\\end{subfigure}\n") ;

	  FrameStart += Form( "\\caption{left:before, right:after}\n") ;
	  FrameStart += Form( "\\end{figure}\n") ;
	  FrameStart += Form( "\\end{frame}\n") ;
	  */
	  //------------------------------------------------
	  
	  // if (!(iflavor%2)){ ///the inner loop
	  //   FrameStart += Form( "\\begin{frame} \n"  );
	  //   FrameStart += Form( "\\begin{figure}\n") ;
	  	  
	  //   FrameStart += Form( "\\subfigure{\\includegraphics[width=0.4\\textwidth]{/export/home/azaman/haifeng2/reader/run/plots_nosystematics/EPS/plot_%s_%s.pdf}}\n",channelName.Data(),histName.Data());
	  //no end figure or end frame here
	    
	  // }
	  
	  
	  // if (iflavor%2){ ///the inner loop
	  //no begin figure or begin frame here
	  //   FrameStart += Form( "\\subfigure{\\includegraphics[width=0.4\\textwidth]{/export/home/azaman/haifeng2/reader/run/plots_nosystematics/EPS/plot_%s_%s.pdf}}\n",channelName.Data(),histName.Data());
	  //   FrameStart += Form( "\\end{figure}\n") ;
	  //   FrameStart += Form( "\\end{frame}\n") ;
	  // }

	  //------------------------------
	  
	}
      
      
      //fprintf( pFile, "%s\n", Content.Data() );
      fprintf( pFile, "%s\n", FrameStart.Data() );
      
    }
  }

  ////reweighting ttbar sample using dEtaTagged plot in CR_Top

#if doReweightTtbar
  
  FILE *  sgFile;
  sgFile = fopen( "output/reweightFactor.txt" , "w");
  
  TH1  *hDataRW, *hWZZZWgRW, *hZjetsRW, *hWjetsRW,*hTtbarRW, *hSingleTopRW, *hQCDRW; ///hard coding

  bool merged= true;
  /*
  hDataRW=(TH1*)finput->Get("H_Data_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hDataRW->Add((TH1*)finput->Get("H_Data_ep_WBF_CR_Top_dEtaTaggedJets"));
    hDataRW->Add((TH1*)finput->Get("H_Data_mm_WBF_CR_Top_dEtaTaggedJets"));
    hDataRW->Add((TH1*)finput->Get("H_Data_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hWZZZWgRW=(TH1*)finput->Get("H_WZZZWg_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hWZZZWgRW->Add((TH1*)finput->Get("H_WZZZWg_ep_WBF_CR_Top_dEtaTaggedJets"));
    hWZZZWgRW->Add((TH1*)finput->Get("H_WZZZWg_mm_WBF_CR_Top_dEtaTaggedJets"));
    hWZZZWgRW->Add((TH1*)finput->Get("H_WZZZWg_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hZjetsRW=(TH1*)finput->Get("H_Zjets_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hZjetsRW->Add((TH1*)finput->Get("H_Zjets_ep_WBF_CR_Top_dEtaTaggedJets"));
    hZjetsRW->Add((TH1*)finput->Get("H_Zjets_mm_WBF_CR_Top_dEtaTaggedJets"));
    hZjetsRW->Add((TH1*)finput->Get("H_Zjets_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hWjetsRW=(TH1*)finput->Get("H_Wjets_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hWjetsRW->Add((TH1*)finput->Get("H_Wjets_ep_WBF_CR_Top_dEtaTaggedJets"));
    hWjetsRW->Add((TH1*)finput->Get("H_Wjets_mm_WBF_CR_Top_dEtaTaggedJets"));
    hWjetsRW->Add((TH1*)finput->Get("H_Wjets_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hQCDRW=(TH1*)finput->Get("H_QCD_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hQCDRW->Add((TH1*)finput->Get("H_QCD_ep_WBF_CR_Top_dEtaTaggedJets"));
    hQCDRW->Add((TH1*)finput->Get("H_QCD_mm_WBF_CR_Top_dEtaTaggedJets"));
    hQCDRW->Add((TH1*)finput->Get("H_QCD_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hSingleTopRW=(TH1*)finput->Get("H_SingleTop_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hSingleTopRW->Add((TH1*)finput->Get("H_SingleTop_ep_WBF_CR_Top_dEtaTaggedJets"));
    hSingleTopRW->Add((TH1*)finput->Get("H_SingleTop_mm_WBF_CR_Top_dEtaTaggedJets"));
    hSingleTopRW->Add((TH1*)finput->Get("H_SingleTop_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  hTtbarRW=(TH1*)finput->Get("H_Ttbar_em_WBF_CR_Top_dEtaTaggedJets");
  if (merged){
    hTtbarRW->Add((TH1*)finput->Get("H_Ttbar_ep_WBF_CR_Top_dEtaTaggedJets"));
    hTtbarRW->Add((TH1*)finput->Get("H_Ttbar_mm_WBF_CR_Top_dEtaTaggedJets"));
    hTtbarRW->Add((TH1*)finput->Get("H_Ttbar_mp_WBF_CR_Top_dEtaTaggedJets"));
  }
  */

  
  //cout<<finput->GetName()<<endl;
  TString hist="dEtaTaggedJets";
  hDataRW=mergeForReweighting(finput, "Data", "CR_Top",hist );
  hWZZZWgRW=mergeForReweighting(finput, "WZZZWg", "CR_Top",hist );
  hWjetsRW=mergeForReweighting(finput, "Wjets", "CR_Top",hist );
  hZjetsRW=mergeForReweighting(finput, "Zjets", "CR_Top",hist );
  hTtbarRW=mergeForReweighting(finput, "Ttbar", "CR_Top",hist );
  hSingleTopRW=mergeForReweighting(finput, "SingleTop", "CR_Top",hist );
  hQCDRW=mergeForReweighting(finput, "QCD", "CR_Top",hist );

  
  hDataRW->Add(hWjetsRW,-1);
  hDataRW->Add(hZjetsRW,-1);
  hDataRW->Add(hWZZZWgRW,-1);
  hDataRW->Add(hSingleTopRW,-1);
  hDataRW->Add(hQCDRW,-1); //hDataRW is data minus all bkg except ttbar
  
  hDataRW->Scale(1/hDataRW->Integral()); //what about overflow bin? already done in GetHistSample
  
  hTtbarRW->Scale(1/hTtbarRW->Integral());

  int Nbins=hDataRW->GetNbinsX();
  
  float reweightFactor[Nbins];
  TString line="";
  
  //cout<<"Nbins= "<<hDataRW->GetNbinsX()<<endl;
  for (int i=0; i<hDataRW->GetNbinsX();++i){
    
    reweightFactor[i]=hDataRW->GetBinContent(i+1)/hTtbarRW->GetBinContent(i+1);//reweightFactor index runs from 0 to 79, bin number runs from 1 to 80
    if (reweightFactor[i]<0.){reweightFactor[i]=0.;} //negative reweight factors set to zero
    line += Form( "%d %f \n" ,i,reweightFactor[i] );
    cout<<"reweightFactor["<<i<<"]= "<<reweightFactor[i]<<endl;
    
    //fprintf( sgFile, "%s \n" , line.Data() );
    
  }
  //cout<<"print "<<line<<endl;
  fprintf( sgFile, "%s " , line.Data() );
  
  TCanvas *c2 = new TCanvas();
  float ratio_size = 0.35 ;
  TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);

  plotReweightFactor(c2,p1,p2,hDataRW, hTtbarRW, "ttbar");

  c2->Print("EPS/plots_reweightTtbar.pdf","pdf");
  p1->Clear();
  p2->Clear();
  
#endif 
  
#if doReweightWjets
  FILE *  sgFile;
  sgFile = fopen( "output/reweightFactorWjets.txt" , "w");
  bool merged= true;
  TH1  *hDataRW, *hWZZZWgRW, *hZjetsRW, *hWjetsRW,*hTtbarRW, *hSingleTopRW, *hQCDRW; ///hard coding
  TString hist="dEtaTaggedJets"; 
  //TString hist="dPhiWjets"; //Viviana
  //TString hist="dPhiTaggedJets"; //Viviana
  
  hDataRW=mergeForReweighting(finput, "Data", "CR_Wjj",hist );
  hWZZZWgRW=mergeForReweighting(finput, "WZZZWg", "CR_Wjj",hist );
  hWjetsRW=mergeForReweighting(finput, "Wjets", "CR_Wjj",hist );
  hZjetsRW=mergeForReweighting(finput, "Zjets", "CR_Wjj",hist );
  hTtbarRW=mergeForReweighting(finput, "Ttbar", "CR_Wjj",hist );
  hSingleTopRW=mergeForReweighting(finput, "SingleTop", "CR_Wjj",hist );
  hQCDRW=mergeForReweighting(finput, "QCD", "CR_Wjj",hist );

  

  hDataRW->Add(hTtbarRW,-1);
  hDataRW->Add(hZjetsRW,-1);
  hDataRW->Add(hWZZZWgRW,-1);
  hDataRW->Add(hSingleTopRW,-1);
  hDataRW->Add(hQCDRW,-1); //hDataRW is data minus all bkg except W+jets

  hDataRW->Scale(1/hDataRW->Integral()); //what about overflow bin? already done in GetHistSample
  hWjetsRW->Scale(1/hWjetsRW->Integral());

  int Nbins=hDataRW->GetNbinsX();
  
  float reweightFactor[Nbins];
  TString line="";
  
  //cout<<"Nbins= "<<hDataRW->GetNbinsX()<<endl;
  for (int i=0; i<hDataRW->GetNbinsX();++i){
    if (hDataRW->GetBinContent(i+1)==0. && hWjetsRW->GetBinContent(i+1)==0)
      {reweightFactor[i]=1.;}
    else{
      reweightFactor[i]=hDataRW->GetBinContent(i+1)/hWjetsRW->GetBinContent(i+1); //reweightFactor index runs from 0 to 79, bin number runs from 1 to 80
    }
    if (reweightFactor[i]<0.){reweightFactor[i]=0.;} //negative reweight factors set to zero
   
    line += Form( "%d %f \n" ,i,reweightFactor[i] );
    cout<<"reweightFactor["<<i<<"]= "<<reweightFactor[i]<<endl;
      
    //fprintf( sgFile, "%s \n" , line.Data() );
      
  }
  fprintf( sgFile, "%s " , line.Data() );

  TCanvas *c2 = new TCanvas();
  float ratio_size = 0.35 ;
  TPad* p1 = new TPad("p1","p1",0.01, ratio_size ,0.99,0.99);
  TPad* p2 = new TPad("p2","p2",0.01,0.01,0.99, ratio_size);

  plotReweightFactor(c2,p1,p2,hDataRW, hWjetsRW, "W+jets");

  c2->Print("EPS/plots_reweightWjets.pdf","pdf");
  p1->Clear();
  p2->Clear();
  
#endif 
  
}


#ifndef __CINT__
int main () { plotMakerHww(); return 0; }
#endif


TH1* mergeForReweighting(TFile* finput, TString sampleName,TString region, TString histName){

  TH1  *h;
  
  h=(TH1*)finput->Get(Form("H_%s_em_WBF_%s_%s", sampleName.Data(),region.Data(),histName.Data()));
  h->Add((TH1*)finput->Get(Form("H_%s_ep_WBF_%s_%s", sampleName.Data(),region.Data(), histName.Data())));
  h->Add((TH1*)finput->Get(Form("H_%s_mm_WBF_%s_%s", sampleName.Data(),region.Data(), histName.Data())));
  h->Add((TH1*)finput->Get(Form("H_%s_mp_WBF_%s_%s", sampleName.Data(),region.Data(), histName.Data())));
    
  
  return h;
}

void plotReweightFactor(TCanvas* c2, TPad* p1, TPad* p2, TH1* hData, TH1* hBkg, const TString sampleName){

  c2->cd();
  p1->Draw();
  p1->SetBottomMargin(0.00);
  p1->SetRightMargin(0.12);
  
  p2->Draw();
  p2->SetTopMargin(0.00);
  p2->SetBottomMargin(0.25);
  p2->SetRightMargin(0.12);

  p1->Draw();
  p1->cd();
  hData->Scale(1/hData->Integral());
  hData->Draw();
  hData->SetLineColor(kBlue);
  
  hData->SetTitle("Reweight factor "+sampleName);	  
  hBkg->Scale(1/hBkg->Integral());
  hBkg->Draw("same");
  hBkg->SetLineColor(kRed);
  double maxi= std::max(hData->GetBinContent(hData->GetMaximumBin()),hBkg->GetBinContent(hBkg->GetMaximumBin()));
  hData->SetMaximum(maxi*1.2);
  
  TLegend* l=new TLegend(0.7,0.7,0.9,0.9);
  
  l->AddEntry(hData,"Bkg-subtracted data","l");
  l->AddEntry(hBkg,sampleName,"l");
  l->Draw();
  
  double xstart=hData->GetBinLowEdge(1);
  double xend=hData->GetBinLowEdge(hData->GetNbinsX()+1);
  
  p2->cd();
  gStyle->SetOptStat(0);
  TH1F *ratioHist = (TH1F*)hData->Clone();
  ratioHist->Divide(hBkg);
  ratioHist->GetYaxis()->SetRangeUser(0., 2.5);
  ratioHist->Draw();
  ratioHist->SetTitle("ratio");
  TLine* horiz_line = new TLine(0.01,1.0,7.99,1.0);
  horiz_line->SetLineStyle(2);
  horiz_line->DrawLine(xstart,1.0,xend,1.0);
  

}
