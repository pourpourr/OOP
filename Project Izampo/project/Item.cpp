#include <iostream>
#include "Item.hpp"
using namespace std;


Item::Item(string name,int cost,bool isTapped,int atkb,int defb,int min,string t,int efbon,int efcost,int d):GreenCard( name, cost, isTapped, atkb, defb, min, t, efbon, efcost){
  durability = d;
  type= 4;
}

void Item::print() {
  /*  cout<<"Cost: "<<cost<<endl;
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
    cout<<"Effect Cost: "<<effectcost<<endl;
    cout<<"Durability: "<<durability<<endl; */
}
int Item::getDurability(){
  return durability;
}
void Item::decreaseDurability(){
  --durability;
}

Katana::Katana(string name):Item(name,0,false,2,0,1,"",1,2,3){}
Spear::Spear(string name):Item(name,0,false,0,2,1,"",1,2,3){}
Bow::Bow(string name):Item(name,2,false,2,2,2,"",3,4,5){}
Ninjato::Ninjato(string name):Item(name,4,false,3,3,3,"",2,2,4){}
Wakizashi::Wakizashi(string name):Item(name,8,false,5,5,3,"",3,3,8){}

void Katana::print(){
  cout<<"Katana:"<< name<<endl;
  Item::print();

}
void Spear::print(){
  cout<<"Spear:"<< name<<endl;
  Item::print();

}
void Bow::print(){
  cout<<"Bow:"<< name<<endl;
  Item::print();

}
void Ninjato::print(){
  cout<<"Ninjato:"<< name<<endl;
  Item::print();

}
void Wakizashi::print(){
  cout<<"Wakizashi:"<< name<<endl;
  Item::print();

}
