#include "CMS3py.h"
CMS3 cms3;

extern "C" void CMS3::Init(TTree *tree) {
  lep1_p4_branch = tree->GetBranch("lep1_p4");
  if (lep1_p4_branch) lep1_p4_branch->SetAddress(&lep1_p4_);
  lep1_mcp4_branch = tree->GetBranch("lep1_mcp4");
  if (lep1_mcp4_branch) lep1_mcp4_branch->SetAddress(&lep1_mcp4_);
  lep2_p4_branch = tree->GetBranch("lep2_p4");
  if (lep2_p4_branch) lep2_p4_branch->SetAddress(&lep2_p4_);
  lep2_mcp4_branch = tree->GetBranch("lep2_mcp4");
  if (lep2_mcp4_branch) lep2_mcp4_branch->SetAddress(&lep2_mcp4_);
  ph_p4_branch = tree->GetBranch("ph_p4");
  if (ph_p4_branch) ph_p4_branch->SetAddress(&ph_p4_);
  ph_mcp4_branch = tree->GetBranch("ph_mcp4");
  if (ph_mcp4_branch) ph_mcp4_branch->SetAddress(&ph_mcp4_);
  softtags_p4_branch = tree->GetBranch("softtags_p4");
  if (softtags_p4_branch) softtags_p4_branch->SetAddress(&softtags_p4_);
  ak4pfjets_p4_branch = tree->GetBranch("ak4pfjets_p4");
  if (ak4pfjets_p4_branch) ak4pfjets_p4_branch->SetAddress(&ak4pfjets_p4_);
  ak4pfjets_leadMEDbjet_p4_branch = tree->GetBranch("ak4pfjets_leadMEDbjet_p4");
  if (ak4pfjets_leadMEDbjet_p4_branch) ak4pfjets_leadMEDbjet_p4_branch->SetAddress(&ak4pfjets_leadMEDbjet_p4_);
  ak4pfjets_leadbtag_p4_branch = tree->GetBranch("ak4pfjets_leadbtag_p4");
  if (ak4pfjets_leadbtag_p4_branch) ak4pfjets_leadbtag_p4_branch->SetAddress(&ak4pfjets_leadbtag_p4_);
  ak4genjets_p4_branch = tree->GetBranch("ak4genjets_p4");
  if (ak4genjets_p4_branch) ak4genjets_p4_branch->SetAddress(&ak4genjets_p4_);
  jup_softtags_p4_branch = tree->GetBranch("jup_softtags_p4");
  if (jup_softtags_p4_branch) jup_softtags_p4_branch->SetAddress(&jup_softtags_p4_);
  jup_ak4pfjets_p4_branch = tree->GetBranch("jup_ak4pfjets_p4");
  if (jup_ak4pfjets_p4_branch) jup_ak4pfjets_p4_branch->SetAddress(&jup_ak4pfjets_p4_);
  jup_ak4pfjets_leadMEDbjet_p4_branch = tree->GetBranch("jup_ak4pfjets_leadMEDbjet_p4");
  if (jup_ak4pfjets_leadMEDbjet_p4_branch) jup_ak4pfjets_leadMEDbjet_p4_branch->SetAddress(&jup_ak4pfjets_leadMEDbjet_p4_);
  jup_ak4pfjets_leadbtag_p4_branch = tree->GetBranch("jup_ak4pfjets_leadbtag_p4");
  if (jup_ak4pfjets_leadbtag_p4_branch) jup_ak4pfjets_leadbtag_p4_branch->SetAddress(&jup_ak4pfjets_leadbtag_p4_);
  jup_ak4genjets_p4_branch = tree->GetBranch("jup_ak4genjets_p4");
  if (jup_ak4genjets_p4_branch) jup_ak4genjets_p4_branch->SetAddress(&jup_ak4genjets_p4_);
  jdown_softtags_p4_branch = tree->GetBranch("jdown_softtags_p4");
  if (jdown_softtags_p4_branch) jdown_softtags_p4_branch->SetAddress(&jdown_softtags_p4_);
  jdown_ak4pfjets_p4_branch = tree->GetBranch("jdown_ak4pfjets_p4");
  if (jdown_ak4pfjets_p4_branch) jdown_ak4pfjets_p4_branch->SetAddress(&jdown_ak4pfjets_p4_);
  jdown_ak4pfjets_leadMEDbjet_p4_branch = tree->GetBranch("jdown_ak4pfjets_leadMEDbjet_p4");
  if (jdown_ak4pfjets_leadMEDbjet_p4_branch) jdown_ak4pfjets_leadMEDbjet_p4_branch->SetAddress(&jdown_ak4pfjets_leadMEDbjet_p4_);
  jdown_ak4pfjets_leadbtag_p4_branch = tree->GetBranch("jdown_ak4pfjets_leadbtag_p4");
  if (jdown_ak4pfjets_leadbtag_p4_branch) jdown_ak4pfjets_leadbtag_p4_branch->SetAddress(&jdown_ak4pfjets_leadbtag_p4_);
  jdown_ak4genjets_p4_branch = tree->GetBranch("jdown_ak4genjets_p4");
  if (jdown_ak4genjets_p4_branch) jdown_ak4genjets_p4_branch->SetAddress(&jdown_ak4genjets_p4_);
  genleps_p4_branch = tree->GetBranch("genleps_p4");
  if (genleps_p4_branch) genleps_p4_branch->SetAddress(&genleps_p4_);
  genleps_motherp4_branch = tree->GetBranch("genleps_motherp4");
  if (genleps_motherp4_branch) genleps_motherp4_branch->SetAddress(&genleps_motherp4_);
  genleps_gmotherp4_branch = tree->GetBranch("genleps_gmotherp4");
  if (genleps_gmotherp4_branch) genleps_gmotherp4_branch->SetAddress(&genleps_gmotherp4_);
  gennus_p4_branch = tree->GetBranch("gennus_p4");
  if (gennus_p4_branch) gennus_p4_branch->SetAddress(&gennus_p4_);
  gennus_motherp4_branch = tree->GetBranch("gennus_motherp4");
  if (gennus_motherp4_branch) gennus_motherp4_branch->SetAddress(&gennus_motherp4_);
  gennus_gmotherp4_branch = tree->GetBranch("gennus_gmotherp4");
  if (gennus_gmotherp4_branch) gennus_gmotherp4_branch->SetAddress(&gennus_gmotherp4_);
  genqs_p4_branch = tree->GetBranch("genqs_p4");
  if (genqs_p4_branch) genqs_p4_branch->SetAddress(&genqs_p4_);
  genqs_motherp4_branch = tree->GetBranch("genqs_motherp4");
  if (genqs_motherp4_branch) genqs_motherp4_branch->SetAddress(&genqs_motherp4_);
  genqs_gmotherp4_branch = tree->GetBranch("genqs_gmotherp4");
  if (genqs_gmotherp4_branch) genqs_gmotherp4_branch->SetAddress(&genqs_gmotherp4_);
  genbosons_p4_branch = tree->GetBranch("genbosons_p4");
  if (genbosons_p4_branch) genbosons_p4_branch->SetAddress(&genbosons_p4_);
  genbosons_motherp4_branch = tree->GetBranch("genbosons_motherp4");
  if (genbosons_motherp4_branch) genbosons_motherp4_branch->SetAddress(&genbosons_motherp4_);
  genbosons_gmotherp4_branch = tree->GetBranch("genbosons_gmotherp4");
  if (genbosons_gmotherp4_branch) genbosons_gmotherp4_branch->SetAddress(&genbosons_gmotherp4_);
  gensusy_p4_branch = tree->GetBranch("gensusy_p4");
  if (gensusy_p4_branch) gensusy_p4_branch->SetAddress(&gensusy_p4_);
  gensusy_motherp4_branch = tree->GetBranch("gensusy_motherp4");
  if (gensusy_motherp4_branch) gensusy_motherp4_branch->SetAddress(&gensusy_motherp4_);
  gensusy_gmotherp4_branch = tree->GetBranch("gensusy_gmotherp4");
  if (gensusy_gmotherp4_branch) gensusy_gmotherp4_branch->SetAddress(&gensusy_gmotherp4_);
  tau_leadtrack_p4_branch = tree->GetBranch("tau_leadtrack_p4");
  if (tau_leadtrack_p4_branch) tau_leadtrack_p4_branch->SetAddress(&tau_leadtrack_p4_);
  tau_leadneutral_p4_branch = tree->GetBranch("tau_leadneutral_p4");
  if (tau_leadneutral_p4_branch) tau_leadneutral_p4_branch->SetAddress(&tau_leadneutral_p4_);
  tau_p4_branch = tree->GetBranch("tau_p4");
  if (tau_p4_branch) tau_p4_branch->SetAddress(&tau_p4_);
  isoTracks_p4_branch = tree->GetBranch("isoTracks_p4");
  if (isoTracks_p4_branch) isoTracks_p4_branch->SetAddress(&isoTracks_p4_);

  tree->SetMakeClass(1);

  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  ls_branch = tree->GetBranch("ls");
  if (ls_branch) ls_branch->SetAddress(&ls_);
  evt_branch = tree->GetBranch("evt");
  if (evt_branch) evt_branch->SetAddress(&evt_);
  nvtxs_branch = tree->GetBranch("nvtxs");
  if (nvtxs_branch) nvtxs_branch->SetAddress(&nvtxs_);
  pu_nvtxs_branch = tree->GetBranch("pu_nvtxs");
  if (pu_nvtxs_branch) pu_nvtxs_branch->SetAddress(&pu_nvtxs_);
  pfmet_branch = tree->GetBranch("pfmet");
  if (pfmet_branch) pfmet_branch->SetAddress(&pfmet_);
  pfmet_phi_branch = tree->GetBranch("pfmet_phi");
  if (pfmet_phi_branch) pfmet_phi_branch->SetAddress(&pfmet_phi_);
  pfmet_jup_branch = tree->GetBranch("pfmet_jup");
  if (pfmet_jup_branch) pfmet_jup_branch->SetAddress(&pfmet_jup_);
  pfmet_phi_jup_branch = tree->GetBranch("pfmet_phi_jup");
  if (pfmet_phi_jup_branch) pfmet_phi_jup_branch->SetAddress(&pfmet_phi_jup_);
  pfmet_jdown_branch = tree->GetBranch("pfmet_jdown");
  if (pfmet_jdown_branch) pfmet_jdown_branch->SetAddress(&pfmet_jdown_);
  pfmet_phi_jdown_branch = tree->GetBranch("pfmet_phi_jdown");
  if (pfmet_phi_jdown_branch) pfmet_phi_jdown_branch->SetAddress(&pfmet_phi_jdown_);
  pfmet_rl_branch = tree->GetBranch("pfmet_rl");
  if (pfmet_rl_branch) pfmet_rl_branch->SetAddress(&pfmet_rl_);
  pfmet_phi_rl_branch = tree->GetBranch("pfmet_phi_rl");
  if (pfmet_phi_rl_branch) pfmet_phi_rl_branch->SetAddress(&pfmet_phi_rl_);
  pfmet_rl_jup_branch = tree->GetBranch("pfmet_rl_jup");
  if (pfmet_rl_jup_branch) pfmet_rl_jup_branch->SetAddress(&pfmet_rl_jup_);
  pfmet_phi_rl_jup_branch = tree->GetBranch("pfmet_phi_rl_jup");
  if (pfmet_phi_rl_jup_branch) pfmet_phi_rl_jup_branch->SetAddress(&pfmet_phi_rl_jup_);
  pfmet_rl_jdown_branch = tree->GetBranch("pfmet_rl_jdown");
  if (pfmet_rl_jdown_branch) pfmet_rl_jdown_branch->SetAddress(&pfmet_rl_jdown_);
  pfmet_phi_rl_jdown_branch = tree->GetBranch("pfmet_phi_rl_jdown");
  if (pfmet_phi_rl_jdown_branch) pfmet_phi_rl_jdown_branch->SetAddress(&pfmet_phi_rl_jdown_);
  pfmet_egclean_branch = tree->GetBranch("pfmet_egclean");
  if (pfmet_egclean_branch) pfmet_egclean_branch->SetAddress(&pfmet_egclean_);
  pfmet_egclean_phi_branch = tree->GetBranch("pfmet_egclean_phi");
  if (pfmet_egclean_phi_branch) pfmet_egclean_phi_branch->SetAddress(&pfmet_egclean_phi_);
  pfmet_muegclean_branch = tree->GetBranch("pfmet_muegclean");
  if (pfmet_muegclean_branch) pfmet_muegclean_branch->SetAddress(&pfmet_muegclean_);
  pfmet_muegclean_phi_branch = tree->GetBranch("pfmet_muegclean_phi");
  if (pfmet_muegclean_phi_branch) pfmet_muegclean_phi_branch->SetAddress(&pfmet_muegclean_phi_);
  pfmet_muegcleanfix_branch = tree->GetBranch("pfmet_muegcleanfix");
  if (pfmet_muegcleanfix_branch) pfmet_muegcleanfix_branch->SetAddress(&pfmet_muegcleanfix_);
  pfmet_muegcleanfix_phi_branch = tree->GetBranch("pfmet_muegcleanfix_phi");
  if (pfmet_muegcleanfix_phi_branch) pfmet_muegcleanfix_phi_branch->SetAddress(&pfmet_muegcleanfix_phi_);
  pfmet_uncorr_branch = tree->GetBranch("pfmet_uncorr");
  if (pfmet_uncorr_branch) pfmet_uncorr_branch->SetAddress(&pfmet_uncorr_);
  pfmet_uncorr_phi_branch = tree->GetBranch("pfmet_uncorr_phi");
  if (pfmet_uncorr_phi_branch) pfmet_uncorr_phi_branch->SetAddress(&pfmet_uncorr_phi_);
  pfmet_original_branch = tree->GetBranch("pfmet_original");
  if (pfmet_original_branch) pfmet_original_branch->SetAddress(&pfmet_original_);
  pfmet_original_phi_branch = tree->GetBranch("pfmet_original_phi");
  if (pfmet_original_phi_branch) pfmet_original_phi_branch->SetAddress(&pfmet_original_phi_);
  scale1fb_branch = tree->GetBranch("scale1fb");
  if (scale1fb_branch) scale1fb_branch->SetAddress(&scale1fb_);
  xsec_branch = tree->GetBranch("xsec");
  if (xsec_branch) xsec_branch->SetAddress(&xsec_);
  xsec_uncert_branch = tree->GetBranch("xsec_uncert");
  if (xsec_uncert_branch) xsec_uncert_branch->SetAddress(&xsec_uncert_);
  kfactor_branch = tree->GetBranch("kfactor");
  if (kfactor_branch) kfactor_branch->SetAddress(&kfactor_);
  pu_ntrue_branch = tree->GetBranch("pu_ntrue");
  if (pu_ntrue_branch) pu_ntrue_branch->SetAddress(&pu_ntrue_);
  ngoodleps_branch = tree->GetBranch("ngoodleps");
  if (ngoodleps_branch) ngoodleps_branch->SetAddress(&ngoodleps_);
  nlooseleps_branch = tree->GetBranch("nlooseleps");
  if (nlooseleps_branch) nlooseleps_branch->SetAddress(&nlooseleps_);
  nvetoleps_branch = tree->GetBranch("nvetoleps");
  if (nvetoleps_branch) nvetoleps_branch->SetAddress(&nvetoleps_);
  is_data_branch = tree->GetBranch("is_data");
  if (is_data_branch) is_data_branch->SetAddress(&is_data_);
  dataset_branch = tree->GetBranch("dataset");
  if (dataset_branch) dataset_branch->SetAddress(&dataset_);
  filename_branch = tree->GetBranch("filename");
  if (filename_branch) filename_branch->SetAddress(&filename_);
  cms3tag_branch = tree->GetBranch("cms3tag");
  if (cms3tag_branch) cms3tag_branch->SetAddress(&cms3tag_);
  nEvents_branch = tree->GetBranch("nEvents");
  if (nEvents_branch) nEvents_branch->SetAddress(&nEvents_);
  nEvents_goodvtx_branch = tree->GetBranch("nEvents_goodvtx");
  if (nEvents_goodvtx_branch) nEvents_goodvtx_branch->SetAddress(&nEvents_goodvtx_);
  nEvents_MET30_branch = tree->GetBranch("nEvents_MET30");
  if (nEvents_MET30_branch) nEvents_MET30_branch->SetAddress(&nEvents_MET30_);
  nEvents_1goodlep_branch = tree->GetBranch("nEvents_1goodlep");
  if (nEvents_1goodlep_branch) nEvents_1goodlep_branch->SetAddress(&nEvents_1goodlep_);
  nEvents_2goodjets_branch = tree->GetBranch("nEvents_2goodjets");
  if (nEvents_2goodjets_branch) nEvents_2goodjets_branch->SetAddress(&nEvents_2goodjets_);
  is0lep_branch = tree->GetBranch("is0lep");
  if (is0lep_branch) is0lep_branch->SetAddress(&is0lep_);
  is1lep_branch = tree->GetBranch("is1lep");
  if (is1lep_branch) is1lep_branch->SetAddress(&is1lep_);
  is2lep_branch = tree->GetBranch("is2lep");
  if (is2lep_branch) is2lep_branch->SetAddress(&is2lep_);
  isZtoNuNu_branch = tree->GetBranch("isZtoNuNu");
  if (isZtoNuNu_branch) isZtoNuNu_branch->SetAddress(&isZtoNuNu_);
  is1lepFromW_branch = tree->GetBranch("is1lepFromW");
  if (is1lepFromW_branch) is1lepFromW_branch->SetAddress(&is1lepFromW_);
  is1lepFromTop_branch = tree->GetBranch("is1lepFromTop");
  if (is1lepFromTop_branch) is1lepFromTop_branch->SetAddress(&is1lepFromTop_);
  MT2W_branch = tree->GetBranch("MT2W");
  if (MT2W_branch) MT2W_branch->SetAddress(&MT2W_);
  MT2W_rl_branch = tree->GetBranch("MT2W_rl");
  if (MT2W_rl_branch) MT2W_rl_branch->SetAddress(&MT2W_rl_);
  mindphi_met_j1_j2_branch = tree->GetBranch("mindphi_met_j1_j2");
  if (mindphi_met_j1_j2_branch) mindphi_met_j1_j2_branch->SetAddress(&mindphi_met_j1_j2_);
  mindphi_met_j1_j2_rl_branch = tree->GetBranch("mindphi_met_j1_j2_rl");
  if (mindphi_met_j1_j2_rl_branch) mindphi_met_j1_j2_rl_branch->SetAddress(&mindphi_met_j1_j2_rl_);
  mt_met_lep_branch = tree->GetBranch("mt_met_lep");
  if (mt_met_lep_branch) mt_met_lep_branch->SetAddress(&mt_met_lep_);
  mt_met_lep_rl_branch = tree->GetBranch("mt_met_lep_rl");
  if (mt_met_lep_rl_branch) mt_met_lep_rl_branch->SetAddress(&mt_met_lep_rl_);
  MT2W_jup_branch = tree->GetBranch("MT2W_jup");
  if (MT2W_jup_branch) MT2W_jup_branch->SetAddress(&MT2W_jup_);
  MT2W_rl_jup_branch = tree->GetBranch("MT2W_rl_jup");
  if (MT2W_rl_jup_branch) MT2W_rl_jup_branch->SetAddress(&MT2W_rl_jup_);
  mindphi_met_j1_j2_jup_branch = tree->GetBranch("mindphi_met_j1_j2_jup");
  if (mindphi_met_j1_j2_jup_branch) mindphi_met_j1_j2_jup_branch->SetAddress(&mindphi_met_j1_j2_jup_);
  mindphi_met_j1_j2_rl_jup_branch = tree->GetBranch("mindphi_met_j1_j2_rl_jup");
  if (mindphi_met_j1_j2_rl_jup_branch) mindphi_met_j1_j2_rl_jup_branch->SetAddress(&mindphi_met_j1_j2_rl_jup_);
  mt_met_lep_jup_branch = tree->GetBranch("mt_met_lep_jup");
  if (mt_met_lep_jup_branch) mt_met_lep_jup_branch->SetAddress(&mt_met_lep_jup_);
  mt_met_lep_rl_jup_branch = tree->GetBranch("mt_met_lep_rl_jup");
  if (mt_met_lep_rl_jup_branch) mt_met_lep_rl_jup_branch->SetAddress(&mt_met_lep_rl_jup_);
  MT2W_jdown_branch = tree->GetBranch("MT2W_jdown");
  if (MT2W_jdown_branch) MT2W_jdown_branch->SetAddress(&MT2W_jdown_);
  MT2W_rl_jdown_branch = tree->GetBranch("MT2W_rl_jdown");
  if (MT2W_rl_jdown_branch) MT2W_rl_jdown_branch->SetAddress(&MT2W_rl_jdown_);
  mindphi_met_j1_j2_jdown_branch = tree->GetBranch("mindphi_met_j1_j2_jdown");
  if (mindphi_met_j1_j2_jdown_branch) mindphi_met_j1_j2_jdown_branch->SetAddress(&mindphi_met_j1_j2_jdown_);
  mindphi_met_j1_j2_rl_jdown_branch = tree->GetBranch("mindphi_met_j1_j2_rl_jdown");
  if (mindphi_met_j1_j2_rl_jdown_branch) mindphi_met_j1_j2_rl_jdown_branch->SetAddress(&mindphi_met_j1_j2_rl_jdown_);
  mt_met_lep_jdown_branch = tree->GetBranch("mt_met_lep_jdown");
  if (mt_met_lep_jdown_branch) mt_met_lep_jdown_branch->SetAddress(&mt_met_lep_jdown_);
  mt_met_lep_rl_jdown_branch = tree->GetBranch("mt_met_lep_rl_jdown");
  if (mt_met_lep_rl_jdown_branch) mt_met_lep_rl_jdown_branch->SetAddress(&mt_met_lep_rl_jdown_);
  hadronic_top_chi2_branch = tree->GetBranch("hadronic_top_chi2");
  if (hadronic_top_chi2_branch) hadronic_top_chi2_branch->SetAddress(&hadronic_top_chi2_);
  ak4pfjets_rho_branch = tree->GetBranch("ak4pfjets_rho");
  if (ak4pfjets_rho_branch) ak4pfjets_rho_branch->SetAddress(&ak4pfjets_rho_);
  pdf_up_weight_branch = tree->GetBranch("pdf_up_weight");
  if (pdf_up_weight_branch) pdf_up_weight_branch->SetAddress(&pdf_up_weight_);
  pdf_down_weight_branch = tree->GetBranch("pdf_down_weight");
  if (pdf_down_weight_branch) pdf_down_weight_branch->SetAddress(&pdf_down_weight_);
  genweightsID_branch = tree->GetBranch("genweightsID");
  if (genweightsID_branch) genweightsID_branch->SetAddress(&genweightsID_);
  genweights_branch = tree->GetBranch("genweights");
  if (genweights_branch) genweights_branch->SetAddress(&genweights_);
  weight_btagsf_branch = tree->GetBranch("weight_btagsf");
  if (weight_btagsf_branch) weight_btagsf_branch->SetAddress(&weight_btagsf_);
  weight_btagsf_heavy_UP_branch = tree->GetBranch("weight_btagsf_heavy_UP");
  if (weight_btagsf_heavy_UP_branch) weight_btagsf_heavy_UP_branch->SetAddress(&weight_btagsf_heavy_UP_);
  weight_btagsf_light_UP_branch = tree->GetBranch("weight_btagsf_light_UP");
  if (weight_btagsf_light_UP_branch) weight_btagsf_light_UP_branch->SetAddress(&weight_btagsf_light_UP_);
  weight_btagsf_heavy_DN_branch = tree->GetBranch("weight_btagsf_heavy_DN");
  if (weight_btagsf_heavy_DN_branch) weight_btagsf_heavy_DN_branch->SetAddress(&weight_btagsf_heavy_DN_);
  weight_btagsf_light_DN_branch = tree->GetBranch("weight_btagsf_light_DN");
  if (weight_btagsf_light_DN_branch) weight_btagsf_light_DN_branch->SetAddress(&weight_btagsf_light_DN_);
  weight_btagsf_fastsim_UP_branch = tree->GetBranch("weight_btagsf_fastsim_UP");
  if (weight_btagsf_fastsim_UP_branch) weight_btagsf_fastsim_UP_branch->SetAddress(&weight_btagsf_fastsim_UP_);
  weight_btagsf_fastsim_DN_branch = tree->GetBranch("weight_btagsf_fastsim_DN");
  if (weight_btagsf_fastsim_DN_branch) weight_btagsf_fastsim_DN_branch->SetAddress(&weight_btagsf_fastsim_DN_);
  weight_analysisbtagsf_branch = tree->GetBranch("weight_analysisbtagsf");
  if (weight_analysisbtagsf_branch) weight_analysisbtagsf_branch->SetAddress(&weight_analysisbtagsf_);
  weight_analysisbtagsf_heavy_UP_branch = tree->GetBranch("weight_analysisbtagsf_heavy_UP");
  if (weight_analysisbtagsf_heavy_UP_branch) weight_analysisbtagsf_heavy_UP_branch->SetAddress(&weight_analysisbtagsf_heavy_UP_);
  weight_analysisbtagsf_light_UP_branch = tree->GetBranch("weight_analysisbtagsf_light_UP");
  if (weight_analysisbtagsf_light_UP_branch) weight_analysisbtagsf_light_UP_branch->SetAddress(&weight_analysisbtagsf_light_UP_);
  weight_analysisbtagsf_heavy_DN_branch = tree->GetBranch("weight_analysisbtagsf_heavy_DN");
  if (weight_analysisbtagsf_heavy_DN_branch) weight_analysisbtagsf_heavy_DN_branch->SetAddress(&weight_analysisbtagsf_heavy_DN_);
  weight_analysisbtagsf_light_DN_branch = tree->GetBranch("weight_analysisbtagsf_light_DN");
  if (weight_analysisbtagsf_light_DN_branch) weight_analysisbtagsf_light_DN_branch->SetAddress(&weight_analysisbtagsf_light_DN_);
  weight_analysisbtagsf_fastsim_UP_branch = tree->GetBranch("weight_analysisbtagsf_fastsim_UP");
  if (weight_analysisbtagsf_fastsim_UP_branch) weight_analysisbtagsf_fastsim_UP_branch->SetAddress(&weight_analysisbtagsf_fastsim_UP_);
  weight_analysisbtagsf_fastsim_DN_branch = tree->GetBranch("weight_analysisbtagsf_fastsim_DN");
  if (weight_analysisbtagsf_fastsim_DN_branch) weight_analysisbtagsf_fastsim_DN_branch->SetAddress(&weight_analysisbtagsf_fastsim_DN_);
  weight_tightbtagsf_branch = tree->GetBranch("weight_tightbtagsf");
  if (weight_tightbtagsf_branch) weight_tightbtagsf_branch->SetAddress(&weight_tightbtagsf_);
  weight_tightbtagsf_heavy_UP_branch = tree->GetBranch("weight_tightbtagsf_heavy_UP");
  if (weight_tightbtagsf_heavy_UP_branch) weight_tightbtagsf_heavy_UP_branch->SetAddress(&weight_tightbtagsf_heavy_UP_);
  weight_tightbtagsf_light_UP_branch = tree->GetBranch("weight_tightbtagsf_light_UP");
  if (weight_tightbtagsf_light_UP_branch) weight_tightbtagsf_light_UP_branch->SetAddress(&weight_tightbtagsf_light_UP_);
  weight_tightbtagsf_heavy_DN_branch = tree->GetBranch("weight_tightbtagsf_heavy_DN");
  if (weight_tightbtagsf_heavy_DN_branch) weight_tightbtagsf_heavy_DN_branch->SetAddress(&weight_tightbtagsf_heavy_DN_);
  weight_tightbtagsf_light_DN_branch = tree->GetBranch("weight_tightbtagsf_light_DN");
  if (weight_tightbtagsf_light_DN_branch) weight_tightbtagsf_light_DN_branch->SetAddress(&weight_tightbtagsf_light_DN_);
  weight_tightbtagsf_fastsim_UP_branch = tree->GetBranch("weight_tightbtagsf_fastsim_UP");
  if (weight_tightbtagsf_fastsim_UP_branch) weight_tightbtagsf_fastsim_UP_branch->SetAddress(&weight_tightbtagsf_fastsim_UP_);
  weight_tightbtagsf_fastsim_DN_branch = tree->GetBranch("weight_tightbtagsf_fastsim_DN");
  if (weight_tightbtagsf_fastsim_DN_branch) weight_tightbtagsf_fastsim_DN_branch->SetAddress(&weight_tightbtagsf_fastsim_DN_);
  weight_loosebtagsf_branch = tree->GetBranch("weight_loosebtagsf");
  if (weight_loosebtagsf_branch) weight_loosebtagsf_branch->SetAddress(&weight_loosebtagsf_);
  weight_loosebtagsf_heavy_UP_branch = tree->GetBranch("weight_loosebtagsf_heavy_UP");
  if (weight_loosebtagsf_heavy_UP_branch) weight_loosebtagsf_heavy_UP_branch->SetAddress(&weight_loosebtagsf_heavy_UP_);
  weight_loosebtagsf_light_UP_branch = tree->GetBranch("weight_loosebtagsf_light_UP");
  if (weight_loosebtagsf_light_UP_branch) weight_loosebtagsf_light_UP_branch->SetAddress(&weight_loosebtagsf_light_UP_);
  weight_loosebtagsf_heavy_DN_branch = tree->GetBranch("weight_loosebtagsf_heavy_DN");
  if (weight_loosebtagsf_heavy_DN_branch) weight_loosebtagsf_heavy_DN_branch->SetAddress(&weight_loosebtagsf_heavy_DN_);
  weight_loosebtagsf_light_DN_branch = tree->GetBranch("weight_loosebtagsf_light_DN");
  if (weight_loosebtagsf_light_DN_branch) weight_loosebtagsf_light_DN_branch->SetAddress(&weight_loosebtagsf_light_DN_);
  weight_loosebtagsf_fastsim_UP_branch = tree->GetBranch("weight_loosebtagsf_fastsim_UP");
  if (weight_loosebtagsf_fastsim_UP_branch) weight_loosebtagsf_fastsim_UP_branch->SetAddress(&weight_loosebtagsf_fastsim_UP_);
  weight_loosebtagsf_fastsim_DN_branch = tree->GetBranch("weight_loosebtagsf_fastsim_DN");
  if (weight_loosebtagsf_fastsim_DN_branch) weight_loosebtagsf_fastsim_DN_branch->SetAddress(&weight_loosebtagsf_fastsim_DN_);
  weight_lepSF_branch = tree->GetBranch("weight_lepSF");
  if (weight_lepSF_branch) weight_lepSF_branch->SetAddress(&weight_lepSF_);
  weight_lepSF_up_branch = tree->GetBranch("weight_lepSF_up");
  if (weight_lepSF_up_branch) weight_lepSF_up_branch->SetAddress(&weight_lepSF_up_);
  weight_lepSF_down_branch = tree->GetBranch("weight_lepSF_down");
  if (weight_lepSF_down_branch) weight_lepSF_down_branch->SetAddress(&weight_lepSF_down_);
  weight_vetoLepSF_branch = tree->GetBranch("weight_vetoLepSF");
  if (weight_vetoLepSF_branch) weight_vetoLepSF_branch->SetAddress(&weight_vetoLepSF_);
  weight_vetoLepSF_up_branch = tree->GetBranch("weight_vetoLepSF_up");
  if (weight_vetoLepSF_up_branch) weight_vetoLepSF_up_branch->SetAddress(&weight_vetoLepSF_up_);
  weight_vetoLepSF_down_branch = tree->GetBranch("weight_vetoLepSF_down");
  if (weight_vetoLepSF_down_branch) weight_vetoLepSF_down_branch->SetAddress(&weight_vetoLepSF_down_);
  weight_lepSF_fastSim_branch = tree->GetBranch("weight_lepSF_fastSim");
  if (weight_lepSF_fastSim_branch) weight_lepSF_fastSim_branch->SetAddress(&weight_lepSF_fastSim_);
  weight_lepSF_fastSim_up_branch = tree->GetBranch("weight_lepSF_fastSim_up");
  if (weight_lepSF_fastSim_up_branch) weight_lepSF_fastSim_up_branch->SetAddress(&weight_lepSF_fastSim_up_);
  weight_lepSF_fastSim_down_branch = tree->GetBranch("weight_lepSF_fastSim_down");
  if (weight_lepSF_fastSim_down_branch) weight_lepSF_fastSim_down_branch->SetAddress(&weight_lepSF_fastSim_down_);
  weight_ISR_branch = tree->GetBranch("weight_ISR");
  if (weight_ISR_branch) weight_ISR_branch->SetAddress(&weight_ISR_);
  weight_ISRup_branch = tree->GetBranch("weight_ISRup");
  if (weight_ISRup_branch) weight_ISRup_branch->SetAddress(&weight_ISRup_);
  weight_ISRdown_branch = tree->GetBranch("weight_ISRdown");
  if (weight_ISRdown_branch) weight_ISRdown_branch->SetAddress(&weight_ISRdown_);
  weight_PU_branch = tree->GetBranch("weight_PU");
  if (weight_PU_branch) weight_PU_branch->SetAddress(&weight_PU_);
  weight_PUup_branch = tree->GetBranch("weight_PUup");
  if (weight_PUup_branch) weight_PUup_branch->SetAddress(&weight_PUup_);
  weight_PUdown_branch = tree->GetBranch("weight_PUdown");
  if (weight_PUdown_branch) weight_PUdown_branch->SetAddress(&weight_PUdown_);
  weight_ISRnjets_branch = tree->GetBranch("weight_ISRnjets");
  if (weight_ISRnjets_branch) weight_ISRnjets_branch->SetAddress(&weight_ISRnjets_);
  weight_ISRnjets_UP_branch = tree->GetBranch("weight_ISRnjets_UP");
  if (weight_ISRnjets_UP_branch) weight_ISRnjets_UP_branch->SetAddress(&weight_ISRnjets_UP_);
  weight_ISRnjets_DN_branch = tree->GetBranch("weight_ISRnjets_DN");
  if (weight_ISRnjets_DN_branch) weight_ISRnjets_DN_branch->SetAddress(&weight_ISRnjets_DN_);
  NISRjets_branch = tree->GetBranch("NISRjets");
  if (NISRjets_branch) NISRjets_branch->SetAddress(&NISRjets_);
  NnonISRjets_branch = tree->GetBranch("NnonISRjets");
  if (NnonISRjets_branch) NnonISRjets_branch->SetAddress(&NnonISRjets_);
  sparms_names_branch = tree->GetBranch("sparms_names");
  if (sparms_names_branch) sparms_names_branch->SetAddress(&sparms_names_);
  sparms_values_branch = tree->GetBranch("sparms_values");
  if (sparms_values_branch) sparms_values_branch->SetAddress(&sparms_values_);
  sparms_subProcessId_branch = tree->GetBranch("sparms_subProcessId");
  if (sparms_subProcessId_branch) sparms_subProcessId_branch->SetAddress(&sparms_subProcessId_);
  mass_lsp_branch = tree->GetBranch("mass_lsp");
  if (mass_lsp_branch) mass_lsp_branch->SetAddress(&mass_lsp_);
  mass_chargino_branch = tree->GetBranch("mass_chargino");
  if (mass_chargino_branch) mass_chargino_branch->SetAddress(&mass_chargino_);
  mass_stop_branch = tree->GetBranch("mass_stop");
  if (mass_stop_branch) mass_stop_branch->SetAddress(&mass_stop_);
  mass_gluino_branch = tree->GetBranch("mass_gluino");
  if (mass_gluino_branch) mass_gluino_branch->SetAddress(&mass_gluino_);
  genmet_branch = tree->GetBranch("genmet");
  if (genmet_branch) genmet_branch->SetAddress(&genmet_);
  genmet_phi_branch = tree->GetBranch("genmet_phi");
  if (genmet_phi_branch) genmet_phi_branch->SetAddress(&genmet_phi_);
  nupt_branch = tree->GetBranch("nupt");
  if (nupt_branch) nupt_branch->SetAddress(&nupt_);
  genht_branch = tree->GetBranch("genht");
  if (genht_branch) genht_branch->SetAddress(&genht_);
  PassTrackVeto_branch = tree->GetBranch("PassTrackVeto");
  if (PassTrackVeto_branch) PassTrackVeto_branch->SetAddress(&PassTrackVeto_);
  PassTauVeto_branch = tree->GetBranch("PassTauVeto");
  if (PassTauVeto_branch) PassTauVeto_branch->SetAddress(&PassTauVeto_);
  topness_branch = tree->GetBranch("topness");
  if (topness_branch) topness_branch->SetAddress(&topness_);
  topnessMod_branch = tree->GetBranch("topnessMod");
  if (topnessMod_branch) topnessMod_branch->SetAddress(&topnessMod_);
  topnessMod_rl_branch = tree->GetBranch("topnessMod_rl");
  if (topnessMod_rl_branch) topnessMod_rl_branch->SetAddress(&topnessMod_rl_);
  topnessMod_jup_branch = tree->GetBranch("topnessMod_jup");
  if (topnessMod_jup_branch) topnessMod_jup_branch->SetAddress(&topnessMod_jup_);
  topnessMod_rl_jup_branch = tree->GetBranch("topnessMod_rl_jup");
  if (topnessMod_rl_jup_branch) topnessMod_rl_jup_branch->SetAddress(&topnessMod_rl_jup_);
  topnessMod_jdown_branch = tree->GetBranch("topnessMod_jdown");
  if (topnessMod_jdown_branch) topnessMod_jdown_branch->SetAddress(&topnessMod_jdown_);
  topnessMod_rl_jdown_branch = tree->GetBranch("topnessMod_rl_jdown");
  if (topnessMod_rl_jdown_branch) topnessMod_rl_jdown_branch->SetAddress(&topnessMod_rl_jdown_);
  Mlb_closestb_branch = tree->GetBranch("Mlb_closestb");
  if (Mlb_closestb_branch) Mlb_closestb_branch->SetAddress(&Mlb_closestb_);
  Mlb_lead_bdiscr_branch = tree->GetBranch("Mlb_lead_bdiscr");
  if (Mlb_lead_bdiscr_branch) Mlb_lead_bdiscr_branch->SetAddress(&Mlb_lead_bdiscr_);
  Mlb_closestb_jup_branch = tree->GetBranch("Mlb_closestb_jup");
  if (Mlb_closestb_jup_branch) Mlb_closestb_jup_branch->SetAddress(&Mlb_closestb_jup_);
  Mlb_lead_bdiscr_jup_branch = tree->GetBranch("Mlb_lead_bdiscr_jup");
  if (Mlb_lead_bdiscr_jup_branch) Mlb_lead_bdiscr_jup_branch->SetAddress(&Mlb_lead_bdiscr_jup_);
  Mlb_closestb_jdown_branch = tree->GetBranch("Mlb_closestb_jdown");
  if (Mlb_closestb_jdown_branch) Mlb_closestb_jdown_branch->SetAddress(&Mlb_closestb_jdown_);
  Mlb_lead_bdiscr_jdown_branch = tree->GetBranch("Mlb_lead_bdiscr_jdown");
  if (Mlb_lead_bdiscr_jdown_branch) Mlb_lead_bdiscr_jdown_branch->SetAddress(&Mlb_lead_bdiscr_jdown_);
  HLT_SingleEl_branch = tree->GetBranch("HLT_SingleEl");
  if (HLT_SingleEl_branch) HLT_SingleEl_branch->SetAddress(&HLT_SingleEl_);
  HLT_SingleMu_branch = tree->GetBranch("HLT_SingleMu");
  if (HLT_SingleMu_branch) HLT_SingleMu_branch->SetAddress(&HLT_SingleMu_);
  HLT_MET_branch = tree->GetBranch("HLT_MET");
  if (HLT_MET_branch) HLT_MET_branch->SetAddress(&HLT_MET_);
  HLT_MET_MHT_branch = tree->GetBranch("HLT_MET_MHT");
  if (HLT_MET_MHT_branch) HLT_MET_MHT_branch->SetAddress(&HLT_MET_MHT_);
  HLT_MET100_MHT100_branch = tree->GetBranch("HLT_MET100_MHT100");
  if (HLT_MET100_MHT100_branch) HLT_MET100_MHT100_branch->SetAddress(&HLT_MET100_MHT100_);
  HLT_MET110_MHT110_branch = tree->GetBranch("HLT_MET110_MHT110");
  if (HLT_MET110_MHT110_branch) HLT_MET110_MHT110_branch->SetAddress(&HLT_MET110_MHT110_);
  HLT_MET120_MHT120_branch = tree->GetBranch("HLT_MET120_MHT120");
  if (HLT_MET120_MHT120_branch) HLT_MET120_MHT120_branch->SetAddress(&HLT_MET120_MHT120_);
  HLT_PFHT_unprescaled_branch = tree->GetBranch("HLT_PFHT_unprescaled");
  if (HLT_PFHT_unprescaled_branch) HLT_PFHT_unprescaled_branch->SetAddress(&HLT_PFHT_unprescaled_);
  HLT_PFHT_prescaled_branch = tree->GetBranch("HLT_PFHT_prescaled");
  if (HLT_PFHT_prescaled_branch) HLT_PFHT_prescaled_branch->SetAddress(&HLT_PFHT_prescaled_);
  HLT_DiEl_branch = tree->GetBranch("HLT_DiEl");
  if (HLT_DiEl_branch) HLT_DiEl_branch->SetAddress(&HLT_DiEl_);
  HLT_DiMu_branch = tree->GetBranch("HLT_DiMu");
  if (HLT_DiMu_branch) HLT_DiMu_branch->SetAddress(&HLT_DiMu_);
  HLT_MuE_branch = tree->GetBranch("HLT_MuE");
  if (HLT_MuE_branch) HLT_MuE_branch->SetAddress(&HLT_MuE_);
  nPhotons_branch = tree->GetBranch("nPhotons");
  if (nPhotons_branch) nPhotons_branch->SetAddress(&nPhotons_);
  ph_ngoodjets_branch = tree->GetBranch("ph_ngoodjets");
  if (ph_ngoodjets_branch) ph_ngoodjets_branch->SetAddress(&ph_ngoodjets_);
  ph_ngoodbtags_branch = tree->GetBranch("ph_ngoodbtags");
  if (ph_ngoodbtags_branch) ph_ngoodbtags_branch->SetAddress(&ph_ngoodbtags_);
  hardgenpt_branch = tree->GetBranch("hardgenpt");
  if (hardgenpt_branch) hardgenpt_branch->SetAddress(&hardgenpt_);
  calomet_branch = tree->GetBranch("calomet");
  if (calomet_branch) calomet_branch->SetAddress(&calomet_);
  calomet_phi_branch = tree->GetBranch("calomet_phi");
  if (calomet_phi_branch) calomet_phi_branch->SetAddress(&calomet_phi_);
  lep1_pdgid_branch = tree->GetBranch("lep1_pdgid");
  if (lep1_pdgid_branch) lep1_pdgid_branch->SetAddress(&lep1_pdgid_);
  lep1_production_type_branch = tree->GetBranch("lep1_production_type");
  if (lep1_production_type_branch) lep1_production_type_branch->SetAddress(&lep1_production_type_);
  lep1_MiniIso_branch = tree->GetBranch("lep1_MiniIso");
  if (lep1_MiniIso_branch) lep1_MiniIso_branch->SetAddress(&lep1_MiniIso_);
  lep1_relIso_branch = tree->GetBranch("lep1_relIso");
  if (lep1_relIso_branch) lep1_relIso_branch->SetAddress(&lep1_relIso_);
  lep1_passLooseID_branch = tree->GetBranch("lep1_passLooseID");
  if (lep1_passLooseID_branch) lep1_passLooseID_branch->SetAddress(&lep1_passLooseID_);
  lep1_passMediumID_branch = tree->GetBranch("lep1_passMediumID");
  if (lep1_passMediumID_branch) lep1_passMediumID_branch->SetAddress(&lep1_passMediumID_);
  lep1_passTightID_branch = tree->GetBranch("lep1_passTightID");
  if (lep1_passTightID_branch) lep1_passTightID_branch->SetAddress(&lep1_passTightID_);
  lep1_passVeto_branch = tree->GetBranch("lep1_passVeto");
  if (lep1_passVeto_branch) lep1_passVeto_branch->SetAddress(&lep1_passVeto_);
  lep1_mc_motherid_branch = tree->GetBranch("lep1_mc_motherid");
  if (lep1_mc_motherid_branch) lep1_mc_motherid_branch->SetAddress(&lep1_mc_motherid_);
  lep1_dphiMET_branch = tree->GetBranch("lep1_dphiMET");
  if (lep1_dphiMET_branch) lep1_dphiMET_branch->SetAddress(&lep1_dphiMET_);
  lep1_dphiMET_jup_branch = tree->GetBranch("lep1_dphiMET_jup");
  if (lep1_dphiMET_jup_branch) lep1_dphiMET_jup_branch->SetAddress(&lep1_dphiMET_jup_);
  lep1_dphiMET_jdown_branch = tree->GetBranch("lep1_dphiMET_jdown");
  if (lep1_dphiMET_jdown_branch) lep1_dphiMET_jdown_branch->SetAddress(&lep1_dphiMET_jdown_);
  lep1_dphiMET_rl_branch = tree->GetBranch("lep1_dphiMET_rl");
  if (lep1_dphiMET_rl_branch) lep1_dphiMET_rl_branch->SetAddress(&lep1_dphiMET_rl_);
  lep1_dphiMET_rl_jup_branch = tree->GetBranch("lep1_dphiMET_rl_jup");
  if (lep1_dphiMET_rl_jup_branch) lep1_dphiMET_rl_jup_branch->SetAddress(&lep1_dphiMET_rl_jup_);
  lep1_dphiMET_rl_jdown_branch = tree->GetBranch("lep1_dphiMET_rl_jdown");
  if (lep1_dphiMET_rl_jdown_branch) lep1_dphiMET_rl_jdown_branch->SetAddress(&lep1_dphiMET_rl_jdown_);
  lep2_pdgid_branch = tree->GetBranch("lep2_pdgid");
  if (lep2_pdgid_branch) lep2_pdgid_branch->SetAddress(&lep2_pdgid_);
  lep2_production_type_branch = tree->GetBranch("lep2_production_type");
  if (lep2_production_type_branch) lep2_production_type_branch->SetAddress(&lep2_production_type_);
  lep2_MiniIso_branch = tree->GetBranch("lep2_MiniIso");
  if (lep2_MiniIso_branch) lep2_MiniIso_branch->SetAddress(&lep2_MiniIso_);
  lep2_relIso_branch = tree->GetBranch("lep2_relIso");
  if (lep2_relIso_branch) lep2_relIso_branch->SetAddress(&lep2_relIso_);
  lep2_passLooseID_branch = tree->GetBranch("lep2_passLooseID");
  if (lep2_passLooseID_branch) lep2_passLooseID_branch->SetAddress(&lep2_passLooseID_);
  lep2_passMediumID_branch = tree->GetBranch("lep2_passMediumID");
  if (lep2_passMediumID_branch) lep2_passMediumID_branch->SetAddress(&lep2_passMediumID_);
  lep2_passTightID_branch = tree->GetBranch("lep2_passTightID");
  if (lep2_passTightID_branch) lep2_passTightID_branch->SetAddress(&lep2_passTightID_);
  lep2_passVeto_branch = tree->GetBranch("lep2_passVeto");
  if (lep2_passVeto_branch) lep2_passVeto_branch->SetAddress(&lep2_passVeto_);
  lep2_mc_motherid_branch = tree->GetBranch("lep2_mc_motherid");
  if (lep2_mc_motherid_branch) lep2_mc_motherid_branch->SetAddress(&lep2_mc_motherid_);
  lep2_dphiMET_branch = tree->GetBranch("lep2_dphiMET");
  if (lep2_dphiMET_branch) lep2_dphiMET_branch->SetAddress(&lep2_dphiMET_);
  lep2_dphiMET_jup_branch = tree->GetBranch("lep2_dphiMET_jup");
  if (lep2_dphiMET_jup_branch) lep2_dphiMET_jup_branch->SetAddress(&lep2_dphiMET_jup_);
  lep2_dphiMET_jdown_branch = tree->GetBranch("lep2_dphiMET_jdown");
  if (lep2_dphiMET_jdown_branch) lep2_dphiMET_jdown_branch->SetAddress(&lep2_dphiMET_jdown_);
  lep2_dphiMET_rl_branch = tree->GetBranch("lep2_dphiMET_rl");
  if (lep2_dphiMET_rl_branch) lep2_dphiMET_rl_branch->SetAddress(&lep2_dphiMET_rl_);
  lep2_dphiMET_rl_jup_branch = tree->GetBranch("lep2_dphiMET_rl_jup");
  if (lep2_dphiMET_rl_jup_branch) lep2_dphiMET_rl_jup_branch->SetAddress(&lep2_dphiMET_rl_jup_);
  lep2_dphiMET_rl_jdown_branch = tree->GetBranch("lep2_dphiMET_rl_jdown");
  if (lep2_dphiMET_rl_jdown_branch) lep2_dphiMET_rl_jdown_branch->SetAddress(&lep2_dphiMET_rl_jdown_);
  ph_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("ph_sigmaIEtaEta_fill5x5");
  if (ph_sigmaIEtaEta_fill5x5_branch) ph_sigmaIEtaEta_fill5x5_branch->SetAddress(&ph_sigmaIEtaEta_fill5x5_);
  ph_hOverE_branch = tree->GetBranch("ph_hOverE");
  if (ph_hOverE_branch) ph_hOverE_branch->SetAddress(&ph_hOverE_);
  ph_r9_branch = tree->GetBranch("ph_r9");
  if (ph_r9_branch) ph_r9_branch->SetAddress(&ph_r9_);
  ph_chiso_branch = tree->GetBranch("ph_chiso");
  if (ph_chiso_branch) ph_chiso_branch->SetAddress(&ph_chiso_);
  ph_nhiso_branch = tree->GetBranch("ph_nhiso");
  if (ph_nhiso_branch) ph_nhiso_branch->SetAddress(&ph_nhiso_);
  ph_phiso_branch = tree->GetBranch("ph_phiso");
  if (ph_phiso_branch) ph_phiso_branch->SetAddress(&ph_phiso_);
  ph_overlapJetId_branch = tree->GetBranch("ph_overlapJetId");
  if (ph_overlapJetId_branch) ph_overlapJetId_branch->SetAddress(&ph_overlapJetId_);
  ph_pt_branch = tree->GetBranch("ph_pt");
  if (ph_pt_branch) ph_pt_branch->SetAddress(&ph_pt_);
  ph_eta_branch = tree->GetBranch("ph_eta");
  if (ph_eta_branch) ph_eta_branch->SetAddress(&ph_eta_);
  ph_phi_branch = tree->GetBranch("ph_phi");
  if (ph_phi_branch) ph_phi_branch->SetAddress(&ph_phi_);
  ph_mass_branch = tree->GetBranch("ph_mass");
  if (ph_mass_branch) ph_mass_branch->SetAddress(&ph_mass_);
  ph_mcMatchId_branch = tree->GetBranch("ph_mcMatchId");
  if (ph_mcMatchId_branch) ph_mcMatchId_branch->SetAddress(&ph_mcMatchId_);
  ph_genIso04_branch = tree->GetBranch("ph_genIso04");
  if (ph_genIso04_branch) ph_genIso04_branch->SetAddress(&ph_genIso04_);
  ph_drMinParton_branch = tree->GetBranch("ph_drMinParton");
  if (ph_drMinParton_branch) ph_drMinParton_branch->SetAddress(&ph_drMinParton_);
  ngoodjets_branch = tree->GetBranch("ngoodjets");
  if (ngoodjets_branch) ngoodjets_branch->SetAddress(&ngoodjets_);
  ngoodbtags_branch = tree->GetBranch("ngoodbtags");
  if (ngoodbtags_branch) ngoodbtags_branch->SetAddress(&ngoodbtags_);
  nloosebtags_branch = tree->GetBranch("nloosebtags");
  if (nloosebtags_branch) nloosebtags_branch->SetAddress(&nloosebtags_);
  ntightbtags_branch = tree->GetBranch("ntightbtags");
  if (ntightbtags_branch) ntightbtags_branch->SetAddress(&ntightbtags_);
  nanalysisbtags_branch = tree->GetBranch("nanalysisbtags");
  if (nanalysisbtags_branch) nanalysisbtags_branch->SetAddress(&nanalysisbtags_);
  nsoftbtags_branch = tree->GetBranch("nsoftbtags");
  if (nsoftbtags_branch) nsoftbtags_branch->SetAddress(&nsoftbtags_);
  ak4_HT_branch = tree->GetBranch("ak4_HT");
  if (ak4_HT_branch) ak4_HT_branch->SetAddress(&ak4_HT_);
  ak4_htratiom_branch = tree->GetBranch("ak4_htratiom");
  if (ak4_htratiom_branch) ak4_htratiom_branch->SetAddress(&ak4_htratiom_);
  dphi_ak4pfjet_met_branch = tree->GetBranch("dphi_ak4pfjet_met");
  if (dphi_ak4pfjet_met_branch) dphi_ak4pfjet_met_branch->SetAddress(&dphi_ak4pfjet_met_);
  ak4pfjets_passMEDbtag_branch = tree->GetBranch("ak4pfjets_passMEDbtag");
  if (ak4pfjets_passMEDbtag_branch) ak4pfjets_passMEDbtag_branch->SetAddress(&ak4pfjets_passMEDbtag_);
  ak4pfjets_CSV_branch = tree->GetBranch("ak4pfjets_CSV");
  if (ak4pfjets_CSV_branch) ak4pfjets_CSV_branch->SetAddress(&ak4pfjets_CSV_);
  ak4pfjets_mva_branch = tree->GetBranch("ak4pfjets_mva");
  if (ak4pfjets_mva_branch) ak4pfjets_mva_branch->SetAddress(&ak4pfjets_mva_);
  ak4pfjets_parton_flavor_branch = tree->GetBranch("ak4pfjets_parton_flavor");
  if (ak4pfjets_parton_flavor_branch) ak4pfjets_parton_flavor_branch->SetAddress(&ak4pfjets_parton_flavor_);
  ak4pfjets_hadron_flavor_branch = tree->GetBranch("ak4pfjets_hadron_flavor");
  if (ak4pfjets_hadron_flavor_branch) ak4pfjets_hadron_flavor_branch->SetAddress(&ak4pfjets_hadron_flavor_);
  ak4pfjets_loose_puid_branch = tree->GetBranch("ak4pfjets_loose_puid");
  if (ak4pfjets_loose_puid_branch) ak4pfjets_loose_puid_branch->SetAddress(&ak4pfjets_loose_puid_);
  ak4pfjets_loose_pfid_branch = tree->GetBranch("ak4pfjets_loose_pfid");
  if (ak4pfjets_loose_pfid_branch) ak4pfjets_loose_pfid_branch->SetAddress(&ak4pfjets_loose_pfid_);
  jup_ngoodjets_branch = tree->GetBranch("jup_ngoodjets");
  if (jup_ngoodjets_branch) jup_ngoodjets_branch->SetAddress(&jup_ngoodjets_);
  jup_ngoodbtags_branch = tree->GetBranch("jup_ngoodbtags");
  if (jup_ngoodbtags_branch) jup_ngoodbtags_branch->SetAddress(&jup_ngoodbtags_);
  jup_nloosebtags_branch = tree->GetBranch("jup_nloosebtags");
  if (jup_nloosebtags_branch) jup_nloosebtags_branch->SetAddress(&jup_nloosebtags_);
  jup_ntightbtags_branch = tree->GetBranch("jup_ntightbtags");
  if (jup_ntightbtags_branch) jup_ntightbtags_branch->SetAddress(&jup_ntightbtags_);
  jup_nanalysisbtags_branch = tree->GetBranch("jup_nanalysisbtags");
  if (jup_nanalysisbtags_branch) jup_nanalysisbtags_branch->SetAddress(&jup_nanalysisbtags_);
  jup_nsoftbtags_branch = tree->GetBranch("jup_nsoftbtags");
  if (jup_nsoftbtags_branch) jup_nsoftbtags_branch->SetAddress(&jup_nsoftbtags_);
  jup_ak4_HT_branch = tree->GetBranch("jup_ak4_HT");
  if (jup_ak4_HT_branch) jup_ak4_HT_branch->SetAddress(&jup_ak4_HT_);
  jup_ak4_htratiom_branch = tree->GetBranch("jup_ak4_htratiom");
  if (jup_ak4_htratiom_branch) jup_ak4_htratiom_branch->SetAddress(&jup_ak4_htratiom_);
  jup_dphi_ak4pfjet_met_branch = tree->GetBranch("jup_dphi_ak4pfjet_met");
  if (jup_dphi_ak4pfjet_met_branch) jup_dphi_ak4pfjet_met_branch->SetAddress(&jup_dphi_ak4pfjet_met_);
  jup_ak4pfjets_passMEDbtag_branch = tree->GetBranch("jup_ak4pfjets_passMEDbtag");
  if (jup_ak4pfjets_passMEDbtag_branch) jup_ak4pfjets_passMEDbtag_branch->SetAddress(&jup_ak4pfjets_passMEDbtag_);
  jup_ak4pfjets_CSV_branch = tree->GetBranch("jup_ak4pfjets_CSV");
  if (jup_ak4pfjets_CSV_branch) jup_ak4pfjets_CSV_branch->SetAddress(&jup_ak4pfjets_CSV_);
  jup_ak4pfjets_mva_branch = tree->GetBranch("jup_ak4pfjets_mva");
  if (jup_ak4pfjets_mva_branch) jup_ak4pfjets_mva_branch->SetAddress(&jup_ak4pfjets_mva_);
  jup_ak4pfjets_parton_flavor_branch = tree->GetBranch("jup_ak4pfjets_parton_flavor");
  if (jup_ak4pfjets_parton_flavor_branch) jup_ak4pfjets_parton_flavor_branch->SetAddress(&jup_ak4pfjets_parton_flavor_);
  jup_ak4pfjets_hadron_flavor_branch = tree->GetBranch("jup_ak4pfjets_hadron_flavor");
  if (jup_ak4pfjets_hadron_flavor_branch) jup_ak4pfjets_hadron_flavor_branch->SetAddress(&jup_ak4pfjets_hadron_flavor_);
  jup_ak4pfjets_loose_puid_branch = tree->GetBranch("jup_ak4pfjets_loose_puid");
  if (jup_ak4pfjets_loose_puid_branch) jup_ak4pfjets_loose_puid_branch->SetAddress(&jup_ak4pfjets_loose_puid_);
  jup_ak4pfjets_loose_pfid_branch = tree->GetBranch("jup_ak4pfjets_loose_pfid");
  if (jup_ak4pfjets_loose_pfid_branch) jup_ak4pfjets_loose_pfid_branch->SetAddress(&jup_ak4pfjets_loose_pfid_);
  jdown_ngoodjets_branch = tree->GetBranch("jdown_ngoodjets");
  if (jdown_ngoodjets_branch) jdown_ngoodjets_branch->SetAddress(&jdown_ngoodjets_);
  jdown_ngoodbtags_branch = tree->GetBranch("jdown_ngoodbtags");
  if (jdown_ngoodbtags_branch) jdown_ngoodbtags_branch->SetAddress(&jdown_ngoodbtags_);
  jdown_nloosebtags_branch = tree->GetBranch("jdown_nloosebtags");
  if (jdown_nloosebtags_branch) jdown_nloosebtags_branch->SetAddress(&jdown_nloosebtags_);
  jdown_ntightbtags_branch = tree->GetBranch("jdown_ntightbtags");
  if (jdown_ntightbtags_branch) jdown_ntightbtags_branch->SetAddress(&jdown_ntightbtags_);
  jdown_nanalysisbtags_branch = tree->GetBranch("jdown_nanalysisbtags");
  if (jdown_nanalysisbtags_branch) jdown_nanalysisbtags_branch->SetAddress(&jdown_nanalysisbtags_);
  jdown_nsoftbtags_branch = tree->GetBranch("jdown_nsoftbtags");
  if (jdown_nsoftbtags_branch) jdown_nsoftbtags_branch->SetAddress(&jdown_nsoftbtags_);
  jdown_ak4_HT_branch = tree->GetBranch("jdown_ak4_HT");
  if (jdown_ak4_HT_branch) jdown_ak4_HT_branch->SetAddress(&jdown_ak4_HT_);
  jdown_ak4_htratiom_branch = tree->GetBranch("jdown_ak4_htratiom");
  if (jdown_ak4_htratiom_branch) jdown_ak4_htratiom_branch->SetAddress(&jdown_ak4_htratiom_);
  jdown_dphi_ak4pfjet_met_branch = tree->GetBranch("jdown_dphi_ak4pfjet_met");
  if (jdown_dphi_ak4pfjet_met_branch) jdown_dphi_ak4pfjet_met_branch->SetAddress(&jdown_dphi_ak4pfjet_met_);
  jdown_ak4pfjets_passMEDbtag_branch = tree->GetBranch("jdown_ak4pfjets_passMEDbtag");
  if (jdown_ak4pfjets_passMEDbtag_branch) jdown_ak4pfjets_passMEDbtag_branch->SetAddress(&jdown_ak4pfjets_passMEDbtag_);
  jdown_ak4pfjets_CSV_branch = tree->GetBranch("jdown_ak4pfjets_CSV");
  if (jdown_ak4pfjets_CSV_branch) jdown_ak4pfjets_CSV_branch->SetAddress(&jdown_ak4pfjets_CSV_);
  jdown_ak4pfjets_mva_branch = tree->GetBranch("jdown_ak4pfjets_mva");
  if (jdown_ak4pfjets_mva_branch) jdown_ak4pfjets_mva_branch->SetAddress(&jdown_ak4pfjets_mva_);
  jdown_ak4pfjets_parton_flavor_branch = tree->GetBranch("jdown_ak4pfjets_parton_flavor");
  if (jdown_ak4pfjets_parton_flavor_branch) jdown_ak4pfjets_parton_flavor_branch->SetAddress(&jdown_ak4pfjets_parton_flavor_);
  jdown_ak4pfjets_hadron_flavor_branch = tree->GetBranch("jdown_ak4pfjets_hadron_flavor");
  if (jdown_ak4pfjets_hadron_flavor_branch) jdown_ak4pfjets_hadron_flavor_branch->SetAddress(&jdown_ak4pfjets_hadron_flavor_);
  jdown_ak4pfjets_loose_puid_branch = tree->GetBranch("jdown_ak4pfjets_loose_puid");
  if (jdown_ak4pfjets_loose_puid_branch) jdown_ak4pfjets_loose_puid_branch->SetAddress(&jdown_ak4pfjets_loose_puid_);
  jdown_ak4pfjets_loose_pfid_branch = tree->GetBranch("jdown_ak4pfjets_loose_pfid");
  if (jdown_ak4pfjets_loose_pfid_branch) jdown_ak4pfjets_loose_pfid_branch->SetAddress(&jdown_ak4pfjets_loose_pfid_);
  genleps_isfromt_branch = tree->GetBranch("genleps_isfromt");
  if (genleps_isfromt_branch) genleps_isfromt_branch->SetAddress(&genleps_isfromt_);
  genleps_id_branch = tree->GetBranch("genleps_id");
  if (genleps_id_branch) genleps_id_branch->SetAddress(&genleps_id_);
  genleps__genpsidx_branch = tree->GetBranch("genleps__genpsidx");
  if (genleps__genpsidx_branch) genleps__genpsidx_branch->SetAddress(&genleps__genpsidx_);
  genleps_status_branch = tree->GetBranch("genleps_status");
  if (genleps_status_branch) genleps_status_branch->SetAddress(&genleps_status_);
  genleps_fromHardProcessDecayed_branch = tree->GetBranch("genleps_fromHardProcessDecayed");
  if (genleps_fromHardProcessDecayed_branch) genleps_fromHardProcessDecayed_branch->SetAddress(&genleps_fromHardProcessDecayed_);
  genleps_fromHardProcessFinalState_branch = tree->GetBranch("genleps_fromHardProcessFinalState");
  if (genleps_fromHardProcessFinalState_branch) genleps_fromHardProcessFinalState_branch->SetAddress(&genleps_fromHardProcessFinalState_);
  genleps_isHardProcess_branch = tree->GetBranch("genleps_isHardProcess");
  if (genleps_isHardProcess_branch) genleps_isHardProcess_branch->SetAddress(&genleps_isHardProcess_);
  genleps_isLastCopy_branch = tree->GetBranch("genleps_isLastCopy");
  if (genleps_isLastCopy_branch) genleps_isLastCopy_branch->SetAddress(&genleps_isLastCopy_);
  genleps_gentaudecay_branch = tree->GetBranch("genleps_gentaudecay");
  if (genleps_gentaudecay_branch) genleps_gentaudecay_branch->SetAddress(&genleps_gentaudecay_);
  gen_nfromtleps__branch = tree->GetBranch("gen_nfromtleps_");
  if (gen_nfromtleps__branch) gen_nfromtleps__branch->SetAddress(&gen_nfromtleps__);
  genleps_motherid_branch = tree->GetBranch("genleps_motherid");
  if (genleps_motherid_branch) genleps_motherid_branch->SetAddress(&genleps_motherid_);
  genleps_motheridx_branch = tree->GetBranch("genleps_motheridx");
  if (genleps_motheridx_branch) genleps_motheridx_branch->SetAddress(&genleps_motheridx_);
  genleps_motherstatus_branch = tree->GetBranch("genleps_motherstatus");
  if (genleps_motherstatus_branch) genleps_motherstatus_branch->SetAddress(&genleps_motherstatus_);
  genleps_gmotherid_branch = tree->GetBranch("genleps_gmotherid");
  if (genleps_gmotherid_branch) genleps_gmotherid_branch->SetAddress(&genleps_gmotherid_);
  genleps_gmotheridx_branch = tree->GetBranch("genleps_gmotheridx");
  if (genleps_gmotheridx_branch) genleps_gmotheridx_branch->SetAddress(&genleps_gmotheridx_);
  genleps_gmotherstatus_branch = tree->GetBranch("genleps_gmotherstatus");
  if (genleps_gmotherstatus_branch) genleps_gmotherstatus_branch->SetAddress(&genleps_gmotherstatus_);
  gennus_isfromt_branch = tree->GetBranch("gennus_isfromt");
  if (gennus_isfromt_branch) gennus_isfromt_branch->SetAddress(&gennus_isfromt_);
  gennus_id_branch = tree->GetBranch("gennus_id");
  if (gennus_id_branch) gennus_id_branch->SetAddress(&gennus_id_);
  gennus__genpsidx_branch = tree->GetBranch("gennus__genpsidx");
  if (gennus__genpsidx_branch) gennus__genpsidx_branch->SetAddress(&gennus__genpsidx_);
  gennus_status_branch = tree->GetBranch("gennus_status");
  if (gennus_status_branch) gennus_status_branch->SetAddress(&gennus_status_);
  gennus_fromHardProcessDecayed_branch = tree->GetBranch("gennus_fromHardProcessDecayed");
  if (gennus_fromHardProcessDecayed_branch) gennus_fromHardProcessDecayed_branch->SetAddress(&gennus_fromHardProcessDecayed_);
  gennus_fromHardProcessFinalState_branch = tree->GetBranch("gennus_fromHardProcessFinalState");
  if (gennus_fromHardProcessFinalState_branch) gennus_fromHardProcessFinalState_branch->SetAddress(&gennus_fromHardProcessFinalState_);
  gennus_isHardProcess_branch = tree->GetBranch("gennus_isHardProcess");
  if (gennus_isHardProcess_branch) gennus_isHardProcess_branch->SetAddress(&gennus_isHardProcess_);
  gennus_isLastCopy_branch = tree->GetBranch("gennus_isLastCopy");
  if (gennus_isLastCopy_branch) gennus_isLastCopy_branch->SetAddress(&gennus_isLastCopy_);
  gennus_gentaudecay_branch = tree->GetBranch("gennus_gentaudecay");
  if (gennus_gentaudecay_branch) gennus_gentaudecay_branch->SetAddress(&gennus_gentaudecay_);
  gen_nfromtnus__branch = tree->GetBranch("gen_nfromtnus_");
  if (gen_nfromtnus__branch) gen_nfromtnus__branch->SetAddress(&gen_nfromtnus__);
  gennus_motherid_branch = tree->GetBranch("gennus_motherid");
  if (gennus_motherid_branch) gennus_motherid_branch->SetAddress(&gennus_motherid_);
  gennus_motheridx_branch = tree->GetBranch("gennus_motheridx");
  if (gennus_motheridx_branch) gennus_motheridx_branch->SetAddress(&gennus_motheridx_);
  gennus_motherstatus_branch = tree->GetBranch("gennus_motherstatus");
  if (gennus_motherstatus_branch) gennus_motherstatus_branch->SetAddress(&gennus_motherstatus_);
  gennus_gmotherid_branch = tree->GetBranch("gennus_gmotherid");
  if (gennus_gmotherid_branch) gennus_gmotherid_branch->SetAddress(&gennus_gmotherid_);
  gennus_gmotheridx_branch = tree->GetBranch("gennus_gmotheridx");
  if (gennus_gmotheridx_branch) gennus_gmotheridx_branch->SetAddress(&gennus_gmotheridx_);
  gennus_gmotherstatus_branch = tree->GetBranch("gennus_gmotherstatus");
  if (gennus_gmotherstatus_branch) gennus_gmotherstatus_branch->SetAddress(&gennus_gmotherstatus_);
  genqs_isfromt_branch = tree->GetBranch("genqs_isfromt");
  if (genqs_isfromt_branch) genqs_isfromt_branch->SetAddress(&genqs_isfromt_);
  genqs_id_branch = tree->GetBranch("genqs_id");
  if (genqs_id_branch) genqs_id_branch->SetAddress(&genqs_id_);
  genqs__genpsidx_branch = tree->GetBranch("genqs__genpsidx");
  if (genqs__genpsidx_branch) genqs__genpsidx_branch->SetAddress(&genqs__genpsidx_);
  genqs_status_branch = tree->GetBranch("genqs_status");
  if (genqs_status_branch) genqs_status_branch->SetAddress(&genqs_status_);
  genqs_fromHardProcessDecayed_branch = tree->GetBranch("genqs_fromHardProcessDecayed");
  if (genqs_fromHardProcessDecayed_branch) genqs_fromHardProcessDecayed_branch->SetAddress(&genqs_fromHardProcessDecayed_);
  genqs_fromHardProcessFinalState_branch = tree->GetBranch("genqs_fromHardProcessFinalState");
  if (genqs_fromHardProcessFinalState_branch) genqs_fromHardProcessFinalState_branch->SetAddress(&genqs_fromHardProcessFinalState_);
  genqs_isHardProcess_branch = tree->GetBranch("genqs_isHardProcess");
  if (genqs_isHardProcess_branch) genqs_isHardProcess_branch->SetAddress(&genqs_isHardProcess_);
  genqs_isLastCopy_branch = tree->GetBranch("genqs_isLastCopy");
  if (genqs_isLastCopy_branch) genqs_isLastCopy_branch->SetAddress(&genqs_isLastCopy_);
  genqs_gentaudecay_branch = tree->GetBranch("genqs_gentaudecay");
  if (genqs_gentaudecay_branch) genqs_gentaudecay_branch->SetAddress(&genqs_gentaudecay_);
  gen_nfromtqs__branch = tree->GetBranch("gen_nfromtqs_");
  if (gen_nfromtqs__branch) gen_nfromtqs__branch->SetAddress(&gen_nfromtqs__);
  genqs_motherid_branch = tree->GetBranch("genqs_motherid");
  if (genqs_motherid_branch) genqs_motherid_branch->SetAddress(&genqs_motherid_);
  genqs_motheridx_branch = tree->GetBranch("genqs_motheridx");
  if (genqs_motheridx_branch) genqs_motheridx_branch->SetAddress(&genqs_motheridx_);
  genqs_motherstatus_branch = tree->GetBranch("genqs_motherstatus");
  if (genqs_motherstatus_branch) genqs_motherstatus_branch->SetAddress(&genqs_motherstatus_);
  genqs_gmotherid_branch = tree->GetBranch("genqs_gmotherid");
  if (genqs_gmotherid_branch) genqs_gmotherid_branch->SetAddress(&genqs_gmotherid_);
  genqs_gmotheridx_branch = tree->GetBranch("genqs_gmotheridx");
  if (genqs_gmotheridx_branch) genqs_gmotheridx_branch->SetAddress(&genqs_gmotheridx_);
  genqs_gmotherstatus_branch = tree->GetBranch("genqs_gmotherstatus");
  if (genqs_gmotherstatus_branch) genqs_gmotherstatus_branch->SetAddress(&genqs_gmotherstatus_);
  genbosons_isfromt_branch = tree->GetBranch("genbosons_isfromt");
  if (genbosons_isfromt_branch) genbosons_isfromt_branch->SetAddress(&genbosons_isfromt_);
  genbosons_id_branch = tree->GetBranch("genbosons_id");
  if (genbosons_id_branch) genbosons_id_branch->SetAddress(&genbosons_id_);
  genbosons__genpsidx_branch = tree->GetBranch("genbosons__genpsidx");
  if (genbosons__genpsidx_branch) genbosons__genpsidx_branch->SetAddress(&genbosons__genpsidx_);
  genbosons_status_branch = tree->GetBranch("genbosons_status");
  if (genbosons_status_branch) genbosons_status_branch->SetAddress(&genbosons_status_);
  genbosons_fromHardProcessDecayed_branch = tree->GetBranch("genbosons_fromHardProcessDecayed");
  if (genbosons_fromHardProcessDecayed_branch) genbosons_fromHardProcessDecayed_branch->SetAddress(&genbosons_fromHardProcessDecayed_);
  genbosons_fromHardProcessFinalState_branch = tree->GetBranch("genbosons_fromHardProcessFinalState");
  if (genbosons_fromHardProcessFinalState_branch) genbosons_fromHardProcessFinalState_branch->SetAddress(&genbosons_fromHardProcessFinalState_);
  genbosons_isHardProcess_branch = tree->GetBranch("genbosons_isHardProcess");
  if (genbosons_isHardProcess_branch) genbosons_isHardProcess_branch->SetAddress(&genbosons_isHardProcess_);
  genbosons_isLastCopy_branch = tree->GetBranch("genbosons_isLastCopy");
  if (genbosons_isLastCopy_branch) genbosons_isLastCopy_branch->SetAddress(&genbosons_isLastCopy_);
  genbosons_gentaudecay_branch = tree->GetBranch("genbosons_gentaudecay");
  if (genbosons_gentaudecay_branch) genbosons_gentaudecay_branch->SetAddress(&genbosons_gentaudecay_);
  gen_nfromtbosons__branch = tree->GetBranch("gen_nfromtbosons_");
  if (gen_nfromtbosons__branch) gen_nfromtbosons__branch->SetAddress(&gen_nfromtbosons__);
  genbosons_motherid_branch = tree->GetBranch("genbosons_motherid");
  if (genbosons_motherid_branch) genbosons_motherid_branch->SetAddress(&genbosons_motherid_);
  genbosons_motheridx_branch = tree->GetBranch("genbosons_motheridx");
  if (genbosons_motheridx_branch) genbosons_motheridx_branch->SetAddress(&genbosons_motheridx_);
  genbosons_motherstatus_branch = tree->GetBranch("genbosons_motherstatus");
  if (genbosons_motherstatus_branch) genbosons_motherstatus_branch->SetAddress(&genbosons_motherstatus_);
  genbosons_gmotherid_branch = tree->GetBranch("genbosons_gmotherid");
  if (genbosons_gmotherid_branch) genbosons_gmotherid_branch->SetAddress(&genbosons_gmotherid_);
  genbosons_gmotheridx_branch = tree->GetBranch("genbosons_gmotheridx");
  if (genbosons_gmotheridx_branch) genbosons_gmotheridx_branch->SetAddress(&genbosons_gmotheridx_);
  genbosons_gmotherstatus_branch = tree->GetBranch("genbosons_gmotherstatus");
  if (genbosons_gmotherstatus_branch) genbosons_gmotherstatus_branch->SetAddress(&genbosons_gmotherstatus_);
  gensusy_isfromt_branch = tree->GetBranch("gensusy_isfromt");
  if (gensusy_isfromt_branch) gensusy_isfromt_branch->SetAddress(&gensusy_isfromt_);
  gensusy_id_branch = tree->GetBranch("gensusy_id");
  if (gensusy_id_branch) gensusy_id_branch->SetAddress(&gensusy_id_);
  gensusy__genpsidx_branch = tree->GetBranch("gensusy__genpsidx");
  if (gensusy__genpsidx_branch) gensusy__genpsidx_branch->SetAddress(&gensusy__genpsidx_);
  gensusy_status_branch = tree->GetBranch("gensusy_status");
  if (gensusy_status_branch) gensusy_status_branch->SetAddress(&gensusy_status_);
  gensusy_fromHardProcessDecayed_branch = tree->GetBranch("gensusy_fromHardProcessDecayed");
  if (gensusy_fromHardProcessDecayed_branch) gensusy_fromHardProcessDecayed_branch->SetAddress(&gensusy_fromHardProcessDecayed_);
  gensusy_fromHardProcessFinalState_branch = tree->GetBranch("gensusy_fromHardProcessFinalState");
  if (gensusy_fromHardProcessFinalState_branch) gensusy_fromHardProcessFinalState_branch->SetAddress(&gensusy_fromHardProcessFinalState_);
  gensusy_isHardProcess_branch = tree->GetBranch("gensusy_isHardProcess");
  if (gensusy_isHardProcess_branch) gensusy_isHardProcess_branch->SetAddress(&gensusy_isHardProcess_);
  gensusy_isLastCopy_branch = tree->GetBranch("gensusy_isLastCopy");
  if (gensusy_isLastCopy_branch) gensusy_isLastCopy_branch->SetAddress(&gensusy_isLastCopy_);
  gensusy_gentaudecay_branch = tree->GetBranch("gensusy_gentaudecay");
  if (gensusy_gentaudecay_branch) gensusy_gentaudecay_branch->SetAddress(&gensusy_gentaudecay_);
  gen_nfromtsusy__branch = tree->GetBranch("gen_nfromtsusy_");
  if (gen_nfromtsusy__branch) gen_nfromtsusy__branch->SetAddress(&gen_nfromtsusy__);
  gensusy_motherid_branch = tree->GetBranch("gensusy_motherid");
  if (gensusy_motherid_branch) gensusy_motherid_branch->SetAddress(&gensusy_motherid_);
  gensusy_motheridx_branch = tree->GetBranch("gensusy_motheridx");
  if (gensusy_motheridx_branch) gensusy_motheridx_branch->SetAddress(&gensusy_motheridx_);
  gensusy_motherstatus_branch = tree->GetBranch("gensusy_motherstatus");
  if (gensusy_motherstatus_branch) gensusy_motherstatus_branch->SetAddress(&gensusy_motherstatus_);
  gensusy_gmotherid_branch = tree->GetBranch("gensusy_gmotherid");
  if (gensusy_gmotherid_branch) gensusy_gmotherid_branch->SetAddress(&gensusy_gmotherid_);
  gensusy_gmotheridx_branch = tree->GetBranch("gensusy_gmotheridx");
  if (gensusy_gmotheridx_branch) gensusy_gmotheridx_branch->SetAddress(&gensusy_gmotheridx_);
  gensusy_gmotherstatus_branch = tree->GetBranch("gensusy_gmotherstatus");
  if (gensusy_gmotherstatus_branch) gensusy_gmotherstatus_branch->SetAddress(&gensusy_gmotherstatus_);
  tau_IDnames_branch = tree->GetBranch("tau_IDnames");
  if (tau_IDnames_branch) tau_IDnames_branch->SetAddress(&tau_IDnames_);
  tau_isocand_p4_branch = tree->GetBranch("tau_isocand_p4");
  if (tau_isocand_p4_branch) tau_isocand_p4_branch->SetAddress(&tau_isocand_p4_);
  tau_sigcand_p4_branch = tree->GetBranch("tau_sigcand_p4");
  if (tau_sigcand_p4_branch) tau_sigcand_p4_branch->SetAddress(&tau_sigcand_p4_);
  tau_ID_branch = tree->GetBranch("tau_ID");
  if (tau_ID_branch) tau_ID_branch->SetAddress(&tau_ID_);
  tau_passID_branch = tree->GetBranch("tau_passID");
  if (tau_passID_branch) tau_passID_branch->SetAddress(&tau_passID_);
  ngoodtaus_branch = tree->GetBranch("ngoodtaus");
  if (ngoodtaus_branch) ngoodtaus_branch->SetAddress(&ngoodtaus_);
  tau_againstMuonTight_branch = tree->GetBranch("tau_againstMuonTight");
  if (tau_againstMuonTight_branch) tau_againstMuonTight_branch->SetAddress(&tau_againstMuonTight_);
  tau_againstElectronLoose_branch = tree->GetBranch("tau_againstElectronLoose");
  if (tau_againstElectronLoose_branch) tau_againstElectronLoose_branch->SetAddress(&tau_againstElectronLoose_);
  tau_isVetoTau_branch = tree->GetBranch("tau_isVetoTau");
  if (tau_isVetoTau_branch) tau_isVetoTau_branch->SetAddress(&tau_isVetoTau_);
  isoTracks_charge_branch = tree->GetBranch("isoTracks_charge");
  if (isoTracks_charge_branch) isoTracks_charge_branch->SetAddress(&isoTracks_charge_);
  isoTracks_absIso_branch = tree->GetBranch("isoTracks_absIso");
  if (isoTracks_absIso_branch) isoTracks_absIso_branch->SetAddress(&isoTracks_absIso_);
  isoTracks_dz_branch = tree->GetBranch("isoTracks_dz");
  if (isoTracks_dz_branch) isoTracks_dz_branch->SetAddress(&isoTracks_dz_);
  isoTracks_pdgId_branch = tree->GetBranch("isoTracks_pdgId");
  if (isoTracks_pdgId_branch) isoTracks_pdgId_branch->SetAddress(&isoTracks_pdgId_);
  isoTracks_isVetoTrack_branch = tree->GetBranch("isoTracks_isVetoTrack");
  if (isoTracks_isVetoTrack_branch) isoTracks_isVetoTrack_branch->SetAddress(&isoTracks_isVetoTrack_);
  isoTracks_isVetoTrack_v2_branch = tree->GetBranch("isoTracks_isVetoTrack_v2");
  if (isoTracks_isVetoTrack_v2_branch) isoTracks_isVetoTrack_v2_branch->SetAddress(&isoTracks_isVetoTrack_v2_);
  isoTracks_isVetoTrack_v3_branch = tree->GetBranch("isoTracks_isVetoTrack_v3");
  if (isoTracks_isVetoTrack_v3_branch) isoTracks_isVetoTrack_v3_branch->SetAddress(&isoTracks_isVetoTrack_v3_);
  filt_cscbeamhalo_branch = tree->GetBranch("filt_cscbeamhalo");
  if (filt_cscbeamhalo_branch) filt_cscbeamhalo_branch->SetAddress(&filt_cscbeamhalo_);
  filt_cscbeamhalo2015_branch = tree->GetBranch("filt_cscbeamhalo2015");
  if (filt_cscbeamhalo2015_branch) filt_cscbeamhalo2015_branch->SetAddress(&filt_cscbeamhalo2015_);
  filt_globaltighthalo2016_branch = tree->GetBranch("filt_globaltighthalo2016");
  if (filt_globaltighthalo2016_branch) filt_globaltighthalo2016_branch->SetAddress(&filt_globaltighthalo2016_);
  filt_globalsupertighthalo2016_branch = tree->GetBranch("filt_globalsupertighthalo2016");
  if (filt_globalsupertighthalo2016_branch) filt_globalsupertighthalo2016_branch->SetAddress(&filt_globalsupertighthalo2016_);
  filt_ecallaser_branch = tree->GetBranch("filt_ecallaser");
  if (filt_ecallaser_branch) filt_ecallaser_branch->SetAddress(&filt_ecallaser_);
  filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
  if (filt_ecaltp_branch) filt_ecaltp_branch->SetAddress(&filt_ecaltp_);
  filt_eebadsc_branch = tree->GetBranch("filt_eebadsc");
  if (filt_eebadsc_branch) filt_eebadsc_branch->SetAddress(&filt_eebadsc_);
  filt_goodvtx_branch = tree->GetBranch("filt_goodvtx");
  if (filt_goodvtx_branch) filt_goodvtx_branch->SetAddress(&filt_goodvtx_);
  filt_badevents_branch = tree->GetBranch("filt_badevents");
  if (filt_badevents_branch) filt_badevents_branch->SetAddress(&filt_badevents_);
  filt_hbhenoise_branch = tree->GetBranch("filt_hbhenoise");
  if (filt_hbhenoise_branch) filt_hbhenoise_branch->SetAddress(&filt_hbhenoise_);
  filt_hbheisonoise_branch = tree->GetBranch("filt_hbheisonoise");
  if (filt_hbheisonoise_branch) filt_hbheisonoise_branch->SetAddress(&filt_hbheisonoise_);
  filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
  if (filt_hcallaser_branch) filt_hcallaser_branch->SetAddress(&filt_hcallaser_);
  filt_trkfail_branch = tree->GetBranch("filt_trkfail");
  if (filt_trkfail_branch) filt_trkfail_branch->SetAddress(&filt_trkfail_);
  filt_trkPOG_branch = tree->GetBranch("filt_trkPOG");
  if (filt_trkPOG_branch) filt_trkPOG_branch->SetAddress(&filt_trkPOG_);
  filt_trkPOG_logerr_tmc_branch = tree->GetBranch("filt_trkPOG_logerr_tmc");
  if (filt_trkPOG_logerr_tmc_branch) filt_trkPOG_logerr_tmc_branch->SetAddress(&filt_trkPOG_logerr_tmc_);
  filt_trkPOG_tmc_branch = tree->GetBranch("filt_trkPOG_tmc");
  if (filt_trkPOG_tmc_branch) filt_trkPOG_tmc_branch->SetAddress(&filt_trkPOG_tmc_);
  filt_trkPOG_tms_branch = tree->GetBranch("filt_trkPOG_tms");
  if (filt_trkPOG_tms_branch) filt_trkPOG_tms_branch->SetAddress(&filt_trkPOG_tms_);
  firstGoodVtxIdx_branch = tree->GetBranch("firstGoodVtxIdx");
  if (firstGoodVtxIdx_branch) firstGoodVtxIdx_branch->SetAddress(&firstGoodVtxIdx_);
  filt_badChargedCandidateFilter_branch = tree->GetBranch("filt_badChargedCandidateFilter");
  if (filt_badChargedCandidateFilter_branch) filt_badChargedCandidateFilter_branch->SetAddress(&filt_badChargedCandidateFilter_);
  filt_badMuonFilter_branch = tree->GetBranch("filt_badMuonFilter");
  if (filt_badMuonFilter_branch) filt_badMuonFilter_branch->SetAddress(&filt_badMuonFilter_);
  filt_met_branch = tree->GetBranch("filt_met");
  if (filt_met_branch) filt_met_branch->SetAddress(&filt_met_);
  filt_fastsimjets_branch = tree->GetBranch("filt_fastsimjets");
  if (filt_fastsimjets_branch) filt_fastsimjets_branch->SetAddress(&filt_fastsimjets_);
  filt_fastsimjets_jup_branch = tree->GetBranch("filt_fastsimjets_jup");
  if (filt_fastsimjets_jup_branch) filt_fastsimjets_jup_branch->SetAddress(&filt_fastsimjets_jup_);
  filt_fastsimjets_jdown_branch = tree->GetBranch("filt_fastsimjets_jdown");
  if (filt_fastsimjets_jdown_branch) filt_fastsimjets_jdown_branch->SetAddress(&filt_fastsimjets_jdown_);
  filt_jetWithBadMuon_branch = tree->GetBranch("filt_jetWithBadMuon");
  if (filt_jetWithBadMuon_branch) filt_jetWithBadMuon_branch->SetAddress(&filt_jetWithBadMuon_);
  filt_jetWithBadMuon_jup_branch = tree->GetBranch("filt_jetWithBadMuon_jup");
  if (filt_jetWithBadMuon_jup_branch) filt_jetWithBadMuon_jup_branch->SetAddress(&filt_jetWithBadMuon_jup_);
  filt_jetWithBadMuon_jdown_branch = tree->GetBranch("filt_jetWithBadMuon_jdown");
  if (filt_jetWithBadMuon_jdown_branch) filt_jetWithBadMuon_jdown_branch->SetAddress(&filt_jetWithBadMuon_jdown_);
  filt_pfovercalomet_branch = tree->GetBranch("filt_pfovercalomet");
  if (filt_pfovercalomet_branch) filt_pfovercalomet_branch->SetAddress(&filt_pfovercalomet_);
  filt_badmuons_branch = tree->GetBranch("filt_badmuons");
  if (filt_badmuons_branch) filt_badmuons_branch->SetAddress(&filt_badmuons_);
  filt_duplicatemuons_branch = tree->GetBranch("filt_duplicatemuons");
  if (filt_duplicatemuons_branch) filt_duplicatemuons_branch->SetAddress(&filt_duplicatemuons_);
  filt_nobadmuons_branch = tree->GetBranch("filt_nobadmuons");
  if (filt_nobadmuons_branch) filt_nobadmuons_branch->SetAddress(&filt_nobadmuons_);

  tree->SetMakeClass(0);
}

