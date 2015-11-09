{

  //gSystem->Load("libMinuit2.so");
  gROOT->ProcessLine(".L MakeDataCardInputs.C+");

  const unsigned int chainsize = 18;
  TChain *ch[chainsize];
  string ds[chainsize];

  string babylocation = "/nfs-7/userdata/stopRun2/StopBabies__CMS3_V07-04-XX/Spring15_25ns_Samples/StopBabyMaker__v7.4.x_v5/Skim__METge30__LEPge1_elPt20_elEta2p1_muPt20_muEta2p1_vetoElPt5_vetoElEta2p4_vetoMuPt5_vetoMuEta2p4__JETge1_jPt30_jEta2p4__20150728/";
  string myhelper;
  ds[ 0] = "TTbar";
  ch[ 0] = new TChain("t"); 
  myhelper = babylocation+"ttbar_powheg_pythia8_25ns.root"; ch[0]->Add(myhelper.c_str());
  ds[ 1] = "SingleT";
  ch[ 1] = new TChain("t");
  myhelper = babylocation+"t_tW_5f_powheg_pythia8_25ns.root";     ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"t_tbarW_5f_powheg_pythia8_25ns.root";  ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"t_tch_4f_powheg_pythia8_25ns.root";    ch[1]->Add(myhelper.c_str());
  myhelper = babylocation+"tbar_tch_4f_powheg_pythia8_25ns.root"; ch[1]->Add(myhelper.c_str());
  ds[ 2] = "Rare";
  ch[ 2] = new TChain("t");
  myhelper = babylocation+"TTWJetsToLNu_amcnlo_pythia8_25ns.root";     ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"TTZToLLNuNu_M-10_amcnlo_pythia8_25ns.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"TTZToQQ_amcnlo_pythia8_25ns.root";          ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"tZq_ll_4f_amcnlo_pythia8_25ns.root";        ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"tZq_nunu_4f_amcnlo_pythia8_25ns.root";      ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"WWTo2l2Nu_powheg_25ns.root";                ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"WWToLNuQQ_powheg_25ns.root";                ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"WZTo1Lnu2Q_amcnlo_pythia8_25ns.root";       ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"WZTo2L2Q_amcnlo_pythia8_25ns.root";         ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"WZTo3LNu_powheg_pythia8_25ns.root";         ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"ZZTo2L2Nu_powheg_pythia8_25ns.root";        ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"ZZTo2L2Q_amcnlo_pythia8_25ns.root";         ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"ZZTo2Q2Nu_amcnlo_pythia8_25ns.root";        ch[2]->Add(myhelper.c_str());
  myhelper = babylocation+"ZZTo4L_powheg_pythia8_25ns.root";           ch[2]->Add(myhelper.c_str());
  //myhelper = babylocation+"zz.root";      ch[2]->Add(myhelper.c_str());
  ds[ 3] = "WJets";
  ch[ 3] = new TChain("t"); 
  myhelper = babylocation+"WJetsToLNu_HT100To200_madgraph_pythia8_25ns.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"WJetsToLNu_HT200To400_madgraph_pythia8_25ns.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"WJetsToLNu_HT400To600_madgraph_pythia8_25ns.root";      ch[3]->Add(myhelper.c_str());
  myhelper = babylocation+"WJetsToLNu_HT600ToInf_madgraph_pythia8_25ns.root";      ch[3]->Add(myhelper.c_str());
  ds[ 4] = "DYJets";
  ch[ 4] = new TChain("t"); 
  myhelper = babylocation+"DYJetsToLL_m10To50_amcnlo_pythia8_25ns.root";  ch[4]->Add(myhelper.c_str());
  myhelper = babylocation+"DYJetsToLL_m50_amcnlo_pythia8_25ns.root";      ch[4]->Add(myhelper.c_str());
  babylocation = "/nfs-7/userdata/stopRun2/CMS3_V07-04-XX/v7.4.x_v5/";
  ds[ 5] = "Signal_T2bw_600_187p5_50";
  ch[ 5] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_600_187p5_50.root";     ch[ 5]->Add(myhelper.c_str());
  ds[ 6] = "Signal_T2bw_600_325_50";
  ch[ 6] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_600_325_50.root";       ch[ 6]->Add(myhelper.c_str());
  ds[ 7] = "Signal_T2bw_600_462p5_50";
  ch[ 7] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_600_462p5_50.root";     ch[ 7]->Add(myhelper.c_str());
  ds[ 8] = "Signal_T2bw_700_250_100";
  ch[ 8] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_700_250_100.root";      ch[ 8]->Add(myhelper.c_str());
  ds[ 9] = "Signal_T2bw_700_400_100";
  ch[ 9] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_700_400_100.root";      ch[ 9]->Add(myhelper.c_str());
  ds[10] = "Signal_T2bw_700_550_100";
  ch[10] = new TChain("t"); 
  myhelper = babylocation+"priv_T2bw_700_550_100.root";      ch[10]->Add(myhelper.c_str());
  ds[11] = "Signal_T2tb_700_250_100";
  ch[11] = new TChain("t"); 
  myhelper = babylocation+"priv_T2tb_700_250_100.root";      ch[11]->Add(myhelper.c_str());
  ds[12] = "Signal_T2tb_700_400_100";
  ch[12] = new TChain("t"); 
  myhelper = babylocation+"priv_T2tb_700_400_100.root";      ch[12]->Add(myhelper.c_str());
  ds[13] = "Signal_T2tb_700_550_100";
  ch[13] = new TChain("t"); 
  myhelper = babylocation+"priv_T2tb_700_550_100.root";      ch[13]->Add(myhelper.c_str());
  babylocation = "/home/users/jgwood/Stop_1Lepton/phys14Samples_cmssw74x_babyMaker/CMSSW_7_2_0/src/StopAnalysis/StopBabyMaker/";
  ds[14] = "Signal_T2tt_425_325";
  ch[14] = new TChain("t"); 
  myhelper = babylocation+"stop_425_325.root";      ch[14]->Add(myhelper.c_str());
  ds[15] = "Signal_T2tt_500_325";
  ch[15] = new TChain("t"); 
  myhelper = babylocation+"stop_500_325.root";      ch[15]->Add(myhelper.c_str());
  ds[16] = "Signal_T2tt_650_325";
  ch[16] = new TChain("t"); 
  myhelper = babylocation+"stop_650_325.root";      ch[16]->Add(myhelper.c_str());
  ds[17] = "Signal_T2tt_850_100";
  ch[17] = new TChain("t"); 
  myhelper = babylocation+"stop_850_100.root";      ch[17]->Add(myhelper.c_str());
  
  for(int i = 0; i<chainsize; ++i){
    TChain *mych = ch[i];
    string mydataset = ds[i];
    ScanChain(mych,true,-1,mydataset); 
  }

}
