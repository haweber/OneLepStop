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

void StudyRootFiles(){

  int bsel = -2;
  //1: 1b, //2: 2b, //-1: 1j, //-2: 2j
  bool yield           = true;
  bool SoverB          = true;
  bool SoverSqrtB      = true;
  bool FigureOfMerit   = true;
  bool SignificanceZbi = true;
  string prefix = "";
  
  map<string, TH1F*> histos; //massive
  vector<string> histonames; histonames.clear();
  map<string,float> bkg;
  map<string,double> bkgerr;
  map<string,float> sig;
  map<string,double> sigerr;
  vector<double> cut; cut.clear();
  
  /*
  if(prefix==""){
  //                                                bsel: 1                          bsel: 2                               bsel: -1                               bsel: -2 or other
  //histonames.push_back("MyVal");                     if(bsel==1) cut.push_back(0.); else if(bsel==2) cut.push_back(0.); else if(bsel==-1) cut.push_back(0.); else cut.push_back(0.);
  histonames.push_back("Topness");                  if(bsel==1) cut.push_back(10.8); else if(bsel==2) cut.push_back(9.  ); else if(bsel==-1) cut.push_back(12.2); else cut.push_back(10.2);
  histonames.push_back("TopnessMod");               if(bsel==1) cut.push_back(9.6 ); else if(bsel==2) cut.push_back(7.  ); else if(bsel==-1) cut.push_back(11.2); else cut.push_back(9.  );
  histonames.push_back("MT2W");                     if(bsel==1) cut.push_back(300.); else if(bsel==2) cut.push_back(224.); else if(bsel==-1) cut.push_back(450.); else cut.push_back(260.);
  //histonames.push_back("DeltaPhiWl");               if(bsel==1) cut.push_back(1.  ); else if(bsel==2) cut.push_back(1.  ); else if(bsel==-1) cut.push_back(1.  ); else cut.push_back(1.  );
  histonames.push_back("MT2_b_b");                  if(bsel==1) cut.push_back(175.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(220.); else cut.push_back(165.);
  histonames.push_back("MT2_lb_b");                 if(bsel==1) cut.push_back(235.); else if(bsel==2) cut.push_back(200.); else if(bsel==-1) cut.push_back(285.); else cut.push_back(220.);
  histonames.push_back("MT2_lb_bq");                if(bsel==1) cut.push_back(300.); else if(bsel==2) cut.push_back(275.); else if(bsel==-1) cut.push_back(335.); else cut.push_back(280.);
  histonames.push_back("MT2_lb_bqq");               if(bsel==1) cut.push_back(455.); else if(bsel==2) cut.push_back(425.); else if(bsel==-1) cut.push_back(495.); else cut.push_back(445.);
  histonames.push_back("MT2_lb_b_mless");           if(bsel==1) cut.push_back(175.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(220.); else cut.push_back(165.);
  histonames.push_back("MT2_lb_bq_mless");          if(bsel==1) cut.push_back(170.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(200.); else cut.push_back(155.);
  histonames.push_back("MT2_lb_bqq_mless");         if(bsel==1) cut.push_back(185.); else if(bsel==2) cut.push_back(175.); else if(bsel==-1) cut.push_back(210.); else cut.push_back(190.);
  //histonames.push_back("MT2_lb_bqq_Mjjj");          if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  //histonames.push_back("MT2_lb_bqq_MjjjMlb");       if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(375.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  histonames.push_back("MTq_max");                  if(bsel==1) cut.push_back(600.); else if(bsel==2) cut.push_back(600.); else if(bsel==-1) cut.push_back(600.); else cut.push_back(600.);
  histonames.push_back("MTq_leadj300");             if(bsel==1) cut.push_back(750.); else if(bsel==2) cut.push_back(750.); else if(bsel==-1) cut.push_back(750.); else cut.push_back(750.);
  histonames.push_back("MTq_leadj");                if(bsel==1) cut.push_back(650.); else if(bsel==2) cut.push_back(650.); else if(bsel==-1) cut.push_back(650.); else cut.push_back(650.);
  histonames.push_back("METsqrtHT");                if(bsel==1) cut.push_back(14. ); else if(bsel==2) cut.push_back(14. ); else if(bsel==-1) cut.push_back(14. ); else cut.push_back(14. );
  histonames.push_back("RM");                       if(bsel==1) cut.push_back(1.2 ); else if(bsel==2) cut.push_back(1.2 ); else if(bsel==-1) cut.push_back(1.2 ); else cut.push_back(1.2 );
  histonames.push_back("RM300");                    if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM500");                    if(bsel==1) cut.push_back(0.6 ); else if(bsel==2) cut.push_back(0.6 ); else if(bsel==-1) cut.push_back(0.6 ); else cut.push_back(0.6 );
  histonames.push_back("RM700");                    if(bsel==1) cut.push_back(0.5 ); else if(bsel==2) cut.push_back(0.5 ); else if(bsel==-1) cut.push_back(0.5 ); else cut.push_back(0.5 );
  histonames.push_back("MT2_l_q");                  if(bsel==1) cut.push_back(80. ); else if(bsel==2) cut.push_back(80. ); else if(bsel==-1) cut.push_back(80. ); else cut.push_back(80. );
  histonames.push_back("MT2_l_qq");                 if(bsel==1) cut.push_back(140.); else if(bsel==2) cut.push_back(140.); else if(bsel==-1) cut.push_back(140.); else cut.push_back(140.);
  histonames.push_back("MT2_l_qq_mless");           if(bsel==1) cut.push_back(140.); else if(bsel==2) cut.push_back(140.); else if(bsel==-1) cut.push_back(140.); else cut.push_back(140.);
  histonames.push_back("DeltaPhiWl_noMT");          if(bsel==1) cut.push_back(1.  ); else if(bsel==2) cut.push_back(1.  ); else if(bsel==-1) cut.push_back(1.  ); else cut.push_back(1.  );
  }
  if(prefix=="MET300_"){
  //                                                bsel: 1                          bsel: 2                               bsel: -1                               bsel: -2 or other
  //histonames.push_back("MyVal");                     if(bsel==1) cut.push_back(0.); else if(bsel==2) cut.push_back(0.); else if(bsel==-1) cut.push_back(0.); else cut.push_back(0.);
  histonames.push_back("Topness");                  if(bsel==1) cut.push_back(9.2 ); else if(bsel==2) cut.push_back(5.  ); else if(bsel==-1) cut.push_back(11.6); else cut.push_back(8.6  );
  histonames.push_back("TopnessMod");               if(bsel==1) cut.push_back(10. ); else if(bsel==2) cut.push_back(7.  ); else if(bsel==-1) cut.push_back(11.6); else cut.push_back(9.4  );
  histonames.push_back("MT2W");                     if(bsel==1) cut.push_back(232.); else if(bsel==2) cut.push_back(180.); else if(bsel==-1) cut.push_back(364.); else cut.push_back(220.);
  //histonames.push_back("DeltaPhiWl");               if(bsel==1) cut.push_back(1.  ); else if(bsel==2) cut.push_back(1.  ); else if(bsel==-1) cut.push_back(1.  ); else cut.push_back(1.  );
  histonames.push_back("MT2_b_b");                  if(bsel==1) cut.push_back(130.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(165.); else cut.push_back(120.);
  histonames.push_back("MT2_lb_b");                 if(bsel==1) cut.push_back(205.); else if(bsel==2) cut.push_back(175.); else if(bsel==-1) cut.push_back(255.); else cut.push_back(195.);
  histonames.push_back("MT2_lb_bq");                if(bsel==1) cut.push_back(330.); else if(bsel==2) cut.push_back(300.); else if(bsel==-1) cut.push_back(365.); else cut.push_back(310.);
  histonames.push_back("MT2_lb_bqq");               if(bsel==1) cut.push_back(380.); else if(bsel==2) cut.push_back(350.); else if(bsel==-1) cut.push_back(425.); else cut.push_back(380.);
  histonames.push_back("MT2_lb_b_mless");           if(bsel==1) cut.push_back(140.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(185.); else cut.push_back(130.);
  histonames.push_back("MT2_lb_bq_mless");          if(bsel==1) cut.push_back(75.);  else if(bsel==2) cut.push_back(50.);  else if(bsel==-1) cut.push_back(110.); else cut.push_back(65.);
  histonames.push_back("MT2_lb_bqq_mless");         if(bsel==1) cut.push_back(210.); else if(bsel==2) cut.push_back(175.); else if(bsel==-1) cut.push_back(235.); else cut.push_back(210.);
  //histonames.push_back("MT2_lb_bqq_Mjjj");          if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  //histonames.push_back("MT2_lb_bqq_MjjjMlb");       if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(375.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  histonames.push_back("MTq_max");                  if(bsel==1) cut.push_back(700.); else if(bsel==2) cut.push_back(700.); else if(bsel==-1) cut.push_back(700.); else cut.push_back(700.);
  histonames.push_back("MTq_leadj300");             if(bsel==1) cut.push_back(750.); else if(bsel==2) cut.push_back(750.); else if(bsel==-1) cut.push_back(750.); else cut.push_back(750.);
  histonames.push_back("MTq_leadj");                if(bsel==1) cut.push_back(650.); else if(bsel==2) cut.push_back(650.); else if(bsel==-1) cut.push_back(650.); else cut.push_back(650.);
  histonames.push_back("METsqrtHT");                if(bsel==1) cut.push_back(15. ); else if(bsel==2) cut.push_back(15. ); else if(bsel==-1) cut.push_back(15. ); else cut.push_back(15. );
  histonames.push_back("RM");                       if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM300");                    if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM500");                    if(bsel==1) cut.push_back(0.6 ); else if(bsel==2) cut.push_back(0.6 ); else if(bsel==-1) cut.push_back(0.6 ); else cut.push_back(0.6 );
  histonames.push_back("RM700");                    if(bsel==1) cut.push_back(0.5 ); else if(bsel==2) cut.push_back(0.5 ); else if(bsel==-1) cut.push_back(0.5 ); else cut.push_back(0.5 );
  histonames.push_back("MT2_l_q");                  if(bsel==1) cut.push_back(60. ); else if(bsel==2) cut.push_back(60. ); else if(bsel==-1) cut.push_back(60. ); else cut.push_back(60. );
  histonames.push_back("MT2_l_qq");                 if(bsel==1) cut.push_back(50. ); else if(bsel==2) cut.push_back(50. ); else if(bsel==-1) cut.push_back(50. ); else cut.push_back(50. );
  histonames.push_back("MT2_l_qq_mless");           if(bsel==1) cut.push_back(60. ); else if(bsel==2) cut.push_back(60. ); else if(bsel==-1) cut.push_back(60. ); else cut.push_back(60. );
  histonames.push_back("DeltaPhiWl_noMT");          if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  }
  if(prefix=="chi210_"){
  //                                                bsel: 1                          bsel: 2                               bsel: -1                               bsel: -2 or other
  //histonames.push_back("MyVal");                     if(bsel==1) cut.push_back(0.); else if(bsel==2) cut.push_back(0.); else if(bsel==-1) cut.push_back(0.); else cut.push_back(0.);
  histonames.push_back("Topness");                  if(bsel==1) cut.push_back(9.2);  else if(bsel==2) cut.push_back(5.  ); else if(bsel==-1) cut.push_back(11.8); else cut.push_back(9.0  );
  histonames.push_back("TopnessMod");               if(bsel==1) cut.push_back(9.6 ); else if(bsel==2) cut.push_back(7.  ); else if(bsel==-1) cut.push_back(11.8); else cut.push_back(9.4  );
  histonames.push_back("MT2W");                     if(bsel==1) cut.push_back(232.); else if(bsel==2) cut.push_back(180.); else if(bsel==-1) cut.push_back(372.); else cut.push_back(230.);
  //histonames.push_back("DeltaPhiWl");               if(bsel==1) cut.push_back(1.  ); else if(bsel==2) cut.push_back(1.  ); else if(bsel==-1) cut.push_back(1.  ); else cut.push_back(1.  );
  histonames.push_back("MT2_b_b");                  if(bsel==1) cut.push_back(130.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(175.); else cut.push_back(130.);
  histonames.push_back("MT2_lb_b");                 if(bsel==1) cut.push_back(130.); else if(bsel==2) cut.push_back(125.); else if(bsel==-1) cut.push_back(175.); else cut.push_back(135.);
  histonames.push_back("MT2_lb_bq");                if(bsel==1) cut.push_back(210.); else if(bsel==2) cut.push_back(200.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(210.);
  histonames.push_back("MT2_lb_bqq");               if(bsel==1) cut.push_back(380.); else if(bsel==2) cut.push_back(350.); else if(bsel==-1) cut.push_back(425.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_b_mless");           if(bsel==1) cut.push_back(140.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(195.); else cut.push_back(140.);
  histonames.push_back("MT2_lb_bq_mless");          if(bsel==1) cut.push_back(70.);  else if(bsel==2) cut.push_back(50.);  else if(bsel==-1) cut.push_back(115.); else cut.push_back(70.);
  histonames.push_back("MT2_lb_bqq_mless");         if(bsel==1) cut.push_back(95. ); else if(bsel==2) cut.push_back(75. ); else if(bsel==-1) cut.push_back(125.); else cut.push_back(90. );
  //histonames.push_back("MT2_lb_bqq_Mjjj");          if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  //histonames.push_back("MT2_lb_bqq_MjjjMlb");       if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(375.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  histonames.push_back("MTq_max");                  if(bsel==1) cut.push_back(700.); else if(bsel==2) cut.push_back(700.); else if(bsel==-1) cut.push_back(700.); else cut.push_back(700.);
  histonames.push_back("MTq_leadj300");             if(bsel==1) cut.push_back(750.); else if(bsel==2) cut.push_back(750.); else if(bsel==-1) cut.push_back(750.); else cut.push_back(750.);
  histonames.push_back("MTq_leadj");                if(bsel==1) cut.push_back(650.); else if(bsel==2) cut.push_back(650.); else if(bsel==-1) cut.push_back(650.); else cut.push_back(650.);
  histonames.push_back("METsqrtHT");                if(bsel==1) cut.push_back(15. ); else if(bsel==2) cut.push_back(15. ); else if(bsel==-1) cut.push_back(15. ); else cut.push_back(15. );
  histonames.push_back("RM");                       if(bsel==1) cut.push_back(0.9 ); else if(bsel==2) cut.push_back(0.9 ); else if(bsel==-1) cut.push_back(0.9 ); else cut.push_back(0.9 );
  histonames.push_back("RM300");                    if(bsel==1) cut.push_back(0.9 ); else if(bsel==2) cut.push_back(0.9 ); else if(bsel==-1) cut.push_back(0.9 ); else cut.push_back(0.9 );
  histonames.push_back("RM500");                    if(bsel==1) cut.push_back(0.6 ); else if(bsel==2) cut.push_back(0.6 ); else if(bsel==-1) cut.push_back(0.6 ); else cut.push_back(0.6 );
  histonames.push_back("RM700");                    if(bsel==1) cut.push_back(0.5 ); else if(bsel==2) cut.push_back(0.5 ); else if(bsel==-1) cut.push_back(0.5 ); else cut.push_back(0.5 );
  histonames.push_back("MT2_l_q");                  if(bsel==1) cut.push_back(60. ); else if(bsel==2) cut.push_back(60. ); else if(bsel==-1) cut.push_back(60. ); else cut.push_back(60. );
  histonames.push_back("MT2_l_qq");                 if(bsel==1) cut.push_back(50. ); else if(bsel==2) cut.push_back(50. ); else if(bsel==-1) cut.push_back(50. ); else cut.push_back(50. );
  histonames.push_back("MT2_l_qq_mless");           if(bsel==1) cut.push_back(40. ); else if(bsel==2) cut.push_back(40. ); else if(bsel==-1) cut.push_back(40. ); else cut.push_back(40. );
  histonames.push_back("DeltaPhiWl_noMT");          if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  }
  if(prefix=="MT2W200_"){
  //                                                bsel: 1                          bsel: 2                               bsel: -1                               bsel: -2 or other
  //histonames.push_back("MyVal");                     if(bsel==1) cut.push_back(0.); else if(bsel==2) cut.push_back(0.); else if(bsel==-1) cut.push_back(0.); else cut.push_back(0.);
  histonames.push_back("Topness");                  if(bsel==1) cut.push_back(10.6); else if(bsel==2) cut.push_back(10. ); else if(bsel==-1) cut.push_back(11.4); else cut.push_back(10.4 );
  histonames.push_back("TopnessMod");               if(bsel==1) cut.push_back(7.8 ); else if(bsel==2) cut.push_back(7.  ); else if(bsel==-1) cut.push_back(9.8 ); else cut.push_back(5.2  );
  histonames.push_back("MT2W");                     if(bsel==1) cut.push_back(240.); else if(bsel==2) cut.push_back(200.); else if(bsel==-1) cut.push_back(380.); else cut.push_back(200.);
  //histonames.push_back("DeltaPhiWl");               if(bsel==1) cut.push_back(1.  ); else if(bsel==2) cut.push_back(1.  ); else if(bsel==-1) cut.push_back(1.  ); else cut.push_back(1.  );
  histonames.push_back("MT2_b_b");                  if(bsel==1) cut.push_back(110.); else if(bsel==2) cut.push_back(75.);  else if(bsel==-1) cut.push_back(120.); else cut.push_back(75. );
  histonames.push_back("MT2_lb_b");                 if(bsel==1) cut.push_back(175.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(185.); else cut.push_back(160.);
  histonames.push_back("MT2_lb_bq");                if(bsel==1) cut.push_back(300.); else if(bsel==2) cut.push_back(275.); else if(bsel==-1) cut.push_back(315.); else cut.push_back(280.);
  histonames.push_back("MT2_lb_bqq");               if(bsel==1) cut.push_back(385.); else if(bsel==2) cut.push_back(350.); else if(bsel==-1) cut.push_back(420.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_b_mless");           if(bsel==1) cut.push_back(140.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(170.); else cut.push_back(110.);
  histonames.push_back("MT2_lb_bq_mless");          if(bsel==1) cut.push_back(45.);  else if(bsel==2) cut.push_back(25.);  else if(bsel==-1) cut.push_back(75. ); else cut.push_back(35.);
  histonames.push_back("MT2_lb_bqq_mless");         if(bsel==1) cut.push_back(55. ); else if(bsel==2) cut.push_back(25. ); else if(bsel==-1) cut.push_back(70. ); else cut.push_back(45. );
  //histonames.push_back("MT2_lb_bqq_Mjjj");          if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    if(bsel==1) cut.push_back(0.  ); else if(bsel==2) cut.push_back(0.  ); else if(bsel==-1) cut.push_back(0.  ); else cut.push_back(0.  );
  //histonames.push_back("MT2_lb_bqq_MjjjMlb");       if(bsel==1) cut.push_back(375.); else if(bsel==2) cut.push_back(375.); else if(bsel==-1) cut.push_back(375.); else cut.push_back(375.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); if(bsel==1) cut.push_back(0.  ); else if(bsel==2) cut.push_back(0.  ); else if(bsel==-1) cut.push_back(0.  ); else cut.push_back(0.  );
  histonames.push_back("MTq_max");                  if(bsel==1) cut.push_back(450.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(450.); else cut.push_back(450.);
  histonames.push_back("MTq_leadj300");             if(bsel==1) cut.push_back(700.); else if(bsel==2) cut.push_back(700.); else if(bsel==-1) cut.push_back(700.); else cut.push_back(700.);
  histonames.push_back("MTq_leadj");                if(bsel==1) cut.push_back(450.); else if(bsel==2) cut.push_back(450.); else if(bsel==-1) cut.push_back(450.); else cut.push_back(450.);
  histonames.push_back("METsqrtHT");                if(bsel==1) cut.push_back(12.5); else if(bsel==2) cut.push_back(12.5); else if(bsel==-1) cut.push_back(12.5); else cut.push_back(12.5);
  histonames.push_back("RM");                       if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM300");                    if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM500");                    if(bsel==1) cut.push_back(0.6 ); else if(bsel==2) cut.push_back(0.6 ); else if(bsel==-1) cut.push_back(0.6 ); else cut.push_back(0.6 );
  histonames.push_back("RM700");                    if(bsel==1) cut.push_back(0.4 ); else if(bsel==2) cut.push_back(0.4 ); else if(bsel==-1) cut.push_back(0.4 ); else cut.push_back(0.4 );
  histonames.push_back("MT2_l_q");                  if(bsel==1) cut.push_back(20. ); else if(bsel==2) cut.push_back(20. ); else if(bsel==-1) cut.push_back(20. ); else cut.push_back(20. );
  histonames.push_back("MT2_l_qq");                 if(bsel==1) cut.push_back(50. ); else if(bsel==2) cut.push_back(50. ); else if(bsel==-1) cut.push_back(50. ); else cut.push_back(50. );
  histonames.push_back("MT2_l_qq_mless");           if(bsel==1) cut.push_back(20. ); else if(bsel==2) cut.push_back(20. ); else if(bsel==-1) cut.push_back(20. ); else cut.push_back(20. );
  histonames.push_back("DeltaPhiWl_noMT");          if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  }
  if(prefix="all"){
*/  histonames.push_back("Topness");                  if(bsel==1) cut.push_back(10.8); else if(bsel==2) cut.push_back(9.  ); else if(bsel==-1) cut.push_back(12.2); else cut.push_back(10.2);
  histonames.push_back("TopnessMod");               if(bsel==1) cut.push_back(9.6 ); else if(bsel==2) cut.push_back(7.  ); else if(bsel==-1) cut.push_back(11.2); else cut.push_back(9.  );
  histonames.push_back("MT2W");                     if(bsel==1) cut.push_back(240.); else if(bsel==2) cut.push_back(200.); else if(bsel==-1) cut.push_back(380.); else cut.push_back(200.);
  histonames.push_back("MT2_b_b");                  if(bsel==1) cut.push_back(130.); else if(bsel==2) cut.push_back(100.); else if(bsel==-1) cut.push_back(165.); else cut.push_back(120.);
  histonames.push_back("MT2_lb_b");                 if(bsel==1) cut.push_back(205.); else if(bsel==2) cut.push_back(175.); else if(bsel==-1) cut.push_back(255.); else cut.push_back(195.);
  histonames.push_back("MT2_lb_bq");                if(bsel==1) cut.push_back(330.); else if(bsel==2) cut.push_back(300.); else if(bsel==-1) cut.push_back(365.); else cut.push_back(310.);
  histonames.push_back("MT2_lb_bqq");               if(bsel==1) cut.push_back(380.); else if(bsel==2) cut.push_back(350.); else if(bsel==-1) cut.push_back(425.); else cut.push_back(380.);
  histonames.push_back("MT2_lb_b_mless");           if(bsel==1) cut.push_back(175.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(220.); else cut.push_back(165.);
  histonames.push_back("MT2_lb_bq_mless");          if(bsel==1) cut.push_back(170.); else if(bsel==2) cut.push_back(150.); else if(bsel==-1) cut.push_back(200.); else cut.push_back(155.);
  histonames.push_back("MT2_lb_bqq_mless");         if(bsel==1) cut.push_back(185.); else if(bsel==2) cut.push_back(175.); else if(bsel==-1) cut.push_back(210.); else cut.push_back(190.);
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    if(bsel==1) cut.push_back(250.); else if(bsel==2) cut.push_back(250.); else if(bsel==-1) cut.push_back(250.); else cut.push_back(250.);
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); if(bsel==1) cut.push_back(0.  ); else if(bsel==2) cut.push_back(0.  ); else if(bsel==-1) cut.push_back(0.  ); else cut.push_back(0.  );
  histonames.push_back("MTq_max");                  if(bsel==1) cut.push_back(600.); else if(bsel==2) cut.push_back(600.); else if(bsel==-1) cut.push_back(600.); else cut.push_back(600.);
  histonames.push_back("MTq_leadj300");             if(bsel==1) cut.push_back(750.); else if(bsel==2) cut.push_back(750.); else if(bsel==-1) cut.push_back(750.); else cut.push_back(750.);
  histonames.push_back("MTq_leadj");                if(bsel==1) cut.push_back(650.); else if(bsel==2) cut.push_back(650.); else if(bsel==-1) cut.push_back(650.); else cut.push_back(650.);
  histonames.push_back("METsqrtHT");                if(bsel==1) cut.push_back(14. ); else if(bsel==2) cut.push_back(14. ); else if(bsel==-1) cut.push_back(14. ); else cut.push_back(14. );
  histonames.push_back("RM");                       if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM300");                    if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  histonames.push_back("RM500");                    if(bsel==1) cut.push_back(0.6 ); else if(bsel==2) cut.push_back(0.6 ); else if(bsel==-1) cut.push_back(0.6 ); else cut.push_back(0.6 );
  histonames.push_back("RM700");                    if(bsel==1) cut.push_back(0.4 ); else if(bsel==2) cut.push_back(0.4 ); else if(bsel==-1) cut.push_back(0.4 ); else cut.push_back(0.4 );
  histonames.push_back("MT2_l_q");                  if(bsel==1) cut.push_back(60. ); else if(bsel==2) cut.push_back(60. ); else if(bsel==-1) cut.push_back(60. ); else cut.push_back(60. );
  histonames.push_back("MT2_l_qq");                 if(bsel==1) cut.push_back(50. ); else if(bsel==2) cut.push_back(50. ); else if(bsel==-1) cut.push_back(50. ); else cut.push_back(50. );
  histonames.push_back("MT2_l_qq_mless");           if(bsel==1) cut.push_back(60. ); else if(bsel==2) cut.push_back(60. ); else if(bsel==-1) cut.push_back(60. ); else cut.push_back(60. );
  histonames.push_back("DeltaPhiWl_noMT");          if(bsel==1) cut.push_back(0.8 ); else if(bsel==2) cut.push_back(0.8 ); else if(bsel==-1) cut.push_back(0.8 ); else cut.push_back(0.8 );
  //  }

  string addX = "";
  if(bsel == 1) addX = "add1b/";
  if(bsel ==-1) addX = "add1j/";
  if(bsel == 2) addX = "add2b/";
  if(bsel ==-2) addX = "add2j/";
  
  TFile *fin[samplenamesize];
  for(unsigned int j = 0; j<samplenamesize; ++j){
    string rootname = "rootfiles/MassVariableStudies/" + addX + "Histos_"+samplename[j]+".root";
    if(j<=2)  rootname = "rootfiles/MassVariableStudies/" + addX + "Histos_TTbar.root";
    fin[j] = TFile::Open(rootname.c_str());
    fin[j]->cd();
    for(unsigned int i = 0; i<histonames.size(); ++i){
      string mapname;
      if(cut[i]>-99.){
	string loadname = "Print_" + prefix + histonames[i] + "_"+samplename[j];
	mapname = histonames[i] + "_"+samplename[j];
	if(histos.count(mapname) == 0 ) histos[mapname] = (TH1F*)fin[j]->Get(loadname.c_str());
      }
    }
  }

    for(unsigned int i = 0; i<histonames.size(); ++i){
      float bgTop(0),bgST(0),bgRare(0),bgVJets(0);
      double bgTopErr(0),bgSTErr(0),bgRareErr(0),bgVJetsErr(0),bgTopErr2(0),bgTopErr3(0);
      //float sig425(0),sig500(0),sig650(0),sig850(0);
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
    if(yield){
      cout << "Event yields" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << ", cut at " << setw(7) << cut[i] << ": bg="  << setw(10) << bkg[var]
	     << ", sig: 425="  << setw(10) << sig[var+"_Stop_425_325"] << ", 500="  << setw(10) << sig[var+"_Stop_500_325"]
	     <<      ", 650="  << setw(10) << sig[var+"_Stop_650_325"] << ", 800="  << setw(10) << sig[var+"_Stop_850_100"] << " " << histos[var+"_Stop_425_325"]->GetBinWidth(1) << endl;
      }
    }
    if(SoverB){
      cout << endl << "now S/B" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << ", cut at " << setw(7) << cut[i]
	     << ": sig: 425=" << setw(10) << SoB(sig[var+"_Stop_425_325"],bkg[var]) << ", 500=" << setw(10) << SoB(sig[var+"_Stop_500_325"],bkg[var])
	     <<      ", 650=" << setw(10) << SoB(sig[var+"_Stop_650_325"],bkg[var]) << ", 800=" << setw(10) << SoB(sig[var+"_Stop_850_100"],bkg[var]) << endl;
      }
    }
    if(SoverSqrtB){
      cout << endl << "now S/sqrt(B)" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << ", cut at " << setw(7) << cut[i]
	     << ": sig: 425=" << setw(10) << SoSqrtB(sig[var+"_Stop_425_325"],bkg[var]) << ", 500=" << setw(10) << SoSqrtB(sig[var+"_Stop_500_325"],bkg[var])
	     <<      ", 650=" << setw(10) << SoSqrtB(sig[var+"_Stop_650_325"],bkg[var]) << ", 800=" << setw(10) << SoSqrtB(sig[var+"_Stop_850_100"],bkg[var]) << endl;
      }
    }
    if(FigureOfMerit){
      cout << endl << "now FoM = S/sqrt(B+Delta(B)^2)" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << ", cut at " << setw(7) << cut[i]
	     << ": sig: 425=" << setw(10) << FoM(sig[var+"_Stop_425_325"],bkg[var],0.3*bkg[var]) << ", 500=" << setw(10) << FoM(sig[var+"_Stop_500_325"],bkg[var],0.3*bkg[var])
	     <<      ", 650=" << setw(10) << FoM(sig[var+"_Stop_650_325"],bkg[var],0.3*bkg[var]) << ", 800=" << setw(10) << FoM(sig[var+"_Stop_850_100"],bkg[var],0.3*bkg[var]) << endl;
      }
    }
    if(SignificanceZbi){
      cout << endl << "now Z_bi" << endl;
      for(unsigned int i = 0; i<histonames.size(); ++i){
	string var;
	var = histonames[i];
	cout << " "  << setw(25) << var << ", cut at " << setw(7) << cut[i]
	     << ": sig: 425=" << setw(10) << Zbi(sig[var+"_Stop_425_325"],bkg[var],0.3*bkg[var]) << ", 500=" << setw(10) << Zbi(sig[var+"_Stop_500_325"],bkg[var],0.3*bkg[var])
	     <<      ", 650=" << setw(10) << Zbi(sig[var+"_Stop_650_325"],bkg[var],0.3*bkg[var]) << ", 800=" << setw(10) << Zbi(sig[var+"_Stop_850_100"],bkg[var],0.3*bkg[var]) << endl;
      }
    }


}
