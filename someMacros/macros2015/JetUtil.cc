#include "JetUtil.h"


namespace JetUtil
{

  double round(double input, int digits){
    /*double multiplier = 1.;
      for(unsigned int i = 0; i<digits) multiplier *=10.;
      double output = input * multiplier;
      return round(output)/multiplier;*/
    return ceil( ( input * pow( 10,digits ) ) - 0.5 ) / pow( 10,digits );
  }
  
  //compare two Math::LorentzVector
  //if false the two vectors are not the same (caution when using newly calculated objects due to machine precision)
  //allow for 10 MeV roundings
  bool CompareLV(LorentzVector lv1, LorentzVector lv2){
    if(TMath::Abs(lv1.Px()-lv2.Px())>0.01) return false;
    if(TMath::Abs(lv1.Py()-lv2.Py())>0.01) return false;
    if(TMath::Abs(lv1.Pz()-lv2.Pz())>0.01) return false;
    if(TMath::Abs(lv1.E() -lv2.E() )>0.01) return false;
    return true;
  }

  //helper function for DeltaPhi, using two phi's
  float DeltaPhi(float phi1, float phi2){
    // From cmssw reco::deltaPhi()
    float result = phi1 - phi2;
    while( result >   TMath::Pi() ) result -= TMath::TwoPi();
    while( result <= -TMath::Pi() ) result += TMath::TwoPi();
    return TMath::Abs(result);
  }

  //helper function for DeltaPhi, using two Math::LorentzVector's
  float deltaPhi(LorentzVector jet1, LorentzVector jet2){
    // From cmssw reco::deltaPhi()
    float result = jet1.Phi() - jet2.Phi();
    while( result >   TMath::Pi() ) result -= TMath::TwoPi();
    while( result <= -TMath::Pi() ) result += TMath::TwoPi();
    return TMath::Abs(result);
  }

  //helper function for DeltaR, using two phi's and eta's
  float DeltaR(float phi1, float phi2, float eta1, float eta2){
    // From cmssw reco::deltaPhi()
    float dphi = phi1 - phi2;
    while( dphi >   TMath::Pi() ) dphi -= TMath::TwoPi();
    while( dphi <= -TMath::Pi() ) dphi += TMath::TwoPi();
    return TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(eta1-eta2,2));
  }

  //helper function for DeltaR, using two Math::LorentzVector's
  float deltaR(LorentzVector jet1, LorentzVector jet2){
    // From cmssw reco::deltaPhi()
    float dphi = jet1.Phi() - jet2.Phi();
    while( dphi >   TMath::Pi() ) dphi -= TMath::TwoPi();
    while( dphi <= -TMath::Pi() ) dphi += TMath::TwoPi();
    return TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(jet1.Eta()-jet2.Eta(),2));
  }
  
  //function to get b-jets for topness or MT2 function - not used anymore
  //minbjets: if N(b-tagged jets) >= minbjets, don't search for additional jets (default = 2)
  //addnjets: if <=minbjets bjets found, have total of addnjets for bjet looper adding jets to bjet vector using addjets (default=2, recommended=2,3)
  //          if addnjets< N(jets), but minbjets>=N(jets), set addnjets = N(jets) in function
  //versionAddjets: ==1: according to highest b-tag discriminant, ==2: according to highest jet-pt (default=2)
  vector<LorentzVector > BJetSelector(vector<LorentzVector > jets, vector<float> btagvalues, float bjetdiscr, unsigned int minbjets, unsigned int minaddbjets, int versionAddjets){
    vector<LorentzVector > bjets; bjets.clear();
    if(jets.size()!=btagvalues.size())         return bjets;
    if(jets.size()<minbjets)                   return bjets;
    if(versionAddjets!=1 && versionAddjets!=2) return bjets;
    
    vector<int> b;
    vector<int>::iterator it;
    for(unsigned int n = 0; n<jets.size(); ++n){
      if(btagvalues.at(n)>bjetdiscr) bjets.push_back(jets.at(n) );
      it = b.begin(); bool inloop = false;
      for(unsigned int k = 0; k<b.size();++k){ 
	if(versionAddjets==1 && btagvalues.at(n)>btagvalues.at(b.at(k)) ) { b.insert(it+k,n); inloop = true; break;} 
	if(versionAddjets==2 && jets.at(n).Pt() >jets.at(b.at(k)).Pt()  ) { b.insert(it+k,n); inloop = true; break;}
      }
      if(inloop==false) b.push_back(n);
      
    }
    if(bjets.size()>=minbjets) return bjets;
    int n = -1;
    if(minaddbjets>jets.size() ) minaddbjets = jets.size();
    while(bjets.size()<minaddbjets){
      ++n;
      bool alreadyused = false;
      for(unsigned int k =0; k<bjets.size();++k){
	if(JetUtil::CompareLV(bjets.at(k),jets.at(b.at(n)) )==true) {alreadyused=true; break; }
      }
      if(!alreadyused) bjets.push_back(jets.at(b.at(n)) );
    }
    return bjets;
  }

  //sort vector 'jets' acording to 'btagvalues' - sorting done by hand - a smarter sorting could be implemented
  vector<int> JetIndexCSVsorted(vector<float> btagvalues, vector<LorentzVector > jets, vector<bool> jid, float minpt, float maxeta, bool passjid){

    vector<int> b;
    if(btagvalues.size()!=jets.size()) return b;
    if(btagvalues.size()!=jid.size())  return b;
    vector<int>::iterator it;
    for(unsigned int n = 0; n<jets.size(); ++n){
      if(jets.at(n).Pt()<minpt)               continue;
      if(TMath::Abs(jets.at(n).Eta())>maxeta) continue;
      if(passjid && jid.at(n)==false)         continue;
      it = b.begin(); bool inloop = false;
      for(unsigned int k = 0; k<b.size();++k){ 
	if(btagvalues.at(n)>btagvalues.at(b.at(k)) ) { b.insert(it+k,n); inloop = true; break;}
      }
      if(inloop==false) b.push_back(n);
    }
    return b;
  }

}//end namespace 
