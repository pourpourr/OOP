#ifndef __ITEM__
#define __ITEM__
#include "Card.hpp"

#include <iostream>

using namespace std;

class GreenCard;

class Item:public GreenCard{
protected:
  int durability;
public:
  Item(string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost,int dur);
  int getDurability();
  void decreaseDurability();
  void print();

};

class Katana:public Item{
public:
  Katana(string name);
  void print();
};

class Spear:public Item{
public:
  Spear(string name);
  void print();
};

class Bow:public Item{
public:
  Bow(string name);
  void print();
};

class Ninjato:public Item{
public:
  Ninjato(string name);
  void print();
};

class Wakizashi:public Item{
public:
  Wakizashi(string name);
  void print();
};
#endif
