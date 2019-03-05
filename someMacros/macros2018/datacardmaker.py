import ROOT
from inspect import currentframe, getframeinfo
import csv
import math
from optparse import OptionParser
import re
import numpy as np
import sys
import os
import cStringIO

frameinfo = getframeinfo(currentframe())

class MyParser(OptionParser):
    def format_epilog(self, formatter):
        return self.epilog
epi = '''
EXAMPLE:
    > python datacardmaker.py --scan='T2tt,T2tb,T2tt' --bin='0,1,2' --analysis='0,1' --stop='200-1200' --lsp='25-650'
    > python datacardmaker.py --scan='T2tt,T2tb,T2tt' --bin='0-12' --analysis='0,1' --stop='200,1200' --lsp='25,650'
    > python datacardmaker.py --scan='T2tt,T2tb,T2tt' --bin='all' --analysis='all' --stop='200' --lsp='25' --nosigcont --uncorr --nosigsyst --nobgsyst --fake --shape
    Every option is OR
'''

parser = MyParser(epilog=epi)
parser.add_option('','--scan',dest='scans',help='Input which scan you want to produce datacards for.')
parser.add_option('','--bin',dest='bins',help='Input for which signal bins you want to run the scan for.')
parser.add_option('','--analysis',dest='analyses',help='Which analysis? 0 - general, 1 - compressed.')
parser.add_option('','--stop',dest='stops',help='Stop masses - if seperated by comma single masses, if you use a dash use the full range.')
parser.add_option('','--lsp',dest='lsps',help='LSP masses - if seperated by comma single masses, if you use a dash use the full range.')
parser.add_option('','--nosigcont',action="store_false", dest="nosigconts", default=True,help='Do not correct for signal contamination.')
parser.add_option('','--uncorr',action="store_false", dest="uncorrs", default=True,help='Set uncertainties to be uncorrelated.')
parser.add_option('','--nosigsyst',action="store_false", dest="nosigsysts", default=True,help='Drop signal systematics.')
parser.add_option('','--nobgsyst',action="store_false", dest="nobgsysts", default=True,help='Drop background systematics.')
parser.add_option('','--fake',action="store_false", dest="fakes", default=True,help='Fake data instead of real data.')
parser.add_option('','--shape',action="store_true", dest="shapes", default=False,help='Instead of pure text card, create shape card with rootfile.')

(opts, args) = parser.parse_args()

def loadarguments():
    scanlist = ['T2tt']
    analysislist=[0,1]
    binlist = range(1,28)
    stoplist = np.arange(75,1825,25).tolist()
    lsplist = np.arange(0,675,25).tolist()
    sigcont=True
    corr=True
    sigsyst=True
    bgsyst=True
    realdata=True
    shapecard=False

    if opts.scans:
        scanlist = opts.scans.split(',')
    if opts.analyses:
        analysislisttemp = opts.analyses.split(',')
        analysislist = [int(x) for x in analysislisttemp]
    if opts.bins:
        listtemp = opts.bins.split(',')
        rangelist = [re.findall(r'\d+', b) for b in listtemp]
        listrange=[]
        for b in rangelist:
            if len(b)==2:
                 listrange.extend(range(int(b[0]),int(b[1])+1))
            else:
                listrange.append(int(b[0]))
        binlist = listrange
    if opts.stops:
        listtemp = opts.stops.split(',')
        rangelist = [re.findall(r'\d+', b) for b in listtemp]
        listrange=[]
        for b in rangelist:
            if len(b)==2:
                 listrange.extend(np.arange(int(b[0]),int(b[1])+1,25).tolist())
            else:
                listrange.append(int(b[0]))
        stoplist = listrange
    if opts.lsps:
        listtemp = opts.lsps.split(',')
        rangelist = [re.findall(r'\d+', b) for b in listtemp]
        listrange=[]
        for b in rangelist:
            if len(b)==2:
                 listrange.extend(np.arange(int(b[0]),int(b[1])+1,25).tolist())
            else:
                listrange.append(int(b[0]))
        lsplist = listrange
    sigcont   = opts.nosigconts
    corr      = opts.uncorrs
    sigsyst   = opts.nosigsysts
    bgsyst    = opts.nobgsysts
    realdata  = opts.fakes
    shapecard = opts.shapes

    return scanlist, analysislist, binlist, stoplist, lsplist, sigcont, corr, sigsyst, bgsyst, realdata, shapecard

def loadSingleHistogram(myfile,histoname):
    if myfile.GetListOfKeys().Contains(histoname):
        return myfile.Get(histoname)
    else:
        print "Histogram",histoname,"does not exist in file",myfile.GetName()," - Please fix. Exiting."
        sys.exit()
    return 0

def CloneSingleHistogram(histos,histoname,newname):
    ROOT.TH1.AddDirectory(0)
    if histoname in histos:
        h = histos[histoname].Clone(newname)
        return h
    else:
        print "Histogram",histoname,"does not exist in histos dictionary - Please fix. Exiting."
        sys.exit()
    return 0

