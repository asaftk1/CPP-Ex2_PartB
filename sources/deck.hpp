#ifndef DECK_HPP
#define DECK_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.hpp"
using namespace std;

namespace ariel{

class Deck {
    private:
    vector<Card> m_deck;
    
    public:
    
    void print(vector<Card>)  ;

    void creat_starting_deck();

    void shuffle() ;

    vector<Card>& get_m_cards()  {
        return m_deck;
    }
};   
}

#endif 