{

  //gROOT->ProcessLine(".L PublicPlotHistos.C+");
  gROOT->ProcessLine(".L GetSignalHistosTTH.C+");
  //gROOT->ProcessLine(".L testCRAZY.C+");
  //gROOT->ProcessLine(".L InvestigatettZttH.C+");
  const unsigned int chainsize = 2;
  TChain *ch[chainsize];
  string dataset[chainsize];


  string babylocation = "/home/users/haweber/stopifyTTH/StopAnalysis/StopBabyMaker/";
  string myhelper;
  
  dataset[0] = "ttH_125";
  ch[0] = new TChain("t");
  myhelper = babylocation + "tth_Private80X.root"; ch[0]->Add(myhelper.c_str());
  dataset[1] = "ttZ";
  ch[1] = new TChain("t");
  myhelper = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22/output/ttZJets_13TeV_madgraphMLM*.root"; ch[1]->Add(myhelper.c_str());

  for(int i = 0; i<chainsize; ++i){
    if(i==1) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
