#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <TLorentzVector.h>
#include <math.h>
#include <assert.h>


#include "MiniObjSelector.h"
#include "SelectionTools.h"

#define ObjDEBUG 0


using namespace std;
//using namespace constants;


MiniObjSelector::MiniObjSelector(foo* thisfoo , CutFlowTool* thisct, const TString& option)
{
  // Initialization

  m_option = option ;
  h1       = thisfoo ;
  m_ct     = thisct ;

  m_useCombNN   = true  ; 
  m_useIP3DSV1  = false ; 
  m_useSV0      = false ; 
  

  

  //if (ObjDEBUG) cout << isGood << endl;

}

MiniObjSelector::~MiniObjSelector(){}


// The rest of function go here



void MiniObjSelector::findVBFTaggingJets( vector<TLorentzVector> *m_jets, std::pair<int, int> *vbfjetsIndex,  const std::pair<int, int> *WjetsIndex,
					  float jetpTCut, float min_mjj, float min_dyjj, float leadingJetPt, vector<TLorentzVector> *m_fatjets,
					  float ptfatjet_Cut, float fatjet_minm, float fatjet_maxm, bool doFJ)
{
  
  // from Rikard.Sandstrom@cern.ch
  

  vbfjetsIndex->first = -1;
  vbfjetsIndex->second = -1;
  double tagjj_FOM = -1; //figure-of-merit to decide which jets are tagging jets (e.g. m(jj) or Deta(jj))
  
  if(doFJ){
    
    //for fat jet case
    
    int idxfat= WjetsIndex->first;  //this is the index of the fat-jet, which should have already been found using the findWjetsNew function
    
    assert(idxfat >= 0  && (WjetsIndex->second == -1) );
    
    if(idxfat >= 0){
      
      for (unsigned int i=0; i<(*m_jets).size()-1; ++i) {  /// looping till (*m_jets).size()-1. Because later j=i+1    
        
	if ( (*m_jets).at(i).DeltaR( (*m_fatjets).at(idxfat) ) < constants::dRFJregjetORCut ) { continue; }
	
	if ((*m_jets).at(i).Pt()<jetpTCut) continue;
	
	for (unsigned int j=i+1; j<(*m_jets).size(); ++j) {
	  
	  if ( (*m_jets).at(j).DeltaR( (*m_fatjets).at(idxfat) ) < constants::dRFJregjetORCut ) { continue; }
	  
	  if ((*m_jets).at(j).Pt()<jetpTCut) continue;
	  
	  TLorentzVector tagjj_tlv = (*m_jets).at(i) + (*m_jets).at(j);
	  
	  
	  if ( 
	      ( vbfFOM( (*m_jets).at(i),(*m_jets).at(j) )  > tagjj_FOM )  //Largest figure-of-merit
	      && (tagjj_tlv.M()>min_mjj)   /// Mass passes threshold
	       && ( ((*m_jets).at(i).Pt()>leadingJetPt) || ((*m_jets).at(j).Pt()>leadingJetPt) ) /// We may want one of the vbf jets to pass the cut on leadingJetPt
	       && (fabs((*m_jets).at(i).Rapidity()-(*m_jets).at(j).Rapidity())>min_dyjj) /// Separation in rapidity
	       ){
	    
	    tagjj_FOM = vbfFOM( (*m_jets).at(i),(*m_jets).at(j) );
	    
	    
	    if ((*m_jets)[i].Pt()>(*m_jets)[j].Pt()) {
	      vbfjetsIndex->first  = i;
	      vbfjetsIndex->second = j;
	    } else {	
	      vbfjetsIndex->first  = j;
	      vbfjetsIndex->second = i;
	    }
	    
	  }
	  
	} //end loop over jet j
      } //end loop over jet i
      
    } //end if(idxfat>=0)
    
  }//end for fat jet case
  else{
    
    //start resolved jets
    bool resolvedWjetsFound=false;
    if(WjetsIndex->first>=0 && WjetsIndex->second>=0){
      resolvedWjetsFound=true;
    }

    if ( ((*m_jets).size()>=4) ) {
      
      for (unsigned int i=0; i<(*m_jets).size()-1; ++i) { /// looping till (*m_jets).size()-1. Because later j=i+1    
	
	if (resolvedWjetsFound && (i==(unsigned int)WjetsIndex->first || i==(unsigned int)WjetsIndex->second) ) continue;//remove W jets  

	if ((*m_jets).at(i).Pt()<jetpTCut) continue;
	
	for (unsigned int j=i+1; j<(*m_jets).size(); ++j) {

	  if (resolvedWjetsFound && (j==(unsigned int)WjetsIndex->first || j==(unsigned int)WjetsIndex->second) ) continue;//remove W jets  
	  
	  if ((*m_jets).at(j).Pt()<jetpTCut) continue;
	  
	  TLorentzVector tagjj_tlv = (*m_jets).at(i) + (*m_jets).at(j);

	  
	  if ( 
	      ( vbfFOM( (*m_jets).at(i), (*m_jets).at(j) ) > tagjj_FOM )  /// Largest figure-of-merit
	      && (tagjj_tlv.M()>min_mjj)   /// Mass passes threshold
	      && ( ((*m_jets).at(i).Pt()>leadingJetPt) || ((*m_jets).at(j).Pt()>leadingJetPt) ) /// We may want one of the vbf jets to be the leading jet
	      && (fabs((*m_jets).at(i).Rapidity()-(*m_jets).at(j).Rapidity())>min_dyjj) /// Separation in rapidity
	       ){
	    
	    
	    tagjj_FOM = vbfFOM( (*m_jets).at(i), (*m_jets).at(j) );
	    
	    
	    if ((*m_jets)[i].Pt()>(*m_jets)[j].Pt()) {
	      vbfjetsIndex->first  = i;
	      vbfjetsIndex->second = j;
	    } else {	
	      vbfjetsIndex->first  = j;
	      vbfjetsIndex->second = i;
	    }
	    
	  }
	  
	} //end loop over jet j
      } //end loop over jet i
      
      
    } //end if njets=4


  }   //end resolved jets
  
  return;
}



