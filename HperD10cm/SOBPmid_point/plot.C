void plot()
{
    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();
    TGraph *g1=new TGraph;
    string fname;
    string ss;
    Double_t Depth,Gy,GyE,RBE,a,b,c,d;
    fname="350_RF60.txt";
    ifstream inf(fname);
    if(!inf.is_open()){
        cout<<"Data File"<<fname<<"dose not exist!"<<endl;
    }
    getline(inf,ss);
    int i=0;
    while(!inf.eof()){
        inf >> Depth>>Gy>>GyE>>RBE>>a>>b>>c>>d;
        g1->SetPoint(i++,Depth,Gy);
    }
    inf.close();
    g1->Draw("AC");
}