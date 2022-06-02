#include "tree2.h"

 Tree::Tree( Thread& MYThread){
      int i;


      for(i=0; i<Psize; i++){
          Headtree_imput(MYThread.getThreadsPostPtr(i));
      }

}

void Tree::tree_imput(Post* MYPostPtr ,Tree*& Root ){

      if(Root==NULL){
          Root= new Tree;
          Root->creator= MYPostPtr->getcreator();
          Root->Left_kid=NULL;
          Root->Right_kid=NULL;
          Root->ListOfPosts= new List(MYPostPtr);
          Root->counter=1;
      }
      else if(MYPostPtr->getcreator()<Root->creator){
        tree_imput(MYPostPtr,Root->Left_kid);
      }else if (MYPostPtr->getcreator()>Root->creator){
        tree_imput(MYPostPtr,Root->Right_kid);
      }else {
          Root->ListOfPosts->ListAdd(MYPostPtr);
          Root->counter++;

      }


}

void Tree::tree_print(){
      if (this->Left_kid!=NULL){
        this->Left_kid->tree_print();
      }
      std::cout <<"\n  \t twra ayta einai ta post tou \t"<< this->creator<< "\n";
      this->ListOfPosts->ListPrint();
      if(this->Right_kid!=NULL){
        this->Right_kid->tree_print();
      }
}


void Tree:: Tree_marriage(Tree*& Root){

      if (this->Left_kid!=NULL){
        this->Left_kid->Tree_marriage(Root);

      }
      TreeNodeToTree(Root);

      if (this->Right_kid!=NULL) {
        this->Right_kid->Tree_marriage(Root);
      }

}




void Tree::TreeNodeToTree(Tree*& Root){

      if(Root==NULL){
          Root =  new Tree;
          Root ->creator= this->creator;
          Root->Left_kid=NULL;
          Root->Right_kid=NULL;
          Root->ListOfPosts= this -> ListOfPosts;
          Root->counter=1;
      }
      else if (this->creator > Root->creator){
          TreeNodeToTree( Root->Right_kid );

      }else if (this-> creator < Root-> creator ){
          TreeNodeToTree(Root->Left_kid);
      } else{

          Root->ListOfPosts->ListUnity(this->ListOfPosts);
          Root->counter=Root->counter +this->counter;

      }
}

Tree::~Tree(){

    if(ListOfPosts=NU)
    std::cout << "ee" << '\n';
    if(this->Left_kid!=NULL) delete this->Left_kid;
    if(this->Right_kid!=NULL) delete this->Right_kid;
       delete this;

 }

/*
void Tree::Tree_destroy(Tree*& Root){

  if(Root!=NULL){
 std::cout << "paei to dentro destroyed" << '\n';
      Root->Left_kid->Tree_destroy(Root->Left_kid);
      Root->Right_kid->Tree_destroy(Root->Right_kid);
      delete Root;
      Root=NULL;

    }


}*/
