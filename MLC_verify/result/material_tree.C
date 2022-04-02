#include "Riostream.h"
#include "TFile.h"
#include "TTree.h"

void material_tree()
{
    //open ROOT file to save the TTree in 
    TFile *ftree= new TFile("material_tree.root","recreate");
    //creation of TTree
    TTree *t = new TTree("t","tree data of simulation");
    TString material;
    Int_t type,location,energy,width,size;
    Double_t EQ1,EQ2,D_p,rbe;
    //open the data file for reading
    ifstream file;
    file.open("dataFile.txt");
    //creation of branches to hold the variables
    t->Branch("type",&type,"type/S");
    t->Branch("location",&location,"location/I");
    t->Branch("energy",&energy,"energy/I");
    t->Branch("width",&width,"width/I");
    t->Branch("size",&size,"size/I");
    t->Branch("EQ1",&EQ1,"EQ1/D");
    t->Branch("EQ2",&EQ2,"EQ2/D");
    t->Branch("D_p",&D_p,"D_p/D");
    t->Branch("rbe",&rbe,"rbe/D");

    string ss;
    getline(file,ss);
    int i=0;
    while(1)
    {
        file>>material>>location>>energy>>width>>size>>EQ1>>EQ2;
        if (material=="Alloy")
            type=1;
        else
            type=2;
        switch(energy)
        {
        case 165 :
            D_p=  3.69449e-11;
            rbe=1.729;
            break;
        case 200 :
            D_p=  3.56716e-11;
            rbe=1.727;
            break;
        case 250 :
            D_p=  3.22786e-11;
            rbe=1.718;
            break;
        case 300:
            D_p=  2.82846e-11;
            rbe=1.695;
            break;
        case 350 :
            D_p=  2.42485e-11;
            rbe=1.668;
            break;
        case 400 :
            D_p=  2.08814e-11;
            rbe=1.68;
            break;
        default :
            cout<< "error"<<endl;
        }
        if(file.eof()) 
            break;
        cout<<type<<" "<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<EQ1<< " "<<EQ2<<" "<<D_p<<" "<<rbe<<endl;
        t->Fill();
    }
    t->Write();
    ftree->Close();
    file.close();
}