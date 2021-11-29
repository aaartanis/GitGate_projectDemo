void show()
{
    TFile *ipf=new TFile("./400-8-202110291423/braggpeak_water-Dose.root");
    TH1D *h=(TH1D*)ipf->Get("histo");
    h->GetXaxis()->SetTitle("Depth (mm)");
    h->GetYaxis()->SetTitle("Dose (Gy)");
    h->Draw("hist");
}