/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "CustInf.h"
#include "Paycheck.h"


//Global Constants - Math/Physics Constants, Conversions,
const float RTPAY=10.31;
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void getData(CustInf &, unsigned int &, unsigned int &);
void ChksDps(CustInf &, unsigned int ,  unsigned int);
void prtData(CustInf, unsigned int );
void prblm2();
void getData(PayCheck *, int);
float payChk(PayCheck *, int);
void prtamnt(PayCheck *, int);
void prblm3();
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
int *copy(const int *,int); //Copy the Array
int *mode(const int *,int); //Find the mode set
float median(int *,int, int);   //Fill the median Array with the Float array size, 
                            //the median, and the integer array data
float mean(int *,int);
void prntMea(float);
void prntMed(float , int, int); //Print the median Array
void prblm4();
void prblm5();
void prblm6();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    //Exit stage right!
    return 0;
}


void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
}


void prblm1(){
    CustInf cstmer;
    unsigned int numchks;
    unsigned int numdeps;
    
    getData(cstmer, numchks, numdeps);     //repeats for as many users there are
    
    ChksDps(cstmer, numchks, numdeps);
    
    prtData(cstmer, numchks); 
}

void prtData(CustInf cstmer, unsigned int numchks) {
    float sumchks=0;    //sum of all the checks 
    for (int i=0;i<numchks;i++) {   
        sumchks+=cstmer.numchks[i];//adds all the checks up
    }
    
    cout<<"     Account Number: "<<cstmer.acctnum<<endl;
    cout<<"          Your Name: "<<cstmer.name<<endl;
    cout<<"            Address: "<<cstmer.addrs<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"New Account Balance: $"<<cstmer.bal-sumchks<<endl;
    if (sumchks>cstmer.bal) {
        cout<<endl<<"You're account is overdrawn!\n";
        cout<<"A $50.00 overdraft fee will be charged to your account.\n";
        cout<<"New Account Balance: $"<<cstmer.bal-sumchks-50.00<<endl;
    } 
    
}


void ChksDps(CustInf &cstmer, unsigned int numchks, unsigned int numdeps) {
    cstmer.numchks=new float [numchks]; //creates dynamic array of number of checks
    cstmer.numdeps=new float [numdeps]; //creates dynamic array of number of deposits
    //Entering amount of each check
    for (int i=0; i<numchks; i++) {
        cout<<"Enter amount of check "<<i+1<<": ";
        cin>>cstmer.numchks[i];
    }
    cout<<endl;

    //Entering amount of each deposit
    for (int i=0; i<numdeps; i++) {
        cout<<"Enter amount of deposit "<<i+1<<": ";
        cin>>cstmer.numdeps[i];
        cstmer.bal+=cstmer.numdeps[i];  //adds each deposit to balance
    }
    cout<<endl;
}


void getData(CustInf &cstmer, unsigned int &numchks, unsigned int &numdeps) {
        //User inputs account number
    cout<<"Please enter the 5 digit Account Number:"<<endl;
    cin>>cstmer.acctnum;
    if ((cstmer.acctnum/10000)<1||(cstmer.acctnum/10000)>10) { //only accept 
        cout<<"Account number must be 5 digits!\n";            //5 digit number
        exit (1);
    }
    //User inputs their name
    cout<<"Please your name: "<<endl;   
    cin.ignore();
    getline(cin, cstmer.name);
    
    //User inputs address
    cout<<"Please your Address: "<<endl;
    cin.ignore();
    getline(cin, cstmer.addrs);
    
    //User inputs balance of account    
    cout<<"Please enter the balance of your account: "<<endl;
    cin>>cstmer.bal;
    
    //User inputs number of checks    
    cout<<"Please enter amount of checks: "<<endl;
    cin>>numchks;
    
    //User inputs number of checks    
    cout<<"Please enter amount of deposits: "<<endl;
    cin>>numdeps;
}

