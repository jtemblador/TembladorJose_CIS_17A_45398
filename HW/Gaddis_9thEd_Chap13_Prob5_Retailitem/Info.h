/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.h
 * Author: Jose Temblador
 *
 * Created on July 23, 2021, 6:55 PM
 */

#ifndef INFO_H
#define INFO_H

#include <string>
using namespace std;

class Retail {
    private:
        string item;
        int units;
        float price;
    public:
        //Retail (string, int, float);
        void setItem(string);
        void setUnits(int) ;
        void setPrice(float);
        string getItem() {return item;}
        int getUnits() {return units;}
        float getPrice() {return price;}
};

#endif /* INFO_H */

