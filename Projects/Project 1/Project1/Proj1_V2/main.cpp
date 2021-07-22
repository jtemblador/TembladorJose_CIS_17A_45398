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
const int SIZE=20;
struct User {
    char name[SIZE];
    unsigned int hand;
};

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void dlrHnd (string [], string [], int [], int , bool, int &, int &, unsigned char=0); //Gets dealer's hand
void HorF (string [], string [], int &, int, bool, User &, int []); //Asks player to hit/fold
bool checkAce (unsigned char &, bool , User); //Player check ace function
bool linSrch(string [], int [], int [], int , int );    //Linear Search Function
bool checkAceDlr (unsigned char &, bool , int &);          //Dealer checkAce function 
//void printHand(int [], string [], int); //Prints player's hand
unsigned char rndmNum(unsigned char);   //Finds random number
void SlSort(int [], int );       //Sorts the array 
int *Fill (int [], int);          //creates and fills array 
void PrintHand(int *, int, string []);     //Prints users hand

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    User player;
    player.hand=0;
    const unsigned char nCards=52; 
    const unsigned char MAXCARD=10;
    unsigned char rawnum=0;
    unsigned int *hand;
    int cardnum1=0,      //Card index number 1
        cardnum2=1,      //Card index number 2
        dlrhand,         //Dealer's hand
        crdnms1[MAXCARD],//name of card for index 1
        crdnms2[MAXCARD];//name of card for index 2
    float bet;           //User's bet
    string allcards[nCards+1];//Array of all card suits and numbers
    string cards[nCards+1];  
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
/************************************************************************************/    
    cout<<"Welcome! What's your name?\n";  
    cin.getline(player.name, SIZE);
//    cin.ignore();
    cout<<"Place your bet! Cents are allowed.\n"
          "This high stakes Blackjack. All bets are squared by itself.\n";
    cin>>bet;
    cout<<"*********************************************************************\n";
    do {
        rawnum=rndmNum(nCards);             //gets a random card number
        crdnms1[cardnum1]=rawnum;            //Raw Card number is put into an array (players hand)
        cards[cardnum1]=allcards[rawnum];   //assigns random card from card set to player hand
        rawnum=rawnum%13;       //Mods card number by 13 to give it a value
        
        ace=checkAce(rawnum, ace, player);    //Checks to see if player has ace
        
        if (rawnum==0||rawnum==11||rawnum==12||rawnum==13) //Face cards equal 10
            player.hand+=10;
        else if (rawnum==14)   //first ace card is worth 11
            player.hand+=11;
        else player.hand+=rawnum;  //every other card is assigned its number value
        
        cout<<"Card number "<<cardnum1+1<<" is  "<<cards[cardnum1]<<endl<<
              "Your hand is    "<<setw(3)<<player.hand<<endl<<endl;
        cardnum1++;
    } while (cardnum1<2);
    
    if (player.hand==21)
        cout<<"Looks like your hand is already at 21\n"
              "Lets see what the dealer has.\n";
    else HorF(cards, allcards, cardnum1, nCards, ace, player, crdnms1);
    cout<<"*********************************************************************\n";
    ace=false;
    dlrHnd (dlr, allcards, crdnms2, nCards, ace, cardnum2, dlrhand, rawnum);
    cout<<"*********************************************************************\n";

    //Map Inputs to Outputs -> Process
    
    //Display Inputs/Outputs
    
            //If user and dealer hand is over 21, nobody wins
            //If user or dealer hand is over 21, opponent wins
            //If user and dealer below 21, both hands are compared and 
            //greatest hand is determined the winner
            //If user wins, displays amount won
    SlSort(crdnms1, cardnum1);              //Sorts th players hand
    int *srtarry=Fill(crdnms1, cardnum1);   //Fills a dynamic array with the sorted array
    cout<<player.name<<", your cards in order are as follows. (Hearts>Clubs>Diamonds>Spades)\n";
    PrintHand(srtarry, cardnum1, allcards);           //Prints the dynamic array
    
    out.open(rsltOut,ios::out);
    hand= &player.hand;
    out<<"Your hand is     "<<*hand<<".\n";
    out<<"Dealer's hand is "<<dlrhand<<".\n";
            
    if ((player.hand>21)&&(dlrhand>21)) out<<"You and the dealer went over. Nobody wins!\n";
    else if (player.hand>21) out<<"You went over, the Dealer wins!"<<endl;
    else if (dlrhand>21) 
    {
        out<<fixed<<setprecision(2);
        out<<"The Dealer went over, "<<player.name<<" wins!"<<endl;
        out<<"\nYou won "<<pow(bet, 2.0)<<"!";
    }
    else
    {       //Ternary operator to determine winner
        winner=(player.hand>dlrhand)?"Congrats, you won!":
               (dlrhand>player.hand)?"The Dealer won.":"Tie! Nobody won.";
        out<<winner<<endl;
    }                                   //Added this last part that shows how
    if (winner=="Congrats, you won!")   //much you won after betting
    {                                   //in the beginning
        out<<fixed<<setprecision(2);                           
        out<<"The Dealer went over, "<<player.name<<" wins!"<<endl;
        out<<"\nYou won $"<<pow(bet, 2.0)<<"!";
    }
 
        cout<<"\nThe game is over!\n"                                            
        "Results are displayed in the output file named 'results.dat'\n";  
        
    //Exit the Program - Cleanup
    input.close();
    out.close();
    return 0;
}

