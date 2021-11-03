#include "Riostream.h"
#include "TFile.h"
#include "TTree.h"

void datatree_RF()
{
    //open ROOT file to save the TTree in 
    TFile *ftree= new TFile("datatree_RF.root","recreate");
    //creation of TTree
    TTree *t = new TTree("t","tree data of simulation");
    Int_t location,energy,width,size;
    Double_t EQ1,EQ2;
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

    string ss;
    getline(file,ss);
    int i=0;
    while(1)
    {
        file>>location>>energy>>width>>size>>EQ1>>EQ2;
        if(file.eof()) break;
        cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<EQ1<< " "<<EQ2<<endl;
        t->Fill();
    }
    t->Write();
    ftree->Close();
    file.close();
}