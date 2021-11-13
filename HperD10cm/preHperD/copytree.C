void copytree()
{
    TFile *ipf1=new TFile("datatree.root");
    TTree *ipt1=(TTree*)ipf1->Get("t");
    //non-activate range branches
    ipt1->SetBranchStatus("*",1);
    ipt1->SetBranchStatus("range",0);

    //create a new file without range branch
    TFile *opf=new TFile("datatree_new.root","recreate");
    TTree *opt=ipt1->CloneTree();

    opt->Print();
    opf->Write();
}