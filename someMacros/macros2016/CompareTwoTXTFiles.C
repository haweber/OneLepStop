#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "TMath.h"

using namespace std;

struct PrintOut{
    int Run;
    int LS;
    unsigned int Evt;
    float leppt;
    float lepminiIso;
    int leppdgid;
    float met;
    float mt;
    int njets;
    int nvetoleps;
    int nbjets;
    int ngenleps;
    float DPhiWlep;
    float htssm;
    float Mlb_cb;
    float Mjjj;
    float mt2w;
    float Topness;
    float chi2;
    bool trackveto;
    bool tauveto;
};
bool SortPrintOut(PrintOut const& lhs, PrintOut const& rhs) {
    if (lhs.Run != rhs.Run)
        return lhs.Run < rhs.Run;
    if (lhs.LS != rhs.LS)
        return lhs.LS < rhs.LS;
    return lhs.Evt < rhs.Evt;
}

void CompareTwoTXTFiles(string fname1, string fname2){
    
    cout << "file1 " << fname1 << endl;
    cout << "file2 " << fname2 << endl;
    
    PrintOut po1; po1.Run = -1;
    vector<PrintOut> f1;
    char buffer1[300];
    ifstream file1(fname1.c_str());
    while( file1.getline(buffer1, 300, '\n') ){
        sscanf(buffer1, "\t%d\t%d\t%u\t%f\t%d\t%f\t%f\t%d\t%d\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f",
        &po1.Run, &po1.LS, &po1.Evt, &po1.leppt, &po1.leppdgid, &po1.met, &po1.mt, &po1.njets, &po1.nbjets, &po1.ngenleps, &po1.DPhiWlep, &po1.htssm, &po1.Mlb_cb, &po1.Mjjj, &po1.mt2w, &po1.Topness, &po1.chi2);
        if(po1.Run>=1) f1.push_back(po1);
    }
    PrintOut po2; po2.Run = -1;
    vector<PrintOut> f2;
    char buffer2[300];
    ifstream file2(fname2.c_str());
    while( file2.getline(buffer2, 300, '\n') ){
        sscanf(buffer2, "\t%d\t%d\t%u\t%f\t%d\t%f\t%f\t%d\t%d\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f",
               &po2.Run, &po2.LS, &po2.Evt, &po2.leppt, &po2.leppdgid, &po2.met, &po2.mt, &po2.njets, &po2.nbjets, &po2.ngenleps, &po2.DPhiWlep, &po2.htssm, &po2.Mlb_cb, &po2.Mjjj, &po2.mt2w, &po2.Topness, &po2.chi2);
        if(po2.Run>=1) f2.push_back(po2);
    }

    std::sort(f1.begin(), f1.end(), &SortPrintOut);
    std::sort(f2.begin(), f2.end(), &SortPrintOut);
    
    vector<PrintOut> only1;
    vector<PrintOut> only2;
    vector<PrintOut> diff1;
    vector<PrintOut> diff2;
    int lpt(0),lid(0), met(0), mt(0), nj(0), nb(0), ngl(0), dphi(0), htssm(0), mlb(0), mjjj(0), mt2w(0), top(0), chi2(0);

    for(unsigned int i = 0; i<f1.size();++i){
        int jind = -1;
        for(unsigned int j = 0; j<f2.size();++j){
            if(f1[i].Run!=f2[j].Run) continue;
            if(f1[i].LS !=f2[j].LS ) continue;
            if(f1[i].Evt!=f2[j].Evt) continue;
            jind = j; break;
        }
        if(jind==-1){
            only1.push_back(f1[i]);
        } else{
            bool diff = false;
            /*
            if(f1[i].leppt   !=f2[jind].leppt   ) diff = true;
            if(f1[i].leppdgid!=f2[jind].leppdgid) diff = true;
            if(f1[i].met     !=f2[jind].met     ) diff = true;
            if(f1[i].mt      !=f2[jind].mt      ) diff = true;
            if(f1[i].njets   !=f2[jind].njets   ) diff = true;
            if(f1[i].nbjets  !=f2[jind].nbjets  ) diff = true;
            if(f1[i].ngenleps!=f2[jind].ngenleps) diff = true;
            if(fabs(f1[i].DPhiWlep)!=fabs(f2[jind].DPhiWlep)) diff = true;
            if(f1[i].htssm   !=f2[jind].htssm   ) diff = true;
            if(f1[i].Mlb_cb  !=f2[jind].Mlb_cb  ) diff = true;
            if(f1[i].Mjjj    !=f2[jind].Mjjj    ) diff = true;
            if(f1[i].mt2w    !=f2[jind].mt2w    ) diff = true;
            if(f1[i].Topness !=f2[jind].Topness ) diff = true;
            if(f1[i].chi2    !=f2[jind].chi2    ) diff = true;
            */
            float cut = 0.001;

            if(TMath::Abs(f1[i].leppt   -f2[jind].leppt   )>cut) { diff = true; ++lpt; }
            if(TMath::Abs(f1[i].leppdgid-f2[jind].leppdgid)>cut) { diff = true; ++lid; }
            if(TMath::Abs(f1[i].met     -f2[jind].met     )>cut) { diff = true; ++met; }
            if(TMath::Abs(f1[i].mt      -f2[jind].mt      )>cut) { diff = true; ++mt; }
            if(TMath::Abs(f1[i].njets   -f2[jind].njets   )>cut) { diff = true; ++nj; }
            if(TMath::Abs(f1[i].nbjets  -f2[jind].nbjets  )>cut) { diff = true; ++nb; }
            if(TMath::Abs(f1[i].ngenleps-f2[jind].ngenleps)>cut) { diff = true; ++ ngl; }
            if(TMath::Abs(fabs(f1[i].DPhiWlep)-fabs(f2[jind].DPhiWlep))>cut) { diff = true; ++dphi; }
            if(TMath::Abs(f1[i].htssm   -f2[jind].htssm   )>cut) { diff = true; ++htssm; }
            if(TMath::Abs(f1[i].Mlb_cb  -f2[jind].Mlb_cb  )>cut) { diff = true; ++mlb; }
            if(TMath::Abs(f1[i].Mjjj    -f2[jind].Mjjj    )>cut) { diff = true; ++mjjj; }
            //if(TMath::Abs(f1[i].mt2w    -f2[jind].mt2w    )>cut) { diff = true; ++mt2w; }
            //if(TMath::Abs(f1[i].Topness -f2[jind].Topness )>cut) { diff = true; ++top; }
            if(TMath::Abs(f1[i].chi2    -f2[jind].chi2    )>cut) { diff = true; ++chi2; }
            if(diff==true) { diff1.push_back(f1[i]); diff2.push_back(f2[jind]); }
        }
    }
    for(unsigned int i = 0; i<f2.size();++i){
        int jind = -1;
        for(unsigned int j = 0; j<f1.size();++j){
            if(f2[i].Run!=f1[j].Run) continue;
            if(f2[i].LS !=f1[j].LS ) continue;
            if(f2[i].Evt!=f1[j].Evt) continue;
            jind = j; break;
        }
        if(jind==-1){
            only2.push_back(f2[i]);
        }
    }
    if(only1.size()>0) cout << "These events are only in file1" << endl;
    for(unsigned int i = 0; i<only1.size(); ++i){
        PrintOut p = only1[i];
        cout << " " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
        //<< " " << setw(8) << p.lepminiIso
        << " " << setw(3) << p.leppdgid << " " << setw(9)
        << p.met << " " << setw(9) << p.mt << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
        << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
    }
    if(only1.size()>0) cout << "These events are only in file2" << endl;
    for(unsigned int i = 0; i<only2.size(); ++i){
        PrintOut p = only2[i];
        cout << " " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
        //<< " " << setw(8) << p.lepminiIso
        << " " << setw(3) << p.leppdgid << " " << setw(9)
        << p.met << " " << setw(9) << p.mt << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
        << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
    }
    if(diff1.size()>0) {
        cout << "These events differ between" << endl;

    }
    for(unsigned int i = 0; i<diff1.size(); ++i){
        PrintOut p = diff1[i];
        cout << "file1 " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
        //<< " " << setw(8) << p.lepminiIso
        << " " << setw(3) << p.leppdgid << " " << setw(9)
        << p.met << " " << setw(9) << p.mt << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
        << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
        p = diff2[i];
        cout << "file2 " << fixed << setprecision(4) << p.Run << " " << setw(4) << p.LS << " " << setw(6) << p.Evt << " " << setw(8) << p.leppt
        //<< " " << setw(8) << p.lepminiIso
        << " " << setw(3) << p.leppdgid << " " << setw(9)
        << p.met << " " << setw(9) << p.mt << " " << setw(2) << p.njets << " " << setw(1) << p.nbjets << " " << setw(1) << p.ngenleps << " " << setw(6)
        << p.DPhiWlep << " " << setw(9) << p.htssm << " " << setw(9) << p.Mlb_cb << " " << setw(9) << p.Mjjj << " " << setw(9) << p.mt2w << " " << setw(9) << p.Topness << " " << setw(9) << p.chi2 << endl;
    }
    if(diff1.size()==0 && only1.size()==0 && only2.size()==0){
        cout << "Congratulations, files are in perfect sync" << endl;
    }

    cout << "Differences by type: leppt " << lpt << " pdgID " << lid << " MET " << met << " MT " << mt << "NJ " << nj << " NB " << nb << " Ngenleps " << ngl << " DPhiWl " << dphi << " HTssm " << htssm << " Mlb " << mlb << " Mjjj " << mjjj << " MT2W " << mt2w << " topness " << top << " chi2 " << chi2 << endl;
}