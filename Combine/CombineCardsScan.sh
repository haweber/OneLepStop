#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/'
#thedir='temp/'
fakedata=true
dataisbg=true

signaltype='T2tt'
declare -i stopmasslow=425
declare -i stopmasshigh=850
declare -i stopmassstep=25
declare -i lspmasslow=100
declare -i lspmasshigh=325
declare -i lspmassstep=25
declare -i chargmasslow=-1
declare -i chargmasshigh=-1
declare -i chargmassstep=-1
xval=-1
declare -i numbins=9
declare -i zero=0

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

if [ $stopmassstep -lt 1 ]
then
    stopmassstep=1000
fi
if [ ${lspmassstep} -lt 1 ]
then
    lspmassstep=1000
fi
if [ ${chargmassstep} -lt 1 ]
then
    chargmassstep=1000
fi

NameArray=( )
BinArray=("met250_mt2w0" "met250_mt2w200" "met300_mt2w0" "met300_mt2w200" "met350_mt2w0" "met350_mt2w200" "met400_mt2w0" "met400_mt2w200" "met500_mt2w200")

for (( t=0; t<=${stopmasshigh}; t+=$stopmassstep ))
do
    for (( l=$lspmasslow; l<=$lspmasshigh; l+=$lspmassstep ))
    do
	if [ $l -gt $t ]
	then
	    continue
	fi	   
	for (( c=$chargmasslow; c<=$chargmasshigh; c+=$chargmassstep ))
	do
	    #Name=`echo datacard_${signaltype}_${t}`
	    Name=`echo ${signaltype}_${t}`
	    if [ ${c} -gt 0 ]
	    then
		if [ $c -gt $t ]
		then
		    continue
		fi
		if [ $l -gt $c ]
		then
		    continue
		fi
		Name=`echo ${Name}_${c}_${l}`
	    elif [ ${xval} -gt 0 ]
	    then
		Name=`echo ${Name}_${l}_${xval}`
	    else
		Name=`echo ${Name}_${l}`
	    fi
	    NameArray=("${NameArray[@]}" "${Name}")
	    #echo ${NameArray[@]}
	    #echo $t $c $l
	    #echo $stopmasslow $stopmasshigh $stopmassstep
	    #echo $lspmasslow $lspmasshigh $lspmassstep
	done
    done
done

#echo ${Name}

for Name in "${NameArray[@]}"
do
    combinestring=combineCards.py
    validcommand=true
    nonvalidfile=' '
    #for i in {1..9}
    #for i in `seq 1 ${numbins}`;
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
	break
	fi
	chnum=$(($i + 1))
	#combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_bin${i}.txt`
	#combinestring=`echo ${combinestring} ch${chnum}=${thedir}${Name}_${BinArray[$i]}.txt`
	combinestring=`echo ${combinestring} ${thedir}${Name}_${BinArray[$i]}.txt`
	#echo ${combinestring}
    done
    
    if [ "$validcommand" = true ]
    then
	eval ${combinestring} > ${thedir}combinedcards/combined_${Name}.txt
	#echo ${combinestring}
	echo Combined cards for ${Name} into ${thedir}combinedcards/combined_${Name}.txt
	#else
	#    echo There was a non-valid file (${nonvalidfile}). Did not combine for ${Name}.txt
    fi
done
