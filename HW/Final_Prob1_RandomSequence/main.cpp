/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include "Prob1Random.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    
    for(int i=1;i<=ntimes;i++){
        a.randFromSet(); 
    }
    int *x=a.getFreq(); 
    char *y=a.getSet();
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    //Exit stage right!
    return 0;
}