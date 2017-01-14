// This is  -*- C++ -*-

/*
 * @file   HistFiller.h
 * @author Haifeng Li 
 * @date   Sep 13, 2011
 * @brief  Fill histograms
 * @added many new histos Feb 5, 2014 Aungshuman
*/


#ifndef HISTFILLER_H
#define HISTFILLER_H


// C++
#include <vector>
#include <string>
#include <map>

// ROOT
#include <TFile.h>
#include <TH1.h>
#include <TLorentzVector.h> 

// Local 
#include "foo.hh"
#include "HistRun.h"
#include "AsciiRun.h"
#include "SelectionTools.h"

using namespace std ;




class HistFiller 
{ 
  
 public : 
  HistFiller( map <int , std::string> &DatasetTypeMap ,
	      string flavorChannel[], const int &nflavor , 
	      string DScategory[],    const int &nDSType ,
	      TFile *foutput = 0 , string systname ="Nominal"
	      ) ;
  
  int FillHistgrams( const string &channel,
		     const string &cut , // cut gets passed to getHist and MakeNewHist, specifying at which stage the histos need to be filled
		                         //and naming the histos accordingly
		     const int &RunNumber, 
		     const foo *h1, const double &eventWeight  );
  HistRun *getHist( const int &RunNumber, const string &channel ,  const string &cut  ) ;//getHist is a function that returns a pointer to a HistRun type object
  AsciiRun *getAscii( const int &RunNumber, const string &channel , const string &cut    );
  void MakeNewHist( const string &histName ,  const string &cut  ); //creates the first part of the histName using cut
  void MakeNewAscii( const string &txtName ,  const string &cut  ); 
  void CloseAsciiFiles();
  bool AsciiIsOn();
  void ReducedPlots(bool enable);
  double getCosThetaStar(TLorentzVector V1child, TLorentzVector V1, TLorentzVector V2);
  double getCentrality(double jet1eta, double jet2eta, double obj1eta, double obj2eta=-99999999999);
  double getMTWV(TLorentzVector diwjets, TLorentzVector lepton, TLorentzVector neutrino);
  
 private : 
  
  
  TFile * m_foutput ; 
  map <int , std::string>  *m_DatasetTypeMap ; 
  map<std::string, HistRun*>   m_HistNameMap ; 
  map<std::string, AsciiRun*>   m_AsciiNameMap ; 

  string *m_flavorChannel ; 
  int     m_nflavor ; 
  string *m_DScategory  ;
  int     m_nDSType ;
  bool m_reducedPlots;

  float GeV ;

  string m_systname;

  //  bool isOtherSignal(const int &run);


} ; 





HistFiller::HistFiller( map <int , std::string> &DatasetTypeMap ,
			string flavorChannel[], const int &nflavor , 
			string DScategory[],    const int &nDSType ,
			TFile *foutput , string systname
			) 
{
  cout << " init HistFiller " << endl;
  m_reducedPlots=false;
  GeV = 0.001 ;

  m_foutput = foutput ; 
  m_DatasetTypeMap = &DatasetTypeMap ;//for the map see include/SampleMetaData.h
 
  
  m_flavorChannel = flavorChannel; 
  m_nflavor       = nflavor ; 
    
  m_DScategory    = DScategory ;
  m_nDSType       = nDSType  ;

  m_systname       = systname  ; ///added 4/28/15
  
  // test
  cout << "   Flavors : " ; 
  for ( int i=0; i<m_nflavor ; i++ ){
    cout << m_flavorChannel [i]  << ", ";
  }
  cout << endl; 
  
  cout << "   Dataset : " ; 
  for ( int j=0; j<m_nDSType ; j++ ){
    cout << m_DScategory [j] << ", ";
  }
  cout << endl;




}

