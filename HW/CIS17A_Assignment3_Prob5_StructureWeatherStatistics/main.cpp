#include <iostream>
#include <iomanip>

using namespace std;

struct Stats{
    string mnth;
    int ttrn;
    int htemp;
    int ltemp;
    int atemp;
};

void getData(Stats *, int);
void calcData(Stats *, int , float &, float &, string &, int &, string &, int &);
void readData(Stats *, int , float, float , string , int , string , int );


int main(){
    const int NUMMNTHS=12;
    Stats months[NUMMNTHS];
    float avgrn=0;
    float avgtemp=0;
    string lowtemp;
    int ltemp=0;
    string hitemp;
    int htemp=0;
    
    getData(months, NUMMNTHS);
    calcData(months, NUMMNTHS, avgrn, avgtemp, lowtemp, ltemp, hitemp, htemp);
    readData(months, NUMMNTHS, avgrn, avgtemp, lowtemp, ltemp, hitemp, htemp);
    
	return 0;
}

void getData(Stats months[], int NUMMNTHS) {
    for (int i=0; i<NUMMNTHS; i++) {
        cin>>months[i].mnth>>months[i].ttrn>>months[i].ltemp>>months[i].htemp;
    }
}

void calcData(Stats months[], int NUMMNTHS, float &avgrn, float &avgtemp, string &lowtemp, int &ltemp, string &hitemp, int &htemp) {
    //Calculates average rainfall
    avgrn=0;
    avgtemp=0;
    lowtemp=months[0].mnth;
    hitemp=months[0].mnth;
    ltemp=months[0].ltemp;
    htemp=months[0].htemp;
    for (int i=0; i<NUMMNTHS; i++) {
        avgrn+=months[i].ttrn;  //Adds rainfall of every month
        avgtemp+=months[i].htemp;
        avgtemp+=months[i].ltemp;   //adds both high and low temps of every month
        if (ltemp>months[i].ltemp) {    //finds lowest temp of each month
            ltemp=months[i].ltemp;
            lowtemp=months[i].mnth;
        }
        if (htemp<months[i].htemp) {    //finds highest temp of each month
            htemp=months[i].htemp;
            hitemp=months[i].mnth;
        }
    }
    avgrn/=NUMMNTHS;
    avgtemp/=NUMMNTHS*2;
}

void readData(Stats months[], int NUMMNTHS, float avgrn, float avgtemp, string lowtemp, int ltemp, string hitemp, int htemp) {
    cout<<fixed<<setprecision(1);
    cout<<"Average Rainfall "<<avgrn<<" inches/month"<<endl;
    cout<<"Lowest  Temperature "<<left<<setw(8)<<lowtemp<<right<<setw(3)<<ltemp<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<left<<setw(8)<<hitemp <<right<<setw(3)<<htemp<<" Degrees Fahrenheit"<<endl;
    cout<<fixed<<setprecision(0);
    cout<<"Average Temperature for the year "<<avgtemp<<" Degrees Fahrenheit"<<endl;
}