{
  TFile *f = TFile::Open("/export/home/azaman/CAFProd/HWWlvqqCode/external/UJInput2012.root");

  TH3F* h3_pt = (TH3F*)f->Get("CamKt12LCTopoSplitFilteredmassFraction67minSplitR0_pT");
  TH3F* h3_mass = (TH3F*)f->Get("CamKt12LCTopoSplitFilteredmassFraction67minSplitR0_m");
  
  int nx= h3_mass->GetNbinsX();
  int ny= h3_mass->GetNbinsY();
  int nz= h3_mass->GetNbinsZ();

  //cout<<nx<<" "<<ny<<" "<<nz<<endl;
  ofstream ofs ("test.txt", std::ofstream::out);
  
  for (int iz =1; iz<= nz; iz++){
    for (int iy =1; iy<= ny; iy++){
      for (int ix =1; ix<= nx; ix++){
	//ofs<<  h3_pt -> GetBinContent(ix,iy,iz)<<" ";
	
      }
      //ofs<<"\n";
      for (int ix =1; ix<= nx; ix++){
	ofs<<  h3_mass -> GetBinContent(ix,iy,iz)<<" ";
      }
      //cout<<"\n===="<<ix<<","<<iy<<"====\n";
      //ofs<<"\n========\n";
      ofs<<"\n";
    }
  }
  
  
}
