{

  //'compile' macro
  gROOT->ProcessLine(".L ExampleLooper.C+");
  const unsigned int chainsize = 5;//6;
  TChain *ch[chainsize];
  string dataset[chainsize];

  //location of our ntuples that store all the simulated samples
  string babylocation = "/nfs-7/userdata/dsklein/tupler_babies/merged/Stop_1l/v24/skim/";    //>=1lep, >=2j, MET>150, MT>150, minDeltaPhi(j1,j2; MET)>0.5
  //string babylocation = "/nfs-7/userdata/dsklein/tupler_babies/merged/Stop_1l/v24/output/";//>=1lep, >=2j, MET>50          <-- does not contain signal
  string myhelper;

  //already split samples into groups 
  dataset[0] = "LostLeptonAndTop";
  ch[0] = new TChain("t");
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_ext1_25ns*.root";             ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_25ns*.root";                  ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root";    ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root";          ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tch_4f_powheg_pythia8_inclDecays_25ns*.root";             ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_sch_4f_amcnlo_pythia8_25ns*.root";                        ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root";             ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root";          ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "WWTo2l2Nu_powheg_25ns*.root";                               ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttWJets_13TeV_madgraphMLM*.root";                           ch[0]->Add(myhelper.c_str());
  dataset[1] = "WJets";
  ch[1] = new TChain("t");
  myhelper = babylocation + "W1JetsToLNu_madgraph_pythia8_25ns*.root";                   ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W2JetsToLNu_madgraph_pythia8_25ns*.root";                   ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W3JetsToLNu_madgraph_pythia8_25ns*.root";                   ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W4JetsToLNu_madgraph_pythia8_25ns*.root";                   ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W1JetsToLNu_nupT200_madgraph_pythia8_25ns*.root";           ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W2JetsToLNu_nupT200_madgraph_pythia8_25ns*.root";           ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W3JetsToLNu_nupT200_madgraph_pythia8_25ns*.root";           ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W4JetsToLNu_nupT200_madgraph_pythia8_25ns*.root";           ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "WWToLNuQQ_powheg_25ns*.root";                               ch[1]->Add(myhelper.c_str());
  dataset[2] = "Znunu";
  ch[2] = new TChain("t");
  myhelper = babylocation + "ZZTo2L2Nu_powheg_pythia8_25ns*.root";                       ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "ttZJets_13TeV_madgraphMLM*.root";                           ch[2]->Add(myhelper.c_str());
  myhelper = babylocation + "WZTo1L3Nu_amcnlo_pythia8_25ns*.root";                       ch[2]->Add(myhelper.c_str());

  dataset[3] = "Signal_T2tt";
  ch[3] = new TChain("t");
  myhelper = babylocation + "Signal_T2tt_mStop_150to250*.root";                          ch[3]->Add(myhelper.c_str());
  myhelper = babylocation + "Signal_T2tt_mStop_250to350*.root";                          ch[3]->Add(myhelper.c_str());
  myhelper = babylocation + "Signal_T2tt_mStop_350to400*.root";                          ch[3]->Add(myhelper.c_str());
  myhelper = babylocation + "Signal_T2tt_mStop_400to1200*.root";                         ch[3]->Add(myhelper.c_str());

  string babylocation2 = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v24_softbgenmet/skim/";    //>=1lep, >=2j, MET>150, MT>150, minDeltaPhi(j1,j2; MET)>0.5
  //string babylocation2 = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v24_softbgenmet/output/";//>=1lep, >=2j, MET>50
  dataset[4] = "SignalGen_T2tt";
  ch[4] = new TChain("t");
  myhelper = babylocation2 + "Signal_T2tt_mStop_150to250*.root";                          ch[4]->Add(myhelper.c_str());
  myhelper = babylocation2 + "Signal_T2tt_mStop_250to350*.root";                          ch[4]->Add(myhelper.c_str());
  myhelper = babylocation2 + "Signal_T2tt_mStop_350to400*.root";                          ch[4]->Add(myhelper.c_str());
  myhelper = babylocation2 + "Signal_T2tt_mStop_400to1200*.root";                         ch[4]->Add(myhelper.c_str());

  /*
  babylocation = "/nfs-7/userdata/stopRun2/analysis2016_SUS-16-051_35p9fbinv/v24/skim/";//different data format
  dataset[5] = "Data";
  ch[5] = new TChain("t");
  myhelper = babylocation + "data_met_Run*.root";                                        ch[5]->Add(myhelper.c_str());
  myhelper = babylocation + "data_single_electron_*.root";                               ch[5]->Add(myhelper.c_str());
  myhelper = babylocation + "data_single_muon_*.root";                                   ch[5]->Add(myhelper.c_str());
  */

  //run over all TChains --> see ExampleLooper.C
  for(int i = 0; i<chainsize; ++i){
    //if(i!=3) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