def loadAllHistos(scanlist,analysislist,realdata):
    ROOT.TH1.AddDirectory(0)
    histos = dict()
    files = dict()
    #load files
    for a in analysislist:
        anname = analysisname(a)
        f = ROOT.TFile()
        if a==0:
            f = ROOT.TFile("resultfiles/bkgEst_lostLepton__mlb_v2_bins__histos_updated.root","open")
        elif a==1:
            f = ROOT.TFile("resultfiles/LostLepton_BkgEst_compressed.root","open")
        files["f2l_"+str(a)] = f
        if a==0:
            f = ROOT.TFile("resultfiles/Wjets.root","open")
        elif a==1:
            f = ROOT.TFile("resultfiles/WJets_BkgEst_compressed.root","open")
        files["f1l_"+str(a)] = f
        if a==0:
            f = ROOT.TFile("resultfiles/TT1lSR.root","open")
        elif a==1:
            f = ROOT.TFile("resultfiles/TT1l_BkgEst_compressed.root","open")
        files["fTT1l_"+str(a)] = f
        f = ROOT.TFile("resultfiles/Znunu_BkgEst_"+anname+".root","open")
        files["fZ_"+str(a)] = f
        if realdata:
            if a==0:
                f = ROOT.TFile("resultfiles/DataSR.root","open")
            elif a==1:
                f = ROOT.TFile("resultfiles/DataSR_compressed.root","open")
            files["fData_"+str(a)] = f
        for s in scanlist:
            f = ROOT.TFile("signalyields/Histos_"+anname+"_Signal_" + s + ".root","open")
            files["f"+s+"_"+str(a)] = f
    for f in files:
        if not os.path.exists(files[f].GetName()):
            print "File",files[f].GetName(),"does not exist - please fix - I exit here"
            sys.exit()
    #load histograms
    for a in analysislist:
        h = ROOT.TH1D()
        hS = ROOT.TH3D()
        if realdata:
            #Data
            h = loadSingleHistogram(files["fData_"+str(a)],"SR_Data")
            histos["Data_"+str(a)+"_yield"] = h.Clone("Data_"+str(a)+"_yield")
        #Lost Lepton
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_yield")
        histos["BG2l_"+str(a)+"_yield"] = h.Clone("BG2l_"+str(a)+"_yield")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_bTagEffHFUp")
        histos["BG2l_"+str(a)+"_bHFup"] = h.Clone("BG2l_"+str(a)+"_bHFup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_bTagEffHFDn")
        histos["BG2l_"+str(a)+"_bHFdn"] = h.Clone("BG2l_"+str(a)+"_bHFdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_bTagEffLFUp")
        histos["BG2l_"+str(a)+"_bLFup"] = h.Clone("BG2l_"+str(a)+"_bLFup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_bTagEffLFDn")
        histos["BG2l_"+str(a)+"_bLFdn"] = h.Clone("BG2l_"+str(a)+"_bLFdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_lepSFUp")
        histos["BG2l_"+str(a)+"_lepSFup"] = h.Clone("BG2l_"+str(a)+"_lepSFup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_lepSFDn")
        histos["BG2l_"+str(a)+"_lepSFdn"] = h.Clone("BG2l_"+str(a)+"_lepSFdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_tauSFUp")
        histos["BG2l_"+str(a)+"_tauSFup"] = h.Clone("BG2l_"+str(a)+"_tauSFup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_tauSFDn")
        histos["BG2l_"+str(a)+"_tauSFdn"] = h.Clone("BG2l_"+str(a)+"_tauSFdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_pileupUp")
        histos["BG2l_"+str(a)+"_PUup"] = h.Clone("BG2l_"+str(a)+"_PUup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_pileupDn")
        histos["BG2l_"+str(a)+"_PUdn"] = h.Clone("BG2l_"+str(a)+"_PUdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_ISRUp")
        histos["BG2l_"+str(a)+"_ISRup"] = h.Clone("BG2l_"+str(a)+"_ISRup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_ISRDn")
        histos["BG2l_"+str(a)+"_ISRdn"] = h.Clone("BG2l_"+str(a)+"_ISRdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_mcStatsUp")
        histos["BG2l_"+str(a)+"_MCstatup"] = h.Clone("BG2l_"+str(a)+"_MCstatup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_mcStatsDn")
        histos["BG2l_"+str(a)+"_MCstatdn"] = h.Clone("BG2l_"+str(a)+"_MCstatdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_dataStatsDn")
        histos["BG2l_"+str(a)+"_Statup"] = h.Clone("BG2l_"+str(a)+"_Statup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_dataStatsUp")
        histos["BG2l_"+str(a)+"_Statdn"] = h.Clone("BG2l_"+str(a)+"_Statdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_alphasUp")
        histos["BG2l_"+str(a)+"_aSup"] = h.Clone("BG2l_"+str(a)+"_aSup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_alphasDn")
        histos["BG2l_"+str(a)+"_aSdn"] = h.Clone("BG2l_"+str(a)+"_aSdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_q2Dn")
        histos["BG2l_"+str(a)+"_Q2up"] = h.Clone("BG2l_"+str(a)+"_Q2up")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_yield")
        histos["BG2l_"+str(a)+"_Q2dn"] = h.Clone("BG2l_"+str(a)+"_Q2dn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_jesUp")
        histos["BG2l_"+str(a)+"_JESup"] = h.Clone("BG2l_"+str(a)+"_JESup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_jesDn")
        histos["BG2l_"+str(a)+"_JESdn"] = h.Clone("BG2l_"+str(a)+"_JESdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_metResUp")
        histos["BG2l_"+str(a)+"_METResup"] = h.Clone("BG2l_"+str(a)+"_METResup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_metResDn")
        histos["BG2l_"+str(a)+"_METResdn"] = h.Clone("BG2l_"+str(a)+"_METResdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_metTTbarUp")
        histos["BG2l_"+str(a)+"_METup"] = h.Clone("BG2l_"+str(a)+"_METup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_metTTbarDn")
        histos["BG2l_"+str(a)+"_METdn"] = h.Clone("BG2l_"+str(a)+"_METdn")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_cr2lTriggerSFUp")
        histos["BG2l_"+str(a)+"_Trigup"] = h.Clone("BG2l_"+str(a)+"_Trigup")
        h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_cr2lTriggerSFDn")
        histos["BG2l_"+str(a)+"_Trigdn"] = h.Clone("BG2l_"+str(a)+"_Trigdn")
        #the histograms below work only for general analysis - XXXX
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRdatayield")
        #histos["BG2l_"+str(a)+"_CRyieldData"] = h.Clone("BG2l_"+str(a)+"_CRyieldData")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRsimyield")
        #histos["BG2l_"+str(a)+"_CRyieldSim"] = h.Clone("BG2l_"+str(a)+"_CRyieldSim")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRsimrawyield")
        #histos["BG2l_"+str(a)+"_CRRawyieldSim"] = h.Clone("BG2l_"+str(a)+"_CRRawyieldSim")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRLLyield")
        #histos["BG2l_"+str(a)+"_CRyieldLL"] = h.Clone("BG2l_"+str(a)+"_CRyieldLL")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRWyield")
        #histos["BG2l_"+str(a)+"_CRyieldW"] = h.Clone("BG2l_"+str(a)+"_CRyieldW")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRtt1lyield")
        #histos["BG2l_"+str(a)+"_CRyieldtt1l"] = h.Clone("BG2l_"+str(a)+"_CRyieldtt1l")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_CRZyield")
        #histos["BG2l_"+str(a)+"_CRyieldZ"] = h.Clone("BG2l_"+str(a)+"_CRyieldZ")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_TF")
        #histos["BG2l_"+str(a)+"_SRCRTF"] = h.Clone("BG2l_"+str(a)+"_SRCRTF")
        #h = loadSingleHistogram(files["f2l_"+str(a)],"CR2l_SRyieldLL")
        #histos["BG2l_"+str(a)+"_SRyieldExp"] = h.Clone("BG2l_"+str(a)+"_SRyieldExp")
        #1l not from top
        h = loadSingleHistogram(files["f1l_"+str(a)],"CR1lyield")
        histos["BG1l_"+str(a)+"_yield"] = h.Clone("BG1l_"+str(a)+"_yield")
        h = loadSingleHistogram(files["f1l_"+str(a)],"dataStats_Up")
        histos["BG1l_"+str(a)+"_Statup"] = h.Clone("BG1l_"+str(a)+"_Statup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"dataStats_Dn")
        histos["BG1l_"+str(a)+"_Statdn"] = h.Clone("BG1l_"+str(a)+"_Statdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"mcStats_Up")
        histos["BG1l_"+str(a)+"_MCstatup"] = h.Clone("BG1l_"+str(a)+"_MCstatup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"mcStats_Dn")
        histos["BG1l_"+str(a)+"_MCstatdn"] = h.Clone("BG1l_"+str(a)+"_MCstatdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"bTagEffHF_Up")
        histos["BG1l_"+str(a)+"_bHFup"] = h.Clone("BG1l_"+str(a)+"_bHFup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"bTagEffHF_Dn")
        histos["BG1l_"+str(a)+"_bHFdn"] = h.Clone("BG1l_"+str(a)+"_bHFdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"bTagEffLF_Up")
        histos["BG1l_"+str(a)+"_bLFup"] = h.Clone("BG1l_"+str(a)+"_bLFup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"bTagEffLF_Dn")
        histos["BG1l_"+str(a)+"_bLFdn"] = h.Clone("BG1l_"+str(a)+"_bLFdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"Wb_Up")
        histos["BG1l_"+str(a)+"_Wbxsup"] = h.Clone("BG1l_"+str(a)+"_Wbxsup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"Wb_Dn")
        histos["BG1l_"+str(a)+"_Wbxsdn"] = h.Clone("BG1l_"+str(a)+"_Wbxsdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"pdf_Up")
        histos["BG1l_"+str(a)+"_PDFup"] = h.Clone("BG1l_"+str(a)+"_PDFup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"pdf_Dn")
        histos["BG1l_"+str(a)+"_PDFdn"] = h.Clone("BG1l_"+str(a)+"_PDFdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"q2_Up")
        histos["BG1l_"+str(a)+"_Q2up"] = h.Clone("BG1l_"+str(a)+"_Q2up")
        h = loadSingleHistogram(files["f1l_"+str(a)],"q2_Dn")
        histos["BG1l_"+str(a)+"_Q2dn"] = h.Clone("BG1l_"+str(a)+"_Q2dn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"JES_Up")
        histos["BG1l_"+str(a)+"_JESup"] = h.Clone("BG1l_"+str(a)+"_JESup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"JES_Dn")
        histos["BG1l_"+str(a)+"_JESdn"] = h.Clone("BG1l_"+str(a)+"_JESdn")
        h = loadSingleHistogram(files["f1l_"+str(a)],"CRCont_Up")
        histos["BG1l_"+str(a)+"_CRcontup"] = h.Clone("BG1l_"+str(a)+"_CRcontup")
        h = loadSingleHistogram(files["f1l_"+str(a)],"CRCont_Dn")
        histos["BG1l_"+str(a)+"_CRcontdn"] = h.Clone("BG1l_"+str(a)+"_CRcontdn")
        #1l from top
        h = loadSingleHistogram(files["fTT1l_"+str(a)],"SR_Top")
        histos["BGTT1l_"+str(a)+"_yield"] = h.Clone("BGTT1l_"+str(a)+"_yield")
        #Znunu
        h = loadSingleHistogram(files["fZ_"+str(a)],"yield")
        histos["BGZ_"+str(a)+"_yield"] = h.Clone("BGZ_"+str(a)+"_yield")
        h = loadSingleHistogram(files["fZ_"+str(a)],"normalizationUP")
        histos["BGZ_"+str(a)+"_Statup"] = h.Clone("BGZ_"+str(a)+"_Statup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"normalizationDN")
        histos["BGZ_"+str(a)+"_Statdn"] = h.Clone("BGZ_"+str(a)+"_Statdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"yield")
        histos["BGZ_"+str(a)+"_MCstatup"] = h.Clone("BGZ_"+str(a)+"_MCstatup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"yield")
        histos["BGZ_"+str(a)+"_MCstatdn"] = h.Clone("BGZ_"+str(a)+"_MCstatdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"Q2UP")
        histos["BGZ_"+str(a)+"_Q2up"] = h.Clone("BGZ_"+str(a)+"_Q2up")
        h = loadSingleHistogram(files["fZ_"+str(a)],"Q2DN")
        histos["BGZ_"+str(a)+"_Q2dn"] = h.Clone("BGZ_"+str(a)+"_Q2dn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"pdfUP")
        histos["BGZ_"+str(a)+"_PDFup"] = h.Clone("BGZ_"+str(a)+"_PDFup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"pdfDN")
        histos["BGZ_"+str(a)+"_PDFdn"] = h.Clone("BGZ_"+str(a)+"_PDFdn")  
        h = loadSingleHistogram(files["fZ_"+str(a)],"alphaSUP")
        histos["BGZ_"+str(a)+"_aSup"] = h.Clone("BGZ_"+str(a)+"_aSup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"alphaSDN")
        histos["BGZ_"+str(a)+"_aSdn"] = h.Clone("BGZ_"+str(a)+"_aSdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"btagHeavyUP")
        histos["BGZ_"+str(a)+"_bHFup"] = h.Clone("BGZ_"+str(a)+"_bHFup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"btagHeavyDN")
        histos["BGZ_"+str(a)+"_bHFdn"] = h.Clone("BGZ_"+str(a)+"_bHFdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"btagLightUP")
        histos["BGZ_"+str(a)+"_bLFup"] = h.Clone("BGZ_"+str(a)+"_bLFup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"btagLightDN")
        histos["BGZ_"+str(a)+"_bLFdn"] = h.Clone("BGZ_"+str(a)+"_bLFdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"PUup")
        histos["BGZ_"+str(a)+"_PUup"] = h.Clone("BGZ_"+str(a)+"_PUup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"PUdown")
        histos["BGZ_"+str(a)+"_PUdn"] = h.Clone("BGZ_"+str(a)+"_PUdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"jesUP")
        histos["BGZ_"+str(a)+"_JESup"] = h.Clone("BGZ_"+str(a)+"_JESup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"jesDN")
        histos["BGZ_"+str(a)+"_JESdn"] = h.Clone("BGZ_"+str(a)+"_JESdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"lepSFUP")
        histos["BGZ_"+str(a)+"_lepSFup"] = h.Clone("BGZ_"+str(a)+"_lepSFup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"lepSFDN")
        histos["BGZ_"+str(a)+"_lepSFdn"] = h.Clone("BGZ_"+str(a)+"_lepSFdn")
        h = loadSingleHistogram(files["fZ_"+str(a)],"ISRnjetsUp")
        histos["BGZ_"+str(a)+"_ISRup"] = h.Clone("BGZ_"+str(a)+"_ISRup")
        h = loadSingleHistogram(files["fZ_"+str(a)],"ISRnjetsDown")
        histos["BGZ_"+str(a)+"_ISRdn"] = h.Clone("BGZ_"+str(a)+"_ISRdn")
        #signal
        for s in scanlist:
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SRyield")
            histos[s+"_"+str(a)+"_yield"] = hS.Clone(s+"_"+str(a)+"_yield")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SRyield_gen")
            histos[s+"_"+str(a)+"_yield_gen"] = hS.Clone(s+"_"+str(a)+"_yield_gen")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"CR1l_sigcontamination")
            histos[s+"_"+str(a)+"_SigContCR1l"] = hS.Clone(s+"_"+str(a)+"_SigContCR1l")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"CR1l_sigcontamination_gen")
            histos[s+"_"+str(a)+"_SigContCR1l_gen"] = hS.Clone(s+"_"+str(a)+"_SigContCR1l_gen")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"CR2l_sigcontamination")
            histos[s+"_"+str(a)+"_SigContCR2l"] = hS.Clone(s+"_"+str(a)+"_SigContCR2l")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"CR2l_sigcontamination_gen")
            histos[s+"_"+str(a)+"_SigContCR2l_gen"] = hS.Clone(s+"_"+str(a)+"_SigContCR2l_gen")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Xsecup")
            histos[s+"_"+str(a)+"_xsup"] = hS.Clone(s+"_"+str(a)+"_xsup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Xsecdown")
            histos[s+"_"+str(a)+"_xsdn"] = hS.Clone(s+"_"+str(a)+"_xsdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bup_HF")
            histos[s+"_"+str(a)+"_bHFup"] = hS.Clone(s+"_"+str(a)+"_bHFup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bdown_HF")
            histos[s+"_"+str(a)+"_bHFdn"] = hS.Clone(s+"_"+str(a)+"_bHFdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bup_LF")
            histos[s+"_"+str(a)+"_bLFup"] = hS.Clone(s+"_"+str(a)+"_bLFup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bdown_LF")
            histos[s+"_"+str(a)+"_bLFdn"] = hS.Clone(s+"_"+str(a)+"_bLFdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bup_FS")
            histos[s+"_"+str(a)+"_bFSup"] = hS.Clone(s+"_"+str(a)+"_bFSup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_Bdown_FS")
            histos[s+"_"+str(a)+"_bFSdn"] = hS.Clone(s+"_"+str(a)+"_bFSdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_JESup")
            histos[s+"_"+str(a)+"_JESup"] = hS.Clone(s+"_"+str(a)+"_JESup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_JESdown")
            histos[s+"_"+str(a)+"_JESdn"] = hS.Clone(s+"_"+str(a)+"_JESdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_muRFup")
            histos[s+"_"+str(a)+"_Q2up"] = hS.Clone(s+"_"+str(a)+"_Q2up")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_muRFdown")
            histos[s+"_"+str(a)+"_Q2dn"] = hS.Clone(s+"_"+str(a)+"_Q2dn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_ISRup")
            histos[s+"_"+str(a)+"_ISRup"] = hS.Clone(s+"_"+str(a)+"_ISRup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_ISRdown")
            histos[s+"_"+str(a)+"_ISRdn"] = hS.Clone(s+"_"+str(a)+"_ISRdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_PUup")
            histos[s+"_"+str(a)+"_PUup"] = hS.Clone(s+"_"+str(a)+"_PUup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_PUdown")
            histos[s+"_"+str(a)+"_PUdn"] = hS.Clone(s+"_"+str(a)+"_PUdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_LepEffup")
            histos[s+"_"+str(a)+"_lepSFup"] = hS.Clone(s+"_"+str(a)+"_lepSFup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_LepEffdown")
            histos[s+"_"+str(a)+"_lepSFdn"] = hS.Clone(s+"_"+str(a)+"_lepSFdn")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_LepEffFSup")
            histos[s+"_"+str(a)+"_lepFSSFup"] = hS.Clone(s+"_"+str(a)+"_lepFSSFup")
            hS = loadSingleHistogram(files["f"+s+"_"+str(a)],"SR_LepEffFSdown")
            histos[s+"_"+str(a)+"_lepFSSFdn"] = hS.Clone(s+"_"+str(a)+"_lepFSSFdn")
    return histos

def GetUncertaintyName(name,updown,binwise,b,correlated,scan,stop,lsp,issig,is2l,is1l,isTT1l,isZ):
    bname = ""
    if binwise: bname = "_b"+str(b).zfill(2)
    uncertaintynames = ""
    if not correlated:
        if issig:  uncertaintynames = (name+"_"+scan+"_"+str(stop)+"_"+str(lsp)+bname)
        if is2l:   uncertaintynames = (name+"_BG2l"    +bname)
        if is1l:   uncertaintynames = (name+"_BG1l"    +bname)
        if isTT1l: uncertaintynames = (name+"_BGTT1l"  +bname)
        if isZ:    uncertaintynames = (name+"_BGZnunu" +bname)
    else:
        uncertaintynames = (name+bname)
    return uncertaintynames


def makeShapeCardRootfile(histos,scanlist,analysis,stoplist,lsplist,sigcont,corr,sigsyst,bgsyst,realdata):
    ROOT.TH1.AddDirectory(0)
    datacarddir = "dummy/"
    if not corr:
        datacarddir += "uncorr/"
    if not sigcont:
        datacarddir += "nosigcontcorr/"
    if not realdata:
        datacarddir += "fake/"
    if not sigsyst:
        datacarddir += "nosigsyst/"
    if not bgsyst:
        datacarddir += "nobgsyst/"
    if not os.path.exists(datacarddir):
        os.mkdir(datacarddir)
        print("Directory " , datacarddir ,  " Created ")
    a = analysis
    hall = dict()
    hdummy = CloneSingleHistogram(histos,"BG2l_"  +str(a)+"_yield","dummy")
    if validanalysis(a) == False:
        return False
    if realdata:
        hall["data_obs"] = CloneSingleHistogram(histos,"Data_"+str(a)+"_yield","data_obs")
    else:
        hall["data_obs"] = CloneSingleHistogram(histos,"BG2l_"+str(a)+"_yield","data_obs")
        for b in range(1,hall["data_obs"].GetNbinsX()):
            hall["data_obs"].SetBinContent(b,round(hall["data_obs"].GetBinContent(b)))
    hall["BG2l"]    = CloneSingleHistogram(histos,"BG2l_"  +str(a)+"_yield","BG2l")
    hall["BG1l"]    = CloneSingleHistogram(histos,"BG1l_"  +str(a)+"_yield","BG1l")
    hall["BGTT1l"]  = CloneSingleHistogram(histos,"BGTT1l_"+str(a)+"_yield","BGTT1l")
    hall["BGZnunu"] = CloneSingleHistogram(histos,"BGZ_"   +str(a)+"_yield","BGZnunu")
    #autoMCstats?
    #datastat
    hall["BGZnunu_CMS_stop1l_StatZUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_Statup","BGZnunu_CMS_stop1l_StatZUp")
    hall["BGZnunu_CMS_stop1l_StatZDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_Statdn","BGZnunu_CMS_stop1l_StatZDown")
    #for b in binlist:
    for b in range(1,analysismaxbin(a)+1):
        if b <=0: continue
        if b > analysismaxbin(a): continue
        #could implement here: if b==X and b==Y str(b) --> str(whatever)
        #datastat
        hall[   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos,   "BG2l_"  +str(a)+"_yield",   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Up")
        hall[   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,histos[ "BG2l_"  +str(a)+"_Statup"].GetBinContent(b))
        hall[   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos,   "BG2l_"  +str(a)+"_yield",   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Down")
        hall[   "BG2l_CMS_stop1l_Stat2l_b"+str(b).zfill(2)+"Down"].SetBinContent(b,histos[ "BG2l_"  +str(a)+"_Statdn"].GetBinContent(b))
        hall[   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos,   "BG1l_"  +str(a)+"_yield",   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Up")
        hall[   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,histos[ "BG1l_"  +str(a)+"_Statup"].GetBinContent(b))
        hall[   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos,   "BG1l_"  +str(a)+"_yield",   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Down")
        hall[   "BG1l_CMS_stop1l_Stat1l_b"+str(b).zfill(2)+"Down"].SetBinContent(b,histos[ "BG1l_"  +str(a)+"_Statdn"].GetBinContent(b))
        # CMS_stop1l_unc_BGTT1l
        hall["BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos, "BGTT1l_"  +str(a)+"_yield","BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Up")
        hall["BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,   2.0*histos[ "BGTT1l_"  +str(a)+"_yield"].GetBinContent(b))
        hall["BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos, "BGTT1l_"  +str(a)+"_yield","BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Down")
        hall["BGTT1l_CMS_stop1l_uncTT1l_b"+str(b).zfill(2)+"Down"].SetBinContent(b,   0.0*histos[ "BGTT1l_"  +str(a)+"_yield"].GetBinContent(b))
        #MCstat
        hall[   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos,   "BG2l_"  +str(a)+"_yield",   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Up")
        hall[   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,histos[ "BG2l_"  +str(a)+"_MCstatup"].GetBinContent(b))
        hall[   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos,   "BG2l_"  +str(a)+"_yield",   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Down")
        hall[   "BG2l_CMS_stop1l_MCstat2l_b"+str(b).zfill(2)+"Down"].SetBinContent(b,histos[ "BG2l_"  +str(a)+"_MCstatdn"].GetBinContent(b))
        hall[   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos,   "BG1l_"  +str(a)+"_yield",   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Up")
        hall[   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,histos[ "BG1l_"  +str(a)+"_MCstatup"].GetBinContent(b))
        hall[   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos,   "BG1l_"  +str(a)+"_yield",   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Down")
        hall[   "BG1l_CMS_stop1l_MCstat1l_b"+str(b).zfill(2)+"Down"].SetBinContent(b,histos[ "BG1l_"  +str(a)+"_MCstatdn"].GetBinContent(b))
        hall["BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Up"  ] = CloneSingleHistogram(histos,    "BGZ_"  +str(a)+"_yield","BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Up")
        hall["BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,histos[  "BGZ_"  +str(a)+"_MCstatup"].GetBinContent(b))
        hall["BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Down"] = CloneSingleHistogram(histos,    "BGZ_"  +str(a)+"_yield","BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Down")
        hall["BGZnunu_CMS_stop1l_MCstatZ_b"+str(b).zfill(2)+"Down"].SetBinContent(b,histos[  "BGZ_"  +str(a)+"_MCstatdn"].GetBinContent(b))
    ###lumi_13TeV is done via text
    ###CMS_stop1l_trig_metsl is done via text
    hall[   "BG2l_CMS_stop1l_trig_2lCRUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_Trigup",   "BG2l_CMS_stop1l_trig_2lCRUp")
    hall[   "BG2l_CMS_stop1l_trig_2lCRDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_Trigdn",   "BG2l_CMS_stop1l_trig_2lCRDown")
    hall[   "BG2l_CMS_btag_heavyUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_bHFup",   "BG2l_CMS_btag_heavyUp")
    hall[   "BG2l_CMS_btag_heavyDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_bHFdn",   "BG2l_CMS_btag_heavyDown")
    hall[   "BG1l_CMS_btag_heavyUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_bHFup",   "BG1l_CMS_btag_heavyUp")
    hall[   "BG1l_CMS_btag_heavyDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_bHFdn",   "BG1l_CMS_btag_heavyDown")
    hall["BGZnunu_CMS_btag_heavyUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_bHFup","BGZnunu_CMS_btag_heavyUp")
    hall["BGZnunu_CMS_btag_heavyDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_bHFdn","BGZnunu_CMS_btag_heavyDown")
    hall[   "BG2l_CMS_btag_lightUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_bHFup",   "BG2l_CMS_btag_lightUp")
    hall[   "BG2l_CMS_btag_lightDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_bHFdn",   "BG2l_CMS_btag_lightDown")
    hall[   "BG1l_CMS_btag_lightUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_bHFup",   "BG1l_CMS_btag_lightUp")
    hall[   "BG1l_CMS_btag_lightDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_bHFdn",   "BG1l_CMS_btag_lightDown")
    hall["BGZnunu_CMS_btag_lightUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_bHFup","BGZnunu_CMS_btag_lightUp")
    hall["BGZnunu_CMS_btag_lightDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_bHFdn","BGZnunu_CMS_btag_lightDown")
    hall[   "BG2l_CMS_eff_lUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_lepSFup",   "BG2l_CMS_eff_lUp")
    hall[   "BG2l_CMS_eff_lDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_lepSFdn",   "BG2l_CMS_eff_lDown")
    hall["BGZnunu_CMS_eff_lUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_lepSFup","BGZnunu_CMS_eff_lUp")
    hall["BGZnunu_CMS_eff_lDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_lepSFdn","BGZnunu_CMS_eff_lDown")
    hall[   "BG2l_CMS_eff_tauvetoUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_tauSFup",   "BG2l_CMS_eff_tauvetoUp")
    hall[   "BG2l_CMS_eff_tauvetoDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_tauSFdn",   "BG2l_CMS_eff_tauvetoDown")
    hall[   "BG2l_CMS_isrUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_ISRup",   "BG2l_CMS_isrUp")
    hall[   "BG2l_CMS_isrDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_ISRdn",   "BG2l_CMS_isrDown")
    hall["BGZnunu_CMS_isrUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_ISRup","BGZnunu_CMS_isrUp")
    hall["BGZnunu_CMS_isrDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_ISRdn","BGZnunu_CMS_isrDown")
    hall[   "BG2l_CMS_pileupUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_PUup",   "BG2l_CMS_pileupUp")
    hall[   "BG2l_CMS_pileupDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_PUdn",   "BG2l_CMS_pileupDown")
    hall["BGZnunu_CMS_pileupUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_PUup","BGZnunu_CMS_pileupUp")
    hall["BGZnunu_CMS_pileupDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_PUdn","BGZnunu_CMS_pileupDown")
    hall[   "BG2l_CMS_scale_jUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_JESup",   "BG2l_CMS_scale_jUp")
    hall[   "BG2l_CMS_scale_jDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_JESdn",   "BG2l_CMS_scale_jDown")
    hall[   "BG1l_CMS_scale_jUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_JESup",   "BG1l_CMS_scale_jUp")
    hall[   "BG1l_CMS_scale_jDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_JESdn",   "BG1l_CMS_scale_jDown")
    hall["BGZnunu_CMS_scale_jUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_JESup","BGZnunu_CMS_scale_jUp")
    hall["BGZnunu_CMS_scale_jDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_JESdn","BGZnunu_CMS_scale_jDown")
    hall[   "BG2l_CMS_res_metUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_METResup",   "BG2l_CMS_res_metUp")
    hall[   "BG2l_CMS_res_metDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_METResdn",   "BG2l_CMS_res_metDown")
    hall[   "BG2l_CMS_stop1l_TTMETUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_METup",   "BG2l_CMS_stop1l_TTMETUp")
    hall[   "BG2l_CMS_stop1l_TTMETDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_METdn",   "BG2l_CMS_stop1l_TTMETDown")
    hall[   "BG1l_CMS_stop1l_WbbcrosssecUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_Wbxsup",   "BG1l_CMS_stop1l_WbbcrosssecUp")
    hall[   "BG1l_CMS_stop1l_WbbcrosssecDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_Wbxsdn",   "BG1l_CMS_stop1l_WbbcrosssecDown")
    hall[   "BG1l_CMS_stop1l_non1lcontamUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_CRcontup",   "BG1l_CMS_stop1l_non1lcontamUp")
    hall[   "BG1l_CMS_stop1l_non1lcontamDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_CRcontdn",   "BG1l_CMS_stop1l_non1lcontamDown")
    hall[   "BG2l_QCDscale_tt_ACCEPTUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_Q2up",   "BG2l_QCDscale_tt_ACCEPTUp")
    hall[   "BG2l_QCDscale_tt_ACCEPTDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_Q2dn",   "BG2l_QCDscale_tt_ACCEPTDown")
    hall[   "BG1l_QCDscale_W_ACCEPTUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_Q2up",   "BG1l_QCDscale_W_ACCEPTUp")
    hall[   "BG1l_QCDscale_W_ACCEPTDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_Q2dn",   "BG1l_QCDscale_W_ACCEPTDown")
    hall["BGZnunu_QCDscale_ttV_ACCEPTUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_Q2up","BGZnunu_QCDscale_ttV_ACCEPTUp")
    hall["BGZnunu_QCDscale_ttV_ACCEPTDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_Q2dn","BGZnunu_QCDscale_ttV_ACCEPTDown")
    hall["BGZnunu_pdf_gg_ACCEPTUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_PDFup","BGZnunu_pdf_gg_ACCEPTUp")
    hall["BGZnunu_pdf_gg_ACCEPTDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_PDFdn","BGZnunu_pdf_gg_ACCEPTDown")
    hall[   "BG1l_pdf_qqbar_ACCEPTUp"  ] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_PDFup",   "BG1l_pdf_qqbar_ACCEPTUp")
    hall[   "BG1l_pdf_qqbar_ACCEPTDown"] = CloneSingleHistogram(histos,   "BG1l_"+str(a)+"_PDFdn",   "BG1l_pdf_qqbar_ACCEPTDown")
    hall[   "BG2l_QCDalphaSUp"  ] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_aSup",   "BG2l_QCDalphaSUp")
    hall[   "BG2l_QCDalphaSDown"] = CloneSingleHistogram(histos,   "BG2l_"+str(a)+"_aSdn",   "BG2l_QCDalphaSDown")
    hall["BGZnunu_QCDalphaSUp"  ] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_aSup","BGZnunu_QCDalphaSUp")
    hall["BGZnunu_QCDalphaSDown"] = CloneSingleHistogram(histos,    "BGZ_"+str(a)+"_aSdn","BGZnunu_QCDalphaSDown")
    #need to add l.221-238 - XXXX
    for s in scanlist:
        for stop in stoplist:
            if stop < scanminstop(s): continue
            if stop > scanmaxstop(s): continue
            for lsp in lsplist:
                if lsp > stop: continue
                if lsp < scanminlsp(s): continue
                if lsp > scanmaxlsp(s): continue
                #first get total signal acceptance yield
                totrawyield = 0
                totrecoyield = 0
                totgenyield  = 0
                for b in range(1,analysismaxbin(a)+1):
                    #for b in binlist:
                    if b <=0: continue
                    if b > analysismaxbin(a): continue
                    b3 = histos[s+"_"+str(a)+"_yield"].FindBin(stop,lsp,b)
                    if sigcont:
                        totgenyield  += max(0.0,histos[s+"_"  +str(a)+"_yield_gen"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR2l_gen"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR1l_gen"].GetBinContent(b3))
                        totrecoyield += max(0.0,histos[s+"_" +str(a)+"_yield"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR2l"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR1l"].GetBinContent(b3))
                        totrawyield  += histos[s+"_"  +str(a)+"_yield"].GetBinContent(b3)
                    else:
                        totgenyield  += histos[s+"_"  +str(a)+"_yield_gen"].GetBinContent(b3)
                        totrecoyield += histos[s+"_"  +str(a)+"_yield"].GetBinContent(b3)
                        totrawyield  += histos[s+"_"  +str(a)+"_yield"].GetBinContent(b3)
                #print "totrawyield",totrawyield
                if totrawyield == 0:
                    print "Signal point",s,stop,lsp,"for analyis",analysisname(a),"does not exist or has no signal - don't store in rootfile"
                    continue
                hall[s+"_"+str(stop)+"_"+str(lsp)] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp))
                #FIX THIS
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimDown")
                #trackveto by hand
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jDown")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTUp"  ] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTUp")
                hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTDown"] = hdummy.Clone(s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTDown")
                for b in range(1,analysismaxbin(a)+1):
                    #for b in binlist:
                    if b <=0: continue
                    if b > analysismaxbin(a): continue
                    b3 = histos[s+"_"+str(a)+"_yield"].FindBin(stop,lsp,b)
                    osigyield    = histos[s+"_" +str(a)+"_yield"].GetBinContent(b3)
                    sigyield = osigyield
                    recosigyield = sigyield
                    gensigyield = histos[s+"_"  +str(a)+"_yield_gen"].GetBinContent(b3)
                    sc = 1.
                    if sigcont:
                        gensigyield = max(0.0,gensigyield-histos[s+"_"  +str(a)+"_SigContCR2l_gen"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR1l_gen"].GetBinContent(b3))
                        recosigyield = max(0.0,osigyield-histos[s+"_"  +str(a)+"_SigContCR2l"].GetBinContent(b3)-histos[s+"_"  +str(a)+"_SigContCR1l"].GetBinContent(b3))
                    if True:
                        sigyield = (recosigyield+gensigyield)/2.
                        if osigyield != 0.:
                            sc = sigyield/osigyield
                            #sc = ((totrecoyield+totgenyield)/2.)/totrawyield
                    sigyielddiff = abs(sigyield-recosigyield)
                    #start here
                    hall[s+"_"+str(stop)+"_"+str(lsp)].SetBinContent(b,sigyield)
                    hall[s+"_"+str(stop)+"_"+str(lsp)].SetBinError(  b,histos[s+"_"+str(a)+"_yield"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETUp"  ].SetBinContent(b,sigyield+sigyielddiff)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_genMETDown"].SetBinContent(b,max(sigyield-sigyielddiff,0.))
                    #MCstat
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Up"  ] = hall[s+"_"+str(stop)+"_"+str(lsp)].Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Up"  )
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Up"  ].SetBinContent(b,(hall[s+"_"+str(stop)+"_"+str(lsp)].GetBinContent(b)+hall[s+"_"+str(stop)+"_"+str(lsp)].GetBinError(b))*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Down"] = hall[s+"_"+str(stop)+"_"+str(lsp)].Clone(s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Down")
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_stop1l_MCstatSig_b"+str(b).zfill(2)+"Down"].SetBinContent(b,max((hall[s+"_"+str(stop)+"_"+str(lsp)].GetBinContent(b)-hall[s+"_"+str(stop)+"_"+str(lsp)].GetBinError(b))*sc,0.))
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_xsup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_xsup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionDown"].SetBinContent(b,histos[s+"_"+str(a)+"_xsdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_SUSY_stop_crosssectionDown"].SetBinError(  b,histos[s+"_"+str(a)+"_xsdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_bHFup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_bHFup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyDown"].SetBinContent(b,histos[s+"_"+str(a)+"_bHFdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_heavyDown"].SetBinError(  b,histos[s+"_"+str(a)+"_bHFdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_bLFup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_bLFup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightDown"].SetBinContent(b,histos[s+"_"+str(a)+"_bLFdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_lightDown"].SetBinError(  b,histos[s+"_"+str(a)+"_bLFdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_bFSup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_bFSup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimDown"].SetBinContent(b,histos[s+"_"+str(a)+"_bFSdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_btag_fastsimDown"].SetBinError(  b,histos[s+"_"+str(a)+"_bFSdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_lepSFup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_lepSFup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lDown"].SetBinContent(b,histos[s+"_"+str(a)+"_lepSFdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_lDown"].SetBinError(  b,histos[s+"_"+str(a)+"_lepSFdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_lepFSSFup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_lepFSSFup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimDown"].SetBinContent(b,histos[s+"_"+str(a)+"_lepFSSFdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_eff_l_fastsimDown"].SetBinError(  b,histos[s+"_"+str(a)+"_lepFSSFdn"].GetBinError(  b3)*sc)
                    #trackveto by hand
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_ISRup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_ISRup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrDown"].SetBinContent(b,histos[s+"_"+str(a)+"_ISRdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_isrDown"].SetBinError(  b,histos[s+"_"+str(a)+"_ISRdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_PUup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_PUup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupDown"].SetBinContent(b,histos[s+"_"+str(a)+"_PUdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_pileupDown"].SetBinError(  b,histos[s+"_"+str(a)+"_PUdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_JESup"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_JESup"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jDown"].SetBinContent(b,histos[s+"_"+str(a)+"_JESdn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_CMS_scale_jDown"].SetBinError(  b,histos[s+"_"+str(a)+"_JESdn"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTUp"  ].SetBinContent(b,histos[s+"_"+str(a)+"_Q2up"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTUp"  ].SetBinError(  b,histos[s+"_"+str(a)+"_Q2up"].GetBinError(  b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTDown"].SetBinContent(b,histos[s+"_"+str(a)+"_Q2dn"].GetBinContent(b3)*sc)
                    hall[s+"_"+str(stop)+"_"+str(lsp)+"_QCDscale_stop_ACCEPTDown"].SetBinError(  b,histos[s+"_"+str(a)+"_Q2dn"].GetBinError(  b3)*sc)
    histosall = hall
    #this is the indention of analysislist
    filename = datacarddir + "Stop1lDatacardInput_"+analysisname(a)+".root"
    tfile = ROOT.TFile(filename,"recreate")
    tfile.cd()
    for histokey in hall:
        hall[histokey].Write()
    tfile.Close()
    print "Written datacard input root file ",filename,"- existing file replaced."
    return histosall


def makeShapeDatacard(hall,scan,analysis,stop,lsp,sigcont,corr,sigsyst,bgsyst,realdata):
    TrueS = (True if sigsyst else False)
    TrueB = (True if bgsyst  else False)
    TrueC = (True if corr    else False) #this doesn't do much right now
    fsp = 50
    scg = 25
    prc = "%.5f"
    ROOT.TH1.AddDirectory(0)
    datacarddir = "dummy/"
    if not corr:
        datacarddir += "uncorr/"
    if not sigcont:
        datacarddir += "nosigcontcorr/"
    if not realdata:
        datacarddir += "fake/"
    if not sigsyst:
        datacarddir += "nosigsyst/"
    if not bgsyst:
        datacarddir += "nobgsyst/"
    if not os.path.exists(datacarddir):
        os.mkdir(datacarddir)
        print("Directory " , datacarddir ,  " Created ")
    datasum   = hall["data_obs"].Integral()
    sigsum    = 0 #fix key error
    if scan+"_"+str(stop)+"_"+str(lsp) in hall:
        sigsum    = hall[scan+"_"+str(stop)+"_"+str(lsp)].Integral()
    else:
        print "Signal point",scan,stop,lsp,"for analyis",analysisname(analysis),"does not exist or has no signal - skip"
        return False
    print "sigsum",sigsum
    bg2lsum   = hall["BG2l"].Integral()
    bg1lsum   = hall["BG1l"].Integral()
    bgtt1lsum = hall["BGTT1l"].Integral()
    bgzsum    = hall["BGZnunu"].Integral()
    #for b in range(1,hall["BG2l"].GetNbinsX()+1):
    #    print b,stop,lsp,hall[scan+"_"+str(stop)+"_"+str(lsp)].GetBinContent(b),hall["BG2l"].GetBinContent(b)
    signame = scan+"_"+str(stop)+"_"+str(lsp)
    datacard = cStringIO.StringIO()
    datacard.write("# My significance experiment\n")
    datacard.write("imax   1  number of channels\n")
    datacard.write("jmax   4  number of backgrounds\n")
    datacard.write("kmax   *  number of nuisance parameters\n")
    datacard.write("------------\n")
    datacard.write("shapes * CMS_stop1l_13TeV "+datacarddir + "Stop1lDatacardInput_"+analysisname(analysis)+".root $PROCESS $PROCESS_$SYSTEMATIC\n")
    datacard.write("------------\n")
    datacard.write("# observations \n")
    datacard.write("bin         CMS_stop1l_13TeV\n")
    if realdata:
        datacard.write("observation "+str(int(datasum))+"\n")
    else:
        datacard.write("observation 0\n")
    datacard.write("------------\n")
    datacard.write("#now we list all expected number of events\n")
    datacard.write("bin".ljust(fsp)+" ".ljust(12)+"CMS_stop1l_13TeV".ljust(scg)+"CMS_stop1l_13TeV".ljust(scg)+"CMS_stop1l_13TeV".ljust(scg)+"CMS_stop1l_13TeV".ljust(scg)+"CMS_stop1l_13TeV".ljust(scg)+"\n")
    datacard.write("process".ljust(fsp)+" ".ljust(12)+signame.ljust(scg)+"BG2l".ljust(scg)+"BG1l".ljust(scg)+"BGTT1l".ljust(scg)+"BGZnunu".ljust(scg)+"\n")
    datacard.write("process".ljust(fsp)+" ".ljust(12)+"0".ljust(scg)+"1".ljust(scg)+"2".ljust(scg)+"3".ljust(scg)+"4".ljust(scg)+"\n")
    datacard.write("rate".ljust(fsp)+" ".ljust(12)+str(prc % sigsum).ljust(scg)+str(prc % bg2lsum).ljust(scg)+str(prc % bg1lsum).ljust(scg)+str(prc % bgtt1lsum).ljust(scg)+str(prc % bgzsum).ljust(scg)+"\n")
    datacard.write("------------\n")
    datacard.write(str("CMS_lumi_13TeV_2016").ljust(fsp)+" lnN".ljust(12) + "1.025".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"1.025".ljust(scg)+"1.025".ljust(scg)+"\n")
    if TrueS and TrueB:
        datacard.write(str("CMS_stop1l_trig_metsl").ljust(fsp)+" lnN".ljust(12) + "0.97/1".ljust(scg)+"-".ljust(scg)+"0.97/1".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    if TrueS:
        datacard.write(("CMS_eff_trackvetoSig").ljust(fsp)+" lnN".ljust(12) + "1.03".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    for b in range(1,analysismaxbin(analysis)+1):
    #for b in binlist:
        #if b <=0: continue
        #if b > analysismaxbin(analysis): continue
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_MCstatSig_b"+str(b).zfill(2),"shape" ,fsp,scg,TrueS,False,False,False,False))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_MCstat2l_b" +str(b).zfill(2),"shape" ,fsp,scg,False,TrueB,False,False,False))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_MCstat1l_b" +str(b).zfill(2),"shape" ,fsp,scg,False,False,TrueB,False,False))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_MCstatZ_b"  +str(b).zfill(2),"shape" ,fsp,scg,False,False,False,False,TrueB))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_uncTT1l_b"  +str(b).zfill(2),"shape" ,fsp,scg,False,False,False,TrueB,False))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_Stat2l_b"+str(b).zfill(2),   "shape" ,fsp,scg,False,TrueB,False,False,False))
        datacard.write(GetUncertaintyLineShape("CMS_stop1l_Stat1l_b"+str(b).zfill(2),   "shape" ,fsp,scg,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_StatZ",      "shape" ,fsp,scg,False,False,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_trig_2lCR",  "shape" ,fsp,scg,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_btag_heavy",        "shape" ,fsp,scg,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_btag_light",        "shape" ,fsp,scg,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_btag_fastsim",      "shape" ,fsp,scg,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_eff_l",             "shape" ,fsp,scg,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_eff_l_fastsim",     "shape" ,fsp,scg,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_eff_tauveto",       "shape" ,fsp,scg,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_isr",               "shape" ,fsp,scg,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_pileup",            "shape" ,fsp,scg,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_scale_j",           "shape" ,fsp,scg,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineShape("CMS_res_met",           "shape" ,fsp,scg,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_TTMET",      "shape" ,fsp,scg,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_Wbbcrosssec","shape" ,fsp,scg,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_non1lcontam","shape" ,fsp,scg,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineShape("QCDscale_stop_ACCEPT",  "shape" ,fsp,scg,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineShape("QCDscale_tt_ACCEPT",    "shape" ,fsp,scg,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineShape("QCDscale_W_ACCEPT",     "shape" ,fsp,scg,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineShape("QCDscale_ttV_ACCEPT",   "shape" ,fsp,scg,False,False,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("pdf_gg_ACCEPT",         "shape" ,fsp,scg,False,False,False,False,TrueB))
    datacard.write(GetUncertaintyLineShape("pdf_qqbar_ACCEPT",      "shape" ,fsp,scg,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineShape("CMS_stop1l_genMET",     "shapeU",fsp,scg,TrueS,False,False,False,False))
    datacardname = datacarddir + "shapedatacard_"+scan+"_"+str(stop)+"_"+str(lsp)+"_"+analysisname(analysis)+".txt"
    datacardtxt = open(datacardname,"w")
    datacardtxt.write(datacard.getvalue())
    datacardtxt.close()
    print "Written datacard",datacardname,"- existing file replaced."
    datacard.close()
    return True

    
def GetUncertaintyLineShape(uncertaintyname,shapename,fsp,scg,issig,is2l,is1l,isTT1l,isZ):
    uncertaintyline = uncertaintyname.ljust(fsp) + shapename.ljust(12)
    if issig:
        uncertaintyline += "1".ljust(scg)
    else:
        uncertaintyline += "-".ljust(scg)
    if is2l:
        uncertaintyline += "1".ljust(scg)
    else:
        uncertaintyline += "-".ljust(scg)
    if is1l:
        uncertaintyline += "1".ljust(scg)
    else:
        uncertaintyline += "-".ljust(scg)
    if isTT1l:
        uncertaintyline += "1".ljust(scg)
    else:
        uncertaintyline += "-".ljust(scg)
    if isZ:
        uncertaintyline += "1".ljust(scg)
    else:
        uncertaintyline += "-".ljust(scg)
    uncertaintyline += "\n"
    return uncertaintyline

def makeSingleBinTextDatacard(histos,b,scan,ana,stop,lsp,sigcont,corr,sigsyst,bgsyst,realdata):
    TrueS = (True if sigsyst else False)
    TrueB = (True if bgsyst  else False)
    TrueC = (True if corr    else False)
    b3 = histos[scan+"_"+str(ana)+"_yield"].FindBin(stop,lsp,b)
    osigyield    = histos[scan+"_" +str(ana)+"_yield"].GetBinContent(b3)
    bg2lyield    = histos["BG2l_"  +str(ana)+"_yield"].GetBinContent(b)
    bg1lyield    = histos["BG1l_"  +str(ana)+"_yield"].GetBinContent(b)
    bg1ltopyield = histos["BGTT1l_"+str(ana)+"_yield"].GetBinContent(b)
    bgzyield     = histos["BGZ_"   +str(ana)+"_yield"].GetBinContent(b)
    sigyield = osigyield
    recosigyield = sigyield
    gensigyield = histos[scan+"_"  +str(ana)+"_yield_gen"].GetBinContent(b3)
    if sigcont:
        gensigyield = max(0.0,gensigyield-histos[scan+"_"  +str(ana)+"_SigContCR2l_gen"].GetBinContent(b3)-histos[scan+"_"  +str(ana)+"_SigContCR1l_gen"].GetBinContent(b3))
        recosigyield = max(0.0,osigyield-histos[scan+"_"  +str(ana)+"_SigContCR2l"].GetBinContent(b3)-histos[scan+"_"  +str(ana)+"_SigContCR1l"].GetBinContent(b3))
    if True:
        sigyield = (recosigyield+gensigyield)/2.
    if osigyield==0 or sigyield==0:
        return False

    fsp = 50
    scg = 25
    prc = "%.5f"
    signame = scan+"_"+str(stop)+"_"+str(lsp)
    datacard = cStringIO.StringIO()
    datacard.write("# My significance experiment\n")
    datacard.write("imax   1  number of channels\n")
    datacard.write("jmax   4  number of backgrounds\n")
    datacard.write("kmax   *  number of nuisance parameters\n")
    datacard.write("------------\n")
    datacard.write("# observations \n")
    datacard.write("bin         ch"+str(b).zfill(2)+"\n")
    if realdata:
        datacard.write("observation "+str(int(histos["Data_"+str(ana)+"_yield"].GetBinContent(b)))+"\n")
    else:
        datacard.write("observation 0\n")
    datacard.write("------------\n")
    datacard.write("#now we list all expected number of events\n")
    datacard.write("bin".ljust(fsp)+" ".ljust(12)+"ch"+str(b).zfill(2).ljust(scg-2)+"ch"+str(b).zfill(2).ljust(scg-2)+"ch"+str(b).zfill(2).ljust(scg-2)+"ch"+str(b).zfill(2).ljust(scg-2)+"ch"+str(b).zfill(2).ljust(scg-2)+"\n")
    datacard.write("process".ljust(fsp)+" ".ljust(12)+signame.ljust(scg)+"BG2l".ljust(scg)+"BG1l".ljust(scg)+"BGTT1l".ljust(scg)+"BGZnunu".ljust(scg)+"\n")
    datacard.write("process".ljust(fsp)+" ".ljust(12)+"0".ljust(scg)+"1".ljust(scg)+"2".ljust(scg)+"3".ljust(scg)+"4".ljust(scg)+"\n")
    datacard.write("rate".ljust(fsp)+" ".ljust(12)+str(prc % sigyield).ljust(scg)+str(prc % bg2lyield).ljust(scg)+str(prc % bg1lyield).ljust(scg)+str(prc % bg1ltopyield).ljust(scg)+str(prc % bgzyield).ljust(scg)+"\n")
    datacard.write("------------\n")
    #print "dummy for ",scan,ana,stop,lsp,b
    #print datacard.getvalue()
    prc = "%.4f"
    if TrueS:
        datacard.write(str("CMS_stop1l_MCstat_"+signame+"_b"+str(b).zfill(2)).ljust(fsp)+" lnN".ljust(12) + str(prc % (1.+ histos[scan+"_" +str(ana)+"_yield"].GetBinError(b3) / osigyield)).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_MCstat",     "MCstat", False,True ,False,histos,ana,b,b3,scan,stop,lsp,False,TrueB,TrueB,False,TrueB))
    if TrueB:
        datacard.write(("CMS_stop1l_unc_BGTT1l"+"_b"+str(b).zfill(2)).ljust(fsp)+" lnN".ljust(12) + "-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"2.0".ljust(scg)+"-".ljust(scg)+"\n")
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_Stat",       "Stat",   False,True ,False,histos,ana,b,b3,scan,stop,lsp,False,TrueB,TrueB,False,False))#comment XXXX
    #datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_Stat",       "Stat",   False,True ,False,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))#new XXXX
    #datacard.write(GetUncertaintyLinegmN(fsp,scg,prc,"CMS_stop1l_Stat",       "Stat",   False,False,False,histos,ana,b,b3,scan,stop,lsp,False,TrueB,False,False,False))#new XXXX

    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_Stat",       "Stat",   False,False,False,histos,ana,b,b3,scan,stop,lsp,False,False,False,False,TrueB))
    datacard.write(str("CMS_lumi_13TeV_2016").ljust(fsp)+" lnN".ljust(12) + "1.025".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"1.025".ljust(scg)+"1.025".ljust(scg)+"\n")
    if TrueS and TrueB:
        datacard.write(str("CMS_stop1l_trig_metsl").ljust(fsp)+" lnN".ljust(12) + "0.97/1".ljust(scg)+"-".ljust(scg)+"0.97/1".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    if TrueB:
        datacard.write(str("CMS_stop1l_trig_2lCR").ljust(fsp)+" lnN".ljust(12) + "-".ljust(scg)+getUncert(histos,"BG2l_"  +str(ana),"Trig",True,b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")

    if TrueS:
        datacard.write(("CMS_stop1l_genMET_"+signame).ljust(fsp)+" lnU".ljust(12) + str(prc % (1.+abs(gensigyield-recosigyield) / recosigyield)).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    #               LnN vs. GmN?                      Name in datacard         hist-ID  updn  bin-by corr                               sig   2l    1l    TT1l  Znunu
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_btag_heavy",        "bHF",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_btag_light",        "bLF",    False,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_btag_fastsim",      "bFS",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_eff_l",             "lepSF",  True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_eff_l_fastsim",     "lepFSSF",True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_eff_tauveto",       "tauSF",  True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,TrueB,False,False,False))
    datacard.write(("CMS_eff_trackveto_"+signame).ljust(fsp)+" lnN".ljust(12) + "1.03".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n")
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_isr",               "ISR",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_pileup",            "PU",     True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,False,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_scale_j",           "JES",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,TrueB,TrueB,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_res_met",           "METRes", True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_TTMET",      "MET",    True ,False,False,histos,ana,b,b3,scan,stop,lsp,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_Wbbcrosssec","Wbxs",   True ,False,False,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"CMS_stop1l_non1lcontam","CRcont", True ,False,False,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))

    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"QCDscale_stop_ACCEPT",  "Q2",     True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,TrueS,False,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"QCDscale_tt_ACCEPT",    "Q2",     True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,TrueB,False,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"QCDscale_W_ACCEPT",     "Q2",     True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"QCDscale_ttV_ACCEPT",   "Q2",     True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,False,False,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"pdf_gg_ACCEPT",         "PDF",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,False,False,False,TrueB))
    datacard.write(GetUncertaintyLineLnN(fsp,scg,prc,"pdf_qqbar_ACCEPT",      "PDF",    True ,False,TrueC,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))

    #datacard.write(GetUncertaintyLinegmN(fsp,scg,prc,"CMS_stop1l_Norm",       "CR0b",   False,False,False,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))
    #datacard.write(GetUncertaintyLinegmN(fsp,scg,prc,"CMS_stop1l_SimStat",    "Random", False,False,False,histos,ana,b,b3,scan,stop,lsp,False,False,TrueB,False,False))#identifier not used

    #I need to rewrite this to use CR fit, but implement RateParameter according to p.8 of https://indico.cern.ch/event/747340/contributions/3198652/attachments/1744338/2823485/Fitting_Control_Regions.pdf

    datacardname = "dummy/"
    if not corr:
        datacardname += "uncorr/"
    if not sigcont:
        datacardname += "nosigcontcorr/"
    if not realdata:
        datacardname += "fake/"
    if not sigsyst:
        datacardname += "nosigsyst/"
    if not bgsyst:
        datacardname += "nobgsyst/"
    if not os.path.exists(datacardname):
        os.mkdir(datacardname)
        print("Directory " , datacardname ,  " Created ")
    datacardname += "datacard_"+scan+"_"+str(stop)+"_"+str(lsp)+"_"+analysisname(ana)+"_b"+str(b).zfill(2)+".txt"
    datacardtxt = open(datacardname,"w")
    datacardtxt.write(datacard.getvalue())
    datacardtxt.close()
    print "Written datacard",datacardname,"- existing file replaced."
    datacard.close()
    return True

def GetUncertaintyLineLnN(fsp,scg,prc,name,identifier,updown,binwise,correlated,histos,analysis,b,b3,scan,stop,lsp,issig,is2l,is1l,isTT1l,isZ):
    bname = ""
    if binwise: bname = "_b"+str(b).zfill(2)
    uncertaintyline = ""
    if not correlated:
        if issig:  uncertaintyline += (name+"_"+scan+"_"+str(stop)+"_"+str(lsp)+bname).ljust(fsp)+" lnN".ljust(12)+getUncert(histos,scan+"_"+str(analysis),identifier,updown,b3,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if is2l:   uncertaintyline += (name+"_BG2l"    +bname).ljust(fsp)+" lnN".ljust(12)+"-".ljust(scg)+getUncert(histos,"BG2l_"+str(analysis),identifier,updown,b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if is1l:   uncertaintyline += (name+"_BG1l"    +bname).ljust(fsp)+" lnN".ljust(12)+"-".ljust(scg)+"-".ljust(scg)+getUncert(histos,"BG1l_"+str(analysis),identifier,updown,b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if isTT1l: uncertaintyline += (name+"_BGTT1l"  +bname).ljust(fsp)+" lnN".ljust(12)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+getUncert(histos,"BGTT1l_"+str(analysis),identifier,updown,b,prc).ljust(scg)+"-".ljust(scg)+"\n"
        if isZ:    uncertaintyline += (name+"_BGZnunu" +bname).ljust(fsp)+" lnN".ljust(12)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+getUncert(histos,"BGZ_"+str(analysis),identifier,updown,b,prc).ljust(scg)+"\n"
    else:
        uncertaintyline += (name+bname).ljust(fsp)+" lnN".ljust(12)+(getUncert(histos,scan+"_"+str(analysis),identifier,updown,b3,prc).ljust(scg) if issig else "-".ljust(scg)) \
            +(getUncert(histos,"BG2l_"  +str(analysis),identifier,updown,b,prc).ljust(scg) if is2l   else "-".ljust(scg)) \
            +(getUncert(histos,"BG1l_"  +str(analysis),identifier,updown,b,prc).ljust(scg) if is1l   else "-".ljust(scg)) \
            +(getUncert(histos,"BGTT1l_"+str(analysis),identifier,updown,b,prc).ljust(scg) if isTT1l else "-".ljust(scg)) \
            +(getUncert(histos,"BGZ_"   +str(analysis),identifier,updown,b,prc).ljust(scg) if isZ    else "-".ljust(scg)) + "\n"
    return uncertaintyline

def getUncert(h,basename,uncname,updown,b,prc):
    cent =  h[basename+"_yield"].GetBinContent(b)
    if cent == 0:
        return "-"
    up,down = 0,0
    if updown:
        up   = h[basename+"_"+uncname+"up"].GetBinContent(b) / cent
        down = h[basename+"_"+uncname+"dn"].GetBinContent(b) / cent
        downstr,upstr = "",""
        if down < 1:
            downstr = str(prc % max(0.01,(1./(2.-down))))
        else:
            downstr = str(prc % min(10.,down))
        if up < 1:
            upstr = str(prc % max(0.01,(1./(2.-up))))
        else:
            upstr = str(prc % min(10.,up))
        if abs(up-1.)<0.001 and  abs(down-1.)<0.001: #no uncertainty, set it to 0.1%
            return "1.001"
        elif abs(up-1.)<0.001: #only down uncertainty, set it to be the only one
            return downstr
        elif abs(down-1.)<0.001: #only down uncertainty, set it to be the only one
            return upstr
        else: #both up and down uncertainties
            return (downstr+"/"+upstr)
    else:
        unc  = h[basename+"_"+uncname+"up"].GetBinContent(b) / cent #probably need to modify this
        if abs(unc-1.)<0.001: #no uncertainty, set it to 0.1%
            return "1.001"
        elif unc < 1:
            return str(prc % max(0.01,(1./(2.-unc))))
        else:
            return str(prc % min(10.,unc))


def GetUncertaintyLinegmN(fsp,scg,prc,name,identifier,updown,binwise,correlated,histos,analysis,b,b3,scan,stop,lsp,issig,is2l,is1l,isTT1l,isZ):
    #identifier is crname
    #correlated does not work here !!
    #also how to deal with non-binwise background?
    bname = ""
    if binwise: bname = "_b"+str(b).zfill(2)
    uncertaintyline = ""
    #if not correlated:
    if True:
        if issig:  uncertaintyline += (name+"_"+scan+"_"+str(stop)+"_"+str(lsp)+bname).ljust(fsp)+" gmN "+str(GetCRyield(histos, scan+"_"+str(analysis),identifier,b3,prc)).ljust(7)+GetGmNFactor(histos,scan+"_"+str(analysis),identifier,b3,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if is2l:   uncertaintyline += (name+"_BG2l"    +bname).ljust(fsp)+" gmN "+str(GetCRyield(histos, "BG2l_"  +str(analysis),identifier,b,prc)).ljust(7)+"-".ljust(scg)+GetGmNFactor(histos,"BG2l_"  +str(analysis),identifier,b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if is1l:   uncertaintyline += (name+"_BG1l"    +bname).ljust(fsp)+" gmN "+str(GetCRyield(histos, "BG1l_"  +str(analysis),identifier,b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+GetGmNFactor(histos,"BG1l_"  +str(analysis),identifier,b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
        if isTT1l: uncertaintyline += (name+"_BGTT1l"  +bname).ljust(fsp)+" gmN "+str(GetCRyield(histos, "BGTT1l_"+str(analysis),identifier,b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+GetGmNFactor(histos,"BGTT1l_"+str(analysis),identifier,b,prc).ljust(scg)+"-".ljust(scg)+"\n"
        if isZ:    uncertaintyline += (name+"_BGZnunu" +bname).ljust(fsp)+" gmN "+str(GetCRyield(histos, "BGZ_"   +str(analysis),identifier,b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+GetGmNFactor(histos,"BGZ_"   +str(analysis),identifier,b,prc).ljust(scg)+"\n"
    else:
        uncertaintyline += (name+bname).ljust(fsp)+" gmN "+str(GetCRyield(scan+"_"+str(analysis),identifier,b3,prc)).ljust(7)+(GetGmNFactor(histos,scan+"_"+str(analysis),identifier,b3,prc).ljust(scg) if issig else "-".ljust(scg)) \
            +(GetGmNFactor(histos,"BG2l_"  +str(analysis),identifier,b,prc).ljust(scg) if is2l   else "-".ljust(scg)) \
            +(GetGmNFactor(histos,"BG1l_"  +str(analysis),identifier,b,prc).ljust(scg) if is1l   else "-".ljust(scg)) \
            +(GetGmNFactor(histos,"BGTT1l_"+str(analysis),identifier,b,prc).ljust(scg) if isTT1l else "-".ljust(scg)) \
            +(GetGmNFactor(histos,"BGZ_"   +str(analysis),identifier,b,prc).ljust(scg) if isZ    else "-".ljust(scg)) + "\n"
    return uncertaintyline

def GetCRyield(h,basename,crname,b,prc):
    #if crname + "_Data" not in h:
    #    print "Histogram",crname + "_Data","has not been loaded - Please fix. Exiting."
    #    sys.exit()
    CR =  h[basename + "_CRyieldData"].GetBinContent(b)
    return str(int(round(CR)))

def GetGmNFactor(h,basename,crname,b,prc):
    if basename + "_SRCRTF" in h:
        return str(prc % h[basename+"_SRCRTF"].GetBinContent(b) )
    else:
        SR =  h[basename+"_SRyieldExp"].GetBinContent(b) #base does contain bg name
        CR =  h[basename+"_CRyieldSim"].GetBinContent(b)   #this should be the complete CR yield - i.e. factor includes also purity factor
        return str(prc % float(SR/CR))
    return -1

def GetCRyieldForMCstats(h,basename,b,prc):
    CR =  h[basename + "_SRRawyieldSim"].GetBinContent(b)
    return str(int(round(CR)))

def GetGmNFactorMCstats(h,basename,b,prc):
    SR =  h[basename+"_SRyieldSim"].GetBinContent(b) 
    CR =  h[basename+"_SRRawyieldSim"].GetBinContent(b)
    return str(prc % float(SR/CR))

def GetSimYieldUncLinegmN(fsp,scg,prc,name,identifier,updown,binwise,correlated,histos,analysis,b,b3,scan,stop,lsp,issig,is2l,is1l,isTT1l,isZ):
    #identifier is crname
    #correlated does not work here !!
    #also binwise is forced
    bname = ""
    #if binwise: bname = "_b"+str(b).zfill(2)
    bname = "_b"+str(b).zfill(2)
    uncertaintyline = ""
    if issig:  uncertaintyline += (name+"_"+scan+"_"+str(stop)+"_"+str(lsp)+bname).ljust(fsp)+" gmN "+str(GetGmNFactorMCstats(scan+"_"+str(analysis),b3,prc)).ljust(7)+GetCRyieldForMCstats(histos,scan+"_"+str(analysis),b3,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
    if is2l:   uncertaintyline += (name+"_BG2l"    +bname).ljust(fsp)+" gmN "+str(GetGmNFactorMCstats("BG2l_"  +str(analysis),b,prc)).ljust(7)+"-".ljust(scg)+GetCRyieldForMCstats(histos,"BG2l_"  +str(analysis),b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
    if is1l:   uncertaintyline += (name+"_BG1l"    +bname).ljust(fsp)+" gmN "+str(GetGmNFactorMCstats("BG1l_"  +str(analysis),b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+GetCRyieldForMCstats(histos,"BG1l_"  +str(analysis),b,prc).ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"\n"
    if isTT1l: uncertaintyline += (name+"_BGTT1l"  +bname).ljust(fsp)+" gmN "+str(GetGmNFactorMCstats("BGTT1l_"+str(analysis),b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+GetCRyieldForMCstats(histos,"BGTT1l_"+str(analysis),b,prc).ljust(scg)+"-".ljust(scg)+"\n"
    if isZ:    uncertaintyline += (name+"_BGZnunu" +bname).ljust(fsp)+" gmN "+str(GetGmNFactorMCstats("BGZ_"   +str(analysis),b,prc)).ljust(7)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+"-".ljust(scg)+GetCRyieldForMCstats(histos,"BGZ_"   +str(analysis),b,prc).ljust(scg)+"\n"
    return uncertaintyline



def analysisname(analysis):
    if analysis==0:
        return "std"
    elif analysis==1:
        return "compressed"
    return "BS"

def analysismaxbin(analysis):
    if analysis==0:
        return 27
    elif analysis==1:
        return 4
    return -1

def scanminstop(scan):
    return 150.

def scanmaxstop(scan):
    return 1500.

def scanminlsp(scan):
    return 0.

def scanmaxlsp(scan):
    return 650.                           

def validanalysis(analysis):
    if analysis==0 or analysis==1:
        return True
    return False

def validpoint(h,stop,lsp,analysis):
    sig = 0.0
    for b in range(1,analysismaxbin(analysis)+1):
        b3 = h.FindBin(stop,lsp,b)
        sig += h.GetBinContent(b3)
    if sig == 0:
        return False
    return True

def main():

    scanlist, analysislist, binlist, stoplist, lsplist, sigcont, corr, sigsyst, bgsyst, realdata, shapecard = loadarguments()
    #print scanlist
    #print binlist
    #print sigcont,corr,sigsyst,bgsyst,realdata
    #histos = loadAllHistos(scanlist,analysislist,realdata)
    histos = dict()
    histos = loadAllHistos(scanlist,analysislist,realdata)
    #print histos
    for a in analysislist:
        if validanalysis(a) == False: continue
        histosall = dict()
        if shapecard:
            histosall = makeShapeCardRootfile(histos,scanlist,a,stoplist,lsplist,sigcont,corr,sigsyst,bgsyst,realdata)
        for s in scanlist:
            for t in stoplist:
                if t < scanminstop(s): continue
                if t > scanmaxstop(s): continue
                for l in lsplist:
                    if l > t: continue
                    if l < scanminlsp(s): continue
                    if l > scanmaxlsp(s): continue
                    if shapecard:
                        makeShapeDatacard(histosall,s,a,t,l,sigcont,corr,sigsyst,bgsyst,realdata)
                    for b in binlist:
                        if b <=0: continue
                        if b > analysismaxbin(a): continue
                        validpoint(histos[s+"_"+str(a)+"_yield"],t,l,a)
                        #print a,b,s,t,l
                        if not shapecard:
                            makeSingleBinTextDatacard(histos,b,s,a,t,l,sigcont,corr,sigsyst,bgsyst,realdata)
                        

if __name__ == "__main__":
    main()
