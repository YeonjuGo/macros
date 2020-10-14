#!/bin/bash

INPUTDIRNUM=$1
JETDR=$2
SEQ=$3
retDir=$PWD
cFile=testCondor_yj.job

DATE=`date +%Y%m%d`
TIME=`date +%H%M%S`
#cDir=./../../../../../SE/condorDir/condor_inputDir"$INPUTDIRNUM"_dR"$JETDR"_seq"$SEQ"
cDir=/gpfs/mnt/gpfs02/sphenix/user/yeonjugo/PFJetReco/condorDir/condor_inputDir"$INPUTDIRNUM"_dR"$JETDR"_seq"$SEQ"
echo $cDir
#cDir=condorDir/condor_inputDir"$INPUTDIRNUM"_dR"$JETDR"_seq"$SEQ"
#cDir=condorDir/condor_"$DATE"_"$TIME"
mkdir -p $cDir

cFile2=${cFile%.job}
cFile2="$cFile2"_"$INPUTDIRNUM"_"$JETDR"_seq"$SEQ".job
#cFile2="$cFile2"_"$DATE"_"$TIME".job
cp $cFile $cFile2

sed -i -e "s@INITDIR@$cDir@g" $cFile2
#sed -i -e "s@INITDIR@$PWD/$cDir@g" $cFile2

#submitFile=condorScript/scriptForCondor_inputDir"$INPUTDIRNUM"_dR"$JETDR"_seq"$SEQ".sh
#cp $submitFile $retDir/scriptForCondor.sh 

files=(DisplayOn.C Fun4All_G4_EICDetector.C Fun4All_G4_fsPHENIX.C Fun4All_G4_sPHENIX.C G4_EPD.C G4_MvtxService.C G4Setup_EICDetector.C G4Setup_fsPHENIX.C G4Setup_sPHENIX.C G4_Aerogel.C G4_Bbc.C G4_BlackHole.C G4_CEmc_EIC.C G4_CEmc_Spacal.C G4_CaloTrigger.C G4_DIRC.C G4_DSTReader.C G4_DSTReader_EICDetector.C G4_DSTReader_fsPHENIX.C G4_EEMC.C G4_FEMC.C G4_FEMC_EIC.C G4_FGEM_fsPHENIX.C G4_FHCAL.C G4_FwdJets.C G4_GEM_EIC.C G4_Global.C G4_HIJetReco.C G4_HcalIn_ref.C G4_HcalOut_ref.C G4_Input.C G4_Input_Gun.C G4_Input_Simple.C G4_Intt.C G4_Jets.C G4_Magnet.C G4_Mvtx.C G4_Mvtx_EIC.C G4_PSTOF.C G4_ParticleFlow.C G4_Pipe.C G4_Pipe_EIC.C G4_Piston.C G4_PlugDoor.C G4_PlugDoor_EIC.C G4_PlugDoor_fsPHENIX.C G4_RICH.C G4_Svtx_maps_ladders+intt_ladders+tpc_KalmanPatRec_EIC.C G4_TPC.C G4_TPC_EIC.C G4_TopoClusterReco.C G4_Tracking.C G4_Tracking_EIC.C G4_Tracking_fsPHENIX.C G4_User.C G4_World.C GlobalVariables.C Makefile.am configure.ac ReadClustersRunTracking.C TreeMaker.C TreeMaker.h TreeMakerLinkDef.h autogen.sh flowAfterburner.xml init_gui_vis.mac phpythia6.cfg phpythia8.cfg sartre.cfg vis.mac)

inputStr=""
for i in ${files[@]}
do
    cp $i $cDir
    inputStr="$inputStr $i"
done

echo $inputStr

cd $cDir
tar -czvf inTar.tar.gz $inputStr
rm -f *.C
rm -f *.h
rm -f *.txt
rm -f *.cfg
rm -f *.config
rm -f *.am
rm -f *.ac
rm -f *.mac
rm -f *.xml
rm -f autogen.sh
cd $retDir

echo "Arguments       = \$(Process) $INPUTDIRNUM $JETDR $SEQ" >> $cFile2
echo "transfer_input_files = inTar.tar.gz,scriptForCondor.sh" >> $cFile2
echo "Queue 1" >> $cFile2

mv $cFile2 $cDir
cp scriptForCondor.sh $cDir

cd $cDir 
condor_submit $cFile2
