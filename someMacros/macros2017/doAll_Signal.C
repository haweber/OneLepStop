{
  int whichsignal = -1;//1 T2tt, 2 T2bW, 3 T2tb - if -1 all three
  bool genMET = false;

  bool cutflow = false;

  if(!cutflow){
    const unsigned int chainsize = 3;
    TChain *ch[chainsize];
    string dataset[chainsize];
    string myhelper;
    string babylocation;

    //normal
    if(!genMET){
      //gROOT->ProcessLine(".L GetSignalHistos_get2lCReventlist.C+");
      gROOT->ProcessLine(".L GetSignalHistos_copySFonfly.C+");
      //gROOT->ProcessLine(".L GetSignalHistos.C+");
      //babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_tempSignal_reco_oldJEC/output/";
      babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22/output/";
      dataset[0] = "Signal_T2tt";
      ch[0] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tt*.root"; ch[0]->Add(myhelper.c_str());
      dataset[1] = "Signal_T2bW";
      ch[1] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2bW*.root"; ch[1]->Add(myhelper.c_str());
      dataset[2] = "Signal_T2tb";
      ch[2] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tb*.root"; ch[2]->Add(myhelper.c_str());
    }
    else {
      gROOT->ProcessLine(".L GetSignalHistosGen_copySFonfly.C+");
      //gROOT->ProcessLine(".L GetSignalHistosGen.C+");
      //babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_tempSignal_gen_oldJEC/output/";
      babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22_genv2/output/";
      dataset[0] = "Signal_T2tt";
      ch[0] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tt*.root"; ch[0]->Add(myhelper.c_str());
      dataset[1] = "Signal_T2bW";
      ch[1] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2bW*.root"; ch[1]->Add(myhelper.c_str());
      dataset[2] = "Signal_T2tb";
      ch[2] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tb*.root"; ch[2]->Add(myhelper.c_str());
    }
    for(int i = 0; i<chainsize; ++i){
      if(whichsignal>=0&&i!=(whichsignal-1)) continue;
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      cout << i << " " << mydataset << " " << mych->GetEntries() << endl;
      ScanChain(mych,true,-1,mydataset); 
    }
  }
  else{
    const unsigned int chainsize = 9;
    TChain *ch[chainsize];
    string dataset[chainsize];
    string myhelper;
    string babylocation;
    gROOT->ProcessLine(".L SignalCutFlow.C+");

    //if(genMET) babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_tempSignal_gen_oldJEC/output/";
    //else       babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v16_tempSignal_reco_oldJEC/output/";
    if(genMET) babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22_genv2/output/";
    else       babylocation = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v22/output/";
    
    dataset[0] = "Signal_T2tt_1000_50";
    ch[0] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt_mStop_400to1200*.root"; ch[0]->Add(myhelper.c_str());
    dataset[1] = "Signal_T2tt_800_400";
    ch[1] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt_mStop_400to1200*.root"; ch[1]->Add(myhelper.c_str());
    dataset[2] = "Signal_T2tt_500_325";
    ch[2] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tt_mStop_400to1200*.root"; ch[2]->Add(myhelper.c_str());
    dataset[3] = "Signal_T2bW_900_50";
    ch[3] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2bW*.root"; ch[3]->Add(myhelper.c_str());
    dataset[4] = "Signal_T2bW_800_350";
    ch[4] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2bW*.root"; ch[4]->Add(myhelper.c_str());
    dataset[5] = "Signal_T2bW_500_300";
    ch[5] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2bW*.root"; ch[5]->Add(myhelper.c_str());
    dataset[6] = "Signal_T2tb_850_50";
    ch[6] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tb*.root"; ch[6]->Add(myhelper.c_str());
    dataset[7] = "Signal_T2tb_750_300";
    ch[7] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tb*.root"; ch[7]->Add(myhelper.c_str());
    dataset[8] = "Signal_T2tb_450_250";
    ch[8] = new TChain("t"); 
    myhelper = babylocation+"Signal_T2tb*.root"; ch[8]->Add(myhelper.c_str());

    for(int i = 0; i<chainsize; ++i){
      TChain *mych = ch[i];
      string mydataset = dataset[i];
      cout << i << " " << mydataset << " " << mych->GetEntries() << endl;
      ScanChain(mych,true,-1,mydataset); 
    }
  }

}
