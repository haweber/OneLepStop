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

void StudyRootFilesFurtherStudies(){

  bool yield           = true;
  bool SoverB          = false;
  bool SoverSqrtB      = false;
  bool FigureOfMerit   = false;
  bool SignificanceZbi = true;
    
    bool bgdetermination = false;
    bool getROCcurves = false;
    
  int pf=2;
  string prefix = "";
  if(pf==0)  prefix = "";
  if(pf==1)  prefix = "MET300_";
  if(pf==2)  prefix = "chi210_";
  if(pf==3)  prefix = "MT2W200_";
  
    map<string, TH1F*> histos; //massive
    map<string, TGraphAsymmErrors*> histROC; //massive
    map<string, TGraphAsymmErrors*> histROCSP; //massive
    //map<string, TGraph*> histROC; //massive
  vector<string> histonames; histonames.clear();
  map<string,float> bkg;
  map<string,double> bkgerr;
  map<string,float> sig;
  map<string,double> sigerr;
  vector<double> cut; cut.clear();
    
   // histonames.push_back("MT2W3j");                     if(pf==0) cut.push_back(287.5); else if(pf==1) cut.push_back(260); else if(pf==2) cut.push_back(256.25); else cut.push_back(317.5);
   // histonames.push_back("Topness3j");                  if(pf==0) cut.push_back(10.55 ); else if(pf==1) cut.push_back(10.); else if(pf==2) cut.push_back(10. ); else cut.push_back(11.2 );
   // histonames.push_back("TopnessMod3j");               if(pf==0) cut.push_back(6.65 ); else if(pf==1) cut.push_back(-2.15); else if(pf==2) cut.push_back(1.45 ); else cut.push_back(8.6 );

    
    histonames.push_back("MT2W3j");                     if(pf==0) cut.push_back(225); else if(pf==1) cut.push_back(210); else if(pf==2) cut.push_back(200); else cut.push_back(317.5);
    histonames.push_back("Topness3j");                  if(pf==0) cut.push_back(8.7 ); else if(pf==1) cut.push_back(8.5); else if(pf==2) cut.push_back(7.75 ); else cut.push_back(11.2 );
    histonames.push_back("TopnessMod3j");               if(pf==0) cut.push_back(-3.8 ); else if(pf==1) cut.push_back(-4.5); else if(pf==2) cut.push_back(-4.65 ); else cut.push_back(8.6 );
 /*
    histonames.push_back("MET_noMETsqrtHT");            if(pf==0) cut.push_back(350); else if(pf==1) cut.push_back(368.75); else if(pf==2) cut.push_back(371.25); else cut.push_back(355);
    histonames.push_back("MET_METsqrtHT14");            if(pf==0) cut.push_back(296.25); else if(pf==1) cut.push_back(352.5); else if(pf==2) cut.push_back(351.25); else cut.push_back(332.5);
    histonames.push_back("METsqrtHT_MET150");           if(pf==0) cut.push_back(16 ); else if(pf==1) cut.push_back(16.6 ); else if(pf==2) cut.push_back(16.5); else cut.push_back(16.2);
    histonames.push_back("METsqrtHT_noMET");            if(pf==0) cut.push_back(16 ); else if(pf==1) cut.push_back(16.6 ); else if(pf==2) cut.push_back(16.5); else cut.push_back(16.2);
    histonames.push_back("METsqrtHTlpt_MET150");        if(pf==0) cut.push_back(14.2 ); else if(pf==1) cut.push_back(14.9 ); else if(pf==2) cut.push_back(14.9); else cut.push_back(14.6);
    histonames.push_back("METsqrtHTlpt_noMET");         if(pf==0) cut.push_back(14.2 ); else if(pf==1) cut.push_back(14.9 ); else if(pf==2) cut.push_back(14.9); else cut.push_back(14.6);
  
    histonames.push_back("MT2W3j");                     if(pf==0) cut.push_back(336.25); else if(pf==1) cut.push_back(290); else if(pf==2) cut.push_back(268.75); else cut.push_back(317.5);
    histonames.push_back("MT2W4j");                     if(pf==0) cut.push_back(303.75); else if(pf==1) cut.push_back(261.25); else if(pf==2) cut.push_back(242.5); else cut.push_back(281.25);
    histonames.push_back("MT2W3j4j");                   if(pf==0) cut.push_back(251.25); else if(pf==1) cut.push_back(231.25); else if(pf==2) cut.push_back(228.75); else cut.push_back(263.75);
    histonames.push_back("MT2W3j_noord");               if(pf==0) cut.push_back(311.25); else if(pf==1) cut.push_back(262.5); else if(pf==2) cut.push_back(247.5); else cut.push_back(285);
    histonames.push_back("MT2W4j_noord");               if(pf==0) cut.push_back(273.75); else if(pf==1) cut.push_back(227.5); else if(pf==2) cut.push_back(212.5); else cut.push_back(240);
    histonames.push_back("MT2W3j4j_noord");             if(pf==0) cut.push_back(220); else if(pf==1) cut.push_back(206.25); else if(pf==2) cut.push_back(205); else cut.push_back(226.25);
    
    histonames.push_back("Topness3j");                  if(pf==0) cut.push_back(11.15 ); else if(pf==1) cut.push_back(10.65); else if(pf==2) cut.push_back(10.4 ); else cut.push_back(11.2 );
    histonames.push_back("Topness4j");                  if(pf==0) cut.push_back(10.85 ); else if(pf==1) cut.push_back(10.2); else if(pf==2) cut.push_back(9.8 ); else cut.push_back(10.9 );
    histonames.push_back("Topness3j4j");                if(pf==0) cut.push_back(9.8 ); else if(pf==1) cut.push_back(9.5); else if(pf==2) cut.push_back(9.45 ); else cut.push_back(10.35 );
    histonames.push_back("Topness3j_noord");            if(pf==0) cut.push_back(10.85 ); else if(pf==1) cut.push_back(10.25); else if(pf==2) cut.push_back(9.8 ); else cut.push_back(10.85 );
    histonames.push_back("Topness4j_noord");            if(pf==0) cut.push_back(10.4 ); else if(pf==1) cut.push_back(9.2); else if(pf==2) cut.push_back(8.7 ); else cut.push_back(9.8 );
    histonames.push_back("Topness3j4j_noord");          if(pf==0) cut.push_back(8.75 ); else if(pf==1) cut.push_back(8.6); else if(pf==2) cut.push_back(8.3 ); else cut.push_back(9.3 );
    
    histonames.push_back("TopnessMod3j");               if(pf==0) cut.push_back(8.05 ); else if(pf==1) cut.push_back(7); else if(pf==2) cut.push_back(5.2 ); else cut.push_back(8.6 );
    histonames.push_back("TopnessMod4j");               if(pf==0) cut.push_back(6.6 ); else if(pf==1) cut.push_back(-3.8); else if(pf==2) cut.push_back(-4. ); else cut.push_back(5.2 );
    histonames.push_back("TopnessMod3j4j");             if(pf==0) cut.push_back(0.4 ); else if(pf==1) cut.push_back(-4.3); else if(pf==2) cut.push_back(-4.35 ); else cut.push_back(-4.4 );
    //histonames.push_back("TopnessMod3j_noord");         if(pf==0) cut.push_back(0. ); else if(pf==1) cut.push_back(7.  ); else if(pf==2) cut.push_back(7. ); else cut.push_back(7. );
    histonames.push_back("TopnessMod4j_noord");         if(pf==0) cut.push_back(6.6); else if(pf==1) cut.push_back(0.  ); else if(pf==2) cut.push_back(0. ); else cut.push_back(5.2 );
    histonames.push_back("TopnessMod3j4j_noord");       if(pf==0) cut.push_back(0.4 ); else if(pf==1) cut.push_back(0.  ); else if(pf==2) cut.push_back(0. ); else cut.push_back(0. );
    
    histonames.push_back("MT2lbb3j");                   if(pf==0) cut.push_back(251.25); else if(pf==1) cut.push_back(233.75); else if(pf==2) cut.push_back(221.25); else cut.push_back(237.5);
    histonames.push_back("MT2lbb4j");                   if(pf==0) cut.push_back(237.5); else if(pf==1) cut.push_back(216.25); else if(pf==2) cut.push_back(205); else cut.push_back(222.5);
    histonames.push_back("MT2lbb3j4j");                 if(pf==0) cut.push_back(207.5); else if(pf==1) cut.push_back(198.75); else if(pf==2) cut.push_back(195); else cut.push_back(206.25);
    histonames.push_back("MT2lbb3j_noord");             if(pf==0) cut.push_back(245); else if(pf==1) cut.push_back(228.75); else if(pf==2) cut.push_back(215); else cut.push_back(230);
    histonames.push_back("MT2lbb4j_noord");             if(pf==0) cut.push_back(220); else if(pf==1) cut.push_back(203.75); else if(pf==2) cut.push_back(187.5); else cut.push_back(198.75);
    histonames.push_back("MT2lbb3j4j_noord");           if(pf==0) cut.push_back(192.5); else if(pf==1) cut.push_back(181.25); else if(pf==2) cut.push_back(177.5); else cut.push_back(177.5);
    
    histonames.push_back("MT2lbbqq3j");                 if(pf==0) cut.push_back(520); else if(pf==1) cut.push_back(456.25); else if(pf==2) cut.push_back(390); else cut.push_back(371.25);
    histonames.push_back("MT2lbbqq4j");                 if(pf==0) cut.push_back(498.75); else if(pf==1) cut.push_back(437.5); else if(pf==2) cut.push_back(372.5); else cut.push_back(341.25);
    histonames.push_back("MT2lbbqq3j4j");               if(pf==0) cut.push_back(437.5); else if(pf==1) cut.push_back(421.25); else if(pf==2) cut.push_back(362.5); else cut.push_back(340);
    histonames.push_back("MT2lbbqq3j_noord");           if(pf==0) cut.push_back(575); else if(pf==1) cut.push_back(502.5); else if(pf==2) cut.push_back(420); else cut.push_back(395);
    histonames.push_back("MT2lbbqq4j_noord");           if(pf==0) cut.push_back(555); else if(pf==1) cut.push_back(495); else if(pf==2) cut.push_back(407.5); else cut.push_back(372.5);
    histonames.push_back("MT2lbbqq3j4j_noord");         if(pf==0) cut.push_back(532.5); else if(pf==1) cut.push_back(477.5); else if(pf==2) cut.push_back(405); else cut.push_back(370);
    
    histonames.push_back("mMT2lbb3j");                  if(pf==0) cut.push_back(172.5); else if(pf==1) cut.push_back(155); else if(pf==2) cut.push_back(152.5); else cut.push_back(153.75);
    histonames.push_back("mMT2lbb4j");                  if(pf==0) cut.push_back(160); else if(pf==1) cut.push_back(135); else if(pf==2) cut.push_back(127.5); else cut.push_back(112.5);
    histonames.push_back("mMT2lbb3j4j");                if(pf==0) cut.push_back(133.75); else if(pf==1) cut.push_back(100); else if(pf==2) cut.push_back(101.25); else cut.push_back(93.75);
    histonames.push_back("mMT2lbb3j_noord");            if(pf==0) cut.push_back(170); else if(pf==1) cut.push_back(151.25); else if(pf==2) cut.push_back(141.25); else cut.push_back(151.25);
    histonames.push_back("mMT2lbb4j_noord");            if(pf==0) cut.push_back(156.25); else if(pf==1) cut.push_back(125); else if(pf==2) cut.push_back(120); else cut.push_back(96.25);
    histonames.push_back("mMT2lbb3j4j_noord");          if(pf==0) cut.push_back(123.75); else if(pf==1) cut.push_back(90); else if(pf==2) cut.push_back(90); else cut.push_back(62.5);
    
    histonames.push_back("mMT2lbbqq3j");                if(pf==0) cut.push_back(200); else if(pf==1) cut.push_back(176.25); else if(pf==2) cut.push_back(158.75); else cut.push_back(116.25);
    histonames.push_back("mMT2lbbqq4j");                if(pf==0) cut.push_back(191.25); else if(pf==1) cut.push_back(167.5); else if(pf==2) cut.push_back(152.5); else cut.push_back(93.75);
    histonames.push_back("mMT2lbbqq3j4j");              if(pf==0) cut.push_back(173.75); else if(pf==1) cut.push_back(150); else if(pf==2) cut.push_back(146.25); else cut.push_back(80);
    histonames.push_back("mMT2lbbqq3j_noord");          if(pf==0) cut.push_back(211.25); else if(pf==1) cut.push_back(198.75); else if(pf==2) cut.push_back(180); else cut.push_back(133.75);
    histonames.push_back("mMT2lbbqq4j_noord");          if(pf==0) cut.push_back(206.25); else if(pf==1) cut.push_back(188.75); else if(pf==2) cut.push_back(175); else cut.push_back(128.75);
    histonames.push_back("mMT2lbbqq3j4j_noord");        if(pf==0) cut.push_back(193.75); else if(pf==1) cut.push_back(176.25); else if(pf==2) cut.push_back(165); else cut.push_back(120);
*/
    

  string addX = "";
  
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
        if(cut[i]>-99.){
            if(histos.count(mapname) == 0 ) histos[mapname] = (TH1F*)fin[j]->Get(loadname.c_str());
        }
        if(j>=6){
            if(histROC.count(mapname) == 0 )  histROC[mapname ] = new TGraphAsymmErrors();
            histROC[mapname ]->SetName(mapname.c_str());
            if(histROCSP.count(mapname) == 0 )  histROCSP[mapname ] = new TGraphAsymmErrors();
            string graphname = mapname + "SP";
            histROCSP[mapname ]->SetName(graphname.c_str());
        }
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
                bg = histos[var+"_TTbar1l"]->IntegralAndError(j,histos[var+"_TTbar1l"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                bg+= histos[var+"_TTbar2l"]->IntegralAndError(j,histos[var+"_TTbar2l"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                bg+= histos[var+"_TTbarH" ]->IntegralAndError(j,histos[var+"_TTbarH" ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                bg+= histos[var+"_SingleT"]->IntegralAndError(j,histos[var+"_SingleT"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                bg+= histos[var+"_Rare"   ]->IntegralAndError(j,histos[var+"_Rare"   ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                bg+= histos[var+"_VJets"  ]->IntegralAndError(j,histos[var+"_VJets"  ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
                if(fabs(oldbg-bg)>0.0001){
                    if(bg<150&&bg>20)cout << "var " << var << " bin " << j << " binlowedge " << histos[var+"_TTbar1l"]->GetBinLowEdge(j) << " has integral " << bg << " +/- " << 100.* sqrt(errsum)/bg << " percent" << endl;
                    oldbg = bg;
                }
            }
            oldbg = 0;
            cout << endl;
        }
    }
    if(getROCcurves){
    map<string,double> sigSum;
    map<string,double> sigErrSum;
    TH1D *effpass = new TH1D("effpass","",1,0,1); //effpass->Sumw2();
    TH1D *efftotl = new TH1D("efftotl","",1,0,1); //efftotl->Sumw2();
    for(unsigned int i = 0; i<histonames.size(); ++i){
        string var;
        var = histonames[i];
        //cout << var << endl;
        //getchar();
        double bgSum(0), bgErrSum(0);
        sigSum["Stop_425_325"] = 0; sigErrSum["Stop_425_325"] = 0;
        sigSum["Stop_500_325"] = 0; sigErrSum["Stop_500_325"] = 0;
        sigSum["Stop_650_325"] = 0; sigErrSum["Stop_650_325"] = 0;
        sigSum["Stop_850_100"] = 0; sigErrSum["Stop_850_100"] = 0;
        double oldbg(0);
        for(unsigned int j = 1; j <= histos[var+"_TTbar1l"]->GetNbinsX(); j+=10){
            double bg(0), bgerr(0), errsum(0);
            double sg(0), sgerr(0);
            bg = histos[var+"_TTbar1l"]->IntegralAndError(j,histos[var+"_TTbar1l"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            bg+= histos[var+"_TTbar2l"]->IntegralAndError(j,histos[var+"_TTbar2l"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            bg+= histos[var+"_TTbarH" ]->IntegralAndError(j,histos[var+"_TTbarH" ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            bg+= histos[var+"_SingleT"]->IntegralAndError(j,histos[var+"_SingleT"]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            bg+= histos[var+"_Rare"   ]->IntegralAndError(j,histos[var+"_Rare"   ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            bg+= histos[var+"_VJets"  ]->IntegralAndError(j,histos[var+"_VJets"  ]->GetNbinsX(),bgerr ); errsum += bgerr*bgerr;
            if(j==1) { bgSum = bg; bgErrSum = errsum; }
            if(fabs(oldbg-bg)>0.0001){
                oldbg = bg;
                TH1F *ht; TH1F *hp; TEfficiency *teff;
                effpass->SetBinContent(1,bg); effpass->SetBinError(1,bgerr);
                efftotl->SetBinContent(1,bgSum); efftotl->SetBinError(1,bgErrSum);
                ht = (TH1F*)efftotl->Clone("ht");
                hp = (TH1F*)effpass->Clone("hp");
                teff = new TEfficiency((*hp),(*ht));
                double bgeff = teff->GetEfficiency(1); double bgefferrlow = teff->GetEfficiencyErrorLow(1); double bgefferrup = teff->GetEfficiencyErrorUp(1);
                double oldsg(0);
                for(unsigned int s = 6; s<samplenamesize; ++s){
                    sg = histos[var+"_"+samplename[s] ]->IntegralAndError(j,histos[var+"_"+samplename[s] ]->GetNbinsX(),sgerr );
                    if(j==1) { sigSum[samplename[s] ] = sg; sigErrSum[samplename[s] ] = sgerr; }
                    if(fabs(oldsg-sg)>0.0001){
                        oldsg =sg;
                        effpass->SetBinContent(1,sg); effpass->SetBinError(1,sgerr);
                        efftotl->SetBinContent(1,sigSum[samplename[s] ]); efftotl->SetBinError(1,sigErrSum[samplename[s] ]);
                        TEfficiency *teff2;
                        ht = (TH1F*)efftotl->Clone("ht");
                        hp = (TH1F*)effpass->Clone("hp");
                        teff2 = new TEfficiency((*hp),(*ht));
                        double sgeff = teff2->GetEfficiency(1); double sgefferrlow = teff2->GetEfficiencyErrorLow(1); double sgefferrup = teff2->GetEfficiencyErrorUp(1);
                        int n = histROC[var+"_"+samplename[s] ]->GetN();
                        histROC[var+"_"+samplename[s] ]->SetPoint(n,sgeff,bgeff);
                        histROC[var+"_"+samplename[s] ]->SetPointError(n,sgefferrlow,sgefferrup,bgefferrlow,bgefferrup);
                        TString tester = var;
                        if((tester.Contains("MET") && fabs(histos[var+"_TTbar1l"]->GetBinLowEdge(j)-300)<0.001)||
                           (tester.Contains("MT2W") && fabs(histos[var+"_TTbar1l"]->GetBinLowEdge(j)-200)<0.001)||
                           (tester.Contains("Topness") && !tester.Contains("TopnessMod") && fabs(histos[var+"_TTbar1l"]->GetBinLowEdge(j)-9)<0.001)||
                           (tester.Contains("TopnessMod") && fabs(histos[var+"_TTbar1l"]->GetBinLowEdge(j)-7)<0.001) ){
                        n = histROCSP[var+"_"+samplename[s] ]->GetN();
                        histROCSP[var+"_"+samplename[s] ]->SetPoint(n,sgeff,bgeff);
                        histROCSP[var+"_"+samplename[s] ]->SetPointError(n,sgefferrlow,sgefferrup,bgefferrlow,bgefferrup);
                        }
                        delete teff2;
                        //histROC[var+"_"+samplename[s] ]->SetPoint(n,sg/sigSum[samplename[s] ],bg/bgSum);
                    }
                }
                delete teff;
            }
        }
    }
    string gfilename = "TGraphs"+prefix+"FurtherChecks.root";
    TFile *fg = new TFile(gfilename.c_str(),"RECREATE");
    fg->cd();
        for(map<string,TGraphAsymmErrors*>::iterator h=    histROC.begin(); h!=    histROC.end();++h) h->second->Write();
        for(map<string,TGraphAsymmErrors*>::iterator h=    histROCSP.begin(); h!=    histROCSP.end();++h) h->second->Write();
    //for(map<string,TGraph*>::iterator h=    histROC.begin(); h!=    histROC.end();++h) h->second->Write();
    cout << "ROCcurves stored in " << fg->GetName() << endl;
    fg->Close();
    }
    
    for(unsigned int i = 0; i<histonames.size(); ++i){
      float bgTop(0),bgST(0),bgRare(0),bgVJets(0);
      double bgTopErr(0),bgSTErr(0),bgRareErr(0),bgVJetsErr(0),bgTopErr2(0),bgTopErr3(0);
      string var;
      var = histonames[i];
      bgTop = histos[var+"_TTbar1l"]->IntegralAndError(histos[var+"_TTbar1l"]->FindBin(cut[i]),histos[var+"_TTbar1l"]->GetNbinsX(),bgTopErr );
      bgTop+= histos[var+"_TTbar2l"]->IntegralAndError(histos[var+"_TTbar2l"]->FindBin(cut[i]),histos[var+"_TTbar2l"]->GetNbinsX(),bgTopErr2 );
      bgTop+= histos[var+"_TTbarH" ]->IntegralAndError(histos[var+"_TTbarH" ]->FindBin(cut[i]),histos[var+"_TTbarH" ]->GetNbinsX(),bgTopErr3 );
      bgST  = histos[var+"_SingleT"]->IntegralAndError(histos[var+"_SingleT"]->FindBin(cut[i]),histos[var+"_SingleT"]->GetNbinsX(),bgSTErr );
      bgRare= histos[var+"_Rare"   ]->IntegralAndError(histos[var+"_Rare"   ]->FindBin(cut[i]),histos[var+"_Rare"   ]->GetNbinsX(),bgRareErr );
      bgVJets= histos[var+"_VJets"  ]->IntegralAndError(histos[var+"_VJets"  ]->FindBin(cut[i]),histos[var+"_VJets"  ]->GetNbinsX(),bgVJetsErr );
      bkg[var] = bgTop+bgST+bgRare+bgVJets; 
      bkgerr[var] = sqrt(pow(bgTopErr,2)+pow(bgTopErr2,2)+pow(bgTopErr3,2)+pow(bgSTErr,2)+pow(bgRareErr,2)+pow(bgVJetsErr,2) );
      //if(i==0) cout << bgTop << " " << bgST << " " << bgRare << " " << bgVJets << endl;
      double signalerr(0);
      sig[var+"_Stop_425_325"] = histos[var+"_Stop_425_325"]->IntegralAndError(histos[var+"_Stop_425_325"]->FindBin(cut[i]),histos[var+"_Stop_425_325"]->GetNbinsX(),signalerr );
      sigerr[var+"_Stop_425_325"] = signalerr;
      sig[var+"_Stop_500_325"] = histos[var+"_Stop_500_325"]->IntegralAndError(histos[var+"_Stop_500_325"]->FindBin(cut[i]),histos[var+"_Stop_500_325"]->GetNbinsX(),signalerr );
      sigerr[var+"_Stop_500_325"] = signalerr;
      sig[var+"_Stop_650_325"] = histos[var+"_Stop_650_325"]->IntegralAndError(histos[var+"_Stop_650_325"]->FindBin(cut[i]),histos[var+"_Stop_650_325"]->GetNbinsX(),signalerr );
      sigerr[var+"_Stop_650_325"] = signalerr;
      sig[var+"_Stop_850_100"] = histos[var+"_Stop_850_100"]->IntegralAndError(histos[var+"_Stop_850_100"]->FindBin(cut[i]),histos[var+"_Stop_850_100"]->GetNbinsX(),signalerr );
      sigerr[var+"_Stop_850_100"] = signalerr;
    }
    cout << prefix << endl;
    if(yield){
      cout << "Event yields" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << " " << setw(10) << histos[var+"_TTbar1l"]->GetBinLowEdge(histos[var+"_TTbar1l"]->FindBin(cut[i])) << " "  << setw(12) << bkg[var]
	     << " "  << setw(12) << sig[var+"_Stop_425_325"] << " "  << setw(12) << sig[var+"_Stop_500_325"]
	     <<      " "  << setw(12) << sig[var+"_Stop_650_325"] << " "  << setw(12) << sig[var+"_Stop_850_100"] << " " << histos[var+"_Stop_425_325"]->GetBinWidth(1) << endl;
      }
    }
    if(SoverB){
      cout << endl << "now S/B" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << " " << setw(10) << histos[var+"_TTbar1l"]->GetBinLowEdge(histos[var+"_TTbar1l"]->FindBin(cut[i]))
	     << " " << setw(12) << SoB(sig[var+"_Stop_425_325"],bkg[var]) << " " << setw(12) << SoB(sig[var+"_Stop_500_325"],bkg[var])
	     <<      " " << setw(12) << SoB(sig[var+"_Stop_650_325"],bkg[var]) << " " << setw(12) << SoB(sig[var+"_Stop_850_100"],bkg[var]) << endl;
      }
    }
    if(SoverSqrtB){
      cout << endl << "now S/sqrt(B)" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << " " << setw(10) <<  histos[var+"_TTbar1l"]->GetBinLowEdge(histos[var+"_TTbar1l"]->FindBin(cut[i]))
	     << " " << setw(12) << SoSqrtB(sig[var+"_Stop_425_325"],bkg[var]) << " " << setw(12) << SoSqrtB(sig[var+"_Stop_500_325"],bkg[var])
	     <<      " " << setw(12) << SoSqrtB(sig[var+"_Stop_650_325"],bkg[var]) << " " << setw(12) << SoSqrtB(sig[var+"_Stop_850_100"],bkg[var]) << endl;
      }
    }
    if(FigureOfMerit){
      cout << endl << "now FoM = S/sqrt(B+Delta(B)^2)" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << " " << setw(10) <<  histos[var+"_TTbar1l"]->GetBinLowEdge(histos[var+"_TTbar1l"]->FindBin(cut[i]))
	     << " " << setw(12) << FoM(sig[var+"_Stop_425_325"],bkg[var],0.3*bkg[var]) << " " << setw(12) << FoM(sig[var+"_Stop_500_325"],bkg[var],0.3*bkg[var])
	     <<      " " << setw(12) << FoM(sig[var+"_Stop_650_325"],bkg[var],0.3*bkg[var]) << " " << setw(12) << FoM(sig[var+"_Stop_850_100"],bkg[var],0.3*bkg[var]) << endl;
      }
    }
    if(SignificanceZbi){
      cout << endl << "now Z_bi" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << " " << setw(10) <<  histos[var+"_TTbar1l"]->GetBinLowEdge(histos[var+"_TTbar1l"]->FindBin(cut[i]))
	     << " " << setw(12) << Zbi(sig[var+"_Stop_425_325"],bkg[var],0.3*bkg[var]) << " " << setw(12) << Zbi(sig[var+"_Stop_500_325"],bkg[var],0.3*bkg[var])
	     <<      " " << setw(12) << Zbi(sig[var+"_Stop_650_325"],bkg[var],0.3*bkg[var]) << " " << setw(12) << Zbi(sig[var+"_Stop_850_100"],bkg[var],0.3*bkg[var]) << endl;
      }
    }


}
