//R_LOAD_LIBRARY($ROOTSYS/test/libEvent.so);
//for size
void copytree3()
{
    TFile oldfile("datatree_MLC.root");
    TTree *oldtree;
    oldfile.GetObject("t",oldtree);

    const auto nentries = oldtree->GetEntries();
    Int_t size=0;
    oldtree->SetBranchAddress("size",&size);

    //create a new file + a clone of old tree without some entries in new file 
    TFile newfile("datatree_MLC_new.root","recreate");
    auto newtree=oldtree->CloneTree(0);
    for (auto i:ROOT::TSeqI(nentries)){
        oldtree->GetEntry(i);
        if(size>0) newtree->Fill();
        //if(size->GetNtrack()>=2) cout<<"size->GetNtrack() "<<size->GetNtrack()<<endl;     
    }
    newtree->Write();
}