{

  gROOT->ProcessLine(".L TriggerEfficienciesHistos.C+");
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];


  string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v9/output/";
  string myhelper;
  
  dataset[0] = "dataPFHT";
  ch[0] = new TChain("t");
  myhelper = babylocation + "data_jetht_Run2016B_MINIAOD_23Sep2016-v3.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016C_MINIAOD_23Sep2016-v1.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016D_MINIAOD_23Sep2016-v1.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016E_MINIAOD_23Sep2016-v1.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016F_MINIAOD_23Sep2016-v1.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016G_MINIAOD_23Sep2016-v1.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016H_MINIAOD_PromptReco-v2.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_jetht_Run2016H_MINIAOD_PromptReco-v3.root"; ch[0]->Add(myhelper.c_str());

  for(int i = 0; i<chainsize; ++i){
    //if(i!=0) continue;
    //if(i==0) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
