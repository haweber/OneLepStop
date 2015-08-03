#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"
#include "CMS3.h"

struct myevt{

  	unsigned int index;
	float	evt_pfmet;
	float	evt_pfmetPhi;
	float	evt_trackmet;
	float	evt_trackmetPhi;
	float	evt_pfsumet;
	float	evt_pfmetSig;
	int	evt_event;
	int	evt_lumiBlock;
	int	evt_run;
	bool	filt_csc;
	bool	filt_hbhe;
	bool	filt_hcallaser;
	bool	filt_ecaltp;
	bool	filt_trkfail;
	bool	filt_eebadsc;
	bool	evt_isRealData;
	float	scale1fb;
	float	evt_xsec_incl;
	float	evt_kfactor;
	float	gen_met;
	float	gen_metPhi;
	float	njets;
	float	ht;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > jets;
	vector<float> jets_disc;
	TString sample;
	int	nFOs_SS;
	int	nvtx;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > p4;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > tag_p4;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > dilep_p4;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mc_p4;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > mc_motherp4;
	int	id;
	int	idx;
	float	dxyPV;
	float	dZ;
	float	dxyPV_err;
	int	motherID;
	int	mc_id;
	float	RelIso03;
	float	RelIso03EA;
	float	RelIso03DB;
	bool	passes_SS_tight_v3;
	bool	passes_SS_tight_noiso_v3;
	bool	passes_SS_fo_v3;
	bool	passes_SS_fo_noiso_v3;
	bool	passes_SS_fo_looseMVA_v3;
	bool	passes_SS_fo_looseMVA_noiso_v3;
	bool	passes_HAD_veto_v3;
	bool	passes_HAD_veto_noiso_v3;
	bool	passes_HAD_loose_v3;
	bool	passes_HAD_loose_noiso_v3;
	bool	passes_POG_vetoID;
	bool	passes_POG_looseID;
	bool	passes_POG_mediumID;
	bool	passes_POG_tightID;
	float	ip3d;
	float	ip3derr;
	int	type;
	float	mt;
	float	ptrelv0;
	float	ptrelv1;
	float	miniiso;
	float	miniisoDB;
	float	reliso04;
	float	annulus04;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jet_close_lep;
	float	ptratio;
	int	tag_charge;
	bool	tag_HLTLeadingLeg;
	float	dilep_mass;
	float	sigmaIEtaIEta_full5x5;
	float	sigmaIEtaIEta;
	float	etaSC;
	float	dEtaIn;
	float	dPhiIn;
	float	hOverE;
	float	ecalEnergy;
	float	eOverPIn;
	bool	conv_vtx_flag;
	int	exp_innerlayers;
	int	charge;
	int	sccharge;
	int	ckf_charge;
	bool	threeChargeAgree;
	float	mva;
	float	tkIso;
	float	ecalIso;
	float	hcalIso;
	float	ecalPFClusterIso;
	float	hcalPFClusterIso;
	int	ckf_laywithmeas;
	float	sigmaIPhiIPhi_full5x5;
	float	e1x5_full5x5;
	float	e5x5_full5x5;
	float	r9_full5x5;
	float	etaSCwidth;
	float	phiSCwidth;
	float	eSCRaw;
	float	eSCPresh;
	float	ckf_chi2;
	int	ckf_ndof;
	float	chi2;
	int	ndof;
	float	fbrem;
	float	eOverPOut;
	float	dEtaOut;
	int	pid_PFMuon;
	float	gfit_chi2;
	float	gfit_ndof;
	int	gfit_validSTAHits;
	int	numberOfMatchedStations;
	int	validPixelHits;
	int	nlayers;
	float	chi2LocalPosition;
	float	trkKink;
	int	validHits;
	int	lostHits;
	int	exp_outerlayers;
	float	segmCompatibility;
	int	HLT_Mu8_TrkIsoVVL;
	int	HLT_Mu17_TrkIsoVVL;
	int	HLT_Mu24_TrkIsoVVL;
	int	HLT_Mu34_TrkIsoVVL;
	int	HLT_Mu8;
	int	HLT_Mu17;
	int	HLT_Mu24;
	int	HLT_Mu34;
	int	HLT_Mu10_CentralPFJet30_BTagCSV0p5PF;
	int	HLT_IsoMu24_eta2p1;
	int	HLT_IsoTkMu24_eta2p1;
	int	HLT_IsoMu27;
	int	HLT_IsoTkMu27;
  	int	HLT_IsoMu20;
	int	HLT_IsoTkMu20;
	int	HLT_Mu45_eta2p1;
	int	HLT_Mu50;
	int	HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
	int	HLT_Ele12_CaloIdM_TrackIdM_PFJet30;
	int	HLT_Ele18_CaloIdM_TrackIdM_PFJet30;
	int	HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
	int	HLT_Ele33_CaloIdM_TrackIdM_PFJet30;
	int	HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
	int	HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30;
	int	HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
	int	HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30;
	int	HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF;
	int	HLT_Ele27_eta2p1_WP75_Gsf;
	int	HLT_Ele27_WP85_Gsf;
	int	HLT_Ele27_eta2p1_WPLoose_Gsf;
	int	HLT_Ele27_eta2p1_WPTight_Gsf;
	int	HLT_Ele32_eta2p1_WP75_Gsf;
	int	HLT_Ele32_eta2p1_WPLoose_Gsf;
	int	HLT_Ele32_eta2p1_WPTight_Gsf;
	int	HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300;
	int	HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
	int	HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
	int	HLT_DoubleMu8_Mass8_PFHT300;
	int	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
	int	HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
	int	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
	int	HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
	int	HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300;
	int	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
        float   iso03sumPt;
        float   iso03emEt;
        float   iso03hadEt;
  	int 	tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg;
  	int 	tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg;
  	int 	tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg;
  	int 	tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg;
  	int 	probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg;
  	int 	probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg;
  	int 	probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg;
  	int 	probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg;
};

