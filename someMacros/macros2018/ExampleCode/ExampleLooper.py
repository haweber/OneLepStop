from inspect import currentframe, getframeinfo
import math
import cmath
import ctypes
import os
import ROOT
#from ROOT import Math
#from ROOT.Math import LorentzVector
#from ROOT import TLorentzVector, TH1D, TH2D, TH3D, TFile, TTree, TTreeCache, TFile, TDirectory, TBenchmark

lv = ROOT.Math.LorentzVector(ROOT.Math.PxPyPzE4D(float)) #typedef LorentzVector
tas = ctypes.CDLL(os.path.abspath("./Tools/library.so")) #contains dorky,goodrun, and CMS3

def dRbetweenVectors(vec1,vec2):
    dphi = min(abs(vec1.Phi() - vec2.Phi()), 2*math.pi - abs(vec1.Phi() - vec2.Phi()) )
    deta = vec1.Eta() - vec2.Eta()
    return math.sqrt(dphi*dphi+deta*deta)

def dPhibetweenVectors(phi1,phi2):
   return min(abs(phi1 - phi2), 2*math.pi - abs(phi1 - phi2) )

def calculateMt(p4,met):
    return math.sqrt(2.*p4.Et()*met.Et()*(1. - math.cos(p4.Phi()-met.Phi()) ) )

