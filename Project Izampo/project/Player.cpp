#include "Player.hpp"

using namespace std;


Player::Player(string n, Stronghold* strong){

  name= n;
  MyStronghold= strong;
  DeckBuilder MyDecks;
  fateDeck=MyDecks.createFateDeck();
  dynastyDeck=MyDecks.createDynastyDeck();
  MyDecks.deckShuffler(fateDeck);
  MyDecks.deckShuffler(dynastyDeck);
  honour= MyStronghold->getHonour();
  money=MyStronghold->getHarvestValue();
  MyStronghold->Tap();
  numberOfProvinces=NUM_OF_PROVINCES;
  numOfArmy=0;
  numOfHand=0;
  numOfHoldings=0;
  turns=0;
  total_wins=0;
  wins=0;
  for(int i =0 ; i< numberOfProvinces; i++){

      provinces.insert(provinces.begin(),drawDynastyCard());
  }
  for(int i =0 ; i< STARTING_HAND; i++){

      hand.insert(hand.begin(),drawFateCard());
      numOfHand++;

  }


}

string Player::getName(){
   return name;
}

void Player::printPlayer(){
  std::cout << "name "<< name << '\n';
  printProvinces();
}

GreenCard* Player:: drawFateCard(){
    GreenCard* temp= fateDeck->front();
    fateDeck->pop_front();
    return temp;
}

BlackCard* Player:: drawDynastyCard(){
    BlackCard* temp= dynastyDeck->front();
    dynastyDeck->pop_front();
    return temp;
}

void Player::CardUnTapping(){

    for(int i=0 ; i< numberOfProvinces; i++){
        provinces[i]->unTap();
    }
    for(int i=0 ; i< numOfArmy; i++){

      army[i]-> unTap();
    }
    for(int i=0 ; i< numOfHoldings; i++){

      holdings[i]-> unTap();
    }
    for(int i=0 ; i<numOfHand; i++){
      hand[i]->unTap();

    }
}

bool Player::MoneyMaker(int required){


    bool flag;
    int sum;
    if(!(MyStronghold->getIsTapped())){
      sum = MyStronghold->getHarvestValue();
    }else sum=0;
    int i =0, tempMoney=money;

    while(sum<required && i<numOfHoldings){

          if(!(holdings[i]->getIsTapped())){
            sum+= holdings[i]->getHarvestValue();
          }

          i++;
    }
    if(sum<required){
      sum+=tempMoney;
      tempMoney=0;
      if(sum<required){
        flag= false;
      }else flag= true;
    }else flag= true;

    if(flag){
      money=sum-required+tempMoney;

      while(--i>=0){
        holdings[i]->Tap();
      }
      MyStronghold->Tap();
      std::cout << "purchase successfull" << '\n';
    }else{

      std::cout << "Not enough money" << '\n';
    }
    return flag;


}

void Player::revealProvinces(){

  for(int i=0 ; i< numberOfProvinces; i++){
      provinces[i]->Reveal();
  }
}

void Player ::startingPhase(){

  std::cout << "startingPhase for " <<name<< '\n';

    CardUnTapping();
    hand.insert(hand.begin(),drawFateCard());
    numOfHand++;
    revealProvinces();
    printHand();
    printProvinces();

}

void Player::economyPhase(){

    if(checkPlayer()){
      std::cout << "economyPhase for " <<name<< '\n';
      int selection ;

      revealProvinces();
      printProvinces();

      if(numOfArmy<MAX_ARMY){
        std::cout << "Give num of province you want to buy or press anything else to abort" << '\n';
        std::cin >> selection;
        while(selection>=0 && selection< numberOfProvinces){
            if(provinces[selection]->getIsRevealed()){
              if (MoneyMaker(provinces[selection]->getCost())){
                    if(provinces[selection]->getType()==1){
                        Personality* tempPers= dynamic_cast<Personality*>(provinces[selection]);
                        army.push_back(tempPers);
                        numOfArmy++;
                    }else{
                        Holding* tempHold= dynamic_cast<Holding*>(provinces[selection]);

                        holdings.push_back(tempHold);
                        numOfHoldings++;
                    }
                    provinces[selection]= drawDynastyCard();
                    provinces[selection]->Hide();
              }else std::cout << "not enough money" << '\n';
            }else std::cout << "Province NOT avaulable to be bought (is hidden)" << '\n';
            std::cout << "Give num of province you want to buy or press anything else to abort" << '\n';
            std::cin >> selection;

          }
        }else std::cout << "Player has reached the max number of army he can have" << '\n';
      }

}

