/* 
 * File:   Ga9EdC11P3
 * Author: Jose Temblador
 * Created on: July 11, 2021 6:45PM
 * Purpose:  Assignment 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

//User Libraries
const int NUMQRTS = 4;

struct Company {
    string divnme;
    float qrtr[NUMQRTS];
    float qrtsls;
    float annsls;
    
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    Company loc[NUMQRTS]; 
    string nsew[NUMQRTS] = {"North", "West", "East", "South"};
    for (int i=0;i<NUMQRTS;i++) {
        loc[i].divnme=nsew[i];
        cout<<loc[i].divnme<<endl;
        cout<<"Enter first-quarter sales:\n";
        cin>>loc[i].qrtr[0];
        cout<<"Enter second-quarter sales:\n";
        cin>>loc[i].qrtr[1];
        cout<<"Enter third-quarter sales:\n";
        cin>>loc[i].qrtr[2];
        cout<<"Enter fourth-quarter sales:\n";
        cin>>loc[i].qrtr[3];
        int j=0;
        while (j<NUMQRTS) {
            loc[i].annsls+=loc[i].qrtr[j];
            j++;
        };
        cout<<fixed<<setprecision(2);
        cout<<"Total Annual sales:$"<<loc[i].annsls<<endl;
        cout<<"Average Quarterly Sales:$"<<loc[i].annsls/4;
        if (i+1!=4) cout<<endl;
        
    }
    
    //Exit stage right!
    return 0;
}