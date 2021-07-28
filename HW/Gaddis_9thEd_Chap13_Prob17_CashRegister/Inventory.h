/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: mac
 *
 * Created on July 24, 2021, 4:55 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H
using namespace std;


class Inventory {
    private: 
        int itemNum, qnt;
        float cst, ttlCst;
    public: 
        Inventory ();
        Inventory (int, int, float);
        void setItemNum(int);
        void setQnt(int);
        void setCost(float);
        void setTtlCost();
        void printItems();
        int getItemNum() {return itemNum;}
        int getQnt() {return qnt;}
        float getCst() {return cst;}
        float getTtlCost() {return ttlCst;}
};

class CashRegister {
    private:
        float salestax, price, subttl, ttl;
    public:
        CashRegister();
        //void setPrice(float);
        //void setSubTtl(float, int);
        //void setTtl(float, int);
        float getPrice(float);
        float getSubTtl(int);
        float getTtl();
};

#endif /* INVENTORY_H */

