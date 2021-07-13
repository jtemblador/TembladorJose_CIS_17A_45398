/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 12, 2021, 8:20 PM
 * Purpose:  Corporate sales output program
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const unsigned int SIZE=4;

struct SalesData {
    string dvname;       //division name North, South, East, West
    char qrtr[SIZE];     //Quarter 1, 2, 3, 4
    float qrtrsls[SIZE]; //sales of each quarter
};

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
    fstream fileOut;   //Creating file for output 
    fileOut.open("SalesData.dat", ios::out); //opens file for output
    for (int i=0;i<SIZE;i++) {
        fileOut<<qrtnme[i].dvname<<" Division Sales Report:\n"; //reads out data in
        for(int j=0;j<SIZE;j++) {                               //same order it's read in
            fileOut<<"Quarter "<<static_cast<int>(qrtnme[i].qrtr[j])
                <<" Sales: "<<qrtnme[i].qrtrsls[j]<<endl;
        }
        fileOut<<endl;
    }
    fileOut.close();    //close file
}

void DataIn(SalesData qrtnme[], const unsigned int SIZE) {
    string nwes[4] = {"North", "West", "East", "South"};
    
    for (int i=0;i<SIZE; i++) {
        qrtnme[i].dvname=nwes[i];   //assigns each division its name 
        for (int j=0;j<SIZE;j++) {
            qrtnme[i].qrtr[j]=j+1; //starts at quarter 1
            cout<<"Enter quarter "<<static_cast<int>(qrtnme[i].qrtr[j])
                <<" sales for "<<qrtnme[i].dvname<<" Division:\n";
            cin>>qrtnme[i].qrtrsls[j]; //loops until all sales for each quarter 
        }                              //have been inputted
    }
}