#include "tree.h"


Tree* Tree::Tree_create( Thread& MYThread){
      int i;
      Tree* Root=NULL;

      for(i=0; i<Psize; i++){
          tree_imput(MYThread.getThreadsPostPtr(i),Root);
      }
        return Root;
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

    Left_kid=NULL;
    Right_kid=NULL;
    if (ListOfPosts->ListGetSize()!=0) delete ListOfPosts;

 }


void Tree::Tree_destroy(Tree*& Root){

  if(Root!=NULL ){

      if(Root->Left_kid!=NULL){
        Tree_destroy(Root->Left_kid);
      }
      if (Root->Right_kid!=NULL){
        Tree_destroy(Root->Right_kid);
      }

      delete Root;
      Root=NULL;

    }


}
