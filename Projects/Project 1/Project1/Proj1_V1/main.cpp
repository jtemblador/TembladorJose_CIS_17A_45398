/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 4, 2021, 10:50 AM
 * Purpose:  CPP Template 
 *           To be copied for each Assignment Problem
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator
#include <iomanip>   //Formats output
#include <cmath>     //Math library
#include <ctime>     //Time Library 
#include <string>    //String Library
#include <fstream>   //File Input/Output Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void dlrHnd (string [], string [], int [], int , bool, int &, int &, unsigned char=0); //Gets dealer's hand
void HorF (string [], string [], int &, int, bool, unsigned int &, int []);
bool checkAce (unsigned char &, bool , unsigned int &); //Player check ace function
void selcSrt(int [], int );             //Selection sort function
void bublSrt(int [], int );             //Bubble sort function
bool linSrch(string [], int [], int [], int , int ); //Linear Search Function
void printHand(int [], string [], int); //Prints player's handzbool checkAce (unsigned char &, bool , int &);      //Dealer checkAce function 
unsigned char rndmNum(unsigned char);  //Finds random number

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const unsigned char nCards=52; 
    const unsigned char MAXCARD=10;
    unsigned char rawnum=0;
    int cardnum1=1,
        cardnum2=1,
        dlrhand,
        crdnms1[MAXCARD],
        crdnms2[MAXCARD];
    unsigned int hand=0;
    float bet;
    string allcards[nCards+1];
    string cards[nCards+1];
    string name;
    string dlr[nCards+1];
    string winner;
    string rsltOut="results.dat";  //Output winner/loser
    bool ace=false;
    
    //Initialize Variables
    fstream input, out;
    string  cardIn;
    string  fileName="card.dat";;


    input.open(fileName.c_str(),ios::in);
    
    for (int i=1; i<=nCards; i++) {
        input>>cardIn;          //file is read in and assigns 
        allcards[i]=cardIn;     //all cards to array allcards
    }

    input.close();
