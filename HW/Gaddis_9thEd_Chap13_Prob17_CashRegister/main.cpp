/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include "Inventory.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number function
    
    //Declare Variables
    const int NUMITMS=3;
    int a, b;
    
    Inventory invnt[NUMITMS]= { Inventory(1, 8,  4.50), 
                                Inventory(2, 5,  8.99),
                                Inventory(3, 10, 7.99) };
    
    for (int i=0; i<NUMITMS; i++)
        invnt[i].printItems(); cout<<endl;
    
    cout<<"Enter item you would like to purchase: ";
    cin>>a;
    a--;
    
    cout<<"Enter quantity you would like to purchase: ";
    cin>>b;
    
    CashRegister tran;
    
    cout<<invnt[a].getQnt()<<endl;
    if ((a>=0&&a<NUMITMS+1)&&(b>=0&&b<(invnt[a].getQnt()+1))) {
        cout<<fixed<<setprecision(2);
        cout<<"The cost of that item is $"<<invnt[a].getCst()<<endl;
        cout<<"The price of each item is $"<<tran.getPrice(invnt[a].getCst())<<endl;
        cout<<"Subtotal of transaction: $"<<tran.getSubTtl(b)<<endl;
        cout<<"Adding 6% sales tax, the total amount is: $"<<tran.getTtl()<<endl;
        
        float onHand;
        cout<<"\nEnter amount you paying with. ";
        cin>>onHand;
        if (onHand>tran.getTtl())
            cout<<"\nYour change is $"<<onHand-tran.getTtl()<<endl;
        else cout<<"\nYou don't have enough money!"<<endl;
    }
    else cout<<"\nInvald item number or we've run out of that item!\n";
    
    
    //Exit stage right!
    return 0;
}