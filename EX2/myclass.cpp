#include "myclass.h"

#include "tree.h"
int idCounter=0;

////DATE////

void Date::setDate(int d=1,int m=1 , int y=2000){

	day = d;
	month = m;
	year = y;
}

///////////////////
//POST/////////////
//////////////
Post::Post(){
		int rd,rm,ry;
	id= idCounter++;
	title =nameMaker();
	creator=CreatorNamer();
	text=nameMaker();
	rd= rand()%30+1;
	rm= rand()%12 +1;
	ry=rand()%21+2000;
	PdateOfcreation.setDate(rd,rm,ry);
}

void Post::Printer(){

std::cout << "=================================" << '\n';
		std::cout << " Post \n id of post \t" << id<<std::endl;
		std::cout << "title of post \t" << title<<std::endl;
		std::cout << "creator of post \t" << creator<<std::endl;
		std::cout << "text of post \t" << text<<std::endl;
		std::cout << "date of creation of Post \t" << PdateOfcreation.day <<"\t"<<PdateOfcreation.month <<"\t"<<PdateOfcreation.year <<std::endl;
std::cout << "=================================" << "\n \n";
}

Post::~Post(){
	std::cout<<"Post number:  "<<id<<"  is about to be destroyed"<<std::endl;

}

std::string Post::getcreator() const{
		return creator;
}







/////////////////////////////////////////////////////////
/// Thread///////////////
/////////////////
Thread::Thread(){
		int i,rd,rm,ry;
		subject=nameMaker();
		creator=CreatorNamer();
		rd= rand()%30+1;
		rm= rand()%12 +1;
		ry=rand()%21+2000;
		TdateOfcreation.setDate(rd,rm,ry);
				std::cout <<"Thread with subject:   "<<subject<<"  has just been created !\n";
		for(i=0;i<Psize;i++) threadsPost[i];
}


Thread :: ~Thread(){

	int i;

	std::cout<<"Thread with subject  "<<subject<<"  is about to be destroyed"<<std::endl;


}


void Thread::Printer(){
	int i;

	std::cout<< "\n thread  "<< std::endl;
	std::cout<<"subject \t"<<subject<<std::endl;
	std::cout<<"creator \t"<<creator<<std::endl;
	std::cout<<"num of posts \t"<<Psize<<std::endl;
	std::cout << "date of creation of Thread \t" << TdateOfcreation.day <<"\t"<<TdateOfcreation.month <<"\t"<<TdateOfcreation.year <<std::endl;
		for(i=0; i<Psize; i++){

			threadsPost[i].Printer();
		}
}
void Thread::TitlePrinter(){

			std::cout<<"subject \t"<<subject<<std::endl;

}

Post* Thread::getThreadsPostPtr(int pos) {

			return &threadsPost[pos];



}



//////////////////////
///FOROUM/////////
////////////////
Foroum::Foroum( std::string tit){

				int i;
				std::cout <<"Foroum with title:   "<<tit<<"  has just been created \n";
					title= tit;
					for(i=0; i<Tsize; i++)	foroumsThread[i];
}

Foroum::~Foroum(){

		std::cout <<"Foroum with title:   "<<title<<"  is about to be destroyed \n";

}


void Foroum::Printer(){
	int i;
	std::cout<<"num of threads \t"<<Tsize<<std::endl;
	std::cout<<"title \t"<<title<<std::endl;
		for(i=0; i<Tsize; i++){

			foroumsThread[i].Printer();
	}
}

void Foroum::PrintSorted(){
		int i;
		Tree** temp= new Tree*[Tsize];     // array of temp tree* that will be merged into one
		temp[0]=temp[0]->Tree_create(foroumsThread[0]);
		for(i=1; i<Tsize; i++){
				temp[i]=temp[i]->Tree_create(foroumsThread[i]);

				temp[i]->Tree_marriage(temp[0]);

		}
		temp[0]->tree_print();

		for(i=0; i<Tsize; i++){


				temp[i]->Tree_destroy(temp[i]);

		}
		delete[] temp;



	}
