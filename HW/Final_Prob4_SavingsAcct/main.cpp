/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include "Savings.h"
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++) {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    } 
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = " 
       <<mine.Total((float)(0.10),7)<<endl;
    
    cout<<"Balance after 7 years given 10% interest = " 
    <<mine.TotalRecursive((float)(0.10),7)<<" Recursive Calculation "<<endl;
    //Exit stage right!
    return 0;
}