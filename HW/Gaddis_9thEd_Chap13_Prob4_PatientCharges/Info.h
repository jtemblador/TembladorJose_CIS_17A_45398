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

class Patient {
    private:
        string fulname, fuladrs, number, emnam, emnm;
    public:
        Patient (string, string, string, string, string );
        string getFullname() {return fulname;}
        string getAddres() {return fuladrs;}
        string getnumber() {return number;}
        string getEmName() {return emnam;}
        string getEmNum() {return emnm;}
};

class Procedure {
    private:
        string proc, date, doc;
        float amnt;
    public:
        Procedure (string, string, string, float);
        string getPrcd() {return proc;}
        string getDate() {return date;}
        string getDoc() {return doc;}
        float getAmnt() {return amnt;}
};

#endif /* INFO_H */

