#!/bin/bash

START_DIR=`pwd`

MAKER_NAME=CMSSW_7_1_5/src/HiggsAnalysis/CombinedLimit/

#COPYDIR=/hadoop/cms/store/user/haweber/condor/limits/dropsigcont/fakedata/
#COPYDIR=/hadoop/cms/store/user/haweber/condor/limits/fakedata/
COPYDIR=/hadoop/cms/store/user/haweber/condor/significances/
#COPYDIR=/hadoop/cms/store/user/haweber/condor/significances/correlated/

SCRATCH_DIR=/data/tmp/haweber/significances/
#SCRATCH_DIR=/data/tmp/haweber/significances/correlated/

CONDOR_DIR_NAME=HiggsCombine_CMSSW_7_1_5

USER_EMAIL=haweber@fnal.gov

#DATACARD_DIR=../datacards/combined/
#DATACARD_DIR=../datacards2p3fbinv/dropsigcont/fakedata/combinedcards/
#DATACARD_DIR=../datacards2p3fbinv/fakedata/combinedcards/
DATACARD_DIR=../datacards2p3fbinv/combinedcards/
#DATACARD_DIR=../datacards2p3fbinv/correlated/combinedcards/

#
# Input Sanitation
#

if [ -z $START_DIR ]; then
    echo "START_DIR not set, don't know where I am starting from :(, exiting..."
    echo "Please set it in setup.sh! and do source setup.sh"
    return 1;
fi
if [ -z $CMSSW_BASE ]; then
    echo "CMSSW_BASE var not set, run cmsenv, exiting..."
    return 1;
fi
if [ -z $DATACARD_DIR ]; then
    echo "DATACARD_DIR not set, don't know which maker to use :(, exiting..."
    echo "Please set it in setup.sh and do source setup.sh!"
    return 1;
fi
if [ ! -d $DATACARD_DIR ]; then
    echo "$DATACARD_DIR does not exist, :( making it..."
    mkdir -p $DATACARD_DIR
    #echo "Please set it in setup.sh and do source setup.sh!"
    #return 1;
fi
if [ ! -d $COPYDIR ]; then
    echo "$COPYDIR does not exist, :( making it..."
    mkdir -p $COPYDIR
    #echo "Please set it in setup.sh and do source setup.sh!"
    #return 1;
fi
if [ -z $COPYDIR ]; then
    echo "COPYDIR not set, don't know which maker to use :(, exiting..."
    echo "Please set it in setup.sh and do source setup.sh!"
    return 1;
fi
if [ -z $MAKER_NAME ]; then
    echo "MAKER_NAME not set, don't know which maker to use :(, exiting..."
    echo "Please set it in setup.sh and do source setup.sh!"
    return 1;
fi
if [ ! -d $SCRATCH_DIR ]; then
    echo "$SCRATCH_DIR does not exist, :( making it..."
    mkdir -p $SCRATCH_DIR
    mkdir -p $SCRATCH_DIR/logs/
    #echo "Please set it in setup.sh and do source setup.sh!"
    #return 1;
fi
if [ -z $SCRATCH_DIR ]; then
    echo "SCRATCH_DIR not set, don't know which SCRATCH area to use :(, exiting..."
    echo "Please set it in setup.sh and do source setup.sh!"
    return 1;
fi
if [ -z $CONDOR_DIR_NAME ]; then
    echo "CONDOR_DIR_NAME not set, don't know what name to use for your tarball :(, exiting..."
    echo "Please set it in setup.sh! and do source setup.sh"
    return 1;
fi
if [ -z $USER_EMAIL ]; then
    echo "USER_EMAIL not set, don't know where to send email notifications for condor jobs completing :(, exiting..."
    echo "Please set it in setup.sh! and do source setup.sh"
    return 1;
fi

CONDOR_ENV_READY=true
