#include <iostream>
#include "namer.h"
#include "myclass.h"
#include <cstdlib>
#include <ctime>

void printOptions(){
		std::cout << "1. Print foroum's Thread titles" << '\n';
		std::cout << "2. Give subject of thread and print it" << '\n';
		std::cout << "3. Give id of a post and print it" << '\n';
		std::cout<<"4. Exit..."<<std:: endl;
}

int main() {
	srand(time(NULL));
int opt,i,randNum;
std::string sub;
	Foroum Myforoum("Antikeimenostrafhs Programmatismos");
	std::cout << "\n Printing Foroum..." << '\n';
	Myforoum.Printer();
	std::cout << "\n Printing Thread kanones kai xrhsimes plhrofories" << "\n \n";
	Myforoum.ThreadFinder("kanones kai xrhsimes plhrofories");
	std::cout << "============================" << '\n';
	std::cout << "\n Printing some Random posts" << '\n';
	for(i=0; i<5; i++){
			randNum= rand()%(Psize*Tsize);
			Myforoum.ForoumPostFinder(randNum);

	}


	printOptions();
  std:: cin >>opt;
		while(opt!=4 ){
			switch (opt){

					case 1:
							Myforoum.Printer();
							break;
					case 2:
							std::cout << "give subject \n";
							std::cin.ignore(40000,'\n');    // \n is left in stream
							std::getline( std::cin , sub );
							Myforoum.ThreadFinder(sub);
							break ;
					case 3:
							std::cout << "give post's id" << '\n';
							std::cin >> randNum;
							Myforoum.ForoumPostFinder(randNum);
							break ;
			}
			printOptions();
		  std:: cin >>opt;
		}

	return 0;
}
