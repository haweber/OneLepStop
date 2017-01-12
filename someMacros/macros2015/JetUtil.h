#ifndef JETUTIL_H
#define JETUTIL_H


#include "TMath.h"
#include <vector>
#include "Math/LorentzVector.h"
#include <math.h>

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std;

namespace JetUtil
{

  // comments, see .C
  double round(double input, int digits);
  bool   CompareLV(LorentzVector lv1, LorentzVector lv2);
  float  DeltaPhi(float phi1, float phi2);
  float  deltaPhi(LorentzVector jet1, LorentzVector jet2);
  float  DeltaR(float phi1, float phi2, float eta1, float eta2);
  float  deltaR(LorentzVector jet1, LorentzVector jet2);

  vector<LorentzVector> BJetSelector(vector<LorentzVector > jets, vector<float> btagvalues, float bjetdiscr=0.814, unsigned int minbjets=2, unsigned int minaddbjets=2, int versionAddjets=2);
  vector<int>           JetIndexCSVsorted(vector<float> btagvalues, vector<LorentzVector > jets, vector<bool> jid, float minpt=30., float maxeta=2.5, bool passjid=true);

}//end namespace 

#endif
