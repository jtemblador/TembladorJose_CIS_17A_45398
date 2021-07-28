/* 
 * File:   NumDays.cpp
 * Author: Jose Temblador
 *
 * Created on July 25, 2021, 3:53 PM
 */

#include <cstdlib>
#include "NumDays.h"

using namespace std;

NumDays::NumDays() {
    wkhrs=0;
    days=0;
}

NumDays::NumDays(int a) {
    wkhrs=a;
    days=a/8.0;
}
