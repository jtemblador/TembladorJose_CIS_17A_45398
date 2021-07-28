/* 
 * File:   DayofYear.h
 * Author: mac
 *
 * Created on July 25, 2021, 3:05 AM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
using namespace std;

class DayofYear {
private: 
    int day;
    int days[12];
    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"};
    string month;
public:
    DayofYear(int);
    void Print();
    string getMonth();
    int getDate();
};

#endif /* DAYOFYEAR_H */

