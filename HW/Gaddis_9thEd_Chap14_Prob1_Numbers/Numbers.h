/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: mac
 *
 * Created on July 25, 2021, 1:56 AM
 */
#include <string>
using namespace std;

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers {
private:
    int number;
public:
    Numbers(int n) {number=n;}
    string lssthn20[20];
    string tens[10];
    string hun;
    string thou;
    void Print();
};

#endif /* NUMBERS_H */

