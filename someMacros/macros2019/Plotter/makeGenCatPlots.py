#! /usr/bin/env python
import os
import sys
import ROOT
# run in batch mode to suppress plot windows
ROOT.gROOT.SetBatch(1)

from MT2PlotMaker import *

base_plots = [
    ("met",True,None,None),
    # ("metbins",True,None,None),
    ("mt",True,None,None),
    #("metphi",True,None,None),
    ("njets",True,None,None),
    ("nbjets",True,None,None),
    ("tmod",True,None,None),
    ("tmod",True,None,None),
    ("mlepb",True,None,None),
    ("dphijmet",True,None,None),
    #("dphilmet",True,None,None),
    #("nvtxs",False,None,None),

    ("nsbtags",True,None,None),
    #("nak8jets",True,None,None),
    ("deepttag",True,None,None,6),
    # ("resttag",True,None,None,4),
    #("bdtttag",True,None,None,4),
    ("tfttag",True,None,None,4),
]

obj_plots = [
    #("lep1pt",True,None,None),
    #("lep1eta",True,None,None),
    # ("lep2pt",True,None,None),
    # ("lep2eta",True,None,None),

    #("jet1pt",True,None,None),
    # ("jet2pt",True,None,None),
    #("jet1eta",True,None,None),
    #("jet2eta",True,None,None),
]

rl_plots = [
    # ("mll",True,None,None,3),
    ("rlmet",True,None,None),
    ("rlmt",True,None,None),
    #("nleps",True,None,None),
    # ("rlmet_h",True,None,None),
    # ("rlmt_h",True,None,None),
    ("rltmod",True,None,None),
    ("rldphijmet",True,None,None),
    #("rldphilmet",True,None,None),
]

def addsuff(plotset, suf):
    for i in range(len(plotset)):
        x = list(plotset[i])
        x[0] += suf
        plotset[i] = tuple(x)
    return plotset


def makePlotsByGenCatRun2():

    # srNames = [  'srsbmet+srbase+srsbmt2' ]
    srNames = [  'srbase','cr0bbase','cr2lbase','srsbfmt','srsbfmt4' ]

    bvsuf = 'v31_m13'

    exts = ['pdf','C']
    bkgnames = ['ttbar', 'Vjets', 'singleT', 'rare'] # superceded byt gencats, but need to exist
    gencats   = ['2lep', '1lepTop', '1lepW', 'Znunu',]
    gencats0b = ['1lepW', '2lep', 'Znunu', '1lepTop',]

    for ysuf in ['16', '17', '18', 'run2']:
        if ysuf is not 'run2':
            continue
        bkg_set = ['allBkg_'+ysuf]
        dataname = 'allData_'+ysuf
        input_dir = '/home/users/sicheng/working/StopAnalysis/StopLooper/output/samp'+ysuf+'_'+bvsuf
        signame = 'SMS_all_'+ysuf
        output_dir = 'plots_'+ysuf+'_'+bvsuf+'_temp'
        if ysuf == 'run2':
            input_dir = '/home/users/sicheng/working/StopAnalysis/StopLooper/output/combRun2_'+bvsuf
        input_dir = '/home/users/haweber/fromSicheng/histograms'
        for sr in srNames:
            plot_set = base_plots+rl_plots if ('cr2l' in sr) else base_plots
            if sr == 'srsbfmt' or sr == 'srsbfmt4':
                plot_set = plot_set + [("mt_h",True,None,None),]
            cats = gencats0b if 'cr0b' in sr else gencats
            # MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, gencats=cats)
            if sr == 'srbase' or sr == 'srsbfmt' or sr == 'srsbfmt4':
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_900_500', 'T2bW_950_100','T2bt_750_400'],ratioType=1)#srsbfmt4_mt_h
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2bW_800_450', 'T2bt_750_400','T2tt_425_325'],ratioType=1)#srsbfmt_mt_h
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_1050_100', 'T2bW_950_100','T2tt_900_500'],ratioType=1)#srbase_deepttag
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_1050_100', 'T2bW_950_100','T2tt_900_500'],ratioType=1)#srbase_tfttag
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_900_500', 'T2bW_800_450','T2bt_750_400'],ratioType=1)#srbase_dphijmet #need usermax, l.10 of pyRootPlotMaker
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_1050_100', 'T2bW_950_100','T2bt_950_100'],ratioType=1)#srbase_met
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2bW_950_100', 'T2tt_900_500','T2bW_800_450'],ratioType=1)#srbase_mlepb
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2bW_950_100', 'T2bt_750_400','T2tt_425_325'],ratioType=1)#srbase_njets
                MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_1050_100', 'T2bt_950_100','T2bW_800_450'],ratioType=1)#srbase_tmod
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2tt_1050_100', 'T2tt_900_500','T2tt_425_325'],ratioType=1)
                #MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=['T2bt_950_100', 'T2bt_750_400','T2bW_950_100', 'T2bW_800_450'],ratioType=1)
            else:
                MT2PlotMaker(input_dir, bkg_set, dataname, sr, plot_set, output_dir, exts, scaleMC=False, gencats=cats, signame=signame, sig_points=[],ratioType=1)


if __name__ == '__main__':

    makePlotsByGenCatRun2()
