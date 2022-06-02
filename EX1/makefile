CPP = g++
OBJ = FirstEx.o myclass.o namer.o 

myforoum1: $(OBJ)
	$(CPP) -o myforoum1 $(OBJ)

myclass.o: myclass.cpp
	$(CPP) -c myclass.cpp 

namer.o: namer.cpp
	$(CPP) -c namer.cpp 

FirstEx.o: FirstEx.cpp
	$(CPP) -c FirstEx.cpp 


clean:
	rm -f $(OBJ) myforoum1
