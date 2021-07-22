/* 
 * File:   main.cpp
 * Author: Jose Temblaador
 * Created on March 6th, 2019, 7:45 PM
 */

//Libraries
#include <iostream>//I/O Library
using namespace std;

//No Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
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
    
    //Exit stage right
    return 0;
}