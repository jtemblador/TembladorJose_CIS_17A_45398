/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  Gaddis Chapter 15 Problem 4
 */

//System Libraries
#include <iostream>  //I/O Library
#include "MilTime.h"
#include "Time.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int hr, sec;
    
    //Initialize Variables
    hr=22;
    sec=55;
    
    if (hr<0||hr>2359||sec<0||sec>59) {
        cout<<"Please enter a valid time.\n";
    }
    else {
        MilTime a(hr, sec);
        cout<<"Military Time: "<<a.getMilHr()<<":"<<a.getMilSec()<<endl;
        cout<<"Standard Time: "<<a.get12Hr()<<":"<<a.getMilSec();
        a.getMilHr()>12? cout<<"PM":cout<<"AM";
        cout<<endl;

    }
    //Process/Map inputs to outputs

    //Output data
    
    //Exit stage right!
    return 0;
}