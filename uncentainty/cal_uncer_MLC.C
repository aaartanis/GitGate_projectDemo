#include<iostream>
using namespace std;
#include<fstream>
void cal_uncer_MLC()
{
    //ene_iso  165MeV/u 90deg 200cm
    // 29.1%
/*    Double_t x[48]={16.1,17.63,18.62,9.593,14.77,15.57,12.66,17.22,8.898,20.3,\
    17.99,16.76,4.245,14.95,7.394,22.03,16.41,11.98,8.279,17.25,\
    13.15,14.06,21.59,8.805,17.39,16.67,14.65,19.79,13.09,12.73,\
    16.13,21.08,15.48,11.79,17.38,16.8,13.33,16.77,25.62,10.95,\
    15.59,11.57,26.94,21.46,13.07,17.73,14.05,10.99};
*/

    //ene_iso 400MeV/u 90deg 200cm
    // 11.7%
/*    Double_t x[48]={7.231,7.067,6.371,7.578,7.809,6.478,7.014,6.148,7.615,9.05,\
    6.505,8.491,7.747,7.579,7.746,7.294,7.808,7.36,7.093,9.9,\
    8.195,7.475,8.165,6.103,5.965,7.317,7.995,9.198,7.072,7.836,\
    8.251,7.327,7.275,7.506,7.817,7.878,5.806,6.909,7.341,8.021,\
    6.024,7.426,6.875,7.754,9.07,6.733,7.97,5.948};
*/    

    //ene_iso 400MeV/u iso
    //1.9%
 /*   Double_t x[48]={36.94,35.89,36.77,35.72,37.3,37.18,37.02,36.7,37.03,37.08,\
    36.78,35.51,37.18,37.05,35.61,37.53,35.94,38.57,36.53,36.76,\
    37.77,36.17,36.53,37.86,35.9,36.96,38.32,35.92,36.61,37.26,\
    36.31,36.33,37.57,36.13,37.07,36.42,37.57,36.71,36.25,37.06,\
    36.38,37.72,37.68,36.84,37.45,37.29,35.97,36.74};
*/

    ofstream outFile;
    outFile.open("MLC.csv",ios::out);
    outFile<< "size"<<","<<"location"<<","<<"error"<<"\n";

    TFile *root_file;
    TH1D *h;
    TString  file;
    string path="/home/rocky/software/GitGate_projectDemo/MLC_iso";
    string work_dir[16]={"/iso","/0deg/25cm","/0deg/50cm","/0deg/100cm",\
    "/0deg/150cm","/0deg/200cm","/45deg/25cm","/45deg/50cm",\
    "/45deg/100cm","/45deg/150cm","/45deg/200cm","/90deg/25cm",\
    "/90deg/50cm","/90deg/100cm","/90deg/150cm","/90deg/200cm"};
    string a[6]={"0","30","60","90","120","150"};
    Double_t x[48];
    Double_t x_average,Variance, deviation, statistical_error;
    Double_t sum_x,sum_var;

    for(Int_t i=0;i<6;i++)//6
    {
        for(Int_t j=0;j<16;j++)//16
        {
            for(Int_t k=0;k<48;k++)
            {
                file.Form("%s/%s-202107171418/output%s/%d_receptor%d.root",\
                path.c_str(),a[i].c_str(),work_dir[j].c_str(),j,k+1);
                root_file=new TFile(file.Data());
                h=(TH1D*)root_file->Get("energySpectrumFluenceTrack");
                x[k]=h->GetMean();
                root_file->Close();
            }
            
            sum_x=0;
            sum_var=0;
            x_average=0;
            Variance=0;
            deviation=0;
            for(Int_t i=0;i<48;i++)
            {
                sum_x=sum_x+ x[i];
            }
            x_average=sum_x/48;
            for(Int_t i=0;i<48;i++)
            {
                sum_var=sum_var+TMath::Power(x[i]-x_average,2);
            }
            Variance=sum_var/48;
            deviation=TMath::Sqrt(Variance);
            statistical_error=deviation*100/x_average;
            cout<<"receptor in "<<a[i]<<" "<<work_dir[j]<<endl;
            outFile<< a[i]<<","<< j<<","<< statistical_error<<"\n";
            //cout<< "statistic error = "<< deviation*100/x_average <<"%"<<endl;

        }
    }
    outFile.close();


}