double MiniObjSelector::vbfFOM(TLorentzVector jet1, TLorentzVector jet2){
  //This is the function that calculates the figure-of-merit (mjj or Deta(jj), for example) used to decide which jets
  //are the tagging jets.  Make sure that this function always returns a number >=0, and that larger values are "better"
  
  double value=-1;
  
  if(constants::vbfTaggingMethod==0){
    TLorentzVector jetcombo = jet1 + jet2;
    value = jetcombo.M();
  }
  else if(constants::vbfTaggingMethod==1){
    value = fabs( jet1.Eta()-jet2.Eta() );
  }
  else{
    cout<<"vbfTaggingMethod = "<<constants::vbfTaggingMethod<<" not supported!"<<endl;
    assert(0);
  }

  return value;

}

/*
void MiniObjSelector::findWJets( vector<TLorentzVector> *m_jets, vector<TLorentzVector> *m_fatjets, 
				 const std::pair<int, int> *vbfjetsIndex, 
				 std::pair<int, int> *WjetsIndex, 
				 float jetpTCut, float leadingJetPt ) 
{
  
  WjetsIndex->first = -1;
  WjetsIndex->second = -1;


  // -- Normal jets
  std::pair<int, int> TmpIndex; TmpIndex.first = -1; TmpIndex.second = -1;
  double wjj_mini = 99999999999.;
  int jetsize = (*m_jets).size();
  for ( int i=0; i<jetsize-1; ++i) {
      
    if ((*m_jets).at(i).Pt()<jetpTCut) continue;
    if (i==vbfjetsIndex->first || i==vbfjetsIndex->second) continue;
    
    
    for ( int j=i+1; j<jetsize; ++j) {
      
      if ((*m_jets).at(j).Pt()<jetpTCut) continue;
      if (j==vbfjetsIndex->first || j==vbfjetsIndex->second) continue;

      TLorentzVector tagjj_tlv = (*m_jets).at(i) + (*m_jets).at(j);
      double massDiffW = fabs( tagjj_tlv.M() - constants::MassW  );

      if ( (  massDiffW < wjj_mini) 
	   && ( ((*m_jets).at(i).Pt()>leadingJetPt) || ((*m_jets).at(j).Pt()>leadingJetPt) ) /// Leading jet pt
	   ){

	wjj_mini = massDiffW;
	  
	if ((*m_jets)[i].Pt()>(*m_jets)[j].Pt()) {
	  TmpIndex.first  = i;
	  TmpIndex.second = j;
	} else {	
	  TmpIndex.first  = j;
	  TmpIndex.second = i;
	}
	
      }
    }
  }

  // -- Fat jets
  double fatjet_mini = 99999999999.;
  int fatjet_wjet_index = -1 ; 
  for ( unsigned int i=0; i<(*m_fatjets).size(); i++){
  double massDiffW = fabs( (*m_fatjets).at(i).M() - constants::MassW);
    if ( (massDiffW < fatjet_mini) 
	 && ( (*m_fatjets).at(i).Pt() > leadingJetPt )
	 )
      {
	fatjet_mini = massDiffW ; 
	fatjet_wjet_index = i;
      }
  }

  // --
  if (  fatjet_mini <  wjj_mini ) {
    WjetsIndex->first  = fatjet_wjet_index;
    WjetsIndex->second = -1;
  }
  else{
    WjetsIndex->first  = TmpIndex.first  ;
    WjetsIndex->second = TmpIndex.second ;
  }
  
  
  return;
}
*/


