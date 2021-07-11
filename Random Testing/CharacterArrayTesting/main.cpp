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
    
    int num=1;
    int *thing=nullptr;
    
    thing=&num;
    
    cout<<" Number is equal to "<<num<<endl;
    cout<<"Address is equal to "<<thing<<endl;
    
    thing+=1;
    
    cout<<" Number is equal to "<<*thing<<endl;

    
    return 0;
}