bool sameEvent (myevt A, myevt B){
  if(A.evt_run      !=B.evt_run      ) return false;
  if(A.evt_lumiBlock!=B.evt_lumiBlock) return false;
  if(A.evt_event    !=B.evt_event    ) return false;
  return true;
}

bool resetEvent(myevt &A){

  A.index = 0;
  A.evt_pfmet = -99;
  A.evt_pfmetPhi = -99;
  A.evt_trackmet = -99;
  A.evt_trackmetPhi = -99;
  A.evt_pfsumet = -99;
  A.evt_pfmetSig = -99;
  A.evt_event = -99;
  A.evt_lumiBlock = -99;
  A.evt_run = -99;
  A.filt_csc = false;
  A.filt_hbhe = false;
  A.filt_hcallaser = false;
  A.filt_ecaltp = false;
  A.filt_trkfail = false;
  A.filt_eebadsc = false;
  A.evt_isRealData = false;
  A.scale1fb = -99;
  A.evt_xsec_incl = -99;
  A.evt_kfactor = -99;
  A.gen_met = -99;
  A.gen_metPhi = -99;
  A.njets = -99;
  A.ht = -99;
  A.jets.clear();
  A.jets_disc.clear();
  A.sample = "";
  A.nFOs_SS = -99;
  A.nvtx = -99;
  A.p4 = LorentzVector(0,0,0,0);
  A.tag_p4 = LorentzVector(0,0,0,0);
  A.dilep_p4 = LorentzVector(0,0,0,0);
  A.mc_p4 = LorentzVector(0,0,0,0);
  A.mc_motherp4 = LorentzVector(0,0,0,0);
  A.id = -99;
  A.idx = -99;
  A.dxyPV = -99;
  A.dZ = -99;
  A.dxyPV_err = -99;
  A.motherID = -99;
  A.mc_id = -99;
  A.RelIso03 = -99;
  A.RelIso03EA = -99;
  A.RelIso03DB = -99;
  A.passes_SS_tight_v3 = false;
  A.passes_SS_tight_noiso_v3 = false;
  A.passes_SS_fo_v3 = false;
  A.passes_SS_fo_noiso_v3 = false;
  A.passes_SS_fo_looseMVA_v3 = false;
  A.passes_SS_fo_looseMVA_noiso_v3 = false;
  A.passes_HAD_veto_v3 = false;
  A.passes_HAD_veto_noiso_v3 = false;
  A.passes_HAD_loose_v3 = false;
  A.passes_HAD_loose_noiso_v3 = false;
  A.passes_POG_vetoID = false;
  A.passes_POG_looseID = false;
  A.passes_POG_mediumID = false;
  A.passes_POG_tightID = false;
  A.ip3d = -99;
  A.ip3derr = -99;
  A.type = -99;
  A.mt = -99;
  A.ptrelv0 = -99;
  A.ptrelv1 = -99;
  A.miniiso = -99;
  A.miniisoDB = -99;
  A.reliso04 = -99;
  A.annulus04 = -99;
  A.jet_close_lep = LorentzVector(0,0,0,0);
  A.ptratio = -99;
  A.tag_charge = -99;
  A.tag_HLTLeadingLeg = false;
  A.dilep_mass = -99;
  A.sigmaIEtaIEta_full5x5 = -99;
  A.sigmaIEtaIEta = -99;
  A.etaSC = -99;
  A.dEtaIn = -99;
  A.dPhiIn = -99;
  A.hOverE = -99;
  A.ecalEnergy = -99;
  A.eOverPIn = -99;
  A.conv_vtx_flag = false;
  A.exp_innerlayers = -99;
  A.charge = -99;
  A.sccharge = -99;
  A.ckf_charge = -99;
  A.threeChargeAgree = false;
  A.mva = -99;
  A.tkIso = -99;
  A.ecalIso = -99;
  A.hcalIso = -99;
  A.ecalPFClusterIso = -99;
  A.hcalPFClusterIso = -99;
  A.ckf_laywithmeas = -99;
  A.sigmaIPhiIPhi_full5x5 = -99;
  A.e1x5_full5x5 = -99;
  A.e5x5_full5x5 = -99;
  A.r9_full5x5 = -99;
  A.etaSCwidth = -99;
  A.phiSCwidth = -99;
  A.eSCRaw = -99;
  A.eSCPresh = -99;
  A.ckf_chi2 = -99;
  A.ckf_ndof = -99;
  A.chi2 = -99;
  A.ndof = -99;
  A.fbrem = -99;
  A.eOverPOut = -99;
  A.dEtaOut = -99;
  A.pid_PFMuon = -99;
  A.gfit_chi2 = -99;
  A.gfit_ndof = -99;
  A.gfit_validSTAHits = -99;
  A.numberOfMatchedStations = -99;
  A.validPixelHits = -99;
  A.nlayers = -99;
  A.chi2LocalPosition = -99;
  A.trkKink = -99;
  A.validHits = -99;
  A.lostHits = -99;
  A.exp_outerlayers = -99;
  A.segmCompatibility = -99;
  A.HLT_Mu8_TrkIsoVVL = -99;
  A.HLT_Mu17_TrkIsoVVL = -99;
  A.HLT_Mu24_TrkIsoVVL = -99;
  A.HLT_Mu34_TrkIsoVVL = -99;
  A.HLT_Mu8 = -99;
  A.HLT_Mu17 = -99;
  A.HLT_Mu24 = -99;
  A.HLT_Mu34 = -99;
  A.HLT_Mu10_CentralPFJet30_BTagCSV0p5PF = -99;
  A.HLT_IsoMu24_eta2p1 = -99;
  A.HLT_IsoTkMu24_eta2p1 = -99;
  A.HLT_IsoMu27 = -99;
  A.HLT_IsoTkMu27 = -99;
  A.HLT_IsoMu20 = -99;
  A.HLT_IsoTkMu20 = -99;
  A.HLT_Mu45_eta2p1 = -99;
  A.HLT_Mu50 = -99;
  A.HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -99;
  A.HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = -99;
  A.HLT_Ele18_CaloIdM_TrackIdM_PFJet30 = -99;
  A.HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = -99;
  A.HLT_Ele33_CaloIdM_TrackIdM_PFJet30 = -99;
  A.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = -99;
  A.HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30 = -99;
  A.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = -99;
  A.HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30 = -99;
  A.HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF = -99;
  A.HLT_Ele27_eta2p1_WP75_Gsf = -99;
  A.HLT_Ele27_WP85_Gsf = -99;
  A.HLT_Ele27_eta2p1_WPLoose_Gsf = -99;
  A.HLT_Ele27_eta2p1_WPTight_Gsf = -99;
  A.HLT_Ele32_eta2p1_WP75_Gsf = -99;
  A.HLT_Ele32_eta2p1_WPLoose_Gsf = -99;
  A.HLT_Ele32_eta2p1_WPTight_Gsf = -99;
  A.HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300 = -99;
  A.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = -99;
  A.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = -99;
  A.HLT_DoubleMu8_Mass8_PFHT300 = -99;
  A.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = -99;
  A.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = -99;
  A.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = -99;
  A.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = -99;
  A.HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = -99;
  A.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = -99;
  A.iso03sumPt = -1;
  A.iso03emEt = -1;
  A.iso03hadEt = -1;	
  A.tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = -1;
  A.tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = -1;
  A.tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = -1;
  A.tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = -1;
  A.probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = -1;
  A.probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = -1;
  A.probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = -1;
  A.probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = -1;

  return true;

}


