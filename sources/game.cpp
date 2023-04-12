#include "game.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace ariel;


Game::Game(Player& pl1, Player& pl2): m_pl1(pl1), m_pl2(pl2)
{
   
    m_deck.creat_starting_deck();
    creat_player_decks();

}

void Game::creat_player_decks()
{  
    for (int i = 0; i < m_deck.get_m_cards().size()-1; i+=2) {
        
         m_pl1.deck.get_m_cards().push_back((Card(m_deck.get_m_cards()[static_cast<std::vector<Card>::size_type>(i)].get_rank(),m_deck.get_m_cards()[static_cast<std::vector<Card>::size_type>(i)].get_suit())));
         m_pl2.deck.get_m_cards().push_back((Card(m_deck.get_m_cards()[static_cast<std::vector<Card>::size_type>(i+1)].get_rank(),m_deck.get_m_cards()[static_cast<std::vector<Card>::size_type>(i+1)].get_suit())));
 
    }  
    
    
}

void Game::playTurn()
{ 
    cout << "pla SS = " << m_pl1.stacksize() << std::endl;
    
   if(m_pl1.stacksize() == 0 || m_pl2.stacksize() == 0)
        {
            throw std:: runtime_error("Activating another turn after the game is over -- ERORRRRR");
        }
    
   if(&m_pl1 == &m_pl2)
   {
    throw std:: runtime_error("One player");
   }
   m_pl1.TurnCount++;
   m_pl2.TurnCount++;

    Card& p1_card = m_pl1.deck.get_m_cards().back();

    Card& p2_card = m_pl2.deck.get_m_cards().back();

    
    while(static_cast<int>(p2_card.get_rank()) == static_cast<int>(p1_card.get_rank()) && m_pl1.stacksize() != 0)
    {
        log.push_back(m_pl1.name + " played " + p1_card.to_string() + ". " + m_pl2.name + " played " + p2_card.to_string() + ". " + " Draw.");
             Draw++;

            m_pl1.deck.get_m_cards().pop_back();
            m_pl2.deck.get_m_cards().pop_back();


            m_tie_deck.get_m_cards().push_back(p1_card);
            m_tie_deck.get_m_cards().push_back(p2_card);

           
            if (m_pl1.stacksize() != 0)
            {
            Card& p1_revers_card = m_pl1.deck.get_m_cards().back();
            Card& p2_revers_card = m_pl2.deck.get_m_cards().back();

            m_pl1.deck.get_m_cards().pop_back();
            m_pl2.deck.get_m_cards().pop_back();

            m_tie_deck.get_m_cards().push_back(p1_revers_card);
            m_tie_deck.get_m_cards().push_back(p2_revers_card);

            p1_card = m_pl1.deck.get_m_cards().back();
            p2_card = m_pl2.deck.get_m_cards().back();
            }

            
            if(static_cast<int>(p2_card.get_rank()) == static_cast<int>(p1_card.get_rank()))
            {
                 m_pl1.TurnCount++;
                 m_pl2.TurnCount++;
            }

        }

        /////////cards were finished while tie brake///////////
        if(m_pl1.stacksize() == 0 && m_tie_deck.get_m_cards().size() > 0)
        {
            if(m_tie_deck.get_m_cards().size() == 2)
            {
                Card& c1 = m_pl1.deck.get_m_cards().back();
                
                m_pl1.winning_deck.get_m_cards().push_back(c1);
                m_tie_deck.get_m_cards().pop_back();

                Card& c2 = m_pl2.deck.get_m_cards().back();
                m_pl2.winning_deck.get_m_cards().push_back(c2);
                m_tie_deck.get_m_cards().pop_back();
            }
            else
            {
                while(!m_tie_deck.get_m_cards().empty()) 
                { 
                    m_pl1.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                    m_pl2.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                    m_tie_deck.get_m_cards().pop_back();
                    m_tie_deck.get_m_cards().pop_back();
                }
                m_pl1.deck.shuffle();
                m_pl2.deck.shuffle();
                
            }
        }

         if(static_cast<int>(p1_card.get_rank()) < static_cast<int>(p2_card.get_rank()))
        {
            if(static_cast<int>(p1_card.get_rank()) == 1 && static_cast<int> (p2_card.get_rank()) != 2)
            {
           m_pl1.winning_deck.get_m_cards().push_back(p1_card);
           m_pl1.winning_deck.get_m_cards().push_back(p2_card);
           m_pl1.WinsCount++;
           m_pl1.deck.get_m_cards().pop_back();
            m_pl2.deck.get_m_cards().pop_back();
           setLastTurn(m_pl1.name + " played " + p1_card.to_string() + " " + m_pl2.name + " played " + p2_card.to_string() + ". " + m_pl1.name + " wins.");           // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
           while(!m_tie_deck.get_m_cards().empty())
           {
                m_pl1.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                m_tie_deck.get_m_cards().pop_back();
           }
        }
        else 
        {
            m_pl1.deck.get_m_cards().pop_back();
            m_pl2.deck.get_m_cards().pop_back();

            m_pl2.winning_deck.get_m_cards().push_back(p1_card);
            m_pl2.winning_deck.get_m_cards().push_back(p2_card);
            m_pl2.WinsCount++;
            setLastTurn(m_pl1.name + " played " + p1_card.to_string() + ". " + m_pl2.name + " played " + p2_card.to_string() + ". " + m_pl2.name + " wins.");
            while(!(m_tie_deck.get_m_cards().empty()))
           {
                m_pl2.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                m_tie_deck.get_m_cards().pop_back();
           }
        }
   
    }
    else if(static_cast<int>(p2_card.get_rank()) < static_cast<int>(p1_card.get_rank()))
    {
          if(static_cast<int>(p2_card.get_rank()) == 1 && static_cast<int>(p1_card.get_rank()) != 2)

        {
           m_pl2.winning_deck.get_m_cards().push_back(p1_card);
           m_pl2.winning_deck.get_m_cards().push_back(p2_card);
           m_pl2.WinsCount++;
           m_pl1.deck.get_m_cards().pop_back();
           m_pl2.deck.get_m_cards().pop_back();

           setLastTurn(m_pl1.name + " played " + p1_card.to_string() + ". " + m_pl2.name + " played " + p2_card.to_string() + ". " + m_pl2.name + " wins.");
            while(!m_tie_deck.get_m_cards().empty())
           {
                m_pl2.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                m_tie_deck.get_m_cards().pop_back();
           }
        }
        else 
        {
            m_pl1.winning_deck.get_m_cards().push_back(p1_card);
            m_pl1.winning_deck.get_m_cards().push_back(p2_card);
            m_pl1.WinsCount++;
            m_pl1.deck.get_m_cards().pop_back();
            m_pl2.deck.get_m_cards().pop_back();
            
            setLastTurn(m_pl1.name + " played " + p1_card.to_string() + ". " + m_pl2.name + " played " + p2_card.to_string() + ". " + m_pl1.name + " wins.");
            while(!m_tie_deck.get_m_cards().empty())
           {
                m_pl1.winning_deck.get_m_cards().push_back(m_tie_deck.get_m_cards().back());
                m_tie_deck.get_m_cards().pop_back();
           }
        }  
    }  
    cout << "tie deck "<<m_tie_deck.get_m_cards().size()<<std::endl;
    log.push_back(getLastTurn());
}



