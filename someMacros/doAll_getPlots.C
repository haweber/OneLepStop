{

  gSystem->Load("libMinuit2.so");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/JetUtil.cc+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/topness.cc+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/Davismt2.cc+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/MT2_implementations.cc+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/mt2w_bisect.cpp+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/mt2w.cc+");
  gROOT->ProcessLine(".L StopAnalysis/StopBabyMaker/stop_variables/chi2.cc+");


  //gROOT->ProcessLine(".L GetHistoOneCut.C+");
  // gROOT->ProcessLine(".L GetHistoCorrelations.C+");
  //gROOT->ProcessLine(".L GetCutFlow.C+");
  //gROOT->ProcessLine(".L TestBDTcreatetrees.C+");
  //gROOT->ProcessLine(".L TestIP.C+");
  //gROOT->ProcessLine(".L GetHistosDRlep.C+");
  //gROOT->ProcessLine(".L GetHistosJetInputNumbers.C+");
  //gROOT->ProcessLine(".L DoCutflow.C+");
  //gROOT->ProcessLine(".L GetGenMatching.C+");
  //
  //gROOT->ProcessLine(".L GetHistosVarious.C+");
  //
  //gROOT->ProcessLine(".L TestRun.C+");
  gROOT->ProcessLine(".L GetHistosSingleTTTbar.C+");
  const unsigned int chainsize = 8;
  TChain *ch[chainsize];
  string dataset[chainsize];


  //original "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_2jskim/
  //intermed "/nfs-7/userdata/stop2015/babies_4May2015/"
  // /nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim/
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__fullLepSelection__20150527/";
  //string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim__leptonPt15__20150603/";
  string babylocation = "/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1l_ge2j_tempsync_20150618/";
  string helper;
  dataset[0] = "TTbar";
  ch[0] = new TChain("t"); 
  helper = babylocation+"ttbar.root"; ch[0]->Add(helper.c_str());
  dataset[1] = "SingleT";
  ch[1] = new TChain("t");
  //helper = babylocation+"t_sch.root";    ch[1]->Add(helper.c_str());
  //helper = babylocation+"tbar_sch.root"; ch[1]->Add(helper.c_str());
  //helper = babylocation+"t_tch.root";    ch[1]->Add(helper.c_str());
  //helper = babylocation+"tbar_tch.root"; ch[1]->Add(helper.c_str());
  helper = babylocation+"t_tW.root";     ch[1]->Add(helper.c_str());
  helper = babylocation+"tbar_tW.root";  ch[1]->Add(helper.c_str());
  dataset[2] = "Rare";
  ch[2] = new TChain("t");
  helper = babylocation+"ttwjets.root"; ch[2]->Add(helper.c_str());
  helper = babylocation+"ttzjets.root"; ch[2]->Add(helper.c_str());
  helper = babylocation+"wzjets.root";  ch[2]->Add(helper.c_str());
  helper = babylocation+"zz.root";      ch[2]->Add(helper.c_str());
  dataset[3] = "VJets";
  ch[3] = new TChain("t"); 
  //helper = babylocation+"wjets.root";      ch[3]->Add(helper.c_str());
  helper = babylocation+"wjetsHT100.root";      ch[3]->Add(helper.c_str());
  helper = babylocation+"wjetsHT200.root";      ch[3]->Add(helper.c_str());
  helper = babylocation+"wjetsHT400.root";      ch[3]->Add(helper.c_str());
  helper = babylocation+"wjetsHT600.root";      ch[3]->Add(helper.c_str());
  helper = babylocation+"dyjets.root";      ch[3]->Add(helper.c_str());
  dataset[4] = "Stop_425_325";
  ch[4] = new TChain("t"); 
  helper = babylocation+"stop_425_325.root";      ch[4]->Add(helper.c_str());
  dataset[5] = "Stop_500_325";
  ch[5] = new TChain("t"); 
  helper = babylocation+"stop_500_325.root";      ch[5]->Add(helper.c_str());
  dataset[6] = "Stop_650_325";
  ch[6] = new TChain("t"); 
  helper = babylocation+"stop_650_325.root";      ch[6]->Add(helper.c_str());
  dataset[7] = "Stop_850_100";
  ch[7] = new TChain("t"); 
  helper = babylocation+"stop_850_100.root";      ch[7]->Add(helper.c_str());

  for(int i = 0; i<chainsize; ++i){
    ScanChain(ch[i],true,-1,dataset[i]); 
  }

  //gROOT->ProcessLine(".x StudyRootFiles.C+");
  //gROOT->ProcessLine(".L dataMCplotMaker.cc+");
  //gROOT->ProcessLine(".x makePlotPlot.C+");
  //
  //gROOT->ProcessLine(".x TestPlot.C+");
  //
  //gROOT->ProcessLine(".x makePlotCutFlow.C+");
  //gROOT->ProcessLine(".x GetSRTable.C+");
  //gROOT->ProcessLine(".x GetCFNumbers.C+");
  //
  //gROOT->ProcessLine(".x makePlotIP.C+");
}
