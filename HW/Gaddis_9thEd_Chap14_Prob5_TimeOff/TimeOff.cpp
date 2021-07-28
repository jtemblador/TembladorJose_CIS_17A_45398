/* 
 * File:   TimeOff.cpp
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 3:53 PM
 */

#include <cstdlib>
#include "TimeOff.h"

using namespace std;

TimeOff::TimeOff() {
    wkhrs=0;
    days=0;
}

TimeOff::TimeOff(int a) {
    wkhrs=a;
    days=a/8.0;
}
