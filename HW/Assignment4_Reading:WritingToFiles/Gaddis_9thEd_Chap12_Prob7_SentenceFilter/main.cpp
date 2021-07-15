/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 12, 2021, 12:19 PM
 * Purpose:  Sentence filter problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    char inName[SIZE];
    char outName[SIZE];
    char data;
    
    ifstream infile;
    fstream outfile;
    
    //Process/Map inputs to outputs
    cout<<"Enter file name to open (input.dat).\n";
    cin>>inName;
    infile.open(inName);
    
    cout<<"Enter file name to send data to.\n";
    cin>>outName;
    outfile.open(outName, ios::out); //creating output file
    
    if (infile){
        infile.get(data);
        outfile.put(toupper(data));
        while (infile) {
            infile.get(data);
            outfile.put(tolower(data));
        }
    }
    
    infile.close();
    outfile.close();
    
    //Output data
    
    //Exit stage right!
    return 0;
}