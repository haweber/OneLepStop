#from ROOT import TCanvas  # global import, easy but NOT recommended
import ROOT
from inspect import currentframe, getframeinfo
import math

frameinfo = getframeinfo(currentframe())

data = False
lumi = 150.
logy = True

ROOT.gStyle.SetOptStat(0);

f = ROOT.TFile("rootfiles/Examplefile.root","open")

histonames = ["MT_NJge2",   "MT_NJge4_METge250",                     "MinDeltaRLepJet_NJge2", "SignalRegionYields"]
axisnames  = ["M_{T} [GeV]","M_{T} [GeV]",                           "min#DeltaR(jet,lep)",   "signal region"     ]
selectname = ["#geq2 jets", "#geq4 jets, p_{T}^{miss} #geq 250 GeV", "#geq2 jets",            ""                  ]

bgsamples  = ["LostLepton",  "TT1l",                   "WJets",                      "Znunu"]
bglegend   = ["Lost lepton", "1#font[12]{l} from top", "1#font[12]{l} not from top", "Z#rightarrow#nu#bar{#nu}"]
bgcolor    = [ 429,           625,                      798,                          611                      ]#kCyan-3, kRed-7, kOrange-2, kMagenta-5

sigsamples = ["Signal_T2tt_Wcorridor",                                  "Signal_T2tt_topcorridor",                                "Signal_T2tt_betweencorridor",                                  "Signal_T2tt_highDM"                                        ]
siglegend  = ["#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (W corridor)", "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (t corridor)", "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (between corridor)", "#tilde{t}#rightarrowt#tilde{#chi}^{0}_{1} (above corridor)"]
sigcolor   = [ 418,                                                      601,                                                      401,                                                            617]#kGreen+2, kBlue+1, kYellow+1, kMagenta+1

stacks = dict()
histos = dict()

for h,a in zip(histonames,axisnames) :
    stacks[h] = ROOT.THStack()
    for s,l,c in zip(sigsamples,siglegend,sigcolor) :
        #print h+"_"+s
        histos[h+"_"+s] = f.Get(h+"_"+s)
        histos[h+"_"+s].GetXaxis().SetTitle(a)
        histos[h+"_"+s].GetYaxis().SetTitle("Events")
        histos[h+"_"+s].GetXaxis().SetTitleSize(0.)
        for b in range(histos[h+"_"+s].GetNbinsX()) :
            if histos[h+"_"+s].GetBinContent(b) < 0 :
                histos[h+"_"+s].SetBinContent(b,0)
                histos[h+"_"+s].SetBinError(b,0)
        histos[h+"_"+s].SetLineColor(c)
        histos[h+"_"+s].SetMarkerColor(c)
        histos[h+"_"+s].SetLineWidth(3)
        histos[h+"_"+s].SetLineStyle(7)
    for s,l,c in zip(reversed(bgsamples),reversed(bglegend),reversed(bgcolor)) :
        #print h+"_"+s
        histos[h+"_"+s] = f.Get(h+"_"+s)
        histos[h+"_"+s].GetXaxis().SetTitle(a)
        histos[h+"_"+s].GetYaxis().SetTitle("Events")
        histos[h+"_"+s].GetXaxis().SetTitleSize(0.)
        for b in range(histos[h+"_"+s].GetNbinsX()) :
            if histos[h+"_"+s].GetBinContent(b) < 0 :
                histos[h+"_"+s].SetBinContent(b,0)
                histos[h+"_"+s].SetBinError(b,0)
        histos[h+"_"+s].SetLineColor(c)
        histos[h+"_"+s].SetMarkerColor(c)
        histos[h+"_"+s].SetFillColor(c)
        stacks[h].Add(histos[h+"_"+s])
        if h+"_bg" not in histos :
            histos[h+"_bg"] = histos[h+"_"+s].Clone(h+"_bg")
            histos[h+"_bg"].SetLineColor(ROOT.kBlack)
            histos[h+"_bg"].SetFillColor(ROOT.kBlack)
            histos[h+"_bg"].SetFillStyle(3544)
        else :
            histos[h+"_bg"].Add(histos[h+"_"+s])
    if data :
        histos[h+"_Data"] = f.Get(h+"_Data")
        histos[h+"_Data"].SetLineColor(ROOT.kBlack)
        histos[h+"_Data"].SetLineWidth(2)
        histos[h+"_Data"].SetMarkerStyle(20)
        histos[h+"_Ratio"] = histos[h+"_Data"].Clone(h+"_Ratio")
        histos[h+"_Ratio"].Divide(histos[h+"_bg"])
            