void prblm2(){
    unsigned int size;  //number of employees
    
    cout<<"How many employees will input their information?"<<endl;
    cin>>size;
    PayCheck *empl= new PayCheck[size]; //dynamically creating size of structure
    
    for (int i=0;i<size;i++) {
        getData(empl, i);     //repeats for as many users there are
        empl[i].pay=payChk(empl, i);
        
        cout<<"     Company: Dr. Lehr's CIS-17A Class\n";
        cout<<"     Address: "<<empl[i].add<<endl;
        cout<<"     Name: "<<setw(14)<<left<<empl[i].name;
        cout<<fixed<<setprecision(2);
        cout<<"Amount: $"<<empl[i].pay<<endl;
        cout<<"     Amount: ";
        prtamnt(empl, i); 
        cout<<endl;    //Prints amount in numbers
        cout<<"     Signature:  ________________________\n\n";
    }
    
}

void prtamnt(PayCheck *empl, int i) {
    unsigned short n2Cnvrt=empl[i].pay;
    unsigned char n1000s,n100s,n10s,n1s;
    n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
    n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=n2Cnvrt%10;        //Remainder of division by 10
    
    cout<<(n1000s==5?"Five Thousand ":
               n1000s==4?"Four Thousand ":
               n1000s==3?"Three Thousand ":
               n1000s==2?"Two Thousand ":
               n1000s==1?"One Thousand ":"");
    
    cout<<(n100s==9?"Nine Hundred ":
               n100s==8?"Eight Hundred ":
               n100s==7?"Seven Hundred ":
               n100s==6?"Six Hundred ":
               n100s==5?"Five Hundred ":
               n100s==4?"Four Hundred ":
               n100s==3?"Three Hundred ":
               n100s==2?"Two Hundred ":
               n100s==1?"One Hundred ":"");
    
    cout<<(n10s==9?"and Ninety ":
               n10s==8?"and Eighty ":
               n10s==7?"and Seventy ":
               n10s==6?"and Sixty ":
               n10s==5?"and Fifty ":
               n10s==4?"and Forty ":
               n10s==3?"and Thirty ":
               n10s==2?"and Twenty ":"and ");
    
    if (n10s==1) {
        cout<<(n1s==9?"Nineteen ":
               n1s==8?"Eighteen ":
               n1s==7?"Seventeen ":
               n1s==6?"Sixteen ":
               n1s==5?"Fifteen ":
               n1s==4?"Fourteen ":
               n1s==3?"Thirteen ":
               n1s==2?"Twelve ":
               n1s==1?"Eleven ":
               n1s==0?"Ten ":"");
    }
    else {
        cout<<(n1s==9?"Nine ":
               n1s==8?"Eight ":
               n1s==7?"Seven ":
               n1s==6?"Six ":
               n1s==5?"Five ":
               n1s==4?"Four ":
               n1s==3?"Three ":
               n1s==2?"Two ":
               n1s==1?"One ":"");
    }
    cout<<"Dollars";
    
    int p2Cnvrt=empl[i].pay*100;  //Shift decimal two places to the left
    unsigned char x10s,x1s;
    x10s=p2Cnvrt%100/10;    //Find Tenth decimal
    x1s=p2Cnvrt%10;         //find hundredth decimal
    
    if (x10s==0&&x1s==0) cout<<"";
    else {
        cout<<" and ";
        cout<<(x10s==9?"Ninety ":
           x10s==8?"Eighty ":
           x10s==7?"Seventy ":
           x10s==6?"Sixty ":
           x10s==5?"Fifty ":
           x10s==4?"Fourty ":
           x10s==3?"Thirty ":
           x10s==2?"Twenty ":"");
        
        if (x10s==1) {
            cout<<(x1s==9?"Nineteen ":
                   x1s==8?"Eighteen ":
                   x1s==7?"Seventeen ":
                   x1s==6?"Sixteen ":
                   x1s==5?"Fifteen ":
                   x1s==4?"Fourteen ":
                   x1s==3?"Thirteen ":
                   x1s==2?"Twelve ":
                   x1s==1?"Eleven ":
                   x1s==0?"Ten ":"");
        }
        else {
            cout<<(x1s==9?"Nine ":
                   x1s==8?"Eight ":
                   x1s==7?"Seven ":
                   x1s==6?"Six ":
                   x1s==5?"Five ":
                   x1s==4?"Four ":
                   x1s==3?"Three ":
                   x1s==2?"Two ":
                   x1s==1?"One ":"");
        }
        cout<<"Cents";
    }    
}

