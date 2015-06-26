{


  gROOT->ProcessLine(".L TestBDT.C+");

  TString signal[4] = {"Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  TString background[4] = {"TTbar1l","TTbar2l","SingleT","TTV"};
  
  for(int i = 0; i<4; ++i){
    for(int j = 0; j<4; ++j){
      TestBDT(signal[i],background[j]);
    }
  }

}