int HistFiller::FillHistgrams( const string &channel,
			       const string &cut , 
			       const int &RunNumber, 
			       const foo *h1, const double &eventWeight  )
{

  
  if ( m_DatasetTypeMap->find(RunNumber) == m_DatasetTypeMap->end() ) {//if RunNumber is not in the map, exit.
    //cout<<"RunNumber: "<<RunNumber<<" not in the map\n";
    return 0 ; 
  }

  HistRun *thisHist = (HistRun*)getHist( RunNumber, channel , cut ) ; //thisHist is a pointer to a HistRun type object.
                                                                      //HistRun class contains all the initialized histograms
                                                                      //thisHist gets histoName using "getHist" given the RunNumber, channel and cut
  if (!thisHist) {
    cout << "HistFiller :: " << "Can not find the correct histogram pointer " << " RunNumber " << RunNumber << " Channel " << channel << endl;
    cout << "Check the DScategory list in minihbb.cxx, make sure it agrees with the list of input files."<<endl;
    exit(20);
  }

  AsciiRun *thisAscii;
  bool doShortAscii=false;
  
  ////&&&&
  if( AsciiIsOn() && (cut =="WBF_SR" || cut =="WBF_SRfatOnly")){ //For ratio plots fill out ascii files for only Signal Regions, too many open files caused some problem
    doShortAscii = true;
  } else{doShortAscii = false;}
  // std::cout<<"cut = "<<cut<<" "<<AsciiIsOn()<<" "<<doShortAscii<<endl; //happens every event, so cout is not a great idea"
  ////
  
  if(doShortAscii){
    thisAscii =  (AsciiRun*)getAscii( RunNumber, channel , cut ) ;
  }
  
  TString category = TString((*m_DatasetTypeMap)[RunNumber] ); //"Top","WZZZWgZjets","Wjets","H_ggF_125" etc
  TLorentzVector lepton; 
  lepton.SetPtEtaPhiE(  h1->lep_pt ->at(0)*GeV, 
			h1->lep_eta->at(0)  ,
			h1->lep_phi->at(0)  ,
			h1->lep_E  ->at(0)*GeV  ); 

  TLorentzVector neutrino; 
  float E_neutrino = TMath::Sqrt(h1->MET_x*h1->MET_x + h1->MET_y*h1->MET_y + h1->MET_z*h1->MET_z);
  neutrino.SetPxPyPzE(  h1->MET_x*GeV, 
			h1->MET_y*GeV, 
			h1->MET_z*GeV, 
			E_neutrino    *GeV );
  
  
  float val_ptwlep = (lepton + neutrino).Pt();
  float val_mT = sqrt(2*lepton.Pt()*neutrino.Pt()*(1-cos(fabs(lepton.DeltaPhi(neutrino)))));//DeltaPhi is a function of a TLorentzVector
  
    
  
  thisHist -> lep_pt  -> Fill( h1->lep_pt ->at(0)*GeV,  eventWeight );
  thisHist -> MET_et  -> Fill( h1->MET    * GeV , eventWeight );
  thisHist -> mT  -> Fill(val_mT  , eventWeight);
  thisHist -> ptwlep  -> Fill(val_ptwlep  , eventWeight);
  thisHist -> dPhilepMET -> Fill ( lepton.DeltaPhi(neutrino) ,eventWeight);
  
  thisHist -> runNumber ->Fill(h1->RunNumber, eventWeight);

  //isolation, d0 and z0 (7/29/15)
  
  if (abs(h1->lep_ID->at(0))==11 ){ //leading lepton is electron
    thisHist -> elRelEtCone30 ->Fill(h1->el_etcone30_0/h1->lep_pt->at(0), eventWeight);
    thisHist -> elRelPtCone30 ->Fill(h1->el_ptcone30_0/h1->lep_pt->at(0), eventWeight);
    if (h1->el_etcone30_0/h1->lep_pt->at(0) > 0)thisHist -> log_elRelEtCone30 ->Fill(TMath::Log10( h1->el_etcone30_0/h1->lep_pt->at(0) ), eventWeight);
    thisHist -> log_elRelPtCone30 ->Fill(TMath::Log10( h1->el_ptcone30_0/h1->lep_pt->at(0) ), eventWeight);
    thisHist -> elz0sinth ->Fill(h1->el_z0sinth_0, eventWeight);
    thisHist -> eld0sigd0 ->Fill(fabs(h1->el_d0_0/h1->el_sigd0_0  ), eventWeight);

    if (h1->el_ptcone30_0/h1->lep_pt->at(0) < 0.2){
      //cout<<"Hello!! "<< h1->MET  * GeV << " "  <<h1->el_ptcone30_0/h1->lep_pt->at(0)<<endl;
      thisHist-> MET_elRelPtCone30_lt02 -> Fill(  h1->MET  * GeV , eventWeight);   //MET distribution given ptcone30/pt < 0.2
    }
    
    //cout<<"elEtCone30 = "<<h1->el_etcone30_0<<endl;
    //cout<<"elPtCone30 = "<<h1->el_ptcone30_0<<endl;
    //cout<<"elRelEtCone30 = "<<h1->el_etcone30_0/h1->lep_pt->at(0)<<endl;
    //cout<<"elRelPtCone30 = "<<h1->el_ptcone30_0/h1->lep_pt->at(0)<<endl;
    //cout<<"elz0sinth  = "<< h1->el_z0sinth_0 <<endl;
    //cout<<"eld0sigd0  = "<< fabs(h1->el_d0_0/h1->el_sigd0_0 ) <<endl;
  }


  if (abs(h1->lep_ID->at(0))==13 ){ //leading lepton is muon
    thisHist -> muRelEtCone30 ->Fill(h1->mu_etcone30_0/h1->lep_pt->at(0), eventWeight);
    thisHist -> muRelPtCone30 ->Fill(h1->mu_ptcone30_0/h1->lep_pt->at(0), eventWeight);
    if (h1->mu_etcone30_0/h1->lep_pt->at(0) > 0)thisHist -> log_muRelEtCone30 ->Fill(TMath::Log10( h1->mu_etcone30_0/h1->lep_pt->at(0) ), eventWeight);
    thisHist -> log_muRelPtCone30 ->Fill(TMath::Log10( h1->mu_ptcone30_0/h1->lep_pt->at(0) ), eventWeight);
    thisHist -> muz0sinth ->Fill(h1->mu_z0sinth_0, eventWeight);
    thisHist -> mud0sigd0 ->Fill(fabs(h1->mu_d0_0/h1->mu_sigd0_0  ), eventWeight);

    if (h1->mu_ptcone30_0/h1->lep_pt->at(0) < 0.2){
      thisHist-> MET_muRelPtCone30_lt02 -> Fill(  h1->MET  * GeV , eventWeight);   //MET distribution given ptcone30/pt < 0.2
    }
    
    
    //cout<<"muEtCone30 = "<<h1->mu_etcone30_0<<endl;
    //cout<<"muPtCone30 = "<<h1->mu_ptcone30_0<<endl;
    //cout<<"muRelEtCone30 = "<<h1->mu_etcone30_0/h1->lep_pt->at(0)<<endl;
    //cout<<"muRelPtCone30 = "<<h1->mu_ptcone30_0/h1->lep_pt->at(0)<<endl;
    //cout<<"muz0sinth  = "<< h1->mu_z0sinth_0 <<endl;
    //cout<<"mud0sigd0  = "<< fabs(h1->mu_d0_0/h1->mu_sigd0_0 ) <<endl;
  }


  if(!m_reducedPlots){
    thisHist -> lep_eta -> Fill( h1->lep_eta->at(0)  ,  eventWeight );
    thisHist -> lep_phi -> Fill( h1->lep_phi->at(0)  ,  eventWeight );

  
    

    ///mT investigation. ptWlep and dPhilepMET sliced 
    if( abs(lepton.DeltaPhi(neutrino)) <= 1.4) {thisHist -> mT_dPhilepMET_lt14 -> Fill ( val_mT ,eventWeight);}
    else {thisHist -> mT_dPhilepMET_gt14 -> Fill ( val_mT ,eventWeight);}

    if( val_ptwlep <= 50) {thisHist -> mT_ptwlep_lt50 -> Fill ( val_mT ,eventWeight);}
    else if( val_ptwlep > 50 && val_ptwlep <=100) {thisHist -> mT_ptwlep_50_100 -> Fill ( val_mT ,eventWeight);}
    else if( val_ptwlep > 100 && val_ptwlep <=150) {thisHist -> mT_ptwlep_100_150 -> Fill ( val_mT ,eventWeight);}
    else {thisHist -> mT_ptwlep_gt150 -> Fill ( val_mT ,eventWeight);}
  

    thisHist -> mT_ptwlep -> Fill (val_mT ,val_ptwlep ,  eventWeight);

  }

  //cout<<"val_mT = "<<val_mT<<", val_ptwlep = "<<val_ptwlep<<endl;
  //thisHist -> mT_ptwlep -> Fill (val_mT ,val_ptwlep ,  eventWeight);



  // */
  
  // if ( category.BeginsWith("Data")){
  //   //cout<<"category= "<<category<<endl;
  //   if (divbfjets.M()<1500)thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }else{
  //   thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }
  ///////
  // /*


  if(h1->lep_n==2){

    TLorentzVector lepton2;
    lepton2.SetPtEtaPhiE(  h1->lep_pt ->at(1)*GeV,
			   h1->lep_eta->at(1)  ,
			   h1->lep_phi->at(1)  ,
			   h1->lep_E  ->at(1)*GeV  );

    
    double dilepMass = (lepton+lepton2).M();
    double dilepPt = (lepton+lepton2).Pt();

    if(!m_reducedPlots){
      thisHist -> mll  -> Fill( dilepMass,  eventWeight );  
      thisHist -> ptll  -> Fill( dilepPt,  eventWeight );  
      
      thisHist -> lep2_pt  -> Fill( lepton2.Pt(),  eventWeight );  
    }
  
  }

  


  ///////////////////////////////////////////////////
  //truth quantities

  //  double METdiff = (h1->MET - h1->MET_truth_nonint)*GeV;
  //  thisHist -> METdiff    -> Fill( METdiff, eventWeight );


  
  int mc_n= h1->mctruth_pdgId->size();
  //cout<<"mc_n = "<<mc_n<<endl;
  TLorentzVector true_lepton;
  
  for(int i=0;i<mc_n;i++){
    if ( abs(h1->mctruth_pdgId->at(i)) == 11 || abs(h1->mctruth_pdgId->at(i)) == 13 ){ //electron or muon
      true_lepton.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*GeV, 
				 h1->mctruth_eta ->at(i)  ,
				 h1->mctruth_phi ->at(i)  ,
				 h1->mctruth_m ->at(i)*GeV  ); 
    }
  }
  TLorentzVector true_neutrino;
  
  for(int i=0;i<mc_n;i++){
    if ( abs(h1->mctruth_pdgId->at(i)) == 12 || abs(h1->mctruth_pdgId->at(i)) == 14 ){ //electron or muon neutrino
      true_neutrino.SetPtEtaPhiM(  h1->mctruth_pt ->at(i)*GeV, 
				   h1->mctruth_eta ->at(i)  ,
				   h1->mctruth_phi ->at(i)  ,
				   h1->mctruth_m ->at(i)*GeV  ); 
    }
  }
  float val_dR_lepTrueLep = lepton.DeltaR(true_lepton);
  float val_dPhi_METtrueNu = neutrino.DeltaPhi(true_neutrino);
  float val_pt_trueLep = true_lepton.Pt();
  float val_pt_lepTrueLep = lepton.Pt() - true_lepton.Pt();
  float val_Et_trueNu =true_neutrino.Et();
  float val_Et_METtrueNu = neutrino.Et() - true_neutrino.Et();
  float val_dPhilv_true = true_lepton.DeltaPhi(true_neutrino);
  float val_mT_true = sqrt(2*true_lepton.Pt()*true_neutrino.Et()*(1-cos(fabs(true_lepton.DeltaPhi(true_neutrino)))));
  float val_mlv_true = (true_lepton+true_neutrino).M();


  int nTrueCquark=0;
  for(int i=0;i<mc_n;i++){
    if (abs(h1->mctruth_pdgId->at(i)) == 4 ){
      nTrueCquark++;
    }
  }

  if(!m_reducedPlots){
    
    thisHist -> nTrueB ->Fill(  h1->mctruth_Nbquarks , eventWeight );
    thisHist -> nTrueC -> Fill(nTrueCquark ,  eventWeight ) ;
    
    
    thisHist -> dR_lepTrueLep  -> Fill(val_dR_lepTrueLep ,  eventWeight ) ;
    thisHist -> dPhi_METtrueNu  -> Fill(val_dPhi_METtrueNu ,  eventWeight ) ;
    thisHist -> pt_trueLep  -> Fill(val_pt_trueLep ,  eventWeight ) ;
    thisHist -> Et_trueNu  -> Fill(val_Et_trueNu ,  eventWeight ) ;
    thisHist -> pt_lepTrueLep  -> Fill(val_pt_lepTrueLep ,  eventWeight ) ;
    thisHist -> Et_METtrueNu  -> Fill(val_Et_METtrueNu ,  eventWeight ) ;
    thisHist -> dPhilv_true  -> Fill(val_dPhilv_true ,  eventWeight ) ;
    thisHist -> mT_true  -> Fill(val_mT_true ,  eventWeight ) ;
    thisHist -> mlv_true  -> Fill(val_mlv_true ,  eventWeight ) ;
  }

  ///////end truth quantities
  ///////////////////////////////////////////////////




  vector<TLorentzVector> m_jets;
  for (int ijet=0; ijet<h1->jet_n; ijet++){
    TLorentzVector thisjet;
    thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
			  h1->jet_eta->at(ijet),
			  h1->jet_phi->at(ijet),
			  h1->jet_E  ->at(ijet)/1000. ) ;
    
    m_jets.push_back(thisjet);
    //    thisHist-> jet_emfrac -> Fill ( h1-> jet_emfrac ->at(ijet), eventWeight );
  }

  /*
  int val_njetsOverlapPh=0;
  TLorentzVector thePhoton;
  thePhoton.SetPtEtaPhiM( h1->truthStable_ph_pt->at(0)/1000.,
			  h1->truthStable_ph_eta->at(0),
			  h1->truthStable_ph_phi->at(0),
			  0 );
  

  for (unsigned ijet=0; ijet<m_jets.size(); ijet++){
    if(m_jets[ijet].DeltaR(thePhoton) < 0.4){
      val_njetsOverlapPh++;
    }
  }

  thisHist -> nJetsOverlapPh -> Fill(val_njetsOverlapPh , eventWeight);  
  */  
  
  //////////////jet closest to the leading lepton
  double val_min_dR_lepjet= 1000.; //min value of dR between the leading lepton and a jet
  for (int i=0; i<h1->jet_n; i++){
    if ( lepton.DeltaR(m_jets[i]) < val_min_dR_lepjet ){
      val_min_dR_lepjet = lepton.DeltaR(m_jets[i]);
    }
  }
  if(!m_reducedPlots){
    thisHist -> min_dR_lepjet  -> Fill(val_min_dR_lepjet ,  eventWeight ) ;
  }

  vector<TLorentzVector> m_fatjets;
  for (int ijet=0; ijet<h1->fatjet_n; ijet++){
    TLorentzVector thisjet;
    thisjet.SetPtEtaPhiE( h1->fatjet_pt ->at(ijet)/1000.,
                          h1->fatjet_eta->at(ijet),
                          h1->fatjet_phi->at(ijet),
                          h1->fatjet_E  ->at(ijet)/1000. ) ;
    
    m_fatjets.push_back(thisjet);
  }

  //////////////fat-jet closest to the lepton
  double val_min_dR_lepfatjet= 1000.; //min value of dR between the lepton and a fatjet               
  for (int i=0; i<h1->fatjet_n; i++){
    if ( lepton.DeltaR(m_fatjets[i]) < val_min_dR_lepfatjet ){
      val_min_dR_lepfatjet = lepton.DeltaR(m_fatjets[i]);
    }
  }
  if(!m_reducedPlots){
    thisHist -> min_dR_lepfatjet  -> Fill(val_min_dR_lepfatjet ,  eventWeight ) ;
  }
  
  
  
  if(!m_reducedPlots){
    thisHist -> ttbarWeight    -> Fill( h1->ttbarWeight );

  }  


  bool doFJ=false;
  TLorentzVector wjet1,wjet2, diwjets;
  
  if (h1->WjetsIndex1>=0 && h1->WjetsIndex2>=0) { //resolve jet selection
    doFJ=false;
    wjet1.SetPtEtaPhiE(  h1->jet_pt ->at(h1->WjetsIndex1)*GeV,
			 h1->jet_eta->at(h1->WjetsIndex1),
			 h1->jet_phi->at(h1->WjetsIndex1),
			 h1->jet_E  ->at(h1->WjetsIndex1)*GeV );

    wjet2.SetPtEtaPhiE(  h1->jet_pt ->at(h1->WjetsIndex2)*GeV,
			 h1->jet_eta->at(h1->WjetsIndex2),
			 h1->jet_phi->at(h1->WjetsIndex2),
			 h1->jet_E  ->at(h1->WjetsIndex2)*GeV );
    diwjets = wjet1 + wjet2;


  }
  else if (h1->WjetsIndex1>=0){  //fat jet selection
    doFJ=true;
    diwjets.SetPtEtaPhiE(  h1->fatjet_pt ->at(h1->WjetsIndex1)*GeV,
			   h1->fatjet_eta->at(h1->WjetsIndex1),
			   h1->fatjet_phi->at(h1->WjetsIndex1),
			   h1->fatjet_E  ->at(h1->WjetsIndex1)*GeV );
    



    
    if(!m_reducedPlots){
      thisHist->fatjet_M   ->Fill(diwjets.M(), eventWeight);
      thisHist->fatjet_pt  ->Fill(diwjets.Pt(), eventWeight);
      thisHist->fatjet_eta ->Fill(diwjets.Eta(), eventWeight);
      thisHist->fatjet_phi ->Fill(diwjets.Phi(), eventWeight);
      
      
      //investigation of fatjet mass peak reconstruction
      if (diwjets.Pt()>=150 )thisHist->fatjetM_pt150   ->Fill(diwjets.M(), eventWeight);
      if (diwjets.Pt()>=200 )thisHist->fatjetM_pt200   ->Fill(diwjets.M(), eventWeight);
      if (diwjets.Pt()>=250 )thisHist->fatjetM_pt250   ->Fill(diwjets.M(), eventWeight);
      if (diwjets.Pt()>=300 )thisHist->fatjetM_pt300   ->Fill(diwjets.M(), eventWeight);
      
      thisHist -> dRlepFJ  -> Fill( diwjets.DeltaR(lepton),  eventWeight ) ;
      
      
      ///jet closest to W-fatjet
      double val_min_dR_FJ_jet= 1000.; //min value of dR between the W-fatjet and a jet
      for (int i=0; i<h1->jet_n; i++){
	thisHist -> dR_FJ_jets -> Fill( diwjets.DeltaR(m_jets[i]) ,  eventWeight );
	if ( diwjets.DeltaR(m_jets[i]) < val_min_dR_FJ_jet ){
	  val_min_dR_FJ_jet = diwjets.DeltaR(m_jets[i]);
	}
      }
      
      thisHist -> min_dR_FJ_jet  -> Fill(val_min_dR_FJ_jet ,  eventWeight ) ;
    
    }
    
  }

 

  ///commented out by auzaman on 9/12/14
  // else if (h1->WjetsIndex1>=0 && h1->WjetsIndex2<0){
  //   doFJ=true;
  //   diwjets.SetPtEtaPhiE( h1->fatjet_pt ->at(h1->WjetsIndex1)*GeV,
  // 			  h1->fatjet_eta->at(h1->WjetsIndex1),
  // 			  h1->fatjet_phi->at(h1->WjetsIndex1),
  // 			  h1->fatjet_E  ->at(h1->WjetsIndex1)*GeV );
  // }  

  
  TLorentzVector vbfjet1,vbfjet2, divbfjets;

  if (h1->vbfjetsIndex1>=0 && h1->vbfjetsIndex2>=0) {
   
    vbfjet1.SetPtEtaPhiE(  h1->jet_pt ->at(h1->vbfjetsIndex1)*GeV,
			   h1->jet_eta->at(h1->vbfjetsIndex1),
			   h1->jet_phi->at(h1->vbfjetsIndex1),
			   h1->jet_E  ->at(h1->vbfjetsIndex1)*GeV );
    
    vbfjet2.SetPtEtaPhiE(  h1->jet_pt ->at(h1->vbfjetsIndex2)*GeV,
			   h1->jet_eta->at(h1->vbfjetsIndex2),
			   h1->jet_phi->at(h1->vbfjetsIndex2),
			   h1->jet_E  ->at(h1->vbfjetsIndex2)*GeV );
    divbfjets = vbfjet1 + vbfjet2;
  }

  thisHist -> Njet    -> Fill( h1->jet_n, eventWeight );
  //  thisHist -> Njet    -> Fill( h1->jet_n -val_njetsOverlapPh, eventWeight );

  if(!m_reducedPlots){
    
    if(doFJ){ 
      thisHist -> Nfatjet    -> Fill( h1->fatjet_n, eventWeight );
    }
  
    if(h1->jet_n >= 1){
      thisHist -> jet1_pt  -> Fill( h1->jet_pt->at(0)*GeV,  eventWeight ) ;
      thisHist -> jet1_eta  -> Fill( h1->jet_eta->at(0),  eventWeight ) ;
      thisHist -> jet1_phi  -> Fill( h1->jet_phi->at(0),  eventWeight ) ;
    }
    if(h1->jet_n >= 2){
      thisHist -> jet2_pt  -> Fill( h1->jet_pt->at(1)*GeV,  eventWeight ) ; 
      thisHist -> jet2_eta  -> Fill( h1->jet_eta->at(1),  eventWeight ) ;
      thisHist -> jet2_phi  -> Fill( h1->jet_phi->at(1),  eventWeight ) ;
    }
    if(h1->jet_n >= 3){
      thisHist -> jet3_pt  -> Fill( h1->jet_pt->at(2)*GeV,  eventWeight ) ;
      thisHist -> jet3_eta  -> Fill( h1->jet_eta->at(2),  eventWeight ) ;
      thisHist -> jet3_phi  -> Fill( h1->jet_phi->at(2),  eventWeight ) ;
    }    
    if (h1->jet_n >=4){
      thisHist -> jet4_pt  -> Fill( h1->jet_pt->at(3)*GeV,  eventWeight ) ;
      thisHist -> jet4_eta  -> Fill( h1->jet_eta->at(3),  eventWeight ) ;
      thisHist -> jet4_phi  -> Fill( h1->jet_phi->at(3),  eventWeight ) ;
    }

  }
  
  
  int trueVpdgId=0;
  TLorentzVector true_Vjj;
  vector<TLorentzVector> true_Vjets; 
  vector<TLorentzVector> true_otherjets;
  
  bool isTrueSigEvent = SelectionTools::getTruePartonVectors(h1, true_Vjj, true_Vjets, true_otherjets, trueVpdgId);
  
  int nCloseQuarks=0;
  double maxEta=0;
  double minPt=1000000;
  double deltaVVW=10000;
  double deltaVVZ=10000;

  
  
  if(isTrueSigEvent){
    
    if(true_otherjets.size()!=2){ cout<<"SCREEEEEEEEAM"<<endl;}
    TLorentzVector qqPair = true_otherjets[0] + true_otherjets[1];
    deltaVVW = qqPair.M() - constants::MassW;
    deltaVVZ = qqPair.M() - constants::MassZ;
    
    for(int pmc=0; pmc<mc_n; pmc++){
      if ( abs(h1->mctruth_pdgId->at(pmc)) >0 && abs(h1->mctruth_pdgId->at(pmc))<7 ) { //quarks                                       
	
	TLorentzVector thisPart;
	thisPart.SetPtEtaPhiM(  h1->mctruth_pt ->at(pmc)*GeV,
				h1->mctruth_eta ->at(pmc)  ,
				h1->mctruth_phi ->at(pmc)  ,
				h1->mctruth_m ->at(pmc)*GeV  );
	
	double dRfatQ = true_Vjj.DeltaR(thisPart);
	if(dRfatQ<1.2){
	  nCloseQuarks++;
	}
      }
    }
    
    
    for(unsigned itj=0; itj<true_Vjets.size(); itj++){
      if(fabs(true_Vjets[itj].Eta())>maxEta){
	maxEta = fabs(true_Vjets[itj].Eta());
      }
      if(true_Vjets[itj].Pt()<minPt){
	minPt = true_Vjets[itj].Pt();
      }
    }
    
  }
      
  
  double trueVjjpT = -1;
  
  bool includeEvent=true;
  TLorentzVector decaySum;

  if(isTrueSigEvent){
    //strangely, decaySum is not exactly equal to true_Vjj.  This might be due 
    //to details in Whizard, that don't necessary respect 4-momentum conservation in the truth record?
    decaySum = true_Vjets[0] + true_Vjets[1];
    trueVjjpT = decaySum.Pt();
    
    TLorentzVector boostedDecay = true_Vjets[0];
    boostedDecay.Boost( -decaySum.BoostVector() );
    // double cosThetaDecay =  cos( boostedDecay.Angle(decaySum.Vect()) );
     
    
    //  if(trueVjjpT>200 && trueVjjpT<300 &&  fabs(decaySum.Eta())<1.2 && maxEta<1.0 && h1->mctruth_Nbquarks==0 ){//  && nCloseQuarks==2 ){
    //includeEvent = (trueVjjpT>200 && trueVjjpT<1000 &&  fabs(decaySum.Eta())<1.2 && h1->mctruth_Nbquarks==0); // && fabs(cosThetaDecay)>0.6 );
    // if(trueVjjpT>0 && trueVjjpT<1000 &&  fabs(decaySum.Eta())<1.2 && h1->mctruth_Nbquarks==0 && fabs(cosThetaDecay)<0.6 ){//  && nCloseQuarks==2 ){
    
    
    if(includeEvent){

      if(!m_reducedPlots){
	thisHist -> trueVpt ->Fill(trueVjjpT, eventWeight);
	thisHist -> trueVeta ->Fill(decaySum.Eta(), eventWeight);
	
	thisHist -> trueVjMaxEta ->Fill(maxEta, eventWeight);
	thisHist -> trueVjMinPt ->Fill(minPt, eventWeight);
	thisHist -> trueVjjDR ->Fill(true_Vjets[0].DeltaR(true_Vjets[1]), eventWeight);
	
	//      thisHist -> trueVjjCosTh ->Fill( fabs(cosThetaDecay), eventWeight);
      }      


      if(abs(trueVpdgId)==23){ //is a Z ->jj
	if(!m_reducedPlots){
	  thisHist -> trueDeltaVVW ->Fill(deltaVVW, eventWeight);
	}
      }
      else if(abs(trueVpdgId)==24){ //is a W->jj
	if(!m_reducedPlots){
	  thisHist -> trueDeltaVVZ ->Fill(deltaVVZ, eventWeight);
	}
      }
      else{
	cout<<"SCREAAAAAM!!!"<<endl;
      }

    }
  }
  
  
  int nMatchFat=0;
  for (int ijet=0; ijet<h1->fatjet_n; ijet++){
    TLorentzVector thisjet;
    thisjet.SetPtEtaPhiE( h1->fatjet_pt ->at(ijet)/1000.,
			  h1->fatjet_eta->at(ijet),
			  h1->fatjet_phi->at(ijet),
			  h1->fatjet_E  ->at(ijet)/1000. ) ;
    
    if(thisjet.Pt()<100){
      continue;
    }
    
    if(isTrueSigEvent){
            
      if(includeEvent){
	//    if(trueVjjpT>0  && trueVjjpT<1000 && fabs(decaySum.Eta())<1.2 && h1->mctruth_Nbquarks==0 && fabs(cosThetaDecay)<0.6){
	
	double dRfatV = thisjet.DeltaR(decaySum);
	if(!m_reducedPlots){
	  thisHist -> dRfatjetV->Fill( dRfatV, eventWeight );
	}	  

	if(dRfatV<0.5){
	  double fatM = thisjet.M();

	  if(!m_reducedPlots){
	    thisHist -> truthMatchedfatjetM->Fill(fatM, eventWeight);
	  }	  

	  if(fatM>50 && fatM<110){
	    nMatchFat++;
	    if(!m_reducedPlots){
	      thisHist -> trueVptMatched ->Fill(trueVjjpT, eventWeight);
	      thisHist -> trueVetaMatched ->Fill(decaySum.Eta(), eventWeight);
	    }	    

	    if(nMatchFat>=2){
	      cout<<"SCREAEEEEAM!"<<endl;
	    }
	    
	  }
	  
	}
	
      }
      
    }//end if(isTrueSigEvent)
    
 
  } //end loop over fat jets
  
  
  if(isTrueSigEvent&&includeEvent){
    
    vector<unsigned> matchedJets;  //are there *any* jets matched to the true V->jj partons?
    vector<unsigned> matchedJetsToWjets;  //do the jets selected by the Wjet selection match the true V->jj partons?
    
    for (unsigned jtrue=0; jtrue<true_Vjets.size(); jtrue++){
      
      double minDR=10000;
      unsigned matchId=500000;
      for (unsigned ijet=0; ijet<m_jets.size(); ijet++){
	
	bool alreadyUsed = false;
	for(unsigned mm=0; mm<matchedJets.size(); mm++){
	  if(matchedJets[mm] == ijet){
	    alreadyUsed = true;
	  }
	}
	if(alreadyUsed){ continue;}  //don't match the same jet to two different quarks
	
	double dRjetTrue = m_jets[ijet].DeltaR(true_Vjets[jtrue]);
	if(dRjetTrue<minDR){
	  minDR = dRjetTrue;
	  if(dRjetTrue<0.4){
	    matchId=ijet;
	  }
	}
      }
      if(matchId!=500000){
	matchedJets.push_back(matchId);
      }      
    } //end loop over true_Vjets

    bool wjetsAreMatched=false;
    if (h1->WjetsIndex1>=0  && h1->WjetsIndex2>=0 && h1->vbfjetsIndex1>=0 && h1->vbfjetsIndex2>=0 ) {
      double matchw1=false;
      for (unsigned jtrue=0; jtrue<true_Vjets.size(); jtrue++){    
	double dRjetTrue = m_jets[h1->WjetsIndex1].DeltaR(true_Vjets[jtrue]);
	if(dRjetTrue<0.4){
	  matchw1=true;
	}
      }

      double matchw2=false;
      for (unsigned jtrue=0; jtrue<true_Vjets.size(); jtrue++){
        double dRjetTrue = m_jets[h1->WjetsIndex2].DeltaR(true_Vjets[jtrue]);
        if(dRjetTrue<0.4){
          matchw2=true;
        }
      }
      if(matchw1 && matchw2){ 
	wjetsAreMatched=true;
      }
    }
    
    if(includeEvent){
      
      if(matchedJets.size()==2){
	TLorentzVector myDijet= m_jets[matchedJets[0]] + m_jets[matchedJets[1]];

	if(!m_reducedPlots){
	  thisHist -> matchedDijetM->Fill(myDijet.M(), eventWeight);
	  
	  if(myDijet.M()>50 && myDijet.M()<110){
	    
	    thisHist -> trueVptDijetMatched ->Fill(trueVjjpT, eventWeight);
	    
	    if(wjetsAreMatched){
	      thisHist -> trueVptDijetWjetMatched ->Fill(trueVjjpT, eventWeight);
	    }
	    
	  }
	  
	}

      }//end if(matchedJets.size()==2)

    }
    
    
  }//end if(isTrueSigEvent&&includeEvent)
  
  //this will be true either for a useFJ or a !useFJ event
  if (h1->WjetsIndex1>=0  &&  h1->vbfjetsIndex1>=0 && h1->vbfjetsIndex2>=0 ) {
  
    float val_mlvjj = ( lepton + neutrino + diwjets).M();
    float val_mwjj  = diwjets.M();
    //cout<<"Wjet mjj= "<<val_mwjj<<endl;
    float val_ptlvjj = ( lepton + neutrino + diwjets).Pt();
    float val_ptwjj  = diwjets.Pt();
    
    float val_scaldiff_ptwj1_ptwj2 = 0, val_cosThetaWDecay=-10;    
    float val_sumPt = 0;

   
    
    
    if (h1->WjetsIndex2>=0 ){    //resolved jet selection
      //resolved case
      val_sumPt = (lepton.Pt()+neutrino.Pt()+ vbfjet1.Pt()+vbfjet2.Pt()+wjet1.Pt()+wjet2.Pt());

      val_scaldiff_ptwj1_ptwj2 = wjet1.Pt() - wjet2.Pt();
      
      //      TLorentzVector boostedWDecayProd = wjet1;
      //  boostedWDecayProd.Boost( -diwjets.BoostVector() );
      // val_cosThetaWDecay =  cos( boostedWDecayProd.Angle(diwjets.Vect()) );
      //      cout<<"cosThetaWDecay (1) = "<<val_cosThetaWDecay<<endl;
      
      /*
      TLorentzVector boostedWDecayProd = wjet1;
      boostedWDecayProd.Boost( -diwjets.BoostVector() );
      
      TLorentzVector leptonicW = lepton + neutrino;
      TLorentzVector diboson = leptonicW + diwjets; 
      TLorentzVector boostedW = diwjets;
      boostedW.Boost( -diboson.BoostVector() );
      
      val_cosThetaWDecay =  cos(  boostedWDecayProd.Angle(boostedW.Vect()) );
      //cout<<"cosThetaWDecay (2) = "<<val_cosThetaWDecay<<endl;
      */      

      
      TLorentzVector leptonicW = lepton + neutrino;
      val_cosThetaWDecay =  fabs( getCosThetaStar(wjet1, diwjets, leptonicW) );
      
    }
    else{
      //fat-jet case
      val_sumPt = (lepton.Pt()+neutrino.Pt()+ vbfjet1.Pt()+vbfjet2.Pt()+diwjets.Pt());
    }
    
    TLorentzVector leptonicW = lepton + neutrino;
    double val_cosThetaWlep =  getCosThetaStar(lepton, leptonicW, diwjets);

        
    float val_cosdPhi_wjjwlep = cos( diwjets.DeltaPhi( lepton + neutrino ) );
    
    double val_VVvecptdiff = (diwjets - leptonicW).Pt();
    
    double val_mTWV = getMTWV(diwjets,lepton,neutrino);
    
    TVector3 wwaxis = (lepton + neutrino  - diwjets).Vect();
    TVector3 vbfaxis = (vbfjet1 - vbfjet2).Vect();

    float val_dR_vbfwwaxes = vbfaxis.DeltaR(wwaxis);
    float val_dEta_vbfwwaxes = fabs( vbfaxis.Eta() - wwaxis.Eta() );
    float val_dPhi_vbfwwaxes = vbfaxis.DeltaPhi(wwaxis);

    //define these dphi, deta, dR variables as the smaller of the two angles formed between the axes.  
    wwaxis = - wwaxis;
    if(vbfaxis.DeltaR(wwaxis) < val_dR_vbfwwaxes ){
      val_dR_vbfwwaxes = vbfaxis.DeltaR(wwaxis);
    }
    else if(  fabs( vbfaxis.Eta() - wwaxis.Eta() ) < val_dEta_vbfwwaxes ){
      val_dEta_vbfwwaxes = fabs( vbfaxis.Eta() - wwaxis.Eta() );
    }
    else if( vbfaxis.DeltaPhi(wwaxis) < val_dPhi_vbfwwaxes ){
      val_dPhi_vbfwwaxes = vbfaxis.DeltaPhi(wwaxis);
    }
    
    
    float L=fabs(vbfjet1.Eta()-vbfjet2.Eta());
    float avgEtaTagged= (vbfjet1.Eta()+vbfjet2.Eta())/2;
    float val_diff_etawjj_avgEtaTagged=fabs(diwjets.Eta()-avgEtaTagged);//during truth studies: hist_etaWjj
    float val_mass_lnuj0= ( m_jets[0]+lepton+ neutrino ).M();
    
    double val_lepCentrality = getCentrality(vbfjet1.Eta(), vbfjet2.Eta(), lepton.Eta() );
    double val_bosonCentrality = getCentrality(vbfjet1.Eta(), vbfjet2.Eta(), diwjets.Eta(), leptonicW.Eta() );

    
    
    float val_mass_j0j1j2=-1;
    if(h1->jet_n > 2){
      val_mass_j0j1j2= ( m_jets[0]+ m_jets[1]+ m_jets[2] ).M();
    }

    float val_ptBalance = -1;
    if (!doFJ) {

      if(!m_reducedPlots){
        thisHist -> Wjet1_pt  -> Fill( h1->jet_pt->at(h1->WjetsIndex1)*GeV,  eventWeight ) ;
        thisHist -> Wjet2_pt  -> Fill( h1->jet_pt->at(h1->WjetsIndex2)*GeV,  eventWeight ) ;
        thisHist -> AvgPt_Wjets  -> Fill( (h1->jet_pt->at(h1->WjetsIndex1)*GeV+ h1->jet_pt->at(h1->WjetsIndex2)*GeV)/2,  eventWeight ) ;
      }
      val_ptBalance = (lepton + neutrino+diwjets+divbfjets).Pt()/(lepton.Pt() + neutrino.Pt()+wjet1.Pt()+wjet2.Pt()+vbfjet1.Pt()+vbfjet2.Pt());


    }
    else{
      val_ptBalance = (lepton + neutrino+diwjets+divbfjets).Pt()/(lepton.Pt() + neutrino.Pt()+diwjets.Pt()+vbfjet1.Pt()+vbfjet2.Pt());
    }
    
    thisHist -> ptBalance  -> Fill(val_ptBalance  , eventWeight);


    float val_VVptBalance = (lepton + neutrino+diwjets).Pt()/(leptonicW.Pt() + diwjets.Pt());
    thisHist -> VVptBalance  -> Fill(val_VVptBalance  , eventWeight);

    float val_VVptSum = leptonicW.Pt() + diwjets.Pt();
    thisHist -> VVptSum  -> Fill(val_VVptSum  , eventWeight);
    
    

    if(doShortAscii){
      
      if(constants::writeAsciiMode==0){
	thisAscii->textFile << h1->RunNumber<<" "<<h1->EventNumber<<" "<<eventWeight<<" "<<lepton.Pt()<<" "<<lepton.Phi()<<" "<<lepton.Eta()<<" "<<h1->MET_x *GeV<<" "<<h1->MET_y *GeV<<" "<<h1->MET *GeV<<" "<<val_ptwlep<<" "<<h1->jet_n<<" "<<h1->jet_pt->at(0)*GeV<<" "<<h1->jet_pt->at(1)*GeV<<" "<<vbfjet1.Pt()<<" "<<vbfjet1.Phi()<<" "<<vbfjet1.Eta()<<" "<<vbfjet2.Pt()<<" "<<vbfjet2.Phi()<<" "<<vbfjet2.Eta()<<" "<<val_mlvjj<<" "<<val_mwjj<<" "<<val_ptlvjj<<" "<<val_ptwjj<<" "<<avgEtaTagged<<" "<<val_mass_lnuj0<<" "<<val_sumPt<<" "<<(L/2)-val_diff_etawjj_avgEtaTagged<<" "<<(L/2)-fabs(lepton.Eta()-avgEtaTagged)<<" "<<val_mT<<" "<<val_cosdPhi_wjjwlep<<" "<<val_scaldiff_ptwj1_ptwj2<<" "<<val_dR_vbfwwaxes<<" "<<val_dEta_vbfwwaxes<<" "<<val_dPhi_vbfwwaxes<<" "<<fabs(vbfjet1.Eta()-vbfjet2.Eta())<<" "<<vbfjet1.DeltaPhi(vbfjet2)<<" "<<vbfjet1.DeltaR(vbfjet2)<<" "<<divbfjets.M()<<" "<<divbfjets.Pt()<<" "<<val_ptlvjj-divbfjets.Pt()<<" "<<val_cosThetaWlep<<" "<<val_lepCentrality<<" "<<val_bosonCentrality<<" "<<val_VVvecptdiff<<" "<<val_mTWV<<" "<<val_VVptBalance<<" "; //Aungshuman
      }
      else if(constants::writeAsciiMode==1){
	//transform certain variables so that signal peaks towards larger values of the variable (necessary for rgs optimization code)
	thisAscii->textFile << eventWeight<<" "<<lepton.Pt()<<" "<<h1->MET*GeV<<" "<<val_ptwlep<<" "<<vbfjet1.Pt()<<" "<<fabs(vbfjet1.Eta())<<" "<<vbfjet2.Pt()<<" "<<fabs(vbfjet2.Eta())<<" "<<val_mlvjj<<" "<<-fabs(val_mwjj-85)<<" "<<val_ptlvjj<<" "<<val_ptwjj<<" "<<fabs(avgEtaTagged)<<" "<<divbfjets.M()<<" "<<val_lepCentrality<<" "<<val_bosonCentrality<<" "<<val_VVptSum<<" "<<val_VVvecptdiff<<" "<<val_mTWV<<" "<<-val_VVptBalance<<" "<<-val_ptBalance<<" "<<val_min_dR_lepjet<<" "<<fabs(vbfjet1.Eta()-vbfjet2.Eta())<<" "<<-val_cosThetaWlep<<" ";  //BL
      }
      else{
	assert(0);
      }

    }
        
    thisHist -> Mlvjj -> Fill(val_mlvjj , eventWeight);///hist_mWW
    thisHist -> Mwjj  -> Fill(val_mwjj  , eventWeight);///hist_mW
    thisHist -> ptlvjj -> Fill(val_ptlvjj , eventWeight);///hist_ptWW
    thisHist -> ptwjj  -> Fill(val_ptwjj  , eventWeight);///hist_ptW
    
    thisHist -> ptwjj_ptwlep -> Fill (val_ptwjj ,val_ptwlep ,  eventWeight);
    
    thisHist -> cosDPhiwjjwlep -> Fill  ( val_cosdPhi_wjjwlep , eventWeight);    
    thisHist -> VVvecptdiff -> Fill  ( val_VVvecptdiff , eventWeight);
    

    //thisHist -> MlvjjWD -> Fill(val_mlvjj , eventWeight);
    //thisHist -> MwjjWD  -> Fill(val_mwjj  , eventWeight);
 
    thisHist -> etaX -> Fill ((L/2)-val_diff_etawjj_avgEtaTagged , eventWeight);
    thisHist -> etaY -> Fill ((L/2)-fabs(lepton.Eta()-avgEtaTagged) , eventWeight);
    thisHist -> dEtaTaggedJets -> Fill ( fabs(vbfjet1.Eta()-vbfjet2.Eta()) ,eventWeight);
    thisHist -> cosThetaWlep -> Fill(val_cosThetaWlep, eventWeight);

    thisHist -> lepCentrality -> Fill(val_lepCentrality, eventWeight);
    thisHist -> bosonCentrality -> Fill(val_bosonCentrality, eventWeight);


    thisHist -> mTWV ->Fill(val_mTWV, eventWeight);
    //    thisHist -> EtWlepAlt_EtWlep -> Fill( val_etWlepAlt, val_etWlep , eventWeight);
    thisHist -> mTWV_Mlvjj -> Fill( val_mTWV, val_mlvjj , eventWeight);
    thisHist -> mTWV_VVvecptdiff -> Fill( val_mTWV, val_VVvecptdiff , eventWeight);
    thisHist -> mTWV_ptwlep -> Fill (val_mTWV ,val_ptwlep ,  eventWeight);

    thisHist -> mjjTagged_MET -> Fill (divbfjets.M() ,h1->MET * GeV ,  eventWeight);
    
    if(!m_reducedPlots){
      
      thisHist -> sumPt -> Fill(val_sumPt , eventWeight);///scalar sum of lv and first 4 jets
      thisHist -> diff_etawjj_avgEtaTagged -> Fill(val_diff_etawjj_avgEtaTagged , eventWeight);//hist_etaWjj
      thisHist -> dPhiTaggedJets -> Fill ( vbfjet1.DeltaPhi(vbfjet2) ,eventWeight);
      thisHist -> dRTaggedJets -> Fill ( vbfjet1.DeltaR(vbfjet2) ,eventWeight);
      

      thisHist -> dRvbfwwaxes -> Fill ( val_dR_vbfwwaxes , eventWeight);
      thisHist -> dEtavbfwwaxes -> Fill ( val_dEta_vbfwwaxes , eventWeight);
      thisHist -> dPhivbfwwaxes -> Fill ( val_dPhi_vbfwwaxes , eventWeight);
      
    }
     
      
    if (h1->WjetsIndex2>=0 ){ //Only for resolved jet selection

      thisHist -> dRWjets -> Fill ( wjet1.DeltaR(wjet2) ,eventWeight);     
      thisHist -> cosThetaWDecay -> Fill(val_cosThetaWDecay, eventWeight);      

      if(!m_reducedPlots){
	thisHist -> dEtaWjets -> Fill ( fabs(wjet1.Eta()-wjet2.Eta()) ,eventWeight);
	thisHist -> dPhiWjets -> Fill ( wjet1.DeltaPhi(wjet2) ,eventWeight);
	thisHist -> diffptwj1ptwj2 -> Fill(val_scaldiff_ptwj1_ptwj2 , eventWeight);
      }
      
      
      if(doShortAscii){
	
	if(constants::writeAsciiMode==0){
	  thisAscii->textFile << wjet1.DeltaR(wjet2)<< " "<< wjet1.DeltaPhi(wjet2)<<" "<<fabs(wjet1.Eta()-wjet2.Eta())<<" "<<wjet1.Pt()<<" "<<wjet1.Eta()<<" "<<wjet1.Phi()<<" "<<wjet2.Pt()<<" "<<wjet2.Eta()<<" "<<wjet2.Phi()<<" "<<val_cosThetaWDecay<<" ";   //Aungshuman
	}
	else if(constants::writeAsciiMode==1){
	  thisAscii->textFile << -wjet1.DeltaR(wjet2)<<" "<<wjet1.Pt()<<" "<<wjet2.Pt()<<" "<<-val_cosThetaWDecay;  //BL
	}
	
      }
      
    }    
    else{
      
      if(doShortAscii){
	
	if(constants::writeAsciiMode==0){
	  thisAscii->textFile << "0 0 0 0 0 0 0 0 0 0 ";   //Aungshuman
	}
	else if(constants::writeAsciiMode==1){
	  thisAscii->textFile << "0 0 0 0"; //BL
	}

      }
    }

    
    if(doShortAscii){
      if(constants::writeAsciiMode==0){
	thisAscii->textFile <<val_ptBalance;  //Aungshuman
      }
    }
    
    if(doShortAscii){
      //  cout<<"Writing event to ascii"<<endl;
      thisAscii->textFile << "\n";
    }
    
    thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
    thisHist -> ptjjTagged  -> Fill(divbfjets.Pt() , eventWeight); 
    
    if(!m_reducedPlots){
      
      thisHist -> mass_lnuj0 -> Fill ( val_mass_lnuj0 ,eventWeight);
      thisHist -> mass_j0j1j2 -> Fill ( val_mass_j0j1j2 ,eventWeight);
      
      thisHist -> diff_ptww_ptjjTagged  -> Fill(val_ptlvjj-divbfjets.Pt() , eventWeight);
    }

  // */
  
  // if ( category.BeginsWith("Data")){
  //   //cout<<"category= "<<category<<endl;
  //   if (divbfjets.M()<1500)thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }else{
  //   thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }
  ///////
  // /*


    thisHist -> vbfjet1_pt  -> Fill( h1->jet_pt->at(h1->vbfjetsIndex1)*GeV,  eventWeight ) ;
    thisHist -> vbfjet2_pt  -> Fill( h1->jet_pt->at(h1->vbfjetsIndex2)*GeV,  eventWeight ) ;
    thisHist -> vbfjet1_eta  -> Fill( h1->jet_eta->at(h1->vbfjetsIndex1),  eventWeight ) ;
    thisHist -> vbfjet2_eta  -> Fill( h1->jet_eta->at(h1->vbfjetsIndex2),  eventWeight ) ;
    
    
    if(!m_reducedPlots){
      thisHist -> dEtaMax  -> Fill( h1->dEtaMax,  eventWeight ) ;      
      
      thisHist -> vbfjets_etaProduct  -> Fill( (h1->jet_eta->at(h1->vbfjetsIndex1))*(h1->jet_eta->at(h1->vbfjetsIndex2)),  eventWeight ) ;
      
      thisHist -> vbfjet1_phi  -> Fill( h1->jet_phi->at(h1->vbfjetsIndex1),  eventWeight ) ;
      thisHist -> vbfjet2_phi  -> Fill( h1->jet_phi->at(h1->vbfjetsIndex2),  eventWeight ) ;
      
      thisHist -> ptjjMax  -> Fill( h1->ptjjMax ,  eventWeight ) ;///It is obtained straight from minihbb in GeV
      
    }
    
    
    
    
    // Calculate b-tag
    
    bool useFJ=false; //hard-code for now
    TLorentzVector wjetfat;
    //bool btagged = false;
    for(int ijet=0;ijet<h1->jet_n;ijet++){
      
      bool _isWjet = (ijet==h1->WjetsIndex1 || ijet==h1->WjetsIndex2) ? true : false ;
      if (useFJ) _isWjet = false;
      
      TLorentzVector thisjet;
      thisjet.SetPtEtaPhiE( h1->jet_pt ->at(ijet)/1000.,
			    h1->jet_eta->at(ijet),
			    h1->jet_phi->at(ijet),
			    h1->jet_E  ->at(ijet)/1000. ) ;
      
      if (  (fabs(h1->jet_eta->at(ijet)) <2.5) &&  ///central
	    (!_isWjet) &&                          ///non-W jet
	    ((!useFJ) || fabs(thisjet.DeltaR(wjetfat))>0.4  ) /// not fat jet or >0.4 far from a w-fatjet
	    )
	{
	  
	  if(h1->mctruth_Nbquarks==0 && nTrueCquark==0){

	    if(!m_reducedPlots){
	      thisHist -> MV1 -> Fill(h1->jet_MV1->at(ijet), eventWeight);
	    }
	  }
	  
	}
    
    }//end for (int ijet=0;ijet<h1->jet_n;ijet++)
        
    
  }  //end if (h1->WjetsIndex1>=0  &&  h1->vbfjetsIndex1>=0 && h1->vbfjetsIndex2>=0 )
  
  
  double val_min_dEta_Wlepjet=1000.; //min value of dEta between Wlep and a jet
  for (int i=0; i<h1->jet_n; i++){
    if (fabs(( lepton + neutrino ).Eta()-m_jets[i].Eta())<val_min_dEta_Wlepjet){
      val_min_dEta_Wlepjet=fabs(( lepton + neutrino ).Eta()-m_jets[i].Eta());
    }
  }

  if(!m_reducedPlots){
    thisHist -> min_dEta_Wlepjet  -> Fill(val_min_dEta_Wlepjet ,  eventWeight ) ;  
  }    

  // if ( category.BeginsWith("Data")){
  //   //cout<<"category= "<<category<<endl;
  //   if (divbfjets.M()<1500)thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }else{
  //   thisHist -> mjjTagged  -> Fill(divbfjets.M() , eventWeight);
  // }


  
  //TString category = TString((*m_DatasetTypeMap)[RunNumber] ); //"Top","WZZZWgZjets","Wjets","H_ggF_125" etc
  
  if ( category.BeginsWith("H_") && ( !category.Contains("_500")) ) return 0;//if the sample is Higgs but not H_*_500*, then do not fill the following variables-- only mll?
  
  if(!m_reducedPlots){
    thisHist -> topRWEventWeight    -> Fill( h1->topRWEventWeight );
    thisHist -> wjetsRWEventWeight    -> Fill( h1->wjetsRWEventWeight );
    thisHist -> mcEventWeight    -> Fill( h1->mcEventWeight );
    thisHist -> EventWeight    -> Fill( h1->EventWeight );
  }    

  
