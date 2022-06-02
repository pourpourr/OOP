#ifndef __FOLLOWER__
#define __FOLLOWER__
#include "Card.hpp"
#include <iostream>
using namespace std;

class GreenCard;


class Follower :public GreenCard{
public:
  Follower (string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost);
  void print();

};

class FootSoldier:public Follower{
  public:
  FootSoldier(string name);
  void print();
};
class Archer:public Follower{
  public:
  Archer(string name);
  void print();
};
class Sieger:public Follower{
  public:
  Sieger(string name);
  void print();
};
class Cavalry:public Follower{
  public:
  Cavalry(string name);
  void print();
};
class Atakebune:public Follower{
  public:
  Atakebune(string name);
  void print();
};
class Bushido:public Follower{
  public:
  Bushido(string name);
  void print();
};
#endif
