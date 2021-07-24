/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DateHeader.h
 * Author: mac
 *
 * Created on July 23, 2021, 4:19 PM
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
    void setYear(int c);
    void setMonth(int b);
    void setDay (int a);
    void PrintDate();
};

#endif /* DATEHEADER_H */