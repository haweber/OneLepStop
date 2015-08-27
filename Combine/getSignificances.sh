
INPUTDIR="datacards/fakedata/dataisbg/combinedcards/"
OUTPUTDIR="outputfiles/fakedata/dataisbg/"
LOGDIR="logs"

observed=false #if false get expectected
priori=true #if false use posteriori

declare -a samples=("T2tt")
declare -i ntoys=200

#get list of files for that samples
for i in "${samples[@]}"
do
    ls ${INPUTDIR}combined_${i}_*.txt > myfilelist

done

nLines=`wc -l < myfilelist`

#echo $nLines

methodcmd="--toysFreq"
methodname="Posteriori"
if [ "${priori}" = true ]
then
    methodcmd=" "
    methodname="Priori"
fi

#run all samples
for (( i = 1; i <= $nLines; i++ ))
do
    

    temp=`awk "NR==$i" myfilelist` #this is the datacard I have
    #echo ${temp}
    Par0=`echo $temp |cut -d'_' -f2` #sample
    Par1=`echo $temp |cut -d'_' -f3` #top mass
    Par2=`echo $temp |cut -d'_' -f4` #chargino or LSP mass
    Par3=`echo $temp |cut -d'_' -f5` #LSP mass or x or empty
    Par1=`echo $Par1 |cut -d'.' -f1`
    Par2=`echo $Par2 |cut -d'.' -f1` #if here file ends with .txt
    Par3=`echo $Par3 |cut -d'.' -f1`

    if [ "${observed}" = true ]
    then
	if [ "$Par3" == "" ]
	then
	    combine  -M ProfileLikelihood --significance ${temp} -n Obs${Par0}_${Par1}_${Par2} > /dev/null 2>&1
	    mv higgsCombineObs${Par0}_${Par1}_${Par2}.ProfileLikelihood.mH120.root ${OUTPUTDIR}Signif_ProfileLikelihood_Obs_${Par0}_${Par1}_${Par2}.root
	else
	    combine  -M ProfileLikelihood --significance ${temp} -n Obs${Par0}_${Par1}_${Par2}_${Par3} > /dev/null 2>&1
	    mv higgsCombineObs${Par0}_${Par1}_${Par2}_${Par3}.ProfileLikelihood.mH120.root ${OUTPUTDIR}Signif_ProfileLikelihood_Obs_${Par0}_${Par1}_${Par2}_${Par3}.root
	fi
    else
	if [ "$Par3" == "" ]
	then
	    rn=$RANDOM
	    combine  -M ProfileLikelihood --significance ${temp} -n Exp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${rn} -t ${ntoys} --expectSignal=1 ${methodcmd} > /dev/null 2>&1
	    if [ ${ntoys} -gt 0 ]
	    then
		mv higgsCombineExp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${rn}.ProfileLikelihood.mH120*.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}Toys${ntoys}_${Par0}_${Par1}_${Par2}.root
	    else
		mv higgsCombineExp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${rn}.ProfileLikelihood.mH120*.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}_${Par0}_${Par1}_${Par2}.root
	    fi
	else
	    rn=$RANDOM
	    combine  -M ProfileLikelihood --significance ${temp} -n Exp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${Par3}_${rn} -t ${ntoys} --expectSignal=1 ${methodcmd} > /dev/null 2>&1
	    if [ ${ntoys} -gt 0 ]
	    then
		mv higgsCombineExp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${Par3}_${rn}.ProfileLikelihood.mH120*.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}Toys${ntoys}_${Par0}_${Par1}_${Par2}_${Par3}.root
	    else
		mv higgsCombineExp${methodname}Toys${ntoys}${Par0}_${Par1}_${Par2}_${Par3}_${rn}.ProfileLikelihood.mH120*.root ${OUTPUTDIR}Signif_ProfileLikelihood_Exp${methodname}_${Par0}_${Par1}_${Par2}_${Par3}.root
	    fi
	fi
    fi
    
done

rm myfilelist
