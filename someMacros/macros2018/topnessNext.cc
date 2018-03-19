#include "topnessNext.h"

//version 1: without 'reco top' and 'CM' term
//all other version: full topness (including 'reco W')
float topnessMinimization(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, TLorentzVector met, TLorentzVector lep, TLorentzVector bjet1, TLorentzVector bjet2, int version, double aW, double aT, double aCM) {

  cout.precision(11);
  TFitter *minimizer=new TFitter(4) ;
  double p1 = -1;
  minimizer->ExecuteCommand("SET PRINTOUT",&p1,1);
  if(version==1) minimizer->SetFCN(minuitFunctionWrapperV1);
  else minimizer->SetFCN(minuitFunctionWrapper);
  // get variables for Topness
  int mydigit = 3;
  double iLpx = JetUtil::round(lep.Px(),mydigit);
  double iLpy = JetUtil::round(lep.Py(),mydigit);
  double iLpz = JetUtil::round(lep.Pz(),mydigit);
  double iLpe = JetUtil::round(lep.E(),mydigit);
  double iB1px = JetUtil::round(bjet1.Px(),mydigit);
  double iB1py = JetUtil::round(bjet1.Py(),mydigit);
  double iB1pz = JetUtil::round(bjet1.Pz(),mydigit);
  double iB1pe = JetUtil::round(bjet1.E(),mydigit);
  double iB2px = JetUtil::round(bjet2.Px(),mydigit);
  double iB2py = JetUtil::round(bjet2.Py(),mydigit);
  double iB2pz = JetUtil::round(bjet2.Pz(),mydigit);
  double iB2pe = JetUtil::round(bjet2.E(),mydigit);
  double iMpx = JetUtil::round(met.Px(),mydigit);
  double iMpy = JetUtil::round(met.Py(),mydigit);
  double iMpz = JetUtil::round(met.Pz(),mydigit);
  double iMpe = JetUtil::round(met.E(),mydigit);

  // Define parameters [param number, param name, init val, estimated distance to min, bla, bla] // 300,3000,-3000,3000
  minimizer->SetParameter(0,"pwx",0,500,-3000,3000);
  minimizer->SetParameter(1,"pwy",0,500,-3000,3000);
  minimizer->SetParameter(2,"pwz",0,500,-3000,3000);
  minimizer->SetParameter(3,"pnz",0,500,-3000,3000);
  // fixed parameters
  minimizer->SetParameter(4,"plx",iLpx,0,iLpx-0.001,iLpx+0.001);
  minimizer->SetParameter(5,"ply",iLpy,0,iLpy-0.001,iLpy+0.001);
  minimizer->SetParameter(6,"plz",iLpz,0,iLpz-0.001,iLpz+0.001);
  minimizer->SetParameter(7,"ple",iLpe,0,iLpe-0.001,iLpe+0.001);
  minimizer->SetParameter(8,"pb1x",iB1px,0,iB1px-0.001,iB1px+0.001);
  minimizer->SetParameter(9,"pb1y",iB1py,0,iB1py-0.001,iB1py+0.001);
  minimizer->SetParameter(10,"pb1z",iB1pz,0,iB1pz-0.001,iB1pz+0.001);
  minimizer->SetParameter(11,"pb1e",iB1pe,0,iB1pe-0.001,iB1pe+0.001);
  minimizer->SetParameter(12,"pb2x",iB2px,0,iB2px-0.001,iB2px+0.001);
  minimizer->SetParameter(13,"pb2y",iB2py,0,iB2py-0.001,iB2py+0.001);
  minimizer->SetParameter(14,"pb2z",iB2pz,0,iB2pz-0.001,iB2pz+0.001);
  minimizer->SetParameter(15,"pb2e",iB2pe,0,iB2pe-0.001,iB2pe+0.001);
  minimizer->SetParameter(16,"pmx",iMpx,0,iMpx-0.001,iMpx+0.001);
  minimizer->SetParameter(17,"pmy",iMpy,0,iMpy-0.001,iMpy+0.001);
  minimizer->SetParameter(18,"pmz",iMpz,0,iMpz-0.001,iMpz+0.001);
  minimizer->SetParameter(19,"pme",iMpe,0,iMpe-0.001,iMpe+0.001);
  minimizer->SetParameter(20,"aW" ,aW,0,aW-0.001,aW+0.001);
  minimizer->SetParameter(21,"aT" ,aT,0,aT-0.001,aT+0.001);
  minimizer->SetParameter(22,"aCM",aCM,0,aCM-0.001,aCM+0.001);
  minimizer->FixParameter(4);
  minimizer->FixParameter(5);
  minimizer->FixParameter(6);
  minimizer->FixParameter(7);
  minimizer->FixParameter(8);
  minimizer->FixParameter(9);
  minimizer->FixParameter(10);
  minimizer->FixParameter(11);
  minimizer->FixParameter(12);
  minimizer->FixParameter(13);
  minimizer->FixParameter(14);
  minimizer->FixParameter(15);
  minimizer->FixParameter(16);
  minimizer->FixParameter(17);
  minimizer->FixParameter(18);
  minimizer->FixParameter(19);
  minimizer->FixParameter(20);
  minimizer->FixParameter(21);
  minimizer->FixParameter(22);
  // Run the simplex minimizer to get close to the minimum [no good precision, but robust]
  // For signal regions, no difference seen with migrad, but more stable
  minimizer->ExecuteCommand("SIMPLEX",0,0);
  //Get the best fit values
  double pwx_fit = minimizer->GetParameter(0);
  double pwy_fit = minimizer->GetParameter(1);
  double pwz_fit = minimizer->GetParameter(2);
  double pnz_fit = minimizer->GetParameter(3);
  pWz = pwz_fit;
  pnz = pnz_fit;
  pnx = met.Px() - pwx_fit;
  pny = met.Py() - pwy_fit;
  //cout << "output minimizer" << endl;
  //cout << "pwx " << pwx_fit << " pwy " << pwy_fit << " pwz " << pwz_fit << " pnz " << pnz_fit << endl;
  delete minimizer;
  // get the function value at best fit
  if(version==1){
    return log(topnessFunctionV1(CM, TM, WL, TL, 
				 pwx_fit,pwy_fit,pwz_fit,pnz_fit,
				 iLpx,iLpy,iLpz,iLpe,
				 iB1px,iB1py,iB1pz,iB1pe,
				 iB2px,iB2py,iB2pz,iB2pe,
				 iMpx,iMpy,iMpz,iMpe,
				 aW,aT,aCM
				 ));
  }
  else {
    return log(topnessFunction(CM, TM, WL, TL, 
			       pwx_fit,pwy_fit,pwz_fit,pnz_fit,
                               iLpx,iLpy,iLpz,iLpe,
                               iB1px,iB1py,iB1pz,iB1pe,
                               iB2px,iB2py,iB2pz,iB2pe,
                               iMpx,iMpy,iMpz,iMpe,
			       aW,aT,aCM
                               ));
  }
} // ~ end of Topness Minimization()

