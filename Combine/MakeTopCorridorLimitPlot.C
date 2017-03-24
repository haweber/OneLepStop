{

    TFile *f = TFile::Open("Limits1DCorridor_T2tt_compressed_36p6fbinv.root");
    //TFile *f = TFile::Open("Limits1DCorridor_T2tt_std_36p6fbinv.root");


TGraph *gExpXsec = (TGraph*)f->Get("gExpXsec");
TGraph *gExp1mXsec = (TGraph*)f->Get("gExp1mXsec");
TGraph *gExp1pXsec = (TGraph*)f->Get("gExp1pXsec");
TGraph *gExp2mXsec = (TGraph*)f->Get("gExp2mXsec");
TGraph *gExp2pXsec = (TGraph*)f->Get("gExp2pXsec");
TGraph *gObsXsec = (TGraph*)f->Get("gObsXsec");
TGraph *hObs1mXsec = (TGraph*)f->Get("gObs1mXsec");
TGraph *gObs1pXsec = (TGraph*)f->Get("gObs1pXsec");
TGraphErrors *gx = (TGraphErrors*)f->Get("gXsec_13TeV");

TGraph *g2 = new TGraph();
for(int i = 0; i<gExp2mXsec->GetN();++i){
double x,y;
gExp2mXsec->GetPoint(i,x,y);
g2->SetPoint(g2->GetN(),x,y);
}
for(int i = gExp2pXsec->GetN()-1; i>=0;--i){
double x,y;
gExp2pXsec->GetPoint(i,x,y);
g2->SetPoint(g2->GetN(),x,y);
}
TGraph *gxc = new TGraph();
    TGraph *gxpX = new TGraph();
    TGraph *gxp = new TGraph();
TGraph *gxm = new TGraph();
for(int i = 0; i<gx->GetN();++i){
double x,y;
gx->GetPoint(i,x,y);
double ep = gx->GetErrorYhigh(i);
double em = gx->GetErrorYlow(i);
gxp->SetPoint(i,x,y+fabs(ep));
gxm->SetPoint(i,x,y-fabs(em));
gxc->SetPoint(i,x,y);
}

TGraph *g1 = new TGraph();
for(int i = 0; i<gExp1mXsec->GetN();++i){
double x,y;
gExp1mXsec->GetPoint(i,x,y);
g1->SetPoint(g1->GetN(),x,y);
}
for(int i = gExp1pXsec->GetN()-1; i>=0;--i){
double x,y;
gExp1pXsec->GetPoint(i,x,y);
g1->SetPoint(g1->GetN(),x,y);
}

   TCanvas *c1 = new TCanvas("c1", "",477,85,900,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLogy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.12);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetBottomMargin(0.15);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);

//TH1F *haxis = new TH1F("haxis","",10,275,550);
TH1F *haxis = new TH1F("haxis","",10,175,650);
haxis->SetMinimum(0.2);
//haxis->SetMinimum(0.4);
haxis->SetMaximum(250);

haxis->Draw("axis");
haxis->GetXaxis()->SetTitle("M_{#tilde{t}} [GeV]");
haxis->GetXaxis()->SetLabelFont(42);
haxis->GetXaxis()->SetLabelOffset(0.007);
haxis->GetXaxis()->SetLabelSize(0.05);
haxis->GetXaxis()->SetTitleSize(0.06);
haxis->GetXaxis()->SetTitleOffset(1.05);
haxis->GetXaxis()->SetTitleFont(42);
haxis->GetYaxis()->SetTitle("95% CL upper limit on #sigma_{signal} [pb]");
haxis->GetYaxis()->SetNdivisions(509);
haxis->GetYaxis()->SetLabelFont(42);
haxis->GetYaxis()->SetLabelOffset(0.007);
haxis->GetYaxis()->SetLabelSize(0.05);
haxis->GetYaxis()->SetTitleSize(0.06);
haxis->GetYaxis()->SetTitleOffset(0.9);
haxis->GetYaxis()->SetTitleFont(42);
haxis->GetZaxis()->SetLabelFont(42);
haxis->GetZaxis()->SetLabelOffset(0.007);
haxis->GetZaxis()->SetLabelSize(0.05);
haxis->GetZaxis()->SetTitleSize(0.06);
haxis->GetZaxis()->SetTitleFont(42);

