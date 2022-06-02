#include <iostream>
#include "myclass.h"
#include <cstdlib>
#include <ctime>



int main() {
	srand(time(NULL));

	Foroum Myforoum("Antikeimenostrafhs Programmatismos");
	Myforoum.Printer();

std::cout << "++++++++++++++++ \n PRINT SORTED\n++++++++++++++++" << '\n';
	Myforoum.PrintSorted();
	std ::cout <<"ola good"<<std::endl;
	return 0;
}
