#include "Follower.hpp"

using namespace std;



Follower::Follower(string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost):GreenCard( name, cost, isTapped, atkb, defb, min, t, efbon, efcost){
  type =3;
}
void Follower::print(){
  /*
  cout<<"Cost: "<<cost<<endl;
  if(getIsTapped()){
    cout<<"Tapped"<<endl;
  }else{
    cout<<"Untapped"<<endl;
  }
  cout<<"AttackBonus: "<<attackbonus<<endl;
  cout<<"DefenceBonus: "<<defencebonus<<endl;
  cout<<"Minimum Honor required: "<<minimumhonour<<endl;
  cout<<"text: "<<cardtext<<endl;
  cout<<"Effect bonus: "<<effectbonus<<endl;
  cout<<"Effect Cost: "<<effectcost<<endl; */

}

FootSoldier::FootSoldier(string name):Follower(name,0,false,2,0,1,"",1,2){}//to text pws tha to diaxeiristoume?
Archer::Archer(string name):Follower(name,0,false,0,2,1,"",1,2){}
Sieger::Sieger(string name):Follower(name,5,false,3,3,2,"",2,3){}
Cavalry::Cavalry(string name):Follower(name,3,false,4,2,3,"",3,4){}
Atakebune::Atakebune(string name):Follower(name,3,false,2,4,3,"",3,4){}
Bushido::Bushido(string name):Follower(name,8,false,8,8,6,"",3,8){}

void FootSoldier::print(){
  cout<<"FootSoldier:"<< name<<endl;
  Follower::print();

}
void Archer::print(){
  cout<<"Archer:"<< name<<endl;
  Follower::print();

}
void Sieger::print(){
  cout<<"Sieger:"<< name<<endl;
  Follower::print();

}
void Cavalry::print(){
  cout<<"Cavalry:"<< name<<endl;
  Follower::print();

}
void Atakebune::print(){
  cout<<"Atakebune:"<< name<<endl;
  Follower::print();

}
void Bushido::print(){
  cout<<"Bushido:"<< name<<endl;
  Follower::print();

}