void Game::playAll()
{
    while(m_pl1.stacksize() != 0 && m_pl2.stacksize() != 0 )
    {
        playTurn();
    }     
}


void Game:: printLastTurn() 
{
    std::cout << getLastTurn() << std::endl;
}


void Game:: printWiner() 
{
    if(m_pl1.winning_deck.get_m_cards().size() > m_pl2.winning_deck.get_m_cards().size())
    {
        cout << m_pl1.name << std::endl;
    }
    else if(m_pl1.winning_deck.get_m_cards().size() < m_pl2.winning_deck.get_m_cards().size())
    {
        cout << m_pl2.name << std::endl;
    }
    else cout << "Its a tie" << std::endl;
}


void Game::printLog()
{
    while(!log.empty())
    {
        if (!log.empty()) { // make sure log is not empty before popping and outputting
        auto lastLog = log.back(); // get the last element of the log vector
        log.pop_back(); // remove the last element from the log vector
        cout << lastLog << endl; // output the removed element
}
    }
}
// for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
              // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void Game::printStats()
{
    double winRate_pl1 = static_cast<double>(m_pl1.WinsCount) / m_pl1.TurnCount;
    double winRate_pl2 = static_cast<double>(m_pl2.WinsCount) / m_pl2.TurnCount;
    double DrawRate = static_cast<double>(Draw) / m_pl1.TurnCount;
    cout<<std::endl;
    cout<< "Player: "<< m_pl1.name << " win rate: " << winRate_pl1 << ", " << "card won: " << m_pl1.cardesTaken() << "." << std::endl;
    cout<< "Player: "<< m_pl2.name << " win rate: " << winRate_pl2 << ", " << "card won: " << m_pl2.cardesTaken() << "." << std::endl;
    cout << "draw rate: "<< DrawRate << " draws that happand: "<< Draw << std::endl;

}

