#include "CutFlowTool.h"
#include <TH1D.h>
#include <TH2F.h>
#include <TFile.h>

#include <cmath>

using namespace std;




void CutFlowTool::registCut(std::string cut, std::string CutDescribe){
  cutV this_cut ; ///typedef struct { std::string cut ;std::string cutDes ; } cutV ;std::vector<cutV> m_cut ;//from CutFlowTool.h
  this_cut.cut = cut ; 
  this_cut.cutDes = CutDescribe ;
  
  m_cut.push_back(this_cut) ;
}


void CutFlowTool::add(  int run, std::string cut, double EventWeight ){
  // Speed is important for this function.
  CutFlowTable[run][cut] += EventWeight ;
  StatErrorCutFlowTable [run][cut] += EventWeight*EventWeight ; 
};



void CutFlowTool::Print(){
 
  std::cout <<"\\begin{center}"                                                << std::endl;
  std::cout <<"\\begin{tabular}{|l|r|r|r|r|r|r|r|r|r|r|}"                      << std::endl;
  std::cout <<"\\hline"                                                        << std::endl;

  for ( itRun=CutFlowTable.begin() ; itRun != CutFlowTable.end(); ++itRun ){
    if (  itRun==CutFlowTable.begin()) {
      std::cout << "Run     "  ; 
      
      for ( itV = m_cut.begin(); itV != m_cut.end() ; ++itV ){
	std::string cuts = (*itV).cut ;
	std::cout << " & " << std::setw(10) << std::right << cuts ; 
      }
      std::cout << "  \\\\" << std::endl;
      std::cout <<"\\hline"                                                        << std::endl;
    }
    
    
    std::cout << (*itRun).first << "  " ;
    
    for ( itV = m_cut.begin(); itV != m_cut.end() ; ++itV ){
	std::string cuts = (*itV).cut ;
	double number = (*itRun).second[cuts] ;
	printf(" &%10.2f",  number );
    }

    std::cout << "  \\\\ "<< std::endl;

  }

  std::cout << "\\hline"           << std::endl;
  std::cout << "\\end{tabular}"         << std::endl;
  std::cout << "\\end{center}"     << std::endl;


};


void CutFlowTool::PrintI(){
 

  for ( itRun=CutFlowTable.begin() ; itRun != CutFlowTable.end(); ++itRun ){
    std::cout << (*itRun).first << endl ;
    std::cout << "----------------------------------" << endl;
    for ( itV = m_cut.begin(); itV != m_cut.end() ; ++itV ){
      std::string cuts = (*itV).cut ;
      double number = (*itRun).second[cuts] ;
      cout << std::setw(20) << std::left << cuts << " : " <<  number  << endl;
    }
    
  }



};



double CutFlowTool::getCutValue( int run, std::string cut ) {
  
  float value = CutFlowTable[run][cut] ;

  return value ;
};


void CutFlowTool::SaveToFile( TFile *foutput){ //Create the cutflow histograms

  if (!foutput) return ;
  
  foutput -> cd();
  
  if ( !gDirectory->Get("CutFlow") )
    foutput -> mkdir("CutFlow");
  
  gDirectory->cd("CutFlow");
  

  // Write cutflow to histograms
  for ( itRun=CutFlowTable.begin() ; itRun != CutFlowTable.end(); ++itRun ){
    
    
    int runNumber = (*itRun).first ;
    TString histname = Form("%d_CutFlow", runNumber);

    cout<<"Adding run "<<runNumber<<" to "<<histname<<" cut flow"<<endl;

    int _ncuts = m_cut.size() + 20;
    TH1D *cutflow = new TH1D(histname, histname, _ncuts, 0., float(_ncuts) );
    cutflow -> Sumw2();

    int binN = 1 ;
    for ( itV = m_cut.begin(); itV != m_cut.end() ; ++itV ){
      std::string cuts = (*itV).cut ;

      float number = (*itRun).second[cuts] ;
      cutflow->SetBinContent(binN, number);

      float error = StatErrorCutFlowTable [runNumber][cuts]; 
      error = std::sqrt( error );
      cutflow->SetBinError(binN, error);

      TString RCuts = cuts ;
      cutflow->GetXaxis()->SetBinLabel(binN,RCuts);
      binN++ ;
    }

    
    

  }


  

};
