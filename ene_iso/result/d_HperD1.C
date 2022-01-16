Double_t fitFunc(Double_t *x,Double_t *par){
    return TMath::Power(x[0]/par[0],par[1]);
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
    f1->SetLineWidth(3);
    f1->SetParNames("d_iso","a");
    f1->SetParameters(72,-2);
    //Draw with option goff and generate variables
    Double_t d_iso=72.34;
    Double_t x[16];
    Double_t r[5]={25,50,100,150,200};
    //Double_t theta[3]={0,45,90};
    Double_t pi=TMath::Pi();
    Double_t rad[3]={0,pi/4,pi/2};
    x[0]=d_iso;
    Int_t temp=1;
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<5;j++)
        {
            x[temp]=TMath::Sqrt(TMath::Sq(d_iso+r[j]*TMath::Cos(rad[i]))+TMath::Sq(r[j]*TMath::Sin(rad[i])));
            //cout<<x[temp]<<endl;
            temp++;
        }
    }
    //location<=5
    //(location==0 ||( location>=6 && location<=10))
    //Double_t x[] = {72,97,122,172,222,272,91.403,113.027,159.268,207.262,256.025,76.217,87.658,123.223,166.385,212.565};
    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/79.870180:location","energy==400 && (location==0 ||( location>=11 && location<=15))","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr1->SetTitle("400 MeV/u");
    gr1->SetMarkerStyle(21);
    gr1->SetMarkerColor(9);
    gr1->SetMarkerSize(1.5);
    //gr1->Fit("myfit","","",69,275);


    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/47.038287:location","energy==350 && (location==0 ||( location>=11 && location<=15))","goff");
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr2->SetTitle("350 MeV/u");
    gr2->SetMarkerStyle(22);
    gr2->SetMarkerColor(2);
    gr2->SetMarkerSize(1.5);
    //gr2->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/24.625802:location","energy==300 && (location==0 ||( location>=11 && location<=15))","goff");
    TGraph *gr3=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr3->SetTitle("300 MeV/u");
    gr3->SetMarkerStyle(23);
    gr3->SetMarkerColor(3);
    gr3->SetMarkerSize(1.5);
    //gr3->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/11.649179:location","energy==250 && (location==0 ||( location>=11 && location<=15))","goff");
    TGraph *gr4=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr4->SetTitle("250 MeV/u");
    gr4->SetMarkerStyle(20);
    gr4->SetMarkerColor(4);
    gr4->SetMarkerSize(1.5);
    //gr4->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/4.6997141:location","energy==200 && (location==0 ||( location>=11 && location<=15))","goff");
    TGraph *gr5=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr5->SetTitle("200 MeV/u");
    gr5->SetMarkerStyle(43);
    gr5->SetMarkerColor(6);
    gr5->SetMarkerSize(1.5);
    //gr5->Fit("myfit","","",70,275);

    ipt->Draw("((EQ1+EQ2)*1e-9/(D_p*rbe))/2.1156558:location","energy==165 && (location==0 ||( location>=11 && location<=15))","goff");
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
    //gPad->SetLogx();
    //gPad->SetLogy();
    mgp->Fit("myfit","","",70,280);
    
    //mgp->GetXaxis()->SetLimits(50,400);
    //mgp->GetYaxis()->SetRangeUser(0.04,2);

    mgp->GetXaxis()->SetLimits(50,300);
    mgp->GetYaxis()->SetRangeUser(0,1.4);

    mgp->GetXaxis()->SetTitle("d (cm)");
    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("(H/D)_{d}/^{}(H/D)_{d_{iso}}");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.7,0.6,0.95,0.95);
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

    TLatex * t=new TLatex();
    //t->SetTextFont(22);
    t->SetNDC();
    t->SetTextSize(0.04);
    //t->DrawLatex(0.25,0.35,"#frac{(H/D)_{d}}{(H/D)_{d_{iso}}} = (#frac{d}{76.124})^{-1.6191}");
    t->DrawLatex(0.65,0.45,"#frac{(H/D)_{d}}{(H/D)_{d_{iso}}} = (#frac{d}{76.124})^{-1.6191}");
    //t->DrawLatex(0.25,0.25,"#chi^{2} / ndf = 3.70e-1 / 34");
    t->DrawLatex(0.65,0.35,"#chi^{2} / ndf = 0.37 / 34");
    t->SetTextSize(0.06);
    t->DrawLatex(0.4,0.85,"90^{#circ} direction");




    gPad->Modified();
    gPad->Update();
    c1->Modified();
    c1->Update();
   // gPad->BuildLegend();

    

}