#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/'
fakedata=true
dataisbg=true

signaltype='T2tt'

postfit=false #if false do prefit

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

if [ $# -ge 1 ]
then
    signaltype=$1
fi
if [ $# -ge 2 ]
then
    postfit=$2
fi
if [ $# -ge 3 ]
then
    fakedata=$3
fi
if [ $# -ge 4 ]
then
    dataisbg=$4
fi
if [ $# -eq 10 ]
then
    stopmasslow=$5
    stopmasshigh=$6
    stopmassstep=$7
    lspmasslow=$8
    lspmasshigh=$9
    lspmassstep=${10}
elif [ $# -eq 11 ]
then
    stopmasslow=$5
    stopmasshigh=$6
    stopmassstep=$7
    lspmasslow=$8
    lspmasshigh=$9
    lspmassstep=${10}
    xval=${11}
elif [ $# -ge 13 ]
then
    stopmasslow=$5
    stopmasshigh=$6
    stopmassstep=$7
    chargmasslow=$8
    chargmasshigh=$9
    chargmassstep=${10}
    spmasslow=${11}
    lspmasshigh=${12}
    lspmassstep=${13}
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
    bash getLimits.sh ${Name} ${postfit} ${fakedata} ${dataisbg}
done

