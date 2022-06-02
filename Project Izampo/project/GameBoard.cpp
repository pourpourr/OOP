#include "GameBoard.hpp"

GameBoard::GameBoard(){
  numOfFighters = NUM_OF_FIGHTERS;
  Stronghold* strong;
  for(int i=0 ; i< numOfFighters; i++){
    strong= new Stronghold(nameMaker());
    fighters.push_back(new Player(CreatorNamer(),strong));
  }
}


void GameBoard::Play(){
  int i,choice;
  while (numOfFighters!=1) {
    for( i=0 ; i< numOfFighters; i++){
      fighters[i]->startingPhase();
    }
    for( i=0 ; i< numOfFighters; i++){
      fighters[i]->equipPhase();
    }
    std::cout << "ACTIVE PLAYERS" << '\n';
    for( i=0 ; i< numOfFighters; i++){
      std::cout << i <<". " << '\n';
      fighters[i]->printPlayer();
    }
    for(i=0 ; i< numOfFighters; i++){
      
      do{
        std::cout << "Fighter " <<fighters[i]->getName()<< " choose your opponent "<< '\n';
        std::cin >> choice;
        if(choice!=i && choice>=0 && choice<numOfFighters&&fighters[choice]->checkPlayer()){
          fighters[i]->battlePhase(*fighters[choice]);
          break;
        }else std::cout << "Player is dead or bad number given . Try again" << '\n';

      }while(true);

    }
    for(i=0 ; i< numOfFighters; i++){

      fighters[i]->economyPhase();
    }
    for(i=0 ; i< numOfFighters; i++){
      fighters[i]->endPhase();
    }

    i=numOfFighters;
    while(--i>=0){
        if(!fighters[i]->checkPlayer()){
          fighterRemove(i);
        }
    }

  }
  std::cout << "AND THE WINNER IIIIIIIS  " << fighters[0]->getName()<< '\n';
}

void GameBoard::fighterRemove(int pos){
  Player* temp = fighters[pos];
  fighters[pos]= fighters[numOfFighters-1];
  fighters[numOfFighters-1]=temp;
  fighters.pop_back();
  numOfFighters--;

}
