
INPUTDIR="datacards/fakedata/dataisbg/combinedcards/"
OUTPUTDIR="outputfiles/fakedata/dataisbg/"
LOGDIR="logs"

declare -a samples=("T2tt")

postfit=false #if false do prefit

#get list of files for that samples
for i in "${samples[@]}"
do
    ls ${INPUTDIR}combined_${i}_*.txt > myfilelist

done

nLines=`wc -l < myfilelist`

#echo $nLines

methodcmd="--noFitAsimov"
methodname="PreFit"
if [ "${postfit}" = true ]
then
    methodcmd=" "
    methodname="PostFit"
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

    if [ "$Par3" == "" ]
    then
	combine  -M Asymptotic ${temp} ${methodcmd} -n ${methodname}${Par0}_${Par1}_${Par2} > /dev/null 2>&1
	mv higgsCombine${methodname}${Par0}_${Par1}_${Par2}.Asymptotic.mH120.root ${OUTPUTDIR}Limits_Asymptotic_${methodname}_${Par0}_${Par1}_${Par2}.root
    else
	combine  -M Asymptotic ${temp} ${methodcmd} -n ${methodname}${Par0}_${Par1}_${Par2}_${Par3} > /dev/null 2>&1
	mv higgsCombine${methodname}${Par0}_${Par1}_${Par2}_${Par3}.Asymptotic.mH120.root ${OUTPUTDIR}Limits_Asymptotic_${methodname}_${Par0}_${Par1}_${Par2}_${Par3}.root
    fi
    
done

rm myfilelist
