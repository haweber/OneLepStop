# MT2PlotUtils.py
# various plotting utilities

def GetColor(sample):
    if 'ttbar'   in sample: return 870  # kAzure+10
    if 'singleT' in sample: return 625  # kRed-7
    if 'Vjets'   in sample: return 798  # kOrange-2
    # if 'rare'    in sample: return 877  # kViolet-3
    if 'rare'    in sample: return 614  # kMagenta-2

    if 'tt2l'    in sample: return 866  # kAzure+6
    if 'tt1l'    in sample: return 861  # kAzure+1

    if 'data'    in sample: return 14   # Gray
    if 'lostlep' in sample: return 866  # kAzure+6
    if 'FromW'   in sample: return 796  # kOrange-4
    if 'FromTop' in sample: return 625  # kRed-7
    if 'ZToNuNu' in sample: return 613  # kMagenta-3

    if "2lep"    in sample: return 866  # kAzure+6
    if "1lepW"   in sample: return 796  # kOrange-4
    if "1lepTop" in sample: return 625  # kRed-7
    if "Znunu"   in sample: return 872  # kViolet-8

    return 870 # for everything else

def GetCRName(cr):
    names = {"crrlbase": "Removed Lepton CR",
             "cr2lbase" : "Dilepton CR",
             "cr0bbase" : "0 b-tag CR",
             "cr2lincl1" : "Dilepton CR 2-3j",
             "cr2lincl4J" : "Dilepton CR #geq 4j",
             }

    # use the above name if defined, otherwise use cr itself
    return names.get(cr,cr)

def GetSampleName(sample):
    names = {
        # "dyjetsll_ht": "Z(#font[12]{ll})+Jets",
        # "2015dyjetsll_ht": "Z(#font[12]{ll})+Jets",
        # "zinv_ht": "Z(#nu#nu)+Jets",
        # "2015zinv_ht": "Z(#nu#nu)+Jets",
        "lostlepFromCRs": "Lost Lepton",
        "lostlep": "Lost Lepton",
        "tt2l" : "t#bar{t}#rightarrow2 #font[12]{l}" ,
        "tt1l" : "t#bar{t}#rightarrow1 #font[12]{l}" ,
        "ttbar" : "t#bar{t}+Jets" ,
        "Vjets": "V+Jets",
        "singleT": "single top",
        "rare": "t#bar{t}V+VV",
        "TTZToLLNuNu": "t#bar{t}Z(#font[12]{#nu#nu})+Jets",
        "_16" : " 16" ,
        "_17" : " 17" ,
        "_18" : " 18" ,
        "_run2" : "" ,
        # "allData" : "allData" ,
        # "allBkg " : "allBkg" ,
        "_mrs0" : " no METRes corr." ,
        "_mrs2" : " w/ METRes corr." ,
        #"2lep" : "t#bar{t}/tW#rightarrow2 #font[12]{l}",
        #"1lepW" : "1#font[12]{l} from W",
        #"1lepTop" : "1#font[12]{l} from top",
        #"Znunu" : "Z#rightarrow #nu#nu",
        "2lep" : "Lost lepton",
        "1lepW" : "W+jets",
        "1lepTop" : "t#bar{t}/tW#rightarrow1#font[12]{l}",
        "Znunu" : "Z#rightarrow #nu#bar{#nu}",
    }

    # use the above name if defined, otherwise use sample itself
    for k, v in names.items():
        if k in sample:
            sample = sample.replace(k, v)

    # return names.get(sample,sample)
    return sample