bool MiniObjSelector::findWJetsNew( vector<TLorentzVector> *m_jets, 
				    vector<TLorentzVector> *m_fatjets, 
				    const std::pair<int, int> *vbfjetsIndex, 
				    std::pair<int, int> *WjetsIndex, 
				    float jetpTCut, float ptfatjet_Cut,
				    float fatjet_minm, float fatjet_maxm,
				    bool &useFJ) 
{

  /* from Hass Abouzeid <Hass.Abouzeid@cern.ch> */
  bool passWjetsSelection(false);


  double dijetpTCut = 0.0;  //for resolved-jet case, require minimum pT(jj).  putting a cut in this function
                              //has a different effect than a cut minihbb, since putting a cut here allows for
                              //the possibility of a different jet-pair passing the pT(jj) cut.

  WjetsIndex->first = -1;
  WjetsIndex->second = -1;
  
  //have VBF jets already been chosen?                                                                                                               
  bool vbfjetsFound=false;
  if(vbfjetsIndex->first>=0 && vbfjetsIndex->second>=0){
    vbfjetsFound=true;
  }
  
  assert(vbfjetsFound==false);  //fat-jet code is only designed to work when vbfjets have not been found yet.   
  
  
  //cout << "1 jet size="  << (*m_jets).size() << endl; 

  if(!useFJ){
    //resolved W-jets selection
    
    //--- Find W Jet pair 
    int idx1=-1;
    int idx2=-1;
    double bestMatch = -0.00001;
    // For ambiguity solving
    vector<pair<int, int> > vIdx; //all pairs with mass within 15 GeV of MassW
    
    
    if (  (*m_jets).size() >=4 ) { ///originally was 2
      
      for(unsigned int i=0; i < (*m_jets).size()-1; i++){ /// looping till (*m_jets).size()-1. Because later j=i+1
	//cout<<"---------"<<endl;
	if ((*m_jets).at(i).Pt()<jetpTCut) continue;
	if (vbfjetsFound  && (i==(unsigned int)vbfjetsIndex->first || i==(unsigned int)vbfjetsIndex->second) ) continue;//remove tagged jets
	
	for(unsigned int j = i+1; j<(*m_jets).size(); j++){
	  
	  if ((*m_jets).at(j).Pt()<jetpTCut) continue;
	  if (vbfjetsFound && (j==(unsigned int)vbfjetsIndex->first || j==(unsigned int)vbfjetsIndex->second) ) continue;
	  
	  //	if((*m_jets).at(i).Pt() < 100 && (*m_jets).at(j).Pt() < 100){
	  //  continue; //require at least one of the two W-jets to have pT>100 GeV.
	  //	}
	  
	  //cout<<"jetpt["<<i<<"] "<<(*m_jets).at(i).Pt()<<endl;
	  //cout<<"jet2pt["<<j<<"] "<<(*m_jets).at(j).Pt()<<endl;
	  
	  double dijetPt  = ( (*m_jets).at(i) + (*m_jets).at(j) ).Pt();
	  if(dijetPt<dijetpTCut){
	    continue;
	  }
	  
	  double dijetMass =( (*m_jets).at(i) + (*m_jets).at(j) ).M();
	  //cout<<"mjj= "<<dijetMass<<endl;
	  
	  
	  // Check if within W mass window
	  if(fabs(dijetMass-constants::MassW)<15.){
	    vIdx.push_back(pair<int, int>(i,j));// all pairs with mass within 15 GeV of MassW
	    //cout<<"pair with mass in 65,96: (i,j)= ("<<i<<","<<j<<")"<<endl;
	    //cout<<"mjj= "<< ( (*m_jets).at(i) + (*m_jets).at(j) ).M() <<endl;
	  }
	  //cout<<"(idx1,idx2)= ("<<idx1<<","<<idx2<<")"<<endl;
	  
	  if(fabs(dijetMass-constants::MassW)<bestMatch||bestMatch<0){//choose the pair closest to MassW 
	    bestMatch = fabs(dijetMass-constants::MassW);
	    //if (bestMatch<15){///auzaman added this condition, will force all pairs to be within 15 GeV of W-mass
	    double pt1=(*m_jets).at(i).Pt();
	    double pt2=(*m_jets).at(j).Pt();
	    if(pt1>pt2){ 
	      idx1=i; 
	      idx2=j;
	    }else{
	      idx1=j;
	      idx2=i; ///right now idx1,2 are the pair of jets with mjj closest to W-mass, not necessarily within 15 GeV of W-mass
	    }
	    //}
	  }
	  //cout<<"(idx1,idx2)= ("<<idx1<<","<<idx2<<")"<<endl;
	}
	
	//cout<<"closest to Wmass (idx1,idx2)= ("<<idx1<<","<<idx2<<")"<<endl;
	//cout<<"mjj(idx1,idx2)= "<< ( (*m_jets).at(idx1) + (*m_jets).at(idx2) ).M() <<endl;
	//if (idx1>0 && idx2>0)cout<<"mjj(idx1,idx2)= "<< ( (*m_jets).at(idx1) + (*m_jets).at(idx2) ).M() <<endl;
      }
      
      
      //cout << "2" << endl; 
      
      //--- First check to see if any are in W Mass window
      //    If so, we take the highest Pt pair
      for(unsigned int i=0; i < vIdx.size() ; i++ ){
	//cout<<"*********"<<endl;
	double pt1=(*m_jets).at(vIdx[i].first ).Pt();
	double pt2=(*m_jets).at(vIdx[i].second).Pt();
	
	//    /*
	//	original method  ==> seems to work better than choosing pair with highest vector pt sum, or with highest scalar pt sum.
	//        in any case, the different methods only have a ~few percent effect, so it doesn't matter much which one is chosen.
	if(((pt1 >= (*m_jets).at(idx1).Pt())&&(pt2 >= (*m_jets).at(idx2).Pt()))||
	   ((pt2 >= (*m_jets).at(idx1).Pt())&&(pt1 >= (*m_jets).at(idx2).Pt()))){
	  
	  if(pt1>pt2){
	    idx1 = vIdx[i].first;
	    idx2 = vIdx[i].second;  ///if there are more than one candidate pairs in the mass window, we choose the highest pt pair
	  }
	  else{
	    idx2 = vIdx[i].first;
	    idx1 = vIdx[i].second;
	  }
	}
	//      */
	
      }
      //cout<<"finally (idx1,idx2)= ("<<idx1<<","<<idx2<<")"<<endl;
      //cout<<"finally mjj(idx1,idx2)= "<< ( (*m_jets).at(idx1) + (*m_jets).at(idx2) ).M() <<endl;
    } //end if njets >= 4
    
    WjetsIndex->first  = idx1;  //index of higher-pT w-jet candidate.                               
    WjetsIndex->second = idx2;  //index of lower-pT w-jet candidate.
    if ((idx1!=-1)&&(idx2!=-1)) passWjetsSelection = true;
    
  }// end if(!useFJ)    
  else{
    
    // ---------------------
    // Fat Jets
    // ---------------------
    
    int idxfat=-1;
    //double ptfatjet_Cut = 300;
    double deltam_min  = 100000;  //initialize this to huge number
    //double fatjet_minm = 60;
    //double fatjet_maxm = 110;
    
    if ( ( (*m_jets).size()>=2 && (*m_fatjets).size()>0 )  ) {
      
      //choose fatjet with mjj closest to W-mass that has pT>ptfatjet_Cut
      for (unsigned int i=0; i<(*m_fatjets).size(); ++i) {
	
	if(  fabs( (*m_fatjets).at(i).Eta() ) > constants::etaFJCut ){
	  continue;
	}
	
	
	double fjmass = (*m_fatjets).at(i).M();
	//      if (  (*m_fatjets).at(i).Pt()  > ptfatjet_Cut  &&  (fjmass >  fatjet_minm)  &&  (fjmass < fatjet_maxm) && ( fabs(fjmass-constants::MassW)   < deltam_min) ){
	if (  (*m_fatjets).at(i).Pt()  > ptfatjet_Cut  &&  ( fabs(fjmass-constants::MassW)   < deltam_min) ){
	  deltam_min = fjmass;
	  idxfat = i;
	}
      }
      
    }
    
    
    WjetsIndex->first  = idxfat; ///m_fatjets index  
    WjetsIndex->second = -1;
    if (idxfat!=-1) passWjetsSelection = true;
    
  }// end if(useFJ)
  
  
  return passWjetsSelection;

}





