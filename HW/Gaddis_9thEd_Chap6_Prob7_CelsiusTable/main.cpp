/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 24, 2021, 9:33 PM
 * Purpose:  calculating fahrenheit to celsius
 *           printing out a table of fahrenheit
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void Fah2Cel(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    //Declare Variables
    int tempF;
    
    //Initialize Variables
    tempF=80;   //40 degrees fahrenheit
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Input a temperature in Fahrenheit to convert to Celsius.\n";
    Fah2Cel(tempF);
    
    cout<<"Temperature from 0 degrees Fahrenheit to 20 degrees Fahrenheit"
          "Converted to Celsius.\n";
    for(int i=0;i<=20;i++) Fah2Cel(i);
    
    //Exit stage right!
    return 0;
}

void Fah2Cel(int a) {
    cout<<a<<" Fahrenheit is "<<5*(a-32)/9<<" Celsius.\n";
    return;
}