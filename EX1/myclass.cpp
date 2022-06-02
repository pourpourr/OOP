#include "myclass.h"
int idCounter=0; // global counter for the post id

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
	Printer();
}

int Post::getId() const{

		return id;

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


/////////////////////////////////////////////////////////
/// Thread///////////////
/////////////////
Thread::Thread(std::string sub){
		int i,rd,rm,ry;
		if(sub!="0"){
			subject=sub;
		}else {
			subject= nameMaker();
		}
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

			std::cout<<"Thread's subject \t"<<subject<<std::endl;

}
void Thread::CheckAndPrint(std::string sub){
			if(subject.compare(sub)==0){
				 this->Printer();
			}

}


void Thread::ThreadPostFinder(int x){
			int i;
			for(i=0; i<Psize; i++){
					if(x==threadsPost[i].getId()){
						threadsPost[i].Printer();
					}
			}
}


//////////////////////
///FOROUM/////////
////////////////
Foroum::Foroum( std::string tit){

				int i;
				std::cout <<"Foroum with title:   "<<tit<<"  has just been created \n";
					title= tit;


}

Foroum::~Foroum(){

		std::cout <<"Foroum with title:   "<<title<<"  is about to be destroyed \n";

}
void Foroum::ThreadFinder(std::string sub){
		int i;
		for(i=0;i<Tsize;i++){
			foroumsThread[i].CheckAndPrint(sub);
		}

}

void Foroum::ForoumPostFinder(int x){
			int i;
			for(i=0; i<Tsize; i++){
				foroumsThread[i].ThreadPostFinder(x);
			}

}

void Foroum::Printer(){
	int i;
	std::cout<<"num of threads \t"<<Tsize<<std::endl;
	std::cout<<"title \t"<<title<<std::endl;
		for(i=0; i<Tsize; i++){

			foroumsThread[i].TitlePrinter();
	}
}
