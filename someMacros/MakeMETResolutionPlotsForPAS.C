#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TColor.h"
#include "TPad.h"
#include "TF1.h"
#include "TLine.h"
#include "TLatex.h"


void MakeMETResolutionFile(){
    

   map<string, TH1F*> histos;
   vector<string> histonamesData; histonamesData.clear();
   vector<string> histonamesMC; histonamesMC.clear();
   vector<string> histonamesnew; histonamesnew.clear();
   //vector<int> hbins; hbins.clear();
   //vector<float> hlow; hlow.clear();
   //vector<float> hup; hup.clear();
    
    histonamesMC.push_back("PhotHT_MET250_ge4j0b_PhotonMC");
    histonamesMC.push_back("PhotHT_MET250_3j0b_PhotonMC");
    histonamesMC.push_back("PhotHT_MET250_2j0b_PhotonMC");
    histonamesMC.push_back("PhotHT_MET250_ge4jge1b_PhotonMC");
    histonamesMC.push_back("PhotHT_MET250_3jge1b_PhotonMC");
    histonamesMC.push_back("PhotHT_MET250_2jge1b_PhotonMC");
   
   histonamesMC.push_back("PhotMET_ge4j0b_PhotonMC");
    histonamesMC.push_back("PhotMET_3j0b_PhotonMC");
    histonamesMC.push_back("PhotMET_2j0b_PhotonMC");
   histonamesMC.push_back("PhotMET_ge4jge1b_PhotonMC");
    histonamesMC.push_back("PhotMET_3jge1b_PhotonMC");
    histonamesMC.push_back("PhotMET_2jge1b_PhotonMC");
   histonamesMC.push_back("PhotMET_ge4j0b_unwgt_PhotonMC");
    histonamesMC.push_back("PhotMET_3j0b_unwgt_PhotonMC");
    histonamesMC.push_back("PhotMET_2j0b_unwgt_PhotonMC");
   histonamesMC.push_back("PhotMET_ge4jge1b_unwgt_PhotonMC");
    histonamesMC.push_back("PhotMET_3jge1b_unwgt_PhotonMC");
    histonamesMC.push_back("PhotMET_2jge1b_unwgt_PhotonMC");
   
   histonamesData.push_back("PhotMET_ge4j0b_PhotonData");
    histonamesData.push_back("PhotMET_3j0b_PhotonData");
    histonamesData.push_back("PhotMET_2j0b_PhotonData");
   histonamesData.push_back("PhotMET_ge4jge1b_PhotonData");
    histonamesData.push_back("PhotMET_3jge1b_PhotonData");
    histonamesData.push_back("PhotMET_2jge1b_PhotonData");
   histonamesData.push_back("PhotMET_ge4j0b_unwgt_PhotonData");
    histonamesData.push_back("PhotMET_3j0b_unwgt_PhotonData");
    histonamesData.push_back("PhotMET_2j0b_unwgt_PhotonData");
   histonamesData.push_back("PhotMET_ge4jge1b_unwgt_PhotonData");
    histonamesData.push_back("PhotMET_3jge1b_unwgt_PhotonData");
    histonamesData.push_back("PhotMET_2jge1b_unwgt_PhotonData");
    
    histonamesData.push_back("PhotHT_MET250_ge4j0b_PhotonData");
    histonamesData.push_back("PhotHT_MET250_3j0b_PhotonData");
    histonamesData.push_back("PhotHT_MET250_2j0b_PhotonData");
    histonamesData.push_back("PhotHT_MET250_ge4jge1b_PhotonData");
    histonamesData.push_back("PhotHT_MET250_3jge1b_PhotonData");
    histonamesData.push_back("PhotHT_MET250_2jge1b_PhotonData");
   
   histonamesnew.push_back("PhotMET_ge4j0b_DataVsMC");
    histonamesnew.push_back("PhotMET_3j0b_DataVsMC");
    histonamesnew.push_back("PhotMET_2j0b_DataVsMC");
   histonamesnew.push_back("PhotMET_ge4jge1b_DataVsMC");
    histonamesnew.push_back("PhotMET_3jge1b_DataVsMC");
    histonamesnew.push_back("PhotMET_2jge1b_DataVsMC");
   histonamesnew.push_back("PhotMET_ge4j0b_unwgt_DataVsMC");
    histonamesnew.push_back("PhotMET_3j0b_unwgt_DataVsMC");
    histonamesnew.push_back("PhotMET_2j0b_unwgt_DataVsMC");
   histonamesnew.push_back("PhotMET_ge4jge1b_unwgt_DataVsMC");
    histonamesnew.push_back("PhotMET_3jge1b_unwgt_DataVsMC");
    histonamesnew.push_back("PhotMET_2jge1b_unwgt_DataVsMC");
   
   histonamesnew.push_back("PhotMET_ge4j0b_wgtVsunwgt_MC");
    histonamesnew.push_back("PhotMET_3j0b_wgtVsunwgt_MC");
    histonamesnew.push_back("PhotMET_2j0b_wgtVsunwgt_MC");
   histonamesnew.push_back("PhotMET_ge4jge1b_wgtVsunwgt_MC");
    histonamesnew.push_back("PhotMET_3jge1b_wgtVsunwgt_MC");
    histonamesnew.push_back("PhotMET_2jge1b_wgtVsunwgt_MC");
   histonamesnew.push_back("PhotMET_ge4j0b_wgtVsunwgt_Data");
    histonamesnew.push_back("PhotMET_3j0b_wgtVsunwgt_Data");
    histonamesnew.push_back("PhotMET_2j0b_wgtVsunwgt_Data");
   histonamesnew.push_back("PhotMET_ge4jge1b_wgtVsunwgt_Data");
    histonamesnew.push_back("PhotMET_3jge1b_wgtVsunwgt_Data");
    histonamesnew.push_back("PhotMET_2jge1b_wgtVsunwgt_Data");
   
   TFile *fMC = TFile::Open("PhotMETResolutionIncl2jkilllow_PhotonMC.root");
   fMC->cd();
    for(unsigned int i = 0; i<histonamesMC.size();++i) histos[histonamesMC[i] ] = (TH1F*)fMC->Get(histonamesMC[i].c_str());
    for(unsigned int i = 0; i<histonamesMC.size();++i) {
        histos["Norm" + histonamesMC[i] ] = (TH1F*)histos[histonamesMC[i] ]->Clone(("Norm" + histonamesMC[i]).c_str());
        //histos["Norm" + histonamesMC[i] ] = (TH1F*)fMC->Get(histonamesMC[i].c_str());
        //histos["Norm" + histonamesMC[i] ]->SetName(("Norm" + histonamesMC[i]).c_str());
        histos["Norm" + histonamesMC[i] ]->Scale(1./histos["Norm" + histonamesMC[i] ]->Integral());
    }

   TFile *fData = TFile::Open("PhotMETResolutionIncl2jkilllow_PhotonData.root");
   fData->cd();
   for(unsigned int i = 0; i<histonamesData.size();++i) histos[histonamesData[i] ] = (TH1F*)fData->Get(histonamesData[i].c_str());

    histos["PhotMET_2j0b_PhotonData"]->Add(histos["PhotMET_3j0b_PhotonData"]);
    histos["PhotMET_2j0b_PhotonData"]->Add(histos["PhotMET_ge4j0b_PhotonData"]);
    histos["PhotMET_2j0b_PhotonMC"]->Add(histos["PhotMET_3j0b_PhotonMC"]);
    histos["PhotMET_2j0b_PhotonMC"]->Add(histos["PhotMET_ge4j0b_PhotonMC"]);
    histos["PhotMET_2j0b_unwgt_PhotonData"]->Add(histos["PhotMET_3j0b_unwgt_PhotonData"]);
    histos["PhotMET_2j0b_unwgt_PhotonData"]->Add(histos["PhotMET_ge4j0b_unwgt_PhotonData"]);
    histos["PhotMET_2j0b_unwgt_PhotonMC"]->Add(histos["PhotMET_3j0b_unwgt_PhotonMC"]);
    histos["PhotMET_2j0b_unwgt_PhotonMC"]->Add(histos["PhotMET_ge4j0b_unwgt_PhotonMC"]);
    
    for(unsigned int i = 0; i<histonamesData.size();++i) {
        histos["Norm" + histonamesData[i] ] = (TH1F*)histos[histonamesData[i] ]->Clone(("Norm" + histonamesData[i]).c_str());
        //histos["Norm" + histonamesData[i] ] = (TH1F*)fData->Get(histonamesData[i].c_str());
        //histos["Norm" + histonamesData[i] ]->SetName(("Norm" + histonamesData[i]).c_str());
        histos["Norm" + histonamesData[i] ]->Scale(1./histos["Norm" + histonamesData[i] ]->Integral());
    }
    
   histos["PhotMET_2j0b_DataVsMC"] = (TH1F*)histos["PhotMET_2j0b_PhotonData"]->Clone("PhotMET_2j0b_DataVsMC");
    histos["PhotMET_2j0b_DataVsMC"]->Divide(histos["PhotMET_2j0b_PhotonMC"]);
    histos["PhotMET_2j0b_unwgt_DataVsMC"] = (TH1F*)histos["PhotMET_2j0b_unwgt_PhotonData"]->Clone("PhotMET_2j0b_unwgt_DataVsMC");
    histos["PhotMET_2j0b_unwgt_DataVsMC"]->Divide(histos["PhotMET_2j0b_unwgt_PhotonMC"]);
    histos["PhotMET_2j0b_wgtVsunwgt_Data"] = (TH1F*)histos["PhotMET_2j0b_PhotonData"]->Clone("PhotMET_2j0b_wgtVsunwgt_Data");
    histos["PhotMET_2j0b_wgtVsunwgt_Data"]->Divide(histos["PhotMET_2j0b_unwgt_PhotonData"]);
    histos["PhotMET_2j0b_wgtVsunwgt_MC"] = (TH1F*)histos["PhotMET_2j0b_PhotonMC"]->Clone("PhotMET_2j0b_wgtVsunwgt_MC");
    histos["PhotMET_2j0b_wgtVsunwgt_MC"]->Divide(histos["PhotMET_2j0b_unwgt_PhotonMC"]);
    
   histos["NormPhotMET_2j0b_DataVsMC"] = (TH1F*)histos["NormPhotMET_2j0b_PhotonData"]->Clone("NormPhotMET_2j0b_DataVsMC");
    histos["NormPhotMET_2j0b_DataVsMC"]->Divide(histos["NormPhotMET_2j0b_PhotonMC"]);
    histos["NormPhotMET_2j0b_unwgt_DataVsMC"] = (TH1F*)histos["NormPhotMET_2j0b_unwgt_PhotonData"]->Clone("NormPhotMET_2j0b_unwgt_DataVsMC");
    histos["NormPhotMET_2j0b_unwgt_DataVsMC"]->Divide(histos["NormPhotMET_2j0b_unwgt_PhotonMC"]);
    histos["NormPhotMET_2j0b_wgtVsunwgt_Data"] = (TH1F*)histos["NormPhotMET_2j0b_PhotonData"]->Clone("NormPhotMET_2j0b_wgtVsunwgt_Data");
    histos["NormPhotMET_2j0b_wgtVsunwgt_Data"]->Divide(histos["NormPhotMET_2j0b_unwgt_PhotonData"]);
    histos["NormPhotMET_2j0b_wgtVsunwgt_MC"] = (TH1F*)histos["NormPhotMET_2j0b_PhotonMC"]->Clone("NormPhotMET_2j0b_wgtVsunwgt_MC");
    histos["NormPhotMET_2j0b_wgtVsunwgt_MC"]->Divide(histos["NormPhotMET_2j0b_unwgt_PhotonMC"]);
    cout << __LINE__ << endl;

    
   TFile *f = new TFile("PhotMETResolutionForPAS.root","RECREATE");
   for(map<string,TH1F*>::iterator h=    histos.begin(); h!=    histos.end();++h) h->second->Write();
   f->Close();
   cout << "Saved histos in " << f->GetName() << endl;
   delete f;
}

