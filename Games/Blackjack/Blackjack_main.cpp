#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "House.h"


using namespace std;




int main(int argc, char** argv) {
    
    int numPlayers;
    int startingChips;
    
    cout<<"\nEnter Starting Chips Value: $";
    cin>>startingChips;
    cout<<"\nEnter Number of Players: ";
    cin>>numPlayers;

    House h(numPlayers, startingChips);
    
    h.gameplay();
    
    return 0;
}

