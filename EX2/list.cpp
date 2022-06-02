#include "list.h"



List::List( Post* MYPostPtr){
    first=new Listnode(MYPostPtr);
    size=1;

}

List::~List(){
    Listnode* temp;
    Listnode* curr;
    curr=first;
    temp=curr;
    while(curr!=NULL){
      curr=curr->getNext();
      delete temp;
      temp=curr;
    }
    size=0;


}

int List::ListGetSize(){
    return size;

}

void List::ListAdd( Post* MYPostPtr){
    Listnode* newNode = new Listnode(MYPostPtr);
    Listnode* temp;
    temp= first;
    while(temp->getNext()!=NULL){
      temp=temp->getNext();
    }
    temp->setNext(newNode);
    size++;
}

void List::ListPrint(){
  Listnode* temp2= first;
  while(temp2->getNext()!=NULL){
  temp2->getListsPostPtr()->Printer();
    temp2=temp2->getNext();
  }
     temp2->getListsPostPtr()->Printer();
  std::cout<<"num of post by creator ="<<size<<std::endl;
}



Listnode::Listnode( Post* MYPostPtr){
  PostPtr=MYPostPtr;
  next=NULL;

}



Listnode* Listnode::getNext() {
    return this->next;

}

Post* Listnode:: getListsPostPtr() {
    return this->PostPtr;

}

void Listnode::setNext( Listnode* listNext) {

    this->next= listNext;
}




void List ::ListUnity(List*& MYList){
  Listnode* temp;
  temp= first;
  while(temp->getNext()!=NULL){
    temp=temp->getNext();
  }
  temp->setNext(MYList->first);
  size= size + MYList->size;



}
