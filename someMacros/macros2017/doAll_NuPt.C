{

  bool getNuOrNunuPt = false;
  bool getPhotPt = true;
  bool getPhotMETshape = false;
  bool applyPhotMETresToTT = false;

  if(getNuOrNunuPt){
    gROOT->ProcessLine(".L NuOrNunuPt.C+");
    const unsigned int chainsize = 1;
    TChain *ch[chainsize];
    string dataset[chainsize];
    float extraweight[chainsize];

    //string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v9/output/";
    string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v18/output/";
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
    myhelper = babylocation + "t_sch_4f_amcnlo_pythia8_25ns.root*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());

    for(int i = 0; i<chainsize; ++i){
      //if(i!=0) continue;
      //if(i==0) continue;
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      ScanChain(mych,true,-1,mydataset); 
    }
  }
  if(getPhotPt||getPhotMETshape){
    if(getPhotPt) gROOT->ProcessLine(".L PhotJetsPt.C+");
    else if(getPhotMETshape) gROOT->ProcessLine(".L PhotMETDistributions.C+");
    const unsigned int chainsize = 2;
    TChain *ch[chainsize];
    string dataset[chainsize];
    float extraweight[chainsize];
       string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_photonstemp/output/";
    string myhelper;
  
    dataset[0] = "PhotonMC";
    ch[0] = new TChain("t");
    myhelper = babylocation + "GJets_DR0p4_HT100to200_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_DR0p4_HT200to400_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_DR0p4_HT40to100_25ns*.root";  ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_DR0p4_HT600toInf_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT100to200_25ns*.root";       ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT200to400_25ns*.root";       ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT400to600_25ns*.root";       ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT40to100_25ns*.root";        ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT600toInf_25ns*.root";       ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "GJets_HT600toInf_ext1_25ns*.root";  ch[0]->Add(myhelper.c_str());
    dataset[1] = "PhotonData";
    ch[1] = new TChain("t");
    myhelper = babylocation + "data_singlephoton_Run2016B_23Sep2016_v3*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016C_23Sep2016_v1*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016D_23Sep2016_v1*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016E_23Sep2016_v1*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016F_23Sep2016_v1*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016G_23Sep2016_v1*.root";  ch[1]->Add(myhelper.c_str());
    myhelper = babylocation + "data_singlephoton_Run2016H_PromptReco_v2*.root"; ch[1]->Add(myhelper.c_str());//apparently v3 got merged into this

      for(int i = 0; i<chainsize; ++i){
      //if(i!=0) continue;
      //if(i==0) continue;
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      ScanChain(mych,true,-1,mydataset); 
    }
  }
   if(applyPhotMETresToTT){
     //gROOT->ProcessLine(".L /home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/JetUtil.cc++");
     //gROOT->ProcessLine(".L /home/users/haweber/StopAnalysis/AnalysisCode/StopAnalysis/StopBabyMaker/stop_variables/topness.cc++");

    gROOT->ProcessLine(".L CheckResolution.C++");
    const unsigned int chainsize = 1;
    TChain *ch[chainsize];
    string dataset[chainsize];
    float extraweight[chainsize];

    //string babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v9/output/";
    string babylocation = "/nfs-7/userdata/isuarez/tupler_babies/merged/Stop_1l/v18/output/";
    string myhelper;
  
    dataset[0] = "all";
    ch[0] = new TChain("t");
    myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
    //myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_25ns*.root"; ch[0]->Add(myhelper.c_str());
    //myhelper = babylocation + "ttbar_diLept_madgraph_pythia8_ext1_25ns*.root"; ch[0]->Add(myhelper.c_str());
    //myhelper = babylocation + "t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());
    //myhelper = babylocation + "t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "t_sch_4f_amcnlo_pythia8_25ns.root*.root"; ch[0]->Add(myhelper.c_str());
    myhelper = babylocation + "tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root"; ch[0]->Add(myhelper.c_str());

    for(int i = 0; i<chainsize; ++i){
      //if(i!=0) continue;
      //if(i==0) continue;
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      ScanChain(mych,true,-1,mydataset); 
    }
  }
}
