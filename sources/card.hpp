#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
namespace ariel {
class Card {
public:
    enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(Rank rank, Suit suit)
        : m_rank(rank), m_suit(suit)
    {
    }

    Rank get_rank() const {
        return m_rank;
    }

    Suit get_suit() const {
        return m_suit;
    }
    void print() const {
        switch (m_rank) {
            case Rank::ACE:
                std::cout << "Ace";
                break;
            case Rank::JACK:
                std::cout << "Jack";
                break;
            case Rank::QUEEN:
                std::cout << "Queen";
                break;
            case Rank::KING:
                std::cout << "King";
                break;
            default:
                std::cout << static_cast<int>(m_rank);
                break;
        }
    }
    std::string to_string() const;
private:
    Rank m_rank;
    Suit m_suit;
};

}
#endif 
