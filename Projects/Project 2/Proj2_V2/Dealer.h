/* 
 * File:   Dealer.h
 * Author: Jose Temblador
 *
 * Created on July 28, 2021, 5:50 PM
 */
#include <string>
using namespace std;


#ifndef DEALER_H
#define DEALER_H

class Dealer {
    private:
        int hand;
        string name;
    public:
        Dealer();
        ~Dealer();
        Dealer(string, int);
        void setHand(int);
        int getHand() {return hand;}
        string getName() {return name;}
};

#endif /* DEALER_H */

