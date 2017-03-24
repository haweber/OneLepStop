string tablefragment (TH1D *h, int b, bool data=false){
    stringstream ss;
    if(data) ss << (int)h->GetBinContent(b);
    else if(h->GetBinContent(b)<0.005) return "---";
    else if(h->GetBinContent(b)>=99.95) ss << fixed << setprecision(0) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    else if(h->GetBinContent(b)>=0.995) ss << fixed << setprecision(1) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    else ss << fixed << setprecision(2) << h->GetBinContent(b) << "$\\pm$" << h->GetBinError(b);
    return ss.str();
}

string tableline(string firstbin, int b, TH1D *hLL, TH1D *htt1l, TH1D *h0b, TH1D *hZ, TH1D *hbg, TH1D *hdata){
    stringstream ss;
    ss << firstbin << " & " << tablefragment(hLL,b) << " & " << tablefragment(htt1l,b) << " & " << tablefragment(h0b,b) << " & " << tablefragment(hZ,b) << " & " << tablefragment(hbg,b) << " & " << tablefragment(hdata,b,true) << " \\\\" << endl;
    return ss.str();
}

void MakeResultRootfile(){

TFile *fresults = new TFile("ResultRootFileMoriond17.root","RECREATE");
TH1D *hdata = new TH1D("rpt_Data","",31,0,31); hdata->Sumw2(); hdata->SetBinErrorOption(TH1::kPoisson);
TH1D *hLL = new TH1D("rpt_LLest","",31,0,31); hLL->Sumw2();
TH1D *h0b = new TH1D("rpt_0best","",31,0,31); h0b->Sumw2();
TH1D *hZ = new TH1D("rpt_znunu","",31,0,31); hZ->Sumw2();
TH1D *htt1l = new TH1D("rpt_tt1l","",31,0,31); htt1l->Sumw2();
TH1D *hbg = new TH1D("rpt_bg","",31,0,31); hbg->Sumw2();

TFile *fLL = TFile::Open("bkgEst_lostLepton__mlb_v2_bins__histos.root");

    TH1D *hLLc = (TH1D*)fLL->Get("CR2l_yield"); hLLc->SetName("CR2lyield");
    TFile *fLLc = TFile::Open("LostLepton_BkgEst_compressed.root");
    TH1D *hLLcc = (TH1D*)fLLc->Get("CR2l_yield"); hLLcc->SetName("CR2lyieldc");
    /*
  TH1D *hLLu1 = (TH1D*)fLL->Get("CR2l_dataStatsUp");
  TH1D *hLLd1 = (TH1D*)fLL->Get("CR2l_dataStatsDn");
  TH1D *hLLu2 = (TH1D*)fLL->Get("CR2l_mcStatsUp");
  TH1D *hLLd2 = (TH1D*)fLL->Get("CR2l_mcStatsDn");
  TH1D *hLLu3 = (TH1D*)fLL->Get("CR2l_jesUp");
  TH1D *hLLd3 = (TH1D*)fLL->Get("CR2l_jesDn");
  TH1D *hLLu4 = (TH1D*)fLL->Get("CR2l_bTagEffHFUp");
  TH1D *hLLd4 = (TH1D*)fLL->Get("CR2l_bTagEffHFDn");
  TH1D *hLLu5 = (TH1D*)fLL->Get("CR2l_bTagEffLFUp");
  TH1D *hLLd5 = (TH1D*)fLL->Get("CR2l_bTagEffLFDn");
  TH1D *hLLu6 = (TH1D*)fLL->Get("CR2l_lepSFUp");
  TH1D *hLLd6 = (TH1D*)fLL->Get("CR2l_lepSFDn");
  TH1D *hLLu7 = (TH1D*)fLL->Get("CR2l_metResUp");
  TH1D *hLLd7 = (TH1D*)fLL->Get("CR2l_metResDn");
  TH1D *hLLu8 = (TH1D*)fLL->Get("CR2l_pdfUp");
  TH1D *hLLd8 = (TH1D*)fLL->Get("CR2l_pdfDn");
  TH1D *hLLu9 = (TH1D*)fLL->Get("CR2l_alphasUp");
  TH1D *hLLd9 = (TH1D*)fLL->Get("CR2l_alphasDn");
  TH1D *hLLu10 = (TH1D*)fLL->Get("CR2l_q2Up");
  TH1D *hLLd10 = (TH1D*)fLL->Get("CR2l_q2Dn");
  TH1D *hLLu11 = (TH1D*)fLL->Get("CR2l_cr2lTriggerSFUp");
  TH1D *hLLd11 = (TH1D*)fLL->Get("CR2l_cr2lTriggerSFDn");
  TH1D *hLLu12 = (TH1D*)fLL->Get("CR2l_ISRUp");
  TH1D *hLLd12 = (TH1D*)fLL->Get("CR2l_ISRDn");
     */

    //TFile *ftt1l = TFile::Open("bkgEst_1lepFromTop__mlb_v2_bins__histos.root");
    //TH1D *htt1lc = (TH1D*)ftt1l->Get("ee1lep_fromTop_yield"); htt1lc->SetName("tt1l");
    TFile *ftt1l = TFile::Open("TT1lSR.root");
    TH1D *htt1lc = (TH1D*)ftt1l->Get("SR_Top"); htt1lc->SetName("tt1l");
    TFile *ftt1lc = TFile::Open("TT1l_BkgEst_compressed.root");
    //TH1D *htt1lcc = (TH1D*)ftt1lc->Get("ee1lep_fromTop_yield"); htt1lcc->SetName("tt1lc");
    TH1D *htt1lcc = (TH1D*)ftt1lc->Get("SR_Top"); htt1lcc->SetName("tt1lc");
    
    TFile *fZtoNuNu = TFile::Open("Znunu_BkgEst_std.root");
    TH1D *hZc = (TH1D*)fZtoNuNu->Get("total");hZc->SetName("hZc");
    TFile *fZtoNuNuc = TFile::Open("Znunu_BkgEst_compressed.root");
    TH1D *hZcc = (TH1D*)fZtoNuNuc->Get("total");hZcc->SetName("hZcc");

    TFile *fW = TFile::Open("Wjets.root");
    TH1D *hWc = (TH1D*)fW->Get("CR1lyield");hWc->SetName("hWc");
    TFile *fWc = TFile::Open("WJets_BkgEst_compressed.root");
    TH1D *hWcc = (TH1D*)fWc->Get("CR1lyield");hWcc->SetName("hWcc");
    
  for(int i = 1; i<=27; ++i){
	double LL = hLLc->GetBinContent(i);
	hLL->SetBinContent(i,LL);
	//double errLLu = sqrt(pow(hLLu1->GetBinContent(i)-LL,2)+pow(hLLu2->GetBinContent(i)-LL,2)+pow(hLLu3->GetBinContent(i)-LL,2)+pow(hLLu4->GetBinContent(i)-LL,2)+pow(hLLu5->GetBinContent(i)-LL,2)+pow(hLLu6->GetBinContent(i)-LL,2)+pow(hLLu7->GetBinContent(i)-LL,2)+pow(hLLu8->GetBinContent(i)-LL,2)+pow(hLLu9->GetBinContent(i)-LL,2)+pow(hLLu10->GetBinContent(i)-LL,2)+pow(hLLu11->GetBinContent(i)-LL,2)+pow(hLLu12->GetBinContent(i)-LL,2));
	//double errLLd = sqrt(pow(hLLd1->GetBinContent(i)-LL,2)+pow(hLLd2->GetBinContent(i)-LL,2)+pow(hLLd3->GetBinContent(i)-LL,2)+pow(hLLd4->GetBinContent(i)-LL,2)+pow(hLLd5->GetBinContent(i)-LL,2)+pow(hLLd6->GetBinContent(i)-LL,2)+pow(hLLd7->GetBinContent(i)-LL,2)+pow(hLLd8->GetBinContent(i)-LL,2)+pow(hLLd9->GetBinContent(i)-LL,2)+pow(hLLd10->GetBinContent(i)-LL,2)+pow(hLLd11->GetBinContent(i)-LL,2)+pow(hLLd12->GetBinContent(i)-LL,2));
      //double errLL = sqrt(errLLu*errLLd);
      double errLL = hLLc->GetBinError(i);
	htt1l->SetBinContent(i,htt1lc->GetBinContent(i));htt1l->SetBinError(i,htt1lc->GetBinContent(i));
	//cout << "LL " << LL << " + " << errLLu << " - " << errLLd << endl;
	hLL->SetBinError(i,errLL);
	double Z = hZc->GetBinContent(i);
	hZ->SetBinContent(i,Z);
      double errZ = hZc->GetBinError(i);
	hZ->SetBinError(i,errZ);
      h0b->SetBinContent(i,hWc->GetBinContent(i));
      h0b->SetBinError(i,hWc->GetBinError(i));
  }
    for(int i = 28; i<=31; ++i){
        int b = i-27;
        hLL->SetBinContent(i,hLLcc->GetBinContent(b));
        hLL->SetBinError  (i,hLLcc->GetBinError(  b));
        htt1l->SetBinContent(i,htt1lcc->GetBinContent(b));htt1l->SetBinError(i,htt1lcc->GetBinContent(b));
        hZ->SetBinContent(i,hZcc->GetBinContent(b));
        hZ->SetBinError  (i,hZcc->GetBinError(  b));
        h0b->SetBinContent(i,hWcc->GetBinContent(b));
        h0b->SetBinError  (i,hWcc->GetBinError(  b));
    }
/*
h0b->SetBinContent( 1,7.95);	h0b->SetBinError( 1,sqrt(pow(0.90,2)+pow(1.89,2)));
h0b->SetBinContent( 2,4.19);	h0b->SetBinError( 2,sqrt(pow(0.65,2)+pow(0.80,2)));
h0b->SetBinContent( 3,2.20);	h0b->SetBinError( 3,sqrt(pow(0.49,2)+pow(0.29,2)));
h0b->SetBinContent( 4,0.81);	h0b->SetBinError( 4,sqrt(pow(0.30,2)+pow(0.07,2)));
h0b->SetBinContent( 5,7.79);	h0b->SetBinError( 5,sqrt(pow(0.72,2)+pow(1.00,2)));
h0b->SetBinContent( 6,2.02);	h0b->SetBinError( 6,sqrt(pow(0.36,2)+pow(0.25,2)));
h0b->SetBinContent( 7,1.16);	h0b->SetBinError( 7,sqrt(pow(0.28,2)+pow(0.09,2)));
h0b->SetBinContent( 8,11.84);	h0b->SetBinError( 8,sqrt(pow(1.87,2)+pow(8.55,2)));
h0b->SetBinContent( 9,2.54);	h0b->SetBinError( 9,sqrt(pow(0.60,2)+pow(1.37,2)));
h0b->SetBinContent(10,0.45);	h0b->SetBinError(10,sqrt(pow(0.22,2)+pow(0.30,2)));
h0b->SetBinContent(11,0.20);	h0b->SetBinError(11,sqrt(pow(0.15,2)+pow(0.06,2)));
h0b->SetBinContent(12,0.66);	h0b->SetBinError(12,sqrt(pow(0.41,2)+pow(0.20,2)));
h0b->SetBinContent(13,8.58);	h0b->SetBinError(13,sqrt(pow(1.17,2)+pow(2.03,2)));
h0b->SetBinContent(14,2.56);	h0b->SetBinError(14,sqrt(pow(0.69,2)+pow(0.54,2)));
h0b->SetBinContent(15,0.83);	h0b->SetBinError(15,sqrt(pow(0.34,2)+pow(0.21,2)));
h0b->SetBinContent(16,0.87);	h0b->SetBinError(16,sqrt(pow(0.32,2)+pow(0.21,2)));
h0b->SetBinContent(17,6.71);	h0b->SetBinError(17,sqrt(pow(2.02,2)+pow(2.32,2)));
h0b->SetBinContent(18,1.60);	h0b->SetBinError(18,sqrt(pow(0.49,2)+pow(0.38,2)));
h0b->SetBinContent(19,0.29);	h0b->SetBinError(19,sqrt(pow(0.22,2)+pow(0.10,2)));
h0b->SetBinContent(20,3.28);	h0b->SetBinError(20,sqrt(pow(0.57,2)+pow(0.55,2)));
h0b->SetBinContent(21,0.26);	h0b->SetBinError(21,sqrt(pow(0.14,2)+pow(0.06,2)));
h0b->SetBinContent(22,1.09);	h0b->SetBinError(22,sqrt(pow(0.48,2)+pow(0.68,2)));
h0b->SetBinContent(23,0.72);	h0b->SetBinError(23,sqrt(pow(0.44,2)+pow(0.15,2)));
h0b->SetBinContent(24,0.67);	h0b->SetBinError(24,sqrt(pow(0.37,2)+pow(0.17,2)));
h0b->SetBinContent(25,0.34);	h0b->SetBinError(25,sqrt(pow(0.34,2)+pow(0.07,2)));
h0b->SetBinContent(26,1.86);	h0b->SetBinError(26,sqrt(pow(0.70,2)+pow(0.21,2)));
h0b->SetBinContent(27,0.60);	h0b->SetBinError(27,sqrt(pow(0.25,2)+pow(0.10,2)));
*/
hbg->Add(h0b);
hbg->Add(hZ);
hbg->Add(htt1l);
hbg->Add(hLL);
/*
hbg->Scale(18.1/36.6);
h0b->Scale(18.1/36.6);
hZ->Scale(18.1/36.6);
htt1l->Scale(18.1/36.6);
hLL->Scale(18.1/36.6);
*/
//vector<int> datavec = {59,20,7,2,2,4,1,256,60,11,5,1,33,6,3,0,53,16,0,5,0, 9, 9,3,1,1,1};
//vector<int> datavec = {48,16,4,2,2,3,1,189,39, 6,5,1,27,5,2,0,42,11,0,4,0, 7, 7,3,0,1,1};
//vector<int> datavec =   {93,32,8,3,7,5,1,398,81,15,8,3,44,9,4,1,72,27,1,7,0,15,14,4,2,1,1};
//  for(int i = 1; i<=27; ++i){
//hdata->SetBinContent(i,datavec[i-1]);
//}

    TFile *fData = TFile::Open("DataSR.root");
    TH1D *hDatac = (TH1D*)fData->Get("SR_Data");hDatac->SetName("bla");
    TFile *fDatac = TFile::Open("DataSR_compressed.root");
    TH1D *hDatacc = (TH1D*)fDatac->Get("SR_Data");hDatacc->SetName("blacc");
    for(int i = 1; i<=27; ++i){
        double d = hDatac->GetBinContent(i);
        double derr = hDatac->GetBinError(i);
        hdata->SetBinContent(i,d);
    }
    for(int i = 28; i<=31; ++i){
        int b = i-27;
        hdata->SetBinContent(i,hDatacc->GetBinContent(b));
    }
    
cout << "\\begin{table}[htb]" << endl;
cout << "\\centering" << endl;
cout << "\\small" << endl;
cout << "\\begin{tabular}{|r|r|r|r|c|c|c|c|c|c|}" << endl;
cout << "\\hline" << endl;
cout << " \\multirow{2}{*}{$N_\\mathrm{J}$} & \\multirow{2}{*}{$t_\\mathrm{mod}$} & $M_\\mathrm{\\ell b}$ & $E_\\mathrm{T}^\\mathrm{miss}$ & Lost  & \\multirow{2}{*}{1$\\ell$ (top)} & 1$\\ell$ (not & \\multirow{2}{*}{$Z\\rightarrow\\nu\\bar{\\nu}$} & Total & \\multirow{2}{*}{Data} \\\\" << endl;
cout << "  &  &  [GeV] &  [GeV] &  lepton &  &  top) &  & background &  \\\\" << endl;
cout << "\\hline" << endl;
    cout << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $250-350$", 1,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $350-450$", 2,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\leq3$ &    $>10$ & $\\leq175$ & $450-600$", 3,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\leq3$ &    $>10$ & $\\leq175$ &    $>600$", 4,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\leq3$ &    $>10$ &     $>175$ & $250-450$", 5,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\leq3$ &    $>10$ &     $>175$ & $450-600$", 6,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\leq3$ &    $>10$ &     $>175$ &    $>600$", 7,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $250-350$", 8,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $350-450$", 9,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $450-550$",10,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ & $550-650$",11,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ & $\\leq175$ &    $>650$",12,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $250-350$",13,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $350-450$",14,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ &     $>175$ & $450-550$",15,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ & $\\leq0$ &     $>175$ &    $>550$",16,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ & $250-350$",17,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ & $350-550$",18,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &   $0-10$ & $\\leq175$ &    $>550$",19,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ &   $0-10$ &     $>175$ & $250-450$",20,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &   $0-10$ &     $>175$ &    $>450$",21,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $250-350$",22,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $350-450$",23,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &    $>10$ & $\\leq175$ & $450-600$",24,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &    $>10$ & $\\leq175$ &    $>600$",25,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << tableline("$\\geq4$ &    $>10$ &     $>175$ & $250-450$",26,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("$\\geq4$ &    $>10$ &     $>175$ &    $>450$",27,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << "\\hline" << endl;
    cout << tableline("\\multicolumn{3}{|l|}{compressed region} & $250-350$",28,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("\\multicolumn{3}{|l|}{compressed region} & $350-450$",29,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("\\multicolumn{3}{|l|}{compressed region} & $450-550$",30,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << tableline("\\multicolumn{3}{|l|}{compressed region} &    $>550$",31,hLL,htt1l,h0b,hZ,hbg,hdata);
    cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    cout << "\\end{table}" << endl;

fresults->cd();
hLL->Write();
htt1l->Write();
hZ->Write();
h0b->Write();
hbg->Write();
hdata->Write();
fresults->Close();
}