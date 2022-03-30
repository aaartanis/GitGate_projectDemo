void plot3()
{
        gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadRightMargin(0.1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);//0.15 0.2
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

    TFile *ipf=new TFile("mergefile.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TCanvas *c0=new TCanvas("c0","c0",2);
    c0->cd();
    TPad *pad=new TPad("pad","pad",0,0,1,1);
    pad->Draw();
    pad->cd();
    pad->Range(0,0,15,15);
    /* //width
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==2 && location <=15 && size ==0","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr1->SetMarkerStyle(34);
    gr1->SetMarkerColor(7);
    gr1->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==4 && location <=15 && size ==0 ","goff");
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(6);
    gr2->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=15 && size ==0 ","goff");
    TGraph *gr3=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr3->SetMarkerStyle(20);
    gr3->SetMarkerColor(4);
    gr3->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==8 && location <=15 && size ==0 ","goff");
    TGraph *gr4=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(3);
    gr4->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==10 &&location <=15 && size ==0 ","goff");
    TGraph *gr5=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr5->SetMarkerStyle(22);
    gr5->SetMarkerColor(2);
    gr5->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==12 && location <=15 && size ==0 ","goff");
    TGraph *gr6=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr6->SetMarkerStyle(43);
    gr6->SetMarkerColor(9);
    gr6->SetMarkerSize(1.5);
    */

    
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=5 && size ==0","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr1->SetMarkerStyle(34);
    gr1->SetMarkerColor(7);
    gr1->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=5 && size ==30 ","goff");
    TGraph *gr2=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(6);
    gr2->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=5 && size ==60 ","goff");
    TGraph *gr3=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr3->SetMarkerStyle(20);
    gr3->SetMarkerColor(4);
    gr3->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=5 && size ==90 ","goff");
    TGraph *gr4=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(3);
    gr4->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 &&location <=5 && size ==120 ","goff");
    TGraph *gr5=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr5->SetMarkerStyle(22);
    gr5->SetMarkerColor(2);
    gr5->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==400 && width==6 && location <=5 && size ==150 ","goff");
    TGraph *gr6=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr6->SetMarkerStyle(43);
    gr6->SetMarkerColor(9);
    gr6->SetMarkerSize(1.5);
    

/*
//        ipt->Draw("HD_pre/HD_mc:distance","energy==400   && width==6 && location <=15 && size =150 ","goff");


    ipt->Draw("HD_pre/HD_mc:distance","energy==165   && width==6 && location <=5 && size <=100 ","goff");
    TGraph *gr7=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr7->SetMarkerStyle(29);
    gr7->SetMarkerColor(46);
    gr7->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==200   && width==6 && location <=5 && size <=100 ","goff");
    TGraph *gr8=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr8->SetMarkerStyle(33);
    gr8->SetMarkerColor(21);
    gr8->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==250   && width==6 &&location <=5 && size <=100 ","goff");
    TGraph *gr9=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr9->SetMarkerStyle(39);
    gr9->SetMarkerColor(38);
    gr9->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==300   && width==6 && location <=5 && size <=100 ","goff");
    TGraph *gr10=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr10->SetMarkerStyle(41);
    gr10->SetMarkerColor(41);
    gr10->SetMarkerSize(1.5);
    ipt->Draw("HD_pre/HD_mc:distance","energy==350   && width==6 && location <=5 && size <=100 ","goff");
    TGraph *gr11=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr11->SetMarkerStyle(47);
    gr11->SetMarkerColor(28);
    gr11->SetMarkerSize(1.5);
*/

    TMultiGraph *mgp=new TMultiGraph();
    mgp->Add(gr1,"p");
    mgp->Add(gr2,"p");
    mgp->Add(gr3,"p");
    mgp->Add(gr4,"p");
    mgp->Add(gr5,"p");
    mgp->Add(gr6,"p");
    //mgp->Add(gr7,"p");
    //mgp->Add(gr8,"p");
    //mgp->Add(gr9,"p");
    //mgp->Add(gr10,"p");
    //mgp->Add(gr11,"p");
    mgp->Draw("a");
    //mgp->GetYaxis()->SetLimits(0,3);
    //mgp->GetXaxis()->SetLimits(40,310);
    //mgp->GetYaxis()->SetRangeUser(0.9,1.05);
    //mgp->GetYaxis()->SetRangeUser(0,6);
    mgp->GetYaxis()->SetRangeUser(0,2);


    //mgp->GetXaxis()->SetRangeUser(40,310);
    mgp->GetXaxis()->SetTitle("d (cm)");
    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("(H/D)_{pred} / (H/D)_{mc}");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.6,0.5,0.8,0.8);

    //leg->AddEntry(gr7,"165 MeV/u,  6cm SOBP","p");
    //leg->AddEntry(gr8,"200 MeV/u,  6cm SOBP","p");
    //leg->AddEntry(gr9,"250 MeV/u,  6cm SOBP","p");
    //leg->AddEntry(gr10,"300 MeV/u,  6cm SOBP","p");
    //leg->AddEntry(gr11,"350 MeV/u,  6cm SOBP","p");

    /*
    leg->AddEntry(gr1,"SOBP 2cm","p");
    leg->AddEntry(gr2,"SOBP 4cm","p");
    leg->AddEntry(gr3,"SOBP 6cm","p");
    leg->AddEntry(gr4,"SOBP 8cm","p");
    leg->AddEntry(gr5,"SOBP 10cm","p");
    leg->AddEntry(gr6,"SOBP 12cm","p");
    */

    leg->AddEntry(gr1,"Closed","p");
    leg->AddEntry(gr2,"3#times3 cm^{2}","p");
    leg->AddEntry(gr3,"6#times6 cm^{2}","p");
    leg->AddEntry(gr4,"9#times9 cm^{2} ","p");
    leg->AddEntry(gr5,"12#times12 cm^{2}","p");
    leg->AddEntry(gr6,"15#times15 cm^{2}","p");

    //leg->SetMargin(0.);
    //leg->AddEntry(f1,"Power law fit","l");
    leg->SetTextSize(0.03);
    leg->Draw();
    gPad->SetGridy(1);

}