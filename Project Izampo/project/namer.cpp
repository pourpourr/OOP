#include <cstdlib>
#include <string>
#include "namer.h"
//char Rsymbols[] = { 'a','b','c','d','e','f','g','h','i','j','0','1','2','3','4','5','6','7','8','9' };
std::string Creators[]={"george","john","stahtis","laertis","jason","eua","mariella"};
std::string Rsymbols[] = { "a","b","c","d","e","f","g","h","i","j","0","1","2","3","4","5","6","7","8","9" };

static int i=0;

std::string nameMaker() {

	int length = rand() % 10 + 1;
	int i;
	std::string name = "";
	for(i = 0; i< length; i++)
	{
		name += Rsymbols[rand() % 20];
	}
/*	name.resize(length+1);
	for (i = 0; i < length; i++) {
		name[i] = Rsymbols[rand() % 20];

	}
	name[i] = '\0';
	*/
	return name;
}

std::string CreatorNamer(){
	return Creators[i++];
}
