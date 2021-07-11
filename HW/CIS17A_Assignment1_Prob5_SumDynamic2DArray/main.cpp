#include <iostream>

using namespace std;


int **getData(int &,int &);              //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);            //Deallocate memory
int sum(const int * const *, int,int);   //Return the Sum

int main(){
    
    int **array, ROW, COL;
    
    array=getData(ROW, COL);
    prntDat(array, ROW, COL);
    cout<<sum(array, ROW, COL);
    destroy(array, ROW, COL);
    
	return 0;
}

int **getData(int &ROW,int &COL){              //Return the 2-D array and its size.
    cin>>ROW>>COL;
    int **array = new int *[ROW];       //allocates memory for each row in array
    for(int i=0;i<ROW;i++){
        array[i] = new int[COL];        //allocates memory for amount of columns in array 
        for (int j=0;j<COL;j++){
            cin>>array[i][j];
        }
    }
    return array;
}

void prntDat(const int* const *array,int ROW,int COL){//Print the 2-D Array
    for (int i=0;i<ROW;i++) {
        for (int j=0;j<COL;j++){
            if (j==COL-1) cout<<array[i][j];     //Excludes space if it the last number
            else cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void destroy(int **array, int ROW, int COL){            //Deallocate memory
    for (int i=0;i<ROW;i++) {
        delete [] array[i];       //deletes each column
    }
    delete array;
}

int sum(const int *const *array, int ROW,int COL){   //Return the Sum
    int sum=0;
    for (int i=0;i<ROW;i++){
        for (int j=0;j<COL;j++) {
            sum+=array[i][j];       //for loop to sum all elements together
        }
    }
    return sum;
}