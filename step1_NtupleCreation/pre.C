void pre() {

   TFile* file0 = TFile::Open("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/Data2015_ZprimeMuMu_13TeV_merged/SingleMuon_Run2015B-16Oct2015-v1_Nov13_50ns.root");
   TTree* tree = (TTree*)file0->Get("tree");
   cout << "Number of Events in tree " << (int)tree->GetEntries() << endl;

   TCanvas* c0 = new TCanvas();
   TH1F* h1_Mu_nbMuon = new TH1F("h1_Mu_nbMuon","h1_Mu_nbMuon",10,0,10);
   tree->Draw("Mu_nbMuon >> h1_Mu_nbMuon");
   delete c0;

   TCanvas* c1 = new TCanvas();
   c1->Divide(1,2);
   c1->cd(1);
   c1->GetPad(1)->SetLogy();
   h1_Mu_nbMuon->Draw();
   c1->cd(2);
   c1->GetPad(2)->SetLogy();
   tree->Draw("Mu_ptTunePMuonBestTrack");
	c1->Print("pre.pdf");
}