extern "C" void CMS3::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  run_isLoaded = false;
  ls_isLoaded = false;
  evt_isLoaded = false;
  nvtxs_isLoaded = false;
  pu_nvtxs_isLoaded = false;
  pfmet_isLoaded = false;
  pfmet_phi_isLoaded = false;
  pfmet_jup_isLoaded = false;
  pfmet_phi_jup_isLoaded = false;
  pfmet_jdown_isLoaded = false;
  pfmet_phi_jdown_isLoaded = false;
  pfmet_rl_isLoaded = false;
  pfmet_phi_rl_isLoaded = false;
  pfmet_rl_jup_isLoaded = false;
  pfmet_phi_rl_jup_isLoaded = false;
  pfmet_rl_jdown_isLoaded = false;
  pfmet_phi_rl_jdown_isLoaded = false;
  pfmet_egclean_isLoaded = false;
  pfmet_egclean_phi_isLoaded = false;
  pfmet_muegclean_isLoaded = false;
  pfmet_muegclean_phi_isLoaded = false;
  pfmet_muegcleanfix_isLoaded = false;
  pfmet_muegcleanfix_phi_isLoaded = false;
  pfmet_uncorr_isLoaded = false;
  pfmet_uncorr_phi_isLoaded = false;
  pfmet_original_isLoaded = false;
  pfmet_original_phi_isLoaded = false;
  scale1fb_isLoaded = false;
  xsec_isLoaded = false;
  xsec_uncert_isLoaded = false;
  kfactor_isLoaded = false;
  pu_ntrue_isLoaded = false;
  ngoodleps_isLoaded = false;
  nlooseleps_isLoaded = false;
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
  is0lep_isLoaded = false;
  is1lep_isLoaded = false;
  is2lep_isLoaded = false;
  isZtoNuNu_isLoaded = false;
  is1lepFromW_isLoaded = false;
  is1lepFromTop_isLoaded = false;
  MT2W_isLoaded = false;
  MT2W_rl_isLoaded = false;
  mindphi_met_j1_j2_isLoaded = false;
  mindphi_met_j1_j2_rl_isLoaded = false;
  mt_met_lep_isLoaded = false;
  mt_met_lep_rl_isLoaded = false;
  MT2W_jup_isLoaded = false;
  MT2W_rl_jup_isLoaded = false;
  mindphi_met_j1_j2_jup_isLoaded = false;
  mindphi_met_j1_j2_rl_jup_isLoaded = false;
  mt_met_lep_jup_isLoaded = false;
  mt_met_lep_rl_jup_isLoaded = false;
  MT2W_jdown_isLoaded = false;
  MT2W_rl_jdown_isLoaded = false;
  mindphi_met_j1_j2_jdown_isLoaded = false;
  mindphi_met_j1_j2_rl_jdown_isLoaded = false;
  mt_met_lep_jdown_isLoaded = false;
  mt_met_lep_rl_jdown_isLoaded = false;
  hadronic_top_chi2_isLoaded = false;
  ak4pfjets_rho_isLoaded = false;
  pdf_up_weight_isLoaded = false;
  pdf_down_weight_isLoaded = false;
  genweightsID_isLoaded = false;
  genweights_isLoaded = false;
  weight_btagsf_isLoaded = false;
  weight_btagsf_heavy_UP_isLoaded = false;
  weight_btagsf_light_UP_isLoaded = false;
  weight_btagsf_heavy_DN_isLoaded = false;
  weight_btagsf_light_DN_isLoaded = false;
  weight_btagsf_fastsim_UP_isLoaded = false;
  weight_btagsf_fastsim_DN_isLoaded = false;
  weight_analysisbtagsf_isLoaded = false;
  weight_analysisbtagsf_heavy_UP_isLoaded = false;
  weight_analysisbtagsf_light_UP_isLoaded = false;
  weight_analysisbtagsf_heavy_DN_isLoaded = false;
  weight_analysisbtagsf_light_DN_isLoaded = false;
  weight_analysisbtagsf_fastsim_UP_isLoaded = false;
  weight_analysisbtagsf_fastsim_DN_isLoaded = false;
  weight_tightbtagsf_isLoaded = false;
  weight_tightbtagsf_heavy_UP_isLoaded = false;
  weight_tightbtagsf_light_UP_isLoaded = false;
  weight_tightbtagsf_heavy_DN_isLoaded = false;
  weight_tightbtagsf_light_DN_isLoaded = false;
  weight_tightbtagsf_fastsim_UP_isLoaded = false;
  weight_tightbtagsf_fastsim_DN_isLoaded = false;
  weight_loosebtagsf_isLoaded = false;
  weight_loosebtagsf_heavy_UP_isLoaded = false;
  weight_loosebtagsf_light_UP_isLoaded = false;
  weight_loosebtagsf_heavy_DN_isLoaded = false;
  weight_loosebtagsf_light_DN_isLoaded = false;
  weight_loosebtagsf_fastsim_UP_isLoaded = false;
  weight_loosebtagsf_fastsim_DN_isLoaded = false;
  weight_lepSF_isLoaded = false;
  weight_lepSF_up_isLoaded = false;
  weight_lepSF_down_isLoaded = false;
  weight_vetoLepSF_isLoaded = false;
  weight_vetoLepSF_up_isLoaded = false;
  weight_vetoLepSF_down_isLoaded = false;
  weight_lepSF_fastSim_isLoaded = false;
  weight_lepSF_fastSim_up_isLoaded = false;
  weight_lepSF_fastSim_down_isLoaded = false;
  weight_ISR_isLoaded = false;
  weight_ISRup_isLoaded = false;
  weight_ISRdown_isLoaded = false;
  weight_PU_isLoaded = false;
  weight_PUup_isLoaded = false;
  weight_PUdown_isLoaded = false;
  weight_ISRnjets_isLoaded = false;
  weight_ISRnjets_UP_isLoaded = false;
  weight_ISRnjets_DN_isLoaded = false;
  NISRjets_isLoaded = false;
  NnonISRjets_isLoaded = false;
  sparms_names_isLoaded = false;
  sparms_values_isLoaded = false;
  sparms_subProcessId_isLoaded = false;
  mass_lsp_isLoaded = false;
  mass_chargino_isLoaded = false;
  mass_stop_isLoaded = false;
  mass_gluino_isLoaded = false;
  genmet_isLoaded = false;
  genmet_phi_isLoaded = false;
  nupt_isLoaded = false;
  genht_isLoaded = false;
  PassTrackVeto_isLoaded = false;
  PassTauVeto_isLoaded = false;
  topness_isLoaded = false;
  topnessMod_isLoaded = false;
  topnessMod_rl_isLoaded = false;
  topnessMod_jup_isLoaded = false;
  topnessMod_rl_jup_isLoaded = false;
  topnessMod_jdown_isLoaded = false;
  topnessMod_rl_jdown_isLoaded = false;
  Mlb_closestb_isLoaded = false;
  Mlb_lead_bdiscr_isLoaded = false;
  Mlb_closestb_jup_isLoaded = false;
  Mlb_lead_bdiscr_jup_isLoaded = false;
  Mlb_closestb_jdown_isLoaded = false;
  Mlb_lead_bdiscr_jdown_isLoaded = false;
  HLT_SingleEl_isLoaded = false;
  HLT_SingleMu_isLoaded = false;
  HLT_MET_isLoaded = false;
  HLT_MET_MHT_isLoaded = false;
  HLT_MET100_MHT100_isLoaded = false;
  HLT_MET110_MHT110_isLoaded = false;
  HLT_MET120_MHT120_isLoaded = false;
  HLT_PFHT_unprescaled_isLoaded = false;
  HLT_PFHT_prescaled_isLoaded = false;
  HLT_DiEl_isLoaded = false;
  HLT_DiMu_isLoaded = false;
  HLT_MuE_isLoaded = false;
  nPhotons_isLoaded = false;
  ph_ngoodjets_isLoaded = false;
  ph_ngoodbtags_isLoaded = false;
  hardgenpt_isLoaded = false;
  calomet_isLoaded = false;
  calomet_phi_isLoaded = false;
  lep1_pdgid_isLoaded = false;
  lep1_production_type_isLoaded = false;
  lep1_MiniIso_isLoaded = false;
  lep1_relIso_isLoaded = false;
  lep1_passLooseID_isLoaded = false;
  lep1_passMediumID_isLoaded = false;
  lep1_passTightID_isLoaded = false;
  lep1_passVeto_isLoaded = false;
  lep1_p4_isLoaded = false;
  lep1_mcp4_isLoaded = false;
  lep1_mc_motherid_isLoaded = false;
  lep1_dphiMET_isLoaded = false;
  lep1_dphiMET_jup_isLoaded = false;
  lep1_dphiMET_jdown_isLoaded = false;
  lep1_dphiMET_rl_isLoaded = false;
  lep1_dphiMET_rl_jup_isLoaded = false;
  lep1_dphiMET_rl_jdown_isLoaded = false;
  lep2_pdgid_isLoaded = false;
  lep2_production_type_isLoaded = false;
  lep2_MiniIso_isLoaded = false;
  lep2_relIso_isLoaded = false;
  lep2_passLooseID_isLoaded = false;
  lep2_passMediumID_isLoaded = false;
  lep2_passTightID_isLoaded = false;
  lep2_passVeto_isLoaded = false;
  lep2_p4_isLoaded = false;
  lep2_mcp4_isLoaded = false;
  lep2_mc_motherid_isLoaded = false;
  lep2_dphiMET_isLoaded = false;
  lep2_dphiMET_jup_isLoaded = false;
  lep2_dphiMET_jdown_isLoaded = false;
  lep2_dphiMET_rl_isLoaded = false;
  lep2_dphiMET_rl_jup_isLoaded = false;
  lep2_dphiMET_rl_jdown_isLoaded = false;
  ph_sigmaIEtaEta_fill5x5_isLoaded = false;
  ph_hOverE_isLoaded = false;
  ph_r9_isLoaded = false;
  ph_chiso_isLoaded = false;
  ph_nhiso_isLoaded = false;
  ph_phiso_isLoaded = false;
  ph_overlapJetId_isLoaded = false;
  ph_p4_isLoaded = false;
  ph_mcp4_isLoaded = false;
  ph_pt_isLoaded = false;
  ph_eta_isLoaded = false;
  ph_phi_isLoaded = false;
  ph_mass_isLoaded = false;
  ph_mcMatchId_isLoaded = false;
  ph_genIso04_isLoaded = false;
  ph_drMinParton_isLoaded = false;
  ngoodjets_isLoaded = false;
  ngoodbtags_isLoaded = false;
  nloosebtags_isLoaded = false;
  ntightbtags_isLoaded = false;
  nanalysisbtags_isLoaded = false;
  softtags_p4_isLoaded = false;
  nsoftbtags_isLoaded = false;
  ak4_HT_isLoaded = false;
  ak4_htratiom_isLoaded = false;
  dphi_ak4pfjet_met_isLoaded = false;
  ak4pfjets_p4_isLoaded = false;
  ak4pfjets_passMEDbtag_isLoaded = false;
  ak4pfjets_CSV_isLoaded = false;
  ak4pfjets_mva_isLoaded = false;
  ak4pfjets_parton_flavor_isLoaded = false;
  ak4pfjets_hadron_flavor_isLoaded = false;
  ak4pfjets_loose_puid_isLoaded = false;
  ak4pfjets_loose_pfid_isLoaded = false;
  ak4pfjets_leadMEDbjet_p4_isLoaded = false;
  ak4pfjets_leadbtag_p4_isLoaded = false;
  ak4genjets_p4_isLoaded = false;
  jup_ngoodjets_isLoaded = false;
  jup_ngoodbtags_isLoaded = false;
  jup_nloosebtags_isLoaded = false;
  jup_ntightbtags_isLoaded = false;
  jup_nanalysisbtags_isLoaded = false;
  jup_softtags_p4_isLoaded = false;
  jup_nsoftbtags_isLoaded = false;
  jup_ak4_HT_isLoaded = false;
  jup_ak4_htratiom_isLoaded = false;
  jup_dphi_ak4pfjet_met_isLoaded = false;
  jup_ak4pfjets_p4_isLoaded = false;
  jup_ak4pfjets_passMEDbtag_isLoaded = false;
  jup_ak4pfjets_CSV_isLoaded = false;
  jup_ak4pfjets_mva_isLoaded = false;
  jup_ak4pfjets_parton_flavor_isLoaded = false;
  jup_ak4pfjets_hadron_flavor_isLoaded = false;
  jup_ak4pfjets_loose_puid_isLoaded = false;
  jup_ak4pfjets_loose_pfid_isLoaded = false;
  jup_ak4pfjets_leadMEDbjet_p4_isLoaded = false;
  jup_ak4pfjets_leadbtag_p4_isLoaded = false;
  jup_ak4genjets_p4_isLoaded = false;
  jdown_ngoodjets_isLoaded = false;
  jdown_ngoodbtags_isLoaded = false;
  jdown_nloosebtags_isLoaded = false;
  jdown_ntightbtags_isLoaded = false;
  jdown_nanalysisbtags_isLoaded = false;
  jdown_softtags_p4_isLoaded = false;
  jdown_nsoftbtags_isLoaded = false;
  jdown_ak4_HT_isLoaded = false;
  jdown_ak4_htratiom_isLoaded = false;
  jdown_dphi_ak4pfjet_met_isLoaded = false;
  jdown_ak4pfjets_p4_isLoaded = false;
  jdown_ak4pfjets_passMEDbtag_isLoaded = false;
  jdown_ak4pfjets_CSV_isLoaded = false;
  jdown_ak4pfjets_mva_isLoaded = false;
  jdown_ak4pfjets_parton_flavor_isLoaded = false;
  jdown_ak4pfjets_hadron_flavor_isLoaded = false;
  jdown_ak4pfjets_loose_puid_isLoaded = false;
  jdown_ak4pfjets_loose_pfid_isLoaded = false;
  jdown_ak4pfjets_leadMEDbjet_p4_isLoaded = false;
  jdown_ak4pfjets_leadbtag_p4_isLoaded = false;
  jdown_ak4genjets_p4_isLoaded = false;
  genleps_isfromt_isLoaded = false;
  genleps_p4_isLoaded = false;
  genleps_id_isLoaded = false;
  genleps__genpsidx_isLoaded = false;
  genleps_status_isLoaded = false;
  genleps_fromHardProcessDecayed_isLoaded = false;
  genleps_fromHardProcessFinalState_isLoaded = false;
  genleps_isHardProcess_isLoaded = false;
  genleps_isLastCopy_isLoaded = false;
  genleps_gentaudecay_isLoaded = false;
  gen_nfromtleps__isLoaded = false;
  genleps_motherp4_isLoaded = false;
  genleps_motherid_isLoaded = false;
  genleps_motheridx_isLoaded = false;
  genleps_motherstatus_isLoaded = false;
  genleps_gmotherp4_isLoaded = false;
  genleps_gmotherid_isLoaded = false;
  genleps_gmotheridx_isLoaded = false;
  genleps_gmotherstatus_isLoaded = false;
  gennus_isfromt_isLoaded = false;
  gennus_p4_isLoaded = false;
  gennus_id_isLoaded = false;
  gennus__genpsidx_isLoaded = false;
  gennus_status_isLoaded = false;
  gennus_fromHardProcessDecayed_isLoaded = false;
  gennus_fromHardProcessFinalState_isLoaded = false;
  gennus_isHardProcess_isLoaded = false;
  gennus_isLastCopy_isLoaded = false;
  gennus_gentaudecay_isLoaded = false;
  gen_nfromtnus__isLoaded = false;
  gennus_motherp4_isLoaded = false;
  gennus_motherid_isLoaded = false;
  gennus_motheridx_isLoaded = false;
  gennus_motherstatus_isLoaded = false;
  gennus_gmotherp4_isLoaded = false;
  gennus_gmotherid_isLoaded = false;
  gennus_gmotheridx_isLoaded = false;
  gennus_gmotherstatus_isLoaded = false;
  genqs_isfromt_isLoaded = false;
  genqs_p4_isLoaded = false;
  genqs_id_isLoaded = false;
  genqs__genpsidx_isLoaded = false;
  genqs_status_isLoaded = false;
  genqs_fromHardProcessDecayed_isLoaded = false;
  genqs_fromHardProcessFinalState_isLoaded = false;
  genqs_isHardProcess_isLoaded = false;
  genqs_isLastCopy_isLoaded = false;
  genqs_gentaudecay_isLoaded = false;
  gen_nfromtqs__isLoaded = false;
  genqs_motherp4_isLoaded = false;
  genqs_motherid_isLoaded = false;
  genqs_motheridx_isLoaded = false;
  genqs_motherstatus_isLoaded = false;
  genqs_gmotherp4_isLoaded = false;
  genqs_gmotherid_isLoaded = false;
  genqs_gmotheridx_isLoaded = false;
  genqs_gmotherstatus_isLoaded = false;
  genbosons_isfromt_isLoaded = false;
  genbosons_p4_isLoaded = false;
  genbosons_id_isLoaded = false;
  genbosons__genpsidx_isLoaded = false;
  genbosons_status_isLoaded = false;
  genbosons_fromHardProcessDecayed_isLoaded = false;
  genbosons_fromHardProcessFinalState_isLoaded = false;
  genbosons_isHardProcess_isLoaded = false;
  genbosons_isLastCopy_isLoaded = false;
  genbosons_gentaudecay_isLoaded = false;
  gen_nfromtbosons__isLoaded = false;
  genbosons_motherp4_isLoaded = false;
  genbosons_motherid_isLoaded = false;
  genbosons_motheridx_isLoaded = false;
  genbosons_motherstatus_isLoaded = false;
  genbosons_gmotherp4_isLoaded = false;
  genbosons_gmotherid_isLoaded = false;
  genbosons_gmotheridx_isLoaded = false;
  genbosons_gmotherstatus_isLoaded = false;
  gensusy_isfromt_isLoaded = false;
  gensusy_p4_isLoaded = false;
  gensusy_id_isLoaded = false;
  gensusy__genpsidx_isLoaded = false;
  gensusy_status_isLoaded = false;
  gensusy_fromHardProcessDecayed_isLoaded = false;
  gensusy_fromHardProcessFinalState_isLoaded = false;
  gensusy_isHardProcess_isLoaded = false;
  gensusy_isLastCopy_isLoaded = false;
  gensusy_gentaudecay_isLoaded = false;
  gen_nfromtsusy__isLoaded = false;
  gensusy_motherp4_isLoaded = false;
  gensusy_motherid_isLoaded = false;
  gensusy_motheridx_isLoaded = false;
  gensusy_motherstatus_isLoaded = false;
  gensusy_gmotherp4_isLoaded = false;
  gensusy_gmotherid_isLoaded = false;
  gensusy_gmotheridx_isLoaded = false;
  gensusy_gmotherstatus_isLoaded = false;
  tau_IDnames_isLoaded = false;
  tau_leadtrack_p4_isLoaded = false;
  tau_leadneutral_p4_isLoaded = false;
  tau_p4_isLoaded = false;
  tau_isocand_p4_isLoaded = false;
  tau_sigcand_p4_isLoaded = false;
  tau_ID_isLoaded = false;
  tau_passID_isLoaded = false;
  ngoodtaus_isLoaded = false;
  tau_againstMuonTight_isLoaded = false;
  tau_againstElectronLoose_isLoaded = false;
  tau_isVetoTau_isLoaded = false;
  isoTracks_p4_isLoaded = false;
  isoTracks_charge_isLoaded = false;
  isoTracks_absIso_isLoaded = false;
  isoTracks_dz_isLoaded = false;
  isoTracks_pdgId_isLoaded = false;
  isoTracks_isVetoTrack_isLoaded = false;
  isoTracks_isVetoTrack_v2_isLoaded = false;
  isoTracks_isVetoTrack_v3_isLoaded = false;
  filt_cscbeamhalo_isLoaded = false;
  filt_cscbeamhalo2015_isLoaded = false;
  filt_globaltighthalo2016_isLoaded = false;
  filt_globalsupertighthalo2016_isLoaded = false;
  filt_ecallaser_isLoaded = false;
  filt_ecaltp_isLoaded = false;
  filt_eebadsc_isLoaded = false;
  filt_goodvtx_isLoaded = false;
  filt_badevents_isLoaded = false;
  filt_hbhenoise_isLoaded = false;
  filt_hbheisonoise_isLoaded = false;
  filt_hcallaser_isLoaded = false;
  filt_trkfail_isLoaded = false;
  filt_trkPOG_isLoaded = false;
  filt_trkPOG_logerr_tmc_isLoaded = false;
  filt_trkPOG_tmc_isLoaded = false;
  filt_trkPOG_tms_isLoaded = false;
  firstGoodVtxIdx_isLoaded = false;
  filt_badChargedCandidateFilter_isLoaded = false;
  filt_badMuonFilter_isLoaded = false;
  filt_met_isLoaded = false;
  filt_fastsimjets_isLoaded = false;
  filt_fastsimjets_jup_isLoaded = false;
  filt_fastsimjets_jdown_isLoaded = false;
  filt_jetWithBadMuon_isLoaded = false;
  filt_jetWithBadMuon_jup_isLoaded = false;
  filt_jetWithBadMuon_jdown_isLoaded = false;
  filt_pfovercalomet_isLoaded = false;
  filt_badmuons_isLoaded = false;
  filt_duplicatemuons_isLoaded = false;
  filt_nobadmuons_isLoaded = false;
}

