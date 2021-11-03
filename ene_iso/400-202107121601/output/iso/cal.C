#include "Riostream.h"
void cal()
{
        ifstream file;
        file.open("0_receptor1_energySpectrumNbPart.txt");
        string ss;
        Double_t a,b,sum;
        for(int i=0;i<10;i++){  
                getline(file,ss);}
        sum=0;
        while(!file.eof())
        {
                file>>a>>b;
                sum +=b;
        }
        cout<<"sum: "<<sum<<endl;

        TFile *ipf=new TFile("0_receptor1.root");
        TH1D *h=(TH1D*)ipf->Get("energySpectrumNbPart");
        Double_t en=0;
        for(int bin=1;bin<=h->GetNbinsX();bin++)
        {
            en += h->GetBinContent(bin);
        
        }
        cout<<"entries: "<<en<<endl;



}
