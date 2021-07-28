/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 26, 2021, 1:24PM
 * Purpose:  Chapter 15 problem 1
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include "ProdWrkr.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void printData(ProdWrkr &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    string name,  date;
    int empnum, shift;
    float rate;
    
    //Declare Variables
    name = "Jose Temblador";
    date = "07/28/1998";
    rate = 12.50;
    empnum = 12345;
    shift = 1;
    
    //Initialize Variables
    ProdWrkr emp1(name, empnum, date, shift, rate);
    ProdWrkr emp2("Jeff Bezos", 56789, "01/12/1964", 2, 192);
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Printing employee data...\n\n";
    printData(emp1);
    printData(emp2);
    //Exit stage right!
    return 0;
}

void printData(ProdWrkr &emp) {
    cout<<"Name: "<<emp.getName()<<endl;
    cout<<"ID Number: "<<emp.getNum()<<endl;
    cout<<"Date Hired: "<<emp.getDate()<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Rate of pay: $"<<emp.getRate()<<" per hour"<<endl;
    emp.getShift()==1? cout<<"Day shift":cout<<"Night Shift";
    cout<<endl<<endl;
}
