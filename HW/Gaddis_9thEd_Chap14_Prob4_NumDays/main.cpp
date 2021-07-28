/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on July 25, 2021, 10:50 AM
 * Purpose:  NumDays Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>
#include <iomanip>
#include "NumDays.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int one, two;
    
    cout<<"Enter amount of hours worked for the first day: ";
    cin>>one;
    cout<<"Enter amount of hours worked for the second day: ";
    cin>>two;
    
    NumDays a(one), b(two);
    cout<<"Work days for first day: "<<a.getDays()<<" and Hours : "<<a.getHrs()<<endl;
    cout<<"Work days for second day: "<<b.getDays()<<" and Hours : "<<b.getHrs()<<endl;
    
    //Adding Up days that were worked
    NumDays c= a+b;
    cout<<"Total work days worked: "<<c.getDays()<<" and Hours : "<<c.getHrs()<<endl;
    
    //Subtracting days that were worked
    c= a-b;
    cout<<"Difference of days worked: "<<abs(c.getDays())<<" and Hours : "<<c.getHrs()<<endl;
    
    //Using post incrementing operator
    NumDays d=c++;
    cout<<"Post incrementing total days worked: "<<d.getDays()<<" and Hours : "<<d.getHrs()<<endl;
    
    //Using pre incrementing operator
    d=++c;
    cout<<"Pre incrementing total days worked: "<<d.getDays()<<" and Hours : "<<d.getHrs()<<endl;
    
    //Using post decrementing operator
    d=c--;
    cout<<"Post decrementing total days worked: "<<d.getDays()<<" and Hours : "<<d.getHrs()<<endl;
    
    //Using pre decrementing operator
    d=--c;
    cout<<"Pre decrementing total days worked: "<<d.getDays()<<" and Hours : "<<d.getHrs()<<endl;

    //Exit stage right!
    return 0;
}