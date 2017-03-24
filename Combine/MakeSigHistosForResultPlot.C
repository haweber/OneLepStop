{

TFile *f = new TFile("SignalDistribution_forresult.root","RECREATE");
TH1D *T2tt_900_300             = new TH1D("T2tt_900_300",            "",31,0,31);
TH1D *T2tt_900_300_gencorr     = new TH1D("T2tt_900_300_gencorr",    "",31,0,31);
TH1D *T2tt_900_300_contcorr    = new TH1D("T2tt_900_300_contcorr",   "",31,0,31);
TH1D *T2tt_900_300_gencontcorr = new TH1D("T2tt_900_300_gencontcorr","",31,0,31);
TH1D *T2tb_600_300             = new TH1D("T2tb_600_300",            "",31,0,31);
TH1D *T2tb_600_300_gencorr     = new TH1D("T2tb_600_300_gencorr",    "",31,0,31);
TH1D *T2tb_600_300_contcorr    = new TH1D("T2tb_600_300_contcorr",   "",31,0,31);
TH1D *T2tb_600_300_gencontcorr = new TH1D("T2tb_600_300_gencontcorr","",31,0,31);
TH1D *T2bW_900_50             = new TH1D("T2bW_900_50",            "",31,0,31);
TH1D *T2bW_900_50_gencorr     = new TH1D("T2bW_900_50_gencorr",    "",31,0,31);
TH1D *T2bW_900_50_contcorr    = new TH1D("T2bW_900_50_contcorr",   "",31,0,31);
TH1D *T2bW_900_50_gencontcorr = new TH1D("T2bW_900_50_gencontcorr","",31,0,31);
    TH1D *T2bW_600_300             = new TH1D("T2bW_600_300",            "",31,0,31);
    TH1D *T2bW_600_300_gencorr     = new TH1D("T2bW_600_300_gencorr",    "",31,0,31);
    TH1D *T2bW_600_300_contcorr    = new TH1D("T2bW_600_300_contcorr",   "",31,0,31);
    TH1D *T2bW_600_300_gencontcorr = new TH1D("T2bW_600_300_gencontcorr","",31,0,31);
    
    
TFile *tt = TFile::Open("Histos_std_Signal_T2tt.root");
TH3D *SRtt   = (TH3D*)tt->Get("SRyield");                   SRtt  ->SetName("SRtt");
TH3D *CR0tt  = (TH3D*)tt->Get("CR1l_sigcontamination");     CR0tt ->SetName("CR0tt");
TH3D *CR2tt  = (TH3D*)tt->Get("CR2l_sigcontamination");     CR2tt ->SetName("CR2tt");
TH3D *SRttg  = (TH3D*)tt->Get("SRyield_gen");               SRttg ->SetName("SRttg");
TH3D *CR0ttg = (TH3D*)tt->Get("CR1l_sigcontamination_gen"); CR0ttg->SetName("CR0ttg");
TH3D *CR2ttg = (TH3D*)tt->Get("CR2l_sigcontamination_gen"); CR2ttg->SetName("CR2ttg");
TFile *tb = TFile::Open("Histos_std_Signal_T2tb.root");
TH3D *SRtb   = (TH3D*)tb->Get("SRyield");                   SRtb  ->SetName("SRtb");
TH3D *CR0tb  = (TH3D*)tb->Get("CR1l_sigcontamination");     CR0tb ->SetName("CR0tb");
TH3D *CR2tb  = (TH3D*)tb->Get("CR2l_sigcontamination");     CR2tb ->SetName("CR2tb");
TH3D *SRtbg  = (TH3D*)tb->Get("SRyield_gen");               SRtbg ->SetName("SRtbg");
TH3D *CR0tbg = (TH3D*)tb->Get("CR1l_sigcontamination_gen"); CR0tbg->SetName("CR0tbg");
TH3D *CR2tbg = (TH3D*)tb->Get("CR2l_sigcontamination_gen"); CR2tbg->SetName("CR2tbg");
TFile *bW = TFile::Open("Histos_std_Signal_T2bW.root");
TH3D *SRbW   = (TH3D*)bW->Get("SRyield");                   SRbW  ->SetName("SRbW");
TH3D *CR0bW  = (TH3D*)bW->Get("CR1l_sigcontamination");     CR0bW ->SetName("CR0bW");
TH3D *CR2bW  = (TH3D*)bW->Get("CR2l_sigcontamination");     CR2bW ->SetName("CR2bW");
TH3D *SRbWg  = (TH3D*)bW->Get("SRyield_gen");               SRbWg ->SetName("SRbWg");
TH3D *CR0bWg = (TH3D*)bW->Get("CR1l_sigcontamination_gen"); CR0bWg->SetName("CR0bWg");
TH3D *CR2bWg = (TH3D*)bW->Get("CR2l_sigcontamination_gen"); CR2bWg->SetName("CR2bWg");
    
    
    TFile *ctt = TFile::Open("Histos_compressed_Signal_T2tt.root");
    TH3D *cSRtt   = (TH3D*)ctt->Get("SRyield");                   cSRtt  ->SetName("cSRtt");
    TH3D *cCR0tt  = (TH3D*)ctt->Get("CR1l_sigcontamination");     cCR0tt ->SetName("cCR0tt");
    TH3D *cCR2tt  = (TH3D*)ctt->Get("CR2l_sigcontamination");     cCR2tt ->SetName("cCR2tt");
    TH3D *cSRttg  = (TH3D*)ctt->Get("SRyield_gen");               cSRttg ->SetName("cSRttg");
    TH3D *cCR0ttg = (TH3D*)ctt->Get("CR1l_sigcontamination_gen"); cCR0ttg->SetName("cCR0ttg");
    TH3D *cCR2ttg = (TH3D*)ctt->Get("CR2l_sigcontamination_gen"); cCR2ttg->SetName("cCR2ttg");
    TFile *ctb = TFile::Open("Histos_compressed_Signal_T2tb.root");
    TH3D *cSRtb   = (TH3D*)ctb->Get("SRyield");                   cSRtb  ->SetName("cSRtb");
    TH3D *cCR0tb  = (TH3D*)ctb->Get("CR1l_sigcontamination");     cCR0tb ->SetName("cCR0tb");
    TH3D *cCR2tb  = (TH3D*)ctb->Get("CR2l_sigcontamination");     cCR2tb ->SetName("cCR2tb");
    TH3D *cSRtbg  = (TH3D*)ctb->Get("SRyield_gen");               cSRtbg ->SetName("cSRtbg");
    TH3D *cCR0tbg = (TH3D*)ctb->Get("CR1l_sigcontamination_gen"); cCR0tbg->SetName("cCR0tbg");
    TH3D *cCR2tbg = (TH3D*)ctb->Get("CR2l_sigcontamination_gen"); cCR2tbg->SetName("cCR2tbg");
    TFile *cbW = TFile::Open("Histos_compressed_Signal_T2bW.root");
    TH3D *cSRbW   = (TH3D*)cbW->Get("SRyield");                   cSRbW  ->SetName("cSRbW");
    TH3D *cCR0bW  = (TH3D*)cbW->Get("CR1l_sigcontamination");     cCR0bW ->SetName("cCR0bW");
    TH3D *cCR2bW  = (TH3D*)cbW->Get("CR2l_sigcontamination");     cCR2bW ->SetName("cCR2bW");
    TH3D *cSRbWg  = (TH3D*)cbW->Get("SRyield_gen");               cSRbWg ->SetName("cSRbWg");
    TH3D *cCR0bWg = (TH3D*)cbW->Get("CR1l_sigcontamination_gen"); cCR0bWg->SetName("cCR0bWg");
    TH3D *cCR2bWg = (TH3D*)cbW->Get("CR2l_sigcontamination_gen"); cCR2bWg->SetName("cCR2bWg");

for(int b=1; b<=27; ++b){
	double y, ys, gy, gys;
	double yerr, yserr, gyerr, gyserr;
	int bin;

	TH3D *h1  = (TH3D*)SRtt ->Clone("h1");
	TH3D *h1g = (TH3D*)SRttg->Clone("h1g");
	bin = h1->FindBin(900,300,(float)b-0.5);
	y = h1->GetBinContent(bin);
	yerr = h1->GetBinError(bin);
	gy = (y+h1g->GetBinContent(bin))/2.;
	gyerr = sqrt((pow(yerr,2)+pow(h1g->GetBinError(bin),2))/sqrt(2.));
	h1->Add(CR0tt,-1);
	h1->Add(CR2tt,-1);
	h1g->Add(CR0ttg,-1);
	h1g->Add(CR2ttg,-1);
	ys = TMath::Max(0.,h1->GetBinContent(bin));
	yserr = (ys>0) ? h1->GetBinError(bin) : 0;
	gys = TMath::Max(0.,h1g->GetBinContent(bin));
	gyserr = (gys>0) ? h1g->GetBinError(bin) : 0;
	gys = (ys + gys)/2.;
	gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));

	T2tt_900_300            ->SetBinContent(b,y);
	T2tt_900_300            ->SetBinError(  b,yerr);
	T2tt_900_300_gencorr    ->SetBinContent(b,gy);
	T2tt_900_300_gencorr    ->SetBinError(  b,gyerr);
	T2tt_900_300_contcorr   ->SetBinContent(b,ys);
	T2tt_900_300_contcorr   ->SetBinError(  b,yserr);
	T2tt_900_300_gencontcorr->SetBinContent(b,gys);
	T2tt_900_300_gencontcorr->SetBinError(  b,gyserr);
}

