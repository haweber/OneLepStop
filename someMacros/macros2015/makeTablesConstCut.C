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
#include "TString.h"

using namespace std;

float Zbi_(float sig, float bg, float bgrelunc=0.1){
    
    double bgunc = bgrelunc*bg;
    double tau = bg/pow(bgunc,2);//bgunc is absolute
    double n_on = sig+bg;//total yield in SR = sig + bg
    double n_off = tau*bg;
    double P_Bi = TMath::BetaIncomplete(1./(1.+tau),n_on,n_off+1);
    double Z_Bi = sqrt(2.)*TMath::ErfInverse(1.-2.*P_Bi);
    return Z_Bi;
}

float SoB_(float sig, float bg){
    if(bg==0) return -1.;
    return sig/bg;
}

float SoSqrtB_(float sig, float bg){
    if(bg<=0) return -1;
    return sig/sqrt(bg);
}

float FoM_(float sig, float bg, float bgrelunc=0.1){
    double bgunc = bgrelunc*bg;
    if((bg+bgunc*bgunc)<=0) return -1;
    return sig/sqrt(bg+bgunc*bgunc);
}

vector<float> ZBi(vector<float> sig, vector<float> bg){
    vector<float> output;
    for(unsigned int i = 0; i<sig.size(); ++i) output.push_back(Zbi_(sig[i],bg[i]) );
    return output;
}

vector<float> FOM(vector<float> sig, vector<float> bg){
    vector<float> output;
    for(unsigned int i = 0; i<sig.size(); ++i) output.push_back(FoM_(sig[i],bg[i]) );
    return output;
}

vector<float> SB(vector<float> sig, vector<float> bg){
    vector<float> output;
    for(unsigned int i = 0; i<sig.size(); ++i) output.push_back(SoB_(sig[i],bg[i]) );
    return output;
}

vector<float> SsB(vector<float> sig, vector<float> bg){
    vector<float> output;
    for(unsigned int i = 0; i<sig.size(); ++i) output.push_back(SoSqrtB_(sig[i],bg[i]) );
    return output;
}