extern "C" void CMS3::LoadAllBranches() {
  // load all branches
  if (run_branch != 0) run();
  if (ls_branch != 0) ls();
  if (evt_branch != 0) evt();
  if (nvtxs_branch != 0) nvtxs();
  if (pu_nvtxs_branch != 0) pu_nvtxs();
  if (pfmet_branch != 0) pfmet();
  if (pfmet_phi_branch != 0) pfmet_phi();
  if (pfmet_jup_branch != 0) pfmet_jup();
  if (pfmet_phi_jup_branch != 0) pfmet_phi_jup();
  if (pfmet_jdown_branch != 0) pfmet_jdown();
  if (pfmet_phi_jdown_branch != 0) pfmet_phi_jdown();
  if (pfmet_rl_branch != 0) pfmet_rl();
  if (pfmet_phi_rl_branch != 0) pfmet_phi_rl();
  if (pfmet_rl_jup_branch != 0) pfmet_rl_jup();
  if (pfmet_phi_rl_jup_branch != 0) pfmet_phi_rl_jup();
  if (pfmet_rl_jdown_branch != 0) pfmet_rl_jdown();
  if (pfmet_phi_rl_jdown_branch != 0) pfmet_phi_rl_jdown();
  if (pfmet_egclean_branch != 0) pfmet_egclean();
  if (pfmet_egclean_phi_branch != 0) pfmet_egclean_phi();
  if (pfmet_muegclean_branch != 0) pfmet_muegclean();
  if (pfmet_muegclean_phi_branch != 0) pfmet_muegclean_phi();
  if (pfmet_muegcleanfix_branch != 0) pfmet_muegcleanfix();
  if (pfmet_muegcleanfix_phi_branch != 0) pfmet_muegcleanfix_phi();
  if (pfmet_uncorr_branch != 0) pfmet_uncorr();
  if (pfmet_uncorr_phi_branch != 0) pfmet_uncorr_phi();
  if (pfmet_original_branch != 0) pfmet_original();
  if (pfmet_original_phi_branch != 0) pfmet_original_phi();
  if (scale1fb_branch != 0) scale1fb();
  if (xsec_branch != 0) xsec();
  if (xsec_uncert_branch != 0) xsec_uncert();
  if (kfactor_branch != 0) kfactor();
  if (pu_ntrue_branch != 0) pu_ntrue();
  if (ngoodleps_branch != 0) ngoodleps();
  if (nlooseleps_branch != 0) nlooseleps();
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
  if (is0lep_branch != 0) is0lep();
  if (is1lep_branch != 0) is1lep();
  if (is2lep_branch != 0) is2lep();
  if (isZtoNuNu_branch != 0) isZtoNuNu();
  if (is1lepFromW_branch != 0) is1lepFromW();
  if (is1lepFromTop_branch != 0) is1lepFromTop();
  if (MT2W_branch != 0) MT2W();
  if (MT2W_rl_branch != 0) MT2W_rl();
  if (mindphi_met_j1_j2_branch != 0) mindphi_met_j1_j2();
  if (mindphi_met_j1_j2_rl_branch != 0) mindphi_met_j1_j2_rl();
  if (mt_met_lep_branch != 0) mt_met_lep();
  if (mt_met_lep_rl_branch != 0) mt_met_lep_rl();
  if (MT2W_jup_branch != 0) MT2W_jup();
  if (MT2W_rl_jup_branch != 0) MT2W_rl_jup();
  if (mindphi_met_j1_j2_jup_branch != 0) mindphi_met_j1_j2_jup();
  if (mindphi_met_j1_j2_rl_jup_branch != 0) mindphi_met_j1_j2_rl_jup();
  if (mt_met_lep_jup_branch != 0) mt_met_lep_jup();
  if (mt_met_lep_rl_jup_branch != 0) mt_met_lep_rl_jup();
  if (MT2W_jdown_branch != 0) MT2W_jdown();
  if (MT2W_rl_jdown_branch != 0) MT2W_rl_jdown();
  if (mindphi_met_j1_j2_jdown_branch != 0) mindphi_met_j1_j2_jdown();
  if (mindphi_met_j1_j2_rl_jdown_branch != 0) mindphi_met_j1_j2_rl_jdown();
  if (mt_met_lep_jdown_branch != 0) mt_met_lep_jdown();
  if (mt_met_lep_rl_jdown_branch != 0) mt_met_lep_rl_jdown();
  if (hadronic_top_chi2_branch != 0) hadronic_top_chi2();
  if (ak4pfjets_rho_branch != 0) ak4pfjets_rho();
  if (pdf_up_weight_branch != 0) pdf_up_weight();
  if (pdf_down_weight_branch != 0) pdf_down_weight();
  if (genweightsID_branch != 0) genweightsID();
  if (genweights_branch != 0) genweights();
  if (weight_btagsf_branch != 0) weight_btagsf();
  if (weight_btagsf_heavy_UP_branch != 0) weight_btagsf_heavy_UP();
  if (weight_btagsf_light_UP_branch != 0) weight_btagsf_light_UP();
  if (weight_btagsf_heavy_DN_branch != 0) weight_btagsf_heavy_DN();
  if (weight_btagsf_light_DN_branch != 0) weight_btagsf_light_DN();
  if (weight_btagsf_fastsim_UP_branch != 0) weight_btagsf_fastsim_UP();
  if (weight_btagsf_fastsim_DN_branch != 0) weight_btagsf_fastsim_DN();
  if (weight_analysisbtagsf_branch != 0) weight_analysisbtagsf();
  if (weight_analysisbtagsf_heavy_UP_branch != 0) weight_analysisbtagsf_heavy_UP();
  if (weight_analysisbtagsf_light_UP_branch != 0) weight_analysisbtagsf_light_UP();
  if (weight_analysisbtagsf_heavy_DN_branch != 0) weight_analysisbtagsf_heavy_DN();
  if (weight_analysisbtagsf_light_DN_branch != 0) weight_analysisbtagsf_light_DN();
  if (weight_analysisbtagsf_fastsim_UP_branch != 0) weight_analysisbtagsf_fastsim_UP();
  if (weight_analysisbtagsf_fastsim_DN_branch != 0) weight_analysisbtagsf_fastsim_DN();
  if (weight_tightbtagsf_branch != 0) weight_tightbtagsf();
  if (weight_tightbtagsf_heavy_UP_branch != 0) weight_tightbtagsf_heavy_UP();
  if (weight_tightbtagsf_light_UP_branch != 0) weight_tightbtagsf_light_UP();
  if (weight_tightbtagsf_heavy_DN_branch != 0) weight_tightbtagsf_heavy_DN();
  if (weight_tightbtagsf_light_DN_branch != 0) weight_tightbtagsf_light_DN();
  if (weight_tightbtagsf_fastsim_UP_branch != 0) weight_tightbtagsf_fastsim_UP();
  if (weight_tightbtagsf_fastsim_DN_branch != 0) weight_tightbtagsf_fastsim_DN();
  if (weight_loosebtagsf_branch != 0) weight_loosebtagsf();
  if (weight_loosebtagsf_heavy_UP_branch != 0) weight_loosebtagsf_heavy_UP();
  if (weight_loosebtagsf_light_UP_branch != 0) weight_loosebtagsf_light_UP();
  if (weight_loosebtagsf_heavy_DN_branch != 0) weight_loosebtagsf_heavy_DN();
  if (weight_loosebtagsf_light_DN_branch != 0) weight_loosebtagsf_light_DN();
  if (weight_loosebtagsf_fastsim_UP_branch != 0) weight_loosebtagsf_fastsim_UP();
  if (weight_loosebtagsf_fastsim_DN_branch != 0) weight_loosebtagsf_fastsim_DN();
  if (weight_lepSF_branch != 0) weight_lepSF();
  if (weight_lepSF_up_branch != 0) weight_lepSF_up();
  if (weight_lepSF_down_branch != 0) weight_lepSF_down();
  if (weight_vetoLepSF_branch != 0) weight_vetoLepSF();
  if (weight_vetoLepSF_up_branch != 0) weight_vetoLepSF_up();
  if (weight_vetoLepSF_down_branch != 0) weight_vetoLepSF_down();
  if (weight_lepSF_fastSim_branch != 0) weight_lepSF_fastSim();
  if (weight_lepSF_fastSim_up_branch != 0) weight_lepSF_fastSim_up();
  if (weight_lepSF_fastSim_down_branch != 0) weight_lepSF_fastSim_down();
  if (weight_ISR_branch != 0) weight_ISR();
  if (weight_ISRup_branch != 0) weight_ISRup();
  if (weight_ISRdown_branch != 0) weight_ISRdown();
  if (weight_PU_branch != 0) weight_PU();
  if (weight_PUup_branch != 0) weight_PUup();
  if (weight_PUdown_branch != 0) weight_PUdown();
  if (weight_ISRnjets_branch != 0) weight_ISRnjets();
  if (weight_ISRnjets_UP_branch != 0) weight_ISRnjets_UP();
  if (weight_ISRnjets_DN_branch != 0) weight_ISRnjets_DN();
  if (NISRjets_branch != 0) NISRjets();
  if (NnonISRjets_branch != 0) NnonISRjets();
  if (sparms_names_branch != 0) sparms_names();
  if (sparms_values_branch != 0) sparms_values();
  if (sparms_subProcessId_branch != 0) sparms_subProcessId();
  if (mass_lsp_branch != 0) mass_lsp();
  if (mass_chargino_branch != 0) mass_chargino();
  if (mass_stop_branch != 0) mass_stop();
  if (mass_gluino_branch != 0) mass_gluino();
  if (genmet_branch != 0) genmet();
  if (genmet_phi_branch != 0) genmet_phi();
  if (nupt_branch != 0) nupt();
  if (genht_branch != 0) genht();
  if (PassTrackVeto_branch != 0) PassTrackVeto();
  if (PassTauVeto_branch != 0) PassTauVeto();
  if (topness_branch != 0) topness();
  if (topnessMod_branch != 0) topnessMod();
  if (topnessMod_rl_branch != 0) topnessMod_rl();
  if (topnessMod_jup_branch != 0) topnessMod_jup();
  if (topnessMod_rl_jup_branch != 0) topnessMod_rl_jup();
  if (topnessMod_jdown_branch != 0) topnessMod_jdown();
  if (topnessMod_rl_jdown_branch != 0) topnessMod_rl_jdown();
  if (Mlb_closestb_branch != 0) Mlb_closestb();
  if (Mlb_lead_bdiscr_branch != 0) Mlb_lead_bdiscr();
  if (Mlb_closestb_jup_branch != 0) Mlb_closestb_jup();
  if (Mlb_lead_bdiscr_jup_branch != 0) Mlb_lead_bdiscr_jup();
  if (Mlb_closestb_jdown_branch != 0) Mlb_closestb_jdown();
  if (Mlb_lead_bdiscr_jdown_branch != 0) Mlb_lead_bdiscr_jdown();
  if (HLT_SingleEl_branch != 0) HLT_SingleEl();
  if (HLT_SingleMu_branch != 0) HLT_SingleMu();
  if (HLT_MET_branch != 0) HLT_MET();
  if (HLT_MET_MHT_branch != 0) HLT_MET_MHT();
  if (HLT_MET100_MHT100_branch != 0) HLT_MET100_MHT100();
  if (HLT_MET110_MHT110_branch != 0) HLT_MET110_MHT110();
  if (HLT_MET120_MHT120_branch != 0) HLT_MET120_MHT120();
  if (HLT_PFHT_unprescaled_branch != 0) HLT_PFHT_unprescaled();
  if (HLT_PFHT_prescaled_branch != 0) HLT_PFHT_prescaled();
  if (HLT_DiEl_branch != 0) HLT_DiEl();
  if (HLT_DiMu_branch != 0) HLT_DiMu();
  if (HLT_MuE_branch != 0) HLT_MuE();
  if (nPhotons_branch != 0) nPhotons();
  if (ph_ngoodjets_branch != 0) ph_ngoodjets();
  if (ph_ngoodbtags_branch != 0) ph_ngoodbtags();
  if (hardgenpt_branch != 0) hardgenpt();
  if (calomet_branch != 0) calomet();
  if (calomet_phi_branch != 0) calomet_phi();
  if (lep1_pdgid_branch != 0) lep1_pdgid();
  if (lep1_production_type_branch != 0) lep1_production_type();
  if (lep1_MiniIso_branch != 0) lep1_MiniIso();
  if (lep1_relIso_branch != 0) lep1_relIso();
  if (lep1_passLooseID_branch != 0) lep1_passLooseID();
  if (lep1_passMediumID_branch != 0) lep1_passMediumID();
  if (lep1_passTightID_branch != 0) lep1_passTightID();
  if (lep1_passVeto_branch != 0) lep1_passVeto();
  if (lep1_p4_branch != 0) lep1_p4();
  if (lep1_mcp4_branch != 0) lep1_mcp4();
  if (lep1_mc_motherid_branch != 0) lep1_mc_motherid();
  if (lep1_dphiMET_branch != 0) lep1_dphiMET();
  if (lep1_dphiMET_jup_branch != 0) lep1_dphiMET_jup();
  if (lep1_dphiMET_jdown_branch != 0) lep1_dphiMET_jdown();
  if (lep1_dphiMET_rl_branch != 0) lep1_dphiMET_rl();
  if (lep1_dphiMET_rl_jup_branch != 0) lep1_dphiMET_rl_jup();
  if (lep1_dphiMET_rl_jdown_branch != 0) lep1_dphiMET_rl_jdown();
  if (lep2_pdgid_branch != 0) lep2_pdgid();
  if (lep2_production_type_branch != 0) lep2_production_type();
  if (lep2_MiniIso_branch != 0) lep2_MiniIso();
  if (lep2_relIso_branch != 0) lep2_relIso();
  if (lep2_passLooseID_branch != 0) lep2_passLooseID();
  if (lep2_passMediumID_branch != 0) lep2_passMediumID();
  if (lep2_passTightID_branch != 0) lep2_passTightID();
  if (lep2_passVeto_branch != 0) lep2_passVeto();
  if (lep2_p4_branch != 0) lep2_p4();
  if (lep2_mcp4_branch != 0) lep2_mcp4();
  if (lep2_mc_motherid_branch != 0) lep2_mc_motherid();
  if (lep2_dphiMET_branch != 0) lep2_dphiMET();
  if (lep2_dphiMET_jup_branch != 0) lep2_dphiMET_jup();
  if (lep2_dphiMET_jdown_branch != 0) lep2_dphiMET_jdown();
  if (lep2_dphiMET_rl_branch != 0) lep2_dphiMET_rl();
  if (lep2_dphiMET_rl_jup_branch != 0) lep2_dphiMET_rl_jup();
  if (lep2_dphiMET_rl_jdown_branch != 0) lep2_dphiMET_rl_jdown();
  if (ph_sigmaIEtaEta_fill5x5_branch != 0) ph_sigmaIEtaEta_fill5x5();
  if (ph_hOverE_branch != 0) ph_hOverE();
  if (ph_r9_branch != 0) ph_r9();
  if (ph_chiso_branch != 0) ph_chiso();
  if (ph_nhiso_branch != 0) ph_nhiso();
  if (ph_phiso_branch != 0) ph_phiso();
  if (ph_overlapJetId_branch != 0) ph_overlapJetId();
  if (ph_p4_branch != 0) ph_p4();
  if (ph_mcp4_branch != 0) ph_mcp4();
  if (ph_pt_branch != 0) ph_pt();
  if (ph_eta_branch != 0) ph_eta();
  if (ph_phi_branch != 0) ph_phi();
  if (ph_mass_branch != 0) ph_mass();
  if (ph_mcMatchId_branch != 0) ph_mcMatchId();
  if (ph_genIso04_branch != 0) ph_genIso04();
  if (ph_drMinParton_branch != 0) ph_drMinParton();
  if (ngoodjets_branch != 0) ngoodjets();
  if (ngoodbtags_branch != 0) ngoodbtags();
  if (nloosebtags_branch != 0) nloosebtags();
  if (ntightbtags_branch != 0) ntightbtags();
  if (nanalysisbtags_branch != 0) nanalysisbtags();
  if (softtags_p4_branch != 0) softtags_p4();
  if (nsoftbtags_branch != 0) nsoftbtags();
  if (ak4_HT_branch != 0) ak4_HT();
  if (ak4_htratiom_branch != 0) ak4_htratiom();
  if (dphi_ak4pfjet_met_branch != 0) dphi_ak4pfjet_met();
  if (ak4pfjets_p4_branch != 0) ak4pfjets_p4();
  if (ak4pfjets_passMEDbtag_branch != 0) ak4pfjets_passMEDbtag();
  if (ak4pfjets_CSV_branch != 0) ak4pfjets_CSV();
  if (ak4pfjets_mva_branch != 0) ak4pfjets_mva();
  if (ak4pfjets_parton_flavor_branch != 0) ak4pfjets_parton_flavor();
  if (ak4pfjets_hadron_flavor_branch != 0) ak4pfjets_hadron_flavor();
  if (ak4pfjets_loose_puid_branch != 0) ak4pfjets_loose_puid();
  if (ak4pfjets_loose_pfid_branch != 0) ak4pfjets_loose_pfid();
  if (ak4pfjets_leadMEDbjet_p4_branch != 0) ak4pfjets_leadMEDbjet_p4();
  if (ak4pfjets_leadbtag_p4_branch != 0) ak4pfjets_leadbtag_p4();
  if (ak4genjets_p4_branch != 0) ak4genjets_p4();
  if (jup_ngoodjets_branch != 0) jup_ngoodjets();
  if (jup_ngoodbtags_branch != 0) jup_ngoodbtags();
  if (jup_nloosebtags_branch != 0) jup_nloosebtags();
  if (jup_ntightbtags_branch != 0) jup_ntightbtags();
  if (jup_nanalysisbtags_branch != 0) jup_nanalysisbtags();
  if (jup_softtags_p4_branch != 0) jup_softtags_p4();
  if (jup_nsoftbtags_branch != 0) jup_nsoftbtags();
  if (jup_ak4_HT_branch != 0) jup_ak4_HT();
  if (jup_ak4_htratiom_branch != 0) jup_ak4_htratiom();
  if (jup_dphi_ak4pfjet_met_branch != 0) jup_dphi_ak4pfjet_met();
  if (jup_ak4pfjets_p4_branch != 0) jup_ak4pfjets_p4();
  if (jup_ak4pfjets_passMEDbtag_branch != 0) jup_ak4pfjets_passMEDbtag();
  if (jup_ak4pfjets_CSV_branch != 0) jup_ak4pfjets_CSV();
  if (jup_ak4pfjets_mva_branch != 0) jup_ak4pfjets_mva();
  if (jup_ak4pfjets_parton_flavor_branch != 0) jup_ak4pfjets_parton_flavor();
  if (jup_ak4pfjets_hadron_flavor_branch != 0) jup_ak4pfjets_hadron_flavor();
  if (jup_ak4pfjets_loose_puid_branch != 0) jup_ak4pfjets_loose_puid();
  if (jup_ak4pfjets_loose_pfid_branch != 0) jup_ak4pfjets_loose_pfid();
  if (jup_ak4pfjets_leadMEDbjet_p4_branch != 0) jup_ak4pfjets_leadMEDbjet_p4();
  if (jup_ak4pfjets_leadbtag_p4_branch != 0) jup_ak4pfjets_leadbtag_p4();
  if (jup_ak4genjets_p4_branch != 0) jup_ak4genjets_p4();
  if (jdown_ngoodjets_branch != 0) jdown_ngoodjets();
  if (jdown_ngoodbtags_branch != 0) jdown_ngoodbtags();
  if (jdown_nloosebtags_branch != 0) jdown_nloosebtags();
  if (jdown_ntightbtags_branch != 0) jdown_ntightbtags();
  if (jdown_nanalysisbtags_branch != 0) jdown_nanalysisbtags();
  if (jdown_softtags_p4_branch != 0) jdown_softtags_p4();
  if (jdown_nsoftbtags_branch != 0) jdown_nsoftbtags();
  if (jdown_ak4_HT_branch != 0) jdown_ak4_HT();
  if (jdown_ak4_htratiom_branch != 0) jdown_ak4_htratiom();
  if (jdown_dphi_ak4pfjet_met_branch != 0) jdown_dphi_ak4pfjet_met();
  if (jdown_ak4pfjets_p4_branch != 0) jdown_ak4pfjets_p4();
  if (jdown_ak4pfjets_passMEDbtag_branch != 0) jdown_ak4pfjets_passMEDbtag();
  if (jdown_ak4pfjets_CSV_branch != 0) jdown_ak4pfjets_CSV();
  if (jdown_ak4pfjets_mva_branch != 0) jdown_ak4pfjets_mva();
  if (jdown_ak4pfjets_parton_flavor_branch != 0) jdown_ak4pfjets_parton_flavor();
  if (jdown_ak4pfjets_hadron_flavor_branch != 0) jdown_ak4pfjets_hadron_flavor();
  if (jdown_ak4pfjets_loose_puid_branch != 0) jdown_ak4pfjets_loose_puid();
  if (jdown_ak4pfjets_loose_pfid_branch != 0) jdown_ak4pfjets_loose_pfid();
  if (jdown_ak4pfjets_leadMEDbjet_p4_branch != 0) jdown_ak4pfjets_leadMEDbjet_p4();
  if (jdown_ak4pfjets_leadbtag_p4_branch != 0) jdown_ak4pfjets_leadbtag_p4();
  if (jdown_ak4genjets_p4_branch != 0) jdown_ak4genjets_p4();
  if (genleps_isfromt_branch != 0) genleps_isfromt();
  if (genleps_p4_branch != 0) genleps_p4();
  if (genleps_id_branch != 0) genleps_id();
  if (genleps__genpsidx_branch != 0) genleps__genpsidx();
  if (genleps_status_branch != 0) genleps_status();
  if (genleps_fromHardProcessDecayed_branch != 0) genleps_fromHardProcessDecayed();
  if (genleps_fromHardProcessFinalState_branch != 0) genleps_fromHardProcessFinalState();
  if (genleps_isHardProcess_branch != 0) genleps_isHardProcess();
  if (genleps_isLastCopy_branch != 0) genleps_isLastCopy();
  if (genleps_gentaudecay_branch != 0) genleps_gentaudecay();
  if (gen_nfromtleps__branch != 0) gen_nfromtleps_();
  if (genleps_motherp4_branch != 0) genleps_motherp4();
  if (genleps_motherid_branch != 0) genleps_motherid();
  if (genleps_motheridx_branch != 0) genleps_motheridx();
  if (genleps_motherstatus_branch != 0) genleps_motherstatus();
  if (genleps_gmotherp4_branch != 0) genleps_gmotherp4();
  if (genleps_gmotherid_branch != 0) genleps_gmotherid();
  if (genleps_gmotheridx_branch != 0) genleps_gmotheridx();
  if (genleps_gmotherstatus_branch != 0) genleps_gmotherstatus();
  if (gennus_isfromt_branch != 0) gennus_isfromt();
  if (gennus_p4_branch != 0) gennus_p4();
  if (gennus_id_branch != 0) gennus_id();
  if (gennus__genpsidx_branch != 0) gennus__genpsidx();
  if (gennus_status_branch != 0) gennus_status();
  if (gennus_fromHardProcessDecayed_branch != 0) gennus_fromHardProcessDecayed();
  if (gennus_fromHardProcessFinalState_branch != 0) gennus_fromHardProcessFinalState();
  if (gennus_isHardProcess_branch != 0) gennus_isHardProcess();
  if (gennus_isLastCopy_branch != 0) gennus_isLastCopy();
  if (gennus_gentaudecay_branch != 0) gennus_gentaudecay();
  if (gen_nfromtnus__branch != 0) gen_nfromtnus_();
  if (gennus_motherp4_branch != 0) gennus_motherp4();
  if (gennus_motherid_branch != 0) gennus_motherid();
  if (gennus_motheridx_branch != 0) gennus_motheridx();
  if (gennus_motherstatus_branch != 0) gennus_motherstatus();
  if (gennus_gmotherp4_branch != 0) gennus_gmotherp4();
  if (gennus_gmotherid_branch != 0) gennus_gmotherid();
  if (gennus_gmotheridx_branch != 0) gennus_gmotheridx();
  if (gennus_gmotherstatus_branch != 0) gennus_gmotherstatus();
  if (genqs_isfromt_branch != 0) genqs_isfromt();
  if (genqs_p4_branch != 0) genqs_p4();
  if (genqs_id_branch != 0) genqs_id();
  if (genqs__genpsidx_branch != 0) genqs__genpsidx();
  if (genqs_status_branch != 0) genqs_status();
  if (genqs_fromHardProcessDecayed_branch != 0) genqs_fromHardProcessDecayed();
  if (genqs_fromHardProcessFinalState_branch != 0) genqs_fromHardProcessFinalState();
  if (genqs_isHardProcess_branch != 0) genqs_isHardProcess();
  if (genqs_isLastCopy_branch != 0) genqs_isLastCopy();
  if (genqs_gentaudecay_branch != 0) genqs_gentaudecay();
  if (gen_nfromtqs__branch != 0) gen_nfromtqs_();
  if (genqs_motherp4_branch != 0) genqs_motherp4();
  if (genqs_motherid_branch != 0) genqs_motherid();
  if (genqs_motheridx_branch != 0) genqs_motheridx();
  if (genqs_motherstatus_branch != 0) genqs_motherstatus();
  if (genqs_gmotherp4_branch != 0) genqs_gmotherp4();
  if (genqs_gmotherid_branch != 0) genqs_gmotherid();
  if (genqs_gmotheridx_branch != 0) genqs_gmotheridx();
  if (genqs_gmotherstatus_branch != 0) genqs_gmotherstatus();
  if (genbosons_isfromt_branch != 0) genbosons_isfromt();
  if (genbosons_p4_branch != 0) genbosons_p4();
  if (genbosons_id_branch != 0) genbosons_id();
  if (genbosons__genpsidx_branch != 0) genbosons__genpsidx();
  if (genbosons_status_branch != 0) genbosons_status();
  if (genbosons_fromHardProcessDecayed_branch != 0) genbosons_fromHardProcessDecayed();
  if (genbosons_fromHardProcessFinalState_branch != 0) genbosons_fromHardProcessFinalState();
  if (genbosons_isHardProcess_branch != 0) genbosons_isHardProcess();
  if (genbosons_isLastCopy_branch != 0) genbosons_isLastCopy();
  if (genbosons_gentaudecay_branch != 0) genbosons_gentaudecay();
  if (gen_nfromtbosons__branch != 0) gen_nfromtbosons_();
  if (genbosons_motherp4_branch != 0) genbosons_motherp4();
  if (genbosons_motherid_branch != 0) genbosons_motherid();
  if (genbosons_motheridx_branch != 0) genbosons_motheridx();
  if (genbosons_motherstatus_branch != 0) genbosons_motherstatus();
  if (genbosons_gmotherp4_branch != 0) genbosons_gmotherp4();
  if (genbosons_gmotherid_branch != 0) genbosons_gmotherid();
  if (genbosons_gmotheridx_branch != 0) genbosons_gmotheridx();
  if (genbosons_gmotherstatus_branch != 0) genbosons_gmotherstatus();
  if (gensusy_isfromt_branch != 0) gensusy_isfromt();
  if (gensusy_p4_branch != 0) gensusy_p4();
  if (gensusy_id_branch != 0) gensusy_id();
  if (gensusy__genpsidx_branch != 0) gensusy__genpsidx();
  if (gensusy_status_branch != 0) gensusy_status();
  if (gensusy_fromHardProcessDecayed_branch != 0) gensusy_fromHardProcessDecayed();
  if (gensusy_fromHardProcessFinalState_branch != 0) gensusy_fromHardProcessFinalState();
  if (gensusy_isHardProcess_branch != 0) gensusy_isHardProcess();
  if (gensusy_isLastCopy_branch != 0) gensusy_isLastCopy();
  if (gensusy_gentaudecay_branch != 0) gensusy_gentaudecay();
  if (gen_nfromtsusy__branch != 0) gen_nfromtsusy_();
  if (gensusy_motherp4_branch != 0) gensusy_motherp4();
  if (gensusy_motherid_branch != 0) gensusy_motherid();
  if (gensusy_motheridx_branch != 0) gensusy_motheridx();
  if (gensusy_motherstatus_branch != 0) gensusy_motherstatus();
  if (gensusy_gmotherp4_branch != 0) gensusy_gmotherp4();
  if (gensusy_gmotherid_branch != 0) gensusy_gmotherid();
  if (gensusy_gmotheridx_branch != 0) gensusy_gmotheridx();
  if (gensusy_gmotherstatus_branch != 0) gensusy_gmotherstatus();
  if (tau_IDnames_branch != 0) tau_IDnames();
  if (tau_leadtrack_p4_branch != 0) tau_leadtrack_p4();
  if (tau_leadneutral_p4_branch != 0) tau_leadneutral_p4();
  if (tau_p4_branch != 0) tau_p4();
  if (tau_isocand_p4_branch != 0) tau_isocand_p4();
  if (tau_sigcand_p4_branch != 0) tau_sigcand_p4();
  if (tau_ID_branch != 0) tau_ID();
  if (tau_passID_branch != 0) tau_passID();
  if (ngoodtaus_branch != 0) ngoodtaus();
  if (tau_againstMuonTight_branch != 0) tau_againstMuonTight();
  if (tau_againstElectronLoose_branch != 0) tau_againstElectronLoose();
  if (tau_isVetoTau_branch != 0) tau_isVetoTau();
  if (isoTracks_p4_branch != 0) isoTracks_p4();
  if (isoTracks_charge_branch != 0) isoTracks_charge();
  if (isoTracks_absIso_branch != 0) isoTracks_absIso();
  if (isoTracks_dz_branch != 0) isoTracks_dz();
  if (isoTracks_pdgId_branch != 0) isoTracks_pdgId();
  if (isoTracks_isVetoTrack_branch != 0) isoTracks_isVetoTrack();
  if (isoTracks_isVetoTrack_v2_branch != 0) isoTracks_isVetoTrack_v2();
  if (isoTracks_isVetoTrack_v3_branch != 0) isoTracks_isVetoTrack_v3();
  if (filt_cscbeamhalo_branch != 0) filt_cscbeamhalo();
  if (filt_cscbeamhalo2015_branch != 0) filt_cscbeamhalo2015();
  if (filt_globaltighthalo2016_branch != 0) filt_globaltighthalo2016();
  if (filt_globalsupertighthalo2016_branch != 0) filt_globalsupertighthalo2016();
  if (filt_ecallaser_branch != 0) filt_ecallaser();
  if (filt_ecaltp_branch != 0) filt_ecaltp();
  if (filt_eebadsc_branch != 0) filt_eebadsc();
  if (filt_goodvtx_branch != 0) filt_goodvtx();
  if (filt_badevents_branch != 0) filt_badevents();
  if (filt_hbhenoise_branch != 0) filt_hbhenoise();
  if (filt_hbheisonoise_branch != 0) filt_hbheisonoise();
  if (filt_hcallaser_branch != 0) filt_hcallaser();
  if (filt_trkfail_branch != 0) filt_trkfail();
  if (filt_trkPOG_branch != 0) filt_trkPOG();
  if (filt_trkPOG_logerr_tmc_branch != 0) filt_trkPOG_logerr_tmc();
  if (filt_trkPOG_tmc_branch != 0) filt_trkPOG_tmc();
  if (filt_trkPOG_tms_branch != 0) filt_trkPOG_tms();
  if (firstGoodVtxIdx_branch != 0) firstGoodVtxIdx();
  if (filt_badChargedCandidateFilter_branch != 0) filt_badChargedCandidateFilter();
  if (filt_badMuonFilter_branch != 0) filt_badMuonFilter();
  if (filt_met_branch != 0) filt_met();
  if (filt_fastsimjets_branch != 0) filt_fastsimjets();
  if (filt_fastsimjets_jup_branch != 0) filt_fastsimjets_jup();
  if (filt_fastsimjets_jdown_branch != 0) filt_fastsimjets_jdown();
  if (filt_jetWithBadMuon_branch != 0) filt_jetWithBadMuon();
  if (filt_jetWithBadMuon_jup_branch != 0) filt_jetWithBadMuon_jup();
  if (filt_jetWithBadMuon_jdown_branch != 0) filt_jetWithBadMuon_jdown();
  if (filt_pfovercalomet_branch != 0) filt_pfovercalomet();
  if (filt_badmuons_branch != 0) filt_badmuons();
  if (filt_duplicatemuons_branch != 0) filt_duplicatemuons();
  if (filt_nobadmuons_branch != 0) filt_nobadmuons();
}

