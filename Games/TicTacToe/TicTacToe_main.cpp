/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToe_main.cpp
 * Author: Kevin Vo
 *
 * Created on June 17, 2020, 1:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

//Constant variable 
const int d = 3;    //Dimension of gameboard
const char AI_in = 'O';

void gameBoard_FN(char gb[][d], const int x, const int y, const char c);
bool isClear(const char gb[][d], const int x, const int y);
bool checkWin(const char gb[][d], bool &);
void gameplay(char gb[][d]);
void showGameboard(const char gb[][d]);

void gameBoard_FN(char gb[][d], const int x, const int y, const char c)
{
    if(x < 3 && y < 3 && y >= 0 && x >= 0)
    {
        gb[x][y] = c;
    }
    
}

bool isClear(const char gb[][d], const int x, const int y)
{    
    if(gb[x][y] == ' ')
    {
        return true;
    }

    return false;
}

void gameplay(char gb[][d])
{
    bool won; //Checks winning condition
    bool playerWon; //checks if player has won
    do
    {
        showGameboard(gb);
        
        int AI_x, AI_y; //AI inputs for x & y coord.
        int P_x, P_y;   //Player inputs for x & y coord.

        bool playerCleared = false;

        playerWon = false; //checks if player has won

        cout<<endl;
        cout<<"-------------------\n";
        cout<<"|  Player's Turn  |\n";
        cout<<"-------------------\n";
        //Prompts user to input x & y
        while(!playerCleared)
        {
            //Prompts player for input
            cout<<"\nInput X: ";
            cin>>P_x;
            cout<<"Input Y: ";
            cin>>P_y;
            cout<<endl;

            playerCleared = isClear(gb, P_x, P_y);

            if(!playerCleared)
                cout<<"\n("<<P_x<<","<<P_y<<") has been filled.\n";
            else
                gameBoard_FN(gb, P_x, P_y, 'X');
        
        }
    

        showGameboard(gb);


        cout<<endl;
        cout<<"-------------------\n";
        cout<<"|    AI's Turn    |\n";
        cout<<"-------------------\n";
        
        //Allows AI to input x & y
        //Check for clear spots for AI
        AI_x = rand()%3;
        AI_y = rand()%3;

        do
        {
        
            if(isClear(gb, AI_x, AI_y))
            {
                gameBoard_FN(gb, AI_x, AI_y, AI_in);
                break;
            }
            else
            {
                AI_x = rand()%2+1;
                AI_y = rand()%2+1;
            }
            cout<<"\n\tX = "<<AI_x<<"\tY = "<<AI_y<<endl;
        }while(1);
        
        cout<<"\n\tX = "<<AI_x<<"\tY = "<<AI_y<<endl;
        
        //Checks winning condition
        won = checkWin(gb, playerWon);

       
    
    }while(!won);
    
    if(won && playerWon)
            cout<<"\n\nCongratulations! You WIN!\n";
        else if(won && !playerWon)
            cout<<"\n\nYou LOSE!\n";
}

bool checkWin(const char gb[][d], bool & playerWon)
{
    const int numSymb = 2;                  //Number of symbols used = 2; X & Y
    const int sym[numSymb] = {'Y', 'X'};    //Holds symbols X & Y to check
    
    for(int i = 0; i < numSymb; i++)
    {
        playerWon = i;
        
        //Checks verticals 
        if(gb[0][0] == sym[i] && gb[1][0] == sym[i] && gb[2][0] == sym[i])
            return true;
        else if(gb[0][1] == sym[i] && gb[1][1] == sym[i] && gb[2][1] == sym[i])
            return true;
        else if(gb[0][2] == sym[i] && gb[1][2] == sym[i] && gb[2][2] == sym[i])
            return true;

        //Checks horizontals
        else if(gb[0][0] == sym[i] && gb[0][1] == sym[i] && gb[0][2] == sym[i])
            return true;
        else if(gb[1][0] == sym[i] && gb[1][1] == sym[i] && gb[1][2] == sym[i])
            return true;
        else if(gb[2][0] == sym[i] && gb[2][1] == sym[i] && gb[2][2] == sym[i])
            return true;

        //Checks crosses
        else if(gb[0][0] == sym[i] && gb[1][1] == sym[i] && gb[2][2] == sym[i])
            return true;
        else if(gb[2][0] == sym[i] && gb[1][1] == sym[i] && gb[0][2] == sym[i])
            return true;
    }
    
    return false;
    
}
int main(int argc, char** argv) 
{
    
    srand(time(NULL));
    
    //Setting up game board
    char gb[d][d] = { 
                             ' ', ' ', ' ',
                             ' ', ' ', ' ',
                             ' ', ' ', ' ',
                                            };
    

    gameplay(gb);
 
    return 0;
}

void showGameboard(const char gb[][d])
{
    cout<<endl;


    cout<<gb[0][0]<<" | "<<gb[0][1]<<" | "<<gb[0][2]<<"\t"<<"00"<<" | "<<"01"<<" | "<<"02" <<endl;
    cout<<"-----------\t-----------\n";
    cout<<gb[1][0]<<" | "<<gb[1][1]<<" | "<<gb[1][2]<<"\t"<<"10"<<" | "<<"11"<<" | "<<"12"<<endl;
    cout<<"-----------\t-----------\n";
    cout<<gb[2][0]<<" | "<<gb[2][1]<<" | "<<gb[2][2]<<"\t"<<"20"<<" | "<<"21"<<" | "<<"22"<<endl;

    
    
    cout<<endl;
};