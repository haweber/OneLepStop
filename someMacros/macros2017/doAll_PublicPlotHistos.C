{

  gROOT->ProcessLine(".L PublicPlotHistos.C+");
  const unsigned int chainsize = 16;
  TChain *ch[chainsize];
  string dataset[chainsize];


  string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v17/output/";
  string myhelper;
  
  dataset[0] = "Data";
  ch[0] = new TChain("t");
  myhelper = babylocation + "data_met_Run*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_single_electron_Run*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "data_single_muon_Run*.root"; ch[0]->Add(myhelper.c_str());

  babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v18/output/";

  dataset[1] = "Top";
  ch[1] = new TChain("t");
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_ext1_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "t_sch_4f_amcnlo_pythia8_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "WWTo2l2Nu_powheg_25ns*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "ttWJets_13TeV_madgraphMLM*.root"; ch[1]->Add(myhelper.c_str());
  dataset[2] = "WJets";
  ch[2] = new TChain("t");
  myhelper = babylocation + "W1JetsToLNu_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W2JetsToLNu_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W3JetsToLNu_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W4JetsToLNu_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W1JetsToLNu_nupT200_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W2JetsToLNu_nupT200_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W3JetsToLNu_nupT200_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "W4JetsToLNu_nupT200_madgraph_pythia8_25ns*.root"; ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "WWToLNuQQ_powheg_25ns*.root"; ch[2]->Add(myhelper.c_str());
  dataset[3] = "Znunu";
  ch[3] = new TChain("t");
  myhelper = babylocation + "ZZTo2L2Nu_powheg_pythia8_25ns*.root"; ch[3]->Add(myhelper.c_str());
  myhelper = babylocation + "ttZJets_13TeV_madgraphMLM*.root"; ch[3]->Add(myhelper.c_str());
  myhelper = babylocation + "WZTo1L3Nu_amcnlo_pythia8_25ns*.root"; ch[3]->Add(myhelper.c_str());
  //myhelper = babylocation + "tZq_ll_4f_amcatnlo-pythia8_25ns*.root"; ch[3]->Add(myhelper.c_str());

  babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v17/output/";
  babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_tempSignal_reco_oldJEC/output/";
  //Signal_T2bW_850_50
  dataset[4] = "Signal_T2bW_850_50";
  ch[4] = new TChain("t");
  myhelper = babylocation + "Signal_T2bW*.root"; ch[4]->Add(myhelper.c_str());
  //Signal_T2bW_850_300
  dataset[5] = "Signal_T2bW_850_300";
  ch[5] = new TChain("t");
  myhelper = babylocation + "Signal_T2bW*.root"; ch[5]->Add(myhelper.c_str());
  //Signal_T2bW_500_300
  dataset[6] = "Signal_T2bW_500_300";
  ch[6] = new TChain("t");
  myhelper = babylocation + "Signal_T2bW*.root"; ch[6]->Add(myhelper.c_str());
  //Signal_T2tb_900_50
  dataset[7] = "Signal_T2tb_900_50";
  ch[7] = new TChain("t");
  myhelper = babylocation + "Signal_T2tb*.root"; ch[7]->Add(myhelper.c_str());
  //Signal_T2tb_850_300
  dataset[8] = "Signal_T2tb_850_300";
  ch[8] = new TChain("t");
  myhelper = babylocation + "Signal_T2tb*.root"; ch[8]->Add(myhelper.c_str());
  //Signal_T2tb_500_300
  dataset[9] = "Signal_T2tb_500_300";
  ch[9] = new TChain("t");
  myhelper = babylocation + "Signal_T2tb*.root"; ch[9]->Add(myhelper.c_str());
  //Signal_T2tt_950_50
  dataset[10] = "Signal_T2tt_950_50";
  ch[10] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root"; ch[10]->Add(myhelper.c_str());
  //Signal_T2tt_950_300
  dataset[11] = "Signal_T2tt_950_300";
  ch[11] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root"; ch[11]->Add(myhelper.c_str());
  //Signal_T2tt_600_400
  dataset[12] = "Signal_T2tt_600_400";
  ch[12] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root"; ch[12]->Add(myhelper.c_str());
  //Signal_T2tt_425_300
  dataset[13] = "Signal_T2tt_425_300";
  ch[13] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root"; ch[13]->Add(myhelper.c_str());
  //Signal_T2tt_425_250
  dataset[14] = "Signal_T2tt_425_250";
  ch[14] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root"; ch[14]->Add(myhelper.c_str());
  //Signal_T2tt_350_250
  dataset[15] = "Signal_T2tt_350_250";
  ch[15] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_350to400*.root"; ch[15]->Add(myhelper.c_str());
  
  for(int i = 0; i<chainsize; ++i){
    if(i!=0) continue;
    //if(i==0) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
