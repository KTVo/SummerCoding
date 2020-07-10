#include "Player.h"


//Constructor
Player::Player()
{
    handVal = 0;
    chips = 0;
}

//Value a player has in-hand
void Player::setHandVal(const int valNewCard)
{
    handVal += valNewCard;
}

//Calculates number of chips player has left
void Player::setChips(const int gainedChips)
{
    chips += gainedChips;
}

