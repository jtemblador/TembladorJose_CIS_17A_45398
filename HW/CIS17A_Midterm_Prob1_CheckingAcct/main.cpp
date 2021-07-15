/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
struct CustInf {
    int acctnum;    //account number
    string name;    //customer name
    string addrs;   //address
    float bal;      //Balance of account at the beginning of the month
    float *numchks;  //number of checks inputted by user
    float numdeps;  //number of checks deposited by user 
    
};
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void getData(CustInf *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    unsigned int size;
    
    cout<<"How many users will input their account information?"<<endl;
    cin>>size;
    CustInf *cstmer= new CustInf[size]; //dynamically creating size of structure
    
    for (int i=0;i<size;i++) {
        getData(cstmer, i);     //repeats for as many users there are
    }
    
    //Exit stage right!
    return 0;
}

void getData(CustInf *cstmer, int i) {
    
    cout<<"Please enter the Account Number:"<<endl;
    cin>>cstmer[i].acctnum;
    
    cout<<"Please your name: "<<endl;
    cin.ignore();
    getline(cin, cstmer[i].name);
    
    cout<<"Please your Address: "<<endl;
    cin>>cstmer[i].addrs;
    
    unsigned int numchks;
    cout<<"Please enter amount of checks: "<<endl;
    cin>>numchks;
    cstmer[i].numchks=new float [numchks];
    
    unsigned int numdeps;
    cout<<"Please enter amount of deposits: "<<endl;
    cin>>numdeps;
    cstmer[i].numdeps=*new float [numdeps];
    
    for (int j=0; j<numchks; j++) {
        cstmer[i].numchks[j]=j;
        cout<<cstmer[i].numchks[j]<<endl;
    }
}