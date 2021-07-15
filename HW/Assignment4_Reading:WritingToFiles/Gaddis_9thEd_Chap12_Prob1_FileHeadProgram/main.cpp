/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 12, 2021, 12:19 PM
 * Purpose:  Binary File Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    ifstream inFile;
    string filenm, inpdata;
    unsigned int count=1;
    
    cout<<"Please enter the name of the file '9lines.dat' or '10lines.dat': "<<endl;
    cin>>filenm;
    
    inFile.open(filenm.c_str(), ios::in);
    
    if (inFile) {
    getline(inFile, inpdata);

        while (inFile) {
            cout<<inpdata<<endl;
            getline(inFile, inpdata);
            count++;
        }
    if (count<=10) {
        cout<<"The entire file was displayed!\n";
    }
    inFile.close();
    
    }
    
    else {
        cout<<"Cannot open file!\n";
    }
    return 0;
}