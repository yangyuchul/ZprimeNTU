#!/bin/bash

root -l << EOF
.L TagProbeMuonYC.C+
TagProbeMuon m;
m.Loop();
.q
EOF


#inChain->Add("../../../eos/uscms/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015C-PromptReco-v1_MuonPhys_Nov13_25ns.root    ");

#inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015C-25ns-05Oct2015-v1_MuonPhys_Nov13_25ns.root");
#inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015C-PromptReco-v1_Nov13_50ns.root"             );
#inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015D-PromptReco-v3_MuonPhys_Nov13_25ns.root"    );
#inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015D-PromptReco-v4_MuonPhys_Nov13_25ns.root"    );

root -l << EOF
.L TagProbeMuonYC.C+
TChain* inChain = new TChain("tree");
inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015B-16Oct2015-v1_Nov13_50ns.root"              );
//inChain->Add("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015C-25ns-05Oct2015-v1_MuonPhys_Nov13_25ns.root");
TagProbeMuon m(inChain);
m.Loop("Analyse_TagandProbe_Data_DY_60_Mass_120_HighPtMuon_ID_pt45.root");
.q
EOF


