/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries
struct CustInf {
    int acctnum;    //account number
    string name;    //customer name
    string addrs;   //address
    float bal;      //Balance of account at the beginning of the month
    float *numchks;  //number of checks inputted by user
    float *numdeps;  //number of checks deposited by user 
};
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void getData(CustInf &, unsigned int &, unsigned int &);
void ChksDps(CustInf &, unsigned int ,  unsigned int);
void prtData(CustInf, unsigned int );

//Execution Begins Here
int main(int argc, char** argv) {
    CustInf cstmer;
    unsigned int numchks;
    unsigned int numdeps;
    
    getData(cstmer, numchks, numdeps);     //repeats for as many users there are
    
    ChksDps(cstmer, numchks, numdeps);
    
    prtData(cstmer, numchks); 
    
    //Exit stage right!
    return 0;
}

void prtData(CustInf cstmer, unsigned int numchks) {
    float sumchks=0;    //sum of all the checks 
    for (int i=0;i<numchks;i++) {   
        sumchks+=cstmer.numchks[i];//adds all the checks up
    }
    
    cout<<"     Account Number: "<<cstmer.acctnum<<endl;
    cout<<"          Your Name: "<<cstmer.name<<endl;
    cout<<"            Address: "<<cstmer.addrs<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"New Account Balance: $"<<cstmer.bal-sumchks<<endl;
    if (sumchks>cstmer.bal) {
        cout<<endl<<"You're account is overdrawn!\n";
        cout<<"A $50.00 overdraft fee will be charged to your account.\n";
        cout<<"New Account Balance: $"<<cstmer.bal-sumchks-50.00<<endl;
    } 
    
}


void ChksDps(CustInf &cstmer, unsigned int numchks, unsigned int numdeps) {
    cstmer.numchks=new float [numchks]; //creates dynamic array of number of checks
    cstmer.numdeps=new float [numdeps]; //creates dynamic array of number of deposits
    //Entering amount of each check
    for (int i=0; i<numchks; i++) {
        cout<<"Enter amount of check "<<i+1<<": ";
        cin>>cstmer.numchks[i];
    }
    cout<<endl;

    //Entering amount of each deposit
    for (int i=0; i<numdeps; i++) {
        cout<<"Enter amount of deposit "<<i+1<<": ";
        cin>>cstmer.numdeps[i];
        cstmer.bal+=cstmer.numdeps[i];  //adds each deposit to balance
    }
    cout<<endl;
}


void getData(CustInf &cstmer, unsigned int &numchks, unsigned int &numdeps) {
        //User inputs account number
    cout<<"Please enter the 5 digit Account Number:"<<endl;
    cin>>cstmer.acctnum;
    if ((cstmer.acctnum/10000)<1||(cstmer.acctnum/10000)>10) { //only accept 
        cout<<"Account number must be 5 digits!\n";            //5 digit number
        exit (1);
    }
    //User inputs their name
    cout<<"Please your name: "<<endl;   
    cin.ignore();
    getline(cin, cstmer.name);
    
    //User inputs address
    cout<<"Please your Address: "<<endl;
    cin.ignore();
    getline(cin, cstmer.addrs);
    
    //User inputs balance of account    
    cout<<"Please enter the balance of your account: "<<endl;
    cin>>cstmer.bal;
    
    //User inputs number of checks    
    cout<<"Please enter amount of checks: "<<endl;
    cin>>numchks;
    
    //User inputs number of checks    
    cout<<"Please enter amount of deposits: "<<endl;
    cin>>numdeps;
}