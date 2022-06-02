#ifndef __HOLDING__
#define __HOLDING__
#include "Card.hpp"

#include <iostream>

using namespace std;

class BlackCard;


class Holding:public BlackCard {
protected:
  int harvestValue;

public:
  Holding (string name,int cost,bool isTapped,bool isR,int val);
  int getHarvestValue();
  void print();

};

class Stronghold:public Holding{
protected:
  int honour;
  int initialDefence;
public:
  Stronghold (string n);
  int getHonour();
  int getInitialDefence();
  int getMoney();
  void print();
};
//h fash me ta enum thelei doulema
class Plain:public Holding {
public:
  Plain (string n);
  void print();
};
class Mine:public Holding {
public:
  Mine (string n);
  void print();
};
class GoldMine:public Holding {
public:
   GoldMine(string n);
   void print();
};
class CrystalMine:public Holding {
public:
  CrystalMine (string n);
  void print();
};
class Farmland:public Holding {
public:
  Farmland (string n);
  void print();
};
class GiftsandFavour:public Holding {
public:
  GiftsandFavour (string n);
  void print();
};
#endif