//  thisHist -> MLL       -> Fill( h1->Mll    * GeV , eventWeight );
//  thisHist -> FineMLL   -> Fill( h1->Mll    * GeV , eventWeight );
//
//  if ( isOtherSignal(RunNumber) ) { 
//    return 0;
//  }
//
//  thisHist -> PtLL      -> Fill( h1->Ptll   * GeV , eventWeight );
//  thisHist -> NVertex   -> Fill( h1->Nvxp         , eventWeight );

//  thisHist -> deltaPhi  -> Fill( h1->DPhill       , eventWeight );
//  thisHist -> MetRel    -> Fill( h1->METRel * GeV , eventWeight );
//  thisHist -> WT        -> Fill( h1->MT     * GeV , eventWeight );
//
//  thisHist -> JetMulti  -> Fill( h1->m_jet_n      , eventWeight );
//  
//  
//  if ( h1->lepPt1 > h1->lepPt0 )
//    {
//      thisHist -> lep1_pt  -> Fill( h1->lepPt1  *GeV,  eventWeight );
//      thisHist -> lep1_eta -> Fill( h1->lepEta1 ,  eventWeight );
//      thisHist -> lep1_phi -> Fill( h1->lepPhi1 ,  eventWeight );
//      thisHist -> lep2_pt  -> Fill( h1->lepPt0  *GeV,  eventWeight );
//      thisHist -> lep2_eta -> Fill( h1->lepEta0 ,  eventWeight );
//      thisHist -> lep2_phi -> Fill( h1->lepPhi0 ,  eventWeight );
//    }
//  else 
//    {
//      thisHist -> lep1_pt  -> Fill( h1->lepPt0  *GeV,  eventWeight );
//      thisHist -> lep1_eta -> Fill( h1->lepEta0 ,  eventWeight );
//      thisHist -> lep1_phi -> Fill( h1->lepPhi0 ,  eventWeight );
//      thisHist -> lep2_pt  -> Fill( h1->lepPt1  *GeV,  eventWeight );
//      thisHist -> lep2_eta -> Fill( h1->lepEta1 ,  eventWeight );
//      thisHist -> lep2_phi -> Fill( h1->lepPhi1 ,  eventWeight );
//    }
//  
//  
//  thisHist -> MET_phi      -> Fill( h1->MET_phi      ,  eventWeight ) ;
//  
//  
//  //if ( h1->nJet > 0 ){
//  //  thisHist -> jet1_pt      -> Fill( h1->jet1_pt      ,  eventWeight ) ;
//  //  thisHist -> jet1_eta     -> Fill( h1->jet1_eta     ,  eventWeight ) ;
//  //  thisHist -> jet1_phi     -> Fill( h1->jet1_phi     ,  eventWeight ) ;
//  //  thisHist -> jet1_CombNN  -> Fill( h1->jet_CombNN ->at(0) ,  eventWeight ) ;
//  //}
//  //
//  
//  if ( h1->m_jet_n >= 2 )
//    {
//      float etaJ1etaJ2 = h1->jetEta0 * h1->jetEta1 ; 
//      thisHist -> dEtajj     -> Fill( h1->DEtajj,   eventWeight );
//      thisHist -> EtaJ1EtaJ2 -> Fill( etaJ1etaJ2 ,  eventWeight );
//      thisHist -> Mjj        -> Fill( GeV*h1->Mjj,       eventWeight );
//    }

  
  return 0 ; 
};


