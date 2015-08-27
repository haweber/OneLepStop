The current procedure is

0. setup your CMSSW environment, see
https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit#ROOT6_SLC6_release_CMSSW_7_4_X

1. get inputs for datacard maker
One example is the looper doAll_makeDataCardInputs.C running MakeDataCardInputs.C
This create rootfiles that are used to make datacards from MC
This is still under optimization. Also, at a later stage
the rootfiles should be given by the people doing background estimations and systematic studies on signal.

2. create data cards
Currently done with makeDataCards.C
The function makeDataCardsScan() does all the work.
You can give input which scan you want to do (default T2tt), if you want to use fakedata
(false, false - first one needs to be true if no data available), and the areas of the scan
Note, that in the function load() the correlations for background uncertainties are decided!!
Here, the code needs to be adjusted for uncertainties.
Also, as 1. is still in progress, possible adjustments here might be needed.
Need to think to implement shape uncertainties.

3. create limits/significances
done with getLimits.sh/getSignificances.sh
For limits can decide on prefit or postfit.
As the asymptotic is run, you get expected and observed at one time.
For significances, can set observed/expected; for expected can set a priori/a posteriori and the number of toys (-1 means no toys).
Here profile likelihood is run.
Currently, both scripts are written such that all datacards in a given directory are processed.

Still to do: Run on condor/crab. Leave that for later, when we have a scan to test it.
I think we don't need crab if we don't run Hybrid method.

4. Read out the limits/significances from the rootfiles created in 3.
done with ReadLimitSignificance.C and function ReadoutLimitScan()
At this stage, need to give scan (e.g. T2tt) Observed/Expected (Obs/ExpPriori/ExpPosteriori/...), the directory of the rootfiles, the method used (asymptotic/profilelikelihood), limit/significance?, quantile/limiterror (at asymptotic limit), and if fake data was used.
Here, some work to optimize the input is needed.
