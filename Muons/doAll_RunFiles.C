{

  //gROOT->ProcessLine(".L GetMuonHistos.C+");
  gROOT->ProcessLine(".L GetMuonHistos3.C+");
  //gROOT->ProcessLine(".L GetMuonHistosTrigger.C+");

  const unsigned int chainsize = 6;
  TChain *ch[chainsize];
  string dataset[chainsize];

  string babylocation = "";
  string myhelper;
  //dataset[0] = "test";
  //ch[0] = new TChain("t"); 
  //myhelper = babylocation+"~/LeptonBabyMaker/default.root"; ch[0]->Add(myhelper.c_str());
  
  ///hadoop/cms/store/user/haweber/condor/forCommissioning/20150711_cmssw74x/merged_files/
  ///hadoop/cms/store/user/haweber/condor/forCommissioning/20150711_cmssw74x/merged_files/SingleMu_unmerged.root
  dataset[0] = "TTbar_amcnlo_50ns"; ch[0] = new TChain("t"); 
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/TTbar_amcnlo_50ns.root"; ch[0]->Add(myhelper.c_str());
  dataset[1] = "WJets_50ns"; ch[1] = new TChain("t"); 
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/WJetsToLNu_50ns.root"; ch[1]->Add(myhelper.c_str());
  dataset[2] = "DY_M10_50ns"; ch[2] = new TChain("t"); 
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/DY_M10_50ns.root"; ch[2]->Add(myhelper.c_str());
  dataset[3] = "DY_M50_50ns"; ch[3] = new TChain("t"); 
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/DY_M50_50ns.root"; ch[3]->Add(myhelper.c_str());
  dataset[4] = "SingleMuon"; ch[4] = new TChain("t"); 
  //myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.04b/Run2015B/SingleMu2015.root"; ch[4]->Add(myhelper.c_str());
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.11/2015SingleMuon.root"; ch[4]->Add(myhelper.c_str());
  dataset[5] = "DoubleMuon"; ch[5] = new TChain("t"); 
  //myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.04b/Run2015B/DoubleMuon2015.root"; ch[5]->Add(myhelper.c_str());
  myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.11/2015DoubleMuon.root"; ch[5]->Add(myhelper.c_str());
  //dataset[6] = "MuonEG"; ch[6] = new TChain("t"); 
  //myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/Run2015B/MuonEG.root"; ch[6]->Add(myhelper.c_str());
  //dataset[7] = "SingleElectron"; ch[7] = new TChain("t"); 
  //myhelper = babylocation+"/nfs-7/userdata/leptonTree/v0.03/Run2015B/SingleElectron.root"; ch[7]->Add(myhelper.c_str());
  for(int i = 0; i<chainsize; ++i){
    //if(i<4) continue;
    TChain *mych = ch[i];
    string mydataset = dataset[i];
    ScanChain(mych,true,-1,mydataset); 
  }

}
