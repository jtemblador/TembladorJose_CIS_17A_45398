/* 
 * File:   DateSW.cpp
 * Author: mac
 *
 * Created on July 23, 2021, 4:25 PM
 */

#include "Date.h"
#include <iostream>  //I/O Library
using namespace std;

Date::Date() {
    dy=0;
    mth=0;
    yr=0;
}

Date::Date(int a, int b, int c) {
    dy=a;
    mth=b;
    yr=c;
}


void Date::setDay(int a){
    if (a>31 || a<1)
        throw InvDay();
    else dy=a;
}

void Date::setMonth(int b){
    if (b>12 || b<1)
        throw InvMonth();
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