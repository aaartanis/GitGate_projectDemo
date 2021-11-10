Double_t fitFunc(Double_t *x,Double_t *par){
    return par[0]*x[0]+par[1];
}
void s_HperD1()
{
    TFile *ipf=new TFile("datatree_MLC.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TMultiGraph *m1 =new TMultiGraph();
    TGraph *gr[10];
    Color_t col[10]={1,2,3,4,41,40,6,9,46,49}; 
    Int_t mar[10]={20,33,22,23,29,21,34,39,43,47};
    Int_t local[10]={0,3,5,8,10,13,15};
    Double_t H0[10]={13.423419,2.3918080,0.9520865,2.2561327,0.7924870,2.2974350,0.5254408};
    TString loc,target;
    TF1 *f1=new TF1("myfit",fitFunc,0,230,2);
    f1->SetLineColor(1);
    f1->SetLineWidth(5);
    f1->SetParNames("k","a");
    f1->SetParameters(-0.004,1);

    for(int i=0;i<7;i++)
    {
        target.Form("((EQ1+EQ2)*1e-9/D_p)/%f:size*size/100",H0[i]);
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
    leg=new TLegend(0.6,0.6,0.95,0.95);
    leg->AddEntry(gr[0],"Isocenter","p");
    leg->AddEntry(gr[1]," 0#circ 100cm","p");
    leg->AddEntry(gr[4],"45#circ 200cm","p");
    leg->AddEntry(gr[2]," 0#circ 200cm","p");
    leg->AddEntry(gr[5],"90#circ 100cm","p");
    leg->AddEntry(gr[3],"45#circ 100cm","p");
    leg->AddEntry(gr[6],"90#circ 200cm","p");
    leg->AddEntry(f1,"Linear fit","l");
    leg->SetTextSize(0.04);
    leg->Draw();

}