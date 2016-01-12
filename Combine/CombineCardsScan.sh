#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/'
fakedata=true
dataisbg=true

signaltype='T2tt'
declare -i stopmasslow=100
declare -i stopmasshigh=975
declare -i stopmassstep=25
declare -i lspmasslow=0
declare -i lspmasshigh=500
declare -i lspmassstep=25
declare -i chargmasslow=-1
declare -i chargmasshigh=-1
declare -i chargmassstep=-1
xval=-1

if [ $# -ge 1 ]
then
    signaltype=$1
fi

if [ $# -ge 2 ]
then
    fakedata=$2
fi
if [ $# -ge 3 ]
then
    dataisbg=$3
fi
if [ $# -eq 9 ]
then
    stopmasslow=$4
    stopmasshigh=$5
    stopmassstep=$6
    lspmasslow=$7
    lspmasshigh=$8
    lspmassstep=$9
elif [ $# -eq 10 ]
then
    stopmasslow=$4
    stopmasshigh=$5
    stopmassstep=$6
    lspmasslow=$7
    lspmasshigh=$8
    lspmassstep=$9
    xval=${10}
elif [ $# -ge 12 ]
then
    stopmasslow=$4
    stopmasshigh=$5
    stopmassstep=$6
    chargmasslow=$7
    chargmasshigh=$8
    chargmassstep=$9
    spmasslow=${10}
    lspmasshigh=${11}
    lspmassstep=${12}
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
    bash CombineCards.sh ${Name} ${fakedata} ${dataisbg}
done