void MiniObjSelector::SetNeutrinoPz()
{
  
  // from Rikard.Sandstrom@cern.ch

  const float WMASS=constants::MassW*1000.; // MeV

  TLorentzVector l;
  l.SetPtEtaPhiE(  h1->lep_pt->at(0), 
		   h1->lep_eta->at(0), 
		   h1->lep_phi->at(0),
		   h1->lep_E->at(0)  );
    
  double lx = l.Px();
  double ly = l.Py();
  double lz = l.Pz();

  // Calculate neutrino momentum

  double nx = h1->MET_x;
  double ny = h1->MET_y;
  double nz = 0.;

  double a =  4.*lx*lx
    +4.*ly*ly;
  double b = -4.*WMASS*WMASS*lz
    -8.*lx*nx*lz
    -8.*ly*ny*lz;
  double c = 4.*ly*ly*nx*nx
    + 4.*lz*lz*nx*nx
    + 4.*lx*lx*ny*ny
    + 4.*lz*lz*ny*ny
    - 8.*lx*nx*ly*ny
    - 4.*lx*nx*WMASS*WMASS
    - 4.*ly*ny*WMASS*WMASS
    - WMASS*WMASS*WMASS*WMASS;

  double discriminant = b*b - 4.*a*c;
  if (discriminant < 0.) discriminant=0.;

  double nz1 = -9999;
  double nz2 = -9999;
  if (a!=0) {
    nz1 = 0.5*(-b + TMath::Sqrt(discriminant)) / a;
    nz2 = 0.5*(-b - TMath::Sqrt(discriminant)) / a;
  }
  if (fabs(nz1) < fabs(nz2)) {
    nz = nz1;
  }
  else {
    nz = nz2;
  }
  

  h1->MET_z=nz;


  return;

  //return TLorentzVector(nx, ny, nz, TMath::Sqrt(nx*nx + ny*ny + nz*nz));

  
}