struct mymuo{

	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > p4;
	int	id;
	int	idx;
	float	dxyPV;
	float	dZ;
	float	dxyPV_err;
	float	RelIso03;
	float	RelIso03EA;
	float	RelIso03DB;
	bool	passes_POG_vetoID;
	bool	passes_POG_looseID;
	bool	passes_POG_mediumID;
	bool	passes_POG_tightID;
	float	ip3d;
	float	ip3derr;
	int	type;
	float	mt;
	float	ptrelv0;
	float	ptrelv1;
	float	miniiso;
	float	miniisoDB;
	float	reliso04;
	float	annulus04;
	int	exp_innerlayers;
	int	pid_PFMuon;
	float	gfit_chi2;
	float	gfit_ndof;
	int	gfit_validSTAHits;
	int	numberOfMatchedStations;
	int	validPixelHits;
	int	nlayers;
	float	chi2LocalPosition;
	float	trkKink;
	int	validHits;
	int	lostHits;
	int	exp_outerlayers;
	float	segmCompatibility;

};
/*
bool passLooseID(int type, int pid_PFMuon){
  if (!pid_PFMuon) return false;    
  bool isGlobal  = true;
  bool isTracker = true;
  if ((type & (1<<1)) == 0) isGlobal  = false;
  if ((type & (1<<2)) == 0) isTracker = false;
  if (!(isGlobal || isTracker)) return false;  
  return true;
}


bool passMediumID(int type, float gfit_chi2, float gfit_ndof, float chi2LocalPosition, float trkKink, int validHits, int lostHits, int exp_innerlayers, int exp_outerlayers, float segmCompatibility, int pid_PFMuon){
  bool isGlobal  = true;
  if (((type) & (1<<1)) == 0) isGlobal  = false;
  bool goodGlb = isGlobal &&gfit_chi2/gfit_ndof<3. && chi2LocalPosition<12. && trkKink<20.;
  double validFraction = validHits/(double)(validHits+lostHits+exp_innerlayers+exp_outerlayers);
  bool good = passLooseID(type,pid_PFMuon) && validFraction >= 0.8 &&  segmCompatibility >= (goodGlb ? 0.303 : 0.451);
  return good;
}

bool passTightID(int pid_PFMuon, int type, float gfit_chi2, float gfit_ndof, int gfit_validSTAHits, int numberOfMatchedStations, int validPixelHits, int nlayers, float dxyPV, float dZ){
  if (!pid_PFMuon) return false;    
  if (((type) & (1<<1)) == 0 ) return false;//global muon
  if (gfit_chi2/gfit_ndof >= 10  ) return false; 
  if (gfit_validSTAHits== 0   ) return false; 
  if (numberOfMatchedStations<  2   ) return false;
  if (validPixelHits== 0   ) return false;
  if (nlayers<  6   ) return false;
  if (fabs(dxyPV) >  0.2 ) return false;
  if (fabs(dZ) >  0.5 ) return false;
  return true;
}
*/
bool passLooseID(myevt e){
  if (!e.pid_PFMuon) return false;    
  bool isGlobal  = true;
  bool isTracker = true;
  if ((e.type & (1<<1)) == 0) isGlobal  = false;
  if ((e.type & (1<<2)) == 0) isTracker = false;
  if (!(isGlobal || isTracker)) return false;  
  return true;
}


