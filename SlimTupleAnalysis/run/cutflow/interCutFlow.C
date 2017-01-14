//-*-  this is C++ -*-
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
#include "TPRegexp.h"
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG 1

#define Blind 0

map <TString, int> FromBinLabelToBin ; 
enum sampleType {DATA, BG, SIG, NONE};

TString resolveName="Resolve";
TString fatName="Fat";

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

TString niceCutName(TString cutName){
  TString niceName="";
  
  int jetMode=-1;

  if(cutName.EndsWith(resolveName)){
    TPRegexp re1("(.*)"+resolveName+"$");
    re1.Substitute(cutName,"$1");
    jetMode=0;
  }
  else if(cutName.EndsWith(fatName)){
    TPRegexp re1("(.*)"+fatName+"$");
    re1.Substitute(cutName,"$1");
    jetMode=1;
  }
  

  if(cutName=="PRESELECT"){
    niceName="Preselection";
  }
  else if(cutName=="ONELEPTON"){
    niceName="$N(\\ell)=1$";
  }
  else if(cutName=="LEPTONPT"){
    niceName="$\\pT(\\ell)>30\\gev$";
  }
  else if(cutName=="MET"){
    niceName="$\\met>30\\gev$";
  }
  else if(cutName=="MT"){
    niceName="$\\mt>40\\gev$";
  }
  else if(cutName=="NOTBTAG"){
    niceName="b-tag veto";
  }
  else if(cutName=="MJJ"){
    niceName="$m(\\Vhad)$ window";
  }
  else if(cutName=="JETSELECT"){
    if(jetMode==0){
      niceName="Res. jet select.";
    }
    else if(jetMode==1){
      niceName="Merged jet select.";
    }
  }
  else if(cutName=="PtWlep"){
    niceName="$\\pTWlep$";
  }
  //else if(cutName=="VVPtBal"){
  //  niceName="$\\VVpTbal$";
  // }
  else if(cutName=="CosThWjj"){
    niceName="$\\cosThWjj$";
  }
  //else if(cutName=="OLRemoval"){
  //  if(jetMode==0){
  //    niceName="!(merged)";
  //  }
  //  else if(jetMode==1){
  //    niceName="!(resolved)";
  //  }
  //}
  //&&&& added 3/7/16
  else if(cutName=="mVhadWindow"){
    niceName="$m(\\Vhad)$ window";
  }
  else if(cutName=="LooseMjjTag"){
    niceName="loose $\\mjjTag$";
  }
  else if(cutName=="FinalMjjTag"){
    niceName="tight $\\mjjTag$";
  }
  //else if(cutName=="PtWlep"){
  //niceName="$\\pTWlep$";
  //}
  else if(cutName=="VVPtBal"){
    niceName="$\\pT$ balance";
  }
  //else if(cutName=="CosThWjj"){
  //  niceName="$\\cosThWjj$";
  // }
  //  else if(cutName=="JETSELECT"){
  //  if(jetMode==0){
  //    niceName="Res. jet select.";
  //  }
  //  else if(jetMode==1){
  //    niceName="Merged jet select.";
  //  }
  //}
  else if(cutName=="OLRemoval"){
    if(jetMode==0){
      niceName="!(optim. SR merged)";
    }
    else if(jetMode==1){
      niceName="!(optim. SR resolved)";
    }
  }
  else if(cutName=="LooseVBSOLRemoval"){
    if(jetMode==0){
      niceName="!(loose VBS merged) \\textbf{$\\star$}";
    }
    else if(jetMode==1){
      niceName="!(loose VBS res.) \\textbf{$\\star$}";
    }
  }
  
  else{
    niceName=cutName;
  }

  return niceName;
  
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
  if ( histname.Contains("Wjets_")) {  // HARD coded. Scale W+jetsQCD with 0.82
    //cout<<"HELLO"<<endl;
    h->Scale(0.82);  //&&&&+
  }
  if ( !h->GetSumw2N() )h->Sumw2();
  return h;
}

