/* 
 * File:   main.cpp
 * Author: Jose Temblador
 * Created on 7/1/21 7:23 PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd) {
    cout<<"Input the number of integers to input.\n";
    int size;
    cin>>size;
    cout<<"Input each number.\n";
    for (int i=0; i<size; i++) 
    {
        int a;
        cin>>a;
        if (a%2==1) odd.push_back(a);
        else even.push_back(a);
    }
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]) {
    for (int i=0; i<even.size(); i++)
    array[i][0]=even[i];
    for (int i=0; i<odd.size(); i++)
    array[i][1]=odd[i];
}

void prntVec(vector<int> even, vector<int> odd,int size) {
    cout<<"    Vector      Even       Odd\n";
    int a=0;
    if (even.size()>odd.size()) a=even.size();
    else a=odd.size();
    for (int i=0; i<a; i++)
    {
        cout<<right<<"          "<<setw(size);
        if (i<even.size()) cout<<even[i];
        else cout<<"         "; 
        if (i<odd.size()) cout<<setw(size)<<odd[i]<<endl;
        else cout<<"          \n"; 
    }
}

void prntAry(const int array[][COLMAX],int even,int odd,int size) {
    cout<<"     Array      Even       Odd\n";
    int a;
    if (even>odd) a=even;
    else a=odd;
    for(int i=0;i<a; i++) 
    {
        cout<<right<<"          "<<setw(size);
        if (i<even) cout<<array[i][0];
        else cout<<"          "; 
        if (i<odd) cout<<setw(size)<<array[i][1]<<endl;
        else cout<<"          \n"; 
    }
}