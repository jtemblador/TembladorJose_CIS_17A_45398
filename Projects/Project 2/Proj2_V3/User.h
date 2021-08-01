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
    protected:
        string name;
        string copyname;
        int hand;
        static int objCnt;
    public:
        User();
        User (User &);
        ~User();
        void setName(string);
        void setHand(int);
        void setHand(int, int);
        int gethand() {return hand;}
        string getName() {return name;}
        void setCopyName(User &);
        string getCopyName();
        int getObjCnt();
        void printData(string, string, int, int);
        const User operator ++(int) {
            hand++;
            return *this;
        }
        const User operator --(int) {
            hand--;
            return *this;
        }
        User operator +(User a) {
            User sum;
            sum.setHand(a.gethand()+gethand());
            return sum;
        }
};


#endif /* USER_H */

