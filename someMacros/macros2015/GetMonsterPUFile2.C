

// C++
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TProfile.h"


using namespace std;


void GetMonsterPUFile2(){
    
    /*TFile *fn25 = TFile::Open("Histos_normalTTbar_25ns.root");
    TFile *fn50 = TFile::Open("Histos_normalTTbar_50ns.root");
    TFile *fp25 = TFile::Open("Histos_puppiTTbar_25ns.root");
    TFile *fp50 = TFile::Open("Histos_puppiTTbar_50ns.root");*/
    string sn25 = "Histos_normalTTbar_25ns.root";
    string sn50 = "Histos_normalTTbar_50ns.root";
    string sp25 = "Histos_puppiTTbar_25ns.root";
    string sp50 = "Histos_puppiTTbar_50ns.root";
    
    map<string, TH2F*> histos;
    map<string, TH1D*> hist;
    map<string, TProfile*> histPj;
    vector<string> histonames; histonames.clear();
    
    const int pssize = 6;
    string prestring[pssize] = {"PreselMT120MET150","PreselMT120","Preselection","MET300","chi210","MT2W200"};
    
    const int ssize = 8;
    string samplestring[ssize] = {"normalTTbar_25ns_2l", "normalTTbar_25ns_1l", "normalTTbar_50ns_2l", "normalTTbar_50ns_1l", "puppiTTbar_25ns_2l", "puppiTTbar_25ns_1l", "puppiTTbar_50ns_2l", "puppiTTbar_50ns_1l"};
    
    const int PUbinsize = 5;
    string PUbin[PUbinsize] = {"0to10","11to15","16to20","21to25","25toInf"};
    
    const int Pjsize = 2;
    string projstring[Pjsize] = {"ProjVar", "ProjPU"};
    
    histonames.push_back("DeltaPhiWl");               
    histonames.push_back("MT");                       
    histonames.push_back("MET");                      
    histonames.push_back("chi2");                     
    histonames.push_back("MT2W");                     
    histonames.push_back("MT2_lb_b");                 
    histonames.push_back("MT2_lb_bqq");               
    histonames.push_back("MT2_lb_b_mless");           
    histonames.push_back("MT2_lb_bqq_mless");         
    histonames.push_back("MTq_max");                  
    histonames.push_back("MTq_leadj300");             
    histonames.push_back("METsqrtHT");                
    //RM = MET/ptLeadJet
    histonames.push_back("RM300");                    
    histonames.push_back("MT2_l_q");                  
    histonames.push_back("MT2_l_qq");                 
    histonames.push_back("MT2_l_qq_mless");           
    histonames.push_back("Topness");                  
    histonames.push_back("TopnessMod");
    
    histonames.push_back("NJets");                     
    histonames.push_back("NBJets");                    
    histonames.push_back("LepMiniIso");                
    histonames.push_back("LepPt");                     
    histonames.push_back("LepEta");                    
    histonames.push_back("J1Pt");                      
    histonames.push_back("J2Pt");                      
    histonames.push_back("J3Pt");                      
    histonames.push_back("J4Pt");                      
    histonames.push_back("B1Pt");                      
    histonames.push_back("JPt");                       
    histonames.push_back("BPt");                       
    histonames.push_back("JEta");                      
    histonames.push_back("BEta");
    TFile *out1; TFile *out2;
    TFile *f;
    string outstring1 = "PUbin";
    string outstring2 = "PUProj";
    for(unsigned int b = 0; b<ssize; ++b){
        if(b==0) f = TFile::Open(sn25.c_str());
        if(b==2) f = TFile::Open(sn50.c_str());
        if(b==4) f = TFile::Open(sp25.c_str());
        if(b==6) f = TFile::Open(sp50.c_str());
        if(b==0) { outstring1= "PUbin"+sn25; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==2) { outstring1= "PUbin"+sn50; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==4) { outstring1= "PUbin"+sp25; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==6) { outstring1= "PUbin"+sp50; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==0) { outstring2= "PUProj"+sn25; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==2) { outstring2= "PUProj"+sn50; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==4) { outstring2= "PUProj"+sp25; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==6) { outstring2= "PUProj"+sp50; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        /*
        if(b==0||b==1) f = TFile::Open(sn25.c_str());
        if(b==2||b==3) f = TFile::Open(sn50.c_str());
        if(b==4||b==5) f = TFile::Open(sp25.c_str());
        if(b==6||b==7) f = TFile::Open(sp50.c_str());
        if(b==0||b==1) { outstring1= "PUbin"+sn25; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==2||b==3) { outstring1= "PUbin"+sn50; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==4||b==5) { outstring1= "PUbin"+sp25; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==6||b==7) { outstring1= "PUbin"+sp50; out1 = new TFile(outstring1.c_str(),"RECREATE"); }
        if(b==0||b==1) { outstring2= "PUProj"+sn25; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==2||b==3) { outstring2= "PUProj"+sn50; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==4||b==5) { outstring2= "PUProj"+sp25; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        if(b==6||b==7) { outstring2= "PUProj"+sp50; out2 = new TFile(outstring2.c_str(),"RECREATE"); }
        */
        f->cd();
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                f->cd();
                string mapname;
                mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplestring[b];
                if(histos.count(mapname) == 0 ) histos[mapname] =(TH2F*)f->Get(mapname.c_str());
                mapname = prestring[c] +"_"+ histonames[i] + "_vsNPUInt_"+samplestring[b];
                if(histos.count(mapname) == 0 ) histos[mapname] =(TH2F*)f->Get(mapname.c_str());
                mapname = prestring[c] +"_"+ histonames[i] + "_vsNPV_"+samplestring[b];
                if(histos.count(mapname) == 0 ) histos[mapname] =(TH2F*)f->Get(mapname.c_str());
                for(unsigned int a = 0; a<PUbinsize; ++a){
                    f->cd();
                    int lowbin, upbin;
                    if(a==0){ lowbin = 1;  upbin = 11; }//bin 1 starts at 0, bin 2 at 1, etc...
                    if(a==1){ lowbin = 12; upbin = 16; }
                    if(a==2){ lowbin = 17; upbin = 21; }
                    if(a==3){ lowbin = 22; upbin = 26; }
                    if(a==4){ lowbin = 27; upbin = 50; }//bin 50 stops at 50
                    out1->cd();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplestring[b];
                    string newname = prestring[c] + "_"+ histonames[i] + "_NPUV"+PUbin[a]+"_"+samplestring[b];
                    if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                    //if(c==0&&a==1&&b==1) cout << mapname << " " << newname << endl;
                    hist[newname]->Write();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+samplestring[b];
                    newname = prestring[c] + "_"+ histonames[i] + "_NPUInt"+PUbin[a]+"_"+samplestring[b];
                    if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                    hist[newname]->Write();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+samplestring[b];
                    newname = prestring[c] + "_"+ histonames[i] + "_NPV"+PUbin[a]+"_"+samplestring[b];
                    if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                    hist[newname]->Write();
                    f->cd();
                }
                for(unsigned int a = 0; a<Pjsize; ++a){
                    f->cd();
                    out2->cd();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplestring[b];
                    string newname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+projstring[a]+"_"+samplestring[b];
                    if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                    if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                    histPj[newname]->Write();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+samplestring[b];
                    newname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+projstring[a]+"_"+samplestring[b];
                    if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                    if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                    histPj[newname]->Write();
                    mapname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+samplestring[b];
                    newname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+projstring[a]+"_"+samplestring[b];
                    if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                    if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                    histPj[newname]->Write();
                    f->cd();
                }
                
            }
        }
        if(b==1||b==3||b==5||b==7){
            f->Close();
            out1->cd();
            out1->Close();
            out2->cd();
            out2->Close();
        }
    }
    /*
    TFile *monster = new TFile("PUHistos_AllProjectionsProfiles.root","RECREATE");
    monster->cd();
    for(unsigned int b = 0; b<ssize; ++b){
        for(unsigned int c = 0; c<pssize; ++c){
            for(unsigned int i = 0; i<histonames.size(); ++i){
                string mapname;
                 for(unsigned int a = 0; a<PUbinsize; ++a){
                 int lowbin, upbin;
                 if(a==0){ lowbin = 1;  upbin = 11; }//bin 1 starts at 0, bin 2 at 1, etc...
                 if(a==1){ lowbin = 12; upbin = 16; }
                 if(a==2){ lowbin = 17; upbin = 21; }
                 if(a==3){ lowbin = 22; upbin = 26; }
                 if(a==4){ lowbin = 27; upbin = 50; }//bin 50 stops at 50
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplestring[b];
                 string newname = prestring[c] + "_"+ histonames[i] + "_NPUV"+PUbin[a]+"_"+samplestring[b];
                 if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+samplestring[b];
                 newname = prestring[c] + "_"+ histonames[i] + "_NPUInt"+PUbin[a]+"_"+samplestring[b];
                 if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+samplestring[b];
                 newname = prestring[c] + "_"+ histonames[i] + "_NPV"+PUbin[a]+"_"+samplestring[b];
                 if(hist.count(newname) == 0 ) hist[newname] = (TH1D*)histos[mapname]->ProjectionX(newname.c_str(),lowbin,upbin,"e");
                 }
                 for(unsigned int a = 0; a<Pjsize; ++a){
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+samplestring[b];
                 string newname = prestring[c] + "_"+ histonames[i] + "_vsNPUV_"+projstring[a]+"_"+samplestring[b];
                 if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                 if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+samplestring[b];
                 newname = prestring[c] + "_"+ histonames[i] + "_vsNPUInt_"+projstring[a]+"_"+samplestring[b];
                 if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                 if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                 mapname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+samplestring[b];
                 newname = prestring[c] + "_"+ histonames[i] + "_vsNPV_"+projstring[a]+"_"+samplestring[b];
                 if(a==0 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileX(newname.c_str());
                 if(a==1 && histPj.count(newname) == 0 ) histPj[newname] = (TProfile*)histos[mapname]->ProfileY(newname.c_str());
                 }
            }
        }
    }
    
    
    monster->cd();
    for(map<string,TH1D*>::iterator     h=    hist.begin(); h!=    hist.end();++h) {h->second->Write(); }
    for(map<string,TProfile*>::iterator h=  histPj.begin(); h!=  histPj.end();++h) {h->second->Write(); }
    monster->Close();
   */
    
    
}