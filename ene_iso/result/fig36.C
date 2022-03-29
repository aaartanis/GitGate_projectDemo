void fig36()
{    
    TCanvas *c[3];
    TString canvas,file_name,name,pic_name,format;
    TFile *root_file;
    TH1D *h[5],*h0;
    Int_t a[6]={400,350,300,250,200,165};
    Int_t b[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    string recep_id[16]={"iso","0deg_25cm","0deg_50cm","0deg_100cm",\
    "0deg_150cm","0deg_200cm","45deg_25cm","45deg_50cm","45deg_100cm",\
    "45deg_150cm","45deg_200cm","90deg_25cm","90deg_50cm","90deg_100cm",\
    "90deg_150cm","90deg_200cm"};
    Double_t event_numb[6]={10031664,10028265,10031125,10030249,10031509,10031445};
   
    
    gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadRightMargin(0.1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetTextFont(22);
    gStyle->SetTextSize(0.08);
    gStyle->SetLabelFont(22,"xyz");
    gStyle->SetLabelSize(0.05,"xyz");
    gStyle->SetLabelOffset(0.015,"xyz");
    gStyle->SetTitleFont(22,"xyz");
    gStyle->SetTitleSize(0.06,"xyz");
    gStyle->SetTitleOffset(1.2,"xyz");
    gStyle->SetLegendFont(22);

    gStyle->SetFrameLineStyle(1);
    gStyle->SetFrameLineWidth(3);
    gStyle->SetLineWidth(3);
    gStyle->SetHistLineWidth(3);
    gStyle->SetMarkerSize(1.5);
    TGaxis::SetMaxDigits(3);

    TCanvas *c0=new TCanvas("c0","c0",2);
    gPad->SetLogx(1);

    Int_t temp=1;
    for(Int_t j=0;j<5;j++)
    {
        file_name.Form("400-202107121601/%d_receptor.root",b[j+11]);
        cout<< file_name.Data()<<endl;
        root_file=new TFile(file_name.Data());
        h[j]=(TH1D*)root_file->Get("energySpectrumFluenceTrack");
        h[j]->Scale(1/904.77868);
        h[j]->Scale(1/event_numb[0]);

        if(j==0)
            {
                h[j]->GetXaxis()->SetTitle("Energy (MeV)");
                h[j]->GetXaxis()->CenterTitle(true);
                h[j]->GetYaxis()->SetTitle("#Phi ( n#upoint cm^{-2}#upoint ion^{-1})");
                h[j]->GetYaxis()->CenterTitle(true);
                h[j]->SetLineColor(1);
                h[j]->Draw("hist");
            }
            else
            {
                temp++;
                if(temp==5) temp++;
                h[j]->SetLineColor(temp);
                h[j]->Draw("same hist ");
            }
    }
    TLegend *leg;
    leg=new TLegend(0.7,0.6,0.95,0.95);
    leg->AddEntry(h[0],"25 cm","l");
    leg->AddEntry(h[1],"50 cm","l");
    leg->AddEntry(h[2],"100 cm","l");
    leg->AddEntry(h[3],"150 cm","l");
    leg->AddEntry(h[4],"200 cm","l");
    leg->SetTextSize(0.05);
    leg->Draw();
    gStyle->SetOptFit(0000);

    TLatex * t=new TLatex();
    t->SetNDC();
    t->SetTextSize(0.06);
    t->DrawLatex(0.2,0.8,"90^{#circ} direction");

    

/*
    for(Int_t i=0;i<16;i++)
    {
        canvas.Form("c%d",i+1);
        c[i]=new TCanvas(canvas.Data(),canvas.Data(),2);
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
        c[i]->Draw();
        //format.Form(".pdf");
        //pic_name.Form("/home/rocky/software/GitGate_projectDemo/ene_iso/result/fluence/%s%s",recep_id[i].c_str(),format.Data());

        //c[i]->SaveAs(pic_name.Data());
        
    }
    */
}