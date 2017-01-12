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

float Zbi_(float sig, float bg, float bgrelunc=0.3){
    
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

float FoM_(float sig, float bg, float bgrelunc=0.3){
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
            for(unsigned int i = 0; i<24; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tbg,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                TString mystring = StringValue;
                variable.push_back(mystring); cut.push_back(tcut); bg.push_back(tbg);
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==2 && !strcmp(buffer, "now S/B")){
            for(unsigned int i = 0; i<24; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==3 && !strcmp(buffer, "now S/sqrt(B)")){
            for(unsigned int i = 0; i<24; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==4 && !strcmp(buffer, "now FoM = S/sqrt(B+Delta(B)^2)")){
            for(unsigned int i = 0; i<24; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
        if(load==5 && !strcmp(buffer, "now Z_bi")){
            for(unsigned int i = 0; i<24; ++i){
                IN.getline(buffer, 200, '\n');
                sscanf(buffer, "\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t",StringValue,&tcut,&tsig425,&tsig500,&tsig650,&tsig850,&td);
                //cout << StringValue << " " << tcut << " " << tbg << " " << tsig425 << " " << tsig500 << " " << tsig650 << " " << tsig850 << " " << td << endl;
                sig425.push_back(tsig425); sig500.push_back(tsig500); sig650.push_back(tsig650); sig850.push_back(tsig850);
            }
        }
    }
    
}


void makeTables(){
    
    bool single = true;//plot single addstring - X variable
    bool cutflow = true;//compare among addstring
    int version = 1; //1 normal, 2 MET300, 3 chi210, 4 MT2W200
    
    
    vector<TString> Xvarb1;     vector<TString> varb1;     vector<TString> METvarb1;     vector<TString> chivarb1;     vector<TString> MTWvarb1;
    vector<float> Xcutb1;       vector<float> cutb1;       vector<float> METcutb1;       vector<float> chicutb1;       vector<float> MTWcutb1;
    vector<float> Xbgb1;        vector<float> bgb1;        vector<float> METbgb1;        vector<float> chibgb1;        vector<float> MTWbgb1;
    vector<float> Xsig425b1;    vector<float> sig425b1;    vector<float> METsig425b1;    vector<float> chisig425b1;    vector<float> MTWsig425b1;
    vector<float> Xsig500b1;    vector<float> sig500b1;    vector<float> METsig500b1;    vector<float> chisig500b1;    vector<float> MTWsig500b1;
    vector<float> Xsig650b1;    vector<float> sig650b1;    vector<float> METsig650b1;    vector<float> chisig650b1;    vector<float> MTWsig650b1;
    vector<float> Xsig850b1;    vector<float> sig850b1;    vector<float> METsig850b1;    vector<float> chisig850b1;    vector<float> MTWsig850b1;
    vector<float> XSBsig425b1;  vector<float> SBsig425b1;  vector<float> METSBsig425b1;  vector<float> chiSBsig425b1;  vector<float> MTWSBsig425b1;
    vector<float> XSBsig500b1;  vector<float> SBsig500b1;  vector<float> METSBsig500b1;  vector<float> chiSBsig500b1;  vector<float> MTWSBsig500b1;
    vector<float> XSBsig650b1;  vector<float> SBsig650b1;  vector<float> METSBsig650b1;  vector<float> chiSBsig650b1;  vector<float> MTWSBsig650b1;
    vector<float> XSBsig850b1;  vector<float> SBsig850b1;  vector<float> METSBsig850b1;  vector<float> chiSBsig850b1;  vector<float> MTWSBsig850b1;
    vector<float> XSsBsig425b1; vector<float> SsBsig425b1; vector<float> METSsBsig425b1; vector<float> chiSsBsig425b1; vector<float> MTWSsBsig425b1;
    vector<float> XSsBsig500b1; vector<float> SsBsig500b1; vector<float> METSsBsig500b1; vector<float> chiSsBsig500b1; vector<float> MTWSsBsig500b1;
    vector<float> XSsBsig650b1; vector<float> SsBsig650b1; vector<float> METSsBsig650b1; vector<float> chiSsBsig650b1; vector<float> MTWSsBsig650b1;
    vector<float> XSsBsig850b1; vector<float> SsBsig850b1; vector<float> METSsBsig850b1; vector<float> chiSsBsig850b1; vector<float> MTWSsBsig850b1;
    vector<float> XFoMsig425b1; vector<float> FoMsig425b1; vector<float> METFoMsig425b1; vector<float> chiFoMsig425b1; vector<float> MTWFoMsig425b1;
    vector<float> XFoMsig500b1; vector<float> FoMsig500b1; vector<float> METFoMsig500b1; vector<float> chiFoMsig500b1; vector<float> MTWFoMsig500b1;
    vector<float> XFoMsig650b1; vector<float> FoMsig650b1; vector<float> METFoMsig650b1; vector<float> chiFoMsig650b1; vector<float> MTWFoMsig650b1;
    vector<float> XFoMsig850b1; vector<float> FoMsig850b1; vector<float> METFoMsig850b1; vector<float> chiFoMsig850b1; vector<float> MTWFoMsig850b1;
    vector<float> XZsig425b1;   vector<float> Zsig425b1;   vector<float> METZsig425b1;   vector<float> chiZsig425b1;   vector<float> MTWZsig425b1;
    vector<float> XZsig500b1;   vector<float> Zsig500b1;   vector<float> METZsig500b1;   vector<float> chiZsig500b1;   vector<float> MTWZsig500b1;
    vector<float> XZsig650b1;   vector<float> Zsig650b1;   vector<float> METZsig650b1;   vector<float> chiZsig650b1;   vector<float> MTWZsig650b1;
    vector<float> XZsig850b1;   vector<float> Zsig850b1;   vector<float> METZsig850b1;   vector<float> chiZsig850b1;   vector<float> MTWZsig850b1;
    vector<float> d1,d2; vector<TString> ds;
    
    load(varb1,cutb1,bgb1,sig425b1,sig500b1,sig650b1,sig850b1,1,"_add1b.txt");
    SBsig425b1 = SB(sig425b1,bgb1); SBsig500b1 = SB(sig500b1,bgb1); SBsig650b1 = SB(sig650b1,bgb1); SBsig850b1 = SB(sig850b1,bgb1);
    SsBsig425b1 = SsB(sig425b1,bgb1); SsBsig500b1 = SsB(sig500b1,bgb1); SsBsig650b1 = SsB(sig650b1,bgb1); SsBsig850b1 = SsB(sig850b1,bgb1);
    FoMsig425b1 = FOM(sig425b1,bgb1); FoMsig500b1 = FOM(sig500b1,bgb1); FoMsig650b1 = FOM(sig650b1,bgb1); FoMsig850b1 = FOM(sig850b1,bgb1);
    Zsig425b1 = ZBi(sig425b1,bgb1); Zsig500b1 = ZBi(sig500b1,bgb1); Zsig650b1 = ZBi(sig650b1,bgb1); Zsig850b1 = ZBi(sig850b1,bgb1);
    //load(ds,d1,d2,SBsig425b1,SBsig500b1,SBsig650b1,SBsig850b1,2,"_add1b.txt");
    //load(ds,d1,d2,SsBsig425b1,SsBsig500b1,SsBsig650b1,SsBsig850b1,3,"_add1b.txt");
    //load(ds,d1,d2,FoMsig425b1,FoMsig500b1,FoMsig650b1,FoMsig850b1,4,"_add1b.txt");
    //load(ds,d1,d2,Zsig425b1,Zsig500b1,Zsig650b1,Zsig850b1,5,"_add1b.txt");
    
    load(METvarb1,METcutb1,METbgb1,METsig425b1,METsig500b1,METsig650b1,METsig850b1,1,"MET300/_add1b.txt");
    METSBsig425b1 = SB(METsig425b1,METbgb1); METSBsig500b1 = SB(METsig500b1,METbgb1); METSBsig650b1 = SB(METsig650b1,METbgb1); METSBsig850b1 = SB(METsig850b1,METbgb1);
    METSsBsig425b1 = SsB(METsig425b1,METbgb1); METSsBsig500b1 = SsB(METsig500b1,METbgb1); METSsBsig650b1 = SsB(METsig650b1,METbgb1); METSsBsig850b1 = SsB(METsig850b1,METbgb1);
    METFoMsig425b1 = FOM(METsig425b1,METbgb1); METFoMsig500b1 = FOM(METsig500b1,METbgb1); METFoMsig650b1 = FOM(METsig650b1,METbgb1); METFoMsig850b1 = FOM(METsig850b1,METbgb1);
    METZsig425b1 = ZBi(METsig425b1,METbgb1); METZsig500b1 = ZBi(METsig500b1,METbgb1); METZsig650b1 = ZBi(METsig650b1,METbgb1); METZsig850b1 = ZBi(METsig850b1,METbgb1);
    //load(ds,d1,d2,METSBsig425b1,METSBsig500b1,METSBsig650b1,METSBsig850b1,2,"MET300/_add1b.txt");
    //load(ds,d1,d2,METSsBsig425b1,METSsBsig500b1,METSsBsig650b1,METSsBsig850b1,3,"MET300/_add1b.txt");
    //load(ds,d1,d2,METFoMsig425b1,METFoMsig500b1,METFoMsig650b1,METFoMsig850b1,4,"MET300/_add1b.txt");
    //load(ds,d1,d2,METZsig425b1,METZsig500b1,METZsig650b1,METZsig850b1,5,"MET300/_add1b.txt");
    
    load(chivarb1,chicutb1,chibgb1,chisig425b1,chisig500b1,chisig650b1,chisig850b1,1,"chi210/_add1b.txt");
    chiSBsig425b1 = SB(chisig425b1,chibgb1); chiSBsig500b1 = SB(chisig500b1,chibgb1); chiSBsig650b1 = SB(chisig650b1,chibgb1); chiSBsig850b1 = SB(chisig850b1,chibgb1);
    chiSsBsig425b1 = SsB(chisig425b1,chibgb1); chiSsBsig500b1 = SsB(chisig500b1,chibgb1); chiSsBsig650b1 = SsB(chisig650b1,chibgb1); chiSsBsig850b1 = SsB(chisig850b1,chibgb1);
    chiFoMsig425b1 = FOM(chisig425b1,chibgb1); chiFoMsig500b1 = FOM(chisig500b1,chibgb1); chiFoMsig650b1 = FOM(chisig650b1,chibgb1); chiFoMsig850b1 = FOM(chisig850b1,chibgb1);
    chiZsig425b1 = ZBi(chisig425b1,chibgb1); chiZsig500b1 = ZBi(chisig500b1,chibgb1); chiZsig650b1 = ZBi(chisig650b1,chibgb1); chiZsig850b1 = ZBi(chisig850b1,chibgb1);
    //load(ds,d1,d2,chiSBsig425b1,chiSBsig500b1,chiSBsig650b1,chiSBsig850b1,2,"chi210/_add1b.txt");
    //load(ds,d1,d2,chiSsBsig425b1,chiSsBsig500b1,chiSsBsig650b1,chiSsBsig850b1,3,"chi210/_add1b.txt");
    //load(ds,d1,d2,chiFoMsig425b1,chiFoMsig500b1,chiFoMsig650b1,chiFoMsig850b1,4,"chi210/_add1b.txt");
    //load(ds,d1,d2,chiZsig425b1,chiZsig500b1,chiZsig650b1,chiZsig850b1,5,"chi210/_add1b.txt");
    
    load(MTWvarb1,MTWcutb1,MTWbgb1,MTWsig425b1,MTWsig500b1,MTWsig650b1,MTWsig850b1,1,"MT2W200/_add1b.txt");
    MTWSBsig425b1 = SB(MTWsig425b1,MTWbgb1); MTWSBsig500b1 = SB(MTWsig500b1,MTWbgb1); MTWSBsig650b1 = SB(MTWsig650b1,MTWbgb1); MTWSBsig850b1 = SB(MTWsig850b1,MTWbgb1);
    MTWSsBsig425b1 = SsB(MTWsig425b1,MTWbgb1); MTWSsBsig500b1 = SsB(MTWsig500b1,MTWbgb1); MTWSsBsig650b1 = SsB(MTWsig650b1,MTWbgb1); MTWSsBsig850b1 = SsB(MTWsig850b1,MTWbgb1);
    MTWFoMsig425b1 = FOM(MTWsig425b1,MTWbgb1); MTWFoMsig500b1 = FOM(MTWsig500b1,MTWbgb1); MTWFoMsig650b1 = FOM(MTWsig650b1,MTWbgb1); MTWFoMsig850b1 = FOM(MTWsig850b1,MTWbgb1);
    MTWZsig425b1 = ZBi(MTWsig425b1,MTWbgb1); MTWZsig500b1 = ZBi(MTWsig500b1,MTWbgb1); MTWZsig650b1 = ZBi(MTWsig650b1,MTWbgb1); MTWZsig850b1 = ZBi(MTWsig850b1,MTWbgb1);
    //load(ds,d1,d2,MTWSBsig425b1,MTWSBsig500b1,MTWSBsig650b1,MTWSBsig850b1,2,"MT2W200/_add1b.txt");
    //load(ds,d1,d2,MTWSsBsig425b1,MTWSsBsig500b1,MTWSsBsig650b1,MTWSsBsig850b1,3,"MT2W200/_add1b.txt");
    //load(ds,d1,d2,MTWFoMsig425b1,MTWFoMsig500b1,MTWFoMsig650b1,MTWFoMsig850b1,4,"MT2W200/_add1b.txt");
    //load(ds,d1,d2,MTWZsig425b1,MTWZsig500b1,MTWZsig650b1,MTWZsig850b1,5,"MT2W200/_add1b.txt");
    
    if(version==1){
        Xvarb1 = varb1; Xcutb1 = cutb1; Xbgb1 = bgb1; Xsig425b1 = sig425b1; Xsig500b1 = sig500b1; Xsig650b1 = sig650b1; Xsig850b1 = sig850b1;
        XSBsig425b1 = SBsig425b1; XSBsig500b1 = SBsig500b1; XSBsig650b1 = SBsig650b1; XSBsig850b1 = SBsig850b1; XSsBsig425b1 = SsBsig425b1; XSsBsig500b1 = SsBsig500b1; XSsBsig650b1 = SsBsig650b1; XSsBsig850b1 = SsBsig850b1;
        XFoMsig425b1 = FoMsig425b1; XFoMsig500b1 = FoMsig500b1; XFoMsig650b1 = FoMsig650b1; XFoMsig850b1 = FoMsig850b1; XZsig425b1 = Zsig425b1; XZsig500b1 = Zsig500b1; XZsig650b1 = Zsig650b1; XZsig850b1 = Zsig850b1;
    }if(version==2){
        Xvarb1 = METvarb1; Xcutb1 = METcutb1; Xbgb1 = METbgb1; Xsig425b1 = METsig425b1; Xsig500b1 = METsig500b1; Xsig650b1 = METsig650b1; Xsig850b1 = METsig850b1;
        XSBsig425b1 = METSBsig425b1; XSBsig500b1 = METSBsig500b1; XSBsig650b1 = METSBsig650b1; XSBsig850b1 = METSBsig850b1; XSsBsig425b1 = METSsBsig425b1; XSsBsig500b1 = METSsBsig500b1; XSsBsig650b1 = METSsBsig650b1; XSsBsig850b1 = METSsBsig850b1;
        XFoMsig425b1 = METFoMsig425b1; XFoMsig500b1 = METFoMsig500b1; XFoMsig650b1 = METFoMsig650b1; XFoMsig850b1 = METFoMsig850b1; XZsig425b1 = METZsig425b1; XZsig500b1 = METZsig500b1; XZsig650b1 = METZsig650b1; XZsig850b1 = METZsig850b1;
    }if(version==3){
        Xvarb1 = chivarb1; Xcutb1 = chicutb1; Xbgb1 = chibgb1; Xsig425b1 = chisig425b1; Xsig500b1 = chisig500b1; Xsig650b1 = chisig650b1; Xsig850b1 = chisig850b1;
        XSBsig425b1 = chiSBsig425b1; XSBsig500b1 = chiSBsig500b1; XSBsig650b1 = chiSBsig650b1; XSBsig850b1 = chiSBsig850b1; XSsBsig425b1 = chiSsBsig425b1; XSsBsig500b1 = chiSsBsig500b1; XSsBsig650b1 = chiSsBsig650b1; XSsBsig850b1 = chiSsBsig850b1;
        XFoMsig425b1 = chiFoMsig425b1; XFoMsig500b1 = chiFoMsig500b1; XFoMsig650b1 = chiFoMsig650b1; XFoMsig850b1 = chiFoMsig850b1; XZsig425b1 = chiZsig425b1; XZsig500b1 = chiZsig500b1; XZsig650b1 = chiZsig650b1; XZsig850b1 = chiZsig850b1;
    }if(version==4){
        Xvarb1 = MTWvarb1; Xcutb1 = MTWcutb1; Xbgb1 = MTWbgb1; Xsig425b1 = MTWsig425b1; Xsig500b1 = MTWsig500b1; Xsig650b1 = MTWsig650b1; Xsig850b1 = MTWsig850b1;
        XSBsig425b1 = MTWSBsig425b1; XSBsig500b1 = MTWSBsig500b1; XSBsig650b1 = MTWSBsig650b1; XSBsig850b1 = MTWSBsig850b1; XSsBsig425b1 = MTWSsBsig425b1; XSsBsig500b1 = MTWSsBsig500b1; XSsBsig650b1 = MTWSsBsig650b1; XSsBsig850b1 = MTWSsBsig850b1;
        XFoMsig425b1 = MTWFoMsig425b1; XFoMsig500b1 = MTWFoMsig500b1; XFoMsig650b1 = MTWFoMsig650b1; XFoMsig850b1 = MTWFoMsig850b1; XZsig425b1 = MTWZsig425b1; XZsig500b1 = MTWZsig500b1; XZsig650b1 = MTWZsig650b1; XZsig850b1 = MTWZsig850b1;
    }
    
    
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
    
    load(varb2,cutb2,bgb2,sig425b2,sig500b2,sig650b2,sig850b2,1,"_add2b.txt");
    SBsig425b2 = SB(sig425b2,bgb2); SBsig500b2 = SB(sig500b2,bgb2); SBsig650b2 = SB(sig650b2,bgb2); SBsig850b2 = SB(sig850b2,bgb2);
    SsBsig425b2 = SsB(sig425b2,bgb2); SsBsig500b2 = SsB(sig500b2,bgb2); SsBsig650b2 = SsB(sig650b2,bgb2); SsBsig850b2 = SsB(sig850b2,bgb2);
    FoMsig425b2 = FOM(sig425b2,bgb2); FoMsig500b2 = FOM(sig500b2,bgb2); FoMsig650b2 = FOM(sig650b2,bgb2); FoMsig850b2 = FOM(sig850b2,bgb2);
    Zsig425b2 = ZBi(sig425b2,bgb2); Zsig500b2 = ZBi(sig500b2,bgb2); Zsig650b2 = ZBi(sig650b2,bgb2); Zsig850b2 = ZBi(sig850b2,bgb2);
    //load(ds,d1,d2,SBsig425b2,SBsig500b2,SBsig650b2,SBsig850b2,2,"_add2b.txt");
    //load(ds,d1,d2,SsBsig425b2,SsBsig500b2,SsBsig650b2,SsBsig850b2,3,"_add2b.txt");
    //load(ds,d1,d2,FoMsig425b2,FoMsig500b2,FoMsig650b2,FoMsig850b2,4,"_add2b.txt");
    //load(ds,d1,d2,Zsig425b2,Zsig500b2,Zsig650b2,Zsig850b2,5,"_add2b.txt");
    
    load(METvarb2,METcutb2,METbgb2,METsig425b2,METsig500b2,METsig650b2,METsig850b2,1,"MET300/_add2b.txt");
    METSBsig425b2 = SB(METsig425b2,METbgb2); METSBsig500b2 = SB(METsig500b2,METbgb2); METSBsig650b2 = SB(METsig650b2,METbgb2); METSBsig850b2 = SB(METsig850b2,METbgb2);
    METSsBsig425b2 = SsB(METsig425b2,METbgb2); METSsBsig500b2 = SsB(METsig500b2,METbgb2); METSsBsig650b2 = SsB(METsig650b2,METbgb2); METSsBsig850b2 = SsB(METsig850b2,METbgb2);
    METFoMsig425b2 = FOM(METsig425b2,METbgb2); METFoMsig500b2 = FOM(METsig500b2,METbgb2); METFoMsig650b2 = FOM(METsig650b2,METbgb2); METFoMsig850b2 = FOM(METsig850b2,METbgb2);
    METZsig425b2 = ZBi(METsig425b2,METbgb2); METZsig500b2 = ZBi(METsig500b2,METbgb2); METZsig650b2 = ZBi(METsig650b2,METbgb2); METZsig850b2 = ZBi(METsig850b2,METbgb2);
    //load(ds,d1,d2,METSBsig425b2,METSBsig500b2,METSBsig650b2,METSBsig850b2,2,"MET300/_add2b.txt");
    //load(ds,d1,d2,METSsBsig425b2,METSsBsig500b2,METSsBsig650b2,METSsBsig850b2,3,"MET300/_add2b.txt");
    //load(ds,d1,d2,METFoMsig425b2,METFoMsig500b2,METFoMsig650b2,METFoMsig850b2,4,"MET300/_add2b.txt");
    //load(ds,d1,d2,METZsig425b2,METZsig500b2,METZsig650b2,METZsig850b2,5,"MET300/_add2b.txt");
    
    load(chivarb2,chicutb2,chibgb2,chisig425b2,chisig500b2,chisig650b2,chisig850b2,1,"chi210/_add2b.txt");
    chiSBsig425b2 = SB(chisig425b2,chibgb2); chiSBsig500b2 = SB(chisig500b2,chibgb2); chiSBsig650b2 = SB(chisig650b2,chibgb2); chiSBsig850b2 = SB(chisig850b2,chibgb2);
    chiSsBsig425b2 = SsB(chisig425b2,chibgb2); chiSsBsig500b2 = SsB(chisig500b2,chibgb2); chiSsBsig650b2 = SsB(chisig650b2,chibgb2); chiSsBsig850b2 = SsB(chisig850b2,chibgb2);
    chiFoMsig425b2 = FOM(chisig425b2,chibgb2); chiFoMsig500b2 = FOM(chisig500b2,chibgb2); chiFoMsig650b2 = FOM(chisig650b2,chibgb2); chiFoMsig850b2 = FOM(chisig850b2,chibgb2);
    chiZsig425b2 = ZBi(chisig425b2,chibgb2); chiZsig500b2 = ZBi(chisig500b2,chibgb2); chiZsig650b2 = ZBi(chisig650b2,chibgb2); chiZsig850b2 = ZBi(chisig850b2,chibgb2);
    //load(ds,d1,d2,chiSBsig425b2,chiSBsig500b2,chiSBsig650b2,chiSBsig850b2,2,"chi210/_add2b.txt");
    //load(ds,d1,d2,chiSsBsig425b2,chiSsBsig500b2,chiSsBsig650b2,chiSsBsig850b2,3,"chi210/_add2b.txt");
    //load(ds,d1,d2,chiFoMsig425b2,chiFoMsig500b2,chiFoMsig650b2,chiFoMsig850b2,4,"chi210/_add2b.txt");
    //load(ds,d1,d2,chiZsig425b2,chiZsig500b2,chiZsig650b2,chiZsig850b2,5,"chi210/_add2b.txt");
    
    load(MTWvarb2,MTWcutb2,MTWbgb2,MTWsig425b2,MTWsig500b2,MTWsig650b2,MTWsig850b2,1,"MT2W200/_add2b.txt");
    MTWSBsig425b2 = SB(MTWsig425b2,MTWbgb2); MTWSBsig500b2 = SB(MTWsig500b2,MTWbgb2); MTWSBsig650b2 = SB(MTWsig650b2,MTWbgb2); MTWSBsig850b2 = SB(MTWsig850b2,MTWbgb2);
    MTWSsBsig425b2 = SsB(MTWsig425b2,MTWbgb2); MTWSsBsig500b2 = SsB(MTWsig500b2,MTWbgb2); MTWSsBsig650b2 = SsB(MTWsig650b2,MTWbgb2); MTWSsBsig850b2 = SsB(MTWsig850b2,MTWbgb2);
    MTWFoMsig425b2 = FOM(MTWsig425b2,MTWbgb2); MTWFoMsig500b2 = FOM(MTWsig500b2,MTWbgb2); MTWFoMsig650b2 = FOM(MTWsig650b2,MTWbgb2); MTWFoMsig850b2 = FOM(MTWsig850b2,MTWbgb2);
    MTWZsig425b2 = ZBi(MTWsig425b2,MTWbgb2); MTWZsig500b2 = ZBi(MTWsig500b2,MTWbgb2); MTWZsig650b2 = ZBi(MTWsig650b2,MTWbgb2); MTWZsig850b2 = ZBi(MTWsig850b2,MTWbgb2);
    //load(ds,d1,d2,MTWSBsig425b2,MTWSBsig500b2,MTWSBsig650b2,MTWSBsig850b2,2,"MT2W200/_add2b.txt");
    //load(ds,d1,d2,MTWSsBsig425b2,MTWSsBsig500b2,MTWSsBsig650b2,MTWSsBsig850b2,3,"MT2W200/_add2b.txt");
    //load(ds,d1,d2,MTWFoMsig425b2,MTWFoMsig500b2,MTWFoMsig650b2,MTWFoMsig850b2,4,"MT2W200/_add2b.txt");
    //load(ds,d1,d2,MTWZsig425b2,MTWZsig500b2,MTWZsig650b2,MTWZsig850b2,5,"MT2W200/_add2b.txt");
    
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
    
    vector<TString> Xvarj2;     vector<TString> varj2;     vector<TString> METvarj2;     vector<TString> chivarj2;     vector<TString> MTWvarj2;
    vector<float> Xcutj2;       vector<float> cutj2;       vector<float> METcutj2;       vector<float> chicutj2;       vector<float> MTWcutj2;
    vector<float> Xbgj2;        vector<float> bgj2;        vector<float> METbgj2;        vector<float> chibgj2;        vector<float> MTWbgj2;
    vector<float> Xsig425j2;    vector<float> sig425j2;    vector<float> METsig425j2;    vector<float> chisig425j2;    vector<float> MTWsig425j2;
    vector<float> Xsig500j2;    vector<float> sig500j2;    vector<float> METsig500j2;    vector<float> chisig500j2;    vector<float> MTWsig500j2;
    vector<float> Xsig650j2;    vector<float> sig650j2;    vector<float> METsig650j2;    vector<float> chisig650j2;    vector<float> MTWsig650j2;
    vector<float> Xsig850j2;    vector<float> sig850j2;    vector<float> METsig850j2;    vector<float> chisig850j2;    vector<float> MTWsig850j2;
    vector<float> XSBsig425j2;  vector<float> SBsig425j2;  vector<float> METSBsig425j2;  vector<float> chiSBsig425j2;  vector<float> MTWSBsig425j2;
    vector<float> XSBsig500j2;  vector<float> SBsig500j2;  vector<float> METSBsig500j2;  vector<float> chiSBsig500j2;  vector<float> MTWSBsig500j2;
    vector<float> XSBsig650j2;  vector<float> SBsig650j2;  vector<float> METSBsig650j2;  vector<float> chiSBsig650j2;  vector<float> MTWSBsig650j2;
    vector<float> XSBsig850j2;  vector<float> SBsig850j2;  vector<float> METSBsig850j2;  vector<float> chiSBsig850j2;  vector<float> MTWSBsig850j2;
    vector<float> XSsBsig425j2; vector<float> SsBsig425j2; vector<float> METSsBsig425j2; vector<float> chiSsBsig425j2; vector<float> MTWSsBsig425j2;
    vector<float> XSsBsig500j2; vector<float> SsBsig500j2; vector<float> METSsBsig500j2; vector<float> chiSsBsig500j2; vector<float> MTWSsBsig500j2;
    vector<float> XSsBsig650j2; vector<float> SsBsig650j2; vector<float> METSsBsig650j2; vector<float> chiSsBsig650j2; vector<float> MTWSsBsig650j2;
    vector<float> XSsBsig850j2; vector<float> SsBsig850j2; vector<float> METSsBsig850j2; vector<float> chiSsBsig850j2; vector<float> MTWSsBsig850j2;
    vector<float> XFoMsig425j2; vector<float> FoMsig425j2; vector<float> METFoMsig425j2; vector<float> chiFoMsig425j2; vector<float> MTWFoMsig425j2;
    vector<float> XFoMsig500j2; vector<float> FoMsig500j2; vector<float> METFoMsig500j2; vector<float> chiFoMsig500j2; vector<float> MTWFoMsig500j2;
    vector<float> XFoMsig650j2; vector<float> FoMsig650j2; vector<float> METFoMsig650j2; vector<float> chiFoMsig650j2; vector<float> MTWFoMsig650j2;
    vector<float> XFoMsig850j2; vector<float> FoMsig850j2; vector<float> METFoMsig850j2; vector<float> chiFoMsig850j2; vector<float> MTWFoMsig850j2;
    vector<float> XZsig425j2;   vector<float> Zsig425j2;   vector<float> METZsig425j2;   vector<float> chiZsig425j2;   vector<float> MTWZsig425j2;
    vector<float> XZsig500j2;   vector<float> Zsig500j2;   vector<float> METZsig500j2;   vector<float> chiZsig500j2;   vector<float> MTWZsig500j2;
    vector<float> XZsig650j2;   vector<float> Zsig650j2;   vector<float> METZsig650j2;   vector<float> chiZsig650j2;   vector<float> MTWZsig650j2;
    vector<float> XZsig850j2;   vector<float> Zsig850j2;   vector<float> METZsig850j2;   vector<float> chiZsig850j2;   vector<float> MTWZsig850j2;
    
    load(varj2,cutj2,bgj2,sig425j2,sig500j2,sig650j2,sig850j2,1,"_add2j.txt");
    SBsig425j2 = SB(sig425j2,bgj2); SBsig500j2 = SB(sig500j2,bgj2); SBsig650j2 = SB(sig650j2,bgj2); SBsig850j2 = SB(sig850j2,bgj2);
    SsBsig425j2 = SsB(sig425j2,bgj2); SsBsig500j2 = SsB(sig500j2,bgj2); SsBsig650j2 = SsB(sig650j2,bgj2); SsBsig850j2 = SsB(sig850j2,bgj2);
    FoMsig425j2 = FOM(sig425j2,bgj2); FoMsig500j2 = FOM(sig500j2,bgj2); FoMsig650j2 = FOM(sig650j2,bgj2); FoMsig850j2 = FOM(sig850j2,bgj2);
    Zsig425j2 = ZBi(sig425j2,bgj2); Zsig500j2 = ZBi(sig500j2,bgj2); Zsig650j2 = ZBi(sig650j2,bgj2); Zsig850j2 = ZBi(sig850j2,bgj2);
    //load(ds,d1,d2,SBsig425j2,SBsig500j2,SBsig650j2,SBsig850j2,2,"_add2j.txt");
    //load(ds,d1,d2,SsBsig425j2,SsBsig500j2,SsBsig650j2,SsBsig850j2,3,"_add2j.txt");
    //load(ds,d1,d2,FoMsig425j2,FoMsig500j2,FoMsig650j2,FoMsig850j2,4,"_add2j.txt");
    //load(ds,d1,d2,Zsig425j2,Zsig500j2,Zsig650j2,Zsig850j2,5,"_add2j.txt");
    
    load(METvarj2,METcutj2,METbgj2,METsig425j2,METsig500j2,METsig650j2,METsig850j2,1,"MET300/_add2j.txt");
    METSBsig425j2 = SB(METsig425j2,METbgj2); METSBsig500j2 = SB(METsig500j2,METbgj2); METSBsig650j2 = SB(METsig650j2,METbgj2); METSBsig850j2 = SB(METsig850j2,METbgj2);
    METSsBsig425j2 = SsB(METsig425j2,METbgj2); METSsBsig500j2 = SsB(METsig500j2,METbgj2); METSsBsig650j2 = SsB(METsig650j2,METbgj2); METSsBsig850j2 = SsB(METsig850j2,METbgj2);
    METFoMsig425j2 = FOM(METsig425j2,METbgj2); METFoMsig500j2 = FOM(METsig500j2,METbgj2); METFoMsig650j2 = FOM(METsig650j2,METbgj2); METFoMsig850j2 = FOM(METsig850j2,METbgj2);
    METZsig425j2 = ZBi(METsig425j2,METbgj2); METZsig500j2 = ZBi(METsig500j2,METbgj2); METZsig650j2 = ZBi(METsig650j2,METbgj2); METZsig850j2 = ZBi(METsig850j2,METbgj2);
    //load(ds,d1,d2,METSBsig425j2,METSBsig500j2,METSBsig650j2,METSBsig850j2,2,"MET300/_add2j.txt");
    //load(ds,d1,d2,METSsBsig425j2,METSsBsig500j2,METSsBsig650j2,METSsBsig850j2,3,"MET300/_add2j.txt");
    //load(ds,d1,d2,METFoMsig425j2,METFoMsig500j2,METFoMsig650j2,METFoMsig850j2,4,"MET300/_add2j.txt");
    //load(ds,d1,d2,METZsig425j2,METZsig500j2,METZsig650j2,METZsig850j2,5,"MET300/_add2j.txt");
    
    load(chivarj2,chicutj2,chibgj2,chisig425j2,chisig500j2,chisig650j2,chisig850j2,1,"chi210/_add2j.txt");
    chiSBsig425j2 = SB(chisig425j2,chibgj2); chiSBsig500j2 = SB(chisig500j2,chibgj2); chiSBsig650j2 = SB(chisig650j2,chibgj2); chiSBsig850j2 = SB(chisig850j2,chibgj2);
    chiSsBsig425j2 = SsB(chisig425j2,chibgj2); chiSsBsig500j2 = SsB(chisig500j2,chibgj2); chiSsBsig650j2 = SsB(chisig650j2,chibgj2); chiSsBsig850j2 = SsB(chisig850j2,chibgj2);
    chiFoMsig425j2 = FOM(chisig425j2,chibgj2); chiFoMsig500j2 = FOM(chisig500j2,chibgj2); chiFoMsig650j2 = FOM(chisig650j2,chibgj2); chiFoMsig850j2 = FOM(chisig850j2,chibgj2);
    chiZsig425j2 = ZBi(chisig425j2,chibgj2); chiZsig500j2 = ZBi(chisig500j2,chibgj2); chiZsig650j2 = ZBi(chisig650j2,chibgj2); chiZsig850j2 = ZBi(chisig850j2,chibgj2);
    //load(ds,d1,d2,chiSBsig425j2,chiSBsig500j2,chiSBsig650j2,chiSBsig850j2,2,"chi210/_add2j.txt");
    //load(ds,d1,d2,chiSsBsig425j2,chiSsBsig500j2,chiSsBsig650j2,chiSsBsig850j2,3,"chi210/_add2j.txt");
    //load(ds,d1,d2,chiFoMsig425j2,chiFoMsig500j2,chiFoMsig650j2,chiFoMsig850j2,4,"chi210/_add2j.txt");
    //load(ds,d1,d2,chiZsig425j2,chiZsig500j2,chiZsig650j2,chiZsig850j2,5,"chi210/_add2j.txt");
    
    load(MTWvarj2,MTWcutj2,MTWbgj2,MTWsig425j2,MTWsig500j2,MTWsig650j2,MTWsig850j2,1,"MT2W200/_add2j.txt");
    MTWSBsig425j2 = SB(MTWsig425j2,MTWbgj2); MTWSBsig500j2 = SB(MTWsig500j2,MTWbgj2); MTWSBsig650j2 = SB(MTWsig650j2,MTWbgj2); MTWSBsig850j2 = SB(MTWsig850j2,MTWbgj2);
    MTWSsBsig425j2 = SsB(MTWsig425j2,MTWbgj2); MTWSsBsig500j2 = SsB(MTWsig500j2,MTWbgj2); MTWSsBsig650j2 = SsB(MTWsig650j2,MTWbgj2); MTWSsBsig850j2 = SsB(MTWsig850j2,MTWbgj2);
    MTWFoMsig425j2 = FOM(MTWsig425j2,MTWbgj2); MTWFoMsig500j2 = FOM(MTWsig500j2,MTWbgj2); MTWFoMsig650j2 = FOM(MTWsig650j2,MTWbgj2); MTWFoMsig850j2 = FOM(MTWsig850j2,MTWbgj2);
    MTWZsig425j2 = ZBi(MTWsig425j2,MTWbgj2); MTWZsig500j2 = ZBi(MTWsig500j2,MTWbgj2); MTWZsig650j2 = ZBi(MTWsig650j2,MTWbgj2); MTWZsig850j2 = ZBi(MTWsig850j2,MTWbgj2);
    //load(ds,d1,d2,MTWSBsig425j2,MTWSBsig500j2,MTWSBsig650j2,MTWSBsig850j2,2,"MT2W200/_add2j.txt");
    //load(ds,d1,d2,MTWSsBsig425j2,MTWSsBsig500j2,MTWSsBsig650j2,MTWSsBsig850j2,3,"MT2W200/_add2j.txt");
    //load(ds,d1,d2,MTWFoMsig425j2,MTWFoMsig500j2,MTWFoMsig650j2,MTWFoMsig850j2,4,"MT2W200/_add2j.txt");
    //load(ds,d1,d2,MTWZsig425j2,MTWZsig500j2,MTWZsig650j2,MTWZsig850j2,5,"MT2W200/_add2j.txt");
    
    if(version==1){
        Xvarj2 = varj2; Xcutj2 = cutj2; Xbgj2 = bgj2; Xsig425j2 = sig425j2; Xsig500j2 = sig500j2; Xsig650j2 = sig650j2; Xsig850j2 = sig850j2;
        XSBsig425j2 = SBsig425j2; XSBsig500j2 = SBsig500j2; XSBsig650j2 = SBsig650j2; XSBsig850j2 = SBsig850j2; XSsBsig425j2 = SsBsig425j2; XSsBsig500j2 = SsBsig500j2; XSsBsig650j2 = SsBsig650j2; XSsBsig850j2 = SsBsig850j2;
        XFoMsig425j2 = FoMsig425j2; XFoMsig500j2 = FoMsig500j2; XFoMsig650j2 = FoMsig650j2; XFoMsig850j2 = FoMsig850j2; XZsig425j2 = Zsig425j2; XZsig500j2 = Zsig500j2; XZsig650j2 = Zsig650j2; XZsig850j2 = Zsig850j2;
    }if(version==2){
        Xvarj2 = METvarj2; Xcutj2 = METcutj2; Xbgj2 = METbgj2; Xsig425j2 = METsig425j2; Xsig500j2 = METsig500j2; Xsig650j2 = METsig650j2; Xsig850j2 = METsig850j2;
        XSBsig425j2 = METSBsig425j2; XSBsig500j2 = METSBsig500j2; XSBsig650j2 = METSBsig650j2; XSBsig850j2 = METSBsig850j2; XSsBsig425j2 = METSsBsig425j2; XSsBsig500j2 = METSsBsig500j2; XSsBsig650j2 = METSsBsig650j2; XSsBsig850j2 = METSsBsig850j2;
        XFoMsig425j2 = METFoMsig425j2; XFoMsig500j2 = METFoMsig500j2; XFoMsig650j2 = METFoMsig650j2; XFoMsig850j2 = METFoMsig850j2; XZsig425j2 = METZsig425j2; XZsig500j2 = METZsig500j2; XZsig650j2 = METZsig650j2; XZsig850j2 = METZsig850j2;
    }if(version==3){
        Xvarj2 = chivarj2; Xcutj2 = chicutj2; Xbgj2 = chibgj2; Xsig425j2 = chisig425j2; Xsig500j2 = chisig500j2; Xsig650j2 = chisig650j2; Xsig850j2 = chisig850j2;
        XSBsig425j2 = chiSBsig425j2; XSBsig500j2 = chiSBsig500j2; XSBsig650j2 = chiSBsig650j2; XSBsig850j2 = chiSBsig850j2; XSsBsig425j2 = chiSsBsig425j2; XSsBsig500j2 = chiSsBsig500j2; XSsBsig650j2 = chiSsBsig650j2; XSsBsig850j2 = chiSsBsig850j2;
        XFoMsig425j2 = chiFoMsig425j2; XFoMsig500j2 = chiFoMsig500j2; XFoMsig650j2 = chiFoMsig650j2; XFoMsig850j2 = chiFoMsig850j2; XZsig425j2 = chiZsig425j2; XZsig500j2 = chiZsig500j2; XZsig650j2 = chiZsig650j2; XZsig850j2 = chiZsig850j2;
    }if(version==4){
        Xvarj2 = MTWvarj2; Xcutj2 = MTWcutj2; Xbgj2 = MTWbgj2; Xsig425j2 = MTWsig425j2; Xsig500j2 = MTWsig500j2; Xsig650j2 = MTWsig650j2; Xsig850j2 = MTWsig850j2;
        XSBsig425j2 = MTWSBsig425j2; XSBsig500j2 = MTWSBsig500j2; XSBsig650j2 = MTWSBsig650j2; XSBsig850j2 = MTWSBsig850j2; XSsBsig425j2 = MTWSsBsig425j2; XSsBsig500j2 = MTWSsBsig500j2; XSsBsig650j2 = MTWSsBsig650j2; XSsBsig850j2 = MTWSsBsig850j2;
        XFoMsig425j2 = MTWFoMsig425j2; XFoMsig500j2 = MTWFoMsig500j2; XFoMsig650j2 = MTWFoMsig650j2; XFoMsig850j2 = MTWFoMsig850j2; XZsig425j2 = MTWZsig425j2; XZsig500j2 = MTWZsig500j2; XZsig650j2 = MTWZsig650j2; XZsig850j2 = MTWZsig850j2;
    }
    
    vector<TString> Xvarj1;     vector<TString> varj1;     vector<TString> METvarj1;     vector<TString> chivarj1;     vector<TString> MTWvarj1;
    vector<float> Xcutj1;       vector<float> cutj1;       vector<float> METcutj1;       vector<float> chicutj1;       vector<float> MTWcutj1;
    vector<float> Xbgj1;        vector<float> bgj1;        vector<float> METbgj1;        vector<float> chibgj1;        vector<float> MTWbgj1;
    vector<float> Xsig425j1;    vector<float> sig425j1;    vector<float> METsig425j1;    vector<float> chisig425j1;    vector<float> MTWsig425j1;
    vector<float> Xsig500j1;    vector<float> sig500j1;    vector<float> METsig500j1;    vector<float> chisig500j1;    vector<float> MTWsig500j1;
    vector<float> Xsig650j1;    vector<float> sig650j1;    vector<float> METsig650j1;    vector<float> chisig650j1;    vector<float> MTWsig650j1;
    vector<float> Xsig850j1;    vector<float> sig850j1;    vector<float> METsig850j1;    vector<float> chisig850j1;    vector<float> MTWsig850j1;
    vector<float> XSBsig425j1;  vector<float> SBsig425j1;  vector<float> METSBsig425j1;  vector<float> chiSBsig425j1;  vector<float> MTWSBsig425j1;
    vector<float> XSBsig500j1;  vector<float> SBsig500j1;  vector<float> METSBsig500j1;  vector<float> chiSBsig500j1;  vector<float> MTWSBsig500j1;
    vector<float> XSBsig650j1;  vector<float> SBsig650j1;  vector<float> METSBsig650j1;  vector<float> chiSBsig650j1;  vector<float> MTWSBsig650j1;
    vector<float> XSBsig850j1;  vector<float> SBsig850j1;  vector<float> METSBsig850j1;  vector<float> chiSBsig850j1;  vector<float> MTWSBsig850j1;
    vector<float> XSsBsig425j1; vector<float> SsBsig425j1; vector<float> METSsBsig425j1; vector<float> chiSsBsig425j1; vector<float> MTWSsBsig425j1;
    vector<float> XSsBsig500j1; vector<float> SsBsig500j1; vector<float> METSsBsig500j1; vector<float> chiSsBsig500j1; vector<float> MTWSsBsig500j1;
    vector<float> XSsBsig650j1; vector<float> SsBsig650j1; vector<float> METSsBsig650j1; vector<float> chiSsBsig650j1; vector<float> MTWSsBsig650j1;
    vector<float> XSsBsig850j1; vector<float> SsBsig850j1; vector<float> METSsBsig850j1; vector<float> chiSsBsig850j1; vector<float> MTWSsBsig850j1;
    vector<float> XFoMsig425j1; vector<float> FoMsig425j1; vector<float> METFoMsig425j1; vector<float> chiFoMsig425j1; vector<float> MTWFoMsig425j1;
    vector<float> XFoMsig500j1; vector<float> FoMsig500j1; vector<float> METFoMsig500j1; vector<float> chiFoMsig500j1; vector<float> MTWFoMsig500j1;
    vector<float> XFoMsig650j1; vector<float> FoMsig650j1; vector<float> METFoMsig650j1; vector<float> chiFoMsig650j1; vector<float> MTWFoMsig650j1;
    vector<float> XFoMsig850j1; vector<float> FoMsig850j1; vector<float> METFoMsig850j1; vector<float> chiFoMsig850j1; vector<float> MTWFoMsig850j1;
    vector<float> XZsig425j1;   vector<float> Zsig425j1;   vector<float> METZsig425j1;   vector<float> chiZsig425j1;   vector<float> MTWZsig425j1;
    vector<float> XZsig500j1;   vector<float> Zsig500j1;   vector<float> METZsig500j1;   vector<float> chiZsig500j1;   vector<float> MTWZsig500j1;
    vector<float> XZsig650j1;   vector<float> Zsig650j1;   vector<float> METZsig650j1;   vector<float> chiZsig650j1;   vector<float> MTWZsig650j1;
    vector<float> XZsig850j1;   vector<float> Zsig850j1;   vector<float> METZsig850j1;   vector<float> chiZsig850j1;   vector<float> MTWZsig850j1;
    
    load(varj1,cutj1,bgj1,sig425j1,sig500j1,sig650j1,sig850j1,1,"_add1j.txt");
    SBsig425j1 = SB(sig425j1,bgj1); SBsig500j1 = SB(sig500j1,bgj1); SBsig650j1 = SB(sig650j1,bgj1); SBsig850j1 = SB(sig850j1,bgj1);
    SsBsig425j1 = SsB(sig425j1,bgj1); SsBsig500j1 = SsB(sig500j1,bgj1); SsBsig650j1 = SsB(sig650j1,bgj1); SsBsig850j1 = SsB(sig850j1,bgj1);
    FoMsig425j1 = FOM(sig425j1,bgj1); FoMsig500j1 = FOM(sig500j1,bgj1); FoMsig650j1 = FOM(sig650j1,bgj1); FoMsig850j1 = FOM(sig850j1,bgj1);
    Zsig425j1 = ZBi(sig425j1,bgj1); Zsig500j1 = ZBi(sig500j1,bgj1); Zsig650j1 = ZBi(sig650j1,bgj1); Zsig850j1 = ZBi(sig850j1,bgj1);
    //load(ds,d1,d2,SBsig425j1,SBsig500j1,SBsig650j1,SBsig850j1,2,"_add1j.txt");
    //load(ds,d1,d2,SsBsig425j1,SsBsig500j1,SsBsig650j1,SsBsig850j1,3,"_add1j.txt");
    //load(ds,d1,d2,FoMsig425j1,FoMsig500j1,FoMsig650j1,FoMsig850j1,4,"_add1j.txt");
    //load(ds,d1,d2,Zsig425j1,Zsig500j1,Zsig650j1,Zsig850j1,5,"_add1j.txt");
    
    load(METvarj1,METcutj1,METbgj1,METsig425j1,METsig500j1,METsig650j1,METsig850j1,1,"MET300/_add1j.txt");
    METSBsig425j1 = SB(METsig425j1,METbgj1); METSBsig500j1 = SB(METsig500j1,METbgj1); METSBsig650j1 = SB(METsig650j1,METbgj1); METSBsig850j1 = SB(METsig850j1,METbgj1);
    METSsBsig425j1 = SsB(METsig425j1,METbgj1); METSsBsig500j1 = SsB(METsig500j1,METbgj1); METSsBsig650j1 = SsB(METsig650j1,METbgj1); METSsBsig850j1 = SsB(METsig850j1,METbgj1);
    METFoMsig425j1 = FOM(METsig425j1,METbgj1); METFoMsig500j1 = FOM(METsig500j1,METbgj1); METFoMsig650j1 = FOM(METsig650j1,METbgj1); METFoMsig850j1 = FOM(METsig850j1,METbgj1);
    METZsig425j1 = ZBi(METsig425j1,METbgj1); METZsig500j1 = ZBi(METsig500j1,METbgj1); METZsig650j1 = ZBi(METsig650j1,METbgj1); METZsig850j1 = ZBi(METsig850j1,METbgj1);
    //load(ds,d1,d2,METSBsig425j1,METSBsig500j1,METSBsig650j1,METSBsig850j1,2,"MET300/_add1j.txt");
    //load(ds,d1,d2,METSsBsig425j1,METSsBsig500j1,METSsBsig650j1,METSsBsig850j1,3,"MET300/_add1j.txt");
    //load(ds,d1,d2,METFoMsig425j1,METFoMsig500j1,METFoMsig650j1,METFoMsig850j1,4,"MET300/_add1j.txt");
    //load(ds,d1,d2,METZsig425j1,METZsig500j1,METZsig650j1,METZsig850j1,5,"MET300/_add1j.txt");
    
    load(chivarj1,chicutj1,chibgj1,chisig425j1,chisig500j1,chisig650j1,chisig850j1,1,"chi210/_add1j.txt");
    chiSBsig425j1 = SB(chisig425j1,chibgj1); chiSBsig500j1 = SB(chisig500j1,chibgj1); chiSBsig650j1 = SB(chisig650j1,chibgj1); chiSBsig850j1 = SB(chisig850j1,chibgj1);
    chiSsBsig425j1 = SsB(chisig425j1,chibgj1); chiSsBsig500j1 = SsB(chisig500j1,chibgj1); chiSsBsig650j1 = SsB(chisig650j1,chibgj1); chiSsBsig850j1 = SsB(chisig850j1,chibgj1);
    chiFoMsig425j1 = FOM(chisig425j1,chibgj1); chiFoMsig500j1 = FOM(chisig500j1,chibgj1); chiFoMsig650j1 = FOM(chisig650j1,chibgj1); chiFoMsig850j1 = FOM(chisig850j1,chibgj1);
    chiZsig425j1 = ZBi(chisig425j1,chibgj1); chiZsig500j1 = ZBi(chisig500j1,chibgj1); chiZsig650j1 = ZBi(chisig650j1,chibgj1); chiZsig850j1 = ZBi(chisig850j1,chibgj1);
    //load(ds,d1,d2,chiSBsig425j1,chiSBsig500j1,chiSBsig650j1,chiSBsig850j1,2,"chi210/_add1j.txt");
    //load(ds,d1,d2,chiSsBsig425j1,chiSsBsig500j1,chiSsBsig650j1,chiSsBsig850j1,3,"chi210/_add1j.txt");
    //load(ds,d1,d2,chiFoMsig425j1,chiFoMsig500j1,chiFoMsig650j1,chiFoMsig850j1,4,"chi210/_add1j.txt");
    //load(ds,d1,d2,chiZsig425j1,chiZsig500j1,chiZsig650j1,chiZsig850j1,5,"chi210/_add1j.txt");
    
    load(MTWvarj1,MTWcutj1,MTWbgj1,MTWsig425j1,MTWsig500j1,MTWsig650j1,MTWsig850j1,1,"MT2W200/_add1j.txt");
    MTWSBsig425j1 = SB(MTWsig425j1,MTWbgj1); MTWSBsig500j1 = SB(MTWsig500j1,MTWbgj1); MTWSBsig650j1 = SB(MTWsig650j1,MTWbgj1); MTWSBsig850j1 = SB(MTWsig850j1,MTWbgj1);
    MTWSsBsig425j1 = SsB(MTWsig425j1,MTWbgj1); MTWSsBsig500j1 = SsB(MTWsig500j1,MTWbgj1); MTWSsBsig650j1 = SsB(MTWsig650j1,MTWbgj1); MTWSsBsig850j1 = SsB(MTWsig850j1,MTWbgj1);
    MTWFoMsig425j1 = FOM(MTWsig425j1,MTWbgj1); MTWFoMsig500j1 = FOM(MTWsig500j1,MTWbgj1); MTWFoMsig650j1 = FOM(MTWsig650j1,MTWbgj1); MTWFoMsig850j1 = FOM(MTWsig850j1,MTWbgj1);
    MTWZsig425j1 = ZBi(MTWsig425j1,MTWbgj1); MTWZsig500j1 = ZBi(MTWsig500j1,MTWbgj1); MTWZsig650j1 = ZBi(MTWsig650j1,MTWbgj1); MTWZsig850j1 = ZBi(MTWsig850j1,MTWbgj1);
    //load(ds,d1,d2,MTWSBsig425j1,MTWSBsig500j1,MTWSBsig650j1,MTWSBsig850j1,2,"MT2W200/_add1j.txt");
    //load(ds,d1,d2,MTWSsBsig425j1,MTWSsBsig500j1,MTWSsBsig650j1,MTWSsBsig850j1,3,"MT2W200/_add1j.txt");
    //load(ds,d1,d2,MTWFoMsig425j1,MTWFoMsig500j1,MTWFoMsig650j1,MTWFoMsig850j1,4,"MT2W200/_add1j.txt");
    //load(ds,d1,d2,MTWZsig425j1,MTWZsig500j1,MTWZsig650j1,MTWZsig850j1,5,"MT2W200/_add1j.txt");
    
    if(version==1){
        Xvarj1 = varj1; Xcutj1 = cutj1; Xbgj1 = bgj1; Xsig425j1 = sig425j1; Xsig500j1 = sig500j1; Xsig650j1 = sig650j1; Xsig850j1 = sig850j1;
        XSBsig425j1 = SBsig425j1; XSBsig500j1 = SBsig500j1; XSBsig650j1 = SBsig650j1; XSBsig850j1 = SBsig850j1; XSsBsig425j1 = SsBsig425j1; XSsBsig500j1 = SsBsig500j1; XSsBsig650j1 = SsBsig650j1; XSsBsig850j1 = SsBsig850j1;
        XFoMsig425j1 = FoMsig425j1; XFoMsig500j1 = FoMsig500j1; XFoMsig650j1 = FoMsig650j1; XFoMsig850j1 = FoMsig850j1; XZsig425j1 = Zsig425j1; XZsig500j1 = Zsig500j1; XZsig650j1 = Zsig650j1; XZsig850j1 = Zsig850j1;
    }if(version==2){
        Xvarj1 = METvarj1; Xcutj1 = METcutj1; Xbgj1 = METbgj1; Xsig425j1 = METsig425j1; Xsig500j1 = METsig500j1; Xsig650j1 = METsig650j1; Xsig850j1 = METsig850j1;
        XSBsig425j1 = METSBsig425j1; XSBsig500j1 = METSBsig500j1; XSBsig650j1 = METSBsig650j1; XSBsig850j1 = METSBsig850j1; XSsBsig425j1 = METSsBsig425j1; XSsBsig500j1 = METSsBsig500j1; XSsBsig650j1 = METSsBsig650j1; XSsBsig850j1 = METSsBsig850j1;
        XFoMsig425j1 = METFoMsig425j1; XFoMsig500j1 = METFoMsig500j1; XFoMsig650j1 = METFoMsig650j1; XFoMsig850j1 = METFoMsig850j1; XZsig425j1 = METZsig425j1; XZsig500j1 = METZsig500j1; XZsig650j1 = METZsig650j1; XZsig850j1 = METZsig850j1;
    }if(version==3){
        Xvarj1 = chivarj1; Xcutj1 = chicutj1; Xbgj1 = chibgj1; Xsig425j1 = chisig425j1; Xsig500j1 = chisig500j1; Xsig650j1 = chisig650j1; Xsig850j1 = chisig850j1;
        XSBsig425j1 = chiSBsig425j1; XSBsig500j1 = chiSBsig500j1; XSBsig650j1 = chiSBsig650j1; XSBsig850j1 = chiSBsig850j1; XSsBsig425j1 = chiSsBsig425j1; XSsBsig500j1 = chiSsBsig500j1; XSsBsig650j1 = chiSsBsig650j1; XSsBsig850j1 = chiSsBsig850j1;
        XFoMsig425j1 = chiFoMsig425j1; XFoMsig500j1 = chiFoMsig500j1; XFoMsig650j1 = chiFoMsig650j1; XFoMsig850j1 = chiFoMsig850j1; XZsig425j1 = chiZsig425j1; XZsig500j1 = chiZsig500j1; XZsig650j1 = chiZsig650j1; XZsig850j1 = chiZsig850j1;
    }if(version==4){
        Xvarj1 = MTWvarj1; Xcutj1 = MTWcutj1; Xbgj1 = MTWbgj1; Xsig425j1 = MTWsig425j1; Xsig500j1 = MTWsig500j1; Xsig650j1 = MTWsig650j1; Xsig850j1 = MTWsig850j1;
        XSBsig425j1 = MTWSBsig425j1; XSBsig500j1 = MTWSBsig500j1; XSBsig650j1 = MTWSBsig650j1; XSBsig850j1 = MTWSBsig850j1; XSsBsig425j1 = MTWSsBsig425j1; XSsBsig500j1 = MTWSsBsig500j1; XSsBsig650j1 = MTWSsBsig650j1; XSsBsig850j1 = MTWSsBsig850j1;
        XFoMsig425j1 = MTWFoMsig425j1; XFoMsig500j1 = MTWFoMsig500j1; XFoMsig650j1 = MTWFoMsig650j1; XFoMsig850j1 = MTWFoMsig850j1; XZsig425j1 = MTWZsig425j1; XZsig500j1 = MTWZsig500j1; XZsig650j1 = MTWZsig650j1; XZsig850j1 = MTWZsig850j1;
    }
    
    
    
    if(cutflow){
        
        cout << "cuts cutflow" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << cutb2[j] << " & " << METcutb2[j] << " & " << chicutb2[j] << " & " << MTWcutb2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << bgb2[j] << " & " << METbgb2[j] << " & " << chibgb2[j] << " & " << MTWbgb2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << sig425b2[j] << " & " << METsig425b2[j] << " & " << chisig425b2[j] << " & " << MTWsig425b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << sig500b2[j] << " & " << METsig500b2[j] << " & " << chisig500b2[j] << " & " << MTWsig500b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << sig650b2[j] << " & " << METsig650b2[j] << " & " << chisig650b2[j] << " & " << MTWsig650b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << sig850b2[j] << " & " << METsig850b2[j] << " & " << chisig850b2[j] << " & " << MTWsig850b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SBsig425b2[j] << " & " << METSBsig425b2[j] << " & " << chiSBsig425b2[j] << " & " << MTWSBsig425b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SBsig500b2[j] << " & " << METSBsig500b2[j] << " & " << chiSBsig500b2[j] << " & " << MTWSBsig500b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SBsig650b2[j] << " & " << METSBsig650b2[j] << " & " << chiSBsig650b2[j] << " & " << MTWSBsig650b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SBsig850b2[j] << " & " << METSBsig850b2[j] << " & " << chiSBsig850b2[j] << " & " << MTWSBsig850b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SsBsig425b2[j] << " & " << METSsBsig425b2[j] << " & " << chiSsBsig425b2[j] << " & " << MTWSsBsig425b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SsBsig500b2[j] << " & " << METSsBsig500b2[j] << " & " << chiSsBsig500b2[j] << " & " << MTWSsBsig500b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SsBsig650b2[j] << " & " << METSsBsig650b2[j] << " & " << chiSsBsig650b2[j] << " & " << MTWSsBsig650b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << SsBsig850b2[j] << " & " << METSsBsig850b2[j] << " & " << chiSsBsig850b2[j] << " & " << MTWSsBsig850b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << FoMsig425b2[j] << " & " << METFoMsig425b2[j] << " & " << chiFoMsig425b2[j] << " & " << MTWFoMsig425b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << FoMsig500b2[j] << " & " << METFoMsig500b2[j] << " & " << chiFoMsig500b2[j] << " & " << MTWFoMsig500b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << FoMsig650b2[j] << " & " << METFoMsig650b2[j] << " & " << chiFoMsig650b2[j] << " & " << MTWFoMsig650b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << FoMsig850b2[j] << " & " << METFoMsig850b2[j] << " & " << chiFoMsig850b2[j] << " & " << MTWFoMsig850b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << Zsig425b2[j] << " & " << METZsig425b2[j] << " & " << chiZsig425b2[j] << " & " << MTWZsig425b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << Zsig500b2[j] << " & " << METZsig500b2[j] << " & " << chiZsig500b2[j] << " & " << MTWZsig500b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << Zsig650b2[j] << " & " << METZsig650b2[j] << " & " << chiZsig650b2[j] << " & " << MTWZsig650b2[j] << "\\\\" << endl;
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
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & preselection & $\\mathrm{E}_\\mathrm{T}^\\mathrm{miss} > 300$ GeV & $\\chi^2 < 10$ & $\\mathrm{M}_\\mathrm{T2}^\\mathrm{W} > 200$ GeV \\\\" << endl;
        for(unsigned int j = 0; j<varb2.size(); ++j){
            cout << " " << varb2[j] << fixed << setprecision(2) << " & " << Zsig850b2[j] << " & " << METZsig850b2[j] << " & " << chiZsig850b2[j] << " & " << MTWZsig850b2[j] << "\\\\" << endl;
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
        
        cout << "cuts jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xcutb1[j] << " & " << Xcutb2[j] << " & " << Xcutj1[j] << " & " << Xcutj2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "bg yield jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xbgb1[j] << " & " << Xbgb2[j] << " & " << Xbgj1[j] << " & " << Xbgj2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig425 yield jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xsig425b1[j] << " & " << Xsig425b2[j] << " & " << Xsig425j1[j] << " & " << Xsig425j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 yield jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xsig500b1[j] << " & " << Xsig500b2[j] << " & " << Xsig500j1[j] << " & " << Xsig500j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 yield jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xsig650b1[j] << " & " << Xsig650b2[j] << " & " << Xsig650j1[j] << " & " << Xsig650j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 yield jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << Xsig850b1[j] << " & " << Xsig850b2[j] << " & " << Xsig850j1[j] << " & " << Xsig850j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 S/B jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSBsig425b1[j] << " & " << XSBsig425b2[j] << " & " << XSBsig425j1[j] << " & " << XSBsig425j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 S/B jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSBsig500b1[j] << " & " << XSBsig500b2[j] << " & " << XSBsig500j1[j] << " & " << XSBsig500j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 S/B jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSBsig650b1[j] << " & " << XSBsig650b2[j] << " & " << XSBsig650j1[j] << " & " << XSBsig650j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 S/B jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSBsig850b1[j] << " & " << XSBsig850b2[j] << " & " << XSBsig850j1[j] << " & " << XSBsig850j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 S/sqrt(B) jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSsBsig425b1[j] << " & " << XSsBsig425b2[j] << " & " << XSsBsig425j1[j] << " & " << XSsBsig425j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 S/sqrt(B) jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSsBsig500b1[j] << " & " << XSsBsig500b2[j] << " & " << XSsBsig500j1[j] << " & " << XSsBsig500j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 S/sqrt(B) jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSsBsig650b1[j] << " & " << XSsBsig650b2[j] << " & " << XSsBsig650j1[j] << " & " << XSsBsig650j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 S/sqrt(B) jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XSsBsig850b1[j] << " & " << XSsBsig850b2[j] << " & " << XSsBsig850j1[j] << " & " << XSsBsig850j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 FoM jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XFoMsig425b1[j] << " & " << XFoMsig425b2[j] << " & " << XFoMsig425j1[j] << " & " << XFoMsig425j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 FoM jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XFoMsig500b1[j] << " & " << XFoMsig500b2[j] << " & " << XFoMsig500j1[j] << " & " << XFoMsig500j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 FoM jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XFoMsig650b1[j] << " & " << XFoMsig650b2[j] << " & " << XFoMsig650j1[j] << " & " << XFoMsig650j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 FoM jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XFoMsig850b1[j] << " & " << XFoMsig850b2[j] << " & " << XFoMsig850j1[j] << " & " << XFoMsig850j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        
        cout << "sig425 Zbi jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XZsig425b1[j] << " & " << XZsig425b2[j] << " & " << XZsig425j1[j] << " & " << XZsig425j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig500 Zbi jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XZsig500b1[j] << " & " << XZsig500b2[j] << " & " << XZsig500j1[j] << " & " << XZsig500j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig650 Zbi jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XZsig650b1[j] << " & " << XZsig650b2[j] << " & " << XZsig650j1[j] << " & " << XZsig650j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
        cout << "sig850 Zbi jetinput" << endl;
        cout << "\\begin{table}"             << endl
        << "\\begin{center}"            << endl
        << "\\small"                    << endl;
       	cout << "\\begin{tabular}{|l|cccc|}" << endl;
        cout << "\\hline\\hline"             << endl;
        cout << " Variable & add1CSV & add2CSV & add1PT & add2PT \\\\" << endl;
        for(unsigned int j = 0; j<Xvarb2.size(); ++j){
            cout << " " << Xvarb2[j] << fixed << setprecision(2) << " & " << XZsig850b1[j] << " & " << XZsig850b2[j] << " & " << XZsig850j1[j] << " & " << XZsig850j2[j] << "\\\\" << endl;
        }
        cout << "\\hline\\hline" << endl
        << "\\end{tabular}"     << endl
        << "\\end{center}"     << endl
        << "\\end{table}"      << endl
        << endl;
        
    }

}