/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include "DayofYear.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int a;
    
    cout<<"Enter a number between 1-365: ";
    cin>>a;
    
    DayofYear cnvt(a);
    cnvt.Print();
    
    //Exit stage right!
    return 0;
}