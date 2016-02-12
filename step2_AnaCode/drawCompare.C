void drawCompare() {

	TFile* file1 = TFile::Open("CMSSW745-Analyse_ZprimeToMuMu_13TeV.root");
	TFile* file2 = TFile::Open("/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/histosZprimeMuMu_combined/output_SingleMuon_Run2015B-16Oct2015-v1_Nov13_50ns.root");

	TString name("ZprimeRecomass");
	TH1F* h1 = (TH1F*)file1->Get(name);
	TH1F* h2 = (TH1F*)file2->Get(name);

	h1->SetTitle(file1->GetName());
	h2->SetTitle(file2->GetName());

	h1->GetXaxis()->SetRangeUser(0,1000);
	h2->GetXaxis()->SetRangeUser(0,1000);

	TCanvas* c1 = new TCanvas();
	c1->Divide(1,2);
	c1->cd(1); c1->GetPad(1)->SetLogy();
	h1->Draw();
	c1->cd(2); c1->GetPad(2)->SetLogy();
	h2->Draw();
	c1->Print("drawCompare.pdf");

}
