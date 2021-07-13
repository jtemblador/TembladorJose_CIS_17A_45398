#include <iostream>
#include <iomanip>

using namespace std;

struct Stats{
    float ttrn;
    int htemp;
    int ltemp;
};

void getData(Stats *, int);
void calcData(Stats *, int , float &, float &, int &, int &);

enum allmonths { January, Feburary, March, April, May, June};

int main(){
    const int NUMMNTHS=6;
    Stats months[NUMMNTHS];
    float avgrn=0;
    float avgtemp=0;
    int ltemp=0;
    int htemp=0;
    
    getData(months, NUMMNTHS);
    calcData(months, NUMMNTHS, avgrn, avgtemp, ltemp, htemp);
    
	return 0;
}

void getData(Stats months[], int NUMMNTHS) {
    allmonths index; 
    for (int i=0; i<NUMMNTHS; i++) {
        cout<<"Enter the total rainfall for the month:\n";
        cin>>months[i].ttrn;
        cout<<"Enter the high temp:\n";
        cin>>months[i].htemp;
        cout<<"Enter the low temp:\n";
        cin>>months[i].ltemp;
    }
}

void calcData(Stats months[], int NUMMNTHS, float &avgrn, float &avgtemp, int &ltemp, int &htemp) {
    //Calculates average rainfall
    avgrn=0;
    avgtemp=0;
    ltemp=months[January].ltemp;
    htemp=months[January].htemp;
    allmonths index; 
    for (index=January; index<=June; index=static_cast<allmonths>(index+1)) {
        avgrn+=months[index].ttrn;  //Adds rainfall of every month
        avgtemp+=months[index].htemp;
        avgtemp+=months[index].ltemp;   //adds both high and low temps of every month
        if (ltemp>months[index].ltemp) {    //finds lowest temp of each month
            ltemp=months[index].ltemp;
        }
        if (htemp<months[index].htemp) {    //finds highest temp of each month
            htemp=months[index].htemp;
        }
    }
    avgrn/=NUMMNTHS;
    avgtemp/=NUMMNTHS*2;
    
    cout<<fixed<<setprecision(2);
    cout<<"Average monthly rainfall:"<<avgrn<<endl;
    cout<<"High Temp:"<<htemp<<endl;
    cout<<"Low Temp:"<<ltemp<<endl;
    cout<<fixed<<setprecision(1);
    cout<<"Average Temp:"<<avgtemp;
}