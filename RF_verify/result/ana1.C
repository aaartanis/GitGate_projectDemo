void ana1()
{    
    TCanvas *c[2];
    TLegend *leg[2];
    TString canvas,file_name,name,pic_name,format;
    TFile *root_file;
    TH1D *h[2][3],*h0;
    //Int_t a[6]={400,350,300,250,200,165};
    Int_t a[3]={2,6,10};
    Int_t b[2]={0,1};
    string recep_id[2]={"iso","pre_point"};
    //Double_t event_numb[6]={10031664,10028265,10031125,10030249,10031509,10031445};
    Double_t event_numb[6]={10031445,10030832,10031189};

    for(Int_t i=1;i<2;i++)
    {
        canvas.Form("c%d",i+1);
        c[i]=new TCanvas(canvas.Data(),canvas.Data());
        leg[i]=new TLegend(0.17,0.6,0.54,0.9);
        Int_t temp=1;
        for(Int_t j=0;j<3;j++)
        {
            cout<< recep_id[i]<<endl;
            //change file directory name
            file_name.Form("%d-202203271606/%d_receptor.root",a[j],b[i]);
            //change the legend name
            name.Form("SOBP width %dcm %s",a[j],recep_id[i].c_str());
            cout<<file_name.Data()<<endl;
            root_file=new TFile(file_name.Data());
            //h[i][j]=(TH1D*)root_file->Get("energySpectrumNbPart");
            h[i][j]=(TH1D*)root_file->Get("energySpectrumFluenceTrack");

            //h[i][j]->Scale(1/113.097);//dN/dA
            h[i][j]->Scale(1/904.77868);

            h[i][j]->Scale(1/event_numb[j]);
            h[i][j]->SetTitle(name.Data());

            //cout<<h[i][j]->GetBinContent(1)<<endl;
            h[i][j]->SetMinimum(0);
            //cout<<h[i][j]->GetBinLowEdge(1)<<endl;

            if(j==0)
            {
                h[i][j]->GetXaxis()->SetTitle("Energy (MeV)");
                h[i][j]->GetXaxis()->CenterTitle(true);
                h[i][j]->GetYaxis()->SetTitle("#Phi (n#upoint cm^{-2}#upoint ion^{-1})");
                h[i][j]->GetYaxis()->CenterTitle(true);
                h[i][j]->SetLineColor(1);
                h[i][j]->Draw("hist ");
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
        gPad->SetLogx(1);
        //gStyle->SetLegendTextSize(0);
        leg[i]->Draw();
        //c[i]->BuildLegend();
        //c[i]->Draw();
        format.Form(".pdf");
        //change the path
        //old//pic_name.Form("/home/aaa/Desktop/Room2/RF_iso/result/fluence/%s%s",recep_id[i].c_str(),format.Data());
        pic_name.Form("/home/rocky/software/GitGate_projectDemo/RF_verify/result/fluence/%s%s",recep_id[i].c_str(),format.Data());

        c[i]->SaveAs(pic_name.Data());
        

    }
}