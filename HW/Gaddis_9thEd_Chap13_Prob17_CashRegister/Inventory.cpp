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

#include <iostream>  //I/O Library
#include <iomanip>
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

void Inventory::printItems() {
    cout<<fixed<<setprecision(2);
    cout<<"Item number:   "<<getItemNum()<<endl;
    cout<<"Item quantity: "<<getQnt()<<endl;
    cout<<"Item cost:     $"<<getCst()<<endl;
    cout<<"Total cost :   $"<<getTtlCost()<<endl<<endl;
}

CashRegister::CashRegister() {
    salestax=0.06;
}

float CashRegister::getPrice(float b) {
    price = b+(b*0.3);
    return price;
}

float CashRegister::getSubTtl(int quant) {
    subttl = quant*(price);
    return subttl;
}

float CashRegister::getTtl() {
    ttl = subttl+(salestax*subttl);
    return ttl;
}