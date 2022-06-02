#ifndef __CLASS__
#define __CLASS__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "namer.h"


const int Psize= 4;
const int Tsize=5;
 struct Date{
	int day,month,year;
	void setDate(int d,int m, int y);
};



class Post
{
	public:
		Post();
		~Post();
		void Printer();
		std::string getcreator() const;
	private:
		int id;
		std::string title, creator, text;
		Date PdateOfcreation;

};




class Thread
{
	public:
		Thread();
		void TitlePrinter();
		~Thread();
		void Printer();
		Post* getThreadsPostPtr(int pos) ;
	private:
		std::string subject, creator;
		Date TdateOfcreation;
		Post threadsPost[Psize];
};

class Foroum
{
	public:
		Foroum( std::string tit);
		~Foroum();
		void Printer();
   void PrintSorted();


	private:
		std::string title;
		Thread foroumsThread[Tsize];
};





#endif
