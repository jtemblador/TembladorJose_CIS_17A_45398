/* 
 * File:   Numbers.cpp
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 2:07 AM
 */
#include <iostream>  //I/O Library
#include <cstdlib>
#include "Numbers.h"

using namespace std;

void Numbers::Print() {
    string lssthn20[20]= {"Zero","One","Two","Three","Four","Five","Six","Seven",
                          "Eight","Nine","Ten","Eleven","Twelve","Thirteen",
                          "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen",
                          "Nineteen"};
    string tens[10]=     {"Zero","Ten","Twenty","Thirty","Forty",
                          "Fifty","Sixty","Seventy","Eighty","Ninety"};
    string hun = " Hundred ";
    string thou = " Thousand ";
    unsigned int n1000s,n100s,n10s,n1s;
    n1000s=number/1000;   //Shift 3 places to the left
    n100s=number%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=number%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=number%10;
    
    if (n1000s>0){
        cout<<lssthn20[n1000s]<<thou;
    }
    if (n100s>0) {
        cout<<lssthn20[n100s]<<hun;
    }
    if (n10s==1) 
        cout<<lssthn20[n1s+10]<<" ";
    else 
        if (n10s>0) {
            cout<<tens[n10s]<<" ";
            if (n1s>0) {
                cout<<lssthn20[n1s];
            }
            
        }
        else cout<<lssthn20[n1s];
    
    
}