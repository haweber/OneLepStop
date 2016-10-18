#don't use txt here
datacard="datacard"
datacarddir=""

if [ $# -eq 2 ]
then
    datacarddir=$2
    datacard=$1
    echo "don't use txt in datacard name"
    echo "please note that you should not put the directory in the datacard name - put it as a secondary argument"
elif [ $# -eq 1 ]
then
    datacard=$1
    echo "please note that you should not put the directory in the datacard name - put it as a secondary argument"
else
    echo "provide at least a datacard name"
    echo "don't use txt in datacard name"
    echo "please note that you should not put the directory in the datacard name - put it as a secondary argument"
    return
fi


#note, do this once per analysis - choose any datacard containing all SR bins

text2workspace.py --X-allow-no-signal --X-allow-no-background ${datacarddir}${datacard}.txt

#combine -M MaxLikelihoodFit --saveShapes --saveWithUnc --numToysForShape 2000  --saveOverall ${datacard}.root --preFitValue 0
combine -M MaxLikelihoodFit --saveShapes --saveWithUncertainties --numToysForShape 2000  --saveOverallShapes ${datacarddir}${datacard}.root --preFitValue 0

root -l -b -q GetCorrelationMatrix.C+

#renaming just to make sure we know where this is from
mv test.root CorrelationCovariance_${datacard}.root
