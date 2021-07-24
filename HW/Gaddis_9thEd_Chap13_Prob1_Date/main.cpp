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
//#include "DateSw.cpp"
#include "DateHeader.h"

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {    
    //Declare Variables
    Date date;
    int day, month, year;
    
    cout<<"Please enter the day, month, and year.\n";
    cout<<"Example 20 5 2021\n";
    cin>>day>>month>>year;
    
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    
    cout<<"The entered date is as follows:\n";
    
    date.PrintDate();
    
    //Output data
    
    //Exit stage right!
    return 0;
}