HistRun * HistFiller::getHist( const int &RunNumber, const string &channel , const string &cut    )
{
  
  std::string category = (*m_DatasetTypeMap)[RunNumber] ; 
  
  if ( category == ""  ) {
    cout << "HistFiller::getHist " << "Can not find DatasetType for this run  " << RunNumber << endl;
    exit(20);
  }

  std::string histName = "H_" + category + "_"  + channel  + cut ; 
    
  
  if ( m_HistNameMap.find(histName) == m_HistNameMap.end() ) {
    MakeNewHist( histName , cut);
  }
  
  return m_HistNameMap[histName]; //returns a HistRun type object which contains histograms for various variables, e.g. jet1_pt, mjjTagged etc.
 
}


AsciiRun * HistFiller::getAscii( const int &RunNumber, const string &channel , const string &cut    )
{

  std::string category = (*m_DatasetTypeMap)[RunNumber] ;

  if ( category == ""  ) {
    cout << "HistFiller::getAscii " << "Can not find DatasetType for this run  " << RunNumber << endl;
    exit(20);
  }


  //std::string txtName = "txt_" + category + "_"  + channel  + cut ;
  std::string txtName = "txt_" + category + "_"  + channel  + cut + "_"  + m_systname; ///&&&& added 4/28/15
  //  cout<<"looking for "<<txtName<<endl;

  if ( m_AsciiNameMap.find(txtName) == m_AsciiNameMap.end() ) {
    MakeNewAscii( txtName , cut);
  }

  return m_AsciiNameMap[txtName]; //returns a AsciiRun type object which contains Ascii files filled with events

}





