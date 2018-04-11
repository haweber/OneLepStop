g++ -shared -c -fPIC dorkypy.cc -o dorkypy.o
g++ -shared -c -fPIC goodrunpy.cc -o goodrunpy.o
g++ -shared -c -fPIC testf.C -o testf.o
g++ -shared -c -fPIC CMS3py.cc `root-config --libs --cflags`  -o CMS3py.o
g++ -shared -Wl,-soname,library.so -o library.so goodrunpy.o dorkypy.o testf.o CMS3py.o


In py code, this should work:
import ctypes
ctypes.CDLL('Tools/library.so').set_goodrun_file_json(json_file)
