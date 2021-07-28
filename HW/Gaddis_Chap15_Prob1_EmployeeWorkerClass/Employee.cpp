/* 
 * File:   Employee.cpp
 * Author: mac
 *
 * Created on July 25, 2021, 11:53 PM
 */

#include <cstdlib>
#include "Employee.h"
using namespace std;

Employee::Employee () {
    num=0;
    name="";
    date="";
}

Employee::Employee (string a, int b, string c) {
    name=a;
    num=b;
    date=c;
}

void Employee::setName(string in) {
    name=in;
}

void Employee::setNum(int a) {
    name=a;
}

void Employee::setDate(string a) {
    date=a;
}