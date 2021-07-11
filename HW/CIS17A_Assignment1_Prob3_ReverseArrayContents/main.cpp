#include <iostream>

using namespace std;
int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);     //Sort in reverse order
void prntDat(const int *,int);     //Print the array

int main(){
    int size;
    int *array;
    cin>>size;
    array=getData(size);
    array=sort(array, size);
    prntDat(array, size);
    cout<<endl;
    array=reverse(array, size);
    prntDat(array, size);
    
	return 0;
}

int *getData(int &size){                //Fill the array
    int *array = new int [size];    //creating dynamic array
    for (int i=0;i<size;i++){
        cin>>array[i];
    }
    return array;
}

int *sort(const int *array,int size){         //Sort smallest to largest
    int temp;
    int *srtary = new int [size];
    for (int i=0;i<size;i++)
        srtary[i]=array[i];
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            if (srtary[i] < srtary[j]) {
                     temp = srtary[i];
                srtary[i] = srtary[j];
                srtary[j] = temp;
            }
            
        }
    }
    return srtary;
}

int *reverse(const int *array,int size){      //Sort in reverse order
    int temp;
    int *srtary = new int [size];
    for (int i=0;i<size;i++)
        srtary[i]=array[i];
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            if (srtary[i] > srtary[j]) {
                     temp = srtary[i];
                srtary[i] = srtary[j];
                srtary[j] = temp;
            }
            
        }
    }
    return srtary;
}

void prntDat(const int *array,int size){      //Print the array
    for (int i=0;i<size;i++){
        if (i<size-1) cout<<array[i]<<" ";
        else cout<<array[i];
    }
}