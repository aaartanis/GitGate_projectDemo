Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*TMath::Power(x[0],par[1]);
}

void tree_plot1()
{
    TFile *ipf=new TFile("datatree_MLC.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TMultiGraph *m1 =new TMultiGraph();
    TGraph *gr[10];
    Color_t col[10]={1,2,3,4,41,40,6,9,46,49}; 
    Int_t mar[10]={20,33,22,23,29,21,34,39,43,47};
    Int_t local[10]={0,2,3,5,7,8,10,12,13,15};
    Double_t EQ1[10]={0.215527,0.0747379,0.0374133,0.0147071,0.081925,0.038539,0.0137778,0.115472,0.0417132,0.0095373};
    Double_t EQ2[10]={0.0647728,0.0242042,0.012531,0.0051738,0.0208625,0.0085722,0.0027704,0.021648,0.0062604,0.0014345};
    TString loc,target;

    for(int i=0;i<10;i++)
    {
        target.Form("(EQ1)/%f:size*size/100",EQ1[i]);
        loc.Form("location==%d",local[i]);
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
    m1->GetYaxis()->SetRangeUser(0,1.2);
    TLegend *leg;
    leg=new TLegend(0.6,0.6,0.95,0.95);
    leg->AddEntry(gr[0],"Isocenter","pl");
    leg->AddEntry(gr[1],"theta= 0 deg, r=50 cm","pl");
    leg->AddEntry(gr[4],"theta=45 deg, r=50 cm","pl");
    leg->AddEntry(gr[7],"theta=90 deg, r=50 cm","pl");
    leg->AddEntry(gr[2],"theta= 0 deg, r=100 cm","pl");
    leg->AddEntry(gr[5],"theta=45 deg, r=100 cm","pl");
    leg->AddEntry(gr[8],"theta=90 deg, r=100 cm","pl");
    leg->AddEntry(gr[3],"theta= 0 deg, r=200 cm","pl");
    leg->AddEntry(gr[6],"theta=45 deg, r=200 cm","pl");
    leg->AddEntry(gr[9],"theta=90 deg, r=200 cm","pl");
    leg->SetTextSize(0.04);
    leg->Draw();
    m1->GetXaxis()->SetTitle("aperture size/(cm^{2})");
    m1->GetXaxis()->CenterTitle(true);
    m1->GetYaxis()->SetTitle("H_{EQ1} / H_{EQ1_{0}}");
    m1->GetYaxis()->CenterTitle(true);





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