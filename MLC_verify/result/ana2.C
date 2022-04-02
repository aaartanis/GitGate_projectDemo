#include <iostream>
#include <fstream>
using namespace std;

void ana2()
{
    TGraph *g1=new TGraph;
    string fname;
    string ss;
    Double_t energy,factor;
    fname="ICRP_74.txt";
    ifstream inf(fname);
    if(!inf.is_open()){
        cout<<"Data File"<<fname<<"does not exist!"<<endl;
    }
    getline(inf,ss);
    int i=0;
    while(!inf.eof()){
        inf >>energy>>factor;
        g1->SetPoint(i++,energy,factor);
    }
    inf.close();
    g1->Draw("AC");

    TGraph *g2=new TGraph;
    fname="Fluka1998.txt";
    ifstream inf1(fname);
    if(!inf1.is_open()){
        cout<<"Data File"<<fname<<"does not exist!"<<endl;
    }
    getline(inf1,ss);
    i=0;
    while(!inf1.eof()){
        inf1>>energy>>factor;
        g2->SetPoint(i++,energy*1e3,factor*(1e12));
    }
    inf1.close();
    g2->Draw("ACP");

    Int_t NumberofBins=480;
    Double_t X[481];
    Double_t Xlow=1e-6,Xhigh=1e3;
    Double_t BinSize=(TMath::Log10(Xhigh)-TMath::Log10(Xlow))/NumberofBins;
    for(int i=0;i<=NumberofBins;i++)
    {
        X[i]=Xlow * TMath::Power(10,BinSize*i);
    }

    TH1D *th[16][2];
    TCanvas *c[16];
    TLegend *leg[16];
    TString canvas,file_name,name,pic_name,format;
    TFile *root_file;
    TH1D *h[16][2],*h0,*th0;
    //Int_t a[6]={2,4,6,8,10,12};
    string a[2]={"Alloy","Iron"};
    Int_t b[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Double_t db;
    Double_t sum1,sum2;
    string recep_id[16]={"iso","0deg_25cm","0deg_50cm","0deg_100cm",\
    "0deg_150cm","0deg_200cm","45deg_25cm","45deg_50cm","45deg_100cm",\
    "45deg_150cm","45deg_200cm","90deg_25cm","90deg_50cm","90deg_100cm",\
    "90deg_150cm","90deg_200cm"};
    //Double_t event_numb[6]={10031509,10031445,10031445,10031509,10031479,10031172};
    Double_t event_numb[2]={10031189,10031317};

   

    ofstream dataFile;
    dataFile.open("dataFile.txt",ofstream::app);
    dataFile <<"type"<<"\t"<< "location"<<"\t"<<"energy(MeV/u)"<<"\t"<<"SOBP_width(cm)"<<"\t"<<"aperture_size(mm)"<<"\t"<< "dose_EQ_min-15(pSv/ion)"<<"\t"<<"dose_EQ_15-max(pSv/ion)"<<endl;
    for(int i=0;i<16;i++) //i<16 change i<1
    {
        canvas.Form("c%d",i+1);
        c[i]=new TCanvas(canvas.Data(),canvas.Data());
        leg[i]=new TLegend(0.17,0.6,0.54,0.9);
        Int_t temp=1;
        for(int j=0;j<2;j++)
        {
            //change file directory name
            file_name.Form("%s-202204011550/%d_receptor.root",a[j].c_str(),b[i]);//change the name
            //change the legend name
            name.Form("%s %s",a[j].c_str(),recep_id[i].c_str());
            cout<<file_name.Data()<<endl;
            root_file=new TFile(file_name.Data());
            //h[i][j]=(TH1D*)root_file->Get("energySpectrumNbPart");
            h[i][j]=(TH1D*)root_file->Get("energySpectrumFluenceTrack");

            //h[i][j]->Scale(1/113.097);//dN/dA
            h[i][j]->Scale(1/904.77868);

            h[i][j]->Scale(1/event_numb[j]);
            h[i][j]->SetTitle(name.Data());
            
            th[i][j]=new TH1D(name.Data(),name.Data(),NumberofBins,X);
            db=0;
            for(int bin=1;bin<=h[i][j]->GetNbinsX();bin++)
            {
                if((h[i][j]->GetBinLowEdge(bin+1))<=200)
                    //db=(h[i][j]->GetBinContent(bin))*(h[i][j]->GetBinWidth(bin))*(g1->Eval(h[i][j]->GetBinCenter(bin)));
                    db=(h[i][j]->GetBinContent(bin))*(g1->Eval(h[i][j]->GetBinCenter(bin)));
                else
                    //db=(h[i][j]->GetBinContent(bin))*(h[i][j]->GetBinWidth(bin))*(g2->Eval(h[i][j]->GetBinCenter(bin)));
                    db=(h[i][j]->GetBinContent(bin))*(g2->Eval(h[i][j]->GetBinCenter(bin)));
                th[i][j]->Fill(h[i][j]->GetBinCenter(bin),db);
            }
            if(j==0)
            {
                th[i][j]->GetXaxis()->SetTitle("Energy (MeV)");
                th[i][j]->GetXaxis()->CenterTitle(true);
                th[i][j]->GetYaxis()->SetTitle("H per ion (pSv#upoint ion^{-1})");
                th[i][j]->GetYaxis()->CenterTitle(true);
                th[i][j]->SetLineColor(1);
                th[i][j]->Draw("hist");

                if(i==4 )
                {
                    Double_t  plotmax= 1.2*th[i][j]->GetMaximum();
                    th[i][j]->SetMaximum(plotmax);
                }
                if(i==5 )
                {
                    Double_t  plotmax= 1.7*th[i][j]->GetMaximum();
                    th[i][j]->SetMaximum(plotmax);
                }
            }
            else
            {
                temp++;
                if (temp==5) temp++;
                th[i][j]->SetLineColor(temp); 
                th[i][j]->Draw("same hist");
            }
            //cout the contrubution
            sum1=0;
            sum2=0;
            for(int N=1;N<=th[i][j]->GetNbinsX();N++)
            {
                if((th[i][j]->GetBinLowEdge(N+1))<=15.0)
                    sum1 += th[i][j]->GetBinContent(N);
                else
                    sum2 += th[i][j]->GetBinContent(N);
            }
          
            //change the varition
            Int_t energy=300;
            Int_t SOBP_width=6;
            Int_t aperturesize=50;
            //Int_t aperture_size=0;
            dataFile<<a[j]<<"\t"<<b[i]<<"\t"<<energy<<"\t"<<SOBP_width<<"\t"<<aperturesize<<"\t"<<sum1<<"\t"<<sum2<<endl;

            leg[i]->AddEntry(th[i][j],name.Data(),"l");
            leg[i]->SetTextSize(0.04);
            
        }
        c[i]->cd();
        gStyle->SetOptStat(0);
        gPad->SetLogx(1);
        leg[i]->Draw();
        c[i]->Draw();
        format.Form(".pdf");
        //pic_name.Form("/home/aaa/Desktop/Room2/MLC_iso/result/dose_equ/%s%s",recep_id[i].c_str(),format.Data());
        pic_name.Form("/home/rocky/software/GitGate_projectDemo/MLC_verify/result/dose_equ/%s%s",recep_id[i].c_str(),format.Data());

        c[i]->SaveAs(pic_name.Data());
    }
}