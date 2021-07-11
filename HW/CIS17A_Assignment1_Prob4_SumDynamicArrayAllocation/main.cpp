#include <iostream>

using namespace std;

int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

int main(){
	int a;
	
	int *array=getData(a);      //retrieves data
	int *sum=sumAry(array, a);  //sums the array
	
	prntAry(array, a);    //prints array
	cout<<endl;
	prntAry(sum, a);      //prints sum
	
	return 0;
}

int *getData(int &a) {           //Return the array size and the array from the inputs
    int *array = new int [a];
    cin>>a;

    for(int i=0;i<a;i++)
        cin>>array[i];
    
    return array;
}

int *sumAry(const int *array,int a){   //Return the array with successive sums
    int *sum = new int [a];

    sum[0]=array[0];
    for (int i=1; i<a; i++)
        sum[i]=sum[i-1]+array[i];
    
    return sum; 
}

void prntAry(const int *arry,int a) { //Print the array
    for (int i=0; i<a; i++) {
        if (i==a-1) cout<<arry[i];
        else cout<<arry[i]<<" ";
    }
}