for(int b=1; b<=27; ++b){
	double y, ys, gy, gys;
	double yerr, yserr, gyerr, gyserr;
	int bin;

	TH3D *h2  = (TH3D*)SRtb ->Clone("h2");
	TH3D *h2g = (TH3D*)SRtbg->Clone("h2g");
	bin = h2->FindBin(600,300,(float)b-0.5);
	y = h2->GetBinContent(bin);
	yerr = h2->GetBinError(bin);
	gy = (y+h2g->GetBinContent(bin))/2.;
	gyerr = sqrt((pow(yerr,2)+pow(h2g->GetBinError(bin),2))/sqrt(2.));
	h2->Add(CR0tb,-1);
	h2->Add(CR2tb,-1);
	h2g->Add(CR0tbg,-1);
	h2g->Add(CR2tbg,-1);
	ys = TMath::Max(0.,h2->GetBinContent(bin));
	yserr = (ys>0) ? h2->GetBinError(bin) : 0;
	gys = TMath::Max(0.,h2g->GetBinContent(bin));
	gyserr = (gys>0) ? h2g->GetBinError(bin) : 0;
	gys = (ys + gys)/2.;
	gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));

	T2tb_600_300            ->SetBinContent(b,y);
	T2tb_600_300            ->SetBinError(  b,yerr);
	T2tb_600_300_gencorr    ->SetBinContent(b,gy);
	T2tb_600_300_gencorr    ->SetBinError(  b,gyerr);
	T2tb_600_300_contcorr   ->SetBinContent(b,ys);
	T2tb_600_300_contcorr   ->SetBinError(  b,yserr);
	T2tb_600_300_gencontcorr->SetBinContent(b,gys);
	T2tb_600_300_gencontcorr->SetBinError(  b,gyserr);

}

