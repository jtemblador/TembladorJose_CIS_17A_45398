/* 
 * File:   MilTime.cpp
 * Author: Jose Temblador
 *
 * Created on July 26, 2021, 1:46 PM
 */

#include <cstdlib>
#include "MilTime.h"
#include "Time.h"
using namespace std;

MilTime::MilTime() {
    milHr=0;
    milSec=0;
}

MilTime::MilTime(int hr, int sec) {
    setTime(hr, sec);
}

void MilTime::setTime(int inhr, int inmin) {
    milHr=inhr;
    milSec=inmin;
    if (milHr>12) {
        hr=milHr-12;
    }
    else hr=milHr;
}