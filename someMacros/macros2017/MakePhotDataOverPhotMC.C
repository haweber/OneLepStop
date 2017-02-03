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

void MakePhotDataOverPhotMC(){

 TFile *fphsim  = TFile::Open("rootfiles/PhotonMETResolution/PhotMETDistribution_NuorNuNuPtweighted_PhotonMC.root");
 //fphsim->ls();
  fphsim->cd();
  TH1F *h23j_1l_sim        = (TH1F*)fphsim ->Get("PhotMET_23j_1ltop_PhotonMC");
  TH1F *h23j_2l_sim        = (TH1F*)fphsim ->Get("PhotMET_23j_2l_PhotonMC");
  TH1F *h23j_1l_lMlb_sim   = (TH1F*)fphsim ->Get("PhotMET_23j_lMlb_1ltop_PhotonMC");
  TH1F *h23j_2l_ltmod_sim  = (TH1F*)fphsim ->Get("PhotMET_23j_ltmod_2l_PhotonMC");
  TH1F *h23j_1l_hMlb_sim   = (TH1F*)fphsim ->Get("PhotMET_23j_hMlb_1ltop_PhotonMC");
  TH1F *h23j_2l_htmod_sim  = (TH1F*)fphsim ->Get("PhotMET_23j_htmod_2l_PhotonMC");
  TH1F *h23j_sim           = (TH1F*)fphsim ->Get("PhotMET_23j_noweight_PhotonMC");
  TH1F *h4j_1l_sim         = (TH1F*)fphsim ->Get("PhotMET_4j_1ltop_PhotonMC");
  TH1F *h4j_2l_sim         = (TH1F*)fphsim ->Get("PhotMET_4j_2l_PhotonMC");
  TH1F *h4j_1l_lMlb_sim    = (TH1F*)fphsim ->Get("PhotMET_4j_lMlb_1ltop_PhotonMC");
  TH1F *h4j_2l_ltmod_sim   = (TH1F*)fphsim ->Get("PhotMET_4j_ltmod_2l_PhotonMC");
  TH1F *h4j_1l_hMlb_sim    = (TH1F*)fphsim ->Get("PhotMET_4j_hMlb_1ltop_PhotonMC");
  TH1F *h4j_2l_htmod_sim   = (TH1F*)fphsim ->Get("PhotMET_4j_htmod_2l_PhotonMC");
  TH1F *h4j_sim            = (TH1F*)fphsim ->Get("PhotMET_4j_noweight_PhotonMC");
  TH1F *h5j_1l_sim         = (TH1F*)fphsim ->Get("PhotMET_5j_1ltop_PhotonMC");
  TH1F *h5j_2l_sim         = (TH1F*)fphsim ->Get("PhotMET_5j_2l_PhotonMC");
  TH1F *h5j_sim            = (TH1F*)fphsim ->Get("PhotMET_5j_noweight_PhotonMC");
  
  TFile *fphdata  = TFile::Open("rootfiles/PhotonMETResolution/PhotMETDistribution_NuorNuNuPtweighted_PhotonData.root");
  fphdata->cd();
  TH1F *h23j_1l_data       = (TH1F*)fphdata->Get("PhotMET_23j_1ltop_PhotonData");
  TH1F *h23j_2l_data       = (TH1F*)fphdata->Get("PhotMET_23j_2l_PhotonData");
  TH1F *h23j_1l_lMlb_data  = (TH1F*)fphdata->Get("PhotMET_23j_lMlb_1ltop_PhotonData");
  TH1F *h23j_2l_ltmod_data = (TH1F*)fphdata->Get("PhotMET_23j_ltmod_2l_PhotonData");
  TH1F *h23j_1l_hMlb_data  = (TH1F*)fphdata->Get("PhotMET_23j_hMlb_1ltop_PhotonData");
  TH1F *h23j_2l_htmod_data = (TH1F*)fphdata->Get("PhotMET_23j_htmod_2l_PhotonData");
  TH1F *h23j_data          = (TH1F*)fphdata->Get("PhotMET_23j_noweight_PhotonData");
  TH1F *h4j_1l_data        = (TH1F*)fphdata->Get("PhotMET_4j_1ltop_PhotonData");
  TH1F *h4j_2l_data        = (TH1F*)fphdata->Get("PhotMET_4j_2l_PhotonData");
  TH1F *h4j_1l_lMlb_data   = (TH1F*)fphdata->Get("PhotMET_4j_lMlb_1ltop_PhotonData");
  TH1F *h4j_2l_ltmod_data  = (TH1F*)fphdata->Get("PhotMET_4j_ltmod_2l_PhotonData");
  TH1F *h4j_1l_hMlb_data   = (TH1F*)fphdata->Get("PhotMET_4j_hMlb_1ltop_PhotonData");
  TH1F *h4j_2l_htmod_data  = (TH1F*)fphdata->Get("PhotMET_4j_htmod_2l_PhotonData");
  TH1F *h4j_data           = (TH1F*)fphdata->Get("PhotMET_4j_noweight_PhotonData");
  TH1F *h5j_1l_data        = (TH1F*)fphdata->Get("PhotMET_5j_1ltop_PhotonData");
  TH1F *h5j_2l_data        = (TH1F*)fphdata->Get("PhotMET_5j_2l_PhotonData");
  TH1F *h5j_data           = (TH1F*)fphdata->Get("PhotMET_5j_noweight_PhotonData");


  double xA[5] = {250.,350.,450.,600.,750.};
  double xB[4] = {250.,450.,600.,750.};
  double xC[6] = {250.,350.,450.,550.,650.,750.};
  double xD[5] = {250.,350.,450.,550.,750.};
  double xE[4] = {250.,350.,550.,750.};
  double xF[3] = {250.,450.,750.};
  double xG[5] = {250.,350.,450.,600.,750.};
  double xH[3] = {250.,450.,750.};
  double xI[5] = {250.,350.,450.,550.,750.};
  
  double xAp[4] = {250.,350.,450.,750.};
  double xBp[2] = {250.,750.};
  double xCp[5] = {250.,350.,450.,550.,750.};
  double xDp[4] = {250.,350.,450.,750.};
  double xEp[3] = {250.,350.,750.};
  double xFp[2] = {250.,750.};
  double xGp[4] = {250.,350.,450.,750.};
  double xHp[2] = {250.,750.};
  double xIp[5] = {250.,350.,450.,550.,750.};
  /*
TFile *f = new TFile("rootfiles/PhotonMETResolution/PhotMETDistribution_NuorNuNuPtweighted_simplekinematics_SRbinned.root","RECREATE");
  f->cd();
  TH1F *hA_1ltop_sim  = (TH1F*)h23j_1l_sim ->Rebin(4,"hA_1ltop_sim" , xA);
  TH1F *hB_1ltop_sim  = (TH1F*)h23j_1l_sim ->Rebin(3,"hB_1ltop_sim" , xB);
  TH1F *hC_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(5,"hC_1ltop_sim" , xC);
  TH1F *hD_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(4,"hD_1ltop_sim" , xD);
  TH1F *hE_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(3,"hE_1ltop_sim" , xE);
  TH1F *hF_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(2,"hF_1ltop_sim" , xF);
  TH1F *hG_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(4,"hG_1ltop_sim" , xG);
  TH1F *hH_1ltop_sim  = (TH1F* )h4j_1l_sim ->Rebin(2,"hH_1ltop_sim" , xH);
  TH1F *hI_1ltop_sim  = (TH1F* )h5j_1l_sim      ->Rebin(4,"hI_1ltop_sim" , xI);
  TH1F *hA_1ltop_data = (TH1F*)h23j_1l_data->Rebin(4,"hA_1ltop_data", xA);
  TH1F *hB_1ltop_data = (TH1F*)h23j_1l_data->Rebin(3,"hB_1ltop_data", xB);
  TH1F *hC_1ltop_data = (TH1F* )h4j_1l_data->Rebin(5,"hC_1ltop_data", xC);
  TH1F *hD_1ltop_data = (TH1F* )h4j_1l_data->Rebin(4,"hD_1ltop_data", xD);
  TH1F *hE_1ltop_data = (TH1F* )h4j_1l_data->Rebin(3,"hE_1ltop_data", xE);
  TH1F *hF_1ltop_data = (TH1F* )h4j_1l_data->Rebin(2,"hF_1ltop_data", xF);
  TH1F *hG_1ltop_data = (TH1F* )h4j_1l_data->Rebin(4,"hG_1ltop_data", xG);
  TH1F *hH_1ltop_data = (TH1F* )h4j_1l_data->Rebin(2,"hH_1ltop_data", xH);
  TH1F *hI_1ltop_data = (TH1F* )h5j_1l_data     ->Rebin(4,"hI_1ltop_data", xI);
  TH1F *hA_2l_sim  = (TH1F*)h23j_2l_sim ->Rebin(4,"hA_2l_sim" , xA);
  TH1F *hB_2l_sim  = (TH1F*)h23j_2l_sim ->Rebin(3,"hB_2l_sim" , xB);
  TH1F *hC_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(5,"hC_2l_sim" , xC);
  TH1F *hD_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(4,"hD_2l_sim" , xD);
  TH1F *hE_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(3,"hE_2l_sim" , xE);
  TH1F *hF_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(2,"hF_2l_sim" , xF);
  TH1F *hG_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(4,"hG_2l_sim" , xG);
  TH1F *hH_2l_sim  = (TH1F* )h4j_2l_sim ->Rebin(2,"hH_2l_sim" , xH);
  TH1F *hI_2l_sim  = (TH1F* )h5j_2l_sim       ->Rebin(4,"hI_2l_sim" , xI);
  TH1F *hA_2l_data = (TH1F*)h23j_2l_data->Rebin(4,"hA_2l_data", xA);
  TH1F *hB_2l_data = (TH1F*)h23j_2l_data->Rebin(3,"hB_2l_data", xB);
  TH1F *hC_2l_data = (TH1F* )h4j_2l_data->Rebin(5,"hC_2l_data", xC);
  TH1F *hD_2l_data = (TH1F* )h4j_2l_data->Rebin(4,"hD_2l_data", xD);
  TH1F *hE_2l_data = (TH1F* )h4j_2l_data->Rebin(3,"hE_2l_data", xE);
  TH1F *hF_2l_data = (TH1F* )h4j_2l_data->Rebin(2,"hF_2l_data", xF);
  TH1F *hG_2l_data = (TH1F* )h4j_2l_data->Rebin(4,"hG_2l_data", xG);
  TH1F *hH_2l_data = (TH1F* )h4j_2l_data->Rebin(2,"hH_2l_data", xH);
  TH1F *hI_2l_data = (TH1F* )h5j_2l_data      ->Rebin(4,"hI_2l_data", xI);
  */
  TFile *f = new TFile("rootfiles/PhotonMETResolution/PhotMETDistribution_NuorNuNuPtweighted_SRbinned_forJohn.root","RECREATE");
  f->cd();
  TH1F *hA_1ltop_sim  = (TH1F*)h23j_1l_hMlb_sim ->Rebin(4,"hA_1ltop_sim" , xA);
  TH1F *hB_1ltop_sim  = (TH1F*)h23j_1l_lMlb_sim ->Rebin(3,"hB_1ltop_sim" , xB);
  TH1F *hC_1ltop_sim  = (TH1F* )h4j_1l_lMlb_sim ->Rebin(5,"hC_1ltop_sim" , xC);
  TH1F *hD_1ltop_sim  = (TH1F* )h4j_1l_hMlb_sim ->Rebin(4,"hD_1ltop_sim" , xD);
  TH1F *hE_1ltop_sim  = (TH1F* )h4j_1l_lMlb_sim ->Rebin(3,"hE_1ltop_sim" , xE);
  TH1F *hF_1ltop_sim  = (TH1F* )h4j_1l_hMlb_sim ->Rebin(2,"hF_1ltop_sim" , xF);
  TH1F *hG_1ltop_sim  = (TH1F* )h4j_1l_lMlb_sim ->Rebin(4,"hG_1ltop_sim" , xG);
  TH1F *hH_1ltop_sim  = (TH1F* )h4j_1l_hMlb_sim ->Rebin(2,"hH_1ltop_sim" , xH);
  TH1F *hI_1ltop_sim  = (TH1F* )h5j_1l_sim      ->Rebin(4,"hI_1ltop_sim" , xI);
  TH1F *hA_1ltop_data = (TH1F*)h23j_1l_hMlb_data->Rebin(4,"hA_1ltop_data", xA);
  TH1F *hB_1ltop_data = (TH1F*)h23j_1l_lMlb_data->Rebin(3,"hB_1ltop_data", xB);
  TH1F *hC_1ltop_data = (TH1F* )h4j_1l_lMlb_data->Rebin(5,"hC_1ltop_data", xC);
  TH1F *hD_1ltop_data = (TH1F* )h4j_1l_hMlb_data->Rebin(4,"hD_1ltop_data", xD);
  TH1F *hE_1ltop_data = (TH1F* )h4j_1l_lMlb_data->Rebin(3,"hE_1ltop_data", xE);
  TH1F *hF_1ltop_data = (TH1F* )h4j_1l_hMlb_data->Rebin(2,"hF_1ltop_data", xF);
  TH1F *hG_1ltop_data = (TH1F* )h4j_1l_lMlb_data->Rebin(4,"hG_1ltop_data", xG);
  TH1F *hH_1ltop_data = (TH1F* )h4j_1l_hMlb_data->Rebin(2,"hH_1ltop_data", xH);
  TH1F *hI_1ltop_data = (TH1F* )h5j_1l_data     ->Rebin(4,"hI_1ltop_data", xI);
  TH1F *hA_2l_sim  = (TH1F*)h23j_2l_htmod_sim ->Rebin(4,"hA_2l_sim" , xA);
  TH1F *hB_2l_sim  = (TH1F*)h23j_2l_htmod_sim ->Rebin(3,"hB_2l_sim" , xB);
  TH1F *hC_2l_sim  = (TH1F* )h4j_2l_ltmod_sim ->Rebin(5,"hC_2l_sim" , xC);
  TH1F *hD_2l_sim  = (TH1F* )h4j_2l_ltmod_sim ->Rebin(4,"hD_2l_sim" , xD);
  TH1F *hE_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(3,"hE_2l_sim" , xE);
  TH1F *hF_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(2,"hF_2l_sim" , xF);
  TH1F *hG_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(4,"hG_2l_sim" , xG);
  TH1F *hH_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(2,"hH_2l_sim" , xH);
  TH1F *hI_2l_sim  = (TH1F* )h5j_2l_sim       ->Rebin(4,"hI_2l_sim" , xI);
  TH1F *hA_2l_data = (TH1F*)h23j_2l_htmod_data->Rebin(4,"hA_2l_data", xA);
  TH1F *hB_2l_data = (TH1F*)h23j_2l_htmod_data->Rebin(3,"hB_2l_data", xB);
  TH1F *hC_2l_data = (TH1F* )h4j_2l_ltmod_data->Rebin(5,"hC_2l_data", xC);
  TH1F *hD_2l_data = (TH1F* )h4j_2l_ltmod_data->Rebin(4,"hD_2l_data", xD);
  TH1F *hE_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(3,"hE_2l_data", xE);
  TH1F *hF_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(2,"hF_2l_data", xF);
  TH1F *hG_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(4,"hG_2l_data", xG);
  TH1F *hH_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(2,"hH_2l_data", xH);
  TH1F *hI_2l_data = (TH1F* )h5j_2l_data      ->Rebin(4,"hI_2l_data", xI);

  TH1F *hAp_2l_sim  = (TH1F*)h23j_2l_htmod_sim ->Rebin(3,"hAp_2l_sim" , xAp);
  TH1F *hBp_2l_sim  = (TH1F*)h23j_2l_htmod_sim ->Rebin(1,"hBp_2l_sim" , xBp);
  TH1F *hCp_2l_sim  = (TH1F* )h4j_2l_ltmod_sim ->Rebin(4,"hCp_2l_sim" , xCp);
  TH1F *hDp_2l_sim  = (TH1F* )h4j_2l_ltmod_sim ->Rebin(3,"hDp_2l_sim" , xDp);
  TH1F *hEp_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(2,"hEp_2l_sim" , xEp);
  TH1F *hFp_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(1,"hFp_2l_sim" , xFp);
  TH1F *hGp_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(3,"hGp_2l_sim" , xGp);
  TH1F *hHp_2l_sim  = (TH1F* )h4j_2l_htmod_sim ->Rebin(1,"hHp_2l_sim" , xHp);
  TH1F *hIp_2l_sim  = (TH1F* )h5j_2l_sim       ->Rebin(4,"hIp_2l_sim" , xIp);
  TH1F *hAp_2l_data = (TH1F*)h23j_2l_htmod_data->Rebin(3,"hAp_2l_data", xAp);
  TH1F *hBp_2l_data = (TH1F*)h23j_2l_htmod_data->Rebin(1,"hBp_2l_data", xBp);
  TH1F *hCp_2l_data = (TH1F* )h4j_2l_ltmod_data->Rebin(4,"hCp_2l_data", xCp);
  TH1F *hDp_2l_data = (TH1F* )h4j_2l_ltmod_data->Rebin(3,"hDp_2l_data", xDp);
  TH1F *hEp_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(2,"hEp_2l_data", xEp);
  TH1F *hFp_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(1,"hFp_2l_data", xFp);
  TH1F *hGp_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(3,"hGp_2l_data", xGp);
  TH1F *hHp_2l_data = (TH1F* )h4j_2l_htmod_data->Rebin(1,"hHp_2l_data", xHp);
  TH1F *hIp_2l_data = (TH1F* )h5j_2l_data      ->Rebin(4,"hIp_2l_data", xIp);
  
  f->cd();
  hA_1ltop_sim  ->Write();
  hB_1ltop_sim  ->Write();
  hC_1ltop_sim  ->Write();
  hD_1ltop_sim  ->Write();
  hE_1ltop_sim  ->Write();
  hF_1ltop_sim  ->Write();
  hG_1ltop_sim  ->Write();
  hH_1ltop_sim  ->Write();
  hI_1ltop_sim  ->Write();
  hA_1ltop_data ->Write();
  hB_1ltop_data ->Write();
  hC_1ltop_data ->Write();
  hD_1ltop_data ->Write();
  hE_1ltop_data ->Write();
  hF_1ltop_data ->Write();
  hG_1ltop_data ->Write();
  hH_1ltop_data ->Write();
  hI_1ltop_data ->Write();
  hA_2l_sim  ->Write();
  hB_2l_sim  ->Write();
  hC_2l_sim  ->Write();
  hD_2l_sim  ->Write();
  hE_2l_sim  ->Write();
  hF_2l_sim  ->Write();
  hG_2l_sim  ->Write();
  hH_2l_sim  ->Write();
  hI_2l_sim  ->Write();
  hA_2l_data ->Write();
  hB_2l_data ->Write();
  hC_2l_data ->Write();
  hD_2l_data ->Write();
  hE_2l_data ->Write();
  hF_2l_data ->Write();
  hG_2l_data ->Write();
  hH_2l_data ->Write();
  hI_2l_data ->Write();
  hAp_2l_sim  ->Write();
  hBp_2l_sim  ->Write();
  hCp_2l_sim  ->Write();
  hDp_2l_sim  ->Write();
  hEp_2l_sim  ->Write();
  hFp_2l_sim  ->Write();
  hGp_2l_sim  ->Write();
  hHp_2l_sim  ->Write();
  hIp_2l_sim  ->Write();
  hAp_2l_data ->Write();
  hBp_2l_data ->Write();
  hCp_2l_data ->Write();
  hDp_2l_data ->Write();
  hEp_2l_data ->Write();
  hFp_2l_data ->Write();
  hGp_2l_data ->Write();
  hHp_2l_data ->Write();
  hIp_2l_data ->Write();

  f->Close();
  
}
