
#directory of combined datacards
mydir=$DATACARD_DIR
NAME=T2tt
MSTOP=-9
MLSP=-9
MCharg=-9
xval=-1
postfit=false
#xsecup 1 xsecdown -1
xsecupdown=0
#SR=2 - compressed SR
SR=1

if [ $SR -eq 2 ]
then
    mydir=${DATACARD_DIR}compressed/
fi

tar_file=/hadoop/cms/store/user/haweber/HiggsCombine_CMSSW_7_1_5.tar.gz

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
#run a job per stop mass - for now
for (( t=${stopmasslow}; t<=${stopmasshigh}; t+=$stopmassstep ))
do
    TYPE_MASS=`echo ${NAME}_${t}`
    if [ $SR -eq 2 ]
    then
	TYPE_MASS=`echo Compressed${TYPE_MASS}`
    fi
    NameArray=( )    
    for (( l=$lspmasslow; l<=$lspmasshigh; l+=$lspmassstep ))
    do
	if [ $l -gt $t ]
	then
	    continue
	fi	   
	for (( c=$chargmasslow; c<=$chargmasshigh; c+=$chargmassstep ))
	do
	    Name=$TYPE_MASS
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
	done
    done

    #add here xsec up down
    if [ ${xsecupdown} -eq -1 ]
    then
	mydir=`echo ${mydir}xsecdown/`
    elif [ ${xsecupdown} -eq 1 ]
    then
	mydir=`echo ${mydir}xsecup/`
    fi

    #copy datacard here
    for Name in "${NameArray[@]}"
    do
	if [ ! -e "${mydir}/datacard_${Name}.txt" ] && [ ! -f "${mydir}/datacard_${Name}.txt" ] && [ ! -s "${mydir}/datacard_${Name}.txt" ]
	then
	    #echo "File ${temp} does not exist. Stop."
	    continue
	else    
	    #computes automatically observed and expected limit together
	    cp ${mydir}/datacard_${Name}.txt .
	fi
    done
    DATACARDS_TAR=datacards.tar.gz
    tar czfv $DATACARDS_TAR datacard_*.txt
    rm datacard_*.txt

    #now do condor submission

    cp condorFileTemplate condorFile
    sed -i "s,ARG1,$postfit,g" condorFile
    sed -i "s,ARG2,$COPYDIR,g" condorFile
    sed -i "s,ARG3,$CONDOR_DIR_NAME,g" condorFile
    sed -i "s,ARG4,$DATACARDS_TAR,g" condorFile
    sed -i "s,ARG5,$MAKER_NAME,g" condorFile
    sed -i "s,ARG6,$TYPE_MASS,g" condorFile
    sed -i "s,ARG7,$SCRATCH_DIR,g" condorFile
    sed -i "s,ARG8,$USER_EMAIL,g" condorFile
    sed -i "s,USER_PROXY,$pathToProxy,g" condorFile
    sed -i "s,TARFILE1,$tar_file,g" condorFile
    sed -i "s,TARFILE2,$DATACARDS_TAR,g" condorFile
    condor_submit condorFile

done

