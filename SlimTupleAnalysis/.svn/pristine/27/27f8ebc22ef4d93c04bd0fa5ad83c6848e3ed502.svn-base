/**
 * @file   VertexWeightingTool.h
 * @author Haifeng Li <Haifeng.Li@cern.ch>
 * @date   Nov. 2011
 * @brief  
 */


#ifndef VERTEXWEIGHTINGTOOL_H_H
#define VERTEXWEIGHTINGTOOL_H_H

#include <string>
#include <iostream>

#include <TMath.h>

class VertxWeightingTool
{
 
 public :
  VertxWeightingTool(){} ;
  ~VertxWeightingTool(){} ;

 public :
  float getVertexWeight( const float &nvertex ) ; 

 private :
  
  static const int nBin = 40 ; 
  static const float VertexWeightArray[   nBin+1 ] ; 
  static const float VertexWeightContent[ nBin   ] ; 
};



const float VertxWeightingTool::VertexWeightArray  [nBin+1] = { 0.0 , 1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0 , 7.0 , 8.0 , 9.0 , 10.0 , 11.0 , 12.0 , 13.0 , 14.0 , 15.0 , 16.0 , 17.0 , 18.0 , 19.0 , 20.0 , 21.0 , 22.0 , 23.0 , 24.0 , 25.0 , 26.0 , 27.0 , 28.0 , 29.0 , 30.0 , 31.0 , 32.0 , 33.0 , 34.0 , 35.0 , 36.0 , 37.0 , 38.0 , 39.0 , 40.0 } ;
const float VertxWeightingTool::VertexWeightContent[nBin] = { 0.000000 , 1.853069 , 1.628615 , 1.420641 , 1.266993 , 1.131842 , 1.026346 , 0.930918 , 0.839155 , 0.745825 , 0.655104 , 0.560575 , 0.492689 , 0.405061 , 0.352727 , 0.317320 , 0.270691 , 0.245436 , 0.235240 , 0.223216 , 0.216957 , 0.255216 , 0.265073 , 0.453356 , 0.144335 , 8.463807 , 0.166337 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 , 0.000000 } ;



float VertxWeightingTool::getVertexWeight( const float &nvertex ) 
{
  
  if ( nvertex > 25.  ) return 0.2 ; 
  if ( nvertex < 0.   ) return 1.  ;  


  int binR  = TMath::BinarySearch( nBin+1 ,  VertexWeightArray , nvertex ) ;
  
  
  return VertexWeightContent[binR] ; 
}



#endif // not VERTEXWEIGHTINGTOOL_H_H
