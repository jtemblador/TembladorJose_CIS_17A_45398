/* 
 * File:   Ga9EdC11P11
 * Author:  Jose Temblador 
 * Created on July 11, 2021 9:11PM
 * Purpose:  Assignment 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

const int NUMBUD = 10;

struct MonthlyBudget {
    float hs, util, hhex, trans, fd, 
          med, ins, ent, clth, misc;
};

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
void getDta(MonthlyBudget &);
void decide(MonthlyBudget);
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    MonthlyBudget stu;
    
    getDta(stu);
    
    decide(stu);
    //Exit stage right!
    return 0;
}

void getDta(MonthlyBudget &stu) {
    cout<<"Enter housing cost for the month:$\n";
    cin>>stu.hs;
    cout<<"Enter utilities cost for the month:$\n";
    cin>>stu.util;
    cout<<"Enter household expenses cost for the month:$\n";
    cin>>stu.hhex;
    cout<<"Enter transportation cost for the month:$\n";
    cin>>stu.trans;
    cout<<"Enter food cost for the month:$\n";
    cin>>stu.fd;
    cout<<"Enter medical cost for the month:$\n";
    cin>>stu.med;
    cout<<"Enter insurance cost for the month:$\n";
    cin>>stu.ins;
    cout<<"Enter entertainment cost for the month:$\n";
    cin>>stu.ent;
    cout<<"Enter clothing cost for the month:$\n";
    cin>>stu.clth;
    cout<<"Enter miscellaneous cost for the month:$\n";
    cin>>stu.misc;
    
}

void decide(MonthlyBudget stu) {
    float sum=0.0;
    cout<<"Housing ";
    stu.hs==500.00?cout<<"Even":
    stu.hs <500.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.hs;
    cout<<"Utilities ";
    stu.util==150.00?cout<<"Even":
    stu.util <150.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.util;
    cout<<"Household Expenses ";
    stu.hhex==65.00?cout<<"Even":
    stu.hhex <65.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.hhex;
    cout<<"Transportation ";
    stu.trans==50.00?cout<<"Even":
    stu.trans <50.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.trans;
    cout<<"Food ";
    stu.fd==250.00?cout<<"Even":
    stu.fd <250.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.fd;
    cout<<"Medical ";
    stu.med==30.00?cout<<"Even":
    stu.med<30.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.med;
    cout<<"Insurance ";
    stu.ins==100.00?cout<<"Even":
    stu.ins<100.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.ins;
    cout<<"Entertainment ";
    stu.ent==150.00?cout<<"Even":
    stu.ent<150.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.ent;
    cout<<"Clothing ";
    stu.clth==75.00?cout<<"Even":
    stu.clth<75.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.clth;
    cout<<"Miscellaneous ";
    stu.misc==50.00?cout<<"Even":
    stu.misc<50.00?cout<<"Under":cout<<"Over";
    cout<<endl;
    sum+=stu.misc;
    
    cout<<fixed<<setprecision(2);
    cout<<"You were $";
    sum<1420.00?cout<<1420-sum<<" under budget":cout<<sum-1420<<" over budget";
}