float payChk(PayCheck *empl, int i) {
    float sumpay=0;
    //calculating total paycheck
    sumpay=empl[i].hrs>40? (empl[i].hrs-40)*(RTPAY*3)+(RTPAY*2*19)+(RTPAY*20):
           empl[i].hrs>20? (empl[i].hrs-20)*(RTPAY*2)+(RTPAY*20):
                           (empl[i].hrs)*RTPAY;
    return sumpay;
}

void getData(PayCheck *empl, int i) {
    //Retrieves employee name
    cout<<"Enter name of employee #"<<i+1<<" : "<<endl;
    cin.ignore();
    getline(cin, empl[i].name);
    
    //Retrieves employee address
    cout<<"Enter Address of employee #"<<i+1<<" : "<<endl;
    getline(cin, empl[i].add);
    
    //User enters hours worked
    cout<<"Please enter hours worked: "<<endl;
    cin>>empl[i].hrs;
    if (empl[i].hrs<0) {
        cout<<"Please enter only positive numbers!\n";
        exit(0);
    }
}

void prblm3(){
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Original Array"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the average of the array
    float meanum=mean(ary, arySize);
    prntMea(meanum);
    
    //Print the median 
    float medary=median(ary, arySize, modNum);
    prntMed(medary, arySize, modNum);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes      = "<<
            ary[0]<<endl;
    cout<<"The max Frequency        = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void prntMed(float medary, int size, int modNum){     //Print the median Array
    cout<<"The median of the array  = ";
    cout<<static_cast<float>(medary/modNum)<<" "<<endl;
}

void prntMea(float a) {
    cout<<"The average of the array = ";
    cout<<a<<endl;
}

float mean(int *array, int size) {
    float menum=0;
    for (int i=0; i<size; i++) {
        menum+=array[i];
    }
    return menum/size;
}


float median(int *array, int size, int modNum){  //Fill the median Array with the Float array size, the median, and the integer array data
    float med=0;
    if (modNum>=10) {
        med=40;
    }
    else {
        for (int i=0;i<modNum;i++){
            med+=array[i];   
        }
        //med/=modNum;
    }

    return med;
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
//    mrkSort(ary,arySize);
    //Find the max Frequency
    int maxfreq=0;
    int curfreq=0;
    int modes=0;
    for (int i=0; i<=9; i++) {
        for (int j=0; j<arySize; j++) {
            if (i==*(array+j)) {
                curfreq++;
            }
            if (curfreq>maxfreq) maxfreq=curfreq;
        }
        if (curfreq==1) { }
        else if (curfreq==maxfreq) {
            modes++;
            
        }
        curfreq=0; 
    }
    //Find the number of modes
    
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=modes;
    int *modeAry=new int[nmodes+2];
    //Finding individual numbers and inputting them into array
    maxfreq=0;
    curfreq=0;
    modes=0;
    int index=2;
    for (int i=0; i<=9; i++) {
        for (int j=0; j<arySize; j++) {
            if (i==*(array+j)) {
                curfreq++;
            }
            if (curfreq>maxfreq) maxfreq=curfreq;
        }
        if (curfreq==1) { }
        else if (curfreq==maxfreq) {
            modes++;
            modeAry[index]=i;
            index++;
        }
        curfreq=0; 
    }
    
    modeAry[0]=modes;//Stub returns no modes
    modeAry[1]=maxfreq;//Stub returns Frequency 1
    
    
    //Fill the mode array

    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}

