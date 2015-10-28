// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>
#include <map>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TTree.h"
#include "TBranch.h"
#include "TString.h"
#include "TH1F.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

using namespace std;

bool allBKG = true;

void MakeAll();
void CreateAllHisto();
void CreateHisto(TString filename);
void MakeAllTGraphComparison();
void MakeTGraphComparison(TString signal);
void MakeAllPlots();
void MakePlots(TString signal);

void MakeAll(){
  CreateAllHisto();
  MakeAllTGraphComparison();
  MakeAllPlots();
}

void CreateAllHisto(){
  if(allBKG){
    CreateHisto("TTbar1l");
    CreateHisto("TTbar2l");
    CreateHisto("SingleT");
    CreateHisto("Rare");
    CreateHisto("WJets");
    CreateHisto("DYJets");
  }
  CreateHisto("TTJets_DiLept_madgraph_25ns_1");
  CreateHisto("TTJets_DiLept_madgraph_25ns_2");
  CreateHisto("T2bw_600_187p5_50");
  CreateHisto("T2bw_600_325_50");
  CreateHisto("T2bw_600_462p5_50");
  CreateHisto("T2bw_700_250_100");
  CreateHisto("T2bw_700_400_100");
  CreateHisto("T2bw_700_550_100");
  CreateHisto("T2tb_700_250_100");
  CreateHisto("T2tb_700_400_100");
  CreateHisto("T2tb_700_550_100");
  CreateHisto("T2tt_425_325");
  CreateHisto("T2tt_500_325");
  CreateHisto("T2tt_650_325");
  CreateHisto("T2tt_850_100");
}

void CreateHisto(TString filename){
  vector<TString> histonames;
  histonames.push_back("BDToutput_T2bw_600_187p5_50");
  histonames.push_back("BDToutput_T2bw_600_325_50");
  histonames.push_back("BDToutput_T2bw_600_462p5_50");
  histonames.push_back("BDToutput_T2bw_700_250_100");
  histonames.push_back("BDToutput_T2bw_700_400_100");
  histonames.push_back("BDToutput_T2bw_700_550_100");
  histonames.push_back("BDToutput_T2tb_700_250_100");
  histonames.push_back("BDToutput_T2tb_700_400_100");
  histonames.push_back("BDToutput_T2tb_700_550_100");
  histonames.push_back("BDToutput_T2tt_425_325");
  histonames.push_back("BDToutput_T2tt_500_325");
  histonames.push_back("BDToutput_T2tt_650_325");
  histonames.push_back("BDToutput_T2tt_850_100");
  histonames.push_back("pfmet");
  histonames.push_back("pfmet_MT2W");
  map<TString, TH1F*> histos; //massive
  map<TString, float> value;

  TString infilename = "/nfs-7/userdata/stopRun2/testMVA/standardsamples/"+filename+".root";
  TFile *f1 = TFile::Open(infilename.Data());
  TTree* t = (TTree*)f1->Get("t");

  for(unsigned int i = 0; i<histonames.size()-2;++i){
    histos[histonames[i] ] = new TH1F(histonames[i].Data(),"",400,-1,1); histos[histonames[i] ]->Sumw2();
    value[histonames[i] ] = -1;
  }
  histos["pfmet"] = new TH1F("pfmet","",300,250,1000); histos["pfmet"]->Sumw2();
  value["pfmet"] = -1;
  histos["pfmet_MT2W"] = new TH1F("pfmet_MT2W","",300,250,1000); histos["pfmet_MT2W"]->Sumw2();
  value["pfmet_MT2W"] = -1;
  float weight1fb;
  float MT2W;
  float mindphi_met_j1_j2;
  float njets;
  for(unsigned int i = 0; i<histonames.size()-1;++i){
    t->SetBranchAddress(histonames[i].Data(), &value[histonames[i] ]);
  }
  t->SetBranchAddress("scale1fb",                    &weight1fb);
  t->SetBranchAddress("MT2W",                        &MT2W);
  t->SetBranchAddress("mindphi_met_j1_j2",            &mindphi_met_j1_j2);
  t->SetBranchAddress("ngoodjets",                   &njets);
  
  for (Long64_t ievt=0; ievt<t->GetEntries();ievt++) {

    if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

    t->GetEntry(ievt);
    float weight = weight1fb*3.;
    if(filename.Contains("TTJets_DiLept_madgraph_25ns_1")) weight *= 5977821./(5977821.+24521141.);
    if(filename.Contains("TTJets_DiLept_madgraph_25ns_2")) weight *=24521141./(5977821.+24521141.);
    value["pfmet_MT2W"] = value["pfmet"];
    for(unsigned int i = 0; i<histonames.size()-2;++i){
      histos[histonames[i] ]->Fill(value[histonames[i] ],weight);
    }
    //if(MT2W<200) continue;
    //if(mindphi_met_j1_j2<0.8) continue;
    if(njets>=3.9) histos["pfmet"]->Fill(value["pfmet"],weight);//stupid but make sure that we select 4 jets
    if(MT2W>200&&njets>=3.9) histos["pfmet_MT2W"]->Fill(value["pfmet"],weight);//stupid but make sure that we select 4 jets
  }
  TString outfilename = "rootfiles/TMVA/histosforprinting/BDTHistograms_"+filename+".root";
  TFile *fout = new TFile(outfilename.Data(),"RECREATE");
  fout->cd();
  for(unsigned int i = 0; i<histonames.size();++i){
    for(unsigned int j = 0; j<=histos[histonames[i] ]->GetNbinsX()+1; ++j){
      if(histos[histonames[i] ]->GetBinContent(j)<0) histos[histonames[i] ]->SetBinContent(j,0);
    }
    histos[histonames[i] ]->Write();
  }
  fout->Close();
  cout << "Made BDTdistribution histograms " << outfilename << endl;
  delete fout;

}