// full function
double topnessFunction(double &CM, double &TM, double &WL, double &TL, 
		       double pwx_, double pwy_, double pwz_, double pnz_,
                       double plx_, double ply_, double plz_, double ple_,
                       double pb1x_, double pb1y_, double pb1z_, double pb1e_,
                       double pb2x_, double pb2y_, double pb2z_, double pb2e_,
                       double pmx_, double pmy_, double pmz_, double pme_,
                       double aW_, double aT_, double aCM_) {
  const double mW = 81.;
  const double mT = 172.;
  const double aW = aW_;
  const double aT = aT_;
  const double aCM = aCM_;
    
  // construct the lorentz vectors
  TLorentzVector vW; vW.SetPxPyPzE(pwx_,pwy_,pwz_,(sqrt((mW*mW)+(pwx_*pwx_)+(pwy_*pwy_)+(pwz_*pwz_)))) ;
  TLorentzVector vL; vL.SetPxPyPzE(plx_,ply_,plz_,ple_);
  TLorentzVector vB1; vB1.SetPxPyPzE(pb1x_,pb1y_,pb1z_,pb1e_);
  TLorentzVector vB2; vB2.SetPxPyPzE(pb2x_,pb2y_,pb2z_,pb2e_);
  TLorentzVector vMET; vMET.SetPxPyPzE(pmx_,pmy_,pmz_,pme_);
  TLorentzVector vN; vN.SetPxPyPzE((pmx_-pwx_),(pmy_-pwy_),pnz_,(sqrt(pow((pmx_-pwx_),2)+pow((pmy_-pwy_),2)+pow(pnz_,2))));
  // construct the w-term (lost)
  //double tWM = ( pow( ((mW*mW) - (vW.M2())),2) ) / (pow(aW,4));//zero by construction
  // construct the w-term (lep)
  double tWL = ( pow( ((mW*mW) - ((vL+vN).M2())),2) ) / (pow(aW,4));
  // construct the tL-term [seen lepton]
  double tTL = ( pow( ((mT*mT) - ((vL+vB1+vN).M2())),2) ) / (pow(aT,4));
  // construct the tM-term [miss lepton]
  double tTM = ( pow( ((mT*mT) - ((vB2+vW).M2())),2) ) / (pow(aT,4));
  // construct the CM-term
  double tCM = ( pow( ((4*(mT*mT)) - ((vL+vN+vW+vB1+vB2).M2())),2) ) / (pow(aCM,4));
  CM = tCM; TM = tTM; TL = tTL; WL = tWL;
  // calculate Topness
  double Topness = tWL + tTL + tTM + tCM;
  return Topness;
}

