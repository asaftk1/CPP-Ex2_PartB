#include <iostream>
#include <string>
#include "card.hpp"
#include "deck.hpp"
using namespace ariel;
using namespace std;
   
   
    void Deck::creat_starting_deck()
    {
        
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 1; rank <= 13; ++rank) {

                m_deck.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
            }
        }
        shuffle();
    }

    void Deck::print(vector<Card> deck)  {
        for (const auto& card : deck) {
            card.print();
            std::cout << ", ";
        }
        std::cout<< std::endl;
    }

    void Deck:: shuffle() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
    }


