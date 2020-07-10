#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int handVal;    //Hand value for each player
    int chips;  //number of chips a player has
    
public:
    int getHandVal() const { return handVal; }
    int getChips() const { return chips; }
    void setHandVal(const int);
    void setChips(const int);
    Player(); //constructor
    
};


#endif /* PLAYER_H */

