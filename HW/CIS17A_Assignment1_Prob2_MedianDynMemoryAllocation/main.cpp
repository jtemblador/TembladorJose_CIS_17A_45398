#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);     //Print the integer array
float *median(int *,int);    //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *, int);       //Print the median Array

int main(){
	int size;
	cin>>size;
	int *array=getData(size);
	prntDat(array, size);
	cout<<endl;
	float *medary=median(array, size);
	prntMed(medary, size);
	return 0;
}

int *getData(int &size){         //Return the array size and the array
    int *array= new int [size];
    for(int i=0; i<size; ++i)
        cin>>array[i];
    return array;
}

void prntDat(int *array,int size){    //Print the integer array
    for(int i=0;i<size;i++)
        if (i<size-1) cout<<array[i]<<" ";
        else cout<<array[i];
}

float *median(int *array, int size){  //Fill the median Array with the Float array size, the median, and the integer array data
    float *medary = new float [size+2];
    medary[0]=1.0*(size+2);
    if (size%2!=0) {
        float med = *(array + (size/2));
        medary[1]=med;
    }
    else {
        int index1=(size/2)-1;
        int index2=size/2;
        float med=(*(array + index1)+*(array+index2))/ 2.0;
        medary[1]=med;
    }
    for (int i=2;i<size+2;i++){
        medary[i]=1.0*array[i-2];
    }
    return medary;
}

void prntMed(float *medary, int size){     //Print the median Array
    cout<<medary[0]<<" ";
    for (int i=1;i<size+2;i++){
       if (i<size+1) cout<<setprecision(3)<<showpoint<<medary[i]<<" ";
       else cout<<setprecision(3)<<showpoint<<medary[i];
    }
}