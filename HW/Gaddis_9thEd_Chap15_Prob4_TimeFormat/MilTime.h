/* 
 * File:   MilTime.h
 * Author: Jose Temblador
 *
 * Created on July 26, 2021, 1:43 PM
 */

#include "Time.h"
#ifndef MILTIME_H
#define MILTIME_H
using namespace std;


class MilTime:public Time {
    private: 
        int milHr, milSec;
    public:
        MilTime();
        MilTime(int, int);
        void setTime(int, int);
        int getMilSec() {return milSec;}
        int getMilHr() {return milHr;}
        int get12Hr() {return hr;}
};

#endif /* MILTIME_H */

