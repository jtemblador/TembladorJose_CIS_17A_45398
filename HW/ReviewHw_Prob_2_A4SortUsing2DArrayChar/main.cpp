/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on 6/29/21 7:58PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
                                                    //string compare and string copy
int  read(char array[][COLMAX],int &rowDet) {
    char arr[rowDet];
    int maxCol=0, count=0;
    while (cin>>arr[count++]) {
/*        if (strlen(arr[count]) > maxCol) 
            maxCol= strlen(arr[count]);
*/    }
    for (int i=0;i<rowDet;i++){
        for (int j=0; j<maxCol; j++) {
            array[i][j]=arr[j];
        }
    }
    cout<<maxCol<<endl;
    return maxCol;
}

void sort(char array[][COLMAX],int rowIn,int colIn) {
    
}

void print(const char array[][COLMAX],int rowIn,int colIn) {
    cout<<"The Sorted Array\n";
    for (int i=0; i<rowIn; i++) {
        for (int j=0;j<colIn;j++)
        cout<<array[i][j];
    }
    cout<<endl;
}