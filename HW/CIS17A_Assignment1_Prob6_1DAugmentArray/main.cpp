#include <iostream>

using namespace std;

int *getData(int &);            //Read the array
int *augment(const int *,int);  //Augment and copy the original array
void prntAry(const int *,int);  //Print the array

int main(){
    int size;
    cin>>size;
    int *array = getData(size);
    prntAry(array, size);
    cout << endl;
    array = augment(array, size);
    prntAry(array, size+1);
    
	return 0;
}

int *getData(int &size){            //Read the array
    int *array = new int [size];
    for (int i=0; i<size; i++) {
        cin >> array[i];
    }
    return array;
}

int *augment(const int *array, int size){  //Augment and copy the original array
    int *augary = new int [size+1];
    augary[0]=0;
    for (int i=0;i<size;i++){
        augary[i+1]=array[i];
    }
    return augary;
}

void prntAry(const int *array,int size){  //Print the array
    for (int i = 0; i<size; i++) {
        if (i==size-1) cout<<array[i];
        else cout << array[i] << " ";
    }
}