for(int b=1; b<=27; ++b){
	double y, ys, gy, gys;
	double yerr, yserr, gyerr, gyserr;
	int bin;

	TH3D *h3  = (TH3D*)SRbW ->Clone("h3");
	TH3D *h3g = (TH3D*)SRbWg->Clone("h3g");
	bin = h3->FindBin(900,50,(float)b-0.5);
	y = h3->GetBinContent(bin);
	yerr = h3->GetBinError(bin);
	gy = (y+h3g->GetBinContent(bin))/2.;
	gyerr = sqrt((pow(yerr,2)+pow(h3g->GetBinError(bin),2))/sqrt(2.));
	h3->Add(CR0bW,-1);
	h3->Add(CR2bW,-1);
	h3g->Add(CR0bWg,-1);
	h3g->Add(CR2bWg,-1);
	ys = TMath::Max(0.,h3->GetBinContent(bin));
	yserr = (ys>0) ? h3->GetBinError(bin) : 0;
	gys = TMath::Max(0.,h3g->GetBinContent(bin));
	gyserr = (gys>0) ? h3g->GetBinError(bin) : 0;
	gys = (ys + gys)/2.;
	gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));

	T2bW_900_50            ->SetBinContent(b,y);
	T2bW_900_50            ->SetBinError(  b,yerr);
	T2bW_900_50_gencorr    ->SetBinContent(b,gy);
	T2bW_900_50_gencorr    ->SetBinError(  b,gyerr);
	T2bW_900_50_contcorr   ->SetBinContent(b,ys);
	T2bW_900_50_contcorr   ->SetBinError(  b,yserr);
	T2bW_900_50_gencontcorr->SetBinContent(b,gys);
	T2bW_900_50_gencontcorr->SetBinError(  b,gyserr);

}
    
