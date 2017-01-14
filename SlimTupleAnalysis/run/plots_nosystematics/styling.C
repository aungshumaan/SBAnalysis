#include "TStyle.h"
void styling()
{

  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(kFALSE);

  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleFillColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetPalette(1);
  

}