void PrintHand(int *array, int size, string allcards []) {
    for (int i=0; i<size; i++) {
        cout<<"Card "<<i+1<<" is "<<allcards[*(array+i)]<<endl;
    }
}

int *Fill(int a[],int n) {
    int *array= new int [n]; //Creating Dynamic Array
    for(int i=0; i<n; ++i)
        array[i]=a[i];       //Filling dynamic array of previously sorted array
    return array;            //returning dynamic 
}

void SlSort(int a[],int n){
    for(int i=0;i<n;i++){      //Loop for each position in List
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

void dlrHnd (string dlr[], string allcards[], int crdnms2[], int nCards, bool ace, 
             int &cardnum2, int &dlrhand, unsigned char rawnum) {
    dlrhand=0;
    
    cout<<"It is now the Dealers turn.\n"<<endl;
        while (dlrhand<=16)       //Once dealer reaches 16 or greater, loop ends
    {                      
        rawnum=rndmNum(nCards);         //gets a random card number
        crdnms2[cardnum2]=rawnum;       //Raw Card number is put into an array (players hand)
        dlr[cardnum2]=allcards[rawnum]; //assigns random card from card set to player hand
        rawnum=rawnum%13;               //Mods card number by 13 to give it a value
        
        ace=checkAceDlr(rawnum, ace, dlrhand);    //Checks to see if player has ace
        
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

bool checkAceDlr (unsigned char &rawnum, bool ace, int &hand) {//Dealer's checkAce function
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

void HorF(string cards[], string allcards[], int &cardnum1, int nCards, 
          bool ace, User &player, int crdnms1[]) {
    unsigned char decide;
    unsigned char rawnum=0;
    cout<<"Would you like to hit or fold?"<<endl<<
          "Type H to hit or any other key to fold"<<endl;
        cin>>decide;
        cout<<endl;
        if (static_cast<int>(decide)=='h')  decide-=32;
        
        for (cardnum1=2;decide=='H'&&player.hand<21;cardnum1++)  //Only repeats if decision is hit or
    {                                                   //hand is below 21
        rawnum=rndmNum(nCards);             //gets a random card number
        crdnms1[cardnum1]=rawnum;            //Raw Card number is put into an array (players hand)
        cards[cardnum1]=allcards[rawnum];
        rawnum=rawnum%13;       //Mods card number by 13 to give it a value
        
        ace=checkAce(rawnum, ace, player);    //Checks to see if player has ace
        
        if (rawnum==0||rawnum==11||rawnum==12||rawnum==13) //Face cards equal 10
            player.hand+=10; 
        else if (rawnum==14)   //first ace card is worth 11
            player.hand+=11;
        else player.hand+=rawnum;  //every other card is assigned its number value
        
        cout<<"Card number "<<cardnum1+1<<" is  "<<cards[cardnum1]<<endl<<
              "Your hand is    "<<setw(3)<<player.hand<<endl<<endl;
        
        if (player.hand<21)
        {               //Asks player to hit or fold
            cout<<"Would you like to hit or fold?"<<endl<<
                  "Type H to hit or any other key to fold"<<endl;
            cin>>decide;
            if (static_cast<int>(decide)=='h')  decide-=32;
        }
    }
}

bool checkAce (unsigned char &rawnum, bool ace, User player) {//User's checkAce function
    if (rawnum==1)
    {
        if (ace==true)
        {  //player can only have 1 ace card worth 11, every other ace card after is worth 1
            cout<<"Looks like you already have an ace card.\n"
                  "This card will be worth 1.\n";
            return true;
        }
        else if ((player.hand+rawnum+10)>21)
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

unsigned char rndmNum(unsigned char nCards) {
    return rand()%nCards+1; //Gets a random number from 1-52
}
