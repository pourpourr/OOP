#ifndef __CLASS__
#define __CLASS__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "namer.h"


const int Psize= 5;
const int Tsize=3;
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
    int getId() const;
	private:
		int id;
		std::string title, creator, text;
		Date PdateOfcreation;

};




class Thread
{
	public:
		Thread(std::string sub="0");
		void TitlePrinter();
		~Thread();
		void CheckAndPrint(std::string sub);
		void Printer();
    void ThreadPostFinder(int x);
	private:
		std::string subject, creator;
		Date TdateOfcreation;
		Post threadsPost[Psize];
};

class Foroum
{
	public:
		void ThreadFinder(std::string sub);
    void ForoumPostFinder(int x);
		Foroum( std::string tit);
		~Foroum();
		void Printer();


	private:
		std::string title;
		Thread foroumsThread[Tsize]={Thread("kanones kai xrhsimes plhrofories")};
};





#endif
