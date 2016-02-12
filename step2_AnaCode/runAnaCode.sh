#!/bin/bash

root -l << EOF
Char_t name[300];  
sprintf(name,"/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015B-16Oct2015-v1_Nov13_50ns.root");
TFile *file0 = TFile::Open(name)
TTree *tree3 = (TTree*)file0->Get("tree");
.L ZprimeMuMuPat.C+
ZprimeMuMuPat b(name,tree3,1.,"","2015");
b.Loop();

.q
EOF


