string tablefragment (TH1F *h, int b, bool data=false){
    stringstream ss;
    if(data) ss << (int)h->GetBinContent(b);
    else if(h->GetBinContent(b)<0.005) return "\\multicolumn{2}{c|}{---}";
    else if(h->GetBinContent(b)>=99.95) ss << fixed << setprecision(0) << "\\multicolumn{2}{c|}{" << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b) << "}";
    else if(h->GetBinContent(b)>=0.995) ss << fixed << setprecision(1) << "\\multicolumn{2}{c|}{" << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b) << "}";
    else ss << fixed << setprecision(2) << "\\multicolumn{2}{c|}{" << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b) << "}";
    return ss.str();
}

string tableline(string firstbin, int b, TH1F *h1, TH1F *h2, TH1F *h3){
    stringstream ss;
    ss << firstbin << " & " << tablefragment(h1,b) << " & " << tablefragment(h2,b) << " & " << tablefragment(h3,b) <<  " \\\\" << endl;
    return ss.str();
}

string tablecore(TH1F *h1, TH1F *h2, TH1F *h3){
    stringstream ss;
    //ss << "\\begin{tabular}{|r|r|r|r|c|c|c|}" << endl
    //<< "\\hline" << endl
    ss << tableline("\\multicolumn{4}{|r|}{$\\geq1\\ell$, $\\geq2$ jets, $\\MET>150\\GeV$}", 1,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+\\MT>150\\GeV$}", 2,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+\\geq1$ b-tagged jet}", 3,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+2^{\\text{nd}}\\ell$ veto}", 4,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+\\tau_{\\text{h}}$, iso.track veto}", 5,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+\\min\\Delta\\phi(\\MET,j_{1,2})>0.8$}", 6,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$+\\MET>250\\GeV$}", 7,h1,h2,h3)
    << "\\hline" << endl
    << tableline("\\multicolumn{4}{|r|}{$\\tmod>0$}", 8,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$\\tmod>10$}", 9,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$\\Mlb\\leq175\\GeV$}",11,h1,h2,h3)
    << tableline("\\multicolumn{4}{|r|}{$\\Mlb>175\\GeV$}",10,h1,h2,h3)
    << "\\hline" << endl
    << "\\hline" << endl
    << "\\multirow{2}{*}{$N_\\mathrm{J}$} & \\multirow{2}{*}{$t_\\mathrm{mod}$} & $M_\\mathrm{\\ell b}$ & $E_\\mathrm{T}^\\mathrm{miss}$ & & & & & & \\\\" << endl
    << "  &  &  [GeV] &  [GeV] & & & & & & \\\\" << endl
    << "\\hline" << endl
    //<< tableline("SR sum",12,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $250-350$",13,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $350-450$",14,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $450-600$",15,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ & $\\leq175$ &    $>600$",16,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ &     $>175$ & $250-450$",17,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ &     $>175$ & $450-600$",18,h1,h2,h3)
    << tableline("$\\leq3$ &    $>10$ &     $>175$ &    $>600$",19,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $250-350$",20,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $350-450$",21,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $450-550$",22,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $550-650$",23,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ &    $>650$",24,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $250-350$",25,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $350-450$",26,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $450-550$",27,h1,h2,h3)
    << tableline("$\\geq4$ & $\\leq0$ &     $>175$ &    $>550$",28,h1,h2,h3)
    << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ & $250-350$",29,h1,h2,h3)
    << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ & $350-550$",30,h1,h2,h3)
    << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ &    $>550$",31,h1,h2,h3)
    << tableline("$\\geq4$ &   $0-10$ &     $>175$ & $250-450$",32,h1,h2,h3)
    << tableline("$\\geq4$ &   $0-10$ &     $>175$ &    $>450$",33,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $250-350$",34,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $350-450$",35,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $450-600$",36,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ & $\\leq175$ &    $>600$",37,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ &     $>175$ & $250-450$",38,h1,h2,h3)
    << tableline("$\\geq4$ &    $>10$ &     $>175$ &    $>450$",39,h1,h2,h3)
    << "\\hline" << endl
    << tableline("\\multicolumn{3}{|l|}{compressed region} & $250-350$",40,h1,h2,h3)
    << tableline("\\multicolumn{3}{|l|}{compressed region} & $350-450$",41,h1,h2,h3)
    << tableline("\\multicolumn{3}{|l|}{compressed region} & $450-550$",42,h1,h2,h3)
    << tableline("\\multicolumn{3}{|l|}{compressed region} &    $>550$",43,h1,h2,h3);
    //<< "\\hline" << endl
    //<< "\\end{tabular}" << endl;
    return ss.str();
}