g2->SetFillColor(kYellow);
g1->SetFillColor(kGreen);
gExpXsec->SetLineWidth(2); gExpXsec->SetLineColor(kRed); gExpXsec->SetLineStyle(2);
gObsXsec->SetLineWidth(3); gObsXsec->SetLineColor(kBlack); 
gxc->SetLineWidth(2); gxc->SetLineColor(kBlue);
    gxp->SetLineWidth(1); gxp->SetLineColor(kBlue); gxp->SetLineStyle(2);
    gxpX->SetLineWidth(2); gxpX->SetLineColor(kBlue); gxpX->SetLineStyle(2);
gxm->SetLineWidth(1); gxm->SetLineColor(kBlue); gxm->SetLineStyle(2);

g2->Draw("Fsame");
g1->Draw("Fsame");

gxc->Draw("csame");
gxp->Draw("csame");
gxm->Draw("csame");

gExpXsec->Draw("csame");
gObsXsec->Draw("csame");
    haxis->Draw("sameaxis");

   TLegend *leg = new TLegend(0.604,0.657,0.8425,0.822,NULL,"brNDC");
   leg->SetNColumns(2);
   leg->SetBorderSize(0);
   leg->SetTextSize(0.042);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(gExpXsec,"expected","l");
   leg->AddEntry(g1,"#pm 1#sigma_{experiment}","f");
   leg->AddEntry(gObsXsec,"observed","l");
   leg->AddEntry(g2,"#pm 2#sigma_{experiment}","f");
    leg->AddEntry(gxc,"theory cross-section","l");
    TLegend *leg2 = new TLegend(0.604,0.581,0.8425,0.68,NULL,"brNDC");
    leg2->SetNColumns(2);
    leg2->SetBorderSize(0);
    leg2->SetTextSize(0.042);
    leg2->SetLineColor(1);
    leg2->SetLineStyle(1);
    leg2->SetLineWidth(2);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(1001);
    leg2->AddEntry(gxpX,"#pm 1#sigma_{theory cross-section}","l");
    leg2->Draw();
   leg->Draw();


    //TLatex *   texs = new TLatex(0.95,0.944,"36.6 fb^{-1} (13 TeV)");
    TLatex *   texs = new TLatex(0.95,0.944,"35.9 fb^{-1} (13 TeV)");
   texs->SetNDC();
   texs->SetTextAlign(31);
   texs->SetTextFont(42);
   texs->SetTextSize(0.042);
   texs->SetLineWidth(2);
   texs->Draw();
   TLatex *texC = new TLatex(0.12,0.944,"CMS");
   texC->SetNDC();
   texC->SetTextAlign(11);
   texC->SetTextFont(61);
   texC->SetTextSize(0.0525);
   texC->SetLineWidth(2);
   texC->Draw();
   TLatex *texP = new TLatex(0.20,0.9444,"Preliminary");
   texP->SetNDC();
   texP->SetTextAlign(11);
   texP->SetTextFont(52);
   texP->SetTextSize(0.0399);
   texP->SetLineWidth(2);
   texP->Draw();

   TLatex *   tex = new TLatex(0.604,0.85,"M_{#tilde{t}} - M_{#tilde{#chi}^{0}_{1}} = 175 GeV");
   tex->SetNDC();
   tex->SetTextAlign(11);
   tex->SetTextFont(42);
   tex->SetTextSize(0.042);
   tex->SetLineWidth(2);
   tex->Draw();
    
    c1->SaveAs("Limits1DCorridor_T2tt_compressed_36p6fbinv.eps");
    //c1->SaveAs("Limits1DCorridor_T2tt_std_36p6fbinv.eps");

}

