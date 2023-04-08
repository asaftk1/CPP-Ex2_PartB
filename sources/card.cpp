#include "card.hpp"
using namespace ariel;
std::string Card:: to_string() const {
        std::string rankStr;
        switch (m_rank) {
            case Rank::ACE:
                rankStr = "Ace";
                break;
            case Rank::JACK:
                rankStr = "Jack";
                break;
            case Rank::QUEEN:
                rankStr = "Queen";
                break;
            case Rank::KING:
                rankStr = "King";
                break;
            default:
                rankStr = std::to_string(static_cast<int>(m_rank));
                break;
        }

        std::string suitStr;
        switch (m_suit) {
            case Suit::CLUBS:
                suitStr = "Clubs";
                break;
            case Suit::DIAMONDS:
                suitStr = "Diamonds";
                break;
            case Suit::HEARTS:
                suitStr = "Hearts";
                break;
            case Suit::SPADES:
                suitStr = "Spades";
                break;
            default:
                break;
        }

        return rankStr + " of " + suitStr;
    }