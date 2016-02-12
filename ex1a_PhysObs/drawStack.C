#include "ZZStyle.C"

void drawStack(bool useDataBkg = false) {
	TString histDir = "/wk3/cmsdas/store/user/cmsdas/2016/LONG_EXERCISES/ZprimeDiLeptons/histosZprimeMuMu_combined/" ;
	TString fileName[44];
	TFile* file[44];
	TH1F* h1[44];
	
	fileName[0]  = "output_SingleMuon_Run2015B-16Oct2015-v1_Nov13_50ns.root" ;
	fileName[1]  = "output_SingleMuon_Run2015C-PromptReco-v1_Nov13_50ns.root" ;
	fileName[2]  = "output_SingleMuon_Run2015C-25ns-05Oct2015-v1_MuonPhys_Nov13_25ns.root" ;
	fileName[3]  = "output_SingleMuon_Run2015D-PromptReco-v3_MuonPhys_Nov13_25ns.root" ;
	fileName[4]  = "output_SingleMuon_Run2015D-PromptReco-v4_MuonPhys_Nov13_25ns.root" ;

	fileName[5]  = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_120_200.root" ;
	fileName[6]  = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_1400_2300.root" ;
	fileName[7]  = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_200_400.root" ;
	fileName[8]  = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_2300_3500.root" ;
	fileName[9]  = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_3500_4500.root" ;
	fileName[10] = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_400_800.root" ;
	fileName[11] = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_4500_6000.root" ;
	fileName[12] = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_50_120.root" ;
	fileName[13] = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_6000_Inf.root" ;
	fileName[14] = "output_ZToMuMu_NNPDF30_13TeV-powheg_M_800_1400.root" ;
	fileName[15] = "output_DYJetsToTauTau_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root" ;

	fileName[16] = "output_WW_TuneCUETP8M1_13TeV-pythia8.root" ; 
	fileName[17] = "output_WZ_TuneCUETP8M1_13TeV-pythia8.root" ; 
	fileName[18] = "output_ZZ_TuneCUETP8M1_13TeV-pythia8.root" ; 

	fileName[19] = "output_TT_TuneCUETP8M1_13TeV-powheg-pythia8.root" ;                                   
	fileName[20] = "output_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root" ; 
	fileName[21] = "output_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root" ;     
	fileName[22] = "output_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root" ;     
	fileName[23] = "output_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root" ;         
	fileName[24] = "output_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1.root" ;       

	fileName[25] = "output_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root" ; 

	fileName[26] = "output_QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[27] = "output_QCD_Pt_10to15_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[28] = "output_QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[29] = "output_QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[30] = "output_QCD_Pt_15to30_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[31] = "output_QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[32] = "output_QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[33] = "output_QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[34] = "output_QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[35] = "output_QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[36] = "output_QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[37] = "output_QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[38] = "output_QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[39] = "output_QCD_Pt_5to10_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[40] = "output_QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[41] = "output_QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8.root" ;
	fileName[42] = "output_QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8.root" ;

	fileName[43] = "output_ZprimeToMuMu_M-5000_TuneCUETP8M1_13TeV-pythia8.root" ;

	TString histName = "ZprimeRecomass";
	int Rebin = 20;
	for(int i=0; i<44; i++) {
		file[i] = TFile::Open(histDir + fileName[i]);
		h1[i] = (TH1F*)file[i]->Get(histName);
		h1[i]->Rebin(Rebin);
	}

	//DiJet by FR fomr Data
	int nRebin = Rebin;
	TH1 *hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new=NULL;
	TFile *fDiJets = TFile::Open("plots/FR-estimate-DiJets-Data-OS-1GeVBin-2800.root");
	TH1F *hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData = (TH1F*)fDiJets->Get("DataSub");
	hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData->SetBins(10000,0.,10000.);
	hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new=hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData->Rebin(nRebin,"hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData");
	hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new->SetLineColor(kYellow);
	hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new->SetFillColor(kYellow);
	hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new->SetMarkerStyle(24);
	//Wjets by FR from MC
	TH1 *hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new=NULL;
	TFile *fWJets = TFile::Open("plots/FR-estimate-Dijets-Wjets-MC-OS-1GeVBin-2800pb.root");
	TH1F *hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC = (TH1F*)fWJets->Get("WjetsHisto");
	hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC->SetBins(10000,0.,10000.);
	hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new=hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC->Rebin(nRebin,"hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC");
	hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new->SetLineColor(kYellow+2);
	hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new->SetFillColor(kYellow+2);
	hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new->SetMarkerStyle(24);


	TH1F* h1_data = (TH1F*)(h1[0]->Clone());
	for(int i=1; i<5; i++) { h1_data->Add(h1[i]); }

	TH1F* h1_z2mm = (TH1F*)(h1[5]->Clone());
	for(int i=6; i<16; i++) { h1_z2mm->Add(h1[i]); }

	TH1F* h1_dibo = (TH1F*)(h1[16]->Clone());
	for(int i=17; i<19; i++) { h1_dibo->Add(h1[i]); }

	TH1F* h1_tops = (TH1F*)(h1[19]->Clone());
	for(int i=20; i<25; i++) { h1_tops->Add(h1[i]); }

	TH1F* h1_wjetMC = (TH1F*)(h1[25]->Clone());
	TH1F* h1_mjetMC = (TH1F*)(h1[26]->Clone());
	for(int i=27; i<43; i++) { h1_mjetMC->Add(h1[i]); }

	TH1F* h1_wjetData = (TH1F*)(hfourlepbestmass_4l_afterSel_WJetsFromFakeRateFromMC_new_new->Clone());
	TH1F* h1_mjetData = (TH1F*)(hfourlepbestmass_4l_afterSel_DiJetsFromFakeRateFromData_new_new->Clone());

	TH1F* h1_zpri   = (TH1F*)(h1[43]->Clone());


	
	TH1F* h1_wjet = (useDataBkg) ? (TH1F*) h1_wjetData->Clone() : (TH1F*)h1_wjetMC;
	TH1F* h1_mjet = (useDataBkg) ? (TH1F*) h1_mjetData->Clone() : (TH1F*)h1_mjetMC;

	TH1F* htotaldata = (TH1F*)h1_data->Clone();
	const int arraysize = 500; 
	Float_t x[arraysize],y[arraysize],exl[arraysize],exh[arraysize],eyl[arraysize],eyh[arraysize];
	float totaldataentries=0.,totaldataentries100=0.;
	for (int nbins=1;nbins<=htotaldata->GetNbinsX(); nbins++){
   	x[nbins-1]=htotaldata->GetBinCenter(nbins);
   	y[nbins-1]=htotaldata->GetBinContent(nbins);
   	exl[nbins-1]=0.;
   	exh[nbins-1]=0.;
    	totaldataentries=totaldataentries+htotaldata->GetBinContent(nbins);
    	if(htotaldata->GetBinCenter(nbins)>100. && htotaldata->GetBinCenter(nbins)<800.) totaldataentries100=totaldataentries100+htotaldata->GetBinContent(nbins);
		if(htotaldata->GetBinContent(nbins)>0){
			eyh[nbins-1]=+0.5 + sqrt(htotaldata->GetBinContent(nbins)+0.25);
			eyl[nbins-1]=-0.5 + sqrt(htotaldata->GetBinContent(nbins)+0.25);
		} else {
           x[nbins-1] = 0.;
         eyl[nbins-1] = 0.;
         eyh[nbins-1] = 0.;
		}
	}
	int Nbins = (int)htotaldata->GetNbinsX();
	TGraphAsymmErrors *gr = new TGraphAsymmErrors(Nbins,x,y,exl,exh,eyl,eyh);
	gr->SetMarkerColor(1);
	gr->SetMarkerStyle(20);
	gr->SetMarkerSize(0.95);



	TH1F* h1_tBkg = (TH1F*)h1_z2mm->Clone();
			h1_tBkg->Add(h1_dibo);
			h1_tBkg->Add(h1_tops);
			h1_tBkg->Add(h1_wjet);
			h1_tBkg->Add(h1_mjet);

	TH1F* h1_ratio = (TH1F*)h1_data->Clone();
	h1_ratio->Divide(h1_tBkg);

	h1_mjet->SetFillColor(kYellow)  ;	h1_mjet->SetLineColor(kYellow)  ;
	h1_wjet->SetFillColor(kSpring)  ;	h1_wjet->SetLineColor(kSpring)  ;
	h1_tops->SetFillColor(kRed)     ;	h1_tops->SetLineColor(kRed)     ;
	h1_dibo->SetFillColor(kGreen+2) ;	h1_dibo->SetLineColor(kGreen+2) ;
	h1_z2mm->SetFillColor(kAzure-9) ;	h1_z2mm->SetLineColor(kAzure-9) ;


	THStack* h1_sBkg = new THStack();
		h1_sBkg->Add(h1_mjet);
		h1_sBkg->Add(h1_wjet);
		h1_sBkg->Add(h1_tops);
		h1_sBkg->Add(h1_dibo);
		h1_sBkg->Add(h1_z2mm);


	TH2F* hframe1 = new TH2F("hframe1","hframe1",80,60.,3000.,500,0.005,50000.);
   TH2F* hframe2 = new TH2F("hframe2","hframe2",80,60.,3000.,1000, -1.5, 3.5);

	TStyle * style = getStyle("ZZ");
	style->cd();
	style->SetNdivisions(508, "X");
	style->SetNdivisions(508, "Y");
	style->SetMarkerSize(0.8);


  	TCanvas *c1 = new TCanvas("c1","c1",800,800);
	c1->cd();
	c1->SetTicks(1,1);

	c1->SetLogy();
	hframe1->Draw("");
	h1_tBkg->SetLineColor(2);
	h1_tBkg->SetLineWidth(2);
	//h1_data->Draw("ep same");
	//h1_tBkg->Draw("same HIST");
	h1_sBkg->Draw("hist same");
	gr->Draw("EPsame");

	h1_zpri->Scale(100);
	h1_zpri->SetLineWidth(3);
	h1_zpri->SetLineColor(6) ;
	h1_zpri->Draw("hist same");
	
	gPad->RedrawAxis();

	TLegend* legend = new TLegend( 0.6, 0.74, 0.9, 0.92);
	legend->SetFillColor(kWhite);
	legend->SetTextSize(0.020);
	legend->AddEntry(gr,"Data", "P");
	if(useDataBkg) {
		legend->AddEntry(h1_mjet,"di-jets (FR from data)", "F"); 
		legend->AddEntry(h1_wjet,"W-Jets (FR from MC)", "F");
	} else {
		legend->AddEntry(h1_mjet,"di-jets", "F"); 
		legend->AddEntry(h1_wjet,"W-Jets", "F");
	}
	legend->AddEntry(h1_tops,"t#bar{t}, tW, #bar{t}W", "F");
	legend->AddEntry(h1_dibo,"di-boson",               "F");
	legend->AddEntry(h1_z2mm,"#gamma^{*}/Z #rightarrow #mu^{+}#mu^{-}", "F");
	legend->AddEntry(h1_zpri,"Z'(5 TeV) #rightarrow #mu^{+}#mu^{-} #times 100", "l");
	legend->Draw("same");

	//  c1->Update();
	double canvasratio = 0.3;
	c1->SetBottomMargin(canvasratio + (1-canvasratio)*c1->GetBottomMargin()-canvasratio*c1->GetTopMargin());
	// Ratio: data / total bkg 
	canvasratio = 0.16;
	TPad *ratioPad = new TPad("BottomPad","",0,0,1,1);
	ratioPad->SetTopMargin((1-canvasratio) - (1-canvasratio)*ratioPad->GetBottomMargin()+canvasratio*ratioPad->GetTopMargin());
	ratioPad->SetFillStyle(4000);
	ratioPad->SetFillColor(4000);
	ratioPad->SetFrameFillColor(4000);
	ratioPad->SetFrameFillStyle(4000);
	ratioPad->SetFrameBorderMode(0);
	ratioPad->SetTicks(1,1);
	ratioPad->SetGrid(1,1);
	ratioPad->Draw();
	ratioPad->cd();
	
	hframe2->GetYaxis()->SetLabelSize(0.010);
	hframe2->GetXaxis()->SetLabelSize(0.010);
	hframe2->GetYaxis()->SetTitleSize(0.03);
	hframe2->GetXaxis()->SetTitleSize(0.03);
	hframe2->SetYTitle("Data/MC");
	hframe2->GetYaxis()->SetNdivisions(503);
	hframe2->Draw("");

	h1_ratio->SetMarkerStyle(20);
	h1_ratio->SetMarkerSize(0.95);
	h1_ratio->SetMarkerColor(kBlack);
	h1_ratio->Draw("Psame");
	c1->Update();


	TPaveText *ll = new TPaveText(0.15, 0.95, 0.95, 0.99, "NDC");
	ll->SetTextSize(0.027);
	ll->SetTextFont(42);
	ll->SetFillColor(0);
	ll->SetBorderSize(0);
	ll->SetMargin(0.01);
	ll->SetTextAlign(12); // align left
	TString text = "CMS Preliminary";
	ll->AddText(0.01,0.5,text);
	text = "#sqrt{s} = 13 TeV, L = 2.8 fb^{-1}" ;
	ll->AddText(0.65, 0.6, text);
	ll->Draw("same");

	if(useDataBkg) {
		c1->Print("drawStack_QCDfromData.pdf");
	} else {
		c1->Print("drawStack.pdf");
	}


}
