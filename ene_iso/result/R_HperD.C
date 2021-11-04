void R_HperD()
{
    TFile *ipf=new TFile("datatree.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();
    ipt->Draw("((EQ1+EQ2)*1e-9/D_p):range*1e-1","location==0","goff");//pSv->mSv
    TGraph *gr0=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr0->SetMarkerStyle(21);
    gr0->SetMarkerColor(1);
    gr0->SetMarkerSize(1.5);
    gr0->SetLineColor(1);
    gr0->SetLineWidth(3);
    gr0->SetTitle("Isocenter");
    //gr0->Draw("ap");

    ipt->Draw("((EQ1+EQ2)*1e-9/D_p):range*1e-1","location==1","goff");//pSv->mSv
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr1->SetMarkerStyle(22);
    gr1->SetMarkerColor(2);
    gr1->SetMarkerSize(1.5);
    gr1->SetLineColor(2);
    gr1->SetLineWidth(3);
    gr1->SetTitle("0#circ 25cm");


    ipt->Draw("((EQ1+EQ2)*1e-9/D_p):range*1e-1","location==3","goff");//pSv->mSv
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr2->SetMarkerStyle(23);
    gr2->SetMarkerColor(kBlue);
    gr2->SetMarkerSize(1.5);
    gr2->SetLineColor(kBlue);
    gr2->SetLineWidth(3);
    gr2->SetTitle("0#circ 100cm");

    TMultiGraph *mgp=new TMultiGraph();
    mgp->Add(gr0,"pc");
    mgp->Add(gr1,"pc");
    mgp->Add(gr2,"pc");
    mgp->Draw("a");
    mgp->GetYaxis()->SetLimits(0,17);
    mgp->GetXaxis()->SetLimits(0,30);
    mgp->GetYaxis()->SetRangeUser(0,17);
    mgp->GetXaxis()->SetRangeUser(0,30);
    mgp->GetXaxis()->SetTitle("Range (cm)");
    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("H/D (mSv/Gy)");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.2,0.6,0.4,0.8);
    leg->AddEntry(gr0,"Isocenter","pl");
    leg->AddEntry(gr1,"0#circ 25cm","pl");
    leg->AddEntry(gr2,"0#circ 100cm","pl");
    leg->SetTextSize(0.04);
    leg->Draw();
}