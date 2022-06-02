#include "Holding.hpp"
using namespace std;


Holding::Holding(string name,int cost,bool isTapped,bool isR,int val):BlackCard(name,cost,isTapped,isR){
  harvestValue = val;
  type = 2;
}
int Holding::getHarvestValue(){
  return harvestValue;
}

void Holding::print(){
  /*cout<<"Cost: "<<cost<<endl;
  if(getIsTapped()){
    cout<<"Tapped"<<endl;
  }else{
    cout<<"Untapped"<<endl;
  }
  if(getIsRevealed()){
    cout<<"Revealed"<<endl;
  }else{
    cout<<"Not Revealed"<<endl;
  }
  cout<<"Harvest value: "<<harvestValue<<endl;*/
}

Stronghold::  Stronghold (string n):Holding(n,5,false,false,5){

    honour= 5;
    initialDefence=5;

}

int Stronghold:: getHonour(){

    return honour;
}
int Stronghold:: getMoney(){

    return harvestValue;
}
int Stronghold:: getInitialDefence(){

    return initialDefence;
}

Plain::Plain(string n):Holding(n,2,false,false,2){

}
Mine::Mine(string n):Holding(n,5,false,false,3){

}
GoldMine::GoldMine(string n):Holding(n,7,false,false,5){

}
CrystalMine::CrystalMine(string n):Holding(n,12,false,false,6){

}
Farmland::Farmland(string n):Holding(n,3,false,false,4){

}
GiftsandFavour::GiftsandFavour(string n):Holding(n,2,false,false,2){

}

void Stronghold::print(){
  cout<<"Stronghold:"<< name<<endl;
  /*cout<<"Cost: "<<cost<<endl;
  if(getIsTapped()){
    cout<<"Tapped"<<endl;
  }else{
    cout<<"Untapped"<<endl;
  }
  if(getIsRevealed()){
    cout<<"Revealed"<<endl;
  }else{
    cout<<"Not Revealed"<<endl;
  }
  cout<<"Initial defence: "<<initialDefence<<endl;
  cout<<"Starting money: "<<harvestValue<<endl;
  cout<<"Starting Honour: "<<honour<<endl;*/
}
void Plain::print(){
  cout<<"Plain:"<< name<<endl;
  Holding::print();


}
void Mine::print(){
  cout<<"Mine:"<< name<<endl;
  Holding::print();

}
void GoldMine::print(){
  cout<<"GoldMine:"<< name<<endl;
  Holding::print();

}
void CrystalMine::print(){
  cout<<"CrystalMine:"<< name<<endl;
  Holding::print();

}
void Farmland::print(){
  cout<<"Farmland:"<< name<<endl;
  Holding::print();

}
void GiftsandFavour::print(){
  cout<<"GiftsandFavour:"<< name<<endl;
  Holding::print();

}
