#! /usr/bin/env python
import os
import sys
import ROOT
# run in batch mode to suppress plot windows
ROOT.gROOT.SetBatch(1)

from MT2PlotMaker import *

exts = ['pdf']
bkgnames = ['ttbar', 'Vjets', 'singleT', 'rare']
# bkgnames = ['tt2l', 'Vjets', 'singleT', 'tt1l', 'rare']
gencats   = ['2lep', '1lepTop', '1lepW', 'Znunu',]
gencats0b = ['1lepW', '2lep', 'Znunu', '1lepTop',]

base_plots = [
    ("met",True,None,None),
    ("metbins",True,None,None),
    ("mt",True,None,None),
    ("njets",True,None,None),
    ("metphi",True,None,None),
    ("njets",True,None,None),
    ("nbjets",True,None,None),
    ("tmod",True,None,None),
    ("mlepb",True,None,None),
    ("dphijmet",True,None,None),
    ("dphilmet",True,None,None),
    ("nvtxs",False,None,None),

    ("nsbtags",True,None,None),
    ("nak8jets",True,None,None),
    ("deepttag",True,None,None,6),
    # ("resttag",True,None,None,4),
    ("bdtttag",True,None,None,4),
    ("tfttag",True,None,None,4),
]

obj_plots = [
    ("lep1pt",True,None,None),
    ("lep1eta",True,None,None),
    # ("lep2pt",True,None,None),
    # ("lep2eta",True,None,None),

    ("jet1pt",True,None,None),
    # ("jet2pt",True,None,None),
    ("jet1eta",True,None,None),
    ("jet2eta",True,None,None),
]

rl_plots = [
    # ("mll",True,None,None,3),
    ("rlmet",True,None,None),
    ("rlmt",True,None,None),
    ("nleps",True,None,None),
    # ("rlmet_h",True,None,None),
    # ("rlmt_h",True,None,None),
    ("rltmod",True,None,None),
    ("rldphijmet",True,None,None),
    ("rldphilmet",True,None,None),
]

cor_plots = [
    ("met",True,None,None),
    ("mt",True,None,None),
    ("njets",True,None,None),
    ("metphi",True,None,None),
    ("njets",True,None,None),
    ("nbjets",True,None,None),
    ("dphijmet",True,None,None),
    ("dphilmet",True,None,None),
    ("nvtxs",False,None,None),

    ("lep1pt",True,None,None),
    ("nsbtags",True,None,None),
    ("nak8jets",True,None,None),
]

emu_plots = [
    ("metbins",True,(50,800),None),
    ("rlmetbins",True,(50,800),None),
    ("met_h",True,None,None),
    ("mt_h",True,None,None),
    ("mll",True,None,None),
    ("ptll",True,None,None,2),
    ("ptbb",True,None,None,2),

    ("njets",True,None,None),
    ("nbjets",True,None,None),
    # ("topness",True,None,None),
    # ("jet1pt",True,None,None),

    # ("rlmet",True,None,None),
    # ("metorg",True,None,None),
    # ("jetpt_200nonb",True,None,None),
    # ("njet_200nonb",True,None,None),

    # ("mtttbar",True,None,None),
    ("ptttbar",True,None,None),
    ("ptttbar_b1",True,(0,800),None),
    ("ptisr_b1",True,(0,800),None),
    ("htisr_b1",True,(0,800),None),
]

emu_met = [
    ("metbinA",True,None,None),
    ("metbinB",True,None,None),
    ("metbinC",True,None,None),
    ("metbinE",True,None,None),
    ("metbinG",True,None,None),
    ("metbinH",True,None,None),
]