bool MiniObjSelector::passHiggsMLL( const int &mass ) 
{
  
  
  //if (  mass < 200  )
  //  {
  //    if ( h1->mLL < 50. ) return true ; 
  //  }
  //else
  //  {
  //    if ( h1->mLL < 150. ) return true ; 
  //  }
  

   return false ;

}

bool MiniObjSelector::passHiggsDPhiLL( const int &mass ) 
{
  

  
  //if (  mass < 200  )
  //  {
  //    if ( h1->dPhiLL < 1.8 ) return true ; 
  //  }
  //else
  //  {
  //    return true ; 
  //  }
  
  

   return false ;

}


bool MiniObjSelector::passHiggsHwwMT( const int &mass ) 
{
  

  //if (  mass < 200  )
  //  {
  //    if (  (h1->HwwMt > 0.75*mass) && ( h1->HwwMt < mass)   ) return true ;  
  //  }
  //else
  //  {
  //    if (  (h1->HwwMt > 0.60*mass) && ( h1->HwwMt < mass)   ) return true ; 
  //  }
  

   return false ;

}



float MiniObjSelector::getZttMassFromBillQ()
{

  //TLorentzVector Lep1, Lep2, LepSum; 
  //
  //Lep1.SetPtEtaPhiE( h1->lep1_pt, h1->lep1_eta, h1->lep1_phi, h1->lep1_e );
  //Lep2.SetPtEtaPhiE( h1->lep2_pt, h1->lep2_eta, h1->lep2_phi, h1->lep2_e );
  //
  //LepSum = Lep1 + Lep2 ;
  //
  //TLorentzVector vmet ; 
  //vmet.SetPtEtaPhiM( h1->MET_et, 0., h1->MET_phi, 0. ) ; 
  //
  //float Mll  = LepSum.M(); 
  //float n    = (-Lep1.Py()*Lep2.Px()+Lep1.Px()*Lep2.Py());
  //float sumX = (Lep1.Px()+Lep2.Px()+ vmet.Px() );
  //float sumY = (Lep1.Py()+Lep2.Py()+ vmet.Py() );
  //float xtau1 = (n/(sumX*Lep2.Py()-sumY*Lep2.Px()));
  //float xtau2 = (n/(sumY*Lep1.Px()-sumX*Lep1.Py()));
  //
  //float M_tautau = -999.; 
  //
  //if ( xtau1>0. && xtau2>0.)  M_tautau = (Mll/sqrt(xtau1*xtau2));

  
  //return M_tautau  ;


  return 0.;


}


