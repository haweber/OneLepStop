{

  gSystem->Load("libMinuit2.so");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/JetUtil.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/Topness.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/topness.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/Davismt2.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.cpp+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/mt2w.cc+");
  //gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/chi2.cc+");


  gROOT->ProcessLine(".L SyncCutflow.C+");//>=v3
  //gROOT->ProcessLine(".L SyncCutflowM3b.C+");//<=v1
  const unsigned int chainsize = 2;
  TChain *ch[chainsize];
  string dataset[chainsize];


  //original "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_2jskim/
  //intermed "/nfs-7/userdata/stop2015/babies_4May2015/"
  // /nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim/
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__fullLepSelection__20150527/";
  string babylocation = "/home/users/haweber/syncfiles/v4/";
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__leptonPt15__20150603/";
  string helper;
  dataset[0] = "Stop_650_325";
  ch[0] = new TChain("t"); 
  helper = babylocation+"stop_650_325.root";      ch[0]->Add(helper.c_str());
  //ch[0]->Add("/home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/stop_650_325.root");
  dataset[1] = "Stop_850_100";
  ch[1] = new TChain("t"); 
  helper = babylocation+"stop_850_100.root";      ch[1]->Add(helper.c_str());

  for(int i = 0; i<chainsize; ++i){
    ScanChain(ch[i],true,-1,dataset[i]); 
  }

}
