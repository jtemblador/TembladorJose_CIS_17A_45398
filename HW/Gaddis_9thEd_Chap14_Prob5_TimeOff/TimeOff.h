/* 
 * File:   TimeOff.h
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 3:51 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H
#include <cmath>
using namespace std;

class TimeOff {
    private: 
        int wkhrs;
        float days, sckdys;
    public: 
        TimeOff();
        TimeOff(int);
        void maxSick ();
        int getHrs(){return wkhrs;}
        float getDays() {return days;}
        TimeOff& operator --() {//prefix operator
            --wkhrs;
            days=wkhrs/8.0;
            return *this;
        }
        TimeOff& operator ++() {//prefix operator
            ++wkhrs;
            days=wkhrs/8.0;
            return *this;
        }
        const TimeOff operator ++ (int){
            TimeOff a(*this);
            ++wkhrs;
            days=(wkhrs/8.0);
            return a;
        }
        const TimeOff operator -- (int){
            TimeOff a(*this);
            --wkhrs;
            days=(wkhrs/8.0);
            return a;
        }
        TimeOff operator +(TimeOff a) {
            int res = abs(getHrs()+a.getHrs());
            TimeOff result(res);
            return result;
        }
        TimeOff operator -(TimeOff a) {
            int res = abs (getHrs()-a.getHrs());
            TimeOff result(res);
            return result;
        }
};

#endif /* NUMDAYS_H */

