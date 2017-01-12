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
#include "TColor.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLine.h"
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



void GetCutflowSignalTable(){
    
    cout << __LINE__<<endl;
    TFile *f = TFile::Open("CutflowSignal.root");
    cout << __LINE__<<endl;
    TH1F *ttbar1l = (TH1F*)f->Get("Cutflow_TTbar1l");
    TH1F *ttbar2l = (TH1F*)f->Get("Cutflow_TTbar2l");
    TH1F *tW = (TH1F*)f->Get("Cutflow_tW");
    TH1F *WJets = (TH1F*)f->Get("Cutflow_WJets");
    TH1F *rare = (TH1F*)f->Get("Cutflow_Rare");
    cout << __LINE__<<endl;
    
    TH1F *bg = (TH1F*)ttbar1l->Clone("Cutflow_Bg");
    bg->Add(ttbar2l);
    bg->Add(tW);
    bg->Add(WJets);
    bg->Add(rare);
    cout << __LINE__<< " " << bg->Integral() << endl;
    
    TH1F *T2tt275 = (TH1F*)f->Get("Cutflow_T2tt_275_100");
    TH1F *T2tt300 = (TH1F*)f->Get("Cutflow_T2tt_300_200");
    TH1F *T2tt600 = (TH1F*)f->Get("Cutflow_T2tt_600_250");
    TH1F *T2tt700 = (TH1F*)f->Get("Cutflow_T2tt_700_50");
    TH1F *T2bW300 = (TH1F*)f->Get("Cutflow_T2bW_300_150");
    TH1F *T2bW500 = (TH1F*)f->Get("Cutflow_T2bW_500_200");
    TH1F *T2bW600 = (TH1F*)f->Get("Cutflow_T2bW_600_50");
    cout << __LINE__<<endl;
    //cout << __LINE__<< " " << T2tt275->Integral() << endl;//<< " " << T2tt300->Integral()<< " " << T2tt600->Integral()<< " " << T2tt700->Integral()<< " " << bg->Integral() << endl;
    //cout << __LINE__<< " " << T2tt275->Integral()<< " " << T2bW300->Integral()<< " " << T2bW500->Integral()<< " " << T2bW600->Integral()<< " " << bg->Integral() << endl;

    
    std::ostringstream* fLogStream = new std::ostringstream();
    cout << __LINE__<<endl;
    
    *fLogStream << "*********************************************************************" << endl;
    *fLogStream << "\%BEGINLATEX\%"             << endl;
    *fLogStream << "\\begin{table}[htb]"        << endl
    << "\\begin{center}"            << endl;
     *fLogStream << "\\tiny"                    << endl;
    *fLogStream << "\\caption{\\label{tab:cutflow} Cutflow for total background and selected signals for 2.3 fb$^{-1}$. All yields are directly taken from simulation and no data/simulation corrections are applied. Uncertainty is only statistical.}" << endl;
    *fLogStream << "\\begin{tabular}{|l|c|cccc|ccc|}" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << "Selection & background & \\multicolumn{4}{c|}{$M_{\\PSQt} - M_{\\PSGczDo}$ [GeV] for $\\PSQt\\to t\\PSGczDo$} & \\multicolumn{3}{c|}{$M_{\\PSQt} - M_{\\PSGczDo}$ [GeV] for $\\PSQt\\to b\\PSGcpmDo$} \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << " & & 275--100 & 300--200 & 600--250 & 700--50 & 300--150 & 500--200 & 600--50 \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    //cout << __LINE__<<endl;
    *fLogStream << "$\\geq2$ jets, $\\MET>250\\GeV$, $\\MT>50\\GeV$ & $" << fixed << setprecision(0) << bg->GetBinContent(1) << "\\pm" << bg->GetBinError(1)
   //     << "$ & $" << T2tt275->GetBinContent(1) << "\\pm" << T2tt275->GetBinError(1)
        << "$ & $" << T2tt300->GetBinContent(1) << "\\pm" << T2tt300->GetBinError(1)
    //    << "$ & $" << T2tt600->GetBinContent(1) << "\\pm" << T2tt600->GetBinError(1)
        << "$ & $" << T2tt700->GetBinContent(1) << "\\pm" << T2tt700->GetBinError(1)
        << "$ & $" << T2bW300->GetBinContent(1) << "\\pm" << T2bW300->GetBinError(1)
  //      << "$ & $" << T2bW500->GetBinContent(1) << "\\pm" << T2bW500->GetBinError(1)
        << "$ & $" << T2bW600->GetBinContent(1) << "\\pm" << T2bW600->GetBinError(1)
        << "$ \\\\" << endl;
    //cout << __LINE__<<endl;
    *fLogStream << "$+$ $\\MT>150\\GeV$ & $" << fixed << setprecision(1) << bg->GetBinContent(2) << "\\pm" << bg->GetBinError(2)
 //   << "$ & $" << T2tt275->GetBinContent(2) << "\\pm" << T2tt275->GetBinError(2)
    << "$ & $" << T2tt300->GetBinContent(2) << "\\pm" << T2tt300->GetBinError(2)
 //   << "$ & $" << T2tt600->GetBinContent(2) << "\\pm" << T2tt600->GetBinError(2)
    << "$ & $" << T2tt700->GetBinContent(2) << "\\pm" << T2tt700->GetBinError(2)
    << "$ & $" << T2bW300->GetBinContent(2) << "\\pm" << T2bW300->GetBinError(2)
 //   << "$ & $" << T2bW500->GetBinContent(2) << "\\pm" << T2bW500->GetBinError(2)
    << "$ & $" << T2bW600->GetBinContent(2) << "\\pm" << T2bW600->GetBinError(2)
    << "$ \\\\" << endl;
    
    *fLogStream << "$+$ $\\geq 1$ b-tagged jet & $" << fixed << setprecision(1) << bg->GetBinContent(3) << "\\pm" << bg->GetBinError(3)
//    << "$ & $" << T2tt275->GetBinContent(3) << "\\pm" << T2tt275->GetBinError(3)
    << "$ & $" << T2tt300->GetBinContent(3) << "\\pm" << T2tt300->GetBinError(3)
//    << "$ & $" << T2tt600->GetBinContent(3) << "\\pm" << T2tt600->GetBinError(3)
    << "$ & $" << T2tt700->GetBinContent(3) << "\\pm" << T2tt700->GetBinError(3)
    << "$ & $" << T2bW300->GetBinContent(3) << "\\pm" << T2bW300->GetBinError(3)
//    << "$ & $" << T2bW500->GetBinContent(3) << "\\pm" << T2bW500->GetBinError(3)
    << "$ & $" << T2bW600->GetBinContent(3) << "\\pm" << T2bW600->GetBinError(3)
    << "$ \\\\" << endl;
    
    *fLogStream << "$+$ $\\MET>250\\GeV$ & $" << fixed << setprecision(2) << bg->GetBinContent(4) << "\\pm" << bg->GetBinError(4)
//    << "$ & $" << T2tt275->GetBinContent(4) << "\\pm" << T2tt275->GetBinError(4)
    << "$ & $" << T2tt300->GetBinContent(4) << "\\pm" << T2tt300->GetBinError(4)
//    << "$ & $" << T2tt600->GetBinContent(4) << "\\pm" << T2tt600->GetBinError(4)
    << "$ & $" << T2tt700->GetBinContent(4) << "\\pm" << T2tt700->GetBinError(4)
    << "$ & $" << T2bW300->GetBinContent(4) << "\\pm" << T2bW300->GetBinError(4)
//    << "$ & $" << T2bW500->GetBinContent(4) << "\\pm" << T2bW500->GetBinError(4)
    << "$ & $" << T2bW600->GetBinContent(4) << "\\pm" << T2bW600->GetBinError(4)
    << "$ \\\\" << endl;
    
    *fLogStream << "$+$ no additional veto-lepton & $" << fixed << setprecision(2) << bg->GetBinContent(5) << "\\pm" << bg->GetBinError(5)
//    << "$ & $" << T2tt275->GetBinContent(5) << "\\pm" << T2tt275->GetBinError(5)
    << "$ & $" << T2tt300->GetBinContent(5) << "\\pm" << T2tt300->GetBinError(5)
//    << "$ & $" << T2tt600->GetBinContent(5) << "\\pm" << T2tt600->GetBinError(5)
    << "$ & $" << T2tt700->GetBinContent(5) << "\\pm" << T2tt700->GetBinError(5)
    << "$ & $" << T2bW300->GetBinContent(5) << "\\pm" << T2bW300->GetBinError(5)
//    << "$ & $" << T2bW500->GetBinContent(5) << "\\pm" << T2bW500->GetBinError(5)
    << "$ & $" << T2bW600->GetBinContent(5) << "\\pm" << T2bW600->GetBinError(5)
    << "$ \\\\" << endl;
    
    *fLogStream << "$+$ tau and $\\tau_\\text{h}$ veto & $" << fixed << setprecision(2) << bg->GetBinContent(6) << "\\pm" << bg->GetBinError(6)
//    << "$ & $" << T2tt275->GetBinContent(6) << "\\pm" << T2tt275->GetBinError(6)
    << "$ & $" << T2tt300->GetBinContent(6) << "\\pm" << T2tt300->GetBinError(6)
//    << "$ & $" << T2tt600->GetBinContent(6) << "\\pm" << T2tt600->GetBinError(6)
    << "$ & $" << T2tt700->GetBinContent(6) << "\\pm" << T2tt700->GetBinError(6)
    << "$ & $" << T2bW300->GetBinContent(6) << "\\pm" << T2bW300->GetBinError(6)
//    << "$ & $" << T2bW500->GetBinContent(6) << "\\pm" << T2bW500->GetBinError(6)
    << "$ & $" << T2bW600->GetBinContent(6) << "\\pm" << T2bW600->GetBinError(6)
    << "$ \\\\" << endl;
    
    *fLogStream << "$+$ $\\min\\Delta\\phi(j_{1,2},\\MET)>0.8$ & $" << fixed << setprecision(2) << bg->GetBinContent(7) << "\\pm" << bg->GetBinError(7)
//    << "$ & $" << T2tt275->GetBinContent(7) << "\\pm" << T2tt275->GetBinError(7)
    << "$ & $" << T2tt300->GetBinContent(7) << "\\pm" << T2tt300->GetBinError(7)
//    << "$ & $" << T2tt600->GetBinContent(7) << "\\pm" << T2tt600->GetBinError(7)
    << "$ & $" << T2tt700->GetBinContent(7) << "\\pm" << T2tt700->GetBinError(7)
    << "$ & $" << T2bW300->GetBinContent(7) << "\\pm" << T2bW300->GetBinError(7)
//    << "$ & $" << T2bW500->GetBinContent(7) << "\\pm" << T2bW500->GetBinError(7)
    << "$ & $" << T2bW600->GetBinContent(7) << "\\pm" << T2bW600->GetBinError(7)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << " & \\multicolumn{8}{l|}{Signal Regions} \\\\" << endl;
    *fLogStream << "\\hline"                    << endl
    << "\\MET [GeV] & \\multicolumn{8}{l|}{Compressed $\\PSGcpmDo-\\PSGczDo$: $2$ jets, $t_\\mathrm{mod}>6.4$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2) << bg->GetBinContent(8) << "\\pm" << bg->GetBinError(8)
//    << "$ & $" << T2tt275->GetBinContent(8) << "\\pm" << T2tt275->GetBinError(8)
    << "$ & $" << T2tt300->GetBinContent(8) << "\\pm" << T2tt300->GetBinError(8)
//    << "$ & $" << T2tt600->GetBinContent(8) << "\\pm" << T2tt600->GetBinError(8)
    << "$ & $" << T2tt700->GetBinContent(8) << "\\pm" << T2tt700->GetBinError(8)
    << "$ & $" << T2bW300->GetBinContent(8) << "\\pm" << T2bW300->GetBinError(8)
//    << "$ & $" << T2bW500->GetBinContent(8) << "\\pm" << T2bW500->GetBinError(8)
    << "$ & $" << T2bW600->GetBinContent(8) << "\\pm" << T2bW600->GetBinError(8)
    << "$ \\\\" << endl;
    *fLogStream << "$>350$    & $" << fixed << setprecision(2) << bg->GetBinContent(9) << "\\pm" << bg->GetBinError(9)
//    << "$ & $" << T2tt275->GetBinContent(9) << "\\pm" << T2tt275->GetBinError(9)
    << "$ & $" << T2tt300->GetBinContent(9) << "\\pm" << T2tt300->GetBinError(9)
//    << "$ & $" << T2tt600->GetBinContent(9) << "\\pm" << T2tt600->GetBinError(9)
    << "$ & $" << T2tt700->GetBinContent(9) << "\\pm" << T2tt700->GetBinError(9)
    << "$ & $" << T2bW300->GetBinContent(9) << "\\pm" << T2bW300->GetBinError(9)
//    << "$ & $" << T2bW500->GetBinContent(9) << "\\pm" << T2bW500->GetBinError(9)
    << "$ & $" << T2bW600->GetBinContent(9) << "\\pm" << T2bW600->GetBinError(9)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{8}{l|}{Boosted High $\\Delta M$: $3$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2) << bg->GetBinContent(10) << "\\pm" << bg->GetBinError(10)
//    << "$ & $" << T2tt275->GetBinContent(10) << "\\pm" << T2tt275->GetBinError(10)
    << "$ & $" << T2tt300->GetBinContent(10) << "\\pm" << T2tt300->GetBinError(10)
//    << "$ & $" << T2tt600->GetBinContent(10) << "\\pm" << T2tt600->GetBinError(10)
    << "$ & $" << T2tt700->GetBinContent(10) << "\\pm" << T2tt700->GetBinError(10)
    << "$ & $" << T2bW300->GetBinContent(10) << "\\pm" << T2bW300->GetBinError(10)
//    << "$ & $" << T2bW500->GetBinContent(10) << "\\pm" << T2bW500->GetBinError(10)
    << "$ & $" << T2bW600->GetBinContent(10) << "\\pm" << T2bW600->GetBinError(10)
    << "$ \\\\" << endl;
    *fLogStream << "$>350$    & $" << fixed << setprecision(2) << bg->GetBinContent(11) << "\\pm" << bg->GetBinError(11)
//    << "$ & $" << T2tt275->GetBinContent(11) << "\\pm" << T2tt275->GetBinError(11)
    << "$ & $" << T2tt300->GetBinContent(11) << "\\pm" << T2tt300->GetBinError(11)
//    << "$ & $" << T2tt600->GetBinContent(11) << "\\pm" << T2tt600->GetBinError(11)
    << "$ & $" << T2tt700->GetBinContent(11) << "\\pm" << T2tt700->GetBinError(11)
    << "$ & $" << T2bW300->GetBinContent(11) << "\\pm" << T2bW300->GetBinError(11)
//    << "$ & $" << T2bW500->GetBinContent(11) << "\\pm" << T2bW500->GetBinError(11)
    << "$ & $" << T2bW600->GetBinContent(11) << "\\pm" << T2bW600->GetBinError(11)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{8}{l|}{Low $\\Delta M$: $\\geq4$ jets, $\\MTtW\\leq200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-325$    & $" << fixed << setprecision(2) << bg->GetBinContent(12) << "\\pm" << bg->GetBinError(12)
//    << "$ & $" << T2tt275->GetBinContent(12) << "\\pm" << T2tt275->GetBinError(12)
    << "$ & $" << T2tt300->GetBinContent(12) << "\\pm" << T2tt300->GetBinError(12)
//    << "$ & $" << T2tt600->GetBinContent(12) << "\\pm" << T2tt600->GetBinError(12)
    << "$ & $" << T2tt700->GetBinContent(12) << "\\pm" << T2tt700->GetBinError(12)
    << "$ & $" << T2bW300->GetBinContent(12) << "\\pm" << T2bW300->GetBinError(12)
//    << "$ & $" << T2bW500->GetBinContent(12) << "\\pm" << T2bW500->GetBinError(12)
    << "$ & $" << T2bW600->GetBinContent(12) << "\\pm" << T2bW600->GetBinError(12)
    << "$ \\\\" << endl;
    *fLogStream << "$>325$    & $" << fixed << setprecision(2) << bg->GetBinContent(13) << "\\pm" << bg->GetBinError(13)
//    << "$ & $" << T2tt275->GetBinContent(13) << "\\pm" << T2tt275->GetBinError(13)
    << "$ & $" << T2tt300->GetBinContent(13) << "\\pm" << T2tt300->GetBinError(13)
//    << "$ & $" << T2tt600->GetBinContent(13) << "\\pm" << T2tt600->GetBinError(13)
    << "$ & $" << T2tt700->GetBinContent(13) << "\\pm" << T2tt700->GetBinError(13)
    << "$ & $" << T2bW300->GetBinContent(13) << "\\pm" << T2bW300->GetBinError(13)
//    << "$ & $" << T2bW500->GetBinContent(13) << "\\pm" << T2bW500->GetBinError(13)
    << "$ & $" << T2bW600->GetBinContent(13) << "\\pm" << T2bW600->GetBinError(13)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{8}{l|}{High $\\Delta M$: $\\geq4$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2) << bg->GetBinContent(14) << "\\pm" << bg->GetBinError(14)
//    << "$ & $" << T2tt275->GetBinContent(14) << "\\pm" << T2tt275->GetBinError(14)
    << "$ & $" << T2tt300->GetBinContent(14) << "\\pm" << T2tt300->GetBinError(14)
//    << "$ & $" << T2tt600->GetBinContent(14) << "\\pm" << T2tt600->GetBinError(14)
    << "$ & $" << T2tt700->GetBinContent(14) << "\\pm" << T2tt700->GetBinError(14)
    << "$ & $" << T2bW300->GetBinContent(14) << "\\pm" << T2bW300->GetBinError(14)
//    << "$ & $" << T2bW500->GetBinContent(14) << "\\pm" << T2bW500->GetBinError(14)
    << "$ & $" << T2bW600->GetBinContent(14) << "\\pm" << T2bW600->GetBinError(14)
    << "$ \\\\" << endl;
    *fLogStream << "$350-450$    & $" << fixed << setprecision(2) << bg->GetBinContent(15) << "\\pm" << bg->GetBinError(15)
//    << "$ & $" << T2tt275->GetBinContent(15) << "\\pm" << T2tt275->GetBinError(15)
    << "$ & $" << T2tt300->GetBinContent(15) << "\\pm" << T2tt300->GetBinError(15)
//    << "$ & $" << T2tt600->GetBinContent(15) << "\\pm" << T2tt600->GetBinError(15)
    << "$ & $" << T2tt700->GetBinContent(15) << "\\pm" << T2tt700->GetBinError(15)
    << "$ & $" << T2bW300->GetBinContent(15) << "\\pm" << T2bW300->GetBinError(15)
//    << "$ & $" << T2bW500->GetBinContent(15) << "\\pm" << T2bW500->GetBinError(15)
    << "$ & $" << T2bW600->GetBinContent(15) << "\\pm" << T2bW600->GetBinError(15)
    << "$ \\\\" << endl;
    *fLogStream << "$>450$    & $" << fixed << setprecision(2) << bg->GetBinContent(16) << "\\pm" << bg->GetBinError(16)
//    << "$ & $" << T2tt275->GetBinContent(16) << "\\pm" << T2tt275->GetBinError(16)
    << "$ & $" << T2tt300->GetBinContent(16) << "\\pm" << T2tt300->GetBinError(16)
//    << "$ & $" << T2tt600->GetBinContent(16) << "\\pm" << T2tt600->GetBinError(16)
    << "$ & $" << T2tt700->GetBinContent(16) << "\\pm" << T2tt700->GetBinError(16)
    << "$ & $" << T2bW300->GetBinContent(16) << "\\pm" << T2bW300->GetBinError(16)
//    << "$ & $" << T2bW500->GetBinContent(16) << "\\pm" << T2bW500->GetBinError(16)
    << "$ & $" << T2bW600->GetBinContent(16) << "\\pm" << T2bW600->GetBinError(16)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\end{tabular}" << endl
    << "\\end{center}"  << endl
    << "\\end{table}"   << endl
    << "\%ENDLATEX\%"   << endl
    << endl;
    cout << fLogStream->str();
}

void GetPreselectionSignalTable(){

    cout << __LINE__<<endl;
    TFile *f = TFile::Open("CutflowSignal.root");
    cout << __LINE__<<endl;
    TH1F *ttbar1l = (TH1F*)f->Get("Cutflow_TTbar1l");
    TH1F *ttbar2l = (TH1F*)f->Get("Cutflow_TTbar2l");
    TH1F *tW = (TH1F*)f->Get("Cutflow_tW");
    TH1F *WJets = (TH1F*)f->Get("Cutflow_WJets");
    TH1F *rare = (TH1F*)f->Get("Cutflow_Rare");
    cout << __LINE__<<endl;
    
    TH1F *bg = (TH1F*)ttbar1l->Clone("Cutflow_Bg");
    bg->Add(ttbar2l);
    bg->Add(tW);
    bg->Add(WJets);
    bg->Add(rare);
    
    std::ostringstream* fLogStream = new std::ostringstream();
    
    *fLogStream << "*********************************************************************" << endl;
    *fLogStream << "\%BEGINLATEX\%"             << endl;
    *fLogStream << "\\begin{table}[htb]"        << endl
    << "\\begin{center}"            << endl;
    //*fLogStream << "\\tiny"                    << endl;
    *fLogStream << "\\caption{\\label{tab:yields} Yields for the backgrounds  for 2.3 fb$^{-1}$. All yields are directly taken from simulation and no data/simulation corrections are applied. Uncertainty is only statistical.}" << endl;
    *fLogStream << "\\begin{tabular}{|l|ccccc|c|}" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << " Selection/\\MET [GeV] & $\\cPqt\\cPaqt\\to2\\ell$ & $\\cPqt\\cPaqt\\to1\\ell$ & Single Top (tW) & WJets & Rare & Total \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream  << fixed << setprecision(2) << " Preselection & $"
    << ttbar2l->GetBinContent(7) << "\\pm" << ttbar2l->GetBinError(7) << "$ & $"
    << ttbar1l->GetBinContent(7) << "\\pm" << ttbar1l->GetBinError(7) << "$ & $"
    << tW     ->GetBinContent(7) << "\\pm" << tW     ->GetBinError(7) << "$ & $"
    << WJets  ->GetBinContent(7) << "\\pm" << WJets  ->GetBinError(7) << "$ & $"
    << rare   ->GetBinContent(7) << "\\pm" << rare   ->GetBinError(7) << "$ & $"
    << bg     ->GetBinContent(7) << "\\pm" << bg     ->GetBinError(7) << "$ \\\\" << endl;
    *fLogStream << "\\hline"                    << endl
    << "\\MET [GeV] & \\multicolumn{6}{l|}{Compressed $\\PSGcpmDo-\\PSGczDo$: $2$ jets, $t_\\mathrm{mod}>6.4$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(8) << "\\pm" << ttbar2l->GetBinError(8) << "$ & $"
    << ttbar1l->GetBinContent(8) << "\\pm" << ttbar1l->GetBinError(8) << "$ & $"
    << tW     ->GetBinContent(8) << "\\pm" << tW     ->GetBinError(8) << "$ & $"
    << WJets  ->GetBinContent(8) << "\\pm" << WJets  ->GetBinError(8) << "$ & $"
    << rare   ->GetBinContent(8) << "\\pm" << rare   ->GetBinError(8) << "$ & $"
    << bg     ->GetBinContent(8) << "\\pm" << bg     ->GetBinError(8) << "$ \\\\" << endl;
    *fLogStream << "$>350$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(9) << "\\pm" << ttbar2l->GetBinError(9) << "$ & $"
    << ttbar1l->GetBinContent(9) << "\\pm" << ttbar1l->GetBinError(9) << "$ & $"
    << tW     ->GetBinContent(9) << "\\pm" << tW     ->GetBinError(9) << "$ & $"
    << WJets  ->GetBinContent(9) << "\\pm" << WJets  ->GetBinError(9) << "$ & $"
    << rare   ->GetBinContent(9) << "\\pm" << rare   ->GetBinError(9) << "$ & $"
    << bg     ->GetBinContent(9) << "\\pm" << bg     ->GetBinError(9) << "$ \\\\" << endl;
    
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{6}{l|}{Boosted High $\\Delta M$: $3$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(10) << "\\pm" << ttbar2l->GetBinError(10) << "$ & $"
    << ttbar1l->GetBinContent(10) << "\\pm" << ttbar1l->GetBinError(10) << "$ & $"
    << tW     ->GetBinContent(10) << "\\pm" << tW     ->GetBinError(10) << "$ & $"
    << WJets  ->GetBinContent(10) << "\\pm" << WJets  ->GetBinError(10) << "$ & $"
    << rare   ->GetBinContent(10) << "\\pm" << rare   ->GetBinError(10) << "$ & $"
    << bg     ->GetBinContent(10) << "\\pm" << bg     ->GetBinError(10) << "$ \\\\" << endl;
    *fLogStream << "$>350$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(11) << "\\pm" << ttbar2l->GetBinError(11) << "$ & $"
    << ttbar1l->GetBinContent(11) << "\\pm" << ttbar1l->GetBinError(11) << "$ & $"
    << tW     ->GetBinContent(11) << "\\pm" << tW     ->GetBinError(11) << "$ & $"
    << WJets  ->GetBinContent(11) << "\\pm" << WJets  ->GetBinError(11) << "$ & $"
    << rare   ->GetBinContent(11) << "\\pm" << rare   ->GetBinError(11) << "$ & $"
    << bg     ->GetBinContent(11) << "\\pm" << bg     ->GetBinError(11) << "$ \\\\" << endl;
    
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{6}{l|}{Low $\\Delta M$: $\\geq4$ jets, $\\MTtW\\leq200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-325$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(12) << "\\pm" << ttbar2l->GetBinError(12) << "$ & $"
    << ttbar1l->GetBinContent(12) << "\\pm" << ttbar1l->GetBinError(12) << "$ & $"
    << tW     ->GetBinContent(12) << "\\pm" << tW     ->GetBinError(12) << "$ & $"
    << WJets  ->GetBinContent(12) << "\\pm" << WJets  ->GetBinError(12) << "$ & $"
    << rare   ->GetBinContent(12) << "\\pm" << rare   ->GetBinError(12) << "$ & $"
    << bg     ->GetBinContent(12) << "\\pm" << bg     ->GetBinError(12) << "$ \\\\" << endl;
    *fLogStream << "$>325$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(13) << "\\pm" << ttbar2l->GetBinError(13) << "$ & $"
    << ttbar1l->GetBinContent(13) << "\\pm" << ttbar1l->GetBinError(13) << "$ & $"
    << tW     ->GetBinContent(13) << "\\pm" << tW     ->GetBinError(13) << "$ & $"
    << WJets  ->GetBinContent(13) << "\\pm" << WJets  ->GetBinError(13) << "$ & $"
    << rare   ->GetBinContent(13) << "\\pm" << rare   ->GetBinError(13) << "$ & $"
    << bg     ->GetBinContent(13) << "\\pm" << bg     ->GetBinError(13) << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\MET [GeV]  & \\multicolumn{6}{l|}{High $\\Delta M$: $\\geq4$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
    << "\\hline" << endl;
    *fLogStream << "$250-350$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(14) << "\\pm" << ttbar2l->GetBinError(14) << "$ & $"
    << ttbar1l->GetBinContent(14) << "\\pm" << ttbar1l->GetBinError(14) << "$ & $"
    << tW     ->GetBinContent(14) << "\\pm" << tW     ->GetBinError(14) << "$ & $"
    << WJets  ->GetBinContent(14) << "\\pm" << WJets  ->GetBinError(14) << "$ & $"
    << rare   ->GetBinContent(14) << "\\pm" << rare   ->GetBinError(14) << "$ & $"
    << bg     ->GetBinContent(14) << "\\pm" << bg     ->GetBinError(14) << "$ \\\\" << endl;
    *fLogStream << "$350-450$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(15) << "\\pm" << ttbar2l->GetBinError(15) << "$ & $"
    << ttbar1l->GetBinContent(15) << "\\pm" << ttbar1l->GetBinError(15) << "$ & $"
    << tW     ->GetBinContent(15) << "\\pm" << tW     ->GetBinError(15) << "$ & $"
    << WJets  ->GetBinContent(15) << "\\pm" << WJets  ->GetBinError(15) << "$ & $"
    << rare   ->GetBinContent(15) << "\\pm" << rare   ->GetBinError(15) << "$ & $"
    << bg     ->GetBinContent(15) << "\\pm" << bg     ->GetBinError(15) << "$ \\\\" << endl;
    *fLogStream << "$>450$    & $" << fixed << setprecision(2)
    << ttbar2l->GetBinContent(16) << "\\pm" << ttbar2l->GetBinError(16) << "$ & $"
    << ttbar1l->GetBinContent(16) << "\\pm" << ttbar1l->GetBinError(16) << "$ & $"
    << tW     ->GetBinContent(16) << "\\pm" << tW     ->GetBinError(16) << "$ & $"
    << WJets  ->GetBinContent(16) << "\\pm" << WJets  ->GetBinError(16) << "$ & $"
    << rare   ->GetBinContent(16) << "\\pm" << rare   ->GetBinError(16) << "$ & $"
    << bg     ->GetBinContent(16) << "\\pm" << bg     ->GetBinError(16) << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\end{tabular}" << endl
    << "\\end{center}"  << endl
    << "\\end{table}"   << endl
    << "\%ENDLATEX\%"   << endl
    << endl;
    cout << fLogStream->str();
    
}
void GetLeptonCompareTable(){
    
    
    cout << __LINE__<<endl;
    TFile *f = TFile::Open("CutflowSignal.root");
    cout << __LINE__<<endl;
    TH1F *ttbar1l = (TH1F*)f->Get("LepCompare_TTbar1l");
    TH1F *ttbar2l = (TH1F*)f->Get("LepCompare_TTbar2l");
    TH1F *tW = (TH1F*)f->Get("LepCompare_tW");
    TH1F *WJets = (TH1F*)f->Get("LepCompare_WJets");
    TH1F *rare = (TH1F*)f->Get("LepCompare_Rare");
    cout << __LINE__<<endl;
    
    TH1F *bg = (TH1F*)ttbar1l->Clone("LepCompare_Bg");
    bg->Add(ttbar2l);
    bg->Add(tW);
    bg->Add(WJets);
    bg->Add(rare);
    cout << __LINE__<< " " << bg->Integral() << endl;
    
    TH1F *T2tt275 = (TH1F*)f->Get("LepCompare_T2tt_275_100");
    TH1F *T2tt300 = (TH1F*)f->Get("LepCompare_T2tt_300_200");
    TH1F *T2tt600 = (TH1F*)f->Get("LepCompare_T2tt_600_250");
    TH1F *T2tt700 = (TH1F*)f->Get("LepCompare_T2tt_700_50");
    TH1F *T2bW300 = (TH1F*)f->Get("LepCompare_T2bW_300_150");
    TH1F *T2bW500 = (TH1F*)f->Get("LepCompare_T2bW_500_200");
    TH1F *T2bW600 = (TH1F*)f->Get("LepCompare_T2bW_600_50");
    
    std::ostringstream* fLogStream = new std::ostringstream();
    cout << __LINE__<<endl;
    
    *fLogStream << "*********************************************************************" << endl;
    *fLogStream << "\%BEGINLATEX\%"             << endl;
    *fLogStream << "\\begin{table}[htb]"        << endl
    << "\\begin{center}"            << endl;
    *fLogStream << "\\tiny"                    << endl;
    *fLogStream << "\\caption{\\label{tab:cutflow} Cutflow for total background and selected signals for 2.3 fb$^{-1}$. All yields are directly taken from simulation and no data/simulation corrections are applied. Uncertainty is only statistical.}" << endl;
    *fLogStream << "\\begin{tabular}{|l|c|cccc|ccc|}" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << "Selection & background & \\multicolumn{4}{c|}{$M_{\\PSQt} - M_{\\PSGczDo}$ [GeV] for $\\PSQt\\to t\\PSGczDo$} & \\multicolumn{3}{c|}{$M_{\\PSQt} - M_{\\PSGczDo}$ [GeV] for $\\PSQt\\to b\\PSGcpmDo$} \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << " & & 275--100 & 300--200 & 600--250 & 700--50 & 300--150 & 500--200 & 600--50 \\\\" << endl;
    *fLogStream << "\\hline"                    << endl;
    //cout << __LINE__<<endl;
    *fLogStream << "$\\MET>250\\GeV$, $\\ell\\,\\pt>20\\GeV$ & $" << fixed << setprecision(1) << bg->GetBinContent(1) << "\\pm" << bg->GetBinError(1)
    << "$ & $" << T2tt275->GetBinContent(1) << "\\pm" << T2tt275->GetBinError(1)
    << "$ & $" << T2tt300->GetBinContent(1) << "\\pm" << T2tt300->GetBinError(1)
    << "$ & $" << T2tt600->GetBinContent(1) << "\\pm" << T2tt600->GetBinError(1)
    << "$ & $" << T2tt700->GetBinContent(1) << "\\pm" << T2tt700->GetBinError(1)
    << "$ & $" << T2bW300->GetBinContent(1) << "\\pm" << T2bW300->GetBinError(1)
    << "$ & $" << T2bW500->GetBinContent(1) << "\\pm" << T2bW500->GetBinError(1)
    << "$ & $" << T2bW600->GetBinContent(1) << "\\pm" << T2bW600->GetBinError(1)
    << "$ \\\\" << endl;
    *fLogStream << "$\\MET>250\\GeV$, $\\ell\\,\\pt>31/24\\GeV$ & $" << fixed << setprecision(1) << bg->GetBinContent(2) << "\\pm" << bg->GetBinError(2)
    << "$ & $" << T2tt275->GetBinContent(2) << "\\pm" << T2tt275->GetBinError(2)
    << "$ & $" << T2tt300->GetBinContent(2) << "\\pm" << T2tt300->GetBinError(2)
    << "$ & $" << T2tt600->GetBinContent(2) << "\\pm" << T2tt600->GetBinError(2)
    << "$ & $" << T2tt700->GetBinContent(2) << "\\pm" << T2tt700->GetBinError(2)
    << "$ & $" << T2bW300->GetBinContent(2) << "\\pm" << T2bW300->GetBinError(2)
    << "$ & $" << T2bW500->GetBinContent(2) << "\\pm" << T2bW500->GetBinError(2)
    << "$ & $" << T2bW600->GetBinContent(2) << "\\pm" << T2bW600->GetBinError(2)
    << "$ \\\\" << endl;
    *fLogStream << "$\\MET>200\\GeV$, $\\ell\\,\\pt>20\\GeV$ & $" << fixed << setprecision(1) << bg->GetBinContent(3) << "\\pm" << bg->GetBinError(3)
    << "$ & $" << T2tt275->GetBinContent(3) << "\\pm" << T2tt275->GetBinError(3)
    << "$ & $" << T2tt300->GetBinContent(3) << "\\pm" << T2tt300->GetBinError(3)
    << "$ & $" << T2tt600->GetBinContent(3) << "\\pm" << T2tt600->GetBinError(3)
    << "$ & $" << T2tt700->GetBinContent(3) << "\\pm" << T2tt700->GetBinError(3)
    << "$ & $" << T2bW300->GetBinContent(3) << "\\pm" << T2bW300->GetBinError(3)
    << "$ & $" << T2bW500->GetBinContent(3) << "\\pm" << T2bW500->GetBinError(3)
    << "$ & $" << T2bW600->GetBinContent(3) << "\\pm" << T2bW600->GetBinError(3)
    << "$ \\\\" << endl;
    *fLogStream << "$\\MET>200\\GeV$, $\\ell\\,\\pt>31/24\\GeV$ & $" << fixed << setprecision(1) << bg->GetBinContent(4) << "\\pm" << bg->GetBinError(4)
    << "$ & $" << T2tt275->GetBinContent(4) << "\\pm" << T2tt275->GetBinError(4)
    << "$ & $" << T2tt300->GetBinContent(4) << "\\pm" << T2tt300->GetBinError(4)
    << "$ & $" << T2tt600->GetBinContent(4) << "\\pm" << T2tt600->GetBinError(4)
    << "$ & $" << T2tt700->GetBinContent(4) << "\\pm" << T2tt700->GetBinError(4)
    << "$ & $" << T2bW300->GetBinContent(4) << "\\pm" << T2bW300->GetBinError(4)
    << "$ & $" << T2bW500->GetBinContent(4) << "\\pm" << T2bW500->GetBinError(4)
    << "$ & $" << T2bW600->GetBinContent(4) << "\\pm" << T2bW600->GetBinError(4)
    << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl
    << "\\end{tabular}" << endl
    << "\\end{center}"  << endl
    << "\\end{table}"   << endl
    << "\%ENDLATEX\%"   << endl
    << endl;
    cout << fLogStream->str();


}






void GetMT2WCutEfficiency(){
    
    cout << __LINE__<<endl;
    TFile *f = TFile::Open("CutflowSignal.root");
    cout << __LINE__<<endl;
    TH1F *ttbar1l = (TH1F*)f->Get("Cutflow2_TTbar1l");
    TH1F *ttbar2l = (TH1F*)f->Get("Cutflow2_TTbar2l");
    TH1F *tW = (TH1F*)f->Get("Cutflow2_tW");
    TH1F *WJets = (TH1F*)f->Get("Cutflow2_WJets");
    TH1F *rare = (TH1F*)f->Get("Cutflow2_Rare");
    cout << __LINE__<<endl;
    
    TH1F *bg = (TH1F*)ttbar1l->Clone("Cutflow2_Bg");
    bg->Add(ttbar2l);
    bg->Add(tW);
    bg->Add(WJets);
    bg->Add(rare);
    
    
    TH1F *T2tt275 = (TH1F*)f->Get("Cutflow2_T2tt_275_100");
    TH1F *T2tt300 = (TH1F*)f->Get("Cutflow2_T2tt_300_200");
    TH1F *T2tt600 = (TH1F*)f->Get("Cutflow2_T2tt_600_250");
    TH1F *T2tt700 = (TH1F*)f->Get("Cutflow2_T2tt_700_50");
    TH1F *T2bW300 = (TH1F*)f->Get("Cutflow2_T2tb_650_325");
    TH1F *T2bW500 = (TH1F*)f->Get("Cutflow2_T2bW_500_200");
    TH1F *T2bW600 = (TH1F*)f->Get("Cutflow2_T2tb_850_100");
    
    std::ostringstream* fLogStream = new std::ostringstream();
    
    *fLogStream << "*********************************************************************" << endl;
    *fLogStream << "\%BEGINLATEX\%"             << endl;
    *fLogStream << "\\begin{table}[htb]"        << endl
    << "\\begin{center}"            << endl;
    //*fLogStream << "\\tiny"                    << endl;
    *fLogStream << "\\caption{\\label{tab:MT2Wtopness} MT2W and mod discriminating powers..}" << endl;
    *fLogStream << "\\begin{tabular}{|l|cc|cc|}" << endl;
    *fLogStream << "\\hline"                    << endl;
    *fLogStream << "Sample & 2 jets, $t_\\text{mod}<6.4$ & 2 jets, $t_\\text{mod}>6.4$ & $\\geq 3$ jets, $\\MTtW<200\\GeV$ & $\\geq 3$ jets, $\\MTtW<200\\GeV$ \\\\";
    *fLogStream << "\\hline"                    << endl;
    *fLogStream  << fixed << setprecision(2) << " $\\cPqt\\cPaqt\\to2\\ell$ & $"
    << ttbar2l->GetBinContent(1) << "\\pm" << ttbar2l->GetBinError(1) << "$ & $"
    << ttbar2l->GetBinContent(2) << "\\pm" << ttbar2l->GetBinError(2) << "$ & $"
    << ttbar2l->GetBinContent(3) << "\\pm" << ttbar2l->GetBinError(3) << "$ & $"
    << ttbar2l->GetBinContent(4) << "\\pm" << ttbar2l->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " $\\cPqt\\cPaqt\\to1\\ell$ & $"
    << ttbar1l->GetBinContent(1) << "\\pm" << ttbar1l->GetBinError(1) << "$ & $"
    << ttbar1l->GetBinContent(2) << "\\pm" << ttbar1l->GetBinError(2) << "$ & $"
    << ttbar1l->GetBinContent(3) << "\\pm" << ttbar1l->GetBinError(3) << "$ & $"
    << ttbar1l->GetBinContent(4) << "\\pm" << ttbar1l->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " Single Top (tW) & $"
    << tW->GetBinContent(1) << "\\pm" << tW->GetBinError(1) << "$ & $"
    << tW->GetBinContent(2) << "\\pm" << tW->GetBinError(2) << "$ & $"
    << tW->GetBinContent(3) << "\\pm" << tW->GetBinError(3) << "$ & $"
    << tW->GetBinContent(4) << "\\pm" << tW->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " W+jets & $"
    << WJets->GetBinContent(1) << "\\pm" << WJets->GetBinError(1) << "$ & $"
    << WJets->GetBinContent(2) << "\\pm" << WJets->GetBinError(2) << "$ & $"
    << WJets->GetBinContent(3) << "\\pm" << WJets->GetBinError(3) << "$ & $"
    << WJets->GetBinContent(4) << "\\pm" << WJets->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " Rare & $"
    << rare->GetBinContent(1) << "\\pm" << rare->GetBinError(1) << "$ & $"
    << rare->GetBinContent(2) << "\\pm" << rare->GetBinError(2) << "$ & $"
    << rare->GetBinContent(3) << "\\pm" << rare->GetBinError(3) << "$ & $"
    << rare->GetBinContent(4) << "\\pm" << rare->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream << "\\hline" << endl;
    *fLogStream  << fixed << setprecision(2) << " T2tt-300-200 & $"
    << T2tt300->GetBinContent(1) << "\\pm" << T2tt300->GetBinError(1) << "$ & $"
    << T2tt300->GetBinContent(2) << "\\pm" << T2tt300->GetBinError(2) << "$ & $"
    << T2tt300->GetBinContent(3) << "\\pm" << T2tt300->GetBinError(3) << "$ & $"
    << T2tt300->GetBinContent(4) << "\\pm" << T2tt300->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " T2tt-700-50 & $"
    << T2tt700->GetBinContent(1) << "\\pm" << T2tt700->GetBinError(1) << "$ & $"
    << T2tt700->GetBinContent(2) << "\\pm" << T2tt700->GetBinError(2) << "$ & $"
    << T2tt700->GetBinContent(3) << "\\pm" << T2tt700->GetBinError(3) << "$ & $"
    << T2tt700->GetBinContent(4) << "\\pm" << T2tt700->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " T2bW-300-150 & $"
    << T2bW300->GetBinContent(1) << "\\pm" << T2bW300->GetBinError(1) << "$ & $"
    << T2bW300->GetBinContent(2) << "\\pm" << T2bW300->GetBinError(2) << "$ & $"
    << T2bW300->GetBinContent(3) << "\\pm" << T2bW300->GetBinError(3) << "$ & $"
    << T2bW300->GetBinContent(4) << "\\pm" << T2bW300->GetBinError(4) << "$ \\\\" << endl;
    *fLogStream  << fixed << setprecision(2) << " T2bW-600-50 & $"
    << T2bW600->GetBinContent(1) << "\\pm" << T2bW600->GetBinError(1) << "$ & $"
    << T2bW600->GetBinContent(2) << "\\pm" << T2bW600->GetBinError(2) << "$ & $"
    << T2bW600->GetBinContent(3) << "\\pm" << T2bW600->GetBinError(3) << "$ & $"
    << T2bW600->GetBinContent(4) << "\\pm" << T2bW600->GetBinError(4) << "$ \\\\" << endl;
    
    *fLogStream << "\\hline" << endl
    << "\\end{tabular}" << endl
    << "\\end{center}"  << endl
    << "\\end{table}"   << endl
    << "\%ENDLATEX\%"   << endl
    << endl;
    cout << fLogStream->str();
    
}