//version 1: without 'reco top' and 'CM' term
double topnessFunctionV1(double &CM, double &TM, double &WL, double &TL,
			 double pwx_, double pwy_, double pwz_, double pnz_,
			 double plx_, double ply_, double plz_, double ple_,
			 double pb1x_, double pb1y_, double pb1z_, double pb1e_,
			 double pb2x_, double pb2y_, double pb2z_, double pb2e_,
			 double pmx_, double pmy_, double pmz_, double pme_,
			 double aW_, double aT_, double aCM_) {
  const double mW = 81.;
  const double mT = 172.;
  const double aW = aW_;
  const double aT = aT_;
  const double aCM = aCM_;
    
  // construct the lorentz vectors
  TLorentzVector vW; vW.SetPxPyPzE(pwx_,pwy_,pwz_,(sqrt((mW*mW)+(pwx_*pwx_)+(pwy_*pwy_)+(pwz_*pwz_)))) ;
  TLorentzVector vL; vL.SetPxPyPzE(plx_,ply_,plz_,ple_);
  TLorentzVector vB1; vB1.SetPxPyPzE(pb1x_,pb1y_,pb1z_,pb1e_);
  TLorentzVector vB2; vB2.SetPxPyPzE(pb2x_,pb2y_,pb2z_,pb2e_);
  TLorentzVector vMET; vMET.SetPxPyPzE(pmx_,pmy_,pmz_,pme_);
  TLorentzVector vN; vN.SetPxPyPzE((pmx_-pwx_),(pmy_-pwy_),pnz_,(sqrt(pow((pmx_-pwx_),2)+pow((pmy_-pwy_),2)+pow(pnz_,2))));
  // construct the w-term (lost)
  //double tWM = ( pow( ((mW*mW) - (vW.M2())),2) ) / (pow(aW,4));//zero by construction
  // construct the w-term (lep)
  double tWL = ( pow( ((mW*mW) - ((vL+vN).M2())),2) ) / (pow(aW,4));
  // construct the tL-term [seen lepton]
  double tTL = ( pow( ((mT*mT) - ((vL+vB1+vN).M2())),2) ) / (pow(aT,4));
  // construct the tM-term [miss lepton]
  double tTM = ( pow( ((mT*mT) - ((vB2+vW).M2())),2) ) / (pow(aT,4));
  // construct the CM-term
  double tCM = ( pow( ((4*(mT*mT)) - ((vL+vN+vW+vB1+vB2).M2())),2) ) / (pow(aCM,4));
  // calculate Topness
  CM = tCM; TM = tTM; TL = tTL; WL = tWL;
  double Topness = tWL + tTM;
  return Topness;
}

//wrapper function using TLorentzVector // deprecated
// double precision needed for minimization
/*float gettopness(TLorentzVector met, TLorentzVector lep, vector<TLorentzVector> bjets, int version){
  double topness = 9e9;
  if(bjets.size()<2) return -999.;
  for(unsigned int n = 0; n<bjets.size(); ++n){
    for(unsigned int m = 0; m<bjets.size(); ++m){
      if(n==m) continue;
      double tmptop = topnessMinimization(met,lep,bjets[n],bjets[m],version);
      if(tmptop<topness) topness = tmptop;
    }
  }
  return topness;
}*/

