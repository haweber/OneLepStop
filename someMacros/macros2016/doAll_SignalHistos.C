{
  int jes = 0;
  int whichsignal = 1;//1 T2tt, 2 T2bW, 3 T2tb
  
  const unsigned int chainsize = 1;
  TChain *ch[chainsize];
  string dataset[chainsize];
  string myhelper;
  string babylocation;

  //normal
  if(abs(jes)!=1){
    gROOT->ProcessLine(".L GetSignalHistos.C+");
    //gROOT->ProcessLine(".L GetSignalHistosPolarized.C+");
    if(whichsignal==1){
      babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160127/merged_files/";
      dataset[0] = "Signal_T2tt";
      ch[0] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tt.root"; ch[0]->Add(myhelper.c_str());
    } else if(whichsignal==2){
      babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218/merged_files/";
      dataset[0] = "Signal_T2bW";
      ch[0] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2bW.root"; ch[0]->Add(myhelper.c_str());
    }
     else if(whichsignal==3){
      babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218/merged_files/";
      dataset[0] = "Signal_T2tb";
      ch[0] = new TChain("t"); 
      myhelper = babylocation+"Signal_T2tb.root"; ch[0]->Add(myhelper.c_str());
    }
  }
  //JESup/down
  if(abs(jes)==1){
    gROOT->ProcessLine(".L GetSignalHistosJES.C+");
    //gROOT->ProcessLine(".L GetSignalHistosJESPolarized.C+");
    //JESup
    if(jes==1){
      if(whichsignal==1){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160127_JESup/merged_files/";
	dataset[0] = "Signal_T2tt_JESup";
      } else if(whichsignal==2){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218_JESup/merged_files/";
	dataset[0] = "Signal_T2bW_JESup";
      } else if(whichsignal==3){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218_JESup/merged_files/";
	dataset[0] = "Signal_T2tb_JESup";
      }
    }
    //JESdown
    if(jes==(-1)) {
      if(whichsignal==1){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160127_JESdown/merged_files/";
	dataset[0] = "Signal_T2tt_JESdown";
      } else if(whichsignal==2){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218_JESdown/merged_files/";
	dataset[0] = "Signal_T2bW_JESdown";
      } else if(whichsignal==3){
	babylocation = "/hadoop/cms/store/user/haweber/condor/stop1l/stopbabies_20160218_JESdown/merged_files/";
	dataset[0] = "Signal_T2tb_JESdown";
      }
    }
    ch[0] = new TChain("t");
    if(whichsignal==1){
      myhelper = babylocation+"Signal_T2tt.root"; ch[0]->Add(myhelper.c_str());
    } else if(whichsignal==2){
      myhelper = babylocation+"Signal_T2bW.root"; ch[0]->Add(myhelper.c_str());
    } else if(whichsignal==3){
      myhelper = babylocation+"Signal_T2tb.root"; ch[0]->Add(myhelper.c_str());
    }
  }
  for(int i = 0; i<chainsize; ++i){
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 
  }


}
