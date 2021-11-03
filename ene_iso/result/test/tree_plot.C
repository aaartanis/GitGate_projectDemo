void tree_plot()
{
    TFile *ipf=new TFile("datatree.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    //ipt->Scan("*");
    Int_t n=ipt->Draw("EQ1+EQ2:energy","location==0","*");
    printf("The arrays' dimension is %d\n",n);

    //Retrieve variables 
    Double_t *tot=ipt->GetVal(0);//GetVal(0) get first one(EQ1+EQ2) 
    Double_t *e =ipt->GetVal(1);

    //Creat and draw graphs
    TGraph *gs= new TGraph(n,e,tot);
    TCanvas *c1=new TCanvas("c1","c1");
    c1->cd();
    gs->SetMarkerStyle(22);
    gs->Draw("ap");

}