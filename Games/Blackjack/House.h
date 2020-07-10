/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   House.h
 * Author: Kevin Vo
 *
 * Created on July 9, 2020, 7:21 PM
 */

#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <vector>    //For hold each player's hand
#include "Player.h"

using namespace std;

//Constant global variables
const int numCardType = 13;
const int handCap = 21;
const int numDeck = 8;
const int numUnique = numCardType * 4;

class House{

private:
    vector<string> *v;
    Player *player;
    short int aceModify(const short int);
    bool *playerLost;
    int numPlayer;
    bool gameOver;
    bool usedCards[numDeck][numUnique];
    void displayStats(const int);
    void assignCard(const int);
    void displayHand(const int);
    
public:  
    House(int, int);    //Constructor
    ~House();    //Destructor
    short int getACardVal(const char, const short int);
    bool checksVictor();
    int getNumPlayerIngame();
    void setUsedCards(const int, const int);
    void gameplay();
    //bool *getUsedCards() const { return usedCards; }
    
    struct Cards
    {
        const string deck[numUnique] = {    "AS","AH","AC","AD",
                                            "2S","2H","2C","2D",
                                            "3S","3H","3C","3D",
                                            "4S","4H","4C","4D",
                                            "5S","5H","5C","5D",
                                            "6S","6H","6C","6D",
                                            "7S","7H","7C","7D",
                                            "8S","8H","8C","8D",
                                            "9S","9H","9C","9D",
                                            "10S","10H","10C","10D",
                                            "JS","JH","JC","JD",
                                            "QS","QH","QC","QD",
                                            "KS","KH","KC","KD"     };

    } C[numDeck];      
    
    string cardPicker();
};


#endif /* HOUSE_H */