sb_plots = [
    ("met_h",True,None,None),
    ("met_s",True,(150, 250),None),
    ("mt_s",True,None,None),
    ("metphi",True,None,None),
    ("dphijmet",True,None,None),
    ("dphilmet",True,None,None),
    ("njets",True,None,None),
    ("nbjets",True,None,None),
    ("lep1pt",True,None,None),
    ("lep1eta",True,None,None),
    ("lep1phi",True,None,None),
    ("dphiWlep",True,None,None),
    ("dphiWmet",True,None,None),
    ("nvtxs",False,None,None),
    ("tmod",True,None,None),

    # ("met_rs",True,None,None),
    # ("mt_rs",True,None,None),
    # ("metphi_rs",True,None,None),
    # ("dphijmet_rs",True,None,None),
    # ("dphilmet_rs",True,None,None),
]

def addsuff(plotset, suf):
    for i in range(len(plotset)):
        x = list(plotset[i])
        x[0] += suf
        plotset[i] = tuple(x)
    return plotset


def makePlotsByGenCatRun2():

    # srNames = ['cr2lbase', 'cr0bbase']
    # srNames = ['cr2lJ3', 'cr0bJ3']
    # srNames = [ 'srsbfmt', 'srsbfull', ]
    srNames = [  'srsbmet+srbase+srsbmt2' ]
    # srNames = ['cr2lincl1', 'cr2lincl4J']
    base_plots = [("mt_h",True,None,None),("met_h",True,None,None),]
    # srNames = ['cr2lI', 'cr0bI', 'cr2lJ', 'cr0bJ']

    # bvsuf = 'v39_s6'
    bvsuf = 'v31_m13'
    # bvsuf = 'v31_cor_w2'

    gencats = [ '1lepTop', '1lepW', '2lep', 'Znunu',]

    for ysuf in ['16', '17', '18']:
    # for ysuf in ['18']:
    # for ysuf in ['run2']:
        bkg_set = ['allBkg_'+ysuf]
        dataname = 'allData_'+ysuf
        dataname = None
        input_dir = '../../StopLooper/output/samp'+ysuf+'_'+bvsuf
        # output_dir = 'plots_'+ysuf+'_MCunscaled_'+bvsuf
        output_dir = 'plots_'+ysuf+'_'+bvsuf+'_nodata'
        # output_dir = 'plots_'+ysuf+'_'+bvsuf
        if ysuf == 'run2':
            input_dir = '../../StopLooper/output/combRun2_'+bvsuf

        for sr in srNames:
            plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
            cats = gencats0b if 'cr0b' in sr else gencats
            MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, gencats=cats)
            # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats)


