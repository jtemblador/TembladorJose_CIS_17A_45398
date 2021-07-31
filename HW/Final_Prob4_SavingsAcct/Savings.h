/* 
 * File:   Savings.h
 * Author: mac
 *
 * Created on July 30, 2021, 2:09 PM
 */

#ifndef SAVINGS_H
#define SAVINGS_H
//using namespace std;    

class SavingsAccount {
    private:
        float Withdraw(float);  //Utility Procedure
        float Deposit(float);   //Utility Procedure
        float balance;          //Property
        int   FreqWithDraw;     //Property
        int   FreqDeposit;      //Property
    public:
        SavingsAccount(float);              //Constructor
        void  Transaction(float);           //Procedure
        float Total(float=0,int=0);         //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                   //Output Properties
};


#endif /* SAVINGS_H */

