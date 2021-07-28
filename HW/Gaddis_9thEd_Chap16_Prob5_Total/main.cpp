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
temp total (int a) {
    temp input, sum=0;
    for (int i=0;i<a;i++) {
        cout<<"Enter value: ";
        cin>>input;
        sum+=input;
    }
    cout<<"Total is: "<<sum<<endl<<endl;
    //return sum;
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int a;
    
    cout<<"Enter number of int values to sum: ";
    cin>>a;
    total<int>(a);
    
    cout<<"Enter number of float values to sum: ";
    cin>>a;
    total<float>(a);
    
    //Exit stage right!
    return 0;
}