/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustInf.h
 * Author: mac
 *
 * Created on July 19, 2021, 11:29 PM
 */

#ifndef CUSTINF_H
#define CUSTINF_H

struct CustInf {
    int acctnum;    //account number
    string name;    //customer name
    string addrs;   //address
    float bal;      //Balance of account at the beginning of the month
    float *numchks;  //number of checks inputted by user
    float *numdeps;  //number of checks deposited by user 
};

#endif /* CUSTINF_H */

