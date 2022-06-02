#include <cstdlib>
#include <string>
#include "namer.h"
std::string Creators[]={"george","john","stahtis","laertis","jason"};
std::string Rsymbols[] = { "a","b","c","d","e","f","g","h","i","j","0","1","2","3","4","5","6","7","8","9" };


std::string nameMaker() {

	int length = rand() % 10 + 1;
	int i;
	std::string name = "";
	for(i = 0; i< length; i++)
	{
		name += Rsymbols[rand() % 20];
	}

	return name;
}

std::string CreatorNamer(){
	return Creators[rand()%5];
}
