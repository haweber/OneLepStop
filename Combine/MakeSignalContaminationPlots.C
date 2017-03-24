void MakeSignalContaminationPlots(){
    
    TFile *f = new TFile("SignalContamination.root","READ");
    map <string,TH2D*> h;
    //h[   "SRcont_T2tt"]=(TH2D*)f->Get("SRcont_T2tt");
    h[ "SRcont0b_T2tt"]=(TH2D*)f->Get("SRcont0b_T2tt");
    h[ "SRcont0b_T2ttp"]=(TH2D*)h[ "SRcont0b_T2tt"]->Clone("SRcont0b_T2ttp");
    h[ "SRcont2l_T2tt"]=(TH2D*)f->Get("SRcont2l_T2tt");
    //h[   "SRcont_T2tb"]=(TH2D*)f->Get("SRcont_T2tb");
    h[ "SRcont0b_T2tb"]=(TH2D*)f->Get("SRcont0b_T2tb");
    h[ "SRcont2l_T2tb"]=(TH2D*)f->Get("SRcont2l_T2tb");
    //h[   "SRcont_T2bW"]=(TH2D*)f->Get("SRcont_T2bW");
    h[ "SRcont0b_T2bW"]=(TH2D*)f->Get("SRcont0b_T2bW");
    h[ "SRcont2l_T2bW"]=(TH2D*)f->Get("SRcont2l_T2bW");
    //h[  "cSRcont_T2tt"]=(TH2D*)f->Get("cSRcont_T2tt");
    h["cSRcont0b_T2tt"]=(TH2D*)f->Get("cSRcont0b_T2tt");
    h["cSRcont2l_T2tt"]=(TH2D*)f->Get("cSRcont2l_T2tt");
    for(map<string,TH2D*>::iterator hi=    h.begin(); hi!=    h.end();++hi) {
        hi->second->GetXaxis()->SetTitle("m_{#tilde{t}} [GeV]");
        hi->second->GetXaxis()->SetLabelFont(42);
        hi->second->GetXaxis()->SetLabelSize(0.035);
        hi->second->GetXaxis()->SetTitleSize(0.05);
        hi->second->GetXaxis()->SetTitleOffset(1.2);
        hi->second->GetXaxis()->SetTitleFont(42);
        hi->second->GetXaxis()->SetNdivisions(505);
        hi->second->GetYaxis()->SetTitle("m_{#tilde{#chi}_{1}^{0}} [GeV]");
        hi->second->GetYaxis()->SetLabelFont(42);
        hi->second->GetYaxis()->SetLabelSize(0.035);
        hi->second->GetYaxis()->SetTitleSize(0.05);
        hi->second->GetYaxis()->SetTitleOffset(1.35);
        hi->second->GetYaxis()->SetTitleFont(42);
        hi->second->GetYaxis()->SetNdivisions(505);
        hi->second->GetZaxis()->SetNdivisions(505);
    }
    h[ "SRcont0b_T2tt" ]->GetZaxis()->SetRangeUser(0,0.1);
    h[ "SRcont0b_T2tb" ]->GetZaxis()->SetRangeUser(0,0.1);
    h[ "SRcont0b_T2bW" ]->GetZaxis()->SetRangeUser(0,0.1);
    h["cSRcont0b_T2tt" ]->GetZaxis()->SetRangeUser(0,0.6);
    h[ "SRcont0b_T2ttp"]->GetZaxis()->SetRangeUser(0,0.6);
    h[ "SRcont2l_T2tt" ]->GetZaxis()->SetRangeUser(0,0.2);
    h[ "SRcont2l_T2tb" ]->GetZaxis()->SetRangeUser(0,0.2);
    h[ "SRcont2l_T2bW" ]->GetZaxis()->SetRangeUser(0,0.2);
    h["cSRcont2l_T2tt" ]->GetZaxis()->SetRangeUser(0,0.2);
    
    TCanvas *c1 = new TCanvas("c1", "c1",50,50,600,600);
    gStyle->SetOptFit(1);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetErrorX(0.5);
    //c1->Range(-6.311689,-1.891383,28.75325,4.56342);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    //c1->SetLogy();
    c1->SetTickx(1);
    c1->SetTicky(1);
    c1->SetLeftMargin(0.15);
    //   c1->SetRightMargin(0.05);
    c1->SetRightMargin(0.17);
    c1->SetTopMargin(0.07);
    c1->SetBottomMargin(0.15);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    gStyle->SetHatchesLineWidth(0);

    TLatex * ztex = new TLatex(0.985,0.92,"relative signal contamination correction" );
    ztex->SetNDC();
    ztex->SetTextAlign(31);
    ztex->SetTextFont(42);
    ztex->SetTextSize(0.042);
    ztex->SetTextAngle(90);
    ztex->SetLineWidth(2);
    //ztex->Draw();
    
    
    //final CMS style
    TLatex *tLumi = new TLatex(0.846,0.944,"(13 TeV)");
    //TLatex *tLumi = new TLatex(0.846,0.944,"36.6 fb^{-1} (13 TeV)");
    tLumi->SetNDC();
    tLumi->SetTextAlign(31);
    tLumi->SetTextFont(42);
    tLumi->SetTextSize(0.042);
    tLumi->SetLineWidth(2);
    //tLumi->Draw();
    TLatex *tCMS = new TLatex(0.152,0.944,"CMS");
    tCMS->SetNDC();
    tCMS->SetTextAlign(11);
    tCMS->SetTextFont(61);
    tCMS->SetTextSize(0.0525);
    tCMS->SetLineWidth(2);
    //tCMS->Draw();
    TLatex *tPrel = new TLatex(0.265,0.944,"Simulation");
    tPrel->SetNDC();
    tPrel->SetTextAlign(11);
    tPrel->SetTextFont(52);
    tPrel->SetTextSize(0.042);
    tPrel->SetLineWidth(2);
    //tPrel->Draw();
    
    TLatex *scan;
    TLatex *type;
    TLatex *compressed;
    
    for(map<string,TH2D*>::iterator hi=    h.begin(); hi!=    h.end();++hi){
        cout << hi->first << endl;
        if(hi->first.find("T2tt")!=string::npos){
            scan = new TLatex(0.175,0.79,"T2tt");
        }
        if(hi->first.find("T2tb")!=string::npos){
            scan = new TLatex(0.175,0.79,"T2tb");
        }
        if(hi->first.find("T2bW")!=string::npos){
            scan = new TLatex(0.175,0.79,"T2bW");
        }
        if(hi->first.find("0b")!=string::npos){
            type = new TLatex(0.175,0.875,"CR0b contamination");
        }
        if(hi->first.find("2l")!=string::npos){
            type = new TLatex(0.175,0.875,"CR2l contamination");
        }
        scan->SetNDC();
        scan->SetTextAlign(11);
        scan->SetTextFont(42);
        scan->SetTextSize(0.035);
        scan->SetLineWidth(2);
        type->SetNDC();
        type->SetTextAlign(11);
        type->SetTextFont(42);
        type->SetTextSize(0.035);
        type->SetLineWidth(2);
        
        hi->second->Draw("COLZ");
        ztex->Draw();
        tCMS->Draw();
        tPrel->Draw();
        scan->Draw();
        type->Draw();
        if(hi->first.find("cSR")!=string::npos){
            compressed = new TLatex(0.175,0.835,"compressed analysis");
            compressed->SetNDC();
            compressed->SetTextAlign(11);
            compressed->SetTextFont(42);
            compressed->SetTextSize(0.035);
            compressed->SetLineWidth(2);
            compressed->Draw();
        }
        string outname = hi->first + ".eps";
        c1->SaveAs(outname.c_str());
    }

   
}

