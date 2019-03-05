{
  bool dropsigcont = false;//if testing influence of sig contamination - turn true when testing few mass points
  bool correlated = true;  //if testing correlations - probably not
  bool fakedata=false; bool nosigsyst=false; bool nobgsyst=false;//don't change these
  int analysis = 0;//0 - std, 1 - compressed
  TString mysignal = "T2tb_33_67";
  /*
  signaltype = "T2tt";
  signaltype = "T2tt_lefthanded";
  signaltype = "T2tt_righthanded";
  signaltype = "T2bW";
  signaltype = "T2tb";
  signaltype = "T2tb_50_50";
  signaltype = "T2tb_0_100";
  signaltype = "T2tb_100_0";
  signaltype = "T2tb_75_25";
  signaltype = "T2tb_25_75";
  signaltype = "T2tb_67_33";
  signaltype = "T2tb_33_67";
  */

  gROOT->ProcessLine(".L makeDataCards_codingcopy.C+");
  //gROOT->ProcessLine(".L makeDataCards_BSforFrank.C+");

  //real datacard making
  makeDataCardsOneScan(mysignal,analysis,dropsigcont,correlated,fakedata,nosigsyst,nobgsyst);
  //makeDataCardsOneScan(3,mysignal,analysis,dropsigcont,correlated,fakedata,nosigsyst,nobgsyst);

  //for certain tests like sig cont - run only few masses
  //int mStop = 900; int mLSP = 50;
  //makeDataCardsAllBins(mysignal,analysis,dropsigcont,correlated,mStop,mLSP,-1,-1,fakedata,true,nobgsyst);
  
}
