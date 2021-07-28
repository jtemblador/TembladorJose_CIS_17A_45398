/* 
 * File:   DateHeader.h
 * Author: Jose Temblador
 *
 * Created on July 27, 2021, 4:19 PM
 */

#ifndef DATEHEADER_H
#define DATEHEADER_H

//using namespace std;

class Date {
    private:
        int dy;
        int mth;
        int yr; 
    public: 
        Date();
        Date(int, int, int);
        void Inv();
        void setYear(int c);
        void setMonth(int b);
        void setDay (int a);
        int getYear(){return yr;}
        int getMonth(){return mth;}
        int getDay(){return dy;}
        void PrintDate();
        class InvDay{};
        class InvMonth{};
        
};

#endif /* DATEHEADER_H */