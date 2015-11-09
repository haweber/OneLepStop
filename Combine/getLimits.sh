
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
postfit=false #if false do prefit


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
    postfit=$2
fi
if [ $# -gt 2 ]
then
    fakedata=$3
fi
if [ $# -gt 3 ]
then
    dataisbg=$4
fi

methodcmd="--noFitAsimov"
methodname="PreFit"
if [ "${postfit}" = true ]
then
    methodcmd=" "
    methodname="PostFit"
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

temp=`echo ${INPUTDIR}combined_${Signal}.txt`

if [ ! -e "${temp}" ] && [ ! -f "${temp}" ] && [ ! -s "${temp}" ]
then
    echo "File ${temp} does not exist. Stop."
    exit 0;
else    
    #computes automatically observed and expected limit together
    combine  -M Asymptotic ${temp} ${methodcmd} -n ${methodname}${Signal} > /dev/null 2>&1
    mv higgsCombine${methodname}${Signal}.Asymptotic.mH120.root ${OUTPUTDIR}Limits_Asymptotic_${methodname}_${Signal}.root
fi
