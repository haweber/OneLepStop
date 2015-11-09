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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &firstVtx_posp4() { return cms3.firstVtx_posp4(); }
	const int &pu_nvtxs() { return cms3.pu_nvtxs(); }
	const float &pfmet() { return cms3.pfmet(); }
	const float &pfmet_phi() { return cms3.pfmet_phi(); }
	const float &calomet() { return cms3.calomet(); }
	const float &calomet_phi() { return cms3.calomet_phi(); }
	const float &filt_cscbeamhalo() { return cms3.filt_cscbeamhalo(); }
	const float &filt_ecallaser() { return cms3.filt_ecallaser(); }
	const float &filt_ecaltp() { return cms3.filt_ecaltp(); }
	const float &filt_eebadsc() { return cms3.filt_eebadsc(); }
	const float &filt_goodvtx() { return cms3.filt_goodvtx(); }
	const float &filt_hbhenoise() { return cms3.filt_hbhenoise(); }
	const float &filt_hcallaser() { return cms3.filt_hcallaser(); }
	const float &filt_met() { return cms3.filt_met(); }
	const float &filt_trkfail() { return cms3.filt_trkfail(); }
	const float &filt_trkPOG() { return cms3.filt_trkPOG(); }
	const float &filt_trkPOG_tmc() { return cms3.filt_trkPOG_tmc(); }
	const float &filt_trkPOG_tms() { return cms3.filt_trkPOG_tms(); }
	const float &filt_eff() { return cms3.filt_eff(); }
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
	const bool &PassTrackVeto_v2() { return cms3.PassTrackVeto_v2(); }
	const bool &PassTrackVeto_v3() { return cms3.PassTrackVeto_v3(); }
	const bool &PassTauVeto() { return cms3.PassTauVeto(); }
	const float &EA_all_rho() { return cms3.EA_all_rho(); }
	const float &EA_allcalo_rho() { return cms3.EA_allcalo_rho(); }
	const float &EA_centralcalo_rho() { return cms3.EA_centralcalo_rho(); }
	const float &EA_centralchargedpileup_rho() { return cms3.EA_centralchargedpileup_rho(); }
	const float &EA_centralneutral_rho() { return cms3.EA_centralneutral_rho(); }
	const float &topness() { return cms3.topness(); }
	const float &topness_lep2() { return cms3.topness_lep2(); }
	const float &topnessMod() { return cms3.topnessMod(); }
	const float &topnessMod_lep2() { return cms3.topnessMod_lep2(); }
	const float &MT2_lb_b() { return cms3.MT2_lb_b(); }
	const float &MT2_lb_b_lep2() { return cms3.MT2_lb_b_lep2(); }
	const float &MT2_lb_b_mass() { return cms3.MT2_lb_b_mass(); }
	const float &MT2_lb_b_mass_lep2() { return cms3.MT2_lb_b_mass_lep2(); }
	const float &MT2_lb_bqq() { return cms3.MT2_lb_bqq(); }
	const float &MT2_lb_bqq_lep2() { return cms3.MT2_lb_bqq_lep2(); }
	const float &MT2_lb_bqq_mass() { return cms3.MT2_lb_bqq_mass(); }
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
	const int &HLT_MET120Btag() { return cms3.HLT_MET120Btag(); }
	const int &HLT_MET120Mu5() { return cms3.HLT_MET120Mu5(); }
	const int &HLT_HT350MET120() { return cms3.HLT_HT350MET120(); }
	const int &HLT_DiEl() { return cms3.HLT_DiEl(); }
	const int &HLT_DiMu() { return cms3.HLT_DiMu(); }
	const int &HLT_Mu8El17() { return cms3.HLT_Mu8El17(); }
	const int &HLT_Mu8El23() { return cms3.HLT_Mu8El23(); }
	const int &HLT_Mu17El12() { return cms3.HLT_Mu17El12(); }
	const int &HLT_Mu23El12() { return cms3.HLT_Mu23El12(); }
	const int &HLT_SingleEl27() { return cms3.HLT_SingleEl27(); }
	const int &HLT_SingleEl27Tight() { return cms3.HLT_SingleEl27Tight(); }
	const int &HLT_SingleElTight() { return cms3.HLT_SingleElTight(); }
	const int &HLT_SingleElHT200() { return cms3.HLT_SingleElHT200(); }
	const int &HLT_SingleMuNoEta() { return cms3.HLT_SingleMuNoEta(); }
	const int &HLT_SingleMuNoIso() { return cms3.HLT_SingleMuNoIso(); }
	const int &HLT_SingleMuNoIsoNoEta() { return cms3.HLT_SingleMuNoIsoNoEta(); }
	const int &HLT_Mu6HT200MET100() { return cms3.HLT_Mu6HT200MET100(); }
	const int &HLT_HT350MET100() { return cms3.HLT_HT350MET100(); }
	const int &HLT_SingleMu17() { return cms3.HLT_SingleMu17(); }
	const int &HLT_SingleMu20() { return cms3.HLT_SingleMu20(); }
	const int &HLT_SingleMu24() { return cms3.HLT_SingleMu24(); }
	const int &HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight() { return cms3.HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight(); }
	const int &HLT_MET90_MHT90_IDTight() { return cms3.HLT_MET90_MHT90_IDTight(); }
	const int &HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight() { return cms3.HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight(); }
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
	const float &ak4pfjet_overlep1_muf() { return cms3.ak4pfjet_overlep1_muf(); }
	const int &ak4pfjet_overlep1_cm() { return cms3.ak4pfjet_overlep1_cm(); }
	const int &ak4pfjet_overlep1_nm() { return cms3.ak4pfjet_overlep1_nm(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4() { return cms3.ak4pfjet_overlep2_p4(); }
	const float &ak4pfjet_overlep2_CSV() { return cms3.ak4pfjet_overlep2_CSV(); }
	const float &ak4pfjet_overlep2_pu_id() { return cms3.ak4pfjet_overlep2_pu_id(); }
	const float &ak4pfjet_overlep2_chf() { return cms3.ak4pfjet_overlep2_chf(); }
	const float &ak4pfjet_overlep2_nhf() { return cms3.ak4pfjet_overlep2_nhf(); }
	const float &ak4pfjet_overlep2_cef() { return cms3.ak4pfjet_overlep2_cef(); }
	const float &ak4pfjet_overlep2_nef() { return cms3.ak4pfjet_overlep2_nef(); }
	const float &ak4pfjet_overlep2_muf() { return cms3.ak4pfjet_overlep2_muf(); }
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
	const vector<TString> &tau_IDnames() { return cms3.tau_IDnames(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4() { return cms3.tau_leadtrack_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4() { return cms3.tau_leadneutral_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4() { return cms3.tau_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4() { return cms3.tau_isocand_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4() { return cms3.tau_sigcand_p4(); }
	const vector<float> &tau_mass() { return cms3.tau_mass(); }
	const vector<vector<float> > &tau_ID() { return cms3.tau_ID(); }
	const vector<float> &tau_passID() { return cms3.tau_passID(); }
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
	const vector<bool> &isoTracks_isVetoTrack_v2() { return cms3.isoTracks_isVetoTrack_v2(); }
	const vector<bool> &isoTracks_isVetoTrack_v3() { return cms3.isoTracks_isVetoTrack_v3(); }
	const vector<bool> &genels_isfromt() { return cms3.genels_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_p4() { return cms3.genels_p4(); }
	const vector<float> &genels_charge() { return cms3.genels_charge(); }
	const vector<float> &genels_iso() { return cms3.genels_iso(); }
	const vector<float> &genels_mass() { return cms3.genels_mass(); }
	const vector<int> &genels_id() { return cms3.genels_id(); }
	const vector<int> &genels__genpsidx() { return cms3.genels__genpsidx(); }
	const vector<int> &genels_status() { return cms3.genels_status(); }
	const vector<bool> &genels_fromHardProcessBeforeFSR() { return cms3.genels_fromHardProcessBeforeFSR(); }
	const vector<bool> &genels_fromHardProcessDecayed() { return cms3.genels_fromHardProcessDecayed(); }
	const vector<bool> &genels_fromHardProcessFinalState() { return cms3.genels_fromHardProcessFinalState(); }
	const vector<bool> &genels_isDirectHardProcessTauDecayProductFinalState() { return cms3.genels_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genels_isDirectPromptTauDecayProductFinalState() { return cms3.genels_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genels_isHardProcess() { return cms3.genels_isHardProcess(); }
	const vector<bool> &genels_isLastCopy() { return cms3.genels_isLastCopy(); }
	const vector<bool> &genels_isLastCopyBeforeFSR() { return cms3.genels_isLastCopyBeforeFSR(); }
	const vector<bool> &genels_isMostlyLikePythia6Status3() { return cms3.genels_isMostlyLikePythia6Status3(); }
	const vector<bool> &genels_isPromptDecayed() { return cms3.genels_isPromptDecayed(); }
	const vector<bool> &genels_isPromptFinalState() { return cms3.genels_isPromptFinalState(); }
	const vector<vector<int> > &genels_lepdaughter_id() { return cms3.genels_lepdaughter_id(); }
	const vector<int> &genels_gentaudecay() { return cms3.genels_gentaudecay(); }
	const int &gen_nfromtels_() { return cms3.gen_nfromtels_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_motherp4() { return cms3.genels_motherp4(); }
	const vector<float> &genels_mothercharge() { return cms3.genels_mothercharge(); }
	const vector<int> &genels_motherid() { return cms3.genels_motherid(); }
	const vector<int> &genels_motheridx() { return cms3.genels_motheridx(); }
	const vector<int> &genels_motherstatus() { return cms3.genels_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_gmotherp4() { return cms3.genels_gmotherp4(); }
	const vector<int> &genels_gmothercharge() { return cms3.genels_gmothercharge(); }
	const vector<int> &genels_gmotherid() { return cms3.genels_gmotherid(); }
	const vector<int> &genels_gmotheridx() { return cms3.genels_gmotheridx(); }
	const vector<int> &genels_gmotherstatus() { return cms3.genels_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplemotherp4() { return cms3.genels_simplemotherp4(); }
	const vector<int> &genels_simplemothercharge() { return cms3.genels_simplemothercharge(); }
	const vector<int> &genels_simplemotherid() { return cms3.genels_simplemotherid(); }
	const vector<int> &genels_simplemotheridx() { return cms3.genels_simplemotheridx(); }
	const vector<int> &genels_simplemotherstatus() { return cms3.genels_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genels_simplegmotherp4() { return cms3.genels_simplegmotherp4(); }
	const vector<int> &genels_simplegmothercharge() { return cms3.genels_simplegmothercharge(); }
	const vector<int> &genels_simplegmotherid() { return cms3.genels_simplegmotherid(); }
	const vector<int> &genels_simplegmotheridx() { return cms3.genels_simplegmotheridx(); }
	const vector<int> &genels_simplegmotherstatus() { return cms3.genels_simplegmotherstatus(); }
	const vector<bool> &genmus_isfromt() { return cms3.genmus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_p4() { return cms3.genmus_p4(); }
	const vector<float> &genmus_charge() { return cms3.genmus_charge(); }
	const vector<float> &genmus_iso() { return cms3.genmus_iso(); }
	const vector<float> &genmus_mass() { return cms3.genmus_mass(); }
	const vector<int> &genmus_id() { return cms3.genmus_id(); }
	const vector<int> &genmus__genpsidx() { return cms3.genmus__genpsidx(); }
	const vector<int> &genmus_status() { return cms3.genmus_status(); }
	const vector<bool> &genmus_fromHardProcessBeforeFSR() { return cms3.genmus_fromHardProcessBeforeFSR(); }
	const vector<bool> &genmus_fromHardProcessDecayed() { return cms3.genmus_fromHardProcessDecayed(); }
	const vector<bool> &genmus_fromHardProcessFinalState() { return cms3.genmus_fromHardProcessFinalState(); }
	const vector<bool> &genmus_isDirectHardProcessTauDecayProductFinalState() { return cms3.genmus_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genmus_isDirectPromptTauDecayProductFinalState() { return cms3.genmus_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genmus_isHardProcess() { return cms3.genmus_isHardProcess(); }
	const vector<bool> &genmus_isLastCopy() { return cms3.genmus_isLastCopy(); }
	const vector<bool> &genmus_isLastCopyBeforeFSR() { return cms3.genmus_isLastCopyBeforeFSR(); }
	const vector<bool> &genmus_isMostlyLikePythia6Status3() { return cms3.genmus_isMostlyLikePythia6Status3(); }
	const vector<bool> &genmus_isPromptDecayed() { return cms3.genmus_isPromptDecayed(); }
	const vector<bool> &genmus_isPromptFinalState() { return cms3.genmus_isPromptFinalState(); }
	const vector<vector<int> > &genmus_lepdaughter_id() { return cms3.genmus_lepdaughter_id(); }
	const vector<int> &genmus_gentaudecay() { return cms3.genmus_gentaudecay(); }
	const int &gen_nfromtmus_() { return cms3.gen_nfromtmus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_motherp4() { return cms3.genmus_motherp4(); }
	const vector<float> &genmus_mothercharge() { return cms3.genmus_mothercharge(); }
	const vector<int> &genmus_motherid() { return cms3.genmus_motherid(); }
	const vector<int> &genmus_motheridx() { return cms3.genmus_motheridx(); }
	const vector<int> &genmus_motherstatus() { return cms3.genmus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_gmotherp4() { return cms3.genmus_gmotherp4(); }
	const vector<int> &genmus_gmothercharge() { return cms3.genmus_gmothercharge(); }
	const vector<int> &genmus_gmotherid() { return cms3.genmus_gmotherid(); }
	const vector<int> &genmus_gmotheridx() { return cms3.genmus_gmotheridx(); }
	const vector<int> &genmus_gmotherstatus() { return cms3.genmus_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplemotherp4() { return cms3.genmus_simplemotherp4(); }
	const vector<int> &genmus_simplemothercharge() { return cms3.genmus_simplemothercharge(); }
	const vector<int> &genmus_simplemotherid() { return cms3.genmus_simplemotherid(); }
	const vector<int> &genmus_simplemotheridx() { return cms3.genmus_simplemotheridx(); }
	const vector<int> &genmus_simplemotherstatus() { return cms3.genmus_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genmus_simplegmotherp4() { return cms3.genmus_simplegmotherp4(); }
	const vector<int> &genmus_simplegmothercharge() { return cms3.genmus_simplegmothercharge(); }
	const vector<int> &genmus_simplegmotherid() { return cms3.genmus_simplegmotherid(); }
	const vector<int> &genmus_simplegmotheridx() { return cms3.genmus_simplegmotheridx(); }
	const vector<int> &genmus_simplegmotherstatus() { return cms3.genmus_simplegmotherstatus(); }
	const vector<bool> &gentaus_isfromt() { return cms3.gentaus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_p4() { return cms3.gentaus_p4(); }
	const vector<float> &gentaus_charge() { return cms3.gentaus_charge(); }
	const vector<float> &gentaus_iso() { return cms3.gentaus_iso(); }
	const vector<float> &gentaus_mass() { return cms3.gentaus_mass(); }
	const vector<int> &gentaus_id() { return cms3.gentaus_id(); }
	const vector<int> &gentaus__genpsidx() { return cms3.gentaus__genpsidx(); }
	const vector<int> &gentaus_status() { return cms3.gentaus_status(); }
	const vector<bool> &gentaus_fromHardProcessBeforeFSR() { return cms3.gentaus_fromHardProcessBeforeFSR(); }
	const vector<bool> &gentaus_fromHardProcessDecayed() { return cms3.gentaus_fromHardProcessDecayed(); }
	const vector<bool> &gentaus_fromHardProcessFinalState() { return cms3.gentaus_fromHardProcessFinalState(); }
	const vector<bool> &gentaus_isDirectHardProcessTauDecayProductFinalState() { return cms3.gentaus_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gentaus_isDirectPromptTauDecayProductFinalState() { return cms3.gentaus_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gentaus_isHardProcess() { return cms3.gentaus_isHardProcess(); }
	const vector<bool> &gentaus_isLastCopy() { return cms3.gentaus_isLastCopy(); }
	const vector<bool> &gentaus_isLastCopyBeforeFSR() { return cms3.gentaus_isLastCopyBeforeFSR(); }
	const vector<bool> &gentaus_isMostlyLikePythia6Status3() { return cms3.gentaus_isMostlyLikePythia6Status3(); }
	const vector<bool> &gentaus_isPromptDecayed() { return cms3.gentaus_isPromptDecayed(); }
	const vector<bool> &gentaus_isPromptFinalState() { return cms3.gentaus_isPromptFinalState(); }
	const vector<vector<int> > &gentaus_lepdaughter_id() { return cms3.gentaus_lepdaughter_id(); }
	const vector<int> &gentaus_gentaudecay() { return cms3.gentaus_gentaudecay(); }
	const int &gen_nfromttaus_() { return cms3.gen_nfromttaus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_motherp4() { return cms3.gentaus_motherp4(); }
	const vector<float> &gentaus_mothercharge() { return cms3.gentaus_mothercharge(); }
	const vector<int> &gentaus_motherid() { return cms3.gentaus_motherid(); }
	const vector<int> &gentaus_motheridx() { return cms3.gentaus_motheridx(); }
	const vector<int> &gentaus_motherstatus() { return cms3.gentaus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_gmotherp4() { return cms3.gentaus_gmotherp4(); }
	const vector<int> &gentaus_gmothercharge() { return cms3.gentaus_gmothercharge(); }
	const vector<int> &gentaus_gmotherid() { return cms3.gentaus_gmotherid(); }
	const vector<int> &gentaus_gmotheridx() { return cms3.gentaus_gmotheridx(); }
	const vector<int> &gentaus_gmotherstatus() { return cms3.gentaus_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplemotherp4() { return cms3.gentaus_simplemotherp4(); }
	const vector<int> &gentaus_simplemothercharge() { return cms3.gentaus_simplemothercharge(); }
	const vector<int> &gentaus_simplemotherid() { return cms3.gentaus_simplemotherid(); }
	const vector<int> &gentaus_simplemotheridx() { return cms3.gentaus_simplemotheridx(); }
	const vector<int> &gentaus_simplemotherstatus() { return cms3.gentaus_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gentaus_simplegmotherp4() { return cms3.gentaus_simplegmotherp4(); }
	const vector<int> &gentaus_simplegmothercharge() { return cms3.gentaus_simplegmothercharge(); }
	const vector<int> &gentaus_simplegmotherid() { return cms3.gentaus_simplegmotherid(); }
	const vector<int> &gentaus_simplegmotheridx() { return cms3.gentaus_simplegmotheridx(); }
	const vector<int> &gentaus_simplegmotherstatus() { return cms3.gentaus_simplegmotherstatus(); }
	const vector<bool> &gennuels_isfromt() { return cms3.gennuels_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_p4() { return cms3.gennuels_p4(); }
	const vector<float> &gennuels_charge() { return cms3.gennuels_charge(); }
	const vector<float> &gennuels_iso() { return cms3.gennuels_iso(); }
	const vector<float> &gennuels_mass() { return cms3.gennuels_mass(); }
	const vector<int> &gennuels_id() { return cms3.gennuels_id(); }
	const vector<int> &gennuels__genpsidx() { return cms3.gennuels__genpsidx(); }
	const vector<int> &gennuels_status() { return cms3.gennuels_status(); }
	const vector<bool> &gennuels_fromHardProcessBeforeFSR() { return cms3.gennuels_fromHardProcessBeforeFSR(); }
	const vector<bool> &gennuels_fromHardProcessDecayed() { return cms3.gennuels_fromHardProcessDecayed(); }
	const vector<bool> &gennuels_fromHardProcessFinalState() { return cms3.gennuels_fromHardProcessFinalState(); }
	const vector<bool> &gennuels_isDirectHardProcessTauDecayProductFinalState() { return cms3.gennuels_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gennuels_isDirectPromptTauDecayProductFinalState() { return cms3.gennuels_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gennuels_isHardProcess() { return cms3.gennuels_isHardProcess(); }
	const vector<bool> &gennuels_isLastCopy() { return cms3.gennuels_isLastCopy(); }
	const vector<bool> &gennuels_isLastCopyBeforeFSR() { return cms3.gennuels_isLastCopyBeforeFSR(); }
	const vector<bool> &gennuels_isMostlyLikePythia6Status3() { return cms3.gennuels_isMostlyLikePythia6Status3(); }
	const vector<bool> &gennuels_isPromptDecayed() { return cms3.gennuels_isPromptDecayed(); }
	const vector<bool> &gennuels_isPromptFinalState() { return cms3.gennuels_isPromptFinalState(); }
	const vector<vector<int> > &gennuels_lepdaughter_id() { return cms3.gennuels_lepdaughter_id(); }
	const vector<int> &gennuels_gentaudecay() { return cms3.gennuels_gentaudecay(); }
	const int &gen_nfromtnuels_() { return cms3.gen_nfromtnuels_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_motherp4() { return cms3.gennuels_motherp4(); }
	const vector<float> &gennuels_mothercharge() { return cms3.gennuels_mothercharge(); }
	const vector<int> &gennuels_motherid() { return cms3.gennuels_motherid(); }
	const vector<int> &gennuels_motheridx() { return cms3.gennuels_motheridx(); }
	const vector<int> &gennuels_motherstatus() { return cms3.gennuels_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_gmotherp4() { return cms3.gennuels_gmotherp4(); }
	const vector<int> &gennuels_gmothercharge() { return cms3.gennuels_gmothercharge(); }
	const vector<int> &gennuels_gmotherid() { return cms3.gennuels_gmotherid(); }
	const vector<int> &gennuels_gmotheridx() { return cms3.gennuels_gmotheridx(); }
	const vector<int> &gennuels_gmotherstatus() { return cms3.gennuels_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplemotherp4() { return cms3.gennuels_simplemotherp4(); }
	const vector<int> &gennuels_simplemothercharge() { return cms3.gennuels_simplemothercharge(); }
	const vector<int> &gennuels_simplemotherid() { return cms3.gennuels_simplemotherid(); }
	const vector<int> &gennuels_simplemotheridx() { return cms3.gennuels_simplemotheridx(); }
	const vector<int> &gennuels_simplemotherstatus() { return cms3.gennuels_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennuels_simplegmotherp4() { return cms3.gennuels_simplegmotherp4(); }
	const vector<int> &gennuels_simplegmothercharge() { return cms3.gennuels_simplegmothercharge(); }
	const vector<int> &gennuels_simplegmotherid() { return cms3.gennuels_simplegmotherid(); }
	const vector<int> &gennuels_simplegmotheridx() { return cms3.gennuels_simplegmotheridx(); }
	const vector<int> &gennuels_simplegmotherstatus() { return cms3.gennuels_simplegmotherstatus(); }
	const vector<bool> &gennumus_isfromt() { return cms3.gennumus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_p4() { return cms3.gennumus_p4(); }
	const vector<float> &gennumus_charge() { return cms3.gennumus_charge(); }
	const vector<float> &gennumus_iso() { return cms3.gennumus_iso(); }
	const vector<float> &gennumus_mass() { return cms3.gennumus_mass(); }
	const vector<int> &gennumus_id() { return cms3.gennumus_id(); }
	const vector<int> &gennumus__genpsidx() { return cms3.gennumus__genpsidx(); }
	const vector<int> &gennumus_status() { return cms3.gennumus_status(); }
	const vector<bool> &gennumus_fromHardProcessBeforeFSR() { return cms3.gennumus_fromHardProcessBeforeFSR(); }
	const vector<bool> &gennumus_fromHardProcessDecayed() { return cms3.gennumus_fromHardProcessDecayed(); }
	const vector<bool> &gennumus_fromHardProcessFinalState() { return cms3.gennumus_fromHardProcessFinalState(); }
	const vector<bool> &gennumus_isDirectHardProcessTauDecayProductFinalState() { return cms3.gennumus_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gennumus_isDirectPromptTauDecayProductFinalState() { return cms3.gennumus_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gennumus_isHardProcess() { return cms3.gennumus_isHardProcess(); }
	const vector<bool> &gennumus_isLastCopy() { return cms3.gennumus_isLastCopy(); }
	const vector<bool> &gennumus_isLastCopyBeforeFSR() { return cms3.gennumus_isLastCopyBeforeFSR(); }
	const vector<bool> &gennumus_isMostlyLikePythia6Status3() { return cms3.gennumus_isMostlyLikePythia6Status3(); }
	const vector<bool> &gennumus_isPromptDecayed() { return cms3.gennumus_isPromptDecayed(); }
	const vector<bool> &gennumus_isPromptFinalState() { return cms3.gennumus_isPromptFinalState(); }
	const vector<vector<int> > &gennumus_lepdaughter_id() { return cms3.gennumus_lepdaughter_id(); }
	const vector<int> &gennumus_gentaudecay() { return cms3.gennumus_gentaudecay(); }
	const int &gen_nfromtnumus_() { return cms3.gen_nfromtnumus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_motherp4() { return cms3.gennumus_motherp4(); }
	const vector<float> &gennumus_mothercharge() { return cms3.gennumus_mothercharge(); }
	const vector<int> &gennumus_motherid() { return cms3.gennumus_motherid(); }
	const vector<int> &gennumus_motheridx() { return cms3.gennumus_motheridx(); }
	const vector<int> &gennumus_motherstatus() { return cms3.gennumus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_gmotherp4() { return cms3.gennumus_gmotherp4(); }
	const vector<int> &gennumus_gmothercharge() { return cms3.gennumus_gmothercharge(); }
	const vector<int> &gennumus_gmotherid() { return cms3.gennumus_gmotherid(); }
	const vector<int> &gennumus_gmotheridx() { return cms3.gennumus_gmotheridx(); }
	const vector<int> &gennumus_gmotherstatus() { return cms3.gennumus_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplemotherp4() { return cms3.gennumus_simplemotherp4(); }
	const vector<int> &gennumus_simplemothercharge() { return cms3.gennumus_simplemothercharge(); }
	const vector<int> &gennumus_simplemotherid() { return cms3.gennumus_simplemotherid(); }
	const vector<int> &gennumus_simplemotheridx() { return cms3.gennumus_simplemotheridx(); }
	const vector<int> &gennumus_simplemotherstatus() { return cms3.gennumus_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennumus_simplegmotherp4() { return cms3.gennumus_simplegmotherp4(); }
	const vector<int> &gennumus_simplegmothercharge() { return cms3.gennumus_simplegmothercharge(); }
	const vector<int> &gennumus_simplegmotherid() { return cms3.gennumus_simplegmotherid(); }
	const vector<int> &gennumus_simplegmotheridx() { return cms3.gennumus_simplegmotheridx(); }
	const vector<int> &gennumus_simplegmotherstatus() { return cms3.gennumus_simplegmotherstatus(); }
	const vector<bool> &gennutaus_isfromt() { return cms3.gennutaus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_p4() { return cms3.gennutaus_p4(); }
	const vector<float> &gennutaus_charge() { return cms3.gennutaus_charge(); }
	const vector<float> &gennutaus_iso() { return cms3.gennutaus_iso(); }
	const vector<float> &gennutaus_mass() { return cms3.gennutaus_mass(); }
	const vector<int> &gennutaus_id() { return cms3.gennutaus_id(); }
	const vector<int> &gennutaus__genpsidx() { return cms3.gennutaus__genpsidx(); }
	const vector<int> &gennutaus_status() { return cms3.gennutaus_status(); }
	const vector<bool> &gennutaus_fromHardProcessBeforeFSR() { return cms3.gennutaus_fromHardProcessBeforeFSR(); }
	const vector<bool> &gennutaus_fromHardProcessDecayed() { return cms3.gennutaus_fromHardProcessDecayed(); }
	const vector<bool> &gennutaus_fromHardProcessFinalState() { return cms3.gennutaus_fromHardProcessFinalState(); }
	const vector<bool> &gennutaus_isDirectHardProcessTauDecayProductFinalState() { return cms3.gennutaus_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gennutaus_isDirectPromptTauDecayProductFinalState() { return cms3.gennutaus_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gennutaus_isHardProcess() { return cms3.gennutaus_isHardProcess(); }
	const vector<bool> &gennutaus_isLastCopy() { return cms3.gennutaus_isLastCopy(); }
	const vector<bool> &gennutaus_isLastCopyBeforeFSR() { return cms3.gennutaus_isLastCopyBeforeFSR(); }
	const vector<bool> &gennutaus_isMostlyLikePythia6Status3() { return cms3.gennutaus_isMostlyLikePythia6Status3(); }
	const vector<bool> &gennutaus_isPromptDecayed() { return cms3.gennutaus_isPromptDecayed(); }
	const vector<bool> &gennutaus_isPromptFinalState() { return cms3.gennutaus_isPromptFinalState(); }
	const vector<vector<int> > &gennutaus_lepdaughter_id() { return cms3.gennutaus_lepdaughter_id(); }
	const vector<int> &gennutaus_gentaudecay() { return cms3.gennutaus_gentaudecay(); }
	const int &gen_nfromtnutaus_() { return cms3.gen_nfromtnutaus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_motherp4() { return cms3.gennutaus_motherp4(); }
	const vector<float> &gennutaus_mothercharge() { return cms3.gennutaus_mothercharge(); }
	const vector<int> &gennutaus_motherid() { return cms3.gennutaus_motherid(); }
	const vector<int> &gennutaus_motheridx() { return cms3.gennutaus_motheridx(); }
	const vector<int> &gennutaus_motherstatus() { return cms3.gennutaus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_gmotherp4() { return cms3.gennutaus_gmotherp4(); }
	const vector<int> &gennutaus_gmothercharge() { return cms3.gennutaus_gmothercharge(); }
	const vector<int> &gennutaus_gmotherid() { return cms3.gennutaus_gmotherid(); }
	const vector<int> &gennutaus_gmotheridx() { return cms3.gennutaus_gmotheridx(); }
	const vector<int> &gennutaus_gmotherstatus() { return cms3.gennutaus_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplemotherp4() { return cms3.gennutaus_simplemotherp4(); }
	const vector<int> &gennutaus_simplemothercharge() { return cms3.gennutaus_simplemothercharge(); }
	const vector<int> &gennutaus_simplemotherid() { return cms3.gennutaus_simplemotherid(); }
	const vector<int> &gennutaus_simplemotheridx() { return cms3.gennutaus_simplemotheridx(); }
	const vector<int> &gennutaus_simplemotherstatus() { return cms3.gennutaus_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennutaus_simplegmotherp4() { return cms3.gennutaus_simplegmotherp4(); }
	const vector<int> &gennutaus_simplegmothercharge() { return cms3.gennutaus_simplegmothercharge(); }
	const vector<int> &gennutaus_simplegmotherid() { return cms3.gennutaus_simplegmotherid(); }
	const vector<int> &gennutaus_simplegmotheridx() { return cms3.gennutaus_simplegmotheridx(); }
	const vector<int> &gennutaus_simplegmotherstatus() { return cms3.gennutaus_simplegmotherstatus(); }
	const vector<bool> &gents_isfromt() { return cms3.gents_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4() { return cms3.gents_p4(); }
	const vector<float> &gents_charge() { return cms3.gents_charge(); }
	const vector<float> &gents_iso() { return cms3.gents_iso(); }
	const vector<float> &gents_mass() { return cms3.gents_mass(); }
	const vector<int> &gents_id() { return cms3.gents_id(); }
	const vector<int> &gents__genpsidx() { return cms3.gents__genpsidx(); }
	const vector<int> &gents_status() { return cms3.gents_status(); }
	const vector<bool> &gents_fromHardProcessBeforeFSR() { return cms3.gents_fromHardProcessBeforeFSR(); }
	const vector<bool> &gents_fromHardProcessDecayed() { return cms3.gents_fromHardProcessDecayed(); }
	const vector<bool> &gents_fromHardProcessFinalState() { return cms3.gents_fromHardProcessFinalState(); }
	const vector<bool> &gents_isDirectHardProcessTauDecayProductFinalState() { return cms3.gents_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gents_isDirectPromptTauDecayProductFinalState() { return cms3.gents_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gents_isHardProcess() { return cms3.gents_isHardProcess(); }
	const vector<bool> &gents_isLastCopy() { return cms3.gents_isLastCopy(); }
	const vector<bool> &gents_isLastCopyBeforeFSR() { return cms3.gents_isLastCopyBeforeFSR(); }
	const vector<bool> &gents_isMostlyLikePythia6Status3() { return cms3.gents_isMostlyLikePythia6Status3(); }
	const vector<bool> &gents_isPromptDecayed() { return cms3.gents_isPromptDecayed(); }
	const vector<bool> &gents_isPromptFinalState() { return cms3.gents_isPromptFinalState(); }
	const vector<vector<int> > &gents_lepdaughter_id() { return cms3.gents_lepdaughter_id(); }
	const vector<int> &gents_gentaudecay() { return cms3.gents_gentaudecay(); }
	const int &gen_nfromtts_() { return cms3.gen_nfromtts_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4() { return cms3.gents_motherp4(); }
	const vector<float> &gents_mothercharge() { return cms3.gents_mothercharge(); }
	const vector<int> &gents_motherid() { return cms3.gents_motherid(); }
	const vector<int> &gents_motheridx() { return cms3.gents_motheridx(); }
	const vector<int> &gents_motherstatus() { return cms3.gents_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_gmotherp4() { return cms3.gents_gmotherp4(); }
	const vector<int> &gents_gmothercharge() { return cms3.gents_gmothercharge(); }
	const vector<int> &gents_gmotherid() { return cms3.gents_gmotherid(); }
	const vector<int> &gents_gmotheridx() { return cms3.gents_gmotheridx(); }
	const vector<int> &gents_gmotherstatus() { return cms3.gents_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplemotherp4() { return cms3.gents_simplemotherp4(); }
	const vector<int> &gents_simplemothercharge() { return cms3.gents_simplemothercharge(); }
	const vector<int> &gents_simplemotherid() { return cms3.gents_simplemotherid(); }
	const vector<int> &gents_simplemotheridx() { return cms3.gents_simplemotheridx(); }
	const vector<int> &gents_simplemotherstatus() { return cms3.gents_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_simplegmotherp4() { return cms3.gents_simplegmotherp4(); }
	const vector<int> &gents_simplegmothercharge() { return cms3.gents_simplegmothercharge(); }
	const vector<int> &gents_simplegmotherid() { return cms3.gents_simplegmotherid(); }
	const vector<int> &gents_simplegmotheridx() { return cms3.gents_simplegmotheridx(); }
	const vector<int> &gents_simplegmotherstatus() { return cms3.gents_simplegmotherstatus(); }
	const vector<bool> &genbs_isfromt() { return cms3.genbs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_p4() { return cms3.genbs_p4(); }
	const vector<float> &genbs_charge() { return cms3.genbs_charge(); }
	const vector<float> &genbs_iso() { return cms3.genbs_iso(); }
	const vector<float> &genbs_mass() { return cms3.genbs_mass(); }
	const vector<int> &genbs_id() { return cms3.genbs_id(); }
	const vector<int> &genbs__genpsidx() { return cms3.genbs__genpsidx(); }
	const vector<int> &genbs_status() { return cms3.genbs_status(); }
	const vector<bool> &genbs_fromHardProcessBeforeFSR() { return cms3.genbs_fromHardProcessBeforeFSR(); }
	const vector<bool> &genbs_fromHardProcessDecayed() { return cms3.genbs_fromHardProcessDecayed(); }
	const vector<bool> &genbs_fromHardProcessFinalState() { return cms3.genbs_fromHardProcessFinalState(); }
	const vector<bool> &genbs_isDirectHardProcessTauDecayProductFinalState() { return cms3.genbs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genbs_isDirectPromptTauDecayProductFinalState() { return cms3.genbs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genbs_isHardProcess() { return cms3.genbs_isHardProcess(); }
	const vector<bool> &genbs_isLastCopy() { return cms3.genbs_isLastCopy(); }
	const vector<bool> &genbs_isLastCopyBeforeFSR() { return cms3.genbs_isLastCopyBeforeFSR(); }
	const vector<bool> &genbs_isMostlyLikePythia6Status3() { return cms3.genbs_isMostlyLikePythia6Status3(); }
	const vector<bool> &genbs_isPromptDecayed() { return cms3.genbs_isPromptDecayed(); }
	const vector<bool> &genbs_isPromptFinalState() { return cms3.genbs_isPromptFinalState(); }
	const vector<vector<int> > &genbs_lepdaughter_id() { return cms3.genbs_lepdaughter_id(); }
	const vector<int> &genbs_gentaudecay() { return cms3.genbs_gentaudecay(); }
	const int &gen_nfromtbs_() { return cms3.gen_nfromtbs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_motherp4() { return cms3.genbs_motherp4(); }
	const vector<float> &genbs_mothercharge() { return cms3.genbs_mothercharge(); }
	const vector<int> &genbs_motherid() { return cms3.genbs_motherid(); }
	const vector<int> &genbs_motheridx() { return cms3.genbs_motheridx(); }
	const vector<int> &genbs_motherstatus() { return cms3.genbs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_gmotherp4() { return cms3.genbs_gmotherp4(); }
	const vector<int> &genbs_gmothercharge() { return cms3.genbs_gmothercharge(); }
	const vector<int> &genbs_gmotherid() { return cms3.genbs_gmotherid(); }
	const vector<int> &genbs_gmotheridx() { return cms3.genbs_gmotheridx(); }
	const vector<int> &genbs_gmotherstatus() { return cms3.genbs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplemotherp4() { return cms3.genbs_simplemotherp4(); }
	const vector<int> &genbs_simplemothercharge() { return cms3.genbs_simplemothercharge(); }
	const vector<int> &genbs_simplemotherid() { return cms3.genbs_simplemotherid(); }
	const vector<int> &genbs_simplemotheridx() { return cms3.genbs_simplemotheridx(); }
	const vector<int> &genbs_simplemotherstatus() { return cms3.genbs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbs_simplegmotherp4() { return cms3.genbs_simplegmotherp4(); }
	const vector<int> &genbs_simplegmothercharge() { return cms3.genbs_simplegmothercharge(); }
	const vector<int> &genbs_simplegmotherid() { return cms3.genbs_simplegmotherid(); }
	const vector<int> &genbs_simplegmotheridx() { return cms3.genbs_simplegmotheridx(); }
	const vector<int> &genbs_simplegmotherstatus() { return cms3.genbs_simplegmotherstatus(); }
	const vector<bool> &gencs_isfromt() { return cms3.gencs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_p4() { return cms3.gencs_p4(); }
	const vector<float> &gencs_charge() { return cms3.gencs_charge(); }
	const vector<float> &gencs_iso() { return cms3.gencs_iso(); }
	const vector<float> &gencs_mass() { return cms3.gencs_mass(); }
	const vector<int> &gencs_id() { return cms3.gencs_id(); }
	const vector<int> &gencs__genpsidx() { return cms3.gencs__genpsidx(); }
	const vector<int> &gencs_status() { return cms3.gencs_status(); }
	const vector<bool> &gencs_fromHardProcessBeforeFSR() { return cms3.gencs_fromHardProcessBeforeFSR(); }
	const vector<bool> &gencs_fromHardProcessDecayed() { return cms3.gencs_fromHardProcessDecayed(); }
	const vector<bool> &gencs_fromHardProcessFinalState() { return cms3.gencs_fromHardProcessFinalState(); }
	const vector<bool> &gencs_isDirectHardProcessTauDecayProductFinalState() { return cms3.gencs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &gencs_isDirectPromptTauDecayProductFinalState() { return cms3.gencs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &gencs_isHardProcess() { return cms3.gencs_isHardProcess(); }
	const vector<bool> &gencs_isLastCopy() { return cms3.gencs_isLastCopy(); }
	const vector<bool> &gencs_isLastCopyBeforeFSR() { return cms3.gencs_isLastCopyBeforeFSR(); }
	const vector<bool> &gencs_isMostlyLikePythia6Status3() { return cms3.gencs_isMostlyLikePythia6Status3(); }
	const vector<bool> &gencs_isPromptDecayed() { return cms3.gencs_isPromptDecayed(); }
	const vector<bool> &gencs_isPromptFinalState() { return cms3.gencs_isPromptFinalState(); }
	const vector<vector<int> > &gencs_lepdaughter_id() { return cms3.gencs_lepdaughter_id(); }
	const vector<int> &gencs_gentaudecay() { return cms3.gencs_gentaudecay(); }
	const int &gen_nfromtcs_() { return cms3.gen_nfromtcs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_motherp4() { return cms3.gencs_motherp4(); }
	const vector<float> &gencs_mothercharge() { return cms3.gencs_mothercharge(); }
	const vector<int> &gencs_motherid() { return cms3.gencs_motherid(); }
	const vector<int> &gencs_motheridx() { return cms3.gencs_motheridx(); }
	const vector<int> &gencs_motherstatus() { return cms3.gencs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_gmotherp4() { return cms3.gencs_gmotherp4(); }
	const vector<int> &gencs_gmothercharge() { return cms3.gencs_gmothercharge(); }
	const vector<int> &gencs_gmotherid() { return cms3.gencs_gmotherid(); }
	const vector<int> &gencs_gmotheridx() { return cms3.gencs_gmotheridx(); }
	const vector<int> &gencs_gmotherstatus() { return cms3.gencs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplemotherp4() { return cms3.gencs_simplemotherp4(); }
	const vector<int> &gencs_simplemothercharge() { return cms3.gencs_simplemothercharge(); }
	const vector<int> &gencs_simplemotherid() { return cms3.gencs_simplemotherid(); }
	const vector<int> &gencs_simplemotheridx() { return cms3.gencs_simplemotheridx(); }
	const vector<int> &gencs_simplemotherstatus() { return cms3.gencs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gencs_simplegmotherp4() { return cms3.gencs_simplegmotherp4(); }
	const vector<int> &gencs_simplegmothercharge() { return cms3.gencs_simplegmothercharge(); }
	const vector<int> &gencs_simplegmotherid() { return cms3.gencs_simplegmotherid(); }
	const vector<int> &gencs_simplegmotheridx() { return cms3.gencs_simplegmotheridx(); }
	const vector<int> &gencs_simplegmotherstatus() { return cms3.gencs_simplegmotherstatus(); }
	const vector<bool> &genqs_isfromt() { return cms3.genqs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4() { return cms3.genqs_p4(); }
	const vector<float> &genqs_charge() { return cms3.genqs_charge(); }
	const vector<float> &genqs_iso() { return cms3.genqs_iso(); }
	const vector<float> &genqs_mass() { return cms3.genqs_mass(); }
	const vector<int> &genqs_id() { return cms3.genqs_id(); }
	const vector<int> &genqs__genpsidx() { return cms3.genqs__genpsidx(); }
	const vector<int> &genqs_status() { return cms3.genqs_status(); }
	const vector<bool> &genqs_fromHardProcessBeforeFSR() { return cms3.genqs_fromHardProcessBeforeFSR(); }
	const vector<bool> &genqs_fromHardProcessDecayed() { return cms3.genqs_fromHardProcessDecayed(); }
	const vector<bool> &genqs_fromHardProcessFinalState() { return cms3.genqs_fromHardProcessFinalState(); }
	const vector<bool> &genqs_isDirectHardProcessTauDecayProductFinalState() { return cms3.genqs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genqs_isDirectPromptTauDecayProductFinalState() { return cms3.genqs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genqs_isHardProcess() { return cms3.genqs_isHardProcess(); }
	const vector<bool> &genqs_isLastCopy() { return cms3.genqs_isLastCopy(); }
	const vector<bool> &genqs_isLastCopyBeforeFSR() { return cms3.genqs_isLastCopyBeforeFSR(); }
	const vector<bool> &genqs_isMostlyLikePythia6Status3() { return cms3.genqs_isMostlyLikePythia6Status3(); }
	const vector<bool> &genqs_isPromptDecayed() { return cms3.genqs_isPromptDecayed(); }
	const vector<bool> &genqs_isPromptFinalState() { return cms3.genqs_isPromptFinalState(); }
	const vector<vector<int> > &genqs_lepdaughter_id() { return cms3.genqs_lepdaughter_id(); }
	const vector<int> &genqs_gentaudecay() { return cms3.genqs_gentaudecay(); }
	const int &gen_nfromtqs_() { return cms3.gen_nfromtqs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4() { return cms3.genqs_motherp4(); }
	const vector<float> &genqs_mothercharge() { return cms3.genqs_mothercharge(); }
	const vector<int> &genqs_motherid() { return cms3.genqs_motherid(); }
	const vector<int> &genqs_motheridx() { return cms3.genqs_motheridx(); }
	const vector<int> &genqs_motherstatus() { return cms3.genqs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4() { return cms3.genqs_gmotherp4(); }
	const vector<int> &genqs_gmothercharge() { return cms3.genqs_gmothercharge(); }
	const vector<int> &genqs_gmotherid() { return cms3.genqs_gmotherid(); }
	const vector<int> &genqs_gmotheridx() { return cms3.genqs_gmotheridx(); }
	const vector<int> &genqs_gmotherstatus() { return cms3.genqs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplemotherp4() { return cms3.genqs_simplemotherp4(); }
	const vector<int> &genqs_simplemothercharge() { return cms3.genqs_simplemothercharge(); }
	const vector<int> &genqs_simplemotherid() { return cms3.genqs_simplemotherid(); }
	const vector<int> &genqs_simplemotheridx() { return cms3.genqs_simplemotheridx(); }
	const vector<int> &genqs_simplemotherstatus() { return cms3.genqs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_simplegmotherp4() { return cms3.genqs_simplegmotherp4(); }
	const vector<int> &genqs_simplegmothercharge() { return cms3.genqs_simplegmothercharge(); }
	const vector<int> &genqs_simplegmotherid() { return cms3.genqs_simplegmotherid(); }
	const vector<int> &genqs_simplegmotheridx() { return cms3.genqs_simplegmotheridx(); }
	const vector<int> &genqs_simplegmotherstatus() { return cms3.genqs_simplegmotherstatus(); }
	const vector<bool> &genglus_isfromt() { return cms3.genglus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_p4() { return cms3.genglus_p4(); }
	const vector<float> &genglus_charge() { return cms3.genglus_charge(); }
	const vector<float> &genglus_iso() { return cms3.genglus_iso(); }
	const vector<float> &genglus_mass() { return cms3.genglus_mass(); }
	const vector<int> &genglus_id() { return cms3.genglus_id(); }
	const vector<int> &genglus__genpsidx() { return cms3.genglus__genpsidx(); }
	const vector<int> &genglus_status() { return cms3.genglus_status(); }
	const vector<bool> &genglus_fromHardProcessBeforeFSR() { return cms3.genglus_fromHardProcessBeforeFSR(); }
	const vector<bool> &genglus_fromHardProcessDecayed() { return cms3.genglus_fromHardProcessDecayed(); }
	const vector<bool> &genglus_fromHardProcessFinalState() { return cms3.genglus_fromHardProcessFinalState(); }
	const vector<bool> &genglus_isDirectHardProcessTauDecayProductFinalState() { return cms3.genglus_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genglus_isDirectPromptTauDecayProductFinalState() { return cms3.genglus_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genglus_isHardProcess() { return cms3.genglus_isHardProcess(); }
	const vector<bool> &genglus_isLastCopy() { return cms3.genglus_isLastCopy(); }
	const vector<bool> &genglus_isLastCopyBeforeFSR() { return cms3.genglus_isLastCopyBeforeFSR(); }
	const vector<bool> &genglus_isMostlyLikePythia6Status3() { return cms3.genglus_isMostlyLikePythia6Status3(); }
	const vector<bool> &genglus_isPromptDecayed() { return cms3.genglus_isPromptDecayed(); }
	const vector<bool> &genglus_isPromptFinalState() { return cms3.genglus_isPromptFinalState(); }
	const vector<vector<int> > &genglus_lepdaughter_id() { return cms3.genglus_lepdaughter_id(); }
	const vector<int> &genglus_gentaudecay() { return cms3.genglus_gentaudecay(); }
	const int &gen_nfromtglus_() { return cms3.gen_nfromtglus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_motherp4() { return cms3.genglus_motherp4(); }
	const vector<float> &genglus_mothercharge() { return cms3.genglus_mothercharge(); }
	const vector<int> &genglus_motherid() { return cms3.genglus_motherid(); }
	const vector<int> &genglus_motheridx() { return cms3.genglus_motheridx(); }
	const vector<int> &genglus_motherstatus() { return cms3.genglus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_gmotherp4() { return cms3.genglus_gmotherp4(); }
	const vector<int> &genglus_gmothercharge() { return cms3.genglus_gmothercharge(); }
	const vector<int> &genglus_gmotherid() { return cms3.genglus_gmotherid(); }
	const vector<int> &genglus_gmotheridx() { return cms3.genglus_gmotheridx(); }
	const vector<int> &genglus_gmotherstatus() { return cms3.genglus_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplemotherp4() { return cms3.genglus_simplemotherp4(); }
	const vector<int> &genglus_simplemothercharge() { return cms3.genglus_simplemothercharge(); }
	const vector<int> &genglus_simplemotherid() { return cms3.genglus_simplemotherid(); }
	const vector<int> &genglus_simplemotheridx() { return cms3.genglus_simplemotheridx(); }
	const vector<int> &genglus_simplemotherstatus() { return cms3.genglus_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genglus_simplegmotherp4() { return cms3.genglus_simplegmotherp4(); }
	const vector<int> &genglus_simplegmothercharge() { return cms3.genglus_simplegmothercharge(); }
	const vector<int> &genglus_simplegmotherid() { return cms3.genglus_simplegmotherid(); }
	const vector<int> &genglus_simplegmotheridx() { return cms3.genglus_simplegmotheridx(); }
	const vector<int> &genglus_simplegmotherstatus() { return cms3.genglus_simplegmotherstatus(); }
	const vector<bool> &genws_isfromt() { return cms3.genws_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_p4() { return cms3.genws_p4(); }
	const vector<float> &genws_charge() { return cms3.genws_charge(); }
	const vector<float> &genws_iso() { return cms3.genws_iso(); }
	const vector<float> &genws_mass() { return cms3.genws_mass(); }
	const vector<int> &genws_id() { return cms3.genws_id(); }
	const vector<int> &genws__genpsidx() { return cms3.genws__genpsidx(); }
	const vector<int> &genws_status() { return cms3.genws_status(); }
	const vector<bool> &genws_fromHardProcessBeforeFSR() { return cms3.genws_fromHardProcessBeforeFSR(); }
	const vector<bool> &genws_fromHardProcessDecayed() { return cms3.genws_fromHardProcessDecayed(); }
	const vector<bool> &genws_fromHardProcessFinalState() { return cms3.genws_fromHardProcessFinalState(); }
	const vector<bool> &genws_isDirectHardProcessTauDecayProductFinalState() { return cms3.genws_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genws_isDirectPromptTauDecayProductFinalState() { return cms3.genws_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genws_isHardProcess() { return cms3.genws_isHardProcess(); }
	const vector<bool> &genws_isLastCopy() { return cms3.genws_isLastCopy(); }
	const vector<bool> &genws_isLastCopyBeforeFSR() { return cms3.genws_isLastCopyBeforeFSR(); }
	const vector<bool> &genws_isMostlyLikePythia6Status3() { return cms3.genws_isMostlyLikePythia6Status3(); }
	const vector<bool> &genws_isPromptDecayed() { return cms3.genws_isPromptDecayed(); }
	const vector<bool> &genws_isPromptFinalState() { return cms3.genws_isPromptFinalState(); }
	const vector<vector<int> > &genws_lepdaughter_id() { return cms3.genws_lepdaughter_id(); }
	const vector<int> &genws_gentaudecay() { return cms3.genws_gentaudecay(); }
	const int &gen_nfromtws_() { return cms3.gen_nfromtws_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_motherp4() { return cms3.genws_motherp4(); }
	const vector<float> &genws_mothercharge() { return cms3.genws_mothercharge(); }
	const vector<int> &genws_motherid() { return cms3.genws_motherid(); }
	const vector<int> &genws_motheridx() { return cms3.genws_motheridx(); }
	const vector<int> &genws_motherstatus() { return cms3.genws_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_gmotherp4() { return cms3.genws_gmotherp4(); }
	const vector<int> &genws_gmothercharge() { return cms3.genws_gmothercharge(); }
	const vector<int> &genws_gmotherid() { return cms3.genws_gmotherid(); }
	const vector<int> &genws_gmotheridx() { return cms3.genws_gmotheridx(); }
	const vector<int> &genws_gmotherstatus() { return cms3.genws_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplemotherp4() { return cms3.genws_simplemotherp4(); }
	const vector<int> &genws_simplemothercharge() { return cms3.genws_simplemothercharge(); }
	const vector<int> &genws_simplemotherid() { return cms3.genws_simplemotherid(); }
	const vector<int> &genws_simplemotheridx() { return cms3.genws_simplemotheridx(); }
	const vector<int> &genws_simplemotherstatus() { return cms3.genws_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genws_simplegmotherp4() { return cms3.genws_simplegmotherp4(); }
	const vector<int> &genws_simplegmothercharge() { return cms3.genws_simplegmothercharge(); }
	const vector<int> &genws_simplegmotherid() { return cms3.genws_simplegmotherid(); }
	const vector<int> &genws_simplegmotheridx() { return cms3.genws_simplegmotheridx(); }
	const vector<int> &genws_simplegmotherstatus() { return cms3.genws_simplegmotherstatus(); }
	const vector<bool> &genzs_isfromt() { return cms3.genzs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_p4() { return cms3.genzs_p4(); }
	const vector<float> &genzs_charge() { return cms3.genzs_charge(); }
	const vector<float> &genzs_iso() { return cms3.genzs_iso(); }
	const vector<float> &genzs_mass() { return cms3.genzs_mass(); }
	const vector<int> &genzs_id() { return cms3.genzs_id(); }
	const vector<int> &genzs__genpsidx() { return cms3.genzs__genpsidx(); }
	const vector<int> &genzs_status() { return cms3.genzs_status(); }
	const vector<bool> &genzs_fromHardProcessBeforeFSR() { return cms3.genzs_fromHardProcessBeforeFSR(); }
	const vector<bool> &genzs_fromHardProcessDecayed() { return cms3.genzs_fromHardProcessDecayed(); }
	const vector<bool> &genzs_fromHardProcessFinalState() { return cms3.genzs_fromHardProcessFinalState(); }
	const vector<bool> &genzs_isDirectHardProcessTauDecayProductFinalState() { return cms3.genzs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genzs_isDirectPromptTauDecayProductFinalState() { return cms3.genzs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genzs_isHardProcess() { return cms3.genzs_isHardProcess(); }
	const vector<bool> &genzs_isLastCopy() { return cms3.genzs_isLastCopy(); }
	const vector<bool> &genzs_isLastCopyBeforeFSR() { return cms3.genzs_isLastCopyBeforeFSR(); }
	const vector<bool> &genzs_isMostlyLikePythia6Status3() { return cms3.genzs_isMostlyLikePythia6Status3(); }
	const vector<bool> &genzs_isPromptDecayed() { return cms3.genzs_isPromptDecayed(); }
	const vector<bool> &genzs_isPromptFinalState() { return cms3.genzs_isPromptFinalState(); }
	const vector<vector<int> > &genzs_lepdaughter_id() { return cms3.genzs_lepdaughter_id(); }
	const vector<int> &genzs_gentaudecay() { return cms3.genzs_gentaudecay(); }
	const int &gen_nfromtzs_() { return cms3.gen_nfromtzs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_motherp4() { return cms3.genzs_motherp4(); }
	const vector<float> &genzs_mothercharge() { return cms3.genzs_mothercharge(); }
	const vector<int> &genzs_motherid() { return cms3.genzs_motherid(); }
	const vector<int> &genzs_motheridx() { return cms3.genzs_motheridx(); }
	const vector<int> &genzs_motherstatus() { return cms3.genzs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_gmotherp4() { return cms3.genzs_gmotherp4(); }
	const vector<int> &genzs_gmothercharge() { return cms3.genzs_gmothercharge(); }
	const vector<int> &genzs_gmotherid() { return cms3.genzs_gmotherid(); }
	const vector<int> &genzs_gmotheridx() { return cms3.genzs_gmotheridx(); }
	const vector<int> &genzs_gmotherstatus() { return cms3.genzs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplemotherp4() { return cms3.genzs_simplemotherp4(); }
	const vector<int> &genzs_simplemothercharge() { return cms3.genzs_simplemothercharge(); }
	const vector<int> &genzs_simplemotherid() { return cms3.genzs_simplemotherid(); }
	const vector<int> &genzs_simplemotheridx() { return cms3.genzs_simplemotheridx(); }
	const vector<int> &genzs_simplemotherstatus() { return cms3.genzs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genzs_simplegmotherp4() { return cms3.genzs_simplegmotherp4(); }
	const vector<int> &genzs_simplegmothercharge() { return cms3.genzs_simplegmothercharge(); }
	const vector<int> &genzs_simplegmotherid() { return cms3.genzs_simplegmotherid(); }
	const vector<int> &genzs_simplegmotheridx() { return cms3.genzs_simplegmotheridx(); }
	const vector<int> &genzs_simplegmotherstatus() { return cms3.genzs_simplegmotherstatus(); }
	const vector<bool> &genphs_isfromt() { return cms3.genphs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_p4() { return cms3.genphs_p4(); }
	const vector<float> &genphs_charge() { return cms3.genphs_charge(); }
	const vector<float> &genphs_iso() { return cms3.genphs_iso(); }
	const vector<float> &genphs_mass() { return cms3.genphs_mass(); }
	const vector<int> &genphs_id() { return cms3.genphs_id(); }
	const vector<int> &genphs__genpsidx() { return cms3.genphs__genpsidx(); }
	const vector<int> &genphs_status() { return cms3.genphs_status(); }
	const vector<bool> &genphs_fromHardProcessBeforeFSR() { return cms3.genphs_fromHardProcessBeforeFSR(); }
	const vector<bool> &genphs_fromHardProcessDecayed() { return cms3.genphs_fromHardProcessDecayed(); }
	const vector<bool> &genphs_fromHardProcessFinalState() { return cms3.genphs_fromHardProcessFinalState(); }
	const vector<bool> &genphs_isDirectHardProcessTauDecayProductFinalState() { return cms3.genphs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genphs_isDirectPromptTauDecayProductFinalState() { return cms3.genphs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genphs_isHardProcess() { return cms3.genphs_isHardProcess(); }
	const vector<bool> &genphs_isLastCopy() { return cms3.genphs_isLastCopy(); }
	const vector<bool> &genphs_isLastCopyBeforeFSR() { return cms3.genphs_isLastCopyBeforeFSR(); }
	const vector<bool> &genphs_isMostlyLikePythia6Status3() { return cms3.genphs_isMostlyLikePythia6Status3(); }
	const vector<bool> &genphs_isPromptDecayed() { return cms3.genphs_isPromptDecayed(); }
	const vector<bool> &genphs_isPromptFinalState() { return cms3.genphs_isPromptFinalState(); }
	const vector<vector<int> > &genphs_lepdaughter_id() { return cms3.genphs_lepdaughter_id(); }
	const vector<int> &genphs_gentaudecay() { return cms3.genphs_gentaudecay(); }
	const int &gen_nfromtphs_() { return cms3.gen_nfromtphs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_motherp4() { return cms3.genphs_motherp4(); }
	const vector<float> &genphs_mothercharge() { return cms3.genphs_mothercharge(); }
	const vector<int> &genphs_motherid() { return cms3.genphs_motherid(); }
	const vector<int> &genphs_motheridx() { return cms3.genphs_motheridx(); }
	const vector<int> &genphs_motherstatus() { return cms3.genphs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_gmotherp4() { return cms3.genphs_gmotherp4(); }
	const vector<int> &genphs_gmothercharge() { return cms3.genphs_gmothercharge(); }
	const vector<int> &genphs_gmotherid() { return cms3.genphs_gmotherid(); }
	const vector<int> &genphs_gmotheridx() { return cms3.genphs_gmotheridx(); }
	const vector<int> &genphs_gmotherstatus() { return cms3.genphs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplemotherp4() { return cms3.genphs_simplemotherp4(); }
	const vector<int> &genphs_simplemothercharge() { return cms3.genphs_simplemothercharge(); }
	const vector<int> &genphs_simplemotherid() { return cms3.genphs_simplemotherid(); }
	const vector<int> &genphs_simplemotheridx() { return cms3.genphs_simplemotheridx(); }
	const vector<int> &genphs_simplemotherstatus() { return cms3.genphs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genphs_simplegmotherp4() { return cms3.genphs_simplegmotherp4(); }
	const vector<int> &genphs_simplegmothercharge() { return cms3.genphs_simplegmothercharge(); }
	const vector<int> &genphs_simplegmotherid() { return cms3.genphs_simplegmotherid(); }
	const vector<int> &genphs_simplegmotheridx() { return cms3.genphs_simplegmotheridx(); }
	const vector<int> &genphs_simplegmotherstatus() { return cms3.genphs_simplegmotherstatus(); }
	const vector<bool> &genhs_isfromt() { return cms3.genhs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_p4() { return cms3.genhs_p4(); }
	const vector<float> &genhs_charge() { return cms3.genhs_charge(); }
	const vector<float> &genhs_iso() { return cms3.genhs_iso(); }
	const vector<float> &genhs_mass() { return cms3.genhs_mass(); }
	const vector<int> &genhs_id() { return cms3.genhs_id(); }
	const vector<int> &genhs__genpsidx() { return cms3.genhs__genpsidx(); }
	const vector<int> &genhs_status() { return cms3.genhs_status(); }
	const vector<bool> &genhs_fromHardProcessBeforeFSR() { return cms3.genhs_fromHardProcessBeforeFSR(); }
	const vector<bool> &genhs_fromHardProcessDecayed() { return cms3.genhs_fromHardProcessDecayed(); }
	const vector<bool> &genhs_fromHardProcessFinalState() { return cms3.genhs_fromHardProcessFinalState(); }
	const vector<bool> &genhs_isDirectHardProcessTauDecayProductFinalState() { return cms3.genhs_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genhs_isDirectPromptTauDecayProductFinalState() { return cms3.genhs_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genhs_isHardProcess() { return cms3.genhs_isHardProcess(); }
	const vector<bool> &genhs_isLastCopy() { return cms3.genhs_isLastCopy(); }
	const vector<bool> &genhs_isLastCopyBeforeFSR() { return cms3.genhs_isLastCopyBeforeFSR(); }
	const vector<bool> &genhs_isMostlyLikePythia6Status3() { return cms3.genhs_isMostlyLikePythia6Status3(); }
	const vector<bool> &genhs_isPromptDecayed() { return cms3.genhs_isPromptDecayed(); }
	const vector<bool> &genhs_isPromptFinalState() { return cms3.genhs_isPromptFinalState(); }
	const vector<vector<int> > &genhs_lepdaughter_id() { return cms3.genhs_lepdaughter_id(); }
	const vector<int> &genhs_gentaudecay() { return cms3.genhs_gentaudecay(); }
	const int &gen_nfromths_() { return cms3.gen_nfromths_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_motherp4() { return cms3.genhs_motherp4(); }
	const vector<float> &genhs_mothercharge() { return cms3.genhs_mothercharge(); }
	const vector<int> &genhs_motherid() { return cms3.genhs_motherid(); }
	const vector<int> &genhs_motheridx() { return cms3.genhs_motheridx(); }
	const vector<int> &genhs_motherstatus() { return cms3.genhs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_gmotherp4() { return cms3.genhs_gmotherp4(); }
	const vector<int> &genhs_gmothercharge() { return cms3.genhs_gmothercharge(); }
	const vector<int> &genhs_gmotherid() { return cms3.genhs_gmotherid(); }
	const vector<int> &genhs_gmotheridx() { return cms3.genhs_gmotheridx(); }
	const vector<int> &genhs_gmotherstatus() { return cms3.genhs_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplemotherp4() { return cms3.genhs_simplemotherp4(); }
	const vector<int> &genhs_simplemothercharge() { return cms3.genhs_simplemothercharge(); }
	const vector<int> &genhs_simplemotherid() { return cms3.genhs_simplemotherid(); }
	const vector<int> &genhs_simplemotheridx() { return cms3.genhs_simplemotheridx(); }
	const vector<int> &genhs_simplemotherstatus() { return cms3.genhs_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genhs_simplegmotherp4() { return cms3.genhs_simplegmotherp4(); }
	const vector<int> &genhs_simplegmothercharge() { return cms3.genhs_simplegmothercharge(); }
	const vector<int> &genhs_simplegmotherid() { return cms3.genhs_simplegmotherid(); }
	const vector<int> &genhs_simplegmotheridx() { return cms3.genhs_simplegmotheridx(); }
	const vector<int> &genhs_simplegmotherstatus() { return cms3.genhs_simplegmotherstatus(); }
	const vector<bool> &genlsp_isfromt() { return cms3.genlsp_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_p4() { return cms3.genlsp_p4(); }
	const vector<float> &genlsp_charge() { return cms3.genlsp_charge(); }
	const vector<float> &genlsp_iso() { return cms3.genlsp_iso(); }
	const vector<float> &genlsp_mass() { return cms3.genlsp_mass(); }
	const vector<int> &genlsp_id() { return cms3.genlsp_id(); }
	const vector<int> &genlsp__genpsidx() { return cms3.genlsp__genpsidx(); }
	const vector<int> &genlsp_status() { return cms3.genlsp_status(); }
	const vector<bool> &genlsp_fromHardProcessBeforeFSR() { return cms3.genlsp_fromHardProcessBeforeFSR(); }
	const vector<bool> &genlsp_fromHardProcessDecayed() { return cms3.genlsp_fromHardProcessDecayed(); }
	const vector<bool> &genlsp_fromHardProcessFinalState() { return cms3.genlsp_fromHardProcessFinalState(); }
	const vector<bool> &genlsp_isDirectHardProcessTauDecayProductFinalState() { return cms3.genlsp_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genlsp_isDirectPromptTauDecayProductFinalState() { return cms3.genlsp_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genlsp_isHardProcess() { return cms3.genlsp_isHardProcess(); }
	const vector<bool> &genlsp_isLastCopy() { return cms3.genlsp_isLastCopy(); }
	const vector<bool> &genlsp_isLastCopyBeforeFSR() { return cms3.genlsp_isLastCopyBeforeFSR(); }
	const vector<bool> &genlsp_isMostlyLikePythia6Status3() { return cms3.genlsp_isMostlyLikePythia6Status3(); }
	const vector<bool> &genlsp_isPromptDecayed() { return cms3.genlsp_isPromptDecayed(); }
	const vector<bool> &genlsp_isPromptFinalState() { return cms3.genlsp_isPromptFinalState(); }
	const vector<vector<int> > &genlsp_lepdaughter_id() { return cms3.genlsp_lepdaughter_id(); }
	const vector<int> &genlsp_gentaudecay() { return cms3.genlsp_gentaudecay(); }
	const int &gen_nfromtlsp_() { return cms3.gen_nfromtlsp_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_motherp4() { return cms3.genlsp_motherp4(); }
	const vector<float> &genlsp_mothercharge() { return cms3.genlsp_mothercharge(); }
	const vector<int> &genlsp_motherid() { return cms3.genlsp_motherid(); }
	const vector<int> &genlsp_motheridx() { return cms3.genlsp_motheridx(); }
	const vector<int> &genlsp_motherstatus() { return cms3.genlsp_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_gmotherp4() { return cms3.genlsp_gmotherp4(); }
	const vector<int> &genlsp_gmothercharge() { return cms3.genlsp_gmothercharge(); }
	const vector<int> &genlsp_gmotherid() { return cms3.genlsp_gmotherid(); }
	const vector<int> &genlsp_gmotheridx() { return cms3.genlsp_gmotheridx(); }
	const vector<int> &genlsp_gmotherstatus() { return cms3.genlsp_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplemotherp4() { return cms3.genlsp_simplemotherp4(); }
	const vector<int> &genlsp_simplemothercharge() { return cms3.genlsp_simplemothercharge(); }
	const vector<int> &genlsp_simplemotherid() { return cms3.genlsp_simplemotherid(); }
	const vector<int> &genlsp_simplemotheridx() { return cms3.genlsp_simplemotheridx(); }
	const vector<int> &genlsp_simplemotherstatus() { return cms3.genlsp_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genlsp_simplegmotherp4() { return cms3.genlsp_simplegmotherp4(); }
	const vector<int> &genlsp_simplegmothercharge() { return cms3.genlsp_simplegmothercharge(); }
	const vector<int> &genlsp_simplegmotherid() { return cms3.genlsp_simplegmotherid(); }
	const vector<int> &genlsp_simplegmotheridx() { return cms3.genlsp_simplegmotheridx(); }
	const vector<int> &genlsp_simplegmotherstatus() { return cms3.genlsp_simplegmotherstatus(); }
	const vector<bool> &genstop_isfromt() { return cms3.genstop_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_p4() { return cms3.genstop_p4(); }
	const vector<float> &genstop_charge() { return cms3.genstop_charge(); }
	const vector<float> &genstop_iso() { return cms3.genstop_iso(); }
	const vector<float> &genstop_mass() { return cms3.genstop_mass(); }
	const vector<int> &genstop_id() { return cms3.genstop_id(); }
	const vector<int> &genstop__genpsidx() { return cms3.genstop__genpsidx(); }
	const vector<int> &genstop_status() { return cms3.genstop_status(); }
	const vector<bool> &genstop_fromHardProcessBeforeFSR() { return cms3.genstop_fromHardProcessBeforeFSR(); }
	const vector<bool> &genstop_fromHardProcessDecayed() { return cms3.genstop_fromHardProcessDecayed(); }
	const vector<bool> &genstop_fromHardProcessFinalState() { return cms3.genstop_fromHardProcessFinalState(); }
	const vector<bool> &genstop_isDirectHardProcessTauDecayProductFinalState() { return cms3.genstop_isDirectHardProcessTauDecayProductFinalState(); }
	const vector<bool> &genstop_isDirectPromptTauDecayProductFinalState() { return cms3.genstop_isDirectPromptTauDecayProductFinalState(); }
	const vector<bool> &genstop_isHardProcess() { return cms3.genstop_isHardProcess(); }
	const vector<bool> &genstop_isLastCopy() { return cms3.genstop_isLastCopy(); }
	const vector<bool> &genstop_isLastCopyBeforeFSR() { return cms3.genstop_isLastCopyBeforeFSR(); }
	const vector<bool> &genstop_isMostlyLikePythia6Status3() { return cms3.genstop_isMostlyLikePythia6Status3(); }
	const vector<bool> &genstop_isPromptDecayed() { return cms3.genstop_isPromptDecayed(); }
	const vector<bool> &genstop_isPromptFinalState() { return cms3.genstop_isPromptFinalState(); }
	const vector<vector<int> > &genstop_lepdaughter_id() { return cms3.genstop_lepdaughter_id(); }
	const vector<int> &genstop_gentaudecay() { return cms3.genstop_gentaudecay(); }
	const int &gen_nfromtstop_() { return cms3.gen_nfromtstop_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_motherp4() { return cms3.genstop_motherp4(); }
	const vector<float> &genstop_mothercharge() { return cms3.genstop_mothercharge(); }
	const vector<int> &genstop_motherid() { return cms3.genstop_motherid(); }
	const vector<int> &genstop_motheridx() { return cms3.genstop_motheridx(); }
	const vector<int> &genstop_motherstatus() { return cms3.genstop_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_gmotherp4() { return cms3.genstop_gmotherp4(); }
	const vector<int> &genstop_gmothercharge() { return cms3.genstop_gmothercharge(); }
	const vector<int> &genstop_gmotherid() { return cms3.genstop_gmotherid(); }
	const vector<int> &genstop_gmotheridx() { return cms3.genstop_gmotheridx(); }
	const vector<int> &genstop_gmotherstatus() { return cms3.genstop_gmotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplemotherp4() { return cms3.genstop_simplemotherp4(); }
	const vector<int> &genstop_simplemothercharge() { return cms3.genstop_simplemothercharge(); }
	const vector<int> &genstop_simplemotherid() { return cms3.genstop_simplemotherid(); }
	const vector<int> &genstop_simplemotheridx() { return cms3.genstop_simplemotheridx(); }
	const vector<int> &genstop_simplemotherstatus() { return cms3.genstop_simplemotherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genstop_simplegmotherp4() { return cms3.genstop_simplegmotherp4(); }
	const vector<int> &genstop_simplegmothercharge() { return cms3.genstop_simplegmothercharge(); }
	const vector<int> &genstop_simplegmotherid() { return cms3.genstop_simplegmotherid(); }
	const vector<int> &genstop_simplegmotheridx() { return cms3.genstop_simplegmotheridx(); }
	const vector<int> &genstop_simplegmotherstatus() { return cms3.genstop_simplegmotherstatus(); }
}
