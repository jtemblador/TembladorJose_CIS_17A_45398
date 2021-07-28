/* 
 * File:   Time.cpp
 * Author: Jose Temblador
 * Created on July 26, 2021, 1:40 PM
 */

#include <cstdlib>

#include "Time.h"
using namespace std;

Time::Time() {
    hr=0;
    min=0;
    sec=0;
}

Time::Time(int h, int m, int s) {
    hr=h;
    min=m;
    sec=s;
}