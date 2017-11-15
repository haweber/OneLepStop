{
  gROOT->ProcessLine(".L makeDataCards_ttH.C+");

  //0: std, 1: compressed
  makeDataCardsAllBins("ttH_125",0);


}
