#include <string.h>
void plotplus()
{
    TString RootPath;
    char InputFile[100];//name!
    Int_t Event_number;
    TFile *ipf;
    TH1D *h,*dh;
    TF1 *f1;
    Double_t mean,sigma;
    Int_t max_bin,mini_bin;
    TCanvas *c0=new TCanvas("c0","c0");
    gStyle->SetOptFit(1);
    ifstream myfile;
    myfile.open("output.txt");
    
    while(1)
    {  
        
        myfile>>InputFile>>Event_number;
        if(myfile.eof()) break;
        cout<<"File "<<InputFile<< " number "<<Event_number<<endl;

        RootPath.Form("./%s/braggpeak_water-Dose.root",InputFile);
        ipf=new TFile(RootPath.Data());
        h=(TH1D*)ipf->Get("histo");
        dh=new TH1D("dh","dh/dx",1750,-175,175);
        for(int i=1;i<=h->GetNbinsX();i++)
        {
            Double_t df=h->GetBinContent(i+1)-h->GetBinContent(i);
            dh->Fill(h->GetBinLowEdge(i+1),df);
        }
        dh->Sumw2(0);
        f1=new TF1("f1","[0]*TMath::Exp(-0.5*((x-[1])/[2])^2)",89,94);
        f1->SetParameter(0,-4e-6);
        f1->SetParameter(1,92);
        f1->SetParameter(2,0.5);
        dh->Fit("f1","R");
        mean=f1->GetParameter(1);
        sigma=f1->GetParameter(2);
        max_bin=h->GetMaximumBin();
        mini_bin=h->FindBin(mean+sigma);
        cout<<"bin number "<<h->GetNbinsX()<<endl;
        cout<<"maximumbin "<<max_bin<<endl;
        cout<<"minimumbin "<<mini_bin<<endl;
        cout<<(max_bin+mini_bin)/2<<endl;
        cout<<"mid-point D "<<h->GetBinContent((max_bin+mini_bin)/2)<<endl;
        cout<<"D/p = "<<(h->GetBinContent((max_bin+mini_bin)/2))/Event_number<<" Grey"<<endl;
        c0->cd();
        dh->Draw();
        strcat(InputFile,".png");
        cout<<InputFile<<endl;
        c0->SaveAs(InputFile);
        cout<<"     "<<endl;

        //h->Draw("hist");
    }
    myfile.close();
  
}