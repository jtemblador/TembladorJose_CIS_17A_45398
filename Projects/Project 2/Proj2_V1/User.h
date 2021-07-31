/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: mac
 *
 * Created on July 19, 2021, 3:21 AM
 */

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;


class User {
    private:
        string name;
        int hand;
    public:
        User();
        ~User();
        void setName(string);
        void setHand(int);
        void setHand(int, int);
        int gethand() {return hand;}
        string getName() {return name;}
};


#endif /* USER_H */

