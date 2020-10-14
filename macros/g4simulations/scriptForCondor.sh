#!/usr/bin/bash

#id=0
#if [[ $# -eq 1 ]]
#then
#    id=$1
#fi

id=$1
INPUTDIRNUM=$2
JETDR=$3
SEQ=$4

QCDE=10
JETEI=20
JETEF=22p5

if [[ INPUTDIRNUM -eq 0 || INPUTDIRNUM -eq 1 || INPUTDIRNUM -eq 2 || INPUTDIRNUM -eq 3 ]]
then
    QCDE=10
elif [[ INPUTDIRNUM -eq 4 || INPUTDIRNUM -eq 5 || INPUTDIRNUM -eq 6 || INPUTDIRNUM -eq 7 ]]
then
    QCDE=15
elif [[ INPUTDIRNUM -eq 8 || INPUTDIRNUM -eq 9 || INPUTDIRNUM -eq 10 || INPUTDIRNUM -eq 11 ]]
then
    QCDE=25
elif [[ INPUTDIRNUM -eq 12 || INPUTDIRNUM -eq 13 || INPUTDIRNUM -eq 14 || INPUTDIRNUM -eq 15 ]]
then
    QCDE=35
elif [[ INPUTDIRNUM -eq 16 || INPUTDIRNUM -eq 17 || INPUTDIRNUM -eq 18 || INPUTDIRNUM -eq 19 ]]
then
    QCDE=45
elif [[ INPUTDIRNUM -eq 22 || INPUTDIRNUM -eq 23 ]]
then
    QCDE=7
else
    echo "wrong input directoryERROR"
fi

if [[ INPUTDIRNUM -eq 0 ]]
then
    JETEI=20
    JETEF=22p5
elif [[ INPUTDIRNUM -eq 1 ]]
then
    JETEI=22p5
    JETEF=25
elif [[ INPUTDIRNUM -eq 2 ]]
then
    JETEI=25
    JETEF=27p5
elif [[ INPUTDIRNUM -eq 3 ]]
then
    JETEI=27p5
    JETEF=30
elif [[ INPUTDIRNUM -eq 4 ]]
then
    JETEI=30
    JETEF=32p5
elif [[ INPUTDIRNUM -eq 5 ]]
then
    JETEI=32p5
    JETEF=35
elif [[ INPUTDIRNUM -eq 6 ]]
then
    JETEI=35
    JETEF=37p5
elif [[ INPUTDIRNUM -eq 7 ]]
then
    JETEI=37p5
    JETEF=40
elif [[ INPUTDIRNUM -eq 8 ]]
then
    JETEI=40
    JETEF=42p5
elif [[ INPUTDIRNUM -eq 9 ]]
then
    JETEI=42p5
    JETEF=45
elif [[ INPUTDIRNUM -eq 10 ]]
then
    JETEI=45
    JETEF=47p5
elif [[ INPUTDIRNUM -eq 11 ]]
then
    JETEI=47p5
    JETEF=50
elif [[ INPUTDIRNUM -eq 12 ]]
then
    JETEI=50
    JETEF=52p5
elif [[ INPUTDIRNUM -eq 13 ]]
then
    JETEI=52p5
    JETEF=55
elif [[ INPUTDIRNUM -eq 14 ]]
then
    JETEI=55
    JETEF=57p5
elif [[ INPUTDIRNUM -eq 15 ]]
then
    JETEI=57p5
    JETEF=60
elif [[ INPUTDIRNUM -eq 16 ]]
then
    JETEI=60
    JETEF=62p5
elif [[ INPUTDIRNUM -eq 17 ]]
then
    JETEI=62p5
    JETEF=65
elif [[ INPUTDIRNUM -eq 18 ]]
then
    JETEI=65
    JETEF=67p5
elif [[ INPUTDIRNUM -eq 19 ]]
then
    JETEI=67p5
    JETEF=70
elif [[ INPUTDIRNUM -eq 22 ]]
then
    JETEI=15
    JETEF=17p5
elif [[ INPUTDIRNUM -eq 23 ]]
then
    JETEI=17p5
    JETEF=20
else
    echo "wrong input directory ERROR"
fi

source /opt/sphenix/core/bin/sphenix_setup.sh -n
export SPHENIX=/sphenix/u/yeonjugo/Projects/sPHENIX_2ndfromDennis/
if [[ $SPHENIX == "/sphenix/u/yeonjugo/Projects/sPHENIX_2ndfromDennis/" ]]
then
    dummy=0
else
    echo "YOU NEED TO EDIT scriptForCondor.sh path SPHENIX - currently set xsto YOURPATHHERE"
    echo $SPHENIX 

    return
    exit 1
fi

export MYINSTALL="$SPHENIX"/install

source /opt/sphenix/core/bin/setup_local.sh $MYINSTALL
tar -xzvf inTar.tar.gz

source autogen.sh --prefix=$MYINSTALL
make 
make install

root -l -b -q "Fun4All_G4_sPHENIX.C(10,\"/sphenix/user/dvp/gen/newQCD/$INPUTDIRNUM/hepmc_QCD${QCDE}GeV_R0${JETDR}jet${JETEI}GeV_${JETEF}GeV_eta0p45_seq00$SEQ.dat\",\"hepmc_QCD${QCDE}GeV_R0${JETDR}jet${JETEI}GeV_${JETEF}GeV_eta0p45_seq00${SEQ}_Job$id.root\")" >& log_hepmc_QCD${QCDE}GeV_R0${JETDR}jet${JETEI}GeV_${JETEF}GeV_eta0p45_seq00${j}_$id.log 

echo "JOB COMPLETE!"
