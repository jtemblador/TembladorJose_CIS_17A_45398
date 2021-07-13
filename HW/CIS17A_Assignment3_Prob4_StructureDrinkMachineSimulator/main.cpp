#include <iostream>
#include <iomanip>

using namespace std;

struct Soda {
    string name;
    float cost;
    unsigned char stock;
};

void menu(Soda *, const int);
void select(string &, short &);
bool disburse(Soda *, int, string, short , unsigned short &);

int main(){
    const int NUMSODA=5;
    string choice;
    short recvd;
    unsigned short earned=0;
    Soda brand[NUMSODA]={ {"Cola", 75, 20},
                          {"Root Beer", 75, 20},
                          {"Lemon-Lime", 75, 20},
                          {"Grape Soda", 80, 20},
                          {"Cream Soda", 80, 20} };
    
    do {
        menu(brand, NUMSODA);
        select(choice, recvd);
    } while (disburse(brand, NUMSODA, choice, recvd, earned));
    
    
	return 0;
}

void menu(Soda brand[], const int size) {
    for(int i=0;i<size;i++) {
        cout<<left<<setw(11)<<brand[i].name<<brand[i].cost<<"  "<<static_cast<int>(brand[i].stock)<<endl;
    }
}

void select(string &brand, short &change) {
    change=0;
    getline(cin, brand);
    if(brand!="Quit"){
        cin>>change;
        cin.ignore();
    }
    if (change<0||change>100) exit (0);
}

bool disburse(Soda *brand, int NUMSODA, string choice, short recvd, unsigned short &earned) {
    if (choice=="Quit") {
        cout<<choice<<endl<<earned<<endl;
        return false;
    }
    bool found=false;
    cout<<"Quit"<<endl;
    for (int i=0; i<NUMSODA;i++) {
        if(choice==brand[i].name) {
            if(recvd<brand[i].cost){
                exit(0);
            } else {
                if(brand[i].stock>=1){
                    brand[i].stock--;
                    cout<<recvd-brand[i].cost<<endl;
                    earned+=brand[i].cost;
                    found=true;
                }
            }
        }
    }
    return found;
}