{


  //
  gROOT->ProcessLine(".L MakeDataCardInputs.C+");
  const unsigned int chainsize = 5;
  TChain *ch[chainsize];
  string dataset[chainsize];

  //gROOT->ProcessLine("cout << 1 << endl;");

  //original "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_2jskim/
  //intermed "/nfs-7/userdata/stop2015/babies_4May2015/"
  // /nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim/
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__fullLepSelection__20150527/";
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__leptonPt15__20150603/";
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1l_ge2j_tempsync_20150618/";
  string babylocation = "/nfs-7/userdata/stopRun2/StopBabies__CMS3_V07-02-08/Phys14_Samples/StopBabyMaker__v7.4.x_v0/Skim__METge30__LEPge1_elPt40_elEta2p1_muPt30_muEta2p1__JETge2_jPt30_jEta2p4__20150628/";
  string myhelper;
  dataset[0] = "TTbar";
  ch[0] = new TChain("t"); 
  myhelper = babylocation+"ttbar.root"; ch[0]->Add(myhelper.c_str());
  dataset[1] = "SingleTop";
  ch[1] = new TChain("t");
  myhelper = babylocation+"t_sch.root";    ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"tbar_sch.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"t_tch.root";    ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"tbar_tch.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"t_tW.root";     ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"tbar_tW.root";  ch[1]->Add(myhelper.c_str());
  dataset[2] = "TTV";
  ch[2] = new TChain("t");
  myhelper = babylocation+"ttwjets.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"ttzjets.root"; ch[2]->Add(myhelper.c_str());
  //myhelper = babylocation+"wzjets.root";  ch[2]->Add(myhelper.c_str());
  //myhelper = babylocation+"zz.root";      ch[2]->Add(myhelper.c_str());
  //myhelper = babylocation+"dyjets.root";      ch[2]->Add(myhelper.c_str());
  dataset[3] = "WJets";
  ch[3] = new TChain("t"); 
  //myhelper = babylocation+"wjets.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"wjetsHT100.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"wjetsHT200.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"wjetsHT400.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"wjetsHT600.root";      ch[3]->Add(myhelper.c_str());
  //myhelper = babylocation+"dyjets.root";      ch[3]->Add(myhelper.c_str());
  //dataset[4] = "Stop_425_325";
  dataset[4] = "Signal_T2tt";
  ch[4] = new TChain("t"); 
  myhelper = babylocation+"stop_425_325.root";      ch[4]->Add(myhelper.c_str());
  myhelper = babylocation+"stop_500_325.root";      ch[4]->Add(myhelper.c_str());
  myhelper = babylocation+"stop_650_325.root";      ch[4]->Add(myhelper.c_str());
  myhelper = babylocation+"stop_850_100.root";      ch[4]->Add(myhelper.c_str());
  //dataset[5] = "Stop_500_325";
  //ch[5] = new TChain("t"); 
  //myhelper = babylocation+"stop_500_325.root";      ch[5]->Add(myhelper.c_str());
  //dataset[6] = "Stop_650_325";
  //ch[6] = new TChain("t"); 
  //myhelper = babylocation+"stop_650_325.root";      ch[6]->Add(myhelper.c_str());
  //dataset[7] = "Stop_850_100";
  //ch[7] = new TChain("t"); 
  //myhelper = babylocation+"stop_850_100.root";      ch[7]->Add(myhelper.c_str());

  for(int i = 0; i<chainsize; ++i){
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }

  //gROOT->ProcessLine(".x StudyRootFiles.C+");
}
