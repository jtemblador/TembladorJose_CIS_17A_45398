/* 
 * File:   Prob3Table.cpp
 * Author: Jose Temblador
 *
 * Created on July 27, 2021, 11:19 PM
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Prob3Table.h"
using namespace std;

#include <fstream>
#include "Prob3Table.h"

Prob3Table::Prob3Table(char *fn, int rows, int cols) { //Constructor
    colSum=new int[cols];   //dynamically creates number of columns
    rowSum=new int[rows];   //dynamically creates number of rows
    this->cols=cols;
    this->rows=rows;
   
    ifstream infile; // File being read in
    infile.open(fn, std::ios::in);
    table=new int[(cols*rows)];// table that has rows+columns in one array

    for (int i=0; i<rows*cols; i++)
        infile>>table[i];
    calcTable();
    infile.close();
}

void Prob3Table::calcTable(void) { 
    grandTotal=0;
    for (int i=0; i<cols; i++) {
        colSum[i]=0;
        for (int j=0; j<rows; j++) {
            colSum[i]+=table[j*cols+i];
        }
        grandTotal+=colSum[i];
    }
    for (int i=0; i<rows; i++) {
        rowSum[i]=0;    //sets row equal to 0
        for (int j=0; j<cols; j++) {
            rowSum[i]+=table[i*cols+j]; //adds up all columns in row 
        }
    }
}