{
  int jes = -1;
  
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];
  string myhelper;
  string babylocation;

  //normal
  if(abs(jes)!=1){
    gROOT->ProcessLine(".L GetSignalHistos.C+");
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_v0704x_v7_20160106/merged_files/";
    dataset[0] = "Signal_T2tt";
    ch[0] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt.root"; ch[0]->Add(myhelper.c_str());
  }
  //JESup/down
  if(abs(jes)==1){
    gROOT->ProcessLine(".L GetSignalHistosJES.C+");
    //JESup
    if(jes==1){
      babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_v0704x_v7_20160106_JESup/merged_files/";
      dataset[0] = "Signal_T2tt_JESup";
    }
    //JESdown
    if(jes==(-1)) {
      babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_v0704x_v7_20160106_JESdown/merged_files/";
      dataset[0] = "Signal_T2tt_JESdown";
    }
    ch[0] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt.root"; ch[0]->Add(myhelper.c_str());
  }
  for(int i = 0; i<chainsize; ++i){
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 
  }


}
