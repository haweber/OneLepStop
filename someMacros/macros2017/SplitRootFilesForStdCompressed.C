{

    vector<string> Zhisto;
    Zhisto.push_back("yield");
    Zhisto.push_back("mcStatsDN");
    Zhisto.push_back("mcStatsUP");
    Zhisto.push_back("lepSFDN");
    Zhisto.push_back("lepSFUP");
    Zhisto.push_back("btagLightDN");
    Zhisto.push_back("btagLightUP");
    Zhisto.push_back("btagHeavyDN");
    Zhisto.push_back("btagHeavyUP");
    Zhisto.push_back("PUdown");
    Zhisto.push_back("PUup");
    Zhisto.push_back("pdfDN");
    Zhisto.push_back("pdfUP");
    Zhisto.push_back("alphaSDN");
    Zhisto.push_back("alphaSUP");
    Zhisto.push_back("Q2DN");
    Zhisto.push_back("Q2UP");
    Zhisto.push_back("jesDN");
    Zhisto.push_back("jesUP");
    Zhisto.push_back("ISRnjetsDown");
    Zhisto.push_back("ISRnjetsUp");
    Zhisto.push_back("normalizationDN");
    Zhisto.push_back("normalizationUP");
    Zhisto.push_back("total");
    map<string,TH1D*> hZ;
    TFile *fZ = TFile::Open("ZNuNu_BkgEst.root");
    for(unsigned int i = 0; i<Zhisto.size();++i){
        hZ[Zhisto[i] ] = (TH1D*)fZ->Get(Zhisto[i].c_str());
        string t = Zhisto[i] + "_std";
        hZ[t] = new TH1D(t.c_str(),"",27,0,27);
        hZ[t]->Sumw2();
        for(int b = 1; b<=27; ++b){
            hZ[t]->SetBinContent(b,hZ[Zhisto[i] ]->GetBinContent(b));
            hZ[t]->SetBinError(b,hZ[Zhisto[i] ]->GetBinError(b));
        }
        t = Zhisto[i] + "_compressed";
        hZ[t] = new TH1D(t.c_str(),"",4,0,4);
        hZ[t]->Sumw2();
        for(int b = 28; b<=31; ++b){
            int bin = b-27;
            hZ[t]->SetBinContent(bin,hZ[Zhisto[i] ]->GetBinContent(b));
            hZ[t]->SetBinError(bin,hZ[Zhisto[i] ]->GetBinError(b));
        }
    }
    TFile *fZs = new TFile("Znunu_BkgEst_std.root","RECREATE");
    fZs->cd();
    for(unsigned int i = 0; i<Zhisto.size();++i){
        string t = Zhisto[i] + "_std";
        hZ[t]->Write(Zhisto[i].c_str(),TObject::kOverwrite);
    }
    fZs->Close();
    TFile *fZc = new TFile("Znunu_BkgEst_compressed.root","RECREATE");
    fZc->cd();
    for(unsigned int i = 0; i<Zhisto.size();++i){
        string t = Zhisto[i] + "_compressed";
        hZ[t]->Write(Zhisto[i].c_str(),TObject::kOverwrite);
    }
    fZc->Close();
    
    TFile *ftt1l = TFile::Open("bkgEst_1lepFromTop__corridor_bins__histos.root");
    //TH1D *htt1lold = (TH1D*)ftt1l->Get("srMC");
    TH1D *htt1lold = (TH1D*)ftt1l->Get("ee1lep_fromTop_yield");
    TH1D *htt1l = new TH1D("ee1lep_fromTop_yield","",4,0,4);
    htt1l->SetBinContent(1,htt1lold->GetBinContent(1));
    htt1l->SetBinContent(2,htt1lold->GetBinContent(2));
    htt1l->SetBinContent(3,htt1lold->GetBinContent(3));
    htt1l->SetBinContent(4,htt1lold->GetBinContent(4));
    htt1l->SetBinError(1,htt1lold->GetBinContent(1));
    htt1l->SetBinError(2,htt1lold->GetBinContent(2));
    htt1l->SetBinError(3,htt1lold->GetBinContent(3));
    htt1l->SetBinError(4,htt1lold->GetBinContent(4));
    /*
    htt1l->SetBinContent(1,htt1lold->GetBinContent(28));
    htt1l->SetBinContent(2,htt1lold->GetBinContent(29));
    htt1l->SetBinContent(3,htt1lold->GetBinContent(30));
    htt1l->SetBinContent(4,htt1lold->GetBinContent(31));
    htt1l->SetBinError(1,htt1lold->GetBinContent(28));
    htt1l->SetBinError(2,htt1lold->GetBinContent(29));
    htt1l->SetBinError(3,htt1lold->GetBinContent(30));
    htt1l->SetBinError(4,htt1lold->GetBinContent(31));
     *//*
    htt1l->SetBinContent(1,5.6);
    htt1l->SetBinContent(2,1.1);
    htt1l->SetBinContent(3,0.12);
    htt1l->SetBinContent(4,0.14);
    htt1l->SetBinError(1,5.6);
    htt1l->SetBinError(2,1.1);
    htt1l->SetBinError(3,0.12);
    htt1l->SetBinError(4,0.14);
        */
    TFile *ftt1lc = new TFile("TT1l_BkgEst_compressed.root","RECREATE");
    ftt1lc->cd();
    //htt1l->Write("ee1lep_fromTop_yield",TObject::kOverwrite);
    htt1l->Write("SR_Top",TObject::kOverwrite);
    ftt1lc->Close();

    cout << __LINE__ << endl;
    /*
    TFile *fW = TFile::Open("onelepwEstimates.root");
    map<string,TH1D*> hw;
    hw["onelepwBkg"] = (TH1D*)fW->Get("onelepwBkg");
    hw["estimate_datastats"] = (TH1D*)fW->Get("estimate_datastats");
    hw["estimate_mcstats"] = (TH1D*)fW->Get("estimate_mcstats");
    hw["variation_lepSFdown"] = (TH1D*)fW->Get("variation_lepSFdown");
    hw["variation_lepSFup"] = (TH1D*)fW->Get("variation_lepSFup");
    hw["variation_qSquaredup"] = (TH1D*)fW->Get("variation_qSquaredup");
    hw["variation_qSquareddown"] = (TH1D*)fW->Get("variation_qSquareddown");
    hw["variation_alphaSup"] = (TH1D*)fW->Get("variation_alphaSup");
    hw["variation_alphaSdown"] = (TH1D*)fW->Get("variation_alphaSdown");
    hw["variation_METresup"] = (TH1D*)fW->Get("variation_METresup");
    hw["variation_METresdown"] = (TH1D*)fW->Get("variation_METresdown");
    hw["variation_contamup"] = (TH1D*)fW->Get("variation_contamup");
    hw["variation_contamdown"] = (TH1D*)fW->Get("variation_contamdown");
    //hw["variation_isrnjetsup"] = (TH1D*)fW->Get("variation_isrnjetsup");
    //hw["variation_isrnjetsdown"] = (TH1D*)fW->Get("variation_isrnjetsdown");
    hw["variation_JESup"] = (TH1D*)fW->Get("variation_JESup");
    hw["variation_JESdown"] = (TH1D*)fW->Get("variation_JESdown");
    hw["variation_btagHFup"] = (TH1D*)fW->Get("variation_btagHFup");
    hw["variation_btagHFdown"] = (TH1D*)fW->Get("variation_btagHFdown");
    hw["variation_btagLFup"] = (TH1D*)fW->Get("variation_btagLFup");
    hw["variation_btagLFdown"] = (TH1D*)fW->Get("variation_btagLFdown");
    hw["variation_pdfup"] = (TH1D*)fW->Get("variation_pdfup");
    hw["variation_pdfdown"] = (TH1D*)fW->Get("variation_pdfdown");
    hw["variation_PUup"] = (TH1D*)fW->Get("variation_PUup");
    hw["variation_PUdown"] = (TH1D*)fW->Get("variation_PUdown");
     */
    TFile *fW = TFile::Open("bkgEst_1lepFromW__corridor_bins__histos.root");
    map<string,TH1D*> hw;
    hw["onelepwBkg"] = (TH1D*)fW->Get("CR0b_yield");
    hw["estimate_datastats_up"] = (TH1D*)fW->Get("CR0b_dataStatsUp");
    hw["estimate_datastats_dn"] = (TH1D*)fW->Get("CR0b_dataStatsDn");
    hw["estimate_mcstats_up"] = (TH1D*)fW->Get("CR0b_mcStatsUp");
    hw["estimate_mcstats_dn"] = (TH1D*)fW->Get("CR0b_mcStatsDn");
    hw["variation_lepSFdown"] = (TH1D*)fW->Get("CR0b_lepSFDn");
    hw["variation_lepSFup"] = (TH1D*)fW->Get("CR0b_lepSFUp");
    hw["variation_qSquaredup"] = (TH1D*)fW->Get("CR0b_q2Up");
    hw["variation_qSquareddown"] = (TH1D*)fW->Get("CR0b_q2Dn");
    hw["variation_alphaSup"] = (TH1D*)fW->Get("CR0b_alphasUp");
    hw["variation_alphaSdown"] = (TH1D*)fW->Get("CR0b_alphasDn");
    hw["variation_METresup"] = (TH1D*)fW->Get("CR0b_metResUp");
    hw["variation_METresdown"] = (TH1D*)fW->Get("CR0b_metResDn");
    hw["variation_contamup"] = (TH1D*)fW->Get("CR0b_impurityUp");
    hw["variation_contamdown"] = (TH1D*)fW->Get("CR0b_impurityDn");
    //hw["variation_isrnjetsup"] = (TH1D*)fW->Get("CR0b_ISRUp");
    //hw["variation_isrnjetsdown"] = (TH1D*)fW->Get("CR0b_ISRDn");
    hw["variation_JESup"] = (TH1D*)fW->Get("CR0b_jesUp");
    hw["variation_JESdown"] = (TH1D*)fW->Get("CR0b_jesDn");
    hw["variation_btagHFup"] = (TH1D*)fW->Get("CR0b_bTagEffHFUp");
    hw["variation_btagHFdown"] = (TH1D*)fW->Get("CR0b_bTagEffHFDn");
    hw["variation_btagLFup"] = (TH1D*)fW->Get("CR0b_bTagEffLFUp");
    hw["variation_btagLFdown"] = (TH1D*)fW->Get("CR0b_bTagEffLFDn");
    hw["variation_pdfup"] = (TH1D*)fW->Get("CR0b_pdfUp");
    hw["variation_pdfdown"] = (TH1D*)fW->Get("CR0b_pdfDn");
    hw["variation_PUup"] = (TH1D*)fW->Get("CR0b_pileupUp");
    hw["variation_PUdown"] = (TH1D*)fW->Get("CR0b_pileupDn");
    hw["variation_Wbup"] = (TH1D*)fW->Get("CR0b_hfXsecUp");
    hw["variation_Wbdn"] = (TH1D*)fW->Get("CR0b_hfXsecDn");
    map<string,TH1D*> hist1l;
    
    hist1l["CR1lyield"] = new TH1D("CR1lyield","",4,0,4);
    hist1l["mcStats_Up"] = new TH1D("mcStats_Up","",4,0,4);
    hist1l["mcStats_Dn"] = new TH1D("mcStats_Dn","",4,0,4);
    hist1l["Wb_Up"] = new TH1D("Wb_Up","",4,0,4);
    hist1l["Wb_Down"] = new TH1D("Wb_Dn","",4,0,4);
    hist1l["btag_HF_Up"] = new TH1D("bTagEffHF_Up","",4,0,4);
    hist1l["btag_HF_Down"] = new TH1D("bTagEffHF_Dn","",4,0,4);
    hist1l["btag_LF_Up"] = new TH1D("bTagEffLF_Up","",4,0,4);
    hist1l["btag_LF_Down"] = new TH1D("bTagEffLF_Dn","",4,0,4);
    hist1l["pdf_Up"] = new TH1D("pdf_Up","",4,0,4);
    hist1l["pdf_Dn"] = new TH1D("pdf_Dn","",4,0,4);
    hist1l["q2_Up"] = new TH1D("q2_Up","",4,0,4);
    hist1l["q2_Dn"] = new TH1D("q2_Dn","",4,0,4);
    hist1l["lepSF_Up"] = new TH1D("lepSF_Up","",4,0,4);
    hist1l["lepSF_Down"] = new TH1D("lepSF_Dn","",4,0,4);
    hist1l["jes_Up"] = new TH1D("JES_Up","",4,0,4);
    hist1l["jes_Dn"] = new TH1D("JES_Dn","",4,0,4);
    hist1l["CRCont_Up"] = new TH1D("CRCont_Up","",4,0,4);
    hist1l["CRCont_Dn"] = new TH1D("CRCont_Dn","",4,0,4);
    //hist1l["metres_Up"] = new TH1D("metres_Up","",4,0,4);
    //hist1l["metres_Down"] = new TH1D("metres_Dn","",4,0,4);
    //hist1l["ISR_Up"] = new TH1D("ISR_Up","",4,0,4);
    //hist1l["ISR_Down"] = new TH1D("ISR_Dn","",4,0,4);
    hist1l["PU_Up"] = new TH1D("PU_Up","",4,0,4);
    hist1l["PU_Dn"] = new TH1D("PU_Dn","",4,0,4);
    hist1l["dataStats_Up"] = new TH1D("dataStats_Up","",4,0,4);
    hist1l["dataStats_Dn"] = new TH1D("dataStats_Dn","",4,0,4);
    cout << __LINE__ << endl;
    for(int i = 1; i<=4;++i){
        //int b = 27+i;
        int b = i;
        hist1l["CR1lyield"]->SetBinContent(i,hw["onelepwBkg"]->GetBinContent(b));
        hist1l["CR1lyield"]->SetBinError(i,hw["onelepwBkg"]->GetBinError(b));
        hist1l["mcStats_Up"]->SetBinContent(i,hw["estimate_mcstats_up"]->GetBinContent(b));
        hist1l["mcStats_Dn"]->SetBinContent(i,TMath::Max(0.,hw["estimate_mcstats_dn"]->GetBinContent(b)));
        hist1l["Wb_Up"]->SetBinContent(i,hw["variation_Wbup"]->GetBinContent(b));
        hist1l["Wb_Down"]->SetBinContent(i,hw["variation_Wbdn"]->GetBinContent(b));
        hist1l["btag_HF_Up"]->SetBinContent(i,hw["variation_btagHFup"]->GetBinContent(b));
        hist1l["btag_HF_Down"]->SetBinContent(i,hw["variation_btagHFdown"]->GetBinContent(b));
        hist1l["btag_LF_Up"]->SetBinContent(i,hw["variation_btagLFup"]->GetBinContent(b));
        hist1l["btag_LF_Down"]->SetBinContent(i,hw["variation_btagHFdown"]->GetBinContent(b));
        hist1l["pdf_Up"]->SetBinContent(i,hw["variation_pdfup"]->GetBinContent(b));
        hist1l["pdf_Dn"]->SetBinContent(i,hw["variation_pdfdown"]->GetBinContent(b));
        //hist1l["ISR_Up"]->SetBinContent(i,hw["variation_isrnjetsup"]->GetBinContent(b));
        //hist1l["ISR_Down"]->SetBinContent(i,hw["variation_isrnjetsdown"]->GetBinContent(b));
        hist1l["q2_Up"]->SetBinContent(i,hw["variation_qSquaredup"]->GetBinContent(b));
        hist1l["q2_Dn"]->SetBinContent(i,hw["variation_qSquareddown"]->GetBinContent(b));
        hist1l["jes_Up"]->SetBinContent(i,hw["variation_JESup"]->GetBinContent(b));
        hist1l["jes_Dn"]->SetBinContent(i,hw["variation_JESdown"]->GetBinContent(b));
        hist1l["PU_Up"]->SetBinContent(i,hw["variation_PUup"]->GetBinContent(b));
        hist1l["PU_Dn"]->SetBinContent(i,hw["variation_PUdown"]->GetBinContent(b));
        hist1l["CRCont_Up"]->SetBinContent(i,hw["variation_contamup"]->GetBinContent(b));
        hist1l["CRCont_Dn"]->SetBinContent(i,hw["variation_contamdown"]->GetBinContent(b));
        //hist1l["metres_Up"]->SetBinContent(i,hw["variation_METresup"]->GetBinContent(b));
        //hist1l["metres_Down"]->SetBinContent(i,hw["variation_METresdown"]->GetBinContent(b));
        hist1l["lepSF_Up"]->SetBinContent(i,hw["variation_lepSFup"]->GetBinContent(b));
        hist1l["lepSF_Down"]->SetBinContent(i,hw["variation_lepSFdown"]->GetBinContent(b));
        hist1l["dataStats_Up"]->SetBinContent(i,hw["estimate_datastats_up"]->GetBinContent(b));
        hist1l["dataStats_Dn"]->SetBinContent(i,TMath::Max(0.,hw["estimate_datastats_dn"]->GetBinContent(b)));
    }
    cout << __LINE__ << endl;
    TFile *fWc = new TFile("WJets_BkgEst_compressed.root","RECREATE");
    fWc->cd();
    for(map<string,TH1D*>::iterator h=    hist1l.begin(); h!=    hist1l.end();++h) {
     h->second->Write(h->second->GetName(),TObject::kOverwrite);
    }
    fWc->Close();


    
    cout << __LINE__ << endl;
    /*
    TFile *ftt2l = TFile::Open("lostlepEstimates.root");
    map<string,TH1D*> h2l;
    h2l["lostLepBkg"] = (TH1D*)ftt2l->Get("lostLepBkg");
    h2l["estimate_datastats"] = (TH1D*)ftt2l->Get("estimate_datastats");
    h2l["estimate_mcstats"] = (TH1D*)ftt2l->Get("estimate_mcstats");
    h2l["variation_lepSFup"] = (TH1D*)ftt2l->Get("variation_lepSFup");
    h2l["variation_lepSFdown"] = (TH1D*)ftt2l->Get("variation_lepSFdown");
    h2l["variation_qSquaredup"] = (TH1D*)ftt2l->Get("variation_qSquaredup");
    h2l["variation_qSquareddown"] = (TH1D*)ftt2l->Get("variation_qSquareddown");
    h2l["variation_alphaSup"] = (TH1D*)ftt2l->Get("variation_alphaSup");
    h2l["variation_alphaSdown"] = (TH1D*)ftt2l->Get("variation_alphaSdown");
    h2l["variation_cr2ltrigup"] = (TH1D*)ftt2l->Get("variation_cr2ltrigup");
    h2l["variation_cr2ltrigdown"] = (TH1D*)ftt2l->Get("variation_cr2ltrigdown");
    h2l["variation_METresup"] = (TH1D*)ftt2l->Get("variation_METresup");
    h2l["variation_METresdown"] = (TH1D*)ftt2l->Get("variation_METresdown");
    h2l["variation_isrnjetsup"] = (TH1D*)ftt2l->Get("variation_isrnjetsdown");
    h2l["variation_isrnjetsdown"] = (TH1D*)ftt2l->Get("variation_isrnjetsdown");
    h2l["variation_JESup"] = (TH1D*)ftt2l->Get("variation_JESup");
    h2l["variation_JESdown"] = (TH1D*)ftt2l->Get("variation_JESdown");
    h2l["variation_btagHFup"] = (TH1D*)ftt2l->Get("variation_btagHFup");
    h2l["variation_btagHFdown"] = (TH1D*)ftt2l->Get("variation_btagHFdown");
    h2l["variation_btagLFup"] = (TH1D*)ftt2l->Get("variation_btagLFup");
    h2l["variation_btagLFdown"] = (TH1D*)ftt2l->Get("variation_btagLFdown");
    //h2l["variation_trigeffup"] = (TH1D*)ftt2l->Get("variation_trigeffup");
    //h2l["variation_trigeffdown"] = (TH1D*)ftt2l->Get("variation_trigeffdown");
    h2l["variation_PUup"] = (TH1D*)ftt2l->Get("variation_PUup");
    h2l["variation_PUdown"] = (TH1D*)ftt2l->Get("variation_PUdown");
     */
    TFile *ftt2l = TFile::Open("bkgEst_lostLepton__corridor_bins__histos.root");
    map<string,TH1D*> h2l;
    h2l["lostLepBkg"] = (TH1D*)ftt2l->Get("CR2l_yield");
    h2l["estimate_datastats_up"] = (TH1D*)ftt2l->Get("CR2l_dataStatsUp");
    h2l["estimate_datastats_dn"] = (TH1D*)ftt2l->Get("CR2l_dataStatsDn");
    h2l["estimate_mcstats_up"] = (TH1D*)ftt2l->Get("CR2l_mcStatsUp");
    h2l["estimate_mcstats_dn"] = (TH1D*)ftt2l->Get("CR2l_mcStatsDn");
    h2l["variation_lepSFup"] = (TH1D*)ftt2l->Get("CR2l_lepSFUp");
    h2l["variation_lepSFdown"] = (TH1D*)ftt2l->Get("CR2l_lepSFDn");
    h2l["variation_qSquaredup"] = (TH1D*)ftt2l->Get("CR2l_q2Up");
    h2l["variation_qSquareddown"] = (TH1D*)ftt2l->Get("CR2l_q2Dn");
    h2l["variation_alphaSup"] = (TH1D*)ftt2l->Get("CR2l_alphasUp");
    h2l["variation_alphaSdown"] = (TH1D*)ftt2l->Get("CR2l_alphasDn");
    h2l["variation_cr2ltrigup"] = (TH1D*)ftt2l->Get("CR2l_cr2lTriggerSFUp");
    h2l["variation_cr2ltrigdown"] = (TH1D*)ftt2l->Get("CR2l_cr2lTriggerSFDn");
    h2l["variation_METresup"] = (TH1D*)ftt2l->Get("CR2l_metResUp");
    h2l["variation_METresdown"] = (TH1D*)ftt2l->Get("CR2l_metResDn");
    h2l["variation_isrnjetsup"] = (TH1D*)ftt2l->Get("CR2l_ISRUp");
    h2l["variation_isrnjetsdown"] = (TH1D*)ftt2l->Get("CR2l_ISRDn");
    h2l["variation_JESup"] = (TH1D*)ftt2l->Get("CR2l_jesUp");
    h2l["variation_JESdown"] = (TH1D*)ftt2l->Get("CR2l_jesDn");
    h2l["variation_btagHFup"] = (TH1D*)ftt2l->Get("CR2l_bTagEffHFUp");
    h2l["variation_btagHFdown"] = (TH1D*)ftt2l->Get("CR2l_bTagEffHFDn");
    h2l["variation_btagLFup"] = (TH1D*)ftt2l->Get("CR2l_bTagEffLFUp");
    h2l["variation_btagLFdown"] = (TH1D*)ftt2l->Get("CR2l_bTagEffLFDn");
    //h2l["variation_trigeffup"] = (TH1D*)ftt2l->Get("variation_trigeffup");
    //h2l["variation_trigeffdown"] = (TH1D*)ftt2l->Get("variation_trigeffdown");
    h2l["variation_PUup"] = (TH1D*)ftt2l->Get("CR2l_pileupUp");
    h2l["variation_PUdown"] = (TH1D*)ftt2l->Get("CR2l_pileupDn");
    h2l["CR2l_metTTbarUp"] = (TH1D*)ftt2l->Get("CR2l_metTTbarUp");//xxx
    h2l["CR2l_metTTbarDn"] = (TH1D*)ftt2l->Get("CR2l_metTTbarDn");//xxx
    h2l["CR2l_tauSFUp"] = (TH1D*)ftt2l->Get("CR2l_tauSFUp");//xxx
    h2l["CR2l_tauSFDn"] = (TH1D*)ftt2l->Get("CR2l_tauSFDn");//xxx
    
    map<string,TH1D*> hist2l;
    hist2l["CR2l_yield"]           = new TH1D("CR2l_yield","",4,0,4);
    hist2l["CR2l_bTagEffHFUp"]     = new TH1D("CR2l_bTagEffHFUp","",4,0,4);
    hist2l["CR2l_bTagEffHFDn"]     = new TH1D("CR2l_bTagEffHFDn","",4,0,4);
    hist2l["CR2l_bTagEffLFUp"]     = new TH1D("CR2l_bTagEffLFUp","",4,0,4);
    hist2l["CR2l_bTagEffLFDn"]     = new TH1D("CR2l_bTagEffLFDn","",4,0,4);
    hist2l["CR2l_lepSFUp"]         = new TH1D("CR2l_lepSFUp","",4,0,4);
    hist2l["CR2l_lepSFDn"]         = new TH1D("CR2l_lepSFDn","",4,0,4);
    //hist2l["CR2l_ttbarSysPtUp"]  = new TH1D("CR2l_ttbarSysPtUp","",4,0,4);
    //hist2l["CR2l_ttbarSysPtDn"]  = new TH1D("CR2l_ttbarSysPtDn","",4,0,4);
    hist2l["CR2l_ISRUp"]           = new TH1D("CR2l_ISRUp","",4,0,4);
    hist2l["CR2l_ISRDn"]           = new TH1D("CR2l_ISRDn","",4,0,4);
    hist2l["CR2l_mcStatsUp"]       = new TH1D("CR2l_mcStatsUp","",4,0,4);
    hist2l["CR2l_mcStatsDn"]       = new TH1D("CR2l_mcStatsDn","",4,0,4);
    hist2l["CR2l_dataStatsDn"]     = new TH1D("CR2l_dataStatsDn","",4,0,4);
    hist2l["CR2l_dataStatsUp"]     = new TH1D("CR2l_dataStatsUp","",4,0,4);
    ////hist2l["CR2l_PDFup"]       = new TH1D("CR2l_PDFup","",4,0,4);
    ////hist2l["CR2l_PDFdown"]     = new TH1D("CR2l_PDFdown","",4,0,4);
    hist2l["CR2l_alphasUp"]        = new TH1D("CR2l_alphasUp","",4,0,4);
    hist2l["CR2l_alphasDn"]        = new TH1D("CR2l_alphasDn","",4,0,4);
    hist2l["CR2l_q2Dn"]            = new TH1D("CR2l_q2Dn","",4,0,4);
    hist2l["CR2l_q2Up"]            = new TH1D("CR2l_q2Up","",4,0,4);
    hist2l["CR2l_jesUp"]         = new TH1D("CR2l_jesUp","",4,0,4);//XXX
    hist2l["CR2l_jesDn"]         = new TH1D("CR2l_jesDn","",4,0,4);//XXX
    hist2l["CR2l_cr2lTriggerSFUp"] = new TH1D("CR2l_cr2lTriggerSFUp","",4,0,4);
    hist2l["CR2l_cr2lTriggerSFDn"] = new TH1D("CR2l_cr2lTriggerSFDn","",4,0,4);
    hist2l["CR2l_metResUp"]        = new TH1D("CR2l_metResUp","",4,0,4);
    hist2l["CR2l_metResDn"]        = new TH1D("CR2l_metResDn","",4,0,4);
    hist2l["CR2l_tauSFUp"]        = new TH1D("CR2l_tauSFUp","",4,0,4);
    hist2l["CR2l_tauSFDn"]        = new TH1D("CR2l_tauSFDn","",4,0,4);
    hist2l["CR2l_pileupUp"]        = new TH1D("CR2l_pileupUp","",4,0,4);
    hist2l["CR2l_pileupDn"]        = new TH1D("CR2l_pileupDn","",4,0,4);
    hist2l["CR2l_metTTbarUp"]        = new TH1D("CR2l_metTTbarUp","",4,0,4);
    hist2l["CR2l_metTTbarDn"]        = new TH1D("CR2l_metTTbarDn","",4,0,4);
    cout << __LINE__ << endl;
    for(int i = 1; i<=4;++i){
        //int b = 27+i;
        int b = i;
        hist2l["CR2l_yield"]->SetBinContent(i,h2l["lostLepBkg"]->GetBinContent(b));
        hist2l["CR2l_yield"]->SetBinError(i,h2l["lostLepBkg"]->GetBinError(b));
        hist2l["CR2l_bTagEffHFUp"]->SetBinContent(i,h2l["variation_btagHFup"]->GetBinContent(b));
        hist2l["CR2l_bTagEffHFDn"]->SetBinContent(i,h2l["variation_btagHFdown"]->GetBinContent(b));
        hist2l["CR2l_bTagEffLFUp"]->SetBinContent(i,h2l["variation_btagLFup"]->GetBinContent(b));
        hist2l["CR2l_bTagEffLFDn"]->SetBinContent(i,h2l["variation_btagLFdown"]->GetBinContent(b));
        hist2l["CR2l_lepSFUp"]->SetBinContent(i,h2l["variation_lepSFup"]->GetBinContent(b));
        hist2l["CR2l_lepSFDn"]->SetBinContent(i,h2l["variation_lepSFdown"]->GetBinContent(b));
        //hist2l["CR2l_ttbarSysPtUp"]->SetBinContent(i,h2l["lostLepBkg"]->GetBinContent(b));
        //hist2l["CR2l_ttbarSysPtDn"]->SetBinContent(i,h2l["lostLepBkg"]->GetBinContent(b));
        hist2l["CR2l_ISRUp"]->SetBinContent(i,h2l["variation_isrnjetsup"]->GetBinContent(b));
        hist2l["CR2l_ISRDn"]->SetBinContent(i,h2l["variation_isrnjetsdown"]->GetBinContent(b));
        hist2l["CR2l_mcStatsUp"]->SetBinContent(i,h2l["estimate_mcstats_up"]->GetBinContent(b));
        hist2l["CR2l_mcStatsDn"]->SetBinContent(i,TMath::Max(0.,h2l["estimate_mcstats_dn"]->GetBinContent(b)));
        hist2l["CR2l_dataStatsDn"]->SetBinContent(i,h2l["estimate_datastats_up"]->GetBinContent(b));
        hist2l["CR2l_dataStatsUp"]->SetBinContent(i,TMath::Max(0.,h2l["estimate_datastats_dn"]->GetBinContent(b)));
        ////hist2l["CR2l_PDFup"]->SetBinContent(i,h2l["lostLepBkg"]->GetBinContent(b));
        ////hist2l["CR2l_PDFdown"]->SetBinContent(i,h2l["lostLepBkg"]->GetBinContent(b));
        hist2l["CR2l_alphasUp"]->SetBinContent(i,h2l["variation_alphaSup"]->GetBinContent(b));
        hist2l["CR2l_alphasDn"]->SetBinContent(i,h2l["variation_alphaSdown"]->GetBinContent(b));
        hist2l["CR2l_q2Dn"]->SetBinContent(i,h2l["variation_qSquareddown"]->GetBinContent(b));
        hist2l["CR2l_q2Up"]->SetBinContent(i,h2l["variation_qSquaredup"]->GetBinContent(b));
        hist2l["CR2l_jesUp"]->SetBinContent(i,h2l["variation_JESup"]->GetBinContent(b));
        hist2l["CR2l_jesDn"]->SetBinContent(i,h2l["variation_JESdown"]->GetBinContent(b));
        hist2l["CR2l_cr2lTriggerSFUp"]->SetBinContent(i,h2l["variation_cr2ltrigup"]->GetBinContent(b));
        hist2l["CR2l_cr2lTriggerSFDn"]->SetBinContent(i,h2l["variation_cr2ltrigdown"]->GetBinContent(b));
        hist2l["CR2l_metResUp"]->SetBinContent(i,h2l["variation_METresup"]->GetBinContent(b));
        hist2l["CR2l_metResDn"]->SetBinContent(i,h2l["variation_METresdown"]->GetBinContent(b));
        hist2l["CR2l_tauSFUp"]->SetBinContent(i,h2l["CR2l_tauSFUp"]->GetBinContent(b));
        hist2l["CR2l_tauSFDn"]->SetBinContent(i,h2l["CR2l_tauSFDn"]->GetBinContent(b));
        hist2l["CR2l_pileupUp"]->SetBinContent(i,h2l["variation_PUup"]->GetBinContent(b));
        hist2l["CR2l_pileupDn"]->SetBinContent(i,h2l["variation_PUdown"]->GetBinContent(b));
        hist2l["CR2l_metTTbarUp"]->SetBinContent(i,h2l["CR2l_metTTbarUp"]->GetBinContent(b));
        hist2l["CR2l_metTTbarDn"]->SetBinContent(i,h2l["CR2l_metTTbarDn"]->GetBinContent(b));
    }
    cout << __LINE__ << endl;
    TFile *ftt2lc = new TFile("LostLepton_BkgEst_compressed.root","RECREATE");
    ftt2lc->cd();
    for(map<string,TH1D*>::iterator h=    hist2l.begin(); h!=    hist2l.end();++h) {
        h->second->Write(h->second->GetName(),TObject::kOverwrite);
    }
    ftt2lc->Close();
    cout << __LINE__ << endl;
    
    TFile *fdatac = new TFile("DataSR_compressed.root","RECREATE");
    fdatac->cd();
    TH1D *SR_Data = new TH1D("SR_Data","",4,0,4);
    SR_Data->SetBinContent(1,72);
    SR_Data->SetBinContent(2,30);
    SR_Data->SetBinContent(3,2);
    SR_Data->SetBinContent(4,2);
    SR_Data->Write();
    fdatac->Close();
}