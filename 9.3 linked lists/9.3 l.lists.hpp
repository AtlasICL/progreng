#include <iostream>

struct intListNode{
  int val;
  intListNode* nextNode;
};

int main(){

  // 1
  intListNode* list;
  list = NULL;

  // 2
  intListNode* tmp;
  tmp = new intListNode;

  // 3
  tmp->val = 2;
  tmp->nextNode = list;

  // 4
  list = tmp;

  // B:
  tmp = new intListNode;

  tmp->val = 3;
  tmp->nextNode = list;

  list = tmp;

  // to print:

  intListNode* lit;
  lit = list;
  // lit (l iteration) starts at the beginning of the list, which is the pointer "list"
  while (lit != NULL){
    std::cout << lit->val << std::endl;
    lit = lit->nextNode;
  }

  // to deallocate:
  lit = list;
  while (lit != NULL){
    tmp = lit->nextNode;
    delete lit;
    lit = tmp;
  }
  
}