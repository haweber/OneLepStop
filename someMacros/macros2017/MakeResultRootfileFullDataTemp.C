{

TFile *fresults = new TFile("resultsforfullDataTemp.root","RECREATE");
TH1D *hdata = new TH1D("rpt_Data","",27,0,27); hdata->Sumw2();
TH1D *hLL = new TH1D("rpt_LLest","",27,0,27); hLL->Sumw2();
TH1D *h0b = new TH1D("rpt_0best","",27,0,27); h0b->Sumw2();
TH1D *hZ = new TH1D("rpt_znunu","",27,0,27); hZ->Sumw2();
TH1D *htt1l = new TH1D("rpt_tt1l","",27,0,27); htt1l->Sumw2();
TH1D *hbg = new TH1D("rpt_bg","",27,0,27); hbg->Sumw2();

TFile *fLL = TFile::Open("bkgEst_lostLepton__mlb_v2_bins__histos.root");

  TH1D *hLLc = (TH1D*)fLL->Get("CR2l_yield");
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

TFile *ftt1l = TFile::Open("bkgEst_1lepFromTop__mlb_v2_bins__histos.root");
TH1D *htt1lc = (TH1D*)ftt1l->Get("ee1lep_fromTop_yield");

TFile *fZtoNuNu = TFile::Open("bkgEst_ZtoNuNu__mlb_v2_bins__histos.root");

  TH1D *hZc = (TH1D*)fZtoNuNu->Get("ZtoNuNu_yield");
  TH1D *hZu1 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_mcStatsUp");
  TH1D *hZd1 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_mcStatsDn");
  TH1D *hZu2 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_jesUp");
  TH1D *hZd2 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_jesDn");
  TH1D *hZu3 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_bTagEffHFUp");
  TH1D *hZd3 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_bTagEffHFDn");
  TH1D *hZu4 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_bTagEffLFUp");
  TH1D *hZd4 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_bTagEffLFDn");
  TH1D *hZu5 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_lepSFUp");
  TH1D *hZd5 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_lepSFDn");
  TH1D *hZu6 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_pdfUp");
  TH1D *hZd6 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_pdfDn");
  TH1D *hZu7 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_alphasUp");
  TH1D *hZd7 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_alphasDn");
  TH1D *hZu8 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_q2Up");
  TH1D *hZd8 = (TH1D*)fZtoNuNu->Get("ZtoNuNu_q2Dn");

  for(int i = 1; i<=27; ++i){
	double LL = hLLc->GetBinContent(i);
	hLL->SetBinContent(i,LL);
	double errLLu = sqrt(pow(hLLu1->GetBinContent(i)-LL,2)+pow(hLLu2->GetBinContent(i)-LL,2)+pow(hLLu3->GetBinContent(i)-LL,2)+pow(hLLu4->GetBinContent(i)-LL,2)+pow(hLLu5->GetBinContent(i)-LL,2)+pow(hLLu6->GetBinContent(i)-LL,2)+pow(hLLu7->GetBinContent(i)-LL,2)+pow(hLLu8->GetBinContent(i)-LL,2)+pow(hLLu9->GetBinContent(i)-LL,2)+pow(hLLu10->GetBinContent(i)-LL,2)+pow(hLLu11->GetBinContent(i)-LL,2)+pow(hLLu12->GetBinContent(i)-LL,2));
	double errLLd = sqrt(pow(hLLd1->GetBinContent(i)-LL,2)+pow(hLLd2->GetBinContent(i)-LL,2)+pow(hLLd3->GetBinContent(i)-LL,2)+pow(hLLd4->GetBinContent(i)-LL,2)+pow(hLLd5->GetBinContent(i)-LL,2)+pow(hLLd6->GetBinContent(i)-LL,2)+pow(hLLd7->GetBinContent(i)-LL,2)+pow(hLLd8->GetBinContent(i)-LL,2)+pow(hLLd9->GetBinContent(i)-LL,2)+pow(hLLd10->GetBinContent(i)-LL,2)+pow(hLLd11->GetBinContent(i)-LL,2)+pow(hLLd12->GetBinContent(i)-LL,2));
	htt1l->SetBinContent(i,htt1lc->GetBinContent(i));htt1l->SetBinError(i,htt1lc->GetBinContent(i));
	//cout << "LL " << LL << " + " << errLLu << " - " << errLLd << endl;
	double errLL = sqrt(errLLu*errLLd);
	hLL->SetBinError(i,errLL);
	double Z = hZc->GetBinContent(i);
	hZ->SetBinContent(i,Z);
	double errZu = sqrt(pow(hZu1->GetBinContent(i)-Z,2)+pow(hZu2->GetBinContent(i)-Z,2)+pow(hZu3->GetBinContent(i)-Z,2)+pow(hZu4->GetBinContent(i)-Z,2)+pow(hZu5->GetBinContent(i)-Z,2)+pow(hZu6->GetBinContent(i)-Z,2)+pow(hZu8->GetBinContent(i)-Z,2)+pow(hZu1->GetBinContent(i)-Z,2));
	double errZd = sqrt(pow(fabs(hZd1->GetBinContent(i))-Z,2)+pow(hZd2->GetBinContent(i)-Z,2)+pow(hZd3->GetBinContent(i)-Z,2)+pow(hZd4->GetBinContent(i)-Z,2)+pow(hZd5->GetBinContent(i)-Z,2)+pow(hZd6->GetBinContent(i)-Z,2)+pow(hZd8->GetBinContent(i)-Z,2)+pow(hZd1->GetBinContent(i)-Z,2));
	double errZ = sqrt(errZu*errZd);
	errZ = (errZu+errZ)/2.;
	//cout << "Z " << Z << " + " << errZu << " - " << errZd <<  " errZ " << errZ << endl;
	hZ->SetBinError(i,errZ);
  }
h0b->SetBinContent( 1,11.62);	h0b->SetBinError( 1,sqrt(pow(1.92,2)+pow(2.58,2)));
h0b->SetBinContent( 2,4.52);	h0b->SetBinError( 2,sqrt(pow(0.71,2)+pow(0.93,2)));
h0b->SetBinContent( 3,2.65);	h0b->SetBinError( 3,sqrt(pow(0.64,2)+pow(0.56,2)));
h0b->SetBinContent( 4,0.53);	h0b->SetBinError( 4,sqrt(pow(0.53,2)+pow(0.06,2)));
h0b->SetBinContent( 5,7.17);	h0b->SetBinError( 5,sqrt(pow(0.65,2)+pow(0.91,2)));
h0b->SetBinContent( 6,1.73);	h0b->SetBinError( 6,sqrt(pow(0.32,2)+pow(0.32,2)));
h0b->SetBinContent( 7,0.90);	h0b->SetBinError( 7,sqrt(pow(0.32,2)+pow(0.15,2)));
h0b->SetBinContent( 8,11.74);	h0b->SetBinError( 8,sqrt(pow(1.60,2)+pow(7.33,2)));
h0b->SetBinContent( 9,3.09);	h0b->SetBinError( 9,sqrt(pow(0.74,2)+pow(1.36,2)));
h0b->SetBinContent(10,0.54);	h0b->SetBinError(10,sqrt(pow(0.27,2)+pow(0.35,2)));
h0b->SetBinContent(11,0.24);	h0b->SetBinError(11,sqrt(pow(0.19,2)+pow(0.13,2)));
h0b->SetBinContent(12,0.39);	h0b->SetBinError(12,sqrt(pow(0.26,2)+pow(0.18,2)));
h0b->SetBinContent(13,11.97);	h0b->SetBinError(13,sqrt(pow(3.53,2)+pow(3.35,2)));
h0b->SetBinContent(14,2.83);	h0b->SetBinError(14,sqrt(pow(1.20,2)+pow(0.61,2)));
h0b->SetBinContent(15,0.63);	h0b->SetBinError(15,sqrt(pow(0.26,2)+pow(0.15,2)));
h0b->SetBinContent(16,0.63);	h0b->SetBinError(16,sqrt(pow(0.23,2)+pow(0.26,2)));
h0b->SetBinContent(17,6.74);	h0b->SetBinError(17,sqrt(pow(1.99,2)+pow(3.96,2)));
h0b->SetBinContent(18,1.70);	h0b->SetBinError(18,sqrt(pow(0.56,2)+pow(0.36,2)));
h0b->SetBinContent(19,0.22);	h0b->SetBinError(19,sqrt(pow(0.18,2)+pow(0.05,2)));
h0b->SetBinContent(20,4.06);	h0b->SetBinError(20,sqrt(pow(1.51,2)+pow(1.04,2)));
h0b->SetBinContent(21,0.21);	h0b->SetBinError(21,sqrt(pow(0.13,2)+pow(0.05,2)));
h0b->SetBinContent(22,1.25);	h0b->SetBinError(22,sqrt(pow(0.83,2)+pow(0.47,2)));
h0b->SetBinContent(23,0.63);	h0b->SetBinError(23,sqrt(pow(0.39,2)+pow(0.32,2)));
h0b->SetBinContent(24,0.73);	h0b->SetBinError(24,sqrt(pow(0.40,2)+pow(0.25,2)));
h0b->SetBinContent(25,0.16);	h0b->SetBinError(25,sqrt(pow(0.17,2)+pow(0.02,2)));
h0b->SetBinContent(26,0.81);	h0b->SetBinError(26,sqrt(pow(0.30,2)+pow(0.17,2)));
h0b->SetBinContent(27,0.53);	h0b->SetBinError(27,sqrt(pow(0.24,2)+pow(0.09,2)));

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
vector<int> datavec =   {93,32,8,3,7,5,1,398,81,15,8,3,44,9,4,1,72,27,1,7,0,15,14,4,2,1,1};
  for(int i = 1; i<=27; ++i){
hdata->SetBinContent(i,datavec[i-1]);
}

cout << "\\begin{table}[htb]" << endl;
cout << "\\centering" << endl;
cout << "\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|}" << endl;
cout << "\\hline" << endl;
cout << " \\multirow{2}{*}{$N_\\mathrm{J}$} & \\multirow{2}{*}{$t_\\mathrm{mod}$} & $M_\\mathrm{\\ell b}$ & $E_\\mathrm{T}^\\mathrm{miss}$ & Lost  & \\multirow{2}{*}{1$\\ell$ (top)} & 1$\\ell$ (not & \\multirow{2}{*}{$Z\\rightarrow\\nu\\bar{\\nu}$} & Total & \\multirow{2}{*}{Data} \\\\" << endl;
cout << "  &  &  [GeV] &  [GeV] &  lepton &  &  top) &  & background &  \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\leq3$ & $>10$ & $\\leq175$ & $250-350$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 1) << "$\\pm$" << hLL->GetBinError( 1) << " & " << htt1l->GetBinContent( 1) << "$\\pm$" << htt1l->GetBinError( 1) << " & " << h0b->GetBinContent( 1) << "$\\pm$" << h0b->GetBinError( 1) << " & " << hZ->GetBinContent( 1) << "$\\pm$" << hZ->GetBinError( 1) << " & " << hbg->GetBinContent( 1) << "$\\pm$" << hbg->GetBinError( 1) << " & " << (int)hdata->GetBinContent( 1) << " \\\\" << endl;
cout << "$\\leq3$ & $>10$ & $\\leq175$ & $350-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 2) << "$\\pm$" << hLL->GetBinError( 2) << " & " << htt1l->GetBinContent( 2) << "$\\pm$" << htt1l->GetBinError( 2) << " & " << h0b->GetBinContent( 2) << "$\\pm$" << h0b->GetBinError( 2) << " & " << hZ->GetBinContent( 2) << "$\\pm$" << hZ->GetBinError( 2) << " & " << hbg->GetBinContent( 2) << "$\\pm$" << hbg->GetBinError( 2) << " & " << (int)hdata->GetBinContent( 2) << " \\\\" << endl;
cout << "$\\leq3$ & $>10$ & $\\leq175$ & $450-600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 3) << "$\\pm$" << hLL->GetBinError( 3) << " & " << htt1l->GetBinContent( 3) << "$\\pm$" << htt1l->GetBinError( 3) << " & " << h0b->GetBinContent( 3) << "$\\pm$" << h0b->GetBinError( 3) << " & " << hZ->GetBinContent( 3) << "$\\pm$" << hZ->GetBinError( 3) << " & " << hbg->GetBinContent( 3) << "$\\pm$" << hbg->GetBinError( 3) << " & " << (int)hdata->GetBinContent( 3) << " \\\\" << endl;
cout << "$\\leq3$ & $>10$ & $\\leq175$ & $>600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 4) << "$\\pm$" << hLL->GetBinError( 4) << " & " << htt1l->GetBinContent( 4) << "$\\pm$" << htt1l->GetBinError( 4) << " & " << h0b->GetBinContent( 4) << "$\\pm$" << h0b->GetBinError( 4) << " & " << hZ->GetBinContent( 4) << "$\\pm$" << hZ->GetBinError( 4) << " & " << hbg->GetBinContent( 4) << "$\\pm$" << hbg->GetBinError( 4) << " & " << (int)hdata->GetBinContent( 4) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\leq3$ & $>10$ & $>175$ & $250-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 5) << "$\\pm$" << hLL->GetBinError( 5) << " & " << htt1l->GetBinContent( 5) << "$\\pm$" << htt1l->GetBinError( 5) << " & " << h0b->GetBinContent( 5) << "$\\pm$" << h0b->GetBinError( 5) << " & " << hZ->GetBinContent( 5) << "$\\pm$" << hZ->GetBinError( 5) << " & " << hbg->GetBinContent( 5) << "$\\pm$" << hbg->GetBinError( 5) << " & " << (int)hdata->GetBinContent( 5) << " \\\\" << endl;
cout << "$\\leq3$ & $>10$ & $>175$ & $450-600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 6) << "$\\pm$" << hLL->GetBinError( 6) << " & " << htt1l->GetBinContent( 6) << "$\\pm$" << htt1l->GetBinError( 6) << " & " << h0b->GetBinContent( 6) << "$\\pm$" << h0b->GetBinError( 6) << " & " << hZ->GetBinContent( 6) << "$\\pm$" << hZ->GetBinError( 6) << " & " << hbg->GetBinContent( 6) << "$\\pm$" << hbg->GetBinError( 6) << " & " << (int)hdata->GetBinContent( 6) << " \\\\" << endl;
cout << "$\\leq3$ & $>10$ & $>175$ & $>600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent( 7) << "$\\pm$" << hLL->GetBinError( 7) << " & " << htt1l->GetBinContent( 7) << "$\\pm$" << htt1l->GetBinError( 7) << " & " << h0b->GetBinContent( 7) << "$\\pm$" << h0b->GetBinError( 7) << " & " << hZ->GetBinContent( 7) << "$\\pm$" << hZ->GetBinError( 7) << " & " << hbg->GetBinContent( 7) << "$\\pm$" << hbg->GetBinError( 7) << " & " << (int)hdata->GetBinContent( 7) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $\\leq0$ & $\\leq175$ & $250-350$ & " 	<< fixed << setprecision(2) << hLL->GetBinContent( 8) << "$\\pm$" << hLL->GetBinError( 8) << " & " << htt1l->GetBinContent( 8) << "$\\pm$" << htt1l->GetBinError( 8) << " & " << h0b->GetBinContent( 8) << "$\\pm$" << h0b->GetBinError( 8) << " & " << hZ->GetBinContent( 8) << "$\\pm$" << hZ->GetBinError( 8) << " & " << hbg->GetBinContent( 8) << "$\\pm$" << hbg->GetBinError( 8) << " & " << (int)hdata->GetBinContent( 8) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $\\leq175$ & $350-450$ & " 	<< fixed << setprecision(2) << hLL->GetBinContent( 9) << "$\\pm$" << hLL->GetBinError( 9) << " & " << htt1l->GetBinContent( 9) << "$\\pm$" << htt1l->GetBinError( 9) << " & " << h0b->GetBinContent( 9) << "$\\pm$" << h0b->GetBinError( 9) << " & " << hZ->GetBinContent( 9) << "$\\pm$" << hZ->GetBinError( 9) << " & " << hbg->GetBinContent( 9) << "$\\pm$" << hbg->GetBinError( 9) << " & " << (int)hdata->GetBinContent( 9) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $\\leq175$ & $450-550$ & " 	<< fixed << setprecision(2) << hLL->GetBinContent(10) << "$\\pm$" << hLL->GetBinError(10) << " & " << htt1l->GetBinContent(10) << "$\\pm$" << htt1l->GetBinError(10) << " & " << h0b->GetBinContent(10) << "$\\pm$" << h0b->GetBinError(10) << " & " << hZ->GetBinContent(10) << "$\\pm$" << hZ->GetBinError(10) << " & " << hbg->GetBinContent(10) << "$\\pm$" << hbg->GetBinError(10) << " & " << (int)hdata->GetBinContent(10) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $\\leq175$ & $550-650$ & " 	<< fixed << setprecision(2) << hLL->GetBinContent(11) << "$\\pm$" << hLL->GetBinError(11) << " & " << htt1l->GetBinContent(11) << "$\\pm$" << htt1l->GetBinError(11) << " & " << h0b->GetBinContent(11) << "$\\pm$" << h0b->GetBinError(11) << " & " << hZ->GetBinContent(11) << "$\\pm$" << hZ->GetBinError(11) << " & " << hbg->GetBinContent(11) << "$\\pm$" << hbg->GetBinError(11) << " & " << (int)hdata->GetBinContent(11) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $\\leq175$ & $>650$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(12) << "$\\pm$" << hLL->GetBinError(12) << " & " << htt1l->GetBinContent(12) << "$\\pm$" << htt1l->GetBinError(12) << " & " << h0b->GetBinContent(12) << "$\\pm$" << h0b->GetBinError(12) << " & " << hZ->GetBinContent(12) << "$\\pm$" << hZ->GetBinError(12) << " & " << hbg->GetBinContent(12) << "$\\pm$" << hbg->GetBinError(12) << " & " << (int)hdata->GetBinContent(12) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $\\leq0$ & $>175$ & $250-350$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(13) << "$\\pm$" << hLL->GetBinError(13) << " & " << htt1l->GetBinContent(13) << "$\\pm$" << htt1l->GetBinError(13) << " & " << h0b->GetBinContent(13) << "$\\pm$" << h0b->GetBinError(13) << " & " << hZ->GetBinContent(13) << "$\\pm$" << hZ->GetBinError(13) << " & " << hbg->GetBinContent(13) << "$\\pm$" << hbg->GetBinError(13) << " & " << (int)hdata->GetBinContent(13) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $>175$ & $350-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(14) << "$\\pm$" << hLL->GetBinError(14) << " & " << htt1l->GetBinContent(14) << "$\\pm$" << htt1l->GetBinError(14) << " & " << h0b->GetBinContent(14) << "$\\pm$" << h0b->GetBinError(14) << " & " << hZ->GetBinContent(14) << "$\\pm$" << hZ->GetBinError(14) << " & " << hbg->GetBinContent(14) << "$\\pm$" << hbg->GetBinError(14) << " & " << (int)hdata->GetBinContent(14) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $>175$ & $450-550$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(15) << "$\\pm$" << hLL->GetBinError(15) << " & " << htt1l->GetBinContent(15) << "$\\pm$" << htt1l->GetBinError(15) << " & " << h0b->GetBinContent(15) << "$\\pm$" << h0b->GetBinError(15) << " & " << hZ->GetBinContent(15) << "$\\pm$" << hZ->GetBinError(15) << " & " << hbg->GetBinContent(15) << "$\\pm$" << hbg->GetBinError(15) << " & " << (int)hdata->GetBinContent(15) << " \\\\" << endl;
cout << "$\\geq4$ & $\\leq0$ & $>175$ & $>550$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(16) << "$\\pm$" << hLL->GetBinError(16) << " & " << htt1l->GetBinContent(16) << "$\\pm$" << htt1l->GetBinError(16) << " & " << h0b->GetBinContent(16) << "$\\pm$" << h0b->GetBinError(16) << " & " << hZ->GetBinContent(16) << "$\\pm$" << hZ->GetBinError(16) << " & " << hbg->GetBinContent(16) << "$\\pm$" << hbg->GetBinError(16) << " & " << (int)hdata->GetBinContent(16) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $0-10$ & $\\leq175$ & $250-350$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(17) << "$\\pm$" << hLL->GetBinError(17) << " & " << htt1l->GetBinContent(17) << "$\\pm$" << htt1l->GetBinError(17) << " & " << h0b->GetBinContent(17) << "$\\pm$" << h0b->GetBinError(17) << " & " << hZ->GetBinContent(17) << "$\\pm$" << hZ->GetBinError(17) << " & " << hbg->GetBinContent(17) << "$\\pm$" << hbg->GetBinError(17) << " & " << (int)hdata->GetBinContent(17) << " \\\\" << endl;
cout << "$\\geq4$ & $0-10$ & $\\leq175$ & $350-550$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(18) << "$\\pm$" << hLL->GetBinError(18) << " & " << htt1l->GetBinContent(18) << "$\\pm$" << htt1l->GetBinError(18) << " & " << h0b->GetBinContent(18) << "$\\pm$" << h0b->GetBinError(18) << " & " << hZ->GetBinContent(18) << "$\\pm$" << hZ->GetBinError(18) << " & " << hbg->GetBinContent(18) << "$\\pm$" << hbg->GetBinError(18) << " & " << (int)hdata->GetBinContent(18) << " \\\\" << endl;
cout << "$\\geq4$ & $0-10$ & $\\leq175$ & $>550$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(19) << "$\\pm$" << hLL->GetBinError(19) << " & " << htt1l->GetBinContent(19) << "$\\pm$" << htt1l->GetBinError(19) << " & " << h0b->GetBinContent(19) << "$\\pm$" << h0b->GetBinError(19) << " & " << hZ->GetBinContent(19) << "$\\pm$" << hZ->GetBinError(19) << " & " << hbg->GetBinContent(19) << "$\\pm$" << hbg->GetBinError(19) << " & " << (int)hdata->GetBinContent(19) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $0-10$ & $>175$ & $250-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(20) << "$\\pm$" << hLL->GetBinError(20) << " & " << htt1l->GetBinContent(20) << "$\\pm$" << htt1l->GetBinError(20) << " & " << h0b->GetBinContent(20) << "$\\pm$" << h0b->GetBinError(20) << " & " << hZ->GetBinContent(20) << "$\\pm$" << hZ->GetBinError(20) << " & " << hbg->GetBinContent(20) << "$\\pm$" << hbg->GetBinError(20) << " & " << (int)hdata->GetBinContent(20) << " \\\\" << endl;
cout << "$\\geq4$ & $0-10$ & $>175$ & $>450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(21) << "$\\pm$" << hLL->GetBinError(21) << " & " << htt1l->GetBinContent(21) << "$\\pm$" << htt1l->GetBinError(21) << " & " << h0b->GetBinContent(21) << "$\\pm$" << h0b->GetBinError(21) << " & " << hZ->GetBinContent(21) << "$\\pm$" << hZ->GetBinError(21) << " & " << hbg->GetBinContent(21) << "$\\pm$" << hbg->GetBinError(21) << " & " << (int)hdata->GetBinContent(21) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $>10$ & $\\leq175$ & $250-350$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(22) << "$\\pm$" << hLL->GetBinError(22) << " & " << htt1l->GetBinContent(22) << "$\\pm$" << htt1l->GetBinError(22) << " & " << h0b->GetBinContent(22) << "$\\pm$" << h0b->GetBinError(22) << " & " << hZ->GetBinContent(22) << "$\\pm$" << hZ->GetBinError(22) << " & " << hbg->GetBinContent(22) << "$\\pm$" << hbg->GetBinError(22) << " & " << (int)hdata->GetBinContent(22) << " \\\\" << endl;
cout << "$\\geq4$ & $>10$ & $\\leq175$ & $350-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(23) << "$\\pm$" << hLL->GetBinError(23) << " & " << htt1l->GetBinContent(23) << "$\\pm$" << htt1l->GetBinError(23) << " & " << h0b->GetBinContent(23) << "$\\pm$" << h0b->GetBinError(23) << " & " << hZ->GetBinContent(23) << "$\\pm$" << hZ->GetBinError(23) << " & " << hbg->GetBinContent(23) << "$\\pm$" << hbg->GetBinError(23) << " & " << (int)hdata->GetBinContent(23) << " \\\\" << endl;
cout << "$\\geq4$ & $>10$ & $\\leq175$ & $450-600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(24) << "$\\pm$" << hLL->GetBinError(24) << " & " << htt1l->GetBinContent(24) << "$\\pm$" << htt1l->GetBinError(24) << " & " << h0b->GetBinContent(24) << "$\\pm$" << h0b->GetBinError(24) << " & " << hZ->GetBinContent(24) << "$\\pm$" << hZ->GetBinError(24) << " & " << hbg->GetBinContent(24) << "$\\pm$" << hbg->GetBinError(24) << " & " << (int)hdata->GetBinContent(24) << " \\\\" << endl;
cout << "$\\geq4$ & $>10$ & $\\leq175$ & $>600$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(25) << "$\\pm$" << hLL->GetBinError(25) << " & " << htt1l->GetBinContent(25) << "$\\pm$" << htt1l->GetBinError(25) << " & " << h0b->GetBinContent(25) << "$\\pm$" << h0b->GetBinError(25) << " & " << hZ->GetBinContent(25) << "$\\pm$" << hZ->GetBinError(25) << " & " << hbg->GetBinContent(25) << "$\\pm$" << hbg->GetBinError(25) << " & " << (int)hdata->GetBinContent(25) << " \\\\" << endl;
cout << "\\hline" << endl;
cout << "$\\geq4$ & $>10$ & $>175$ & $250-450$ & " 		<< fixed << setprecision(2) << hLL->GetBinContent(26) << "$\\pm$" << hLL->GetBinError(26) << " & " << htt1l->GetBinContent(26) << "$\\pm$" << htt1l->GetBinError(26) << " & " << h0b->GetBinContent(26) << "$\\pm$" << h0b->GetBinError(26) << " & " << hZ->GetBinContent(26) << "$\\pm$" << hZ->GetBinError(26) << " & " << hbg->GetBinContent(26) << "$\\pm$" << hbg->GetBinError(26) << " & " << (int)hdata->GetBinContent(26) << " \\\\" << endl;
cout << "$\\geq4$ & $>10$ & $>175$ & $>450$ & " 			<< fixed << setprecision(2) << hLL->GetBinContent(27) << "$\\pm$" << hLL->GetBinError(27) << " & " << htt1l->GetBinContent(27) << "$\\pm$" << htt1l->GetBinError(27) << " & " << h0b->GetBinContent(27) << "$\\pm$" << h0b->GetBinError(27) << " & " << hZ->GetBinContent(27) << "$\\pm$" << hZ->GetBinError(27) << " & " << hbg->GetBinContent(27) << "$\\pm$" << hbg->GetBinError(27) << " & " << (int)hdata->GetBinContent(27) << " \\\\" << endl;
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