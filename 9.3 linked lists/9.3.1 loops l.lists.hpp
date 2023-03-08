#include <iostream>
#include <vector>

void printVectorInt(const std::vector<int> vin){
  std::cout << "[ ";
  for (int i = 0; i < vin.size(); i++)
    std::cout << vin[i] << " ";
  std::cout << "]" << std::endl;
}

struct listNode{
  int val;
  listNode* nextNode;
};



int main(){

  int n;

  std::vector<int> input;

  std::cout << "How many elements? --> " << std::endl;
  std::cin >> n;

  std::cout << n << " elements to input: " << std::endl;

  int in;
  for (int i = 0; i < n; i++){
    std::cin >> in;
    input.push_back(in);
  }

  printVectorInt(input);

  listNode* l = NULL;

  listNode* tmp;

  for (int i = 0; i < n; i++){
    tmp = new listNode;    
    tmp->val = input[i];
    tmp->nextNode = l;
    l = tmp;
    
  }

  listNode* lit;
  lit = l;
  // lit (l iteration) starts at the beginning of the list, which is the pointer "list"
  std::cout << "(";
  while (lit != NULL){
    std::cout << lit->val << ",";
    lit = lit->nextNode;
  }
  std::cout << ")" << std::endl;

  

  // to deallocate:
  lit = l;
  while (lit != NULL){
    tmp = lit->nextNode;
    delete lit;
    lit = tmp;
  }
  
  
}