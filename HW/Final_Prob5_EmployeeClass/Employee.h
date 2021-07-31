/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: mac
 *
 * Created on July 30, 2021, 11:33 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private: 
        double Tax(float);   //Utility Procedure
        char   MyName[20];   //Property
        char   JobTitle[20]; //Property
        float  HourlyRate;   //Property
        int    HoursWorked;  //Property
        float  GrossPay;     //Property
        float  NetPay;       //Property
    public:
        Employee(char[],char[],float); //Constructor
        float  CalculatePay(float,int);//Procedure
        float  getGrossPay(float,int); //Procedure
        float  getNetPay(float);       //Procedure
        void   toString();             //Procedure
        int    setHoursWorked(int);    //Procedure
        float  setHourlyRate(float);   //Procedure
};

#endif /* EMPLOYEE_H */