def makeCRbasePlotsRun2():

    # bkgnames = ['ttbar', 'Vjets', 'singleT', 'rare']
    # bkgrar0b = ['Vjets', 'ttbar', 'singleT', 'rare']

    # srNames = ['cr2lbase', 'cr0bbase']
    # srNames = ['cr2lincl1', 'cr2lincl2+cr2lincl3+cr2lincl4']
    # srNames = ['cr2lsbfmt']
    # srNames = ['cr0bsbfull']
    # srNames = ['cr2lI', 'cr0bI', 'cr2lJ', 'cr0bJ']
    # srNames = ['srJ0', 'srJ1', 'srJ2', 'srJ3', 'srJ4']
    srNames = [ 'cr2lJ3', 'cr0bJ3']

    # base_plots.append(("met_h",True,None,None))
    # base_plots = [("met_h",True,None,None), ("mt_s",True,None,None), ("lep1pt",True,None,None), ("dphilmet",True,None,None)]
    # base_plots = [("met_h",True,None,None), ("mt_h",True,None,None), ("lep1pt",True,None,None), ("dphilmet",True,None,None)]
    # base_plots = [("mt",True,None,None), ("mlepb",True,None,None)]
    # base_plots = addsuff(base_plots, '_mu')

    bvsuf = 'v31_s8'

    # 2016 parameters
    input_dir = '../../StopLooper/output/samp16_'+bvsuf
    output_dir = 'plots16_'+bvsuf
    bkg_set = [fn+'_16' for fn in bkgnames]
    dataname = 'allData_16'

    # for sr in srNames:
    #     plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
    #     bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
    #     MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts)

    # 2017 parameters
    input_dir = '../../StopLooper/output/samp17_'+bvsuf
    # input_dir = '../../StopLooper/output/samp17_v39_mrs2'
    output_dir = 'plots17_'+bvsuf
    bkg_set = [fn+'_17' for fn in bkgnames]
    dataname = 'allData_17'

    # for sr in srNames:
    #     plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
    #     bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
    #     MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts)

    # 2018 parameters
    bvsuf = 'v31_cor_w2'
    input_dir = '../../StopLooper/output/samp18_'+bvsuf
    output_dir = 'plots18_'+bvsuf
    bkg_set = [fn+'_18' for fn in bkgnames]
    dataname = 'allData_18'
    # dataname = None
    # signame = 'SMS_T2tt_18'

    # for sr in srNames:
    #     plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
    #     bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
    #     # MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts)
    #     MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, signame=signame, sig_points=['425_325','450_325'])

    # Combined dataset parameters
    input_dir = '../../StopLooper/output/combRun2_'+bvsuf
    output_dir = 'plotsRun2_'+bvsuf
    bkg_set = [fn+'_run2' for fn in bkgnames]
    dataname = 'allData_run2'
    # dataname = None
    signame = 'SMS_T2tt_run2'

    for sr in srNames:
        plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
        bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
        MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts)
        # MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, signame=signame, sig_points=['800_675',])
        # MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, signame=signame, sig_points=['425_325','450_325'])

    # srNames = ['cr2lbase', 'cr0bbase', 'srsbmet', 'cr2lsbmet']

    # for sr in srNames:
    #     plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
    #     plot_set = plot_set[1:] if 'sbmet' in sr else base_plots+emu_plots if 'cremu' in sr else plot_set
    #     bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
    #     MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, scaleMC=True)



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Special plots
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

def makeCRemuPlots():

    # for sr in srNames:
    #     plot_set = base_plots+obj_plots+rl_plots if ('cr2l' in sr) else base_plots+obj_plots
    #     plot_set = addsuff(plot_set[:2],'_h')+plot_set[2:] if 'sb' in sr else base_plots+obj_plots+rl_plots+emu_plots if 'cremu' in sr else plot_set
    #     # plot_set = [(x+'_h' if (x == "met" or x == "rlmet") else x) for x in plot_set] if 'sbmet' in sr else plot_set
    #     # addsuff(plot_set, '_el')
    #     bkg_rearr = [bkg_set[1], bkg_set[0]] + bkg_set[2:] if 'cr0b' in sr else bkg_set
    #     MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, scaleMC=True)
    #     # MT2PlotMaker(input_dir, bkg_rearr, dataname, sr, plot_set, output_dir, exts, scaleMC=True, suffix='_jesDn')

    bkgnames = ['ttbar', 'singleT', 'Vjets', 'rare']

    bvsuf = 'v31_cremu1'
    srNames = ['cremuA1', 'cremuA2', 'cremuA3']
    # srNames = ['cremuA0']
    # plot_set = [("ptttbar",True,None,None), ("ptttbar_b1",True,None,None)]
    plot_set = emu_plots

    srNames = ['cremuA1',]
    plot_set = [
        ("rlmetbinA",True,None,None),
        ("rlmetbinB",True,None,None),
        ("rlmetbinC",True,None,None),
        ("rlmetbinE",True,None,None),
        ("rlmetbinG",True,None,None),
        ("rlmetbinH",True,None,None),
        ("rlmetbinI",True,None,None),
        ("rlmetbinJ",True,None,None),
    ]

    input_dir = '../../StopLooper/output/samp16_'+bvsuf
    output_dir = 'plots16_'+bvsuf
    bkg_set = [fn+'_16' for fn in bkgnames]
    dataname = 'allData_16'

    for sr in srNames:
        MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, systset=['ISR'])

    input_dir = '../../StopLooper/output/samp17_'+bvsuf
    output_dir = 'plots17_'+bvsuf
    bkg_set = [fn+'_17' for fn in bkgnames]
    # bkg_set = ['TTJets_amcnlo',] + bkg_set[1:]
    dataname = 'allData_17'

    for sr in srNames:
        MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, systset=['ISR'])

    # bvsuf = 'v37_m1'
    input_dir = '../../StopLooper/output/samp18_'+bvsuf
    output_dir = 'plots18_'+bvsuf
    bkg_set = [fn+'_18' for fn in bkgnames]
    dataname = 'allData_18'

    for sr in srNames:
        MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1)
        # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, systset=['ISR'])

    input_dir = '../../StopLooper/output/combRun2_'+bvsuf
    output_dir = 'plots_run2_'+bvsuf
    bkg_set = [fn+'_run2' for fn in bkgnames]
    dataname = 'allData_run2'

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts)
    #     # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1)
    #     # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, systset=['ISR'])


