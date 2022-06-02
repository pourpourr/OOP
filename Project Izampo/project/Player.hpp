#ifndef __PLAYER__
#define __PLAYER__
#include <iostream>
#include <vector>
#include <string>
#include "DeckBuilder.hpp"
#include "Card.hpp"
#include "Personality.hpp"
#include "Holding.hpp"

#define MAX_ARMY 6
#define MAX_HOLDINGS 4
#define MAX_HAND 6
#define STARTING_HAND 3
#define NUM_OF_PROVINCES 3

using namespace std;


class BlackCard;
class GreenCard;
class Holding;
class Personality;

class Player{
    private:
      string name;
      list<GreenCard *>* fateDeck;
      list<BlackCard *>* dynastyDeck;
      vector <GreenCard *> hand;
      int honour;
      Stronghold* MyStronghold;
      int money;
      vector <BlackCard *> provinces;
      int numberOfProvinces;
      vector <Holding*> holdings;
      vector <Personality*> army;
      int numOfArmy;
      int numOfHoldings;
      int numOfHand;
      int turns ;
      int wins;
      int total_wins;

    public :

      Player(string name, Stronghold* strong);
      void startingPhase();
      GreenCard* drawFateCard();
      BlackCard* drawDynastyCard();
      void CardUnTapping();
      void handRemove(int pos);
      void revealProvinces();
      bool MoneyMaker(int required);
      void economyPhase();
      void equipPhase();
      void endPhase();
      void discardSurplusFateCards();
      void printGameStatistics();
      void printHand();
      void printProvinces();
      void printArmy();
      void printHoldings();
      void battlePhase(Player &opponent);
      void provinceDestroy(int i);
      void bury(int place);
      bool checkPlayer();
      string getName();
      void printPlayer();
};
#endif
