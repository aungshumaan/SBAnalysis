// $id$
/*
 * @author Haifeng Li
 * @date   Aug, 2011
 * @brief  Print the cut flow tables from histgrams
*/


#include "TList.h"
#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "TClass.h"
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG 0

#define Blind 0

map <TString, int> FromBinLabelToBin ; 
enum sampleType {DATA, BG, SIG, NONE};

struct Sample
{
  Sample(string _name, sampleType _type, string _internalName, TH1* _hist=NULL)
  {
    name  =_name;
    type = _type;
    internalName = _internalName;
    hist = _hist;
    SF=-999.;
  }

  string name;
  sampleType type;
  string internalName;
  TH1* hist;
  float SF;
};


void splitString(std::string &s, std::vector<std::string>& lst, string sep="_" )
{
  for(size_t p=0, q=0; p!=s.npos; p=q)
    lst.push_back(s.substr(p+(p!=0), (q=s.find(sep, p+1))-p-(p!=0)));
  ///substr takes parameters pos(position of first char) and len(number of characters to add)
  ///s.find(sub,n): starting search from n-th character, returns the absolute position of the
  ///first occurance of string 'sub' in 's'.If no match is found it returns npos, i.e. size of string.
}


bool DuplicatedElement(const vector<string> *vec, const string &element)
{
  /* Check whether one vector already contains the element */
  for (unsigned int i=0; i<vec->size(); i++) {
    if (vec->at(i)==element) return true;
  }
  return false;
}

void getChannelNames(TH1* h,  vector<string> *flavorArr, vector<string> *modeArr, vector<string> *cutArr )
{

  /*Loop one histogram. Read all the bin labels and find the flavor, mode, cuts names */

  for (Int_t i=1; i<=h->GetNbinsX(); i++) {
    float events = h->GetBinContent(i); 
    string binlabel = h->GetXaxis()->GetBinLabel(i);
    cout<<"binlabel= "<<binlabel<<endl;
    if (  binlabel == "" && events < 0.01 ) continue;
    //printf("%2d)  %-25s  %10.1f \n", i, binlabel.c_str() , events) ;
    
    vector<string> lst;
    splitString(binlabel, lst);
    if (lst.size() < 3) {cout << "Error in names ->" << binlabel << endl;}
    string flavor = lst[0];
    string mode = lst[1];
    string cut;
    if (lst.size() == 3)cut = lst[2];
    if (lst.size() == 4)cut = lst[2]+"_"+lst[3];  //BTAG_FJ and MJJ_FJ

    
    cout << flavor << ", " << mode <<", " << cut << endl;
    if (!DuplicatedElement(flavorArr, flavor))  flavorArr->push_back(flavor);
    if (!DuplicatedElement(modeArr,   mode  ))  modeArr  ->push_back(mode  );
    if (!DuplicatedElement(cutArr,    cut   ))  cutArr   ->push_back(cut   );
    
  }
}


void printOneRun(TH1* h){


  for (Int_t i=1; i<=h->GetNbinsX(); i++) {
    float events = h->GetBinContent(i); 
    TString binlabel = h->GetXaxis()->GetBinLabel(i);
    if (  binlabel == "" && events < 0.01 ) continue;
    printf("%2d)  %15s  %10.1f \n", i, binlabel.Data() , events) ;
  }


}


float getOneCutValue(TH1* h, TString cutname){ ///given the cutflow histo and cutname, finds the number of events passing that cut

  if ( FromBinLabelToBin.find(cutname) == FromBinLabelToBin.end() ) { ///searching for the keys of the map
    cout << " Error : Cannot find cut " << cutname << " in " << h->GetName() << " histogram " << endl;
    exit(3);
  }

  int bini = FromBinLabelToBin[cutname] ; 
  int maxbin = h->GetNbinsX() ; 
  if ( bini > maxbin ){
    cout << " Error : bini is larger than the bin length " << maxbin << endl;
    exit(4);
  }
  
  
  float events = h->GetBinContent(bini); 
  TString binlabel = h->GetXaxis()->GetBinLabel(bini);

  if ( binlabel != cutname  ){
    cout << " Error : cutname " << cutname <<  " is not the same with given bin label " << binlabel  << endl;
    exit(5);
  }

  return events ; 
  
}

