/* 
 * File:   ProdWrkr.h
 * Author: Jose Temblador
 *
 * Created on July 26, 2021, 8:02 PM
 */

#ifndef PRODWRKR_H
#define PRODWRKR_H

#include "Employee.h"
using namespace std;

class ProdWrkr:public Employee {
    private:
        int shift;
        float rate;
    public:
        ProdWrkr():Employee() { 
            shift=0;
            rate=0.0;
        }
        ProdWrkr(string name, int num, string date, int sh, float rt)
        :Employee(name, num, date) {
            shift=sh;
            rate=rt;
        }
        //mutator functions 
        void setShift(int);
        void setRate(float);
        //accessor functions
        int getShift() const {return shift;}
        float getRate () const {return rate;}
};

#endif /* PRODWRKR_H */

