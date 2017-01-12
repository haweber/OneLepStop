{

  gROOT->ProcessLine(".L BTagInputs.C+");
  const unsigned int chainsize = 3;
  TChain *ch[chainsize];
  string dataset[chainsize];
  float extraweight[chainsize];

  //string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v9/output/";
  //string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v11/output/";
  string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v16_Moriond17MC/output/"/
  string myhelper;
  
  dataset[0] = "TT";
  ch[0] = new TChain("t");
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());
  dataset[1] = "W";
  ch[1] = new TChain("t");
  myhelper = babylocation + "W1*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W2*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W3*.root"; ch[1]->Add(myhelper.c_str());
  myhelper = babylocation + "W4*.root"; ch[1]->Add(myhelper.c_str());

  babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l_2016/stop_babies_V080009_signal_norm_v2/merged_files/";
  dataset[2] = "Signal";
  ch[2] = new TChain("t");
  myhelper = babylocation + "Signal*.root"; ch[2]->Add(myhelper.c_str());

	
  for(int i = 0; i<chainsize; ++i){
    //if(i!=0) continue;
    //if(i==0) continue;
    if(i==2) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
