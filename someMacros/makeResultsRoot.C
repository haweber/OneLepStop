{
TFile *fnew = new TFile("ElectronicLimitsSUS16002.root","recreate");


TH2F *h;
TGraph *g;

TFile *fT2tt = TFile::Open("Limits2DHistograms_T2tt_postfit.root");
h = (TH2F*)fT2tt->Get("hExpXsec");
TH2F *hExpT2tt = (TH2F*)h->Clone("hExpULCrossSection_T2tt");
h = (TH2F*)fT2tt->Get("hObsXsec");
TH2F *hObsT2tt = (TH2F*)h->Clone("hObsULCrossSection_T2tt");
g = (TGraph*)fT2tt->Get("gExp");
TGraph *gExpT2tt = (TGraph*)g->Clone("gExpLimit_T2tt");
g = (TGraph*)fT2tt->Get("gExp1p");
TGraph *gExp1pT2tt = (TGraph*)g->Clone("gExpLimit_plus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gExp1p_2");
TGraph *gExp1p_2T2tt = (TGraph*)g->Clone("gExpLimit_2_plus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gExp1m");
TGraph *gExp1mT2tt = (TGraph*)g->Clone("gExpLimit_minus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gObs1m");
TGraph *gObs1pT2tt = (TGraph*)g->Clone("gObsLimit_plus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gObs1m_2");
TGraph *gObs1p_2T2tt = (TGraph*)g->Clone("gObsLimit_2_plus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gObs1p");
TGraph *gObs1mT2tt = (TGraph*)g->Clone("gObsLimit_minus1sigma_T2tt");
g = (TGraph*)fT2tt->Get("gObs");
TGraph *gObsT2tt = (TGraph*)g->Clone("gObsLimit_T2tt");


TFile *fT2tb = TFile::Open("Limits2DHistograms_T2tb_postfit.root");
h = (TH2F*)fT2tb->Get("hExpXsec");
TH2F *hExpT2tb = (TH2F*)h->Clone("hExpULCrossSection_T2tb_50_50");
h = (TH2F*)fT2tb->Get("hObsXsec");
TH2F *hObsT2tb = (TH2F*)h->Clone("hObsULCrossSection_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gExp");
TGraph *gExpT2tb = (TGraph*)g->Clone("gExpLimit_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gExp1p");
TGraph *gExp1pT2tb = (TGraph*)g->Clone("gExpLimit_plus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gExp1p_2");
TGraph *gExp1p_2T2tb = (TGraph*)g->Clone("gExpLimit_2_plus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gExp1m");
TGraph *gExp1mT2tb = (TGraph*)g->Clone("gExpLimit_minus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gObs1m");
TGraph *gObs1pT2tb = (TGraph*)g->Clone("gObsLimit_plus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gObs1m_2");
TGraph *gObs1p_2T2tb = (TGraph*)g->Clone("gObsLimit_2_plus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gObs1p");
TGraph *gObs1mT2tb = (TGraph*)g->Clone("gObsLimit_minus1sigma_T2tb_50_50");
g = (TGraph*)fT2tb->Get("gObs");
TGraph *gObsT2tb = (TGraph*)g->Clone("gObsLimit_T2tb_50_50");

TFile *fT2ttr = TFile::Open("Limits2DHistograms_T2tt_righthanded_postfit.root");
g = (TGraph*)fT2ttr->Get("gExp");
TGraph *gExpT2ttr = (TGraph*)g->Clone("gExpLimit_T2tt_righthanded");
g = (TGraph*)fT2ttr->Get("gObs");
TGraph *gObsT2ttr = (TGraph*)g->Clone("gObsLimit_T2tt_righthanded");

TFile *fT2ttl = TFile::Open("Limits2DHistograms_T2tt_lefthanded_postfit.root");
g = (TGraph*)fT2ttl->Get("gExp_2");
TGraph *gExpT2ttl = (TGraph*)g->Clone("gExpLimit_T2tt_lefthanded");
g = (TGraph*)fT2ttl->Get("gObs_2");
TGraph *gObsT2ttl = (TGraph*)g->Clone("gObsLimit_T2tt_lefthanded");

TFile *fT2tb75 = TFile::Open("Limits2DHistograms_T2tb_75_25_postfit.root");
g = (TGraph*)fT2tb75->Get("gExp");
TGraph *gExpT2tb75 = (TGraph*)g->Clone("gExpLimit_T2tb_75_25");
g = (TGraph*)fT2tb75->Get("gObs");
TGraph *gObsT2tb75 = (TGraph*)g->Clone("gObsLimit_T2tb_75_25");

TFile *fT2tb67 = TFile::Open("Limits2DHistograms_T2tb_67_33_postfit.root");
g = (TGraph*)fT2tb67->Get("gExp");
TGraph *gExpT2tb67 = (TGraph*)g->Clone("gExpLimit_T2tb_67_33");
g = (TGraph*)fT2tb67->Get("gObs");
TGraph *gObsT2tb67 = (TGraph*)g->Clone("gObsLimit_T2tb_67_33");

TFile *fT2tb33 = TFile::Open("Limits2DHistograms_T2tb_33_67_postfit.root");
g = (TGraph*)fT2tb33->Get("gExp");
TGraph *gExpT2tb33 = (TGraph*)g->Clone("gExpLimit_T2tb_33_67");
g = (TGraph*)fT2tb33->Get("gObs");
TGraph *gObsT2tb33 = (TGraph*)g->Clone("gObsLimit_T2tb_33_67");

TFile *fT2tb25 = TFile::Open("Limits2DHistograms_T2tb_25_75_postfit.root");
g = (TGraph*)fT2tb25->Get("gExp");
TGraph *gExpT2tb25 = (TGraph*)g->Clone("gExpLimit_T2tb_25_75");
g = (TGraph*)fT2tb25->Get("gObs");
TGraph *gObsT2tb25 = (TGraph*)g->Clone("gObsLimit_T2tb_25_75");
g = (TGraph*)fT2tb25->Get("gObs_2");
TGraph *gObsT2tb252 = (TGraph*)g->Clone("gObsLimit_2_T2tb_25_75");

fnew->cd();
hExpT2tt->Write();
hObsT2tt->Write();
gExpT2tt->Write();
gExp1pT2tt->Write();
gExp1p_2T2tt->Write();
gExp1mT2tt->Write();
gObs1pT2tt->Write();
gObs1p_2T2tt->Write();
gObs1mT2tt->Write();
gObsT2tt->Write();

hExpT2tb->Write();
hObsT2tb->Write();
gExpT2tb->Write();
gExp1pT2tb->Write();
gExp1p_2T2tb->Write();
gExp1mT2tb->Write();
gObs1pT2tb->Write();
gObs1p_2T2tb->Write();
gObs1mT2tb->Write();
gObsT2tb->Write();

gExpT2ttr->Write();
gObsT2ttr->Write();
gExpT2ttl->Write();
gObsT2ttl->Write();

gExpT2tb75->Write();
gObsT2tb75->Write();
gExpT2tb67->Write();
gObsT2tb67->Write();
gExpT2tb33->Write();
gObsT2tb33->Write();
gExpT2tb25->Write();
gObsT2tb25->Write();
gObsT2tb252->Write();
fnew->Close();
}