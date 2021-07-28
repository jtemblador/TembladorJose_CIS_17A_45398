/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: mac
 *
 * Created on July 25, 2021, 11:44 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    private:
        string name;
        int num;
        string date;
    public:
        Employee ();
        Employee (string, int, string);
        void setName(string);
        void setNum(int);
        void setDate(string);
        string getName() {return name;}
        int getNum() {return num;}
        string getDate () {return date;}
        
};

#endif /* EMPLOYEE_H */

