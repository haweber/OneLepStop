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
	int	pu_nvtxs_;
	TBranch *pu_nvtxs_branch;
	bool pu_nvtxs_isLoaded;
	float	pfmet_;
	TBranch *pfmet_branch;
	bool pfmet_isLoaded;
	float	pfmet_phi_;
	TBranch *pfmet_phi_branch;
	bool pfmet_phi_isLoaded;
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
	float	Topness_lep2_;
	TBranch *Topness_lep2_branch;
	bool Topness_lep2_isLoaded;
	float	TopnessMod_lep1_;
	TBranch *TopnessMod_lep1_branch;
	bool TopnessMod_lep1_isLoaded;
	float	TopnessMod_lep2_;
	TBranch *TopnessMod_lep2_branch;
	bool TopnessMod_lep2_isLoaded;
	float	MT2_lb_b_lep1_;
	TBranch *MT2_lb_b_lep1_branch;
	bool MT2_lb_b_lep1_isLoaded;
	float	MT2_lb_b_lep2_;
	TBranch *MT2_lb_b_lep2_branch;
	bool MT2_lb_b_lep2_isLoaded;
	float	MT2_lb_b_mass_lep1_;
	TBranch *MT2_lb_b_mass_lep1_branch;
	bool MT2_lb_b_mass_lep1_isLoaded;
	float	MT2_lb_b_mass_lep2_;
	TBranch *MT2_lb_b_mass_lep2_branch;
	bool MT2_lb_b_mass_lep2_isLoaded;
	float	MT2_lb_bqq_lep1_;
	TBranch *MT2_lb_bqq_lep1_branch;
	bool MT2_lb_bqq_lep1_isLoaded;
	float	MT2_lb_bqq_lep2_;
	TBranch *MT2_lb_bqq_lep2_branch;
	bool MT2_lb_bqq_lep2_isLoaded;
	float	MT2_lb_bqq_mass_lep1_;
	TBranch *MT2_lb_bqq_mass_lep1_branch;
	bool MT2_lb_bqq_mass_lep1_isLoaded;
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
	int	HLT_ht350met120_;
	TBranch *HLT_ht350met120_branch;
	bool HLT_ht350met120_isLoaded;
	int	HLT_MET120Btag_;
	TBranch *HLT_MET120Btag_branch;
	bool HLT_MET120Btag_isLoaded;
	int	HLT_MET120Mu5_;
	TBranch *HLT_MET120Mu5_branch;
	bool HLT_MET120Mu5_isLoaded;
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
	vector<bool> *genleptau_els_isfromt_;
	TBranch *genleptau_els_isfromt_branch;
	bool genleptau_els_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genleptau_els_p4_;
	TBranch *genleptau_els_p4_branch;
	bool genleptau_els_p4_isLoaded;
	vector<float> *genleptau_els_charge_;
	TBranch *genleptau_els_charge_branch;
	bool genleptau_els_charge_isLoaded;
	vector<float> *genleptau_els_iso_;
	TBranch *genleptau_els_iso_branch;
	bool genleptau_els_iso_isLoaded;
	vector<float> *genleptau_els_mass_;
	TBranch *genleptau_els_mass_branch;
	bool genleptau_els_mass_isLoaded;
	vector<int> *genleptau_els_id_;
	TBranch *genleptau_els_id_branch;
	bool genleptau_els_id_isLoaded;
	vector<int> *genleptau_els__genpsidx_;
	TBranch *genleptau_els__genpsidx_branch;
	bool genleptau_els__genpsidx_isLoaded;
	vector<int> *genleptau_els_status_;
	TBranch *genleptau_els_status_branch;
	bool genleptau_els_status_isLoaded;
	vector<vector<int> > *genleptau_els_lepdaughter_id_;
	TBranch *genleptau_els_lepdaughter_id_branch;
	bool genleptau_els_lepdaughter_id_isLoaded;
	vector<int> *genleptau_els_gentaudecay_;
	TBranch *genleptau_els_gentaudecay_branch;
	bool genleptau_els_gentaudecay_isLoaded;
	int	gen_nfromtleptau_els__;
	TBranch *gen_nfromtleptau_els__branch;
	bool gen_nfromtleptau_els__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genleptau_els_motherp4_;
	TBranch *genleptau_els_motherp4_branch;
	bool genleptau_els_motherp4_isLoaded;
	vector<float> *genleptau_els_mothercharge_;
	TBranch *genleptau_els_mothercharge_branch;
	bool genleptau_els_mothercharge_isLoaded;
	vector<int> *genleptau_els_motherid_;
	TBranch *genleptau_els_motherid_branch;
	bool genleptau_els_motherid_isLoaded;
	vector<int> *genleptau_els_motheridx_;
	TBranch *genleptau_els_motheridx_branch;
	bool genleptau_els_motheridx_isLoaded;
	vector<int> *genleptau_els_motherstatus_;
	TBranch *genleptau_els_motherstatus_branch;
	bool genleptau_els_motherstatus_isLoaded;
	vector<bool> *genleptau_mus_isfromt_;
	TBranch *genleptau_mus_isfromt_branch;
	bool genleptau_mus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genleptau_mus_p4_;
	TBranch *genleptau_mus_p4_branch;
	bool genleptau_mus_p4_isLoaded;
	vector<float> *genleptau_mus_charge_;
	TBranch *genleptau_mus_charge_branch;
	bool genleptau_mus_charge_isLoaded;
	vector<float> *genleptau_mus_iso_;
	TBranch *genleptau_mus_iso_branch;
	bool genleptau_mus_iso_isLoaded;
	vector<float> *genleptau_mus_mass_;
	TBranch *genleptau_mus_mass_branch;
	bool genleptau_mus_mass_isLoaded;
	vector<int> *genleptau_mus_id_;
	TBranch *genleptau_mus_id_branch;
	bool genleptau_mus_id_isLoaded;
	vector<int> *genleptau_mus__genpsidx_;
	TBranch *genleptau_mus__genpsidx_branch;
	bool genleptau_mus__genpsidx_isLoaded;
	vector<int> *genleptau_mus_status_;
	TBranch *genleptau_mus_status_branch;
	bool genleptau_mus_status_isLoaded;
	vector<vector<int> > *genleptau_mus_lepdaughter_id_;
	TBranch *genleptau_mus_lepdaughter_id_branch;
	bool genleptau_mus_lepdaughter_id_isLoaded;
	vector<int> *genleptau_mus_gentaudecay_;
	TBranch *genleptau_mus_gentaudecay_branch;
	bool genleptau_mus_gentaudecay_isLoaded;
	int	gen_nfromtleptau_mus__;
	TBranch *gen_nfromtleptau_mus__branch;
	bool gen_nfromtleptau_mus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genleptau_mus_motherp4_;
	TBranch *genleptau_mus_motherp4_branch;
	bool genleptau_mus_motherp4_isLoaded;
	vector<float> *genleptau_mus_mothercharge_;
	TBranch *genleptau_mus_mothercharge_branch;
	bool genleptau_mus_mothercharge_isLoaded;
	vector<int> *genleptau_mus_motherid_;
	TBranch *genleptau_mus_motherid_branch;
	bool genleptau_mus_motherid_isLoaded;
	vector<int> *genleptau_mus_motheridx_;
	TBranch *genleptau_mus_motheridx_branch;
	bool genleptau_mus_motheridx_isLoaded;
	vector<int> *genleptau_mus_motherstatus_;
	TBranch *genleptau_mus_motherstatus_branch;
	bool genleptau_mus_motherstatus_isLoaded;
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
	vector<bool> *gennus_isfromt_;
	TBranch *gennus_isfromt_branch;
	bool gennus_isfromt_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennus_p4_;
	TBranch *gennus_p4_branch;
	bool gennus_p4_isLoaded;
	vector<float> *gennus_charge_;
	TBranch *gennus_charge_branch;
	bool gennus_charge_isLoaded;
	vector<float> *gennus_iso_;
	TBranch *gennus_iso_branch;
	bool gennus_iso_isLoaded;
	vector<float> *gennus_mass_;
	TBranch *gennus_mass_branch;
	bool gennus_mass_isLoaded;
	vector<int> *gennus_id_;
	TBranch *gennus_id_branch;
	bool gennus_id_isLoaded;
	vector<int> *gennus__genpsidx_;
	TBranch *gennus__genpsidx_branch;
	bool gennus__genpsidx_isLoaded;
	vector<int> *gennus_status_;
	TBranch *gennus_status_branch;
	bool gennus_status_isLoaded;
	vector<vector<int> > *gennus_lepdaughter_id_;
	TBranch *gennus_lepdaughter_id_branch;
	bool gennus_lepdaughter_id_isLoaded;
	vector<int> *gennus_gentaudecay_;
	TBranch *gennus_gentaudecay_branch;
	bool gennus_gentaudecay_isLoaded;
	int	gen_nfromtnus__;
	TBranch *gen_nfromtnus__branch;
	bool gen_nfromtnus__isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gennus_motherp4_;
	TBranch *gennus_motherp4_branch;
	bool gennus_motherp4_isLoaded;
	vector<float> *gennus_mothercharge_;
	TBranch *gennus_mothercharge_branch;
	bool gennus_mothercharge_isLoaded;
	vector<int> *gennus_motherid_;
	TBranch *gennus_motherid_branch;
	bool gennus_motherid_isLoaded;
	vector<int> *gennus_motheridx_;
	TBranch *gennus_motheridx_branch;
	bool gennus_motheridx_isLoaded;
	vector<int> *gennus_motherstatus_;
	TBranch *gennus_motherstatus_branch;
	bool gennus_motherstatus_isLoaded;
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
public: 
void Init(TTree *tree) {
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
	genleptau_els_p4_branch = 0;
	if (tree->GetBranch("genleptau_els_p4") != 0) {
		genleptau_els_p4_branch = tree->GetBranch("genleptau_els_p4");
		if (genleptau_els_p4_branch) {genleptau_els_p4_branch->SetAddress(&genleptau_els_p4_);}
	}
	genleptau_els_motherp4_branch = 0;
	if (tree->GetBranch("genleptau_els_motherp4") != 0) {
		genleptau_els_motherp4_branch = tree->GetBranch("genleptau_els_motherp4");
		if (genleptau_els_motherp4_branch) {genleptau_els_motherp4_branch->SetAddress(&genleptau_els_motherp4_);}
	}
	genleptau_mus_p4_branch = 0;
	if (tree->GetBranch("genleptau_mus_p4") != 0) {
		genleptau_mus_p4_branch = tree->GetBranch("genleptau_mus_p4");
		if (genleptau_mus_p4_branch) {genleptau_mus_p4_branch->SetAddress(&genleptau_mus_p4_);}
	}
	genleptau_mus_motherp4_branch = 0;
	if (tree->GetBranch("genleptau_mus_motherp4") != 0) {
		genleptau_mus_motherp4_branch = tree->GetBranch("genleptau_mus_motherp4");
		if (genleptau_mus_motherp4_branch) {genleptau_mus_motherp4_branch->SetAddress(&genleptau_mus_motherp4_);}
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
	gennus_p4_branch = 0;
	if (tree->GetBranch("gennus_p4") != 0) {
		gennus_p4_branch = tree->GetBranch("gennus_p4");
		if (gennus_p4_branch) {gennus_p4_branch->SetAddress(&gennus_p4_);}
	}
	gennus_motherp4_branch = 0;
	if (tree->GetBranch("gennus_motherp4") != 0) {
		gennus_motherp4_branch = tree->GetBranch("gennus_motherp4");
		if (gennus_motherp4_branch) {gennus_motherp4_branch->SetAddress(&gennus_motherp4_);}
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
	Topness_lep2_branch = 0;
	if (tree->GetBranch("Topness_lep2") != 0) {
		Topness_lep2_branch = tree->GetBranch("Topness_lep2");
		if (Topness_lep2_branch) {Topness_lep2_branch->SetAddress(&Topness_lep2_);}
	}
	TopnessMod_lep1_branch = 0;
	if (tree->GetBranch("TopnessMod_lep1") != 0) {
		TopnessMod_lep1_branch = tree->GetBranch("TopnessMod_lep1");
		if (TopnessMod_lep1_branch) {TopnessMod_lep1_branch->SetAddress(&TopnessMod_lep1_);}
	}
	TopnessMod_lep2_branch = 0;
	if (tree->GetBranch("TopnessMod_lep2") != 0) {
		TopnessMod_lep2_branch = tree->GetBranch("TopnessMod_lep2");
		if (TopnessMod_lep2_branch) {TopnessMod_lep2_branch->SetAddress(&TopnessMod_lep2_);}
	}
	MT2_lb_b_lep1_branch = 0;
	if (tree->GetBranch("MT2_lb_b_lep1") != 0) {
		MT2_lb_b_lep1_branch = tree->GetBranch("MT2_lb_b_lep1");
		if (MT2_lb_b_lep1_branch) {MT2_lb_b_lep1_branch->SetAddress(&MT2_lb_b_lep1_);}
	}
	MT2_lb_b_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_lep2") != 0) {
		MT2_lb_b_lep2_branch = tree->GetBranch("MT2_lb_b_lep2");
		if (MT2_lb_b_lep2_branch) {MT2_lb_b_lep2_branch->SetAddress(&MT2_lb_b_lep2_);}
	}
	MT2_lb_b_mass_lep1_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass_lep1") != 0) {
		MT2_lb_b_mass_lep1_branch = tree->GetBranch("MT2_lb_b_mass_lep1");
		if (MT2_lb_b_mass_lep1_branch) {MT2_lb_b_mass_lep1_branch->SetAddress(&MT2_lb_b_mass_lep1_);}
	}
	MT2_lb_b_mass_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass_lep2") != 0) {
		MT2_lb_b_mass_lep2_branch = tree->GetBranch("MT2_lb_b_mass_lep2");
		if (MT2_lb_b_mass_lep2_branch) {MT2_lb_b_mass_lep2_branch->SetAddress(&MT2_lb_b_mass_lep2_);}
	}
	MT2_lb_bqq_lep1_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_lep1") != 0) {
		MT2_lb_bqq_lep1_branch = tree->GetBranch("MT2_lb_bqq_lep1");
		if (MT2_lb_bqq_lep1_branch) {MT2_lb_bqq_lep1_branch->SetAddress(&MT2_lb_bqq_lep1_);}
	}
	MT2_lb_bqq_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_lep2") != 0) {
		MT2_lb_bqq_lep2_branch = tree->GetBranch("MT2_lb_bqq_lep2");
		if (MT2_lb_bqq_lep2_branch) {MT2_lb_bqq_lep2_branch->SetAddress(&MT2_lb_bqq_lep2_);}
	}
	MT2_lb_bqq_mass_lep1_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_mass_lep1") != 0) {
		MT2_lb_bqq_mass_lep1_branch = tree->GetBranch("MT2_lb_bqq_mass_lep1");
		if (MT2_lb_bqq_mass_lep1_branch) {MT2_lb_bqq_mass_lep1_branch->SetAddress(&MT2_lb_bqq_mass_lep1_);}
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
	HLT_ht350met120_branch = 0;
	if (tree->GetBranch("HLT_ht350met120") != 0) {
		HLT_ht350met120_branch = tree->GetBranch("HLT_ht350met120");
		if (HLT_ht350met120_branch) {HLT_ht350met120_branch->SetAddress(&HLT_ht350met120_);}
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
	genleptau_els_isfromt_branch = 0;
	if (tree->GetBranch("genleptau_els_isfromt") != 0) {
		genleptau_els_isfromt_branch = tree->GetBranch("genleptau_els_isfromt");
		if (genleptau_els_isfromt_branch) {genleptau_els_isfromt_branch->SetAddress(&genleptau_els_isfromt_);}
	}
	genleptau_els_charge_branch = 0;
	if (tree->GetBranch("genleptau_els_charge") != 0) {
		genleptau_els_charge_branch = tree->GetBranch("genleptau_els_charge");
		if (genleptau_els_charge_branch) {genleptau_els_charge_branch->SetAddress(&genleptau_els_charge_);}
	}
	genleptau_els_iso_branch = 0;
	if (tree->GetBranch("genleptau_els_iso") != 0) {
		genleptau_els_iso_branch = tree->GetBranch("genleptau_els_iso");
		if (genleptau_els_iso_branch) {genleptau_els_iso_branch->SetAddress(&genleptau_els_iso_);}
	}
	genleptau_els_mass_branch = 0;
	if (tree->GetBranch("genleptau_els_mass") != 0) {
		genleptau_els_mass_branch = tree->GetBranch("genleptau_els_mass");
		if (genleptau_els_mass_branch) {genleptau_els_mass_branch->SetAddress(&genleptau_els_mass_);}
	}
	genleptau_els_id_branch = 0;
	if (tree->GetBranch("genleptau_els_id") != 0) {
		genleptau_els_id_branch = tree->GetBranch("genleptau_els_id");
		if (genleptau_els_id_branch) {genleptau_els_id_branch->SetAddress(&genleptau_els_id_);}
	}
	genleptau_els__genpsidx_branch = 0;
	if (tree->GetBranch("genleptau_els__genpsidx") != 0) {
		genleptau_els__genpsidx_branch = tree->GetBranch("genleptau_els__genpsidx");
		if (genleptau_els__genpsidx_branch) {genleptau_els__genpsidx_branch->SetAddress(&genleptau_els__genpsidx_);}
	}
	genleptau_els_status_branch = 0;
	if (tree->GetBranch("genleptau_els_status") != 0) {
		genleptau_els_status_branch = tree->GetBranch("genleptau_els_status");
		if (genleptau_els_status_branch) {genleptau_els_status_branch->SetAddress(&genleptau_els_status_);}
	}
	genleptau_els_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genleptau_els_lepdaughter_id") != 0) {
		genleptau_els_lepdaughter_id_branch = tree->GetBranch("genleptau_els_lepdaughter_id");
		if (genleptau_els_lepdaughter_id_branch) {genleptau_els_lepdaughter_id_branch->SetAddress(&genleptau_els_lepdaughter_id_);}
	}
	genleptau_els_gentaudecay_branch = 0;
	if (tree->GetBranch("genleptau_els_gentaudecay") != 0) {
		genleptau_els_gentaudecay_branch = tree->GetBranch("genleptau_els_gentaudecay");
		if (genleptau_els_gentaudecay_branch) {genleptau_els_gentaudecay_branch->SetAddress(&genleptau_els_gentaudecay_);}
	}
	gen_nfromtleptau_els__branch = 0;
	if (tree->GetBranch("gen_nfromtleptau_els_") != 0) {
		gen_nfromtleptau_els__branch = tree->GetBranch("gen_nfromtleptau_els_");
		if (gen_nfromtleptau_els__branch) {gen_nfromtleptau_els__branch->SetAddress(&gen_nfromtleptau_els__);}
	}
	genleptau_els_mothercharge_branch = 0;
	if (tree->GetBranch("genleptau_els_mothercharge") != 0) {
		genleptau_els_mothercharge_branch = tree->GetBranch("genleptau_els_mothercharge");
		if (genleptau_els_mothercharge_branch) {genleptau_els_mothercharge_branch->SetAddress(&genleptau_els_mothercharge_);}
	}
	genleptau_els_motherid_branch = 0;
	if (tree->GetBranch("genleptau_els_motherid") != 0) {
		genleptau_els_motherid_branch = tree->GetBranch("genleptau_els_motherid");
		if (genleptau_els_motherid_branch) {genleptau_els_motherid_branch->SetAddress(&genleptau_els_motherid_);}
	}
	genleptau_els_motheridx_branch = 0;
	if (tree->GetBranch("genleptau_els_motheridx") != 0) {
		genleptau_els_motheridx_branch = tree->GetBranch("genleptau_els_motheridx");
		if (genleptau_els_motheridx_branch) {genleptau_els_motheridx_branch->SetAddress(&genleptau_els_motheridx_);}
	}
	genleptau_els_motherstatus_branch = 0;
	if (tree->GetBranch("genleptau_els_motherstatus") != 0) {
		genleptau_els_motherstatus_branch = tree->GetBranch("genleptau_els_motherstatus");
		if (genleptau_els_motherstatus_branch) {genleptau_els_motherstatus_branch->SetAddress(&genleptau_els_motherstatus_);}
	}
	genleptau_mus_isfromt_branch = 0;
	if (tree->GetBranch("genleptau_mus_isfromt") != 0) {
		genleptau_mus_isfromt_branch = tree->GetBranch("genleptau_mus_isfromt");
		if (genleptau_mus_isfromt_branch) {genleptau_mus_isfromt_branch->SetAddress(&genleptau_mus_isfromt_);}
	}
	genleptau_mus_charge_branch = 0;
	if (tree->GetBranch("genleptau_mus_charge") != 0) {
		genleptau_mus_charge_branch = tree->GetBranch("genleptau_mus_charge");
		if (genleptau_mus_charge_branch) {genleptau_mus_charge_branch->SetAddress(&genleptau_mus_charge_);}
	}
	genleptau_mus_iso_branch = 0;
	if (tree->GetBranch("genleptau_mus_iso") != 0) {
		genleptau_mus_iso_branch = tree->GetBranch("genleptau_mus_iso");
		if (genleptau_mus_iso_branch) {genleptau_mus_iso_branch->SetAddress(&genleptau_mus_iso_);}
	}
	genleptau_mus_mass_branch = 0;
	if (tree->GetBranch("genleptau_mus_mass") != 0) {
		genleptau_mus_mass_branch = tree->GetBranch("genleptau_mus_mass");
		if (genleptau_mus_mass_branch) {genleptau_mus_mass_branch->SetAddress(&genleptau_mus_mass_);}
	}
	genleptau_mus_id_branch = 0;
	if (tree->GetBranch("genleptau_mus_id") != 0) {
		genleptau_mus_id_branch = tree->GetBranch("genleptau_mus_id");
		if (genleptau_mus_id_branch) {genleptau_mus_id_branch->SetAddress(&genleptau_mus_id_);}
	}
	genleptau_mus__genpsidx_branch = 0;
	if (tree->GetBranch("genleptau_mus__genpsidx") != 0) {
		genleptau_mus__genpsidx_branch = tree->GetBranch("genleptau_mus__genpsidx");
		if (genleptau_mus__genpsidx_branch) {genleptau_mus__genpsidx_branch->SetAddress(&genleptau_mus__genpsidx_);}
	}
	genleptau_mus_status_branch = 0;
	if (tree->GetBranch("genleptau_mus_status") != 0) {
		genleptau_mus_status_branch = tree->GetBranch("genleptau_mus_status");
		if (genleptau_mus_status_branch) {genleptau_mus_status_branch->SetAddress(&genleptau_mus_status_);}
	}
	genleptau_mus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("genleptau_mus_lepdaughter_id") != 0) {
		genleptau_mus_lepdaughter_id_branch = tree->GetBranch("genleptau_mus_lepdaughter_id");
		if (genleptau_mus_lepdaughter_id_branch) {genleptau_mus_lepdaughter_id_branch->SetAddress(&genleptau_mus_lepdaughter_id_);}
	}
	genleptau_mus_gentaudecay_branch = 0;
	if (tree->GetBranch("genleptau_mus_gentaudecay") != 0) {
		genleptau_mus_gentaudecay_branch = tree->GetBranch("genleptau_mus_gentaudecay");
		if (genleptau_mus_gentaudecay_branch) {genleptau_mus_gentaudecay_branch->SetAddress(&genleptau_mus_gentaudecay_);}
	}
	gen_nfromtleptau_mus__branch = 0;
	if (tree->GetBranch("gen_nfromtleptau_mus_") != 0) {
		gen_nfromtleptau_mus__branch = tree->GetBranch("gen_nfromtleptau_mus_");
		if (gen_nfromtleptau_mus__branch) {gen_nfromtleptau_mus__branch->SetAddress(&gen_nfromtleptau_mus__);}
	}
	genleptau_mus_mothercharge_branch = 0;
	if (tree->GetBranch("genleptau_mus_mothercharge") != 0) {
		genleptau_mus_mothercharge_branch = tree->GetBranch("genleptau_mus_mothercharge");
		if (genleptau_mus_mothercharge_branch) {genleptau_mus_mothercharge_branch->SetAddress(&genleptau_mus_mothercharge_);}
	}
	genleptau_mus_motherid_branch = 0;
	if (tree->GetBranch("genleptau_mus_motherid") != 0) {
		genleptau_mus_motherid_branch = tree->GetBranch("genleptau_mus_motherid");
		if (genleptau_mus_motherid_branch) {genleptau_mus_motherid_branch->SetAddress(&genleptau_mus_motherid_);}
	}
	genleptau_mus_motheridx_branch = 0;
	if (tree->GetBranch("genleptau_mus_motheridx") != 0) {
		genleptau_mus_motheridx_branch = tree->GetBranch("genleptau_mus_motheridx");
		if (genleptau_mus_motheridx_branch) {genleptau_mus_motheridx_branch->SetAddress(&genleptau_mus_motheridx_);}
	}
	genleptau_mus_motherstatus_branch = 0;
	if (tree->GetBranch("genleptau_mus_motherstatus") != 0) {
		genleptau_mus_motherstatus_branch = tree->GetBranch("genleptau_mus_motherstatus");
		if (genleptau_mus_motherstatus_branch) {genleptau_mus_motherstatus_branch->SetAddress(&genleptau_mus_motherstatus_);}
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
	gennus_isfromt_branch = 0;
	if (tree->GetBranch("gennus_isfromt") != 0) {
		gennus_isfromt_branch = tree->GetBranch("gennus_isfromt");
		if (gennus_isfromt_branch) {gennus_isfromt_branch->SetAddress(&gennus_isfromt_);}
	}
	gennus_charge_branch = 0;
	if (tree->GetBranch("gennus_charge") != 0) {
		gennus_charge_branch = tree->GetBranch("gennus_charge");
		if (gennus_charge_branch) {gennus_charge_branch->SetAddress(&gennus_charge_);}
	}
	gennus_iso_branch = 0;
	if (tree->GetBranch("gennus_iso") != 0) {
		gennus_iso_branch = tree->GetBranch("gennus_iso");
		if (gennus_iso_branch) {gennus_iso_branch->SetAddress(&gennus_iso_);}
	}
	gennus_mass_branch = 0;
	if (tree->GetBranch("gennus_mass") != 0) {
		gennus_mass_branch = tree->GetBranch("gennus_mass");
		if (gennus_mass_branch) {gennus_mass_branch->SetAddress(&gennus_mass_);}
	}
	gennus_id_branch = 0;
	if (tree->GetBranch("gennus_id") != 0) {
		gennus_id_branch = tree->GetBranch("gennus_id");
		if (gennus_id_branch) {gennus_id_branch->SetAddress(&gennus_id_);}
	}
	gennus__genpsidx_branch = 0;
	if (tree->GetBranch("gennus__genpsidx") != 0) {
		gennus__genpsidx_branch = tree->GetBranch("gennus__genpsidx");
		if (gennus__genpsidx_branch) {gennus__genpsidx_branch->SetAddress(&gennus__genpsidx_);}
	}
	gennus_status_branch = 0;
	if (tree->GetBranch("gennus_status") != 0) {
		gennus_status_branch = tree->GetBranch("gennus_status");
		if (gennus_status_branch) {gennus_status_branch->SetAddress(&gennus_status_);}
	}
	gennus_lepdaughter_id_branch = 0;
	if (tree->GetBranch("gennus_lepdaughter_id") != 0) {
		gennus_lepdaughter_id_branch = tree->GetBranch("gennus_lepdaughter_id");
		if (gennus_lepdaughter_id_branch) {gennus_lepdaughter_id_branch->SetAddress(&gennus_lepdaughter_id_);}
	}
	gennus_gentaudecay_branch = 0;
	if (tree->GetBranch("gennus_gentaudecay") != 0) {
		gennus_gentaudecay_branch = tree->GetBranch("gennus_gentaudecay");
		if (gennus_gentaudecay_branch) {gennus_gentaudecay_branch->SetAddress(&gennus_gentaudecay_);}
	}
	gen_nfromtnus__branch = 0;
	if (tree->GetBranch("gen_nfromtnus_") != 0) {
		gen_nfromtnus__branch = tree->GetBranch("gen_nfromtnus_");
		if (gen_nfromtnus__branch) {gen_nfromtnus__branch->SetAddress(&gen_nfromtnus__);}
	}
	gennus_mothercharge_branch = 0;
	if (tree->GetBranch("gennus_mothercharge") != 0) {
		gennus_mothercharge_branch = tree->GetBranch("gennus_mothercharge");
		if (gennus_mothercharge_branch) {gennus_mothercharge_branch->SetAddress(&gennus_mothercharge_);}
	}
	gennus_motherid_branch = 0;
	if (tree->GetBranch("gennus_motherid") != 0) {
		gennus_motherid_branch = tree->GetBranch("gennus_motherid");
		if (gennus_motherid_branch) {gennus_motherid_branch->SetAddress(&gennus_motherid_);}
	}
	gennus_motheridx_branch = 0;
	if (tree->GetBranch("gennus_motheridx") != 0) {
		gennus_motheridx_branch = tree->GetBranch("gennus_motheridx");
		if (gennus_motheridx_branch) {gennus_motheridx_branch->SetAddress(&gennus_motheridx_);}
	}
	gennus_motherstatus_branch = 0;
	if (tree->GetBranch("gennus_motherstatus") != 0) {
		gennus_motherstatus_branch = tree->GetBranch("gennus_motherstatus");
		if (gennus_motherstatus_branch) {gennus_motherstatus_branch->SetAddress(&gennus_motherstatus_);}
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
		pu_nvtxs_isLoaded = false;
		pfmet_isLoaded = false;
		pfmet_phi_isLoaded = false;
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
		PassTauVeto_isLoaded = false;
		EA_all_rho_isLoaded = false;
		EA_allcalo_rho_isLoaded = false;
		EA_centralcalo_rho_isLoaded = false;
		EA_centralchargedpileup_rho_isLoaded = false;
		EA_centralneutral_rho_isLoaded = false;
		topness_isLoaded = false;
		Topness_lep2_isLoaded = false;
		TopnessMod_lep1_isLoaded = false;
		TopnessMod_lep2_isLoaded = false;
		MT2_lb_b_lep1_isLoaded = false;
		MT2_lb_b_lep2_isLoaded = false;
		MT2_lb_b_mass_lep1_isLoaded = false;
		MT2_lb_b_mass_lep2_isLoaded = false;
		MT2_lb_bqq_lep1_isLoaded = false;
		MT2_lb_bqq_lep2_isLoaded = false;
		MT2_lb_bqq_mass_lep1_isLoaded = false;
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
		HLT_ht350met120_isLoaded = false;
		HLT_MET120Btag_isLoaded = false;
		HLT_MET120Mu5_isLoaded = false;
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
		ak4pfjet_overlep1_cm_isLoaded = false;
		ak4pfjet_overlep1_nm_isLoaded = false;
		ak4pfjet_overlep2_p4_isLoaded = false;
		ak4pfjet_overlep2_CSV_isLoaded = false;
		ak4pfjet_overlep2_pu_id_isLoaded = false;
		ak4pfjet_overlep2_chf_isLoaded = false;
		ak4pfjet_overlep2_nhf_isLoaded = false;
		ak4pfjet_overlep2_cef_isLoaded = false;
		ak4pfjet_overlep2_nef_isLoaded = false;
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
		genels_isfromt_isLoaded = false;
		genels_p4_isLoaded = false;
		genels_charge_isLoaded = false;
		genels_iso_isLoaded = false;
		genels_mass_isLoaded = false;
		genels_id_isLoaded = false;
		genels__genpsidx_isLoaded = false;
		genels_status_isLoaded = false;
		genels_lepdaughter_id_isLoaded = false;
		genels_gentaudecay_isLoaded = false;
		gen_nfromtels__isLoaded = false;
		genels_motherp4_isLoaded = false;
		genels_mothercharge_isLoaded = false;
		genels_motherid_isLoaded = false;
		genels_motheridx_isLoaded = false;
		genels_motherstatus_isLoaded = false;
		genmus_isfromt_isLoaded = false;
		genmus_p4_isLoaded = false;
		genmus_charge_isLoaded = false;
		genmus_iso_isLoaded = false;
		genmus_mass_isLoaded = false;
		genmus_id_isLoaded = false;
		genmus__genpsidx_isLoaded = false;
		genmus_status_isLoaded = false;
		genmus_lepdaughter_id_isLoaded = false;
		genmus_gentaudecay_isLoaded = false;
		gen_nfromtmus__isLoaded = false;
		genmus_motherp4_isLoaded = false;
		genmus_mothercharge_isLoaded = false;
		genmus_motherid_isLoaded = false;
		genmus_motheridx_isLoaded = false;
		genmus_motherstatus_isLoaded = false;
		genleptau_els_isfromt_isLoaded = false;
		genleptau_els_p4_isLoaded = false;
		genleptau_els_charge_isLoaded = false;
		genleptau_els_iso_isLoaded = false;
		genleptau_els_mass_isLoaded = false;
		genleptau_els_id_isLoaded = false;
		genleptau_els__genpsidx_isLoaded = false;
		genleptau_els_status_isLoaded = false;
		genleptau_els_lepdaughter_id_isLoaded = false;
		genleptau_els_gentaudecay_isLoaded = false;
		gen_nfromtleptau_els__isLoaded = false;
		genleptau_els_motherp4_isLoaded = false;
		genleptau_els_mothercharge_isLoaded = false;
		genleptau_els_motherid_isLoaded = false;
		genleptau_els_motheridx_isLoaded = false;
		genleptau_els_motherstatus_isLoaded = false;
		genleptau_mus_isfromt_isLoaded = false;
		genleptau_mus_p4_isLoaded = false;
		genleptau_mus_charge_isLoaded = false;
		genleptau_mus_iso_isLoaded = false;
		genleptau_mus_mass_isLoaded = false;
		genleptau_mus_id_isLoaded = false;
		genleptau_mus__genpsidx_isLoaded = false;
		genleptau_mus_status_isLoaded = false;
		genleptau_mus_lepdaughter_id_isLoaded = false;
		genleptau_mus_gentaudecay_isLoaded = false;
		gen_nfromtleptau_mus__isLoaded = false;
		genleptau_mus_motherp4_isLoaded = false;
		genleptau_mus_mothercharge_isLoaded = false;
		genleptau_mus_motherid_isLoaded = false;
		genleptau_mus_motheridx_isLoaded = false;
		genleptau_mus_motherstatus_isLoaded = false;
		gentaus_isfromt_isLoaded = false;
		gentaus_p4_isLoaded = false;
		gentaus_charge_isLoaded = false;
		gentaus_iso_isLoaded = false;
		gentaus_mass_isLoaded = false;
		gentaus_id_isLoaded = false;
		gentaus__genpsidx_isLoaded = false;
		gentaus_status_isLoaded = false;
		gentaus_lepdaughter_id_isLoaded = false;
		gentaus_gentaudecay_isLoaded = false;
		gen_nfromttaus__isLoaded = false;
		gentaus_motherp4_isLoaded = false;
		gentaus_mothercharge_isLoaded = false;
		gentaus_motherid_isLoaded = false;
		gentaus_motheridx_isLoaded = false;
		gentaus_motherstatus_isLoaded = false;
		gennus_isfromt_isLoaded = false;
		gennus_p4_isLoaded = false;
		gennus_charge_isLoaded = false;
		gennus_iso_isLoaded = false;
		gennus_mass_isLoaded = false;
		gennus_id_isLoaded = false;
		gennus__genpsidx_isLoaded = false;
		gennus_status_isLoaded = false;
		gennus_lepdaughter_id_isLoaded = false;
		gennus_gentaudecay_isLoaded = false;
		gen_nfromtnus__isLoaded = false;
		gennus_motherp4_isLoaded = false;
		gennus_mothercharge_isLoaded = false;
		gennus_motherid_isLoaded = false;
		gennus_motheridx_isLoaded = false;
		gennus_motherstatus_isLoaded = false;
		genbs_isfromt_isLoaded = false;
		genbs_p4_isLoaded = false;
		genbs_charge_isLoaded = false;
		genbs_iso_isLoaded = false;
		genbs_mass_isLoaded = false;
		genbs_id_isLoaded = false;
		genbs__genpsidx_isLoaded = false;
		genbs_status_isLoaded = false;
		genbs_lepdaughter_id_isLoaded = false;
		genbs_gentaudecay_isLoaded = false;
		gen_nfromtbs__isLoaded = false;
		genbs_motherp4_isLoaded = false;
		genbs_mothercharge_isLoaded = false;
		genbs_motherid_isLoaded = false;
		genbs_motheridx_isLoaded = false;
		genbs_motherstatus_isLoaded = false;
		gents_isfromt_isLoaded = false;
		gents_p4_isLoaded = false;
		gents_charge_isLoaded = false;
		gents_iso_isLoaded = false;
		gents_mass_isLoaded = false;
		gents_id_isLoaded = false;
		gents__genpsidx_isLoaded = false;
		gents_status_isLoaded = false;
		gents_lepdaughter_id_isLoaded = false;
		gents_gentaudecay_isLoaded = false;
		gen_nfromtts__isLoaded = false;
		gents_motherp4_isLoaded = false;
		gents_mothercharge_isLoaded = false;
		gents_motherid_isLoaded = false;
		gents_motheridx_isLoaded = false;
		gents_motherstatus_isLoaded = false;
		genqs_isfromt_isLoaded = false;
		genqs_p4_isLoaded = false;
		genqs_charge_isLoaded = false;
		genqs_iso_isLoaded = false;
		genqs_mass_isLoaded = false;
		genqs_id_isLoaded = false;
		genqs__genpsidx_isLoaded = false;
		genqs_status_isLoaded = false;
		genqs_lepdaughter_id_isLoaded = false;
		genqs_gentaudecay_isLoaded = false;
		gen_nfromtqs__isLoaded = false;
		genqs_motherp4_isLoaded = false;
		genqs_mothercharge_isLoaded = false;
		genqs_motherid_isLoaded = false;
		genqs_motheridx_isLoaded = false;
		genqs_motherstatus_isLoaded = false;
		genlsp_isfromt_isLoaded = false;
		genlsp_p4_isLoaded = false;
		genlsp_charge_isLoaded = false;
		genlsp_iso_isLoaded = false;
		genlsp_mass_isLoaded = false;
		genlsp_id_isLoaded = false;
		genlsp__genpsidx_isLoaded = false;
		genlsp_status_isLoaded = false;
		genlsp_lepdaughter_id_isLoaded = false;
		genlsp_gentaudecay_isLoaded = false;
		gen_nfromtlsp__isLoaded = false;
		genlsp_motherp4_isLoaded = false;
		genlsp_mothercharge_isLoaded = false;
		genlsp_motherid_isLoaded = false;
		genlsp_motheridx_isLoaded = false;
		genlsp_motherstatus_isLoaded = false;
		genstop_isfromt_isLoaded = false;
		genstop_p4_isLoaded = false;
		genstop_charge_isLoaded = false;
		genstop_iso_isLoaded = false;
		genstop_mass_isLoaded = false;
		genstop_id_isLoaded = false;
		genstop__genpsidx_isLoaded = false;
		genstop_status_isLoaded = false;
		genstop_lepdaughter_id_isLoaded = false;
		genstop_gentaudecay_isLoaded = false;
		gen_nfromtstop__isLoaded = false;
		genstop_motherp4_isLoaded = false;
		genstop_mothercharge_isLoaded = false;
		genstop_motherid_isLoaded = false;
		genstop_motheridx_isLoaded = false;
		genstop_motherstatus_isLoaded = false;
		tau_IDnames_isLoaded = false;
		tau_leadtrack_p4_isLoaded = false;
		tau_leadneutral_p4_isLoaded = false;
		tau_p4_isLoaded = false;
		tau_isocand_p4_isLoaded = false;
		tau_sigcand_p4_isLoaded = false;
		tau_mass_isLoaded = false;
		tau_ID_isLoaded = false;
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
	if (pu_nvtxs_branch != 0) pu_nvtxs();
	if (pfmet_branch != 0) pfmet();
	if (pfmet_phi_branch != 0) pfmet_phi();
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
	if (PassTauVeto_branch != 0) PassTauVeto();
	if (EA_all_rho_branch != 0) EA_all_rho();
	if (EA_allcalo_rho_branch != 0) EA_allcalo_rho();
	if (EA_centralcalo_rho_branch != 0) EA_centralcalo_rho();
	if (EA_centralchargedpileup_rho_branch != 0) EA_centralchargedpileup_rho();
	if (EA_centralneutral_rho_branch != 0) EA_centralneutral_rho();
	if (topness_branch != 0) topness();
	if (Topness_lep2_branch != 0) Topness_lep2();
	if (TopnessMod_lep1_branch != 0) TopnessMod_lep1();
	if (TopnessMod_lep2_branch != 0) TopnessMod_lep2();
	if (MT2_lb_b_lep1_branch != 0) MT2_lb_b_lep1();
	if (MT2_lb_b_lep2_branch != 0) MT2_lb_b_lep2();
	if (MT2_lb_b_mass_lep1_branch != 0) MT2_lb_b_mass_lep1();
	if (MT2_lb_b_mass_lep2_branch != 0) MT2_lb_b_mass_lep2();
	if (MT2_lb_bqq_lep1_branch != 0) MT2_lb_bqq_lep1();
	if (MT2_lb_bqq_lep2_branch != 0) MT2_lb_bqq_lep2();
	if (MT2_lb_bqq_mass_lep1_branch != 0) MT2_lb_bqq_mass_lep1();
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
	if (HLT_ht350met120_branch != 0) HLT_ht350met120();
	if (HLT_MET120Btag_branch != 0) HLT_MET120Btag();
	if (HLT_MET120Mu5_branch != 0) HLT_MET120Mu5();
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
	if (ak4pfjet_overlep1_cm_branch != 0) ak4pfjet_overlep1_cm();
	if (ak4pfjet_overlep1_nm_branch != 0) ak4pfjet_overlep1_nm();
	if (ak4pfjet_overlep2_p4_branch != 0) ak4pfjet_overlep2_p4();
	if (ak4pfjet_overlep2_CSV_branch != 0) ak4pfjet_overlep2_CSV();
	if (ak4pfjet_overlep2_pu_id_branch != 0) ak4pfjet_overlep2_pu_id();
	if (ak4pfjet_overlep2_chf_branch != 0) ak4pfjet_overlep2_chf();
	if (ak4pfjet_overlep2_nhf_branch != 0) ak4pfjet_overlep2_nhf();
	if (ak4pfjet_overlep2_cef_branch != 0) ak4pfjet_overlep2_cef();
	if (ak4pfjet_overlep2_nef_branch != 0) ak4pfjet_overlep2_nef();
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
	if (genels_isfromt_branch != 0) genels_isfromt();
	if (genels_p4_branch != 0) genels_p4();
	if (genels_charge_branch != 0) genels_charge();
	if (genels_iso_branch != 0) genels_iso();
	if (genels_mass_branch != 0) genels_mass();
	if (genels_id_branch != 0) genels_id();
	if (genels__genpsidx_branch != 0) genels__genpsidx();
	if (genels_status_branch != 0) genels_status();
	if (genels_lepdaughter_id_branch != 0) genels_lepdaughter_id();
	if (genels_gentaudecay_branch != 0) genels_gentaudecay();
	if (gen_nfromtels__branch != 0) gen_nfromtels_();
	if (genels_motherp4_branch != 0) genels_motherp4();
	if (genels_mothercharge_branch != 0) genels_mothercharge();
	if (genels_motherid_branch != 0) genels_motherid();
	if (genels_motheridx_branch != 0) genels_motheridx();
	if (genels_motherstatus_branch != 0) genels_motherstatus();
	if (genmus_isfromt_branch != 0) genmus_isfromt();
	if (genmus_p4_branch != 0) genmus_p4();
	if (genmus_charge_branch != 0) genmus_charge();
	if (genmus_iso_branch != 0) genmus_iso();
	if (genmus_mass_branch != 0) genmus_mass();
	if (genmus_id_branch != 0) genmus_id();
	if (genmus__genpsidx_branch != 0) genmus__genpsidx();
	if (genmus_status_branch != 0) genmus_status();
	if (genmus_lepdaughter_id_branch != 0) genmus_lepdaughter_id();
	if (genmus_gentaudecay_branch != 0) genmus_gentaudecay();
	if (gen_nfromtmus__branch != 0) gen_nfromtmus_();
	if (genmus_motherp4_branch != 0) genmus_motherp4();
	if (genmus_mothercharge_branch != 0) genmus_mothercharge();
	if (genmus_motherid_branch != 0) genmus_motherid();
	if (genmus_motheridx_branch != 0) genmus_motheridx();
	if (genmus_motherstatus_branch != 0) genmus_motherstatus();
	if (genleptau_els_isfromt_branch != 0) genleptau_els_isfromt();
	if (genleptau_els_p4_branch != 0) genleptau_els_p4();
	if (genleptau_els_charge_branch != 0) genleptau_els_charge();
	if (genleptau_els_iso_branch != 0) genleptau_els_iso();
	if (genleptau_els_mass_branch != 0) genleptau_els_mass();
	if (genleptau_els_id_branch != 0) genleptau_els_id();
	if (genleptau_els__genpsidx_branch != 0) genleptau_els__genpsidx();
	if (genleptau_els_status_branch != 0) genleptau_els_status();
	if (genleptau_els_lepdaughter_id_branch != 0) genleptau_els_lepdaughter_id();
	if (genleptau_els_gentaudecay_branch != 0) genleptau_els_gentaudecay();
	if (gen_nfromtleptau_els__branch != 0) gen_nfromtleptau_els_();
	if (genleptau_els_motherp4_branch != 0) genleptau_els_motherp4();
	if (genleptau_els_mothercharge_branch != 0) genleptau_els_mothercharge();
	if (genleptau_els_motherid_branch != 0) genleptau_els_motherid();
	if (genleptau_els_motheridx_branch != 0) genleptau_els_motheridx();
	if (genleptau_els_motherstatus_branch != 0) genleptau_els_motherstatus();
	if (genleptau_mus_isfromt_branch != 0) genleptau_mus_isfromt();
	if (genleptau_mus_p4_branch != 0) genleptau_mus_p4();
	if (genleptau_mus_charge_branch != 0) genleptau_mus_charge();
	if (genleptau_mus_iso_branch != 0) genleptau_mus_iso();
	if (genleptau_mus_mass_branch != 0) genleptau_mus_mass();
	if (genleptau_mus_id_branch != 0) genleptau_mus_id();
	if (genleptau_mus__genpsidx_branch != 0) genleptau_mus__genpsidx();
	if (genleptau_mus_status_branch != 0) genleptau_mus_status();
	if (genleptau_mus_lepdaughter_id_branch != 0) genleptau_mus_lepdaughter_id();
	if (genleptau_mus_gentaudecay_branch != 0) genleptau_mus_gentaudecay();
	if (gen_nfromtleptau_mus__branch != 0) gen_nfromtleptau_mus_();
	if (genleptau_mus_motherp4_branch != 0) genleptau_mus_motherp4();
	if (genleptau_mus_mothercharge_branch != 0) genleptau_mus_mothercharge();
	if (genleptau_mus_motherid_branch != 0) genleptau_mus_motherid();
	if (genleptau_mus_motheridx_branch != 0) genleptau_mus_motheridx();
	if (genleptau_mus_motherstatus_branch != 0) genleptau_mus_motherstatus();
	if (gentaus_isfromt_branch != 0) gentaus_isfromt();
	if (gentaus_p4_branch != 0) gentaus_p4();
	if (gentaus_charge_branch != 0) gentaus_charge();
	if (gentaus_iso_branch != 0) gentaus_iso();
	if (gentaus_mass_branch != 0) gentaus_mass();
	if (gentaus_id_branch != 0) gentaus_id();
	if (gentaus__genpsidx_branch != 0) gentaus__genpsidx();
	if (gentaus_status_branch != 0) gentaus_status();
	if (gentaus_lepdaughter_id_branch != 0) gentaus_lepdaughter_id();
	if (gentaus_gentaudecay_branch != 0) gentaus_gentaudecay();
	if (gen_nfromttaus__branch != 0) gen_nfromttaus_();
	if (gentaus_motherp4_branch != 0) gentaus_motherp4();
	if (gentaus_mothercharge_branch != 0) gentaus_mothercharge();
	if (gentaus_motherid_branch != 0) gentaus_motherid();
	if (gentaus_motheridx_branch != 0) gentaus_motheridx();
	if (gentaus_motherstatus_branch != 0) gentaus_motherstatus();
	if (gennus_isfromt_branch != 0) gennus_isfromt();
	if (gennus_p4_branch != 0) gennus_p4();
	if (gennus_charge_branch != 0) gennus_charge();
	if (gennus_iso_branch != 0) gennus_iso();
	if (gennus_mass_branch != 0) gennus_mass();
	if (gennus_id_branch != 0) gennus_id();
	if (gennus__genpsidx_branch != 0) gennus__genpsidx();
	if (gennus_status_branch != 0) gennus_status();
	if (gennus_lepdaughter_id_branch != 0) gennus_lepdaughter_id();
	if (gennus_gentaudecay_branch != 0) gennus_gentaudecay();
	if (gen_nfromtnus__branch != 0) gen_nfromtnus_();
	if (gennus_motherp4_branch != 0) gennus_motherp4();
	if (gennus_mothercharge_branch != 0) gennus_mothercharge();
	if (gennus_motherid_branch != 0) gennus_motherid();
	if (gennus_motheridx_branch != 0) gennus_motheridx();
	if (gennus_motherstatus_branch != 0) gennus_motherstatus();
	if (genbs_isfromt_branch != 0) genbs_isfromt();
	if (genbs_p4_branch != 0) genbs_p4();
	if (genbs_charge_branch != 0) genbs_charge();
	if (genbs_iso_branch != 0) genbs_iso();
	if (genbs_mass_branch != 0) genbs_mass();
	if (genbs_id_branch != 0) genbs_id();
	if (genbs__genpsidx_branch != 0) genbs__genpsidx();
	if (genbs_status_branch != 0) genbs_status();
	if (genbs_lepdaughter_id_branch != 0) genbs_lepdaughter_id();
	if (genbs_gentaudecay_branch != 0) genbs_gentaudecay();
	if (gen_nfromtbs__branch != 0) gen_nfromtbs_();
	if (genbs_motherp4_branch != 0) genbs_motherp4();
	if (genbs_mothercharge_branch != 0) genbs_mothercharge();
	if (genbs_motherid_branch != 0) genbs_motherid();
	if (genbs_motheridx_branch != 0) genbs_motheridx();
	if (genbs_motherstatus_branch != 0) genbs_motherstatus();
	if (gents_isfromt_branch != 0) gents_isfromt();
	if (gents_p4_branch != 0) gents_p4();
	if (gents_charge_branch != 0) gents_charge();
	if (gents_iso_branch != 0) gents_iso();
	if (gents_mass_branch != 0) gents_mass();
	if (gents_id_branch != 0) gents_id();
	if (gents__genpsidx_branch != 0) gents__genpsidx();
	if (gents_status_branch != 0) gents_status();
	if (gents_lepdaughter_id_branch != 0) gents_lepdaughter_id();
	if (gents_gentaudecay_branch != 0) gents_gentaudecay();
	if (gen_nfromtts__branch != 0) gen_nfromtts_();
	if (gents_motherp4_branch != 0) gents_motherp4();
	if (gents_mothercharge_branch != 0) gents_mothercharge();
	if (gents_motherid_branch != 0) gents_motherid();
	if (gents_motheridx_branch != 0) gents_motheridx();
	if (gents_motherstatus_branch != 0) gents_motherstatus();
	if (genqs_isfromt_branch != 0) genqs_isfromt();
	if (genqs_p4_branch != 0) genqs_p4();
	if (genqs_charge_branch != 0) genqs_charge();
	if (genqs_iso_branch != 0) genqs_iso();
	if (genqs_mass_branch != 0) genqs_mass();
	if (genqs_id_branch != 0) genqs_id();
	if (genqs__genpsidx_branch != 0) genqs__genpsidx();
	if (genqs_status_branch != 0) genqs_status();
	if (genqs_lepdaughter_id_branch != 0) genqs_lepdaughter_id();
	if (genqs_gentaudecay_branch != 0) genqs_gentaudecay();
	if (gen_nfromtqs__branch != 0) gen_nfromtqs_();
	if (genqs_motherp4_branch != 0) genqs_motherp4();
	if (genqs_mothercharge_branch != 0) genqs_mothercharge();
	if (genqs_motherid_branch != 0) genqs_motherid();
	if (genqs_motheridx_branch != 0) genqs_motheridx();
	if (genqs_motherstatus_branch != 0) genqs_motherstatus();
	if (genlsp_isfromt_branch != 0) genlsp_isfromt();
	if (genlsp_p4_branch != 0) genlsp_p4();
	if (genlsp_charge_branch != 0) genlsp_charge();
	if (genlsp_iso_branch != 0) genlsp_iso();
	if (genlsp_mass_branch != 0) genlsp_mass();
	if (genlsp_id_branch != 0) genlsp_id();
	if (genlsp__genpsidx_branch != 0) genlsp__genpsidx();
	if (genlsp_status_branch != 0) genlsp_status();
	if (genlsp_lepdaughter_id_branch != 0) genlsp_lepdaughter_id();
	if (genlsp_gentaudecay_branch != 0) genlsp_gentaudecay();
	if (gen_nfromtlsp__branch != 0) gen_nfromtlsp_();
	if (genlsp_motherp4_branch != 0) genlsp_motherp4();
	if (genlsp_mothercharge_branch != 0) genlsp_mothercharge();
	if (genlsp_motherid_branch != 0) genlsp_motherid();
	if (genlsp_motheridx_branch != 0) genlsp_motheridx();
	if (genlsp_motherstatus_branch != 0) genlsp_motherstatus();
	if (genstop_isfromt_branch != 0) genstop_isfromt();
	if (genstop_p4_branch != 0) genstop_p4();
	if (genstop_charge_branch != 0) genstop_charge();
	if (genstop_iso_branch != 0) genstop_iso();
	if (genstop_mass_branch != 0) genstop_mass();
	if (genstop_id_branch != 0) genstop_id();
	if (genstop__genpsidx_branch != 0) genstop__genpsidx();
	if (genstop_status_branch != 0) genstop_status();
	if (genstop_lepdaughter_id_branch != 0) genstop_lepdaughter_id();
	if (genstop_gentaudecay_branch != 0) genstop_gentaudecay();
	if (gen_nfromtstop__branch != 0) gen_nfromtstop_();
	if (genstop_motherp4_branch != 0) genstop_motherp4();
	if (genstop_mothercharge_branch != 0) genstop_mothercharge();
	if (genstop_motherid_branch != 0) genstop_motherid();
	if (genstop_motheridx_branch != 0) genstop_motheridx();
	if (genstop_motherstatus_branch != 0) genstop_motherstatus();
	if (tau_IDnames_branch != 0) tau_IDnames();
	if (tau_leadtrack_p4_branch != 0) tau_leadtrack_p4();
	if (tau_leadneutral_p4_branch != 0) tau_leadneutral_p4();
	if (tau_p4_branch != 0) tau_p4();
	if (tau_isocand_p4_branch != 0) tau_isocand_p4();
	if (tau_sigcand_p4_branch != 0) tau_sigcand_p4();
	if (tau_mass_branch != 0) tau_mass();
	if (tau_ID_branch != 0) tau_ID();
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
	float &Topness_lep2()
	{
		if (not Topness_lep2_isLoaded) {
			if (Topness_lep2_branch != 0) {
				Topness_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Topness_lep2_branch does not exist!\n");
				exit(1);
			}
			Topness_lep2_isLoaded = true;
		}
		return Topness_lep2_;
	}
	float &TopnessMod_lep1()
	{
		if (not TopnessMod_lep1_isLoaded) {
			if (TopnessMod_lep1_branch != 0) {
				TopnessMod_lep1_branch->GetEntry(index);
			} else { 
				printf("branch TopnessMod_lep1_branch does not exist!\n");
				exit(1);
			}
			TopnessMod_lep1_isLoaded = true;
		}
		return TopnessMod_lep1_;
	}
	float &TopnessMod_lep2()
	{
		if (not TopnessMod_lep2_isLoaded) {
			if (TopnessMod_lep2_branch != 0) {
				TopnessMod_lep2_branch->GetEntry(index);
			} else { 
				printf("branch TopnessMod_lep2_branch does not exist!\n");
				exit(1);
			}
			TopnessMod_lep2_isLoaded = true;
		}
		return TopnessMod_lep2_;
	}
	float &MT2_lb_b_lep1()
	{
		if (not MT2_lb_b_lep1_isLoaded) {
			if (MT2_lb_b_lep1_branch != 0) {
				MT2_lb_b_lep1_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_lep1_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_lep1_isLoaded = true;
		}
		return MT2_lb_b_lep1_;
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
	float &MT2_lb_b_mass_lep1()
	{
		if (not MT2_lb_b_mass_lep1_isLoaded) {
			if (MT2_lb_b_mass_lep1_branch != 0) {
				MT2_lb_b_mass_lep1_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_mass_lep1_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_mass_lep1_isLoaded = true;
		}
		return MT2_lb_b_mass_lep1_;
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
	float &MT2_lb_bqq_lep1()
	{
		if (not MT2_lb_bqq_lep1_isLoaded) {
			if (MT2_lb_bqq_lep1_branch != 0) {
				MT2_lb_bqq_lep1_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_lep1_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_lep1_isLoaded = true;
		}
		return MT2_lb_bqq_lep1_;
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
	float &MT2_lb_bqq_mass_lep1()
	{
		if (not MT2_lb_bqq_mass_lep1_isLoaded) {
			if (MT2_lb_bqq_mass_lep1_branch != 0) {
				MT2_lb_bqq_mass_lep1_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_mass_lep1_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_mass_lep1_isLoaded = true;
		}
		return MT2_lb_bqq_mass_lep1_;
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
	int &HLT_ht350met120()
	{
		if (not HLT_ht350met120_isLoaded) {
			if (HLT_ht350met120_branch != 0) {
				HLT_ht350met120_branch->GetEntry(index);
			} else { 
				printf("branch HLT_ht350met120_branch does not exist!\n");
				exit(1);
			}
			HLT_ht350met120_isLoaded = true;
		}
		return HLT_ht350met120_;
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
	const vector<bool> &genleptau_els_isfromt()
	{
		if (not genleptau_els_isfromt_isLoaded) {
			if (genleptau_els_isfromt_branch != 0) {
				genleptau_els_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_isfromt_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_isfromt_isLoaded = true;
		}
		return *genleptau_els_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_p4()
	{
		if (not genleptau_els_p4_isLoaded) {
			if (genleptau_els_p4_branch != 0) {
				genleptau_els_p4_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_p4_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_p4_isLoaded = true;
		}
		return *genleptau_els_p4_;
	}
	const vector<float> &genleptau_els_charge()
	{
		if (not genleptau_els_charge_isLoaded) {
			if (genleptau_els_charge_branch != 0) {
				genleptau_els_charge_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_charge_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_charge_isLoaded = true;
		}
		return *genleptau_els_charge_;
	}
	const vector<float> &genleptau_els_iso()
	{
		if (not genleptau_els_iso_isLoaded) {
			if (genleptau_els_iso_branch != 0) {
				genleptau_els_iso_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_iso_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_iso_isLoaded = true;
		}
		return *genleptau_els_iso_;
	}
	const vector<float> &genleptau_els_mass()
	{
		if (not genleptau_els_mass_isLoaded) {
			if (genleptau_els_mass_branch != 0) {
				genleptau_els_mass_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_mass_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_mass_isLoaded = true;
		}
		return *genleptau_els_mass_;
	}
	const vector<int> &genleptau_els_id()
	{
		if (not genleptau_els_id_isLoaded) {
			if (genleptau_els_id_branch != 0) {
				genleptau_els_id_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_id_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_id_isLoaded = true;
		}
		return *genleptau_els_id_;
	}
	const vector<int> &genleptau_els__genpsidx()
	{
		if (not genleptau_els__genpsidx_isLoaded) {
			if (genleptau_els__genpsidx_branch != 0) {
				genleptau_els__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genleptau_els__genpsidx_isLoaded = true;
		}
		return *genleptau_els__genpsidx_;
	}
	const vector<int> &genleptau_els_status()
	{
		if (not genleptau_els_status_isLoaded) {
			if (genleptau_els_status_branch != 0) {
				genleptau_els_status_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_status_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_status_isLoaded = true;
		}
		return *genleptau_els_status_;
	}
	const vector<vector<int> > &genleptau_els_lepdaughter_id()
	{
		if (not genleptau_els_lepdaughter_id_isLoaded) {
			if (genleptau_els_lepdaughter_id_branch != 0) {
				genleptau_els_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_lepdaughter_id_isLoaded = true;
		}
		return *genleptau_els_lepdaughter_id_;
	}
	const vector<int> &genleptau_els_gentaudecay()
	{
		if (not genleptau_els_gentaudecay_isLoaded) {
			if (genleptau_els_gentaudecay_branch != 0) {
				genleptau_els_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_gentaudecay_isLoaded = true;
		}
		return *genleptau_els_gentaudecay_;
	}
	int &gen_nfromtleptau_els_()
	{
		if (not gen_nfromtleptau_els__isLoaded) {
			if (gen_nfromtleptau_els__branch != 0) {
				gen_nfromtleptau_els__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtleptau_els__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtleptau_els__isLoaded = true;
		}
		return gen_nfromtleptau_els__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_motherp4()
	{
		if (not genleptau_els_motherp4_isLoaded) {
			if (genleptau_els_motherp4_branch != 0) {
				genleptau_els_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_motherp4_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_motherp4_isLoaded = true;
		}
		return *genleptau_els_motherp4_;
	}
	const vector<float> &genleptau_els_mothercharge()
	{
		if (not genleptau_els_mothercharge_isLoaded) {
			if (genleptau_els_mothercharge_branch != 0) {
				genleptau_els_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_mothercharge_isLoaded = true;
		}
		return *genleptau_els_mothercharge_;
	}
	const vector<int> &genleptau_els_motherid()
	{
		if (not genleptau_els_motherid_isLoaded) {
			if (genleptau_els_motherid_branch != 0) {
				genleptau_els_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_motherid_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_motherid_isLoaded = true;
		}
		return *genleptau_els_motherid_;
	}
	const vector<int> &genleptau_els_motheridx()
	{
		if (not genleptau_els_motheridx_isLoaded) {
			if (genleptau_els_motheridx_branch != 0) {
				genleptau_els_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_motheridx_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_motheridx_isLoaded = true;
		}
		return *genleptau_els_motheridx_;
	}
	const vector<int> &genleptau_els_motherstatus()
	{
		if (not genleptau_els_motherstatus_isLoaded) {
			if (genleptau_els_motherstatus_branch != 0) {
				genleptau_els_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_els_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genleptau_els_motherstatus_isLoaded = true;
		}
		return *genleptau_els_motherstatus_;
	}
	const vector<bool> &genleptau_mus_isfromt()
	{
		if (not genleptau_mus_isfromt_isLoaded) {
			if (genleptau_mus_isfromt_branch != 0) {
				genleptau_mus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_isfromt_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_isfromt_isLoaded = true;
		}
		return *genleptau_mus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_p4()
	{
		if (not genleptau_mus_p4_isLoaded) {
			if (genleptau_mus_p4_branch != 0) {
				genleptau_mus_p4_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_p4_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_p4_isLoaded = true;
		}
		return *genleptau_mus_p4_;
	}
	const vector<float> &genleptau_mus_charge()
	{
		if (not genleptau_mus_charge_isLoaded) {
			if (genleptau_mus_charge_branch != 0) {
				genleptau_mus_charge_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_charge_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_charge_isLoaded = true;
		}
		return *genleptau_mus_charge_;
	}
	const vector<float> &genleptau_mus_iso()
	{
		if (not genleptau_mus_iso_isLoaded) {
			if (genleptau_mus_iso_branch != 0) {
				genleptau_mus_iso_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_iso_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_iso_isLoaded = true;
		}
		return *genleptau_mus_iso_;
	}
	const vector<float> &genleptau_mus_mass()
	{
		if (not genleptau_mus_mass_isLoaded) {
			if (genleptau_mus_mass_branch != 0) {
				genleptau_mus_mass_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_mass_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_mass_isLoaded = true;
		}
		return *genleptau_mus_mass_;
	}
	const vector<int> &genleptau_mus_id()
	{
		if (not genleptau_mus_id_isLoaded) {
			if (genleptau_mus_id_branch != 0) {
				genleptau_mus_id_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_id_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_id_isLoaded = true;
		}
		return *genleptau_mus_id_;
	}
	const vector<int> &genleptau_mus__genpsidx()
	{
		if (not genleptau_mus__genpsidx_isLoaded) {
			if (genleptau_mus__genpsidx_branch != 0) {
				genleptau_mus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus__genpsidx_isLoaded = true;
		}
		return *genleptau_mus__genpsidx_;
	}
	const vector<int> &genleptau_mus_status()
	{
		if (not genleptau_mus_status_isLoaded) {
			if (genleptau_mus_status_branch != 0) {
				genleptau_mus_status_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_status_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_status_isLoaded = true;
		}
		return *genleptau_mus_status_;
	}
	const vector<vector<int> > &genleptau_mus_lepdaughter_id()
	{
		if (not genleptau_mus_lepdaughter_id_isLoaded) {
			if (genleptau_mus_lepdaughter_id_branch != 0) {
				genleptau_mus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_lepdaughter_id_isLoaded = true;
		}
		return *genleptau_mus_lepdaughter_id_;
	}
	const vector<int> &genleptau_mus_gentaudecay()
	{
		if (not genleptau_mus_gentaudecay_isLoaded) {
			if (genleptau_mus_gentaudecay_branch != 0) {
				genleptau_mus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_gentaudecay_isLoaded = true;
		}
		return *genleptau_mus_gentaudecay_;
	}
	int &gen_nfromtleptau_mus_()
	{
		if (not gen_nfromtleptau_mus__isLoaded) {
			if (gen_nfromtleptau_mus__branch != 0) {
				gen_nfromtleptau_mus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtleptau_mus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtleptau_mus__isLoaded = true;
		}
		return gen_nfromtleptau_mus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_motherp4()
	{
		if (not genleptau_mus_motherp4_isLoaded) {
			if (genleptau_mus_motherp4_branch != 0) {
				genleptau_mus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_motherp4_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_motherp4_isLoaded = true;
		}
		return *genleptau_mus_motherp4_;
	}
	const vector<float> &genleptau_mus_mothercharge()
	{
		if (not genleptau_mus_mothercharge_isLoaded) {
			if (genleptau_mus_mothercharge_branch != 0) {
				genleptau_mus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_mothercharge_isLoaded = true;
		}
		return *genleptau_mus_mothercharge_;
	}
	const vector<int> &genleptau_mus_motherid()
	{
		if (not genleptau_mus_motherid_isLoaded) {
			if (genleptau_mus_motherid_branch != 0) {
				genleptau_mus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_motherid_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_motherid_isLoaded = true;
		}
		return *genleptau_mus_motherid_;
	}
	const vector<int> &genleptau_mus_motheridx()
	{
		if (not genleptau_mus_motheridx_isLoaded) {
			if (genleptau_mus_motheridx_branch != 0) {
				genleptau_mus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_motheridx_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_motheridx_isLoaded = true;
		}
		return *genleptau_mus_motheridx_;
	}
	const vector<int> &genleptau_mus_motherstatus()
	{
		if (not genleptau_mus_motherstatus_isLoaded) {
			if (genleptau_mus_motherstatus_branch != 0) {
				genleptau_mus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genleptau_mus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genleptau_mus_motherstatus_isLoaded = true;
		}
		return *genleptau_mus_motherstatus_;
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
	const vector<bool> &gennus_isfromt()
	{
		if (not gennus_isfromt_isLoaded) {
			if (gennus_isfromt_branch != 0) {
				gennus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gennus_isfromt_branch does not exist!\n");
				exit(1);
			}
			gennus_isfromt_isLoaded = true;
		}
		return *gennus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4()
	{
		if (not gennus_p4_isLoaded) {
			if (gennus_p4_branch != 0) {
				gennus_p4_branch->GetEntry(index);
			} else { 
				printf("branch gennus_p4_branch does not exist!\n");
				exit(1);
			}
			gennus_p4_isLoaded = true;
		}
		return *gennus_p4_;
	}
	const vector<float> &gennus_charge()
	{
		if (not gennus_charge_isLoaded) {
			if (gennus_charge_branch != 0) {
				gennus_charge_branch->GetEntry(index);
			} else { 
				printf("branch gennus_charge_branch does not exist!\n");
				exit(1);
			}
			gennus_charge_isLoaded = true;
		}
		return *gennus_charge_;
	}
	const vector<float> &gennus_iso()
	{
		if (not gennus_iso_isLoaded) {
			if (gennus_iso_branch != 0) {
				gennus_iso_branch->GetEntry(index);
			} else { 
				printf("branch gennus_iso_branch does not exist!\n");
				exit(1);
			}
			gennus_iso_isLoaded = true;
		}
		return *gennus_iso_;
	}
	const vector<float> &gennus_mass()
	{
		if (not gennus_mass_isLoaded) {
			if (gennus_mass_branch != 0) {
				gennus_mass_branch->GetEntry(index);
			} else { 
				printf("branch gennus_mass_branch does not exist!\n");
				exit(1);
			}
			gennus_mass_isLoaded = true;
		}
		return *gennus_mass_;
	}
	const vector<int> &gennus_id()
	{
		if (not gennus_id_isLoaded) {
			if (gennus_id_branch != 0) {
				gennus_id_branch->GetEntry(index);
			} else { 
				printf("branch gennus_id_branch does not exist!\n");
				exit(1);
			}
			gennus_id_isLoaded = true;
		}
		return *gennus_id_;
	}
	const vector<int> &gennus__genpsidx()
	{
		if (not gennus__genpsidx_isLoaded) {
			if (gennus__genpsidx_branch != 0) {
				gennus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gennus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gennus__genpsidx_isLoaded = true;
		}
		return *gennus__genpsidx_;
	}
	const vector<int> &gennus_status()
	{
		if (not gennus_status_isLoaded) {
			if (gennus_status_branch != 0) {
				gennus_status_branch->GetEntry(index);
			} else { 
				printf("branch gennus_status_branch does not exist!\n");
				exit(1);
			}
			gennus_status_isLoaded = true;
		}
		return *gennus_status_;
	}
	const vector<vector<int> > &gennus_lepdaughter_id()
	{
		if (not gennus_lepdaughter_id_isLoaded) {
			if (gennus_lepdaughter_id_branch != 0) {
				gennus_lepdaughter_id_branch->GetEntry(index);
			} else { 
				printf("branch gennus_lepdaughter_id_branch does not exist!\n");
				exit(1);
			}
			gennus_lepdaughter_id_isLoaded = true;
		}
		return *gennus_lepdaughter_id_;
	}
	const vector<int> &gennus_gentaudecay()
	{
		if (not gennus_gentaudecay_isLoaded) {
			if (gennus_gentaudecay_branch != 0) {
				gennus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gennus_gentaudecay_isLoaded = true;
		}
		return *gennus_gentaudecay_;
	}
	int &gen_nfromtnus_()
	{
		if (not gen_nfromtnus__isLoaded) {
			if (gen_nfromtnus__branch != 0) {
				gen_nfromtnus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtnus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtnus__isLoaded = true;
		}
		return gen_nfromtnus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4()
	{
		if (not gennus_motherp4_isLoaded) {
			if (gennus_motherp4_branch != 0) {
				gennus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherp4_branch does not exist!\n");
				exit(1);
			}
			gennus_motherp4_isLoaded = true;
		}
		return *gennus_motherp4_;
	}
	const vector<float> &gennus_mothercharge()
	{
		if (not gennus_mothercharge_isLoaded) {
			if (gennus_mothercharge_branch != 0) {
				gennus_mothercharge_branch->GetEntry(index);
			} else { 
				printf("branch gennus_mothercharge_branch does not exist!\n");
				exit(1);
			}
			gennus_mothercharge_isLoaded = true;
		}
		return *gennus_mothercharge_;
	}
	const vector<int> &gennus_motherid()
	{
		if (not gennus_motherid_isLoaded) {
			if (gennus_motherid_branch != 0) {
				gennus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherid_branch does not exist!\n");
				exit(1);
			}
			gennus_motherid_isLoaded = true;
		}
		return *gennus_motherid_;
	}
	const vector<int> &gennus_motheridx()
	{
		if (not gennus_motheridx_isLoaded) {
			if (gennus_motheridx_branch != 0) {
				gennus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motheridx_branch does not exist!\n");
				exit(1);
			}
			gennus_motheridx_isLoaded = true;
		}
		return *gennus_motheridx_;
	}
	const vector<int> &gennus_motherstatus()
	{
		if (not gennus_motherstatus_isLoaded) {
			if (gennus_motherstatus_branch != 0) {
				gennus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gennus_motherstatus_isLoaded = true;
		}
		return *gennus_motherstatus_;
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
	const int &pu_nvtxs();
	const float &pfmet();
	const float &pfmet_phi();
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
	const bool &PassTauVeto();
	const float &EA_all_rho();
	const float &EA_allcalo_rho();
	const float &EA_centralcalo_rho();
	const float &EA_centralchargedpileup_rho();
	const float &EA_centralneutral_rho();
	const float &topness();
	const float &Topness_lep2();
	const float &TopnessMod_lep1();
	const float &TopnessMod_lep2();
	const float &MT2_lb_b_lep1();
	const float &MT2_lb_b_lep2();
	const float &MT2_lb_b_mass_lep1();
	const float &MT2_lb_b_mass_lep2();
	const float &MT2_lb_bqq_lep1();
	const float &MT2_lb_bqq_lep2();
	const float &MT2_lb_bqq_mass_lep1();
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
	const int &HLT_ht350met120();
	const int &HLT_MET120Btag();
	const int &HLT_MET120Mu5();
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
	const int &ak4pfjet_overlep1_cm();
	const int &ak4pfjet_overlep1_nm();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4();
	const float &ak4pfjet_overlep2_CSV();
	const float &ak4pfjet_overlep2_pu_id();
	const float &ak4pfjet_overlep2_chf();
	const float &ak4pfjet_overlep2_nhf();
	const float &ak4pfjet_overlep2_cef();
	const float &ak4pfjet_overlep2_nef();
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
	const vector<bool> &genels_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_p4();
	const vector<float> &genels_charge();
	const vector<float> &genels_iso();
	const vector<float> &genels_mass();
	const vector<int> &genels_id();
	const vector<int> &genels__genpsidx();
	const vector<int> &genels_status();
	const vector<vector<int> > &genels_lepdaughter_id();
	const vector<int> &genels_gentaudecay();
	const int &gen_nfromtels_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_motherp4();
	const vector<float> &genels_mothercharge();
	const vector<int> &genels_motherid();
	const vector<int> &genels_motheridx();
	const vector<int> &genels_motherstatus();
	const vector<bool> &genmus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_p4();
	const vector<float> &genmus_charge();
	const vector<float> &genmus_iso();
	const vector<float> &genmus_mass();
	const vector<int> &genmus_id();
	const vector<int> &genmus__genpsidx();
	const vector<int> &genmus_status();
	const vector<vector<int> > &genmus_lepdaughter_id();
	const vector<int> &genmus_gentaudecay();
	const int &gen_nfromtmus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_motherp4();
	const vector<float> &genmus_mothercharge();
	const vector<int> &genmus_motherid();
	const vector<int> &genmus_motheridx();
	const vector<int> &genmus_motherstatus();
	const vector<bool> &genleptau_els_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_p4();
	const vector<float> &genleptau_els_charge();
	const vector<float> &genleptau_els_iso();
	const vector<float> &genleptau_els_mass();
	const vector<int> &genleptau_els_id();
	const vector<int> &genleptau_els__genpsidx();
	const vector<int> &genleptau_els_status();
	const vector<vector<int> > &genleptau_els_lepdaughter_id();
	const vector<int> &genleptau_els_gentaudecay();
	const int &gen_nfromtleptau_els_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_motherp4();
	const vector<float> &genleptau_els_mothercharge();
	const vector<int> &genleptau_els_motherid();
	const vector<int> &genleptau_els_motheridx();
	const vector<int> &genleptau_els_motherstatus();
	const vector<bool> &genleptau_mus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_p4();
	const vector<float> &genleptau_mus_charge();
	const vector<float> &genleptau_mus_iso();
	const vector<float> &genleptau_mus_mass();
	const vector<int> &genleptau_mus_id();
	const vector<int> &genleptau_mus__genpsidx();
	const vector<int> &genleptau_mus_status();
	const vector<vector<int> > &genleptau_mus_lepdaughter_id();
	const vector<int> &genleptau_mus_gentaudecay();
	const int &gen_nfromtleptau_mus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_motherp4();
	const vector<float> &genleptau_mus_mothercharge();
	const vector<int> &genleptau_mus_motherid();
	const vector<int> &genleptau_mus_motheridx();
	const vector<int> &genleptau_mus_motherstatus();
	const vector<bool> &gentaus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_p4();
	const vector<float> &gentaus_charge();
	const vector<float> &gentaus_iso();
	const vector<float> &gentaus_mass();
	const vector<int> &gentaus_id();
	const vector<int> &gentaus__genpsidx();
	const vector<int> &gentaus_status();
	const vector<vector<int> > &gentaus_lepdaughter_id();
	const vector<int> &gentaus_gentaudecay();
	const int &gen_nfromttaus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_motherp4();
	const vector<float> &gentaus_mothercharge();
	const vector<int> &gentaus_motherid();
	const vector<int> &gentaus_motheridx();
	const vector<int> &gentaus_motherstatus();
	const vector<bool> &gennus_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4();
	const vector<float> &gennus_charge();
	const vector<float> &gennus_iso();
	const vector<float> &gennus_mass();
	const vector<int> &gennus_id();
	const vector<int> &gennus__genpsidx();
	const vector<int> &gennus_status();
	const vector<vector<int> > &gennus_lepdaughter_id();
	const vector<int> &gennus_gentaudecay();
	const int &gen_nfromtnus_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4();
	const vector<float> &gennus_mothercharge();
	const vector<int> &gennus_motherid();
	const vector<int> &gennus_motheridx();
	const vector<int> &gennus_motherstatus();
	const vector<bool> &genbs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_p4();
	const vector<float> &genbs_charge();
	const vector<float> &genbs_iso();
	const vector<float> &genbs_mass();
	const vector<int> &genbs_id();
	const vector<int> &genbs__genpsidx();
	const vector<int> &genbs_status();
	const vector<vector<int> > &genbs_lepdaughter_id();
	const vector<int> &genbs_gentaudecay();
	const int &gen_nfromtbs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_motherp4();
	const vector<float> &genbs_mothercharge();
	const vector<int> &genbs_motherid();
	const vector<int> &genbs_motheridx();
	const vector<int> &genbs_motherstatus();
	const vector<bool> &gents_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4();
	const vector<float> &gents_charge();
	const vector<float> &gents_iso();
	const vector<float> &gents_mass();
	const vector<int> &gents_id();
	const vector<int> &gents__genpsidx();
	const vector<int> &gents_status();
	const vector<vector<int> > &gents_lepdaughter_id();
	const vector<int> &gents_gentaudecay();
	const int &gen_nfromtts_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4();
	const vector<float> &gents_mothercharge();
	const vector<int> &gents_motherid();
	const vector<int> &gents_motheridx();
	const vector<int> &gents_motherstatus();
	const vector<bool> &genqs_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4();
	const vector<float> &genqs_charge();
	const vector<float> &genqs_iso();
	const vector<float> &genqs_mass();
	const vector<int> &genqs_id();
	const vector<int> &genqs__genpsidx();
	const vector<int> &genqs_status();
	const vector<vector<int> > &genqs_lepdaughter_id();
	const vector<int> &genqs_gentaudecay();
	const int &gen_nfromtqs_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4();
	const vector<float> &genqs_mothercharge();
	const vector<int> &genqs_motherid();
	const vector<int> &genqs_motheridx();
	const vector<int> &genqs_motherstatus();
	const vector<bool> &genlsp_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_p4();
	const vector<float> &genlsp_charge();
	const vector<float> &genlsp_iso();
	const vector<float> &genlsp_mass();
	const vector<int> &genlsp_id();
	const vector<int> &genlsp__genpsidx();
	const vector<int> &genlsp_status();
	const vector<vector<int> > &genlsp_lepdaughter_id();
	const vector<int> &genlsp_gentaudecay();
	const int &gen_nfromtlsp_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_motherp4();
	const vector<float> &genlsp_mothercharge();
	const vector<int> &genlsp_motherid();
	const vector<int> &genlsp_motheridx();
	const vector<int> &genlsp_motherstatus();
	const vector<bool> &genstop_isfromt();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_p4();
	const vector<float> &genstop_charge();
	const vector<float> &genstop_iso();
	const vector<float> &genstop_mass();
	const vector<int> &genstop_id();
	const vector<int> &genstop__genpsidx();
	const vector<int> &genstop_status();
	const vector<vector<int> > &genstop_lepdaughter_id();
	const vector<int> &genstop_gentaudecay();
	const int &gen_nfromtstop_();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_motherp4();
	const vector<float> &genstop_mothercharge();
	const vector<int> &genstop_motherid();
	const vector<int> &genstop_motheridx();
	const vector<int> &genstop_motherstatus();
	const vector<TString> &tau_IDnames();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4();
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4();
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4();
	const vector<float> &tau_mass();
	const vector<vector<float> > &tau_ID();
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
}
#endif
