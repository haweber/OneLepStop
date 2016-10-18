#include "TList.h"
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
#include "TStyle.h"
#include "TROOT.h"
#include "TH3F.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMap.h"
#include "TStopwatch.h"
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

void GetCorrelationMatrix(TString inputfilename="mlfit.root"){

  TFile *fin = TFile::Open(inputfilename);
  TH2D *hcov = (TH2D*)fin->Get("shapes_prefit/overall_total_covar");
  //possibly need to redo the axis bin ordering
  //get temp diagram - and swap by
  //hcov->SetBinContent(newi,newj,temp->GetBinContent(oldi,oldj));
  
  TH2D *hcovdiag = (TH2D*)hcov->Clone("forDiag");
  for(int i = 1; i<=hcovdiag->GetNbinsX(); ++i){
      for(int j = 1; j<=hcovdiag->GetNbinsY(); ++j){
	if(i!=j){
	  hcovdiag->SetBinContent(i,j,0);
	  hcovdiag->SetBinError(i,j,0);
	} else {
	  hcovdiag->SetBinContent(i,j,1./sqrt(hcovdiag->GetBinContent(i,j)));
	  hcovdiag->SetBinError(i,j,0);
	}
      }
  }
  
  TH2D *hcor = new TH2D("correlationMatrix","", hcov->GetNbinsX(), hcov->GetXaxis()->GetBinLowEdge(1), hcov->GetXaxis()->GetBinLowEdge(hcov->GetNbinsX()+1), hcov->GetNbinsY(), hcov->GetYaxis()->GetBinLowEdge(1), hcov->GetYaxis()->GetBinLowEdge(hcov->GetNbinsY()+1) );

    for(int i = 1; i<=hcovdiag->GetNbinsX(); ++i){
      for(int j = 1; j<=hcovdiag->GetNbinsY(); ++j){
	hcor->SetBinContent(i,j,hcovdiag->GetBinContent(j,j)*hcov->GetBinContent(i,j)*hcovdiag->GetBinContent(i,i));
      }
    }
  hcov->SetName("covarianceMatrix");
  TFile *fout = new TFile("test.root","RECREATE");
  fout->cd();
  hcor->Write();
  hcov->Write();
  fout->Close();
}
  
