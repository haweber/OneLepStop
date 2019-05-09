import os
import numpy as np
import ROOT
import pyRootPlotMaker as ppm
import MT2PlotUtils as utils

def MT2PlotMaker(rootdir, samples, data, dirname, plots, output_dir=".", exts=["pdf"], tag="", scaleMC=True, suffix = None,
                 datatitle = 'Observed', systset=None, lumi=None, ratioType=0, signame=None, sig_points=None, gencats=None):
    '''
    rootdir contains output of MT2Looper, samples are names of the .root files,
    data is the name of the data file, dirname is the directory within the root file
    to extract plots from, plots are a list of plot definitions from MT2PlotDefs
    exts is a list of file extensions to produce
    note that dirname can be a '+' separated string of directories to add together
    '''

    h_bkg_vecs = [[] for x in plots]
    h_data = []

    dirnames = [s.strip() for s in dirname.split("+")]

    dogencat = False
    ncats = len(samples)
    if type(gencats) == list and ncats == 1:
        ncats = len(gencats)
        dogencat = True

    if lumi==None:
        if 'samp16' in rootdir: lumi = 35.9
        if 'samp17' in rootdir: lumi = 41.5
        if 'samp18' in rootdir: lumi = 59.7
        if 'Run2'   in rootdir: lumi = 137.2

    if lumi==None:
        if  '16'  in data: lumi = 35.9
        if  '17'  in data: lumi = 41.5
        if  '18'  in data: lumi = 59.7
        if 'run2' in data: lumi = 137.2

    ## deal with suffixes
    # crdybaseInclLowPtOF means that we should take the plots in crdybaseIncl that end in LowPt
    # crdybaseInclLowPtSF means that we should take the plots in crdybaseIncl that end in LowPtemu
    if suffix != None and suffix != '' and suffix[0] != '_':
        suffix = '_'+suffix

    systs = [None for x in plots]
    drawSystematicBand = False
    if systset is not None and type(systset)==list:
        drawSystematicBand = True
        systs = [[] for x in plots]
        h_bkg_vecs_syst_up = [[[] for s in systset] for p in plots ]
        h_bkg_vecs_syst_dn = [[[] for s in systset] for p in plots ]

    #     nbins = h_mt2bins_data.GetNbinsX()
    #     systs = [0 for i in range(nbins)]
    #     ## get systematic in first bin
    #     incr = 0
    #     for ibin in range(2,nbins+1):
    #         incr += 0.4 / (nbins-1) * (ibin-1) * h_mt2bins_data.GetBinContent(i)
    #     systs[0] = incr/h_mt2bins_data.GetBinContent(1)
    #     ## get systematics in other bins
    #     for ibin in range(2,nbins+1):
    #         systs[ibin-1] = 0.4 / (nbins-1) * (ibin-1)


    ## get background histograms
    for icat in range(ncats):
        # get the root file for the given sample. This assumes that frag/fake photons come from qcd_ht.root
        if dogencat:
            fn = os.path.join(rootdir, samples[0]+".root")
        else:
            fn = os.path.join(rootdir, samples[icat]+".root")
        fid = ROOT.TFile(fn)

        for iplot in range(len(plots)):
            vn = plots[iplot][0]
            if dogencat: vn += '_'+gencats[icat]
            if suffix != None: vn += suffix
            h_bkg_vecs[iplot].append( fid.Get(dirnames[0]+"/h_"+vn) )

            # histogram won't exist if there are no events. Replace it with None, handle later
            if type(h_bkg_vecs[iplot][-1])==type(ROOT.TObject()):
                h_bkg_vecs[iplot][-1] = None
            else:
                h_bkg_vecs[iplot][-1].SetDirectory(0)
                # handle the case with more than one directory
                for idir in range(1, len(dirnames)):
                    h_bkg_vecs[iplot][-1].Add(fid.Get(dirnames[idir]+"/h_"+vn))

            if drawSystematicBand:
                for isys, sys in enumerate(systset):
                    h_bkg_vecs_syst_up[iplot][isys].append( fid.Get("{}/h_{}_{}Up".format(dirnames[0],vn,sys)) )
                    h_bkg_vecs_syst_dn[iplot][isys].append( fid.Get("{}/h_{}_{}Dn".format(dirnames[0],vn,sys)) )
                    h_bkg_vecs_syst_up[iplot][isys][-1].SetDirectory(0)
                    h_bkg_vecs_syst_dn[iplot][isys][-1].SetDirectory(0)

        fid.Close()

    # deal with nonexistent histograms <--
    skipList = []
    for i in range(len(plots)):
        firstGood = -1
        for icat in range(ncats):
            if h_bkg_vecs[i][icat] != None:
                firstGood = icat
                break
        if firstGood==-1:
            # raise RuntimeError("all background histograms are empty for {0}/h_{1}!".format(dirname,plots[i][0]))
            print "Error: all background histograms are empty for {0}/h_{1}! Skipping!".format(dirname,plots[i][0])
            skipList.append(i)
            continue
        for icat in range(ncats):
            if h_bkg_vecs[i][icat] == None:
                h_bkg_vecs[i][icat] = h_bkg_vecs[i][firstGood].Clone()
                h_bkg_vecs[i][icat].Reset()
        if drawSystematicBand:
            h_bkg_tot = h_bkg_vecs[i][firstGood].Clone()
            syst_up = [0.0] * h_bkg_tot.GetNbinsX()
            syst_dn = [0.0] * h_bkg_tot.GetNbinsX()
            for icat in range(ncats):
                if icat != firstGood and h_bkg_vecs[i][icat] != None:
                    h_bkg_tot.Add(h_bkg_vecs[i][icat])
            for isys, sys in enumerate(systset):
                h_bkg_tot_syst_up = h_bkg_vecs_syst_up[i][isys][firstGood].Clone()
                h_bkg_tot_syst_dn = h_bkg_vecs_syst_dn[i][isys][firstGood].Clone()
                for icat in range(ncats):
                    if icat == firstGood: continue
                    if h_bkg_vecs_syst_up[i][isys][icat] != None:
                        h_bkg_tot_syst_up.Add(h_bkg_vecs_syst_up[i][isys][icat])
                    if h_bkg_vecs_syst_dn[i][isys][icat] != None:
                        h_bkg_tot_syst_dn.Add(h_bkg_vecs_syst_dn[i][isys][icat])
                h_bkg_tot_syst_up.Scale(h_bkg_tot.Integral()/h_bkg_tot_syst_up.Integral())
                h_bkg_tot_syst_dn.Scale(h_bkg_tot.Integral()/h_bkg_tot_syst_dn.Integral())
                h_bkg_tot_syst_up.Divide(h_bkg_tot)
                h_bkg_tot_syst_dn.Divide(h_bkg_tot)
                for ibin in range(1, h_bkg_tot.GetNbinsX()+1):
                    sysup = h_bkg_tot_syst_up.GetBinContent(ibin)-1
                    sysdn = h_bkg_tot_syst_dn.GetBinContent(ibin)-1
                    h_bkg_tot_syst_up.SetBinError(ibin, abs(sysup))
                    h_bkg_tot_syst_dn.SetBinError(ibin, abs(sysdn))
                    h_bkg_tot_syst_up.SetBinContent(ibin, 1)
                    h_bkg_tot_syst_dn.SetBinContent(ibin, 1)
                    # Temporary
                    syst_up[ibin-1] = ((syst_up[ibin-1])**2 + sysup**2)**0.5
                    syst_dn[ibin-1] = ((syst_dn[ibin-1])**2 + sysdn**2)**0.5

            systs[i] = syst_up # Temporary
            for ibin in range(len(syst_up)):
                systs[i][ibin] = max(syst_up[ibin], syst_dn[ibin])

    ## get data histograms
    if data==None:
        h_data = [None for i in plots]
    else:
        data_file = os.path.join(rootdir, data+".root")
        fid = ROOT.TFile(data_file)
        for i, pl in enumerate(plots):
            if i in skipList: continue
            vn = pl[0]
            # if suffix != None:
            #     vn += suffix
            h_data.append( fid.Get(dirnames[0]+"/h_"+vn) )
            if type(h_data[-1])==type(ROOT.TObject()):
                raise Exception("No {0}/h_{1} histogram for {2}!".format(dirname, vn, data))
            h_data[-1].SetDirectory(0)
            # handle the case with more than one directory
            for idir in range(1, len(dirnames)):
                h_data[-1].Add(fid.Get(dirnames[idir]+"/h_"+vn))
        fid.Close()

    ## get signal histograms
    h_sig_vec = [[] for i in plots]
    sig_names = [[] for i in plots]
    if sig_points is not None:
        sig_file = os.path.join(rootdir, signame+".root")
        fid = ROOT.TFile(sig_file)
        for i, pl in enumerate(plots):
            if i in skipList: continue
            for spt in sig_points:
                vn = pl[0]+'_'+spt
                h_sig_vec[i].append( fid.Get(dirnames[0]+"/h_"+vn) )
                #hacking
                if spt == "T2tt_1050_100":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}(1050,100)")
                elif spt == "T2tt_1000_100":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}(1000,100)")
                elif spt == "T2tt_900_500":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}(900,500)")
                elif spt == "T2tt_425_325":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}(425,325)")
                elif spt == "T2bW_950_100":
                    sig_names[i].append("#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1}(950,100)")
                elif spt == "T2bW_800_450":
                    sig_names[i].append("#tilde{t}#rightarrowb#tilde{#chi}^{#pm}_{1}(800,450)")
                elif spt == "T2bt_950_100":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}/b#tilde{#chi}^{#pm}_{1}(950,100)")
                elif spt == "T2bt_750_400":
                    sig_names[i].append("#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1}/b#tilde{#chi}^{#pm}_{1}(750,400)")
                else:
                    sig_names[i].append( spt)
                if type(h_sig_vec[i][-1])==type(ROOT.TObject()):
                    raise Exception("No {0}/h_{1} histogram for {2}!".format(dirname, vn, signame))
                h_sig_vec[i][-1].SetDirectory(0)
                # handle the case with more than one directory
                for idir in range(1, len(dirnames)):
                    h_sig_vec[i][-1].Add(fid.Get(dirnames[idir]+"/h_"+vn))
        fid.Close()

    # make the output directory if it doesn't exist
    if not os.path.isdir(os.path.join(output_dir,dirname+tag)):
        os.makedirs(os.path.join(output_dir,dirname+tag))

    # make all of the plots
    for i in range(len(plots)):
        if i in skipList: continue
        vn = plots[i][0]
        if suffix != None: vn += suffix
        userMin,userMax = None,None
        if plots[i][3]!=None:
            userMin = plots[i][3][0]
            userMax = plots[i][3][1]
        if len(plots[i]) >= 5:
            utils.Rebin(h_bkg_vecs[i],h_sig_vec[i],h_data[i], plots[i][4])
        doOverflow = True
        if len(plots[i]) >= 6:
            doOverflow = plots[i][5]
        markerSize=0.8
        title = utils.GetCRName(dirname)
        xAxisTitle = h_bkg_vecs[i][0].GetXaxis().GetTitle()
        unit = None
        if xAxisTitle == "":
            xAxisTitle = utils.GetVarName(vn)
            unit = utils.GetUnit(vn)
        xAxisTitle = utils.GetVarName(vn)#now I'm going stupid
        unit = utils.GetUnit(vn)#now I'm going stupid
        subtitles = utils.GetSubtitles(dirname)
        if h_data[i]!=None:
            if not scaleMC:
                subLegText = ["# Data events: {ndata}"]
            elif type(scaleMC) == float:
                subLegText = ["MC scaled by {}".format(scaleMC),"# Data events: {ndata}"]
            else:
                subLegText = ["MC scaled by {datamcsf}","# Data events: {ndata}"]
        else:
            subLegText = None
        subLegText = None
        subtitles = None
        title = None
        # subLegText = None
        if dogencat:
            sns = [utils.GetSampleName(s) for s in gencats]
            colors = [utils.GetColor(s) for s in gencats]
        else:
            sns = [utils.GetSampleName(s) for s in samples]
            colors = [utils.GetColor(s) for s in samples]

        for ext in exts:
            saveAs = os.path.join(output_dir,dirname+tag,"{0}_{1}.{2}".format(dirname,vn,ext))
            ppm.plotDataMC(h_bkg_vecs[i], sns, h_data[i], doPause=False, xAxisTitle=xAxisTitle, lumi=lumi, lumiUnit='fb',
                           title=title, subtitles=subtitles, dataTitle=datatitle, xRangeUser=plots[i][2], isLog=plots[i][1], saveAs=saveAs,
                           scaleMCtoData=scaleMC, xAxisUnit=unit, userMin=userMin, userMax=userMax, doSort=False, customColors=colors,
                           #markerSize=markerSize, titleSize=0.035, subtitleSize=0.033, legCoords=(0.60,0.70,0.87,0.895),
                           markerSize=markerSize, titleSize=0.035, subtitleSize=0.033, legCoords=(0.33,0.66,0.87,0.895),
                           subLegText=subLegText, subLegTextSize=0.036, doBkgError=True, doOverflow=doOverflow, cmsTextSize=0.04,
                           convertToPoisson=False, drawZeros=False, drawSystematicBand=drawSystematicBand, systematics=systs[i],
                           h_sig_vec=h_sig_vec[i], sig_names=sig_names[i], ratioType=ratioType)
