/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 24, 2021, 9:33 PM
 * Purpose:  calculating population of organisms
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float PCTCNV=100;
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    //Declare Variables
    float pct,    //percent 
          orgnsm, //organisms
          days;   //days
    
    //Initialize Variables
    orgnsm=10;      //number of organisms to start
    pct=5/PCTCNV;   //Divide by 100 to get percentage
    days=5;         //number of days
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Enter how many organisms to start with, daily population "
          "increase as a percentage, and number of days.\n";
    
    for (int i=0; i<days; i++){
        cout<<"At day "<<i+1<<" there are "<<static_cast<int>(orgnsm)<<".\n";
        orgnsm+=orgnsm*pct;
    }
    
    //Exit stage right!
    return 0;
}