#include "House.h"
#include "Player.h"
#include <iostream>
#include <vector>    //For hold each player's hand
using namespace std;

//Constructor
House::House(int numPlayer, int startingOut)
{
    v = new vector<string>[numPlayer];
    
    gameOver = false;
    
    player = new Player [numPlayer];
    
    for(int i = 0; i < numPlayer; i++)
        player[i].setChips(startingOut);
        
    this->numPlayer = numPlayer;
    
    playerLost = new bool [numPlayer]; //Allocates boolean to number players
                                        //to check if in-game or lost
    
    for(int i = 0; i < numPlayer; i++)
        playerLost[i] = false;  
    
    for(int i = 0; i < numDeck; i++)
        for(int j = 0; j < numUnique; j++)
        {
            usedCards[i][j] = false;
        }
}

//Destructor
House::~House()
{
    for(int i = 0; i < numPlayer;i++)
        v[i].clear();
    delete[] playerLost;
    delete[] player;
}

bool House::checksVictor()
{
    int i = 0;
    bool playerWins = false;
    bool houseWins = false;
    
    while(i < numPlayer && !playerWins)
    {
        if(player[i].getHandVal() == handCap)
            playerWins = true;
        
        i++;
    }
    
    if(playerWins)
    {
        cout<<"Congratulations! Player "<<i<<" has won the game!\n";
        cout<<"With $"<<player[i].getChips()<<" remaining.\n";
        gameOver = true;

    }
    else 
    {
    
        for(int i = 0; i < numPlayer; i++)
            if(playerLost[i] == true)
                houseWins = false;

        if(houseWins)
        {
            cout<<"No players remaining.\nThe House Wins!\n";
            gameOver = true;
        }
    }   
    
    return gameOver;
}

void House::setUsedCards(const int nDeck, const int nCard)
{
    usedCards[nDeck][nCard] = true;
}

int House::getNumPlayerIngame()
{
    int numCurrentPlayer = 0;
    for(; numCurrentPlayer < numPlayer; numCurrentPlayer++)
    {
        
    }
        
    return numCurrentPlayer+1;
}

//Decides whether if an ACE should be 1 or 11
short int House::aceModify(const short int playerHandVal)
{
    if(playerHandVal+11 <= handCap)
        return 11;
    else
        return 1;
}

//Returns worth of a card
short int House::getACardVal(const char cardVal, const short int handVal)
{
    if(cardVal == 'A')
        return aceModify(handVal);
    else if(cardVal == '1' || cardVal == 'J'  || cardVal == 'Q'  || 
            cardVal == 'K' )
        return 10;
    else 
        return cardVal - 48; //Converts char ASCII value into an int
}


string House::cardPicker()
{
    int nDeck = rand()%numDeck;
    int nCard = rand()%numUnique;
        
    while(usedCards[nDeck][nCard] != false){
        nDeck = rand()%numDeck;
        nCard = rand()%numUnique;
        
    };
    
    setUsedCards(nDeck, nCard);

    string chosenCard = C[nDeck].deck[nCard];
    
return chosenCard; }

void House::displayStats(const int cntPlayer)
{
    cout<<"\nPlayer "<<cntPlayer+1<<" / "<<getNumPlayerIngame()+1;
    cout<<"\nChips: $"<<player[cntPlayer].getChips();
    cout<<"\nHand: "<<player[cntPlayer].getHandVal();
    cout<<"\n---------------------------------\n";
}

void House::displayHand(const int cntPlayer)
{
    cout<<"\nPlayer "<<cntPlayer+1<<"'s hand: ";
    
    for(vector<string>::iterator it = v->begin(); it != v->end(); it++)
        cout<<*it<<" ";
    
    cout<<endl;
}

void House::assignCard(const int cntPlayer)
{
    string chosenCard = cardPicker();
            
    v[cntPlayer].push_back(chosenCard);
                
    int cardVal = getACardVal(chosenCard[0], player[cntPlayer].getHandVal());
                
    player[cntPlayer].setHandVal(cardVal);
}

void House::gameplay()
{
    char input;
    
    //Pre-places 2 cards for each player
    for(int i = 0; i < 2; i++)
        for(int cntPlayer = 0; cntPlayer < numPlayer; cntPlayer++)
        {
            displayStats(cntPlayer);
            
            assignCard(cntPlayer);
            
            displayHand(cntPlayer);
        }
    
    
    while(checksVictor() == false)
    {
        
        for(int cntPlayer = 0; cntPlayer < numPlayer; cntPlayer++)
        {
            //Skips to the next player if current player already lost
            while(playerLost[cntPlayer] == true && cntPlayer < numPlayer)
            {
                cntPlayer++;
            }
            
            displayStats(cntPlayer);
            
            do{
                cout<<"\nEnter H (hit) or S (stand): ";
                cin>>input;

                if(input == 'h' || input == 'H')
                {
                    input = 'H';
                    cout<<"Player "<<cntPlayer+1<<" has chosen to HIT!\n";
                }
                else if(input == 's' || input == 'S')
                {
                    input = 'S';
                    cout<<"Player "<<cntPlayer+1<<" has chosen to STAND!\n";
                }
                else
                    cout<<"\nError: Input is wrong!\n";
            
            }while(input != 'S' && input != 'H');
            
            if(input == 'H')
            {
                assignCard(cntPlayer);
                displayHand(cntPlayer);
            }
            else
                cout<<"\nPlayer "<<cntPlayer<<" had chosen to STAY.\n";
    
            
        }
    }
}