bool passMediumID(myevt e){
  bool isGlobal  = true;
  if (((e.type) & (1<<1)) == 0) isGlobal  = false;
  bool goodGlb = isGlobal &&e.gfit_chi2/e.gfit_ndof<3. && e.chi2LocalPosition<12. && e.trkKink<20.;
  double validFraction = e.validHits/(double)(e.validHits+e.lostHits+e.exp_innerlayers+e.exp_outerlayers);
  bool good = passLooseID(e) && validFraction >= 0.8 &&  e.segmCompatibility >= (goodGlb ? 0.303 : 0.451);
  return good;
}

bool passTightID(myevt e){
  if (!e.pid_PFMuon) return false;    
  if (((e.type) & (1<<1)) == 0 ) return false;//global muon
  if (e.gfit_chi2/e.gfit_ndof >= 10  ) return false; 
  if (e.gfit_validSTAHits== 0   ) return false; 
  if (e.numberOfMatchedStations<  2   ) return false;
  if (e.validPixelHits== 0   ) return false;
  if (e.nlayers<  6   ) return false;
  if (fabs(e.dxyPV) >  0.2 ) return false;
  if (fabs(e.dZ) >  0.5 ) return false;
  return true;
}

bool setmymuo(mymuo &m, myevt e){
  if(abs(e.id)!=13) return false;
  m.p4                  = e.p4;
  m.id			= e.id;
  m.idx			= e.idx;
  m.dxyPV		= e.dxyPV;
  m.dZ			= e.dZ;
  m.dxyPV_err		= e.dxyPV_err;
  m.RelIso03		= e.RelIso03;
  m.RelIso03EA		= e.RelIso03EA;
  m.RelIso03DB		= e.RelIso03DB;
  //m.passes_POG_vetoID	= passLooseID(e.type, e.pid_PFMuon);
  //m.passes_POG_looseID	= passLooseID(e.type, e.pid_PFMuon);
  //m.passes_POG_mediumID	= passMediumID(e.type, e.gfit_chi2, e.gfit_ndof, e.chi2LocalPosition, e.trkKink, e.validHits, e.lostHits, e.exp_innerlayers, e.exp_outerlayers, e.segmCompatibility, e.pid_PFMuon);
  //m.passes_POG_tightID	= passTightID(e.pid_PFMuon, e.type, e.gfit_chi2, e.gfit_ndof, e.gfit_validSTAHits, e.numberOfMatchedStations, e.validPixelHits, e.nlayers, e.dxyPV, e.dZ);
  m.passes_POG_vetoID	= passLooseID(e);
  m.passes_POG_looseID	= passLooseID(e);
  m.passes_POG_mediumID	= passMediumID(e);
  m.passes_POG_tightID	= passTightID(e);
  m.ip3d		= e.ip3d;
  m.ip3derr		= e.ip3derr;
  m.type		= e.type;
  m.mt			= e.mt;
  m.ptrelv0		= e.ptrelv0;
  m.ptrelv1		= e.ptrelv1;
  m.miniiso		= e.miniiso;
  m.miniisoDB		= e.miniisoDB;
  m.reliso04		= e.reliso04;
  m.annulus04		= e.annulus04;
  m.exp_innerlayers	= e.exp_innerlayers;
  m.pid_PFMuon		= e.pid_PFMuon;
  m.gfit_chi2		= e.gfit_chi2;
  m.gfit_ndof		= e.gfit_ndof;
  m.gfit_validSTAHits	= e.gfit_validSTAHits;
  m.numberOfMatchedStations	= e.numberOfMatchedStations;
  m.validPixelHits	= e.validPixelHits;
  m.nlayers		= e.nlayers;
  m.chi2LocalPosition	= e.chi2LocalPosition;
  m.trkKink		= e.trkKink;
  m.validHits		= e.validHits;
  m.lostHits		= e.lostHits;
  m.exp_outerlayers	= e.exp_outerlayers;
  m.segmCompatibility	= e.segmCompatibility;
  return true;
  
}

