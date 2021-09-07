/* 
 * File:   Prob3Inherited.h
 * Author: Jose Temblador
 *
 * Created on July 28, 2021, 12:34 PM
 */

#include "Prob3Inherited.h"

Prob3TableInherited::Prob3TableInherited(char *fn, int r, int c)
                    :Prob3Table(fn, r, c) { 
    
    augTable = new int[(r+1)*(c+1)];
    for (int i=0; i<r;i++) {
        for (int j=0; j<c;j++) {
            augTable[(c+1)*i+j]=this->table[i*c+j];//creating 
        }
    }
    //filling augmented array
    for (int i=0; i<cols; i++){
        augTable[(c+1)*i+c]=this->rowSum[i];
        augTable[(c+1)*r+i]=this->colSum[i];
    }
    augTable[(r+1)*(c+1)-1]=this->grandTotal;
};