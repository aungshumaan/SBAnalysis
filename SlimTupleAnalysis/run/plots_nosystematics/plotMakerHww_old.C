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

void plotMakerHww()
{

  
  gStyle->SetOptStat(kFALSE);
  
  TString fileName="../hwwlvqq.root";
  TFile *finput = new TFile(fileName) ;
  if (finput->IsZombie()) { cout << "Error : can not find file " << fileName << endl; exit(1); }


#if !test
  const int NFavlors   = 4 ;  std::string flavorChannel[NFavlors]= {"em", "ep", "mm", "mp"} ;
  //const int NFavlors   = 1 ;  std::string flavorChannel[NFavlors]= {"em"} ;
  const int nCuts = 3 ;
  std::string cuts[nCuts]  = { 

    //"WBF_MET",
    //"WBF_BTAG",

    "WBF_SR", 
    "WBF_CR_Wjj",
    "WBF_CR_Top",
  } ;

//  const int nHistType = 11 ;  
//  std::string histType[nHistType]   = { "Mlvjj","MET_et", 
//					"dPhi_wjet", "dPhi_LepMet", "dPhi_LepWjet1", "dPhi_MetWjet1", 
//					"dPhi_WhadWlep", "Whad_pt", "Wlep_pt", "dEta_WhadWlep", 
//					"ptbalance"} ;
  const int nHistType = 4 ;  std::string histType[nHistType]   = { "Mlvjj", "Mwjj", "Njet", "MET_et" } ;
  
#else
  const int NFavlors   = 1 ; std::string flavorChannel[NFavlors]= {"ep"} ;
  const int nCuts      = 1 ; std::string cuts[nCuts]  = { "ggF_LeadJetPt" };
  const int nHistType  = 1 ; std::string histType[nHistType]   = { "Mlvjj" } ;
#endif

 

  
  std::vector<Sample> vs; 
  vs.push_back(Sample("Data"          , kBlack     , "Data"        ));
  vs.push_back(Sample("WZZZWg"   , kMagenta+2 , "Diboson/Zjets" ));
  vs.push_back(Sample("Zjets"   , kBlue , "Z+jets" ));
  vs.push_back(Sample("Ttbar"           , kYellow    , "ttbar"         ));
  vs.push_back(Sample("SingleTop"           , kYellow-5    , "single Top"         ));
  vs.push_back(Sample("Wjets"         , kCyan      , "W+jets"      ));
  //vs.push_back(Sample("Signal[500]"        , kRed-8     , "H[500]"      ));
//  vs.push_back(Sample("Signal[600]"        , kRed-7     , "H[600]"      ));
//  vs.push_back(Sample("Signal[700]"        , kRed-6     , "H[700]"      ));
//  vs.push_back(Sample("Signal[800]"        , kRed-5     , "H[800]"      ));
//  vs.push_back(Sample("Signal[900]"        , kRed-2     , "H[900]"      ));





  bool useSF = false; //true;

  bool drawTwoPads = true ;
  int crx = 800; 
  int cry = 580;

#if wide
  crx = 1000;
#endif 
  if ( drawTwoPads ){   crx= 750; cry = 700;         }


  TString channelName("");
  int canvasIndex = 0 ; 

  const int range = 700; 
  TCanvas *cr[range];


  int NCanvasToOpen    = nCuts * nHistType * NFavlors; 


  if (  range < NCanvasToOpen ){  
    cout << "Error : You have to increase the number of [range] to more than " << NCanvasToOpen+1 << endl;       
    exit(2);
  }

  for (int i=0; i<NCanvasToOpen; i++){
    cr[i] = new TCanvas(Form("c%i",i), Form("c%i",i) , 0, 0, crx, cry );
  }

  TString lumi = "20.7" ;

  for (int icut=0; icut<nCuts; icut++) 
    {
      for ( int itype=0; itype<nHistType; itype++)
	{
	  for ( int iflavor=0 ; iflavor< NFavlors; iflavor++)
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

  


  FILE *  pFile = fopen( "./EPS/inclueplotsforbeamer.tex" , "w");

  fprintf( pFile, "\\section{Plots for H$\\rightarrow WW \\rightarrow \\ell\\nu jj $}\n" );

  TString flavorForTex("");
  for (int icut=0; icut<nCuts ; icut++) {
     
    TString thiscut = cuts[icut]; 
    thiscut = thiscut.ReplaceAll("_", "\\_"); 

    fprintf( pFile, "\\subsection{Plots after %s Cuts}\n", thiscut.Data() );
    
    for ( int iflavor=0 ; iflavor<NFavlors ; iflavor++){

      channelName = flavorChannel[iflavor] + "_" + cuts[icut];
      flavorForTex = flavorChannel[iflavor]; 
      flavorForTex = flavorForTex.ReplaceAll("u", "\\mu");
     
     
      TString FrameStart(""), FrameEnd(""), Content(""); 
      FrameStart += Form( "\\frame{ \n"  );
      FrameStart += Form( "\\frametitle{Plots for $%s$ Channel after %s} \n", flavorForTex.Data(), thiscut.Data() ); 
      FrameStart += Form( "\\centering \\begin{pgfpicture}{0cm}{0cm}{12  cm}{8 cm} \n");

      FrameEnd   += "\\end{pgfpicture}  }\n" ;

 
      for ( int itype=0; itype<nHistType; itype++)
	{
	  
	  float x(0.),y(0.);
	  if ( itype%4 == 0 )  Content += FrameStart ; 
	  
	  if ( itype%4 == 0 ||itype%4 == 1 ) y = 4. ; 
	  if ( itype%4 == 1 ||itype%4 == 3 ) x = 5.7 ; 

#if wide
	  TString oneplot = 
	    Form( "\\pgfputat{\\pgfxy(%2.1f, %2.1f)}{\\pgfbox[left,base]{  \\pgfimage[width=5.5 cm, height=3 cm]{plot/plot_%s_%s} } } \n", 
		  x, y,  channelName.Data(), histType[itype].c_str() );
#else	  
	  TString oneplot = 
	    Form( "\\pgfputat{\\pgfxy(%2.1f, %2.1f)}{\\pgfbox[left,base]{  \\pgfimage[width=5.5 cm, height=4 cm]{plot/plot_%s_%s} } } \n", 
		  x, y,  channelName.Data(), histType[itype].c_str() );
#endif
	  Content += oneplot ;

	  if ( itype%4 == 3 || itype==nHistType-1)  Content += FrameEnd ; 
	}
      
      
      fprintf( pFile, "%s\n", Content.Data() );

    }
  }
  
 
  
}


#ifndef __CINT__
int main () { plotMakerHww(); return 0; }
#endif
