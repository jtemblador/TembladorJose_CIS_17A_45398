/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include "Prob2Sort.h"
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    
    char *ch2=new char[10*16];
    char *ch2p=ch2; 
    while(infile.get(*ch2)){
        cout<<*ch2;ch2++;
    } 
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column ";
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending); 
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
        } 
    }
    
    delete []zc;
    cout<<endl;
    
    //Exit stage right!
    return 0;
}