float MiniObjSelector::TotalPt()
{

  //TLorentzVector Lep1, Lep2, LepSum; 
  //
  //Lep1.SetPtEtaPhiE( h1->lep1_pt, h1->lep1_eta, h1->lep1_phi, h1->lep1_e );
  //Lep2.SetPtEtaPhiE( h1->lep2_pt, h1->lep2_eta, h1->lep2_phi, h1->lep2_e );
  //
  //TLorentzVector MET ; 
  //MET.SetPtEtaPhiM( h1->MET_et, 0., h1->MET_phi, 0. ) ; 
  //
  //float PtTot = 0;
  //float PtTotx = 0;
  //float PtToty = 0;
  //
  //for(  int j=0; j<h1->nJet; j++  )  
  //  {
  //    if ( fabs(h1->jet_jvf->at(j)) < 0.75 ) continue ;
  //    TLorentzVector jet; jet.SetPtEtaPhiE( h1->jet_pt ->at(j), 
  //					    h1->jet_eta->at(j),
  //					    h1->jet_phi->at(j),
  //					    h1->jet_E  ->at(j) ) ;
  //    
  //    PtTotx += jet.Px() ;
  //    PtToty += jet.Py() ;
  //  }
  //
  //
  //PtTotx += Lep1.Px()  + Lep2.Px() + MET.Px() ;
  //PtToty += Lep1.Py()  + Lep2.Py() + MET.Py() ;
  //
  //PtTot = sqrt(PtTotx*PtTotx + PtToty*PtToty); 
  //
  //return  PtTot ; 


  return 0.;
  
}

int  MiniObjSelector::getVVcharges()
{

  //return:
  //0:  osWW, 1:  ssWW, 2: W+Z, 3: W-Z, 4: ZZ

  unsigned nparts = h1->mctruth_pdgId->size();
 
  int lepcharge=0;
  int hadboson =-1;

  for(unsigned ip=0; ip<nparts; ip++){
    
    int pdgId = h1->mctruth_pdgId->at(ip);
    //    int parent = h1->mctruth_parent->at(ip);

    if(pdgId ==23 || pdgId==24 || pdgId == -24){
      hadboson = pdgId;
    }

    cout<<"pdg = "<<pdgId<<endl; //" ; parent = "<<parent<<endl;
    
    if(pdgId==11 || pdgId==13 || pdgId==15){
      lepcharge--;
    }
    else if(pdgId==-11 || pdgId==-13 || pdgId==-15){
      lepcharge++;
    }
    
  }
  
  int bosoncharge = 0;
  if(hadboson==23){
    bosoncharge = 0;
  }
  else if(hadboson==24){
    bosoncharge = 1;
  }
  else if(hadboson==-24){
    bosoncharge = -1;
  }
  else{
    return -1;
  }

  cout<<"boson = "<<bosoncharge<<" ; lep = "<<lepcharge<<endl;

  if(bosoncharge*lepcharge < 0){
    return 0;
  }
  else if(bosoncharge*lepcharge > 0){
    return 1;
  }
  else if(bosoncharge==0 && lepcharge==0){
    return 4;
  }
  //in this case one boson is charged, and one boson is neutral
  else if(bosoncharge + lepcharge > 0){
    return 2;
  }
  else{
    return 3;
  }

}


