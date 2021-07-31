/* 
 * File:   Prob3Inherited.h
 * Author: Jose Temblador
 *
 * Created on July 28, 2021, 11:34 PM
 */

#ifndef PROB3INHERITED_H
#define PROB3INHERITED_H
#include "Prob3Table.h"
#include "Prob3Table.h"

class Prob3TableInherited:public Prob3Table
{
    protected:
        int *augTable; //Augmented Table with sums
    public:
        Prob3TableInherited(char *,int,int); //Constructor
        ~Prob3TableInherited(){delete [] augTable;}; //Destructor
        const int *getAugTable(void){return augTable;};
};

#endif /* PROB3INHERITED_H */

