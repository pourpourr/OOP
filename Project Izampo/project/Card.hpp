#ifndef __CARD__
#define __CARD__
#include <iostream>
#include <string>
using namespace std;

class Card{
    protected:
      string name;
      int cost;
      bool isTapped;
      int type;
    public:
      string getName();
      int getCost();
      bool getIsTapped();
      Card(string n,int c,bool t);
      int getType();
      void unTap();
      void Tap();
      virtual void print() =0;


};
class GreenCard:public Card{
protected:
  int attackbonus;
  int defencebonus;
  int minimumhonour;
  string cardtext;
  int effectbonus;
  int effectcost;
public:
  GreenCard(string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost);
  int getAttack();
  int getDefence();
  int getMinHonour();
  string getText();
  int getEffectBonus();
  int getBonusCost();
  void applyBonus();
  //virtual void decreaseDurability();
  //virtual int getDurability();
  };


class BlackCard:public Card{
protected:
  bool isRevealed;
public:
  BlackCard(string name,int cost,bool isTapped,bool isR);
  bool getIsRevealed();
  void Reveal();
  void Hide();
//  virtual int getDefence();
};

//to stronghold de katalavainw an thelei holding h black card giati uparxei to arxiko kai to holding
// class Plain():public Holding {
// private:
//
// public:
//   Plain ();
//
// };Mine
#endif
