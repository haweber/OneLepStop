#include "dataMCplotMaker.h"
#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include <vector>
#include <string>
#include "TString.h"

using namespace std;

void makePlotPlot2(){
    
    bool DCSonly = false;//keep always false

    //string whichdata = "SingleMuon";
    string whichdata = "DoubleMuon";
    //string whichdata = "MuonEG";
  
  //  vector<char*> bgnames, signames;
  vector<string> bgstrings, sigstrings;
  vector<Color_t> colors;
  const unsigned int datasetsize = 4;//12
  const unsigned int bgsetsize = 4;//8
  const unsigned int sigsetsize = datasetsize-bgsetsize;
  string datasets[datasetsize]={"TTbar_amcnlo_50ns","WJets_50ns","DY_M50_50ns","DY_M10_50ns"};
  //char* dataset[datasetsize]={"TTbar1l","TTbar2l","SingleT","VJets","Rare","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  const Color_t mccolor[datasetsize]={kBlue+1,kGreen+1,kMagenta+1,kMagenta-2};//
  
  string outputdir = "../plots/first_20150727/";
  string  inputdir = "../rootfiles/first_20150727/";
    if(DCSonly) outputdir = "../plots/first_20150727/DCSonly/";
  
  for(unsigned int n=0; n<bgsetsize; ++n) {
    //bgnames.push_back(dataset[n]);
    bgstrings.push_back(datasets[n]);
    colors.push_back(mccolor[n]);
  }
  for(unsigned int n=bgsetsize; n<datasetsize; ++n) {
    //signames.push_back(dataset[n]);
    sigstrings.push_back(datasets[n]);
    colors.push_back(mccolor[n]);
  }
  TFile *fbg[bgsetsize];
  for(unsigned int n=0; n<bgsetsize; ++n) {
    string datasetstring = datasets[n];
    TString x = (inputdir+"Histos3_"+datasetstring+".root");
      if(DCSonly) x = (inputdir+"Histos3DCS_"+datasetstring+".root");
    //cout << x << endl;
      fbg[n] = TFile::Open(x);
      //  cout << fbg[n].IsZombie();
  }
    
    TString fdataname = (inputdir+"Histos3_"+whichdata+".root");
    if(DCSonly) fdataname = (inputdir+"Histos3DCS_"+whichdata+".root");
    TFile *fdata = TFile::Open(fdataname.Data());

  vector<string> histonames;

    histonames.push_back("Mll");
    histonames.push_back("Mud0");
    histonames.push_back("MudZ");
    histonames.push_back("MuIP3d");
    histonames.push_back("MuRelIso03DB");
    histonames.push_back("MuMiniIsoEA");
    histonames.push_back("MuMiniIsoDB");
    histonames.push_back("MuRelIso04");
    histonames.push_back("MuAnnulus04");
    histonames.push_back("MuRelIso03DB_MT30");
    histonames.push_back("MuMiniIsoEA_MT30");
    histonames.push_back("MuMiniIsoDB_MT30");
    histonames.push_back("MuRelIso04_MT30");
    histonames.push_back("MuAnnulus04_MT30");
    histonames.push_back("MuID");
    histonames.push_back("MuvalidFraction");
    histonames.push_back("MuisPF");
    histonames.push_back("Mugfit_normchi2");
    histonames.push_back("Mugfit_validSTAHits");
    histonames.push_back("MunumberOfMatchedStations");
    histonames.push_back("Munlayers");
    histonames.push_back("Muchi2LocalPosition");
    histonames.push_back("MutrkKink");
    histonames.push_back("MusegmCompatibility");
    histonames.push_back("MuvalidPixelHits");
    histonames.push_back("MuPt");
    histonames.push_back("MuEta");
    histonames.push_back("MuPhi");
    histonames.push_back("MuCharge");
    histonames.push_back("MT");
    histonames.push_back("ZPt");
    histonames.push_back("Z_Pt");
    histonames.push_back("ZEta");
    histonames.push_back("ZPhi");
    histonames.push_back("DPhill");
    histonames.push_back("DEtall");
    histonames.push_back("DRll");
    histonames.push_back("MET");
    histonames.push_back("HT");
    histonames.push_back("NJets");
    histonames.push_back("NBJets");
    histonames.push_back("MyMuPt");
    histonames.push_back("MyMuEta");
    histonames.push_back("MyMuPhi");
    histonames.push_back("MyMuCharge");



  TH1F* null = new TH1F("","",1,-1,1);
    float scale;
    for(unsigned int i = 0; i<histonames.size();++i){
        //if(prefix!="") options = "--outputName " + outputdir + prestring  + prefix + "/" + histonames[i] + " --xAxisLabel " + histonames[i] + " --energy 13 --lumi 10 --noXaxisUnit --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05";
        // string options = "--outputName " + outputdir + prestring + "/" + histonames[i] + " --xAxisLabel " + prestring + histonames[i] + " --noXaxisUnit --energy 13 --lumi 10 --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05 --legendRight -0.2";//topness
        for(unsigned int j = 0; j<11; ++j){
            float bgsum = 0;
           vector<TH1F*> bghist; bghist.clear();
            vector<TH1F*> sighist; sighist.clear();
            string prefix = "";
            if(j==1) prefix = "NJ0_";
            else if(j==2) prefix = "NJ1_";
            else if(j==3) prefix = "NJ2_";
            else if(j==4) prefix = "NJge3_";
            else if(j==5) prefix = "NB0_";
            else if(j==6) prefix = "NBge1_";
            else if(j==7) prefix = "HTge100_";
            else if(j==8) prefix = "METge50_";
            else if(j==9) prefix = "METge25_";
            else if(j==10) prefix = "HTge150_";
            string options = "--outputName " + outputdir + whichdata + "/" + prefix + histonames[i] + " --xAxisLabel " + histonames[i] + " --energy 13 --lumi 40.3 --legendTextSize 0.02 --preserveBackgroundOrder --legendUp 0.05";
            if(DCSonly)options = "--outputName " + outputdir + whichdata + "/" + prefix + histonames[i] + " --xAxisLabel " + histonames[i] + " --energy 13 --lumi XX --legendTextSize 0.02 --preserveBackgroundOrder --legendUp 0.05";
            for(unsigned int n=0; n<bgsetsize; ++n){
                int fileidentifier = n;
                fbg[fileidentifier]->cd();
                string name = prefix + histonames[i]+"_"+bgstrings[n];
                //cout << fbg[fileidentifier]->GetName() << " " << name << endl;
                TH1F *h = (TH1F*)fbg[fileidentifier]->Get(name.c_str());
                bghist.push_back(h);
                scale += h->Integral();
                bgsum += h->Integral(h->FindBin(75.1),h->FindBin(104.9));
            }
            string name = prefix + histonames[i]+"_"+whichdata;
            TH1F *hdata = (TH1F*)fdata->Get(name.c_str());
            if(histonames[i]=="Mll") cout << name << "  bg Zpeak " << bgsum << " data Zpeak " << hdata->Integral(hdata->FindBin(75.1),hdata->FindBin(104.9)) << " rat " <<  hdata->Integral(hdata->FindBin(75.1),hdata->FindBin(104.9))/bgsum << endl;
            if(scale<=0) continue;
            if(hdata->Integral()<=0) continue;
            scale = (float)hdata->Integral()/scale;
            //if(!DCSonly) scale = 1.;
            //for(unsigned int n=0; n<bgsetsize; ++n) bghist[n]->Scale(scale);
            dataMCplotMaker(hdata,bghist,bgstrings,whichdata.c_str(),"",options,sighist,sigstrings,colors);
            cout << "Data/MC scale is " << scale << endl;
        }
    }
}
