#include <iostream>   
#include <cstdlib>   
#include <iomanip>   
using namespace std; 

struct MovieInfo{
    string movName; //name of Movie
    char *dirName;  //directors name
    unsigned short yrRlsd; //year released
    unsigned short runTime;//run time of movie
};

int main(int argc, char** argv) {
    
    const int TOOBIG=10;
    MovieInfo mveInfo[TOOBIG];
    int nMovies;//How many movies?
    
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;               
    
    for(int mvees=0;mvees<nMovies;mvees++){
        cin.ignore();              
        getline(cin,mveInfo[mvees].movName);//get name of movie 
        int size=81; //creating a dynamic array
        mveInfo[mvees].dirName=new char[size];
        cin.getline(mveInfo[mvees].dirName,size-1);//Array Structure element
        cin>>mveInfo[mvees].yrRlsd;//inputted year released
        cin>>mveInfo[mvees].runTime;//runtime of movie
        
        
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<mveInfo[mvees].runTime<<endl;
    }
    
    //delete dynamic array to free memory
    for(int mvees=0;mvees<nMovies;mvees++){
        delete [] mveInfo[mvees].dirName;
    }

    //Exit stage right!
    return 0;
}