const unsigned int &CMS3::run() {
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

const unsigned int &CMS3::ls() {
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

const unsigned int &CMS3::evt() {
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

const int &CMS3::nvtxs() {
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

const int &CMS3::pu_nvtxs() {
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

const float &CMS3::pfmet() {
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

const float &CMS3::pfmet_phi() {
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

const float &CMS3::pfmet_jup() {
  if (not pfmet_jup_isLoaded) {
    if (pfmet_jup_branch != 0) {
      pfmet_jup_branch->GetEntry(index);
    } else {
      printf("branch pfmet_jup_branch does not exist!\n");
      exit(1);
    }
    pfmet_jup_isLoaded = true;
  }
  return pfmet_jup_;
}

const float &CMS3::pfmet_phi_jup() {
  if (not pfmet_phi_jup_isLoaded) {
    if (pfmet_phi_jup_branch != 0) {
      pfmet_phi_jup_branch->GetEntry(index);
    } else {
      printf("branch pfmet_phi_jup_branch does not exist!\n");
      exit(1);
    }
    pfmet_phi_jup_isLoaded = true;
  }
  return pfmet_phi_jup_;
}

const float &CMS3::pfmet_jdown() {
  if (not pfmet_jdown_isLoaded) {
    if (pfmet_jdown_branch != 0) {
      pfmet_jdown_branch->GetEntry(index);
    } else {
      printf("branch pfmet_jdown_branch does not exist!\n");
      exit(1);
    }
    pfmet_jdown_isLoaded = true;
  }
  return pfmet_jdown_;
}

const float &CMS3::pfmet_phi_jdown() {
  if (not pfmet_phi_jdown_isLoaded) {
    if (pfmet_phi_jdown_branch != 0) {
      pfmet_phi_jdown_branch->GetEntry(index);
    } else {
      printf("branch pfmet_phi_jdown_branch does not exist!\n");
      exit(1);
    }
    pfmet_phi_jdown_isLoaded = true;
  }
  return pfmet_phi_jdown_;
}

const float &CMS3::pfmet_rl() {
  if (not pfmet_rl_isLoaded) {
    if (pfmet_rl_branch != 0) {
      pfmet_rl_branch->GetEntry(index);
    } else {
      printf("branch pfmet_rl_branch does not exist!\n");
      exit(1);
    }
    pfmet_rl_isLoaded = true;
  }
  return pfmet_rl_;
}

const float &CMS3::pfmet_phi_rl() {
  if (not pfmet_phi_rl_isLoaded) {
    if (pfmet_phi_rl_branch != 0) {
      pfmet_phi_rl_branch->GetEntry(index);
    } else {
      printf("branch pfmet_phi_rl_branch does not exist!\n");
      exit(1);
    }
    pfmet_phi_rl_isLoaded = true;
  }
  return pfmet_phi_rl_;
}

const float &CMS3::pfmet_rl_jup() {
  if (not pfmet_rl_jup_isLoaded) {
    if (pfmet_rl_jup_branch != 0) {
      pfmet_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch pfmet_rl_jup_branch does not exist!\n");
      exit(1);
    }
    pfmet_rl_jup_isLoaded = true;
  }
  return pfmet_rl_jup_;
}

const float &CMS3::pfmet_phi_rl_jup() {
  if (not pfmet_phi_rl_jup_isLoaded) {
    if (pfmet_phi_rl_jup_branch != 0) {
      pfmet_phi_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch pfmet_phi_rl_jup_branch does not exist!\n");
      exit(1);
    }
    pfmet_phi_rl_jup_isLoaded = true;
  }
  return pfmet_phi_rl_jup_;
}

const float &CMS3::pfmet_rl_jdown() {
  if (not pfmet_rl_jdown_isLoaded) {
    if (pfmet_rl_jdown_branch != 0) {
      pfmet_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch pfmet_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    pfmet_rl_jdown_isLoaded = true;
  }
  return pfmet_rl_jdown_;
}

const float &CMS3::pfmet_phi_rl_jdown() {
  if (not pfmet_phi_rl_jdown_isLoaded) {
    if (pfmet_phi_rl_jdown_branch != 0) {
      pfmet_phi_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch pfmet_phi_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    pfmet_phi_rl_jdown_isLoaded = true;
  }
  return pfmet_phi_rl_jdown_;
}

const float &CMS3::pfmet_egclean() {
  if (not pfmet_egclean_isLoaded) {
    if (pfmet_egclean_branch != 0) {
      pfmet_egclean_branch->GetEntry(index);
    } else {
      printf("branch pfmet_egclean_branch does not exist!\n");
      exit(1);
    }
    pfmet_egclean_isLoaded = true;
  }
  return pfmet_egclean_;
}

const float &CMS3::pfmet_egclean_phi() {
  if (not pfmet_egclean_phi_isLoaded) {
    if (pfmet_egclean_phi_branch != 0) {
      pfmet_egclean_phi_branch->GetEntry(index);
    } else {
      printf("branch pfmet_egclean_phi_branch does not exist!\n");
      exit(1);
    }
    pfmet_egclean_phi_isLoaded = true;
  }
  return pfmet_egclean_phi_;
}

const float &CMS3::pfmet_muegclean() {
  if (not pfmet_muegclean_isLoaded) {
    if (pfmet_muegclean_branch != 0) {
      pfmet_muegclean_branch->GetEntry(index);
    } else {
      printf("branch pfmet_muegclean_branch does not exist!\n");
      exit(1);
    }
    pfmet_muegclean_isLoaded = true;
  }
  return pfmet_muegclean_;
}

const float &CMS3::pfmet_muegclean_phi() {
  if (not pfmet_muegclean_phi_isLoaded) {
    if (pfmet_muegclean_phi_branch != 0) {
      pfmet_muegclean_phi_branch->GetEntry(index);
    } else {
      printf("branch pfmet_muegclean_phi_branch does not exist!\n");
      exit(1);
    }
    pfmet_muegclean_phi_isLoaded = true;
  }
  return pfmet_muegclean_phi_;
}

const float &CMS3::pfmet_muegcleanfix() {
  if (not pfmet_muegcleanfix_isLoaded) {
    if (pfmet_muegcleanfix_branch != 0) {
      pfmet_muegcleanfix_branch->GetEntry(index);
    } else {
      printf("branch pfmet_muegcleanfix_branch does not exist!\n");
      exit(1);
    }
    pfmet_muegcleanfix_isLoaded = true;
  }
  return pfmet_muegcleanfix_;
}

const float &CMS3::pfmet_muegcleanfix_phi() {
  if (not pfmet_muegcleanfix_phi_isLoaded) {
    if (pfmet_muegcleanfix_phi_branch != 0) {
      pfmet_muegcleanfix_phi_branch->GetEntry(index);
    } else {
      printf("branch pfmet_muegcleanfix_phi_branch does not exist!\n");
      exit(1);
    }
    pfmet_muegcleanfix_phi_isLoaded = true;
  }
  return pfmet_muegcleanfix_phi_;
}

const float &CMS3::pfmet_uncorr() {
  if (not pfmet_uncorr_isLoaded) {
    if (pfmet_uncorr_branch != 0) {
      pfmet_uncorr_branch->GetEntry(index);
    } else {
      printf("branch pfmet_uncorr_branch does not exist!\n");
      exit(1);
    }
    pfmet_uncorr_isLoaded = true;
  }
  return pfmet_uncorr_;
}

const float &CMS3::pfmet_uncorr_phi() {
  if (not pfmet_uncorr_phi_isLoaded) {
    if (pfmet_uncorr_phi_branch != 0) {
      pfmet_uncorr_phi_branch->GetEntry(index);
    } else {
      printf("branch pfmet_uncorr_phi_branch does not exist!\n");
      exit(1);
    }
    pfmet_uncorr_phi_isLoaded = true;
  }
  return pfmet_uncorr_phi_;
}

const float &CMS3::pfmet_original() {
  if (not pfmet_original_isLoaded) {
    if (pfmet_original_branch != 0) {
      pfmet_original_branch->GetEntry(index);
    } else {
      printf("branch pfmet_original_branch does not exist!\n");
      exit(1);
    }
    pfmet_original_isLoaded = true;
  }
  return pfmet_original_;
}

const float &CMS3::pfmet_original_phi() {
  if (not pfmet_original_phi_isLoaded) {
    if (pfmet_original_phi_branch != 0) {
      pfmet_original_phi_branch->GetEntry(index);
    } else {
      printf("branch pfmet_original_phi_branch does not exist!\n");
      exit(1);
    }
    pfmet_original_phi_isLoaded = true;
  }
  return pfmet_original_phi_;
}

const float &CMS3::scale1fb() {
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

const float &CMS3::xsec() {
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

const float &CMS3::xsec_uncert() {
  if (not xsec_uncert_isLoaded) {
    if (xsec_uncert_branch != 0) {
      xsec_uncert_branch->GetEntry(index);
    } else {
      printf("branch xsec_uncert_branch does not exist!\n");
      exit(1);
    }
    xsec_uncert_isLoaded = true;
  }
  return xsec_uncert_;
}

const float &CMS3::kfactor() {
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

const float &CMS3::pu_ntrue() {
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

const int &CMS3::ngoodleps() {
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

const int &CMS3::nlooseleps() {
  if (not nlooseleps_isLoaded) {
    if (nlooseleps_branch != 0) {
      nlooseleps_branch->GetEntry(index);
    } else {
      printf("branch nlooseleps_branch does not exist!\n");
      exit(1);
    }
    nlooseleps_isLoaded = true;
  }
  return nlooseleps_;
}

const int &CMS3::nvetoleps() {
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

const bool &CMS3::is_data() {
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

const string &CMS3::dataset() {
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

const string &CMS3::filename() {
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

const string &CMS3::cms3tag() {
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

const unsigned int &CMS3::nEvents() {
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

const unsigned int &CMS3::nEvents_goodvtx() {
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

const unsigned int &CMS3::nEvents_MET30() {
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

const unsigned int &CMS3::nEvents_1goodlep() {
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

const unsigned int &CMS3::nEvents_2goodjets() {
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

const int &CMS3::is0lep() {
  if (not is0lep_isLoaded) {
    if (is0lep_branch != 0) {
      is0lep_branch->GetEntry(index);
    } else {
      printf("branch is0lep_branch does not exist!\n");
      exit(1);
    }
    is0lep_isLoaded = true;
  }
  return is0lep_;
}

const int &CMS3::is1lep() {
  if (not is1lep_isLoaded) {
    if (is1lep_branch != 0) {
      is1lep_branch->GetEntry(index);
    } else {
      printf("branch is1lep_branch does not exist!\n");
      exit(1);
    }
    is1lep_isLoaded = true;
  }
  return is1lep_;
}

const int &CMS3::is2lep() {
  if (not is2lep_isLoaded) {
    if (is2lep_branch != 0) {
      is2lep_branch->GetEntry(index);
    } else {
      printf("branch is2lep_branch does not exist!\n");
      exit(1);
    }
    is2lep_isLoaded = true;
  }
  return is2lep_;
}

const int &CMS3::isZtoNuNu() {
  if (not isZtoNuNu_isLoaded) {
    if (isZtoNuNu_branch != 0) {
      isZtoNuNu_branch->GetEntry(index);
    } else {
      printf("branch isZtoNuNu_branch does not exist!\n");
      exit(1);
    }
    isZtoNuNu_isLoaded = true;
  }
  return isZtoNuNu_;
}

const int &CMS3::is1lepFromW() {
  if (not is1lepFromW_isLoaded) {
    if (is1lepFromW_branch != 0) {
      is1lepFromW_branch->GetEntry(index);
    } else {
      printf("branch is1lepFromW_branch does not exist!\n");
      exit(1);
    }
    is1lepFromW_isLoaded = true;
  }
  return is1lepFromW_;
}

const int &CMS3::is1lepFromTop() {
  if (not is1lepFromTop_isLoaded) {
    if (is1lepFromTop_branch != 0) {
      is1lepFromTop_branch->GetEntry(index);
    } else {
      printf("branch is1lepFromTop_branch does not exist!\n");
      exit(1);
    }
    is1lepFromTop_isLoaded = true;
  }
  return is1lepFromTop_;
}

const float &CMS3::MT2W() {
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

const float &CMS3::MT2W_rl() {
  if (not MT2W_rl_isLoaded) {
    if (MT2W_rl_branch != 0) {
      MT2W_rl_branch->GetEntry(index);
    } else {
      printf("branch MT2W_rl_branch does not exist!\n");
      exit(1);
    }
    MT2W_rl_isLoaded = true;
  }
  return MT2W_rl_;
}

const float &CMS3::mindphi_met_j1_j2() {
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

const float &CMS3::mindphi_met_j1_j2_rl() {
  if (not mindphi_met_j1_j2_rl_isLoaded) {
    if (mindphi_met_j1_j2_rl_branch != 0) {
      mindphi_met_j1_j2_rl_branch->GetEntry(index);
    } else {
      printf("branch mindphi_met_j1_j2_rl_branch does not exist!\n");
      exit(1);
    }
    mindphi_met_j1_j2_rl_isLoaded = true;
  }
  return mindphi_met_j1_j2_rl_;
}

const float &CMS3::mt_met_lep() {
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

const float &CMS3::mt_met_lep_rl() {
  if (not mt_met_lep_rl_isLoaded) {
    if (mt_met_lep_rl_branch != 0) {
      mt_met_lep_rl_branch->GetEntry(index);
    } else {
      printf("branch mt_met_lep_rl_branch does not exist!\n");
      exit(1);
    }
    mt_met_lep_rl_isLoaded = true;
  }
  return mt_met_lep_rl_;
}

const float &CMS3::MT2W_jup() {
  if (not MT2W_jup_isLoaded) {
    if (MT2W_jup_branch != 0) {
      MT2W_jup_branch->GetEntry(index);
    } else {
      printf("branch MT2W_jup_branch does not exist!\n");
      exit(1);
    }
    MT2W_jup_isLoaded = true;
  }
  return MT2W_jup_;
}

const float &CMS3::MT2W_rl_jup() {
  if (not MT2W_rl_jup_isLoaded) {
    if (MT2W_rl_jup_branch != 0) {
      MT2W_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch MT2W_rl_jup_branch does not exist!\n");
      exit(1);
    }
    MT2W_rl_jup_isLoaded = true;
  }
  return MT2W_rl_jup_;
}

const float &CMS3::mindphi_met_j1_j2_jup() {
  if (not mindphi_met_j1_j2_jup_isLoaded) {
    if (mindphi_met_j1_j2_jup_branch != 0) {
      mindphi_met_j1_j2_jup_branch->GetEntry(index);
    } else {
      printf("branch mindphi_met_j1_j2_jup_branch does not exist!\n");
      exit(1);
    }
    mindphi_met_j1_j2_jup_isLoaded = true;
  }
  return mindphi_met_j1_j2_jup_;
}

const float &CMS3::mindphi_met_j1_j2_rl_jup() {
  if (not mindphi_met_j1_j2_rl_jup_isLoaded) {
    if (mindphi_met_j1_j2_rl_jup_branch != 0) {
      mindphi_met_j1_j2_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch mindphi_met_j1_j2_rl_jup_branch does not exist!\n");
      exit(1);
    }
    mindphi_met_j1_j2_rl_jup_isLoaded = true;
  }
  return mindphi_met_j1_j2_rl_jup_;
}

const float &CMS3::mt_met_lep_jup() {
  if (not mt_met_lep_jup_isLoaded) {
    if (mt_met_lep_jup_branch != 0) {
      mt_met_lep_jup_branch->GetEntry(index);
    } else {
      printf("branch mt_met_lep_jup_branch does not exist!\n");
      exit(1);
    }
    mt_met_lep_jup_isLoaded = true;
  }
  return mt_met_lep_jup_;
}

const float &CMS3::mt_met_lep_rl_jup() {
  if (not mt_met_lep_rl_jup_isLoaded) {
    if (mt_met_lep_rl_jup_branch != 0) {
      mt_met_lep_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch mt_met_lep_rl_jup_branch does not exist!\n");
      exit(1);
    }
    mt_met_lep_rl_jup_isLoaded = true;
  }
  return mt_met_lep_rl_jup_;
}

const float &CMS3::MT2W_jdown() {
  if (not MT2W_jdown_isLoaded) {
    if (MT2W_jdown_branch != 0) {
      MT2W_jdown_branch->GetEntry(index);
    } else {
      printf("branch MT2W_jdown_branch does not exist!\n");
      exit(1);
    }
    MT2W_jdown_isLoaded = true;
  }
  return MT2W_jdown_;
}

const float &CMS3::MT2W_rl_jdown() {
  if (not MT2W_rl_jdown_isLoaded) {
    if (MT2W_rl_jdown_branch != 0) {
      MT2W_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch MT2W_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    MT2W_rl_jdown_isLoaded = true;
  }
  return MT2W_rl_jdown_;
}

const float &CMS3::mindphi_met_j1_j2_jdown() {
  if (not mindphi_met_j1_j2_jdown_isLoaded) {
    if (mindphi_met_j1_j2_jdown_branch != 0) {
      mindphi_met_j1_j2_jdown_branch->GetEntry(index);
    } else {
      printf("branch mindphi_met_j1_j2_jdown_branch does not exist!\n");
      exit(1);
    }
    mindphi_met_j1_j2_jdown_isLoaded = true;
  }
  return mindphi_met_j1_j2_jdown_;
}

const float &CMS3::mindphi_met_j1_j2_rl_jdown() {
  if (not mindphi_met_j1_j2_rl_jdown_isLoaded) {
    if (mindphi_met_j1_j2_rl_jdown_branch != 0) {
      mindphi_met_j1_j2_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch mindphi_met_j1_j2_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    mindphi_met_j1_j2_rl_jdown_isLoaded = true;
  }
  return mindphi_met_j1_j2_rl_jdown_;
}

const float &CMS3::mt_met_lep_jdown() {
  if (not mt_met_lep_jdown_isLoaded) {
    if (mt_met_lep_jdown_branch != 0) {
      mt_met_lep_jdown_branch->GetEntry(index);
    } else {
      printf("branch mt_met_lep_jdown_branch does not exist!\n");
      exit(1);
    }
    mt_met_lep_jdown_isLoaded = true;
  }
  return mt_met_lep_jdown_;
}

const float &CMS3::mt_met_lep_rl_jdown() {
  if (not mt_met_lep_rl_jdown_isLoaded) {
    if (mt_met_lep_rl_jdown_branch != 0) {
      mt_met_lep_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch mt_met_lep_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    mt_met_lep_rl_jdown_isLoaded = true;
  }
  return mt_met_lep_rl_jdown_;
}

const float &CMS3::hadronic_top_chi2() {
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

const float &CMS3::ak4pfjets_rho() {
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

const float &CMS3::pdf_up_weight() {
  if (not pdf_up_weight_isLoaded) {
    if (pdf_up_weight_branch != 0) {
      pdf_up_weight_branch->GetEntry(index);
    } else {
      printf("branch pdf_up_weight_branch does not exist!\n");
      exit(1);
    }
    pdf_up_weight_isLoaded = true;
  }
  return pdf_up_weight_;
}

const float &CMS3::pdf_down_weight() {
  if (not pdf_down_weight_isLoaded) {
    if (pdf_down_weight_branch != 0) {
      pdf_down_weight_branch->GetEntry(index);
    } else {
      printf("branch pdf_down_weight_branch does not exist!\n");
      exit(1);
    }
    pdf_down_weight_isLoaded = true;
  }
  return pdf_down_weight_;
}

const vector<string> &CMS3::genweightsID() {
  if (not genweightsID_isLoaded) {
    if (genweightsID_branch != 0) {
      genweightsID_branch->GetEntry(index);
    } else {
      printf("branch genweightsID_branch does not exist!\n");
      exit(1);
    }
    genweightsID_isLoaded = true;
  }
  return *genweightsID_;
}

const vector<float> &CMS3::genweights() {
  if (not genweights_isLoaded) {
    if (genweights_branch != 0) {
      genweights_branch->GetEntry(index);
    } else {
      printf("branch genweights_branch does not exist!\n");
      exit(1);
    }
    genweights_isLoaded = true;
  }
  return *genweights_;
}

const float &CMS3::weight_btagsf() {
  if (not weight_btagsf_isLoaded) {
    if (weight_btagsf_branch != 0) {
      weight_btagsf_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_isLoaded = true;
  }
  return weight_btagsf_;
}

const float &CMS3::weight_btagsf_heavy_UP() {
  if (not weight_btagsf_heavy_UP_isLoaded) {
    if (weight_btagsf_heavy_UP_branch != 0) {
      weight_btagsf_heavy_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_heavy_UP_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_heavy_UP_isLoaded = true;
  }
  return weight_btagsf_heavy_UP_;
}

const float &CMS3::weight_btagsf_light_UP() {
  if (not weight_btagsf_light_UP_isLoaded) {
    if (weight_btagsf_light_UP_branch != 0) {
      weight_btagsf_light_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_light_UP_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_light_UP_isLoaded = true;
  }
  return weight_btagsf_light_UP_;
}

const float &CMS3::weight_btagsf_heavy_DN() {
  if (not weight_btagsf_heavy_DN_isLoaded) {
    if (weight_btagsf_heavy_DN_branch != 0) {
      weight_btagsf_heavy_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_heavy_DN_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_heavy_DN_isLoaded = true;
  }
  return weight_btagsf_heavy_DN_;
}

const float &CMS3::weight_btagsf_light_DN() {
  if (not weight_btagsf_light_DN_isLoaded) {
    if (weight_btagsf_light_DN_branch != 0) {
      weight_btagsf_light_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_light_DN_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_light_DN_isLoaded = true;
  }
  return weight_btagsf_light_DN_;
}

const float &CMS3::weight_btagsf_fastsim_UP() {
  if (not weight_btagsf_fastsim_UP_isLoaded) {
    if (weight_btagsf_fastsim_UP_branch != 0) {
      weight_btagsf_fastsim_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_fastsim_UP_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_fastsim_UP_isLoaded = true;
  }
  return weight_btagsf_fastsim_UP_;
}

const float &CMS3::weight_btagsf_fastsim_DN() {
  if (not weight_btagsf_fastsim_DN_isLoaded) {
    if (weight_btagsf_fastsim_DN_branch != 0) {
      weight_btagsf_fastsim_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_btagsf_fastsim_DN_branch does not exist!\n");
      exit(1);
    }
    weight_btagsf_fastsim_DN_isLoaded = true;
  }
  return weight_btagsf_fastsim_DN_;
}

const float &CMS3::weight_analysisbtagsf() {
  if (not weight_analysisbtagsf_isLoaded) {
    if (weight_analysisbtagsf_branch != 0) {
      weight_analysisbtagsf_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_isLoaded = true;
  }
  return weight_analysisbtagsf_;
}

const float &CMS3::weight_analysisbtagsf_heavy_UP() {
  if (not weight_analysisbtagsf_heavy_UP_isLoaded) {
    if (weight_analysisbtagsf_heavy_UP_branch != 0) {
      weight_analysisbtagsf_heavy_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_heavy_UP_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_heavy_UP_isLoaded = true;
  }
  return weight_analysisbtagsf_heavy_UP_;
}

const float &CMS3::weight_analysisbtagsf_light_UP() {
  if (not weight_analysisbtagsf_light_UP_isLoaded) {
    if (weight_analysisbtagsf_light_UP_branch != 0) {
      weight_analysisbtagsf_light_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_light_UP_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_light_UP_isLoaded = true;
  }
  return weight_analysisbtagsf_light_UP_;
}

const float &CMS3::weight_analysisbtagsf_heavy_DN() {
  if (not weight_analysisbtagsf_heavy_DN_isLoaded) {
    if (weight_analysisbtagsf_heavy_DN_branch != 0) {
      weight_analysisbtagsf_heavy_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_heavy_DN_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_heavy_DN_isLoaded = true;
  }
  return weight_analysisbtagsf_heavy_DN_;
}

const float &CMS3::weight_analysisbtagsf_light_DN() {
  if (not weight_analysisbtagsf_light_DN_isLoaded) {
    if (weight_analysisbtagsf_light_DN_branch != 0) {
      weight_analysisbtagsf_light_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_light_DN_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_light_DN_isLoaded = true;
  }
  return weight_analysisbtagsf_light_DN_;
}

const float &CMS3::weight_analysisbtagsf_fastsim_UP() {
  if (not weight_analysisbtagsf_fastsim_UP_isLoaded) {
    if (weight_analysisbtagsf_fastsim_UP_branch != 0) {
      weight_analysisbtagsf_fastsim_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_fastsim_UP_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_fastsim_UP_isLoaded = true;
  }
  return weight_analysisbtagsf_fastsim_UP_;
}

const float &CMS3::weight_analysisbtagsf_fastsim_DN() {
  if (not weight_analysisbtagsf_fastsim_DN_isLoaded) {
    if (weight_analysisbtagsf_fastsim_DN_branch != 0) {
      weight_analysisbtagsf_fastsim_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_analysisbtagsf_fastsim_DN_branch does not exist!\n");
      exit(1);
    }
    weight_analysisbtagsf_fastsim_DN_isLoaded = true;
  }
  return weight_analysisbtagsf_fastsim_DN_;
}

const float &CMS3::weight_tightbtagsf() {
  if (not weight_tightbtagsf_isLoaded) {
    if (weight_tightbtagsf_branch != 0) {
      weight_tightbtagsf_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_isLoaded = true;
  }
  return weight_tightbtagsf_;
}

const float &CMS3::weight_tightbtagsf_heavy_UP() {
  if (not weight_tightbtagsf_heavy_UP_isLoaded) {
    if (weight_tightbtagsf_heavy_UP_branch != 0) {
      weight_tightbtagsf_heavy_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_heavy_UP_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_heavy_UP_isLoaded = true;
  }
  return weight_tightbtagsf_heavy_UP_;
}

const float &CMS3::weight_tightbtagsf_light_UP() {
  if (not weight_tightbtagsf_light_UP_isLoaded) {
    if (weight_tightbtagsf_light_UP_branch != 0) {
      weight_tightbtagsf_light_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_light_UP_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_light_UP_isLoaded = true;
  }
  return weight_tightbtagsf_light_UP_;
}

const float &CMS3::weight_tightbtagsf_heavy_DN() {
  if (not weight_tightbtagsf_heavy_DN_isLoaded) {
    if (weight_tightbtagsf_heavy_DN_branch != 0) {
      weight_tightbtagsf_heavy_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_heavy_DN_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_heavy_DN_isLoaded = true;
  }
  return weight_tightbtagsf_heavy_DN_;
}

const float &CMS3::weight_tightbtagsf_light_DN() {
  if (not weight_tightbtagsf_light_DN_isLoaded) {
    if (weight_tightbtagsf_light_DN_branch != 0) {
      weight_tightbtagsf_light_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_light_DN_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_light_DN_isLoaded = true;
  }
  return weight_tightbtagsf_light_DN_;
}

const float &CMS3::weight_tightbtagsf_fastsim_UP() {
  if (not weight_tightbtagsf_fastsim_UP_isLoaded) {
    if (weight_tightbtagsf_fastsim_UP_branch != 0) {
      weight_tightbtagsf_fastsim_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_fastsim_UP_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_fastsim_UP_isLoaded = true;
  }
  return weight_tightbtagsf_fastsim_UP_;
}

const float &CMS3::weight_tightbtagsf_fastsim_DN() {
  if (not weight_tightbtagsf_fastsim_DN_isLoaded) {
    if (weight_tightbtagsf_fastsim_DN_branch != 0) {
      weight_tightbtagsf_fastsim_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_tightbtagsf_fastsim_DN_branch does not exist!\n");
      exit(1);
    }
    weight_tightbtagsf_fastsim_DN_isLoaded = true;
  }
  return weight_tightbtagsf_fastsim_DN_;
}

const float &CMS3::weight_loosebtagsf() {
  if (not weight_loosebtagsf_isLoaded) {
    if (weight_loosebtagsf_branch != 0) {
      weight_loosebtagsf_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_isLoaded = true;
  }
  return weight_loosebtagsf_;
}

const float &CMS3::weight_loosebtagsf_heavy_UP() {
  if (not weight_loosebtagsf_heavy_UP_isLoaded) {
    if (weight_loosebtagsf_heavy_UP_branch != 0) {
      weight_loosebtagsf_heavy_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_heavy_UP_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_heavy_UP_isLoaded = true;
  }
  return weight_loosebtagsf_heavy_UP_;
}

const float &CMS3::weight_loosebtagsf_light_UP() {
  if (not weight_loosebtagsf_light_UP_isLoaded) {
    if (weight_loosebtagsf_light_UP_branch != 0) {
      weight_loosebtagsf_light_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_light_UP_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_light_UP_isLoaded = true;
  }
  return weight_loosebtagsf_light_UP_;
}

const float &CMS3::weight_loosebtagsf_heavy_DN() {
  if (not weight_loosebtagsf_heavy_DN_isLoaded) {
    if (weight_loosebtagsf_heavy_DN_branch != 0) {
      weight_loosebtagsf_heavy_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_heavy_DN_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_heavy_DN_isLoaded = true;
  }
  return weight_loosebtagsf_heavy_DN_;
}

const float &CMS3::weight_loosebtagsf_light_DN() {
  if (not weight_loosebtagsf_light_DN_isLoaded) {
    if (weight_loosebtagsf_light_DN_branch != 0) {
      weight_loosebtagsf_light_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_light_DN_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_light_DN_isLoaded = true;
  }
  return weight_loosebtagsf_light_DN_;
}

const float &CMS3::weight_loosebtagsf_fastsim_UP() {
  if (not weight_loosebtagsf_fastsim_UP_isLoaded) {
    if (weight_loosebtagsf_fastsim_UP_branch != 0) {
      weight_loosebtagsf_fastsim_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_fastsim_UP_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_fastsim_UP_isLoaded = true;
  }
  return weight_loosebtagsf_fastsim_UP_;
}

const float &CMS3::weight_loosebtagsf_fastsim_DN() {
  if (not weight_loosebtagsf_fastsim_DN_isLoaded) {
    if (weight_loosebtagsf_fastsim_DN_branch != 0) {
      weight_loosebtagsf_fastsim_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_loosebtagsf_fastsim_DN_branch does not exist!\n");
      exit(1);
    }
    weight_loosebtagsf_fastsim_DN_isLoaded = true;
  }
  return weight_loosebtagsf_fastsim_DN_;
}

const float &CMS3::weight_lepSF() {
  if (not weight_lepSF_isLoaded) {
    if (weight_lepSF_branch != 0) {
      weight_lepSF_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_isLoaded = true;
  }
  return weight_lepSF_;
}

const float &CMS3::weight_lepSF_up() {
  if (not weight_lepSF_up_isLoaded) {
    if (weight_lepSF_up_branch != 0) {
      weight_lepSF_up_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_up_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_up_isLoaded = true;
  }
  return weight_lepSF_up_;
}

const float &CMS3::weight_lepSF_down() {
  if (not weight_lepSF_down_isLoaded) {
    if (weight_lepSF_down_branch != 0) {
      weight_lepSF_down_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_down_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_down_isLoaded = true;
  }
  return weight_lepSF_down_;
}

const float &CMS3::weight_vetoLepSF() {
  if (not weight_vetoLepSF_isLoaded) {
    if (weight_vetoLepSF_branch != 0) {
      weight_vetoLepSF_branch->GetEntry(index);
    } else {
      printf("branch weight_vetoLepSF_branch does not exist!\n");
      exit(1);
    }
    weight_vetoLepSF_isLoaded = true;
  }
  return weight_vetoLepSF_;
}

const float &CMS3::weight_vetoLepSF_up() {
  if (not weight_vetoLepSF_up_isLoaded) {
    if (weight_vetoLepSF_up_branch != 0) {
      weight_vetoLepSF_up_branch->GetEntry(index);
    } else {
      printf("branch weight_vetoLepSF_up_branch does not exist!\n");
      exit(1);
    }
    weight_vetoLepSF_up_isLoaded = true;
  }
  return weight_vetoLepSF_up_;
}

const float &CMS3::weight_vetoLepSF_down() {
  if (not weight_vetoLepSF_down_isLoaded) {
    if (weight_vetoLepSF_down_branch != 0) {
      weight_vetoLepSF_down_branch->GetEntry(index);
    } else {
      printf("branch weight_vetoLepSF_down_branch does not exist!\n");
      exit(1);
    }
    weight_vetoLepSF_down_isLoaded = true;
  }
  return weight_vetoLepSF_down_;
}

const float &CMS3::weight_lepSF_fastSim() {
  if (not weight_lepSF_fastSim_isLoaded) {
    if (weight_lepSF_fastSim_branch != 0) {
      weight_lepSF_fastSim_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_fastSim_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_fastSim_isLoaded = true;
  }
  return weight_lepSF_fastSim_;
}

const float &CMS3::weight_lepSF_fastSim_up() {
  if (not weight_lepSF_fastSim_up_isLoaded) {
    if (weight_lepSF_fastSim_up_branch != 0) {
      weight_lepSF_fastSim_up_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_fastSim_up_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_fastSim_up_isLoaded = true;
  }
  return weight_lepSF_fastSim_up_;
}

const float &CMS3::weight_lepSF_fastSim_down() {
  if (not weight_lepSF_fastSim_down_isLoaded) {
    if (weight_lepSF_fastSim_down_branch != 0) {
      weight_lepSF_fastSim_down_branch->GetEntry(index);
    } else {
      printf("branch weight_lepSF_fastSim_down_branch does not exist!\n");
      exit(1);
    }
    weight_lepSF_fastSim_down_isLoaded = true;
  }
  return weight_lepSF_fastSim_down_;
}

const float &CMS3::weight_ISR() {
  if (not weight_ISR_isLoaded) {
    if (weight_ISR_branch != 0) {
      weight_ISR_branch->GetEntry(index);
    } else {
      printf("branch weight_ISR_branch does not exist!\n");
      exit(1);
    }
    weight_ISR_isLoaded = true;
  }
  return weight_ISR_;
}

const float &CMS3::weight_ISRup() {
  if (not weight_ISRup_isLoaded) {
    if (weight_ISRup_branch != 0) {
      weight_ISRup_branch->GetEntry(index);
    } else {
      printf("branch weight_ISRup_branch does not exist!\n");
      exit(1);
    }
    weight_ISRup_isLoaded = true;
  }
  return weight_ISRup_;
}

const float &CMS3::weight_ISRdown() {
  if (not weight_ISRdown_isLoaded) {
    if (weight_ISRdown_branch != 0) {
      weight_ISRdown_branch->GetEntry(index);
    } else {
      printf("branch weight_ISRdown_branch does not exist!\n");
      exit(1);
    }
    weight_ISRdown_isLoaded = true;
  }
  return weight_ISRdown_;
}

const float &CMS3::weight_PU() {
  if (not weight_PU_isLoaded) {
    if (weight_PU_branch != 0) {
      weight_PU_branch->GetEntry(index);
    } else {
      printf("branch weight_PU_branch does not exist!\n");
      exit(1);
    }
    weight_PU_isLoaded = true;
  }
  return weight_PU_;
}

const float &CMS3::weight_PUup() {
  if (not weight_PUup_isLoaded) {
    if (weight_PUup_branch != 0) {
      weight_PUup_branch->GetEntry(index);
    } else {
      printf("branch weight_PUup_branch does not exist!\n");
      exit(1);
    }
    weight_PUup_isLoaded = true;
  }
  return weight_PUup_;
}

const float &CMS3::weight_PUdown() {
  if (not weight_PUdown_isLoaded) {
    if (weight_PUdown_branch != 0) {
      weight_PUdown_branch->GetEntry(index);
    } else {
      printf("branch weight_PUdown_branch does not exist!\n");
      exit(1);
    }
    weight_PUdown_isLoaded = true;
  }
  return weight_PUdown_;
}

const float &CMS3::weight_ISRnjets() {
  if (not weight_ISRnjets_isLoaded) {
    if (weight_ISRnjets_branch != 0) {
      weight_ISRnjets_branch->GetEntry(index);
    } else {
      printf("branch weight_ISRnjets_branch does not exist!\n");
      exit(1);
    }
    weight_ISRnjets_isLoaded = true;
  }
  return weight_ISRnjets_;
}

const float &CMS3::weight_ISRnjets_UP() {
  if (not weight_ISRnjets_UP_isLoaded) {
    if (weight_ISRnjets_UP_branch != 0) {
      weight_ISRnjets_UP_branch->GetEntry(index);
    } else {
      printf("branch weight_ISRnjets_UP_branch does not exist!\n");
      exit(1);
    }
    weight_ISRnjets_UP_isLoaded = true;
  }
  return weight_ISRnjets_UP_;
}

const float &CMS3::weight_ISRnjets_DN() {
  if (not weight_ISRnjets_DN_isLoaded) {
    if (weight_ISRnjets_DN_branch != 0) {
      weight_ISRnjets_DN_branch->GetEntry(index);
    } else {
      printf("branch weight_ISRnjets_DN_branch does not exist!\n");
      exit(1);
    }
    weight_ISRnjets_DN_isLoaded = true;
  }
  return weight_ISRnjets_DN_;
}

const int &CMS3::NISRjets() {
  if (not NISRjets_isLoaded) {
    if (NISRjets_branch != 0) {
      NISRjets_branch->GetEntry(index);
    } else {
      printf("branch NISRjets_branch does not exist!\n");
      exit(1);
    }
    NISRjets_isLoaded = true;
  }
  return NISRjets_;
}

const int &CMS3::NnonISRjets() {
  if (not NnonISRjets_isLoaded) {
    if (NnonISRjets_branch != 0) {
      NnonISRjets_branch->GetEntry(index);
    } else {
      printf("branch NnonISRjets_branch does not exist!\n");
      exit(1);
    }
    NnonISRjets_isLoaded = true;
  }
  return NnonISRjets_;
}

const vector<string> &CMS3::sparms_names() {
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

const vector<float> &CMS3::sparms_values() {
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

const int &CMS3::sparms_subProcessId() {
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

const float &CMS3::mass_lsp() {
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

const float &CMS3::mass_chargino() {
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

const float &CMS3::mass_stop() {
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

const float &CMS3::mass_gluino() {
  if (not mass_gluino_isLoaded) {
    if (mass_gluino_branch != 0) {
      mass_gluino_branch->GetEntry(index);
    } else {
      printf("branch mass_gluino_branch does not exist!\n");
      exit(1);
    }
    mass_gluino_isLoaded = true;
  }
  return mass_gluino_;
}

const float &CMS3::genmet() {
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

const float &CMS3::genmet_phi() {
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

const float &CMS3::nupt() {
  if (not nupt_isLoaded) {
    if (nupt_branch != 0) {
      nupt_branch->GetEntry(index);
    } else {
      printf("branch nupt_branch does not exist!\n");
      exit(1);
    }
    nupt_isLoaded = true;
  }
  return nupt_;
}

const float &CMS3::genht() {
  if (not genht_isLoaded) {
    if (genht_branch != 0) {
      genht_branch->GetEntry(index);
    } else {
      printf("branch genht_branch does not exist!\n");
      exit(1);
    }
    genht_isLoaded = true;
  }
  return genht_;
}

const bool &CMS3::PassTrackVeto() {
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

const bool &CMS3::PassTauVeto() {
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

const float &CMS3::topness() {
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

const float &CMS3::topnessMod() {
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

const float &CMS3::topnessMod_rl() {
  if (not topnessMod_rl_isLoaded) {
    if (topnessMod_rl_branch != 0) {
      topnessMod_rl_branch->GetEntry(index);
    } else {
      printf("branch topnessMod_rl_branch does not exist!\n");
      exit(1);
    }
    topnessMod_rl_isLoaded = true;
  }
  return topnessMod_rl_;
}

const float &CMS3::topnessMod_jup() {
  if (not topnessMod_jup_isLoaded) {
    if (topnessMod_jup_branch != 0) {
      topnessMod_jup_branch->GetEntry(index);
    } else {
      printf("branch topnessMod_jup_branch does not exist!\n");
      exit(1);
    }
    topnessMod_jup_isLoaded = true;
  }
  return topnessMod_jup_;
}

const float &CMS3::topnessMod_rl_jup() {
  if (not topnessMod_rl_jup_isLoaded) {
    if (topnessMod_rl_jup_branch != 0) {
      topnessMod_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch topnessMod_rl_jup_branch does not exist!\n");
      exit(1);
    }
    topnessMod_rl_jup_isLoaded = true;
  }
  return topnessMod_rl_jup_;
}

const float &CMS3::topnessMod_jdown() {
  if (not topnessMod_jdown_isLoaded) {
    if (topnessMod_jdown_branch != 0) {
      topnessMod_jdown_branch->GetEntry(index);
    } else {
      printf("branch topnessMod_jdown_branch does not exist!\n");
      exit(1);
    }
    topnessMod_jdown_isLoaded = true;
  }
  return topnessMod_jdown_;
}

const float &CMS3::topnessMod_rl_jdown() {
  if (not topnessMod_rl_jdown_isLoaded) {
    if (topnessMod_rl_jdown_branch != 0) {
      topnessMod_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch topnessMod_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    topnessMod_rl_jdown_isLoaded = true;
  }
  return topnessMod_rl_jdown_;
}

const float &CMS3::Mlb_closestb() {
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

const float &CMS3::Mlb_lead_bdiscr() {
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

const float &CMS3::Mlb_closestb_jup() {
  if (not Mlb_closestb_jup_isLoaded) {
    if (Mlb_closestb_jup_branch != 0) {
      Mlb_closestb_jup_branch->GetEntry(index);
    } else {
      printf("branch Mlb_closestb_jup_branch does not exist!\n");
      exit(1);
    }
    Mlb_closestb_jup_isLoaded = true;
  }
  return Mlb_closestb_jup_;
}

const float &CMS3::Mlb_lead_bdiscr_jup() {
  if (not Mlb_lead_bdiscr_jup_isLoaded) {
    if (Mlb_lead_bdiscr_jup_branch != 0) {
      Mlb_lead_bdiscr_jup_branch->GetEntry(index);
    } else {
      printf("branch Mlb_lead_bdiscr_jup_branch does not exist!\n");
      exit(1);
    }
    Mlb_lead_bdiscr_jup_isLoaded = true;
  }
  return Mlb_lead_bdiscr_jup_;
}

const float &CMS3::Mlb_closestb_jdown() {
  if (not Mlb_closestb_jdown_isLoaded) {
    if (Mlb_closestb_jdown_branch != 0) {
      Mlb_closestb_jdown_branch->GetEntry(index);
    } else {
      printf("branch Mlb_closestb_jdown_branch does not exist!\n");
      exit(1);
    }
    Mlb_closestb_jdown_isLoaded = true;
  }
  return Mlb_closestb_jdown_;
}

const float &CMS3::Mlb_lead_bdiscr_jdown() {
  if (not Mlb_lead_bdiscr_jdown_isLoaded) {
    if (Mlb_lead_bdiscr_jdown_branch != 0) {
      Mlb_lead_bdiscr_jdown_branch->GetEntry(index);
    } else {
      printf("branch Mlb_lead_bdiscr_jdown_branch does not exist!\n");
      exit(1);
    }
    Mlb_lead_bdiscr_jdown_isLoaded = true;
  }
  return Mlb_lead_bdiscr_jdown_;
}

const int &CMS3::HLT_SingleEl() {
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

const int &CMS3::HLT_SingleMu() {
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

const int &CMS3::HLT_MET() {
  if (not HLT_MET_isLoaded) {
    if (HLT_MET_branch != 0) {
      HLT_MET_branch->GetEntry(index);
    } else {
      printf("branch HLT_MET_branch does not exist!\n");
      exit(1);
    }
    HLT_MET_isLoaded = true;
  }
  return HLT_MET_;
}

const int &CMS3::HLT_MET_MHT() {
  if (not HLT_MET_MHT_isLoaded) {
    if (HLT_MET_MHT_branch != 0) {
      HLT_MET_MHT_branch->GetEntry(index);
    } else {
      printf("branch HLT_MET_MHT_branch does not exist!\n");
      exit(1);
    }
    HLT_MET_MHT_isLoaded = true;
  }
  return HLT_MET_MHT_;
}

const int &CMS3::HLT_MET100_MHT100() {
  if (not HLT_MET100_MHT100_isLoaded) {
    if (HLT_MET100_MHT100_branch != 0) {
      HLT_MET100_MHT100_branch->GetEntry(index);
    } else {
      printf("branch HLT_MET100_MHT100_branch does not exist!\n");
      exit(1);
    }
    HLT_MET100_MHT100_isLoaded = true;
  }
  return HLT_MET100_MHT100_;
}

const int &CMS3::HLT_MET110_MHT110() {
  if (not HLT_MET110_MHT110_isLoaded) {
    if (HLT_MET110_MHT110_branch != 0) {
      HLT_MET110_MHT110_branch->GetEntry(index);
    } else {
      printf("branch HLT_MET110_MHT110_branch does not exist!\n");
      exit(1);
    }
    HLT_MET110_MHT110_isLoaded = true;
  }
  return HLT_MET110_MHT110_;
}

const int &CMS3::HLT_MET120_MHT120() {
  if (not HLT_MET120_MHT120_isLoaded) {
    if (HLT_MET120_MHT120_branch != 0) {
      HLT_MET120_MHT120_branch->GetEntry(index);
    } else {
      printf("branch HLT_MET120_MHT120_branch does not exist!\n");
      exit(1);
    }
    HLT_MET120_MHT120_isLoaded = true;
  }
  return HLT_MET120_MHT120_;
}

const int &CMS3::HLT_PFHT_unprescaled() {
  if (not HLT_PFHT_unprescaled_isLoaded) {
    if (HLT_PFHT_unprescaled_branch != 0) {
      HLT_PFHT_unprescaled_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT_unprescaled_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT_unprescaled_isLoaded = true;
  }
  return HLT_PFHT_unprescaled_;
}

const int &CMS3::HLT_PFHT_prescaled() {
  if (not HLT_PFHT_prescaled_isLoaded) {
    if (HLT_PFHT_prescaled_branch != 0) {
      HLT_PFHT_prescaled_branch->GetEntry(index);
    } else {
      printf("branch HLT_PFHT_prescaled_branch does not exist!\n");
      exit(1);
    }
    HLT_PFHT_prescaled_isLoaded = true;
  }
  return HLT_PFHT_prescaled_;
}

const int &CMS3::HLT_DiEl() {
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

const int &CMS3::HLT_DiMu() {
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

const int &CMS3::HLT_MuE() {
  if (not HLT_MuE_isLoaded) {
    if (HLT_MuE_branch != 0) {
      HLT_MuE_branch->GetEntry(index);
    } else {
      printf("branch HLT_MuE_branch does not exist!\n");
      exit(1);
    }
    HLT_MuE_isLoaded = true;
  }
  return HLT_MuE_;
}

const int &CMS3::nPhotons() {
  if (not nPhotons_isLoaded) {
    if (nPhotons_branch != 0) {
      nPhotons_branch->GetEntry(index);
    } else {
      printf("branch nPhotons_branch does not exist!\n");
      exit(1);
    }
    nPhotons_isLoaded = true;
  }
  return nPhotons_;
}

const int &CMS3::ph_ngoodjets() {
  if (not ph_ngoodjets_isLoaded) {
    if (ph_ngoodjets_branch != 0) {
      ph_ngoodjets_branch->GetEntry(index);
    } else {
      printf("branch ph_ngoodjets_branch does not exist!\n");
      exit(1);
    }
    ph_ngoodjets_isLoaded = true;
  }
  return ph_ngoodjets_;
}

const int &CMS3::ph_ngoodbtags() {
  if (not ph_ngoodbtags_isLoaded) {
    if (ph_ngoodbtags_branch != 0) {
      ph_ngoodbtags_branch->GetEntry(index);
    } else {
      printf("branch ph_ngoodbtags_branch does not exist!\n");
      exit(1);
    }
    ph_ngoodbtags_isLoaded = true;
  }
  return ph_ngoodbtags_;
}

const float &CMS3::hardgenpt() {
  if (not hardgenpt_isLoaded) {
    if (hardgenpt_branch != 0) {
      hardgenpt_branch->GetEntry(index);
    } else {
      printf("branch hardgenpt_branch does not exist!\n");
      exit(1);
    }
    hardgenpt_isLoaded = true;
  }
  return hardgenpt_;
}

const float &CMS3::calomet() {
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

const float &CMS3::calomet_phi() {
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

const int &CMS3::lep1_pdgid() {
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

const int &CMS3::lep1_production_type() {
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

const float &CMS3::lep1_MiniIso() {
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

const float &CMS3::lep1_relIso() {
  if (not lep1_relIso_isLoaded) {
    if (lep1_relIso_branch != 0) {
      lep1_relIso_branch->GetEntry(index);
    } else {
      printf("branch lep1_relIso_branch does not exist!\n");
      exit(1);
    }
    lep1_relIso_isLoaded = true;
  }
  return lep1_relIso_;
}

const bool &CMS3::lep1_passLooseID() {
  if (not lep1_passLooseID_isLoaded) {
    if (lep1_passLooseID_branch != 0) {
      lep1_passLooseID_branch->GetEntry(index);
    } else {
      printf("branch lep1_passLooseID_branch does not exist!\n");
      exit(1);
    }
    lep1_passLooseID_isLoaded = true;
  }
  return lep1_passLooseID_;
}

const bool &CMS3::lep1_passMediumID() {
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

const bool &CMS3::lep1_passTightID() {
  if (not lep1_passTightID_isLoaded) {
    if (lep1_passTightID_branch != 0) {
      lep1_passTightID_branch->GetEntry(index);
    } else {
      printf("branch lep1_passTightID_branch does not exist!\n");
      exit(1);
    }
    lep1_passTightID_isLoaded = true;
  }
  return lep1_passTightID_;
}

const bool &CMS3::lep1_passVeto() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep1_p4() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep1_mcp4() {
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

const int &CMS3::lep1_mc_motherid() {
  if (not lep1_mc_motherid_isLoaded) {
    if (lep1_mc_motherid_branch != 0) {
      lep1_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch lep1_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    lep1_mc_motherid_isLoaded = true;
  }
  return lep1_mc_motherid_;
}

const float &CMS3::lep1_dphiMET() {
  if (not lep1_dphiMET_isLoaded) {
    if (lep1_dphiMET_branch != 0) {
      lep1_dphiMET_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_isLoaded = true;
  }
  return lep1_dphiMET_;
}

const float &CMS3::lep1_dphiMET_jup() {
  if (not lep1_dphiMET_jup_isLoaded) {
    if (lep1_dphiMET_jup_branch != 0) {
      lep1_dphiMET_jup_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_jup_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_jup_isLoaded = true;
  }
  return lep1_dphiMET_jup_;
}

const float &CMS3::lep1_dphiMET_jdown() {
  if (not lep1_dphiMET_jdown_isLoaded) {
    if (lep1_dphiMET_jdown_branch != 0) {
      lep1_dphiMET_jdown_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_jdown_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_jdown_isLoaded = true;
  }
  return lep1_dphiMET_jdown_;
}

const float &CMS3::lep1_dphiMET_rl() {
  if (not lep1_dphiMET_rl_isLoaded) {
    if (lep1_dphiMET_rl_branch != 0) {
      lep1_dphiMET_rl_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_rl_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_rl_isLoaded = true;
  }
  return lep1_dphiMET_rl_;
}

const float &CMS3::lep1_dphiMET_rl_jup() {
  if (not lep1_dphiMET_rl_jup_isLoaded) {
    if (lep1_dphiMET_rl_jup_branch != 0) {
      lep1_dphiMET_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_rl_jup_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_rl_jup_isLoaded = true;
  }
  return lep1_dphiMET_rl_jup_;
}

const float &CMS3::lep1_dphiMET_rl_jdown() {
  if (not lep1_dphiMET_rl_jdown_isLoaded) {
    if (lep1_dphiMET_rl_jdown_branch != 0) {
      lep1_dphiMET_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch lep1_dphiMET_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    lep1_dphiMET_rl_jdown_isLoaded = true;
  }
  return lep1_dphiMET_rl_jdown_;
}

const int &CMS3::lep2_pdgid() {
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

const int &CMS3::lep2_production_type() {
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

const float &CMS3::lep2_MiniIso() {
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

const float &CMS3::lep2_relIso() {
  if (not lep2_relIso_isLoaded) {
    if (lep2_relIso_branch != 0) {
      lep2_relIso_branch->GetEntry(index);
    } else {
      printf("branch lep2_relIso_branch does not exist!\n");
      exit(1);
    }
    lep2_relIso_isLoaded = true;
  }
  return lep2_relIso_;
}

const bool &CMS3::lep2_passLooseID() {
  if (not lep2_passLooseID_isLoaded) {
    if (lep2_passLooseID_branch != 0) {
      lep2_passLooseID_branch->GetEntry(index);
    } else {
      printf("branch lep2_passLooseID_branch does not exist!\n");
      exit(1);
    }
    lep2_passLooseID_isLoaded = true;
  }
  return lep2_passLooseID_;
}

const bool &CMS3::lep2_passMediumID() {
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

const bool &CMS3::lep2_passTightID() {
  if (not lep2_passTightID_isLoaded) {
    if (lep2_passTightID_branch != 0) {
      lep2_passTightID_branch->GetEntry(index);
    } else {
      printf("branch lep2_passTightID_branch does not exist!\n");
      exit(1);
    }
    lep2_passTightID_isLoaded = true;
  }
  return lep2_passTightID_;
}

const bool &CMS3::lep2_passVeto() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep2_p4() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep2_mcp4() {
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

const int &CMS3::lep2_mc_motherid() {
  if (not lep2_mc_motherid_isLoaded) {
    if (lep2_mc_motherid_branch != 0) {
      lep2_mc_motherid_branch->GetEntry(index);
    } else {
      printf("branch lep2_mc_motherid_branch does not exist!\n");
      exit(1);
    }
    lep2_mc_motherid_isLoaded = true;
  }
  return lep2_mc_motherid_;
}

const float &CMS3::lep2_dphiMET() {
  if (not lep2_dphiMET_isLoaded) {
    if (lep2_dphiMET_branch != 0) {
      lep2_dphiMET_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_isLoaded = true;
  }
  return lep2_dphiMET_;
}

const float &CMS3::lep2_dphiMET_jup() {
  if (not lep2_dphiMET_jup_isLoaded) {
    if (lep2_dphiMET_jup_branch != 0) {
      lep2_dphiMET_jup_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_jup_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_jup_isLoaded = true;
  }
  return lep2_dphiMET_jup_;
}

const float &CMS3::lep2_dphiMET_jdown() {
  if (not lep2_dphiMET_jdown_isLoaded) {
    if (lep2_dphiMET_jdown_branch != 0) {
      lep2_dphiMET_jdown_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_jdown_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_jdown_isLoaded = true;
  }
  return lep2_dphiMET_jdown_;
}

const float &CMS3::lep2_dphiMET_rl() {
  if (not lep2_dphiMET_rl_isLoaded) {
    if (lep2_dphiMET_rl_branch != 0) {
      lep2_dphiMET_rl_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_rl_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_rl_isLoaded = true;
  }
  return lep2_dphiMET_rl_;
}

const float &CMS3::lep2_dphiMET_rl_jup() {
  if (not lep2_dphiMET_rl_jup_isLoaded) {
    if (lep2_dphiMET_rl_jup_branch != 0) {
      lep2_dphiMET_rl_jup_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_rl_jup_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_rl_jup_isLoaded = true;
  }
  return lep2_dphiMET_rl_jup_;
}

const float &CMS3::lep2_dphiMET_rl_jdown() {
  if (not lep2_dphiMET_rl_jdown_isLoaded) {
    if (lep2_dphiMET_rl_jdown_branch != 0) {
      lep2_dphiMET_rl_jdown_branch->GetEntry(index);
    } else {
      printf("branch lep2_dphiMET_rl_jdown_branch does not exist!\n");
      exit(1);
    }
    lep2_dphiMET_rl_jdown_isLoaded = true;
  }
  return lep2_dphiMET_rl_jdown_;
}

const vector<float> &CMS3::ph_sigmaIEtaEta_fill5x5() {
  if (not ph_sigmaIEtaEta_fill5x5_isLoaded) {
    if (ph_sigmaIEtaEta_fill5x5_branch != 0) {
      ph_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
    } else {
      printf("branch ph_sigmaIEtaEta_fill5x5_branch does not exist!\n");
      exit(1);
    }
    ph_sigmaIEtaEta_fill5x5_isLoaded = true;
  }
  return *ph_sigmaIEtaEta_fill5x5_;
}

const vector<float> &CMS3::ph_hOverE() {
  if (not ph_hOverE_isLoaded) {
    if (ph_hOverE_branch != 0) {
      ph_hOverE_branch->GetEntry(index);
    } else {
      printf("branch ph_hOverE_branch does not exist!\n");
      exit(1);
    }
    ph_hOverE_isLoaded = true;
  }
  return *ph_hOverE_;
}

const vector<float> &CMS3::ph_r9() {
  if (not ph_r9_isLoaded) {
    if (ph_r9_branch != 0) {
      ph_r9_branch->GetEntry(index);
    } else {
      printf("branch ph_r9_branch does not exist!\n");
      exit(1);
    }
    ph_r9_isLoaded = true;
  }
  return *ph_r9_;
}

const vector<float> &CMS3::ph_chiso() {
  if (not ph_chiso_isLoaded) {
    if (ph_chiso_branch != 0) {
      ph_chiso_branch->GetEntry(index);
    } else {
      printf("branch ph_chiso_branch does not exist!\n");
      exit(1);
    }
    ph_chiso_isLoaded = true;
  }
  return *ph_chiso_;
}

const vector<float> &CMS3::ph_nhiso() {
  if (not ph_nhiso_isLoaded) {
    if (ph_nhiso_branch != 0) {
      ph_nhiso_branch->GetEntry(index);
    } else {
      printf("branch ph_nhiso_branch does not exist!\n");
      exit(1);
    }
    ph_nhiso_isLoaded = true;
  }
  return *ph_nhiso_;
}

const vector<float> &CMS3::ph_phiso() {
  if (not ph_phiso_isLoaded) {
    if (ph_phiso_branch != 0) {
      ph_phiso_branch->GetEntry(index);
    } else {
      printf("branch ph_phiso_branch does not exist!\n");
      exit(1);
    }
    ph_phiso_isLoaded = true;
  }
  return *ph_phiso_;
}

const vector<int> &CMS3::ph_overlapJetId() {
  if (not ph_overlapJetId_isLoaded) {
    if (ph_overlapJetId_branch != 0) {
      ph_overlapJetId_branch->GetEntry(index);
    } else {
      printf("branch ph_overlapJetId_branch does not exist!\n");
      exit(1);
    }
    ph_overlapJetId_isLoaded = true;
  }
  return *ph_overlapJetId_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ph_p4() {
  if (not ph_p4_isLoaded) {
    if (ph_p4_branch != 0) {
      ph_p4_branch->GetEntry(index);
    } else {
      printf("branch ph_p4_branch does not exist!\n");
      exit(1);
    }
    ph_p4_isLoaded = true;
  }
  return *ph_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ph_mcp4() {
  if (not ph_mcp4_isLoaded) {
    if (ph_mcp4_branch != 0) {
      ph_mcp4_branch->GetEntry(index);
    } else {
      printf("branch ph_mcp4_branch does not exist!\n");
      exit(1);
    }
    ph_mcp4_isLoaded = true;
  }
  return *ph_mcp4_;
}

const vector<float> &CMS3::ph_pt() {
  if (not ph_pt_isLoaded) {
    if (ph_pt_branch != 0) {
      ph_pt_branch->GetEntry(index);
    } else {
      printf("branch ph_pt_branch does not exist!\n");
      exit(1);
    }
    ph_pt_isLoaded = true;
  }
  return *ph_pt_;
}

const vector<float> &CMS3::ph_eta() {
  if (not ph_eta_isLoaded) {
    if (ph_eta_branch != 0) {
      ph_eta_branch->GetEntry(index);
    } else {
      printf("branch ph_eta_branch does not exist!\n");
      exit(1);
    }
    ph_eta_isLoaded = true;
  }
  return *ph_eta_;
}

const vector<float> &CMS3::ph_phi() {
  if (not ph_phi_isLoaded) {
    if (ph_phi_branch != 0) {
      ph_phi_branch->GetEntry(index);
    } else {
      printf("branch ph_phi_branch does not exist!\n");
      exit(1);
    }
    ph_phi_isLoaded = true;
  }
  return *ph_phi_;
}

const vector<float> &CMS3::ph_mass() {
  if (not ph_mass_isLoaded) {
    if (ph_mass_branch != 0) {
      ph_mass_branch->GetEntry(index);
    } else {
      printf("branch ph_mass_branch does not exist!\n");
      exit(1);
    }
    ph_mass_isLoaded = true;
  }
  return *ph_mass_;
}

const vector<int> &CMS3::ph_mcMatchId() {
  if (not ph_mcMatchId_isLoaded) {
    if (ph_mcMatchId_branch != 0) {
      ph_mcMatchId_branch->GetEntry(index);
    } else {
      printf("branch ph_mcMatchId_branch does not exist!\n");
      exit(1);
    }
    ph_mcMatchId_isLoaded = true;
  }
  return *ph_mcMatchId_;
}

const vector<float> &CMS3::ph_genIso04() {
  if (not ph_genIso04_isLoaded) {
    if (ph_genIso04_branch != 0) {
      ph_genIso04_branch->GetEntry(index);
    } else {
      printf("branch ph_genIso04_branch does not exist!\n");
      exit(1);
    }
    ph_genIso04_isLoaded = true;
  }
  return *ph_genIso04_;
}

const vector<float> &CMS3::ph_drMinParton() {
  if (not ph_drMinParton_isLoaded) {
    if (ph_drMinParton_branch != 0) {
      ph_drMinParton_branch->GetEntry(index);
    } else {
      printf("branch ph_drMinParton_branch does not exist!\n");
      exit(1);
    }
    ph_drMinParton_isLoaded = true;
  }
  return *ph_drMinParton_;
}

const int &CMS3::ngoodjets() {
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

const int &CMS3::ngoodbtags() {
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

const int &CMS3::nloosebtags() {
  if (not nloosebtags_isLoaded) {
    if (nloosebtags_branch != 0) {
      nloosebtags_branch->GetEntry(index);
    } else {
      printf("branch nloosebtags_branch does not exist!\n");
      exit(1);
    }
    nloosebtags_isLoaded = true;
  }
  return nloosebtags_;
}

const int &CMS3::ntightbtags() {
  if (not ntightbtags_isLoaded) {
    if (ntightbtags_branch != 0) {
      ntightbtags_branch->GetEntry(index);
    } else {
      printf("branch ntightbtags_branch does not exist!\n");
      exit(1);
    }
    ntightbtags_isLoaded = true;
  }
  return ntightbtags_;
}

const int &CMS3::nanalysisbtags() {
  if (not nanalysisbtags_isLoaded) {
    if (nanalysisbtags_branch != 0) {
      nanalysisbtags_branch->GetEntry(index);
    } else {
      printf("branch nanalysisbtags_branch does not exist!\n");
      exit(1);
    }
    nanalysisbtags_isLoaded = true;
  }
  return nanalysisbtags_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::softtags_p4() {
  if (not softtags_p4_isLoaded) {
    if (softtags_p4_branch != 0) {
      softtags_p4_branch->GetEntry(index);
    } else {
      printf("branch softtags_p4_branch does not exist!\n");
      exit(1);
    }
    softtags_p4_isLoaded = true;
  }
  return *softtags_p4_;
}

const int &CMS3::nsoftbtags() {
  if (not nsoftbtags_isLoaded) {
    if (nsoftbtags_branch != 0) {
      nsoftbtags_branch->GetEntry(index);
    } else {
      printf("branch nsoftbtags_branch does not exist!\n");
      exit(1);
    }
    nsoftbtags_isLoaded = true;
  }
  return nsoftbtags_;
}

const float &CMS3::ak4_HT() {
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

const float &CMS3::ak4_htratiom() {
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

const vector<float> &CMS3::dphi_ak4pfjet_met() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak4pfjets_p4() {
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

const vector<bool> &CMS3::ak4pfjets_passMEDbtag() {
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

const vector<float> &CMS3::ak4pfjets_CSV() {
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

const vector<float> &CMS3::ak4pfjets_mva() {
  if (not ak4pfjets_mva_isLoaded) {
    if (ak4pfjets_mva_branch != 0) {
      ak4pfjets_mva_branch->GetEntry(index);
    } else {
      printf("branch ak4pfjets_mva_branch does not exist!\n");
      exit(1);
    }
    ak4pfjets_mva_isLoaded = true;
  }
  return *ak4pfjets_mva_;
}

const vector<int> &CMS3::ak4pfjets_parton_flavor() {
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

const vector<int> &CMS3::ak4pfjets_hadron_flavor() {
  if (not ak4pfjets_hadron_flavor_isLoaded) {
    if (ak4pfjets_hadron_flavor_branch != 0) {
      ak4pfjets_hadron_flavor_branch->GetEntry(index);
    } else {
      printf("branch ak4pfjets_hadron_flavor_branch does not exist!\n");
      exit(1);
    }
    ak4pfjets_hadron_flavor_isLoaded = true;
  }
  return *ak4pfjets_hadron_flavor_;
}

const vector<bool> &CMS3::ak4pfjets_loose_puid() {
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

const vector<bool> &CMS3::ak4pfjets_loose_pfid() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjets_leadMEDbjet_p4() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjets_leadbtag_p4() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak4genjets_p4() {
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

const int &CMS3::jup_ngoodjets() {
  if (not jup_ngoodjets_isLoaded) {
    if (jup_ngoodjets_branch != 0) {
      jup_ngoodjets_branch->GetEntry(index);
    } else {
      printf("branch jup_ngoodjets_branch does not exist!\n");
      exit(1);
    }
    jup_ngoodjets_isLoaded = true;
  }
  return jup_ngoodjets_;
}

const int &CMS3::jup_ngoodbtags() {
  if (not jup_ngoodbtags_isLoaded) {
    if (jup_ngoodbtags_branch != 0) {
      jup_ngoodbtags_branch->GetEntry(index);
    } else {
      printf("branch jup_ngoodbtags_branch does not exist!\n");
      exit(1);
    }
    jup_ngoodbtags_isLoaded = true;
  }
  return jup_ngoodbtags_;
}

const int &CMS3::jup_nloosebtags() {
  if (not jup_nloosebtags_isLoaded) {
    if (jup_nloosebtags_branch != 0) {
      jup_nloosebtags_branch->GetEntry(index);
    } else {
      printf("branch jup_nloosebtags_branch does not exist!\n");
      exit(1);
    }
    jup_nloosebtags_isLoaded = true;
  }
  return jup_nloosebtags_;
}

const int &CMS3::jup_ntightbtags() {
  if (not jup_ntightbtags_isLoaded) {
    if (jup_ntightbtags_branch != 0) {
      jup_ntightbtags_branch->GetEntry(index);
    } else {
      printf("branch jup_ntightbtags_branch does not exist!\n");
      exit(1);
    }
    jup_ntightbtags_isLoaded = true;
  }
  return jup_ntightbtags_;
}

const int &CMS3::jup_nanalysisbtags() {
  if (not jup_nanalysisbtags_isLoaded) {
    if (jup_nanalysisbtags_branch != 0) {
      jup_nanalysisbtags_branch->GetEntry(index);
    } else {
      printf("branch jup_nanalysisbtags_branch does not exist!\n");
      exit(1);
    }
    jup_nanalysisbtags_isLoaded = true;
  }
  return jup_nanalysisbtags_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jup_softtags_p4() {
  if (not jup_softtags_p4_isLoaded) {
    if (jup_softtags_p4_branch != 0) {
      jup_softtags_p4_branch->GetEntry(index);
    } else {
      printf("branch jup_softtags_p4_branch does not exist!\n");
      exit(1);
    }
    jup_softtags_p4_isLoaded = true;
  }
  return *jup_softtags_p4_;
}

const int &CMS3::jup_nsoftbtags() {
  if (not jup_nsoftbtags_isLoaded) {
    if (jup_nsoftbtags_branch != 0) {
      jup_nsoftbtags_branch->GetEntry(index);
    } else {
      printf("branch jup_nsoftbtags_branch does not exist!\n");
      exit(1);
    }
    jup_nsoftbtags_isLoaded = true;
  }
  return jup_nsoftbtags_;
}

const float &CMS3::jup_ak4_HT() {
  if (not jup_ak4_HT_isLoaded) {
    if (jup_ak4_HT_branch != 0) {
      jup_ak4_HT_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4_HT_branch does not exist!\n");
      exit(1);
    }
    jup_ak4_HT_isLoaded = true;
  }
  return jup_ak4_HT_;
}

const float &CMS3::jup_ak4_htratiom() {
  if (not jup_ak4_htratiom_isLoaded) {
    if (jup_ak4_htratiom_branch != 0) {
      jup_ak4_htratiom_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4_htratiom_branch does not exist!\n");
      exit(1);
    }
    jup_ak4_htratiom_isLoaded = true;
  }
  return jup_ak4_htratiom_;
}

const vector<float> &CMS3::jup_dphi_ak4pfjet_met() {
  if (not jup_dphi_ak4pfjet_met_isLoaded) {
    if (jup_dphi_ak4pfjet_met_branch != 0) {
      jup_dphi_ak4pfjet_met_branch->GetEntry(index);
    } else {
      printf("branch jup_dphi_ak4pfjet_met_branch does not exist!\n");
      exit(1);
    }
    jup_dphi_ak4pfjet_met_isLoaded = true;
  }
  return *jup_dphi_ak4pfjet_met_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jup_ak4pfjets_p4() {
  if (not jup_ak4pfjets_p4_isLoaded) {
    if (jup_ak4pfjets_p4_branch != 0) {
      jup_ak4pfjets_p4_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_p4_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_p4_isLoaded = true;
  }
  return *jup_ak4pfjets_p4_;
}

const vector<bool> &CMS3::jup_ak4pfjets_passMEDbtag() {
  if (not jup_ak4pfjets_passMEDbtag_isLoaded) {
    if (jup_ak4pfjets_passMEDbtag_branch != 0) {
      jup_ak4pfjets_passMEDbtag_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_passMEDbtag_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_passMEDbtag_isLoaded = true;
  }
  return *jup_ak4pfjets_passMEDbtag_;
}

const vector<float> &CMS3::jup_ak4pfjets_CSV() {
  if (not jup_ak4pfjets_CSV_isLoaded) {
    if (jup_ak4pfjets_CSV_branch != 0) {
      jup_ak4pfjets_CSV_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_CSV_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_CSV_isLoaded = true;
  }
  return *jup_ak4pfjets_CSV_;
}

const vector<float> &CMS3::jup_ak4pfjets_mva() {
  if (not jup_ak4pfjets_mva_isLoaded) {
    if (jup_ak4pfjets_mva_branch != 0) {
      jup_ak4pfjets_mva_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_mva_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_mva_isLoaded = true;
  }
  return *jup_ak4pfjets_mva_;
}

const vector<int> &CMS3::jup_ak4pfjets_parton_flavor() {
  if (not jup_ak4pfjets_parton_flavor_isLoaded) {
    if (jup_ak4pfjets_parton_flavor_branch != 0) {
      jup_ak4pfjets_parton_flavor_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_parton_flavor_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_parton_flavor_isLoaded = true;
  }
  return *jup_ak4pfjets_parton_flavor_;
}

const vector<int> &CMS3::jup_ak4pfjets_hadron_flavor() {
  if (not jup_ak4pfjets_hadron_flavor_isLoaded) {
    if (jup_ak4pfjets_hadron_flavor_branch != 0) {
      jup_ak4pfjets_hadron_flavor_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_hadron_flavor_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_hadron_flavor_isLoaded = true;
  }
  return *jup_ak4pfjets_hadron_flavor_;
}

const vector<bool> &CMS3::jup_ak4pfjets_loose_puid() {
  if (not jup_ak4pfjets_loose_puid_isLoaded) {
    if (jup_ak4pfjets_loose_puid_branch != 0) {
      jup_ak4pfjets_loose_puid_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_loose_puid_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_loose_puid_isLoaded = true;
  }
  return *jup_ak4pfjets_loose_puid_;
}

const vector<bool> &CMS3::jup_ak4pfjets_loose_pfid() {
  if (not jup_ak4pfjets_loose_pfid_isLoaded) {
    if (jup_ak4pfjets_loose_pfid_branch != 0) {
      jup_ak4pfjets_loose_pfid_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_loose_pfid_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_loose_pfid_isLoaded = true;
  }
  return *jup_ak4pfjets_loose_pfid_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::jup_ak4pfjets_leadMEDbjet_p4() {
  if (not jup_ak4pfjets_leadMEDbjet_p4_isLoaded) {
    if (jup_ak4pfjets_leadMEDbjet_p4_branch != 0) {
      jup_ak4pfjets_leadMEDbjet_p4_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_leadMEDbjet_p4_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_leadMEDbjet_p4_isLoaded = true;
  }
  return *jup_ak4pfjets_leadMEDbjet_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::jup_ak4pfjets_leadbtag_p4() {
  if (not jup_ak4pfjets_leadbtag_p4_isLoaded) {
    if (jup_ak4pfjets_leadbtag_p4_branch != 0) {
      jup_ak4pfjets_leadbtag_p4_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4pfjets_leadbtag_p4_branch does not exist!\n");
      exit(1);
    }
    jup_ak4pfjets_leadbtag_p4_isLoaded = true;
  }
  return *jup_ak4pfjets_leadbtag_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jup_ak4genjets_p4() {
  if (not jup_ak4genjets_p4_isLoaded) {
    if (jup_ak4genjets_p4_branch != 0) {
      jup_ak4genjets_p4_branch->GetEntry(index);
    } else {
      printf("branch jup_ak4genjets_p4_branch does not exist!\n");
      exit(1);
    }
    jup_ak4genjets_p4_isLoaded = true;
  }
  return *jup_ak4genjets_p4_;
}

const int &CMS3::jdown_ngoodjets() {
  if (not jdown_ngoodjets_isLoaded) {
    if (jdown_ngoodjets_branch != 0) {
      jdown_ngoodjets_branch->GetEntry(index);
    } else {
      printf("branch jdown_ngoodjets_branch does not exist!\n");
      exit(1);
    }
    jdown_ngoodjets_isLoaded = true;
  }
  return jdown_ngoodjets_;
}

const int &CMS3::jdown_ngoodbtags() {
  if (not jdown_ngoodbtags_isLoaded) {
    if (jdown_ngoodbtags_branch != 0) {
      jdown_ngoodbtags_branch->GetEntry(index);
    } else {
      printf("branch jdown_ngoodbtags_branch does not exist!\n");
      exit(1);
    }
    jdown_ngoodbtags_isLoaded = true;
  }
  return jdown_ngoodbtags_;
}

const int &CMS3::jdown_nloosebtags() {
  if (not jdown_nloosebtags_isLoaded) {
    if (jdown_nloosebtags_branch != 0) {
      jdown_nloosebtags_branch->GetEntry(index);
    } else {
      printf("branch jdown_nloosebtags_branch does not exist!\n");
      exit(1);
    }
    jdown_nloosebtags_isLoaded = true;
  }
  return jdown_nloosebtags_;
}

const int &CMS3::jdown_ntightbtags() {
  if (not jdown_ntightbtags_isLoaded) {
    if (jdown_ntightbtags_branch != 0) {
      jdown_ntightbtags_branch->GetEntry(index);
    } else {
      printf("branch jdown_ntightbtags_branch does not exist!\n");
      exit(1);
    }
    jdown_ntightbtags_isLoaded = true;
  }
  return jdown_ntightbtags_;
}

const int &CMS3::jdown_nanalysisbtags() {
  if (not jdown_nanalysisbtags_isLoaded) {
    if (jdown_nanalysisbtags_branch != 0) {
      jdown_nanalysisbtags_branch->GetEntry(index);
    } else {
      printf("branch jdown_nanalysisbtags_branch does not exist!\n");
      exit(1);
    }
    jdown_nanalysisbtags_isLoaded = true;
  }
  return jdown_nanalysisbtags_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jdown_softtags_p4() {
  if (not jdown_softtags_p4_isLoaded) {
    if (jdown_softtags_p4_branch != 0) {
      jdown_softtags_p4_branch->GetEntry(index);
    } else {
      printf("branch jdown_softtags_p4_branch does not exist!\n");
      exit(1);
    }
    jdown_softtags_p4_isLoaded = true;
  }
  return *jdown_softtags_p4_;
}

const int &CMS3::jdown_nsoftbtags() {
  if (not jdown_nsoftbtags_isLoaded) {
    if (jdown_nsoftbtags_branch != 0) {
      jdown_nsoftbtags_branch->GetEntry(index);
    } else {
      printf("branch jdown_nsoftbtags_branch does not exist!\n");
      exit(1);
    }
    jdown_nsoftbtags_isLoaded = true;
  }
  return jdown_nsoftbtags_;
}

const float &CMS3::jdown_ak4_HT() {
  if (not jdown_ak4_HT_isLoaded) {
    if (jdown_ak4_HT_branch != 0) {
      jdown_ak4_HT_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4_HT_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4_HT_isLoaded = true;
  }
  return jdown_ak4_HT_;
}

const float &CMS3::jdown_ak4_htratiom() {
  if (not jdown_ak4_htratiom_isLoaded) {
    if (jdown_ak4_htratiom_branch != 0) {
      jdown_ak4_htratiom_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4_htratiom_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4_htratiom_isLoaded = true;
  }
  return jdown_ak4_htratiom_;
}

const vector<float> &CMS3::jdown_dphi_ak4pfjet_met() {
  if (not jdown_dphi_ak4pfjet_met_isLoaded) {
    if (jdown_dphi_ak4pfjet_met_branch != 0) {
      jdown_dphi_ak4pfjet_met_branch->GetEntry(index);
    } else {
      printf("branch jdown_dphi_ak4pfjet_met_branch does not exist!\n");
      exit(1);
    }
    jdown_dphi_ak4pfjet_met_isLoaded = true;
  }
  return *jdown_dphi_ak4pfjet_met_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jdown_ak4pfjets_p4() {
  if (not jdown_ak4pfjets_p4_isLoaded) {
    if (jdown_ak4pfjets_p4_branch != 0) {
      jdown_ak4pfjets_p4_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_p4_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_p4_isLoaded = true;
  }
  return *jdown_ak4pfjets_p4_;
}

const vector<bool> &CMS3::jdown_ak4pfjets_passMEDbtag() {
  if (not jdown_ak4pfjets_passMEDbtag_isLoaded) {
    if (jdown_ak4pfjets_passMEDbtag_branch != 0) {
      jdown_ak4pfjets_passMEDbtag_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_passMEDbtag_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_passMEDbtag_isLoaded = true;
  }
  return *jdown_ak4pfjets_passMEDbtag_;
}

const vector<float> &CMS3::jdown_ak4pfjets_CSV() {
  if (not jdown_ak4pfjets_CSV_isLoaded) {
    if (jdown_ak4pfjets_CSV_branch != 0) {
      jdown_ak4pfjets_CSV_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_CSV_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_CSV_isLoaded = true;
  }
  return *jdown_ak4pfjets_CSV_;
}

const vector<float> &CMS3::jdown_ak4pfjets_mva() {
  if (not jdown_ak4pfjets_mva_isLoaded) {
    if (jdown_ak4pfjets_mva_branch != 0) {
      jdown_ak4pfjets_mva_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_mva_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_mva_isLoaded = true;
  }
  return *jdown_ak4pfjets_mva_;
}

const vector<int> &CMS3::jdown_ak4pfjets_parton_flavor() {
  if (not jdown_ak4pfjets_parton_flavor_isLoaded) {
    if (jdown_ak4pfjets_parton_flavor_branch != 0) {
      jdown_ak4pfjets_parton_flavor_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_parton_flavor_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_parton_flavor_isLoaded = true;
  }
  return *jdown_ak4pfjets_parton_flavor_;
}

const vector<int> &CMS3::jdown_ak4pfjets_hadron_flavor() {
  if (not jdown_ak4pfjets_hadron_flavor_isLoaded) {
    if (jdown_ak4pfjets_hadron_flavor_branch != 0) {
      jdown_ak4pfjets_hadron_flavor_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_hadron_flavor_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_hadron_flavor_isLoaded = true;
  }
  return *jdown_ak4pfjets_hadron_flavor_;
}

const vector<bool> &CMS3::jdown_ak4pfjets_loose_puid() {
  if (not jdown_ak4pfjets_loose_puid_isLoaded) {
    if (jdown_ak4pfjets_loose_puid_branch != 0) {
      jdown_ak4pfjets_loose_puid_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_loose_puid_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_loose_puid_isLoaded = true;
  }
  return *jdown_ak4pfjets_loose_puid_;
}

const vector<bool> &CMS3::jdown_ak4pfjets_loose_pfid() {
  if (not jdown_ak4pfjets_loose_pfid_isLoaded) {
    if (jdown_ak4pfjets_loose_pfid_branch != 0) {
      jdown_ak4pfjets_loose_pfid_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_loose_pfid_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_loose_pfid_isLoaded = true;
  }
  return *jdown_ak4pfjets_loose_pfid_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::jdown_ak4pfjets_leadMEDbjet_p4() {
  if (not jdown_ak4pfjets_leadMEDbjet_p4_isLoaded) {
    if (jdown_ak4pfjets_leadMEDbjet_p4_branch != 0) {
      jdown_ak4pfjets_leadMEDbjet_p4_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_leadMEDbjet_p4_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_leadMEDbjet_p4_isLoaded = true;
  }
  return *jdown_ak4pfjets_leadMEDbjet_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::jdown_ak4pfjets_leadbtag_p4() {
  if (not jdown_ak4pfjets_leadbtag_p4_isLoaded) {
    if (jdown_ak4pfjets_leadbtag_p4_branch != 0) {
      jdown_ak4pfjets_leadbtag_p4_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4pfjets_leadbtag_p4_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4pfjets_leadbtag_p4_isLoaded = true;
  }
  return *jdown_ak4pfjets_leadbtag_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::jdown_ak4genjets_p4() {
  if (not jdown_ak4genjets_p4_isLoaded) {
    if (jdown_ak4genjets_p4_branch != 0) {
      jdown_ak4genjets_p4_branch->GetEntry(index);
    } else {
      printf("branch jdown_ak4genjets_p4_branch does not exist!\n");
      exit(1);
    }
    jdown_ak4genjets_p4_isLoaded = true;
  }
  return *jdown_ak4genjets_p4_;
}

const vector<bool> &CMS3::genleps_isfromt() {
  if (not genleps_isfromt_isLoaded) {
    if (genleps_isfromt_branch != 0) {
      genleps_isfromt_branch->GetEntry(index);
    } else {
      printf("branch genleps_isfromt_branch does not exist!\n");
      exit(1);
    }
    genleps_isfromt_isLoaded = true;
  }
  return *genleps_isfromt_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_p4() {
  if (not genleps_p4_isLoaded) {
    if (genleps_p4_branch != 0) {
      genleps_p4_branch->GetEntry(index);
    } else {
      printf("branch genleps_p4_branch does not exist!\n");
      exit(1);
    }
    genleps_p4_isLoaded = true;
  }
  return *genleps_p4_;
}

const vector<int> &CMS3::genleps_id() {
  if (not genleps_id_isLoaded) {
    if (genleps_id_branch != 0) {
      genleps_id_branch->GetEntry(index);
    } else {
      printf("branch genleps_id_branch does not exist!\n");
      exit(1);
    }
    genleps_id_isLoaded = true;
  }
  return *genleps_id_;
}

const vector<int> &CMS3::genleps__genpsidx() {
  if (not genleps__genpsidx_isLoaded) {
    if (genleps__genpsidx_branch != 0) {
      genleps__genpsidx_branch->GetEntry(index);
    } else {
      printf("branch genleps__genpsidx_branch does not exist!\n");
      exit(1);
    }
    genleps__genpsidx_isLoaded = true;
  }
  return *genleps__genpsidx_;
}

const vector<int> &CMS3::genleps_status() {
  if (not genleps_status_isLoaded) {
    if (genleps_status_branch != 0) {
      genleps_status_branch->GetEntry(index);
    } else {
      printf("branch genleps_status_branch does not exist!\n");
      exit(1);
    }
    genleps_status_isLoaded = true;
  }
  return *genleps_status_;
}

const vector<bool> &CMS3::genleps_fromHardProcessDecayed() {
  if (not genleps_fromHardProcessDecayed_isLoaded) {
    if (genleps_fromHardProcessDecayed_branch != 0) {
      genleps_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch genleps_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    genleps_fromHardProcessDecayed_isLoaded = true;
  }
  return *genleps_fromHardProcessDecayed_;
}

const vector<bool> &CMS3::genleps_fromHardProcessFinalState() {
  if (not genleps_fromHardProcessFinalState_isLoaded) {
    if (genleps_fromHardProcessFinalState_branch != 0) {
      genleps_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch genleps_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    genleps_fromHardProcessFinalState_isLoaded = true;
  }
  return *genleps_fromHardProcessFinalState_;
}

const vector<bool> &CMS3::genleps_isHardProcess() {
  if (not genleps_isHardProcess_isLoaded) {
    if (genleps_isHardProcess_branch != 0) {
      genleps_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch genleps_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    genleps_isHardProcess_isLoaded = true;
  }
  return *genleps_isHardProcess_;
}

const vector<bool> &CMS3::genleps_isLastCopy() {
  if (not genleps_isLastCopy_isLoaded) {
    if (genleps_isLastCopy_branch != 0) {
      genleps_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch genleps_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    genleps_isLastCopy_isLoaded = true;
  }
  return *genleps_isLastCopy_;
}

const vector<int> &CMS3::genleps_gentaudecay() {
  if (not genleps_gentaudecay_isLoaded) {
    if (genleps_gentaudecay_branch != 0) {
      genleps_gentaudecay_branch->GetEntry(index);
    } else {
      printf("branch genleps_gentaudecay_branch does not exist!\n");
      exit(1);
    }
    genleps_gentaudecay_isLoaded = true;
  }
  return *genleps_gentaudecay_;
}

const int &CMS3::gen_nfromtleps_() {
  if (not gen_nfromtleps__isLoaded) {
    if (gen_nfromtleps__branch != 0) {
      gen_nfromtleps__branch->GetEntry(index);
    } else {
      printf("branch gen_nfromtleps__branch does not exist!\n");
      exit(1);
    }
    gen_nfromtleps__isLoaded = true;
  }
  return gen_nfromtleps__;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_motherp4() {
  if (not genleps_motherp4_isLoaded) {
    if (genleps_motherp4_branch != 0) {
      genleps_motherp4_branch->GetEntry(index);
    } else {
      printf("branch genleps_motherp4_branch does not exist!\n");
      exit(1);
    }
    genleps_motherp4_isLoaded = true;
  }
  return *genleps_motherp4_;
}

const vector<int> &CMS3::genleps_motherid() {
  if (not genleps_motherid_isLoaded) {
    if (genleps_motherid_branch != 0) {
      genleps_motherid_branch->GetEntry(index);
    } else {
      printf("branch genleps_motherid_branch does not exist!\n");
      exit(1);
    }
    genleps_motherid_isLoaded = true;
  }
  return *genleps_motherid_;
}

const vector<int> &CMS3::genleps_motheridx() {
  if (not genleps_motheridx_isLoaded) {
    if (genleps_motheridx_branch != 0) {
      genleps_motheridx_branch->GetEntry(index);
    } else {
      printf("branch genleps_motheridx_branch does not exist!\n");
      exit(1);
    }
    genleps_motheridx_isLoaded = true;
  }
  return *genleps_motheridx_;
}

const vector<int> &CMS3::genleps_motherstatus() {
  if (not genleps_motherstatus_isLoaded) {
    if (genleps_motherstatus_branch != 0) {
      genleps_motherstatus_branch->GetEntry(index);
    } else {
      printf("branch genleps_motherstatus_branch does not exist!\n");
      exit(1);
    }
    genleps_motherstatus_isLoaded = true;
  }
  return *genleps_motherstatus_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_gmotherp4() {
  if (not genleps_gmotherp4_isLoaded) {
    if (genleps_gmotherp4_branch != 0) {
      genleps_gmotherp4_branch->GetEntry(index);
    } else {
      printf("branch genleps_gmotherp4_branch does not exist!\n");
      exit(1);
    }
    genleps_gmotherp4_isLoaded = true;
  }
  return *genleps_gmotherp4_;
}

const vector<int> &CMS3::genleps_gmotherid() {
  if (not genleps_gmotherid_isLoaded) {
    if (genleps_gmotherid_branch != 0) {
      genleps_gmotherid_branch->GetEntry(index);
    } else {
      printf("branch genleps_gmotherid_branch does not exist!\n");
      exit(1);
    }
    genleps_gmotherid_isLoaded = true;
  }
  return *genleps_gmotherid_;
}

const vector<int> &CMS3::genleps_gmotheridx() {
  if (not genleps_gmotheridx_isLoaded) {
    if (genleps_gmotheridx_branch != 0) {
      genleps_gmotheridx_branch->GetEntry(index);
    } else {
      printf("branch genleps_gmotheridx_branch does not exist!\n");
      exit(1);
    }
    genleps_gmotheridx_isLoaded = true;
  }
  return *genleps_gmotheridx_;
}

const vector<int> &CMS3::genleps_gmotherstatus() {
  if (not genleps_gmotherstatus_isLoaded) {
    if (genleps_gmotherstatus_branch != 0) {
      genleps_gmotherstatus_branch->GetEntry(index);
    } else {
      printf("branch genleps_gmotherstatus_branch does not exist!\n");
      exit(1);
    }
    genleps_gmotherstatus_isLoaded = true;
  }
  return *genleps_gmotherstatus_;
}

const vector<bool> &CMS3::gennus_isfromt() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_p4() {
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

const vector<int> &CMS3::gennus_id() {
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

const vector<int> &CMS3::gennus__genpsidx() {
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

const vector<int> &CMS3::gennus_status() {
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

const vector<bool> &CMS3::gennus_fromHardProcessDecayed() {
  if (not gennus_fromHardProcessDecayed_isLoaded) {
    if (gennus_fromHardProcessDecayed_branch != 0) {
      gennus_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch gennus_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    gennus_fromHardProcessDecayed_isLoaded = true;
  }
  return *gennus_fromHardProcessDecayed_;
}

const vector<bool> &CMS3::gennus_fromHardProcessFinalState() {
  if (not gennus_fromHardProcessFinalState_isLoaded) {
    if (gennus_fromHardProcessFinalState_branch != 0) {
      gennus_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch gennus_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    gennus_fromHardProcessFinalState_isLoaded = true;
  }
  return *gennus_fromHardProcessFinalState_;
}

const vector<bool> &CMS3::gennus_isHardProcess() {
  if (not gennus_isHardProcess_isLoaded) {
    if (gennus_isHardProcess_branch != 0) {
      gennus_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch gennus_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    gennus_isHardProcess_isLoaded = true;
  }
  return *gennus_isHardProcess_;
}

const vector<bool> &CMS3::gennus_isLastCopy() {
  if (not gennus_isLastCopy_isLoaded) {
    if (gennus_isLastCopy_branch != 0) {
      gennus_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch gennus_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    gennus_isLastCopy_isLoaded = true;
  }
  return *gennus_isLastCopy_;
}

const vector<int> &CMS3::gennus_gentaudecay() {
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

const int &CMS3::gen_nfromtnus_() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_motherp4() {
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

const vector<int> &CMS3::gennus_motherid() {
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

const vector<int> &CMS3::gennus_motheridx() {
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

const vector<int> &CMS3::gennus_motherstatus() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_gmotherp4() {
  if (not gennus_gmotherp4_isLoaded) {
    if (gennus_gmotherp4_branch != 0) {
      gennus_gmotherp4_branch->GetEntry(index);
    } else {
      printf("branch gennus_gmotherp4_branch does not exist!\n");
      exit(1);
    }
    gennus_gmotherp4_isLoaded = true;
  }
  return *gennus_gmotherp4_;
}

const vector<int> &CMS3::gennus_gmotherid() {
  if (not gennus_gmotherid_isLoaded) {
    if (gennus_gmotherid_branch != 0) {
      gennus_gmotherid_branch->GetEntry(index);
    } else {
      printf("branch gennus_gmotherid_branch does not exist!\n");
      exit(1);
    }
    gennus_gmotherid_isLoaded = true;
  }
  return *gennus_gmotherid_;
}

const vector<int> &CMS3::gennus_gmotheridx() {
  if (not gennus_gmotheridx_isLoaded) {
    if (gennus_gmotheridx_branch != 0) {
      gennus_gmotheridx_branch->GetEntry(index);
    } else {
      printf("branch gennus_gmotheridx_branch does not exist!\n");
      exit(1);
    }
    gennus_gmotheridx_isLoaded = true;
  }
  return *gennus_gmotheridx_;
}

const vector<int> &CMS3::gennus_gmotherstatus() {
  if (not gennus_gmotherstatus_isLoaded) {
    if (gennus_gmotherstatus_branch != 0) {
      gennus_gmotherstatus_branch->GetEntry(index);
    } else {
      printf("branch gennus_gmotherstatus_branch does not exist!\n");
      exit(1);
    }
    gennus_gmotherstatus_isLoaded = true;
  }
  return *gennus_gmotherstatus_;
}

const vector<bool> &CMS3::genqs_isfromt() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_p4() {
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

const vector<int> &CMS3::genqs_id() {
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

const vector<int> &CMS3::genqs__genpsidx() {
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

const vector<int> &CMS3::genqs_status() {
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

const vector<bool> &CMS3::genqs_fromHardProcessDecayed() {
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

const vector<bool> &CMS3::genqs_fromHardProcessFinalState() {
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

const vector<bool> &CMS3::genqs_isHardProcess() {
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

const vector<bool> &CMS3::genqs_isLastCopy() {
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

const vector<int> &CMS3::genqs_gentaudecay() {
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

const int &CMS3::gen_nfromtqs_() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_motherp4() {
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

const vector<int> &CMS3::genqs_motherid() {
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

const vector<int> &CMS3::genqs_motheridx() {
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

const vector<int> &CMS3::genqs_motherstatus() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_gmotherp4() {
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

const vector<int> &CMS3::genqs_gmotherid() {
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

const vector<int> &CMS3::genqs_gmotheridx() {
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

const vector<int> &CMS3::genqs_gmotherstatus() {
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

const vector<bool> &CMS3::genbosons_isfromt() {
  if (not genbosons_isfromt_isLoaded) {
    if (genbosons_isfromt_branch != 0) {
      genbosons_isfromt_branch->GetEntry(index);
    } else {
      printf("branch genbosons_isfromt_branch does not exist!\n");
      exit(1);
    }
    genbosons_isfromt_isLoaded = true;
  }
  return *genbosons_isfromt_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_p4() {
  if (not genbosons_p4_isLoaded) {
    if (genbosons_p4_branch != 0) {
      genbosons_p4_branch->GetEntry(index);
    } else {
      printf("branch genbosons_p4_branch does not exist!\n");
      exit(1);
    }
    genbosons_p4_isLoaded = true;
  }
  return *genbosons_p4_;
}

const vector<int> &CMS3::genbosons_id() {
  if (not genbosons_id_isLoaded) {
    if (genbosons_id_branch != 0) {
      genbosons_id_branch->GetEntry(index);
    } else {
      printf("branch genbosons_id_branch does not exist!\n");
      exit(1);
    }
    genbosons_id_isLoaded = true;
  }
  return *genbosons_id_;
}

const vector<int> &CMS3::genbosons__genpsidx() {
  if (not genbosons__genpsidx_isLoaded) {
    if (genbosons__genpsidx_branch != 0) {
      genbosons__genpsidx_branch->GetEntry(index);
    } else {
      printf("branch genbosons__genpsidx_branch does not exist!\n");
      exit(1);
    }
    genbosons__genpsidx_isLoaded = true;
  }
  return *genbosons__genpsidx_;
}

const vector<int> &CMS3::genbosons_status() {
  if (not genbosons_status_isLoaded) {
    if (genbosons_status_branch != 0) {
      genbosons_status_branch->GetEntry(index);
    } else {
      printf("branch genbosons_status_branch does not exist!\n");
      exit(1);
    }
    genbosons_status_isLoaded = true;
  }
  return *genbosons_status_;
}

const vector<bool> &CMS3::genbosons_fromHardProcessDecayed() {
  if (not genbosons_fromHardProcessDecayed_isLoaded) {
    if (genbosons_fromHardProcessDecayed_branch != 0) {
      genbosons_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch genbosons_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    genbosons_fromHardProcessDecayed_isLoaded = true;
  }
  return *genbosons_fromHardProcessDecayed_;
}

const vector<bool> &CMS3::genbosons_fromHardProcessFinalState() {
  if (not genbosons_fromHardProcessFinalState_isLoaded) {
    if (genbosons_fromHardProcessFinalState_branch != 0) {
      genbosons_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch genbosons_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    genbosons_fromHardProcessFinalState_isLoaded = true;
  }
  return *genbosons_fromHardProcessFinalState_;
}

const vector<bool> &CMS3::genbosons_isHardProcess() {
  if (not genbosons_isHardProcess_isLoaded) {
    if (genbosons_isHardProcess_branch != 0) {
      genbosons_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch genbosons_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    genbosons_isHardProcess_isLoaded = true;
  }
  return *genbosons_isHardProcess_;
}

const vector<bool> &CMS3::genbosons_isLastCopy() {
  if (not genbosons_isLastCopy_isLoaded) {
    if (genbosons_isLastCopy_branch != 0) {
      genbosons_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch genbosons_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    genbosons_isLastCopy_isLoaded = true;
  }
  return *genbosons_isLastCopy_;
}

const vector<int> &CMS3::genbosons_gentaudecay() {
  if (not genbosons_gentaudecay_isLoaded) {
    if (genbosons_gentaudecay_branch != 0) {
      genbosons_gentaudecay_branch->GetEntry(index);
    } else {
      printf("branch genbosons_gentaudecay_branch does not exist!\n");
      exit(1);
    }
    genbosons_gentaudecay_isLoaded = true;
  }
  return *genbosons_gentaudecay_;
}

const int &CMS3::gen_nfromtbosons_() {
  if (not gen_nfromtbosons__isLoaded) {
    if (gen_nfromtbosons__branch != 0) {
      gen_nfromtbosons__branch->GetEntry(index);
    } else {
      printf("branch gen_nfromtbosons__branch does not exist!\n");
      exit(1);
    }
    gen_nfromtbosons__isLoaded = true;
  }
  return gen_nfromtbosons__;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_motherp4() {
  if (not genbosons_motherp4_isLoaded) {
    if (genbosons_motherp4_branch != 0) {
      genbosons_motherp4_branch->GetEntry(index);
    } else {
      printf("branch genbosons_motherp4_branch does not exist!\n");
      exit(1);
    }
    genbosons_motherp4_isLoaded = true;
  }
  return *genbosons_motherp4_;
}

const vector<int> &CMS3::genbosons_motherid() {
  if (not genbosons_motherid_isLoaded) {
    if (genbosons_motherid_branch != 0) {
      genbosons_motherid_branch->GetEntry(index);
    } else {
      printf("branch genbosons_motherid_branch does not exist!\n");
      exit(1);
    }
    genbosons_motherid_isLoaded = true;
  }
  return *genbosons_motherid_;
}

const vector<int> &CMS3::genbosons_motheridx() {
  if (not genbosons_motheridx_isLoaded) {
    if (genbosons_motheridx_branch != 0) {
      genbosons_motheridx_branch->GetEntry(index);
    } else {
      printf("branch genbosons_motheridx_branch does not exist!\n");
      exit(1);
    }
    genbosons_motheridx_isLoaded = true;
  }
  return *genbosons_motheridx_;
}

const vector<int> &CMS3::genbosons_motherstatus() {
  if (not genbosons_motherstatus_isLoaded) {
    if (genbosons_motherstatus_branch != 0) {
      genbosons_motherstatus_branch->GetEntry(index);
    } else {
      printf("branch genbosons_motherstatus_branch does not exist!\n");
      exit(1);
    }
    genbosons_motherstatus_isLoaded = true;
  }
  return *genbosons_motherstatus_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_gmotherp4() {
  if (not genbosons_gmotherp4_isLoaded) {
    if (genbosons_gmotherp4_branch != 0) {
      genbosons_gmotherp4_branch->GetEntry(index);
    } else {
      printf("branch genbosons_gmotherp4_branch does not exist!\n");
      exit(1);
    }
    genbosons_gmotherp4_isLoaded = true;
  }
  return *genbosons_gmotherp4_;
}

const vector<int> &CMS3::genbosons_gmotherid() {
  if (not genbosons_gmotherid_isLoaded) {
    if (genbosons_gmotherid_branch != 0) {
      genbosons_gmotherid_branch->GetEntry(index);
    } else {
      printf("branch genbosons_gmotherid_branch does not exist!\n");
      exit(1);
    }
    genbosons_gmotherid_isLoaded = true;
  }
  return *genbosons_gmotherid_;
}

const vector<int> &CMS3::genbosons_gmotheridx() {
  if (not genbosons_gmotheridx_isLoaded) {
    if (genbosons_gmotheridx_branch != 0) {
      genbosons_gmotheridx_branch->GetEntry(index);
    } else {
      printf("branch genbosons_gmotheridx_branch does not exist!\n");
      exit(1);
    }
    genbosons_gmotheridx_isLoaded = true;
  }
  return *genbosons_gmotheridx_;
}

const vector<int> &CMS3::genbosons_gmotherstatus() {
  if (not genbosons_gmotherstatus_isLoaded) {
    if (genbosons_gmotherstatus_branch != 0) {
      genbosons_gmotherstatus_branch->GetEntry(index);
    } else {
      printf("branch genbosons_gmotherstatus_branch does not exist!\n");
      exit(1);
    }
    genbosons_gmotherstatus_isLoaded = true;
  }
  return *genbosons_gmotherstatus_;
}

const vector<bool> &CMS3::gensusy_isfromt() {
  if (not gensusy_isfromt_isLoaded) {
    if (gensusy_isfromt_branch != 0) {
      gensusy_isfromt_branch->GetEntry(index);
    } else {
      printf("branch gensusy_isfromt_branch does not exist!\n");
      exit(1);
    }
    gensusy_isfromt_isLoaded = true;
  }
  return *gensusy_isfromt_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_p4() {
  if (not gensusy_p4_isLoaded) {
    if (gensusy_p4_branch != 0) {
      gensusy_p4_branch->GetEntry(index);
    } else {
      printf("branch gensusy_p4_branch does not exist!\n");
      exit(1);
    }
    gensusy_p4_isLoaded = true;
  }
  return *gensusy_p4_;
}

const vector<int> &CMS3::gensusy_id() {
  if (not gensusy_id_isLoaded) {
    if (gensusy_id_branch != 0) {
      gensusy_id_branch->GetEntry(index);
    } else {
      printf("branch gensusy_id_branch does not exist!\n");
      exit(1);
    }
    gensusy_id_isLoaded = true;
  }
  return *gensusy_id_;
}

const vector<int> &CMS3::gensusy__genpsidx() {
  if (not gensusy__genpsidx_isLoaded) {
    if (gensusy__genpsidx_branch != 0) {
      gensusy__genpsidx_branch->GetEntry(index);
    } else {
      printf("branch gensusy__genpsidx_branch does not exist!\n");
      exit(1);
    }
    gensusy__genpsidx_isLoaded = true;
  }
  return *gensusy__genpsidx_;
}

const vector<int> &CMS3::gensusy_status() {
  if (not gensusy_status_isLoaded) {
    if (gensusy_status_branch != 0) {
      gensusy_status_branch->GetEntry(index);
    } else {
      printf("branch gensusy_status_branch does not exist!\n");
      exit(1);
    }
    gensusy_status_isLoaded = true;
  }
  return *gensusy_status_;
}

const vector<bool> &CMS3::gensusy_fromHardProcessDecayed() {
  if (not gensusy_fromHardProcessDecayed_isLoaded) {
    if (gensusy_fromHardProcessDecayed_branch != 0) {
      gensusy_fromHardProcessDecayed_branch->GetEntry(index);
    } else {
      printf("branch gensusy_fromHardProcessDecayed_branch does not exist!\n");
      exit(1);
    }
    gensusy_fromHardProcessDecayed_isLoaded = true;
  }
  return *gensusy_fromHardProcessDecayed_;
}

const vector<bool> &CMS3::gensusy_fromHardProcessFinalState() {
  if (not gensusy_fromHardProcessFinalState_isLoaded) {
    if (gensusy_fromHardProcessFinalState_branch != 0) {
      gensusy_fromHardProcessFinalState_branch->GetEntry(index);
    } else {
      printf("branch gensusy_fromHardProcessFinalState_branch does not exist!\n");
      exit(1);
    }
    gensusy_fromHardProcessFinalState_isLoaded = true;
  }
  return *gensusy_fromHardProcessFinalState_;
}

const vector<bool> &CMS3::gensusy_isHardProcess() {
  if (not gensusy_isHardProcess_isLoaded) {
    if (gensusy_isHardProcess_branch != 0) {
      gensusy_isHardProcess_branch->GetEntry(index);
    } else {
      printf("branch gensusy_isHardProcess_branch does not exist!\n");
      exit(1);
    }
    gensusy_isHardProcess_isLoaded = true;
  }
  return *gensusy_isHardProcess_;
}

const vector<bool> &CMS3::gensusy_isLastCopy() {
  if (not gensusy_isLastCopy_isLoaded) {
    if (gensusy_isLastCopy_branch != 0) {
      gensusy_isLastCopy_branch->GetEntry(index);
    } else {
      printf("branch gensusy_isLastCopy_branch does not exist!\n");
      exit(1);
    }
    gensusy_isLastCopy_isLoaded = true;
  }
  return *gensusy_isLastCopy_;
}

const vector<int> &CMS3::gensusy_gentaudecay() {
  if (not gensusy_gentaudecay_isLoaded) {
    if (gensusy_gentaudecay_branch != 0) {
      gensusy_gentaudecay_branch->GetEntry(index);
    } else {
      printf("branch gensusy_gentaudecay_branch does not exist!\n");
      exit(1);
    }
    gensusy_gentaudecay_isLoaded = true;
  }
  return *gensusy_gentaudecay_;
}

const int &CMS3::gen_nfromtsusy_() {
  if (not gen_nfromtsusy__isLoaded) {
    if (gen_nfromtsusy__branch != 0) {
      gen_nfromtsusy__branch->GetEntry(index);
    } else {
      printf("branch gen_nfromtsusy__branch does not exist!\n");
      exit(1);
    }
    gen_nfromtsusy__isLoaded = true;
  }
  return gen_nfromtsusy__;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_motherp4() {
  if (not gensusy_motherp4_isLoaded) {
    if (gensusy_motherp4_branch != 0) {
      gensusy_motherp4_branch->GetEntry(index);
    } else {
      printf("branch gensusy_motherp4_branch does not exist!\n");
      exit(1);
    }
    gensusy_motherp4_isLoaded = true;
  }
  return *gensusy_motherp4_;
}

const vector<int> &CMS3::gensusy_motherid() {
  if (not gensusy_motherid_isLoaded) {
    if (gensusy_motherid_branch != 0) {
      gensusy_motherid_branch->GetEntry(index);
    } else {
      printf("branch gensusy_motherid_branch does not exist!\n");
      exit(1);
    }
    gensusy_motherid_isLoaded = true;
  }
  return *gensusy_motherid_;
}

const vector<int> &CMS3::gensusy_motheridx() {
  if (not gensusy_motheridx_isLoaded) {
    if (gensusy_motheridx_branch != 0) {
      gensusy_motheridx_branch->GetEntry(index);
    } else {
      printf("branch gensusy_motheridx_branch does not exist!\n");
      exit(1);
    }
    gensusy_motheridx_isLoaded = true;
  }
  return *gensusy_motheridx_;
}

const vector<int> &CMS3::gensusy_motherstatus() {
  if (not gensusy_motherstatus_isLoaded) {
    if (gensusy_motherstatus_branch != 0) {
      gensusy_motherstatus_branch->GetEntry(index);
    } else {
      printf("branch gensusy_motherstatus_branch does not exist!\n");
      exit(1);
    }
    gensusy_motherstatus_isLoaded = true;
  }
  return *gensusy_motherstatus_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_gmotherp4() {
  if (not gensusy_gmotherp4_isLoaded) {
    if (gensusy_gmotherp4_branch != 0) {
      gensusy_gmotherp4_branch->GetEntry(index);
    } else {
      printf("branch gensusy_gmotherp4_branch does not exist!\n");
      exit(1);
    }
    gensusy_gmotherp4_isLoaded = true;
  }
  return *gensusy_gmotherp4_;
}

const vector<int> &CMS3::gensusy_gmotherid() {
  if (not gensusy_gmotherid_isLoaded) {
    if (gensusy_gmotherid_branch != 0) {
      gensusy_gmotherid_branch->GetEntry(index);
    } else {
      printf("branch gensusy_gmotherid_branch does not exist!\n");
      exit(1);
    }
    gensusy_gmotherid_isLoaded = true;
  }
  return *gensusy_gmotherid_;
}

const vector<int> &CMS3::gensusy_gmotheridx() {
  if (not gensusy_gmotheridx_isLoaded) {
    if (gensusy_gmotheridx_branch != 0) {
      gensusy_gmotheridx_branch->GetEntry(index);
    } else {
      printf("branch gensusy_gmotheridx_branch does not exist!\n");
      exit(1);
    }
    gensusy_gmotheridx_isLoaded = true;
  }
  return *gensusy_gmotheridx_;
}

const vector<int> &CMS3::gensusy_gmotherstatus() {
  if (not gensusy_gmotherstatus_isLoaded) {
    if (gensusy_gmotherstatus_branch != 0) {
      gensusy_gmotherstatus_branch->GetEntry(index);
    } else {
      printf("branch gensusy_gmotherstatus_branch does not exist!\n");
      exit(1);
    }
    gensusy_gmotherstatus_isLoaded = true;
  }
  return *gensusy_gmotherstatus_;
}

const vector<TString> &CMS3::tau_IDnames() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_leadtrack_p4() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_leadneutral_p4() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_p4() {
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

const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::tau_isocand_p4() {
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

const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::tau_sigcand_p4() {
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

const vector<vector<float> > &CMS3::tau_ID() {
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

const vector<float> &CMS3::tau_passID() {
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

const int &CMS3::ngoodtaus() {
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

const vector<float> &CMS3::tau_againstMuonTight() {
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

const vector<float> &CMS3::tau_againstElectronLoose() {
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

const vector<bool> &CMS3::tau_isVetoTau() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::isoTracks_p4() {
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

const vector<int> &CMS3::isoTracks_charge() {
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

const vector<float> &CMS3::isoTracks_absIso() {
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

const vector<float> &CMS3::isoTracks_dz() {
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

const vector<int> &CMS3::isoTracks_pdgId() {
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

const vector<bool> &CMS3::isoTracks_isVetoTrack() {
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

const vector<bool> &CMS3::isoTracks_isVetoTrack_v2() {
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

const vector<bool> &CMS3::isoTracks_isVetoTrack_v3() {
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

const float &CMS3::filt_cscbeamhalo() {
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

const float &CMS3::filt_cscbeamhalo2015() {
  if (not filt_cscbeamhalo2015_isLoaded) {
    if (filt_cscbeamhalo2015_branch != 0) {
      filt_cscbeamhalo2015_branch->GetEntry(index);
    } else {
      printf("branch filt_cscbeamhalo2015_branch does not exist!\n");
      exit(1);
    }
    filt_cscbeamhalo2015_isLoaded = true;
  }
  return filt_cscbeamhalo2015_;
}

const float &CMS3::filt_globaltighthalo2016() {
  if (not filt_globaltighthalo2016_isLoaded) {
    if (filt_globaltighthalo2016_branch != 0) {
      filt_globaltighthalo2016_branch->GetEntry(index);
    } else {
      printf("branch filt_globaltighthalo2016_branch does not exist!\n");
      exit(1);
    }
    filt_globaltighthalo2016_isLoaded = true;
  }
  return filt_globaltighthalo2016_;
}

const float &CMS3::filt_globalsupertighthalo2016() {
  if (not filt_globalsupertighthalo2016_isLoaded) {
    if (filt_globalsupertighthalo2016_branch != 0) {
      filt_globalsupertighthalo2016_branch->GetEntry(index);
    } else {
      printf("branch filt_globalsupertighthalo2016_branch does not exist!\n");
      exit(1);
    }
    filt_globalsupertighthalo2016_isLoaded = true;
  }
  return filt_globalsupertighthalo2016_;
}

const float &CMS3::filt_ecallaser() {
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

const float &CMS3::filt_ecaltp() {
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

const float &CMS3::filt_eebadsc() {
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

const float &CMS3::filt_goodvtx() {
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

const float &CMS3::filt_badevents() {
  if (not filt_badevents_isLoaded) {
    if (filt_badevents_branch != 0) {
      filt_badevents_branch->GetEntry(index);
    } else {
      printf("branch filt_badevents_branch does not exist!\n");
      exit(1);
    }
    filt_badevents_isLoaded = true;
  }
  return filt_badevents_;
}

const float &CMS3::filt_hbhenoise() {
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

const float &CMS3::filt_hbheisonoise() {
  if (not filt_hbheisonoise_isLoaded) {
    if (filt_hbheisonoise_branch != 0) {
      filt_hbheisonoise_branch->GetEntry(index);
    } else {
      printf("branch filt_hbheisonoise_branch does not exist!\n");
      exit(1);
    }
    filt_hbheisonoise_isLoaded = true;
  }
  return filt_hbheisonoise_;
}

const float &CMS3::filt_hcallaser() {
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

const float &CMS3::filt_trkfail() {
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

const float &CMS3::filt_trkPOG() {
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

const float &CMS3::filt_trkPOG_logerr_tmc() {
  if (not filt_trkPOG_logerr_tmc_isLoaded) {
    if (filt_trkPOG_logerr_tmc_branch != 0) {
      filt_trkPOG_logerr_tmc_branch->GetEntry(index);
    } else {
      printf("branch filt_trkPOG_logerr_tmc_branch does not exist!\n");
      exit(1);
    }
    filt_trkPOG_logerr_tmc_isLoaded = true;
  }
  return filt_trkPOG_logerr_tmc_;
}

const float &CMS3::filt_trkPOG_tmc() {
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

const float &CMS3::filt_trkPOG_tms() {
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

const int &CMS3::firstGoodVtxIdx() {
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

const float &CMS3::filt_badChargedCandidateFilter() {
  if (not filt_badChargedCandidateFilter_isLoaded) {
    if (filt_badChargedCandidateFilter_branch != 0) {
      filt_badChargedCandidateFilter_branch->GetEntry(index);
    } else {
      printf("branch filt_badChargedCandidateFilter_branch does not exist!\n");
      exit(1);
    }
    filt_badChargedCandidateFilter_isLoaded = true;
  }
  return filt_badChargedCandidateFilter_;
}

const float &CMS3::filt_badMuonFilter() {
  if (not filt_badMuonFilter_isLoaded) {
    if (filt_badMuonFilter_branch != 0) {
      filt_badMuonFilter_branch->GetEntry(index);
    } else {
      printf("branch filt_badMuonFilter_branch does not exist!\n");
      exit(1);
    }
    filt_badMuonFilter_isLoaded = true;
  }
  return filt_badMuonFilter_;
}

const float &CMS3::filt_met() {
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

const bool &CMS3::filt_fastsimjets() {
  if (not filt_fastsimjets_isLoaded) {
    if (filt_fastsimjets_branch != 0) {
      filt_fastsimjets_branch->GetEntry(index);
    } else {
      printf("branch filt_fastsimjets_branch does not exist!\n");
      exit(1);
    }
    filt_fastsimjets_isLoaded = true;
  }
  return filt_fastsimjets_;
}

const bool &CMS3::filt_fastsimjets_jup() {
  if (not filt_fastsimjets_jup_isLoaded) {
    if (filt_fastsimjets_jup_branch != 0) {
      filt_fastsimjets_jup_branch->GetEntry(index);
    } else {
      printf("branch filt_fastsimjets_jup_branch does not exist!\n");
      exit(1);
    }
    filt_fastsimjets_jup_isLoaded = true;
  }
  return filt_fastsimjets_jup_;
}

const bool &CMS3::filt_fastsimjets_jdown() {
  if (not filt_fastsimjets_jdown_isLoaded) {
    if (filt_fastsimjets_jdown_branch != 0) {
      filt_fastsimjets_jdown_branch->GetEntry(index);
    } else {
      printf("branch filt_fastsimjets_jdown_branch does not exist!\n");
      exit(1);
    }
    filt_fastsimjets_jdown_isLoaded = true;
  }
  return filt_fastsimjets_jdown_;
}

const bool &CMS3::filt_jetWithBadMuon() {
  if (not filt_jetWithBadMuon_isLoaded) {
    if (filt_jetWithBadMuon_branch != 0) {
      filt_jetWithBadMuon_branch->GetEntry(index);
    } else {
      printf("branch filt_jetWithBadMuon_branch does not exist!\n");
      exit(1);
    }
    filt_jetWithBadMuon_isLoaded = true;
  }
  return filt_jetWithBadMuon_;
}

const bool &CMS3::filt_jetWithBadMuon_jup() {
  if (not filt_jetWithBadMuon_jup_isLoaded) {
    if (filt_jetWithBadMuon_jup_branch != 0) {
      filt_jetWithBadMuon_jup_branch->GetEntry(index);
    } else {
      printf("branch filt_jetWithBadMuon_jup_branch does not exist!\n");
      exit(1);
    }
    filt_jetWithBadMuon_jup_isLoaded = true;
  }
  return filt_jetWithBadMuon_jup_;
}

const bool &CMS3::filt_jetWithBadMuon_jdown() {
  if (not filt_jetWithBadMuon_jdown_isLoaded) {
    if (filt_jetWithBadMuon_jdown_branch != 0) {
      filt_jetWithBadMuon_jdown_branch->GetEntry(index);
    } else {
      printf("branch filt_jetWithBadMuon_jdown_branch does not exist!\n");
      exit(1);
    }
    filt_jetWithBadMuon_jdown_isLoaded = true;
  }
  return filt_jetWithBadMuon_jdown_;
}

const bool &CMS3::filt_pfovercalomet() {
  if (not filt_pfovercalomet_isLoaded) {
    if (filt_pfovercalomet_branch != 0) {
      filt_pfovercalomet_branch->GetEntry(index);
    } else {
      printf("branch filt_pfovercalomet_branch does not exist!\n");
      exit(1);
    }
    filt_pfovercalomet_isLoaded = true;
  }
  return filt_pfovercalomet_;
}

const bool &CMS3::filt_badmuons() {
  if (not filt_badmuons_isLoaded) {
    if (filt_badmuons_branch != 0) {
      filt_badmuons_branch->GetEntry(index);
    } else {
      printf("branch filt_badmuons_branch does not exist!\n");
      exit(1);
    }
    filt_badmuons_isLoaded = true;
  }
  return filt_badmuons_;
}

const bool &CMS3::filt_duplicatemuons() {
  if (not filt_duplicatemuons_isLoaded) {
    if (filt_duplicatemuons_branch != 0) {
      filt_duplicatemuons_branch->GetEntry(index);
    } else {
      printf("branch filt_duplicatemuons_branch does not exist!\n");
      exit(1);
    }
    filt_duplicatemuons_isLoaded = true;
  }
  return filt_duplicatemuons_;
}

const bool &CMS3::filt_nobadmuons() {
  if (not filt_nobadmuons_isLoaded) {
    if (filt_nobadmuons_branch != 0) {
      filt_nobadmuons_branch->GetEntry(index);
    } else {
      printf("branch filt_nobadmuons_branch does not exist!\n");
      exit(1);
    }
    filt_nobadmuons_isLoaded = true;
  }
  return filt_nobadmuons_;
}


extern "C" void CMS3::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
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

namespace tas {

extern "C" void Init(TTree *tree) { return cms3.Init(tree); }
extern "C" void GetEntry(unsigned int idx) { return cms3.GetEntry(idx); }
extern "C" void LoadAllBranches() { return cms3.LoadAllBranches(); }
extern "C" void progress(int nEventsTotal, int nEventsChain) { return cms3.progress(nEventsTotal,nEventsChain); }

extern "C" const unsigned int &run() { return cms3.run(); }
extern "C" const unsigned int &ls() { return cms3.ls(); }
extern "C" const unsigned int &evt() { return cms3.evt(); }
extern "C" const int &nvtxs() { return cms3.nvtxs(); }
extern "C" const int &pu_nvtxs() { return cms3.pu_nvtxs(); }
extern "C" const float &pfmet() { return cms3.pfmet(); }
extern "C" const float &pfmet_phi() { return cms3.pfmet_phi(); }
extern "C" const float &pfmet_jup() { return cms3.pfmet_jup(); }
extern "C" const float &pfmet_phi_jup() { return cms3.pfmet_phi_jup(); }
extern "C" const float &pfmet_jdown() { return cms3.pfmet_jdown(); }
extern "C" const float &pfmet_phi_jdown() { return cms3.pfmet_phi_jdown(); }
extern "C" const float &pfmet_rl() { return cms3.pfmet_rl(); }
extern "C" const float &pfmet_phi_rl() { return cms3.pfmet_phi_rl(); }
extern "C" const float &pfmet_rl_jup() { return cms3.pfmet_rl_jup(); }
extern "C" const float &pfmet_phi_rl_jup() { return cms3.pfmet_phi_rl_jup(); }
extern "C" const float &pfmet_rl_jdown() { return cms3.pfmet_rl_jdown(); }
extern "C" const float &pfmet_phi_rl_jdown() { return cms3.pfmet_phi_rl_jdown(); }
extern "C" const float &pfmet_egclean() { return cms3.pfmet_egclean(); }
extern "C" const float &pfmet_egclean_phi() { return cms3.pfmet_egclean_phi(); }
extern "C" const float &pfmet_muegclean() { return cms3.pfmet_muegclean(); }
extern "C" const float &pfmet_muegclean_phi() { return cms3.pfmet_muegclean_phi(); }
extern "C" const float &pfmet_muegcleanfix() { return cms3.pfmet_muegcleanfix(); }
extern "C" const float &pfmet_muegcleanfix_phi() { return cms3.pfmet_muegcleanfix_phi(); }
extern "C" const float &pfmet_uncorr() { return cms3.pfmet_uncorr(); }
extern "C" const float &pfmet_uncorr_phi() { return cms3.pfmet_uncorr_phi(); }
extern "C" const float &pfmet_original() { return cms3.pfmet_original(); }
extern "C" const float &pfmet_original_phi() { return cms3.pfmet_original_phi(); }
extern "C" const float &scale1fb() { return cms3.scale1fb(); }
extern "C" const float &xsec() { return cms3.xsec(); }
extern "C" const float &xsec_uncert() { return cms3.xsec_uncert(); }
extern "C" const float &kfactor() { return cms3.kfactor(); }
extern "C" const float &pu_ntrue() { return cms3.pu_ntrue(); }
extern "C" const int &ngoodleps() { return cms3.ngoodleps(); }
extern "C" const int &nlooseleps() { return cms3.nlooseleps(); }
extern "C" const int &nvetoleps() { return cms3.nvetoleps(); }
extern "C" const bool &is_data() { return cms3.is_data(); }
extern "C" const string &dataset() { return cms3.dataset(); }
extern "C" const string &filename() { return cms3.filename(); }
extern "C" const string &cms3tag() { return cms3.cms3tag(); }
extern "C" const unsigned int &nEvents() { return cms3.nEvents(); }
extern "C" const unsigned int &nEvents_goodvtx() { return cms3.nEvents_goodvtx(); }
extern "C" const unsigned int &nEvents_MET30() { return cms3.nEvents_MET30(); }
extern "C" const unsigned int &nEvents_1goodlep() { return cms3.nEvents_1goodlep(); }
extern "C" const unsigned int &nEvents_2goodjets() { return cms3.nEvents_2goodjets(); }
extern "C" const int &is0lep() { return cms3.is0lep(); }
extern "C" const int &is1lep() { return cms3.is1lep(); }
extern "C" const int &is2lep() { return cms3.is2lep(); }
extern "C" const int &isZtoNuNu() { return cms3.isZtoNuNu(); }
extern "C" const int &is1lepFromW() { return cms3.is1lepFromW(); }
extern "C" const int &is1lepFromTop() { return cms3.is1lepFromTop(); }
extern "C" const float &MT2W() { return cms3.MT2W(); }
extern "C" const float &MT2W_rl() { return cms3.MT2W_rl(); }
extern "C" const float &mindphi_met_j1_j2() { return cms3.mindphi_met_j1_j2(); }
extern "C" const float &mindphi_met_j1_j2_rl() { return cms3.mindphi_met_j1_j2_rl(); }
extern "C" const float &mt_met_lep() { return cms3.mt_met_lep(); }
extern "C" const float &mt_met_lep_rl() { return cms3.mt_met_lep_rl(); }
extern "C" const float &MT2W_jup() { return cms3.MT2W_jup(); }
extern "C" const float &MT2W_rl_jup() { return cms3.MT2W_rl_jup(); }
extern "C" const float &mindphi_met_j1_j2_jup() { return cms3.mindphi_met_j1_j2_jup(); }
extern "C" const float &mindphi_met_j1_j2_rl_jup() { return cms3.mindphi_met_j1_j2_rl_jup(); }
extern "C" const float &mt_met_lep_jup() { return cms3.mt_met_lep_jup(); }
extern "C" const float &mt_met_lep_rl_jup() { return cms3.mt_met_lep_rl_jup(); }
extern "C" const float &MT2W_jdown() { return cms3.MT2W_jdown(); }
extern "C" const float &MT2W_rl_jdown() { return cms3.MT2W_rl_jdown(); }
extern "C" const float &mindphi_met_j1_j2_jdown() { return cms3.mindphi_met_j1_j2_jdown(); }
extern "C" const float &mindphi_met_j1_j2_rl_jdown() { return cms3.mindphi_met_j1_j2_rl_jdown(); }
extern "C" const float &mt_met_lep_jdown() { return cms3.mt_met_lep_jdown(); }
extern "C" const float &mt_met_lep_rl_jdown() { return cms3.mt_met_lep_rl_jdown(); }
extern "C" const float &hadronic_top_chi2() { return cms3.hadronic_top_chi2(); }
extern "C" const float &ak4pfjets_rho() { return cms3.ak4pfjets_rho(); }
extern "C" const float &pdf_up_weight() { return cms3.pdf_up_weight(); }
extern "C" const float &pdf_down_weight() { return cms3.pdf_down_weight(); }
extern "C" const vector<string> &genweightsID() { return cms3.genweightsID(); }
extern "C" const vector<float> &genweights() { return cms3.genweights(); }
extern "C" const float &weight_btagsf() { return cms3.weight_btagsf(); }
extern "C" const float &weight_btagsf_heavy_UP() { return cms3.weight_btagsf_heavy_UP(); }
extern "C" const float &weight_btagsf_light_UP() { return cms3.weight_btagsf_light_UP(); }
extern "C" const float &weight_btagsf_heavy_DN() { return cms3.weight_btagsf_heavy_DN(); }
extern "C" const float &weight_btagsf_light_DN() { return cms3.weight_btagsf_light_DN(); }
extern "C" const float &weight_btagsf_fastsim_UP() { return cms3.weight_btagsf_fastsim_UP(); }
extern "C" const float &weight_btagsf_fastsim_DN() { return cms3.weight_btagsf_fastsim_DN(); }
extern "C" const float &weight_analysisbtagsf() { return cms3.weight_analysisbtagsf(); }
extern "C" const float &weight_analysisbtagsf_heavy_UP() { return cms3.weight_analysisbtagsf_heavy_UP(); }
extern "C" const float &weight_analysisbtagsf_light_UP() { return cms3.weight_analysisbtagsf_light_UP(); }
extern "C" const float &weight_analysisbtagsf_heavy_DN() { return cms3.weight_analysisbtagsf_heavy_DN(); }
extern "C" const float &weight_analysisbtagsf_light_DN() { return cms3.weight_analysisbtagsf_light_DN(); }
extern "C" const float &weight_analysisbtagsf_fastsim_UP() { return cms3.weight_analysisbtagsf_fastsim_UP(); }
extern "C" const float &weight_analysisbtagsf_fastsim_DN() { return cms3.weight_analysisbtagsf_fastsim_DN(); }
extern "C" const float &weight_tightbtagsf() { return cms3.weight_tightbtagsf(); }
extern "C" const float &weight_tightbtagsf_heavy_UP() { return cms3.weight_tightbtagsf_heavy_UP(); }
extern "C" const float &weight_tightbtagsf_light_UP() { return cms3.weight_tightbtagsf_light_UP(); }
extern "C" const float &weight_tightbtagsf_heavy_DN() { return cms3.weight_tightbtagsf_heavy_DN(); }
extern "C" const float &weight_tightbtagsf_light_DN() { return cms3.weight_tightbtagsf_light_DN(); }
extern "C" const float &weight_tightbtagsf_fastsim_UP() { return cms3.weight_tightbtagsf_fastsim_UP(); }
extern "C" const float &weight_tightbtagsf_fastsim_DN() { return cms3.weight_tightbtagsf_fastsim_DN(); }
extern "C" const float &weight_loosebtagsf() { return cms3.weight_loosebtagsf(); }
extern "C" const float &weight_loosebtagsf_heavy_UP() { return cms3.weight_loosebtagsf_heavy_UP(); }
extern "C" const float &weight_loosebtagsf_light_UP() { return cms3.weight_loosebtagsf_light_UP(); }
extern "C" const float &weight_loosebtagsf_heavy_DN() { return cms3.weight_loosebtagsf_heavy_DN(); }
extern "C" const float &weight_loosebtagsf_light_DN() { return cms3.weight_loosebtagsf_light_DN(); }
extern "C" const float &weight_loosebtagsf_fastsim_UP() { return cms3.weight_loosebtagsf_fastsim_UP(); }
extern "C" const float &weight_loosebtagsf_fastsim_DN() { return cms3.weight_loosebtagsf_fastsim_DN(); }
extern "C" const float &weight_lepSF() { return cms3.weight_lepSF(); }
extern "C" const float &weight_lepSF_up() { return cms3.weight_lepSF_up(); }
extern "C" const float &weight_lepSF_down() { return cms3.weight_lepSF_down(); }
extern "C" const float &weight_vetoLepSF() { return cms3.weight_vetoLepSF(); }
extern "C" const float &weight_vetoLepSF_up() { return cms3.weight_vetoLepSF_up(); }
extern "C" const float &weight_vetoLepSF_down() { return cms3.weight_vetoLepSF_down(); }
extern "C" const float &weight_lepSF_fastSim() { return cms3.weight_lepSF_fastSim(); }
extern "C" const float &weight_lepSF_fastSim_up() { return cms3.weight_lepSF_fastSim_up(); }
extern "C" const float &weight_lepSF_fastSim_down() { return cms3.weight_lepSF_fastSim_down(); }
extern "C" const float &weight_ISR() { return cms3.weight_ISR(); }
extern "C" const float &weight_ISRup() { return cms3.weight_ISRup(); }
extern "C" const float &weight_ISRdown() { return cms3.weight_ISRdown(); }
extern "C" const float &weight_PU() { return cms3.weight_PU(); }
extern "C" const float &weight_PUup() { return cms3.weight_PUup(); }
extern "C" const float &weight_PUdown() { return cms3.weight_PUdown(); }
extern "C" const float &weight_ISRnjets() { return cms3.weight_ISRnjets(); }
extern "C" const float &weight_ISRnjets_UP() { return cms3.weight_ISRnjets_UP(); }
extern "C" const float &weight_ISRnjets_DN() { return cms3.weight_ISRnjets_DN(); }
extern "C" const int &NISRjets() { return cms3.NISRjets(); }
extern "C" const int &NnonISRjets() { return cms3.NnonISRjets(); }
extern "C" const vector<string> &sparms_names() { return cms3.sparms_names(); }
extern "C" const vector<float> &sparms_values() { return cms3.sparms_values(); }
extern "C" const int &sparms_subProcessId() { return cms3.sparms_subProcessId(); }
extern "C" const float &mass_lsp() { return cms3.mass_lsp(); }
extern "C" const float &mass_chargino() { return cms3.mass_chargino(); }
extern "C" const float &mass_stop() { return cms3.mass_stop(); }
extern "C" const float &mass_gluino() { return cms3.mass_gluino(); }
extern "C" const float &genmet() { return cms3.genmet(); }
extern "C" const float &genmet_phi() { return cms3.genmet_phi(); }
extern "C" const float &nupt() { return cms3.nupt(); }
extern "C" const float &genht() { return cms3.genht(); }
extern "C" const bool &PassTrackVeto() { return cms3.PassTrackVeto(); }
extern "C" const bool &PassTauVeto() { return cms3.PassTauVeto(); }
extern "C" const float &topness() { return cms3.topness(); }
extern "C" const float &topnessMod() { return cms3.topnessMod(); }
extern "C" const float &topnessMod_rl() { return cms3.topnessMod_rl(); }
extern "C" const float &topnessMod_jup() { return cms3.topnessMod_jup(); }
extern "C" const float &topnessMod_rl_jup() { return cms3.topnessMod_rl_jup(); }
extern "C" const float &topnessMod_jdown() { return cms3.topnessMod_jdown(); }
extern "C" const float &topnessMod_rl_jdown() { return cms3.topnessMod_rl_jdown(); }
extern "C" const float &Mlb_closestb() { return cms3.Mlb_closestb(); }
extern "C" const float &Mlb_lead_bdiscr() { return cms3.Mlb_lead_bdiscr(); }
extern "C" const float &Mlb_closestb_jup() { return cms3.Mlb_closestb_jup(); }
extern "C" const float &Mlb_lead_bdiscr_jup() { return cms3.Mlb_lead_bdiscr_jup(); }
extern "C" const float &Mlb_closestb_jdown() { return cms3.Mlb_closestb_jdown(); }
extern "C" const float &Mlb_lead_bdiscr_jdown() { return cms3.Mlb_lead_bdiscr_jdown(); }
extern "C" const int &HLT_SingleEl() { return cms3.HLT_SingleEl(); }
extern "C" const int &HLT_SingleMu() { return cms3.HLT_SingleMu(); }
extern "C" const int &HLT_MET() { return cms3.HLT_MET(); }
extern "C" const int &HLT_MET_MHT() { return cms3.HLT_MET_MHT(); }
extern "C" const int &HLT_MET100_MHT100() { return cms3.HLT_MET100_MHT100(); }
extern "C" const int &HLT_MET110_MHT110() { return cms3.HLT_MET110_MHT110(); }
extern "C" const int &HLT_MET120_MHT120() { return cms3.HLT_MET120_MHT120(); }
extern "C" const int &HLT_PFHT_unprescaled() { return cms3.HLT_PFHT_unprescaled(); }
extern "C" const int &HLT_PFHT_prescaled() { return cms3.HLT_PFHT_prescaled(); }
extern "C" const int &HLT_DiEl() { return cms3.HLT_DiEl(); }
extern "C" const int &HLT_DiMu() { return cms3.HLT_DiMu(); }
extern "C" const int &HLT_MuE() { return cms3.HLT_MuE(); }
extern "C" const int &nPhotons() { return cms3.nPhotons(); }
extern "C" const int &ph_ngoodjets() { return cms3.ph_ngoodjets(); }
extern "C" const int &ph_ngoodbtags() { return cms3.ph_ngoodbtags(); }
extern "C" const float &hardgenpt() { return cms3.hardgenpt(); }
extern "C" const float &calomet() { return cms3.calomet(); }
extern "C" const float &calomet_phi() { return cms3.calomet_phi(); }
extern "C" const int &lep1_pdgid() { return cms3.lep1_pdgid(); }
extern "C" const int &lep1_production_type() { return cms3.lep1_production_type(); }
extern "C" const float &lep1_MiniIso() { return cms3.lep1_MiniIso(); }
extern "C" const float &lep1_relIso() { return cms3.lep1_relIso(); }
extern "C" const bool &lep1_passLooseID() { return cms3.lep1_passLooseID(); }
extern "C" const bool &lep1_passMediumID() { return cms3.lep1_passMediumID(); }
extern "C" const bool &lep1_passTightID() { return cms3.lep1_passTightID(); }
extern "C" const bool &lep1_passVeto() { return cms3.lep1_passVeto(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return cms3.lep1_p4(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4() { return cms3.lep1_mcp4(); }
extern "C" const int &lep1_mc_motherid() { return cms3.lep1_mc_motherid(); }
extern "C" const float &lep1_dphiMET() { return cms3.lep1_dphiMET(); }
extern "C" const float &lep1_dphiMET_jup() { return cms3.lep1_dphiMET_jup(); }
extern "C" const float &lep1_dphiMET_jdown() { return cms3.lep1_dphiMET_jdown(); }
extern "C" const float &lep1_dphiMET_rl() { return cms3.lep1_dphiMET_rl(); }
extern "C" const float &lep1_dphiMET_rl_jup() { return cms3.lep1_dphiMET_rl_jup(); }
extern "C" const float &lep1_dphiMET_rl_jdown() { return cms3.lep1_dphiMET_rl_jdown(); }
extern "C" const int &lep2_pdgid() { return cms3.lep2_pdgid(); }
extern "C" const int &lep2_production_type() { return cms3.lep2_production_type(); }
extern "C" const float &lep2_MiniIso() { return cms3.lep2_MiniIso(); }
extern "C" const float &lep2_relIso() { return cms3.lep2_relIso(); }
extern "C" const bool &lep2_passLooseID() { return cms3.lep2_passLooseID(); }
extern "C" const bool &lep2_passMediumID() { return cms3.lep2_passMediumID(); }
extern "C" const bool &lep2_passTightID() { return cms3.lep2_passTightID(); }
extern "C" const bool &lep2_passVeto() { return cms3.lep2_passVeto(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return cms3.lep2_p4(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4() { return cms3.lep2_mcp4(); }
extern "C" const int &lep2_mc_motherid() { return cms3.lep2_mc_motherid(); }
extern "C" const float &lep2_dphiMET() { return cms3.lep2_dphiMET(); }
extern "C" const float &lep2_dphiMET_jup() { return cms3.lep2_dphiMET_jup(); }
extern "C" const float &lep2_dphiMET_jdown() { return cms3.lep2_dphiMET_jdown(); }
extern "C" const float &lep2_dphiMET_rl() { return cms3.lep2_dphiMET_rl(); }
extern "C" const float &lep2_dphiMET_rl_jup() { return cms3.lep2_dphiMET_rl_jup(); }
extern "C" const float &lep2_dphiMET_rl_jdown() { return cms3.lep2_dphiMET_rl_jdown(); }
extern "C" const vector<float> &ph_sigmaIEtaEta_fill5x5() { return cms3.ph_sigmaIEtaEta_fill5x5(); }
extern "C" const vector<float> &ph_hOverE() { return cms3.ph_hOverE(); }
extern "C" const vector<float> &ph_r9() { return cms3.ph_r9(); }
extern "C" const vector<float> &ph_chiso() { return cms3.ph_chiso(); }
extern "C" const vector<float> &ph_nhiso() { return cms3.ph_nhiso(); }
extern "C" const vector<float> &ph_phiso() { return cms3.ph_phiso(); }
extern "C" const vector<int> &ph_overlapJetId() { return cms3.ph_overlapJetId(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_p4() { return cms3.ph_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_mcp4() { return cms3.ph_mcp4(); }
extern "C" const vector<float> &ph_pt() { return cms3.ph_pt(); }
extern "C" const vector<float> &ph_eta() { return cms3.ph_eta(); }
extern "C" const vector<float> &ph_phi() { return cms3.ph_phi(); }
extern "C" const vector<float> &ph_mass() { return cms3.ph_mass(); }
extern "C" const vector<int> &ph_mcMatchId() { return cms3.ph_mcMatchId(); }
extern "C" const vector<float> &ph_genIso04() { return cms3.ph_genIso04(); }
extern "C" const vector<float> &ph_drMinParton() { return cms3.ph_drMinParton(); }
extern "C" const int &ngoodjets() { return cms3.ngoodjets(); }
extern "C" const int &ngoodbtags() { return cms3.ngoodbtags(); }
extern "C" const int &nloosebtags() { return cms3.nloosebtags(); }
extern "C" const int &ntightbtags() { return cms3.ntightbtags(); }
extern "C" const int &nanalysisbtags() { return cms3.nanalysisbtags(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &softtags_p4() { return cms3.softtags_p4(); }
extern "C" const int &nsoftbtags() { return cms3.nsoftbtags(); }
extern "C" const float &ak4_HT() { return cms3.ak4_HT(); }
extern "C" const float &ak4_htratiom() { return cms3.ak4_htratiom(); }
extern "C" const vector<float> &dphi_ak4pfjet_met() { return cms3.dphi_ak4pfjet_met(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4() { return cms3.ak4pfjets_p4(); }
extern "C" const vector<bool> &ak4pfjets_passMEDbtag() { return cms3.ak4pfjets_passMEDbtag(); }
extern "C" const vector<float> &ak4pfjets_CSV() { return cms3.ak4pfjets_CSV(); }
extern "C" const vector<float> &ak4pfjets_mva() { return cms3.ak4pfjets_mva(); }
extern "C" const vector<int> &ak4pfjets_parton_flavor() { return cms3.ak4pfjets_parton_flavor(); }
extern "C" const vector<int> &ak4pfjets_hadron_flavor() { return cms3.ak4pfjets_hadron_flavor(); }
extern "C" const vector<bool> &ak4pfjets_loose_puid() { return cms3.ak4pfjets_loose_puid(); }
extern "C" const vector<bool> &ak4pfjets_loose_pfid() { return cms3.ak4pfjets_loose_pfid(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4() { return cms3.ak4pfjets_leadMEDbjet_p4(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4() { return cms3.ak4pfjets_leadbtag_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4() { return cms3.ak4genjets_p4(); }
extern "C" const int &jup_ngoodjets() { return cms3.jup_ngoodjets(); }
extern "C" const int &jup_ngoodbtags() { return cms3.jup_ngoodbtags(); }
extern "C" const int &jup_nloosebtags() { return cms3.jup_nloosebtags(); }
extern "C" const int &jup_ntightbtags() { return cms3.jup_ntightbtags(); }
extern "C" const int &jup_nanalysisbtags() { return cms3.jup_nanalysisbtags(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jup_softtags_p4() { return cms3.jup_softtags_p4(); }
extern "C" const int &jup_nsoftbtags() { return cms3.jup_nsoftbtags(); }
extern "C" const float &jup_ak4_HT() { return cms3.jup_ak4_HT(); }
extern "C" const float &jup_ak4_htratiom() { return cms3.jup_ak4_htratiom(); }
extern "C" const vector<float> &jup_dphi_ak4pfjet_met() { return cms3.jup_dphi_ak4pfjet_met(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jup_ak4pfjets_p4() { return cms3.jup_ak4pfjets_p4(); }
extern "C" const vector<bool> &jup_ak4pfjets_passMEDbtag() { return cms3.jup_ak4pfjets_passMEDbtag(); }
extern "C" const vector<float> &jup_ak4pfjets_CSV() { return cms3.jup_ak4pfjets_CSV(); }
extern "C" const vector<float> &jup_ak4pfjets_mva() { return cms3.jup_ak4pfjets_mva(); }
extern "C" const vector<int> &jup_ak4pfjets_parton_flavor() { return cms3.jup_ak4pfjets_parton_flavor(); }
extern "C" const vector<int> &jup_ak4pfjets_hadron_flavor() { return cms3.jup_ak4pfjets_hadron_flavor(); }
extern "C" const vector<bool> &jup_ak4pfjets_loose_puid() { return cms3.jup_ak4pfjets_loose_puid(); }
extern "C" const vector<bool> &jup_ak4pfjets_loose_pfid() { return cms3.jup_ak4pfjets_loose_pfid(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jup_ak4pfjets_leadMEDbjet_p4() { return cms3.jup_ak4pfjets_leadMEDbjet_p4(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jup_ak4pfjets_leadbtag_p4() { return cms3.jup_ak4pfjets_leadbtag_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jup_ak4genjets_p4() { return cms3.jup_ak4genjets_p4(); }
extern "C" const int &jdown_ngoodjets() { return cms3.jdown_ngoodjets(); }
extern "C" const int &jdown_ngoodbtags() { return cms3.jdown_ngoodbtags(); }
extern "C" const int &jdown_nloosebtags() { return cms3.jdown_nloosebtags(); }
extern "C" const int &jdown_ntightbtags() { return cms3.jdown_ntightbtags(); }
extern "C" const int &jdown_nanalysisbtags() { return cms3.jdown_nanalysisbtags(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jdown_softtags_p4() { return cms3.jdown_softtags_p4(); }
extern "C" const int &jdown_nsoftbtags() { return cms3.jdown_nsoftbtags(); }
extern "C" const float &jdown_ak4_HT() { return cms3.jdown_ak4_HT(); }
extern "C" const float &jdown_ak4_htratiom() { return cms3.jdown_ak4_htratiom(); }
extern "C" const vector<float> &jdown_dphi_ak4pfjet_met() { return cms3.jdown_dphi_ak4pfjet_met(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jdown_ak4pfjets_p4() { return cms3.jdown_ak4pfjets_p4(); }
extern "C" const vector<bool> &jdown_ak4pfjets_passMEDbtag() { return cms3.jdown_ak4pfjets_passMEDbtag(); }
extern "C" const vector<float> &jdown_ak4pfjets_CSV() { return cms3.jdown_ak4pfjets_CSV(); }
extern "C" const vector<float> &jdown_ak4pfjets_mva() { return cms3.jdown_ak4pfjets_mva(); }
extern "C" const vector<int> &jdown_ak4pfjets_parton_flavor() { return cms3.jdown_ak4pfjets_parton_flavor(); }
extern "C" const vector<int> &jdown_ak4pfjets_hadron_flavor() { return cms3.jdown_ak4pfjets_hadron_flavor(); }
extern "C" const vector<bool> &jdown_ak4pfjets_loose_puid() { return cms3.jdown_ak4pfjets_loose_puid(); }
extern "C" const vector<bool> &jdown_ak4pfjets_loose_pfid() { return cms3.jdown_ak4pfjets_loose_pfid(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jdown_ak4pfjets_leadMEDbjet_p4() { return cms3.jdown_ak4pfjets_leadMEDbjet_p4(); }
extern "C" const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jdown_ak4pfjets_leadbtag_p4() { return cms3.jdown_ak4pfjets_leadbtag_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jdown_ak4genjets_p4() { return cms3.jdown_ak4genjets_p4(); }
extern "C" const vector<bool> &genleps_isfromt() { return cms3.genleps_isfromt(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_p4() { return cms3.genleps_p4(); }
extern "C" const vector<int> &genleps_id() { return cms3.genleps_id(); }
extern "C" const vector<int> &genleps__genpsidx() { return cms3.genleps__genpsidx(); }
extern "C" const vector<int> &genleps_status() { return cms3.genleps_status(); }
extern "C" const vector<bool> &genleps_fromHardProcessDecayed() { return cms3.genleps_fromHardProcessDecayed(); }
extern "C" const vector<bool> &genleps_fromHardProcessFinalState() { return cms3.genleps_fromHardProcessFinalState(); }
extern "C" const vector<bool> &genleps_isHardProcess() { return cms3.genleps_isHardProcess(); }
extern "C" const vector<bool> &genleps_isLastCopy() { return cms3.genleps_isLastCopy(); }
extern "C" const vector<int> &genleps_gentaudecay() { return cms3.genleps_gentaudecay(); }
extern "C" const int &gen_nfromtleps_() { return cms3.gen_nfromtleps_(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_motherp4() { return cms3.genleps_motherp4(); }
extern "C" const vector<int> &genleps_motherid() { return cms3.genleps_motherid(); }
extern "C" const vector<int> &genleps_motheridx() { return cms3.genleps_motheridx(); }
extern "C" const vector<int> &genleps_motherstatus() { return cms3.genleps_motherstatus(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_gmotherp4() { return cms3.genleps_gmotherp4(); }
extern "C" const vector<int> &genleps_gmotherid() { return cms3.genleps_gmotherid(); }
extern "C" const vector<int> &genleps_gmotheridx() { return cms3.genleps_gmotheridx(); }
extern "C" const vector<int> &genleps_gmotherstatus() { return cms3.genleps_gmotherstatus(); }
extern "C" const vector<bool> &gennus_isfromt() { return cms3.gennus_isfromt(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4() { return cms3.gennus_p4(); }
extern "C" const vector<int> &gennus_id() { return cms3.gennus_id(); }
extern "C" const vector<int> &gennus__genpsidx() { return cms3.gennus__genpsidx(); }
extern "C" const vector<int> &gennus_status() { return cms3.gennus_status(); }
extern "C" const vector<bool> &gennus_fromHardProcessDecayed() { return cms3.gennus_fromHardProcessDecayed(); }
extern "C" const vector<bool> &gennus_fromHardProcessFinalState() { return cms3.gennus_fromHardProcessFinalState(); }
extern "C" const vector<bool> &gennus_isHardProcess() { return cms3.gennus_isHardProcess(); }
extern "C" const vector<bool> &gennus_isLastCopy() { return cms3.gennus_isLastCopy(); }
extern "C" const vector<int> &gennus_gentaudecay() { return cms3.gennus_gentaudecay(); }
extern "C" const int &gen_nfromtnus_() { return cms3.gen_nfromtnus_(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4() { return cms3.gennus_motherp4(); }
extern "C" const vector<int> &gennus_motherid() { return cms3.gennus_motherid(); }
extern "C" const vector<int> &gennus_motheridx() { return cms3.gennus_motheridx(); }
extern "C" const vector<int> &gennus_motherstatus() { return cms3.gennus_motherstatus(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_gmotherp4() { return cms3.gennus_gmotherp4(); }
extern "C" const vector<int> &gennus_gmotherid() { return cms3.gennus_gmotherid(); }
extern "C" const vector<int> &gennus_gmotheridx() { return cms3.gennus_gmotheridx(); }
extern "C" const vector<int> &gennus_gmotherstatus() { return cms3.gennus_gmotherstatus(); }
extern "C" const vector<bool> &genqs_isfromt() { return cms3.genqs_isfromt(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4() { return cms3.genqs_p4(); }
extern "C" const vector<int> &genqs_id() { return cms3.genqs_id(); }
extern "C" const vector<int> &genqs__genpsidx() { return cms3.genqs__genpsidx(); }
extern "C" const vector<int> &genqs_status() { return cms3.genqs_status(); }
extern "C" const vector<bool> &genqs_fromHardProcessDecayed() { return cms3.genqs_fromHardProcessDecayed(); }
extern "C" const vector<bool> &genqs_fromHardProcessFinalState() { return cms3.genqs_fromHardProcessFinalState(); }
extern "C" const vector<bool> &genqs_isHardProcess() { return cms3.genqs_isHardProcess(); }
extern "C" const vector<bool> &genqs_isLastCopy() { return cms3.genqs_isLastCopy(); }
extern "C" const vector<int> &genqs_gentaudecay() { return cms3.genqs_gentaudecay(); }
extern "C" const int &gen_nfromtqs_() { return cms3.gen_nfromtqs_(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4() { return cms3.genqs_motherp4(); }
extern "C" const vector<int> &genqs_motherid() { return cms3.genqs_motherid(); }
extern "C" const vector<int> &genqs_motheridx() { return cms3.genqs_motheridx(); }
extern "C" const vector<int> &genqs_motherstatus() { return cms3.genqs_motherstatus(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4() { return cms3.genqs_gmotherp4(); }
extern "C" const vector<int> &genqs_gmotherid() { return cms3.genqs_gmotherid(); }
extern "C" const vector<int> &genqs_gmotheridx() { return cms3.genqs_gmotheridx(); }
extern "C" const vector<int> &genqs_gmotherstatus() { return cms3.genqs_gmotherstatus(); }
extern "C" const vector<bool> &genbosons_isfromt() { return cms3.genbosons_isfromt(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_p4() { return cms3.genbosons_p4(); }
extern "C" const vector<int> &genbosons_id() { return cms3.genbosons_id(); }
extern "C" const vector<int> &genbosons__genpsidx() { return cms3.genbosons__genpsidx(); }
extern "C" const vector<int> &genbosons_status() { return cms3.genbosons_status(); }
extern "C" const vector<bool> &genbosons_fromHardProcessDecayed() { return cms3.genbosons_fromHardProcessDecayed(); }
extern "C" const vector<bool> &genbosons_fromHardProcessFinalState() { return cms3.genbosons_fromHardProcessFinalState(); }
extern "C" const vector<bool> &genbosons_isHardProcess() { return cms3.genbosons_isHardProcess(); }
extern "C" const vector<bool> &genbosons_isLastCopy() { return cms3.genbosons_isLastCopy(); }
extern "C" const vector<int> &genbosons_gentaudecay() { return cms3.genbosons_gentaudecay(); }
extern "C" const int &gen_nfromtbosons_() { return cms3.gen_nfromtbosons_(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_motherp4() { return cms3.genbosons_motherp4(); }
extern "C" const vector<int> &genbosons_motherid() { return cms3.genbosons_motherid(); }
extern "C" const vector<int> &genbosons_motheridx() { return cms3.genbosons_motheridx(); }
extern "C" const vector<int> &genbosons_motherstatus() { return cms3.genbosons_motherstatus(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_gmotherp4() { return cms3.genbosons_gmotherp4(); }
extern "C" const vector<int> &genbosons_gmotherid() { return cms3.genbosons_gmotherid(); }
extern "C" const vector<int> &genbosons_gmotheridx() { return cms3.genbosons_gmotheridx(); }
extern "C" const vector<int> &genbosons_gmotherstatus() { return cms3.genbosons_gmotherstatus(); }
extern "C" const vector<bool> &gensusy_isfromt() { return cms3.gensusy_isfromt(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_p4() { return cms3.gensusy_p4(); }
extern "C" const vector<int> &gensusy_id() { return cms3.gensusy_id(); }
extern "C" const vector<int> &gensusy__genpsidx() { return cms3.gensusy__genpsidx(); }
extern "C" const vector<int> &gensusy_status() { return cms3.gensusy_status(); }
extern "C" const vector<bool> &gensusy_fromHardProcessDecayed() { return cms3.gensusy_fromHardProcessDecayed(); }
extern "C" const vector<bool> &gensusy_fromHardProcessFinalState() { return cms3.gensusy_fromHardProcessFinalState(); }
extern "C" const vector<bool> &gensusy_isHardProcess() { return cms3.gensusy_isHardProcess(); }
extern "C" const vector<bool> &gensusy_isLastCopy() { return cms3.gensusy_isLastCopy(); }
extern "C" const vector<int> &gensusy_gentaudecay() { return cms3.gensusy_gentaudecay(); }
extern "C" const int &gen_nfromtsusy_() { return cms3.gen_nfromtsusy_(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_motherp4() { return cms3.gensusy_motherp4(); }
extern "C" const vector<int> &gensusy_motherid() { return cms3.gensusy_motherid(); }
extern "C" const vector<int> &gensusy_motheridx() { return cms3.gensusy_motheridx(); }
extern "C" const vector<int> &gensusy_motherstatus() { return cms3.gensusy_motherstatus(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_gmotherp4() { return cms3.gensusy_gmotherp4(); }
extern "C" const vector<int> &gensusy_gmotherid() { return cms3.gensusy_gmotherid(); }
extern "C" const vector<int> &gensusy_gmotheridx() { return cms3.gensusy_gmotheridx(); }
extern "C" const vector<int> &gensusy_gmotherstatus() { return cms3.gensusy_gmotherstatus(); }
extern "C" const vector<TString> &tau_IDnames() { return cms3.tau_IDnames(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4() { return cms3.tau_leadtrack_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4() { return cms3.tau_leadneutral_p4(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4() { return cms3.tau_p4(); }
extern "C" const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4() { return cms3.tau_isocand_p4(); }
extern "C" const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4() { return cms3.tau_sigcand_p4(); }
extern "C" const vector<vector<float> > &tau_ID() { return cms3.tau_ID(); }
extern "C" const vector<float> &tau_passID() { return cms3.tau_passID(); }
extern "C" const int &ngoodtaus() { return cms3.ngoodtaus(); }
extern "C" const vector<float> &tau_againstMuonTight() { return cms3.tau_againstMuonTight(); }
extern "C" const vector<float> &tau_againstElectronLoose() { return cms3.tau_againstElectronLoose(); }
extern "C" const vector<bool> &tau_isVetoTau() { return cms3.tau_isVetoTau(); }
extern "C" const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isoTracks_p4() { return cms3.isoTracks_p4(); }
extern "C" const vector<int> &isoTracks_charge() { return cms3.isoTracks_charge(); }
extern "C" const vector<float> &isoTracks_absIso() { return cms3.isoTracks_absIso(); }
extern "C" const vector<float> &isoTracks_dz() { return cms3.isoTracks_dz(); }
extern "C" const vector<int> &isoTracks_pdgId() { return cms3.isoTracks_pdgId(); }
extern "C" const vector<bool> &isoTracks_isVetoTrack() { return cms3.isoTracks_isVetoTrack(); }
extern "C" const vector<bool> &isoTracks_isVetoTrack_v2() { return cms3.isoTracks_isVetoTrack_v2(); }
extern "C" const vector<bool> &isoTracks_isVetoTrack_v3() { return cms3.isoTracks_isVetoTrack_v3(); }
extern "C" const float &filt_cscbeamhalo() { return cms3.filt_cscbeamhalo(); }
extern "C" const float &filt_cscbeamhalo2015() { return cms3.filt_cscbeamhalo2015(); }
extern "C" const float &filt_globaltighthalo2016() { return cms3.filt_globaltighthalo2016(); }
extern "C" const float &filt_globalsupertighthalo2016() { return cms3.filt_globalsupertighthalo2016(); }
extern "C" const float &filt_ecallaser() { return cms3.filt_ecallaser(); }
extern "C" const float &filt_ecaltp() { return cms3.filt_ecaltp(); }
extern "C" const float &filt_eebadsc() { return cms3.filt_eebadsc(); }
extern "C" const float &filt_goodvtx() { return cms3.filt_goodvtx(); }
extern "C" const float &filt_badevents() { return cms3.filt_badevents(); }
extern "C" const float &filt_hbhenoise() { return cms3.filt_hbhenoise(); }
extern "C" const float &filt_hbheisonoise() { return cms3.filt_hbheisonoise(); }
extern "C" const float &filt_hcallaser() { return cms3.filt_hcallaser(); }
extern "C" const float &filt_trkfail() { return cms3.filt_trkfail(); }
extern "C" const float &filt_trkPOG() { return cms3.filt_trkPOG(); }
extern "C" const float &filt_trkPOG_logerr_tmc() { return cms3.filt_trkPOG_logerr_tmc(); }
extern "C" const float &filt_trkPOG_tmc() { return cms3.filt_trkPOG_tmc(); }
extern "C" const float &filt_trkPOG_tms() { return cms3.filt_trkPOG_tms(); }
extern "C" const int &firstGoodVtxIdx() { return cms3.firstGoodVtxIdx(); }
extern "C" const float &filt_badChargedCandidateFilter() { return cms3.filt_badChargedCandidateFilter(); }
extern "C" const float &filt_badMuonFilter() { return cms3.filt_badMuonFilter(); }
extern "C" const float &filt_met() { return cms3.filt_met(); }
extern "C" const bool &filt_fastsimjets() { return cms3.filt_fastsimjets(); }
extern "C" const bool &filt_fastsimjets_jup() { return cms3.filt_fastsimjets_jup(); }
extern "C" const bool &filt_fastsimjets_jdown() { return cms3.filt_fastsimjets_jdown(); }
extern "C" const bool &filt_jetWithBadMuon() { return cms3.filt_jetWithBadMuon(); }
extern "C" const bool &filt_jetWithBadMuon_jup() { return cms3.filt_jetWithBadMuon_jup(); }
extern "C" const bool &filt_jetWithBadMuon_jdown() { return cms3.filt_jetWithBadMuon_jdown(); }
extern "C" const bool &filt_pfovercalomet() { return cms3.filt_pfovercalomet(); }
extern "C" const bool &filt_badmuons() { return cms3.filt_badmuons(); }
extern "C" const bool &filt_duplicatemuons() { return cms3.filt_duplicatemuons(); }
extern "C" const bool &filt_nobadmuons() { return cms3.filt_nobadmuons(); }

}


extern "C"
{

}
