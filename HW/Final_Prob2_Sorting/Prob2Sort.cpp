/* 
 * File:   Prob2Sort.cpp
 * Author: Jose Temblador
 *
 * Created on July 27, 2021, 5:36 PM
 */

/*#include <cstdlib>
#include <iostream>  //I/O Library
#include "Prob2Sort.h"
using namespace std;

template<class T>
T *Prob2Sort<T>::sortArray(const T *str,int size, bool as) {
    T *test = new T[size];
    T temp;
    for (int i=0; i<size-1;i++) 
        test[i]=str[i];
    bool swap;
    do {
        for (int i=0; i<size; i++) {
            if (as==true) {
                if (test[i]>test[i+1]) {
                    temp=test[i];
                    test[i+1]=test[i];
                    test[i+1]=temp;
                    swap=true;
                }
                else {
                    temp=test[i];
                    test[i+1]=test[i];
                    test[i+1]=temp;
                    swap=true;
                }
            }
        }
    } while (swap==true);
        return test;
}

template<class T>
T *Prob2Sort<T>::sortArray(const T *str,int y, int x, int col, bool as) {//Sorts a 2 dimensional array
    T *test = new T[x*y];                                                //represented as a 1 dim array
    for (int i=0; i<(x*y);i++) 
        test[i]=str[i];
    col-=1;
    bool swap;
    T temp;
    do {
        swap=false;
        for(int i=0; i<y-1;i++) {
            if (as==true) {
                if (test[i*x+col]>test[(i+1)*x+col]) {
                    swap=true;
                    for (int j=0; j<x;j++) {
                        temp=test[i*x+j];
                        test[i*x+j]=test[(i+1)*x+j];
                        test[(i+1)*x+j]=temp;
                    }
                }
                else {
                    if (test[i*x+col]>test[(i+1)*x+col]) {
                        swap=true;
                        for (int j=0; j<x;j++) {
                            temp=test[i*x+j];
                            test[i*x+j]=test[(i+1)*x+j];
                            test[(i+1)*x+j]=temp;
                        }
                    }
                }
            }
        }
    } while (swap==true);
    return test;
}
 * */
