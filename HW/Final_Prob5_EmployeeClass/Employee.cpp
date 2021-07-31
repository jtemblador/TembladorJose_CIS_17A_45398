/* 
 * File:   Employee.cpp
 * Author: Jose Temblador
 *
 * Created on July 30, 2021, 11:37 PM
 */
#include "Employee.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

Employee::Employee (char name[],char job[], float rate) {
    strcpy(MyName, name);
    strcpy(JobTitle,job);
    HourlyRate=rate;
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}

double Employee::Tax(float pay) {
    if (pay<=500) return 0.1;
    else if (pay<=1000) return 0.2;
    else return 0.3;
}

int Employee::setHoursWorked(int hrs) {
    HoursWorked=hrs;
    return HoursWorked;
}

float Employee::setHourlyRate(float rate) {
    HourlyRate=rate;
    return HourlyRate;
}

float Employee::CalculatePay(float rate,int hrs) {
    return getNetPay(getGrossPay(setHourlyRate(rate),setHoursWorked(hrs)));
}

float Employee::getGrossPay(float rate, int hrs) {
    GrossPay=hrs<=40?  rate*hrs:
             hrs<50? (rate*0.5)*(hrs-40)+(rate*40):
                     (rate*2)*(hrs-50)+(rate*0.5)*(30)+(rate*40);
    return GrossPay;
}

float Employee::getNetPay(float gross) {
    if (GrossPay<=500) {
        NetPay=gross-(Tax(GrossPay)*gross);
        return NetPay;
    }
    else if (GrossPay>500&&GrossPay<=1000){
        NetPay=gross;
        NetPay-=(Tax(GrossPay)*(gross-500));
        NetPay-=(0.1*500);
    }
    else {
        NetPay=gross;
        NetPay-=(Tax(GrossPay)*(gross-1000));
        NetPay-=(0.2*(500));
        NetPay-=(0.1*500);
    }
}

void Employee::toString(){
    if (HourlyRate>200) {
        cout<<"Unacceptable Hourly Rate"<<endl;
        HourlyRate=0;
    }
    if (HoursWorked<0) {
        cout<<"Unacceptable Hours Worked"<<endl;
        HoursWorked=0;
    }
    cout <<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<" Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked<<" ";
    cout<<"Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
    
}