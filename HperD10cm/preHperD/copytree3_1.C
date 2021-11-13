//R_LOAD_LIBRARY($ROOTSYS/test/libEvent.so);
//for width
void copytree3_1()
{
    TFile oldfile("datatree_RF.root");
    TTree *oldtree;
    oldfile.GetObject("t",oldtree);

    const auto nentries = oldtree->GetEntries();
    Int_t width=0;
    oldtree->SetBranchAddress("width",&width);

    //create a new file + a clone of old tree without some entries in new file 
    TFile newfile("datatree_RF_new.root","recreate");
    auto newtree=oldtree->CloneTree(0);
    for (auto i:ROOT::TSeqI(nentries)){
        oldtree->GetEntry(i);
        if(width!=6) newtree->Fill();
        //if(size->GetNtrack()>=2) cout<<"size->GetNtrack() "<<size->GetNtrack()<<endl;     
    }
    newtree->Write();
}