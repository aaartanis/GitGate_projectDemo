Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*x[0]+par[1];
}

void s_HperD_sep()
{
    TFile *ipf=new TFile("datatree_MLC.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TMultiGraph *m1 =new TMultiGraph();
    TGraph *gr[6];
    Color_t col[6]={1,2,3,4,41,40}; 
    Int_t mar[6]={20,33,22,23,29,21};
    Int_t local_angle0[6]={0,1,2,3,4,5};
    Int_t local_angle45[6]={0,6,7,8,9,10};
    Int_t local_angle90[6]={0,11,12,13,14,15};

    Double_t H0_angle0[6]={79.965760,44.413671,28.194749,14.229541,8.5341015,5.6708961};
    Double_t H0_angle45[6]={79.965760,47.776683,29.294782,13.442573,7.4607779,4.722088};
    Double_t H0_angle90[6]={79.965760,63.647495,39.097537,13.677506,5.9341943,3.1296592};

    TString loc,target;

    for(int i=0;i<6;i++)
    {
        target.Form("((EQ1+EQ2)*1e-9/(D_p*rbe))/%f:size*size/100",H0_angle0[i]);
        loc.Form("location==%d",local_angle0[i]);
        ipt->Draw(target.Data(),loc.Data(),"goff");
        gr[i]=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
        gr[i]->SetMarkerColor(col[i]);
        gr[i]->SetLineColor(col[i]);
        gr[i]->SetLineWidth(3);
        gr[i]->SetMarkerStyle(mar[i]);
        gr[i]->SetMarkerSize(1.5);
        m1->Add(gr[i],"P");  
    }
    
    TF1 *f1=new TF1("myfit",fitFunc,0,12,2);
    f1->SetLineColor(1);
    f1->SetLineWidth(3);
    f1->SetParNames("a","b");
    f1->SetParameters(-0.004,1);


    TCanvas *c0=new TCanvas();
    c0->cd();
    m1->Fit("myfit","","",0,230);
    m1->GetXaxis()->SetTitle("aperture size (cm^{2})");
    m1->GetXaxis()->CenterTitle(true);
    m1->GetYaxis()->SetTitle("(H/D)_{a} /^{}(H/D)_{0}");
    m1->GetYaxis()->CenterTitle(true);  
    m1->Draw("ACP");
    //m1->GetYaxis()->SetLimits(0,1.2);
    m1->GetYaxis()->SetRangeUser(0,1.2);
    //m1->GetXaxis()->SetRangeUser(0,250);
    m1->GetXaxis()->SetLimits(0,250);
    TLegend *leg;
    leg=new TLegend(0.75,0.6,0.95,0.95);
    leg->AddEntry(gr[0],"Isocenter","p");
    leg->AddEntry(gr[1],"25cm","p");
    leg->AddEntry(gr[2],"50cm","p");
    leg->AddEntry(gr[3],"100cm","p");
    leg->AddEntry(gr[4],"150cm","p");
    leg->AddEntry(gr[5],"200cm","p");
    leg->AddEntry(f1,"Pol2 fit","l");
    leg->SetTextSize(0.04);
    leg->Draw();

    TLatex *t = new TLatex();
    t->SetNDC();
    t->SetTextSize(0.04);
    t->DrawLatex(0.2,0.32,"C_{a} = - 3.63303e-3 a + 0.958614 ");
    t->DrawLatex(0.2,0.25,"#chi^{2} / ndf = 0.201 / 34");
    t->SetTextSize(0.06);
    t->DrawLatex(0.4,0.85,"0^{#circ} direction");

}