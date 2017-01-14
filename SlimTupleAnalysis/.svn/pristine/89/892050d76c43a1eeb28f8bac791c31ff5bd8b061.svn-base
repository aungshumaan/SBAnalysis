#ifndef SELECTIONTOOLS_H
#define SELECTIONTOOLS_H

// C++
#include <vector>

// ROOT     
#include <TLorentzVector.h>

//local
#include "foo.hh"

using namespace std;

namespace constants{

  const float Pi   = 3.1415926 ;
  const float MassZ = 91.1876 ; // GeV
  const float MassW = 80.385  ; // GeV
  const float GeV = 0.001 ;
  
  //https://twiki.cern.ch/twiki/bin/view/AtlasProtected/BTagCalib2014
  //60% WP:  0.9827, 70% WP:  0.7892, 80% WP:  0.3511, 85% WP:  0.1340   
  
  const double mv1SRCut = 0.1340;
  const double mv1TopCRCut = 0.9827;
  //const double mv1TopCRCut = 0.1340;
    
  const double mjjResolveHiCut=96.0;
  //  const double mjjResolveLoCut=65.0;
  const double mjjResolveLoCut=74.0;
  //const double mjjResolveHiCut=110.0;
  //const double mjjResolveLoCut=60.0;

  const double etaFJCut=1.2;  //|eta(fat-jet)|<cut
  const double dRFJlepORCut=1.2;  //dR(fat-jet,lepton) for overlap-removal
  const double dRFJregjetORCut=1.2; //dR(fat-jet, regular jet) for overlap-removal

  
  const bool doReducedPlots=true;  //if true, will only produce a small number of (important) plots.
  const int writeAsciiMode=-1;  // -1:  no ASCII output; 0:  Aungshuman's ASCII output; 1:  Brian's ASCII output

  const int vbfTaggingMethod=0;  //0:  choose tag-jets based on m(jj).  1:  choose tag-jets based on Deta(jj)
  
}

namespace SelectionTools{
    
  bool getTruePartonVectors(const foo* h1, TLorentzVector& true_Vjj, vector<TLorentzVector>& true_Vjets, vector<TLorentzVector>& true_otherjets, int& trueVpdgId);

  bool isDoubleCountedVWZ(const foo* h1);
  
}

#endif
