#include <iostream>
#include <vector>
#include "Player.hpp"
#include "namer.h"
#define NUM_OF_FIGHTERS 3

class GameBoard{

  private:
    vector <Player*> fighters;
    int numOfFighters;
  public:
    void fighterRemove(int pos);
    GameBoard();
    void Play();

};
