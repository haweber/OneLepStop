Main code to create histograms is
ExampleLooper.C
which is run via
root -l -b -q runMacro.C

(root environment should be set up using cmsenv)

For reference only a ExampleLooper.py script has been written.
This code is extremely slow and not recommended - also I did not check it for bugs beyond segfaults.

Out of these histograms one can make plots using either MakePlots.C or MakePlots.py (whatever is preferred - here speed is not that critical.
I prefer the .C file as I can run in batch mode without graphics (which is much faster, and I simply don't know how to do that for python).
