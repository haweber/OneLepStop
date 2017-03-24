void GoodnessOfFitResult()
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Feb 21 13:36:54 2017) by ROOT version6.04/00
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",307,94,600,600);
   gStyle->SetOptStat(0);
   //Canvas_1->Range(-6.25,-10.2375,56.25,92.1375);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
    
    double value = -1;
    
    TFile *fobs = TFile::Open("GoodnessOfFit_Observed_std_T2tt_900_50.root");
    TTree *tobs = (TTree*)fobs->Get("limit");
    tobs->SetBranchAddress("limit", &value);
    tobs->GetEntry(0);
    double obsvalue = value;
    cout << "Observed " << obsvalue << endl;

   TH1F *TestStatistics = new TH1F("TestStatistics","",120,0,65);
    TestStatistics->GetXaxis()->SetTitle("Test statistics");
   TestStatistics->GetXaxis()->SetLabelFont(42);
   TestStatistics->GetXaxis()->SetLabelSize(0.035);
   TestStatistics->GetXaxis()->SetTitleSize(0.035);
   TestStatistics->GetXaxis()->SetTitleFont(42);
   TestStatistics->GetYaxis()->SetTitle("Number of toys");
   TestStatistics->GetYaxis()->SetLabelFont(42);
   TestStatistics->GetYaxis()->SetLabelSize(0.035);
    TestStatistics->GetYaxis()->SetTitleSize(0.035);
    TestStatistics->GetYaxis()->SetTitleOffset(1.30);
   TestStatistics->GetYaxis()->SetTitleFont(42);
   TestStatistics->GetZaxis()->SetLabelFont(42);
   TestStatistics->GetZaxis()->SetLabelSize(0.035);
   TestStatistics->GetZaxis()->SetTitleSize(0.035);
   TestStatistics->GetZaxis()->SetTitleFont(42);
    TestStatistics->SetLineColor(kBlue+2);
    TestStatistics->SetLineWidth(2);
    
    TFile *fexp = TFile::Open("GoodnessOfFit_ToysSum_datacard_std_T2tt_900_50.root");
    TTree *texp = (TTree*)fexp->Get("limit");
    texp->SetBranchAddress("limit", &value);
    for(int i = 0; i<texp->GetEntries();++i){
        texp->GetEntry(i);
        TestStatistics->Fill(value);
    }
   TestStatistics->Draw("");
    float max = TestStatistics->GetMaximum();
    
    double xq[5] = {0.5, 0.16, 0.84, 0.025, 0.975};
    double yq[5];
    TestStatistics->GetQuantiles(5,yq,xq);
    for(int i =0; i<5;++i) cout << "xq " << xq[i] << " yq " << yq[i] << endl;
 
    
    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
   TLine *lineExp = new TLine(yq[0],0,yq[0],max*1.05);
   ci = TColor::GetColor("#ff0000");
   lineExp->SetLineColor(ci);
   lineExp->SetLineWidth(3);
   lineExp->Draw();
   TLine *lineExp1p = new TLine(yq[2],0,yq[2],max*1.05);
   ci = TColor::GetColor("#ff0000");
   lineExp1p->SetLineColor(ci);
   lineExp1p->SetLineStyle(7);
   lineExp1p->SetLineWidth(2);
   lineExp1p->Draw();
   TLine *lineExp1m = new TLine(yq[1],0,yq[1],max*1.05);
   ci = TColor::GetColor("#ff0000");
   lineExp1m->SetLineColor(ci);
   lineExp1m->SetLineStyle(7);
   lineExp1m->SetLineWidth(2);
   lineExp1m->Draw();
   TLine *lineExp2p = new TLine(yq[4],0,yq[4],max*1.05);
   ci = TColor::GetColor("#ff0000");
   lineExp2p->SetLineColor(ci);
   lineExp2p->SetLineStyle(2);
   lineExp2p->Draw();
   TLine *lineExp2m = new TLine(yq[3],0,yq[3],max*1.05);
   ci = TColor::GetColor("#ff0000");
   lineExp2m->SetLineColor(ci);
   lineExp2m->SetLineStyle(2);
   lineExp2m->Draw();
    TLine *lineObs = new TLine(obsvalue,0,obsvalue,max*1.05);
    lineObs->SetLineWidth(3);
    lineObs->SetLineColor(1);
    lineObs->Draw();
    
    TLatex *tLumi = new TLatex(0.895,0.914,"35.9 fb^{-1} (13 TeV)");
    tLumi->SetNDC();
    tLumi->SetTextAlign(31);
    tLumi->SetTextFont(42);
    tLumi->SetTextSize(0.042);
    tLumi->SetLineWidth(2);
    tLumi->Draw();
    TLatex *tECM = new TLatex(0.95,0.944,"(13 TeV)");
    //TLatex *tECM = new TLatex(0.95,0.944,"(13 TeV)");
    tECM->SetNDC();
    tECM->SetTextAlign(31);
    tECM->SetTextFont(42);
    tECM->SetTextSize(0.042);
    tECM->SetLineWidth(2);
    //tLumi->Draw();
    TLatex *tCMS = new TLatex(0.10,0.914,"CMS");
    tCMS->SetNDC();
    tCMS->SetTextAlign(11);
    tCMS->SetTextFont(61);
    tCMS->SetTextSize(0.0525);
    tCMS->SetLineWidth(2);
    tCMS->Draw();
    //TLatex *tSim = new TLatex(0.215,0.914,"Supplementary");
    TLatex *tSim = new TLatex(0.215,0.914,"Preliminary");
    tSim->SetNDC();
    tSim->SetTextAlign(11);
    tSim->SetTextFont(52);
    tSim->SetTextSize(0.042);
    tSim->SetLineWidth(2);
    tSim->Draw();
    
    TLatex *tstats = new TLatex(0.615,0.775,"Toys statistics");
    tstats->SetNDC();
    tstats->SetTextAlign(11);
    tstats->SetTextFont(42);
    tstats->SetTextSize(0.042);
    tstats->Draw();
    TLine *lstats = new TLine(0.57,0.785,0.6025,0.785);
    lstats->SetNDC();
    lstats->SetLineWidth(2);
    lstats->SetLineColor(kBlue+2);
    lstats->Draw();
    TLatex *txobs = new TLatex(0.615,0.725,"Observed");
    txobs->SetNDC();
    txobs->SetTextAlign(11);
    txobs->SetTextFont(42);
    txobs->SetTextSize(0.042);
    txobs->Draw();
    TLine *lobs = new TLine(0.57,0.7375,0.6025,0.7375);
    lobs->SetNDC();
    lobs->SetLineWidth(3);
    lobs->SetLineColor(kBlack);
    lobs->Draw();
    TLatex *txexp = new TLatex(0.615,0.675,"Expected #pm 1/2#sigma");
    txexp->SetNDC();
    txexp->SetTextAlign(11);
    txexp->SetTextFont(42);
    txexp->SetTextSize(0.042);
    txexp->Draw();
    TLine *lexp = new TLine(0.57,0.6875,0.6025,0.6875);
    lexp->SetNDC();
    lexp->SetLineWidth(3);
    lexp->SetLineColor(kRed);
    lexp->Draw();
    TLine *lexpp1 = new TLine(0.57,0.695,0.6025,0.695);
    lexpp1->SetNDC();
    lexpp1->SetLineWidth(2);
    lexpp1->SetLineColor(kRed);
    lexpp1->SetLineStyle(7);
    lexpp1->Draw();
    TLine *lexpm1 = new TLine(0.57,0.68,0.6025,0.68);
    lexpm1->SetNDC();
    lexpm1->SetLineWidth(2);
    lexpm1->SetLineColor(kRed);
    lexpm1->SetLineStyle(7);
    lexpm1->Draw();
    TLine *lexpp2 = new TLine(0.57,0.7015,0.6025,0.7015);
    lexpp2->SetNDC();
    lexpp2->SetLineWidth(1);
    lexpp2->SetLineColor(kRed);
    lexpp2->SetLineStyle(2);
    lexpp2->Draw();
    TLine *lexpm2 = new TLine(0.57,0.6735,0.6025,0.6735);
    lexpm2->SetNDC();
    lexpm2->SetLineWidth(1);
    lexpm2->SetLineColor(kRed);
    lexpm2->SetLineStyle(2);
    lexpm2->Draw();
    
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
