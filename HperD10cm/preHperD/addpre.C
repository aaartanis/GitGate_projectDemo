void addpre()
{
    Int_t location,width,size,energy;
    Int_t ene[]={165,200,250,300,350,400};
    Double_t EQ1,EQ2,D_p,distance,HD_pre,HD_mc,rbe;
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
    ipt->SetBranchAddress("rbe",&rbe);
    TBranch *disBranch=ipt->Branch("distance",&distance,"distance/D");
    TBranch *preBranch=ipt->Branch("HD_pre",&HD_pre,"HD_pre/D");
    TBranch *mcBranch=ipt->Branch("HD_mc",&HD_mc,"HD_mc/D");

    Double_t d_iso=72.34;
    Double_t x[16];
    Double_t r[5]={25,50,100,150,200};
    //Double_t theta[3]={0,45,90};
    Double_t pi=TMath::Pi();
    Double_t rad[3]={0,pi/4,pi/2};
    x[0]=d_iso;
    Int_t temp=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            x[temp]=TMath::Sqrt(TMath::Sq(d_iso+r[j]*TMath::Cos(rad[i]))+TMath::Sq(r[j]*TMath::Sin(rad[i])));
            //cout<<x[temp]<<endl;
            temp++;
        }
    }
    //Get (H/D)_ref
    Long64_t nentries=ipt->GetEntries();
    for(Long64_t jentry=0; jentry<nentries;jentry++){
        ipt->GetEntry(jentry);
        switch(location)
        {
            case 0:
                distance=x[0];
                break;
            case 1:
                distance=x[1];
                break;
            case 2:
                distance=x[2];
                break;
            case 3:
                distance=x[3];
                break;
            case 4:
                distance=x[4];
                break;
            case 5:
                distance=x[5];
                break;
            case 6:
                distance=x[6];
                break;
            case 7:
                distance=x[7];
                break;
            case 8:
                distance=x[8];
                break;
            case 9:
                distance=x[9];
                break;
            case 10:
                distance=x[10];
                break;
            case 11:
                distance=x[11];
                break;
            case 12:
                distance=x[12];
                break;
            case 13:
                distance=x[13];
                break;
            case 14:
                distance=x[14];
                break;
            case 15:
                distance=x[15];
                break;
            default:
                cout<<"Error"<<endl;
        }
        if(location==0 && width==6 && size==0)
        {
            switch(energy)
            {
                case 165:
                    HDRef[0]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                case 200:
                    HDRef[1]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                case 250:
                    HDRef[2]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                case 300:
                    HDRef[3]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                case 350:
                    HDRef[4]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                case 400:
                    HDRef[5]=(EQ1+EQ2)*1e-9/(D_p*rbe);
                    break;
                default:
                    cout<<"Error of energy"<<endl;
            }
        }
        if(energy==165)
        {
            HD_pre=HDRef[0]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[0]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==200)
        {
            HD_pre=HDRef[1]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[1]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==250)
        {
            HD_pre=HDRef[2]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[2]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==300)
        {
            HD_pre=HDRef[3]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[3]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==350)
        {
            HD_pre=HDRef[4]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[4]<< " "<<HD_pre<<" "<<endl;
        }
        if(energy==400)
        {
            HD_pre=HDRef[5]*TMath::Power(distance/72.34,-2.22094)*(-0.00383208*size*size/100+0.996192)*(-0.0238401*width+1.14768);
            cout<< location<< " "<< energy<< " "<< width<< " "<<size<< " "<<HDRef[5]<< " "<<HD_pre<<" "<<endl;
        }
        HD_mc=(EQ1+EQ2)*1e-9/(D_p*rbe);
        cout<<HD_mc<<endl;
        disBranch->Fill();
        preBranch->Fill();
        mcBranch->Fill();
    }
    ipt->Write();
    ipf->Close();
}