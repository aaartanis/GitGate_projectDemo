#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    int a =10;
    float b=9.0;
    ofstream dataFile;
    dataFile.open("dataFile.txt",ofstream::app);//追加的方式
    
    dataFile <<"name"<<"\t"<<"0-15MeV"<<"\t"<<"15--MeV"<<"\t"<<"tot_sum"<<\
    "\t"<<"contribution" <<endl;
    dataFile << 18 <<"\t"<< 200<< "\t"<<800<<"\t"<<"1000"<<"\t"<<"百分2000"<<"\n";
    //<< "\t" << " "<< b<< "\n";
       // << b <<endl;

    dataFile.close();
   


}