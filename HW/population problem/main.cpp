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

//Global Constants
const int PCTCVT=100;
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    //Declare Variables
    float pct;
    int org, days;
    
    //Initialize Variables
    pct=5/PCTCVT;
    org=5;
    days=5;
    //Process/Map inputs to outputs
    
    //Output data
    for (int i=0; i<days; i++){
        cout<<"At day "<<i+1<<" there are "<<org<<".\n";
        org=org+(org*pct);
    }
    //Exit stage right!
    return 0;
}