void MakeSignalContRoot(){
 
    map <string,TH3D*> hin;
    map <string,TH2D*> h;
    TFile *fT2tt = TFile::Open("Histos_std_Signal_T2tt.root");
    hin[                  "SRyield_T2tt"] = (TH3D*)fT2tt->Get("SRyield");                   hin[                  "SRyield_T2tt"]->SetName(                  "SRyield_T2tt");
    hin[              "SRyield_gen_T2tt"] = (TH3D*)fT2tt->Get("SRyield_gen");               hin[              "SRyield_gen_T2tt"]->SetName(              "SRyield_gen_T2tt");
    hin[    "CR1l_sigcontamination_T2tt"] = (TH3D*)fT2tt->Get("CR1l_sigcontamination");     hin[    "CR1l_sigcontamination_T2tt"]->SetName(    "CR1l_sigcontamination_T2tt");
    hin[    "CR2l_sigcontamination_T2tt"] = (TH3D*)fT2tt->Get("CR2l_sigcontamination");     hin[    "CR2l_sigcontamination_T2tt"]->SetName(    "CR2l_sigcontamination_T2tt");
    hin["CR1l_sigcontamination_gen_T2tt"] = (TH3D*)fT2tt->Get("CR1l_sigcontamination_gen"); hin["CR1l_sigcontamination_gen_T2tt"]->SetName("CR1l_sigcontamination_gen_T2tt");
    hin["CR2l_sigcontamination_gen_T2tt"] = (TH3D*)fT2tt->Get("CR2l_sigcontamination_gen"); hin["CR2l_sigcontamination_gen_T2tt"]->SetName("CR2l_sigcontamination_gen_T2tt");

    TFile *fT2tb = TFile::Open("Histos_std_Signal_T2tb.root");
    hin[                  "SRyield_T2tb"] = (TH3D*)fT2tb->Get("SRyield");                   hin[                  "SRyield_T2tb"]->SetName(                  "SRyield_T2tb");
    hin[              "SRyield_gen_T2tb"] = (TH3D*)fT2tb->Get("SRyield_gen");               hin[              "SRyield_gen_T2tb"]->SetName(              "SRyield_gen_T2tb");
    hin[    "CR1l_sigcontamination_T2tb"] = (TH3D*)fT2tb->Get("CR1l_sigcontamination");     hin[    "CR1l_sigcontamination_T2tb"]->SetName(    "CR1l_sigcontamination_T2tb");
    hin[    "CR2l_sigcontamination_T2tb"] = (TH3D*)fT2tb->Get("CR2l_sigcontamination");     hin[    "CR2l_sigcontamination_T2tb"]->SetName(    "CR2l_sigcontamination_T2tb");
    hin["CR1l_sigcontamination_gen_T2tb"] = (TH3D*)fT2tb->Get("CR1l_sigcontamination_gen"); hin["CR1l_sigcontamination_gen_T2tb"]->SetName("CR1l_sigcontamination_gen_T2tb");
    hin["CR2l_sigcontamination_gen_T2tb"] = (TH3D*)fT2tb->Get("CR2l_sigcontamination_gen"); hin["CR2l_sigcontamination_gen_T2tb"]->SetName("CR2l_sigcontamination_gen_T2tb");

    TFile *fT2bW = TFile::Open("Histos_std_Signal_T2bW.root");
    hin[                  "SRyield_T2bW"] = (TH3D*)fT2bW->Get("SRyield");                   hin[                  "SRyield_T2bW"]->SetName(                  "SRyield_T2bW");
    hin[              "SRyield_gen_T2bW"] = (TH3D*)fT2bW->Get("SRyield_gen");               hin[              "SRyield_gen_T2bW"]->SetName(              "SRyield_gen_T2bW");
    hin[    "CR1l_sigcontamination_T2bW"] = (TH3D*)fT2bW->Get("CR1l_sigcontamination");     hin[    "CR1l_sigcontamination_T2bW"]->SetName(    "CR1l_sigcontamination_T2bW");
    hin[    "CR2l_sigcontamination_T2bW"] = (TH3D*)fT2bW->Get("CR2l_sigcontamination");     hin[    "CR2l_sigcontamination_T2bW"]->SetName(    "CR2l_sigcontamination_T2bW");
    hin["CR1l_sigcontamination_gen_T2bW"] = (TH3D*)fT2bW->Get("CR1l_sigcontamination_gen"); hin["CR1l_sigcontamination_gen_T2bW"]->SetName("CR1l_sigcontamination_gen_T2bW");
    hin["CR2l_sigcontamination_gen_T2bW"] = (TH3D*)fT2bW->Get("CR2l_sigcontamination_gen"); hin["CR2l_sigcontamination_gen_T2bW"]->SetName("CR2l_sigcontamination_gen_T2bW");

    TFile *fT2ttc = TFile::Open("Histos_compressed_Signal_T2tt.root");
    hin[                  "SRyield_T2ttc"] = (TH3D*)fT2ttc->Get("SRyield");                   hin[                  "SRyield_T2ttc"]->SetName(                  "SRyield_T2ttc");
    hin[              "SRyield_gen_T2ttc"] = (TH3D*)fT2ttc->Get("SRyield_gen");               hin[              "SRyield_gen_T2ttc"]->SetName(              "SRyield_gen_T2ttc");
    hin[    "CR1l_sigcontamination_T2ttc"] = (TH3D*)fT2ttc->Get("CR1l_sigcontamination");     hin[    "CR1l_sigcontamination_T2ttc"]->SetName(    "CR1l_sigcontamination_T2ttc");
    hin[    "CR2l_sigcontamination_T2ttc"] = (TH3D*)fT2ttc->Get("CR2l_sigcontamination");     hin[    "CR2l_sigcontamination_T2ttc"]->SetName(    "CR2l_sigcontamination_T2ttc");
    hin["CR1l_sigcontamination_gen_T2ttc"] = (TH3D*)fT2ttc->Get("CR1l_sigcontamination_gen"); hin["CR1l_sigcontamination_gen_T2ttc"]->SetName("CR1l_sigcontamination_gen_T2ttc");
    hin["CR2l_sigcontamination_gen_T2ttc"] = (TH3D*)fT2ttc->Get("CR2l_sigcontamination_gen"); hin["CR2l_sigcontamination_gen_T2ttc"]->SetName("CR2l_sigcontamination_gen_T2ttc");

    h[ "SRcont0b_T2tt"] = new TH2D( "SRcont0b_T2tt","",42,150,1200,25,0,650);
    h[ "SRcont2l_T2tt"] = new TH2D( "SRcont2l_T2tt","",42,150,1200,25,0,650);
    h[   "SRcont_T2tt"] = new TH2D(   "SRcont_T2tt","",42,150,1200,25,0,650);
    h[ "SRcont0b_T2tb"] = new TH2D( "SRcont0b_T2tb","",32,200,1000,18,0,450);
    h[ "SRcont2l_T2tb"] = new TH2D( "SRcont2l_T2tb","",32,200,1000,18,0,450);
    h[   "SRcont_T2tb"] = new TH2D(   "SRcont_T2tb","",32,200,1000,18,0,450);
    h[ "SRcont0b_T2bW"] = new TH2D( "SRcont0b_T2bW","",40,200,1200,25,0,650);
    h[ "SRcont2l_T2bW"] = new TH2D( "SRcont2l_T2bW","",40,200,1200,25,0,650);
    h[   "SRcont_T2bW"] = new TH2D(   "SRcont_T2bW","",40,200,1200,25,0,650);
    h["cSRcont0b_T2tt"] = new TH2D("cSRcont0b_T2tt","",42,150,1200,25,0,650);
    h["cSRcont2l_T2tt"] = new TH2D("cSRcont2l_T2tt","",42,150,1200,25,0,650);
    h[  "cSRcont_T2tt"] = new TH2D(  "cSRcont_T2tt","",42,150,1200,25,0,650);
    
    h[    "SRsum_T2tt"] = new TH2D(    "SRsum_T2tt","",42,150,1200,25,0,650);
    h[    "SRsum_T2tb"] = new TH2D(    "SRsum_T2tb","",32,200,1000,18,0,450);
    h[    "SRsum_T2bW"] = new TH2D(    "SRsum_T2bW","",40,200,1200,25,0,650);
    h[   "cSRsum_T2tt"] = new TH2D(   "cSRsum_T2tt","",42,150,1200,25,0,650);

    
    for(unsigned int x = 1; x<=hin["SRyield_T2tb"]->GetNbinsX();++x){
        for(unsigned int y = 1; y<=hin["SRyield_T2tb"]->GetNbinsY();++y){
            //std
            for(unsigned int b = 1; b<=27; ++b){
                double stop =hin["SRyield_T2tb"]->GetXaxis()->GetBinCenter(x);
                double lsp =hin["SRyield_T2tb"]->GetYaxis()->GetBinCenter(y);
                double SR, SR1l, SR2l, SR1l2l;
                //T2tt
                SR     = (hin["SRyield_T2tt"]->GetBinContent(x,y,b)+hin["SRyield_gen_T2tt"]->GetBinContent(x,y,b))/2.;
                SR1l   = (TMath::Max(0.,hin["SRyield_T2tt"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2tt"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tt"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2tt"]->GetBinContent(x,y,b)))/2.;
                SR2l   = (TMath::Max(0.,hin["SRyield_T2tt"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2tt"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tt"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2tt"]->GetBinContent(x,y,b)))/2.;
                SR1l2l = (TMath::Max(0.,hin["SRyield_T2tt"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2tt"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2tt"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tt"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2tt"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2tt"]->GetBinContent(x,y,b)))/2.;
                if(SR>0&&stop>=150&&stop<=1200&&lsp>=0&&lsp<=650){
                    h[   "SRsum_T2tt"]->Fill(stop,lsp, SR);
                    h[  "SRcont_T2tt"]->Fill(stop,lsp,(SR-SR1l2l));
                    h["SRcont0b_T2tt"]->Fill(stop,lsp,(SR-SR1l  ));
                    h["SRcont2l_T2tt"]->Fill(stop,lsp,(SR-SR2l  ));
                    
                }
                //T2tb
                SR     = (hin["SRyield_T2tb"]->GetBinContent(x,y,b)+hin["SRyield_gen_T2tb"]->GetBinContent(x,y,b))/2.;
                SR1l   = (TMath::Max(0.,hin["SRyield_T2tb"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2tb"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tb"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2tb"]->GetBinContent(x,y,b)))/2.;
                SR2l   = (TMath::Max(0.,hin["SRyield_T2tb"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2tb"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tb"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2tb"]->GetBinContent(x,y,b)))/2.;
                SR1l2l = (TMath::Max(0.,hin["SRyield_T2tb"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2tb"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2tb"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2tb"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2tb"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2tb"]->GetBinContent(x,y,b)))/2.;
                if(SR>0&&stop>=200&&stop<=1000&&lsp>=0&&lsp<=450){
                    h[   "SRsum_T2tb"]->Fill(stop,lsp, SR);
                    h[  "SRcont_T2tb"]->Fill(stop,lsp,(SR-SR1l2l));
                    h["SRcont0b_T2tb"]->Fill(stop,lsp,(SR-SR1l  ));
                    h["SRcont2l_T2tb"]->Fill(stop,lsp,(SR-SR2l  ));
                    
                }
                //T2bW
                SR     = (hin["SRyield_T2bW"]->GetBinContent(x,y,b)+hin["SRyield_gen_T2bW"]->GetBinContent(x,y,b))/2.;
                SR1l   = (TMath::Max(0.,hin["SRyield_T2bW"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2bW"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2bW"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2bW"]->GetBinContent(x,y,b)))/2.;
                SR2l   = (TMath::Max(0.,hin["SRyield_T2bW"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2bW"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2bW"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2bW"]->GetBinContent(x,y,b)))/2.;
                SR1l2l = (TMath::Max(0.,hin["SRyield_T2bW"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2bW"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2bW"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2bW"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2bW"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2bW"]->GetBinContent(x,y,b)))/2.;
                if(SR>0&&stop>=200&&stop<=1200&&lsp>=0&&lsp<=650){
                    h[   "SRsum_T2bW"]->Fill(stop,lsp, SR);
                    h[  "SRcont_T2bW"]->Fill(stop,lsp,(SR-SR1l2l));
                    h["SRcont0b_T2bW"]->Fill(stop,lsp,(SR-SR1l  ));
                    h["SRcont2l_T2bW"]->Fill(stop,lsp,(SR-SR2l  ));
                    
                }
            }
            //compressed
            for(unsigned int b = 1; b<=4; ++b){
                double stop =hin["SRyield_T2ttc"]->GetXaxis()->GetBinCenter(x);
                double lsp =hin["SRyield_T2ttc"]->GetYaxis()->GetBinCenter(y);
                double SR, SR1l, SR2l, SR1l2l;
                //T2tt
                SR     = (hin["SRyield_T2ttc"]->GetBinContent(x,y,b)+hin["SRyield_gen_T2ttc"]->GetBinContent(x,y,b))/2.;
                SR1l   = (TMath::Max(0.,hin["SRyield_T2ttc"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2ttc"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2ttc"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2ttc"]->GetBinContent(x,y,b)))/2.;
                SR2l   = (TMath::Max(0.,hin["SRyield_T2ttc"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2ttc"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2ttc"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2ttc"]->GetBinContent(x,y,b)))/2.;
                SR1l2l = (TMath::Max(0.,hin["SRyield_T2ttc"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_T2ttc"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_T2ttc"]->GetBinContent(x,y,b))+TMath::Max(0.,hin["SRyield_gen_T2ttc"]->GetBinContent(x,y,b)-hin["CR2l_sigcontamination_gen_T2ttc"]->GetBinContent(x,y,b)-hin["CR1l_sigcontamination_gen_T2ttc"]->GetBinContent(x,y,b)))/2.;
                if(SR>0&&stop>=150&&stop<=1200&&lsp>=0&&lsp<=650){
                    h[   "cSRsum_T2tt"]->Fill(stop,lsp, SR);
                    h[  "cSRcont_T2tt"]->Fill(stop,lsp,(SR-SR1l2l));
                    h["cSRcont0b_T2tt"]->Fill(stop,lsp,(SR-SR1l  ));
                    h["cSRcont2l_T2tt"]->Fill(stop,lsp,(SR-SR2l  ));
                    
                }
            }
        }//y
    }//x
    h[   "SRcont_T2tt"]->Divide(h[ "SRsum_T2tt"]);
    h[ "SRcont0b_T2tt"]->Divide(h[ "SRsum_T2tt"]);
    h[ "SRcont2l_T2tt"]->Divide(h[ "SRsum_T2tt"]);
    h[   "SRcont_T2tb"]->Divide(h[ "SRsum_T2tb"]);
    h[ "SRcont0b_T2tb"]->Divide(h[ "SRsum_T2tb"]);
    h[ "SRcont2l_T2tb"]->Divide(h[ "SRsum_T2tb"]);
    h[   "SRcont_T2bW"]->Divide(h[ "SRsum_T2bW"]);
    h[ "SRcont0b_T2bW"]->Divide(h[ "SRsum_T2bW"]);
    h[ "SRcont2l_T2bW"]->Divide(h[ "SRsum_T2bW"]);
    h[  "cSRcont_T2tt"]->Divide(h["cSRsum_T2tt"]);
    h["cSRcont0b_T2tt"]->Divide(h["cSRsum_T2tt"]);
    h["cSRcont2l_T2tt"]->Divide(h["cSRsum_T2tt"]);
    TFile *f = new TFile("SignalContamination.root","RECREATE");
    f->cd();
    for(map<string,TH2D*>::iterator hi=    h.begin(); hi!=    h.end();++hi) hi->second->Write();
    f->Close();

}