void MakeMETResolutionPlots(bool fit=false){
    
    map<string, TH1F*> histos;
    vector<string> histonames; histonames.clear();
    histonames.push_back("PhotMET_2j0b_PhotonMC");
    histonames.push_back("PhotMET_2j0b_unwgt_PhotonMC");
    histonames.push_back("PhotMET_2j0b_PhotonData");
    histonames.push_back("PhotMET_2j0b_unwgt_PhotonData");
    histonames.push_back("PhotMET_2j0b_DataVsMC");
    histonames.push_back("PhotMET_2j0b_unwgt_DataVsMC");
    histonames.push_back("PhotMET_2j0b_wgtVsunwgt_MC");
    
    vector<string> dataMCname; dataMCname.clear();
    dataMCname.push_back("PhotMET_2j0b");
    vector<string> legaddedname; legaddedname.clear();
    legaddedname.push_back("#geq2 jets, 0 b-jets");
    
    TFile *f = TFile::Open("PhotMETResolutionForPAS.root");//Killlow New
    f->cd();
    for(unsigned int i = 0; i<histonames.size();++i) histos[histonames[i] ] = (TH1F*)f->Get(histonames[i].c_str());
    for(unsigned int i = 0; i<histonames.size();++i) histos["Norm"+histonames[i] ] = (TH1F*)f->Get(("Norm"+histonames[i]).c_str());
    TCanvas *c1 = new TCanvas("c1", "",250,250,600,750);
    c1->cd();
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    c1->Range(0,0,1,1);
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
    
    TFile *ftemp = new TFile("htemp.root","recreate");
 
    
    c1->cd();

    
    vector<string> firsth, secondh, ratioh, typeh, leg1h, leg2h, selh;
    vector<bool> norm;
    //data vs MC wgt
    for(unsigned int i = 0; i<dataMCname.size(); ++i){
        firsth.push_back(dataMCname[i] +"_PhotonMC"); leg1h.push_back("Simulation");
        secondh.push_back(dataMCname[i] +"_PhotonData"); leg2h.push_back("Data");
        ratioh.push_back(dataMCname[i] +"_DataVsMC");
        selh.push_back(legaddedname[i]);
        typeh.push_back("reweighted to W+jets #nu-p_{T}");
        norm.push_back(false);
    }
    //data vs MC unwgt
    for(unsigned int i = 0; i<dataMCname.size(); ++i){
        firsth.push_back(dataMCname[i] +"_unwgt_PhotonMC"); leg1h.push_back("Simulation");
        secondh.push_back(dataMCname[i] +"_unwgt_PhotonData"); leg2h.push_back("Data");
        ratioh.push_back(dataMCname[i] +"_unwgt_DataVsMC");
        selh.push_back(legaddedname[i]);
        typeh.push_back("not reweighted to W+jets #nu-p_{T}");
        norm.push_back(false);
    }
    /*
    //data wgt vs unwgt
    for(unsigned int i = 0; i<dataMCname.size(); ++i){
        firsth.push_back(dataMCname[i] +"_PhotonData"); leg1h.push_back("Reweighted");
        secondh.push_back(dataMCname[i] +"_unwgt_PhotonData"); leg2h.push_back("Unweighted");
        ratioh.push_back(dataMCname[i] +"_wgtVsunwgt_Data");
        selh.push_back(legaddedname[i]);
        typeh.push_back("Data");
        norm.push_back(false);
    }
    //MC wgt vs unwgt
    for(unsigned int i = 0; i<dataMCname.size(); ++i){
        firsth.push_back(dataMCname[i] +"_PhotonMC"); leg1h.push_back("Reweighted");
        secondh.push_back(dataMCname[i] +"_unwgt_PhotonMC"); leg2h.push_back("Unweighted");
        ratioh.push_back(dataMCname[i] +"_wgtVsunwgt_MC");
        selh.push_back(legaddedname[i]);
        typeh.push_back("Simulation");
        norm.push_back(false);
    }
    */
    //get all normalized ones
    unsigned int initialfirsthsize =firsth.size();
    for(unsigned int i = 0; i<initialfirsthsize;++i){//can do so as it appends at the end
        firsth.push_back("Norm"+firsth[i]); leg1h.push_back(leg1h[i]);
        secondh.push_back("Norm"+secondh[i]); leg2h.push_back(leg2h[i]);
        ratioh.push_back("Norm"+ratioh[i]);
        selh.push_back(selh[i]); typeh.push_back(typeh[i]);
        norm.push_back(true);
    }

    //for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){ cout << h->first << " " << h->second->GetName() << endl; }
    TF1 *ff = new TF1("ff","[0]",250,750);
    TF1 *fe = new TF1("fe","[0]+x*[1]",250,750);
    fe->SetLineColor(kMagenta); fe->SetLineStyle(2);
    
    
    //for(unsigned int i = 0; i<1;++i){
    for(unsigned int i = 0; i<firsth.size();++i){
        cout << firsth[i] << ", " << secondh[i] << endl;
        float f1,f1e, e1, e1e, e2, e2e;
        if(fit){
            cout << "---  " << ratioh[i] << ":" << endl;
            histos[ratioh[i] ]->Fit(ff,"QR");
            histos[ratioh[i] ]->Fit(fe,"QR");
            cout << "Constant: chi2/ndof " << ff->GetChisquare()/ff->GetNDF() << ", Linear: chi2/ndof "  << fe->GetChisquare()/fe->GetNDF() << endl;
        }
        //cout << "  " << ratioh[i] << " " << histos[ratioh[i] ]->GetName() << endl;
        c1->cd();
        TPad *plotpad = new TPad("plotpad", "Pad containing the overlay plot",0,0.211838,1,1);
        plotpad->Draw();
        plotpad->cd();
        //plotpad->Range(-41.72231,-3.114222,275.3672,7.045847);
        plotpad->SetFillColor(0);
        plotpad->SetBorderMode(0);
        plotpad->SetBorderSize(2);
        plotpad->SetTickx(1);
        plotpad->SetTicky(1);
        //plotpad->SetLogy();
        plotpad->SetLeftMargin(0.18);
        plotpad->SetRightMargin(0.05);
        plotpad->SetTopMargin(0.07);
        plotpad->SetBottomMargin(0.15);
        plotpad->SetFrameFillStyle(0);
        plotpad->SetFrameBorderMode(0);
        plotpad->SetFrameFillStyle(0);
        plotpad->SetFrameBorderMode(0);
        plotpad->cd();
        float max = TMath::Max(histos[firsth[i] ]->GetMaximum(),histos[secondh[i] ]->GetMaximum());
        max *= 1.3;
        histos[firsth[i] ]->SetFillColor(kBlue);
        histos[firsth[i] ]->SetLineColor(kBlue);
        histos[firsth[i] ]->SetLineWidth(2);
        histos[firsth[i] ]->SetMarkerColor(kBlue);
        histos[firsth[i] ]->GetXaxis()->SetTitle("");//no title here
        histos[firsth[i] ]->GetXaxis()->SetLabelFont(42);
        histos[firsth[i] ]->GetXaxis()->SetLabelOffset(0.007);
        histos[firsth[i] ]->GetXaxis()->SetLabelSize(0.05);
        histos[firsth[i] ]->GetXaxis()->SetTitleSize(0.0);
        histos[firsth[i] ]->GetXaxis()->SetTitleOffset(0.9);
        histos[firsth[i] ]->GetXaxis()->SetTitleFont(42);
        histos[firsth[i] ]->GetYaxis()->SetTitle("Events / 25 GeV");
        if(norm[i]==true) histos[firsth[i] ]->GetYaxis()->SetTitle("a.u. / 25 GeV");
        histos[firsth[i] ]->GetYaxis()->SetLabelFont(42);
        histos[firsth[i] ]->GetYaxis()->SetLabelOffset(0.007);
        histos[firsth[i] ]->GetYaxis()->SetLabelSize(0.05);
        histos[firsth[i] ]->GetYaxis()->SetTitleSize(0.06);
        histos[firsth[i] ]->GetYaxis()->SetTitleOffset(1.25);
        histos[firsth[i] ]->GetYaxis()->SetTitleFont(42);
        histos[firsth[i] ]->GetZaxis()->SetLabelFont(42);
        histos[firsth[i] ]->GetZaxis()->SetLabelOffset(0.007);
        histos[firsth[i] ]->GetZaxis()->SetLabelSize(0.05);
        histos[firsth[i] ]->GetZaxis()->SetTitleSize(0.06);
        histos[firsth[i] ]->GetZaxis()->SetTitleFont(42);
        histos[firsth[i] ]->SetStats(0);
        histos[firsth[i] ]->SetMaximum(max);
        histos[secondh[i] ]->SetFillColor(kRed);
        histos[secondh[i] ]->SetLineColor(kRed);
        histos[secondh[i] ]->SetLineWidth(2);
        histos[secondh[i] ]->SetMarkerColor(kRed);
        histos[secondh[i] ]->GetXaxis()->SetTitle("");//no title here
        histos[secondh[i] ]->GetXaxis()->SetLabelFont(42);
        histos[secondh[i] ]->GetXaxis()->SetLabelOffset(0.007);
        histos[secondh[i] ]->GetXaxis()->SetLabelSize(0.05);
        histos[secondh[i] ]->GetXaxis()->SetTitleSize(0.0);
        histos[secondh[i] ]->GetXaxis()->SetTitleOffset(0.9);
        histos[secondh[i] ]->GetXaxis()->SetTitleFont(42);
        histos[secondh[i] ]->GetYaxis()->SetTitle("Events / 25 GeV");
        if(norm[i]==true) histos[secondh[i] ]->GetYaxis()->SetTitle("a.u. / 25 GeV");
        histos[secondh[i] ]->GetYaxis()->SetLabelFont(42);
        histos[secondh[i] ]->GetYaxis()->SetLabelOffset(0.007);
        histos[secondh[i] ]->GetYaxis()->SetLabelSize(0.05);
        histos[secondh[i] ]->GetYaxis()->SetTitleSize(0.06);
        histos[secondh[i] ]->GetYaxis()->SetTitleOffset(1.25);
        histos[secondh[i] ]->GetYaxis()->SetTitleFont(42);
        histos[secondh[i] ]->GetZaxis()->SetLabelFont(42);
        histos[secondh[i] ]->GetZaxis()->SetLabelOffset(0.007);
        histos[secondh[i] ]->GetZaxis()->SetLabelSize(0.05);
        histos[secondh[i] ]->GetZaxis()->SetTitleSize(0.06);
        histos[secondh[i] ]->GetZaxis()->SetTitleFont(42);
        histos[secondh[i] ]->SetStats(0);
        histos[secondh[i] ]->SetMaximum(max);
        histos[firsth[i] ]->Draw("E1");
        histos[secondh[i] ]->Draw("sameE1");
        //cout << __LINE__ << endl;
        TLegend *leg = new TLegend(0.368,0.775,0.7,0.9,NULL,"brNDC");
        leg->SetBorderSize(0);  leg->SetTextSize(0.042);    leg->SetTextFont(42);   leg->SetLineColor(1);
        leg->SetLineStyle(1);   leg->SetLineWidth(2);   leg->SetFillColor(0);   leg->SetFillStyle(1001);
        leg->AddEntry(histos[firsth[i] ], leg1h[i].c_str(), "lep");
        leg->AddEntry(histos[secondh[i] ], leg2h[i].c_str(), "lep");
        leg->Draw();
        TLatex *tex1 = new TLatex(0.45,0.725,selh[i].c_str());
        tex1->SetNDC();  tex1->SetTextAlign(11);
        tex1->SetTextFont(42);   tex1->SetTextSize(0.0385); tex1->SetLineWidth(2);
        tex1->Draw();
        TLatex *tex2 = new TLatex(0.45,0.667,typeh[i].c_str());
        tex2->SetNDC();  tex2->SetTextAlign(11);
        tex2->SetTextFont(42);   tex2->SetTextSize(0.0385);   tex2->SetLineWidth(2);
        tex2->Draw();
        string sqrts = "2.11 fb^{-1} (13 TeV)";
        if(norm[i]==true) sqrts = "(13 TeV)";
        TLatex *tex3 = new TLatex(0.95,0.944,sqrts.c_str());
        tex3->SetNDC();  tex3->SetTextAlign(31);
        tex3->SetTextFont(42);   tex3->SetTextSize(0.042);    tex3->SetLineWidth(2);
        tex3->Draw();
        TLatex *tex4 = new TLatex(0.21465,0.9027,"CMS");
        tex4->SetNDC();  tex4->SetTextAlign(13);
        tex4->SetTextFont(61);   tex4->SetTextSize(0.0525);   tex4->SetLineWidth(2);
        tex4->Draw();
        TLatex *tex5 = new TLatex(0.21465,0.8397,"Private");
        tex5->SetNDC();  tex5->SetTextAlign(13);
        tex5->SetTextFont(52);   tex5->SetTextSize(0.0399);   tex5->SetLineWidth(2);
        tex5->Draw();
        //plotpad->Modified();
        TLatex *texf = new TLatex();
        texf->SetNDC();  texf->SetTextAlign(11); texf->SetTextColor(kOrange+1);
        texf->SetTextFont(42);   texf->SetTextSize(0.035);   texf->SetLineWidth(2);
        TLatex *texe = new TLatex();
        texe->SetNDC();  texe->SetTextAlign(11); texe->SetTextColor(kMagenta);
        texe->SetTextFont(42);   texe->SetTextSize(0.035);   texe->SetLineWidth(2);
        if(fit){
            texf->DrawLatex(0.45,0.575,"Constant fit:");
            std::ostringstream ss;
            ss << fixed << setprecision(2) << "c = " << ff->GetParameter(0) << " #pm " << ff->GetParError(0);
            std::string s(ss.str());
            texf->DrawLatex(0.625,0.575,s.c_str());
            texe->DrawLatex(0.45,0.525,"Linear fit:");
            std::ostringstream ss1, ss2;
            ss1 << fixed << setprecision(2) << "c = " << fe->GetParameter(0) << " #pm " << fe->GetParError(0);
            ss2 << fixed << setprecision(2) << "m = " << fe->GetParameter(1)*10000. << " #pm " << fe->GetParError(1)*10000. << " #times10^{-4}";
            std::string s1(ss1.str());
            texe->DrawLatex(0.59,0.525,s1.c_str());
            std::string s2(ss2.str());
            texe->DrawLatex(0.59,0.485,s2.c_str());
        }
        
        c1->cd();
        TPad *ratiopad = new TPad("ratiopad", "Pad containing the ratio",0,0.,1.,0.2889441);
        ratiopad->Draw();
        ratiopad->cd();
        //ratiopad->Range(-42.2271,-0.8571431,273.6941,2.214286);
        ratiopad->SetFillColor(0);
        ratiopad->SetBorderMode(0);
        ratiopad->SetBorderSize(2);
        ratiopad->SetTickx(1);
        ratiopad->SetTicky(1);
        ratiopad->SetLeftMargin(0.18);
        ratiopad->SetRightMargin(0.05);
        ratiopad->SetTopMargin(0.07);
        ratiopad->SetBottomMargin(0.28);
        ratiopad->SetFrameFillStyle(0);
        ratiopad->SetFrameBorderMode(0);
        ratiopad->SetFrameFillStyle(0);
        ratiopad->SetFrameBorderMode(0);
        ratiopad->cd();
        TString temp = typeh[i];
        double xbins[6] = {150,200,250,350,450,750};
        //double xbins[4] = {250,350,450,750};
        //TH1F *hfirst = (TH1F*)histos[firsth[i] ]->Clone("hfirst");
        //TH1F *hsecond = (TH1F*)histos[secondh[i] ]->Clone("hsecond");
        TH1F *hfirst;
        //hfirst->Draw();
        TH1F *hsecond;
        if(temp.Contains("Data")||temp.Contains("Simulation")){
            hsecond = (TH1F*)histos[secondh[i] ]->Rebin(5,"hfirst",xbins);
            hfirst = (TH1F*)histos[firsth[i] ]->Rebin(5,"hsecond",xbins);
            //hsecond = (TH1F*)histos[secondh[i] ]->Rebin(3,"hfirst",xbins);
            //hfirst = (TH1F*)histos[firsth[i] ]->Rebin(3,"hsecond",xbins);
            cout << "hsecond is rebinned " << secondh[i] << " hfirst is rebinned " << firsth[i] << endl;
            cout << "all is fine hsecond belongs to secondh[i], hfirst belongs to secondh[i] " << endl;

        } else {
            hsecond = (TH1F*)histos[firsth[i] ]->Rebin(5,"hsecond",xbins);
            hfirst = (TH1F*)histos[secondh[i] ]->Rebin(5,"hfirst",xbins);
            //hsecond = (TH1F*)histos[firsth[i] ]->Rebin(3,"hsecond",xbins);
            //hfirst = (TH1F*)histos[secondh[i] ]->Rebin(3,"hfirst",xbins);
            cout << "hsecond is rebinned " << secondh[i] << " hfirst is rebinned " << firsth[i] << endl;
           float binyield1, otherbinyield1, binerror1, otherbinerror1;
            float ratio1, ratioerr1;
            float binyield2, otherbinyield2, binerror2, otherbinerror2;
            float ratio2, ratioerr2;
            float rr, rrerr;
            float rr2, rrerr2;

            cout << "careful hsecond belongs to firsth[i], hfirst belongs to secondh[i] " << endl;

            binyield1 = hfirst->GetBinContent(3); otherbinyield1 = hfirst->GetBinContent(4)+hfirst->GetBinContent(5);
            binyield2 = hsecond->GetBinContent(3); otherbinyield2 = hsecond->GetBinContent(4)+hsecond->GetBinContent(5);
            binerror1 = hfirst->GetBinError(3); otherbinerror1 = sqrt(pow(hfirst->GetBinError(4),2)+pow(hfirst->GetBinError(5),2));
            binerror2 = hsecond->GetBinError(3); otherbinerror2 = sqrt(pow(hsecond->GetBinError(4),2)+pow(hsecond->GetBinError(5),2));
            ratio1 = binyield1/(binyield1+otherbinyield1); ratioerr1 = sqrt(pow(otherbinyield1*binerror1/pow(binyield1+otherbinyield1,2),2) + pow(otherbinerror1*binyield1/pow(binyield1+otherbinyield1,2),2) );
            ratio2 = binyield2/(binyield2+otherbinyield2); ratioerr2 = sqrt(pow(otherbinyield2*binerror2/pow(binyield2+otherbinyield2,2),2) + pow(otherbinerror2*binyield2/pow(binyield2+otherbinyield2,2),2) );
            cout << "ratio 1 is from hfirst, ratio2 is from hsecond" << ": ";
            cout << "ratio1 = " << binyield1 << "/" <<(binyield1+otherbinyield1) << ", ";
            cout << "ratio2 = " << binyield2 << "/" <<(binyield2+otherbinyield2) << endl;
            rr =ratio1/ratio2; rrerr = sqrt(pow(ratio1*ratioerr2/pow(ratio2,2),2)+pow(ratioerr1/ratio2,2));
            rr2 =ratio2/ratio1; rrerr2 = sqrt(pow(ratio2*ratioerr1/pow(ratio1,2),2)+pow(ratioerr2/ratio1,2));
            cout <<secondh[i] << "/" << firsth[i] << ": " << "bin(" << xbins[2] << "-" << xbins[3] << ")/total rat " << ratio1 << "/" <<ratio2 << " = " << rr << " +/- " << rrerr << endl;
            cout <<firsth[i] << "/" << secondh[i] << ": " << "bin(" << xbins[2] << "-" << xbins[3] << ")/total rat " << ratio2 << "/" <<ratio1 << " = " << rr2 << " +/- " << rrerr2 << endl;
            
            binyield1 = hfirst->GetBinContent(4); otherbinyield1 = hfirst->GetBinContent(3)+hfirst->GetBinContent(5);
            binyield2 = hsecond->GetBinContent(4); otherbinyield2 = hsecond->GetBinContent(3)+hsecond->GetBinContent(5);
            binerror1 = hfirst->GetBinError(4); otherbinerror1 = sqrt(pow(hfirst->GetBinError(3),2)+pow(hfirst->GetBinError(5),2));
            binerror2 = hsecond->GetBinError(4); otherbinerror2 = sqrt(pow(hsecond->GetBinError(3),2)+pow(hsecond->GetBinError(5),2));
            ratio1 = binyield1/(binyield1+otherbinyield1); ratioerr1 = sqrt(pow(otherbinyield1*binerror1/pow(binyield1+otherbinyield1,2),2) + pow(otherbinerror1*binyield1/pow(binyield1+otherbinyield1,2),2) );
            ratio2 = binyield2/(binyield2+otherbinyield2); ratioerr2 = sqrt(pow(otherbinyield2*binerror2/pow(binyield2+otherbinyield2,2),2) + pow(otherbinerror2*binyield2/pow(binyield2+otherbinyield2,2),2) );
            rr =ratio1/ratio2; rrerr = sqrt(pow(ratio1*ratioerr2/pow(ratio2,2),2)+pow(ratioerr1/ratio2,2));
            rr2 =ratio2/ratio1; rrerr2 = sqrt(pow(ratio2*ratioerr1/pow(ratio1,2),2)+pow(ratioerr2/ratio1,2));
            cout <<secondh[i] << "/" << firsth[i] << ": " << "bin(" << xbins[3] << "-" << xbins[4] << ")/total rat " << ratio1 << "/" <<ratio2 << " = " << rr << " +/- " << rrerr << endl;
            cout <<firsth[i] << "/" << secondh[i] << ": " << "bin(" << xbins[3] << "-" << xbins[4] << ")/total rat " << ratio2 << "/" <<ratio1 << " = " << rr2 << " +/- " << rrerr2 << endl;

            binyield1 = hfirst->GetBinContent(5); otherbinyield1 = hfirst->GetBinContent(4)+hfirst->GetBinContent(3);
            binyield2 = hsecond->GetBinContent(5); otherbinyield2 = hsecond->GetBinContent(4)+hsecond->GetBinContent(3);
            binerror1 = hfirst->GetBinError(5); otherbinerror1 = sqrt(pow(hfirst->GetBinError(4),2)+pow(hfirst->GetBinError(3),2));
            binerror2 = hsecond->GetBinError(5); otherbinerror2 = sqrt(pow(hsecond->GetBinError(4),2)+pow(hsecond->GetBinError(3),2));
            ratio1 = binyield1/(binyield1+otherbinyield1); ratioerr1 = sqrt(pow(otherbinyield1*binerror1/pow(binyield1+otherbinyield1,2),2) + pow(otherbinerror1*binyield1/pow(binyield1+otherbinyield1,2),2) );
            ratio2 = binyield2/(binyield2+otherbinyield2); ratioerr2 = sqrt(pow(otherbinyield2*binerror2/pow(binyield2+otherbinyield2,2),2) + pow(otherbinerror2*binyield2/pow(binyield2+otherbinyield2,2),2) );
            rr =ratio1/ratio2; rrerr = sqrt(pow(ratio1*ratioerr2/pow(ratio2,2),2)+pow(ratioerr1/ratio2,2));
            rr2 =ratio2/ratio1; rrerr2 = sqrt(pow(ratio2*ratioerr1/pow(ratio1,2),2)+pow(ratioerr2/ratio1,2));
            cout <<secondh[i] << "/" << firsth[i] << ": " << "bin(" << xbins[4] << "-" << xbins[5] << ")/total rat " << ratio1 << "/" <<ratio2 << " = " << rr << " +/- " << rrerr << endl;
            cout <<firsth[i] << "/" << secondh[i] << ": " << "bin(" << xbins[4] << "-" << xbins[5] << ")/total rat " << ratio2 << "/" <<ratio1 << " = " << rr2 << " +/- " << rrerr2 << endl;
            
            otherbinyield1 = hfirst->GetBinContent(3); binyield1 = hfirst->GetBinContent(4)+hfirst->GetBinContent(5);
            otherbinyield2 = hsecond->GetBinContent(3); binyield2 = hsecond->GetBinContent(4)+hsecond->GetBinContent(5);
            otherbinerror1 = hfirst->GetBinError(3); binerror1 = sqrt(pow(hfirst->GetBinError(4),2)+pow(hfirst->GetBinError(5),2));
            otherbinerror2 = hsecond->GetBinError(3); binerror2 = sqrt(pow(hsecond->GetBinError(4),2)+pow(hsecond->GetBinError(5),2));
            ratio1 = binyield1/(binyield1+otherbinyield1); ratioerr1 = sqrt(pow(otherbinyield1*binerror1/pow(binyield1+otherbinyield1,2),2) + pow(otherbinerror1*binyield1/pow(binyield1+otherbinyield1,2),2) );
            ratio2 = binyield2/(binyield2+otherbinyield2); ratioerr2 = sqrt(pow(otherbinyield2*binerror2/pow(binyield2+otherbinyield2,2),2) + pow(otherbinerror2*binyield2/pow(binyield2+otherbinyield2,2),2) );
            //cout << "ratio 1 is from hfirst, ratio2 is from hsecond" << ": ";
            //cout << "ratio1 = " << binyield1 << "/" <<(binyield1+otherbinyield1) << ", ";
            //cout << "ratio2 = " << binyield2 << "/" <<(binyield2+otherbinyield2) << endl;
            rr =ratio1/ratio2; rrerr = sqrt(pow(ratio1*ratioerr2/pow(ratio2,2),2)+pow(ratioerr1/ratio2,2));
            rr2 =ratio2/ratio1; rrerr2 = sqrt(pow(ratio2*ratioerr1/pow(ratio1,2),2)+pow(ratioerr2/ratio1,2));
            cout <<secondh[i] << "/" << firsth[i] << ": " << "bin(" << xbins[3] << "-" << xbins[5] << ")/total rat " << ratio1 << "/" <<ratio2 << " = " << rr << " +/- " << rrerr << endl;
            cout <<firsth[i] << "/" << secondh[i] << ": " << "bin(" << xbins[3] << "-" << xbins[5] << ")/total rat " << ratio2 << "/" <<ratio1 << " = " << rr2 << " +/- " << rrerr2 << endl;


        }
        string nrat = "hratio"+ratioh[i];
        TH1F *hratio = (TH1F*)hfirst->Clone(nrat.c_str());
        //for(unsigned int i = 1; i<=hratio->GetNbinsX(); ++i) cout << i << " " << hratio->GetBinContent(i) << ", ";
        //cout << endl;
        hratio->Divide(hsecond);
        //cout << temp << " " << hratio->GetName() << endl;
        double singlesum(0),binnedsum(0);
        for(unsigned int j = 1; j<=histos[secondh[i] ]->GetNbinsX();++j){
            cout << secondh[i] << " bin " << j << " " << histos[secondh[i] ]->GetBinContent(j) << endl; singlesum +=histos[secondh[i] ]->GetBinContent(j);
            cout << firsth[i]  << " bin " << j << " " << histos[firsth[i]  ]->GetBinContent(j) << endl;
        }
        for(unsigned int k = 1; k<=hfirst->GetNbinsX();++k){
            cout << secondh[i] << " bin " << k << " " << hfirst->GetBinContent(k) << endl;binnedsum += hfirst->GetBinContent(k);
            cout << firsth[i]  << " bin " << k << " " << hsecond->GetBinContent(k) << endl;
            cout << "ratio"    << " bin " << k << " " << hratio->GetBinContent(k) << endl;
        }
        cout << "org " << singlesum << " rebinned " << binnedsum << endl;
        cout << hfirst->GetName() << " " << hsecond->GetName() << endl;
        cout << hratio->GetName() << endl;
        cout << ratioh[i] << endl;
        cout << histos.count(ratioh[i]) << endl;
        if(norm[i]&&temp.Contains("Data")) { cout << __LINE__ << endl; hratio->SetMinimum(0.75); hratio->SetMaximum(2); }
        else if(norm[i]&&temp.Contains("Simulation")) { cout << __LINE__ << endl; hratio->SetMinimum(0.75); hratio->SetMaximum(2); }
        else if(temp.Contains("Data")) { cout << __LINE__ << endl; hratio->SetMinimum(0.0); hratio->SetMaximum(1.3*histos[ratioh[i] ]->GetMaximum() ); }
        else if(temp.Contains("Simulation")) { cout << __LINE__ << endl; hratio->SetMinimum(0.0); hratio->SetMaximum(1.3*histos[ratioh[i] ]->GetMaximum() ); }
        else if(temp.Contains("not"))  { cout << __LINE__ << endl; hratio->SetMinimum(0.5); hratio->SetMaximum(1.5); }
        else { cout << __LINE__ << endl; hratio->SetMinimum(0.4); hratio->SetMaximum(1.5); }

        //hratio->SetEntries(4241.649);
        hratio->SetDirectory(0);
        hratio->SetStats(0);
        hratio->SetLineWidth(2);
        hratio->SetLineColor(1);
        hratio->SetMarkerColor(1);
        hratio->SetMarkerStyle(20);
        hratio->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss}| [GeV]");
        hratio->GetXaxis()->SetLabelFont(42);
        hratio->GetXaxis()->SetLabelSize(0);
        hratio->GetXaxis()->SetTitleSize(0.18);
        hratio->GetXaxis()->SetTickLength(0.09);
        hratio->GetXaxis()->SetTitleOffset(0.5 );
        hratio->GetXaxis()->SetTitleFont(42);
        hratio->GetYaxis()->SetTitle("ratio");
        hratio->GetYaxis()->SetNdivisions(505);
        hratio->GetYaxis()->SetLabelFont(42);
        hratio->GetYaxis()->SetLabelSize(0.16);
        hratio->GetYaxis()->SetTitleSize(0.18);
        hratio->GetYaxis()->SetTitleOffset(0.43);
        hratio->GetYaxis()->SetTitleFont(42);
        hratio->GetZaxis()->SetLabelFont(42);
        hratio->GetZaxis()->SetLabelSize(0.035);
        hratio->GetZaxis()->SetTitleSize(0.035);
        hratio->GetZaxis()->SetTitleFont(42);
        hratio->Draw("E");
        /*
        //cout << temp << " " << histos[ratioh[i] ]->GetName() << endl;
        if(norm[i]&&temp.Contains("Data")) { histos[ratioh[i] ]->SetMinimum(0.75); histos[ratioh[i] ]->SetMaximum(2); }
        else if(norm[i]&&temp.Contains("Simulation")) { histos[ratioh[i] ]->SetMinimum(0.75); histos[ratioh[i] ]->SetMaximum(2); }
        else if(temp.Contains("Data")) { histos[ratioh[i] ]->SetMinimum(0.0); histos[ratioh[i] ]->SetMaximum(1.3*histos[ratioh[i] ]->GetMaximum() ); }
        else if(temp.Contains("Simulation")) { histos[ratioh[i] ]->SetMinimum(0.0); histos[ratioh[i] ]->SetMaximum(1.3*histos[ratioh[i] ]->GetMaximum() ); }
        else if(temp.Contains("not"))  { histos[ratioh[i] ]->SetMinimum(0.5); histos[ratioh[i] ]->SetMaximum(1.5); }
        else { histos[ratioh[i] ]->SetMinimum(0.4); histos[ratioh[i] ]->SetMaximum(1.5); }
        //histos[ratioh[i] ]->SetEntries(4241.649);
        histos[ratioh[i] ]->SetDirectory(0);
        histos[ratioh[i] ]->SetStats(0);
        histos[ratioh[i] ]->SetLineWidth(2);
        histos[ratioh[i] ]->SetLineColor(1);
        histos[ratioh[i] ]->SetMarkerStyle(20);
        histos[ratioh[i] ]->GetXaxis()->SetTitle("|#gamma-#vec{p}_{T} + #vec{p}_{T}^{miss}| [GeV]");
        histos[ratioh[i] ]->GetXaxis()->SetLabelFont(42);
        histos[ratioh[i] ]->GetXaxis()->SetLabelSize(0);
        histos[ratioh[i] ]->GetXaxis()->SetTitleSize(0.18);
        histos[ratioh[i] ]->GetXaxis()->SetTickLength(0.09);
        histos[ratioh[i] ]->GetXaxis()->SetTitleOffset(0.5 );
        histos[ratioh[i] ]->GetXaxis()->SetTitleFont(42);
        histos[ratioh[i] ]->GetYaxis()->SetTitle("ratio");
        histos[ratioh[i] ]->GetYaxis()->SetNdivisions(505);
        histos[ratioh[i] ]->GetYaxis()->SetLabelFont(42);
        histos[ratioh[i] ]->GetYaxis()->SetLabelSize(0.16);
        histos[ratioh[i] ]->GetYaxis()->SetTitleSize(0.18);
        histos[ratioh[i] ]->GetYaxis()->SetTitleOffset(0.43);
        histos[ratioh[i] ]->GetYaxis()->SetTitleFont(42);
        histos[ratioh[i] ]->GetZaxis()->SetLabelFont(42);
        histos[ratioh[i] ]->GetZaxis()->SetLabelSize(0.035);
        histos[ratioh[i] ]->GetZaxis()->SetTitleSize(0.035);
        histos[ratioh[i] ]->GetZaxis()->SetTitleFont(42);
        histos[ratioh[i] ]->Draw("E");
        */
        TLine *line = new TLine(150,1,750,1);
        line->SetLineStyle(7);
        line->SetLineWidth(2);
        line->Draw();
        TLine *lineff = new TLine(250,1,750,1);
        lineff->SetLineStyle(1);
        lineff->SetLineWidth(2);
        lineff->SetLineColor(kOrange+1);
        TLine *linefe = new TLine(250,1,750,1);
        linefe->SetLineStyle(2);
        linefe->SetLineWidth(2);
        linefe->SetLineColor(kMagenta);
        if(fit){
            float par0 = ff->GetParameter(0);
            lineff->SetY1(par0);
            lineff->SetY2(par0);
            lineff->Draw();
            linefe->SetY1(fe->Eval(250.) );
            linefe->SetY2(fe->Eval(750.) );
            linefe->Draw();
            cout << hratio->GetName() << ": Linear fit " << par0 << "+/-" <<ff->GetParError(0) << ", bin(" << hratio->GetBinLowEdge(3) << "-" << hratio->GetBinLowEdge(4) << ") " << hratio->GetBinContent(3) << " ratio " << hratio->GetBinContent(3)/par0 << " +/- " << sqrt(pow(hratio->GetBinError(3)/par0,2)+pow(hratio->GetBinContent(3)*ff->GetParError(0)/(par0*par0),2)) << endl;
            cout << hratio->GetName() << ": Linear fit " << par0 << "+/-" <<ff->GetParError(0) << ", bin(" << hratio->GetBinLowEdge(4) << "-" << hratio->GetBinLowEdge(5) << ") " << hratio->GetBinContent(4) << " ratio " << hratio->GetBinContent(4)/par0 << " +/- " << sqrt(pow(hratio->GetBinError(4)/par0,2)+pow(hratio->GetBinContent(4)*ff->GetParError(0)/(par0*par0),2)) << endl;
            cout << hratio->GetName() << ": Linear fit " << par0 << "+/-" <<ff->GetParError(0) << ", bin(" << hratio->GetBinLowEdge(5) << "-" << hratio->GetBinLowEdge(6) << ") " << hratio->GetBinContent(5) << " ratio " << hratio->GetBinContent(5)/par0 << " +/- " << sqrt(pow(hratio->GetBinError(5)/par0,2)+pow(hratio->GetBinContent(5)*ff->GetParError(0)/(par0*par0),2)) << endl;
        }
        //ratiopad->Modified();
        c1->cd();
        c1->Modified();
        c1->cd();
        string savename = "forpas/" + ratioh[i] + "New.pdf";
        if(fit) savename = "forpas/fitted_" + ratioh[i] + "New.pdf";
        c1->SaveAs(savename.c_str() );//don't safe
        savename = "forpas/" + ratioh[i] + "New.root";
        if(fit) savename = "forpas/fitted_" + ratioh[i] + "New.C";
        c1->SaveAs(savename.c_str() );//don't safe
        plotpad->Clear();
        ratiopad->Clear();
        c1->Clear();
        delete line;
        delete lineff;
        delete leg;
        delete tex1;
        delete tex2;
        delete tex3;
        delete tex4;
        delete tex5;
        delete texf;
        delete texe;
        //cout << __LINE__ << endl;
        //delete ratiopad;//strange
        //delete plotpad;
        ftemp->cd();
        hratio->Write();
        hfirst->Write();
    }
    ftemp->Close();
    delete ff;
    delete fe;
    //delete c1;

}
