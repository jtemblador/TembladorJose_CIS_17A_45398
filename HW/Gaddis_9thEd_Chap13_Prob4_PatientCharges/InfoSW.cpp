/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfoSW.cpp
 * Author: mac
 *
 * Created on July 23, 2021, 8:53 PM
 */

#include "Info.h"
using namespace std;


Patient::Patient (string name, string adrs, string num, string emname, string emnum ) {
    fulname = name;
    fuladrs = adrs;
    number = num;
    emnam = emname;
    emnm = emnum;
}

Procedure::Procedure(string a, string b, string c, float d) {
    proc = a;
    date = b;
    doc = c;
    amnt = d;
}