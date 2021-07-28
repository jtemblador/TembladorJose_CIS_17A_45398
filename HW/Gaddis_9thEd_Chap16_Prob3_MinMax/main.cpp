/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose: Gaddis Chapter 16 Problem 4 - Min/Max template
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//template to return min value
template <class temp>
temp min (int a, int b) {
    if (a<b) return a;
    else return b;
}

//template to return max value
template <class temp>
temp max (int a, int b) {
    if (a>b) return a;
    else return b;
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int a, b;
    
    //Initialize Variables
    a=4;
    b=5;
    //Process/Map inputs to outputs
    cout<<"Min Value: "<<min(a, b)<<endl;
    cout<<"Max Value: "<<max(a,b);
    //Output data
    
    //Exit stage right!
    return 0;
}