def ScanChain(chain,fast,nEvents,skimFilePrefix):
    #these eight lines are just there to help understanding how the libary tas and tpyedef lv and ROOT interface work
    #x1___ = lv(30.,20.,10.,60.)
    #x2___ = lv(20.,20.,30.,60.)
    #lv1___ = ROOT.TLorentzVector(30.,20.,10.,60.)
    #lv2___ = ROOT.TLorentzVector(10.,20.,30.,60.)
    #tas.stupid(True)
    #tas.stupid(False)
    #print dRbetweenVectors(lv1___,lv2___), dPhibetweenVectors(lv1___.Phi(),lv2___.Phi()), calculateMt(lv1___,lv2___)
    #print dRbetweenVectors( x1___, x2___), dPhibetweenVectors( x1___.Phi(), x2___.Phi()), calculateMt( x1___, x2___)

    #real code starts here
    bmark = ROOT.TBenchmark()
    bmark.Start("benchmark")

    rootdir = ROOT.gDirectory.GetDirectory("Rint:")

    #define histograms here - we store kinematic distribution in those
    histos     = dict()
    nsigpoints = dict()
    histograms = []
    #histogram base name, number of bins, range low-high
    histograms.append(("MT_NJge2",             20, 0. , 500.))
    histograms.append(("MT_NJge4_METge250",    20, 0. , 500.))
    histograms.append(("MinDeltaRLepJet_NJge2",20, 0. , 5.0 ))
    histograms.append(("SignalRegionYields",    4, 0.5, 4.5 ))
    samples = [skimFilePrefix]
    if "LostLeptonAndTop" in skimFilePrefix: 
        samples = ["LostLepton", "Top1l"] #split lost lepton (tt2l) and top1l (tt1l)
    elif "Signal_T2tt" in skimFilePrefix:
        samples = ["Signal_T2tt_Wcorridor", "Signal_T2tt_topcorridor", "Signal_T2tt_betweencorridor", "Signal_T2tt_highDM"] # split signal depending on mass splitting Delta M (Mstop, MLSP)
    elif "SignalGen_T2tt" in skimFilePrefix:
        samples = ["SignalGen_T2tt_Wcorridor", "SignalGen_T2tt_topcorridor", "SignalGen_T2tt_betweencorridor", "SignalGen_T2tt_highDM"] #for genMET signal
    for s in samples:
        for hg in histograms: 
            histos[hg[0]+"_"+s] = ROOT.TH1D(hg[0]+"_"+s,"",hg[1],hg[2],hg[3]) #actually booking stuff
            histos[hg[0]+"_"+s].Sumw2()
            histos[hg[0]+"_"+s].SetDirectory(rootdir)
        nsigpoints[s] = set()

    if "Data" in skimFilePrefix: #Data need to be good - JSON file stores good run periods
        json_file = "Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt"
        tas.set_goodrun_file_json(json_file)

    #start file loop
    nEventsTotal = 0
    nEventsChain = chain.GetEntries()
    if nEvents >= 0:
        nEventsChain = nEvents
    listOfFiles = chain.GetListOfFiles()
    for chfile in listOfFiles: #loop over all files in TChain
        counterhist = None
        tfile = ROOT.TFile(chfile.GetTitle())
        print "Running over ", tfile.GetName()
        #now load the normalization histograms
        if "Signal" in skimFilePrefix:
            counterhist = ROOT.TH3D(tfile.Get("h_counterSMS")) #counter histogram (needed for normalization) for signal
            counterhist.SetDirectory(0)
        else:
            counterhist = ROOT.TH1D(tfile.Get("h_counter")) #counter histogram (needed for normalization of systematic effects)
            counterhist.SetDirectory(0)

        tree = tfile.Get("t") #get the tree in the TFile that has all event quantities
        if nEventsTotal >= nEventsChain:
            continue
        #now loop over all events e in a tree
        for e in tree:
            if nEventsTotal >= nEventsChain:
                continue
            nEventsTotal += 1
            #if nEventsTotal >=10000:
            #    break

            tas.progress( nEventsTotal, nEventsChain )#what is the progress within the chain

            weight = 1. #event weight

            #define what type of sample the event is
            samplename = skimFilePrefix
            if "LostLeptonAndTop" in samplename:
                if e.is1lepFromTop:
                    samplename = "TT1l"
                else:
                    samplename = "LostLepton"
            elif "Signal_T2tt" in samplename:
                if e.mass_lsp < 100.:#fastsim doesn't work well in that regime
                    continue
                if   (e.mass_stop-e.mass_lsp) < 98.:
                    samplename = "Signal_T2tt_Wcorridor"
                elif (e.mass_stop-e.mass_lsp) > 165. and (e.mass_stop-e.mass_lsp) < 185.:
                    samplename = "Signal_T2tt_topcorridor"
                elif (e.mass_stop-e.mass_lsp) >= 99. and (e.mass_stop-e.mass_lsp) <=150.:
                     samplename = "Signal_T2tt_betweencorridor"
                elif (e.mass_stop-e.mass_lsp) >=199. and (e.mass_stop-e.mass_lsp) <=250.:
                    samplename = "Signal_T2tt_highDM"
                else: #this region is not of interest for us
                    continue
            elif "SignalGen_T2tt" in samplename:
                if e.mass_lsp < 100.:#fastsim doesn't work well in that regime
                    continue
                if   (e.mass_stop-e.mass_lsp) < 98.:
                    samplename = "SignalGen_T2tt_Wcorridor"
                elif (e.mass_stop-e.mass_lsp) > 165. and (e.mass_stop-e.mass_lsp) < 185.:
                    samplename = "SignalGen_T2tt_topcorridor"
                elif (e.mass_stop-e.mass_lsp) >= 99. and (e.mass_stop-e.mass_lsp) <=150.:
                     samplename = "SignalGen_T2tt_betweencorridor"
                elif (e.mass_stop-e.mass_lsp) >=199. and (e.mass_stop-e.mass_lsp) <=250.:
                    samplename = "SignalGen_T2tt_highDM"
                else: #this region is not of interest for us
                    continue

            #now we get the correct event weight
            #expected event number (for real data) N = cross section * Luminosity
            #if we generate M simulated events, we need to normalize M to the correctly expected event yield: N = weight * M
            #--> weight = N / M = cross section * luminosity / M
            #in our ntuples: scale1fb = cross section * 1 fb^-1 / M --> can scale to any expected data set size
            if (not e.is_data) and ("Signal" not in samplename): #this is background
                nevts = counterhist.GetBinContent(counterhist.FindBin(22)) #total number of generated events
                weight = e.scale1fb*150. #event weight for a luminosity of 150 fb^-1
                nlepSF = counterhist.GetBinContent(counterhist.FindBin(28))
                lepSFweight = e.weight_lepSF*nevts/nlepSF if nlepSF>0 else  -1
                if lepSFweight>=0:
                    weight *= lepSFweight
            elif not e.is_data: #this is signal
                nevts = counterhist.GetBinContent(counterhist.FindBin(e.mass_stop,e.mass_lsp,36)) #total number of generated events
                nsigpoints[samplename].add(counterhist.FindBin(e.mass_stop,e.mass_lsp,36))#unique identifier for each signal point
                weight = e.xsec*150000./nevts #xsec is given in pb, not fb
                nlepSF = counterhist.GetBinContent(counterhist.FindBin(e.mass_stop,e.mass_lsp,27))
                nlepFS = counterhist.GetBinContent(counterhist.FindBin(e.mass_stop,e.mass_lsp,33))
                lepSFweight = e.weight_lepSF        *nevts/nlepSF if nlepSF>0 else  -1
                lepFSweight = e.weight_lepSF_fastSim*nevts/nlepFS if nlepFS>0 else  -1
                #lepSFweight = e.weight_lepSF*nevts/counterhist.GetBinContent(counterhist.FindBin(e.mass_stop,e.mass_lsp,27))
                #lepFSweight = e.weight_lepSF_fastSim*nevts/counterhist.GetBinContent(counterhist.FindBin(e.mass_stop,e.mass_lsp,33))#signal is produced with FastSimulation --> need an additional scale factor between fast and full simulation
                if lepSFweight>=0: # and math.isfinite(lepSFweight):
                    weight *= lepSFweight
                if lepFSweight>=0: # and math.isfinite(lepFSweight):
                    weight *= lepFSweight
                if not e.filt_fastsimjets:
                    continue

            #We have datasets that simulate both the same process, or have partial kinematic overlap -->
            #remove either overlap or apply appropriate additional event weight to remove double counting
            if ("ttbar_diLept_madgraph_pythia8_25ns" in tfile.GetName()):
                weight *= 5.77109e+06/(5.77109e+06 + 2.34556e+07)
            if ("ttbar_diLept_madgraph_pythia8_ext1_25ns" in tfile.GetName()):
                weight *= 2.34556e+07/(5.77109e+06 + 2.34556e+07)
            #if ("ttbar_singleLeptFromT_madgraph_pythia8_25ns" in tfile.GetName()):
            #    weight *= 1.16509e+07/(1.16509e+07 + 4.08199e+07)
            #if ("ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns" in tfile.GetName()):
            #    weight *= 4.08199e+07/(1.16509e+07 + 4.08199e+07)
            #if ("ttbar_singleLeptFromTbar_madgraph_pythia8_25ns" in tfile.GetName()):
            #    weight *= 1.13617e+07/(1.13617e+07 + 4.63189e+07)
            #if ("ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns" in tfile.GetName()):
            #    weight *= 4.63189e+07/(1.13617e+07 + 4.63189e+07)
            if "WJets" in samplename:
                if "nupT200" in tfile.GetName():
                    if e.nupt < 200.:
                        continue
                else:
                    if e.nupt > 200.:
                        continue

            #this is our preselection: exactly one good lepton (and no secondary loose lepton/track/hadronic tau), at least 2 jets, high MET and MT.
            if e.nvtxs<0               : continue
            if e.ngoodleps!=1          : continue
            if e.nvetoleps!=1          : continue
            if not e.PassTrackVeto     : continue
            if not e.PassTauVeto       : continue
            if e.ngoodjets<2           : continue
            if e.ngoodbtags<1          : continue
            if e.pfmet<250.            : continue
            if e.mt_met_lep<150.       : continue
            if e.mindphi_met_j1_j2<0.5 : continue

            #apply trigger requirement to data
            if e.is_data:
                weight = 1.
                if abs(e.lep1_pdgid)==11:
                    if not (e.HLT_MET or e.HLT_MET100_MHT100 or e.HLT_MET110_MHT110 or e.HLT_MET120_MHT120 or e.HLT_SingleEl):
                        continue
                elif abs(e.lep1_pdgid)==13:
                    if not (e.HLT_MET or e.HLT_MET100_MHT100 or e.HLT_MET110_MHT110 or e.HLT_MET120_MHT120 or e.HLT_SingleMu):
                        continue

            #as we loop over multiple 'datasets' (group of data events), an event could appear in two of them - make sure that we don't count such an event twice
            if e.is_data:
                id = tas.DorkyEventIdentifier(e.run, e.evt, e.ls)
                if tas.is_duplicate(id):
                    continue

            #reject run periods where detector was in bad state
            if e.is_data:
                if not tas.goodrun(e.run, e.ls):
                    continue

            #sometimes unexpected noise (from wrongly recorded detector pulses) happen - filter those out
            if e.is_data:
                if not e.filt_met                       : continue
                if not e.filt_badMuonFilter             : continue
                if not e.filt_badChargedCandidateFilter : continue
                if not e.filt_jetWithBadMuon            : continue
                if not e.filt_pfovercalomet             : continue
                if not e.filt_duplicatemuons            : continue
                if not e.filt_badmuons                  : continue
                if not e.PassTrackVeto                  : continue
                if not e.PassTrackVeto                  : continue
                if not e.PassTrackVeto                  : continue
                if not e.PassTrackVeto                  : continue


            #this is the final CORE of the code - fill in histograms
            #first a signal region binned histogram - so define signal region
            SR = -1
            if e.ngoodleps==1 and e.nvetoleps==1 and e.PassTrackVeto and e.PassTauVeto and e.ngoodbtags>=1 and e.ngoodjets>=5 and e.lep1_p4.Pt()<150. and e.lep1_dphiMET<2.0 and e.mindphi_met_j1_j2>0.5 and e.pfmet>=250. and e.mt_met_lep>150. and e.ak4pfjets_passMEDbtag[0]==False:
                if   e.pfmet>550.:
                    SR = 4
                elif e.pfmet>450.:
                    SR = 3
                elif e.pfmet>350.:
                    SR = 2
                elif e.pfmet>250.:
                    SR = 1

            #now fill the histogram
            if SR>0:
                histos["SignalRegionYields_" + samplename].Fill(SR,weight)

            #note that MT is already precalculated in our ntuples, also from above we already have a preselection for >=2j
            histos["MT_NJge2_"+samplename].Fill(e.mt_met_lep,weight);
            #here we want some additional selection
            if e.ngoodjets>=4 and e.pfmet>=250.:
                histos["MT_NJge4_METge250_"+samplename].Fill(e.mt_met_lep,weight);
            #let's look at a variable that is not precalculated - so we need to do it 'by hand'
            minDRlj = 999. #ridicoulously large value
            for i in range(0,e.ngoodjets): #do it this way as I access multiple branches
                if e.ak4pfjets_p4[i].Pt()<30.:
                    continue
                if abs(e.ak4pfjets_p4[i].Eta())>2.4:
                    continue
                if not e.ak4pfjets_loose_pfid[i]:
                    continue
                if minDRlj > dRbetweenVectors(e.ak4pfjets_p4[i],e.lep1_p4):
                    #we have on the very top a function defined dRbetweenVectors to help us - this one I actually use frequently
                    #we have found a jet-lepton pair with smaller DR - save this as current smallest DR
                    minDRlj = dRbetweenVectors(e.ak4pfjets_p4[i],e.lep1_p4)
            #now have found that variable, let's fill it.
            histos["MinDeltaRLepJet_NJge2_"+samplename].Fill(minDRlj,weight);

        #end event loop
    #end file loop

    #filled all histograms - last gymnastics
    for key in histos:
        #add overflow
        histos[key].SetBinContent(histos[key].GetNbinsX(), histos[key].GetBinContent(histos[key].GetNbinsX()) + histos[key].GetBinContent(histos[key].GetNbinsX()+1))
        histos[key].SetBinError(histos[key].GetNbinsX(), math.sqrt(math.pow(histos[key].GetBinError(histos[key].GetNbinsX()),2) + math.pow(histos[key].GetBinError(histos[key].GetNbinsX()+1),2) ) )
        #add underflow
        histos[key].SetBinContent(1, histos[key].GetBinContent(1) + histos[key].GetBinContent(0))
        histos[key].SetBinError(1, math.sqrt(math.pow(histos[key].GetBinError(1),2) + math.pow(histos[key].GetBinError(0),2) ) )
        #for signal only - normalize the signal yield to what we expect from a single event point (i.e. get averaged yield per point)
        if "Signal_T2tt_Wcorridor"       in key:
            histos[key].Scale(1./len(nsigpoints["Signal_T2tt_Wcorridor"]))
        if "Signal_T2tt_topcorridor"     in key:
            histos[key].Scale(1./len(nsigpoints["Signal_T2tt_topcorridor"]))
        if "Signal_T2tt_betweencorridor" in key:
            histos[key].Scale(1./len(nsigpoints["Signal_T2tt_betweencorridor"]))
        if "Signal_T2tt_highDM"          in key:
            histos[key].Scale(1./len(nsigpoints["Signal_T2tt_highDM"]))
        if "SignalGen_T2tt_Wcorridor"       in key:
            histos[key].Scale(1./len(nsigpoints["SignalGen_T2tt_Wcorridor"]))
        if "SignalGen_T2tt_topcorridor"     in key:
            histos[key].Scale(1./len(nsigpoints["SignalGen_T2tt_topcorridor"]))
        if "SignalGen_T2tt_betweencorridor" in key:
            histos[key].Scale(1./len(nsigpoints["SignalGen_T2tt_betweencorridor"]))
        if "SignalGen_T2tt_highDM"          in key:
            histos[key].Scale(1./len(nsigpoints["SignalGen_T2tt_highDM"]))
    
        #now we want to store all histograms
        filename = "rootfiles/Examplefilepy.root" #note this will fail saving if directory rootfiles does not exist

        f = ROOT.TFile(filename,"UPDATE") #use "Update" as we store several 'chains' into one file. Note, we need to be careful in our histogram names, because if we are not, we might overwrite a previous histogram.
        f.cd()
        for key in histos:
            histos[key].Write(key,ROOT.TObject.kOverwrite) #note, that we overwrite files - but that is ok, because we have unique histogram names for each chain
        f.Close()
        print "Saved histos in ",f.GetName()

    #show final performance
    bmark.Stop("benchmark")
    print ""
    print nEventsTotal, " Events Processed"
    print "------------------------------"
    print "CPU  Time:	", bmark.GetCpuTime( "benchmark")
    print "Real Time:	", bmark.GetRealTime("benchmark")
    print ""
    return True

