#include <iostream>

using namespace std;

int **getData(int &,int &);                 //Get the Matrix Data
void printDat(const int * const *,int,int); //Print the Matrix
int **augment(const int * const *,int,int); //Augment the original array
void destroy(int **,int);                   //Destroy the Matrix, i.e., reallocate memory

int main(){
	int ROW, COL;
	int **array;
	
	cin>>ROW>>COL;
	
	array=getData(ROW, COL);
	printDat(array, ROW, COL);
	cout<<endl;
	array=augment(array, ++ROW, ++COL);
	printDat(array, ROW, COL);

	
	return 0;
}

int **getData(int &ROW,int &COL){                 //Get the Matrix Data
    int **arr = new int *[ROW];
    
    for(int i=0;i<ROW;i++){
        arr[i] = new int [COL];
    }
    
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            cin>>arr[i][j];
        }
    }
    return arr;
}

void printDat(const int *const *array, int ROW, int COL){ //Print the Matrix
    for (int i=0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (j==COL-1) cout<<array[i][j];
            else cout<<array[i][j]<<" ";
        }
        if (i==ROW-1) ;
            else cout<<endl;
    }
}

int **augment(const int * const *array, int ROW, int COL){ //Augment the original array
    int **augary = new int *[ROW];
    for (int i=0;i<ROW;i++){
        augary[i]=new int [COL];
        for (int j=0;j<COL;j++){
            if (i==0) augary[i][j] = 0;
            else if (j==0) augary[i][j] = 0;
            else augary[i][j]=array[i-1][j-1];
        }
    }
    return augary;
}

void destroy(int **array, int ROW){                   //Destroy the Matrix, i.e., reallocate memory
    for (int i=0;i<ROW;i++)
    delete [] array [i];
}