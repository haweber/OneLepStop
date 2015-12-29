NOTE: CODE SHOULD BE READY BUT HAS NOT TESTED YET (so bugs might be there)

#Condor submission for combine limit setting

Instructions:
  1.  modify setup.sh appropriately: MAKER_NAME, CONDOR_DIR_NAME should not be changed...
  2.  run '. setup.sh'
  3.  modify '. batch.sh':
       a) Name is 'T2tt, T2bW, T2tb'
       b) I think you can keep MSTOP, etc. - need to see if these options are needed
	   c) postfit is 'true, false'
	   d) xsecupdown is '0, 1, -1'
	   e) SR is '1, 2' (or more precise - compressed SR is 2, everything else is main SR'
  4.  run '. batch.sh'
  5.  Wait until rootfiles arrive

To be done:
  1. Implement checks if things were submitted and/or are finished.
  2. Improve code for all possible cases.
