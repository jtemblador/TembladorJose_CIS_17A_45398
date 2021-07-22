/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2019, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <iomanip>
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
int *copy(const int *,int); //Copy the Array
int *mode(const int *,int); //Find the mode set
float median(int *,int, int);   //Fill the median Array with the Float array size, 
                            //the median, and the integer array data
float mean(int *,int);
void prntMea(float);
void prntMed(float , int, int); //Print the median Array

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Original Array"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the average of the array
    float meanum=mean(ary, arySize);
    prntMea(meanum);
    
    //Print the median 
    float medary=median(ary, arySize, modNum);
    prntMed(medary, arySize, modNum);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes      = "<<
            ary[0]<<endl;
    cout<<"The max Frequency        = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void prntMed(float medary, int size, int modNum){     //Print the median Array
    cout<<"The median of the array  = ";
    cout<<static_cast<float>(medary/modNum)<<" "<<endl;
}

void prntMea(float a) {
    cout<<"The average of the array = ";
    cout<<a<<endl;
}

float mean(int *array, int size) {
    float menum=0;
    for (int i=0; i<size; i++) {
        menum+=array[i];
    }
    return menum/size;
}


float median(int *array, int size, int modNum){  //Fill the median Array with the Float array size, the median, and the integer array data
    float med=0;
    if (modNum>=10) {
        med=40;
    }
    else {
        for (int i=0;i<modNum;i++){
            med+=array[i];   
        }
        //med/=modNum;
    }

    return med;
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
//    mrkSort(ary,arySize);
    //Find the max Frequency
    int maxfreq=0;
    int curfreq=0;
    int modes=0;
    for (int i=0; i<=9; i++) {
        for (int j=0; j<arySize; j++) {
            if (i==*(array+j)) {
                curfreq++;
            }
            if (curfreq>maxfreq) maxfreq=curfreq;
        }
        if (curfreq==1) { }
        else if (curfreq==maxfreq) {
            modes++;
            
        }
        curfreq=0; 
    }
    //Find the number of modes
    
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=modes;
    int *modeAry=new int[nmodes+2];
    //Finding individual numbers and inputting them into array
    maxfreq=0;
    curfreq=0;
    modes=0;
    int index=2;
    for (int i=0; i<=9; i++) {
        for (int j=0; j<arySize; j++) {
            if (i==*(array+j)) {
                curfreq++;
            }
            if (curfreq>maxfreq) maxfreq=curfreq;
        }
        if (curfreq==1) { }
        else if (curfreq==maxfreq) {
            modes++;
            modeAry[index]=i;
            index++;
        }
        curfreq=0; 
    }
    
    modeAry[0]=modes;//Stub returns no modes
    modeAry[1]=maxfreq;//Stub returns Frequency 1
    
    
    //Fill the mode array

    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}