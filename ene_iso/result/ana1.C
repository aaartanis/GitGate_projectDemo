void ana1()
{    
    TCanvas *c[16];
    TLegend *leg[16];
    TString canvas,file_name,name,pic_name,format;
    TFile *root_file;
    TH1D *h[16][6],*h0;
    Int_t a[6]={400,350,300,250,200,165};
    Int_t b[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    string recep_id[16]={"iso","0deg_25cm","0deg_50cm","0deg_100cm",\
    "0deg_150cm","0deg_200cm","45deg_25cm","45deg_50cm","45deg_100cm",\
    "45deg_150cm","45deg_200cm","90deg_25cm","90deg_50cm","90deg_100cm",\
    "90deg_150cm","90deg_200cm"};
    Double_t event_numb[6]={10031664,10028265,10031125,10030249,10031509,10031445};
   
    for(Int_t i=0;i<16;i++)
    {
        canvas.Form("c%d",i+1);
        c[i]=new TCanvas(canvas.Data(),canvas.Data());
        leg[i]=new TLegend(0.17,0.6,0.54,0.9);
        gPad->SetLogx(1);
        Int_t temp=1;
        for(Int_t j=0;j<6;j++)
        {
            cout<< recep_id[i]<<endl;
            file_name.Form("%d-202107121601/%d_receptor.root",a[j],b[i]);
            name.Form("%dMeV/u %s",a[j],recep_id[i].c_str());
            //name.Form("%dMeV/u ",a[j]);

            cout<<file_name.Data()<<endl;
            root_file=new TFile(file_name.Data());
            //h[i][j]=(TH1D*)root_file->Get("energySpectrumNbPart");//Nb
            h[i][j]=(TH1D*)root_file->Get("energySpectrumFluenceTrack");

            //h[i][j]->Scale(1/113.097);//dN/dA Nb
            h[i][j]->Scale(1/904.77868);
            h[i][j]->Scale(1/event_numb[j]);
            h[i][j]->SetTitle(name.Data());

            if(j==0)
            {
                h[i][j]->GetXaxis()->SetTitle("Energy (MeV)");
                h[i][j]->GetXaxis()->CenterTitle(true);
                h[i][j]->GetYaxis()->SetTitle("#Phi ( n#upoint cm^{-2}#upoint ion^{-1})");
                h[i][j]->GetYaxis()->CenterTitle(true);
                h[i][j]->SetLineColor(1);
                h[i][j]->Draw("hist");
            }
            else
            {
                temp++;
                if(temp==5) temp++;
                h[i][j]->SetLineColor(temp);
                h[i][j]->Draw("same hist ");
            }
            
            leg[i]->AddEntry(h[i][j],name.Data(),"l");
            leg[i]->SetTextSize(0.04);

        }
        c[i]->cd();
        gStyle->SetOptStat(0);
        
        //gStyle->SetLegendTextSize(0);
        leg[i]->Draw();
        //c[i]->BuildLegend();
        c[i]->Draw();
        format.Form(".pdf");
        //   old//pic_name.Form("/home/aaa/Desktop/Room2/ene_iso/result/fluence/%s%s",recep_id[i].c_str(),format.Data());
        pic_name.Form("/home/rocky/software/GitGate_projectDemo/ene_iso/result/fluence/%s%s",recep_id[i].c_str(),format.Data());

        c[i]->SaveAs(pic_name.Data());
        
    }
}