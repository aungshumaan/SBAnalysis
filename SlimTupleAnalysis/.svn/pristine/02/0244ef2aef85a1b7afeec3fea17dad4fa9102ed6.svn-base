// This is  -*- C++ -*-
#ifndef SAMPLEMETADATA_H
#define SAMPLEMETADATA_H


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TString.h>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

namespace SampleMetaData
{
 
  void GetDatasetType( map <int , std::string> &DatasetTypeMap )
  {
    
    // ----------- Data -------------
    DatasetTypeMap[888888] = "Data" ; 
    


    //DatasetTypeMap[ 105200 ] = "Ttbar"     ; // ttbar MC@NLO
    DatasetTypeMap[ 117050 ] = "Ttbar"     ; // ttbar Powheg+Pythia
    //commented out 7/23/14 ---------
    // DatasetTypeMap[ 108343 ] = "SingleTop" ; // SingleTopSChanWenu MC@LNO+Jimmy
    // DatasetTypeMap[ 108344 ] = "SingleTop" ; // SingleTopSChanWmunu MC@LNO+Jimmy
    // DatasetTypeMap[ 108345 ] = "SingleTop" ; // SingleTopSChanWtaunu MC@LNO+Jimmy
    // DatasetTypeMap[ 108346 ] = "SingleTop" ; // SingleTopWtChanIncl MC@LNO+Jimmy

    // DatasetTypeMap[ 117360 ] = "SingleTop" ; // singletop_tchan_e AcerMC+Pythia
    // DatasetTypeMap[ 117361 ] = "SingleTop" ; // singletop_tchan_mu AcerMC+Pythia
    // DatasetTypeMap[ 117362 ] = "SingleTop" ; // singletop_tchan_tau AcerMC+Pythia
    //-----------------

    //added 7/23/14 ------
    DatasetTypeMap[ 110101 ] = "SingleTop" ; // singletop_tchan   AcerMCPythia
    DatasetTypeMap[ 110119 ] = "SingleTop" ; // singletop_schan    PowhegPythia
    DatasetTypeMap[ 110140 ] = "SingleTop" ; // singletop_Wtchan    PowhegPythia
    //----------------
    //Sherpa VBF W+jets
    DatasetTypeMap[ 129915 ] = "WjetsEWKSherpa" ; //
    DatasetTypeMap[ 129916 ] = "WjetsEWKSherpa" ; //
    DatasetTypeMap[ 129917 ] = "WjetsEWKSherpa" ; //

    DatasetTypeMap[ 105985 ] = "WZZZWg" ; // WW Herwig
    DatasetTypeMap[ 105986 ] = "WZZZWg" ; // ZZ Herwig 
    DatasetTypeMap[ 105987 ] = "WZZZWg" ; // WZ Herwig
    DatasetTypeMap[ 145161 ] = "WZZZWg" ; // eegammaPt10 Sherpa
    DatasetTypeMap[ 145162 ] = "WZZZWg" ; // mumugammaPt10 Sherpa

    //DatasetTypeMap[ 146430 ] = "WZZZWgZjets" ; //"WZZZWg" ; // WgammaNp0 Alpgen+Jimmy
    //DatasetTypeMap[ 146431 ] = "WZZZWgZjets" ; //"WZZZWg" ; // WgammaNp1 Alpgen+Jimmy
    //DatasetTypeMap[ 146432 ] = "WZZZWgZjets" ; //"WZZZWg" ; // WgammaNp2 Alpgen+Jimmy
    //DatasetTypeMap[ 146433 ] = "WZZZWgZjets" ; //"WZZZWg" ; // WgammaNp3 Alpgen+Jimmy

    DatasetTypeMap[ 146436 ] = "WZZZWg" ;// WgammaNp0_LeptonPhotonFilter Alpgen+Jimmy 
    DatasetTypeMap[ 146437 ] = "WZZZWg" ;// WgammaNp1_LeptonPhotonFilter Alpgen+Jimmy
    DatasetTypeMap[ 146438 ] = "WZZZWg" ;// WgammaNp2_LeptonPhotonFilter Alpgen+Jimmy
    DatasetTypeMap[ 146439 ] = "WZZZWg" ;// WgammaNp3_LeptonPhotonFilter Alpgen+Jimmy
    DatasetTypeMap[ 146434 ] = "WZZZWg" ; // WgammaNp4 Alpgen+Jimmy
    DatasetTypeMap[ 146435 ] = "WZZZWg" ; // WgammaNp5 Alpgen+Jimmy

    //added Sep 25, 2014 - blindqui
    DatasetTypeMap[ 183734 ] = "WZZZWg" ; // WW-> enuqq Sherpa
    DatasetTypeMap[ 183736 ] = "WZZZWg" ; // WW-> munuqq Sherpa
    DatasetTypeMap[ 183738 ] = "WZZZWg" ; // WW-> taunuqq Sherpa

    //&&&&
    //DatasetTypeMap[ 183734 ] = "WW" ; // WW-> enuqq Sherpa
    //DatasetTypeMap[ 183736 ] = "WW" ; // WW-> munuqq Sherpa
    //DatasetTypeMap[ 183738 ] = "WW" ; // WW-> taunuqq Sherpa

    DatasetTypeMap[ 177997 ] = "WZZZWg" ; // WW-> lnulnu Sherpa
    
    DatasetTypeMap[ 183735 ] = "WZZZWg" ; // WZ-> enuqq Sherpa
    DatasetTypeMap[ 183737 ] = "WZZZWg" ; // WZ-> munuqq Sherpa
    DatasetTypeMap[ 183739 ] = "WZZZWg" ; // WZ-> taunuqq Sherpa

    //&&&&
    //DatasetTypeMap[ 183735 ] = "WZ" ; // WZ-> enuqq Sherpa
    //DatasetTypeMap[ 183737 ] = "WZ" ; // WZ-> munuqq Sherpa
    //DatasetTypeMap[ 183739 ] = "WZ" ; // WZ-> taunuqq Sherpa
    
    DatasetTypeMap[ 183585 ] = "WZZZWg" ; // WZ-> qqee Sherpa
    DatasetTypeMap[ 183587 ] = "WZZZWg" ; // WZ-> qqmumu Sherpa
    DatasetTypeMap[ 183589 ] = "WZZZWg" ; // WZ-> qqtautau Sherpa
    
    DatasetTypeMap[ 179974 ] = "WZZZWg" ; // WZ-> lnull Sherpa
    DatasetTypeMap[ 179975 ] = "WZZZWg" ; // WZ-> lnununu Sherpa
    
    DatasetTypeMap[ 183586 ] = "WZZZWg" ; // ZZ-> qqee Sherpa
    DatasetTypeMap[ 183588 ] = "WZZZWg" ; // ZZ-> qqmumu Sherpa 
    DatasetTypeMap[ 183590 ] = "WZZZWg" ; // ZZ-> qqtautau Sherpa
    
    
    //end added

    DatasetTypeMap[ 147770 ] = "Zjets" ; //"Zjets" ; // Zee Sherpa 
    DatasetTypeMap[ 147771 ] = "Zjets" ; //"Zjets" ; // Zmumu Sherpa 
    DatasetTypeMap[ 147772 ] = "Zjets" ; //"Zjets" ; // Ztautau Sherpa


    // Comment out pT sliced Sherpa Z , uncommented for new slim ntuples from Haifeng, 7/22/14
    DatasetTypeMap[ 167797 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter
    DatasetTypeMap[ 167798 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto
    DatasetTypeMap[ 167799 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto
    DatasetTypeMap[ 167800 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter
    DatasetTypeMap[ 167801 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto
    DatasetTypeMap[ 167802 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto
    DatasetTypeMap[ 167803 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter
    DatasetTypeMap[ 167804 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto
    DatasetTypeMap[ 167805 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto
    DatasetTypeMap[ 167809 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter
    DatasetTypeMap[ 167810 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto
    DatasetTypeMap[ 167811 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto
    DatasetTypeMap[ 167812 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter
    DatasetTypeMap[ 167813 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto
    DatasetTypeMap[ 167814 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto
    DatasetTypeMap[ 167815 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter
    DatasetTypeMap[ 167816 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto
    DatasetTypeMap[ 167817 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto
    DatasetTypeMap[ 167821 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter
    DatasetTypeMap[ 167822 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto
    DatasetTypeMap[ 167823 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto
    DatasetTypeMap[ 167824 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter
    DatasetTypeMap[ 167825 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto
    DatasetTypeMap[ 167826 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto
    DatasetTypeMap[ 167827 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter
    DatasetTypeMap[ 167828 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto
    DatasetTypeMap[ 167829 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto
    DatasetTypeMap[ 167833 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt500_BFilter
    DatasetTypeMap[ 167834 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto
    DatasetTypeMap[ 167835 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto
    DatasetTypeMap[ 167836 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt500_BFilter
    DatasetTypeMap[ 167837 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto
    DatasetTypeMap[ 167838 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto
    DatasetTypeMap[ 167839 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt500_BFilter
    DatasetTypeMap[ 167840 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto
    DatasetTypeMap[ 167841 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto
    DatasetTypeMap[ 180543 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter
    DatasetTypeMap[ 180544 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto
    DatasetTypeMap[ 180545 ] = "Zjets" ; // Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto
    DatasetTypeMap[ 180546 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter
    DatasetTypeMap[ 180547 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto
    DatasetTypeMap[ 180548 ] = "Zjets" ; // Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto
    DatasetTypeMap[ 180549 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter
    DatasetTypeMap[ 180550 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto
    DatasetTypeMap[ 180551 ] = "Zjets" ; // Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto

    
    //SHERPA W+jets samples
    DatasetTypeMap[ 147774 ] = "Wjets" ; // Wenu  FS
    DatasetTypeMap[ 147775 ] = "Wjets" ; // Wmunu  FS
    DatasetTypeMap[ 147776 ] = "Wjets" ; // Wtaunu FS
    DatasetTypeMap[ 167761 ] = "Wjets" ; // WenuMassiveCBPt70  AF
    DatasetTypeMap[ 167762 ] = "Wjets" ; // WenuMassiveCBPt70  AF
    DatasetTypeMap[ 167763 ] = "Wjets" ; // WenuMassiveCBPt70  AF
    DatasetTypeMap[ 167764 ] = "Wjets" ; // WmunuMassiveCBPt70  AF
    DatasetTypeMap[ 167765 ] = "Wjets" ; // WmunuMassiveCBPt70  AF
    DatasetTypeMap[ 167766 ] = "Wjets" ; // WmunuMassiveCBPt70  AF
    DatasetTypeMap[ 167767 ] = "Wjets" ; // WtaunuMassiveCBPt70  FS  
    DatasetTypeMap[ 167768 ] = "Wjets" ; // WtaunuMassiveCBPt70  FS  
    DatasetTypeMap[ 167769 ] = "Wjets" ; // WtaunuMassiveCBPt70  FS  
    DatasetTypeMap[ 167770 ] = "Wjets" ; // WenuMassiveCBPt140  FS  AF
    DatasetTypeMap[ 167771 ] = "Wjets" ; // WenuMassiveCBPt140  FS  AF
    DatasetTypeMap[ 167772 ] = "Wjets" ; // WenuMassiveCBPt140  FS  AF
    DatasetTypeMap[ 167773 ] = "Wjets" ; // WmunuMassiveCBPt140  AF
    DatasetTypeMap[ 167774 ] = "Wjets" ; // WmunuMassiveCBPt140  AF
    DatasetTypeMap[ 167775 ] = "Wjets" ; // WmunuMassiveCBPt140  AF
    DatasetTypeMap[ 167776 ] = "Wjets" ; // WtaunuMassiveCBPt140  FS
    DatasetTypeMap[ 167777 ] = "Wjets" ; // WtaunuMassiveCBPt140  FS
    DatasetTypeMap[ 167778 ] = "Wjets" ; // WtaunuMassiveCBPt140  FS
    DatasetTypeMap[ 167779 ] = "Wjets" ; // WenuMassiveCBPt280  FS
    DatasetTypeMap[ 167780 ] = "Wjets" ; // WenuMassiveCBPt280  FS
    DatasetTypeMap[ 167781 ] = "Wjets" ; // WenuMassiveCBPt280  FS
    DatasetTypeMap[ 167782 ] = "Wjets" ; // WmunuMassiveCBPt280  FS
    DatasetTypeMap[ 167783 ] = "Wjets" ; // WmunuMassiveCBPt280  FS
    DatasetTypeMap[ 167784 ] = "Wjets" ; // WmunuMassiveCBPt280  FS
    DatasetTypeMap[ 167785 ] = "Wjets" ; // WtaunuMassiveCBPt280  FS
    DatasetTypeMap[ 167786 ] = "Wjets" ; // WtaunuMassiveCBPt280  FS
    DatasetTypeMap[ 167787 ] = "Wjets" ; // WtaunuMassiveCBPt280  FS
    DatasetTypeMap[ 167788 ] = "Wjets" ; // WenuMassiveCBPt500  FS  AF
    DatasetTypeMap[ 167789 ] = "Wjets" ; // WenuMassiveCBPt500  FS  AF
    DatasetTypeMap[ 167790 ] = "Wjets" ; // WenuMassiveCBPt500  FS  AF
    DatasetTypeMap[ 167791 ] = "Wjets" ; // WmunuMassiveCBPt500  FS
    DatasetTypeMap[ 167792 ] = "Wjets" ; // WmunuMassiveCBPt500  FS
    DatasetTypeMap[ 167793 ] = "Wjets" ; // WmunuMassiveCBPt500  FS
    DatasetTypeMap[ 167794 ] = "Wjets" ; // WtaunuMassiveCBPt500  FS
    DatasetTypeMap[ 167795 ] = "Wjets" ; // WtaunuMassiveCBPt500  FS
    DatasetTypeMap[ 167796 ] = "Wjets" ; // WtaunuMassiveCBPt500  FS

    DatasetTypeMap[ 180534 ] = "Wjets" ; // WenuMassiveCBPt40_70_BFilter           AF
    DatasetTypeMap[ 180535 ] = "Wjets" ; // WenuMassiveCBPt40_70_CJetFilterBVeto   AF
    DatasetTypeMap[ 180536 ] = "Wjets" ; // WenuMassiveCBPt40_70_CJetVetoBVeto     AF
    DatasetTypeMap[ 180537 ] = "Wjets" ; // WmunuMassiveCBPt40_70_BFilter          AF
    DatasetTypeMap[ 180538 ] = "Wjets" ; // WmunuMassiveCBPt40_70_CJetFilterBVeto  AF
    DatasetTypeMap[ 180539 ] = "Wjets" ; // WmunuMassiveCBPt40_70_CJetVetoBVeto    AF
    DatasetTypeMap[ 180540 ] = "Wjets" ; // WtaunuMassiveCBPt40_70_BFilter         AF
    DatasetTypeMap[ 180541 ] = "Wjets" ; // WtaunuMassiveCBPt40_70_CJetFilterBVeto  AF
    DatasetTypeMap[ 180542 ] = "Wjets" ; // WtaunuMassiveCBPt40_70_CJetVetoBVeto   AF
    
    ///////Sherpa pt0 samples
    // /*
    DatasetTypeMap[ 167740 ] = "Wjets" ; //WenuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167741 ] = "Wjets" ; //WenuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167742 ] = "Wjets" ; //WenuMassiveCBPt0_CJetVetoBVeto
    DatasetTypeMap[ 167743 ] = "Wjets" ; //WmunuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167744 ] = "Wjets" ; //WmunuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167745 ] = "Wjets" ; //WmunuMassiveCBPt0_CJetVetoBVeto
    DatasetTypeMap[ 167746 ] = "Wjets" ; //WtaunuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167747 ] = "Wjets" ; //WtaunuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167748 ] = "Wjets" ; //WtaunuMassiveCBPt0_CJetVetoBVeto

    DatasetTypeMap[ 167749 ] = "Zjets" ; //WenuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167750 ] = "Zjets" ; //WenuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167751 ] = "Zjets" ; //WenuMassiveCBPt0_CJetVetoBVeto
    DatasetTypeMap[ 167752 ] = "Zjets" ; //WmunuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167753 ] = "Zjets" ; //WmunuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167754 ] = "Zjets" ; //WmunuMassiveCBPt0_CJetVetoBVeto
    DatasetTypeMap[ 167755 ] = "Zjets" ; //WtaunuMassiveCBPt0_BFilter
    DatasetTypeMap[ 167756 ] = "Zjets" ; //WtaunuMassiveCBPt0_CJetFilterBVeto
    DatasetTypeMap[ 167757 ] = "Zjets" ; //WtaunuMassiveCBPt0_CJetVetoBVeto
    // */
    
    //Alpgen-Pythia W+jets sample

    DatasetTypeMap[ 147025 ] = "WjetsAlp" ; //WenuNp0
    DatasetTypeMap[ 147026 ] = "WjetsAlp" ; //WenuNp1
    DatasetTypeMap[ 147027 ] = "WjetsAlp" ; //WenuNp2
    DatasetTypeMap[ 147028 ] = "WjetsAlp" ; //WenuNp3
    DatasetTypeMap[ 147029 ] = "WjetsAlp" ; //WenuNp4
    DatasetTypeMap[ 147030 ] = "WjetsAlp" ; //WenuNp5incl
    DatasetTypeMap[ 147033 ] = "WjetsAlp" ; //WmunuNp0
    DatasetTypeMap[ 147034 ] = "WjetsAlp" ; //WmunuNp1
    DatasetTypeMap[ 147035 ] = "WjetsAlp" ; //WmunuNp2
    DatasetTypeMap[ 147036 ] = "WjetsAlp" ; //WmunuNp3
    DatasetTypeMap[ 147037 ] = "WjetsAlp" ; //WmunuNp4
    DatasetTypeMap[ 147038 ] = "WjetsAlp" ; //WmunuNp5incl
    DatasetTypeMap[ 147041 ] = "WjetsAlp" ; //WtaunuNp0
    DatasetTypeMap[ 147042 ] = "WjetsAlp" ; //WtaunuNp1
    DatasetTypeMap[ 147043 ] = "WjetsAlp" ; //WtaunuNp2
    DatasetTypeMap[ 147044 ] = "WjetsAlp" ; //WtaunuNp3
    DatasetTypeMap[ 147045 ] = "WjetsAlp" ; //WtaunuNp4
    DatasetTypeMap[ 147046 ] = "WjetsAlp" ; //WtaunuNp5incl


    DatasetTypeMap[ 200156 ] = "WjetsAlp" ; //WccNp0
    DatasetTypeMap[ 200157 ] = "WjetsAlp" ; //WccNp1
    DatasetTypeMap[ 200158 ] = "WjetsAlp" ; //WccNp2
    DatasetTypeMap[ 200159 ] = "WjetsAlp" ; //WccNp3incl
    DatasetTypeMap[ 200056 ] = "WjetsAlp" ; //WcNp0
    DatasetTypeMap[ 200057 ] = "WjetsAlp" ; //WcNp1
    DatasetTypeMap[ 200058 ] = "WjetsAlp" ; //WcNp2
    DatasetTypeMap[ 200059 ] = "WjetsAlp" ; //WcNp3
    DatasetTypeMap[ 200060 ] = "WjetsAlp" ; //WcNp4incl
    DatasetTypeMap[ 200256 ] = "WjetsAlp" ; //WbbNp0
    DatasetTypeMap[ 200257 ] = "WjetsAlp" ; //WbbNp1
    DatasetTypeMap[ 200258 ] = "WjetsAlp" ; //WbbNp2
    DatasetTypeMap[ 200259 ] = "WjetsAlp" ; //WbbNp3incl

    //////
    
    
    //Sherpa Systematic variations -- BL
    DatasetTypeMap[ 183485 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt70_140_BFilter_ckkw15
    DatasetTypeMap[ 183486 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt70_140_BFilter_ckkw30
    DatasetTypeMap[ 183487 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt70_140_BFilter_fac025
    DatasetTypeMap[ 183488 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt70_140_BFilter_fac4
    DatasetTypeMap[ 183489 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt70_140_BFilter_renorm025
    DatasetTypeMap[ 183490 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt70_140_BFilter_renorm4
    DatasetTypeMap[ 183491 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_ckkw15
    DatasetTypeMap[ 183492 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_ckkw30
    DatasetTypeMap[ 183493 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_fac025
    DatasetTypeMap[ 183494 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_fac4
    DatasetTypeMap[ 183495 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_renorm025
    DatasetTypeMap[ 183496 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt70_140_CJetFilterBVeto_renorm4
    DatasetTypeMap[ 183497 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_ckkw15
    DatasetTypeMap[ 183498 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_ckkw30
    DatasetTypeMap[ 183499 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_fac025
    DatasetTypeMap[ 183500 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_fac4
    DatasetTypeMap[ 183501 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_renorm025
    DatasetTypeMap[ 183502 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt70_140_CJetVetoBVeto_renorm4
    DatasetTypeMap[ 183503 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt140_280_BFilter_ckkw15
    DatasetTypeMap[ 183504 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt140_280_BFilter_ckkw30
    DatasetTypeMap[ 183505 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt140_280_BFilter_fac025
    DatasetTypeMap[ 183506 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt140_280_BFilter_fac4
    DatasetTypeMap[ 183507 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt140_280_BFilter_renorm025
    DatasetTypeMap[ 183508 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt140_280_BFilter_renorm4
    DatasetTypeMap[ 183509 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_ckkw15
    DatasetTypeMap[ 183510 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_ckkw30
    DatasetTypeMap[ 183511 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_fac025
    DatasetTypeMap[ 183512 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_fac4
    DatasetTypeMap[ 183513 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_renorm025
    DatasetTypeMap[ 183514 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt140_280_CJetFilterBVeto_renorm4
    DatasetTypeMap[ 183515 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_ckkw15
    DatasetTypeMap[ 183516 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_ckkw30
    DatasetTypeMap[ 183517 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_fac025
    DatasetTypeMap[ 183518 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_fac4
    DatasetTypeMap[ 183519 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_renorm025
    DatasetTypeMap[ 183520 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt140_280_CJetVetoBVeto_renorm4
    DatasetTypeMap[ 183521 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt280_500_BFilter_ckkw15
    DatasetTypeMap[ 183522 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt280_500_BFilter_ckkw30
    DatasetTypeMap[ 183523 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt280_500_BFilter_fac025
    DatasetTypeMap[ 183524 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt280_500_BFilter_fac4
    DatasetTypeMap[ 183525 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt280_500_BFilter_renorm025
    DatasetTypeMap[ 183526 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt280_500_BFilter_renorm4
    DatasetTypeMap[ 183527 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_ckkw15
    DatasetTypeMap[ 183528 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_ckkw30
    DatasetTypeMap[ 183529 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_fac025
    DatasetTypeMap[ 183530 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_fac4
    DatasetTypeMap[ 183531 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_renorm025
    DatasetTypeMap[ 183532 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt280_500_CJetFilterBVeto_renorm4
    DatasetTypeMap[ 183533 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_ckkw15
    DatasetTypeMap[ 183534 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_ckkw30
    DatasetTypeMap[ 183535 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_fac025
    DatasetTypeMap[ 183536 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_fac4
    DatasetTypeMap[ 183537 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_renorm025
    DatasetTypeMap[ 183538 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt280_500_CJetVetoBVeto_renorm4
    DatasetTypeMap[ 183539 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt500_BFilter_ckkw15
    DatasetTypeMap[ 183540 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt500_BFilter_ckkw30
    DatasetTypeMap[ 183541 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt500_BFilter_fac025
    DatasetTypeMap[ 183542 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt500_BFilter_fac4
    DatasetTypeMap[ 183543 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt500_BFilter_renorm025
    DatasetTypeMap[ 183544 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt500_BFilter_renorm4
    DatasetTypeMap[ 183545 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt500_CJetFilterBVeto_ckkw15
    DatasetTypeMap[ 183546 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt500_CJetFilterBVeto_ckkw30
    DatasetTypeMap[ 183547 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt500_CJetFilterBVeto_fac025
    DatasetTypeMap[ 183548 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt500_CJetFilterBVeto_fac4
    DatasetTypeMap[ 183549 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt500_CJetFilterBVeto_renorm025
    DatasetTypeMap[ 183550 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt500_CJetFilterBVeto_renorm4
    DatasetTypeMap[ 183551 ] = "TruthWjetsckkw15" ; //WenuMassiveCBPt500_CJetVetoBVeto_ckkw15
    DatasetTypeMap[ 183552 ] = "TruthWjetsckkw30" ; //WenuMassiveCBPt500_CJetVetoBVeto_ckkw30
    DatasetTypeMap[ 183553 ] = "TruthWjetsfac025" ; //WenuMassiveCBPt500_CJetVetoBVeto_fac025
    DatasetTypeMap[ 183554 ] = "TruthWjetsfac4" ; //WenuMassiveCBPt500_CJetVetoBVeto_fac4
    DatasetTypeMap[ 183555 ] = "TruthWjetsrenorm025" ; //WenuMassiveCBPt500_CJetVetoBVeto_renorm025
    DatasetTypeMap[ 183556 ] = "TruthWjetsrenorm4" ; //WenuMassiveCBPt500_CJetVetoBVeto_renorm4

    
    //Powheg Systematic variations -- BL     
    DatasetTypeMap[ 185696 ] = "TruthPowhegWjets_Nominal" ; //W2Jets_Wm_Nominal
    DatasetTypeMap[ 185697 ] = "TruthPowhegWjets_MuFdown" ; //W2Jets_Wm_MuFdown
    DatasetTypeMap[ 185698 ] = "TruthPowhegWjets_MuFup" ; //W2Jets_Wm_MuFup
    DatasetTypeMap[ 185699 ] = "TruthPowhegWjets_MuRdown" ; //W2Jets_Wm_MuRdown
    DatasetTypeMap[ 185700 ] = "TruthPowhegWjets_MuRup" ; //W2Jets_Wm_MuRup
    DatasetTypeMap[ 185701 ] = "TruthPowhegWjets_MuRFdown" ; //W2Jets_Wm_MuRFdown
    DatasetTypeMap[ 185702 ] = "TruthPowhegWjets_MuRFup" ; //W2Jets_Wm_MuRFup
    DatasetTypeMap[ 185703 ] = "TruthPowhegWjets_Nominal" ; //W2Jets_Wp_Nominal
    DatasetTypeMap[ 185704 ] = "TruthPowhegWjets_MuFdown" ; //W2Jets_Wp_MuFdown
    DatasetTypeMap[ 185705 ] = "TruthPowhegWjets_MuFup" ; //W2Jets_Wp_MuFup
    DatasetTypeMap[ 185706 ] = "TruthPowhegWjets_MuRdown" ; //W2Jets_Wp_MuRdown
    DatasetTypeMap[ 185707 ] = "TruthPowhegWjets_MuRup" ; //W2Jets_Wp_MuRup
    DatasetTypeMap[ 185708 ] = "TruthPowhegWjets_MuRFdown" ; //W2Jets_Wp_MuRFdown
    DatasetTypeMap[ 185709 ] = "TruthPowhegWjets_MuRFup" ; //W2Jets_Wp_MuRFup
    
    //Powheg-Pythia W+jets sample
    DatasetTypeMap[ 185836 ] = "WjetsPow" ; //Wm->enu+jets, PowhegPythia8
    DatasetTypeMap[ 185837 ] = "WjetsPow" ; //Wp->enu+jets, PowhegPythia8
    DatasetTypeMap[ 185696 ] = "WjetsPow" ; //Wm->munu+jets, PowhegPythia8
    DatasetTypeMap[ 185703 ] = "WjetsPow" ; //Wp->munu+jets, PowhegPythia8
    
    // DatasetTypeMap[ 185836 ] = "Wjets" ; //Wm->enu+jets, PowhegPythia8
    // DatasetTypeMap[ 185837 ] = "Wjets" ; //Wp->enu+jets, PowhegPythia8
    // DatasetTypeMap[ 185696 ] = "Wjets" ; //Wm->munu+jets, PowhegPythia8
    // DatasetTypeMap[ 185703 ] = "Wjets" ; //Wp->munu+jets, PowhegPythia8

    //Powheg EWK W+jets
    
    DatasetTypeMap[ 185847 ] = "WjetsPow" ; //Wm->enu+jets, PowhegPythia8
    DatasetTypeMap[ 185848 ] = "WjetsPow" ; //Wp->enu+jets, PowhegPythia8


    //Whizard scale-varied samples
    DatasetTypeMap[ 212000 ] = "VBS_WV_01_0_s_20_20";
    DatasetTypeMap[ 212001 ] = "VBS_WV_01_0_s_20_10";
    DatasetTypeMap[ 212002 ] = "VBS_WV_01_0_s_20_05";
    DatasetTypeMap[ 212003 ] = "VBS_WV_01_0_s_10_20";
    DatasetTypeMap[ 212004 ] = "VBS_WV_01_0_s_10_05";
    DatasetTypeMap[ 212005 ] = "VBS_WV_01_0_s_05_20";
    DatasetTypeMap[ 212006 ] = "VBS_WV_01_0_s_05_10";
    DatasetTypeMap[ 212007 ] = "VBS_WV_01_0_s_05_05";

    DatasetTypeMap[ 213000 ] = "VBS_ZV_01_0_s_20_20";
    DatasetTypeMap[ 213001 ] = "VBS_ZV_01_0_s_20_10";
    DatasetTypeMap[ 213002 ] = "VBS_ZV_01_0_s_20_05";
    DatasetTypeMap[ 213003 ] = "VBS_ZV_01_0_s_10_20";
    DatasetTypeMap[ 213004 ] = "VBS_ZV_01_0_s_10_05";
    DatasetTypeMap[ 213005 ] = "VBS_ZV_01_0_s_05_20";
    DatasetTypeMap[ 213006 ] = "VBS_ZV_01_0_s_05_10";
    DatasetTypeMap[ 213007 ] = "VBS_ZV_01_0_s_05_05";








    //Commented out on Jan 29, 2014 by AZ, kept Higgs VBF 125
    //DatasetTypeMap[ 161351 ] = "H_ggF_125" ; // ggH125
    /*
      DatasetTypeMap[ 161366 ] = "H_ggF_200" ; // ggH200
      DatasetTypeMap[ 161367 ] = "H_ggF_220" ; // ggH220
      DatasetTypeMap[ 161368 ] = "H_ggF_240" ; // ggH240
      DatasetTypeMap[ 161369 ] = "H_ggF_260" ; // ggH260
      DatasetTypeMap[ 161370 ] = "H_ggF_280" ; // ggH280
      DatasetTypeMap[ 161371 ] = "H_ggF_300" ; // ggH300
      DatasetTypeMap[ 161372 ] = "H_ggF_320" ; // ggH320
      DatasetTypeMap[ 161373 ] = "H_ggF_340" ; // ggH340
      DatasetTypeMap[ 161374 ] = "H_ggF_360" ; // ggH360
      DatasetTypeMap[ 161375 ] = "H_ggF_380" ; // ggH380
      DatasetTypeMap[ 167930 ] = "H_ggF_400" ; // ggH400CPS
      DatasetTypeMap[ 167931 ] = "H_ggF_420" ; // ggH420CPS
      DatasetTypeMap[ 167932 ] = "H_ggF_440" ; // ggH440CPS
      DatasetTypeMap[ 167933 ] = "H_ggF_460" ; // ggH460CPS
      DatasetTypeMap[ 167934 ] = "H_ggF_480" ; // ggH480CPS
      DatasetTypeMap[ 167935 ] = "H_ggF_500" ; // ggH500CPS
      DatasetTypeMap[ 167936 ] = "H_ggF_520" ; // ggH520CPS
      DatasetTypeMap[ 167937 ] = "H_ggF_540" ; // ggH540CPS
      DatasetTypeMap[ 167938 ] = "H_ggF_560" ; // ggH560CPS
      DatasetTypeMap[ 167939 ] = "H_ggF_580" ; // ggH580CPS
      DatasetTypeMap[ 167940 ] = "H_ggF_600" ; // ggH600CPS
      DatasetTypeMap[ 167941 ] = "H_ggF_650" ; // ggH650CPS
      DatasetTypeMap[ 167942 ] = "H_ggF_700" ; // ggH700CPS
      DatasetTypeMap[ 167943 ] = "H_ggF_750" ; // ggH750CPS
      DatasetTypeMap[ 167944 ] = "H_ggF_800" ; // ggH800CPS
      DatasetTypeMap[ 167945 ] = "H_ggF_850" ; // ggH850CPS
      DatasetTypeMap[ 167946 ] = "H_ggF_900" ; // ggH900CPS
      DatasetTypeMap[ 167947 ] = "H_ggF_950" ; // ggH950CPS
      DatasetTypeMap[ 167948 ] = "H_ggF_1000" ; // ggH1000CPS
    */

    DatasetTypeMap[ 161401 ] = "H_VBF_125" ; // VBFH125
    /*
      DatasetTypeMap[ 161416 ] = "H_VBF_200" ; // VBFH200
      DatasetTypeMap[ 161417 ] = "H_VBF_220" ; // VBFH220
      DatasetTypeMap[ 161418 ] = "H_VBF_240" ; // VBFH240
      DatasetTypeMap[ 161419 ] = "H_VBF_260" ; // VBFH260
      DatasetTypeMap[ 161420 ] = "H_VBF_280" ; // VBFH280
      DatasetTypeMap[ 161421 ] = "H_VBF_300" ; // VBFH300
      DatasetTypeMap[ 161422 ] = "H_VBF_320" ; // VBFH320
      DatasetTypeMap[ 161423 ] = "H_VBF_340" ; // VBFH340
      DatasetTypeMap[ 161424 ] = "H_VBF_360" ; // VBFH360
      DatasetTypeMap[ 161425 ] = "H_VBF_380" ; // VBFH380
      DatasetTypeMap[ 169130 ] = "H_VBF_400" ; // VBFH400CPS
      DatasetTypeMap[ 169131 ] = "H_VBF_420" ; // VBFH420CPS
      DatasetTypeMap[ 169132 ] = "H_VBF_440" ; // VBFH440CPS
      DatasetTypeMap[ 169133 ] = "H_VBF_460" ; // VBFH460CPS
      DatasetTypeMap[ 169134 ] = "H_VBF_480" ; // VBFH480CPS
      DatasetTypeMap[ 169135 ] = "H_VBF_500" ; // VBFH500CPS
      DatasetTypeMap[ 169136 ] = "H_VBF_520" ; // VBFH520CPS
      DatasetTypeMap[ 169137 ] = "H_VBF_540" ; // VBFH540CPS
      DatasetTypeMap[ 169138 ] = "H_VBF_560" ; // VBFH560CPS
      DatasetTypeMap[ 169139 ] = "H_VBF_580" ; // VBFH580CPS
      DatasetTypeMap[ 169140 ] = "H_VBF_600" ; // VBFH600CPS
      DatasetTypeMap[ 169141 ] = "H_VBF_650" ; // VBFH650CPS
      DatasetTypeMap[ 169142 ] = "H_VBF_700" ; // VBFH700CPS
      DatasetTypeMap[ 169143 ] = "H_VBF_750" ; // VBFH750CPS
      DatasetTypeMap[ 169144 ] = "H_VBF_800" ; // VBFH800CPS
      DatasetTypeMap[ 169145 ] = "H_VBF_850" ; // VBFH850CPS
      DatasetTypeMap[ 169146 ] = "H_VBF_900" ; // VBFH900CPS
      DatasetTypeMap[ 169147 ] = "H_VBF_950" ; // VBFH950CPS
      DatasetTypeMap[ 169148 ] = "H_VBF_1000" ; // VBFH1000CPS

      DatasetTypeMap[ 167950 ] = "H_ggF_300NWA";
      DatasetTypeMap[ 167951 ] = "H_ggF_400NWA" ;
      DatasetTypeMap[ 167952 ] = "H_ggF_500NWA" ;
      DatasetTypeMap[ 167953 ] = "H_ggF_600NWA" ;
      DatasetTypeMap[ 167954 ] = "H_ggF_700NWA" ;
      DatasetTypeMap[ 167955 ] = "H_ggF_800NWA" ;
      DatasetTypeMap[ 167956 ] = "H_ggF_900NWA" ;
      DatasetTypeMap[ 167957 ] = "H_ggF_1000NWA";

      DatasetTypeMap[ 169150 ] = "H_VBF_300NWA" ;
      DatasetTypeMap[ 169151 ] = "H_VBF_400NWA" ;
      DatasetTypeMap[ 169152 ] = "H_VBF_500NWA" ;
      DatasetTypeMap[ 169153 ] = "H_VBF_600NWA" ;
      DatasetTypeMap[ 169154 ] = "H_VBF_700NWA" ;
      DatasetTypeMap[ 169155 ] = "H_VBF_800NWA" ;
      DatasetTypeMap[ 169156 ] = "H_VBF_900NWA" ;
      DatasetTypeMap[ 169157 ] = "H_VBF_1000NWA";
    */


    DatasetTypeMap[ 185721 ] =  "VBS_WV_0_0";
    DatasetTypeMap[ 185722 ] =  "VBS_WV_0_01";
    DatasetTypeMap[ 185723 ] =  "VBS_WV_0_02";
    DatasetTypeMap[ 185724 ] =  "VBS_WV_0_m01";
    DatasetTypeMap[ 185725 ] =  "VBS_WV_0_m02";
    DatasetTypeMap[ 185726 ] =  "VBS_WV_01_0";
    DatasetTypeMap[ 185727 ] =  "VBS_WV_01_01";
    DatasetTypeMap[ 185728 ] =  "VBS_WV_01_m02";
    DatasetTypeMap[ 185729 ] =  "VBS_WV_01_m04";
    DatasetTypeMap[ 185730 ] =  "VBS_WV_02_m03";
    DatasetTypeMap[ 185731 ] =  "VBS_WV_03_m02";
    DatasetTypeMap[ 185732 ] =  "VBS_WV_03_m06";
    DatasetTypeMap[ 185733 ] =  "VBS_WV_m01_0";
    DatasetTypeMap[ 185734 ] =  "VBS_WV_m01_02";
    DatasetTypeMap[ 185735 ] =  "VBS_WV_m01_04";
    DatasetTypeMap[ 185736 ] =  "VBS_WV_m01_m01";
    DatasetTypeMap[ 185737 ] =  "VBS_WV_m02_03";
    DatasetTypeMap[ 185738 ] =  "VBS_WV_m03_02";
    DatasetTypeMap[ 185739 ] =  "VBS_WV_m03_06";
    DatasetTypeMap[ 185740 ] =  "VBS_WV_01_m01";
    DatasetTypeMap[ 185741 ] =  "VBS_WV_m01_01";
    DatasetTypeMap[ 185742 ] =  "VBS_WV_005_005";
    DatasetTypeMap[ 185743 ] =  "VBS_WV_005_0";
    DatasetTypeMap[ 185744 ] =  "VBS_WV_005_m005";
    DatasetTypeMap[ 185745 ] =  "VBS_WV_0_005";
    DatasetTypeMap[ 185746 ] =  "VBS_WV_0_m005";
    DatasetTypeMap[ 185747 ] =  "VBS_WV_m005_005";
    DatasetTypeMap[ 185748 ] =  "VBS_WV_m005_0";
    DatasetTypeMap[ 185749 ] =  "VBS_WV_m005_m005";
    DatasetTypeMap[ 185750 ] =  "VBS_WV_03_03";
    DatasetTypeMap[ 185751 ] =  "VBS_WV_03_0";
    DatasetTypeMap[ 185752 ] =  "VBS_WV_03_m03";
    DatasetTypeMap[ 185753 ] =  "VBS_WV_0_03";
    DatasetTypeMap[ 185754 ] =  "VBS_WV_0_m03";
    DatasetTypeMap[ 185755 ] =  "VBS_WV_m03_03";
    DatasetTypeMap[ 185756 ] =  "VBS_WV_m03_0";
    DatasetTypeMap[ 185757 ] =  "VBS_WV_m03_m03";
    DatasetTypeMap[ 185758 ] =  "VBS_ZV_0_0";
    DatasetTypeMap[ 185759 ] =  "VBS_ZV_0_01";
    DatasetTypeMap[ 185760 ] =  "VBS_ZV_0_02";
    DatasetTypeMap[ 185761 ] =  "VBS_ZV_0_m01";
    DatasetTypeMap[ 185762 ] =  "VBS_ZV_0_m02";
    DatasetTypeMap[ 185763 ] =  "VBS_ZV_01_0";
    DatasetTypeMap[ 185764 ] =  "VBS_ZV_01_01";
    DatasetTypeMap[ 185765 ] =  "VBS_ZV_01_m02";
    DatasetTypeMap[ 185766 ] =  "VBS_ZV_01_m04";
    DatasetTypeMap[ 185767 ] =  "VBS_ZV_02_m03";
    DatasetTypeMap[ 185768 ] =  "VBS_ZV_03_m02";
    DatasetTypeMap[ 185769 ] =  "VBS_ZV_03_m06";
    DatasetTypeMap[ 185770 ] =  "VBS_ZV_m01_0";
    DatasetTypeMap[ 185771 ] =  "VBS_ZV_m01_02";
    DatasetTypeMap[ 185772 ] =  "VBS_ZV_m01_04";
    DatasetTypeMap[ 185773 ] =  "VBS_ZV_m01_m01";
    DatasetTypeMap[ 185774 ] =  "VBS_ZV_m02_03";
    DatasetTypeMap[ 185775 ] =  "VBS_ZV_m03_02";
    DatasetTypeMap[ 185776 ] =  "VBS_ZV_m03_06";
    DatasetTypeMap[ 185777 ] =  "VBS_ZV_01_m01";
    DatasetTypeMap[ 185778 ] =  "VBS_ZV_m01_01";
    DatasetTypeMap[ 185779 ] =  "VBS_ZV_005_005";
    DatasetTypeMap[ 185780 ] =  "VBS_ZV_005_0";
    DatasetTypeMap[ 185781 ] =  "VBS_ZV_005_m005";
    DatasetTypeMap[ 185782 ] =  "VBS_ZV_0_005";
    DatasetTypeMap[ 185783 ] =  "VBS_ZV_0_m005";
    DatasetTypeMap[ 185784 ] =  "VBS_ZV_m005_005";
    DatasetTypeMap[ 185785 ] =  "VBS_ZV_m005_0";
    DatasetTypeMap[ 185786 ] =  "VBS_ZV_m005_m005";
    DatasetTypeMap[ 185787 ] =  "VBS_ZV_03_03";
    DatasetTypeMap[ 185788 ] =  "VBS_ZV_03_0";
    DatasetTypeMap[ 185789 ] =  "VBS_ZV_03_m03";
    DatasetTypeMap[ 185790 ] =  "VBS_ZV_0_03";
    DatasetTypeMap[ 185791 ] =  "VBS_ZV_0_m03";
    DatasetTypeMap[ 185792 ] =  "VBS_ZV_m03_03";
    DatasetTypeMap[ 185793 ] =  "VBS_ZV_m03_0";
    DatasetTypeMap[ 185794 ] =  "VBS_ZV_m03_m03";
    
    DatasetTypeMap[ 207266 ] =  "VBS_WV_003_003";
    DatasetTypeMap[ 207267 ] =  "VBS_WV_003_0";
    DatasetTypeMap[ 207268 ] =  "VBS_WV_003_m003";
    DatasetTypeMap[ 207269 ] =  "VBS_WV_0_003";
    DatasetTypeMap[ 207270 ] =  "VBS_WV_0_m003";
    DatasetTypeMap[ 207271 ] =  "VBS_WV_m003_003";
    DatasetTypeMap[ 207272 ] =  "VBS_WV_m003_0";
    DatasetTypeMap[ 207273 ] =  "VBS_WV_m003_m003";
    DatasetTypeMap[ 207274 ] =  "VBS_ZV_003_003";
    DatasetTypeMap[ 207275 ] =  "VBS_ZV_003_0";
    DatasetTypeMap[ 207276 ] =  "VBS_ZV_003_m003";
    DatasetTypeMap[ 207277 ] =  "VBS_ZV_0_003";
    DatasetTypeMap[ 207278 ] =  "VBS_ZV_0_m003";
    DatasetTypeMap[ 207279 ] =  "VBS_ZV_m003_003";
    DatasetTypeMap[ 207280 ] =  "VBS_ZV_m003_0";
    DatasetTypeMap[ 207281 ] =  "VBS_ZV_m003_m003";
    

    /*    
    DatasetTypeMap[ 185721 ] = "VBS_WV_0_0";     // MC12.185721.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_0_a5_0
    DatasetTypeMap[ 185723 ] = "VBS_WV_0_02";    // MC12.185723.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_00_a5_02
    DatasetTypeMap[ 185725 ] = "VBS_WV_0_m02";    
    DatasetTypeMap[ 185751 ] = "VBS_WV_03_0";    // MC12.185751.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_03_a5_0
    DatasetTypeMap[ 185758 ] = "VBS_ZV_0_0";     // MC12.185758.WhizardPythia8_AU2_CT10_ZVsemileptonic_km_a4_0_a5_0
    DatasetTypeMap[ 185760 ] = "VBS_ZV_0_02";    // MC12.185760.WhizardPythia8_AU2_CT10_ZVsemileptonic_km_a4_00_a5_02
    DatasetTypeMap[ 185788 ] = "VBS_ZV_03_0";    // MC12.185788.WhizardPythia8_AU2_CT10_ZVsemileptonic_km_a4_03_a5_0
    DatasetTypeMap[ 185726 ] = "VBS_WV_01_0";    // MC12.185726.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_01_a5_00
    DatasetTypeMap[ 185733 ] = "VBS_WV_m01_0";   // MC12.185733.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_m01_a5_00
    DatasetTypeMap[ 185743 ] = "VBS_WV_005_0";   // MC12.185743.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_005_a5_0
    DatasetTypeMap[ 185748 ] = "VBS_WV_m005_0";  // MC12.185748.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_m005_a5_0
    DatasetTypeMap[ 185756 ] = "VBS_WV_m03_0";   // MC12.185756.WhizardPythia8_AU2_CT10_WVsemileptonic_km_a4_m03_a5_0
    */

    DatasetTypeMap[ 185894 ] = "WWSM";        //mc12_8TeV.185894.McAtNloJimmy_AUET2CT10_WW_V_V_WZtoLeptonFilter.merge.NTUP_COMMON.e3364_s1773_s1776_r4485_r4540_p1680/
    DatasetTypeMap[ 185895 ] = "WpZSM";
    DatasetTypeMap[ 185896 ] = "WmZSM";
    DatasetTypeMap[ 185897 ] = "WWaTGC";     //mc12_8TeV.185897.McAtNloJimmy_AUET2CT10_WW_V_V_m0p3_1p0_0p3_WZtoLeptonFilter.merge.NTUP_COMMON.e3364_s1773_s1776_r4485_r4540_p1680/
    DatasetTypeMap[ 185898 ] = "WpZaTGC";
    DatasetTypeMap[ 185899 ] = "WmZaTGC";

  
  }
  

}



#endif // END SAMPLEMETADATA_H
