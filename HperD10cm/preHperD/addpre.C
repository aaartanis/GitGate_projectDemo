void addpre()
{
    Int_t location,width,size,energy;
    Int_t ene[]={165,200,250,300,350,400};
    Double_t EQ1,EQ2,D_p,distance,HD_pre,HD_mc;
    Double_t HDRef[6];
    TFile *ipf=new TFile("mergefile.root","update");
    TTree *ipt=(TTree*)ipf->Get("t");
    ipt->SetBranchAddress("location",&location);
    ipt->SetBranchAddress("energy",&energy);
    ipt->SetBranchAddress("width",&width);
    ipt->SetBranchAddress("size",&size);
    ipt->SetBranchAddress("EQ1",&EQ1);
    ipt->SetBranchAddress("EQ2",&EQ2);
    ipt->SetBranchAddress("D_p",&D_p);
    TBranch *disBranch=ipt->Branch("distance",&distance,"distance/D");
    TBranch *preBranch=ipt->Branch("HD_pre",&HD_pre,"HD_pre/D");
    TBranch *mcBranch=ipt->Branch("HD_mc",&HD_mc,"HD_mc/D");

    //Get (H/D)_ref
    Long64_t nentries=ipt->GetEntries();
    for(Long64_t jentry=0; jentry<nentries;jentry++){
        ipt->GetEntry(jentry);
        switch(location)
        {
            case 0:
                distance=72;
                break;
            case 1:
                distance=97;
                break;
            case 2:
                distance=122;
                break;
            case 3:
                distance=172;
                break;
            case 4:
                distance=222;
                break;
            case 5:
                distance=272;
                break;
            case 6:
                distance=91.403;
                break;
            case 7:
                distance=113.027;
                break;
            case 8:
                distance=159.268;
                break;
            case 9:
                distance=207.262;
                break;
            case 10:
                distance=256.025;
                break;
            case 11:
                distance=76.217;
                break;
            case 12:
                distance=87.658;
                break;
            case 13:
                distance=123.223;
                break;
            case 14:
                distance=166.385;
                break;
            case 15:
                distance=212.565;
                break;
            default:
                cout<<"Error"<<endl;
        }
        if(location==0 && width==6 && size==0)
        {
            switch(energy)
            {
                case 165:
                    HDRef[0]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                case 200:
                    HDRef[1]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                case 250:
                    HDRef[2]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                case 300:
                    HDRef[3]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                case 350:
                    HDRef[4]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                case 400:
                    HDRef[5]=(EQ1+EQ2)*1e-9/D_p;
                    break;
                default:
                    cout<<"Error of energy"<<endl;
            }
        }
        if(energy==165)
        {
            HD_pre=HDRef[0]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[0]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==200)
        {
            HD_pre=HDRef[1]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[1]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==250)
        {
            HD_pre=HDRef[2]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[2]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==300)
        {
            HD_pre=HDRef[3]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[3]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==350)
        {
            HD_pre=HDRef[4]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[4]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==400)
        {
            HD_pre=HDRef[5]*TMath::Power(distance/71.1,-2.213)*(-0.00379*size*size/100+0.997)*(-0.0238*width+1.148);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[5]<< " "<<HD_pre<<" "<<endl;
        }
        HD_mc=(EQ1+EQ2)*1e-9/D_p;
        cout<<HD_mc<<endl;
        disBranch->Fill();
        preBranch->Fill();
        mcBranch->Fill();
    }
    ipt->Write();
    ipf->Close();
}