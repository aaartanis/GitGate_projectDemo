Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*x[0]+par[1];
}

void s_HperD_sep()
{
    gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadRightMargin(0.1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetTextFont(22);
    gStyle->SetTextSize(0.08);
    gStyle->SetLabelFont(22,"xyz");
    gStyle->SetLabelSize(0.05,"xyz");
    gStyle->SetLabelOffset(0.015,"xyz");
    gStyle->SetTitleFont(22,"xyz");
    gStyle->SetTitleSize(0.06,"xyz");
    gStyle->SetTitleOffset(1.12,"xyz");
    gStyle->SetLegendFont(22);

    gStyle->SetFrameLineStyle(1);
    gStyle->SetFrameLineWidth(3);
    gStyle->SetLineWidth(3);
    gStyle->SetHistLineWidth(3);
    gStyle->SetMarkerSize(1.5);
    TGaxis::SetMaxDigits(3);

    TFile *ipf=new TFile("datatree_MLC.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TMultiGraph *m1 =new TMultiGraph();
    TGraph *gr[6];
    Color_t col[6]={1,2,3,4,41,40}; 
    Int_t mar[6]={20,33,22,23,29,21};
    Int_t local_angle0[6]={0,1,2,3,4,5};
    Int_t local_angle45[6]={0,6,7,8,9,10};
    Int_t local_angle90[6]={0,11,12,13,14,15};
    
    //here are (EQ1+EQ2)*1e-9/(D_p*rbe)
    Double_t H0_angle0[6]={79.965760,44.413671,28.194749,14.229541,8.5341015,5.6708961};
    Double_t H0_angle45[6]={79.965760,47.776683,29.294782,13.442573,7.4607779,4.722088};
    Double_t H0_angle90[6]={79.965760,63.647495,39.097537,13.677506,5.9341943,3.1296592};
    //here are E1 E2
    Double_t H1_angle0[6]={2.15622,1.18485,0.747466,0.374137,0.222972,0.147249};
    Double_t H1_angle45[6]={2.15622,1.30494,0.818877,0.385726,0.216631,0.138003};
    Double_t H1_angle90[6]={2.15622,1.79812,1.15517,0.417303,0.181585,0.0953229};
    Double_t H2_angle0[6]={0.649039,0.373215,0.241627,0.125046,0.0764107,0.0516903};
    Double_t H2_angle45[6]={0.649039,0.371102,0.208806,0.0858496,0.0450987,0.0276514};
    Double_t H2_angle90[6]={0.649039,0.434682,0.216401,0.0625142,0.026591,0.0144679};

    TString loc,target;

    for(int i=0;i<6;i++)
    {
        //target.Form("((EQ1+EQ2)*1e-9/(D_p*rbe))/%f:size*size/100",H0_angle0[i]);
        target.Form("EQ2/%f:size*size/100",H2_angle0[i]);
        loc.Form("location==%d",local_angle0[i]);
        ipt->Draw(target.Data(),loc.Data(),"goff");
        gr[i]=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
        gr[i]->SetMarkerColor(col[i]);
        gr[i]->SetLineColor(col[i]);
        gr[i]->SetLineWidth(3);
        gr[i]->SetMarkerStyle(mar[i]);
        gr[i]->SetMarkerSize(1.5);
        m1->Add(gr[i],"pc");  
    }
    
    TF1 *f1=new TF1("myfit",fitFunc,0,12,2);
    f1->SetLineColor(1);
    f1->SetLineWidth(5);
    f1->SetParNames("a","b");
    f1->SetParameters(-0.004,1);


    TCanvas *c0=new TCanvas("c0","c0",2);
    c0->cd();
    //m1->Fit("myfit","","",0,230);
    m1->GetXaxis()->SetTitle("aperture size (cm^{2})");
    m1->GetXaxis()->CenterTitle(true);
    m1->GetYaxis()->SetTitle("(H/D)_{2} /^{}(H/D)_{2_{0}}");
    m1->GetYaxis()->CenterTitle(true);  
    m1->Draw("ACP");
    //m1->GetYaxis()->SetLimits(0,1.2);
    //m1->GetYaxis()->SetRangeUser(0,1.2);
    m1->GetYaxis()->SetRangeUser(0,2);
    //m1->GetXaxis()->SetRangeUser(0,250);
    m1->GetXaxis()->SetLimits(-10,250);
    TLegend *leg;
    leg=new TLegend(0.7,0.6,0.9,0.9);
    leg->AddEntry(gr[0],"Isocenter","l");
    leg->AddEntry(gr[1],"25cm","l");
    leg->AddEntry(gr[2],"50cm","l");
    leg->AddEntry(gr[3],"100cm","l");
    leg->AddEntry(gr[4],"150cm","l");
    leg->AddEntry(gr[5],"200cm","l");
    //leg->AddEntry(f1,"Fit","l");
    leg->SetTextSize(0.04);
    leg->Draw();

    TLatex *t = new TLatex();
    t->SetNDC();
    //t->SetTextSize(0.04);
    //t->DrawLatex(0.2,0.32,"C_{a} = - 3.63303e-3 a + 0.958614 ");
    //t->DrawLatex(0.2,0.25,"#chi^{2} / ndf = 0.201 / 34");
    t->SetTextSize(0.06);
    t->DrawLatex(0.19,0.82,"0^{#circ} direction");

}