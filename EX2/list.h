#ifndef __LIST__
#define __LIST__

#include <iostream>
#include "myclass.h"



class Listnode{
    public:
        Listnode(Post* MYPostPtr);
        Listnode* getNext() ;
        void setNext( Listnode* listNext) ;
        Post* getListsPostPtr() ;
    private:
        Post* PostPtr;
        Listnode* next;



};



class List{
    public:
        List ( Post* MYPostPtr);
        void ListAdd( Post* MYPostPtr);
        void ListPrint();
        void ListUnity(List*& MYList);
       ~List();
       int ListGetSize();

    private:
        Listnode* first;
        int size;

};


#endif