/****************************************************************************************************************/
    unsigned int grtng=rand()%6+1;
    switch(grtng)      //Random greeting at the start of every game
    {
        case 1: cout<<"Welcome to Las Vegas!"<<endl<<endl;break;
        case 2: cout<<"Join us! There's plenty of "
                      "space at the tables."<<endl<<endl;break;
        case 3: cout<<"Back for more?"<<endl<<endl;break;
        case 4: cout<<"I was wondering when I was going to see you again!"<<endl<<endl;break;
        case 5: cout<<"Ready to win?"<<endl<<endl;break;
        default: 
        {
            cout<<"You should come back tomorrow, looks like"  
                  " you've had too much to drink."<<endl;
            exit(0);
        }               //Added exit function
    }

    cout<<"Welcome! What's your name?\n";       
    cin>>name;
    cout<<"Welcome, "<<name<<"."<<endl<<
          "We're playing Blackjack tonight. Please take a seat. "<<endl<<
          "At the end of the round the dealer will show you his hand."<<endl;
    cout<<"*********************************************************************\n";
    cout<<"Place your bet! Cents are allowed.\n"
          "This high stakes Blackjack. All bets are squared by itself.\n";
    cin>>bet;
    cout<<"*********************************************************************\n";
    do {
        rawnum=rndmNum(nCards);             //gets a random card number
        crdnms1[cardnum1]=rawnum;            //Raw Card number is put into an array (players hand)
        cards[cardnum1]=allcards[rawnum];   //assigns random card from card set to player hand
        rawnum=rawnum%13;       //Mods card number by 13 to give it a value
        
        ace=checkAce(rawnum, ace, hand);    //Checks to see if player has ace
        
        if (rawnum==0||rawnum==11||rawnum==12||rawnum==13) //Face cards equal 10
            hand+=10;
        else if (rawnum==14)   //first ace card is worth 11
            hand+=11;
        else hand+=rawnum;  //every other card is assigned its number value
        
        cout<<"Card number "<<cardnum1<<" is  "<<cards[cardnum1]<<endl<<
              "Your hand is    "<<setw(3)<<hand<<endl<<endl;
        cardnum1++;
    } while (cardnum1<=2);
    
    if (hand==21)
        cout<<"Looks like your hand is already at 21\n"
              "Lets see what the dealer has.\n";
        else HorF(cards, allcards, cardnum1, nCards, ace, hand, crdnms1);
    cout<<"*********************************************************************\n";
    ace=false;
    dlrHnd (dlr, allcards, crdnms2, nCards, ace, cardnum2, dlrhand, rawnum);
    cout<<"*********************************************************************\n";

    cout<<"Your cards will now be sorted.\n\nThe order is Spades<Diamonds<Clubs<Hearts.\n"
          "Press 1 for Selection Sort\nPress 2 for Bubble sort"<<endl;
    unsigned int sort;
    cin>>sort;
    switch(sort)
    {
        case 1: selcSrt(crdnms1, cardnum1);break;
        case 2: bublSrt(crdnms1, cardnum1);break;
    }
    cout<<"*********************************************************************\n";
    printHand(crdnms1, allcards, cardnum1);
    
    cout<<"We will now search your hand and the dealer's hand and see if there are any duplicate cards.\n"
          "Press 1 for Linear Search Sort\nPress 2 to skip"<<endl;
    cin>>sort;
    switch(sort)
    {
        case 1: if (linSrch(allcards, crdnms1, crdnms2, cardnum1, cardnum2)) ;
                else cout<<"No match was found\n";break;
        case 2: ;break;
    }
    //unsigned int sort;
    //cin>>sort;
    
    cout<<endl;
    
    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    
            //If user and dealer hand is over 21, nobody wins
            //If user or dealer hand is over 21, opponent wins
            //If user and dealer below 21, both hands are compared and 
            //greatest hand is determined the winner
            //If user wins, displays amount won
    
    out.open(rsltOut,ios::out);
    
    out<<"Your hand is     "<<hand<<".\n";
    out<<"Dealer's hand is "<<dlrhand<<".\n";
            
    if ((hand>21)&&(dlrhand>21)) out<<"You and the dealer went over. Nobody wins!\n";
    else if (hand>21) out<<"You went over, the Dealer wins!"<<endl;
    else if (dlrhand>21) 
    {
        out<<fixed<<setprecision(2);
        out<<"The Dealer went over, "<<name<<" wins!"<<endl;
        out<<"\nYou won "<<pow(bet, 2.0)<<"!";
    }
    else
    {       //Ternary operator to determine winner
        winner=(hand>dlrhand)?"Congrats, you won!":
               (dlrhand>hand)?"The Dealer won.":"Tie! Nobody won.";
        out<<winner<<endl;
    }                                   //Added this last part that shows how
    if (winner=="Congrats, you won!")   //much you won after betting
    {                                   //in the beginning
        out<<fixed<<setprecision(2);                           
        out<<"The Dealer went over, "<<name<<" wins!"<<endl;
        out<<"\nYou won $"<<pow(bet, 2.0)<<"!";
    }
 
        cout<<"\nThe game is over!\n"                                            
        "Results are displayed in the output file named 'results.dat'\n";  
 
  
    //Exit the Program - Cleanup
    input.close();
    out.close();
    return 0;
}

bool linSrch(string allcards[], int crdnms1[], int crdnms2[], int cardnum1, int cardnum2) {
    int a;
    if (cardnum1>=cardnum2) a=cardnum1;
    else a=cardnum2;
    for(int i=1;i<=a;i++){
        for (int j=1;j<=a;j++)
        if(crdnms1[i]==crdnms2[j])
        {   
            cout<<"The matching card is "<<allcards[crdnms1[i]];
            return true;
        }
    }
    return false;
}

void printHand(int crdnms1[], string allcards[], int cardnum1) {
    for(int i=1;i<cardnum1;i++){
        cout<<"Card number "<<i<<" is now "<<allcards[crdnms1[i]]<<"."<<endl;
    }
    cout<<endl;
}

void bublSrt(int a[],int n){
    bool swap;
    do{
        swap=false;
        for(int i=1;i<n-1;i++){  //Loop to swap with first in List
            if(a[i]>a[i+1]){       //Put the smallest at top of List
                a[i]=a[i]^a[i+1];  //In place Swap
                a[i+1]=a[i]^a[i+1];  //In place Swap
                a[i]=a[i]^a[i+1];   //In place Swap
                swap=true;
            }
        }
    }while(swap);
}

void selcSrt(int a[],int n){
    for(int i=1;i<n;i++){      //Loop for each position in List
        int idxMin=i;
        for(int j=i+1;j<n;j++){  //Loop to swap with first in List
            if(a[idxMin]>a[j]){  //Put the smallest at top of List
                idxMin=j;
            }
        }
        int temp=a[i];
        a[i]=a[idxMin];
        a[idxMin]=temp;
    }
}

unsigned char rndmNum(unsigned char nCards) {
    return rand()%nCards+1; //Gets a random number from 1-52
}

