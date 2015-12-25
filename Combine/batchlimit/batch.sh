
#directory of combined datacards
mydir=xxx/
NAME=T2tt
MSTOP=100
MLSP=-9
MCharg=-9
xval=-1
postfit=false
#xsecup 1 xsecdown -1
xsecupdown=0

#PUT THIS INTO A SPLITTING LOOP - probably enough to split per stop mass - i.e. do batch submission for each stop mass

#prepare parameters for datacard running
declare -i stopmasslow=100
declare -i stopmasshigh=1000
declare -i stopmassstep=25
declare -i lspmasslow=0
declare -i lspmasshigh=450
declare -i lspmassstep=25
declare -i chargmasslow=-1
declare -i chargmasshigh=-1
declare -i chargmassstep=-1
xval=-1

if [ $MSTOP -gt -1 ]
then
    stopmasslow=$MSTOP
    stopmasshigh=$MSTOP
fi
if [ $MLSP -gt -1 ]
then
    lspmasslow=$MLSP
    lspmasshigh=$MLSP
fi
#if MCharg = -1 - then run over it, if <-5 then don't
if [ $MCharg -gt -1 ]
then
    chargmasslow=$MCharg
    chargmasshigh=$MCharg
    chargmassstep=25
elif [ $Mcharg -gt -5 ]
then
    chargmasslow=0
    chargmasshigh=1000
    chargmassstep=25
fi

#create list of datacards I want to run
NameArray=( )
for (( t=${stopmasslow}; t<=${stopmasshigh}; t+=$stopmassstep ))
do
    for (( l=$lspmasslow; l<=$lspmasshigh; l+=$lspmassstep ))
    do
	if [ $l -gt $t ]
	then
	    continue
	fi	   
	for (( c=$chargmasslow; c<=$chargmasshigh; c+=$chargmassstep ))
	do
	    Name=`echo ${NAME}_${t}`
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
	    #add here xsec up down
	    if [ ${xsecupdown} -eq -1 ]
	    then
		Name=`echo ${Name}_xsecdown`
	    elif [ ${xsecupdown} -eq 1 ]
	    then
		Name=`echo ${Name}_xsecup`
	    fi
	    NameArray=("${NameArray[@]}" "${Name}")
	done
    done
done

#copy datacard here
for Name in "${NameArray[@]}"
do
    if [ ! -e "${Name}" ] && [ ! -f "${Name}" ] && [ ! -s "${Name}" ]
    then
	#echo "File ${temp} does not exist. Stop."
	exit 0;
    else    
	#computes automatically observed and expected limit together
	cp ${mydir}/datacard_${Name}.txt .
    fi
done
tar czfv $DATACARDS_TAR datacard_*.txt
rm datacard_*.txt

#now do condor submission
