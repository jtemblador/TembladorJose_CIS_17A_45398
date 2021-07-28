/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include "Numbers.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int n;
    
    cout<<"Enter 4 digit number between 1-9999 to convert: ";
    cin>>n;
    
    if (n>0&&n<=9999) {
        Numbers convert(n);
        convert.Print();
    }
    else cout<<"Integer must be positive and within 1-9999.\n";
    
    //Exit stage right!
    return 0;
}