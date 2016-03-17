{

TFile *_file0 = TFile::Open("CheckResolutionNew_TTbar.root");

    TH1F *MET_3j_res20 = (TH1F*)_file0->Get("MET_3j_res20_TTbar1l");
    TH1F *MET_2j_res20 = (TH1F*)_file0->Get("MET_2j_res20_TTbar1l");
TH1F *MET_lowMT2W_res20 = (TH1F*)_file0->Get("MET_lowMT2W_res20_TTbar1l");
TH1F *MET_highMT2W_res20 = (TH1F*)_file0->Get("MET_highMT2W_res20_TTbar1l");
    TH1F *MET_3j_res15 = (TH1F*)_file0->Get("MET_3j_res15_TTbar1l");
    TH1F *MET_2j_res15 = (TH1F*)_file0->Get("MET_2j_res15_TTbar1l");
TH1F *MET_lowMT2W_res15 = (TH1F*)_file0->Get("MET_lowMT2W_res15_TTbar1l");
TH1F *MET_highMT2W_res15 = (TH1F*)_file0->Get("MET_highMT2W_res15_TTbar1l");
    TH1F *MET_3j_res10 = (TH1F*)_file0->Get("MET_3j_res10_TTbar1l");
    TH1F *MET_2j_res10 = (TH1F*)_file0->Get("MET_2j_res10_TTbar1l");
TH1F *MET_lowMT2W_res10 = (TH1F*)_file0->Get("MET_lowMT2W_res10_TTbar1l");
TH1F *MET_highMT2W_res10 = (TH1F*)_file0->Get("MET_highMT2W_res10_TTbar1l");
    TH1F *MET_3j = (TH1F*)_file0->Get("MET_3j_TTbar1l");
    TH1F *MET_2j = (TH1F*)_file0->Get("MET_2j_TTbar1l");
TH1F *MET_lowMT2W = (TH1F*)_file0->Get("MET_lowMT2W_TTbar1l");
TH1F *MET_highMT2W = (TH1F*)_file0->Get("MET_highMT2W_TTbar1l");
cout << __LINE__ << endl;
int b250 = MET_3j->FindBin(251);
int u325 = MET_3j->FindBin(324);
int b325 = MET_3j->FindBin(326);
int u350 = MET_3j->FindBin(349);
int b350 = MET_3j->FindBin(351);
int u450 = MET_3j->FindBin(449);
int b450 = MET_3j->FindBin(451);
int lbin = MET_3j->FindBin(499);
double err;

      cout << "*********************************************************************" << endl;
      cout << "\%BEGINLATEX\%"             << endl;
      cout << "\\begin{table}"             << endl
		  << "\\begin{center}"            << endl
		  << "\\small"                    << endl;
      cout << "\\begin{tabular}{|l|r|c|c|c|c|}"    << endl;	     
      cout << "\\hline"                    << endl;
	cout << "region & $E_\\mathrm{T}^\\mathrm{miss}$ [GeV] & nominal & 10\\% worse & 15\\% worse & 20\\% worse \\\\ " << endl << "\\hline" << endl
    << "2 jets & 250--350 & " << fixed << setprecision(2)
    << MET_2j->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_2j_res10->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & "
    << MET_2j_res15->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_2j_res20->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " \\\\ " << endl
    << "2 jets & $>350$ & " << fixed << setprecision(2)
    << MET_2j->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & " << MET_2j_res10->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & "
    << MET_2j_res15->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & " << MET_2j_res20->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " \\\\ " << endl
            << "\\hline" << endl << "3 jets & 250--350 & " << fixed << setprecision(2)
            << MET_3j->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_3j_res10->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & "
            << MET_3j_res15->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_3j_res20->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "3 jets & $>350$ & " << fixed << setprecision(2)
		<< MET_3j->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & " << MET_3j_res10->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & " 
		<< MET_3j_res15->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " & " << MET_3j_res20->IntegralAndError(b350,lbin,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "\\hline" << endl << "$\\geq4$ jets, low $M_\\mathrm{T2}^\\mathrm{W}$ & 250--325 & " 
		<< MET_lowMT2W->IntegralAndError(b250,u325,err) << "$\\pm$" << err << " & " << MET_lowMT2W_res10->IntegralAndError(b250,u325,err) << "$\\pm$" << err << " & " 
		<< MET_lowMT2W_res15->IntegralAndError(b250,u325,err) << "$\\pm$" << err << " & " << MET_lowMT2W_res20->IntegralAndError(b250,u325,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "$\\geq4$ jets, low $M_\\mathrm{T2}^\\mathrm{W}$ & $>325$ & " 
		<< MET_lowMT2W->IntegralAndError(b325,lbin,err) << "$\\pm$" << err << " & " << MET_lowMT2W_res10->IntegralAndError(b325,lbin,err) << "$\\pm$" << err << " & " 
		<< MET_lowMT2W_res15->IntegralAndError(b325,lbin,err) << "$\\pm$" << err << " & " << MET_lowMT2W_res20->IntegralAndError(b325,lbin,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "\\hline" << endl << "$\\geq4$ jets, high $M_\\mathrm{T2}^\\mathrm{W}$ & 250--350 & " 
		<< MET_highMT2W->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_highMT2W_res10->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " 
		<< MET_highMT2W_res15->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " & " << MET_highMT2W_res20->IntegralAndError(b250,u350,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "$\\geq4$ jets, high $M_\\mathrm{T2}^\\mathrm{W}$ & 350--450 & " 
		<< MET_highMT2W->IntegralAndError(b350,u450,err) << "$\\pm$" << err << " & " << MET_highMT2W_res10->IntegralAndError(b350,u450,err) << "$\\pm$" << err << " & " 
		<< MET_highMT2W_res15->IntegralAndError(b350,u450,err) << "$\\pm$" << err << " & " << MET_highMT2W_res20->IntegralAndError(b350,u450,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "$\\geq4$ jets, high $M_\\mathrm{T2}^\\mathrm{W}$ & $>450$ & " 
		<< MET_highMT2W->IntegralAndError(b450,lbin,err) << "$\\pm$" << err << " & " << MET_highMT2W_res10->IntegralAndError(b450,lbin,err) << "$\\pm$" << err << " & " 
		<< MET_highMT2W_res15->IntegralAndError(b450,lbin,err) << "$\\pm$" << err << " & " << MET_highMT2W_res20->IntegralAndError(b450,lbin,err) << "$\\pm$" << err << " \\\\ " << endl
		<< "\\hline" << endl
	      << "\\end{tabular}" << endl
	      << "\\end{center}"  << endl
	      << "\\end{table}"   << endl
	      << "\%ENDLATEX\%"   << endl
	      << endl;


   TCanvas *c1 = new TCanvas("c1", "",334,217,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   //c1->Range(-116.8831,-4.861091,532.4675,0.0498308);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   //c1->SetLogy();
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

    MET_2j      ->SetLineColor(kBlack); MET_2j      ->SetMarkerColor(kBlack);  MET_2j      ->SetLineWidth(2);
    MET_3j      ->SetLineColor(kBlack); MET_3j      ->SetMarkerColor(kBlack);  MET_3j      ->SetLineWidth(2);
   MET_lowMT2W ->SetLineColor(kBlack); MET_lowMT2W ->SetMarkerColor(kBlack);  MET_lowMT2W ->SetLineWidth(2);
   MET_highMT2W->SetLineColor(kBlack); MET_highMT2W->SetMarkerColor(kBlack);  MET_highMT2W->SetLineWidth(2);

    MET_2j_res10      ->SetLineColor(kRed+1); MET_2j_res10      ->SetMarkerColor(kRed+1);  MET_2j_res10      ->SetLineWidth(2);
    MET_3j_res10      ->SetLineColor(kRed+1); MET_3j_res10      ->SetMarkerColor(kRed+1);  MET_3j_res10      ->SetLineWidth(2);
   MET_lowMT2W_res10 ->SetLineColor(kRed+1); MET_lowMT2W_res10 ->SetMarkerColor(kRed+1);  MET_lowMT2W_res10 ->SetLineWidth(2);
   MET_highMT2W_res10->SetLineColor(kRed+1); MET_highMT2W_res10->SetMarkerColor(kRed+1);  MET_highMT2W_res10->SetLineWidth(2);

    MET_2j_res15      ->SetLineColor(kCyan+1); MET_2j_res15      ->SetMarkerColor(kCyan+1);  MET_2j_res15      ->SetLineWidth(2);
    MET_3j_res15      ->SetLineColor(kCyan+1); MET_3j_res15      ->SetMarkerColor(kCyan+1);  MET_3j_res15      ->SetLineWidth(2);
   MET_lowMT2W_res15 ->SetLineColor(kCyan+1); MET_lowMT2W_res15 ->SetMarkerColor(kCyan+1);  MET_lowMT2W_res15 ->SetLineWidth(2);
   MET_highMT2W_res15->SetLineColor(kCyan+1); MET_highMT2W_res15->SetMarkerColor(kCyan+1);  MET_highMT2W_res15->SetLineWidth(2);

    MET_2j_res20      ->SetLineColor(kGreen+1); MET_2j_res20      ->SetMarkerColor(kGreen+1);  MET_2j_res20      ->SetLineWidth(2);
    MET_3j_res20      ->SetLineColor(kGreen+1); MET_3j_res20      ->SetMarkerColor(kGreen+1);  MET_3j_res20      ->SetLineWidth(2);
   MET_lowMT2W_res20 ->SetLineColor(kGreen+1); MET_lowMT2W_res20 ->SetMarkerColor(kGreen+1);  MET_lowMT2W_res20 ->SetLineWidth(2);
   MET_highMT2W_res20->SetLineColor(kGreen+1); MET_highMT2W_res20->SetMarkerColor(kGreen+1);  MET_highMT2W_res20->SetLineWidth(2);
    


    MET_2j_res20->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
    MET_2j_res20->GetXaxis()->SetLabelFont(42);
    MET_2j_res20->GetXaxis()->SetLabelSize(0.035);
    MET_2j_res20->GetXaxis()->SetTitleSize(0.05);
    MET_2j_res20->GetXaxis()->SetTitleFont(42);
    MET_2j_res20->GetYaxis()->SetTitle("events / 25 GeV");
    MET_2j_res20->GetYaxis()->SetLabelFont(42);
    MET_2j_res20->GetYaxis()->SetLabelSize(0.035);
    MET_2j_res20->GetYaxis()->SetTitleSize(0.05);
    MET_2j_res20->GetYaxis()->SetTitleOffset(1.2);
    MET_2j_res20->GetYaxis()->SetTitleFont(42);
    MET_2j_res20->GetZaxis()->SetLabelFont(42);
    MET_2j_res20->Rebin(2);
    MET_2j_res15->Rebin(2);
    MET_2j_res10->Rebin(2);
    MET_2j      ->Rebin(2);
    MET_2j_res20->SetMaximum(1.35*MET_2j_res20->GetMaximum());
    //MET_2j_res20->GetXaxis()->SetRangeUser(250,500);
    
    
   MET_3j_res20->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
   MET_3j_res20->GetXaxis()->SetLabelFont(42);
   MET_3j_res20->GetXaxis()->SetLabelSize(0.035);
   MET_3j_res20->GetXaxis()->SetTitleSize(0.05);
   MET_3j_res20->GetXaxis()->SetTitleFont(42);
   MET_3j_res20->GetYaxis()->SetTitle("events / 25 GeV");
   MET_3j_res20->GetYaxis()->SetLabelFont(42);
   MET_3j_res20->GetYaxis()->SetLabelSize(0.035);
   MET_3j_res20->GetYaxis()->SetTitleSize(0.05);
   MET_3j_res20->GetYaxis()->SetTitleOffset(1.2);
   MET_3j_res20->GetYaxis()->SetTitleFont(42);
   MET_3j_res20->GetZaxis()->SetLabelFont(42);
   MET_3j_res20->Rebin(2);
   MET_3j_res15->Rebin(2);
   MET_3j_res10->Rebin(2);
   MET_3j      ->Rebin(2);
   MET_3j_res20->SetMaximum(1.35*MET_3j_res20->GetMaximum());
   //MET_3j_res20->GetXaxis()->SetRangeUser(250,500);

   MET_lowMT2W_res20->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
   MET_lowMT2W_res20->GetXaxis()->SetLabelFont(42);
   MET_lowMT2W_res20->GetXaxis()->SetLabelSize(0.035);
   MET_lowMT2W_res20->GetXaxis()->SetTitleSize(0.05);
   MET_lowMT2W_res20->GetXaxis()->SetTitleFont(42);
    MET_lowMT2W_res20->GetYaxis()->SetTitle("events / 25 GeV");
    MET_lowMT2W_res20->GetYaxis()->SetTitle("events / 50 GeV");
   MET_lowMT2W_res20->GetYaxis()->SetLabelFont(42);
   MET_lowMT2W_res20->GetYaxis()->SetLabelSize(0.035);
   MET_lowMT2W_res20->GetYaxis()->SetTitleSize(0.05);
   MET_lowMT2W_res20->GetYaxis()->SetTitleOffset(1.2);
   MET_lowMT2W_res20->GetYaxis()->SetTitleFont(42);
   MET_lowMT2W_res20->GetZaxis()->SetLabelFont(42);
   MET_lowMT2W_res20->SetMaximum(1.35*MET_lowMT2W_res20->GetMaximum());
   //MET_lowMT2W_res20->GetXaxis()->SetRangeUser(250,500);

   MET_highMT2W_res20->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
   MET_highMT2W_res20->GetXaxis()->SetLabelFont(42);
   MET_highMT2W_res20->GetXaxis()->SetLabelSize(0.035);
   MET_highMT2W_res20->GetXaxis()->SetTitleSize(0.05);
   MET_highMT2W_res20->GetXaxis()->SetTitleFont(42);
   MET_highMT2W_res20->GetYaxis()->SetTitle("events / 25 GeV");
   MET_highMT2W_res20->GetYaxis()->SetLabelFont(42);
   MET_highMT2W_res20->GetYaxis()->SetLabelSize(0.035);
   MET_highMT2W_res20->GetYaxis()->SetTitleSize(0.05);
   MET_highMT2W_res20->GetYaxis()->SetTitleOffset(1.2);
   MET_highMT2W_res20->GetYaxis()->SetTitleFont(42);
   MET_highMT2W_res20->GetZaxis()->SetLabelFont(42);
   MET_highMT2W_res20->SetMaximum(1.35*MET_highMT2W_res20->GetMaximum());
   //MET_highMT2W_res20->GetXaxis()->SetRangeUser(250,500);
    
    double binnew[7] = {150,150.1,200,250,350,450,500};
    MET_2j_res20->Rebin(2,"MET_2j_res20",binnew);
    MET_2j_res15->Rebin(2,"MET_2j_res15",binnew);
    MET_2j_res10->Rebin(2,"MET_2j_res10",binnew);
    MET_2j      ->Rebin(2,"MET_2j",binnew);
    
    MET_3j_res20->Rebin(2,"MET_3j_res20",binnew);
    MET_3j_res15->Rebin(2,"MET_3j_res15",binnew);
    MET_3j_res10->Rebin(2,"MET_3j_res10",binnew);
    MET_3j      ->Rebin(2,"MET_3j",binnew);
    
    MET_lowMT2W_res20->Rebin(2,"MET_lowMT2W_res20",binnew);
    MET_lowMT2W_res15->Rebin(2,"MET_lowMT2W_res15",binnew);
    MET_lowMT2W_res10->Rebin(2,"MET_lowMT2W_res10",binnew);
    MET_lowMT2W      ->Rebin(2,"MET_lowMT2W",binnew);
    
    MET_highMT2W_res20->Rebin(2,"MET_highMT2W_res20",binnew);
    MET_highMT2W_res15->Rebin(2,"MET_highMT2W_res15",binnew);
    MET_highMT2W_res10->Rebin(2,"MET_highMT2W_res10",binnew);
    MET_highMT2W      ->Rebin(2,"MET_highMT2W",binnew);
    

    MET_lowMT2W_res20->Rebin(2);
    MET_lowMT2W_res15->Rebin(2);
    MET_lowMT2W_res10->Rebin(2);
    MET_lowMT2W      ->Rebin(2);
    //MET_lowMT2W_res20->Scale(1./MET_lowMT2W_res20->Integral(MET_2j_res20->FindBin(251),MET_2j_res20->FindBin(499)));
    //MET_lowMT2W_res15->Scale(1./MET_lowMT2W_res15->Integral(MET_2j_res20->FindBin(251),MET_2j_res20->FindBin(499)));
    //MET_lowMT2W_res10->Scale(1./MET_lowMT2W_res10->Integral(MET_2j_res20->FindBin(251),MET_2j_res20->FindBin(499)));
    //MET_lowMT2W->Scale(1./MET_lowMT2W->Integral(MET_2j_res20->FindBin(251),MET_2j_res20->FindBin(499)));
    MET_lowMT2W_res20->GetXaxis()->SetRangeUser(250.,500);
    MET_highMT2W_res20->GetXaxis()->SetRangeUser(250.,500);
    MET_3j_res20->GetXaxis()->SetRangeUser(250.,500);
    MET_2j_res20->GetXaxis()->SetRangeUser(250.,500);
    MET_lowMT2W_res20->SetMaximum(2);

    
   TLegend *leg = new TLegend(0.5,0.6793313,0.7742475,0.8966565,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04181185);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(MET_3j,        "nominal E_{T}^{miss} res.", "lep");
   leg->AddEntry(MET_3j_res10,"10% worse E_{T}^{miss} res.", "lep");
   leg->AddEntry(MET_3j_res15,"15% worse E_{T}^{miss} res.", "lep");
   leg->AddEntry(MET_3j_res20,"20% worse E_{T}^{miss} res.", "lep");
   TLatex *texs = new TLatex(0.95,0.944,"2.3 fb^{-1} (13 TeV)");
   texs->SetNDC();
   texs->SetTextAlign(31);
   texs->SetTextFont(42);
   texs->SetTextSize(0.042);
   texs->SetLineWidth(2);
   TLatex *texc = new TLatex(0.21465,0.9027,"CMS");
   texc->SetNDC();
   texc->SetTextAlign(13);
   texc->SetTextFont(61);
   texc->SetTextSize(0.0525);
   texc->SetLineWidth(2);   texc->Draw();
   TLatex *texp = new TLatex(0.21465,0.8397,"Simulation");
   texp->SetNDC();
   texp->SetTextAlign(13);
   texp->SetTextFont(52);
   texp->SetTextSize(0.0399);
   texp->SetLineWidth(2);

   MET_lowMT2W_res20->Draw("");
   MET_lowMT2W_res15->Draw("same");
   MET_lowMT2W_res10->Draw("same");
   MET_lowMT2W->Draw("same");
   leg->Draw();
   texs->Draw();
   texc->Draw();
   texp->Draw();
   TLatex *tex2 = new TLatex(0.515,0.623,"#geq4 jets, low M_{T2}^{W}");
   tex2->SetNDC();
   tex2->SetTextFont(42);
   tex2->SetTextSize(0.03789474);
   tex2->SetLineWidth(2);
   tex2->Draw();
   c1->SaveAs("METres_MET_lowMT2W_TTbar1l_.pdf");

   c1->Clear();
   MET_highMT2W_res20->Draw("");
   MET_highMT2W_res15->Draw("same");
   MET_highMT2W_res10->Draw("same");
   MET_highMT2W->Draw("same");
   leg->Draw();
   texs->Draw();
   texc->Draw();
   texp->Draw();
   TLatex *tex3 = new TLatex(0.515,0.623,"#geq4 jets, high M_{T2}^{W}");
   tex3->SetNDC();
   tex3->SetTextFont(42);
   tex3->SetTextSize(0.03789474);
   tex3->SetLineWidth(2);
   tex3->Draw();
   c1->SaveAs("METres_MET_highMT2W_TTbar1l_.pdf");

   c1->Clear();
   MET_3j_res20->Draw("");
   MET_3j_res15->Draw("same");
   MET_3j_res10->Draw("same");
   MET_3j->Draw("same");
   leg->Draw();
   texs->Draw();
   texc->Draw();
   texp->Draw();
   TLatex *tex1 = new TLatex(0.515,0.623,"3 jets");
   tex1->SetNDC();
   tex1->SetTextFont(42);
   tex1->SetTextSize(0.03789474);
   tex1->SetLineWidth(2);
   tex1->Draw();
   c1->SaveAs("METres_MET_3j_TTbar1l_.pdf");
    
    c1->Clear();
    MET_2j_res20->Draw("");
    MET_2j_res15->Draw("same");
    MET_2j_res10->Draw("same");
    MET_2j->Draw("same");
    leg->Draw();
    texs->Draw();
    texc->Draw();
    texp->Draw();
    TLatex *tex12 = new TLatex(0.515,0.623,"2 jets");
    tex12->SetNDC();
    tex12->SetTextFont(42);
    tex12->SetTextSize(0.03789474);
    tex12->SetLineWidth(2);
    tex12->Draw();
    c1->SaveAs("METres_MET_2j_TTbar1l_.pdf");
}
