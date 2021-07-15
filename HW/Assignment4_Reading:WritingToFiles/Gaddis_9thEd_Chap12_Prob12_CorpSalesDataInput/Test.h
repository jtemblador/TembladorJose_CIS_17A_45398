/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Test.h
 * Author: 
 *
 * Created on July 13, 2021, 6:53 PM
 */

#ifndef TEST_H
#define TEST_H
const unsigned int SIZE=4;

struct SalesData {
    string dvname;       //division name North, South, East, West
    char qrtr[SIZE];     //Quarter 1, 2, 3, 4
    float qrtrsls[SIZE]; //sales of each quarter
};

#endif /* TEST_H */