struct sort_by_pt{
  bool operator () (mymuo &v1, mymuo &v2)
  {
        return v1.p4.pt() > v2.p4.pt();
  }

    bool operator () (myevt &v1, myevt &v2)
  {
        return v1.p4.pt() > v2.p4.pt();
  }
};

vector<mymuo> sortbypt(vector<mymuo> mu){
  vector<mymuo> newmu = mu;
  sort(newmu.begin(), newmu.end(), sort_by_pt());
  return newmu;
}

vector<myevt> sortbypt(vector<myevt> mu){
  vector<myevt> newmu = mu;
  sort(newmu.begin(), newmu.end(), sort_by_pt());
  return newmu;
}


float calculateMt(const LorentzVector p4, double met, double met_phi){
  float phi1 = p4.Phi();
  float phi2 = met_phi;
  float Et1  = p4.Et();
  float Et2  = met;

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

float getdphi( float phi1 , float phi2 ){                                                                                                                                      
  float dphi = fabs( phi1 - phi2 );
  if( dphi > TMath::Pi() ) dphi = TMath::TwoPi() - dphi;
  return dphi;
}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

myevt getbettereleevt(myevt A, myevt B){
  myevt temp; resetEvent(temp);
  if(abs(A.id)!=11 && abs(B.id)!=11) return temp;
  if(abs(A.id)!=11) return B;
  if(abs(B.id)!=11) return A;
  if(A.passes_POG_mediumID && !B.passes_POG_mediumID) return A;
  if(!A.passes_POG_mediumID && B.passes_POG_mediumID) return B;
  if(A.passes_POG_looseID && !B.passes_POG_looseID) return A;
  if(!A.passes_POG_looseID && B.passes_POG_looseID) return B;
  if(A.RelIso03EA<0.107587 && B.RelIso03EA>0.163368) return A;
  if(B.RelIso03EA<0.107587 && A.RelIso03EA>0.163368) return B;
  if(fabs(A.p4.Eta())<2.1 && fabs(B.p4.Eta())>2.1) return A;
  if(fabs(A.p4.Eta())>2.1 && fabs(B.p4.Eta())<2.1) return B;
  if(fabs(A.p4.Eta())<1.479 && fabs(B.p4.Eta())>1.479) return A;
  if(fabs(A.p4.Eta())>1.479 && fabs(B.p4.Eta())<1.479) return B;
  if(A.p4.Pt() > B.p4.Pt() ) return A;
  return B;
}

myevt getbettermuo(myevt A, myevt B){
  myevt temp; resetEvent(temp);
  if(abs(A.id)!=13 && abs(B.id)!=13) return temp;
  if(abs(A.id)!=13) return B;
  if(abs(B.id)!=13) return A;
  //if(A.passes_POG_mediumID && !B.passes_POG_mediumID) return A;
  //if(!A.passes_POG_mediumID && B.passes_POG_mediumID) return B;
  //if(A.passes_POG_looseID && !B.passes_POG_looseID) return A;
  //if(!A.passes_POG_looseID && B.passes_POG_looseID) return B;
  if(fabs(A.p4.Eta())<2.1 && fabs(B.p4.Eta())>2.1) return A;
  if(fabs(A.p4.Eta())>2.1 && fabs(B.p4.Eta())<2.1) return B;
  if(A.RelIso03EA<0.10 && B.RelIso03EA>0.15) return A;//??
  if(B.RelIso03EA<0.10 && A.RelIso03EA>0.15) return B;//??
  if(fabs(A.p4.Eta())<1.479 && fabs(B.p4.Eta())>1.479) return A;
  if(fabs(A.p4.Eta())>1.479 && fabs(B.p4.Eta())<1.479) return B;
  if(A.p4.Pt() > B.p4.Pt() ) return A;
  return B;
}
