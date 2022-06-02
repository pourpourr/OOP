#include "Card.hpp"
using namespace std;

int Card::getCost(){
  return cost;
}
string Card::getName(){
  return name;
}
bool Card::getIsTapped(){
  return isTapped;
}
Card::Card(string n,int c, bool t): cost(c),name(n), isTapped(t) {}

int Card::getType(){
  return type;
}

void Card::unTap(){
  isTapped= true;
}
void Card::Tap(){
  isTapped=false;
}

GreenCard::GreenCard(string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost):Card(name,cost,isTapped){
  attackbonus = atkb;
  defencebonus = defb;
  minimumhonour = min;
  cardtext = t;
  effectbonus = efbon;
  effectcost = efcost;
}
int GreenCard::getAttack(){
  return attackbonus;
}
int GreenCard::getDefence(){
  return defencebonus;
}
int GreenCard::getMinHonour(){
  return minimumhonour;
}
int GreenCard::getEffectBonus(){
  return effectbonus;
}
int GreenCard::getBonusCost(){
  return effectcost;
}

void GreenCard::applyBonus(){
  attackbonus+=effectbonus;
  defencebonus+=effectbonus;
}


BlackCard::BlackCard(string name,int cost,bool isTapped,bool isR):Card(name,cost,isTapped){
  isRevealed = isR;
}
bool BlackCard::getIsRevealed(){
  return isRevealed;
}
void BlackCard::Reveal(){
  isRevealed = true;
}
void BlackCard::Hide(){
  isRevealed = false;
}
//kai gia stronghold? kai oxi to panw constructor?
