/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 24, 2021, 8:05 PM
 * Purpose:  currency conversion
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    //Declare Variables
    float dol, yen, euros;
    
    //Initialize Variables
    yen  =110.88;
    euros=0.84;
    
    //Process/Map inputs to outputs
    cout<<"Enter a dollar amount to convert to Yen and Euros.\n";
    cin>>dol;
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<dol<<" Dollars converted to Yen is   "<<dol*yen<<endl;
    cout<<dol<<" Dollars converted to Euros is "<<dol*euros;
    //Exit stage right!
    return 0;
}