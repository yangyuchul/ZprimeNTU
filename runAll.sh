#!/bin/bash


echo "### Step1: The ntuple creation "
cd step1_NtupleCreation
cmsRun runMakeMuonTree_HLT50_cfg.py   
echo "cmsRun runMakeMuonTree_HLT50_cfg.py To backgroud job"
cmsRun runMakeMuonTree_HLT50_mc_cfg.py 
echo "cmsRun runMakeMuonTree_HLT50_mc_cfg.py To background job"
root -b -l -q pre.C
ls -al $PWD/pre.pdf

cd -
echo ""


echo "### Step2: The analysis code (Ntuple to Histogram)"
cd step2_AnaCode
echo "Wait a few minutes! To make histograms"
./runAnaCode.sh >& runAnaCode.log
ls -al CMSSW745-Analyse_ZprimeToMuMu_13TeV.root
root -b -q -l drawCompare.C 
ls -al  drawCompare.pdf
cd -
echo ""


echo "### Exercise1: Physics Observables "
cd ex1a_PhysObs
root -l -b -q drawStack.C
ls -al drawStack.pdf
cd -
echo ""


echo "### Exercise1b: Mass Resolution"
cd ex1b_MassRes
if [ ! -d histosZprimeMuMu_combined ] && [ -f histosZprimeMuMu_combined.tgz ]; then tar zxvf histosZprimeMuMu_combined.tgz; fi
source sourceroot.sh # using root version 5
root -l -b -q 
ls MC-Zprime5000-CMSSW745-MassResolution-fit.png  
ls MC-Zprime5000-CMSSW745-MassResolutionPull-fit.png
eval `scramv1 runtime -sh` ### it is cmsenv command # to back version 6 root in CMSSW_7_4_5
cd -
echo ""


echo "### Exercise2: Invariant mass plot"
cd ex1a_PhysObs
root -l -b -q drawStack.C'(true)'
ls -al drawStack_QCDfromData.pdf
cd -
echo ""


echo "### Exercise2b: Event display : skip!!!"
echo ""

echo "### Exercise3: Efficienty Tag and Probe "
cd ex3_TagProbe
echo "Wait a few minutes! To make histograms"
./runTagProbe.sh >& runTagProbe.log
ls -al Analyse_TagandProbe_Data_DY_60_Mass_120_HighPtMuon_ID_pt45.root  Analyse_TagandProbe_MC_DY_60_Mass_120_HighPtMuon_ID_pt45.root

source sourceroot.sh
root -l -b -q TagProbeMuonPlots.C
ls -al  Eff_TagProbe_ID_MC_13TeV_PtProbe_cmssw720.pdf 
ls -al  Eff_TagProbe_ID_MC_13TeV_vtxProbe_cmssw720.pdf
ls -al  Eff_TagProbe_ID_MC_13TeV_EtaProbe_cmssw720.pdf

root -l -b -q TagProbeMuonPlotsTrackIso.C 
ls -al Eff_TagProbe_ID_MC_13TeV_PtProbe_cmssw720-trackiso.pdf 
ls -al Eff_TagProbe_ID_MC_13TeV_vtxProbe_cmssw720-trackiso.pdf
ls -al Eff_TagProbe_ID_MC_13TeV_EtaProbe_cmssw720-trackiso.pdf
eval `scramv1 runtime -sh` ### it is cmsenv command # to back version 6 root in CMSSW_7_4_5
cd -
echo ""


echo "### Exercise4: Background estimation and Fake Rate"
cd ex4_fakeRate
root -l -b -q  plotFR_QCD.C
root -l -b -q  plotFraction_EWK.C
root -l -b -q  plotFR_data.C
ls -al *.pdf
cd -
echo ""

echo "### Exercise5: Significance"
cd ex5_significance
root -l -b -q sig.C
ls -al *.pdf
cd -
echo ""


 
echo "###########"

find step1_NtupleCreation step2_AnaCode ex1a_PhysObs ex1b_MassRes ex3_TagProbe ex4_fakeRate ex5_significance -name "*.pdf"
find step1_NtupleCreation step2_AnaCode ex1a_PhysObs ex1b_MassRes ex3_TagProbe ex4_fakeRate ex5_significance -name "*.png"
echo "#Done"

