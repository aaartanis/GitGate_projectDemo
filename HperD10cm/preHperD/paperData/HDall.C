void HDall()
{
    TCanvas *c0=new TCanvas("c0","c0");
    c0->cd();

    TFile *ipf=new TFile("../mergefile.root");
    TTree *ipt=(TTree*)ipf->Get("t");
    Double_t DFE[3]={15,40,90};
    ipt->Draw("HD_mc/rbe:location","energy==300 && width==6 && size ==0 && location>=11 && location<=13","goff");
    TGraph *gr1=new TGraph(ipt->GetSelectedRows(),DFE,ipt->GetV1());
    gr1->SetMarkerStyle(43);
    gr1->SetMarkerColor(1);
    gr1->SetMarkerSize(2);
    gr1->SetLineWidth(3);

    TTree *t1=new TTree("t1","tree form Yan.CSV");
    t1->ReadFile("Yan.CSV","x/D:y/D:y_coordinate/D");
    t1->Draw("y_coordinate:x","","goff");
    TGraph *g1=new TGraph(t1->GetSelectedRows(),t1->GetV2(),t1->GetV1());
    //g1->SetMarkerStyle(20);
    //g1->SetMarkerColor(6);
    //g1->SetMarkerSize(2);
    g1->SetLineWidth(3);
    g1->SetLineColor(6);
    g1->SetLineStyle(2);

    /*
    TTree *t2=new TTree("t2","tree form Wroe.CSV");
    t2->ReadFile("Wroe.CSV","x/D:y/D:y_coordinate/D");
    t2->Draw("y_coordinate:x","","goff");
    TGraph *g2=new TGraph(t2->GetSelectedRows(),t2->GetV2(),t2->GetV1());
    g2->SetLineWidth(3);
    g2->SetLineColor(4);
    g2->SetMarkerStyle(20);
    g2->SetMarkerSize(1.5);
    g2->SetMarkerColor(4);
  
    TTree *t3=new TTree("t3","tree form Mesoloras.CSV");
    t3->ReadFile("Mesoloras.CSV","x/D:y/D:y_coordinate/D");
    t3->Draw("y_coordinate:x","","goff");
    TGraph *g3=new TGraph(t3->GetSelectedRows(),t3->GetV2(),t3->GetV1());
    g3->SetLineWidth(3);
    g3->SetLineColor(46);
    g3->SetMarkerStyle(21);
    g3->SetMarkerSize(1.5);
    g3->SetMarkerColor(46);

    TTree *t4=new TTree("t4","tree form Zacharatou.CSV");
    t4->ReadFile("Zacharatou.CSV","x/D:y/D:y_coordinate/D");
    t4->Draw("y_coordinate:x","","goff");
    TGraph *g4=new TGraph(t4->GetSelectedRows(),t4->GetV2(),t4->GetV1());
    g4->SetLineWidth(3);
    g4->SetLineColor(kRed+1);
    g4->SetLineStyle(2);
*/
    TTree *t2=new TTree("t2","tree form work_waterbox.CSV");
    t2->ReadFile("work_waterbox.CSV","x/D:y/D:y_coordinate/D");
    t2->Draw("y_coordinate:x","","goff");
    TGraph *g2=new TGraph(t2->GetSelectedRows(),t2->GetV2(),t2->GetV1());
    g2->SetLineWidth(3);
    g2->SetLineColor(4);
    g2->SetMarkerStyle(20);
    g2->SetMarkerSize(1.5);
    g2->SetMarkerColor(4);
  
    TTree *t3=new TTree("t3","tree form work_Alloy.CSV");
    t3->ReadFile("work_Alloy.CSV","x/D:y/D:y_coordinate/D");
    t3->Draw("y_coordinate:x","","goff");
    TGraph *g3=new TGraph(t3->GetSelectedRows(),t3->GetV2(),t3->GetV1());
    g3->SetLineWidth(3);
    g3->SetLineColor(46);
    g3->SetMarkerStyle(21);
    g3->SetMarkerSize(1.5);
    g3->SetMarkerColor(46);

    TTree *t4=new TTree("t4","tree form work_Iron.CSV");
    t4->ReadFile("work_Iron.CSV","x/D:y/D:y_coordinate/D");
    t4->Draw("y_coordinate:x","","goff");
    TGraph *g4=new TGraph(t4->GetSelectedRows(),t4->GetV2(),t4->GetV1());
    g4->SetLineWidth(3);
    g4->SetLineColor(kRed+1);
    g4->SetLineStyle(2);

    TTree *t5=new TTree("t5","tree form Polf.CSV");
    t5->ReadFile("Polf.CSV","x/D:y/D:y_coordinate/D");
    t5->Draw("y_coordinate:x","","goff");
    TGraph *g5=new TGraph(t5->GetSelectedRows(),t5->GetV2(),t5->GetV1());
    g5->SetLineWidth(3);
    g5->SetLineColor(38);
    g5->SetMarkerStyle(22);
    g5->SetMarkerSize(1.5);
    g5->SetMarkerColor(38);

    TTree *t6=new TTree("t6","tree form Schneider.CSV");
    t6->ReadFile("Schneider.CSV","x/D:y/D:y_coordinate/D");
    t6->Draw("y_coordinate:x","","goff");
    TGraph *g6=new TGraph(t6->GetSelectedRows(),t6->GetV2(),t6->GetV1());
    g6->SetLineWidth(3);
    g6->SetLineColor(8);
    g6->SetMarkerStyle(23);
    g6->SetMarkerSize(1.5);
    g6->SetMarkerColor(8);

    TTree *t7=new TTree("t7","tree form Yonai.CSV");
    t7->ReadFile("Yonai.CSV","x/D:y/D:y_coordinate/D");
    t7->Draw("y_coordinate:x","","goff");
    TGraph *g7=new TGraph(t7->GetSelectedRows(),t7->GetV2(),t7->GetV1());
    g7->SetLineWidth(3);
    g7->SetLineColor(9);
    g7->SetMarkerStyle(29);
    g7->SetMarkerSize(2);
    g7->SetMarkerColor(9);

    TTree *t8=new TTree("t8","tree form upperBounds.CSV");
    t8->ReadFile("upperBounds.CSV","x/D:y/D:y_coordinate/D");
    t8->Draw("y_coordinate:x","","goff");
    TGraph *g8=new TGraph(t8->GetSelectedRows(),t8->GetV2(),t8->GetV1());
    g8->SetLineWidth(5);
    g8->SetLineColorAlpha(kRed,0.35);

    TTree *t9=new TTree("t","tree form lowerBounds.CSV");
    t9->ReadFile("lowerBounds.CSV","x/D:y/D:y_coordinate/D");
    t9->Draw("y_coordinate:x","","goff");
    TGraph *g9=new TGraph(t9->GetSelectedRows(),t9->GetV2(),t9->GetV1());
    g9->SetLineWidth(5);
    g9->SetLineColorAlpha(kRed,0.35);

    TTree *t10=new TTree("t10","tree form Zheng.CSV");
    t10->ReadFile("Zheng.CSV","x/D:y/D:y_coordinate/D");
    t10->Draw("y_coordinate:x","","goff");
    TGraph *g10=new TGraph(t10->GetSelectedRows(),t10->GetV2(),t10->GetV1());
    g10->SetLineWidth(3);
    g10->SetLineColor(kYellow+1);
    g10->SetMarkerStyle(49);
    g10->SetMarkerSize(1.5);
    g10->SetMarkerColor(kYellow+1);

    gPad->SetLogy();
    TMultiGraph *mgp=new TMultiGraph();
    mgp->Add(g8,"c");
    mgp->Add(g9,"c");    
    mgp->Add(g1,"c");
   // mgp->Add(g4,"c");
    mgp->Add(g10,"pl");
    mgp->Add(g2,"pl");    
    mgp->Add(g3,"pl");
    mgp->Add(g4,"pl");
    mgp->Add(g5,"pl");
    mgp->Add(g6,"pl");    
    mgp->Add(g7,"pl");
    mgp->Add(gr1,"pl");
    mgp->GetXaxis()->SetRangeUser(0,80);
    mgp->GetYaxis()->SetRangeUser(1e-2,1000);
    mgp->Draw("a");
    mgp->GetXaxis()->SetTitle("Distance From Field Edge (cm)");
    //mgp->GetXaxis()->SetTitle("\\hbox{与射野边缘的距离} (cm)");

    mgp->GetXaxis()->CenterTitle(true);
    mgp->GetYaxis()->SetTitle("H/D (mSv/Gy)");
    mgp->GetYaxis()->CenterTitle(true);
    TLegend *leg;
    leg=new TLegend(0.6,0.5,0.8,0.8);
    leg->AddEntry(g8,"Upper Bounds","l");
    leg->AddEntry(g9,"Lower Bounds","l");
    leg->AddEntry(g1,"Proton -Yan et al","l");
   // leg->AddEntry(g2,"Wroe et al","pl");
   // leg->AddEntry(g3,"Mesoloras et al","pl");
   // leg->AddEntry(g4,"Zacharatou Jarlskog et al","l");
    leg->AddEntry(g10,"Proton -Zheng et al","pl");
    leg->AddEntry(g5,"Proton -Polf et al","pl");
    leg->AddEntry(g6,"Proton scanning","pl");
    leg->AddEntry(g6,"-Schneider et al","");
    leg->AddEntry(g7,"Carbon -Yonai et al","pl");
    leg->AddEntry(gr1,"Carbon -This Work","pl");
    leg->AddEntry(g3,"Alloy","pl");
    leg->AddEntry(g4,"Iron","pl");
    leg->AddEntry(g2,"Watertank","pl");
    //leg->AddEntry(f1,"Power law fit","l");
    leg->SetTextSize(0.03);
    leg->Draw();
}