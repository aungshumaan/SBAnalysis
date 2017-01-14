#include <iostream>
void upperLimit(double s=0, double b=0){
  //double s,b;
  //cout<<"What is signal and bkg?"<<endl;
  //cin>> s >>endl;
  //cin>> b >>endl;
  double signal =s;
  cout<< "signal = "<<signal <<endl;
  double bkg =b;
  double expected = signal + bkg;
  cout<< "expected = "<<expected <<endl;
  double unc = sqrt(expected);
  cout<< "uncertainty = "<<unc<<endl;
  double sup = expected + 1.68 * unc - bkg;
  cout<< "signal upper limit  = "<<sup<<endl;
}
