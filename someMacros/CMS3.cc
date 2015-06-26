#include "CMS3.h"
CMS3 cms3;
namespace tas {
	const unsigned int &run() { return cms3.run(); }
	const unsigned int &ls() { return cms3.ls(); }
	const unsigned int &evt() { return cms3.evt(); }
	const int &nvtxs() { return cms3.nvtxs(); }
	const int &firstGoodVtxIdx() { return cms3.firstGoodVtxIdx(); }
	const int &firstVtx_isfake() { return cms3.firstVtx_isfake(); }
	const float &firstVtx_ndof() { return cms3.firstVtx_ndof(); }
	const float &firstVtx_posRho() { return cms3.firstVtx_posRho(); }
	const float &firstVtx_posZ() { return cms3.firstVtx_posZ(); }
	const int &pu_nvtxs() { return cms3.pu_nvtxs(); }
	const float &pfmet() { return cms3.pfmet(); }
	const float &pfmet_phi() { return cms3.pfmet_phi(); }
	const float &scale1fb() { return cms3.scale1fb(); }
	const float &xsec() { return cms3.xsec(); }
	const float &kfactor() { return cms3.kfactor(); }
	const float &pu_ntrue() { return cms3.pu_ntrue(); }
	const int &ngoodleps() { return cms3.ngoodleps(); }
	const int &nvetoleps() { return cms3.nvetoleps(); }
	const bool &is_data() { return cms3.is_data(); }
	const string &dataset() { return cms3.dataset(); }
	const string &filename() { return cms3.filename(); }
	const string &cms3tag() { return cms3.cms3tag(); }
	const unsigned int &nEvents() { return cms3.nEvents(); }
	const unsigned int &nEvents_goodvtx() { return cms3.nEvents_goodvtx(); }
	const unsigned int &nEvents_MET30() { return cms3.nEvents_MET30(); }
	const unsigned int &nEvents_1goodlep() { return cms3.nEvents_1goodlep(); }
	const unsigned int &nEvents_2goodjets() { return cms3.nEvents_2goodjets(); }
	const int &genlepsfromtop() { return cms3.genlepsfromtop(); }
	const float &MT2W() { return cms3.MT2W(); }
	const float &MT2W_lep2() { return cms3.MT2W_lep2(); }
	const float &mindphi_met_j1_j2() { return cms3.mindphi_met_j1_j2(); }
	const float &mt_met_lep() { return cms3.mt_met_lep(); }
	const float &mt_met_lep2() { return cms3.mt_met_lep2(); }
	const float &dR_lep_leadb() { return cms3.dR_lep_leadb(); }
	const float &dR_lep2_leadb() { return cms3.dR_lep2_leadb(); }
	const float &hadronic_top_chi2() { return cms3.hadronic_top_chi2(); }
	const float &dphi_Wlep() { return cms3.dphi_Wlep(); }
	const float &MET_over_sqrtHT() { return cms3.MET_over_sqrtHT(); }
	const float &ak4pfjets_rho() { return cms3.ak4pfjets_rho(); }
	const vector<string> &sparms_comment() { return cms3.sparms_comment(); }
	const vector<string> &sparms_names() { return cms3.sparms_names(); }
	const float &sparms_filterEfficiency() { return cms3.sparms_filterEfficiency(); }
	const float &sparms_pdfScale() { return cms3.sparms_pdfScale(); }
	const float &sparms_pdfWeight1() { return cms3.sparms_pdfWeight1(); }
	const float &sparms_pdfWeight2() { return cms3.sparms_pdfWeight2(); }
	const float &sparms_weight() { return cms3.sparms_weight(); }
	const float &sparms_xsec() { return cms3.sparms_xsec(); }
	const vector<float> &sparms_values() { return cms3.sparms_values(); }
	const int &sparms_subProcessId() { return cms3.sparms_subProcessId(); }
	const float &mass_lsp() { return cms3.mass_lsp(); }
	const float &mass_chargino() { return cms3.mass_chargino(); }
	const float &mass_stop() { return cms3.mass_stop(); }
	const float &genmet() { return cms3.genmet(); }
	const float &genmet_phi() { return cms3.genmet_phi(); }
	const bool &PassTrackVeto() { return cms3.PassTrackVeto(); }
	const bool &PassTauVeto() { return cms3.PassTauVeto(); }
	const float &EA_all_rho() { return cms3.EA_all_rho(); }
	const float &EA_allcalo_rho() { return cms3.EA_allcalo_rho(); }
	const float &EA_centralcalo_rho() { return cms3.EA_centralcalo_rho(); }
	const float &EA_centralchargedpileup_rho() { return cms3.EA_centralchargedpileup_rho(); }
	const float &EA_centralneutral_rho() { return cms3.EA_centralneutral_rho(); }
	const float &topness() { return cms3.topness(); }
	const float &Topness_lep2() { return cms3.Topness_lep2(); }
	const float &TopnessMod_lep1() { return cms3.TopnessMod_lep1(); }
	const float &TopnessMod_lep2() { return cms3.TopnessMod_lep2(); }
	const float &MT2_lb_b_lep1() { return cms3.MT2_lb_b_lep1(); }
	const float &MT2_lb_b_lep2() { return cms3.MT2_lb_b_lep2(); }
	const float &MT2_lb_b_mass_lep1() { return cms3.MT2_lb_b_mass_lep1(); }
	const float &MT2_lb_b_mass_lep2() { return cms3.MT2_lb_b_mass_lep2(); }
	const float &MT2_lb_bqq_lep1() { return cms3.MT2_lb_bqq_lep1(); }
	const float &MT2_lb_bqq_lep2() { return cms3.MT2_lb_bqq_lep2(); }
	const float &MT2_lb_bqq_mass_lep1() { return cms3.MT2_lb_bqq_mass_lep1(); }
	const float &MT2_lb_bqq_mass_lep2() { return cms3.MT2_lb_bqq_mass_lep2(); }
	const float &Mlb_closestb() { return cms3.Mlb_closestb(); }
	const float &Mlb_lead_bdiscr() { return cms3.Mlb_lead_bdiscr(); }
	const float &Mlb_closestb_lep2() { return cms3.Mlb_closestb_lep2(); }
	const float &Mlb_lead_bdiscr_lep2() { return cms3.Mlb_lead_bdiscr_lep2(); }
	const float &Mjjj() { return cms3.Mjjj(); }
	const float &Mjjj_lep2() { return cms3.Mjjj_lep2(); }
	const int &HLT_SingleEl() { return cms3.HLT_SingleEl(); }
	const int &HLT_SingleMu() { return cms3.HLT_SingleMu(); }
	const int &HLT_MET170() { return cms3.HLT_MET170(); }
	const int &HLT_ht350met120() { return cms3.HLT_ht350met120(); }
	const int &HLT_MET120Btag() { return cms3.HLT_MET120Btag(); }
	const int &HLT_MET120Mu5() { return cms3.HLT_MET120Mu5(); }
	const float &pu_weight() { return cms3.pu_weight(); }
	const float &lep_sf() { return cms3.lep_sf(); }
	const float &btag_sf() { return cms3.btag_sf(); }
	const float &HLT_SingleEl_eff() { return cms3.HLT_SingleEl_eff(); }
	const float &HLT_SingleMu_eff() { return cms3.HLT_SingleMu_eff(); }
	const bool &lep1_is_mu() { return cms3.lep1_is_mu(); }
	const bool &lep1_is_el() { return cms3.lep1_is_el(); }
	const int &lep1_charge() { return cms3.lep1_charge(); }
	const int &lep1_pdgid() { return cms3.lep1_pdgid(); }
	const int &lep1_type() { return cms3.lep1_type(); }
	const int &lep1_production_type() { return cms3.lep1_production_type(); }
	const float &lep1_d0() { return cms3.lep1_d0(); }
	const float &lep1_d0err() { return cms3.lep1_d0err(); }
	const float &lep1_dz() { return cms3.lep1_dz(); }
	const float &lep1_dzerr() { return cms3.lep1_dzerr(); }
	const float &lep1_sigmaIEtaEta_fill5x5() { return cms3.lep1_sigmaIEtaEta_fill5x5(); }
	const float &lep1_dEtaIn() { return cms3.lep1_dEtaIn(); }
	const float &lep1_dPhiIn() { return cms3.lep1_dPhiIn(); }
	const float &lep1_hOverE() { return cms3.lep1_hOverE(); }
	const float &lep1_ooEmooP() { return cms3.lep1_ooEmooP(); }
	const int &lep1_expectedMissingInnerHits() { return cms3.lep1_expectedMissingInnerHits(); }
	const bool &lep1_conversionVeto() { return cms3.lep1_conversionVeto(); }
	const float &lep1_etaSC() { return cms3.lep1_etaSC(); }
	const float &lep1_ChiSqr() { return cms3.lep1_ChiSqr(); }
	const float &lep1_chiso() { return cms3.lep1_chiso(); }
	const float &lep1_nhiso() { return cms3.lep1_nhiso(); }
	const float &lep1_emiso() { return cms3.lep1_emiso(); }
	const float &lep1_deltaBeta() { return cms3.lep1_deltaBeta(); }
	const float &lep1_relIso03DB() { return cms3.lep1_relIso03DB(); }
	const float &lep1_relIso03EA() { return cms3.lep1_relIso03EA(); }
	const float &lep1_relIso04DB() { return cms3.lep1_relIso04DB(); }
	const float &lep1_miniRelIsoDB() { return cms3.lep1_miniRelIsoDB(); }
	const float &lep1_miniRelIsoEA() { return cms3.lep1_miniRelIsoEA(); }
	const float &lep1_MiniIso() { return cms3.lep1_MiniIso(); }
	const int &lep1_mcid() { return cms3.lep1_mcid(); }
	const int &lep1_mcstatus() { return cms3.lep1_mcstatus(); }
	const int &lep1_mc3dr() { return cms3.lep1_mc3dr(); }
	const int &lep1_mc3id() { return cms3.lep1_mc3id(); }
	const int &lep1_mc3idx() { return cms3.lep1_mc3idx(); }
	const int &lep1_mc3motherid() { return cms3.lep1_mc3motherid(); }
	const int &lep1_mc3motheridx() { return cms3.lep1_mc3motheridx(); }
	const bool &lep1_is_eleid_loose() { return cms3.lep1_is_eleid_loose(); }
	const bool &lep1_is_eleid_medium() { return cms3.lep1_is_eleid_medium(); }
	const bool &lep1_is_eleid_tight() { return cms3.lep1_is_eleid_tight(); }
	const bool &lep1_is_phys14_loose_noIso() { return cms3.lep1_is_phys14_loose_noIso(); }
	const bool &lep1_is_phys14_medium_noIso() { return cms3.lep1_is_phys14_medium_noIso(); }
	const bool &lep1_is_phys14_tight_noIso() { return cms3.lep1_is_phys14_tight_noIso(); }
	const float &lep1_eoverpin() { return cms3.lep1_eoverpin(); }
	const bool &lep1_is_muoid_loose() { return cms3.lep1_is_muoid_loose(); }
	const bool &lep1_is_muoid_medium() { return cms3.lep1_is_muoid_medium(); }
	const bool &lep1_is_muoid_tight() { return cms3.lep1_is_muoid_tight(); }
	const float &lep1_ip3d() { return cms3.lep1_ip3d(); }
	const float &lep1_ip3derr() { return cms3.lep1_ip3derr(); }
	const bool &lep1_is_pfmu() { return cms3.lep1_is_pfmu(); }
	const bool &lep1_passMediumID() { return cms3.lep1_passMediumID(); }
	const bool &lep1_passVeto() { return cms3.lep1_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return cms3.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4() { return cms3.lep1_mcp4(); }
	const float &lep1_pt() { return cms3.lep1_pt(); }
	const float &lep1_eta() { return cms3.lep1_eta(); }
	const float &lep1_phi() { return cms3.lep1_phi(); }
	const float &lep1_mass() { return cms3.lep1_mass(); }
	const bool &lep2_is_mu() { return cms3.lep2_is_mu(); }
	const bool &lep2_is_el() { return cms3.lep2_is_el(); }
	const int &lep2_charge() { return cms3.lep2_charge(); }
	const int &lep2_pdgid() { return cms3.lep2_pdgid(); }
	const int &lep2_type() { return cms3.lep2_type(); }
	const int &lep2_production_type() { return cms3.lep2_production_type(); }
	const float &lep2_d0() { return cms3.lep2_d0(); }
	const float &lep2_d0err() { return cms3.lep2_d0err(); }
	const float &lep2_dz() { return cms3.lep2_dz(); }
	const float &lep2_dzerr() { return cms3.lep2_dzerr(); }
	const float &lep2_sigmaIEtaEta_fill5x5() { return cms3.lep2_sigmaIEtaEta_fill5x5(); }
	const float &lep2_dEtaIn() { return cms3.lep2_dEtaIn(); }
	const float &lep2_dPhiIn() { return cms3.lep2_dPhiIn(); }
	const float &lep2_hOverE() { return cms3.lep2_hOverE(); }
	const float &lep2_ooEmooP() { return cms3.lep2_ooEmooP(); }
	const int &lep2_expectedMissingInnerHits() { return cms3.lep2_expectedMissingInnerHits(); }
	const bool &lep2_conversionVeto() { return cms3.lep2_conversionVeto(); }
	const float &lep2_etaSC() { return cms3.lep2_etaSC(); }
	const float &lep2_ChiSqr() { return cms3.lep2_ChiSqr(); }
	const float &lep2_chiso() { return cms3.lep2_chiso(); }
	const float &lep2_nhiso() { return cms3.lep2_nhiso(); }
	const float &lep2_emiso() { return cms3.lep2_emiso(); }
	const float &lep2_deltaBeta() { return cms3.lep2_deltaBeta(); }
	const float &lep2_relIso03DB() { return cms3.lep2_relIso03DB(); }
	const float &lep2_relIso03EA() { return cms3.lep2_relIso03EA(); }
	const float &lep2_relIso04DB() { return cms3.lep2_relIso04DB(); }
	const float &lep2_miniRelIsoDB() { return cms3.lep2_miniRelIsoDB(); }
	const float &lep2_miniRelIsoEA() { return cms3.lep2_miniRelIsoEA(); }
	const float &lep2_MiniIso() { return cms3.lep2_MiniIso(); }
	const int &lep2_mcid() { return cms3.lep2_mcid(); }
	const int &lep2_mcstatus() { return cms3.lep2_mcstatus(); }
	const int &lep2_mc3dr() { return cms3.lep2_mc3dr(); }
	const int &lep2_mc3id() { return cms3.lep2_mc3id(); }
	const int &lep2_mc3idx() { return cms3.lep2_mc3idx(); }
	const int &lep2_mc3motherid() { return cms3.lep2_mc3motherid(); }
	const int &lep2_mc3motheridx() { return cms3.lep2_mc3motheridx(); }
	const bool &lep2_is_eleid_loose() { return cms3.lep2_is_eleid_loose(); }
	const bool &lep2_is_eleid_medium() { return cms3.lep2_is_eleid_medium(); }
	const bool &lep2_is_eleid_tight() { return cms3.lep2_is_eleid_tight(); }
	const bool &lep2_is_phys14_loose_noIso() { return cms3.lep2_is_phys14_loose_noIso(); }
	const bool &lep2_is_phys14_medium_noIso() { return cms3.lep2_is_phys14_medium_noIso(); }
	const bool &lep2_is_phys14_tight_noIso() { return cms3.lep2_is_phys14_tight_noIso(); }
	const float &lep2_eoverpin() { return cms3.lep2_eoverpin(); }
	const bool &lep2_is_muoid_loose() { return cms3.lep2_is_muoid_loose(); }
	const bool &lep2_is_muoid_medium() { return cms3.lep2_is_muoid_medium(); }
	const bool &lep2_is_muoid_tight() { return cms3.lep2_is_muoid_tight(); }
	const float &lep2_ip3d() { return cms3.lep2_ip3d(); }
	const float &lep2_ip3derr() { return cms3.lep2_ip3derr(); }
	const bool &lep2_is_pfmu() { return cms3.lep2_is_pfmu(); }
	const bool &lep2_passMediumID() { return cms3.lep2_passMediumID(); }
	const bool &lep2_passVeto() { return cms3.lep2_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return cms3.lep2_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4() { return cms3.lep2_mcp4(); }
	const float &lep2_pt() { return cms3.lep2_pt(); }
	const float &lep2_eta() { return cms3.lep2_eta(); }
	const float &lep2_phi() { return cms3.lep2_phi(); }
	const float &lep2_mass() { return cms3.lep2_mass(); }
	const int &nGoodGenJets() { return cms3.nGoodGenJets(); }
	const int &ngoodjets() { return cms3.ngoodjets(); }
	const int &nfailjets() { return cms3.nfailjets(); }
	const int &ak8GoodPFJets() { return cms3.ak8GoodPFJets(); }
	const int &ngoodbtags() { return cms3.ngoodbtags(); }
	const float &ak4_HT() { return cms3.ak4_HT(); }
	const float &ak4_htssm() { return cms3.ak4_htssm(); }
	const float &ak4_htosm() { return cms3.ak4_htosm(); }
	const float &ak4_htratiom() { return cms3.ak4_htratiom(); }
	const vector<float> &dphi_ak4pfjet_met() { return cms3.dphi_ak4pfjet_met(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4() { return cms3.ak4pfjets_p4(); }
	const vector<float> &ak4pfjets_pt() { return cms3.ak4pfjets_pt(); }
	const vector<float> &ak4pfjets_eta() { return cms3.ak4pfjets_eta(); }
	const vector<float> &ak4pfjets_phi() { return cms3.ak4pfjets_phi(); }
	const vector<float> &ak4pfjets_mass() { return cms3.ak4pfjets_mass(); }
	const vector<bool> &ak4pfjets_passMEDbtag() { return cms3.ak4pfjets_passMEDbtag(); }
	const vector<float> &ak4pfjets_qg_disc() { return cms3.ak4pfjets_qg_disc(); }
	const vector<float> &ak4pfjets_CSV() { return cms3.ak4pfjets_CSV(); }
	const vector<float> &ak4pfjets_puid() { return cms3.ak4pfjets_puid(); }
	const vector<int> &ak4pfjets_parton_flavor() { return cms3.ak4pfjets_parton_flavor(); }
	const vector<bool> &ak4pfjets_loose_puid() { return cms3.ak4pfjets_loose_puid(); }
	const vector<bool> &ak4pfjets_loose_pfid() { return cms3.ak4pfjets_loose_pfid(); }
	const vector<bool> &ak4pfjets_medium_pfid() { return cms3.ak4pfjets_medium_pfid(); }
	const vector<bool> &ak4pfjets_tight_pfid() { return cms3.ak4pfjets_tight_pfid(); }
	const vector<float> &ak4pfjets_MEDbjet_pt() { return cms3.ak4pfjets_MEDbjet_pt(); }
	const float &ak4pfjets_leadMEDbjet_pt() { return cms3.ak4pfjets_leadMEDbjet_pt(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4() { return cms3.ak4pfjets_leadMEDbjet_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4() { return cms3.ak4pfjets_leadbtag_p4(); }
	const vector<float> &ak4pfjets_chf() { return cms3.ak4pfjets_chf(); }
	const vector<float> &ak4pfjets_nhf() { return cms3.ak4pfjets_nhf(); }
	const vector<float> &ak4pfjets_cef() { return cms3.ak4pfjets_cef(); }
	const vector<float> &ak4pfjets_nef() { return cms3.ak4pfjets_nef(); }
	const vector<float> &ak4pfjets_muf() { return cms3.ak4pfjets_muf(); }
	const vector<int> &ak4pfjets_cm() { return cms3.ak4pfjets_cm(); }
	const vector<int> &ak4pfjets_nm() { return cms3.ak4pfjets_nm(); }
	const vector<int> &ak4pfjets_mc3dr() { return cms3.ak4pfjets_mc3dr(); }
	const vector<int> &ak4pfjets_mc3id() { return cms3.ak4pfjets_mc3id(); }
	const vector<int> &ak4pfjets_mc3idx() { return cms3.ak4pfjets_mc3idx(); }
	const vector<int> &ak4pfjets_mcmotherid() { return cms3.ak4pfjets_mcmotherid(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep1_p4() { return cms3.ak4pfjet_overlep1_p4(); }
	const float &ak4pfjet_overlep1_CSV() { return cms3.ak4pfjet_overlep1_CSV(); }
	const float &ak4pfjet_overlep1_pu_id() { return cms3.ak4pfjet_overlep1_pu_id(); }
	const float &ak4pfjet_overlep1_chf() { return cms3.ak4pfjet_overlep1_chf(); }
	const float &ak4pfjet_overlep1_nhf() { return cms3.ak4pfjet_overlep1_nhf(); }
	const float &ak4pfjet_overlep1_cef() { return cms3.ak4pfjet_overlep1_cef(); }
	const float &ak4pfjet_overlep1_nef() { return cms3.ak4pfjet_overlep1_nef(); }
	const int &ak4pfjet_overlep1_cm() { return cms3.ak4pfjet_overlep1_cm(); }
	const int &ak4pfjet_overlep1_nm() { return cms3.ak4pfjet_overlep1_nm(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4() { return cms3.ak4pfjet_overlep2_p4(); }
	const float &ak4pfjet_overlep2_CSV() { return cms3.ak4pfjet_overlep2_CSV(); }
	const float &ak4pfjet_overlep2_pu_id() { return cms3.ak4pfjet_overlep2_pu_id(); }
	const float &ak4pfjet_overlep2_chf() { return cms3.ak4pfjet_overlep2_chf(); }
	const float &ak4pfjet_overlep2_nhf() { return cms3.ak4pfjet_overlep2_nhf(); }
	const float &ak4pfjet_overlep2_cef() { return cms3.ak4pfjet_overlep2_cef(); }
	const float &ak4pfjet_overlep2_nef() { return cms3.ak4pfjet_overlep2_nef(); }
	const int &ak4pfjet_overlep2_cm() { return cms3.ak4pfjet_overlep2_cm(); }
	const int &ak4pfjet_overlep2_nm() { return cms3.ak4pfjet_overlep2_nm(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8pfjets_p4() { return cms3.ak8pfjets_p4(); }
	const vector<float> &ak8pfjets_tau1() { return cms3.ak8pfjets_tau1(); }
	const vector<float> &ak8pfjets_tau2() { return cms3.ak8pfjets_tau2(); }
	const vector<float> &ak8pfjets_tau3() { return cms3.ak8pfjets_tau3(); }
	const vector<float> &ak8pfjets_top_mass() { return cms3.ak8pfjets_top_mass(); }
	const vector<float> &ak8pfjets_pruned_mass() { return cms3.ak8pfjets_pruned_mass(); }
	const vector<float> &ak8pfjets_trimmed_mass() { return cms3.ak8pfjets_trimmed_mass(); }
	const vector<float> &ak8pfjets_filtered_mass() { return cms3.ak8pfjets_filtered_mass(); }
	const vector<float> &ak8pfjets_pu_id() { return cms3.ak8pfjets_pu_id(); }
	const vector<int> &ak8pfjets_parton_flavor() { return cms3.ak8pfjets_parton_flavor(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4() { return cms3.ak4genjets_p4(); }
	const vector<bool> &genels_isfromt() { return cms3.genels_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_p4() { return cms3.genels_p4(); }
	const vector<float> &genels_charge() { return cms3.genels_charge(); }
	const vector<float> &genels_iso() { return cms3.genels_iso(); }
	const vector<float> &genels_mass() { return cms3.genels_mass(); }
	const vector<int> &genels_id() { return cms3.genels_id(); }
	const vector<int> &genels__genpsidx() { return cms3.genels__genpsidx(); }
	const vector<int> &genels_status() { return cms3.genels_status(); }
	const vector<vector<int> > &genels_lepdaughter_id() { return cms3.genels_lepdaughter_id(); }
	const vector<int> &genels_gentaudecay() { return cms3.genels_gentaudecay(); }
	const int &gen_nfromtels_() { return cms3.gen_nfromtels_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_motherp4() { return cms3.genels_motherp4(); }
	const vector<float> &genels_mothercharge() { return cms3.genels_mothercharge(); }
	const vector<int> &genels_motherid() { return cms3.genels_motherid(); }
	const vector<int> &genels_motheridx() { return cms3.genels_motheridx(); }
	const vector<int> &genels_motherstatus() { return cms3.genels_motherstatus(); }
	const vector<bool> &genmus_isfromt() { return cms3.genmus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_p4() { return cms3.genmus_p4(); }
	const vector<float> &genmus_charge() { return cms3.genmus_charge(); }
	const vector<float> &genmus_iso() { return cms3.genmus_iso(); }
	const vector<float> &genmus_mass() { return cms3.genmus_mass(); }
	const vector<int> &genmus_id() { return cms3.genmus_id(); }
	const vector<int> &genmus__genpsidx() { return cms3.genmus__genpsidx(); }
	const vector<int> &genmus_status() { return cms3.genmus_status(); }
	const vector<vector<int> > &genmus_lepdaughter_id() { return cms3.genmus_lepdaughter_id(); }
	const vector<int> &genmus_gentaudecay() { return cms3.genmus_gentaudecay(); }
	const int &gen_nfromtmus_() { return cms3.gen_nfromtmus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_motherp4() { return cms3.genmus_motherp4(); }
	const vector<float> &genmus_mothercharge() { return cms3.genmus_mothercharge(); }
	const vector<int> &genmus_motherid() { return cms3.genmus_motherid(); }
	const vector<int> &genmus_motheridx() { return cms3.genmus_motheridx(); }
	const vector<int> &genmus_motherstatus() { return cms3.genmus_motherstatus(); }
	const vector<bool> &genleptau_els_isfromt() { return cms3.genleptau_els_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_p4() { return cms3.genleptau_els_p4(); }
	const vector<float> &genleptau_els_charge() { return cms3.genleptau_els_charge(); }
	const vector<float> &genleptau_els_iso() { return cms3.genleptau_els_iso(); }
	const vector<float> &genleptau_els_mass() { return cms3.genleptau_els_mass(); }
	const vector<int> &genleptau_els_id() { return cms3.genleptau_els_id(); }
	const vector<int> &genleptau_els__genpsidx() { return cms3.genleptau_els__genpsidx(); }
	const vector<int> &genleptau_els_status() { return cms3.genleptau_els_status(); }
	const vector<vector<int> > &genleptau_els_lepdaughter_id() { return cms3.genleptau_els_lepdaughter_id(); }
	const vector<int> &genleptau_els_gentaudecay() { return cms3.genleptau_els_gentaudecay(); }
	const int &gen_nfromtleptau_els_() { return cms3.gen_nfromtleptau_els_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_els_motherp4() { return cms3.genleptau_els_motherp4(); }
	const vector<float> &genleptau_els_mothercharge() { return cms3.genleptau_els_mothercharge(); }
	const vector<int> &genleptau_els_motherid() { return cms3.genleptau_els_motherid(); }
	const vector<int> &genleptau_els_motheridx() { return cms3.genleptau_els_motheridx(); }
	const vector<int> &genleptau_els_motherstatus() { return cms3.genleptau_els_motherstatus(); }
	const vector<bool> &genleptau_mus_isfromt() { return cms3.genleptau_mus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_p4() { return cms3.genleptau_mus_p4(); }
	const vector<float> &genleptau_mus_charge() { return cms3.genleptau_mus_charge(); }
	const vector<float> &genleptau_mus_iso() { return cms3.genleptau_mus_iso(); }
	const vector<float> &genleptau_mus_mass() { return cms3.genleptau_mus_mass(); }
	const vector<int> &genleptau_mus_id() { return cms3.genleptau_mus_id(); }
	const vector<int> &genleptau_mus__genpsidx() { return cms3.genleptau_mus__genpsidx(); }
	const vector<int> &genleptau_mus_status() { return cms3.genleptau_mus_status(); }
	const vector<vector<int> > &genleptau_mus_lepdaughter_id() { return cms3.genleptau_mus_lepdaughter_id(); }
	const vector<int> &genleptau_mus_gentaudecay() { return cms3.genleptau_mus_gentaudecay(); }
	const int &gen_nfromtleptau_mus_() { return cms3.gen_nfromtleptau_mus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleptau_mus_motherp4() { return cms3.genleptau_mus_motherp4(); }
	const vector<float> &genleptau_mus_mothercharge() { return cms3.genleptau_mus_mothercharge(); }
	const vector<int> &genleptau_mus_motherid() { return cms3.genleptau_mus_motherid(); }
	const vector<int> &genleptau_mus_motheridx() { return cms3.genleptau_mus_motheridx(); }
	const vector<int> &genleptau_mus_motherstatus() { return cms3.genleptau_mus_motherstatus(); }
	const vector<bool> &gentaus_isfromt() { return cms3.gentaus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_p4() { return cms3.gentaus_p4(); }
	const vector<float> &gentaus_charge() { return cms3.gentaus_charge(); }
	const vector<float> &gentaus_iso() { return cms3.gentaus_iso(); }
	const vector<float> &gentaus_mass() { return cms3.gentaus_mass(); }
	const vector<int> &gentaus_id() { return cms3.gentaus_id(); }
	const vector<int> &gentaus__genpsidx() { return cms3.gentaus__genpsidx(); }
	const vector<int> &gentaus_status() { return cms3.gentaus_status(); }
	const vector<vector<int> > &gentaus_lepdaughter_id() { return cms3.gentaus_lepdaughter_id(); }
	const vector<int> &gentaus_gentaudecay() { return cms3.gentaus_gentaudecay(); }
	const int &gen_nfromttaus_() { return cms3.gen_nfromttaus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_motherp4() { return cms3.gentaus_motherp4(); }
	const vector<float> &gentaus_mothercharge() { return cms3.gentaus_mothercharge(); }
	const vector<int> &gentaus_motherid() { return cms3.gentaus_motherid(); }
	const vector<int> &gentaus_motheridx() { return cms3.gentaus_motheridx(); }
	const vector<int> &gentaus_motherstatus() { return cms3.gentaus_motherstatus(); }
	const vector<bool> &gennus_isfromt() { return cms3.gennus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4() { return cms3.gennus_p4(); }
	const vector<float> &gennus_charge() { return cms3.gennus_charge(); }
	const vector<float> &gennus_iso() { return cms3.gennus_iso(); }
	const vector<float> &gennus_mass() { return cms3.gennus_mass(); }
	const vector<int> &gennus_id() { return cms3.gennus_id(); }
	const vector<int> &gennus__genpsidx() { return cms3.gennus__genpsidx(); }
	const vector<int> &gennus_status() { return cms3.gennus_status(); }
	const vector<vector<int> > &gennus_lepdaughter_id() { return cms3.gennus_lepdaughter_id(); }
	const vector<int> &gennus_gentaudecay() { return cms3.gennus_gentaudecay(); }
	const int &gen_nfromtnus_() { return cms3.gen_nfromtnus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4() { return cms3.gennus_motherp4(); }
	const vector<float> &gennus_mothercharge() { return cms3.gennus_mothercharge(); }
	const vector<int> &gennus_motherid() { return cms3.gennus_motherid(); }
	const vector<int> &gennus_motheridx() { return cms3.gennus_motheridx(); }
	const vector<int> &gennus_motherstatus() { return cms3.gennus_motherstatus(); }
	const vector<bool> &genbs_isfromt() { return cms3.genbs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_p4() { return cms3.genbs_p4(); }
	const vector<float> &genbs_charge() { return cms3.genbs_charge(); }
	const vector<float> &genbs_iso() { return cms3.genbs_iso(); }
	const vector<float> &genbs_mass() { return cms3.genbs_mass(); }
	const vector<int> &genbs_id() { return cms3.genbs_id(); }
	const vector<int> &genbs__genpsidx() { return cms3.genbs__genpsidx(); }
	const vector<int> &genbs_status() { return cms3.genbs_status(); }
	const vector<vector<int> > &genbs_lepdaughter_id() { return cms3.genbs_lepdaughter_id(); }
	const vector<int> &genbs_gentaudecay() { return cms3.genbs_gentaudecay(); }
	const int &gen_nfromtbs_() { return cms3.gen_nfromtbs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_motherp4() { return cms3.genbs_motherp4(); }
	const vector<float> &genbs_mothercharge() { return cms3.genbs_mothercharge(); }
	const vector<int> &genbs_motherid() { return cms3.genbs_motherid(); }
	const vector<int> &genbs_motheridx() { return cms3.genbs_motheridx(); }
	const vector<int> &genbs_motherstatus() { return cms3.genbs_motherstatus(); }
	const vector<bool> &gents_isfromt() { return cms3.gents_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4() { return cms3.gents_p4(); }
	const vector<float> &gents_charge() { return cms3.gents_charge(); }
	const vector<float> &gents_iso() { return cms3.gents_iso(); }
	const vector<float> &gents_mass() { return cms3.gents_mass(); }
	const vector<int> &gents_id() { return cms3.gents_id(); }
	const vector<int> &gents__genpsidx() { return cms3.gents__genpsidx(); }
	const vector<int> &gents_status() { return cms3.gents_status(); }
	const vector<vector<int> > &gents_lepdaughter_id() { return cms3.gents_lepdaughter_id(); }
	const vector<int> &gents_gentaudecay() { return cms3.gents_gentaudecay(); }
	const int &gen_nfromtts_() { return cms3.gen_nfromtts_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4() { return cms3.gents_motherp4(); }
	const vector<float> &gents_mothercharge() { return cms3.gents_mothercharge(); }
	const vector<int> &gents_motherid() { return cms3.gents_motherid(); }
	const vector<int> &gents_motheridx() { return cms3.gents_motheridx(); }
	const vector<int> &gents_motherstatus() { return cms3.gents_motherstatus(); }
	const vector<bool> &genqs_isfromt() { return cms3.genqs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4() { return cms3.genqs_p4(); }
	const vector<float> &genqs_charge() { return cms3.genqs_charge(); }
	const vector<float> &genqs_iso() { return cms3.genqs_iso(); }
	const vector<float> &genqs_mass() { return cms3.genqs_mass(); }
	const vector<int> &genqs_id() { return cms3.genqs_id(); }
	const vector<int> &genqs__genpsidx() { return cms3.genqs__genpsidx(); }
	const vector<int> &genqs_status() { return cms3.genqs_status(); }
	const vector<vector<int> > &genqs_lepdaughter_id() { return cms3.genqs_lepdaughter_id(); }
	const vector<int> &genqs_gentaudecay() { return cms3.genqs_gentaudecay(); }
	const int &gen_nfromtqs_() { return cms3.gen_nfromtqs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4() { return cms3.genqs_motherp4(); }
	const vector<float> &genqs_mothercharge() { return cms3.genqs_mothercharge(); }
	const vector<int> &genqs_motherid() { return cms3.genqs_motherid(); }
	const vector<int> &genqs_motheridx() { return cms3.genqs_motheridx(); }
	const vector<int> &genqs_motherstatus() { return cms3.genqs_motherstatus(); }
	const vector<bool> &genlsp_isfromt() { return cms3.genlsp_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_p4() { return cms3.genlsp_p4(); }
	const vector<float> &genlsp_charge() { return cms3.genlsp_charge(); }
	const vector<float> &genlsp_iso() { return cms3.genlsp_iso(); }
	const vector<float> &genlsp_mass() { return cms3.genlsp_mass(); }
	const vector<int> &genlsp_id() { return cms3.genlsp_id(); }
	const vector<int> &genlsp__genpsidx() { return cms3.genlsp__genpsidx(); }
	const vector<int> &genlsp_status() { return cms3.genlsp_status(); }
	const vector<vector<int> > &genlsp_lepdaughter_id() { return cms3.genlsp_lepdaughter_id(); }
	const vector<int> &genlsp_gentaudecay() { return cms3.genlsp_gentaudecay(); }
	const int &gen_nfromtlsp_() { return cms3.gen_nfromtlsp_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_motherp4() { return cms3.genlsp_motherp4(); }
	const vector<float> &genlsp_mothercharge() { return cms3.genlsp_mothercharge(); }
	const vector<int> &genlsp_motherid() { return cms3.genlsp_motherid(); }
	const vector<int> &genlsp_motheridx() { return cms3.genlsp_motheridx(); }
	const vector<int> &genlsp_motherstatus() { return cms3.genlsp_motherstatus(); }
	const vector<bool> &genstop_isfromt() { return cms3.genstop_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_p4() { return cms3.genstop_p4(); }
	const vector<float> &genstop_charge() { return cms3.genstop_charge(); }
	const vector<float> &genstop_iso() { return cms3.genstop_iso(); }
	const vector<float> &genstop_mass() { return cms3.genstop_mass(); }
	const vector<int> &genstop_id() { return cms3.genstop_id(); }
	const vector<int> &genstop__genpsidx() { return cms3.genstop__genpsidx(); }
	const vector<int> &genstop_status() { return cms3.genstop_status(); }
	const vector<vector<int> > &genstop_lepdaughter_id() { return cms3.genstop_lepdaughter_id(); }
	const vector<int> &genstop_gentaudecay() { return cms3.genstop_gentaudecay(); }
	const int &gen_nfromtstop_() { return cms3.gen_nfromtstop_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_motherp4() { return cms3.genstop_motherp4(); }
	const vector<float> &genstop_mothercharge() { return cms3.genstop_mothercharge(); }
	const vector<int> &genstop_motherid() { return cms3.genstop_motherid(); }
	const vector<int> &genstop_motheridx() { return cms3.genstop_motheridx(); }
	const vector<int> &genstop_motherstatus() { return cms3.genstop_motherstatus(); }
	const vector<TString> &tau_IDnames() { return cms3.tau_IDnames(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4() { return cms3.tau_leadtrack_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4() { return cms3.tau_leadneutral_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4() { return cms3.tau_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4() { return cms3.tau_isocand_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4() { return cms3.tau_sigcand_p4(); }
	const vector<float> &tau_mass() { return cms3.tau_mass(); }
	const vector<vector<float> > &tau_ID() { return cms3.tau_ID(); }
	const vector<float> &tau_charge() { return cms3.tau_charge(); }
	const int &ngoodtaus() { return cms3.ngoodtaus(); }
	const vector<float> &tau_againstMuonTight() { return cms3.tau_againstMuonTight(); }
	const vector<float> &tau_againstElectronLoose() { return cms3.tau_againstElectronLoose(); }
	const vector<bool> &tau_isVetoTau() { return cms3.tau_isVetoTau(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isoTracks_p4() { return cms3.isoTracks_p4(); }
	const vector<int> &isoTracks_charge() { return cms3.isoTracks_charge(); }
	const vector<float> &isoTracks_absIso() { return cms3.isoTracks_absIso(); }
	const vector<float> &isoTracks_dz() { return cms3.isoTracks_dz(); }
	const vector<int> &isoTracks_pdgId() { return cms3.isoTracks_pdgId(); }
	const vector<int> &isoTracks_selectedidx() { return cms3.isoTracks_selectedidx(); }
	const int &isoTracks_nselected() { return cms3.isoTracks_nselected(); }
	const vector<bool> &isoTracks_isVetoTrack() { return cms3.isoTracks_isVetoTrack(); }
}
