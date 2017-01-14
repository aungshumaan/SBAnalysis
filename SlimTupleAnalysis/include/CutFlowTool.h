/**
 * @file   CutFlowTool.h
 * @author Haifeng Li <Haifeng.Li@cern.ch>
 * @date   October 2010
 * @brief  Tool for cut flow
 */


#ifndef CUTFLOWTOOL_H
#define CUTFLOWTOOL_H

#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>

#include <TFile.h>
#include <TString.h>
#include <TH1F.h>

class ICutFlowTool ///abstract base class
{
 public:
  virtual ~ICutFlowTool(){};
  virtual void add( int run, std::string cut,  double EventWeight) = 0 ;
  virtual void Print() = 0 ;
  virtual void PrintI() = 0 ;
  virtual void registCut(std::string cut, std::string CutDescribe) = 0 ;
  virtual void SaveToFile( TFile *foutput )= 0;
  virtual double getCutValue(  int run, std::string cut ) = 0;
};


class CutFlowTool : public virtual ICutFlowTool
{
 public :
  CutFlowTool(){};
  

  void add( int run, std::string cut,  double EventWeight);
  void Print();
  void PrintI();
  void registCut(std::string cut, std::string CutDescribe);
  void SaveToFile( TFile *foutput);
  double getCutValue( int run, std::string cut ) ;

 private:
  typedef std::map<std::string, double> t_inner_map;   ///typeDef is a C++ thing, used to introduce aliases for data types
  typedef std::map<int, t_inner_map> t_dual_map;
  
  t_dual_map CutFlowTable;
  t_dual_map StatErrorCutFlowTable;
 
  std::map<std::string, double>::iterator itCut ;
  std::map<int, t_inner_map>::iterator itRun ;
  
  
  typedef struct {   
    std::string cut ;
    std::string cutDes ; 
  } cutV ;


  std::vector<cutV> m_cut ;
  std::vector<cutV>::iterator itV ;
  

} ;





#endif // not CUTFLOWTOOL_H



