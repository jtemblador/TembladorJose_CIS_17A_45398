/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 24, 2021, 8:00 PM
 * Purpose:  celsius to fahrenheit converter 
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
    
    //Declare Variables
    unsigned int temp;
    //Initialize Variables
    
    //Process/Map inputs to outputs
    cout<<"Enter a temperature to convert to Fahrenheit.\n";
    cin>>temp;
    //Output data
    cout<<temp<<" Celsius converted to Fahrenheit is ";
    cout<<temp*9/5+32;
    //Exit stage right!
    return 0;
}