void SignalCutflowTables(){
    
    TFile *f = TFile::Open("SignalCutFlow_averaged.root");
    
    map<string,TH1F*> h;
    vector<string> hname;
    hname.push_back("SignalCutFlow_Signal_T2tt_1000_50");
    hname.push_back("SignalCutFlow_Signal_T2tt_800_400");
    hname.push_back("SignalCutFlow_Signal_T2tt_500_325");
    hname.push_back("SignalCutFlow_Signal_T2tb_850_50");
    hname.push_back("SignalCutFlow_Signal_T2tb_750_300");
    hname.push_back("SignalCutFlow_Signal_T2tb_450_250");
    hname.push_back("SignalCutFlow_Signal_T2bW_900_50");
    hname.push_back("SignalCutFlow_Signal_T2bW_800_350");
    hname.push_back("SignalCutFlow_Signal_T2bW_500_300");
    
    for(unsigned int i = 0; i<hname.size(); ++i){
        h[hname[i] ] = (TH1F*)f->Get(hname[i].c_str());
    }
    
    cout << "\\begin{table}[htb]" << endl;
    cout << "\\centering" << endl << "\\small" << endl;
    cout << "\\caption{Cutflow table for $\\Pp\\Pp\\to\\PSQt\\PSQt^{*}\\to \\PQt\\PAQt\\PSGczDo\\PSGczDo$ signals for an integrated luminosity of 36.6\\fbinv. The uncertainties are purely statistical. No correction for signal contamination in data control regions are applied.}" << endl;
    cout << "\\begin{tabular}{|r|r|r|r|cc|cc|cc|}" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{\\multirow{2}{*}{Selection}} & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ & $M_{\\PSQt}$ & $M_{\\PSGczDo}$  & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ \\\\" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & 1000 & 50 & 800 & 400 & 500 & 325 \\\\" << endl;
    cout << "\\hline" << endl;
    cout << tablecore(h["SignalCutFlow_Signal_T2tt_1000_50"],h["SignalCutFlow_Signal_T2tt_800_400"],h["SignalCutFlow_Signal_T2tt_500_325"]);
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;
    
    cout << endl << endl;
    
    cout << "\\begin{table}[htb]" << endl;
    cout << "\\centering" << endl << "\\small" << endl;
    cout << "\\caption{Cutflow table for $\\Pp\\Pp\\to\\PSQt\\PSQt^{*}, \\PSQt\\to\\PQt\\PSGczDo / \\PQb\\PSGcpmDo$ signals for an integrated luminosity of 36.6\\fbinv. The branching fraction for this model is BR($\\PSQt\\to\\PQt\\PSGczDo$) = BR($\\PSQt\\to\\PQb\\PSGcpmDo$) = 0.5, and $M_{\\PSGcpmDo} = M_{\\PSGczDo} + 5\\GeV$. The uncertainties are purely statistical. No correction for signal contamination in data control regions are applied.}" << endl;
    cout << "\\begin{tabular}{|r|r|r|r|cc|cc|cc|}" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{\\multirow{2}{*}{Selection}} & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ & $M_{\\PSQt}$ & $M_{\\PSGczDo}$  & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ \\\\" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & 850 & 50 & 750 & 300 & 450 & 250 \\\\" << endl;
    cout << "\\hline" << endl;
    cout << tablecore(h["SignalCutFlow_Signal_T2tb_850_50"],h["SignalCutFlow_Signal_T2tb_750_300"],h["SignalCutFlow_Signal_T2tb_450_250"]);
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;
    
    cout << endl << endl;
    
    cout << "\\begin{table}[htb]" << endl;
    cout << "\\centering" << endl << "\\small" << endl;
    cout << "\\caption{Cutflow table for $\\Pp\\Pp\\to\\PSQt\\PSQt^{*}\\to \\PQb\\PAQb\\PSGcpmDo\\PSGcpmDo$, $\\PSGcpmDo\\to\\PW\\PSGczDo$ signals with $M_{\\PSGcpmDo} = (M_{\\PSQt}+M_{\\PSGczDo})/2$ for an integrated luminosity of 36.6\\fbinv. The uncertainties are purely statistical. No correction for signal contamination in data control regions are applied.}" << endl;
    cout << "\\begin{tabular}{|r|r|r|r|cc|cc|cc|}" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{\\multirow{2}{*}{Selection}} & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ & $M_{\\PSQt}$ & $M_{\\PSGczDo}$  & $M_{\\PSQt}$ & $M_{\\PSGczDo}$ \\\\" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] & [GeV] \\\\" << endl;
    cout << "\\hline" << endl;
    cout << "\\multicolumn{4}{|r|}{ } & 900 & 50 & 800 & 350 & 500 & 300 \\\\" << endl;
    cout << "\\hline" << endl;
    cout << tablecore(h["SignalCutFlow_Signal_T2bW_900_50"],h["SignalCutFlow_Signal_T2bW_800_350"],h["SignalCutFlow_Signal_T2bW_500_300"]);
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;
}