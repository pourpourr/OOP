CPP = g++
OBJ = Card.o DeckBuilder.o Holding.o Item.o main.o Personality.o Player.o  Follower.o GameBoard.o namer.o

myL5R: $(OBJ)
	$(CPP) -o myL5R $(OBJ)

Card.o: Card.cpp
	$(CPP) -c Card.cpp

Follower.o: Follower.cpp
	$(CPP) -c Follower.cpp


Holding.o: Holding.cpp
	$(CPP) -c Holding.cpp

Item.o: Item.cpp
	$(CPP) -c Item.cpp


Personality.o: Personality.cpp
	$(CPP) -c Personality.cpp

DeckBuilder.o: DeckBuilder.cpp
	$(CPP) -c DeckBuilder.cpp


Player.o: Player.cpp
	$(CPP) -c Player.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

namer.o: namer.cpp
	$(CPP) -c namer.cpp

GameBoard.o: GameBoard.cpp
	$(CPP) -c GameBoard.cpp

clean:
	rm -f $(OBJ) myL5R
