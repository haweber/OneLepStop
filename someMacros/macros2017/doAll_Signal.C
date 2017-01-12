{
  int whichsignal = 1;//1 T2tt, 2 T2bW, 3 T2tb - if -1 all three
  bool genMET = false;
 
  const unsigned int chainsize = 3;
  TChain *ch[chainsize];
  string dataset[chainsize];
  string myhelper;
  string babylocation;

  //normal
  if(!genMET){
    gROOT->ProcessLine(".L GetSignalHistosGen.C+");
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_gen_v2/merged_files/";
    dataset[0] = "Signal_T2tt";
    ch[0] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt*.root"; ch[0]->Add(myhelper.c_str());
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_gen_v2/merged_files/";
    dataset[1] = "Signal_T2bW";
    ch[1] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2bW*.root"; ch[1]->Add(myhelper.c_str());
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_gen_v2/merged_files/";
    dataset[2] = "Signal_T2tb";
    ch[2] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tb*.root"; ch[2]->Add(myhelper.c_str());
  }
  else {
    gROOT->ProcessLine(".L GetSignalHistos.C+");
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_norm_v2/merged_files/";
    dataset[0] = "Signal_T2tt";
    ch[0] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt*.root"; ch[0]->Add(myhelper.c_str());
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_norm_v2/merged_files/";
    dataset[1] = "Signal_T2bW";
    ch[1] = new TChain("t"); 
    babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_norm_v2/merged_files/";
    dataset[2] = "Signal_T2tb";
    ch[2] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tb*.root"; ch[2]->Add(myhelper.c_str());
  }
  for(int i = 0; i<chainsize; ++i){
    if(whichsignal>=0&&i!=(whichsignal-1)) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    cout << i << " " << mydataset << " " << mych->GetEntries() << endl;
    ScanChain(mych,true,-1,mydataset); 
  }


}