void GetHistSample(std::vector<Sample>* vs , TFile *finput)   ///build hBG and hSig from cutflow histograms in the root file so that sum of all bkg or signal can be printed on the cutflow table.
{
  
  TH1 *hBG=NULL, *hSig=NULL;
  TH1 *hWjets=NULL; //&&&&+ sum of QCD and EWK W+jets
  for (unsigned int i=0; i<(*vs).size(); i++) {
    Sample *sam= &((*vs)[i]);

    vector<string> lst;
    splitString(sam->internalName, lst, ";"); ///for example: "H_ggF_300;H_VBF_300"
    cout << "size " <<  lst.size()  << " " << sam->internalName << endl;

    TH1 *h; 
    for (int i=0; i<lst.size(); i++) { 

      TString histname = Form("CutFlow/%s_CutFlow", (lst[i]).c_str()); //CutFlow directory inside the root file
      //cout <<"histname ="<< histname << endl;
      TString cloneName = "Clone_"+lst[i] ; 
      TH1 *thisHist= getOneHist( finput, histname, cloneName);
      if (!thisHist) { cout << " GetHistSample::Error : can not find histogram for " << histname << endl; exit(1); }
      if (i==0)  h = thisHist ; 
      else       h->Add(thisHist);
    }
    

//    TString histname = Form("CutFlow/%s_CutFlow", (sam->internalName).c_str());
//    cout << histname << endl;
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
    // /* // &&&&+
    if (sam->type==BG && (sam->name=="W+jets QCD" || sam->name =="W+jets EWK")) {
      if (!hWjets) hWjets = (TH1*)h->Clone("hWjets"); 
      else      hWjets -> Add(h); ///Adding W+jets QCD and EWK together
    }
    // */  ////  
    lst.clear();
   }

  //(*vs).push_back(Sample("Signal", NONE, "", hSig));
  (*vs).push_back(Sample("W+jets", NONE, "", hWjets)); //&&&&+
  (*vs).push_back(Sample("BG",     NONE, "", hBG )); ///&&&& Sum of all bkg
  

}

