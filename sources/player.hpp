#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "card.hpp"
#include "deck.hpp"

namespace ariel {
    class Player {
        public:
        std :: string name;  
        Deck deck;
        Deck winning_deck; 
        
        int TurnCount = 0;
        int WinsCount = 0;
        int stacksize();
        int cardesTaken();     
        
        Player(const std::string& name):name(name){
           
        }  
        Player();
    };
}

#endif 