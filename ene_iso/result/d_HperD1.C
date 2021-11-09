Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*TMath::Power(x[0],par[1]);
}

void d_HperD1()
{
    TFile *ipf=new TFile("datatree.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    //ipt->Scan("*");
    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();
    ipt->Draw("((EQ1+EQ2)*1e-9/D_p):energy","location==0","goff");
    TGraph *gr=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr->SetMarkerStyle(22);
    gr->SetMarkerSize(1.5);
    gr->Draw("ap");

    TCanvas *c1=new TCanvas("c1","c1");
    c1->cd();
    TF1 *f1=new TF1("myfit",fitFunc,72,300,2);
    f1->SetLineColor(1);
    f1->SetLineWidth(5);
    f1->SetParNames("k1","a1");
    f1->SetParameters(1,-2);
    //Draw with option goff and generate variables
    Double_t x[] = {72,97,122,172,222,272,91.403,113.027,159.268,207.262,256.025,76.217,87.658,123.223,166.385,212.565};
    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/13.400471:location","energy==400","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr1->SetTitle("400 MeV/u");
    gr1->SetMarkerStyle(21);
    gr1->SetMarkerColor(9);
    gr1->SetMarkerSize(1.5);
    //gr1->Fit("myfit","","",69,275);


    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/7.8383858:location","energy==350","goff");
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr2->SetTitle("350 MeV/u");
    gr2->SetMarkerStyle(22);
    gr2->SetMarkerColor(2);
    gr2->SetMarkerSize(1.5);
    //gr2->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/4.1716092:location","energy==300","goff");
    TGraph *gr3=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr3->SetTitle("300 MeV/u");
    gr3->SetMarkerStyle(23);
    gr3->SetMarkerColor(3);
    gr3->SetMarkerSize(1.5);
    //gr3->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/2.0008829:location","energy==250","goff");
    TGraph *gr4=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr4->SetTitle("250 MeV/u");
    gr4->SetMarkerStyle(20);
    gr4->SetMarkerColor(4);
    gr4->SetMarkerSize(1.5);
    //gr4->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/0.8116145:location","energy==200","goff");
    TGraph *gr5=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr5->SetTitle("200 MeV/u");
    gr5->SetMarkerStyle(43);
    gr5->SetMarkerColor(6);
    gr5->SetMarkerSize(1.5);
    //gr5->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/D_p)/0.3656566:location","energy==165","goff");
    TGraph *gr6=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr6->SetTitle("165 MeV/u");
    gr6->SetMarkerStyle(34);
    gr6->SetMarkerColor(7);
    gr6->SetMarkerSize(1.5);  
    //gr6->Fit("myfit","","",70,275);  

    TMultiGraph *mgp=new TMultiGraph();
    mgp->Add(gr1,"p");
    mgp->Add(gr2,"p");
    mgp->Add(gr3,"p");
    mgp->Add(gr4,"p");
    mgp->Add(gr5,"p");
    mgp->Add(gr6,"p");
    mgp->Draw("a");
    gPad->SetLogx();
    gPad->SetLogy();
    mgp->Fit("myfit","","",70,275);
    //mgp->GetYaxis()->SetLimits(0,14);
    mgp->GetXaxis()->SetLimits(50,1000);
    mgp->GetYaxis()->SetRangeUser(0.05,1.2);
    //mgp->GetXaxis()->SetRangeUser(10,1000);
    mgp->GetXaxis()->SetTitle("d (cm)");
    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("(H/D)_{d}/^{}(H/D)_{d_{iso}}");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.6,0.5,0.8,0.8);
    leg->AddEntry(gr1,"400 MeV/u","p");
    leg->AddEntry(gr2,"350 MeV/u","p");
    leg->AddEntry(gr3,"300 MeV/u","p");
    leg->AddEntry(gr4,"250 MeV/u","p");
    leg->AddEntry(gr5,"200 MeV/u","p");
    leg->AddEntry(gr6,"165 MeV/u","p");
    leg->AddEntry(f1,"Power law fit","l");
    leg->SetTextSize(0.04);
    leg->Draw();
    gStyle->SetOptFit(0000);
    gPad->Modified();
    gPad->Update();
   // gPad->BuildLegend();

    

}