float getOneCutError(TH1* h, TString cutname){ ///given the cutflow histo and cutname, finds the error in nevents passing that cut

  if ( FromBinLabelToBin.find(cutname) == FromBinLabelToBin.end() ) { 
    cout << " Error : Cannot find cut " << cutname << " in " << h->GetName() << " histogram " << endl;
    exit(3);
  }

  int bini = FromBinLabelToBin[cutname] ; 
  int maxbin = h->GetNbinsX() ; 
  if ( bini > maxbin ){
    cout << " Error : bini is larger than the bin length " << maxbin << endl;
    exit(4);
  }

  float events = h->GetBinError( bini ); 
  TString binlabel = h->GetXaxis()->GetBinLabel(bini);

  if ( binlabel != cutname  ){
    cout << " Error : cutname " << cutname <<  " is not the same with given bin label " << binlabel  << endl;
    exit(5);
  }

  return events ; 
  
}



void GetBinLabelMap( TH1* h ) ///maps binLabel to a bin number
{
  
  for (Int_t i=1; i<=h->GetNbinsX(); i++) {
    TString binlabel = h->GetXaxis()->GetBinLabel(i);
    FromBinLabelToBin [binlabel] = i ; 
  }
}

TH1* getOneHist(TFile *finput, TString histname, TString cloneName) 
{
  /* Get sigle histogram from input root file. 
   * Return error if it can not find that histograms. 
   * Check whether Sumw2 is already setup. Set it up if no. 
   */

  if ( !finput->Get(histname)) { cout << " getOneHist :: Error : can not find histogram " << histname << endl;exit(1); }
  TH1 *h = ( TH1*) finput->Get( histname )->Clone( cloneName ) ; 
  if ( !h->GetSumw2N() )h->Sumw2();
  return h;
}

void GetHistSample(vector<Sample>* vs , TFile *finput)   ///build hBG and hSig from cutflow histograms in the root file so that sum of all bkg or signal can be printed on the cutflow table.
{
  
  TH1 *hBG=NULL, *hSig=NULL;
  for (unsigned int i=0; i<(*vs).size(); i++) {
    Sample *sam= &((*vs)[i]);

    vector<string> lst;
    splitString(sam->internalName, lst, ";"); ///for example: "H_ggF_300;H_VBF_300"
    cout << "size " <<  lst.size()  << " " << sam->internalName << endl;

    TH1 *h; 
    for (unsigned int jj=0; jj<lst.size(); jj++) { 

      TString histname = Form("CutFlow/%s_CutFlow", (lst[jj]).c_str()); //CutFlow directory inside the root file
      TString cloneName = "Clone_"+lst[jj] ; 
      TH1 *thisHist= getOneHist( finput, histname, cloneName);
      if (!thisHist) { cout << " GetHistSample::Error : can not find histogram for " << histname << endl; exit(1); }
      if (jj==0)  h = thisHist ; 
      else       h->Add(thisHist);
    }
    

//    TString histname = Form("CutFlow/%s_CutFlow", (sam->internalName).c_str());
//    //cout << histname << endl;
//    TString cloneName = "h"+sam->name ; 
//    TH1 *h = getOneHist( finput, histname, cloneName);


    
    sam->hist = h; //insert the cutflow histogram in Sample
    // Signal
    //if (sam->type==SIG) { 
    //  if (!hSig) hSig=(TH1*)h->Clone("hSig") ;
    //  else hSig->Add(h);
    //}
    // Background
    if (sam->type==BG) {
      if (!hBG) hBG = (TH1*)h->Clone("hBG"); 
      else      hBG -> Add(h); ///Adding all the bkg together
    }
     
    lst.clear();
   }

  //(*vs).push_back(Sample("Signal", NONE, "", hSig));
  (*vs).push_back(Sample("BG",     NONE, "", hBG )); ///&&&& Sum of all bkg
  

}

