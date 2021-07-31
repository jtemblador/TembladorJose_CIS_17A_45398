/* 
 * File:   Prob3Inherited.h
 * Author: Jose Temblador
 *
 * Created on July 28, 2021, 12:34 PM
 */

#include "Prob3Inherited.h"

Prob3TableInherited::Prob3TableInherited(char *fn, int rows, int cols)
                    :Prob3Table(fn, rows, cols) { 
    
    augTable = new int[(rows+1)*(cols+1)];
    for (int i=0; i<rows;i++) {
        for (int j=0; j<cols;j++) {
            augTable[(cols+1)*i+j]=this->table[i*cols+j];
        }
    }
    //filling augmented array
    for (int i=0; i<cols; i++){
        augTable[(cols+1)*i+cols]=this->rowSum[i];
        augTable[(cols+1)*rows+i]=this->colSum[i];
    }
    augTable[(rows+1)*(cols+1)-1]=this->grandTotal;
};