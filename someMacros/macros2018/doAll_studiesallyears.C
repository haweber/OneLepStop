{

  //'compile' macro
  gROOT->ProcessLine(".L TTZNBfit.C+");

  //location of our ntuples that store all the simulated samples
  string dirdata2016   = "/nfs-7/userdata/sicheng/stopbabies/merged/data_v30_3/";    //>=1lep, >=2j, MET>150
  string dirdata2017   = "/nfs-7/userdata/sicheng/stopbabies/merged/data_v30_3/";    //>=1lep, >=2j, MET>150
  string dirdata2018   = "/nfs-7/userdata/sicheng/stopbabies/merged/data_v30_3/";    //>=1lep, >=2j, MET>150
  //string dirmc2016   = "/nfs-7/userdata/sicheng/stopbabies/merged/s16v3_v30_3/";    //>=1lep, >=2j, MET>150
  string dirmc2016     = "/nfs-7/userdata/sicheng/stopbabies/merged/s16v3_v29_14/";    //>=1lep, >=2j, MET>150
  string dirmc2017     = "/nfs-7/userdata/sicheng/stopbabies/merged/f17v2_v30_7/";   //>=1lep, >=2j, MET>150
  string dirmc2018     = "/nfs-7/userdata/sicheng/stopbabies/merged/a18v1_v30_7/";    //>=1lep, >=2j, MET>150
  string myhelper;


  //int year = 2016;
  for(int year = 2016; year <= 2018; ++year){
    const unsigned int chainsize = 5;
    TChain *ch[chainsize];
    string dataset[chainsize];

    
    //already split samples into groups 
    dataset[0] = "LostLeptonAndTop";
    ch[0] = new TChain("t");
    if(year==2016){
      myhelper = dirmc2016 + "TTJets_*.root";                      ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "TTWJetsToLNu_*.root";                ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "ST_*.root";                          ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "WWTo2L2Nu_*.root";                   ch[0]->Add(myhelper.c_str());
    }
    
    if(year==2017){
      myhelper = dirmc2017 + "TTJets_*.root";                      ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "TTWJetsToLNu_*.root";                ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "ST_*.root";                          ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "WWTo2L2Nu_*.root";                   ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "ZZTo2L2Nu_*.root";                   ch[0]->Add(myhelper.c_str());
    }
    
    if(year==2018){
      myhelper = dirmc2018 + "TTJets_*.root";                      ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2018 + "TTWJetsToLNu_*.root";                ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2018 + "ST_*.root";                          ch[0]->Add(myhelper.c_str());
      myhelper = dirmc2018 + "ZZTo2L2Nu_*.root";                   ch[0]->Add(myhelper.c_str());
    }
    dataset[1] = "WJets";
    ch[1] = new TChain("t");
    if(year==2016){
      myhelper = dirmc2016 + "W*JetsToLNu_*.root";                 ch[1]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "W*Jets_NuPt200_*.root";              ch[1]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "WZTo1L1Nu2Q_*.root";                 ch[1]->Add(myhelper.c_str());
    }
    if(year==2017){
      myhelper = dirmc2017 + "W*JetsToLNu_*.root";                 ch[1]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "W*Jets_NuPt200_*.root";              ch[1]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "WZTo1L1Nu2Q_*.root";                 ch[1]->Add(myhelper.c_str());
    }
    if(year==2018){
      myhelper = dirmc2018 + "W*JetsToLNu_*.root";                 ch[1]->Add(myhelper.c_str());
      myhelper = dirmc2018 + "W*Jets_NuPt200_*.root";              ch[1]->Add(myhelper.c_str());
    }

    /*
    dataset[2] = "Znunu";
    ch[2] = new TChain("t");
    if(year==2016){
      myhelper = dirmc2016 + "TTZToLLNuNu_*.root";                 ch[2]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "WZTo1L3Nu_*.root";                   ch[2]->Add(myhelper.c_str());
    }
    if(year==2017){
      myhelper = dirmc2017 + "TTZToLLNuNu_*.root";                 ch[2]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "WZTo1L3Nu_*.root";                   ch[2]->Add(myhelper.c_str());
    }
    if(year==2018){
      myhelper = dirmc2018 + "TTZToLLNuNu_*.root";                 ch[2]->Add(myhelper.c_str());
    }
    */
    dataset[2] = "TTZ";
    ch[2] = new TChain("t");
    if(year==2016){
      myhelper = dirmc2016 + "TTZToLLNuNu_*.root";                 ch[2]->Add(myhelper.c_str());
      //myhelper = dirmc2016 + "WZTo1L3Nu_*.root";                   ch[2]->Add(myhelper.c_str());
    }
    if(year==2017){
      myhelper = dirmc2017 + "TTZToLLNuNu_*.root";                 ch[2]->Add(myhelper.c_str());
      //myhelper = dirmc2017 + "WZTo1L3Nu_*.root";                   ch[2]->Add(myhelper.c_str());
    }
    if(year==2018){
      myhelper = dirmc2018 + "TTZToLLNu_*.root";                 ch[2]->Add(myhelper.c_str());
    }
    
    dataset[3] = "Data";
    ch[3] = new TChain("t");
    if(year==2016){
      myhelper = dirdata2016 + "data_2016*_singleel*.root"; ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2016 + "data_2016*_singlemu*.root"; ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2016 + "data_2016*_muoneg*.root";   ch[3]->Add(myhelper.c_str());
    }
    if(year==2017){
      myhelper = dirdata2017 + "data_2017*_singleel*.root"; ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2017 + "data_2017*_singlemu*.root"; ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2017 + "data_2017*_muoneg*.root";   ch[3]->Add(myhelper.c_str());
    }
    if(year==2018){
      myhelper = dirdata2017 + "data_2018*_egamma*.root";   ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2017 + "data_2018*_singlemu*.root"; ch[3]->Add(myhelper.c_str());
      myhelper = dirdata2017 + "data_2018*_muoneg*.root";   ch[3]->Add(myhelper.c_str());
    }

    dataset[4] = "WZ";
    ch[4] = new TChain("t");
    if(year==2016){
      myhelper = dirmc2016 + "WZTo1L3Nu_*.root";                   ch[4]->Add(myhelper.c_str());
      myhelper = dirmc2016 + "WZTo3LNu_amcnlo_*.root";             ch[4]->Add(myhelper.c_str());
    }
    if(year==2017){
      myhelper = dirmc2017 + "WZTo1L3Nu_*.root";                   ch[4]->Add(myhelper.c_str());
      myhelper = dirmc2017 + "WZTo3LNu_*.root";                    ch[4]->Add(myhelper.c_str());
    }
    if(year==2018){
      myhelper = dirmc2017 + "WZTo1L3Nu_*.root";                   ch[4]->Add(myhelper.c_str());
      myhelper = dirmc2018 + "WZTo3LNu_*.root";                    ch[4]->Add(myhelper.c_str());
    }
    
    //run over all TChains --> see ExampleLooper.C
    for(int i = 0; i<chainsize; ++i){
      //if(i<5) continue;
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      ScanChain(mych,true,-1,mydataset,year); 
      delete ch[i];
    }
  }//year
}
