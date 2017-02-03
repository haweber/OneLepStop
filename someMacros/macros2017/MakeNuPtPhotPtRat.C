#include "TChain.h"
#include "TString.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 

using namespace std;

void MakeNuPtPhotPtRat(){

  TFile *fnu = TFile::Open("rootfiles/PhotonMETResolution/NuOrNunuPt.root");
  //fnu->ls();
  fnu->cd();
  TH1F* h23j_lMlb_1ltop = (TH1F*)fnu->Get("NuOrNunuPt_MET150_23j_MT120_Mlble175_1ltop");
  TH1F* h23j_hMlb_1ltop = (TH1F*)fnu->Get("NuOrNunuPt_MET150_23j_MT120_Mlbgt175_1ltop");
  TH1F* h4j_lMlb_1ltop  = (TH1F*)fnu->Get("NuOrNunuPt_MET150_4j_MT120_Mlble175_1ltop");
  TH1F* h4j_hMlb_1ltop  = (TH1F*)fnu->Get("NuOrNunuPt_MET150_4j_MT120_Mlbgt175_1ltop");
  TH1F* h5j_1ltop       = (TH1F*)fnu->Get("NuOrNunuPt_MET150_5j_MT120_DPhiLepMETle2_leppTle150_1ltop");
  TH1F* h23j_ltmod_2l = (TH1F*)fnu->Get("NuOrNunuPt_MET150_23j_MT150_tmodle0_2l");
  TH1F* h23j_htmod_2l = (TH1F*)fnu->Get("NuOrNunuPt_MET150_23j_MT150_tmodgt0_2l");
  TH1F* h4j_ltmod_2l  = (TH1F*)fnu->Get("NuOrNunuPt_MET150_4j_MT150_tmodle0_2l");
  TH1F* h4j_htmod_2l  = (TH1F*)fnu->Get("NuOrNunuPt_MET150_4j_MT150_tmodgt0_2l");
  TH1F* h5j_2l        = (TH1F*)fnu->Get("NuOrNunuPt_MET150_5j_MT150_DPhiLepMETle2_leppTle150_2l");
 TFile *fphsim  = TFile::Open("rootfiles/PhotonMETResolution/PhotPt_PhotonMC.root");
 //fphsim->ls();
  fphsim->cd();
  TH1F *h23j_sim = (TH1F*)fphsim->Get("PhotPt_MET150_23j_PhotonMC");
  TH1F *h4j_sim  = (TH1F*)fphsim->Get("PhotPt_MET150_4j_PhotonMC");
  TH1F *h5j_sim  = (TH1F*)fphsim->Get("PhotPt_MET150_5j_PhotonMC");
  TFile *fphdata  = TFile::Open("rootfiles/PhotonMETResolution/PhotPt_PhotonData.root");
  fphdata->cd();
  TH1F *h23j_data = (TH1F*)fphdata->Get("PhotPt_MET150_23j_PhotonData");
  TH1F *h4j_data  = (TH1F*)fphdata->Get("PhotPt_MET150_4j_PhotonData");
  TH1F *h5j_data  = (TH1F*)fphdata->Get("PhotPt_MET150_5j_PhotonData");
  //rebin all by 2
  h23j_lMlb_1ltop->Rebin(2);
  h23j_hMlb_1ltop->Rebin(2);
  h4j_lMlb_1ltop ->Rebin(2);
  h4j_hMlb_1ltop ->Rebin(2);
  h23j_ltmod_2l  ->Rebin(2);
  h23j_htmod_2l  ->Rebin(2);
  h4j_ltmod_2l   ->Rebin(2);
  h4j_htmod_2l   ->Rebin(2);
  h23j_sim       ->Rebin(2);
  h4j_sim        ->Rebin(2);
  h23j_data      ->Rebin(2);
  h4j_data       ->Rebin(2);
  h5j_1ltop      ->Rebin(2);
  h5j_2l         ->Rebin(2);
  h5j_sim        ->Rebin(2);
  h5j_data       ->Rebin(2);

  TH1F *t23j1ltop = (TH1F*)h23j_lMlb_1ltop->Clone("t23j1ltop"); t23j1ltop->Add(h23j_hMlb_1ltop);
  TH1F *t4j1ltop = (TH1F*)h4j_lMlb_1ltop->Clone("t4j1ltop"); t4j1ltop->Add(h4j_hMlb_1ltop);
  TH1F *t23j2l = (TH1F*)h23j_ltmod_2l->Clone("t23j2l"); t23j2l->Add(h23j_htmod_2l);
  TH1F *t4j2l = (TH1F*)h4j_ltmod_2l->Clone("t4j2l"); t4j2l->Add(h4j_htmod_2l);

      /*
  h23j_lMlb_1ltop->Scale(1./h23j_lMlb_1ltop->Integral());
  h23j_hMlb_1ltop->Scale(1./h23j_hMlb_1ltop->Integral());
  h4j_lMlb_1ltop ->Scale(1./h4j_lMlb_1ltop ->Integral());
  h4j_hMlb_1ltop ->Scale(1./h4j_hMlb_1ltop ->Integral());
  h23j_ltmod_2l  ->Scale(1./h23j_ltmod_2l  ->Integral());
  h23j_htmod_2l  ->Scale(1./h23j_htmod_2l  ->Integral());
  h4j_ltmod_2l   ->Scale(1./h4j_ltmod_2l   ->Integral());
  h4j_htmod_2l   ->Scale(1./h4j_htmod_2l   ->Integral());
  h23j_sim       ->Scale(1./h23j_sim       ->Integral());
  h4j_sim        ->Scale(1./h4j_sim        ->Integral());
  h23j_data      ->Scale(1./h23j_data      ->Integral());
  h4j_data       ->Scale(1./h4j_data       ->Integral());
  t23j1ltop      ->Scale(1./t23j1ltop      ->Integral());
  t4j1ltop       ->Scale(1./t4j1ltop       ->Integral());
  t23j2l         ->Scale(1./t23j2l         ->Integral());
  t4j2l          ->Scale(1./t4j2l          ->Integral());
  h5j_1ltop      ->Scale(1./h5j_1ltop      ->Integral());
  h5j_2l         ->Scale(1./h5j_2l         ->Integral());
  h5j_sim        ->Scale(1./h5j_sim        ->Integral());
  h5j_data       ->Scale(1./h5j_data       ->Integral());
      */

  //23j 1top, 5j 1top
  double xbins1[17] = {0, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360,1000};
  //4j 1top
  double xbins2[22] = {0, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 420, 440, 460,1000};
  //23j/4j, 2top, 5j
  double xbins3[34] = {0, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 420, 440, 460, 480, 500, 520, 540, 560, 580, 600, 620, 640, 660, 680,1000};
  TFile *f = new TFile("rootfiles/PhotonMETResolution/NuOrNunuPtVsPhotPt.root","RECREATE");
  f->cd();
  TH1F* hrat_data_23j_lMlb_1ltop = (TH1F*)h23j_lMlb_1ltop->Rebin(16,"NuPtVsPhotPt_23j_lMlb_1ltopVsData",xbins1);
  TH1F* hrat_data_23j_hMlb_1ltop = (TH1F*)h23j_hMlb_1ltop->Rebin(16,"NuPtVsPhotPt_23j_hMlb_1ltopVsData",xbins1);
  TH1F* hrat_data_4j_lMlb_1ltop  = (TH1F*)h4j_lMlb_1ltop ->Rebin(21,"NuPtVsPhotPt_4j_lMlb_1ltopVsData",xbins2);
  TH1F* hrat_data_4j_hMlb_1ltop  = (TH1F*)h4j_hMlb_1ltop ->Rebin(21,"NuPtVsPhotPt_4j_hMlb_1ltopVsData",xbins2);
  TH1F* hrat_sim_23j_lMlb_1ltop  = (TH1F*)h23j_lMlb_1ltop->Rebin(16,"NuPtVsPhotPt_23j_lMlb_1ltopVsSim",xbins1);
  TH1F* hrat_sim_23j_hMlb_1ltop  = (TH1F*)h23j_hMlb_1ltop->Rebin(16,"NuPtVsPhotPt_23j_hMlb_1ltopVsSim",xbins1);
  TH1F* hrat_sim_4j_lMlb_1ltop   = (TH1F*)h4j_lMlb_1ltop ->Rebin(21,"NuPtVsPhotPt_4j_lMlb_1ltopVsSim",xbins2);
  TH1F* hrat_sim_4j_hMlb_1ltop   = (TH1F*)h4j_hMlb_1ltop ->Rebin(21,"NuPtVsPhotPt_4j_hMlb_1ltopVsSim",xbins2);
  TH1F* hrat_data_23j_ltmod_2l = (TH1F*)h23j_ltmod_2l->Rebin(33,"NuNuPtVsPhotPt_23j_ltmod_2lVsData",xbins3);
  TH1F* hrat_data_23j_htmod_2l = (TH1F*)h23j_htmod_2l->Rebin(33,"NuNuPtVsPhotPt_23j_htmod_2lVsData",xbins3);
  TH1F* hrat_data_4j_ltmod_2l  = (TH1F*)h4j_ltmod_2l ->Rebin(33,"NuNuPtVsPhotPt_4j_ltmod_2lVsData",xbins3);
  TH1F* hrat_data_4j_htmod_2l  = (TH1F*)h4j_htmod_2l ->Rebin(33,"NuNuPtVsPhotPt_4j_htmod_2lVsData",xbins3);
  TH1F* hrat_sim_23j_ltmod_2l  = (TH1F*)h23j_ltmod_2l->Rebin(33,"NuNuPtVsPhotPt_23j_ltmod_2lVsSim",xbins3);
  TH1F* hrat_sim_23j_htmod_2l  = (TH1F*)h23j_htmod_2l->Rebin(33,"NuNuPtVsPhotPt_23j_htmod_2lVsSim",xbins3);
  TH1F* hrat_sim_4j_ltmod_2l   = (TH1F*)h4j_ltmod_2l ->Rebin(33,"NuNuPtVsPhotPt_4j_ltmod_2lVsSim",xbins3);
  TH1F* hrat_sim_4j_htmod_2l   = (TH1F*)h4j_htmod_2l ->Rebin(33,"NuNuPtVsPhotPt_4j_htmod_2lVsSim",xbins3);
  TH1F* hrat_data_23j_1ltop = (TH1F*)t23j1ltop->Rebin(16,"NuPtVsPhotPt_23j_1ltopVsData",xbins1);
  TH1F* hrat_data_4j_1ltop  = (TH1F*)t4j1ltop ->Rebin(21,"NuPtVsPhotPt_4j_1ltopVsData",xbins2);
  TH1F* hrat_data_23j_2l    = (TH1F*)t23j2l   ->Rebin(33,"NuPtVsPhotPt_23j_2lVsData",xbins3);
  TH1F* hrat_data_4j_2l     = (TH1F*)t4j2l    ->Rebin(33,"NuPtVsPhotPt_4j_2lVsData",xbins3);
  TH1F* hrat_sim_23j_1ltop  = (TH1F*)t23j1ltop->Rebin(16,"NuPtVsPhotPt_23j_1ltopVsSim",xbins1);
  TH1F* hrat_sim_4j_1ltop   = (TH1F*)t4j1ltop ->Rebin(21,"NuPtVsPhotPt_4j_1ltopVsSim",xbins2);
  TH1F* hrat_sim_23j_2l     = (TH1F*)t23j2l   ->Rebin(33,"NuPtVsPhotPt_23j_2lVsSim",xbins3);
  TH1F* hrat_sim_4j_2l      = (TH1F*)t4j2l    ->Rebin(33,"NuPtVsPhotPt_4j_2lVsSim",xbins3);
  TH1F* hrat_data_5j_1ltop  = (TH1F*)h5j_1ltop->Rebin(16,"NuPtVsPhotPt_5j_1ltopVsData",xbins1);
  TH1F* hrat_sim_5j_1ltop   = (TH1F*)h5j_1ltop->Rebin(16,"NuPtVsPhotPt_5j_1ltopVsSim",xbins1);
  TH1F* hrat_data_5j_2l     = (TH1F*)h5j_2l   ->Rebin(33,"NuPtVsPhotPt_5j_2lVsData",xbins3);
  TH1F* hrat_sim_5j_2l      = (TH1F*)h5j_2l   ->Rebin(33,"NuPtVsPhotPt_5j_2lVsSim",xbins3);
  /*
  TH1F* hrat_data_23j_lMlb_1ltop = (TH1F*)h23j_lMlb_1ltop->Clone("NuPtVsPhotPt_23j_lMlb_1ltopVsData");
  TH1F* hrat_data_23j_hMlb_1ltop = (TH1F*)h23j_hMlb_1ltop->Clone("NuPtVsPhotPt_23j_hMlb_1ltopVsData");
  TH1F* hrat_data_4j_lMlb_1ltop  = (TH1F*)h4j_lMlb_1ltop ->Clone("NuPtVsPhotPt_4j_lMlb_1ltopVsData");
  TH1F* hrat_data_4j_hMlb_1ltop  = (TH1F*)h4j_hMlb_1ltop ->Clone("NuPtVsPhotPt_4j_hMlb_1ltopVsData");
  TH1F* hrat_sim_23j_lMlb_1ltop  = (TH1F*)h23j_lMlb_1ltop->Clone("NuPtVsPhotPt_23j_lMlb_1ltopVsSim");
  TH1F* hrat_sim_23j_hMlb_1ltop  = (TH1F*)h23j_hMlb_1ltop->Clone("NuPtVsPhotPt_23j_hMlb_1ltopVsSim");
  TH1F* hrat_sim_4j_lMlb_1ltop   = (TH1F*)h4j_lMlb_1ltop ->Clone("NuPtVsPhotPt_4j_lMlb_1ltopVsSim");
  TH1F* hrat_sim_4j_hMlb_1ltop   = (TH1F*)h4j_hMlb_1ltop ->Clone("NuPtVsPhotPt_4j_hMlb_1ltopVsSim");
  TH1F* hrat_data_23j_ltmod_2l = (TH1F*)h23j_ltmod_2l->Clone("NuNuPtVsPhotPt_23j_ltmod_2lVsData");
  TH1F* hrat_data_23j_htmod_2l = (TH1F*)h23j_htmod_2l->Clone("NuNuPtVsPhotPt_23j_htmod_2lVsData");
  TH1F* hrat_data_4j_ltmod_2l  = (TH1F*)h4j_ltmod_2l ->Clone("NuNuPtVsPhotPt_4j_ltmod_2lVsData");
  TH1F* hrat_data_4j_htmod_2l  = (TH1F*)h4j_htmod_2l ->Clone("NuNuPtVsPhotPt_4j_htmod_2lVsData");
  TH1F* hrat_sim_23j_ltmod_2l  = (TH1F*)h23j_ltmod_2l->Clone("NuNuPtVsPhotPt_23j_ltmod_2lVsSim");
  TH1F* hrat_sim_23j_htmod_2l  = (TH1F*)h23j_htmod_2l->Clone("NuNuPtVsPhotPt_23j_htmod_2lVsSim");
  TH1F* hrat_sim_4j_ltmod_2l   = (TH1F*)h4j_ltmod_2l ->Clone("NuNuPtVsPhotPt_4j_ltmod_2lVsSim");
  TH1F* hrat_sim_4j_htmod_2l   = (TH1F*)h4j_htmod_2l ->Clone("NuNuPtVsPhotPt_4j_htmod_2lVsSim");
  TH1F* hrat_data_23j_1ltop = (TH1F*)t23j1ltop->Clone("NuPtVsPhotPt_23j_1ltopVsData");
  TH1F* hrat_data_4j_1ltop  = (TH1F*)t4j1ltop ->Clone("NuPtVsPhotPt_4j_1ltopVsData");
  TH1F* hrat_data_23j_2l    = (TH1F*)t23j2l   ->Clone("NuPtVsPhotPt_23j_2lVsData");
  TH1F* hrat_data_4j_2l     = (TH1F*)t4j2l    ->Clone("NuPtVsPhotPt_4j_2lVsData");
  TH1F* hrat_sim_23j_1ltop  = (TH1F*)t23j1ltop->Clone("NuPtVsPhotPt_23j_1ltopVsSim");
  TH1F* hrat_sim_4j_1ltop   = (TH1F*)t4j1ltop ->Clone("NuPtVsPhotPt_4j_1ltopVsSim");
  TH1F* hrat_sim_23j_2l     = (TH1F*)t23j2l   ->Clone("NuPtVsPhotPt_23j_2lVsSim");
  TH1F* hrat_sim_4j_2l      = (TH1F*)t4j2l    ->Clone("NuPtVsPhotPt_4j_2lVsSim");
  TH1F* hrat_data_5j_1ltop  = (TH1F*)h5j_1ltop->Clone("NuPtVsPhotPt_5j_1ltopVsData");
  TH1F* hrat_sim_5j_1ltop   = (TH1F*)h5j_1ltop->Clone("NuPtVsPhotPt_5j_1ltopVsSim");
  TH1F* hrat_data_5j_2l     = (TH1F*)h5j_2l   ->Clone("NuPtVsPhotPt_5j_2lVsData");
  TH1F* hrat_sim_5j_2l      = (TH1F*)h5j_2l   ->Clone("NuPtVsPhotPt_5j_2lVsSim");
  */

  hrat_data_23j_lMlb_1ltop ->Scale(1./hrat_data_23j_lMlb_1ltop->Integral());
  hrat_data_23j_hMlb_1ltop ->Scale(1./hrat_data_23j_hMlb_1ltop->Integral());
  hrat_data_4j_lMlb_1ltop  ->Scale(1./hrat_data_4j_lMlb_1ltop ->Integral());
  hrat_data_4j_hMlb_1ltop  ->Scale(1./hrat_data_4j_hMlb_1ltop ->Integral());
  hrat_sim_23j_lMlb_1ltop  ->Scale(1./hrat_sim_23j_lMlb_1ltop ->Integral());
  hrat_sim_23j_hMlb_1ltop  ->Scale(1./hrat_sim_23j_hMlb_1ltop ->Integral());
  hrat_sim_4j_lMlb_1ltop   ->Scale(1./hrat_sim_4j_lMlb_1ltop  ->Integral());
  hrat_sim_4j_hMlb_1ltop   ->Scale(1./hrat_sim_4j_hMlb_1ltop  ->Integral());
  hrat_data_23j_ltmod_2l ->Scale(1./hrat_data_23j_ltmod_2l->Integral());
  hrat_data_23j_htmod_2l ->Scale(1./hrat_data_23j_htmod_2l->Integral());
  hrat_data_4j_ltmod_2l  ->Scale(1./hrat_data_4j_ltmod_2l ->Integral());
  hrat_data_4j_htmod_2l  ->Scale(1./hrat_data_4j_htmod_2l ->Integral());
  hrat_sim_23j_ltmod_2l  ->Scale(1./hrat_sim_23j_ltmod_2l ->Integral());
  hrat_sim_23j_htmod_2l  ->Scale(1./hrat_sim_23j_htmod_2l ->Integral());
  hrat_sim_4j_ltmod_2l   ->Scale(1./hrat_sim_4j_ltmod_2l  ->Integral());
  hrat_sim_4j_htmod_2l   ->Scale(1./hrat_sim_4j_htmod_2l  ->Integral());
  hrat_data_23j_1ltop ->Scale(1./hrat_data_23j_1ltop->Integral());
  hrat_data_4j_1ltop  ->Scale(1./hrat_data_4j_1ltop ->Integral());
  hrat_data_23j_2l    ->Scale(1./hrat_data_4j_1ltop ->Integral());
  hrat_data_4j_2l     ->Scale(1./hrat_data_4j_2l    ->Integral());
  hrat_sim_23j_1ltop  ->Scale(1./hrat_sim_23j_1ltop ->Integral());
  hrat_sim_4j_1ltop   ->Scale(1./hrat_sim_4j_1ltop  ->Integral());
  hrat_sim_23j_2l     ->Scale(1./hrat_sim_23j_2l    ->Integral());
  hrat_sim_4j_2l      ->Scale(1./hrat_sim_4j_2l     ->Integral());
  hrat_data_5j_1ltop  ->Scale(1./hrat_data_5j_1ltop ->Integral());
  hrat_sim_5j_1ltop   ->Scale(1./hrat_sim_5j_1ltop  ->Integral());
  hrat_data_5j_2l     ->Scale(1./hrat_data_5j_2l    ->Integral());
  hrat_sim_5j_2l      ->Scale(1./hrat_sim_5j_2l     ->Integral());

  TH1F *h23j_data_1l = (TH1F*)h23j_data->Rebin(16,"h23j_data_1l",xbins1);
  TH1F *h23j_sim_1l  = (TH1F*)h23j_sim ->Rebin(16,"h23j_sim_1l", xbins1);
  TH1F *h5j_data_1l  = (TH1F*)h5j_data ->Rebin(16,"h5j_data_1l", xbins1);
  TH1F *h5j_sim_1l   = (TH1F*)h5j_sim  ->Rebin(16,"h5j_sim_1l",  xbins1);
  TH1F *h4j_data_1l  = (TH1F*)h4j_data ->Rebin(21,"h4j_data_1l", xbins2);
  TH1F *h4j_sim_1l   = (TH1F*)h4j_sim  ->Rebin(21,"h4j_sim_1l",  xbins2);

  TH1F *h23j_data_2l = (TH1F*)h23j_data->Rebin(33,"h23j_data_2l",xbins3);
  TH1F *h23j_sim_2l  = (TH1F*)h23j_sim ->Rebin(33,"h23j_sim_2l", xbins3);
  TH1F *h5j_data_2l  = (TH1F*)h5j_data ->Rebin(33,"h5j_data_2l", xbins3);
  TH1F *h5j_sim_2l   = (TH1F*)h5j_sim  ->Rebin(33,"h5j_sim_2l",  xbins3);
  TH1F *h4j_data_2l  = (TH1F*)h4j_data ->Rebin(33,"h4j_data_2l", xbins3);
  TH1F *h4j_sim_2l   = (TH1F*)h4j_sim  ->Rebin(33,"h4j_sim_2l",  xbins3);

  h23j_data_1l->Scale(1./h23j_data_1l->Integral());
  h23j_sim_1l ->Scale(1./h23j_sim_1l ->Integral());
  h5j_data_1l ->Scale(1./h5j_data_1l ->Integral());
  h5j_sim_1l  ->Scale(1./h5j_sim_1l  ->Integral());
  h4j_data_1l ->Scale(1./h4j_data_1l ->Integral());
  h4j_sim_1l  ->Scale(1./h4j_sim_1l  ->Integral());
  h23j_data_2l->Scale(1./h23j_data_2l->Integral());
  h23j_sim_2l ->Scale(1./h23j_sim_2l ->Integral());
  h5j_data_2l ->Scale(1./h5j_data_2l ->Integral());
  h5j_sim_2l  ->Scale(1./h5j_sim_2l  ->Integral());
  h4j_data_2l ->Scale(1./h4j_data_2l ->Integral());
  h4j_sim_2l  ->Scale(1./h4j_sim_2l  ->Integral());
  
  hrat_data_23j_lMlb_1ltop->Divide(h23j_data_1l);
  hrat_data_23j_hMlb_1ltop->Divide(h23j_data_1l);
  hrat_data_4j_lMlb_1ltop ->Divide(h4j_data_1l);
  hrat_data_4j_hMlb_1ltop ->Divide(h4j_data_1l);
  hrat_sim_23j_lMlb_1ltop ->Divide(h23j_sim_1l);
  hrat_sim_23j_hMlb_1ltop ->Divide(h23j_sim_1l);
  hrat_sim_4j_lMlb_1ltop  ->Divide(h4j_sim_1l);
  hrat_sim_4j_hMlb_1ltop  ->Divide(h4j_sim_1l);
  hrat_data_23j_ltmod_2l->Divide(h23j_data_2l);
  hrat_data_23j_htmod_2l->Divide(h23j_data_2l);
  hrat_data_4j_ltmod_2l ->Divide(h4j_data_2l);
  hrat_data_4j_htmod_2l ->Divide(h4j_data_2l);
  hrat_sim_23j_ltmod_2l ->Divide(h23j_sim_2l);
  hrat_sim_23j_htmod_2l ->Divide(h23j_sim_2l);
  hrat_sim_4j_ltmod_2l  ->Divide(h4j_sim_2l);
  hrat_sim_4j_htmod_2l  ->Divide(h4j_sim_2l);
  hrat_data_23j_1ltop->Divide(h23j_data_1l);
  hrat_data_4j_1ltop ->Divide(h4j_data_1l);
  hrat_data_23j_2l   ->Divide(h23j_data_2l);
  hrat_data_4j_2l    ->Divide(h4j_data_2l);
  hrat_sim_23j_1ltop->Divide(h23j_sim_1l);
  hrat_sim_4j_1ltop ->Divide(h4j_sim_1l);
  hrat_sim_23j_2l   ->Divide(h23j_sim_2l);
  hrat_sim_4j_2l    ->Divide(h4j_sim_2l);
  hrat_data_5j_1ltop->Divide(h5j_data_1l);
  hrat_sim_5j_1ltop ->Divide(h5j_sim_1l);
  hrat_data_5j_2l   ->Divide(h5j_data_2l);
  hrat_sim_5j_2l    ->Divide(h5j_sim_2l);
  
  f->cd();
  hrat_data_23j_lMlb_1ltop->Write();
  hrat_data_23j_hMlb_1ltop->Write();
  hrat_data_4j_lMlb_1ltop ->Write();
  hrat_data_4j_hMlb_1ltop ->Write();
  hrat_sim_23j_lMlb_1ltop ->Write();
  hrat_sim_23j_hMlb_1ltop ->Write();
  hrat_sim_4j_lMlb_1ltop  ->Write();
  hrat_sim_4j_hMlb_1ltop  ->Write();
  hrat_data_23j_ltmod_2l->Write();
  hrat_data_23j_htmod_2l->Write();
  hrat_data_4j_ltmod_2l ->Write();
  hrat_data_4j_htmod_2l ->Write();
  hrat_sim_23j_ltmod_2l ->Write();
  hrat_sim_23j_htmod_2l ->Write();
  hrat_sim_4j_ltmod_2l  ->Write();
  hrat_sim_4j_htmod_2l  ->Write();
  hrat_data_23j_1ltop->Write();
  hrat_data_4j_1ltop ->Write();
  hrat_data_23j_2l   ->Write();
  hrat_data_4j_2l    ->Write();
  hrat_sim_23j_1ltop->Write();
  hrat_sim_4j_1ltop ->Write();
  hrat_sim_23j_2l   ->Write();
  hrat_sim_4j_2l    ->Write();
  hrat_data_5j_1ltop->Write();
  hrat_sim_5j_1ltop ->Write();
  hrat_data_5j_2l   ->Write();
  hrat_sim_5j_2l    ->Write();
  f->Close();
  
}
