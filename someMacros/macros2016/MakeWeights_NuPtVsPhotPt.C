{

    double xbins[20] = {0,40,80,100,120,140,160,180,200,220,240,260,280,300,320,340,400,500,600,1000};
    
TFile *_file2 = TFile::Open("PhotJetsPt_PhotonData.root");
TFile *_file1 = TFile::Open("PhotJetsPt_PhotonMC.root");
TFile *_file0 = TFile::Open("WJetsPt_WJetsMC.root");

TH1F *htemp = (TH1F*)_file0->Get("NuPt_MET150ge3jge1bMT120_WJetsMC");
TH1F *ho = (TH1F*)_file0->Get("NuPt_MET150ge3j0bMT120_WJetsMC");
ho->Add(htemp,1);
//h->Rebin(2);
TH1F *h = (TH1F*)ho->Rebin(19,"hnew0",xbins);
    float hbefore = h->Integral();

TH1F *hData1bo = (TH1F*)_file2->Get("PhotPt_MET150ge3jge1bMT150_PhotonData");
TH1F *hData0bo = (TH1F*)_file2->Get("PhotPt_MET150ge3j0bMT150_PhotonData");
//hData1b->Rebin(2);
//hData0b->Rebin(2);
TH1F *hData0b = (TH1F*)hData0bo->Rebin(19,"hnew1",xbins);
TH1F *hData1b = (TH1F*)hData1bo->Rebin(19,"hnew2",xbins);
    float databeforeo = hData0b->Integral();
    float databefore1 = hData1b->Integral();


TH1F *hMC0bo = (TH1F*)_file1->Get("PhotPt_MET150ge3j0bMT150_PhotonMC");
TH1F *hMC1bo = (TH1F*)_file1->Get("PhotPt_MET150ge3jge1bMT150_PhotonMC");
//hMC0b->Rebin(2);
//hMC1b->Rebin(2);
TH1F *hMC0b = (TH1F*)hMC0bo->Rebin(19,"hnew3",xbins);
TH1F *hMC1b = (TH1F*)hMC1bo->Rebin(19,"hnew4",xbins);
    float mcbeforeo = hMC0b->Integral();
    float mcbefore1 = hMC1b->Integral();
    
TH1F *hDataweight1b = (TH1F*)h->Clone("NuPtPhotPtWeight1bData");
TH1F *hDataweight0b = (TH1F*)h->Clone("NuPtPhotPtWeight0bData");

TH1F *hMCweight1b = (TH1F*)h->Clone("NuPtPhotPtWeight1bMC");
TH1F *hMCweight0b = (TH1F*)h->Clone("NuPtPhotPtWeight0bMC");

hDataweight1b->Divide(hData1b);
hDataweight0b->Divide(hData0b);
    float dataaftero = hDataweight0b->Integral();
    float dataafter1 = hDataweight1b->Integral();

hMCweight1b->Divide(hMC1b);
hMCweight0b->Divide(hMC0b);
    float mcaftero = hMCweight0b->Integral();
    float mcafter1 = hMCweight1b->Integral();
    
    cout << "WJets Integral " << hbefore << endl;
    cout << "0b/1b PhotonMC " << mcbeforeo << "/" << mcbefore1 << endl;
    cout << "0b/1b PhotonData " << databeforeo << "/" << databefore1 << endl;
    cout << "0b/1b weightsMC " << mcaftero << "/" << mcafter1 << endl;
    cout << "0b/1b weightsData " << dataaftero << "/" << dataafter1 << endl;

TFile *f = new TFile("Weights_NuPtVsPhotPt.root","RECREATE");
f->cd();
hDataweight1b->Write();
hDataweight0b->Write();
hMCweight1b->Write();
hMCweight0b->Write();
f->Close();
delete f;
}