void HistFiller::MakeNewHist( const string &histName , const string &cut)       
{
  if ( m_foutput ) m_foutput -> cd(); 

  //cout << "HistFiller::MakeNewHist -> Make a new HistRun "  << histName << endl;
  //cout << " is only mll " << onlymll << " histname " << histName << " , runnumber " << endl;

  for ( int itype=0; itype< m_nDSType; itype++ ){
    for ( int iflavor=0 ; iflavor<m_nflavor ; iflavor++){
      std::string thisHistName = "H_" + m_DScategory[itype] + "_" + m_flavorChannel[iflavor] + "_" + cut ; //e.g. H_Top_em_WBF_CR_Top,where cut is WBF_CR_Top
                                                                                                           //WBF is prod mod and CR_Top defines a specific cut
      //cout  << " new hist name " << thisHistName << endl; 

      //      bool reducedPlots = true;
      //      TString thisCate = m_DScategory[itype] ; 
      // if ( thisCate.BeginsWith("H_") && ( !thisCate.Contains("_500"))  ) onlymll = true;

      m_HistNameMap[thisHistName]= new HistRun( thisHistName , m_reducedPlots );
    }
  } 


}


void HistFiller::MakeNewAscii( const string &txtName , const string &cut)
{
  
  if ( m_foutput ) m_foutput -> cd();
  
  for ( int itype=0; itype< m_nDSType; itype++ ){
    for ( int iflavor=0 ; iflavor<m_nflavor ; iflavor++){
      //std::string thisAsciiName = "txt_" + m_DScategory[itype] + "_" + m_flavorChannel[iflavor] + "_" + cut ;
      std::string thisAsciiName = "txt_" + m_DScategory[itype] + "_" + m_flavorChannel[iflavor] + "_" + cut + "_"  + m_systname ; 
      //e.g. txt_Top_em_WBF_CR_Top,where cut is WBF
      //WBF is prod mod and CR_Top defines a specific cut
      
      bool onlymll = false ;
      TString thisCate = m_DScategory[itype] ;
      if ( thisCate.BeginsWith("txt_") && ( !thisCate.Contains("_500"))  ) onlymll = true;
      
      cout<<"creating new AsciiRun "<<thisAsciiName<<endl;

      m_AsciiNameMap[thisAsciiName]= new AsciiRun( thisAsciiName , onlymll );
    }
  }
  
}


