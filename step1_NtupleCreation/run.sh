#!/bin/bash

cmsRun runMakeMuonTree_HLT50_cfg.py >& runMakeMuonTree_HLT50_cfg.log &
cmsRun runMakeMuonTree_HLT50_mc_cfg.py >& runMakeMuonTree_HLT50_mc_cfg.log &

