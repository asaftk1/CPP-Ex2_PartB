#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"
#include "game.hpp"

using namespace ariel;

int Player::stacksize() 
{
    return deck.get_m_cards().size();
}

int Player::cardesTaken() {   
    
    return winning_deck.get_m_cards().size();
}
