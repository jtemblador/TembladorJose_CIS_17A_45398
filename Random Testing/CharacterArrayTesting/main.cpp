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
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    char a[4]={0,1,2,3};
    int num=0;
    
    for (int i=4;i<0;i--) {
        num=num+static_cast<int>(a[i])*10;
        //cout<<static_cast<int>(a[i])<<endl;
    }
    cout<<num<<endl;
    
    return 0;
}