#include "Personality.hpp"

using namespace std;


Personality::Personality(string name,int cost,bool isTapped,bool isR,int a,int d,int h ):BlackCard(name,cost,isTapped,isR){
  attack = a;
  defence = d;
  honor = h;
  isDead = false;
  type = 1;
  numOfGreen=0;
//  followersitems = NULL;
}

int Personality::getNumOfGreen(){
  return numOfGreen;
}

void Personality::decreaseHonor(){
  --honor;
}

void Personality::print(){
  /*cout<<"Cost: "<<cost<<endl;
  if(getIsTapped()){
    cout<<"Tapped"<<endl;
  }else{
    cout<<"Untapped"<<endl;
  }
  cout<<"Attack: "<<attack<<endl;
  cout<<"Defence: "<<defence<<endl;
  cout<<"Honor: "<<honor<<endl;
  if(isDead){
    cout<<"Dead"<<endl;
  }else{
    cout<<"Alive"<<endl;
  }
  std::cout << "followersitems----" << '\n';
  for(int i = 0;i<numOfGreen;i++){
    followersitems[i]->print();
  } */
}

void Personality::addFollowerItem(GreenCard* G){//kai edw
  followersitems.insert(followersitems.begin(),G);
  numOfGreen++;
}
int Personality::getAttack(){
  return attack;
}
int Personality::getDefence(){
  return defence;
}
int Personality::getHonor(){
  return honor;
}
bool Personality::getState(){
  return isDead;
}

void Personality::setDead(){
  isDead = true;
}


void Personality::detach(GreenCard * G){
  int place;
  for(int i = 0;i<numOfGreen;i++){
    if(followersitems[i] == G){
      place = i;
    }
  }
  GreenCard* temp = followersitems[place];
  followersitems[place] = followersitems[numOfGreen-1];
  followersitems[numOfGreen -1] = temp;
  followersitems.pop_back();
  numOfGreen--;
}
void Personality::itemDecrease(){

  for(int i =0;i<numOfGreen;i++){
    if(followersitems[i]->getType() == 4){
      Item* temp= dynamic_cast<Item*>(followersitems[i]);
      temp->decreaseDurability();
      if(temp->getDurability() == 0){
        detach(followersitems[i]);
        numOfGreen--;
      }
    }
  }
}
int Personality::getTotalAttack(){
 int temp = 0;
  for(int i = 0; i<numOfGreen; i++){
    if(followersitems[i]!=NULL){
      temp += followersitems[i]->getAttack();
    }
  }
  temp+=attack;
  return temp;
}
int Personality::getTotalDefence(){
 int temp = 0;
  for(int i = 0; i<numOfGreen; i++){//to size edw einai? osa exei mesa?
    if(followersitems[i]!=NULL){
      temp += followersitems[i]->getDefence();//getters
    }
  }
  temp+=defence;
  return temp;
}


Attacker::Attacker(string n):Personality(n,5,false,false,3,2,2){//to isRevealed de kserw ti mpainei opote to evala false pantou

}
Defender::Defender(string n):Personality(n,5,false,false,2,3,2){

}
Champion::Champion(string n):Personality(n,15,false,false,10,5,8){

}
Chancellor::Chancellor(string n):Personality(n,15,false,false,5,10,8){

}
Shogun::Shogun(string n):Personality(n,30,false,false,20,20,12){

}

void Attacker::print(){
  cout<<"Attacker:"<< name<<endl;
  Personality::print();
}

void Defender::print(){
  cout<<"Defender:"<< name<<endl;
  Personality::print();

}

void Champion::print(){
  cout<<"Champion:"<< name<<endl;
  Personality::print();

}

void Chancellor::print(){
  cout<<"Chancellor:"<< name<<endl;
  Personality::print();

}
void Shogun::print(){
  cout<<"Shogun:"<< name<<endl;
  Personality::print();

}
