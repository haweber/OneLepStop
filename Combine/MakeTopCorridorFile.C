{
    TFile *fold = TFile::Open("Limits2DHistograms_compressed_T2tt_postfit.root");
    //TFile *fold = TFile::Open("Limits2DHistograms_std_T2tt_postfit.root");
    //TFile *fold = TFile::Open("Limits2DHistograms_std_T2tt_postfit_12p9fbinv.root");

//TH2F *hExpXsec = (TH2F*)fold->Get("hExpXsec");
//TH2F *hExp1mXsec = (TH2F*)fold->Get("hExp1mXsec");
//TH2F *hExp1pXsec = (TH2F*)fold->Get("hExp1pXsec");
//TH2F *hExp2mXsec = (TH2F*)fold->Get("hExp2mXsec");
//TH2F *hExp2pXsec = (TH2F*)fold->Get("hExp2pXsec");
//TH2F *hObsXsec = (TH2F*)fold->Get("hObsXsec");
//TH2F *hObs1mXsec = (TH2F*)fold->Get("hObs1mXsec");
//TH2F *hObs1pXsec = (TH2F*)fold->Get("hObs1pXsec");

TH2F *hExpXsec = (TH2F*)fold->Get("hExpOrgXsec");
TH2F *hExp1mXsec = (TH2F*)fold->Get("hExp1mOrgXsec");
TH2F *hExp1pXsec = (TH2F*)fold->Get("hExp1pOrgXsec");
TH2F *hExp2mXsec = (TH2F*)fold->Get("hExp2mOrgXsec");
TH2F *hExp2pXsec = (TH2F*)fold->Get("hExp2pOrgXsec");
TH2F *hObsXsec = (TH2F*)fold->Get("hObsOrgXsec");
TH2F *hObs1mXsec = (TH2F*)fold->Get("hObs1mOrgXsec");
TH2F *hObs1pXsec = (TH2F*)fold->Get("hObs1pOrgXsec");
TH2F *hExp = (TH2F*)fold->Get("hExpOrg");
TH2F *hExp1m = (TH2F*)fold->Get("hExp1mOrg");
TH2F *hExp1p = (TH2F*)fold->Get("hExp1pOrg");

TGraph *gExpXsec = new TGraph(); gExpXsec->SetName("gExpXsec");
TGraph *gExp1mXsec = new TGraph(); gExp1mXsec->SetName("gExp1mXsec");
TGraph *gExp1pXsec = new TGraph(); gExp1pXsec->SetName("gExp1pXsec");
TGraph *gExp2mXsec = new TGraph(); gExp2mXsec->SetName("gExp2mXsec");
TGraph *gExp2pXsec = new TGraph(); gExp2pXsec->SetName("gExp2pXsec");
TGraph *gObsXsec = new TGraph(); gObsXsec->SetName("gObsXsec");
TGraph *gObs1mXsec = new TGraph(); gObs1mXsec->SetName("gObs1mXsec");
TGraph *gObs1pXsec = new TGraph(); gObs1pXsec->SetName("gObs1pXsec");
TFile *ftemp = TFile::Open("../../general/xsec_stop_8_13_TeV.root");
TH1F *h = (TH1F*)ftemp->Get("xsec_13TeV");
TGraph *g = (TGraph*)ftemp->Get("g_xsec_13TeV");
TH1F *hx = (TH1F*)h->Clone("hXsec_13TeV");
TGraph *gx = (TGraph*)g->Clone("gXsec_13TeV");
hx->Integral();


for(int x = 1; x<=hExpXsec->GetNbinsX();++x){for(int y = 1; y<=hExpXsec->GetNbinsY();++y){
if(hExpXsec->GetXaxis()->GetBinLowEdge(x) - hExpXsec->GetYaxis()->GetBinLowEdge(y)-175==0) {
if(hExp1mXsec->GetBinContent(x,y)==hExp1pXsec->GetBinContent(x,y)) continue;
gExpXsec->SetPoint(gExpXsec->GetN(),hExpXsec->GetXaxis()->GetBinLowEdge(x),hExpXsec->GetBinContent(x,y));
gExp1mXsec->SetPoint(gExp1mXsec->GetN(),hExp1mXsec->GetXaxis()->GetBinLowEdge(x),hExp1mXsec->GetBinContent(x,y));
gExp1pXsec->SetPoint(gExp1pXsec->GetN(),hExp1pXsec->GetXaxis()->GetBinLowEdge(x),hExp1pXsec->GetBinContent(x,y));
gExp2mXsec->SetPoint(gExp2mXsec->GetN(),hExp2mXsec->GetXaxis()->GetBinLowEdge(x),hExp2mXsec->GetBinContent(x,y));
gExp2pXsec->SetPoint(gExp2pXsec->GetN(),hExp2pXsec->GetXaxis()->GetBinLowEdge(x),hExp2pXsec->GetBinContent(x,y));
gObsXsec->SetPoint(gObsXsec->GetN(),hObsXsec->GetXaxis()->GetBinLowEdge(x),hObsXsec->GetBinContent(x,y));
gObs1mXsec->SetPoint(gObs1mXsec->GetN(),hObs1mXsec->GetXaxis()->GetBinLowEdge(x),hObs1mXsec->GetBinContent(x,y));
gObs1pXsec->SetPoint(gObs1pXsec->GetN(),hObs1pXsec->GetXaxis()->GetBinLowEdge(x),hObs1pXsec->GetBinContent(x,y));
cout << hExpXsec->GetXaxis()->GetBinLowEdge(x) << " " << hExpXsec->GetYaxis()->GetBinLowEdge(y) << " " << hExpXsec->GetXaxis()->GetBinLowEdge(x) - hExpXsec->GetYaxis()->GetBinLowEdge(y)-175 << endl;
cout << hExpXsec->GetBinContent(x,y) << " " << hExp1mXsec->GetBinContent(x,y) << " " << hExp1pXsec->GetBinContent(x,y) << ", " << hObsXsec->GetBinContent(x,y) << " " <<  hObs1mXsec->GetBinContent(x,y)<< " " << hObs1pXsec->GetBinContent(x,y) << endl;
cout << hExp->GetBinContent(x,y)*hx->GetBinContent(hx->FindBin(hExp->GetXaxis()->GetBinLowEdge(x))) << " " << hExp1m->GetBinContent(x,y)*hx->GetBinContent(hx->FindBin(hExp->GetXaxis()->GetBinLowEdge(x))) << " " << hExp1p->GetBinContent(x,y)*hx->GetBinContent(hx->FindBin(hExp->GetXaxis()->GetBinLowEdge(x)))  << endl;

}}}

    TFile *f = new TFile("Limits1DCorridor_T2tt_compressed_36p6fbinv.root","recreate");
    //TFile *f = new TFile("Limits1DCorridor_T2tt_std_36p6fbinv.root","recreate");
f->cd();
gExpXsec->Write();
gExp1mXsec->Write();
gExp1pXsec->Write();
gExp2mXsec->Write();
gExp2pXsec->Write();
gObsXsec->Write();
gObs1mXsec->Write();
gObs1pXsec->Write();
gx->Write();
hx->Write();
f->Close();
}