void interCutFlow(){

  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf3.lv4/hwwlvqq.Nominal.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1.lv7_looseBadLep4_bchbug_NEWcutflow.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_looseBadLep4.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_all97.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.41.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_all81.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_all97.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv4.4_smw.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7_NEWcutflow.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv7.WjetsAlp_NEWcutflow.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_noSeparateWjetsEWK.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_WjetsBugFixed.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_separateWjetsEWK.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4.4_smw/hwwlvqq.Nominal.small.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.1_sig.lv7.root"); // All 90 signal samples with optimized cuts.

  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_noSeparateWjetsEWK_cutflow.root"); //v9 cutflow, boson centrality> 1.0

  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.185722.TST.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_cutflow.root"); //v10 cutflow  boson centrality> 0.9
  TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_New_all97.root"); //wjets separate
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst_lumi20.2/hwwlvqq.cutflow.root"); //boson centrality> 0.9, lumi 20.2
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv8_smw_wp20_NewFatJetSyst_lumi20.2/hwwlvqq.all97.root"); //wjets separate
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/hwwlvqq.Nominal.caf4.2.lv8_smw_wp20_NEW_jetpt40_cutflow.root");
  //TFile *fInput = new TFile("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/HWWLVQQ.caf4.2.lv4_fatwindow40_140_mjjTag0_fatjetmass/hwwlvqq.FatJMRUp2.root");
  
  
  map<std::string, TH1*> FromNameToTH1 ; 
  
  ///HARD CODING!!!
  std::vector<Sample> vs; ///name, type,internalName, TH1* hist
  // /* &&&&
  vs.push_back(Sample("Data"          , DATA , "888888")); ///the internal name used to be "888888"
  //vs.push_back(Sample("W+jets"         , BG   , "Wjets"));
  vs.push_back(Sample("W+jets EWK"         , BG   , "WjetsEWKSherpa"));
  vs.push_back(Sample("W+jets QCD"         , BG   , "Wjets"));
  vs.push_back(Sample("Ttbar"           , BG   , "Ttbar"));
  vs.push_back(Sample("SingleTop"           , BG   , "SingleTop"));
  vs.push_back(Sample("Diboson" , BG   , "WZZZWg"));
  vs.push_back(Sample("Z+jets" , BG   , "Zjets"));
  //   */
  
  //vs.push_back(Sample("Data"          , BG , "888888")); /// when only using data

  //  /*
  //vs.push_back(Sample("WWSM"         , BG   , "WWSM"));
  //vs.push_back(Sample("WWaTGC"         , BG   , "WWaTGC"));
  //vs.push_back(Sample("WpZSM"         , BG   , "WpZSM"));
  //vs.push_back(Sample("WpZaTGC"         , BG   , "WpZaTGC"));
  //vs.push_back(Sample("WmZSM"         , BG   , "WmZSM"));
  //vs.push_back(Sample("WmZaTGC"         , BG   , "WmZaTGC"));
  //  */
  
  //vs.push_back(Sample("WW"         , BG   , "WW"));
  //vs.push_back(Sample("WZ"           , BG   , "WZ"));
  // vs.push_back(Sample("ZZ"           , BG   , "ZZ"));
  // vs.push_back(Sample("Wgamma" , BG   , "Wgamma"));
  // vs.push_back(Sample("Zgamma" , BG   , "Zgamma"));

  
  
  // vs.push_back(Sample("WjetsInc"         , BG   , "WjetsInc"));
  // vs.push_back(Sample("Wjets40"           , BG   , "Wjets_40"));
  // vs.push_back(Sample("Wjets70"           , BG   , "Wjets_70"));
  // vs.push_back(Sample("Wjets140" , BG   , "Wjets_140"));
  // vs.push_back(Sample("Wjets280" , BG   , "Wjets_280"));
  // vs.push_back(Sample("Wjets500" , BG   , "Wjets_500"));
  
  //&&&&
  //   /*
  vs.push_back(Sample("WV(0,0)" ,SIG   , "VBS_WV_0_0"));
  //vs.push_back(Sample("WV0,03" , SIG   , "VBS_WV_0_03"));
  vs.push_back(Sample("WV(0.1,0)" , SIG   , "VBS_WV_01_0"));
  vs.push_back(Sample("ZV(0,0)" , SIG   , "VBS_ZV_0_0"));
  //vs.push_back(Sample("ZV0,03" , SIG   , "VBS_ZV_0_03"));
  vs.push_back(Sample("ZV(0.1,0)" , SIG   , "VBS_ZV_01_0"));
  //  */

  //vs.push_back(Sample("WV0.1,0" ,BG   , "VBS_WV_01_0"));
  //vs.push_back(Sample("WjetsAlp" ,BG   , "WjetsAlp"));
 
	     

  // Get histograms pointers from file
  GetHistSample(&vs, fInput);

  for (unsigned int i=0; i<vs.size(); i++) FromNameToTH1[vs[i].name] = vs[i].hist; ///maps sample names to histograms
  
  // Get table titles
  vector<string> sampleTable; 
  //sampleTable.push_back("Signal"); 

  for (unsigned int i=0; i<vs.size(); i++) {
    if (vs[i].type==SIG) sampleTable.push_back(vs[i].name) ;
  }
  for (unsigned int i=0; i<vs.size(); i++) {
    //if (vs[i].type==BG ) { 
    if (vs[i].type==BG && !( vs[i].name =="W+jets EWK" || vs[i].name =="W+jets QCD") ) { //&&&&+ no separate columns for WjetsEWK and WjetsQCD
      sampleTable.push_back(vs[i].name) ;
    }
  }
  /////
  sampleTable.push_back("W+jets"); // &&&&+ sum of WjetsEWK and WjetsQCD
  sampleTable.push_back("BG"); //&&&& Sum of all bkg, just commenting out this one line should make sure you don't see a row for sum of bkg.

#if Blind
#else
  sampleTable.push_back("Data"); //&&&& if no data, comment out this line
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
      
      TString resOrFat[2] = {resolveName,fatName};
      for (unsigned  int jResOrFat=0 ; jResOrFat<2 ; jResOrFat++){
	
	 FILE *  pFile = fopen(Form("tables/cutflow_summary_%s_%s.tex", channelName.c_str(), resOrFat[jResOrFat].Data()) , "w");
	
	string col = "|l|" ; 
	for ( unsigned int isample=0; isample<sampleTable.size(); isample++) col += "r|" ;
	fprintf( pFile, "\\begin{tabular}{%s} \\hline \n", col.c_str());
	
	fprintf( pFile, " %10s ", "Selection");
	for ( unsigned int isample=0; isample<sampleTable.size(); isample++) 	fprintf( pFile,  " & %10s ", sampleTable[isample].c_str()  );
	fprintf( pFile, "\\\\ \\hline \n") ;
	
	for (unsigned int icut=0; icut<cutArr.size() ; icut++) {
	  TString oriCutname, outputCutName ;
	  oriCutname =  channelName + "_" +cutArr[icut];

	  TString cutString = cutArr[icut].c_str();
	  //cout<<icut<<":"<<cutArr[icut].c_str()<<endl;
	  
	  //cut is either for the appropriate selection (resolve or fat) or is a pre-selection common to both
	  if(cutString.EndsWith(resOrFat[jResOrFat]) ||  ( !cutString.EndsWith(resOrFat[0]) && !cutString.EndsWith(resOrFat[1]) )   ){
	    //cout<<cutString<<endl;
	    if (cutString =="STARTPOINT")continue; //&&&& comment out STARTPOINT row
	    if (cutString.Contains("PtWlep")){
	      fprintf (pFile, "\\hline  \\multicolumn{12}{|l|}{Optimized SR:} \\\\ \n\\hline \n"); //&&&& HARD CODED column size 12 for full table. Need to readjust for smaller or bigger number of samples.
	      
	    }
	    if(cutString.EndsWith(resolveName) && cutString.Contains("VVPtBal")){ continue;} //no cut on VVptBalance for resolved &&&&
	    if(cutString.EndsWith(fatName) && cutString.Contains("CosThWjj")){ continue;}  //no cut on cosThetaStar for fat  &&&&
	    outputCutName = niceCutName(cutString);
	    outputCutName = outputCutName.ReplaceAll("_", "\\_");
	    
	    fprintf( pFile, " %10s ",  outputCutName.Data()  );


	    
	    for ( unsigned int isample=0; isample<sampleTable.size(); isample++)   {
	      float value = getOneCutValue( FromNameToTH1[ sampleTable[isample] ] ,  oriCutname ) ; 
	      float error = getOneCutError( FromNameToTH1[ sampleTable[isample] ] ,  oriCutname ) ;
	      
	      	      
	      if ( sampleTable[isample] == "Data" ){ fprintf( pFile,  " & %10.0f ", value );     }  
	      //else                     		 { fprintf( pFile,  " & %10.2f $\\pm$ %3.2f ", value , error);	}//if you don't want error &&&&
	      else {
		//fprintf( pFile,  " & %10.2f $\\pm$ %3.2f  ", value, error );
		// if (icut<15) fprintf( pFile,  " & %10.0f ", value );  //remove unnecessary precision. 
		// //else fprintf( pFile,  " & %10.2f ", value ); //only value, no uncertainty
		// else fprintf( pFile,  " & %10.2f $\\pm$ %3.2f  ", value, error );
		if (icut<13)fprintf( pFile,  " & \\numRP{ %f }{0} $\\pm$  \\numRP{%f }{0}  ", value, error );
		else fprintf( pFile,  " & \\numRP{ %f }{1} $\\pm$  \\numRP{%f }{1}  ", value, error ); //numRF is a latex macro. requires siunitx package (11/6/15)
	      }
	    }
	    fprintf( pFile, "\\\\ \n") ;
	    
	    
	  }//end if(resOrFat)
	  
	} //end loop over cuts
	
	fprintf( pFile, "\\hline \\end{tabular} \n " ) ;
	
      }//end loop over (Resolved/Fat)
      
    }
  }
  
}




#ifndef __CINT__
int main () { interCutFlow(); return 0; }
#endif
