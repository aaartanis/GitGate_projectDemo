void graph()
{
    TCanvas *c0=new TCanvas("c0","my graph");
    TGraph *g=new TGraph;
    string fname;
    fname="dataFile.txt";
    string ss,name;
    Double_t low_H,high_H,tot_H, perce1,perce2;
    Double_t energy[6]={400,350,300,250,200,165};

    ifstream inf(fname);
    if(!inf.is_open())
    {
        cout<<"Data File"<<fname<< "does not exist!"<<endl;
    }
    getline(inf,ss);
   /* int i=0;
    while(!inf.eof())
    {
        inf >> name >> low_H >> high_H >> tot_H >> perce1 >> perce2;
        g->SetPoint()
    }
    */
    for(int i=0;i<6;i++)
    {
        inf >> name >>ss >> low_H >> high_H >> tot_H >> perce1 >> perce2;
        cout<<name<<"  " << low_H<<"  "<<high_H<<" "<<perce1<<" "<<perce2<<endl;
        g->SetPoint(i,energy[i],tot_H);
    }
    inf.close();
    g->SetLineColor(kBlack);
    g->SetLineWidth(3);
    g->SetMarkerStyle(kFullCircle);
    g->SetMarkerSize(1.5);
    g->SetTitle("the relation of beam energy and dose equivalent");
    g->Draw("ACP");
    c0->Draw();
}