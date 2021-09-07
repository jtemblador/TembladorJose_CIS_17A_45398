/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<"5.75 Conversions\n";
    cout<<"Hex: 5.C\n";
    cout<<"Oct: 5.6\n";
    cout<<"Bin: 101.1100\n";
    cout<<"NASA Format: 0101 1100 | 0000 0000 | 0000 0000 | 0000 0011\n";
    cout<<"or 0.1011100 x 2^3\n";
    cout<<"IEEE 754 :   0100 0000 | 1011 1000 | 0000 0000 | 0000 0000\n";
    unsigned char oneByte=0x5D; //8WD 8BP
    oneByte>>=4;
    cout<<"One byte integer: "<<static_cast<int>(oneByte)<<endl<<endl;
    
    cout<<"0.9 Conversions\n";
    cout<<"Hex: 0.E[6]\n";
    cout<<"Oct: 0.7[1463]\n";
    cout<<"Bin: 0.111[001100110011]\n";
    cout<<"NASA Format: 0111 0011 | 0011 0011 | 0011 0011 | 0000 0000\n";
    cout<<"or 0.111001100110011 x 2^0\n";
    cout<<"IEEE 754 :   0011 1111 | 0110 0110 | 0110 0110 | 0110 0110\n";
    unsigned short twoByte=0xE667;//16 WD 16BP
    twoByte>>=15;
    cout<<"Two byte integer: "<<static_cast<int>(twoByte)<<endl<<endl;
    
    cout<<"99.7 Conversions\n";
    cout<<"Hex: 63.B[3]\n";
    cout<<"Oct: 143.5[4631]\n";
    cout<<"Bin: 001100011.101[100110011001]\n";
    cout<<"NASA Format: 0110 0011 | 1011 0011 | 0011 0011 | 0000 0111\n";
    cout<<"or 0.1100011101100110011001 x 2^7\n";
    cout<<"IEEE 754 :   0100 0010 | 1100 0111 | 0110 0110 | 0110 0110\n";
    unsigned int thrByte=0x63BBBB; //24WD 
    thrByte>>=16;
    cout<<"Three byte integer: "<<static_cast<int>(thrByte)<<endl;
    unsigned char num=0b111;
    thrByte=0x63BBBB; 
    thrByte*=num;
    thrByte>>=16;
    cout<<"Three byte integer mutlipyed by 1 byte integer: "<<static_cast<int>(thrByte)<<endl;    
    
    //Exit stage right!
    return 0;
}