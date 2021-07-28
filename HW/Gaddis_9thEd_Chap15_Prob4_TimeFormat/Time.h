/* 
 * File:   Time.h
 * Author: Jose Temblador
 *
 * Created on July 26, 2021, 9:30 AM
 */

#ifndef TIME_H
#define TIME_H
using namespace std;

class Time {
protected:
    int hr, min, sec;
public:
    Time();
    Time(int, int, int);
    int getHr() {return hr;}
    int getMin() {return min;}
    int getSec() {return sec;}
};

#endif /* TIME_H */

