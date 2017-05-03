
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


thedir='datacards2p3fbinv/correlated/dropsigcont/'
#should make this dir configurable

if [ $# -eq 0 ]
then
    echo You should provide  the signal.
    exit 0
fi
    
signal=$1

#echo ${thedir}

Name=`echo datacard_${signal}`

#echo ${Name}

combinestring=combineCards.py
validcommand=false

maxbins=27
for i in `seq 1 ${maxbins}`;
do
    if [ ! -e "${thedir}${Name}_b${i}.txt" ] && [ ! -f "${thedir}${Name}_b${i}.txt" ] && [ ! -s "${thedir}${Name}_b${i}.txt" ]
    then
	validcommand=false
	nonvalidfile=`echo ${thedir}${Name}_b${i}.txt`
	#break
	continue
    fi
    validcommand=true
    if [ ${i} -lt 10 ]
    then
	combinestring=`echo ${combinestring} ch00${i}=${thedir}${Name}_b${i}.txt`
    elif [ ${i} -lt 100 ]
    then
	combinestring=`echo ${combinestring} ch0${i}=${thedir}${Name}_b${i}.txt`
    else
	combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_b${i}.txt`
    fi
    #echo ${combinestring}
done

if [ "$validcommand" = true ]
then
    eval ${combinestring} > ${thedir}combinedcards/${Name}.txt
    #echo ${combinestring}
    echo "Combined cards for ${Name} into ${thedir}combinedcards/${Name}.txt"
#else
#    echo "Some input file did not exist. Didnt combine"
fi