void MakeAllTGraphComparison(){
  MakeTGraphComparison("T2bw_600_187p5_50");
  MakeTGraphComparison("T2bw_600_325_50");
  MakeTGraphComparison("T2bw_600_462p5_50");
  MakeTGraphComparison("T2bw_700_250_100");
  MakeTGraphComparison("T2bw_700_400_100");
  MakeTGraphComparison("T2bw_700_550_100");
  MakeTGraphComparison("T2tb_700_250_100");
  MakeTGraphComparison("T2tb_700_400_100");
  MakeTGraphComparison("T2tb_700_550_100");
  MakeTGraphComparison("T2tt_425_325");
  MakeTGraphComparison("T2tt_500_325");
  MakeTGraphComparison("T2tt_650_325");
  MakeTGraphComparison("T2tt_850_100");
}

void MakeTGraphComparison(TString signal){

  vector<TString> trainer;
  trainer.push_back("T2bw_600_187p5_50");
  trainer.push_back("T2bw_600_325_50");
  trainer.push_back("T2bw_600_462p5_50");
  trainer.push_back("T2bw_700_250_100");
  trainer.push_back("T2bw_700_400_100");
  trainer.push_back("T2bw_700_550_100");
  trainer.push_back("T2tb_700_250_100");
  trainer.push_back("T2tb_700_400_100");
  trainer.push_back("T2tb_700_550_100");
  trainer.push_back("T2tt_425_325");
  trainer.push_back("T2tt_500_325");
  trainer.push_back("T2tt_650_325");
  trainer.push_back("T2tt_850_100");
  trainer.push_back("pfmet");
  trainer.push_back("pfmet_MT2W");

  const unsigned int p = trainer.size();
  TGraph *g[p];
  
  for(unsigned int k = 0; k<trainer.size();++k){
    TString histoname = "BDToutput_"+trainer[k];
    if(k==trainer.size()-2) histoname = "pfmet";
    if(k==trainer.size()-1) histoname = "pfmet_MT2W";
    g[k] = new TGraph();
    TString name = "TTbar2lVs"+signal+"_trainedwith_"+trainer[k];
    g[k]->SetName(name.Data());
    g[k]->SetTitle(name.Data());
    TFile *fbgd;
    //cout << __LINE__ << endl;
    if(allBKG) fbgd = TFile::Open("rootfiles/TMVA/histosforprinting/BDTHistograms_allBKG.root");
    else fbgd = TFile::Open("rootfiles/TMVA/histosforprinting/BDTHistograms_TTJets_DiLept_madgraph_25ns.root");
    //cout << __LINE__ << " " << fbgd->GetName() << " " << histoname.Data() << endl;
    TH1F *hbgd = (TH1F*)fbgd->Get(histoname.Data());
    //cout << __LINE__ << endl;
    hbgd->SetName("hbgd");
    //cout << __LINE__ << endl;
    TString signame = "rootfiles/TMVA/histosforprinting/BDTHistograms_"+signal+".root";
    TFile *fsig = TFile::Open(signame.Data() );
    TH1F *hsig = (TH1F*)fsig->Get(histoname.Data());
    hsig->SetName("hsig");
    for(int i = 1; i<=hsig->GetNbinsX();++i){
      double x,y;
      x = hsig->Integral(i,hsig->GetNbinsX()+1);//not that this includes overflow bin
      y = hbgd->Integral(i,hbgd->GetNbinsX()+1);//not that this includes overflow bin
      int n = g[k]->GetN();
      g[k]->SetPoint(n,x,y);
    }
  }
  TString outname = "rootfiles/TMVA/histosforprinting/TGraph_TTbar2lVs"+signal+".root";
  if(allBKG) outname = "rootfiles/TMVA/histosforprinting/TGraph_allBKGVs"+signal+".root";
  TFile *fout = new TFile(outname.Data(),"RECREATE");
  fout->cd();
  for(unsigned int k = 0; k<trainer.size();++k){
    g[k]->Sort();
    g[k]->Write();
  }
  fout->Close();
  cout << "Made TGraph comparisons " << outname << endl;
  delete fout;
}

