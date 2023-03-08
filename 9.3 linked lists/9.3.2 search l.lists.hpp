#include <iostream>

struct intListNode{
  int val;
  intListNode* nextNode;
};

int main(){

  std::cout << "enter number to find : " << std::endl;
  int n;
  std::cin >> n;
  bool found = false;

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

  intListNode* lit;
  lit = list;
  std::cout << "(";
  while (lit != NULL){
    std::cout << lit->val << ",";
    lit = lit->nextNode;
  }
  std::cout << ")" << std::endl;

  intListNode* searcher;
  searcher = list;
  while (searcher != NULL){
    if (searcher->val == n){
      found = true;
    }
    searcher = searcher->nextNode;
  }
  

  // to deallocate:
  lit = list;
  while (lit != NULL){
    tmp = lit->nextNode;
    delete lit;
    lit = tmp;
  }

  std::cout << found << std::endl;
  
}