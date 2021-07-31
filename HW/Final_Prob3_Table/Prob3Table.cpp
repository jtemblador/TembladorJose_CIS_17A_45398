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

Prob3Table::Prob3Table(char *fn, int rows, int cols) { //Constructor then Destructor
    ifstream infile; // File with table inside
    colSum=new int[cols];
    rowSum=new int[rows];
    this->cols=cols;
    this->rows=rows;
   
    infile.open(fn, std::ios::in);
    table=new int[(cols*rows)];

    for (int i=0; i<rows*cols; i++)
        infile >> table[i];
    calcTable();
    infile.close();
}

void Prob3Table::calcTable(void) { //Calculate all the sums
    grandTotal=0;
    for (int i=0; i<rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSum[i] += table[i * cols + j];
        }
    }
    for (int i = 0; i<cols; i++) {
        colSum[i] = 0;
        for (int j=0; j<rows; j++) {
            colSum[i]+=table[j*cols+i];
        }
        grandTotal+=colSum[i];
    }
}