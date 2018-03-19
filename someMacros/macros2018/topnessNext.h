#include "TFitter.h"
#include "TMath.h"
#include <vector>
#include "Math/LorentzVector.h"
#include <math.h>
#include "TLorentzVector.h"
#include "JetUtil.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std;

// comments, see .C file

float topnessMinimization(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, TLorentzVector met, TLorentzVector lep, TLorentzVector bjet1, TLorentzVector bjet2, int version=1, double aW=5, double aT=15, double aCM=1000);

double topnessFunction(double &CM, double &TM, double &WL, double &TL,
		       double pwx_, double pwy_, double pwz_, double pnz_,
                       double plx_, double ply_, double plz_, double ple_,
                       double pb1x_, double pb1y_, double pb1z_, double pb1e_,
                       double pb2x_, double pb2y_, double pb2z_, double pb2e_,
                       double pmx_, double pmy_, double pmz_, double pme_,
                       double aW_, double aT_, double aCM_);
double topnessFunctionX(double pwx_, double pwy_, double pwz_, double pnz_,
                       double plx_, double ply_, double plz_, double ple_,
                       double pb1x_, double pb1y_, double pb1z_, double pb1e_,
                       double pb2x_, double pb2y_, double pb2z_, double pb2e_,
                       double pmx_, double pmy_, double pmz_, double pme_,
			double aW_, double aT_, double aCM_){
  double x1,x2,x3,x4;
  return topnessFunction(x1,x2,x3,x4,
		        pwx_,  pwy_,  pwz_,  pnz_,
                        plx_,  ply_,  plz_,  ple_,
                        pb1x_,  pb1y_,  pb1z_,  pb1e_,
                        pb2x_,  pb2y_,  pb2z_,  pb2e_,
                        pmx_,  pmy_,  pmz_,  pme_,
                        aW_,  aT_,  aCM_);
}

void minuitFunctionWrapper(int& nDim, double* gout, double& result, double* par, int flg/*, double &CM, double &TM, double &WL, double &TL*/) {
  result = topnessFunctionX(
			   par[0],par[1],par[2],par[3],
                           par[4],par[5],par[6],par[7],
                           par[8],par[9],par[10],par[11],
                           par[12],par[13],par[14],par[15],
                           par[16],par[17],par[18],par[19],
                           par[20],par[21],par[22]
                           );
}

double topnessFunctionV1(double &CM, double &TM, double &WL, double &TL,
			 double pwx_, double pwy_, double pwz_, double pnz_,
			 double plx_, double ply_, double plz_, double ple_,
			 double pb1x_, double pb1y_, double pb1z_, double pb1e_,
			 double pb2x_, double pb2y_, double pb2z_, double pb2e_,
			 double pmx_, double pmy_, double pmz_, double pme_,
			 double aW_, double aT_, double aCM_);
double topnessFunctionV1X(double pwx_, double pwy_, double pwz_, double pnz_,
			 double plx_, double ply_, double plz_, double ple_,
			 double pb1x_, double pb1y_, double pb1z_, double pb1e_,
			 double pb2x_, double pb2y_, double pb2z_, double pb2e_,
			 double pmx_, double pmy_, double pmz_, double pme_,
			 double aW_, double aT_, double aCM_){
  double x1,x2,x3,x4;
  return topnessFunctionV1(x1,x2,x3,x4,
		        pwx_,  pwy_,  pwz_,  pnz_,
                        plx_,  ply_,  plz_,  ple_,
                        pb1x_,  pb1y_,  pb1z_,  pb1e_,
                        pb2x_,  pb2y_,  pb2z_,  pb2e_,
                        pmx_,  pmy_,  pmz_,  pme_,
                        aW_,  aT_,  aCM_);
}

void minuitFunctionWrapperV1(int& nDim, double* gout, double& result, double* par, int flg/*, double &CM, double &TM, double &WL, double &TL*/) {
  result = topnessFunctionV1X(/*CM,TM,WL,TL,*/
			     par[0],par[1],par[2],par[3],
			     par[4],par[5],par[6],par[7],
			     par[8],par[9],par[10],par[11],
			     par[12],par[13],par[14],par[15],
			     par[16],par[17],par[18],par[19],
			     par[20],par[21],par[22]
			     );
}


//float gettopness(TLorentzVector met, TLorentzVector lep, vector<TLorentzVector > bjets, int version=1);
//float Gettopness(LorentzVector met, LorentzVector lep, vector<LorentzVector > bjets, int version=1);
//float Gettopness_(float met, float metphi, LorentzVector lep, vector<LorentzVector> bjets, int version=1);

//float TopnessVersion(int version, LorentzVector MET, LorentzVector lep, vector<LorentzVector> jets, vector<float> jet_bdiscr, float btagdiscr=0.814, unsigned int addnjets=2, int addjets=2);
//float TopnessVersion_(int version, float met, float metphi, LorentzVector lep, vector<LorentzVector> jets, vector<float> jet_bdiscr, float btagdiscr=0.814, unsigned int addnjets=2, int addjets=2);

float CalcTopness(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, int version, LorentzVector MET,       LorentzVector lep, vector<LorentzVector> bjets,  vector<LorentzVector> addjets, double aW=5, double aT=15, double aCM=1000, bool forceb=false, bool dontforceb=false);
float CalcTopness_(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, int version, float MET, float METphi, LorentzVector lep, vector<LorentzVector> bjets,  vector<LorentzVector> addjets, double aW=5, double aT=15, double aCM=1000, bool forceb=false, bool dontforceb=false);