# # # # # # # # # # # # # # # # # # # # # # # # #
# Study for the 2017 samples with MET recipe v2

def makePlotsvMETandErra():
    input_dir = '../../StopLooper/output/combRun2_v37_m3'
    # input_dir = '../../StopLooper/output/data17_v30_leptrig'
    # output_dir = 'plots17_31MarFvs09MayF_metv0'
    output_dir = 'plots17_vMETandEra'
    # bkg_set = ['data_2017F_31Mar_METv2',]
    bkg_set = ['data_2017BtoE_METv2',]
    dataname = 'data_2017F_09May_METv2'
    srNames = ['cr2lbase', 'cr2lsbmet',]
    # srNames = ['cremuA0', 'cremuA1',]
    # srNames += ['srsbmet2', 'cr2lsbmet2', 'srsbmt', 'cr2lsbmt']
    srNames = ['srsbmet2','cr0bsbmet2',]
    # srNames = ['srsbmet2']
    # srNames = ['srsbmt']

    plot_set = sb_plots
    # plot_set = base_plots

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)

    # bkg_set = ['data_2017BtoE_METv2',]
    # dataname = 'data_2017F_31Mar_METv2'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/31MarFvsBtoE_metv2_{1}; mv {0}/{1} {0}/31MarFvsBtoE_metv2_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017BtoE_METv0',]
    # dataname = 'data_2017F_09May_METv0'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayFvsBtoE_metv0_{1}; mv {0}/{1} {0}/09MayFvsBtoE_metv0_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017BtoE_METv2',]
    # dataname = 'data_2017F_09May_METv2_purwgtd'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayFvsBtoE_metv2_purw_{1}; mv {0}/{1} {0}/09MayFvsBtoE_metv2_purw_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017BtoE_METv2',]
    # dataname = 'data_2017F_09May_METv2'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayFvsBtoE_metv2_{1}; mv {0}/{1} {0}/09MayFvsBtoE_metv2_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017BtoE_METv2',]
    # dataname = 'data_2017F_09May_METv0'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayFvsBtoE_metv0vsv2_{1}; mv {0}/{1} {0}/09MayFvsBtoE_metv0vsv2_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017F_09May_METv2',]
    # dataname = 'data_2017F_09May_METv0'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayF_metv0vsv2_{1}; mv {0}/{1} {0}/09MayF_metv0vsv2_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017F_31Mar_METv2',]
    # dataname = 'data_2017F_09May_METv0'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/09MayFvs31MarF_metv0vsv2_{1}; mv {0}/{1} {0}/09MayFvs31MarF_metv0vsv2_{1}'.format(output_dir, sr))

    # bkg_set = ['data_2017BtoE_METv2',]
    # dataname = 'data_2017BtoE_METv0'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/BtoE_metv0vsv2_{1}; mv {0}/{1} {0}/BtoE_metv0vsv2_{1}'.format(output_dir, sr))

    # input_dir = '../../StopLooper/output/samp17_v37_m6'
    input_dir = '../../StopLooper/output/samp17_v39_mrs0'
    output_dir = 'plots_samp17_v39'
    # input_dir = '../../StopLooper/output/samp18_v39_m4'
    # output_dir = 'plots18_v39_m4'
    # bkg_set = ['Vjets_17', 'ttbar_17', 'singleT_17', 'rare_17']
    # bkg_set = ['ttbar_17', 'Vjets_17', 'singleT_17', 'rare_17']
    # bkg_set = ['tt1l_17', 'tt2l_17', 'Vjets_17', 'singleT_17', 'rare_17']
    bkg_set = ['Vjets_17', 'tt1l_17', 'tt2l_17', 'singleT_17', 'rare_17']
    # dataname = 'allData_09May_17'
    # dataname = 'allData_31Mar_17'
    dataname = 'data_2017F_31Mar'
    # srNames = ['cr0bsbmet2','cr0bsbmt','cr0bsbfull']
    # plot_set = [("mt_s",True,None,None), ("dphilmet",True,None,None), ("mt_rs",True,None,None), ("dphilmet_rs",True,None,None),("nvtxs",False,None,None),]
    plot_set = [("mt_s",True,None,None), ("dphilmet",True,None,None), ]
    # plot_set = [("rlmt_h",True,None,None), ("rldphilmet",True,None,None),]
    # plot_set = base_plots
    # srNames = ['cr0bsbfmt']
    # srNames = ['cr0bbase']
    srNames = ['cr0bsbmet2']
    # for sr in srNames:
    #     # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname, scaleMC=1.0)
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname)
    #     os.system('rm -r {0}/{1}_v39mrs0_F; mv {0}/{1} {0}/{1}_v39mrs0_F'.format(output_dir, sr))
    #     # os.system('rm -r {0}/{1}_mrsF3_31Mar; mv {0}/{1} {0}/{1}_mrsF3_31Mar'.format(output_dir, sr))
        # os.system('rm -r {0}/{1}_v37m6; mv {0}/{1} {0}/{1}_v37m6'.format(output_dir, sr))

    # input_dir = '../../StopLooper/output/samp18_v39_m6'
    # output_dir = 'plots18_v39_metres'
    # # bkg_set = ['Vjets_18', 'tt1l_18', 'tt2l_18', 'singleT_18', 'rare_18']
    # bkg_set = ['tt1l_18', 'tt2l_18', 'Vjets_18', 'singleT_18', 'rare_18']
    # srNames = ['srsbmet2']
    # dataname = 'allData_18'
    # for sr in srNames:
    #     # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname, scaleMC=False)
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname)
    #     os.system('rm -r {0}/{1}_v39mrs0; mv {0}/{1} {0}/{1}_v39mrs0'.format(output_dir, sr))

    # input_dir = '../../StopLooper/output/samp16_v39_m6_trigonMC'
    # output_dir = 'plots16_v39_metres'
    # # bkg_set = ['Vjets_16', 'tt1l_16', 'tt2l_16', 'singleT_16', 'rare_16']
    # bkg_set = ['tt1l_16', 'tt2l_16', 'Vjets_16', 'singleT_16', 'rare_16']
    # srNames = ['srsbmet2']
    # # srNames = ['cr2lbase']
    # # plot_set = base_plots
    # dataname = 'allData_16'
    # # dataname = 'data_2016B'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname)
    #     os.system('rm -r {0}/{1}_v39mrs0_trigonMC; mv {0}/{1} {0}/{1}_v39mrs0_trigonMC'.format(output_dir, sr))

    bvsuf = 'v31_m3_ht5cut'
    # bvsuf = 'v31_m3'
    # srNames = ['srsbmt', 'srsbmet2', 'cr0bsbmt', 'cr0bbase']
    # srNames = [ 'cr2lbase',]
    srNames = [ 'cr0bbase',]
    # srNames = [ 'srsbmet2',]

    plot_set = [
        # ("mht",True,None,None,3),
        # ("mhtovermet",True,None,None,3),
        # ("diffmhtmet",True,None,None,3),
        # ("met_s",True,None,None,2),
        # ("metphi",False,None,None,2),
        ("dphilmet",True,None,None,2),
        # ("lep1pt_lowMHT",True,None,None,2),
        # ("lep1pt",True,None,None,2),
        ("mt_s",True,None,None,2),
        ("met_h",True,None,None,2),
        ("metphi",False,None,None,2),
        # ("rlmet",True,None,None,2),
        # # ("rlmetphi",False,None,None,2),
        # ("uncormet",True,None,None,2),
        # ("uncormetphi",False,None,None,2),
        # ("cmet",True,None,None,2),
        # ("cmetphi",False,None,None,2),
        # ("rmet",True,None,None,2),
        # ("rmetphi",False,None,None,2),
        # ("rlcmet",True,None,None,2),
        # ("rlcmetphi",False,None,None,2),
        # ("rldphilmet",False,None,None,2),
        # ("rldphilcmet",False,None,None,2),
    ]

    input_dir = '../../StopLooper/output/samp16_'+bvsuf
    output_dir = 'plots_v31_s3'
    dataname = 'allData_16'
    bkg_set = ['Vjets_16', 'tt1l_16', 'tt2l_16', 'singleT_16', 'rare_16']
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname)
    #     os.system('rm -r {0}/{1}_all2016; mv {0}/{1} {0}/{1}_all2016'.format(output_dir, sr))

    input_dir = '../../StopLooper/output/samp17_'+bvsuf
    # input_dir = '../../StopLooper/output/samp17_s3'
    output_dir = 'plots_v31_s3'
    # bkg_set = ['data_2017BtoE',]
    # dataname = 'data_2017F'
    # dataname = 'data_2017BtoE'
    # dataname = 'data_2017F'
    # dataname = 'allData_17'
    # bkg_set = [ 'Vjets_17', 'tt1l_17', 'singleT_17', 'tt2l_17', 'rare_17']
    # for sr in srNames:
    #     # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname, scaleMC=0.326)
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname)
    #     # os.system('rm -r {0}/{1}_2017FvsBtoE; mv {0}/{1} {0}/{1}_2017FvsBtoE'.format(output_dir, sr))
    #     # os.system('rm -r {0}/{1}_2017BtoEvsMC; mv {0}/{1} {0}/{1}_2017BtoEvsMC'.format(output_dir, sr))
    #     # os.system('rm -r {0}/{1}_2017FvsMC_ht5; mv {0}/{1} {0}/{1}_2017FvsMC_ht5'.format(output_dir, sr))
    #     os.system('rm -r {0}/{1}_2017vsMC; mv {0}/{1} {0}/{1}_2017FvsMC'.format(output_dir, sr))

    # bvsuf = 'v31_s5'
    # bvsuf = 'v31_cremu2_METxy'
    bvsuf = 'v31_nxy'
    input_dir = '../../StopLooper/output/samp18_'+bvsuf
    output_dir = 'plots_v31_s3'
    # bkg_set = ['data_2018A',]
    # dataname = 'data_2018D'
    # dataname = 'data_2017BtoE'
    # bkg_set = ['Vjets_18', 'tt1l_18', 'tt2l_18', 'singleT_18', 'rare_18']
    # srNames = [ 'cremuM1', 'cremuM2', 'cremuM3']
    srNames = [ 'cr0bbase']
    # srNames = [ 'cremuA1',]
    bkg_set = ['tt2l_18', 'tt1l_18', 'Vjets_18', 'singleT_18', 'rare_18']
    dataname = 'allData_18'
    for sr in srNames:
        MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, datatitle=dataname )
        # os.system('rm -r {0}/{1}_2018DvsA; mv {0}/{1} {0}/{1}_2018DvsA'.format(output_dir, sr))
        os.system('rm -r {0}/{1}_2018vsMC_xyonly; mv {0}/{1} {0}/{1}_2018vsMC_xyonly'.format(output_dir, sr))