void HorF(string cards[], string allcards[], int &cardnum1, int nCards, 
          bool ace, unsigned int &hand, int crdnms1[]) {
    unsigned char decide;
    unsigned char rawnum=0;
    cout<<"Would you like to hit or fold?"<<endl<<
          "Type H to hit or any other key to fold"<<endl;
        cin>>decide;
        cout<<endl;
        if (static_cast<int>(decide)=='h')  decide-=32;
        
        for (cardnum1=3;decide=='H'&&hand<21;cardnum1++)  //Only repeats if decision is hit or
    {                                                   //hand is below 21
        rawnum=rndmNum(nCards);             //gets a random card number
        crdnms1[cardnum1]=rawnum;            //Raw Card number is put into an array (players hand)
        cards[cardnum1]=allcards[rawnum];   //assigns random card from card set to player hand
        rawnum=rawnum%13;       //Mods card number by 13 to give it a value
        
        ace=checkAce(rawnum, ace, hand);    //Checks to see if player has ace
        
        if (rawnum==0||rawnum==11||rawnum==12||rawnum==13) //Face cards equal 10
            hand+=10; 
        else if (rawnum==14)   //first ace card is worth 11
            hand+=11;
        else hand+=rawnum;  //every other card is assigned its number value
        
        cout<<"Card number "<<cardnum1<<" is  "<<cards[cardnum1]<<endl<<
              "Your hand is    "<<setw(3)<<hand<<endl<<endl;
        
        if (hand<21)
        {               //Asks player to hit or fold
            cout<<"Would you like to hit or fold?"<<endl<<
                  "Type H to hit or any other key to fold"<<endl;
            cin>>decide;
            if (static_cast<int>(decide)=='h')  decide-=32;
        }
    }
}

bool checkAce (unsigned char &rawnum, bool ace, unsigned int &hand) {
    if (rawnum==1)
    {
        if (ace==true)
        {  //player can only have 1 ace card worth 11, every other ace card after is worth 1
            cout<<"Looks like you already have an ace card.\n"
                  "This card will be worth 1.\n";
            return true;
        }
        else if ((hand+rawnum+10)>21)
        {   //if hand goes over 21, ace is worth 1
            cout<<"You don't have an Ace, but you will go over"<<
            " if it's counted as 11. This one counts as 1."<<endl;
            return false;
        }
        else 
        {   //if first ace and hand is under 21, ace is worth 11
            cout<<"Your luck! Looks like you got an Ace.\n";
            rawnum=14;
            return true;
        }
    }
    return false;
}

bool checkAce (unsigned char &rawnum, bool ace, int &hand) {
    if (rawnum==1)
    {
        if (ace==true)
        {  //player can only have 1 ace card worth 11, every other ace card after is worth 1
            cout<<"Dealer already have an ace card.\n"
                  "This card will be worth 1.\n";
            return true;
        }
        else if ((hand+rawnum+10)>21)
        {   //if hand goes over 21, ace is worth 1
            cout<<"Dealer doesn't have an Ace, but he'll go over"<<
            " if it's counted as 11. This one counts as 1."<<endl;
            return false;
        }
        else 
        {   //if first ace and hand is under 21, ace is worth 11
            cout<<"Dealer got an Ace.\n";
            rawnum=14;
            return true;
        }
    }
    return false;
}

void dlrHnd (string dlr[], string allcards[], int crdnms2[], int nCards, bool ace, 
             int &cardnum2, int &dlrhand, unsigned char rawnum) {
    dlrhand=0;
    
    cout<<"It is now the Dealers turn.\n"<<endl;
        while (dlrhand<=16)       //Once dealer reaches 16 or greater, loop ends
    {                      
        rawnum=rndmNum(nCards);                //gets a random card number
        crdnms2[cardnum2]=rawnum;            //Raw Card number is put into an array (players hand)
        dlr[cardnum2]=allcards[rawnum];        //assigns random card from card set to player hand
        rawnum=rawnum%13;     //Mods card number by 13 to give it a value
        
        ace=checkAce(rawnum, ace, dlrhand);    //Checks to see if player has ace
        
        if (rawnum==0||rawnum==11||rawnum==12||rawnum==13) //Face cards equal 10
            dlrhand+=10;
        else if (rawnum==14)   //first ace card is worth 11
            dlrhand+=11;
        else dlrhand+=rawnum;  //every other card is assigned its number value
        
        cout<<"Card "<<cardnum2<<" is     "<<dlr[cardnum2]<<".\n";
        cout<<"Dealer is at "<<setw(2)<<dlrhand<<".\n"<<endl;
        cardnum2++;
    } 
}