void interCutFlow(){

  //   TFile *fInput = new TFile("/export/home/blindqui/analysis/VBS/SlimTupleAnalysis/run/fakeEstimation/hwwlvqq.root");  
  TFile *fInput = new TFile("/export/home/blindqui/analysis/VBS/SlimTupleAnalysis/run/fakeEstimation/hwwlvqqAungshumansList.root");

  //  TFile *fInput = new TFile("/export/home/blindqui/analysis/VBS/SlimTupleAnalysis/run/hwwSigTest.root");

  // TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_noveto_signalOnly.root");
  // TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq_tight_fat12_noveto_signalOnly.root");


  //TFile *fInput = new TFile("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.2_signalOnly.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10_signalOnly.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10_noTtbarOrBtagWeight.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_v10.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/hwwlvqq_lep30_met30_mjj0_mt40_AlpgenInclWjets_common.root");

  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/fakeEstimation/lvqqNoMetFakeRegion.root");///this is for QCD CR
  //TFile *fInput = new TFile("/export/home/azaman/haifeng2/reader/run/fakeEstimation/lvqqNoMetFakeRegion_lep30_met25_mjj0_mt40.root");

  //TFile *fInput = new TFile("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_lhf06_periodA_2.44.root");
  //TFile *fInput = new TFile("/export/home/azaman/haifeng4/SlimTupleAnalysis/run/hwwlvqq_az_periodA_2.44.root");
    
  map<std::string, TH1*> FromNameToTH1 ; 
  
  ///HARD CODING!!!
  std::vector<Sample> vs; ///name, type,internalName, TH1* hist
  // /* &&&&
  //vs.push_back(Sample("Data"          , DATA , "888888")); ///the internal name used to be "888888"
  /////vs.push_back(Sample("Data"          , BG , "888888")); /// when only using data
  vs.push_back(Sample("Wjets"         , BG   , "Wjets"));
  vs.push_back(Sample("Ttbar"           , BG   , "Ttbar"));
  vs.push_back(Sample("SingleTop"           , BG   , "SingleTop"));
  vs.push_back(Sample("Diboson" , BG   , "WZZZWg"));
  vs.push_back(Sample("Zjets" , BG   , "Zjets"));
  // */
  
  // vs.push_back(Sample("WW"         , BG   , "WW"));
  // vs.push_back(Sample("WZ"           , BG   , "WZ"));
  // vs.push_back(Sample("ZZ"           , BG   , "ZZ"));
  // vs.push_back(Sample("Wgamma" , BG   , "Wgamma"));
  // vs.push_back(Sample("Zgamma" , BG   , "Zgamma"));
  
  //&&&&
  /*
  vs.push_back(Sample("WV0,0" , BG   , "VBS_WV_0_0"));
  vs.push_back(Sample("WV0,02" , BG   , "VBS_WV_0_02"));
  vs.push_back(Sample("WV03,0" , BG   , "VBS_WV_03_0"));
  vs.push_back(Sample("ZV0,0" , BG   , "VBS_ZV_0_0"));
  vs.push_back(Sample("ZV0,02" , BG   , "VBS_ZV_0_02"));
  vs.push_back(Sample("ZV03,0" , BG   , "VBS_ZV_03_0"));
  */
    
  //vs.push_back(Sample("Signal[700]"   , SIG  , "H_ggF_700;H_VBF_700" ) );
 

	     

  // Get histograms pointers from file
  GetHistSample(&vs, fInput);

  for (unsigned int i=0; i<vs.size(); i++) FromNameToTH1[vs[i].name] = vs[i].hist; ///maps sample names to histograms
  
  // Get table titles
  vector<string> sampleTable; 
  //sampleTable.push_back("Signal"); 

  for (unsigned int i=0; i<vs.size(); i++) { if (vs[i].type==SIG) sampleTable.push_back(vs[i].name) ; }
  for (unsigned int i=0; i<vs.size(); i++) { if (vs[i].type==BG ) sampleTable.push_back(vs[i].name) ; }
  /////
  //sampleTable.push_back("BG"); //&&&& Sum of all bkg, just commenting out this one line should make sure you don't see a row for sum of bkg.

#if Blind
#else
  //sampleTable.push_back("Data"); //&&&& if no data, comment out this line
#endif

  

  cout << "\n > Samples : " ;
  for (unsigned int i=0; i<sampleTable.size(); i++) {  cout << sampleTable[i] << ", ";} 
  cout << "\n" << endl;

  
  // Make the bin label to bin number map

  GetBinLabelMap( FromNameToTH1["BG"] ); 

  //--------------------------------------------
  // Get Meta Data
  vector<string> flavorArr, modeArr, cutArr;

  getChannelNames( FromNameToTH1["BG"] , &flavorArr, &modeArr, &cutArr); 
  
  cout << "flavor = " << endl;
  for (unsigned int i=0; i<flavorArr.size(); i++) cout << "       " <<  flavorArr[i] << endl;
  
  cout << "mode = " << endl;
  for (unsigned int i=0; i<modeArr.size(); i++) cout << "       " <<  modeArr[i] << endl;
  cout << "cut = " << endl;
  for (unsigned int i=0; i<cutArr.size(); i++) cout <<"       " <<  cutArr[i] << endl;


  //--------------------------------------------
  // Printing
  for (unsigned int imode=0; imode<modeArr.size(); imode++){
    for (unsigned  int iflavor=0 ; iflavor<flavorArr.size() ; iflavor++){
      
      string channelName=   flavorArr[iflavor] + "_" +  modeArr[imode] ;

      cout << ">>> plotting summary table for " << channelName << " ... " << endl ;

      FILE *  pFile;
      pFile = fopen(Form("tables/cutflow_summary_%s_%s.tex", channelName.c_str(), "Nominal") , "w");
      
      if(pFile == NULL){
	cout<<"Unable to create output tex file.  Please verify that the 'tables' directory exists."<<endl;
	exit(0);
      }
      
      string col = "|l|" ; 
      for ( unsigned int isample=0; isample<sampleTable.size(); isample++) col += "r|" ;
      fprintf( pFile, "\\begin{tabular}{%s} \\hline \n", col.c_str());

      fprintf( pFile, " %10s ", "Selection");
      for ( unsigned int isample=0; isample<sampleTable.size(); isample++) 	fprintf( pFile,  " & %10s ", sampleTable[isample].c_str()  );
      fprintf( pFile, "\\\\ \\hline \n") ;
      
      for (unsigned int icut=0; icut<cutArr.size() ; icut++) {
	  TString oriCutname, outputCutName ;
	  oriCutname =  channelName + "_" +cutArr[icut]; 
	  outputCutName = cutArr[icut].c_str() ; 
	  outputCutName = outputCutName.ReplaceAll("_", "\\_");
    	
	  fprintf( pFile, " %10s ",  outputCutName.Data()  );
	  
	  for ( unsigned int isample=0; isample<sampleTable.size(); isample++)   {
	    float value = getOneCutValue( FromNameToTH1[ sampleTable[isample] ] ,  oriCutname ) ; 
	    float error = getOneCutError( FromNameToTH1[ sampleTable[isample] ] ,  oriCutname ) ; 
	    if ( sampleTable[isample] == "Data" ){ fprintf( pFile,  " & %10.0f ", value );     }  
	    else                     		 { fprintf( pFile,  " & %10.2f $\\pm$ %3.2f ", value , error);	}
	  }
	  fprintf( pFile, "\\\\ \n") ;
      }
      fprintf( pFile, "\\hline \\end{tabular} \n " ) ;
    }
  }
  
}




#ifndef __CINT__
int main () { interCutFlow(); return 0; }
#endif