def GetVarName(var):
    names = {"ht": "H_{T}",
             "met": "E_{T}^{miss}",
             "rlmet": "E_{T}^{miss}",
             "mt2": "M_{T2}",
             "mt" : "M_{T}",
             "mt_h" : "M_{T}",
             "metbins": "E_{T}^{miss}",
             "mt2bins": "M_{T2}",
             "nJet30": "N(jet)",
             "nBJet20": "N(b jet)",
             "njets": "N_{J}",
             "nbjets": "N_{b}",
             "nsbtags": "N_{soft b}",
             "tmod": "t_{mod}",
             "rltmod": "t_{mod}",
             "mlepb": "M_{#font[12]{l}b}",
             "dphijmet": "min#Delta#phi(j_{1,2}, E_{T}^{miss})",
             "deepttag": "Discriminant of merged top quark tagger algorithm",
             "tfttag": "Discriminant of resolved top quark tagger algorithm",
             "leppt": "p_{T}(lep)",
             "lepeta": "#eta(lep)",
             "lep1pt": "p_{T}(lep1)",
             "lep1eta": "#eta(lep1)",
             "lep2pt": "p_{T}(lep2)",
             "lep2eta": "#eta(lep2)",
             "nlepveto": "N(veto lep)",
             "zllmass": "m_{#font[12]{ll}}",
             "gammaPt": "P_{T}(#gamma)",
             "gammaEta": "#eta(#gamma)",
             "jet1pt": "Leading jet p_{T}",
             }

    if "SigmaIetaIeta" in var:
        return "Photon #sigma_{i#eta i#eta}"

    # use the above name if defined, otherwise use var itself
    return names.get(var,var)

def GetUnit(vn):
    noUnit = ["nJet","nBJet","eta","nlep","drMin","SigmaIetaIeta", "njets", "nbjets", "nsbtags", "tmod", "rltmod", "dphijmet", "deepttag", "tfttag"]
    for s in noUnit:
        if s.lower() in vn.lower():
            return None

    return "GeV"

def GetSubtitles(dirname):
    # do special cases first
    # if dirname=="crqcdbaseJ":
    #     return ["p_{T}(jet1) > 250 GeV", "N(jet) = 2"]

    met = "E_{T}^{miss}"
    mt  = "M_{T}"
    if "cr2l" in dirname:
        met = "E_{T}^{miss}(rl)"
        mt  = "M_{T}(rl)"

    subtitle = [met+" > 250 GeV", mt+" > 150 GeV", "#geq 2j, #geq 1b"]

    if "I" in dirname: subtitle[2] = "#geq 5j, #geq 1 med-b"
    if "J" in dirname: subtitle[2] = "#geq 3j, #geq 1 soft-b"

    if "cr0b" in dirname:
        subtitle[2] = "#geq 2j, = 0b"
        if "J" in dirname: 
            subtitle[2] = "#geq 3j, =0med-b, =0soft-b"

    if "cremu" in dirname:
        subtitle = [met+" > 50 GeV", "M(e#mu) > 20 GeV", "#geq 2j, #geq 0b"]
        if   "A1" in dirname: subtitle[2] = "#geq 2j, #geq 1b"
        elif "A2" in dirname: subtitle[2] = "#geq 2j, #geq 2b"
        elif "A3" in dirname: subtitle[2] = "#geq 2j, = 2b"
        elif "B0" in dirname: subtitle[2] = "#geq 2j, 0b"
        elif "B1" in dirname: subtitle[2] = "#geq 2j, 1b"

        if "emuM" in dirname: subtitle[2] = "#geq 2j, 1b"
        if   "M1" in dirname: subtitle[1] = "50 GeV < "+met+"< 100 GeV "
        elif "M2" in dirname: subtitle[1] = "150 GeV < "+met+"< 250 GeV "
        elif "M3" in dirname: subtitle[1] = met+" > 250 GeV"

    if "sbmet"  in dirname:
        subtitle[0] = "150 GeV < "+met+" < 250 GeV"
        if "sbmet2" in dirname:
            subtitle[1] = mt+" > 0 GeV"
            subtitle[2] = "#geq 4j, #geq 1b"
    if "sbmt" in dirname:
        subtitle[1] = "0 GeV < "+mt+" < 150 GeV"
    if "sbfmt" in dirname:
        subtitle[1] = mt+" > 0 GeV"
    if "sbfull" in dirname:
        subtitle[0] = met+" > 150 GeV"
        subtitle[1] = mt+" > 0 GeV"
    if "incl1" in dirname:
        subtitle[2] = "2-3j, #geq 1b"
    if "incl4J" in dirname:
        subtitle[2] = "#geq 4j, #geq 1b"

    return subtitle

def Rebin(h_bkg_vec, h_sig_vec, h_data, r):
    for h in h_bkg_vec:
        h.Rebin(r)
    for h in h_sig_vec:
        h.Rebin(r)
    if h_data!=None:
        h_data.Rebin(r)
