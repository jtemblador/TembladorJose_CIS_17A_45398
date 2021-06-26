/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 25, 2021, 11:18 PM
 * Purpose:  Reading in file, outputting table of rainy/sunny/clear days
 */

//System Libraries
#include <iostream>  //I/O Library
#include <fstream>   //File Input/Output Library
#include <string>    //String Library
#include <vector>    //Vector library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays
const int NUMMONTH=3; //number of months
const int NUMDAYS=30; //number of days per month
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    //Declare Variables
    string array[NUMMONTH][NUMDAYS]; //3x30 array months x days
    fstream input; //input file
    char readIn;
    string fileName="RainorShine.dat";
    input.open(fileName.c_str(),ios::in);
    int jnRain=0, jnSun=0, jnClr=0,
        jlRain=0, jlSun=0, jlClr=0,
        auRain=0, auSun=0, auClr=0;
    
    //Initialize Variables
    
    
    //Process/Map inputs to outputs
    for (int i=0; i<NUMMONTH; i++){
        for (int j=0; j<NUMDAYS; j++){
            input>>readIn;
            array[i][j]=readIn;
            if (i==0) {
                if (readIn=='R') jnRain++;
                if (readIn=='S') jnSun++;
                if (readIn=='C') jnClr++;
            }
            if (i==1) {
                if (readIn=='R') jlRain++;
                if (readIn=='S') jlSun++;
                if (readIn=='C') jlClr++;
            }
            if (i==2) {
                if (readIn=='R') auRain++;
                if (readIn=='S') auSun++;
                if (readIn=='C') auClr++;
            }
        }
        
    }

/*    for (int i=0; i<NUMMONTH; i++){
        for (int j=0; j<NUMDAYS; j++){
            cout<<array[i][j]<<endl;
        }        
    }
*/
    cout<<"Number of rainy days in June: "<<jnRain<<endl;
    cout<<"Number of sunny days in June: "<<jnSun<<endl;
    cout<<"Number of clear days in June: "<<jnClr<<endl<<endl;
    
    cout<<"Number of rainy days in July: "<<jlRain<<endl;
    cout<<"Number of sunny days in July: "<<jlSun<<endl;
    cout<<"Number of clear days in July: "<<jlClr<<endl<<endl;
    
    cout<<"Number of rainy days in August: "<<auRain<<endl;
    cout<<"Number of sunny days in August: "<<auSun<<endl;
    cout<<"Number of clear days in August: "<<auClr<<endl<<endl;
    
    if (jnRain>auRain&&jnRain>jlRain) cout<<"\nJune had the most amount of rainy days!";
    if (jlRain>auRain&&jlRain>jnRain) cout<<"\nJuly had the most amount of rainy days!";
    if (auRain>jnRain&&auRain>jlRain) cout<<"\nAugust had the most amount of rainy days!";
    
    //Output data
    input.close();

    
    //Exit stage right!
    return 0;
}