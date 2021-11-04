#include "Riostream.h"
#include "TFile.h"
#include "TTree.h"

void datatree()
{
    //open ROOT file to save the TTree in 
    TFile *ftree= new TFile("datatree.root","recreate");
    //creation of TTree
    TTree *t = new TTree("t","tree data of simulation");
    Int_t location,energy,width,size,range;
    Double_t EQ1,EQ2,D_p;
    //open the data file for reading
    ifstream file;
    file.open("dataFile.txt");
    //creation of branches to hold the variables
    t->Branch("location",&location,"location/I");
    t->Branch("energy",&energy,"energy/I");
    t->Branch("width",&width,"width/I");
    t->Branch("size",&size,"size/I");
    t->Branch("EQ1",&EQ1,"EQ1/D");
    t->Branch("EQ2",&EQ2,"EQ2/D");
    t->Branch("D_p",&D_p,"D_p/D");
    t->Branch("range",&range,"range/I");

    string ss;
    getline(file,ss);
    int i=0;
    while(1)
    {
        file>>location>>energy>>width>>size>>EQ1>>EQ2;
        switch(energy)
        {
        case 165 :
            D_p=  3.69449e-11;
            range= 55;
            break;
        case 200 :
            D_p=  3.56716e-11;
            range= 79;
            break;
        case 250 :
            D_p=  3.22786e-11;
            range= 120;
            break;
        case 300:
            D_p=  2.82846e-11;
            range= 165;
            break;
        case 350 :
            D_p=  2.42485e-11;
            range= 214;
            break;
        case 400 :
            D_p=  2.08814e-11;
            range= 267;
            break;
        default :
            cout<< "error"<<endl;
        }
        if(file.eof()) break;
        cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<EQ1<< " "<<EQ2<<" "<<D_p<<" "<<range<<endl;
        t->Fill();
    }
    t->Write();
    ftree->Close();
    file.close();
}