def makePlots17vs18():
    # input_dir = '../../StopLooper/output/samp17_v37_m3'
    input_dir = '../../StopLooper/output/combRun2_v37_m3'
    output_dir = 'plots_17vs18_metv0'
    bkg_set = ['allData_17',]
    dataname = 'allData_18'
    # srNames = ['srsbmet2','cr0bsbmet2',]
    # srNames = ['cremuA0','cremuA1' ]
    # srNames = ['cr2lbase','cr0bbase' ]
    srNames = ['cr0bbase', ]
    # plot_set = sb_plots
    plot_set = base_plots
    # plot_set = base_plots

    # bkg_set = ['data_2017BtoE_METv0',]
    # # dataname = 'allData_18'
    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system('rm -r {0}/{1}_18vs17BtoE_metv0; mv {0}/{1} {0}/{1}_18vs17BtoE_metv0'.format(output_dir, sr))

    # MT2PlotMaker(input_dir, bkg_set, dataname, 'srsbmet3', sb_plots, output_dir, exts, ratioType=1, scaleMC=0.49)


def makeComparisomPlotsForSysts():
    input_dir = '../../StopLooper/output/combRun2_v37_m3'

    srNames = ['cremuA0', 'cremuA1']
    # srNames += ['srsbmet2', ]
    # srNames = ['srsbmet2','cr0bsbmet2','srsbmet2m','cr0bsbmet2m']
    gen_plots = [
        ("genttbar_pt",True,None,None),
        ("genttbar_mt",True,None,None),
        ("genttbar_p",True,None,None),
        ("genttbar_M",True,None,None),
        ("nisrmatch",True,None,None),
        ("genttbar_ptb1",True,None,None),
    ]

    output_dir = 'plots_16vs17_metv0'
    bkg_set = ['allData_16',]
    dataname = 'allData_17'

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, emu_plots, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system("mv {0}/{1} {0}/data_{1}".format(output_dir, sr))

    input_dir = '../../StopLooper/output/samp17_v30_cremu4'
    output_dir = 'plots_16vs17'
    bkg_set = ['ttbar_16_unscaled',]
    dataname = 'ttbar_17'

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, emu_plots+gen_plots, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system("rm -r {0}/ttbar_{1}_uns16; mv {0}/{1} {0}/ttbar_{1}_uns16".format(output_dir, sr))

    bkg_set = ['ttbar_16_scaled',]
    dataname = 'ttbar_17'

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, emu_plots+gen_plots, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system("rm -r {0}/ttbar_{1}_s16v17; mv {0}/{1} {0}/ttbar_{1}_s16v17".format(output_dir, sr))

    bkg_set = ['ttbar_16_unscaled',]
    dataname = 'ttbar_16_scaled'

    # for sr in srNames:
    #     MT2PlotMaker(input_dir, bkg_set, dataname, sr, emu_plots+gen_plots, output_dir, exts, ratioType=1, datatitle=dataname)
    #     os.system("rm -r {0}/ttbar_{1}_s16v16; mv {0}/{1} {0}/ttbar_{1}_s16v16".format(output_dir, sr))

    input_dir = '../../StopLooper/output/comb16_v39_mrs'
    output_dir = 'plots16_v39_metres'
    bkg_set = ['allBkg_16_mrs0',]
    dataname = 'allBkg_16_mrs2'
    srNames = [ 'srsbfmt']
    plot_set = sb_plots
    # plot_set = [("mt_h",True,None,None),]
    srNames = ['cr0bsbmet2',]
    # plot_set = base_plots+rl_plots

    for sr in srNames:
        MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, ratioType=0, scaleMC=False, datatitle='allBkg 18 w/ METRes corr.')
        os.system("rm -r {0}/{1}_mrsOnvsOff; mv {0}/{1} {0}/{1}_mrsOnvsOff".format(output_dir, sr))


if __name__ == '__main__':

    # plotsSignalRegions()

    makePlotsByGenCatRun2()

    # makeCRbasePlotsRun2()

    # makePlotsvMETandErra()

    # makeCRemuPlots()

    # makeComparisomPlotsForSysts()
