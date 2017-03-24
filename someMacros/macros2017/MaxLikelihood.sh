combine -M MaxLikelihoodFit datacard.txt  --saveShapes --saveWithUncertainties
python diffNuisances.py  mlfit.root -g output.root
