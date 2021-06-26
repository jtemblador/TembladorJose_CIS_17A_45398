/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 25, 2021, 9:33 PM
 * Purpose:  searching for a string (binary search and linear search)
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>    //String Library
using namespace std;

//User Libraries

//Global Constants
const int numNms = 20;
//Math, Science, Universal, Conversions, High Dimensioned Arrays
//Function Prototypes
void selcSrt(string [], int);
int binSrch(string [], int ,string );

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    //Declare Variables
    string names[numNms] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill",
                            "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                            "James, Jean", "Weaver, Jim", "Pore, Bob",
                            "Rutherford, Greg", "Javens, Renee",
                            "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth" };
    string srchnm = "Looney, Joe"; //name to search for
    int posn;   //position name was found at
    
    //Initialize Variables
    selcSrt(names, numNms); //sorting names
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Searching for "<<srchnm<<endl;
    posn = binSrch(names,numNms, srchnm); //binary search to search name, returns position
    
    if (posn==-1){
        cout<<srchnm<<" was not found.\n";
    } else 
        cout<<srchnm<<" found at position "<<posn<<endl;
    
    //Exit stage right!
    return 0;
}

void selcSrt(string a[], int n){
    for(int i=0;i<n-1;i++){      //Loop for each position in List
        int idxMin=i;
        for(int j=i+1;j<n;j++){  //Loop to swap with first in List
            if(a[idxMin]>a[j]){  //Put the smallest at top of List
                idxMin=j;
            }
        }
        string temp=a[i];
        a[i]=a[idxMin];
        a[idxMin]=temp;
    }
}

int binSrch(string a[],int n,string val){
    int first = 0,      //first array element
        last  = n-1,    //last array element
        middle,         //middle array element
        position = -1;  //position of middle value
    bool found =false;  //flag
    
    while (!found && first<=last){
        middle = (first+last)/2;//calculate midpoint
        if (a[middle]==val){
            found=true;
            position=middle;
        }
        else if (a[middle] > val)
            last = middle-1;    //if value is in lower half
        else 
            first = middle+1;   //if value is in upper half
    }
    return position;
}