void MakeAllPlots(){
  MakePlots("T2bw_600_187p5_50");
  MakePlots("T2bw_600_325_50");
  MakePlots("T2bw_600_462p5_50");
  MakePlots("T2bw_700_250_100");
  MakePlots("T2bw_700_400_100");
  MakePlots("T2bw_700_550_100");
  MakePlots("T2tb_700_250_100");
  MakePlots("T2tb_700_400_100");
  MakePlots("T2tb_700_550_100");
  MakePlots("T2tt_425_325");
  MakePlots("T2tt_500_325");
  MakePlots("T2tt_650_325");
  MakePlots("T2tt_850_100");
}

void MakePlots(TString signal){

  vector<TString> trainer;
  trainer.push_back("T2bw_600_187p5_50");
  trainer.push_back("T2bw_600_325_50");
  trainer.push_back("T2bw_600_462p5_50");
  trainer.push_back("T2bw_700_250_100");
  trainer.push_back("T2bw_700_400_100");
  trainer.push_back("T2bw_700_550_100");
  trainer.push_back("T2tb_700_250_100");
  trainer.push_back("T2tb_700_400_100");
  trainer.push_back("T2tb_700_550_100");
  trainer.push_back("T2tt_425_325");
  trainer.push_back("T2tt_500_325");
  trainer.push_back("T2tt_650_325");
  trainer.push_back("T2tt_850_100");
  trainer.push_back("pfmet");
  trainer.push_back("pfmet_MT2W");
  for(unsigned int k = 0; k<trainer.size();++k){
    if(trainer[k].Contains(signal)) {
      trainer.erase (trainer.begin()+k);
      break;
    }
  }
  TLegend *leg = new TLegend(0.21,0.63,0.41,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.02);
   leg->SetTextFont(42);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);

  TString outname = "rootfiles/TMVA/histosforprinting/TGraph_TTbar2lVs"+signal+".root";
  if(allBKG) outname = "rootfiles/TMVA/histosforprinting/TGraph_allBKGVs"+signal+".root";
  TFile *fout = TFile::Open(outname.Data() );
  //cout << outname.Data() << endl;

  const unsigned int p = trainer.size();
  TGraph *g[p];
  TGraph *gopt;
  TString name = "TTbar2lVs"+signal+"_trainedwith_"+signal;
  float maxvaluey = -1;
  gopt = (TGraph*)fout->Get(name.Data());
  for(int i = 0; i<gopt->GetN();++i){
    double x,y;
    double xp,yp;
    gopt->GetPoint(i,x,y);//requires sorted points
    gopt->GetPoint(i+1,xp,yp);
    if(x<15.&&xp>15.) {
      if(maxvaluey<yp) maxvaluey = yp;
      break;
    }
  }
  gopt->SetLineColor(kRed); gopt->SetMarkerColor(kRed); gopt->SetLineWidth(2);
  leg->AddEntry(gopt,signal.Data(),"lp");
  for(unsigned int k = 0; k<trainer.size();++k){
    name = "TTbar2lVs"+signal+"_trainedwith_"+trainer[k];
    g[k] = (TGraph*)fout->Get(name.Data());
    if(k== 0) { g[k]->SetLineColor(kYellow+1); g[k]->SetMarkerColor(kYellow+1); g[k]->SetLineStyle(2); }
    if(k== 1) { g[k]->SetLineColor(kGreen+1);  g[k]->SetMarkerColor(kGreen+1);  g[k]->SetLineStyle(3); }
    if(k== 2) { g[k]->SetLineColor(kCyan+1);   g[k]->SetMarkerColor(kCyan+1);   g[k]->SetLineStyle(7); }
    if(k== 3) { g[k]->SetLineColor(kBlue+1);   g[k]->SetMarkerColor(kBlue+1);   g[k]->SetLineStyle(2); }
    if(k== 4) { g[k]->SetLineColor(kMagenta+1);g[k]->SetMarkerColor(kMagenta+1);g[k]->SetLineStyle(3); }
    if(k== 5) { g[k]->SetLineColor(kGray+1);   g[k]->SetMarkerColor(kGray+1);   g[k]->SetLineStyle(7); }
    if(k== 6) { g[k]->SetLineColor(kGreen+3);  g[k]->SetMarkerColor(kGreen+3);  g[k]->SetLineStyle(2); }
    if(k== 7) { g[k]->SetLineColor(kCyan+3);   g[k]->SetMarkerColor(kCyan+3);   g[k]->SetLineStyle(3); }
    if(k== 8) { g[k]->SetLineColor(kBlue+3);   g[k]->SetMarkerColor(kBlue+3);   g[k]->SetLineStyle(7); }
    if(k== 9) { g[k]->SetLineColor(kMagenta+3);g[k]->SetMarkerColor(kMagenta+3);g[k]->SetLineStyle(2); }
    if(k==10) { g[k]->SetLineColor(kRed+3);    g[k]->SetMarkerColor(kRed+3);    g[k]->SetLineStyle(3); }
    if(k==11) { g[k]->SetLineColor(kYellow+3); g[k]->SetMarkerColor(kYellow+3); g[k]->SetLineStyle(7); }
    if(k==12) { g[k]->SetLineColor(kBlack);    g[k]->SetMarkerColor(kBlack);    g[k]->SetLineStyle(8); g[k]->SetLineWidth(2); }//pfmet
    if(k==13) { g[k]->SetLineColor(kOrange+1); g[k]->SetMarkerColor(kOrange+1); g[k]->SetLineStyle(5); g[k]->SetLineWidth(2); }//pfmet_MT2W
    leg->AddEntry(g[k],trainer[k].Data(),"lp");
    for(int i = 0; i<g[k]->GetN();++i){
      double x,y;
      double xp,yp;
      g[k]->GetPoint(i,x,y);//requires sorted points
      g[k]->GetPoint(i+1,xp,yp);
      if(x<15.&&xp>15.) {
	if(maxvaluey<yp) maxvaluey = yp;
	break;
      }
    }
  }
  if(maxvaluey<15) maxvaluey = 15;
  if(allBKG && maxvaluey>15) maxvaluey = 15;
  if(!allBKG && maxvaluey>15) maxvaluey = 15;

  TCanvas *c1 = new TCanvas("c1", "",209,51,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.18);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetBottomMargin(0.15);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
  TH1F *haxis = new TH1F("haxis","",15,0,15);
  haxis->GetXaxis()->SetTitle("signal yield/3 fb^{-1}");
  haxis->GetYaxis()->SetTitle("background yield/3 fb^{-1}");
  haxis->GetYaxis()->SetTitleOffset(1.2);
  haxis->SetMinimum(0.);
  haxis->SetMaximum(maxvaluey);
  haxis->Draw();
  for(unsigned int k = 0; k<trainer.size();++k){
    g[k]->Draw("l");
  }
  gopt->Draw("l");
  leg->Draw("same");
  TString pdfname = "plots/TMVAcompare/TTbar2lVs"+signal+".pdf";
  if(allBKG) pdfname = "plots/TMVAcompare/allBKGVs"+signal+".pdf";
  c1->SaveAs(pdfname.Data());

  delete leg;
  delete c1;
}
