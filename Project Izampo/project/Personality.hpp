#ifndef __PERSONALITY__
#define __PERSONALITY__
#include <iostream>
#include <vector>
#include "Card.hpp"
#include "Item.hpp"

using namespace std;


class BlackCard;
class GreenCard;
class Item;
#define MAX_FOLLOWERS_ITEMS 4


class Personality: public BlackCard{
protected:
  vector <GreenCard*> followersitems;
  int attack;
  int defence;
  int honor;
  bool isDead;
  int numOfGreen;
public:
  Personality (string name,int cost,bool isTapped,bool isR,int a,int d,int h);
  int getAttack();
  int getDefence();
  int getHonor();
  bool getState();
  void addFollowerItem(GreenCard*);
  int getTotalAttack();
  int getTotalDefence();
  void setDead();
  void detach(GreenCard* G);
  void itemDecrease();
  void decreaseHonor();
  int getNumOfGreen();
  void print();


};




class Attacker:public Personality{
public:
  Attacker(string n);
  void print();
};
class Defender:public Personality{
public:
  Defender(string n);
  void print();
};
class Champion:public Personality{
public:
  Champion(string n);
  void print();
};
class Chancellor:public Personality{
public:
  Chancellor(string n);
  void print();
};
class Shogun:public Personality{
public:
  Shogun(string n);
  void print();
};
#endif
