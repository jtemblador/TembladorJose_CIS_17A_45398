/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on July 16th, 2021, 7:58 PM
 */

//Libraries
#include <iostream>
using namespace std;

//No Global Constants

//Execution begins here
int main(int argc, char*argv[]) {
    //Factorial for unsigned char
    unsigned char uchint=1;
    int uchn=1;
    while (uchn<6) {
        uchint=uchn*uchint;
        uchn++;
    }
    cout<<"Largest n value for Data Type 'unisgned short int' is "<<uchn-1<<"!."<<endl;
    
    
    //Factorial for char
    char chint=1;
    int chn=1;
    while (chn<6) {
        chint=chn*chint;
        chn++;
    }
    cout<<"Largest n value for Data Type 'unisgned short int' is "<<chn-1<<"!."<<endl;
    
    
    //Factorial for unsigned short int
    unsigned short int ushint=1;
    int usn=1;
    while (usn<9) {
        ushint=usn*ushint;
        usn++;
    }
    cout<<"Largest n value for Data Type 'unisgned short int' is "<<usn-1<<"!."<<endl;
    
    //Factorial for short int
    short int shinft=1;
    int sn=1;
    while (sn<8) {
        shinft=sn*shinft;
        sn++;
    }
    cout<<"Largest n value for Data Type 'short int' is "<<sn-1<<"!."<<endl;
    
    
    //Factorial for int
    int intfact=1;
    int n=1;
    while (n<13) {
        intfact=n*intfact;
        n++;

    }
    cout<<"Largest n value for Data Type 'int' is "<<n-1<<"!."<<endl;
    
    
    //Factorial for unsigned int
    unsigned int uninft=1;
    int un=1;
    while (un<13) {
        uninft=un*uninft;
        un++;
    }
    cout<<"Largest n value for Data Type 'unisgned int' is "<<un-1<<"!."<<endl;
    
    
    //Factorial for long int
    long int lngint=1;
    int ln=1;
    while (ln<21) {
        lngint=ln*lngint;
        ln++;
    }
    cout<<"Largest n value for Data Type 'long int' is "<<ln-1<<"!."<<endl;
    
    
    //Factorial for unsigned long int
    unsigned long int ulngint=1;
    int uln=1;
    while (uln<21) {
        ulngint=uln*ulngint;
        uln++;
    }
    cout<<"Largest n value for Data Type 'unsigned long int' is "<<uln-1<<"!."<<endl;
    
    
    //Factorial for long long int
    long long int llngint=1;
    int lln=1;
    while (lln<21) {
        llngint=lln*llngint;
        lln++;
    }
    cout<<"Largest n value for Data Type 'long long int' is "<<lln-1<<"!."<<endl;
    
    
    //Factorial for unsigned long long int
    unsigned long long int ullgint=1;
    int ulln=1;
    while (ulln<21) {
        ullgint=ulln*ullgint;
        ulln++;
    }
    cout<<"Largest n value for Data Type 'unsigned long long int' is "<<ulln-1<<"!."<<endl;
    
    //Factorial for float 
    float flint=1;
    int fln=1;
    while (fln<35) {
        flint=fln*flint;
        fln++;
    }
    cout<<"Largest n value for Data Type 'float' is "<<fln-1<<"!."<<endl;
    
    //Factorial for double 
    double dbint=1;
    int dbn=1;
    while (dbn<171) {
        dbint=dbn*dbint;
        dbn++;
    }
    cout<<"Largest n value for Data Type 'double' is "<<dbn-1<<"!."<<endl;
    
    
    //Factorial for long double 
    long double ldbint=1;
    int ldbn=1;
    while (ldbn<1755) {
        ldbint=ldbn*ldbint;
        ldbn++;
    }
    cout<<"Largest n value for Data Type 'long double' is "<<ldbn-1<<"!."<<endl;    
    
    //Exit stage right
    return 0;
}

