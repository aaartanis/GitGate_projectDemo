Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*TMath::Power(x[0],par[1]);
}

void tree_plot1()
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

    Double_t HD_EQ1_angle0[6]={61.464474,33.774931,21.307011,10.665022,6.355964,4.1974299};
    Double_t HD_EQ1_angle45[6]={61.464474,37.198176,23.342629,10.995374,6.1752097,3.9338666};
    Double_t HD_EQ1_angle90[6]={61.464474,51.256597,32.928883,11.895497,5.1762003,2.7172422};

    Double_t HD_EQ2_angle0[6]={18.501285,10.63874,6.8877371,3.5645188,2.1781374,1.4734661};
    Double_t HD_EQ2_angle45[6]={18.501285,10.578507,5.9521529,2.4471995,1.2855682,0.7882214};
    Double_t HD_EQ2_angle90[6]={18.501285,12.390897,6.1686534,1.7820085,0.757994,0.4124170};

    TString loc,target;

    for(int i=0;i<6;i++)
    {
        target.Form("((EQ2)*1e-9/(D_p*rbe))/%f:size*size/100",HD_EQ2_angle0[i]);
        loc.Form("location==%d",local_angle0[i]);
        ipt->Draw(target.Data(),loc.Data(),"goff");
        gr[i]=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
        gr[i]->SetMarkerColor(col[i]);
        gr[i]->SetLineColor(col[i]);
        gr[i]->SetLineWidth(2);
        gr[i]->SetMarkerStyle(mar[i]);
        gr[i]->SetMarkerSize(1.5);
        m1->Add(gr[i],"CP");  
    }
    
    TCanvas *c0=new TCanvas();
    c0->cd();
    m1->Draw("ACP");
    m1->GetYaxis()->SetRangeUser(0,2);
    TLegend *leg;
    leg=new TLegend(0.75,0.6,0.95,0.95);
    leg->AddEntry(gr[0],"Isocenter","pl");
    leg->AddEntry(gr[1],"25 cm","pl");
    leg->AddEntry(gr[2],"50 cm","pl");
    leg->AddEntry(gr[3],"100 cm","pl");
    leg->AddEntry(gr[4],"150 cm","pl");
    leg->AddEntry(gr[5],"200 cm","pl");
    leg->SetTextSize(0.04);
    leg->Draw();
    m1->GetXaxis()->SetTitle("aperture size/(cm^{2})");
    m1->GetXaxis()->CenterTitle(true);
    m1->GetYaxis()->SetTitle("(H/D)_{2} / (H/D)_{2_{0}}");
    m1->GetYaxis()->CenterTitle(true);

    TLatex *t = new TLatex();
    t->SetNDC();
    t->SetTextSize(0.06);
    t->DrawLatex(0.4,0.85,"0^{#circ} direction");





/*

    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();
    ipt->Draw("EQ1+EQ2:e","location==0","goff");
    TGraph *gr=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr->SetMarkerStyle(22);
    gr->SetMarkerSize(1.5);
    gr->Draw("ap");

    TCanvas *c1=new TCanvas("c1","c1");
    c1->cd();
    TF1 *f1=new TF1("myfit",fitFunc,72,300,2);
    f1->SetLineColor(1);
    f1->SetLineWidth(3);
    f1->SetParNames("k1","a1");
    f1->SetParameters(1,-2);
    //Draw with option goff and generate variables
    Double_t x[] = {72,97,122,172,222,272,91.403,113.027,159.268,207.262,256.025,76.217,87.658,123.223,166.385,212.565};
    ipt->Draw("EQ1+EQ2:location","energy==400","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr1->SetTitle("400 MeV/u");
    gr1->SetMarkerStyle(21);
    gr1->SetMarkerColor(1);
    gr1->SetMarkerSize(1.5);
    gr1->Fit("myfit","","",69,280);


    ipt->Draw("EQ1+EQ2:location","energy==350","goff");
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr2->SetTitle("350 MeV/u");
    gr2->SetMarkerStyle(22);
    gr2->SetMarkerColor(2);
    gr2->SetMarkerSize(1.5);
    gr2->Fit("myfit","","",70,280);

    ipt->Draw("EQ1+EQ2:location","energy==300","goff");
    TGraph *gr3=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr3->SetTitle("300 MeV/u");
    gr3->SetMarkerStyle(23);
    gr3->SetMarkerColor(3);
    gr3->SetMarkerSize(1.5);
    gr3->Fit("myfit","","",70,280);

    ipt->Draw("EQ1+EQ2:location","energy==250","goff");
    TGraph *gr4=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr4->SetTitle("250 MeV/u");
    gr4->SetMarkerStyle(20);
    gr4->SetMarkerColor(4);
    gr4->SetMarkerSize(1.5);
    gr4->Fit("myfit","","",70,280);

    ipt->Draw("EQ1+EQ2:location","energy==200","goff");
    TGraph *gr5=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr5->SetTitle("200 MeV/u");
    gr5->SetMarkerStyle(72);
    gr5->SetMarkerColor(6);
    gr5->SetMarkerSize(1.5);
    gr5->Fit("myfit","","",70,280);

    ipt->Draw("EQ1+EQ2:location","energy==165","goff");
    TGraph *gr6=new TGraph(ipt->GetSelectedRows(),x,ipt->GetV1());
    gr6->SetTitle("165 MeV/u");
    gr6->SetMarkerStyle(71);
    gr6->SetMarkerColor(7);
    gr6->SetMarkerSize(1.5);  
    gr6->Fit("myfit","","",70,280);  

    TMultiGraph *mgp=new TMultiGraph();
    mgp->Add(gr1,"p");
    mgp->Add(gr2,"p");
    mgp->Add(gr3,"p");
    mgp->Add(gr4,"p");
    mgp->Add(gr5,"p");
    mgp->Add(gr6,"p");
    mgp->Draw("a");
    mgp->GetYaxis()->SetLimits(0,0.36);
    mgp->GetXaxis()->SetLimits(40,310);
    mgp->GetYaxis()->SetRangeUser(0,0.36);
    mgp->GetXaxis()->SetRangeUser(40,310);
    mgp->GetXaxis()->SetTitle("d/(cm)");
    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("H per ion / (pSv#upoint ion^{-1})");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.6,0.5,0.8,0.8);
    leg->AddEntry(gr1,"400 MeV/u","p");
    leg->AddEntry(gr2,"350 MeV/u","p");
    leg->AddEntry(gr3,"300 MeV/u","p");
    leg->AddEntry(gr4,"250 MeV/u","p");
    leg->AddEntry(gr5,"200 MeV/u","p");
    leg->AddEntry(gr6,"165 MeV/u","p");
    leg->SetTextSize(0.04);
    leg->Draw();
    gStyle->SetOptFit(0000);
    gPad->Modified();
    gPad->Update();
   // gPad->BuildLegend();

*/    

}