/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.cpp
 * Author: mac
 *
 * Created on July 24, 2021, 7:27 PM
 */

#include <cstdlib>
#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
    itemNum=0;
    qnt=0;
    cst=0;
    ttlCst=0;
}

Inventory::Inventory (int a, int b, float c) {
    setItemNum(a);
    setQnt(b);
    setCost(c);
    setTtlCost();
}

void Inventory::setItemNum(int i) {
    itemNum=i;
}

void Inventory::setQnt(int q) {
    qnt=q;
}

void Inventory::setCost(float c) {
    cst=c;
}

void Inventory::setTtlCost() {
    ttlCst=qnt*cst;
}