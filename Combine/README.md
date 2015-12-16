The current procedure is

0. setup your CMSSW environment, see
https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit#ROOT5_SLC6_release_CMSSW_7_1_X
(not the ROOT6 implementation is not recommended)

1. get inputs for datacard maker - THIS IS ONLY IF RUN ONLY MC YIELDS!
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

--> Here, the code needs to be adjusted for uncertainties (especially
    the load function but also other places...)

Also, as 1. is still in progress, possible adjustments here might be needed,
i.e. need to think to implement shape uncertainties.
Probably this will be just hardcoded (for now)

2a. Combine datacards done by CombineCards.sh

Input/output datacards directories are hardcoded. Inputs are
1) signal name
2) use fake data which is 3) bg-only or bg+sig.

Note, that this needs the respective single bin datacards.

There is a more automatized 'independent' script called
CombineCardsAllScans.sh (not thoroughly tested - obviously).


3. create limits/significances (requires combined data cards)
done with getLimits.sh/getSignificances.sh

3a. For limits can decide
1) signal name
2) prefit or postfit,
3) use fake data which is 4) bg-only or bg+sig.

As the asymptotic is run, you get expected and observed at one time.

Currently input and output direcories are hardcoded (I think it is
more robust against human error).

There are further automized files like getLimitsAllScans.sh (tests are
limited on their functionality.

Note that getLimitsScan.sh does NOT inherit from getLimits.sh


3b. For significances, again input/output directories are hardcoded.
You can set
1) signal name
2) number of toys (or no toys = -1)
3) observed or expected?
4) priori or posteriori
5) use fake data which is 6) bg-only or bg+sig.

Here profile likelihood is run.

Still to do: Run on condor/crab. Leave that for later, when we have a scan to test it.
I think we don't need crab if we don't run Hybrid method.

There is an 'indendent' automatized code called getSignificancesAllScans.sh

4. Read out the limits/significances from the rootfiles created in 3.
done with ReadLimitSignificance.C and function ReadoutLimitScan()
At this stage, need to give scan (e.g. T2tt) Observed/Expected (Obs/ExpPriori/ExpPosteriori/...), the directory of the rootfiles, the method used (asymptotic/profilelikelihood), limit/significance?, quantile/limiterror (at asymptotic limit), and if fake data was used.
Here, some work to optimize the input is needed.

This code is not really that great - it creates a text file with the
output.

Need to work here...
