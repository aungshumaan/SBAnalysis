void cutflow_CAFSlim(TString ds="167761")
{
  
  TFile* fCAF =TFile::Open(Form("/export/home/azaman/Analysis5/SlimTupleAnalysis/run/plots_nosystematics/CAF_CUTFLOW/cutflow_%s.root",ds.Data()));
  TFile* fSlim =TFile::Open(Form("/export/scratch1/azaman/lvqqNtuple/VBS_3.25/%s.lvqqMiniNtuple.root.Nominal",ds.Data()));
  TH1D* hCAF= (TH1D*)fCAF->Get("l_channel");
  double nCAF =hCAF->GetBinContent(12);

  TH1D* hSlim= (TH1D*)fSlim->Get("cutflow");
  double nSlim =hSlim->GetBinContent(1);
  cout<<ds<<endl;
  cout<<"end of CAF       = " <<nCAF<<endl;
  cout<<"start of slim    = " <<nSlim<<endl;
  cout<<"relative deviation  = " <<(nSlim-nCAF)/nCAF<<endl;
}
