/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 12, 2021, 8:20 PM
 * Purpose:  Corporate sales INPUT program
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries
#include "Test.h"

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
//Function Prototypes
void DataIn (SalesData *, const unsigned int );
void DataOut(SalesData *, const unsigned int );

//Execution Begins Here
int main(int argc, char** argv) {
    SalesData qrtnme[SIZE];
    
    DataIn  (qrtnme, SIZE); //Data is read in by the user
    DataOut (qrtnme, SIZE); //Data is read out to a file
    
    cout<<"Run Complete!\n";
    return 0;
}

void DataOut(SalesData qrtnme[], const unsigned int SIZE) {
    float yrsls=0, hidiv=0, lwdiv=10000;
    string hnmdiv, lnmdiv;
    for (int i=0;i<SIZE;i++) {
        float ttlsls=0;
        cout<<setprecision(2)<<fixed;
        cout<<qrtnme[i].dvname<<" Division Sales Report:\n"; //reads out data in
        for(int j=0;j<SIZE;j++) {                            //same order it's read in
            cout<<"Quarter "<<static_cast<int>(qrtnme[i].qrtr[j])
                <<" Sales: "<<setw(7)<<right<<qrtnme[i].qrtrsls[j]<<endl;
            ttlsls+=qrtnme[i].qrtrsls[j];
        }
        yrsls+=ttlsls;
            if (hidiv<ttlsls) {
                hidiv=ttlsls;
                hnmdiv=qrtnme[i].dvname;
            }
            if (lwdiv>ttlsls) {
                lwdiv=ttlsls;
                lnmdiv=qrtnme[i].dvname;
            }
        cout<<setprecision(2)<<fixed;
        cout<<"Total yearly Sales for "<<qrtnme[i].dvname<<" Division: "
            <<setw(10)<<right<<ttlsls<<endl;
        cout<<"Average Quarterly Sales for "<<qrtnme[i].dvname<<" Quarter: "<<ttlsls/4;
        cout<<endl<<endl;
    }
    
    
    cout<<"Highest Grossing Division was "<<hnmdiv<<" Division!"<<endl;
    cout<<"Lowest  Grossing Division was "<<lnmdiv<<" Division!"<<endl;
    cout<<"Total yearly Sales for Company: "<<yrsls<<endl;
}

void DataIn(SalesData qrtnme[], const unsigned int SIZE) {
    string nwes[4] = {"North", "West", "East", "South"};
    ifstream inFile;
    inFile.open("SalesData.dat", ios::in);
    
    for (int i=0;i<SIZE; i++) {
        qrtnme[i].dvname=nwes[i];   //assigns each division its name 
        for (int j=0;j<SIZE;j++) {
            qrtnme[i].qrtr[j]=j+1; //starts at quarter 1
            inFile>>qrtnme[i].qrtrsls[j];    //loops until all sales for each 
            //if (qrtnme[i].qrtrsls[j]<0) { //quarter have been inputted
            //    cout<<"Only positive numbers are allowed for input";
            //    exit(1);
            //}
        }
    }
    inFile.close();
}