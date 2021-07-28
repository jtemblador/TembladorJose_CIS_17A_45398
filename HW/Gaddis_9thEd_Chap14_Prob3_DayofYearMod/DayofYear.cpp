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
    if (num>365) {
        num-=365;
        day=num;
    }
    else if (num<1) {
        num+=365;
        day=num;
    }
    else 
        day=num;
}

void DayofYear::Print () {
    cout<<"Day "<<day<<" is "<<getMonth()<<" "<<getDate()<<endl;
    
}

string DayofYear::getMonth() {
    if (day <= 31) {
        month=months[0];
        return month;
    }
    else if (day <= 59) {
        month=months[1];
        return month;
    }
    else if (day <= 90) {
        month=months[2];
        return month;
    }
    else if (day <= 120) {
        month=months[3];
        return month;
    }
    else if (day <= 151) {
        month=months[4];
        return month;
    }
    else if (day <= 181) {
        month=months[5];
        return month;
    }
    else if (day <= 212) {
        month=months[6];
        return month;
    }
    else if (day <= 243) {
        month=months[7];
        return month;
    }
    else if (day <= 273) {
        month=months[8];
        return month;
    }
    else if (day <= 304) {
        month=months[9];
        return month;
    }
    else if (day <= 334) {
        month=months[10];
        return month;
    }
    else {
        month=months[11];
        return month;
    }
    return month;
}

int DayofYear::getDate() {
    if (day <= 31) {
        return day;
    }
    else if (day <= 59) {
        day-=31;
        return day;
    }
    else if (day <= 90) {
        day = day-59;
        return day;
    }
    else if (day <= 120) {
        day = day-90;
        return day;
    }
    else if (day <= 151) {
        day = day-120;
        return day;
    }
    else if (day <= 181) {
        day = day-151;
        return day;
    }
    else if (day <= 212) {
        day = day-181;
        return day;
    }
    else if (day <= 243) {
        day = day-212;
        return day;
    }
    else if (day <= 273) {
        day = day-243;
        return day;
    }
    else if (day <= 304) {
        day = day-273;
        return day;
    }
    else if (day <= 334) {
        day = day-304;
        return day;
    }
    else {
        day = day-334;
        return day;
    }
}