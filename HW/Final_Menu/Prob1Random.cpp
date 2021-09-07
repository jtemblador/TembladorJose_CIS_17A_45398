/* 
 * File:   Prob1Random.cpp
 * Author: Jose Temblador
 *
 * Created on July 26, 2021, 4:36 PM
 */

#include <cstdlib>
#include <ctime>
#include "Prob1Random.h"
using namespace std;

Prob1Random::Prob1Random(const char a, const char *b) {
    numRand = 0;
    srand(static_cast<unsigned int>(time(0)));
    nset=a;
    set = new char[a]; //dynamically creating set array
    freq = new int[a]; //dynamically creating frequency array
    for (int i=0; i<a;i++) {
        set[i]=b[i];//filling structural array with pointed char array
        freq[i]=0;  //frequency of index i
    }
}

Prob1Random::~Prob1Random(void) {
    delete []set;
    delete []freq;
}

char Prob1Random::randFromSet(void) {
    char i=rand()%nset;
    freq[i]++;
    numRand++;
    return set[i];
}

char *Prob1Random::getSet(void) const {return set;}

int *Prob1Random::getFreq(void) const {return freq;}

int Prob1Random::getNumRand(void) const {return numRand;}