#include "TEfficiency.h"
#include "TEventList.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TString.h"
#include "TObject.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TCut.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TH3F.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TAxis.h"
#include "TSystem.h"
#include "TMap.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <cmath>

using namespace std;

//const int samplenamesize = 10;
//string samplename[samplenamesize]={"TTbar","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
const int samplenamesize = 10;
//string samplename[samplenamesize]={"TTbar1l","TTbar2l","TTbarH","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
string samplename[samplenamesize]={"TTbar1l","TTbar2l","TTbarH","SingleT","VJets","Rare","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};

float Zbi(float sig, float bg, float bgunc){

  double tau = bg/pow(bgunc,2);//bgunc is absolute
  double n_on = sig+bg;//total yield in SR = sig + bg
  double n_off = tau*bg;
  double P_Bi = TMath::BetaIncomplete(1./(1.+tau),n_on,n_off+1);
  double Z_Bi = sqrt(2.)*TMath::ErfInverse(1.-2.*P_Bi);
  return Z_Bi;
}

float SoB(float sig, float bg){
  if(bg==0) return -1.;
  return sig/bg;
}

float SoSqrtB(float sig, float bg){
  if(bg<=0) return -1;
  return sig/sqrt(bg);
}

float FoM(float sig, float bg, float bgunc){
  if((bg+bgunc*bgunc)<=0) return -1;
  return sig/sqrt(bg+bgunc*bgunc);
}

void StudyRootFilesFurtherStudiesMET2(){
  
  bool bgdetermination = false;
    
  int pf=0;
  string prefix = "";
  if(pf==0)  prefix = "";
  if(pf==1)  prefix = "chi210_";
    if(pf==2)  prefix = "MT2W200_";
//    if(pf==3)  prefix = "MTleadj750_";
//    if(pf==4)  prefix = "MTleadj850_";
//    if(pf==5)  prefix = "MTleadj950_";
  
    map<string, TH1F*> histos; //massive
  vector<string> histonames; histonames.clear();
  map<string,float> bkg;
  map<string,double> bkgerr;
  map<string,float> sig;
  map<string,double> sigerr;
    
    map<string,vector<double> > sel;
  /*
    sel["TopnessMod0_MET_noMETsqrtHT"].clear();
    sel["TopnessMod7_MET_noMETsqrtHT"].clear();
    sel["TopnessMod0_MET_noMETsqrtHT"]     = {150,   250,  350,   450, 750};//all exclusive
    sel["TopnessMod7_MET_noMETsqrtHT"]     = {250,  325,   400,   750, 755};
    //for(unsigned int i = 0; i<sel["TopnessMod0_MET_noMETsqrtHT"].size();++i){
    //    cout << "bin " << i+1 << "/" << sel["TopnessMod0_MET_noMETsqrtHT"].size() << " has value " << sel["TopnessMod0_MET_noMETsqrtHT"][i] << endl;
    //    cout << "bin " << i+1 << "/" << sel["TopnessMod7_MET_noMETsqrtHT"].size() << " has value " << sel["TopnessMod7_MET_noMETsqrtHT"][i] << endl;
    //}
    histonames.push_back("TopnessMod0_MET_noMETsqrtHT");
    histonames.push_back("TopnessMod7_MET_noMETsqrtHT");
    */
    //histonames.push_back("MT2Wle200nochi2_MET_noMETsqrtHT");

    sel["MT2Wle200nochi2_MET_noMETsqrtHT"].clear();
    sel["MT2W200nochi2_MET_noMETsqrtHT"].clear();
    sel["MT2W200nochi2_MET_noMETsqrtHT"]     = {250, 300,   350,  400,   500, 750};//all exclusive
    sel["MT2Wle200nochi2_MET_noMETsqrtHT"]     = {250, 300,   350,  400,   500, 750};
    for(unsigned int i = 0; i<sel["MT2Wle200nochi2_MET_noMETsqrtHT"].size();++i){
        cout << "bin " << i+1 << "/" << sel["MT2Wle200nochi2_MET_noMETsqrtHT"].size() << " has value " << sel["MT2Wle200nochi2_MET_noMETsqrtHT"][i] << endl;
        cout << "bin " << i+1 << "/" << sel["MT2W200nochi2_MET_noMETsqrtHT"].size() << " has value " << sel["MT2W200nochi2_MET_noMETsqrtHT"][i] << endl;
    }
    histonames.push_back("MT2Wle200nochi2_MET_noMETsqrtHT");
    histonames.push_back("MT2W200nochi2_MET_noMETsqrtHT");

/*
    sel["MT2Wle200nochi2_MET_noMETsqrtHT"].clear();
    sel["MT2Wle200nochi2_MET_noMETsqrtHT"]     = {250, 300,  400, 750, 775};
    histonames.push_back("MT2Wle200nochi2_MET_noMETsqrtHT");
*/
/*
    sel["MET_noMETsqrtHT"]     = {300,   350,  400,   500, 750};
    sel["MT2W200_MET_noMETsqrtHT"]     = {225,   300,  400, 750, 775};
    sel["MT2W200nochi2_MET_noMETsqrtHT"]     = {200,   275,  350,   450, 750};
    histonames.push_back("MET_noMETsqrtHT");
    histonames.push_back("MT2W200_MET_noMETsqrtHT");
    histonames.push_back("MT2W200nochi2_MET_noMETsqrtHT");
*/
/*
    sel["MET_noMETsqrtHT"]     = {275,   325,  400,   500, 750};
    sel["MTleadj600_MET_noMETsqrtHT"]     = {250,   350,  475, 750, 775};
    sel["RM0p7_MET_noMETsqrtHT"]     = {225,   350,  475,   750, 775};
    histonames.push_back("MET_noMETsqrtHT");
    histonames.push_back("MTleadj600_MET_noMETsqrtHT");
    histonames.push_back("RM0p7_MET_noMETsqrtHT");
*/
  
  TFile *fin[samplenamesize];
  for(unsigned int j = 0; j<samplenamesize; ++j){
    string rootname = "HistosFurtherChecks_"+samplename[j]+".root";
    if(j<=2)  rootname = "HistosFurtherChecks_TTbar.root";
    fin[j] = TFile::Open(rootname.c_str());
    fin[j]->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
        string mapname;
        string loadname = "Print_" + prefix + histonames[i] + "_"+samplename[j];
        mapname = histonames[i] + "_"+samplename[j];
        if(histos.count(mapname) == 0 ) histos[mapname] = (TH1F*)fin[j]->Get(loadname.c_str());
    }
  }

    if(bgdetermination){
        for(unsigned int i = 0; i<histonames.size(); ++i){
            float bgTop(0),bgST(0),bgRare(0),bgVJets(0);
            double bgTopErr(0),bgSTErr(0),bgRareErr(0),bgVJetsErr(0),bgTopErr2(0),bgTopErr3(0);
            //float sig425(0),sig500(0),sig650(0),sig850(0);
            string var;
            var = histonames[i];
            double oldbg(0);
            //for(unsigned int j = histos[var+"_TTbar1l"]->FindBin(cut[i]); j <= histos[var+"_TTbar1l"]->GetNbinsX(); ++j){
            for(unsigned int j = 1; j <= histos[var+"_TTbar1l"]->GetNbinsX(); ++j){
                    double bg(0), bgerr(0), errsum(0);
                //if(histos[var+"_TTbar1l"]->GetBinLowEdge(j)!=200) continue;
                //if(histos[var+"_TTbar1l"]->GetBinLowEdge(j)!=250) continue;
                //if(histos[var+"_TTbar1l"]->GetBinLowEdge(j)!=300) continue;
                //if(histos[var+"_TTbar1l"]->GetBinLowEdge(j)!=350) continue;
                //if(histos[var+"_TTbar1l"]->GetBinLowEdge(j)!=400) continue;
                    //cout << __LINE__<<endl;
                    //cout << << histos[var+"_TTbar1l"]->GetBinLowEdge(j) << " " << histos[var+"_TTbar1l"]->GetBinLowEdge(k) << " ";
                    //if(histos[var+"_TTbar1l"]->GetBinLowEdge(k)!=250) continue;
                    unsigned int k = histos[var+"_TTbar1l"]->GetNbinsX();
                    //cout << __LINE__<<endl;
                    bg = histos[var+"_TTbar1l"]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    bg+= histos[var+"_TTbar2l"]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    bg+= histos[var+"_TTbarH" ]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    bg+= histos[var+"_SingleT"]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    bg+= histos[var+"_Rare"   ]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    bg+= histos[var+"_VJets"  ]->IntegralAndError(j,k,bgerr )/2; errsum += bgerr*bgerr/4;
                    float sig425 = histos[var+"_Stop_425_325"  ]->Integral(j,histos[var+"_Stop_425_325"  ]->GetNbinsX())/2;
                    float sig500 = histos[var+"_Stop_500_325"  ]->Integral(j,histos[var+"_Stop_500_325"  ]->GetNbinsX())/2;
                    float sig650 = histos[var+"_Stop_650_325"  ]->Integral(j,histos[var+"_Stop_650_325"  ]->GetNbinsX())/2;
                    float sig850 = histos[var+"_Stop_850_100"  ]->Integral(j,histos[var+"_Stop_850_100"  ]->GetNbinsX())/2;
                    if(fabs(0-bg)<200 && int(histos[var+"_TTbar1l"]->GetBinLowEdge(j))%25==0 && fabs(oldbg-bg)>0.001){
                        cout << "var " << var << " bin " << j << " binlowedge " << histos[var+"_TTbar1l"]->GetBinLowEdge(j) << " has integral " << bg << " +/- " << 100.* sqrt(errsum)/bg << " percent (" << fabs(0-bg) <<")"<<  endl;
                        cout << "    sig425="<< sig425 << ", sig500=" << sig500 << ", sig650=" << sig650 << ", sig850=" << sig850 << endl;
                        oldbg = bg;
                    }
            }
            oldbg = 0;
            cout << endl;
        }
    } else{
    for(unsigned int j = 0; j < sel[histonames[0] ].size()-1; ++j){
        for(unsigned int i = 0; i<histonames.size(); ++i){
            string var;
            var = histonames[i];
            double bg(0), bgerr(0), errsum(0);
            double bg2(0), bgerr2(0), errsum2(0);
            double signalerr;
            int blow = histos[var+"_TTbar1l"]->FindBin(sel[var][j]+0.0001);
            int bup = histos[var+"_TTbar1l"]->FindBin(sel[var][j+1]-0.0001);
            //cout <<sel[var][j]+0.0001 << "-->" << blow << "  " <<sel[var][j+1]-0.0001 << "-->" << bup << endl;
            bg = histos[var+"_TTbar1l"]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            bg+= histos[var+"_TTbar2l"]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            bg+= histos[var+"_TTbarH" ]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            bg+= histos[var+"_SingleT"]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            bg+= histos[var+"_Rare"   ]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            bg+= histos[var+"_VJets"  ]->IntegralAndError(blow,bup,bgerr )/2; errsum += bgerr*bgerr/4;
            sig[var+"_Stop_425_325"] = histos[var+"_Stop_425_325"]->IntegralAndError(blow,bup,signalerr )/2;
            sigerr[var+"_Stop_425_325"] = signalerr/2;
            sig[var+"_Stop_500_325"] = histos[var+"_Stop_500_325"]->IntegralAndError(blow,bup,signalerr )/2;
            sigerr[var+"_Stop_500_325"] = signalerr/2;
            sig[var+"_Stop_650_325"] = histos[var+"_Stop_650_325"]->IntegralAndError(blow,bup,signalerr )/2;
            sigerr[var+"_Stop_650_325"] = signalerr/2;
            sig[var+"_Stop_850_100"] = histos[var+"_Stop_850_100"]->IntegralAndError(blow,bup,signalerr )/2;
            sigerr[var+"_Stop_850_100"] = signalerr/2;
            /*cout << histos[var+"_TTbar1l"]->GetBinLowEdge(blow) << "-" << histos[var+"_TTbar1l"]->GetBinLowEdge(bup)+histos[var+"_TTbar1l"]->GetBinWidth(bup)
                 << ": TTbar1l " << histos[var+"_TTbar1l"]->Integral(blow,bup)/2
            << ", TTbar2l " << histos[var+"_TTbar2l"]->Integral(blow,bup)/2
            << ", TTbarH  " << histos[var+"_TTbarH"]->Integral(blow,bup)/2
            << ", SingleT " << histos[var+"_SingleT"]->Integral(blow,bup)/2
            << ", Rare    " << histos[var+"_Rare"]->Integral(blow,bup)/2
            << ", VJets   " << histos[var+"_VJets"]->Integral(blow,bup)/2 << endl;
            */
            //cout << "var " << var << " from " << histos[var+"_TTbar1l"]->GetBinLowEdge(blow) << "-" <<histos[var+"_TTbar1l"]->GetBinLowEdge(bup)+histos[var+"_TTbar1l"]->GetBinWidth(bup) << " has integral " << bg << " +/- " << 100.* sqrt(errsum)/bg << " percent"<<  endl;
            cout << var << " & " << histos[var+"_TTbar1l"]->GetBinLowEdge(blow) << "-" << histos[var+"_TTbar1l"]->GetBinLowEdge(bup)+histos[var+"_TTbar1l"]->GetBinWidth(bup) << " & ";
            cout << fixed << setprecision(2) << bg << "$\\pm$" << sqrt(errsum) << " & " << sig[var+"_Stop_425_325"]  << "$\\pm$" << sigerr[var+"_Stop_425_325"]
                 << " & " << sig[var+"_Stop_500_325"]  << "$\\pm$" << sigerr[var+"_Stop_500_325"]
                 << " & " << sig[var+"_Stop_650_325"]  << "$\\pm$" << sigerr[var+"_Stop_650_325"]
                 << " & " << sig[var+"_Stop_850_100"]  << "$\\pm$" << sigerr[var+"_Stop_850_100"] << " \\\\" << endl;
        }
        cout << endl;
    }
    }

}
