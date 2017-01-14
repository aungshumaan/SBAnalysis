// This is  -*- C++ -*-
#ifndef EVENTRECORDER_H
#define EVENTRECORDER_H


#include <vector>
#include <string.h>

// Local 
#include "foo.hh"

class EventRecorder 
{

public : 
   
  EventRecorder(); 
  
  void SaveMainHiggsCandidates( const int &jetch, const foo *h1, const TString &flavor ) ; 
  void SaveOtherCandidates( const int &jetch, const foo *h1, const TString &flavor) ;
  void PrintHwwCandidates( FILE *pFile, const foo *h1, const TString &flavor) ; 
  void WriteEnd() ;

private :
  static const int njet = 3;
  static const std::string jetChannel[njet]  ;
  
  FILE *pFile[njet] , *pFileOtherMass[njet];

} ; 



const std::string EventRecorder::jetChannel[njet] = {"0jet", "1jet", "2jet"};


// cxx 
EventRecorder::EventRecorder()
{
  
  const int nOutPutVar = 15; 
  TString outPutVar[nOutPutVar] = { "DPhi", "mLL", "MT", "MetRel", "MET", "PtLL", "PtTot", 
				    "L1Pt", "L1Eta", "L2Pt", "L2Eta" , "JetPt", "JetEta" , "SV0", "CombNN" };
  string col("|rrrr|") ; 
  for ( int i=0; i<nOutPutVar; i++) col += "r" ;
  col += "|"; 

  
  for ( int ijet=0; ijet<njet; ijet++  )
    {
      // Standard
      pFile[ijet] = fopen(Form("HiggsWWCandidates_%s.tex", jetChannel[ijet].c_str() ) , "w");
  
      fprintf( pFile[ijet], "\\begin{tabular}{%s} \\hline  \n", col.c_str());
  
      TString eventInfo = Form(" %7s & %10s & %2s & %4s", "Run", "Event", "ch", "Njet");
      for ( int iv=0; iv<nOutPutVar; iv++ )  eventInfo += Form(" & %6s", outPutVar[iv].Data() );
      fprintf( pFile[ijet], "%s  \\\\ \n \\hline \n" , eventInfo.Data() );
  
    }

}

void EventRecorder::SaveMainHiggsCandidates( const int &jetch, const foo *h1, const TString &flavor) 
{

  PrintHwwCandidates( pFile[jetch], h1, flavor) ;

}

void EventRecorder::SaveOtherCandidates( const int &jetch, const foo *h1, const TString &flavor) 
{

  //PrintHwwCandidates( pFileOtherMass[jetch], h1, flavor) ;

}



void EventRecorder::PrintHwwCandidates( FILE *pFile, const foo *h1, const TString &flavor) 
{
  
  
  //TString evtInfo = Form(" %7d & %10d & %s & %4d ", h1->RunNumber , h1->EventNumber, flavor.Data(), h1->nJet ) ; 
  //TString evtdetail = Form( " %6.2f & %6.2f & %6.2f & %6.2f & %6.2f & %6.2f & %6.2f ", 
  //			    h1->dPhiLL, h1->mLL, h1->HwwMt, h1->MET_rel, h1->MET_et, h1->PtLL, h1->TotalPt  );
  //
  //TString lepInfo = Form( " %6.2f & %6.2f & %6.2f & %6.2f ", h1->lep1_pt, h1->lep1_eta, h1->lep2_pt, h1->lep2_eta ); 
  //TString jetInfo = Form( " %6.2f & %6.2f & %6.2f & %6.2f ", -999., -999., -999., -999. );  
  //if ( h1->nJet > 0 ) 
  //  jetInfo = Form( " %6.2f & %6.2f & %6.2f & %6.2f ", h1->jet_pt->at(0) , h1->jet_eta->at(0), -999., h1->jet_CombNN->at(0) );  
  //
  //TString totalEvent = evtInfo + "&" + evtdetail +"&" + lepInfo +"&"+ jetInfo ; 
  //
  //fprintf( pFile, "%s \\\\ \n" , totalEvent.Data() );

}




void EventRecorder::WriteEnd()
{

  for ( int ijet=0; ijet<njet; ijet++  )
    {
       fprintf( pFile[ijet] , "\\hline \\end{tabular} \n " ) ;
       fclose ( pFile[ijet] );
    }

}



#endif // END EVENTRECORDER_H
