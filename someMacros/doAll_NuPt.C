{

  gROOT->ProcessLine(".L NuOrNunuPt.C+");
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];
  float extraweight[chainsize];

  //string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v9/output/";
  string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v11/output/";
  string myhelper;
  
  dataset[0] = "all";
  ch[0] = new TChain("t");
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());
  myhelper = babylocation + "t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());

  for(int i = 0; i<chainsize; ++i){
    //if(i!=0) continue;
    //if(i==0) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 

  }
}
