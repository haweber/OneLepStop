void rootlogon() {
  //gSystem->SetIncludePath(" -I../MT2Code/include/ -I../TESCO/include/");
  gSystem->Load("libPhysics");
  gSystem->Load("libFWCoreFWLite.so");
  AutoLibraryLoader::enable();
  gSystem->Load("libDataFormatsFWLite.so");
  //gSystem->Load("../MT2Code/shlib/libDiLeptonAnalysis.so");
  gROOT->LoadMacro("/home/users/haweber/Software/makeCMS3ClassFiles/vecUtils.h");
  
}
