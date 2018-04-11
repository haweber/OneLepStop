
#ifndef GOODRUN_H
#define GOODRUN_H

extern "C" bool goodrun (unsigned int run, unsigned int lumi_block);
extern "C" bool goodrun_json (unsigned int run, unsigned int lumi_block);
extern "C" void set_goodrun_file (const char* filename);
extern "C" void set_goodrun_file_json (const char* filename);
extern "C" int  min_run ();
extern "C" int  max_run ();
extern "C" int  min_run_min_lumi ();
extern "C" int  max_run_max_lumi ();

#endif