void HistFiller::CloseAsciiFiles(){
  
  map<std::string, AsciiRun*>::iterator it_Map;
  for(it_Map = m_AsciiNameMap.begin(); it_Map != m_AsciiNameMap.end(); it_Map++) {
    AsciiRun* myAsciiRun = it_Map->second;
    delete myAsciiRun;
  }
  
}

bool HistFiller::AsciiIsOn(){
  if(constants::writeAsciiMode==-1){
    return false;
  }
  else if(constants::writeAsciiMode>=0){
    return true;
  }
  else{
    assert(0);
  }
  
}

void HistFiller::ReducedPlots(bool enable){
  m_reducedPlots = enable;
}


double HistFiller::getCosThetaStar(TLorentzVector V1child, TLorentzVector V1, TLorentzVector V2){
  //calculate cos( DeltaTheta(V1child, V1) ), where V1child is measured in the V1 frame, and
  //V1 is measured in the center-of-mass frame of V1+V2 system.
  //This is for case where V1+V2 is produced, then V1 decays to V1child and V1other (we don't care about V1other).
  //This is generally known as cos(Theta*).  Code has been cross-checked with Sarah Barnes from the WZ group.
  
  
  TLorentzVector boostedVDecayProd = V1child;
  
  TLorentzVector diboson = V2 + V1;
  TLorentzVector boostedV = V1;
  
  //Boost V1 and V1-child to the diboson V1+V2 reference frame
  boostedV.Boost( -diboson.BoostVector() );
  boostedVDecayProd.Boost( -diboson.BoostVector() );
  
  //Now boost V1 child to the V1 reference frame.
  boostedVDecayProd.Boost( -boostedV.BoostVector() );

  //calculate cos(Theta*)
  double cosThetaStar =  cos(  boostedVDecayProd.Angle(boostedV.Vect()) );
  
  return cosThetaStar;
  
}

