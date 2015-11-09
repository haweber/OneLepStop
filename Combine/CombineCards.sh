
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

#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/'
fakedata=false
dataisbg=true

if [ $# -eq 0 ]
then
    echo You should provide at least the signal.
    exit 0
fi
    

#signal='T2tt_425_325'
signal=$1

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
    if [ "$dataisbg" = true ]
    then
	thedir=`echo ${thedir}dataisbg/`
    else
	thedir=`echo ${thedir}dataisbgsig/`
    fi
else
    thedir=`echo ${thedir}data/`
fi

#echo ${thedir}



Name=`echo ${signal}`

#echo ${Name}

combinestring=combineCards.py
validcommand=true

BinArray=("met250_mt2w0" "met250_mt2w200" "met300_mt2w0" "met300_mt2w200" "met350_mt2w0" "met350_mt2w200" "met400_mt2w0" "met400_mt2w200" "met500_mt2w200")
for i in "${!BinArray[@]}"
do
    #echo $i
    #echo "${thedir}${Name}_${i}.txt"
    #if [ ! -e "${thedir}${Name}_bin${i}.txt" ] && [ ! -f "${thedir}${Name}_bin${i}.txt" ] && [ ! -s "${thedir}${Name}_bin${i}.txt" ]
    if [ ! -e "${thedir}${Name}_${BinArray[$i]}.txt" ] && [ ! -f "${thedir}${Name}_${BinArray[$i]}.txt" ] && [ ! -s "${thedir}${Name}_${BinArray[$i]}.txt" ]
    then
	validcommand=false
	#nonvalidfile=`echo ${thedir}${Name}_bin${i}.txt`
	nonvalidfile=`echo ${thedir}${Name}_${BinArray[$i]}.txt`
	#echo "file ${thedir}${Name}_${BinArray[$i]}.txt does not exist. dont combine"
	break
    fi
    chnum=$(($i + 1))
    #combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_bin${i}.txt`
    combinestring=`echo ${combinestring} ch${chnum}=${thedir}${Name}_${BinArray[$i]}.txt`
    #echo ${combinestring}
done

if [ "$validcommand" = true ]
then
    eval ${combinestring} > ${thedir}combinedcards/combined_${Name}.txt

    #echo ${combinestring}

    echo "Combined cards for ${Name} into ${thedir}combinedcards/combined_${Name}.txt"
#else
#    echo "Some input file did not exist. Didnt combine"
fi
