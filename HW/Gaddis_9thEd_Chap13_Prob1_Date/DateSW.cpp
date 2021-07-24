/* 
 * File:   DateSW.cpp
 * Author: mac
 *
 * Created on July 23, 2021, 4:25 PM
 */
#include <iostream>  //I/O Library
using namespace std;

#include "DateHeader.h"

void Date::setDay(int a){
    if (a>31 && a<1)
        cout<<"This day does not exist.\n";
    else dy=a;
}

void Date::setMonth(int b){
    if (b>12 && b<1)
        cout<<"This month does not exist.\n";
    else mth=b;
}

void Date::setYear(int c) {
    yr=c;
}

void Date::PrintDate() {
    string month[12] ={ "January", "February", "March", "April", "May", "June",
             "July", "August", "September", "October", "November", "December" };
    cout<<mth<<"/"<<dy<<"/"<<yr<<endl;
    cout<<month[mth-1]<<" "<<dy<<", "<<yr<<endl;
    cout<<dy<<" "<<month[mth-1]<<" "<<yr;
}