double HistFiller::getCentrality(double jet1eta, double jet2eta, double obj1eta, double obj2eta){

  double maxJetEta = jet1eta;
  if(jet2eta>maxJetEta){
    maxJetEta = jet2eta;
  }
  
  double minJetEta = jet1eta;
  if(jet2eta<minJetEta){
    minJetEta = jet2eta;
  }
  double maxObjEta = obj1eta;
  double minObjEta = obj1eta;
  if(obj2eta> -100000){ //If there are only three objects, this makes sure the third object represents both maxObjEta and minObjEta
    if(obj2eta<minObjEta){
      minObjEta = obj2eta;
    }
    
    if(obj2eta>maxObjEta){
      maxObjEta = obj2eta;
    }
  }
  
  double deltaMinus = minObjEta - minJetEta;
  double deltaPlus = maxJetEta - maxObjEta;
  
  double centrality = deltaMinus;
  if(deltaPlus < centrality){
    centrality = deltaPlus;
  }
  
  //  cout<<"centrality of "<<jet1eta<<" ; "<<jet2eta<<" ; "<<obj1eta<<" ; "<<obj2eta<<"    === "<<centrality<<endl;
  
  return centrality;
  
}

double HistFiller::getMTWV(TLorentzVector diwjets, TLorentzVector lepton, TLorentzVector neutrino){
  //See http://arxiv.org/abs/0912.0715 and http://arxiv.org/abs/1204.1648 
  
  //    float val_etWlepAlt=leptonicW.Et(); //the true transverse E of W->lv            
  
  float val_etWlep=lepton.Et() + neutrino.Pt();  //"transverse E" of W->lv
  TLorentzVector leptonicW = lepton + neutrino;
  
  float val_etVjj=diwjets.Et();

  double val_pxVjj = diwjets.Px();
  double val_pyVjj = diwjets.Py();
  double val_pxWlep = leptonicW.Px();
  double val_pyWlep = leptonicW.Py();
  
  
  double mtwv = sqrt(  pow(val_etVjj+val_etWlep,2) - pow(val_pxVjj+val_pxWlep,2) - pow(val_pyVjj+val_pyWlep,2) );        
  
  return mtwv;

}

//bool  HistFiller::isOtherSignal(const int &RunNumber)
//{
//  
//  if ( 
//      ((  RunNumber >= 161351 && RunNumber <= 161375 )  ||
//       (  RunNumber >= 167930 && RunNumber <= 167948 )  ||
//       (  RunNumber >= 161401 && RunNumber <= 161425 )  ||
//       (  RunNumber >= 169130 && RunNumber <= 169148 )  ) && 
//       ( RunNumber != 167935 && RunNumber != 169135 )  
//       )
//    {
//      return true;
//    }
//  else 
//    { 
//      return false;
//    }
//  
//}

#endif // END HISTFILLER_H

