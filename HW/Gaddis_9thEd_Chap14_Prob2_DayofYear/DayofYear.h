/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    string month[12];
public:
    DayofYear(int);
    void Print();
};

#endif /* DAYOFYEAR_H */

