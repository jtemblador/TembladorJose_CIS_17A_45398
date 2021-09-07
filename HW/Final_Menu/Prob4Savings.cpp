/* 
 * File:   Savings.cpp
 * Author: mac
 *
 * Created on July 30, 2021, 2:11 PM
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Prob4Savings.h"
using namespace std;

SavingsAccount::SavingsAccount(float num) {
    if(num>0) balance=num;
    else balance=0;
    FreqDeposit=0;
    FreqWithDraw=0;
}

void SavingsAccount::Transaction(float num) {
    if(num>0)Deposit(num);
    else Withdraw(num);
}

float SavingsAccount::Deposit(float num) {
    balance+=num;
    FreqDeposit++;
    return balance;
}

float SavingsAccount::Withdraw(float num) {
    if(num<balance) {
        balance-=num;
        FreqWithDraw++;
    }
    else cout<<"Withdraw not Allowed"<<endl;
    return balance;
}

void SavingsAccount::toString(){
    cout<<"Balance = $"<<balance<<endl;
    cout<<"Withdraws = "<<FreqWithDraw<<endl;
    cout<<"Deposit = "<<FreqDeposit<<endl;
}

float SavingsAccount::Total(float savint, int time){
    float tot=0;
    for(int i=0;i<time;i++)
        tot=(tot+(balance*(0.1+savint)));
    return tot;
//    return balance*exp(time*log(1+savint));

}

float SavingsAccount::TotalRecursive(float savint, int time) {
    if (time<=0) return balance;
    return TotalRecursive(savint, time-1)*(1+savint);
}