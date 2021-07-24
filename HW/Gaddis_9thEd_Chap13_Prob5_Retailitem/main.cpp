/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on July 23, 2021, 10:50 AM
 * Purpose:  Patient Information
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include "Info.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {    
    //Declare Variables
    Retail item[3];
    
    item[0].setItem("Jacket");
    item[0].setPrice(59.95);
    item[0].setUnits(12);
    
    item[1].setItem("Designer Jeans");
    item[1].setPrice(34.95);
    item[1].setUnits(40);
    
    item[2].setItem("Shirt");
    item[2].setPrice(24.95);
    item[2].setUnits(20);
    
    
    cout<<"        Description     Units  Price"<<endl;
    for (int i=0; i<3; i++) {
        cout<<"Item #"<<i+1<<" "<<left<<setw(16)<<item[i].getItem()<<setw(7)
            <<item[i].getUnits()<<item[i].getPrice()<<endl;
    }
    
    //Output data
    
    //Exit stage right!
    return 0;
}