tLumi = ROOT.TLatex(0.95,0.955,str(lumi)+" fb^{-1} (13 TeV)")
tLumi.SetNDC()
tLumi.SetTextAlign(31)
tLumi.SetTextFont(42)
tLumi.SetTextSize(0.042)
tLumi.SetLineWidth(2)
tECM = ROOT.TLatex(0.95,0.955,"(13 TeV)")
tECM.SetNDC()
tECM.SetTextAlign(31)
tECM.SetTextFont(42)
tECM.SetTextSize(0.042)
tECM.SetLineWidth(2)
tCMS = ROOT.TLatex(0.125,0.955,"CMS")
tCMS.SetNDC()
tCMS.SetTextAlign(11)
tCMS.SetTextFont(61)
tCMS.SetTextSize(0.0525)
tCMS.SetLineWidth(2)
tSim = ROOT.TLatex(0.295,0.955,"Simulation")
tSim.SetNDC()
tSim.SetTextAlign(11)
tSim.SetTextFont(52)
tSim.SetTextSize(0.042)
tSim.SetLineWidth(2)
tPrel = ROOT.TLatex(0.295,0.955,"Preliminary")
tPrel.SetNDC()
tPrel.SetTextAlign(11)
tPrel.SetTextFont(52)
tPrel.SetTextSize(0.042)
tPrel.SetLineWidth(2)

legbg = ROOT.TLegend(0.2,0.67,0.5,0.89,"","brNDC")
legbg.SetBorderSize(0)
legbg.SetTextSize(0.033)
legbg.SetLineColor(1)
legbg.SetLineStyle(1)
legbg.SetLineWidth(2)
legbg.SetFillColor(0)
legbg.SetFillStyle(1001)
legsig = ROOT.TLegend(0.5,0.67,0.85,0.89,"","brNDC")
legsig.SetBorderSize(0)
legsig.SetTextSize(0.033)
legsig.SetLineColor(1)
legsig.SetLineStyle(1)
legsig.SetLineWidth(2)
legsig.SetFillColor(0)
legsig.SetFillStyle(1001)
for s,l in zip(bgsamples,bglegend) :
    legbg.AddEntry(histos[histonames[0]+"_"+s],l,"f")
if data:
    legsig.AddEntry(histos[histonames[0]+"_Data"],"Data","ep")
for s,l in zip(reversed(sigsamples),reversed(siglegend)) :
    legsig.AddEntry(histos[histonames[0]+"_"+s],l,"l")
        
for h in histonames :
    c1 = ROOT.TCanvas("c1", "",334,192,600,600)
    c1.SetFillColor(0)
    c1.SetBorderMode(0)
    c1.SetBorderSize(2)
    c1.SetTickx(1)
    c1.SetTicky(1)
    c1.SetLeftMargin(0.18)
    c1.SetRightMargin(0.05)
    c1.SetTopMargin(0.07)
    c1.SetBottomMargin(0.15)
    c1.SetFrameFillStyle(0)
    c1.SetFrameBorderMode(0)
    c1.SetFrameFillStyle(0)
    c1.SetFrameBorderMode(0)
    if logy:
        c1.SetLogy()
    maximum = max(histos[h+"_bg"].GetMaximum(),1.)
    minimum = max(histos[h+"_bg"].GetMinimum(),0.)
    if logy:
        minimum = pow(10.0, math.floor(math.log10(0.9*minimum))) if minimum != 0 else True
        maximum = pow(10.0, math.ceil( math.log10(100*maximum))) if maximum != 0 else True
        minimum = 0.02 if minimum == 0 else True
        minimum = 0.2  if (minimum > 1 and minimum < 5) else True
        minimum = 2.0  if minimum > 0 else True
    else:
        minimum = 0.
        maximum *= 2. 

    stacks[h].SetMaximum(maximum)
    histos[h+"_bg"].SetMaximum(maximum)
    if data:
        histos[h+"_Data"].SetMaximum(maximum)
    stacks[h].Draw("hist")
    stacks[h].SetHistogram(histos[h+"_bg"])
    stacks[h].Draw("hist")
    #histos[h+"_bg"].Draw("sameE2")
    histos[h+"_Data"].Draw("sameE0X0") if data else True
    for s in reversed(sigsamples) :
        histos[h+"_"+s].Draw("histsame")
    legbg.Draw()
    legsig.Draw()
    tLumi.Draw()
    tCMS.Draw()
    tSim.Draw()

    c1.cd()
    outname = "Log_"+h if logy else "Lin_"+h
    outname = "plots/" + outname + ".pdf"
    c1.SaveAs(outname)
    c1.cd()
    
for s in stacks :
    stacks[s].Delete()