void load(vector<TString> &variable, vector<float> &cut, vector<float> &bg, vector<float> &sig425, vector<float> &sig500, vector<float> &sig650, vector<float> &sig850, int load, string sample){
    int nvar = 48;
    char buffer[200];
    char StringValue[100];
    float tcut(0),tbg(0),tsig425(0),tsig500(0),tsig650(0),tsig850(0),td(0);
    ifstream IN(sample.c_str() );
    while( IN.getline(buffer, 200, '\n') ){
        // ok = false;
        if (buffer[0] == '#') {
            continue; // Skip lines commented with '#'
        }
        if(load==1 && !strcmp(buffer, "Event yields")){
            for(unsigned int i = 0; i<nvar; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tbg,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                TString mystring = StringValue;
                variable.push_back(mystring); cut.push_back(tcut); bg.push_back(tbg);
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==2 && !strcmp(buffer, "now S/B")){
            for(unsigned int i = 0; i<nvar; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==3 && !strcmp(buffer, "now S/sqrt(B)")){
            for(unsigned int i = 0; i<nvar; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==4 && !strcmp(buffer, "now FoM = S/sqrt(B+Delta(B)^2)")){
            for(unsigned int i = 0; i<nvar; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==5 && !strcmp(buffer, "now Z_bi")){
            for(unsigned int i = 0; i<nvar; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
    }
    
}


void makeTablesConstCut(){
    
    bool single = false;//plot single addstring - X variable
    bool cutflow = true;//compare among addstring
    int version = 1; //1 normal, 2 MET300, 3 chi210, 4 MT2W200
   
    
    vector<TString> Xvarb2;     vector<TString> varb2;     vector<TString> METvarb2;     vector<TString> chivarb2;     vector<TString> MTWvarb2;
    vector<float> Xcutb2;       vector<float> cutb2;       vector<float> METcutb2;       vector<float> chicutb2;       vector<float> MTWcutb2;
    vector<float> Xbgb2;        vector<float> bgb2;        vector<float> METbgb2;        vector<float> chibgb2;        vector<float> MTWbgb2;
    vector<float> Xsig425b2;    vector<float> sig425b2;    vector<float> METsig425b2;    vector<float> chisig425b2;    vector<float> MTWsig425b2;
    vector<float> Xsig500b2;    vector<float> sig500b2;    vector<float> METsig500b2;    vector<float> chisig500b2;    vector<float> MTWsig500b2;
    vector<float> Xsig650b2;    vector<float> sig650b2;    vector<float> METsig650b2;    vector<float> chisig650b2;    vector<float> MTWsig650b2;
    vector<float> Xsig850b2;    vector<float> sig850b2;    vector<float> METsig850b2;    vector<float> chisig850b2;    vector<float> MTWsig850b2;
    vector<float> XSBsig425b2;  vector<float> SBsig425b2;  vector<float> METSBsig425b2;  vector<float> chiSBsig425b2;  vector<float> MTWSBsig425b2;
    vector<float> XSBsig500b2;  vector<float> SBsig500b2;  vector<float> METSBsig500b2;  vector<float> chiSBsig500b2;  vector<float> MTWSBsig500b2;
    vector<float> XSBsig650b2;  vector<float> SBsig650b2;  vector<float> METSBsig650b2;  vector<float> chiSBsig650b2;  vector<float> MTWSBsig650b2;
    vector<float> XSBsig850b2;  vector<float> SBsig850b2;  vector<float> METSBsig850b2;  vector<float> chiSBsig850b2;  vector<float> MTWSBsig850b2;
    vector<float> XSsBsig425b2; vector<float> SsBsig425b2; vector<float> METSsBsig425b2; vector<float> chiSsBsig425b2; vector<float> MTWSsBsig425b2;
    vector<float> XSsBsig500b2; vector<float> SsBsig500b2; vector<float> METSsBsig500b2; vector<float> chiSsBsig500b2; vector<float> MTWSsBsig500b2;
    vector<float> XSsBsig650b2; vector<float> SsBsig650b2; vector<float> METSsBsig650b2; vector<float> chiSsBsig650b2; vector<float> MTWSsBsig650b2;
    vector<float> XSsBsig850b2; vector<float> SsBsig850b2; vector<float> METSsBsig850b2; vector<float> chiSsBsig850b2; vector<float> MTWSsBsig850b2;
    vector<float> XFoMsig425b2; vector<float> FoMsig425b2; vector<float> METFoMsig425b2; vector<float> chiFoMsig425b2; vector<float> MTWFoMsig425b2;
    vector<float> XFoMsig500b2; vector<float> FoMsig500b2; vector<float> METFoMsig500b2; vector<float> chiFoMsig500b2; vector<float> MTWFoMsig500b2;
    vector<float> XFoMsig650b2; vector<float> FoMsig650b2; vector<float> METFoMsig650b2; vector<float> chiFoMsig650b2; vector<float> MTWFoMsig650b2;
    vector<float> XFoMsig850b2; vector<float> FoMsig850b2; vector<float> METFoMsig850b2; vector<float> chiFoMsig850b2; vector<float> MTWFoMsig850b2;
    vector<float> XZsig425b2;   vector<float> Zsig425b2;   vector<float> METZsig425b2;   vector<float> chiZsig425b2;   vector<float> MTWZsig425b2;
    vector<float> XZsig500b2;   vector<float> Zsig500b2;   vector<float> METZsig500b2;   vector<float> chiZsig500b2;   vector<float> MTWZsig500b2;
    vector<float> XZsig650b2;   vector<float> Zsig650b2;   vector<float> METZsig650b2;   vector<float> chiZsig650b2;   vector<float> MTWZsig650b2;
    vector<float> XZsig850b2;   vector<float> Zsig850b2;   vector<float> METZsig850b2;   vector<float> chiZsig850b2;   vector<float> MTWZsig850b2;
    
    load(varb2,cutb2,bgb2,sig425b2,sig500b2,sig650b2,sig850b2,1,"_constcut.txt");
    SBsig425b2 = SB(sig425b2,bgb2); SBsig500b2 = SB(sig500b2,bgb2); SBsig650b2 = SB(sig650b2,bgb2); SBsig850b2 = SB(sig850b2,bgb2);
    SsBsig425b2 = SsB(sig425b2,bgb2); SsBsig500b2 = SsB(sig500b2,bgb2); SsBsig650b2 = SsB(sig650b2,bgb2); SsBsig850b2 = SsB(sig850b2,bgb2);
    FoMsig425b2 = FOM(sig425b2,bgb2); FoMsig500b2 = FOM(sig500b2,bgb2); FoMsig650b2 = FOM(sig650b2,bgb2); FoMsig850b2 = FOM(sig850b2,bgb2);
    Zsig425b2 = ZBi(sig425b2,bgb2); Zsig500b2 = ZBi(sig500b2,bgb2); Zsig650b2 = ZBi(sig650b2,bgb2); Zsig850b2 = ZBi(sig850b2,bgb2);
    //load(ds,d1,d2,SBsig425b2,SBsig500b2,SBsig650b2,SBsig850b2,2,"_add2bconstcut.txt");
    //load(ds,d1,d2,SsBsig425b2,SsBsig500b2,SsBsig650b2,SsBsig850b2,3,"_add2bconstcut.txt");
    //load(ds,d1,d2,FoMsig425b2,FoMsig500b2,FoMsig650b2,FoMsig850b2,4,"_add2bconstcut.txt");
    //load(ds,d1,d2,Zsig425b2,Zsig500b2,Zsig650b2,Zsig850b2,5,"_add2bconstcut.txt");
    
    load(METvarb2,METcutb2,METbgb2,METsig425b2,METsig500b2,METsig650b2,METsig850b2,1,"_MET300_constcut.txt");
    METSBsig425b2 = SB(METsig425b2,METbgb2); METSBsig500b2 = SB(METsig500b2,METbgb2); METSBsig650b2 = SB(METsig650b2,METbgb2); METSBsig850b2 = SB(METsig850b2,METbgb2);
    METSsBsig425b2 = SsB(METsig425b2,METbgb2); METSsBsig500b2 = SsB(METsig500b2,METbgb2); METSsBsig650b2 = SsB(METsig650b2,METbgb2); METSsBsig850b2 = SsB(METsig850b2,METbgb2);
    METFoMsig425b2 = FOM(METsig425b2,METbgb2); METFoMsig500b2 = FOM(METsig500b2,METbgb2); METFoMsig650b2 = FOM(METsig650b2,METbgb2); METFoMsig850b2 = FOM(METsig850b2,METbgb2);
    METZsig425b2 = ZBi(METsig425b2,METbgb2); METZsig500b2 = ZBi(METsig500b2,METbgb2); METZsig650b2 = ZBi(METsig650b2,METbgb2); METZsig850b2 = ZBi(METsig850b2,METbgb2);
    //load(ds,d1,d2,METSBsig425b2,METSBsig500b2,METSBsig650b2,METSBsig850b2,2,"MET300/_add2bconstcut.txt");
    //load(ds,d1,d2,METSsBsig425b2,METSsBsig500b2,METSsBsig650b2,METSsBsig850b2,3,"MET300/_add2bconstcut.txt");
    //load(ds,d1,d2,METFoMsig425b2,METFoMsig500b2,METFoMsig650b2,METFoMsig850b2,4,"MET300/_add2bconstcut.txt");
    //load(ds,d1,d2,METZsig425b2,METZsig500b2,METZsig650b2,METZsig850b2,5,"MET300/_add2bconstcut.txt");
    
    load(chivarb2,chicutb2,chibgb2,chisig425b2,chisig500b2,chisig650b2,chisig850b2,1,"_chi210_constcut.txt");
    chiSBsig425b2 = SB(chisig425b2,chibgb2); chiSBsig500b2 = SB(chisig500b2,chibgb2); chiSBsig650b2 = SB(chisig650b2,chibgb2); chiSBsig850b2 = SB(chisig850b2,chibgb2);
    chiSsBsig425b2 = SsB(chisig425b2,chibgb2); chiSsBsig500b2 = SsB(chisig500b2,chibgb2); chiSsBsig650b2 = SsB(chisig650b2,chibgb2); chiSsBsig850b2 = SsB(chisig850b2,chibgb2);
    chiFoMsig425b2 = FOM(chisig425b2,chibgb2); chiFoMsig500b2 = FOM(chisig500b2,chibgb2); chiFoMsig650b2 = FOM(chisig650b2,chibgb2); chiFoMsig850b2 = FOM(chisig850b2,chibgb2);
    chiZsig425b2 = ZBi(chisig425b2,chibgb2); chiZsig500b2 = ZBi(chisig500b2,chibgb2); chiZsig650b2 = ZBi(chisig650b2,chibgb2); chiZsig850b2 = ZBi(chisig850b2,chibgb2);
    //load(ds,d1,d2,chiSBsig425b2,chiSBsig500b2,chiSBsig650b2,chiSBsig850b2,2,"chi210/_add2bconstcut.txt");
    //load(ds,d1,d2,chiSsBsig425b2,chiSsBsig500b2,chiSsBsig650b2,chiSsBsig850b2,3,"chi210/_add2bconstcut.txt");
    //load(ds,d1,d2,chiFoMsig425b2,chiFoMsig500b2,chiFoMsig650b2,chiFoMsig850b2,4,"chi210/_add2bconstcut.txt");
    //load(ds,d1,d2,chiZsig425b2,chiZsig500b2,chiZsig650b2,chiZsig850b2,5,"chi210/_add2bconstcut.txt");
    
    load(MTWvarb2,MTWcutb2,MTWbgb2,MTWsig425b2,MTWsig500b2,MTWsig650b2,MTWsig850b2,1,"_MT2W200_constcut.txt");
    MTWSBsig425b2 = SB(MTWsig425b2,MTWbgb2); MTWSBsig500b2 = SB(MTWsig500b2,MTWbgb2); MTWSBsig650b2 = SB(MTWsig650b2,MTWbgb2); MTWSBsig850b2 = SB(MTWsig850b2,MTWbgb2);
    MTWSsBsig425b2 = SsB(MTWsig425b2,MTWbgb2); MTWSsBsig500b2 = SsB(MTWsig500b2,MTWbgb2); MTWSsBsig650b2 = SsB(MTWsig650b2,MTWbgb2); MTWSsBsig850b2 = SsB(MTWsig850b2,MTWbgb2);
    MTWFoMsig425b2 = FOM(MTWsig425b2,MTWbgb2); MTWFoMsig500b2 = FOM(MTWsig500b2,MTWbgb2); MTWFoMsig650b2 = FOM(MTWsig650b2,MTWbgb2); MTWFoMsig850b2 = FOM(MTWsig850b2,MTWbgb2);
    MTWZsig425b2 = ZBi(MTWsig425b2,MTWbgb2); MTWZsig500b2 = ZBi(MTWsig500b2,MTWbgb2); MTWZsig650b2 = ZBi(MTWsig650b2,MTWbgb2); MTWZsig850b2 = ZBi(MTWsig850b2,MTWbgb2);
    //load(ds,d1,d2,MTWSBsig425b2,MTWSBsig500b2,MTWSBsig650b2,MTWSBsig850b2,2,"MT2W200/_add2bconstcut.txt");
    //load(ds,d1,d2,MTWSsBsig425b2,MTWSsBsig500b2,MTWSsBsig650b2,MTWSsBsig850b2,3,"MT2W200/_add2bconstcut.txt");
    //load(ds,d1,d2,MTWFoMsig425b2,MTWFoMsig500b2,MTWFoMsig650b2,MTWFoMsig850b2,4,"MT2W200/_add2bconstcut.txt");
    //load(ds,d1,d2,MTWZsig425b2,MTWZsig500b2,MTWZsig650b2,MTWZsig850b2,5,"MT2W200/_add2bconstcut.txt");
    
    if(version==1){
        Xvarb2 = varb2; Xcutb2 = cutb2; Xbgb2 = bgb2; Xsig425b2 = sig425b2; Xsig500b2 = sig500b2; Xsig650b2 = sig650b2; Xsig850b2 = sig850b2;
        XSBsig425b2 = SBsig425b2; XSBsig500b2 = SBsig500b2; XSBsig650b2 = SBsig650b2; XSBsig850b2 = SBsig850b2; XSsBsig425b2 = SsBsig425b2; XSsBsig500b2 = SsBsig500b2; XSsBsig650b2 = SsBsig650b2; XSsBsig850b2 = SsBsig850b2;
        XFoMsig425b2 = FoMsig425b2; XFoMsig500b2 = FoMsig500b2; XFoMsig650b2 = FoMsig650b2; XFoMsig850b2 = FoMsig850b2; XZsig425b2 = Zsig425b2; XZsig500b2 = Zsig500b2; XZsig650b2 = Zsig650b2; XZsig850b2 = Zsig850b2;
    }if(version==2){
        Xvarb2 = METvarb2; Xcutb2 = METcutb2; Xbgb2 = METbgb2; Xsig425b2 = METsig425b2; Xsig500b2 = METsig500b2; Xsig650b2 = METsig650b2; Xsig850b2 = METsig850b2;
        XSBsig425b2 = METSBsig425b2; XSBsig500b2 = METSBsig500b2; XSBsig650b2 = METSBsig650b2; XSBsig850b2 = METSBsig850b2; XSsBsig425b2 = METSsBsig425b2; XSsBsig500b2 = METSsBsig500b2; XSsBsig650b2 = METSsBsig650b2; XSsBsig850b2 = METSsBsig850b2;
        XFoMsig425b2 = METFoMsig425b2; XFoMsig500b2 = METFoMsig500b2; XFoMsig650b2 = METFoMsig650b2; XFoMsig850b2 = METFoMsig850b2; XZsig425b2 = METZsig425b2; XZsig500b2 = METZsig500b2; XZsig650b2 = METZsig650b2; XZsig850b2 = METZsig850b2;
    }if(version==3){
        Xvarb2 = chivarb2; Xcutb2 = chicutb2; Xbgb2 = chibgb2; Xsig425b2 = chisig425b2; Xsig500b2 = chisig500b2; Xsig650b2 = chisig650b2; Xsig850b2 = chisig850b2;
        XSBsig425b2 = chiSBsig425b2; XSBsig500b2 = chiSBsig500b2; XSBsig650b2 = chiSBsig650b2; XSBsig850b2 = chiSBsig850b2; XSsBsig425b2 = chiSsBsig425b2; XSsBsig500b2 = chiSsBsig500b2; XSsBsig650b2 = chiSsBsig650b2; XSsBsig850b2 = chiSsBsig850b2;
        XFoMsig425b2 = chiFoMsig425b2; XFoMsig500b2 = chiFoMsig500b2; XFoMsig650b2 = chiFoMsig650b2; XFoMsig850b2 = chiFoMsig850b2; XZsig425b2 = chiZsig425b2; XZsig500b2 = chiZsig500b2; XZsig650b2 = chiZsig650b2; XZsig850b2 = chiZsig850b2;
    }if(version==4){
        Xvarb2 = MTWvarb2; Xcutb2 = MTWcutb2; Xbgb2 = MTWbgb2; Xsig425b2 = MTWsig425b2; Xsig500b2 = MTWsig500b2; Xsig650b2 = MTWsig650b2; Xsig850b2 = MTWsig850b2;
        XSBsig425b2 = MTWSBsig425b2; XSBsig500b2 = MTWSBsig500b2; XSBsig650b2 = MTWSBsig650b2; XSBsig850b2 = MTWSBsig850b2; XSsBsig425b2 = MTWSsBsig425b2; XSsBsig500b2 = MTWSsBsig500b2; XSsBsig650b2 = MTWSsBsig650b2; XSsBsig850b2 = MTWSsBsig850b2;
        XFoMsig425b2 = MTWFoMsig425b2; XFoMsig500b2 = MTWFoMsig500b2; XFoMsig650b2 = MTWFoMsig650b2; XFoMsig850b2 = MTWFoMsig850b2; XZsig425b2 = MTWZsig425b2; XZsig500b2 = MTWZsig500b2; XZsig650b2 = MTWZsig650b2; XZsig850b2 = MTWZsig850b2;
    }
    
    
    
    if(cutflow){
        
        cout << "cuts cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << cutb2[j] << " & " << METcutb2[j] << " & " << chicutb2[j] /*<< " & " << MTWcutb2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "bg yield cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << bgb2[j] << " & " << METbgb2[j] << " & " << chibgb2[j] /*<< " & " << MTWbgb2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig425 yield cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << sig425b2[j] << " & " << METsig425b2[j] << " & " << chisig425b2[j] /*<< " & " << MTWsig425b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 yield cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << sig500b2[j] << " & " << METsig500b2[j] << " & " << chisig500b2[j] /*<< " & " << MTWsig500b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 yield cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << sig650b2[j] << " & " << METsig650b2[j] << " & " << chisig650b2[j]/* << " & " << MTWsig650b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 yield cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << sig850b2[j] << " & " << METsig850b2[j] << " & " << chisig850b2[j]/* << " & " << MTWsig850b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 S/B cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SBsig425b2[j] << " & " << METSBsig425b2[j] << " & " << chiSBsig425b2[j] /*<< " & " << MTWSBsig425b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 S/B cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SBsig500b2[j] << " & " << METSBsig500b2[j] << " & " << chiSBsig500b2[j] /*<< " & " << MTWSBsig500b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 S/B cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SBsig650b2[j] << " & " << METSBsig650b2[j] << " & " << chiSBsig650b2[j] /*<< " & " << MTWSBsig650b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 S/B cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SBsig850b2[j] << " & " << METSBsig850b2[j] << " & " << chiSBsig850b2[j] /*<< " & " << MTWSBsig850b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 S/sqrt(B) cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SsBsig425b2[j] << " & " << METSsBsig425b2[j] << " & " << chiSsBsig425b2[j] /*<< " & " << MTWSsBsig425b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 S/sqrt(B) cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SsBsig500b2[j] << " & " << METSsBsig500b2[j] << " & " << chiSsBsig500b2[j] /*<< " & " << MTWSsBsig500b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 S/sqrt(B) cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SsBsig650b2[j] << " & " << METSsBsig650b2[j] << " & " << chiSsBsig650b2[j] /*<< " & " << MTWSsBsig650b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 S/sqrt(B) cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << SsBsig850b2[j] << " & " << METSsBsig850b2[j] << " & " << chiSsBsig850b2[j] /*<< " & " << MTWSsBsig850b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 FoM cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << FoMsig425b2[j] << " & " << METFoMsig425b2[j] << " & " << chiFoMsig425b2[j] /*<< " & " << MTWFoMsig425b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 FoM cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << FoMsig500b2[j] << " & " << METFoMsig500b2[j] << " & " << chiFoMsig500b2[j]/* << " & " << MTWFoMsig500b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 FoM cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << FoMsig650b2[j] << " & " << METFoMsig650b2[j] << " & " << chiFoMsig650b2[j] /*<< " & " << MTWFoMsig650b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 FoM cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << FoMsig850b2[j] << " & " << METFoMsig850b2[j] << " & " << chiFoMsig850b2[j] /*<< " & " << MTWFoMsig850b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 Zbi cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << Zsig425b2[j] << " & " << METZsig425b2[j] << " & " << chiZsig425b2[j] /*<< " & " << MTWZsig425b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 Zbi cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << Zsig500b2[j] << " & " << METZsig500b2[j] << " & " << chiZsig500b2[j]/* << " & " << MTWZsig500b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 Zbi cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << Zsig650b2[j] << " & " << METZsig650b2[j] << " & " << chiZsig650b2[j]/* << " & " << MTWZsig650b2[j]*/ << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 Zbi cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|ccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ \\\\" << endl; //& $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] /*<< ">"<<cutb2[j] << "$" */<< fixed << setprecision(2) << " & " << Zsig850b2[j] << " & " << METZsig850b2[j] << " & " << chiZsig850b2[j] /*<< " & " << MTWZsig850b2[j] */<< "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
  
        
    }
    
    
    
    
    
    
    
    
    
    
    
    if(single){
        cout << "Cuts and yields" << endl;
    
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|lr|ccccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & cut [GeV] & bg & 425-325 & 500-325 & 650-325 & 850-100 \\\\" << endl;
        cout << "\\hline" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << fixed << setprecision(2) << Xvarb2[j] << " & " << Xcutb2[j] << " & " << Xbgb2[j] << " & " << Xsig425b2[j] << " & " << Xsig500b2[j] << " & " << Xsig650b2[j] << " & " << Xsig850b2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "S/B" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & 425-325 & 500-325 & 650-325 & 850-100 \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << fixed << setprecision(2) << Xvarb2[j] << " & " << XSBsig425b2[j] << " & " << XSBsig500b2[j] << " & " << XSBsig650b2[j] << " & " << XSBsig850b2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "S/sqrt(B)" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & 425-325 & 500-325 & 650-325 & 850-100 \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << fixed << setprecision(2) << Xvarb2[j] << " & " << XSsBsig425b2[j] << " & " << XSsBsig500b2[j] << " & " << XSsBsig650b2[j] << " & " << XSsBsig850b2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "FoM" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & 425-325 & 500-325 & 650-325 & 850-100 \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << fixed << setprecision(2) << Xvarb2[j] << " & " << XFoMsig425b2[j] << " & " << XFoMsig500b2[j] << " & " << XFoMsig650b2[j] << " & " << XFoMsig850b2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "Zbi" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & 425-325 & 500-325 & 650-325 & 850-100 \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << fixed << setprecision(2) << Xvarb2[j] << " & " << XZsig425b2[j] << " & " << XZsig500b2[j] << " & " << XZsig650b2[j] << " & " << XZsig850b2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
    }

}