void Player::handRemove(int pos){

    GreenCard* temp;
    temp = hand[pos];
    hand[pos]=hand[numOfHand-1];
    hand[numOfHand-1]=temp;
    hand.pop_back();
    numOfHand--;

}

void Player::equipPhase(){

  std::cout << "equipPhase for " <<name<< '\n';

  if (numOfArmy>0){

    string buyOption,bonus;
    int pers,selection;
    std::cout << "Do you want to equip your Army ?(y/n)" << '\n';
    std::cin >> buyOption;
    while (buyOption=="y") {
        printArmy();
        printHand();
        std::cout << "Give Personality's num " << '\n';
        std::cin >> pers;
        std::cout << "Give GreenCard's num(hand)" << '\n';
        std::cin>> selection;
        if(pers>=0 && selection>=0 && pers< numOfArmy && selection<numOfHand){
          if(hand[selection]->getMinHonour()){
            if(army[pers]->getNumOfGreen()<MAX_FOLLOWERS_ITEMS ){
                if(MoneyMaker(hand[selection]->getCost())){
                    std::cout << "Do you want to apply the bonus?(y/n)" << '\n';
                    std::cin>> bonus;
                    if(bonus=="y"){
                        if(MoneyMaker(hand[selection]->getBonusCost())){
                            hand[selection]->applyBonus();
                        }else std::cout << "not enough money for effect to apply" << '\n';
                    }

                    army[pers]->addFollowerItem(hand[selection]);
                    handRemove(selection);
                }else std::cout << "not enough money" << '\n';
            }else std::cout << "Too many followers and items" << '\n';
          }else std::cout << "Not enough honour" << '\n';
        } else std::cout << "bad number given" << '\n';
        std::cout << "Do you want to equip your Army ?(y/n)" << '\n';
        std::cin >> buyOption;

    }
  }

}

void Player::endPhase(){

  std::cout << "endPhase for " <<name<< '\n';

    discardSurplusFateCards();
    printGameStatistics();
    printHand();
    printArmy();
    printHoldings();
    printProvinces();

}

void Player::printGameStatistics(){
    std::cout << "Player's name " << name<< '\n';
    std::cout << "money " <<money<< '\n';
    std::cout << "honour " << honour<<'\n';
    std::cout << "turns " << turns <<'\n';
    std::cout << "Total wins " <<total_wins<<'\n';
    std::cout << "Wins without opponent's province destroyed "  <<wins << '\n';


}

void Player::discardSurplusFateCards(){
  int place;
  while(numOfHand> MAX_HAND){
    printHand();
    std::cout << "which Green card would you like to discard?" << '\n';
    std::cin>>place;
    handRemove(place);
  }
}



