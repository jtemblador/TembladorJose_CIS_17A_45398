/* 
 * File:   NumDays.h
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 3:51 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H
#include <cmath>
using namespace std;

class NumDays {
    private: 
        int wkhrs;
        float days;
    public: 
        NumDays();
        NumDays(int);
        int getHrs(){return wkhrs;}
        float getDays() {return days;}
        NumDays& operator --() {//prefix operator
            --wkhrs;
            days=wkhrs/8.0;
            return *this;
        }
        NumDays& operator ++() {//prefix operator
            ++wkhrs;
            days=wkhrs/8.0;
            return *this;
        }
        const NumDays operator ++ (int){
            NumDays a(*this);
            ++wkhrs;
            days=(wkhrs/8.0);
            return a;
        }
        const NumDays operator -- (int){
            NumDays a(*this);
            --wkhrs;
            days=(wkhrs/8.0);
            return a;
        }
        NumDays operator +(NumDays a) {
            int res = abs(getHrs()+a.getHrs());
            NumDays result(res);
            return result;
        }
        NumDays operator -(NumDays a) {
            int res = abs (getHrs()-a.getHrs());
            NumDays result(res);
            return result;
        }
};

#endif /* NUMDAYS_H */

