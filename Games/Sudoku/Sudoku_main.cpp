/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sudoku_main.cpp
 * Author: Kevin
 *
 * Created on June 29, 2020, 8:19 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

const int dimen = 4; //for 4x4 Sudoku 

void showTable(const short [][dimen]);
void showPositions(const short [][dimen]);
void showOriginalTable(const short [][dimen]);
void clearTable(short [][dimen]);
void randSetupTable(short [][dimen], bool [][dimen]);
bool checkUnique(const short [][dimen], const int, const int, const short);
void checkInputRange(const char, int&, const int, const int);
void input(short [][dimen], const bool [][dimen], int, int, int);
bool checkWin(const short [][dimen], bool []);
void gamePlay(short [][dimen], const short [][dimen], bool [], bool [][dimen]);

void showTable(const short gT[][dimen])
{
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
        {
            cout<<gT[i][j];
            
            if(j%(dimen-1) == 0 && j != 0)
                cout<<endl;
            else
                cout<<" | ";
        }
}

void showPositions()
{
    cout<<endl;
    
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
        {
            cout<<i<<j;
            
            if(j%(dimen-1) == 0 && j != 0)
                cout<<endl;
            else
                cout<<" | ";
        }
    
    cout<<endl;
}


void showOriginalTable(const short orgT[][dimen])
{
    cout<<endl;
    
       for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
        {
            cout<<orgT[i][j];
            
            if(j%(dimen-1) == 0 && j != 0)
                cout<<endl;
            else
                cout<<" | ";
        }
    cout<<endl;
}

void clearTable(short gT[][dimen])
{
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
            gT[i][j] = 0;
}   

void randSetupTable(short gT[][dimen], bool preassignedCells[][dimen])
{
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
        {
            bool isUnique = false;  //checks if row & col of cell doesn't have
                                    //unique value
            short rnd = rand()%9 + 1;   //Assigns random value to sudoku
            int assignProb = rand()%100 + 1;

            if(assignProb >= 70) //Assign ~30% of the time
            {
                while(!isUnique)
                {
                    rnd = rand()%9 + 1;   //Assigns random value to sudoku
                    isUnique = checkUnique(gT, i, j, rnd);
                }
            
                gT[i][j] = rnd;
                preassignedCells[i][j] = true;
            }
        }
}

bool checkUnique(const short gT[][dimen], const int x, const int y, 
        const short inVal)
{
    for(int i = 0; i < dimen; i++)
    {
        if(gT[x][i] == inVal || gT[i][y] == inVal)
        {
            return false;
        }
        
    }
    
    return true;
    
}

void checkInputRange(const char id, int &val, const int lwrBnd, const int upprBnd)
{

    if(id == 'x')
    {
        while(val < lwrBnd || val > upprBnd)
        {
            cout<<"\nX must be ["<<lwrBnd<<","<<upprBnd<<"]. Try again\n";
            cout<<"\nEnter X: ";
            cin>>val;
        }
    }
    else if(id == 'y')
    {
        while(val < lwrBnd || val > upprBnd)
        {
            cout<<"\nY must be ["<<lwrBnd<<","<<upprBnd<<"]. Try again\n";
            cout<<"\nEnter Y: ";
            cin>>val;
        }
    }
}

void input(short gT[][dimen], bool preassignedCells[][dimen],
    int x, int y, int inVal)
{
    while(preassignedCells[x][y] == true)
    {
        cout<<"\nCannot edit. Cell was assigned by game. Try again\n";
        cout<<"\nEnter x: ";
        cin>>x;
        
        checkInputRange('x', x, 0, dimen-1);
        
        cout<<"\nEnter y: ";
        cin>>y;
        
        checkInputRange('y', y, 0, dimen-1);
    }
    
    while(checkUnique(gT, x, y, inVal) == false)
    {
        cout<<"\nThis value already exist in row "<<x<<" column "<<y<<endl;
        cout<<"Please try again.\n";
        
        do{
            cout<<endl<<"Enter value: ";
            cin>>inVal;

            cout<<endl;
        
            if(inVal <= 0 || inVal >= 10)
                cout<<"\nTry again. Value must be 1-9\n";
                
        }while(inVal <= 0 || inVal >= 10);
    }
    
    gT[x][y] = inVal;
}

bool checkWin(const short gT[][dimen], bool filledRows[])
{
    bool gameOver = true;
    
    for(int i = 0; i < dimen; i++)
        if(!filledRows[i])
            for(int j = 0; j < dimen; j++)
            {
                if(gT[i][j] == 0)
                {
                    gameOver = false;
                    i = dimen;
                    break;
                }
                
                if(j == dimen-1 && gameOver == true)
                {
                    filledRows[i] = true;
                }
            }
    
    return gameOver;
}

void gamePlay(short gT[][dimen], const short orgT[][dimen], bool filledRows[], 
        bool preassignedCells[dimen][dimen])
{
    int x, 
        y, 
        inVal;
    while(checkWin(gT, filledRows) == false)
    {
        showTable(gT);
        
        showPositions();
        
        showOriginalTable(orgT);
        
        cout<<endl<<"\nEnter X: ";
        cin>>x;
        
        checkInputRange('x', x, 0, dimen-1);
        
        cout<<endl<<"\nEnter Y: ";
        cin>>y;
        
        checkInputRange('y', y, 0, dimen-1);
        
        do{
            cout<<endl<<"Enter value: ";
            cin>>inVal;

            cout<<endl;
        
            if(inVal <= 0 || inVal >= 10)
                cout<<"\nTry again. Value must be 1-9\n";
                
        }while(inVal <= 0 || inVal >= 10);
        
        input(gT, preassignedCells, x, y, inVal);
    }
}


int main(int argc, char** argv) {
    
    bool filledRows[dimen]; //Labels a row as filled
                            //to exclude from checking
    
    bool preassignedCells[dimen][dimen];
    
    srand(time(NULL));
    
    short int gT[dimen][dimen];  //sudoku table
    
    short int orgT[dimen][dimen]; //clones game table right after setup to
                                  //show preassigned values
    
    
    for(int i = 0; i < dimen; i++)
        filledRows[i] = false;
    
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
            preassignedCells[i][j] = false;
    
    clearTable(gT); //Assigns 0 to all slots
    
    randSetupTable(gT, preassignedCells);
    
    //Clones game table after setup
    for(int i = 0; i < dimen; i++)
        for(int j = 0; j < dimen; j++)
            orgT[i][j] = gT[i][j]; 
            
    gamePlay(gT, orgT, filledRows, preassignedCells);
    
    return 0;
}

