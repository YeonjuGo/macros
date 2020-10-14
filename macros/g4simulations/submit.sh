#!/bin/bash

INPUTDIRNUM=$1
JETDR=$2
SEQ=$3
retDir=$PWD
cFile=testCondor_yj.job

DATE=`date +%Y%m%d`
TIME=`date +%H%M%S`
cDir=/gpfs/mnt/gpfs02/sphenix/user/yeonjugo/PFJetReco/condorDir_HCALTOPO_ECALTOPO_corrected/condor_inputDir"$INPUTDIRNUM"_dR"$JETDR"_seq"$SEQ"
echo $cDir
#cDir=condorDir/condor_"$DATE"_"$TIME"
mkdir -p $cDir

cFile2=${cFile%.job}
cFile2="$cFile2"_"$INPUTDIRNUM"_"$JETDR"_seq"$SEQ".job
cp $cFile $cFile2

sed -i -e "s@INITDIR@$retDir@g" $cFile2

echo "Arguments       = \$(Process) $INPUTDIRNUM $JETDR $SEQ $cDir" >> $cFile2
echo "Output        = $cDir/condor_\$(Process).out" >> $cFile2
echo "Error         = $cDir/condor_\$(Process).err" >> $cFile2
echo "Log           = $cDir/condor_\$(Process).log" >> $cFile2
echo "Queue 1" >> $cFile2

cp $cFile2 $cDir
cp scriptForCondor.sh $cDir

condor_submit $cFile2
rm $cFile2
