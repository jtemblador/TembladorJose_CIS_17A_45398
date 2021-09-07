/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 12th, 2021, 10:51 AM
 * Purpose:  Basic Menu with Functions for exams and homework
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include "Prob1Random.h"
#include "Prob3Inherited.h"
#include "Prob4Savings.h"
#include "Prob5Employee.h"
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void prob0();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int choose;//Choose a problem
    
    //Initialize variables here
    do{
        cout<<"Choose from the following Menu Items"<<endl;
        cout<<"Problem 1"<<endl;
        cout<<"Problem 2"<<endl;
        cout<<"Problem 3"<<endl;
        cout<<"Problem 4"<<endl;
        cout<<"Problem 5"<<endl;
        cout<<"Problem 6"<<endl;
        cout<<"6 or greater, all negatives to exit"<<endl;
        cin>>choose;
        
        switch(choose){
            case 1:prob1();break;
            case 2:prob2();break;
            case 3:prob3();break;
            case 4:prob4();break;
            case 5:prob5();break;
            case 6:prob6();break;
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=1 && choose<=6);

    return 0;
}

void prob1(){
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    
    for(int i=1;i<=ntimes;i++){
        a.randFromSet(); 
    }
    int *x=a.getFreq(); 
    char *y=a.getSet();
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl<<endl;
}

void prob2(){
    cout<<endl;
}

void prob3(){
cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prob4(){
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++) {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    } 
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = " 
       <<mine.Total((float)(0.10),7)<<endl;
    
    cout<<"Balance after 7 years given 10% interest = " 
    <<mine.TotalRecursive((float)(0.10),7)<<" Recursive Calculation "<<endl;
    cout<<endl;
}

void prob5(){
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25)); 
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25)); 
    Mark.toString(); 
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25)); 
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40)); 
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50)); 
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
    cout<<endl;
}

void prob6(){
    
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
    cout<<"Three byte integer mutlipyed by 1 byte integer: "<<static_cast<int>(thrByte);
    cout<<endl<<endl;    
}

