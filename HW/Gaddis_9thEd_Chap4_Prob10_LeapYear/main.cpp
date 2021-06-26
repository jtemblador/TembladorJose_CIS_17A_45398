/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 24, 2021, 8:05 PM
 * Purpose:  determining leap years
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
    unsigned int year,month, days=0;
    
    //Initialize Variables
    
    
    //Process/Map inputs to outputs
    cout<<"Enter a month.\n";
    cin>>month;
    cout<<"Enter a year.\n";
    cin>>year;
    days= month==1?  31:
          month==2?  28:
          month==3?  31:
          month==4?  30:
          month==5?  31:
          month==6?  30:
          month==7?  31:
          month==8?  31:
          month==9?  30:
          month==10? 31:
          month==11? 30:31;
          
    if (year%100==0&&year%400==0) days+=1;
    else if (year%4==0) days+=1;
    
    //Output data
    cout<<days<<" days.\n";
    //Exit stage right!
    return 0;
}