// -*- C++ -*-
#ifndef CMS3_H
#define CMS3_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class CMS3 {
private: 
protected: 
	unsigned int index;
	unsigned int	run_;
	TBranch *run_branch;
	bool run_isLoaded;
	unsigned int	ls_;
	TBranch *ls_branch;
	bool ls_isLoaded;
	unsigned int	evt_;
	TBranch *evt_branch;
	bool evt_isLoaded;
	int	nvtxs_;
	TBranch *nvtxs_branch;
	bool nvtxs_isLoaded;
	int	firstGoodVtxIdx_;
	TBranch *firstGoodVtxIdx_branch;
	bool firstGoodVtxIdx_isLoaded;
	int	firstVtx_isfake_;
	TBranch *firstVtx_isfake_branch;
	bool firstVtx_isfake_isLoaded;
	float	firstVtx_ndof_;
	TBranch *firstVtx_ndof_branch;
	bool firstVtx_ndof_isLoaded;
	float	firstVtx_posRho_;
	TBranch *firstVtx_posRho_branch;
	bool firstVtx_posRho_isLoaded;
	float	firstVtx_posZ_;
	TBranch *firstVtx_posZ_branch;
	bool firstVtx_posZ_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *firstVtx_posp4_;
	TBranch *firstVtx_posp4_branch;
	bool firstVtx_posp4_isLoaded;
	int	pu_nvtxs_;
	TBranch *pu_nvtxs_branch;
	bool pu_nvtxs_isLoaded;
	float	pfmet_;
	TBranch *pfmet_branch;
	bool pfmet_isLoaded;
	float	pfmet_phi_;
	TBranch *pfmet_phi_branch;
	bool pfmet_phi_isLoaded;
	float	calomet_;
	TBranch *calomet_branch;
	bool calomet_isLoaded;
	float	calomet_phi_;
	TBranch *calomet_phi_branch;
	bool calomet_phi_isLoaded;
	float	filt_cscbeamhalo_;
	TBranch *filt_cscbeamhalo_branch;
	bool filt_cscbeamhalo_isLoaded;
	float	filt_ecallaser_;
	TBranch *filt_ecallaser_branch;
	bool filt_ecallaser_isLoaded;
	float	filt_ecaltp_;
	TBranch *filt_ecaltp_branch;
	bool filt_ecaltp_isLoaded;
	float	filt_eebadsc_;
	TBranch *filt_eebadsc_branch;
	bool filt_eebadsc_isLoaded;
	float	filt_goodvtx_;
	TBranch *filt_goodvtx_branch;
	bool filt_goodvtx_isLoaded;
	float	filt_hbhenoise_;
	TBranch *filt_hbhenoise_branch;
	bool filt_hbhenoise_isLoaded;
	float	filt_hcallaser_;
	TBranch *filt_hcallaser_branch;
	bool filt_hcallaser_isLoaded;
	float	filt_met_;
	TBranch *filt_met_branch;
	bool filt_met_isLoaded;
	float	filt_trkfail_;
	TBranch *filt_trkfail_branch;
	bool filt_trkfail_isLoaded;
	float	filt_trkPOG_;
	TBranch *filt_trkPOG_branch;
	bool filt_trkPOG_isLoaded;
	float	filt_trkPOG_tmc_;
	TBranch *filt_trkPOG_tmc_branch;
	bool filt_trkPOG_tmc_isLoaded;
	float	filt_trkPOG_tms_;
	TBranch *filt_trkPOG_tms_branch;
	bool filt_trkPOG_tms_isLoaded;
	float	filt_eff_;
	TBranch *filt_eff_branch;
	bool filt_eff_isLoaded;
	float	scale1fb_;
	TBranch *scale1fb_branch;
	bool scale1fb_isLoaded;
	float	xsec_;
	TBranch *xsec_branch;
	bool xsec_isLoaded;
	float	kfactor_;
	TBranch *kfactor_branch;
	bool kfactor_isLoaded;
	float	pu_ntrue_;
	TBranch *pu_ntrue_branch;
	bool pu_ntrue_isLoaded;
	int	ngoodleps_;
	TBranch *ngoodleps_branch;
	bool ngoodleps_isLoaded;
	int	nvetoleps_;
	TBranch *nvetoleps_branch;
	bool nvetoleps_isLoaded;
	bool	is_data_;
	TBranch *is_data_branch;
	bool is_data_isLoaded;
	string *dataset_;
	TBranch *dataset_branch;
	bool dataset_isLoaded;
	string *filename_;
	TBranch *filename_branch;
	bool filename_isLoaded;
	string *cms3tag_;
	TBranch *cms3tag_branch;
	bool cms3tag_isLoaded;
	unsigned int	nEvents_;
	TBranch *nEvents_branch;
	bool nEvents_isLoaded;
	unsigned int	nEvents_goodvtx_;
	TBranch *nEvents_goodvtx_branch;
	bool nEvents_goodvtx_isLoaded;
	unsigned int	nEvents_MET30_;
	TBranch *nEvents_MET30_branch;
	bool nEvents_MET30_isLoaded;
	unsigned int	nEvents_1goodlep_;
	TBranch *nEvents_1goodlep_branch;
	bool nEvents_1goodlep_isLoaded;
	unsigned int	nEvents_2goodjets_;
	TBranch *nEvents_2goodjets_branch;
	bool nEvents_2goodjets_isLoaded;
	int	genlepsfromtop_;
	TBranch *genlepsfromtop_branch;
	bool genlepsfromtop_isLoaded;
	float	MT2W_;
	TBranch *MT2W_branch;
	bool MT2W_isLoaded;
	float	MT2W_lep2_;
	TBranch *MT2W_lep2_branch;
	bool MT2W_lep2_isLoaded;
	float	mindphi_met_j1_j2_;
	TBranch *mindphi_met_j1_j2_branch;
	bool mindphi_met_j1_j2_isLoaded;
	float	mt_met_lep_;
	TBranch *mt_met_lep_branch;
	bool mt_met_lep_isLoaded;
	float	mt_met_lep2_;
	TBranch *mt_met_lep2_branch;
	bool mt_met_lep2_isLoaded;
	float	dR_lep_leadb_;
	TBranch *dR_lep_leadb_branch;
	bool dR_lep_leadb_isLoaded;
	float	dR_lep2_leadb_;
	TBranch *dR_lep2_leadb_branch;
	bool dR_lep2_leadb_isLoaded;
	float	hadronic_top_chi2_;
	TBranch *hadronic_top_chi2_branch;
	bool hadronic_top_chi2_isLoaded;
	float	dphi_Wlep_;
	TBranch *dphi_Wlep_branch;
	bool dphi_Wlep_isLoaded;
	float	MET_over_sqrtHT_;
	TBranch *MET_over_sqrtHT_branch;
	bool MET_over_sqrtHT_isLoaded;
	float	ak4pfjets_rho_;
	TBranch *ak4pfjets_rho_branch;
	bool ak4pfjets_rho_isLoaded;
	vector<string> *sparms_comment_;
	TBranch *sparms_comment_branch;
	bool sparms_comment_isLoaded;
	vector<string> *sparms_names_;
	TBranch *sparms_names_branch;
	bool sparms_names_isLoaded;
	float	sparms_filterEfficiency_;
	TBranch *sparms_filterEfficiency_branch;
	bool sparms_filterEfficiency_isLoaded;
	float	sparms_pdfScale_;
	TBranch *sparms_pdfScale_branch;
	bool sparms_pdfScale_isLoaded;
	float	sparms_pdfWeight1_;
	TBranch *sparms_pdfWeight1_branch;
	bool sparms_pdfWeight1_isLoaded;
	float	sparms_pdfWeight2_;
	TBranch *sparms_pdfWeight2_branch;
	bool sparms_pdfWeight2_isLoaded;
	float	sparms_weight_;
	TBranch *sparms_weight_branch;
	bool sparms_weight_isLoaded;
	float	sparms_xsec_;
	TBranch *sparms_xsec_branch;
	bool sparms_xsec_isLoaded;
	vector<float> *sparms_values_;
	TBranch *sparms_values_branch;
	bool sparms_values_isLoaded;
	int	sparms_subProcessId_;
	TBranch *sparms_subProcessId_branch;
	bool sparms_subProcessId_isLoaded;
	float	mass_lsp_;
	TBranch *mass_lsp_branch;
	bool mass_lsp_isLoaded;
	float	mass_chargino_;
	TBranch *mass_chargino_branch;
	bool mass_chargino_isLoaded;
	float	mass_stop_;
	TBranch *mass_stop_branch;
	bool mass_stop_isLoaded;
	float	genmet_;
	TBranch *genmet_branch;
	bool genmet_isLoaded;
	float	genmet_phi_;
	TBranch *genmet_phi_branch;
	bool genmet_phi_isLoaded;
	bool	PassTrackVeto_;
	TBranch *PassTrackVeto_branch;
	bool PassTrackVeto_isLoaded;
	bool	PassTrackVeto_v2_;
	TBranch *PassTrackVeto_v2_branch;
	bool PassTrackVeto_v2_isLoaded;
	bool	PassTrackVeto_v3_;
	TBranch *PassTrackVeto_v3_branch;
	bool PassTrackVeto_v3_isLoaded;
	bool	PassTauVeto_;
	TBranch *PassTauVeto_branch;
	bool PassTauVeto_isLoaded;
	float	EA_all_rho_;
	TBranch *EA_all_rho_branch;
	bool EA_all_rho_isLoaded;
	float	EA_allcalo_rho_;
	TBranch *EA_allcalo_rho_branch;
	bool EA_allcalo_rho_isLoaded;
	float	EA_centralcalo_rho_;
	TBranch *EA_centralcalo_rho_branch;
	bool EA_centralcalo_rho_isLoaded;
	float	EA_centralchargedpileup_rho_;
	TBranch *EA_centralchargedpileup_rho_branch;
	bool EA_centralchargedpileup_rho_isLoaded;
	float	EA_centralneutral_rho_;
	TBranch *EA_centralneutral_rho_branch;
	bool EA_centralneutral_rho_isLoaded;
	float	topness_;
	TBranch *topness_branch;
	bool topness_isLoaded;
	float	topness_lep2_;
	TBranch *topness_lep2_branch;
	bool topness_lep2_isLoaded;
	float	topnessMod_;
	TBranch *topnessMod_branch;
	bool topnessMod_isLoaded;
	float	topnessMod_lep2_;
	TBranch *topnessMod_lep2_branch;
	bool topnessMod_lep2_isLoaded;
	float	MT2_lb_b_;
	TBranch *MT2_lb_b_branch;
	bool MT2_lb_b_isLoaded;
	float	MT2_lb_b_lep2_;
	TBranch *MT2_lb_b_lep2_branch;
	bool MT2_lb_b_lep2_isLoaded;
	float	MT2_lb_b_mass_;
	TBranch *MT2_lb_b_mass_branch;
	bool MT2_lb_b_mass_isLoaded;
	float	MT2_lb_b_mass_lep2_;
	TBranch *MT2_lb_b_mass_lep2_branch;
	bool MT2_lb_b_mass_lep2_isLoaded;
	float	MT2_lb_bqq_;
	TBranch *MT2_lb_bqq_branch;
	bool MT2_lb_bqq_isLoaded;
	float	MT2_lb_bqq_lep2_;
	TBranch *MT2_lb_bqq_lep2_branch;
	bool MT2_lb_bqq_lep2_isLoaded;
	float	MT2_lb_bqq_mass_;
	TBranch *MT2_lb_bqq_mass_branch;
	bool MT2_lb_bqq_mass_isLoaded;
	float	MT2_lb_bqq_mass_lep2_;
	TBranch *MT2_lb_bqq_mass_lep2_branch;
	bool MT2_lb_bqq_mass_lep2_isLoaded;
	float	Mlb_closestb_;
	TBranch *Mlb_closestb_branch;
	bool Mlb_closestb_isLoaded;
	float	Mlb_lead_bdiscr_;
	TBranch *Mlb_lead_bdiscr_branch;
	bool Mlb_lead_bdiscr_isLoaded;
	float	Mlb_closestb_lep2_;
	TBranch *Mlb_closestb_lep2_branch;
	bool Mlb_closestb_lep2_isLoaded;
	float	Mlb_lead_bdiscr_lep2_;
	TBranch *Mlb_lead_bdiscr_lep2_branch;
	bool Mlb_lead_bdiscr_lep2_isLoaded;
	float	Mjjj_;
	TBranch *Mjjj_branch;
	bool Mjjj_isLoaded;
	float	Mjjj_lep2_;
	TBranch *Mjjj_lep2_branch;
	bool Mjjj_lep2_isLoaded;
	int	HLT_SingleEl_;
	TBranch *HLT_SingleEl_branch;
	bool HLT_SingleEl_isLoaded;
	int	HLT_SingleMu_;
	TBranch *HLT_SingleMu_branch;
	bool HLT_SingleMu_isLoaded;
	int	HLT_MET170_;
	TBranch *HLT_MET170_branch;
	bool HLT_MET170_isLoaded;
	int	HLT_MET120Btag_;
	TBranch *HLT_MET120Btag_branch;
	bool HLT_MET120Btag_isLoaded;
	int	HLT_MET120Mu5_;
	TBranch *HLT_MET120Mu5_branch;
	bool HLT_MET120Mu5_isLoaded;
	int	HLT_HT350MET120_;
	TBranch *HLT_HT350MET120_branch;
	bool HLT_HT350MET120_isLoaded;
	int	HLT_DiEl_;
	TBranch *HLT_DiEl_branch;
	bool HLT_DiEl_isLoaded;
	int	HLT_DiMu_;
	TBranch *HLT_DiMu_branch;
	bool HLT_DiMu_isLoaded;
	int	HLT_Mu8El17_;
	TBranch *HLT_Mu8El17_branch;
	bool HLT_Mu8El17_isLoaded;
	int	HLT_Mu8El23_;
	TBranch *HLT_Mu8El23_branch;
	bool HLT_Mu8El23_isLoaded;
	int	HLT_Mu17El12_;
	TBranch *HLT_Mu17El12_branch;
	bool HLT_Mu17El12_isLoaded;
	int	HLT_Mu23El12_;
	TBranch *HLT_Mu23El12_branch;
	bool HLT_Mu23El12_isLoaded;
	int	HLT_SingleEl27_;
	TBranch *HLT_SingleEl27_branch;
	bool HLT_SingleEl27_isLoaded;
	int	HLT_SingleEl27Tight_;
	TBranch *HLT_SingleEl27Tight_branch;
	bool HLT_SingleEl27Tight_isLoaded;
	int	HLT_SingleElTight_;
	TBranch *HLT_SingleElTight_branch;
	bool HLT_SingleElTight_isLoaded;
	int	HLT_SingleElHT200_;
	TBranch *HLT_SingleElHT200_branch;
	bool HLT_SingleElHT200_isLoaded;
	int	HLT_SingleMuNoEta_;
	TBranch *HLT_SingleMuNoEta_branch;
	bool HLT_SingleMuNoEta_isLoaded;
	int	HLT_SingleMuNoIso_;
	TBranch *HLT_SingleMuNoIso_branch;
	bool HLT_SingleMuNoIso_isLoaded;
	int	HLT_SingleMuNoIsoNoEta_;
	TBranch *HLT_SingleMuNoIsoNoEta_branch;
	bool HLT_SingleMuNoIsoNoEta_isLoaded;
	int	HLT_Mu6HT200MET100_;
	TBranch *HLT_Mu6HT200MET100_branch;
	bool HLT_Mu6HT200MET100_isLoaded;
	int	HLT_HT350MET100_;
	TBranch *HLT_HT350MET100_branch;
	bool HLT_HT350MET100_isLoaded;
	int	HLT_SingleMu17_;
	TBranch *HLT_SingleMu17_branch;
	bool HLT_SingleMu17_isLoaded;
	int	HLT_SingleMu20_;
	TBranch *HLT_SingleMu20_branch;
	bool HLT_SingleMu20_isLoaded;
	int	HLT_SingleMu24_;
	TBranch *HLT_SingleMu24_branch;
	bool HLT_SingleMu24_isLoaded;
	int	HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_;
	TBranch *HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch;
	bool HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded;
	int	HLT_MET90_MHT90_IDTight_;
	TBranch *HLT_MET90_MHT90_IDTight_branch;
	bool HLT_MET90_MHT90_IDTight_isLoaded;
	int	HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_;
	TBranch *HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch;
	bool HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded;
	float	pu_weight_;
	TBranch *pu_weight_branch;
	bool pu_weight_isLoaded;
	float	lep_sf_;
	TBranch *lep_sf_branch;
	bool lep_sf_isLoaded;
	float	btag_sf_;
	TBranch *btag_sf_branch;
	bool btag_sf_isLoaded;
	float	HLT_SingleEl_eff_;
	TBranch *HLT_SingleEl_eff_branch;
	bool HLT_SingleEl_eff_isLoaded;
	float	HLT_SingleMu_eff_;
	TBranch *HLT_SingleMu_eff_branch;
	bool HLT_SingleMu_eff_isLoaded;
	bool	lep1_is_mu_;
	TBranch *lep1_is_mu_branch;
	bool lep1_is_mu_isLoaded;
	bool	lep1_is_el_;
	TBranch *lep1_is_el_branch;
	bool lep1_is_el_isLoaded;
	int	lep1_charge_;
	TBranch *lep1_charge_branch;
	bool lep1_charge_isLoaded;
	int	lep1_pdgid_;
	TBranch *lep1_pdgid_branch;
	bool lep1_pdgid_isLoaded;
	int	lep1_type_;
	TBranch *lep1_type_branch;
	bool lep1_type_isLoaded;
	int	lep1_production_type_;
	TBranch *lep1_production_type_branch;
	bool lep1_production_type_isLoaded;
	float	lep1_d0_;
	TBranch *lep1_d0_branch;
	bool lep1_d0_isLoaded;
	float	lep1_d0err_;
	TBranch *lep1_d0err_branch;
	bool lep1_d0err_isLoaded;
	float	lep1_dz_;
	TBranch *lep1_dz_branch;
	bool lep1_dz_isLoaded;
	float	lep1_dzerr_;
	TBranch *lep1_dzerr_branch;
	bool lep1_dzerr_isLoaded;
	float	lep1_sigmaIEtaEta_fill5x5_;
	TBranch *lep1_sigmaIEtaEta_fill5x5_branch;
	bool lep1_sigmaIEtaEta_fill5x5_isLoaded;
	float	lep1_dEtaIn_;
	TBranch *lep1_dEtaIn_branch;
	bool lep1_dEtaIn_isLoaded;
	float	lep1_dPhiIn_;
	TBranch *lep1_dPhiIn_branch;
	bool lep1_dPhiIn_isLoaded;
	float	lep1_hOverE_;
	TBranch *lep1_hOverE_branch;
	bool lep1_hOverE_isLoaded;
	float	lep1_ooEmooP_;
	TBranch *lep1_ooEmooP_branch;
	bool lep1_ooEmooP_isLoaded;
	int	lep1_expectedMissingInnerHits_;
	TBranch *lep1_expectedMissingInnerHits_branch;
	bool lep1_expectedMissingInnerHits_isLoaded;
	bool	lep1_conversionVeto_;
	TBranch *lep1_conversionVeto_branch;
	bool lep1_conversionVeto_isLoaded;
	float	lep1_etaSC_;
	TBranch *lep1_etaSC_branch;
	bool lep1_etaSC_isLoaded;
	float	lep1_ChiSqr_;
	TBranch *lep1_ChiSqr_branch;
	bool lep1_ChiSqr_isLoaded;
	float	lep1_chiso_;
	TBranch *lep1_chiso_branch;
	bool lep1_chiso_isLoaded;
	float	lep1_nhiso_;
	TBranch *lep1_nhiso_branch;
	bool lep1_nhiso_isLoaded;
	float	lep1_emiso_;
	TBranch *lep1_emiso_branch;
	bool lep1_emiso_isLoaded;
	float	lep1_deltaBeta_;
	TBranch *lep1_deltaBeta_branch;
	bool lep1_deltaBeta_isLoaded;
	float	lep1_relIso03DB_;
	TBranch *lep1_relIso03DB_branch;
	bool lep1_relIso03DB_isLoaded;
	float	lep1_relIso03EA_;
	TBranch *lep1_relIso03EA_branch;
	bool lep1_relIso03EA_isLoaded;
	float	lep1_relIso04DB_;
	TBranch *lep1_relIso04DB_branch;
	bool lep1_relIso04DB_isLoaded;
	float	lep1_miniRelIsoDB_;
	TBranch *lep1_miniRelIsoDB_branch;
	bool lep1_miniRelIsoDB_isLoaded;
	float	lep1_miniRelIsoEA_;
	TBranch *lep1_miniRelIsoEA_branch;
	bool lep1_miniRelIsoEA_isLoaded;
	float	lep1_MiniIso_;
	TBranch *lep1_MiniIso_branch;
	bool lep1_MiniIso_isLoaded;
	int	lep1_mcid_;
	TBranch *lep1_mcid_branch;
	bool lep1_mcid_isLoaded;
	int	lep1_mcstatus_;
	TBranch *lep1_mcstatus_branch;
	bool lep1_mcstatus_isLoaded;
	int	lep1_mc3dr_;
	TBranch *lep1_mc3dr_branch;
	bool lep1_mc3dr_isLoaded;
	int	lep1_mc3id_;
	TBranch *lep1_mc3id_branch;
	bool lep1_mc3id_isLoaded;
	int	lep1_mc3idx_;
	TBranch *lep1_mc3idx_branch;
	bool lep1_mc3idx_isLoaded;
	int	lep1_mc3motherid_;
	TBranch *lep1_mc3motherid_branch;
	bool lep1_mc3motherid_isLoaded;
	int	lep1_mc3motheridx_;
	TBranch *lep1_mc3motheridx_branch;
	bool lep1_mc3motheridx_isLoaded;
	bool	lep1_is_eleid_loose_;
	TBranch *lep1_is_eleid_loose_branch;
	bool lep1_is_eleid_loose_isLoaded;
	bool	lep1_is_eleid_medium_;
	TBranch *lep1_is_eleid_medium_branch;
	bool lep1_is_eleid_medium_isLoaded;
	bool	lep1_is_eleid_tight_;
	TBranch *lep1_is_eleid_tight_branch;
	bool lep1_is_eleid_tight_isLoaded;
	bool	lep1_is_phys14_loose_noIso_;
	TBranch *lep1_is_phys14_loose_noIso_branch;
	bool lep1_is_phys14_loose_noIso_isLoaded;
	bool	lep1_is_phys14_medium_noIso_;
	TBranch *lep1_is_phys14_medium_noIso_branch;
	bool lep1_is_phys14_medium_noIso_isLoaded;
	bool	lep1_is_phys14_tight_noIso_;
	TBranch *lep1_is_phys14_tight_noIso_branch;
	bool lep1_is_phys14_tight_noIso_isLoaded;
	float	lep1_eoverpin_;
	TBranch *lep1_eoverpin_branch;
	bool lep1_eoverpin_isLoaded;
	bool	lep1_is_muoid_loose_;
	TBranch *lep1_is_muoid_loose_branch;
	bool lep1_is_muoid_loose_isLoaded;
	bool	lep1_is_muoid_medium_;
	TBranch *lep1_is_muoid_medium_branch;
	bool lep1_is_muoid_medium_isLoaded;
	bool	lep1_is_muoid_tight_;
	TBranch *lep1_is_muoid_tight_branch;
	bool lep1_is_muoid_tight_isLoaded;
	float	lep1_ip3d_;
	TBranch *lep1_ip3d_branch;
	bool lep1_ip3d_isLoaded;
	float	lep1_ip3derr_;
	TBranch *lep1_ip3derr_branch;
	bool lep1_ip3derr_isLoaded;
	bool	lep1_is_pfmu_;
	TBranch *lep1_is_pfmu_branch;
	bool lep1_is_pfmu_isLoaded;
	bool	lep1_passMediumID_;
	TBranch *lep1_passMediumID_branch;
	bool lep1_passMediumID_isLoaded;
	bool	lep1_passVeto_;
	TBranch *lep1_passVeto_branch;
	bool lep1_passVeto_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep1_p4_;
	TBranch *lep1_p4_branch;
	bool lep1_p4_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep1_mcp4_;
	TBranch *lep1_mcp4_branch;
	bool lep1_mcp4_isLoaded;
	float	lep1_pt_;
	TBranch *lep1_pt_branch;
	bool lep1_pt_isLoaded;
	float	lep1_eta_;
	TBranch *lep1_eta_branch;
	bool lep1_eta_isLoaded;
	float	lep1_phi_;
	TBranch *lep1_phi_branch;
	bool lep1_phi_isLoaded;
	float	lep1_mass_;
	TBranch *lep1_mass_branch;
	bool lep1_mass_isLoaded;
	bool	lep2_is_mu_;
	TBranch *lep2_is_mu_branch;
	bool lep2_is_mu_isLoaded;
	bool	lep2_is_el_;
	TBranch *lep2_is_el_branch;
	bool lep2_is_el_isLoaded;
	int	lep2_charge_;
	TBranch *lep2_charge_branch;
	bool lep2_charge_isLoaded;
	int	lep2_pdgid_;
	TBranch *lep2_pdgid_branch;
	bool lep2_pdgid_isLoaded;
	int	lep2_type_;
	TBranch *lep2_type_branch;
	bool lep2_type_isLoaded;
	int	lep2_production_type_;
	TBranch *lep2_production_type_branch;
	bool lep2_production_type_isLoaded;
	float	lep2_d0_;
	TBranch *lep2_d0_branch;
	bool lep2_d0_isLoaded;
	float	lep2_d0err_;
	TBranch *lep2_d0err_branch;
	bool lep2_d0err_isLoaded;
	float	lep2_dz_;
	TBranch *lep2_dz_branch;
	bool lep2_dz_isLoaded;
	float	lep2_dzerr_;
	TBranch *lep2_dzerr_branch;
	bool lep2_dzerr_isLoaded;
	float	lep2_sigmaIEtaEta_fill5x5_;
	TBranch *lep2_sigmaIEtaEta_fill5x5_branch;
	bool lep2_sigmaIEtaEta_fill5x5_isLoaded;
	float	lep2_dEtaIn_;
	TBranch *lep2_dEtaIn_branch;
	bool lep2_dEtaIn_isLoaded;
	float	lep2_dPhiIn_;
	TBranch *lep2_dPhiIn_branch;
	bool lep2_dPhiIn_isLoaded;
	float	lep2_hOverE_;
	TBranch *lep2_hOverE_branch;
	bool lep2_hOverE_isLoaded;
	float	lep2_ooEmooP_;
	TBranch *lep2_ooEmooP_branch;
	bool lep2_ooEmooP_isLoaded;
	int	lep2_expectedMissingInnerHits_;
	TBranch *lep2_expectedMissingInnerHits_branch;
	bool lep2_expectedMissingInnerHits_isLoaded;
	bool	lep2_conversionVeto_;
	TBranch *lep2_conversionVeto_branch;
	bool lep2_conversionVeto_isLoaded;
	float	lep2_etaSC_;
	TBranch *lep2_etaSC_branch;
	bool lep2_etaSC_isLoaded;
	float	lep2_ChiSqr_;
	TBranch *lep2_ChiSqr_branch;
	bool lep2_ChiSqr_isLoaded;
	float	lep2_chiso_;
	TBranch *lep2_chiso_branch;
	bool lep2_chiso_isLoaded;
	float	lep2_nhiso_;
	TBranch *lep2_nhiso_branch;
	bool lep2_nhiso_isLoaded;
	float	lep2_emiso_;
	TBranch *lep2_emiso_branch;
	bool lep2_emiso_isLoaded;
	float	lep2_deltaBeta_;
	TBranch *lep2_deltaBeta_branch;
	bool lep2_deltaBeta_isLoaded;
	float	lep2_relIso03DB_;
	TBranch *lep2_relIso03DB_branch;
	bool lep2_relIso03DB_isLoaded;
	float	lep2_relIso03EA_;
	TBranch *lep2_relIso03EA_branch;
	bool lep2_relIso03EA_isLoaded;
	float	lep2_relIso04DB_;
	TBranch *lep2_relIso04DB_branch;
	bool lep2_relIso04DB_isLoaded;
	float	lep2_miniRelIsoDB_;
	TBranch *lep2_miniRelIsoDB_branch;
	bool lep2_miniRelIsoDB_isLoaded;
	float	lep2_miniRelIsoEA_;
	TBranch *lep2_miniRelIsoEA_branch;
	bool lep2_miniRelIsoEA_isLoaded;
	float	lep2_MiniIso_;
	TBranch *lep2_MiniIso_branch;
	bool lep2_MiniIso_isLoaded;
	int	lep2_mcid_;
	TBranch *lep2_mcid_branch;
	bool lep2_mcid_isLoaded;
	int	lep2_mcstatus_;
	TBranch *lep2_mcstatus_branch;
	bool lep2_mcstatus_isLoaded;
	int	lep2_mc3dr_;
	TBranch *lep2_mc3dr_branch;
	bool lep2_mc3dr_isLoaded;
	int	lep2_mc3id_;
	TBranch *lep2_mc3id_branch;
	bool lep2_mc3id_isLoaded;
	int	lep2_mc3idx_;
	TBranch *lep2_mc3idx_branch;
	bool lep2_mc3idx_isLoaded;
	int	lep2_mc3motherid_;
	TBranch *lep2_mc3motherid_branch;
	bool lep2_mc3motherid_isLoaded;
	int	lep2_mc3motheridx_;
	TBranch *lep2_mc3motheridx_branch;
	bool lep2_mc3motheridx_isLoaded;
	bool	lep2_is_eleid_loose_;
	TBranch *lep2_is_eleid_loose_branch;
	bool lep2_is_eleid_loose_isLoaded;
	bool	lep2_is_eleid_medium_;
	TBranch *lep2_is_eleid_medium_branch;
	bool lep2_is_eleid_medium_isLoaded;
	bool	lep2_is_eleid_tight_;
	TBranch *lep2_is_eleid_tight_branch;
	bool lep2_is_eleid_tight_isLoaded;
	bool	lep2_is_phys14_loose_noIso_;
	TBranch *lep2_is_phys14_loose_noIso_branch;
	bool lep2_is_phys14_loose_noIso_isLoaded;
	bool	lep2_is_phys14_medium_noIso_;
	TBranch *lep2_is_phys14_medium_noIso_branch;
	bool lep2_is_phys14_medium_noIso_isLoaded;
	bool	lep2_is_phys14_tight_noIso_;
	TBranch *lep2_is_phys14_tight_noIso_branch;
	bool lep2_is_phys14_tight_noIso_isLoaded;
	float	lep2_eoverpin_;
	TBranch *lep2_eoverpin_branch;
	bool lep2_eoverpin_isLoaded;
	bool	lep2_is_muoid_loose_;
	TBranch *lep2_is_muoid_loose_branch;
	bool lep2_is_muoid_loose_isLoaded;
	bool	lep2_is_muoid_medium_;
	TBranch *lep2_is_muoid_medium_branch;
	bool lep2_is_muoid_medium_isLoaded;
	bool	lep2_is_muoid_tight_;
	TBranch *lep2_is_muoid_tight_branch;
	bool lep2_is_muoid_tight_isLoaded;
	float	lep2_ip3d_;
	TBranch *lep2_ip3d_branch;
	bool lep2_ip3d_isLoaded;
	float	lep2_ip3derr_;
	TBranch *lep2_ip3derr_branch;
	bool lep2_ip3derr_isLoaded;
	bool	lep2_is_pfmu_;
	TBranch *lep2_is_pfmu_branch;
	bool lep2_is_pfmu_isLoaded;
	bool	lep2_passMediumID_;
	TBranch *lep2_passMediumID_branch;
	bool lep2_passMediumID_isLoaded;
	bool	lep2_passVeto_;
	TBranch *lep2_passVeto_branch;
	bool lep2_passVeto_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep2_p4_;
	TBranch *lep2_p4_branch;
	bool lep2_p4_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep2_mcp4_;
	TBranch *lep2_mcp4_branch;
	bool lep2_mcp4_isLoaded;
	float	lep2_pt_;
	TBranch *lep2_pt_branch;
	bool lep2_pt_isLoaded;
	float	lep2_eta_;
	TBranch *lep2_eta_branch;
	bool lep2_eta_isLoaded;
	float	lep2_phi_;
	TBranch *lep2_phi_branch;
	bool lep2_phi_isLoaded;
	float	lep2_mass_;
	TBranch *lep2_mass_branch;
	bool lep2_mass_isLoaded;
	int	nGoodGenJets_;
	TBranch *nGoodGenJets_branch;
	bool nGoodGenJets_isLoaded;
	int	ngoodjets_;
	TBranch *ngoodjets_branch;
	bool ngoodjets_isLoaded;
	int	nfailjets_;
	TBranch *nfailjets_branch;
	bool nfailjets_isLoaded;
	int	ak8GoodPFJets_;
	TBranch *ak8GoodPFJets_branch;
	bool ak8GoodPFJets_isLoaded;
	int	ngoodbtags_;
	TBranch *ngoodbtags_branch;
	bool ngoodbtags_isLoaded;
	float	ak4_HT_;
	TBranch *ak4_HT_branch;
	bool ak4_HT_isLoaded;
	float	ak4_htssm_;
	TBranch *ak4_htssm_branch;
	bool ak4_htssm_isLoaded;
	float	ak4_htosm_;
	TBranch *ak4_htosm_branch;
	bool ak4_htosm_isLoaded;
	float	ak4_htratiom_;
	TBranch *ak4_htratiom_branch;
	bool ak4_htratiom_isLoaded;
	vector<float> *dphi_ak4pfjet_met_;
	TBranch *dphi_ak4pfjet_met_branch;
	bool dphi_ak4pfjet_met_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *ak4pfjets_p4_;
	TBranch *ak4pfjets_p4_branch;
	bool ak4pfjets_p4_isLoaded;
	vector<float> *ak4pfjets_pt_;
	TBranch *ak4pfjets_pt_branch;
	bool ak4pfjets_pt_isLoaded;
	vector<float> *ak4pfjets_eta_;
	TBranch *ak4pfjets_eta_branch;
	bool ak4pfjets_eta_isLoaded;
	vector<float> *ak4pfjets_phi_;
	TBranch *ak4pfjets_phi_branch;
	bool ak4pfjets_phi_isLoaded;
	vector<float> *ak4pfjets_mass_;
	TBranch *ak4pfjets_mass_branch;
	bool ak4pfjets_mass_isLoaded;
	vector<bool> *ak4pfjets_passMEDbtag_;
	TBranch *ak4pfjets_passMEDbtag_branch;
	bool ak4pfjets_passMEDbtag_isLoaded;
	vector<float> *ak4pfjets_qg_disc_;
	TBranch *ak4pfjets_qg_disc_branch;
	bool ak4pfjets_qg_disc_isLoaded;
	vector<float> *ak4pfjets_CSV_;
	TBranch *ak4pfjets_CSV_branch;
	bool ak4pfjets_CSV_isLoaded;
	vector<float> *ak4pfjets_puid_;
	TBranch *ak4pfjets_puid_branch;
	bool ak4pfjets_puid_isLoaded;
	vector<int> *ak4pfjets_parton_flavor_;
	TBranch *ak4pfjets_parton_flavor_branch;
	bool ak4pfjets_parton_flavor_isLoaded;
	vector<bool> *ak4pfjets_loose_puid_;
	TBranch *ak4pfjets_loose_puid_branch;
	bool ak4pfjets_loose_puid_isLoaded;
	vector<bool> *ak4pfjets_loose_pfid_;
	TBranch *ak4pfjets_loose_pfid_branch;
	bool ak4pfjets_loose_pfid_isLoaded;
	vector<bool> *ak4pfjets_medium_pfid_;
	TBranch *ak4pfjets_medium_pfid_branch;
	bool ak4pfjets_medium_pfid_isLoaded;
	vector<bool> *ak4pfjets_tight_pfid_;
	TBranch *ak4pfjets_tight_pfid_branch;
	bool ak4pfjets_tight_pfid_isLoaded;
	vector<float> *ak4pfjets_MEDbjet_pt_;
	TBranch *ak4pfjets_MEDbjet_pt_branch;
	bool ak4pfjets_MEDbjet_pt_isLoaded;
	float	ak4pfjets_leadMEDbjet_pt_;
	TBranch *ak4pfjets_leadMEDbjet_pt_branch;
	bool ak4pfjets_leadMEDbjet_pt_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *ak4pfjets_leadMEDbjet_p4_;
	TBranch *ak4pfjets_leadMEDbjet_p4_branch;
	bool ak4pfjets_leadMEDbjet_p4_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *ak4pfjets_leadbtag_p4_;
	TBranch *ak4pfjets_leadbtag_p4_branch;
	bool ak4pfjets_leadbtag_p4_isLoaded;
	vector<float> *ak4pfjets_chf_;
	TBranch *ak4pfjets_chf_branch;
	bool ak4pfjets_chf_isLoaded;
	vector<float> *ak4pfjets_nhf_;
	TBranch *ak4pfjets_nhf_branch;
	bool ak4pfjets_nhf_isLoaded;
	vector<float> *ak4pfjets_cef_;
	TBranch *ak4pfjets_cef_branch;
	bool ak4pfjets_cef_isLoaded;
	vector<float> *ak4pfjets_nef_;
	TBranch *ak4pfjets_nef_branch;
	bool ak4pfjets_nef_isLoaded;
	vector<float> *ak4pfjets_muf_;
	TBranch *ak4pfjets_muf_branch;
	bool ak4pfjets_muf_isLoaded;
	vector<int> *ak4pfjets_cm_;
	TBranch *ak4pfjets_cm_branch;
	bool ak4pfjets_cm_isLoaded;
	vector<int> *ak4pfjets_nm_;
	TBranch *ak4pfjets_nm_branch;
	bool ak4pfjets_nm_isLoaded;
	vector<int> *ak4pfjets_mc3dr_;
	TBranch *ak4pfjets_mc3dr_branch;
	bool ak4pfjets_mc3dr_isLoaded;
	vector<int> *ak4pfjets_mc3id_;
	TBranch *ak4pfjets_mc3id_branch;
	bool ak4pfjets_mc3id_isLoaded;
	vector<int> *ak4pfjets_mc3idx_;
	TBranch *ak4pfjets_mc3idx_branch;
	bool ak4pfjets_mc3idx_isLoaded;
	vector<int> *ak4pfjets_mcmotherid_;
	TBranch *ak4pfjets_mcmotherid_branch;
	bool ak4pfjets_mcmotherid_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *ak4pfjet_overlep1_p4_;
	TBranch *ak4pfjet_overlep1_p4_branch;
	bool ak4pfjet_overlep1_p4_isLoaded;
	float	ak4pfjet_overlep1_CSV_;
	TBranch *ak4pfjet_overlep1_CSV_branch;
	bool ak4pfjet_overlep1_CSV_isLoaded;
	float	ak4pfjet_overlep1_pu_id_;
	TBranch *ak4pfjet_overlep1_pu_id_branch;
	bool ak4pfjet_overlep1_pu_id_isLoaded;
	float	ak4pfjet_overlep1_chf_;
	TBranch *ak4pfjet_overlep1_chf_branch;
	bool ak4pfjet_overlep1_chf_isLoaded;
	float	ak4pfjet_overlep1_nhf_;
	TBranch *ak4pfjet_overlep1_nhf_branch;
	bool ak4pfjet_overlep1_nhf_isLoaded;
	float	ak4pfjet_overlep1_cef_;
	TBranch *ak4pfjet_overlep1_cef_branch;
	bool ak4pfjet_overlep1_cef_isLoaded;
	float	ak4pfjet_overlep1_nef_;
	TBranch *ak4pfjet_overlep1_nef_branch;
	bool ak4pfjet_overlep1_nef_isLoaded;
	float	ak4pfjet_overlep1_muf_;
	TBranch *ak4pfjet_overlep1_muf_branch;
	bool ak4pfjet_overlep1_muf_isLoaded;
	int	ak4pfjet_overlep1_cm_;
	TBranch *ak4pfjet_overlep1_cm_branch;
	bool ak4pfjet_overlep1_cm_isLoaded;
	int	ak4pfjet_overlep1_nm_;
	TBranch *ak4pfjet_overlep1_nm_branch;
	bool ak4pfjet_overlep1_nm_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *ak4pfjet_overlep2_p4_;
	TBranch *ak4pfjet_overlep2_p4_branch;
	bool ak4pfjet_overlep2_p4_isLoaded;
	float	ak4pfjet_overlep2_CSV_;
	TBranch *ak4pfjet_overlep2_CSV_branch;
	bool ak4pfjet_overlep2_CSV_isLoaded;
	float	ak4pfjet_overlep2_pu_id_;
	TBranch *ak4pfjet_overlep2_pu_id_branch;
	bool ak4pfjet_overlep2_pu_id_isLoaded;
	float	ak4pfjet_overlep2_chf_;
	TBranch *ak4pfjet_overlep2_chf_branch;
	bool ak4pfjet_overlep2_chf_isLoaded;
	float	ak4pfjet_overlep2_nhf_;
	TBranch *ak4pfjet_overlep2_nhf_branch;
	bool ak4pfjet_overlep2_nhf_isLoaded;
	float	ak4pfjet_overlep2_cef_;
	TBranch *ak4pfjet_overlep2_cef_branch;
	bool ak4pfjet_overlep2_cef_isLoaded;
	float	ak4pfjet_overlep2_nef_;
	TBranch *ak4pfjet_overlep2_nef_branch;
	bool ak4pfjet_overlep2_nef_isLoaded;
	float	ak4pfjet_overlep2_muf_;
	TBranch *ak4pfjet_overlep2_muf_branch;
	bool ak4pfjet_overlep2_muf_isLoaded;
	int	ak4pfjet_overlep2_cm_;
	TBranch *ak4pfjet_overlep2_cm_branch;
	bool ak4pfjet_overlep2_cm_isLoaded;
	int	ak4pfjet_overlep2_nm_;
	TBranch *ak4pfjet_overlep2_nm_branch;
	bool ak4pfjet_overlep2_nm_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *ak8pfjets_p4_;
	TBranch *ak8pfjets_p4_branch;
	bool ak8pfjets_p4_isLoaded;
	vector<float> *ak8pfjets_tau1_;
	TBranch *ak8pfjets_tau1_branch;
	bool ak8pfjets_tau1_isLoaded;
	vector<float> *ak8pfjets_tau2_;
	TBranch *ak8pfjets_tau2_branch;
	bool ak8pfjets_tau2_isLoaded;
	vector<float> *ak8pfjets_tau3_;
	TBranch *ak8pfjets_tau3_branch;
	bool ak8pfjets_tau3_isLoaded;
	vector<float> *ak8pfjets_top_mass_;
	TBranch *ak8pfjets_top_mass_branch;
	bool ak8pfjets_top_mass_isLoaded;
	vector<float> *ak8pfjets_pruned_mass_;
	TBranch *ak8pfjets_pruned_mass_branch;
	bool ak8pfjets_pruned_mass_isLoaded;
	vector<float> *ak8pfjets_trimmed_mass_;
	TBranch *ak8pfjets_trimmed_mass_branch;
	bool ak8pfjets_trimmed_mass_isLoaded;
	vector<float> *ak8pfjets_filtered_mass_;
	TBranch *ak8pfjets_filtered_mass_branch;
	bool ak8pfjets_filtered_mass_isLoaded;
	vector<float> *ak8pfjets_pu_id_;
	TBranch *ak8pfjets_pu_id_branch;
	bool ak8pfjets_pu_id_isLoaded;
	vector<int> *ak8pfjets_parton_flavor_;
	TBranch *ak8pfjets_parton_flavor_branch;
	bool ak8pfjets_parton_flavor_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *ak4genjets_p4_;
	TBranch *ak4genjets_p4_branch;
	bool ak4genjets_p4_isLoaded;
	vector<TString> *tau_IDnames_;
	TBranch *tau_IDnames_branch;
	bool tau_IDnames_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *tau_leadtrack_p4_;
	TBranch *tau_leadtrack_p4_branch;
	bool tau_leadtrack_p4_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *tau_leadneutral_p4_;
	TBranch *tau_leadneutral_p4_branch;
	bool tau_leadneutral_p4_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *tau_p4_;
	TBranch *tau_p4_branch;
	bool tau_p4_isLoaded;
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > *tau_isocand_p4_;
	TBranch *tau_isocand_p4_branch;
	bool tau_isocand_p4_isLoaded;
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > *tau_sigcand_p4_;
	TBranch *tau_sigcand_p4_branch;
	bool tau_sigcand_p4_isLoaded;
	vector<float> *tau_mass_;
	TBranch *tau_mass_branch;
	bool tau_mass_isLoaded;
	vector<vector<float> > *tau_ID_;
	TBranch *tau_ID_branch;
	bool tau_ID_isLoaded;
	vector<float> *tau_passID_;
	TBranch *tau_passID_branch;
	bool tau_passID_isLoaded;
	vector<float> *tau_charge_;
	TBranch *tau_charge_branch;
	bool tau_charge_isLoaded;
	int	ngoodtaus_;
	TBranch *ngoodtaus_branch;
	bool ngoodtaus_isLoaded;
	vector<float> *tau_againstMuonTight_;
	TBranch *tau_againstMuonTight_branch;
	bool tau_againstMuonTight_isLoaded;
	vector<float> *tau_againstElectronLoose_;
	TBranch *tau_againstElectronLoose_branch;
	bool tau_againstElectronLoose_isLoaded;
	vector<bool> *tau_isVetoTau_;
	TBranch *tau_isVetoTau_branch;
	bool tau_isVetoTau_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *isoTracks_p4_;
	TBranch *isoTracks_p4_branch;
	bool isoTracks_p4_isLoaded;
	vector<int> *isoTracks_charge_;
	TBranch *isoTracks_charge_branch;
	bool isoTracks_charge_isLoaded;
	vector<float> *isoTracks_absIso_;
	TBranch *isoTracks_absIso_branch;
	bool isoTracks_absIso_isLoaded;
	vector<float> *isoTracks_dz_;
	TBranch *isoTracks_dz_branch;
	bool isoTracks_dz_isLoaded;
	vector<int> *isoTracks_pdgId_;
	TBranch *isoTracks_pdgId_branch;
	bool isoTracks_pdgId_isLoaded;
	vector<int> *isoTracks_selectedidx_;
	TBranch *isoTracks_selectedidx_branch;
	bool isoTracks_selectedidx_isLoaded;
	int	isoTracks_nselected_;
	TBranch *isoTracks_nselected_branch;
	bool isoTracks_nselected_isLoaded;
	vector<bool> *isoTracks_isVetoTrack_;
	TBranch *isoTracks_isVetoTrack_branch;
	bool isoTracks_isVetoTrack_isLoaded;
	vector<bool> *isoTracks_isVetoTrack_v2_;
	TBranch *isoTracks_isVetoTrack_v2_branch;
	bool isoTracks_isVetoTrack_v2_isLoaded;
	vector<bool> *isoTracks_isVetoTrack_v3_;
	TBranch *isoTracks_isVetoTrack_v3_branch;
	bool isoTracks_isVetoTrack_v3_isLoaded;
	vector<bool> *genels_isfromt_;
	TBranch *genels_isfromt_branch;
	bool genels_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genels_p4_;
	TBranch *genels_p4_branch;
	bool genels_p4_isLoaded;
	vector<float> *genels_charge_;
	TBranch *genels_charge_branch;
	bool genels_charge_isLoaded;
	vector<float> *genels_iso_;
	TBranch *genels_iso_branch;
	bool genels_iso_isLoaded;
	vector<float> *genels_mass_;
	TBranch *genels_mass_branch;
	bool genels_mass_isLoaded;
	vector<int> *genels_id_;
	TBranch *genels_id_branch;
	bool genels_id_isLoaded;
	vector<int> *genels__genpsidx_;
	TBranch *genels__genpsidx_branch;
	bool genels__genpsidx_isLoaded;
	vector<int> *genels_status_;
	TBranch *genels_status_branch;
	bool genels_status_isLoaded;
	vector<bool> *genels_fromHardProcessBeforeFSR_;
	TBranch *genels_fromHardProcessBeforeFSR_branch;
	bool genels_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genels_fromHardProcessDecayed_;
	TBranch *genels_fromHardProcessDecayed_branch;
	bool genels_fromHardProcessDecayed_isLoaded;
	vector<bool> *genels_fromHardProcessFinalState_;
	TBranch *genels_fromHardProcessFinalState_branch;
	bool genels_fromHardProcessFinalState_isLoaded;
	vector<bool> *genels_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genels_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genels_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genels_isDirectPromptTauDecayProductFinalState_;
	TBranch *genels_isDirectPromptTauDecayProductFinalState_branch;
	bool genels_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genels_isHardProcess_;
	TBranch *genels_isHardProcess_branch;
	bool genels_isHardProcess_isLoaded;
	vector<bool> *genels_isLastCopy_;
	TBranch *genels_isLastCopy_branch;
	bool genels_isLastCopy_isLoaded;
	vector<bool> *genels_isLastCopyBeforeFSR_;
	TBranch *genels_isLastCopyBeforeFSR_branch;
	bool genels_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genels_isMostlyLikePythia6Status3_;
	TBranch *genels_isMostlyLikePythia6Status3_branch;
	bool genels_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genels_isPromptDecayed_;
	TBranch *genels_isPromptDecayed_branch;
	bool genels_isPromptDecayed_isLoaded;
	vector<bool> *genels_isPromptFinalState_;
	TBranch *genels_isPromptFinalState_branch;
	bool genels_isPromptFinalState_isLoaded;
	vector<vector<int> > *genels_lepdaughter_id_;
	TBranch *genels_lepdaughter_id_branch;
	bool genels_lepdaughter_id_isLoaded;
	vector<int> *genels_gentaudecay_;
	TBranch *genels_gentaudecay_branch;
	bool genels_gentaudecay_isLoaded;
	int	gen_nfromtels__;
	TBranch *gen_nfromtels__branch;
	bool gen_nfromtels__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genels_motherp4_;
	TBranch *genels_motherp4_branch;
	bool genels_motherp4_isLoaded;
	vector<float> *genels_mothercharge_;
	TBranch *genels_mothercharge_branch;
	bool genels_mothercharge_isLoaded;
	vector<int> *genels_motherid_;
	TBranch *genels_motherid_branch;
	bool genels_motherid_isLoaded;
	vector<int> *genels_motheridx_;
	TBranch *genels_motheridx_branch;
	bool genels_motheridx_isLoaded;
	vector<int> *genels_motherstatus_;
	TBranch *genels_motherstatus_branch;
	bool genels_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genels_gmotherp4_;
	TBranch *genels_gmotherp4_branch;
	bool genels_gmotherp4_isLoaded;
	vector<int> *genels_gmothercharge_;
	TBranch *genels_gmothercharge_branch;
	bool genels_gmothercharge_isLoaded;
	vector<int> *genels_gmotherid_;
	TBranch *genels_gmotherid_branch;
	bool genels_gmotherid_isLoaded;
	vector<int> *genels_gmotheridx_;
	TBranch *genels_gmotheridx_branch;
	bool genels_gmotheridx_isLoaded;
	vector<int> *genels_gmotherstatus_;
	TBranch *genels_gmotherstatus_branch;
	bool genels_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genels_simplemotherp4_;
	TBranch *genels_simplemotherp4_branch;
	bool genels_simplemotherp4_isLoaded;
	vector<int> *genels_simplemothercharge_;
	TBranch *genels_simplemothercharge_branch;
	bool genels_simplemothercharge_isLoaded;
	vector<int> *genels_simplemotherid_;
	TBranch *genels_simplemotherid_branch;
	bool genels_simplemotherid_isLoaded;
	vector<int> *genels_simplemotheridx_;
	TBranch *genels_simplemotheridx_branch;
	bool genels_simplemotheridx_isLoaded;
	vector<int> *genels_simplemotherstatus_;
	TBranch *genels_simplemotherstatus_branch;
	bool genels_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genels_simplegmotherp4_;
	TBranch *genels_simplegmotherp4_branch;
	bool genels_simplegmotherp4_isLoaded;
	vector<int> *genels_simplegmothercharge_;
	TBranch *genels_simplegmothercharge_branch;
	bool genels_simplegmothercharge_isLoaded;
	vector<int> *genels_simplegmotherid_;
	TBranch *genels_simplegmotherid_branch;
	bool genels_simplegmotherid_isLoaded;
	vector<int> *genels_simplegmotheridx_;
	TBranch *genels_simplegmotheridx_branch;
	bool genels_simplegmotheridx_isLoaded;
	vector<int> *genels_simplegmotherstatus_;
	TBranch *genels_simplegmotherstatus_branch;
	bool genels_simplegmotherstatus_isLoaded;
	vector<bool> *genmus_isfromt_;
	TBranch *genmus_isfromt_branch;
	bool genmus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genmus_p4_;
	TBranch *genmus_p4_branch;
	bool genmus_p4_isLoaded;
	vector<float> *genmus_charge_;
	TBranch *genmus_charge_branch;
	bool genmus_charge_isLoaded;
	vector<float> *genmus_iso_;
	TBranch *genmus_iso_branch;
	bool genmus_iso_isLoaded;
	vector<float> *genmus_mass_;
	TBranch *genmus_mass_branch;
	bool genmus_mass_isLoaded;
	vector<int> *genmus_id_;
	TBranch *genmus_id_branch;
	bool genmus_id_isLoaded;
	vector<int> *genmus__genpsidx_;
	TBranch *genmus__genpsidx_branch;
	bool genmus__genpsidx_isLoaded;
	vector<int> *genmus_status_;
	TBranch *genmus_status_branch;
	bool genmus_status_isLoaded;
	vector<bool> *genmus_fromHardProcessBeforeFSR_;
	TBranch *genmus_fromHardProcessBeforeFSR_branch;
	bool genmus_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genmus_fromHardProcessDecayed_;
	TBranch *genmus_fromHardProcessDecayed_branch;
	bool genmus_fromHardProcessDecayed_isLoaded;
	vector<bool> *genmus_fromHardProcessFinalState_;
	TBranch *genmus_fromHardProcessFinalState_branch;
	bool genmus_fromHardProcessFinalState_isLoaded;
	vector<bool> *genmus_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genmus_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genmus_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genmus_isDirectPromptTauDecayProductFinalState_;
	TBranch *genmus_isDirectPromptTauDecayProductFinalState_branch;
	bool genmus_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genmus_isHardProcess_;
	TBranch *genmus_isHardProcess_branch;
	bool genmus_isHardProcess_isLoaded;
	vector<bool> *genmus_isLastCopy_;
	TBranch *genmus_isLastCopy_branch;
	bool genmus_isLastCopy_isLoaded;
	vector<bool> *genmus_isLastCopyBeforeFSR_;
	TBranch *genmus_isLastCopyBeforeFSR_branch;
	bool genmus_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genmus_isMostlyLikePythia6Status3_;
	TBranch *genmus_isMostlyLikePythia6Status3_branch;
	bool genmus_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genmus_isPromptDecayed_;
	TBranch *genmus_isPromptDecayed_branch;
	bool genmus_isPromptDecayed_isLoaded;
	vector<bool> *genmus_isPromptFinalState_;
	TBranch *genmus_isPromptFinalState_branch;
	bool genmus_isPromptFinalState_isLoaded;
	vector<vector<int> > *genmus_lepdaughter_id_;
	TBranch *genmus_lepdaughter_id_branch;
	bool genmus_lepdaughter_id_isLoaded;
	vector<int> *genmus_gentaudecay_;
	TBranch *genmus_gentaudecay_branch;
	bool genmus_gentaudecay_isLoaded;
	int	gen_nfromtmus__;
	TBranch *gen_nfromtmus__branch;
	bool gen_nfromtmus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genmus_motherp4_;
	TBranch *genmus_motherp4_branch;
	bool genmus_motherp4_isLoaded;
	vector<float> *genmus_mothercharge_;
	TBranch *genmus_mothercharge_branch;
	bool genmus_mothercharge_isLoaded;
	vector<int> *genmus_motherid_;
	TBranch *genmus_motherid_branch;
	bool genmus_motherid_isLoaded;
	vector<int> *genmus_motheridx_;
	TBranch *genmus_motheridx_branch;
	bool genmus_motheridx_isLoaded;
	vector<int> *genmus_motherstatus_;
	TBranch *genmus_motherstatus_branch;
	bool genmus_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genmus_gmotherp4_;
	TBranch *genmus_gmotherp4_branch;
	bool genmus_gmotherp4_isLoaded;
	vector<int> *genmus_gmothercharge_;
	TBranch *genmus_gmothercharge_branch;
	bool genmus_gmothercharge_isLoaded;
	vector<int> *genmus_gmotherid_;
	TBranch *genmus_gmotherid_branch;
	bool genmus_gmotherid_isLoaded;
	vector<int> *genmus_gmotheridx_;
	TBranch *genmus_gmotheridx_branch;
	bool genmus_gmotheridx_isLoaded;
	vector<int> *genmus_gmotherstatus_;
	TBranch *genmus_gmotherstatus_branch;
	bool genmus_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genmus_simplemotherp4_;
	TBranch *genmus_simplemotherp4_branch;
	bool genmus_simplemotherp4_isLoaded;
	vector<int> *genmus_simplemothercharge_;
	TBranch *genmus_simplemothercharge_branch;
	bool genmus_simplemothercharge_isLoaded;
	vector<int> *genmus_simplemotherid_;
	TBranch *genmus_simplemotherid_branch;
	bool genmus_simplemotherid_isLoaded;
	vector<int> *genmus_simplemotheridx_;
	TBranch *genmus_simplemotheridx_branch;
	bool genmus_simplemotheridx_isLoaded;
	vector<int> *genmus_simplemotherstatus_;
	TBranch *genmus_simplemotherstatus_branch;
	bool genmus_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genmus_simplegmotherp4_;
	TBranch *genmus_simplegmotherp4_branch;
	bool genmus_simplegmotherp4_isLoaded;
	vector<int> *genmus_simplegmothercharge_;
	TBranch *genmus_simplegmothercharge_branch;
	bool genmus_simplegmothercharge_isLoaded;
	vector<int> *genmus_simplegmotherid_;
	TBranch *genmus_simplegmotherid_branch;
	bool genmus_simplegmotherid_isLoaded;
	vector<int> *genmus_simplegmotheridx_;
	TBranch *genmus_simplegmotheridx_branch;
	bool genmus_simplegmotheridx_isLoaded;
	vector<int> *genmus_simplegmotherstatus_;
	TBranch *genmus_simplegmotherstatus_branch;
	bool genmus_simplegmotherstatus_isLoaded;
	vector<bool> *gentaus_isfromt_;
	TBranch *gentaus_isfromt_branch;
	bool gentaus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gentaus_p4_;
	TBranch *gentaus_p4_branch;
	bool gentaus_p4_isLoaded;
	vector<float> *gentaus_charge_;
	TBranch *gentaus_charge_branch;
	bool gentaus_charge_isLoaded;
	vector<float> *gentaus_iso_;
	TBranch *gentaus_iso_branch;
	bool gentaus_iso_isLoaded;
	vector<float> *gentaus_mass_;
	TBranch *gentaus_mass_branch;
	bool gentaus_mass_isLoaded;
	vector<int> *gentaus_id_;
	TBranch *gentaus_id_branch;
	bool gentaus_id_isLoaded;
	vector<int> *gentaus__genpsidx_;
	TBranch *gentaus__genpsidx_branch;
	bool gentaus__genpsidx_isLoaded;
	vector<int> *gentaus_status_;
	TBranch *gentaus_status_branch;
	bool gentaus_status_isLoaded;
	vector<bool> *gentaus_fromHardProcessBeforeFSR_;
	TBranch *gentaus_fromHardProcessBeforeFSR_branch;
	bool gentaus_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gentaus_fromHardProcessDecayed_;
	TBranch *gentaus_fromHardProcessDecayed_branch;
	bool gentaus_fromHardProcessDecayed_isLoaded;
	vector<bool> *gentaus_fromHardProcessFinalState_;
	TBranch *gentaus_fromHardProcessFinalState_branch;
	bool gentaus_fromHardProcessFinalState_isLoaded;
	vector<bool> *gentaus_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gentaus_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gentaus_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gentaus_isDirectPromptTauDecayProductFinalState_;
	TBranch *gentaus_isDirectPromptTauDecayProductFinalState_branch;
	bool gentaus_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gentaus_isHardProcess_;
	TBranch *gentaus_isHardProcess_branch;
	bool gentaus_isHardProcess_isLoaded;
	vector<bool> *gentaus_isLastCopy_;
	TBranch *gentaus_isLastCopy_branch;
	bool gentaus_isLastCopy_isLoaded;
	vector<bool> *gentaus_isLastCopyBeforeFSR_;
	TBranch *gentaus_isLastCopyBeforeFSR_branch;
	bool gentaus_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gentaus_isMostlyLikePythia6Status3_;
	TBranch *gentaus_isMostlyLikePythia6Status3_branch;
	bool gentaus_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gentaus_isPromptDecayed_;
	TBranch *gentaus_isPromptDecayed_branch;
	bool gentaus_isPromptDecayed_isLoaded;
	vector<bool> *gentaus_isPromptFinalState_;
	TBranch *gentaus_isPromptFinalState_branch;
	bool gentaus_isPromptFinalState_isLoaded;
	vector<vector<int> > *gentaus_lepdaughter_id_;
	TBranch *gentaus_lepdaughter_id_branch;
	bool gentaus_lepdaughter_id_isLoaded;
	vector<int> *gentaus_gentaudecay_;
	TBranch *gentaus_gentaudecay_branch;
	bool gentaus_gentaudecay_isLoaded;
	int	gen_nfromttaus__;
	TBranch *gen_nfromttaus__branch;
	bool gen_nfromttaus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gentaus_motherp4_;
	TBranch *gentaus_motherp4_branch;
	bool gentaus_motherp4_isLoaded;
	vector<float> *gentaus_mothercharge_;
	TBranch *gentaus_mothercharge_branch;
	bool gentaus_mothercharge_isLoaded;
	vector<int> *gentaus_motherid_;
	TBranch *gentaus_motherid_branch;
	bool gentaus_motherid_isLoaded;
	vector<int> *gentaus_motheridx_;
	TBranch *gentaus_motheridx_branch;
	bool gentaus_motheridx_isLoaded;
	vector<int> *gentaus_motherstatus_;
	TBranch *gentaus_motherstatus_branch;
	bool gentaus_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gentaus_gmotherp4_;
	TBranch *gentaus_gmotherp4_branch;
	bool gentaus_gmotherp4_isLoaded;
	vector<int> *gentaus_gmothercharge_;
	TBranch *gentaus_gmothercharge_branch;
	bool gentaus_gmothercharge_isLoaded;
	vector<int> *gentaus_gmotherid_;
	TBranch *gentaus_gmotherid_branch;
	bool gentaus_gmotherid_isLoaded;
	vector<int> *gentaus_gmotheridx_;
	TBranch *gentaus_gmotheridx_branch;
	bool gentaus_gmotheridx_isLoaded;
	vector<int> *gentaus_gmotherstatus_;
	TBranch *gentaus_gmotherstatus_branch;
	bool gentaus_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gentaus_simplemotherp4_;
	TBranch *gentaus_simplemotherp4_branch;
	bool gentaus_simplemotherp4_isLoaded;
	vector<int> *gentaus_simplemothercharge_;
	TBranch *gentaus_simplemothercharge_branch;
	bool gentaus_simplemothercharge_isLoaded;
	vector<int> *gentaus_simplemotherid_;
	TBranch *gentaus_simplemotherid_branch;
	bool gentaus_simplemotherid_isLoaded;
	vector<int> *gentaus_simplemotheridx_;
	TBranch *gentaus_simplemotheridx_branch;
	bool gentaus_simplemotheridx_isLoaded;
	vector<int> *gentaus_simplemotherstatus_;
	TBranch *gentaus_simplemotherstatus_branch;
	bool gentaus_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gentaus_simplegmotherp4_;
	TBranch *gentaus_simplegmotherp4_branch;
	bool gentaus_simplegmotherp4_isLoaded;
	vector<int> *gentaus_simplegmothercharge_;
	TBranch *gentaus_simplegmothercharge_branch;
	bool gentaus_simplegmothercharge_isLoaded;
	vector<int> *gentaus_simplegmotherid_;
	TBranch *gentaus_simplegmotherid_branch;
	bool gentaus_simplegmotherid_isLoaded;
	vector<int> *gentaus_simplegmotheridx_;
	TBranch *gentaus_simplegmotheridx_branch;
	bool gentaus_simplegmotheridx_isLoaded;
	vector<int> *gentaus_simplegmotherstatus_;
	TBranch *gentaus_simplegmotherstatus_branch;
	bool gentaus_simplegmotherstatus_isLoaded;
	vector<bool> *gennuels_isfromt_;
	TBranch *gennuels_isfromt_branch;
	bool gennuels_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennuels_p4_;
	TBranch *gennuels_p4_branch;
	bool gennuels_p4_isLoaded;
	vector<float> *gennuels_charge_;
	TBranch *gennuels_charge_branch;
	bool gennuels_charge_isLoaded;
	vector<float> *gennuels_iso_;
	TBranch *gennuels_iso_branch;
	bool gennuels_iso_isLoaded;
	vector<float> *gennuels_mass_;
	TBranch *gennuels_mass_branch;
	bool gennuels_mass_isLoaded;
	vector<int> *gennuels_id_;
	TBranch *gennuels_id_branch;
	bool gennuels_id_isLoaded;
	vector<int> *gennuels__genpsidx_;
	TBranch *gennuels__genpsidx_branch;
	bool gennuels__genpsidx_isLoaded;
	vector<int> *gennuels_status_;
	TBranch *gennuels_status_branch;
	bool gennuels_status_isLoaded;
	vector<bool> *gennuels_fromHardProcessBeforeFSR_;
	TBranch *gennuels_fromHardProcessBeforeFSR_branch;
	bool gennuels_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gennuels_fromHardProcessDecayed_;
	TBranch *gennuels_fromHardProcessDecayed_branch;
	bool gennuels_fromHardProcessDecayed_isLoaded;
	vector<bool> *gennuels_fromHardProcessFinalState_;
	TBranch *gennuels_fromHardProcessFinalState_branch;
	bool gennuels_fromHardProcessFinalState_isLoaded;
	vector<bool> *gennuels_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gennuels_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gennuels_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gennuels_isDirectPromptTauDecayProductFinalState_;
	TBranch *gennuels_isDirectPromptTauDecayProductFinalState_branch;
	bool gennuels_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gennuels_isHardProcess_;
	TBranch *gennuels_isHardProcess_branch;
	bool gennuels_isHardProcess_isLoaded;
	vector<bool> *gennuels_isLastCopy_;
	TBranch *gennuels_isLastCopy_branch;
	bool gennuels_isLastCopy_isLoaded;
	vector<bool> *gennuels_isLastCopyBeforeFSR_;
	TBranch *gennuels_isLastCopyBeforeFSR_branch;
	bool gennuels_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gennuels_isMostlyLikePythia6Status3_;
	TBranch *gennuels_isMostlyLikePythia6Status3_branch;
	bool gennuels_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gennuels_isPromptDecayed_;
	TBranch *gennuels_isPromptDecayed_branch;
	bool gennuels_isPromptDecayed_isLoaded;
	vector<bool> *gennuels_isPromptFinalState_;
	TBranch *gennuels_isPromptFinalState_branch;
	bool gennuels_isPromptFinalState_isLoaded;
	vector<vector<int> > *gennuels_lepdaughter_id_;
	TBranch *gennuels_lepdaughter_id_branch;
	bool gennuels_lepdaughter_id_isLoaded;
	vector<int> *gennuels_gentaudecay_;
	TBranch *gennuels_gentaudecay_branch;
	bool gennuels_gentaudecay_isLoaded;
	int	gen_nfromtnuels__;
	TBranch *gen_nfromtnuels__branch;
	bool gen_nfromtnuels__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennuels_motherp4_;
	TBranch *gennuels_motherp4_branch;
	bool gennuels_motherp4_isLoaded;
	vector<float> *gennuels_mothercharge_;
	TBranch *gennuels_mothercharge_branch;
	bool gennuels_mothercharge_isLoaded;
	vector<int> *gennuels_motherid_;
	TBranch *gennuels_motherid_branch;
	bool gennuels_motherid_isLoaded;
	vector<int> *gennuels_motheridx_;
	TBranch *gennuels_motheridx_branch;
	bool gennuels_motheridx_isLoaded;
	vector<int> *gennuels_motherstatus_;
	TBranch *gennuels_motherstatus_branch;
	bool gennuels_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennuels_gmotherp4_;
	TBranch *gennuels_gmotherp4_branch;
	bool gennuels_gmotherp4_isLoaded;
	vector<int> *gennuels_gmothercharge_;
	TBranch *gennuels_gmothercharge_branch;
	bool gennuels_gmothercharge_isLoaded;
	vector<int> *gennuels_gmotherid_;
	TBranch *gennuels_gmotherid_branch;
	bool gennuels_gmotherid_isLoaded;
	vector<int> *gennuels_gmotheridx_;
	TBranch *gennuels_gmotheridx_branch;
	bool gennuels_gmotheridx_isLoaded;
	vector<int> *gennuels_gmotherstatus_;
	TBranch *gennuels_gmotherstatus_branch;
	bool gennuels_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennuels_simplemotherp4_;
	TBranch *gennuels_simplemotherp4_branch;
	bool gennuels_simplemotherp4_isLoaded;
	vector<int> *gennuels_simplemothercharge_;
	TBranch *gennuels_simplemothercharge_branch;
	bool gennuels_simplemothercharge_isLoaded;
	vector<int> *gennuels_simplemotherid_;
	TBranch *gennuels_simplemotherid_branch;
	bool gennuels_simplemotherid_isLoaded;
	vector<int> *gennuels_simplemotheridx_;
	TBranch *gennuels_simplemotheridx_branch;
	bool gennuels_simplemotheridx_isLoaded;
	vector<int> *gennuels_simplemotherstatus_;
	TBranch *gennuels_simplemotherstatus_branch;
	bool gennuels_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennuels_simplegmotherp4_;
	TBranch *gennuels_simplegmotherp4_branch;
	bool gennuels_simplegmotherp4_isLoaded;
	vector<int> *gennuels_simplegmothercharge_;
	TBranch *gennuels_simplegmothercharge_branch;
	bool gennuels_simplegmothercharge_isLoaded;
	vector<int> *gennuels_simplegmotherid_;
	TBranch *gennuels_simplegmotherid_branch;
	bool gennuels_simplegmotherid_isLoaded;
	vector<int> *gennuels_simplegmotheridx_;
	TBranch *gennuels_simplegmotheridx_branch;
	bool gennuels_simplegmotheridx_isLoaded;
	vector<int> *gennuels_simplegmotherstatus_;
	TBranch *gennuels_simplegmotherstatus_branch;
	bool gennuels_simplegmotherstatus_isLoaded;
	vector<bool> *gennumus_isfromt_;
	TBranch *gennumus_isfromt_branch;
	bool gennumus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennumus_p4_;
	TBranch *gennumus_p4_branch;
	bool gennumus_p4_isLoaded;
	vector<float> *gennumus_charge_;
	TBranch *gennumus_charge_branch;
	bool gennumus_charge_isLoaded;
	vector<float> *gennumus_iso_;
	TBranch *gennumus_iso_branch;
	bool gennumus_iso_isLoaded;
	vector<float> *gennumus_mass_;
	TBranch *gennumus_mass_branch;
	bool gennumus_mass_isLoaded;
	vector<int> *gennumus_id_;
	TBranch *gennumus_id_branch;
	bool gennumus_id_isLoaded;
	vector<int> *gennumus__genpsidx_;
	TBranch *gennumus__genpsidx_branch;
	bool gennumus__genpsidx_isLoaded;
	vector<int> *gennumus_status_;
	TBranch *gennumus_status_branch;
	bool gennumus_status_isLoaded;
	vector<bool> *gennumus_fromHardProcessBeforeFSR_;
	TBranch *gennumus_fromHardProcessBeforeFSR_branch;
	bool gennumus_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gennumus_fromHardProcessDecayed_;
	TBranch *gennumus_fromHardProcessDecayed_branch;
	bool gennumus_fromHardProcessDecayed_isLoaded;
	vector<bool> *gennumus_fromHardProcessFinalState_;
	TBranch *gennumus_fromHardProcessFinalState_branch;
	bool gennumus_fromHardProcessFinalState_isLoaded;
	vector<bool> *gennumus_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gennumus_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gennumus_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gennumus_isDirectPromptTauDecayProductFinalState_;
	TBranch *gennumus_isDirectPromptTauDecayProductFinalState_branch;
	bool gennumus_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gennumus_isHardProcess_;
	TBranch *gennumus_isHardProcess_branch;
	bool gennumus_isHardProcess_isLoaded;
	vector<bool> *gennumus_isLastCopy_;
	TBranch *gennumus_isLastCopy_branch;
	bool gennumus_isLastCopy_isLoaded;
	vector<bool> *gennumus_isLastCopyBeforeFSR_;
	TBranch *gennumus_isLastCopyBeforeFSR_branch;
	bool gennumus_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gennumus_isMostlyLikePythia6Status3_;
	TBranch *gennumus_isMostlyLikePythia6Status3_branch;
	bool gennumus_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gennumus_isPromptDecayed_;
	TBranch *gennumus_isPromptDecayed_branch;
	bool gennumus_isPromptDecayed_isLoaded;
	vector<bool> *gennumus_isPromptFinalState_;
	TBranch *gennumus_isPromptFinalState_branch;
	bool gennumus_isPromptFinalState_isLoaded;
	vector<vector<int> > *gennumus_lepdaughter_id_;
	TBranch *gennumus_lepdaughter_id_branch;
	bool gennumus_lepdaughter_id_isLoaded;
	vector<int> *gennumus_gentaudecay_;
	TBranch *gennumus_gentaudecay_branch;
	bool gennumus_gentaudecay_isLoaded;
	int	gen_nfromtnumus__;
	TBranch *gen_nfromtnumus__branch;
	bool gen_nfromtnumus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennumus_motherp4_;
	TBranch *gennumus_motherp4_branch;
	bool gennumus_motherp4_isLoaded;
	vector<float> *gennumus_mothercharge_;
	TBranch *gennumus_mothercharge_branch;
	bool gennumus_mothercharge_isLoaded;
	vector<int> *gennumus_motherid_;
	TBranch *gennumus_motherid_branch;
	bool gennumus_motherid_isLoaded;
	vector<int> *gennumus_motheridx_;
	TBranch *gennumus_motheridx_branch;
	bool gennumus_motheridx_isLoaded;
	vector<int> *gennumus_motherstatus_;
	TBranch *gennumus_motherstatus_branch;
	bool gennumus_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennumus_gmotherp4_;
	TBranch *gennumus_gmotherp4_branch;
	bool gennumus_gmotherp4_isLoaded;
	vector<int> *gennumus_gmothercharge_;
	TBranch *gennumus_gmothercharge_branch;
	bool gennumus_gmothercharge_isLoaded;
	vector<int> *gennumus_gmotherid_;
	TBranch *gennumus_gmotherid_branch;
	bool gennumus_gmotherid_isLoaded;
	vector<int> *gennumus_gmotheridx_;
	TBranch *gennumus_gmotheridx_branch;
	bool gennumus_gmotheridx_isLoaded;
	vector<int> *gennumus_gmotherstatus_;
	TBranch *gennumus_gmotherstatus_branch;
	bool gennumus_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennumus_simplemotherp4_;
	TBranch *gennumus_simplemotherp4_branch;
	bool gennumus_simplemotherp4_isLoaded;
	vector<int> *gennumus_simplemothercharge_;
	TBranch *gennumus_simplemothercharge_branch;
	bool gennumus_simplemothercharge_isLoaded;
	vector<int> *gennumus_simplemotherid_;
	TBranch *gennumus_simplemotherid_branch;
	bool gennumus_simplemotherid_isLoaded;
	vector<int> *gennumus_simplemotheridx_;
	TBranch *gennumus_simplemotheridx_branch;
	bool gennumus_simplemotheridx_isLoaded;
	vector<int> *gennumus_simplemotherstatus_;
	TBranch *gennumus_simplemotherstatus_branch;
	bool gennumus_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennumus_simplegmotherp4_;
	TBranch *gennumus_simplegmotherp4_branch;
	bool gennumus_simplegmotherp4_isLoaded;
	vector<int> *gennumus_simplegmothercharge_;
	TBranch *gennumus_simplegmothercharge_branch;
	bool gennumus_simplegmothercharge_isLoaded;
	vector<int> *gennumus_simplegmotherid_;
	TBranch *gennumus_simplegmotherid_branch;
	bool gennumus_simplegmotherid_isLoaded;
	vector<int> *gennumus_simplegmotheridx_;
	TBranch *gennumus_simplegmotheridx_branch;
	bool gennumus_simplegmotheridx_isLoaded;
	vector<int> *gennumus_simplegmotherstatus_;
	TBranch *gennumus_simplegmotherstatus_branch;
	bool gennumus_simplegmotherstatus_isLoaded;
	vector<bool> *gennutaus_isfromt_;
	TBranch *gennutaus_isfromt_branch;
	bool gennutaus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennutaus_p4_;
	TBranch *gennutaus_p4_branch;
	bool gennutaus_p4_isLoaded;
	vector<float> *gennutaus_charge_;
	TBranch *gennutaus_charge_branch;
	bool gennutaus_charge_isLoaded;
	vector<float> *gennutaus_iso_;
	TBranch *gennutaus_iso_branch;
	bool gennutaus_iso_isLoaded;
	vector<float> *gennutaus_mass_;
	TBranch *gennutaus_mass_branch;
	bool gennutaus_mass_isLoaded;
	vector<int> *gennutaus_id_;
	TBranch *gennutaus_id_branch;
	bool gennutaus_id_isLoaded;
	vector<int> *gennutaus__genpsidx_;
	TBranch *gennutaus__genpsidx_branch;
	bool gennutaus__genpsidx_isLoaded;
	vector<int> *gennutaus_status_;
	TBranch *gennutaus_status_branch;
	bool gennutaus_status_isLoaded;
	vector<bool> *gennutaus_fromHardProcessBeforeFSR_;
	TBranch *gennutaus_fromHardProcessBeforeFSR_branch;
	bool gennutaus_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gennutaus_fromHardProcessDecayed_;
	TBranch *gennutaus_fromHardProcessDecayed_branch;
	bool gennutaus_fromHardProcessDecayed_isLoaded;
	vector<bool> *gennutaus_fromHardProcessFinalState_;
	TBranch *gennutaus_fromHardProcessFinalState_branch;
	bool gennutaus_fromHardProcessFinalState_isLoaded;
	vector<bool> *gennutaus_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gennutaus_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gennutaus_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gennutaus_isDirectPromptTauDecayProductFinalState_;
	TBranch *gennutaus_isDirectPromptTauDecayProductFinalState_branch;
	bool gennutaus_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gennutaus_isHardProcess_;
	TBranch *gennutaus_isHardProcess_branch;
	bool gennutaus_isHardProcess_isLoaded;
	vector<bool> *gennutaus_isLastCopy_;
	TBranch *gennutaus_isLastCopy_branch;
	bool gennutaus_isLastCopy_isLoaded;
	vector<bool> *gennutaus_isLastCopyBeforeFSR_;
	TBranch *gennutaus_isLastCopyBeforeFSR_branch;
	bool gennutaus_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gennutaus_isMostlyLikePythia6Status3_;
	TBranch *gennutaus_isMostlyLikePythia6Status3_branch;
	bool gennutaus_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gennutaus_isPromptDecayed_;
	TBranch *gennutaus_isPromptDecayed_branch;
	bool gennutaus_isPromptDecayed_isLoaded;
	vector<bool> *gennutaus_isPromptFinalState_;
	TBranch *gennutaus_isPromptFinalState_branch;
	bool gennutaus_isPromptFinalState_isLoaded;
	vector<vector<int> > *gennutaus_lepdaughter_id_;
	TBranch *gennutaus_lepdaughter_id_branch;
	bool gennutaus_lepdaughter_id_isLoaded;
	vector<int> *gennutaus_gentaudecay_;
	TBranch *gennutaus_gentaudecay_branch;
	bool gennutaus_gentaudecay_isLoaded;
	int	gen_nfromtnutaus__;
	TBranch *gen_nfromtnutaus__branch;
	bool gen_nfromtnutaus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennutaus_motherp4_;
	TBranch *gennutaus_motherp4_branch;
	bool gennutaus_motherp4_isLoaded;
	vector<float> *gennutaus_mothercharge_;
	TBranch *gennutaus_mothercharge_branch;
	bool gennutaus_mothercharge_isLoaded;
	vector<int> *gennutaus_motherid_;
	TBranch *gennutaus_motherid_branch;
	bool gennutaus_motherid_isLoaded;
	vector<int> *gennutaus_motheridx_;
	TBranch *gennutaus_motheridx_branch;
	bool gennutaus_motheridx_isLoaded;
	vector<int> *gennutaus_motherstatus_;
	TBranch *gennutaus_motherstatus_branch;
	bool gennutaus_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennutaus_gmotherp4_;
	TBranch *gennutaus_gmotherp4_branch;
	bool gennutaus_gmotherp4_isLoaded;
	vector<int> *gennutaus_gmothercharge_;
	TBranch *gennutaus_gmothercharge_branch;
	bool gennutaus_gmothercharge_isLoaded;
	vector<int> *gennutaus_gmotherid_;
	TBranch *gennutaus_gmotherid_branch;
	bool gennutaus_gmotherid_isLoaded;
	vector<int> *gennutaus_gmotheridx_;
	TBranch *gennutaus_gmotheridx_branch;
	bool gennutaus_gmotheridx_isLoaded;
	vector<int> *gennutaus_gmotherstatus_;
	TBranch *gennutaus_gmotherstatus_branch;
	bool gennutaus_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennutaus_simplemotherp4_;
	TBranch *gennutaus_simplemotherp4_branch;
	bool gennutaus_simplemotherp4_isLoaded;
	vector<int> *gennutaus_simplemothercharge_;
	TBranch *gennutaus_simplemothercharge_branch;
	bool gennutaus_simplemothercharge_isLoaded;
	vector<int> *gennutaus_simplemotherid_;
	TBranch *gennutaus_simplemotherid_branch;
	bool gennutaus_simplemotherid_isLoaded;
	vector<int> *gennutaus_simplemotheridx_;
	TBranch *gennutaus_simplemotheridx_branch;
	bool gennutaus_simplemotheridx_isLoaded;
	vector<int> *gennutaus_simplemotherstatus_;
	TBranch *gennutaus_simplemotherstatus_branch;
	bool gennutaus_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennutaus_simplegmotherp4_;
	TBranch *gennutaus_simplegmotherp4_branch;
	bool gennutaus_simplegmotherp4_isLoaded;
	vector<int> *gennutaus_simplegmothercharge_;
	TBranch *gennutaus_simplegmothercharge_branch;
	bool gennutaus_simplegmothercharge_isLoaded;
	vector<int> *gennutaus_simplegmotherid_;
	TBranch *gennutaus_simplegmotherid_branch;
	bool gennutaus_simplegmotherid_isLoaded;
	vector<int> *gennutaus_simplegmotheridx_;
	TBranch *gennutaus_simplegmotheridx_branch;
	bool gennutaus_simplegmotheridx_isLoaded;
	vector<int> *gennutaus_simplegmotherstatus_;
	TBranch *gennutaus_simplegmotherstatus_branch;
	bool gennutaus_simplegmotherstatus_isLoaded;
	vector<bool> *gents_isfromt_;
	TBranch *gents_isfromt_branch;
	bool gents_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gents_p4_;
	TBranch *gents_p4_branch;
	bool gents_p4_isLoaded;
	vector<float> *gents_charge_;
	TBranch *gents_charge_branch;
	bool gents_charge_isLoaded;
	vector<float> *gents_iso_;
	TBranch *gents_iso_branch;
	bool gents_iso_isLoaded;
	vector<float> *gents_mass_;
	TBranch *gents_mass_branch;
	bool gents_mass_isLoaded;
	vector<int> *gents_id_;
	TBranch *gents_id_branch;
	bool gents_id_isLoaded;
	vector<int> *gents__genpsidx_;
	TBranch *gents__genpsidx_branch;
	bool gents__genpsidx_isLoaded;
	vector<int> *gents_status_;
	TBranch *gents_status_branch;
	bool gents_status_isLoaded;
	vector<bool> *gents_fromHardProcessBeforeFSR_;
	TBranch *gents_fromHardProcessBeforeFSR_branch;
	bool gents_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gents_fromHardProcessDecayed_;
	TBranch *gents_fromHardProcessDecayed_branch;
	bool gents_fromHardProcessDecayed_isLoaded;
	vector<bool> *gents_fromHardProcessFinalState_;
	TBranch *gents_fromHardProcessFinalState_branch;
	bool gents_fromHardProcessFinalState_isLoaded;
	vector<bool> *gents_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gents_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gents_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gents_isDirectPromptTauDecayProductFinalState_;
	TBranch *gents_isDirectPromptTauDecayProductFinalState_branch;
	bool gents_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gents_isHardProcess_;
	TBranch *gents_isHardProcess_branch;
	bool gents_isHardProcess_isLoaded;
	vector<bool> *gents_isLastCopy_;
	TBranch *gents_isLastCopy_branch;
	bool gents_isLastCopy_isLoaded;
	vector<bool> *gents_isLastCopyBeforeFSR_;
	TBranch *gents_isLastCopyBeforeFSR_branch;
	bool gents_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gents_isMostlyLikePythia6Status3_;
	TBranch *gents_isMostlyLikePythia6Status3_branch;
	bool gents_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gents_isPromptDecayed_;
	TBranch *gents_isPromptDecayed_branch;
	bool gents_isPromptDecayed_isLoaded;
	vector<bool> *gents_isPromptFinalState_;
	TBranch *gents_isPromptFinalState_branch;
	bool gents_isPromptFinalState_isLoaded;
	vector<vector<int> > *gents_lepdaughter_id_;
	TBranch *gents_lepdaughter_id_branch;
	bool gents_lepdaughter_id_isLoaded;
	vector<int> *gents_gentaudecay_;
	TBranch *gents_gentaudecay_branch;
	bool gents_gentaudecay_isLoaded;
	int	gen_nfromtts__;
	TBranch *gen_nfromtts__branch;
	bool gen_nfromtts__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gents_motherp4_;
	TBranch *gents_motherp4_branch;
	bool gents_motherp4_isLoaded;
	vector<float> *gents_mothercharge_;
	TBranch *gents_mothercharge_branch;
	bool gents_mothercharge_isLoaded;
	vector<int> *gents_motherid_;
	TBranch *gents_motherid_branch;
	bool gents_motherid_isLoaded;
	vector<int> *gents_motheridx_;
	TBranch *gents_motheridx_branch;
	bool gents_motheridx_isLoaded;
	vector<int> *gents_motherstatus_;
	TBranch *gents_motherstatus_branch;
	bool gents_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gents_gmotherp4_;
	TBranch *gents_gmotherp4_branch;
	bool gents_gmotherp4_isLoaded;
	vector<int> *gents_gmothercharge_;
	TBranch *gents_gmothercharge_branch;
	bool gents_gmothercharge_isLoaded;
	vector<int> *gents_gmotherid_;
	TBranch *gents_gmotherid_branch;
	bool gents_gmotherid_isLoaded;
	vector<int> *gents_gmotheridx_;
	TBranch *gents_gmotheridx_branch;
	bool gents_gmotheridx_isLoaded;
	vector<int> *gents_gmotherstatus_;
	TBranch *gents_gmotherstatus_branch;
	bool gents_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gents_simplemotherp4_;
	TBranch *gents_simplemotherp4_branch;
	bool gents_simplemotherp4_isLoaded;
	vector<int> *gents_simplemothercharge_;
	TBranch *gents_simplemothercharge_branch;
	bool gents_simplemothercharge_isLoaded;
	vector<int> *gents_simplemotherid_;
	TBranch *gents_simplemotherid_branch;
	bool gents_simplemotherid_isLoaded;
	vector<int> *gents_simplemotheridx_;
	TBranch *gents_simplemotheridx_branch;
	bool gents_simplemotheridx_isLoaded;
	vector<int> *gents_simplemotherstatus_;
	TBranch *gents_simplemotherstatus_branch;
	bool gents_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gents_simplegmotherp4_;
	TBranch *gents_simplegmotherp4_branch;
	bool gents_simplegmotherp4_isLoaded;
	vector<int> *gents_simplegmothercharge_;
	TBranch *gents_simplegmothercharge_branch;
	bool gents_simplegmothercharge_isLoaded;
	vector<int> *gents_simplegmotherid_;
	TBranch *gents_simplegmotherid_branch;
	bool gents_simplegmotherid_isLoaded;
	vector<int> *gents_simplegmotheridx_;
	TBranch *gents_simplegmotheridx_branch;
	bool gents_simplegmotheridx_isLoaded;
	vector<int> *gents_simplegmotherstatus_;
	TBranch *gents_simplegmotherstatus_branch;
	bool gents_simplegmotherstatus_isLoaded;
	vector<bool> *genbs_isfromt_;
	TBranch *genbs_isfromt_branch;
	bool genbs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genbs_p4_;
	TBranch *genbs_p4_branch;
	bool genbs_p4_isLoaded;
	vector<float> *genbs_charge_;
	TBranch *genbs_charge_branch;
	bool genbs_charge_isLoaded;
	vector<float> *genbs_iso_;
	TBranch *genbs_iso_branch;
	bool genbs_iso_isLoaded;
	vector<float> *genbs_mass_;
	TBranch *genbs_mass_branch;
	bool genbs_mass_isLoaded;
	vector<int> *genbs_id_;
	TBranch *genbs_id_branch;
	bool genbs_id_isLoaded;
	vector<int> *genbs__genpsidx_;
	TBranch *genbs__genpsidx_branch;
	bool genbs__genpsidx_isLoaded;
	vector<int> *genbs_status_;
	TBranch *genbs_status_branch;
	bool genbs_status_isLoaded;
	vector<bool> *genbs_fromHardProcessBeforeFSR_;
	TBranch *genbs_fromHardProcessBeforeFSR_branch;
	bool genbs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genbs_fromHardProcessDecayed_;
	TBranch *genbs_fromHardProcessDecayed_branch;
	bool genbs_fromHardProcessDecayed_isLoaded;
	vector<bool> *genbs_fromHardProcessFinalState_;
	TBranch *genbs_fromHardProcessFinalState_branch;
	bool genbs_fromHardProcessFinalState_isLoaded;
	vector<bool> *genbs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genbs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genbs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genbs_isDirectPromptTauDecayProductFinalState_;
	TBranch *genbs_isDirectPromptTauDecayProductFinalState_branch;
	bool genbs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genbs_isHardProcess_;
	TBranch *genbs_isHardProcess_branch;
	bool genbs_isHardProcess_isLoaded;
	vector<bool> *genbs_isLastCopy_;
	TBranch *genbs_isLastCopy_branch;
	bool genbs_isLastCopy_isLoaded;
	vector<bool> *genbs_isLastCopyBeforeFSR_;
	TBranch *genbs_isLastCopyBeforeFSR_branch;
	bool genbs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genbs_isMostlyLikePythia6Status3_;
	TBranch *genbs_isMostlyLikePythia6Status3_branch;
	bool genbs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genbs_isPromptDecayed_;
	TBranch *genbs_isPromptDecayed_branch;
	bool genbs_isPromptDecayed_isLoaded;
	vector<bool> *genbs_isPromptFinalState_;
	TBranch *genbs_isPromptFinalState_branch;
	bool genbs_isPromptFinalState_isLoaded;
	vector<vector<int> > *genbs_lepdaughter_id_;
	TBranch *genbs_lepdaughter_id_branch;
	bool genbs_lepdaughter_id_isLoaded;
	vector<int> *genbs_gentaudecay_;
	TBranch *genbs_gentaudecay_branch;
	bool genbs_gentaudecay_isLoaded;
	int	gen_nfromtbs__;
	TBranch *gen_nfromtbs__branch;
	bool gen_nfromtbs__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genbs_motherp4_;
	TBranch *genbs_motherp4_branch;
	bool genbs_motherp4_isLoaded;
	vector<float> *genbs_mothercharge_;
	TBranch *genbs_mothercharge_branch;
	bool genbs_mothercharge_isLoaded;
	vector<int> *genbs_motherid_;
	TBranch *genbs_motherid_branch;
	bool genbs_motherid_isLoaded;
	vector<int> *genbs_motheridx_;
	TBranch *genbs_motheridx_branch;
	bool genbs_motheridx_isLoaded;
	vector<int> *genbs_motherstatus_;
	TBranch *genbs_motherstatus_branch;
	bool genbs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genbs_gmotherp4_;
	TBranch *genbs_gmotherp4_branch;
	bool genbs_gmotherp4_isLoaded;
	vector<int> *genbs_gmothercharge_;
	TBranch *genbs_gmothercharge_branch;
	bool genbs_gmothercharge_isLoaded;
	vector<int> *genbs_gmotherid_;
	TBranch *genbs_gmotherid_branch;
	bool genbs_gmotherid_isLoaded;
	vector<int> *genbs_gmotheridx_;
	TBranch *genbs_gmotheridx_branch;
	bool genbs_gmotheridx_isLoaded;
	vector<int> *genbs_gmotherstatus_;
	TBranch *genbs_gmotherstatus_branch;
	bool genbs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genbs_simplemotherp4_;
	TBranch *genbs_simplemotherp4_branch;
	bool genbs_simplemotherp4_isLoaded;
	vector<int> *genbs_simplemothercharge_;
	TBranch *genbs_simplemothercharge_branch;
	bool genbs_simplemothercharge_isLoaded;
	vector<int> *genbs_simplemotherid_;
	TBranch *genbs_simplemotherid_branch;
	bool genbs_simplemotherid_isLoaded;
	vector<int> *genbs_simplemotheridx_;
	TBranch *genbs_simplemotheridx_branch;
	bool genbs_simplemotheridx_isLoaded;
	vector<int> *genbs_simplemotherstatus_;
	TBranch *genbs_simplemotherstatus_branch;
	bool genbs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genbs_simplegmotherp4_;
	TBranch *genbs_simplegmotherp4_branch;
	bool genbs_simplegmotherp4_isLoaded;
	vector<int> *genbs_simplegmothercharge_;
	TBranch *genbs_simplegmothercharge_branch;
	bool genbs_simplegmothercharge_isLoaded;
	vector<int> *genbs_simplegmotherid_;
	TBranch *genbs_simplegmotherid_branch;
	bool genbs_simplegmotherid_isLoaded;
	vector<int> *genbs_simplegmotheridx_;
	TBranch *genbs_simplegmotheridx_branch;
	bool genbs_simplegmotheridx_isLoaded;
	vector<int> *genbs_simplegmotherstatus_;
	TBranch *genbs_simplegmotherstatus_branch;
	bool genbs_simplegmotherstatus_isLoaded;
	vector<bool> *gencs_isfromt_;
	TBranch *gencs_isfromt_branch;
	bool gencs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gencs_p4_;
	TBranch *gencs_p4_branch;
	bool gencs_p4_isLoaded;
	vector<float> *gencs_charge_;
	TBranch *gencs_charge_branch;
	bool gencs_charge_isLoaded;
	vector<float> *gencs_iso_;
	TBranch *gencs_iso_branch;
	bool gencs_iso_isLoaded;
	vector<float> *gencs_mass_;
	TBranch *gencs_mass_branch;
	bool gencs_mass_isLoaded;
	vector<int> *gencs_id_;
	TBranch *gencs_id_branch;
	bool gencs_id_isLoaded;
	vector<int> *gencs__genpsidx_;
	TBranch *gencs__genpsidx_branch;
	bool gencs__genpsidx_isLoaded;
	vector<int> *gencs_status_;
	TBranch *gencs_status_branch;
	bool gencs_status_isLoaded;
	vector<bool> *gencs_fromHardProcessBeforeFSR_;
	TBranch *gencs_fromHardProcessBeforeFSR_branch;
	bool gencs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *gencs_fromHardProcessDecayed_;
	TBranch *gencs_fromHardProcessDecayed_branch;
	bool gencs_fromHardProcessDecayed_isLoaded;
	vector<bool> *gencs_fromHardProcessFinalState_;
	TBranch *gencs_fromHardProcessFinalState_branch;
	bool gencs_fromHardProcessFinalState_isLoaded;
	vector<bool> *gencs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *gencs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool gencs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *gencs_isDirectPromptTauDecayProductFinalState_;
	TBranch *gencs_isDirectPromptTauDecayProductFinalState_branch;
	bool gencs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *gencs_isHardProcess_;
	TBranch *gencs_isHardProcess_branch;
	bool gencs_isHardProcess_isLoaded;
	vector<bool> *gencs_isLastCopy_;
	TBranch *gencs_isLastCopy_branch;
	bool gencs_isLastCopy_isLoaded;
	vector<bool> *gencs_isLastCopyBeforeFSR_;
	TBranch *gencs_isLastCopyBeforeFSR_branch;
	bool gencs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *gencs_isMostlyLikePythia6Status3_;
	TBranch *gencs_isMostlyLikePythia6Status3_branch;
	bool gencs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *gencs_isPromptDecayed_;
	TBranch *gencs_isPromptDecayed_branch;
	bool gencs_isPromptDecayed_isLoaded;
	vector<bool> *gencs_isPromptFinalState_;
	TBranch *gencs_isPromptFinalState_branch;
	bool gencs_isPromptFinalState_isLoaded;
	vector<vector<int> > *gencs_lepdaughter_id_;
	TBranch *gencs_lepdaughter_id_branch;
	bool gencs_lepdaughter_id_isLoaded;
	vector<int> *gencs_gentaudecay_;
	TBranch *gencs_gentaudecay_branch;
	bool gencs_gentaudecay_isLoaded;
	int	gen_nfromtcs__;
	TBranch *gen_nfromtcs__branch;
	bool gen_nfromtcs__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gencs_motherp4_;
	TBranch *gencs_motherp4_branch;
	bool gencs_motherp4_isLoaded;
	vector<float> *gencs_mothercharge_;
	TBranch *gencs_mothercharge_branch;
	bool gencs_mothercharge_isLoaded;
	vector<int> *gencs_motherid_;
	TBranch *gencs_motherid_branch;
	bool gencs_motherid_isLoaded;
	vector<int> *gencs_motheridx_;
	TBranch *gencs_motheridx_branch;
	bool gencs_motheridx_isLoaded;
	vector<int> *gencs_motherstatus_;
	TBranch *gencs_motherstatus_branch;
	bool gencs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gencs_gmotherp4_;
	TBranch *gencs_gmotherp4_branch;
	bool gencs_gmotherp4_isLoaded;
	vector<int> *gencs_gmothercharge_;
	TBranch *gencs_gmothercharge_branch;
	bool gencs_gmothercharge_isLoaded;
	vector<int> *gencs_gmotherid_;
	TBranch *gencs_gmotherid_branch;
	bool gencs_gmotherid_isLoaded;
	vector<int> *gencs_gmotheridx_;
	TBranch *gencs_gmotheridx_branch;
	bool gencs_gmotheridx_isLoaded;
	vector<int> *gencs_gmotherstatus_;
	TBranch *gencs_gmotherstatus_branch;
	bool gencs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gencs_simplemotherp4_;
	TBranch *gencs_simplemotherp4_branch;
	bool gencs_simplemotherp4_isLoaded;
	vector<int> *gencs_simplemothercharge_;
	TBranch *gencs_simplemothercharge_branch;
	bool gencs_simplemothercharge_isLoaded;
	vector<int> *gencs_simplemotherid_;
	TBranch *gencs_simplemotherid_branch;
	bool gencs_simplemotherid_isLoaded;
	vector<int> *gencs_simplemotheridx_;
	TBranch *gencs_simplemotheridx_branch;
	bool gencs_simplemotheridx_isLoaded;
	vector<int> *gencs_simplemotherstatus_;
	TBranch *gencs_simplemotherstatus_branch;
	bool gencs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gencs_simplegmotherp4_;
	TBranch *gencs_simplegmotherp4_branch;
	bool gencs_simplegmotherp4_isLoaded;
	vector<int> *gencs_simplegmothercharge_;
	TBranch *gencs_simplegmothercharge_branch;
	bool gencs_simplegmothercharge_isLoaded;
	vector<int> *gencs_simplegmotherid_;
	TBranch *gencs_simplegmotherid_branch;
	bool gencs_simplegmotherid_isLoaded;
	vector<int> *gencs_simplegmotheridx_;
	TBranch *gencs_simplegmotheridx_branch;
	bool gencs_simplegmotheridx_isLoaded;
	vector<int> *gencs_simplegmotherstatus_;
	TBranch *gencs_simplegmotherstatus_branch;
	bool gencs_simplegmotherstatus_isLoaded;
	vector<bool> *genqs_isfromt_;
	TBranch *genqs_isfromt_branch;
	bool genqs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genqs_p4_;
	TBranch *genqs_p4_branch;
	bool genqs_p4_isLoaded;
	vector<float> *genqs_charge_;
	TBranch *genqs_charge_branch;
	bool genqs_charge_isLoaded;
	vector<float> *genqs_iso_;
	TBranch *genqs_iso_branch;
	bool genqs_iso_isLoaded;
	vector<float> *genqs_mass_;
	TBranch *genqs_mass_branch;
	bool genqs_mass_isLoaded;
	vector<int> *genqs_id_;
	TBranch *genqs_id_branch;
	bool genqs_id_isLoaded;
	vector<int> *genqs__genpsidx_;
	TBranch *genqs__genpsidx_branch;
	bool genqs__genpsidx_isLoaded;
	vector<int> *genqs_status_;
	TBranch *genqs_status_branch;
	bool genqs_status_isLoaded;
	vector<bool> *genqs_fromHardProcessBeforeFSR_;
	TBranch *genqs_fromHardProcessBeforeFSR_branch;
	bool genqs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genqs_fromHardProcessDecayed_;
	TBranch *genqs_fromHardProcessDecayed_branch;
	bool genqs_fromHardProcessDecayed_isLoaded;
	vector<bool> *genqs_fromHardProcessFinalState_;
	TBranch *genqs_fromHardProcessFinalState_branch;
	bool genqs_fromHardProcessFinalState_isLoaded;
	vector<bool> *genqs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genqs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genqs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genqs_isDirectPromptTauDecayProductFinalState_;
	TBranch *genqs_isDirectPromptTauDecayProductFinalState_branch;
	bool genqs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genqs_isHardProcess_;
	TBranch *genqs_isHardProcess_branch;
	bool genqs_isHardProcess_isLoaded;
	vector<bool> *genqs_isLastCopy_;
	TBranch *genqs_isLastCopy_branch;
	bool genqs_isLastCopy_isLoaded;
	vector<bool> *genqs_isLastCopyBeforeFSR_;
	TBranch *genqs_isLastCopyBeforeFSR_branch;
	bool genqs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genqs_isMostlyLikePythia6Status3_;
	TBranch *genqs_isMostlyLikePythia6Status3_branch;
	bool genqs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genqs_isPromptDecayed_;
	TBranch *genqs_isPromptDecayed_branch;
	bool genqs_isPromptDecayed_isLoaded;
	vector<bool> *genqs_isPromptFinalState_;
	TBranch *genqs_isPromptFinalState_branch;
	bool genqs_isPromptFinalState_isLoaded;
	vector<vector<int> > *genqs_lepdaughter_id_;
	TBranch *genqs_lepdaughter_id_branch;
	bool genqs_lepdaughter_id_isLoaded;
	vector<int> *genqs_gentaudecay_;
	TBranch *genqs_gentaudecay_branch;
	bool genqs_gentaudecay_isLoaded;
	int	gen_nfromtqs__;
	TBranch *gen_nfromtqs__branch;
	bool gen_nfromtqs__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genqs_motherp4_;
	TBranch *genqs_motherp4_branch;
	bool genqs_motherp4_isLoaded;
	vector<float> *genqs_mothercharge_;
	TBranch *genqs_mothercharge_branch;
	bool genqs_mothercharge_isLoaded;
	vector<int> *genqs_motherid_;
	TBranch *genqs_motherid_branch;
	bool genqs_motherid_isLoaded;
	vector<int> *genqs_motheridx_;
	TBranch *genqs_motheridx_branch;
	bool genqs_motheridx_isLoaded;
	vector<int> *genqs_motherstatus_;
	TBranch *genqs_motherstatus_branch;
	bool genqs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genqs_gmotherp4_;
	TBranch *genqs_gmotherp4_branch;
	bool genqs_gmotherp4_isLoaded;
	vector<int> *genqs_gmothercharge_;
	TBranch *genqs_gmothercharge_branch;
	bool genqs_gmothercharge_isLoaded;
	vector<int> *genqs_gmotherid_;
	TBranch *genqs_gmotherid_branch;
	bool genqs_gmotherid_isLoaded;
	vector<int> *genqs_gmotheridx_;
	TBranch *genqs_gmotheridx_branch;
	bool genqs_gmotheridx_isLoaded;
	vector<int> *genqs_gmotherstatus_;
	TBranch *genqs_gmotherstatus_branch;
	bool genqs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genqs_simplemotherp4_;
	TBranch *genqs_simplemotherp4_branch;
	bool genqs_simplemotherp4_isLoaded;
	vector<int> *genqs_simplemothercharge_;
	TBranch *genqs_simplemothercharge_branch;
	bool genqs_simplemothercharge_isLoaded;
	vector<int> *genqs_simplemotherid_;
	TBranch *genqs_simplemotherid_branch;
	bool genqs_simplemotherid_isLoaded;
	vector<int> *genqs_simplemotheridx_;
	TBranch *genqs_simplemotheridx_branch;
	bool genqs_simplemotheridx_isLoaded;
	vector<int> *genqs_simplemotherstatus_;
	TBranch *genqs_simplemotherstatus_branch;
	bool genqs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genqs_simplegmotherp4_;
	TBranch *genqs_simplegmotherp4_branch;
	bool genqs_simplegmotherp4_isLoaded;
	vector<int> *genqs_simplegmothercharge_;
	TBranch *genqs_simplegmothercharge_branch;
	bool genqs_simplegmothercharge_isLoaded;
	vector<int> *genqs_simplegmotherid_;
	TBranch *genqs_simplegmotherid_branch;
	bool genqs_simplegmotherid_isLoaded;
	vector<int> *genqs_simplegmotheridx_;
	TBranch *genqs_simplegmotheridx_branch;
	bool genqs_simplegmotheridx_isLoaded;
	vector<int> *genqs_simplegmotherstatus_;
	TBranch *genqs_simplegmotherstatus_branch;
	bool genqs_simplegmotherstatus_isLoaded;
	vector<bool> *genglus_isfromt_;
	TBranch *genglus_isfromt_branch;
	bool genglus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genglus_p4_;
	TBranch *genglus_p4_branch;
	bool genglus_p4_isLoaded;
	vector<float> *genglus_charge_;
	TBranch *genglus_charge_branch;
	bool genglus_charge_isLoaded;
	vector<float> *genglus_iso_;
	TBranch *genglus_iso_branch;
	bool genglus_iso_isLoaded;
	vector<float> *genglus_mass_;
	TBranch *genglus_mass_branch;
	bool genglus_mass_isLoaded;
	vector<int> *genglus_id_;
	TBranch *genglus_id_branch;
	bool genglus_id_isLoaded;
	vector<int> *genglus__genpsidx_;
	TBranch *genglus__genpsidx_branch;
	bool genglus__genpsidx_isLoaded;
	vector<int> *genglus_status_;
	TBranch *genglus_status_branch;
	bool genglus_status_isLoaded;
	vector<bool> *genglus_fromHardProcessBeforeFSR_;
	TBranch *genglus_fromHardProcessBeforeFSR_branch;
	bool genglus_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genglus_fromHardProcessDecayed_;
	TBranch *genglus_fromHardProcessDecayed_branch;
	bool genglus_fromHardProcessDecayed_isLoaded;
	vector<bool> *genglus_fromHardProcessFinalState_;
	TBranch *genglus_fromHardProcessFinalState_branch;
	bool genglus_fromHardProcessFinalState_isLoaded;
	vector<bool> *genglus_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genglus_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genglus_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genglus_isDirectPromptTauDecayProductFinalState_;
	TBranch *genglus_isDirectPromptTauDecayProductFinalState_branch;
	bool genglus_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genglus_isHardProcess_;
	TBranch *genglus_isHardProcess_branch;
	bool genglus_isHardProcess_isLoaded;
	vector<bool> *genglus_isLastCopy_;
	TBranch *genglus_isLastCopy_branch;
	bool genglus_isLastCopy_isLoaded;
	vector<bool> *genglus_isLastCopyBeforeFSR_;
	TBranch *genglus_isLastCopyBeforeFSR_branch;
	bool genglus_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genglus_isMostlyLikePythia6Status3_;
	TBranch *genglus_isMostlyLikePythia6Status3_branch;
	bool genglus_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genglus_isPromptDecayed_;
	TBranch *genglus_isPromptDecayed_branch;
	bool genglus_isPromptDecayed_isLoaded;
	vector<bool> *genglus_isPromptFinalState_;
	TBranch *genglus_isPromptFinalState_branch;
	bool genglus_isPromptFinalState_isLoaded;
	vector<vector<int> > *genglus_lepdaughter_id_;
	TBranch *genglus_lepdaughter_id_branch;
	bool genglus_lepdaughter_id_isLoaded;
	vector<int> *genglus_gentaudecay_;
	TBranch *genglus_gentaudecay_branch;
	bool genglus_gentaudecay_isLoaded;
	int	gen_nfromtglus__;
	TBranch *gen_nfromtglus__branch;
	bool gen_nfromtglus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genglus_motherp4_;
	TBranch *genglus_motherp4_branch;
	bool genglus_motherp4_isLoaded;
	vector<float> *genglus_mothercharge_;
	TBranch *genglus_mothercharge_branch;
	bool genglus_mothercharge_isLoaded;
	vector<int> *genglus_motherid_;
	TBranch *genglus_motherid_branch;
	bool genglus_motherid_isLoaded;
	vector<int> *genglus_motheridx_;
	TBranch *genglus_motheridx_branch;
	bool genglus_motheridx_isLoaded;
	vector<int> *genglus_motherstatus_;
	TBranch *genglus_motherstatus_branch;
	bool genglus_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genglus_gmotherp4_;
	TBranch *genglus_gmotherp4_branch;
	bool genglus_gmotherp4_isLoaded;
	vector<int> *genglus_gmothercharge_;
	TBranch *genglus_gmothercharge_branch;
	bool genglus_gmothercharge_isLoaded;
	vector<int> *genglus_gmotherid_;
	TBranch *genglus_gmotherid_branch;
	bool genglus_gmotherid_isLoaded;
	vector<int> *genglus_gmotheridx_;
	TBranch *genglus_gmotheridx_branch;
	bool genglus_gmotheridx_isLoaded;
	vector<int> *genglus_gmotherstatus_;
	TBranch *genglus_gmotherstatus_branch;
	bool genglus_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genglus_simplemotherp4_;
	TBranch *genglus_simplemotherp4_branch;
	bool genglus_simplemotherp4_isLoaded;
	vector<int> *genglus_simplemothercharge_;
	TBranch *genglus_simplemothercharge_branch;
	bool genglus_simplemothercharge_isLoaded;
	vector<int> *genglus_simplemotherid_;
	TBranch *genglus_simplemotherid_branch;
	bool genglus_simplemotherid_isLoaded;
	vector<int> *genglus_simplemotheridx_;
	TBranch *genglus_simplemotheridx_branch;
	bool genglus_simplemotheridx_isLoaded;
	vector<int> *genglus_simplemotherstatus_;
	TBranch *genglus_simplemotherstatus_branch;
	bool genglus_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genglus_simplegmotherp4_;
	TBranch *genglus_simplegmotherp4_branch;
	bool genglus_simplegmotherp4_isLoaded;
	vector<int> *genglus_simplegmothercharge_;
	TBranch *genglus_simplegmothercharge_branch;
	bool genglus_simplegmothercharge_isLoaded;
	vector<int> *genglus_simplegmotherid_;
	TBranch *genglus_simplegmotherid_branch;
	bool genglus_simplegmotherid_isLoaded;
	vector<int> *genglus_simplegmotheridx_;
	TBranch *genglus_simplegmotheridx_branch;
	bool genglus_simplegmotheridx_isLoaded;
	vector<int> *genglus_simplegmotherstatus_;
	TBranch *genglus_simplegmotherstatus_branch;
	bool genglus_simplegmotherstatus_isLoaded;
	vector<bool> *genws_isfromt_;
	TBranch *genws_isfromt_branch;
	bool genws_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genws_p4_;
	TBranch *genws_p4_branch;
	bool genws_p4_isLoaded;
	vector<float> *genws_charge_;
	TBranch *genws_charge_branch;
	bool genws_charge_isLoaded;
	vector<float> *genws_iso_;
	TBranch *genws_iso_branch;
	bool genws_iso_isLoaded;
	vector<float> *genws_mass_;
	TBranch *genws_mass_branch;
	bool genws_mass_isLoaded;
	vector<int> *genws_id_;
	TBranch *genws_id_branch;
	bool genws_id_isLoaded;
	vector<int> *genws__genpsidx_;
	TBranch *genws__genpsidx_branch;
	bool genws__genpsidx_isLoaded;
	vector<int> *genws_status_;
	TBranch *genws_status_branch;
	bool genws_status_isLoaded;
	vector<bool> *genws_fromHardProcessBeforeFSR_;
	TBranch *genws_fromHardProcessBeforeFSR_branch;
	bool genws_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genws_fromHardProcessDecayed_;
	TBranch *genws_fromHardProcessDecayed_branch;
	bool genws_fromHardProcessDecayed_isLoaded;
	vector<bool> *genws_fromHardProcessFinalState_;
	TBranch *genws_fromHardProcessFinalState_branch;
	bool genws_fromHardProcessFinalState_isLoaded;
	vector<bool> *genws_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genws_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genws_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genws_isDirectPromptTauDecayProductFinalState_;
	TBranch *genws_isDirectPromptTauDecayProductFinalState_branch;
	bool genws_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genws_isHardProcess_;
	TBranch *genws_isHardProcess_branch;
	bool genws_isHardProcess_isLoaded;
	vector<bool> *genws_isLastCopy_;
	TBranch *genws_isLastCopy_branch;
	bool genws_isLastCopy_isLoaded;
	vector<bool> *genws_isLastCopyBeforeFSR_;
	TBranch *genws_isLastCopyBeforeFSR_branch;
	bool genws_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genws_isMostlyLikePythia6Status3_;
	TBranch *genws_isMostlyLikePythia6Status3_branch;
	bool genws_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genws_isPromptDecayed_;
	TBranch *genws_isPromptDecayed_branch;
	bool genws_isPromptDecayed_isLoaded;
	vector<bool> *genws_isPromptFinalState_;
	TBranch *genws_isPromptFinalState_branch;
	bool genws_isPromptFinalState_isLoaded;
	vector<vector<int> > *genws_lepdaughter_id_;
	TBranch *genws_lepdaughter_id_branch;
	bool genws_lepdaughter_id_isLoaded;
	vector<int> *genws_gentaudecay_;
	TBranch *genws_gentaudecay_branch;
	bool genws_gentaudecay_isLoaded;
	int	gen_nfromtws__;
	TBranch *gen_nfromtws__branch;
	bool gen_nfromtws__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genws_motherp4_;
	TBranch *genws_motherp4_branch;
	bool genws_motherp4_isLoaded;
	vector<float> *genws_mothercharge_;
	TBranch *genws_mothercharge_branch;
	bool genws_mothercharge_isLoaded;
	vector<int> *genws_motherid_;
	TBranch *genws_motherid_branch;
	bool genws_motherid_isLoaded;
	vector<int> *genws_motheridx_;
	TBranch *genws_motheridx_branch;
	bool genws_motheridx_isLoaded;
	vector<int> *genws_motherstatus_;
	TBranch *genws_motherstatus_branch;
	bool genws_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genws_gmotherp4_;
	TBranch *genws_gmotherp4_branch;
	bool genws_gmotherp4_isLoaded;
	vector<int> *genws_gmothercharge_;
	TBranch *genws_gmothercharge_branch;
	bool genws_gmothercharge_isLoaded;
	vector<int> *genws_gmotherid_;
	TBranch *genws_gmotherid_branch;
	bool genws_gmotherid_isLoaded;
	vector<int> *genws_gmotheridx_;
	TBranch *genws_gmotheridx_branch;
	bool genws_gmotheridx_isLoaded;
	vector<int> *genws_gmotherstatus_;
	TBranch *genws_gmotherstatus_branch;
	bool genws_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genws_simplemotherp4_;
	TBranch *genws_simplemotherp4_branch;
	bool genws_simplemotherp4_isLoaded;
	vector<int> *genws_simplemothercharge_;
	TBranch *genws_simplemothercharge_branch;
	bool genws_simplemothercharge_isLoaded;
	vector<int> *genws_simplemotherid_;
	TBranch *genws_simplemotherid_branch;
	bool genws_simplemotherid_isLoaded;
	vector<int> *genws_simplemotheridx_;
	TBranch *genws_simplemotheridx_branch;
	bool genws_simplemotheridx_isLoaded;
	vector<int> *genws_simplemotherstatus_;
	TBranch *genws_simplemotherstatus_branch;
	bool genws_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genws_simplegmotherp4_;
	TBranch *genws_simplegmotherp4_branch;
	bool genws_simplegmotherp4_isLoaded;
	vector<int> *genws_simplegmothercharge_;
	TBranch *genws_simplegmothercharge_branch;
	bool genws_simplegmothercharge_isLoaded;
	vector<int> *genws_simplegmotherid_;
	TBranch *genws_simplegmotherid_branch;
	bool genws_simplegmotherid_isLoaded;
	vector<int> *genws_simplegmotheridx_;
	TBranch *genws_simplegmotheridx_branch;
	bool genws_simplegmotheridx_isLoaded;
	vector<int> *genws_simplegmotherstatus_;
	TBranch *genws_simplegmotherstatus_branch;
	bool genws_simplegmotherstatus_isLoaded;
	vector<bool> *genzs_isfromt_;
	TBranch *genzs_isfromt_branch;
	bool genzs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genzs_p4_;
	TBranch *genzs_p4_branch;
	bool genzs_p4_isLoaded;
	vector<float> *genzs_charge_;
	TBranch *genzs_charge_branch;
	bool genzs_charge_isLoaded;
	vector<float> *genzs_iso_;
	TBranch *genzs_iso_branch;
	bool genzs_iso_isLoaded;
	vector<float> *genzs_mass_;
	TBranch *genzs_mass_branch;
	bool genzs_mass_isLoaded;
	vector<int> *genzs_id_;
	TBranch *genzs_id_branch;
	bool genzs_id_isLoaded;
	vector<int> *genzs__genpsidx_;
	TBranch *genzs__genpsidx_branch;
	bool genzs__genpsidx_isLoaded;
	vector<int> *genzs_status_;
	TBranch *genzs_status_branch;
	bool genzs_status_isLoaded;
	vector<bool> *genzs_fromHardProcessBeforeFSR_;
	TBranch *genzs_fromHardProcessBeforeFSR_branch;
	bool genzs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genzs_fromHardProcessDecayed_;
	TBranch *genzs_fromHardProcessDecayed_branch;
	bool genzs_fromHardProcessDecayed_isLoaded;
	vector<bool> *genzs_fromHardProcessFinalState_;
	TBranch *genzs_fromHardProcessFinalState_branch;
	bool genzs_fromHardProcessFinalState_isLoaded;
	vector<bool> *genzs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genzs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genzs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genzs_isDirectPromptTauDecayProductFinalState_;
	TBranch *genzs_isDirectPromptTauDecayProductFinalState_branch;
	bool genzs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genzs_isHardProcess_;
	TBranch *genzs_isHardProcess_branch;
	bool genzs_isHardProcess_isLoaded;
	vector<bool> *genzs_isLastCopy_;
	TBranch *genzs_isLastCopy_branch;
	bool genzs_isLastCopy_isLoaded;
	vector<bool> *genzs_isLastCopyBeforeFSR_;
	TBranch *genzs_isLastCopyBeforeFSR_branch;
	bool genzs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genzs_isMostlyLikePythia6Status3_;
	TBranch *genzs_isMostlyLikePythia6Status3_branch;
	bool genzs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genzs_isPromptDecayed_;
	TBranch *genzs_isPromptDecayed_branch;
	bool genzs_isPromptDecayed_isLoaded;
	vector<bool> *genzs_isPromptFinalState_;
	TBranch *genzs_isPromptFinalState_branch;
	bool genzs_isPromptFinalState_isLoaded;
	vector<vector<int> > *genzs_lepdaughter_id_;
	TBranch *genzs_lepdaughter_id_branch;
	bool genzs_lepdaughter_id_isLoaded;
	vector<int> *genzs_gentaudecay_;
	TBranch *genzs_gentaudecay_branch;
	bool genzs_gentaudecay_isLoaded;
	int	gen_nfromtzs__;
	TBranch *gen_nfromtzs__branch;
	bool gen_nfromtzs__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genzs_motherp4_;
	TBranch *genzs_motherp4_branch;
	bool genzs_motherp4_isLoaded;
	vector<float> *genzs_mothercharge_;
	TBranch *genzs_mothercharge_branch;
	bool genzs_mothercharge_isLoaded;
	vector<int> *genzs_motherid_;
	TBranch *genzs_motherid_branch;
	bool genzs_motherid_isLoaded;
	vector<int> *genzs_motheridx_;
	TBranch *genzs_motheridx_branch;
	bool genzs_motheridx_isLoaded;
	vector<int> *genzs_motherstatus_;
	TBranch *genzs_motherstatus_branch;
	bool genzs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genzs_gmotherp4_;
	TBranch *genzs_gmotherp4_branch;
	bool genzs_gmotherp4_isLoaded;
	vector<int> *genzs_gmothercharge_;
	TBranch *genzs_gmothercharge_branch;
	bool genzs_gmothercharge_isLoaded;
	vector<int> *genzs_gmotherid_;
	TBranch *genzs_gmotherid_branch;
	bool genzs_gmotherid_isLoaded;
	vector<int> *genzs_gmotheridx_;
	TBranch *genzs_gmotheridx_branch;
	bool genzs_gmotheridx_isLoaded;
	vector<int> *genzs_gmotherstatus_;
	TBranch *genzs_gmotherstatus_branch;
	bool genzs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genzs_simplemotherp4_;
	TBranch *genzs_simplemotherp4_branch;
	bool genzs_simplemotherp4_isLoaded;
	vector<int> *genzs_simplemothercharge_;
	TBranch *genzs_simplemothercharge_branch;
	bool genzs_simplemothercharge_isLoaded;
	vector<int> *genzs_simplemotherid_;
	TBranch *genzs_simplemotherid_branch;
	bool genzs_simplemotherid_isLoaded;
	vector<int> *genzs_simplemotheridx_;
	TBranch *genzs_simplemotheridx_branch;
	bool genzs_simplemotheridx_isLoaded;
	vector<int> *genzs_simplemotherstatus_;
	TBranch *genzs_simplemotherstatus_branch;
	bool genzs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genzs_simplegmotherp4_;
	TBranch *genzs_simplegmotherp4_branch;
	bool genzs_simplegmotherp4_isLoaded;
	vector<int> *genzs_simplegmothercharge_;
	TBranch *genzs_simplegmothercharge_branch;
	bool genzs_simplegmothercharge_isLoaded;
	vector<int> *genzs_simplegmotherid_;
	TBranch *genzs_simplegmotherid_branch;
	bool genzs_simplegmotherid_isLoaded;
	vector<int> *genzs_simplegmotheridx_;
	TBranch *genzs_simplegmotheridx_branch;
	bool genzs_simplegmotheridx_isLoaded;
	vector<int> *genzs_simplegmotherstatus_;
	TBranch *genzs_simplegmotherstatus_branch;
	bool genzs_simplegmotherstatus_isLoaded;
	vector<bool> *genphs_isfromt_;
	TBranch *genphs_isfromt_branch;
	bool genphs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genphs_p4_;
	TBranch *genphs_p4_branch;
	bool genphs_p4_isLoaded;
	vector<float> *genphs_charge_;
	TBranch *genphs_charge_branch;
	bool genphs_charge_isLoaded;
	vector<float> *genphs_iso_;
	TBranch *genphs_iso_branch;
	bool genphs_iso_isLoaded;
	vector<float> *genphs_mass_;
	TBranch *genphs_mass_branch;
	bool genphs_mass_isLoaded;
	vector<int> *genphs_id_;
	TBranch *genphs_id_branch;
	bool genphs_id_isLoaded;
	vector<int> *genphs__genpsidx_;
	TBranch *genphs__genpsidx_branch;
	bool genphs__genpsidx_isLoaded;
	vector<int> *genphs_status_;
	TBranch *genphs_status_branch;
	bool genphs_status_isLoaded;
	vector<bool> *genphs_fromHardProcessBeforeFSR_;
	TBranch *genphs_fromHardProcessBeforeFSR_branch;
	bool genphs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genphs_fromHardProcessDecayed_;
	TBranch *genphs_fromHardProcessDecayed_branch;
	bool genphs_fromHardProcessDecayed_isLoaded;
	vector<bool> *genphs_fromHardProcessFinalState_;
	TBranch *genphs_fromHardProcessFinalState_branch;
	bool genphs_fromHardProcessFinalState_isLoaded;
	vector<bool> *genphs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genphs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genphs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genphs_isDirectPromptTauDecayProductFinalState_;
	TBranch *genphs_isDirectPromptTauDecayProductFinalState_branch;
	bool genphs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genphs_isHardProcess_;
	TBranch *genphs_isHardProcess_branch;
	bool genphs_isHardProcess_isLoaded;
	vector<bool> *genphs_isLastCopy_;
	TBranch *genphs_isLastCopy_branch;
	bool genphs_isLastCopy_isLoaded;
	vector<bool> *genphs_isLastCopyBeforeFSR_;
	TBranch *genphs_isLastCopyBeforeFSR_branch;
	bool genphs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genphs_isMostlyLikePythia6Status3_;
	TBranch *genphs_isMostlyLikePythia6Status3_branch;
	bool genphs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genphs_isPromptDecayed_;
	TBranch *genphs_isPromptDecayed_branch;
	bool genphs_isPromptDecayed_isLoaded;
	vector<bool> *genphs_isPromptFinalState_;
	TBranch *genphs_isPromptFinalState_branch;
	bool genphs_isPromptFinalState_isLoaded;
	vector<vector<int> > *genphs_lepdaughter_id_;
	TBranch *genphs_lepdaughter_id_branch;
	bool genphs_lepdaughter_id_isLoaded;
	vector<int> *genphs_gentaudecay_;
	TBranch *genphs_gentaudecay_branch;
	bool genphs_gentaudecay_isLoaded;
	int	gen_nfromtphs__;
	TBranch *gen_nfromtphs__branch;
	bool gen_nfromtphs__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genphs_motherp4_;
	TBranch *genphs_motherp4_branch;
	bool genphs_motherp4_isLoaded;
	vector<float> *genphs_mothercharge_;
	TBranch *genphs_mothercharge_branch;
	bool genphs_mothercharge_isLoaded;
	vector<int> *genphs_motherid_;
	TBranch *genphs_motherid_branch;
	bool genphs_motherid_isLoaded;
	vector<int> *genphs_motheridx_;
	TBranch *genphs_motheridx_branch;
	bool genphs_motheridx_isLoaded;
	vector<int> *genphs_motherstatus_;
	TBranch *genphs_motherstatus_branch;
	bool genphs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genphs_gmotherp4_;
	TBranch *genphs_gmotherp4_branch;
	bool genphs_gmotherp4_isLoaded;
	vector<int> *genphs_gmothercharge_;
	TBranch *genphs_gmothercharge_branch;
	bool genphs_gmothercharge_isLoaded;
	vector<int> *genphs_gmotherid_;
	TBranch *genphs_gmotherid_branch;
	bool genphs_gmotherid_isLoaded;
	vector<int> *genphs_gmotheridx_;
	TBranch *genphs_gmotheridx_branch;
	bool genphs_gmotheridx_isLoaded;
	vector<int> *genphs_gmotherstatus_;
	TBranch *genphs_gmotherstatus_branch;
	bool genphs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genphs_simplemotherp4_;
	TBranch *genphs_simplemotherp4_branch;
	bool genphs_simplemotherp4_isLoaded;
	vector<int> *genphs_simplemothercharge_;
	TBranch *genphs_simplemothercharge_branch;
	bool genphs_simplemothercharge_isLoaded;
	vector<int> *genphs_simplemotherid_;
	TBranch *genphs_simplemotherid_branch;
	bool genphs_simplemotherid_isLoaded;
	vector<int> *genphs_simplemotheridx_;
	TBranch *genphs_simplemotheridx_branch;
	bool genphs_simplemotheridx_isLoaded;
	vector<int> *genphs_simplemotherstatus_;
	TBranch *genphs_simplemotherstatus_branch;
	bool genphs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genphs_simplegmotherp4_;
	TBranch *genphs_simplegmotherp4_branch;
	bool genphs_simplegmotherp4_isLoaded;
	vector<int> *genphs_simplegmothercharge_;
	TBranch *genphs_simplegmothercharge_branch;
	bool genphs_simplegmothercharge_isLoaded;
	vector<int> *genphs_simplegmotherid_;
	TBranch *genphs_simplegmotherid_branch;
	bool genphs_simplegmotherid_isLoaded;
	vector<int> *genphs_simplegmotheridx_;
	TBranch *genphs_simplegmotheridx_branch;
	bool genphs_simplegmotheridx_isLoaded;
	vector<int> *genphs_simplegmotherstatus_;
	TBranch *genphs_simplegmotherstatus_branch;
	bool genphs_simplegmotherstatus_isLoaded;
	vector<bool> *genhs_isfromt_;
	TBranch *genhs_isfromt_branch;
	bool genhs_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genhs_p4_;
	TBranch *genhs_p4_branch;
	bool genhs_p4_isLoaded;
	vector<float> *genhs_charge_;
	TBranch *genhs_charge_branch;
	bool genhs_charge_isLoaded;
	vector<float> *genhs_iso_;
	TBranch *genhs_iso_branch;
	bool genhs_iso_isLoaded;
	vector<float> *genhs_mass_;
	TBranch *genhs_mass_branch;
	bool genhs_mass_isLoaded;
	vector<int> *genhs_id_;
	TBranch *genhs_id_branch;
	bool genhs_id_isLoaded;
	vector<int> *genhs__genpsidx_;
	TBranch *genhs__genpsidx_branch;
	bool genhs__genpsidx_isLoaded;
	vector<int> *genhs_status_;
	TBranch *genhs_status_branch;
	bool genhs_status_isLoaded;
	vector<bool> *genhs_fromHardProcessBeforeFSR_;
	TBranch *genhs_fromHardProcessBeforeFSR_branch;
	bool genhs_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genhs_fromHardProcessDecayed_;
	TBranch *genhs_fromHardProcessDecayed_branch;
	bool genhs_fromHardProcessDecayed_isLoaded;
	vector<bool> *genhs_fromHardProcessFinalState_;
	TBranch *genhs_fromHardProcessFinalState_branch;
	bool genhs_fromHardProcessFinalState_isLoaded;
	vector<bool> *genhs_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genhs_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genhs_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genhs_isDirectPromptTauDecayProductFinalState_;
	TBranch *genhs_isDirectPromptTauDecayProductFinalState_branch;
	bool genhs_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genhs_isHardProcess_;
	TBranch *genhs_isHardProcess_branch;
	bool genhs_isHardProcess_isLoaded;
	vector<bool> *genhs_isLastCopy_;
	TBranch *genhs_isLastCopy_branch;
	bool genhs_isLastCopy_isLoaded;
	vector<bool> *genhs_isLastCopyBeforeFSR_;
	TBranch *genhs_isLastCopyBeforeFSR_branch;
	bool genhs_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genhs_isMostlyLikePythia6Status3_;
	TBranch *genhs_isMostlyLikePythia6Status3_branch;
	bool genhs_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genhs_isPromptDecayed_;
	TBranch *genhs_isPromptDecayed_branch;
	bool genhs_isPromptDecayed_isLoaded;
	vector<bool> *genhs_isPromptFinalState_;
	TBranch *genhs_isPromptFinalState_branch;
	bool genhs_isPromptFinalState_isLoaded;
	vector<vector<int> > *genhs_lepdaughter_id_;
	TBranch *genhs_lepdaughter_id_branch;
	bool genhs_lepdaughter_id_isLoaded;
	vector<int> *genhs_gentaudecay_;
	TBranch *genhs_gentaudecay_branch;
	bool genhs_gentaudecay_isLoaded;
	int	gen_nfromths__;
	TBranch *gen_nfromths__branch;
	bool gen_nfromths__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genhs_motherp4_;
	TBranch *genhs_motherp4_branch;
	bool genhs_motherp4_isLoaded;
	vector<float> *genhs_mothercharge_;
	TBranch *genhs_mothercharge_branch;
	bool genhs_mothercharge_isLoaded;
	vector<int> *genhs_motherid_;
	TBranch *genhs_motherid_branch;
	bool genhs_motherid_isLoaded;
	vector<int> *genhs_motheridx_;
	TBranch *genhs_motheridx_branch;
	bool genhs_motheridx_isLoaded;
	vector<int> *genhs_motherstatus_;
	TBranch *genhs_motherstatus_branch;
	bool genhs_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genhs_gmotherp4_;
	TBranch *genhs_gmotherp4_branch;
	bool genhs_gmotherp4_isLoaded;
	vector<int> *genhs_gmothercharge_;
	TBranch *genhs_gmothercharge_branch;
	bool genhs_gmothercharge_isLoaded;
	vector<int> *genhs_gmotherid_;
	TBranch *genhs_gmotherid_branch;
	bool genhs_gmotherid_isLoaded;
	vector<int> *genhs_gmotheridx_;
	TBranch *genhs_gmotheridx_branch;
	bool genhs_gmotheridx_isLoaded;
	vector<int> *genhs_gmotherstatus_;
	TBranch *genhs_gmotherstatus_branch;
	bool genhs_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genhs_simplemotherp4_;
	TBranch *genhs_simplemotherp4_branch;
	bool genhs_simplemotherp4_isLoaded;
	vector<int> *genhs_simplemothercharge_;
	TBranch *genhs_simplemothercharge_branch;
	bool genhs_simplemothercharge_isLoaded;
	vector<int> *genhs_simplemotherid_;
	TBranch *genhs_simplemotherid_branch;
	bool genhs_simplemotherid_isLoaded;
	vector<int> *genhs_simplemotheridx_;
	TBranch *genhs_simplemotheridx_branch;
	bool genhs_simplemotheridx_isLoaded;
	vector<int> *genhs_simplemotherstatus_;
	TBranch *genhs_simplemotherstatus_branch;
	bool genhs_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genhs_simplegmotherp4_;
	TBranch *genhs_simplegmotherp4_branch;
	bool genhs_simplegmotherp4_isLoaded;
	vector<int> *genhs_simplegmothercharge_;
	TBranch *genhs_simplegmothercharge_branch;
	bool genhs_simplegmothercharge_isLoaded;
	vector<int> *genhs_simplegmotherid_;
	TBranch *genhs_simplegmotherid_branch;
	bool genhs_simplegmotherid_isLoaded;
	vector<int> *genhs_simplegmotheridx_;
	TBranch *genhs_simplegmotheridx_branch;
	bool genhs_simplegmotheridx_isLoaded;
	vector<int> *genhs_simplegmotherstatus_;
	TBranch *genhs_simplegmotherstatus_branch;
	bool genhs_simplegmotherstatus_isLoaded;
	vector<bool> *genlsp_isfromt_;
	TBranch *genlsp_isfromt_branch;
	bool genlsp_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genlsp_p4_;
	TBranch *genlsp_p4_branch;
	bool genlsp_p4_isLoaded;
	vector<float> *genlsp_charge_;
	TBranch *genlsp_charge_branch;
	bool genlsp_charge_isLoaded;
	vector<float> *genlsp_iso_;
	TBranch *genlsp_iso_branch;
	bool genlsp_iso_isLoaded;
	vector<float> *genlsp_mass_;
	TBranch *genlsp_mass_branch;
	bool genlsp_mass_isLoaded;
	vector<int> *genlsp_id_;
	TBranch *genlsp_id_branch;
	bool genlsp_id_isLoaded;
	vector<int> *genlsp__genpsidx_;
	TBranch *genlsp__genpsidx_branch;
	bool genlsp__genpsidx_isLoaded;
	vector<int> *genlsp_status_;
	TBranch *genlsp_status_branch;
	bool genlsp_status_isLoaded;
	vector<bool> *genlsp_fromHardProcessBeforeFSR_;
	TBranch *genlsp_fromHardProcessBeforeFSR_branch;
	bool genlsp_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genlsp_fromHardProcessDecayed_;
	TBranch *genlsp_fromHardProcessDecayed_branch;
	bool genlsp_fromHardProcessDecayed_isLoaded;
	vector<bool> *genlsp_fromHardProcessFinalState_;
	TBranch *genlsp_fromHardProcessFinalState_branch;
	bool genlsp_fromHardProcessFinalState_isLoaded;
	vector<bool> *genlsp_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genlsp_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genlsp_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genlsp_isDirectPromptTauDecayProductFinalState_;
	TBranch *genlsp_isDirectPromptTauDecayProductFinalState_branch;
	bool genlsp_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genlsp_isHardProcess_;
	TBranch *genlsp_isHardProcess_branch;
	bool genlsp_isHardProcess_isLoaded;
	vector<bool> *genlsp_isLastCopy_;
	TBranch *genlsp_isLastCopy_branch;
	bool genlsp_isLastCopy_isLoaded;
	vector<bool> *genlsp_isLastCopyBeforeFSR_;
	TBranch *genlsp_isLastCopyBeforeFSR_branch;
	bool genlsp_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genlsp_isMostlyLikePythia6Status3_;
	TBranch *genlsp_isMostlyLikePythia6Status3_branch;
	bool genlsp_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genlsp_isPromptDecayed_;
	TBranch *genlsp_isPromptDecayed_branch;
	bool genlsp_isPromptDecayed_isLoaded;
	vector<bool> *genlsp_isPromptFinalState_;
	TBranch *genlsp_isPromptFinalState_branch;
	bool genlsp_isPromptFinalState_isLoaded;
	vector<vector<int> > *genlsp_lepdaughter_id_;
	TBranch *genlsp_lepdaughter_id_branch;
	bool genlsp_lepdaughter_id_isLoaded;
	vector<int> *genlsp_gentaudecay_;
	TBranch *genlsp_gentaudecay_branch;
	bool genlsp_gentaudecay_isLoaded;
	int	gen_nfromtlsp__;
	TBranch *gen_nfromtlsp__branch;
	bool gen_nfromtlsp__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genlsp_motherp4_;
	TBranch *genlsp_motherp4_branch;
	bool genlsp_motherp4_isLoaded;
	vector<float> *genlsp_mothercharge_;
	TBranch *genlsp_mothercharge_branch;
	bool genlsp_mothercharge_isLoaded;
	vector<int> *genlsp_motherid_;
	TBranch *genlsp_motherid_branch;
	bool genlsp_motherid_isLoaded;
	vector<int> *genlsp_motheridx_;
	TBranch *genlsp_motheridx_branch;
	bool genlsp_motheridx_isLoaded;
	vector<int> *genlsp_motherstatus_;
	TBranch *genlsp_motherstatus_branch;
	bool genlsp_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genlsp_gmotherp4_;
	TBranch *genlsp_gmotherp4_branch;
	bool genlsp_gmotherp4_isLoaded;
	vector<int> *genlsp_gmothercharge_;
	TBranch *genlsp_gmothercharge_branch;
	bool genlsp_gmothercharge_isLoaded;
	vector<int> *genlsp_gmotherid_;
	TBranch *genlsp_gmotherid_branch;
	bool genlsp_gmotherid_isLoaded;
	vector<int> *genlsp_gmotheridx_;
	TBranch *genlsp_gmotheridx_branch;
	bool genlsp_gmotheridx_isLoaded;
	vector<int> *genlsp_gmotherstatus_;
	TBranch *genlsp_gmotherstatus_branch;
	bool genlsp_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genlsp_simplemotherp4_;
	TBranch *genlsp_simplemotherp4_branch;
	bool genlsp_simplemotherp4_isLoaded;
	vector<int> *genlsp_simplemothercharge_;
	TBranch *genlsp_simplemothercharge_branch;
	bool genlsp_simplemothercharge_isLoaded;
	vector<int> *genlsp_simplemotherid_;
	TBranch *genlsp_simplemotherid_branch;
	bool genlsp_simplemotherid_isLoaded;
	vector<int> *genlsp_simplemotheridx_;
	TBranch *genlsp_simplemotheridx_branch;
	bool genlsp_simplemotheridx_isLoaded;
	vector<int> *genlsp_simplemotherstatus_;
	TBranch *genlsp_simplemotherstatus_branch;
	bool genlsp_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genlsp_simplegmotherp4_;
	TBranch *genlsp_simplegmotherp4_branch;
	bool genlsp_simplegmotherp4_isLoaded;
	vector<int> *genlsp_simplegmothercharge_;
	TBranch *genlsp_simplegmothercharge_branch;
	bool genlsp_simplegmothercharge_isLoaded;
	vector<int> *genlsp_simplegmotherid_;
	TBranch *genlsp_simplegmotherid_branch;
	bool genlsp_simplegmotherid_isLoaded;
	vector<int> *genlsp_simplegmotheridx_;
	TBranch *genlsp_simplegmotheridx_branch;
	bool genlsp_simplegmotheridx_isLoaded;
	vector<int> *genlsp_simplegmotherstatus_;
	TBranch *genlsp_simplegmotherstatus_branch;
	bool genlsp_simplegmotherstatus_isLoaded;
	vector<bool> *genstop_isfromt_;
	TBranch *genstop_isfromt_branch;
	bool genstop_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genstop_p4_;
	TBranch *genstop_p4_branch;
	bool genstop_p4_isLoaded;
	vector<float> *genstop_charge_;
	TBranch *genstop_charge_branch;
	bool genstop_charge_isLoaded;
	vector<float> *genstop_iso_;
	TBranch *genstop_iso_branch;
	bool genstop_iso_isLoaded;
	vector<float> *genstop_mass_;
	TBranch *genstop_mass_branch;
	bool genstop_mass_isLoaded;
	vector<int> *genstop_id_;
	TBranch *genstop_id_branch;
	bool genstop_id_isLoaded;
	vector<int> *genstop__genpsidx_;
	TBranch *genstop__genpsidx_branch;
	bool genstop__genpsidx_isLoaded;
	vector<int> *genstop_status_;
	TBranch *genstop_status_branch;
	bool genstop_status_isLoaded;
	vector<bool> *genstop_fromHardProcessBeforeFSR_;
	TBranch *genstop_fromHardProcessBeforeFSR_branch;
	bool genstop_fromHardProcessBeforeFSR_isLoaded;
	vector<bool> *genstop_fromHardProcessDecayed_;
	TBranch *genstop_fromHardProcessDecayed_branch;
	bool genstop_fromHardProcessDecayed_isLoaded;
	vector<bool> *genstop_fromHardProcessFinalState_;
	TBranch *genstop_fromHardProcessFinalState_branch;
	bool genstop_fromHardProcessFinalState_isLoaded;
	vector<bool> *genstop_isDirectHardProcessTauDecayProductFinalState_;
	TBranch *genstop_isDirectHardProcessTauDecayProductFinalState_branch;
	bool genstop_isDirectHardProcessTauDecayProductFinalState_isLoaded;
	vector<bool> *genstop_isDirectPromptTauDecayProductFinalState_;
	TBranch *genstop_isDirectPromptTauDecayProductFinalState_branch;
	bool genstop_isDirectPromptTauDecayProductFinalState_isLoaded;
	vector<bool> *genstop_isHardProcess_;
	TBranch *genstop_isHardProcess_branch;
	bool genstop_isHardProcess_isLoaded;
	vector<bool> *genstop_isLastCopy_;
	TBranch *genstop_isLastCopy_branch;
	bool genstop_isLastCopy_isLoaded;
	vector<bool> *genstop_isLastCopyBeforeFSR_;
	TBranch *genstop_isLastCopyBeforeFSR_branch;
	bool genstop_isLastCopyBeforeFSR_isLoaded;
	vector<bool> *genstop_isMostlyLikePythia6Status3_;
	TBranch *genstop_isMostlyLikePythia6Status3_branch;
	bool genstop_isMostlyLikePythia6Status3_isLoaded;
	vector<bool> *genstop_isPromptDecayed_;
	TBranch *genstop_isPromptDecayed_branch;
	bool genstop_isPromptDecayed_isLoaded;
	vector<bool> *genstop_isPromptFinalState_;
	TBranch *genstop_isPromptFinalState_branch;
	bool genstop_isPromptFinalState_isLoaded;
	vector<vector<int> > *genstop_lepdaughter_id_;
	TBranch *genstop_lepdaughter_id_branch;
	bool genstop_lepdaughter_id_isLoaded;
	vector<int> *genstop_gentaudecay_;
	TBranch *genstop_gentaudecay_branch;
	bool genstop_gentaudecay_isLoaded;
	int	gen_nfromtstop__;
	TBranch *gen_nfromtstop__branch;
	bool gen_nfromtstop__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genstop_motherp4_;
	TBranch *genstop_motherp4_branch;
	bool genstop_motherp4_isLoaded;
	vector<float> *genstop_mothercharge_;
	TBranch *genstop_mothercharge_branch;
	bool genstop_mothercharge_isLoaded;
	vector<int> *genstop_motherid_;
	TBranch *genstop_motherid_branch;
	bool genstop_motherid_isLoaded;
	vector<int> *genstop_motheridx_;
	TBranch *genstop_motheridx_branch;
	bool genstop_motheridx_isLoaded;
	vector<int> *genstop_motherstatus_;
	TBranch *genstop_motherstatus_branch;
	bool genstop_motherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genstop_gmotherp4_;
	TBranch *genstop_gmotherp4_branch;
	bool genstop_gmotherp4_isLoaded;
	vector<int> *genstop_gmothercharge_;
	TBranch *genstop_gmothercharge_branch;
	bool genstop_gmothercharge_isLoaded;
	vector<int> *genstop_gmotherid_;
	TBranch *genstop_gmotherid_branch;
	bool genstop_gmotherid_isLoaded;
	vector<int> *genstop_gmotheridx_;
	TBranch *genstop_gmotheridx_branch;
	bool genstop_gmotheridx_isLoaded;
	vector<int> *genstop_gmotherstatus_;
	TBranch *genstop_gmotherstatus_branch;
	bool genstop_gmotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genstop_simplemotherp4_;
	TBranch *genstop_simplemotherp4_branch;
	bool genstop_simplemotherp4_isLoaded;
	vector<int> *genstop_simplemothercharge_;
	TBranch *genstop_simplemothercharge_branch;
	bool genstop_simplemothercharge_isLoaded;
	vector<int> *genstop_simplemotherid_;
	TBranch *genstop_simplemotherid_branch;
	bool genstop_simplemotherid_isLoaded;
	vector<int> *genstop_simplemotheridx_;
	TBranch *genstop_simplemotheridx_branch;
	bool genstop_simplemotheridx_isLoaded;
	vector<int> *genstop_simplemotherstatus_;
	TBranch *genstop_simplemotherstatus_branch;
	bool genstop_simplemotherstatus_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genstop_simplegmotherp4_;
	TBranch *genstop_simplegmotherp4_branch;
	bool genstop_simplegmotherp4_isLoaded;
	vector<int> *genstop_simplegmothercharge_;
	TBranch *genstop_simplegmothercharge_branch;
	bool genstop_simplegmothercharge_isLoaded;
	vector<int> *genstop_simplegmotherid_;
	TBranch *genstop_simplegmotherid_branch;
	bool genstop_simplegmotherid_isLoaded;
	vector<int> *genstop_simplegmotheridx_;
	TBranch *genstop_simplegmotheridx_branch;
	bool genstop_simplegmotheridx_isLoaded;
	vector<int> *genstop_simplegmotherstatus_;
	TBranch *genstop_simplegmotherstatus_branch;
	bool genstop_simplegmotherstatus_isLoaded;
public: 
void Init(TTree *tree) {
	firstVtx_posp4_branch = 0;
	if (tree->GetBranch("firstVtx_posp4") != 0) {
		firstVtx_posp4_branch = tree->GetBranch("firstVtx_posp4");
		if (firstVtx_posp4_branch) {firstVtx_posp4_branch->SetAddress(&firstVtx_posp4_);}
	}
	lep1_p4_branch = 0;
	if (tree->GetBranch("lep1_p4") != 0) {
		lep1_p4_branch = tree->GetBranch("lep1_p4");
		if (lep1_p4_branch) {lep1_p4_branch->SetAddress(&lep1_p4_);}
	}
	lep1_mcp4_branch = 0;
	if (tree->GetBranch("lep1_mcp4") != 0) {
		lep1_mcp4_branch = tree->GetBranch("lep1_mcp4");
		if (lep1_mcp4_branch) {lep1_mcp4_branch->SetAddress(&lep1_mcp4_);}
	}
	lep2_p4_branch = 0;
	if (tree->GetBranch("lep2_p4") != 0) {
		lep2_p4_branch = tree->GetBranch("lep2_p4");
		if (lep2_p4_branch) {lep2_p4_branch->SetAddress(&lep2_p4_);}
	}
	lep2_mcp4_branch = 0;
	if (tree->GetBranch("lep2_mcp4") != 0) {
		lep2_mcp4_branch = tree->GetBranch("lep2_mcp4");
		if (lep2_mcp4_branch) {lep2_mcp4_branch->SetAddress(&lep2_mcp4_);}
	}
	ak4pfjets_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_p4") != 0) {
		ak4pfjets_p4_branch = tree->GetBranch("ak4pfjets_p4");
		if (ak4pfjets_p4_branch) {ak4pfjets_p4_branch->SetAddress(&ak4pfjets_p4_);}
	}
	ak4pfjets_leadMEDbjet_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadMEDbjet_p4") != 0) {
		ak4pfjets_leadMEDbjet_p4_branch = tree->GetBranch("ak4pfjets_leadMEDbjet_p4");
		if (ak4pfjets_leadMEDbjet_p4_branch) {ak4pfjets_leadMEDbjet_p4_branch->SetAddress(&ak4pfjets_leadMEDbjet_p4_);}
	}
	ak4pfjets_leadbtag_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadbtag_p4") != 0) {
		ak4pfjets_leadbtag_p4_branch = tree->GetBranch("ak4pfjets_leadbtag_p4");
		if (ak4pfjets_leadbtag_p4_branch) {ak4pfjets_leadbtag_p4_branch->SetAddress(&ak4pfjets_leadbtag_p4_);}
	}
	ak4pfjet_overlep1_p4_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_p4") != 0) {
		ak4pfjet_overlep1_p4_branch = tree->GetBranch("ak4pfjet_overlep1_p4");
		if (ak4pfjet_overlep1_p4_branch) {ak4pfjet_overlep1_p4_branch->SetAddress(&ak4pfjet_overlep1_p4_);}
	}
	ak4pfjet_overlep2_p4_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_p4") != 0) {
		ak4pfjet_overlep2_p4_branch = tree->GetBranch("ak4pfjet_overlep2_p4");
		if (ak4pfjet_overlep2_p4_branch) {ak4pfjet_overlep2_p4_branch->SetAddress(&ak4pfjet_overlep2_p4_);}
	}
	ak8pfjets_p4_branch = 0;
	if (tree->GetBranch("ak8pfjets_p4") != 0) {
		ak8pfjets_p4_branch = tree->GetBranch("ak8pfjets_p4");
		if (ak8pfjets_p4_branch) {ak8pfjets_p4_branch->SetAddress(&ak8pfjets_p4_);}
	}
	ak4genjets_p4_branch = 0;
	if (tree->GetBranch("ak4genjets_p4") != 0) {
		ak4genjets_p4_branch = tree->GetBranch("ak4genjets_p4");
		if (ak4genjets_p4_branch) {ak4genjets_p4_branch->SetAddress(&ak4genjets_p4_);}
	}
	tau_leadtrack_p4_branch = 0;
	if (tree->GetBranch("tau_leadtrack_p4") != 0) {
		tau_leadtrack_p4_branch = tree->GetBranch("tau_leadtrack_p4");
		if (tau_leadtrack_p4_branch) {tau_leadtrack_p4_branch->SetAddress(&tau_leadtrack_p4_);}
	}
	tau_leadneutral_p4_branch = 0;
	if (tree->GetBranch("tau_leadneutral_p4") != 0) {
		tau_leadneutral_p4_branch = tree->GetBranch("tau_leadneutral_p4");
		if (tau_leadneutral_p4_branch) {tau_leadneutral_p4_branch->SetAddress(&tau_leadneutral_p4_);}
	}
	tau_p4_branch = 0;
	if (tree->GetBranch("tau_p4") != 0) {
		tau_p4_branch = tree->GetBranch("tau_p4");
		if (tau_p4_branch) {tau_p4_branch->SetAddress(&tau_p4_);}
	}
	isoTracks_p4_branch = 0;
	if (tree->GetBranch("isoTracks_p4") != 0) {
		isoTracks_p4_branch = tree->GetBranch("isoTracks_p4");
		if (isoTracks_p4_branch) {isoTracks_p4_branch->SetAddress(&isoTracks_p4_);}
	}
	genels_p4_branch = 0;
	if (tree->GetBranch("genels_p4") != 0) {
		genels_p4_branch = tree->GetBranch("genels_p4");
		if (genels_p4_branch) {genels_p4_branch->SetAddress(&genels_p4_);}
	}
	genels_motherp4_branch = 0;
	if (tree->GetBranch("genels_motherp4") != 0) {
		genels_motherp4_branch = tree->GetBranch("genels_motherp4");
		if (genels_motherp4_branch) {genels_motherp4_branch->SetAddress(&genels_motherp4_);}
	}
	genels_gmotherp4_branch = 0;
	if (tree->GetBranch("genels_gmotherp4") != 0) {
		genels_gmotherp4_branch = tree->GetBranch("genels_gmotherp4");
		if (genels_gmotherp4_branch) {genels_gmotherp4_branch->SetAddress(&genels_gmotherp4_);}
	}
	genels_simplemotherp4_branch = 0;
	if (tree->GetBranch("genels_simplemotherp4") != 0) {
		genels_simplemotherp4_branch = tree->GetBranch("genels_simplemotherp4");
		if (genels_simplemotherp4_branch) {genels_simplemotherp4_branch->SetAddress(&genels_simplemotherp4_);}
	}
	genels_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genels_simplegmotherp4") != 0) {
		genels_simplegmotherp4_branch = tree->GetBranch("genels_simplegmotherp4");
		if (genels_simplegmotherp4_branch) {genels_simplegmotherp4_branch->SetAddress(&genels_simplegmotherp4_);}
	}
	genmus_p4_branch = 0;
	if (tree->GetBranch("genmus_p4") != 0) {
		genmus_p4_branch = tree->GetBranch("genmus_p4");
		if (genmus_p4_branch) {genmus_p4_branch->SetAddress(&genmus_p4_);}
	}
	genmus_motherp4_branch = 0;
	if (tree->GetBranch("genmus_motherp4") != 0) {
		genmus_motherp4_branch = tree->GetBranch("genmus_motherp4");
		if (genmus_motherp4_branch) {genmus_motherp4_branch->SetAddress(&genmus_motherp4_);}
	}
	genmus_gmotherp4_branch = 0;
	if (tree->GetBranch("genmus_gmotherp4") != 0) {
		genmus_gmotherp4_branch = tree->GetBranch("genmus_gmotherp4");
		if (genmus_gmotherp4_branch) {genmus_gmotherp4_branch->SetAddress(&genmus_gmotherp4_);}
	}
	genmus_simplemotherp4_branch = 0;
	if (tree->GetBranch("genmus_simplemotherp4") != 0) {
		genmus_simplemotherp4_branch = tree->GetBranch("genmus_simplemotherp4");
		if (genmus_simplemotherp4_branch) {genmus_simplemotherp4_branch->SetAddress(&genmus_simplemotherp4_);}
	}
	genmus_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genmus_simplegmotherp4") != 0) {
		genmus_simplegmotherp4_branch = tree->GetBranch("genmus_simplegmotherp4");
		if (genmus_simplegmotherp4_branch) {genmus_simplegmotherp4_branch->SetAddress(&genmus_simplegmotherp4_);}
	}
	gentaus_p4_branch = 0;
	if (tree->GetBranch("gentaus_p4") != 0) {
		gentaus_p4_branch = tree->GetBranch("gentaus_p4");
		if (gentaus_p4_branch) {gentaus_p4_branch->SetAddress(&gentaus_p4_);}
	}
	gentaus_motherp4_branch = 0;
	if (tree->GetBranch("gentaus_motherp4") != 0) {
		gentaus_motherp4_branch = tree->GetBranch("gentaus_motherp4");
		if (gentaus_motherp4_branch) {gentaus_motherp4_branch->SetAddress(&gentaus_motherp4_);}
	}
	gentaus_gmotherp4_branch = 0;
	if (tree->GetBranch("gentaus_gmotherp4") != 0) {
		gentaus_gmotherp4_branch = tree->GetBranch("gentaus_gmotherp4");
		if (gentaus_gmotherp4_branch) {gentaus_gmotherp4_branch->SetAddress(&gentaus_gmotherp4_);}
	}
	gentaus_simplemotherp4_branch = 0;
	if (tree->GetBranch("gentaus_simplemotherp4") != 0) {
		gentaus_simplemotherp4_branch = tree->GetBranch("gentaus_simplemotherp4");
		if (gentaus_simplemotherp4_branch) {gentaus_simplemotherp4_branch->SetAddress(&gentaus_simplemotherp4_);}
	}
	gentaus_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gentaus_simplegmotherp4") != 0) {
		gentaus_simplegmotherp4_branch = tree->GetBranch("gentaus_simplegmotherp4");
		if (gentaus_simplegmotherp4_branch) {gentaus_simplegmotherp4_branch->SetAddress(&gentaus_simplegmotherp4_);}
	}
	gennuels_p4_branch = 0;
	if (tree->GetBranch("gennuels_p4") != 0) {
		gennuels_p4_branch = tree->GetBranch("gennuels_p4");
		if (gennuels_p4_branch) {gennuels_p4_branch->SetAddress(&gennuels_p4_);}
	}
	gennuels_motherp4_branch = 0;
	if (tree->GetBranch("gennuels_motherp4") != 0) {
		gennuels_motherp4_branch = tree->GetBranch("gennuels_motherp4");
		if (gennuels_motherp4_branch) {gennuels_motherp4_branch->SetAddress(&gennuels_motherp4_);}
	}
	gennuels_gmotherp4_branch = 0;
	if (tree->GetBranch("gennuels_gmotherp4") != 0) {
		gennuels_gmotherp4_branch = tree->GetBranch("gennuels_gmotherp4");
		if (gennuels_gmotherp4_branch) {gennuels_gmotherp4_branch->SetAddress(&gennuels_gmotherp4_);}
	}
	gennuels_simplemotherp4_branch = 0;
	if (tree->GetBranch("gennuels_simplemotherp4") != 0) {
		gennuels_simplemotherp4_branch = tree->GetBranch("gennuels_simplemotherp4");
		if (gennuels_simplemotherp4_branch) {gennuels_simplemotherp4_branch->SetAddress(&gennuels_simplemotherp4_);}
	}
	gennuels_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gennuels_simplegmotherp4") != 0) {
		gennuels_simplegmotherp4_branch = tree->GetBranch("gennuels_simplegmotherp4");
		if (gennuels_simplegmotherp4_branch) {gennuels_simplegmotherp4_branch->SetAddress(&gennuels_simplegmotherp4_);}
	}
	gennumus_p4_branch = 0;
	if (tree->GetBranch("gennumus_p4") != 0) {
		gennumus_p4_branch = tree->GetBranch("gennumus_p4");
		if (gennumus_p4_branch) {gennumus_p4_branch->SetAddress(&gennumus_p4_);}
	}
	gennumus_motherp4_branch = 0;
	if (tree->GetBranch("gennumus_motherp4") != 0) {
		gennumus_motherp4_branch = tree->GetBranch("gennumus_motherp4");
		if (gennumus_motherp4_branch) {gennumus_motherp4_branch->SetAddress(&gennumus_motherp4_);}
	}
	gennumus_gmotherp4_branch = 0;
	if (tree->GetBranch("gennumus_gmotherp4") != 0) {
		gennumus_gmotherp4_branch = tree->GetBranch("gennumus_gmotherp4");
		if (gennumus_gmotherp4_branch) {gennumus_gmotherp4_branch->SetAddress(&gennumus_gmotherp4_);}
	}
	gennumus_simplemotherp4_branch = 0;
	if (tree->GetBranch("gennumus_simplemotherp4") != 0) {
		gennumus_simplemotherp4_branch = tree->GetBranch("gennumus_simplemotherp4");
		if (gennumus_simplemotherp4_branch) {gennumus_simplemotherp4_branch->SetAddress(&gennumus_simplemotherp4_);}
	}
	gennumus_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gennumus_simplegmotherp4") != 0) {
		gennumus_simplegmotherp4_branch = tree->GetBranch("gennumus_simplegmotherp4");
		if (gennumus_simplegmotherp4_branch) {gennumus_simplegmotherp4_branch->SetAddress(&gennumus_simplegmotherp4_);}
	}
	gennutaus_p4_branch = 0;
	if (tree->GetBranch("gennutaus_p4") != 0) {
		gennutaus_p4_branch = tree->GetBranch("gennutaus_p4");
		if (gennutaus_p4_branch) {gennutaus_p4_branch->SetAddress(&gennutaus_p4_);}
	}
	gennutaus_motherp4_branch = 0;
	if (tree->GetBranch("gennutaus_motherp4") != 0) {
		gennutaus_motherp4_branch = tree->GetBranch("gennutaus_motherp4");
		if (gennutaus_motherp4_branch) {gennutaus_motherp4_branch->SetAddress(&gennutaus_motherp4_);}
	}
	gennutaus_gmotherp4_branch = 0;
	if (tree->GetBranch("gennutaus_gmotherp4") != 0) {
		gennutaus_gmotherp4_branch = tree->GetBranch("gennutaus_gmotherp4");
		if (gennutaus_gmotherp4_branch) {gennutaus_gmotherp4_branch->SetAddress(&gennutaus_gmotherp4_);}
	}
	gennutaus_simplemotherp4_branch = 0;
	if (tree->GetBranch("gennutaus_simplemotherp4") != 0) {
		gennutaus_simplemotherp4_branch = tree->GetBranch("gennutaus_simplemotherp4");
		if (gennutaus_simplemotherp4_branch) {gennutaus_simplemotherp4_branch->SetAddress(&gennutaus_simplemotherp4_);}
	}
	gennutaus_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gennutaus_simplegmotherp4") != 0) {
		gennutaus_simplegmotherp4_branch = tree->GetBranch("gennutaus_simplegmotherp4");
		if (gennutaus_simplegmotherp4_branch) {gennutaus_simplegmotherp4_branch->SetAddress(&gennutaus_simplegmotherp4_);}
	}
	gents_p4_branch = 0;
	if (tree->GetBranch("gents_p4") != 0) {
		gents_p4_branch = tree->GetBranch("gents_p4");
		if (gents_p4_branch) {gents_p4_branch->SetAddress(&gents_p4_);}
	}
	gents_motherp4_branch = 0;
	if (tree->GetBranch("gents_motherp4") != 0) {
		gents_motherp4_branch = tree->GetBranch("gents_motherp4");
		if (gents_motherp4_branch) {gents_motherp4_branch->SetAddress(&gents_motherp4_);}
	}
	gents_gmotherp4_branch = 0;
	if (tree->GetBranch("gents_gmotherp4") != 0) {
		gents_gmotherp4_branch = tree->GetBranch("gents_gmotherp4");
		if (gents_gmotherp4_branch) {gents_gmotherp4_branch->SetAddress(&gents_gmotherp4_);}
	}
	gents_simplemotherp4_branch = 0;
	if (tree->GetBranch("gents_simplemotherp4") != 0) {
		gents_simplemotherp4_branch = tree->GetBranch("gents_simplemotherp4");
		if (gents_simplemotherp4_branch) {gents_simplemotherp4_branch->SetAddress(&gents_simplemotherp4_);}
	}
	gents_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gents_simplegmotherp4") != 0) {
		gents_simplegmotherp4_branch = tree->GetBranch("gents_simplegmotherp4");
		if (gents_simplegmotherp4_branch) {gents_simplegmotherp4_branch->SetAddress(&gents_simplegmotherp4_);}
	}
	genbs_p4_branch = 0;
	if (tree->GetBranch("genbs_p4") != 0) {
		genbs_p4_branch = tree->GetBranch("genbs_p4");
		if (genbs_p4_branch) {genbs_p4_branch->SetAddress(&genbs_p4_);}
	}
	genbs_motherp4_branch = 0;
	if (tree->GetBranch("genbs_motherp4") != 0) {
		genbs_motherp4_branch = tree->GetBranch("genbs_motherp4");
		if (genbs_motherp4_branch) {genbs_motherp4_branch->SetAddress(&genbs_motherp4_);}
	}
	genbs_gmotherp4_branch = 0;
	if (tree->GetBranch("genbs_gmotherp4") != 0) {
		genbs_gmotherp4_branch = tree->GetBranch("genbs_gmotherp4");
		if (genbs_gmotherp4_branch) {genbs_gmotherp4_branch->SetAddress(&genbs_gmotherp4_);}
	}
	genbs_simplemotherp4_branch = 0;
	if (tree->GetBranch("genbs_simplemotherp4") != 0) {
		genbs_simplemotherp4_branch = tree->GetBranch("genbs_simplemotherp4");
		if (genbs_simplemotherp4_branch) {genbs_simplemotherp4_branch->SetAddress(&genbs_simplemotherp4_);}
	}
	genbs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genbs_simplegmotherp4") != 0) {
		genbs_simplegmotherp4_branch = tree->GetBranch("genbs_simplegmotherp4");
		if (genbs_simplegmotherp4_branch) {genbs_simplegmotherp4_branch->SetAddress(&genbs_simplegmotherp4_);}
	}
	gencs_p4_branch = 0;
	if (tree->GetBranch("gencs_p4") != 0) {
		gencs_p4_branch = tree->GetBranch("gencs_p4");
		if (gencs_p4_branch) {gencs_p4_branch->SetAddress(&gencs_p4_);}
	}
	gencs_motherp4_branch = 0;
	if (tree->GetBranch("gencs_motherp4") != 0) {
		gencs_motherp4_branch = tree->GetBranch("gencs_motherp4");
		if (gencs_motherp4_branch) {gencs_motherp4_branch->SetAddress(&gencs_motherp4_);}
	}
	gencs_gmotherp4_branch = 0;
	if (tree->GetBranch("gencs_gmotherp4") != 0) {
		gencs_gmotherp4_branch = tree->GetBranch("gencs_gmotherp4");
		if (gencs_gmotherp4_branch) {gencs_gmotherp4_branch->SetAddress(&gencs_gmotherp4_);}
	}
	gencs_simplemotherp4_branch = 0;
	if (tree->GetBranch("gencs_simplemotherp4") != 0) {
		gencs_simplemotherp4_branch = tree->GetBranch("gencs_simplemotherp4");
		if (gencs_simplemotherp4_branch) {gencs_simplemotherp4_branch->SetAddress(&gencs_simplemotherp4_);}
	}
	gencs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("gencs_simplegmotherp4") != 0) {
		gencs_simplegmotherp4_branch = tree->GetBranch("gencs_simplegmotherp4");
		if (gencs_simplegmotherp4_branch) {gencs_simplegmotherp4_branch->SetAddress(&gencs_simplegmotherp4_);}
	}
	genqs_p4_branch = 0;
	if (tree->GetBranch("genqs_p4") != 0) {
		genqs_p4_branch = tree->GetBranch("genqs_p4");
		if (genqs_p4_branch) {genqs_p4_branch->SetAddress(&genqs_p4_);}
	}
	genqs_motherp4_branch = 0;
	if (tree->GetBranch("genqs_motherp4") != 0) {
		genqs_motherp4_branch = tree->GetBranch("genqs_motherp4");
		if (genqs_motherp4_branch) {genqs_motherp4_branch->SetAddress(&genqs_motherp4_);}
	}
	genqs_gmotherp4_branch = 0;
	if (tree->GetBranch("genqs_gmotherp4") != 0) {
		genqs_gmotherp4_branch = tree->GetBranch("genqs_gmotherp4");
		if (genqs_gmotherp4_branch) {genqs_gmotherp4_branch->SetAddress(&genqs_gmotherp4_);}
	}
	genqs_simplemotherp4_branch = 0;
	if (tree->GetBranch("genqs_simplemotherp4") != 0) {
		genqs_simplemotherp4_branch = tree->GetBranch("genqs_simplemotherp4");
		if (genqs_simplemotherp4_branch) {genqs_simplemotherp4_branch->SetAddress(&genqs_simplemotherp4_);}
	}
	genqs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genqs_simplegmotherp4") != 0) {
		genqs_simplegmotherp4_branch = tree->GetBranch("genqs_simplegmotherp4");
		if (genqs_simplegmotherp4_branch) {genqs_simplegmotherp4_branch->SetAddress(&genqs_simplegmotherp4_);}
	}
	genglus_p4_branch = 0;
	if (tree->GetBranch("genglus_p4") != 0) {
		genglus_p4_branch = tree->GetBranch("genglus_p4");
		if (genglus_p4_branch) {genglus_p4_branch->SetAddress(&genglus_p4_);}
	}
	genglus_motherp4_branch = 0;
	if (tree->GetBranch("genglus_motherp4") != 0) {
		genglus_motherp4_branch = tree->GetBranch("genglus_motherp4");
		if (genglus_motherp4_branch) {genglus_motherp4_branch->SetAddress(&genglus_motherp4_);}
	}
	genglus_gmotherp4_branch = 0;
	if (tree->GetBranch("genglus_gmotherp4") != 0) {
		genglus_gmotherp4_branch = tree->GetBranch("genglus_gmotherp4");
		if (genglus_gmotherp4_branch) {genglus_gmotherp4_branch->SetAddress(&genglus_gmotherp4_);}
	}
	genglus_simplemotherp4_branch = 0;
	if (tree->GetBranch("genglus_simplemotherp4") != 0) {
		genglus_simplemotherp4_branch = tree->GetBranch("genglus_simplemotherp4");
		if (genglus_simplemotherp4_branch) {genglus_simplemotherp4_branch->SetAddress(&genglus_simplemotherp4_);}
	}
	genglus_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genglus_simplegmotherp4") != 0) {
		genglus_simplegmotherp4_branch = tree->GetBranch("genglus_simplegmotherp4");
		if (genglus_simplegmotherp4_branch) {genglus_simplegmotherp4_branch->SetAddress(&genglus_simplegmotherp4_);}
	}
	genws_p4_branch = 0;
	if (tree->GetBranch("genws_p4") != 0) {
		genws_p4_branch = tree->GetBranch("genws_p4");
		if (genws_p4_branch) {genws_p4_branch->SetAddress(&genws_p4_);}
	}
	genws_motherp4_branch = 0;
	if (tree->GetBranch("genws_motherp4") != 0) {
		genws_motherp4_branch = tree->GetBranch("genws_motherp4");
		if (genws_motherp4_branch) {genws_motherp4_branch->SetAddress(&genws_motherp4_);}
	}
	genws_gmotherp4_branch = 0;
	if (tree->GetBranch("genws_gmotherp4") != 0) {
		genws_gmotherp4_branch = tree->GetBranch("genws_gmotherp4");
		if (genws_gmotherp4_branch) {genws_gmotherp4_branch->SetAddress(&genws_gmotherp4_);}
	}
	genws_simplemotherp4_branch = 0;
	if (tree->GetBranch("genws_simplemotherp4") != 0) {
		genws_simplemotherp4_branch = tree->GetBranch("genws_simplemotherp4");
		if (genws_simplemotherp4_branch) {genws_simplemotherp4_branch->SetAddress(&genws_simplemotherp4_);}
	}
	genws_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genws_simplegmotherp4") != 0) {
		genws_simplegmotherp4_branch = tree->GetBranch("genws_simplegmotherp4");
		if (genws_simplegmotherp4_branch) {genws_simplegmotherp4_branch->SetAddress(&genws_simplegmotherp4_);}
	}
	genzs_p4_branch = 0;
	if (tree->GetBranch("genzs_p4") != 0) {
		genzs_p4_branch = tree->GetBranch("genzs_p4");
		if (genzs_p4_branch) {genzs_p4_branch->SetAddress(&genzs_p4_);}
	}
	genzs_motherp4_branch = 0;
	if (tree->GetBranch("genzs_motherp4") != 0) {
		genzs_motherp4_branch = tree->GetBranch("genzs_motherp4");
		if (genzs_motherp4_branch) {genzs_motherp4_branch->SetAddress(&genzs_motherp4_);}
	}
	genzs_gmotherp4_branch = 0;
	if (tree->GetBranch("genzs_gmotherp4") != 0) {
		genzs_gmotherp4_branch = tree->GetBranch("genzs_gmotherp4");
		if (genzs_gmotherp4_branch) {genzs_gmotherp4_branch->SetAddress(&genzs_gmotherp4_);}
	}
	genzs_simplemotherp4_branch = 0;
	if (tree->GetBranch("genzs_simplemotherp4") != 0) {
		genzs_simplemotherp4_branch = tree->GetBranch("genzs_simplemotherp4");
		if (genzs_simplemotherp4_branch) {genzs_simplemotherp4_branch->SetAddress(&genzs_simplemotherp4_);}
	}
	genzs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genzs_simplegmotherp4") != 0) {
		genzs_simplegmotherp4_branch = tree->GetBranch("genzs_simplegmotherp4");
		if (genzs_simplegmotherp4_branch) {genzs_simplegmotherp4_branch->SetAddress(&genzs_simplegmotherp4_);}
	}
	genphs_p4_branch = 0;
	if (tree->GetBranch("genphs_p4") != 0) {
		genphs_p4_branch = tree->GetBranch("genphs_p4");
		if (genphs_p4_branch) {genphs_p4_branch->SetAddress(&genphs_p4_);}
	}
	genphs_motherp4_branch = 0;
	if (tree->GetBranch("genphs_motherp4") != 0) {
		genphs_motherp4_branch = tree->GetBranch("genphs_motherp4");
		if (genphs_motherp4_branch) {genphs_motherp4_branch->SetAddress(&genphs_motherp4_);}
	}
	genphs_gmotherp4_branch = 0;
	if (tree->GetBranch("genphs_gmotherp4") != 0) {
		genphs_gmotherp4_branch = tree->GetBranch("genphs_gmotherp4");
		if (genphs_gmotherp4_branch) {genphs_gmotherp4_branch->SetAddress(&genphs_gmotherp4_);}
	}
	genphs_simplemotherp4_branch = 0;
	if (tree->GetBranch("genphs_simplemotherp4") != 0) {
		genphs_simplemotherp4_branch = tree->GetBranch("genphs_simplemotherp4");
		if (genphs_simplemotherp4_branch) {genphs_simplemotherp4_branch->SetAddress(&genphs_simplemotherp4_);}
	}
	genphs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genphs_simplegmotherp4") != 0) {
		genphs_simplegmotherp4_branch = tree->GetBranch("genphs_simplegmotherp4");
		if (genphs_simplegmotherp4_branch) {genphs_simplegmotherp4_branch->SetAddress(&genphs_simplegmotherp4_);}
	}
	genhs_p4_branch = 0;
	if (tree->GetBranch("genhs_p4") != 0) {
		genhs_p4_branch = tree->GetBranch("genhs_p4");
		if (genhs_p4_branch) {genhs_p4_branch->SetAddress(&genhs_p4_);}
	}
	genhs_motherp4_branch = 0;
	if (tree->GetBranch("genhs_motherp4") != 0) {
		genhs_motherp4_branch = tree->GetBranch("genhs_motherp4");
		if (genhs_motherp4_branch) {genhs_motherp4_branch->SetAddress(&genhs_motherp4_);}
	}
	genhs_gmotherp4_branch = 0;
	if (tree->GetBranch("genhs_gmotherp4") != 0) {
		genhs_gmotherp4_branch = tree->GetBranch("genhs_gmotherp4");
		if (genhs_gmotherp4_branch) {genhs_gmotherp4_branch->SetAddress(&genhs_gmotherp4_);}
	}
	genhs_simplemotherp4_branch = 0;
	if (tree->GetBranch("genhs_simplemotherp4") != 0) {
		genhs_simplemotherp4_branch = tree->GetBranch("genhs_simplemotherp4");
		if (genhs_simplemotherp4_branch) {genhs_simplemotherp4_branch->SetAddress(&genhs_simplemotherp4_);}
	}
	genhs_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genhs_simplegmotherp4") != 0) {
		genhs_simplegmotherp4_branch = tree->GetBranch("genhs_simplegmotherp4");
		if (genhs_simplegmotherp4_branch) {genhs_simplegmotherp4_branch->SetAddress(&genhs_simplegmotherp4_);}
	}
	genlsp_p4_branch = 0;
	if (tree->GetBranch("genlsp_p4") != 0) {
		genlsp_p4_branch = tree->GetBranch("genlsp_p4");
		if (genlsp_p4_branch) {genlsp_p4_branch->SetAddress(&genlsp_p4_);}
	}
	genlsp_motherp4_branch = 0;
	if (tree->GetBranch("genlsp_motherp4") != 0) {
		genlsp_motherp4_branch = tree->GetBranch("genlsp_motherp4");
		if (genlsp_motherp4_branch) {genlsp_motherp4_branch->SetAddress(&genlsp_motherp4_);}
	}
	genlsp_gmotherp4_branch = 0;
	if (tree->GetBranch("genlsp_gmotherp4") != 0) {
		genlsp_gmotherp4_branch = tree->GetBranch("genlsp_gmotherp4");
		if (genlsp_gmotherp4_branch) {genlsp_gmotherp4_branch->SetAddress(&genlsp_gmotherp4_);}
	}
	genlsp_simplemotherp4_branch = 0;
	if (tree->GetBranch("genlsp_simplemotherp4") != 0) {
		genlsp_simplemotherp4_branch = tree->GetBranch("genlsp_simplemotherp4");
		if (genlsp_simplemotherp4_branch) {genlsp_simplemotherp4_branch->SetAddress(&genlsp_simplemotherp4_);}
	}
	genlsp_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genlsp_simplegmotherp4") != 0) {
		genlsp_simplegmotherp4_branch = tree->GetBranch("genlsp_simplegmotherp4");
		if (genlsp_simplegmotherp4_branch) {genlsp_simplegmotherp4_branch->SetAddress(&genlsp_simplegmotherp4_);}
	}
	genstop_p4_branch = 0;
	if (tree->GetBranch("genstop_p4") != 0) {
		genstop_p4_branch = tree->GetBranch("genstop_p4");
		if (genstop_p4_branch) {genstop_p4_branch->SetAddress(&genstop_p4_);}
	}
	genstop_motherp4_branch = 0;
	if (tree->GetBranch("genstop_motherp4") != 0) {
		genstop_motherp4_branch = tree->GetBranch("genstop_motherp4");
		if (genstop_motherp4_branch) {genstop_motherp4_branch->SetAddress(&genstop_motherp4_);}
	}
	genstop_gmotherp4_branch = 0;
	if (tree->GetBranch("genstop_gmotherp4") != 0) {
		genstop_gmotherp4_branch = tree->GetBranch("genstop_gmotherp4");
		if (genstop_gmotherp4_branch) {genstop_gmotherp4_branch->SetAddress(&genstop_gmotherp4_);}
	}
	genstop_simplemotherp4_branch = 0;
	if (tree->GetBranch("genstop_simplemotherp4") != 0) {
		genstop_simplemotherp4_branch = tree->GetBranch("genstop_simplemotherp4");
		if (genstop_simplemotherp4_branch) {genstop_simplemotherp4_branch->SetAddress(&genstop_simplemotherp4_);}
	}
	genstop_simplegmotherp4_branch = 0;
	if (tree->GetBranch("genstop_simplegmotherp4") != 0) {
		genstop_simplegmotherp4_branch = tree->GetBranch("genstop_simplegmotherp4");
		if (genstop_simplegmotherp4_branch) {genstop_simplegmotherp4_branch->SetAddress(&genstop_simplegmotherp4_);}
	}
  tree->SetMakeClass(1);
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	ls_branch = 0;
	if (tree->GetBranch("ls") != 0) {
		ls_branch = tree->GetBranch("ls");
		if (ls_branch) {ls_branch->SetAddress(&ls_);}
	}
	evt_branch = 0;
	if (tree->GetBranch("evt") != 0) {
		evt_branch = tree->GetBranch("evt");
		if (evt_branch) {evt_branch->SetAddress(&evt_);}
	}
	nvtxs_branch = 0;
	if (tree->GetBranch("nvtxs") != 0) {
		nvtxs_branch = tree->GetBranch("nvtxs");
		if (nvtxs_branch) {nvtxs_branch->SetAddress(&nvtxs_);}
	}
	firstGoodVtxIdx_branch = 0;
	if (tree->GetBranch("firstGoodVtxIdx") != 0) {
		firstGoodVtxIdx_branch = tree->GetBranch("firstGoodVtxIdx");
		if (firstGoodVtxIdx_branch) {firstGoodVtxIdx_branch->SetAddress(&firstGoodVtxIdx_);}
	}
	firstVtx_isfake_branch = 0;
	if (tree->GetBranch("firstVtx_isfake") != 0) {
		firstVtx_isfake_branch = tree->GetBranch("firstVtx_isfake");
		if (firstVtx_isfake_branch) {firstVtx_isfake_branch->SetAddress(&firstVtx_isfake_);}
	}
	firstVtx_ndof_branch = 0;
	if (tree->GetBranch("firstVtx_ndof") != 0) {
		firstVtx_ndof_branch = tree->GetBranch("firstVtx_ndof");
		if (firstVtx_ndof_branch) {firstVtx_ndof_branch->SetAddress(&firstVtx_ndof_);}
	}
	firstVtx_posRho_branch = 0;
	if (tree->GetBranch("firstVtx_posRho") != 0) {
		firstVtx_posRho_branch = tree->GetBranch("firstVtx_posRho");
		if (firstVtx_posRho_branch) {firstVtx_posRho_branch->SetAddress(&firstVtx_posRho_);}
	}
	firstVtx_posZ_branch = 0;
	if (tree->GetBranch("firstVtx_posZ") != 0) {
		firstVtx_posZ_branch = tree->GetBranch("firstVtx_posZ");
		if (firstVtx_posZ_branch) {firstVtx_posZ_branch->SetAddress(&firstVtx_posZ_);}
	}
	pu_nvtxs_branch = 0;
	if (tree->GetBranch("pu_nvtxs") != 0) {
		pu_nvtxs_branch = tree->GetBranch("pu_nvtxs");
		if (pu_nvtxs_branch) {pu_nvtxs_branch->SetAddress(&pu_nvtxs_);}
	}
	pfmet_branch = 0;
	if (tree->GetBranch("pfmet") != 0) {
		pfmet_branch = tree->GetBranch("pfmet");
		if (pfmet_branch) {pfmet_branch->SetAddress(&pfmet_);}
	}
	pfmet_phi_branch = 0;
	if (tree->GetBranch("pfmet_phi") != 0) {
		pfmet_phi_branch = tree->GetBranch("pfmet_phi");
		if (pfmet_phi_branch) {pfmet_phi_branch->SetAddress(&pfmet_phi_);}
	}
	calomet_branch = 0;
	if (tree->GetBranch("calomet") != 0) {
		calomet_branch = tree->GetBranch("calomet");
		if (calomet_branch) {calomet_branch->SetAddress(&calomet_);}
	}
	calomet_phi_branch = 0;
	if (tree->GetBranch("calomet_phi") != 0) {
		calomet_phi_branch = tree->GetBranch("calomet_phi");
		if (calomet_phi_branch) {calomet_phi_branch->SetAddress(&calomet_phi_);}
	}
	filt_cscbeamhalo_branch = 0;
	if (tree->GetBranch("filt_cscbeamhalo") != 0) {
		filt_cscbeamhalo_branch = tree->GetBranch("filt_cscbeamhalo");
		if (filt_cscbeamhalo_branch) {filt_cscbeamhalo_branch->SetAddress(&filt_cscbeamhalo_);}
	}
	filt_ecallaser_branch = 0;
	if (tree->GetBranch("filt_ecallaser") != 0) {
		filt_ecallaser_branch = tree->GetBranch("filt_ecallaser");
		if (filt_ecallaser_branch) {filt_ecallaser_branch->SetAddress(&filt_ecallaser_);}
	}
	filt_ecaltp_branch = 0;
	if (tree->GetBranch("filt_ecaltp") != 0) {
		filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
		if (filt_ecaltp_branch) {filt_ecaltp_branch->SetAddress(&filt_ecaltp_);}
	}
	filt_eebadsc_branch = 0;
	if (tree->GetBranch("filt_eebadsc") != 0) {
		filt_eebadsc_branch = tree->GetBranch("filt_eebadsc");
		if (filt_eebadsc_branch) {filt_eebadsc_branch->SetAddress(&filt_eebadsc_);}
	}
	filt_goodvtx_branch = 0;
	if (tree->GetBranch("filt_goodvtx") != 0) {
		filt_goodvtx_branch = tree->GetBranch("filt_goodvtx");
		if (filt_goodvtx_branch) {filt_goodvtx_branch->SetAddress(&filt_goodvtx_);}
	}
	filt_hbhenoise_branch = 0;
	if (tree->GetBranch("filt_hbhenoise") != 0) {
		filt_hbhenoise_branch = tree->GetBranch("filt_hbhenoise");
		if (filt_hbhenoise_branch) {filt_hbhenoise_branch->SetAddress(&filt_hbhenoise_);}
	}
	filt_hcallaser_branch = 0;
	if (tree->GetBranch("filt_hcallaser") != 0) {
		filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
		if (filt_hcallaser_branch) {filt_hcallaser_branch->SetAddress(&filt_hcallaser_);}
	}
	filt_met_branch = 0;
	if (tree->GetBranch("filt_met") != 0) {
		filt_met_branch = tree->GetBranch("filt_met");
		if (filt_met_branch) {filt_met_branch->SetAddress(&filt_met_);}
	}
	filt_trkfail_branch = 0;
	if (tree->GetBranch("filt_trkfail") != 0) {
		filt_trkfail_branch = tree->GetBranch("filt_trkfail");
		if (filt_trkfail_branch) {filt_trkfail_branch->SetAddress(&filt_trkfail_);}
	}
	filt_trkPOG_branch = 0;
	if (tree->GetBranch("filt_trkPOG") != 0) {
		filt_trkPOG_branch = tree->GetBranch("filt_trkPOG");
		if (filt_trkPOG_branch) {filt_trkPOG_branch->SetAddress(&filt_trkPOG_);}
	}
	filt_trkPOG_tmc_branch = 0;
	if (tree->GetBranch("filt_trkPOG_tmc") != 0) {
		filt_trkPOG_tmc_branch = tree->GetBranch("filt_trkPOG_tmc");
		if (filt_trkPOG_tmc_branch) {filt_trkPOG_tmc_branch->SetAddress(&filt_trkPOG_tmc_);}
	}
	filt_trkPOG_tms_branch = 0;
	if (tree->GetBranch("filt_trkPOG_tms") != 0) {
		filt_trkPOG_tms_branch = tree->GetBranch("filt_trkPOG_tms");
		if (filt_trkPOG_tms_branch) {filt_trkPOG_tms_branch->SetAddress(&filt_trkPOG_tms_);}
	}
	filt_eff_branch = 0;
	if (tree->GetBranch("filt_eff") != 0) {
		filt_eff_branch = tree->GetBranch("filt_eff");
		if (filt_eff_branch) {filt_eff_branch->SetAddress(&filt_eff_);}
	}
	scale1fb_branch = 0;
	if (tree->GetBranch("scale1fb") != 0) {
		scale1fb_branch = tree->GetBranch("scale1fb");
		if (scale1fb_branch) {scale1fb_branch->SetAddress(&scale1fb_);}
	}
	xsec_branch = 0;
	if (tree->GetBranch("xsec") != 0) {
		xsec_branch = tree->GetBranch("xsec");
		if (xsec_branch) {xsec_branch->SetAddress(&xsec_);}
	}
	kfactor_branch = 0;
	if (tree->GetBranch("kfactor") != 0) {
		kfactor_branch = tree->GetBranch("kfactor");
		if (kfactor_branch) {kfactor_branch->SetAddress(&kfactor_);}
	}
	pu_ntrue_branch = 0;
	if (tree->GetBranch("pu_ntrue") != 0) {
		pu_ntrue_branch = tree->GetBranch("pu_ntrue");
		if (pu_ntrue_branch) {pu_ntrue_branch->SetAddress(&pu_ntrue_);}
	}
	ngoodleps_branch = 0;
	if (tree->GetBranch("ngoodleps") != 0) {
		ngoodleps_branch = tree->GetBranch("ngoodleps");
		if (ngoodleps_branch) {ngoodleps_branch->SetAddress(&ngoodleps_);}
	}
	nvetoleps_branch = 0;
	if (tree->GetBranch("nvetoleps") != 0) {
		nvetoleps_branch = tree->GetBranch("nvetoleps");
		if (nvetoleps_branch) {nvetoleps_branch->SetAddress(&nvetoleps_);}
	}
	is_data_branch = 0;
	if (tree->GetBranch("is_data") != 0) {
		is_data_branch = tree->GetBranch("is_data");
		if (is_data_branch) {is_data_branch->SetAddress(&is_data_);}
	}
	dataset_branch = 0;
	if (tree->GetBranch("dataset") != 0) {
		dataset_branch = tree->GetBranch("dataset");
		if (dataset_branch) {dataset_branch->SetAddress(&dataset_);}
	}
	filename_branch = 0;
	if (tree->GetBranch("filename") != 0) {
		filename_branch = tree->GetBranch("filename");
		if (filename_branch) {filename_branch->SetAddress(&filename_);}
	}
	cms3tag_branch = 0;
	if (tree->GetBranch("cms3tag") != 0) {
		cms3tag_branch = tree->GetBranch("cms3tag");
		if (cms3tag_branch) {cms3tag_branch->SetAddress(&cms3tag_);}
	}
	nEvents_branch = 0;
	if (tree->GetBranch("nEvents") != 0) {
		nEvents_branch = tree->GetBranch("nEvents");
		if (nEvents_branch) {nEvents_branch->SetAddress(&nEvents_);}
	}
	nEvents_goodvtx_branch = 0;
	if (tree->GetBranch("nEvents_goodvtx") != 0) {
		nEvents_goodvtx_branch = tree->GetBranch("nEvents_goodvtx");
		if (nEvents_goodvtx_branch) {nEvents_goodvtx_branch->SetAddress(&nEvents_goodvtx_);}
	}
	nEvents_MET30_branch = 0;
	if (tree->GetBranch("nEvents_MET30") != 0) {
		nEvents_MET30_branch = tree->GetBranch("nEvents_MET30");
		if (nEvents_MET30_branch) {nEvents_MET30_branch->SetAddress(&nEvents_MET30_);}
	}
	nEvents_1goodlep_branch = 0;
	if (tree->GetBranch("nEvents_1goodlep") != 0) {
		nEvents_1goodlep_branch = tree->GetBranch("nEvents_1goodlep");
		if (nEvents_1goodlep_branch) {nEvents_1goodlep_branch->SetAddress(&nEvents_1goodlep_);}
	}
	nEvents_2goodjets_branch = 0;
	if (tree->GetBranch("nEvents_2goodjets") != 0) {
		nEvents_2goodjets_branch = tree->GetBranch("nEvents_2goodjets");
		if (nEvents_2goodjets_branch) {nEvents_2goodjets_branch->SetAddress(&nEvents_2goodjets_);}
	}
	genlepsfromtop_branch = 0;
	if (tree->GetBranch("genlepsfromtop") != 0) {
		genlepsfromtop_branch = tree->GetBranch("genlepsfromtop");
		if (genlepsfromtop_branch) {genlepsfromtop_branch->SetAddress(&genlepsfromtop_);}
	}
	MT2W_branch = 0;
	if (tree->GetBranch("MT2W") != 0) {
		MT2W_branch = tree->GetBranch("MT2W");
		if (MT2W_branch) {MT2W_branch->SetAddress(&MT2W_);}
	}
	MT2W_lep2_branch = 0;
	if (tree->GetBranch("MT2W_lep2") != 0) {
		MT2W_lep2_branch = tree->GetBranch("MT2W_lep2");
		if (MT2W_lep2_branch) {MT2W_lep2_branch->SetAddress(&MT2W_lep2_);}
	}
	mindphi_met_j1_j2_branch = 0;
	if (tree->GetBranch("mindphi_met_j1_j2") != 0) {
		mindphi_met_j1_j2_branch = tree->GetBranch("mindphi_met_j1_j2");
		if (mindphi_met_j1_j2_branch) {mindphi_met_j1_j2_branch->SetAddress(&mindphi_met_j1_j2_);}
	}
	mt_met_lep_branch = 0;
	if (tree->GetBranch("mt_met_lep") != 0) {
		mt_met_lep_branch = tree->GetBranch("mt_met_lep");
		if (mt_met_lep_branch) {mt_met_lep_branch->SetAddress(&mt_met_lep_);}
	}
	mt_met_lep2_branch = 0;
	if (tree->GetBranch("mt_met_lep2") != 0) {
		mt_met_lep2_branch = tree->GetBranch("mt_met_lep2");
		if (mt_met_lep2_branch) {mt_met_lep2_branch->SetAddress(&mt_met_lep2_);}
	}
	dR_lep_leadb_branch = 0;
	if (tree->GetBranch("dR_lep_leadb") != 0) {
		dR_lep_leadb_branch = tree->GetBranch("dR_lep_leadb");
		if (dR_lep_leadb_branch) {dR_lep_leadb_branch->SetAddress(&dR_lep_leadb_);}
	}
	dR_lep2_leadb_branch = 0;
	if (tree->GetBranch("dR_lep2_leadb") != 0) {
		dR_lep2_leadb_branch = tree->GetBranch("dR_lep2_leadb");
		if (dR_lep2_leadb_branch) {dR_lep2_leadb_branch->SetAddress(&dR_lep2_leadb_);}
	}
	hadronic_top_chi2_branch = 0;
	if (tree->GetBranch("hadronic_top_chi2") != 0) {
		hadronic_top_chi2_branch = tree->GetBranch("hadronic_top_chi2");
		if (hadronic_top_chi2_branch) {hadronic_top_chi2_branch->SetAddress(&hadronic_top_chi2_);}
	}
	dphi_Wlep_branch = 0;
	if (tree->GetBranch("dphi_Wlep") != 0) {
		dphi_Wlep_branch = tree->GetBranch("dphi_Wlep");
		if (dphi_Wlep_branch) {dphi_Wlep_branch->SetAddress(&dphi_Wlep_);}
	}
	MET_over_sqrtHT_branch = 0;
	if (tree->GetBranch("MET_over_sqrtHT") != 0) {
		MET_over_sqrtHT_branch = tree->GetBranch("MET_over_sqrtHT");
		if (MET_over_sqrtHT_branch) {MET_over_sqrtHT_branch->SetAddress(&MET_over_sqrtHT_);}
	}
	ak4pfjets_rho_branch = 0;
	if (tree->GetBranch("ak4pfjets_rho") != 0) {
		ak4pfjets_rho_branch = tree->GetBranch("ak4pfjets_rho");
		if (ak4pfjets_rho_branch) {ak4pfjets_rho_branch->SetAddress(&ak4pfjets_rho_);}
	}
	sparms_comment_branch = 0;
	if (tree->GetBranch("sparms_comment") != 0) {
		sparms_comment_branch = tree->GetBranch("sparms_comment");
		if (sparms_comment_branch) {sparms_comment_branch->SetAddress(&sparms_comment_);}
	}
	sparms_names_branch = 0;
	if (tree->GetBranch("sparms_names") != 0) {
		sparms_names_branch = tree->GetBranch("sparms_names");
		if (sparms_names_branch) {sparms_names_branch->SetAddress(&sparms_names_);}
	}
	sparms_filterEfficiency_branch = 0;
	if (tree->GetBranch("sparms_filterEfficiency") != 0) {
		sparms_filterEfficiency_branch = tree->GetBranch("sparms_filterEfficiency");
		if (sparms_filterEfficiency_branch) {sparms_filterEfficiency_branch->SetAddress(&sparms_filterEfficiency_);}
	}
	sparms_pdfScale_branch = 0;
	if (tree->GetBranch("sparms_pdfScale") != 0) {
		sparms_pdfScale_branch = tree->GetBranch("sparms_pdfScale");
		if (sparms_pdfScale_branch) {sparms_pdfScale_branch->SetAddress(&sparms_pdfScale_);}
	}
	sparms_pdfWeight1_branch = 0;
	if (tree->GetBranch("sparms_pdfWeight1") != 0) {
		sparms_pdfWeight1_branch = tree->GetBranch("sparms_pdfWeight1");
		if (sparms_pdfWeight1_branch) {sparms_pdfWeight1_branch->SetAddress(&sparms_pdfWeight1_);}
	}
	sparms_pdfWeight2_branch = 0;
	if (tree->GetBranch("sparms_pdfWeight2") != 0) {
		sparms_pdfWeight2_branch = tree->GetBranch("sparms_pdfWeight2");
		if (sparms_pdfWeight2_branch) {sparms_pdfWeight2_branch->SetAddress(&sparms_pdfWeight2_);}
	}
	sparms_weight_branch = 0;
	if (tree->GetBranch("sparms_weight") != 0) {
		sparms_weight_branch = tree->GetBranch("sparms_weight");
		if (sparms_weight_branch) {sparms_weight_branch->SetAddress(&sparms_weight_);}
	}
	sparms_xsec_branch = 0;
	if (tree->GetBranch("sparms_xsec") != 0) {
		sparms_xsec_branch = tree->GetBranch("sparms_xsec");
		if (sparms_xsec_branch) {sparms_xsec_branch->SetAddress(&sparms_xsec_);}
	}
	sparms_values_branch = 0;
	if (tree->GetBranch("sparms_values") != 0) {
		sparms_values_branch = tree->GetBranch("sparms_values");
		if (sparms_values_branch) {sparms_values_branch->SetAddress(&sparms_values_);}
	}
	sparms_subProcessId_branch = 0;
	if (tree->GetBranch("sparms_subProcessId") != 0) {
		sparms_subProcessId_branch = tree->GetBranch("sparms_subProcessId");
		if (sparms_subProcessId_branch) {sparms_subProcessId_branch->SetAddress(&sparms_subProcessId_);}
	}
	mass_lsp_branch = 0;
	if (tree->GetBranch("mass_lsp") != 0) {
		mass_lsp_branch = tree->GetBranch("mass_lsp");
		if (mass_lsp_branch) {mass_lsp_branch->SetAddress(&mass_lsp_);}
	}
	mass_chargino_branch = 0;
	if (tree->GetBranch("mass_chargino") != 0) {
		mass_chargino_branch = tree->GetBranch("mass_chargino");
		if (mass_chargino_branch) {mass_chargino_branch->SetAddress(&mass_chargino_);}
	}
	mass_stop_branch = 0;
	if (tree->GetBranch("mass_stop") != 0) {
		mass_stop_branch = tree->GetBranch("mass_stop");
		if (mass_stop_branch) {mass_stop_branch->SetAddress(&mass_stop_);}
	}
	genmet_branch = 0;
	if (tree->GetBranch("genmet") != 0) {
		genmet_branch = tree->GetBranch("genmet");
		if (genmet_branch) {genmet_branch->SetAddress(&genmet_);}
	}
	genmet_phi_branch = 0;
	if (tree->GetBranch("genmet_phi") != 0) {
		genmet_phi_branch = tree->GetBranch("genmet_phi");
		if (genmet_phi_branch) {genmet_phi_branch->SetAddress(&genmet_phi_);}
	}
	PassTrackVeto_branch = 0;
	if (tree->GetBranch("PassTrackVeto") != 0) {
		PassTrackVeto_branch = tree->GetBranch("PassTrackVeto");
		if (PassTrackVeto_branch) {PassTrackVeto_branch->SetAddress(&PassTrackVeto_);}
	}
	PassTrackVeto_v2_branch = 0;
	if (tree->GetBranch("PassTrackVeto_v2") != 0) {
		PassTrackVeto_v2_branch = tree->GetBranch("PassTrackVeto_v2");
		if (PassTrackVeto_v2_branch) {PassTrackVeto_v2_branch->SetAddress(&PassTrackVeto_v2_);}
	}
	PassTrackVeto_v3_branch = 0;
	if (tree->GetBranch("PassTrackVeto_v3") != 0) {
		PassTrackVeto_v3_branch = tree->GetBranch("PassTrackVeto_v3");
		if (PassTrackVeto_v3_branch) {PassTrackVeto_v3_branch->SetAddress(&PassTrackVeto_v3_);}
	}
	PassTauVeto_branch = 0;
	if (tree->GetBranch("PassTauVeto") != 0) {
		PassTauVeto_branch = tree->GetBranch("PassTauVeto");
		if (PassTauVeto_branch) {PassTauVeto_branch->SetAddress(&PassTauVeto_);}
	}
	EA_all_rho_branch = 0;
	if (tree->GetBranch("EA_all_rho") != 0) {
		EA_all_rho_branch = tree->GetBranch("EA_all_rho");
		if (EA_all_rho_branch) {EA_all_rho_branch->SetAddress(&EA_all_rho_);}
	}
	EA_allcalo_rho_branch = 0;
	if (tree->GetBranch("EA_allcalo_rho") != 0) {
		EA_allcalo_rho_branch = tree->GetBranch("EA_allcalo_rho");
		if (EA_allcalo_rho_branch) {EA_allcalo_rho_branch->SetAddress(&EA_allcalo_rho_);}
	}
	EA_centralcalo_rho_branch = 0;
	if (tree->GetBranch("EA_centralcalo_rho") != 0) {
		EA_centralcalo_rho_branch = tree->GetBranch("EA_centralcalo_rho");
		if (EA_centralcalo_rho_branch) {EA_centralcalo_rho_branch->SetAddress(&EA_centralcalo_rho_);}
	}
	EA_centralchargedpileup_rho_branch = 0;
	if (tree->GetBranch("EA_centralchargedpileup_rho") != 0) {
		EA_centralchargedpileup_rho_branch = tree->GetBranch("EA_centralchargedpileup_rho");
		if (EA_centralchargedpileup_rho_branch) {EA_centralchargedpileup_rho_branch->SetAddress(&EA_centralchargedpileup_rho_);}
	}
	EA_centralneutral_rho_branch = 0;
	if (tree->GetBranch("EA_centralneutral_rho") != 0) {
		EA_centralneutral_rho_branch = tree->GetBranch("EA_centralneutral_rho");
		if (EA_centralneutral_rho_branch) {EA_centralneutral_rho_branch->SetAddress(&EA_centralneutral_rho_);}
	}
	topness_branch = 0;
	if (tree->GetBranch("topness") != 0) {
		topness_branch = tree->GetBranch("topness");
		if (topness_branch) {topness_branch->SetAddress(&topness_);}
	}
	topness_lep2_branch = 0;
	if (tree->GetBranch("topness_lep2") != 0) {
		topness_lep2_branch = tree->GetBranch("topness_lep2");
		if (topness_lep2_branch) {topness_lep2_branch->SetAddress(&topness_lep2_);}
	}
	topnessMod_branch = 0;
	if (tree->GetBranch("topnessMod") != 0) {
		topnessMod_branch = tree->GetBranch("topnessMod");
		if (topnessMod_branch) {topnessMod_branch->SetAddress(&topnessMod_);}
	}
	topnessMod_lep2_branch = 0;
	if (tree->GetBranch("topnessMod_lep2") != 0) {
		topnessMod_lep2_branch = tree->GetBranch("topnessMod_lep2");
		if (topnessMod_lep2_branch) {topnessMod_lep2_branch->SetAddress(&topnessMod_lep2_);}
	}
	MT2_lb_b_branch = 0;
	if (tree->GetBranch("MT2_lb_b") != 0) {
		MT2_lb_b_branch = tree->GetBranch("MT2_lb_b");
		if (MT2_lb_b_branch) {MT2_lb_b_branch->SetAddress(&MT2_lb_b_);}
	}
	MT2_lb_b_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_lep2") != 0) {
		MT2_lb_b_lep2_branch = tree->GetBranch("MT2_lb_b_lep2");
		if (MT2_lb_b_lep2_branch) {MT2_lb_b_lep2_branch->SetAddress(&MT2_lb_b_lep2_);}
	}
	MT2_lb_b_mass_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass") != 0) {
		MT2_lb_b_mass_branch = tree->GetBranch("MT2_lb_b_mass");
		if (MT2_lb_b_mass_branch) {MT2_lb_b_mass_branch->SetAddress(&MT2_lb_b_mass_);}
	}
	MT2_lb_b_mass_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass_lep2") != 0) {
		MT2_lb_b_mass_lep2_branch = tree->GetBranch("MT2_lb_b_mass_lep2");
		if (MT2_lb_b_mass_lep2_branch) {MT2_lb_b_mass_lep2_branch->SetAddress(&MT2_lb_b_mass_lep2_);}
	}
	MT2_lb_bqq_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq") != 0) {
		MT2_lb_bqq_branch = tree->GetBranch("MT2_lb_bqq");
		if (MT2_lb_bqq_branch) {MT2_lb_bqq_branch->SetAddress(&MT2_lb_bqq_);}
	}
	MT2_lb_bqq_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_lep2") != 0) {
		MT2_lb_bqq_lep2_branch = tree->GetBranch("MT2_lb_bqq_lep2");
		if (MT2_lb_bqq_lep2_branch) {MT2_lb_bqq_lep2_branch->SetAddress(&MT2_lb_bqq_lep2_);}
	}
	MT2_lb_bqq_mass_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_mass") != 0) {
		MT2_lb_bqq_mass_branch = tree->GetBranch("MT2_lb_bqq_mass");
		if (MT2_lb_bqq_mass_branch) {MT2_lb_bqq_mass_branch->SetAddress(&MT2_lb_bqq_mass_);}
	}
	MT2_lb_bqq_mass_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_mass_lep2") != 0) {
		MT2_lb_bqq_mass_lep2_branch = tree->GetBranch("MT2_lb_bqq_mass_lep2");
		if (MT2_lb_bqq_mass_lep2_branch) {MT2_lb_bqq_mass_lep2_branch->SetAddress(&MT2_lb_bqq_mass_lep2_);}
	}
	Mlb_closestb_branch = 0;
	if (tree->GetBranch("Mlb_closestb") != 0) {
		Mlb_closestb_branch = tree->GetBranch("Mlb_closestb");
		if (Mlb_closestb_branch) {Mlb_closestb_branch->SetAddress(&Mlb_closestb_);}
	}
	Mlb_lead_bdiscr_branch = 0;
	if (tree->GetBranch("Mlb_lead_bdiscr") != 0) {
		Mlb_lead_bdiscr_branch = tree->GetBranch("Mlb_lead_bdiscr");
		if (Mlb_lead_bdiscr_branch) {Mlb_lead_bdiscr_branch->SetAddress(&Mlb_lead_bdiscr_);}
	}
	Mlb_closestb_lep2_branch = 0;
	if (tree->GetBranch("Mlb_closestb_lep2") != 0) {
		Mlb_closestb_lep2_branch = tree->GetBranch("Mlb_closestb_lep2");
		if (Mlb_closestb_lep2_branch) {Mlb_closestb_lep2_branch->SetAddress(&Mlb_closestb_lep2_);}
	}
	Mlb_lead_bdiscr_lep2_branch = 0;
	if (tree->GetBranch("Mlb_lead_bdiscr_lep2") != 0) {
		Mlb_lead_bdiscr_lep2_branch = tree->GetBranch("Mlb_lead_bdiscr_lep2");
		if (Mlb_lead_bdiscr_lep2_branch) {Mlb_lead_bdiscr_lep2_branch->SetAddress(&Mlb_lead_bdiscr_lep2_);}
	}
	Mjjj_branch = 0;
	if (tree->GetBranch("Mjjj") != 0) {
		Mjjj_branch = tree->GetBranch("Mjjj");
		if (Mjjj_branch) {Mjjj_branch->SetAddress(&Mjjj_);}
	}
	Mjjj_lep2_branch = 0;
	if (tree->GetBranch("Mjjj_lep2") != 0) {
		Mjjj_lep2_branch = tree->GetBranch("Mjjj_lep2");
		if (Mjjj_lep2_branch) {Mjjj_lep2_branch->SetAddress(&Mjjj_lep2_);}
	}
	HLT_SingleEl_branch = 0;
	if (tree->GetBranch("HLT_SingleEl") != 0) {
		HLT_SingleEl_branch = tree->GetBranch("HLT_SingleEl");
		if (HLT_SingleEl_branch) {HLT_SingleEl_branch->SetAddress(&HLT_SingleEl_);}
	}
	HLT_SingleMu_branch = 0;
	if (tree->GetBranch("HLT_SingleMu") != 0) {
		HLT_SingleMu_branch = tree->GetBranch("HLT_SingleMu");
		if (HLT_SingleMu_branch) {HLT_SingleMu_branch->SetAddress(&HLT_SingleMu_);}
	}
	HLT_MET170_branch = 0;
	if (tree->GetBranch("HLT_MET170") != 0) {
		HLT_MET170_branch = tree->GetBranch("HLT_MET170");
		if (HLT_MET170_branch) {HLT_MET170_branch->SetAddress(&HLT_MET170_);}
	}
	HLT_MET120Btag_branch = 0;
	if (tree->GetBranch("HLT_MET120Btag") != 0) {
		HLT_MET120Btag_branch = tree->GetBranch("HLT_MET120Btag");
		if (HLT_MET120Btag_branch) {HLT_MET120Btag_branch->SetAddress(&HLT_MET120Btag_);}
	}
	HLT_MET120Mu5_branch = 0;
	if (tree->GetBranch("HLT_MET120Mu5") != 0) {
		HLT_MET120Mu5_branch = tree->GetBranch("HLT_MET120Mu5");
		if (HLT_MET120Mu5_branch) {HLT_MET120Mu5_branch->SetAddress(&HLT_MET120Mu5_);}
	}
	HLT_HT350MET120_branch = 0;
	if (tree->GetBranch("HLT_HT350MET120") != 0) {
		HLT_HT350MET120_branch = tree->GetBranch("HLT_HT350MET120");
		if (HLT_HT350MET120_branch) {HLT_HT350MET120_branch->SetAddress(&HLT_HT350MET120_);}
	}
	HLT_DiEl_branch = 0;
	if (tree->GetBranch("HLT_DiEl") != 0) {
		HLT_DiEl_branch = tree->GetBranch("HLT_DiEl");
		if (HLT_DiEl_branch) {HLT_DiEl_branch->SetAddress(&HLT_DiEl_);}
	}
	HLT_DiMu_branch = 0;
	if (tree->GetBranch("HLT_DiMu") != 0) {
		HLT_DiMu_branch = tree->GetBranch("HLT_DiMu");
		if (HLT_DiMu_branch) {HLT_DiMu_branch->SetAddress(&HLT_DiMu_);}
	}
	HLT_Mu8El17_branch = 0;
	if (tree->GetBranch("HLT_Mu8El17") != 0) {
		HLT_Mu8El17_branch = tree->GetBranch("HLT_Mu8El17");
		if (HLT_Mu8El17_branch) {HLT_Mu8El17_branch->SetAddress(&HLT_Mu8El17_);}
	}
	HLT_Mu8El23_branch = 0;
	if (tree->GetBranch("HLT_Mu8El23") != 0) {
		HLT_Mu8El23_branch = tree->GetBranch("HLT_Mu8El23");
		if (HLT_Mu8El23_branch) {HLT_Mu8El23_branch->SetAddress(&HLT_Mu8El23_);}
	}
	HLT_Mu17El12_branch = 0;
	if (tree->GetBranch("HLT_Mu17El12") != 0) {
		HLT_Mu17El12_branch = tree->GetBranch("HLT_Mu17El12");
		if (HLT_Mu17El12_branch) {HLT_Mu17El12_branch->SetAddress(&HLT_Mu17El12_);}
	}
	HLT_Mu23El12_branch = 0;
	if (tree->GetBranch("HLT_Mu23El12") != 0) {
		HLT_Mu23El12_branch = tree->GetBranch("HLT_Mu23El12");
		if (HLT_Mu23El12_branch) {HLT_Mu23El12_branch->SetAddress(&HLT_Mu23El12_);}
	}
	HLT_SingleEl27_branch = 0;
	if (tree->GetBranch("HLT_SingleEl27") != 0) {
		HLT_SingleEl27_branch = tree->GetBranch("HLT_SingleEl27");
		if (HLT_SingleEl27_branch) {HLT_SingleEl27_branch->SetAddress(&HLT_SingleEl27_);}
	}
	HLT_SingleEl27Tight_branch = 0;
	if (tree->GetBranch("HLT_SingleEl27Tight") != 0) {
		HLT_SingleEl27Tight_branch = tree->GetBranch("HLT_SingleEl27Tight");
		if (HLT_SingleEl27Tight_branch) {HLT_SingleEl27Tight_branch->SetAddress(&HLT_SingleEl27Tight_);}
	}
	HLT_SingleElTight_branch = 0;
	if (tree->GetBranch("HLT_SingleElTight") != 0) {
		HLT_SingleElTight_branch = tree->GetBranch("HLT_SingleElTight");
		if (HLT_SingleElTight_branch) {HLT_SingleElTight_branch->SetAddress(&HLT_SingleElTight_);}
	}
	HLT_SingleElHT200_branch = 0;
	if (tree->GetBranch("HLT_SingleElHT200") != 0) {
		HLT_SingleElHT200_branch = tree->GetBranch("HLT_SingleElHT200");
		if (HLT_SingleElHT200_branch) {HLT_SingleElHT200_branch->SetAddress(&HLT_SingleElHT200_);}
	}
	HLT_SingleMuNoEta_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoEta") != 0) {
		HLT_SingleMuNoEta_branch = tree->GetBranch("HLT_SingleMuNoEta");
		if (HLT_SingleMuNoEta_branch) {HLT_SingleMuNoEta_branch->SetAddress(&HLT_SingleMuNoEta_);}
	}
	HLT_SingleMuNoIso_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoIso") != 0) {
		HLT_SingleMuNoIso_branch = tree->GetBranch("HLT_SingleMuNoIso");
		if (HLT_SingleMuNoIso_branch) {HLT_SingleMuNoIso_branch->SetAddress(&HLT_SingleMuNoIso_);}
	}
	HLT_SingleMuNoIsoNoEta_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoIsoNoEta") != 0) {
		HLT_SingleMuNoIsoNoEta_branch = tree->GetBranch("HLT_SingleMuNoIsoNoEta");
		if (HLT_SingleMuNoIsoNoEta_branch) {HLT_SingleMuNoIsoNoEta_branch->SetAddress(&HLT_SingleMuNoIsoNoEta_);}
	}
	HLT_Mu6HT200MET100_branch = 0;
	if (tree->GetBranch("HLT_Mu6HT200MET100") != 0) {
		HLT_Mu6HT200MET100_branch = tree->GetBranch("HLT_Mu6HT200MET100");
		if (HLT_Mu6HT200MET100_branch) {HLT_Mu6HT200MET100_branch->SetAddress(&HLT_Mu6HT200MET100_);}
	}
	HLT_HT350MET100_branch = 0;
	if (tree->GetBranch("HLT_HT350MET100") != 0) {
		HLT_HT350MET100_branch = tree->GetBranch("HLT_HT350MET100");
		if (HLT_HT350MET100_branch) {HLT_HT350MET100_branch->SetAddress(&HLT_HT350MET100_);}
	}
	HLT_SingleMu17_branch = 0;
	if (tree->GetBranch("HLT_SingleMu17") != 0) {
		HLT_SingleMu17_branch = tree->GetBranch("HLT_SingleMu17");
		if (HLT_SingleMu17_branch) {HLT_SingleMu17_branch->SetAddress(&HLT_SingleMu17_);}
	}
	HLT_SingleMu20_branch = 0;
	if (tree->GetBranch("HLT_SingleMu20") != 0) {
		HLT_SingleMu20_branch = tree->GetBranch("HLT_SingleMu20");
		if (HLT_SingleMu20_branch) {HLT_SingleMu20_branch->SetAddress(&HLT_SingleMu20_);}
	}
	HLT_SingleMu24_branch = 0;
	if (tree->GetBranch("HLT_SingleMu24") != 0) {
		HLT_SingleMu24_branch = tree->GetBranch("HLT_SingleMu24");
		if (HLT_SingleMu24_branch) {HLT_SingleMu24_branch->SetAddress(&HLT_SingleMu24_);}
	}
	HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight") != 0) {
		HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch = tree->GetBranch("HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight");
		if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch) {HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch->SetAddress(&HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_);}
	}
	HLT_MET90_MHT90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_MET90_MHT90_IDTight") != 0) {
		HLT_MET90_MHT90_IDTight_branch = tree->GetBranch("HLT_MET90_MHT90_IDTight");
		if (HLT_MET90_MHT90_IDTight_branch) {HLT_MET90_MHT90_IDTight_branch->SetAddress(&HLT_MET90_MHT90_IDTight_);}
	}
	HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight") != 0) {
		HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch = tree->GetBranch("HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight");
		if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch) {HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch->SetAddress(&HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_);}
	}
	pu_weight_branch = 0;
	if (tree->GetBranch("pu_weight") != 0) {
		pu_weight_branch = tree->GetBranch("pu_weight");
		if (pu_weight_branch) {pu_weight_branch->SetAddress(&pu_weight_);}
	}
	lep_sf_branch = 0;
	if (tree->GetBranch("lep_sf") != 0) {
		lep_sf_branch = tree->GetBranch("lep_sf");
		if (lep_sf_branch) {lep_sf_branch->SetAddress(&lep_sf_);}
	}
	btag_sf_branch = 0;
	if (tree->GetBranch("btag_sf") != 0) {
		btag_sf_branch = tree->GetBranch("btag_sf");
		if (btag_sf_branch) {btag_sf_branch->SetAddress(&btag_sf_);}
	}
	HLT_SingleEl_eff_branch = 0;
	if (tree->GetBranch("HLT_SingleEl_eff") != 0) {
		HLT_SingleEl_eff_branch = tree->GetBranch("HLT_SingleEl_eff");
		if (HLT_SingleEl_eff_branch) {HLT_SingleEl_eff_branch->SetAddress(&HLT_SingleEl_eff_);}
	}
	HLT_SingleMu_eff_branch = 0;
	if (tree->GetBranch("HLT_SingleMu_eff") != 0) {
		HLT_SingleMu_eff_branch = tree->GetBranch("HLT_SingleMu_eff");
		if (HLT_SingleMu_eff_branch) {HLT_SingleMu_eff_branch->SetAddress(&HLT_SingleMu_eff_);}
	}
	lep1_is_mu_branch = 0;
	if (tree->GetBranch("lep1_is_mu") != 0) {
		lep1_is_mu_branch = tree->GetBranch("lep1_is_mu");
		if (lep1_is_mu_branch) {lep1_is_mu_branch->SetAddress(&lep1_is_mu_);}
	}
	lep1_is_el_branch = 0;
	if (tree->GetBranch("lep1_is_el") != 0) {
		lep1_is_el_branch = tree->GetBranch("lep1_is_el");
		if (lep1_is_el_branch) {lep1_is_el_branch->SetAddress(&lep1_is_el_);}
	}
	lep1_charge_branch = 0;
	if (tree->GetBranch("lep1_charge") != 0) {
		lep1_charge_branch = tree->GetBranch("lep1_charge");
		if (lep1_charge_branch) {lep1_charge_branch->SetAddress(&lep1_charge_);}
	}
	lep1_pdgid_branch = 0;
	if (tree->GetBranch("lep1_pdgid") != 0) {
		lep1_pdgid_branch = tree->GetBranch("lep1_pdgid");
		if (lep1_pdgid_branch) {lep1_pdgid_branch->SetAddress(&lep1_pdgid_);}
	}
	lep1_type_branch = 0;
	if (tree->GetBranch("lep1_type") != 0) {
		lep1_type_branch = tree->GetBranch("lep1_type");
		if (lep1_type_branch) {lep1_type_branch->SetAddress(&lep1_type_);}
	}
	lep1_production_type_branch = 0;
	if (tree->GetBranch("lep1_production_type") != 0) {
		lep1_production_type_branch = tree->GetBranch("lep1_production_type");
		if (lep1_production_type_branch) {lep1_production_type_branch->SetAddress(&lep1_production_type_);}
	}
	lep1_d0_branch = 0;
	if (tree->GetBranch("lep1_d0") != 0) {
		lep1_d0_branch = tree->GetBranch("lep1_d0");
		if (lep1_d0_branch) {lep1_d0_branch->SetAddress(&lep1_d0_);}
	}
	lep1_d0err_branch = 0;
	if (tree->GetBranch("lep1_d0err") != 0) {
		lep1_d0err_branch = tree->GetBranch("lep1_d0err");
		if (lep1_d0err_branch) {lep1_d0err_branch->SetAddress(&lep1_d0err_);}
	}
	lep1_dz_branch = 0;
	if (tree->GetBranch("lep1_dz") != 0) {
		lep1_dz_branch = tree->GetBranch("lep1_dz");
		if (lep1_dz_branch) {lep1_dz_branch->SetAddress(&lep1_dz_);}
	}
	lep1_dzerr_branch = 0;
	if (tree->GetBranch("lep1_dzerr") != 0) {
		lep1_dzerr_branch = tree->GetBranch("lep1_dzerr");
		if (lep1_dzerr_branch) {lep1_dzerr_branch->SetAddress(&lep1_dzerr_);}
	}
	lep1_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("lep1_sigmaIEtaEta_fill5x5") != 0) {
		lep1_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("lep1_sigmaIEtaEta_fill5x5");
		if (lep1_sigmaIEtaEta_fill5x5_branch) {lep1_sigmaIEtaEta_fill5x5_branch->SetAddress(&lep1_sigmaIEtaEta_fill5x5_);}
	}
	lep1_dEtaIn_branch = 0;
	if (tree->GetBranch("lep1_dEtaIn") != 0) {
		lep1_dEtaIn_branch = tree->GetBranch("lep1_dEtaIn");
		if (lep1_dEtaIn_branch) {lep1_dEtaIn_branch->SetAddress(&lep1_dEtaIn_);}
	}
	lep1_dPhiIn_branch = 0;
	if (tree->GetBranch("lep1_dPhiIn") != 0) {
		lep1_dPhiIn_branch = tree->GetBranch("lep1_dPhiIn");
		if (lep1_dPhiIn_branch) {lep1_dPhiIn_branch->SetAddress(&lep1_dPhiIn_);}
	}
	lep1_hOverE_branch = 0;
	if (tree->GetBranch("lep1_hOverE") != 0) {
		lep1_hOverE_branch = tree->GetBranch("lep1_hOverE");
		if (lep1_hOverE_branch) {lep1_hOverE_branch->SetAddress(&lep1_hOverE_);}
	}
	lep1_ooEmooP_branch = 0;
	if (tree->GetBranch("lep1_ooEmooP") != 0) {
		lep1_ooEmooP_branch = tree->GetBranch("lep1_ooEmooP");
		if (lep1_ooEmooP_branch) {lep1_ooEmooP_branch->SetAddress(&lep1_ooEmooP_);}
	}
	lep1_expectedMissingInnerHits_branch = 0;
	if (tree->GetBranch("lep1_expectedMissingInnerHits") != 0) {
		lep1_expectedMissingInnerHits_branch = tree->GetBranch("lep1_expectedMissingInnerHits");
		if (lep1_expectedMissingInnerHits_branch) {lep1_expectedMissingInnerHits_branch->SetAddress(&lep1_expectedMissingInnerHits_);}
	}
	lep1_conversionVeto_branch = 0;
	if (tree->GetBranch("lep1_conversionVeto") != 0) {
		lep1_conversionVeto_branch = tree->GetBranch("lep1_conversionVeto");
		if (lep1_conversionVeto_branch) {lep1_conversionVeto_branch->SetAddress(&lep1_conversionVeto_);}
	}
	lep1_etaSC_branch = 0;
	if (tree->GetBranch("lep1_etaSC") != 0) {
		lep1_etaSC_branch = tree->GetBranch("lep1_etaSC");
		if (lep1_etaSC_branch) {lep1_etaSC_branch->SetAddress(&lep1_etaSC_);}
	}
	lep1_ChiSqr_branch = 0;
	if (tree->GetBranch("lep1_ChiSqr") != 0) {
		lep1_ChiSqr_branch = tree->GetBranch("lep1_ChiSqr");
		if (lep1_ChiSqr_branch) {lep1_ChiSqr_branch->SetAddress(&lep1_ChiSqr_);}
	}
	lep1_chiso_branch = 0;
	if (tree->GetBranch("lep1_chiso") != 0) {
		lep1_chiso_branch = tree->GetBranch("lep1_chiso");
		if (lep1_chiso_branch) {lep1_chiso_branch->SetAddress(&lep1_chiso_);}
	}
	lep1_nhiso_branch = 0;
	if (tree->GetBranch("lep1_nhiso") != 0) {
		lep1_nhiso_branch = tree->GetBranch("lep1_nhiso");
		if (lep1_nhiso_branch) {lep1_nhiso_branch->SetAddress(&lep1_nhiso_);}
	}
	lep1_emiso_branch = 0;
	if (tree->GetBranch("lep1_emiso") != 0) {
		lep1_emiso_branch = tree->GetBranch("lep1_emiso");
		if (lep1_emiso_branch) {lep1_emiso_branch->SetAddress(&lep1_emiso_);}
	}
	lep1_deltaBeta_branch = 0;
	if (tree->GetBranch("lep1_deltaBeta") != 0) {
		lep1_deltaBeta_branch = tree->GetBranch("lep1_deltaBeta");
		if (lep1_deltaBeta_branch) {lep1_deltaBeta_branch->SetAddress(&lep1_deltaBeta_);}
	}
	lep1_relIso03DB_branch = 0;
	if (tree->GetBranch("lep1_relIso03DB") != 0) {
		lep1_relIso03DB_branch = tree->GetBranch("lep1_relIso03DB");
		if (lep1_relIso03DB_branch) {lep1_relIso03DB_branch->SetAddress(&lep1_relIso03DB_);}
	}
	lep1_relIso03EA_branch = 0;
	if (tree->GetBranch("lep1_relIso03EA") != 0) {
		lep1_relIso03EA_branch = tree->GetBranch("lep1_relIso03EA");
		if (lep1_relIso03EA_branch) {lep1_relIso03EA_branch->SetAddress(&lep1_relIso03EA_);}
	}
	lep1_relIso04DB_branch = 0;
	if (tree->GetBranch("lep1_relIso04DB") != 0) {
		lep1_relIso04DB_branch = tree->GetBranch("lep1_relIso04DB");
		if (lep1_relIso04DB_branch) {lep1_relIso04DB_branch->SetAddress(&lep1_relIso04DB_);}
	}
	lep1_miniRelIsoDB_branch = 0;
	if (tree->GetBranch("lep1_miniRelIsoDB") != 0) {
		lep1_miniRelIsoDB_branch = tree->GetBranch("lep1_miniRelIsoDB");
		if (lep1_miniRelIsoDB_branch) {lep1_miniRelIsoDB_branch->SetAddress(&lep1_miniRelIsoDB_);}
	}
	lep1_miniRelIsoEA_branch = 0;
	if (tree->GetBranch("lep1_miniRelIsoEA") != 0) {
		lep1_miniRelIsoEA_branch = tree->GetBranch("lep1_miniRelIsoEA");
		if (lep1_miniRelIsoEA_branch) {lep1_miniRelIsoEA_branch->SetAddress(&lep1_miniRelIsoEA_);}
	}
	lep1_MiniIso_branch = 0;
	if (tree->GetBranch("lep1_MiniIso") != 0) {
		lep1_MiniIso_branch = tree->GetBranch("lep1_MiniIso");
		if (lep1_MiniIso_branch) {lep1_MiniIso_branch->SetAddress(&lep1_MiniIso_);}
	}
	lep1_mcid_branch = 0;
	if (tree->GetBranch("lep1_mcid") != 0) {
		lep1_mcid_branch = tree->GetBranch("lep1_mcid");
		if (lep1_mcid_branch) {lep1_mcid_branch->SetAddress(&lep1_mcid_);}
	}
	lep1_mcstatus_branch = 0;
	if (tree->GetBranch("lep1_mcstatus") != 0) {
		lep1_mcstatus_branch = tree->GetBranch("lep1_mcstatus");
		if (lep1_mcstatus_branch) {lep1_mcstatus_branch->SetAddress(&lep1_mcstatus_);}
	}
	lep1_mc3dr_branch = 0;
	if (tree->GetBranch("lep1_mc3dr") != 0) {
		lep1_mc3dr_branch = tree->GetBranch("lep1_mc3dr");
		if (lep1_mc3dr_branch) {lep1_mc3dr_branch->SetAddress(&lep1_mc3dr_);}
	}
	lep1_mc3id_branch = 0;
	if (tree->GetBranch("lep1_mc3id") != 0) {
		lep1_mc3id_branch = tree->GetBranch("lep1_mc3id");
		if (lep1_mc3id_branch) {lep1_mc3id_branch->SetAddress(&lep1_mc3id_);}
	}
	lep1_mc3idx_branch = 0;
	if (tree->GetBranch("lep1_mc3idx") != 0) {
		lep1_mc3idx_branch = tree->GetBranch("lep1_mc3idx");
		if (lep1_mc3idx_branch) {lep1_mc3idx_branch->SetAddress(&lep1_mc3idx_);}
	}
	lep1_mc3motherid_branch = 0;
	if (tree->GetBranch("lep1_mc3motherid") != 0) {
		lep1_mc3motherid_branch = tree->GetBranch("lep1_mc3motherid");
		if (lep1_mc3motherid_branch) {lep1_mc3motherid_branch->SetAddress(&lep1_mc3motherid_);}
	}
	lep1_mc3motheridx_branch = 0;
	if (tree->GetBranch("lep1_mc3motheridx") != 0) {
		lep1_mc3motheridx_branch = tree->GetBranch("lep1_mc3motheridx");
		if (lep1_mc3motheridx_branch) {lep1_mc3motheridx_branch->SetAddress(&lep1_mc3motheridx_);}
	}
	lep1_is_eleid_loose_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_loose") != 0) {
		lep1_is_eleid_loose_branch = tree->GetBranch("lep1_is_eleid_loose");
		if (lep1_is_eleid_loose_branch) {lep1_is_eleid_loose_branch->SetAddress(&lep1_is_eleid_loose_);}
	}
	lep1_is_eleid_medium_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_medium") != 0) {
		lep1_is_eleid_medium_branch = tree->GetBranch("lep1_is_eleid_medium");
		if (lep1_is_eleid_medium_branch) {lep1_is_eleid_medium_branch->SetAddress(&lep1_is_eleid_medium_);}
	}
	lep1_is_eleid_tight_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_tight") != 0) {
		lep1_is_eleid_tight_branch = tree->GetBranch("lep1_is_eleid_tight");
		if (lep1_is_eleid_tight_branch) {lep1_is_eleid_tight_branch->SetAddress(&lep1_is_eleid_tight_);}
	}
	lep1_is_phys14_loose_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_loose_noIso") != 0) {
		lep1_is_phys14_loose_noIso_branch = tree->GetBranch("lep1_is_phys14_loose_noIso");
		if (lep1_is_phys14_loose_noIso_branch) {lep1_is_phys14_loose_noIso_branch->SetAddress(&lep1_is_phys14_loose_noIso_);}
	}
	lep1_is_phys14_medium_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_medium_noIso") != 0) {
		lep1_is_phys14_medium_noIso_branch = tree->GetBranch("lep1_is_phys14_medium_noIso");
		if (lep1_is_phys14_medium_noIso_branch) {lep1_is_phys14_medium_noIso_branch->SetAddress(&lep1_is_phys14_medium_noIso_);}
	}
	lep1_is_phys14_tight_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_tight_noIso") != 0) {
		lep1_is_phys14_tight_noIso_branch = tree->GetBranch("lep1_is_phys14_tight_noIso");
		if (lep1_is_phys14_tight_noIso_branch) {lep1_is_phys14_tight_noIso_branch->SetAddress(&lep1_is_phys14_tight_noIso_);}
	}
	lep1_eoverpin_branch = 0;
	if (tree->GetBranch("lep1_eoverpin") != 0) {
		lep1_eoverpin_branch = tree->GetBranch("lep1_eoverpin");
		if (lep1_eoverpin_branch) {lep1_eoverpin_branch->SetAddress(&lep1_eoverpin_);}
	}
	lep1_is_muoid_loose_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_loose") != 0) {
		lep1_is_muoid_loose_branch = tree->GetBranch("lep1_is_muoid_loose");
		if (lep1_is_muoid_loose_branch) {lep1_is_muoid_loose_branch->SetAddress(&lep1_is_muoid_loose_);}
	}
	lep1_is_muoid_medium_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_medium") != 0) {
		lep1_is_muoid_medium_branch = tree->GetBranch("lep1_is_muoid_medium");
		if (lep1_is_muoid_medium_branch) {lep1_is_muoid_medium_branch->SetAddress(&lep1_is_muoid_medium_);}
	}
	lep1_is_muoid_tight_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_tight") != 0) {
		lep1_is_muoid_tight_branch = tree->GetBranch("lep1_is_muoid_tight");
		if (lep1_is_muoid_tight_branch) {lep1_is_muoid_tight_branch->SetAddress(&lep1_is_muoid_tight_);}
	}
	lep1_ip3d_branch = 0;
	if (tree->GetBranch("lep1_ip3d") != 0) {
		lep1_ip3d_branch = tree->GetBranch("lep1_ip3d");
		if (lep1_ip3d_branch) {lep1_ip3d_branch->SetAddress(&lep1_ip3d_);}
	}
	lep1_ip3derr_branch = 0;
	if (tree->GetBranch("lep1_ip3derr") != 0) {
		lep1_ip3derr_branch = tree->GetBranch("lep1_ip3derr");
		if (lep1_ip3derr_branch) {lep1_ip3derr_branch->SetAddress(&lep1_ip3derr_);}
	}
	lep1_is_pfmu_branch = 0;
	if (tree->GetBranch("lep1_is_pfmu") != 0) {
		lep1_is_pfmu_branch = tree->GetBranch("lep1_is_pfmu");
		if (lep1_is_pfmu_branch) {lep1_is_pfmu_branch->SetAddress(&lep1_is_pfmu_);}
	}
	lep1_passMediumID_branch = 0;
	if (tree->GetBranch("lep1_passMediumID") != 0) {
		lep1_passMediumID_branch = tree->GetBranch("lep1_passMediumID");
		if (lep1_passMediumID_branch) {lep1_passMediumID_branch->SetAddress(&lep1_passMediumID_);}
	}
	lep1_passVeto_branch = 0;
	if (tree->GetBranch("lep1_passVeto") != 0) {
		lep1_passVeto_branch = tree->GetBranch("lep1_passVeto");
		if (lep1_passVeto_branch) {lep1_passVeto_branch->SetAddress(&lep1_passVeto_);}
	}
	lep1_pt_branch = 0;
	if (tree->GetBranch("lep1_pt") != 0) {
		lep1_pt_branch = tree->GetBranch("lep1_pt");
		if (lep1_pt_branch) {lep1_pt_branch->SetAddress(&lep1_pt_);}
	}
	lep1_eta_branch = 0;
	if (tree->GetBranch("lep1_eta") != 0) {
		lep1_eta_branch = tree->GetBranch("lep1_eta");
		if (lep1_eta_branch) {lep1_eta_branch->SetAddress(&lep1_eta_);}
	}
	lep1_phi_branch = 0;
	if (tree->GetBranch("lep1_phi") != 0) {
		lep1_phi_branch = tree->GetBranch("lep1_phi");
		if (lep1_phi_branch) {lep1_phi_branch->SetAddress(&lep1_phi_);}
	}
	lep1_mass_branch = 0;
	if (tree->GetBranch("lep1_mass") != 0) {
		lep1_mass_branch = tree->GetBranch("lep1_mass");
		if (lep1_mass_branch) {lep1_mass_branch->SetAddress(&lep1_mass_);}
	}
	lep2_is_mu_branch = 0;
	if (tree->GetBranch("lep2_is_mu") != 0) {
		lep2_is_mu_branch = tree->GetBranch("lep2_is_mu");
		if (lep2_is_mu_branch) {lep2_is_mu_branch->SetAddress(&lep2_is_mu_);}
	}
	lep2_is_el_branch = 0;
	if (tree->GetBranch("lep2_is_el") != 0) {
		lep2_is_el_branch = tree->GetBranch("lep2_is_el");
		if (lep2_is_el_branch) {lep2_is_el_branch->SetAddress(&lep2_is_el_);}
	}
	lep2_charge_branch = 0;
	if (tree->GetBranch("lep2_charge") != 0) {
		lep2_charge_branch = tree->GetBranch("lep2_charge");
		if (lep2_charge_branch) {lep2_charge_branch->SetAddress(&lep2_charge_);}
	}
	lep2_pdgid_branch = 0;
	if (tree->GetBranch("lep2_pdgid") != 0) {
		lep2_pdgid_branch = tree->GetBranch("lep2_pdgid");
		if (lep2_pdgid_branch) {lep2_pdgid_branch->SetAddress(&lep2_pdgid_);}
	}
	lep2_type_branch = 0;
	if (tree->GetBranch("lep2_type") != 0) {
		lep2_type_branch = tree->GetBranch("lep2_type");
		if (lep2_type_branch) {lep2_type_branch->SetAddress(&lep2_type_);}
	}
	lep2_production_type_branch = 0;
	if (tree->GetBranch("lep2_production_type") != 0) {
		lep2_production_type_branch = tree->GetBranch("lep2_production_type");
		if (lep2_production_type_branch) {lep2_production_type_branch->SetAddress(&lep2_production_type_);}
	}
	lep2_d0_branch = 0;
	if (tree->GetBranch("lep2_d0") != 0) {
		lep2_d0_branch = tree->GetBranch("lep2_d0");
		if (lep2_d0_branch) {lep2_d0_branch->SetAddress(&lep2_d0_);}
	}
	lep2_d0err_branch = 0;
	if (tree->GetBranch("lep2_d0err") != 0) {
		lep2_d0err_branch = tree->GetBranch("lep2_d0err");
		if (lep2_d0err_branch) {lep2_d0err_branch->SetAddress(&lep2_d0err_);}
	}
	lep2_dz_branch = 0;
	if (tree->GetBranch("lep2_dz") != 0) {
		lep2_dz_branch = tree->GetBranch("lep2_dz");
		if (lep2_dz_branch) {lep2_dz_branch->SetAddress(&lep2_dz_);}
	}
	lep2_dzerr_branch = 0;
	if (tree->GetBranch("lep2_dzerr") != 0) {
		lep2_dzerr_branch = tree->GetBranch("lep2_dzerr");
		if (lep2_dzerr_branch) {lep2_dzerr_branch->SetAddress(&lep2_dzerr_);}
	}
	lep2_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("lep2_sigmaIEtaEta_fill5x5") != 0) {
		lep2_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("lep2_sigmaIEtaEta_fill5x5");
		if (lep2_sigmaIEtaEta_fill5x5_branch) {lep2_sigmaIEtaEta_fill5x5_branch->SetAddress(&lep2_sigmaIEtaEta_fill5x5_);}
	}
	lep2_dEtaIn_branch = 0;
	if (tree->GetBranch("lep2_dEtaIn") != 0) {
		lep2_dEtaIn_branch = tree->GetBranch("lep2_dEtaIn");
		if (lep2_dEtaIn_branch) {lep2_dEtaIn_branch->SetAddress(&lep2_dEtaIn_);}
	}
	lep2_dPhiIn_branch = 0;
	if (tree->GetBranch("lep2_dPhiIn") != 0) {
		lep2_dPhiIn_branch = tree->GetBranch("lep2_dPhiIn");
		if (lep2_dPhiIn_branch) {lep2_dPhiIn_branch->SetAddress(&lep2_dPhiIn_);}
	}
	lep2_hOverE_branch = 0;
	if (tree->GetBranch("lep2_hOverE") != 0) {
		lep2_hOverE_branch = tree->GetBranch("lep2_hOverE");
		if (lep2_hOverE_branch) {lep2_hOverE_branch->SetAddress(&lep2_hOverE_);}
	}
	lep2_ooEmooP_branch = 0;
	if (tree->GetBranch("lep2_ooEmooP") != 0) {
		lep2_ooEmooP_branch = tree->GetBranch("lep2_ooEmooP");
		if (lep2_ooEmooP_branch) {lep2_ooEmooP_branch->SetAddress(&lep2_ooEmooP_);}
	}
	lep2_expectedMissingInnerHits_branch = 0;
	if (tree->GetBranch("lep2_expectedMissingInnerHits") != 0) {
		lep2_expectedMissingInnerHits_branch = tree->GetBranch("lep2_expectedMissingInnerHits");
		if (lep2_expectedMissingInnerHits_branch) {lep2_expectedMissingInnerHits_branch->SetAddress(&lep2_expectedMissingInnerHits_);}
	}
	lep2_conversionVeto_branch = 0;
	if (tree->GetBranch("lep2_conversionVeto") != 0) {
		lep2_conversionVeto_branch = tree->GetBranch("lep2_conversionVeto");
		if (lep2_conversionVeto_branch) {lep2_conversionVeto_branch->SetAddress(&lep2_conversionVeto_);}
	}
	lep2_etaSC_branch = 0;
	if (tree->GetBranch("lep2_etaSC") != 0) {
		lep2_etaSC_branch = tree->GetBranch("lep2_etaSC");
		if (lep2_etaSC_branch) {lep2_etaSC_branch->SetAddress(&lep2_etaSC_);}
	}
	lep2_ChiSqr_branch = 0;
	if (tree->GetBranch("lep2_ChiSqr") != 0) {
		lep2_ChiSqr_branch = tree->GetBranch("lep2_ChiSqr");
		if (lep2_ChiSqr_branch) {lep2_ChiSqr_branch->SetAddress(&lep2_ChiSqr_);}
	}
	lep2_chiso_branch = 0;
	if (tree->GetBranch("lep2_chiso") != 0) {
		lep2_chiso_branch = tree->GetBranch("lep2_chiso");
		if (lep2_chiso_branch) {lep2_chiso_branch->SetAddress(&lep2_chiso_);}
	}
	lep2_nhiso_branch = 0;
	if (tree->GetBranch("lep2_nhiso") != 0) {
		lep2_nhiso_branch = tree->GetBranch("lep2_nhiso");
		if (lep2_nhiso_branch) {lep2_nhiso_branch->SetAddress(&lep2_nhiso_);}
	}
	lep2_emiso_branch = 0;
	if (tree->GetBranch("lep2_emiso") != 0) {
		lep2_emiso_branch = tree->GetBranch("lep2_emiso");
		if (lep2_emiso_branch) {lep2_emiso_branch->SetAddress(&lep2_emiso_);}
	}
	lep2_deltaBeta_branch = 0;
	if (tree->GetBranch("lep2_deltaBeta") != 0) {
		lep2_deltaBeta_branch = tree->GetBranch("lep2_deltaBeta");
		if (lep2_deltaBeta_branch) {lep2_deltaBeta_branch->SetAddress(&lep2_deltaBeta_);}
	}
	lep2_relIso03DB_branch = 0;
	if (tree->GetBranch("lep2_relIso03DB") != 0) {
		lep2_relIso03DB_branch = tree->GetBranch("lep2_relIso03DB");
		if (lep2_relIso03DB_branch) {lep2_relIso03DB_branch->SetAddress(&lep2_relIso03DB_);}
	}
	lep2_relIso03EA_branch = 0;
	if (tree->GetBranch("lep2_relIso03EA") != 0) {
		lep2_relIso03EA_branch = tree->GetBranch("lep2_relIso03EA");
		if (lep2_relIso03EA_branch) {lep2_relIso03EA_branch->SetAddress(&lep2_relIso03EA_);}
	}
	lep2_relIso04DB_branch = 0;
	if (tree->GetBranch("lep2_relIso04DB") != 0) {
		lep2_relIso04DB_branch = tree->GetBranch("lep2_relIso04DB");
		if (lep2_relIso04DB_branch) {lep2_relIso04DB_branch->SetAddress(&lep2_relIso04DB_);}
	}
	lep2_miniRelIsoDB_branch = 0;
	if (tree->GetBranch("lep2_miniRelIsoDB") != 0) {
		lep2_miniRelIsoDB_branch = tree->GetBranch("lep2_miniRelIsoDB");
		if (lep2_miniRelIsoDB_branch) {lep2_miniRelIsoDB_branch->SetAddress(&lep2_miniRelIsoDB_);}
	}
	lep2_miniRelIsoEA_branch = 0;
	if (tree->GetBranch("lep2_miniRelIsoEA") != 0) {
		lep2_miniRelIsoEA_branch = tree->GetBranch("lep2_miniRelIsoEA");
		if (lep2_miniRelIsoEA_branch) {lep2_miniRelIsoEA_branch->SetAddress(&lep2_miniRelIsoEA_);}
	}
	lep2_MiniIso_branch = 0;
	if (tree->GetBranch("lep2_MiniIso") != 0) {
		lep2_MiniIso_branch = tree->GetBranch("lep2_MiniIso");
		if (lep2_MiniIso_branch) {lep2_MiniIso_branch->SetAddress(&lep2_MiniIso_);}
	}
	lep2_mcid_branch = 0;
	if (tree->GetBranch("lep2_mcid") != 0) {
		lep2_mcid_branch = tree->GetBranch("lep2_mcid");
		if (lep2_mcid_branch) {lep2_mcid_branch->SetAddress(&lep2_mcid_);}
	}
	lep2_mcstatus_branch = 0;
	if (tree->GetBranch("lep2_mcstatus") != 0) {
		lep2_mcstatus_branch = tree->GetBranch("lep2_mcstatus");
		if (lep2_mcstatus_branch) {lep2_mcstatus_branch->SetAddress(&lep2_mcstatus_);}
	}
	lep2_mc3dr_branch = 0;
	if (tree->GetBranch("lep2_mc3dr") != 0) {
		lep2_mc3dr_branch = tree->GetBranch("lep2_mc3dr");
		if (lep2_mc3dr_branch) {lep2_mc3dr_branch->SetAddress(&lep2_mc3dr_);}
	}
	lep2_mc3id_branch = 0;
	if (tree->GetBranch("lep2_mc3id") != 0) {
		lep2_mc3id_branch = tree->GetBranch("lep2_mc3id");
		if (lep2_mc3id_branch) {lep2_mc3id_branch->SetAddress(&lep2_mc3id_);}
	}
	lep2_mc3idx_branch = 0;
	if (tree->GetBranch("lep2_mc3idx") != 0) {
		lep2_mc3idx_branch = tree->GetBranch("lep2_mc3idx");
		if (lep2_mc3idx_branch) {lep2_mc3idx_branch->SetAddress(&lep2_mc3idx_);}
	}
	lep2_mc3motherid_branch = 0;
	if (tree->GetBranch("lep2_mc3motherid") != 0) {
		lep2_mc3motherid_branch = tree->GetBranch("lep2_mc3motherid");
		if (lep2_mc3motherid_branch) {lep2_mc3motherid_branch->SetAddress(&lep2_mc3motherid_);}
	}
	lep2_mc3motheridx_branch = 0;
	if (tree->GetBranch("lep2_mc3motheridx") != 0) {
		lep2_mc3motheridx_branch = tree->GetBranch("lep2_mc3motheridx");
		if (lep2_mc3motheridx_branch) {lep2_mc3motheridx_branch->SetAddress(&lep2_mc3motheridx_);}
	}
	lep2_is_eleid_loose_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_loose") != 0) {
		lep2_is_eleid_loose_branch = tree->GetBranch("lep2_is_eleid_loose");
		if (lep2_is_eleid_loose_branch) {lep2_is_eleid_loose_branch->SetAddress(&lep2_is_eleid_loose_);}
	}
	lep2_is_eleid_medium_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_medium") != 0) {
		lep2_is_eleid_medium_branch = tree->GetBranch("lep2_is_eleid_medium");
		if (lep2_is_eleid_medium_branch) {lep2_is_eleid_medium_branch->SetAddress(&lep2_is_eleid_medium_);}
	}
	lep2_is_eleid_tight_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_tight") != 0) {
		lep2_is_eleid_tight_branch = tree->GetBranch("lep2_is_eleid_tight");
		if (lep2_is_eleid_tight_branch) {lep2_is_eleid_tight_branch->SetAddress(&lep2_is_eleid_tight_);}
	}
	lep2_is_phys14_loose_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_loose_noIso") != 0) {
		lep2_is_phys14_loose_noIso_branch = tree->GetBranch("lep2_is_phys14_loose_noIso");
		if (lep2_is_phys14_loose_noIso_branch) {lep2_is_phys14_loose_noIso_branch->SetAddress(&lep2_is_phys14_loose_noIso_);}
	}
	lep2_is_phys14_medium_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_medium_noIso") != 0) {
		lep2_is_phys14_medium_noIso_branch = tree->GetBranch("lep2_is_phys14_medium_noIso");
		if (lep2_is_phys14_medium_noIso_branch) {lep2_is_phys14_medium_noIso_branch->SetAddress(&lep2_is_phys14_medium_noIso_);}
	}
	lep2_is_phys14_tight_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_tight_noIso") != 0) {
		lep2_is_phys14_tight_noIso_branch = tree->GetBranch("lep2_is_phys14_tight_noIso");
		if (lep2_is_phys14_tight_noIso_branch) {lep2_is_phys14_tight_noIso_branch->SetAddress(&lep2_is_phys14_tight_noIso_);}
	}
	lep2_eoverpin_branch = 0;
	if (tree->GetBranch("lep2_eoverpin") != 0) {
		lep2_eoverpin_branch = tree->GetBranch("lep2_eoverpin");
		if (lep2_eoverpin_branch) {lep2_eoverpin_branch->SetAddress(&lep2_eoverpin_);}
	}
	lep2_is_muoid_loose_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_loose") != 0) {
		lep2_is_muoid_loose_branch = tree->GetBranch("lep2_is_muoid_loose");
		if (lep2_is_muoid_loose_branch) {lep2_is_muoid_loose_branch->SetAddress(&lep2_is_muoid_loose_);}
	}
	lep2_is_muoid_medium_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_medium") != 0) {
		lep2_is_muoid_medium_branch = tree->GetBranch("lep2_is_muoid_medium");
		if (lep2_is_muoid_medium_branch) {lep2_is_muoid_medium_branch->SetAddress(&lep2_is_muoid_medium_);}
	}
	lep2_is_muoid_tight_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_tight") != 0) {
		lep2_is_muoid_tight_branch = tree->GetBranch("lep2_is_muoid_tight");
		if (lep2_is_muoid_tight_branch) {lep2_is_muoid_tight_branch->SetAddress(&lep2_is_muoid_tight_);}
	}
	lep2_ip3d_branch = 0;
	if (tree->GetBranch("lep2_ip3d") != 0) {
		lep2_ip3d_branch = tree->GetBranch("lep2_ip3d");
		if (lep2_ip3d_branch) {lep2_ip3d_branch->SetAddress(&lep2_ip3d_);}
	}
	lep2_ip3derr_branch = 0;
	if (tree->GetBranch("lep2_ip3derr") != 0) {
		lep2_ip3derr_branch = tree->GetBranch("lep2_ip3derr");
		if (lep2_ip3derr_branch) {lep2_ip3derr_branch->SetAddress(&lep2_ip3derr_);}
	}
	lep2_is_pfmu_branch = 0;
	if (tree->GetBranch("lep2_is_pfmu") != 0) {
		lep2_is_pfmu_branch = tree->GetBranch("lep2_is_pfmu");
		if (lep2_is_pfmu_branch) {lep2_is_pfmu_branch->SetAddress(&lep2_is_pfmu_);}
	}
	lep2_passMediumID_branch = 0;
	if (tree->GetBranch("lep2_passMediumID") != 0) {
		lep2_passMediumID_branch = tree->GetBranch("lep2_passMediumID");
		if (lep2_passMediumID_branch) {lep2_passMediumID_branch->SetAddress(&lep2_passMediumID_);}
	}
	lep2_passVeto_branch = 0;
	if (tree->GetBranch("lep2_passVeto") != 0) {
		lep2_passVeto_branch = tree->GetBranch("lep2_passVeto");
		if (lep2_passVeto_branch) {lep2_passVeto_branch->SetAddress(&lep2_passVeto_);}
	}
	lep2_pt_branch = 0;
	if (tree->GetBranch("lep2_pt") != 0) {
		lep2_pt_branch = tree->GetBranch("lep2_pt");
		if (lep2_pt_branch) {lep2_pt_branch->SetAddress(&lep2_pt_);}
	}
	lep2_eta_branch = 0;
	if (tree->GetBranch("lep2_eta") != 0) {
		lep2_eta_branch = tree->GetBranch("lep2_eta");
		if (lep2_eta_branch) {lep2_eta_branch->SetAddress(&lep2_eta_);}
	}
	lep2_phi_branch = 0;
	if (tree->GetBranch("lep2_phi") != 0) {
		lep2_phi_branch = tree->GetBranch("lep2_phi");
		if (lep2_phi_branch) {lep2_phi_branch->SetAddress(&lep2_phi_);}
	}
	lep2_mass_branch = 0;
	if (tree->GetBranch("lep2_mass") != 0) {
		lep2_mass_branch = tree->GetBranch("lep2_mass");
		if (lep2_mass_branch) {lep2_mass_branch->SetAddress(&lep2_mass_);}
	}
	nGoodGenJets_branch = 0;
	if (tree->GetBranch("nGoodGenJets") != 0) {
		nGoodGenJets_branch = tree->GetBranch("nGoodGenJets");
		if (nGoodGenJets_branch) {nGoodGenJets_branch->SetAddress(&nGoodGenJets_);}
	}
	ngoodjets_branch = 0;
	if (tree->GetBranch("ngoodjets") != 0) {
		ngoodjets_branch = tree->GetBranch("ngoodjets");
		if (ngoodjets_branch) {ngoodjets_branch->SetAddress(&ngoodjets_);}
	}
	nfailjets_branch = 0;
	if (tree->GetBranch("nfailjets") != 0) {
		nfailjets_branch = tree->GetBranch("nfailjets");
		if (nfailjets_branch) {nfailjets_branch->SetAddress(&nfailjets_);}
	}
	ak8GoodPFJets_branch = 0;
	if (tree->GetBranch("ak8GoodPFJets") != 0) {
		ak8GoodPFJets_branch = tree->GetBranch("ak8GoodPFJets");
		if (ak8GoodPFJets_branch) {ak8GoodPFJets_branch->SetAddress(&ak8GoodPFJets_);}
	}
	ngoodbtags_branch = 0;
	if (tree->GetBranch("ngoodbtags") != 0) {
		ngoodbtags_branch = tree->GetBranch("ngoodbtags");
		if (ngoodbtags_branch) {ngoodbtags_branch->SetAddress(&ngoodbtags_);}
	}
	ak4_HT_branch = 0;
	if (tree->GetBranch("ak4_HT") != 0) {
		ak4_HT_branch = tree->GetBranch("ak4_HT");
		if (ak4_HT_branch) {ak4_HT_branch->SetAddress(&ak4_HT_);}
	}
	ak4_htssm_branch = 0;
	if (tree->GetBranch("ak4_htssm") != 0) {
		ak4_htssm_branch = tree->GetBranch("ak4_htssm");
		if (ak4_htssm_branch) {ak4_htssm_branch->SetAddress(&ak4_htssm_);}
	}
	ak4_htosm_branch = 0;
	if (tree->GetBranch("ak4_htosm") != 0) {
		ak4_htosm_branch = tree->GetBranch("ak4_htosm");
		if (ak4_htosm_branch) {ak4_htosm_branch->SetAddress(&ak4_htosm_);}
	}
	ak4_htratiom_branch = 0;
	if (tree->GetBranch("ak4_htratiom") != 0) {
		ak4_htratiom_branch = tree->GetBranch("ak4_htratiom");
		if (ak4_htratiom_branch) {ak4_htratiom_branch->SetAddress(&ak4_htratiom_);}
	}
	dphi_ak4pfjet_met_branch = 0;
	if (tree->GetBranch("dphi_ak4pfjet_met") != 0) {
		dphi_ak4pfjet_met_branch = tree->GetBranch("dphi_ak4pfjet_met");
		if (dphi_ak4pfjet_met_branch) {dphi_ak4pfjet_met_branch->SetAddress(&dphi_ak4pfjet_met_);}
	}
	ak4pfjets_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_pt") != 0) {
		ak4pfjets_pt_branch = tree->GetBranch("ak4pfjets_pt");
		if (ak4pfjets_pt_branch) {ak4pfjets_pt_branch->SetAddress(&ak4pfjets_pt_);}
	}
	ak4pfjets_eta_branch = 0;
	if (tree->GetBranch("ak4pfjets_eta") != 0) {
		ak4pfjets_eta_branch = tree->GetBranch("ak4pfjets_eta");
		if (ak4pfjets_eta_branch) {ak4pfjets_eta_branch->SetAddress(&ak4pfjets_eta_);}
	}
	ak4pfjets_phi_branch = 0;
	if (tree->GetBranch("ak4pfjets_phi") != 0) {
		ak4pfjets_phi_branch = tree->GetBranch("ak4pfjets_phi");
		if (ak4pfjets_phi_branch) {ak4pfjets_phi_branch->SetAddress(&ak4pfjets_phi_);}
	}
	ak4pfjets_mass_branch = 0;
	if (tree->GetBranch("ak4pfjets_mass") != 0) {
		ak4pfjets_mass_branch = tree->GetBranch("ak4pfjets_mass");
		if (ak4pfjets_mass_branch) {ak4pfjets_mass_branch->SetAddress(&ak4pfjets_mass_);}
	}
	ak4pfjets_passMEDbtag_branch = 0;
	if (tree->GetBranch("ak4pfjets_passMEDbtag") != 0) {
		ak4pfjets_passMEDbtag_branch = tree->GetBranch("ak4pfjets_passMEDbtag");
		if (ak4pfjets_passMEDbtag_branch) {ak4pfjets_passMEDbtag_branch->SetAddress(&ak4pfjets_passMEDbtag_);}
	}
	ak4pfjets_qg_disc_branch = 0;
	if (tree->GetBranch("ak4pfjets_qg_disc") != 0) {
		ak4pfjets_qg_disc_branch = tree->GetBranch("ak4pfjets_qg_disc");
		if (ak4pfjets_qg_disc_branch) {ak4pfjets_qg_disc_branch->SetAddress(&ak4pfjets_qg_disc_);}
	}
	ak4pfjets_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjets_CSV") != 0) {
		ak4pfjets_CSV_branch = tree->GetBranch("ak4pfjets_CSV");
		if (ak4pfjets_CSV_branch) {ak4pfjets_CSV_branch->SetAddress(&ak4pfjets_CSV_);}
	}
	ak4pfjets_puid_branch = 0;
	if (tree->GetBranch("ak4pfjets_puid") != 0) {
		ak4pfjets_puid_branch = tree->GetBranch("ak4pfjets_puid");
		if (ak4pfjets_puid_branch) {ak4pfjets_puid_branch->SetAddress(&ak4pfjets_puid_);}
	}
	ak4pfjets_parton_flavor_branch = 0;
	if (tree->GetBranch("ak4pfjets_parton_flavor") != 0) {
		ak4pfjets_parton_flavor_branch = tree->GetBranch("ak4pfjets_parton_flavor");
		if (ak4pfjets_parton_flavor_branch) {ak4pfjets_parton_flavor_branch->SetAddress(&ak4pfjets_parton_flavor_);}
	}
	ak4pfjets_loose_puid_branch = 0;
	if (tree->GetBranch("ak4pfjets_loose_puid") != 0) {
		ak4pfjets_loose_puid_branch = tree->GetBranch("ak4pfjets_loose_puid");
		if (ak4pfjets_loose_puid_branch) {ak4pfjets_loose_puid_branch->SetAddress(&ak4pfjets_loose_puid_);}
	}
	ak4pfjets_loose_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_loose_pfid") != 0) {
		ak4pfjets_loose_pfid_branch = tree->GetBranch("ak4pfjets_loose_pfid");
		if (ak4pfjets_loose_pfid_branch) {ak4pfjets_loose_pfid_branch->SetAddress(&ak4pfjets_loose_pfid_);}
	}
	ak4pfjets_medium_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_medium_pfid") != 0) {
		ak4pfjets_medium_pfid_branch = tree->GetBranch("ak4pfjets_medium_pfid");
		if (ak4pfjets_medium_pfid_branch) {ak4pfjets_medium_pfid_branch->SetAddress(&ak4pfjets_medium_pfid_);}
	}
	ak4pfjets_tight_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_tight_pfid") != 0) {
		ak4pfjets_tight_pfid_branch = tree->GetBranch("ak4pfjets_tight_pfid");
		if (ak4pfjets_tight_pfid_branch) {ak4pfjets_tight_pfid_branch->SetAddress(&ak4pfjets_tight_pfid_);}
	}
	ak4pfjets_MEDbjet_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_MEDbjet_pt") != 0) {
		ak4pfjets_MEDbjet_pt_branch = tree->GetBranch("ak4pfjets_MEDbjet_pt");
		if (ak4pfjets_MEDbjet_pt_branch) {ak4pfjets_MEDbjet_pt_branch->SetAddress(&ak4pfjets_MEDbjet_pt_);}
	}
	ak4pfjets_leadMEDbjet_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadMEDbjet_pt") != 0) {
		ak4pfjets_leadMEDbjet_pt_branch = tree->GetBranch("ak4pfjets_leadMEDbjet_pt");
		if (ak4pfjets_leadMEDbjet_pt_branch) {ak4pfjets_leadMEDbjet_pt_branch->SetAddress(&ak4pfjets_leadMEDbjet_pt_);}
	}
	ak4pfjets_chf_branch = 0;
	if (tree->GetBranch("ak4pfjets_chf") != 0) {
		ak4pfjets_chf_branch = tree->GetBranch("ak4pfjets_chf");
		if (ak4pfjets_chf_branch) {ak4pfjets_chf_branch->SetAddress(&ak4pfjets_chf_);}
	}
	ak4pfjets_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjets_nhf") != 0) {
		ak4pfjets_nhf_branch = tree->GetBranch("ak4pfjets_nhf");
		if (ak4pfjets_nhf_branch) {ak4pfjets_nhf_branch->SetAddress(&ak4pfjets_nhf_);}
	}
	ak4pfjets_cef_branch = 0;
	if (tree->GetBranch("ak4pfjets_cef") != 0) {
		ak4pfjets_cef_branch = tree->GetBranch("ak4pfjets_cef");
		if (ak4pfjets_cef_branch) {ak4pfjets_cef_branch->SetAddress(&ak4pfjets_cef_);}
	}
	ak4pfjets_nef_branch = 0;
	if (tree->GetBranch("ak4pfjets_nef") != 0) {
		ak4pfjets_nef_branch = tree->GetBranch("ak4pfjets_nef");
		if (ak4pfjets_nef_branch) {ak4pfjets_nef_branch->SetAddress(&ak4pfjets_nef_);}
	}
	ak4pfjets_muf_branch = 0;
	if (tree->GetBranch("ak4pfjets_muf") != 0) {
		ak4pfjets_muf_branch = tree->GetBranch("ak4pfjets_muf");
		if (ak4pfjets_muf_branch) {ak4pfjets_muf_branch->SetAddress(&ak4pfjets_muf_);}
	}
	ak4pfjets_cm_branch = 0;
	if (tree->GetBranch("ak4pfjets_cm") != 0) {
		ak4pfjets_cm_branch = tree->GetBranch("ak4pfjets_cm");
		if (ak4pfjets_cm_branch) {ak4pfjets_cm_branch->SetAddress(&ak4pfjets_cm_);}
	}
	ak4pfjets_nm_branch = 0;
	if (tree->GetBranch("ak4pfjets_nm") != 0) {
		ak4pfjets_nm_branch = tree->GetBranch("ak4pfjets_nm");
		if (ak4pfjets_nm_branch) {ak4pfjets_nm_branch->SetAddress(&ak4pfjets_nm_);}
	}
	ak4pfjets_mc3dr_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3dr") != 0) {
		ak4pfjets_mc3dr_branch = tree->GetBranch("ak4pfjets_mc3dr");
		if (ak4pfjets_mc3dr_branch) {ak4pfjets_mc3dr_branch->SetAddress(&ak4pfjets_mc3dr_);}
	}
	ak4pfjets_mc3id_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3id") != 0) {
		ak4pfjets_mc3id_branch = tree->GetBranch("ak4pfjets_mc3id");
		if (ak4pfjets_mc3id_branch) {ak4pfjets_mc3id_branch->SetAddress(&ak4pfjets_mc3id_);}
	}
	ak4pfjets_mc3idx_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3idx") != 0) {
		ak4pfjets_mc3idx_branch = tree->GetBranch("ak4pfjets_mc3idx");
		if (ak4pfjets_mc3idx_branch) {ak4pfjets_mc3idx_branch->SetAddress(&ak4pfjets_mc3idx_);}
	}
	ak4pfjets_mcmotherid_branch = 0;
	if (tree->GetBranch("ak4pfjets_mcmotherid") != 0) {
		ak4pfjets_mcmotherid_branch = tree->GetBranch("ak4pfjets_mcmotherid");
		if (ak4pfjets_mcmotherid_branch) {ak4pfjets_mcmotherid_branch->SetAddress(&ak4pfjets_mcmotherid_);}
	}
	ak4pfjet_overlep1_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_CSV") != 0) {
		ak4pfjet_overlep1_CSV_branch = tree->GetBranch("ak4pfjet_overlep1_CSV");
		if (ak4pfjet_overlep1_CSV_branch) {ak4pfjet_overlep1_CSV_branch->SetAddress(&ak4pfjet_overlep1_CSV_);}
	}
	ak4pfjet_overlep1_pu_id_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_pu_id") != 0) {
		ak4pfjet_overlep1_pu_id_branch = tree->GetBranch("ak4pfjet_overlep1_pu_id");
		if (ak4pfjet_overlep1_pu_id_branch) {ak4pfjet_overlep1_pu_id_branch->SetAddress(&ak4pfjet_overlep1_pu_id_);}
	}
	ak4pfjet_overlep1_chf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_chf") != 0) {
		ak4pfjet_overlep1_chf_branch = tree->GetBranch("ak4pfjet_overlep1_chf");
		if (ak4pfjet_overlep1_chf_branch) {ak4pfjet_overlep1_chf_branch->SetAddress(&ak4pfjet_overlep1_chf_);}
	}
	ak4pfjet_overlep1_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nhf") != 0) {
		ak4pfjet_overlep1_nhf_branch = tree->GetBranch("ak4pfjet_overlep1_nhf");
		if (ak4pfjet_overlep1_nhf_branch) {ak4pfjet_overlep1_nhf_branch->SetAddress(&ak4pfjet_overlep1_nhf_);}
	}
	ak4pfjet_overlep1_cef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_cef") != 0) {
		ak4pfjet_overlep1_cef_branch = tree->GetBranch("ak4pfjet_overlep1_cef");
		if (ak4pfjet_overlep1_cef_branch) {ak4pfjet_overlep1_cef_branch->SetAddress(&ak4pfjet_overlep1_cef_);}
	}
	ak4pfjet_overlep1_nef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nef") != 0) {
		ak4pfjet_overlep1_nef_branch = tree->GetBranch("ak4pfjet_overlep1_nef");
		if (ak4pfjet_overlep1_nef_branch) {ak4pfjet_overlep1_nef_branch->SetAddress(&ak4pfjet_overlep1_nef_);}
	}
	ak4pfjet_overlep1_muf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_muf") != 0) {
		ak4pfjet_overlep1_muf_branch = tree->GetBranch("ak4pfjet_overlep1_muf");
		if (ak4pfjet_overlep1_muf_branch) {ak4pfjet_overlep1_muf_branch->SetAddress(&ak4pfjet_overlep1_muf_);}
	}
	ak4pfjet_overlep1_cm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_cm") != 0) {
		ak4pfjet_overlep1_cm_branch = tree->GetBranch("ak4pfjet_overlep1_cm");
		if (ak4pfjet_overlep1_cm_branch) {ak4pfjet_overlep1_cm_branch->SetAddress(&ak4pfjet_overlep1_cm_);}
	}
	ak4pfjet_overlep1_nm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nm") != 0) {
		ak4pfjet_overlep1_nm_branch = tree->GetBranch("ak4pfjet_overlep1_nm");
		if (ak4pfjet_overlep1_nm_branch) {ak4pfjet_overlep1_nm_branch->SetAddress(&ak4pfjet_overlep1_nm_);}
	}
	ak4pfjet_overlep2_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_CSV") != 0) {
		ak4pfjet_overlep2_CSV_branch = tree->GetBranch("ak4pfjet_overlep2_CSV");
		if (ak4pfjet_overlep2_CSV_branch) {ak4pfjet_overlep2_CSV_branch->SetAddress(&ak4pfjet_overlep2_CSV_);}
	}
	ak4pfjet_overlep2_pu_id_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_pu_id") != 0) {
		ak4pfjet_overlep2_pu_id_branch = tree->GetBranch("ak4pfjet_overlep2_pu_id");
		if (ak4pfjet_overlep2_pu_id_branch) {ak4pfjet_overlep2_pu_id_branch->SetAddress(&ak4pfjet_overlep2_pu_id_);}
	}
	ak4pfjet_overlep2_chf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_chf") != 0) {
		ak4pfjet_overlep2_chf_branch = tree->GetBranch("ak4pfjet_overlep2_chf");
		if (ak4pfjet_overlep2_chf_branch) {ak4pfjet_overlep2_chf_branch->SetAddress(&ak4pfjet_overlep2_chf_);}
	}
	ak4pfjet_overlep2_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nhf") != 0) {
		ak4pfjet_overlep2_nhf_branch = tree->GetBranch("ak4pfjet_overlep2_nhf");
		if (ak4pfjet_overlep2_nhf_branch) {ak4pfjet_overlep2_nhf_branch->SetAddress(&ak4pfjet_overlep2_nhf_);}
	}
	ak4pfjet_overlep2_cef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_cef") != 0) {
		ak4pfjet_overlep2_cef_branch = tree->GetBranch("ak4pfjet_overlep2_cef");
		if (ak4pfjet_overlep2_cef_branch) {ak4pfjet_overlep2_cef_branch->SetAddress(&ak4pfjet_overlep2_cef_);}
	}
	ak4pfjet_overlep2_nef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nef") != 0) {
		ak4pfjet_overlep2_nef_branch = tree->GetBranch("ak4pfjet_overlep2_nef");
		if (ak4pfjet_overlep2_nef_branch) {ak4pfjet_overlep2_nef_branch->SetAddress(&ak4pfjet_overlep2_nef_);}
	}
	ak4pfjet_overlep2_muf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_muf") != 0) {
		ak4pfjet_overlep2_muf_branch = tree->GetBranch("ak4pfjet_overlep2_muf");
		if (ak4pfjet_overlep2_muf_branch) {ak4pfjet_overlep2_muf_branch->SetAddress(&ak4pfjet_overlep2_muf_);}
	}
	ak4pfjet_overlep2_cm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_cm") != 0) {
		ak4pfjet_overlep2_cm_branch = tree->GetBranch("ak4pfjet_overlep2_cm");
		if (ak4pfjet_overlep2_cm_branch) {ak4pfjet_overlep2_cm_branch->SetAddress(&ak4pfjet_overlep2_cm_);}
	}
	ak4pfjet_overlep2_nm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nm") != 0) {
		ak4pfjet_overlep2_nm_branch = tree->GetBranch("ak4pfjet_overlep2_nm");
		if (ak4pfjet_overlep2_nm_branch) {ak4pfjet_overlep2_nm_branch->SetAddress(&ak4pfjet_overlep2_nm_);}
	}
	ak8pfjets_tau1_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau1") != 0) {
		ak8pfjets_tau1_branch = tree->GetBranch("ak8pfjets_tau1");
		if (ak8pfjets_tau1_branch) {ak8pfjets_tau1_branch->SetAddress(&ak8pfjets_tau1_);}
	}
	ak8pfjets_tau2_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau2") != 0) {
		ak8pfjets_tau2_branch = tree->GetBranch("ak8pfjets_tau2");
		if (ak8pfjets_tau2_branch) {ak8pfjets_tau2_branch->SetAddress(&ak8pfjets_tau2_);}
	}
	ak8pfjets_tau3_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau3") != 0) {
		ak8pfjets_tau3_branch = tree->GetBranch("ak8pfjets_tau3");
		if (ak8pfjets_tau3_branch) {ak8pfjets_tau3_branch->SetAddress(&ak8pfjets_tau3_);}
	}
	ak8pfjets_top_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_top_mass") != 0) {
		ak8pfjets_top_mass_branch = tree->GetBranch("ak8pfjets_top_mass");
		if (ak8pfjets_top_mass_branch) {ak8pfjets_top_mass_branch->SetAddress(&ak8pfjets_top_mass_);}
	}
	ak8pfjets_pruned_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_pruned_mass") != 0) {
		ak8pfjets_pruned_mass_branch = tree->GetBranch("ak8pfjets_pruned_mass");
		if (ak8pfjets_pruned_mass_branch) {ak8pfjets_pruned_mass_branch->SetAddress(&ak8pfjets_pruned_mass_);}
	}
	ak8pfjets_trimmed_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_trimmed_mass") != 0) {
		ak8pfjets_trimmed_mass_branch = tree->GetBranch("ak8pfjets_trimmed_mass");
		if (ak8pfjets_trimmed_mass_branch) {ak8pfjets_trimmed_mass_branch->SetAddress(&ak8pfjets_trimmed_mass_);}
	}
	ak8pfjets_filtered_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_filtered_mass") != 0) {
		ak8pfjets_filtered_mass_branch = tree->GetBranch("ak8pfjets_filtered_mass");
		if (ak8pfjets_filtered_mass_branch) {ak8pfjets_filtered_mass_branch->SetAddress(&ak8pfjets_filtered_mass_);}
	}
	ak8pfjets_pu_id_branch = 0;
	if (tree->GetBranch("ak8pfjets_pu_id") != 0) {
		ak8pfjets_pu_id_branch = tree->GetBranch("ak8pfjets_pu_id");
		if (ak8pfjets_pu_id_branch) {ak8pfjets_pu_id_branch->SetAddress(&ak8pfjets_pu_id_);}
	}
	ak8pfjets_parton_flavor_branch = 0;
	if (tree->GetBranch("ak8pfjets_parton_flavor") != 0) {
		ak8pfjets_parton_flavor_branch = tree->GetBranch("ak8pfjets_parton_flavor");
		if (ak8pfjets_parton_flavor_branch) {ak8pfjets_parton_flavor_branch->SetAddress(&ak8pfjets_parton_flavor_);}
	}
	tau_IDnames_branch = 0;
	if (tree->GetBranch("tau_IDnames") != 0) {
		tau_IDnames_branch = tree->GetBranch("tau_IDnames");
		if (tau_IDnames_branch) {tau_IDnames_branch->SetAddress(&tau_IDnames_);}
	}
	tau_isocand_p4_branch = 0;
	if (tree->GetBranch("tau_isocand_p4") != 0) {
		tau_isocand_p4_branch = tree->GetBranch("tau_isocand_p4");
		if (tau_isocand_p4_branch) {tau_isocand_p4_branch->SetAddress(&tau_isocand_p4_);}
	}
	tau_sigcand_p4_branch = 0;
	if (tree->GetBranch("tau_sigcand_p4") != 0) {
		tau_sigcand_p4_branch = tree->GetBranch("tau_sigcand_p4");
		if (tau_sigcand_p4_branch) {tau_sigcand_p4_branch->SetAddress(&tau_sigcand_p4_);}
	}
	tau_mass_branch = 0;
	if (tree->GetBranch("tau_mass") != 0) {
		tau_mass_branch = tree->GetBranch("tau_mass");
		if (tau_mass_branch) {tau_mass_branch->SetAddress(&tau_mass_);}
	}
	tau_ID_branch = 0;
	if (tree->GetBranch("tau_ID") != 0) {
		tau_ID_branch = tree->GetBranch("tau_ID");
		if (tau_ID_branch) {tau_ID_branch->SetAddress(&tau_ID_);}
	}
	tau_passID_branch = 0;
	if (tree->GetBranch("tau_passID") != 0) {
		tau_passID_branch = tree->GetBranch("tau_passID");
		if (tau_passID_branch) {tau_passID_branch->SetAddress(&tau_passID_);}
	}
	tau_charge_branch = 0;
	if (tree->GetBranch("tau_charge") != 0) {
		tau_charge_branch = tree->GetBranch("tau_charge");
		if (tau_charge_branch) {tau_charge_branch->SetAddress(&tau_charge_);}
	}
	ngoodtaus_branch = 0;
	if (tree->GetBranch("ngoodtaus") != 0) {
		ngoodtaus_branch = tree->GetBranch("ngoodtaus");
		if (ngoodtaus_branch) {ngoodtaus_branch->SetAddress(&ngoodtaus_);}
	}
	tau_againstMuonTight_branch = 0;
	if (tree->GetBranch("tau_againstMuonTight") != 0) {
		tau_againstMuonTight_branch = tree->GetBranch("tau_againstMuonTight");
		if (tau_againstMuonTight_branch) {tau_againstMuonTight_branch->SetAddress(&tau_againstMuonTight_);}
	}
	tau_againstElectronLoose_branch = 0;
	if (tree->GetBranch("tau_againstElectronLoose") != 0) {
		tau_againstElectronLoose_branch = tree->GetBranch("tau_againstElectronLoose");
		if (tau_againstElectronLoose_branch) {tau_againstElectronLoose_branch->SetAddress(&tau_againstElectronLoose_);}
	}
	tau_isVetoTau_branch = 0;
	if (tree->GetBranch("tau_isVetoTau") != 0) {
		tau_isVetoTau_branch = tree->GetBranch("tau_isVetoTau");
		if (tau_isVetoTau_branch) {tau_isVetoTau_branch->SetAddress(&tau_isVetoTau_);}
	}
	isoTracks_charge_branch = 0;
	if (tree->GetBranch("isoTracks_charge") != 0) {
		isoTracks_charge_branch = tree->GetBranch("isoTracks_charge");
		if (isoTracks_charge_branch) {isoTracks_charge_branch->SetAddress(&isoTracks_charge_);}
	}
	isoTracks_absIso_branch = 0;
	if (tree->GetBranch("isoTracks_absIso") != 0) {
		isoTracks_absIso_branch = tree->GetBranch("isoTracks_absIso");
		if (isoTracks_absIso_branch) {isoTracks_absIso_branch->SetAddress(&isoTracks_absIso_);}
	}
	isoTracks_dz_branch = 0;
	if (tree->GetBranch("isoTracks_dz") != 0) {
		isoTracks_dz_branch = tree->GetBranch("isoTracks_dz");
		if (isoTracks_dz_branch) {isoTracks_dz_branch->SetAddress(&isoTracks_dz_);}
	}
	isoTracks_pdgId_branch = 0;
	if (tree->GetBranch("isoTracks_pdgId") != 0) {
		isoTracks_pdgId_branch = tree->GetBranch("isoTracks_pdgId");
		if (isoTracks_pdgId_branch) {isoTracks_pdgId_branch->SetAddress(&isoTracks_pdgId_);}
	}
	isoTracks_selectedidx_branch = 0;
	if (tree->GetBranch("isoTracks_selectedidx") != 0) {
		isoTracks_selectedidx_branch = tree->GetBranch("isoTracks_selectedidx");
		if (isoTracks_selectedidx_branch) {isoTracks_selectedidx_branch->SetAddress(&isoTracks_selectedidx_);}
	}
	isoTracks_nselected_branch = 0;
	if (tree->GetBranch("isoTracks_nselected") != 0) {
		isoTracks_nselected_branch = tree->GetBranch("isoTracks_nselected");
		if (isoTracks_nselected_branch) {isoTracks_nselected_branch->SetAddress(&isoTracks_nselected_);}
	}
	isoTracks_isVetoTrack_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack") != 0) {
		isoTracks_isVetoTrack_branch = tree->GetBranch("isoTracks_isVetoTrack");
		if (isoTracks_isVetoTrack_branch) {isoTracks_isVetoTrack_branch->SetAddress(&isoTracks_isVetoTrack_);}
	}
	isoTracks_isVetoTrack_v2_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack_v2") != 0) {
		isoTracks_isVetoTrack_v2_branch = tree->GetBranch("isoTracks_isVetoTrack_v2");
		if (isoTracks_isVetoTrack_v2_branch) {isoTracks_isVetoTrack_v2_branch->SetAddress(&isoTracks_isVetoTrack_v2_);}
	}
	isoTracks_isVetoTrack_v3_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack_v3") != 0) {
		isoTracks_isVetoTrack_v3_branch = tree->GetBranch("isoTracks_isVetoTrack_v3");
		if (isoTracks_isVetoTrack_v3_branch) {isoTracks_isVetoTrack_v3_branch->SetAddress(&isoTracks_isVetoTrack_v3_);}
	}
	genels_isfromt_branch = 0;
	if (tree->GetBranch("genels_isfromt") != 0) {
		genels_isfromt_branch = tree->GetBranch("genels_isfromt");
		if (genels_isfromt_branch) {genels_isfromt_branch->SetAddress(&genels_isfromt_);}
	}
	genels_charge_branch = 0;
	if (tree->GetBranch("genels_charge") != 0) {
		genels_charge_branch = tree->GetBranch("genels_charge");
		if (genels_charge_branch) {genels_charge_branch->SetAddress(&genels_charge_);}
	}
	genels_iso_branch = 0;
	if (tree->GetBranch("genels_iso") != 0) {
		genels_iso_branch = tree->GetBranch("genels_iso");
		if (genels_iso_branch) {genels_iso_branch->SetAddress(&genels_iso_);}
	}
	genels_mass_branch = 0;
	if (tree->GetBranch("genels_mass") != 0) {
		genels_mass_branch = tree->GetBranch("genels_mass");
		if (genels_mass_branch) {genels_mass_branch->SetAddress(&genels_mass_);}
	}
	genels_id_branch = 0;
	if (tree->GetBranch("genels_id") != 0) {
		genels_id_branch = tree->GetBranch("genels_id");
		if (genels_id_branch) {genels_id_branch->SetAddress(&genels_id_);}
	}
	genels__genpsidx_branch = 0;
	if (tree->GetBranch("genels__genpsidx") != 0) {
		genels__genpsidx_branch = tree->GetBranch("genels__genpsidx");
		if (genels__genpsidx_branch) {genels__genpsidx_branch->SetAddress(&genels__genpsidx_);}
	}
	genels_status_branch = 0;
	if (tree->GetBranch("genels_status") != 0) {
		genels_status_branch = tree->GetBranch("genels_status");
		if (genels_status_branch) {genels_status_branch->SetAddress(&genels_status_);}
	}
	genels_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genels_fromHardProcessBeforeFSR") != 0) {
		genels_fromHardProcessBeforeFSR_branch = tree->GetBranch("genels_fromHardProcessBeforeFSR");
		if (genels_fromHardProcessBeforeFSR_branch) {genels_fromHardProcessBeforeFSR_branch->SetAddress(&genels_fromHardProcessBeforeFSR_);}
	}
	genels_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genels_fromHardProcessDecayed") != 0) {
		genels_fromHardProcessDecayed_branch = tree->GetBranch("genels_fromHardProcessDecayed");
		if (genels_fromHardProcessDecayed_branch) {genels_fromHardProcessDecayed_branch->SetAddress(&genels_fromHardProcessDecayed_);}
	}
	genels_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genels_fromHardProcessFinalState") != 0) {
		genels_fromHardProcessFinalState_branch = tree->GetBranch("genels_fromHardProcessFinalState");
		if (genels_fromHardProcessFinalState_branch) {genels_fromHardProcessFinalState_branch->SetAddress(&genels_fromHardProcessFinalState_);}
	}
	genels_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genels_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genels_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genels_isDirectHardProcessTauDecayProductFinalState");
		if (genels_isDirectHardProcessTauDecayProductFinalState_branch) {genels_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genels_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genels_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genels_isDirectPromptTauDecayProductFinalState") != 0) {
		genels_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genels_isDirectPromptTauDecayProductFinalState");
		if (genels_isDirectPromptTauDecayProductFinalState_branch) {genels_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genels_isDirectPromptTauDecayProductFinalState_);}
	}
	genels_isHardProcess_branch = 0;
	if (tree->GetBranch("genels_isHardProcess") != 0) {
		genels_isHardProcess_branch = tree->GetBranch("genels_isHardProcess");
		if (genels_isHardProcess_branch) {genels_isHardProcess_branch->SetAddress(&genels_isHardProcess_);}
	}
	genels_isLastCopy_branch = 0;
	if (tree->GetBranch("genels_isLastCopy") != 0) {
		genels_isLastCopy_branch = tree->GetBranch("genels_isLastCopy");
		if (genels_isLastCopy_branch) {genels_isLastCopy_branch->SetAddress(&genels_isLastCopy_);}
	}
	genels_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genels_isLastCopyBeforeFSR") != 0) {
		genels_isLastCopyBeforeFSR_branch = tree->GetBranch("genels_isLastCopyBeforeFSR");
		if (genels_isLastCopyBeforeFSR_branch) {genels_isLastCopyBeforeFSR_branch->SetAddress(&genels_isLastCopyBeforeFSR_);}
	}
	genels_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genels_isMostlyLikePythia6Status3") != 0) {
		genels_isMostlyLikePythia6Status3_branch = tree->GetBranch("genels_isMostlyLikePythia6Status3");
		if (genels_isMostlyLikePythia6Status3_branch) {genels_isMostlyLikePythia6Status3_branch->SetAddress(&genels_isMostlyLikePythia6Status3_);}
	}
	genels_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genels_isPromptDecayed") != 0) {
		genels_isPromptDecayed_branch = tree->GetBranch("genels_isPromptDecayed");
		if (genels_isPromptDecayed_branch) {genels_isPromptDecayed_branch->SetAddress(&genels_isPromptDecayed_);}
	}
	genels_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genels_isPromptFinalState") != 0) {
		genels_isPromptFinalState_branch = tree->GetBranch("genels_isPromptFinalState");
		if (genels_isPromptFinalState_branch) {genels_isPromptFinalState_branch->SetAddress(&genels_isPromptFinalState_);}
	}
	genels_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genels_lepdaughter_id") != 0) {
		genels_lepdaughter_id_branch = tree->GetBranch("genels_lepdaughter_id");
		if (genels_lepdaughter_id_branch) {genels_lepdaughter_id_branch->SetAddress(&genels_lepdaughter_id_);}
	}
	genels_gentaudecay_branch = 0;
	if (tree->GetBranch("genels_gentaudecay") != 0) {
		genels_gentaudecay_branch = tree->GetBranch("genels_gentaudecay");
		if (genels_gentaudecay_branch) {genels_gentaudecay_branch->SetAddress(&genels_gentaudecay_);}
	}
	gen_nfromtels__branch = 0;
	if (tree->GetBranch("gen_nfromtels_") != 0) {
		gen_nfromtels__branch = tree->GetBranch("gen_nfromtels_");
		if (gen_nfromtels__branch) {gen_nfromtels__branch->SetAddress(&gen_nfromtels__);}
	}
	genels_mothercharge_branch = 0;
	if (tree->GetBranch("genels_mothercharge") != 0) {
		genels_mothercharge_branch = tree->GetBranch("genels_mothercharge");
		if (genels_mothercharge_branch) {genels_mothercharge_branch->SetAddress(&genels_mothercharge_);}
	}
	genels_motherid_branch = 0;
	if (tree->GetBranch("genels_motherid") != 0) {
		genels_motherid_branch = tree->GetBranch("genels_motherid");
		if (genels_motherid_branch) {genels_motherid_branch->SetAddress(&genels_motherid_);}
	}
	genels_motheridx_branch = 0;
	if (tree->GetBranch("genels_motheridx") != 0) {
		genels_motheridx_branch = tree->GetBranch("genels_motheridx");
		if (genels_motheridx_branch) {genels_motheridx_branch->SetAddress(&genels_motheridx_);}
	}
	genels_motherstatus_branch = 0;
	if (tree->GetBranch("genels_motherstatus") != 0) {
		genels_motherstatus_branch = tree->GetBranch("genels_motherstatus");
		if (genels_motherstatus_branch) {genels_motherstatus_branch->SetAddress(&genels_motherstatus_);}
	}
	genels_gmothercharge_branch = 0;
	if (tree->GetBranch("genels_gmothercharge") != 0) {
		genels_gmothercharge_branch = tree->GetBranch("genels_gmothercharge");
		if (genels_gmothercharge_branch) {genels_gmothercharge_branch->SetAddress(&genels_gmothercharge_);}
	}
	genels_gmotherid_branch = 0;
	if (tree->GetBranch("genels_gmotherid") != 0) {
		genels_gmotherid_branch = tree->GetBranch("genels_gmotherid");
		if (genels_gmotherid_branch) {genels_gmotherid_branch->SetAddress(&genels_gmotherid_);}
	}
	genels_gmotheridx_branch = 0;
	if (tree->GetBranch("genels_gmotheridx") != 0) {
		genels_gmotheridx_branch = tree->GetBranch("genels_gmotheridx");
		if (genels_gmotheridx_branch) {genels_gmotheridx_branch->SetAddress(&genels_gmotheridx_);}
	}
	genels_gmotherstatus_branch = 0;
	if (tree->GetBranch("genels_gmotherstatus") != 0) {
		genels_gmotherstatus_branch = tree->GetBranch("genels_gmotherstatus");
		if (genels_gmotherstatus_branch) {genels_gmotherstatus_branch->SetAddress(&genels_gmotherstatus_);}
	}
	genels_simplemothercharge_branch = 0;
	if (tree->GetBranch("genels_simplemothercharge") != 0) {
		genels_simplemothercharge_branch = tree->GetBranch("genels_simplemothercharge");
		if (genels_simplemothercharge_branch) {genels_simplemothercharge_branch->SetAddress(&genels_simplemothercharge_);}
	}
	genels_simplemotherid_branch = 0;
	if (tree->GetBranch("genels_simplemotherid") != 0) {
		genels_simplemotherid_branch = tree->GetBranch("genels_simplemotherid");
		if (genels_simplemotherid_branch) {genels_simplemotherid_branch->SetAddress(&genels_simplemotherid_);}
	}
	genels_simplemotheridx_branch = 0;
	if (tree->GetBranch("genels_simplemotheridx") != 0) {
		genels_simplemotheridx_branch = tree->GetBranch("genels_simplemotheridx");
		if (genels_simplemotheridx_branch) {genels_simplemotheridx_branch->SetAddress(&genels_simplemotheridx_);}
	}
	genels_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genels_simplemotherstatus") != 0) {
		genels_simplemotherstatus_branch = tree->GetBranch("genels_simplemotherstatus");
		if (genels_simplemotherstatus_branch) {genels_simplemotherstatus_branch->SetAddress(&genels_simplemotherstatus_);}
	}
	genels_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genels_simplegmothercharge") != 0) {
		genels_simplegmothercharge_branch = tree->GetBranch("genels_simplegmothercharge");
		if (genels_simplegmothercharge_branch) {genels_simplegmothercharge_branch->SetAddress(&genels_simplegmothercharge_);}
	}
	genels_simplegmotherid_branch = 0;
	if (tree->GetBranch("genels_simplegmotherid") != 0) {
		genels_simplegmotherid_branch = tree->GetBranch("genels_simplegmotherid");
		if (genels_simplegmotherid_branch) {genels_simplegmotherid_branch->SetAddress(&genels_simplegmotherid_);}
	}
	genels_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genels_simplegmotheridx") != 0) {
		genels_simplegmotheridx_branch = tree->GetBranch("genels_simplegmotheridx");
		if (genels_simplegmotheridx_branch) {genels_simplegmotheridx_branch->SetAddress(&genels_simplegmotheridx_);}
	}
	genels_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genels_simplegmotherstatus") != 0) {
		genels_simplegmotherstatus_branch = tree->GetBranch("genels_simplegmotherstatus");
		if (genels_simplegmotherstatus_branch) {genels_simplegmotherstatus_branch->SetAddress(&genels_simplegmotherstatus_);}
	}
	genmus_isfromt_branch = 0;
	if (tree->GetBranch("genmus_isfromt") != 0) {
		genmus_isfromt_branch = tree->GetBranch("genmus_isfromt");
		if (genmus_isfromt_branch) {genmus_isfromt_branch->SetAddress(&genmus_isfromt_);}
	}
	genmus_charge_branch = 0;
	if (tree->GetBranch("genmus_charge") != 0) {
		genmus_charge_branch = tree->GetBranch("genmus_charge");
		if (genmus_charge_branch) {genmus_charge_branch->SetAddress(&genmus_charge_);}
	}
	genmus_iso_branch = 0;
	if (tree->GetBranch("genmus_iso") != 0) {
		genmus_iso_branch = tree->GetBranch("genmus_iso");
		if (genmus_iso_branch) {genmus_iso_branch->SetAddress(&genmus_iso_);}
	}
	genmus_mass_branch = 0;
	if (tree->GetBranch("genmus_mass") != 0) {
		genmus_mass_branch = tree->GetBranch("genmus_mass");
		if (genmus_mass_branch) {genmus_mass_branch->SetAddress(&genmus_mass_);}
	}
	genmus_id_branch = 0;
	if (tree->GetBranch("genmus_id") != 0) {
		genmus_id_branch = tree->GetBranch("genmus_id");
		if (genmus_id_branch) {genmus_id_branch->SetAddress(&genmus_id_);}
	}
	genmus__genpsidx_branch = 0;
	if (tree->GetBranch("genmus__genpsidx") != 0) {
		genmus__genpsidx_branch = tree->GetBranch("genmus__genpsidx");
		if (genmus__genpsidx_branch) {genmus__genpsidx_branch->SetAddress(&genmus__genpsidx_);}
	}
	genmus_status_branch = 0;
	if (tree->GetBranch("genmus_status") != 0) {
		genmus_status_branch = tree->GetBranch("genmus_status");
		if (genmus_status_branch) {genmus_status_branch->SetAddress(&genmus_status_);}
	}
	genmus_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genmus_fromHardProcessBeforeFSR") != 0) {
		genmus_fromHardProcessBeforeFSR_branch = tree->GetBranch("genmus_fromHardProcessBeforeFSR");
		if (genmus_fromHardProcessBeforeFSR_branch) {genmus_fromHardProcessBeforeFSR_branch->SetAddress(&genmus_fromHardProcessBeforeFSR_);}
	}
	genmus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genmus_fromHardProcessDecayed") != 0) {
		genmus_fromHardProcessDecayed_branch = tree->GetBranch("genmus_fromHardProcessDecayed");
		if (genmus_fromHardProcessDecayed_branch) {genmus_fromHardProcessDecayed_branch->SetAddress(&genmus_fromHardProcessDecayed_);}
	}
	genmus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genmus_fromHardProcessFinalState") != 0) {
		genmus_fromHardProcessFinalState_branch = tree->GetBranch("genmus_fromHardProcessFinalState");
		if (genmus_fromHardProcessFinalState_branch) {genmus_fromHardProcessFinalState_branch->SetAddress(&genmus_fromHardProcessFinalState_);}
	}
	genmus_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genmus_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genmus_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genmus_isDirectHardProcessTauDecayProductFinalState");
		if (genmus_isDirectHardProcessTauDecayProductFinalState_branch) {genmus_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genmus_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genmus_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genmus_isDirectPromptTauDecayProductFinalState") != 0) {
		genmus_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genmus_isDirectPromptTauDecayProductFinalState");
		if (genmus_isDirectPromptTauDecayProductFinalState_branch) {genmus_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genmus_isDirectPromptTauDecayProductFinalState_);}
	}
	genmus_isHardProcess_branch = 0;
	if (tree->GetBranch("genmus_isHardProcess") != 0) {
		genmus_isHardProcess_branch = tree->GetBranch("genmus_isHardProcess");
		if (genmus_isHardProcess_branch) {genmus_isHardProcess_branch->SetAddress(&genmus_isHardProcess_);}
	}
	genmus_isLastCopy_branch = 0;
	if (tree->GetBranch("genmus_isLastCopy") != 0) {
		genmus_isLastCopy_branch = tree->GetBranch("genmus_isLastCopy");
		if (genmus_isLastCopy_branch) {genmus_isLastCopy_branch->SetAddress(&genmus_isLastCopy_);}
	}
	genmus_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genmus_isLastCopyBeforeFSR") != 0) {
		genmus_isLastCopyBeforeFSR_branch = tree->GetBranch("genmus_isLastCopyBeforeFSR");
		if (genmus_isLastCopyBeforeFSR_branch) {genmus_isLastCopyBeforeFSR_branch->SetAddress(&genmus_isLastCopyBeforeFSR_);}
	}
	genmus_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genmus_isMostlyLikePythia6Status3") != 0) {
		genmus_isMostlyLikePythia6Status3_branch = tree->GetBranch("genmus_isMostlyLikePythia6Status3");
		if (genmus_isMostlyLikePythia6Status3_branch) {genmus_isMostlyLikePythia6Status3_branch->SetAddress(&genmus_isMostlyLikePythia6Status3_);}
	}
	genmus_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genmus_isPromptDecayed") != 0) {
		genmus_isPromptDecayed_branch = tree->GetBranch("genmus_isPromptDecayed");
		if (genmus_isPromptDecayed_branch) {genmus_isPromptDecayed_branch->SetAddress(&genmus_isPromptDecayed_);}
	}
	genmus_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genmus_isPromptFinalState") != 0) {
		genmus_isPromptFinalState_branch = tree->GetBranch("genmus_isPromptFinalState");
		if (genmus_isPromptFinalState_branch) {genmus_isPromptFinalState_branch->SetAddress(&genmus_isPromptFinalState_);}
	}
	genmus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genmus_lepdaughter_id") != 0) {
		genmus_lepdaughter_id_branch = tree->GetBranch("genmus_lepdaughter_id");
		if (genmus_lepdaughter_id_branch) {genmus_lepdaughter_id_branch->SetAddress(&genmus_lepdaughter_id_);}
	}
	genmus_gentaudecay_branch = 0;
	if (tree->GetBranch("genmus_gentaudecay") != 0) {
		genmus_gentaudecay_branch = tree->GetBranch("genmus_gentaudecay");
		if (genmus_gentaudecay_branch) {genmus_gentaudecay_branch->SetAddress(&genmus_gentaudecay_);}
	}
	gen_nfromtmus__branch = 0;
	if (tree->GetBranch("gen_nfromtmus_") != 0) {
		gen_nfromtmus__branch = tree->GetBranch("gen_nfromtmus_");
		if (gen_nfromtmus__branch) {gen_nfromtmus__branch->SetAddress(&gen_nfromtmus__);}
	}
	genmus_mothercharge_branch = 0;
	if (tree->GetBranch("genmus_mothercharge") != 0) {
		genmus_mothercharge_branch = tree->GetBranch("genmus_mothercharge");
		if (genmus_mothercharge_branch) {genmus_mothercharge_branch->SetAddress(&genmus_mothercharge_);}
	}
	genmus_motherid_branch = 0;
	if (tree->GetBranch("genmus_motherid") != 0) {
		genmus_motherid_branch = tree->GetBranch("genmus_motherid");
		if (genmus_motherid_branch) {genmus_motherid_branch->SetAddress(&genmus_motherid_);}
	}
	genmus_motheridx_branch = 0;
	if (tree->GetBranch("genmus_motheridx") != 0) {
		genmus_motheridx_branch = tree->GetBranch("genmus_motheridx");
		if (genmus_motheridx_branch) {genmus_motheridx_branch->SetAddress(&genmus_motheridx_);}
	}
	genmus_motherstatus_branch = 0;
	if (tree->GetBranch("genmus_motherstatus") != 0) {
		genmus_motherstatus_branch = tree->GetBranch("genmus_motherstatus");
		if (genmus_motherstatus_branch) {genmus_motherstatus_branch->SetAddress(&genmus_motherstatus_);}
	}
	genmus_gmothercharge_branch = 0;
	if (tree->GetBranch("genmus_gmothercharge") != 0) {
		genmus_gmothercharge_branch = tree->GetBranch("genmus_gmothercharge");
		if (genmus_gmothercharge_branch) {genmus_gmothercharge_branch->SetAddress(&genmus_gmothercharge_);}
	}
	genmus_gmotherid_branch = 0;
	if (tree->GetBranch("genmus_gmotherid") != 0) {
		genmus_gmotherid_branch = tree->GetBranch("genmus_gmotherid");
		if (genmus_gmotherid_branch) {genmus_gmotherid_branch->SetAddress(&genmus_gmotherid_);}
	}
	genmus_gmotheridx_branch = 0;
	if (tree->GetBranch("genmus_gmotheridx") != 0) {
		genmus_gmotheridx_branch = tree->GetBranch("genmus_gmotheridx");
		if (genmus_gmotheridx_branch) {genmus_gmotheridx_branch->SetAddress(&genmus_gmotheridx_);}
	}
	genmus_gmotherstatus_branch = 0;
	if (tree->GetBranch("genmus_gmotherstatus") != 0) {
		genmus_gmotherstatus_branch = tree->GetBranch("genmus_gmotherstatus");
		if (genmus_gmotherstatus_branch) {genmus_gmotherstatus_branch->SetAddress(&genmus_gmotherstatus_);}
	}
	genmus_simplemothercharge_branch = 0;
	if (tree->GetBranch("genmus_simplemothercharge") != 0) {
		genmus_simplemothercharge_branch = tree->GetBranch("genmus_simplemothercharge");
		if (genmus_simplemothercharge_branch) {genmus_simplemothercharge_branch->SetAddress(&genmus_simplemothercharge_);}
	}
	genmus_simplemotherid_branch = 0;
	if (tree->GetBranch("genmus_simplemotherid") != 0) {
		genmus_simplemotherid_branch = tree->GetBranch("genmus_simplemotherid");
		if (genmus_simplemotherid_branch) {genmus_simplemotherid_branch->SetAddress(&genmus_simplemotherid_);}
	}
	genmus_simplemotheridx_branch = 0;
	if (tree->GetBranch("genmus_simplemotheridx") != 0) {
		genmus_simplemotheridx_branch = tree->GetBranch("genmus_simplemotheridx");
		if (genmus_simplemotheridx_branch) {genmus_simplemotheridx_branch->SetAddress(&genmus_simplemotheridx_);}
	}
	genmus_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genmus_simplemotherstatus") != 0) {
		genmus_simplemotherstatus_branch = tree->GetBranch("genmus_simplemotherstatus");
		if (genmus_simplemotherstatus_branch) {genmus_simplemotherstatus_branch->SetAddress(&genmus_simplemotherstatus_);}
	}
	genmus_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genmus_simplegmothercharge") != 0) {
		genmus_simplegmothercharge_branch = tree->GetBranch("genmus_simplegmothercharge");
		if (genmus_simplegmothercharge_branch) {genmus_simplegmothercharge_branch->SetAddress(&genmus_simplegmothercharge_);}
	}
	genmus_simplegmotherid_branch = 0;
	if (tree->GetBranch("genmus_simplegmotherid") != 0) {
		genmus_simplegmotherid_branch = tree->GetBranch("genmus_simplegmotherid");
		if (genmus_simplegmotherid_branch) {genmus_simplegmotherid_branch->SetAddress(&genmus_simplegmotherid_);}
	}
	genmus_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genmus_simplegmotheridx") != 0) {
		genmus_simplegmotheridx_branch = tree->GetBranch("genmus_simplegmotheridx");
		if (genmus_simplegmotheridx_branch) {genmus_simplegmotheridx_branch->SetAddress(&genmus_simplegmotheridx_);}
	}
	genmus_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genmus_simplegmotherstatus") != 0) {
		genmus_simplegmotherstatus_branch = tree->GetBranch("genmus_simplegmotherstatus");
		if (genmus_simplegmotherstatus_branch) {genmus_simplegmotherstatus_branch->SetAddress(&genmus_simplegmotherstatus_);}
	}
	gentaus_isfromt_branch = 0;
	if (tree->GetBranch("gentaus_isfromt") != 0) {
		gentaus_isfromt_branch = tree->GetBranch("gentaus_isfromt");
		if (gentaus_isfromt_branch) {gentaus_isfromt_branch->SetAddress(&gentaus_isfromt_);}
	}
	gentaus_charge_branch = 0;
	if (tree->GetBranch("gentaus_charge") != 0) {
		gentaus_charge_branch = tree->GetBranch("gentaus_charge");
		if (gentaus_charge_branch) {gentaus_charge_branch->SetAddress(&gentaus_charge_);}
	}
	gentaus_iso_branch = 0;
	if (tree->GetBranch("gentaus_iso") != 0) {
		gentaus_iso_branch = tree->GetBranch("gentaus_iso");
		if (gentaus_iso_branch) {gentaus_iso_branch->SetAddress(&gentaus_iso_);}
	}
	gentaus_mass_branch = 0;
	if (tree->GetBranch("gentaus_mass") != 0) {
		gentaus_mass_branch = tree->GetBranch("gentaus_mass");
		if (gentaus_mass_branch) {gentaus_mass_branch->SetAddress(&gentaus_mass_);}
	}
	gentaus_id_branch = 0;
	if (tree->GetBranch("gentaus_id") != 0) {
		gentaus_id_branch = tree->GetBranch("gentaus_id");
		if (gentaus_id_branch) {gentaus_id_branch->SetAddress(&gentaus_id_);}
	}
	gentaus__genpsidx_branch = 0;
	if (tree->GetBranch("gentaus__genpsidx") != 0) {
		gentaus__genpsidx_branch = tree->GetBranch("gentaus__genpsidx");
		if (gentaus__genpsidx_branch) {gentaus__genpsidx_branch->SetAddress(&gentaus__genpsidx_);}
	}
	gentaus_status_branch = 0;
	if (tree->GetBranch("gentaus_status") != 0) {
		gentaus_status_branch = tree->GetBranch("gentaus_status");
		if (gentaus_status_branch) {gentaus_status_branch->SetAddress(&gentaus_status_);}
	}
	gentaus_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gentaus_fromHardProcessBeforeFSR") != 0) {
		gentaus_fromHardProcessBeforeFSR_branch = tree->GetBranch("gentaus_fromHardProcessBeforeFSR");
		if (gentaus_fromHardProcessBeforeFSR_branch) {gentaus_fromHardProcessBeforeFSR_branch->SetAddress(&gentaus_fromHardProcessBeforeFSR_);}
	}
	gentaus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gentaus_fromHardProcessDecayed") != 0) {
		gentaus_fromHardProcessDecayed_branch = tree->GetBranch("gentaus_fromHardProcessDecayed");
		if (gentaus_fromHardProcessDecayed_branch) {gentaus_fromHardProcessDecayed_branch->SetAddress(&gentaus_fromHardProcessDecayed_);}
	}
	gentaus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gentaus_fromHardProcessFinalState") != 0) {
		gentaus_fromHardProcessFinalState_branch = tree->GetBranch("gentaus_fromHardProcessFinalState");
		if (gentaus_fromHardProcessFinalState_branch) {gentaus_fromHardProcessFinalState_branch->SetAddress(&gentaus_fromHardProcessFinalState_);}
	}
	gentaus_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gentaus_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gentaus_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gentaus_isDirectHardProcessTauDecayProductFinalState");
		if (gentaus_isDirectHardProcessTauDecayProductFinalState_branch) {gentaus_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gentaus_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gentaus_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gentaus_isDirectPromptTauDecayProductFinalState") != 0) {
		gentaus_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gentaus_isDirectPromptTauDecayProductFinalState");
		if (gentaus_isDirectPromptTauDecayProductFinalState_branch) {gentaus_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gentaus_isDirectPromptTauDecayProductFinalState_);}
	}
	gentaus_isHardProcess_branch = 0;
	if (tree->GetBranch("gentaus_isHardProcess") != 0) {
		gentaus_isHardProcess_branch = tree->GetBranch("gentaus_isHardProcess");
		if (gentaus_isHardProcess_branch) {gentaus_isHardProcess_branch->SetAddress(&gentaus_isHardProcess_);}
	}
	gentaus_isLastCopy_branch = 0;
	if (tree->GetBranch("gentaus_isLastCopy") != 0) {
		gentaus_isLastCopy_branch = tree->GetBranch("gentaus_isLastCopy");
		if (gentaus_isLastCopy_branch) {gentaus_isLastCopy_branch->SetAddress(&gentaus_isLastCopy_);}
	}
	gentaus_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gentaus_isLastCopyBeforeFSR") != 0) {
		gentaus_isLastCopyBeforeFSR_branch = tree->GetBranch("gentaus_isLastCopyBeforeFSR");
		if (gentaus_isLastCopyBeforeFSR_branch) {gentaus_isLastCopyBeforeFSR_branch->SetAddress(&gentaus_isLastCopyBeforeFSR_);}
	}
	gentaus_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gentaus_isMostlyLikePythia6Status3") != 0) {
		gentaus_isMostlyLikePythia6Status3_branch = tree->GetBranch("gentaus_isMostlyLikePythia6Status3");
		if (gentaus_isMostlyLikePythia6Status3_branch) {gentaus_isMostlyLikePythia6Status3_branch->SetAddress(&gentaus_isMostlyLikePythia6Status3_);}
	}
	gentaus_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gentaus_isPromptDecayed") != 0) {
		gentaus_isPromptDecayed_branch = tree->GetBranch("gentaus_isPromptDecayed");
		if (gentaus_isPromptDecayed_branch) {gentaus_isPromptDecayed_branch->SetAddress(&gentaus_isPromptDecayed_);}
	}
	gentaus_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gentaus_isPromptFinalState") != 0) {
		gentaus_isPromptFinalState_branch = tree->GetBranch("gentaus_isPromptFinalState");
		if (gentaus_isPromptFinalState_branch) {gentaus_isPromptFinalState_branch->SetAddress(&gentaus_isPromptFinalState_);}
	}
	gentaus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gentaus_lepdaughter_id") != 0) {
		gentaus_lepdaughter_id_branch = tree->GetBranch("gentaus_lepdaughter_id");
		if (gentaus_lepdaughter_id_branch) {gentaus_lepdaughter_id_branch->SetAddress(&gentaus_lepdaughter_id_);}
	}
	gentaus_gentaudecay_branch = 0;
	if (tree->GetBranch("gentaus_gentaudecay") != 0) {
		gentaus_gentaudecay_branch = tree->GetBranch("gentaus_gentaudecay");
		if (gentaus_gentaudecay_branch) {gentaus_gentaudecay_branch->SetAddress(&gentaus_gentaudecay_);}
	}
	gen_nfromttaus__branch = 0;
	if (tree->GetBranch("gen_nfromttaus_") != 0) {
		gen_nfromttaus__branch = tree->GetBranch("gen_nfromttaus_");
		if (gen_nfromttaus__branch) {gen_nfromttaus__branch->SetAddress(&gen_nfromttaus__);}
	}
	gentaus_mothercharge_branch = 0;
	if (tree->GetBranch("gentaus_mothercharge") != 0) {
		gentaus_mothercharge_branch = tree->GetBranch("gentaus_mothercharge");
		if (gentaus_mothercharge_branch) {gentaus_mothercharge_branch->SetAddress(&gentaus_mothercharge_);}
	}
	gentaus_motherid_branch = 0;
	if (tree->GetBranch("gentaus_motherid") != 0) {
		gentaus_motherid_branch = tree->GetBranch("gentaus_motherid");
		if (gentaus_motherid_branch) {gentaus_motherid_branch->SetAddress(&gentaus_motherid_);}
	}
	gentaus_motheridx_branch = 0;
	if (tree->GetBranch("gentaus_motheridx") != 0) {
		gentaus_motheridx_branch = tree->GetBranch("gentaus_motheridx");
		if (gentaus_motheridx_branch) {gentaus_motheridx_branch->SetAddress(&gentaus_motheridx_);}
	}
	gentaus_motherstatus_branch = 0;
	if (tree->GetBranch("gentaus_motherstatus") != 0) {
		gentaus_motherstatus_branch = tree->GetBranch("gentaus_motherstatus");
		if (gentaus_motherstatus_branch) {gentaus_motherstatus_branch->SetAddress(&gentaus_motherstatus_);}
	}
	gentaus_gmothercharge_branch = 0;
	if (tree->GetBranch("gentaus_gmothercharge") != 0) {
		gentaus_gmothercharge_branch = tree->GetBranch("gentaus_gmothercharge");
		if (gentaus_gmothercharge_branch) {gentaus_gmothercharge_branch->SetAddress(&gentaus_gmothercharge_);}
	}
	gentaus_gmotherid_branch = 0;
	if (tree->GetBranch("gentaus_gmotherid") != 0) {
		gentaus_gmotherid_branch = tree->GetBranch("gentaus_gmotherid");
		if (gentaus_gmotherid_branch) {gentaus_gmotherid_branch->SetAddress(&gentaus_gmotherid_);}
	}
	gentaus_gmotheridx_branch = 0;
	if (tree->GetBranch("gentaus_gmotheridx") != 0) {
		gentaus_gmotheridx_branch = tree->GetBranch("gentaus_gmotheridx");
		if (gentaus_gmotheridx_branch) {gentaus_gmotheridx_branch->SetAddress(&gentaus_gmotheridx_);}
	}
	gentaus_gmotherstatus_branch = 0;
	if (tree->GetBranch("gentaus_gmotherstatus") != 0) {
		gentaus_gmotherstatus_branch = tree->GetBranch("gentaus_gmotherstatus");
		if (gentaus_gmotherstatus_branch) {gentaus_gmotherstatus_branch->SetAddress(&gentaus_gmotherstatus_);}
	}
	gentaus_simplemothercharge_branch = 0;
	if (tree->GetBranch("gentaus_simplemothercharge") != 0) {
		gentaus_simplemothercharge_branch = tree->GetBranch("gentaus_simplemothercharge");
		if (gentaus_simplemothercharge_branch) {gentaus_simplemothercharge_branch->SetAddress(&gentaus_simplemothercharge_);}
	}
	gentaus_simplemotherid_branch = 0;
	if (tree->GetBranch("gentaus_simplemotherid") != 0) {
		gentaus_simplemotherid_branch = tree->GetBranch("gentaus_simplemotherid");
		if (gentaus_simplemotherid_branch) {gentaus_simplemotherid_branch->SetAddress(&gentaus_simplemotherid_);}
	}
	gentaus_simplemotheridx_branch = 0;
	if (tree->GetBranch("gentaus_simplemotheridx") != 0) {
		gentaus_simplemotheridx_branch = tree->GetBranch("gentaus_simplemotheridx");
		if (gentaus_simplemotheridx_branch) {gentaus_simplemotheridx_branch->SetAddress(&gentaus_simplemotheridx_);}
	}
	gentaus_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gentaus_simplemotherstatus") != 0) {
		gentaus_simplemotherstatus_branch = tree->GetBranch("gentaus_simplemotherstatus");
		if (gentaus_simplemotherstatus_branch) {gentaus_simplemotherstatus_branch->SetAddress(&gentaus_simplemotherstatus_);}
	}
	gentaus_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gentaus_simplegmothercharge") != 0) {
		gentaus_simplegmothercharge_branch = tree->GetBranch("gentaus_simplegmothercharge");
		if (gentaus_simplegmothercharge_branch) {gentaus_simplegmothercharge_branch->SetAddress(&gentaus_simplegmothercharge_);}
	}
	gentaus_simplegmotherid_branch = 0;
	if (tree->GetBranch("gentaus_simplegmotherid") != 0) {
		gentaus_simplegmotherid_branch = tree->GetBranch("gentaus_simplegmotherid");
		if (gentaus_simplegmotherid_branch) {gentaus_simplegmotherid_branch->SetAddress(&gentaus_simplegmotherid_);}
	}
	gentaus_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gentaus_simplegmotheridx") != 0) {
		gentaus_simplegmotheridx_branch = tree->GetBranch("gentaus_simplegmotheridx");
		if (gentaus_simplegmotheridx_branch) {gentaus_simplegmotheridx_branch->SetAddress(&gentaus_simplegmotheridx_);}
	}
	gentaus_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gentaus_simplegmotherstatus") != 0) {
		gentaus_simplegmotherstatus_branch = tree->GetBranch("gentaus_simplegmotherstatus");
		if (gentaus_simplegmotherstatus_branch) {gentaus_simplegmotherstatus_branch->SetAddress(&gentaus_simplegmotherstatus_);}
	}
	gennuels_isfromt_branch = 0;
	if (tree->GetBranch("gennuels_isfromt") != 0) {
		gennuels_isfromt_branch = tree->GetBranch("gennuels_isfromt");
		if (gennuels_isfromt_branch) {gennuels_isfromt_branch->SetAddress(&gennuels_isfromt_);}
	}
	gennuels_charge_branch = 0;
	if (tree->GetBranch("gennuels_charge") != 0) {
		gennuels_charge_branch = tree->GetBranch("gennuels_charge");
		if (gennuels_charge_branch) {gennuels_charge_branch->SetAddress(&gennuels_charge_);}
	}
	gennuels_iso_branch = 0;
	if (tree->GetBranch("gennuels_iso") != 0) {
		gennuels_iso_branch = tree->GetBranch("gennuels_iso");
		if (gennuels_iso_branch) {gennuels_iso_branch->SetAddress(&gennuels_iso_);}
	}
	gennuels_mass_branch = 0;
	if (tree->GetBranch("gennuels_mass") != 0) {
		gennuels_mass_branch = tree->GetBranch("gennuels_mass");
		if (gennuels_mass_branch) {gennuels_mass_branch->SetAddress(&gennuels_mass_);}
	}
	gennuels_id_branch = 0;
	if (tree->GetBranch("gennuels_id") != 0) {
		gennuels_id_branch = tree->GetBranch("gennuels_id");
		if (gennuels_id_branch) {gennuels_id_branch->SetAddress(&gennuels_id_);}
	}
	gennuels__genpsidx_branch = 0;
	if (tree->GetBranch("gennuels__genpsidx") != 0) {
		gennuels__genpsidx_branch = tree->GetBranch("gennuels__genpsidx");
		if (gennuels__genpsidx_branch) {gennuels__genpsidx_branch->SetAddress(&gennuels__genpsidx_);}
	}
	gennuels_status_branch = 0;
	if (tree->GetBranch("gennuels_status") != 0) {
		gennuels_status_branch = tree->GetBranch("gennuels_status");
		if (gennuels_status_branch) {gennuels_status_branch->SetAddress(&gennuels_status_);}
	}
	gennuels_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gennuels_fromHardProcessBeforeFSR") != 0) {
		gennuels_fromHardProcessBeforeFSR_branch = tree->GetBranch("gennuels_fromHardProcessBeforeFSR");
		if (gennuels_fromHardProcessBeforeFSR_branch) {gennuels_fromHardProcessBeforeFSR_branch->SetAddress(&gennuels_fromHardProcessBeforeFSR_);}
	}
	gennuels_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gennuels_fromHardProcessDecayed") != 0) {
		gennuels_fromHardProcessDecayed_branch = tree->GetBranch("gennuels_fromHardProcessDecayed");
		if (gennuels_fromHardProcessDecayed_branch) {gennuels_fromHardProcessDecayed_branch->SetAddress(&gennuels_fromHardProcessDecayed_);}
	}
	gennuels_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gennuels_fromHardProcessFinalState") != 0) {
		gennuels_fromHardProcessFinalState_branch = tree->GetBranch("gennuels_fromHardProcessFinalState");
		if (gennuels_fromHardProcessFinalState_branch) {gennuels_fromHardProcessFinalState_branch->SetAddress(&gennuels_fromHardProcessFinalState_);}
	}
	gennuels_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennuels_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gennuels_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gennuels_isDirectHardProcessTauDecayProductFinalState");
		if (gennuels_isDirectHardProcessTauDecayProductFinalState_branch) {gennuels_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gennuels_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gennuels_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennuels_isDirectPromptTauDecayProductFinalState") != 0) {
		gennuels_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gennuels_isDirectPromptTauDecayProductFinalState");
		if (gennuels_isDirectPromptTauDecayProductFinalState_branch) {gennuels_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gennuels_isDirectPromptTauDecayProductFinalState_);}
	}
	gennuels_isHardProcess_branch = 0;
	if (tree->GetBranch("gennuels_isHardProcess") != 0) {
		gennuels_isHardProcess_branch = tree->GetBranch("gennuels_isHardProcess");
		if (gennuels_isHardProcess_branch) {gennuels_isHardProcess_branch->SetAddress(&gennuels_isHardProcess_);}
	}
	gennuels_isLastCopy_branch = 0;
	if (tree->GetBranch("gennuels_isLastCopy") != 0) {
		gennuels_isLastCopy_branch = tree->GetBranch("gennuels_isLastCopy");
		if (gennuels_isLastCopy_branch) {gennuels_isLastCopy_branch->SetAddress(&gennuels_isLastCopy_);}
	}
	gennuels_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gennuels_isLastCopyBeforeFSR") != 0) {
		gennuels_isLastCopyBeforeFSR_branch = tree->GetBranch("gennuels_isLastCopyBeforeFSR");
		if (gennuels_isLastCopyBeforeFSR_branch) {gennuels_isLastCopyBeforeFSR_branch->SetAddress(&gennuels_isLastCopyBeforeFSR_);}
	}
	gennuels_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gennuels_isMostlyLikePythia6Status3") != 0) {
		gennuels_isMostlyLikePythia6Status3_branch = tree->GetBranch("gennuels_isMostlyLikePythia6Status3");
		if (gennuels_isMostlyLikePythia6Status3_branch) {gennuels_isMostlyLikePythia6Status3_branch->SetAddress(&gennuels_isMostlyLikePythia6Status3_);}
	}
	gennuels_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gennuels_isPromptDecayed") != 0) {
		gennuels_isPromptDecayed_branch = tree->GetBranch("gennuels_isPromptDecayed");
		if (gennuels_isPromptDecayed_branch) {gennuels_isPromptDecayed_branch->SetAddress(&gennuels_isPromptDecayed_);}
	}
	gennuels_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gennuels_isPromptFinalState") != 0) {
		gennuels_isPromptFinalState_branch = tree->GetBranch("gennuels_isPromptFinalState");
		if (gennuels_isPromptFinalState_branch) {gennuels_isPromptFinalState_branch->SetAddress(&gennuels_isPromptFinalState_);}
	}
	gennuels_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gennuels_lepdaughter_id") != 0) {
		gennuels_lepdaughter_id_branch = tree->GetBranch("gennuels_lepdaughter_id");
		if (gennuels_lepdaughter_id_branch) {gennuels_lepdaughter_id_branch->SetAddress(&gennuels_lepdaughter_id_);}
	}
	gennuels_gentaudecay_branch = 0;
	if (tree->GetBranch("gennuels_gentaudecay") != 0) {
		gennuels_gentaudecay_branch = tree->GetBranch("gennuels_gentaudecay");
		if (gennuels_gentaudecay_branch) {gennuels_gentaudecay_branch->SetAddress(&gennuels_gentaudecay_);}
	}
	gen_nfromtnuels__branch = 0;
	if (tree->GetBranch("gen_nfromtnuels_") != 0) {
		gen_nfromtnuels__branch = tree->GetBranch("gen_nfromtnuels_");
		if (gen_nfromtnuels__branch) {gen_nfromtnuels__branch->SetAddress(&gen_nfromtnuels__);}
	}
	gennuels_mothercharge_branch = 0;
	if (tree->GetBranch("gennuels_mothercharge") != 0) {
		gennuels_mothercharge_branch = tree->GetBranch("gennuels_mothercharge");
		if (gennuels_mothercharge_branch) {gennuels_mothercharge_branch->SetAddress(&gennuels_mothercharge_);}
	}
	gennuels_motherid_branch = 0;
	if (tree->GetBranch("gennuels_motherid") != 0) {
		gennuels_motherid_branch = tree->GetBranch("gennuels_motherid");
		if (gennuels_motherid_branch) {gennuels_motherid_branch->SetAddress(&gennuels_motherid_);}
	}
	gennuels_motheridx_branch = 0;
	if (tree->GetBranch("gennuels_motheridx") != 0) {
		gennuels_motheridx_branch = tree->GetBranch("gennuels_motheridx");
		if (gennuels_motheridx_branch) {gennuels_motheridx_branch->SetAddress(&gennuels_motheridx_);}
	}
	gennuels_motherstatus_branch = 0;
	if (tree->GetBranch("gennuels_motherstatus") != 0) {
		gennuels_motherstatus_branch = tree->GetBranch("gennuels_motherstatus");
		if (gennuels_motherstatus_branch) {gennuels_motherstatus_branch->SetAddress(&gennuels_motherstatus_);}
	}
	gennuels_gmothercharge_branch = 0;
	if (tree->GetBranch("gennuels_gmothercharge") != 0) {
		gennuels_gmothercharge_branch = tree->GetBranch("gennuels_gmothercharge");
		if (gennuels_gmothercharge_branch) {gennuels_gmothercharge_branch->SetAddress(&gennuels_gmothercharge_);}
	}
	gennuels_gmotherid_branch = 0;
	if (tree->GetBranch("gennuels_gmotherid") != 0) {
		gennuels_gmotherid_branch = tree->GetBranch("gennuels_gmotherid");
		if (gennuels_gmotherid_branch) {gennuels_gmotherid_branch->SetAddress(&gennuels_gmotherid_);}
	}
	gennuels_gmotheridx_branch = 0;
	if (tree->GetBranch("gennuels_gmotheridx") != 0) {
		gennuels_gmotheridx_branch = tree->GetBranch("gennuels_gmotheridx");
		if (gennuels_gmotheridx_branch) {gennuels_gmotheridx_branch->SetAddress(&gennuels_gmotheridx_);}
	}
	gennuels_gmotherstatus_branch = 0;
	if (tree->GetBranch("gennuels_gmotherstatus") != 0) {
		gennuels_gmotherstatus_branch = tree->GetBranch("gennuels_gmotherstatus");
		if (gennuels_gmotherstatus_branch) {gennuels_gmotherstatus_branch->SetAddress(&gennuels_gmotherstatus_);}
	}
	gennuels_simplemothercharge_branch = 0;
	if (tree->GetBranch("gennuels_simplemothercharge") != 0) {
		gennuels_simplemothercharge_branch = tree->GetBranch("gennuels_simplemothercharge");
		if (gennuels_simplemothercharge_branch) {gennuels_simplemothercharge_branch->SetAddress(&gennuels_simplemothercharge_);}
	}
	gennuels_simplemotherid_branch = 0;
	if (tree->GetBranch("gennuels_simplemotherid") != 0) {
		gennuels_simplemotherid_branch = tree->GetBranch("gennuels_simplemotherid");
		if (gennuels_simplemotherid_branch) {gennuels_simplemotherid_branch->SetAddress(&gennuels_simplemotherid_);}
	}
	gennuels_simplemotheridx_branch = 0;
	if (tree->GetBranch("gennuels_simplemotheridx") != 0) {
		gennuels_simplemotheridx_branch = tree->GetBranch("gennuels_simplemotheridx");
		if (gennuels_simplemotheridx_branch) {gennuels_simplemotheridx_branch->SetAddress(&gennuels_simplemotheridx_);}
	}
	gennuels_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gennuels_simplemotherstatus") != 0) {
		gennuels_simplemotherstatus_branch = tree->GetBranch("gennuels_simplemotherstatus");
		if (gennuels_simplemotherstatus_branch) {gennuels_simplemotherstatus_branch->SetAddress(&gennuels_simplemotherstatus_);}
	}
	gennuels_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gennuels_simplegmothercharge") != 0) {
		gennuels_simplegmothercharge_branch = tree->GetBranch("gennuels_simplegmothercharge");
		if (gennuels_simplegmothercharge_branch) {gennuels_simplegmothercharge_branch->SetAddress(&gennuels_simplegmothercharge_);}
	}
	gennuels_simplegmotherid_branch = 0;
	if (tree->GetBranch("gennuels_simplegmotherid") != 0) {
		gennuels_simplegmotherid_branch = tree->GetBranch("gennuels_simplegmotherid");
		if (gennuels_simplegmotherid_branch) {gennuels_simplegmotherid_branch->SetAddress(&gennuels_simplegmotherid_);}
	}
	gennuels_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gennuels_simplegmotheridx") != 0) {
		gennuels_simplegmotheridx_branch = tree->GetBranch("gennuels_simplegmotheridx");
		if (gennuels_simplegmotheridx_branch) {gennuels_simplegmotheridx_branch->SetAddress(&gennuels_simplegmotheridx_);}
	}
	gennuels_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gennuels_simplegmotherstatus") != 0) {
		gennuels_simplegmotherstatus_branch = tree->GetBranch("gennuels_simplegmotherstatus");
		if (gennuels_simplegmotherstatus_branch) {gennuels_simplegmotherstatus_branch->SetAddress(&gennuels_simplegmotherstatus_);}
	}
	gennumus_isfromt_branch = 0;
	if (tree->GetBranch("gennumus_isfromt") != 0) {
		gennumus_isfromt_branch = tree->GetBranch("gennumus_isfromt");
		if (gennumus_isfromt_branch) {gennumus_isfromt_branch->SetAddress(&gennumus_isfromt_);}
	}
	gennumus_charge_branch = 0;
	if (tree->GetBranch("gennumus_charge") != 0) {
		gennumus_charge_branch = tree->GetBranch("gennumus_charge");
		if (gennumus_charge_branch) {gennumus_charge_branch->SetAddress(&gennumus_charge_);}
	}
	gennumus_iso_branch = 0;
	if (tree->GetBranch("gennumus_iso") != 0) {
		gennumus_iso_branch = tree->GetBranch("gennumus_iso");
		if (gennumus_iso_branch) {gennumus_iso_branch->SetAddress(&gennumus_iso_);}
	}
	gennumus_mass_branch = 0;
	if (tree->GetBranch("gennumus_mass") != 0) {
		gennumus_mass_branch = tree->GetBranch("gennumus_mass");
		if (gennumus_mass_branch) {gennumus_mass_branch->SetAddress(&gennumus_mass_);}
	}
	gennumus_id_branch = 0;
	if (tree->GetBranch("gennumus_id") != 0) {
		gennumus_id_branch = tree->GetBranch("gennumus_id");
		if (gennumus_id_branch) {gennumus_id_branch->SetAddress(&gennumus_id_);}
	}
	gennumus__genpsidx_branch = 0;
	if (tree->GetBranch("gennumus__genpsidx") != 0) {
		gennumus__genpsidx_branch = tree->GetBranch("gennumus__genpsidx");
		if (gennumus__genpsidx_branch) {gennumus__genpsidx_branch->SetAddress(&gennumus__genpsidx_);}
	}
	gennumus_status_branch = 0;
	if (tree->GetBranch("gennumus_status") != 0) {
		gennumus_status_branch = tree->GetBranch("gennumus_status");
		if (gennumus_status_branch) {gennumus_status_branch->SetAddress(&gennumus_status_);}
	}
	gennumus_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gennumus_fromHardProcessBeforeFSR") != 0) {
		gennumus_fromHardProcessBeforeFSR_branch = tree->GetBranch("gennumus_fromHardProcessBeforeFSR");
		if (gennumus_fromHardProcessBeforeFSR_branch) {gennumus_fromHardProcessBeforeFSR_branch->SetAddress(&gennumus_fromHardProcessBeforeFSR_);}
	}
	gennumus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gennumus_fromHardProcessDecayed") != 0) {
		gennumus_fromHardProcessDecayed_branch = tree->GetBranch("gennumus_fromHardProcessDecayed");
		if (gennumus_fromHardProcessDecayed_branch) {gennumus_fromHardProcessDecayed_branch->SetAddress(&gennumus_fromHardProcessDecayed_);}
	}
	gennumus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gennumus_fromHardProcessFinalState") != 0) {
		gennumus_fromHardProcessFinalState_branch = tree->GetBranch("gennumus_fromHardProcessFinalState");
		if (gennumus_fromHardProcessFinalState_branch) {gennumus_fromHardProcessFinalState_branch->SetAddress(&gennumus_fromHardProcessFinalState_);}
	}
	gennumus_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennumus_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gennumus_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gennumus_isDirectHardProcessTauDecayProductFinalState");
		if (gennumus_isDirectHardProcessTauDecayProductFinalState_branch) {gennumus_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gennumus_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gennumus_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennumus_isDirectPromptTauDecayProductFinalState") != 0) {
		gennumus_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gennumus_isDirectPromptTauDecayProductFinalState");
		if (gennumus_isDirectPromptTauDecayProductFinalState_branch) {gennumus_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gennumus_isDirectPromptTauDecayProductFinalState_);}
	}
	gennumus_isHardProcess_branch = 0;
	if (tree->GetBranch("gennumus_isHardProcess") != 0) {
		gennumus_isHardProcess_branch = tree->GetBranch("gennumus_isHardProcess");
		if (gennumus_isHardProcess_branch) {gennumus_isHardProcess_branch->SetAddress(&gennumus_isHardProcess_);}
	}
	gennumus_isLastCopy_branch = 0;
	if (tree->GetBranch("gennumus_isLastCopy") != 0) {
		gennumus_isLastCopy_branch = tree->GetBranch("gennumus_isLastCopy");
		if (gennumus_isLastCopy_branch) {gennumus_isLastCopy_branch->SetAddress(&gennumus_isLastCopy_);}
	}
	gennumus_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gennumus_isLastCopyBeforeFSR") != 0) {
		gennumus_isLastCopyBeforeFSR_branch = tree->GetBranch("gennumus_isLastCopyBeforeFSR");
		if (gennumus_isLastCopyBeforeFSR_branch) {gennumus_isLastCopyBeforeFSR_branch->SetAddress(&gennumus_isLastCopyBeforeFSR_);}
	}
	gennumus_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gennumus_isMostlyLikePythia6Status3") != 0) {
		gennumus_isMostlyLikePythia6Status3_branch = tree->GetBranch("gennumus_isMostlyLikePythia6Status3");
		if (gennumus_isMostlyLikePythia6Status3_branch) {gennumus_isMostlyLikePythia6Status3_branch->SetAddress(&gennumus_isMostlyLikePythia6Status3_);}
	}
	gennumus_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gennumus_isPromptDecayed") != 0) {
		gennumus_isPromptDecayed_branch = tree->GetBranch("gennumus_isPromptDecayed");
		if (gennumus_isPromptDecayed_branch) {gennumus_isPromptDecayed_branch->SetAddress(&gennumus_isPromptDecayed_);}
	}
	gennumus_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gennumus_isPromptFinalState") != 0) {
		gennumus_isPromptFinalState_branch = tree->GetBranch("gennumus_isPromptFinalState");
		if (gennumus_isPromptFinalState_branch) {gennumus_isPromptFinalState_branch->SetAddress(&gennumus_isPromptFinalState_);}
	}
	gennumus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gennumus_lepdaughter_id") != 0) {
		gennumus_lepdaughter_id_branch = tree->GetBranch("gennumus_lepdaughter_id");
		if (gennumus_lepdaughter_id_branch) {gennumus_lepdaughter_id_branch->SetAddress(&gennumus_lepdaughter_id_);}
	}
	gennumus_gentaudecay_branch = 0;
	if (tree->GetBranch("gennumus_gentaudecay") != 0) {
		gennumus_gentaudecay_branch = tree->GetBranch("gennumus_gentaudecay");
		if (gennumus_gentaudecay_branch) {gennumus_gentaudecay_branch->SetAddress(&gennumus_gentaudecay_);}
	}
	gen_nfromtnumus__branch = 0;
	if (tree->GetBranch("gen_nfromtnumus_") != 0) {
		gen_nfromtnumus__branch = tree->GetBranch("gen_nfromtnumus_");
		if (gen_nfromtnumus__branch) {gen_nfromtnumus__branch->SetAddress(&gen_nfromtnumus__);}
	}
	gennumus_mothercharge_branch = 0;
	if (tree->GetBranch("gennumus_mothercharge") != 0) {
		gennumus_mothercharge_branch = tree->GetBranch("gennumus_mothercharge");
		if (gennumus_mothercharge_branch) {gennumus_mothercharge_branch->SetAddress(&gennumus_mothercharge_);}
	}
	gennumus_motherid_branch = 0;
	if (tree->GetBranch("gennumus_motherid") != 0) {
		gennumus_motherid_branch = tree->GetBranch("gennumus_motherid");
		if (gennumus_motherid_branch) {gennumus_motherid_branch->SetAddress(&gennumus_motherid_);}
	}
	gennumus_motheridx_branch = 0;
	if (tree->GetBranch("gennumus_motheridx") != 0) {
		gennumus_motheridx_branch = tree->GetBranch("gennumus_motheridx");
		if (gennumus_motheridx_branch) {gennumus_motheridx_branch->SetAddress(&gennumus_motheridx_);}
	}
	gennumus_motherstatus_branch = 0;
	if (tree->GetBranch("gennumus_motherstatus") != 0) {
		gennumus_motherstatus_branch = tree->GetBranch("gennumus_motherstatus");
		if (gennumus_motherstatus_branch) {gennumus_motherstatus_branch->SetAddress(&gennumus_motherstatus_);}
	}
	gennumus_gmothercharge_branch = 0;
	if (tree->GetBranch("gennumus_gmothercharge") != 0) {
		gennumus_gmothercharge_branch = tree->GetBranch("gennumus_gmothercharge");
		if (gennumus_gmothercharge_branch) {gennumus_gmothercharge_branch->SetAddress(&gennumus_gmothercharge_);}
	}
	gennumus_gmotherid_branch = 0;
	if (tree->GetBranch("gennumus_gmotherid") != 0) {
		gennumus_gmotherid_branch = tree->GetBranch("gennumus_gmotherid");
		if (gennumus_gmotherid_branch) {gennumus_gmotherid_branch->SetAddress(&gennumus_gmotherid_);}
	}
	gennumus_gmotheridx_branch = 0;
	if (tree->GetBranch("gennumus_gmotheridx") != 0) {
		gennumus_gmotheridx_branch = tree->GetBranch("gennumus_gmotheridx");
		if (gennumus_gmotheridx_branch) {gennumus_gmotheridx_branch->SetAddress(&gennumus_gmotheridx_);}
	}
	gennumus_gmotherstatus_branch = 0;
	if (tree->GetBranch("gennumus_gmotherstatus") != 0) {
		gennumus_gmotherstatus_branch = tree->GetBranch("gennumus_gmotherstatus");
		if (gennumus_gmotherstatus_branch) {gennumus_gmotherstatus_branch->SetAddress(&gennumus_gmotherstatus_);}
	}
	gennumus_simplemothercharge_branch = 0;
	if (tree->GetBranch("gennumus_simplemothercharge") != 0) {
		gennumus_simplemothercharge_branch = tree->GetBranch("gennumus_simplemothercharge");
		if (gennumus_simplemothercharge_branch) {gennumus_simplemothercharge_branch->SetAddress(&gennumus_simplemothercharge_);}
	}
	gennumus_simplemotherid_branch = 0;
	if (tree->GetBranch("gennumus_simplemotherid") != 0) {
		gennumus_simplemotherid_branch = tree->GetBranch("gennumus_simplemotherid");
		if (gennumus_simplemotherid_branch) {gennumus_simplemotherid_branch->SetAddress(&gennumus_simplemotherid_);}
	}
	gennumus_simplemotheridx_branch = 0;
	if (tree->GetBranch("gennumus_simplemotheridx") != 0) {
		gennumus_simplemotheridx_branch = tree->GetBranch("gennumus_simplemotheridx");
		if (gennumus_simplemotheridx_branch) {gennumus_simplemotheridx_branch->SetAddress(&gennumus_simplemotheridx_);}
	}
	gennumus_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gennumus_simplemotherstatus") != 0) {
		gennumus_simplemotherstatus_branch = tree->GetBranch("gennumus_simplemotherstatus");
		if (gennumus_simplemotherstatus_branch) {gennumus_simplemotherstatus_branch->SetAddress(&gennumus_simplemotherstatus_);}
	}
	gennumus_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gennumus_simplegmothercharge") != 0) {
		gennumus_simplegmothercharge_branch = tree->GetBranch("gennumus_simplegmothercharge");
		if (gennumus_simplegmothercharge_branch) {gennumus_simplegmothercharge_branch->SetAddress(&gennumus_simplegmothercharge_);}
	}
	gennumus_simplegmotherid_branch = 0;
	if (tree->GetBranch("gennumus_simplegmotherid") != 0) {
		gennumus_simplegmotherid_branch = tree->GetBranch("gennumus_simplegmotherid");
		if (gennumus_simplegmotherid_branch) {gennumus_simplegmotherid_branch->SetAddress(&gennumus_simplegmotherid_);}
	}
	gennumus_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gennumus_simplegmotheridx") != 0) {
		gennumus_simplegmotheridx_branch = tree->GetBranch("gennumus_simplegmotheridx");
		if (gennumus_simplegmotheridx_branch) {gennumus_simplegmotheridx_branch->SetAddress(&gennumus_simplegmotheridx_);}
	}
	gennumus_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gennumus_simplegmotherstatus") != 0) {
		gennumus_simplegmotherstatus_branch = tree->GetBranch("gennumus_simplegmotherstatus");
		if (gennumus_simplegmotherstatus_branch) {gennumus_simplegmotherstatus_branch->SetAddress(&gennumus_simplegmotherstatus_);}
	}
	gennutaus_isfromt_branch = 0;
	if (tree->GetBranch("gennutaus_isfromt") != 0) {
		gennutaus_isfromt_branch = tree->GetBranch("gennutaus_isfromt");
		if (gennutaus_isfromt_branch) {gennutaus_isfromt_branch->SetAddress(&gennutaus_isfromt_);}
	}
	gennutaus_charge_branch = 0;
	if (tree->GetBranch("gennutaus_charge") != 0) {
		gennutaus_charge_branch = tree->GetBranch("gennutaus_charge");
		if (gennutaus_charge_branch) {gennutaus_charge_branch->SetAddress(&gennutaus_charge_);}
	}
	gennutaus_iso_branch = 0;
	if (tree->GetBranch("gennutaus_iso") != 0) {
		gennutaus_iso_branch = tree->GetBranch("gennutaus_iso");
		if (gennutaus_iso_branch) {gennutaus_iso_branch->SetAddress(&gennutaus_iso_);}
	}
	gennutaus_mass_branch = 0;
	if (tree->GetBranch("gennutaus_mass") != 0) {
		gennutaus_mass_branch = tree->GetBranch("gennutaus_mass");
		if (gennutaus_mass_branch) {gennutaus_mass_branch->SetAddress(&gennutaus_mass_);}
	}
	gennutaus_id_branch = 0;
	if (tree->GetBranch("gennutaus_id") != 0) {
		gennutaus_id_branch = tree->GetBranch("gennutaus_id");
		if (gennutaus_id_branch) {gennutaus_id_branch->SetAddress(&gennutaus_id_);}
	}
	gennutaus__genpsidx_branch = 0;
	if (tree->GetBranch("gennutaus__genpsidx") != 0) {
		gennutaus__genpsidx_branch = tree->GetBranch("gennutaus__genpsidx");
		if (gennutaus__genpsidx_branch) {gennutaus__genpsidx_branch->SetAddress(&gennutaus__genpsidx_);}
	}
	gennutaus_status_branch = 0;
	if (tree->GetBranch("gennutaus_status") != 0) {
		gennutaus_status_branch = tree->GetBranch("gennutaus_status");
		if (gennutaus_status_branch) {gennutaus_status_branch->SetAddress(&gennutaus_status_);}
	}
	gennutaus_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gennutaus_fromHardProcessBeforeFSR") != 0) {
		gennutaus_fromHardProcessBeforeFSR_branch = tree->GetBranch("gennutaus_fromHardProcessBeforeFSR");
		if (gennutaus_fromHardProcessBeforeFSR_branch) {gennutaus_fromHardProcessBeforeFSR_branch->SetAddress(&gennutaus_fromHardProcessBeforeFSR_);}
	}
	gennutaus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gennutaus_fromHardProcessDecayed") != 0) {
		gennutaus_fromHardProcessDecayed_branch = tree->GetBranch("gennutaus_fromHardProcessDecayed");
		if (gennutaus_fromHardProcessDecayed_branch) {gennutaus_fromHardProcessDecayed_branch->SetAddress(&gennutaus_fromHardProcessDecayed_);}
	}
	gennutaus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gennutaus_fromHardProcessFinalState") != 0) {
		gennutaus_fromHardProcessFinalState_branch = tree->GetBranch("gennutaus_fromHardProcessFinalState");
		if (gennutaus_fromHardProcessFinalState_branch) {gennutaus_fromHardProcessFinalState_branch->SetAddress(&gennutaus_fromHardProcessFinalState_);}
	}
	gennutaus_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennutaus_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gennutaus_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gennutaus_isDirectHardProcessTauDecayProductFinalState");
		if (gennutaus_isDirectHardProcessTauDecayProductFinalState_branch) {gennutaus_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gennutaus_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gennutaus_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gennutaus_isDirectPromptTauDecayProductFinalState") != 0) {
		gennutaus_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gennutaus_isDirectPromptTauDecayProductFinalState");
		if (gennutaus_isDirectPromptTauDecayProductFinalState_branch) {gennutaus_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gennutaus_isDirectPromptTauDecayProductFinalState_);}
	}
	gennutaus_isHardProcess_branch = 0;
	if (tree->GetBranch("gennutaus_isHardProcess") != 0) {
		gennutaus_isHardProcess_branch = tree->GetBranch("gennutaus_isHardProcess");
		if (gennutaus_isHardProcess_branch) {gennutaus_isHardProcess_branch->SetAddress(&gennutaus_isHardProcess_);}
	}
	gennutaus_isLastCopy_branch = 0;
	if (tree->GetBranch("gennutaus_isLastCopy") != 0) {
		gennutaus_isLastCopy_branch = tree->GetBranch("gennutaus_isLastCopy");
		if (gennutaus_isLastCopy_branch) {gennutaus_isLastCopy_branch->SetAddress(&gennutaus_isLastCopy_);}
	}
	gennutaus_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gennutaus_isLastCopyBeforeFSR") != 0) {
		gennutaus_isLastCopyBeforeFSR_branch = tree->GetBranch("gennutaus_isLastCopyBeforeFSR");
		if (gennutaus_isLastCopyBeforeFSR_branch) {gennutaus_isLastCopyBeforeFSR_branch->SetAddress(&gennutaus_isLastCopyBeforeFSR_);}
	}
	gennutaus_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gennutaus_isMostlyLikePythia6Status3") != 0) {
		gennutaus_isMostlyLikePythia6Status3_branch = tree->GetBranch("gennutaus_isMostlyLikePythia6Status3");
		if (gennutaus_isMostlyLikePythia6Status3_branch) {gennutaus_isMostlyLikePythia6Status3_branch->SetAddress(&gennutaus_isMostlyLikePythia6Status3_);}
	}
	gennutaus_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gennutaus_isPromptDecayed") != 0) {
		gennutaus_isPromptDecayed_branch = tree->GetBranch("gennutaus_isPromptDecayed");
		if (gennutaus_isPromptDecayed_branch) {gennutaus_isPromptDecayed_branch->SetAddress(&gennutaus_isPromptDecayed_);}
	}
	gennutaus_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gennutaus_isPromptFinalState") != 0) {
		gennutaus_isPromptFinalState_branch = tree->GetBranch("gennutaus_isPromptFinalState");
		if (gennutaus_isPromptFinalState_branch) {gennutaus_isPromptFinalState_branch->SetAddress(&gennutaus_isPromptFinalState_);}
	}
	gennutaus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gennutaus_lepdaughter_id") != 0) {
		gennutaus_lepdaughter_id_branch = tree->GetBranch("gennutaus_lepdaughter_id");
		if (gennutaus_lepdaughter_id_branch) {gennutaus_lepdaughter_id_branch->SetAddress(&gennutaus_lepdaughter_id_);}
	}
	gennutaus_gentaudecay_branch = 0;
	if (tree->GetBranch("gennutaus_gentaudecay") != 0) {
		gennutaus_gentaudecay_branch = tree->GetBranch("gennutaus_gentaudecay");
		if (gennutaus_gentaudecay_branch) {gennutaus_gentaudecay_branch->SetAddress(&gennutaus_gentaudecay_);}
	}
	gen_nfromtnutaus__branch = 0;
	if (tree->GetBranch("gen_nfromtnutaus_") != 0) {
		gen_nfromtnutaus__branch = tree->GetBranch("gen_nfromtnutaus_");
		if (gen_nfromtnutaus__branch) {gen_nfromtnutaus__branch->SetAddress(&gen_nfromtnutaus__);}
	}
	gennutaus_mothercharge_branch = 0;
	if (tree->GetBranch("gennutaus_mothercharge") != 0) {
		gennutaus_mothercharge_branch = tree->GetBranch("gennutaus_mothercharge");
		if (gennutaus_mothercharge_branch) {gennutaus_mothercharge_branch->SetAddress(&gennutaus_mothercharge_);}
	}
	gennutaus_motherid_branch = 0;
	if (tree->GetBranch("gennutaus_motherid") != 0) {
		gennutaus_motherid_branch = tree->GetBranch("gennutaus_motherid");
		if (gennutaus_motherid_branch) {gennutaus_motherid_branch->SetAddress(&gennutaus_motherid_);}
	}
	gennutaus_motheridx_branch = 0;
	if (tree->GetBranch("gennutaus_motheridx") != 0) {
		gennutaus_motheridx_branch = tree->GetBranch("gennutaus_motheridx");
		if (gennutaus_motheridx_branch) {gennutaus_motheridx_branch->SetAddress(&gennutaus_motheridx_);}
	}
	gennutaus_motherstatus_branch = 0;
	if (tree->GetBranch("gennutaus_motherstatus") != 0) {
		gennutaus_motherstatus_branch = tree->GetBranch("gennutaus_motherstatus");
		if (gennutaus_motherstatus_branch) {gennutaus_motherstatus_branch->SetAddress(&gennutaus_motherstatus_);}
	}
	gennutaus_gmothercharge_branch = 0;
	if (tree->GetBranch("gennutaus_gmothercharge") != 0) {
		gennutaus_gmothercharge_branch = tree->GetBranch("gennutaus_gmothercharge");
		if (gennutaus_gmothercharge_branch) {gennutaus_gmothercharge_branch->SetAddress(&gennutaus_gmothercharge_);}
	}
	gennutaus_gmotherid_branch = 0;
	if (tree->GetBranch("gennutaus_gmotherid") != 0) {
		gennutaus_gmotherid_branch = tree->GetBranch("gennutaus_gmotherid");
		if (gennutaus_gmotherid_branch) {gennutaus_gmotherid_branch->SetAddress(&gennutaus_gmotherid_);}
	}
	gennutaus_gmotheridx_branch = 0;
	if (tree->GetBranch("gennutaus_gmotheridx") != 0) {
		gennutaus_gmotheridx_branch = tree->GetBranch("gennutaus_gmotheridx");
		if (gennutaus_gmotheridx_branch) {gennutaus_gmotheridx_branch->SetAddress(&gennutaus_gmotheridx_);}
	}
	gennutaus_gmotherstatus_branch = 0;
	if (tree->GetBranch("gennutaus_gmotherstatus") != 0) {
		gennutaus_gmotherstatus_branch = tree->GetBranch("gennutaus_gmotherstatus");
		if (gennutaus_gmotherstatus_branch) {gennutaus_gmotherstatus_branch->SetAddress(&gennutaus_gmotherstatus_);}
	}
	gennutaus_simplemothercharge_branch = 0;
	if (tree->GetBranch("gennutaus_simplemothercharge") != 0) {
		gennutaus_simplemothercharge_branch = tree->GetBranch("gennutaus_simplemothercharge");
		if (gennutaus_simplemothercharge_branch) {gennutaus_simplemothercharge_branch->SetAddress(&gennutaus_simplemothercharge_);}
	}
	gennutaus_simplemotherid_branch = 0;
	if (tree->GetBranch("gennutaus_simplemotherid") != 0) {
		gennutaus_simplemotherid_branch = tree->GetBranch("gennutaus_simplemotherid");
		if (gennutaus_simplemotherid_branch) {gennutaus_simplemotherid_branch->SetAddress(&gennutaus_simplemotherid_);}
	}
	gennutaus_simplemotheridx_branch = 0;
	if (tree->GetBranch("gennutaus_simplemotheridx") != 0) {
		gennutaus_simplemotheridx_branch = tree->GetBranch("gennutaus_simplemotheridx");
		if (gennutaus_simplemotheridx_branch) {gennutaus_simplemotheridx_branch->SetAddress(&gennutaus_simplemotheridx_);}
	}
	gennutaus_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gennutaus_simplemotherstatus") != 0) {
		gennutaus_simplemotherstatus_branch = tree->GetBranch("gennutaus_simplemotherstatus");
		if (gennutaus_simplemotherstatus_branch) {gennutaus_simplemotherstatus_branch->SetAddress(&gennutaus_simplemotherstatus_);}
	}
	gennutaus_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gennutaus_simplegmothercharge") != 0) {
		gennutaus_simplegmothercharge_branch = tree->GetBranch("gennutaus_simplegmothercharge");
		if (gennutaus_simplegmothercharge_branch) {gennutaus_simplegmothercharge_branch->SetAddress(&gennutaus_simplegmothercharge_);}
	}
	gennutaus_simplegmotherid_branch = 0;
	if (tree->GetBranch("gennutaus_simplegmotherid") != 0) {
		gennutaus_simplegmotherid_branch = tree->GetBranch("gennutaus_simplegmotherid");
		if (gennutaus_simplegmotherid_branch) {gennutaus_simplegmotherid_branch->SetAddress(&gennutaus_simplegmotherid_);}
	}
	gennutaus_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gennutaus_simplegmotheridx") != 0) {
		gennutaus_simplegmotheridx_branch = tree->GetBranch("gennutaus_simplegmotheridx");
		if (gennutaus_simplegmotheridx_branch) {gennutaus_simplegmotheridx_branch->SetAddress(&gennutaus_simplegmotheridx_);}
	}
	gennutaus_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gennutaus_simplegmotherstatus") != 0) {
		gennutaus_simplegmotherstatus_branch = tree->GetBranch("gennutaus_simplegmotherstatus");
		if (gennutaus_simplegmotherstatus_branch) {gennutaus_simplegmotherstatus_branch->SetAddress(&gennutaus_simplegmotherstatus_);}
	}
	gents_isfromt_branch = 0;
	if (tree->GetBranch("gents_isfromt") != 0) {
		gents_isfromt_branch = tree->GetBranch("gents_isfromt");
		if (gents_isfromt_branch) {gents_isfromt_branch->SetAddress(&gents_isfromt_);}
	}
	gents_charge_branch = 0;
	if (tree->GetBranch("gents_charge") != 0) {
		gents_charge_branch = tree->GetBranch("gents_charge");
		if (gents_charge_branch) {gents_charge_branch->SetAddress(&gents_charge_);}
	}
	gents_iso_branch = 0;
	if (tree->GetBranch("gents_iso") != 0) {
		gents_iso_branch = tree->GetBranch("gents_iso");
		if (gents_iso_branch) {gents_iso_branch->SetAddress(&gents_iso_);}
	}
	gents_mass_branch = 0;
	if (tree->GetBranch("gents_mass") != 0) {
		gents_mass_branch = tree->GetBranch("gents_mass");
		if (gents_mass_branch) {gents_mass_branch->SetAddress(&gents_mass_);}
	}
	gents_id_branch = 0;
	if (tree->GetBranch("gents_id") != 0) {
		gents_id_branch = tree->GetBranch("gents_id");
		if (gents_id_branch) {gents_id_branch->SetAddress(&gents_id_);}
	}
	gents__genpsidx_branch = 0;
	if (tree->GetBranch("gents__genpsidx") != 0) {
		gents__genpsidx_branch = tree->GetBranch("gents__genpsidx");
		if (gents__genpsidx_branch) {gents__genpsidx_branch->SetAddress(&gents__genpsidx_);}
	}
	gents_status_branch = 0;
	if (tree->GetBranch("gents_status") != 0) {
		gents_status_branch = tree->GetBranch("gents_status");
		if (gents_status_branch) {gents_status_branch->SetAddress(&gents_status_);}
	}
	gents_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gents_fromHardProcessBeforeFSR") != 0) {
		gents_fromHardProcessBeforeFSR_branch = tree->GetBranch("gents_fromHardProcessBeforeFSR");
		if (gents_fromHardProcessBeforeFSR_branch) {gents_fromHardProcessBeforeFSR_branch->SetAddress(&gents_fromHardProcessBeforeFSR_);}
	}
	gents_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gents_fromHardProcessDecayed") != 0) {
		gents_fromHardProcessDecayed_branch = tree->GetBranch("gents_fromHardProcessDecayed");
		if (gents_fromHardProcessDecayed_branch) {gents_fromHardProcessDecayed_branch->SetAddress(&gents_fromHardProcessDecayed_);}
	}
	gents_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gents_fromHardProcessFinalState") != 0) {
		gents_fromHardProcessFinalState_branch = tree->GetBranch("gents_fromHardProcessFinalState");
		if (gents_fromHardProcessFinalState_branch) {gents_fromHardProcessFinalState_branch->SetAddress(&gents_fromHardProcessFinalState_);}
	}
	gents_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gents_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gents_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gents_isDirectHardProcessTauDecayProductFinalState");
		if (gents_isDirectHardProcessTauDecayProductFinalState_branch) {gents_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gents_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gents_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gents_isDirectPromptTauDecayProductFinalState") != 0) {
		gents_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gents_isDirectPromptTauDecayProductFinalState");
		if (gents_isDirectPromptTauDecayProductFinalState_branch) {gents_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gents_isDirectPromptTauDecayProductFinalState_);}
	}
	gents_isHardProcess_branch = 0;
	if (tree->GetBranch("gents_isHardProcess") != 0) {
		gents_isHardProcess_branch = tree->GetBranch("gents_isHardProcess");
		if (gents_isHardProcess_branch) {gents_isHardProcess_branch->SetAddress(&gents_isHardProcess_);}
	}
	gents_isLastCopy_branch = 0;
	if (tree->GetBranch("gents_isLastCopy") != 0) {
		gents_isLastCopy_branch = tree->GetBranch("gents_isLastCopy");
		if (gents_isLastCopy_branch) {gents_isLastCopy_branch->SetAddress(&gents_isLastCopy_);}
	}
	gents_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gents_isLastCopyBeforeFSR") != 0) {
		gents_isLastCopyBeforeFSR_branch = tree->GetBranch("gents_isLastCopyBeforeFSR");
		if (gents_isLastCopyBeforeFSR_branch) {gents_isLastCopyBeforeFSR_branch->SetAddress(&gents_isLastCopyBeforeFSR_);}
	}
	gents_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gents_isMostlyLikePythia6Status3") != 0) {
		gents_isMostlyLikePythia6Status3_branch = tree->GetBranch("gents_isMostlyLikePythia6Status3");
		if (gents_isMostlyLikePythia6Status3_branch) {gents_isMostlyLikePythia6Status3_branch->SetAddress(&gents_isMostlyLikePythia6Status3_);}
	}
	gents_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gents_isPromptDecayed") != 0) {
		gents_isPromptDecayed_branch = tree->GetBranch("gents_isPromptDecayed");
		if (gents_isPromptDecayed_branch) {gents_isPromptDecayed_branch->SetAddress(&gents_isPromptDecayed_);}
	}
	gents_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gents_isPromptFinalState") != 0) {
		gents_isPromptFinalState_branch = tree->GetBranch("gents_isPromptFinalState");
		if (gents_isPromptFinalState_branch) {gents_isPromptFinalState_branch->SetAddress(&gents_isPromptFinalState_);}
	}
	gents_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gents_lepdaughter_id") != 0) {
		gents_lepdaughter_id_branch = tree->GetBranch("gents_lepdaughter_id");
		if (gents_lepdaughter_id_branch) {gents_lepdaughter_id_branch->SetAddress(&gents_lepdaughter_id_);}
	}
	gents_gentaudecay_branch = 0;
	if (tree->GetBranch("gents_gentaudecay") != 0) {
		gents_gentaudecay_branch = tree->GetBranch("gents_gentaudecay");
		if (gents_gentaudecay_branch) {gents_gentaudecay_branch->SetAddress(&gents_gentaudecay_);}
	}
	gen_nfromtts__branch = 0;
	if (tree->GetBranch("gen_nfromtts_") != 0) {
		gen_nfromtts__branch = tree->GetBranch("gen_nfromtts_");
		if (gen_nfromtts__branch) {gen_nfromtts__branch->SetAddress(&gen_nfromtts__);}
	}
	gents_mothercharge_branch = 0;
	if (tree->GetBranch("gents_mothercharge") != 0) {
		gents_mothercharge_branch = tree->GetBranch("gents_mothercharge");
		if (gents_mothercharge_branch) {gents_mothercharge_branch->SetAddress(&gents_mothercharge_);}
	}
	gents_motherid_branch = 0;
	if (tree->GetBranch("gents_motherid") != 0) {
		gents_motherid_branch = tree->GetBranch("gents_motherid");
		if (gents_motherid_branch) {gents_motherid_branch->SetAddress(&gents_motherid_);}
	}
	gents_motheridx_branch = 0;
	if (tree->GetBranch("gents_motheridx") != 0) {
		gents_motheridx_branch = tree->GetBranch("gents_motheridx");
		if (gents_motheridx_branch) {gents_motheridx_branch->SetAddress(&gents_motheridx_);}
	}
	gents_motherstatus_branch = 0;
	if (tree->GetBranch("gents_motherstatus") != 0) {
		gents_motherstatus_branch = tree->GetBranch("gents_motherstatus");
		if (gents_motherstatus_branch) {gents_motherstatus_branch->SetAddress(&gents_motherstatus_);}
	}
	gents_gmothercharge_branch = 0;
	if (tree->GetBranch("gents_gmothercharge") != 0) {
		gents_gmothercharge_branch = tree->GetBranch("gents_gmothercharge");
		if (gents_gmothercharge_branch) {gents_gmothercharge_branch->SetAddress(&gents_gmothercharge_);}
	}
	gents_gmotherid_branch = 0;
	if (tree->GetBranch("gents_gmotherid") != 0) {
		gents_gmotherid_branch = tree->GetBranch("gents_gmotherid");
		if (gents_gmotherid_branch) {gents_gmotherid_branch->SetAddress(&gents_gmotherid_);}
	}
	gents_gmotheridx_branch = 0;
	if (tree->GetBranch("gents_gmotheridx") != 0) {
		gents_gmotheridx_branch = tree->GetBranch("gents_gmotheridx");
		if (gents_gmotheridx_branch) {gents_gmotheridx_branch->SetAddress(&gents_gmotheridx_);}
	}
	gents_gmotherstatus_branch = 0;
	if (tree->GetBranch("gents_gmotherstatus") != 0) {
		gents_gmotherstatus_branch = tree->GetBranch("gents_gmotherstatus");
		if (gents_gmotherstatus_branch) {gents_gmotherstatus_branch->SetAddress(&gents_gmotherstatus_);}
	}
	gents_simplemothercharge_branch = 0;
	if (tree->GetBranch("gents_simplemothercharge") != 0) {
		gents_simplemothercharge_branch = tree->GetBranch("gents_simplemothercharge");
		if (gents_simplemothercharge_branch) {gents_simplemothercharge_branch->SetAddress(&gents_simplemothercharge_);}
	}
	gents_simplemotherid_branch = 0;
	if (tree->GetBranch("gents_simplemotherid") != 0) {
		gents_simplemotherid_branch = tree->GetBranch("gents_simplemotherid");
		if (gents_simplemotherid_branch) {gents_simplemotherid_branch->SetAddress(&gents_simplemotherid_);}
	}
	gents_simplemotheridx_branch = 0;
	if (tree->GetBranch("gents_simplemotheridx") != 0) {
		gents_simplemotheridx_branch = tree->GetBranch("gents_simplemotheridx");
		if (gents_simplemotheridx_branch) {gents_simplemotheridx_branch->SetAddress(&gents_simplemotheridx_);}
	}
	gents_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gents_simplemotherstatus") != 0) {
		gents_simplemotherstatus_branch = tree->GetBranch("gents_simplemotherstatus");
		if (gents_simplemotherstatus_branch) {gents_simplemotherstatus_branch->SetAddress(&gents_simplemotherstatus_);}
	}
	gents_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gents_simplegmothercharge") != 0) {
		gents_simplegmothercharge_branch = tree->GetBranch("gents_simplegmothercharge");
		if (gents_simplegmothercharge_branch) {gents_simplegmothercharge_branch->SetAddress(&gents_simplegmothercharge_);}
	}
	gents_simplegmotherid_branch = 0;
	if (tree->GetBranch("gents_simplegmotherid") != 0) {
		gents_simplegmotherid_branch = tree->GetBranch("gents_simplegmotherid");
		if (gents_simplegmotherid_branch) {gents_simplegmotherid_branch->SetAddress(&gents_simplegmotherid_);}
	}
	gents_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gents_simplegmotheridx") != 0) {
		gents_simplegmotheridx_branch = tree->GetBranch("gents_simplegmotheridx");
		if (gents_simplegmotheridx_branch) {gents_simplegmotheridx_branch->SetAddress(&gents_simplegmotheridx_);}
	}
	gents_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gents_simplegmotherstatus") != 0) {
		gents_simplegmotherstatus_branch = tree->GetBranch("gents_simplegmotherstatus");
		if (gents_simplegmotherstatus_branch) {gents_simplegmotherstatus_branch->SetAddress(&gents_simplegmotherstatus_);}
	}
	genbs_isfromt_branch = 0;
	if (tree->GetBranch("genbs_isfromt") != 0) {
		genbs_isfromt_branch = tree->GetBranch("genbs_isfromt");
		if (genbs_isfromt_branch) {genbs_isfromt_branch->SetAddress(&genbs_isfromt_);}
	}
	genbs_charge_branch = 0;
	if (tree->GetBranch("genbs_charge") != 0) {
		genbs_charge_branch = tree->GetBranch("genbs_charge");
		if (genbs_charge_branch) {genbs_charge_branch->SetAddress(&genbs_charge_);}
	}
	genbs_iso_branch = 0;
	if (tree->GetBranch("genbs_iso") != 0) {
		genbs_iso_branch = tree->GetBranch("genbs_iso");
		if (genbs_iso_branch) {genbs_iso_branch->SetAddress(&genbs_iso_);}
	}
	genbs_mass_branch = 0;
	if (tree->GetBranch("genbs_mass") != 0) {
		genbs_mass_branch = tree->GetBranch("genbs_mass");
		if (genbs_mass_branch) {genbs_mass_branch->SetAddress(&genbs_mass_);}
	}
	genbs_id_branch = 0;
	if (tree->GetBranch("genbs_id") != 0) {
		genbs_id_branch = tree->GetBranch("genbs_id");
		if (genbs_id_branch) {genbs_id_branch->SetAddress(&genbs_id_);}
	}
	genbs__genpsidx_branch = 0;
	if (tree->GetBranch("genbs__genpsidx") != 0) {
		genbs__genpsidx_branch = tree->GetBranch("genbs__genpsidx");
		if (genbs__genpsidx_branch) {genbs__genpsidx_branch->SetAddress(&genbs__genpsidx_);}
	}
	genbs_status_branch = 0;
	if (tree->GetBranch("genbs_status") != 0) {
		genbs_status_branch = tree->GetBranch("genbs_status");
		if (genbs_status_branch) {genbs_status_branch->SetAddress(&genbs_status_);}
	}
	genbs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genbs_fromHardProcessBeforeFSR") != 0) {
		genbs_fromHardProcessBeforeFSR_branch = tree->GetBranch("genbs_fromHardProcessBeforeFSR");
		if (genbs_fromHardProcessBeforeFSR_branch) {genbs_fromHardProcessBeforeFSR_branch->SetAddress(&genbs_fromHardProcessBeforeFSR_);}
	}
	genbs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genbs_fromHardProcessDecayed") != 0) {
		genbs_fromHardProcessDecayed_branch = tree->GetBranch("genbs_fromHardProcessDecayed");
		if (genbs_fromHardProcessDecayed_branch) {genbs_fromHardProcessDecayed_branch->SetAddress(&genbs_fromHardProcessDecayed_);}
	}
	genbs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genbs_fromHardProcessFinalState") != 0) {
		genbs_fromHardProcessFinalState_branch = tree->GetBranch("genbs_fromHardProcessFinalState");
		if (genbs_fromHardProcessFinalState_branch) {genbs_fromHardProcessFinalState_branch->SetAddress(&genbs_fromHardProcessFinalState_);}
	}
	genbs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genbs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genbs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genbs_isDirectHardProcessTauDecayProductFinalState");
		if (genbs_isDirectHardProcessTauDecayProductFinalState_branch) {genbs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genbs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genbs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genbs_isDirectPromptTauDecayProductFinalState") != 0) {
		genbs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genbs_isDirectPromptTauDecayProductFinalState");
		if (genbs_isDirectPromptTauDecayProductFinalState_branch) {genbs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genbs_isDirectPromptTauDecayProductFinalState_);}
	}
	genbs_isHardProcess_branch = 0;
	if (tree->GetBranch("genbs_isHardProcess") != 0) {
		genbs_isHardProcess_branch = tree->GetBranch("genbs_isHardProcess");
		if (genbs_isHardProcess_branch) {genbs_isHardProcess_branch->SetAddress(&genbs_isHardProcess_);}
	}
	genbs_isLastCopy_branch = 0;
	if (tree->GetBranch("genbs_isLastCopy") != 0) {
		genbs_isLastCopy_branch = tree->GetBranch("genbs_isLastCopy");
		if (genbs_isLastCopy_branch) {genbs_isLastCopy_branch->SetAddress(&genbs_isLastCopy_);}
	}
	genbs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genbs_isLastCopyBeforeFSR") != 0) {
		genbs_isLastCopyBeforeFSR_branch = tree->GetBranch("genbs_isLastCopyBeforeFSR");
		if (genbs_isLastCopyBeforeFSR_branch) {genbs_isLastCopyBeforeFSR_branch->SetAddress(&genbs_isLastCopyBeforeFSR_);}
	}
	genbs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genbs_isMostlyLikePythia6Status3") != 0) {
		genbs_isMostlyLikePythia6Status3_branch = tree->GetBranch("genbs_isMostlyLikePythia6Status3");
		if (genbs_isMostlyLikePythia6Status3_branch) {genbs_isMostlyLikePythia6Status3_branch->SetAddress(&genbs_isMostlyLikePythia6Status3_);}
	}
	genbs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genbs_isPromptDecayed") != 0) {
		genbs_isPromptDecayed_branch = tree->GetBranch("genbs_isPromptDecayed");
		if (genbs_isPromptDecayed_branch) {genbs_isPromptDecayed_branch->SetAddress(&genbs_isPromptDecayed_);}
	}
	genbs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genbs_isPromptFinalState") != 0) {
		genbs_isPromptFinalState_branch = tree->GetBranch("genbs_isPromptFinalState");
		if (genbs_isPromptFinalState_branch) {genbs_isPromptFinalState_branch->SetAddress(&genbs_isPromptFinalState_);}
	}
	genbs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genbs_lepdaughter_id") != 0) {
		genbs_lepdaughter_id_branch = tree->GetBranch("genbs_lepdaughter_id");
		if (genbs_lepdaughter_id_branch) {genbs_lepdaughter_id_branch->SetAddress(&genbs_lepdaughter_id_);}
	}
	genbs_gentaudecay_branch = 0;
	if (tree->GetBranch("genbs_gentaudecay") != 0) {
		genbs_gentaudecay_branch = tree->GetBranch("genbs_gentaudecay");
		if (genbs_gentaudecay_branch) {genbs_gentaudecay_branch->SetAddress(&genbs_gentaudecay_);}
	}
	gen_nfromtbs__branch = 0;
	if (tree->GetBranch("gen_nfromtbs_") != 0) {
		gen_nfromtbs__branch = tree->GetBranch("gen_nfromtbs_");
		if (gen_nfromtbs__branch) {gen_nfromtbs__branch->SetAddress(&gen_nfromtbs__);}
	}
	genbs_mothercharge_branch = 0;
	if (tree->GetBranch("genbs_mothercharge") != 0) {
		genbs_mothercharge_branch = tree->GetBranch("genbs_mothercharge");
		if (genbs_mothercharge_branch) {genbs_mothercharge_branch->SetAddress(&genbs_mothercharge_);}
	}
	genbs_motherid_branch = 0;
	if (tree->GetBranch("genbs_motherid") != 0) {
		genbs_motherid_branch = tree->GetBranch("genbs_motherid");
		if (genbs_motherid_branch) {genbs_motherid_branch->SetAddress(&genbs_motherid_);}
	}
	genbs_motheridx_branch = 0;
	if (tree->GetBranch("genbs_motheridx") != 0) {
		genbs_motheridx_branch = tree->GetBranch("genbs_motheridx");
		if (genbs_motheridx_branch) {genbs_motheridx_branch->SetAddress(&genbs_motheridx_);}
	}
	genbs_motherstatus_branch = 0;
	if (tree->GetBranch("genbs_motherstatus") != 0) {
		genbs_motherstatus_branch = tree->GetBranch("genbs_motherstatus");
		if (genbs_motherstatus_branch) {genbs_motherstatus_branch->SetAddress(&genbs_motherstatus_);}
	}
	genbs_gmothercharge_branch = 0;
	if (tree->GetBranch("genbs_gmothercharge") != 0) {
		genbs_gmothercharge_branch = tree->GetBranch("genbs_gmothercharge");
		if (genbs_gmothercharge_branch) {genbs_gmothercharge_branch->SetAddress(&genbs_gmothercharge_);}
	}
	genbs_gmotherid_branch = 0;
	if (tree->GetBranch("genbs_gmotherid") != 0) {
		genbs_gmotherid_branch = tree->GetBranch("genbs_gmotherid");
		if (genbs_gmotherid_branch) {genbs_gmotherid_branch->SetAddress(&genbs_gmotherid_);}
	}
	genbs_gmotheridx_branch = 0;
	if (tree->GetBranch("genbs_gmotheridx") != 0) {
		genbs_gmotheridx_branch = tree->GetBranch("genbs_gmotheridx");
		if (genbs_gmotheridx_branch) {genbs_gmotheridx_branch->SetAddress(&genbs_gmotheridx_);}
	}
	genbs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genbs_gmotherstatus") != 0) {
		genbs_gmotherstatus_branch = tree->GetBranch("genbs_gmotherstatus");
		if (genbs_gmotherstatus_branch) {genbs_gmotherstatus_branch->SetAddress(&genbs_gmotherstatus_);}
	}
	genbs_simplemothercharge_branch = 0;
	if (tree->GetBranch("genbs_simplemothercharge") != 0) {
		genbs_simplemothercharge_branch = tree->GetBranch("genbs_simplemothercharge");
		if (genbs_simplemothercharge_branch) {genbs_simplemothercharge_branch->SetAddress(&genbs_simplemothercharge_);}
	}
	genbs_simplemotherid_branch = 0;
	if (tree->GetBranch("genbs_simplemotherid") != 0) {
		genbs_simplemotherid_branch = tree->GetBranch("genbs_simplemotherid");
		if (genbs_simplemotherid_branch) {genbs_simplemotherid_branch->SetAddress(&genbs_simplemotherid_);}
	}
	genbs_simplemotheridx_branch = 0;
	if (tree->GetBranch("genbs_simplemotheridx") != 0) {
		genbs_simplemotheridx_branch = tree->GetBranch("genbs_simplemotheridx");
		if (genbs_simplemotheridx_branch) {genbs_simplemotheridx_branch->SetAddress(&genbs_simplemotheridx_);}
	}
	genbs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genbs_simplemotherstatus") != 0) {
		genbs_simplemotherstatus_branch = tree->GetBranch("genbs_simplemotherstatus");
		if (genbs_simplemotherstatus_branch) {genbs_simplemotherstatus_branch->SetAddress(&genbs_simplemotherstatus_);}
	}
	genbs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genbs_simplegmothercharge") != 0) {
		genbs_simplegmothercharge_branch = tree->GetBranch("genbs_simplegmothercharge");
		if (genbs_simplegmothercharge_branch) {genbs_simplegmothercharge_branch->SetAddress(&genbs_simplegmothercharge_);}
	}
	genbs_simplegmotherid_branch = 0;
	if (tree->GetBranch("genbs_simplegmotherid") != 0) {
		genbs_simplegmotherid_branch = tree->GetBranch("genbs_simplegmotherid");
		if (genbs_simplegmotherid_branch) {genbs_simplegmotherid_branch->SetAddress(&genbs_simplegmotherid_);}
	}
	genbs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genbs_simplegmotheridx") != 0) {
		genbs_simplegmotheridx_branch = tree->GetBranch("genbs_simplegmotheridx");
		if (genbs_simplegmotheridx_branch) {genbs_simplegmotheridx_branch->SetAddress(&genbs_simplegmotheridx_);}
	}
	genbs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genbs_simplegmotherstatus") != 0) {
		genbs_simplegmotherstatus_branch = tree->GetBranch("genbs_simplegmotherstatus");
		if (genbs_simplegmotherstatus_branch) {genbs_simplegmotherstatus_branch->SetAddress(&genbs_simplegmotherstatus_);}
	}
	gencs_isfromt_branch = 0;
	if (tree->GetBranch("gencs_isfromt") != 0) {
		gencs_isfromt_branch = tree->GetBranch("gencs_isfromt");
		if (gencs_isfromt_branch) {gencs_isfromt_branch->SetAddress(&gencs_isfromt_);}
	}
	gencs_charge_branch = 0;
	if (tree->GetBranch("gencs_charge") != 0) {
		gencs_charge_branch = tree->GetBranch("gencs_charge");
		if (gencs_charge_branch) {gencs_charge_branch->SetAddress(&gencs_charge_);}
	}
	gencs_iso_branch = 0;
	if (tree->GetBranch("gencs_iso") != 0) {
		gencs_iso_branch = tree->GetBranch("gencs_iso");
		if (gencs_iso_branch) {gencs_iso_branch->SetAddress(&gencs_iso_);}
	}
	gencs_mass_branch = 0;
	if (tree->GetBranch("gencs_mass") != 0) {
		gencs_mass_branch = tree->GetBranch("gencs_mass");
		if (gencs_mass_branch) {gencs_mass_branch->SetAddress(&gencs_mass_);}
	}
	gencs_id_branch = 0;
	if (tree->GetBranch("gencs_id") != 0) {
		gencs_id_branch = tree->GetBranch("gencs_id");
		if (gencs_id_branch) {gencs_id_branch->SetAddress(&gencs_id_);}
	}
	gencs__genpsidx_branch = 0;
	if (tree->GetBranch("gencs__genpsidx") != 0) {
		gencs__genpsidx_branch = tree->GetBranch("gencs__genpsidx");
		if (gencs__genpsidx_branch) {gencs__genpsidx_branch->SetAddress(&gencs__genpsidx_);}
	}
	gencs_status_branch = 0;
	if (tree->GetBranch("gencs_status") != 0) {
		gencs_status_branch = tree->GetBranch("gencs_status");
		if (gencs_status_branch) {gencs_status_branch->SetAddress(&gencs_status_);}
	}
	gencs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("gencs_fromHardProcessBeforeFSR") != 0) {
		gencs_fromHardProcessBeforeFSR_branch = tree->GetBranch("gencs_fromHardProcessBeforeFSR");
		if (gencs_fromHardProcessBeforeFSR_branch) {gencs_fromHardProcessBeforeFSR_branch->SetAddress(&gencs_fromHardProcessBeforeFSR_);}
	}
	gencs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gencs_fromHardProcessDecayed") != 0) {
		gencs_fromHardProcessDecayed_branch = tree->GetBranch("gencs_fromHardProcessDecayed");
		if (gencs_fromHardProcessDecayed_branch) {gencs_fromHardProcessDecayed_branch->SetAddress(&gencs_fromHardProcessDecayed_);}
	}
	gencs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gencs_fromHardProcessFinalState") != 0) {
		gencs_fromHardProcessFinalState_branch = tree->GetBranch("gencs_fromHardProcessFinalState");
		if (gencs_fromHardProcessFinalState_branch) {gencs_fromHardProcessFinalState_branch->SetAddress(&gencs_fromHardProcessFinalState_);}
	}
	gencs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gencs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		gencs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("gencs_isDirectHardProcessTauDecayProductFinalState");
		if (gencs_isDirectHardProcessTauDecayProductFinalState_branch) {gencs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&gencs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	gencs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("gencs_isDirectPromptTauDecayProductFinalState") != 0) {
		gencs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("gencs_isDirectPromptTauDecayProductFinalState");
		if (gencs_isDirectPromptTauDecayProductFinalState_branch) {gencs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&gencs_isDirectPromptTauDecayProductFinalState_);}
	}
	gencs_isHardProcess_branch = 0;
	if (tree->GetBranch("gencs_isHardProcess") != 0) {
		gencs_isHardProcess_branch = tree->GetBranch("gencs_isHardProcess");
		if (gencs_isHardProcess_branch) {gencs_isHardProcess_branch->SetAddress(&gencs_isHardProcess_);}
	}
	gencs_isLastCopy_branch = 0;
	if (tree->GetBranch("gencs_isLastCopy") != 0) {
		gencs_isLastCopy_branch = tree->GetBranch("gencs_isLastCopy");
		if (gencs_isLastCopy_branch) {gencs_isLastCopy_branch->SetAddress(&gencs_isLastCopy_);}
	}
	gencs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("gencs_isLastCopyBeforeFSR") != 0) {
		gencs_isLastCopyBeforeFSR_branch = tree->GetBranch("gencs_isLastCopyBeforeFSR");
		if (gencs_isLastCopyBeforeFSR_branch) {gencs_isLastCopyBeforeFSR_branch->SetAddress(&gencs_isLastCopyBeforeFSR_);}
	}
	gencs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("gencs_isMostlyLikePythia6Status3") != 0) {
		gencs_isMostlyLikePythia6Status3_branch = tree->GetBranch("gencs_isMostlyLikePythia6Status3");
		if (gencs_isMostlyLikePythia6Status3_branch) {gencs_isMostlyLikePythia6Status3_branch->SetAddress(&gencs_isMostlyLikePythia6Status3_);}
	}
	gencs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("gencs_isPromptDecayed") != 0) {
		gencs_isPromptDecayed_branch = tree->GetBranch("gencs_isPromptDecayed");
		if (gencs_isPromptDecayed_branch) {gencs_isPromptDecayed_branch->SetAddress(&gencs_isPromptDecayed_);}
	}
	gencs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("gencs_isPromptFinalState") != 0) {
		gencs_isPromptFinalState_branch = tree->GetBranch("gencs_isPromptFinalState");
		if (gencs_isPromptFinalState_branch) {gencs_isPromptFinalState_branch->SetAddress(&gencs_isPromptFinalState_);}
	}
	gencs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gencs_lepdaughter_id") != 0) {
		gencs_lepdaughter_id_branch = tree->GetBranch("gencs_lepdaughter_id");
		if (gencs_lepdaughter_id_branch) {gencs_lepdaughter_id_branch->SetAddress(&gencs_lepdaughter_id_);}
	}
	gencs_gentaudecay_branch = 0;
	if (tree->GetBranch("gencs_gentaudecay") != 0) {
		gencs_gentaudecay_branch = tree->GetBranch("gencs_gentaudecay");
		if (gencs_gentaudecay_branch) {gencs_gentaudecay_branch->SetAddress(&gencs_gentaudecay_);}
	}
	gen_nfromtcs__branch = 0;
	if (tree->GetBranch("gen_nfromtcs_") != 0) {
		gen_nfromtcs__branch = tree->GetBranch("gen_nfromtcs_");
		if (gen_nfromtcs__branch) {gen_nfromtcs__branch->SetAddress(&gen_nfromtcs__);}
	}
	gencs_mothercharge_branch = 0;
	if (tree->GetBranch("gencs_mothercharge") != 0) {
		gencs_mothercharge_branch = tree->GetBranch("gencs_mothercharge");
		if (gencs_mothercharge_branch) {gencs_mothercharge_branch->SetAddress(&gencs_mothercharge_);}
	}
	gencs_motherid_branch = 0;
	if (tree->GetBranch("gencs_motherid") != 0) {
		gencs_motherid_branch = tree->GetBranch("gencs_motherid");
		if (gencs_motherid_branch) {gencs_motherid_branch->SetAddress(&gencs_motherid_);}
	}
	gencs_motheridx_branch = 0;
	if (tree->GetBranch("gencs_motheridx") != 0) {
		gencs_motheridx_branch = tree->GetBranch("gencs_motheridx");
		if (gencs_motheridx_branch) {gencs_motheridx_branch->SetAddress(&gencs_motheridx_);}
	}
	gencs_motherstatus_branch = 0;
	if (tree->GetBranch("gencs_motherstatus") != 0) {
		gencs_motherstatus_branch = tree->GetBranch("gencs_motherstatus");
		if (gencs_motherstatus_branch) {gencs_motherstatus_branch->SetAddress(&gencs_motherstatus_);}
	}
	gencs_gmothercharge_branch = 0;
	if (tree->GetBranch("gencs_gmothercharge") != 0) {
		gencs_gmothercharge_branch = tree->GetBranch("gencs_gmothercharge");
		if (gencs_gmothercharge_branch) {gencs_gmothercharge_branch->SetAddress(&gencs_gmothercharge_);}
	}
	gencs_gmotherid_branch = 0;
	if (tree->GetBranch("gencs_gmotherid") != 0) {
		gencs_gmotherid_branch = tree->GetBranch("gencs_gmotherid");
		if (gencs_gmotherid_branch) {gencs_gmotherid_branch->SetAddress(&gencs_gmotherid_);}
	}
	gencs_gmotheridx_branch = 0;
	if (tree->GetBranch("gencs_gmotheridx") != 0) {
		gencs_gmotheridx_branch = tree->GetBranch("gencs_gmotheridx");
		if (gencs_gmotheridx_branch) {gencs_gmotheridx_branch->SetAddress(&gencs_gmotheridx_);}
	}
	gencs_gmotherstatus_branch = 0;
	if (tree->GetBranch("gencs_gmotherstatus") != 0) {
		gencs_gmotherstatus_branch = tree->GetBranch("gencs_gmotherstatus");
		if (gencs_gmotherstatus_branch) {gencs_gmotherstatus_branch->SetAddress(&gencs_gmotherstatus_);}
	}
	gencs_simplemothercharge_branch = 0;
	if (tree->GetBranch("gencs_simplemothercharge") != 0) {
		gencs_simplemothercharge_branch = tree->GetBranch("gencs_simplemothercharge");
		if (gencs_simplemothercharge_branch) {gencs_simplemothercharge_branch->SetAddress(&gencs_simplemothercharge_);}
	}
	gencs_simplemotherid_branch = 0;
	if (tree->GetBranch("gencs_simplemotherid") != 0) {
		gencs_simplemotherid_branch = tree->GetBranch("gencs_simplemotherid");
		if (gencs_simplemotherid_branch) {gencs_simplemotherid_branch->SetAddress(&gencs_simplemotherid_);}
	}
	gencs_simplemotheridx_branch = 0;
	if (tree->GetBranch("gencs_simplemotheridx") != 0) {
		gencs_simplemotheridx_branch = tree->GetBranch("gencs_simplemotheridx");
		if (gencs_simplemotheridx_branch) {gencs_simplemotheridx_branch->SetAddress(&gencs_simplemotheridx_);}
	}
	gencs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("gencs_simplemotherstatus") != 0) {
		gencs_simplemotherstatus_branch = tree->GetBranch("gencs_simplemotherstatus");
		if (gencs_simplemotherstatus_branch) {gencs_simplemotherstatus_branch->SetAddress(&gencs_simplemotherstatus_);}
	}
	gencs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("gencs_simplegmothercharge") != 0) {
		gencs_simplegmothercharge_branch = tree->GetBranch("gencs_simplegmothercharge");
		if (gencs_simplegmothercharge_branch) {gencs_simplegmothercharge_branch->SetAddress(&gencs_simplegmothercharge_);}
	}
	gencs_simplegmotherid_branch = 0;
	if (tree->GetBranch("gencs_simplegmotherid") != 0) {
		gencs_simplegmotherid_branch = tree->GetBranch("gencs_simplegmotherid");
		if (gencs_simplegmotherid_branch) {gencs_simplegmotherid_branch->SetAddress(&gencs_simplegmotherid_);}
	}
	gencs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("gencs_simplegmotheridx") != 0) {
		gencs_simplegmotheridx_branch = tree->GetBranch("gencs_simplegmotheridx");
		if (gencs_simplegmotheridx_branch) {gencs_simplegmotheridx_branch->SetAddress(&gencs_simplegmotheridx_);}
	}
	gencs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("gencs_simplegmotherstatus") != 0) {
		gencs_simplegmotherstatus_branch = tree->GetBranch("gencs_simplegmotherstatus");
		if (gencs_simplegmotherstatus_branch) {gencs_simplegmotherstatus_branch->SetAddress(&gencs_simplegmotherstatus_);}
	}
	genqs_isfromt_branch = 0;
	if (tree->GetBranch("genqs_isfromt") != 0) {
		genqs_isfromt_branch = tree->GetBranch("genqs_isfromt");
		if (genqs_isfromt_branch) {genqs_isfromt_branch->SetAddress(&genqs_isfromt_);}
	}
	genqs_charge_branch = 0;
	if (tree->GetBranch("genqs_charge") != 0) {
		genqs_charge_branch = tree->GetBranch("genqs_charge");
		if (genqs_charge_branch) {genqs_charge_branch->SetAddress(&genqs_charge_);}
	}
	genqs_iso_branch = 0;
	if (tree->GetBranch("genqs_iso") != 0) {
		genqs_iso_branch = tree->GetBranch("genqs_iso");
		if (genqs_iso_branch) {genqs_iso_branch->SetAddress(&genqs_iso_);}
	}
	genqs_mass_branch = 0;
	if (tree->GetBranch("genqs_mass") != 0) {
		genqs_mass_branch = tree->GetBranch("genqs_mass");
		if (genqs_mass_branch) {genqs_mass_branch->SetAddress(&genqs_mass_);}
	}
	genqs_id_branch = 0;
	if (tree->GetBranch("genqs_id") != 0) {
		genqs_id_branch = tree->GetBranch("genqs_id");
		if (genqs_id_branch) {genqs_id_branch->SetAddress(&genqs_id_);}
	}
	genqs__genpsidx_branch = 0;
	if (tree->GetBranch("genqs__genpsidx") != 0) {
		genqs__genpsidx_branch = tree->GetBranch("genqs__genpsidx");
		if (genqs__genpsidx_branch) {genqs__genpsidx_branch->SetAddress(&genqs__genpsidx_);}
	}
	genqs_status_branch = 0;
	if (tree->GetBranch("genqs_status") != 0) {
		genqs_status_branch = tree->GetBranch("genqs_status");
		if (genqs_status_branch) {genqs_status_branch->SetAddress(&genqs_status_);}
	}
	genqs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genqs_fromHardProcessBeforeFSR") != 0) {
		genqs_fromHardProcessBeforeFSR_branch = tree->GetBranch("genqs_fromHardProcessBeforeFSR");
		if (genqs_fromHardProcessBeforeFSR_branch) {genqs_fromHardProcessBeforeFSR_branch->SetAddress(&genqs_fromHardProcessBeforeFSR_);}
	}
	genqs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genqs_fromHardProcessDecayed") != 0) {
		genqs_fromHardProcessDecayed_branch = tree->GetBranch("genqs_fromHardProcessDecayed");
		if (genqs_fromHardProcessDecayed_branch) {genqs_fromHardProcessDecayed_branch->SetAddress(&genqs_fromHardProcessDecayed_);}
	}
	genqs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genqs_fromHardProcessFinalState") != 0) {
		genqs_fromHardProcessFinalState_branch = tree->GetBranch("genqs_fromHardProcessFinalState");
		if (genqs_fromHardProcessFinalState_branch) {genqs_fromHardProcessFinalState_branch->SetAddress(&genqs_fromHardProcessFinalState_);}
	}
	genqs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genqs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genqs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genqs_isDirectHardProcessTauDecayProductFinalState");
		if (genqs_isDirectHardProcessTauDecayProductFinalState_branch) {genqs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genqs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genqs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genqs_isDirectPromptTauDecayProductFinalState") != 0) {
		genqs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genqs_isDirectPromptTauDecayProductFinalState");
		if (genqs_isDirectPromptTauDecayProductFinalState_branch) {genqs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genqs_isDirectPromptTauDecayProductFinalState_);}
	}
	genqs_isHardProcess_branch = 0;
	if (tree->GetBranch("genqs_isHardProcess") != 0) {
		genqs_isHardProcess_branch = tree->GetBranch("genqs_isHardProcess");
		if (genqs_isHardProcess_branch) {genqs_isHardProcess_branch->SetAddress(&genqs_isHardProcess_);}
	}
	genqs_isLastCopy_branch = 0;
	if (tree->GetBranch("genqs_isLastCopy") != 0) {
		genqs_isLastCopy_branch = tree->GetBranch("genqs_isLastCopy");
		if (genqs_isLastCopy_branch) {genqs_isLastCopy_branch->SetAddress(&genqs_isLastCopy_);}
	}
	genqs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genqs_isLastCopyBeforeFSR") != 0) {
		genqs_isLastCopyBeforeFSR_branch = tree->GetBranch("genqs_isLastCopyBeforeFSR");
		if (genqs_isLastCopyBeforeFSR_branch) {genqs_isLastCopyBeforeFSR_branch->SetAddress(&genqs_isLastCopyBeforeFSR_);}
	}
	genqs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genqs_isMostlyLikePythia6Status3") != 0) {
		genqs_isMostlyLikePythia6Status3_branch = tree->GetBranch("genqs_isMostlyLikePythia6Status3");
		if (genqs_isMostlyLikePythia6Status3_branch) {genqs_isMostlyLikePythia6Status3_branch->SetAddress(&genqs_isMostlyLikePythia6Status3_);}
	}
	genqs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genqs_isPromptDecayed") != 0) {
		genqs_isPromptDecayed_branch = tree->GetBranch("genqs_isPromptDecayed");
		if (genqs_isPromptDecayed_branch) {genqs_isPromptDecayed_branch->SetAddress(&genqs_isPromptDecayed_);}
	}
	genqs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genqs_isPromptFinalState") != 0) {
		genqs_isPromptFinalState_branch = tree->GetBranch("genqs_isPromptFinalState");
		if (genqs_isPromptFinalState_branch) {genqs_isPromptFinalState_branch->SetAddress(&genqs_isPromptFinalState_);}
	}
	genqs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genqs_lepdaughter_id") != 0) {
		genqs_lepdaughter_id_branch = tree->GetBranch("genqs_lepdaughter_id");
		if (genqs_lepdaughter_id_branch) {genqs_lepdaughter_id_branch->SetAddress(&genqs_lepdaughter_id_);}
	}
	genqs_gentaudecay_branch = 0;
	if (tree->GetBranch("genqs_gentaudecay") != 0) {
		genqs_gentaudecay_branch = tree->GetBranch("genqs_gentaudecay");
		if (genqs_gentaudecay_branch) {genqs_gentaudecay_branch->SetAddress(&genqs_gentaudecay_);}
	}
	gen_nfromtqs__branch = 0;
	if (tree->GetBranch("gen_nfromtqs_") != 0) {
		gen_nfromtqs__branch = tree->GetBranch("gen_nfromtqs_");
		if (gen_nfromtqs__branch) {gen_nfromtqs__branch->SetAddress(&gen_nfromtqs__);}
	}
	genqs_mothercharge_branch = 0;
	if (tree->GetBranch("genqs_mothercharge") != 0) {
		genqs_mothercharge_branch = tree->GetBranch("genqs_mothercharge");
		if (genqs_mothercharge_branch) {genqs_mothercharge_branch->SetAddress(&genqs_mothercharge_);}
	}
	genqs_motherid_branch = 0;
	if (tree->GetBranch("genqs_motherid") != 0) {
		genqs_motherid_branch = tree->GetBranch("genqs_motherid");
		if (genqs_motherid_branch) {genqs_motherid_branch->SetAddress(&genqs_motherid_);}
	}
	genqs_motheridx_branch = 0;
	if (tree->GetBranch("genqs_motheridx") != 0) {
		genqs_motheridx_branch = tree->GetBranch("genqs_motheridx");
		if (genqs_motheridx_branch) {genqs_motheridx_branch->SetAddress(&genqs_motheridx_);}
	}
	genqs_motherstatus_branch = 0;
	if (tree->GetBranch("genqs_motherstatus") != 0) {
		genqs_motherstatus_branch = tree->GetBranch("genqs_motherstatus");
		if (genqs_motherstatus_branch) {genqs_motherstatus_branch->SetAddress(&genqs_motherstatus_);}
	}
	genqs_gmothercharge_branch = 0;
	if (tree->GetBranch("genqs_gmothercharge") != 0) {
		genqs_gmothercharge_branch = tree->GetBranch("genqs_gmothercharge");
		if (genqs_gmothercharge_branch) {genqs_gmothercharge_branch->SetAddress(&genqs_gmothercharge_);}
	}
	genqs_gmotherid_branch = 0;
	if (tree->GetBranch("genqs_gmotherid") != 0) {
		genqs_gmotherid_branch = tree->GetBranch("genqs_gmotherid");
		if (genqs_gmotherid_branch) {genqs_gmotherid_branch->SetAddress(&genqs_gmotherid_);}
	}
	genqs_gmotheridx_branch = 0;
	if (tree->GetBranch("genqs_gmotheridx") != 0) {
		genqs_gmotheridx_branch = tree->GetBranch("genqs_gmotheridx");
		if (genqs_gmotheridx_branch) {genqs_gmotheridx_branch->SetAddress(&genqs_gmotheridx_);}
	}
	genqs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genqs_gmotherstatus") != 0) {
		genqs_gmotherstatus_branch = tree->GetBranch("genqs_gmotherstatus");
		if (genqs_gmotherstatus_branch) {genqs_gmotherstatus_branch->SetAddress(&genqs_gmotherstatus_);}
	}
	genqs_simplemothercharge_branch = 0;
	if (tree->GetBranch("genqs_simplemothercharge") != 0) {
		genqs_simplemothercharge_branch = tree->GetBranch("genqs_simplemothercharge");
		if (genqs_simplemothercharge_branch) {genqs_simplemothercharge_branch->SetAddress(&genqs_simplemothercharge_);}
	}
	genqs_simplemotherid_branch = 0;
	if (tree->GetBranch("genqs_simplemotherid") != 0) {
		genqs_simplemotherid_branch = tree->GetBranch("genqs_simplemotherid");
		if (genqs_simplemotherid_branch) {genqs_simplemotherid_branch->SetAddress(&genqs_simplemotherid_);}
	}
	genqs_simplemotheridx_branch = 0;
	if (tree->GetBranch("genqs_simplemotheridx") != 0) {
		genqs_simplemotheridx_branch = tree->GetBranch("genqs_simplemotheridx");
		if (genqs_simplemotheridx_branch) {genqs_simplemotheridx_branch->SetAddress(&genqs_simplemotheridx_);}
	}
	genqs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genqs_simplemotherstatus") != 0) {
		genqs_simplemotherstatus_branch = tree->GetBranch("genqs_simplemotherstatus");
		if (genqs_simplemotherstatus_branch) {genqs_simplemotherstatus_branch->SetAddress(&genqs_simplemotherstatus_);}
	}
	genqs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genqs_simplegmothercharge") != 0) {
		genqs_simplegmothercharge_branch = tree->GetBranch("genqs_simplegmothercharge");
		if (genqs_simplegmothercharge_branch) {genqs_simplegmothercharge_branch->SetAddress(&genqs_simplegmothercharge_);}
	}
	genqs_simplegmotherid_branch = 0;
	if (tree->GetBranch("genqs_simplegmotherid") != 0) {
		genqs_simplegmotherid_branch = tree->GetBranch("genqs_simplegmotherid");
		if (genqs_simplegmotherid_branch) {genqs_simplegmotherid_branch->SetAddress(&genqs_simplegmotherid_);}
	}
	genqs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genqs_simplegmotheridx") != 0) {
		genqs_simplegmotheridx_branch = tree->GetBranch("genqs_simplegmotheridx");
		if (genqs_simplegmotheridx_branch) {genqs_simplegmotheridx_branch->SetAddress(&genqs_simplegmotheridx_);}
	}
	genqs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genqs_simplegmotherstatus") != 0) {
		genqs_simplegmotherstatus_branch = tree->GetBranch("genqs_simplegmotherstatus");
		if (genqs_simplegmotherstatus_branch) {genqs_simplegmotherstatus_branch->SetAddress(&genqs_simplegmotherstatus_);}
	}
	genglus_isfromt_branch = 0;
	if (tree->GetBranch("genglus_isfromt") != 0) {
		genglus_isfromt_branch = tree->GetBranch("genglus_isfromt");
		if (genglus_isfromt_branch) {genglus_isfromt_branch->SetAddress(&genglus_isfromt_);}
	}
	genglus_charge_branch = 0;
	if (tree->GetBranch("genglus_charge") != 0) {
		genglus_charge_branch = tree->GetBranch("genglus_charge");
		if (genglus_charge_branch) {genglus_charge_branch->SetAddress(&genglus_charge_);}
	}
	genglus_iso_branch = 0;
	if (tree->GetBranch("genglus_iso") != 0) {
		genglus_iso_branch = tree->GetBranch("genglus_iso");
		if (genglus_iso_branch) {genglus_iso_branch->SetAddress(&genglus_iso_);}
	}
	genglus_mass_branch = 0;
	if (tree->GetBranch("genglus_mass") != 0) {
		genglus_mass_branch = tree->GetBranch("genglus_mass");
		if (genglus_mass_branch) {genglus_mass_branch->SetAddress(&genglus_mass_);}
	}
	genglus_id_branch = 0;
	if (tree->GetBranch("genglus_id") != 0) {
		genglus_id_branch = tree->GetBranch("genglus_id");
		if (genglus_id_branch) {genglus_id_branch->SetAddress(&genglus_id_);}
	}
	genglus__genpsidx_branch = 0;
	if (tree->GetBranch("genglus__genpsidx") != 0) {
		genglus__genpsidx_branch = tree->GetBranch("genglus__genpsidx");
		if (genglus__genpsidx_branch) {genglus__genpsidx_branch->SetAddress(&genglus__genpsidx_);}
	}
	genglus_status_branch = 0;
	if (tree->GetBranch("genglus_status") != 0) {
		genglus_status_branch = tree->GetBranch("genglus_status");
		if (genglus_status_branch) {genglus_status_branch->SetAddress(&genglus_status_);}
	}
	genglus_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genglus_fromHardProcessBeforeFSR") != 0) {
		genglus_fromHardProcessBeforeFSR_branch = tree->GetBranch("genglus_fromHardProcessBeforeFSR");
		if (genglus_fromHardProcessBeforeFSR_branch) {genglus_fromHardProcessBeforeFSR_branch->SetAddress(&genglus_fromHardProcessBeforeFSR_);}
	}
	genglus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genglus_fromHardProcessDecayed") != 0) {
		genglus_fromHardProcessDecayed_branch = tree->GetBranch("genglus_fromHardProcessDecayed");
		if (genglus_fromHardProcessDecayed_branch) {genglus_fromHardProcessDecayed_branch->SetAddress(&genglus_fromHardProcessDecayed_);}
	}
	genglus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genglus_fromHardProcessFinalState") != 0) {
		genglus_fromHardProcessFinalState_branch = tree->GetBranch("genglus_fromHardProcessFinalState");
		if (genglus_fromHardProcessFinalState_branch) {genglus_fromHardProcessFinalState_branch->SetAddress(&genglus_fromHardProcessFinalState_);}
	}
	genglus_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genglus_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genglus_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genglus_isDirectHardProcessTauDecayProductFinalState");
		if (genglus_isDirectHardProcessTauDecayProductFinalState_branch) {genglus_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genglus_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genglus_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genglus_isDirectPromptTauDecayProductFinalState") != 0) {
		genglus_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genglus_isDirectPromptTauDecayProductFinalState");
		if (genglus_isDirectPromptTauDecayProductFinalState_branch) {genglus_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genglus_isDirectPromptTauDecayProductFinalState_);}
	}
	genglus_isHardProcess_branch = 0;
	if (tree->GetBranch("genglus_isHardProcess") != 0) {
		genglus_isHardProcess_branch = tree->GetBranch("genglus_isHardProcess");
		if (genglus_isHardProcess_branch) {genglus_isHardProcess_branch->SetAddress(&genglus_isHardProcess_);}
	}
	genglus_isLastCopy_branch = 0;
	if (tree->GetBranch("genglus_isLastCopy") != 0) {
		genglus_isLastCopy_branch = tree->GetBranch("genglus_isLastCopy");
		if (genglus_isLastCopy_branch) {genglus_isLastCopy_branch->SetAddress(&genglus_isLastCopy_);}
	}
	genglus_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genglus_isLastCopyBeforeFSR") != 0) {
		genglus_isLastCopyBeforeFSR_branch = tree->GetBranch("genglus_isLastCopyBeforeFSR");
		if (genglus_isLastCopyBeforeFSR_branch) {genglus_isLastCopyBeforeFSR_branch->SetAddress(&genglus_isLastCopyBeforeFSR_);}
	}
	genglus_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genglus_isMostlyLikePythia6Status3") != 0) {
		genglus_isMostlyLikePythia6Status3_branch = tree->GetBranch("genglus_isMostlyLikePythia6Status3");
		if (genglus_isMostlyLikePythia6Status3_branch) {genglus_isMostlyLikePythia6Status3_branch->SetAddress(&genglus_isMostlyLikePythia6Status3_);}
	}
	genglus_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genglus_isPromptDecayed") != 0) {
		genglus_isPromptDecayed_branch = tree->GetBranch("genglus_isPromptDecayed");
		if (genglus_isPromptDecayed_branch) {genglus_isPromptDecayed_branch->SetAddress(&genglus_isPromptDecayed_);}
	}
	genglus_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genglus_isPromptFinalState") != 0) {
		genglus_isPromptFinalState_branch = tree->GetBranch("genglus_isPromptFinalState");
		if (genglus_isPromptFinalState_branch) {genglus_isPromptFinalState_branch->SetAddress(&genglus_isPromptFinalState_);}
	}
	genglus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genglus_lepdaughter_id") != 0) {
		genglus_lepdaughter_id_branch = tree->GetBranch("genglus_lepdaughter_id");
		if (genglus_lepdaughter_id_branch) {genglus_lepdaughter_id_branch->SetAddress(&genglus_lepdaughter_id_);}
	}
	genglus_gentaudecay_branch = 0;
	if (tree->GetBranch("genglus_gentaudecay") != 0) {
		genglus_gentaudecay_branch = tree->GetBranch("genglus_gentaudecay");
		if (genglus_gentaudecay_branch) {genglus_gentaudecay_branch->SetAddress(&genglus_gentaudecay_);}
	}
	gen_nfromtglus__branch = 0;
	if (tree->GetBranch("gen_nfromtglus_") != 0) {
		gen_nfromtglus__branch = tree->GetBranch("gen_nfromtglus_");
		if (gen_nfromtglus__branch) {gen_nfromtglus__branch->SetAddress(&gen_nfromtglus__);}
	}
	genglus_mothercharge_branch = 0;
	if (tree->GetBranch("genglus_mothercharge") != 0) {
		genglus_mothercharge_branch = tree->GetBranch("genglus_mothercharge");
		if (genglus_mothercharge_branch) {genglus_mothercharge_branch->SetAddress(&genglus_mothercharge_);}
	}
	genglus_motherid_branch = 0;
	if (tree->GetBranch("genglus_motherid") != 0) {
		genglus_motherid_branch = tree->GetBranch("genglus_motherid");
		if (genglus_motherid_branch) {genglus_motherid_branch->SetAddress(&genglus_motherid_);}
	}
	genglus_motheridx_branch = 0;
	if (tree->GetBranch("genglus_motheridx") != 0) {
		genglus_motheridx_branch = tree->GetBranch("genglus_motheridx");
		if (genglus_motheridx_branch) {genglus_motheridx_branch->SetAddress(&genglus_motheridx_);}
	}
	genglus_motherstatus_branch = 0;
	if (tree->GetBranch("genglus_motherstatus") != 0) {
		genglus_motherstatus_branch = tree->GetBranch("genglus_motherstatus");
		if (genglus_motherstatus_branch) {genglus_motherstatus_branch->SetAddress(&genglus_motherstatus_);}
	}
	genglus_gmothercharge_branch = 0;
	if (tree->GetBranch("genglus_gmothercharge") != 0) {
		genglus_gmothercharge_branch = tree->GetBranch("genglus_gmothercharge");
		if (genglus_gmothercharge_branch) {genglus_gmothercharge_branch->SetAddress(&genglus_gmothercharge_);}
	}
	genglus_gmotherid_branch = 0;
	if (tree->GetBranch("genglus_gmotherid") != 0) {
		genglus_gmotherid_branch = tree->GetBranch("genglus_gmotherid");
		if (genglus_gmotherid_branch) {genglus_gmotherid_branch->SetAddress(&genglus_gmotherid_);}
	}
	genglus_gmotheridx_branch = 0;
	if (tree->GetBranch("genglus_gmotheridx") != 0) {
		genglus_gmotheridx_branch = tree->GetBranch("genglus_gmotheridx");
		if (genglus_gmotheridx_branch) {genglus_gmotheridx_branch->SetAddress(&genglus_gmotheridx_);}
	}
	genglus_gmotherstatus_branch = 0;
	if (tree->GetBranch("genglus_gmotherstatus") != 0) {
		genglus_gmotherstatus_branch = tree->GetBranch("genglus_gmotherstatus");
		if (genglus_gmotherstatus_branch) {genglus_gmotherstatus_branch->SetAddress(&genglus_gmotherstatus_);}
	}
	genglus_simplemothercharge_branch = 0;
	if (tree->GetBranch("genglus_simplemothercharge") != 0) {
		genglus_simplemothercharge_branch = tree->GetBranch("genglus_simplemothercharge");
		if (genglus_simplemothercharge_branch) {genglus_simplemothercharge_branch->SetAddress(&genglus_simplemothercharge_);}
	}
	genglus_simplemotherid_branch = 0;
	if (tree->GetBranch("genglus_simplemotherid") != 0) {
		genglus_simplemotherid_branch = tree->GetBranch("genglus_simplemotherid");
		if (genglus_simplemotherid_branch) {genglus_simplemotherid_branch->SetAddress(&genglus_simplemotherid_);}
	}
	genglus_simplemotheridx_branch = 0;
	if (tree->GetBranch("genglus_simplemotheridx") != 0) {
		genglus_simplemotheridx_branch = tree->GetBranch("genglus_simplemotheridx");
		if (genglus_simplemotheridx_branch) {genglus_simplemotheridx_branch->SetAddress(&genglus_simplemotheridx_);}
	}
	genglus_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genglus_simplemotherstatus") != 0) {
		genglus_simplemotherstatus_branch = tree->GetBranch("genglus_simplemotherstatus");
		if (genglus_simplemotherstatus_branch) {genglus_simplemotherstatus_branch->SetAddress(&genglus_simplemotherstatus_);}
	}
	genglus_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genglus_simplegmothercharge") != 0) {
		genglus_simplegmothercharge_branch = tree->GetBranch("genglus_simplegmothercharge");
		if (genglus_simplegmothercharge_branch) {genglus_simplegmothercharge_branch->SetAddress(&genglus_simplegmothercharge_);}
	}
	genglus_simplegmotherid_branch = 0;
	if (tree->GetBranch("genglus_simplegmotherid") != 0) {
		genglus_simplegmotherid_branch = tree->GetBranch("genglus_simplegmotherid");
		if (genglus_simplegmotherid_branch) {genglus_simplegmotherid_branch->SetAddress(&genglus_simplegmotherid_);}
	}
	genglus_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genglus_simplegmotheridx") != 0) {
		genglus_simplegmotheridx_branch = tree->GetBranch("genglus_simplegmotheridx");
		if (genglus_simplegmotheridx_branch) {genglus_simplegmotheridx_branch->SetAddress(&genglus_simplegmotheridx_);}
	}
	genglus_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genglus_simplegmotherstatus") != 0) {
		genglus_simplegmotherstatus_branch = tree->GetBranch("genglus_simplegmotherstatus");
		if (genglus_simplegmotherstatus_branch) {genglus_simplegmotherstatus_branch->SetAddress(&genglus_simplegmotherstatus_);}
	}
	genws_isfromt_branch = 0;
	if (tree->GetBranch("genws_isfromt") != 0) {
		genws_isfromt_branch = tree->GetBranch("genws_isfromt");
		if (genws_isfromt_branch) {genws_isfromt_branch->SetAddress(&genws_isfromt_);}
	}
	genws_charge_branch = 0;
	if (tree->GetBranch("genws_charge") != 0) {
		genws_charge_branch = tree->GetBranch("genws_charge");
		if (genws_charge_branch) {genws_charge_branch->SetAddress(&genws_charge_);}
	}
	genws_iso_branch = 0;
	if (tree->GetBranch("genws_iso") != 0) {
		genws_iso_branch = tree->GetBranch("genws_iso");
		if (genws_iso_branch) {genws_iso_branch->SetAddress(&genws_iso_);}
	}
	genws_mass_branch = 0;
	if (tree->GetBranch("genws_mass") != 0) {
		genws_mass_branch = tree->GetBranch("genws_mass");
		if (genws_mass_branch) {genws_mass_branch->SetAddress(&genws_mass_);}
	}
	genws_id_branch = 0;
	if (tree->GetBranch("genws_id") != 0) {
		genws_id_branch = tree->GetBranch("genws_id");
		if (genws_id_branch) {genws_id_branch->SetAddress(&genws_id_);}
	}
	genws__genpsidx_branch = 0;
	if (tree->GetBranch("genws__genpsidx") != 0) {
		genws__genpsidx_branch = tree->GetBranch("genws__genpsidx");
		if (genws__genpsidx_branch) {genws__genpsidx_branch->SetAddress(&genws__genpsidx_);}
	}
	genws_status_branch = 0;
	if (tree->GetBranch("genws_status") != 0) {
		genws_status_branch = tree->GetBranch("genws_status");
		if (genws_status_branch) {genws_status_branch->SetAddress(&genws_status_);}
	}
	genws_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genws_fromHardProcessBeforeFSR") != 0) {
		genws_fromHardProcessBeforeFSR_branch = tree->GetBranch("genws_fromHardProcessBeforeFSR");
		if (genws_fromHardProcessBeforeFSR_branch) {genws_fromHardProcessBeforeFSR_branch->SetAddress(&genws_fromHardProcessBeforeFSR_);}
	}
	genws_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genws_fromHardProcessDecayed") != 0) {
		genws_fromHardProcessDecayed_branch = tree->GetBranch("genws_fromHardProcessDecayed");
		if (genws_fromHardProcessDecayed_branch) {genws_fromHardProcessDecayed_branch->SetAddress(&genws_fromHardProcessDecayed_);}
	}
	genws_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genws_fromHardProcessFinalState") != 0) {
		genws_fromHardProcessFinalState_branch = tree->GetBranch("genws_fromHardProcessFinalState");
		if (genws_fromHardProcessFinalState_branch) {genws_fromHardProcessFinalState_branch->SetAddress(&genws_fromHardProcessFinalState_);}
	}
	genws_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genws_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genws_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genws_isDirectHardProcessTauDecayProductFinalState");
		if (genws_isDirectHardProcessTauDecayProductFinalState_branch) {genws_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genws_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genws_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genws_isDirectPromptTauDecayProductFinalState") != 0) {
		genws_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genws_isDirectPromptTauDecayProductFinalState");
		if (genws_isDirectPromptTauDecayProductFinalState_branch) {genws_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genws_isDirectPromptTauDecayProductFinalState_);}
	}
	genws_isHardProcess_branch = 0;
	if (tree->GetBranch("genws_isHardProcess") != 0) {
		genws_isHardProcess_branch = tree->GetBranch("genws_isHardProcess");
		if (genws_isHardProcess_branch) {genws_isHardProcess_branch->SetAddress(&genws_isHardProcess_);}
	}
	genws_isLastCopy_branch = 0;
	if (tree->GetBranch("genws_isLastCopy") != 0) {
		genws_isLastCopy_branch = tree->GetBranch("genws_isLastCopy");
		if (genws_isLastCopy_branch) {genws_isLastCopy_branch->SetAddress(&genws_isLastCopy_);}
	}
	genws_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genws_isLastCopyBeforeFSR") != 0) {
		genws_isLastCopyBeforeFSR_branch = tree->GetBranch("genws_isLastCopyBeforeFSR");
		if (genws_isLastCopyBeforeFSR_branch) {genws_isLastCopyBeforeFSR_branch->SetAddress(&genws_isLastCopyBeforeFSR_);}
	}
	genws_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genws_isMostlyLikePythia6Status3") != 0) {
		genws_isMostlyLikePythia6Status3_branch = tree->GetBranch("genws_isMostlyLikePythia6Status3");
		if (genws_isMostlyLikePythia6Status3_branch) {genws_isMostlyLikePythia6Status3_branch->SetAddress(&genws_isMostlyLikePythia6Status3_);}
	}
	genws_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genws_isPromptDecayed") != 0) {
		genws_isPromptDecayed_branch = tree->GetBranch("genws_isPromptDecayed");
		if (genws_isPromptDecayed_branch) {genws_isPromptDecayed_branch->SetAddress(&genws_isPromptDecayed_);}
	}
	genws_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genws_isPromptFinalState") != 0) {
		genws_isPromptFinalState_branch = tree->GetBranch("genws_isPromptFinalState");
		if (genws_isPromptFinalState_branch) {genws_isPromptFinalState_branch->SetAddress(&genws_isPromptFinalState_);}
	}
	genws_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genws_lepdaughter_id") != 0) {
		genws_lepdaughter_id_branch = tree->GetBranch("genws_lepdaughter_id");
		if (genws_lepdaughter_id_branch) {genws_lepdaughter_id_branch->SetAddress(&genws_lepdaughter_id_);}
	}
	genws_gentaudecay_branch = 0;
	if (tree->GetBranch("genws_gentaudecay") != 0) {
		genws_gentaudecay_branch = tree->GetBranch("genws_gentaudecay");
		if (genws_gentaudecay_branch) {genws_gentaudecay_branch->SetAddress(&genws_gentaudecay_);}
	}
	gen_nfromtws__branch = 0;
	if (tree->GetBranch("gen_nfromtws_") != 0) {
		gen_nfromtws__branch = tree->GetBranch("gen_nfromtws_");
		if (gen_nfromtws__branch) {gen_nfromtws__branch->SetAddress(&gen_nfromtws__);}
	}
	genws_mothercharge_branch = 0;
	if (tree->GetBranch("genws_mothercharge") != 0) {
		genws_mothercharge_branch = tree->GetBranch("genws_mothercharge");
		if (genws_mothercharge_branch) {genws_mothercharge_branch->SetAddress(&genws_mothercharge_);}
	}
	genws_motherid_branch = 0;
	if (tree->GetBranch("genws_motherid") != 0) {
		genws_motherid_branch = tree->GetBranch("genws_motherid");
		if (genws_motherid_branch) {genws_motherid_branch->SetAddress(&genws_motherid_);}
	}
	genws_motheridx_branch = 0;
	if (tree->GetBranch("genws_motheridx") != 0) {
		genws_motheridx_branch = tree->GetBranch("genws_motheridx");
		if (genws_motheridx_branch) {genws_motheridx_branch->SetAddress(&genws_motheridx_);}
	}
	genws_motherstatus_branch = 0;
	if (tree->GetBranch("genws_motherstatus") != 0) {
		genws_motherstatus_branch = tree->GetBranch("genws_motherstatus");
		if (genws_motherstatus_branch) {genws_motherstatus_branch->SetAddress(&genws_motherstatus_);}
	}
	genws_gmothercharge_branch = 0;
	if (tree->GetBranch("genws_gmothercharge") != 0) {
		genws_gmothercharge_branch = tree->GetBranch("genws_gmothercharge");
		if (genws_gmothercharge_branch) {genws_gmothercharge_branch->SetAddress(&genws_gmothercharge_);}
	}
	genws_gmotherid_branch = 0;
	if (tree->GetBranch("genws_gmotherid") != 0) {
		genws_gmotherid_branch = tree->GetBranch("genws_gmotherid");
		if (genws_gmotherid_branch) {genws_gmotherid_branch->SetAddress(&genws_gmotherid_);}
	}
	genws_gmotheridx_branch = 0;
	if (tree->GetBranch("genws_gmotheridx") != 0) {
		genws_gmotheridx_branch = tree->GetBranch("genws_gmotheridx");
		if (genws_gmotheridx_branch) {genws_gmotheridx_branch->SetAddress(&genws_gmotheridx_);}
	}
	genws_gmotherstatus_branch = 0;
	if (tree->GetBranch("genws_gmotherstatus") != 0) {
		genws_gmotherstatus_branch = tree->GetBranch("genws_gmotherstatus");
		if (genws_gmotherstatus_branch) {genws_gmotherstatus_branch->SetAddress(&genws_gmotherstatus_);}
	}
	genws_simplemothercharge_branch = 0;
	if (tree->GetBranch("genws_simplemothercharge") != 0) {
		genws_simplemothercharge_branch = tree->GetBranch("genws_simplemothercharge");
		if (genws_simplemothercharge_branch) {genws_simplemothercharge_branch->SetAddress(&genws_simplemothercharge_);}
	}
	genws_simplemotherid_branch = 0;
	if (tree->GetBranch("genws_simplemotherid") != 0) {
		genws_simplemotherid_branch = tree->GetBranch("genws_simplemotherid");
		if (genws_simplemotherid_branch) {genws_simplemotherid_branch->SetAddress(&genws_simplemotherid_);}
	}
	genws_simplemotheridx_branch = 0;
	if (tree->GetBranch("genws_simplemotheridx") != 0) {
		genws_simplemotheridx_branch = tree->GetBranch("genws_simplemotheridx");
		if (genws_simplemotheridx_branch) {genws_simplemotheridx_branch->SetAddress(&genws_simplemotheridx_);}
	}
	genws_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genws_simplemotherstatus") != 0) {
		genws_simplemotherstatus_branch = tree->GetBranch("genws_simplemotherstatus");
		if (genws_simplemotherstatus_branch) {genws_simplemotherstatus_branch->SetAddress(&genws_simplemotherstatus_);}
	}
	genws_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genws_simplegmothercharge") != 0) {
		genws_simplegmothercharge_branch = tree->GetBranch("genws_simplegmothercharge");
		if (genws_simplegmothercharge_branch) {genws_simplegmothercharge_branch->SetAddress(&genws_simplegmothercharge_);}
	}
	genws_simplegmotherid_branch = 0;
	if (tree->GetBranch("genws_simplegmotherid") != 0) {
		genws_simplegmotherid_branch = tree->GetBranch("genws_simplegmotherid");
		if (genws_simplegmotherid_branch) {genws_simplegmotherid_branch->SetAddress(&genws_simplegmotherid_);}
	}
	genws_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genws_simplegmotheridx") != 0) {
		genws_simplegmotheridx_branch = tree->GetBranch("genws_simplegmotheridx");
		if (genws_simplegmotheridx_branch) {genws_simplegmotheridx_branch->SetAddress(&genws_simplegmotheridx_);}
	}
	genws_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genws_simplegmotherstatus") != 0) {
		genws_simplegmotherstatus_branch = tree->GetBranch("genws_simplegmotherstatus");
		if (genws_simplegmotherstatus_branch) {genws_simplegmotherstatus_branch->SetAddress(&genws_simplegmotherstatus_);}
	}
	genzs_isfromt_branch = 0;
	if (tree->GetBranch("genzs_isfromt") != 0) {
		genzs_isfromt_branch = tree->GetBranch("genzs_isfromt");
		if (genzs_isfromt_branch) {genzs_isfromt_branch->SetAddress(&genzs_isfromt_);}
	}
	genzs_charge_branch = 0;
	if (tree->GetBranch("genzs_charge") != 0) {
		genzs_charge_branch = tree->GetBranch("genzs_charge");
		if (genzs_charge_branch) {genzs_charge_branch->SetAddress(&genzs_charge_);}
	}
	genzs_iso_branch = 0;
	if (tree->GetBranch("genzs_iso") != 0) {
		genzs_iso_branch = tree->GetBranch("genzs_iso");
		if (genzs_iso_branch) {genzs_iso_branch->SetAddress(&genzs_iso_);}
	}
	genzs_mass_branch = 0;
	if (tree->GetBranch("genzs_mass") != 0) {
		genzs_mass_branch = tree->GetBranch("genzs_mass");
		if (genzs_mass_branch) {genzs_mass_branch->SetAddress(&genzs_mass_);}
	}
	genzs_id_branch = 0;
	if (tree->GetBranch("genzs_id") != 0) {
		genzs_id_branch = tree->GetBranch("genzs_id");
		if (genzs_id_branch) {genzs_id_branch->SetAddress(&genzs_id_);}
	}
	genzs__genpsidx_branch = 0;
	if (tree->GetBranch("genzs__genpsidx") != 0) {
		genzs__genpsidx_branch = tree->GetBranch("genzs__genpsidx");
		if (genzs__genpsidx_branch) {genzs__genpsidx_branch->SetAddress(&genzs__genpsidx_);}
	}
	genzs_status_branch = 0;
	if (tree->GetBranch("genzs_status") != 0) {
		genzs_status_branch = tree->GetBranch("genzs_status");
		if (genzs_status_branch) {genzs_status_branch->SetAddress(&genzs_status_);}
	}
	genzs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genzs_fromHardProcessBeforeFSR") != 0) {
		genzs_fromHardProcessBeforeFSR_branch = tree->GetBranch("genzs_fromHardProcessBeforeFSR");
		if (genzs_fromHardProcessBeforeFSR_branch) {genzs_fromHardProcessBeforeFSR_branch->SetAddress(&genzs_fromHardProcessBeforeFSR_);}
	}
	genzs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genzs_fromHardProcessDecayed") != 0) {
		genzs_fromHardProcessDecayed_branch = tree->GetBranch("genzs_fromHardProcessDecayed");
		if (genzs_fromHardProcessDecayed_branch) {genzs_fromHardProcessDecayed_branch->SetAddress(&genzs_fromHardProcessDecayed_);}
	}
	genzs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genzs_fromHardProcessFinalState") != 0) {
		genzs_fromHardProcessFinalState_branch = tree->GetBranch("genzs_fromHardProcessFinalState");
		if (genzs_fromHardProcessFinalState_branch) {genzs_fromHardProcessFinalState_branch->SetAddress(&genzs_fromHardProcessFinalState_);}
	}
	genzs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genzs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genzs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genzs_isDirectHardProcessTauDecayProductFinalState");
		if (genzs_isDirectHardProcessTauDecayProductFinalState_branch) {genzs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genzs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genzs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genzs_isDirectPromptTauDecayProductFinalState") != 0) {
		genzs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genzs_isDirectPromptTauDecayProductFinalState");
		if (genzs_isDirectPromptTauDecayProductFinalState_branch) {genzs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genzs_isDirectPromptTauDecayProductFinalState_);}
	}
	genzs_isHardProcess_branch = 0;
	if (tree->GetBranch("genzs_isHardProcess") != 0) {
		genzs_isHardProcess_branch = tree->GetBranch("genzs_isHardProcess");
		if (genzs_isHardProcess_branch) {genzs_isHardProcess_branch->SetAddress(&genzs_isHardProcess_);}
	}
	genzs_isLastCopy_branch = 0;
	if (tree->GetBranch("genzs_isLastCopy") != 0) {
		genzs_isLastCopy_branch = tree->GetBranch("genzs_isLastCopy");
		if (genzs_isLastCopy_branch) {genzs_isLastCopy_branch->SetAddress(&genzs_isLastCopy_);}
	}
	genzs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genzs_isLastCopyBeforeFSR") != 0) {
		genzs_isLastCopyBeforeFSR_branch = tree->GetBranch("genzs_isLastCopyBeforeFSR");
		if (genzs_isLastCopyBeforeFSR_branch) {genzs_isLastCopyBeforeFSR_branch->SetAddress(&genzs_isLastCopyBeforeFSR_);}
	}
	genzs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genzs_isMostlyLikePythia6Status3") != 0) {
		genzs_isMostlyLikePythia6Status3_branch = tree->GetBranch("genzs_isMostlyLikePythia6Status3");
		if (genzs_isMostlyLikePythia6Status3_branch) {genzs_isMostlyLikePythia6Status3_branch->SetAddress(&genzs_isMostlyLikePythia6Status3_);}
	}
	genzs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genzs_isPromptDecayed") != 0) {
		genzs_isPromptDecayed_branch = tree->GetBranch("genzs_isPromptDecayed");
		if (genzs_isPromptDecayed_branch) {genzs_isPromptDecayed_branch->SetAddress(&genzs_isPromptDecayed_);}
	}
	genzs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genzs_isPromptFinalState") != 0) {
		genzs_isPromptFinalState_branch = tree->GetBranch("genzs_isPromptFinalState");
		if (genzs_isPromptFinalState_branch) {genzs_isPromptFinalState_branch->SetAddress(&genzs_isPromptFinalState_);}
	}
	genzs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genzs_lepdaughter_id") != 0) {
		genzs_lepdaughter_id_branch = tree->GetBranch("genzs_lepdaughter_id");
		if (genzs_lepdaughter_id_branch) {genzs_lepdaughter_id_branch->SetAddress(&genzs_lepdaughter_id_);}
	}
	genzs_gentaudecay_branch = 0;
	if (tree->GetBranch("genzs_gentaudecay") != 0) {
		genzs_gentaudecay_branch = tree->GetBranch("genzs_gentaudecay");
		if (genzs_gentaudecay_branch) {genzs_gentaudecay_branch->SetAddress(&genzs_gentaudecay_);}
	}
	gen_nfromtzs__branch = 0;
	if (tree->GetBranch("gen_nfromtzs_") != 0) {
		gen_nfromtzs__branch = tree->GetBranch("gen_nfromtzs_");
		if (gen_nfromtzs__branch) {gen_nfromtzs__branch->SetAddress(&gen_nfromtzs__);}
	}
	genzs_mothercharge_branch = 0;
	if (tree->GetBranch("genzs_mothercharge") != 0) {
		genzs_mothercharge_branch = tree->GetBranch("genzs_mothercharge");
		if (genzs_mothercharge_branch) {genzs_mothercharge_branch->SetAddress(&genzs_mothercharge_);}
	}
	genzs_motherid_branch = 0;
	if (tree->GetBranch("genzs_motherid") != 0) {
		genzs_motherid_branch = tree->GetBranch("genzs_motherid");
		if (genzs_motherid_branch) {genzs_motherid_branch->SetAddress(&genzs_motherid_);}
	}
	genzs_motheridx_branch = 0;
	if (tree->GetBranch("genzs_motheridx") != 0) {
		genzs_motheridx_branch = tree->GetBranch("genzs_motheridx");
		if (genzs_motheridx_branch) {genzs_motheridx_branch->SetAddress(&genzs_motheridx_);}
	}
	genzs_motherstatus_branch = 0;
	if (tree->GetBranch("genzs_motherstatus") != 0) {
		genzs_motherstatus_branch = tree->GetBranch("genzs_motherstatus");
		if (genzs_motherstatus_branch) {genzs_motherstatus_branch->SetAddress(&genzs_motherstatus_);}
	}
	genzs_gmothercharge_branch = 0;
	if (tree->GetBranch("genzs_gmothercharge") != 0) {
		genzs_gmothercharge_branch = tree->GetBranch("genzs_gmothercharge");
		if (genzs_gmothercharge_branch) {genzs_gmothercharge_branch->SetAddress(&genzs_gmothercharge_);}
	}
	genzs_gmotherid_branch = 0;
	if (tree->GetBranch("genzs_gmotherid") != 0) {
		genzs_gmotherid_branch = tree->GetBranch("genzs_gmotherid");
		if (genzs_gmotherid_branch) {genzs_gmotherid_branch->SetAddress(&genzs_gmotherid_);}
	}
	genzs_gmotheridx_branch = 0;
	if (tree->GetBranch("genzs_gmotheridx") != 0) {
		genzs_gmotheridx_branch = tree->GetBranch("genzs_gmotheridx");
		if (genzs_gmotheridx_branch) {genzs_gmotheridx_branch->SetAddress(&genzs_gmotheridx_);}
	}
	genzs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genzs_gmotherstatus") != 0) {
		genzs_gmotherstatus_branch = tree->GetBranch("genzs_gmotherstatus");
		if (genzs_gmotherstatus_branch) {genzs_gmotherstatus_branch->SetAddress(&genzs_gmotherstatus_);}
	}
	genzs_simplemothercharge_branch = 0;
	if (tree->GetBranch("genzs_simplemothercharge") != 0) {
		genzs_simplemothercharge_branch = tree->GetBranch("genzs_simplemothercharge");
		if (genzs_simplemothercharge_branch) {genzs_simplemothercharge_branch->SetAddress(&genzs_simplemothercharge_);}
	}
	genzs_simplemotherid_branch = 0;
	if (tree->GetBranch("genzs_simplemotherid") != 0) {
		genzs_simplemotherid_branch = tree->GetBranch("genzs_simplemotherid");
		if (genzs_simplemotherid_branch) {genzs_simplemotherid_branch->SetAddress(&genzs_simplemotherid_);}
	}
	genzs_simplemotheridx_branch = 0;
	if (tree->GetBranch("genzs_simplemotheridx") != 0) {
		genzs_simplemotheridx_branch = tree->GetBranch("genzs_simplemotheridx");
		if (genzs_simplemotheridx_branch) {genzs_simplemotheridx_branch->SetAddress(&genzs_simplemotheridx_);}
	}
	genzs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genzs_simplemotherstatus") != 0) {
		genzs_simplemotherstatus_branch = tree->GetBranch("genzs_simplemotherstatus");
		if (genzs_simplemotherstatus_branch) {genzs_simplemotherstatus_branch->SetAddress(&genzs_simplemotherstatus_);}
	}
	genzs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genzs_simplegmothercharge") != 0) {
		genzs_simplegmothercharge_branch = tree->GetBranch("genzs_simplegmothercharge");
		if (genzs_simplegmothercharge_branch) {genzs_simplegmothercharge_branch->SetAddress(&genzs_simplegmothercharge_);}
	}
	genzs_simplegmotherid_branch = 0;
	if (tree->GetBranch("genzs_simplegmotherid") != 0) {
		genzs_simplegmotherid_branch = tree->GetBranch("genzs_simplegmotherid");
		if (genzs_simplegmotherid_branch) {genzs_simplegmotherid_branch->SetAddress(&genzs_simplegmotherid_);}
	}
	genzs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genzs_simplegmotheridx") != 0) {
		genzs_simplegmotheridx_branch = tree->GetBranch("genzs_simplegmotheridx");
		if (genzs_simplegmotheridx_branch) {genzs_simplegmotheridx_branch->SetAddress(&genzs_simplegmotheridx_);}
	}
	genzs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genzs_simplegmotherstatus") != 0) {
		genzs_simplegmotherstatus_branch = tree->GetBranch("genzs_simplegmotherstatus");
		if (genzs_simplegmotherstatus_branch) {genzs_simplegmotherstatus_branch->SetAddress(&genzs_simplegmotherstatus_);}
	}
	genphs_isfromt_branch = 0;
	if (tree->GetBranch("genphs_isfromt") != 0) {
		genphs_isfromt_branch = tree->GetBranch("genphs_isfromt");
		if (genphs_isfromt_branch) {genphs_isfromt_branch->SetAddress(&genphs_isfromt_);}
	}
	genphs_charge_branch = 0;
	if (tree->GetBranch("genphs_charge") != 0) {
		genphs_charge_branch = tree->GetBranch("genphs_charge");
		if (genphs_charge_branch) {genphs_charge_branch->SetAddress(&genphs_charge_);}
	}
	genphs_iso_branch = 0;
	if (tree->GetBranch("genphs_iso") != 0) {
		genphs_iso_branch = tree->GetBranch("genphs_iso");
		if (genphs_iso_branch) {genphs_iso_branch->SetAddress(&genphs_iso_);}
	}
	genphs_mass_branch = 0;
	if (tree->GetBranch("genphs_mass") != 0) {
		genphs_mass_branch = tree->GetBranch("genphs_mass");
		if (genphs_mass_branch) {genphs_mass_branch->SetAddress(&genphs_mass_);}
	}
	genphs_id_branch = 0;
	if (tree->GetBranch("genphs_id") != 0) {
		genphs_id_branch = tree->GetBranch("genphs_id");
		if (genphs_id_branch) {genphs_id_branch->SetAddress(&genphs_id_);}
	}
	genphs__genpsidx_branch = 0;
	if (tree->GetBranch("genphs__genpsidx") != 0) {
		genphs__genpsidx_branch = tree->GetBranch("genphs__genpsidx");
		if (genphs__genpsidx_branch) {genphs__genpsidx_branch->SetAddress(&genphs__genpsidx_);}
	}
	genphs_status_branch = 0;
	if (tree->GetBranch("genphs_status") != 0) {
		genphs_status_branch = tree->GetBranch("genphs_status");
		if (genphs_status_branch) {genphs_status_branch->SetAddress(&genphs_status_);}
	}
	genphs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genphs_fromHardProcessBeforeFSR") != 0) {
		genphs_fromHardProcessBeforeFSR_branch = tree->GetBranch("genphs_fromHardProcessBeforeFSR");
		if (genphs_fromHardProcessBeforeFSR_branch) {genphs_fromHardProcessBeforeFSR_branch->SetAddress(&genphs_fromHardProcessBeforeFSR_);}
	}
	genphs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genphs_fromHardProcessDecayed") != 0) {
		genphs_fromHardProcessDecayed_branch = tree->GetBranch("genphs_fromHardProcessDecayed");
		if (genphs_fromHardProcessDecayed_branch) {genphs_fromHardProcessDecayed_branch->SetAddress(&genphs_fromHardProcessDecayed_);}
	}
	genphs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genphs_fromHardProcessFinalState") != 0) {
		genphs_fromHardProcessFinalState_branch = tree->GetBranch("genphs_fromHardProcessFinalState");
		if (genphs_fromHardProcessFinalState_branch) {genphs_fromHardProcessFinalState_branch->SetAddress(&genphs_fromHardProcessFinalState_);}
	}
	genphs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genphs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genphs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genphs_isDirectHardProcessTauDecayProductFinalState");
		if (genphs_isDirectHardProcessTauDecayProductFinalState_branch) {genphs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genphs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genphs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genphs_isDirectPromptTauDecayProductFinalState") != 0) {
		genphs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genphs_isDirectPromptTauDecayProductFinalState");
		if (genphs_isDirectPromptTauDecayProductFinalState_branch) {genphs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genphs_isDirectPromptTauDecayProductFinalState_);}
	}
	genphs_isHardProcess_branch = 0;
	if (tree->GetBranch("genphs_isHardProcess") != 0) {
		genphs_isHardProcess_branch = tree->GetBranch("genphs_isHardProcess");
		if (genphs_isHardProcess_branch) {genphs_isHardProcess_branch->SetAddress(&genphs_isHardProcess_);}
	}
	genphs_isLastCopy_branch = 0;
	if (tree->GetBranch("genphs_isLastCopy") != 0) {
		genphs_isLastCopy_branch = tree->GetBranch("genphs_isLastCopy");
		if (genphs_isLastCopy_branch) {genphs_isLastCopy_branch->SetAddress(&genphs_isLastCopy_);}
	}
	genphs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genphs_isLastCopyBeforeFSR") != 0) {
		genphs_isLastCopyBeforeFSR_branch = tree->GetBranch("genphs_isLastCopyBeforeFSR");
		if (genphs_isLastCopyBeforeFSR_branch) {genphs_isLastCopyBeforeFSR_branch->SetAddress(&genphs_isLastCopyBeforeFSR_);}
	}
	genphs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genphs_isMostlyLikePythia6Status3") != 0) {
		genphs_isMostlyLikePythia6Status3_branch = tree->GetBranch("genphs_isMostlyLikePythia6Status3");
		if (genphs_isMostlyLikePythia6Status3_branch) {genphs_isMostlyLikePythia6Status3_branch->SetAddress(&genphs_isMostlyLikePythia6Status3_);}
	}
	genphs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genphs_isPromptDecayed") != 0) {
		genphs_isPromptDecayed_branch = tree->GetBranch("genphs_isPromptDecayed");
		if (genphs_isPromptDecayed_branch) {genphs_isPromptDecayed_branch->SetAddress(&genphs_isPromptDecayed_);}
	}
	genphs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genphs_isPromptFinalState") != 0) {
		genphs_isPromptFinalState_branch = tree->GetBranch("genphs_isPromptFinalState");
		if (genphs_isPromptFinalState_branch) {genphs_isPromptFinalState_branch->SetAddress(&genphs_isPromptFinalState_);}
	}
	genphs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genphs_lepdaughter_id") != 0) {
		genphs_lepdaughter_id_branch = tree->GetBranch("genphs_lepdaughter_id");
		if (genphs_lepdaughter_id_branch) {genphs_lepdaughter_id_branch->SetAddress(&genphs_lepdaughter_id_);}
	}
	genphs_gentaudecay_branch = 0;
	if (tree->GetBranch("genphs_gentaudecay") != 0) {
		genphs_gentaudecay_branch = tree->GetBranch("genphs_gentaudecay");
		if (genphs_gentaudecay_branch) {genphs_gentaudecay_branch->SetAddress(&genphs_gentaudecay_);}
	}
	gen_nfromtphs__branch = 0;
	if (tree->GetBranch("gen_nfromtphs_") != 0) {
		gen_nfromtphs__branch = tree->GetBranch("gen_nfromtphs_");
		if (gen_nfromtphs__branch) {gen_nfromtphs__branch->SetAddress(&gen_nfromtphs__);}
	}
	genphs_mothercharge_branch = 0;
	if (tree->GetBranch("genphs_mothercharge") != 0) {
		genphs_mothercharge_branch = tree->GetBranch("genphs_mothercharge");
		if (genphs_mothercharge_branch) {genphs_mothercharge_branch->SetAddress(&genphs_mothercharge_);}
	}
	genphs_motherid_branch = 0;
	if (tree->GetBranch("genphs_motherid") != 0) {
		genphs_motherid_branch = tree->GetBranch("genphs_motherid");
		if (genphs_motherid_branch) {genphs_motherid_branch->SetAddress(&genphs_motherid_);}
	}
	genphs_motheridx_branch = 0;
	if (tree->GetBranch("genphs_motheridx") != 0) {
		genphs_motheridx_branch = tree->GetBranch("genphs_motheridx");
		if (genphs_motheridx_branch) {genphs_motheridx_branch->SetAddress(&genphs_motheridx_);}
	}
	genphs_motherstatus_branch = 0;
	if (tree->GetBranch("genphs_motherstatus") != 0) {
		genphs_motherstatus_branch = tree->GetBranch("genphs_motherstatus");
		if (genphs_motherstatus_branch) {genphs_motherstatus_branch->SetAddress(&genphs_motherstatus_);}
	}
	genphs_gmothercharge_branch = 0;
	if (tree->GetBranch("genphs_gmothercharge") != 0) {
		genphs_gmothercharge_branch = tree->GetBranch("genphs_gmothercharge");
		if (genphs_gmothercharge_branch) {genphs_gmothercharge_branch->SetAddress(&genphs_gmothercharge_);}
	}
	genphs_gmotherid_branch = 0;
	if (tree->GetBranch("genphs_gmotherid") != 0) {
		genphs_gmotherid_branch = tree->GetBranch("genphs_gmotherid");
		if (genphs_gmotherid_branch) {genphs_gmotherid_branch->SetAddress(&genphs_gmotherid_);}
	}
	genphs_gmotheridx_branch = 0;
	if (tree->GetBranch("genphs_gmotheridx") != 0) {
		genphs_gmotheridx_branch = tree->GetBranch("genphs_gmotheridx");
		if (genphs_gmotheridx_branch) {genphs_gmotheridx_branch->SetAddress(&genphs_gmotheridx_);}
	}
	genphs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genphs_gmotherstatus") != 0) {
		genphs_gmotherstatus_branch = tree->GetBranch("genphs_gmotherstatus");
		if (genphs_gmotherstatus_branch) {genphs_gmotherstatus_branch->SetAddress(&genphs_gmotherstatus_);}
	}
	genphs_simplemothercharge_branch = 0;
	if (tree->GetBranch("genphs_simplemothercharge") != 0) {
		genphs_simplemothercharge_branch = tree->GetBranch("genphs_simplemothercharge");
		if (genphs_simplemothercharge_branch) {genphs_simplemothercharge_branch->SetAddress(&genphs_simplemothercharge_);}
	}
	genphs_simplemotherid_branch = 0;
	if (tree->GetBranch("genphs_simplemotherid") != 0) {
		genphs_simplemotherid_branch = tree->GetBranch("genphs_simplemotherid");
		if (genphs_simplemotherid_branch) {genphs_simplemotherid_branch->SetAddress(&genphs_simplemotherid_);}
	}
	genphs_simplemotheridx_branch = 0;
	if (tree->GetBranch("genphs_simplemotheridx") != 0) {
		genphs_simplemotheridx_branch = tree->GetBranch("genphs_simplemotheridx");
		if (genphs_simplemotheridx_branch) {genphs_simplemotheridx_branch->SetAddress(&genphs_simplemotheridx_);}
	}
	genphs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genphs_simplemotherstatus") != 0) {
		genphs_simplemotherstatus_branch = tree->GetBranch("genphs_simplemotherstatus");
		if (genphs_simplemotherstatus_branch) {genphs_simplemotherstatus_branch->SetAddress(&genphs_simplemotherstatus_);}
	}
	genphs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genphs_simplegmothercharge") != 0) {
		genphs_simplegmothercharge_branch = tree->GetBranch("genphs_simplegmothercharge");
		if (genphs_simplegmothercharge_branch) {genphs_simplegmothercharge_branch->SetAddress(&genphs_simplegmothercharge_);}
	}
	genphs_simplegmotherid_branch = 0;
	if (tree->GetBranch("genphs_simplegmotherid") != 0) {
		genphs_simplegmotherid_branch = tree->GetBranch("genphs_simplegmotherid");
		if (genphs_simplegmotherid_branch) {genphs_simplegmotherid_branch->SetAddress(&genphs_simplegmotherid_);}
	}
	genphs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genphs_simplegmotheridx") != 0) {
		genphs_simplegmotheridx_branch = tree->GetBranch("genphs_simplegmotheridx");
		if (genphs_simplegmotheridx_branch) {genphs_simplegmotheridx_branch->SetAddress(&genphs_simplegmotheridx_);}
	}
	genphs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genphs_simplegmotherstatus") != 0) {
		genphs_simplegmotherstatus_branch = tree->GetBranch("genphs_simplegmotherstatus");
		if (genphs_simplegmotherstatus_branch) {genphs_simplegmotherstatus_branch->SetAddress(&genphs_simplegmotherstatus_);}
	}
	genhs_isfromt_branch = 0;
	if (tree->GetBranch("genhs_isfromt") != 0) {
		genhs_isfromt_branch = tree->GetBranch("genhs_isfromt");
		if (genhs_isfromt_branch) {genhs_isfromt_branch->SetAddress(&genhs_isfromt_);}
	}
	genhs_charge_branch = 0;
	if (tree->GetBranch("genhs_charge") != 0) {
		genhs_charge_branch = tree->GetBranch("genhs_charge");
		if (genhs_charge_branch) {genhs_charge_branch->SetAddress(&genhs_charge_);}
	}
	genhs_iso_branch = 0;
	if (tree->GetBranch("genhs_iso") != 0) {
		genhs_iso_branch = tree->GetBranch("genhs_iso");
		if (genhs_iso_branch) {genhs_iso_branch->SetAddress(&genhs_iso_);}
	}
	genhs_mass_branch = 0;
	if (tree->GetBranch("genhs_mass") != 0) {
		genhs_mass_branch = tree->GetBranch("genhs_mass");
		if (genhs_mass_branch) {genhs_mass_branch->SetAddress(&genhs_mass_);}
	}
	genhs_id_branch = 0;
	if (tree->GetBranch("genhs_id") != 0) {
		genhs_id_branch = tree->GetBranch("genhs_id");
		if (genhs_id_branch) {genhs_id_branch->SetAddress(&genhs_id_);}
	}
	genhs__genpsidx_branch = 0;
	if (tree->GetBranch("genhs__genpsidx") != 0) {
		genhs__genpsidx_branch = tree->GetBranch("genhs__genpsidx");
		if (genhs__genpsidx_branch) {genhs__genpsidx_branch->SetAddress(&genhs__genpsidx_);}
	}
	genhs_status_branch = 0;
	if (tree->GetBranch("genhs_status") != 0) {
		genhs_status_branch = tree->GetBranch("genhs_status");
		if (genhs_status_branch) {genhs_status_branch->SetAddress(&genhs_status_);}
	}
	genhs_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genhs_fromHardProcessBeforeFSR") != 0) {
		genhs_fromHardProcessBeforeFSR_branch = tree->GetBranch("genhs_fromHardProcessBeforeFSR");
		if (genhs_fromHardProcessBeforeFSR_branch) {genhs_fromHardProcessBeforeFSR_branch->SetAddress(&genhs_fromHardProcessBeforeFSR_);}
	}
	genhs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genhs_fromHardProcessDecayed") != 0) {
		genhs_fromHardProcessDecayed_branch = tree->GetBranch("genhs_fromHardProcessDecayed");
		if (genhs_fromHardProcessDecayed_branch) {genhs_fromHardProcessDecayed_branch->SetAddress(&genhs_fromHardProcessDecayed_);}
	}
	genhs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genhs_fromHardProcessFinalState") != 0) {
		genhs_fromHardProcessFinalState_branch = tree->GetBranch("genhs_fromHardProcessFinalState");
		if (genhs_fromHardProcessFinalState_branch) {genhs_fromHardProcessFinalState_branch->SetAddress(&genhs_fromHardProcessFinalState_);}
	}
	genhs_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genhs_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genhs_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genhs_isDirectHardProcessTauDecayProductFinalState");
		if (genhs_isDirectHardProcessTauDecayProductFinalState_branch) {genhs_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genhs_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genhs_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genhs_isDirectPromptTauDecayProductFinalState") != 0) {
		genhs_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genhs_isDirectPromptTauDecayProductFinalState");
		if (genhs_isDirectPromptTauDecayProductFinalState_branch) {genhs_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genhs_isDirectPromptTauDecayProductFinalState_);}
	}
	genhs_isHardProcess_branch = 0;
	if (tree->GetBranch("genhs_isHardProcess") != 0) {
		genhs_isHardProcess_branch = tree->GetBranch("genhs_isHardProcess");
		if (genhs_isHardProcess_branch) {genhs_isHardProcess_branch->SetAddress(&genhs_isHardProcess_);}
	}
	genhs_isLastCopy_branch = 0;
	if (tree->GetBranch("genhs_isLastCopy") != 0) {
		genhs_isLastCopy_branch = tree->GetBranch("genhs_isLastCopy");
		if (genhs_isLastCopy_branch) {genhs_isLastCopy_branch->SetAddress(&genhs_isLastCopy_);}
	}
	genhs_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genhs_isLastCopyBeforeFSR") != 0) {
		genhs_isLastCopyBeforeFSR_branch = tree->GetBranch("genhs_isLastCopyBeforeFSR");
		if (genhs_isLastCopyBeforeFSR_branch) {genhs_isLastCopyBeforeFSR_branch->SetAddress(&genhs_isLastCopyBeforeFSR_);}
	}
	genhs_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genhs_isMostlyLikePythia6Status3") != 0) {
		genhs_isMostlyLikePythia6Status3_branch = tree->GetBranch("genhs_isMostlyLikePythia6Status3");
		if (genhs_isMostlyLikePythia6Status3_branch) {genhs_isMostlyLikePythia6Status3_branch->SetAddress(&genhs_isMostlyLikePythia6Status3_);}
	}
	genhs_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genhs_isPromptDecayed") != 0) {
		genhs_isPromptDecayed_branch = tree->GetBranch("genhs_isPromptDecayed");
		if (genhs_isPromptDecayed_branch) {genhs_isPromptDecayed_branch->SetAddress(&genhs_isPromptDecayed_);}
	}
	genhs_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genhs_isPromptFinalState") != 0) {
		genhs_isPromptFinalState_branch = tree->GetBranch("genhs_isPromptFinalState");
		if (genhs_isPromptFinalState_branch) {genhs_isPromptFinalState_branch->SetAddress(&genhs_isPromptFinalState_);}
	}
	genhs_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genhs_lepdaughter_id") != 0) {
		genhs_lepdaughter_id_branch = tree->GetBranch("genhs_lepdaughter_id");
		if (genhs_lepdaughter_id_branch) {genhs_lepdaughter_id_branch->SetAddress(&genhs_lepdaughter_id_);}
	}
	genhs_gentaudecay_branch = 0;
	if (tree->GetBranch("genhs_gentaudecay") != 0) {
		genhs_gentaudecay_branch = tree->GetBranch("genhs_gentaudecay");
		if (genhs_gentaudecay_branch) {genhs_gentaudecay_branch->SetAddress(&genhs_gentaudecay_);}
	}
	gen_nfromths__branch = 0;
	if (tree->GetBranch("gen_nfromths_") != 0) {
		gen_nfromths__branch = tree->GetBranch("gen_nfromths_");
		if (gen_nfromths__branch) {gen_nfromths__branch->SetAddress(&gen_nfromths__);}
	}
	genhs_mothercharge_branch = 0;
	if (tree->GetBranch("genhs_mothercharge") != 0) {
		genhs_mothercharge_branch = tree->GetBranch("genhs_mothercharge");
		if (genhs_mothercharge_branch) {genhs_mothercharge_branch->SetAddress(&genhs_mothercharge_);}
	}
	genhs_motherid_branch = 0;
	if (tree->GetBranch("genhs_motherid") != 0) {
		genhs_motherid_branch = tree->GetBranch("genhs_motherid");
		if (genhs_motherid_branch) {genhs_motherid_branch->SetAddress(&genhs_motherid_);}
	}
	genhs_motheridx_branch = 0;
	if (tree->GetBranch("genhs_motheridx") != 0) {
		genhs_motheridx_branch = tree->GetBranch("genhs_motheridx");
		if (genhs_motheridx_branch) {genhs_motheridx_branch->SetAddress(&genhs_motheridx_);}
	}
	genhs_motherstatus_branch = 0;
	if (tree->GetBranch("genhs_motherstatus") != 0) {
		genhs_motherstatus_branch = tree->GetBranch("genhs_motherstatus");
		if (genhs_motherstatus_branch) {genhs_motherstatus_branch->SetAddress(&genhs_motherstatus_);}
	}
	genhs_gmothercharge_branch = 0;
	if (tree->GetBranch("genhs_gmothercharge") != 0) {
		genhs_gmothercharge_branch = tree->GetBranch("genhs_gmothercharge");
		if (genhs_gmothercharge_branch) {genhs_gmothercharge_branch->SetAddress(&genhs_gmothercharge_);}
	}
	genhs_gmotherid_branch = 0;
	if (tree->GetBranch("genhs_gmotherid") != 0) {
		genhs_gmotherid_branch = tree->GetBranch("genhs_gmotherid");
		if (genhs_gmotherid_branch) {genhs_gmotherid_branch->SetAddress(&genhs_gmotherid_);}
	}
	genhs_gmotheridx_branch = 0;
	if (tree->GetBranch("genhs_gmotheridx") != 0) {
		genhs_gmotheridx_branch = tree->GetBranch("genhs_gmotheridx");
		if (genhs_gmotheridx_branch) {genhs_gmotheridx_branch->SetAddress(&genhs_gmotheridx_);}
	}
	genhs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genhs_gmotherstatus") != 0) {
		genhs_gmotherstatus_branch = tree->GetBranch("genhs_gmotherstatus");
		if (genhs_gmotherstatus_branch) {genhs_gmotherstatus_branch->SetAddress(&genhs_gmotherstatus_);}
	}
	genhs_simplemothercharge_branch = 0;
	if (tree->GetBranch("genhs_simplemothercharge") != 0) {
		genhs_simplemothercharge_branch = tree->GetBranch("genhs_simplemothercharge");
		if (genhs_simplemothercharge_branch) {genhs_simplemothercharge_branch->SetAddress(&genhs_simplemothercharge_);}
	}
	genhs_simplemotherid_branch = 0;
	if (tree->GetBranch("genhs_simplemotherid") != 0) {
		genhs_simplemotherid_branch = tree->GetBranch("genhs_simplemotherid");
		if (genhs_simplemotherid_branch) {genhs_simplemotherid_branch->SetAddress(&genhs_simplemotherid_);}
	}
	genhs_simplemotheridx_branch = 0;
	if (tree->GetBranch("genhs_simplemotheridx") != 0) {
		genhs_simplemotheridx_branch = tree->GetBranch("genhs_simplemotheridx");
		if (genhs_simplemotheridx_branch) {genhs_simplemotheridx_branch->SetAddress(&genhs_simplemotheridx_);}
	}
	genhs_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genhs_simplemotherstatus") != 0) {
		genhs_simplemotherstatus_branch = tree->GetBranch("genhs_simplemotherstatus");
		if (genhs_simplemotherstatus_branch) {genhs_simplemotherstatus_branch->SetAddress(&genhs_simplemotherstatus_);}
	}
	genhs_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genhs_simplegmothercharge") != 0) {
		genhs_simplegmothercharge_branch = tree->GetBranch("genhs_simplegmothercharge");
		if (genhs_simplegmothercharge_branch) {genhs_simplegmothercharge_branch->SetAddress(&genhs_simplegmothercharge_);}
	}
	genhs_simplegmotherid_branch = 0;
	if (tree->GetBranch("genhs_simplegmotherid") != 0) {
		genhs_simplegmotherid_branch = tree->GetBranch("genhs_simplegmotherid");
		if (genhs_simplegmotherid_branch) {genhs_simplegmotherid_branch->SetAddress(&genhs_simplegmotherid_);}
	}
	genhs_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genhs_simplegmotheridx") != 0) {
		genhs_simplegmotheridx_branch = tree->GetBranch("genhs_simplegmotheridx");
		if (genhs_simplegmotheridx_branch) {genhs_simplegmotheridx_branch->SetAddress(&genhs_simplegmotheridx_);}
	}
	genhs_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genhs_simplegmotherstatus") != 0) {
		genhs_simplegmotherstatus_branch = tree->GetBranch("genhs_simplegmotherstatus");
		if (genhs_simplegmotherstatus_branch) {genhs_simplegmotherstatus_branch->SetAddress(&genhs_simplegmotherstatus_);}
	}
	genlsp_isfromt_branch = 0;
	if (tree->GetBranch("genlsp_isfromt") != 0) {
		genlsp_isfromt_branch = tree->GetBranch("genlsp_isfromt");
		if (genlsp_isfromt_branch) {genlsp_isfromt_branch->SetAddress(&genlsp_isfromt_);}
	}
	genlsp_charge_branch = 0;
	if (tree->GetBranch("genlsp_charge") != 0) {
		genlsp_charge_branch = tree->GetBranch("genlsp_charge");
		if (genlsp_charge_branch) {genlsp_charge_branch->SetAddress(&genlsp_charge_);}
	}
	genlsp_iso_branch = 0;
	if (tree->GetBranch("genlsp_iso") != 0) {
		genlsp_iso_branch = tree->GetBranch("genlsp_iso");
		if (genlsp_iso_branch) {genlsp_iso_branch->SetAddress(&genlsp_iso_);}
	}
	genlsp_mass_branch = 0;
	if (tree->GetBranch("genlsp_mass") != 0) {
		genlsp_mass_branch = tree->GetBranch("genlsp_mass");
		if (genlsp_mass_branch) {genlsp_mass_branch->SetAddress(&genlsp_mass_);}
	}
	genlsp_id_branch = 0;
	if (tree->GetBranch("genlsp_id") != 0) {
		genlsp_id_branch = tree->GetBranch("genlsp_id");
		if (genlsp_id_branch) {genlsp_id_branch->SetAddress(&genlsp_id_);}
	}
	genlsp__genpsidx_branch = 0;
	if (tree->GetBranch("genlsp__genpsidx") != 0) {
		genlsp__genpsidx_branch = tree->GetBranch("genlsp__genpsidx");
		if (genlsp__genpsidx_branch) {genlsp__genpsidx_branch->SetAddress(&genlsp__genpsidx_);}
	}
	genlsp_status_branch = 0;
	if (tree->GetBranch("genlsp_status") != 0) {
		genlsp_status_branch = tree->GetBranch("genlsp_status");
		if (genlsp_status_branch) {genlsp_status_branch->SetAddress(&genlsp_status_);}
	}
	genlsp_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genlsp_fromHardProcessBeforeFSR") != 0) {
		genlsp_fromHardProcessBeforeFSR_branch = tree->GetBranch("genlsp_fromHardProcessBeforeFSR");
		if (genlsp_fromHardProcessBeforeFSR_branch) {genlsp_fromHardProcessBeforeFSR_branch->SetAddress(&genlsp_fromHardProcessBeforeFSR_);}
	}
	genlsp_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genlsp_fromHardProcessDecayed") != 0) {
		genlsp_fromHardProcessDecayed_branch = tree->GetBranch("genlsp_fromHardProcessDecayed");
		if (genlsp_fromHardProcessDecayed_branch) {genlsp_fromHardProcessDecayed_branch->SetAddress(&genlsp_fromHardProcessDecayed_);}
	}
	genlsp_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genlsp_fromHardProcessFinalState") != 0) {
		genlsp_fromHardProcessFinalState_branch = tree->GetBranch("genlsp_fromHardProcessFinalState");
		if (genlsp_fromHardProcessFinalState_branch) {genlsp_fromHardProcessFinalState_branch->SetAddress(&genlsp_fromHardProcessFinalState_);}
	}
	genlsp_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genlsp_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genlsp_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genlsp_isDirectHardProcessTauDecayProductFinalState");
		if (genlsp_isDirectHardProcessTauDecayProductFinalState_branch) {genlsp_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genlsp_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genlsp_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genlsp_isDirectPromptTauDecayProductFinalState") != 0) {
		genlsp_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genlsp_isDirectPromptTauDecayProductFinalState");
		if (genlsp_isDirectPromptTauDecayProductFinalState_branch) {genlsp_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genlsp_isDirectPromptTauDecayProductFinalState_);}
	}
	genlsp_isHardProcess_branch = 0;
	if (tree->GetBranch("genlsp_isHardProcess") != 0) {
		genlsp_isHardProcess_branch = tree->GetBranch("genlsp_isHardProcess");
		if (genlsp_isHardProcess_branch) {genlsp_isHardProcess_branch->SetAddress(&genlsp_isHardProcess_);}
	}
	genlsp_isLastCopy_branch = 0;
	if (tree->GetBranch("genlsp_isLastCopy") != 0) {
		genlsp_isLastCopy_branch = tree->GetBranch("genlsp_isLastCopy");
		if (genlsp_isLastCopy_branch) {genlsp_isLastCopy_branch->SetAddress(&genlsp_isLastCopy_);}
	}
	genlsp_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genlsp_isLastCopyBeforeFSR") != 0) {
		genlsp_isLastCopyBeforeFSR_branch = tree->GetBranch("genlsp_isLastCopyBeforeFSR");
		if (genlsp_isLastCopyBeforeFSR_branch) {genlsp_isLastCopyBeforeFSR_branch->SetAddress(&genlsp_isLastCopyBeforeFSR_);}
	}
	genlsp_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genlsp_isMostlyLikePythia6Status3") != 0) {
		genlsp_isMostlyLikePythia6Status3_branch = tree->GetBranch("genlsp_isMostlyLikePythia6Status3");
		if (genlsp_isMostlyLikePythia6Status3_branch) {genlsp_isMostlyLikePythia6Status3_branch->SetAddress(&genlsp_isMostlyLikePythia6Status3_);}
	}
	genlsp_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genlsp_isPromptDecayed") != 0) {
		genlsp_isPromptDecayed_branch = tree->GetBranch("genlsp_isPromptDecayed");
		if (genlsp_isPromptDecayed_branch) {genlsp_isPromptDecayed_branch->SetAddress(&genlsp_isPromptDecayed_);}
	}
	genlsp_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genlsp_isPromptFinalState") != 0) {
		genlsp_isPromptFinalState_branch = tree->GetBranch("genlsp_isPromptFinalState");
		if (genlsp_isPromptFinalState_branch) {genlsp_isPromptFinalState_branch->SetAddress(&genlsp_isPromptFinalState_);}
	}
	genlsp_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genlsp_lepdaughter_id") != 0) {
		genlsp_lepdaughter_id_branch = tree->GetBranch("genlsp_lepdaughter_id");
		if (genlsp_lepdaughter_id_branch) {genlsp_lepdaughter_id_branch->SetAddress(&genlsp_lepdaughter_id_);}
	}
	genlsp_gentaudecay_branch = 0;
	if (tree->GetBranch("genlsp_gentaudecay") != 0) {
		genlsp_gentaudecay_branch = tree->GetBranch("genlsp_gentaudecay");
		if (genlsp_gentaudecay_branch) {genlsp_gentaudecay_branch->SetAddress(&genlsp_gentaudecay_);}
	}
	gen_nfromtlsp__branch = 0;
	if (tree->GetBranch("gen_nfromtlsp_") != 0) {
		gen_nfromtlsp__branch = tree->GetBranch("gen_nfromtlsp_");
		if (gen_nfromtlsp__branch) {gen_nfromtlsp__branch->SetAddress(&gen_nfromtlsp__);}
	}
	genlsp_mothercharge_branch = 0;
	if (tree->GetBranch("genlsp_mothercharge") != 0) {
		genlsp_mothercharge_branch = tree->GetBranch("genlsp_mothercharge");
		if (genlsp_mothercharge_branch) {genlsp_mothercharge_branch->SetAddress(&genlsp_mothercharge_);}
	}
	genlsp_motherid_branch = 0;
	if (tree->GetBranch("genlsp_motherid") != 0) {
		genlsp_motherid_branch = tree->GetBranch("genlsp_motherid");
		if (genlsp_motherid_branch) {genlsp_motherid_branch->SetAddress(&genlsp_motherid_);}
	}
	genlsp_motheridx_branch = 0;
	if (tree->GetBranch("genlsp_motheridx") != 0) {
		genlsp_motheridx_branch = tree->GetBranch("genlsp_motheridx");
		if (genlsp_motheridx_branch) {genlsp_motheridx_branch->SetAddress(&genlsp_motheridx_);}
	}
	genlsp_motherstatus_branch = 0;
	if (tree->GetBranch("genlsp_motherstatus") != 0) {
		genlsp_motherstatus_branch = tree->GetBranch("genlsp_motherstatus");
		if (genlsp_motherstatus_branch) {genlsp_motherstatus_branch->SetAddress(&genlsp_motherstatus_);}
	}
	genlsp_gmothercharge_branch = 0;
	if (tree->GetBranch("genlsp_gmothercharge") != 0) {
		genlsp_gmothercharge_branch = tree->GetBranch("genlsp_gmothercharge");
		if (genlsp_gmothercharge_branch) {genlsp_gmothercharge_branch->SetAddress(&genlsp_gmothercharge_);}
	}
	genlsp_gmotherid_branch = 0;
	if (tree->GetBranch("genlsp_gmotherid") != 0) {
		genlsp_gmotherid_branch = tree->GetBranch("genlsp_gmotherid");
		if (genlsp_gmotherid_branch) {genlsp_gmotherid_branch->SetAddress(&genlsp_gmotherid_);}
	}
	genlsp_gmotheridx_branch = 0;
	if (tree->GetBranch("genlsp_gmotheridx") != 0) {
		genlsp_gmotheridx_branch = tree->GetBranch("genlsp_gmotheridx");
		if (genlsp_gmotheridx_branch) {genlsp_gmotheridx_branch->SetAddress(&genlsp_gmotheridx_);}
	}
	genlsp_gmotherstatus_branch = 0;
	if (tree->GetBranch("genlsp_gmotherstatus") != 0) {
		genlsp_gmotherstatus_branch = tree->GetBranch("genlsp_gmotherstatus");
		if (genlsp_gmotherstatus_branch) {genlsp_gmotherstatus_branch->SetAddress(&genlsp_gmotherstatus_);}
	}
	genlsp_simplemothercharge_branch = 0;
	if (tree->GetBranch("genlsp_simplemothercharge") != 0) {
		genlsp_simplemothercharge_branch = tree->GetBranch("genlsp_simplemothercharge");
		if (genlsp_simplemothercharge_branch) {genlsp_simplemothercharge_branch->SetAddress(&genlsp_simplemothercharge_);}
	}
	genlsp_simplemotherid_branch = 0;
	if (tree->GetBranch("genlsp_simplemotherid") != 0) {
		genlsp_simplemotherid_branch = tree->GetBranch("genlsp_simplemotherid");
		if (genlsp_simplemotherid_branch) {genlsp_simplemotherid_branch->SetAddress(&genlsp_simplemotherid_);}
	}
	genlsp_simplemotheridx_branch = 0;
	if (tree->GetBranch("genlsp_simplemotheridx") != 0) {
		genlsp_simplemotheridx_branch = tree->GetBranch("genlsp_simplemotheridx");
		if (genlsp_simplemotheridx_branch) {genlsp_simplemotheridx_branch->SetAddress(&genlsp_simplemotheridx_);}
	}
	genlsp_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genlsp_simplemotherstatus") != 0) {
		genlsp_simplemotherstatus_branch = tree->GetBranch("genlsp_simplemotherstatus");
		if (genlsp_simplemotherstatus_branch) {genlsp_simplemotherstatus_branch->SetAddress(&genlsp_simplemotherstatus_);}
	}
	genlsp_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genlsp_simplegmothercharge") != 0) {
		genlsp_simplegmothercharge_branch = tree->GetBranch("genlsp_simplegmothercharge");
		if (genlsp_simplegmothercharge_branch) {genlsp_simplegmothercharge_branch->SetAddress(&genlsp_simplegmothercharge_);}
	}
	genlsp_simplegmotherid_branch = 0;
	if (tree->GetBranch("genlsp_simplegmotherid") != 0) {
		genlsp_simplegmotherid_branch = tree->GetBranch("genlsp_simplegmotherid");
		if (genlsp_simplegmotherid_branch) {genlsp_simplegmotherid_branch->SetAddress(&genlsp_simplegmotherid_);}
	}
	genlsp_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genlsp_simplegmotheridx") != 0) {
		genlsp_simplegmotheridx_branch = tree->GetBranch("genlsp_simplegmotheridx");
		if (genlsp_simplegmotheridx_branch) {genlsp_simplegmotheridx_branch->SetAddress(&genlsp_simplegmotheridx_);}
	}
	genlsp_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genlsp_simplegmotherstatus") != 0) {
		genlsp_simplegmotherstatus_branch = tree->GetBranch("genlsp_simplegmotherstatus");
		if (genlsp_simplegmotherstatus_branch) {genlsp_simplegmotherstatus_branch->SetAddress(&genlsp_simplegmotherstatus_);}
	}
	genstop_isfromt_branch = 0;
	if (tree->GetBranch("genstop_isfromt") != 0) {
		genstop_isfromt_branch = tree->GetBranch("genstop_isfromt");
		if (genstop_isfromt_branch) {genstop_isfromt_branch->SetAddress(&genstop_isfromt_);}
	}
	genstop_charge_branch = 0;
	if (tree->GetBranch("genstop_charge") != 0) {
		genstop_charge_branch = tree->GetBranch("genstop_charge");
		if (genstop_charge_branch) {genstop_charge_branch->SetAddress(&genstop_charge_);}
	}
	genstop_iso_branch = 0;
	if (tree->GetBranch("genstop_iso") != 0) {
		genstop_iso_branch = tree->GetBranch("genstop_iso");
		if (genstop_iso_branch) {genstop_iso_branch->SetAddress(&genstop_iso_);}
	}
	genstop_mass_branch = 0;
	if (tree->GetBranch("genstop_mass") != 0) {
		genstop_mass_branch = tree->GetBranch("genstop_mass");
		if (genstop_mass_branch) {genstop_mass_branch->SetAddress(&genstop_mass_);}
	}
	genstop_id_branch = 0;
	if (tree->GetBranch("genstop_id") != 0) {
		genstop_id_branch = tree->GetBranch("genstop_id");
		if (genstop_id_branch) {genstop_id_branch->SetAddress(&genstop_id_);}
	}
	genstop__genpsidx_branch = 0;
	if (tree->GetBranch("genstop__genpsidx") != 0) {
		genstop__genpsidx_branch = tree->GetBranch("genstop__genpsidx");
		if (genstop__genpsidx_branch) {genstop__genpsidx_branch->SetAddress(&genstop__genpsidx_);}
	}
	genstop_status_branch = 0;
	if (tree->GetBranch("genstop_status") != 0) {
		genstop_status_branch = tree->GetBranch("genstop_status");
		if (genstop_status_branch) {genstop_status_branch->SetAddress(&genstop_status_);}
	}
	genstop_fromHardProcessBeforeFSR_branch = 0;
	if (tree->GetBranch("genstop_fromHardProcessBeforeFSR") != 0) {
		genstop_fromHardProcessBeforeFSR_branch = tree->GetBranch("genstop_fromHardProcessBeforeFSR");
		if (genstop_fromHardProcessBeforeFSR_branch) {genstop_fromHardProcessBeforeFSR_branch->SetAddress(&genstop_fromHardProcessBeforeFSR_);}
	}
	genstop_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genstop_fromHardProcessDecayed") != 0) {
		genstop_fromHardProcessDecayed_branch = tree->GetBranch("genstop_fromHardProcessDecayed");
		if (genstop_fromHardProcessDecayed_branch) {genstop_fromHardProcessDecayed_branch->SetAddress(&genstop_fromHardProcessDecayed_);}
	}
	genstop_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genstop_fromHardProcessFinalState") != 0) {
		genstop_fromHardProcessFinalState_branch = tree->GetBranch("genstop_fromHardProcessFinalState");
		if (genstop_fromHardProcessFinalState_branch) {genstop_fromHardProcessFinalState_branch->SetAddress(&genstop_fromHardProcessFinalState_);}
	}
	genstop_isDirectHardProcessTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genstop_isDirectHardProcessTauDecayProductFinalState") != 0) {
		genstop_isDirectHardProcessTauDecayProductFinalState_branch = tree->GetBranch("genstop_isDirectHardProcessTauDecayProductFinalState");
		if (genstop_isDirectHardProcessTauDecayProductFinalState_branch) {genstop_isDirectHardProcessTauDecayProductFinalState_branch->SetAddress(&genstop_isDirectHardProcessTauDecayProductFinalState_);}
	}
	genstop_isDirectPromptTauDecayProductFinalState_branch = 0;
	if (tree->GetBranch("genstop_isDirectPromptTauDecayProductFinalState") != 0) {
		genstop_isDirectPromptTauDecayProductFinalState_branch = tree->GetBranch("genstop_isDirectPromptTauDecayProductFinalState");
		if (genstop_isDirectPromptTauDecayProductFinalState_branch) {genstop_isDirectPromptTauDecayProductFinalState_branch->SetAddress(&genstop_isDirectPromptTauDecayProductFinalState_);}
	}
	genstop_isHardProcess_branch = 0;
	if (tree->GetBranch("genstop_isHardProcess") != 0) {
		genstop_isHardProcess_branch = tree->GetBranch("genstop_isHardProcess");
		if (genstop_isHardProcess_branch) {genstop_isHardProcess_branch->SetAddress(&genstop_isHardProcess_);}
	}
	genstop_isLastCopy_branch = 0;
	if (tree->GetBranch("genstop_isLastCopy") != 0) {
		genstop_isLastCopy_branch = tree->GetBranch("genstop_isLastCopy");
		if (genstop_isLastCopy_branch) {genstop_isLastCopy_branch->SetAddress(&genstop_isLastCopy_);}
	}
	genstop_isLastCopyBeforeFSR_branch = 0;
	if (tree->GetBranch("genstop_isLastCopyBeforeFSR") != 0) {
		genstop_isLastCopyBeforeFSR_branch = tree->GetBranch("genstop_isLastCopyBeforeFSR");
		if (genstop_isLastCopyBeforeFSR_branch) {genstop_isLastCopyBeforeFSR_branch->SetAddress(&genstop_isLastCopyBeforeFSR_);}
	}
	genstop_isMostlyLikePythia6Status3_branch = 0;
	if (tree->GetBranch("genstop_isMostlyLikePythia6Status3") != 0) {
		genstop_isMostlyLikePythia6Status3_branch = tree->GetBranch("genstop_isMostlyLikePythia6Status3");
		if (genstop_isMostlyLikePythia6Status3_branch) {genstop_isMostlyLikePythia6Status3_branch->SetAddress(&genstop_isMostlyLikePythia6Status3_);}
	}
	genstop_isPromptDecayed_branch = 0;
	if (tree->GetBranch("genstop_isPromptDecayed") != 0) {
		genstop_isPromptDecayed_branch = tree->GetBranch("genstop_isPromptDecayed");
		if (genstop_isPromptDecayed_branch) {genstop_isPromptDecayed_branch->SetAddress(&genstop_isPromptDecayed_);}
	}
	genstop_isPromptFinalState_branch = 0;
	if (tree->GetBranch("genstop_isPromptFinalState") != 0) {
		genstop_isPromptFinalState_branch = tree->GetBranch("genstop_isPromptFinalState");
		if (genstop_isPromptFinalState_branch) {genstop_isPromptFinalState_branch->SetAddress(&genstop_isPromptFinalState_);}
	}
	genstop_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genstop_lepdaughter_id") != 0) {
		genstop_lepdaughter_id_branch = tree->GetBranch("genstop_lepdaughter_id");
		if (genstop_lepdaughter_id_branch) {genstop_lepdaughter_id_branch->SetAddress(&genstop_lepdaughter_id_);}
	}
	genstop_gentaudecay_branch = 0;
	if (tree->GetBranch("genstop_gentaudecay") != 0) {
		genstop_gentaudecay_branch = tree->GetBranch("genstop_gentaudecay");
		if (genstop_gentaudecay_branch) {genstop_gentaudecay_branch->SetAddress(&genstop_gentaudecay_);}
	}
	gen_nfromtstop__branch = 0;
	if (tree->GetBranch("gen_nfromtstop_") != 0) {
		gen_nfromtstop__branch = tree->GetBranch("gen_nfromtstop_");
		if (gen_nfromtstop__branch) {gen_nfromtstop__branch->SetAddress(&gen_nfromtstop__);}
	}
	genstop_mothercharge_branch = 0;
	if (tree->GetBranch("genstop_mothercharge") != 0) {
		genstop_mothercharge_branch = tree->GetBranch("genstop_mothercharge");
		if (genstop_mothercharge_branch) {genstop_mothercharge_branch->SetAddress(&genstop_mothercharge_);}
	}
	genstop_motherid_branch = 0;
	if (tree->GetBranch("genstop_motherid") != 0) {
		genstop_motherid_branch = tree->GetBranch("genstop_motherid");
		if (genstop_motherid_branch) {genstop_motherid_branch->SetAddress(&genstop_motherid_);}
	}
	genstop_motheridx_branch = 0;
	if (tree->GetBranch("genstop_motheridx") != 0) {
		genstop_motheridx_branch = tree->GetBranch("genstop_motheridx");
		if (genstop_motheridx_branch) {genstop_motheridx_branch->SetAddress(&genstop_motheridx_);}
	}
	genstop_motherstatus_branch = 0;
	if (tree->GetBranch("genstop_motherstatus") != 0) {
		genstop_motherstatus_branch = tree->GetBranch("genstop_motherstatus");
		if (genstop_motherstatus_branch) {genstop_motherstatus_branch->SetAddress(&genstop_motherstatus_);}
	}
	genstop_gmothercharge_branch = 0;
	if (tree->GetBranch("genstop_gmothercharge") != 0) {
		genstop_gmothercharge_branch = tree->GetBranch("genstop_gmothercharge");
		if (genstop_gmothercharge_branch) {genstop_gmothercharge_branch->SetAddress(&genstop_gmothercharge_);}
	}
	genstop_gmotherid_branch = 0;
	if (tree->GetBranch("genstop_gmotherid") != 0) {
		genstop_gmotherid_branch = tree->GetBranch("genstop_gmotherid");
		if (genstop_gmotherid_branch) {genstop_gmotherid_branch->SetAddress(&genstop_gmotherid_);}
	}
	genstop_gmotheridx_branch = 0;
	if (tree->GetBranch("genstop_gmotheridx") != 0) {
		genstop_gmotheridx_branch = tree->GetBranch("genstop_gmotheridx");
		if (genstop_gmotheridx_branch) {genstop_gmotheridx_branch->SetAddress(&genstop_gmotheridx_);}
	}
	genstop_gmotherstatus_branch = 0;
	if (tree->GetBranch("genstop_gmotherstatus") != 0) {
		genstop_gmotherstatus_branch = tree->GetBranch("genstop_gmotherstatus");
		if (genstop_gmotherstatus_branch) {genstop_gmotherstatus_branch->SetAddress(&genstop_gmotherstatus_);}
	}
	genstop_simplemothercharge_branch = 0;
	if (tree->GetBranch("genstop_simplemothercharge") != 0) {
		genstop_simplemothercharge_branch = tree->GetBranch("genstop_simplemothercharge");
		if (genstop_simplemothercharge_branch) {genstop_simplemothercharge_branch->SetAddress(&genstop_simplemothercharge_);}
	}
	genstop_simplemotherid_branch = 0;
	if (tree->GetBranch("genstop_simplemotherid") != 0) {
		genstop_simplemotherid_branch = tree->GetBranch("genstop_simplemotherid");
		if (genstop_simplemotherid_branch) {genstop_simplemotherid_branch->SetAddress(&genstop_simplemotherid_);}
	}
	genstop_simplemotheridx_branch = 0;
	if (tree->GetBranch("genstop_simplemotheridx") != 0) {
		genstop_simplemotheridx_branch = tree->GetBranch("genstop_simplemotheridx");
		if (genstop_simplemotheridx_branch) {genstop_simplemotheridx_branch->SetAddress(&genstop_simplemotheridx_);}
	}
	genstop_simplemotherstatus_branch = 0;
	if (tree->GetBranch("genstop_simplemotherstatus") != 0) {
		genstop_simplemotherstatus_branch = tree->GetBranch("genstop_simplemotherstatus");
		if (genstop_simplemotherstatus_branch) {genstop_simplemotherstatus_branch->SetAddress(&genstop_simplemotherstatus_);}
	}
	genstop_simplegmothercharge_branch = 0;
	if (tree->GetBranch("genstop_simplegmothercharge") != 0) {
		genstop_simplegmothercharge_branch = tree->GetBranch("genstop_simplegmothercharge");
		if (genstop_simplegmothercharge_branch) {genstop_simplegmothercharge_branch->SetAddress(&genstop_simplegmothercharge_);}
	}
	genstop_simplegmotherid_branch = 0;
	if (tree->GetBranch("genstop_simplegmotherid") != 0) {
		genstop_simplegmotherid_branch = tree->GetBranch("genstop_simplegmotherid");
		if (genstop_simplegmotherid_branch) {genstop_simplegmotherid_branch->SetAddress(&genstop_simplegmotherid_);}
	}
	genstop_simplegmotheridx_branch = 0;
	if (tree->GetBranch("genstop_simplegmotheridx") != 0) {
		genstop_simplegmotheridx_branch = tree->GetBranch("genstop_simplegmotheridx");
		if (genstop_simplegmotheridx_branch) {genstop_simplegmotheridx_branch->SetAddress(&genstop_simplegmotheridx_);}
	}
	genstop_simplegmotherstatus_branch = 0;
	if (tree->GetBranch("genstop_simplegmotherstatus") != 0) {
		genstop_simplegmotherstatus_branch = tree->GetBranch("genstop_simplegmotherstatus");
		if (genstop_simplegmotherstatus_branch) {genstop_simplegmotherstatus_branch->SetAddress(&genstop_simplegmotherstatus_);}
	}
  tree->SetMakeClass(0);
}
void GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		run_isLoaded = false;
		ls_isLoaded = false;
		evt_isLoaded = false;
		nvtxs_isLoaded = false;
		firstGoodVtxIdx_isLoaded = false;
		firstVtx_isfake_isLoaded = false;
		firstVtx_ndof_isLoaded = false;
		firstVtx_posRho_isLoaded = false;
		firstVtx_posZ_isLoaded = false;
		firstVtx_posp4_isLoaded = false;
		pu_nvtxs_isLoaded = false;
		pfmet_isLoaded = false;
		pfmet_phi_isLoaded = false;
		calomet_isLoaded = false;
		calomet_phi_isLoaded = false;
		filt_cscbeamhalo_isLoaded = false;
		filt_ecallaser_isLoaded = false;
		filt_ecaltp_isLoaded = false;
		filt_eebadsc_isLoaded = false;
		filt_goodvtx_isLoaded = false;
		filt_hbhenoise_isLoaded = false;
		filt_hcallaser_isLoaded = false;
		filt_met_isLoaded = false;
		filt_trkfail_isLoaded = false;
		filt_trkPOG_isLoaded = false;
		filt_trkPOG_tmc_isLoaded = false;
		filt_trkPOG_tms_isLoaded = false;
		filt_eff_isLoaded = false;
		scale1fb_isLoaded = false;
		xsec_isLoaded = false;
		kfactor_isLoaded = false;
		pu_ntrue_isLoaded = false;
		ngoodleps_isLoaded = false;
		nvetoleps_isLoaded = false;
		is_data_isLoaded = false;
		dataset_isLoaded = false;
		filename_isLoaded = false;
		cms3tag_isLoaded = false;
		nEvents_isLoaded = false;
		nEvents_goodvtx_isLoaded = false;
		nEvents_MET30_isLoaded = false;
		nEvents_1goodlep_isLoaded = false;
		nEvents_2goodjets_isLoaded = false;
		genlepsfromtop_isLoaded = false;
		MT2W_isLoaded = false;
		MT2W_lep2_isLoaded = false;
		mindphi_met_j1_j2_isLoaded = false;
		mt_met_lep_isLoaded = false;
		mt_met_lep2_isLoaded = false;
		dR_lep_leadb_isLoaded = false;
		dR_lep2_leadb_isLoaded = false;
		hadronic_top_chi2_isLoaded = false;
		dphi_Wlep_isLoaded = false;
		MET_over_sqrtHT_isLoaded = false;
		ak4pfjets_rho_isLoaded = false;
		sparms_comment_isLoaded = false;
		sparms_names_isLoaded = false;
		sparms_filterEfficiency_isLoaded = false;
		sparms_pdfScale_isLoaded = false;
		sparms_pdfWeight1_isLoaded = false;
		sparms_pdfWeight2_isLoaded = false;
		sparms_weight_isLoaded = false;
		sparms_xsec_isLoaded = false;
		sparms_values_isLoaded = false;
		sparms_subProcessId_isLoaded = false;
		mass_lsp_isLoaded = false;
		mass_chargino_isLoaded = false;
		mass_stop_isLoaded = false;
		genmet_isLoaded = false;
		genmet_phi_isLoaded = false;
		PassTrackVeto_isLoaded = false;
		PassTrackVeto_v2_isLoaded = false;
		PassTrackVeto_v3_isLoaded = false;
		PassTauVeto_isLoaded = false;
		EA_all_rho_isLoaded = false;
		EA_allcalo_rho_isLoaded = false;
		EA_centralcalo_rho_isLoaded = false;
		EA_centralchargedpileup_rho_isLoaded = false;
		EA_centralneutral_rho_isLoaded = false;
		topness_isLoaded = false;
		topness_lep2_isLoaded = false;
		topnessMod_isLoaded = false;
		topnessMod_lep2_isLoaded = false;
		MT2_lb_b_isLoaded = false;
		MT2_lb_b_lep2_isLoaded = false;
		MT2_lb_b_mass_isLoaded = false;
		MT2_lb_b_mass_lep2_isLoaded = false;
		MT2_lb_bqq_isLoaded = false;
		MT2_lb_bqq_lep2_isLoaded = false;
		MT2_lb_bqq_mass_isLoaded = false;
		MT2_lb_bqq_mass_lep2_isLoaded = false;
		Mlb_closestb_isLoaded = false;
		Mlb_lead_bdiscr_isLoaded = false;
		Mlb_closestb_lep2_isLoaded = false;
		Mlb_lead_bdiscr_lep2_isLoaded = false;
		Mjjj_isLoaded = false;
		Mjjj_lep2_isLoaded = false;
		HLT_SingleEl_isLoaded = false;
		HLT_SingleMu_isLoaded = false;
		HLT_MET170_isLoaded = false;
		HLT_MET120Btag_isLoaded = false;
		HLT_MET120Mu5_isLoaded = false;
		HLT_HT350MET120_isLoaded = false;
		HLT_DiEl_isLoaded = false;
		HLT_DiMu_isLoaded = false;
		HLT_Mu8El17_isLoaded = false;
		HLT_Mu8El23_isLoaded = false;
		HLT_Mu17El12_isLoaded = false;
		HLT_Mu23El12_isLoaded = false;
		HLT_SingleEl27_isLoaded = false;
		HLT_SingleEl27Tight_isLoaded = false;
		HLT_SingleElTight_isLoaded = false;
		HLT_SingleElHT200_isLoaded = false;
		HLT_SingleMuNoEta_isLoaded = false;
		HLT_SingleMuNoIso_isLoaded = false;
		HLT_SingleMuNoIsoNoEta_isLoaded = false;
		HLT_Mu6HT200MET100_isLoaded = false;
		HLT_HT350MET100_isLoaded = false;
		HLT_SingleMu17_isLoaded = false;
		HLT_SingleMu20_isLoaded = false;
		HLT_SingleMu24_isLoaded = false;
		HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded = false;
		HLT_MET90_MHT90_IDTight_isLoaded = false;
		HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded = false;
		pu_weight_isLoaded = false;
		lep_sf_isLoaded = false;
		btag_sf_isLoaded = false;
		HLT_SingleEl_eff_isLoaded = false;
		HLT_SingleMu_eff_isLoaded = false;
		lep1_is_mu_isLoaded = false;
		lep1_is_el_isLoaded = false;
		lep1_charge_isLoaded = false;
		lep1_pdgid_isLoaded = false;
		lep1_type_isLoaded = false;
		lep1_production_type_isLoaded = false;
		lep1_d0_isLoaded = false;
		lep1_d0err_isLoaded = false;
		lep1_dz_isLoaded = false;
		lep1_dzerr_isLoaded = false;
		lep1_sigmaIEtaEta_fill5x5_isLoaded = false;
		lep1_dEtaIn_isLoaded = false;
		lep1_dPhiIn_isLoaded = false;
		lep1_hOverE_isLoaded = false;
		lep1_ooEmooP_isLoaded = false;
		lep1_expectedMissingInnerHits_isLoaded = false;
		lep1_conversionVeto_isLoaded = false;
		lep1_etaSC_isLoaded = false;
		lep1_ChiSqr_isLoaded = false;
		lep1_chiso_isLoaded = false;
		lep1_nhiso_isLoaded = false;
		lep1_emiso_isLoaded = false;
		lep1_deltaBeta_isLoaded = false;
		lep1_relIso03DB_isLoaded = false;
		lep1_relIso03EA_isLoaded = false;
		lep1_relIso04DB_isLoaded = false;
		lep1_miniRelIsoDB_isLoaded = false;
		lep1_miniRelIsoEA_isLoaded = false;
		lep1_MiniIso_isLoaded = false;
		lep1_mcid_isLoaded = false;
		lep1_mcstatus_isLoaded = false;
		lep1_mc3dr_isLoaded = false;
		lep1_mc3id_isLoaded = false;
		lep1_mc3idx_isLoaded = false;
		lep1_mc3motherid_isLoaded = false;
		lep1_mc3motheridx_isLoaded = false;
		lep1_is_eleid_loose_isLoaded = false;
		lep1_is_eleid_medium_isLoaded = false;
		lep1_is_eleid_tight_isLoaded = false;
		lep1_is_phys14_loose_noIso_isLoaded = false;
		lep1_is_phys14_medium_noIso_isLoaded = false;
		lep1_is_phys14_tight_noIso_isLoaded = false;
		lep1_eoverpin_isLoaded = false;
		lep1_is_muoid_loose_isLoaded = false;
		lep1_is_muoid_medium_isLoaded = false;
		lep1_is_muoid_tight_isLoaded = false;
		lep1_ip3d_isLoaded = false;
		lep1_ip3derr_isLoaded = false;
		lep1_is_pfmu_isLoaded = false;
		lep1_passMediumID_isLoaded = false;
		lep1_passVeto_isLoaded = false;
		lep1_p4_isLoaded = false;
		lep1_mcp4_isLoaded = false;
		lep1_pt_isLoaded = false;
		lep1_eta_isLoaded = false;
		lep1_phi_isLoaded = false;
		lep1_mass_isLoaded = false;
		lep2_is_mu_isLoaded = false;
		lep2_is_el_isLoaded = false;
		lep2_charge_isLoaded = false;
		lep2_pdgid_isLoaded = false;
		lep2_type_isLoaded = false;
		lep2_production_type_isLoaded = false;
		lep2_d0_isLoaded = false;
		lep2_d0err_isLoaded = false;
		lep2_dz_isLoaded = false;
		lep2_dzerr_isLoaded = false;
		lep2_sigmaIEtaEta_fill5x5_isLoaded = false;
		lep2_dEtaIn_isLoaded = false;
		lep2_dPhiIn_isLoaded = false;
		lep2_hOverE_isLoaded = false;
		lep2_ooEmooP_isLoaded = false;
		lep2_expectedMissingInnerHits_isLoaded = false;
		lep2_conversionVeto_isLoaded = false;
		lep2_etaSC_isLoaded = false;
		lep2_ChiSqr_isLoaded = false;
		lep2_chiso_isLoaded = false;
		lep2_nhiso_isLoaded = false;
		lep2_emiso_isLoaded = false;
		lep2_deltaBeta_isLoaded = false;
		lep2_relIso03DB_isLoaded = false;
		lep2_relIso03EA_isLoaded = false;
		lep2_relIso04DB_isLoaded = false;
		lep2_miniRelIsoDB_isLoaded = false;
		lep2_miniRelIsoEA_isLoaded = false;
		lep2_MiniIso_isLoaded = false;
		lep2_mcid_isLoaded = false;
		lep2_mcstatus_isLoaded = false;
		lep2_mc3dr_isLoaded = false;
		lep2_mc3id_isLoaded = false;
		lep2_mc3idx_isLoaded = false;
		lep2_mc3motherid_isLoaded = false;
		lep2_mc3motheridx_isLoaded = false;
		lep2_is_eleid_loose_isLoaded = false;
		lep2_is_eleid_medium_isLoaded = false;
		lep2_is_eleid_tight_isLoaded = false;
		lep2_is_phys14_loose_noIso_isLoaded = false;
		lep2_is_phys14_medium_noIso_isLoaded = false;
		lep2_is_phys14_tight_noIso_isLoaded = false;
		lep2_eoverpin_isLoaded = false;
		lep2_is_muoid_loose_isLoaded = false;
		lep2_is_muoid_medium_isLoaded = false;
		lep2_is_muoid_tight_isLoaded = false;
		lep2_ip3d_isLoaded = false;
		lep2_ip3derr_isLoaded = false;
		lep2_is_pfmu_isLoaded = false;
		lep2_passMediumID_isLoaded = false;
		lep2_passVeto_isLoaded = false;
		lep2_p4_isLoaded = false;
		lep2_mcp4_isLoaded = false;
		lep2_pt_isLoaded = false;
		lep2_eta_isLoaded = false;
		lep2_phi_isLoaded = false;
		lep2_mass_isLoaded = false;
		nGoodGenJets_isLoaded = false;
		ngoodjets_isLoaded = false;
		nfailjets_isLoaded = false;
		ak8GoodPFJets_isLoaded = false;
		ngoodbtags_isLoaded = false;
		ak4_HT_isLoaded = false;
		ak4_htssm_isLoaded = false;
		ak4_htosm_isLoaded = false;
		ak4_htratiom_isLoaded = false;
		dphi_ak4pfjet_met_isLoaded = false;
		ak4pfjets_p4_isLoaded = false;
		ak4pfjets_pt_isLoaded = false;
		ak4pfjets_eta_isLoaded = false;
		ak4pfjets_phi_isLoaded = false;
		ak4pfjets_mass_isLoaded = false;
		ak4pfjets_passMEDbtag_isLoaded = false;
		ak4pfjets_qg_disc_isLoaded = false;
		ak4pfjets_CSV_isLoaded = false;
		ak4pfjets_puid_isLoaded = false;
		ak4pfjets_parton_flavor_isLoaded = false;
		ak4pfjets_loose_puid_isLoaded = false;
		ak4pfjets_loose_pfid_isLoaded = false;
		ak4pfjets_medium_pfid_isLoaded = false;
		ak4pfjets_tight_pfid_isLoaded = false;
		ak4pfjets_MEDbjet_pt_isLoaded = false;
		ak4pfjets_leadMEDbjet_pt_isLoaded = false;
		ak4pfjets_leadMEDbjet_p4_isLoaded = false;
		ak4pfjets_leadbtag_p4_isLoaded = false;
		ak4pfjets_chf_isLoaded = false;
		ak4pfjets_nhf_isLoaded = false;
		ak4pfjets_cef_isLoaded = false;
		ak4pfjets_nef_isLoaded = false;
		ak4pfjets_muf_isLoaded = false;
		ak4pfjets_cm_isLoaded = false;
		ak4pfjets_nm_isLoaded = false;
		ak4pfjets_mc3dr_isLoaded = false;
		ak4pfjets_mc3id_isLoaded = false;
		ak4pfjets_mc3idx_isLoaded = false;
		ak4pfjets_mcmotherid_isLoaded = false;
		ak4pfjet_overlep1_p4_isLoaded = false;
		ak4pfjet_overlep1_CSV_isLoaded = false;
		ak4pfjet_overlep1_pu_id_isLoaded = false;
		ak4pfjet_overlep1_chf_isLoaded = false;
		ak4pfjet_overlep1_nhf_isLoaded = false;
		ak4pfjet_overlep1_cef_isLoaded = false;
		ak4pfjet_overlep1_nef_isLoaded = false;
		ak4pfjet_overlep1_muf_isLoaded = false;
		ak4pfjet_overlep1_cm_isLoaded = false;
		ak4pfjet_overlep1_nm_isLoaded = false;
		ak4pfjet_overlep2_p4_isLoaded = false;
		ak4pfjet_overlep2_CSV_isLoaded = false;
		ak4pfjet_overlep2_pu_id_isLoaded = false;
		ak4pfjet_overlep2_chf_isLoaded = false;
		ak4pfjet_overlep2_nhf_isLoaded = false;
		ak4pfjet_overlep2_cef_isLoaded = false;
		ak4pfjet_overlep2_nef_isLoaded = false;
		ak4pfjet_overlep2_muf_isLoaded = false;
		ak4pfjet_overlep2_cm_isLoaded = false;
		ak4pfjet_overlep2_nm_isLoaded = false;
		ak8pfjets_p4_isLoaded = false;
		ak8pfjets_tau1_isLoaded = false;
		ak8pfjets_tau2_isLoaded = false;
		ak8pfjets_tau3_isLoaded = false;
		ak8pfjets_top_mass_isLoaded = false;
		ak8pfjets_pruned_mass_isLoaded = false;
		ak8pfjets_trimmed_mass_isLoaded = false;
		ak8pfjets_filtered_mass_isLoaded = false;
		ak8pfjets_pu_id_isLoaded = false;
		ak8pfjets_parton_flavor_isLoaded = false;
		ak4genjets_p4_isLoaded = false;
		tau_IDnames_isLoaded = false;
		tau_leadtrack_p4_isLoaded = false;
		tau_leadneutral_p4_isLoaded = false;
		tau_p4_isLoaded = false;
		tau_isocand_p4_isLoaded = false;
		tau_sigcand_p4_isLoaded = false;
		tau_mass_isLoaded = false;
		tau_ID_isLoaded = false;
		tau_passID_isLoaded = false;
		tau_charge_isLoaded = false;
		ngoodtaus_isLoaded = false;
		tau_againstMuonTight_isLoaded = false;
		tau_againstElectronLoose_isLoaded = false;
		tau_isVetoTau_isLoaded = false;
		isoTracks_p4_isLoaded = false;
		isoTracks_charge_isLoaded = false;
		isoTracks_absIso_isLoaded = false;
		isoTracks_dz_isLoaded = false;
		isoTracks_pdgId_isLoaded = false;
		isoTracks_selectedidx_isLoaded = false;
		isoTracks_nselected_isLoaded = false;
		isoTracks_isVetoTrack_isLoaded = false;
		isoTracks_isVetoTrack_v2_isLoaded = false;
		isoTracks_isVetoTrack_v3_isLoaded = false;
		genels_isfromt_isLoaded = false;
		genels_p4_isLoaded = false;
		genels_charge_isLoaded = false;
		genels_iso_isLoaded = false;
		genels_mass_isLoaded = false;
		genels_id_isLoaded = false;
		genels__genpsidx_isLoaded = false;
		genels_status_isLoaded = false;
		genels_fromHardProcessBeforeFSR_isLoaded = false;
		genels_fromHardProcessDecayed_isLoaded = false;
		genels_fromHardProcessFinalState_isLoaded = false;
		genels_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genels_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genels_isHardProcess_isLoaded = false;
		genels_isLastCopy_isLoaded = false;
		genels_isLastCopyBeforeFSR_isLoaded = false;
		genels_isMostlyLikePythia6Status3_isLoaded = false;
		genels_isPromptDecayed_isLoaded = false;
		genels_isPromptFinalState_isLoaded = false;
		genels_lepdaughter_id_isLoaded = false;
		genels_gentaudecay_isLoaded = false;
		gen_nfromtels__isLoaded = false;
		genels_motherp4_isLoaded = false;
		genels_mothercharge_isLoaded = false;
		genels_motherid_isLoaded = false;
		genels_motheridx_isLoaded = false;
		genels_motherstatus_isLoaded = false;
		genels_gmotherp4_isLoaded = false;
		genels_gmothercharge_isLoaded = false;
		genels_gmotherid_isLoaded = false;
		genels_gmotheridx_isLoaded = false;
		genels_gmotherstatus_isLoaded = false;
		genels_simplemotherp4_isLoaded = false;
		genels_simplemothercharge_isLoaded = false;
		genels_simplemotherid_isLoaded = false;
		genels_simplemotheridx_isLoaded = false;
		genels_simplemotherstatus_isLoaded = false;
		genels_simplegmotherp4_isLoaded = false;
		genels_simplegmothercharge_isLoaded = false;
		genels_simplegmotherid_isLoaded = false;
		genels_simplegmotheridx_isLoaded = false;
		genels_simplegmotherstatus_isLoaded = false;
		genmus_isfromt_isLoaded = false;
		genmus_p4_isLoaded = false;
		genmus_charge_isLoaded = false;
		genmus_iso_isLoaded = false;
		genmus_mass_isLoaded = false;
		genmus_id_isLoaded = false;
		genmus__genpsidx_isLoaded = false;
		genmus_status_isLoaded = false;
		genmus_fromHardProcessBeforeFSR_isLoaded = false;
		genmus_fromHardProcessDecayed_isLoaded = false;
		genmus_fromHardProcessFinalState_isLoaded = false;
		genmus_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genmus_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genmus_isHardProcess_isLoaded = false;
		genmus_isLastCopy_isLoaded = false;
		genmus_isLastCopyBeforeFSR_isLoaded = false;
		genmus_isMostlyLikePythia6Status3_isLoaded = false;
		genmus_isPromptDecayed_isLoaded = false;
		genmus_isPromptFinalState_isLoaded = false;
		genmus_lepdaughter_id_isLoaded = false;
		genmus_gentaudecay_isLoaded = false;
		gen_nfromtmus__isLoaded = false;
		genmus_motherp4_isLoaded = false;
		genmus_mothercharge_isLoaded = false;
		genmus_motherid_isLoaded = false;
		genmus_motheridx_isLoaded = false;
		genmus_motherstatus_isLoaded = false;
		genmus_gmotherp4_isLoaded = false;
		genmus_gmothercharge_isLoaded = false;
		genmus_gmotherid_isLoaded = false;
		genmus_gmotheridx_isLoaded = false;
		genmus_gmotherstatus_isLoaded = false;
		genmus_simplemotherp4_isLoaded = false;
		genmus_simplemothercharge_isLoaded = false;
		genmus_simplemotherid_isLoaded = false;
		genmus_simplemotheridx_isLoaded = false;
		genmus_simplemotherstatus_isLoaded = false;
		genmus_simplegmotherp4_isLoaded = false;
		genmus_simplegmothercharge_isLoaded = false;
		genmus_simplegmotherid_isLoaded = false;
		genmus_simplegmotheridx_isLoaded = false;
		genmus_simplegmotherstatus_isLoaded = false;
		gentaus_isfromt_isLoaded = false;
		gentaus_p4_isLoaded = false;
		gentaus_charge_isLoaded = false;
		gentaus_iso_isLoaded = false;
		gentaus_mass_isLoaded = false;
		gentaus_id_isLoaded = false;
		gentaus__genpsidx_isLoaded = false;
		gentaus_status_isLoaded = false;
		gentaus_fromHardProcessBeforeFSR_isLoaded = false;
		gentaus_fromHardProcessDecayed_isLoaded = false;
		gentaus_fromHardProcessFinalState_isLoaded = false;
		gentaus_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gentaus_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gentaus_isHardProcess_isLoaded = false;
		gentaus_isLastCopy_isLoaded = false;
		gentaus_isLastCopyBeforeFSR_isLoaded = false;
		gentaus_isMostlyLikePythia6Status3_isLoaded = false;
		gentaus_isPromptDecayed_isLoaded = false;
		gentaus_isPromptFinalState_isLoaded = false;
		gentaus_lepdaughter_id_isLoaded = false;
		gentaus_gentaudecay_isLoaded = false;
		gen_nfromttaus__isLoaded = false;
		gentaus_motherp4_isLoaded = false;
		gentaus_mothercharge_isLoaded = false;
		gentaus_motherid_isLoaded = false;
		gentaus_motheridx_isLoaded = false;
		gentaus_motherstatus_isLoaded = false;
		gentaus_gmotherp4_isLoaded = false;
		gentaus_gmothercharge_isLoaded = false;
		gentaus_gmotherid_isLoaded = false;
		gentaus_gmotheridx_isLoaded = false;
		gentaus_gmotherstatus_isLoaded = false;
		gentaus_simplemotherp4_isLoaded = false;
		gentaus_simplemothercharge_isLoaded = false;
		gentaus_simplemotherid_isLoaded = false;
		gentaus_simplemotheridx_isLoaded = false;
		gentaus_simplemotherstatus_isLoaded = false;
		gentaus_simplegmotherp4_isLoaded = false;
		gentaus_simplegmothercharge_isLoaded = false;
		gentaus_simplegmotherid_isLoaded = false;
		gentaus_simplegmotheridx_isLoaded = false;
		gentaus_simplegmotherstatus_isLoaded = false;
		gennuels_isfromt_isLoaded = false;
		gennuels_p4_isLoaded = false;
		gennuels_charge_isLoaded = false;
		gennuels_iso_isLoaded = false;
		gennuels_mass_isLoaded = false;
		gennuels_id_isLoaded = false;
		gennuels__genpsidx_isLoaded = false;
		gennuels_status_isLoaded = false;
		gennuels_fromHardProcessBeforeFSR_isLoaded = false;
		gennuels_fromHardProcessDecayed_isLoaded = false;
		gennuels_fromHardProcessFinalState_isLoaded = false;
		gennuels_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gennuels_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gennuels_isHardProcess_isLoaded = false;
		gennuels_isLastCopy_isLoaded = false;
		gennuels_isLastCopyBeforeFSR_isLoaded = false;
		gennuels_isMostlyLikePythia6Status3_isLoaded = false;
		gennuels_isPromptDecayed_isLoaded = false;
		gennuels_isPromptFinalState_isLoaded = false;
		gennuels_lepdaughter_id_isLoaded = false;
		gennuels_gentaudecay_isLoaded = false;
		gen_nfromtnuels__isLoaded = false;
		gennuels_motherp4_isLoaded = false;
		gennuels_mothercharge_isLoaded = false;
		gennuels_motherid_isLoaded = false;
		gennuels_motheridx_isLoaded = false;
		gennuels_motherstatus_isLoaded = false;
		gennuels_gmotherp4_isLoaded = false;
		gennuels_gmothercharge_isLoaded = false;
		gennuels_gmotherid_isLoaded = false;
		gennuels_gmotheridx_isLoaded = false;
		gennuels_gmotherstatus_isLoaded = false;
		gennuels_simplemotherp4_isLoaded = false;
		gennuels_simplemothercharge_isLoaded = false;
		gennuels_simplemotherid_isLoaded = false;
		gennuels_simplemotheridx_isLoaded = false;
		gennuels_simplemotherstatus_isLoaded = false;
		gennuels_simplegmotherp4_isLoaded = false;
		gennuels_simplegmothercharge_isLoaded = false;
		gennuels_simplegmotherid_isLoaded = false;
		gennuels_simplegmotheridx_isLoaded = false;
		gennuels_simplegmotherstatus_isLoaded = false;
		gennumus_isfromt_isLoaded = false;
		gennumus_p4_isLoaded = false;
		gennumus_charge_isLoaded = false;
		gennumus_iso_isLoaded = false;
		gennumus_mass_isLoaded = false;
		gennumus_id_isLoaded = false;
		gennumus__genpsidx_isLoaded = false;
		gennumus_status_isLoaded = false;
		gennumus_fromHardProcessBeforeFSR_isLoaded = false;
		gennumus_fromHardProcessDecayed_isLoaded = false;
		gennumus_fromHardProcessFinalState_isLoaded = false;
		gennumus_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gennumus_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gennumus_isHardProcess_isLoaded = false;
		gennumus_isLastCopy_isLoaded = false;
		gennumus_isLastCopyBeforeFSR_isLoaded = false;
		gennumus_isMostlyLikePythia6Status3_isLoaded = false;
		gennumus_isPromptDecayed_isLoaded = false;
		gennumus_isPromptFinalState_isLoaded = false;
		gennumus_lepdaughter_id_isLoaded = false;
		gennumus_gentaudecay_isLoaded = false;
		gen_nfromtnumus__isLoaded = false;
		gennumus_motherp4_isLoaded = false;
		gennumus_mothercharge_isLoaded = false;
		gennumus_motherid_isLoaded = false;
		gennumus_motheridx_isLoaded = false;
		gennumus_motherstatus_isLoaded = false;
		gennumus_gmotherp4_isLoaded = false;
		gennumus_gmothercharge_isLoaded = false;
		gennumus_gmotherid_isLoaded = false;
		gennumus_gmotheridx_isLoaded = false;
		gennumus_gmotherstatus_isLoaded = false;
		gennumus_simplemotherp4_isLoaded = false;
		gennumus_simplemothercharge_isLoaded = false;
		gennumus_simplemotherid_isLoaded = false;
		gennumus_simplemotheridx_isLoaded = false;
		gennumus_simplemotherstatus_isLoaded = false;
		gennumus_simplegmotherp4_isLoaded = false;
		gennumus_simplegmothercharge_isLoaded = false;
		gennumus_simplegmotherid_isLoaded = false;
		gennumus_simplegmotheridx_isLoaded = false;
		gennumus_simplegmotherstatus_isLoaded = false;
		gennutaus_isfromt_isLoaded = false;
		gennutaus_p4_isLoaded = false;
		gennutaus_charge_isLoaded = false;
		gennutaus_iso_isLoaded = false;
		gennutaus_mass_isLoaded = false;
		gennutaus_id_isLoaded = false;
		gennutaus__genpsidx_isLoaded = false;
		gennutaus_status_isLoaded = false;
		gennutaus_fromHardProcessBeforeFSR_isLoaded = false;
		gennutaus_fromHardProcessDecayed_isLoaded = false;
		gennutaus_fromHardProcessFinalState_isLoaded = false;
		gennutaus_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gennutaus_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gennutaus_isHardProcess_isLoaded = false;
		gennutaus_isLastCopy_isLoaded = false;
		gennutaus_isLastCopyBeforeFSR_isLoaded = false;
		gennutaus_isMostlyLikePythia6Status3_isLoaded = false;
		gennutaus_isPromptDecayed_isLoaded = false;
		gennutaus_isPromptFinalState_isLoaded = false;
		gennutaus_lepdaughter_id_isLoaded = false;
		gennutaus_gentaudecay_isLoaded = false;
		gen_nfromtnutaus__isLoaded = false;
		gennutaus_motherp4_isLoaded = false;
		gennutaus_mothercharge_isLoaded = false;
		gennutaus_motherid_isLoaded = false;
		gennutaus_motheridx_isLoaded = false;
		gennutaus_motherstatus_isLoaded = false;
		gennutaus_gmotherp4_isLoaded = false;
		gennutaus_gmothercharge_isLoaded = false;
		gennutaus_gmotherid_isLoaded = false;
		gennutaus_gmotheridx_isLoaded = false;
		gennutaus_gmotherstatus_isLoaded = false;
		gennutaus_simplemotherp4_isLoaded = false;
		gennutaus_simplemothercharge_isLoaded = false;
		gennutaus_simplemotherid_isLoaded = false;
		gennutaus_simplemotheridx_isLoaded = false;
		gennutaus_simplemotherstatus_isLoaded = false;
		gennutaus_simplegmotherp4_isLoaded = false;
		gennutaus_simplegmothercharge_isLoaded = false;
		gennutaus_simplegmotherid_isLoaded = false;
		gennutaus_simplegmotheridx_isLoaded = false;
		gennutaus_simplegmotherstatus_isLoaded = false;
		gents_isfromt_isLoaded = false;
		gents_p4_isLoaded = false;
		gents_charge_isLoaded = false;
		gents_iso_isLoaded = false;
		gents_mass_isLoaded = false;
		gents_id_isLoaded = false;
		gents__genpsidx_isLoaded = false;
		gents_status_isLoaded = false;
		gents_fromHardProcessBeforeFSR_isLoaded = false;
		gents_fromHardProcessDecayed_isLoaded = false;
		gents_fromHardProcessFinalState_isLoaded = false;
		gents_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gents_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gents_isHardProcess_isLoaded = false;
		gents_isLastCopy_isLoaded = false;
		gents_isLastCopyBeforeFSR_isLoaded = false;
		gents_isMostlyLikePythia6Status3_isLoaded = false;
		gents_isPromptDecayed_isLoaded = false;
		gents_isPromptFinalState_isLoaded = false;
		gents_lepdaughter_id_isLoaded = false;
		gents_gentaudecay_isLoaded = false;
		gen_nfromtts__isLoaded = false;
		gents_motherp4_isLoaded = false;
		gents_mothercharge_isLoaded = false;
		gents_motherid_isLoaded = false;
		gents_motheridx_isLoaded = false;
		gents_motherstatus_isLoaded = false;
		gents_gmotherp4_isLoaded = false;
		gents_gmothercharge_isLoaded = false;
		gents_gmotherid_isLoaded = false;
		gents_gmotheridx_isLoaded = false;
		gents_gmotherstatus_isLoaded = false;
		gents_simplemotherp4_isLoaded = false;
		gents_simplemothercharge_isLoaded = false;
		gents_simplemotherid_isLoaded = false;
		gents_simplemotheridx_isLoaded = false;
		gents_simplemotherstatus_isLoaded = false;
		gents_simplegmotherp4_isLoaded = false;
		gents_simplegmothercharge_isLoaded = false;
		gents_simplegmotherid_isLoaded = false;
		gents_simplegmotheridx_isLoaded = false;
		gents_simplegmotherstatus_isLoaded = false;
		genbs_isfromt_isLoaded = false;
		genbs_p4_isLoaded = false;
		genbs_charge_isLoaded = false;
		genbs_iso_isLoaded = false;
		genbs_mass_isLoaded = false;
		genbs_id_isLoaded = false;
		genbs__genpsidx_isLoaded = false;
		genbs_status_isLoaded = false;
		genbs_fromHardProcessBeforeFSR_isLoaded = false;
		genbs_fromHardProcessDecayed_isLoaded = false;
		genbs_fromHardProcessFinalState_isLoaded = false;
		genbs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genbs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genbs_isHardProcess_isLoaded = false;
		genbs_isLastCopy_isLoaded = false;
		genbs_isLastCopyBeforeFSR_isLoaded = false;
		genbs_isMostlyLikePythia6Status3_isLoaded = false;
		genbs_isPromptDecayed_isLoaded = false;
		genbs_isPromptFinalState_isLoaded = false;
		genbs_lepdaughter_id_isLoaded = false;
		genbs_gentaudecay_isLoaded = false;
		gen_nfromtbs__isLoaded = false;
		genbs_motherp4_isLoaded = false;
		genbs_mothercharge_isLoaded = false;
		genbs_motherid_isLoaded = false;
		genbs_motheridx_isLoaded = false;
		genbs_motherstatus_isLoaded = false;
		genbs_gmotherp4_isLoaded = false;
		genbs_gmothercharge_isLoaded = false;
		genbs_gmotherid_isLoaded = false;
		genbs_gmotheridx_isLoaded = false;
		genbs_gmotherstatus_isLoaded = false;
		genbs_simplemotherp4_isLoaded = false;
		genbs_simplemothercharge_isLoaded = false;
		genbs_simplemotherid_isLoaded = false;
		genbs_simplemotheridx_isLoaded = false;
		genbs_simplemotherstatus_isLoaded = false;
		genbs_simplegmotherp4_isLoaded = false;
		genbs_simplegmothercharge_isLoaded = false;
		genbs_simplegmotherid_isLoaded = false;
		genbs_simplegmotheridx_isLoaded = false;
		genbs_simplegmotherstatus_isLoaded = false;
		gencs_isfromt_isLoaded = false;
		gencs_p4_isLoaded = false;
		gencs_charge_isLoaded = false;
		gencs_iso_isLoaded = false;
		gencs_mass_isLoaded = false;
		gencs_id_isLoaded = false;
		gencs__genpsidx_isLoaded = false;
		gencs_status_isLoaded = false;
		gencs_fromHardProcessBeforeFSR_isLoaded = false;
		gencs_fromHardProcessDecayed_isLoaded = false;
		gencs_fromHardProcessFinalState_isLoaded = false;
		gencs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		gencs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		gencs_isHardProcess_isLoaded = false;
		gencs_isLastCopy_isLoaded = false;
		gencs_isLastCopyBeforeFSR_isLoaded = false;
		gencs_isMostlyLikePythia6Status3_isLoaded = false;
		gencs_isPromptDecayed_isLoaded = false;
		gencs_isPromptFinalState_isLoaded = false;
		gencs_lepdaughter_id_isLoaded = false;
		gencs_gentaudecay_isLoaded = false;
		gen_nfromtcs__isLoaded = false;
		gencs_motherp4_isLoaded = false;
		gencs_mothercharge_isLoaded = false;
		gencs_motherid_isLoaded = false;
		gencs_motheridx_isLoaded = false;
		gencs_motherstatus_isLoaded = false;
		gencs_gmotherp4_isLoaded = false;
		gencs_gmothercharge_isLoaded = false;
		gencs_gmotherid_isLoaded = false;
		gencs_gmotheridx_isLoaded = false;
		gencs_gmotherstatus_isLoaded = false;
		gencs_simplemotherp4_isLoaded = false;
		gencs_simplemothercharge_isLoaded = false;
		gencs_simplemotherid_isLoaded = false;
		gencs_simplemotheridx_isLoaded = false;
		gencs_simplemotherstatus_isLoaded = false;
		gencs_simplegmotherp4_isLoaded = false;
		gencs_simplegmothercharge_isLoaded = false;
		gencs_simplegmotherid_isLoaded = false;
		gencs_simplegmotheridx_isLoaded = false;
		gencs_simplegmotherstatus_isLoaded = false;
		genqs_isfromt_isLoaded = false;
		genqs_p4_isLoaded = false;
		genqs_charge_isLoaded = false;
		genqs_iso_isLoaded = false;
		genqs_mass_isLoaded = false;
		genqs_id_isLoaded = false;
		genqs__genpsidx_isLoaded = false;
		genqs_status_isLoaded = false;
		genqs_fromHardProcessBeforeFSR_isLoaded = false;
		genqs_fromHardProcessDecayed_isLoaded = false;
		genqs_fromHardProcessFinalState_isLoaded = false;
		genqs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genqs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genqs_isHardProcess_isLoaded = false;
		genqs_isLastCopy_isLoaded = false;
		genqs_isLastCopyBeforeFSR_isLoaded = false;
		genqs_isMostlyLikePythia6Status3_isLoaded = false;
		genqs_isPromptDecayed_isLoaded = false;
		genqs_isPromptFinalState_isLoaded = false;
		genqs_lepdaughter_id_isLoaded = false;
		genqs_gentaudecay_isLoaded = false;
		gen_nfromtqs__isLoaded = false;
		genqs_motherp4_isLoaded = false;
		genqs_mothercharge_isLoaded = false;
		genqs_motherid_isLoaded = false;
		genqs_motheridx_isLoaded = false;
		genqs_motherstatus_isLoaded = false;
		genqs_gmotherp4_isLoaded = false;
		genqs_gmothercharge_isLoaded = false;
		genqs_gmotherid_isLoaded = false;
		genqs_gmotheridx_isLoaded = false;
		genqs_gmotherstatus_isLoaded = false;
		genqs_simplemotherp4_isLoaded = false;
		genqs_simplemothercharge_isLoaded = false;
		genqs_simplemotherid_isLoaded = false;
		genqs_simplemotheridx_isLoaded = false;
		genqs_simplemotherstatus_isLoaded = false;
		genqs_simplegmotherp4_isLoaded = false;
		genqs_simplegmothercharge_isLoaded = false;
		genqs_simplegmotherid_isLoaded = false;
		genqs_simplegmotheridx_isLoaded = false;
		genqs_simplegmotherstatus_isLoaded = false;
		genglus_isfromt_isLoaded = false;
		genglus_p4_isLoaded = false;
		genglus_charge_isLoaded = false;
		genglus_iso_isLoaded = false;
		genglus_mass_isLoaded = false;
		genglus_id_isLoaded = false;
		genglus__genpsidx_isLoaded = false;
		genglus_status_isLoaded = false;
		genglus_fromHardProcessBeforeFSR_isLoaded = false;
		genglus_fromHardProcessDecayed_isLoaded = false;
		genglus_fromHardProcessFinalState_isLoaded = false;
		genglus_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genglus_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genglus_isHardProcess_isLoaded = false;
		genglus_isLastCopy_isLoaded = false;
		genglus_isLastCopyBeforeFSR_isLoaded = false;
		genglus_isMostlyLikePythia6Status3_isLoaded = false;
		genglus_isPromptDecayed_isLoaded = false;
		genglus_isPromptFinalState_isLoaded = false;
		genglus_lepdaughter_id_isLoaded = false;
		genglus_gentaudecay_isLoaded = false;
		gen_nfromtglus__isLoaded = false;
		genglus_motherp4_isLoaded = false;
		genglus_mothercharge_isLoaded = false;
		genglus_motherid_isLoaded = false;
		genglus_motheridx_isLoaded = false;
		genglus_motherstatus_isLoaded = false;
		genglus_gmotherp4_isLoaded = false;
		genglus_gmothercharge_isLoaded = false;
		genglus_gmotherid_isLoaded = false;
		genglus_gmotheridx_isLoaded = false;
		genglus_gmotherstatus_isLoaded = false;
		genglus_simplemotherp4_isLoaded = false;
		genglus_simplemothercharge_isLoaded = false;
		genglus_simplemotherid_isLoaded = false;
		genglus_simplemotheridx_isLoaded = false;
		genglus_simplemotherstatus_isLoaded = false;
		genglus_simplegmotherp4_isLoaded = false;
		genglus_simplegmothercharge_isLoaded = false;
		genglus_simplegmotherid_isLoaded = false;
		genglus_simplegmotheridx_isLoaded = false;
		genglus_simplegmotherstatus_isLoaded = false;
		genws_isfromt_isLoaded = false;
		genws_p4_isLoaded = false;
		genws_charge_isLoaded = false;
		genws_iso_isLoaded = false;
		genws_mass_isLoaded = false;
		genws_id_isLoaded = false;
		genws__genpsidx_isLoaded = false;
		genws_status_isLoaded = false;
		genws_fromHardProcessBeforeFSR_isLoaded = false;
		genws_fromHardProcessDecayed_isLoaded = false;
		genws_fromHardProcessFinalState_isLoaded = false;
		genws_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genws_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genws_isHardProcess_isLoaded = false;
		genws_isLastCopy_isLoaded = false;
		genws_isLastCopyBeforeFSR_isLoaded = false;
		genws_isMostlyLikePythia6Status3_isLoaded = false;
		genws_isPromptDecayed_isLoaded = false;
		genws_isPromptFinalState_isLoaded = false;
		genws_lepdaughter_id_isLoaded = false;
		genws_gentaudecay_isLoaded = false;
		gen_nfromtws__isLoaded = false;
		genws_motherp4_isLoaded = false;
		genws_mothercharge_isLoaded = false;
		genws_motherid_isLoaded = false;
		genws_motheridx_isLoaded = false;
		genws_motherstatus_isLoaded = false;
		genws_gmotherp4_isLoaded = false;
		genws_gmothercharge_isLoaded = false;
		genws_gmotherid_isLoaded = false;
		genws_gmotheridx_isLoaded = false;
		genws_gmotherstatus_isLoaded = false;
		genws_simplemotherp4_isLoaded = false;
		genws_simplemothercharge_isLoaded = false;
		genws_simplemotherid_isLoaded = false;
		genws_simplemotheridx_isLoaded = false;
		genws_simplemotherstatus_isLoaded = false;
		genws_simplegmotherp4_isLoaded = false;
		genws_simplegmothercharge_isLoaded = false;
		genws_simplegmotherid_isLoaded = false;
		genws_simplegmotheridx_isLoaded = false;
		genws_simplegmotherstatus_isLoaded = false;
		genzs_isfromt_isLoaded = false;
		genzs_p4_isLoaded = false;
		genzs_charge_isLoaded = false;
		genzs_iso_isLoaded = false;
		genzs_mass_isLoaded = false;
		genzs_id_isLoaded = false;
		genzs__genpsidx_isLoaded = false;
		genzs_status_isLoaded = false;
		genzs_fromHardProcessBeforeFSR_isLoaded = false;
		genzs_fromHardProcessDecayed_isLoaded = false;
		genzs_fromHardProcessFinalState_isLoaded = false;
		genzs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genzs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genzs_isHardProcess_isLoaded = false;
		genzs_isLastCopy_isLoaded = false;
		genzs_isLastCopyBeforeFSR_isLoaded = false;
		genzs_isMostlyLikePythia6Status3_isLoaded = false;
		genzs_isPromptDecayed_isLoaded = false;
		genzs_isPromptFinalState_isLoaded = false;
		genzs_lepdaughter_id_isLoaded = false;
		genzs_gentaudecay_isLoaded = false;
		gen_nfromtzs__isLoaded = false;
		genzs_motherp4_isLoaded = false;
		genzs_mothercharge_isLoaded = false;
		genzs_motherid_isLoaded = false;
		genzs_motheridx_isLoaded = false;
		genzs_motherstatus_isLoaded = false;
		genzs_gmotherp4_isLoaded = false;
		genzs_gmothercharge_isLoaded = false;
		genzs_gmotherid_isLoaded = false;
		genzs_gmotheridx_isLoaded = false;
		genzs_gmotherstatus_isLoaded = false;
		genzs_simplemotherp4_isLoaded = false;
		genzs_simplemothercharge_isLoaded = false;
		genzs_simplemotherid_isLoaded = false;
		genzs_simplemotheridx_isLoaded = false;
		genzs_simplemotherstatus_isLoaded = false;
		genzs_simplegmotherp4_isLoaded = false;
		genzs_simplegmothercharge_isLoaded = false;
		genzs_simplegmotherid_isLoaded = false;
		genzs_simplegmotheridx_isLoaded = false;
		genzs_simplegmotherstatus_isLoaded = false;
		genphs_isfromt_isLoaded = false;
		genphs_p4_isLoaded = false;
		genphs_charge_isLoaded = false;
		genphs_iso_isLoaded = false;
		genphs_mass_isLoaded = false;
		genphs_id_isLoaded = false;
		genphs__genpsidx_isLoaded = false;
		genphs_status_isLoaded = false;
		genphs_fromHardProcessBeforeFSR_isLoaded = false;
		genphs_fromHardProcessDecayed_isLoaded = false;
		genphs_fromHardProcessFinalState_isLoaded = false;
		genphs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genphs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genphs_isHardProcess_isLoaded = false;
		genphs_isLastCopy_isLoaded = false;
		genphs_isLastCopyBeforeFSR_isLoaded = false;
		genphs_isMostlyLikePythia6Status3_isLoaded = false;
		genphs_isPromptDecayed_isLoaded = false;
		genphs_isPromptFinalState_isLoaded = false;
		genphs_lepdaughter_id_isLoaded = false;
		genphs_gentaudecay_isLoaded = false;
		gen_nfromtphs__isLoaded = false;
		genphs_motherp4_isLoaded = false;
		genphs_mothercharge_isLoaded = false;
		genphs_motherid_isLoaded = false;
		genphs_motheridx_isLoaded = false;
		genphs_motherstatus_isLoaded = false;
		genphs_gmotherp4_isLoaded = false;
		genphs_gmothercharge_isLoaded = false;
		genphs_gmotherid_isLoaded = false;
		genphs_gmotheridx_isLoaded = false;
		genphs_gmotherstatus_isLoaded = false;
		genphs_simplemotherp4_isLoaded = false;
		genphs_simplemothercharge_isLoaded = false;
		genphs_simplemotherid_isLoaded = false;
		genphs_simplemotheridx_isLoaded = false;
		genphs_simplemotherstatus_isLoaded = false;
		genphs_simplegmotherp4_isLoaded = false;
		genphs_simplegmothercharge_isLoaded = false;
		genphs_simplegmotherid_isLoaded = false;
		genphs_simplegmotheridx_isLoaded = false;
		genphs_simplegmotherstatus_isLoaded = false;
		genhs_isfromt_isLoaded = false;
		genhs_p4_isLoaded = false;
		genhs_charge_isLoaded = false;
		genhs_iso_isLoaded = false;
		genhs_mass_isLoaded = false;
		genhs_id_isLoaded = false;
		genhs__genpsidx_isLoaded = false;
		genhs_status_isLoaded = false;
		genhs_fromHardProcessBeforeFSR_isLoaded = false;
		genhs_fromHardProcessDecayed_isLoaded = false;
		genhs_fromHardProcessFinalState_isLoaded = false;
		genhs_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genhs_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genhs_isHardProcess_isLoaded = false;
		genhs_isLastCopy_isLoaded = false;
		genhs_isLastCopyBeforeFSR_isLoaded = false;
		genhs_isMostlyLikePythia6Status3_isLoaded = false;
		genhs_isPromptDecayed_isLoaded = false;
		genhs_isPromptFinalState_isLoaded = false;
		genhs_lepdaughter_id_isLoaded = false;
		genhs_gentaudecay_isLoaded = false;
		gen_nfromths__isLoaded = false;
		genhs_motherp4_isLoaded = false;
		genhs_mothercharge_isLoaded = false;
		genhs_motherid_isLoaded = false;
		genhs_motheridx_isLoaded = false;
		genhs_motherstatus_isLoaded = false;
		genhs_gmotherp4_isLoaded = false;
		genhs_gmothercharge_isLoaded = false;
		genhs_gmotherid_isLoaded = false;
		genhs_gmotheridx_isLoaded = false;
		genhs_gmotherstatus_isLoaded = false;
		genhs_simplemotherp4_isLoaded = false;
		genhs_simplemothercharge_isLoaded = false;
		genhs_simplemotherid_isLoaded = false;
		genhs_simplemotheridx_isLoaded = false;
		genhs_simplemotherstatus_isLoaded = false;
		genhs_simplegmotherp4_isLoaded = false;
		genhs_simplegmothercharge_isLoaded = false;
		genhs_simplegmotherid_isLoaded = false;
		genhs_simplegmotheridx_isLoaded = false;
		genhs_simplegmotherstatus_isLoaded = false;
		genlsp_isfromt_isLoaded = false;
		genlsp_p4_isLoaded = false;
		genlsp_charge_isLoaded = false;
		genlsp_iso_isLoaded = false;
		genlsp_mass_isLoaded = false;
		genlsp_id_isLoaded = false;
		genlsp__genpsidx_isLoaded = false;
		genlsp_status_isLoaded = false;
		genlsp_fromHardProcessBeforeFSR_isLoaded = false;
		genlsp_fromHardProcessDecayed_isLoaded = false;
		genlsp_fromHardProcessFinalState_isLoaded = false;
		genlsp_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genlsp_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genlsp_isHardProcess_isLoaded = false;
		genlsp_isLastCopy_isLoaded = false;
		genlsp_isLastCopyBeforeFSR_isLoaded = false;
		genlsp_isMostlyLikePythia6Status3_isLoaded = false;
		genlsp_isPromptDecayed_isLoaded = false;
		genlsp_isPromptFinalState_isLoaded = false;
		genlsp_lepdaughter_id_isLoaded = false;
		genlsp_gentaudecay_isLoaded = false;
		gen_nfromtlsp__isLoaded = false;
		genlsp_motherp4_isLoaded = false;
		genlsp_mothercharge_isLoaded = false;
		genlsp_motherid_isLoaded = false;
		genlsp_motheridx_isLoaded = false;
		genlsp_motherstatus_isLoaded = false;
		genlsp_gmotherp4_isLoaded = false;
		genlsp_gmothercharge_isLoaded = false;
		genlsp_gmotherid_isLoaded = false;
		genlsp_gmotheridx_isLoaded = false;
		genlsp_gmotherstatus_isLoaded = false;
		genlsp_simplemotherp4_isLoaded = false;
		genlsp_simplemothercharge_isLoaded = false;
		genlsp_simplemotherid_isLoaded = false;
		genlsp_simplemotheridx_isLoaded = false;
		genlsp_simplemotherstatus_isLoaded = false;
		genlsp_simplegmotherp4_isLoaded = false;
		genlsp_simplegmothercharge_isLoaded = false;
		genlsp_simplegmotherid_isLoaded = false;
		genlsp_simplegmotheridx_isLoaded = false;
		genlsp_simplegmotherstatus_isLoaded = false;
		genstop_isfromt_isLoaded = false;
		genstop_p4_isLoaded = false;
		genstop_charge_isLoaded = false;
		genstop_iso_isLoaded = false;
		genstop_mass_isLoaded = false;
		genstop_id_isLoaded = false;
		genstop__genpsidx_isLoaded = false;
		genstop_status_isLoaded = false;
		genstop_fromHardProcessBeforeFSR_isLoaded = false;
		genstop_fromHardProcessDecayed_isLoaded = false;
		genstop_fromHardProcessFinalState_isLoaded = false;
		genstop_isDirectHardProcessTauDecayProductFinalState_isLoaded = false;
		genstop_isDirectPromptTauDecayProductFinalState_isLoaded = false;
		genstop_isHardProcess_isLoaded = false;
		genstop_isLastCopy_isLoaded = false;
		genstop_isLastCopyBeforeFSR_isLoaded = false;
		genstop_isMostlyLikePythia6Status3_isLoaded = false;
		genstop_isPromptDecayed_isLoaded = false;
		genstop_isPromptFinalState_isLoaded = false;
		genstop_lepdaughter_id_isLoaded = false;
		genstop_gentaudecay_isLoaded = false;
		gen_nfromtstop__isLoaded = false;
		genstop_motherp4_isLoaded = false;
		genstop_mothercharge_isLoaded = false;
		genstop_motherid_isLoaded = false;
		genstop_motheridx_isLoaded = false;
		genstop_motherstatus_isLoaded = false;
		genstop_gmotherp4_isLoaded = false;
		genstop_gmothercharge_isLoaded = false;
		genstop_gmotherid_isLoaded = false;
		genstop_gmotheridx_isLoaded = false;
		genstop_gmotherstatus_isLoaded = false;
		genstop_simplemotherp4_isLoaded = false;
		genstop_simplemothercharge_isLoaded = false;
		genstop_simplemotherid_isLoaded = false;
		genstop_simplemotheridx_isLoaded = false;
		genstop_simplemotherstatus_isLoaded = false;
		genstop_simplegmotherp4_isLoaded = false;
		genstop_simplegmothercharge_isLoaded = false;
		genstop_simplegmotherid_isLoaded = false;
		genstop_simplegmotheridx_isLoaded = false;
		genstop_simplegmotherstatus_isLoaded = false;
	}

void LoadAllBranches() 
	// load all branches
{
	if (run_branch != 0) run();
	if (ls_branch != 0) ls();
	if (evt_branch != 0) evt();
	if (nvtxs_branch != 0) nvtxs();
	if (firstGoodVtxIdx_branch != 0) firstGoodVtxIdx();
	if (firstVtx_isfake_branch != 0) firstVtx_isfake();
	if (firstVtx_ndof_branch != 0) firstVtx_ndof();
	if (firstVtx_posRho_branch != 0) firstVtx_posRho();
	if (firstVtx_posZ_branch != 0) firstVtx_posZ();
	if (firstVtx_posp4_branch != 0) firstVtx_posp4();
	if (pu_nvtxs_branch != 0) pu_nvtxs();
	if (pfmet_branch != 0) pfmet();
	if (pfmet_phi_branch != 0) pfmet_phi();
	if (calomet_branch != 0) calomet();
	if (calomet_phi_branch != 0) calomet_phi();
	if (filt_cscbeamhalo_branch != 0) filt_cscbeamhalo();
	if (filt_ecallaser_branch != 0) filt_ecallaser();
	if (filt_ecaltp_branch != 0) filt_ecaltp();
	if (filt_eebadsc_branch != 0) filt_eebadsc();
	if (filt_goodvtx_branch != 0) filt_goodvtx();
	if (filt_hbhenoise_branch != 0) filt_hbhenoise();
	if (filt_hcallaser_branch != 0) filt_hcallaser();
	if (filt_met_branch != 0) filt_met();
	if (filt_trkfail_branch != 0) filt_trkfail();
	if (filt_trkPOG_branch != 0) filt_trkPOG();
	if (filt_trkPOG_tmc_branch != 0) filt_trkPOG_tmc();
	if (filt_trkPOG_tms_branch != 0) filt_trkPOG_tms();
	if (filt_eff_branch != 0) filt_eff();
	if (scale1fb_branch != 0) scale1fb();
	if (xsec_branch != 0) xsec();
	if (kfactor_branch != 0) kfactor();
	if (pu_ntrue_branch != 0) pu_ntrue();
	if (ngoodleps_branch != 0) ngoodleps();
	if (nvetoleps_branch != 0) nvetoleps();
	if (is_data_branch != 0) is_data();
	if (dataset_branch != 0) dataset();
	if (filename_branch != 0) filename();
	if (cms3tag_branch != 0) cms3tag();
	if (nEvents_branch != 0) nEvents();
	if (nEvents_goodvtx_branch != 0) nEvents_goodvtx();
	if (nEvents_MET30_branch != 0) nEvents_MET30();
	if (nEvents_1goodlep_branch != 0) nEvents_1goodlep();
	if (nEvents_2goodjets_branch != 0) nEvents_2goodjets();
	if (genlepsfromtop_branch != 0) genlepsfromtop();
	if (MT2W_branch != 0) MT2W();
	if (MT2W_lep2_branch != 0) MT2W_lep2();
	if (mindphi_met_j1_j2_branch != 0) mindphi_met_j1_j2();
	if (mt_met_lep_branch != 0) mt_met_lep();
	if (mt_met_lep2_branch != 0) mt_met_lep2();
	if (dR_lep_leadb_branch != 0) dR_lep_leadb();
	if (dR_lep2_leadb_branch != 0) dR_lep2_leadb();
	if (hadronic_top_chi2_branch != 0) hadronic_top_chi2();
	if (dphi_Wlep_branch != 0) dphi_Wlep();
	if (MET_over_sqrtHT_branch != 0) MET_over_sqrtHT();
	if (ak4pfjets_rho_branch != 0) ak4pfjets_rho();
	if (sparms_comment_branch != 0) sparms_comment();
	if (sparms_names_branch != 0) sparms_names();
	if (sparms_filterEfficiency_branch != 0) sparms_filterEfficiency();
	if (sparms_pdfScale_branch != 0) sparms_pdfScale();
	if (sparms_pdfWeight1_branch != 0) sparms_pdfWeight1();
	if (sparms_pdfWeight2_branch != 0) sparms_pdfWeight2();
	if (sparms_weight_branch != 0) sparms_weight();
	if (sparms_xsec_branch != 0) sparms_xsec();
	if (sparms_values_branch != 0) sparms_values();
	if (sparms_subProcessId_branch != 0) sparms_subProcessId();
	if (mass_lsp_branch != 0) mass_lsp();
	if (mass_chargino_branch != 0) mass_chargino();
	if (mass_stop_branch != 0) mass_stop();
	if (genmet_branch != 0) genmet();
	if (genmet_phi_branch != 0) genmet_phi();
	if (PassTrackVeto_branch != 0) PassTrackVeto();
	if (PassTrackVeto_v2_branch != 0) PassTrackVeto_v2();
	if (PassTrackVeto_v3_branch != 0) PassTrackVeto_v3();
	if (PassTauVeto_branch != 0) PassTauVeto();
	if (EA_all_rho_branch != 0) EA_all_rho();
	if (EA_allcalo_rho_branch != 0) EA_allcalo_rho();
	if (EA_centralcalo_rho_branch != 0) EA_centralcalo_rho();
	if (EA_centralchargedpileup_rho_branch != 0) EA_centralchargedpileup_rho();
	if (EA_centralneutral_rho_branch != 0) EA_centralneutral_rho();
	if (topness_branch != 0) topness();
	if (topness_lep2_branch != 0) topness_lep2();
	if (topnessMod_branch != 0) topnessMod();
	if (topnessMod_lep2_branch != 0) topnessMod_lep2();
	if (MT2_lb_b_branch != 0) MT2_lb_b();
	if (MT2_lb_b_lep2_branch != 0) MT2_lb_b_lep2();
	if (MT2_lb_b_mass_branch != 0) MT2_lb_b_mass();
	if (MT2_lb_b_mass_lep2_branch != 0) MT2_lb_b_mass_lep2();
	if (MT2_lb_bqq_branch != 0) MT2_lb_bqq();
	if (MT2_lb_bqq_lep2_branch != 0) MT2_lb_bqq_lep2();
	if (MT2_lb_bqq_mass_branch != 0) MT2_lb_bqq_mass();
	if (MT2_lb_bqq_mass_lep2_branch != 0) MT2_lb_bqq_mass_lep2();
	if (Mlb_closestb_branch != 0) Mlb_closestb();
	if (Mlb_lead_bdiscr_branch != 0) Mlb_lead_bdiscr();
	if (Mlb_closestb_lep2_branch != 0) Mlb_closestb_lep2();
	if (Mlb_lead_bdiscr_lep2_branch != 0) Mlb_lead_bdiscr_lep2();
	if (Mjjj_branch != 0) Mjjj();
	if (Mjjj_lep2_branch != 0) Mjjj_lep2();
	if (HLT_SingleEl_branch != 0) HLT_SingleEl();
	if (HLT_SingleMu_branch != 0) HLT_SingleMu();
	if (HLT_MET170_branch != 0) HLT_MET170();
	if (HLT_MET120Btag_branch != 0) HLT_MET120Btag();
	if (HLT_MET120Mu5_branch != 0) HLT_MET120Mu5();
	if (HLT_HT350MET120_branch != 0) HLT_HT350MET120();
	if (HLT_DiEl_branch != 0) HLT_DiEl();
	if (HLT_DiMu_branch != 0) HLT_DiMu();
	if (HLT_Mu8El17_branch != 0) HLT_Mu8El17();
	if (HLT_Mu8El23_branch != 0) HLT_Mu8El23();
	if (HLT_Mu17El12_branch != 0) HLT_Mu17El12();
	if (HLT_Mu23El12_branch != 0) HLT_Mu23El12();
	if (HLT_SingleEl27_branch != 0) HLT_SingleEl27();
	if (HLT_SingleEl27Tight_branch != 0) HLT_SingleEl27Tight();
	if (HLT_SingleElTight_branch != 0) HLT_SingleElTight();
	if (HLT_SingleElHT200_branch != 0) HLT_SingleElHT200();
	if (HLT_SingleMuNoEta_branch != 0) HLT_SingleMuNoEta();
	if (HLT_SingleMuNoIso_branch != 0) HLT_SingleMuNoIso();
	if (HLT_SingleMuNoIsoNoEta_branch != 0) HLT_SingleMuNoIsoNoEta();
	if (HLT_Mu6HT200MET100_branch != 0) HLT_Mu6HT200MET100();
	if (HLT_HT350MET100_branch != 0) HLT_HT350MET100();
	if (HLT_SingleMu17_branch != 0) HLT_SingleMu17();
	if (HLT_SingleMu20_branch != 0) HLT_SingleMu20();
	if (HLT_SingleMu24_branch != 0) HLT_SingleMu24();
	if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch != 0) HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight();
	if (HLT_MET90_MHT90_IDTight_branch != 0) HLT_MET90_MHT90_IDTight();
	if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch != 0) HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight();
	if (pu_weight_branch != 0) pu_weight();
	if (lep_sf_branch != 0) lep_sf();
	if (btag_sf_branch != 0) btag_sf();
	if (HLT_SingleEl_eff_branch != 0) HLT_SingleEl_eff();
	if (HLT_SingleMu_eff_branch != 0) HLT_SingleMu_eff();
	if (lep1_is_mu_branch != 0) lep1_is_mu();
	if (lep1_is_el_branch != 0) lep1_is_el();
	if (lep1_charge_branch != 0) lep1_charge();
	if (lep1_pdgid_branch != 0) lep1_pdgid();
	if (lep1_type_branch != 0) lep1_type();
	if (lep1_production_type_branch != 0) lep1_production_type();
	if (lep1_d0_branch != 0) lep1_d0();
	if (lep1_d0err_branch != 0) lep1_d0err();
	if (lep1_dz_branch != 0) lep1_dz();
	if (lep1_dzerr_branch != 0) lep1_dzerr();
	if (lep1_sigmaIEtaEta_fill5x5_branch != 0) lep1_sigmaIEtaEta_fill5x5();
	if (lep1_dEtaIn_branch != 0) lep1_dEtaIn();
	if (lep1_dPhiIn_branch != 0) lep1_dPhiIn();
	if (lep1_hOverE_branch != 0) lep1_hOverE();
	if (lep1_ooEmooP_branch != 0) lep1_ooEmooP();
	if (lep1_expectedMissingInnerHits_branch != 0) lep1_expectedMissingInnerHits();
	if (lep1_conversionVeto_branch != 0) lep1_conversionVeto();
	if (lep1_etaSC_branch != 0) lep1_etaSC();
	if (lep1_ChiSqr_branch != 0) lep1_ChiSqr();
	if (lep1_chiso_branch != 0) lep1_chiso();
	if (lep1_nhiso_branch != 0) lep1_nhiso();
	if (lep1_emiso_branch != 0) lep1_emiso();
	if (lep1_deltaBeta_branch != 0) lep1_deltaBeta();
	if (lep1_relIso03DB_branch != 0) lep1_relIso03DB();
	if (lep1_relIso03EA_branch != 0) lep1_relIso03EA();
	if (lep1_relIso04DB_branch != 0) lep1_relIso04DB();
	if (lep1_miniRelIsoDB_branch != 0) lep1_miniRelIsoDB();
	if (lep1_miniRelIsoEA_branch != 0) lep1_miniRelIsoEA();
	if (lep1_MiniIso_branch != 0) lep1_MiniIso();
	if (lep1_mcid_branch != 0) lep1_mcid();
	if (lep1_mcstatus_branch != 0) lep1_mcstatus();
	if (lep1_mc3dr_branch != 0) lep1_mc3dr();
	if (lep1_mc3id_branch != 0) lep1_mc3id();
	if (lep1_mc3idx_branch != 0) lep1_mc3idx();
	if (lep1_mc3motherid_branch != 0) lep1_mc3motherid();
	if (lep1_mc3motheridx_branch != 0) lep1_mc3motheridx();
	if (lep1_is_eleid_loose_branch != 0) lep1_is_eleid_loose();
	if (lep1_is_eleid_medium_branch != 0) lep1_is_eleid_medium();
	if (lep1_is_eleid_tight_branch != 0) lep1_is_eleid_tight();
	if (lep1_is_phys14_loose_noIso_branch != 0) lep1_is_phys14_loose_noIso();
	if (lep1_is_phys14_medium_noIso_branch != 0) lep1_is_phys14_medium_noIso();
	if (lep1_is_phys14_tight_noIso_branch != 0) lep1_is_phys14_tight_noIso();
	if (lep1_eoverpin_branch != 0) lep1_eoverpin();
	if (lep1_is_muoid_loose_branch != 0) lep1_is_muoid_loose();
	if (lep1_is_muoid_medium_branch != 0) lep1_is_muoid_medium();
	if (lep1_is_muoid_tight_branch != 0) lep1_is_muoid_tight();
	if (lep1_ip3d_branch != 0) lep1_ip3d();
	if (lep1_ip3derr_branch != 0) lep1_ip3derr();
	if (lep1_is_pfmu_branch != 0) lep1_is_pfmu();
	if (lep1_passMediumID_branch != 0) lep1_passMediumID();
	if (lep1_passVeto_branch != 0) lep1_passVeto();
	if (lep1_p4_branch != 0) lep1_p4();
	if (lep1_mcp4_branch != 0) lep1_mcp4();
	if (lep1_pt_branch != 0) lep1_pt();
	if (lep1_eta_branch != 0) lep1_eta();
	if (lep1_phi_branch != 0) lep1_phi();
	if (lep1_mass_branch != 0) lep1_mass();
	if (lep2_is_mu_branch != 0) lep2_is_mu();
	if (lep2_is_el_branch != 0) lep2_is_el();
	if (lep2_charge_branch != 0) lep2_charge();
	if (lep2_pdgid_branch != 0) lep2_pdgid();
	if (lep2_type_branch != 0) lep2_type();
	if (lep2_production_type_branch != 0) lep2_production_type();
	if (lep2_d0_branch != 0) lep2_d0();
	if (lep2_d0err_branch != 0) lep2_d0err();
	if (lep2_dz_branch != 0) lep2_dz();
	if (lep2_dzerr_branch != 0) lep2_dzerr();
	if (lep2_sigmaIEtaEta_fill5x5_branch != 0) lep2_sigmaIEtaEta_fill5x5();
	if (lep2_dEtaIn_branch != 0) lep2_dEtaIn();
	if (lep2_dPhiIn_branch != 0) lep2_dPhiIn();
	if (lep2_hOverE_branch != 0) lep2_hOverE();
	if (lep2_ooEmooP_branch != 0) lep2_ooEmooP();
	if (lep2_expectedMissingInnerHits_branch != 0) lep2_expectedMissingInnerHits();
	if (lep2_conversionVeto_branch != 0) lep2_conversionVeto();
	if (lep2_etaSC_branch != 0) lep2_etaSC();
	if (lep2_ChiSqr_branch != 0) lep2_ChiSqr();
	if (lep2_chiso_branch != 0) lep2_chiso();
	if (lep2_nhiso_branch != 0) lep2_nhiso();
	if (lep2_emiso_branch != 0) lep2_emiso();
	if (lep2_deltaBeta_branch != 0) lep2_deltaBeta();
	if (lep2_relIso03DB_branch != 0) lep2_relIso03DB();
	if (lep2_relIso03EA_branch != 0) lep2_relIso03EA();
	if (lep2_relIso04DB_branch != 0) lep2_relIso04DB();
	if (lep2_miniRelIsoDB_branch != 0) lep2_miniRelIsoDB();
	if (lep2_miniRelIsoEA_branch != 0) lep2_miniRelIsoEA();
	if (lep2_MiniIso_branch != 0) lep2_MiniIso();
	if (lep2_mcid_branch != 0) lep2_mcid();
	if (lep2_mcstatus_branch != 0) lep2_mcstatus();
	if (lep2_mc3dr_branch != 0) lep2_mc3dr();
	if (lep2_mc3id_branch != 0) lep2_mc3id();
	if (lep2_mc3idx_branch != 0) lep2_mc3idx();
	if (lep2_mc3motherid_branch != 0) lep2_mc3motherid();
	if (lep2_mc3motheridx_branch != 0) lep2_mc3motheridx();
	if (lep2_is_eleid_loose_branch != 0) lep2_is_eleid_loose();
	if (lep2_is_eleid_medium_branch != 0) lep2_is_eleid_medium();
	if (lep2_is_eleid_tight_branch != 0) lep2_is_eleid_tight();
	if (lep2_is_phys14_loose_noIso_branch != 0) lep2_is_phys14_loose_noIso();
	if (lep2_is_phys14_medium_noIso_branch != 0) lep2_is_phys14_medium_noIso();
	if (lep2_is_phys14_tight_noIso_branch != 0) lep2_is_phys14_tight_noIso();
	if (lep2_eoverpin_branch != 0) lep2_eoverpin();
	if (lep2_is_muoid_loose_branch != 0) lep2_is_muoid_loose();
	if (lep2_is_muoid_medium_branch != 0) lep2_is_muoid_medium();
	if (lep2_is_muoid_tight_branch != 0) lep2_is_muoid_tight();
	if (lep2_ip3d_branch != 0) lep2_ip3d();
	if (lep2_ip3derr_branch != 0) lep2_ip3derr();
	if (lep2_is_pfmu_branch != 0) lep2_is_pfmu();
	if (lep2_passMediumID_branch != 0) lep2_passMediumID();
	if (lep2_passVeto_branch != 0) lep2_passVeto();
	if (lep2_p4_branch != 0) lep2_p4();
	if (lep2_mcp4_branch != 0) lep2_mcp4();
	if (lep2_pt_branch != 0) lep2_pt();
	if (lep2_eta_branch != 0) lep2_eta();
	if (lep2_phi_branch != 0) lep2_phi();
	if (lep2_mass_branch != 0) lep2_mass();
	if (nGoodGenJets_branch != 0) nGoodGenJets();
	if (ngoodjets_branch != 0) ngoodjets();
	if (nfailjets_branch != 0) nfailjets();
	if (ak8GoodPFJets_branch != 0) ak8GoodPFJets();
	if (ngoodbtags_branch != 0) ngoodbtags();
	if (ak4_HT_branch != 0) ak4_HT();
	if (ak4_htssm_branch != 0) ak4_htssm();
	if (ak4_htosm_branch != 0) ak4_htosm();
	if (ak4_htratiom_branch != 0) ak4_htratiom();
	if (dphi_ak4pfjet_met_branch != 0) dphi_ak4pfjet_met();
	if (ak4pfjets_p4_branch != 0) ak4pfjets_p4();
	if (ak4pfjets_pt_branch != 0) ak4pfjets_pt();
	if (ak4pfjets_eta_branch != 0) ak4pfjets_eta();
	if (ak4pfjets_phi_branch != 0) ak4pfjets_phi();
	if (ak4pfjets_mass_branch != 0) ak4pfjets_mass();
	if (ak4pfjets_passMEDbtag_branch != 0) ak4pfjets_passMEDbtag();
	if (ak4pfjets_qg_disc_branch != 0) ak4pfjets_qg_disc();
	if (ak4pfjets_CSV_branch != 0) ak4pfjets_CSV();
	if (ak4pfjets_puid_branch != 0) ak4pfjets_puid();
	if (ak4pfjets_parton_flavor_branch != 0) ak4pfjets_parton_flavor();
	if (ak4pfjets_loose_puid_branch != 0) ak4pfjets_loose_puid();
	if (ak4pfjets_loose_pfid_branch != 0) ak4pfjets_loose_pfid();
	if (ak4pfjets_medium_pfid_branch != 0) ak4pfjets_medium_pfid();
	if (ak4pfjets_tight_pfid_branch != 0) ak4pfjets_tight_pfid();
	if (ak4pfjets_MEDbjet_pt_branch != 0) ak4pfjets_MEDbjet_pt();
	if (ak4pfjets_leadMEDbjet_pt_branch != 0) ak4pfjets_leadMEDbjet_pt();
	if (ak4pfjets_leadMEDbjet_p4_branch != 0) ak4pfjets_leadMEDbjet_p4();
	if (ak4pfjets_leadbtag_p4_branch != 0) ak4pfjets_leadbtag_p4();
	if (ak4pfjets_chf_branch != 0) ak4pfjets_chf();
	if (ak4pfjets_nhf_branch != 0) ak4pfjets_nhf();
	if (ak4pfjets_cef_branch != 0) ak4pfjets_cef();
	if (ak4pfjets_nef_branch != 0) ak4pfjets_nef();
	if (ak4pfjets_muf_branch != 0) ak4pfjets_muf();
	if (ak4pfjets_cm_branch != 0) ak4pfjets_cm();
	if (ak4pfjets_nm_branch != 0) ak4pfjets_nm();
	if (ak4pfjets_mc3dr_branch != 0) ak4pfjets_mc3dr();
	if (ak4pfjets_mc3id_branch != 0) ak4pfjets_mc3id();
	if (ak4pfjets_mc3idx_branch != 0) ak4pfjets_mc3idx();
	if (ak4pfjets_mcmotherid_branch != 0) ak4pfjets_mcmotherid();
	if (ak4pfjet_overlep1_p4_branch != 0) ak4pfjet_overlep1_p4();
	if (ak4pfjet_overlep1_CSV_branch != 0) ak4pfjet_overlep1_CSV();
	if (ak4pfjet_overlep1_pu_id_branch != 0) ak4pfjet_overlep1_pu_id();
	if (ak4pfjet_overlep1_chf_branch != 0) ak4pfjet_overlep1_chf();
	if (ak4pfjet_overlep1_nhf_branch != 0) ak4pfjet_overlep1_nhf();
	if (ak4pfjet_overlep1_cef_branch != 0) ak4pfjet_overlep1_cef();
	if (ak4pfjet_overlep1_nef_branch != 0) ak4pfjet_overlep1_nef();
	if (ak4pfjet_overlep1_muf_branch != 0) ak4pfjet_overlep1_muf();
	if (ak4pfjet_overlep1_cm_branch != 0) ak4pfjet_overlep1_cm();
	if (ak4pfjet_overlep1_nm_branch != 0) ak4pfjet_overlep1_nm();
	if (ak4pfjet_overlep2_p4_branch != 0) ak4pfjet_overlep2_p4();
	if (ak4pfjet_overlep2_CSV_branch != 0) ak4pfjet_overlep2_CSV();
	if (ak4pfjet_overlep2_pu_id_branch != 0) ak4pfjet_overlep2_pu_id();
	if (ak4pfjet_overlep2_chf_branch != 0) ak4pfjet_overlep2_chf();
	if (ak4pfjet_overlep2_nhf_branch != 0) ak4pfjet_overlep2_nhf();
	if (ak4pfjet_overlep2_cef_branch != 0) ak4pfjet_overlep2_cef();
	if (ak4pfjet_overlep2_nef_branch != 0) ak4pfjet_overlep2_nef();
	if (ak4pfjet_overlep2_muf_branch != 0) ak4pfjet_overlep2_muf();
	if (ak4pfjet_overlep2_cm_branch != 0) ak4pfjet_overlep2_cm();
	if (ak4pfjet_overlep2_nm_branch != 0) ak4pfjet_overlep2_nm();
	if (ak8pfjets_p4_branch != 0) ak8pfjets_p4();
	if (ak8pfjets_tau1_branch != 0) ak8pfjets_tau1();
	if (ak8pfjets_tau2_branch != 0) ak8pfjets_tau2();
	if (ak8pfjets_tau3_branch != 0) ak8pfjets_tau3();
	if (ak8pfjets_top_mass_branch != 0) ak8pfjets_top_mass();
	if (ak8pfjets_pruned_mass_branch != 0) ak8pfjets_pruned_mass();
	if (ak8pfjets_trimmed_mass_branch != 0) ak8pfjets_trimmed_mass();
	if (ak8pfjets_filtered_mass_branch != 0) ak8pfjets_filtered_mass();
	if (ak8pfjets_pu_id_branch != 0) ak8pfjets_pu_id();
	if (ak8pfjets_parton_flavor_branch != 0) ak8pfjets_parton_flavor();
	if (ak4genjets_p4_branch != 0) ak4genjets_p4();
	if (tau_IDnames_branch != 0) tau_IDnames();
	if (tau_leadtrack_p4_branch != 0) tau_leadtrack_p4();
	if (tau_leadneutral_p4_branch != 0) tau_leadneutral_p4();
	if (tau_p4_branch != 0) tau_p4();
	if (tau_isocand_p4_branch != 0) tau_isocand_p4();
	if (tau_sigcand_p4_branch != 0) tau_sigcand_p4();
	if (tau_mass_branch != 0) tau_mass();
	if (tau_ID_branch != 0) tau_ID();
	if (tau_passID_branch != 0) tau_passID();
	if (tau_charge_branch != 0) tau_charge();
	if (ngoodtaus_branch != 0) ngoodtaus();
	if (tau_againstMuonTight_branch != 0) tau_againstMuonTight();
	if (tau_againstElectronLoose_branch != 0) tau_againstElectronLoose();
	if (tau_isVetoTau_branch != 0) tau_isVetoTau();
	if (isoTracks_p4_branch != 0) isoTracks_p4();
	if (isoTracks_charge_branch != 0) isoTracks_charge();
	if (isoTracks_absIso_branch != 0) isoTracks_absIso();
	if (isoTracks_dz_branch != 0) isoTracks_dz();
	if (isoTracks_pdgId_branch != 0) isoTracks_pdgId();
	if (isoTracks_selectedidx_branch != 0) isoTracks_selectedidx();
	if (isoTracks_nselected_branch != 0) isoTracks_nselected();
	if (isoTracks_isVetoTrack_branch != 0) isoTracks_isVetoTrack();
	if (isoTracks_isVetoTrack_v2_branch != 0) isoTracks_isVetoTrack_v2();
	if (isoTracks_isVetoTrack_v3_branch != 0) isoTracks_isVetoTrack_v3();
	if (genels_isfromt_branch != 0) genels_isfromt();
	if (genels_p4_branch != 0) genels_p4();
	if (genels_charge_branch != 0) genels_charge();
	if (genels_iso_branch != 0) genels_iso();
	if (genels_mass_branch != 0) genels_mass();
	if (genels_id_branch != 0) genels_id();
	if (genels__genpsidx_branch != 0) genels__genpsidx();
	if (genels_status_branch != 0) genels_status();
	if (genels_fromHardProcessBeforeFSR_branch != 0) genels_fromHardProcessBeforeFSR();
	if (genels_fromHardProcessDecayed_branch != 0) genels_fromHardProcessDecayed();
	if (genels_fromHardProcessFinalState_branch != 0) genels_fromHardProcessFinalState();
	if (genels_isDirectHardProcessTauDecayProductFinalState_branch != 0) genels_isDirectHardProcessTauDecayProductFinalState();
	if (genels_isDirectPromptTauDecayProductFinalState_branch != 0) genels_isDirectPromptTauDecayProductFinalState();
	if (genels_isHardProcess_branch != 0) genels_isHardProcess();
	if (genels_isLastCopy_branch != 0) genels_isLastCopy();
	if (genels_isLastCopyBeforeFSR_branch != 0) genels_isLastCopyBeforeFSR();
	if (genels_isMostlyLikePythia6Status3_branch != 0) genels_isMostlyLikePythia6Status3();
	if (genels_isPromptDecayed_branch != 0) genels_isPromptDecayed();
	if (genels_isPromptFinalState_branch != 0) genels_isPromptFinalState();
	if (genels_lepdaughter_id_branch != 0) genels_lepdaughter_id();
	if (genels_gentaudecay_branch != 0) genels_gentaudecay();
	if (gen_nfromtels__branch != 0) gen_nfromtels_();
	if (genels_motherp4_branch != 0) genels_motherp4();
	if (genels_mothercharge_branch != 0) genels_mothercharge();
	if (genels_motherid_branch != 0) genels_motherid();
	if (genels_motheridx_branch != 0) genels_motheridx();
	if (genels_motherstatus_branch != 0) genels_motherstatus();
	if (genels_gmotherp4_branch != 0) genels_gmotherp4();
	if (genels_gmothercharge_branch != 0) genels_gmothercharge();
	if (genels_gmotherid_branch != 0) genels_gmotherid();
	if (genels_gmotheridx_branch != 0) genels_gmotheridx();
	if (genels_gmotherstatus_branch != 0) genels_gmotherstatus();
	if (genels_simplemotherp4_branch != 0) genels_simplemotherp4();
	if (genels_simplemothercharge_branch != 0) genels_simplemothercharge();
	if (genels_simplemotherid_branch != 0) genels_simplemotherid();
	if (genels_simplemotheridx_branch != 0) genels_simplemotheridx();
	if (genels_simplemotherstatus_branch != 0) genels_simplemotherstatus();
	if (genels_simplegmotherp4_branch != 0) genels_simplegmotherp4();
	if (genels_simplegmothercharge_branch != 0) genels_simplegmothercharge();
	if (genels_simplegmotherid_branch != 0) genels_simplegmotherid();
	if (genels_simplegmotheridx_branch != 0) genels_simplegmotheridx();
	if (genels_simplegmotherstatus_branch != 0) genels_simplegmotherstatus();
	if (genmus_isfromt_branch != 0) genmus_isfromt();
	if (genmus_p4_branch != 0) genmus_p4();
	if (genmus_charge_branch != 0) genmus_charge();
	if (genmus_iso_branch != 0) genmus_iso();
	if (genmus_mass_branch != 0) genmus_mass();
	if (genmus_id_branch != 0) genmus_id();
	if (genmus__genpsidx_branch != 0) genmus__genpsidx();
	if (genmus_status_branch != 0) genmus_status();
	if (genmus_fromHardProcessBeforeFSR_branch != 0) genmus_fromHardProcessBeforeFSR();
	if (genmus_fromHardProcessDecayed_branch != 0) genmus_fromHardProcessDecayed();
	if (genmus_fromHardProcessFinalState_branch != 0) genmus_fromHardProcessFinalState();
	if (genmus_isDirectHardProcessTauDecayProductFinalState_branch != 0) genmus_isDirectHardProcessTauDecayProductFinalState();
	if (genmus_isDirectPromptTauDecayProductFinalState_branch != 0) genmus_isDirectPromptTauDecayProductFinalState();
	if (genmus_isHardProcess_branch != 0) genmus_isHardProcess();
	if (genmus_isLastCopy_branch != 0) genmus_isLastCopy();
	if (genmus_isLastCopyBeforeFSR_branch != 0) genmus_isLastCopyBeforeFSR();
	if (genmus_isMostlyLikePythia6Status3_branch != 0) genmus_isMostlyLikePythia6Status3();
	if (genmus_isPromptDecayed_branch != 0) genmus_isPromptDecayed();
	if (genmus_isPromptFinalState_branch != 0) genmus_isPromptFinalState();
	if (genmus_lepdaughter_id_branch != 0) genmus_lepdaughter_id();
	if (genmus_gentaudecay_branch != 0) genmus_gentaudecay();
	if (gen_nfromtmus__branch != 0) gen_nfromtmus_();
	if (genmus_motherp4_branch != 0) genmus_motherp4();
	if (genmus_mothercharge_branch != 0) genmus_mothercharge();
	if (genmus_motherid_branch != 0) genmus_motherid();
	if (genmus_motheridx_branch != 0) genmus_motheridx();
	if (genmus_motherstatus_branch != 0) genmus_motherstatus();
	if (genmus_gmotherp4_branch != 0) genmus_gmotherp4();
	if (genmus_gmothercharge_branch != 0) genmus_gmothercharge();
	if (genmus_gmotherid_branch != 0) genmus_gmotherid();
	if (genmus_gmotheridx_branch != 0) genmus_gmotheridx();
	if (genmus_gmotherstatus_branch != 0) genmus_gmotherstatus();
	if (genmus_simplemotherp4_branch != 0) genmus_simplemotherp4();
	if (genmus_simplemothercharge_branch != 0) genmus_simplemothercharge();
	if (genmus_simplemotherid_branch != 0) genmus_simplemotherid();
	if (genmus_simplemotheridx_branch != 0) genmus_simplemotheridx();
	if (genmus_simplemotherstatus_branch != 0) genmus_simplemotherstatus();
	if (genmus_simplegmotherp4_branch != 0) genmus_simplegmotherp4();
	if (genmus_simplegmothercharge_branch != 0) genmus_simplegmothercharge();
	if (genmus_simplegmotherid_branch != 0) genmus_simplegmotherid();
	if (genmus_simplegmotheridx_branch != 0) genmus_simplegmotheridx();
	if (genmus_simplegmotherstatus_branch != 0) genmus_simplegmotherstatus();
	if (gentaus_isfromt_branch != 0) gentaus_isfromt();
	if (gentaus_p4_branch != 0) gentaus_p4();
	if (gentaus_charge_branch != 0) gentaus_charge();
	if (gentaus_iso_branch != 0) gentaus_iso();
	if (gentaus_mass_branch != 0) gentaus_mass();
	if (gentaus_id_branch != 0) gentaus_id();
	if (gentaus__genpsidx_branch != 0) gentaus__genpsidx();
	if (gentaus_status_branch != 0) gentaus_status();
	if (gentaus_fromHardProcessBeforeFSR_branch != 0) gentaus_fromHardProcessBeforeFSR();
	if (gentaus_fromHardProcessDecayed_branch != 0) gentaus_fromHardProcessDecayed();
	if (gentaus_fromHardProcessFinalState_branch != 0) gentaus_fromHardProcessFinalState();
	if (gentaus_isDirectHardProcessTauDecayProductFinalState_branch != 0) gentaus_isDirectHardProcessTauDecayProductFinalState();
	if (gentaus_isDirectPromptTauDecayProductFinalState_branch != 0) gentaus_isDirectPromptTauDecayProductFinalState();
	if (gentaus_isHardProcess_branch != 0) gentaus_isHardProcess();
	if (gentaus_isLastCopy_branch != 0) gentaus_isLastCopy();
	if (gentaus_isLastCopyBeforeFSR_branch != 0) gentaus_isLastCopyBeforeFSR();
	if (gentaus_isMostlyLikePythia6Status3_branch != 0) gentaus_isMostlyLikePythia6Status3();
	if (gentaus_isPromptDecayed_branch != 0) gentaus_isPromptDecayed();
	if (gentaus_isPromptFinalState_branch != 0) gentaus_isPromptFinalState();
	if (gentaus_lepdaughter_id_branch != 0) gentaus_lepdaughter_id();
	if (gentaus_gentaudecay_branch != 0) gentaus_gentaudecay();
	if (gen_nfromttaus__branch != 0) gen_nfromttaus_();
	if (gentaus_motherp4_branch != 0) gentaus_motherp4();
	if (gentaus_mothercharge_branch != 0) gentaus_mothercharge();
	if (gentaus_motherid_branch != 0) gentaus_motherid();
	if (gentaus_motheridx_branch != 0) gentaus_motheridx();
	if (gentaus_motherstatus_branch != 0) gentaus_motherstatus();
	if (gentaus_gmotherp4_branch != 0) gentaus_gmotherp4();
	if (gentaus_gmothercharge_branch != 0) gentaus_gmothercharge();
	if (gentaus_gmotherid_branch != 0) gentaus_gmotherid();
	if (gentaus_gmotheridx_branch != 0) gentaus_gmotheridx();
	if (gentaus_gmotherstatus_branch != 0) gentaus_gmotherstatus();
	if (gentaus_simplemotherp4_branch != 0) gentaus_simplemotherp4();
	if (gentaus_simplemothercharge_branch != 0) gentaus_simplemothercharge();
	if (gentaus_simplemotherid_branch != 0) gentaus_simplemotherid();
	if (gentaus_simplemotheridx_branch != 0) gentaus_simplemotheridx();
	if (gentaus_simplemotherstatus_branch != 0) gentaus_simplemotherstatus();
	if (gentaus_simplegmotherp4_branch != 0) gentaus_simplegmotherp4();
	if (gentaus_simplegmothercharge_branch != 0) gentaus_simplegmothercharge();
	if (gentaus_simplegmotherid_branch != 0) gentaus_simplegmotherid();
	if (gentaus_simplegmotheridx_branch != 0) gentaus_simplegmotheridx();
	if (gentaus_simplegmotherstatus_branch != 0) gentaus_simplegmotherstatus();
	if (gennuels_isfromt_branch != 0) gennuels_isfromt();
	if (gennuels_p4_branch != 0) gennuels_p4();
	if (gennuels_charge_branch != 0) gennuels_charge();
	if (gennuels_iso_branch != 0) gennuels_iso();
	if (gennuels_mass_branch != 0) gennuels_mass();
	if (gennuels_id_branch != 0) gennuels_id();
	if (gennuels__genpsidx_branch != 0) gennuels__genpsidx();
	if (gennuels_status_branch != 0) gennuels_status();
	if (gennuels_fromHardProcessBeforeFSR_branch != 0) gennuels_fromHardProcessBeforeFSR();
	if (gennuels_fromHardProcessDecayed_branch != 0) gennuels_fromHardProcessDecayed();
	if (gennuels_fromHardProcessFinalState_branch != 0) gennuels_fromHardProcessFinalState();
	if (gennuels_isDirectHardProcessTauDecayProductFinalState_branch != 0) gennuels_isDirectHardProcessTauDecayProductFinalState();
	if (gennuels_isDirectPromptTauDecayProductFinalState_branch != 0) gennuels_isDirectPromptTauDecayProductFinalState();
	if (gennuels_isHardProcess_branch != 0) gennuels_isHardProcess();
	if (gennuels_isLastCopy_branch != 0) gennuels_isLastCopy();
	if (gennuels_isLastCopyBeforeFSR_branch != 0) gennuels_isLastCopyBeforeFSR();
	if (gennuels_isMostlyLikePythia6Status3_branch != 0) gennuels_isMostlyLikePythia6Status3();
	if (gennuels_isPromptDecayed_branch != 0) gennuels_isPromptDecayed();
	if (gennuels_isPromptFinalState_branch != 0) gennuels_isPromptFinalState();
	if (gennuels_lepdaughter_id_branch != 0) gennuels_lepdaughter_id();
	if (gennuels_gentaudecay_branch != 0) gennuels_gentaudecay();
	if (gen_nfromtnuels__branch != 0) gen_nfromtnuels_();
	if (gennuels_motherp4_branch != 0) gennuels_motherp4();
	if (gennuels_mothercharge_branch != 0) gennuels_mothercharge();
	if (gennuels_motherid_branch != 0) gennuels_motherid();
	if (gennuels_motheridx_branch != 0) gennuels_motheridx();
	if (gennuels_motherstatus_branch != 0) gennuels_motherstatus();
	if (gennuels_gmotherp4_branch != 0) gennuels_gmotherp4();
	if (gennuels_gmothercharge_branch != 0) gennuels_gmothercharge();
	if (gennuels_gmotherid_branch != 0) gennuels_gmotherid();
	if (gennuels_gmotheridx_branch != 0) gennuels_gmotheridx();
	if (gennuels_gmotherstatus_branch != 0) gennuels_gmotherstatus();
	if (gennuels_simplemotherp4_branch != 0) gennuels_simplemotherp4();
	if (gennuels_simplemothercharge_branch != 0) gennuels_simplemothercharge();
	if (gennuels_simplemotherid_branch != 0) gennuels_simplemotherid();
	if (gennuels_simplemotheridx_branch != 0) gennuels_simplemotheridx();
	if (gennuels_simplemotherstatus_branch != 0) gennuels_simplemotherstatus();
	if (gennuels_simplegmotherp4_branch != 0) gennuels_simplegmotherp4();
	if (gennuels_simplegmothercharge_branch != 0) gennuels_simplegmothercharge();
	if (gennuels_simplegmotherid_branch != 0) gennuels_simplegmotherid();
	if (gennuels_simplegmotheridx_branch != 0) gennuels_simplegmotheridx();
	if (gennuels_simplegmotherstatus_branch != 0) gennuels_simplegmotherstatus();
	if (gennumus_isfromt_branch != 0) gennumus_isfromt();
	if (gennumus_p4_branch != 0) gennumus_p4();
	if (gennumus_charge_branch != 0) gennumus_charge();
	if (gennumus_iso_branch != 0) gennumus_iso();
	if (gennumus_mass_branch != 0) gennumus_mass();
	if (gennumus_id_branch != 0) gennumus_id();
	if (gennumus__genpsidx_branch != 0) gennumus__genpsidx();
	if (gennumus_status_branch != 0) gennumus_status();
	if (gennumus_fromHardProcessBeforeFSR_branch != 0) gennumus_fromHardProcessBeforeFSR();
	if (gennumus_fromHardProcessDecayed_branch != 0) gennumus_fromHardProcessDecayed();
	if (gennumus_fromHardProcessFinalState_branch != 0) gennumus_fromHardProcessFinalState();
	if (gennumus_isDirectHardProcessTauDecayProductFinalState_branch != 0) gennumus_isDirectHardProcessTauDecayProductFinalState();
	if (gennumus_isDirectPromptTauDecayProductFinalState_branch != 0) gennumus_isDirectPromptTauDecayProductFinalState();
	if (gennumus_isHardProcess_branch != 0) gennumus_isHardProcess();
	if (gennumus_isLastCopy_branch != 0) gennumus_isLastCopy();
	if (gennumus_isLastCopyBeforeFSR_branch != 0) gennumus_isLastCopyBeforeFSR();
	if (gennumus_isMostlyLikePythia6Status3_branch != 0) gennumus_isMostlyLikePythia6Status3();
	if (gennumus_isPromptDecayed_branch != 0) gennumus_isPromptDecayed();
	if (gennumus_isPromptFinalState_branch != 0) gennumus_isPromptFinalState();
	if (gennumus_lepdaughter_id_branch != 0) gennumus_lepdaughter_id();
	if (gennumus_gentaudecay_branch != 0) gennumus_gentaudecay();
	if (gen_nfromtnumus__branch != 0) gen_nfromtnumus_();
	if (gennumus_motherp4_branch != 0) gennumus_motherp4();
	if (gennumus_mothercharge_branch != 0) gennumus_mothercharge();
	if (gennumus_motherid_branch != 0) gennumus_motherid();
	if (gennumus_motheridx_branch != 0) gennumus_motheridx();
	if (gennumus_motherstatus_branch != 0) gennumus_motherstatus();
	if (gennumus_gmotherp4_branch != 0) gennumus_gmotherp4();
	if (gennumus_gmothercharge_branch != 0) gennumus_gmothercharge();
	if (gennumus_gmotherid_branch != 0) gennumus_gmotherid();
	if (gennumus_gmotheridx_branch != 0) gennumus_gmotheridx();
	if (gennumus_gmotherstatus_branch != 0) gennumus_gmotherstatus();
	if (gennumus_simplemotherp4_branch != 0) gennumus_simplemotherp4();
	if (gennumus_simplemothercharge_branch != 0) gennumus_simplemothercharge();
	if (gennumus_simplemotherid_branch != 0) gennumus_simplemotherid();
	if (gennumus_simplemotheridx_branch != 0) gennumus_simplemotheridx();
	if (gennumus_simplemotherstatus_branch != 0) gennumus_simplemotherstatus();
	if (gennumus_simplegmotherp4_branch != 0) gennumus_simplegmotherp4();
	if (gennumus_simplegmothercharge_branch != 0) gennumus_simplegmothercharge();
	if (gennumus_simplegmotherid_branch != 0) gennumus_simplegmotherid();
	if (gennumus_simplegmotheridx_branch != 0) gennumus_simplegmotheridx();
	if (gennumus_simplegmotherstatus_branch != 0) gennumus_simplegmotherstatus();
	if (gennutaus_isfromt_branch != 0) gennutaus_isfromt();
	if (gennutaus_p4_branch != 0) gennutaus_p4();
	if (gennutaus_charge_branch != 0) gennutaus_charge();
	if (gennutaus_iso_branch != 0) gennutaus_iso();
	if (gennutaus_mass_branch != 0) gennutaus_mass();
	if (gennutaus_id_branch != 0) gennutaus_id();
	if (gennutaus__genpsidx_branch != 0) gennutaus__genpsidx();
	if (gennutaus_status_branch != 0) gennutaus_status();
	if (gennutaus_fromHardProcessBeforeFSR_branch != 0) gennutaus_fromHardProcessBeforeFSR();
	if (gennutaus_fromHardProcessDecayed_branch != 0) gennutaus_fromHardProcessDecayed();
	if (gennutaus_fromHardProcessFinalState_branch != 0) gennutaus_fromHardProcessFinalState();
	if (gennutaus_isDirectHardProcessTauDecayProductFinalState_branch != 0) gennutaus_isDirectHardProcessTauDecayProductFinalState();
	if (gennutaus_isDirectPromptTauDecayProductFinalState_branch != 0) gennutaus_isDirectPromptTauDecayProductFinalState();
	if (gennutaus_isHardProcess_branch != 0) gennutaus_isHardProcess();
	if (gennutaus_isLastCopy_branch != 0) gennutaus_isLastCopy();
	if (gennutaus_isLastCopyBeforeFSR_branch != 0) gennutaus_isLastCopyBeforeFSR();
	if (gennutaus_isMostlyLikePythia6Status3_branch != 0) gennutaus_isMostlyLikePythia6Status3();
	if (gennutaus_isPromptDecayed_branch != 0) gennutaus_isPromptDecayed();
	if (gennutaus_isPromptFinalState_branch != 0) gennutaus_isPromptFinalState();
	if (gennutaus_lepdaughter_id_branch != 0) gennutaus_lepdaughter_id();
	if (gennutaus_gentaudecay_branch != 0) gennutaus_gentaudecay();
	if (gen_nfromtnutaus__branch != 0) gen_nfromtnutaus_();
	if (gennutaus_motherp4_branch != 0) gennutaus_motherp4();
	if (gennutaus_mothercharge_branch != 0) gennutaus_mothercharge();
	if (gennutaus_motherid_branch != 0) gennutaus_motherid();
	if (gennutaus_motheridx_branch != 0) gennutaus_motheridx();
	if (gennutaus_motherstatus_branch != 0) gennutaus_motherstatus();
	if (gennutaus_gmotherp4_branch != 0) gennutaus_gmotherp4();
	if (gennutaus_gmothercharge_branch != 0) gennutaus_gmothercharge();
	if (gennutaus_gmotherid_branch != 0) gennutaus_gmotherid();
	if (gennutaus_gmotheridx_branch != 0) gennutaus_gmotheridx();
	if (gennutaus_gmotherstatus_branch != 0) gennutaus_gmotherstatus();
	if (gennutaus_simplemotherp4_branch != 0) gennutaus_simplemotherp4();
	if (gennutaus_simplemothercharge_branch != 0) gennutaus_simplemothercharge();
	if (gennutaus_simplemotherid_branch != 0) gennutaus_simplemotherid();
	if (gennutaus_simplemotheridx_branch != 0) gennutaus_simplemotheridx();
	if (gennutaus_simplemotherstatus_branch != 0) gennutaus_simplemotherstatus();
	if (gennutaus_simplegmotherp4_branch != 0) gennutaus_simplegmotherp4();
	if (gennutaus_simplegmothercharge_branch != 0) gennutaus_simplegmothercharge();
	if (gennutaus_simplegmotherid_branch != 0) gennutaus_simplegmotherid();
	if (gennutaus_simplegmotheridx_branch != 0) gennutaus_simplegmotheridx();
	if (gennutaus_simplegmotherstatus_branch != 0) gennutaus_simplegmotherstatus();
	if (gents_isfromt_branch != 0) gents_isfromt();
	if (gents_p4_branch != 0) gents_p4();
	if (gents_charge_branch != 0) gents_charge();
	if (gents_iso_branch != 0) gents_iso();
	if (gents_mass_branch != 0) gents_mass();
	if (gents_id_branch != 0) gents_id();
	if (gents__genpsidx_branch != 0) gents__genpsidx();
	if (gents_status_branch != 0) gents_status();
	if (gents_fromHardProcessBeforeFSR_branch != 0) gents_fromHardProcessBeforeFSR();
	if (gents_fromHardProcessDecayed_branch != 0) gents_fromHardProcessDecayed();
	if (gents_fromHardProcessFinalState_branch != 0) gents_fromHardProcessFinalState();
	if (gents_isDirectHardProcessTauDecayProductFinalState_branch != 0) gents_isDirectHardProcessTauDecayProductFinalState();
	if (gents_isDirectPromptTauDecayProductFinalState_branch != 0) gents_isDirectPromptTauDecayProductFinalState();
	if (gents_isHardProcess_branch != 0) gents_isHardProcess();
	if (gents_isLastCopy_branch != 0) gents_isLastCopy();
	if (gents_isLastCopyBeforeFSR_branch != 0) gents_isLastCopyBeforeFSR();
	if (gents_isMostlyLikePythia6Status3_branch != 0) gents_isMostlyLikePythia6Status3();
	if (gents_isPromptDecayed_branch != 0) gents_isPromptDecayed();
	if (gents_isPromptFinalState_branch != 0) gents_isPromptFinalState();
	if (gents_lepdaughter_id_branch != 0) gents_lepdaughter_id();
	if (gents_gentaudecay_branch != 0) gents_gentaudecay();
	if (gen_nfromtts__branch != 0) gen_nfromtts_();
	if (gents_motherp4_branch != 0) gents_motherp4();
	if (gents_mothercharge_branch != 0) gents_mothercharge();
	if (gents_motherid_branch != 0) gents_motherid();
	if (gents_motheridx_branch != 0) gents_motheridx();
	if (gents_motherstatus_branch != 0) gents_motherstatus();
	if (gents_gmotherp4_branch != 0) gents_gmotherp4();
	if (gents_gmothercharge_branch != 0) gents_gmothercharge();
	if (gents_gmotherid_branch != 0) gents_gmotherid();
	if (gents_gmotheridx_branch != 0) gents_gmotheridx();
	if (gents_gmotherstatus_branch != 0) gents_gmotherstatus();
	if (gents_simplemotherp4_branch != 0) gents_simplemotherp4();
	if (gents_simplemothercharge_branch != 0) gents_simplemothercharge();
	if (gents_simplemotherid_branch != 0) gents_simplemotherid();
	if (gents_simplemotheridx_branch != 0) gents_simplemotheridx();
	if (gents_simplemotherstatus_branch != 0) gents_simplemotherstatus();
	if (gents_simplegmotherp4_branch != 0) gents_simplegmotherp4();
	if (gents_simplegmothercharge_branch != 0) gents_simplegmothercharge();
	if (gents_simplegmotherid_branch != 0) gents_simplegmotherid();
	if (gents_simplegmotheridx_branch != 0) gents_simplegmotheridx();
	if (gents_simplegmotherstatus_branch != 0) gents_simplegmotherstatus();
	if (genbs_isfromt_branch != 0) genbs_isfromt();
	if (genbs_p4_branch != 0) genbs_p4();
	if (genbs_charge_branch != 0) genbs_charge();
	if (genbs_iso_branch != 0) genbs_iso();
	if (genbs_mass_branch != 0) genbs_mass();
	if (genbs_id_branch != 0) genbs_id();
	if (genbs__genpsidx_branch != 0) genbs__genpsidx();
	if (genbs_status_branch != 0) genbs_status();
	if (genbs_fromHardProcessBeforeFSR_branch != 0) genbs_fromHardProcessBeforeFSR();
	if (genbs_fromHardProcessDecayed_branch != 0) genbs_fromHardProcessDecayed();
	if (genbs_fromHardProcessFinalState_branch != 0) genbs_fromHardProcessFinalState();
	if (genbs_isDirectHardProcessTauDecayProductFinalState_branch != 0) genbs_isDirectHardProcessTauDecayProductFinalState();
	if (genbs_isDirectPromptTauDecayProductFinalState_branch != 0) genbs_isDirectPromptTauDecayProductFinalState();
	if (genbs_isHardProcess_branch != 0) genbs_isHardProcess();
	if (genbs_isLastCopy_branch != 0) genbs_isLastCopy();
	if (genbs_isLastCopyBeforeFSR_branch != 0) genbs_isLastCopyBeforeFSR();
	if (genbs_isMostlyLikePythia6Status3_branch != 0) genbs_isMostlyLikePythia6Status3();
	if (genbs_isPromptDecayed_branch != 0) genbs_isPromptDecayed();
	if (genbs_isPromptFinalState_branch != 0) genbs_isPromptFinalState();
	if (genbs_lepdaughter_id_branch != 0) genbs_lepdaughter_id();
	if (genbs_gentaudecay_branch != 0) genbs_gentaudecay();
	if (gen_nfromtbs__branch != 0) gen_nfromtbs_();
	if (genbs_motherp4_branch != 0) genbs_motherp4();
	if (genbs_mothercharge_branch != 0) genbs_mothercharge();
	if (genbs_motherid_branch != 0) genbs_motherid();
	if (genbs_motheridx_branch != 0) genbs_motheridx();
	if (genbs_motherstatus_branch != 0) genbs_motherstatus();
	if (genbs_gmotherp4_branch != 0) genbs_gmotherp4();
	if (genbs_gmothercharge_branch != 0) genbs_gmothercharge();
	if (genbs_gmotherid_branch != 0) genbs_gmotherid();
	if (genbs_gmotheridx_branch != 0) genbs_gmotheridx();
	if (genbs_gmotherstatus_branch != 0) genbs_gmotherstatus();
	if (genbs_simplemotherp4_branch != 0) genbs_simplemotherp4();
	if (genbs_simplemothercharge_branch != 0) genbs_simplemothercharge();
	if (genbs_simplemotherid_branch != 0) genbs_simplemotherid();
	if (genbs_simplemotheridx_branch != 0) genbs_simplemotheridx();
	if (genbs_simplemotherstatus_branch != 0) genbs_simplemotherstatus();
	if (genbs_simplegmotherp4_branch != 0) genbs_simplegmotherp4();
	if (genbs_simplegmothercharge_branch != 0) genbs_simplegmothercharge();
	if (genbs_simplegmotherid_branch != 0) genbs_simplegmotherid();
	if (genbs_simplegmotheridx_branch != 0) genbs_simplegmotheridx();
	if (genbs_simplegmotherstatus_branch != 0) genbs_simplegmotherstatus();
	if (gencs_isfromt_branch != 0) gencs_isfromt();
	if (gencs_p4_branch != 0) gencs_p4();
	if (gencs_charge_branch != 0) gencs_charge();
	if (gencs_iso_branch != 0) gencs_iso();
	if (gencs_mass_branch != 0) gencs_mass();
	if (gencs_id_branch != 0) gencs_id();
	if (gencs__genpsidx_branch != 0) gencs__genpsidx();
	if (gencs_status_branch != 0) gencs_status();
	if (gencs_fromHardProcessBeforeFSR_branch != 0) gencs_fromHardProcessBeforeFSR();
	if (gencs_fromHardProcessDecayed_branch != 0) gencs_fromHardProcessDecayed();
	if (gencs_fromHardProcessFinalState_branch != 0) gencs_fromHardProcessFinalState();
	if (gencs_isDirectHardProcessTauDecayProductFinalState_branch != 0) gencs_isDirectHardProcessTauDecayProductFinalState();
	if (gencs_isDirectPromptTauDecayProductFinalState_branch != 0) gencs_isDirectPromptTauDecayProductFinalState();
	if (gencs_isHardProcess_branch != 0) gencs_isHardProcess();
	if (gencs_isLastCopy_branch != 0) gencs_isLastCopy();
	if (gencs_isLastCopyBeforeFSR_branch != 0) gencs_isLastCopyBeforeFSR();
	if (gencs_isMostlyLikePythia6Status3_branch != 0) gencs_isMostlyLikePythia6Status3();
	if (gencs_isPromptDecayed_branch != 0) gencs_isPromptDecayed();
	if (gencs_isPromptFinalState_branch != 0) gencs_isPromptFinalState();
	if (gencs_lepdaughter_id_branch != 0) gencs_lepdaughter_id();
	if (gencs_gentaudecay_branch != 0) gencs_gentaudecay();
	if (gen_nfromtcs__branch != 0) gen_nfromtcs_();
	if (gencs_motherp4_branch != 0) gencs_motherp4();
	if (gencs_mothercharge_branch != 0) gencs_mothercharge();
	if (gencs_motherid_branch != 0) gencs_motherid();
	if (gencs_motheridx_branch != 0) gencs_motheridx();
	if (gencs_motherstatus_branch != 0) gencs_motherstatus();
	if (gencs_gmotherp4_branch != 0) gencs_gmotherp4();
	if (gencs_gmothercharge_branch != 0) gencs_gmothercharge();
	if (gencs_gmotherid_branch != 0) gencs_gmotherid();
	if (gencs_gmotheridx_branch != 0) gencs_gmotheridx();
	if (gencs_gmotherstatus_branch != 0) gencs_gmotherstatus();
	if (gencs_simplemotherp4_branch != 0) gencs_simplemotherp4();
	if (gencs_simplemothercharge_branch != 0) gencs_simplemothercharge();
	if (gencs_simplemotherid_branch != 0) gencs_simplemotherid();
	if (gencs_simplemotheridx_branch != 0) gencs_simplemotheridx();
	if (gencs_simplemotherstatus_branch != 0) gencs_simplemotherstatus();
	if (gencs_simplegmotherp4_branch != 0) gencs_simplegmotherp4();
	if (gencs_simplegmothercharge_branch != 0) gencs_simplegmothercharge();
	if (gencs_simplegmotherid_branch != 0) gencs_simplegmotherid();
	if (gencs_simplegmotheridx_branch != 0) gencs_simplegmotheridx();
	if (gencs_simplegmotherstatus_branch != 0) gencs_simplegmotherstatus();
	if (genqs_isfromt_branch != 0) genqs_isfromt();
	if (genqs_p4_branch != 0) genqs_p4();
	if (genqs_charge_branch != 0) genqs_charge();
	if (genqs_iso_branch != 0) genqs_iso();
	if (genqs_mass_branch != 0) genqs_mass();
	if (genqs_id_branch != 0) genqs_id();
	if (genqs__genpsidx_branch != 0) genqs__genpsidx();
	if (genqs_status_branch != 0) genqs_status();
	if (genqs_fromHardProcessBeforeFSR_branch != 0) genqs_fromHardProcessBeforeFSR();
	if (genqs_fromHardProcessDecayed_branch != 0) genqs_fromHardProcessDecayed();
	if (genqs_fromHardProcessFinalState_branch != 0) genqs_fromHardProcessFinalState();
	if (genqs_isDirectHardProcessTauDecayProductFinalState_branch != 0) genqs_isDirectHardProcessTauDecayProductFinalState();
	if (genqs_isDirectPromptTauDecayProductFinalState_branch != 0) genqs_isDirectPromptTauDecayProductFinalState();
	if (genqs_isHardProcess_branch != 0) genqs_isHardProcess();
	if (genqs_isLastCopy_branch != 0) genqs_isLastCopy();
	if (genqs_isLastCopyBeforeFSR_branch != 0) genqs_isLastCopyBeforeFSR();
	if (genqs_isMostlyLikePythia6Status3_branch != 0) genqs_isMostlyLikePythia6Status3();
	if (genqs_isPromptDecayed_branch != 0) genqs_isPromptDecayed();
	if (genqs_isPromptFinalState_branch != 0) genqs_isPromptFinalState();
	if (genqs_lepdaughter_id_branch != 0) genqs_lepdaughter_id();
	if (genqs_gentaudecay_branch != 0) genqs_gentaudecay();
	if (gen_nfromtqs__branch != 0) gen_nfromtqs_();
	if (genqs_motherp4_branch != 0) genqs_motherp4();
	if (genqs_mothercharge_branch != 0) genqs_mothercharge();
	if (genqs_motherid_branch != 0) genqs_motherid();
	if (genqs_motheridx_branch != 0) genqs_motheridx();
	if (genqs_motherstatus_branch != 0) genqs_motherstatus();
	if (genqs_gmotherp4_branch != 0) genqs_gmotherp4();
	if (genqs_gmothercharge_branch != 0) genqs_gmothercharge();
	if (genqs_gmotherid_branch != 0) genqs_gmotherid();
	if (genqs_gmotheridx_branch != 0) genqs_gmotheridx();
	if (genqs_gmotherstatus_branch != 0) genqs_gmotherstatus();
	if (genqs_simplemotherp4_branch != 0) genqs_simplemotherp4();
	if (genqs_simplemothercharge_branch != 0) genqs_simplemothercharge();
	if (genqs_simplemotherid_branch != 0) genqs_simplemotherid();
	if (genqs_simplemotheridx_branch != 0) genqs_simplemotheridx();
	if (genqs_simplemotherstatus_branch != 0) genqs_simplemotherstatus();
	if (genqs_simplegmotherp4_branch != 0) genqs_simplegmotherp4();
	if (genqs_simplegmothercharge_branch != 0) genqs_simplegmothercharge();
	if (genqs_simplegmotherid_branch != 0) genqs_simplegmotherid();
	if (genqs_simplegmotheridx_branch != 0) genqs_simplegmotheridx();
	if (genqs_simplegmotherstatus_branch != 0) genqs_simplegmotherstatus();
	if (genglus_isfromt_branch != 0) genglus_isfromt();
	if (genglus_p4_branch != 0) genglus_p4();
	if (genglus_charge_branch != 0) genglus_charge();
	if (genglus_iso_branch != 0) genglus_iso();
	if (genglus_mass_branch != 0) genglus_mass();
	if (genglus_id_branch != 0) genglus_id();
	if (genglus__genpsidx_branch != 0) genglus__genpsidx();
	if (genglus_status_branch != 0) genglus_status();
	if (genglus_fromHardProcessBeforeFSR_branch != 0) genglus_fromHardProcessBeforeFSR();
	if (genglus_fromHardProcessDecayed_branch != 0) genglus_fromHardProcessDecayed();
	if (genglus_fromHardProcessFinalState_branch != 0) genglus_fromHardProcessFinalState();
	if (genglus_isDirectHardProcessTauDecayProductFinalState_branch != 0) genglus_isDirectHardProcessTauDecayProductFinalState();
	if (genglus_isDirectPromptTauDecayProductFinalState_branch != 0) genglus_isDirectPromptTauDecayProductFinalState();
	if (genglus_isHardProcess_branch != 0) genglus_isHardProcess();
	if (genglus_isLastCopy_branch != 0) genglus_isLastCopy();
	if (genglus_isLastCopyBeforeFSR_branch != 0) genglus_isLastCopyBeforeFSR();
	if (genglus_isMostlyLikePythia6Status3_branch != 0) genglus_isMostlyLikePythia6Status3();
	if (genglus_isPromptDecayed_branch != 0) genglus_isPromptDecayed();
	if (genglus_isPromptFinalState_branch != 0) genglus_isPromptFinalState();
	if (genglus_lepdaughter_id_branch != 0) genglus_lepdaughter_id();
	if (genglus_gentaudecay_branch != 0) genglus_gentaudecay();
	if (gen_nfromtglus__branch != 0) gen_nfromtglus_();
	if (genglus_motherp4_branch != 0) genglus_motherp4();
	if (genglus_mothercharge_branch != 0) genglus_mothercharge();
	if (genglus_motherid_branch != 0) genglus_motherid();
	if (genglus_motheridx_branch != 0) genglus_motheridx();
	if (genglus_motherstatus_branch != 0) genglus_motherstatus();
	if (genglus_gmotherp4_branch != 0) genglus_gmotherp4();
	if (genglus_gmothercharge_branch != 0) genglus_gmothercharge();
	if (genglus_gmotherid_branch != 0) genglus_gmotherid();
	if (genglus_gmotheridx_branch != 0) genglus_gmotheridx();
	if (genglus_gmotherstatus_branch != 0) genglus_gmotherstatus();
	if (genglus_simplemotherp4_branch != 0) genglus_simplemotherp4();
	if (genglus_simplemothercharge_branch != 0) genglus_simplemothercharge();
	if (genglus_simplemotherid_branch != 0) genglus_simplemotherid();
	if (genglus_simplemotheridx_branch != 0) genglus_simplemotheridx();
	if (genglus_simplemotherstatus_branch != 0) genglus_simplemotherstatus();
	if (genglus_simplegmotherp4_branch != 0) genglus_simplegmotherp4();
	if (genglus_simplegmothercharge_branch != 0) genglus_simplegmothercharge();
	if (genglus_simplegmotherid_branch != 0) genglus_simplegmotherid();
	if (genglus_simplegmotheridx_branch != 0) genglus_simplegmotheridx();
	if (genglus_simplegmotherstatus_branch != 0) genglus_simplegmotherstatus();
	if (genws_isfromt_branch != 0) genws_isfromt();
	if (genws_p4_branch != 0) genws_p4();
	if (genws_charge_branch != 0) genws_charge();
	if (genws_iso_branch != 0) genws_iso();
	if (genws_mass_branch != 0) genws_mass();
	if (genws_id_branch != 0) genws_id();
	if (genws__genpsidx_branch != 0) genws__genpsidx();
	if (genws_status_branch != 0) genws_status();
	if (genws_fromHardProcessBeforeFSR_branch != 0) genws_fromHardProcessBeforeFSR();
	if (genws_fromHardProcessDecayed_branch != 0) genws_fromHardProcessDecayed();
	if (genws_fromHardProcessFinalState_branch != 0) genws_fromHardProcessFinalState();
	if (genws_isDirectHardProcessTauDecayProductFinalState_branch != 0) genws_isDirectHardProcessTauDecayProductFinalState();
	if (genws_isDirectPromptTauDecayProductFinalState_branch != 0) genws_isDirectPromptTauDecayProductFinalState();
	if (genws_isHardProcess_branch != 0) genws_isHardProcess();
	if (genws_isLastCopy_branch != 0) genws_isLastCopy();
	if (genws_isLastCopyBeforeFSR_branch != 0) genws_isLastCopyBeforeFSR();
	if (genws_isMostlyLikePythia6Status3_branch != 0) genws_isMostlyLikePythia6Status3();
	if (genws_isPromptDecayed_branch != 0) genws_isPromptDecayed();
	if (genws_isPromptFinalState_branch != 0) genws_isPromptFinalState();
	if (genws_lepdaughter_id_branch != 0) genws_lepdaughter_id();
	if (genws_gentaudecay_branch != 0) genws_gentaudecay();
	if (gen_nfromtws__branch != 0) gen_nfromtws_();
	if (genws_motherp4_branch != 0) genws_motherp4();
	if (genws_mothercharge_branch != 0) genws_mothercharge();
	if (genws_motherid_branch != 0) genws_motherid();
	if (genws_motheridx_branch != 0) genws_motheridx();
	if (genws_motherstatus_branch != 0) genws_motherstatus();
	if (genws_gmotherp4_branch != 0) genws_gmotherp4();
	if (genws_gmothercharge_branch != 0) genws_gmothercharge();
	if (genws_gmotherid_branch != 0) genws_gmotherid();
	if (genws_gmotheridx_branch != 0) genws_gmotheridx();
	if (genws_gmotherstatus_branch != 0) genws_gmotherstatus();
	if (genws_simplemotherp4_branch != 0) genws_simplemotherp4();
	if (genws_simplemothercharge_branch != 0) genws_simplemothercharge();
	if (genws_simplemotherid_branch != 0) genws_simplemotherid();
	if (genws_simplemotheridx_branch != 0) genws_simplemotheridx();
	if (genws_simplemotherstatus_branch != 0) genws_simplemotherstatus();
	if (genws_simplegmotherp4_branch != 0) genws_simplegmotherp4();
	if (genws_simplegmothercharge_branch != 0) genws_simplegmothercharge();
	if (genws_simplegmotherid_branch != 0) genws_simplegmotherid();
	if (genws_simplegmotheridx_branch != 0) genws_simplegmotheridx();
	if (genws_simplegmotherstatus_branch != 0) genws_simplegmotherstatus();
	if (genzs_isfromt_branch != 0) genzs_isfromt();
	if (genzs_p4_branch != 0) genzs_p4();
	if (genzs_charge_branch != 0) genzs_charge();
	if (genzs_iso_branch != 0) genzs_iso();
	if (genzs_mass_branch != 0) genzs_mass();
	if (genzs_id_branch != 0) genzs_id();
	if (genzs__genpsidx_branch != 0) genzs__genpsidx();
	if (genzs_status_branch != 0) genzs_status();
	if (genzs_fromHardProcessBeforeFSR_branch != 0) genzs_fromHardProcessBeforeFSR();
	if (genzs_fromHardProcessDecayed_branch != 0) genzs_fromHardProcessDecayed();
	if (genzs_fromHardProcessFinalState_branch != 0) genzs_fromHardProcessFinalState();
	if (genzs_isDirectHardProcessTauDecayProductFinalState_branch != 0) genzs_isDirectHardProcessTauDecayProductFinalState();
	if (genzs_isDirectPromptTauDecayProductFinalState_branch != 0) genzs_isDirectPromptTauDecayProductFinalState();
	if (genzs_isHardProcess_branch != 0) genzs_isHardProcess();
	if (genzs_isLastCopy_branch != 0) genzs_isLastCopy();
	if (genzs_isLastCopyBeforeFSR_branch != 0) genzs_isLastCopyBeforeFSR();
	if (genzs_isMostlyLikePythia6Status3_branch != 0) genzs_isMostlyLikePythia6Status3();
	if (genzs_isPromptDecayed_branch != 0) genzs_isPromptDecayed();
	if (genzs_isPromptFinalState_branch != 0) genzs_isPromptFinalState();
	if (genzs_lepdaughter_id_branch != 0) genzs_lepdaughter_id();
	if (genzs_gentaudecay_branch != 0) genzs_gentaudecay();
	if (gen_nfromtzs__branch != 0) gen_nfromtzs_();
	if (genzs_motherp4_branch != 0) genzs_motherp4();
	if (genzs_mothercharge_branch != 0) genzs_mothercharge();
	if (genzs_motherid_branch != 0) genzs_motherid();
	if (genzs_motheridx_branch != 0) genzs_motheridx();
	if (genzs_motherstatus_branch != 0) genzs_motherstatus();
	if (genzs_gmotherp4_branch != 0) genzs_gmotherp4();
	if (genzs_gmothercharge_branch != 0) genzs_gmothercharge();
	if (genzs_gmotherid_branch != 0) genzs_gmotherid();
	if (genzs_gmotheridx_branch != 0) genzs_gmotheridx();
	if (genzs_gmotherstatus_branch != 0) genzs_gmotherstatus();
	if (genzs_simplemotherp4_branch != 0) genzs_simplemotherp4();
	if (genzs_simplemothercharge_branch != 0) genzs_simplemothercharge();
	if (genzs_simplemotherid_branch != 0) genzs_simplemotherid();
	if (genzs_simplemotheridx_branch != 0) genzs_simplemotheridx();
	if (genzs_simplemotherstatus_branch != 0) genzs_simplemotherstatus();
	if (genzs_simplegmotherp4_branch != 0) genzs_simplegmotherp4();
	if (genzs_simplegmothercharge_branch != 0) genzs_simplegmothercharge();
	if (genzs_simplegmotherid_branch != 0) genzs_simplegmotherid();
	if (genzs_simplegmotheridx_branch != 0) genzs_simplegmotheridx();
	if (genzs_simplegmotherstatus_branch != 0) genzs_simplegmotherstatus();
	if (genphs_isfromt_branch != 0) genphs_isfromt();
	if (genphs_p4_branch != 0) genphs_p4();
	if (genphs_charge_branch != 0) genphs_charge();
	if (genphs_iso_branch != 0) genphs_iso();
	if (genphs_mass_branch != 0) genphs_mass();
	if (genphs_id_branch != 0) genphs_id();
	if (genphs__genpsidx_branch != 0) genphs__genpsidx();
	if (genphs_status_branch != 0) genphs_status();
	if (genphs_fromHardProcessBeforeFSR_branch != 0) genphs_fromHardProcessBeforeFSR();
	if (genphs_fromHardProcessDecayed_branch != 0) genphs_fromHardProcessDecayed();
	if (genphs_fromHardProcessFinalState_branch != 0) genphs_fromHardProcessFinalState();
	if (genphs_isDirectHardProcessTauDecayProductFinalState_branch != 0) genphs_isDirectHardProcessTauDecayProductFinalState();
	if (genphs_isDirectPromptTauDecayProductFinalState_branch != 0) genphs_isDirectPromptTauDecayProductFinalState();
	if (genphs_isHardProcess_branch != 0) genphs_isHardProcess();
	if (genphs_isLastCopy_branch != 0) genphs_isLastCopy();
	if (genphs_isLastCopyBeforeFSR_branch != 0) genphs_isLastCopyBeforeFSR();
	if (genphs_isMostlyLikePythia6Status3_branch != 0) genphs_isMostlyLikePythia6Status3();
	if (genphs_isPromptDecayed_branch != 0) genphs_isPromptDecayed();
	if (genphs_isPromptFinalState_branch != 0) genphs_isPromptFinalState();
	if (genphs_lepdaughter_id_branch != 0) genphs_lepdaughter_id();
	if (genphs_gentaudecay_branch != 0) genphs_gentaudecay();
	if (gen_nfromtphs__branch != 0) gen_nfromtphs_();
	if (genphs_motherp4_branch != 0) genphs_motherp4();
	if (genphs_mothercharge_branch != 0) genphs_mothercharge();
	if (genphs_motherid_branch != 0) genphs_motherid();
	if (genphs_motheridx_branch != 0) genphs_motheridx();
	if (genphs_motherstatus_branch != 0) genphs_motherstatus();
	if (genphs_gmotherp4_branch != 0) genphs_gmotherp4();
	if (genphs_gmothercharge_branch != 0) genphs_gmothercharge();
	if (genphs_gmotherid_branch != 0) genphs_gmotherid();
	if (genphs_gmotheridx_branch != 0) genphs_gmotheridx();
	if (genphs_gmotherstatus_branch != 0) genphs_gmotherstatus();
	if (genphs_simplemotherp4_branch != 0) genphs_simplemotherp4();
	if (genphs_simplemothercharge_branch != 0) genphs_simplemothercharge();
	if (genphs_simplemotherid_branch != 0) genphs_simplemotherid();
	if (genphs_simplemotheridx_branch != 0) genphs_simplemotheridx();
	if (genphs_simplemotherstatus_branch != 0) genphs_simplemotherstatus();
	if (genphs_simplegmotherp4_branch != 0) genphs_simplegmotherp4();
	if (genphs_simplegmothercharge_branch != 0) genphs_simplegmothercharge();
	if (genphs_simplegmotherid_branch != 0) genphs_simplegmotherid();
	if (genphs_simplegmotheridx_branch != 0) genphs_simplegmotheridx();
	if (genphs_simplegmotherstatus_branch != 0) genphs_simplegmotherstatus();
	if (genhs_isfromt_branch != 0) genhs_isfromt();
	if (genhs_p4_branch != 0) genhs_p4();
	if (genhs_charge_branch != 0) genhs_charge();
	if (genhs_iso_branch != 0) genhs_iso();
	if (genhs_mass_branch != 0) genhs_mass();
	if (genhs_id_branch != 0) genhs_id();
	if (genhs__genpsidx_branch != 0) genhs__genpsidx();
	if (genhs_status_branch != 0) genhs_status();
	if (genhs_fromHardProcessBeforeFSR_branch != 0) genhs_fromHardProcessBeforeFSR();
	if (genhs_fromHardProcessDecayed_branch != 0) genhs_fromHardProcessDecayed();
	if (genhs_fromHardProcessFinalState_branch != 0) genhs_fromHardProcessFinalState();
	if (genhs_isDirectHardProcessTauDecayProductFinalState_branch != 0) genhs_isDirectHardProcessTauDecayProductFinalState();
	if (genhs_isDirectPromptTauDecayProductFinalState_branch != 0) genhs_isDirectPromptTauDecayProductFinalState();
	if (genhs_isHardProcess_branch != 0) genhs_isHardProcess();
	if (genhs_isLastCopy_branch != 0) genhs_isLastCopy();
	if (genhs_isLastCopyBeforeFSR_branch != 0) genhs_isLastCopyBeforeFSR();
	if (genhs_isMostlyLikePythia6Status3_branch != 0) genhs_isMostlyLikePythia6Status3();
	if (genhs_isPromptDecayed_branch != 0) genhs_isPromptDecayed();
	if (genhs_isPromptFinalState_branch != 0) genhs_isPromptFinalState();
	if (genhs_lepdaughter_id_branch != 0) genhs_lepdaughter_id();
	if (genhs_gentaudecay_branch != 0) genhs_gentaudecay();
	if (gen_nfromths__branch != 0) gen_nfromths_();
	if (genhs_motherp4_branch != 0) genhs_motherp4();
	if (genhs_mothercharge_branch != 0) genhs_mothercharge();
	if (genhs_motherid_branch != 0) genhs_motherid();
	if (genhs_motheridx_branch != 0) genhs_motheridx();
	if (genhs_motherstatus_branch != 0) genhs_motherstatus();
	if (genhs_gmotherp4_branch != 0) genhs_gmotherp4();
	if (genhs_gmothercharge_branch != 0) genhs_gmothercharge();
	if (genhs_gmotherid_branch != 0) genhs_gmotherid();
	if (genhs_gmotheridx_branch != 0) genhs_gmotheridx();
	if (genhs_gmotherstatus_branch != 0) genhs_gmotherstatus();
	if (genhs_simplemotherp4_branch != 0) genhs_simplemotherp4();
	if (genhs_simplemothercharge_branch != 0) genhs_simplemothercharge();
	if (genhs_simplemotherid_branch != 0) genhs_simplemotherid();
	if (genhs_simplemotheridx_branch != 0) genhs_simplemotheridx();
	if (genhs_simplemotherstatus_branch != 0) genhs_simplemotherstatus();
	if (genhs_simplegmotherp4_branch != 0) genhs_simplegmotherp4();
	if (genhs_simplegmothercharge_branch != 0) genhs_simplegmothercharge();
	if (genhs_simplegmotherid_branch != 0) genhs_simplegmotherid();
	if (genhs_simplegmotheridx_branch != 0) genhs_simplegmotheridx();
	if (genhs_simplegmotherstatus_branch != 0) genhs_simplegmotherstatus();
	if (genlsp_isfromt_branch != 0) genlsp_isfromt();
	if (genlsp_p4_branch != 0) genlsp_p4();
	if (genlsp_charge_branch != 0) genlsp_charge();
	if (genlsp_iso_branch != 0) genlsp_iso();
	if (genlsp_mass_branch != 0) genlsp_mass();
	if (genlsp_id_branch != 0) genlsp_id();
	if (genlsp__genpsidx_branch != 0) genlsp__genpsidx();
	if (genlsp_status_branch != 0) genlsp_status();
	if (genlsp_fromHardProcessBeforeFSR_branch != 0) genlsp_fromHardProcessBeforeFSR();
	if (genlsp_fromHardProcessDecayed_branch != 0) genlsp_fromHardProcessDecayed();
	if (genlsp_fromHardProcessFinalState_branch != 0) genlsp_fromHardProcessFinalState();
	if (genlsp_isDirectHardProcessTauDecayProductFinalState_branch != 0) genlsp_isDirectHardProcessTauDecayProductFinalState();
	if (genlsp_isDirectPromptTauDecayProductFinalState_branch != 0) genlsp_isDirectPromptTauDecayProductFinalState();
	if (genlsp_isHardProcess_branch != 0) genlsp_isHardProcess();
	if (genlsp_isLastCopy_branch != 0) genlsp_isLastCopy();
	if (genlsp_isLastCopyBeforeFSR_branch != 0) genlsp_isLastCopyBeforeFSR();
	if (genlsp_isMostlyLikePythia6Status3_branch != 0) genlsp_isMostlyLikePythia6Status3();
	if (genlsp_isPromptDecayed_branch != 0) genlsp_isPromptDecayed();
	if (genlsp_isPromptFinalState_branch != 0) genlsp_isPromptFinalState();
	if (genlsp_lepdaughter_id_branch != 0) genlsp_lepdaughter_id();
	if (genlsp_gentaudecay_branch != 0) genlsp_gentaudecay();
	if (gen_nfromtlsp__branch != 0) gen_nfromtlsp_();
	if (genlsp_motherp4_branch != 0) genlsp_motherp4();
	if (genlsp_mothercharge_branch != 0) genlsp_mothercharge();
	if (genlsp_motherid_branch != 0) genlsp_motherid();
	if (genlsp_motheridx_branch != 0) genlsp_motheridx();
	if (genlsp_motherstatus_branch != 0) genlsp_motherstatus();
	if (genlsp_gmotherp4_branch != 0) genlsp_gmotherp4();
	if (genlsp_gmothercharge_branch != 0) genlsp_gmothercharge();
	if (genlsp_gmotherid_branch != 0) genlsp_gmotherid();
	if (genlsp_gmotheridx_branch != 0) genlsp_gmotheridx();
	if (genlsp_gmotherstatus_branch != 0) genlsp_gmotherstatus();
	if (genlsp_simplemotherp4_branch != 0) genlsp_simplemotherp4();
	if (genlsp_simplemothercharge_branch != 0) genlsp_simplemothercharge();
	if (genlsp_simplemotherid_branch != 0) genlsp_simplemotherid();
	if (genlsp_simplemotheridx_branch != 0) genlsp_simplemotheridx();
	if (genlsp_simplemotherstatus_branch != 0) genlsp_simplemotherstatus();
	if (genlsp_simplegmotherp4_branch != 0) genlsp_simplegmotherp4();
	if (genlsp_simplegmothercharge_branch != 0) genlsp_simplegmothercharge();
	if (genlsp_simplegmotherid_branch != 0) genlsp_simplegmotherid();
	if (genlsp_simplegmotheridx_branch != 0) genlsp_simplegmotheridx();
	if (genlsp_simplegmotherstatus_branch != 0) genlsp_simplegmotherstatus();
	if (genstop_isfromt_branch != 0) genstop_isfromt();
	if (genstop_p4_branch != 0) genstop_p4();
	if (genstop_charge_branch != 0) genstop_charge();
	if (genstop_iso_branch != 0) genstop_iso();
	if (genstop_mass_branch != 0) genstop_mass();
	if (genstop_id_branch != 0) genstop_id();
	if (genstop__genpsidx_branch != 0) genstop__genpsidx();
	if (genstop_status_branch != 0) genstop_status();
	if (genstop_fromHardProcessBeforeFSR_branch != 0) genstop_fromHardProcessBeforeFSR();
	if (genstop_fromHardProcessDecayed_branch != 0) genstop_fromHardProcessDecayed();
	if (genstop_fromHardProcessFinalState_branch != 0) genstop_fromHardProcessFinalState();
	if (genstop_isDirectHardProcessTauDecayProductFinalState_branch != 0) genstop_isDirectHardProcessTauDecayProductFinalState();
	if (genstop_isDirectPromptTauDecayProductFinalState_branch != 0) genstop_isDirectPromptTauDecayProductFinalState();
	if (genstop_isHardProcess_branch != 0) genstop_isHardProcess();
	if (genstop_isLastCopy_branch != 0) genstop_isLastCopy();
	if (genstop_isLastCopyBeforeFSR_branch != 0) genstop_isLastCopyBeforeFSR();
	if (genstop_isMostlyLikePythia6Status3_branch != 0) genstop_isMostlyLikePythia6Status3();
	if (genstop_isPromptDecayed_branch != 0) genstop_isPromptDecayed();
	if (genstop_isPromptFinalState_branch != 0) genstop_isPromptFinalState();
	if (genstop_lepdaughter_id_branch != 0) genstop_lepdaughter_id();
	if (genstop_gentaudecay_branch != 0) genstop_gentaudecay();
	if (gen_nfromtstop__branch != 0) gen_nfromtstop_();
	if (genstop_motherp4_branch != 0) genstop_motherp4();
	if (genstop_mothercharge_branch != 0) genstop_mothercharge();
	if (genstop_motherid_branch != 0) genstop_motherid();
	if (genstop_motheridx_branch != 0) genstop_motheridx();
	if (genstop_motherstatus_branch != 0) genstop_motherstatus();
	if (genstop_gmotherp4_branch != 0) genstop_gmotherp4();
	if (genstop_gmothercharge_branch != 0) genstop_gmothercharge();
	if (genstop_gmotherid_branch != 0) genstop_gmotherid();
	if (genstop_gmotheridx_branch != 0) genstop_gmotheridx();
	if (genstop_gmotherstatus_branch != 0) genstop_gmotherstatus();
	if (genstop_simplemotherp4_branch != 0) genstop_simplemotherp4();
	if (genstop_simplemothercharge_branch != 0) genstop_simplemothercharge();
	if (genstop_simplemotherid_branch != 0) genstop_simplemotherid();
	if (genstop_simplemotheridx_branch != 0) genstop_simplemotheridx();
	if (genstop_simplemotherstatus_branch != 0) genstop_simplemotherstatus();
	if (genstop_simplegmotherp4_branch != 0) genstop_simplegmotherp4();
	if (genstop_simplegmothercharge_branch != 0) genstop_simplegmothercharge();
	if (genstop_simplegmotherid_branch != 0) genstop_simplegmotherid();
	if (genstop_simplegmotheridx_branch != 0) genstop_simplegmotheridx();
	if (genstop_simplegmotherstatus_branch != 0) genstop_simplegmotherstatus();
}

	unsigned int &run()
	{
		if (not run_isLoaded) {
			if (run_branch != 0) {
				run_branch->GetEntry(index);
			} else { 
				printf("branch run_branch does not exist!\n");
				exit(1);
			}
			run_isLoaded = true;
		}
		return run_;
	}
	unsigned int &ls()
	{
		if (not ls_isLoaded) {
			if (ls_branch != 0) {
				ls_branch->GetEntry(index);
			} else { 
				printf("branch ls_branch does not exist!\n");
				exit(1);
			}
			ls_isLoaded = true;
		}
		return ls_;
	}
	unsigned int &evt()
	{
		if (not evt_isLoaded) {
			if (evt_branch != 0) {
				evt_branch->GetEntry(index);
			} else { 
				printf("branch evt_branch does not exist!\n");
				exit(1);
			}
			evt_isLoaded = true;
		}
		return evt_;
	}
	int &nvtxs()
	{
		if (not nvtxs_isLoaded) {
			if (nvtxs_branch != 0) {
				nvtxs_branch->GetEntry(index);
			} else { 
				printf("branch nvtxs_branch does not exist!\n");
				exit(1);
			}
			nvtxs_isLoaded = true;
		}
		return nvtxs_;
	}
	int &firstGoodVtxIdx()
	{
		if (not firstGoodVtxIdx_isLoaded) {
			if (firstGoodVtxIdx_branch != 0) {
				firstGoodVtxIdx_branch->GetEntry(index);
			} else { 
				printf("branch firstGoodVtxIdx_branch does not exist!\n");
				exit(1);
			}
			firstGoodVtxIdx_isLoaded = true;
		}
		return firstGoodVtxIdx_;
	}
	int &firstVtx_isfake()
	{
		if (not firstVtx_isfake_isLoaded) {
			if (firstVtx_isfake_branch != 0) {
				firstVtx_isfake_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_isfake_branch does not exist!\n");
				exit(1);
			}
			firstVtx_isfake_isLoaded = true;
		}
		return firstVtx_isfake_;
	}
	float &firstVtx_ndof()
	{
		if (not firstVtx_ndof_isLoaded) {
			if (firstVtx_ndof_branch != 0) {
				firstVtx_ndof_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_ndof_branch does not exist!\n");
				exit(1);
			}
			firstVtx_ndof_isLoaded = true;
		}
		return firstVtx_ndof_;
	}
	float &firstVtx_posRho()
	{
		if (not firstVtx_posRho_isLoaded) {
			if (firstVtx_posRho_branch != 0) {
				firstVtx_posRho_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posRho_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posRho_isLoaded = true;
		}
		return firstVtx_posRho_;
	}
	float &firstVtx_posZ()
	{
		if (not firstVtx_posZ_isLoaded) {
			if (firstVtx_posZ_branch != 0) {
				firstVtx_posZ_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posZ_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posZ_isLoaded = true;
		}
		return firstVtx_posZ_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &firstVtx_posp4()
	{
		if (not firstVtx_posp4_isLoaded) {
			if (firstVtx_posp4_branch != 0) {
				firstVtx_posp4_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posp4_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posp4_isLoaded = true;
		}
		return *firstVtx_posp4_;
	}
	int &pu_nvtxs()
	{
		if (not pu_nvtxs_isLoaded) {
			if (pu_nvtxs_branch != 0) {
				pu_nvtxs_branch->GetEntry(index);
			} else { 
				printf("branch pu_nvtxs_branch does not exist!\n");
				exit(1);
			}
			pu_nvtxs_isLoaded = true;
		}
		return pu_nvtxs_;
	}
	float &pfmet()
	{
		if (not pfmet_isLoaded) {
			if (pfmet_branch != 0) {
				pfmet_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_branch does not exist!\n");
				exit(1);
			}
			pfmet_isLoaded = true;
		}
		return pfmet_;
	}
	float &pfmet_phi()
	{
		if (not pfmet_phi_isLoaded) {
			if (pfmet_phi_branch != 0) {
				pfmet_phi_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_phi_branch does not exist!\n");
				exit(1);
			}
			pfmet_phi_isLoaded = true;
		}
		return pfmet_phi_;
	}
	float &calomet()
	{
		if (not calomet_isLoaded) {
			if (calomet_branch != 0) {
				calomet_branch->GetEntry(index);
			} else { 
				printf("branch calomet_branch does not exist!\n");
				exit(1);
			}
			calomet_isLoaded = true;
		}
		return calomet_;
	}
	float &calomet_phi()
	{
		if (not calomet_phi_isLoaded) {
			if (calomet_phi_branch != 0) {
				calomet_phi_branch->GetEntry(index);
			} else { 
				printf("branch calomet_phi_branch does not exist!\n");
				exit(1);
			}
			calomet_phi_isLoaded = true;
		}
		return calomet_phi_;
	}
	float &filt_cscbeamhalo()
	{
		if (not filt_cscbeamhalo_isLoaded) {
			if (filt_cscbeamhalo_branch != 0) {
				filt_cscbeamhalo_branch->GetEntry(index);
			} else { 
				printf("branch filt_cscbeamhalo_branch does not exist!\n");
				exit(1);
			}
			filt_cscbeamhalo_isLoaded = true;
		}
		return filt_cscbeamhalo_;
	}
	float &filt_ecallaser()
	{
		if (not filt_ecallaser_isLoaded) {
			if (filt_ecallaser_branch != 0) {
				filt_ecallaser_branch->GetEntry(index);
			} else { 
				printf("branch filt_ecallaser_branch does not exist!\n");
				exit(1);
			}
			filt_ecallaser_isLoaded = true;
		}
		return filt_ecallaser_;
	}
	float &filt_ecaltp()
	{
		if (not filt_ecaltp_isLoaded) {
			if (filt_ecaltp_branch != 0) {
				filt_ecaltp_branch->GetEntry(index);
			} else { 
				printf("branch filt_ecaltp_branch does not exist!\n");
				exit(1);
			}
			filt_ecaltp_isLoaded = true;
		}
		return filt_ecaltp_;
	}
	float &filt_eebadsc()
	{
		if (not filt_eebadsc_isLoaded) {
			if (filt_eebadsc_branch != 0) {
				filt_eebadsc_branch->GetEntry(index);
			} else { 
				printf("branch filt_eebadsc_branch does not exist!\n");
				exit(1);
			}
			filt_eebadsc_isLoaded = true;
		}
		return filt_eebadsc_;
	}
	float &filt_goodvtx()
	{
		if (not filt_goodvtx_isLoaded) {
			if (filt_goodvtx_branch != 0) {
				filt_goodvtx_branch->GetEntry(index);
			} else { 
				printf("branch filt_goodvtx_branch does not exist!\n");
				exit(1);
			}
			filt_goodvtx_isLoaded = true;
		}
		return filt_goodvtx_;
	}
	float &filt_hbhenoise()
	{
		if (not filt_hbhenoise_isLoaded) {
			if (filt_hbhenoise_branch != 0) {
				filt_hbhenoise_branch->GetEntry(index);
			} else { 
				printf("branch filt_hbhenoise_branch does not exist!\n");
				exit(1);
			}
			filt_hbhenoise_isLoaded = true;
		}
		return filt_hbhenoise_;
	}
	float &filt_hcallaser()
	{
		if (not filt_hcallaser_isLoaded) {
			if (filt_hcallaser_branch != 0) {
				filt_hcallaser_branch->GetEntry(index);
			} else { 
				printf("branch filt_hcallaser_branch does not exist!\n");
				exit(1);
			}
			filt_hcallaser_isLoaded = true;
		}
		return filt_hcallaser_;
	}
	float &filt_met()
	{
		if (not filt_met_isLoaded) {
			if (filt_met_branch != 0) {
				filt_met_branch->GetEntry(index);
			} else { 
				printf("branch filt_met_branch does not exist!\n");
				exit(1);
			}
			filt_met_isLoaded = true;
		}
		return filt_met_;
	}
	float &filt_trkfail()
	{
		if (not filt_trkfail_isLoaded) {
			if (filt_trkfail_branch != 0) {
				filt_trkfail_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkfail_branch does not exist!\n");
				exit(1);
			}
			filt_trkfail_isLoaded = true;
		}
		return filt_trkfail_;
	}
	float &filt_trkPOG()
	{
		if (not filt_trkPOG_isLoaded) {
			if (filt_trkPOG_branch != 0) {
				filt_trkPOG_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_isLoaded = true;
		}
		return filt_trkPOG_;
	}
	float &filt_trkPOG_tmc()
	{
		if (not filt_trkPOG_tmc_isLoaded) {
			if (filt_trkPOG_tmc_branch != 0) {
				filt_trkPOG_tmc_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_tmc_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_tmc_isLoaded = true;
		}
		return filt_trkPOG_tmc_;
	}
	float &filt_trkPOG_tms()
	{
		if (not filt_trkPOG_tms_isLoaded) {
			if (filt_trkPOG_tms_branch != 0) {
				filt_trkPOG_tms_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_tms_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_tms_isLoaded = true;
		}
		return filt_trkPOG_tms_;
	}
	float &filt_eff()
	{
		if (not filt_eff_isLoaded) {
			if (filt_eff_branch != 0) {
				filt_eff_branch->GetEntry(index);
			} else { 
				printf("branch filt_eff_branch does not exist!\n");
				exit(1);
			}
			filt_eff_isLoaded = true;
		}
		return filt_eff_;
	}
	float &scale1fb()
	{
		if (not scale1fb_isLoaded) {
			if (scale1fb_branch != 0) {
				scale1fb_branch->GetEntry(index);
			} else { 
				printf("branch scale1fb_branch does not exist!\n");
				exit(1);
			}
			scale1fb_isLoaded = true;
		}
		return scale1fb_;
	}
	float &xsec()
	{
		if (not xsec_isLoaded) {
			if (xsec_branch != 0) {
				xsec_branch->GetEntry(index);
			} else { 
				printf("branch xsec_branch does not exist!\n");
				exit(1);
			}
			xsec_isLoaded = true;
		}
		return xsec_;
	}
	float &kfactor()
	{
		if (not kfactor_isLoaded) {
			if (kfactor_branch != 0) {
				kfactor_branch->GetEntry(index);
			} else { 
				printf("branch kfactor_branch does not exist!\n");
				exit(1);
			}
			kfactor_isLoaded = true;
		}
		return kfactor_;
	}
	float &pu_ntrue()
	{
		if (not pu_ntrue_isLoaded) {
			if (pu_ntrue_branch != 0) {
				pu_ntrue_branch->GetEntry(index);
			} else { 
				printf("branch pu_ntrue_branch does not exist!\n");
				exit(1);
			}
			pu_ntrue_isLoaded = true;
		}
		return pu_ntrue_;
	}
	int &ngoodleps()
	{
		if (not ngoodleps_isLoaded) {
			if (ngoodleps_branch != 0) {
				ngoodleps_branch->GetEntry(index);
			} else { 
				printf("branch ngoodleps_branch does not exist!\n");
				exit(1);
			}
			ngoodleps_isLoaded = true;
		}
		return ngoodleps_;
	}
	int &nvetoleps()
	{
		if (not nvetoleps_isLoaded) {
			if (nvetoleps_branch != 0) {
				nvetoleps_branch->GetEntry(index);
			} else { 
				printf("branch nvetoleps_branch does not exist!\n");
				exit(1);
			}
			nvetoleps_isLoaded = true;
		}
		return nvetoleps_;
	}
	bool &	is_data()
	{
		if (not is_data_isLoaded) {
			if (is_data_branch != 0) {
				is_data_branch->GetEntry(index);
			} else { 
				printf("branch is_data_branch does not exist!\n");
				exit(1);
			}
			is_data_isLoaded = true;
		}
		return is_data_;
	}
	string &dataset()
	{
		if (not dataset_isLoaded) {
			if (dataset_branch != 0) {
				dataset_branch->GetEntry(index);
			} else { 
				printf("branch dataset_branch does not exist!\n");
				exit(1);
			}
			dataset_isLoaded = true;
		}
		return *dataset_;
	}
	string &filename()
	{
		if (not filename_isLoaded) {
			if (filename_branch != 0) {
				filename_branch->GetEntry(index);
			} else { 
				printf("branch filename_branch does not exist!\n");
				exit(1);
			}
			filename_isLoaded = true;
		}
		return *filename_;
	}
	string &cms3tag()
	{
		if (not cms3tag_isLoaded) {
			if (cms3tag_branch != 0) {
				cms3tag_branch->GetEntry(index);
			} else { 
				printf("branch cms3tag_branch does not exist!\n");
				exit(1);
			}
			cms3tag_isLoaded = true;
		}
		return *cms3tag_;
	}
	unsigned int &nEvents()
	{
		if (not nEvents_isLoaded) {
			if (nEvents_branch != 0) {
				nEvents_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_branch does not exist!\n");
				exit(1);
			}
			nEvents_isLoaded = true;
		}
		return nEvents_;
	}
	unsigned int &nEvents_goodvtx()
	{
		if (not nEvents_goodvtx_isLoaded) {
			if (nEvents_goodvtx_branch != 0) {
				nEvents_goodvtx_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_goodvtx_branch does not exist!\n");
				exit(1);
			}
			nEvents_goodvtx_isLoaded = true;
		}
		return nEvents_goodvtx_;
	}
	unsigned int &nEvents_MET30()
	{
		if (not nEvents_MET30_isLoaded) {
			if (nEvents_MET30_branch != 0) {
				nEvents_MET30_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_MET30_branch does not exist!\n");
				exit(1);
			}
			nEvents_MET30_isLoaded = true;
		}
		return nEvents_MET30_;
	}
	unsigned int &nEvents_1goodlep()
	{
		if (not nEvents_1goodlep_isLoaded) {
			if (nEvents_1goodlep_branch != 0) {
				nEvents_1goodlep_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_1goodlep_branch does not exist!\n");
				exit(1);
			}
			nEvents_1goodlep_isLoaded = true;
		}
		return nEvents_1goodlep_;
	}
	unsigned int &nEvents_2goodjets()
	{
		if (not nEvents_2goodjets_isLoaded) {
			if (nEvents_2goodjets_branch != 0) {
				nEvents_2goodjets_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_2goodjets_branch does not exist!\n");
				exit(1);
			}
			nEvents_2goodjets_isLoaded = true;
		}
		return nEvents_2goodjets_;
	}
	int &genlepsfromtop()
	{
		if (not genlepsfromtop_isLoaded) {
			if (genlepsfromtop_branch != 0) {
				genlepsfromtop_branch->GetEntry(index);
			} else { 
				printf("branch genlepsfromtop_branch does not exist!\n");
				exit(1);
			}
			genlepsfromtop_isLoaded = true;
		}
		return genlepsfromtop_;
	}
	float &MT2W()
	{
		if (not MT2W_isLoaded) {
			if (MT2W_branch != 0) {
				MT2W_branch->GetEntry(index);
			} else { 
				printf("branch MT2W_branch does not exist!\n");
				exit(1);
			}
			MT2W_isLoaded = true;
		}
		return MT2W_;
	}
	float &MT2W_lep2()
	{
		if (not MT2W_lep2_isLoaded) {
			if (MT2W_lep2_branch != 0) {
				MT2W_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2W_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2W_lep2_isLoaded = true;
		}
		return MT2W_lep2_;
	}
	float &mindphi_met_j1_j2()
	{
		if (not mindphi_met_j1_j2_isLoaded) {
			if (mindphi_met_j1_j2_branch != 0) {
				mindphi_met_j1_j2_branch->GetEntry(index);
			} else { 
				printf("branch mindphi_met_j1_j2_branch does not exist!\n");
				exit(1);
			}
			mindphi_met_j1_j2_isLoaded = true;
		}
		return mindphi_met_j1_j2_;
	}
	float &mt_met_lep()
	{
		if (not mt_met_lep_isLoaded) {
			if (mt_met_lep_branch != 0) {
				mt_met_lep_branch->GetEntry(index);
			} else { 
				printf("branch mt_met_lep_branch does not exist!\n");
				exit(1);
			}
			mt_met_lep_isLoaded = true;
		}
		return mt_met_lep_;
	}
	float &mt_met_lep2()
	{
		if (not mt_met_lep2_isLoaded) {
			if (mt_met_lep2_branch != 0) {
				mt_met_lep2_branch->GetEntry(index);
			} else { 
				printf("branch mt_met_lep2_branch does not exist!\n");
				exit(1);
			}
			mt_met_lep2_isLoaded = true;
		}
		return mt_met_lep2_;
	}
	float &dR_lep_leadb()
	{
		if (not dR_lep_leadb_isLoaded) {
			if (dR_lep_leadb_branch != 0) {
				dR_lep_leadb_branch->GetEntry(index);
			} else { 
				printf("branch dR_lep_leadb_branch does not exist!\n");
				exit(1);
			}
			dR_lep_leadb_isLoaded = true;
		}
		return dR_lep_leadb_;
	}
	float &dR_lep2_leadb()
	{
		if (not dR_lep2_leadb_isLoaded) {
			if (dR_lep2_leadb_branch != 0) {
				dR_lep2_leadb_branch->GetEntry(index);
			} else { 
				printf("branch dR_lep2_leadb_branch does not exist!\n");
				exit(1);
			}
			dR_lep2_leadb_isLoaded = true;
		}
		return dR_lep2_leadb_;
	}
	float &hadronic_top_chi2()
	{
		if (not hadronic_top_chi2_isLoaded) {
			if (hadronic_top_chi2_branch != 0) {
				hadronic_top_chi2_branch->GetEntry(index);
			} else { 
				printf("branch hadronic_top_chi2_branch does not exist!\n");
				exit(1);
			}
			hadronic_top_chi2_isLoaded = true;
		}
		return hadronic_top_chi2_;
	}
	float &dphi_Wlep()
	{
		if (not dphi_Wlep_isLoaded) {
			if (dphi_Wlep_branch != 0) {
				dphi_Wlep_branch->GetEntry(index);
			} else { 
				printf("branch dphi_Wlep_branch does not exist!\n");
				exit(1);
			}
			dphi_Wlep_isLoaded = true;
		}
		return dphi_Wlep_;
	}
	float &MET_over_sqrtHT()
	{
		if (not MET_over_sqrtHT_isLoaded) {
			if (MET_over_sqrtHT_branch != 0) {
				MET_over_sqrtHT_branch->GetEntry(index);
			} else { 
				printf("branch MET_over_sqrtHT_branch does not exist!\n");
				exit(1);
			}
			MET_over_sqrtHT_isLoaded = true;
		}
		return MET_over_sqrtHT_;
	}
	float &ak4pfjets_rho()
	{
		if (not ak4pfjets_rho_isLoaded) {
			if (ak4pfjets_rho_branch != 0) {
				ak4pfjets_rho_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_rho_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_rho_isLoaded = true;
		}
		return ak4pfjets_rho_;
	}
	const vector<string> &sparms_comment()
	{
		if (not sparms_comment_isLoaded) {
			if (sparms_comment_branch != 0) {
				sparms_comment_branch->GetEntry(index);
			} else { 
				printf("branch sparms_comment_branch does not exist!\n");
				exit(1);
			}
			sparms_comment_isLoaded = true;
		}
		return *sparms_comment_;
	}
	const vector<string> &sparms_names()
	{
		if (not sparms_names_isLoaded) {
			if (sparms_names_branch != 0) {
				sparms_names_branch->GetEntry(index);
			} else { 
				printf("branch sparms_names_branch does not exist!\n");
				exit(1);
			}
			sparms_names_isLoaded = true;
		}
		return *sparms_names_;
	}
	float &sparms_filterEfficiency()
	{
		if (not sparms_filterEfficiency_isLoaded) {
			if (sparms_filterEfficiency_branch != 0) {
				sparms_filterEfficiency_branch->GetEntry(index);
			} else { 
				printf("branch sparms_filterEfficiency_branch does not exist!\n");
				exit(1);
			}
			sparms_filterEfficiency_isLoaded = true;
		}
		return sparms_filterEfficiency_;
	}
	float &sparms_pdfScale()
	{
		if (not sparms_pdfScale_isLoaded) {
			if (sparms_pdfScale_branch != 0) {
				sparms_pdfScale_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfScale_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfScale_isLoaded = true;
		}
		return sparms_pdfScale_;
	}
	float &sparms_pdfWeight1()
	{
		if (not sparms_pdfWeight1_isLoaded) {
			if (sparms_pdfWeight1_branch != 0) {
				sparms_pdfWeight1_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfWeight1_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfWeight1_isLoaded = true;
		}
		return sparms_pdfWeight1_;
	}
	float &sparms_pdfWeight2()
	{
		if (not sparms_pdfWeight2_isLoaded) {
			if (sparms_pdfWeight2_branch != 0) {
				sparms_pdfWeight2_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfWeight2_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfWeight2_isLoaded = true;
		}
		return sparms_pdfWeight2_;
	}
	float &sparms_weight()
	{
		if (not sparms_weight_isLoaded) {
			if (sparms_weight_branch != 0) {
				sparms_weight_branch->GetEntry(index);
			} else { 
				printf("branch sparms_weight_branch does not exist!\n");
				exit(1);
			}
			sparms_weight_isLoaded = true;
		}
		return sparms_weight_;
	}
	float &sparms_xsec()
	{
		if (not sparms_xsec_isLoaded) {
			if (sparms_xsec_branch != 0) {
				sparms_xsec_branch->GetEntry(index);
			} else { 
				printf("branch sparms_xsec_branch does not exist!\n");
				exit(1);
			}
			sparms_xsec_isLoaded = true;
		}
		return sparms_xsec_;
	}
	const vector<float> &sparms_values()
	{
		if (not sparms_values_isLoaded) {
			if (sparms_values_branch != 0) {
				sparms_values_branch->GetEntry(index);
			} else { 
				printf("branch sparms_values_branch does not exist!\n");
				exit(1);
			}
			sparms_values_isLoaded = true;
		}
		return *sparms_values_;
	}
	int &sparms_subProcessId()
	{
		if (not sparms_subProcessId_isLoaded) {
			if (sparms_subProcessId_branch != 0) {
				sparms_subProcessId_branch->GetEntry(index);
			} else { 
				printf("branch sparms_subProcessId_branch does not exist!\n");
				exit(1);
			}
			sparms_subProcessId_isLoaded = true;
		}
		return sparms_subProcessId_;
	}
	float &mass_lsp()
	{
		if (not mass_lsp_isLoaded) {
			if (mass_lsp_branch != 0) {
				mass_lsp_branch->GetEntry(index);
			} else { 
				printf("branch mass_lsp_branch does not exist!\n");
				exit(1);
			}
			mass_lsp_isLoaded = true;
		}
		return mass_lsp_;
	}
	float &mass_chargino()
	{
		if (not mass_chargino_isLoaded) {
			if (mass_chargino_branch != 0) {
				mass_chargino_branch->GetEntry(index);
			} else { 
				printf("branch mass_chargino_branch does not exist!\n");
				exit(1);
			}
			mass_chargino_isLoaded = true;
		}
		return mass_chargino_;
	}
	float &mass_stop()
	{
		if (not mass_stop_isLoaded) {
			if (mass_stop_branch != 0) {
				mass_stop_branch->GetEntry(index);
			} else { 
				printf("branch mass_stop_branch does not exist!\n");
				exit(1);
			}
			mass_stop_isLoaded = true;
		}
		return mass_stop_;
	}
	float &genmet()
	{
		if (not genmet_isLoaded) {
			if (genmet_branch != 0) {
				genmet_branch->GetEntry(index);
			} else { 
				printf("branch genmet_branch does not exist!\n");
				exit(1);
			}
			genmet_isLoaded = true;
		}
		return genmet_;
	}
	float &genmet_phi()
	{
		if (not genmet_phi_isLoaded) {
			if (genmet_phi_branch != 0) {
				genmet_phi_branch->GetEntry(index);
			} else { 
				printf("branch genmet_phi_branch does not exist!\n");
				exit(1);
			}
			genmet_phi_isLoaded = true;
		}
		return genmet_phi_;
	}
	bool &	PassTrackVeto()
	{
		if (not PassTrackVeto_isLoaded) {
			if (PassTrackVeto_branch != 0) {
				PassTrackVeto_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_isLoaded = true;
		}
		return PassTrackVeto_;
	}
	bool &	PassTrackVeto_v2()
	{
		if (not PassTrackVeto_v2_isLoaded) {
			if (PassTrackVeto_v2_branch != 0) {
				PassTrackVeto_v2_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_v2_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_v2_isLoaded = true;
		}
		return PassTrackVeto_v2_;
	}
	bool &	PassTrackVeto_v3()
	{
		if (not PassTrackVeto_v3_isLoaded) {
			if (PassTrackVeto_v3_branch != 0) {
				PassTrackVeto_v3_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_v3_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_v3_isLoaded = true;
		}
		return PassTrackVeto_v3_;
	}
	bool &	PassTauVeto()
	{
		if (not PassTauVeto_isLoaded) {
			if (PassTauVeto_branch != 0) {
				PassTauVeto_branch->GetEntry(index);
			} else { 
				printf("branch PassTauVeto_branch does not exist!\n");
				exit(1);
			}
			PassTauVeto_isLoaded = true;
		}
		return PassTauVeto_;
	}
	float &EA_all_rho()
	{
		if (not EA_all_rho_isLoaded) {
			if (EA_all_rho_branch != 0) {
				EA_all_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_all_rho_branch does not exist!\n");
				exit(1);
			}
			EA_all_rho_isLoaded = true;
		}
		return EA_all_rho_;
	}
	float &EA_allcalo_rho()
	{
		if (not EA_allcalo_rho_isLoaded) {
			if (EA_allcalo_rho_branch != 0) {
				EA_allcalo_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_allcalo_rho_branch does not exist!\n");
				exit(1);
			}
			EA_allcalo_rho_isLoaded = true;
		}
		return EA_allcalo_rho_;
	}
	float &EA_centralcalo_rho()
	{
		if (not EA_centralcalo_rho_isLoaded) {
			if (EA_centralcalo_rho_branch != 0) {
				EA_centralcalo_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralcalo_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralcalo_rho_isLoaded = true;
		}
		return EA_centralcalo_rho_;
	}
	float &EA_centralchargedpileup_rho()
	{
		if (not EA_centralchargedpileup_rho_isLoaded) {
			if (EA_centralchargedpileup_rho_branch != 0) {
				EA_centralchargedpileup_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralchargedpileup_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralchargedpileup_rho_isLoaded = true;
		}
		return EA_centralchargedpileup_rho_;
	}
	float &EA_centralneutral_rho()
	{
		if (not EA_centralneutral_rho_isLoaded) {
			if (EA_centralneutral_rho_branch != 0) {
				EA_centralneutral_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralneutral_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralneutral_rho_isLoaded = true;
		}
		return EA_centralneutral_rho_;
	}
	float &topness()
	{
		if (not topness_isLoaded) {
			if (topness_branch != 0) {
				topness_branch->GetEntry(index);
			} else { 
				printf("branch topness_branch does not exist!\n");
				exit(1);
			}
			topness_isLoaded = true;
		}
		return topness_;
	}
	float &topness_lep2()
	{
		if (not topness_lep2_isLoaded) {
			if (topness_lep2_branch != 0) {
				topness_lep2_branch->GetEntry(index);
			} else { 
				printf("branch topness_lep2_branch does not exist!\n");
				exit(1);
			}
			topness_lep2_isLoaded = true;
		}
		return topness_lep2_;
	}
	float &topnessMod()
	{
		if (not topnessMod_isLoaded) {
			if (topnessMod_branch != 0) {
				topnessMod_branch->GetEntry(index);
			} else { 
				printf("branch topnessMod_branch does not exist!\n");
				exit(1);
			}
			topnessMod_isLoaded = true;
		}
		return topnessMod_;
	}
	float &topnessMod_lep2()
	{
		if (not topnessMod_lep2_isLoaded) {
			if (topnessMod_lep2_branch != 0) {
				topnessMod_lep2_branch->GetEntry(index);
			} else { 
				printf("branch topnessMod_lep2_branch does not exist!\n");
				exit(1);
			}
			topnessMod_lep2_isLoaded = true;
		}
		return topnessMod_lep2_;
	}
	float &MT2_lb_b()
	{
		if (not MT2_lb_b_isLoaded) {
			if (MT2_lb_b_branch != 0) {
				MT2_lb_b_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_isLoaded = true;
		}
		return MT2_lb_b_;
	}
	float &MT2_lb_b_lep2()
	{
		if (not MT2_lb_b_lep2_isLoaded) {
			if (MT2_lb_b_lep2_branch != 0) {
				MT2_lb_b_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_lep2_isLoaded = true;
		}
		return MT2_lb_b_lep2_;
	}
	float &MT2_lb_b_mass()
	{
		if (not MT2_lb_b_mass_isLoaded) {
			if (MT2_lb_b_mass_branch != 0) {
				MT2_lb_b_mass_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_mass_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_mass_isLoaded = true;
		}
		return MT2_lb_b_mass_;
	}
	float &MT2_lb_b_mass_lep2()
	{
		if (not MT2_lb_b_mass_lep2_isLoaded) {
			if (MT2_lb_b_mass_lep2_branch != 0) {
				MT2_lb_b_mass_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_mass_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_mass_lep2_isLoaded = true;
		}
		return MT2_lb_b_mass_lep2_;
	}
	float &MT2_lb_bqq()
	{
		if (not MT2_lb_bqq_isLoaded) {
			if (MT2_lb_bqq_branch != 0) {
				MT2_lb_bqq_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_isLoaded = true;
		}
		return MT2_lb_bqq_;
	}
	float &MT2_lb_bqq_lep2()
	{
		if (not MT2_lb_bqq_lep2_isLoaded) {
			if (MT2_lb_bqq_lep2_branch != 0) {
				MT2_lb_bqq_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_lep2_isLoaded = true;
		}
		return MT2_lb_bqq_lep2_;
	}
	float &MT2_lb_bqq_mass()
	{
		if (not MT2_lb_bqq_mass_isLoaded) {
			if (MT2_lb_bqq_mass_branch != 0) {
				MT2_lb_bqq_mass_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_mass_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_mass_isLoaded = true;
		}
		return MT2_lb_bqq_mass_;
	}
	float &MT2_lb_bqq_mass_lep2()
	{
		if (not MT2_lb_bqq_mass_lep2_isLoaded) {
			if (MT2_lb_bqq_mass_lep2_branch != 0) {
				MT2_lb_bqq_mass_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_mass_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_mass_lep2_isLoaded = true;
		}
		return MT2_lb_bqq_mass_lep2_;
	}
	float &Mlb_closestb()
	{
		if (not Mlb_closestb_isLoaded) {
			if (Mlb_closestb_branch != 0) {
				Mlb_closestb_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_closestb_branch does not exist!\n");
				exit(1);
			}
			Mlb_closestb_isLoaded = true;
		}
		return Mlb_closestb_;
	}
	float &Mlb_lead_bdiscr()
	{
		if (not Mlb_lead_bdiscr_isLoaded) {
			if (Mlb_lead_bdiscr_branch != 0) {
				Mlb_lead_bdiscr_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_lead_bdiscr_branch does not exist!\n");
				exit(1);
			}
			Mlb_lead_bdiscr_isLoaded = true;
		}
		return Mlb_lead_bdiscr_;
	}
	float &Mlb_closestb_lep2()
	{
		if (not Mlb_closestb_lep2_isLoaded) {
			if (Mlb_closestb_lep2_branch != 0) {
				Mlb_closestb_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_closestb_lep2_branch does not exist!\n");
				exit(1);
			}
			Mlb_closestb_lep2_isLoaded = true;
		}
		return Mlb_closestb_lep2_;
	}
	float &Mlb_lead_bdiscr_lep2()
	{
		if (not Mlb_lead_bdiscr_lep2_isLoaded) {
			if (Mlb_lead_bdiscr_lep2_branch != 0) {
				Mlb_lead_bdiscr_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_lead_bdiscr_lep2_branch does not exist!\n");
				exit(1);
			}
			Mlb_lead_bdiscr_lep2_isLoaded = true;
		}
		return Mlb_lead_bdiscr_lep2_;
	}
	float &Mjjj()
	{
		if (not Mjjj_isLoaded) {
			if (Mjjj_branch != 0) {
				Mjjj_branch->GetEntry(index);
			} else { 
				printf("branch Mjjj_branch does not exist!\n");
				exit(1);
			}
			Mjjj_isLoaded = true;
		}
		return Mjjj_;
	}
	float &Mjjj_lep2()
	{
		if (not Mjjj_lep2_isLoaded) {
			if (Mjjj_lep2_branch != 0) {
				Mjjj_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mjjj_lep2_branch does not exist!\n");
				exit(1);
			}
			Mjjj_lep2_isLoaded = true;
		}
		return Mjjj_lep2_;
	}
	int &HLT_SingleEl()
	{
		if (not HLT_SingleEl_isLoaded) {
			if (HLT_SingleEl_branch != 0) {
				HLT_SingleEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl_isLoaded = true;
		}
		return HLT_SingleEl_;
	}
	int &HLT_SingleMu()
	{
		if (not HLT_SingleMu_isLoaded) {
			if (HLT_SingleMu_branch != 0) {
				HLT_SingleMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu_isLoaded = true;
		}
		return HLT_SingleMu_;
	}
	int &HLT_MET170()
	{
		if (not HLT_MET170_isLoaded) {
			if (HLT_MET170_branch != 0) {
				HLT_MET170_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET170_branch does not exist!\n");
				exit(1);
			}
			HLT_MET170_isLoaded = true;
		}
		return HLT_MET170_;
	}
	int &HLT_MET120Btag()
	{
		if (not HLT_MET120Btag_isLoaded) {
			if (HLT_MET120Btag_branch != 0) {
				HLT_MET120Btag_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET120Btag_branch does not exist!\n");
				exit(1);
			}
			HLT_MET120Btag_isLoaded = true;
		}
		return HLT_MET120Btag_;
	}
	int &HLT_MET120Mu5()
	{
		if (not HLT_MET120Mu5_isLoaded) {
			if (HLT_MET120Mu5_branch != 0) {
				HLT_MET120Mu5_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET120Mu5_branch does not exist!\n");
				exit(1);
			}
			HLT_MET120Mu5_isLoaded = true;
		}
		return HLT_MET120Mu5_;
	}
	int &HLT_HT350MET120()
	{
		if (not HLT_HT350MET120_isLoaded) {
			if (HLT_HT350MET120_branch != 0) {
				HLT_HT350MET120_branch->GetEntry(index);
			} else { 
				printf("branch HLT_HT350MET120_branch does not exist!\n");
				exit(1);
			}
			HLT_HT350MET120_isLoaded = true;
		}
		return HLT_HT350MET120_;
	}
	int &HLT_DiEl()
	{
		if (not HLT_DiEl_isLoaded) {
			if (HLT_DiEl_branch != 0) {
				HLT_DiEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiEl_branch does not exist!\n");
				exit(1);
			}
			HLT_DiEl_isLoaded = true;
		}
		return HLT_DiEl_;
	}
	int &HLT_DiMu()
	{
		if (not HLT_DiMu_isLoaded) {
			if (HLT_DiMu_branch != 0) {
				HLT_DiMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiMu_branch does not exist!\n");
				exit(1);
			}
			HLT_DiMu_isLoaded = true;
		}
		return HLT_DiMu_;
	}
	int &HLT_Mu8El17()
	{
		if (not HLT_Mu8El17_isLoaded) {
			if (HLT_Mu8El17_branch != 0) {
				HLT_Mu8El17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8El17_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8El17_isLoaded = true;
		}
		return HLT_Mu8El17_;
	}
	int &HLT_Mu8El23()
	{
		if (not HLT_Mu8El23_isLoaded) {
			if (HLT_Mu8El23_branch != 0) {
				HLT_Mu8El23_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8El23_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8El23_isLoaded = true;
		}
		return HLT_Mu8El23_;
	}
	int &HLT_Mu17El12()
	{
		if (not HLT_Mu17El12_isLoaded) {
			if (HLT_Mu17El12_branch != 0) {
				HLT_Mu17El12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17El12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17El12_isLoaded = true;
		}
		return HLT_Mu17El12_;
	}
	int &HLT_Mu23El12()
	{
		if (not HLT_Mu23El12_isLoaded) {
			if (HLT_Mu23El12_branch != 0) {
				HLT_Mu23El12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23El12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23El12_isLoaded = true;
		}
		return HLT_Mu23El12_;
	}
	int &HLT_SingleEl27()
	{
		if (not HLT_SingleEl27_isLoaded) {
			if (HLT_SingleEl27_branch != 0) {
				HLT_SingleEl27_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl27_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl27_isLoaded = true;
		}
		return HLT_SingleEl27_;
	}
	int &HLT_SingleEl27Tight()
	{
		if (not HLT_SingleEl27Tight_isLoaded) {
			if (HLT_SingleEl27Tight_branch != 0) {
				HLT_SingleEl27Tight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl27Tight_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl27Tight_isLoaded = true;
		}
		return HLT_SingleEl27Tight_;
	}
	int &HLT_SingleElTight()
	{
		if (not HLT_SingleElTight_isLoaded) {
			if (HLT_SingleElTight_branch != 0) {
				HLT_SingleElTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleElTight_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleElTight_isLoaded = true;
		}
		return HLT_SingleElTight_;
	}
	int &HLT_SingleElHT200()
	{
		if (not HLT_SingleElHT200_isLoaded) {
			if (HLT_SingleElHT200_branch != 0) {
				HLT_SingleElHT200_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleElHT200_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleElHT200_isLoaded = true;
		}
		return HLT_SingleElHT200_;
	}
	int &HLT_SingleMuNoEta()
	{
		if (not HLT_SingleMuNoEta_isLoaded) {
			if (HLT_SingleMuNoEta_branch != 0) {
				HLT_SingleMuNoEta_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoEta_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoEta_isLoaded = true;
		}
		return HLT_SingleMuNoEta_;
	}
	int &HLT_SingleMuNoIso()
	{
		if (not HLT_SingleMuNoIso_isLoaded) {
			if (HLT_SingleMuNoIso_branch != 0) {
				HLT_SingleMuNoIso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoIso_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoIso_isLoaded = true;
		}
		return HLT_SingleMuNoIso_;
	}
	int &HLT_SingleMuNoIsoNoEta()
	{
		if (not HLT_SingleMuNoIsoNoEta_isLoaded) {
			if (HLT_SingleMuNoIsoNoEta_branch != 0) {
				HLT_SingleMuNoIsoNoEta_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoIsoNoEta_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoIsoNoEta_isLoaded = true;
		}
		return HLT_SingleMuNoIsoNoEta_;
	}
	int &HLT_Mu6HT200MET100()
	{
		if (not HLT_Mu6HT200MET100_isLoaded) {
			if (HLT_Mu6HT200MET100_branch != 0) {
				HLT_Mu6HT200MET100_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu6HT200MET100_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu6HT200MET100_isLoaded = true;
		}
		return HLT_Mu6HT200MET100_;
	}
	int &HLT_HT350MET100()
	{
		if (not HLT_HT350MET100_isLoaded) {
			if (HLT_HT350MET100_branch != 0) {
				HLT_HT350MET100_branch->GetEntry(index);
			} else { 
				printf("branch HLT_HT350MET100_branch does not exist!\n");
				exit(1);
			}
			HLT_HT350MET100_isLoaded = true;
		}
		return HLT_HT350MET100_;
	}
	int &HLT_SingleMu17()
	{
		if (not HLT_SingleMu17_isLoaded) {
			if (HLT_SingleMu17_branch != 0) {
				HLT_SingleMu17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu17_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu17_isLoaded = true;
		}
		return HLT_SingleMu17_;
	}
	int &HLT_SingleMu20()
	{
		if (not HLT_SingleMu20_isLoaded) {
			if (HLT_SingleMu20_branch != 0) {
				HLT_SingleMu20_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu20_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu20_isLoaded = true;
		}
		return HLT_SingleMu20_;
	}
	int &HLT_SingleMu24()
	{
		if (not HLT_SingleMu24_isLoaded) {
			if (HLT_SingleMu24_branch != 0) {
				HLT_SingleMu24_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu24_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu24_isLoaded = true;
		}
		return HLT_SingleMu24_;
	}
	int &HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight()
	{
		if (not HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded) {
			if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch != 0) {
				HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded = true;
		}
		return HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_;
	}
	int &HLT_MET90_MHT90_IDTight()
	{
		if (not HLT_MET90_MHT90_IDTight_isLoaded) {
			if (HLT_MET90_MHT90_IDTight_branch != 0) {
				HLT_MET90_MHT90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET90_MHT90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_MET90_MHT90_IDTight_isLoaded = true;
		}
		return HLT_MET90_MHT90_IDTight_;
	}
	int &HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight()
	{
		if (not HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded) {
			if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch != 0) {
				HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded = true;
		}
		return HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_;
	}
	float &pu_weight()
	{
		if (not pu_weight_isLoaded) {
			if (pu_weight_branch != 0) {
				pu_weight_branch->GetEntry(index);
			} else { 
				printf("branch pu_weight_branch does not exist!\n");
				exit(1);
			}
			pu_weight_isLoaded = true;
		}
		return pu_weight_;
	}
	float &lep_sf()
	{
		if (not lep_sf_isLoaded) {
			if (lep_sf_branch != 0) {
				lep_sf_branch->GetEntry(index);
			} else { 
				printf("branch lep_sf_branch does not exist!\n");
				exit(1);
			}
			lep_sf_isLoaded = true;
		}
		return lep_sf_;
	}
	float &btag_sf()
	{
		if (not btag_sf_isLoaded) {
			if (btag_sf_branch != 0) {
				btag_sf_branch->GetEntry(index);
			} else { 
				printf("branch btag_sf_branch does not exist!\n");
				exit(1);
			}
			btag_sf_isLoaded = true;
		}
		return btag_sf_;
	}
	float &HLT_SingleEl_eff()
	{
		if (not HLT_SingleEl_eff_isLoaded) {
			if (HLT_SingleEl_eff_branch != 0) {
				HLT_SingleEl_eff_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl_eff_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl_eff_isLoaded = true;
		}
		return HLT_SingleEl_eff_;
	}
	float &HLT_SingleMu_eff()
	{
		if (not HLT_SingleMu_eff_isLoaded) {
			if (HLT_SingleMu_eff_branch != 0) {
				HLT_SingleMu_eff_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu_eff_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu_eff_isLoaded = true;
		}
		return HLT_SingleMu_eff_;
	}
	bool &	lep1_is_mu()
	{
		if (not lep1_is_mu_isLoaded) {
			if (lep1_is_mu_branch != 0) {
				lep1_is_mu_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_mu_branch does not exist!\n");
				exit(1);
			}
			lep1_is_mu_isLoaded = true;
		}
		return lep1_is_mu_;
	}
	bool &	lep1_is_el()
	{
		if (not lep1_is_el_isLoaded) {
			if (lep1_is_el_branch != 0) {
				lep1_is_el_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_el_branch does not exist!\n");
				exit(1);
			}
			lep1_is_el_isLoaded = true;
		}
		return lep1_is_el_;
	}
	int &lep1_charge()
	{
		if (not lep1_charge_isLoaded) {
			if (lep1_charge_branch != 0) {
				lep1_charge_branch->GetEntry(index);
			} else { 
				printf("branch lep1_charge_branch does not exist!\n");
				exit(1);
			}
			lep1_charge_isLoaded = true;
		}
		return lep1_charge_;
	}
	int &lep1_pdgid()
	{
		if (not lep1_pdgid_isLoaded) {
			if (lep1_pdgid_branch != 0) {
				lep1_pdgid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_pdgid_branch does not exist!\n");
				exit(1);
			}
			lep1_pdgid_isLoaded = true;
		}
		return lep1_pdgid_;
	}
	int &lep1_type()
	{
		if (not lep1_type_isLoaded) {
			if (lep1_type_branch != 0) {
				lep1_type_branch->GetEntry(index);
			} else { 
				printf("branch lep1_type_branch does not exist!\n");
				exit(1);
			}
			lep1_type_isLoaded = true;
		}
		return lep1_type_;
	}
	int &lep1_production_type()
	{
		if (not lep1_production_type_isLoaded) {
			if (lep1_production_type_branch != 0) {
				lep1_production_type_branch->GetEntry(index);
			} else { 
				printf("branch lep1_production_type_branch does not exist!\n");
				exit(1);
			}
			lep1_production_type_isLoaded = true;
		}
		return lep1_production_type_;
	}
	float &lep1_d0()
	{
		if (not lep1_d0_isLoaded) {
			if (lep1_d0_branch != 0) {
				lep1_d0_branch->GetEntry(index);
			} else { 
				printf("branch lep1_d0_branch does not exist!\n");
				exit(1);
			}
			lep1_d0_isLoaded = true;
		}
		return lep1_d0_;
	}
	float &lep1_d0err()
	{
		if (not lep1_d0err_isLoaded) {
			if (lep1_d0err_branch != 0) {
				lep1_d0err_branch->GetEntry(index);
			} else { 
				printf("branch lep1_d0err_branch does not exist!\n");
				exit(1);
			}
			lep1_d0err_isLoaded = true;
		}
		return lep1_d0err_;
	}
	float &lep1_dz()
	{
		if (not lep1_dz_isLoaded) {
			if (lep1_dz_branch != 0) {
				lep1_dz_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dz_branch does not exist!\n");
				exit(1);
			}
			lep1_dz_isLoaded = true;
		}
		return lep1_dz_;
	}
	float &lep1_dzerr()
	{
		if (not lep1_dzerr_isLoaded) {
			if (lep1_dzerr_branch != 0) {
				lep1_dzerr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dzerr_branch does not exist!\n");
				exit(1);
			}
			lep1_dzerr_isLoaded = true;
		}
		return lep1_dzerr_;
	}
	float &lep1_sigmaIEtaEta_fill5x5()
	{
		if (not lep1_sigmaIEtaEta_fill5x5_isLoaded) {
			if (lep1_sigmaIEtaEta_fill5x5_branch != 0) {
				lep1_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
			} else { 
				printf("branch lep1_sigmaIEtaEta_fill5x5_branch does not exist!\n");
				exit(1);
			}
			lep1_sigmaIEtaEta_fill5x5_isLoaded = true;
		}
		return lep1_sigmaIEtaEta_fill5x5_;
	}
	float &lep1_dEtaIn()
	{
		if (not lep1_dEtaIn_isLoaded) {
			if (lep1_dEtaIn_branch != 0) {
				lep1_dEtaIn_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dEtaIn_branch does not exist!\n");
				exit(1);
			}
			lep1_dEtaIn_isLoaded = true;
		}
		return lep1_dEtaIn_;
	}
	float &lep1_dPhiIn()
	{
		if (not lep1_dPhiIn_isLoaded) {
			if (lep1_dPhiIn_branch != 0) {
				lep1_dPhiIn_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dPhiIn_branch does not exist!\n");
				exit(1);
			}
			lep1_dPhiIn_isLoaded = true;
		}
		return lep1_dPhiIn_;
	}
	float &lep1_hOverE()
	{
		if (not lep1_hOverE_isLoaded) {
			if (lep1_hOverE_branch != 0) {
				lep1_hOverE_branch->GetEntry(index);
			} else { 
				printf("branch lep1_hOverE_branch does not exist!\n");
				exit(1);
			}
			lep1_hOverE_isLoaded = true;
		}
		return lep1_hOverE_;
	}
	float &lep1_ooEmooP()
	{
		if (not lep1_ooEmooP_isLoaded) {
			if (lep1_ooEmooP_branch != 0) {
				lep1_ooEmooP_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ooEmooP_branch does not exist!\n");
				exit(1);
			}
			lep1_ooEmooP_isLoaded = true;
		}
		return lep1_ooEmooP_;
	}
	int &lep1_expectedMissingInnerHits()
	{
		if (not lep1_expectedMissingInnerHits_isLoaded) {
			if (lep1_expectedMissingInnerHits_branch != 0) {
				lep1_expectedMissingInnerHits_branch->GetEntry(index);
			} else { 
				printf("branch lep1_expectedMissingInnerHits_branch does not exist!\n");
				exit(1);
			}
			lep1_expectedMissingInnerHits_isLoaded = true;
		}
		return lep1_expectedMissingInnerHits_;
	}
	bool &	lep1_conversionVeto()
	{
		if (not lep1_conversionVeto_isLoaded) {
			if (lep1_conversionVeto_branch != 0) {
				lep1_conversionVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep1_conversionVeto_branch does not exist!\n");
				exit(1);
			}
			lep1_conversionVeto_isLoaded = true;
		}
		return lep1_conversionVeto_;
	}
	float &lep1_etaSC()
	{
		if (not lep1_etaSC_isLoaded) {
			if (lep1_etaSC_branch != 0) {
				lep1_etaSC_branch->GetEntry(index);
			} else { 
				printf("branch lep1_etaSC_branch does not exist!\n");
				exit(1);
			}
			lep1_etaSC_isLoaded = true;
		}
		return lep1_etaSC_;
	}
	float &lep1_ChiSqr()
	{
		if (not lep1_ChiSqr_isLoaded) {
			if (lep1_ChiSqr_branch != 0) {
				lep1_ChiSqr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ChiSqr_branch does not exist!\n");
				exit(1);
			}
			lep1_ChiSqr_isLoaded = true;
		}
		return lep1_ChiSqr_;
	}
	float &lep1_chiso()
	{
		if (not lep1_chiso_isLoaded) {
			if (lep1_chiso_branch != 0) {
				lep1_chiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_chiso_branch does not exist!\n");
				exit(1);
			}
			lep1_chiso_isLoaded = true;
		}
		return lep1_chiso_;
	}
	float &lep1_nhiso()
	{
		if (not lep1_nhiso_isLoaded) {
			if (lep1_nhiso_branch != 0) {
				lep1_nhiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_nhiso_branch does not exist!\n");
				exit(1);
			}
			lep1_nhiso_isLoaded = true;
		}
		return lep1_nhiso_;
	}
	float &lep1_emiso()
	{
		if (not lep1_emiso_isLoaded) {
			if (lep1_emiso_branch != 0) {
				lep1_emiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_emiso_branch does not exist!\n");
				exit(1);
			}
			lep1_emiso_isLoaded = true;
		}
		return lep1_emiso_;
	}
	float &lep1_deltaBeta()
	{
		if (not lep1_deltaBeta_isLoaded) {
			if (lep1_deltaBeta_branch != 0) {
				lep1_deltaBeta_branch->GetEntry(index);
			} else { 
				printf("branch lep1_deltaBeta_branch does not exist!\n");
				exit(1);
			}
			lep1_deltaBeta_isLoaded = true;
		}
		return lep1_deltaBeta_;
	}
	float &lep1_relIso03DB()
	{
		if (not lep1_relIso03DB_isLoaded) {
			if (lep1_relIso03DB_branch != 0) {
				lep1_relIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso03DB_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso03DB_isLoaded = true;
		}
		return lep1_relIso03DB_;
	}
	float &lep1_relIso03EA()
	{
		if (not lep1_relIso03EA_isLoaded) {
			if (lep1_relIso03EA_branch != 0) {
				lep1_relIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso03EA_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso03EA_isLoaded = true;
		}
		return lep1_relIso03EA_;
	}
	float &lep1_relIso04DB()
	{
		if (not lep1_relIso04DB_isLoaded) {
			if (lep1_relIso04DB_branch != 0) {
				lep1_relIso04DB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso04DB_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso04DB_isLoaded = true;
		}
		return lep1_relIso04DB_;
	}
	float &lep1_miniRelIsoDB()
	{
		if (not lep1_miniRelIsoDB_isLoaded) {
			if (lep1_miniRelIsoDB_branch != 0) {
				lep1_miniRelIsoDB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_miniRelIsoDB_branch does not exist!\n");
				exit(1);
			}
			lep1_miniRelIsoDB_isLoaded = true;
		}
		return lep1_miniRelIsoDB_;
	}
	float &lep1_miniRelIsoEA()
	{
		if (not lep1_miniRelIsoEA_isLoaded) {
			if (lep1_miniRelIsoEA_branch != 0) {
				lep1_miniRelIsoEA_branch->GetEntry(index);
			} else { 
				printf("branch lep1_miniRelIsoEA_branch does not exist!\n");
				exit(1);
			}
			lep1_miniRelIsoEA_isLoaded = true;
		}
		return lep1_miniRelIsoEA_;
	}
	float &lep1_MiniIso()
	{
		if (not lep1_MiniIso_isLoaded) {
			if (lep1_MiniIso_branch != 0) {
				lep1_MiniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_MiniIso_branch does not exist!\n");
				exit(1);
			}
			lep1_MiniIso_isLoaded = true;
		}
		return lep1_MiniIso_;
	}
	int &lep1_mcid()
	{
		if (not lep1_mcid_isLoaded) {
			if (lep1_mcid_branch != 0) {
				lep1_mcid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcid_branch does not exist!\n");
				exit(1);
			}
			lep1_mcid_isLoaded = true;
		}
		return lep1_mcid_;
	}
	int &lep1_mcstatus()
	{
		if (not lep1_mcstatus_isLoaded) {
			if (lep1_mcstatus_branch != 0) {
				lep1_mcstatus_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcstatus_branch does not exist!\n");
				exit(1);
			}
			lep1_mcstatus_isLoaded = true;
		}
		return lep1_mcstatus_;
	}
	int &lep1_mc3dr()
	{
		if (not lep1_mc3dr_isLoaded) {
			if (lep1_mc3dr_branch != 0) {
				lep1_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3dr_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3dr_isLoaded = true;
		}
		return lep1_mc3dr_;
	}
	int &lep1_mc3id()
	{
		if (not lep1_mc3id_isLoaded) {
			if (lep1_mc3id_branch != 0) {
				lep1_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3id_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3id_isLoaded = true;
		}
		return lep1_mc3id_;
	}
	int &lep1_mc3idx()
	{
		if (not lep1_mc3idx_isLoaded) {
			if (lep1_mc3idx_branch != 0) {
				lep1_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3idx_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3idx_isLoaded = true;
		}
		return lep1_mc3idx_;
	}
	int &lep1_mc3motherid()
	{
		if (not lep1_mc3motherid_isLoaded) {
			if (lep1_mc3motherid_branch != 0) {
				lep1_mc3motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3motherid_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3motherid_isLoaded = true;
		}
		return lep1_mc3motherid_;
	}
	int &lep1_mc3motheridx()
	{
		if (not lep1_mc3motheridx_isLoaded) {
			if (lep1_mc3motheridx_branch != 0) {
				lep1_mc3motheridx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3motheridx_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3motheridx_isLoaded = true;
		}
		return lep1_mc3motheridx_;
	}
	bool &	lep1_is_eleid_loose()
	{
		if (not lep1_is_eleid_loose_isLoaded) {
			if (lep1_is_eleid_loose_branch != 0) {
				lep1_is_eleid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_loose_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_loose_isLoaded = true;
		}
		return lep1_is_eleid_loose_;
	}
	bool &	lep1_is_eleid_medium()
	{
		if (not lep1_is_eleid_medium_isLoaded) {
			if (lep1_is_eleid_medium_branch != 0) {
				lep1_is_eleid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_medium_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_medium_isLoaded = true;
		}
		return lep1_is_eleid_medium_;
	}
	bool &	lep1_is_eleid_tight()
	{
		if (not lep1_is_eleid_tight_isLoaded) {
			if (lep1_is_eleid_tight_branch != 0) {
				lep1_is_eleid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_tight_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_tight_isLoaded = true;
		}
		return lep1_is_eleid_tight_;
	}
	bool &	lep1_is_phys14_loose_noIso()
	{
		if (not lep1_is_phys14_loose_noIso_isLoaded) {
			if (lep1_is_phys14_loose_noIso_branch != 0) {
				lep1_is_phys14_loose_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_loose_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_loose_noIso_isLoaded = true;
		}
		return lep1_is_phys14_loose_noIso_;
	}
	bool &	lep1_is_phys14_medium_noIso()
	{
		if (not lep1_is_phys14_medium_noIso_isLoaded) {
			if (lep1_is_phys14_medium_noIso_branch != 0) {
				lep1_is_phys14_medium_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_medium_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_medium_noIso_isLoaded = true;
		}
		return lep1_is_phys14_medium_noIso_;
	}
	bool &	lep1_is_phys14_tight_noIso()
	{
		if (not lep1_is_phys14_tight_noIso_isLoaded) {
			if (lep1_is_phys14_tight_noIso_branch != 0) {
				lep1_is_phys14_tight_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_tight_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_tight_noIso_isLoaded = true;
		}
		return lep1_is_phys14_tight_noIso_;
	}
	float &lep1_eoverpin()
	{
		if (not lep1_eoverpin_isLoaded) {
			if (lep1_eoverpin_branch != 0) {
				lep1_eoverpin_branch->GetEntry(index);
			} else { 
				printf("branch lep1_eoverpin_branch does not exist!\n");
				exit(1);
			}
			lep1_eoverpin_isLoaded = true;
		}
		return lep1_eoverpin_;
	}
	bool &	lep1_is_muoid_loose()
	{
		if (not lep1_is_muoid_loose_isLoaded) {
			if (lep1_is_muoid_loose_branch != 0) {
				lep1_is_muoid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_loose_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_loose_isLoaded = true;
		}
		return lep1_is_muoid_loose_;
	}
	bool &	lep1_is_muoid_medium()
	{
		if (not lep1_is_muoid_medium_isLoaded) {
			if (lep1_is_muoid_medium_branch != 0) {
				lep1_is_muoid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_medium_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_medium_isLoaded = true;
		}
		return lep1_is_muoid_medium_;
	}
	bool &	lep1_is_muoid_tight()
	{
		if (not lep1_is_muoid_tight_isLoaded) {
			if (lep1_is_muoid_tight_branch != 0) {
				lep1_is_muoid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_tight_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_tight_isLoaded = true;
		}
		return lep1_is_muoid_tight_;
	}
	float &lep1_ip3d()
	{
		if (not lep1_ip3d_isLoaded) {
			if (lep1_ip3d_branch != 0) {
				lep1_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3d_isLoaded = true;
		}
		return lep1_ip3d_;
	}
	float &lep1_ip3derr()
	{
		if (not lep1_ip3derr_isLoaded) {
			if (lep1_ip3derr_branch != 0) {
				lep1_ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3derr_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3derr_isLoaded = true;
		}
		return lep1_ip3derr_;
	}
	bool &	lep1_is_pfmu()
	{
		if (not lep1_is_pfmu_isLoaded) {
			if (lep1_is_pfmu_branch != 0) {
				lep1_is_pfmu_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_pfmu_branch does not exist!\n");
				exit(1);
			}
			lep1_is_pfmu_isLoaded = true;
		}
		return lep1_is_pfmu_;
	}
	bool &	lep1_passMediumID()
	{
		if (not lep1_passMediumID_isLoaded) {
			if (lep1_passMediumID_branch != 0) {
				lep1_passMediumID_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passMediumID_branch does not exist!\n");
				exit(1);
			}
			lep1_passMediumID_isLoaded = true;
		}
		return lep1_passMediumID_;
	}
	bool &	lep1_passVeto()
	{
		if (not lep1_passVeto_isLoaded) {
			if (lep1_passVeto_branch != 0) {
				lep1_passVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passVeto_branch does not exist!\n");
				exit(1);
			}
			lep1_passVeto_isLoaded = true;
		}
		return lep1_passVeto_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4()
	{
		if (not lep1_p4_isLoaded) {
			if (lep1_p4_branch != 0) {
				lep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_p4_branch does not exist!\n");
				exit(1);
			}
			lep1_p4_isLoaded = true;
		}
		return *lep1_p4_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4()
	{
		if (not lep1_mcp4_isLoaded) {
			if (lep1_mcp4_branch != 0) {
				lep1_mcp4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcp4_branch does not exist!\n");
				exit(1);
			}
			lep1_mcp4_isLoaded = true;
		}
		return *lep1_mcp4_;
	}
	float &lep1_pt()
	{
		if (not lep1_pt_isLoaded) {
			if (lep1_pt_branch != 0) {
				lep1_pt_branch->GetEntry(index);
			} else { 
				printf("branch lep1_pt_branch does not exist!\n");
				exit(1);
			}
			lep1_pt_isLoaded = true;
		}
		return lep1_pt_;
	}
	float &lep1_eta()
	{
		if (not lep1_eta_isLoaded) {
			if (lep1_eta_branch != 0) {
				lep1_eta_branch->GetEntry(index);
			} else { 
				printf("branch lep1_eta_branch does not exist!\n");
				exit(1);
			}
			lep1_eta_isLoaded = true;
		}
		return lep1_eta_;
	}
	float &lep1_phi()
	{
		if (not lep1_phi_isLoaded) {
			if (lep1_phi_branch != 0) {
				lep1_phi_branch->GetEntry(index);
			} else { 
				printf("branch lep1_phi_branch does not exist!\n");
				exit(1);
			}
			lep1_phi_isLoaded = true;
		}
		return lep1_phi_;
	}
	float &lep1_mass()
	{
		if (not lep1_mass_isLoaded) {
			if (lep1_mass_branch != 0) {
				lep1_mass_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mass_branch does not exist!\n");
				exit(1);
			}
			lep1_mass_isLoaded = true;
		}
		return lep1_mass_;
	}
	bool &	lep2_is_mu()
	{
		if (not lep2_is_mu_isLoaded) {
			if (lep2_is_mu_branch != 0) {
				lep2_is_mu_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_mu_branch does not exist!\n");
				exit(1);
			}
			lep2_is_mu_isLoaded = true;
		}
		return lep2_is_mu_;
	}
	bool &	lep2_is_el()
	{
		if (not lep2_is_el_isLoaded) {
			if (lep2_is_el_branch != 0) {
				lep2_is_el_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_el_branch does not exist!\n");
				exit(1);
			}
			lep2_is_el_isLoaded = true;
		}
		return lep2_is_el_;
	}
	int &lep2_charge()
	{
		if (not lep2_charge_isLoaded) {
			if (lep2_charge_branch != 0) {
				lep2_charge_branch->GetEntry(index);
			} else { 
				printf("branch lep2_charge_branch does not exist!\n");
				exit(1);
			}
			lep2_charge_isLoaded = true;
		}
		return lep2_charge_;
	}
	int &lep2_pdgid()
	{
		if (not lep2_pdgid_isLoaded) {
			if (lep2_pdgid_branch != 0) {
				lep2_pdgid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_pdgid_branch does not exist!\n");
				exit(1);
			}
			lep2_pdgid_isLoaded = true;
		}
		return lep2_pdgid_;
	}
	int &lep2_type()
	{
		if (not lep2_type_isLoaded) {
			if (lep2_type_branch != 0) {
				lep2_type_branch->GetEntry(index);
			} else { 
				printf("branch lep2_type_branch does not exist!\n");
				exit(1);
			}
			lep2_type_isLoaded = true;
		}
		return lep2_type_;
	}
	int &lep2_production_type()
	{
		if (not lep2_production_type_isLoaded) {
			if (lep2_production_type_branch != 0) {
				lep2_production_type_branch->GetEntry(index);
			} else { 
				printf("branch lep2_production_type_branch does not exist!\n");
				exit(1);
			}
			lep2_production_type_isLoaded = true;
		}
		return lep2_production_type_;
	}
	float &lep2_d0()
	{
		if (not lep2_d0_isLoaded) {
			if (lep2_d0_branch != 0) {
				lep2_d0_branch->GetEntry(index);
			} else { 
				printf("branch lep2_d0_branch does not exist!\n");
				exit(1);
			}
			lep2_d0_isLoaded = true;
		}
		return lep2_d0_;
	}
	float &lep2_d0err()
	{
		if (not lep2_d0err_isLoaded) {
			if (lep2_d0err_branch != 0) {
				lep2_d0err_branch->GetEntry(index);
			} else { 
				printf("branch lep2_d0err_branch does not exist!\n");
				exit(1);
			}
			lep2_d0err_isLoaded = true;
		}
		return lep2_d0err_;
	}
	float &lep2_dz()
	{
		if (not lep2_dz_isLoaded) {
			if (lep2_dz_branch != 0) {
				lep2_dz_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dz_branch does not exist!\n");
				exit(1);
			}
			lep2_dz_isLoaded = true;
		}
		return lep2_dz_;
	}
	float &lep2_dzerr()
	{
		if (not lep2_dzerr_isLoaded) {
			if (lep2_dzerr_branch != 0) {
				lep2_dzerr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dzerr_branch does not exist!\n");
				exit(1);
			}
			lep2_dzerr_isLoaded = true;
		}
		return lep2_dzerr_;
	}
	float &lep2_sigmaIEtaEta_fill5x5()
	{
		if (not lep2_sigmaIEtaEta_fill5x5_isLoaded) {
			if (lep2_sigmaIEtaEta_fill5x5_branch != 0) {
				lep2_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
			} else { 
				printf("branch lep2_sigmaIEtaEta_fill5x5_branch does not exist!\n");
				exit(1);
			}
			lep2_sigmaIEtaEta_fill5x5_isLoaded = true;
		}
		return lep2_sigmaIEtaEta_fill5x5_;
	}
	float &lep2_dEtaIn()
	{
		if (not lep2_dEtaIn_isLoaded) {
			if (lep2_dEtaIn_branch != 0) {
				lep2_dEtaIn_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dEtaIn_branch does not exist!\n");
				exit(1);
			}
			lep2_dEtaIn_isLoaded = true;
		}
		return lep2_dEtaIn_;
	}
	float &lep2_dPhiIn()
	{
		if (not lep2_dPhiIn_isLoaded) {
			if (lep2_dPhiIn_branch != 0) {
				lep2_dPhiIn_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dPhiIn_branch does not exist!\n");
				exit(1);
			}
			lep2_dPhiIn_isLoaded = true;
		}
		return lep2_dPhiIn_;
	}
	float &lep2_hOverE()
	{
		if (not lep2_hOverE_isLoaded) {
			if (lep2_hOverE_branch != 0) {
				lep2_hOverE_branch->GetEntry(index);
			} else { 
				printf("branch lep2_hOverE_branch does not exist!\n");
				exit(1);
			}
			lep2_hOverE_isLoaded = true;
		}
		return lep2_hOverE_;
	}
	float &lep2_ooEmooP()
	{
		if (not lep2_ooEmooP_isLoaded) {
			if (lep2_ooEmooP_branch != 0) {
				lep2_ooEmooP_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ooEmooP_branch does not exist!\n");
				exit(1);
			}
			lep2_ooEmooP_isLoaded = true;
		}
		return lep2_ooEmooP_;
	}
	int &lep2_expectedMissingInnerHits()
	{
		if (not lep2_expectedMissingInnerHits_isLoaded) {
			if (lep2_expectedMissingInnerHits_branch != 0) {
				lep2_expectedMissingInnerHits_branch->GetEntry(index);
			} else { 
				printf("branch lep2_expectedMissingInnerHits_branch does not exist!\n");
				exit(1);
			}
			lep2_expectedMissingInnerHits_isLoaded = true;
		}
		return lep2_expectedMissingInnerHits_;
	}
	bool &	lep2_conversionVeto()
	{
		if (not lep2_conversionVeto_isLoaded) {
			if (lep2_conversionVeto_branch != 0) {
				lep2_conversionVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep2_conversionVeto_branch does not exist!\n");
				exit(1);
			}
			lep2_conversionVeto_isLoaded = true;
		}
		return lep2_conversionVeto_;
	}
	float &lep2_etaSC()
	{
		if (not lep2_etaSC_isLoaded) {
			if (lep2_etaSC_branch != 0) {
				lep2_etaSC_branch->GetEntry(index);
			} else { 
				printf("branch lep2_etaSC_branch does not exist!\n");
				exit(1);
			}
			lep2_etaSC_isLoaded = true;
		}
		return lep2_etaSC_;
	}
	float &lep2_ChiSqr()
	{
		if (not lep2_ChiSqr_isLoaded) {
			if (lep2_ChiSqr_branch != 0) {
				lep2_ChiSqr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ChiSqr_branch does not exist!\n");
				exit(1);
			}
			lep2_ChiSqr_isLoaded = true;
		}
		return lep2_ChiSqr_;
	}
	float &lep2_chiso()
	{
		if (not lep2_chiso_isLoaded) {
			if (lep2_chiso_branch != 0) {
				lep2_chiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_chiso_branch does not exist!\n");
				exit(1);
			}
			lep2_chiso_isLoaded = true;
		}
		return lep2_chiso_;
	}
	float &lep2_nhiso()
	{
		if (not lep2_nhiso_isLoaded) {
			if (lep2_nhiso_branch != 0) {
				lep2_nhiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_nhiso_branch does not exist!\n");
				exit(1);
			}
			lep2_nhiso_isLoaded = true;
		}
		return lep2_nhiso_;
	}
	float &lep2_emiso()
	{
		if (not lep2_emiso_isLoaded) {
			if (lep2_emiso_branch != 0) {
				lep2_emiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_emiso_branch does not exist!\n");
				exit(1);
			}
			lep2_emiso_isLoaded = true;
		}
		return lep2_emiso_;
	}
	float &lep2_deltaBeta()
	{
		if (not lep2_deltaBeta_isLoaded) {
			if (lep2_deltaBeta_branch != 0) {
				lep2_deltaBeta_branch->GetEntry(index);
			} else { 
				printf("branch lep2_deltaBeta_branch does not exist!\n");
				exit(1);
			}
			lep2_deltaBeta_isLoaded = true;
		}
		return lep2_deltaBeta_;
	}
	float &lep2_relIso03DB()
	{
		if (not lep2_relIso03DB_isLoaded) {
			if (lep2_relIso03DB_branch != 0) {
				lep2_relIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso03DB_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso03DB_isLoaded = true;
		}
		return lep2_relIso03DB_;
	}
	float &lep2_relIso03EA()
	{
		if (not lep2_relIso03EA_isLoaded) {
			if (lep2_relIso03EA_branch != 0) {
				lep2_relIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso03EA_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso03EA_isLoaded = true;
		}
		return lep2_relIso03EA_;
	}
	float &lep2_relIso04DB()
	{
		if (not lep2_relIso04DB_isLoaded) {
			if (lep2_relIso04DB_branch != 0) {
				lep2_relIso04DB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso04DB_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso04DB_isLoaded = true;
		}
		return lep2_relIso04DB_;
	}
	float &lep2_miniRelIsoDB()
	{
		if (not lep2_miniRelIsoDB_isLoaded) {
			if (lep2_miniRelIsoDB_branch != 0) {
				lep2_miniRelIsoDB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_miniRelIsoDB_branch does not exist!\n");
				exit(1);
			}
			lep2_miniRelIsoDB_isLoaded = true;
		}
		return lep2_miniRelIsoDB_;
	}
	float &lep2_miniRelIsoEA()
	{
		if (not lep2_miniRelIsoEA_isLoaded) {
			if (lep2_miniRelIsoEA_branch != 0) {
				lep2_miniRelIsoEA_branch->GetEntry(index);
			} else { 
				printf("branch lep2_miniRelIsoEA_branch does not exist!\n");
				exit(1);
			}
			lep2_miniRelIsoEA_isLoaded = true;
		}
		return lep2_miniRelIsoEA_;
	}
	float &lep2_MiniIso()
	{
		if (not lep2_MiniIso_isLoaded) {
			if (lep2_MiniIso_branch != 0) {
				lep2_MiniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_MiniIso_branch does not exist!\n");
				exit(1);
			}
			lep2_MiniIso_isLoaded = true;
		}
		return lep2_MiniIso_;
	}
	int &lep2_mcid()
	{
		if (not lep2_mcid_isLoaded) {
			if (lep2_mcid_branch != 0) {
				lep2_mcid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcid_branch does not exist!\n");
				exit(1);
			}
			lep2_mcid_isLoaded = true;
		}
		return lep2_mcid_;
	}
	int &lep2_mcstatus()
	{
		if (not lep2_mcstatus_isLoaded) {
			if (lep2_mcstatus_branch != 0) {
				lep2_mcstatus_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcstatus_branch does not exist!\n");
				exit(1);
			}
			lep2_mcstatus_isLoaded = true;
		}
		return lep2_mcstatus_;
	}
	int &lep2_mc3dr()
	{
		if (not lep2_mc3dr_isLoaded) {
			if (lep2_mc3dr_branch != 0) {
				lep2_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3dr_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3dr_isLoaded = true;
		}
		return lep2_mc3dr_;
	}
	int &lep2_mc3id()
	{
		if (not lep2_mc3id_isLoaded) {
			if (lep2_mc3id_branch != 0) {
				lep2_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3id_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3id_isLoaded = true;
		}
		return lep2_mc3id_;
	}
	int &lep2_mc3idx()
	{
		if (not lep2_mc3idx_isLoaded) {
			if (lep2_mc3idx_branch != 0) {
				lep2_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3idx_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3idx_isLoaded = true;
		}
		return lep2_mc3idx_;
	}
	int &lep2_mc3motherid()
	{
		if (not lep2_mc3motherid_isLoaded) {
			if (lep2_mc3motherid_branch != 0) {
				lep2_mc3motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3motherid_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3motherid_isLoaded = true;
		}
		return lep2_mc3motherid_;
	}
	int &lep2_mc3motheridx()
	{
		if (not lep2_mc3motheridx_isLoaded) {
			if (lep2_mc3motheridx_branch != 0) {
				lep2_mc3motheridx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3motheridx_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3motheridx_isLoaded = true;
		}
		return lep2_mc3motheridx_;
	}
	bool &	lep2_is_eleid_loose()
	{
		if (not lep2_is_eleid_loose_isLoaded) {
			if (lep2_is_eleid_loose_branch != 0) {
				lep2_is_eleid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_loose_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_loose_isLoaded = true;
		}
		return lep2_is_eleid_loose_;
	}
	bool &	lep2_is_eleid_medium()
	{
		if (not lep2_is_eleid_medium_isLoaded) {
			if (lep2_is_eleid_medium_branch != 0) {
				lep2_is_eleid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_medium_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_medium_isLoaded = true;
		}
		return lep2_is_eleid_medium_;
	}
	bool &	lep2_is_eleid_tight()
	{
		if (not lep2_is_eleid_tight_isLoaded) {
			if (lep2_is_eleid_tight_branch != 0) {
				lep2_is_eleid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_tight_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_tight_isLoaded = true;
		}
		return lep2_is_eleid_tight_;
	}
	bool &	lep2_is_phys14_loose_noIso()
	{
		if (not lep2_is_phys14_loose_noIso_isLoaded) {
			if (lep2_is_phys14_loose_noIso_branch != 0) {
				lep2_is_phys14_loose_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_loose_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_loose_noIso_isLoaded = true;
		}
		return lep2_is_phys14_loose_noIso_;
	}
	bool &	lep2_is_phys14_medium_noIso()
	{
		if (not lep2_is_phys14_medium_noIso_isLoaded) {
			if (lep2_is_phys14_medium_noIso_branch != 0) {
				lep2_is_phys14_medium_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_medium_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_medium_noIso_isLoaded = true;
		}
		return lep2_is_phys14_medium_noIso_;
	}
	bool &	lep2_is_phys14_tight_noIso()
	{
		if (not lep2_is_phys14_tight_noIso_isLoaded) {
			if (lep2_is_phys14_tight_noIso_branch != 0) {
				lep2_is_phys14_tight_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_tight_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_tight_noIso_isLoaded = true;
		}
		return lep2_is_phys14_tight_noIso_;
	}
	float &lep2_eoverpin()
	{
		if (not lep2_eoverpin_isLoaded) {
			if (lep2_eoverpin_branch != 0) {
				lep2_eoverpin_branch->GetEntry(index);
			} else { 
				printf("branch lep2_eoverpin_branch does not exist!\n");
				exit(1);
			}
			lep2_eoverpin_isLoaded = true;
		}
		return lep2_eoverpin_;
	}
	bool &	lep2_is_muoid_loose()
	{
		if (not lep2_is_muoid_loose_isLoaded) {
			if (lep2_is_muoid_loose_branch != 0) {
				lep2_is_muoid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_loose_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_loose_isLoaded = true;
		}
		return lep2_is_muoid_loose_;
	}
	bool &	lep2_is_muoid_medium()
	{
		if (not lep2_is_muoid_medium_isLoaded) {
			if (lep2_is_muoid_medium_branch != 0) {
				lep2_is_muoid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_medium_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_medium_isLoaded = true;
		}
		return lep2_is_muoid_medium_;
	}
	bool &	lep2_is_muoid_tight()
	{
		if (not lep2_is_muoid_tight_isLoaded) {
			if (lep2_is_muoid_tight_branch != 0) {
				lep2_is_muoid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_tight_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_tight_isLoaded = true;
		}
		return lep2_is_muoid_tight_;
	}
	float &lep2_ip3d()
	{
		if (not lep2_ip3d_isLoaded) {
			if (lep2_ip3d_branch != 0) {
				lep2_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3d_isLoaded = true;
		}
		return lep2_ip3d_;
	}
	float &lep2_ip3derr()
	{
		if (not lep2_ip3derr_isLoaded) {
			if (lep2_ip3derr_branch != 0) {
				lep2_ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3derr_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3derr_isLoaded = true;
		}
		return lep2_ip3derr_;
	}
	bool &	lep2_is_pfmu()
	{
		if (not lep2_is_pfmu_isLoaded) {
			if (lep2_is_pfmu_branch != 0) {
				lep2_is_pfmu_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_pfmu_branch does not exist!\n");
				exit(1);
			}
			lep2_is_pfmu_isLoaded = true;
		}
		return lep2_is_pfmu_;
	}
	bool &	lep2_passMediumID()
	{
		if (not lep2_passMediumID_isLoaded) {
			if (lep2_passMediumID_branch != 0) {
				lep2_passMediumID_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passMediumID_branch does not exist!\n");
				exit(1);
			}
			lep2_passMediumID_isLoaded = true;
		}
		return lep2_passMediumID_;
	}
	bool &	lep2_passVeto()
	{
		if (not lep2_passVeto_isLoaded) {
			if (lep2_passVeto_branch != 0) {
				lep2_passVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passVeto_branch does not exist!\n");
				exit(1);
			}
			lep2_passVeto_isLoaded = true;
		}
		return lep2_passVeto_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4()
	{
		if (not lep2_p4_isLoaded) {
			if (lep2_p4_branch != 0) {
				lep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_p4_branch does not exist!\n");
				exit(1);
			}
			lep2_p4_isLoaded = true;
		}
		return *lep2_p4_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4()
	{
		if (not lep2_mcp4_isLoaded) {
			if (lep2_mcp4_branch != 0) {
				lep2_mcp4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcp4_branch does not exist!\n");
				exit(1);
			}
			lep2_mcp4_isLoaded = true;
		}
		return *lep2_mcp4_;
	}
	float &lep2_pt()
	{
		if (not lep2_pt_isLoaded) {
			if (lep2_pt_branch != 0) {
				lep2_pt_branch->GetEntry(index);
			} else { 
				printf("branch lep2_pt_branch does not exist!\n");
				exit(1);
			}
			lep2_pt_isLoaded = true;
		}
		return lep2_pt_;
	}
	float &lep2_eta()
	{
		if (not lep2_eta_isLoaded) {
			if (lep2_eta_branch != 0) {
				lep2_eta_branch->GetEntry(index);
			} else { 
				printf("branch lep2_eta_branch does not exist!\n");
				exit(1);
			}
			lep2_eta_isLoaded = true;
		}
		return lep2_eta_;
	}
	float &lep2_phi()
	{
		if (not lep2_phi_isLoaded) {
			if (lep2_phi_branch != 0) {
				lep2_phi_branch->GetEntry(index);
			} else { 
				printf("branch lep2_phi_branch does not exist!\n");
				exit(1);
			}
			lep2_phi_isLoaded = true;
		}
		return lep2_phi_;
	}
	float &lep2_mass()
	{
		if (not lep2_mass_isLoaded) {
			if (lep2_mass_branch != 0) {
				lep2_mass_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mass_branch does not exist!\n");
				exit(1);
			}
			lep2_mass_isLoaded = true;
		}
		return lep2_mass_;
	}
	int &nGoodGenJets()
	{
		if (not nGoodGenJets_isLoaded) {
			if (nGoodGenJets_branch != 0) {
				nGoodGenJets_branch->GetEntry(index);
			} else { 
				printf("branch nGoodGenJets_branch does not exist!\n");
				exit(1);
			}
			nGoodGenJets_isLoaded = true;
		}
		return nGoodGenJets_;
	}
	int &ngoodjets()
	{
		if (not ngoodjets_isLoaded) {
			if (ngoodjets_branch != 0) {
				ngoodjets_branch->GetEntry(index);
			} else { 
				printf("branch ngoodjets_branch does not exist!\n");
				exit(1);
			}
			ngoodjets_isLoaded = true;
		}
		return ngoodjets_;
	}
	int &nfailjets()
	{
		if (not nfailjets_isLoaded) {
			if (nfailjets_branch != 0) {
				nfailjets_branch->GetEntry(index);
			} else { 
				printf("branch nfailjets_branch does not exist!\n");
				exit(1);
			}
			nfailjets_isLoaded = true;
		}
		return nfailjets_;
	}
	int &ak8GoodPFJets()
	{
		if (not ak8GoodPFJets_isLoaded) {
			if (ak8GoodPFJets_branch != 0) {
				ak8GoodPFJets_branch->GetEntry(index);
			} else { 
				printf("branch ak8GoodPFJets_branch does not exist!\n");
				exit(1);
			}
			ak8GoodPFJets_isLoaded = true;
		}
		return ak8GoodPFJets_;
	}
	int &ngoodbtags()
	{
		if (not ngoodbtags_isLoaded) {
			if (ngoodbtags_branch != 0) {
				ngoodbtags_branch->GetEntry(index);
			} else { 
				printf("branch ngoodbtags_branch does not exist!\n");
				exit(1);
			}
			ngoodbtags_isLoaded = true;
		}
		return ngoodbtags_;
	}
	float &ak4_HT()
	{
		if (not ak4_HT_isLoaded) {
			if (ak4_HT_branch != 0) {
				ak4_HT_branch->GetEntry(index);
			} else { 
				printf("branch ak4_HT_branch does not exist!\n");
				exit(1);
			}
			ak4_HT_isLoaded = true;
		}
		return ak4_HT_;
	}
	float &ak4_htssm()
	{
		if (not ak4_htssm_isLoaded) {
			if (ak4_htssm_branch != 0) {
				ak4_htssm_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htssm_branch does not exist!\n");
				exit(1);
			}
			ak4_htssm_isLoaded = true;
		}
		return ak4_htssm_;
	}
	float &ak4_htosm()
	{
		if (not ak4_htosm_isLoaded) {
			if (ak4_htosm_branch != 0) {
				ak4_htosm_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htosm_branch does not exist!\n");
				exit(1);
			}
			ak4_htosm_isLoaded = true;
		}
		return ak4_htosm_;
	}
	float &ak4_htratiom()
	{
		if (not ak4_htratiom_isLoaded) {
			if (ak4_htratiom_branch != 0) {
				ak4_htratiom_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htratiom_branch does not exist!\n");
				exit(1);
			}
			ak4_htratiom_isLoaded = true;
		}
		return ak4_htratiom_;
	}
	const vector<float> &dphi_ak4pfjet_met()
	{
		if (not dphi_ak4pfjet_met_isLoaded) {
			if (dphi_ak4pfjet_met_branch != 0) {
				dphi_ak4pfjet_met_branch->GetEntry(index);
			} else { 
				printf("branch dphi_ak4pfjet_met_branch does not exist!\n");
				exit(1);
			}
			dphi_ak4pfjet_met_isLoaded = true;
		}
		return *dphi_ak4pfjet_met_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4()
	{
		if (not ak4pfjets_p4_isLoaded) {
			if (ak4pfjets_p4_branch != 0) {
				ak4pfjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_p4_isLoaded = true;
		}
		return *ak4pfjets_p4_;
	}
	const vector<float> &ak4pfjets_pt()
	{
		if (not ak4pfjets_pt_isLoaded) {
			if (ak4pfjets_pt_branch != 0) {
				ak4pfjets_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_pt_isLoaded = true;
		}
		return *ak4pfjets_pt_;
	}
	const vector<float> &ak4pfjets_eta()
	{
		if (not ak4pfjets_eta_isLoaded) {
			if (ak4pfjets_eta_branch != 0) {
				ak4pfjets_eta_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_eta_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_eta_isLoaded = true;
		}
		return *ak4pfjets_eta_;
	}
	const vector<float> &ak4pfjets_phi()
	{
		if (not ak4pfjets_phi_isLoaded) {
			if (ak4pfjets_phi_branch != 0) {
				ak4pfjets_phi_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_phi_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_phi_isLoaded = true;
		}
		return *ak4pfjets_phi_;
	}
	const vector<float> &ak4pfjets_mass()
	{
		if (not ak4pfjets_mass_isLoaded) {
			if (ak4pfjets_mass_branch != 0) {
				ak4pfjets_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mass_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mass_isLoaded = true;
		}
		return *ak4pfjets_mass_;
	}
	const vector<bool> &ak4pfjets_passMEDbtag()
	{
		if (not ak4pfjets_passMEDbtag_isLoaded) {
			if (ak4pfjets_passMEDbtag_branch != 0) {
				ak4pfjets_passMEDbtag_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_passMEDbtag_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_passMEDbtag_isLoaded = true;
		}
		return *ak4pfjets_passMEDbtag_;
	}
	const vector<float> &ak4pfjets_qg_disc()
	{
		if (not ak4pfjets_qg_disc_isLoaded) {
			if (ak4pfjets_qg_disc_branch != 0) {
				ak4pfjets_qg_disc_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_qg_disc_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_qg_disc_isLoaded = true;
		}
		return *ak4pfjets_qg_disc_;
	}
	const vector<float> &ak4pfjets_CSV()
	{
		if (not ak4pfjets_CSV_isLoaded) {
			if (ak4pfjets_CSV_branch != 0) {
				ak4pfjets_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_CSV_isLoaded = true;
		}
		return *ak4pfjets_CSV_;
	}
	const vector<float> &ak4pfjets_puid()
	{
		if (not ak4pfjets_puid_isLoaded) {
			if (ak4pfjets_puid_branch != 0) {
				ak4pfjets_puid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_puid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_puid_isLoaded = true;
		}
		return *ak4pfjets_puid_;
	}
	const vector<int> &ak4pfjets_parton_flavor()
	{
		if (not ak4pfjets_parton_flavor_isLoaded) {
			if (ak4pfjets_parton_flavor_branch != 0) {
				ak4pfjets_parton_flavor_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_parton_flavor_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_parton_flavor_isLoaded = true;
		}
		return *ak4pfjets_parton_flavor_;
	}
	const vector<bool> &ak4pfjets_loose_puid()
	{
		if (not ak4pfjets_loose_puid_isLoaded) {
			if (ak4pfjets_loose_puid_branch != 0) {
				ak4pfjets_loose_puid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_loose_puid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_loose_puid_isLoaded = true;
		}
		return *ak4pfjets_loose_puid_;
	}
	const vector<bool> &ak4pfjets_loose_pfid()
	{
		if (not ak4pfjets_loose_pfid_isLoaded) {
			if (ak4pfjets_loose_pfid_branch != 0) {
				ak4pfjets_loose_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_loose_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_loose_pfid_isLoaded = true;
		}
		return *ak4pfjets_loose_pfid_;
	}
	const vector<bool> &ak4pfjets_medium_pfid()
	{
		if (not ak4pfjets_medium_pfid_isLoaded) {
			if (ak4pfjets_medium_pfid_branch != 0) {
				ak4pfjets_medium_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_medium_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_medium_pfid_isLoaded = true;
		}
		return *ak4pfjets_medium_pfid_;
	}
	const vector<bool> &ak4pfjets_tight_pfid()
	{
		if (not ak4pfjets_tight_pfid_isLoaded) {
			if (ak4pfjets_tight_pfid_branch != 0) {
				ak4pfjets_tight_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_tight_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_tight_pfid_isLoaded = true;
		}
		return *ak4pfjets_tight_pfid_;
	}
	const vector<float> &ak4pfjets_MEDbjet_pt()
	{
		if (not ak4pfjets_MEDbjet_pt_isLoaded) {
			if (ak4pfjets_MEDbjet_pt_branch != 0) {
				ak4pfjets_MEDbjet_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_MEDbjet_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_MEDbjet_pt_isLoaded = true;
		}
		return *ak4pfjets_MEDbjet_pt_;
	}
	float &ak4pfjets_leadMEDbjet_pt()
	{
		if (not ak4pfjets_leadMEDbjet_pt_isLoaded) {
			if (ak4pfjets_leadMEDbjet_pt_branch != 0) {
				ak4pfjets_leadMEDbjet_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadMEDbjet_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadMEDbjet_pt_isLoaded = true;
		}
		return ak4pfjets_leadMEDbjet_pt_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4()
	{
		if (not ak4pfjets_leadMEDbjet_p4_isLoaded) {
			if (ak4pfjets_leadMEDbjet_p4_branch != 0) {
				ak4pfjets_leadMEDbjet_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadMEDbjet_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadMEDbjet_p4_isLoaded = true;
		}
		return *ak4pfjets_leadMEDbjet_p4_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4()
	{
		if (not ak4pfjets_leadbtag_p4_isLoaded) {
			if (ak4pfjets_leadbtag_p4_branch != 0) {
				ak4pfjets_leadbtag_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadbtag_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadbtag_p4_isLoaded = true;
		}
		return *ak4pfjets_leadbtag_p4_;
	}
	const vector<float> &ak4pfjets_chf()
	{
		if (not ak4pfjets_chf_isLoaded) {
			if (ak4pfjets_chf_branch != 0) {
				ak4pfjets_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_chf_isLoaded = true;
		}
		return *ak4pfjets_chf_;
	}
	const vector<float> &ak4pfjets_nhf()
	{
		if (not ak4pfjets_nhf_isLoaded) {
			if (ak4pfjets_nhf_branch != 0) {
				ak4pfjets_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nhf_isLoaded = true;
		}
		return *ak4pfjets_nhf_;
	}
	const vector<float> &ak4pfjets_cef()
	{
		if (not ak4pfjets_cef_isLoaded) {
			if (ak4pfjets_cef_branch != 0) {
				ak4pfjets_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_cef_isLoaded = true;
		}
		return *ak4pfjets_cef_;
	}
	const vector<float> &ak4pfjets_nef()
	{
		if (not ak4pfjets_nef_isLoaded) {
			if (ak4pfjets_nef_branch != 0) {
				ak4pfjets_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nef_isLoaded = true;
		}
		return *ak4pfjets_nef_;
	}
	const vector<float> &ak4pfjets_muf()
	{
		if (not ak4pfjets_muf_isLoaded) {
			if (ak4pfjets_muf_branch != 0) {
				ak4pfjets_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_muf_isLoaded = true;
		}
		return *ak4pfjets_muf_;
	}
	const vector<int> &ak4pfjets_cm()
	{
		if (not ak4pfjets_cm_isLoaded) {
			if (ak4pfjets_cm_branch != 0) {
				ak4pfjets_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_cm_isLoaded = true;
		}
		return *ak4pfjets_cm_;
	}
	const vector<int> &ak4pfjets_nm()
	{
		if (not ak4pfjets_nm_isLoaded) {
			if (ak4pfjets_nm_branch != 0) {
				ak4pfjets_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nm_isLoaded = true;
		}
		return *ak4pfjets_nm_;
	}
	const vector<int> &ak4pfjets_mc3dr()
	{
		if (not ak4pfjets_mc3dr_isLoaded) {
			if (ak4pfjets_mc3dr_branch != 0) {
				ak4pfjets_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3dr_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3dr_isLoaded = true;
		}
		return *ak4pfjets_mc3dr_;
	}
	const vector<int> &ak4pfjets_mc3id()
	{
		if (not ak4pfjets_mc3id_isLoaded) {
			if (ak4pfjets_mc3id_branch != 0) {
				ak4pfjets_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3id_isLoaded = true;
		}
		return *ak4pfjets_mc3id_;
	}
	const vector<int> &ak4pfjets_mc3idx()
	{
		if (not ak4pfjets_mc3idx_isLoaded) {
			if (ak4pfjets_mc3idx_branch != 0) {
				ak4pfjets_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3idx_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3idx_isLoaded = true;
		}
		return *ak4pfjets_mc3idx_;
	}
	const vector<int> &ak4pfjets_mcmotherid()
	{
		if (not ak4pfjets_mcmotherid_isLoaded) {
			if (ak4pfjets_mcmotherid_branch != 0) {
				ak4pfjets_mcmotherid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mcmotherid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mcmotherid_isLoaded = true;
		}
		return *ak4pfjets_mcmotherid_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep1_p4()
	{
		if (not ak4pfjet_overlep1_p4_isLoaded) {
			if (ak4pfjet_overlep1_p4_branch != 0) {
				ak4pfjet_overlep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_p4_isLoaded = true;
		}
		return *ak4pfjet_overlep1_p4_;
	}
	float &ak4pfjet_overlep1_CSV()
	{
		if (not ak4pfjet_overlep1_CSV_isLoaded) {
			if (ak4pfjet_overlep1_CSV_branch != 0) {
				ak4pfjet_overlep1_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_CSV_isLoaded = true;
		}
		return ak4pfjet_overlep1_CSV_;
	}
	float &ak4pfjet_overlep1_pu_id()
	{
		if (not ak4pfjet_overlep1_pu_id_isLoaded) {
			if (ak4pfjet_overlep1_pu_id_branch != 0) {
				ak4pfjet_overlep1_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_pu_id_isLoaded = true;
		}
		return ak4pfjet_overlep1_pu_id_;
	}
	float &ak4pfjet_overlep1_chf()
	{
		if (not ak4pfjet_overlep1_chf_isLoaded) {
			if (ak4pfjet_overlep1_chf_branch != 0) {
				ak4pfjet_overlep1_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_chf_isLoaded = true;
		}
		return ak4pfjet_overlep1_chf_;
	}
	float &ak4pfjet_overlep1_nhf()
	{
		if (not ak4pfjet_overlep1_nhf_isLoaded) {
			if (ak4pfjet_overlep1_nhf_branch != 0) {
				ak4pfjet_overlep1_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nhf_isLoaded = true;
		}
		return ak4pfjet_overlep1_nhf_;
	}
	float &ak4pfjet_overlep1_cef()
	{
		if (not ak4pfjet_overlep1_cef_isLoaded) {
			if (ak4pfjet_overlep1_cef_branch != 0) {
				ak4pfjet_overlep1_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_cef_isLoaded = true;
		}
		return ak4pfjet_overlep1_cef_;
	}
	float &ak4pfjet_overlep1_nef()
	{
		if (not ak4pfjet_overlep1_nef_isLoaded) {
			if (ak4pfjet_overlep1_nef_branch != 0) {
				ak4pfjet_overlep1_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nef_isLoaded = true;
		}
		return ak4pfjet_overlep1_nef_;
	}
	float &ak4pfjet_overlep1_muf()
	{
		if (not ak4pfjet_overlep1_muf_isLoaded) {
			if (ak4pfjet_overlep1_muf_branch != 0) {
				ak4pfjet_overlep1_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_muf_isLoaded = true;
		}
		return ak4pfjet_overlep1_muf_;
	}
	int &ak4pfjet_overlep1_cm()
	{
		if (not ak4pfjet_overlep1_cm_isLoaded) {
			if (ak4pfjet_overlep1_cm_branch != 0) {
				ak4pfjet_overlep1_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_cm_isLoaded = true;
		}
		return ak4pfjet_overlep1_cm_;
	}
	int &ak4pfjet_overlep1_nm()
	{
		if (not ak4pfjet_overlep1_nm_isLoaded) {
			if (ak4pfjet_overlep1_nm_branch != 0) {
				ak4pfjet_overlep1_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nm_isLoaded = true;
		}
		return ak4pfjet_overlep1_nm_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4()
	{
		if (not ak4pfjet_overlep2_p4_isLoaded) {
			if (ak4pfjet_overlep2_p4_branch != 0) {
				ak4pfjet_overlep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_p4_isLoaded = true;
		}
		return *ak4pfjet_overlep2_p4_;
	}
	float &ak4pfjet_overlep2_CSV()
	{
		if (not ak4pfjet_overlep2_CSV_isLoaded) {
			if (ak4pfjet_overlep2_CSV_branch != 0) {
				ak4pfjet_overlep2_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_CSV_isLoaded = true;
		}
		return ak4pfjet_overlep2_CSV_;
	}
	float &ak4pfjet_overlep2_pu_id()
	{
		if (not ak4pfjet_overlep2_pu_id_isLoaded) {
			if (ak4pfjet_overlep2_pu_id_branch != 0) {
				ak4pfjet_overlep2_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_pu_id_isLoaded = true;
		}
		return ak4pfjet_overlep2_pu_id_;
	}
	float &ak4pfjet_overlep2_chf()
	{
		if (not ak4pfjet_overlep2_chf_isLoaded) {
			if (ak4pfjet_overlep2_chf_branch != 0) {
				ak4pfjet_overlep2_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_chf_isLoaded = true;
		}
		return ak4pfjet_overlep2_chf_;
	}
	float &ak4pfjet_overlep2_nhf()
	{
		if (not ak4pfjet_overlep2_nhf_isLoaded) {
			if (ak4pfjet_overlep2_nhf_branch != 0) {
				ak4pfjet_overlep2_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nhf_isLoaded = true;
		}
		return ak4pfjet_overlep2_nhf_;
	}
	float &ak4pfjet_overlep2_cef()
	{
		if (not ak4pfjet_overlep2_cef_isLoaded) {
			if (ak4pfjet_overlep2_cef_branch != 0) {
				ak4pfjet_overlep2_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_cef_isLoaded = true;
		}
		return ak4pfjet_overlep2_cef_;
	}
	float &ak4pfjet_overlep2_nef()
	{
		if (not ak4pfjet_overlep2_nef_isLoaded) {
			if (ak4pfjet_overlep2_nef_branch != 0) {
				ak4pfjet_overlep2_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nef_isLoaded = true;
		}
		return ak4pfjet_overlep2_nef_;
	}
	float &ak4pfjet_overlep2_muf()
	{
		if (not ak4pfjet_overlep2_muf_isLoaded) {
			if (ak4pfjet_overlep2_muf_branch != 0) {
				ak4pfjet_overlep2_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_muf_isLoaded = true;
		}
		return ak4pfjet_overlep2_muf_;
	}
	int &ak4pfjet_overlep2_cm()
	{
		if (not ak4pfjet_overlep2_cm_isLoaded) {
			if (ak4pfjet_overlep2_cm_branch != 0) {
				ak4pfjet_overlep2_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_cm_isLoaded = true;
		}
		return ak4pfjet_overlep2_cm_;
	}
	int &ak4pfjet_overlep2_nm()
	{
		if (not ak4pfjet_overlep2_nm_isLoaded) {
			if (ak4pfjet_overlep2_nm_branch != 0) {
				ak4pfjet_overlep2_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nm_isLoaded = true;
		}
		return ak4pfjet_overlep2_nm_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8pfjets_p4()
	{
		if (not ak8pfjets_p4_isLoaded) {
			if (ak8pfjets_p4_branch != 0) {
				ak8pfjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_p4_isLoaded = true;
		}
		return *ak8pfjets_p4_;
	}
	const vector<float> &ak8pfjets_tau1()
	{
		if (not ak8pfjets_tau1_isLoaded) {
			if (ak8pfjets_tau1_branch != 0) {
				ak8pfjets_tau1_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau1_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau1_isLoaded = true;
		}
		return *ak8pfjets_tau1_;
	}
	const vector<float> &ak8pfjets_tau2()
	{
		if (not ak8pfjets_tau2_isLoaded) {
			if (ak8pfjets_tau2_branch != 0) {
				ak8pfjets_tau2_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau2_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau2_isLoaded = true;
		}
		return *ak8pfjets_tau2_;
	}
	const vector<float> &ak8pfjets_tau3()
	{
		if (not ak8pfjets_tau3_isLoaded) {
			if (ak8pfjets_tau3_branch != 0) {
				ak8pfjets_tau3_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau3_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau3_isLoaded = true;
		}
		return *ak8pfjets_tau3_;
	}
	const vector<float> &ak8pfjets_top_mass()
	{
		if (not ak8pfjets_top_mass_isLoaded) {
			if (ak8pfjets_top_mass_branch != 0) {
				ak8pfjets_top_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_top_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_top_mass_isLoaded = true;
		}
		return *ak8pfjets_top_mass_;
	}
	const vector<float> &ak8pfjets_pruned_mass()
	{
		if (not ak8pfjets_pruned_mass_isLoaded) {
			if (ak8pfjets_pruned_mass_branch != 0) {
				ak8pfjets_pruned_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_pruned_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_pruned_mass_isLoaded = true;
		}
		return *ak8pfjets_pruned_mass_;
	}
	const vector<float> &ak8pfjets_trimmed_mass()
	{
		if (not ak8pfjets_trimmed_mass_isLoaded) {
			if (ak8pfjets_trimmed_mass_branch != 0) {
				ak8pfjets_trimmed_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_trimmed_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_trimmed_mass_isLoaded = true;
		}
		return *ak8pfjets_trimmed_mass_;
	}
	const vector<float> &ak8pfjets_filtered_mass()
	{
		if (not ak8pfjets_filtered_mass_isLoaded) {
			if (ak8pfjets_filtered_mass_branch != 0) {
				ak8pfjets_filtered_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_filtered_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_filtered_mass_isLoaded = true;
		}
		return *ak8pfjets_filtered_mass_;
	}
	const vector<float> &ak8pfjets_pu_id()
	{
		if (not ak8pfjets_pu_id_isLoaded) {
			if (ak8pfjets_pu_id_branch != 0) {
				ak8pfjets_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_pu_id_isLoaded = true;
		}
		return *ak8pfjets_pu_id_;
	}
	const vector<int> &ak8pfjets_parton_flavor()
	{
		if (not ak8pfjets_parton_flavor_isLoaded) {
			if (ak8pfjets_parton_flavor_branch != 0) {
				ak8pfjets_parton_flavor_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_parton_flavor_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_parton_flavor_isLoaded = true;
		}
		return *ak8pfjets_parton_flavor_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4()
	{
		if (not ak4genjets_p4_isLoaded) {
			if (ak4genjets_p4_branch != 0) {
				ak4genjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4genjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak4genjets_p4_isLoaded = true;
		}
		return *ak4genjets_p4_;
	}
	const vector<TString> &tau_IDnames()
	{
		if (not tau_IDnames_isLoaded) {
			if (tau_IDnames_branch != 0) {
				tau_IDnames_branch->GetEntry(index);
			} else { 
				printf("branch tau_IDnames_branch does not exist!\n");
				exit(1);
			}
			tau_IDnames_isLoaded = true;
		}
		return *tau_IDnames_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4()
	{
		if (not tau_leadtrack_p4_isLoaded) {
			if (tau_leadtrack_p4_branch != 0) {
				tau_leadtrack_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_leadtrack_p4_branch does not exist!\n");
				exit(1);
			}
			tau_leadtrack_p4_isLoaded = true;
		}
		return *tau_leadtrack_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4()
	{
		if (not tau_leadneutral_p4_isLoaded) {
			if (tau_leadneutral_p4_branch != 0) {
				tau_leadneutral_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_leadneutral_p4_branch does not exist!\n");
				exit(1);
			}
			tau_leadneutral_p4_isLoaded = true;
		}
		return *tau_leadneutral_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4()
	{
		if (not tau_p4_isLoaded) {
			if (tau_p4_branch != 0) {
				tau_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_p4_branch does not exist!\n");
				exit(1);
			}
			tau_p4_isLoaded = true;
		}
		return *tau_p4_;
	}
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4()
	{
		if (not tau_isocand_p4_isLoaded) {
			if (tau_isocand_p4_branch != 0) {
				tau_isocand_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_isocand_p4_branch does not exist!\n");
				exit(1);
			}
			tau_isocand_p4_isLoaded = true;
		}
		return *tau_isocand_p4_;
	}
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4()
	{
		if (not tau_sigcand_p4_isLoaded) {
			if (tau_sigcand_p4_branch != 0) {
				tau_sigcand_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_sigcand_p4_branch does not exist!\n");
				exit(1);
			}
			tau_sigcand_p4_isLoaded = true;
		}
		return *tau_sigcand_p4_;
	}
	const vector<float> &tau_mass()
	{
		if (not tau_mass_isLoaded) {
			if (tau_mass_branch != 0) {
				tau_mass_branch->GetEntry(index);
			} else { 
				printf("branch tau_mass_branch does not exist!\n");
				exit(1);
			}
			tau_mass_isLoaded = true;
		}
		return *tau_mass_;
	}
	const vector<vector<float> > &tau_ID()
	{
		if (not tau_ID_isLoaded) {
			if (tau_ID_branch != 0) {
				tau_ID_branch->GetEntry(index);
			} else { 
				printf("branch tau_ID_branch does not exist!\n");
				exit(1);
			}
			tau_ID_isLoaded = true;
		}
		return *tau_ID_;
	}
	const vector<float> &tau_passID()
	{
		if (not tau_passID_isLoaded) {
			if (tau_passID_branch != 0) {
				tau_passID_branch->GetEntry(index);
			} else { 
				printf("branch tau_passID_branch does not exist!\n");
				exit(1);
			}
			tau_passID_isLoaded = true;
		}
		return *tau_passID_;
	}
	const vector<float> &tau_charge()
	{
		if (not tau_charge_isLoaded) {
			if (tau_charge_branch != 0) {
				tau_charge_branch->GetEntry(index);
			} else { 
				printf("branch tau_charge_branch does not exist!\n");
				exit(1);
			}
			tau_charge_isLoaded = true;
		}
		return *tau_charge_;
	}
	int &ngoodtaus()
	{
		if (not ngoodtaus_isLoaded) {
			if (ngoodtaus_branch != 0) {
				ngoodtaus_branch->GetEntry(index);
			} else { 
				printf("branch ngoodtaus_branch does not exist!\n");
				exit(1);
			}
			ngoodtaus_isLoaded = true;
		}
		return ngoodtaus_;
	}
	const vector<float> &tau_againstMuonTight()
	{
		if (not tau_againstMuonTight_isLoaded) {
			if (tau_againstMuonTight_branch != 0) {
				tau_againstMuonTight_branch->GetEntry(index);
			} else { 
				printf("branch tau_againstMuonTight_branch does not exist!\n");
				exit(1);
			}
			tau_againstMuonTight_isLoaded = true;
		}
		return *tau_againstMuonTight_;
	}
	const vector<float> &tau_againstElectronLoose()
	{
		if (not tau_againstElectronLoose_isLoaded) {
			if (tau_againstElectronLoose_branch != 0) {
				tau_againstElectronLoose_branch->GetEntry(index);
			} else { 
				printf("branch tau_againstElectronLoose_branch does not exist!\n");
				exit(1);
			}
			tau_againstElectronLoose_isLoaded = true;
		}
		return *tau_againstElectronLoose_;
	}
	const vector<bool> &tau_isVetoTau()
	{
		if (not tau_isVetoTau_isLoaded) {
			if (tau_isVetoTau_branch != 0) {
				tau_isVetoTau_branch->GetEntry(index);
			} else { 
				printf("branch tau_isVetoTau_branch does not exist!\n");
				exit(1);
			}
			tau_isVetoTau_isLoaded = true;
		}
		return *tau_isVetoTau_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isoTracks_p4()
	{
		if (not isoTracks_p4_isLoaded) {
			if (isoTracks_p4_branch != 0) {
				isoTracks_p4_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_p4_branch does not exist!\n");
				exit(1);
			}
			isoTracks_p4_isLoaded = true;
		}
		return *isoTracks_p4_;
	}
	const vector<int> &isoTracks_charge()
	{
		if (not isoTracks_charge_isLoaded) {
			if (isoTracks_charge_branch != 0) {
				isoTracks_charge_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_charge_branch does not exist!\n");
				exit(1);
			}
			isoTracks_charge_isLoaded = true;
		}
		return *isoTracks_charge_;
	}
	const vector<float> &isoTracks_absIso()
	{
		if (not isoTracks_absIso_isLoaded) {
			if (isoTracks_absIso_branch != 0) {
				isoTracks_absIso_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_absIso_branch does not exist!\n");
				exit(1);
			}
			isoTracks_absIso_isLoaded = true;
		}
		return *isoTracks_absIso_;
	}
	const vector<float> &isoTracks_dz()
	{
		if (not isoTracks_dz_isLoaded) {
			if (isoTracks_dz_branch != 0) {
				isoTracks_dz_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_dz_branch does not exist!\n");
				exit(1);
			}
			isoTracks_dz_isLoaded = true;
		}
		return *isoTracks_dz_;
	}
	const vector<int> &isoTracks_pdgId()
	{
		if (not isoTracks_pdgId_isLoaded) {
			if (isoTracks_pdgId_branch != 0) {
				isoTracks_pdgId_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_pdgId_branch does not exist!\n");
				exit(1);
			}
			isoTracks_pdgId_isLoaded = true;
		}
		return *isoTracks_pdgId_;
	}
	const vector<int> &isoTracks_selectedidx()
	{
		if (not isoTracks_selectedidx_isLoaded) {
			if (isoTracks_selectedidx_branch != 0) {
				isoTracks_selectedidx_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_selectedidx_branch does not exist!\n");
				exit(1);
			}
			isoTracks_selectedidx_isLoaded = true;
		}
		return *isoTracks_selectedidx_;
	}
	int &isoTracks_nselected()
	{
		if (not isoTracks_nselected_isLoaded) {
			if (isoTracks_nselected_branch != 0) {
				isoTracks_nselected_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_nselected_branch does not exist!\n");
				exit(1);
			}
			isoTracks_nselected_isLoaded = true;
		}
		return isoTracks_nselected_;
	}
	const vector<bool> &isoTracks_isVetoTrack()
	{
		if (not isoTracks_isVetoTrack_isLoaded) {
			if (isoTracks_isVetoTrack_branch != 0) {
				isoTracks_isVetoTrack_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_;
	}
	const vector<bool> &isoTracks_isVetoTrack_v2()
	{
		if (not isoTracks_isVetoTrack_v2_isLoaded) {
			if (isoTracks_isVetoTrack_v2_branch != 0) {
				isoTracks_isVetoTrack_v2_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_v2_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_v2_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_v2_;
	}
	const vector<bool> &isoTracks_isVetoTrack_v3()
	{
		if (not isoTracks_isVetoTrack_v3_isLoaded) {
			if (isoTracks_isVetoTrack_v3_branch != 0) {
				isoTracks_isVetoTrack_v3_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_v3_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_v3_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_v3_;
	}
	const vector<bool> &genels_isfromt()
	{
		if (not genels_isfromt_isLoaded) {
			if (genels_isfromt_branch != 0) {
				genels_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genels_isfromt_branch does not exist!\n");
				exit(1);
			}
			genels_isfromt_isLoaded = true;
		}
		return *genels_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_p4()
	{
		if (not genels_p4_isLoaded) {
			if (genels_p4_branch != 0) {
				genels_p4_branch->GetEntry(index);
			} else { 
				printf("branch genels_p4_branch does not exist!\n");
				exit(1);
			}
			genels_p4_isLoaded = true;
		}
		return *genels_p4_;
	}
	const vector<float> &genels_charge()
	{
		if (not genels_charge_isLoaded) {
			if (genels_charge_branch != 0) {
				genels_charge_branch->GetEntry(index);
			} else { 
				printf("branch genels_charge_branch does not exist!\n");
				exit(1);
			}
			genels_charge_isLoaded = true;
		}
		return *genels_charge_;
	}
	const vector<float> &genels_iso()
	{
		if (not genels_iso_isLoaded) {
			if (genels_iso_branch != 0) {
				genels_iso_branch->GetEntry(index);
			} else { 
				printf("branch genels_iso_branch does not exist!\n");
				exit(1);
			}
			genels_iso_isLoaded = true;
		}
		return *genels_iso_;
	}
	const vector<float> &genels_mass()
	{
		if (not genels_mass_isLoaded) {
			if (genels_mass_branch != 0) {
				genels_mass_branch->GetEntry(index);
			} else { 
				printf("branch genels_mass_branch does not exist!\n");
				exit(1);
			}
			genels_mass_isLoaded = true;
		}
		return *genels_mass_;
	}
	const vector<int> &genels_id()
	{
		if (not genels_id_isLoaded) {
			if (genels_id_branch != 0) {
				genels_id_branch->GetEntry(index);
			} else { 
				printf("branch genels_id_branch does not exist!\n");
				exit(1);
			}
			genels_id_isLoaded = true;
		}
		return *genels_id_;
	}
	const vector<int> &genels__genpsidx()
	{
		if (not genels__genpsidx_isLoaded) {
			if (genels__genpsidx_branch != 0) {
				genels__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genels__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genels__genpsidx_isLoaded = true;
		}
		return *genels__genpsidx_;
	}
	const vector<int> &genels_status()
	{
		if (not genels_status_isLoaded) {
			if (genels_status_branch != 0) {
				genels_status_branch->GetEntry(index);
			} else { 
				printf("branch genels_status_branch does not exist!\n");
				exit(1);
			}
			genels_status_isLoaded = true;
		}
		return *genels_status_;
	}
	const vector<bool> &genels_fromHardProcessBeforeFSR()
	{
		if (not genels_fromHardProcessBeforeFSR_isLoaded) {
			if (genels_fromHardProcessBeforeFSR_branch != 0) {
				genels_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genels_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genels_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genels_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genels_fromHardProcessDecayed()
	{
		if (not genels_fromHardProcessDecayed_isLoaded) {
			if (genels_fromHardProcessDecayed_branch != 0) {
				genels_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genels_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genels_fromHardProcessDecayed_isLoaded = true;
		}
		return *genels_fromHardProcessDecayed_;
	}
	const vector<bool> &genels_fromHardProcessFinalState()
	{
		if (not genels_fromHardProcessFinalState_isLoaded) {
			if (genels_fromHardProcessFinalState_branch != 0) {
				genels_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genels_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genels_fromHardProcessFinalState_isLoaded = true;
		}
		return *genels_fromHardProcessFinalState_;
	}
	const vector<bool> &genels_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genels_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genels_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genels_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genels_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genels_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genels_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genels_isDirectPromptTauDecayProductFinalState()
	{
		if (not genels_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genels_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genels_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genels_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genels_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genels_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genels_isHardProcess()
	{
		if (not genels_isHardProcess_isLoaded) {
			if (genels_isHardProcess_branch != 0) {
				genels_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genels_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genels_isHardProcess_isLoaded = true;
		}
		return *genels_isHardProcess_;
	}
	const vector<bool> &genels_isLastCopy()
	{
		if (not genels_isLastCopy_isLoaded) {
			if (genels_isLastCopy_branch != 0) {
				genels_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genels_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genels_isLastCopy_isLoaded = true;
		}
		return *genels_isLastCopy_;
	}
	const vector<bool> &genels_isLastCopyBeforeFSR()
	{
		if (not genels_isLastCopyBeforeFSR_isLoaded) {
			if (genels_isLastCopyBeforeFSR_branch != 0) {
				genels_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genels_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genels_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genels_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genels_isMostlyLikePythia6Status3()
	{
		if (not genels_isMostlyLikePythia6Status3_isLoaded) {
			if (genels_isMostlyLikePythia6Status3_branch != 0) {
				genels_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genels_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genels_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genels_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genels_isPromptDecayed()
	{
		if (not genels_isPromptDecayed_isLoaded) {
			if (genels_isPromptDecayed_branch != 0) {
				genels_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genels_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genels_isPromptDecayed_isLoaded = true;
		}
		return *genels_isPromptDecayed_;
	}
	const vector<bool> &genels_isPromptFinalState()
	{
		if (not genels_isPromptFinalState_isLoaded) {
			if (genels_isPromptFinalState_branch != 0) {
				genels_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genels_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genels_isPromptFinalState_isLoaded = true;
		}
		return *genels_isPromptFinalState_;
	}
	const vector<vector<int> > &genels_lepdaughter_id()
	{
		if (not genels_lepdaughter_id_isLoaded) {
			if (genels_lepdaughter_id_branch != 0) {
				genels_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genels_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genels_lepdaughter_id_isLoaded = true;
		}
		return *genels_lepdaughter_id_;
	}
	const vector<int> &genels_gentaudecay()
	{
		if (not genels_gentaudecay_isLoaded) {
			if (genels_gentaudecay_branch != 0) {
				genels_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genels_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genels_gentaudecay_isLoaded = true;
		}
		return *genels_gentaudecay_;
	}
	int &gen_nfromtels_()
	{
		if (not gen_nfromtels__isLoaded) {
			if (gen_nfromtels__branch != 0) {
				gen_nfromtels__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtels__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtels__isLoaded = true;
		}
		return gen_nfromtels__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_motherp4()
	{
		if (not genels_motherp4_isLoaded) {
			if (genels_motherp4_branch != 0) {
				genels_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genels_motherp4_branch does not exist!\n");
				exit(1);
			}
			genels_motherp4_isLoaded = true;
		}
		return *genels_motherp4_;
	}
	const vector<float> &genels_mothercharge()
	{
		if (not genels_mothercharge_isLoaded) {
			if (genels_mothercharge_branch != 0) {
				genels_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genels_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genels_mothercharge_isLoaded = true;
		}
		return *genels_mothercharge_;
	}
	const vector<int> &genels_motherid()
	{
		if (not genels_motherid_isLoaded) {
			if (genels_motherid_branch != 0) {
				genels_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genels_motherid_branch does not exist!\n");
				exit(1);
			}
			genels_motherid_isLoaded = true;
		}
		return *genels_motherid_;
	}
	const vector<int> &genels_motheridx()
	{
		if (not genels_motheridx_isLoaded) {
			if (genels_motheridx_branch != 0) {
				genels_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genels_motheridx_branch does not exist!\n");
				exit(1);
			}
			genels_motheridx_isLoaded = true;
		}
		return *genels_motheridx_;
	}
	const vector<int> &genels_motherstatus()
	{
		if (not genels_motherstatus_isLoaded) {
			if (genels_motherstatus_branch != 0) {
				genels_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genels_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genels_motherstatus_isLoaded = true;
		}
		return *genels_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_gmotherp4()
	{
		if (not genels_gmotherp4_isLoaded) {
			if (genels_gmotherp4_branch != 0) {
				genels_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genels_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genels_gmotherp4_isLoaded = true;
		}
		return *genels_gmotherp4_;
	}
	const vector<int> &genels_gmothercharge()
	{
		if (not genels_gmothercharge_isLoaded) {
			if (genels_gmothercharge_branch != 0) {
				genels_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genels_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genels_gmothercharge_isLoaded = true;
		}
		return *genels_gmothercharge_;
	}
	const vector<int> &genels_gmotherid()
	{
		if (not genels_gmotherid_isLoaded) {
			if (genels_gmotherid_branch != 0) {
				genels_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genels_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genels_gmotherid_isLoaded = true;
		}
		return *genels_gmotherid_;
	}
	const vector<int> &genels_gmotheridx()
	{
		if (not genels_gmotheridx_isLoaded) {
			if (genels_gmotheridx_branch != 0) {
				genels_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genels_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genels_gmotheridx_isLoaded = true;
		}
		return *genels_gmotheridx_;
	}
	const vector<int> &genels_gmotherstatus()
	{
		if (not genels_gmotherstatus_isLoaded) {
			if (genels_gmotherstatus_branch != 0) {
				genels_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genels_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genels_gmotherstatus_isLoaded = true;
		}
		return *genels_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplemotherp4()
	{
		if (not genels_simplemotherp4_isLoaded) {
			if (genels_simplemotherp4_branch != 0) {
				genels_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genels_simplemotherp4_isLoaded = true;
		}
		return *genels_simplemotherp4_;
	}
	const vector<int> &genels_simplemothercharge()
	{
		if (not genels_simplemothercharge_isLoaded) {
			if (genels_simplemothercharge_branch != 0) {
				genels_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genels_simplemothercharge_isLoaded = true;
		}
		return *genels_simplemothercharge_;
	}
	const vector<int> &genels_simplemotherid()
	{
		if (not genels_simplemotherid_isLoaded) {
			if (genels_simplemotherid_branch != 0) {
				genels_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genels_simplemotherid_isLoaded = true;
		}
		return *genels_simplemotherid_;
	}
	const vector<int> &genels_simplemotheridx()
	{
		if (not genels_simplemotheridx_isLoaded) {
			if (genels_simplemotheridx_branch != 0) {
				genels_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genels_simplemotheridx_isLoaded = true;
		}
		return *genels_simplemotheridx_;
	}
	const vector<int> &genels_simplemotherstatus()
	{
		if (not genels_simplemotherstatus_isLoaded) {
			if (genels_simplemotherstatus_branch != 0) {
				genels_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genels_simplemotherstatus_isLoaded = true;
		}
		return *genels_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplegmotherp4()
	{
		if (not genels_simplegmotherp4_isLoaded) {
			if (genels_simplegmotherp4_branch != 0) {
				genels_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genels_simplegmotherp4_isLoaded = true;
		}
		return *genels_simplegmotherp4_;
	}
	const vector<int> &genels_simplegmothercharge()
	{
		if (not genels_simplegmothercharge_isLoaded) {
			if (genels_simplegmothercharge_branch != 0) {
				genels_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genels_simplegmothercharge_isLoaded = true;
		}
		return *genels_simplegmothercharge_;
	}
	const vector<int> &genels_simplegmotherid()
	{
		if (not genels_simplegmotherid_isLoaded) {
			if (genels_simplegmotherid_branch != 0) {
				genels_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genels_simplegmotherid_isLoaded = true;
		}
		return *genels_simplegmotherid_;
	}
	const vector<int> &genels_simplegmotheridx()
	{
		if (not genels_simplegmotheridx_isLoaded) {
			if (genels_simplegmotheridx_branch != 0) {
				genels_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genels_simplegmotheridx_isLoaded = true;
		}
		return *genels_simplegmotheridx_;
	}
	const vector<int> &genels_simplegmotherstatus()
	{
		if (not genels_simplegmotherstatus_isLoaded) {
			if (genels_simplegmotherstatus_branch != 0) {
				genels_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genels_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genels_simplegmotherstatus_isLoaded = true;
		}
		return *genels_simplegmotherstatus_;
	}
	const vector<bool> &genmus_isfromt()
	{
		if (not genmus_isfromt_isLoaded) {
			if (genmus_isfromt_branch != 0) {
				genmus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isfromt_branch does not exist!\n");
				exit(1);
			}
			genmus_isfromt_isLoaded = true;
		}
		return *genmus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_p4()
	{
		if (not genmus_p4_isLoaded) {
			if (genmus_p4_branch != 0) {
				genmus_p4_branch->GetEntry(index);
			} else { 
				printf("branch genmus_p4_branch does not exist!\n");
				exit(1);
			}
			genmus_p4_isLoaded = true;
		}
		return *genmus_p4_;
	}
	const vector<float> &genmus_charge()
	{
		if (not genmus_charge_isLoaded) {
			if (genmus_charge_branch != 0) {
				genmus_charge_branch->GetEntry(index);
			} else { 
				printf("branch genmus_charge_branch does not exist!\n");
				exit(1);
			}
			genmus_charge_isLoaded = true;
		}
		return *genmus_charge_;
	}
	const vector<float> &genmus_iso()
	{
		if (not genmus_iso_isLoaded) {
			if (genmus_iso_branch != 0) {
				genmus_iso_branch->GetEntry(index);
			} else { 
				printf("branch genmus_iso_branch does not exist!\n");
				exit(1);
			}
			genmus_iso_isLoaded = true;
		}
		return *genmus_iso_;
	}
	const vector<float> &genmus_mass()
	{
		if (not genmus_mass_isLoaded) {
			if (genmus_mass_branch != 0) {
				genmus_mass_branch->GetEntry(index);
			} else { 
				printf("branch genmus_mass_branch does not exist!\n");
				exit(1);
			}
			genmus_mass_isLoaded = true;
		}
		return *genmus_mass_;
	}
	const vector<int> &genmus_id()
	{
		if (not genmus_id_isLoaded) {
			if (genmus_id_branch != 0) {
				genmus_id_branch->GetEntry(index);
			} else { 
				printf("branch genmus_id_branch does not exist!\n");
				exit(1);
			}
			genmus_id_isLoaded = true;
		}
		return *genmus_id_;
	}
	const vector<int> &genmus__genpsidx()
	{
		if (not genmus__genpsidx_isLoaded) {
			if (genmus__genpsidx_branch != 0) {
				genmus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genmus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genmus__genpsidx_isLoaded = true;
		}
		return *genmus__genpsidx_;
	}
	const vector<int> &genmus_status()
	{
		if (not genmus_status_isLoaded) {
			if (genmus_status_branch != 0) {
				genmus_status_branch->GetEntry(index);
			} else { 
				printf("branch genmus_status_branch does not exist!\n");
				exit(1);
			}
			genmus_status_isLoaded = true;
		}
		return *genmus_status_;
	}
	const vector<bool> &genmus_fromHardProcessBeforeFSR()
	{
		if (not genmus_fromHardProcessBeforeFSR_isLoaded) {
			if (genmus_fromHardProcessBeforeFSR_branch != 0) {
				genmus_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genmus_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genmus_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genmus_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genmus_fromHardProcessDecayed()
	{
		if (not genmus_fromHardProcessDecayed_isLoaded) {
			if (genmus_fromHardProcessDecayed_branch != 0) {
				genmus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genmus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genmus_fromHardProcessDecayed_isLoaded = true;
		}
		return *genmus_fromHardProcessDecayed_;
	}
	const vector<bool> &genmus_fromHardProcessFinalState()
	{
		if (not genmus_fromHardProcessFinalState_isLoaded) {
			if (genmus_fromHardProcessFinalState_branch != 0) {
				genmus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genmus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genmus_fromHardProcessFinalState_isLoaded = true;
		}
		return *genmus_fromHardProcessFinalState_;
	}
	const vector<bool> &genmus_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genmus_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genmus_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genmus_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genmus_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genmus_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genmus_isDirectPromptTauDecayProductFinalState()
	{
		if (not genmus_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genmus_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genmus_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genmus_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genmus_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genmus_isHardProcess()
	{
		if (not genmus_isHardProcess_isLoaded) {
			if (genmus_isHardProcess_branch != 0) {
				genmus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genmus_isHardProcess_isLoaded = true;
		}
		return *genmus_isHardProcess_;
	}
	const vector<bool> &genmus_isLastCopy()
	{
		if (not genmus_isLastCopy_isLoaded) {
			if (genmus_isLastCopy_branch != 0) {
				genmus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genmus_isLastCopy_isLoaded = true;
		}
		return *genmus_isLastCopy_;
	}
	const vector<bool> &genmus_isLastCopyBeforeFSR()
	{
		if (not genmus_isLastCopyBeforeFSR_isLoaded) {
			if (genmus_isLastCopyBeforeFSR_branch != 0) {
				genmus_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genmus_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genmus_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genmus_isMostlyLikePythia6Status3()
	{
		if (not genmus_isMostlyLikePythia6Status3_isLoaded) {
			if (genmus_isMostlyLikePythia6Status3_branch != 0) {
				genmus_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genmus_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genmus_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genmus_isPromptDecayed()
	{
		if (not genmus_isPromptDecayed_isLoaded) {
			if (genmus_isPromptDecayed_branch != 0) {
				genmus_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genmus_isPromptDecayed_isLoaded = true;
		}
		return *genmus_isPromptDecayed_;
	}
	const vector<bool> &genmus_isPromptFinalState()
	{
		if (not genmus_isPromptFinalState_isLoaded) {
			if (genmus_isPromptFinalState_branch != 0) {
				genmus_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genmus_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genmus_isPromptFinalState_isLoaded = true;
		}
		return *genmus_isPromptFinalState_;
	}
	const vector<vector<int> > &genmus_lepdaughter_id()
	{
		if (not genmus_lepdaughter_id_isLoaded) {
			if (genmus_lepdaughter_id_branch != 0) {
				genmus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genmus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genmus_lepdaughter_id_isLoaded = true;
		}
		return *genmus_lepdaughter_id_;
	}
	const vector<int> &genmus_gentaudecay()
	{
		if (not genmus_gentaudecay_isLoaded) {
			if (genmus_gentaudecay_branch != 0) {
				genmus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genmus_gentaudecay_isLoaded = true;
		}
		return *genmus_gentaudecay_;
	}
	int &gen_nfromtmus_()
	{
		if (not gen_nfromtmus__isLoaded) {
			if (gen_nfromtmus__branch != 0) {
				gen_nfromtmus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtmus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtmus__isLoaded = true;
		}
		return gen_nfromtmus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_motherp4()
	{
		if (not genmus_motherp4_isLoaded) {
			if (genmus_motherp4_branch != 0) {
				genmus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genmus_motherp4_branch does not exist!\n");
				exit(1);
			}
			genmus_motherp4_isLoaded = true;
		}
		return *genmus_motherp4_;
	}
	const vector<float> &genmus_mothercharge()
	{
		if (not genmus_mothercharge_isLoaded) {
			if (genmus_mothercharge_branch != 0) {
				genmus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genmus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genmus_mothercharge_isLoaded = true;
		}
		return *genmus_mothercharge_;
	}
	const vector<int> &genmus_motherid()
	{
		if (not genmus_motherid_isLoaded) {
			if (genmus_motherid_branch != 0) {
				genmus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genmus_motherid_branch does not exist!\n");
				exit(1);
			}
			genmus_motherid_isLoaded = true;
		}
		return *genmus_motherid_;
	}
	const vector<int> &genmus_motheridx()
	{
		if (not genmus_motheridx_isLoaded) {
			if (genmus_motheridx_branch != 0) {
				genmus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genmus_motheridx_branch does not exist!\n");
				exit(1);
			}
			genmus_motheridx_isLoaded = true;
		}
		return *genmus_motheridx_;
	}
	const vector<int> &genmus_motherstatus()
	{
		if (not genmus_motherstatus_isLoaded) {
			if (genmus_motherstatus_branch != 0) {
				genmus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genmus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genmus_motherstatus_isLoaded = true;
		}
		return *genmus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_gmotherp4()
	{
		if (not genmus_gmotherp4_isLoaded) {
			if (genmus_gmotherp4_branch != 0) {
				genmus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genmus_gmotherp4_isLoaded = true;
		}
		return *genmus_gmotherp4_;
	}
	const vector<int> &genmus_gmothercharge()
	{
		if (not genmus_gmothercharge_isLoaded) {
			if (genmus_gmothercharge_branch != 0) {
				genmus_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genmus_gmothercharge_isLoaded = true;
		}
		return *genmus_gmothercharge_;
	}
	const vector<int> &genmus_gmotherid()
	{
		if (not genmus_gmotherid_isLoaded) {
			if (genmus_gmotherid_branch != 0) {
				genmus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genmus_gmotherid_isLoaded = true;
		}
		return *genmus_gmotherid_;
	}
	const vector<int> &genmus_gmotheridx()
	{
		if (not genmus_gmotheridx_isLoaded) {
			if (genmus_gmotheridx_branch != 0) {
				genmus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genmus_gmotheridx_isLoaded = true;
		}
		return *genmus_gmotheridx_;
	}
	const vector<int> &genmus_gmotherstatus()
	{
		if (not genmus_gmotherstatus_isLoaded) {
			if (genmus_gmotherstatus_branch != 0) {
				genmus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genmus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genmus_gmotherstatus_isLoaded = true;
		}
		return *genmus_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplemotherp4()
	{
		if (not genmus_simplemotherp4_isLoaded) {
			if (genmus_simplemotherp4_branch != 0) {
				genmus_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genmus_simplemotherp4_isLoaded = true;
		}
		return *genmus_simplemotherp4_;
	}
	const vector<int> &genmus_simplemothercharge()
	{
		if (not genmus_simplemothercharge_isLoaded) {
			if (genmus_simplemothercharge_branch != 0) {
				genmus_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genmus_simplemothercharge_isLoaded = true;
		}
		return *genmus_simplemothercharge_;
	}
	const vector<int> &genmus_simplemotherid()
	{
		if (not genmus_simplemotherid_isLoaded) {
			if (genmus_simplemotherid_branch != 0) {
				genmus_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genmus_simplemotherid_isLoaded = true;
		}
		return *genmus_simplemotherid_;
	}
	const vector<int> &genmus_simplemotheridx()
	{
		if (not genmus_simplemotheridx_isLoaded) {
			if (genmus_simplemotheridx_branch != 0) {
				genmus_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genmus_simplemotheridx_isLoaded = true;
		}
		return *genmus_simplemotheridx_;
	}
	const vector<int> &genmus_simplemotherstatus()
	{
		if (not genmus_simplemotherstatus_isLoaded) {
			if (genmus_simplemotherstatus_branch != 0) {
				genmus_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genmus_simplemotherstatus_isLoaded = true;
		}
		return *genmus_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplegmotherp4()
	{
		if (not genmus_simplegmotherp4_isLoaded) {
			if (genmus_simplegmotherp4_branch != 0) {
				genmus_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genmus_simplegmotherp4_isLoaded = true;
		}
		return *genmus_simplegmotherp4_;
	}
	const vector<int> &genmus_simplegmothercharge()
	{
		if (not genmus_simplegmothercharge_isLoaded) {
			if (genmus_simplegmothercharge_branch != 0) {
				genmus_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genmus_simplegmothercharge_isLoaded = true;
		}
		return *genmus_simplegmothercharge_;
	}
	const vector<int> &genmus_simplegmotherid()
	{
		if (not genmus_simplegmotherid_isLoaded) {
			if (genmus_simplegmotherid_branch != 0) {
				genmus_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genmus_simplegmotherid_isLoaded = true;
		}
		return *genmus_simplegmotherid_;
	}
	const vector<int> &genmus_simplegmotheridx()
	{
		if (not genmus_simplegmotheridx_isLoaded) {
			if (genmus_simplegmotheridx_branch != 0) {
				genmus_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genmus_simplegmotheridx_isLoaded = true;
		}
		return *genmus_simplegmotheridx_;
	}
	const vector<int> &genmus_simplegmotherstatus()
	{
		if (not genmus_simplegmotherstatus_isLoaded) {
			if (genmus_simplegmotherstatus_branch != 0) {
				genmus_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genmus_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genmus_simplegmotherstatus_isLoaded = true;
		}
		return *genmus_simplegmotherstatus_;
	}
	const vector<bool> &gentaus_isfromt()
	{
		if (not gentaus_isfromt_isLoaded) {
			if (gentaus_isfromt_branch != 0) {
				gentaus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isfromt_branch does not exist!\n");
				exit(1);
			}
			gentaus_isfromt_isLoaded = true;
		}
		return *gentaus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_p4()
	{
		if (not gentaus_p4_isLoaded) {
			if (gentaus_p4_branch != 0) {
				gentaus_p4_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_p4_branch does not exist!\n");
				exit(1);
			}
			gentaus_p4_isLoaded = true;
		}
		return *gentaus_p4_;
	}
	const vector<float> &gentaus_charge()
	{
		if (not gentaus_charge_isLoaded) {
			if (gentaus_charge_branch != 0) {
				gentaus_charge_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_charge_branch does not exist!\n");
				exit(1);
			}
			gentaus_charge_isLoaded = true;
		}
		return *gentaus_charge_;
	}
	const vector<float> &gentaus_iso()
	{
		if (not gentaus_iso_isLoaded) {
			if (gentaus_iso_branch != 0) {
				gentaus_iso_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_iso_branch does not exist!\n");
				exit(1);
			}
			gentaus_iso_isLoaded = true;
		}
		return *gentaus_iso_;
	}
	const vector<float> &gentaus_mass()
	{
		if (not gentaus_mass_isLoaded) {
			if (gentaus_mass_branch != 0) {
				gentaus_mass_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_mass_branch does not exist!\n");
				exit(1);
			}
			gentaus_mass_isLoaded = true;
		}
		return *gentaus_mass_;
	}
	const vector<int> &gentaus_id()
	{
		if (not gentaus_id_isLoaded) {
			if (gentaus_id_branch != 0) {
				gentaus_id_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_id_branch does not exist!\n");
				exit(1);
			}
			gentaus_id_isLoaded = true;
		}
		return *gentaus_id_;
	}
	const vector<int> &gentaus__genpsidx()
	{
		if (not gentaus__genpsidx_isLoaded) {
			if (gentaus__genpsidx_branch != 0) {
				gentaus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gentaus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gentaus__genpsidx_isLoaded = true;
		}
		return *gentaus__genpsidx_;
	}
	const vector<int> &gentaus_status()
	{
		if (not gentaus_status_isLoaded) {
			if (gentaus_status_branch != 0) {
				gentaus_status_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_status_branch does not exist!\n");
				exit(1);
			}
			gentaus_status_isLoaded = true;
		}
		return *gentaus_status_;
	}
	const vector<bool> &gentaus_fromHardProcessBeforeFSR()
	{
		if (not gentaus_fromHardProcessBeforeFSR_isLoaded) {
			if (gentaus_fromHardProcessBeforeFSR_branch != 0) {
				gentaus_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gentaus_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gentaus_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gentaus_fromHardProcessDecayed()
	{
		if (not gentaus_fromHardProcessDecayed_isLoaded) {
			if (gentaus_fromHardProcessDecayed_branch != 0) {
				gentaus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gentaus_fromHardProcessDecayed_isLoaded = true;
		}
		return *gentaus_fromHardProcessDecayed_;
	}
	const vector<bool> &gentaus_fromHardProcessFinalState()
	{
		if (not gentaus_fromHardProcessFinalState_isLoaded) {
			if (gentaus_fromHardProcessFinalState_branch != 0) {
				gentaus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gentaus_fromHardProcessFinalState_isLoaded = true;
		}
		return *gentaus_fromHardProcessFinalState_;
	}
	const vector<bool> &gentaus_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gentaus_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gentaus_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gentaus_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gentaus_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gentaus_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gentaus_isDirectPromptTauDecayProductFinalState()
	{
		if (not gentaus_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gentaus_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gentaus_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gentaus_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gentaus_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gentaus_isHardProcess()
	{
		if (not gentaus_isHardProcess_isLoaded) {
			if (gentaus_isHardProcess_branch != 0) {
				gentaus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gentaus_isHardProcess_isLoaded = true;
		}
		return *gentaus_isHardProcess_;
	}
	const vector<bool> &gentaus_isLastCopy()
	{
		if (not gentaus_isLastCopy_isLoaded) {
			if (gentaus_isLastCopy_branch != 0) {
				gentaus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gentaus_isLastCopy_isLoaded = true;
		}
		return *gentaus_isLastCopy_;
	}
	const vector<bool> &gentaus_isLastCopyBeforeFSR()
	{
		if (not gentaus_isLastCopyBeforeFSR_isLoaded) {
			if (gentaus_isLastCopyBeforeFSR_branch != 0) {
				gentaus_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gentaus_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gentaus_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gentaus_isMostlyLikePythia6Status3()
	{
		if (not gentaus_isMostlyLikePythia6Status3_isLoaded) {
			if (gentaus_isMostlyLikePythia6Status3_branch != 0) {
				gentaus_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gentaus_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gentaus_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gentaus_isPromptDecayed()
	{
		if (not gentaus_isPromptDecayed_isLoaded) {
			if (gentaus_isPromptDecayed_branch != 0) {
				gentaus_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gentaus_isPromptDecayed_isLoaded = true;
		}
		return *gentaus_isPromptDecayed_;
	}
	const vector<bool> &gentaus_isPromptFinalState()
	{
		if (not gentaus_isPromptFinalState_isLoaded) {
			if (gentaus_isPromptFinalState_branch != 0) {
				gentaus_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gentaus_isPromptFinalState_isLoaded = true;
		}
		return *gentaus_isPromptFinalState_;
	}
	const vector<vector<int> > &gentaus_lepdaughter_id()
	{
		if (not gentaus_lepdaughter_id_isLoaded) {
			if (gentaus_lepdaughter_id_branch != 0) {
				gentaus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gentaus_lepdaughter_id_isLoaded = true;
		}
		return *gentaus_lepdaughter_id_;
	}
	const vector<int> &gentaus_gentaudecay()
	{
		if (not gentaus_gentaudecay_isLoaded) {
			if (gentaus_gentaudecay_branch != 0) {
				gentaus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gentaus_gentaudecay_isLoaded = true;
		}
		return *gentaus_gentaudecay_;
	}
	int &gen_nfromttaus_()
	{
		if (not gen_nfromttaus__isLoaded) {
			if (gen_nfromttaus__branch != 0) {
				gen_nfromttaus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromttaus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromttaus__isLoaded = true;
		}
		return gen_nfromttaus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_motherp4()
	{
		if (not gentaus_motherp4_isLoaded) {
			if (gentaus_motherp4_branch != 0) {
				gentaus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_motherp4_branch does not exist!\n");
				exit(1);
			}
			gentaus_motherp4_isLoaded = true;
		}
		return *gentaus_motherp4_;
	}
	const vector<float> &gentaus_mothercharge()
	{
		if (not gentaus_mothercharge_isLoaded) {
			if (gentaus_mothercharge_branch != 0) {
				gentaus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gentaus_mothercharge_isLoaded = true;
		}
		return *gentaus_mothercharge_;
	}
	const vector<int> &gentaus_motherid()
	{
		if (not gentaus_motherid_isLoaded) {
			if (gentaus_motherid_branch != 0) {
				gentaus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_motherid_branch does not exist!\n");
				exit(1);
			}
			gentaus_motherid_isLoaded = true;
		}
		return *gentaus_motherid_;
	}
	const vector<int> &gentaus_motheridx()
	{
		if (not gentaus_motheridx_isLoaded) {
			if (gentaus_motheridx_branch != 0) {
				gentaus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_motheridx_branch does not exist!\n");
				exit(1);
			}
			gentaus_motheridx_isLoaded = true;
		}
		return *gentaus_motheridx_;
	}
	const vector<int> &gentaus_motherstatus()
	{
		if (not gentaus_motherstatus_isLoaded) {
			if (gentaus_motherstatus_branch != 0) {
				gentaus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gentaus_motherstatus_isLoaded = true;
		}
		return *gentaus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_gmotherp4()
	{
		if (not gentaus_gmotherp4_isLoaded) {
			if (gentaus_gmotherp4_branch != 0) {
				gentaus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gentaus_gmotherp4_isLoaded = true;
		}
		return *gentaus_gmotherp4_;
	}
	const vector<int> &gentaus_gmothercharge()
	{
		if (not gentaus_gmothercharge_isLoaded) {
			if (gentaus_gmothercharge_branch != 0) {
				gentaus_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gentaus_gmothercharge_isLoaded = true;
		}
		return *gentaus_gmothercharge_;
	}
	const vector<int> &gentaus_gmotherid()
	{
		if (not gentaus_gmotherid_isLoaded) {
			if (gentaus_gmotherid_branch != 0) {
				gentaus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gentaus_gmotherid_isLoaded = true;
		}
		return *gentaus_gmotherid_;
	}
	const vector<int> &gentaus_gmotheridx()
	{
		if (not gentaus_gmotheridx_isLoaded) {
			if (gentaus_gmotheridx_branch != 0) {
				gentaus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gentaus_gmotheridx_isLoaded = true;
		}
		return *gentaus_gmotheridx_;
	}
	const vector<int> &gentaus_gmotherstatus()
	{
		if (not gentaus_gmotherstatus_isLoaded) {
			if (gentaus_gmotherstatus_branch != 0) {
				gentaus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gentaus_gmotherstatus_isLoaded = true;
		}
		return *gentaus_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplemotherp4()
	{
		if (not gentaus_simplemotherp4_isLoaded) {
			if (gentaus_simplemotherp4_branch != 0) {
				gentaus_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplemotherp4_isLoaded = true;
		}
		return *gentaus_simplemotherp4_;
	}
	const vector<int> &gentaus_simplemothercharge()
	{
		if (not gentaus_simplemothercharge_isLoaded) {
			if (gentaus_simplemothercharge_branch != 0) {
				gentaus_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplemothercharge_isLoaded = true;
		}
		return *gentaus_simplemothercharge_;
	}
	const vector<int> &gentaus_simplemotherid()
	{
		if (not gentaus_simplemotherid_isLoaded) {
			if (gentaus_simplemotherid_branch != 0) {
				gentaus_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplemotherid_isLoaded = true;
		}
		return *gentaus_simplemotherid_;
	}
	const vector<int> &gentaus_simplemotheridx()
	{
		if (not gentaus_simplemotheridx_isLoaded) {
			if (gentaus_simplemotheridx_branch != 0) {
				gentaus_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplemotheridx_isLoaded = true;
		}
		return *gentaus_simplemotheridx_;
	}
	const vector<int> &gentaus_simplemotherstatus()
	{
		if (not gentaus_simplemotherstatus_isLoaded) {
			if (gentaus_simplemotherstatus_branch != 0) {
				gentaus_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplemotherstatus_isLoaded = true;
		}
		return *gentaus_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplegmotherp4()
	{
		if (not gentaus_simplegmotherp4_isLoaded) {
			if (gentaus_simplegmotherp4_branch != 0) {
				gentaus_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplegmotherp4_isLoaded = true;
		}
		return *gentaus_simplegmotherp4_;
	}
	const vector<int> &gentaus_simplegmothercharge()
	{
		if (not gentaus_simplegmothercharge_isLoaded) {
			if (gentaus_simplegmothercharge_branch != 0) {
				gentaus_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplegmothercharge_isLoaded = true;
		}
		return *gentaus_simplegmothercharge_;
	}
	const vector<int> &gentaus_simplegmotherid()
	{
		if (not gentaus_simplegmotherid_isLoaded) {
			if (gentaus_simplegmotherid_branch != 0) {
				gentaus_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplegmotherid_isLoaded = true;
		}
		return *gentaus_simplegmotherid_;
	}
	const vector<int> &gentaus_simplegmotheridx()
	{
		if (not gentaus_simplegmotheridx_isLoaded) {
			if (gentaus_simplegmotheridx_branch != 0) {
				gentaus_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplegmotheridx_isLoaded = true;
		}
		return *gentaus_simplegmotheridx_;
	}
	const vector<int> &gentaus_simplegmotherstatus()
	{
		if (not gentaus_simplegmotherstatus_isLoaded) {
			if (gentaus_simplegmotherstatus_branch != 0) {
				gentaus_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gentaus_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gentaus_simplegmotherstatus_isLoaded = true;
		}
		return *gentaus_simplegmotherstatus_;
	}
	const vector<bool> &gennuels_isfromt()
	{
		if (not gennuels_isfromt_isLoaded) {
			if (gennuels_isfromt_branch != 0) {
				gennuels_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isfromt_branch does not exist!\n");
				exit(1);
			}
			gennuels_isfromt_isLoaded = true;
		}
		return *gennuels_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_p4()
	{
		if (not gennuels_p4_isLoaded) {
			if (gennuels_p4_branch != 0) {
				gennuels_p4_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_p4_branch does not exist!\n");
				exit(1);
			}
			gennuels_p4_isLoaded = true;
		}
		return *gennuels_p4_;
	}
	const vector<float> &gennuels_charge()
	{
		if (not gennuels_charge_isLoaded) {
			if (gennuels_charge_branch != 0) {
				gennuels_charge_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_charge_branch does not exist!\n");
				exit(1);
			}
			gennuels_charge_isLoaded = true;
		}
		return *gennuels_charge_;
	}
	const vector<float> &gennuels_iso()
	{
		if (not gennuels_iso_isLoaded) {
			if (gennuels_iso_branch != 0) {
				gennuels_iso_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_iso_branch does not exist!\n");
				exit(1);
			}
			gennuels_iso_isLoaded = true;
		}
		return *gennuels_iso_;
	}
	const vector<float> &gennuels_mass()
	{
		if (not gennuels_mass_isLoaded) {
			if (gennuels_mass_branch != 0) {
				gennuels_mass_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_mass_branch does not exist!\n");
				exit(1);
			}
			gennuels_mass_isLoaded = true;
		}
		return *gennuels_mass_;
	}
	const vector<int> &gennuels_id()
	{
		if (not gennuels_id_isLoaded) {
			if (gennuels_id_branch != 0) {
				gennuels_id_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_id_branch does not exist!\n");
				exit(1);
			}
			gennuels_id_isLoaded = true;
		}
		return *gennuels_id_;
	}
	const vector<int> &gennuels__genpsidx()
	{
		if (not gennuels__genpsidx_isLoaded) {
			if (gennuels__genpsidx_branch != 0) {
				gennuels__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gennuels__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gennuels__genpsidx_isLoaded = true;
		}
		return *gennuels__genpsidx_;
	}
	const vector<int> &gennuels_status()
	{
		if (not gennuels_status_isLoaded) {
			if (gennuels_status_branch != 0) {
				gennuels_status_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_status_branch does not exist!\n");
				exit(1);
			}
			gennuels_status_isLoaded = true;
		}
		return *gennuels_status_;
	}
	const vector<bool> &gennuels_fromHardProcessBeforeFSR()
	{
		if (not gennuels_fromHardProcessBeforeFSR_isLoaded) {
			if (gennuels_fromHardProcessBeforeFSR_branch != 0) {
				gennuels_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennuels_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gennuels_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gennuels_fromHardProcessDecayed()
	{
		if (not gennuels_fromHardProcessDecayed_isLoaded) {
			if (gennuels_fromHardProcessDecayed_branch != 0) {
				gennuels_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gennuels_fromHardProcessDecayed_isLoaded = true;
		}
		return *gennuels_fromHardProcessDecayed_;
	}
	const vector<bool> &gennuels_fromHardProcessFinalState()
	{
		if (not gennuels_fromHardProcessFinalState_isLoaded) {
			if (gennuels_fromHardProcessFinalState_branch != 0) {
				gennuels_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gennuels_fromHardProcessFinalState_isLoaded = true;
		}
		return *gennuels_fromHardProcessFinalState_;
	}
	const vector<bool> &gennuels_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gennuels_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gennuels_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gennuels_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennuels_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gennuels_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gennuels_isDirectPromptTauDecayProductFinalState()
	{
		if (not gennuels_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gennuels_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gennuels_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennuels_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gennuels_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gennuels_isHardProcess()
	{
		if (not gennuels_isHardProcess_isLoaded) {
			if (gennuels_isHardProcess_branch != 0) {
				gennuels_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gennuels_isHardProcess_isLoaded = true;
		}
		return *gennuels_isHardProcess_;
	}
	const vector<bool> &gennuels_isLastCopy()
	{
		if (not gennuels_isLastCopy_isLoaded) {
			if (gennuels_isLastCopy_branch != 0) {
				gennuels_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gennuels_isLastCopy_isLoaded = true;
		}
		return *gennuels_isLastCopy_;
	}
	const vector<bool> &gennuels_isLastCopyBeforeFSR()
	{
		if (not gennuels_isLastCopyBeforeFSR_isLoaded) {
			if (gennuels_isLastCopyBeforeFSR_branch != 0) {
				gennuels_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennuels_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gennuels_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gennuels_isMostlyLikePythia6Status3()
	{
		if (not gennuels_isMostlyLikePythia6Status3_isLoaded) {
			if (gennuels_isMostlyLikePythia6Status3_branch != 0) {
				gennuels_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gennuels_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gennuels_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gennuels_isPromptDecayed()
	{
		if (not gennuels_isPromptDecayed_isLoaded) {
			if (gennuels_isPromptDecayed_branch != 0) {
				gennuels_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gennuels_isPromptDecayed_isLoaded = true;
		}
		return *gennuels_isPromptDecayed_;
	}
	const vector<bool> &gennuels_isPromptFinalState()
	{
		if (not gennuels_isPromptFinalState_isLoaded) {
			if (gennuels_isPromptFinalState_branch != 0) {
				gennuels_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gennuels_isPromptFinalState_isLoaded = true;
		}
		return *gennuels_isPromptFinalState_;
	}
	const vector<vector<int> > &gennuels_lepdaughter_id()
	{
		if (not gennuels_lepdaughter_id_isLoaded) {
			if (gennuels_lepdaughter_id_branch != 0) {
				gennuels_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gennuels_lepdaughter_id_isLoaded = true;
		}
		return *gennuels_lepdaughter_id_;
	}
	const vector<int> &gennuels_gentaudecay()
	{
		if (not gennuels_gentaudecay_isLoaded) {
			if (gennuels_gentaudecay_branch != 0) {
				gennuels_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gennuels_gentaudecay_isLoaded = true;
		}
		return *gennuels_gentaudecay_;
	}
	int &gen_nfromtnuels_()
	{
		if (not gen_nfromtnuels__isLoaded) {
			if (gen_nfromtnuels__branch != 0) {
				gen_nfromtnuels__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtnuels__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtnuels__isLoaded = true;
		}
		return gen_nfromtnuels__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_motherp4()
	{
		if (not gennuels_motherp4_isLoaded) {
			if (gennuels_motherp4_branch != 0) {
				gennuels_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_motherp4_branch does not exist!\n");
				exit(1);
			}
			gennuels_motherp4_isLoaded = true;
		}
		return *gennuels_motherp4_;
	}
	const vector<float> &gennuels_mothercharge()
	{
		if (not gennuels_mothercharge_isLoaded) {
			if (gennuels_mothercharge_branch != 0) {
				gennuels_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gennuels_mothercharge_isLoaded = true;
		}
		return *gennuels_mothercharge_;
	}
	const vector<int> &gennuels_motherid()
	{
		if (not gennuels_motherid_isLoaded) {
			if (gennuels_motherid_branch != 0) {
				gennuels_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_motherid_branch does not exist!\n");
				exit(1);
			}
			gennuels_motherid_isLoaded = true;
		}
		return *gennuels_motherid_;
	}
	const vector<int> &gennuels_motheridx()
	{
		if (not gennuels_motheridx_isLoaded) {
			if (gennuels_motheridx_branch != 0) {
				gennuels_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_motheridx_branch does not exist!\n");
				exit(1);
			}
			gennuels_motheridx_isLoaded = true;
		}
		return *gennuels_motheridx_;
	}
	const vector<int> &gennuels_motherstatus()
	{
		if (not gennuels_motherstatus_isLoaded) {
			if (gennuels_motherstatus_branch != 0) {
				gennuels_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gennuels_motherstatus_isLoaded = true;
		}
		return *gennuels_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_gmotherp4()
	{
		if (not gennuels_gmotherp4_isLoaded) {
			if (gennuels_gmotherp4_branch != 0) {
				gennuels_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennuels_gmotherp4_isLoaded = true;
		}
		return *gennuels_gmotherp4_;
	}
	const vector<int> &gennuels_gmothercharge()
	{
		if (not gennuels_gmothercharge_isLoaded) {
			if (gennuels_gmothercharge_branch != 0) {
				gennuels_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennuels_gmothercharge_isLoaded = true;
		}
		return *gennuels_gmothercharge_;
	}
	const vector<int> &gennuels_gmotherid()
	{
		if (not gennuels_gmotherid_isLoaded) {
			if (gennuels_gmotherid_branch != 0) {
				gennuels_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gennuels_gmotherid_isLoaded = true;
		}
		return *gennuels_gmotherid_;
	}
	const vector<int> &gennuels_gmotheridx()
	{
		if (not gennuels_gmotheridx_isLoaded) {
			if (gennuels_gmotheridx_branch != 0) {
				gennuels_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennuels_gmotheridx_isLoaded = true;
		}
		return *gennuels_gmotheridx_;
	}
	const vector<int> &gennuels_gmotherstatus()
	{
		if (not gennuels_gmotherstatus_isLoaded) {
			if (gennuels_gmotherstatus_branch != 0) {
				gennuels_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennuels_gmotherstatus_isLoaded = true;
		}
		return *gennuels_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplemotherp4()
	{
		if (not gennuels_simplemotherp4_isLoaded) {
			if (gennuels_simplemotherp4_branch != 0) {
				gennuels_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplemotherp4_isLoaded = true;
		}
		return *gennuels_simplemotherp4_;
	}
	const vector<int> &gennuels_simplemothercharge()
	{
		if (not gennuels_simplemothercharge_isLoaded) {
			if (gennuels_simplemothercharge_branch != 0) {
				gennuels_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplemothercharge_isLoaded = true;
		}
		return *gennuels_simplemothercharge_;
	}
	const vector<int> &gennuels_simplemotherid()
	{
		if (not gennuels_simplemotherid_isLoaded) {
			if (gennuels_simplemotherid_branch != 0) {
				gennuels_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplemotherid_isLoaded = true;
		}
		return *gennuels_simplemotherid_;
	}
	const vector<int> &gennuels_simplemotheridx()
	{
		if (not gennuels_simplemotheridx_isLoaded) {
			if (gennuels_simplemotheridx_branch != 0) {
				gennuels_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplemotheridx_isLoaded = true;
		}
		return *gennuels_simplemotheridx_;
	}
	const vector<int> &gennuels_simplemotherstatus()
	{
		if (not gennuels_simplemotherstatus_isLoaded) {
			if (gennuels_simplemotherstatus_branch != 0) {
				gennuels_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplemotherstatus_isLoaded = true;
		}
		return *gennuels_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplegmotherp4()
	{
		if (not gennuels_simplegmotherp4_isLoaded) {
			if (gennuels_simplegmotherp4_branch != 0) {
				gennuels_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplegmotherp4_isLoaded = true;
		}
		return *gennuels_simplegmotherp4_;
	}
	const vector<int> &gennuels_simplegmothercharge()
	{
		if (not gennuels_simplegmothercharge_isLoaded) {
			if (gennuels_simplegmothercharge_branch != 0) {
				gennuels_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplegmothercharge_isLoaded = true;
		}
		return *gennuels_simplegmothercharge_;
	}
	const vector<int> &gennuels_simplegmotherid()
	{
		if (not gennuels_simplegmotherid_isLoaded) {
			if (gennuels_simplegmotherid_branch != 0) {
				gennuels_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplegmotherid_isLoaded = true;
		}
		return *gennuels_simplegmotherid_;
	}
	const vector<int> &gennuels_simplegmotheridx()
	{
		if (not gennuels_simplegmotheridx_isLoaded) {
			if (gennuels_simplegmotheridx_branch != 0) {
				gennuels_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplegmotheridx_isLoaded = true;
		}
		return *gennuels_simplegmotheridx_;
	}
	const vector<int> &gennuels_simplegmotherstatus()
	{
		if (not gennuels_simplegmotherstatus_isLoaded) {
			if (gennuels_simplegmotherstatus_branch != 0) {
				gennuels_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennuels_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennuels_simplegmotherstatus_isLoaded = true;
		}
		return *gennuels_simplegmotherstatus_;
	}
	const vector<bool> &gennumus_isfromt()
	{
		if (not gennumus_isfromt_isLoaded) {
			if (gennumus_isfromt_branch != 0) {
				gennumus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isfromt_branch does not exist!\n");
				exit(1);
			}
			gennumus_isfromt_isLoaded = true;
		}
		return *gennumus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_p4()
	{
		if (not gennumus_p4_isLoaded) {
			if (gennumus_p4_branch != 0) {
				gennumus_p4_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_p4_branch does not exist!\n");
				exit(1);
			}
			gennumus_p4_isLoaded = true;
		}
		return *gennumus_p4_;
	}
	const vector<float> &gennumus_charge()
	{
		if (not gennumus_charge_isLoaded) {
			if (gennumus_charge_branch != 0) {
				gennumus_charge_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_charge_branch does not exist!\n");
				exit(1);
			}
			gennumus_charge_isLoaded = true;
		}
		return *gennumus_charge_;
	}
	const vector<float> &gennumus_iso()
	{
		if (not gennumus_iso_isLoaded) {
			if (gennumus_iso_branch != 0) {
				gennumus_iso_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_iso_branch does not exist!\n");
				exit(1);
			}
			gennumus_iso_isLoaded = true;
		}
		return *gennumus_iso_;
	}
	const vector<float> &gennumus_mass()
	{
		if (not gennumus_mass_isLoaded) {
			if (gennumus_mass_branch != 0) {
				gennumus_mass_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_mass_branch does not exist!\n");
				exit(1);
			}
			gennumus_mass_isLoaded = true;
		}
		return *gennumus_mass_;
	}
	const vector<int> &gennumus_id()
	{
		if (not gennumus_id_isLoaded) {
			if (gennumus_id_branch != 0) {
				gennumus_id_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_id_branch does not exist!\n");
				exit(1);
			}
			gennumus_id_isLoaded = true;
		}
		return *gennumus_id_;
	}
	const vector<int> &gennumus__genpsidx()
	{
		if (not gennumus__genpsidx_isLoaded) {
			if (gennumus__genpsidx_branch != 0) {
				gennumus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gennumus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gennumus__genpsidx_isLoaded = true;
		}
		return *gennumus__genpsidx_;
	}
	const vector<int> &gennumus_status()
	{
		if (not gennumus_status_isLoaded) {
			if (gennumus_status_branch != 0) {
				gennumus_status_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_status_branch does not exist!\n");
				exit(1);
			}
			gennumus_status_isLoaded = true;
		}
		return *gennumus_status_;
	}
	const vector<bool> &gennumus_fromHardProcessBeforeFSR()
	{
		if (not gennumus_fromHardProcessBeforeFSR_isLoaded) {
			if (gennumus_fromHardProcessBeforeFSR_branch != 0) {
				gennumus_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennumus_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gennumus_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gennumus_fromHardProcessDecayed()
	{
		if (not gennumus_fromHardProcessDecayed_isLoaded) {
			if (gennumus_fromHardProcessDecayed_branch != 0) {
				gennumus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gennumus_fromHardProcessDecayed_isLoaded = true;
		}
		return *gennumus_fromHardProcessDecayed_;
	}
	const vector<bool> &gennumus_fromHardProcessFinalState()
	{
		if (not gennumus_fromHardProcessFinalState_isLoaded) {
			if (gennumus_fromHardProcessFinalState_branch != 0) {
				gennumus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gennumus_fromHardProcessFinalState_isLoaded = true;
		}
		return *gennumus_fromHardProcessFinalState_;
	}
	const vector<bool> &gennumus_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gennumus_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gennumus_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gennumus_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennumus_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gennumus_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gennumus_isDirectPromptTauDecayProductFinalState()
	{
		if (not gennumus_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gennumus_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gennumus_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennumus_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gennumus_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gennumus_isHardProcess()
	{
		if (not gennumus_isHardProcess_isLoaded) {
			if (gennumus_isHardProcess_branch != 0) {
				gennumus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gennumus_isHardProcess_isLoaded = true;
		}
		return *gennumus_isHardProcess_;
	}
	const vector<bool> &gennumus_isLastCopy()
	{
		if (not gennumus_isLastCopy_isLoaded) {
			if (gennumus_isLastCopy_branch != 0) {
				gennumus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gennumus_isLastCopy_isLoaded = true;
		}
		return *gennumus_isLastCopy_;
	}
	const vector<bool> &gennumus_isLastCopyBeforeFSR()
	{
		if (not gennumus_isLastCopyBeforeFSR_isLoaded) {
			if (gennumus_isLastCopyBeforeFSR_branch != 0) {
				gennumus_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennumus_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gennumus_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gennumus_isMostlyLikePythia6Status3()
	{
		if (not gennumus_isMostlyLikePythia6Status3_isLoaded) {
			if (gennumus_isMostlyLikePythia6Status3_branch != 0) {
				gennumus_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gennumus_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gennumus_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gennumus_isPromptDecayed()
	{
		if (not gennumus_isPromptDecayed_isLoaded) {
			if (gennumus_isPromptDecayed_branch != 0) {
				gennumus_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gennumus_isPromptDecayed_isLoaded = true;
		}
		return *gennumus_isPromptDecayed_;
	}
	const vector<bool> &gennumus_isPromptFinalState()
	{
		if (not gennumus_isPromptFinalState_isLoaded) {
			if (gennumus_isPromptFinalState_branch != 0) {
				gennumus_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gennumus_isPromptFinalState_isLoaded = true;
		}
		return *gennumus_isPromptFinalState_;
	}
	const vector<vector<int> > &gennumus_lepdaughter_id()
	{
		if (not gennumus_lepdaughter_id_isLoaded) {
			if (gennumus_lepdaughter_id_branch != 0) {
				gennumus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gennumus_lepdaughter_id_isLoaded = true;
		}
		return *gennumus_lepdaughter_id_;
	}
	const vector<int> &gennumus_gentaudecay()
	{
		if (not gennumus_gentaudecay_isLoaded) {
			if (gennumus_gentaudecay_branch != 0) {
				gennumus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gennumus_gentaudecay_isLoaded = true;
		}
		return *gennumus_gentaudecay_;
	}
	int &gen_nfromtnumus_()
	{
		if (not gen_nfromtnumus__isLoaded) {
			if (gen_nfromtnumus__branch != 0) {
				gen_nfromtnumus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtnumus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtnumus__isLoaded = true;
		}
		return gen_nfromtnumus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_motherp4()
	{
		if (not gennumus_motherp4_isLoaded) {
			if (gennumus_motherp4_branch != 0) {
				gennumus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_motherp4_branch does not exist!\n");
				exit(1);
			}
			gennumus_motherp4_isLoaded = true;
		}
		return *gennumus_motherp4_;
	}
	const vector<float> &gennumus_mothercharge()
	{
		if (not gennumus_mothercharge_isLoaded) {
			if (gennumus_mothercharge_branch != 0) {
				gennumus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gennumus_mothercharge_isLoaded = true;
		}
		return *gennumus_mothercharge_;
	}
	const vector<int> &gennumus_motherid()
	{
		if (not gennumus_motherid_isLoaded) {
			if (gennumus_motherid_branch != 0) {
				gennumus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_motherid_branch does not exist!\n");
				exit(1);
			}
			gennumus_motherid_isLoaded = true;
		}
		return *gennumus_motherid_;
	}
	const vector<int> &gennumus_motheridx()
	{
		if (not gennumus_motheridx_isLoaded) {
			if (gennumus_motheridx_branch != 0) {
				gennumus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_motheridx_branch does not exist!\n");
				exit(1);
			}
			gennumus_motheridx_isLoaded = true;
		}
		return *gennumus_motheridx_;
	}
	const vector<int> &gennumus_motherstatus()
	{
		if (not gennumus_motherstatus_isLoaded) {
			if (gennumus_motherstatus_branch != 0) {
				gennumus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gennumus_motherstatus_isLoaded = true;
		}
		return *gennumus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_gmotherp4()
	{
		if (not gennumus_gmotherp4_isLoaded) {
			if (gennumus_gmotherp4_branch != 0) {
				gennumus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennumus_gmotherp4_isLoaded = true;
		}
		return *gennumus_gmotherp4_;
	}
	const vector<int> &gennumus_gmothercharge()
	{
		if (not gennumus_gmothercharge_isLoaded) {
			if (gennumus_gmothercharge_branch != 0) {
				gennumus_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennumus_gmothercharge_isLoaded = true;
		}
		return *gennumus_gmothercharge_;
	}
	const vector<int> &gennumus_gmotherid()
	{
		if (not gennumus_gmotherid_isLoaded) {
			if (gennumus_gmotherid_branch != 0) {
				gennumus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gennumus_gmotherid_isLoaded = true;
		}
		return *gennumus_gmotherid_;
	}
	const vector<int> &gennumus_gmotheridx()
	{
		if (not gennumus_gmotheridx_isLoaded) {
			if (gennumus_gmotheridx_branch != 0) {
				gennumus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennumus_gmotheridx_isLoaded = true;
		}
		return *gennumus_gmotheridx_;
	}
	const vector<int> &gennumus_gmotherstatus()
	{
		if (not gennumus_gmotherstatus_isLoaded) {
			if (gennumus_gmotherstatus_branch != 0) {
				gennumus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennumus_gmotherstatus_isLoaded = true;
		}
		return *gennumus_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplemotherp4()
	{
		if (not gennumus_simplemotherp4_isLoaded) {
			if (gennumus_simplemotherp4_branch != 0) {
				gennumus_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplemotherp4_isLoaded = true;
		}
		return *gennumus_simplemotherp4_;
	}
	const vector<int> &gennumus_simplemothercharge()
	{
		if (not gennumus_simplemothercharge_isLoaded) {
			if (gennumus_simplemothercharge_branch != 0) {
				gennumus_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplemothercharge_isLoaded = true;
		}
		return *gennumus_simplemothercharge_;
	}
	const vector<int> &gennumus_simplemotherid()
	{
		if (not gennumus_simplemotherid_isLoaded) {
			if (gennumus_simplemotherid_branch != 0) {
				gennumus_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplemotherid_isLoaded = true;
		}
		return *gennumus_simplemotherid_;
	}
	const vector<int> &gennumus_simplemotheridx()
	{
		if (not gennumus_simplemotheridx_isLoaded) {
			if (gennumus_simplemotheridx_branch != 0) {
				gennumus_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplemotheridx_isLoaded = true;
		}
		return *gennumus_simplemotheridx_;
	}
	const vector<int> &gennumus_simplemotherstatus()
	{
		if (not gennumus_simplemotherstatus_isLoaded) {
			if (gennumus_simplemotherstatus_branch != 0) {
				gennumus_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplemotherstatus_isLoaded = true;
		}
		return *gennumus_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplegmotherp4()
	{
		if (not gennumus_simplegmotherp4_isLoaded) {
			if (gennumus_simplegmotherp4_branch != 0) {
				gennumus_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplegmotherp4_isLoaded = true;
		}
		return *gennumus_simplegmotherp4_;
	}
	const vector<int> &gennumus_simplegmothercharge()
	{
		if (not gennumus_simplegmothercharge_isLoaded) {
			if (gennumus_simplegmothercharge_branch != 0) {
				gennumus_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplegmothercharge_isLoaded = true;
		}
		return *gennumus_simplegmothercharge_;
	}
	const vector<int> &gennumus_simplegmotherid()
	{
		if (not gennumus_simplegmotherid_isLoaded) {
			if (gennumus_simplegmotherid_branch != 0) {
				gennumus_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplegmotherid_isLoaded = true;
		}
		return *gennumus_simplegmotherid_;
	}
	const vector<int> &gennumus_simplegmotheridx()
	{
		if (not gennumus_simplegmotheridx_isLoaded) {
			if (gennumus_simplegmotheridx_branch != 0) {
				gennumus_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplegmotheridx_isLoaded = true;
		}
		return *gennumus_simplegmotheridx_;
	}
	const vector<int> &gennumus_simplegmotherstatus()
	{
		if (not gennumus_simplegmotherstatus_isLoaded) {
			if (gennumus_simplegmotherstatus_branch != 0) {
				gennumus_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennumus_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennumus_simplegmotherstatus_isLoaded = true;
		}
		return *gennumus_simplegmotherstatus_;
	}
	const vector<bool> &gennutaus_isfromt()
	{
		if (not gennutaus_isfromt_isLoaded) {
			if (gennutaus_isfromt_branch != 0) {
				gennutaus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isfromt_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isfromt_isLoaded = true;
		}
		return *gennutaus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_p4()
	{
		if (not gennutaus_p4_isLoaded) {
			if (gennutaus_p4_branch != 0) {
				gennutaus_p4_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_p4_branch does not exist!\n");
				exit(1);
			}
			gennutaus_p4_isLoaded = true;
		}
		return *gennutaus_p4_;
	}
	const vector<float> &gennutaus_charge()
	{
		if (not gennutaus_charge_isLoaded) {
			if (gennutaus_charge_branch != 0) {
				gennutaus_charge_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_charge_branch does not exist!\n");
				exit(1);
			}
			gennutaus_charge_isLoaded = true;
		}
		return *gennutaus_charge_;
	}
	const vector<float> &gennutaus_iso()
	{
		if (not gennutaus_iso_isLoaded) {
			if (gennutaus_iso_branch != 0) {
				gennutaus_iso_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_iso_branch does not exist!\n");
				exit(1);
			}
			gennutaus_iso_isLoaded = true;
		}
		return *gennutaus_iso_;
	}
	const vector<float> &gennutaus_mass()
	{
		if (not gennutaus_mass_isLoaded) {
			if (gennutaus_mass_branch != 0) {
				gennutaus_mass_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_mass_branch does not exist!\n");
				exit(1);
			}
			gennutaus_mass_isLoaded = true;
		}
		return *gennutaus_mass_;
	}
	const vector<int> &gennutaus_id()
	{
		if (not gennutaus_id_isLoaded) {
			if (gennutaus_id_branch != 0) {
				gennutaus_id_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_id_branch does not exist!\n");
				exit(1);
			}
			gennutaus_id_isLoaded = true;
		}
		return *gennutaus_id_;
	}
	const vector<int> &gennutaus__genpsidx()
	{
		if (not gennutaus__genpsidx_isLoaded) {
			if (gennutaus__genpsidx_branch != 0) {
				gennutaus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gennutaus__genpsidx_isLoaded = true;
		}
		return *gennutaus__genpsidx_;
	}
	const vector<int> &gennutaus_status()
	{
		if (not gennutaus_status_isLoaded) {
			if (gennutaus_status_branch != 0) {
				gennutaus_status_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_status_branch does not exist!\n");
				exit(1);
			}
			gennutaus_status_isLoaded = true;
		}
		return *gennutaus_status_;
	}
	const vector<bool> &gennutaus_fromHardProcessBeforeFSR()
	{
		if (not gennutaus_fromHardProcessBeforeFSR_isLoaded) {
			if (gennutaus_fromHardProcessBeforeFSR_branch != 0) {
				gennutaus_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennutaus_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gennutaus_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gennutaus_fromHardProcessDecayed()
	{
		if (not gennutaus_fromHardProcessDecayed_isLoaded) {
			if (gennutaus_fromHardProcessDecayed_branch != 0) {
				gennutaus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gennutaus_fromHardProcessDecayed_isLoaded = true;
		}
		return *gennutaus_fromHardProcessDecayed_;
	}
	const vector<bool> &gennutaus_fromHardProcessFinalState()
	{
		if (not gennutaus_fromHardProcessFinalState_isLoaded) {
			if (gennutaus_fromHardProcessFinalState_branch != 0) {
				gennutaus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gennutaus_fromHardProcessFinalState_isLoaded = true;
		}
		return *gennutaus_fromHardProcessFinalState_;
	}
	const vector<bool> &gennutaus_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gennutaus_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gennutaus_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gennutaus_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gennutaus_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gennutaus_isDirectPromptTauDecayProductFinalState()
	{
		if (not gennutaus_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gennutaus_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gennutaus_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gennutaus_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gennutaus_isHardProcess()
	{
		if (not gennutaus_isHardProcess_isLoaded) {
			if (gennutaus_isHardProcess_branch != 0) {
				gennutaus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isHardProcess_isLoaded = true;
		}
		return *gennutaus_isHardProcess_;
	}
	const vector<bool> &gennutaus_isLastCopy()
	{
		if (not gennutaus_isLastCopy_isLoaded) {
			if (gennutaus_isLastCopy_branch != 0) {
				gennutaus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isLastCopy_isLoaded = true;
		}
		return *gennutaus_isLastCopy_;
	}
	const vector<bool> &gennutaus_isLastCopyBeforeFSR()
	{
		if (not gennutaus_isLastCopyBeforeFSR_isLoaded) {
			if (gennutaus_isLastCopyBeforeFSR_branch != 0) {
				gennutaus_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gennutaus_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gennutaus_isMostlyLikePythia6Status3()
	{
		if (not gennutaus_isMostlyLikePythia6Status3_isLoaded) {
			if (gennutaus_isMostlyLikePythia6Status3_branch != 0) {
				gennutaus_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gennutaus_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gennutaus_isPromptDecayed()
	{
		if (not gennutaus_isPromptDecayed_isLoaded) {
			if (gennutaus_isPromptDecayed_branch != 0) {
				gennutaus_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isPromptDecayed_isLoaded = true;
		}
		return *gennutaus_isPromptDecayed_;
	}
	const vector<bool> &gennutaus_isPromptFinalState()
	{
		if (not gennutaus_isPromptFinalState_isLoaded) {
			if (gennutaus_isPromptFinalState_branch != 0) {
				gennutaus_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gennutaus_isPromptFinalState_isLoaded = true;
		}
		return *gennutaus_isPromptFinalState_;
	}
	const vector<vector<int> > &gennutaus_lepdaughter_id()
	{
		if (not gennutaus_lepdaughter_id_isLoaded) {
			if (gennutaus_lepdaughter_id_branch != 0) {
				gennutaus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gennutaus_lepdaughter_id_isLoaded = true;
		}
		return *gennutaus_lepdaughter_id_;
	}
	const vector<int> &gennutaus_gentaudecay()
	{
		if (not gennutaus_gentaudecay_isLoaded) {
			if (gennutaus_gentaudecay_branch != 0) {
				gennutaus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gentaudecay_isLoaded = true;
		}
		return *gennutaus_gentaudecay_;
	}
	int &gen_nfromtnutaus_()
	{
		if (not gen_nfromtnutaus__isLoaded) {
			if (gen_nfromtnutaus__branch != 0) {
				gen_nfromtnutaus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtnutaus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtnutaus__isLoaded = true;
		}
		return gen_nfromtnutaus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_motherp4()
	{
		if (not gennutaus_motherp4_isLoaded) {
			if (gennutaus_motherp4_branch != 0) {
				gennutaus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_motherp4_branch does not exist!\n");
				exit(1);
			}
			gennutaus_motherp4_isLoaded = true;
		}
		return *gennutaus_motherp4_;
	}
	const vector<float> &gennutaus_mothercharge()
	{
		if (not gennutaus_mothercharge_isLoaded) {
			if (gennutaus_mothercharge_branch != 0) {
				gennutaus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gennutaus_mothercharge_isLoaded = true;
		}
		return *gennutaus_mothercharge_;
	}
	const vector<int> &gennutaus_motherid()
	{
		if (not gennutaus_motherid_isLoaded) {
			if (gennutaus_motherid_branch != 0) {
				gennutaus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_motherid_branch does not exist!\n");
				exit(1);
			}
			gennutaus_motherid_isLoaded = true;
		}
		return *gennutaus_motherid_;
	}
	const vector<int> &gennutaus_motheridx()
	{
		if (not gennutaus_motheridx_isLoaded) {
			if (gennutaus_motheridx_branch != 0) {
				gennutaus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_motheridx_branch does not exist!\n");
				exit(1);
			}
			gennutaus_motheridx_isLoaded = true;
		}
		return *gennutaus_motheridx_;
	}
	const vector<int> &gennutaus_motherstatus()
	{
		if (not gennutaus_motherstatus_isLoaded) {
			if (gennutaus_motherstatus_branch != 0) {
				gennutaus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gennutaus_motherstatus_isLoaded = true;
		}
		return *gennutaus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_gmotherp4()
	{
		if (not gennutaus_gmotherp4_isLoaded) {
			if (gennutaus_gmotherp4_branch != 0) {
				gennutaus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gmotherp4_isLoaded = true;
		}
		return *gennutaus_gmotherp4_;
	}
	const vector<int> &gennutaus_gmothercharge()
	{
		if (not gennutaus_gmothercharge_isLoaded) {
			if (gennutaus_gmothercharge_branch != 0) {
				gennutaus_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gmothercharge_isLoaded = true;
		}
		return *gennutaus_gmothercharge_;
	}
	const vector<int> &gennutaus_gmotherid()
	{
		if (not gennutaus_gmotherid_isLoaded) {
			if (gennutaus_gmotherid_branch != 0) {
				gennutaus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gmotherid_isLoaded = true;
		}
		return *gennutaus_gmotherid_;
	}
	const vector<int> &gennutaus_gmotheridx()
	{
		if (not gennutaus_gmotheridx_isLoaded) {
			if (gennutaus_gmotheridx_branch != 0) {
				gennutaus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gmotheridx_isLoaded = true;
		}
		return *gennutaus_gmotheridx_;
	}
	const vector<int> &gennutaus_gmotherstatus()
	{
		if (not gennutaus_gmotherstatus_isLoaded) {
			if (gennutaus_gmotherstatus_branch != 0) {
				gennutaus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennutaus_gmotherstatus_isLoaded = true;
		}
		return *gennutaus_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplemotherp4()
	{
		if (not gennutaus_simplemotherp4_isLoaded) {
			if (gennutaus_simplemotherp4_branch != 0) {
				gennutaus_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplemotherp4_isLoaded = true;
		}
		return *gennutaus_simplemotherp4_;
	}
	const vector<int> &gennutaus_simplemothercharge()
	{
		if (not gennutaus_simplemothercharge_isLoaded) {
			if (gennutaus_simplemothercharge_branch != 0) {
				gennutaus_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplemothercharge_isLoaded = true;
		}
		return *gennutaus_simplemothercharge_;
	}
	const vector<int> &gennutaus_simplemotherid()
	{
		if (not gennutaus_simplemotherid_isLoaded) {
			if (gennutaus_simplemotherid_branch != 0) {
				gennutaus_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplemotherid_isLoaded = true;
		}
		return *gennutaus_simplemotherid_;
	}
	const vector<int> &gennutaus_simplemotheridx()
	{
		if (not gennutaus_simplemotheridx_isLoaded) {
			if (gennutaus_simplemotheridx_branch != 0) {
				gennutaus_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplemotheridx_isLoaded = true;
		}
		return *gennutaus_simplemotheridx_;
	}
	const vector<int> &gennutaus_simplemotherstatus()
	{
		if (not gennutaus_simplemotherstatus_isLoaded) {
			if (gennutaus_simplemotherstatus_branch != 0) {
				gennutaus_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplemotherstatus_isLoaded = true;
		}
		return *gennutaus_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplegmotherp4()
	{
		if (not gennutaus_simplegmotherp4_isLoaded) {
			if (gennutaus_simplegmotherp4_branch != 0) {
				gennutaus_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplegmotherp4_isLoaded = true;
		}
		return *gennutaus_simplegmotherp4_;
	}
	const vector<int> &gennutaus_simplegmothercharge()
	{
		if (not gennutaus_simplegmothercharge_isLoaded) {
			if (gennutaus_simplegmothercharge_branch != 0) {
				gennutaus_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplegmothercharge_isLoaded = true;
		}
		return *gennutaus_simplegmothercharge_;
	}
	const vector<int> &gennutaus_simplegmotherid()
	{
		if (not gennutaus_simplegmotherid_isLoaded) {
			if (gennutaus_simplegmotherid_branch != 0) {
				gennutaus_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplegmotherid_isLoaded = true;
		}
		return *gennutaus_simplegmotherid_;
	}
	const vector<int> &gennutaus_simplegmotheridx()
	{
		if (not gennutaus_simplegmotheridx_isLoaded) {
			if (gennutaus_simplegmotheridx_branch != 0) {
				gennutaus_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplegmotheridx_isLoaded = true;
		}
		return *gennutaus_simplegmotheridx_;
	}
	const vector<int> &gennutaus_simplegmotherstatus()
	{
		if (not gennutaus_simplegmotherstatus_isLoaded) {
			if (gennutaus_simplegmotherstatus_branch != 0) {
				gennutaus_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennutaus_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennutaus_simplegmotherstatus_isLoaded = true;
		}
		return *gennutaus_simplegmotherstatus_;
	}
	const vector<bool> &gents_isfromt()
	{
		if (not gents_isfromt_isLoaded) {
			if (gents_isfromt_branch != 0) {
				gents_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gents_isfromt_branch does not exist!\n");
				exit(1);
			}
			gents_isfromt_isLoaded = true;
		}
		return *gents_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4()
	{
		if (not gents_p4_isLoaded) {
			if (gents_p4_branch != 0) {
				gents_p4_branch->GetEntry(index);
			} else { 
				printf("branch gents_p4_branch does not exist!\n");
				exit(1);
			}
			gents_p4_isLoaded = true;
		}
		return *gents_p4_;
	}
	const vector<float> &gents_charge()
	{
		if (not gents_charge_isLoaded) {
			if (gents_charge_branch != 0) {
				gents_charge_branch->GetEntry(index);
			} else { 
				printf("branch gents_charge_branch does not exist!\n");
				exit(1);
			}
			gents_charge_isLoaded = true;
		}
		return *gents_charge_;
	}
	const vector<float> &gents_iso()
	{
		if (not gents_iso_isLoaded) {
			if (gents_iso_branch != 0) {
				gents_iso_branch->GetEntry(index);
			} else { 
				printf("branch gents_iso_branch does not exist!\n");
				exit(1);
			}
			gents_iso_isLoaded = true;
		}
		return *gents_iso_;
	}
	const vector<float> &gents_mass()
	{
		if (not gents_mass_isLoaded) {
			if (gents_mass_branch != 0) {
				gents_mass_branch->GetEntry(index);
			} else { 
				printf("branch gents_mass_branch does not exist!\n");
				exit(1);
			}
			gents_mass_isLoaded = true;
		}
		return *gents_mass_;
	}
	const vector<int> &gents_id()
	{
		if (not gents_id_isLoaded) {
			if (gents_id_branch != 0) {
				gents_id_branch->GetEntry(index);
			} else { 
				printf("branch gents_id_branch does not exist!\n");
				exit(1);
			}
			gents_id_isLoaded = true;
		}
		return *gents_id_;
	}
	const vector<int> &gents__genpsidx()
	{
		if (not gents__genpsidx_isLoaded) {
			if (gents__genpsidx_branch != 0) {
				gents__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gents__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gents__genpsidx_isLoaded = true;
		}
		return *gents__genpsidx_;
	}
	const vector<int> &gents_status()
	{
		if (not gents_status_isLoaded) {
			if (gents_status_branch != 0) {
				gents_status_branch->GetEntry(index);
			} else { 
				printf("branch gents_status_branch does not exist!\n");
				exit(1);
			}
			gents_status_isLoaded = true;
		}
		return *gents_status_;
	}
	const vector<bool> &gents_fromHardProcessBeforeFSR()
	{
		if (not gents_fromHardProcessBeforeFSR_isLoaded) {
			if (gents_fromHardProcessBeforeFSR_branch != 0) {
				gents_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gents_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gents_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gents_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gents_fromHardProcessDecayed()
	{
		if (not gents_fromHardProcessDecayed_isLoaded) {
			if (gents_fromHardProcessDecayed_branch != 0) {
				gents_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gents_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gents_fromHardProcessDecayed_isLoaded = true;
		}
		return *gents_fromHardProcessDecayed_;
	}
	const vector<bool> &gents_fromHardProcessFinalState()
	{
		if (not gents_fromHardProcessFinalState_isLoaded) {
			if (gents_fromHardProcessFinalState_branch != 0) {
				gents_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gents_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gents_fromHardProcessFinalState_isLoaded = true;
		}
		return *gents_fromHardProcessFinalState_;
	}
	const vector<bool> &gents_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gents_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gents_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gents_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gents_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gents_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gents_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gents_isDirectPromptTauDecayProductFinalState()
	{
		if (not gents_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gents_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gents_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gents_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gents_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gents_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gents_isHardProcess()
	{
		if (not gents_isHardProcess_isLoaded) {
			if (gents_isHardProcess_branch != 0) {
				gents_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gents_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gents_isHardProcess_isLoaded = true;
		}
		return *gents_isHardProcess_;
	}
	const vector<bool> &gents_isLastCopy()
	{
		if (not gents_isLastCopy_isLoaded) {
			if (gents_isLastCopy_branch != 0) {
				gents_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gents_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gents_isLastCopy_isLoaded = true;
		}
		return *gents_isLastCopy_;
	}
	const vector<bool> &gents_isLastCopyBeforeFSR()
	{
		if (not gents_isLastCopyBeforeFSR_isLoaded) {
			if (gents_isLastCopyBeforeFSR_branch != 0) {
				gents_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gents_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gents_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gents_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gents_isMostlyLikePythia6Status3()
	{
		if (not gents_isMostlyLikePythia6Status3_isLoaded) {
			if (gents_isMostlyLikePythia6Status3_branch != 0) {
				gents_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gents_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gents_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gents_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gents_isPromptDecayed()
	{
		if (not gents_isPromptDecayed_isLoaded) {
			if (gents_isPromptDecayed_branch != 0) {
				gents_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gents_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gents_isPromptDecayed_isLoaded = true;
		}
		return *gents_isPromptDecayed_;
	}
	const vector<bool> &gents_isPromptFinalState()
	{
		if (not gents_isPromptFinalState_isLoaded) {
			if (gents_isPromptFinalState_branch != 0) {
				gents_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gents_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gents_isPromptFinalState_isLoaded = true;
		}
		return *gents_isPromptFinalState_;
	}
	const vector<vector<int> > &gents_lepdaughter_id()
	{
		if (not gents_lepdaughter_id_isLoaded) {
			if (gents_lepdaughter_id_branch != 0) {
				gents_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gents_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gents_lepdaughter_id_isLoaded = true;
		}
		return *gents_lepdaughter_id_;
	}
	const vector<int> &gents_gentaudecay()
	{
		if (not gents_gentaudecay_isLoaded) {
			if (gents_gentaudecay_branch != 0) {
				gents_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gents_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gents_gentaudecay_isLoaded = true;
		}
		return *gents_gentaudecay_;
	}
	int &gen_nfromtts_()
	{
		if (not gen_nfromtts__isLoaded) {
			if (gen_nfromtts__branch != 0) {
				gen_nfromtts__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtts__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtts__isLoaded = true;
		}
		return gen_nfromtts__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4()
	{
		if (not gents_motherp4_isLoaded) {
			if (gents_motherp4_branch != 0) {
				gents_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gents_motherp4_branch does not exist!\n");
				exit(1);
			}
			gents_motherp4_isLoaded = true;
		}
		return *gents_motherp4_;
	}
	const vector<float> &gents_mothercharge()
	{
		if (not gents_mothercharge_isLoaded) {
			if (gents_mothercharge_branch != 0) {
				gents_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gents_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gents_mothercharge_isLoaded = true;
		}
		return *gents_mothercharge_;
	}
	const vector<int> &gents_motherid()
	{
		if (not gents_motherid_isLoaded) {
			if (gents_motherid_branch != 0) {
				gents_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gents_motherid_branch does not exist!\n");
				exit(1);
			}
			gents_motherid_isLoaded = true;
		}
		return *gents_motherid_;
	}
	const vector<int> &gents_motheridx()
	{
		if (not gents_motheridx_isLoaded) {
			if (gents_motheridx_branch != 0) {
				gents_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gents_motheridx_branch does not exist!\n");
				exit(1);
			}
			gents_motheridx_isLoaded = true;
		}
		return *gents_motheridx_;
	}
	const vector<int> &gents_motherstatus()
	{
		if (not gents_motherstatus_isLoaded) {
			if (gents_motherstatus_branch != 0) {
				gents_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gents_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gents_motherstatus_isLoaded = true;
		}
		return *gents_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_gmotherp4()
	{
		if (not gents_gmotherp4_isLoaded) {
			if (gents_gmotherp4_branch != 0) {
				gents_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gents_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gents_gmotherp4_isLoaded = true;
		}
		return *gents_gmotherp4_;
	}
	const vector<int> &gents_gmothercharge()
	{
		if (not gents_gmothercharge_isLoaded) {
			if (gents_gmothercharge_branch != 0) {
				gents_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gents_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gents_gmothercharge_isLoaded = true;
		}
		return *gents_gmothercharge_;
	}
	const vector<int> &gents_gmotherid()
	{
		if (not gents_gmotherid_isLoaded) {
			if (gents_gmotherid_branch != 0) {
				gents_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gents_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gents_gmotherid_isLoaded = true;
		}
		return *gents_gmotherid_;
	}
	const vector<int> &gents_gmotheridx()
	{
		if (not gents_gmotheridx_isLoaded) {
			if (gents_gmotheridx_branch != 0) {
				gents_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gents_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gents_gmotheridx_isLoaded = true;
		}
		return *gents_gmotheridx_;
	}
	const vector<int> &gents_gmotherstatus()
	{
		if (not gents_gmotherstatus_isLoaded) {
			if (gents_gmotherstatus_branch != 0) {
				gents_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gents_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gents_gmotherstatus_isLoaded = true;
		}
		return *gents_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplemotherp4()
	{
		if (not gents_simplemotherp4_isLoaded) {
			if (gents_simplemotherp4_branch != 0) {
				gents_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gents_simplemotherp4_isLoaded = true;
		}
		return *gents_simplemotherp4_;
	}
	const vector<int> &gents_simplemothercharge()
	{
		if (not gents_simplemothercharge_isLoaded) {
			if (gents_simplemothercharge_branch != 0) {
				gents_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gents_simplemothercharge_isLoaded = true;
		}
		return *gents_simplemothercharge_;
	}
	const vector<int> &gents_simplemotherid()
	{
		if (not gents_simplemotherid_isLoaded) {
			if (gents_simplemotherid_branch != 0) {
				gents_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gents_simplemotherid_isLoaded = true;
		}
		return *gents_simplemotherid_;
	}
	const vector<int> &gents_simplemotheridx()
	{
		if (not gents_simplemotheridx_isLoaded) {
			if (gents_simplemotheridx_branch != 0) {
				gents_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gents_simplemotheridx_isLoaded = true;
		}
		return *gents_simplemotheridx_;
	}
	const vector<int> &gents_simplemotherstatus()
	{
		if (not gents_simplemotherstatus_isLoaded) {
			if (gents_simplemotherstatus_branch != 0) {
				gents_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gents_simplemotherstatus_isLoaded = true;
		}
		return *gents_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplegmotherp4()
	{
		if (not gents_simplegmotherp4_isLoaded) {
			if (gents_simplegmotherp4_branch != 0) {
				gents_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gents_simplegmotherp4_isLoaded = true;
		}
		return *gents_simplegmotherp4_;
	}
	const vector<int> &gents_simplegmothercharge()
	{
		if (not gents_simplegmothercharge_isLoaded) {
			if (gents_simplegmothercharge_branch != 0) {
				gents_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gents_simplegmothercharge_isLoaded = true;
		}
		return *gents_simplegmothercharge_;
	}
	const vector<int> &gents_simplegmotherid()
	{
		if (not gents_simplegmotherid_isLoaded) {
			if (gents_simplegmotherid_branch != 0) {
				gents_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gents_simplegmotherid_isLoaded = true;
		}
		return *gents_simplegmotherid_;
	}
	const vector<int> &gents_simplegmotheridx()
	{
		if (not gents_simplegmotheridx_isLoaded) {
			if (gents_simplegmotheridx_branch != 0) {
				gents_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gents_simplegmotheridx_isLoaded = true;
		}
		return *gents_simplegmotheridx_;
	}
	const vector<int> &gents_simplegmotherstatus()
	{
		if (not gents_simplegmotherstatus_isLoaded) {
			if (gents_simplegmotherstatus_branch != 0) {
				gents_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gents_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gents_simplegmotherstatus_isLoaded = true;
		}
		return *gents_simplegmotherstatus_;
	}
	const vector<bool> &genbs_isfromt()
	{
		if (not genbs_isfromt_isLoaded) {
			if (genbs_isfromt_branch != 0) {
				genbs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genbs_isfromt_isLoaded = true;
		}
		return *genbs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_p4()
	{
		if (not genbs_p4_isLoaded) {
			if (genbs_p4_branch != 0) {
				genbs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genbs_p4_branch does not exist!\n");
				exit(1);
			}
			genbs_p4_isLoaded = true;
		}
		return *genbs_p4_;
	}
	const vector<float> &genbs_charge()
	{
		if (not genbs_charge_isLoaded) {
			if (genbs_charge_branch != 0) {
				genbs_charge_branch->GetEntry(index);
			} else { 
				printf("branch genbs_charge_branch does not exist!\n");
				exit(1);
			}
			genbs_charge_isLoaded = true;
		}
		return *genbs_charge_;
	}
	const vector<float> &genbs_iso()
	{
		if (not genbs_iso_isLoaded) {
			if (genbs_iso_branch != 0) {
				genbs_iso_branch->GetEntry(index);
			} else { 
				printf("branch genbs_iso_branch does not exist!\n");
				exit(1);
			}
			genbs_iso_isLoaded = true;
		}
		return *genbs_iso_;
	}
	const vector<float> &genbs_mass()
	{
		if (not genbs_mass_isLoaded) {
			if (genbs_mass_branch != 0) {
				genbs_mass_branch->GetEntry(index);
			} else { 
				printf("branch genbs_mass_branch does not exist!\n");
				exit(1);
			}
			genbs_mass_isLoaded = true;
		}
		return *genbs_mass_;
	}
	const vector<int> &genbs_id()
	{
		if (not genbs_id_isLoaded) {
			if (genbs_id_branch != 0) {
				genbs_id_branch->GetEntry(index);
			} else { 
				printf("branch genbs_id_branch does not exist!\n");
				exit(1);
			}
			genbs_id_isLoaded = true;
		}
		return *genbs_id_;
	}
	const vector<int> &genbs__genpsidx()
	{
		if (not genbs__genpsidx_isLoaded) {
			if (genbs__genpsidx_branch != 0) {
				genbs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genbs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genbs__genpsidx_isLoaded = true;
		}
		return *genbs__genpsidx_;
	}
	const vector<int> &genbs_status()
	{
		if (not genbs_status_isLoaded) {
			if (genbs_status_branch != 0) {
				genbs_status_branch->GetEntry(index);
			} else { 
				printf("branch genbs_status_branch does not exist!\n");
				exit(1);
			}
			genbs_status_isLoaded = true;
		}
		return *genbs_status_;
	}
	const vector<bool> &genbs_fromHardProcessBeforeFSR()
	{
		if (not genbs_fromHardProcessBeforeFSR_isLoaded) {
			if (genbs_fromHardProcessBeforeFSR_branch != 0) {
				genbs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genbs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genbs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genbs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genbs_fromHardProcessDecayed()
	{
		if (not genbs_fromHardProcessDecayed_isLoaded) {
			if (genbs_fromHardProcessDecayed_branch != 0) {
				genbs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genbs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genbs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genbs_fromHardProcessDecayed_;
	}
	const vector<bool> &genbs_fromHardProcessFinalState()
	{
		if (not genbs_fromHardProcessFinalState_isLoaded) {
			if (genbs_fromHardProcessFinalState_branch != 0) {
				genbs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genbs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genbs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genbs_fromHardProcessFinalState_;
	}
	const vector<bool> &genbs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genbs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genbs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genbs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genbs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genbs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genbs_isDirectPromptTauDecayProductFinalState()
	{
		if (not genbs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genbs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genbs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genbs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genbs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genbs_isHardProcess()
	{
		if (not genbs_isHardProcess_isLoaded) {
			if (genbs_isHardProcess_branch != 0) {
				genbs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genbs_isHardProcess_isLoaded = true;
		}
		return *genbs_isHardProcess_;
	}
	const vector<bool> &genbs_isLastCopy()
	{
		if (not genbs_isLastCopy_isLoaded) {
			if (genbs_isLastCopy_branch != 0) {
				genbs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genbs_isLastCopy_isLoaded = true;
		}
		return *genbs_isLastCopy_;
	}
	const vector<bool> &genbs_isLastCopyBeforeFSR()
	{
		if (not genbs_isLastCopyBeforeFSR_isLoaded) {
			if (genbs_isLastCopyBeforeFSR_branch != 0) {
				genbs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genbs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genbs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genbs_isMostlyLikePythia6Status3()
	{
		if (not genbs_isMostlyLikePythia6Status3_isLoaded) {
			if (genbs_isMostlyLikePythia6Status3_branch != 0) {
				genbs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genbs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genbs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genbs_isPromptDecayed()
	{
		if (not genbs_isPromptDecayed_isLoaded) {
			if (genbs_isPromptDecayed_branch != 0) {
				genbs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genbs_isPromptDecayed_isLoaded = true;
		}
		return *genbs_isPromptDecayed_;
	}
	const vector<bool> &genbs_isPromptFinalState()
	{
		if (not genbs_isPromptFinalState_isLoaded) {
			if (genbs_isPromptFinalState_branch != 0) {
				genbs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genbs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genbs_isPromptFinalState_isLoaded = true;
		}
		return *genbs_isPromptFinalState_;
	}
	const vector<vector<int> > &genbs_lepdaughter_id()
	{
		if (not genbs_lepdaughter_id_isLoaded) {
			if (genbs_lepdaughter_id_branch != 0) {
				genbs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genbs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genbs_lepdaughter_id_isLoaded = true;
		}
		return *genbs_lepdaughter_id_;
	}
	const vector<int> &genbs_gentaudecay()
	{
		if (not genbs_gentaudecay_isLoaded) {
			if (genbs_gentaudecay_branch != 0) {
				genbs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genbs_gentaudecay_isLoaded = true;
		}
		return *genbs_gentaudecay_;
	}
	int &gen_nfromtbs_()
	{
		if (not gen_nfromtbs__isLoaded) {
			if (gen_nfromtbs__branch != 0) {
				gen_nfromtbs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtbs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtbs__isLoaded = true;
		}
		return gen_nfromtbs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_motherp4()
	{
		if (not genbs_motherp4_isLoaded) {
			if (genbs_motherp4_branch != 0) {
				genbs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genbs_motherp4_isLoaded = true;
		}
		return *genbs_motherp4_;
	}
	const vector<float> &genbs_mothercharge()
	{
		if (not genbs_mothercharge_isLoaded) {
			if (genbs_mothercharge_branch != 0) {
				genbs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genbs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genbs_mothercharge_isLoaded = true;
		}
		return *genbs_mothercharge_;
	}
	const vector<int> &genbs_motherid()
	{
		if (not genbs_motherid_isLoaded) {
			if (genbs_motherid_branch != 0) {
				genbs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genbs_motherid_branch does not exist!\n");
				exit(1);
			}
			genbs_motherid_isLoaded = true;
		}
		return *genbs_motherid_;
	}
	const vector<int> &genbs_motheridx()
	{
		if (not genbs_motheridx_isLoaded) {
			if (genbs_motheridx_branch != 0) {
				genbs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genbs_motheridx_isLoaded = true;
		}
		return *genbs_motheridx_;
	}
	const vector<int> &genbs_motherstatus()
	{
		if (not genbs_motherstatus_isLoaded) {
			if (genbs_motherstatus_branch != 0) {
				genbs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genbs_motherstatus_isLoaded = true;
		}
		return *genbs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_gmotherp4()
	{
		if (not genbs_gmotherp4_isLoaded) {
			if (genbs_gmotherp4_branch != 0) {
				genbs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genbs_gmotherp4_isLoaded = true;
		}
		return *genbs_gmotherp4_;
	}
	const vector<int> &genbs_gmothercharge()
	{
		if (not genbs_gmothercharge_isLoaded) {
			if (genbs_gmothercharge_branch != 0) {
				genbs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genbs_gmothercharge_isLoaded = true;
		}
		return *genbs_gmothercharge_;
	}
	const vector<int> &genbs_gmotherid()
	{
		if (not genbs_gmotherid_isLoaded) {
			if (genbs_gmotherid_branch != 0) {
				genbs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genbs_gmotherid_isLoaded = true;
		}
		return *genbs_gmotherid_;
	}
	const vector<int> &genbs_gmotheridx()
	{
		if (not genbs_gmotheridx_isLoaded) {
			if (genbs_gmotheridx_branch != 0) {
				genbs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genbs_gmotheridx_isLoaded = true;
		}
		return *genbs_gmotheridx_;
	}
	const vector<int> &genbs_gmotherstatus()
	{
		if (not genbs_gmotherstatus_isLoaded) {
			if (genbs_gmotherstatus_branch != 0) {
				genbs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genbs_gmotherstatus_isLoaded = true;
		}
		return *genbs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplemotherp4()
	{
		if (not genbs_simplemotherp4_isLoaded) {
			if (genbs_simplemotherp4_branch != 0) {
				genbs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genbs_simplemotherp4_isLoaded = true;
		}
		return *genbs_simplemotherp4_;
	}
	const vector<int> &genbs_simplemothercharge()
	{
		if (not genbs_simplemothercharge_isLoaded) {
			if (genbs_simplemothercharge_branch != 0) {
				genbs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genbs_simplemothercharge_isLoaded = true;
		}
		return *genbs_simplemothercharge_;
	}
	const vector<int> &genbs_simplemotherid()
	{
		if (not genbs_simplemotherid_isLoaded) {
			if (genbs_simplemotherid_branch != 0) {
				genbs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genbs_simplemotherid_isLoaded = true;
		}
		return *genbs_simplemotherid_;
	}
	const vector<int> &genbs_simplemotheridx()
	{
		if (not genbs_simplemotheridx_isLoaded) {
			if (genbs_simplemotheridx_branch != 0) {
				genbs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genbs_simplemotheridx_isLoaded = true;
		}
		return *genbs_simplemotheridx_;
	}
	const vector<int> &genbs_simplemotherstatus()
	{
		if (not genbs_simplemotherstatus_isLoaded) {
			if (genbs_simplemotherstatus_branch != 0) {
				genbs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genbs_simplemotherstatus_isLoaded = true;
		}
		return *genbs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplegmotherp4()
	{
		if (not genbs_simplegmotherp4_isLoaded) {
			if (genbs_simplegmotherp4_branch != 0) {
				genbs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genbs_simplegmotherp4_isLoaded = true;
		}
		return *genbs_simplegmotherp4_;
	}
	const vector<int> &genbs_simplegmothercharge()
	{
		if (not genbs_simplegmothercharge_isLoaded) {
			if (genbs_simplegmothercharge_branch != 0) {
				genbs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genbs_simplegmothercharge_isLoaded = true;
		}
		return *genbs_simplegmothercharge_;
	}
	const vector<int> &genbs_simplegmotherid()
	{
		if (not genbs_simplegmotherid_isLoaded) {
			if (genbs_simplegmotherid_branch != 0) {
				genbs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genbs_simplegmotherid_isLoaded = true;
		}
		return *genbs_simplegmotherid_;
	}
	const vector<int> &genbs_simplegmotheridx()
	{
		if (not genbs_simplegmotheridx_isLoaded) {
			if (genbs_simplegmotheridx_branch != 0) {
				genbs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genbs_simplegmotheridx_isLoaded = true;
		}
		return *genbs_simplegmotheridx_;
	}
	const vector<int> &genbs_simplegmotherstatus()
	{
		if (not genbs_simplegmotherstatus_isLoaded) {
			if (genbs_simplegmotherstatus_branch != 0) {
				genbs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genbs_simplegmotherstatus_isLoaded = true;
		}
		return *genbs_simplegmotherstatus_;
	}
	const vector<bool> &gencs_isfromt()
	{
		if (not gencs_isfromt_isLoaded) {
			if (gencs_isfromt_branch != 0) {
				gencs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isfromt_branch does not exist!\n");
				exit(1);
			}
			gencs_isfromt_isLoaded = true;
		}
		return *gencs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_p4()
	{
		if (not gencs_p4_isLoaded) {
			if (gencs_p4_branch != 0) {
				gencs_p4_branch->GetEntry(index);
			} else { 
				printf("branch gencs_p4_branch does not exist!\n");
				exit(1);
			}
			gencs_p4_isLoaded = true;
		}
		return *gencs_p4_;
	}
	const vector<float> &gencs_charge()
	{
		if (not gencs_charge_isLoaded) {
			if (gencs_charge_branch != 0) {
				gencs_charge_branch->GetEntry(index);
			} else { 
				printf("branch gencs_charge_branch does not exist!\n");
				exit(1);
			}
			gencs_charge_isLoaded = true;
		}
		return *gencs_charge_;
	}
	const vector<float> &gencs_iso()
	{
		if (not gencs_iso_isLoaded) {
			if (gencs_iso_branch != 0) {
				gencs_iso_branch->GetEntry(index);
			} else { 
				printf("branch gencs_iso_branch does not exist!\n");
				exit(1);
			}
			gencs_iso_isLoaded = true;
		}
		return *gencs_iso_;
	}
	const vector<float> &gencs_mass()
	{
		if (not gencs_mass_isLoaded) {
			if (gencs_mass_branch != 0) {
				gencs_mass_branch->GetEntry(index);
			} else { 
				printf("branch gencs_mass_branch does not exist!\n");
				exit(1);
			}
			gencs_mass_isLoaded = true;
		}
		return *gencs_mass_;
	}
	const vector<int> &gencs_id()
	{
		if (not gencs_id_isLoaded) {
			if (gencs_id_branch != 0) {
				gencs_id_branch->GetEntry(index);
			} else { 
				printf("branch gencs_id_branch does not exist!\n");
				exit(1);
			}
			gencs_id_isLoaded = true;
		}
		return *gencs_id_;
	}
	const vector<int> &gencs__genpsidx()
	{
		if (not gencs__genpsidx_isLoaded) {
			if (gencs__genpsidx_branch != 0) {
				gencs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gencs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gencs__genpsidx_isLoaded = true;
		}
		return *gencs__genpsidx_;
	}
	const vector<int> &gencs_status()
	{
		if (not gencs_status_isLoaded) {
			if (gencs_status_branch != 0) {
				gencs_status_branch->GetEntry(index);
			} else { 
				printf("branch gencs_status_branch does not exist!\n");
				exit(1);
			}
			gencs_status_isLoaded = true;
		}
		return *gencs_status_;
	}
	const vector<bool> &gencs_fromHardProcessBeforeFSR()
	{
		if (not gencs_fromHardProcessBeforeFSR_isLoaded) {
			if (gencs_fromHardProcessBeforeFSR_branch != 0) {
				gencs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gencs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gencs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *gencs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &gencs_fromHardProcessDecayed()
	{
		if (not gencs_fromHardProcessDecayed_isLoaded) {
			if (gencs_fromHardProcessDecayed_branch != 0) {
				gencs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gencs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gencs_fromHardProcessDecayed_isLoaded = true;
		}
		return *gencs_fromHardProcessDecayed_;
	}
	const vector<bool> &gencs_fromHardProcessFinalState()
	{
		if (not gencs_fromHardProcessFinalState_isLoaded) {
			if (gencs_fromHardProcessFinalState_branch != 0) {
				gencs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gencs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gencs_fromHardProcessFinalState_isLoaded = true;
		}
		return *gencs_fromHardProcessFinalState_;
	}
	const vector<bool> &gencs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not gencs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (gencs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				gencs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gencs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *gencs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &gencs_isDirectPromptTauDecayProductFinalState()
	{
		if (not gencs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (gencs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				gencs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			gencs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *gencs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &gencs_isHardProcess()
	{
		if (not gencs_isHardProcess_isLoaded) {
			if (gencs_isHardProcess_branch != 0) {
				gencs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gencs_isHardProcess_isLoaded = true;
		}
		return *gencs_isHardProcess_;
	}
	const vector<bool> &gencs_isLastCopy()
	{
		if (not gencs_isLastCopy_isLoaded) {
			if (gencs_isLastCopy_branch != 0) {
				gencs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gencs_isLastCopy_isLoaded = true;
		}
		return *gencs_isLastCopy_;
	}
	const vector<bool> &gencs_isLastCopyBeforeFSR()
	{
		if (not gencs_isLastCopyBeforeFSR_isLoaded) {
			if (gencs_isLastCopyBeforeFSR_branch != 0) {
				gencs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			gencs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *gencs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &gencs_isMostlyLikePythia6Status3()
	{
		if (not gencs_isMostlyLikePythia6Status3_isLoaded) {
			if (gencs_isMostlyLikePythia6Status3_branch != 0) {
				gencs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			gencs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *gencs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &gencs_isPromptDecayed()
	{
		if (not gencs_isPromptDecayed_isLoaded) {
			if (gencs_isPromptDecayed_branch != 0) {
				gencs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			gencs_isPromptDecayed_isLoaded = true;
		}
		return *gencs_isPromptDecayed_;
	}
	const vector<bool> &gencs_isPromptFinalState()
	{
		if (not gencs_isPromptFinalState_isLoaded) {
			if (gencs_isPromptFinalState_branch != 0) {
				gencs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gencs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			gencs_isPromptFinalState_isLoaded = true;
		}
		return *gencs_isPromptFinalState_;
	}
	const vector<vector<int> > &gencs_lepdaughter_id()
	{
		if (not gencs_lepdaughter_id_isLoaded) {
			if (gencs_lepdaughter_id_branch != 0) {
				gencs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gencs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gencs_lepdaughter_id_isLoaded = true;
		}
		return *gencs_lepdaughter_id_;
	}
	const vector<int> &gencs_gentaudecay()
	{
		if (not gencs_gentaudecay_isLoaded) {
			if (gencs_gentaudecay_branch != 0) {
				gencs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gencs_gentaudecay_isLoaded = true;
		}
		return *gencs_gentaudecay_;
	}
	int &gen_nfromtcs_()
	{
		if (not gen_nfromtcs__isLoaded) {
			if (gen_nfromtcs__branch != 0) {
				gen_nfromtcs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtcs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtcs__isLoaded = true;
		}
		return gen_nfromtcs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_motherp4()
	{
		if (not gencs_motherp4_isLoaded) {
			if (gencs_motherp4_branch != 0) {
				gencs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gencs_motherp4_branch does not exist!\n");
				exit(1);
			}
			gencs_motherp4_isLoaded = true;
		}
		return *gencs_motherp4_;
	}
	const vector<float> &gencs_mothercharge()
	{
		if (not gencs_mothercharge_isLoaded) {
			if (gencs_mothercharge_branch != 0) {
				gencs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gencs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gencs_mothercharge_isLoaded = true;
		}
		return *gencs_mothercharge_;
	}
	const vector<int> &gencs_motherid()
	{
		if (not gencs_motherid_isLoaded) {
			if (gencs_motherid_branch != 0) {
				gencs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gencs_motherid_branch does not exist!\n");
				exit(1);
			}
			gencs_motherid_isLoaded = true;
		}
		return *gencs_motherid_;
	}
	const vector<int> &gencs_motheridx()
	{
		if (not gencs_motheridx_isLoaded) {
			if (gencs_motheridx_branch != 0) {
				gencs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gencs_motheridx_branch does not exist!\n");
				exit(1);
			}
			gencs_motheridx_isLoaded = true;
		}
		return *gencs_motheridx_;
	}
	const vector<int> &gencs_motherstatus()
	{
		if (not gencs_motherstatus_isLoaded) {
			if (gencs_motherstatus_branch != 0) {
				gencs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gencs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gencs_motherstatus_isLoaded = true;
		}
		return *gencs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_gmotherp4()
	{
		if (not gencs_gmotherp4_isLoaded) {
			if (gencs_gmotherp4_branch != 0) {
				gencs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gencs_gmotherp4_isLoaded = true;
		}
		return *gencs_gmotherp4_;
	}
	const vector<int> &gencs_gmothercharge()
	{
		if (not gencs_gmothercharge_isLoaded) {
			if (gencs_gmothercharge_branch != 0) {
				gencs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			gencs_gmothercharge_isLoaded = true;
		}
		return *gencs_gmothercharge_;
	}
	const vector<int> &gencs_gmotherid()
	{
		if (not gencs_gmotherid_isLoaded) {
			if (gencs_gmotherid_branch != 0) {
				gencs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gencs_gmotherid_isLoaded = true;
		}
		return *gencs_gmotherid_;
	}
	const vector<int> &gencs_gmotheridx()
	{
		if (not gencs_gmotheridx_isLoaded) {
			if (gencs_gmotheridx_branch != 0) {
				gencs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gencs_gmotheridx_isLoaded = true;
		}
		return *gencs_gmotheridx_;
	}
	const vector<int> &gencs_gmotherstatus()
	{
		if (not gencs_gmotherstatus_isLoaded) {
			if (gencs_gmotherstatus_branch != 0) {
				gencs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gencs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gencs_gmotherstatus_isLoaded = true;
		}
		return *gencs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplemotherp4()
	{
		if (not gencs_simplemotherp4_isLoaded) {
			if (gencs_simplemotherp4_branch != 0) {
				gencs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			gencs_simplemotherp4_isLoaded = true;
		}
		return *gencs_simplemotherp4_;
	}
	const vector<int> &gencs_simplemothercharge()
	{
		if (not gencs_simplemothercharge_isLoaded) {
			if (gencs_simplemothercharge_branch != 0) {
				gencs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			gencs_simplemothercharge_isLoaded = true;
		}
		return *gencs_simplemothercharge_;
	}
	const vector<int> &gencs_simplemotherid()
	{
		if (not gencs_simplemotherid_isLoaded) {
			if (gencs_simplemotherid_branch != 0) {
				gencs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			gencs_simplemotherid_isLoaded = true;
		}
		return *gencs_simplemotherid_;
	}
	const vector<int> &gencs_simplemotheridx()
	{
		if (not gencs_simplemotheridx_isLoaded) {
			if (gencs_simplemotheridx_branch != 0) {
				gencs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			gencs_simplemotheridx_isLoaded = true;
		}
		return *gencs_simplemotheridx_;
	}
	const vector<int> &gencs_simplemotherstatus()
	{
		if (not gencs_simplemotherstatus_isLoaded) {
			if (gencs_simplemotherstatus_branch != 0) {
				gencs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			gencs_simplemotherstatus_isLoaded = true;
		}
		return *gencs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplegmotherp4()
	{
		if (not gencs_simplegmotherp4_isLoaded) {
			if (gencs_simplegmotherp4_branch != 0) {
				gencs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			gencs_simplegmotherp4_isLoaded = true;
		}
		return *gencs_simplegmotherp4_;
	}
	const vector<int> &gencs_simplegmothercharge()
	{
		if (not gencs_simplegmothercharge_isLoaded) {
			if (gencs_simplegmothercharge_branch != 0) {
				gencs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			gencs_simplegmothercharge_isLoaded = true;
		}
		return *gencs_simplegmothercharge_;
	}
	const vector<int> &gencs_simplegmotherid()
	{
		if (not gencs_simplegmotherid_isLoaded) {
			if (gencs_simplegmotherid_branch != 0) {
				gencs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			gencs_simplegmotherid_isLoaded = true;
		}
		return *gencs_simplegmotherid_;
	}
	const vector<int> &gencs_simplegmotheridx()
	{
		if (not gencs_simplegmotheridx_isLoaded) {
			if (gencs_simplegmotheridx_branch != 0) {
				gencs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			gencs_simplegmotheridx_isLoaded = true;
		}
		return *gencs_simplegmotheridx_;
	}
	const vector<int> &gencs_simplegmotherstatus()
	{
		if (not gencs_simplegmotherstatus_isLoaded) {
			if (gencs_simplegmotherstatus_branch != 0) {
				gencs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gencs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gencs_simplegmotherstatus_isLoaded = true;
		}
		return *gencs_simplegmotherstatus_;
	}
	const vector<bool> &genqs_isfromt()
	{
		if (not genqs_isfromt_isLoaded) {
			if (genqs_isfromt_branch != 0) {
				genqs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genqs_isfromt_isLoaded = true;
		}
		return *genqs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4()
	{
		if (not genqs_p4_isLoaded) {
			if (genqs_p4_branch != 0) {
				genqs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_p4_branch does not exist!\n");
				exit(1);
			}
			genqs_p4_isLoaded = true;
		}
		return *genqs_p4_;
	}
	const vector<float> &genqs_charge()
	{
		if (not genqs_charge_isLoaded) {
			if (genqs_charge_branch != 0) {
				genqs_charge_branch->GetEntry(index);
			} else { 
				printf("branch genqs_charge_branch does not exist!\n");
				exit(1);
			}
			genqs_charge_isLoaded = true;
		}
		return *genqs_charge_;
	}
	const vector<float> &genqs_iso()
	{
		if (not genqs_iso_isLoaded) {
			if (genqs_iso_branch != 0) {
				genqs_iso_branch->GetEntry(index);
			} else { 
				printf("branch genqs_iso_branch does not exist!\n");
				exit(1);
			}
			genqs_iso_isLoaded = true;
		}
		return *genqs_iso_;
	}
	const vector<float> &genqs_mass()
	{
		if (not genqs_mass_isLoaded) {
			if (genqs_mass_branch != 0) {
				genqs_mass_branch->GetEntry(index);
			} else { 
				printf("branch genqs_mass_branch does not exist!\n");
				exit(1);
			}
			genqs_mass_isLoaded = true;
		}
		return *genqs_mass_;
	}
	const vector<int> &genqs_id()
	{
		if (not genqs_id_isLoaded) {
			if (genqs_id_branch != 0) {
				genqs_id_branch->GetEntry(index);
			} else { 
				printf("branch genqs_id_branch does not exist!\n");
				exit(1);
			}
			genqs_id_isLoaded = true;
		}
		return *genqs_id_;
	}
	const vector<int> &genqs__genpsidx()
	{
		if (not genqs__genpsidx_isLoaded) {
			if (genqs__genpsidx_branch != 0) {
				genqs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genqs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genqs__genpsidx_isLoaded = true;
		}
		return *genqs__genpsidx_;
	}
	const vector<int> &genqs_status()
	{
		if (not genqs_status_isLoaded) {
			if (genqs_status_branch != 0) {
				genqs_status_branch->GetEntry(index);
			} else { 
				printf("branch genqs_status_branch does not exist!\n");
				exit(1);
			}
			genqs_status_isLoaded = true;
		}
		return *genqs_status_;
	}
	const vector<bool> &genqs_fromHardProcessBeforeFSR()
	{
		if (not genqs_fromHardProcessBeforeFSR_isLoaded) {
			if (genqs_fromHardProcessBeforeFSR_branch != 0) {
				genqs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genqs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genqs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genqs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genqs_fromHardProcessDecayed()
	{
		if (not genqs_fromHardProcessDecayed_isLoaded) {
			if (genqs_fromHardProcessDecayed_branch != 0) {
				genqs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genqs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genqs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genqs_fromHardProcessDecayed_;
	}
	const vector<bool> &genqs_fromHardProcessFinalState()
	{
		if (not genqs_fromHardProcessFinalState_isLoaded) {
			if (genqs_fromHardProcessFinalState_branch != 0) {
				genqs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genqs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genqs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genqs_fromHardProcessFinalState_;
	}
	const vector<bool> &genqs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genqs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genqs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genqs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genqs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genqs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genqs_isDirectPromptTauDecayProductFinalState()
	{
		if (not genqs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genqs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genqs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genqs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genqs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genqs_isHardProcess()
	{
		if (not genqs_isHardProcess_isLoaded) {
			if (genqs_isHardProcess_branch != 0) {
				genqs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genqs_isHardProcess_isLoaded = true;
		}
		return *genqs_isHardProcess_;
	}
	const vector<bool> &genqs_isLastCopy()
	{
		if (not genqs_isLastCopy_isLoaded) {
			if (genqs_isLastCopy_branch != 0) {
				genqs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genqs_isLastCopy_isLoaded = true;
		}
		return *genqs_isLastCopy_;
	}
	const vector<bool> &genqs_isLastCopyBeforeFSR()
	{
		if (not genqs_isLastCopyBeforeFSR_isLoaded) {
			if (genqs_isLastCopyBeforeFSR_branch != 0) {
				genqs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genqs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genqs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genqs_isMostlyLikePythia6Status3()
	{
		if (not genqs_isMostlyLikePythia6Status3_isLoaded) {
			if (genqs_isMostlyLikePythia6Status3_branch != 0) {
				genqs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genqs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genqs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genqs_isPromptDecayed()
	{
		if (not genqs_isPromptDecayed_isLoaded) {
			if (genqs_isPromptDecayed_branch != 0) {
				genqs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genqs_isPromptDecayed_isLoaded = true;
		}
		return *genqs_isPromptDecayed_;
	}
	const vector<bool> &genqs_isPromptFinalState()
	{
		if (not genqs_isPromptFinalState_isLoaded) {
			if (genqs_isPromptFinalState_branch != 0) {
				genqs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genqs_isPromptFinalState_isLoaded = true;
		}
		return *genqs_isPromptFinalState_;
	}
	const vector<vector<int> > &genqs_lepdaughter_id()
	{
		if (not genqs_lepdaughter_id_isLoaded) {
			if (genqs_lepdaughter_id_branch != 0) {
				genqs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genqs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genqs_lepdaughter_id_isLoaded = true;
		}
		return *genqs_lepdaughter_id_;
	}
	const vector<int> &genqs_gentaudecay()
	{
		if (not genqs_gentaudecay_isLoaded) {
			if (genqs_gentaudecay_branch != 0) {
				genqs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genqs_gentaudecay_isLoaded = true;
		}
		return *genqs_gentaudecay_;
	}
	int &gen_nfromtqs_()
	{
		if (not gen_nfromtqs__isLoaded) {
			if (gen_nfromtqs__branch != 0) {
				gen_nfromtqs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtqs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtqs__isLoaded = true;
		}
		return gen_nfromtqs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4()
	{
		if (not genqs_motherp4_isLoaded) {
			if (genqs_motherp4_branch != 0) {
				genqs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_motherp4_isLoaded = true;
		}
		return *genqs_motherp4_;
	}
	const vector<float> &genqs_mothercharge()
	{
		if (not genqs_mothercharge_isLoaded) {
			if (genqs_mothercharge_branch != 0) {
				genqs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genqs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genqs_mothercharge_isLoaded = true;
		}
		return *genqs_mothercharge_;
	}
	const vector<int> &genqs_motherid()
	{
		if (not genqs_motherid_isLoaded) {
			if (genqs_motherid_branch != 0) {
				genqs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherid_branch does not exist!\n");
				exit(1);
			}
			genqs_motherid_isLoaded = true;
		}
		return *genqs_motherid_;
	}
	const vector<int> &genqs_motheridx()
	{
		if (not genqs_motheridx_isLoaded) {
			if (genqs_motheridx_branch != 0) {
				genqs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_motheridx_isLoaded = true;
		}
		return *genqs_motheridx_;
	}
	const vector<int> &genqs_motherstatus()
	{
		if (not genqs_motherstatus_isLoaded) {
			if (genqs_motherstatus_branch != 0) {
				genqs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_motherstatus_isLoaded = true;
		}
		return *genqs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4()
	{
		if (not genqs_gmotherp4_isLoaded) {
			if (genqs_gmotherp4_branch != 0) {
				genqs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherp4_isLoaded = true;
		}
		return *genqs_gmotherp4_;
	}
	const vector<int> &genqs_gmothercharge()
	{
		if (not genqs_gmothercharge_isLoaded) {
			if (genqs_gmothercharge_branch != 0) {
				genqs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genqs_gmothercharge_isLoaded = true;
		}
		return *genqs_gmothercharge_;
	}
	const vector<int> &genqs_gmotherid()
	{
		if (not genqs_gmotherid_isLoaded) {
			if (genqs_gmotherid_branch != 0) {
				genqs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherid_isLoaded = true;
		}
		return *genqs_gmotherid_;
	}
	const vector<int> &genqs_gmotheridx()
	{
		if (not genqs_gmotheridx_isLoaded) {
			if (genqs_gmotheridx_branch != 0) {
				genqs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotheridx_isLoaded = true;
		}
		return *genqs_gmotheridx_;
	}
	const vector<int> &genqs_gmotherstatus()
	{
		if (not genqs_gmotherstatus_isLoaded) {
			if (genqs_gmotherstatus_branch != 0) {
				genqs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherstatus_isLoaded = true;
		}
		return *genqs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplemotherp4()
	{
		if (not genqs_simplemotherp4_isLoaded) {
			if (genqs_simplemotherp4_branch != 0) {
				genqs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_simplemotherp4_isLoaded = true;
		}
		return *genqs_simplemotherp4_;
	}
	const vector<int> &genqs_simplemothercharge()
	{
		if (not genqs_simplemothercharge_isLoaded) {
			if (genqs_simplemothercharge_branch != 0) {
				genqs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genqs_simplemothercharge_isLoaded = true;
		}
		return *genqs_simplemothercharge_;
	}
	const vector<int> &genqs_simplemotherid()
	{
		if (not genqs_simplemotherid_isLoaded) {
			if (genqs_simplemotherid_branch != 0) {
				genqs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genqs_simplemotherid_isLoaded = true;
		}
		return *genqs_simplemotherid_;
	}
	const vector<int> &genqs_simplemotheridx()
	{
		if (not genqs_simplemotheridx_isLoaded) {
			if (genqs_simplemotheridx_branch != 0) {
				genqs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_simplemotheridx_isLoaded = true;
		}
		return *genqs_simplemotheridx_;
	}
	const vector<int> &genqs_simplemotherstatus()
	{
		if (not genqs_simplemotherstatus_isLoaded) {
			if (genqs_simplemotherstatus_branch != 0) {
				genqs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_simplemotherstatus_isLoaded = true;
		}
		return *genqs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplegmotherp4()
	{
		if (not genqs_simplegmotherp4_isLoaded) {
			if (genqs_simplegmotherp4_branch != 0) {
				genqs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_simplegmotherp4_isLoaded = true;
		}
		return *genqs_simplegmotherp4_;
	}
	const vector<int> &genqs_simplegmothercharge()
	{
		if (not genqs_simplegmothercharge_isLoaded) {
			if (genqs_simplegmothercharge_branch != 0) {
				genqs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genqs_simplegmothercharge_isLoaded = true;
		}
		return *genqs_simplegmothercharge_;
	}
	const vector<int> &genqs_simplegmotherid()
	{
		if (not genqs_simplegmotherid_isLoaded) {
			if (genqs_simplegmotherid_branch != 0) {
				genqs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genqs_simplegmotherid_isLoaded = true;
		}
		return *genqs_simplegmotherid_;
	}
	const vector<int> &genqs_simplegmotheridx()
	{
		if (not genqs_simplegmotheridx_isLoaded) {
			if (genqs_simplegmotheridx_branch != 0) {
				genqs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_simplegmotheridx_isLoaded = true;
		}
		return *genqs_simplegmotheridx_;
	}
	const vector<int> &genqs_simplegmotherstatus()
	{
		if (not genqs_simplegmotherstatus_isLoaded) {
			if (genqs_simplegmotherstatus_branch != 0) {
				genqs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_simplegmotherstatus_isLoaded = true;
		}
		return *genqs_simplegmotherstatus_;
	}
	const vector<bool> &genglus_isfromt()
	{
		if (not genglus_isfromt_isLoaded) {
			if (genglus_isfromt_branch != 0) {
				genglus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isfromt_branch does not exist!\n");
				exit(1);
			}
			genglus_isfromt_isLoaded = true;
		}
		return *genglus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_p4()
	{
		if (not genglus_p4_isLoaded) {
			if (genglus_p4_branch != 0) {
				genglus_p4_branch->GetEntry(index);
			} else { 
				printf("branch genglus_p4_branch does not exist!\n");
				exit(1);
			}
			genglus_p4_isLoaded = true;
		}
		return *genglus_p4_;
	}
	const vector<float> &genglus_charge()
	{
		if (not genglus_charge_isLoaded) {
			if (genglus_charge_branch != 0) {
				genglus_charge_branch->GetEntry(index);
			} else { 
				printf("branch genglus_charge_branch does not exist!\n");
				exit(1);
			}
			genglus_charge_isLoaded = true;
		}
		return *genglus_charge_;
	}
	const vector<float> &genglus_iso()
	{
		if (not genglus_iso_isLoaded) {
			if (genglus_iso_branch != 0) {
				genglus_iso_branch->GetEntry(index);
			} else { 
				printf("branch genglus_iso_branch does not exist!\n");
				exit(1);
			}
			genglus_iso_isLoaded = true;
		}
		return *genglus_iso_;
	}
	const vector<float> &genglus_mass()
	{
		if (not genglus_mass_isLoaded) {
			if (genglus_mass_branch != 0) {
				genglus_mass_branch->GetEntry(index);
			} else { 
				printf("branch genglus_mass_branch does not exist!\n");
				exit(1);
			}
			genglus_mass_isLoaded = true;
		}
		return *genglus_mass_;
	}
	const vector<int> &genglus_id()
	{
		if (not genglus_id_isLoaded) {
			if (genglus_id_branch != 0) {
				genglus_id_branch->GetEntry(index);
			} else { 
				printf("branch genglus_id_branch does not exist!\n");
				exit(1);
			}
			genglus_id_isLoaded = true;
		}
		return *genglus_id_;
	}
	const vector<int> &genglus__genpsidx()
	{
		if (not genglus__genpsidx_isLoaded) {
			if (genglus__genpsidx_branch != 0) {
				genglus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genglus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genglus__genpsidx_isLoaded = true;
		}
		return *genglus__genpsidx_;
	}
	const vector<int> &genglus_status()
	{
		if (not genglus_status_isLoaded) {
			if (genglus_status_branch != 0) {
				genglus_status_branch->GetEntry(index);
			} else { 
				printf("branch genglus_status_branch does not exist!\n");
				exit(1);
			}
			genglus_status_isLoaded = true;
		}
		return *genglus_status_;
	}
	const vector<bool> &genglus_fromHardProcessBeforeFSR()
	{
		if (not genglus_fromHardProcessBeforeFSR_isLoaded) {
			if (genglus_fromHardProcessBeforeFSR_branch != 0) {
				genglus_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genglus_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genglus_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genglus_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genglus_fromHardProcessDecayed()
	{
		if (not genglus_fromHardProcessDecayed_isLoaded) {
			if (genglus_fromHardProcessDecayed_branch != 0) {
				genglus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genglus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genglus_fromHardProcessDecayed_isLoaded = true;
		}
		return *genglus_fromHardProcessDecayed_;
	}
	const vector<bool> &genglus_fromHardProcessFinalState()
	{
		if (not genglus_fromHardProcessFinalState_isLoaded) {
			if (genglus_fromHardProcessFinalState_branch != 0) {
				genglus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genglus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genglus_fromHardProcessFinalState_isLoaded = true;
		}
		return *genglus_fromHardProcessFinalState_;
	}
	const vector<bool> &genglus_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genglus_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genglus_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genglus_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genglus_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genglus_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genglus_isDirectPromptTauDecayProductFinalState()
	{
		if (not genglus_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genglus_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genglus_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genglus_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genglus_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genglus_isHardProcess()
	{
		if (not genglus_isHardProcess_isLoaded) {
			if (genglus_isHardProcess_branch != 0) {
				genglus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genglus_isHardProcess_isLoaded = true;
		}
		return *genglus_isHardProcess_;
	}
	const vector<bool> &genglus_isLastCopy()
	{
		if (not genglus_isLastCopy_isLoaded) {
			if (genglus_isLastCopy_branch != 0) {
				genglus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genglus_isLastCopy_isLoaded = true;
		}
		return *genglus_isLastCopy_;
	}
	const vector<bool> &genglus_isLastCopyBeforeFSR()
	{
		if (not genglus_isLastCopyBeforeFSR_isLoaded) {
			if (genglus_isLastCopyBeforeFSR_branch != 0) {
				genglus_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genglus_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genglus_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genglus_isMostlyLikePythia6Status3()
	{
		if (not genglus_isMostlyLikePythia6Status3_isLoaded) {
			if (genglus_isMostlyLikePythia6Status3_branch != 0) {
				genglus_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genglus_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genglus_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genglus_isPromptDecayed()
	{
		if (not genglus_isPromptDecayed_isLoaded) {
			if (genglus_isPromptDecayed_branch != 0) {
				genglus_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genglus_isPromptDecayed_isLoaded = true;
		}
		return *genglus_isPromptDecayed_;
	}
	const vector<bool> &genglus_isPromptFinalState()
	{
		if (not genglus_isPromptFinalState_isLoaded) {
			if (genglus_isPromptFinalState_branch != 0) {
				genglus_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genglus_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genglus_isPromptFinalState_isLoaded = true;
		}
		return *genglus_isPromptFinalState_;
	}
	const vector<vector<int> > &genglus_lepdaughter_id()
	{
		if (not genglus_lepdaughter_id_isLoaded) {
			if (genglus_lepdaughter_id_branch != 0) {
				genglus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genglus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genglus_lepdaughter_id_isLoaded = true;
		}
		return *genglus_lepdaughter_id_;
	}
	const vector<int> &genglus_gentaudecay()
	{
		if (not genglus_gentaudecay_isLoaded) {
			if (genglus_gentaudecay_branch != 0) {
				genglus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genglus_gentaudecay_isLoaded = true;
		}
		return *genglus_gentaudecay_;
	}
	int &gen_nfromtglus_()
	{
		if (not gen_nfromtglus__isLoaded) {
			if (gen_nfromtglus__branch != 0) {
				gen_nfromtglus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtglus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtglus__isLoaded = true;
		}
		return gen_nfromtglus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_motherp4()
	{
		if (not genglus_motherp4_isLoaded) {
			if (genglus_motherp4_branch != 0) {
				genglus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genglus_motherp4_branch does not exist!\n");
				exit(1);
			}
			genglus_motherp4_isLoaded = true;
		}
		return *genglus_motherp4_;
	}
	const vector<float> &genglus_mothercharge()
	{
		if (not genglus_mothercharge_isLoaded) {
			if (genglus_mothercharge_branch != 0) {
				genglus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genglus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genglus_mothercharge_isLoaded = true;
		}
		return *genglus_mothercharge_;
	}
	const vector<int> &genglus_motherid()
	{
		if (not genglus_motherid_isLoaded) {
			if (genglus_motherid_branch != 0) {
				genglus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genglus_motherid_branch does not exist!\n");
				exit(1);
			}
			genglus_motherid_isLoaded = true;
		}
		return *genglus_motherid_;
	}
	const vector<int> &genglus_motheridx()
	{
		if (not genglus_motheridx_isLoaded) {
			if (genglus_motheridx_branch != 0) {
				genglus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genglus_motheridx_branch does not exist!\n");
				exit(1);
			}
			genglus_motheridx_isLoaded = true;
		}
		return *genglus_motheridx_;
	}
	const vector<int> &genglus_motherstatus()
	{
		if (not genglus_motherstatus_isLoaded) {
			if (genglus_motherstatus_branch != 0) {
				genglus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genglus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genglus_motherstatus_isLoaded = true;
		}
		return *genglus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_gmotherp4()
	{
		if (not genglus_gmotherp4_isLoaded) {
			if (genglus_gmotherp4_branch != 0) {
				genglus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genglus_gmotherp4_isLoaded = true;
		}
		return *genglus_gmotherp4_;
	}
	const vector<int> &genglus_gmothercharge()
	{
		if (not genglus_gmothercharge_isLoaded) {
			if (genglus_gmothercharge_branch != 0) {
				genglus_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genglus_gmothercharge_isLoaded = true;
		}
		return *genglus_gmothercharge_;
	}
	const vector<int> &genglus_gmotherid()
	{
		if (not genglus_gmotherid_isLoaded) {
			if (genglus_gmotherid_branch != 0) {
				genglus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genglus_gmotherid_isLoaded = true;
		}
		return *genglus_gmotherid_;
	}
	const vector<int> &genglus_gmotheridx()
	{
		if (not genglus_gmotheridx_isLoaded) {
			if (genglus_gmotheridx_branch != 0) {
				genglus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genglus_gmotheridx_isLoaded = true;
		}
		return *genglus_gmotheridx_;
	}
	const vector<int> &genglus_gmotherstatus()
	{
		if (not genglus_gmotherstatus_isLoaded) {
			if (genglus_gmotherstatus_branch != 0) {
				genglus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genglus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genglus_gmotherstatus_isLoaded = true;
		}
		return *genglus_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplemotherp4()
	{
		if (not genglus_simplemotherp4_isLoaded) {
			if (genglus_simplemotherp4_branch != 0) {
				genglus_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genglus_simplemotherp4_isLoaded = true;
		}
		return *genglus_simplemotherp4_;
	}
	const vector<int> &genglus_simplemothercharge()
	{
		if (not genglus_simplemothercharge_isLoaded) {
			if (genglus_simplemothercharge_branch != 0) {
				genglus_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genglus_simplemothercharge_isLoaded = true;
		}
		return *genglus_simplemothercharge_;
	}
	const vector<int> &genglus_simplemotherid()
	{
		if (not genglus_simplemotherid_isLoaded) {
			if (genglus_simplemotherid_branch != 0) {
				genglus_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genglus_simplemotherid_isLoaded = true;
		}
		return *genglus_simplemotherid_;
	}
	const vector<int> &genglus_simplemotheridx()
	{
		if (not genglus_simplemotheridx_isLoaded) {
			if (genglus_simplemotheridx_branch != 0) {
				genglus_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genglus_simplemotheridx_isLoaded = true;
		}
		return *genglus_simplemotheridx_;
	}
	const vector<int> &genglus_simplemotherstatus()
	{
		if (not genglus_simplemotherstatus_isLoaded) {
			if (genglus_simplemotherstatus_branch != 0) {
				genglus_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genglus_simplemotherstatus_isLoaded = true;
		}
		return *genglus_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplegmotherp4()
	{
		if (not genglus_simplegmotherp4_isLoaded) {
			if (genglus_simplegmotherp4_branch != 0) {
				genglus_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genglus_simplegmotherp4_isLoaded = true;
		}
		return *genglus_simplegmotherp4_;
	}
	const vector<int> &genglus_simplegmothercharge()
	{
		if (not genglus_simplegmothercharge_isLoaded) {
			if (genglus_simplegmothercharge_branch != 0) {
				genglus_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genglus_simplegmothercharge_isLoaded = true;
		}
		return *genglus_simplegmothercharge_;
	}
	const vector<int> &genglus_simplegmotherid()
	{
		if (not genglus_simplegmotherid_isLoaded) {
			if (genglus_simplegmotherid_branch != 0) {
				genglus_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genglus_simplegmotherid_isLoaded = true;
		}
		return *genglus_simplegmotherid_;
	}
	const vector<int> &genglus_simplegmotheridx()
	{
		if (not genglus_simplegmotheridx_isLoaded) {
			if (genglus_simplegmotheridx_branch != 0) {
				genglus_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genglus_simplegmotheridx_isLoaded = true;
		}
		return *genglus_simplegmotheridx_;
	}
	const vector<int> &genglus_simplegmotherstatus()
	{
		if (not genglus_simplegmotherstatus_isLoaded) {
			if (genglus_simplegmotherstatus_branch != 0) {
				genglus_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genglus_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genglus_simplegmotherstatus_isLoaded = true;
		}
		return *genglus_simplegmotherstatus_;
	}
	const vector<bool> &genws_isfromt()
	{
		if (not genws_isfromt_isLoaded) {
			if (genws_isfromt_branch != 0) {
				genws_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genws_isfromt_branch does not exist!\n");
				exit(1);
			}
			genws_isfromt_isLoaded = true;
		}
		return *genws_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_p4()
	{
		if (not genws_p4_isLoaded) {
			if (genws_p4_branch != 0) {
				genws_p4_branch->GetEntry(index);
			} else { 
				printf("branch genws_p4_branch does not exist!\n");
				exit(1);
			}
			genws_p4_isLoaded = true;
		}
		return *genws_p4_;
	}
	const vector<float> &genws_charge()
	{
		if (not genws_charge_isLoaded) {
			if (genws_charge_branch != 0) {
				genws_charge_branch->GetEntry(index);
			} else { 
				printf("branch genws_charge_branch does not exist!\n");
				exit(1);
			}
			genws_charge_isLoaded = true;
		}
		return *genws_charge_;
	}
	const vector<float> &genws_iso()
	{
		if (not genws_iso_isLoaded) {
			if (genws_iso_branch != 0) {
				genws_iso_branch->GetEntry(index);
			} else { 
				printf("branch genws_iso_branch does not exist!\n");
				exit(1);
			}
			genws_iso_isLoaded = true;
		}
		return *genws_iso_;
	}
	const vector<float> &genws_mass()
	{
		if (not genws_mass_isLoaded) {
			if (genws_mass_branch != 0) {
				genws_mass_branch->GetEntry(index);
			} else { 
				printf("branch genws_mass_branch does not exist!\n");
				exit(1);
			}
			genws_mass_isLoaded = true;
		}
		return *genws_mass_;
	}
	const vector<int> &genws_id()
	{
		if (not genws_id_isLoaded) {
			if (genws_id_branch != 0) {
				genws_id_branch->GetEntry(index);
			} else { 
				printf("branch genws_id_branch does not exist!\n");
				exit(1);
			}
			genws_id_isLoaded = true;
		}
		return *genws_id_;
	}
	const vector<int> &genws__genpsidx()
	{
		if (not genws__genpsidx_isLoaded) {
			if (genws__genpsidx_branch != 0) {
				genws__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genws__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genws__genpsidx_isLoaded = true;
		}
		return *genws__genpsidx_;
	}
	const vector<int> &genws_status()
	{
		if (not genws_status_isLoaded) {
			if (genws_status_branch != 0) {
				genws_status_branch->GetEntry(index);
			} else { 
				printf("branch genws_status_branch does not exist!\n");
				exit(1);
			}
			genws_status_isLoaded = true;
		}
		return *genws_status_;
	}
	const vector<bool> &genws_fromHardProcessBeforeFSR()
	{
		if (not genws_fromHardProcessBeforeFSR_isLoaded) {
			if (genws_fromHardProcessBeforeFSR_branch != 0) {
				genws_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genws_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genws_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genws_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genws_fromHardProcessDecayed()
	{
		if (not genws_fromHardProcessDecayed_isLoaded) {
			if (genws_fromHardProcessDecayed_branch != 0) {
				genws_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genws_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genws_fromHardProcessDecayed_isLoaded = true;
		}
		return *genws_fromHardProcessDecayed_;
	}
	const vector<bool> &genws_fromHardProcessFinalState()
	{
		if (not genws_fromHardProcessFinalState_isLoaded) {
			if (genws_fromHardProcessFinalState_branch != 0) {
				genws_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genws_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genws_fromHardProcessFinalState_isLoaded = true;
		}
		return *genws_fromHardProcessFinalState_;
	}
	const vector<bool> &genws_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genws_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genws_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genws_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genws_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genws_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genws_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genws_isDirectPromptTauDecayProductFinalState()
	{
		if (not genws_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genws_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genws_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genws_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genws_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genws_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genws_isHardProcess()
	{
		if (not genws_isHardProcess_isLoaded) {
			if (genws_isHardProcess_branch != 0) {
				genws_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genws_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genws_isHardProcess_isLoaded = true;
		}
		return *genws_isHardProcess_;
	}
	const vector<bool> &genws_isLastCopy()
	{
		if (not genws_isLastCopy_isLoaded) {
			if (genws_isLastCopy_branch != 0) {
				genws_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genws_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genws_isLastCopy_isLoaded = true;
		}
		return *genws_isLastCopy_;
	}
	const vector<bool> &genws_isLastCopyBeforeFSR()
	{
		if (not genws_isLastCopyBeforeFSR_isLoaded) {
			if (genws_isLastCopyBeforeFSR_branch != 0) {
				genws_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genws_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genws_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genws_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genws_isMostlyLikePythia6Status3()
	{
		if (not genws_isMostlyLikePythia6Status3_isLoaded) {
			if (genws_isMostlyLikePythia6Status3_branch != 0) {
				genws_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genws_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genws_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genws_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genws_isPromptDecayed()
	{
		if (not genws_isPromptDecayed_isLoaded) {
			if (genws_isPromptDecayed_branch != 0) {
				genws_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genws_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genws_isPromptDecayed_isLoaded = true;
		}
		return *genws_isPromptDecayed_;
	}
	const vector<bool> &genws_isPromptFinalState()
	{
		if (not genws_isPromptFinalState_isLoaded) {
			if (genws_isPromptFinalState_branch != 0) {
				genws_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genws_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genws_isPromptFinalState_isLoaded = true;
		}
		return *genws_isPromptFinalState_;
	}
	const vector<vector<int> > &genws_lepdaughter_id()
	{
		if (not genws_lepdaughter_id_isLoaded) {
			if (genws_lepdaughter_id_branch != 0) {
				genws_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genws_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genws_lepdaughter_id_isLoaded = true;
		}
		return *genws_lepdaughter_id_;
	}
	const vector<int> &genws_gentaudecay()
	{
		if (not genws_gentaudecay_isLoaded) {
			if (genws_gentaudecay_branch != 0) {
				genws_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genws_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genws_gentaudecay_isLoaded = true;
		}
		return *genws_gentaudecay_;
	}
	int &gen_nfromtws_()
	{
		if (not gen_nfromtws__isLoaded) {
			if (gen_nfromtws__branch != 0) {
				gen_nfromtws__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtws__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtws__isLoaded = true;
		}
		return gen_nfromtws__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_motherp4()
	{
		if (not genws_motherp4_isLoaded) {
			if (genws_motherp4_branch != 0) {
				genws_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genws_motherp4_branch does not exist!\n");
				exit(1);
			}
			genws_motherp4_isLoaded = true;
		}
		return *genws_motherp4_;
	}
	const vector<float> &genws_mothercharge()
	{
		if (not genws_mothercharge_isLoaded) {
			if (genws_mothercharge_branch != 0) {
				genws_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genws_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genws_mothercharge_isLoaded = true;
		}
		return *genws_mothercharge_;
	}
	const vector<int> &genws_motherid()
	{
		if (not genws_motherid_isLoaded) {
			if (genws_motherid_branch != 0) {
				genws_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genws_motherid_branch does not exist!\n");
				exit(1);
			}
			genws_motherid_isLoaded = true;
		}
		return *genws_motherid_;
	}
	const vector<int> &genws_motheridx()
	{
		if (not genws_motheridx_isLoaded) {
			if (genws_motheridx_branch != 0) {
				genws_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genws_motheridx_branch does not exist!\n");
				exit(1);
			}
			genws_motheridx_isLoaded = true;
		}
		return *genws_motheridx_;
	}
	const vector<int> &genws_motherstatus()
	{
		if (not genws_motherstatus_isLoaded) {
			if (genws_motherstatus_branch != 0) {
				genws_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genws_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genws_motherstatus_isLoaded = true;
		}
		return *genws_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_gmotherp4()
	{
		if (not genws_gmotherp4_isLoaded) {
			if (genws_gmotherp4_branch != 0) {
				genws_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genws_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genws_gmotherp4_isLoaded = true;
		}
		return *genws_gmotherp4_;
	}
	const vector<int> &genws_gmothercharge()
	{
		if (not genws_gmothercharge_isLoaded) {
			if (genws_gmothercharge_branch != 0) {
				genws_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genws_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genws_gmothercharge_isLoaded = true;
		}
		return *genws_gmothercharge_;
	}
	const vector<int> &genws_gmotherid()
	{
		if (not genws_gmotherid_isLoaded) {
			if (genws_gmotherid_branch != 0) {
				genws_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genws_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genws_gmotherid_isLoaded = true;
		}
		return *genws_gmotherid_;
	}
	const vector<int> &genws_gmotheridx()
	{
		if (not genws_gmotheridx_isLoaded) {
			if (genws_gmotheridx_branch != 0) {
				genws_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genws_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genws_gmotheridx_isLoaded = true;
		}
		return *genws_gmotheridx_;
	}
	const vector<int> &genws_gmotherstatus()
	{
		if (not genws_gmotherstatus_isLoaded) {
			if (genws_gmotherstatus_branch != 0) {
				genws_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genws_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genws_gmotherstatus_isLoaded = true;
		}
		return *genws_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplemotherp4()
	{
		if (not genws_simplemotherp4_isLoaded) {
			if (genws_simplemotherp4_branch != 0) {
				genws_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genws_simplemotherp4_isLoaded = true;
		}
		return *genws_simplemotherp4_;
	}
	const vector<int> &genws_simplemothercharge()
	{
		if (not genws_simplemothercharge_isLoaded) {
			if (genws_simplemothercharge_branch != 0) {
				genws_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genws_simplemothercharge_isLoaded = true;
		}
		return *genws_simplemothercharge_;
	}
	const vector<int> &genws_simplemotherid()
	{
		if (not genws_simplemotherid_isLoaded) {
			if (genws_simplemotherid_branch != 0) {
				genws_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genws_simplemotherid_isLoaded = true;
		}
		return *genws_simplemotherid_;
	}
	const vector<int> &genws_simplemotheridx()
	{
		if (not genws_simplemotheridx_isLoaded) {
			if (genws_simplemotheridx_branch != 0) {
				genws_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genws_simplemotheridx_isLoaded = true;
		}
		return *genws_simplemotheridx_;
	}
	const vector<int> &genws_simplemotherstatus()
	{
		if (not genws_simplemotherstatus_isLoaded) {
			if (genws_simplemotherstatus_branch != 0) {
				genws_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genws_simplemotherstatus_isLoaded = true;
		}
		return *genws_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplegmotherp4()
	{
		if (not genws_simplegmotherp4_isLoaded) {
			if (genws_simplegmotherp4_branch != 0) {
				genws_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genws_simplegmotherp4_isLoaded = true;
		}
		return *genws_simplegmotherp4_;
	}
	const vector<int> &genws_simplegmothercharge()
	{
		if (not genws_simplegmothercharge_isLoaded) {
			if (genws_simplegmothercharge_branch != 0) {
				genws_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genws_simplegmothercharge_isLoaded = true;
		}
		return *genws_simplegmothercharge_;
	}
	const vector<int> &genws_simplegmotherid()
	{
		if (not genws_simplegmotherid_isLoaded) {
			if (genws_simplegmotherid_branch != 0) {
				genws_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genws_simplegmotherid_isLoaded = true;
		}
		return *genws_simplegmotherid_;
	}
	const vector<int> &genws_simplegmotheridx()
	{
		if (not genws_simplegmotheridx_isLoaded) {
			if (genws_simplegmotheridx_branch != 0) {
				genws_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genws_simplegmotheridx_isLoaded = true;
		}
		return *genws_simplegmotheridx_;
	}
	const vector<int> &genws_simplegmotherstatus()
	{
		if (not genws_simplegmotherstatus_isLoaded) {
			if (genws_simplegmotherstatus_branch != 0) {
				genws_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genws_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genws_simplegmotherstatus_isLoaded = true;
		}
		return *genws_simplegmotherstatus_;
	}
	const vector<bool> &genzs_isfromt()
	{
		if (not genzs_isfromt_isLoaded) {
			if (genzs_isfromt_branch != 0) {
				genzs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genzs_isfromt_isLoaded = true;
		}
		return *genzs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_p4()
	{
		if (not genzs_p4_isLoaded) {
			if (genzs_p4_branch != 0) {
				genzs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genzs_p4_branch does not exist!\n");
				exit(1);
			}
			genzs_p4_isLoaded = true;
		}
		return *genzs_p4_;
	}
	const vector<float> &genzs_charge()
	{
		if (not genzs_charge_isLoaded) {
			if (genzs_charge_branch != 0) {
				genzs_charge_branch->GetEntry(index);
			} else { 
				printf("branch genzs_charge_branch does not exist!\n");
				exit(1);
			}
			genzs_charge_isLoaded = true;
		}
		return *genzs_charge_;
	}
	const vector<float> &genzs_iso()
	{
		if (not genzs_iso_isLoaded) {
			if (genzs_iso_branch != 0) {
				genzs_iso_branch->GetEntry(index);
			} else { 
				printf("branch genzs_iso_branch does not exist!\n");
				exit(1);
			}
			genzs_iso_isLoaded = true;
		}
		return *genzs_iso_;
	}
	const vector<float> &genzs_mass()
	{
		if (not genzs_mass_isLoaded) {
			if (genzs_mass_branch != 0) {
				genzs_mass_branch->GetEntry(index);
			} else { 
				printf("branch genzs_mass_branch does not exist!\n");
				exit(1);
			}
			genzs_mass_isLoaded = true;
		}
		return *genzs_mass_;
	}
	const vector<int> &genzs_id()
	{
		if (not genzs_id_isLoaded) {
			if (genzs_id_branch != 0) {
				genzs_id_branch->GetEntry(index);
			} else { 
				printf("branch genzs_id_branch does not exist!\n");
				exit(1);
			}
			genzs_id_isLoaded = true;
		}
		return *genzs_id_;
	}
	const vector<int> &genzs__genpsidx()
	{
		if (not genzs__genpsidx_isLoaded) {
			if (genzs__genpsidx_branch != 0) {
				genzs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genzs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genzs__genpsidx_isLoaded = true;
		}
		return *genzs__genpsidx_;
	}
	const vector<int> &genzs_status()
	{
		if (not genzs_status_isLoaded) {
			if (genzs_status_branch != 0) {
				genzs_status_branch->GetEntry(index);
			} else { 
				printf("branch genzs_status_branch does not exist!\n");
				exit(1);
			}
			genzs_status_isLoaded = true;
		}
		return *genzs_status_;
	}
	const vector<bool> &genzs_fromHardProcessBeforeFSR()
	{
		if (not genzs_fromHardProcessBeforeFSR_isLoaded) {
			if (genzs_fromHardProcessBeforeFSR_branch != 0) {
				genzs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genzs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genzs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genzs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genzs_fromHardProcessDecayed()
	{
		if (not genzs_fromHardProcessDecayed_isLoaded) {
			if (genzs_fromHardProcessDecayed_branch != 0) {
				genzs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genzs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genzs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genzs_fromHardProcessDecayed_;
	}
	const vector<bool> &genzs_fromHardProcessFinalState()
	{
		if (not genzs_fromHardProcessFinalState_isLoaded) {
			if (genzs_fromHardProcessFinalState_branch != 0) {
				genzs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genzs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genzs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genzs_fromHardProcessFinalState_;
	}
	const vector<bool> &genzs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genzs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genzs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genzs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genzs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genzs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genzs_isDirectPromptTauDecayProductFinalState()
	{
		if (not genzs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genzs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genzs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genzs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genzs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genzs_isHardProcess()
	{
		if (not genzs_isHardProcess_isLoaded) {
			if (genzs_isHardProcess_branch != 0) {
				genzs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genzs_isHardProcess_isLoaded = true;
		}
		return *genzs_isHardProcess_;
	}
	const vector<bool> &genzs_isLastCopy()
	{
		if (not genzs_isLastCopy_isLoaded) {
			if (genzs_isLastCopy_branch != 0) {
				genzs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genzs_isLastCopy_isLoaded = true;
		}
		return *genzs_isLastCopy_;
	}
	const vector<bool> &genzs_isLastCopyBeforeFSR()
	{
		if (not genzs_isLastCopyBeforeFSR_isLoaded) {
			if (genzs_isLastCopyBeforeFSR_branch != 0) {
				genzs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genzs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genzs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genzs_isMostlyLikePythia6Status3()
	{
		if (not genzs_isMostlyLikePythia6Status3_isLoaded) {
			if (genzs_isMostlyLikePythia6Status3_branch != 0) {
				genzs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genzs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genzs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genzs_isPromptDecayed()
	{
		if (not genzs_isPromptDecayed_isLoaded) {
			if (genzs_isPromptDecayed_branch != 0) {
				genzs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genzs_isPromptDecayed_isLoaded = true;
		}
		return *genzs_isPromptDecayed_;
	}
	const vector<bool> &genzs_isPromptFinalState()
	{
		if (not genzs_isPromptFinalState_isLoaded) {
			if (genzs_isPromptFinalState_branch != 0) {
				genzs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genzs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genzs_isPromptFinalState_isLoaded = true;
		}
		return *genzs_isPromptFinalState_;
	}
	const vector<vector<int> > &genzs_lepdaughter_id()
	{
		if (not genzs_lepdaughter_id_isLoaded) {
			if (genzs_lepdaughter_id_branch != 0) {
				genzs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genzs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genzs_lepdaughter_id_isLoaded = true;
		}
		return *genzs_lepdaughter_id_;
	}
	const vector<int> &genzs_gentaudecay()
	{
		if (not genzs_gentaudecay_isLoaded) {
			if (genzs_gentaudecay_branch != 0) {
				genzs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genzs_gentaudecay_isLoaded = true;
		}
		return *genzs_gentaudecay_;
	}
	int &gen_nfromtzs_()
	{
		if (not gen_nfromtzs__isLoaded) {
			if (gen_nfromtzs__branch != 0) {
				gen_nfromtzs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtzs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtzs__isLoaded = true;
		}
		return gen_nfromtzs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_motherp4()
	{
		if (not genzs_motherp4_isLoaded) {
			if (genzs_motherp4_branch != 0) {
				genzs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genzs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genzs_motherp4_isLoaded = true;
		}
		return *genzs_motherp4_;
	}
	const vector<float> &genzs_mothercharge()
	{
		if (not genzs_mothercharge_isLoaded) {
			if (genzs_mothercharge_branch != 0) {
				genzs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genzs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genzs_mothercharge_isLoaded = true;
		}
		return *genzs_mothercharge_;
	}
	const vector<int> &genzs_motherid()
	{
		if (not genzs_motherid_isLoaded) {
			if (genzs_motherid_branch != 0) {
				genzs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genzs_motherid_branch does not exist!\n");
				exit(1);
			}
			genzs_motherid_isLoaded = true;
		}
		return *genzs_motherid_;
	}
	const vector<int> &genzs_motheridx()
	{
		if (not genzs_motheridx_isLoaded) {
			if (genzs_motheridx_branch != 0) {
				genzs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genzs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genzs_motheridx_isLoaded = true;
		}
		return *genzs_motheridx_;
	}
	const vector<int> &genzs_motherstatus()
	{
		if (not genzs_motherstatus_isLoaded) {
			if (genzs_motherstatus_branch != 0) {
				genzs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genzs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genzs_motherstatus_isLoaded = true;
		}
		return *genzs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_gmotherp4()
	{
		if (not genzs_gmotherp4_isLoaded) {
			if (genzs_gmotherp4_branch != 0) {
				genzs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genzs_gmotherp4_isLoaded = true;
		}
		return *genzs_gmotherp4_;
	}
	const vector<int> &genzs_gmothercharge()
	{
		if (not genzs_gmothercharge_isLoaded) {
			if (genzs_gmothercharge_branch != 0) {
				genzs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genzs_gmothercharge_isLoaded = true;
		}
		return *genzs_gmothercharge_;
	}
	const vector<int> &genzs_gmotherid()
	{
		if (not genzs_gmotherid_isLoaded) {
			if (genzs_gmotherid_branch != 0) {
				genzs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genzs_gmotherid_isLoaded = true;
		}
		return *genzs_gmotherid_;
	}
	const vector<int> &genzs_gmotheridx()
	{
		if (not genzs_gmotheridx_isLoaded) {
			if (genzs_gmotheridx_branch != 0) {
				genzs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genzs_gmotheridx_isLoaded = true;
		}
		return *genzs_gmotheridx_;
	}
	const vector<int> &genzs_gmotherstatus()
	{
		if (not genzs_gmotherstatus_isLoaded) {
			if (genzs_gmotherstatus_branch != 0) {
				genzs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genzs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genzs_gmotherstatus_isLoaded = true;
		}
		return *genzs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplemotherp4()
	{
		if (not genzs_simplemotherp4_isLoaded) {
			if (genzs_simplemotherp4_branch != 0) {
				genzs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genzs_simplemotherp4_isLoaded = true;
		}
		return *genzs_simplemotherp4_;
	}
	const vector<int> &genzs_simplemothercharge()
	{
		if (not genzs_simplemothercharge_isLoaded) {
			if (genzs_simplemothercharge_branch != 0) {
				genzs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genzs_simplemothercharge_isLoaded = true;
		}
		return *genzs_simplemothercharge_;
	}
	const vector<int> &genzs_simplemotherid()
	{
		if (not genzs_simplemotherid_isLoaded) {
			if (genzs_simplemotherid_branch != 0) {
				genzs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genzs_simplemotherid_isLoaded = true;
		}
		return *genzs_simplemotherid_;
	}
	const vector<int> &genzs_simplemotheridx()
	{
		if (not genzs_simplemotheridx_isLoaded) {
			if (genzs_simplemotheridx_branch != 0) {
				genzs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genzs_simplemotheridx_isLoaded = true;
		}
		return *genzs_simplemotheridx_;
	}
	const vector<int> &genzs_simplemotherstatus()
	{
		if (not genzs_simplemotherstatus_isLoaded) {
			if (genzs_simplemotherstatus_branch != 0) {
				genzs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genzs_simplemotherstatus_isLoaded = true;
		}
		return *genzs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplegmotherp4()
	{
		if (not genzs_simplegmotherp4_isLoaded) {
			if (genzs_simplegmotherp4_branch != 0) {
				genzs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genzs_simplegmotherp4_isLoaded = true;
		}
		return *genzs_simplegmotherp4_;
	}
	const vector<int> &genzs_simplegmothercharge()
	{
		if (not genzs_simplegmothercharge_isLoaded) {
			if (genzs_simplegmothercharge_branch != 0) {
				genzs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genzs_simplegmothercharge_isLoaded = true;
		}
		return *genzs_simplegmothercharge_;
	}
	const vector<int> &genzs_simplegmotherid()
	{
		if (not genzs_simplegmotherid_isLoaded) {
			if (genzs_simplegmotherid_branch != 0) {
				genzs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genzs_simplegmotherid_isLoaded = true;
		}
		return *genzs_simplegmotherid_;
	}
	const vector<int> &genzs_simplegmotheridx()
	{
		if (not genzs_simplegmotheridx_isLoaded) {
			if (genzs_simplegmotheridx_branch != 0) {
				genzs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genzs_simplegmotheridx_isLoaded = true;
		}
		return *genzs_simplegmotheridx_;
	}
	const vector<int> &genzs_simplegmotherstatus()
	{
		if (not genzs_simplegmotherstatus_isLoaded) {
			if (genzs_simplegmotherstatus_branch != 0) {
				genzs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genzs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genzs_simplegmotherstatus_isLoaded = true;
		}
		return *genzs_simplegmotherstatus_;
	}
	const vector<bool> &genphs_isfromt()
	{
		if (not genphs_isfromt_isLoaded) {
			if (genphs_isfromt_branch != 0) {
				genphs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genphs_isfromt_isLoaded = true;
		}
		return *genphs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_p4()
	{
		if (not genphs_p4_isLoaded) {
			if (genphs_p4_branch != 0) {
				genphs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genphs_p4_branch does not exist!\n");
				exit(1);
			}
			genphs_p4_isLoaded = true;
		}
		return *genphs_p4_;
	}
	const vector<float> &genphs_charge()
	{
		if (not genphs_charge_isLoaded) {
			if (genphs_charge_branch != 0) {
				genphs_charge_branch->GetEntry(index);
			} else { 
				printf("branch genphs_charge_branch does not exist!\n");
				exit(1);
			}
			genphs_charge_isLoaded = true;
		}
		return *genphs_charge_;
	}
	const vector<float> &genphs_iso()
	{
		if (not genphs_iso_isLoaded) {
			if (genphs_iso_branch != 0) {
				genphs_iso_branch->GetEntry(index);
			} else { 
				printf("branch genphs_iso_branch does not exist!\n");
				exit(1);
			}
			genphs_iso_isLoaded = true;
		}
		return *genphs_iso_;
	}
	const vector<float> &genphs_mass()
	{
		if (not genphs_mass_isLoaded) {
			if (genphs_mass_branch != 0) {
				genphs_mass_branch->GetEntry(index);
			} else { 
				printf("branch genphs_mass_branch does not exist!\n");
				exit(1);
			}
			genphs_mass_isLoaded = true;
		}
		return *genphs_mass_;
	}
	const vector<int> &genphs_id()
	{
		if (not genphs_id_isLoaded) {
			if (genphs_id_branch != 0) {
				genphs_id_branch->GetEntry(index);
			} else { 
				printf("branch genphs_id_branch does not exist!\n");
				exit(1);
			}
			genphs_id_isLoaded = true;
		}
		return *genphs_id_;
	}
	const vector<int> &genphs__genpsidx()
	{
		if (not genphs__genpsidx_isLoaded) {
			if (genphs__genpsidx_branch != 0) {
				genphs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genphs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genphs__genpsidx_isLoaded = true;
		}
		return *genphs__genpsidx_;
	}
	const vector<int> &genphs_status()
	{
		if (not genphs_status_isLoaded) {
			if (genphs_status_branch != 0) {
				genphs_status_branch->GetEntry(index);
			} else { 
				printf("branch genphs_status_branch does not exist!\n");
				exit(1);
			}
			genphs_status_isLoaded = true;
		}
		return *genphs_status_;
	}
	const vector<bool> &genphs_fromHardProcessBeforeFSR()
	{
		if (not genphs_fromHardProcessBeforeFSR_isLoaded) {
			if (genphs_fromHardProcessBeforeFSR_branch != 0) {
				genphs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genphs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genphs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genphs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genphs_fromHardProcessDecayed()
	{
		if (not genphs_fromHardProcessDecayed_isLoaded) {
			if (genphs_fromHardProcessDecayed_branch != 0) {
				genphs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genphs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genphs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genphs_fromHardProcessDecayed_;
	}
	const vector<bool> &genphs_fromHardProcessFinalState()
	{
		if (not genphs_fromHardProcessFinalState_isLoaded) {
			if (genphs_fromHardProcessFinalState_branch != 0) {
				genphs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genphs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genphs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genphs_fromHardProcessFinalState_;
	}
	const vector<bool> &genphs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genphs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genphs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genphs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genphs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genphs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genphs_isDirectPromptTauDecayProductFinalState()
	{
		if (not genphs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genphs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genphs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genphs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genphs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genphs_isHardProcess()
	{
		if (not genphs_isHardProcess_isLoaded) {
			if (genphs_isHardProcess_branch != 0) {
				genphs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genphs_isHardProcess_isLoaded = true;
		}
		return *genphs_isHardProcess_;
	}
	const vector<bool> &genphs_isLastCopy()
	{
		if (not genphs_isLastCopy_isLoaded) {
			if (genphs_isLastCopy_branch != 0) {
				genphs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genphs_isLastCopy_isLoaded = true;
		}
		return *genphs_isLastCopy_;
	}
	const vector<bool> &genphs_isLastCopyBeforeFSR()
	{
		if (not genphs_isLastCopyBeforeFSR_isLoaded) {
			if (genphs_isLastCopyBeforeFSR_branch != 0) {
				genphs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genphs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genphs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genphs_isMostlyLikePythia6Status3()
	{
		if (not genphs_isMostlyLikePythia6Status3_isLoaded) {
			if (genphs_isMostlyLikePythia6Status3_branch != 0) {
				genphs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genphs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genphs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genphs_isPromptDecayed()
	{
		if (not genphs_isPromptDecayed_isLoaded) {
			if (genphs_isPromptDecayed_branch != 0) {
				genphs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genphs_isPromptDecayed_isLoaded = true;
		}
		return *genphs_isPromptDecayed_;
	}
	const vector<bool> &genphs_isPromptFinalState()
	{
		if (not genphs_isPromptFinalState_isLoaded) {
			if (genphs_isPromptFinalState_branch != 0) {
				genphs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genphs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genphs_isPromptFinalState_isLoaded = true;
		}
		return *genphs_isPromptFinalState_;
	}
	const vector<vector<int> > &genphs_lepdaughter_id()
	{
		if (not genphs_lepdaughter_id_isLoaded) {
			if (genphs_lepdaughter_id_branch != 0) {
				genphs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genphs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genphs_lepdaughter_id_isLoaded = true;
		}
		return *genphs_lepdaughter_id_;
	}
	const vector<int> &genphs_gentaudecay()
	{
		if (not genphs_gentaudecay_isLoaded) {
			if (genphs_gentaudecay_branch != 0) {
				genphs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genphs_gentaudecay_isLoaded = true;
		}
		return *genphs_gentaudecay_;
	}
	int &gen_nfromtphs_()
	{
		if (not gen_nfromtphs__isLoaded) {
			if (gen_nfromtphs__branch != 0) {
				gen_nfromtphs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtphs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtphs__isLoaded = true;
		}
		return gen_nfromtphs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_motherp4()
	{
		if (not genphs_motherp4_isLoaded) {
			if (genphs_motherp4_branch != 0) {
				genphs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genphs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genphs_motherp4_isLoaded = true;
		}
		return *genphs_motherp4_;
	}
	const vector<float> &genphs_mothercharge()
	{
		if (not genphs_mothercharge_isLoaded) {
			if (genphs_mothercharge_branch != 0) {
				genphs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genphs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genphs_mothercharge_isLoaded = true;
		}
		return *genphs_mothercharge_;
	}
	const vector<int> &genphs_motherid()
	{
		if (not genphs_motherid_isLoaded) {
			if (genphs_motherid_branch != 0) {
				genphs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genphs_motherid_branch does not exist!\n");
				exit(1);
			}
			genphs_motherid_isLoaded = true;
		}
		return *genphs_motherid_;
	}
	const vector<int> &genphs_motheridx()
	{
		if (not genphs_motheridx_isLoaded) {
			if (genphs_motheridx_branch != 0) {
				genphs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genphs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genphs_motheridx_isLoaded = true;
		}
		return *genphs_motheridx_;
	}
	const vector<int> &genphs_motherstatus()
	{
		if (not genphs_motherstatus_isLoaded) {
			if (genphs_motherstatus_branch != 0) {
				genphs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genphs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genphs_motherstatus_isLoaded = true;
		}
		return *genphs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_gmotherp4()
	{
		if (not genphs_gmotherp4_isLoaded) {
			if (genphs_gmotherp4_branch != 0) {
				genphs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genphs_gmotherp4_isLoaded = true;
		}
		return *genphs_gmotherp4_;
	}
	const vector<int> &genphs_gmothercharge()
	{
		if (not genphs_gmothercharge_isLoaded) {
			if (genphs_gmothercharge_branch != 0) {
				genphs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genphs_gmothercharge_isLoaded = true;
		}
		return *genphs_gmothercharge_;
	}
	const vector<int> &genphs_gmotherid()
	{
		if (not genphs_gmotherid_isLoaded) {
			if (genphs_gmotherid_branch != 0) {
				genphs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genphs_gmotherid_isLoaded = true;
		}
		return *genphs_gmotherid_;
	}
	const vector<int> &genphs_gmotheridx()
	{
		if (not genphs_gmotheridx_isLoaded) {
			if (genphs_gmotheridx_branch != 0) {
				genphs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genphs_gmotheridx_isLoaded = true;
		}
		return *genphs_gmotheridx_;
	}
	const vector<int> &genphs_gmotherstatus()
	{
		if (not genphs_gmotherstatus_isLoaded) {
			if (genphs_gmotherstatus_branch != 0) {
				genphs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genphs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genphs_gmotherstatus_isLoaded = true;
		}
		return *genphs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplemotherp4()
	{
		if (not genphs_simplemotherp4_isLoaded) {
			if (genphs_simplemotherp4_branch != 0) {
				genphs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genphs_simplemotherp4_isLoaded = true;
		}
		return *genphs_simplemotherp4_;
	}
	const vector<int> &genphs_simplemothercharge()
	{
		if (not genphs_simplemothercharge_isLoaded) {
			if (genphs_simplemothercharge_branch != 0) {
				genphs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genphs_simplemothercharge_isLoaded = true;
		}
		return *genphs_simplemothercharge_;
	}
	const vector<int> &genphs_simplemotherid()
	{
		if (not genphs_simplemotherid_isLoaded) {
			if (genphs_simplemotherid_branch != 0) {
				genphs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genphs_simplemotherid_isLoaded = true;
		}
		return *genphs_simplemotherid_;
	}
	const vector<int> &genphs_simplemotheridx()
	{
		if (not genphs_simplemotheridx_isLoaded) {
			if (genphs_simplemotheridx_branch != 0) {
				genphs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genphs_simplemotheridx_isLoaded = true;
		}
		return *genphs_simplemotheridx_;
	}
	const vector<int> &genphs_simplemotherstatus()
	{
		if (not genphs_simplemotherstatus_isLoaded) {
			if (genphs_simplemotherstatus_branch != 0) {
				genphs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genphs_simplemotherstatus_isLoaded = true;
		}
		return *genphs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplegmotherp4()
	{
		if (not genphs_simplegmotherp4_isLoaded) {
			if (genphs_simplegmotherp4_branch != 0) {
				genphs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genphs_simplegmotherp4_isLoaded = true;
		}
		return *genphs_simplegmotherp4_;
	}
	const vector<int> &genphs_simplegmothercharge()
	{
		if (not genphs_simplegmothercharge_isLoaded) {
			if (genphs_simplegmothercharge_branch != 0) {
				genphs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genphs_simplegmothercharge_isLoaded = true;
		}
		return *genphs_simplegmothercharge_;
	}
	const vector<int> &genphs_simplegmotherid()
	{
		if (not genphs_simplegmotherid_isLoaded) {
			if (genphs_simplegmotherid_branch != 0) {
				genphs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genphs_simplegmotherid_isLoaded = true;
		}
		return *genphs_simplegmotherid_;
	}
	const vector<int> &genphs_simplegmotheridx()
	{
		if (not genphs_simplegmotheridx_isLoaded) {
			if (genphs_simplegmotheridx_branch != 0) {
				genphs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genphs_simplegmotheridx_isLoaded = true;
		}
		return *genphs_simplegmotheridx_;
	}
	const vector<int> &genphs_simplegmotherstatus()
	{
		if (not genphs_simplegmotherstatus_isLoaded) {
			if (genphs_simplegmotherstatus_branch != 0) {
				genphs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genphs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genphs_simplegmotherstatus_isLoaded = true;
		}
		return *genphs_simplegmotherstatus_;
	}
	const vector<bool> &genhs_isfromt()
	{
		if (not genhs_isfromt_isLoaded) {
			if (genhs_isfromt_branch != 0) {
				genhs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genhs_isfromt_isLoaded = true;
		}
		return *genhs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_p4()
	{
		if (not genhs_p4_isLoaded) {
			if (genhs_p4_branch != 0) {
				genhs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genhs_p4_branch does not exist!\n");
				exit(1);
			}
			genhs_p4_isLoaded = true;
		}
		return *genhs_p4_;
	}
	const vector<float> &genhs_charge()
	{
		if (not genhs_charge_isLoaded) {
			if (genhs_charge_branch != 0) {
				genhs_charge_branch->GetEntry(index);
			} else { 
				printf("branch genhs_charge_branch does not exist!\n");
				exit(1);
			}
			genhs_charge_isLoaded = true;
		}
		return *genhs_charge_;
	}
	const vector<float> &genhs_iso()
	{
		if (not genhs_iso_isLoaded) {
			if (genhs_iso_branch != 0) {
				genhs_iso_branch->GetEntry(index);
			} else { 
				printf("branch genhs_iso_branch does not exist!\n");
				exit(1);
			}
			genhs_iso_isLoaded = true;
		}
		return *genhs_iso_;
	}
	const vector<float> &genhs_mass()
	{
		if (not genhs_mass_isLoaded) {
			if (genhs_mass_branch != 0) {
				genhs_mass_branch->GetEntry(index);
			} else { 
				printf("branch genhs_mass_branch does not exist!\n");
				exit(1);
			}
			genhs_mass_isLoaded = true;
		}
		return *genhs_mass_;
	}
	const vector<int> &genhs_id()
	{
		if (not genhs_id_isLoaded) {
			if (genhs_id_branch != 0) {
				genhs_id_branch->GetEntry(index);
			} else { 
				printf("branch genhs_id_branch does not exist!\n");
				exit(1);
			}
			genhs_id_isLoaded = true;
		}
		return *genhs_id_;
	}
	const vector<int> &genhs__genpsidx()
	{
		if (not genhs__genpsidx_isLoaded) {
			if (genhs__genpsidx_branch != 0) {
				genhs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genhs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genhs__genpsidx_isLoaded = true;
		}
		return *genhs__genpsidx_;
	}
	const vector<int> &genhs_status()
	{
		if (not genhs_status_isLoaded) {
			if (genhs_status_branch != 0) {
				genhs_status_branch->GetEntry(index);
			} else { 
				printf("branch genhs_status_branch does not exist!\n");
				exit(1);
			}
			genhs_status_isLoaded = true;
		}
		return *genhs_status_;
	}
	const vector<bool> &genhs_fromHardProcessBeforeFSR()
	{
		if (not genhs_fromHardProcessBeforeFSR_isLoaded) {
			if (genhs_fromHardProcessBeforeFSR_branch != 0) {
				genhs_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genhs_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genhs_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genhs_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genhs_fromHardProcessDecayed()
	{
		if (not genhs_fromHardProcessDecayed_isLoaded) {
			if (genhs_fromHardProcessDecayed_branch != 0) {
				genhs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genhs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genhs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genhs_fromHardProcessDecayed_;
	}
	const vector<bool> &genhs_fromHardProcessFinalState()
	{
		if (not genhs_fromHardProcessFinalState_isLoaded) {
			if (genhs_fromHardProcessFinalState_branch != 0) {
				genhs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genhs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genhs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genhs_fromHardProcessFinalState_;
	}
	const vector<bool> &genhs_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genhs_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genhs_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genhs_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genhs_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genhs_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genhs_isDirectPromptTauDecayProductFinalState()
	{
		if (not genhs_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genhs_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genhs_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genhs_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genhs_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genhs_isHardProcess()
	{
		if (not genhs_isHardProcess_isLoaded) {
			if (genhs_isHardProcess_branch != 0) {
				genhs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genhs_isHardProcess_isLoaded = true;
		}
		return *genhs_isHardProcess_;
	}
	const vector<bool> &genhs_isLastCopy()
	{
		if (not genhs_isLastCopy_isLoaded) {
			if (genhs_isLastCopy_branch != 0) {
				genhs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genhs_isLastCopy_isLoaded = true;
		}
		return *genhs_isLastCopy_;
	}
	const vector<bool> &genhs_isLastCopyBeforeFSR()
	{
		if (not genhs_isLastCopyBeforeFSR_isLoaded) {
			if (genhs_isLastCopyBeforeFSR_branch != 0) {
				genhs_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genhs_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genhs_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genhs_isMostlyLikePythia6Status3()
	{
		if (not genhs_isMostlyLikePythia6Status3_isLoaded) {
			if (genhs_isMostlyLikePythia6Status3_branch != 0) {
				genhs_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genhs_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genhs_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genhs_isPromptDecayed()
	{
		if (not genhs_isPromptDecayed_isLoaded) {
			if (genhs_isPromptDecayed_branch != 0) {
				genhs_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genhs_isPromptDecayed_isLoaded = true;
		}
		return *genhs_isPromptDecayed_;
	}
	const vector<bool> &genhs_isPromptFinalState()
	{
		if (not genhs_isPromptFinalState_isLoaded) {
			if (genhs_isPromptFinalState_branch != 0) {
				genhs_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genhs_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genhs_isPromptFinalState_isLoaded = true;
		}
		return *genhs_isPromptFinalState_;
	}
	const vector<vector<int> > &genhs_lepdaughter_id()
	{
		if (not genhs_lepdaughter_id_isLoaded) {
			if (genhs_lepdaughter_id_branch != 0) {
				genhs_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genhs_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genhs_lepdaughter_id_isLoaded = true;
		}
		return *genhs_lepdaughter_id_;
	}
	const vector<int> &genhs_gentaudecay()
	{
		if (not genhs_gentaudecay_isLoaded) {
			if (genhs_gentaudecay_branch != 0) {
				genhs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genhs_gentaudecay_isLoaded = true;
		}
		return *genhs_gentaudecay_;
	}
	int &gen_nfromths_()
	{
		if (not gen_nfromths__isLoaded) {
			if (gen_nfromths__branch != 0) {
				gen_nfromths__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromths__branch does not exist!\n");
				exit(1);
			}
			gen_nfromths__isLoaded = true;
		}
		return gen_nfromths__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_motherp4()
	{
		if (not genhs_motherp4_isLoaded) {
			if (genhs_motherp4_branch != 0) {
				genhs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genhs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genhs_motherp4_isLoaded = true;
		}
		return *genhs_motherp4_;
	}
	const vector<float> &genhs_mothercharge()
	{
		if (not genhs_mothercharge_isLoaded) {
			if (genhs_mothercharge_branch != 0) {
				genhs_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genhs_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genhs_mothercharge_isLoaded = true;
		}
		return *genhs_mothercharge_;
	}
	const vector<int> &genhs_motherid()
	{
		if (not genhs_motherid_isLoaded) {
			if (genhs_motherid_branch != 0) {
				genhs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genhs_motherid_branch does not exist!\n");
				exit(1);
			}
			genhs_motherid_isLoaded = true;
		}
		return *genhs_motherid_;
	}
	const vector<int> &genhs_motheridx()
	{
		if (not genhs_motheridx_isLoaded) {
			if (genhs_motheridx_branch != 0) {
				genhs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genhs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genhs_motheridx_isLoaded = true;
		}
		return *genhs_motheridx_;
	}
	const vector<int> &genhs_motherstatus()
	{
		if (not genhs_motherstatus_isLoaded) {
			if (genhs_motherstatus_branch != 0) {
				genhs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genhs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genhs_motherstatus_isLoaded = true;
		}
		return *genhs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_gmotherp4()
	{
		if (not genhs_gmotherp4_isLoaded) {
			if (genhs_gmotherp4_branch != 0) {
				genhs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genhs_gmotherp4_isLoaded = true;
		}
		return *genhs_gmotherp4_;
	}
	const vector<int> &genhs_gmothercharge()
	{
		if (not genhs_gmothercharge_isLoaded) {
			if (genhs_gmothercharge_branch != 0) {
				genhs_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genhs_gmothercharge_isLoaded = true;
		}
		return *genhs_gmothercharge_;
	}
	const vector<int> &genhs_gmotherid()
	{
		if (not genhs_gmotherid_isLoaded) {
			if (genhs_gmotherid_branch != 0) {
				genhs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genhs_gmotherid_isLoaded = true;
		}
		return *genhs_gmotherid_;
	}
	const vector<int> &genhs_gmotheridx()
	{
		if (not genhs_gmotheridx_isLoaded) {
			if (genhs_gmotheridx_branch != 0) {
				genhs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genhs_gmotheridx_isLoaded = true;
		}
		return *genhs_gmotheridx_;
	}
	const vector<int> &genhs_gmotherstatus()
	{
		if (not genhs_gmotherstatus_isLoaded) {
			if (genhs_gmotherstatus_branch != 0) {
				genhs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genhs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genhs_gmotherstatus_isLoaded = true;
		}
		return *genhs_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplemotherp4()
	{
		if (not genhs_simplemotherp4_isLoaded) {
			if (genhs_simplemotherp4_branch != 0) {
				genhs_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genhs_simplemotherp4_isLoaded = true;
		}
		return *genhs_simplemotherp4_;
	}
	const vector<int> &genhs_simplemothercharge()
	{
		if (not genhs_simplemothercharge_isLoaded) {
			if (genhs_simplemothercharge_branch != 0) {
				genhs_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genhs_simplemothercharge_isLoaded = true;
		}
		return *genhs_simplemothercharge_;
	}
	const vector<int> &genhs_simplemotherid()
	{
		if (not genhs_simplemotherid_isLoaded) {
			if (genhs_simplemotherid_branch != 0) {
				genhs_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genhs_simplemotherid_isLoaded = true;
		}
		return *genhs_simplemotherid_;
	}
	const vector<int> &genhs_simplemotheridx()
	{
		if (not genhs_simplemotheridx_isLoaded) {
			if (genhs_simplemotheridx_branch != 0) {
				genhs_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genhs_simplemotheridx_isLoaded = true;
		}
		return *genhs_simplemotheridx_;
	}
	const vector<int> &genhs_simplemotherstatus()
	{
		if (not genhs_simplemotherstatus_isLoaded) {
			if (genhs_simplemotherstatus_branch != 0) {
				genhs_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genhs_simplemotherstatus_isLoaded = true;
		}
		return *genhs_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplegmotherp4()
	{
		if (not genhs_simplegmotherp4_isLoaded) {
			if (genhs_simplegmotherp4_branch != 0) {
				genhs_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genhs_simplegmotherp4_isLoaded = true;
		}
		return *genhs_simplegmotherp4_;
	}
	const vector<int> &genhs_simplegmothercharge()
	{
		if (not genhs_simplegmothercharge_isLoaded) {
			if (genhs_simplegmothercharge_branch != 0) {
				genhs_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genhs_simplegmothercharge_isLoaded = true;
		}
		return *genhs_simplegmothercharge_;
	}
	const vector<int> &genhs_simplegmotherid()
	{
		if (not genhs_simplegmotherid_isLoaded) {
			if (genhs_simplegmotherid_branch != 0) {
				genhs_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genhs_simplegmotherid_isLoaded = true;
		}
		return *genhs_simplegmotherid_;
	}
	const vector<int> &genhs_simplegmotheridx()
	{
		if (not genhs_simplegmotheridx_isLoaded) {
			if (genhs_simplegmotheridx_branch != 0) {
				genhs_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genhs_simplegmotheridx_isLoaded = true;
		}
		return *genhs_simplegmotheridx_;
	}
	const vector<int> &genhs_simplegmotherstatus()
	{
		if (not genhs_simplegmotherstatus_isLoaded) {
			if (genhs_simplegmotherstatus_branch != 0) {
				genhs_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genhs_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genhs_simplegmotherstatus_isLoaded = true;
		}
		return *genhs_simplegmotherstatus_;
	}
	const vector<bool> &genlsp_isfromt()
	{
		if (not genlsp_isfromt_isLoaded) {
			if (genlsp_isfromt_branch != 0) {
				genlsp_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isfromt_branch does not exist!\n");
				exit(1);
			}
			genlsp_isfromt_isLoaded = true;
		}
		return *genlsp_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_p4()
	{
		if (not genlsp_p4_isLoaded) {
			if (genlsp_p4_branch != 0) {
				genlsp_p4_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_p4_branch does not exist!\n");
				exit(1);
			}
			genlsp_p4_isLoaded = true;
		}
		return *genlsp_p4_;
	}
	const vector<float> &genlsp_charge()
	{
		if (not genlsp_charge_isLoaded) {
			if (genlsp_charge_branch != 0) {
				genlsp_charge_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_charge_branch does not exist!\n");
				exit(1);
			}
			genlsp_charge_isLoaded = true;
		}
		return *genlsp_charge_;
	}
	const vector<float> &genlsp_iso()
	{
		if (not genlsp_iso_isLoaded) {
			if (genlsp_iso_branch != 0) {
				genlsp_iso_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_iso_branch does not exist!\n");
				exit(1);
			}
			genlsp_iso_isLoaded = true;
		}
		return *genlsp_iso_;
	}
	const vector<float> &genlsp_mass()
	{
		if (not genlsp_mass_isLoaded) {
			if (genlsp_mass_branch != 0) {
				genlsp_mass_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_mass_branch does not exist!\n");
				exit(1);
			}
			genlsp_mass_isLoaded = true;
		}
		return *genlsp_mass_;
	}
	const vector<int> &genlsp_id()
	{
		if (not genlsp_id_isLoaded) {
			if (genlsp_id_branch != 0) {
				genlsp_id_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_id_branch does not exist!\n");
				exit(1);
			}
			genlsp_id_isLoaded = true;
		}
		return *genlsp_id_;
	}
	const vector<int> &genlsp__genpsidx()
	{
		if (not genlsp__genpsidx_isLoaded) {
			if (genlsp__genpsidx_branch != 0) {
				genlsp__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genlsp__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genlsp__genpsidx_isLoaded = true;
		}
		return *genlsp__genpsidx_;
	}
	const vector<int> &genlsp_status()
	{
		if (not genlsp_status_isLoaded) {
			if (genlsp_status_branch != 0) {
				genlsp_status_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_status_branch does not exist!\n");
				exit(1);
			}
			genlsp_status_isLoaded = true;
		}
		return *genlsp_status_;
	}
	const vector<bool> &genlsp_fromHardProcessBeforeFSR()
	{
		if (not genlsp_fromHardProcessBeforeFSR_isLoaded) {
			if (genlsp_fromHardProcessBeforeFSR_branch != 0) {
				genlsp_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genlsp_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genlsp_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genlsp_fromHardProcessDecayed()
	{
		if (not genlsp_fromHardProcessDecayed_isLoaded) {
			if (genlsp_fromHardProcessDecayed_branch != 0) {
				genlsp_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genlsp_fromHardProcessDecayed_isLoaded = true;
		}
		return *genlsp_fromHardProcessDecayed_;
	}
	const vector<bool> &genlsp_fromHardProcessFinalState()
	{
		if (not genlsp_fromHardProcessFinalState_isLoaded) {
			if (genlsp_fromHardProcessFinalState_branch != 0) {
				genlsp_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genlsp_fromHardProcessFinalState_isLoaded = true;
		}
		return *genlsp_fromHardProcessFinalState_;
	}
	const vector<bool> &genlsp_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genlsp_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genlsp_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genlsp_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genlsp_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genlsp_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genlsp_isDirectPromptTauDecayProductFinalState()
	{
		if (not genlsp_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genlsp_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genlsp_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genlsp_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genlsp_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genlsp_isHardProcess()
	{
		if (not genlsp_isHardProcess_isLoaded) {
			if (genlsp_isHardProcess_branch != 0) {
				genlsp_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genlsp_isHardProcess_isLoaded = true;
		}
		return *genlsp_isHardProcess_;
	}
	const vector<bool> &genlsp_isLastCopy()
	{
		if (not genlsp_isLastCopy_isLoaded) {
			if (genlsp_isLastCopy_branch != 0) {
				genlsp_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genlsp_isLastCopy_isLoaded = true;
		}
		return *genlsp_isLastCopy_;
	}
	const vector<bool> &genlsp_isLastCopyBeforeFSR()
	{
		if (not genlsp_isLastCopyBeforeFSR_isLoaded) {
			if (genlsp_isLastCopyBeforeFSR_branch != 0) {
				genlsp_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genlsp_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genlsp_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genlsp_isMostlyLikePythia6Status3()
	{
		if (not genlsp_isMostlyLikePythia6Status3_isLoaded) {
			if (genlsp_isMostlyLikePythia6Status3_branch != 0) {
				genlsp_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genlsp_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genlsp_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genlsp_isPromptDecayed()
	{
		if (not genlsp_isPromptDecayed_isLoaded) {
			if (genlsp_isPromptDecayed_branch != 0) {
				genlsp_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genlsp_isPromptDecayed_isLoaded = true;
		}
		return *genlsp_isPromptDecayed_;
	}
	const vector<bool> &genlsp_isPromptFinalState()
	{
		if (not genlsp_isPromptFinalState_isLoaded) {
			if (genlsp_isPromptFinalState_branch != 0) {
				genlsp_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genlsp_isPromptFinalState_isLoaded = true;
		}
		return *genlsp_isPromptFinalState_;
	}
	const vector<vector<int> > &genlsp_lepdaughter_id()
	{
		if (not genlsp_lepdaughter_id_isLoaded) {
			if (genlsp_lepdaughter_id_branch != 0) {
				genlsp_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genlsp_lepdaughter_id_isLoaded = true;
		}
		return *genlsp_lepdaughter_id_;
	}
	const vector<int> &genlsp_gentaudecay()
	{
		if (not genlsp_gentaudecay_isLoaded) {
			if (genlsp_gentaudecay_branch != 0) {
				genlsp_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genlsp_gentaudecay_isLoaded = true;
		}
		return *genlsp_gentaudecay_;
	}
	int &gen_nfromtlsp_()
	{
		if (not gen_nfromtlsp__isLoaded) {
			if (gen_nfromtlsp__branch != 0) {
				gen_nfromtlsp__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtlsp__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtlsp__isLoaded = true;
		}
		return gen_nfromtlsp__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_motherp4()
	{
		if (not genlsp_motherp4_isLoaded) {
			if (genlsp_motherp4_branch != 0) {
				genlsp_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_motherp4_branch does not exist!\n");
				exit(1);
			}
			genlsp_motherp4_isLoaded = true;
		}
		return *genlsp_motherp4_;
	}
	const vector<float> &genlsp_mothercharge()
	{
		if (not genlsp_mothercharge_isLoaded) {
			if (genlsp_mothercharge_branch != 0) {
				genlsp_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genlsp_mothercharge_isLoaded = true;
		}
		return *genlsp_mothercharge_;
	}
	const vector<int> &genlsp_motherid()
	{
		if (not genlsp_motherid_isLoaded) {
			if (genlsp_motherid_branch != 0) {
				genlsp_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_motherid_branch does not exist!\n");
				exit(1);
			}
			genlsp_motherid_isLoaded = true;
		}
		return *genlsp_motherid_;
	}
	const vector<int> &genlsp_motheridx()
	{
		if (not genlsp_motheridx_isLoaded) {
			if (genlsp_motheridx_branch != 0) {
				genlsp_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_motheridx_branch does not exist!\n");
				exit(1);
			}
			genlsp_motheridx_isLoaded = true;
		}
		return *genlsp_motheridx_;
	}
	const vector<int> &genlsp_motherstatus()
	{
		if (not genlsp_motherstatus_isLoaded) {
			if (genlsp_motherstatus_branch != 0) {
				genlsp_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genlsp_motherstatus_isLoaded = true;
		}
		return *genlsp_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_gmotherp4()
	{
		if (not genlsp_gmotherp4_isLoaded) {
			if (genlsp_gmotherp4_branch != 0) {
				genlsp_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genlsp_gmotherp4_isLoaded = true;
		}
		return *genlsp_gmotherp4_;
	}
	const vector<int> &genlsp_gmothercharge()
	{
		if (not genlsp_gmothercharge_isLoaded) {
			if (genlsp_gmothercharge_branch != 0) {
				genlsp_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genlsp_gmothercharge_isLoaded = true;
		}
		return *genlsp_gmothercharge_;
	}
	const vector<int> &genlsp_gmotherid()
	{
		if (not genlsp_gmotherid_isLoaded) {
			if (genlsp_gmotherid_branch != 0) {
				genlsp_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genlsp_gmotherid_isLoaded = true;
		}
		return *genlsp_gmotherid_;
	}
	const vector<int> &genlsp_gmotheridx()
	{
		if (not genlsp_gmotheridx_isLoaded) {
			if (genlsp_gmotheridx_branch != 0) {
				genlsp_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genlsp_gmotheridx_isLoaded = true;
		}
		return *genlsp_gmotheridx_;
	}
	const vector<int> &genlsp_gmotherstatus()
	{
		if (not genlsp_gmotherstatus_isLoaded) {
			if (genlsp_gmotherstatus_branch != 0) {
				genlsp_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genlsp_gmotherstatus_isLoaded = true;
		}
		return *genlsp_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplemotherp4()
	{
		if (not genlsp_simplemotherp4_isLoaded) {
			if (genlsp_simplemotherp4_branch != 0) {
				genlsp_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplemotherp4_isLoaded = true;
		}
		return *genlsp_simplemotherp4_;
	}
	const vector<int> &genlsp_simplemothercharge()
	{
		if (not genlsp_simplemothercharge_isLoaded) {
			if (genlsp_simplemothercharge_branch != 0) {
				genlsp_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplemothercharge_isLoaded = true;
		}
		return *genlsp_simplemothercharge_;
	}
	const vector<int> &genlsp_simplemotherid()
	{
		if (not genlsp_simplemotherid_isLoaded) {
			if (genlsp_simplemotherid_branch != 0) {
				genlsp_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplemotherid_isLoaded = true;
		}
		return *genlsp_simplemotherid_;
	}
	const vector<int> &genlsp_simplemotheridx()
	{
		if (not genlsp_simplemotheridx_isLoaded) {
			if (genlsp_simplemotheridx_branch != 0) {
				genlsp_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplemotheridx_isLoaded = true;
		}
		return *genlsp_simplemotheridx_;
	}
	const vector<int> &genlsp_simplemotherstatus()
	{
		if (not genlsp_simplemotherstatus_isLoaded) {
			if (genlsp_simplemotherstatus_branch != 0) {
				genlsp_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplemotherstatus_isLoaded = true;
		}
		return *genlsp_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplegmotherp4()
	{
		if (not genlsp_simplegmotherp4_isLoaded) {
			if (genlsp_simplegmotherp4_branch != 0) {
				genlsp_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplegmotherp4_isLoaded = true;
		}
		return *genlsp_simplegmotherp4_;
	}
	const vector<int> &genlsp_simplegmothercharge()
	{
		if (not genlsp_simplegmothercharge_isLoaded) {
			if (genlsp_simplegmothercharge_branch != 0) {
				genlsp_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplegmothercharge_isLoaded = true;
		}
		return *genlsp_simplegmothercharge_;
	}
	const vector<int> &genlsp_simplegmotherid()
	{
		if (not genlsp_simplegmotherid_isLoaded) {
			if (genlsp_simplegmotherid_branch != 0) {
				genlsp_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplegmotherid_isLoaded = true;
		}
		return *genlsp_simplegmotherid_;
	}
	const vector<int> &genlsp_simplegmotheridx()
	{
		if (not genlsp_simplegmotheridx_isLoaded) {
			if (genlsp_simplegmotheridx_branch != 0) {
				genlsp_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplegmotheridx_isLoaded = true;
		}
		return *genlsp_simplegmotheridx_;
	}
	const vector<int> &genlsp_simplegmotherstatus()
	{
		if (not genlsp_simplegmotherstatus_isLoaded) {
			if (genlsp_simplegmotherstatus_branch != 0) {
				genlsp_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genlsp_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genlsp_simplegmotherstatus_isLoaded = true;
		}
		return *genlsp_simplegmotherstatus_;
	}
	const vector<bool> &genstop_isfromt()
	{
		if (not genstop_isfromt_isLoaded) {
			if (genstop_isfromt_branch != 0) {
				genstop_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isfromt_branch does not exist!\n");
				exit(1);
			}
			genstop_isfromt_isLoaded = true;
		}
		return *genstop_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_p4()
	{
		if (not genstop_p4_isLoaded) {
			if (genstop_p4_branch != 0) {
				genstop_p4_branch->GetEntry(index);
			} else { 
				printf("branch genstop_p4_branch does not exist!\n");
				exit(1);
			}
			genstop_p4_isLoaded = true;
		}
		return *genstop_p4_;
	}
	const vector<float> &genstop_charge()
	{
		if (not genstop_charge_isLoaded) {
			if (genstop_charge_branch != 0) {
				genstop_charge_branch->GetEntry(index);
			} else { 
				printf("branch genstop_charge_branch does not exist!\n");
				exit(1);
			}
			genstop_charge_isLoaded = true;
		}
		return *genstop_charge_;
	}
	const vector<float> &genstop_iso()
	{
		if (not genstop_iso_isLoaded) {
			if (genstop_iso_branch != 0) {
				genstop_iso_branch->GetEntry(index);
			} else { 
				printf("branch genstop_iso_branch does not exist!\n");
				exit(1);
			}
			genstop_iso_isLoaded = true;
		}
		return *genstop_iso_;
	}
	const vector<float> &genstop_mass()
	{
		if (not genstop_mass_isLoaded) {
			if (genstop_mass_branch != 0) {
				genstop_mass_branch->GetEntry(index);
			} else { 
				printf("branch genstop_mass_branch does not exist!\n");
				exit(1);
			}
			genstop_mass_isLoaded = true;
		}
		return *genstop_mass_;
	}
	const vector<int> &genstop_id()
	{
		if (not genstop_id_isLoaded) {
			if (genstop_id_branch != 0) {
				genstop_id_branch->GetEntry(index);
			} else { 
				printf("branch genstop_id_branch does not exist!\n");
				exit(1);
			}
			genstop_id_isLoaded = true;
		}
		return *genstop_id_;
	}
	const vector<int> &genstop__genpsidx()
	{
		if (not genstop__genpsidx_isLoaded) {
			if (genstop__genpsidx_branch != 0) {
				genstop__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genstop__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genstop__genpsidx_isLoaded = true;
		}
		return *genstop__genpsidx_;
	}
	const vector<int> &genstop_status()
	{
		if (not genstop_status_isLoaded) {
			if (genstop_status_branch != 0) {
				genstop_status_branch->GetEntry(index);
			} else { 
				printf("branch genstop_status_branch does not exist!\n");
				exit(1);
			}
			genstop_status_isLoaded = true;
		}
		return *genstop_status_;
	}
	const vector<bool> &genstop_fromHardProcessBeforeFSR()
	{
		if (not genstop_fromHardProcessBeforeFSR_isLoaded) {
			if (genstop_fromHardProcessBeforeFSR_branch != 0) {
				genstop_fromHardProcessBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genstop_fromHardProcessBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genstop_fromHardProcessBeforeFSR_isLoaded = true;
		}
		return *genstop_fromHardProcessBeforeFSR_;
	}
	const vector<bool> &genstop_fromHardProcessDecayed()
	{
		if (not genstop_fromHardProcessDecayed_isLoaded) {
			if (genstop_fromHardProcessDecayed_branch != 0) {
				genstop_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genstop_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genstop_fromHardProcessDecayed_isLoaded = true;
		}
		return *genstop_fromHardProcessDecayed_;
	}
	const vector<bool> &genstop_fromHardProcessFinalState()
	{
		if (not genstop_fromHardProcessFinalState_isLoaded) {
			if (genstop_fromHardProcessFinalState_branch != 0) {
				genstop_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genstop_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genstop_fromHardProcessFinalState_isLoaded = true;
		}
		return *genstop_fromHardProcessFinalState_;
	}
	const vector<bool> &genstop_isDirectHardProcessTauDecayProductFinalState()
	{
		if (not genstop_isDirectHardProcessTauDecayProductFinalState_isLoaded) {
			if (genstop_isDirectHardProcessTauDecayProductFinalState_branch != 0) {
				genstop_isDirectHardProcessTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isDirectHardProcessTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genstop_isDirectHardProcessTauDecayProductFinalState_isLoaded = true;
		}
		return *genstop_isDirectHardProcessTauDecayProductFinalState_;
	}
	const vector<bool> &genstop_isDirectPromptTauDecayProductFinalState()
	{
		if (not genstop_isDirectPromptTauDecayProductFinalState_isLoaded) {
			if (genstop_isDirectPromptTauDecayProductFinalState_branch != 0) {
				genstop_isDirectPromptTauDecayProductFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isDirectPromptTauDecayProductFinalState_branch does not exist!\n");
				exit(1);
			}
			genstop_isDirectPromptTauDecayProductFinalState_isLoaded = true;
		}
		return *genstop_isDirectPromptTauDecayProductFinalState_;
	}
	const vector<bool> &genstop_isHardProcess()
	{
		if (not genstop_isHardProcess_isLoaded) {
			if (genstop_isHardProcess_branch != 0) {
				genstop_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genstop_isHardProcess_isLoaded = true;
		}
		return *genstop_isHardProcess_;
	}
	const vector<bool> &genstop_isLastCopy()
	{
		if (not genstop_isLastCopy_isLoaded) {
			if (genstop_isLastCopy_branch != 0) {
				genstop_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genstop_isLastCopy_isLoaded = true;
		}
		return *genstop_isLastCopy_;
	}
	const vector<bool> &genstop_isLastCopyBeforeFSR()
	{
		if (not genstop_isLastCopyBeforeFSR_isLoaded) {
			if (genstop_isLastCopyBeforeFSR_branch != 0) {
				genstop_isLastCopyBeforeFSR_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isLastCopyBeforeFSR_branch does not exist!\n");
				exit(1);
			}
			genstop_isLastCopyBeforeFSR_isLoaded = true;
		}
		return *genstop_isLastCopyBeforeFSR_;
	}
	const vector<bool> &genstop_isMostlyLikePythia6Status3()
	{
		if (not genstop_isMostlyLikePythia6Status3_isLoaded) {
			if (genstop_isMostlyLikePythia6Status3_branch != 0) {
				genstop_isMostlyLikePythia6Status3_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isMostlyLikePythia6Status3_branch does not exist!\n");
				exit(1);
			}
			genstop_isMostlyLikePythia6Status3_isLoaded = true;
		}
		return *genstop_isMostlyLikePythia6Status3_;
	}
	const vector<bool> &genstop_isPromptDecayed()
	{
		if (not genstop_isPromptDecayed_isLoaded) {
			if (genstop_isPromptDecayed_branch != 0) {
				genstop_isPromptDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isPromptDecayed_branch does not exist!\n");
				exit(1);
			}
			genstop_isPromptDecayed_isLoaded = true;
		}
		return *genstop_isPromptDecayed_;
	}
	const vector<bool> &genstop_isPromptFinalState()
	{
		if (not genstop_isPromptFinalState_isLoaded) {
			if (genstop_isPromptFinalState_branch != 0) {
				genstop_isPromptFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genstop_isPromptFinalState_branch does not exist!\n");
				exit(1);
			}
			genstop_isPromptFinalState_isLoaded = true;
		}
		return *genstop_isPromptFinalState_;
	}
	const vector<vector<int> > &genstop_lepdaughter_id()
	{
		if (not genstop_lepdaughter_id_isLoaded) {
			if (genstop_lepdaughter_id_branch != 0) {
				genstop_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genstop_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genstop_lepdaughter_id_isLoaded = true;
		}
		return *genstop_lepdaughter_id_;
	}
	const vector<int> &genstop_gentaudecay()
	{
		if (not genstop_gentaudecay_isLoaded) {
			if (genstop_gentaudecay_branch != 0) {
				genstop_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genstop_gentaudecay_isLoaded = true;
		}
		return *genstop_gentaudecay_;
	}
	int &gen_nfromtstop_()
	{
		if (not gen_nfromtstop__isLoaded) {
			if (gen_nfromtstop__branch != 0) {
				gen_nfromtstop__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtstop__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtstop__isLoaded = true;
		}
		return gen_nfromtstop__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_motherp4()
	{
		if (not genstop_motherp4_isLoaded) {
			if (genstop_motherp4_branch != 0) {
				genstop_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genstop_motherp4_branch does not exist!\n");
				exit(1);
			}
			genstop_motherp4_isLoaded = true;
		}
		return *genstop_motherp4_;
	}
	const vector<float> &genstop_mothercharge()
	{
		if (not genstop_mothercharge_isLoaded) {
			if (genstop_mothercharge_branch != 0) {
				genstop_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genstop_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genstop_mothercharge_isLoaded = true;
		}
		return *genstop_mothercharge_;
	}
	const vector<int> &genstop_motherid()
	{
		if (not genstop_motherid_isLoaded) {
			if (genstop_motherid_branch != 0) {
				genstop_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genstop_motherid_branch does not exist!\n");
				exit(1);
			}
			genstop_motherid_isLoaded = true;
		}
		return *genstop_motherid_;
	}
	const vector<int> &genstop_motheridx()
	{
		if (not genstop_motheridx_isLoaded) {
			if (genstop_motheridx_branch != 0) {
				genstop_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genstop_motheridx_branch does not exist!\n");
				exit(1);
			}
			genstop_motheridx_isLoaded = true;
		}
		return *genstop_motheridx_;
	}
	const vector<int> &genstop_motherstatus()
	{
		if (not genstop_motherstatus_isLoaded) {
			if (genstop_motherstatus_branch != 0) {
				genstop_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genstop_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genstop_motherstatus_isLoaded = true;
		}
		return *genstop_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_gmotherp4()
	{
		if (not genstop_gmotherp4_isLoaded) {
			if (genstop_gmotherp4_branch != 0) {
				genstop_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genstop_gmotherp4_isLoaded = true;
		}
		return *genstop_gmotherp4_;
	}
	const vector<int> &genstop_gmothercharge()
	{
		if (not genstop_gmothercharge_isLoaded) {
			if (genstop_gmothercharge_branch != 0) {
				genstop_gmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gmothercharge_branch does not exist!\n");
				exit(1);
			}
			genstop_gmothercharge_isLoaded = true;
		}
		return *genstop_gmothercharge_;
	}
	const vector<int> &genstop_gmotherid()
	{
		if (not genstop_gmotherid_isLoaded) {
			if (genstop_gmotherid_branch != 0) {
				genstop_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genstop_gmotherid_isLoaded = true;
		}
		return *genstop_gmotherid_;
	}
	const vector<int> &genstop_gmotheridx()
	{
		if (not genstop_gmotheridx_isLoaded) {
			if (genstop_gmotheridx_branch != 0) {
				genstop_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genstop_gmotheridx_isLoaded = true;
		}
		return *genstop_gmotheridx_;
	}
	const vector<int> &genstop_gmotherstatus()
	{
		if (not genstop_gmotherstatus_isLoaded) {
			if (genstop_gmotherstatus_branch != 0) {
				genstop_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genstop_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genstop_gmotherstatus_isLoaded = true;
		}
		return *genstop_gmotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplemotherp4()
	{
		if (not genstop_simplemotherp4_isLoaded) {
			if (genstop_simplemotherp4_branch != 0) {
				genstop_simplemotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplemotherp4_branch does not exist!\n");
				exit(1);
			}
			genstop_simplemotherp4_isLoaded = true;
		}
		return *genstop_simplemotherp4_;
	}
	const vector<int> &genstop_simplemothercharge()
	{
		if (not genstop_simplemothercharge_isLoaded) {
			if (genstop_simplemothercharge_branch != 0) {
				genstop_simplemothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplemothercharge_branch does not exist!\n");
				exit(1);
			}
			genstop_simplemothercharge_isLoaded = true;
		}
		return *genstop_simplemothercharge_;
	}
	const vector<int> &genstop_simplemotherid()
	{
		if (not genstop_simplemotherid_isLoaded) {
			if (genstop_simplemotherid_branch != 0) {
				genstop_simplemotherid_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplemotherid_branch does not exist!\n");
				exit(1);
			}
			genstop_simplemotherid_isLoaded = true;
		}
		return *genstop_simplemotherid_;
	}
	const vector<int> &genstop_simplemotheridx()
	{
		if (not genstop_simplemotheridx_isLoaded) {
			if (genstop_simplemotheridx_branch != 0) {
				genstop_simplemotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplemotheridx_branch does not exist!\n");
				exit(1);
			}
			genstop_simplemotheridx_isLoaded = true;
		}
		return *genstop_simplemotheridx_;
	}
	const vector<int> &genstop_simplemotherstatus()
	{
		if (not genstop_simplemotherstatus_isLoaded) {
			if (genstop_simplemotherstatus_branch != 0) {
				genstop_simplemotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplemotherstatus_branch does not exist!\n");
				exit(1);
			}
			genstop_simplemotherstatus_isLoaded = true;
		}
		return *genstop_simplemotherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplegmotherp4()
	{
		if (not genstop_simplegmotherp4_isLoaded) {
			if (genstop_simplegmotherp4_branch != 0) {
				genstop_simplegmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplegmotherp4_branch does not exist!\n");
				exit(1);
			}
			genstop_simplegmotherp4_isLoaded = true;
		}
		return *genstop_simplegmotherp4_;
	}
	const vector<int> &genstop_simplegmothercharge()
	{
		if (not genstop_simplegmothercharge_isLoaded) {
			if (genstop_simplegmothercharge_branch != 0) {
				genstop_simplegmothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplegmothercharge_branch does not exist!\n");
				exit(1);
			}
			genstop_simplegmothercharge_isLoaded = true;
		}
		return *genstop_simplegmothercharge_;
	}
	const vector<int> &genstop_simplegmotherid()
	{
		if (not genstop_simplegmotherid_isLoaded) {
			if (genstop_simplegmotherid_branch != 0) {
				genstop_simplegmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplegmotherid_branch does not exist!\n");
				exit(1);
			}
			genstop_simplegmotherid_isLoaded = true;
		}
		return *genstop_simplegmotherid_;
	}
	const vector<int> &genstop_simplegmotheridx()
	{
		if (not genstop_simplegmotheridx_isLoaded) {
			if (genstop_simplegmotheridx_branch != 0) {
				genstop_simplegmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplegmotheridx_branch does not exist!\n");
				exit(1);
			}
			genstop_simplegmotheridx_isLoaded = true;
		}
		return *genstop_simplegmotheridx_;
	}
	const vector<int> &genstop_simplegmotherstatus()
	{
		if (not genstop_simplegmotherstatus_isLoaded) {
			if (genstop_simplegmotherstatus_branch != 0) {
				genstop_simplegmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genstop_simplegmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genstop_simplegmotherstatus_isLoaded = true;
		}
		return *genstop_simplegmotherstatus_;
	}

  static void progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
};

#ifndef __CINT__
extern CMS3 cms3;
#endif

namespace tas {
	const unsigned int &run();
	const unsigned int &ls();
	const unsigned int &evt();
	const int &nvtxs();
	const int &firstGoodVtxIdx();
	const int &firstVtx_isfake();
	const float &firstVtx_ndof();
	const float &firstVtx_posRho();
	const float &firstVtx_posZ();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &firstVtx_posp4();
	const int &pu_nvtxs();
	const float &pfmet();
	const float &pfmet_phi();
	const float &calomet();
	const float &calomet_phi();
	const float &filt_cscbeamhalo();
	const float &filt_ecallaser();
	const float &filt_ecaltp();
	const float &filt_eebadsc();
	const float &filt_goodvtx();
	const float &filt_hbhenoise();
	const float &filt_hcallaser();
	const float &filt_met();
	const float &filt_trkfail();
	const float &filt_trkPOG();
	const float &filt_trkPOG_tmc();
	const float &filt_trkPOG_tms();
	const float &filt_eff();
	const float &scale1fb();
	const float &xsec();
	const float &kfactor();
	const float &pu_ntrue();
	const int &ngoodleps();
	const int &nvetoleps();
	const bool &is_data();
	const string &dataset();
	const string &filename();
	const string &cms3tag();
	const unsigned int &nEvents();
	const unsigned int &nEvents_goodvtx();
	const unsigned int &nEvents_MET30();
	const unsigned int &nEvents_1goodlep();
	const unsigned int &nEvents_2goodjets();
	const int &genlepsfromtop();
	const float &MT2W();
	const float &MT2W_lep2();
	const float &mindphi_met_j1_j2();
	const float &mt_met_lep();
	const float &mt_met_lep2();
	const float &dR_lep_leadb();
	const float &dR_lep2_leadb();
	const float &hadronic_top_chi2();
	const float &dphi_Wlep();
	const float &MET_over_sqrtHT();
	const float &ak4pfjets_rho();
	const vector<string> &sparms_comment();
	const vector<string> &sparms_names();
	const float &sparms_filterEfficiency();
	const float &sparms_pdfScale();
	const float &sparms_pdfWeight1();
	const float &sparms_pdfWeight2();
	const float &sparms_weight();
	const float &sparms_xsec();
	const vector<float> &sparms_values();
	const int &sparms_subProcessId();
	const float &mass_lsp();
	const float &mass_chargino();
	const float &mass_stop();
	const float &genmet();
	const float &genmet_phi();
	const bool &PassTrackVeto();
	const bool &PassTrackVeto_v2();
	const bool &PassTrackVeto_v3();
	const bool &PassTauVeto();
	const float &EA_all_rho();
	const float &EA_allcalo_rho();
	const float &EA_centralcalo_rho();
	const float &EA_centralchargedpileup_rho();
	const float &EA_centralneutral_rho();
	const float &topness();
	const float &topness_lep2();
	const float &topnessMod();
	const float &topnessMod_lep2();
	const float &MT2_lb_b();
	const float &MT2_lb_b_lep2();
	const float &MT2_lb_b_mass();
	const float &MT2_lb_b_mass_lep2();
	const float &MT2_lb_bqq();
	const float &MT2_lb_bqq_lep2();
	const float &MT2_lb_bqq_mass();
	const float &MT2_lb_bqq_mass_lep2();
	const float &Mlb_closestb();
	const float &Mlb_lead_bdiscr();
	const float &Mlb_closestb_lep2();
	const float &Mlb_lead_bdiscr_lep2();
	const float &Mjjj();
	const float &Mjjj_lep2();
	const int &HLT_SingleEl();
	const int &HLT_SingleMu();
	const int &HLT_MET170();
	const int &HLT_MET120Btag();
	const int &HLT_MET120Mu5();
	const int &HLT_HT350MET120();
	const int &HLT_DiEl();
	const int &HLT_DiMu();
	const int &HLT_Mu8El17();
	const int &HLT_Mu8El23();
	const int &HLT_Mu17El12();
	const int &HLT_Mu23El12();
	const int &HLT_SingleEl27();
	const int &HLT_SingleEl27Tight();
	const int &HLT_SingleElTight();
	const int &HLT_SingleElHT200();
	const int &HLT_SingleMuNoEta();
	const int &HLT_SingleMuNoIso();
	const int &HLT_SingleMuNoIsoNoEta();
	const int &HLT_Mu6HT200MET100();
	const int &HLT_HT350MET100();
	const int &HLT_SingleMu17();
	const int &HLT_SingleMu20();
	const int &HLT_SingleMu24();
	const int &HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight();
	const int &HLT_MET90_MHT90_IDTight();
	const int &HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight();
	const float &pu_weight();
	const float &lep_sf();
	const float &btag_sf();
	const float &HLT_SingleEl_eff();
	const float &HLT_SingleMu_eff();
	const bool &lep1_is_mu();
	const bool &lep1_is_el();
	const int &lep1_charge();
	const int &lep1_pdgid();
	const int &lep1_type();
	const int &lep1_production_type();
	const float &lep1_d0();
	const float &lep1_d0err();
	const float &lep1_dz();
	const float &lep1_dzerr();
	const float &lep1_sigmaIEtaEta_fill5x5();
	const float &lep1_dEtaIn();
	const float &lep1_dPhiIn();
	const float &lep1_hOverE();
	const float &lep1_ooEmooP();
	const int &lep1_expectedMissingInnerHits();
	const bool &lep1_conversionVeto();
	const float &lep1_etaSC();
	const float &lep1_ChiSqr();
	const float &lep1_chiso();
	const float &lep1_nhiso();
	const float &lep1_emiso();
	const float &lep1_deltaBeta();
	const float &lep1_relIso03DB();
	const float &lep1_relIso03EA();
	const float &lep1_relIso04DB();
	const float &lep1_miniRelIsoDB();
	const float &lep1_miniRelIsoEA();
	const float &lep1_MiniIso();
	const int &lep1_mcid();
	const int &lep1_mcstatus();
	const int &lep1_mc3dr();
	const int &lep1_mc3id();
	const int &lep1_mc3idx();
	const int &lep1_mc3motherid();
	const int &lep1_mc3motheridx();
	const bool &lep1_is_eleid_loose();
	const bool &lep1_is_eleid_medium();
	const bool &lep1_is_eleid_tight();
	const bool &lep1_is_phys14_loose_noIso();
	const bool &lep1_is_phys14_medium_noIso();
	const bool &lep1_is_phys14_tight_noIso();
	const float &lep1_eoverpin();
	const bool &lep1_is_muoid_loose();
	const bool &lep1_is_muoid_medium();
	const bool &lep1_is_muoid_tight();
	const float &lep1_ip3d();
	const float &lep1_ip3derr();
	const bool &lep1_is_pfmu();
	const bool &lep1_passMediumID();
	const bool &lep1_passVeto();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4();
	const float &lep1_pt();
	const float &lep1_eta();
	const float &lep1_phi();
	const float &lep1_mass();
	const bool &lep2_is_mu();
	const bool &lep2_is_el();
	const int &lep2_charge();
	const int &lep2_pdgid();
	const int &lep2_type();
	const int &lep2_production_type();
	const float &lep2_d0();
	const float &lep2_d0err();
	const float &lep2_dz();
	const float &lep2_dzerr();
	const float &lep2_sigmaIEtaEta_fill5x5();
	const float &lep2_dEtaIn();
	const float &lep2_dPhiIn();
	const float &lep2_hOverE();
	const float &lep2_ooEmooP();
	const int &lep2_expectedMissingInnerHits();
	const bool &lep2_conversionVeto();
	const float &lep2_etaSC();
	const float &lep2_ChiSqr();
	const float &lep2_chiso();
	const float &lep2_nhiso();
	const float &lep2_emiso();
	const float &lep2_deltaBeta();
	const float &lep2_relIso03DB();
	const float &lep2_relIso03EA();
	const float &lep2_relIso04DB();
	const float &lep2_miniRelIsoDB();
	const float &lep2_miniRelIsoEA();
	const float &lep2_MiniIso();
	const int &lep2_mcid();
	const int &lep2_mcstatus();
	const int &lep2_mc3dr();
	const int &lep2_mc3id();
	const int &lep2_mc3idx();
	const int &lep2_mc3motherid();
	const int &lep2_mc3motheridx();
	const bool &lep2_is_eleid_loose();
	const bool &lep2_is_eleid_medium();
	const bool &lep2_is_eleid_tight();
	const bool &lep2_is_phys14_loose_noIso();
	const bool &lep2_is_phys14_medium_noIso();
	const bool &lep2_is_phys14_tight_noIso();
	const float &lep2_eoverpin();
	const bool &lep2_is_muoid_loose();
	const bool &lep2_is_muoid_medium();
	const bool &lep2_is_muoid_tight();
	const float &lep2_ip3d();
	const float &lep2_ip3derr();
	const bool &lep2_is_pfmu();
	const bool &lep2_passMediumID();
	const bool &lep2_passVeto();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4();
	const float &lep2_pt();
	const float &lep2_eta();
	const float &lep2_phi();
	const float &lep2_mass();
	const int &nGoodGenJets();
	const int &ngoodjets();
	const int &nfailjets();
	const int &ak8GoodPFJets();
	const int &ngoodbtags();
	const float &ak4_HT();
	const float &ak4_htssm();
	const float &ak4_htosm();
	const float &ak4_htratiom();
	const vector<float> &dphi_ak4pfjet_met();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4();
	const vector<float> &ak4pfjets_pt();
	const vector<float> &ak4pfjets_eta();
	const vector<float> &ak4pfjets_phi();
	const vector<float> &ak4pfjets_mass();
	const vector<bool> &ak4pfjets_passMEDbtag();
	const vector<float> &ak4pfjets_qg_disc();
	const vector<float> &ak4pfjets_CSV();
	const vector<float> &ak4pfjets_puid();
	const vector<int> &ak4pfjets_parton_flavor();
	const vector<bool> &ak4pfjets_loose_puid();
	const vector<bool> &ak4pfjets_loose_pfid();
	const vector<bool> &ak4pfjets_medium_pfid();
	const vector<bool> &ak4pfjets_tight_pfid();
	const vector<float> &ak4pfjets_MEDbjet_pt();
	const float &ak4pfjets_leadMEDbjet_pt();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4();
	const vector<float> &ak4pfjets_chf();
	const vector<float> &ak4pfjets_nhf();
	const vector<float> &ak4pfjets_cef();
	const vector<float> &ak4pfjets_nef();
	const vector<float> &ak4pfjets_muf();
	const vector<int> &ak4pfjets_cm();
	const vector<int> &ak4pfjets_nm();
	const vector<int> &ak4pfjets_mc3dr();
	const vector<int> &ak4pfjets_mc3id();
	const vector<int> &ak4pfjets_mc3idx();
	const vector<int> &ak4pfjets_mcmotherid();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep1_p4();
	const float &ak4pfjet_overlep1_CSV();
	const float &ak4pfjet_overlep1_pu_id();
	const float &ak4pfjet_overlep1_chf();
	const float &ak4pfjet_overlep1_nhf();
	const float &ak4pfjet_overlep1_cef();
	const float &ak4pfjet_overlep1_nef();
	const float &ak4pfjet_overlep1_muf();
	const int &ak4pfjet_overlep1_cm();
	const int &ak4pfjet_overlep1_nm();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4();
	const float &ak4pfjet_overlep2_CSV();
	const float &ak4pfjet_overlep2_pu_id();
	const float &ak4pfjet_overlep2_chf();
	const float &ak4pfjet_overlep2_nhf();
	const float &ak4pfjet_overlep2_cef();
	const float &ak4pfjet_overlep2_nef();
	const float &ak4pfjet_overlep2_muf();
	const int &ak4pfjet_overlep2_cm();
	const int &ak4pfjet_overlep2_nm();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8pfjets_p4();
	const vector<float> &ak8pfjets_tau1();
	const vector<float> &ak8pfjets_tau2();
	const vector<float> &ak8pfjets_tau3();
	const vector<float> &ak8pfjets_top_mass();
	const vector<float> &ak8pfjets_pruned_mass();
	const vector<float> &ak8pfjets_trimmed_mass();
	const vector<float> &ak8pfjets_filtered_mass();
	const vector<float> &ak8pfjets_pu_id();
	const vector<int> &ak8pfjets_parton_flavor();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4();
	const vector<TString> &tau_IDnames();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4();
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4();
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4();
	const vector<float> &tau_mass();
	const vector<vector<float> > &tau_ID();
	const vector<float> &tau_passID();
	const vector<float> &tau_charge();
	const int &ngoodtaus();
	const vector<float> &tau_againstMuonTight();
	const vector<float> &tau_againstElectronLoose();
	const vector<bool> &tau_isVetoTau();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isoTracks_p4();
	const vector<int> &isoTracks_charge();
	const vector<float> &isoTracks_absIso();
	const vector<float> &isoTracks_dz();
	const vector<int> &isoTracks_pdgId();
	const vector<int> &isoTracks_selectedidx();
	const int &isoTracks_nselected();
	const vector<bool> &isoTracks_isVetoTrack();
	const vector<bool> &isoTracks_isVetoTrack_v2();
	const vector<bool> &isoTracks_isVetoTrack_v3();
	const vector<bool> &genels_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_p4();
	const vector<float> &genels_charge();
	const vector<float> &genels_iso();
	const vector<float> &genels_mass();
	const vector<int> &genels_id();
	const vector<int> &genels__genpsidx();
	const vector<int> &genels_status();
	const vector<bool> &genels_fromHardProcessBeforeFSR();
	const vector<bool> &genels_fromHardProcessDecayed();
	const vector<bool> &genels_fromHardProcessFinalState();
	const vector<bool> &genels_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genels_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genels_isHardProcess();
	const vector<bool> &genels_isLastCopy();
	const vector<bool> &genels_isLastCopyBeforeFSR();
	const vector<bool> &genels_isMostlyLikePythia6Status3();
	const vector<bool> &genels_isPromptDecayed();
	const vector<bool> &genels_isPromptFinalState();
	const vector<vector<int> > &genels_lepdaughter_id();
	const vector<int> &genels_gentaudecay();
	const int &gen_nfromtels_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_motherp4();
	const vector<float> &genels_mothercharge();
	const vector<int> &genels_motherid();
	const vector<int> &genels_motheridx();
	const vector<int> &genels_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_gmotherp4();
	const vector<int> &genels_gmothercharge();
	const vector<int> &genels_gmotherid();
	const vector<int> &genels_gmotheridx();
	const vector<int> &genels_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplemotherp4();
	const vector<int> &genels_simplemothercharge();
	const vector<int> &genels_simplemotherid();
	const vector<int> &genels_simplemotheridx();
	const vector<int> &genels_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplegmotherp4();
	const vector<int> &genels_simplegmothercharge();
	const vector<int> &genels_simplegmotherid();
	const vector<int> &genels_simplegmotheridx();
	const vector<int> &genels_simplegmotherstatus();
	const vector<bool> &genmus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_p4();
	const vector<float> &genmus_charge();
	const vector<float> &genmus_iso();
	const vector<float> &genmus_mass();
	const vector<int> &genmus_id();
	const vector<int> &genmus__genpsidx();
	const vector<int> &genmus_status();
	const vector<bool> &genmus_fromHardProcessBeforeFSR();
	const vector<bool> &genmus_fromHardProcessDecayed();
	const vector<bool> &genmus_fromHardProcessFinalState();
	const vector<bool> &genmus_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genmus_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genmus_isHardProcess();
	const vector<bool> &genmus_isLastCopy();
	const vector<bool> &genmus_isLastCopyBeforeFSR();
	const vector<bool> &genmus_isMostlyLikePythia6Status3();
	const vector<bool> &genmus_isPromptDecayed();
	const vector<bool> &genmus_isPromptFinalState();
	const vector<vector<int> > &genmus_lepdaughter_id();
	const vector<int> &genmus_gentaudecay();
	const int &gen_nfromtmus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_motherp4();
	const vector<float> &genmus_mothercharge();
	const vector<int> &genmus_motherid();
	const vector<int> &genmus_motheridx();
	const vector<int> &genmus_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_gmotherp4();
	const vector<int> &genmus_gmothercharge();
	const vector<int> &genmus_gmotherid();
	const vector<int> &genmus_gmotheridx();
	const vector<int> &genmus_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplemotherp4();
	const vector<int> &genmus_simplemothercharge();
	const vector<int> &genmus_simplemotherid();
	const vector<int> &genmus_simplemotheridx();
	const vector<int> &genmus_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplegmotherp4();
	const vector<int> &genmus_simplegmothercharge();
	const vector<int> &genmus_simplegmotherid();
	const vector<int> &genmus_simplegmotheridx();
	const vector<int> &genmus_simplegmotherstatus();
	const vector<bool> &gentaus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_p4();
	const vector<float> &gentaus_charge();
	const vector<float> &gentaus_iso();
	const vector<float> &gentaus_mass();
	const vector<int> &gentaus_id();
	const vector<int> &gentaus__genpsidx();
	const vector<int> &gentaus_status();
	const vector<bool> &gentaus_fromHardProcessBeforeFSR();
	const vector<bool> &gentaus_fromHardProcessDecayed();
	const vector<bool> &gentaus_fromHardProcessFinalState();
	const vector<bool> &gentaus_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gentaus_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gentaus_isHardProcess();
	const vector<bool> &gentaus_isLastCopy();
	const vector<bool> &gentaus_isLastCopyBeforeFSR();
	const vector<bool> &gentaus_isMostlyLikePythia6Status3();
	const vector<bool> &gentaus_isPromptDecayed();
	const vector<bool> &gentaus_isPromptFinalState();
	const vector<vector<int> > &gentaus_lepdaughter_id();
	const vector<int> &gentaus_gentaudecay();
	const int &gen_nfromttaus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_motherp4();
	const vector<float> &gentaus_mothercharge();
	const vector<int> &gentaus_motherid();
	const vector<int> &gentaus_motheridx();
	const vector<int> &gentaus_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_gmotherp4();
	const vector<int> &gentaus_gmothercharge();
	const vector<int> &gentaus_gmotherid();
	const vector<int> &gentaus_gmotheridx();
	const vector<int> &gentaus_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplemotherp4();
	const vector<int> &gentaus_simplemothercharge();
	const vector<int> &gentaus_simplemotherid();
	const vector<int> &gentaus_simplemotheridx();
	const vector<int> &gentaus_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplegmotherp4();
	const vector<int> &gentaus_simplegmothercharge();
	const vector<int> &gentaus_simplegmotherid();
	const vector<int> &gentaus_simplegmotheridx();
	const vector<int> &gentaus_simplegmotherstatus();
	const vector<bool> &gennuels_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_p4();
	const vector<float> &gennuels_charge();
	const vector<float> &gennuels_iso();
	const vector<float> &gennuels_mass();
	const vector<int> &gennuels_id();
	const vector<int> &gennuels__genpsidx();
	const vector<int> &gennuels_status();
	const vector<bool> &gennuels_fromHardProcessBeforeFSR();
	const vector<bool> &gennuels_fromHardProcessDecayed();
	const vector<bool> &gennuels_fromHardProcessFinalState();
	const vector<bool> &gennuels_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gennuels_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gennuels_isHardProcess();
	const vector<bool> &gennuels_isLastCopy();
	const vector<bool> &gennuels_isLastCopyBeforeFSR();
	const vector<bool> &gennuels_isMostlyLikePythia6Status3();
	const vector<bool> &gennuels_isPromptDecayed();
	const vector<bool> &gennuels_isPromptFinalState();
	const vector<vector<int> > &gennuels_lepdaughter_id();
	const vector<int> &gennuels_gentaudecay();
	const int &gen_nfromtnuels_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_motherp4();
	const vector<float> &gennuels_mothercharge();
	const vector<int> &gennuels_motherid();
	const vector<int> &gennuels_motheridx();
	const vector<int> &gennuels_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_gmotherp4();
	const vector<int> &gennuels_gmothercharge();
	const vector<int> &gennuels_gmotherid();
	const vector<int> &gennuels_gmotheridx();
	const vector<int> &gennuels_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplemotherp4();
	const vector<int> &gennuels_simplemothercharge();
	const vector<int> &gennuels_simplemotherid();
	const vector<int> &gennuels_simplemotheridx();
	const vector<int> &gennuels_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplegmotherp4();
	const vector<int> &gennuels_simplegmothercharge();
	const vector<int> &gennuels_simplegmotherid();
	const vector<int> &gennuels_simplegmotheridx();
	const vector<int> &gennuels_simplegmotherstatus();
	const vector<bool> &gennumus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_p4();
	const vector<float> &gennumus_charge();
	const vector<float> &gennumus_iso();
	const vector<float> &gennumus_mass();
	const vector<int> &gennumus_id();
	const vector<int> &gennumus__genpsidx();
	const vector<int> &gennumus_status();
	const vector<bool> &gennumus_fromHardProcessBeforeFSR();
	const vector<bool> &gennumus_fromHardProcessDecayed();
	const vector<bool> &gennumus_fromHardProcessFinalState();
	const vector<bool> &gennumus_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gennumus_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gennumus_isHardProcess();
	const vector<bool> &gennumus_isLastCopy();
	const vector<bool> &gennumus_isLastCopyBeforeFSR();
	const vector<bool> &gennumus_isMostlyLikePythia6Status3();
	const vector<bool> &gennumus_isPromptDecayed();
	const vector<bool> &gennumus_isPromptFinalState();
	const vector<vector<int> > &gennumus_lepdaughter_id();
	const vector<int> &gennumus_gentaudecay();
	const int &gen_nfromtnumus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_motherp4();
	const vector<float> &gennumus_mothercharge();
	const vector<int> &gennumus_motherid();
	const vector<int> &gennumus_motheridx();
	const vector<int> &gennumus_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_gmotherp4();
	const vector<int> &gennumus_gmothercharge();
	const vector<int> &gennumus_gmotherid();
	const vector<int> &gennumus_gmotheridx();
	const vector<int> &gennumus_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplemotherp4();
	const vector<int> &gennumus_simplemothercharge();
	const vector<int> &gennumus_simplemotherid();
	const vector<int> &gennumus_simplemotheridx();
	const vector<int> &gennumus_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplegmotherp4();
	const vector<int> &gennumus_simplegmothercharge();
	const vector<int> &gennumus_simplegmotherid();
	const vector<int> &gennumus_simplegmotheridx();
	const vector<int> &gennumus_simplegmotherstatus();
	const vector<bool> &gennutaus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_p4();
	const vector<float> &gennutaus_charge();
	const vector<float> &gennutaus_iso();
	const vector<float> &gennutaus_mass();
	const vector<int> &gennutaus_id();
	const vector<int> &gennutaus__genpsidx();
	const vector<int> &gennutaus_status();
	const vector<bool> &gennutaus_fromHardProcessBeforeFSR();
	const vector<bool> &gennutaus_fromHardProcessDecayed();
	const vector<bool> &gennutaus_fromHardProcessFinalState();
	const vector<bool> &gennutaus_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gennutaus_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gennutaus_isHardProcess();
	const vector<bool> &gennutaus_isLastCopy();
	const vector<bool> &gennutaus_isLastCopyBeforeFSR();
	const vector<bool> &gennutaus_isMostlyLikePythia6Status3();
	const vector<bool> &gennutaus_isPromptDecayed();
	const vector<bool> &gennutaus_isPromptFinalState();
	const vector<vector<int> > &gennutaus_lepdaughter_id();
	const vector<int> &gennutaus_gentaudecay();
	const int &gen_nfromtnutaus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_motherp4();
	const vector<float> &gennutaus_mothercharge();
	const vector<int> &gennutaus_motherid();
	const vector<int> &gennutaus_motheridx();
	const vector<int> &gennutaus_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_gmotherp4();
	const vector<int> &gennutaus_gmothercharge();
	const vector<int> &gennutaus_gmotherid();
	const vector<int> &gennutaus_gmotheridx();
	const vector<int> &gennutaus_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplemotherp4();
	const vector<int> &gennutaus_simplemothercharge();
	const vector<int> &gennutaus_simplemotherid();
	const vector<int> &gennutaus_simplemotheridx();
	const vector<int> &gennutaus_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplegmotherp4();
	const vector<int> &gennutaus_simplegmothercharge();
	const vector<int> &gennutaus_simplegmotherid();
	const vector<int> &gennutaus_simplegmotheridx();
	const vector<int> &gennutaus_simplegmotherstatus();
	const vector<bool> &gents_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4();
	const vector<float> &gents_charge();
	const vector<float> &gents_iso();
	const vector<float> &gents_mass();
	const vector<int> &gents_id();
	const vector<int> &gents__genpsidx();
	const vector<int> &gents_status();
	const vector<bool> &gents_fromHardProcessBeforeFSR();
	const vector<bool> &gents_fromHardProcessDecayed();
	const vector<bool> &gents_fromHardProcessFinalState();
	const vector<bool> &gents_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gents_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gents_isHardProcess();
	const vector<bool> &gents_isLastCopy();
	const vector<bool> &gents_isLastCopyBeforeFSR();
	const vector<bool> &gents_isMostlyLikePythia6Status3();
	const vector<bool> &gents_isPromptDecayed();
	const vector<bool> &gents_isPromptFinalState();
	const vector<vector<int> > &gents_lepdaughter_id();
	const vector<int> &gents_gentaudecay();
	const int &gen_nfromtts_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4();
	const vector<float> &gents_mothercharge();
	const vector<int> &gents_motherid();
	const vector<int> &gents_motheridx();
	const vector<int> &gents_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_gmotherp4();
	const vector<int> &gents_gmothercharge();
	const vector<int> &gents_gmotherid();
	const vector<int> &gents_gmotheridx();
	const vector<int> &gents_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplemotherp4();
	const vector<int> &gents_simplemothercharge();
	const vector<int> &gents_simplemotherid();
	const vector<int> &gents_simplemotheridx();
	const vector<int> &gents_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplegmotherp4();
	const vector<int> &gents_simplegmothercharge();
	const vector<int> &gents_simplegmotherid();
	const vector<int> &gents_simplegmotheridx();
	const vector<int> &gents_simplegmotherstatus();
	const vector<bool> &genbs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_p4();
	const vector<float> &genbs_charge();
	const vector<float> &genbs_iso();
	const vector<float> &genbs_mass();
	const vector<int> &genbs_id();
	const vector<int> &genbs__genpsidx();
	const vector<int> &genbs_status();
	const vector<bool> &genbs_fromHardProcessBeforeFSR();
	const vector<bool> &genbs_fromHardProcessDecayed();
	const vector<bool> &genbs_fromHardProcessFinalState();
	const vector<bool> &genbs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genbs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genbs_isHardProcess();
	const vector<bool> &genbs_isLastCopy();
	const vector<bool> &genbs_isLastCopyBeforeFSR();
	const vector<bool> &genbs_isMostlyLikePythia6Status3();
	const vector<bool> &genbs_isPromptDecayed();
	const vector<bool> &genbs_isPromptFinalState();
	const vector<vector<int> > &genbs_lepdaughter_id();
	const vector<int> &genbs_gentaudecay();
	const int &gen_nfromtbs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_motherp4();
	const vector<float> &genbs_mothercharge();
	const vector<int> &genbs_motherid();
	const vector<int> &genbs_motheridx();
	const vector<int> &genbs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_gmotherp4();
	const vector<int> &genbs_gmothercharge();
	const vector<int> &genbs_gmotherid();
	const vector<int> &genbs_gmotheridx();
	const vector<int> &genbs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplemotherp4();
	const vector<int> &genbs_simplemothercharge();
	const vector<int> &genbs_simplemotherid();
	const vector<int> &genbs_simplemotheridx();
	const vector<int> &genbs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplegmotherp4();
	const vector<int> &genbs_simplegmothercharge();
	const vector<int> &genbs_simplegmotherid();
	const vector<int> &genbs_simplegmotheridx();
	const vector<int> &genbs_simplegmotherstatus();
	const vector<bool> &gencs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_p4();
	const vector<float> &gencs_charge();
	const vector<float> &gencs_iso();
	const vector<float> &gencs_mass();
	const vector<int> &gencs_id();
	const vector<int> &gencs__genpsidx();
	const vector<int> &gencs_status();
	const vector<bool> &gencs_fromHardProcessBeforeFSR();
	const vector<bool> &gencs_fromHardProcessDecayed();
	const vector<bool> &gencs_fromHardProcessFinalState();
	const vector<bool> &gencs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &gencs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &gencs_isHardProcess();
	const vector<bool> &gencs_isLastCopy();
	const vector<bool> &gencs_isLastCopyBeforeFSR();
	const vector<bool> &gencs_isMostlyLikePythia6Status3();
	const vector<bool> &gencs_isPromptDecayed();
	const vector<bool> &gencs_isPromptFinalState();
	const vector<vector<int> > &gencs_lepdaughter_id();
	const vector<int> &gencs_gentaudecay();
	const int &gen_nfromtcs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_motherp4();
	const vector<float> &gencs_mothercharge();
	const vector<int> &gencs_motherid();
	const vector<int> &gencs_motheridx();
	const vector<int> &gencs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_gmotherp4();
	const vector<int> &gencs_gmothercharge();
	const vector<int> &gencs_gmotherid();
	const vector<int> &gencs_gmotheridx();
	const vector<int> &gencs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplemotherp4();
	const vector<int> &gencs_simplemothercharge();
	const vector<int> &gencs_simplemotherid();
	const vector<int> &gencs_simplemotheridx();
	const vector<int> &gencs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplegmotherp4();
	const vector<int> &gencs_simplegmothercharge();
	const vector<int> &gencs_simplegmotherid();
	const vector<int> &gencs_simplegmotheridx();
	const vector<int> &gencs_simplegmotherstatus();
	const vector<bool> &genqs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4();
	const vector<float> &genqs_charge();
	const vector<float> &genqs_iso();
	const vector<float> &genqs_mass();
	const vector<int> &genqs_id();
	const vector<int> &genqs__genpsidx();
	const vector<int> &genqs_status();
	const vector<bool> &genqs_fromHardProcessBeforeFSR();
	const vector<bool> &genqs_fromHardProcessDecayed();
	const vector<bool> &genqs_fromHardProcessFinalState();
	const vector<bool> &genqs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genqs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genqs_isHardProcess();
	const vector<bool> &genqs_isLastCopy();
	const vector<bool> &genqs_isLastCopyBeforeFSR();
	const vector<bool> &genqs_isMostlyLikePythia6Status3();
	const vector<bool> &genqs_isPromptDecayed();
	const vector<bool> &genqs_isPromptFinalState();
	const vector<vector<int> > &genqs_lepdaughter_id();
	const vector<int> &genqs_gentaudecay();
	const int &gen_nfromtqs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4();
	const vector<float> &genqs_mothercharge();
	const vector<int> &genqs_motherid();
	const vector<int> &genqs_motheridx();
	const vector<int> &genqs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4();
	const vector<int> &genqs_gmothercharge();
	const vector<int> &genqs_gmotherid();
	const vector<int> &genqs_gmotheridx();
	const vector<int> &genqs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplemotherp4();
	const vector<int> &genqs_simplemothercharge();
	const vector<int> &genqs_simplemotherid();
	const vector<int> &genqs_simplemotheridx();
	const vector<int> &genqs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplegmotherp4();
	const vector<int> &genqs_simplegmothercharge();
	const vector<int> &genqs_simplegmotherid();
	const vector<int> &genqs_simplegmotheridx();
	const vector<int> &genqs_simplegmotherstatus();
	const vector<bool> &genglus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_p4();
	const vector<float> &genglus_charge();
	const vector<float> &genglus_iso();
	const vector<float> &genglus_mass();
	const vector<int> &genglus_id();
	const vector<int> &genglus__genpsidx();
	const vector<int> &genglus_status();
	const vector<bool> &genglus_fromHardProcessBeforeFSR();
	const vector<bool> &genglus_fromHardProcessDecayed();
	const vector<bool> &genglus_fromHardProcessFinalState();
	const vector<bool> &genglus_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genglus_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genglus_isHardProcess();
	const vector<bool> &genglus_isLastCopy();
	const vector<bool> &genglus_isLastCopyBeforeFSR();
	const vector<bool> &genglus_isMostlyLikePythia6Status3();
	const vector<bool> &genglus_isPromptDecayed();
	const vector<bool> &genglus_isPromptFinalState();
	const vector<vector<int> > &genglus_lepdaughter_id();
	const vector<int> &genglus_gentaudecay();
	const int &gen_nfromtglus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_motherp4();
	const vector<float> &genglus_mothercharge();
	const vector<int> &genglus_motherid();
	const vector<int> &genglus_motheridx();
	const vector<int> &genglus_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_gmotherp4();
	const vector<int> &genglus_gmothercharge();
	const vector<int> &genglus_gmotherid();
	const vector<int> &genglus_gmotheridx();
	const vector<int> &genglus_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplemotherp4();
	const vector<int> &genglus_simplemothercharge();
	const vector<int> &genglus_simplemotherid();
	const vector<int> &genglus_simplemotheridx();
	const vector<int> &genglus_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplegmotherp4();
	const vector<int> &genglus_simplegmothercharge();
	const vector<int> &genglus_simplegmotherid();
	const vector<int> &genglus_simplegmotheridx();
	const vector<int> &genglus_simplegmotherstatus();
	const vector<bool> &genws_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_p4();
	const vector<float> &genws_charge();
	const vector<float> &genws_iso();
	const vector<float> &genws_mass();
	const vector<int> &genws_id();
	const vector<int> &genws__genpsidx();
	const vector<int> &genws_status();
	const vector<bool> &genws_fromHardProcessBeforeFSR();
	const vector<bool> &genws_fromHardProcessDecayed();
	const vector<bool> &genws_fromHardProcessFinalState();
	const vector<bool> &genws_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genws_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genws_isHardProcess();
	const vector<bool> &genws_isLastCopy();
	const vector<bool> &genws_isLastCopyBeforeFSR();
	const vector<bool> &genws_isMostlyLikePythia6Status3();
	const vector<bool> &genws_isPromptDecayed();
	const vector<bool> &genws_isPromptFinalState();
	const vector<vector<int> > &genws_lepdaughter_id();
	const vector<int> &genws_gentaudecay();
	const int &gen_nfromtws_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_motherp4();
	const vector<float> &genws_mothercharge();
	const vector<int> &genws_motherid();
	const vector<int> &genws_motheridx();
	const vector<int> &genws_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_gmotherp4();
	const vector<int> &genws_gmothercharge();
	const vector<int> &genws_gmotherid();
	const vector<int> &genws_gmotheridx();
	const vector<int> &genws_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplemotherp4();
	const vector<int> &genws_simplemothercharge();
	const vector<int> &genws_simplemotherid();
	const vector<int> &genws_simplemotheridx();
	const vector<int> &genws_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplegmotherp4();
	const vector<int> &genws_simplegmothercharge();
	const vector<int> &genws_simplegmotherid();
	const vector<int> &genws_simplegmotheridx();
	const vector<int> &genws_simplegmotherstatus();
	const vector<bool> &genzs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_p4();
	const vector<float> &genzs_charge();
	const vector<float> &genzs_iso();
	const vector<float> &genzs_mass();
	const vector<int> &genzs_id();
	const vector<int> &genzs__genpsidx();
	const vector<int> &genzs_status();
	const vector<bool> &genzs_fromHardProcessBeforeFSR();
	const vector<bool> &genzs_fromHardProcessDecayed();
	const vector<bool> &genzs_fromHardProcessFinalState();
	const vector<bool> &genzs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genzs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genzs_isHardProcess();
	const vector<bool> &genzs_isLastCopy();
	const vector<bool> &genzs_isLastCopyBeforeFSR();
	const vector<bool> &genzs_isMostlyLikePythia6Status3();
	const vector<bool> &genzs_isPromptDecayed();
	const vector<bool> &genzs_isPromptFinalState();
	const vector<vector<int> > &genzs_lepdaughter_id();
	const vector<int> &genzs_gentaudecay();
	const int &gen_nfromtzs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_motherp4();
	const vector<float> &genzs_mothercharge();
	const vector<int> &genzs_motherid();
	const vector<int> &genzs_motheridx();
	const vector<int> &genzs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_gmotherp4();
	const vector<int> &genzs_gmothercharge();
	const vector<int> &genzs_gmotherid();
	const vector<int> &genzs_gmotheridx();
	const vector<int> &genzs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplemotherp4();
	const vector<int> &genzs_simplemothercharge();
	const vector<int> &genzs_simplemotherid();
	const vector<int> &genzs_simplemotheridx();
	const vector<int> &genzs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplegmotherp4();
	const vector<int> &genzs_simplegmothercharge();
	const vector<int> &genzs_simplegmotherid();
	const vector<int> &genzs_simplegmotheridx();
	const vector<int> &genzs_simplegmotherstatus();
	const vector<bool> &genphs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_p4();
	const vector<float> &genphs_charge();
	const vector<float> &genphs_iso();
	const vector<float> &genphs_mass();
	const vector<int> &genphs_id();
	const vector<int> &genphs__genpsidx();
	const vector<int> &genphs_status();
	const vector<bool> &genphs_fromHardProcessBeforeFSR();
	const vector<bool> &genphs_fromHardProcessDecayed();
	const vector<bool> &genphs_fromHardProcessFinalState();
	const vector<bool> &genphs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genphs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genphs_isHardProcess();
	const vector<bool> &genphs_isLastCopy();
	const vector<bool> &genphs_isLastCopyBeforeFSR();
	const vector<bool> &genphs_isMostlyLikePythia6Status3();
	const vector<bool> &genphs_isPromptDecayed();
	const vector<bool> &genphs_isPromptFinalState();
	const vector<vector<int> > &genphs_lepdaughter_id();
	const vector<int> &genphs_gentaudecay();
	const int &gen_nfromtphs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_motherp4();
	const vector<float> &genphs_mothercharge();
	const vector<int> &genphs_motherid();
	const vector<int> &genphs_motheridx();
	const vector<int> &genphs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_gmotherp4();
	const vector<int> &genphs_gmothercharge();
	const vector<int> &genphs_gmotherid();
	const vector<int> &genphs_gmotheridx();
	const vector<int> &genphs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplemotherp4();
	const vector<int> &genphs_simplemothercharge();
	const vector<int> &genphs_simplemotherid();
	const vector<int> &genphs_simplemotheridx();
	const vector<int> &genphs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplegmotherp4();
	const vector<int> &genphs_simplegmothercharge();
	const vector<int> &genphs_simplegmotherid();
	const vector<int> &genphs_simplegmotheridx();
	const vector<int> &genphs_simplegmotherstatus();
	const vector<bool> &genhs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_p4();
	const vector<float> &genhs_charge();
	const vector<float> &genhs_iso();
	const vector<float> &genhs_mass();
	const vector<int> &genhs_id();
	const vector<int> &genhs__genpsidx();
	const vector<int> &genhs_status();
	const vector<bool> &genhs_fromHardProcessBeforeFSR();
	const vector<bool> &genhs_fromHardProcessDecayed();
	const vector<bool> &genhs_fromHardProcessFinalState();
	const vector<bool> &genhs_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genhs_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genhs_isHardProcess();
	const vector<bool> &genhs_isLastCopy();
	const vector<bool> &genhs_isLastCopyBeforeFSR();
	const vector<bool> &genhs_isMostlyLikePythia6Status3();
	const vector<bool> &genhs_isPromptDecayed();
	const vector<bool> &genhs_isPromptFinalState();
	const vector<vector<int> > &genhs_lepdaughter_id();
	const vector<int> &genhs_gentaudecay();
	const int &gen_nfromths_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_motherp4();
	const vector<float> &genhs_mothercharge();
	const vector<int> &genhs_motherid();
	const vector<int> &genhs_motheridx();
	const vector<int> &genhs_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_gmotherp4();
	const vector<int> &genhs_gmothercharge();
	const vector<int> &genhs_gmotherid();
	const vector<int> &genhs_gmotheridx();
	const vector<int> &genhs_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplemotherp4();
	const vector<int> &genhs_simplemothercharge();
	const vector<int> &genhs_simplemotherid();
	const vector<int> &genhs_simplemotheridx();
	const vector<int> &genhs_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplegmotherp4();
	const vector<int> &genhs_simplegmothercharge();
	const vector<int> &genhs_simplegmotherid();
	const vector<int> &genhs_simplegmotheridx();
	const vector<int> &genhs_simplegmotherstatus();
	const vector<bool> &genlsp_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_p4();
	const vector<float> &genlsp_charge();
	const vector<float> &genlsp_iso();
	const vector<float> &genlsp_mass();
	const vector<int> &genlsp_id();
	const vector<int> &genlsp__genpsidx();
	const vector<int> &genlsp_status();
	const vector<bool> &genlsp_fromHardProcessBeforeFSR();
	const vector<bool> &genlsp_fromHardProcessDecayed();
	const vector<bool> &genlsp_fromHardProcessFinalState();
	const vector<bool> &genlsp_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genlsp_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genlsp_isHardProcess();
	const vector<bool> &genlsp_isLastCopy();
	const vector<bool> &genlsp_isLastCopyBeforeFSR();
	const vector<bool> &genlsp_isMostlyLikePythia6Status3();
	const vector<bool> &genlsp_isPromptDecayed();
	const vector<bool> &genlsp_isPromptFinalState();
	const vector<vector<int> > &genlsp_lepdaughter_id();
	const vector<int> &genlsp_gentaudecay();
	const int &gen_nfromtlsp_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_motherp4();
	const vector<float> &genlsp_mothercharge();
	const vector<int> &genlsp_motherid();
	const vector<int> &genlsp_motheridx();
	const vector<int> &genlsp_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_gmotherp4();
	const vector<int> &genlsp_gmothercharge();
	const vector<int> &genlsp_gmotherid();
	const vector<int> &genlsp_gmotheridx();
	const vector<int> &genlsp_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplemotherp4();
	const vector<int> &genlsp_simplemothercharge();
	const vector<int> &genlsp_simplemotherid();
	const vector<int> &genlsp_simplemotheridx();
	const vector<int> &genlsp_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplegmotherp4();
	const vector<int> &genlsp_simplegmothercharge();
	const vector<int> &genlsp_simplegmotherid();
	const vector<int> &genlsp_simplegmotheridx();
	const vector<int> &genlsp_simplegmotherstatus();
	const vector<bool> &genstop_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_p4();
	const vector<float> &genstop_charge();
	const vector<float> &genstop_iso();
	const vector<float> &genstop_mass();
	const vector<int> &genstop_id();
	const vector<int> &genstop__genpsidx();
	const vector<int> &genstop_status();
	const vector<bool> &genstop_fromHardProcessBeforeFSR();
	const vector<bool> &genstop_fromHardProcessDecayed();
	const vector<bool> &genstop_fromHardProcessFinalState();
	const vector<bool> &genstop_isDirectHardProcessTauDecayProductFinalState();
	const vector<bool> &genstop_isDirectPromptTauDecayProductFinalState();
	const vector<bool> &genstop_isHardProcess();
	const vector<bool> &genstop_isLastCopy();
	const vector<bool> &genstop_isLastCopyBeforeFSR();
	const vector<bool> &genstop_isMostlyLikePythia6Status3();
	const vector<bool> &genstop_isPromptDecayed();
	const vector<bool> &genstop_isPromptFinalState();
	const vector<vector<int> > &genstop_lepdaughter_id();
	const vector<int> &genstop_gentaudecay();
	const int &gen_nfromtstop_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_motherp4();
	const vector<float> &genstop_mothercharge();
	const vector<int> &genstop_motherid();
	const vector<int> &genstop_motheridx();
	const vector<int> &genstop_motherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_gmotherp4();
	const vector<int> &genstop_gmothercharge();
	const vector<int> &genstop_gmotherid();
	const vector<int> &genstop_gmotheridx();
	const vector<int> &genstop_gmotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplemotherp4();
	const vector<int> &genstop_simplemothercharge();
	const vector<int> &genstop_simplemotherid();
	const vector<int> &genstop_simplemotheridx();
	const vector<int> &genstop_simplemotherstatus();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplegmotherp4();
	const vector<int> &genstop_simplegmothercharge();
	const vector<int> &genstop_simplegmotherid();
	const vector<int> &genstop_simplegmotheridx();
	const vector<int> &genstop_simplegmotherstatus();
}
#endif
