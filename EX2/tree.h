#ifndef __TREE__
#define __TREE__

#include <iostream>
#include <string>
#include "myclass.h"
#include "list.h"

class Tree{
    public:
      Tree* Tree_create( Thread& MYThread);
      void Tree_marriage(Tree*& Root);
      void TreeNodeToTree(Tree*& Root);
      void tree_imput( Post* MYPost ,Tree*& Root );
      void tree_print();
      void Tree_destroy(Tree*& Root);
      ~Tree();
    private:
      std::string creator;
      Tree* Left_kid;
      Tree* Right_kid;
      List* ListOfPosts;
      int counter;
};


#endif
