
#check cmssw and if it contains HiggsCombine
if [ -z $CMSSW_BASE ]; then
    echo "CMSSW_BASE var not set, run cmsenv, exiting..."
    exit 0;
fi
DIRECTORY=`echo $CMSSW_BASE/src/HiggsAnalysis`
if [ ! -d "$DIRECTORY" ]; then
    echo "Your CMSSW release does not have HiggsCombined installed. Please do."
    echo "Please read https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit"
    echo "You should have ${DIRECTORY}. Exiting..."
    exit 0;
fi

#this is only the base, rest will be added depending on fakedata, dataisbg
INPUTDIR="datacards/"
OUTPUTDIR="outputfiles/"




#Signal="T2tt_425_325"
declare -i ntoys=-1

observed=false #if false get expectected
priori=true #if false use posteriori

fakedata=true
dataisbg=true

if [ $# -eq 0 ]
then
    echo You should provide at least the signal.
    exit 0
fi
Signal=$1

if [ $# -gt 1 ]
then
    ntoys=$2
fi
if [ $# -gt 2 ]
then
    observed=$3
fi
if [ $# -gt 3 ]
then
    priori=$4
fi
if [ $# -gt 4 ]
then
    fakedata=$5
fi
if [ $# -gt 5 ]
then
    dataisbg=$6
fi



methodcmd="--toysFreq"
methodname="Posteriori"
if [ "${priori}" = true ]
then
    methodcmd=" "
    methodname="Priori"
fi

thedir=''
if [ "$fakedata" = true ]
then
    thedir=`echo ${thedir}fakedata/`
    if [ "$dataisbg" = true ]
    then
	thedir=`echo ${thedir}dataisbg/`
    else
	thedir=`echo ${thedir}dataisbgsig/`
    fi
else
    thedir=`echo ${thedir}data/`
fi
INPUTDIR=`echo ${INPUTDIR}${thedir}combinedcards/`
OUTPUTDIR=`echo ${OUTPUTDIR}${thedir}`

temp=`echo ${IMPUTDIR}combined_${Signal}.txt`

if [ "${observed}" = true ]
then
    combine  -M ProfileLikelihood --significance ${temp} -n Obs${Signal} > /dev/null 2>&1
    mv higgsCombineObs${Signal}.ProfileLikelihood.mH120.root ${OUTPUTDIR}Signif_ProfileLikelihood_Obs_${Signal}.root
else
    rnO=$RANDOM
    rnT=$RANDOM
    #as $RANDOM is pretty coarse use two randoms. In principle, I make sure that each file has a single identifier such that the mv statement will work.
    #currently don't need random numbers, but might use it if we run toys on separate notes, and then add up the two rootfiles
    #in this case use rnO as random number input to this tool, else it will be 123456.
    combine  -M ProfileLikelihood --significance ${temp} -n Exp${methodname}Toys${ntoys}${Signal}_${rnO}_${rnT} -t ${ntoys} --expectSignal=1 ${methodcmd} > /dev/null 2>&1
    #ls higgsCombineExp${methodname}Toys${ntoys}${Signal}_${rnO}_${rnT}.ProfileLikelihood.mH120*.root > myfilelist
    #echo ${myfilelist}
    if [ ${ntoys} -gt 0 ]
    then
	mv higgsCombineExp${methodname}Toys${ntoys}${Signal}_${rnO}_${rnT}.ProfileLikelihood.mH120.123456.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}Toys${ntoys}_${Signal}.root
    else
	mv higgsCombineExp${methodname}Toys${ntoys}${Signal}_${rnO}_${rnT}.ProfileLikelihood.mH120.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}_${Signal}.root
    fi
fi
