// ROOT
#include <TFile.h>
#include <TApplication.h> 
#include <TRint.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TLorentzVector.h> 
#include <TRandom3.h>
#include <TKey.h>
#include <TStopwatch.h>

// C++
#include <fstream>
#include <sstream> 
#include <iostream>
#include <iomanip>
#include <vector>
#include <sys/stat.h>
#include <cmath>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <map>
#include <stdio.h>
#include <set>

// Local
#include "foo.hh"
#include "CutFlowTool.h"
#include "SampleMetaData.h"
#include "crossSectionMetaData.h"
#include "SampleDef.h"
#include "EventRecorder.h"
#include "HistRun.h"
#include "HistFiller.h"
#include "MiniObjSelector.h"


#define DEBUG  0
#define PrintOneRunCutFlow 0


using namespace std;
//using namespace constants;  //defined in SelectionTools.h.  Store constants (like cut values) here, that need to be used in several files, like minihbb.cxx and MiniObjSelector.cxx

// Get the individual filenames from a .txt file 
vector<TString> fileNames;


bool fexists( const char *filename ) {
  struct stat buffer ;///uses inbuilt  <sys/stat.h>
  return stat( filename, &buffer )==0;
}

void getFileNames(const char *file) { 
  std::ifstream is(file);
  TString s("");
  while(is>>s) fileNames.push_back(s);
  cout << "Read "<< fileNames.size() << " files.\n\n";
}



