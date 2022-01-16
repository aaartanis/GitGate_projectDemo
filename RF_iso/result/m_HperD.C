Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*TMath::Power(x[0],2)+par[1]*x[0]+par[2];

}
void m_HperD()
{
    TFile *ipf=new TFile("datatree_RF.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TMultiGraph *m1 =new TMultiGraph();
    TGraph *gr[10];
    Color_t col[10]={9,2,3,4,41,40,6,9,46,49}; 
    Int_t mar[10]={20,33,22,23,29,21,34,39,43,47};
    Int_t local[10]={0,3,5,8,10,13,15};
    Double_t H0[10]={79.965760,14.229541,5.6708961,13.442573,4.7220880,13.677506,3.1296592};

    TString loc,target;

    for(int i=0;i<7;i++)
    {
        target.Form("((EQ1+EQ2)*1e-9/(D_p*rbe))/%f:width",H0[i]);
       // if(i==0) 
       //     target.Form("((EQ1+EQ2)*1e-9*0.2/(D_p*rbe)):width");
       // else
       //     target.Form("((EQ1+EQ2)*1e-9/(D_p*rbe)):width");
        loc.Form("location==%d",local[i]);
        ipt->Draw(target.Data(),loc.Data(),"goff");
        gr[i]=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
        gr[i]->SetMarkerColor(col[i]);
        gr[i]->SetLineColor(col[i]);
        gr[i]->SetLineWidth(3);
        gr[i]->SetMarkerStyle(mar[i]);
        gr[i]->SetMarkerSize(1.5);
        m1->Add(gr[i],"P");  
    }

    Int_t ng=6;
    Double_t xg[6]={2,4,6,8,10,12};
    Double_t yg[6]={27.5310,26.9724,25.5701,24.2597,23.1429,22.1497};
    Double_t yg_norm[6];
    for(int i=0;i<ng;i++)
    {
        yg_norm[i]=yg[i]/25.5701;
    }
    TGraph *gra = new TGraph(ng,xg,yg_norm);
    gra->SetMarkerColor(1);
    gra->SetMarkerStyle(48);
    gra->SetMarkerSize(1.5);
    m1->Add(gra,"P");

    TF1 *f1=new TF1("myfit",fitFunc,0,12,3);
    f1->SetLineColor(1);
    f1->SetLineWidth(3);
    f1->SetParNames("a","b","c");
    f1->SetParameters(0.0001,-0.02,1.11);

    TCanvas *c0=new TCanvas();
    c0->cd();
    gra->Fit("myfit","","",1.9,12.1);
    m1->GetXaxis()->SetTitle("SOBP width (cm)");
    m1->GetXaxis()->CenterTitle(true);
    m1->GetYaxis()->SetTitle("(H/D)_{m} /^{}(H/D)_{0}");
    m1->GetYaxis()->CenterTitle(true);
    m1->Draw("AP");
    m1->GetXaxis()->SetLimits(1,13);
    m1->GetYaxis()->SetRangeUser(0.8,1.2);
    TLegend *leg;
    leg=new TLegend(0.6,0.6,0.95,0.95);
    leg->AddEntry(gr[0],"Isocenter","p");
    leg->AddEntry(gr[1]," 0^{#circ} 100cm","p");
    leg->AddEntry(gr[2]," 0^{#circ} 200cm","p");
    leg->AddEntry(gr[3],"45^{#circ} 100cm","p");
    leg->AddEntry(gr[4],"45^{#circ} 200cm","p");
    leg->AddEntry(gr[5],"90^{#circ} 100cm","p");
    leg->AddEntry(gr[6],"90^{#circ} 200cm","p");
    leg->AddEntry(f1,"Pol2 fit","l");
    leg->AddEntry(gra,"Average all locations","p");
    leg->SetTextSize(0.04);
    leg->Draw();

    TLatex * t=new TLatex();
    //t->SetTextFont(22);
    t->SetNDC();
    t->SetTextSize(0.04);
    t->DrawLatex(0.2,0.32,"C_{m} = 1.12e-4 m^{2} - 0.0206487 m + 1.12662 ");
    t->DrawLatex(0.2,0.25,"#chi^{2} / ndf = 2.85e-4 / 3");

}