def main():

    #here we book all TChains to loop over all events - we already split samples as good as we can into processes
    ch = dict()
    sample = []

    ch["LostLeptonAndTop"] = ROOT.TChain("t")
    ch["WJets"] = ROOT.TChain("t")
    ch["Znunu"] = ROOT.TChain("t")
    ch["Signal_T2tt"] = ROOT.TChain("t")
    #ch["Data"] = ROOT.TChain("t")

    babylocation = "/nfs-7/userdata/dsklein/tupler_babies/merged/Stop_1l/v24/skim/"    #>=1lep, >=2j, MET>150, MT>150, minDeltaPhi(j1,j2; MET)>0.5
    #babylocation = "/nfs-7/userdata/dsklein/tupler_babies/merged/Stop_1l/v24/output/"  #>=1lep, >=2j, MET>50          <-- does not contain signal

    ch["LostLeptonAndTop"].Add(babylocation+"ttbar_diLept_madgraph_pythia8_ext1_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"ttbar_diLept_madgraph_pythia8_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"ttbar_singleLeptFromT_madgraph_pythia8_ext1_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"ttbar_singleLeptFromTbar_madgraph_pythia8_ext1_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"t_tch_4f_powheg_pythia8_inclDecays_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"t_sch_4f_amcnlo_pythia8_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"t_tW_5f_powheg_pythia8_noHadDecays_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"t_tbarW_5f_powheg_pythia8_noHadDecays_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"WWTo2l2Nu_powheg_25ns*.root")
    ch["LostLeptonAndTop"].Add(babylocation+"ttWJets_13TeV_madgraphMLM*.root")

    ch["WJets"].Add(babylocation+"W1JetsToLNu_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W2JetsToLNu_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W3JetsToLNu_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W4JetsToLNu_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W1JetsToLNu_nupT200_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W2JetsToLNu_nupT200_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W3JetsToLNu_nupT200_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"W4JetsToLNu_nupT200_madgraph_pythia8_25ns*.root")
    ch["WJets"].Add(babylocation+"WWToLNuQQ_powheg_25ns*.root")
    
    ch["Znunu"].Add(babylocation+"ZZTo2L2Nu_powheg_pythia8_25ns*.root")
    ch["Znunu"].Add(babylocation+"ttZJets_13TeV_madgraphMLM*.root")
    ch["Znunu"].Add(babylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns*.root")

    ch["Signal_T2tt"].Add(babylocation+"Signal_T2tt_mStop_150to250*.root")
    ch["Signal_T2tt"].Add(babylocation+"Signal_T2tt_mStop_250to350*.root")
    ch["Signal_T2tt"].Add(babylocation+"Signal_T2tt_mStop_350to400*.root")
    ch["Signal_T2tt"].Add(babylocation+"Signal_T2tt_mStop_400to1200*.root")

    babylocation2 = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v24_softbgenmet/skim/"    #>=1lep, >=2j, MET>150, MT>150, minDeltaPhi(j1,j2; MET)>0.5
    #babylocation2 = "/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v24_softbgenmet/output/"  #>=1lep, >=2j, MET>50
    ch["SignalGen_T2tt"].Add(babylocation2+"Signal_T2tt_mStop_150to250*.root")
    ch["SignalGen_T2tt"].Add(babylocation2+"Signal_T2tt_mStop_250to350*.root")
    ch["SignalGen_T2tt"].Add(babylocation2+"Signal_T2tt_mStop_350to400*.root")
    ch["SignalGen_T2tt"].Add(babylocation2+"Signal_T2tt_mStop_400to1200*.root")


    #babylocation = "/nfs-7/userdata/stopRun2/analysis2016_SUS-16-051_35p9fbinv/v24/skim/" #different data ntuple format
    #ch["Data"].Add(babylocation+"data_met_Run*.root")
    #ch["Data"].Add(babylocation+"data_single_electron_*.root")
    #ch["Data"].Add(babylocation+"data_single_muon_*.root")

    #do the runnning
    for key in ch:
        ScanChain(ch[key],True,-1,key)

main()
