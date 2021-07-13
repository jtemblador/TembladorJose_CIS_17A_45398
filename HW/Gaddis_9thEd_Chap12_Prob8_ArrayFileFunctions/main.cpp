/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 12, 2021, 12:19 PM
 * Purpose:  Binary File Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void arrayToFile(string, int *, int );
void fileToArray(string, int *, int );

//Execution Begins Here
int main(int argc, char** argv) {
    
    const int SIZE=5;
    string fileNme= "RandomNumbers.dat";
    int a2f[SIZE], f2a[SIZE];
    
    
    arrayToFile(fileNme, a2f, SIZE);
    //Output data
    fileToArray(fileNme, f2a, SIZE);
    //Exit stage right!
    cout<<"Run Complete!";
    return 0;
}

void arrayToFile(string fileNme, int *a2f, int SIZE) {
    //filling the array with random numbers [1-1000]
    srand(static_cast<int>(time(0)));
    ofstream outFile;
    outFile.open(fileNme.c_str(), ios::binary|ios::out);    //open file for binary input
    
    for (int i=0; i<SIZE; i++) {
        a2f[i]=rand()%100+1;   //filling array
        outFile<<a2f[i]<<endl;  //filling file
    }
    
    cout<<"Random numbers read into RandomNumbers.dat\n";
    for (int i=0; i<SIZE; i++) {
        cout<<a2f[i]<<endl;  //reading array to user
    }
    outFile.close();
}

void fileToArray(string fileNme, int *f2a, int SIZE) {
    ifstream inFile;
    inFile.open(fileNme.c_str(), ios::binary|ios::in);
    
    cout<<"Numbers read from RandomNumbers.dat\n";
    for(int i=0;i<SIZE;i++) {
        inFile>>f2a[i];
        cout<<f2a[i]<<endl;
    }
    inFile.close();
}