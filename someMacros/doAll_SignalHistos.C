{
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];
  string myhelper;
  string babylocation;

  //normal
  gROOT->ProcessLine(".L GetSignalHistos.C+");
  babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_v0704x_v7_20160106/merged_files/";
  dataset[0] = "Signal_T2tt";
  ch[0] = new TChain("t"); 
  myhelper = babylocation+"Signal_T2tt.root"; ch[0]->Add(myhelper.c_str());
  //JESup

  //JESdown

  for(int i = 0; i<chainsize; ++i){
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 
  }


}