//wrapper function to get topness using b-tagged jets as input // deprecated
//helper function using Math::LorentzVector
/*float Gettopness(LorentzVector met, LorentzVector lep, vector<LorentzVector> bjets, int version){
  TLorentzVector metlv; metlv.SetPxPyPzE(met.Px(),met.Py(),met.Pz(),met.E());
  TLorentzVector leplv; leplv.SetPxPyPzE(lep.Px(),lep.Py(),lep.Pz(),lep.E());
  TLorentzVector temp(0.,0.,0.,0.); vector<TLorentzVector> jetslv;
  for(unsigned int i = 0; i<bjets.size(); ++i){
    temp.SetPxPyPzE(bjets[i].Px(),bjets[i].Py(),bjets[i].Pz(),bjets[i].E());
    jetslv.push_back(temp);
  }
  return gettopness(metlv,leplv,jetslv,version);
}*/

//wrapper function to get topness using b-tagged jets as input (MET as Pt,Phi given) // deprecated
//helper function using Math::LorentzVector, using Met.Pt and MET.Phi
/*float Gettopness_(float met, float metphi, LorentzVector lep, vector<LorentzVector> bjets, int version){
  float metx = met*TMath::Cos(metphi);
  float mety = met*TMath::Sin(metphi);
  LorentzVector metlv; metlv.SetPxPyPzE(metx,mety,0,met);
  return Gettopness(metlv, lep, bjets, version);
}*/

//wrapper function to get topness using jets as input // deprecated
//addnjets: if <=1 bjets found, have total of addnjets for bjet looper adding jets to bjet vector using addjets (default=2, recommended=2,3)
//addjets: ==1: according to highest b-tag discriminant, ==2: according to highest jet-pt (default=2)
//version: ==1: reduced topness (recommended), else: full topness
/*float TopnessVersion(int version, LorentzVector MET, LorentzVector lep, vector<LorentzVector> jets, vector<float> jet_bdiscr, float btagdiscr, unsigned int addnjets, int addjets){
  if(jets.size()!=jet_bdiscr.size() ) return -999.;
  vector<LorentzVector> bjet = JetUtil::BJetSelector(jets,jet_bdiscr,btagdiscr,2,addnjets,addjets);

  return Gettopness(MET,lep,bjet,version);
}*/

//wrapper function to get topness using jets as input (MET as Pt,Phi given) // deprecated
//addnjets: if <=1 bjets found, have total of addnjets for bjet looper adding jets to bjet vector using addjets (default=2, recommended=2,3)
//addjets: ==1: according to highest b-tag discriminant, ==2: according to highest jet-pt (default=2)
//version: ==1: reduced topness (recommended), else: full topness
/*float TopnessVersion_(int version, float met, float metphi, LorentzVector lep, vector<LorentzVector> jets, vector<float> jet_bdiscr, float btagdiscr, unsigned int addnjets, int addjets){
  float metx = met*TMath::Cos(metphi);
  float mety = met*TMath::Sin(metphi);
  LorentzVector metlv; metlv.SetPxPyPzE(metx,mety,0,met);
  return TopnessVersion(version,metlv,lep,jets,jet_bdiscr,btagdiscr,addnjets,addjets);
}*/

