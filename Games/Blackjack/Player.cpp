#include "Player.h"

#include <iostream>
//Constructor
Player::Player()
{
    handVal = 0;
    chips = 0;
}

//Value a player has in-hand
void Player::setHandVal(const int valNewCard)
{
    std::cout<<"\n00000 handVal + valNewCard = "<<handVal<<" + "<<valNewCard<<std::endl;
    
    handVal += valNewCard;
    
    std::cout<<"\n0000 new handVal = "<<handVal<<std::endl;
}

//Calculates number of chips player has left
void Player::setChips(const int gainedChips)
{
    chips += gainedChips;
}

