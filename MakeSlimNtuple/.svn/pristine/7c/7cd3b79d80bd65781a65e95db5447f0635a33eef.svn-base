// $Id$
/* @authoer Haifeng Li 
 * @date    May 30, 2013
 * @breif   Slimming and skimming tools for Higgs->WW->lvqq ntuple
 * Modified by:
 *   Aungshuman Zaman
 *   Brian Lindquist
 */

// ROOT
#include "TFile.h"
#include "TChain.h"
#include "TROOT.h"
#include "TVector3.h"
#include "TMath.h"
#include "TKey.h"
#include "TTree.h"
#include <TStopwatch.h>

// Cpp
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include <assert.h>


// Local
#include "foo.C"
#include "AnaObject.h"
#include "TCutClass.h"


//using namespace std;
bool DEBUG= 0;


void SortJets(vector<Jet>& jetlist){ 
  //Bubble-sort
  
  int nSwaps;
  for( unsigned rjet=0; rjet< jetlist.size(); rjet++){
    nSwaps=0;
    for( unsigned sjet=0; sjet< jetlist.size() - 1 - rjet; sjet++){

      if(jetlist[sjet].Pt() < jetlist[sjet+1].Pt() ){
	std::swap(jetlist[sjet], jetlist[sjet+1]);
	nSwaps++;
	//cout<<"Did a swap!"<<endl;
      }

    }
    if(nSwaps==0) break;
  }

}


//void SkimSlimLvqqNtuple( bool doMC=1, std::string inputFileList = "input.txt"  )

