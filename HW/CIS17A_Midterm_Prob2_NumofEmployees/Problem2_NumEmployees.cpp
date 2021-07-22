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
#include "Paycheck.h"

//Global Constants
const float RTPAY=10.31;
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void getData(PayCheck *, int);
float payChk(PayCheck *, int);
void prtamnt(PayCheck *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    unsigned int size;  //number of employees
    
    cout<<"How many employees will input their information?"<<endl;
    cin>>size;
    PayCheck *empl= new PayCheck[size]; //dynamically creating size of structure
    
    for (int i=0;i<size;i++) {
        getData(empl, i);     //repeats for as many users there are
        empl[i].pay=payChk(empl, i);
        
        cout<<"     Company: Dr. Lehr's CIS-17A Class\n";
        cout<<"     Address: "<<empl[i].add<<endl;
        cout<<"     Name: "<<setw(14)<<left<<empl[i].name;
        cout<<fixed<<setprecision(2);
        cout<<"Amount: $"<<empl[i].pay<<endl;
        cout<<"     Amount: ";
        prtamnt(empl, i); 
        cout<<endl;    //Prints amount in numbers
        cout<<"     Signature:  ________________________\n\n";
    }
    
    
    //Exit stage right!
    return 0;
}

void prtamnt(PayCheck *empl, int i) {
    unsigned short n2Cnvrt=empl[i].pay;
    unsigned char n1000s,n100s,n10s,n1s;
    n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
    n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=n2Cnvrt%10;        //Remainder of division by 10
    
    cout<<(n1000s==5?"Five Thousand ":
               n1000s==4?"Four Thousand ":
               n1000s==3?"Three Thousand ":
               n1000s==2?"Two Thousand ":
               n1000s==1?"One Thousand ":"");
    
    cout<<(n100s==9?"Nine Hundred ":
               n100s==8?"Eight Hundred ":
               n100s==7?"Seven Hundred ":
               n100s==6?"Six Hundred ":
               n100s==5?"Five Hundred ":
               n100s==4?"Four Hundred ":
               n100s==3?"Three Hundred ":
               n100s==2?"Two Hundred ":
               n100s==1?"One Hundred ":"");
    
    cout<<(n10s==9?"and Ninety ":
               n10s==8?"and Eighty ":
               n10s==7?"and Seventy ":
               n10s==6?"and Sixty ":
               n10s==5?"and Fifty ":
               n10s==4?"and Forty ":
               n10s==3?"and Thirty ":
               n10s==2?"and Twenty ":"and ");
    
    if (n10s==1) {
        cout<<(n1s==9?"Nineteen ":
               n1s==8?"Eighteen ":
               n1s==7?"Seventeen ":
               n1s==6?"Sixteen ":
               n1s==5?"Fifteen ":
               n1s==4?"Fourteen ":
               n1s==3?"Thirteen ":
               n1s==2?"Twelve ":
               n1s==1?"Eleven ":
               n1s==0?"Ten ":"");
    }
    else {
        cout<<(n1s==9?"Nine ":
               n1s==8?"Eight ":
               n1s==7?"Seven ":
               n1s==6?"Six ":
               n1s==5?"Five ":
               n1s==4?"Four ":
               n1s==3?"Three ":
               n1s==2?"Two ":
               n1s==1?"One ":"");
    }
    cout<<"Dollars";
    
    int p2Cnvrt=empl[i].pay*100;  //Shift decimal two places to the left
    unsigned char x10s,x1s;
    x10s=p2Cnvrt%100/10;    //Find Tenth decimal
    x1s=p2Cnvrt%10;         //find hundredth decimal
    
    if (x10s==0&&x1s==0) cout<<"";
    else {
        cout<<" and ";
        cout<<(x10s==9?"Ninety ":
           x10s==8?"Eighty ":
           x10s==7?"Seventy ":
           x10s==6?"Sixty ":
           x10s==5?"Fifty ":
           x10s==4?"Fourty ":
           x10s==3?"Thirty ":
           x10s==2?"Twenty ":"");
        
        if (x10s==1) {
            cout<<(x1s==9?"Nineteen ":
                   x1s==8?"Eighteen ":
                   x1s==7?"Seventeen ":
                   x1s==6?"Sixteen ":
                   x1s==5?"Fifteen ":
                   x1s==4?"Fourteen ":
                   x1s==3?"Thirteen ":
                   x1s==2?"Twelve ":
                   x1s==1?"Eleven ":
                   x1s==0?"Ten ":"");
        }
        else {
            cout<<(x1s==9?"Nine ":
                   x1s==8?"Eight ":
                   x1s==7?"Seven ":
                   x1s==6?"Six ":
                   x1s==5?"Five ":
                   x1s==4?"Four ":
                   x1s==3?"Three ":
                   x1s==2?"Two ":
                   x1s==1?"One ":"");
        }
        cout<<"Cents";
    }    
}

float payChk(PayCheck *empl, int i) {
    float sumpay=0;
    //calculating total paycheck
    sumpay=empl[i].hrs>40? (empl[i].hrs-40)*(RTPAY*3)+(RTPAY*2*19)+(RTPAY*20):
           empl[i].hrs>20? (empl[i].hrs-20)*(RTPAY*2)+(RTPAY*20):
                           (empl[i].hrs)*RTPAY;
    return sumpay;
}

void getData(PayCheck *empl, int i) {
    //Retrieves employee name
    cout<<"Enter name of employee #"<<i+1<<" : "<<endl;
    cin.ignore();
    getline(cin, empl[i].name);
    
    //Retrieves employee address
    cout<<"Enter Address of employee #"<<i+1<<" : "<<endl;
    getline(cin, empl[i].add);
    
    //User enters hours worked
    cout<<"Please enter hours worked: "<<endl;
    cin>>empl[i].hrs;
    if (empl[i].hrs<0) {
        cout<<"Please enter only positive numbers!\n";
        exit(0);
    }
}