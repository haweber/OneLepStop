
#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/'
fakedata=true
dataisbg=true

signaltype='T2tt'
stopmass=425
lspmass=325
chargmass=-1
xval=-1
numbins=9

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



Name=`echo ${signaltype}_${stopmass}`
if [ ${chargmass} -gt 0 ]
then
    Name=`echo ${Name}_${chargmass}_${lspmass}`
elif [ ${xval} -gt 0 ]
then
    Name=`echo ${Name}_${lspmass}_${xval}`
else
    Name=`echo ${Name}_${lspmass}`
fi

#echo ${Name}

combinestring=combineCards.py
#for i in {1..9}
#for i in `seq 1 ${numbins}`;
#do
#    #echo $i
#    combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_bin${i}.txt`
#    #echo ${combinestring}
#done

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
	break
    fi
    chnum=$(($i + 1))
    #combinestring=`echo ${combinestring} ch${i}=${thedir}${Name}_bin${i}.txt`
    combinestring=`echo ${combinestring} ch${chnum}=${thedir}${Name}_${BinArray[$i]}.txt`
    #echo ${combinestring}
done

eval ${combinestring} > ${thedir}combinedcards/combined_${Name}.txt

#echo ${combinestring}

echo Combined cards for ${Name} into ${thedir}combinedcards/combined_${Name}.txt
