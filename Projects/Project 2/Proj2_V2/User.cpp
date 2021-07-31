/* 
 * File:   User.cpp
 * Author: Jose Temblador
 *
 * Created on July 28, 2021, 8:10 PM
 */

#include <iostream>  //I/O Library
#include "User.h"
using namespace std;


User::User() {
    name="";
    hand=0;
}

User::~User() {
    //cout<<"User class destructor engaged.\n";
}

void User::setHand(int a) {
    hand+=a;
}

void User::setHand(int a, int b) {
    hand+=a+b;
}

void User::setName(string a) {
    name=a;
}