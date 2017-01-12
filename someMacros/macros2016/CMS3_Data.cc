#include "CMS3_Data.h"
CMS3 cms3;

void CMS3::Init(TTree *tree) {
	firstVtx_posp4_branch = 0;
	if (tree->GetBranch("firstVtx_posp4") != 0) {
		firstVtx_posp4_branch = tree->GetBranch("firstVtx_posp4");
		if (firstVtx_posp4_branch) {firstVtx_posp4_branch->SetAddress(&firstVtx_posp4_);}
	}
	Zll_p4l1_branch = 0;
	if (tree->GetBranch("Zll_p4l1") != 0) {
		Zll_p4l1_branch = tree->GetBranch("Zll_p4l1");
		if (Zll_p4l1_branch) {Zll_p4l1_branch->SetAddress(&Zll_p4l1_);}
	}
	Zll_p4l2_branch = 0;
	if (tree->GetBranch("Zll_p4l2") != 0) {
		Zll_p4l2_branch = tree->GetBranch("Zll_p4l2");
		if (Zll_p4l2_branch) {Zll_p4l2_branch->SetAddress(&Zll_p4l2_);}
	}
	Zll_p4_branch = 0;
	if (tree->GetBranch("Zll_p4") != 0) {
		Zll_p4_branch = tree->GetBranch("Zll_p4");
		if (Zll_p4_branch) {Zll_p4_branch->SetAddress(&Zll_p4_);}
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
	ph_p4_branch = 0;
	if (tree->GetBranch("ph_p4") != 0) {
		ph_p4_branch = tree->GetBranch("ph_p4");
		if (ph_p4_branch) {ph_p4_branch->SetAddress(&ph_p4_);}
	}
	ph_mcp4_branch = 0;
	if (tree->GetBranch("ph_mcp4") != 0) {
		ph_mcp4_branch = tree->GetBranch("ph_mcp4");
		if (ph_mcp4_branch) {ph_mcp4_branch->SetAddress(&ph_mcp4_);}
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
	genleps_p4_branch = 0;
	if (tree->GetBranch("genleps_p4") != 0) {
		genleps_p4_branch = tree->GetBranch("genleps_p4");
		if (genleps_p4_branch) {genleps_p4_branch->SetAddress(&genleps_p4_);}
	}
	genleps_motherp4_branch = 0;
	if (tree->GetBranch("genleps_motherp4") != 0) {
		genleps_motherp4_branch = tree->GetBranch("genleps_motherp4");
		if (genleps_motherp4_branch) {genleps_motherp4_branch->SetAddress(&genleps_motherp4_);}
	}
	genleps_gmotherp4_branch = 0;
	if (tree->GetBranch("genleps_gmotherp4") != 0) {
		genleps_gmotherp4_branch = tree->GetBranch("genleps_gmotherp4");
		if (genleps_gmotherp4_branch) {genleps_gmotherp4_branch->SetAddress(&genleps_gmotherp4_);}
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
	gennus_gmotherp4_branch = 0;
	if (tree->GetBranch("gennus_gmotherp4") != 0) {
		gennus_gmotherp4_branch = tree->GetBranch("gennus_gmotherp4");
		if (gennus_gmotherp4_branch) {gennus_gmotherp4_branch->SetAddress(&gennus_gmotherp4_);}
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
	genbosons_p4_branch = 0;
	if (tree->GetBranch("genbosons_p4") != 0) {
		genbosons_p4_branch = tree->GetBranch("genbosons_p4");
		if (genbosons_p4_branch) {genbosons_p4_branch->SetAddress(&genbosons_p4_);}
	}
	genbosons_motherp4_branch = 0;
	if (tree->GetBranch("genbosons_motherp4") != 0) {
		genbosons_motherp4_branch = tree->GetBranch("genbosons_motherp4");
		if (genbosons_motherp4_branch) {genbosons_motherp4_branch->SetAddress(&genbosons_motherp4_);}
	}
	genbosons_gmotherp4_branch = 0;
	if (tree->GetBranch("genbosons_gmotherp4") != 0) {
		genbosons_gmotherp4_branch = tree->GetBranch("genbosons_gmotherp4");
		if (genbosons_gmotherp4_branch) {genbosons_gmotherp4_branch->SetAddress(&genbosons_gmotherp4_);}
	}
	gensusy_p4_branch = 0;
	if (tree->GetBranch("gensusy_p4") != 0) {
		gensusy_p4_branch = tree->GetBranch("gensusy_p4");
		if (gensusy_p4_branch) {gensusy_p4_branch->SetAddress(&gensusy_p4_);}
	}
	gensusy_motherp4_branch = 0;
	if (tree->GetBranch("gensusy_motherp4") != 0) {
		gensusy_motherp4_branch = tree->GetBranch("gensusy_motherp4");
		if (gensusy_motherp4_branch) {gensusy_motherp4_branch->SetAddress(&gensusy_motherp4_);}
	}
	gensusy_gmotherp4_branch = 0;
	if (tree->GetBranch("gensusy_gmotherp4") != 0) {
		gensusy_gmotherp4_branch = tree->GetBranch("gensusy_gmotherp4");
		if (gensusy_gmotherp4_branch) {gensusy_gmotherp4_branch->SetAddress(&gensusy_gmotherp4_);}
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
	filt_badevents_branch = 0;
	if (tree->GetBranch("filt_badevents") != 0) {
		filt_badevents_branch = tree->GetBranch("filt_badevents");
		if (filt_badevents_branch) {filt_badevents_branch->SetAddress(&filt_badevents_);}
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
	xsec_uncert_branch = 0;
	if (tree->GetBranch("xsec_uncert") != 0) {
		xsec_uncert_branch = tree->GetBranch("xsec_uncert");
		if (xsec_uncert_branch) {xsec_uncert_branch->SetAddress(&xsec_uncert_);}
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
	nlooseleps_branch = 0;
	if (tree->GetBranch("nlooseleps") != 0) {
		nlooseleps_branch = tree->GetBranch("nlooseleps");
		if (nlooseleps_branch) {nlooseleps_branch->SetAddress(&nlooseleps_);}
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
	genLepsHardProcess_branch = 0;
	if (tree->GetBranch("genLepsHardProcess") != 0) {
		genLepsHardProcess_branch = tree->GetBranch("genLepsHardProcess");
		if (genLepsHardProcess_branch) {genLepsHardProcess_branch->SetAddress(&genLepsHardProcess_);}
	}
	genNusHardProcess_branch = 0;
	if (tree->GetBranch("genNusHardProcess") != 0) {
		genNusHardProcess_branch = tree->GetBranch("genNusHardProcess");
		if (genNusHardProcess_branch) {genNusHardProcess_branch->SetAddress(&genNusHardProcess_);}
	}
	is0lep_branch = 0;
	if (tree->GetBranch("is0lep") != 0) {
		is0lep_branch = tree->GetBranch("is0lep");
		if (is0lep_branch) {is0lep_branch->SetAddress(&is0lep_);}
	}
	is1lep_branch = 0;
	if (tree->GetBranch("is1lep") != 0) {
		is1lep_branch = tree->GetBranch("is1lep");
		if (is1lep_branch) {is1lep_branch->SetAddress(&is1lep_);}
	}
	is2lep_branch = 0;
	if (tree->GetBranch("is2lep") != 0) {
		is2lep_branch = tree->GetBranch("is2lep");
		if (is2lep_branch) {is2lep_branch->SetAddress(&is2lep_);}
	}
	isZtoNuNu_branch = 0;
	if (tree->GetBranch("isZtoNuNu") != 0) {
		isZtoNuNu_branch = tree->GetBranch("isZtoNuNu");
		if (isZtoNuNu_branch) {isZtoNuNu_branch->SetAddress(&isZtoNuNu_);}
	}
	is1lepFromW_branch = 0;
	if (tree->GetBranch("is1lepFromW") != 0) {
		is1lepFromW_branch = tree->GetBranch("is1lepFromW");
		if (is1lepFromW_branch) {is1lepFromW_branch->SetAddress(&is1lepFromW_);}
	}
	is1lepFromTop_branch = 0;
	if (tree->GetBranch("is1lepFromTop") != 0) {
		is1lepFromTop_branch = tree->GetBranch("is1lepFromTop");
		if (is1lepFromTop_branch) {is1lepFromTop_branch->SetAddress(&is1lepFromTop_);}
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
	pdf_up_weight_branch = 0;
	if (tree->GetBranch("pdf_up_weight") != 0) {
		pdf_up_weight_branch = tree->GetBranch("pdf_up_weight");
		if (pdf_up_weight_branch) {pdf_up_weight_branch->SetAddress(&pdf_up_weight_);}
	}
	pdf_down_weight_branch = 0;
	if (tree->GetBranch("pdf_down_weight") != 0) {
		pdf_down_weight_branch = tree->GetBranch("pdf_down_weight");
		if (pdf_down_weight_branch) {pdf_down_weight_branch->SetAddress(&pdf_down_weight_);}
	}
	genweightsID_branch = 0;
	if (tree->GetBranch("genweightsID") != 0) {
		genweightsID_branch = tree->GetBranch("genweightsID");
		if (genweightsID_branch) {genweightsID_branch->SetAddress(&genweightsID_);}
	}
	genweights_branch = 0;
	if (tree->GetBranch("genweights") != 0) {
		genweights_branch = tree->GetBranch("genweights");
		if (genweights_branch) {genweights_branch->SetAddress(&genweights_);}
	}
	weight_btagsf_branch = 0;
	if (tree->GetBranch("weight_btagsf") != 0) {
		weight_btagsf_branch = tree->GetBranch("weight_btagsf");
		if (weight_btagsf_branch) {weight_btagsf_branch->SetAddress(&weight_btagsf_);}
	}
	weight_btagsf_heavy_UP_branch = 0;
	if (tree->GetBranch("weight_btagsf_heavy_UP") != 0) {
		weight_btagsf_heavy_UP_branch = tree->GetBranch("weight_btagsf_heavy_UP");
		if (weight_btagsf_heavy_UP_branch) {weight_btagsf_heavy_UP_branch->SetAddress(&weight_btagsf_heavy_UP_);}
	}
	weight_btagsf_light_UP_branch = 0;
	if (tree->GetBranch("weight_btagsf_light_UP") != 0) {
		weight_btagsf_light_UP_branch = tree->GetBranch("weight_btagsf_light_UP");
		if (weight_btagsf_light_UP_branch) {weight_btagsf_light_UP_branch->SetAddress(&weight_btagsf_light_UP_);}
	}
	weight_btagsf_heavy_DN_branch = 0;
	if (tree->GetBranch("weight_btagsf_heavy_DN") != 0) {
		weight_btagsf_heavy_DN_branch = tree->GetBranch("weight_btagsf_heavy_DN");
		if (weight_btagsf_heavy_DN_branch) {weight_btagsf_heavy_DN_branch->SetAddress(&weight_btagsf_heavy_DN_);}
	}
	weight_btagsf_light_DN_branch = 0;
	if (tree->GetBranch("weight_btagsf_light_DN") != 0) {
		weight_btagsf_light_DN_branch = tree->GetBranch("weight_btagsf_light_DN");
		if (weight_btagsf_light_DN_branch) {weight_btagsf_light_DN_branch->SetAddress(&weight_btagsf_light_DN_);}
	}
	weight_ISR_branch = 0;
	if (tree->GetBranch("weight_ISR") != 0) {
		weight_ISR_branch = tree->GetBranch("weight_ISR");
		if (weight_ISR_branch) {weight_ISR_branch->SetAddress(&weight_ISR_);}
	}
	weight_ISRup_branch = 0;
	if (tree->GetBranch("weight_ISRup") != 0) {
		weight_ISRup_branch = tree->GetBranch("weight_ISRup");
		if (weight_ISRup_branch) {weight_ISRup_branch->SetAddress(&weight_ISRup_);}
	}
	weight_ISRdown_branch = 0;
	if (tree->GetBranch("weight_ISRdown") != 0) {
		weight_ISRdown_branch = tree->GetBranch("weight_ISRdown");
		if (weight_ISRdown_branch) {weight_ISRdown_branch->SetAddress(&weight_ISRdown_);}
	}
	weight_PU_branch = 0;
	if (tree->GetBranch("weight_PU") != 0) {
		weight_PU_branch = tree->GetBranch("weight_PU");
		if (weight_PU_branch) {weight_PU_branch->SetAddress(&weight_PU_);}
	}
	weight_PUup_branch = 0;
	if (tree->GetBranch("weight_PUup") != 0) {
		weight_PUup_branch = tree->GetBranch("weight_PUup");
		if (weight_PUup_branch) {weight_PUup_branch->SetAddress(&weight_PUup_);}
	}
	weight_PUdown_branch = 0;
	if (tree->GetBranch("weight_PUdown") != 0) {
		weight_PUdown_branch = tree->GetBranch("weight_PUdown");
		if (weight_PUdown_branch) {weight_PUdown_branch->SetAddress(&weight_PUdown_);}
	}
	hardgenpt_branch = 0;
	if (tree->GetBranch("hardgenpt") != 0) {
		hardgenpt_branch = tree->GetBranch("hardgenpt");
		if (hardgenpt_branch) {hardgenpt_branch->SetAddress(&hardgenpt_);}
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
	genht_branch = 0;
	if (tree->GetBranch("genht") != 0) {
		genht_branch = tree->GetBranch("genht");
		if (genht_branch) {genht_branch->SetAddress(&genht_);}
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
	HLT_DiEl_17_12_branch = 0;
	if (tree->GetBranch("HLT_DiEl_17_12") != 0) {
		HLT_DiEl_17_12_branch = tree->GetBranch("HLT_DiEl_17_12");
		if (HLT_DiEl_17_12_branch) {HLT_DiEl_17_12_branch->SetAddress(&HLT_DiEl_17_12_);}
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
	HLT_SingleEl23_branch = 0;
	if (tree->GetBranch("HLT_SingleEl23") != 0) {
		HLT_SingleEl23_branch = tree->GetBranch("HLT_SingleEl23");
		if (HLT_SingleEl23_branch) {HLT_SingleEl23_branch->SetAddress(&HLT_SingleEl23_);}
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
	HLT_SingleMu18_branch = 0;
	if (tree->GetBranch("HLT_SingleMu18") != 0) {
		HLT_SingleMu18_branch = tree->GetBranch("HLT_SingleMu18");
		if (HLT_SingleMu18_branch) {HLT_SingleMu18_branch->SetAddress(&HLT_SingleMu18_);}
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
	HLT_Photon90_CaloIdL_PFHT500_branch = 0;
	if (tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500") != 0) {
		HLT_Photon90_CaloIdL_PFHT500_branch = tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500");
		if (HLT_Photon90_CaloIdL_PFHT500_branch) {HLT_Photon90_CaloIdL_PFHT500_branch->SetAddress(&HLT_Photon90_CaloIdL_PFHT500_);}
	}
	HLT_Photon22_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon22_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon22_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon22_R9Id90_HE10_IsoM");
		if (HLT_Photon22_R9Id90_HE10_IsoM_branch) {HLT_Photon22_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon22_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon30_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon30_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon30_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon30_R9Id90_HE10_IsoM");
		if (HLT_Photon30_R9Id90_HE10_IsoM_branch) {HLT_Photon30_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon30_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon36_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon36_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon36_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon36_R9Id90_HE10_IsoM");
		if (HLT_Photon36_R9Id90_HE10_IsoM_branch) {HLT_Photon36_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon36_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon50_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon50_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon50_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon50_R9Id90_HE10_IsoM");
		if (HLT_Photon50_R9Id90_HE10_IsoM_branch) {HLT_Photon50_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon50_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon75_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon75_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon75_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon75_R9Id90_HE10_IsoM");
		if (HLT_Photon75_R9Id90_HE10_IsoM_branch) {HLT_Photon75_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon75_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon90_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon90_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon90_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon90_R9Id90_HE10_IsoM");
		if (HLT_Photon90_R9Id90_HE10_IsoM_branch) {HLT_Photon90_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon90_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon120_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon120_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon120_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon120_R9Id90_HE10_IsoM");
		if (HLT_Photon120_R9Id90_HE10_IsoM_branch) {HLT_Photon120_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon120_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon165_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon165_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon165_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon165_R9Id90_HE10_IsoM");
		if (HLT_Photon165_R9Id90_HE10_IsoM_branch) {HLT_Photon165_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon165_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon175_branch = 0;
	if (tree->GetBranch("HLT_Photon175") != 0) {
		HLT_Photon175_branch = tree->GetBranch("HLT_Photon175");
		if (HLT_Photon175_branch) {HLT_Photon175_branch->SetAddress(&HLT_Photon175_);}
	}
	HLT_Photon165_HE10_branch = 0;
	if (tree->GetBranch("HLT_Photon165_HE10") != 0) {
		HLT_Photon165_HE10_branch = tree->GetBranch("HLT_Photon165_HE10");
		if (HLT_Photon165_HE10_branch) {HLT_Photon165_HE10_branch->SetAddress(&HLT_Photon165_HE10_);}
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
	nPhotons_branch = 0;
	if (tree->GetBranch("nPhotons") != 0) {
		nPhotons_branch = tree->GetBranch("nPhotons");
		if (nPhotons_branch) {nPhotons_branch->SetAddress(&nPhotons_);}
	}
	ph_selectedidx_branch = 0;
	if (tree->GetBranch("ph_selectedidx") != 0) {
		ph_selectedidx_branch = tree->GetBranch("ph_selectedidx");
		if (ph_selectedidx_branch) {ph_selectedidx_branch->SetAddress(&ph_selectedidx_);}
	}
	ph_ngoodjets_branch = 0;
	if (tree->GetBranch("ph_ngoodjets") != 0) {
		ph_ngoodjets_branch = tree->GetBranch("ph_ngoodjets");
		if (ph_ngoodjets_branch) {ph_ngoodjets_branch->SetAddress(&ph_ngoodjets_);}
	}
	ph_ngoodbtags_branch = 0;
	if (tree->GetBranch("ph_ngoodbtags") != 0) {
		ph_ngoodbtags_branch = tree->GetBranch("ph_ngoodbtags");
		if (ph_ngoodbtags_branch) {ph_ngoodbtags_branch->SetAddress(&ph_ngoodbtags_);}
	}
	ph_met_branch = 0;
	if (tree->GetBranch("ph_met") != 0) {
		ph_met_branch = tree->GetBranch("ph_met");
		if (ph_met_branch) {ph_met_branch->SetAddress(&ph_met_);}
	}
	ph_met_phi_branch = 0;
	if (tree->GetBranch("ph_met_phi") != 0) {
		ph_met_phi_branch = tree->GetBranch("ph_met_phi");
		if (ph_met_phi_branch) {ph_met_phi_branch->SetAddress(&ph_met_phi_);}
	}
	ph_HT_branch = 0;
	if (tree->GetBranch("ph_HT") != 0) {
		ph_HT_branch = tree->GetBranch("ph_HT");
		if (ph_HT_branch) {ph_HT_branch->SetAddress(&ph_HT_);}
	}
	ph_htssm_branch = 0;
	if (tree->GetBranch("ph_htssm") != 0) {
		ph_htssm_branch = tree->GetBranch("ph_htssm");
		if (ph_htssm_branch) {ph_htssm_branch->SetAddress(&ph_htssm_);}
	}
	ph_htosm_branch = 0;
	if (tree->GetBranch("ph_htosm") != 0) {
		ph_htosm_branch = tree->GetBranch("ph_htosm");
		if (ph_htosm_branch) {ph_htosm_branch->SetAddress(&ph_htosm_);}
	}
	ph_htratiom_branch = 0;
	if (tree->GetBranch("ph_htratiom") != 0) {
		ph_htratiom_branch = tree->GetBranch("ph_htratiom");
		if (ph_htratiom_branch) {ph_htratiom_branch->SetAddress(&ph_htratiom_);}
	}
	ph_mt_met_lep_branch = 0;
	if (tree->GetBranch("ph_mt_met_lep") != 0) {
		ph_mt_met_lep_branch = tree->GetBranch("ph_mt_met_lep");
		if (ph_mt_met_lep_branch) {ph_mt_met_lep_branch->SetAddress(&ph_mt_met_lep_);}
	}
	ph_dphi_Wlep_branch = 0;
	if (tree->GetBranch("ph_dphi_Wlep") != 0) {
		ph_dphi_Wlep_branch = tree->GetBranch("ph_dphi_Wlep");
		if (ph_dphi_Wlep_branch) {ph_dphi_Wlep_branch->SetAddress(&ph_dphi_Wlep_);}
	}
	ph_MT2W_branch = 0;
	if (tree->GetBranch("ph_MT2W") != 0) {
		ph_MT2W_branch = tree->GetBranch("ph_MT2W");
		if (ph_MT2W_branch) {ph_MT2W_branch->SetAddress(&ph_MT2W_);}
	}
	ph_topness_branch = 0;
	if (tree->GetBranch("ph_topness") != 0) {
		ph_topness_branch = tree->GetBranch("ph_topness");
		if (ph_topness_branch) {ph_topness_branch->SetAddress(&ph_topness_);}
	}
	ph_topnessMod_branch = 0;
	if (tree->GetBranch("ph_topnessMod") != 0) {
		ph_topnessMod_branch = tree->GetBranch("ph_topnessMod");
		if (ph_topnessMod_branch) {ph_topnessMod_branch->SetAddress(&ph_topnessMod_);}
	}
	ph_MT2_lb_b_mass_branch = 0;
	if (tree->GetBranch("ph_MT2_lb_b_mass") != 0) {
		ph_MT2_lb_b_mass_branch = tree->GetBranch("ph_MT2_lb_b_mass");
		if (ph_MT2_lb_b_mass_branch) {ph_MT2_lb_b_mass_branch->SetAddress(&ph_MT2_lb_b_mass_);}
	}
	ph_MT2_lb_b_branch = 0;
	if (tree->GetBranch("ph_MT2_lb_b") != 0) {
		ph_MT2_lb_b_branch = tree->GetBranch("ph_MT2_lb_b");
		if (ph_MT2_lb_b_branch) {ph_MT2_lb_b_branch->SetAddress(&ph_MT2_lb_b_);}
	}
	ph_MT2_lb_bqq_mass_branch = 0;
	if (tree->GetBranch("ph_MT2_lb_bqq_mass") != 0) {
		ph_MT2_lb_bqq_mass_branch = tree->GetBranch("ph_MT2_lb_bqq_mass");
		if (ph_MT2_lb_bqq_mass_branch) {ph_MT2_lb_bqq_mass_branch->SetAddress(&ph_MT2_lb_bqq_mass_);}
	}
	ph_MT2_lb_bqq_branch = 0;
	if (tree->GetBranch("ph_MT2_lb_bqq") != 0) {
		ph_MT2_lb_bqq_branch = tree->GetBranch("ph_MT2_lb_bqq");
		if (ph_MT2_lb_bqq_branch) {ph_MT2_lb_bqq_branch->SetAddress(&ph_MT2_lb_bqq_);}
	}
	ph_hadronic_top_chi2_branch = 0;
	if (tree->GetBranch("ph_hadronic_top_chi2") != 0) {
		ph_hadronic_top_chi2_branch = tree->GetBranch("ph_hadronic_top_chi2");
		if (ph_hadronic_top_chi2_branch) {ph_hadronic_top_chi2_branch->SetAddress(&ph_hadronic_top_chi2_);}
	}
	ph_mindphi_met_j1_j2_branch = 0;
	if (tree->GetBranch("ph_mindphi_met_j1_j2") != 0) {
		ph_mindphi_met_j1_j2_branch = tree->GetBranch("ph_mindphi_met_j1_j2");
		if (ph_mindphi_met_j1_j2_branch) {ph_mindphi_met_j1_j2_branch->SetAddress(&ph_mindphi_met_j1_j2_);}
	}
	ph_Mlb_lead_bdiscr_branch = 0;
	if (tree->GetBranch("ph_Mlb_lead_bdiscr") != 0) {
		ph_Mlb_lead_bdiscr_branch = tree->GetBranch("ph_Mlb_lead_bdiscr");
		if (ph_Mlb_lead_bdiscr_branch) {ph_Mlb_lead_bdiscr_branch->SetAddress(&ph_Mlb_lead_bdiscr_);}
	}
	ph_dR_lep_leadb_branch = 0;
	if (tree->GetBranch("ph_dR_lep_leadb") != 0) {
		ph_dR_lep_leadb_branch = tree->GetBranch("ph_dR_lep_leadb");
		if (ph_dR_lep_leadb_branch) {ph_dR_lep_leadb_branch->SetAddress(&ph_dR_lep_leadb_);}
	}
	ph_Mlb_closestb_branch = 0;
	if (tree->GetBranch("ph_Mlb_closestb") != 0) {
		ph_Mlb_closestb_branch = tree->GetBranch("ph_Mlb_closestb");
		if (ph_Mlb_closestb_branch) {ph_Mlb_closestb_branch->SetAddress(&ph_Mlb_closestb_);}
	}
	ph_Mjjj_branch = 0;
	if (tree->GetBranch("ph_Mjjj") != 0) {
		ph_Mjjj_branch = tree->GetBranch("ph_Mjjj");
		if (ph_Mjjj_branch) {ph_Mjjj_branch->SetAddress(&ph_Mjjj_);}
	}
	Zll_idl1_branch = 0;
	if (tree->GetBranch("Zll_idl1") != 0) {
		Zll_idl1_branch = tree->GetBranch("Zll_idl1");
		if (Zll_idl1_branch) {Zll_idl1_branch->SetAddress(&Zll_idl1_);}
	}
	Zll_idl2_branch = 0;
	if (tree->GetBranch("Zll_idl2") != 0) {
		Zll_idl2_branch = tree->GetBranch("Zll_idl2");
		if (Zll_idl2_branch) {Zll_idl2_branch->SetAddress(&Zll_idl2_);}
	}
	Zll_OS_branch = 0;
	if (tree->GetBranch("Zll_OS") != 0) {
		Zll_OS_branch = tree->GetBranch("Zll_OS");
		if (Zll_OS_branch) {Zll_OS_branch->SetAddress(&Zll_OS_);}
	}
	Zll_SF_branch = 0;
	if (tree->GetBranch("Zll_SF") != 0) {
		Zll_SF_branch = tree->GetBranch("Zll_SF");
		if (Zll_SF_branch) {Zll_SF_branch->SetAddress(&Zll_SF_);}
	}
	Zll_isZmass_branch = 0;
	if (tree->GetBranch("Zll_isZmass") != 0) {
		Zll_isZmass_branch = tree->GetBranch("Zll_isZmass");
		if (Zll_isZmass_branch) {Zll_isZmass_branch->SetAddress(&Zll_isZmass_);}
	}
	Zll_M_branch = 0;
	if (tree->GetBranch("Zll_M") != 0) {
		Zll_M_branch = tree->GetBranch("Zll_M");
		if (Zll_M_branch) {Zll_M_branch->SetAddress(&Zll_M_);}
	}
	Zll_selLep_branch = 0;
	if (tree->GetBranch("Zll_selLep") != 0) {
		Zll_selLep_branch = tree->GetBranch("Zll_selLep");
		if (Zll_selLep_branch) {Zll_selLep_branch->SetAddress(&Zll_selLep_);}
	}
	Zll_met_branch = 0;
	if (tree->GetBranch("Zll_met") != 0) {
		Zll_met_branch = tree->GetBranch("Zll_met");
		if (Zll_met_branch) {Zll_met_branch->SetAddress(&Zll_met_);}
	}
	Zll_met_phi_branch = 0;
	if (tree->GetBranch("Zll_met_phi") != 0) {
		Zll_met_phi_branch = tree->GetBranch("Zll_met_phi");
		if (Zll_met_phi_branch) {Zll_met_phi_branch->SetAddress(&Zll_met_phi_);}
	}
	Zll_mindphi_met_j1_j2_branch = 0;
	if (tree->GetBranch("Zll_mindphi_met_j1_j2") != 0) {
		Zll_mindphi_met_j1_j2_branch = tree->GetBranch("Zll_mindphi_met_j1_j2");
		if (Zll_mindphi_met_j1_j2_branch) {Zll_mindphi_met_j1_j2_branch->SetAddress(&Zll_mindphi_met_j1_j2_);}
	}
	Zll_mt_met_lep_branch = 0;
	if (tree->GetBranch("Zll_mt_met_lep") != 0) {
		Zll_mt_met_lep_branch = tree->GetBranch("Zll_mt_met_lep");
		if (Zll_mt_met_lep_branch) {Zll_mt_met_lep_branch->SetAddress(&Zll_mt_met_lep_);}
	}
	Zll_dphi_Wlep_branch = 0;
	if (tree->GetBranch("Zll_dphi_Wlep") != 0) {
		Zll_dphi_Wlep_branch = tree->GetBranch("Zll_dphi_Wlep");
		if (Zll_dphi_Wlep_branch) {Zll_dphi_Wlep_branch->SetAddress(&Zll_dphi_Wlep_);}
	}
	Zll_MT2W_branch = 0;
	if (tree->GetBranch("Zll_MT2W") != 0) {
		Zll_MT2W_branch = tree->GetBranch("Zll_MT2W");
		if (Zll_MT2W_branch) {Zll_MT2W_branch->SetAddress(&Zll_MT2W_);}
	}
	Zll_topness_branch = 0;
	if (tree->GetBranch("Zll_topness") != 0) {
		Zll_topness_branch = tree->GetBranch("Zll_topness");
		if (Zll_topness_branch) {Zll_topness_branch->SetAddress(&Zll_topness_);}
	}
	Zll_topnessMod_branch = 0;
	if (tree->GetBranch("Zll_topnessMod") != 0) {
		Zll_topnessMod_branch = tree->GetBranch("Zll_topnessMod");
		if (Zll_topnessMod_branch) {Zll_topnessMod_branch->SetAddress(&Zll_topnessMod_);}
	}
	Zll_MT2_lb_b_mass_branch = 0;
	if (tree->GetBranch("Zll_MT2_lb_b_mass") != 0) {
		Zll_MT2_lb_b_mass_branch = tree->GetBranch("Zll_MT2_lb_b_mass");
		if (Zll_MT2_lb_b_mass_branch) {Zll_MT2_lb_b_mass_branch->SetAddress(&Zll_MT2_lb_b_mass_);}
	}
	Zll_MT2_lb_b_branch = 0;
	if (tree->GetBranch("Zll_MT2_lb_b") != 0) {
		Zll_MT2_lb_b_branch = tree->GetBranch("Zll_MT2_lb_b");
		if (Zll_MT2_lb_b_branch) {Zll_MT2_lb_b_branch->SetAddress(&Zll_MT2_lb_b_);}
	}
	Zll_MT2_lb_bqq_mass_branch = 0;
	if (tree->GetBranch("Zll_MT2_lb_bqq_mass") != 0) {
		Zll_MT2_lb_bqq_mass_branch = tree->GetBranch("Zll_MT2_lb_bqq_mass");
		if (Zll_MT2_lb_bqq_mass_branch) {Zll_MT2_lb_bqq_mass_branch->SetAddress(&Zll_MT2_lb_bqq_mass_);}
	}
	Zll_MT2_lb_bqq_branch = 0;
	if (tree->GetBranch("Zll_MT2_lb_bqq") != 0) {
		Zll_MT2_lb_bqq_branch = tree->GetBranch("Zll_MT2_lb_bqq");
		if (Zll_MT2_lb_bqq_branch) {Zll_MT2_lb_bqq_branch->SetAddress(&Zll_MT2_lb_bqq_);}
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
	ph_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("ph_sigmaIEtaEta_fill5x5") != 0) {
		ph_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("ph_sigmaIEtaEta_fill5x5");
		if (ph_sigmaIEtaEta_fill5x5_branch) {ph_sigmaIEtaEta_fill5x5_branch->SetAddress(&ph_sigmaIEtaEta_fill5x5_);}
	}
	ph_hOverE_branch = 0;
	if (tree->GetBranch("ph_hOverE") != 0) {
		ph_hOverE_branch = tree->GetBranch("ph_hOverE");
		if (ph_hOverE_branch) {ph_hOverE_branch->SetAddress(&ph_hOverE_);}
	}
	ph_r9_branch = 0;
	if (tree->GetBranch("ph_r9") != 0) {
		ph_r9_branch = tree->GetBranch("ph_r9");
		if (ph_r9_branch) {ph_r9_branch->SetAddress(&ph_r9_);}
	}
	ph_chiso_branch = 0;
	if (tree->GetBranch("ph_chiso") != 0) {
		ph_chiso_branch = tree->GetBranch("ph_chiso");
		if (ph_chiso_branch) {ph_chiso_branch->SetAddress(&ph_chiso_);}
	}
	ph_nhiso_branch = 0;
	if (tree->GetBranch("ph_nhiso") != 0) {
		ph_nhiso_branch = tree->GetBranch("ph_nhiso");
		if (ph_nhiso_branch) {ph_nhiso_branch->SetAddress(&ph_nhiso_);}
	}
	ph_phiso_branch = 0;
	if (tree->GetBranch("ph_phiso") != 0) {
		ph_phiso_branch = tree->GetBranch("ph_phiso");
		if (ph_phiso_branch) {ph_phiso_branch->SetAddress(&ph_phiso_);}
	}
	ph_idCutBased_branch = 0;
	if (tree->GetBranch("ph_idCutBased") != 0) {
		ph_idCutBased_branch = tree->GetBranch("ph_idCutBased");
		if (ph_idCutBased_branch) {ph_idCutBased_branch->SetAddress(&ph_idCutBased_);}
	}
	ph_overlapJetId_branch = 0;
	if (tree->GetBranch("ph_overlapJetId") != 0) {
		ph_overlapJetId_branch = tree->GetBranch("ph_overlapJetId");
		if (ph_overlapJetId_branch) {ph_overlapJetId_branch->SetAddress(&ph_overlapJetId_);}
	}
	ph_pt_branch = 0;
	if (tree->GetBranch("ph_pt") != 0) {
		ph_pt_branch = tree->GetBranch("ph_pt");
		if (ph_pt_branch) {ph_pt_branch->SetAddress(&ph_pt_);}
	}
	ph_eta_branch = 0;
	if (tree->GetBranch("ph_eta") != 0) {
		ph_eta_branch = tree->GetBranch("ph_eta");
		if (ph_eta_branch) {ph_eta_branch->SetAddress(&ph_eta_);}
	}
	ph_phi_branch = 0;
	if (tree->GetBranch("ph_phi") != 0) {
		ph_phi_branch = tree->GetBranch("ph_phi");
		if (ph_phi_branch) {ph_phi_branch->SetAddress(&ph_phi_);}
	}
	ph_mass_branch = 0;
	if (tree->GetBranch("ph_mass") != 0) {
		ph_mass_branch = tree->GetBranch("ph_mass");
		if (ph_mass_branch) {ph_mass_branch->SetAddress(&ph_mass_);}
	}
	ph_mcMatchId_branch = 0;
	if (tree->GetBranch("ph_mcMatchId") != 0) {
		ph_mcMatchId_branch = tree->GetBranch("ph_mcMatchId");
		if (ph_mcMatchId_branch) {ph_mcMatchId_branch->SetAddress(&ph_mcMatchId_);}
	}
	ph_genIso04_branch = 0;
	if (tree->GetBranch("ph_genIso04") != 0) {
		ph_genIso04_branch = tree->GetBranch("ph_genIso04");
		if (ph_genIso04_branch) {ph_genIso04_branch->SetAddress(&ph_genIso04_);}
	}
	ph_drMinParton_branch = 0;
	if (tree->GetBranch("ph_drMinParton") != 0) {
		ph_drMinParton_branch = tree->GetBranch("ph_drMinParton");
		if (ph_drMinParton_branch) {ph_drMinParton_branch->SetAddress(&ph_drMinParton_);}
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
	ak4pfjets_hadron_flavor_branch = 0;
	if (tree->GetBranch("ak4pfjets_hadron_flavor") != 0) {
		ak4pfjets_hadron_flavor_branch = tree->GetBranch("ak4pfjets_hadron_flavor");
		if (ak4pfjets_hadron_flavor_branch) {ak4pfjets_hadron_flavor_branch->SetAddress(&ak4pfjets_hadron_flavor_);}
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
	genleps_isfromt_branch = 0;
	if (tree->GetBranch("genleps_isfromt") != 0) {
		genleps_isfromt_branch = tree->GetBranch("genleps_isfromt");
		if (genleps_isfromt_branch) {genleps_isfromt_branch->SetAddress(&genleps_isfromt_);}
	}
	genleps_id_branch = 0;
	if (tree->GetBranch("genleps_id") != 0) {
		genleps_id_branch = tree->GetBranch("genleps_id");
		if (genleps_id_branch) {genleps_id_branch->SetAddress(&genleps_id_);}
	}
	genleps__genpsidx_branch = 0;
	if (tree->GetBranch("genleps__genpsidx") != 0) {
		genleps__genpsidx_branch = tree->GetBranch("genleps__genpsidx");
		if (genleps__genpsidx_branch) {genleps__genpsidx_branch->SetAddress(&genleps__genpsidx_);}
	}
	genleps_status_branch = 0;
	if (tree->GetBranch("genleps_status") != 0) {
		genleps_status_branch = tree->GetBranch("genleps_status");
		if (genleps_status_branch) {genleps_status_branch->SetAddress(&genleps_status_);}
	}
	genleps_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genleps_fromHardProcessDecayed") != 0) {
		genleps_fromHardProcessDecayed_branch = tree->GetBranch("genleps_fromHardProcessDecayed");
		if (genleps_fromHardProcessDecayed_branch) {genleps_fromHardProcessDecayed_branch->SetAddress(&genleps_fromHardProcessDecayed_);}
	}
	genleps_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genleps_fromHardProcessFinalState") != 0) {
		genleps_fromHardProcessFinalState_branch = tree->GetBranch("genleps_fromHardProcessFinalState");
		if (genleps_fromHardProcessFinalState_branch) {genleps_fromHardProcessFinalState_branch->SetAddress(&genleps_fromHardProcessFinalState_);}
	}
	genleps_isHardProcess_branch = 0;
	if (tree->GetBranch("genleps_isHardProcess") != 0) {
		genleps_isHardProcess_branch = tree->GetBranch("genleps_isHardProcess");
		if (genleps_isHardProcess_branch) {genleps_isHardProcess_branch->SetAddress(&genleps_isHardProcess_);}
	}
	genleps_isLastCopy_branch = 0;
	if (tree->GetBranch("genleps_isLastCopy") != 0) {
		genleps_isLastCopy_branch = tree->GetBranch("genleps_isLastCopy");
		if (genleps_isLastCopy_branch) {genleps_isLastCopy_branch->SetAddress(&genleps_isLastCopy_);}
	}
	genleps_gentaudecay_branch = 0;
	if (tree->GetBranch("genleps_gentaudecay") != 0) {
		genleps_gentaudecay_branch = tree->GetBranch("genleps_gentaudecay");
		if (genleps_gentaudecay_branch) {genleps_gentaudecay_branch->SetAddress(&genleps_gentaudecay_);}
	}
	gen_nfromtleps__branch = 0;
	if (tree->GetBranch("gen_nfromtleps_") != 0) {
		gen_nfromtleps__branch = tree->GetBranch("gen_nfromtleps_");
		if (gen_nfromtleps__branch) {gen_nfromtleps__branch->SetAddress(&gen_nfromtleps__);}
	}
	genleps_motherid_branch = 0;
	if (tree->GetBranch("genleps_motherid") != 0) {
		genleps_motherid_branch = tree->GetBranch("genleps_motherid");
		if (genleps_motherid_branch) {genleps_motherid_branch->SetAddress(&genleps_motherid_);}
	}
	genleps_motheridx_branch = 0;
	if (tree->GetBranch("genleps_motheridx") != 0) {
		genleps_motheridx_branch = tree->GetBranch("genleps_motheridx");
		if (genleps_motheridx_branch) {genleps_motheridx_branch->SetAddress(&genleps_motheridx_);}
	}
	genleps_motherstatus_branch = 0;
	if (tree->GetBranch("genleps_motherstatus") != 0) {
		genleps_motherstatus_branch = tree->GetBranch("genleps_motherstatus");
		if (genleps_motherstatus_branch) {genleps_motherstatus_branch->SetAddress(&genleps_motherstatus_);}
	}
	genleps_gmotherid_branch = 0;
	if (tree->GetBranch("genleps_gmotherid") != 0) {
		genleps_gmotherid_branch = tree->GetBranch("genleps_gmotherid");
		if (genleps_gmotherid_branch) {genleps_gmotherid_branch->SetAddress(&genleps_gmotherid_);}
	}
	genleps_gmotheridx_branch = 0;
	if (tree->GetBranch("genleps_gmotheridx") != 0) {
		genleps_gmotheridx_branch = tree->GetBranch("genleps_gmotheridx");
		if (genleps_gmotheridx_branch) {genleps_gmotheridx_branch->SetAddress(&genleps_gmotheridx_);}
	}
	genleps_gmotherstatus_branch = 0;
	if (tree->GetBranch("genleps_gmotherstatus") != 0) {
		genleps_gmotherstatus_branch = tree->GetBranch("genleps_gmotherstatus");
		if (genleps_gmotherstatus_branch) {genleps_gmotherstatus_branch->SetAddress(&genleps_gmotherstatus_);}
	}
	gennus_isfromt_branch = 0;
	if (tree->GetBranch("gennus_isfromt") != 0) {
		gennus_isfromt_branch = tree->GetBranch("gennus_isfromt");
		if (gennus_isfromt_branch) {gennus_isfromt_branch->SetAddress(&gennus_isfromt_);}
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
	gennus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gennus_fromHardProcessDecayed") != 0) {
		gennus_fromHardProcessDecayed_branch = tree->GetBranch("gennus_fromHardProcessDecayed");
		if (gennus_fromHardProcessDecayed_branch) {gennus_fromHardProcessDecayed_branch->SetAddress(&gennus_fromHardProcessDecayed_);}
	}
	gennus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gennus_fromHardProcessFinalState") != 0) {
		gennus_fromHardProcessFinalState_branch = tree->GetBranch("gennus_fromHardProcessFinalState");
		if (gennus_fromHardProcessFinalState_branch) {gennus_fromHardProcessFinalState_branch->SetAddress(&gennus_fromHardProcessFinalState_);}
	}
	gennus_isHardProcess_branch = 0;
	if (tree->GetBranch("gennus_isHardProcess") != 0) {
		gennus_isHardProcess_branch = tree->GetBranch("gennus_isHardProcess");
		if (gennus_isHardProcess_branch) {gennus_isHardProcess_branch->SetAddress(&gennus_isHardProcess_);}
	}
	gennus_isLastCopy_branch = 0;
	if (tree->GetBranch("gennus_isLastCopy") != 0) {
		gennus_isLastCopy_branch = tree->GetBranch("gennus_isLastCopy");
		if (gennus_isLastCopy_branch) {gennus_isLastCopy_branch->SetAddress(&gennus_isLastCopy_);}
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
	gennus_gmotherid_branch = 0;
	if (tree->GetBranch("gennus_gmotherid") != 0) {
		gennus_gmotherid_branch = tree->GetBranch("gennus_gmotherid");
		if (gennus_gmotherid_branch) {gennus_gmotherid_branch->SetAddress(&gennus_gmotherid_);}
	}
	gennus_gmotheridx_branch = 0;
	if (tree->GetBranch("gennus_gmotheridx") != 0) {
		gennus_gmotheridx_branch = tree->GetBranch("gennus_gmotheridx");
		if (gennus_gmotheridx_branch) {gennus_gmotheridx_branch->SetAddress(&gennus_gmotheridx_);}
	}
	gennus_gmotherstatus_branch = 0;
	if (tree->GetBranch("gennus_gmotherstatus") != 0) {
		gennus_gmotherstatus_branch = tree->GetBranch("gennus_gmotherstatus");
		if (gennus_gmotherstatus_branch) {gennus_gmotherstatus_branch->SetAddress(&gennus_gmotherstatus_);}
	}
	gents_isfromt_branch = 0;
	if (tree->GetBranch("gents_isfromt") != 0) {
		gents_isfromt_branch = tree->GetBranch("gents_isfromt");
		if (gents_isfromt_branch) {gents_isfromt_branch->SetAddress(&gents_isfromt_);}
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
	genqs_isfromt_branch = 0;
	if (tree->GetBranch("genqs_isfromt") != 0) {
		genqs_isfromt_branch = tree->GetBranch("genqs_isfromt");
		if (genqs_isfromt_branch) {genqs_isfromt_branch->SetAddress(&genqs_isfromt_);}
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
	genbosons_isfromt_branch = 0;
	if (tree->GetBranch("genbosons_isfromt") != 0) {
		genbosons_isfromt_branch = tree->GetBranch("genbosons_isfromt");
		if (genbosons_isfromt_branch) {genbosons_isfromt_branch->SetAddress(&genbosons_isfromt_);}
	}
	genbosons_id_branch = 0;
	if (tree->GetBranch("genbosons_id") != 0) {
		genbosons_id_branch = tree->GetBranch("genbosons_id");
		if (genbosons_id_branch) {genbosons_id_branch->SetAddress(&genbosons_id_);}
	}
	genbosons__genpsidx_branch = 0;
	if (tree->GetBranch("genbosons__genpsidx") != 0) {
		genbosons__genpsidx_branch = tree->GetBranch("genbosons__genpsidx");
		if (genbosons__genpsidx_branch) {genbosons__genpsidx_branch->SetAddress(&genbosons__genpsidx_);}
	}
	genbosons_status_branch = 0;
	if (tree->GetBranch("genbosons_status") != 0) {
		genbosons_status_branch = tree->GetBranch("genbosons_status");
		if (genbosons_status_branch) {genbosons_status_branch->SetAddress(&genbosons_status_);}
	}
	genbosons_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genbosons_fromHardProcessDecayed") != 0) {
		genbosons_fromHardProcessDecayed_branch = tree->GetBranch("genbosons_fromHardProcessDecayed");
		if (genbosons_fromHardProcessDecayed_branch) {genbosons_fromHardProcessDecayed_branch->SetAddress(&genbosons_fromHardProcessDecayed_);}
	}
	genbosons_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genbosons_fromHardProcessFinalState") != 0) {
		genbosons_fromHardProcessFinalState_branch = tree->GetBranch("genbosons_fromHardProcessFinalState");
		if (genbosons_fromHardProcessFinalState_branch) {genbosons_fromHardProcessFinalState_branch->SetAddress(&genbosons_fromHardProcessFinalState_);}
	}
	genbosons_isHardProcess_branch = 0;
	if (tree->GetBranch("genbosons_isHardProcess") != 0) {
		genbosons_isHardProcess_branch = tree->GetBranch("genbosons_isHardProcess");
		if (genbosons_isHardProcess_branch) {genbosons_isHardProcess_branch->SetAddress(&genbosons_isHardProcess_);}
	}
	genbosons_isLastCopy_branch = 0;
	if (tree->GetBranch("genbosons_isLastCopy") != 0) {
		genbosons_isLastCopy_branch = tree->GetBranch("genbosons_isLastCopy");
		if (genbosons_isLastCopy_branch) {genbosons_isLastCopy_branch->SetAddress(&genbosons_isLastCopy_);}
	}
	genbosons_gentaudecay_branch = 0;
	if (tree->GetBranch("genbosons_gentaudecay") != 0) {
		genbosons_gentaudecay_branch = tree->GetBranch("genbosons_gentaudecay");
		if (genbosons_gentaudecay_branch) {genbosons_gentaudecay_branch->SetAddress(&genbosons_gentaudecay_);}
	}
	gen_nfromtbosons__branch = 0;
	if (tree->GetBranch("gen_nfromtbosons_") != 0) {
		gen_nfromtbosons__branch = tree->GetBranch("gen_nfromtbosons_");
		if (gen_nfromtbosons__branch) {gen_nfromtbosons__branch->SetAddress(&gen_nfromtbosons__);}
	}
	genbosons_motherid_branch = 0;
	if (tree->GetBranch("genbosons_motherid") != 0) {
		genbosons_motherid_branch = tree->GetBranch("genbosons_motherid");
		if (genbosons_motherid_branch) {genbosons_motherid_branch->SetAddress(&genbosons_motherid_);}
	}
	genbosons_motheridx_branch = 0;
	if (tree->GetBranch("genbosons_motheridx") != 0) {
		genbosons_motheridx_branch = tree->GetBranch("genbosons_motheridx");
		if (genbosons_motheridx_branch) {genbosons_motheridx_branch->SetAddress(&genbosons_motheridx_);}
	}
	genbosons_motherstatus_branch = 0;
	if (tree->GetBranch("genbosons_motherstatus") != 0) {
		genbosons_motherstatus_branch = tree->GetBranch("genbosons_motherstatus");
		if (genbosons_motherstatus_branch) {genbosons_motherstatus_branch->SetAddress(&genbosons_motherstatus_);}
	}
	genbosons_gmotherid_branch = 0;
	if (tree->GetBranch("genbosons_gmotherid") != 0) {
		genbosons_gmotherid_branch = tree->GetBranch("genbosons_gmotherid");
		if (genbosons_gmotherid_branch) {genbosons_gmotherid_branch->SetAddress(&genbosons_gmotherid_);}
	}
	genbosons_gmotheridx_branch = 0;
	if (tree->GetBranch("genbosons_gmotheridx") != 0) {
		genbosons_gmotheridx_branch = tree->GetBranch("genbosons_gmotheridx");
		if (genbosons_gmotheridx_branch) {genbosons_gmotheridx_branch->SetAddress(&genbosons_gmotheridx_);}
	}
	genbosons_gmotherstatus_branch = 0;
	if (tree->GetBranch("genbosons_gmotherstatus") != 0) {
		genbosons_gmotherstatus_branch = tree->GetBranch("genbosons_gmotherstatus");
		if (genbosons_gmotherstatus_branch) {genbosons_gmotherstatus_branch->SetAddress(&genbosons_gmotherstatus_);}
	}
	gensusy_isfromt_branch = 0;
	if (tree->GetBranch("gensusy_isfromt") != 0) {
		gensusy_isfromt_branch = tree->GetBranch("gensusy_isfromt");
		if (gensusy_isfromt_branch) {gensusy_isfromt_branch->SetAddress(&gensusy_isfromt_);}
	}
	gensusy_id_branch = 0;
	if (tree->GetBranch("gensusy_id") != 0) {
		gensusy_id_branch = tree->GetBranch("gensusy_id");
		if (gensusy_id_branch) {gensusy_id_branch->SetAddress(&gensusy_id_);}
	}
	gensusy__genpsidx_branch = 0;
	if (tree->GetBranch("gensusy__genpsidx") != 0) {
		gensusy__genpsidx_branch = tree->GetBranch("gensusy__genpsidx");
		if (gensusy__genpsidx_branch) {gensusy__genpsidx_branch->SetAddress(&gensusy__genpsidx_);}
	}
	gensusy_status_branch = 0;
	if (tree->GetBranch("gensusy_status") != 0) {
		gensusy_status_branch = tree->GetBranch("gensusy_status");
		if (gensusy_status_branch) {gensusy_status_branch->SetAddress(&gensusy_status_);}
	}
	gensusy_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gensusy_fromHardProcessDecayed") != 0) {
		gensusy_fromHardProcessDecayed_branch = tree->GetBranch("gensusy_fromHardProcessDecayed");
		if (gensusy_fromHardProcessDecayed_branch) {gensusy_fromHardProcessDecayed_branch->SetAddress(&gensusy_fromHardProcessDecayed_);}
	}
	gensusy_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gensusy_fromHardProcessFinalState") != 0) {
		gensusy_fromHardProcessFinalState_branch = tree->GetBranch("gensusy_fromHardProcessFinalState");
		if (gensusy_fromHardProcessFinalState_branch) {gensusy_fromHardProcessFinalState_branch->SetAddress(&gensusy_fromHardProcessFinalState_);}
	}
	gensusy_isHardProcess_branch = 0;
	if (tree->GetBranch("gensusy_isHardProcess") != 0) {
		gensusy_isHardProcess_branch = tree->GetBranch("gensusy_isHardProcess");
		if (gensusy_isHardProcess_branch) {gensusy_isHardProcess_branch->SetAddress(&gensusy_isHardProcess_);}
	}
	gensusy_isLastCopy_branch = 0;
	if (tree->GetBranch("gensusy_isLastCopy") != 0) {
		gensusy_isLastCopy_branch = tree->GetBranch("gensusy_isLastCopy");
		if (gensusy_isLastCopy_branch) {gensusy_isLastCopy_branch->SetAddress(&gensusy_isLastCopy_);}
	}
	gensusy_gentaudecay_branch = 0;
	if (tree->GetBranch("gensusy_gentaudecay") != 0) {
		gensusy_gentaudecay_branch = tree->GetBranch("gensusy_gentaudecay");
		if (gensusy_gentaudecay_branch) {gensusy_gentaudecay_branch->SetAddress(&gensusy_gentaudecay_);}
	}
	gen_nfromtsusy__branch = 0;
	if (tree->GetBranch("gen_nfromtsusy_") != 0) {
		gen_nfromtsusy__branch = tree->GetBranch("gen_nfromtsusy_");
		if (gen_nfromtsusy__branch) {gen_nfromtsusy__branch->SetAddress(&gen_nfromtsusy__);}
	}
	gensusy_motherid_branch = 0;
	if (tree->GetBranch("gensusy_motherid") != 0) {
		gensusy_motherid_branch = tree->GetBranch("gensusy_motherid");
		if (gensusy_motherid_branch) {gensusy_motherid_branch->SetAddress(&gensusy_motherid_);}
	}
	gensusy_motheridx_branch = 0;
	if (tree->GetBranch("gensusy_motheridx") != 0) {
		gensusy_motheridx_branch = tree->GetBranch("gensusy_motheridx");
		if (gensusy_motheridx_branch) {gensusy_motheridx_branch->SetAddress(&gensusy_motheridx_);}
	}
	gensusy_motherstatus_branch = 0;
	if (tree->GetBranch("gensusy_motherstatus") != 0) {
		gensusy_motherstatus_branch = tree->GetBranch("gensusy_motherstatus");
		if (gensusy_motherstatus_branch) {gensusy_motherstatus_branch->SetAddress(&gensusy_motherstatus_);}
	}
	gensusy_gmotherid_branch = 0;
	if (tree->GetBranch("gensusy_gmotherid") != 0) {
		gensusy_gmotherid_branch = tree->GetBranch("gensusy_gmotherid");
		if (gensusy_gmotherid_branch) {gensusy_gmotherid_branch->SetAddress(&gensusy_gmotherid_);}
	}
	gensusy_gmotheridx_branch = 0;
	if (tree->GetBranch("gensusy_gmotheridx") != 0) {
		gensusy_gmotheridx_branch = tree->GetBranch("gensusy_gmotheridx");
		if (gensusy_gmotheridx_branch) {gensusy_gmotheridx_branch->SetAddress(&gensusy_gmotheridx_);}
	}
	gensusy_gmotherstatus_branch = 0;
	if (tree->GetBranch("gensusy_gmotherstatus") != 0) {
		gensusy_gmotherstatus_branch = tree->GetBranch("gensusy_gmotherstatus");
		if (gensusy_gmotherstatus_branch) {gensusy_gmotherstatus_branch->SetAddress(&gensusy_gmotherstatus_);}
	}
  tree->SetMakeClass(0);
}
void CMS3::GetEntry(unsigned int idx) 
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
		filt_badevents_isLoaded = false;
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
		genlepsfromtop_isLoaded = false;
		genLepsHardProcess_isLoaded = false;
		genNusHardProcess_isLoaded = false;
		is0lep_isLoaded = false;
		is1lep_isLoaded = false;
		is2lep_isLoaded = false;
		isZtoNuNu_isLoaded = false;
		is1lepFromW_isLoaded = false;
		is1lepFromTop_isLoaded = false;
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
		pdf_up_weight_isLoaded = false;
		pdf_down_weight_isLoaded = false;
		genweightsID_isLoaded = false;
		genweights_isLoaded = false;
		weight_btagsf_isLoaded = false;
		weight_btagsf_heavy_UP_isLoaded = false;
		weight_btagsf_light_UP_isLoaded = false;
		weight_btagsf_heavy_DN_isLoaded = false;
		weight_btagsf_light_DN_isLoaded = false;
		weight_ISR_isLoaded = false;
		weight_ISRup_isLoaded = false;
		weight_ISRdown_isLoaded = false;
		weight_PU_isLoaded = false;
		weight_PUup_isLoaded = false;
		weight_PUdown_isLoaded = false;
		hardgenpt_isLoaded = false;
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
		genht_isLoaded = false;
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
		HLT_DiEl_17_12_isLoaded = false;
		HLT_DiMu_isLoaded = false;
		HLT_Mu8El17_isLoaded = false;
		HLT_Mu8El23_isLoaded = false;
		HLT_Mu17El12_isLoaded = false;
		HLT_Mu23El12_isLoaded = false;
		HLT_SingleEl23_isLoaded = false;
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
		HLT_SingleMu18_isLoaded = false;
		HLT_SingleMu20_isLoaded = false;
		HLT_SingleMu24_isLoaded = false;
		HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded = false;
		HLT_MET90_MHT90_IDTight_isLoaded = false;
		HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded = false;
		HLT_Photon90_CaloIdL_PFHT500_isLoaded = false;
		HLT_Photon22_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon30_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon36_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon50_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon75_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon90_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon120_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon165_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon175_isLoaded = false;
		HLT_Photon165_HE10_isLoaded = false;
		lep_sf_isLoaded = false;
		btag_sf_isLoaded = false;
		HLT_SingleEl_eff_isLoaded = false;
		HLT_SingleMu_eff_isLoaded = false;
		nPhotons_isLoaded = false;
		ph_selectedidx_isLoaded = false;
		ph_ngoodjets_isLoaded = false;
		ph_ngoodbtags_isLoaded = false;
		ph_met_isLoaded = false;
		ph_met_phi_isLoaded = false;
		ph_HT_isLoaded = false;
		ph_htssm_isLoaded = false;
		ph_htosm_isLoaded = false;
		ph_htratiom_isLoaded = false;
		ph_mt_met_lep_isLoaded = false;
		ph_dphi_Wlep_isLoaded = false;
		ph_MT2W_isLoaded = false;
		ph_topness_isLoaded = false;
		ph_topnessMod_isLoaded = false;
		ph_MT2_lb_b_mass_isLoaded = false;
		ph_MT2_lb_b_isLoaded = false;
		ph_MT2_lb_bqq_mass_isLoaded = false;
		ph_MT2_lb_bqq_isLoaded = false;
		ph_hadronic_top_chi2_isLoaded = false;
		ph_mindphi_met_j1_j2_isLoaded = false;
		ph_Mlb_lead_bdiscr_isLoaded = false;
		ph_dR_lep_leadb_isLoaded = false;
		ph_Mlb_closestb_isLoaded = false;
		ph_Mjjj_isLoaded = false;
		Zll_idl1_isLoaded = false;
		Zll_idl2_isLoaded = false;
		Zll_p4l1_isLoaded = false;
		Zll_p4l2_isLoaded = false;
		Zll_OS_isLoaded = false;
		Zll_SF_isLoaded = false;
		Zll_isZmass_isLoaded = false;
		Zll_M_isLoaded = false;
		Zll_p4_isLoaded = false;
		Zll_selLep_isLoaded = false;
		Zll_met_isLoaded = false;
		Zll_met_phi_isLoaded = false;
		Zll_mindphi_met_j1_j2_isLoaded = false;
		Zll_mt_met_lep_isLoaded = false;
		Zll_dphi_Wlep_isLoaded = false;
		Zll_MT2W_isLoaded = false;
		Zll_topness_isLoaded = false;
		Zll_topnessMod_isLoaded = false;
		Zll_MT2_lb_b_mass_isLoaded = false;
		Zll_MT2_lb_b_isLoaded = false;
		Zll_MT2_lb_bqq_mass_isLoaded = false;
		Zll_MT2_lb_bqq_isLoaded = false;
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
		ph_sigmaIEtaEta_fill5x5_isLoaded = false;
		ph_hOverE_isLoaded = false;
		ph_r9_isLoaded = false;
		ph_chiso_isLoaded = false;
		ph_nhiso_isLoaded = false;
		ph_phiso_isLoaded = false;
		ph_idCutBased_isLoaded = false;
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
		ak4pfjets_hadron_flavor_isLoaded = false;
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
		gents_isfromt_isLoaded = false;
		gents_p4_isLoaded = false;
		gents_id_isLoaded = false;
		gents__genpsidx_isLoaded = false;
		gents_status_isLoaded = false;
		gents_fromHardProcessDecayed_isLoaded = false;
		gents_fromHardProcessFinalState_isLoaded = false;
		gents_isHardProcess_isLoaded = false;
		gents_isLastCopy_isLoaded = false;
		gents_gentaudecay_isLoaded = false;
		gen_nfromtts__isLoaded = false;
		gents_motherp4_isLoaded = false;
		gents_motherid_isLoaded = false;
		gents_motheridx_isLoaded = false;
		gents_motherstatus_isLoaded = false;
		gents_gmotherp4_isLoaded = false;
		gents_gmotherid_isLoaded = false;
		gents_gmotheridx_isLoaded = false;
		gents_gmotherstatus_isLoaded = false;
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
	}

void CMS3::LoadAllBranches() 
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
	if (filt_badevents_branch != 0) filt_badevents();
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
	if (genlepsfromtop_branch != 0) genlepsfromtop();
	if (genLepsHardProcess_branch != 0) genLepsHardProcess();
	if (genNusHardProcess_branch != 0) genNusHardProcess();
	if (is0lep_branch != 0) is0lep();
	if (is1lep_branch != 0) is1lep();
	if (is2lep_branch != 0) is2lep();
	if (isZtoNuNu_branch != 0) isZtoNuNu();
	if (is1lepFromW_branch != 0) is1lepFromW();
	if (is1lepFromTop_branch != 0) is1lepFromTop();
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
	if (pdf_up_weight_branch != 0) pdf_up_weight();
	if (pdf_down_weight_branch != 0) pdf_down_weight();
	if (genweightsID_branch != 0) genweightsID();
	if (genweights_branch != 0) genweights();
	if (weight_btagsf_branch != 0) weight_btagsf();
	if (weight_btagsf_heavy_UP_branch != 0) weight_btagsf_heavy_UP();
	if (weight_btagsf_light_UP_branch != 0) weight_btagsf_light_UP();
	if (weight_btagsf_heavy_DN_branch != 0) weight_btagsf_heavy_DN();
	if (weight_btagsf_light_DN_branch != 0) weight_btagsf_light_DN();
	if (weight_ISR_branch != 0) weight_ISR();
	if (weight_ISRup_branch != 0) weight_ISRup();
	if (weight_ISRdown_branch != 0) weight_ISRdown();
	if (weight_PU_branch != 0) weight_PU();
	if (weight_PUup_branch != 0) weight_PUup();
	if (weight_PUdown_branch != 0) weight_PUdown();
	if (hardgenpt_branch != 0) hardgenpt();
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
	if (genht_branch != 0) genht();
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
	if (HLT_DiEl_17_12_branch != 0) HLT_DiEl_17_12();
	if (HLT_DiMu_branch != 0) HLT_DiMu();
	if (HLT_Mu8El17_branch != 0) HLT_Mu8El17();
	if (HLT_Mu8El23_branch != 0) HLT_Mu8El23();
	if (HLT_Mu17El12_branch != 0) HLT_Mu17El12();
	if (HLT_Mu23El12_branch != 0) HLT_Mu23El12();
	if (HLT_SingleEl23_branch != 0) HLT_SingleEl23();
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
	if (HLT_SingleMu18_branch != 0) HLT_SingleMu18();
	if (HLT_SingleMu20_branch != 0) HLT_SingleMu20();
	if (HLT_SingleMu24_branch != 0) HLT_SingleMu24();
	if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch != 0) HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight();
	if (HLT_MET90_MHT90_IDTight_branch != 0) HLT_MET90_MHT90_IDTight();
	if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch != 0) HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight();
	if (HLT_Photon90_CaloIdL_PFHT500_branch != 0) HLT_Photon90_CaloIdL_PFHT500();
	if (HLT_Photon22_R9Id90_HE10_IsoM_branch != 0) HLT_Photon22_R9Id90_HE10_IsoM();
	if (HLT_Photon30_R9Id90_HE10_IsoM_branch != 0) HLT_Photon30_R9Id90_HE10_IsoM();
	if (HLT_Photon36_R9Id90_HE10_IsoM_branch != 0) HLT_Photon36_R9Id90_HE10_IsoM();
	if (HLT_Photon50_R9Id90_HE10_IsoM_branch != 0) HLT_Photon50_R9Id90_HE10_IsoM();
	if (HLT_Photon75_R9Id90_HE10_IsoM_branch != 0) HLT_Photon75_R9Id90_HE10_IsoM();
	if (HLT_Photon90_R9Id90_HE10_IsoM_branch != 0) HLT_Photon90_R9Id90_HE10_IsoM();
	if (HLT_Photon120_R9Id90_HE10_IsoM_branch != 0) HLT_Photon120_R9Id90_HE10_IsoM();
	if (HLT_Photon165_R9Id90_HE10_IsoM_branch != 0) HLT_Photon165_R9Id90_HE10_IsoM();
	if (HLT_Photon175_branch != 0) HLT_Photon175();
	if (HLT_Photon165_HE10_branch != 0) HLT_Photon165_HE10();
	if (lep_sf_branch != 0) lep_sf();
	if (btag_sf_branch != 0) btag_sf();
	if (HLT_SingleEl_eff_branch != 0) HLT_SingleEl_eff();
	if (HLT_SingleMu_eff_branch != 0) HLT_SingleMu_eff();
	if (nPhotons_branch != 0) nPhotons();
	if (ph_selectedidx_branch != 0) ph_selectedidx();
	if (ph_ngoodjets_branch != 0) ph_ngoodjets();
	if (ph_ngoodbtags_branch != 0) ph_ngoodbtags();
	if (ph_met_branch != 0) ph_met();
	if (ph_met_phi_branch != 0) ph_met_phi();
	if (ph_HT_branch != 0) ph_HT();
	if (ph_htssm_branch != 0) ph_htssm();
	if (ph_htosm_branch != 0) ph_htosm();
	if (ph_htratiom_branch != 0) ph_htratiom();
	if (ph_mt_met_lep_branch != 0) ph_mt_met_lep();
	if (ph_dphi_Wlep_branch != 0) ph_dphi_Wlep();
	if (ph_MT2W_branch != 0) ph_MT2W();
	if (ph_topness_branch != 0) ph_topness();
	if (ph_topnessMod_branch != 0) ph_topnessMod();
	if (ph_MT2_lb_b_mass_branch != 0) ph_MT2_lb_b_mass();
	if (ph_MT2_lb_b_branch != 0) ph_MT2_lb_b();
	if (ph_MT2_lb_bqq_mass_branch != 0) ph_MT2_lb_bqq_mass();
	if (ph_MT2_lb_bqq_branch != 0) ph_MT2_lb_bqq();
	if (ph_hadronic_top_chi2_branch != 0) ph_hadronic_top_chi2();
	if (ph_mindphi_met_j1_j2_branch != 0) ph_mindphi_met_j1_j2();
	if (ph_Mlb_lead_bdiscr_branch != 0) ph_Mlb_lead_bdiscr();
	if (ph_dR_lep_leadb_branch != 0) ph_dR_lep_leadb();
	if (ph_Mlb_closestb_branch != 0) ph_Mlb_closestb();
	if (ph_Mjjj_branch != 0) ph_Mjjj();
	if (Zll_idl1_branch != 0) Zll_idl1();
	if (Zll_idl2_branch != 0) Zll_idl2();
	if (Zll_p4l1_branch != 0) Zll_p4l1();
	if (Zll_p4l2_branch != 0) Zll_p4l2();
	if (Zll_OS_branch != 0) Zll_OS();
	if (Zll_SF_branch != 0) Zll_SF();
	if (Zll_isZmass_branch != 0) Zll_isZmass();
	if (Zll_M_branch != 0) Zll_M();
	if (Zll_p4_branch != 0) Zll_p4();
	if (Zll_selLep_branch != 0) Zll_selLep();
	if (Zll_met_branch != 0) Zll_met();
	if (Zll_met_phi_branch != 0) Zll_met_phi();
	if (Zll_mindphi_met_j1_j2_branch != 0) Zll_mindphi_met_j1_j2();
	if (Zll_mt_met_lep_branch != 0) Zll_mt_met_lep();
	if (Zll_dphi_Wlep_branch != 0) Zll_dphi_Wlep();
	if (Zll_MT2W_branch != 0) Zll_MT2W();
	if (Zll_topness_branch != 0) Zll_topness();
	if (Zll_topnessMod_branch != 0) Zll_topnessMod();
	if (Zll_MT2_lb_b_mass_branch != 0) Zll_MT2_lb_b_mass();
	if (Zll_MT2_lb_b_branch != 0) Zll_MT2_lb_b();
	if (Zll_MT2_lb_bqq_mass_branch != 0) Zll_MT2_lb_bqq_mass();
	if (Zll_MT2_lb_bqq_branch != 0) Zll_MT2_lb_bqq();
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
	if (ph_sigmaIEtaEta_fill5x5_branch != 0) ph_sigmaIEtaEta_fill5x5();
	if (ph_hOverE_branch != 0) ph_hOverE();
	if (ph_r9_branch != 0) ph_r9();
	if (ph_chiso_branch != 0) ph_chiso();
	if (ph_nhiso_branch != 0) ph_nhiso();
	if (ph_phiso_branch != 0) ph_phiso();
	if (ph_idCutBased_branch != 0) ph_idCutBased();
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
	if (ak4pfjets_hadron_flavor_branch != 0) ak4pfjets_hadron_flavor();
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
	if (gents_isfromt_branch != 0) gents_isfromt();
	if (gents_p4_branch != 0) gents_p4();
	if (gents_id_branch != 0) gents_id();
	if (gents__genpsidx_branch != 0) gents__genpsidx();
	if (gents_status_branch != 0) gents_status();
	if (gents_fromHardProcessDecayed_branch != 0) gents_fromHardProcessDecayed();
	if (gents_fromHardProcessFinalState_branch != 0) gents_fromHardProcessFinalState();
	if (gents_isHardProcess_branch != 0) gents_isHardProcess();
	if (gents_isLastCopy_branch != 0) gents_isLastCopy();
	if (gents_gentaudecay_branch != 0) gents_gentaudecay();
	if (gen_nfromtts__branch != 0) gen_nfromtts_();
	if (gents_motherp4_branch != 0) gents_motherp4();
	if (gents_motherid_branch != 0) gents_motherid();
	if (gents_motheridx_branch != 0) gents_motheridx();
	if (gents_motherstatus_branch != 0) gents_motherstatus();
	if (gents_gmotherp4_branch != 0) gents_gmotherp4();
	if (gents_gmotherid_branch != 0) gents_gmotherid();
	if (gents_gmotheridx_branch != 0) gents_gmotheridx();
	if (gents_gmotherstatus_branch != 0) gents_gmotherstatus();
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
}

	const unsigned int &CMS3::run()
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
	const unsigned int &CMS3::ls()
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
	const unsigned int &CMS3::evt()
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
	const int &CMS3::nvtxs()
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
	const int &CMS3::firstGoodVtxIdx()
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
	const int &CMS3::firstVtx_isfake()
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
	const float &CMS3::firstVtx_ndof()
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
	const float &CMS3::firstVtx_posRho()
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
	const float &CMS3::firstVtx_posZ()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::firstVtx_posp4()
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
	const int &CMS3::pu_nvtxs()
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
	const float &CMS3::pfmet()
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
	const float &CMS3::pfmet_phi()
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
	const float &CMS3::calomet()
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
	const float &CMS3::calomet_phi()
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
	const float &CMS3::filt_cscbeamhalo()
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
	const float &CMS3::filt_ecallaser()
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
	const float &CMS3::filt_ecaltp()
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
	const float &CMS3::filt_eebadsc()
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
	const float &CMS3::filt_goodvtx()
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
	const float &CMS3::filt_badevents()
	{
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
	const float &CMS3::filt_hbhenoise()
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
	const float &CMS3::filt_hcallaser()
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
	const float &CMS3::filt_met()
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
	const float &CMS3::filt_trkfail()
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
	const float &CMS3::filt_trkPOG()
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
	const float &CMS3::filt_trkPOG_tmc()
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
	const float &CMS3::filt_trkPOG_tms()
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
	const float &CMS3::filt_eff()
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
	const float &CMS3::scale1fb()
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
	const float &CMS3::xsec()
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
	const float &CMS3::xsec_uncert()
	{
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
	const float &CMS3::kfactor()
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
	const float &CMS3::pu_ntrue()
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
	const int &CMS3::ngoodleps()
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
	const int &CMS3::nlooseleps()
	{
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
	const int &CMS3::nvetoleps()
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
	const bool &	CMS3::is_data()
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
	const string &CMS3::dataset()
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
	const string &CMS3::filename()
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
	const string &CMS3::cms3tag()
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
	const unsigned int &CMS3::nEvents()
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
	const unsigned int &CMS3::nEvents_goodvtx()
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
	const unsigned int &CMS3::nEvents_MET30()
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
	const unsigned int &CMS3::nEvents_1goodlep()
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
	const unsigned int &CMS3::nEvents_2goodjets()
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
	const int &CMS3::genlepsfromtop()
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
	const int &CMS3::genLepsHardProcess()
	{
		if (not genLepsHardProcess_isLoaded) {
			if (genLepsHardProcess_branch != 0) {
				genLepsHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genLepsHardProcess_branch does not exist!\n");
				exit(1);
			}
			genLepsHardProcess_isLoaded = true;
		}
		return genLepsHardProcess_;
	}
	const int &CMS3::genNusHardProcess()
	{
		if (not genNusHardProcess_isLoaded) {
			if (genNusHardProcess_branch != 0) {
				genNusHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genNusHardProcess_branch does not exist!\n");
				exit(1);
			}
			genNusHardProcess_isLoaded = true;
		}
		return genNusHardProcess_;
	}
	const int &CMS3::is0lep()
	{
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
	const int &CMS3::is1lep()
	{
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
	const int &CMS3::is2lep()
	{
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
	const int &CMS3::isZtoNuNu()
	{
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
	const int &CMS3::is1lepFromW()
	{
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
	const int &CMS3::is1lepFromTop()
	{
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
	const float &CMS3::MT2W()
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
	const float &CMS3::MT2W_lep2()
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
	const float &CMS3::mindphi_met_j1_j2()
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
	const float &CMS3::mt_met_lep()
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
	const float &CMS3::mt_met_lep2()
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
	const float &CMS3::dR_lep_leadb()
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
	const float &CMS3::dR_lep2_leadb()
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
	const float &CMS3::hadronic_top_chi2()
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
	const float &CMS3::dphi_Wlep()
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
	const float &CMS3::MET_over_sqrtHT()
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
	const float &CMS3::ak4pfjets_rho()
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
	const float &CMS3::pdf_up_weight()
	{
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
	const float &CMS3::pdf_down_weight()
	{
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
	const vector<string> &CMS3::genweightsID()
	{
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
	const vector<float> &CMS3::genweights()
	{
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
	const float &CMS3::weight_btagsf()
	{
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
	const float &CMS3::weight_btagsf_heavy_UP()
	{
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
	const float &CMS3::weight_btagsf_light_UP()
	{
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
	const float &CMS3::weight_btagsf_heavy_DN()
	{
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
	const float &CMS3::weight_btagsf_light_DN()
	{
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
	const float &CMS3::weight_ISR()
	{
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
	const float &CMS3::weight_ISRup()
	{
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
	const float &CMS3::weight_ISRdown()
	{
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
	const float &CMS3::weight_PU()
	{
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
	const float &CMS3::weight_PUup()
	{
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
	const float &CMS3::weight_PUdown()
	{
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
	const float &CMS3::hardgenpt()
	{
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
	const vector<string> &CMS3::sparms_names()
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
	const float &CMS3::sparms_filterEfficiency()
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
	const float &CMS3::sparms_pdfScale()
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
	const float &CMS3::sparms_pdfWeight1()
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
	const float &CMS3::sparms_pdfWeight2()
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
	const float &CMS3::sparms_weight()
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
	const float &CMS3::sparms_xsec()
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
	const vector<float> &CMS3::sparms_values()
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
	const int &CMS3::sparms_subProcessId()
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
	const float &CMS3::mass_lsp()
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
	const float &CMS3::mass_chargino()
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
	const float &CMS3::mass_stop()
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
	const float &CMS3::genmet()
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
	const float &CMS3::genmet_phi()
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
	const float &CMS3::genht()
	{
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
	const bool &	CMS3::PassTrackVeto()
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
	const bool &	CMS3::PassTrackVeto_v2()
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
	const bool &	CMS3::PassTrackVeto_v3()
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
	const bool &	CMS3::PassTauVeto()
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
	const float &CMS3::EA_all_rho()
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
	const float &CMS3::EA_allcalo_rho()
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
	const float &CMS3::EA_centralcalo_rho()
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
	const float &CMS3::EA_centralchargedpileup_rho()
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
	const float &CMS3::EA_centralneutral_rho()
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
	const float &CMS3::topness()
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
	const float &CMS3::topness_lep2()
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
	const float &CMS3::topnessMod()
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
	const float &CMS3::topnessMod_lep2()
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
	const float &CMS3::MT2_lb_b()
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
	const float &CMS3::MT2_lb_b_lep2()
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
	const float &CMS3::MT2_lb_b_mass()
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
	const float &CMS3::MT2_lb_b_mass_lep2()
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
	const float &CMS3::MT2_lb_bqq()
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
	const float &CMS3::MT2_lb_bqq_lep2()
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
	const float &CMS3::MT2_lb_bqq_mass()
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
	const float &CMS3::MT2_lb_bqq_mass_lep2()
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
	const float &CMS3::Mlb_closestb()
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
	const float &CMS3::Mlb_lead_bdiscr()
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
	const float &CMS3::Mlb_closestb_lep2()
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
	const float &CMS3::Mlb_lead_bdiscr_lep2()
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
	const float &CMS3::Mjjj()
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
	const float &CMS3::Mjjj_lep2()
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
	const int &CMS3::HLT_SingleEl()
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
	const int &CMS3::HLT_SingleMu()
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
	const int &CMS3::HLT_MET170()
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
	const int &CMS3::HLT_MET120Btag()
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
	const int &CMS3::HLT_MET120Mu5()
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
	const int &CMS3::HLT_HT350MET120()
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
	const int &CMS3::HLT_DiEl()
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
	const int &CMS3::HLT_DiEl_17_12()
	{
		if (not HLT_DiEl_17_12_isLoaded) {
			if (HLT_DiEl_17_12_branch != 0) {
				HLT_DiEl_17_12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiEl_17_12_branch does not exist!\n");
				exit(1);
			}
			HLT_DiEl_17_12_isLoaded = true;
		}
		return HLT_DiEl_17_12_;
	}
	const int &CMS3::HLT_DiMu()
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
	const int &CMS3::HLT_Mu8El17()
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
	const int &CMS3::HLT_Mu8El23()
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
	const int &CMS3::HLT_Mu17El12()
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
	const int &CMS3::HLT_Mu23El12()
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
	const int &CMS3::HLT_SingleEl23()
	{
		if (not HLT_SingleEl23_isLoaded) {
			if (HLT_SingleEl23_branch != 0) {
				HLT_SingleEl23_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl23_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl23_isLoaded = true;
		}
		return HLT_SingleEl23_;
	}
	const int &CMS3::HLT_SingleEl27()
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
	const int &CMS3::HLT_SingleEl27Tight()
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
	const int &CMS3::HLT_SingleElTight()
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
	const int &CMS3::HLT_SingleElHT200()
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
	const int &CMS3::HLT_SingleMuNoEta()
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
	const int &CMS3::HLT_SingleMuNoIso()
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
	const int &CMS3::HLT_SingleMuNoIsoNoEta()
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
	const int &CMS3::HLT_Mu6HT200MET100()
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
	const int &CMS3::HLT_HT350MET100()
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
	const int &CMS3::HLT_SingleMu17()
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
	const int &CMS3::HLT_SingleMu18()
	{
		if (not HLT_SingleMu18_isLoaded) {
			if (HLT_SingleMu18_branch != 0) {
				HLT_SingleMu18_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu18_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu18_isLoaded = true;
		}
		return HLT_SingleMu18_;
	}
	const int &CMS3::HLT_SingleMu20()
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
	const int &CMS3::HLT_SingleMu24()
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
	const int &CMS3::HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight()
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
	const int &CMS3::HLT_MET90_MHT90_IDTight()
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
	const int &CMS3::HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight()
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
	const int &CMS3::HLT_Photon90_CaloIdL_PFHT500()
	{
		if (not HLT_Photon90_CaloIdL_PFHT500_isLoaded) {
			if (HLT_Photon90_CaloIdL_PFHT500_branch != 0) {
				HLT_Photon90_CaloIdL_PFHT500_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon90_CaloIdL_PFHT500_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon90_CaloIdL_PFHT500_isLoaded = true;
		}
		return HLT_Photon90_CaloIdL_PFHT500_;
	}
	const int &CMS3::HLT_Photon22_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon22_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon22_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon22_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon22_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon22_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon22_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon30_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon30_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon30_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon30_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon30_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon30_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon30_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon36_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon36_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon36_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon36_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon36_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon36_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon36_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon50_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon50_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon50_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon50_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon50_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon50_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon50_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon75_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon75_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon75_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon75_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon75_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon75_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon75_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon90_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon90_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon90_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon90_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon90_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon90_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon90_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon120_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon120_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon120_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon120_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon120_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon120_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon120_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon165_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon165_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon165_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon165_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon165_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon165_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon165_R9Id90_HE10_IsoM_;
	}
	const int &CMS3::HLT_Photon175()
	{
		if (not HLT_Photon175_isLoaded) {
			if (HLT_Photon175_branch != 0) {
				HLT_Photon175_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon175_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon175_isLoaded = true;
		}
		return HLT_Photon175_;
	}
	const int &CMS3::HLT_Photon165_HE10()
	{
		if (not HLT_Photon165_HE10_isLoaded) {
			if (HLT_Photon165_HE10_branch != 0) {
				HLT_Photon165_HE10_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon165_HE10_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon165_HE10_isLoaded = true;
		}
		return HLT_Photon165_HE10_;
	}
	const float &CMS3::lep_sf()
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
	const float &CMS3::btag_sf()
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
	const float &CMS3::HLT_SingleEl_eff()
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
	const float &CMS3::HLT_SingleMu_eff()
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
	const int &CMS3::nPhotons()
	{
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
	const int &CMS3::ph_selectedidx()
	{
		if (not ph_selectedidx_isLoaded) {
			if (ph_selectedidx_branch != 0) {
				ph_selectedidx_branch->GetEntry(index);
			} else { 
				printf("branch ph_selectedidx_branch does not exist!\n");
				exit(1);
			}
			ph_selectedidx_isLoaded = true;
		}
		return ph_selectedidx_;
	}
	const int &CMS3::ph_ngoodjets()
	{
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
	const int &CMS3::ph_ngoodbtags()
	{
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
	const float &CMS3::ph_met()
	{
		if (not ph_met_isLoaded) {
			if (ph_met_branch != 0) {
				ph_met_branch->GetEntry(index);
			} else { 
				printf("branch ph_met_branch does not exist!\n");
				exit(1);
			}
			ph_met_isLoaded = true;
		}
		return ph_met_;
	}
	const float &CMS3::ph_met_phi()
	{
		if (not ph_met_phi_isLoaded) {
			if (ph_met_phi_branch != 0) {
				ph_met_phi_branch->GetEntry(index);
			} else { 
				printf("branch ph_met_phi_branch does not exist!\n");
				exit(1);
			}
			ph_met_phi_isLoaded = true;
		}
		return ph_met_phi_;
	}
	const float &CMS3::ph_HT()
	{
		if (not ph_HT_isLoaded) {
			if (ph_HT_branch != 0) {
				ph_HT_branch->GetEntry(index);
			} else { 
				printf("branch ph_HT_branch does not exist!\n");
				exit(1);
			}
			ph_HT_isLoaded = true;
		}
		return ph_HT_;
	}
	const float &CMS3::ph_htssm()
	{
		if (not ph_htssm_isLoaded) {
			if (ph_htssm_branch != 0) {
				ph_htssm_branch->GetEntry(index);
			} else { 
				printf("branch ph_htssm_branch does not exist!\n");
				exit(1);
			}
			ph_htssm_isLoaded = true;
		}
		return ph_htssm_;
	}
	const float &CMS3::ph_htosm()
	{
		if (not ph_htosm_isLoaded) {
			if (ph_htosm_branch != 0) {
				ph_htosm_branch->GetEntry(index);
			} else { 
				printf("branch ph_htosm_branch does not exist!\n");
				exit(1);
			}
			ph_htosm_isLoaded = true;
		}
		return ph_htosm_;
	}
	const float &CMS3::ph_htratiom()
	{
		if (not ph_htratiom_isLoaded) {
			if (ph_htratiom_branch != 0) {
				ph_htratiom_branch->GetEntry(index);
			} else { 
				printf("branch ph_htratiom_branch does not exist!\n");
				exit(1);
			}
			ph_htratiom_isLoaded = true;
		}
		return ph_htratiom_;
	}
	const float &CMS3::ph_mt_met_lep()
	{
		if (not ph_mt_met_lep_isLoaded) {
			if (ph_mt_met_lep_branch != 0) {
				ph_mt_met_lep_branch->GetEntry(index);
			} else { 
				printf("branch ph_mt_met_lep_branch does not exist!\n");
				exit(1);
			}
			ph_mt_met_lep_isLoaded = true;
		}
		return ph_mt_met_lep_;
	}
	const float &CMS3::ph_dphi_Wlep()
	{
		if (not ph_dphi_Wlep_isLoaded) {
			if (ph_dphi_Wlep_branch != 0) {
				ph_dphi_Wlep_branch->GetEntry(index);
			} else { 
				printf("branch ph_dphi_Wlep_branch does not exist!\n");
				exit(1);
			}
			ph_dphi_Wlep_isLoaded = true;
		}
		return ph_dphi_Wlep_;
	}
	const float &CMS3::ph_MT2W()
	{
		if (not ph_MT2W_isLoaded) {
			if (ph_MT2W_branch != 0) {
				ph_MT2W_branch->GetEntry(index);
			} else { 
				printf("branch ph_MT2W_branch does not exist!\n");
				exit(1);
			}
			ph_MT2W_isLoaded = true;
		}
		return ph_MT2W_;
	}
	const float &CMS3::ph_topness()
	{
		if (not ph_topness_isLoaded) {
			if (ph_topness_branch != 0) {
				ph_topness_branch->GetEntry(index);
			} else { 
				printf("branch ph_topness_branch does not exist!\n");
				exit(1);
			}
			ph_topness_isLoaded = true;
		}
		return ph_topness_;
	}
	const float &CMS3::ph_topnessMod()
	{
		if (not ph_topnessMod_isLoaded) {
			if (ph_topnessMod_branch != 0) {
				ph_topnessMod_branch->GetEntry(index);
			} else { 
				printf("branch ph_topnessMod_branch does not exist!\n");
				exit(1);
			}
			ph_topnessMod_isLoaded = true;
		}
		return ph_topnessMod_;
	}
	const float &CMS3::ph_MT2_lb_b_mass()
	{
		if (not ph_MT2_lb_b_mass_isLoaded) {
			if (ph_MT2_lb_b_mass_branch != 0) {
				ph_MT2_lb_b_mass_branch->GetEntry(index);
			} else { 
				printf("branch ph_MT2_lb_b_mass_branch does not exist!\n");
				exit(1);
			}
			ph_MT2_lb_b_mass_isLoaded = true;
		}
		return ph_MT2_lb_b_mass_;
	}
	const float &CMS3::ph_MT2_lb_b()
	{
		if (not ph_MT2_lb_b_isLoaded) {
			if (ph_MT2_lb_b_branch != 0) {
				ph_MT2_lb_b_branch->GetEntry(index);
			} else { 
				printf("branch ph_MT2_lb_b_branch does not exist!\n");
				exit(1);
			}
			ph_MT2_lb_b_isLoaded = true;
		}
		return ph_MT2_lb_b_;
	}
	const float &CMS3::ph_MT2_lb_bqq_mass()
	{
		if (not ph_MT2_lb_bqq_mass_isLoaded) {
			if (ph_MT2_lb_bqq_mass_branch != 0) {
				ph_MT2_lb_bqq_mass_branch->GetEntry(index);
			} else { 
				printf("branch ph_MT2_lb_bqq_mass_branch does not exist!\n");
				exit(1);
			}
			ph_MT2_lb_bqq_mass_isLoaded = true;
		}
		return ph_MT2_lb_bqq_mass_;
	}
	const float &CMS3::ph_MT2_lb_bqq()
	{
		if (not ph_MT2_lb_bqq_isLoaded) {
			if (ph_MT2_lb_bqq_branch != 0) {
				ph_MT2_lb_bqq_branch->GetEntry(index);
			} else { 
				printf("branch ph_MT2_lb_bqq_branch does not exist!\n");
				exit(1);
			}
			ph_MT2_lb_bqq_isLoaded = true;
		}
		return ph_MT2_lb_bqq_;
	}
	const float &CMS3::ph_hadronic_top_chi2()
	{
		if (not ph_hadronic_top_chi2_isLoaded) {
			if (ph_hadronic_top_chi2_branch != 0) {
				ph_hadronic_top_chi2_branch->GetEntry(index);
			} else { 
				printf("branch ph_hadronic_top_chi2_branch does not exist!\n");
				exit(1);
			}
			ph_hadronic_top_chi2_isLoaded = true;
		}
		return ph_hadronic_top_chi2_;
	}
	const float &CMS3::ph_mindphi_met_j1_j2()
	{
		if (not ph_mindphi_met_j1_j2_isLoaded) {
			if (ph_mindphi_met_j1_j2_branch != 0) {
				ph_mindphi_met_j1_j2_branch->GetEntry(index);
			} else { 
				printf("branch ph_mindphi_met_j1_j2_branch does not exist!\n");
				exit(1);
			}
			ph_mindphi_met_j1_j2_isLoaded = true;
		}
		return ph_mindphi_met_j1_j2_;
	}
	const float &CMS3::ph_Mlb_lead_bdiscr()
	{
		if (not ph_Mlb_lead_bdiscr_isLoaded) {
			if (ph_Mlb_lead_bdiscr_branch != 0) {
				ph_Mlb_lead_bdiscr_branch->GetEntry(index);
			} else { 
				printf("branch ph_Mlb_lead_bdiscr_branch does not exist!\n");
				exit(1);
			}
			ph_Mlb_lead_bdiscr_isLoaded = true;
		}
		return ph_Mlb_lead_bdiscr_;
	}
	const float &CMS3::ph_dR_lep_leadb()
	{
		if (not ph_dR_lep_leadb_isLoaded) {
			if (ph_dR_lep_leadb_branch != 0) {
				ph_dR_lep_leadb_branch->GetEntry(index);
			} else { 
				printf("branch ph_dR_lep_leadb_branch does not exist!\n");
				exit(1);
			}
			ph_dR_lep_leadb_isLoaded = true;
		}
		return ph_dR_lep_leadb_;
	}
	const float &CMS3::ph_Mlb_closestb()
	{
		if (not ph_Mlb_closestb_isLoaded) {
			if (ph_Mlb_closestb_branch != 0) {
				ph_Mlb_closestb_branch->GetEntry(index);
			} else { 
				printf("branch ph_Mlb_closestb_branch does not exist!\n");
				exit(1);
			}
			ph_Mlb_closestb_isLoaded = true;
		}
		return ph_Mlb_closestb_;
	}
	const float &CMS3::ph_Mjjj()
	{
		if (not ph_Mjjj_isLoaded) {
			if (ph_Mjjj_branch != 0) {
				ph_Mjjj_branch->GetEntry(index);
			} else { 
				printf("branch ph_Mjjj_branch does not exist!\n");
				exit(1);
			}
			ph_Mjjj_isLoaded = true;
		}
		return ph_Mjjj_;
	}
	const int &CMS3::Zll_idl1()
	{
		if (not Zll_idl1_isLoaded) {
			if (Zll_idl1_branch != 0) {
				Zll_idl1_branch->GetEntry(index);
			} else { 
				printf("branch Zll_idl1_branch does not exist!\n");
				exit(1);
			}
			Zll_idl1_isLoaded = true;
		}
		return Zll_idl1_;
	}
	const int &CMS3::Zll_idl2()
	{
		if (not Zll_idl2_isLoaded) {
			if (Zll_idl2_branch != 0) {
				Zll_idl2_branch->GetEntry(index);
			} else { 
				printf("branch Zll_idl2_branch does not exist!\n");
				exit(1);
			}
			Zll_idl2_isLoaded = true;
		}
		return Zll_idl2_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::Zll_p4l1()
	{
		if (not Zll_p4l1_isLoaded) {
			if (Zll_p4l1_branch != 0) {
				Zll_p4l1_branch->GetEntry(index);
			} else { 
				printf("branch Zll_p4l1_branch does not exist!\n");
				exit(1);
			}
			Zll_p4l1_isLoaded = true;
		}
		return *Zll_p4l1_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::Zll_p4l2()
	{
		if (not Zll_p4l2_isLoaded) {
			if (Zll_p4l2_branch != 0) {
				Zll_p4l2_branch->GetEntry(index);
			} else { 
				printf("branch Zll_p4l2_branch does not exist!\n");
				exit(1);
			}
			Zll_p4l2_isLoaded = true;
		}
		return *Zll_p4l2_;
	}
	const bool &	CMS3::Zll_OS()
	{
		if (not Zll_OS_isLoaded) {
			if (Zll_OS_branch != 0) {
				Zll_OS_branch->GetEntry(index);
			} else { 
				printf("branch Zll_OS_branch does not exist!\n");
				exit(1);
			}
			Zll_OS_isLoaded = true;
		}
		return Zll_OS_;
	}
	const bool &	CMS3::Zll_SF()
	{
		if (not Zll_SF_isLoaded) {
			if (Zll_SF_branch != 0) {
				Zll_SF_branch->GetEntry(index);
			} else { 
				printf("branch Zll_SF_branch does not exist!\n");
				exit(1);
			}
			Zll_SF_isLoaded = true;
		}
		return Zll_SF_;
	}
	const bool &	CMS3::Zll_isZmass()
	{
		if (not Zll_isZmass_isLoaded) {
			if (Zll_isZmass_branch != 0) {
				Zll_isZmass_branch->GetEntry(index);
			} else { 
				printf("branch Zll_isZmass_branch does not exist!\n");
				exit(1);
			}
			Zll_isZmass_isLoaded = true;
		}
		return Zll_isZmass_;
	}
	const float &CMS3::Zll_M()
	{
		if (not Zll_M_isLoaded) {
			if (Zll_M_branch != 0) {
				Zll_M_branch->GetEntry(index);
			} else { 
				printf("branch Zll_M_branch does not exist!\n");
				exit(1);
			}
			Zll_M_isLoaded = true;
		}
		return Zll_M_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::Zll_p4()
	{
		if (not Zll_p4_isLoaded) {
			if (Zll_p4_branch != 0) {
				Zll_p4_branch->GetEntry(index);
			} else { 
				printf("branch Zll_p4_branch does not exist!\n");
				exit(1);
			}
			Zll_p4_isLoaded = true;
		}
		return *Zll_p4_;
	}
	const int &CMS3::Zll_selLep()
	{
		if (not Zll_selLep_isLoaded) {
			if (Zll_selLep_branch != 0) {
				Zll_selLep_branch->GetEntry(index);
			} else { 
				printf("branch Zll_selLep_branch does not exist!\n");
				exit(1);
			}
			Zll_selLep_isLoaded = true;
		}
		return Zll_selLep_;
	}
	const float &CMS3::Zll_met()
	{
		if (not Zll_met_isLoaded) {
			if (Zll_met_branch != 0) {
				Zll_met_branch->GetEntry(index);
			} else { 
				printf("branch Zll_met_branch does not exist!\n");
				exit(1);
			}
			Zll_met_isLoaded = true;
		}
		return Zll_met_;
	}
	const float &CMS3::Zll_met_phi()
	{
		if (not Zll_met_phi_isLoaded) {
			if (Zll_met_phi_branch != 0) {
				Zll_met_phi_branch->GetEntry(index);
			} else { 
				printf("branch Zll_met_phi_branch does not exist!\n");
				exit(1);
			}
			Zll_met_phi_isLoaded = true;
		}
		return Zll_met_phi_;
	}
	const float &CMS3::Zll_mindphi_met_j1_j2()
	{
		if (not Zll_mindphi_met_j1_j2_isLoaded) {
			if (Zll_mindphi_met_j1_j2_branch != 0) {
				Zll_mindphi_met_j1_j2_branch->GetEntry(index);
			} else { 
				printf("branch Zll_mindphi_met_j1_j2_branch does not exist!\n");
				exit(1);
			}
			Zll_mindphi_met_j1_j2_isLoaded = true;
		}
		return Zll_mindphi_met_j1_j2_;
	}
	const float &CMS3::Zll_mt_met_lep()
	{
		if (not Zll_mt_met_lep_isLoaded) {
			if (Zll_mt_met_lep_branch != 0) {
				Zll_mt_met_lep_branch->GetEntry(index);
			} else { 
				printf("branch Zll_mt_met_lep_branch does not exist!\n");
				exit(1);
			}
			Zll_mt_met_lep_isLoaded = true;
		}
		return Zll_mt_met_lep_;
	}
	const float &CMS3::Zll_dphi_Wlep()
	{
		if (not Zll_dphi_Wlep_isLoaded) {
			if (Zll_dphi_Wlep_branch != 0) {
				Zll_dphi_Wlep_branch->GetEntry(index);
			} else { 
				printf("branch Zll_dphi_Wlep_branch does not exist!\n");
				exit(1);
			}
			Zll_dphi_Wlep_isLoaded = true;
		}
		return Zll_dphi_Wlep_;
	}
	const float &CMS3::Zll_MT2W()
	{
		if (not Zll_MT2W_isLoaded) {
			if (Zll_MT2W_branch != 0) {
				Zll_MT2W_branch->GetEntry(index);
			} else { 
				printf("branch Zll_MT2W_branch does not exist!\n");
				exit(1);
			}
			Zll_MT2W_isLoaded = true;
		}
		return Zll_MT2W_;
	}
	const float &CMS3::Zll_topness()
	{
		if (not Zll_topness_isLoaded) {
			if (Zll_topness_branch != 0) {
				Zll_topness_branch->GetEntry(index);
			} else { 
				printf("branch Zll_topness_branch does not exist!\n");
				exit(1);
			}
			Zll_topness_isLoaded = true;
		}
		return Zll_topness_;
	}
	const float &CMS3::Zll_topnessMod()
	{
		if (not Zll_topnessMod_isLoaded) {
			if (Zll_topnessMod_branch != 0) {
				Zll_topnessMod_branch->GetEntry(index);
			} else { 
				printf("branch Zll_topnessMod_branch does not exist!\n");
				exit(1);
			}
			Zll_topnessMod_isLoaded = true;
		}
		return Zll_topnessMod_;
	}
	const float &CMS3::Zll_MT2_lb_b_mass()
	{
		if (not Zll_MT2_lb_b_mass_isLoaded) {
			if (Zll_MT2_lb_b_mass_branch != 0) {
				Zll_MT2_lb_b_mass_branch->GetEntry(index);
			} else { 
				printf("branch Zll_MT2_lb_b_mass_branch does not exist!\n");
				exit(1);
			}
			Zll_MT2_lb_b_mass_isLoaded = true;
		}
		return Zll_MT2_lb_b_mass_;
	}
	const float &CMS3::Zll_MT2_lb_b()
	{
		if (not Zll_MT2_lb_b_isLoaded) {
			if (Zll_MT2_lb_b_branch != 0) {
				Zll_MT2_lb_b_branch->GetEntry(index);
			} else { 
				printf("branch Zll_MT2_lb_b_branch does not exist!\n");
				exit(1);
			}
			Zll_MT2_lb_b_isLoaded = true;
		}
		return Zll_MT2_lb_b_;
	}
	const float &CMS3::Zll_MT2_lb_bqq_mass()
	{
		if (not Zll_MT2_lb_bqq_mass_isLoaded) {
			if (Zll_MT2_lb_bqq_mass_branch != 0) {
				Zll_MT2_lb_bqq_mass_branch->GetEntry(index);
			} else { 
				printf("branch Zll_MT2_lb_bqq_mass_branch does not exist!\n");
				exit(1);
			}
			Zll_MT2_lb_bqq_mass_isLoaded = true;
		}
		return Zll_MT2_lb_bqq_mass_;
	}
	const float &CMS3::Zll_MT2_lb_bqq()
	{
		if (not Zll_MT2_lb_bqq_isLoaded) {
			if (Zll_MT2_lb_bqq_branch != 0) {
				Zll_MT2_lb_bqq_branch->GetEntry(index);
			} else { 
				printf("branch Zll_MT2_lb_bqq_branch does not exist!\n");
				exit(1);
			}
			Zll_MT2_lb_bqq_isLoaded = true;
		}
		return Zll_MT2_lb_bqq_;
	}
	const bool &	CMS3::lep1_is_mu()
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
	const bool &	CMS3::lep1_is_el()
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
	const int &CMS3::lep1_charge()
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
	const int &CMS3::lep1_pdgid()
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
	const int &CMS3::lep1_type()
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
	const int &CMS3::lep1_production_type()
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
	const float &CMS3::lep1_d0()
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
	const float &CMS3::lep1_d0err()
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
	const float &CMS3::lep1_dz()
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
	const float &CMS3::lep1_dzerr()
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
	const float &CMS3::lep1_sigmaIEtaEta_fill5x5()
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
	const float &CMS3::lep1_dEtaIn()
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
	const float &CMS3::lep1_dPhiIn()
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
	const float &CMS3::lep1_hOverE()
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
	const float &CMS3::lep1_ooEmooP()
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
	const int &CMS3::lep1_expectedMissingInnerHits()
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
	const bool &	CMS3::lep1_conversionVeto()
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
	const float &CMS3::lep1_etaSC()
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
	const float &CMS3::lep1_ChiSqr()
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
	const float &CMS3::lep1_chiso()
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
	const float &CMS3::lep1_nhiso()
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
	const float &CMS3::lep1_emiso()
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
	const float &CMS3::lep1_deltaBeta()
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
	const float &CMS3::lep1_relIso03DB()
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
	const float &CMS3::lep1_relIso03EA()
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
	const float &CMS3::lep1_relIso04DB()
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
	const float &CMS3::lep1_miniRelIsoDB()
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
	const float &CMS3::lep1_miniRelIsoEA()
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
	const float &CMS3::lep1_MiniIso()
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
	const int &CMS3::lep1_mcid()
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
	const int &CMS3::lep1_mcstatus()
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
	const int &CMS3::lep1_mc3dr()
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
	const int &CMS3::lep1_mc3id()
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
	const int &CMS3::lep1_mc3idx()
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
	const int &CMS3::lep1_mc3motherid()
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
	const int &CMS3::lep1_mc3motheridx()
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
	const bool &	CMS3::lep1_is_eleid_loose()
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
	const bool &	CMS3::lep1_is_eleid_medium()
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
	const bool &	CMS3::lep1_is_eleid_tight()
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
	const bool &	CMS3::lep1_is_phys14_loose_noIso()
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
	const bool &	CMS3::lep1_is_phys14_medium_noIso()
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
	const bool &	CMS3::lep1_is_phys14_tight_noIso()
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
	const float &CMS3::lep1_eoverpin()
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
	const bool &	CMS3::lep1_is_muoid_loose()
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
	const bool &	CMS3::lep1_is_muoid_medium()
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
	const bool &	CMS3::lep1_is_muoid_tight()
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
	const float &CMS3::lep1_ip3d()
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
	const float &CMS3::lep1_ip3derr()
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
	const bool &	CMS3::lep1_is_pfmu()
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
	const bool &	CMS3::lep1_passMediumID()
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
	const bool &	CMS3::lep1_passVeto()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep1_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep1_mcp4()
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
	const float &CMS3::lep1_pt()
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
	const float &CMS3::lep1_eta()
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
	const float &CMS3::lep1_phi()
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
	const float &CMS3::lep1_mass()
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
	const bool &	CMS3::lep2_is_mu()
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
	const bool &	CMS3::lep2_is_el()
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
	const int &CMS3::lep2_charge()
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
	const int &CMS3::lep2_pdgid()
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
	const int &CMS3::lep2_type()
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
	const int &CMS3::lep2_production_type()
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
	const float &CMS3::lep2_d0()
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
	const float &CMS3::lep2_d0err()
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
	const float &CMS3::lep2_dz()
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
	const float &CMS3::lep2_dzerr()
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
	const float &CMS3::lep2_sigmaIEtaEta_fill5x5()
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
	const float &CMS3::lep2_dEtaIn()
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
	const float &CMS3::lep2_dPhiIn()
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
	const float &CMS3::lep2_hOverE()
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
	const float &CMS3::lep2_ooEmooP()
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
	const int &CMS3::lep2_expectedMissingInnerHits()
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
	const bool &	CMS3::lep2_conversionVeto()
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
	const float &CMS3::lep2_etaSC()
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
	const float &CMS3::lep2_ChiSqr()
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
	const float &CMS3::lep2_chiso()
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
	const float &CMS3::lep2_nhiso()
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
	const float &CMS3::lep2_emiso()
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
	const float &CMS3::lep2_deltaBeta()
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
	const float &CMS3::lep2_relIso03DB()
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
	const float &CMS3::lep2_relIso03EA()
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
	const float &CMS3::lep2_relIso04DB()
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
	const float &CMS3::lep2_miniRelIsoDB()
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
	const float &CMS3::lep2_miniRelIsoEA()
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
	const float &CMS3::lep2_MiniIso()
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
	const int &CMS3::lep2_mcid()
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
	const int &CMS3::lep2_mcstatus()
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
	const int &CMS3::lep2_mc3dr()
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
	const int &CMS3::lep2_mc3id()
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
	const int &CMS3::lep2_mc3idx()
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
	const int &CMS3::lep2_mc3motherid()
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
	const int &CMS3::lep2_mc3motheridx()
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
	const bool &	CMS3::lep2_is_eleid_loose()
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
	const bool &	CMS3::lep2_is_eleid_medium()
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
	const bool &	CMS3::lep2_is_eleid_tight()
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
	const bool &	CMS3::lep2_is_phys14_loose_noIso()
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
	const bool &	CMS3::lep2_is_phys14_medium_noIso()
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
	const bool &	CMS3::lep2_is_phys14_tight_noIso()
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
	const float &CMS3::lep2_eoverpin()
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
	const bool &	CMS3::lep2_is_muoid_loose()
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
	const bool &	CMS3::lep2_is_muoid_medium()
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
	const bool &	CMS3::lep2_is_muoid_tight()
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
	const float &CMS3::lep2_ip3d()
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
	const float &CMS3::lep2_ip3derr()
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
	const bool &	CMS3::lep2_is_pfmu()
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
	const bool &	CMS3::lep2_passMediumID()
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
	const bool &	CMS3::lep2_passVeto()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep2_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::lep2_mcp4()
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
	const float &CMS3::lep2_pt()
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
	const float &CMS3::lep2_eta()
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
	const float &CMS3::lep2_phi()
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
	const float &CMS3::lep2_mass()
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
	const vector<float> &CMS3::ph_sigmaIEtaEta_fill5x5()
	{
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
	const vector<float> &CMS3::ph_hOverE()
	{
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
	const vector<float> &CMS3::ph_r9()
	{
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
	const vector<float> &CMS3::ph_chiso()
	{
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
	const vector<float> &CMS3::ph_nhiso()
	{
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
	const vector<float> &CMS3::ph_phiso()
	{
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
	const vector<bool> &CMS3::ph_idCutBased()
	{
		if (not ph_idCutBased_isLoaded) {
			if (ph_idCutBased_branch != 0) {
				ph_idCutBased_branch->GetEntry(index);
			} else { 
				printf("branch ph_idCutBased_branch does not exist!\n");
				exit(1);
			}
			ph_idCutBased_isLoaded = true;
		}
		return *ph_idCutBased_;
	}
	const vector<int> &CMS3::ph_overlapJetId()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ph_p4()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ph_mcp4()
	{
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
	const vector<float> &CMS3::ph_pt()
	{
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
	const vector<float> &CMS3::ph_eta()
	{
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
	const vector<float> &CMS3::ph_phi()
	{
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
	const vector<float> &CMS3::ph_mass()
	{
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
	const vector<int> &CMS3::ph_mcMatchId()
	{
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
	const vector<float> &CMS3::ph_genIso04()
	{
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
	const vector<float> &CMS3::ph_drMinParton()
	{
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
	const int &CMS3::nGoodGenJets()
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
	const int &CMS3::ngoodjets()
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
	const int &CMS3::nfailjets()
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
	const int &CMS3::ak8GoodPFJets()
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
	const int &CMS3::ngoodbtags()
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
	const float &CMS3::ak4_HT()
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
	const float &CMS3::ak4_htssm()
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
	const float &CMS3::ak4_htosm()
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
	const float &CMS3::ak4_htratiom()
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
	const vector<float> &CMS3::dphi_ak4pfjet_met()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak4pfjets_p4()
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
	const vector<float> &CMS3::ak4pfjets_pt()
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
	const vector<float> &CMS3::ak4pfjets_eta()
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
	const vector<float> &CMS3::ak4pfjets_phi()
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
	const vector<float> &CMS3::ak4pfjets_mass()
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
	const vector<bool> &CMS3::ak4pfjets_passMEDbtag()
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
	const vector<float> &CMS3::ak4pfjets_qg_disc()
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
	const vector<float> &CMS3::ak4pfjets_CSV()
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
	const vector<float> &CMS3::ak4pfjets_puid()
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
	const vector<int> &CMS3::ak4pfjets_parton_flavor()
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
	const vector<int> &CMS3::ak4pfjets_hadron_flavor()
	{
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
	const vector<bool> &CMS3::ak4pfjets_loose_puid()
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
	const vector<bool> &CMS3::ak4pfjets_loose_pfid()
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
	const vector<bool> &CMS3::ak4pfjets_medium_pfid()
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
	const vector<bool> &CMS3::ak4pfjets_tight_pfid()
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
	const vector<float> &CMS3::ak4pfjets_MEDbjet_pt()
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
	const float &CMS3::ak4pfjets_leadMEDbjet_pt()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjets_leadMEDbjet_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjets_leadbtag_p4()
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
	const vector<float> &CMS3::ak4pfjets_chf()
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
	const vector<float> &CMS3::ak4pfjets_nhf()
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
	const vector<float> &CMS3::ak4pfjets_cef()
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
	const vector<float> &CMS3::ak4pfjets_nef()
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
	const vector<float> &CMS3::ak4pfjets_muf()
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
	const vector<int> &CMS3::ak4pfjets_cm()
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
	const vector<int> &CMS3::ak4pfjets_nm()
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
	const vector<int> &CMS3::ak4pfjets_mc3dr()
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
	const vector<int> &CMS3::ak4pfjets_mc3id()
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
	const vector<int> &CMS3::ak4pfjets_mc3idx()
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
	const vector<int> &CMS3::ak4pfjets_mcmotherid()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjet_overlep1_p4()
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
	const float &CMS3::ak4pfjet_overlep1_CSV()
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
	const float &CMS3::ak4pfjet_overlep1_pu_id()
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
	const float &CMS3::ak4pfjet_overlep1_chf()
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
	const float &CMS3::ak4pfjet_overlep1_nhf()
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
	const float &CMS3::ak4pfjet_overlep1_cef()
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
	const float &CMS3::ak4pfjet_overlep1_nef()
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
	const float &CMS3::ak4pfjet_overlep1_muf()
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
	const int &CMS3::ak4pfjet_overlep1_cm()
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
	const int &CMS3::ak4pfjet_overlep1_nm()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &CMS3::ak4pfjet_overlep2_p4()
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
	const float &CMS3::ak4pfjet_overlep2_CSV()
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
	const float &CMS3::ak4pfjet_overlep2_pu_id()
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
	const float &CMS3::ak4pfjet_overlep2_chf()
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
	const float &CMS3::ak4pfjet_overlep2_nhf()
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
	const float &CMS3::ak4pfjet_overlep2_cef()
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
	const float &CMS3::ak4pfjet_overlep2_nef()
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
	const float &CMS3::ak4pfjet_overlep2_muf()
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
	const int &CMS3::ak4pfjet_overlep2_cm()
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
	const int &CMS3::ak4pfjet_overlep2_nm()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak8pfjets_p4()
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
	const vector<float> &CMS3::ak8pfjets_tau1()
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
	const vector<float> &CMS3::ak8pfjets_tau2()
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
	const vector<float> &CMS3::ak8pfjets_tau3()
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
	const vector<float> &CMS3::ak8pfjets_top_mass()
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
	const vector<float> &CMS3::ak8pfjets_pruned_mass()
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
	const vector<float> &CMS3::ak8pfjets_trimmed_mass()
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
	const vector<float> &CMS3::ak8pfjets_filtered_mass()
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
	const vector<float> &CMS3::ak8pfjets_pu_id()
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
	const vector<int> &CMS3::ak8pfjets_parton_flavor()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::ak4genjets_p4()
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
	const vector<TString> &CMS3::tau_IDnames()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_leadtrack_p4()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_leadneutral_p4()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::tau_p4()
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
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::tau_isocand_p4()
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
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &CMS3::tau_sigcand_p4()
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
	const vector<float> &CMS3::tau_mass()
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
	const vector<vector<float> > &CMS3::tau_ID()
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
	const vector<float> &CMS3::tau_passID()
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
	const vector<float> &CMS3::tau_charge()
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
	const int &CMS3::ngoodtaus()
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
	const vector<float> &CMS3::tau_againstMuonTight()
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
	const vector<float> &CMS3::tau_againstElectronLoose()
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
	const vector<bool> &CMS3::tau_isVetoTau()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::isoTracks_p4()
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
	const vector<int> &CMS3::isoTracks_charge()
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
	const vector<float> &CMS3::isoTracks_absIso()
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
	const vector<float> &CMS3::isoTracks_dz()
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
	const vector<int> &CMS3::isoTracks_pdgId()
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
	const vector<int> &CMS3::isoTracks_selectedidx()
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
	const int &CMS3::isoTracks_nselected()
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
	const vector<bool> &CMS3::isoTracks_isVetoTrack()
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
	const vector<bool> &CMS3::isoTracks_isVetoTrack_v2()
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
	const vector<bool> &CMS3::isoTracks_isVetoTrack_v3()
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
	const vector<bool> &CMS3::genleps_isfromt()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_p4()
	{
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
	const vector<int> &CMS3::genleps_id()
	{
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
	const vector<int> &CMS3::genleps__genpsidx()
	{
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
	const vector<int> &CMS3::genleps_status()
	{
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
	const vector<bool> &CMS3::genleps_fromHardProcessDecayed()
	{
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
	const vector<bool> &CMS3::genleps_fromHardProcessFinalState()
	{
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
	const vector<bool> &CMS3::genleps_isHardProcess()
	{
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
	const vector<bool> &CMS3::genleps_isLastCopy()
	{
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
	const vector<int> &CMS3::genleps_gentaudecay()
	{
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
	const int &CMS3::gen_nfromtleps_()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_motherp4()
	{
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
	const vector<int> &CMS3::genleps_motherid()
	{
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
	const vector<int> &CMS3::genleps_motheridx()
	{
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
	const vector<int> &CMS3::genleps_motherstatus()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genleps_gmotherp4()
	{
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
	const vector<int> &CMS3::genleps_gmotherid()
	{
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
	const vector<int> &CMS3::genleps_gmotheridx()
	{
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
	const vector<int> &CMS3::genleps_gmotherstatus()
	{
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
	const vector<bool> &CMS3::gennus_isfromt()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_p4()
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
	const vector<int> &CMS3::gennus_id()
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
	const vector<int> &CMS3::gennus__genpsidx()
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
	const vector<int> &CMS3::gennus_status()
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
	const vector<bool> &CMS3::gennus_fromHardProcessDecayed()
	{
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
	const vector<bool> &CMS3::gennus_fromHardProcessFinalState()
	{
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
	const vector<bool> &CMS3::gennus_isHardProcess()
	{
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
	const vector<bool> &CMS3::gennus_isLastCopy()
	{
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
	const vector<int> &CMS3::gennus_gentaudecay()
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
	const int &CMS3::gen_nfromtnus_()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_motherp4()
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
	const vector<int> &CMS3::gennus_motherid()
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
	const vector<int> &CMS3::gennus_motheridx()
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
	const vector<int> &CMS3::gennus_motherstatus()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gennus_gmotherp4()
	{
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
	const vector<int> &CMS3::gennus_gmotherid()
	{
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
	const vector<int> &CMS3::gennus_gmotheridx()
	{
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
	const vector<int> &CMS3::gennus_gmotherstatus()
	{
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
	const vector<bool> &CMS3::gents_isfromt()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gents_p4()
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
	const vector<int> &CMS3::gents_id()
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
	const vector<int> &CMS3::gents__genpsidx()
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
	const vector<int> &CMS3::gents_status()
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
	const vector<bool> &CMS3::gents_fromHardProcessDecayed()
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
	const vector<bool> &CMS3::gents_fromHardProcessFinalState()
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
	const vector<bool> &CMS3::gents_isHardProcess()
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
	const vector<bool> &CMS3::gents_isLastCopy()
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
	const vector<int> &CMS3::gents_gentaudecay()
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
	const int &CMS3::gen_nfromtts_()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gents_motherp4()
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
	const vector<int> &CMS3::gents_motherid()
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
	const vector<int> &CMS3::gents_motheridx()
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
	const vector<int> &CMS3::gents_motherstatus()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gents_gmotherp4()
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
	const vector<int> &CMS3::gents_gmotherid()
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
	const vector<int> &CMS3::gents_gmotheridx()
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
	const vector<int> &CMS3::gents_gmotherstatus()
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
	const vector<bool> &CMS3::genqs_isfromt()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_p4()
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
	const vector<int> &CMS3::genqs_id()
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
	const vector<int> &CMS3::genqs__genpsidx()
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
	const vector<int> &CMS3::genqs_status()
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
	const vector<bool> &CMS3::genqs_fromHardProcessDecayed()
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
	const vector<bool> &CMS3::genqs_fromHardProcessFinalState()
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
	const vector<bool> &CMS3::genqs_isHardProcess()
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
	const vector<bool> &CMS3::genqs_isLastCopy()
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
	const vector<int> &CMS3::genqs_gentaudecay()
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
	const int &CMS3::gen_nfromtqs_()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_motherp4()
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
	const vector<int> &CMS3::genqs_motherid()
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
	const vector<int> &CMS3::genqs_motheridx()
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
	const vector<int> &CMS3::genqs_motherstatus()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genqs_gmotherp4()
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
	const vector<int> &CMS3::genqs_gmotherid()
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
	const vector<int> &CMS3::genqs_gmotheridx()
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
	const vector<int> &CMS3::genqs_gmotherstatus()
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
	const vector<bool> &CMS3::genbosons_isfromt()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_p4()
	{
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
	const vector<int> &CMS3::genbosons_id()
	{
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
	const vector<int> &CMS3::genbosons__genpsidx()
	{
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
	const vector<int> &CMS3::genbosons_status()
	{
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
	const vector<bool> &CMS3::genbosons_fromHardProcessDecayed()
	{
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
	const vector<bool> &CMS3::genbosons_fromHardProcessFinalState()
	{
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
	const vector<bool> &CMS3::genbosons_isHardProcess()
	{
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
	const vector<bool> &CMS3::genbosons_isLastCopy()
	{
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
	const vector<int> &CMS3::genbosons_gentaudecay()
	{
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
	const int &CMS3::gen_nfromtbosons_()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_motherp4()
	{
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
	const vector<int> &CMS3::genbosons_motherid()
	{
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
	const vector<int> &CMS3::genbosons_motheridx()
	{
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
	const vector<int> &CMS3::genbosons_motherstatus()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::genbosons_gmotherp4()
	{
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
	const vector<int> &CMS3::genbosons_gmotherid()
	{
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
	const vector<int> &CMS3::genbosons_gmotheridx()
	{
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
	const vector<int> &CMS3::genbosons_gmotherstatus()
	{
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
	const vector<bool> &CMS3::gensusy_isfromt()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_p4()
	{
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
	const vector<int> &CMS3::gensusy_id()
	{
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
	const vector<int> &CMS3::gensusy__genpsidx()
	{
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
	const vector<int> &CMS3::gensusy_status()
	{
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
	const vector<bool> &CMS3::gensusy_fromHardProcessDecayed()
	{
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
	const vector<bool> &CMS3::gensusy_fromHardProcessFinalState()
	{
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
	const vector<bool> &CMS3::gensusy_isHardProcess()
	{
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
	const vector<bool> &CMS3::gensusy_isLastCopy()
	{
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
	const vector<int> &CMS3::gensusy_gentaudecay()
	{
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
	const int &CMS3::gen_nfromtsusy_()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_motherp4()
	{
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
	const vector<int> &CMS3::gensusy_motherid()
	{
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
	const vector<int> &CMS3::gensusy_motheridx()
	{
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
	const vector<int> &CMS3::gensusy_motherstatus()
	{
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &CMS3::gensusy_gmotherp4()
	{
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
	const vector<int> &CMS3::gensusy_gmotherid()
	{
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
	const vector<int> &CMS3::gensusy_gmotheridx()
	{
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
	const vector<int> &CMS3::gensusy_gmotherstatus()
	{
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

  void CMS3::progress( int nEventsTotal, int nEventsChain ){
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
	const float &filt_badevents() { return cms3.filt_badevents(); }
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
	const float &xsec_uncert() { return cms3.xsec_uncert(); }
	const float &kfactor() { return cms3.kfactor(); }
	const float &pu_ntrue() { return cms3.pu_ntrue(); }
	const int &ngoodleps() { return cms3.ngoodleps(); }
	const int &nlooseleps() { return cms3.nlooseleps(); }
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
	const int &genLepsHardProcess() { return cms3.genLepsHardProcess(); }
	const int &genNusHardProcess() { return cms3.genNusHardProcess(); }
	const int &is0lep() { return cms3.is0lep(); }
	const int &is1lep() { return cms3.is1lep(); }
	const int &is2lep() { return cms3.is2lep(); }
	const int &isZtoNuNu() { return cms3.isZtoNuNu(); }
	const int &is1lepFromW() { return cms3.is1lepFromW(); }
	const int &is1lepFromTop() { return cms3.is1lepFromTop(); }
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
	const float &pdf_up_weight() { return cms3.pdf_up_weight(); }
	const float &pdf_down_weight() { return cms3.pdf_down_weight(); }
	const vector<string> &genweightsID() { return cms3.genweightsID(); }
	const vector<float> &genweights() { return cms3.genweights(); }
	const float &weight_btagsf() { return cms3.weight_btagsf(); }
	const float &weight_btagsf_heavy_UP() { return cms3.weight_btagsf_heavy_UP(); }
	const float &weight_btagsf_light_UP() { return cms3.weight_btagsf_light_UP(); }
	const float &weight_btagsf_heavy_DN() { return cms3.weight_btagsf_heavy_DN(); }
	const float &weight_btagsf_light_DN() { return cms3.weight_btagsf_light_DN(); }
	const float &weight_ISR() { return cms3.weight_ISR(); }
	const float &weight_ISRup() { return cms3.weight_ISRup(); }
	const float &weight_ISRdown() { return cms3.weight_ISRdown(); }
	const float &weight_PU() { return cms3.weight_PU(); }
	const float &weight_PUup() { return cms3.weight_PUup(); }
	const float &weight_PUdown() { return cms3.weight_PUdown(); }
	const float &hardgenpt() { return cms3.hardgenpt(); }
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
	const float &genht() { return cms3.genht(); }
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
	const int &HLT_DiEl_17_12() { return cms3.HLT_DiEl_17_12(); }
	const int &HLT_DiMu() { return cms3.HLT_DiMu(); }
	const int &HLT_Mu8El17() { return cms3.HLT_Mu8El17(); }
	const int &HLT_Mu8El23() { return cms3.HLT_Mu8El23(); }
	const int &HLT_Mu17El12() { return cms3.HLT_Mu17El12(); }
	const int &HLT_Mu23El12() { return cms3.HLT_Mu23El12(); }
	const int &HLT_SingleEl23() { return cms3.HLT_SingleEl23(); }
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
	const int &HLT_SingleMu18() { return cms3.HLT_SingleMu18(); }
	const int &HLT_SingleMu20() { return cms3.HLT_SingleMu20(); }
	const int &HLT_SingleMu24() { return cms3.HLT_SingleMu24(); }
	const int &HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight() { return cms3.HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight(); }
	const int &HLT_MET90_MHT90_IDTight() { return cms3.HLT_MET90_MHT90_IDTight(); }
	const int &HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight() { return cms3.HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight(); }
	const int &HLT_Photon90_CaloIdL_PFHT500() { return cms3.HLT_Photon90_CaloIdL_PFHT500(); }
	const int &HLT_Photon22_R9Id90_HE10_IsoM() { return cms3.HLT_Photon22_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon30_R9Id90_HE10_IsoM() { return cms3.HLT_Photon30_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon36_R9Id90_HE10_IsoM() { return cms3.HLT_Photon36_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon50_R9Id90_HE10_IsoM() { return cms3.HLT_Photon50_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon75_R9Id90_HE10_IsoM() { return cms3.HLT_Photon75_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon90_R9Id90_HE10_IsoM() { return cms3.HLT_Photon90_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon120_R9Id90_HE10_IsoM() { return cms3.HLT_Photon120_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon165_R9Id90_HE10_IsoM() { return cms3.HLT_Photon165_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon175() { return cms3.HLT_Photon175(); }
	const int &HLT_Photon165_HE10() { return cms3.HLT_Photon165_HE10(); }
	const float &lep_sf() { return cms3.lep_sf(); }
	const float &btag_sf() { return cms3.btag_sf(); }
	const float &HLT_SingleEl_eff() { return cms3.HLT_SingleEl_eff(); }
	const float &HLT_SingleMu_eff() { return cms3.HLT_SingleMu_eff(); }
	const int &nPhotons() { return cms3.nPhotons(); }
	const int &ph_selectedidx() { return cms3.ph_selectedidx(); }
	const int &ph_ngoodjets() { return cms3.ph_ngoodjets(); }
	const int &ph_ngoodbtags() { return cms3.ph_ngoodbtags(); }
	const float &ph_met() { return cms3.ph_met(); }
	const float &ph_met_phi() { return cms3.ph_met_phi(); }
	const float &ph_HT() { return cms3.ph_HT(); }
	const float &ph_htssm() { return cms3.ph_htssm(); }
	const float &ph_htosm() { return cms3.ph_htosm(); }
	const float &ph_htratiom() { return cms3.ph_htratiom(); }
	const float &ph_mt_met_lep() { return cms3.ph_mt_met_lep(); }
	const float &ph_dphi_Wlep() { return cms3.ph_dphi_Wlep(); }
	const float &ph_MT2W() { return cms3.ph_MT2W(); }
	const float &ph_topness() { return cms3.ph_topness(); }
	const float &ph_topnessMod() { return cms3.ph_topnessMod(); }
	const float &ph_MT2_lb_b_mass() { return cms3.ph_MT2_lb_b_mass(); }
	const float &ph_MT2_lb_b() { return cms3.ph_MT2_lb_b(); }
	const float &ph_MT2_lb_bqq_mass() { return cms3.ph_MT2_lb_bqq_mass(); }
	const float &ph_MT2_lb_bqq() { return cms3.ph_MT2_lb_bqq(); }
	const float &ph_hadronic_top_chi2() { return cms3.ph_hadronic_top_chi2(); }
	const float &ph_mindphi_met_j1_j2() { return cms3.ph_mindphi_met_j1_j2(); }
	const float &ph_Mlb_lead_bdiscr() { return cms3.ph_Mlb_lead_bdiscr(); }
	const float &ph_dR_lep_leadb() { return cms3.ph_dR_lep_leadb(); }
	const float &ph_Mlb_closestb() { return cms3.ph_Mlb_closestb(); }
	const float &ph_Mjjj() { return cms3.ph_Mjjj(); }
	const int &Zll_idl1() { return cms3.Zll_idl1(); }
	const int &Zll_idl2() { return cms3.Zll_idl2(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Zll_p4l1() { return cms3.Zll_p4l1(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Zll_p4l2() { return cms3.Zll_p4l2(); }
	const bool &Zll_OS() { return cms3.Zll_OS(); }
	const bool &Zll_SF() { return cms3.Zll_SF(); }
	const bool &Zll_isZmass() { return cms3.Zll_isZmass(); }
	const float &Zll_M() { return cms3.Zll_M(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &Zll_p4() { return cms3.Zll_p4(); }
	const int &Zll_selLep() { return cms3.Zll_selLep(); }
	const float &Zll_met() { return cms3.Zll_met(); }
	const float &Zll_met_phi() { return cms3.Zll_met_phi(); }
	const float &Zll_mindphi_met_j1_j2() { return cms3.Zll_mindphi_met_j1_j2(); }
	const float &Zll_mt_met_lep() { return cms3.Zll_mt_met_lep(); }
	const float &Zll_dphi_Wlep() { return cms3.Zll_dphi_Wlep(); }
	const float &Zll_MT2W() { return cms3.Zll_MT2W(); }
	const float &Zll_topness() { return cms3.Zll_topness(); }
	const float &Zll_topnessMod() { return cms3.Zll_topnessMod(); }
	const float &Zll_MT2_lb_b_mass() { return cms3.Zll_MT2_lb_b_mass(); }
	const float &Zll_MT2_lb_b() { return cms3.Zll_MT2_lb_b(); }
	const float &Zll_MT2_lb_bqq_mass() { return cms3.Zll_MT2_lb_bqq_mass(); }
	const float &Zll_MT2_lb_bqq() { return cms3.Zll_MT2_lb_bqq(); }
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
	const vector<float> &ph_sigmaIEtaEta_fill5x5() { return cms3.ph_sigmaIEtaEta_fill5x5(); }
	const vector<float> &ph_hOverE() { return cms3.ph_hOverE(); }
	const vector<float> &ph_r9() { return cms3.ph_r9(); }
	const vector<float> &ph_chiso() { return cms3.ph_chiso(); }
	const vector<float> &ph_nhiso() { return cms3.ph_nhiso(); }
	const vector<float> &ph_phiso() { return cms3.ph_phiso(); }
	const vector<bool> &ph_idCutBased() { return cms3.ph_idCutBased(); }
	const vector<int> &ph_overlapJetId() { return cms3.ph_overlapJetId(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_p4() { return cms3.ph_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_mcp4() { return cms3.ph_mcp4(); }
	const vector<float> &ph_pt() { return cms3.ph_pt(); }
	const vector<float> &ph_eta() { return cms3.ph_eta(); }
	const vector<float> &ph_phi() { return cms3.ph_phi(); }
	const vector<float> &ph_mass() { return cms3.ph_mass(); }
	const vector<int> &ph_mcMatchId() { return cms3.ph_mcMatchId(); }
	const vector<float> &ph_genIso04() { return cms3.ph_genIso04(); }
	const vector<float> &ph_drMinParton() { return cms3.ph_drMinParton(); }
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
	const vector<int> &ak4pfjets_hadron_flavor() { return cms3.ak4pfjets_hadron_flavor(); }
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
	const vector<bool> &genleps_isfromt() { return cms3.genleps_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_p4() { return cms3.genleps_p4(); }
	const vector<int> &genleps_id() { return cms3.genleps_id(); }
	const vector<int> &genleps__genpsidx() { return cms3.genleps__genpsidx(); }
	const vector<int> &genleps_status() { return cms3.genleps_status(); }
	const vector<bool> &genleps_fromHardProcessDecayed() { return cms3.genleps_fromHardProcessDecayed(); }
	const vector<bool> &genleps_fromHardProcessFinalState() { return cms3.genleps_fromHardProcessFinalState(); }
	const vector<bool> &genleps_isHardProcess() { return cms3.genleps_isHardProcess(); }
	const vector<bool> &genleps_isLastCopy() { return cms3.genleps_isLastCopy(); }
	const vector<int> &genleps_gentaudecay() { return cms3.genleps_gentaudecay(); }
	const int &gen_nfromtleps_() { return cms3.gen_nfromtleps_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_motherp4() { return cms3.genleps_motherp4(); }
	const vector<int> &genleps_motherid() { return cms3.genleps_motherid(); }
	const vector<int> &genleps_motheridx() { return cms3.genleps_motheridx(); }
	const vector<int> &genleps_motherstatus() { return cms3.genleps_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_gmotherp4() { return cms3.genleps_gmotherp4(); }
	const vector<int> &genleps_gmotherid() { return cms3.genleps_gmotherid(); }
	const vector<int> &genleps_gmotheridx() { return cms3.genleps_gmotheridx(); }
	const vector<int> &genleps_gmotherstatus() { return cms3.genleps_gmotherstatus(); }
	const vector<bool> &gennus_isfromt() { return cms3.gennus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4() { return cms3.gennus_p4(); }
	const vector<int> &gennus_id() { return cms3.gennus_id(); }
	const vector<int> &gennus__genpsidx() { return cms3.gennus__genpsidx(); }
	const vector<int> &gennus_status() { return cms3.gennus_status(); }
	const vector<bool> &gennus_fromHardProcessDecayed() { return cms3.gennus_fromHardProcessDecayed(); }
	const vector<bool> &gennus_fromHardProcessFinalState() { return cms3.gennus_fromHardProcessFinalState(); }
	const vector<bool> &gennus_isHardProcess() { return cms3.gennus_isHardProcess(); }
	const vector<bool> &gennus_isLastCopy() { return cms3.gennus_isLastCopy(); }
	const vector<int> &gennus_gentaudecay() { return cms3.gennus_gentaudecay(); }
	const int &gen_nfromtnus_() { return cms3.gen_nfromtnus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4() { return cms3.gennus_motherp4(); }
	const vector<int> &gennus_motherid() { return cms3.gennus_motherid(); }
	const vector<int> &gennus_motheridx() { return cms3.gennus_motheridx(); }
	const vector<int> &gennus_motherstatus() { return cms3.gennus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_gmotherp4() { return cms3.gennus_gmotherp4(); }
	const vector<int> &gennus_gmotherid() { return cms3.gennus_gmotherid(); }
	const vector<int> &gennus_gmotheridx() { return cms3.gennus_gmotheridx(); }
	const vector<int> &gennus_gmotherstatus() { return cms3.gennus_gmotherstatus(); }
	const vector<bool> &gents_isfromt() { return cms3.gents_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_p4() { return cms3.gents_p4(); }
	const vector<int> &gents_id() { return cms3.gents_id(); }
	const vector<int> &gents__genpsidx() { return cms3.gents__genpsidx(); }
	const vector<int> &gents_status() { return cms3.gents_status(); }
	const vector<bool> &gents_fromHardProcessDecayed() { return cms3.gents_fromHardProcessDecayed(); }
	const vector<bool> &gents_fromHardProcessFinalState() { return cms3.gents_fromHardProcessFinalState(); }
	const vector<bool> &gents_isHardProcess() { return cms3.gents_isHardProcess(); }
	const vector<bool> &gents_isLastCopy() { return cms3.gents_isLastCopy(); }
	const vector<int> &gents_gentaudecay() { return cms3.gents_gentaudecay(); }
	const int &gen_nfromtts_() { return cms3.gen_nfromtts_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_motherp4() { return cms3.gents_motherp4(); }
	const vector<int> &gents_motherid() { return cms3.gents_motherid(); }
	const vector<int> &gents_motheridx() { return cms3.gents_motheridx(); }
	const vector<int> &gents_motherstatus() { return cms3.gents_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gents_gmotherp4() { return cms3.gents_gmotherp4(); }
	const vector<int> &gents_gmotherid() { return cms3.gents_gmotherid(); }
	const vector<int> &gents_gmotheridx() { return cms3.gents_gmotheridx(); }
	const vector<int> &gents_gmotherstatus() { return cms3.gents_gmotherstatus(); }
	const vector<bool> &genqs_isfromt() { return cms3.genqs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4() { return cms3.genqs_p4(); }
	const vector<int> &genqs_id() { return cms3.genqs_id(); }
	const vector<int> &genqs__genpsidx() { return cms3.genqs__genpsidx(); }
	const vector<int> &genqs_status() { return cms3.genqs_status(); }
	const vector<bool> &genqs_fromHardProcessDecayed() { return cms3.genqs_fromHardProcessDecayed(); }
	const vector<bool> &genqs_fromHardProcessFinalState() { return cms3.genqs_fromHardProcessFinalState(); }
	const vector<bool> &genqs_isHardProcess() { return cms3.genqs_isHardProcess(); }
	const vector<bool> &genqs_isLastCopy() { return cms3.genqs_isLastCopy(); }
	const vector<int> &genqs_gentaudecay() { return cms3.genqs_gentaudecay(); }
	const int &gen_nfromtqs_() { return cms3.gen_nfromtqs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4() { return cms3.genqs_motherp4(); }
	const vector<int> &genqs_motherid() { return cms3.genqs_motherid(); }
	const vector<int> &genqs_motheridx() { return cms3.genqs_motheridx(); }
	const vector<int> &genqs_motherstatus() { return cms3.genqs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4() { return cms3.genqs_gmotherp4(); }
	const vector<int> &genqs_gmotherid() { return cms3.genqs_gmotherid(); }
	const vector<int> &genqs_gmotheridx() { return cms3.genqs_gmotheridx(); }
	const vector<int> &genqs_gmotherstatus() { return cms3.genqs_gmotherstatus(); }
	const vector<bool> &genbosons_isfromt() { return cms3.genbosons_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_p4() { return cms3.genbosons_p4(); }
	const vector<int> &genbosons_id() { return cms3.genbosons_id(); }
	const vector<int> &genbosons__genpsidx() { return cms3.genbosons__genpsidx(); }
	const vector<int> &genbosons_status() { return cms3.genbosons_status(); }
	const vector<bool> &genbosons_fromHardProcessDecayed() { return cms3.genbosons_fromHardProcessDecayed(); }
	const vector<bool> &genbosons_fromHardProcessFinalState() { return cms3.genbosons_fromHardProcessFinalState(); }
	const vector<bool> &genbosons_isHardProcess() { return cms3.genbosons_isHardProcess(); }
	const vector<bool> &genbosons_isLastCopy() { return cms3.genbosons_isLastCopy(); }
	const vector<int> &genbosons_gentaudecay() { return cms3.genbosons_gentaudecay(); }
	const int &gen_nfromtbosons_() { return cms3.gen_nfromtbosons_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_motherp4() { return cms3.genbosons_motherp4(); }
	const vector<int> &genbosons_motherid() { return cms3.genbosons_motherid(); }
	const vector<int> &genbosons_motheridx() { return cms3.genbosons_motheridx(); }
	const vector<int> &genbosons_motherstatus() { return cms3.genbosons_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_gmotherp4() { return cms3.genbosons_gmotherp4(); }
	const vector<int> &genbosons_gmotherid() { return cms3.genbosons_gmotherid(); }
	const vector<int> &genbosons_gmotheridx() { return cms3.genbosons_gmotheridx(); }
	const vector<int> &genbosons_gmotherstatus() { return cms3.genbosons_gmotherstatus(); }
	const vector<bool> &gensusy_isfromt() { return cms3.gensusy_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_p4() { return cms3.gensusy_p4(); }
	const vector<int> &gensusy_id() { return cms3.gensusy_id(); }
	const vector<int> &gensusy__genpsidx() { return cms3.gensusy__genpsidx(); }
	const vector<int> &gensusy_status() { return cms3.gensusy_status(); }
	const vector<bool> &gensusy_fromHardProcessDecayed() { return cms3.gensusy_fromHardProcessDecayed(); }
	const vector<bool> &gensusy_fromHardProcessFinalState() { return cms3.gensusy_fromHardProcessFinalState(); }
	const vector<bool> &gensusy_isHardProcess() { return cms3.gensusy_isHardProcess(); }
	const vector<bool> &gensusy_isLastCopy() { return cms3.gensusy_isLastCopy(); }
	const vector<int> &gensusy_gentaudecay() { return cms3.gensusy_gentaudecay(); }
	const int &gen_nfromtsusy_() { return cms3.gen_nfromtsusy_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_motherp4() { return cms3.gensusy_motherp4(); }
	const vector<int> &gensusy_motherid() { return cms3.gensusy_motherid(); }
	const vector<int> &gensusy_motheridx() { return cms3.gensusy_motheridx(); }
	const vector<int> &gensusy_motherstatus() { return cms3.gensusy_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_gmotherp4() { return cms3.gensusy_gmotherp4(); }
	const vector<int> &gensusy_gmotherid() { return cms3.gensusy_gmotherid(); }
	const vector<int> &gensusy_gmotheridx() { return cms3.gensusy_gmotheridx(); }
	const vector<int> &gensusy_gmotherstatus() { return cms3.gensusy_gmotherstatus(); }
}
