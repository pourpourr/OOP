CPP = g++
OBJ = SecondEx.o myclass.o namer.o tree.o list.o

myforoum2: $(OBJ)
	$(CPP) -o myforoum2 $(OBJ)

myclass.o: myclass.cpp
	$(CPP) -c myclass.cpp myclass.h

namer.o: namer.cpp
	$(CPP) -c namer.cpp namer.h

tree.o: tree.cpp
	$(CPP) -c tree.cpp tree.h

list.o: list.cpp
	$(CPP) -c list.cpp list.h

SecondEx.o: SecondEx.cpp
	$(CPP) -c SecondEx.cpp


clean:
	rm -f $(OBJ) myforoum2
