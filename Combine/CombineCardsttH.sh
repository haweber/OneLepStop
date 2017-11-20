if [ $# -eq 0 ]
then
    echo You should provide at least the signal.
    exit 0
fi

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

thedir='../datacardsTTH/'
#thedir='../datacardsMoriond17_36p6fbinv/correlated/nosigsyst/'
fakedata=false
dataisbg=false
maxbins=27
signal=$1
    

#signal='T2tt_425_325'

if [ $# -gt 1 ]
then
    fakedata=$2
fi

if [ $# -gt 2 ]
then
    dataisbg=$3
fi
    

if [ "$fakedata" = true ]
then
    thedir=`echo ${thedir}fakedata/`
else
    thedir=`echo ${thedir}`
fi

#echo ${thedir}



Name=`echo datacard_${signal}`

#echo ${Name}

combinestring=combineCards.py
validcommand=false

counter=0
for i in `seq 1 ${maxbins}`;
do
    #echo $i
    #echo "${thedir}${Name}_${i}.txt"
    if [ ! -e "${thedir}${Name}_b${i}.txt" ] && [ ! -f "${thedir}${Name}_b${i}.txt" ] && [ ! -s "${thedir}${Name}_b${i}.txt" ]
    then
	nonvalidfile=`echo ${thedir}${Name}_b${i}.txt`
	continue
    fi
    counter=$((counter+1))
    validcommand=true
    chnum=$(($i + 1))
    combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_b${i}.txt`
    #echo ${combinestring}
done

if [ "$validcommand" = true ]
then
    eval ${combinestring} -S > ${thedir}combinedcards/${Name}.txt
    #echo ${combinestring}
    echo "Combined cards for ${Name} into ${thedir}combinedcards/${Name}.txt"
#else
#    echo "Some input file did not exist. Didnt combine ${thedir}combinedcards/${Name}.txt"
fi
