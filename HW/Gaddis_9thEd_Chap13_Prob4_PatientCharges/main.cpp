/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on July 23, 2021, 10:50 AM
 * Purpose:  Patient Information
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include "Info.h"
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {    
    //Declare Variables
    string name, adrs, num, emname, emnum;
    
    //Inputting Data of patient
    name="Jose Temblador";
    adrs="123 Fake St.";
    num="555-6789";
    emname="Jeff Bezos";
    emnum="123-4567";
    
    Patient ptnt(name, adrs, num, emname, emnum);
    cout<<"Patient full name: "<<ptnt.getFullname()<<endl;
    cout<<"Patient Address: "<<ptnt.getAddres()<<endl;
    cout<<"Patient phone number: "<<ptnt.getnumber()<<endl;
    cout<<"Emergency contact name: "<<ptnt.getEmName()<<endl;
    cout<<"Emergency contact number: "<<ptnt.getEmNum()<<endl<<endl;;
    
    //Filling each Class
    Procedure proc[3] = {
        Procedure ("Physical Exam", "July 23, 2021", "Dr. Irvine", 250.00),
        Procedure ("X-ray", "July 23, 2021", "Dr. Jamison", 500.00),
        Procedure ("Blood test", "July 23, 2021", "Dr. Smith", 200.00)
    };
    
    //Outputting Data
    cout<<fixed<<setprecision(2);
    for (int i=0; i<3; i++) {
        cout<<"          Procedure #"<<i+1<<endl;
        cout<<"Prodecure Name: "<<proc[i].getPrcd()<<endl;
        cout<<"Prodecure Date: "<<proc[i].getDate()<<endl;
        cout<<"Prodecure Doctor: "<<proc[i].getDoc()<<endl;
        cout<<"Prodecure Amount: "<<proc[i].getAmnt()<<endl<<endl;
        
    }
            
    //Output data
    
    //Exit stage right!
    return 0;
}