//wrapper function to get topness using correct jets as input - full calculation needs JetUtil CSV ordering, see looper
//version: ==1: reduced topness (recommended), else: full topness
float CalcTopness(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, int version, LorentzVector MET, LorentzVector lep, vector<LorentzVector> bjets,  vector<LorentzVector> addjets, double aW, double aT, double aCM, bool forceb, bool dontforceb){

  if(forceb){
    if(version==1&&(bjets.size()+addjets.size())<1) return -999.;
    if(version==0&&(bjets.size()+addjets.size())<2) return -999.;
  }
  else
    if((bjets.size()+addjets.size())<2) return -999.;
  TLorentzVector l, met, b1, b2;
  l.SetPxPyPzE(lep.Px(),lep.Py(),lep.Pz(),lep.E());
  met.SetPxPyPzE(MET.Px(),MET.Py(),MET.Pz(),MET.E());
  float topness = 1e6;
  double myCM(0), myTM(0), myWL(0), myTL(0);
  double mypnx(0), mypny(0), mypnz(0), mypWz(0);
  if(!forceb){
    for(unsigned int n = 0; n<bjets.size(); ++n){
      b1.SetPxPyPzE(bjets[n].Px(),bjets[n].Py(),bjets[n].Pz(),bjets[n].E());
      for(unsigned int m = n+1; m<bjets.size(); ++m){
	b2.SetPxPyPzE(bjets[m].Px(),bjets[m].Py(),bjets[m].Pz(),bjets[m].E());
	float tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b1,b2,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for b1 " << b1.Pt() << " and b2 " << b2.Pt() << endl;
	tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b2,b1,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for b1 " << b2.Pt() << " and b2 " << b1.Pt() << endl;
      }
      for(unsigned int m = 0; m<addjets.size(); ++m){
	b2.SetPxPyPzE(addjets[m].Px(),addjets[m].Py(),addjets[m].Pz(),addjets[m].E());
	float tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b1,b2,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for b1 " << b1.Pt() << " and a2 " << b2.Pt() << endl;
	tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b2,b1,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for a1 " << b2.Pt() << " and b2 " << b1.Pt() << endl;
      }
    }
    if(bjets.size()==0){
      b1.SetPxPyPzE(addjets[0].Px(),addjets[0].Py(),addjets[0].Pz(),addjets[0].E());
      for(unsigned int m = 1; m<addjets.size(); ++m){
	b2.SetPxPyPzE(addjets[m].Px(),addjets[m].Py(),addjets[m].Pz(),addjets[m].E());
	float tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b1,b2,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b2,b1,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
      }
    }
    if(dontforceb){
      for(unsigned int n = 0; n<addjets.size(); ++n){
	b1.SetPxPyPzE(addjets[n].Px(),addjets[n].Py(),addjets[n].Pz(),addjets[n].E());
	for(unsigned int m = n+1; m<addjets.size(); ++m){
	  b2.SetPxPyPzE(addjets[m].Px(),addjets[m].Py(),addjets[m].Pz(),addjets[m].E());
	  float tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b1,b2,version, aW, aT, aCM);
	  if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	  tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b2,b1,version, aW, aT, aCM);
	  if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	}
      }
    }
  }
  else {
    if(version==0&&(bjets.size())<2) return -999.;
    if(version==1&&(bjets.size())<1) return -999.;
    for(unsigned int n = 0; n<bjets.size(); ++n){
      b1.SetPxPyPzE(bjets[n].Px(),bjets[n].Py(),bjets[n].Pz(),bjets[n].E());
      if(version==1&&bjets.size()==1){
	b2 = b1;
	return topnessMinimization(CM,TM,WL,TL, pnx,pny,pnz,pWz, met,l,b2,b1,version, aW, aT, aCM);
      }
      for(unsigned int m = n+1; m<bjets.size(); ++m){
	b2.SetPxPyPzE(bjets[m].Px(),bjets[m].Py(),bjets[m].Pz(),bjets[m].E());
	float tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b1,b2,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for b1 " << b1.Pt() << " and b2 " << b2.Pt() << endl;
	tmptop = topnessMinimization(myCM,myTM,myWL,myTL, mypnx,mypny,mypnz,mypWz, met,l,b2,b1,version, aW, aT, aCM);
	if(tmptop<topness) { topness = tmptop; CM = myCM; TM = myTM; WL = myWL; TL = myTL; pnx = mypnx; pny = mypny; pnz = mypnz; pWz = mypWz; }
	//cout << "topness " << tmptop << " for b1 " << b2.Pt() << " and b2 " << b1.Pt() << endl;
      }
    }
  }
  return topness;
}

//wrapper function with MET and METPhi instead of METlv
float CalcTopness_(double &CM, double &TM, double &WL, double &TL, double &pnx, double &pny, double &pnz, double &pWz, int version, float MET, float METphi, LorentzVector lep, vector<LorentzVector> bjets,  vector<LorentzVector> addjets, double aW, double aT, double aCM, bool forceb, bool dontforceb){
  float metx = MET*TMath::Cos(METphi);
  float mety = MET*TMath::Sin(METphi);
  LorentzVector metlv; metlv.SetPxPyPzE(metx,mety,0,MET);
  return CalcTopness(CM,TM,WL,TL, pnx,pny,pnz,pWz, version,metlv,lep,bjets,addjets, aW, aT, aCM, forceb, dontforceb);
}