int main(int argc, char* argv[]) {


  //need to have at least three arguments
  if ( argc < 3 ) {
    cout << "usage: " << argv[0] << " <somefile.txt>  <sampleName> " << endl;
    return 0;
  }
  
  const char* theinputfile  = argv[1]; ///example: listntuple.txt
  const char* thesamplename = argv[2]; ///example: hwwlvqq
 
  cout << "The input file list is taken from: " << theinputfile << endl;
  TString name(theinputfile);
  cout << "The sample name is: " << thesamplename << endl;
  TString sample( thesamplename );

  bool CutOnMET    = (argc>3) ? atoi(argv[3]) : 1;
  bool doBadLepton = (argc>4) ? atoi(argv[4]) : 0;
  bool doTwoGoodLeptons = (argc>5) ? atoi(argv[5]) : 0;

  const char* thesystname = (argc>6) ? argv[6] : "Nominal";

  //  bool writeAscii=false; //this has been moved to SelectionTools.h!
  // bool doReducedPlots=true; //this has been moved to SelectionTools.h!
  
  int bchMode= 0;  //0:  medium cut. 1: medium syst-up cut.  2:  medium syst-down cut.  3:  tight cut (I don't recommend this!) 

  cout << " CutOnMET " << CutOnMET << ", doBadLepton " << doBadLepton << endl;
  cout<< "doTwoGoodLeptons " <<doTwoGoodLeptons <<endl;
  
  //---------------------------------------------
  if (!fexists(name.Data())) { 
    cout << name << " not found.\n";
    exit(0);
  }
  
  getFileNames(name.Data());
    

  TStopwatch timer;
  timer.Start();

  
  // Trying TChain...
  TChain *mychain = new TChain("HWWlvqq_mini");
  TList *FileList = new TList();
  cout<<"filenames in "<< theinputfile <<" are:\n";
  for ( unsigned int i_nFname=0; i_nFname<fileNames.size(); i_nFname++){
    if(! (fileNames[i_nFname].Contains('#')) ){ //comment out slimntuples by putting a '#' in front.
      mychain  -> Add( fileNames[i_nFname] ); ///adding all the slim ntuples in a chain
      cout<<fileNames[i_nFname]<<endl;
      FileList -> Add( TFile::Open(fileNames[i_nFname] ));
    }
  }
  


  foo  *h1 = new foo(mychain);

  //if (DEBUG) cout << "Have defined a foo" << endl ;
  
  vector<int> runNames ; 
  map <int, float> runWeight, sumWeightPerRun ;


  float Lumi = 20280.2; //from lumi calc. previous values: 20280.3; // 20693.7 ; // [pb-1]

  cout << " \n>>>Using luminosity in data  " << Lumi << " pb-1"  << endl;
  cout << endl;

  map <int , std::string> DatasetTypeMap ;
  SampleMetaData::GetDatasetType( DatasetTypeMap );//get DSType map from SampleMetaData.h

  bool firstSample = 1 ; 

  FILE *RunLog = fopen( "JobsRunLog.txt" , "w");

  TString path = "./" ; 

  TFile *nextsource = (TFile*)FileList->First(); ///FileList is a TList of all slim ntuple files. First() and After() are TList member functions. nextsource points to the first file in the TList right now.
  while (nextsource){ ///as long as nextsource is not null
    
    TIter next(nextsource->GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {

      TObject *obj = (TH1*)key->ReadObj();
      
      if ( !obj->IsA()->InheritsFrom( TH1::Class() )  ) continue ;
      TH1 *hcut = (TH1*)obj; ///e.g. thisCount_147774; this is present only for MC, not data
      string histname = hcut->GetName();
      if ( !TString(histname).BeginsWith("thisCount_") ) continue;
      int runNumber = atoi((histname.substr(histname.find("_")+1, (histname.size()-histname.find("_")) ) ).c_str()); ///this runNumber is actually the datasetId
      
      if( runNumber > 300000 ) continue ;
      string typeMapString = DatasetTypeMap[runNumber] ;
      if(typeMapString==""){
	cout<<"ERROR:  run  number "<<runNumber<<" appears in input list, but is not included in SampleMetaData.h!!!"<<endl;
	exit(0);	
      }


      cout << histname <<  " runNumber " << runNumber << " raw sum weight " << hcut->GetBinContent(7) <<  endl;
      
      if (firstSample) { 
	for( int i=1; i<=25; i++){ TString binlable = hcut->GetXaxis()->GetBinLabel(i) ; printf("[%2d] bin label : %s \n", i,  binlable.Data()  );} 	
	firstSample = 0 ;      }

      float sumweights  =  hcut->GetBinContent(7) ;
      if (fabs(sumweights) < 1E-8 ) continue ;

      map<int,float>::iterator it = sumWeightPerRun.find(runNumber);
      if(it != sumWeightPerRun.end()){ sumWeightPerRun[runNumber]  += sumweights; //cout << " find dupli. " << sumWeightPerRun[runNumber] << endl;
      }
      else                           { sumWeightPerRun[runNumber]  = sumweights; runNames.push_back(runNumber); }
    }
    nextsource = (TFile*)FileList->After( nextsource ) ;
  }
  

  
  for (std::map<int,float>::iterator it=sumWeightPerRun.begin(); it!=sumWeightPerRun.end(); ++it){
    std::cout << it->first << "  => " << it->second << '\n';
    int runNumber = it->first ; 
    float sumweights = it->second ; 
    float totweight = Lumi*getXsection(runNumber)/sumweights ;///MC is to be scaled by this number (so that it is normalized to data luminosity)
    runWeight[runNumber] = totweight ;
    fprintf(  RunLog, "%10i sum weights %20.1f totweight %5.10f \n", runNumber, sumweights, totweight ) ;

    cout << "run " << runNumber << ",  xs:  " << getXsection(runNumber) << " pb,   Eff lumi = " <<sumweights/getXsection(runNumber)/1000.<<" fb-1"<< endl;
    if( getXsection(runNumber) < 0.0000000001){
      cout<<"ERROR:  run "<<runNumber<<" has a cross-section of "<<getXsection(runNumber) << " pb!! Please check."<<endl;
      exit(0);
    }

  }
  fclose(RunLog) ;

  runNames.push_back(888888);

  cout << "Number of runs (+1 for data): " << runNames.size() << endl;

  TFile   *foutput = TFile::Open(sample+".root","recreate"); ///foutput is hwwlvqq.root

  
  CutFlowTool ct ;
  
  //const int nflavor = 1;  std::string flavorArr[nflavor] = { "em"} ;
  //const int nflavor = 2;  std::string flavorArr[nflavor] = { "em", "ep"} ;
  const int nflavor = 4;  std::string flavorArr[nflavor] = { "em", "ep", "mm", "mp"} ;
  
  
  const int nmode   = 1;  std::string modeArr[nmode]   = { "WBF"} ;
  //const int nmode   = 2;  std::string modeArr[nmode]   = { "ggF", "WBF"} ;
  
  const int nCuts   = 20;  
  std::string cuts[nCuts]  = { 
                               "PRESELECT",
			       //"TWOJETS",
			       "ONELEPTON",
			       "LEPTONPT", 
			       "JETSELECTResolve",
			       "JETSELECTFat",
			       "METResolve",
			       "METFat",
			       //"MTResolve",
			       //"MTFat",
			       "PtWlepResolve",
                               "PtWlepFat",
			       "VVPtBalResolve",
                               "VVPtBalFat",
			       "CentralityResolve",
			       "CentralityFat",      
			       "CosThWjjResolve",
			       "CosThWjjFat",
			       "NOTBTAGResolve",
			       "NOTBTAGFat",
			       "MJJResolve",
			       "MJJFat",
			       "OLRemovalFat"
  } ;
  
  for ( int iflavor=0 ; iflavor<nflavor ; iflavor++){
    for ( int imode=0; imode<nmode; imode++ ){
      for (int icut=0; icut<nCuts ; icut++) { 
	std::string tname = flavorArr[iflavor] + "_" + modeArr[imode] + "_" + cuts[icut];
	ct.registCut( tname, tname );       
	if (DEBUG) cout << tname << endl;
      }
    }
  }
  
  TString option = "None";
  MiniObjSelector objselector( h1, &ct, option) ; 

    /*
      
    //use this one for RGS
    const int nDSType = 32 ;
  std::string DScategory[nDSType] = 
    { "Data",
      "Ttbar",
      "SingleTop", 
      "WZZZWg", 
      "Zjets" , "Wjets",
      //  "Zjets40" , "Wjets40",
      //  "Zjets70" , "Wjets70",
      // "Zjets140" , "Wjets140",
      // "Zjets280" , "Wjets280",
      // "Zjets500" , "Wjets500",
      "VBS_WV_0_0","VBS_WV_005_0", "VBS_ZV_0_0", "VBS_ZV_005_0",  "VBS_WV_01_0", "VBS_ZV_01_0","VBS_WV_03_0", "VBS_ZV_03_0",
      "VBS_WV_0_005", "VBS_ZV_0_005","VBS_WV_0_01", "VBS_ZV_0_01","VBS_WV_0_02", "VBS_ZV_0_02",
      "VBS_WV_m005_0", "VBS_ZV_m005_0",  "VBS_WV_m01_0", "VBS_ZV_m01_0","VBS_WV_m03_0", "VBS_ZV_m03_0",
      "VBS_WV_0_m005", "VBS_ZV_0_m005","VBS_WV_0_m01", "VBS_ZV_0_m01","VBS_WV_0_m02", "VBS_ZV_0_m02"
      // "VBS_WV_01_0","VBS_WV_m01_0","VBS_WV_005_0","VBS_WV_m005_0","VBS_WV_m03_0",
      
    };
    
    */
  


  /*
  const int nDSType = 9;
  std::string DScategory[nDSType] =
    { "Data",
      "Wjets","Zjets",  //the nominal truth Sherpa samples have same DSID as reco samples, so will end up in "Wjets"
      "TruthWjetsckkw15","TruthWjetsckkw30","TruthWjetsfac025","TruthWjetsfac4",
      "TruthWjetsrenorm025","TruthWjetsrenorm4"
    };
  
  */

  /*
  const int nDSType = 10 ;
  std::string DScategory[nDSType] =
    { "Data",
      "Wjets","Zjets",
      "TruthPowhegWjets_Nominal","TruthPowhegWjets_MuFdown","TruthPowhegWjets_MuFup","TruthPowhegWjets_MuRdown",
      "TruthPowhegWjets_MuRup","TruthPowhegWjets_MuRFdown","TruthPowhegWjets_MuRFup"
    };          
  */

  // /*
  const int nDSType = 1 ;
  std::string DScategory[nDSType] =
    { //"Data",
      "Ttbar"
      //"WjetsEWKSherpa",
      //"TruthPowhegWjets_Nominal"
      //"Ttbar", "SingleTop", "WZZZWg", "Zjets" , "Wjets",
      //"VBS_WV_0_0"
      //"WW","WZ","WjetsPow"
      //"WWSM","WpZSM","WmZSM","WWaTGC","WpZaTGC","WmZaTGC"
    };
  //  */


  
   /*
  const int nDSType = 8 ;                    
  std::string DScategory[nDSType] =	
    {
      "Data", "Ttbar", "SingleTop", "WZZZWg", "Zjets" , "Wjets",
      "VBS_WV_0_0", "VBS_WV_0_03"

      //"Ttbar", "SingleTop", "WZZZWg", "Zjets" , "Wjets",
      //"VBS_WV_0_0"

                  
    };
    */

  /*
  const int nDSType =6 ;
  std::string DScategory[nDSType] =
    {
      "VBS_WV_0_0","VBS_WV_01_0","VBS_WV_03_0",
      "VBS_ZV_0_0","VBS_ZV_01_0","VBS_ZV_03_0"
    };
  */

  /*
  //Whizard scale variation systematics
  const int nDSType =18 ;
  std::string DScategory[nDSType] =
    {
      "VBS_WV_01_0","VBS_WV_01_0_s_20_20","VBS_WV_01_0_s_20_10","VBS_WV_01_0_s_20_05",
      "VBS_WV_01_0_s_10_20","VBS_WV_01_0_s_10_05","VBS_WV_01_0_s_05_20","VBS_WV_01_0_s_05_10","VBS_WV_01_0_s_05_05",
      "VBS_ZV_01_0","VBS_ZV_01_0_s_20_20","VBS_ZV_01_0_s_20_10","VBS_ZV_01_0_s_20_05",
      "VBS_ZV_01_0_s_10_20","VBS_ZV_01_0_s_10_05","VBS_ZV_01_0_s_05_20","VBS_ZV_01_0_s_05_10","VBS_ZV_01_0_s_05_05"
    };
*/  
  
   /*
  const int nDSType = 90 ; //74
  
  std::string DScategory[nDSType] =
    
    {                                                                                                                          
      "VBS_WV_0_0","VBS_WV_0_01","VBS_WV_0_02","VBS_WV_0_m01","VBS_WV_0_m02","VBS_WV_01_0","VBS_WV_01_01","VBS_WV_01_m02","VBS_WV_01_m04","VBS_WV_02_m03","VBS_WV_03_m02","VBS_WV_03_m06","VBS_WV_m01_0","VBS_WV_m01_02","VBS_WV_m01_04","VBS_WV_m01_m01","VBS_WV_m02_03","VBS_WV_m03_02","VBS_WV_m03_06","VBS_WV_01_m01","VBS_WV_m01_01","VBS_WV_005_005","VBS_WV_005_0","VBS_WV_005_m005","VBS_WV_0_005","VBS_WV_0_m005","VBS_WV_m005_005","VBS_WV_m005_0","VBS_WV_m005_m005","VBS_WV_03_03","VBS_WV_03_0","VBS_WV_03_m03","VBS_WV_0_03","VBS_WV_0_m03","VBS_WV_m03_03","VBS_WV_m03_0","VBS_WV_m03_m03","VBS_ZV_0_0","VBS_ZV_0_01","VBS_ZV_0_02","VBS_ZV_0_m01","VBS_ZV_0_m02","VBS_ZV_01_0","VBS_ZV_01_01","VBS_ZV_01_m02","VBS_ZV_01_m04","VBS_ZV_02_m03","VBS_ZV_03_m02","VBS_ZV_03_m06","VBS_ZV_m01_0","VBS_ZV_m01_02","VBS_ZV_m01_04","VBS_ZV_m01_m01","VBS_ZV_m02_03","VBS_ZV_m03_02","VBS_ZV_m03_06","VBS_ZV_01_m01","VBS_ZV_m01_01","VBS_ZV_005_005","VBS_ZV_005_0","VBS_ZV_005_m005","VBS_ZV_0_005","VBS_ZV_0_m005","VBS_ZV_m005_005","VBS_ZV_m005_0","VBS_ZV_m005_m005","VBS_ZV_03_03","VBS_ZV_03_0","VBS_ZV_03_m03","VBS_ZV_0_03","VBS_ZV_0_m03","VBS_ZV_m03_03","VBS_ZV_m03_0","VBS_ZV_m03_m03",
      "VBS_WV_003_003","VBS_WV_003_0","VBS_WV_003_m003","VBS_WV_0_003","VBS_WV_0_m003","VBS_WV_m003_003","VBS_WV_m003_0","VBS_WV_m003_m003","VBS_ZV_003_003","VBS_ZV_003_0","VBS_ZV_003_m003","VBS_ZV_0_003","VBS_ZV_0_m003","VBS_ZV_m003_003","VBS_ZV_m003_0","VBS_ZV_m003_m003"
      
    };
   */

    /*
  //use this one for TGClim
  const int nDSType = 96; // 96 //80
  std::string DScategory[nDSType] =
    {
      "Data","Ttbar","SingleTop","WZZZWg","Zjets","Wjets",
      "VBS_WV_0_0","VBS_WV_0_01","VBS_WV_0_02","VBS_WV_0_m01","VBS_WV_0_m02","VBS_WV_01_0","VBS_WV_01_01","VBS_WV_01_m02","VBS_WV_01_m04","VBS_WV_02_m03","VBS_WV_03_m02","VBS_WV_03_m06","VBS_WV_m01_0","VBS_WV_m01_02","VBS_WV_m01_04","VBS_WV_m01_m01","VBS_WV_m02_03","VBS_WV_m03_02","VBS_WV_m03_06","VBS_WV_01_m01","VBS_WV_m01_01","VBS_WV_005_005","VBS_WV_005_0","VBS_WV_005_m005","VBS_WV_0_005","VBS_WV_0_m005","VBS_WV_m005_005","VBS_WV_m005_0","VBS_WV_m005_m005","VBS_WV_03_03","VBS_WV_03_0","VBS_WV_03_m03","VBS_WV_0_03","VBS_WV_0_m03","VBS_WV_m03_03","VBS_WV_m03_0","VBS_WV_m03_m03","VBS_ZV_0_0","VBS_ZV_0_01","VBS_ZV_0_02","VBS_ZV_0_m01","VBS_ZV_0_m02","VBS_ZV_01_0","VBS_ZV_01_01","VBS_ZV_01_m02","VBS_ZV_01_m04","VBS_ZV_02_m03","VBS_ZV_03_m02","VBS_ZV_03_m06","VBS_ZV_m01_0","VBS_ZV_m01_02","VBS_ZV_m01_04","VBS_ZV_m01_m01","VBS_ZV_m02_03","VBS_ZV_m03_02","VBS_ZV_m03_06","VBS_ZV_01_m01","VBS_ZV_m01_01","VBS_ZV_005_005","VBS_ZV_005_0","VBS_ZV_005_m005","VBS_ZV_0_005","VBS_ZV_0_m005","VBS_ZV_m005_005","VBS_ZV_m005_0","VBS_ZV_m005_m005","VBS_ZV_03_03","VBS_ZV_03_0","VBS_ZV_03_m03","VBS_ZV_0_03","VBS_ZV_0_m03","VBS_ZV_m03_03","VBS_ZV_m03_0","VBS_ZV_m03_m03",
      "VBS_WV_003_003","VBS_WV_003_0","VBS_WV_003_m003","VBS_WV_0_003","VBS_WV_0_m003","VBS_WV_m003_003","VBS_WV_m003_0","VBS_WV_m003_m003","VBS_ZV_003_003","VBS_ZV_003_0","VBS_ZV_003_m003","VBS_ZV_0_003","VBS_ZV_0_m003","VBS_ZV_m003_003","VBS_ZV_m003_0","VBS_ZV_m003_m003"
    };
   */
  
   /*
   //For systematics run smaller number of signal samples, you don't need DATA either.
  const int nDSType = 27 ;
  std::string DScategory[nDSType] = 
    {
      
      //"Data", "Ttbar", "SingleTop", "WZZZWg", "Zjets" , "Wjets",
      "Ttbar", "SingleTop", "WZZZWg", "Zjets" , "Wjets",

       "VBS_WV_0_0",   "VBS_WV_0_01",   "VBS_WV_0_m01",      
       "VBS_WV_01_0",  
       "VBS_WV_m01_0",   
       "VBS_WV_03_03", 
       "VBS_WV_03_0",  "VBS_WV_0_03",   "VBS_WV_0_m03",  
       "VBS_WV_m03_0", "VBS_WV_m03_m03",
     
       "VBS_ZV_0_0",   "VBS_ZV_0_01",   "VBS_ZV_0_m01",  
       "VBS_ZV_01_0", 
       "VBS_ZV_m01_0", 
       "VBS_ZV_03_03",
       "VBS_ZV_03_0",  "VBS_ZV_0_03",   "VBS_ZV_0_m03", 
       "VBS_ZV_m03_0", "VBS_ZV_m03_m03"
      
    };
   
   */
  
   /*
  //New aQGC points
  const int nDSType = 16 ;
  std::string DScategory[nDSType] = 
    {
      "VBS_WV_003_003","VBS_WV_003_0","VBS_WV_003_m003","VBS_WV_0_003","VBS_WV_0_m003","VBS_WV_m003_003","VBS_WV_m003_0","VBS_WV_m003_m003",
      "VBS_ZV_003_003","VBS_ZV_003_0","VBS_ZV_003_m003","VBS_ZV_0_003","VBS_ZV_0_m003","VBS_ZV_m003_003","VBS_ZV_m003_0","VBS_ZV_m003_m003"
    };
   */
  
  HistFiller *histfiller = new HistFiller( DatasetTypeMap, 
					   flavorArr, nflavor , 
					   DScategory,    nDSType ,
					   foutput,thesystname  );
  
  
  histfiller->ReducedPlots(constants::doReducedPlots);

  ///Getting the reweighting factor from plots_nosystematics/output/reweightFactor.txt
  //string inFileName = "/export/home/azaman/haifeng2/reader/run/plots_nosystematics/output/reweightFactor.txt";
  //string inFileName = "/export/home/azaman/haifeng2/reader/run/plots_nosystematics/output/reweightFactor_emOnly_shapeRW.txt";
  //string inFileName = "/export/home/azaman/haifeng2/reader/run/plots_nosystematics/output/reweightFactor_mergedSample_shapeRW.txt"; 
  string inFileName = "/export/home/azaman/haifeng4/SlimTupleAnalysis/run/plots_nosystematics/output/reweightFactor.txt";
  
  ifstream inFile(inFileName.c_str());
  
  int _index;
  float _rw_factor ;
  float reweightFactor[80]; ///not flexible
  
  if ( inFile.is_open() ) {
    
    string line ;
    getline( inFile, line );
    
    while( inFile.good() ){
      if (line.find("//")!=line.npos || line.size()==0) { getline(inFile,line); continue; }
      
      istringstream info_line(line); ///line has two float numbers, first one is bin number and second one is rw_factor. An example of a line: 1 1.076741 
      info_line >> _index >>  _rw_factor;  
      reweightFactor[_index] = _rw_factor; 
      //cout<<_bin_number<<" "<<_rw_factor<<endl;
      getline (inFile,line);
    }
  }
  
  inFile.close();
 
  
  //////////////////////////////////////Reweighting W+jets
  
  string inFileName2 = "/export/home/azaman/haifeng2/reader/run/plots_nosystematics/output/reweightFactorWjets.txt";
  //string inFileName2 = "/export/home/azaman/haifeng2/reader/run/plots_nosystematics/output/reweightFactorWjets_mergedSample_shapeRW.txt"; 
  
  ifstream inFile2(inFileName2.c_str());
  
  int _index2;
  float _rw_factor2 ;
  float reweightFactor2[80]; ///not flexible
  
  if ( inFile2.is_open() ) {
    
    string line2 ;
    getline( inFile2, line2 );
    
    while( inFile2.good() ){
      if (line2.find("//")!=line2.npos || line2.size()==0) { getline(inFile2,line2); continue; }
      
      istringstream info_line2(line2); ///line2 has two float numbers, first one is bin number and second one is rw_factor2. An example of a line: 1 1.076741 
      info_line2 >> _index2 >>  _rw_factor2;  
      reweightFactor2[_index2] = _rw_factor2; 
      
      getline (inFile2,line2);
    }
  }
  
  inFile2.close();

  ///////////////////////////////
  
  
  int N = mychain->GetEntries();


  int counter=1 ;

  //  vector<std::pair<int,std::set<int> > > fEventList;   bool firstDataEvent=true;

  for (int i_N=0; i_N<N; i_N++) {
    
    // message print module 
    int ith = (int)(100*(i_N/(float)N))  ;
    if (ith>counter){
      counter = ith ;
      std::cout << "Loading: " << ith  << "%\r" << std::flush;
      //std::cout << "Loading: " << ith  << "%\n";
    }

    h1->GetEntry(i_N);
    
    int RunNumber = h1->RunNumber ;
    //    cout<<"it appears that "<<h1->RunNumber<<" is "<<RunNumber<<endl;
 
    int channelNumber = h1->mc_channel_number ;

    //if(i_N%100000==0)cout<<i_N<<": RunNumber-> "<<RunNumber<<", datasetId-> "<<channelNumber<<endl; //every 1000 events it will print out event number, RunNumber and datasetId

    //    bool IsData (false);  if ( h1->RunNumber >= 200000 ) IsData = true ; ///this is indeed RunNumber, not datasetId

    bool IsData (false);  if ( channelNumber == 0 ) IsData = true ; ///mc_channel_number ==0 for data, ==datasetID for MC
    
    double eventWeight (1.);
    if ( IsData ) {
      RunNumber = 888888;///Now RunNumber is changed to a arbitrary number that does not matches with a datasetId
    }
    else{
      RunNumber = h1->mc_channel_number ;///Now RunNumber is changed to datasetId
      eventWeight *= h1->mcEventWeight ; //this eventweight is directly from D3PDs.
      

      if(DEBUG){
	cout<<"initial event weight = "<<eventWeight<<endl;
      }

      if ( RunNumber ==185836 || RunNumber ==185837 || RunNumber ==185696 || RunNumber ==185703) //Powheg W+jets samples
	{
	  if ( eventWeight<0 || eventWeight > 1e03)continue; //there are several events with very high generator eventWeight. Removing them.
	}

      eventWeight *= runWeight[channelNumber] * h1->pileupEventWeight ;
      
      //cout<<"runweight = "<<runWeight[channelNumber]<<" pileupwieght = "<<h1->pileupEventWeight<<endl;
      
      if(DEBUG){
	cout<<"updated event weight = "<<eventWeight<<endl;
      }
      
      
      // Remove overlap events in unfiltered Wjets samples 
      if ( RunNumber >=147774 && RunNumber <=147776 ){ if (h1->truth_sherpa_Wpt > 40.) continue ; } //redundant because already removed at CAF level
      // Remove overlap events in unfiltered Zjets samples 
      //if ( RunNumber>=147770 && RunNumber<=147772 ){ if (h1->truth_sherpa_Zpt > 40.) continue ; } ///was commented out but uncommented because using pt sliced Z+jets (7/23/14)

      if ( RunNumber == 117050 ) eventWeight *= h1-> ttbarWeight ;///New weights for Powheg-Pyhtia samples. Works for the new slim ntuples (8/14/14)
      
    }
    
    ///if(i_N%100000==0)cout<<i_N<<": datasetId-> "<<channelNumber<<", runWeight["<<channelNumber<<"]-> "<<runWeight[channelNumber]<<", mcEventWeight-> "<<h1->mcEventWeight<<", pileupEventWeight-> "<<h1->pileupEventWeight<<", eventWeight-> "<<eventWeight<<endl; //every 100000 events it will print out event number, RunNumber and datasetId

    // Reset weight 
    //eventWeight = 1.;

    if ( h1->lep_ID->size() == 0)continue; ///&&&& added on 1/8/15.  JERUp 110101 samples were crashing because exactly one lepton was not required while slimming.
    
    string lepflavor="e";   if (abs(h1->lep_ID->at(0))==13 ) {lepflavor="m";}
    //string lepflavor="e";   if (abs(h1->lep_ID->at(0))==13 ) {lepflavor="m";continue;}
    string lepcharge="m";   if (    h1->lep_ID->at(0)<0 )    {lepcharge="p";}///Don't be confused. electron pdgId is 11 and positron is -11. 
    //string lepcharge="m";   if (    h1->lep_ID->at(0)<0 )    {lepcharge="p";continue;}
    std::string channelName = lepflavor + lepcharge + "_" ; 

    // Not charge
    //string lepflavor="m";   if (abs(h1->lep_ID->at(0))==11 ) lepflavor="e"; 
    //std::string channelName = lepflavor + "_" ; 


    //if (DEBUG) cout << channelName << " run " << RunNumber << endl;

    //    cout << channelName << " run " << RunNumber << endl;

    //---------------------                                 
    // Selection
    string prodmode("WBF");
    //if ( vbfjetsIndex.first <0 || vbfjetsIndex.second<0 ) {prodmode = "ggF";continue;} //default mode is WBF, if there are less than two tagged jets then the mode is ggF
    
    //string prodmode("WBF"); if ( vbfjetsIndex.first <0 || vbfjetsIndex.second<0 ) {prodmode = "ggF";}
    string cutname = channelName + prodmode + "_";


    h1->vbfjetsIndex1 = -1;
    h1->vbfjetsIndex2 = -1;
    h1->WjetsIndex1 = -1;
    h1->WjetsIndex2 = -1;    

    
    //cout<<"Event weight = "<<eventWeight<<endl;

    ///Added codes for lepton isolation studies and truth ptW (1/9/15)
    /*
    //////
    //if ( CutOnMET && ( !(h1->MET*constants::GeV< 25.) ) ) continue; //for QCD enriched region
    ////
    
 
    Float_t val_lepEtCone30 = h1->lepEtCone30 *constants::GeV;
    Float_t val_lepPtCone30 = h1->lepPtCone30 *constants::GeV;
    Float_t val_lepz0sinth = h1->lepz0sinth;
    Float_t val_lepd0sigd0 = h1->lepd0sigd0;
    Float_t val_etIso = (h1->lepEtCone30)/h1->lep_pt ->at(0);
    Float_t val_ptIso = (h1->lepPtCone30)/h1->lep_pt ->at(0);
    */
    //////////////
    /*
    
    if (abs(h1->lep_ID->at(0))==11 ) //electron
      {
	if(! ( val_etIso <0.28 && val_ptIso <0.1 ) )continue; //VBS isolation cuts
	//if(! ( val_lepz0sinth < 0.4 ) )continue; //VBS z0sinth cut
	//if(! ( val_lepd0sigd0< 3. ) )continue; //VBS d0sig cut
	
	// if(! ( val_etIso <0.14  ) )continue; //lvjj 8TeV et isolation cut
	// if(! ( val_ptIso <0.07 ) )continue; //lvjj 8TeV pt isolation cut
	// if(! ( val_lepz0sinth < 0.5 ) )continue; //lvjj 8TeV z0sinth cut
	//if(! ( val_lepd0sigd0< 5. ) )continue; //lvjj 8TeV d0sig cut
      }
    else if (abs(h1->lep_ID->at(0))==13 ) //muon
      {
	if(! ( val_etIso <0.30 && val_ptIso <0.12 ) )continue; //VBS isolation cuts
	//if(! ( val_lepz0sinth < 1. ) )continue; //VBS z0sinth cut
	//if(! ( val_lepd0sigd0< 3. ) )continue; //VBS d0sig cut
	
	// if(! ( val_ptIso <0.07 ) )continue; //lvjj 8TeV pt isolation cut
	// if(! ( val_lepz0sinth < 0.5 ) )continue;//lvjj 8TeV z0sinth cut
	//if(! ( val_lepd0sigd0< 3. ) )continue;//lvjj 8TeV d0sig cut
      }
    ///////////////
    */

    /*
    /////if truthStable is filled

    
    if (RunNumber >= 167740 && RunNumber <= 167748 ){
      TLorentzVector true_lepton;  //In this case leading true lepton
      
      if ( abs(h1->lep_ID->at(0)) == 11 && h1->truthStable_el_pt->size()>0 ){ //electron channel
	true_lepton.SetPtEtaPhiM(  h1->truthStable_el_pt->at(0)*constants::GeV, 
				   h1->truthStable_el_eta->at(0)  ,
				   h1->truthStable_el_phi->at(0)  ,
				 0.  );
      }else if ( abs(h1->lep_ID->at(0))== 13  && h1->truthStable_mu_pt->size()>0 ){ //muon channel
	true_lepton.SetPtEtaPhiM(  h1->truthStable_mu_pt->at(0)*constants::GeV, 
				   h1->truthStable_mu_eta->at(0)  ,
				   h1->truthStable_mu_phi->at(0)  ,
				   0.  );
      }
    
      float MET_truth_etx = h1->MET_truth_nonint_x *constants::GeV ;
      float MET_truth_ety = h1->MET_truth_nonint_y *constants::GeV ;
      float MET_truth_et = h1->MET_truth_nonint *constants::GeV ;
      float MET_truth_phi = TMath::ATan(MET_truth_ety/MET_truth_etx);
      
      float trueW_px = true_lepton.Px()+MET_truth_etx;
      float trueW_py = true_lepton.Py()+MET_truth_ety;
      float val_trueW_pt = TMath::Sqrt(trueW_px*trueW_px+trueW_py*trueW_py);
      
      //if (RunNumber >= 167740 && RunNumber <= 167748 ){
      if (val_trueW_pt> 40.)continue;
      //}
      h1->trueW_pt = val_trueW_pt;
    }
    ///////
    */
    
    ct.add( RunNumber, cutname+"PRESELECT", eventWeight ) ;
    
    histfiller -> FillHistgrams( channelName , prodmode+"_PRESELECT" , RunNumber, h1, eventWeight );
    
    
    //this is to remove tri-boson events that are double-counted in Whizard samples.
    bool isDoubleCounted = SelectionTools::isDoubleCountedVWZ(h1);
    if(isDoubleCounted){
      continue;
    }

    
    //cout<<h1->IsBadMediumBCH<<" "<<h1->IsBadMediumBCHUp<<" "<<h1->IsBadMediumBCHDown<<" "<<h1->IsBadTightBCH<<endl;
    if (bchMode>=0){
      if (h1->IsBadMediumBCH >1 || h1->IsBadMediumBCHUp >1 || h1->IsBadMediumBCHDown >1 || h1->IsBadTightBCH >1 ) {
	
        cout<<"Problem with bchMode. It seems there is no bch information in CAF files. Set bchMode to -1"<<endl;
    	exit(0);
      }
    }else if (bchMode<0 && !(h1->IsBadMediumBCH >1 || h1->IsBadMediumBCHUp >1 || h1->IsBadMediumBCHDown >1 || h1->IsBadTightBCH >1 ) ){
      
      //cout<<"Problem with bchMode. Check if you are using bch cut. Nominally bchMode should be set to 0"<<endl;
      //exit(0);
    }

    // &&&& if you do not comment out or set bchmode to -1 for caf v3 or older, your events will be thrown out and you'll be left with PRESELECT region only !!!!!!
    
    //    /*
    if(bchMode==0 && h1->IsBadMediumBCH){
      continue;
    }
    else if(bchMode==1 && h1->IsBadMediumBCHUp){
      continue;
    }
    else if(bchMode==2 && h1->IsBadMediumBCHDown){
      continue;
    }
    else if(bchMode==3 && h1->IsBadTightBCH){
      continue;
    }
    //    */
    
    
    // Set neutrino pZ
    objselector.SetNeutrinoPz();
    //cout << " neutrino pZ " << h1->MET_z << endl;
   
 
   

    std::pair<int, int> vbfjetsIndex;
    std::pair<int, int> vbfjetsFJIndex;


    
    float jetpTCut(30.),
      fatjet_minm(60.), //fatjet mass window low edge. default 60
      fatjet_maxm(110.),//fatjet mass window high edge. default 110
      min_dyjj    (0.), //original 3
      leadingJetPt (30.), //original 40, used in vbfjet selection but I am not using it
      jet0PtCut   (30.), //leading jet pt, added by auzaman
      jet1PtCut   (30.), //sub-leading jet pt, added by auzaman
      lepptCut    (30.),
      metCut      (30.),
      mtCut       (-1.), //default -1, used 40
      
      mlvjjCut    (0.), //used 500
      ptwjjResolvedCut    (0.), //used 250
      etaYCut     (-10000000);  //default -10000000
  
      
    //   /*  
    float fatjetPt( 200.); //200 required for a nice enough W peak in ttbar
    float ptwlepCut (0.); //used 150.
    //float ptwlepCut (150.); //lv4.4
    float cosThWDecayCut ( 10000 ); //default 10000, used 0.55
    
    //cuts for {resolved,fat-jet} selection.
    float bosonCenCut[2] = {-100000,-100000}; //default -100000,-100000 ,  used  1.3,0.9
    float mTWVCut[2]     = {0., 0.}; //default 0
    float VVvecptdiffCut[2] = {0., 0.};  //default 0
    float VVptBalanceCut[2] = {10000., 10000}; //default 10000,10000 ,  used 10000., 0.25
    
    float min_mjj[2]        = {500. , 500.}; //original 600 , default 500 , used  900., 850.
    //float min_mjj[2]        = {200. , 200.}; 
    
    //  */
      
    
       /*
       
    float  fatjetPt( 100.); //200 required for a nice enough W peak in ttbar
    float  ptwlepCut (150.); //used 150.
    //float  ptwlepCut (0.); // lv7.1
    float cosThWDecayCut ( 0.55 ); //default 10000, used 0.55

    // float bosonCenCut[2] = {-100000 ,-100000}; //default -100000 ,  used  1.3,0.9
    float bosonCenCut[2] = {1.3,0.9}; 
    float mTWVCut[2]     = {0., 0.}; //default 0   
    // float mTWVCut[2]     = {625., 800.}; //default 0
    float VVvecptdiffCut[2] = {0., 0.};  //default 0
     
    float VVptBalanceCut[2] = {10000., 0.3}; //default 10000,10000 ,  used 10000., 0.25
    
    float min_mjj[2]        = {900. , 850.}; //original 600 , default 500 , used  900., 850.
    //float min_mjj[2]        = {200. , 200.}; //v8.1
    
      */      
      
    //&&&& fat jet lepton overlap removal
    TLorentzVector lepton; 
    lepton.SetPtEtaPhiE(  h1->lep_pt ->at(0)*constants::GeV, 
			  h1->lep_eta->at(0)  ,
			  h1->lep_phi->at(0)  ,
			  h1->lep_E  ->at(0)*constants::GeV  ); 
    //&&&&
    
    vector<TLorentzVector> m_jets;
    for (int ijet=0; ijet<h1->jet_n; ijet++){
      TLorentzVector thisjet;
      thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
			    h1->jet_eta->at(ijet),
			    h1->jet_phi->at(ijet),
			    h1->jet_E  ->at(ijet)/1000. ) ;
     
      m_jets.push_back(thisjet);
    }

    vector<TLorentzVector> m_fatjets;
    for (int ijet=0; ijet<h1->fatjet_n; ijet++){
      TLorentzVector thisjet;
      //in order for logic to work, need to write out ALL fat jets into m_fatjets.  Don't put any additional cuts here.      
      thisjet.SetPtEtaPhiE( h1->fatjet_pt ->at(ijet)/1000.,
			    h1->fatjet_eta->at(ijet),
			    h1->fatjet_phi->at(ijet),
			    h1->fatjet_E  ->at(ijet)/1000. ) ;

      m_fatjets.push_back(thisjet);
      
    }

    if((int)m_fatjets.size() != h1->fatjet_n){
      cout<<"This is not supposed to happen!  This is a fatal error!  m_fatjets *must* contain all the fatjets in the slim ntuple!"<<endl;
      exit(0);
    }
    
    
    //only FJ
    // if ( m_fatjets.size()<1  ) continue; 
    
    //ct.add( RunNumber, cutname+"FATJET", eventWeight ) ;    
    
        
    
    ///highest dEta jet pair and highest ptjj pair
    double dEtaMax=0.;
    double ptjjMax=0.;
    for (int i=0; i<h1->jet_n-1; i++){
      for (int j=i+1; j<h1->jet_n; j++){
	if (fabs(m_jets[i].Eta()-m_jets[j].Eta())>dEtaMax){
	  dEtaMax=fabs(m_jets[i].Eta()-m_jets[j].Eta());
	}
	if ((m_jets[i]+m_jets[j]).Pt()> ptjjMax){
	  ptjjMax=(m_jets[i]+m_jets[j]).Pt();
	}

      }
     
    }
    h1->dEtaMax = dEtaMax ; 
    h1->ptjjMax = ptjjMax ;
    

    int nLeptons=h1->lep_n; //sum of good and bad lepton
    bool doZCR=false;

    if(nLeptons==1){
      if ( doBadLepton) {     if ( h1->lep_isGood->at(0)) continue; }
      else              {     if (!h1->lep_isGood->at(0)) { continue;} }
      ct.add( RunNumber, cutname+"ONELEPTON", eventWeight ) ;  //only do cutflow for 1-lepton events.
    }
    else if(nLeptons==2){
      if( (!h1->lep_isGood->at(0)) || (!h1->lep_isGood->at(1)) ){ ///both leptons need to be good leptons
	continue;
      }
      if( ( h1->lep_ID->at(0) * h1->lep_ID->at(1) ) > 0 ){
	continue;  //leptons must be opposite-sign.
      }

      doZCR=true;
      //      cout<<"Do ZCR!"<<endl;
    }
    else{
      continue; ///zero-lepton or more than two lepton events rejected
    }
    


    // lepton pT                                                                                                                                          
    if ( !(h1->lep_pt->at(0)*constants::GeV > lepptCut) ) continue ; //originally 25                                                                                 

    if(!doZCR){
      //only do cut-flow and fill histograms for 1-lepton events.                                                                                         
      //histfiller -> FillHistgrams( channelName , prodmode+"_LepPt" , RunNumber, h1, eventWeight );                                                      
      ct.add( RunNumber, cutname+"LEPTONPT", eventWeight ) ;

    }
    

    
    bool useFJ(false); ///true means Fatjet case for W-jet selection
    std::pair<int, int> WjetsIndex;
    std::pair<int, int> WjetsFJIndex;
    
    WjetsIndex.first=-1, WjetsIndex.second=-1;
    WjetsFJIndex.first=-1, WjetsFJIndex.second=-1;
    vbfjetsIndex.first=-1, vbfjetsIndex.second=-1;
    vbfjetsFJIndex.first=-1, vbfjetsFJIndex.second=-1;
    
    bool passWjetsSelection=false;
    bool passWjetsFJSelection=false;
    
    //    /*
    ///We will check both resolved and fat jet possibilities.
    //passWjetsSelection=objselector.findWJetsNew( &m_jets, &m_fatjets, &vbfjetsIndex, &WjetsIndex, jetpTCut,useFJ) ;  //using findWJetsNew which selects the pair of highest pt jets with M within 15 GeV of WMASS
    passWjetsSelection=objselector.findWJetsNew( &m_jets, &m_fatjets, &vbfjetsIndex, &WjetsIndex, jetpTCut, fatjetPt, fatjet_minm, fatjet_maxm, useFJ) ;  //using findWJetsNew which selects the pair of highest pt jets with M within 15 GeV of WMASS                                                                                                   
    //(this is done to avoid ambiguity, because the pair closest to Wmass sometimes                                                                       
    //can be ruled out if a harder jet pt cut is imposed)   
    
    useFJ=true; 
    passWjetsFJSelection=objselector.findWJetsNew( &m_jets, &m_fatjets, &vbfjetsFJIndex, &WjetsFJIndex, jetpTCut, fatjetPt, fatjet_minm, fatjet_maxm, useFJ) ;
    //  */
    
    ///VBF tagged jets added by auzaman                                                                                
    bool doFJ=false;  ///true means Fatjet case for vbf jet selection
    
    if(passWjetsSelection){
      
      objselector.findVBFTaggingJets( &m_jets, &vbfjetsIndex, &WjetsIndex, jetpTCut, min_mjj[0], min_dyjj, leadingJetPt, &m_fatjets, fatjetPt, fatjet_minm, fatjet_maxm, doFJ);
      //h1->vbfjetsIndex1 = vbfjetsIndex.first ;
      //h1->vbfjetsIndex2 = vbfjetsIndex.second ;
    }    

    doFJ=true;
    if(passWjetsFJSelection){
      
      objselector.findVBFTaggingJets( &m_jets, &vbfjetsFJIndex, &WjetsFJIndex, jetpTCut, min_mjj[1], min_dyjj, leadingJetPt, &m_fatjets, fatjetPt, fatjet_minm, fatjet_maxm, doFJ);
      
      //    cout << " VBF jets Index " << vbfjetsIndex.first << ", " << vbfjetsIndex.second << endl;
    }

    bool passVbfSelection=true;
    bool passVbfFJSelection=true;
    if ( (vbfjetsIndex.first <0 || vbfjetsIndex.second<0) ){
      passVbfSelection=false;
    }
    if ( vbfjetsFJIndex.first <0 || vbfjetsFJIndex.second<0 ) {
      passVbfFJSelection=false;
    }
    
    if(!passWjetsSelection && !passWjetsFJSelection){
      continue;
    }

    if(!passVbfSelection && !passVbfFJSelection){
      continue;
    } 
    
    /*
      if( (m_jets.size()<4) ){
       continue;
    }

    double mjjMax=0.;
    for (int i=0; i<h1->jet_n-1; i++){
      for (int j=i+1; j<h1->jet_n; j++){
        if ((m_jets[i] + m_jets[j]).M() > mjjMax){
          mjjMax=(m_jets[i] + m_jets[j]).M();
        }
      }
    }
    if(mjjMax<500){
      continue;
    }
    */

    
    
    
    if(passVbfSelection){
      if (DEBUG) {
	cout << " VBF jets Index " << vbfjetsIndex.first << ", " << vbfjetsIndex.second << endl;
      }
    }


  
    if (DEBUG){
      std::cout<<"number of jets in the event = "<<h1->jet_n<<endl;
      std::cout<<"number of leptons in the event = "<<h1->lep_n<<endl;
      std::cout<<"lepton[0] pt = "<<h1->lep_pt->at(0)*constants::GeV<<endl;
      std::cout<<"lep_isGood ->at(0)  = "<<h1->lep_isGood->at(0)<<endl;
    }
    
    /*
    
    if(passVbfSelection){
      passWjetsSelection=objselector.findWJetsNew( &m_jets, &m_fatjets, &vbfjetsIndex, &WjetsIndex, jetpTCut, useFJ) ;  //using findWJetsNew which selects the pair of highest pt jets with M within 15 GeV of WMASS
      //(this is done to avoid ambiguity, because the pair closest to Wmass sometimes
      //can be ruled out if a harder jet pt cut is imposed)
    }
        
    useFJ=true;
    if(passVbfFJSelection){
      passWjetsFJSelection=objselector.findWJetsNew( &m_jets, &m_fatjets, &vbfjetsFJIndex, &WjetsFJIndex, jetpTCut, useFJ) ;
    }
    */


    /*
    if (!passWjetsSelection && !passWjetsFJSelection) {
      //cout<<"WjetsIndex1 "<<WjetsIndex.first<<" "<<"WjetsIndex2 "<<WjetsIndex.second<<endl;
      continue;
    }
    */    
    
    
    //h1->WjetsIndex1 = WjetsIndex.first ; 
    //h1->WjetsIndex2 = WjetsIndex.second ;
    
    if(!doZCR){
      //only do cut-flow and fill histograms for 1-lepton events.

      
      //NOTE:  _JetSelectResolve and _JetSelectFat HISTOGRAMS CONTAIN OVERLAPPING EVENTS!!!!
      if(passWjetsSelection && passVbfSelection ){
	h1->WjetsIndex1 = WjetsIndex.first ;
	h1->WjetsIndex2 = WjetsIndex.second ;
	h1->vbfjetsIndex1 = vbfjetsIndex.first ;
	h1->vbfjetsIndex2 = vbfjetsIndex.second ;

	ct.add( RunNumber, cutname+"JETSELECTResolve", eventWeight ) ;  
	
	//histfiller -> FillHistgrams( channelName , prodmode+"_JetSelectResolve" , RunNumber, h1, eventWeight );
      }
      
      if( passWjetsFJSelection && passVbfFJSelection ){
	h1->WjetsIndex1 = WjetsFJIndex.first ;
	h1->WjetsIndex2 = WjetsFJIndex.second ;
	h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
	h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
	
	ct.add( RunNumber, cutname+"JETSELECTFat", eventWeight ) ;  

	//histfiller -> FillHistgrams( channelName , prodmode+"_JetSelectFat" , RunNumber, h1, eventWeight );      
      }
      
      /*
      if(passWjetsSelection && !passWjetsFJSelection){
	//histfiller -> FillHistgrams( channelName , prodmode+"_WJETresolve" , RunNumber, h1, eventWeight );
      }
      else if(!passWjetsSelection && passWjetsFJSelection){
	h1->WjetsIndex1 = WjetsFJIndex.first ; 
	h1->WjetsIndex2 = WjetsFJIndex.second ;
	
	h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
	h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
	
	//histfiller -> FillHistgrams( channelName , prodmode+"_WJETfat" , RunNumber, h1, eventWeight );
      }
      else if(passWjetsSelection && passWjetsFJSelection){
	h1->WjetsIndex1 = WjetsIndex.first ; 
	h1->WjetsIndex2 = WjetsIndex.second ;
	
	h1->vbfjetsIndex1 = vbfjetsIndex.first ;
	h1->vbfjetsIndex2 = vbfjetsIndex.second ;
	
	//histfiller -> FillHistgrams( channelName , prodmode+"_WJETbothR" , RunNumber, h1, eventWeight );
	
	h1->WjetsIndex1 = WjetsFJIndex.first ; 
	h1->WjetsIndex2 = WjetsFJIndex.second ;
	
	h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
	h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
	
	//histfiller -> FillHistgrams( channelName , prodmode+"_WJETbothF" , RunNumber, h1, eventWeight );
      }
      */
      
    }  //end if(!doZCR)
    
    //if ( RunNumber == 117050 )cout<<"TAGJETVETO passed!"<<endl;

    
    if (DEBUG) cout << " useFJ " << useFJ << ", idx1=" << WjetsIndex.first << ", idx2=" <<  WjetsIndex.second << " jet n=" << h1->jet_n << endl;

    if(passVbfSelection){
      //if (DEBUG) {
      //cout << " h1->vbfjetsIndex " << h1->vbfjetsIndex1 << ", " << h1->vbfjetsIndex2 << endl;
	//}
    }

    TLorentzVector vbfjet1,vbfjet2, divbfjets;
    
    if (h1->vbfjetsIndex1>=0 && h1->vbfjetsIndex2>=0) { //When you have two vbf jets (both resolved and fat jet selection)
      
      vbfjet1.SetPtEtaPhiE(  h1->jet_pt ->at(h1->vbfjetsIndex1)*constants::GeV,
			     h1->jet_eta->at(h1->vbfjetsIndex1),
			     h1->jet_phi->at(h1->vbfjetsIndex1),
			     h1->jet_E  ->at(h1->vbfjetsIndex1)*constants::GeV );
      
      vbfjet2.SetPtEtaPhiE(  h1->jet_pt ->at(h1->vbfjetsIndex2)*constants::GeV,
			     h1->jet_eta->at(h1->vbfjetsIndex2),
			     h1->jet_phi->at(h1->vbfjetsIndex2),
			     h1->jet_E  ->at(h1->vbfjetsIndex2)*constants::GeV );
      divbfjets = vbfjet1 + vbfjet2;
    }

    float val_mjjTagged = divbfjets.M();
    //std::cout<<"val_mjjTagged  = "<< val_mjjTagged <<endl;
    

    //--------------------------------------------
    // Plotting
    
    
    // MET 
    if(!doZCR){  
      //MAYBE WE WANT AN MET CUT FOR Z-CR, BUT I DON'T THINK SO... -BL
      

      if ( CutOnMET && ( !(h1->MET*constants::GeV> metCut) ) ) continue;//originally 40. If CutOnMET is 0, skip this line

      if(passWjetsSelection && passVbfSelection ){
        h1->WjetsIndex1 = WjetsIndex.first ;
        h1->WjetsIndex2 = WjetsIndex.second ;
        h1->vbfjetsIndex1 = vbfjetsIndex.first ;
        h1->vbfjetsIndex2 = vbfjetsIndex.second ;

	//	histfiller -> FillHistgrams( channelName , prodmode+"_METResolve" , RunNumber, h1, eventWeight ); 
	ct.add( RunNumber, cutname+"METResolve", eventWeight ) ;
      }

      if( passWjetsFJSelection && passVbfFJSelection ){
        h1->WjetsIndex1 = WjetsFJIndex.first ;
        h1->WjetsIndex2 = WjetsFJIndex.second ;
        h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
        h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
	
	//      histfiller -> FillHistgrams( channelName , prodmode+"_METFat" , RunNumber, h1, eventWeight ); 
        ct.add( RunNumber, cutname+"METFat", eventWeight ) ;
	
      }
      
      
    }
    
    // prepare vectors
    /* //&&&&
    TLorentzVector lepton; 
    lepton.SetPtEtaPhiE(  h1->lep_pt ->at(0)*constants::GeV, 
			  h1->lep_eta->at(0)  ,
			  h1->lep_phi->at(0)  ,
			  h1->lep_E  ->at(0)*constants::GeV  ); 
    */
    TLorentzVector neutrino; 
    float E_MET = TMath::Sqrt(h1->MET_x*h1->MET_x + h1->MET_y*h1->MET_y + h1->MET_z*h1->MET_z);
    neutrino.SetPxPyPzE(  h1->MET_x*constants::GeV, 
			  h1->MET_y*constants::GeV, 
			  h1->MET_z*constants::GeV, 
			  E_MET    *constants::GeV );



    /*
    /////doSignal
    int mc_n= h1->mctruth_pdgId->size();
    //cout<<"mc_n = "<<mc_n<<endl;
    TLorentzVector true_lepton;
    
    for(int i=0;i<mc_n;i++){
      if ( abs(h1->mctruth_pdgId->at(i)) == 11 || abs(h1->mctruth_pdgId->at(i)) == 13 ){ //electron or muon
	true_lepton.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*constants::GeV, 
				   h1->mctruth_eta ->at(i)  ,
				   h1->mctruth_phi ->at(i)  ,
				   h1->mctruth_m ->at(i)*constants::GeV  ); 
      }
    }
    TLorentzVector true_neutrino;
    
    for(int i=0;i<mc_n;i++){
      if ( abs(h1->mctruth_pdgId->at(i)) == 12 || abs(h1->mctruth_pdgId->at(i)) == 14 ){ //electron or muon neutrino
	true_neutrino.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*constants::GeV, 
				     h1->mctruth_eta ->at(i)  ,
				     h1->mctruth_phi ->at(i)  ,
				     h1->mctruth_m ->at(i)*constants::GeV  ); 
      }
    }
    ///////
    */
    
  
    
    float val_mT = sqrt(2*lepton.Pt()*neutrino.Pt()*(1-cos(fabs(lepton.DeltaPhi(neutrino)))));
    float val_ptwlep = ( lepton + neutrino ).Pt();
    
    //cout<<"val_mT= "<<val_mT<<endl;
    
    if(!doZCR){
      if ( val_mT< mtCut)  continue;//lv transverse mass >40GeV
      
      //cout<<"val_mT after cut= "<<val_mT<<endl;
      // ct.add( RunNumber, cutname+"MT", eventWeight ) ;
      
      if ( val_ptwlep< ptwlepCut )  continue;//ptW(lv)  >150GeV
      
      if(passWjetsSelection && passVbfSelection ){
	ct.add( RunNumber, cutname+"PtWlepResolve", eventWeight ) ;
      }
      if( passWjetsFJSelection && passVbfFJSelection ){
	ct.add( RunNumber, cutname+"PtWlepFat", eventWeight ) ;
      }
      
    }
    else{  //if doZCR
      
      TLorentzVector lepton2;
      lepton2.SetPtEtaPhiE(  h1->lep_pt ->at(1)*constants::GeV,
			     h1->lep_eta->at(1)  ,
			     h1->lep_phi->at(1)  ,
			     h1->lep_E  ->at(1)*constants::GeV  );


      double dilepMass = (lepton+lepton2).M();
      // double dilepPt = (lepton+lepton2).Pt();
      if(dilepMass<70.0 || dilepMass>110.0){
	continue;
      }
      
      //IF I DO APPLY A PTWLEP CUT, THEN MAYBE FOR Z-CR WE SHOULD APPLY AN ANALOGOUS PT(LL) CUT. -BL
      
    }  //end if(doZCR)


   /*
    double val_min_dEta_Wlepjet=1000.; //min value of dEta between Wlep and a jet
    for (int i=0; i<h1->jet_n; i++){
      if (fabs(( lepton + neutrino ).Eta()-m_jets[i].Eta())<val_min_dEta_Wlepjet){
	val_min_dEta_Wlepjet=fabs(( lepton + neutrino ).Eta()-m_jets[i].Eta());
      }
    }
   */
    
   bool passTotalResolved=false;
   bool passTotalFat=false;
   bool pass_CR_Top_TotalResolved=false;
   bool pass_CR_Top_TotalFat=false;
   bool pass_CR_Wjj_TotalResolved=false;
   bool pass_CR_Wjj_TotalFat=false;
   double thetotalweightR=0, thetotalweightF=0;  //these weights are the final weight, but are only set if an event makes it into one of the SR or CR.   We keep track of them because they are needed later, for the plots that have resolved/fatjet overlap removed.
   
   
   string jetmodeName[2]={"Resolve","Fat"};
   for(int jetmodeLoop=0; jetmodeLoop<2; jetmodeLoop++){
     
     double thetotalweight = eventWeight;   //DO NOT MODIFY eventweight!!!  Only modify thetotalweight if necessary.
     
     //jetmodeLoop=0:  require to pass resolved-jet selection
     //jetmodeLoop=1:  require to pass fat-jet selection
     
     if(jetmodeLoop==0 && (!passWjetsSelection || !passVbfSelection ) ){
       continue;
     }
     
     if(jetmodeLoop==1 && (!passWjetsFJSelection || !passVbfFJSelection) ){
       continue;
     }
     
     if(jetmodeLoop==0){
       useFJ=false;
       
       h1->WjetsIndex1 = WjetsIndex.first ; 
       h1->WjetsIndex2 = WjetsIndex.second ;
       
       h1->vbfjetsIndex1 = vbfjetsIndex.first ;
       h1->vbfjetsIndex2 = vbfjetsIndex.second ;
       
     }
     else{
       useFJ=true;
       
       h1->WjetsIndex1 = WjetsFJIndex.first ; 
       h1->WjetsIndex2 = WjetsFJIndex.second ;
       
       h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
       h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
       
     }

     
     //     cout<<"indices = "<<h1->WjetsIndex1<<" ; "<<h1->WjetsIndex2<<" ; "<<h1->vbfjetsIndex1<<" ; "<<h1->vbfjetsIndex2<<endl;
     
     ///detaTaggedJets 
     float val_dEtaTaggedJets  = fabs(m_jets.at(h1->vbfjetsIndex1).Eta()-m_jets.at(h1->vbfjetsIndex2).Eta());
     
     
     
     TLorentzVector wjet1, wjet2, wjetfat,diwjets,leptonicW;
     leptonicW = lepton + neutrino;
     
     if (!useFJ) {
       wjet1.SetPtEtaPhiE(  h1->jet_pt ->at(h1->WjetsIndex1)*constants::GeV,
			    h1->jet_eta->at(h1->WjetsIndex1),
			    h1->jet_phi->at(h1->WjetsIndex1),
			    h1->jet_E  ->at(h1->WjetsIndex1)*constants::GeV );
       
       wjet2.SetPtEtaPhiE(  h1->jet_pt ->at(h1->WjetsIndex2)*constants::GeV,
			    h1->jet_eta->at(h1->WjetsIndex2),
			    h1->jet_phi->at(h1->WjetsIndex2),
			    h1->jet_E  ->at(h1->WjetsIndex2)*constants::GeV );
       
       diwjets = wjet1 + wjet2;
       
       //float val_mwjj  = diwjets.M();
       float val_ptwjj  = diwjets.Pt();
       
       //This cut is only for the resolved jet case.
       if ( val_ptwjj< ptwjjResolvedCut)  continue;//ptW(jj) > 250GeV
       
     }
     else{
       diwjets.SetPtEtaPhiE(  m_fatjets.at(h1->WjetsIndex1).Pt(),
			      m_fatjets.at(h1->WjetsIndex1).Eta(),
			      m_fatjets.at(h1->WjetsIndex1).Phi(),
			      m_fatjets.at(h1->WjetsIndex1).E() );

       double dR_lep_FJ = diwjets.DeltaR(lepton);
       
       if(dR_lep_FJ < constants::dRFJlepORCut){
	 continue;   //EVENTUALLY THIS SHOULD BE MOVED TO THE SLIMMING CODE, ALTHOUGH IT SHOULDN'T HURT TO KEEP IT HERE AS A REDUNDANT CUT!! - BL
       }
       
     }
     
     float val_mlvjj = ( leptonicW + diwjets).M();
     if ( val_mlvjj< mlvjjCut )  continue;// m(lvjj) > 500GeV
     
     double val_VVvecptdiff = (diwjets - leptonicW).Pt();
     if (val_VVvecptdiff < VVvecptdiffCut[jetmodeLoop] ) continue;    
     
     double val_mTWV = histfiller->getMTWV(diwjets, lepton, neutrino);
     if (val_mTWV < mTWVCut[jetmodeLoop] ) continue;

     float val_VVptBalance = (lepton + neutrino+diwjets).Pt()/(leptonicW.Pt() + diwjets.Pt());
     
     float avgEtaTagged  = ( m_jets.at(h1->vbfjetsIndex1).Eta() + m_jets.at(h1->vbfjetsIndex2).Eta() ) / 2;
     double etaY =  (val_dEtaTaggedJets/2)-fabs(lepton.Eta()-avgEtaTagged);

     double val_lepCentrality = histfiller->getCentrality( m_jets.at(h1->vbfjetsIndex1).Eta(), m_jets.at(h1->vbfjetsIndex2).Eta(), lepton.Eta() );
     double val_bosonCentrality = histfiller->getCentrality( m_jets.at(h1->vbfjetsIndex1).Eta(), m_jets.at(h1->vbfjetsIndex2).Eta(), diwjets.Eta(), leptonicW.Eta() );

     if(val_VVptBalance > VVptBalanceCut[jetmodeLoop]){
       continue; //Placing a cut on the VV pT balance -- BL
     }     
     
     
     if(!doZCR){
       ct.add( RunNumber, cutname+"VVPtBal"+jetmodeName[jetmodeLoop], thetotalweight ) ;
     }     

     if(etaY < etaYCut){
       continue;   //Placing a cut on etaY -- BL
     }
     if( val_bosonCentrality < bosonCenCut[jetmodeLoop] ){
       continue;  //Placing a cut on the boson centrality -- BL
     }     
     
     if(!doZCR){
       ct.add( RunNumber, cutname+"Centrality"+jetmodeName[jetmodeLoop], thetotalweight ) ;
     }

     if (!useFJ) {
       double val_cosThWDecay = fabs(histfiller->getCosThetaStar(  wjet1, diwjets, leptonicW ));
       if (val_cosThWDecay > cosThWDecayCut )  continue;
     }

     if(!doZCR){
       ct.add( RunNumber, cutname+"CosThWjj"+jetmodeName[jetmodeLoop], thetotalweight ) ;
     }
     
     // w-jets eta
     //    if ( !useFJ  ) {
     //      if (  (fabs(h1->jet_eta->at(h1->WjetsIndex1))>2.5 ) || 
     // 	   (fabs(h1->jet_eta->at(h1->WjetsIndex2))>2.5 ) )  continue;
     //    }
     //     ct.add( RunNumber, cutname+"JETETA", thetotalweight ) ;

   
     //if (useFJ) {   if ( diwjets.Pt()< 60. )              continue; }
     //else       {   if ( wjet1.Pt()<60.&&wjet2.Pt()<60. ) continue; }
     
     //ct.add( RunNumber, cutname+"JET0PT", thetotalweight ) ;
     
     
     ///histfiller -> FillHistgrams( channelName , prodmode+"_LeadJetPt" , RunNumber, h1, thetotalweight ); 
     
     
     // two w-jets delta phi
     //    if (!useFJ){
     //      if (  !(fabs(wjet1.DeltaPhi( wjet2 )) < 2.5 ) ) continue;
     //    }
     //ct.add( RunNumber, cutname+"DPHIJJ", thetotalweight ) ;
     
     //    // lepton neutrino delta phi
     //    if ( !(fabs(lepton.DeltaPhi( neutrino )) <2.5)  ) continue;
     //ct.add( RunNumber, cutname+"DPHILNU", thetotalweight ) ;
     
     //    // w-jets lepton delta phi
     //    if (useFJ){
     //      if ( fabs(diwjets.DeltaPhi( lepton )) < 1. ) continue;
     //    }
     //    else { 
     //      if (   (fabs(wjet1.DeltaPhi( lepton )) < 1.) ||  (fabs(wjet2.DeltaPhi( lepton )) < 1.)  ) continue;
     //    }
     //ct.add( RunNumber, cutname+"DPHILJ", thetotalweight ) ;
     
     //    // w-jets neutrino delta phi
     //    if (useFJ){
     //      if ( fabs(diwjets.DeltaPhi( neutrino )) < 1. ) continue;
     //    }
     //    else{
     //      if (   (fabs(wjet1.DeltaPhi( neutrino )) < 1.) || (fabs(wjet2.DeltaPhi( neutrino )) < 1.)  ) continue;
     //    }
     //ct.add( RunNumber, cutname+"DPHINUJ", thetotalweight ) ;

     
     /*
     // bjets veto
     // Loop through all jets, check overlap if useFJ
     bool btagged = false;
     //cout<<"Start btagging... "<<endl;
     for(int ijet=0;ijet<h1->jet_n;ijet++){
     
     bool isWjet=(ijet==h1->WjetsIndex1 || ijet==h1->WjetsIndex2) ? true : false ; 
     if (useFJ) isWjet=false;
     ///the following part is for non-Wjets for which isbtag is true. if the jet is a W-jet or isbtag is false then do nothing and go to point 1
     ///If useFJ, then check if the non-Wjet (with isbtag true) overlaps with the fatJet. If it does then event is not btagged, if no overlap or !useFJ the event is btagged
     
     if( h1->jet_isbtag->at(ijet) && (!isWjet) ){
     
     TLorentzVector thisjet;
     thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
     h1->jet_eta->at(ijet),
     h1->jet_phi->at(ijet),
     h1->jet_E  ->at(ijet)/1000. ) ;
     //--- Check overlap with FJ
     if(useFJ && thisjet.DeltaR(diwjets) < 0.4 ){//event is not btagged if b-jet overlaps with fat jet within R=0.4
     btagged = false;
     }else{
     btagged = true;
       }  
       }      
       }
       
       //cout<<"Point 1 : btagged= "<<btagged<<endl;
       ///if !useFJ and both W-jets have isbtag true then event is btagged. If only one of the W-jets has isbtag true then btagged status remains unchanged, i.e. event is btagged only if it already is from non-Wjets consideration . 
       
       if (  !useFJ  ) {
       if ( h1->jet_isbtag->at(h1->WjetsIndex1) && h1->jet_isbtag->at(h1->WjetsIndex2) ) btagged = true;//event is btagged if for both W-jets isbtag is true
       
       }
       //cout<<"Point 2 : btagged= "<<btagged<<endl;
       */

     ////!!!! BE CAREFUL about histfiller naming convention. The region (part after prodmode) should start with '_' and should not contain multiple parts separated by '_'
     /////The exception is Control regions (e.g., CR_Top, CR_Wjj). In that case it should not contain more than two parts separated by '_'
     //// Not following this convention messes up QCD SF. The way SFs are read right now, CR_Top and CR_Top_fat will get the same SF.
     //// If you are not creating SFs for the regions (e.g. _PREBTAG_FJ) it will be harmless, still it should be avoided.
     
     if(useFJ){
       
       //histfiller -> FillHistgrams( channelName , prodmode+"_PREBTAGFJ" , RunNumber, h1, thetotalweight); 
     }
     else{
       //histfiller -> FillHistgrams( channelName , prodmode+"_PREBTAGR" , RunNumber, h1, thetotalweight);
     }
     

     //normal b-tagging code -BL     
     
     //-----New btag for new slim ntuples without jet_isbtag branch. 7/20/14
     // Calculate b-tag
     bool passBtagVeto = true;
     bool btagged_60 = false;  //btag efficiency 60%
     double thebtagweight = 1;
     ///int nAdditionalBJets = 0;
     int nBJetsOverlapWfatjet = 0;

     
     for(int ijet=0;ijet<h1->jet_n;ijet++){
       
       bool _isWjet = (ijet==h1->WjetsIndex1 || ijet==h1->WjetsIndex2) ? true : false ; /// a Wjet and regular selection
       if (useFJ) _isWjet = false;
       
       
       TLorentzVector thisjet;  ///this tlv is needed to check if the jet overlaps with wjetfat
       thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
			     h1->jet_eta->at(ijet),
			     h1->jet_phi->at(ijet),
			     h1->jet_E  ->at(ijet)/1000. ) ;

       //Non-W jets (resolved selection) or jets not overlapping with the wfatjet (fatjet selection)   
       if (  (fabs(h1->jet_eta->at(ijet)) <2.5) &&  ///central
	     (!_isWjet) &&                          ///Not a regular Wjet
	     ((!useFJ) || fabs(thisjet.DeltaR(diwjets))>0.4  ) /// if using fatjet selection, jet >0.4 far from a w-fatjet. 
	     )
	 {

	   if (h1->jet_MV1->at(ijet) > constants::mv1SRCut) {
	     passBtagVeto = false;
	     ///nAdditionalBJets++;
	     thebtagweight *= h1->jet_BtagWeight->at(ijet);
	   } 
	   else{
	     thebtagweight *= h1->jet_VetoBtagWeight->at(ijet);
	   }

	 }
       
       /*
      ///added by auzaman 1/15/15 &&&&
       //jets overlapping with the wfatjet (fatjet selection)
       if (  (fabs(h1->jet_eta->at(ijet)) <2.5) &&  ///central
	     ((useFJ) && fabs(thisjet.DeltaR(diwjets))<0.4  ) /// using fatjet selection and considering jets within 0.4 of a w-fatjet
	     )
	 {
	   
	   if (h1->jet_MV1->at(ijet) > constants::mv1SRCut) {
	     
	     nBJetsOverlapWfatjet++ ;
	     thebtagweight *= h1->jet_BtagWeight->at(ijet);
	   } 
	   else{
	     thebtagweight *= h1->jet_VetoBtagWeight->at(ijet);
	   }
	   
	 }///added ends
       */
     }
     ///added by auzaman 1/15/15
     //if(useFJ && nBJetsOverlapWfatjet >=2) passBtagVeto = false; ///if there are two isbtag jets overlapping with wfatjet, event is btagged
     //if(useFJ && nBJetsOverlapWfatjet >=1) passBtagVeto = false; ///if there is any isbtag jet overlapping with wfatjet, event is btagged &&&&
     
     //W jet
     bool wjet1_isbtagLoose(false); 
     bool wjet2_isbtagLoose(false); 
     
     if (  !useFJ  ) {
       
       if ( fabs(h1->jet_eta->at(h1->WjetsIndex1)) <2.5 ){
	  
	 if( h1->jet_MV1->at(h1->WjetsIndex1) > constants::mv1SRCut ){
	   wjet1_isbtagLoose = true;
	   thebtagweight *= h1->jet_BtagWeight->at(h1->WjetsIndex1);
	 }
	 else{
	   thebtagweight *= h1->jet_VetoBtagWeight->at(h1->WjetsIndex1);   
	 }
	 
       }
       
       if ( fabs(h1->jet_eta->at(h1->WjetsIndex2)) <2.5 ){
	  
	 if( h1->jet_MV1->at(h1->WjetsIndex2) > constants::mv1SRCut ){
	   wjet2_isbtagLoose = true;
	   thebtagweight *= h1->jet_BtagWeight->at(h1->WjetsIndex2);
	 }
	 else{
	   thebtagweight *= h1->jet_VetoBtagWeight->at(h1->WjetsIndex2);   
	 }
       
       }
       
       
       if ( wjet1_isbtagLoose && wjet2_isbtagLoose ) passBtagVeto = false;
       
     }
     if (IsData) thebtagweight = 1.;
     // end b-tag
     
     
     if(!doZCR){
       if(passBtagVeto){
	 ct.add( RunNumber, cutname+"NOTBTAG"+jetmodeName[jetmodeLoop], thetotalweight*thebtagweight ) ;
       }
     }
     
     
     
     bool btaggedTop=false;  //does event pass the b-tag requirements for the Top CR?
     
     if(!passBtagVeto){
       
       // Calculate b-tag
       double topbtagweight = 1;
       int nBJetsOverlapWfatjet = 0;
       
       for(int ijet=0;ijet<h1->jet_n;ijet++){
	 
	 bool _isWjet = (ijet==h1->WjetsIndex1 || ijet==h1->WjetsIndex2) ? true : false ; /// a Wjet and regular selection
	 if (useFJ) _isWjet = false;
	 
	 
	 TLorentzVector thisjet;  ///this tlv is needed to check if the jet overlaps with wjetfat
	 thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
			       h1->jet_eta->at(ijet),
			       h1->jet_phi->at(ijet),
			       h1->jet_E  ->at(ijet)/1000. ) ;
	 
	 
	 //Non-W jets (resolved selection) or jets not overlapping with the wfatjet (fatjet selection)
	 if (  (fabs(h1->jet_eta->at(ijet)) <2.5) &&  ///central
	       (!_isWjet) &&                          ///Not a regular Wjet
	       ((!useFJ) || fabs(thisjet.DeltaR(diwjets))>0.4  ) /// if using fatjet selection, jet >0.4 far from a w-fatjet.
	       )
	   {

	     if (h1->jet_MV1->at(ijet) > constants::mv1TopCRCut) {
	       btaggedTop = true;
	       ///nAdditionalBJets++;
	       //topbtagweight *= h1->jet_BtagWeight->at(ijet);
	       topbtagweight *= h1->jet_BtagWeight_60->at(ijet); //&&&&
	     }
	     else{
	       //topbtagweight *= h1->jet_VetoBtagWeight->at(ijet);
	       topbtagweight *= h1->jet_VetoBtagWeight_60->at(ijet);
	     }

	   }



       }
       

       //W jet
       bool wjet1_isbtagTight(false);
       bool wjet2_isbtagTight(false);

       if (  !useFJ  ) {

	 if ( fabs(h1->jet_eta->at(h1->WjetsIndex1)) <2.5 ){

	   if( h1->jet_MV1->at(h1->WjetsIndex1) > constants::mv1TopCRCut ){
	     wjet1_isbtagTight = true;
	     //topbtagweight *= h1->jet_BtagWeight->at(h1->WjetsIndex1);
	     topbtagweight *= h1->jet_BtagWeight_60->at(h1->WjetsIndex1); //&&&&
	   }
	   else{
	     //topbtagweight *= h1->jet_VetoBtagWeight->at(h1->WjetsIndex1);
	     topbtagweight *= h1->jet_VetoBtagWeight_60->at(h1->WjetsIndex1);
	   }

	 }

	 if ( fabs(h1->jet_eta->at(h1->WjetsIndex2)) <2.5 ){

	   if( h1->jet_MV1->at(h1->WjetsIndex2) > constants::mv1TopCRCut ){
	     wjet2_isbtagTight = true;
	     //topbtagweight *= h1->jet_BtagWeight->at(h1->WjetsIndex2);
	     topbtagweight *= h1->jet_BtagWeight_60->at(h1->WjetsIndex2);//&&&&
	   }
	   else{
	     //topbtagweight *= h1->jet_VetoBtagWeight->at(h1->WjetsIndex2);
	     topbtagweight *= h1->jet_VetoBtagWeight_60->at(h1->WjetsIndex2);//&&&&
	   }

	 }
	 	 
	 if ( wjet1_isbtagTight && wjet2_isbtagTight ) btaggedTop = true;
	 
       }
       
       if (IsData) topbtagweight = 1.;
       
       
       if(btaggedTop){
	 thebtagweight = topbtagweight;  //Eventually should use b-tag weights for TopCRMv1Cut, not SRMv1Cut! Need to add to ntuples!-- BL	
       }		
       
     } //end if(!passBtagVeto)
     ///end b-tagging for top-quark CR
          
     
     
     // w-jets mass
     float twoWjetsMass(-999.);
     if (useFJ) {
       twoWjetsMass = diwjets.M();
     }
     else{
       TLorentzVector twoWjets = wjet1 + wjet2; 
       twoWjetsMass = twoWjets.M();
     }
     
     
     //if ( RunNumber == 117050 ){
     //float ttbar_pt=;
     //float top_pt=;
     //thetotalweight *= GetTTbarPtWeight_Powheg(ttbar_pt) * GetSequentialTopPtWeight_Powheg(top_pt);//Powheg-Pythia ttbar
     //}
     
     /////-----***************************************
     h1-> topRWEventWeight=1.;
     h1-> wjetsRWEventWeight=1.;
     //cout<<"thetotalweight= "<<thetotalweight<<endl;
     //cout<<"topRWEventWeight= "<<h1->topRWEventWeight<<endl;
     
     //if ( RunNumber == 105200){///MC@NLO ttbar sample
     //if ( RunNumber == 117050){///Powheg-Pythia ttbar sample
     if ( RunNumber == 999999){///don't do ttbar reweighting
       assert(0);  //we're not planning on reweighting!

       //cout<<"Hello blah blah blah \n"<<endl;
       int rw_index=-1;
       
       if(val_dEtaTaggedJets*10>=80)rw_index =79; //overflow bin, not flexible
       else if(val_dEtaTaggedJets*10<0)rw_index =0; //underflow bin, should be empty
       else rw_index =val_dEtaTaggedJets*10; //it is converted to integer, this part is hard coded, need to be changed if dEtaTaggedJets binning is changed
       //cout<<val_dEtaTaggedJets<<endl;
       //cout<<rw_index<<endl; ///rw_index=bin_number -1 =reweightFactor array index
       h1->topRWEventWeight *=reweightFactor[rw_index];
       //cout<<"reweightFactor["<<rw_index<<"]="<<reweightFactor[rw_index]<<endl;
       
       thetotalweight *= reweightFactor[rw_index] ;
       //cout<<"after reweightFactor, thetotalweight= "<<thetotalweight<<"\n----"<<endl;
       
     }
     //cout<<"after reweightFactor, thetotalweight= "<<thetotalweight<<"\n----"<<endl;

     // if (   ( RunNumber >= 147774 && RunNumber <= 147776 )
     // 	|| ( RunNumber >= 167761 && RunNumber <= 167796 )
     // 	|| ( RunNumber >= 180534 && RunNumber <= 180542 )){///W+jets sample
     if ( RunNumber == 999999){///don't do W+jets reweighting
       assert(0);  //we're not planning on reweighting! 
       //cout<<"thetotalweight= "<<thetotalweight<<endl;
       
       //cout<<val_dEtaTaggedJets<<endl;
       int rw_index2=-1;
       if(val_dEtaTaggedJets*10>=80)rw_index2 =79; //overflow bin, not flexible
       else if(val_dEtaTaggedJets*10<0)rw_index2 =0; //underflow bin, should be empty
       else rw_index2 =val_dEtaTaggedJets*10; //it is converted to integer, this part is hard coded, need to be changed if dEtaTaggedJets binning is changed
       //cout<<val_dEtaTaggedJets<<endl;
       //cout<<rw_index<<endl; ///rw_index=bin_number -1 =reweightFactor array index
       h1->wjetsRWEventWeight *=reweightFactor2[rw_index2];
       //cout<<"reweightFactor["<<rw_index<<"]="<<reweightFactor[rw_index]<<endl;
       thetotalweight *= reweightFactor2[rw_index2] ;///
       //cout<<"after reweightFactor, thetotalweight= "<<thetotalweight<<"\n----"<<endl;
       
     }
     //cout<<"after reweightFactor, thetotalweight= "<<thetotalweight<<"\n----"<<endl;
     
     //final weight, after all reweighting and btagging weights.
     thetotalweight *= thebtagweight; 
     if(jetmodeLoop==0){
       thetotalweightR = thetotalweight;
     }
     else{
       thetotalweightF = thetotalweight;
     }
     
     //----*********************************************
     
     //cout<<"after reweightFactor, thetotalweight= "<<thetotalweight<<"\n----"<<endl;
     h1-> EventWeight=thetotalweight;  //the h1->EventWeight doesn't seem to be used anywhere, other than to fill a dedicated EventWeight histogram
     
     if(doZCR){

       if(!useFJ){
	 
	 if( !passBtagVeto) continue;
	 
	 if ( twoWjetsMass > constants::mjjResolveLoCut && twoWjetsMass < constants::mjjResolveHiCut )
	   {
	     
	     //  histfiller -> FillHistgrams( channelName , prodmode+"_ZCR" , RunNumber, h1, thetotalweight );
	     //	   ct.add( RunNumber, cutname+"ZCR", thetotalweight ) ;
	     
	   }
	 
	 
       }
       else{
	 
	 if( !passBtagVeto) continue;
	 ////!!!! BE CAREFUL about histfiller naming convention. The region (part after prodmode) should start with '_' and should not contain multiple parts separated by '_'
	 /////The exception is Control regions (e.g., CR_Top, CR_Wjj). In that case it should not contain more than two parts separated by '_'
	 //// Not following this convention messes up QCD SF. The way SFs are read right now, CR_Top and CR_Top_fat will get the same SF.
	 //// If you are not creating SFs for the regions (e.g. _PREBTAG_FJ) it will be harmless, still it should be avoided.
	 
	 if ( twoWjetsMass > fatjet_minm && twoWjetsMass < fatjet_maxm )  {
	   //WARNING: THIS CONTROL REGION OVERLAPS WITH ZCR.
	   //   histfiller -> FillHistgrams( channelName , prodmode+"_ZCRFJ" , RunNumber, h1, thetotalweight );
	   //	   ct.add( RunNumber, cutname+"ZCR_FJ", thetotalweight ) ;
	   
	 }
       
       }
       

     }//end if(doZCR)
     else{

     
     if(!useFJ){
       
       if ( btaggedTop && twoWjetsMass > constants::mjjResolveLoCut && twoWjetsMass < constants::mjjResolveHiCut ) { ///Top_CR

	 pass_CR_Top_TotalResolved=true;
	
	 histfiller -> FillHistgrams( channelName , prodmode+"_CR_Top" , RunNumber, h1, thetotalweight );

	 
       }
       
       
       if( !passBtagVeto ) continue;
       
       if ( twoWjetsMass > 36. && twoWjetsMass < 5000. ) {///originally upper limit was 126
	 if ( twoWjetsMass > constants::mjjResolveLoCut && twoWjetsMass < constants::mjjResolveHiCut ) 
	   {


	     passTotalResolved=true; ///signal region containing all events passing resolved jet selection. Some of these events may also pass fatjet selection
	     
	     histfiller -> FillHistgrams( channelName , prodmode+"_SR" , RunNumber, h1, thetotalweight );
	     ct.add( RunNumber, cutname+"MJJResolve", thetotalweight ) ;
	     /*
	     if (val_mjjTagged > 200 && val_mjjTagged < 400 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRMJJ200" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 400 && val_mjjTagged < 600 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRMJJ400" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 600 && val_mjjTagged < 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRMJJ600" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRMJJ800" , RunNumber, h1, thetotalweight );}
	     */
	     
	   }else
	   {

	     pass_CR_Wjj_TotalResolved=true;
	     histfiller -> FillHistgrams( channelName , prodmode+"_CR_Wjj" , RunNumber, h1, thetotalweight );
	     /*
	     if (val_mjjTagged > 200 && val_mjjTagged < 400 ){histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjMJJ200" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 400 && val_mjjTagged < 600 ){histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjMJJ400" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 600 && val_mjjTagged < 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjMJJ600" , RunNumber, h1, thetotalweight );}
	     if (val_mjjTagged > 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjMJJ800" , RunNumber, h1, thetotalweight );}
	     */
	   }
       }
       
     }  //end if(!useFJ)
     else{
       
       if ( btaggedTop && twoWjetsMass > fatjet_minm && twoWjetsMass < fatjet_maxm ) { ///Top_CR
	 
	 pass_CR_Top_TotalFat=true; ///Top control region containing all events passing fatjet selection. Some of these events may also pass resolved selection
	 
	 histfiller -> FillHistgrams( channelName , prodmode+"_CR_TopFJ" , RunNumber, h1, thetotalweight );
       }
       
       
       if( !passBtagVeto) continue;
       
       //histfiller -> FillHistgrams( channelName , prodmode+"_BTAGFJ" , RunNumber, h1, thetotalweight ); 
       
       
       if ( twoWjetsMass > fatjet_minm && twoWjetsMass < fatjet_maxm ) 
	 {
	   
	   passTotalFat=true;  ///signal region containing all events passing fatjet selection. Some of these events may also pass resolved selection
	   
	   histfiller -> FillHistgrams( channelName , prodmode+"_SRFJ" , RunNumber, h1, thetotalweight );
	   ct.add( RunNumber, cutname+"MJJFat", thetotalweight ) ;
	   
	 }else
	 {
	   pass_CR_Wjj_TotalFat=true; ///W+jets control region containing all events passing fatjet selection. Some of these events may also pass resolved selection
	   histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjFJ" , RunNumber, h1, thetotalweight ); 
	 }
       
       
       
     }// end if(useFJ)

     }//end if(!doZCR)
     
     

   }//end loop over jet mode(resolved, fat)

   
   if(passTotalResolved || pass_CR_Top_TotalResolved || pass_CR_Wjj_TotalResolved){

     h1->WjetsIndex1 = WjetsIndex.first ;
     h1->WjetsIndex2 = WjetsIndex.second ;

     h1->vbfjetsIndex1 = vbfjetsIndex.first ;
     h1->vbfjetsIndex2 = vbfjetsIndex.second ;

     if(passTotalResolved){
       if(passTotalFat){
	 //histfiller -> FillHistgrams( channelName , prodmode+"_SRbothR" , RunNumber, h1, thetotalweightR );
       }
       else{
	 //histfiller -> FillHistgrams( channelName , prodmode+"_SRresolveOnly" , RunNumber, h1, thetotalweightR ); ///signal region with events passing resolved jet selection and NOT passing fat selection
       }

       /*
       if(!passTotalFat){
         histfiller -> FillHistgrams( channelName , prodmode+"_SRresolveFinal" , RunNumber, h1, thetotalweightR );
       }
       else{
	 TLorentzVector diwjets;
	 diwjets.SetPtEtaPhiE(  m_fatjets.at(WjetsFJIndex.first).Pt(),
				m_fatjets.at(WjetsFJIndex.first).Eta(),
				m_fatjets.at(WjetsFJIndex.first).Phi(),
				m_fatjets.at(WjetsFJIndex.first).E() );
	 
         double ptFatjet = diwjets.Pt();
	 if(ptFatjet<350){
	   histfiller -> FillHistgrams( channelName , prodmode+"_SRresolveFinal" , RunNumber, h1, thetotalweightR );
	 }

       }
       */
       
     }

     if(pass_CR_Top_TotalResolved){
       if(pass_CR_Top_TotalFat){
	 //histfiller -> FillHistgrams( channelName , prodmode+"_CR_TopbothR" , RunNumber, h1, thetotalweightR ); 
       }
       else{
	 //	 histfiller -> FillHistgrams( channelName , prodmode+"_CR_TopresolveOnly" , RunNumber, h1, thetotalweightR ); ///Top control region with events passing resolved jet selection and NOT passing fat selection
       }
     }

     if(pass_CR_Wjj_TotalResolved){
       if(pass_CR_Wjj_TotalFat){
         //histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjbothR" , RunNumber, h1, thetotalweightR );
       }
       else{
         //      histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjresolveOnly" , RunNumber, h1, thetotalweightR );
	 ///Wjj control region with events passing resolved jet selection and NOT passing fat selection
       }
     }



   }

   if(passTotalFat || pass_CR_Top_TotalFat || pass_CR_Wjj_TotalFat ){
     
     h1->WjetsIndex1 = WjetsFJIndex.first ;
     h1->WjetsIndex2 = WjetsFJIndex.second ;
     
     h1->vbfjetsIndex1 = vbfjetsFJIndex.first ;
     h1->vbfjetsIndex2 = vbfjetsFJIndex.second ;
     
     if(passTotalFat){
       if(passTotalResolved){
	 //histfiller -> FillHistgrams( channelName , prodmode+"_SRbothF" , RunNumber, h1, thetotalweightF );
       }
       else{
	 histfiller -> FillHistgrams( channelName , prodmode+"_SRfatOnly" , RunNumber, h1, thetotalweightF ); ///signal region with events passing fatjet selection and NOT passing resolved selection
	 ct.add( RunNumber, cutname+"OLRemovalFat", thetotalweightF ) ;

	 /*
	 if (val_mjjTagged > 200 && val_mjjTagged < 400 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRfatOnlyMJJ200" , RunNumber, h1, thetotalweightF );}
	 if (val_mjjTagged > 400 && val_mjjTagged < 600 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRfatOnlyMJJ400" , RunNumber, h1, thetotalweightF );}
	 if (val_mjjTagged > 600 && val_mjjTagged < 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRfatOnlyMJJ600" , RunNumber, h1, thetotalweightF );}
	 if (val_mjjTagged > 800 ){histfiller -> FillHistgrams( channelName , prodmode+"_SRfatOnlyMJJ800" , RunNumber, h1, thetotalweightF );}
	 */
       }

       /*
       if(!passTotalResolved){
	 histfiller -> FillHistgrams( channelName , prodmode+"_SRfatFinal" , RunNumber, h1, thetotalweightF );
       }
       else{
         TLorentzVector diwjets;
         diwjets.SetPtEtaPhiE(  m_fatjets.at(WjetsFJIndex.first).Pt(),
                                m_fatjets.at(WjetsFJIndex.first).Eta(),
                                m_fatjets.at(WjetsFJIndex.first).Phi(),
                                m_fatjets.at(WjetsFJIndex.first).E() );

         double ptFatjet = diwjets.Pt();
         if(ptFatjet>350){
	   histfiller -> FillHistgrams( channelName , prodmode+"_SRfatFinal" , RunNumber, h1, thetotalweightF );
         }
	 
       }
       */
       
     }
     
     if(pass_CR_Top_TotalFat){
       if(pass_CR_Top_TotalResolved){
	 //histfiller -> FillHistgrams( channelName , prodmode+"_CR_TopbothF" , RunNumber, h1, thetotalweightF );
       }
       else{
	 histfiller -> FillHistgrams( channelName , prodmode+"_CR_TopfatOnly" , RunNumber, h1, thetotalweightF ); ///Top control region with events passing fatjet selection and NOT passing resolved selection
       }
     }
     
     if(pass_CR_Wjj_TotalFat){
       if(pass_CR_Wjj_TotalResolved){
         //histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjbothF" , RunNumber, h1, thetotalweightF );
       }
       else{
	 histfiller -> FillHistgrams( channelName , prodmode+"_CR_WjjfatOnly" , RunNumber, h1, thetotalweightF ); ///Wjj control region with events passing fatjet selection and NOT passing resolved selection
       }
     }
     
   }


  } // End Loop Events

  cout<<"Finished looping over events"<<endl;
  
  
  ct.SaveToFile(foutput);  ///foutput is hwwlvqq.root
  histfiller->CloseAsciiFiles();
  
  cout<<"Done saving 'ct' to file"<<endl;

  if ( runNames.size() < 1 ) {    return 0 ;   }

  foutput->cd("CutFlow");
  
  gDirectory->pwd() ;

  gDirectory->ls();

  int firstRun = runNames[0] ; 
  cout << " First Run " << firstRun << endl;
  for ( int itype=0; itype< nDSType; itype++ ){
    TString newname = Form( "%s_CutFlow",  DScategory[itype].c_str() );
    cout << "new name " << newname << endl;
    TH1F *tmp = (TH1F*) gDirectory -> Get(Form("%d_CutFlow",firstRun )) -> Clone(newname) ; 
    tmp -> SetTitle(newname) ;
    tmp -> Reset();
  }
  

  
  
  for ( unsigned int i=0; i<runNames.size() ; i++){
    int runNumber = runNames[i] ;
    cout << "Run Number " << runNumber << endl;
    TH1F *hcutflow = (TH1F*)gDirectory -> Get( Form( "%d_CutFlow", runNumber )   );
    if (!hcutflow) continue ;
    cout << "Found run names " << hcutflow->GetName() << endl;
    if ( DatasetTypeMap.find(runNumber) == DatasetTypeMap.end() ) continue ;
    string typeMapped = DatasetTypeMap[runNumber] ; 
    cout << "Run " << hcutflow->GetName() << " mapped type " << typeMapped << endl;
    if ( typeMapped == "" ) continue ;
    TString newname1 = Form( "%s_CutFlow", typeMapped.c_str() ) ;
    cout << "New name " << newname1 << endl;
    TH1F *tmp1 = (TH1F*) gDirectory -> Get( newname1 );
    tmp1 -> Add( hcutflow  );
    cout<< newname1 <<" ends"<<endl;
  }
  cout<<"Going to write to foutput ..."<<endl;
 

  foutput->Write();
  foutput->Close();

  //ct.Print();

  cout<<"\n output written to file "<<endl; 
  
#if PrintOneRunCutFlow

  cout << "\n >> Higgs ggF CPS sample at mH=400 GeV \n" << endl;

  const int nfla = 2;  std::string flaArr[nfla] = { "e", "m"} ;
  
  for ( int iflavor=0 ; iflavor<nfla ; iflavor++){
    for ( int imode=0; imode<nmode; imode++ ){
      cout << " \n " << endl;
      for (int icut=0; icut<nCuts ; icut++) {
	std::string tname_m = flaArr[iflavor] + "m_" + modeArr[imode] + "_" + cuts[icut];
        std::string tname_p = flaArr[iflavor] + "p_" + modeArr[imode] + "_" + cuts[icut];
	std::string tname   = flaArr[iflavor] + "_" + modeArr[imode] + "_" + cuts[icut];
	
        float value = ct.getCutValue(167930, tname_m) + ct.getCutValue(167930, tname_p);

	cout << std::setw(20) << std::left << tname << " : " <<  value  << endl;
      }
    }
  }

#endif


  timer.Stop();
  std::cout << " \n\n CPU time = " << timer.CpuTime() << "s real = " << timer.RealTime() << " s " << std::endl;


  
} // End Main Function






