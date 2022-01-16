void barhist()
{
    TFile *ipf=new TFile("mergefile.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    TCanvas *c1=new TCanvas();
    c1->cd();

    ipt->Draw("EQ1+EQ2:energy","location==8 && width==6 && size==0","goff");//EQ1 per theraputic dose / H/(D*rbe)  = EQ1/(EQ1+EQ2)
    Double_t *HD_mc=ipt->GetV1();
    Double_t HD_mc_array[6];
    for(int i=0;i<6;i++)
    {
        HD_mc_array[i]=HD_mc[i];
        //cout<<HD_mc_array[i]<<endl;
    }
    
    ipt->Draw("EQ1:energy","location==8 && width==6 && size==0","goff");
    TH1D *h0=new TH1D("h0","h0",13,1,13);
    TH1D *h1=new TH1D("h1","h1",13,1,13);
    Int_t n=ipt->GetSelectedRows();
    Double_t x[6]={2,4,6,8,10,12};
    Double_t *y=ipt->GetV1();
    for(int i=0;i<n;i++) 
    {
        h1->Fill(x[i],y[i]/HD_mc_array[i]);
        cout<<y[i]/HD_mc_array[i]<<endl;
    }
    h1->SetStats(1);
    h1->SetFillColor(kViolet);
    //h1->SetBarWidth(1);
    //h1->SetBarOffset(0.5);
    //h1->Draw("bar HIST");
    //c1->Draw();

    ipt->Draw("EQ2:energy","location==8 && width==6 && size==0","goff");
    TH1D *h2=new TH1D("h2","h2",13,1,13);
    Int_t n2=ipt->GetSelectedRows();
    Double_t x2[6]={2,4,6,8,10,12};
    Double_t *y2=ipt->GetV1();
    for(int i=0;i<n;i++) 
    {
        h2->Fill(x2[i],y2[i]/HD_mc_array[i]);
        //cout<<y2[i]<<endl;
    }
    //h1->SetStats(0);
    h2->SetFillColor(kBlue); 

    THStack *hs= new THStack("hs","Stacked 1D histogram");
    hs->Add(h0);
    hs->Add(h1);
    hs->Add(h2);
    hs->Draw("hist bar1");
    //hs->GetXaxis()->SetLabelOffset(9999);
    hs->GetXaxis()->SetNdivisions(0);
    hs->GetXaxis()->SetTitle("hello");
    hs->GetXaxis()->CenterTitle(true);
    c1->Draw();

    //TLengend *legend=new TLegend(0.55,0.65,0.76,0.82);
    //legend->AddEntry(h1,"EQ1","f");
    //legend->Draw();

/*
    Int_t n=gr->GetN();
    Double_t *x=gr->GetX();
    Double_t *y=gr->GetY();
    for(int i=0;i<n;i++) 
        h1->Fill(x[i],y[i]);
    h1->Draw("hist");
*/



   // 
   // h1->Draw("bar");

    
    //
    //

    
    //h1->Draw("HIST B");

    //TCanvas *c0=new TCanvas();
  /*
    THStack *hs= new THStack("hs","Stacked 1D histogram");


    
    TH1D *h2=new TH1D("h2","h2",20,150,450);
    h2->SetFillColor(kBlue);

    hs->Add(h1);
    hs->Add(h2);
    hs->Draw("hist");
*/


    
    /*
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
    gr1->SetMarkerStyle(22);
    gr1->SetMarkerColor(2);
    gr1->SetMarkerSize(1.5);
    gr1->Draw();
    */

        /*
    const Int_t nx=6;
    const char *energy[nx]={"165","200","250","300","350","400"};
    //Int_t xlabel[6]={165,200,250,300,350,400};
    TCanvas *c0=new TCanvas();
    c0->cd();
    TH1D *h=new TH1D("h","h",6,0,6);
    h->SetStats(0);
    h->SetFillColor(38);
    h->SetCanExtend(TH1::kAllAxes);
    Double_t *y1=ipt->GetV1();

    for(Int_t i=0;i<6;i++)
    {
        h->Fill(energy[i],y1[i]);
    }
    h->LabelsDeflate();
    //h->SetBarWidth(0.4);
    //h->SetBarOffset(0.5);
    h->Draw("bar HIST");
    c0->Draw();
*/
}