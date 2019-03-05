//#include <stdio.h>
#include "TFile.h"
#include "TLegend.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1D.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
//#include <stdlib.h>
#include <map>
#include <vector>
#include "TROOT.h"
using namespace std;
using namespace RooFit ;

void FitNBforWZvsTTZ(){
    
    std::ostringstream*  fLogStream = new std::ostringstream();

    int year = -1;
    bool reweighted = false;
    bool data = true;
    gStyle->SetOptStat(0);
    bool logy = false;
    map<string, TH1D*> h;
    map<string, TH1D*> rat;
    map<string, THStack*> stack;
    vector<string> histonames;
    vector<string> axisnames;
    //vector<Color_t> cols;
    vector<int> cols;
    vector<int> plottogether;
    vector<string> samples;
    vector<string> samplesleg;
    TFile *f;
    if(year==2016) f = TFile::Open("rootfiles/TTZNBfit_2016.root");
    if(year==2017) f = TFile::Open("rootfiles/TTZNBfit_2017.root");
    if(year==2018) f = TFile::Open("rootfiles/TTZNBfit_2018.root");
    if(year==  -1) f = TFile::Open("rootfiles/TTZNBfit_combined.root");
    if(reweighted) {
        if(year==2016) f = TFile::Open("rootfiles/TTZNBfit_2016_MCweighted.root");
        if(year==2017) f = TFile::Open("rootfiles/TTZNBfit_2017_MCweighted.root");
        if(year==2018) f = TFile::Open("rootfiles/TTZNBfit_2018_MCweighted.root");
        if(year==  -1) f = TFile::Open("rootfiles/TTZNBfit_combined_MCweighted.root");
        
    }
    vector<string> lsel, lname;
    lsel.push_back("");          lname.push_back("");
    lsel.push_back("_emutrig");  lname.push_back("| e#mu triggered");
    lsel.push_back("_etrig");    lname.push_back("| single-e triggered");
    lsel.push_back("_mutrig");   lname.push_back("| single-#mu triggered");
    
    vector<string> Zsel, Zname;
    Zsel.push_back("");          Zname.push_back("");
    Zsel.push_back("_leadlepZ"); Zname.push_back("| l1+l2=Z");
    vector<string> hsel, hname;
    hsel.push_back("NBJets_3goodlep");    hname.push_back("N_{B} | 3 good leptons");
    for(unsigned int i = 0; i<hname.size(); ++i){
        for(unsigned int j =0; j <Zsel.size(); ++j){
            for(unsigned int l =0; l <lsel.size(); ++l){
                histonames.push_back(hsel[i] + lsel[l] + Zsel[j]);
                axisnames.push_back(hname[i] + lname[l] + Zname[j]);
            }
        }
    }
    
    samples.push_back("WJets");         samplesleg.push_back("1#font[12]{l} not from top");
    samples.push_back("TT1l");          samplesleg.push_back("1#font[12]{l} from top");
    samples.push_back("LostLep");       samplesleg.push_back("Lost Lepton");

    samples.push_back("TTZ");       samplesleg.push_back("t#bar{t}Z");
    samples.push_back("WZ");       samplesleg.push_back("WZ");

    samples.push_back("bg");          samplesleg.push_back("background");
    
    int nsig = 0;
    //if(twosig) ++nsig;
    for(unsigned int n = 0; n<histonames.size();++n){
        string mapname = histonames[n] + "_Data";
        h[mapname ]=(TH1D*)f->Get(mapname.c_str());
        //cout << mapname << endl;
        //cout <<h[mapname ]->Integral() << endl;
        int countersbg = 0;
        for(unsigned int s = 0; s<samples.size()-1; ++s){
            mapname = histonames[n] + "_" + samples[s];
            h[mapname ]=(TH1D*)f->Get(mapname.c_str());
            if(samples[s]!="TTZ"&&samples[s]!="WZ"){
                if(countersbg==0) h[histonames[n] + "_bg" ]=(TH1D*)h[mapname]->Clone((histonames[n] + "_bg").c_str());
                else              h[histonames[n] + "_bg" ]->Add(h[mapname],1);
                ++countersbg;
            }
        }
    }
    
    //now do the fit
    for(unsigned int n = 0; n<histonames.size();++n){
        TH1D *httZ     = (TH1D*)h[histonames[n] + "_TTZ"   ]->Clone("httZ"  );
        TH1D *hWZ      = (TH1D*)h[histonames[n] + "_WZ"    ]->Clone("hWZ"   );
        TH1D *hZZ      = (TH1D*)h[histonames[n] + "_TT1l"  ]->Clone("hZZ"   );
        TH1D *hData    = (TH1D*)h[histonames[n] + "_Data"  ]->Clone("hData" );
        TH1D *hOther   = (TH1D*)h[histonames[n] + "_bg"    ]->Clone("hOther");
        //hWZ->Add(hZZ,1);
        httZ  ->SetLineWidth(3);   httZ->SetLineColor(kRed);     httZ->SetMarkerColor(kRed);     httZ->SetLineStyle(kDashed);
        hWZ   ->SetLineWidth(3);    hWZ->SetLineColor(kMagenta);  hWZ->SetMarkerColor(kMagenta);  hWZ->SetLineStyle(kDashed);
        hZZ   ->SetLineWidth(3);    hZZ->SetLineColor(kBlue);     hZZ->SetMarkerColor(kBlue);
        hOther->SetLineWidth(3); hOther->SetLineColor(kGreen); hOther->SetMarkerColor(kGreen); hOther->SetLineStyle(kDotted);
        hData ->SetLineWidth(1);  hData->SetLineColor(kBlack);  hData->SetMarkerColor(kBlack);  hData->SetMarkerStyle(20);

        RooRealVar nb("nb","nb",0.,4.) ; // contained in histos
        
        RooDataHist Data   ("data"  ,"data"  ,nb,hData) ;    // define RooDataHists
        RooDataHist WZ     ("WZ"    ,"WZ"    ,nb,hWZ);
        RooDataHist ttZ    ("ttZ"   ,"ttZ"   ,nb,httZ);
        RooDataHist Other  ("Other" ,"Other" ,nb,hOther);//check this!!!
        
        RooHistPdf WZ_pdf   ("WZ_pdf"     ,"WZ_pdf"     ,nb,WZ     ); // define PDFs for signal and bkg
        RooHistPdf ttZ_pdf  ("ttZ_pdf"    ,"ttZ_pdf"    ,nb,ttZ    );
        RooHistPdf Other_pdf("Other_pdf"  ,"other_pdf"  ,nb,Other  );
        
        RooRealVar nwz       ("nwz"    ,"number of WZ events",         hWZ->Integral()   ,  hWZ ->Integral()  *0.1, hWZ ->Integral()  *1.9);
        RooRealVar nttz      ("nttz"   ,"number of ttZ events",        httZ->Integral()  ,  httZ->Integral()  *0.1, httZ->Integral()  *1.9);
        RooRealVar nother    ("nother" ,"number of Other SM events",   hOther->Integral(),  hOther->Integral()*0.1, hOther->Integral()*1.9); //nother.setConstant(kTRUE);
        //RooRealVar nother    ("nother" ,"number of Other SM events",   hOther->Integral(),  hOther->Integral()*0.6, hOther->Integral()*0.9); //nother.setConstant(kTRUE);
        //RooRealVar nother    ("nother" ,"number of Other SM events",   hOther->Integral(),  hOther->Integral()*0.99, hOther->Integral()*1.01); //nother.setConstant(kTRUE);
        
        // model(x) = nsig*Photons_pdf(x) + nqcd*QCD_pdf(x) + nother*Other_pdf(x), where nother is fixed to nominal contribution
        RooAddPdf model("model","model", RooArgList(WZ_pdf,ttZ_pdf,Other_pdf), RooArgList(nwz, nttz, nother));
        *fLogStream <<"\n**************************************************************************************************\n"
        <<"Starting to extract NB Normalization for " << histonames[n] << ".....\n";
        model.defaultPrintStream(fLogStream);
        
        // perform fit
        RooFitResult* fitres = model.fitTo(Data,SumW2Error(kFALSE),Extended(), Save(kTRUE));
        // if I'm not mistaken: SumW2==false is the right option, as mc-histos already contain proper weights.
        // SumW2Error == true would be needed if input comes from a TTree with (observable, weight) for each entry.
        // then, data.setWeightVar(y) would also be needed.
        
        // make plot
        TCanvas* canv = new TCanvas(("c" + histonames[n]).c_str(),"", 0, 0, 500, 500 );
        RooPlot* frame = nb.frame();
        Data.plotOn(frame, Name("Data")) ;
        model.plotOn(frame,Components(RooArgSet(WZ_pdf,ttZ_pdf,Other_pdf)), Name("Model"));
        model.plotOn(frame,Components(WZ_pdf),        LineStyle(kDashed), LineColor(kMagenta));
        model.plotOn(frame,Components(ttZ_pdf),       LineStyle(kDashed), LineColor(kRed));
        model.plotOn(frame,Components(Other_pdf),     LineStyle(kDotted), LineColor(kGreen));
        std::ostringstream* ssWZ    = new std::ostringstream();
        std::ostringstream* ssttZ   = new std::ostringstream();
        std::ostringstream* ssOther = new std::ostringstream();
        *ssWZ    << fixed << setprecision(2) << "WZ (" <<    nwz.getVal()/   hWZ->Integral() << " #pm " <<    nwz.getError()/   hWZ->Integral() << ")";
        *ssttZ   << fixed << setprecision(2) << "ttZ ("   <<   nttz.getVal()/  httZ->Integral() << " +/- " <<   nttz.getError()/  httZ->Integral() << ")";
        *ssOther << fixed << setprecision(2) << "Other (" << nother.getVal()/hOther->Integral() << " +/- " << nother.getError()/hOther->Integral() << ")";
        TLegend *leg = new TLegend(0.5,0.67,0.85,0.89,NULL,"brNDC");
        leg->SetBorderSize(0);
        leg->SetTextSize(0.035);
        leg->SetLineColor(1);
        leg->SetLineStyle(1);
        leg->SetLineWidth(2);
        leg->SetFillColor(0);
        leg->SetFillStyle(1001);
        leg->SetName("legend");
        leg->AddEntry(hData,                 "Data", "EP");
        leg->AddEntry(hZZ,         "Simulation sum", "L");
        leg->AddEntry(hWZ,      ssWZ->str().c_str(), "L");
        leg->AddEntry(httZ,    ssttZ->str().c_str(), "L");
        leg->AddEntry(hOther,ssOther->str().c_str(), "L");
        leg->Draw();
        frame->Draw();
        canv->Update();
        Double_t chi2 = frame->chiSquare("Model", "Data", 3);
        *fLogStream << "-----------------------------------------------------------------" << endl;
        *fLogStream << "Fit result for: " << histonames[n]                                 << endl;
        fitres->Print("v");
        *fLogStream << "ChiSquare of fit: " << chi2                                        << endl;
        *fLogStream << "-----------------------------------------------------------------" << endl;
        
        double err;
        *fLogStream << "WZ    value = " <<    nwz.getVal() << " +/- " <<    nwz.getError() << ", WZ    SF = " <<    nwz.getVal()/   hWZ->Integral() << " +/- " <<    nwz.getError()/   hWZ->Integral() << endl;
        *fLogStream << "ttZ   value = " <<   nttz.getVal() << " +/- " <<   nttz.getError() << ", ttZ   SF = " <<   nttz.getVal()/  httZ->Integral() << " +/- " <<   nttz.getError()/  httZ->Integral() << endl;
        *fLogStream << "Other value = " << nother.getVal() << " +/- " << nother.getError() << ", Other SF = " << nother.getVal()/hOther->Integral() << " +/- " << nother.getError()/hOther->Integral() << endl;
        *fLogStream << "Data  value = " << hData->IntegralAndError(1,hData->GetNbinsX(),err) << " +/- " << err << endl;
        
        // save RooFit output:
        TString filename;
        if(year==2016) filename ="rootfiles/NBttZfits/NBfit_" + histonames[n] + "_2016.root";
        if(year==2017) filename ="rootfiles/NBttZfits/NBfit_" + histonames[n] + "_2017.root";
        if(year==2018) filename ="rootfiles/NBttZfits/NBfit_" + histonames[n] + "_2018.root";
        if(year==  -1) filename ="rootfiles/NBttZfits/NBfit_" + histonames[n] + "_combined.root";
        if(reweighted){
            if(year==2016) filename ="rootfiles/NBttZfits/MCreweighted/NBfit_" + histonames[n] + "_2016.root";
            if(year==2017) filename ="rootfiles/NBttZfits/MCreweighted/NBfit_" + histonames[n] + "_2017.root";
            if(year==2018) filename ="rootfiles/NBttZfits/MCreweighted/NBfit_" + histonames[n] + "_2018.root";
            if(year==  -1) filename ="rootfiles/NBttZfits/MCreweighted/NBfit_" + histonames[n] + "_combined.root";
            
        }
        TFile *file = new TFile(filename.Data(), "recreate");
        fitres->Write();
        frame->Write();
        leg->Write();
        canv->Write();
        file->Close();
        delete file;
        delete leg;
        delete canv;
        delete fitres;
        delete ssWZ;
        delete ssttZ;
        delete ssOther;
    }
    cout << fLogStream->str();
}
