

void plot()
{
    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();
    TString InputPath, infile, SaveName;
    char a[100];
    int Event_number;
    InputPath="165-0-202111051423";
    infile.Form("../%s/EventNum.txt",InputPath.Data());
    //get eventnum
    FILE *myfile=fopen(infile.Data(),"r");
    if(feof(myfile))
    {
        cout<<"can not open this file"<<endl;
        return 0;
    }
    fscanf(myfile,"%s %d",a,&Event_number);
    cout<< "event number = " << Event_number<<endl;
    fclose(myfile);

    TString RootPath;
    RootPath.Form("./%s/braggpeak_water-Dose.root",InputPath.Data());
    TFile *ipf=new TFile(RootPath.Data());
    TH1D *h=(TH1D*)ipf->Get("histo");
    TH1D *dh=new TH1D("dh","dh/dx",1750,-175,175);
    for(int i=1;i<=h->GetNbinsX();i++)
    {
        Double_t df=h->GetBinContent(i+1)-h->GetBinContent(i);
        dh->Fill(h->GetBinLowEdge(i+1),df);
    }
    dh->Sumw2(0);
    TF1 *f1=new TF1("f1","[0]*TMath::Exp(-0.5*((x-[1])/[2])^2)",-118,-117);
    f1->SetParameter(0,-4e-6);
    f1->SetParameter(1,-117.5);
    f1->SetParameter(2,0.5);
    dh->Fit("f1","R");
    Double_t mean=f1->GetParameter(1);
    Double_t sigma=f1->GetParameter(2);
    Int_t max_bin=h->GetMaximumBin();
    Int_t mini_bin=h->FindBin(mean+3*sigma);
    cout<<"bin number "<<h->GetNbinsX()<<endl;
    cout<<"maximumbin "<<max_bin<<" mm "<<max_bin*0.2<<endl;
    cout<<"minimumbin "<<mini_bin<<" mm "<<mini_bin*0.2<<endl;
    cout<<"residual value "<<max_bin*0.2-mini_bin*0.2<<endl;
    cout<<"mid-bin "<<(max_bin+mini_bin)/2<<endl;
    cout<<"mid-point D "<<h->GetBinContent((max_bin+mini_bin)/2)<<endl;
    cout<<InputPath.Data()<<endl;
    cout<<"D/p = "<<(h->GetBinContent((max_bin+mini_bin)/2))/Event_number<<" Grey"<<endl;
    dh->Draw();
    SaveName.Form("./figure/%s.png",InputPath.Data());
    c0->SaveAs(SaveName.Data());


    //h->Draw("hist");
}