void Player::battlePhase(Player &opponent){
  //attack phase
  std::cout << "BATTLE PHASE FOR " <<name<< '\n';
  int temp = 0,tempattack = 0,tempdefence = 0,target,attackers = 0,choice,toll,k,i;
  turns++;
  vector <Personality*> attackerv;
  if(numOfArmy>0){
      printArmy();
      std::cout<<"pick a personality to activate,or press anything else to activate no personalities"<<endl;
      std::cin>>temp;
      while(temp>=0 && temp< numOfArmy){
          if(!(army[temp]->getIsTapped())){
            std::cout<<"Personality is tapped and cannot be used"<<std::endl;
          }else{
            std::cout<<"Attack with personality? 0 for no 1 for yes"<<std::endl;
            std::cin>>choice;
            if(choice){
              tempattack+=army[temp]->getTotalAttack();
              attackerv.push_back(army[temp]);
              attackers ++;
              army[temp]->Tap();
            }
          }
          std::cout<<"pick another personality to activate,or press anything else to activate no more personalities"<<endl;
          std::cin>>temp;
        }
        std::cout<<"Available provinces to attack are: "<<endl;
        opponent.printProvinces();

        std::cout<<"Pick a province number : (0-"<<opponent.numberOfProvinces-1<<") "<<endl;
        std::cin>>temp;
        std::cout << "DEFENCE PHASE FOR " << opponent.name<< '\n';
        int temp1,defenders = 0;
        vector <Personality*> defenderv;
        std::cout << "DEFENDERS ARMY" << '\n';
        opponent.printArmy();
        if(opponent.numOfArmy==0){
          std::cout << "no ARMY to defend with" << '\n';
        }else{
            std::cout<<"pick a personality to Defend,or press anything else to defend with no personalities"<<endl;
            std::cin>>temp1;
            while (temp1>0 && temp1< opponent.numOfArmy) {

              if(!(opponent.army[temp1]->getIsTapped())){

                  tempdefence+=opponent.army[temp1]->getTotalDefence();
                  defenderv.push_back(opponent.army[temp1]);
                  defenders ++;
                  opponent.army[temp1]->Tap();

              }else cout << "Personality has already been chosen" << '\n';
              std::cout<<"pick another personality to Defend,or press anything else to defend with no more personalities"<<endl;
              std::cin>>temp1;
              opponent.printArmy();
            }

        }
        int provdef = opponent.MyStronghold->getInitialDefence();
        if(opponent.provinces[temp]->getType() == 1){
          Personality* tempPers= dynamic_cast<Personality*>(opponent.provinces[temp]);
          provdef+= tempPers->getDefence();
        }
        tempdefence += provdef;
        std::cout << "----------- Attack = " <<tempattack<< " Defence=  "<<tempdefence<< '\n';
        //meta skotwnoume osous prepei,kanoume detach

        target = tempattack - tempdefence;
        if(target > provdef){
          total_wins++;
          opponent.provinceDestroy(temp);
          for( i = 0; i < defenders;i++){
            defenderv[i]->setDead();
          }
        }else{
          if(target>0){
            wins++;
            toll = 0;
               k = 0;
            while(toll<target){
              attackerv[k]->setDead();
              k++;
              toll += attackerv[k]->getTotalAttack();
            }
            for(i = 0;i<defenders;i++){
              defenderv[i]->setDead();
            }
          }else if(target<0){
              toll = 0;
              k = 0;
              target= target*(-1);
              if(defenders>0){
                while(toll<target){
                  defenderv[k]->setDead();
                  k++;
                  toll += defenderv[k]->getTotalAttack();
                }
              }
              for(i = 0;i<attackers;i++){
                attackerv[i]->setDead();
              }
          }else{
              for(i = 0;i<attackers;i++){
                attackerv[i]->setDead();
              }
              for(i = 0;i<defenders;i++){
                defenderv[i]->setDead();
              }
          }
        }
        for(i = 0;i<attackers;i++){
          attackerv[i]->itemDecrease();
        }
        for(i = 0;i<numOfArmy;i++){
          if(army[i]->getState() || (army[i]->getHonor() == 0)){
            bury(i);
          }

        }
        for(i = 0;i<defenders;i++){
          defenderv[i]->itemDecrease();
        }
        for(i=0;i<opponent.numOfArmy;i++){
          if(opponent.army[i]->getState()||(opponent.army[i]->getHonor() == 0)){
            bury(i);
          }
        }
      }else std::cout << "NO ARMY TO BATTE FOR " << name<< '\n';
  }

bool Player::checkPlayer(){

  if(numberOfProvinces==0)
    return false;
  else
    return true;
}

void Player::bury(int place){
  Personality* temp;
  temp = army[place];
  army[place] = army[numOfArmy-1];
  army[numOfArmy-1] = temp;
  army.pop_back();
  numOfArmy--;
}
void Player::provinceDestroy(int i){
  BlackCard * temp;
  temp = provinces[i];
  provinces[i] = provinces[numberOfProvinces-1];
  provinces[numberOfProvinces-1] = temp;
  provinces.pop_back();
  numberOfProvinces--;
}

void Player::printHand(){
  std::cout << name<< " YOUR HAND" << '\n';

  for(int i = 0;i<numOfHand;i++){
    std::cout<<"Card number: "<<i <<": \n";
    hand[i]->print();
  }
}
void Player::printProvinces(){
  std::cout << name<< " YOUR PROVINCES" << '\n';

  for(int i = 0;i<numberOfProvinces;i++){//mexri?
    std::cout<<"Province number: "<<i <<": \n";
    provinces[i]->print();
  }
}
void Player::printArmy(){
  std::cout << name<< " YOUR ARMY" << '\n';
  for(int i = 0;i<numOfArmy;i++){
    std::cout<<"Personality number: "<<i <<": \n";
    army[i]->print();
  }
}
void Player::printHoldings(){
  std::cout << name<< " YOUR HOLDINGS" << '\n';

  for(int i = 0;i<numOfHoldings;i++){
    std::cout<<" Holding number: "<<i <<": \n";
    holdings[i]->print();
  }
}
