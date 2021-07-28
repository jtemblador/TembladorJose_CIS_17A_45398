/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include "Inventory.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    //Declare Variables
    int itm, quant;
    float cost, ttlCost;
    
    //Entering item number
    cout<<"Enter item number:   ";
    cin>>itm;
    
    //Entering item quantity
    cout<<"Enter item quantity: ";
    cin>>quant;
    
    //Entering item cost
    cout<<"Enter item cost:     ";
    cin>>cost;
    
    cout<<endl;
    if (itm<0||quant<0||cost<0) {
        cout<<"Only positive numbers can be accepted."<<endl;
    }
    else {
        Inventory invnt(itm, quant, cost);
        cout<<fixed<<setprecision(2);
        cout<<"Item number:   "<<invnt.getItemNum()<<endl;
        cout<<"Item quantity: "<<invnt.getQnt()<<endl;
        cout<<"Item cost:     "<<invnt.getCst()<<endl;
        cout<<"Total cost :   "<<invnt.getTtlCost()<<endl;
    }
    //Output data
    
    //Exit stage right!
    return 0;
}