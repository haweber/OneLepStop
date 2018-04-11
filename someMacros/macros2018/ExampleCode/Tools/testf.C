#include <iostream>

using namespace std;

extern "C" void stupid(bool x){
  if(x) cout << "Hello World!" << endl;
  else cout << "Bye World!" << endl;
  return;
}
