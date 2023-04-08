#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"

namespace ariel {
    class Game {
      
      int Draw = 0;
      std::string lastTurn;  
      Deck m_deck; 
      Deck m_tie_deck;
      Player& m_pl1;
      Player& m_pl2; 
      vector<string> log;
    public:
        Game(Player& pl1, Player& pl2);
        void setLastTurn(std::string str)
        {
            lastTurn = std::move(str);
        }
        string getLastTurn()
        {
            return lastTurn;
        }
        void playTurn();
        void playAll();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void creat_player_decks();
    };
}

#endif 