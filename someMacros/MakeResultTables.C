#include "TFile.h"
#include "TH1F.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include "TString.h"

using namespace std;

void MakeResultTables(TString inputfile){

  ifstream infile(inputfile.Data());
  if(!(infile.good() ) ) {
    cout << "file " << inputfile << " does not exist - exit" << endl;
    return;
  }
  TFile *f = new TFile(inputfile,"read");
  if(f->IsZombie()) {
    f->Close();
    delete f;
    cout << "file " << inputfile << " is zombie - exit" << endl;
    return;
  }
  f->cd();

  TH1D *Data = (TH1D*)f->Get("rpt_Data");
  TH1D *LL   = (TH1D*)f->Get("rpt_LLest");
  TH1D *W1l  = (TH1D*)f->Get("rpt_0best");
  TH1D *tt1l = (TH1D*)f->Get("rpt_tt1l");
  TH1D *ttz  = (TH1D*)f->Get("rpt_znunu");
  //TH1D *rpt_750   = (TH1D*)f->Get("rpt_T2tt_750_50" );
  //TH1D *rpt_600   = (TH1D*)f->Get("rpt_T2tt_600_250");
  //TH1D *rpt_500   = (TH1D*)f->Get("rpt_T2tt_500_100");
  //TH1D *rpt_300   = (TH1D*)f->Get("rpt_T2tt_300_200");

  TH1D *bg   = (TH1D*)LL->Clone("rpt_bg"); bg->Sumw2();
  //bg->Add(W1l);//don't do that - I don't know if errors are somed correctly
  for(int i = 1; i<=bg->GetNbinsX(); ++i){
    bg->SetBinContent(i, LL->GetBinContent(i) + W1l->GetBinContent(i) + tt1l->GetBinContent(i) + ttz->GetBinContent(i) );
    bg->SetBinError(i, sqrt(pow(LL->GetBinError(i),2) + pow(W1l->GetBinError(i),2) + pow(tt1l->GetBinError(i),2) + pow(ttz->GetBinError(i),2) ) );
  }
  
  std::ostringstream* fLogStream = new std::ostringstream();
  /*
  *fLogStream << "*********************************************************************" << endl;
  *fLogStream << "\%BEGINLATEX\%"             << endl;
  *fLogStream << "\\begin{table}[htb]"        << endl
	      << "\\begin{center}"            << endl;
  // *fLogStream << "\\small"                    << endl;
  *fLogStream << "\\caption{\\label{tab:results} Results of the data- and simulation-driven background estimates together with the observed data yields for 2.3\\fbinv collected during 2015 pp collisions. The uncertainties are the quadratic sums of statistical and systematic uncertainties.}" << endl;
  *fLogStream << "\\begin{tabular}{|r|cccc|c|r|}" << endl;	     
  *fLogStream << "\\hline"                    << endl;
  *fLogStream << "\\multirow{2}{*}{\\MET [GeV]} &  \\multirow{2}{*}{Lost Lepton} & $1\\ell$ (not  &  \\multirow{2}{*}{$\\ttbar\\to1\\ell$}&  \\multirow{2}{*}{$\\cPZ\\to\\cPgn\\cPagn$} & Total & \\multirow{2}{*}{Data} \\\\" << endl
	      << " &  & from top) &  &  & background &  \\\\" << endl;
    *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{6}{l|}{Boosted High $\\Delta M$: $3$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
  *fLogStream << "$>350$    & $" << fixed << setprecision(2) << LL->GetBinContent(6) << "\\pm" << LL->GetBinError(6) << "$ & $" << W1l->GetBinContent(6) << "\\pm" << W1l->GetBinError(6) << "$ & $" << tt1l->GetBinContent(6) << "\\pm" << tt1l->GetBinError(6) << "$ & $" << ttz->GetBinContent(6) << "\\pm" << ttz->GetBinError(6) << "$ & $" << bg->GetBinContent(6) << "\\pm" << bg->GetBinError(6) << "$ & $" << int(Data->GetBinContent(6)) << "$ \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{6}{l|}{Low $\\Delta M$: $\\geq4$ jets, $\\MTtW\\leq200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
  *fLogStream << "$250-325$ & $" << fixed << setprecision(2) << LL->GetBinContent(1) << "\\pm" << LL->GetBinError(1) << "$ & $" << W1l->GetBinContent(1) << "\\pm" << W1l->GetBinError(1) << "$ & $" << tt1l->GetBinContent(1) << "\\pm" << tt1l->GetBinError(1) << "$ & $" << ttz->GetBinContent(1) << "\\pm" << ttz->GetBinError(1) << "$ & $" << bg->GetBinContent(1) << "\\pm" << bg->GetBinError(1) << "$ & $" << int(Data->GetBinContent(1)) << "$ \\\\" << endl;
  *fLogStream << "$>325$ & $" << fixed << setprecision(2) << LL->GetBinContent(2) << "\\pm" << LL->GetBinError(2) << "$ & $" << W1l->GetBinContent(2) << "\\pm" << W1l->GetBinError(2) << "$ & $" << tt1l->GetBinContent(2) << "\\pm" << tt1l->GetBinError(2) << "$ & $" << ttz->GetBinContent(2) << "\\pm" << ttz->GetBinError(2) << "$ & $" << bg->GetBinContent(2) << "\\pm" << bg->GetBinError(2) << "$ & $" << int(Data->GetBinContent(2)) << "$ \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{6}{l|}{High $\\Delta M$: $\\geq4$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
  *fLogStream << "$250-350$ & $" << fixed << setprecision(2) << LL->GetBinContent(3) << "\\pm" << LL->GetBinError(3) << "$ & $" << W1l->GetBinContent(3) << "\\pm" << W1l->GetBinError(3) << "$ & $" << tt1l->GetBinContent(3) << "\\pm" << tt1l->GetBinError(3) << "$ & $" << ttz->GetBinContent(3) << "\\pm" << ttz->GetBinError(3) << "$ & $" << bg->GetBinContent(3) << "\\pm" << bg->GetBinError(3) << "$ & $" << int(Data->GetBinContent(3)) << "$ \\\\" << endl;
  *fLogStream << "$350-450$ & $" << fixed << setprecision(2) << LL->GetBinContent(4) << "\\pm" << LL->GetBinError(4) << "$ & $" << W1l->GetBinContent(4) << "\\pm" << W1l->GetBinError(4) << "$ & $" << tt1l->GetBinContent(4) << "\\pm" << tt1l->GetBinError(4) << "$ & $" << ttz->GetBinContent(4) << "\\pm" << ttz->GetBinError(4) << "$ & $" << bg->GetBinContent(4) << "\\pm" << bg->GetBinError(4) << "$ & $" << int(Data->GetBinContent(4)) << "$ \\\\" << endl;
  *fLogStream << "$>450$ & $" << fixed << setprecision(2) << LL->GetBinContent(5) << "\\pm" << LL->GetBinError(5) << "$ & $" << W1l->GetBinContent(5) << "\\pm" << W1l->GetBinError(5) << "$ & $" << tt1l->GetBinContent(5) << "\\pm" << tt1l->GetBinError(5) << "$ & $" << ttz->GetBinContent(5) << "\\pm" << ttz->GetBinError(5) << "$ & $" << bg->GetBinContent(5) << "\\pm" << bg->GetBinError(5) << "$ & $" << int(Data->GetBinContent(5)) << "$ \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << "\\end{tabular}" << endl
	      << "\\end{center}"  << endl
	      << "\\end{table}"   << endl
	      << "\%ENDLATEX\%"   << endl
	      << endl;
  cout << fLogStream->str();
  */
    *fLogStream << "*********************************************************************" << endl;
  *fLogStream << "\%BEGINLATEX\%"             << endl;
  *fLogStream << "\\begin{table}[htb]"        << endl
	      << "\\begin{center}"            << endl;
  // *fLogStream << "\\small"                    << endl;
  *fLogStream << "\\caption{\\label{tab:results} Results of the data- and simulation-driven background estimates together with the observed data yields for 2.3\\fbinv collected during 2015 pp collisions. The uncertainties are the quadratic sums of statistical and systematic uncertainties.}" << endl;
  *fLogStream << "\\begin{tabular}{|r|r@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}lr@{\\,$\\pm$\\,}l|r@{\\,$\\pm$\\,}l|r|}" << endl;
  *fLogStream << "\\hline"                    << endl;
  *fLogStream << "\\multirow{2}{*}{\\MET [GeV]} &  \\multicolumn{2}{c|}{\\multirow{2}{*}{Lost Lepton}} & \\multicolumn{2}{c|}{$1\\ell$ (not}  &  \\multicolumn{2}{c|}{\\multirow{2}{*}{$\\ttbar\\to1\\ell$}} &  \\multicolumn{2}{c|}{\\multirow{2}{*}{$\\cPZ\\to\\cPgn\\cPagn$}} & \\multicolumn{2}{c|}{Total} & \\multirow{2}{*}{Data} \\\\" << endl
	      << " & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{from top)} & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{~} & \\multicolumn{2}{c|}{background} &  \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{11}{l|}{Boosted High $\\Delta M$: $3$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
    *fLogStream << "$>350$    & " << fixed << setprecision(2) << LL->GetBinContent(6) << "&" << LL->GetBinError(6) << " & " << W1l->GetBinContent(6) << "&" << W1l->GetBinError(6) << " & " << tt1l->GetBinContent(6) << "&" << tt1l->GetBinError(6) << " & " << ttz->GetBinContent(6) << "&" << ttz->GetBinError(6) << " & " << bg->GetBinContent(6) << "&" << bg->GetBinError(6) << " & " << int(Data->GetBinContent(6)) << " \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{11}{l|}{Low $\\Delta M$: $\\geq4$ jets, $\\MTtW\\leq200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
  *fLogStream << "$250-325$ & " << fixed << setprecision(2) << LL->GetBinContent(1) << "&" << LL->GetBinError(1) << " & " << W1l->GetBinContent(1) << "&" << W1l->GetBinError(1) << " & " << tt1l->GetBinContent(1) << "&" << tt1l->GetBinError(1) << " & " << ttz->GetBinContent(1) << "&" << ttz->GetBinError(1) << " & " << bg->GetBinContent(1) << "&" << bg->GetBinError(1) << " & " << int(Data->GetBinContent(1)) << " \\\\" << endl;
  *fLogStream << "$>325$ & " << fixed << setprecision(2) << LL->GetBinContent(2) << "&" << LL->GetBinError(2) << " & " << W1l->GetBinContent(2) << "&" << W1l->GetBinError(2) << " & " << tt1l->GetBinContent(2) << "&" << tt1l->GetBinError(2) << " & " << ttz->GetBinContent(2) << "&" << ttz->GetBinError(2) << " & " << bg->GetBinContent(2) << "&" << bg->GetBinError(2) << " & " << int(Data->GetBinContent(2)) << " \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << " & \\multicolumn{11}{l|}{High $\\Delta M$: $\\geq4$ jets, $\\MTtW>200\\GeV$} \\\\" << endl
	      << "\\hline" << endl;
  *fLogStream << "$250-350$ & " << fixed << setprecision(2) << LL->GetBinContent(3) << "&" << LL->GetBinError(3) << " & " << W1l->GetBinContent(3) << "&" << W1l->GetBinError(3) << " & " << tt1l->GetBinContent(3) << "&" << tt1l->GetBinError(3) << " & " << ttz->GetBinContent(3) << "&" << ttz->GetBinError(3) << " & " << bg->GetBinContent(3) << "&" << bg->GetBinError(3) << " & " << int(Data->GetBinContent(3)) << " \\\\" << endl;
  *fLogStream << "$350-450$ & " << fixed << setprecision(2) << LL->GetBinContent(4) << "&" << LL->GetBinError(4) << " & " << W1l->GetBinContent(4) << "&" << W1l->GetBinError(4) << " & " << tt1l->GetBinContent(4) << "&" << tt1l->GetBinError(4) << " & " << ttz->GetBinContent(4) << "&" << ttz->GetBinError(4) << " & " << bg->GetBinContent(4) << "&" << bg->GetBinError(4) << " & " << int(Data->GetBinContent(4)) << " \\\\" << endl;
  *fLogStream << "$>450$ & " << fixed << setprecision(2) << LL->GetBinContent(5) << "&" << LL->GetBinError(5) << " & " << W1l->GetBinContent(5) << "&" << W1l->GetBinError(5) << " & " << tt1l->GetBinContent(5) << "&" << tt1l->GetBinError(5) << " & " << ttz->GetBinContent(5) << "&" << ttz->GetBinError(5) << " & " << bg->GetBinContent(5) << "&" << bg->GetBinError(5) << " & " << int(Data->GetBinContent(5)) << " \\\\" << endl;
  *fLogStream << "\\hline" << endl
	      << "\\end{tabular}" << endl
	      << "\\end{center}"  << endl
	      << "\\end{table}"   << endl
	      << "\%ENDLATEX\%"   << endl
	      << endl;
  cout << fLogStream->str();
}