for(int b=1; b<=27; ++b){
        double y, ys, gy, gys;
        double yerr, yserr, gyerr, gyserr;
        int bin;
        
        TH3D *h4  = (TH3D*)SRbW ->Clone("h4");
        TH3D *h4g = (TH3D*)SRbWg->Clone("h4g");
        bin = h4->FindBin(600,300,(float)b-0.5);
        y = h4->GetBinContent(bin);
        yerr = h4->GetBinError(bin);
        gy = (y+h4g->GetBinContent(bin))/2.;
        gyerr = sqrt((pow(yerr,2)+pow(h4g->GetBinError(bin),2))/sqrt(2.));
        h4->Add(CR0bW,-1);
        h4->Add(CR2bW,-1);
        h4g->Add(CR0bWg,-1);
        h4g->Add(CR2bWg,-1);
        ys = TMath::Max(0.,h4->GetBinContent(bin));
        yserr = (ys>0) ? h4->GetBinError(bin) : 0;
        gys = TMath::Max(0.,h4g->GetBinContent(bin));
        gyserr = (gys>0) ? h4g->GetBinError(bin) : 0;
        gys = (ys + gys)/2.;
        gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));
        
        T2bW_600_300            ->SetBinContent(b,y);
        T2bW_600_300            ->SetBinError(  b,yerr);
        T2bW_600_300_gencorr    ->SetBinContent(b,gy);
        T2bW_600_300_gencorr    ->SetBinError(  b,gyerr);
        T2bW_600_300_contcorr   ->SetBinContent(b,ys);
        T2bW_600_300_contcorr   ->SetBinError(  b,yserr);
        T2bW_600_300_gencontcorr->SetBinContent(b,gys);
        T2bW_600_300_gencontcorr->SetBinError(  b,gyserr);
        
    }
    
    for(int b=1; b<=4; ++b){
        double y, ys, gy, gys;
        double yerr, yserr, gyerr, gyserr;
        int bin;
        
        TH3D *ch1  = (TH3D*)cSRtt ->Clone("ch1");
        TH3D *ch1g = (TH3D*)cSRttg->Clone("ch1g");
        bin = ch1->FindBin(900,300,(float)b-0.5);
        y = ch1->GetBinContent(bin);
        yerr = ch1->GetBinError(bin);
        gy = (y+ch1g->GetBinContent(bin))/2.;
        gyerr = sqrt((pow(yerr,2)+pow(ch1g->GetBinError(bin),2))/sqrt(2.));
        ch1->Add(cCR0tt,-1);
        ch1->Add(cCR2tt,-1);
        ch1g->Add(cCR0ttg,-1);
        ch1g->Add(cCR2ttg,-1);
        ys = TMath::Max(0.,ch1->GetBinContent(bin));
        yserr = (ys>0) ? ch1->GetBinError(bin) : 0;
        gys = TMath::Max(0.,ch1g->GetBinContent(bin));
        gyserr = (gys>0) ? ch1g->GetBinError(bin) : 0;
        gys = (ys + gys)/2.;
        gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));
        
        T2tt_900_300            ->SetBinContent(b+27,y);
        T2tt_900_300            ->SetBinError(  b+27,yerr);
        T2tt_900_300_gencorr    ->SetBinContent(b+27,gy);
        T2tt_900_300_gencorr    ->SetBinError(  b+27,gyerr);
        T2tt_900_300_contcorr   ->SetBinContent(b+27,ys);
        T2tt_900_300_contcorr   ->SetBinError(  b+27,yserr);
        T2tt_900_300_gencontcorr->SetBinContent(b+27,gys);
        T2tt_900_300_gencontcorr->SetBinError(  b+27,gyserr);
    }
    
    for(int b=1; b<=4; ++b){
        double y, ys, gy, gys;
        double yerr, yserr, gyerr, gyserr;
        int bin;
        
        TH3D *ch2  = (TH3D*)cSRtb ->Clone("h2");
        TH3D *ch2g = (TH3D*)cSRtbg->Clone("h2g");
        bin = ch2->FindBin(600,300,(float)b-0.5);
        y = ch2->GetBinContent(bin);
        yerr = ch2->GetBinError(bin);
        gy = (y+ch2g->GetBinContent(bin))/2.;
        gyerr = sqrt((pow(yerr,2)+pow(ch2g->GetBinError(bin),2))/sqrt(2.));
        ch2->Add(cCR0tb,-1);
        ch2->Add(cCR2tb,-1);
        ch2g->Add(cCR0tbg,-1);
        ch2g->Add(cCR2tbg,-1);
        ys = TMath::Max(0.,ch2->GetBinContent(bin));
        yserr = (ys>0) ? ch2->GetBinError(bin) : 0;
        gys = TMath::Max(0.,ch2g->GetBinContent(bin));
        gyserr = (gys>0) ? ch2g->GetBinError(bin) : 0;
        gys = (ys + gys)/2.;
        gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));
        
        T2tb_600_300            ->SetBinContent(b+27,y);
        T2tb_600_300            ->SetBinError(  b+27,yerr);
        T2tb_600_300_gencorr    ->SetBinContent(b+27,gy);
        T2tb_600_300_gencorr    ->SetBinError(  b+27,gyerr);
        T2tb_600_300_contcorr   ->SetBinContent(b+27,ys);
        T2tb_600_300_contcorr   ->SetBinError(  b+27,yserr);
        T2tb_600_300_gencontcorr->SetBinContent(b+27,gys);
        T2tb_600_300_gencontcorr->SetBinError(  b+27,gyserr);
        
    }
    
    for(int b=1; b<=4; ++b){
        double y, ys, gy, gys;
        double yerr, yserr, gyerr, gyserr;
        int bin;
        
        TH3D *ch3  = (TH3D*)cSRbW ->Clone("h3");
        TH3D *ch3g = (TH3D*)cSRbWg->Clone("h3g");
        bin = ch3->FindBin(900,50,(float)b-0.5);
        y = ch3->GetBinContent(bin);
        yerr = ch3->GetBinError(bin);
        gy = (y+ch3g->GetBinContent(bin))/2.;
        gyerr = sqrt((pow(yerr,2)+pow(ch3g->GetBinError(bin),2))/sqrt(2.));
        ch3->Add(cCR0bW,-1);
        ch3->Add(cCR2bW,-1);
        ch3g->Add(cCR0bWg,-1);
        ch3g->Add(cCR2bWg,-1);
        ys = TMath::Max(0.,ch3->GetBinContent(bin));
        yserr = (ys>0) ? ch3->GetBinError(bin) : 0;
        gys = TMath::Max(0.,ch3g->GetBinContent(bin));
        gyserr = (gys>0) ? ch3g->GetBinError(bin) : 0;
        gys = (ys + gys)/2.;
        gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));
        
        T2bW_900_50            ->SetBinContent(b+27,y);
        T2bW_900_50            ->SetBinError(  b+27,yerr);
        T2bW_900_50_gencorr    ->SetBinContent(b+27,gy);
        T2bW_900_50_gencorr    ->SetBinError(  b+27,gyerr);
        T2bW_900_50_contcorr   ->SetBinContent(b+27,ys);
        T2bW_900_50_contcorr   ->SetBinError(  b+27,yserr);
        T2bW_900_50_gencontcorr->SetBinContent(b+27,gys);
        T2bW_900_50_gencontcorr->SetBinError(  b+27,gyserr);
        
    }
    for(int b=1; b<=4; ++b){
        double y, ys, gy, gys;
        double yerr, yserr, gyerr, gyserr;
        int bin;
        
        TH3D *ch4  = (TH3D*)cSRbW ->Clone("h4");
        TH3D *ch4g = (TH3D*)cSRbWg->Clone("h4g");
        bin = ch4->FindBin(900,50,(float)b-0.5);
        y = ch4->GetBinContent(bin);
        yerr = ch4->GetBinError(bin);
        gy = (y+ch4g->GetBinContent(bin))/2.;
        gyerr = sqrt((pow(yerr,2)+pow(ch4g->GetBinError(bin),2))/sqrt(2.));
        ch4->Add(cCR0bW,-1);
        ch4->Add(cCR2bW,-1);
        ch4g->Add(cCR0bWg,-1);
        ch4g->Add(cCR2bWg,-1);
        ys = TMath::Max(0.,ch4->GetBinContent(bin));
        yserr = (ys>0) ? ch4->GetBinError(bin) : 0;
        gys = TMath::Max(0.,ch4g->GetBinContent(bin));
        gyserr = (gys>0) ? ch4g->GetBinError(bin) : 0;
        gys = (ys + gys)/2.;
        gyserr = sqrt((pow(yserr,2)+pow(gyserr,2))/sqrt(2.));
        
        T2bW_600_300            ->SetBinContent(b+27,y);
        T2bW_600_300            ->SetBinError(  b+27,yerr);
        T2bW_600_300_gencorr    ->SetBinContent(b+27,gy);
        T2bW_600_300_gencorr    ->SetBinError(  b+27,gyerr);
        T2bW_600_300_contcorr   ->SetBinContent(b+27,ys);
        T2bW_600_300_contcorr   ->SetBinError(  b+27,yserr);
        T2bW_600_300_gencontcorr->SetBinContent(b+27,gys);
        T2bW_600_300_gencontcorr->SetBinError(  b+27,gyserr);
        
    }

f->cd();
T2tt_900_300            ->Write();
T2tt_900_300_gencorr    ->Write();
T2tt_900_300_contcorr   ->Write();
T2tt_900_300_gencontcorr->Write();
T2tb_600_300            ->Write();
T2tb_600_300_gencorr    ->Write();
T2tb_600_300_contcorr   ->Write();
T2tb_600_300_gencontcorr->Write();
T2bW_900_50             ->Write();
T2bW_900_50_gencorr     ->Write();
T2bW_900_50_contcorr    ->Write();
T2bW_900_50_gencontcorr ->Write();
    T2bW_600_300            ->Write();
    T2bW_600_300_gencorr    ->Write();
    T2bW_600_300_contcorr   ->Write();
    T2bW_600_300_gencontcorr->Write();
f->Close();

}