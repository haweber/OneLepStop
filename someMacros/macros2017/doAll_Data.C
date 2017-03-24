{

  gROOT->ProcessLine(".L DataSR.C+");
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];


  //string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v12/output/";
  //string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v17/skim/";
  //string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22/skim/";
  string babylocation = "/hadoop/cms/store/user/haweber/AutoTwopler_babies/Stop_1l_v24/";

  string myhelper;
  
  dataset[0] = "Data";
  ch[0] = new TChain("t");
  //myhelper = babylocation + "data_met_Run*.root"; ch[0]->Add(myhelper.c_str());
  //myhelper = babylocation + "data_single_electron_Run*.root"; ch[0]->Add(myhelper.c_str());
  //myhelper = babylocation + "data_single_muon_Run*.root"; ch[0]->Add(myhelper.c_str());
  //myhelper = babylocation + "data_single_electron_Run2016B*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016B-03Feb2017_ver2-v2/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016C-03Feb2017-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016D-03Feb2017-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016E-03Feb2017-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016F-03Feb2017-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016G-03Feb2017-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016H-03Feb2017_ver2-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "MET_Run2016H-03Feb2017_ver3-v1/output/*.root"; ch[0]->Add(myhelper.c_str());
  babylocation = "/nfs-7/userdata//haweber/tupler_babies/merged/Stop_1l/v24_trulyunmerged/output/";
  myhelper = babylocation + "data_single_electron_*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_single_muon_*.root"; ch[0]->Add(myhelper.c_str());
  for(int i = 0; i<chainsize; ++i){
    //if(i!=0) continue;
    //if(i==0) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