void SkimSlimLvqqNtuple( bool doMC=1, std::string dsId = "110101", std::string syst = "Nominal"  )
{

  gROOT->ProcessLine("#include <vector>");

  TStopwatch timer;
  timer.Start();
  

  //std::string caf_version = "4.1";
  
  ////<<<<<<<< input >>>>>>>>>>>>
  //std::string inputFileList = "input."+dsId+"."+syst+".txt";
  //std::string inputFileList = "input."+caf_version+"_sbahead/input."+dsId+"."+syst+".txt"; //HARD CODED &&&&
  //std::string inputFileList = "input."+caf_version+"/input."+dsId+"."+syst+".txt"; //HARD CODED &&&&
  //std::string inputFileList = "input.4.1_sbahead/input."+dsId+"."+syst+".txt";
  //std::string inputFileList = "input.4.2/input."+dsId+"."+syst+".txt";
  //std::string inputFileList = "input.3.3/input."+dsId+"."+syst+".txt";
  //std::string inputFileList = "input.3.25_sbahead/input.183735.Nominal.txt";
  //std::string inputFileList = "input.3.25/input."+dsId+"."+syst+".txt";
  //std::string inputFileList = "input.3.3_sbahead/input.183735.JMSUp.txt";

  
  std::string treeName = "HWWTree_lvqq";
  ////<<<<<<<< output >>>>>>>>>>>>

  //std::string outputFileName = dsId+".lvqqMiniNtuple.root."+syst;
  //std::string outputFileName = "/export/scratch1/azaman/lvqqNtuple/VBS_"+caf_version+"_looseBadMuon1.1/"+dsId+".lvqqMiniNtuple.root."+syst; //HARD CODED
  //std::string outputFileName = "/export/scratch1/azaman/lvqqNtuple/VBS_4.2_looseBadLep4/"+dsId+".lvqqMiniNtuple.root."+syst; //HARD CODED
  //std::string outputFileName = "/export/scratch1/azaman/lvqqNtuple/VBS_4.1_looseBadMuon3/"+dsId+".lvqqMiniNtuple.root."+syst; //HARD CODED
  //std::string outputFileName = "/export/scratch1/azaman/lvqqNtuple/VBS_4.2_looseBadMuon1.1/"+dsId+".lvqqMiniNtuple.root."+syst; //HARD CODED
  //std::string outputFileName = "/export/scratch1/azaman/lvqqNtuple/VBS_4.1_looseBadLep4/"+dsId+".lvqqMiniNtuple.root."+syst; //HARD CODED
  //std::string outputFileName = "root://sbahead.physics.sunysb.edu//atlas/local/azaman/lvqqNtuple/VBS_3.29/"+dsId+".lvqqMiniNtuple.root."+syst;//do not have permission
  //std::string outputFileName = "/sbahead/atlas/local/azaman/lvqqNtuple/VBS_3.29/"+dsId+".lvqqMiniNtuple.root."+syst;//do not have permission
  

  
  //<<< Hard coded input and output names >>>> &&&&
  //std::string inputFileList = "input.periodL.physics_Muons_VBS_3.25_sbahead.txt";
  //std::string outputFileName = "periodL.physics_Muons_VBS_3.25.lvqqMiniNtuple.root";
  std::string inputFileList = "input.txt";
  //std::string inputFileList = "input.117050.Nominal.test.txt";
  std::string outputFileName = "lvqqMiniNtuple.root";
  
  std::cout<<inputFileList<<endl;
  std::cout<<"######################"<<outputFileName<<"########################"<<endl;

  std::cout << "INFO : Input file list is : " << inputFileList << std::endl;
  std::cout << "INFO : doMC : " <<  doMC << std::endl;

  bool cutOnNjets=true;

  // open input
  std::cout << " Creating chain of trees \""<< treeName << "\"" << std::endl;
  TChain *chain = new TChain(treeName.c_str());

  std::ifstream ifs(inputFileList.c_str());//ifs is the content of inputFileList
  char buf[1000000];
  ifs.get( buf, 1000000 );//'get' extracts character from the stream ifs and saves it to buf, max size 1000000
  std::string str(buf);

  ////////////This is for slimming local small files; used for testing
 
  //str="HWWSkimmedNTUP_lvqq_new.root";
  //str="/export/scratch1/azaman/user.auzaman.145161.Sherpa_CT10_eegammaPt10.VBS_2.42_CAF_0.10_Nominal_HWWSkimmedNTUP_lvqq.root.3338248/user.auzaman.4157061._000035.HWWSkimmedNTUP_lvqq.root";
	   //=======
  //str="/export/scratch1/azaman/user.auzaman.185761.WhizardPythia8_AU2_CT10_ZVsemileptonic_km_a4_00_a5_m01.AF2..0_CAF_0.10_Nominal_HWWSkimmedNTUP_lvqq.root.111788/user.auzaman.002056._000002.HWWSkimmedNTUP_lvqq.root";
  //  str="/export/scratch1/azaman/lvqqNtuple/HWWSkimmedNTUP_lvqq_WV_03_0.root"; //OLD CAF v10 version from Aungshuman
  
  //  str="/export/home/blindqui/analysis/VBS/CAFfiles_v10/HWWlvqqCode/Run/HWWSkimmedNTUP_lvqq_107655.ZeeNp5.root.d"; //new version of CAF that I'm working on


  //  str="/export/scratch1/blindqui/VBS/DownloadSlimTuples/user.blindqui.185725.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_00_a5_m02.VBS_1.1_CAF_0.12_Nominal_HWWSkimmedNTUP_lvqq.root.12982168/user.blindqui.4558131._000003.HWWSkimmedNTUP_lvqq.root";
  

  //=======
  
  //str="/export/home/blindqui/analysis/VBS/CAFfiles_v10/HWWlvqqCode/Run/HWWSkimmedNTUP_lvqq_JetCut20.root"; //old version of CAF
  //str="/export/home/blindqui/analysis/VBS/CAFfiles_v10/HWWlvqqCode/Run/HWWSkimmedNTUP_lvqq_4np.root"; //new version of CAF that I'm working on
  
  //str="/export/scratch1/azaman/CAF/VBS_2.42_CAF_0.10_Nominal/user.auzaman.185721.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_0_a5_0.VBS_2.42_CAF_0.10_Nominal_HWWSkimmedNTUP_lvqq.root.3592153/user.auzaman.4164223._000001.HWWSkimmedNTUP_lvqq.root";
  //str="HWWSkimmedNTUP_lvqq_new.root";

  //str="/export/scratch1/azaman/CAF/new2/user.auzaman.117050.PowhegPythia_P2011C_ttbar.AF2.VBS_3.22_HWWSkimmedNTUP_lvqq.root.BaseJESDown.19121389/user.auzaman.4911122._000001.HWWSkimmedNTUP_lvqq.root.BaseJESDown";
  //str="/sbahead/atlas/local/azaman/CAF/new2/user.auzaman.117050.PowhegPythia_P2011C_ttbar.AF2.VBS_3.22_HWWSkimmedNTUP_lvqq.root.BaseJESDown.19121389/user.auzaman.4911122._000001.HWWSkimmedNTUP_lvqq.root.BaseJESDown";

  //str ="/export/home/azaman/CAFProd/HWWlvqqCode/Run/HWWSkimmedNTUP_lvqq.root.Nominal";
  
  cout<< "str ="<<str <<endl;
  /////////////////
  
  //create file list split by ','
  std::cout << " Making file list " << std::endl;
  std::vector<std::string> fileList;
  for (size_t ii=0,n; ii <= str.length(); ii=n+1) {//loop starts with 0; n is defined so that next iteration is n+1, not 1.
    n = str.find_first_of(',',ii);
    if (n == string::npos) n = str.length();
    string tmp = str.substr(ii,n-ii);//the filename string
    //cout << "file : " << tmp << endl;
    if ( tmp.find("#") == 0)continue; // comment out names by putting a # in front
    ////if ( tmp.find("HWWSkimmedNTUP_lvqq.root") == std::string::npos ) continue ;//no match
    if ( tmp.find("HWWSkimmedNTUP_lvqq") == std::string::npos ) continue ;//no match
    fileList.push_back(tmp);//filelist is the vector containing the filenames in inputFileList (input.txt)
  }

  std::cout << " Chain files together " << std::endl;
  TList *FileList = new TList(); 
  int nFiles =0;
  for (unsigned int iFile=0; iFile < fileList.size(); ++iFile) {
    string fileName = (fileList[iFile]);
    std::cout << "open " << fileName.c_str() << std::endl;
    chain->Add(fileName.c_str());
    FileList -> Add( TFile::Open(fileName.c_str() ));
    nFiles++;
  }
  
  TH1 *Count(0);
  if (nFiles >0) {
    std::cout << " Get cutflow histogram from first file" << std::endl;
    TFile *first_source = (TFile*)FileList->First();
    Count = (TH1*)first_source -> Get("Count") -> Clone("thisCount") ;
    Count->Reset();

    std::cout << " Loop over cutflow histograms in all files" << std::endl;
    TFile *nextsource = (TFile*)FileList->First();//First() and After() are TList options
    while (nextsource){
      TH1* tmpCount = (TH1*) nextsource -> Get("Count") ;
      Count->Add(tmpCount);
      std::cout << nextsource -> GetName() << " weight : " << tmpCount->GetBinContent(7) << std::endl;
      nextsource = (TFile*)FileList->After( nextsource ) ;//going to the naxt obj; analogous to i=i+1; returns 0 if obj is the last in the list
    }
  
    std::cout << "total weights " << Count->GetBinContent(7) << std::endl;
  }
  
  std::cout << "Number of Entries " << chain->GetEntries() << std::endl;
  
  TCutClass  *cutTool = new TCutClass();
  foo *h1 = new foo(chain); //this is input chain
  chain->SetBranchStatus("*",0);///* refers to all branches (wildcard), 0/1 status means branch will not/will be processed. Only activate the branches you need
  chain->SetBranchStatus("RunNumber",  1);
  chain->SetBranchStatus("EventNumber",  1);
  chain->SetBranchStatus("m_el_*",  1);
  chain->SetBranchStatus("m_mu_*",  1);
  chain->SetBranchStatus("m_jet_*", 1);
  chain->SetBranchStatus("m_mfcajet_*", 1);
  chain->SetBranchStatus("MET*",    1);
  chain->SetBranchStatus("is*",     1);
  chain->SetBranchStatus("ttbarWeight",  1) ; ///added 8/20/14
  chain->SetBranchStatus("truth_sherpa_Wpt",  1) ;
  chain->SetBranchStatus("truth_sherpa_Zpt",  1) ;
  // /*
  //chain->SetBranchStatus("leptonEtCone30",  1) ;
  //chain->SetBranchStatus("leptonPtCone30",  1) ;
  //chain->SetBranchStatus("leptonPtCone40",  1) ;
  //chain->SetBranchStatus("leptonz0sinth",  1) ;
  //chain->SetBranchStatus("leptond0sigd0",  1) ;
  //chain->SetBranchStatus("leptonPt",  1) ;
  // */
  chain->SetBranchStatus("mctruth*",  1) ;
  chain->SetBranchStatus("truthStable*",  1) ;
  chain->SetBranchStatus("mc_channel_number", 1) ;
  chain->SetBranchStatus("lepMatch*",     1) ;
  chain->SetBranchStatus("mcEventWeight",     1) ;
  chain->SetBranchStatus("pileupEventWeight*", 1);
  chain->SetBranchStatus("lepTrigSFEventWeight*",1);
  chain->SetBranchStatus("IsBad*", 1);
  chain->SetBranchStatus("lepSF*",1);
  chain->SetBranchStatus("InterferenceW_*", 1);
  chain->SetBranchStatus("MV1_*", 1);
  chain->SetBranchStatus("m_jet_flavor_weight_MV1", 1);///added 8/20/14
  chain->SetBranchStatus("m_jet_emfrac", 1);///added 10/5/14
  chain->SetBranchStatus("m_jet_jvtxf", 1);///added 10/19/14

  // create output file and tree
  std::cout << "create outputfile" << std::endl;  
  TFile *outFile = new TFile(outputFileName.c_str(), "recreate");
  TTree *outTree = new TTree("HWWlvqq_mini","HWWlvqq_mini");
  outTree->SetDirectory(outFile);
  
  ///added cutflow 12/8/14
  TH1D *cutflow = new TH1D("cutflow", "Cutflow ", 15, 0, 15);
  
  cutflow->GetXaxis()->SetBinLabel(1,"ALL");
  cutflow->GetXaxis()->SetBinLabel(2,"NJET");
  cutflow->GetXaxis()->SetBinLabel(3,"JETPT");
  cutflow->GetXaxis()->SetBinLabel(4,"FATJETPT");
  cutflow->GetXaxis()->SetBinLabel(5,"NLEP");

  UInt_t          m_RunNumber;
  UInt_t          m_EventNumber;
  UInt_t          m_mc_channel_number;
  Double_t        m_mcEventWeight;
  Double_t        m_pileupEventWeight;

  bool            m_IsBadMediumBCHDown; //&&&&
  bool            m_IsBadMediumBCHUp;
  bool            m_IsBadMediumBCH;
  bool            m_IsBadTightBCH;
  

  Float_t         m_MET    ;
  Float_t         m_MET_x  ;
  Float_t         m_MET_y  ;
  Float_t         m_MET_phi;

  Float_t         m_MET_STVF    ;
  Float_t         m_MET_x_STVF  ;
  Float_t         m_MET_y_STVF  ;
  Float_t         m_MET_phi_STVF ;

  Float_t         m_ttbarWeight;  ///added 8/20/14
  Float_t         m_truth_sherpa_Wpt;
  Float_t         m_truth_sherpa_Zpt;

  //&&&& 7/29/15
  Float_t         m_el_etcone30_0;
  Float_t         m_el_ptcone30_0;
  Float_t         m_el_z0sinth_0;
  Float_t         m_el_d0_0;
  Float_t         m_el_sigd0_0;
  Float_t         m_mu_etcone30_0;
  Float_t         m_mu_ptcone30_0;
  Float_t         m_mu_z0sinth_0;
  Float_t         m_mu_d0_0;
  Float_t         m_mu_sigd0_0;
  ///
  
  // /*
  //Float_t         m_leptonEtCone30;
  // Float_t         m_leptonPtCone30;
  // Float_t         m_leptonPtCone40;
  // Float_t         m_leptonz0sinth;
  // Float_t         m_leptond0sigd0;
  // Float_t         m_leptonPt;
  // */
  //Added 8/27/14
  //Warning:  these branches only apply to Whizard+Pythia signal.
  std::vector<int>         m_mctruth_pdgId;
  std::vector<float>       m_mctruth_pt;
  std::vector<float>       m_mctruth_eta;
  std::vector<float>       m_mctruth_phi;
  std::vector<float>       m_mctruth_m;
  std::vector<int>         m_mctruth_parent;
  Int_t          m_mctruth_Nbquarks;
  Int_t          m_mctruth_VVmode;
  Int_t          m_mctruth_lepdecay;
  Int_t          m_mctruth_haddecay;
    

  std::vector<float>       m_truthStable_el_pt;
  std::vector<float>       m_truthStable_el_eta;
  std::vector<float>       m_truthStable_el_phi;
  std::vector<float>       m_truthStable_mu_pt;
  std::vector<float>       m_truthStable_mu_eta;
  std::vector<float>       m_truthStable_mu_phi;
  std::vector<float>       m_truthStable_ph_pt;
  std::vector<float>       m_truthStable_ph_eta;
  std::vector<float>       m_truthStable_ph_phi;
  
  Float_t         m_MET_truth_nonint    ;
  Float_t         m_MET_truth_nonint_x  ;
  Float_t         m_MET_truth_nonint_y  ;
  
  Int_t           m_jet_n;
  std::vector<float>   m_jet_E;
  std::vector<float>   m_jet_pt;
  std::vector<float>   m_jet_eta;
  std::vector<float>   m_jet_phi;
  std::vector<float>   m_jet_isbtag;
  std::vector<float>   m_jet_MV1; ///added 8/20/14
  std::vector<float>   m_jet_BtagWeight;
  std::vector<float>   m_jet_VetoBtagWeight;
  ////&&&&
  std::vector<float>   m_jet_BtagWeight_60;
  std::vector<float>   m_jet_VetoBtagWeight_60;
  
  std::vector<float>   m_jet_emfrac;///added 10/5/14
  std::vector<float>   m_jet_jvtxf;///added 10/19/14

  Int_t           m_fatjet_n;
  std::vector<float>   m_fatjet_E;
  std::vector<float>   m_fatjet_pt;
  std::vector<float>   m_fatjet_eta;
  std::vector<float>   m_fatjet_phi;
  std::vector<float>   m_fatjet_m  ;
  

  Int_t           m_lep_n;
  std::vector<float>   m_lep_E;
  std::vector<float>   m_lep_pt;
  std::vector<float>   m_lep_eta;
  std::vector<float>   m_lep_phi;
  std::vector<int>     m_lep_ID;
  std::vector<int>     m_lep_isGood;
  
  std::vector<Lepton>  v_lepton; 
  std::vector<Lepton>  v_BadLepton; 
  std::vector<Jet>     v_jet; 
  std::vector<Jet>     v_fatjet; 

  outTree->Branch("RunNumber"         ,   &m_RunNumber          ) ;
  outTree->Branch("EventNumber"       ,   &m_EventNumber        ) ;
  outTree->Branch("mc_channel_number" ,   &m_mc_channel_number  ) ;
  outTree->Branch("mcEventWeight"     ,   &m_mcEventWeight      ) ;
  outTree->Branch("pileupEventWeight" ,   &m_pileupEventWeight  ) ;

  //  /*
  outTree->Branch("IsBadMediumBCH"       ,   &m_IsBadMediumBCH        ) ; //&&&&
  outTree->Branch("IsBadMediumBCHDown"       ,   &m_IsBadMediumBCHDown        ) ;
  outTree->Branch("IsBadMediumBCHUp"       ,   &m_IsBadMediumBCHUp        ) ;
  outTree->Branch("IsBadTightBCH"       ,   &m_IsBadTightBCH        ) ;
  //  */
  

  outTree->Branch("MET"               ,   &m_MET                ) ;
  outTree->Branch("MET_x"             ,   &m_MET_x              );
  outTree->Branch("MET_y"             ,   &m_MET_y              );
  outTree->Branch("MET_phi"           ,   &m_MET_phi            );
  //  outTree->Branch("MET_STVF"          ,   &m_MET_STVF                ) ;
  // outTree->Branch("MET_x_STVF"        ,   &m_MET_x_STVF              );
  // outTree->Branch("MET_y_STVF"        ,   &m_MET_y_STVF              );
  // outTree->Branch("MET_phi_STVF"      ,   &m_MET_phi_STVF            );
  outTree->Branch("ttbarWeight"       ,   &m_ttbarWeight   );  ///added 8/20/14
  outTree->Branch("truth_sherpa_Wpt"  ,   &m_truth_sherpa_Wpt   );
  outTree->Branch("truth_sherpa_Zpt"  ,   &m_truth_sherpa_Zpt   );

  outTree->Branch("el_etcone30_0"  ,   &m_el_etcone30_0   );
  outTree->Branch("el_ptcone30_0"  ,   &m_el_ptcone30_0   );
  outTree->Branch("el_z0sinth_0"  ,   &m_el_z0sinth_0   );
  outTree->Branch("el_d0_0"  ,   &m_el_d0_0   );
  outTree->Branch("el_sigd0_0"  ,   &m_el_sigd0_0   );
  outTree->Branch("mu_etcone30_0"  ,   &m_mu_etcone30_0   );
  outTree->Branch("mu_ptcone30_0"  ,   &m_mu_ptcone30_0   );
  outTree->Branch("mu_z0sinth_0"  ,   &m_mu_z0sinth_0   );
  outTree->Branch("mu_d0_0"  ,   &m_mu_d0_0   );
  outTree->Branch("mu_sigd0_0"  ,   &m_mu_sigd0_0   );
    
  
  //Added 11/29/14
  // /*
  //outTree->Branch("leptonEtCone30"  ,   &m_leptonEtCone30   );
  // outTree->Branch("leptonPtCone30"  ,   &m_leptonPtCone30   );
  // outTree->Branch("leptonPtCone40"  ,   &m_leptonPtCone40   );
  // outTree->Branch("leptonz0sinth"  ,   &m_leptonz0sinth   );
  // outTree->Branch("leptond0sigd0"  ,   &m_leptond0sigd0   );
  // outTree->Branch("leptonPt"  ,   &m_leptonPt   );
  //  */
  //Added 8/27/14   
  outTree->Branch("mctruth_pdgId"  ,   &m_mctruth_pdgId     );
  outTree->Branch("mctruth_pt"  ,   &m_mctruth_pt     );
  outTree->Branch("mctruth_eta"  ,   &m_mctruth_eta     );
  outTree->Branch("mctruth_phi"  ,   &m_mctruth_phi     );
  outTree->Branch("mctruth_m"  ,   &m_mctruth_m     );
  outTree->Branch("mctruth_parent"  ,   &m_mctruth_parent     );
  outTree->Branch("mctruth_Nbquarks"  ,   &m_mctruth_Nbquarks );
  outTree->Branch("mctruth_VVmode"  ,   &m_mctruth_VVmode );
  outTree->Branch("mctruth_lepdecay"  ,   &m_mctruth_lepdecay );
  outTree->Branch("mctruth_haddecay"  ,   &m_mctruth_haddecay );
  
  outTree->Branch("truthStable_el_pt"  ,   &m_truthStable_el_pt     );
  outTree->Branch("truthStable_el_eta"  ,   &m_truthStable_el_eta     );
  outTree->Branch("truthStable_el_phi"  ,   &m_truthStable_el_phi     );
  outTree->Branch("truthStable_mu_pt"  ,   &m_truthStable_mu_pt     );
  outTree->Branch("truthStable_mu_eta"  ,   &m_truthStable_mu_eta     );
  outTree->Branch("truthStable_mu_phi"  ,   &m_truthStable_mu_phi     );
  outTree->Branch("truthStable_ph_pt"  ,   &m_truthStable_ph_pt     );
  outTree->Branch("truthStable_ph_eta"  ,   &m_truthStable_ph_eta     );
  outTree->Branch("truthStable_ph_phi"  ,   &m_truthStable_ph_phi     );
  
  outTree->Branch("MET_truth_nonint"               ,   &m_MET_truth_nonint                ) ;
  outTree->Branch("MET_truth_nonint_x"             ,   &m_MET_truth_nonint_x              );
  outTree->Branch("MET_truth_nonint_y"             ,   &m_MET_truth_nonint_y              );
  

  outTree->Branch("jet_n"             ,   &m_jet_n          ) ;
  outTree->Branch("jet_E"             ,   &m_jet_E          ) ;
  outTree->Branch("jet_pt"            ,   &m_jet_pt         ) ;
  outTree->Branch("jet_eta"           ,   &m_jet_eta        ) ;
  outTree->Branch("jet_phi"           ,   &m_jet_phi        ) ;
  
  outTree->Branch("jet_isbtag"        ,   &m_jet_isbtag     ) ;
  outTree->Branch("jet_MV1"           ,   &m_jet_MV1     ) ; ///added 8/20/14
  outTree->Branch("jet_BtagWeight"     ,   &m_jet_BtagWeight     ) ;
  outTree->Branch("jet_VetoBtagWeight" ,   &m_jet_VetoBtagWeight ) ;
  ////&&&&
  outTree->Branch("jet_BtagWeight_60"     ,   &m_jet_BtagWeight_60     ) ;
  outTree->Branch("jet_VetoBtagWeight_60" ,   &m_jet_VetoBtagWeight_60 ) ;
  

  outTree->Branch("jet_emfrac"            ,   &m_jet_emfrac         ) ; ///added 10/5/14
  outTree->Branch("jet_jvtxf"            ,   &m_jet_jvtxf         ) ; ///added 10/19/14

  outTree->Branch("fatjet_n"             ,   &m_fatjet_n          ) ;
  outTree->Branch("fatjet_E"             ,   &m_fatjet_E          ) ;
  outTree->Branch("fatjet_pt"            ,   &m_fatjet_pt         ) ;
  outTree->Branch("fatjet_eta"           ,   &m_fatjet_eta        ) ;
  outTree->Branch("fatjet_phi"           ,   &m_fatjet_phi        ) ;
  outTree->Branch("fatjet_m"             ,   &m_fatjet_m          ) ;
  

  outTree->Branch("lep_n"             ,   &m_lep_n          ) ;
  outTree->Branch("lep_E"             ,   &m_lep_E          ) ;
  outTree->Branch("lep_pt"            ,   &m_lep_pt         ) ;
  outTree->Branch("lep_eta"           ,   &m_lep_eta        ) ;
  outTree->Branch("lep_phi"           ,   &m_lep_phi        ) ;
  outTree->Branch("lep_ID"            ,   &m_lep_ID         ) ;
  outTree->Branch("lep_isGood"        ,   &m_lep_isGood     ) ;
  

  
  Long64_t nEntries = chain->GetEntries();
  std::cout << " the chain contains " << nEntries << " entries " << std::endl;

  
  int DatasetID = -1 ;

  int numberOfEvents(0);

  int initialCount(0); ///added by auzaman 12/7/14
  int njetsCount(0); ///added by auzaman 12/7/14
  int jetptCount(0); ///added by auzaman 12/7/14
  int fatjetptCount(0); ///added by auzaman 12/7/14

  bool doSignal=false; //true for signal samples only

  //int count(0.), count2(0.),count3(0.);
  
  for (unsigned int iEvt = 0; iEvt < nEntries; ++iEvt) { //event loop
    if ( iEvt%10000 == 0 ) std::cout << " processed " << iEvt << " events so far " << std::endl;
    initialCount++;
    if(DEBUG) cout<<"Hello"<<endl;
    //cout<<h1-> mcEventWeight<<endl;

    //  cout<<"iEvt = "<<iEvt<<endl;
    
    ///clear the vectors    
    
    m_jet_E     .clear() ;
    m_jet_pt    .clear() ;
    m_jet_eta   .clear() ;
    m_jet_phi   .clear() ;
    m_jet_isbtag.clear();
    m_jet_MV1   .clear();
    m_jet_BtagWeight.clear();
    m_jet_VetoBtagWeight.clear();
    ////&&&&
    m_jet_BtagWeight_60.clear();
    m_jet_VetoBtagWeight_60.clear();
    
    m_jet_emfrac.clear() ;
    m_jet_jvtxf.clear() ;
    
    m_mctruth_pdgId .clear();
    m_mctruth_pt    .clear();
    m_mctruth_eta   .clear();
    m_mctruth_phi   .clear();
    m_mctruth_m     .clear();
    m_mctruth_parent.clear();
    
    m_truthStable_el_pt    .clear();
    m_truthStable_el_eta   .clear();
    m_truthStable_el_phi   .clear();
    m_truthStable_mu_pt    .clear();
    m_truthStable_mu_eta   .clear();
    m_truthStable_mu_phi   .clear();
    m_truthStable_ph_pt    .clear();
    m_truthStable_ph_eta   .clear();
    m_truthStable_ph_phi   .clear();
    
    


    m_fatjet_E   .clear();
    m_fatjet_pt	 .clear();
    m_fatjet_eta .clear();
    m_fatjet_phi .clear();
    m_fatjet_m   .clear();
    

    m_lep_E  .clear() ;
    m_lep_pt .clear() ;
    m_lep_eta.clear() ;
    m_lep_phi.clear() ;
    m_lep_ID .clear() ;
    m_lep_isGood.clear();

    v_lepton    .clear();
    v_BadLepton .clear();
    v_jet       .clear();
    v_fatjet    .clear();
        
    chain->GetEntry(iEvt);
    
    
    if ( iEvt==0 ) DatasetID = h1-> mc_channel_number ;     ///h1 is a foo class object
    else {   if ( ((int)h1->mc_channel_number) != DatasetID) std::cout << "Something wrong with dataset ID" << std::endl;  }
    //cout<<"DatasetId = "<<DatasetID<<" , h1->mc_channel_number = "<<h1->mc_channel_number<<endl;

    m_RunNumber         = h1-> RunNumber         ;
    m_EventNumber       = h1-> EventNumber       ;

    //  /*
       
    m_IsBadMediumBCHUp       = h1-> IsBadMediumBCHUp       ;  //&&&& caf3.2 does not have bch variables
    m_IsBadMediumBCHDown       = h1-> IsBadMediumBCHDown       ;
    m_IsBadMediumBCH       = h1-> IsBadMediumBCH       ;
    m_IsBadTightBCH       = h1-> IsBadTightBCH       ;
    //  */

    //7/31/15, comment out for v3.2 (and earlier I guess)  //HARD CODED &&&&
    //filling out leading lepton etcone30, ptcone30, d0, z0 variables. The leading lepton is medium++ electron or medium muon, but not necessarily isolated or trigger matched
     /*
    if (h1-> m_el_n >0){ 
      m_el_etcone30_0 = h1-> m_el_etcone30->at(0) ; //This electron can be a very bad one ( rarely, because of high pt). But by the end, only those events are stored where there is exactly one OR two good lep OR exactly one bad lep. So the very bad electron event should not be in the output. 
      m_el_ptcone30_0 = h1-> m_el_ptcone30->at(0) ;
      m_el_z0sinth_0 = h1-> m_el_z0sinth->at(0) ;
      m_el_d0_0 = h1-> m_el_trackd0pv->at(0) ;
      m_el_sigd0_0 = h1-> m_el_tracksigd0pv->at(0) ;

    }

    if (h1-> m_mu_n >0){
      m_mu_etcone30_0 = h1-> m_mu_etcone30->at(0) ; //This muon can be a very bad one but rarely, because of high pt 
      m_mu_ptcone30_0 = h1-> m_mu_ptcone30->at(0) ;
      m_mu_z0sinth_0 = h1-> m_mu_z0sinth->at(0) ;
      m_mu_d0_0 = h1-> m_mu_trackd0pv->at(0) ;
      m_mu_sigd0_0 = h1-> m_mu_tracksigd0pv->at(0) ;

    }
     */
    
    //Added 11/29/14 DONT NEED IT (8/2/15)
    // /*
    
    //m_leptonEtCone30 = h1-> leptonEtCone30;
    // m_leptonPtCone30 = h1-> leptonPtCone30 ;
    // m_leptonPtCone40 = h1-> leptonPtCone40 ;
    // m_leptonz0sinth = h1-> leptonz0sinth ;
    // m_leptond0sigd0 = h1-> leptond0sigd0 ;
    // m_leptonPt = h1-> leptonPt ;
    // */
    
    if (doMC) {
      m_mc_channel_number = h1-> mc_channel_number ;
      m_mcEventWeight     = h1-> mcEventWeight     ;
      m_pileupEventWeight = h1-> pileupEventWeight_090 ;
      m_ttbarWeight       = h1-> ttbarWeight ;  ///added 8/20/14
      m_truth_sherpa_Wpt  = h1-> truth_sherpa_Wpt ;
      m_truth_sherpa_Zpt  = h1-> truth_sherpa_Zpt ;

      if ( (m_mc_channel_number>=167930 && m_mc_channel_number<=167948) ||  // ggF CPS samples
	   (m_mc_channel_number>=169130 && m_mc_channel_number<=169148) )   // VBF CPS samples
	{  
	  m_mcEventWeight *= h1->InterferenceW_cen[9]; 
	}
      if ( ( (m_mc_channel_number>= 185721 && m_mc_channel_number<= 185794) || (m_mc_channel_number>= 207266 && m_mc_channel_number<= 207281) ) ){
	doSignal=true;
      }


      //doSignal=false;
      if(DEBUG) cout<<"Hello1 "<<"doSignal = "<<doSignal<<endl;
     
      //=======

      
      
      if (doSignal) {
	
	for(unsigned imc=0; imc< h1->mctruth_pdgId->size(); imc++){
	  m_mctruth_pdgId.push_back( h1->mctruth_pdgId->at(imc) );
	  m_mctruth_pt.push_back( h1->mctruth_pt->at(imc) );
	  m_mctruth_eta.push_back( h1->mctruth_eta->at(imc) );
	  m_mctruth_phi.push_back( h1->mctruth_phi->at(imc) );
	  m_mctruth_m.push_back( h1->mctruth_m->at(imc) );
	  m_mctruth_parent.push_back( h1->mctruth_parent->at(imc) );
	  
	}
	
	if(DEBUG) cout<<"Hello1.1"<<endl;

	if( h1->mctruth_pdgId->size() > 0 ){
	  
	  m_mctruth_Nbquarks=0;
	  std::vector<int> myLeps;
	  std::vector<int> myQuarks;
	  int hadBosonType=-1;
	  int lepBosonType=-1;
	  
	  for(unsigned imc=0; imc< h1->mctruth_pdgId->size(); imc++){

   	    int myPdgId = m_mctruth_pdgId.at(imc);
	    int myParent = m_mctruth_parent.at(imc);
	    
	    //cout<<"imc = "<<imc<<" pdg = "<<myPdgId<<" ; parent = "<<myParent<<" ; pt = "<<m_mctruth_pt.at(imc)<<endl;
	    
	    if(abs(myPdgId)==5){
	      m_mctruth_Nbquarks++;  //total number of b-quarks in hard-scatter, whether from V->jj or from "tag jets"
	    }
	    
	    if(myParent>=0){
	      myQuarks.push_back(myPdgId);
	      int hadBoson = m_mctruth_pdgId.at(myParent);
	      if(abs(hadBoson)==24){ //it's a W->jj
		hadBosonType=0;
	      }
	      else if(abs(hadBoson)==23){  //it's a Z->jj
		hadBosonType=1;
	      }
	      else{ 
		assert(0); 
	      }
	    }
	    
	    
	    if(abs(myPdgId)>=11 && abs(myPdgId)<=16){
	      myLeps.push_back(myPdgId);
	    }
	    
	  }
	  
	  
	  //lepdecay: 0=enu, 1=munu, 2=taunu, 3=ee, 4=mumu, 5=tautau
	  m_mctruth_lepdecay=-1;
	  if(myLeps[0] + myLeps[1] == 0){
	    //it's a Z decay.
	    lepBosonType=1;
	    //pdg codes: e=11, mu=13, tau=15
	    m_mctruth_lepdecay = 3 + (abs(myLeps[0]) - 11)/2;
	    
	  }
	  else if(abs(myLeps[0] + myLeps[1]) == 1){
	    //it's a W decay
	    lepBosonType=0;
	    //pdg(l) + pdg(nu) = 23, 27, or 31
	    m_mctruth_lepdecay =  (abs(myLeps[0]) + abs(myLeps[1]) - 23)/4;
	  }
	  else{
	    assert(0);
	  }
	  
	  //pdg codes: d=1,u=2,s=3,c=4,b=5
	  //haddecay: 0=udbar, 1=csbar, 2=ddbar, 3=uubar, 4=ssbar, 5=ccbar, 6=bbar, -1=error (happens on rare occasions when d3pd record lacks decay)
	  m_mctruth_haddecay=-1;

	  if(myQuarks.size()==2){
	    if(myQuarks[0] + myQuarks[1] == 0){
	      //it's a Z decay. 
	      m_mctruth_haddecay = 1 + abs(myQuarks[0]);
	    }
	    else if(abs(myQuarks[0] + myQuarks[1]) == 1){
	      //it's a W decay
	      m_mctruth_haddecay =  (abs(myQuarks[0]) + abs(myQuarks[1]) - 3)/4;
	    }
	    else{
	      std::cout<<"Woah!!"<<std::endl;
	      assert(0);
	    }
	  }	    

	  //VVmode: 0=W(lv)W(jj), 1=W(lv)Z(jj), 2=Z(ll)W(jj), 3=Z(ll)Z(jj)
	  m_mctruth_VVmode = lepBosonType*2 + hadBosonType;
	  
	}//end if(mctruth size > 0)
      }//end if(doSignal)


      if(DEBUG) cout<<"Hello2"<<endl;
      //=======
      

      ////// 10/5/14  comment out for CAF files VBF_2.5 or older
      // /*
      for(unsigned imc=0; imc< h1->truthStable_el_pt->size(); imc++){
	m_truthStable_el_pt.push_back( h1->truthStable_el_pt->at(imc) );
	m_truthStable_el_eta.push_back( h1->truthStable_el_eta->at(imc) );
	m_truthStable_el_phi.push_back( h1->truthStable_el_phi->at(imc) );
      }
      
      
      for(unsigned imc=0; imc< h1->truthStable_mu_pt->size(); imc++){
	m_truthStable_mu_pt.push_back( h1->truthStable_mu_pt->at(imc) );
	m_truthStable_mu_eta.push_back( h1->truthStable_mu_eta->at(imc) );
	m_truthStable_mu_phi.push_back( h1->truthStable_mu_phi->at(imc) );
      }
      for(unsigned imc=0; imc< h1->truthStable_ph_pt->size(); imc++){
	//Don't write out photons with pT<10 GeV, otherwise file size gets really big.
	if( h1->truthStable_ph_pt->at(imc) > 10000 ){
	  m_truthStable_ph_pt.push_back( h1->truthStable_ph_pt->at(imc) );
	  m_truthStable_ph_eta.push_back( h1->truthStable_ph_eta->at(imc) );
	  m_truthStable_ph_phi.push_back( h1->truthStable_ph_phi->at(imc) );
	}
      }
      
      
      m_MET_truth_nonint               = h1-> MET_truth_nonint      ;
      m_MET_truth_nonint_x             = h1-> MET_truth_nonint_x    ;
      m_MET_truth_nonint_y             = h1-> MET_truth_nonint_y    ;
      // */
      //////
    }
    else {  //data
      m_mc_channel_number = 0 ;
      m_mcEventWeight     = 1 ;
      m_pileupEventWeight = 1 ;
      m_ttbarWeight       = 1 ;  ///added 8/20/14
      m_truth_sherpa_Wpt  = -999 ;
      m_truth_sherpa_Zpt  = -999 ;
      
      if (doSignal) {
	m_mctruth_Nbquarks = -1;
	m_mctruth_VVmode   = -1;
	m_mctruth_lepdecay = -1;
	m_mctruth_haddecay = -1;
      }
      
      // /*
      m_truthStable_el_pt.push_back( 0.);
      m_truthStable_el_eta.push_back( 0.);
      m_truthStable_el_phi.push_back( 0.);
      m_truthStable_mu_pt.push_back( 0.);
      m_truthStable_mu_eta.push_back( 0.);
      m_truthStable_mu_phi.push_back( 0.);
      m_truthStable_ph_pt.push_back( 0.);
      m_truthStable_ph_eta.push_back( 0.);
      m_truthStable_ph_phi.push_back( 0.);
      // */
      
    }

    
    

    //  /*
    m_MET               = h1-> MET      ;
    m_MET_x             = h1-> MET_x    ;
    m_MET_y             = h1-> MET_y    ;
    m_MET_phi           = h1-> MET_phi  ;
   // */
    if(DEBUG) cout<<"Hello3"<<endl;

    /*
    std::cout<<"Temporary hack!!!"<<std::endl;
    m_MET               = h1-> MET_default      ;
    m_MET_x             = h1-> MET_default_x    ;
    m_MET_y             = h1-> MET_default_y    ;
    m_MET_phi           = TMath::ATan2(h1-> MET_default_y, h1-> MET_default_x);
    */

    //    m_MET_STVF               = h1-> MET_STVF      ;
    //   m_MET_x_STVF             = h1-> MET_x_STVF    ;
    //  m_MET_y_STVF             = h1-> MET_y_STVF    ;
    //  m_MET_phi_STVF           = h1-> MET_phi_STVF  ;
    
    // -------------------------------------
    // Object selection

    cutflow->Fill(0.,m_mcEventWeight);

    if( h1->m_jet_n >=2 || h1->m_mfcajet_n >=1){njetsCount++; cutflow->Fill(1.,m_mcEventWeight);} ///added by auzaman 12/7/14

    //cout<<h1->m_jet_n<<" "<<h1->MV1_EventWeight->size() <<endl;
    
    for (int ijet=0; ijet < h1->m_jet_n ; ijet++){
      if ( h1->m_jet_pt->at(ijet) < 30000. ) continue ; // jet pT cut
      Jet thisjet; 
      thisjet.SetPtEtaPhiE( h1->m_jet_pt  ->at(ijet), 
			    h1->m_jet_eta ->at(ijet),
			    h1->m_jet_phi ->at(ijet), 
			    h1->m_jet_E   ->at(ijet)) ; 

      ///IsBjet needed for jet_isbtag, not required for new slim ntuples which uses jet_MV1. 8/20/14 
      //if ( fabs(h1->m_jet_eta->at(ijet)) <2.5 && h1->m_jet_flavor_weight_MV1->at(ijet) > 0.148 )  thisjet.IsBjet=true;
      //else                                                                           thisjet.IsBjet=false;

      if(DEBUG) cout<<"Hello3.01"<<endl;

      thisjet.Jet_MV1             = h1->m_jet_flavor_weight_MV1->at(ijet);  ///added 8/20/14
      thisjet.Jet_Emfrac          = h1->m_jet_emfrac->at(ijet);  ///added 10/5/14   comment out for CAF files VBF_2.5 or older      
      thisjet.Jet_JVF          = h1->m_jet_jvtxf->at(ijet);  ///added 10/19/14

      if(DEBUG) cout<<"Hello3.02"<<endl;

      if (doMC){
	thisjet.MV1_EventWeight     = h1->MV1_EventWeight->at(ijet);
	thisjet.MV1_VetoEventWeight = h1->MV1_VetoEventWeight->at(ijet);
	//&&&&
	thisjet.MV1_EventWeight_60     = h1->MV1_EventWeight_60->at(ijet);
	thisjet.MV1_VetoEventWeight_60 = h1->MV1_VetoEventWeight_60->at(ijet);
      }else { 
	thisjet.MV1_EventWeight     = 1.;
	thisjet.MV1_VetoEventWeight = 1.;
	//&&&&
	thisjet.MV1_EventWeight_60     = h1->MV1_EventWeight_60->at(ijet);
	thisjet.MV1_VetoEventWeight_60 = h1->MV1_VetoEventWeight_60->at(ijet);
      }
      
      v_jet.push_back( thisjet );
    }
    

    
    //Sort jets by pT
    SortJets(v_jet);
    
    jetptCount++;

    cutflow->Fill(2.,m_mcEventWeight);

    if(DEBUG) cout<<"Hello3.1"<<endl;
    // fat jet
    for (int ijet=0; ijet < h1->m_mfcajet_n ; ijet++){
      if ( h1->m_mfcajet_pt->at(ijet) < 40000.    ) continue ; // jet pT cut
      if ( fabs(h1->m_mfcajet_eta->at(ijet) )>2.0 ) continue ; // jet eta < 2.0 (this was done in exotics WV resonance search)  
      Jet thisjet; 
      thisjet.SetPtEtaPhiE( h1->m_mfcajet_pt  ->at(ijet), 
			    h1->m_mfcajet_eta ->at(ijet),
			    h1->m_mfcajet_phi ->at(ijet), 
			    h1->m_mfcajet_E   ->at(ijet)) ; 
      
      //cout<<"fat jet: m = "<<thisjet.M()<<" ; mass = "<<h1->m_mfcajet_m->at(ijet)<<endl;


      v_fatjet.push_back( thisjet );
    }

    //Sort jets by pT
    SortJets(v_fatjet);
    
    fatjetptCount++;

    cutflow->Fill(3.,m_mcEventWeight);

    
    
    //A sanity check.  Later code requires this to be true, so don't delete this line unless you know exactly what you're doing!!!  
    assert(h1->m_el_n == 0 || h1->m_mu_n==0);
    int nLepCAF = h1->m_el_n + h1->m_mu_n;  //total number of leptons, including VERY bad leptons, that don't even satisify the bad lepton criteria.

    if(DEBUG) cout<<"Hello3.2"<<endl;
    // Electron selection
    for (int iel=0; iel < h1->m_el_n ; iel++){ //looping over all the electrons from CAF file

      Lepton thislep; 
      thislep.SetPtEtaPhiE( h1->m_el_pt  ->at(iel), 
			    h1->m_el_eta ->at(iel),
			    h1->m_el_phi ->at(iel), 
			    h1->m_el_E   ->at(iel));
      thislep.pdgID = -11*(int)h1->m_el_charge->at(iel) ; 
      
      if (doMC){
	bool trigMatch = (h1->lepMatch_EF_e24vhi_medium1->at(iel) || h1->lepMatch_EF_e60_medium1->at(iel));
	thislep.trigMatch  = trigMatch;
      }else{
	thislep.trigMatch  = true;
      }
      if      ( h1->isTPP_ele->at(iel)    && h1->isIso_ele->at(iel) ) {   v_lepton   .push_back(thislep);  }
      //if      ( h1->isTPP_ele->at(iel)  ) {   v_lepton   .push_back(thislep);  } //&&&& 8/2/15 no isolation requirement for good electrons

      //else if ( (!h1->isTPP_ele->at(iel)) && h1->isIso_ele->at(iel) ) {   v_BadLepton.push_back(thislep);  } //original
      //else if ( (!h1->isTPP_ele->at(iel))  ) {   v_BadLepton.push_back(thislep);  } //&&&& 7/29/15, bad electron is not tight++, and no isolation requirement --> looseBadMuon1.1
      else if ( (!h1->isTPP_ele->at(iel)) && ( h1-> m_el_etcone30->at(iel)/h1-> m_el_pt->at(iel)) > 0.04 && ( h1-> m_el_ptcone30->at(iel)/h1-> m_el_pt->at(iel)) < 0.5 ) {   v_BadLepton.push_back(thislep);  } //&&&& 8/11/15, bad electron is not tight++, et_rel_isolation > 0.04 and pt_rel_isolation < 0.5 --> looseBadLep4
      

    }

    if(DEBUG) cout<<"Hello4"<<endl;
    //=======
    

    // Muon selection
    for (int imu=0; imu < h1->m_mu_n ; imu++){

      Lepton thislep; 
      thislep.SetPtEtaPhiE( h1->m_mu_pt  ->at(imu), 
			    h1->m_mu_eta ->at(imu),
			    h1->m_mu_phi ->at(imu), 
			    h1->m_mu_E   ->at(imu));
      thislep.pdgID = -13*(int)h1->m_mu_charge->at(imu); 
      
      if(doMC){
	bool trigMatch = (h1->lepMatch_EF_mu24i_tight->at(imu) || h1->lepMatch_EF_mu36_tight->at(imu));
	thislep.trigMatch  = trigMatch;
      }else{
	thislep.trigMatch  = true;
      }
      
      if      ( h1->isD0_muon->at(imu)    && h1->isIso_muon->at(imu) ) { v_lepton   .push_back( thislep ); }
      //if      ( h1->isD0_muon->at(imu)    ) { v_lepton   .push_back( thislep ); } //&&&& 8/2/15 no isolation requirement for good muons

      //else if ( (!h1->isD0_muon->at(imu)) && h1->isIso_muon->at(imu) ) { v_BadLepton.push_back( thislep ); } //original: fail d0 cut, but isolated
      //else if ( (!h1->isD0_muon->at(imu))  ) { v_BadLepton.push_back( thislep ); } //&&&& 7/6/15, loosening bad muon definition. Fail d0 cut, no isolation requirement. --> looseBadMuon1 and looseBadMuon1.1
      else if ( (!h1->isD0_muon->at(imu)) && ( h1-> m_mu_etcone30->at(imu)/h1->m_mu_pt  ->at(imu) ) > 0.04 && ( h1-> m_mu_ptcone30->at(imu)/ h1->m_mu_pt  ->at(imu)) < 0.5) { v_BadLepton.push_back( thislep ); } //&&&&  8/11/15, bad muon fails d0sig cut, et_rel_isolation > 0.04 and pt_rel_isolation < 0.5 --> looseBadLep4


      
      //else if ( (!h1->isIso_muon->at(imu))  ) { v_BadLepton.push_back( thislep ); } //7/22/15, fail isolation cut, no d0 requirement
      //else if ( h1->isD0_muon->at(imu)    && (!h1->isIso_muon->at(imu)) ) { v_BadLepton.push_back( thislep ); } // 7/22/15, fail isolation cut but passes d0 cut.

    }
    if(DEBUG) cout<<"Hello4.1"<<endl;
    //count++;
    
    int whichRegion=-1;  //0:SR, 1: Z-CR, 2:QCD-CR

    //This code requires that the v_lepton and v_BadLepton vectors contain ALL the leptons.  NO CUTS YET AT THIS POINT.
    if(v_lepton.size()==2 && nLepCAF==2){
      //z-control region
      if(v_lepton[0].trigMatch || v_lepton[1].trigMatch ){
	whichRegion=1;
      }
      else{
	continue;
      }

    }
    else if(v_lepton.size()==1 && nLepCAF==1){
      //Signal region
      if(!v_lepton[0].trigMatch){
	continue;
      }
      whichRegion=0;
      
    }
    else if(v_BadLepton.size()==1 && nLepCAF==1){
      //QCD control region
      if(!v_BadLepton[0].trigMatch){
	continue;
      }
      whichRegion=2;
      
    }
    
    if(whichRegion<0){   //it's either ZCR, Signal region or QCD CR. For all other events (like events which has one good and 1 bad lepton) information will not be stored ( outTree->Fill() ).
      continue;
    }

    //count2++;
    
    m_mcEventWeight *= h1->lepTrigSFEventWeight;
    double totalLepSF=1.0;
    double totalLepSFerr=0;

    if(DEBUG) cout<<"Hello5"<<endl;

    
    //lepton trigger SF &&&& not present in CAF files 2.46 or older
    
    if (doMC) {
      if(whichRegion==0){
	assert(nLepCAF==1);  //this must be true for code to work.
	if(DEBUG) cout<<"Hello5.1"<<endl;
	//h1->lepSFEventWeight is not present in CAF files 2.46 or older
	totalLepSF *= h1->lepSFEventWeight->at(0);
	totalLepSFerr = sqrt( pow(h1->lepSFError->at(0),2) + pow(h1->lepSFErrorReco->at(0),2) + pow(h1->lepSFErrorIso->at(0),2) + pow(h1->lepSFErrorSys->at(0),2) );
      
    }
      else if(whichRegion==1){
	assert(nLepCAF==2);  //this must be true for code to work.
	if(DEBUG) cout<<"Hello5.2"<<endl;
	totalLepSF *= h1->lepSFEventWeight->at(0) * h1->lepSFEventWeight->at(1); 
	
	if(h1->m_mu_n==2){
	  //in the case of muons, the lepSFError is a statistical error on SF, which should be basically uncorrelated between two leptons.
	  //The other SF's are systematic, which we will assume are 100% correlated between the two leptons.
	  totalLepSFerr = sqrt( pow(h1->lepSFError->at(0),2) + pow(h1->lepSFError->at(1),2) +
				pow(h1->lepSFErrorReco->at(0)+h1->lepSFErrorReco->at(1),2)  + 
				pow(h1->lepSFErrorIso->at(0)+h1->lepSFErrorIso->at(1),2) +
				pow(h1->lepSFErrorSys->at(0)+h1->lepSFErrorSys->at(1),2) );
      }
	else{
	  //electron case.  Assume all SF's 100% correlated between the two leptons.
	  totalLepSFerr = sqrt(   pow(h1->lepSFError->at(0) + h1->lepSFError->at(1),2) +
				  pow(h1->lepSFErrorReco->at(0)+h1->lepSFErrorReco->at(1),2) +
				pow(h1->lepSFErrorIso->at(0)+h1->lepSFErrorIso->at(1),2) +
				  pow(h1->lepSFErrorSys->at(0)+h1->lepSFErrorSys->at(1),2) );
	}
	
      }
      else if(whichRegion==2){
	assert(nLepCAF==1);  //this must be true for code to work.
	if(DEBUG) cout<<"Hello5.3"<<endl;
	totalLepSF *= h1->lepSFEventWeight->at(0);
	totalLepSFerr = sqrt( pow(h1->lepSFError->at(0),2) + pow(h1->lepSFErrorReco->at(0),2) + pow(h1->lepSFErrorIso->at(0),2) + pow(h1->lepSFErrorSys->at(0),2) );
      }
    } //end doMC
    
    if(DEBUG) cout<<"Hello6"<<endl;

    m_mcEventWeight *= totalLepSF;
    
    //for doing mceventweightUp/Down, I think the performance group recommendation is to apply trigger and ID SF's as uncorrelated, even though
    //the H->lvqq CAF code was treating them as correlated.
    
    
    
    
    // -------------------------------------------
    // Lepton jet overlap. Remove jet if deltaR(lepton, jet) < somevalue
    cutTool->RemoveOverlap( &v_lepton, &v_jet,    0.3, false); 
    //cutTool->RemoveOverlap( &v_lepton, &v_fatjet, 0.3, false);
    cutTool->RemoveOverlap( &v_lepton, &v_fatjet, 1.2, false); //&&&&changed on 1/29/15. 


    //added the following two lines on 7/11/14 (bad lepton bug fix)
    cutTool->RemoveOverlap( &v_BadLepton, &v_jet,    0.3, false); 
    //cutTool->RemoveOverlap( &v_BadLepton, &v_fatjet, 0.3, false);
    cutTool->RemoveOverlap( &v_BadLepton, &v_fatjet, 1.2, false); //&&&&changed on 1/29/15. 

    if(DEBUG) cout<<"Hello7"<<endl;
    // --------------------------------------------
    // Save information into output vector for ntuple
    for (unsigned int j=0; j<v_jet.size() ; j++ ){
      m_jet_pt    .push_back( v_jet[j].Pt()   );
      m_jet_eta   .push_back( v_jet[j].Eta()   );
      m_jet_phi   .push_back( v_jet[j].Phi()   );
      m_jet_E     .push_back( v_jet[j].E()   );
      m_jet_isbtag.push_back( int(v_jet[j].IsBjet) );
      m_jet_MV1.push_back( v_jet[j].Jet_MV1 ) ;  ///added 8/20/14
      m_jet_BtagWeight    .push_back( v_jet[j]. MV1_EventWeight       ) ;
      m_jet_VetoBtagWeight.push_back( v_jet[j]. MV1_VetoEventWeight   ) ;
      ////&&&&
      m_jet_BtagWeight_60    .push_back( v_jet[j]. MV1_EventWeight_60       ) ; ///added 8/31/15
      m_jet_VetoBtagWeight_60.push_back( v_jet[j]. MV1_VetoEventWeight_60   ) ;
      
      m_jet_emfrac    .push_back( v_jet[j].Jet_Emfrac );  ///added 10/5/14, comment out for CAF version VBF_2.5 or older 
      m_jet_jvtxf    .push_back( v_jet[j].Jet_JVF );  ///added 10/19/14
      
    }
    m_jet_n = v_jet.size();

    for (unsigned int j=0; j<v_fatjet.size() ; j++ ){
      m_fatjet_pt .push_back( v_fatjet[j].Pt()   );
      m_fatjet_eta.push_back( v_fatjet[j].Eta()   );
      m_fatjet_phi.push_back( v_fatjet[j].Phi()   );
      m_fatjet_E  .push_back( v_fatjet[j].E()   );
      m_fatjet_m  .push_back( v_fatjet[j].M()   );
    }
    m_fatjet_n = v_fatjet.size();

    
    
    for (unsigned int ilep=0; ilep<v_lepton.size() ; ilep++ ){
      m_lep_pt .push_back( v_lepton[ilep].Pt()   );
      m_lep_eta.push_back( v_lepton[ilep].Eta()  );
      m_lep_phi.push_back( v_lepton[ilep].Phi()  );
      m_lep_E  .push_back( v_lepton[ilep].E()    );
      m_lep_ID .push_back( v_lepton[ilep].pdgID  );
      m_lep_isGood.push_back(int(1));
    }
    m_lep_n = v_lepton.size();

    for (unsigned int ilep=0; ilep<v_BadLepton.size() ; ilep++ ){
      m_lep_pt .push_back( v_BadLepton[ilep].Pt()   );
      m_lep_eta.push_back( v_BadLepton[ilep].Eta()  );
      m_lep_phi.push_back( v_BadLepton[ilep].Phi()  );
      m_lep_E  .push_back( v_BadLepton[ilep].E()    );
      m_lep_ID .push_back( v_BadLepton[ilep].pdgID  );
      m_lep_isGood.push_back(int(0));
    }
    m_lep_n += v_BadLepton.size(); //m_lep_n is now the sum of good and bad lepton. m_lep_n <= nLepCAF

    //////////// &&&&

    //if(whichRegion!= 2){continue;} //only bad lepton
    
  
    
    ///////////

    
    
    if (  (h1->m_el_n + h1->m_mu_n)>=1){cutflow->Fill(4.,m_mcEventWeight);} ///electron or muon irrespective of isolation, isTPP and isD0 
    if (  m_lep_n>=1){cutflow->Fill(5.,m_mcEventWeight);} ///good+bad lepton (isTPP (for electron) and isD0 (for muon) true)
    if (  v_lepton.size()>=1){cutflow->Fill(6.,m_mcEventWeight);} ///good (isolated) lepton
    
    if (  (h1->m_el_n + h1->m_mu_n)==1){cutflow->Fill(7.,m_mcEventWeight);} ///electron or muon irrespective of isolation, isTPP and isD0 
    if (  m_lep_n==1){cutflow->Fill(8.,m_mcEventWeight);} ///good+bad lepton (isTPP (for electron) and isD0 (for muon) true)
    if (  v_lepton.size()==1){cutflow->Fill(9.,m_mcEventWeight);} ///good (isolated) lepton
    
    if (  v_lepton.size()==1 && v_BadLepton.size()==1){cutflow->Fill(10.,m_mcEventWeight);}
    if (  (v_lepton.size()+ v_BadLepton.size())==2){cutflow->Fill(11.,m_mcEventWeight);} 
    
    if(DEBUG) cout<<"Hello8"<<endl;
    //  if ( m_lep_n==1 && (h1->m_el_n + h1->m_mu_n)==1  )
    if ( m_lep_n>0 )
      {
	if ( cutOnNjets==false || m_jet_n >= 2 || m_fatjet_n >= 1 ) { //if cutOnNjets==false, do not require at least two regular (or one fat) jets.
	  numberOfEvents++;
	  
	  outTree->Fill(); //this is when events are filled
	  if(DEBUG) cout<<"Hello8.1"<<endl;
	}
      }

    if(DEBUG) cout<<"Hello9"<<endl;
    
  } // end loop

  //cout<<"count ="<<count<<endl;
  //cout<<"count2 ="<<count2<<endl;
  //cout<<"count3 ="<<count3<<endl;

  outTree->AutoSave();



  outFile->cd();

  if (nFiles >0) {
    TString newname = Form("thisCount_%d", DatasetID); 
    if ( DatasetID > 0 && doMC ){
      TH1 *Num_Count = (TH1*) Count->Clone( newname );
      Num_Count->SetTitle(newname);
    }
    outFile->Add(Count);
  }
  
  outFile->Write();
  outFile->Close();
  
  // cout<<"n_lep>=1 "<<cutflow->GetBinContent(5)<<endl;
  // cout<<"n_lep_tight>=1 "<<cutflow->GetBinContent(6)<<endl;
  // cout<<"n_lep_tight_iso>=1 "<<cutflow->GetBinContent(7)<<endl;

  // cout<<"n_lep==1 "<<cutflow->GetBinContent(8)<<endl;
  // cout<<"n_lep_tight==1 "<<cutflow->GetBinContent(9)<<endl;
  // cout<<"n_lep_tight_iso==1 "<<cutflow->GetBinContent(10)<<endl;
  
  cout << " Number of saved events " << numberOfEvents << endl;

  // cout << " number of events after njet requirement = " << njetsCount << endl;
  // cout << " number of events after jet pt requirement = " << jetptCount << endl;
  // cout << " number of events after fatjet pt and eta requirement = " << fatjetptCount << endl;
  // cout << " Number of saved events = " << numberOfEvents << endl;

  timer.Stop();
  std::cout << " \n\n CPU time = " << timer.CpuTime() << "s real = " << timer.RealTime() << " s " << std::endl;

}



#ifndef __CINT__

#include "TString.h"

int main (int argc, char* argv[]) { 

  int    doMC   = (argc>1) ? atoi(argv[1]) : 0;
  //const char* inputlist = (argc>2) ? argv[2]       : "input.txt";
  const char* dsId = (argc>2) ? argv[2]       : "110101";
  const char* syst = (argc>3) ? argv[3]       : "Nominal";

  SkimSlimLvqqNtuple(doMC, string(dsId) ,string(syst) ) ; 

  return 0; 
}  
#endif