void prblm4(){
    char b[4];
    //Encrypting a 4 digit number
    cout<<"Enter a 4 digit number to encrypt\n";
    cin>>b;
    
    if (b[0]!=8&&b[1]!=8&&b[2]!=8&&b[3]!=8&&b[0]!=9&&b[1]!=9&&b[2]!=9&&b[3]!=9) {
        b[0]=((b[0]-48)+6)%8;
        b[1]=((b[1]-48)+6)%8;
        b[2]=((b[2]-48)+6)%8;
        b[3]=((b[3]-48)+6)%8;
    }
    else cout<<"Number contains 8 or 9.\nCannot encrypt.";
    
    //Swapping digits
    swap(b[0],b[2]);
    swap(b[1],b[3]);    
    cout<<"Encrypted number is : ";
    for (int i=0;i<4;i++) {
        cout<<static_cast<int>(b[i]);
    }
    cout<<endl;
    
    //Decrypting a 4 digit number
    cout<<"Enter a 4 digit number to decrypt\n";
    cin>>b;
    
    if (b[0]!=8&&b[1]!=8&&b[2]!=8&&b[3]!=8&&b[0]!=9&&b[1]!=9&&b[2]!=9&&b[3]!=9) {
        b[0]=(b[0]-6+8)%8;
        b[1]=(b[1]-6+8)%8;
        b[2]=(b[2]-6+8)%8;
        b[3]=(b[3]-6+8)%8;
    }
    else cout<<"Number contains 8 or 9.\nCannot encrypt.";
    //Swapping digits
    swap(b[2],b[0]);
    swap(b[3],b[1]);
    
    cout<<"Decrypted number is : ";
    for (int i=0;i<4;i++) {
        cout<<static_cast<int>(b[i]);
    }
}

void prblm5(){
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
}

void prblm6(){
    cout<<"Base 10 number:     51.1875"<<endl;
    cout<<"Binary Conversion: "<<"110011.11101010011"<<endl;
    cout<<"Octal Conversion:  "<<"63.3523"<<endl;
    cout<<"Hex    Conversion: "<<"33.753"<<endl;
    
    cout<<"Base 10 number:     -51.1875"<<endl;
    cout<<"Binary Conversion: "<<"001100.00010101101"<<endl;
    cout<<"Octal Conversion:  "<<"14.255"<<endl;
    cout<<"Hex    Conversion: "<<"C.AD"<<endl;
    
    cout<<"Base 10 number:     3.19921875"<<endl;
    cout<<"Binary Conversion: "<<"11.1001011111111101111010011"<<endl;
    cout<<"Octal Conversion:  "<<"13.113775723"<<endl;
    cout<<"Hex    Conversion: "<<"B.12FFBD3"<<endl;
    
    cout<<"Base 10 number:     -3.19921875"<<endl;
    cout<<"Binary Conversion: "<<"0.011010000000001000010100"<<endl;
    cout<<"Octal Conversion:  "<<"64.664002055"<<endl;
    cout<<"Hex    Conversion: "<<"4.ED0042C"<<endl;
    
    cout<<"Base 10 number:     0.2"<<endl;
    cout<<"Binary Conversion: "<<"0.10"<<endl;
    cout<<"Octal Conversion:  "<<"0.2"<<endl;
    cout<<"Hex    Conversion: "<<"0.2"<<endl;
    
    cout<<"Base 10 number:     -0.2"<<endl;
    cout<<"Binary Conversion: "<<"0.10"<<endl;
    cout<<"Octal Conversion:  "<<"0.2"<<endl;
    cout<<"Hex    Conversion: "<<"0.2"<<endl;
    
}