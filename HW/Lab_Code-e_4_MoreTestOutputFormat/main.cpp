/*
 * Author: Jose Temblador
 * Date: 3/14/2021
 * Purpose: prob 4, code-e assignment
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
const int SIZE=4;
//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    float num;  //Number to be displayed
    //7 characters or less

    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    for (int i=0;i<SIZE;i++){           //initialize for loop
        cin>>num;                       //at beginning of each loop, num is inputted
        cout<<setw(9) <<setprecision(0)<<num;
        cout<<setw(10)<<setprecision(1)<<fixed<<num;
        if (i==SIZE-1)cout<<setw(10)<<setprecision(2)<<fixed<<num;      //does not print out endl if it's the last line
        else cout<<setw(10)<<setprecision(2)<<fixed<<num<<endl;
    }
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}