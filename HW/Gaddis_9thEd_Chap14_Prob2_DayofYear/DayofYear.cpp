/* 
 * File:   Numbers.cpp
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 2:07 AM
 */
#include <iostream>  //I/O Library
#include <cstdlib>
#include "DayofYear.h"

DayofYear::DayofYear (int num) {
    day=num;
}

void DayofYear::Print () {
    string month[12] = {"January", "February", "March", "April", "May", "June", "July",
                 "August", "September", "October", "November", "December"};
    if (day <= 31) {
        cout<<"Day "<<day<<" is "<<month[0]<<" "<<day;
    }
    else if (day <= 59) {
        cout<<"Day "<<day<<" is "<<month[1]<<" "<<day-31;
    }
    else if (day <= 90) {
        cout<<"Day "<<day<<" is "<<month[2]<<" "<<day-59;
    }
    else if (day <= 120) {
        cout<<"Day "<<day<<" is "<<month[3]<<" "<<day-90;
    }
    else if (day <= 151) {
        cout<<"Day "<<day<<" is "<<month[4]<<" "<<day-120;
    }
    else if (day <= 181) {
        cout<<"Day "<<day<<" is "<<month[5]<<" "<<day-151;
    }
    else if (day <= 212) {
        cout<<"Day "<<day<<" is "<<month[6]<<" "<<day-181;
    }
    else if (day <= 243) {
        cout<<"Day "<<day<<" is "<<month[7]<<" "<<day-212;
    }
    else if (day <= 273) {
        cout<<"Day "<<day<<" is "<<month[8]<<" "<<day-243;
    }
    else if (day <= 304) {
        cout<<"Day "<<day<<" is "<<month[9]<<" "<<day-273;
    }
    else if (day <= 334) {
        cout<<"Day "<<day<<" is "<<month[10]<<" "<<day-304;
    }
    else {
        cout<<"Day "<<day<<" is "<<month[11]<<" "<<day-334;
    }
}