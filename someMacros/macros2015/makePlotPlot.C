#include "dataMCplotMaker.h"
#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include <vector>
#include <string>
#include "TString.h"

using namespace std;

void makePlotPlot(){

  int bsel = 1;
  //1: 1b, //2: 2b, //-1: 1j, //-2: 2j
  
  //  vector<char*> bgnames, signames;
  vector<string> bgstrings, sigstrings;
  vector<Color_t> colors;
  const unsigned int datasetsize = 9;//12
  const unsigned int bgsetsize = 5;//8
  const unsigned int sigsetsize = datasetsize-bgsetsize;
  //string datasets[datasetsize]={"TTbar","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //char* dataset[datasetsize]={"TTbar","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //string datasets[datasetsize]={"TTbar1l","TTbar2l","TTbarH","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  //char* dataset[datasetsize]={"TTbar1l","TTbar2l","TTbarH","SingleT","TTV","WJets","VV","DYJets","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  string datasets[datasetsize]={"TTbar1l","TTbar2l","SingleT","VJets","Rare","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  char* dataset[datasetsize]={"TTbar1l","TTbar2l","SingleT","VJets","Rare","Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  const unsigned int poststringsize = 1;
  //string poststring[poststringsize] = {"MET300_noMT","MET100_MT120","noMT","MT80","MT100","MT125","MT150","SR","SR200","SR200MT2W"};
  string poststring[poststringsize] = {"MET300_"};
  const Color_t mccolor[datasetsize]={kRed-7,kCyan-3,kGreen-7,kOrange-2,kMagenta-5,kGreen+2,kYellow+1,kBlue,kMagenta};//kGreen-7 added

  string prefix = "MET300";
  
  string outputdir, inputdir;
  if(bsel == 1) inputdir = "rootfiles/MassVariableStudies/add1b/";
  if(bsel ==-1) inputdir = "rootfiles/MassVariableStudies/add1j/";
  if(bsel == 2) inputdir = "rootfiles/MassVariableStudies/add2b/";
  if(bsel ==-2) inputdir = "rootfiles/MassVariableStudies/add2j/";
  if(bsel == 1) outputdir = "plots/MassVariableStudies/add1b/";
  if(bsel ==-1) outputdir = "plots/MassVariableStudies/add1j/";
  if(bsel == 2) outputdir = "plots/MassVariableStudies/add2b/";
  if(bsel ==-2) outputdir = "plots/MassVariableStudies/add2j/";
  if(prefix!=""){
    if(bsel == 1) outputdir = "plots/MassVariableStudies/"+prefix+"/add1b/";
    if(bsel ==-1) outputdir = "plots/MassVariableStudies/"+prefix+"/add1j/";
    if(bsel == 2) outputdir = "plots/MassVariableStudies/"+prefix+"/add2b/";
    if(bsel ==-2) outputdir = "plots/MassVariableStudies/"+prefix+"/add2j/";
  }
  
  for(unsigned int n=0; n<bgsetsize; ++n) {
    //bgnames.push_back(dataset[n]);
    bgstrings.push_back(dataset[n]);
    colors.push_back(mccolor[n]);
  }
  for(unsigned int n=bgsetsize; n<datasetsize; ++n) {
    //signames.push_back(dataset[n]);
    sigstrings.push_back(dataset[n]);
    colors.push_back(mccolor[n]);
  }
  TFile *fbg[bgsetsize];
  for(unsigned int n=0; n<bgsetsize; ++n) {
    string datasetstring = datasets[n];
    if(n==0) datasetstring = "TTbar";
    else if(n==1) continue;
    //else if(n==2) continue;
    TString x = (inputdir+"Histos_"+datasetstring+".root");
    cout << x << endl;
      fbg[n] = TFile::Open(x);
      //  cout << fbg[n].IsZombie();
  }
  TFile *fsig[sigsetsize];
  for(unsigned int n=0; n<sigsetsize; ++n) {
    string datasetstring = datasets[bgsetsize+n];
    TString x = (inputdir+"Histos_"+datasetstring+".root");
    cout << x << endl;
    fsig[n] = TFile::Open(x);
  }

  vector<string> histonames;

  histonames.push_back("MT2W");                     
  histonames.push_back("DeltaPhiWl");               
  histonames.push_back("MT2_b_b");                  
  histonames.push_back("MT2_lb_b");                 
  histonames.push_back("MT2_lb_bq");                
  histonames.push_back("MT2_lb_bqq");               
  histonames.push_back("MT2_lb_b_mless");           
  histonames.push_back("MT2_lb_bq_mless");          
  histonames.push_back("MT2_lb_bqq_mless");         
  histonames.push_back("MT2_lb_bqq_Mjjj");          
  histonames.push_back("MT2_lb_bqq_Mjjj_mless");    
  histonames.push_back("MT2_lb_bqq_MjjjMlb");       
  histonames.push_back("MT2_lb_bqq_MjjjMlb_mless"); 
  histonames.push_back("MTq_max");                  
  histonames.push_back("MTq_leadj300");             
  histonames.push_back("MTq_leadj");                
  histonames.push_back("METsqrtHT");                
  histonames.push_back("RM");                       
  histonames.push_back("RM300");                    
  histonames.push_back("RM500");                    
  histonames.push_back("RM700");                    
  histonames.push_back("MT2_l_q");                  
  histonames.push_back("MT2_l_qq");                 
  histonames.push_back("MT2_l_qq_mless");           
  histonames.push_back("Topness");                  
  histonames.push_back("TopnessMod");               
  histonames.push_back("MT");                       
  histonames.push_back("DeltaPhiWl_noMT");

  /*
  histonames.push_back("MT2W");               
  histonames.push_back("MT2_b_b");            
  histonames.push_back("MT2_lb_b");           
  histonames.push_back("MT2_lb_bq");          
  //histonames.push_back("MT2_lb_bq_boost");    
  histonames.push_back("MT2_lb_bqq");         
  histonames.push_back("MT2_l_q");            
  histonames.push_back("MT2_lb_b_mless");        
  histonames.push_back("MT2_lb_bq_mless");       
  //histonames.push_back("MT2_lb_bq_boost_mless"); 
  histonames.push_back("MT2_lb_bqq_mless");      
  //histonames.push_back("MT2_l_q_boost");      
  histonames.push_back("MT2_l_qq_mless");     
  histonames.push_back("Mlb");                
  histonames.push_back("Mlbb");               
  histonames.push_back("M3b");               
  histonames.push_back("MTb");                
  histonames.push_back("MTq");                
  histonames.push_back("MTqmax");                
  histonames.push_back("MTq_boost");          
  histonames.push_back("MTq_boostmax");          
  histonames.push_back("MTq_boost200");          
  histonames.push_back("MTq_boost300");          
  histonames.push_back("MTq_boost400");          
  histonames.push_back("MTq_boost450");          
  histonames.push_back("MTq_boost500");          
  histonames.push_back("MTq_boostLeadJet");          
  histonames.push_back("MTq_boostLeadJet300");          
  histonames.push_back("MTq_boostLeadJetgt300");          
  histonames.push_back("MTq_boostLeadJetlt300");
  histonames.push_back("MTq_boostLeadJetgt400");          
  histonames.push_back("MTq_boostLeadJetlt400");         
  histonames.push_back("MTqq");               
  histonames.push_back("Topness");            
  histonames.push_back("MT");                 
  histonames.push_back("MET");                
  histonames.push_back("HT");                 
  histonames.push_back("METoverHT");          
  histonames.push_back("METoverSqrtHT");      
  histonames.push_back("HTratio");            
  histonames.push_back("dRLepBJet");          
  histonames.push_back("dRLepBMax");          
  histonames.push_back("dRLepBMin");          
  histonames.push_back("dRbb");               
  histonames.push_back("chi2");               
  histonames.push_back("NBJets");             
  histonames.push_back("NJets");              
  histonames.push_back("minDPhi");            
  histonames.push_back("minDPhiJ3");          
  histonames.push_back("minDPhiB");           
  histonames.push_back("NBJetsOverNJets");    
  histonames.push_back("pTlb");               
  histonames.push_back("pTlbb");              
  histonames.push_back("pTl");                
  histonames.push_back("pTleadj");            
  histonames.push_back("pTleadb");            
  histonames.push_back("pTtrailb");           
  histonames.push_back("sumak8topmass");      
  histonames.push_back("sumak8prunedmass");   
  histonames.push_back("sumak8trimmedmass");  
  histonames.push_back("sumak8filteredmass"); 
  histonames.push_back("DeltaPhiWl");
  */

  TH1F* null = new TH1F("","",1,0,1);

    for(unsigned int c = 0; c<poststringsize; ++c){
    string prestring = poststring[c];
    for(unsigned int i = 0; i<histonames.size();++i){
      vector<TH1F*> bghist; bghist.clear();
      vector<TH1F*> sighist; sighist.clear();
      string options = "--outputName " + outputdir + histonames[i] + " --xAxisLabel " + histonames[i] + " --energy 13 --lumi 10 --noXaxisUnit --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05";
      //if(prefix!="") options = "--outputName " + outputdir + prestring  + prefix + "/" + histonames[i] + " --xAxisLabel " + histonames[i] + " --energy 13 --lumi 10 --noXaxisUnit --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05";
      // string options = "--outputName " + outputdir + prestring + "/" + histonames[i] + " --xAxisLabel " + prestring + histonames[i] + " --noXaxisUnit --energy 13 --lumi 10 --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05 --legendRight -0.2";//topness
      for(unsigned int n=0; n<bgsetsize; ++n){
	int fileidentifier = n;
	if(n==1) fileidentifier = 0;//TTbar2l
	//if(n==2) fileidentifier = 0;//TTbarH
	fbg[fileidentifier]->cd();
	string name = prestring + histonames[i]+"_"+bgstrings[n];
	//cout << fbg[fileidentifier]->GetName() << " " << name << endl;
	TH1F *h = (TH1F*)fbg[fileidentifier]->Get(name.c_str());
	bghist.push_back(h);
      }
      for(unsigned int n=0; n<sigsetsize; ++n){
	fsig[n]->cd();
	string name = prestring + histonames[i]+"_"+sigstrings[n];
	TH1F *h = (TH1F*)fsig[n]->Get(name.c_str());
	//cout << fsig[n]->GetName() << " " << name << endl;
	if(prestring=="PreMT_") h->Scale(100.);
	else if(prestring=="PostAll_") h->Scale(10.);
	else h->Scale(25.);
	sighist.push_back(h);
      }
      if(prestring=="PreMT_") dataMCplotMaker(null,bghist,bgstrings,"sig x100","",options,sighist,sigstrings,colors);
      else if(prestring=="PostAll_") dataMCplotMaker(null,bghist,bgstrings,"sig x10","",options,sighist,sigstrings,colors);
      else dataMCplotMaker(null,bghist,bgstrings,"sig x10","",options,sighist,sigstrings,colors);
    }
  }

} 
