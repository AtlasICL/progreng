#include <iostream>

typedef int list_t;

struct listNode{
  list_t val;
  listNode* next;
};

listNode* cons_list(list_t e, listNode* l){
  listNode* tmp;
  tmp = new listNode;

  tmp->val = e;
  tmp->next = l;
  return tmp;
}

void print_list_rec(listNode* l){
  if (l != NULL){
    std::cout << l->val << " " << std::endl;
    print_list_rec(l->next);
  }
}

void deallocate_list_rec(listNode* l){
  listNode* tmp;

  if (l != NULL){
    tmp = l->next;
    delete l;
    deallocate_list_rec(tmp);
  }
}

int length_list_rec(listNode* l){
  if (l == NULL){
    return 0;
  }
  else {
    return 1 + length_list_rec(l->next);
  }
}

int main(){

  listNode* l = NULL;

  for (int i=0; i<17; i++){
    l = cons_list(i, l);
  }

  print_list_rec(l);

  int count = length_list_rec(l);

  std::cout << count;

  deallocate_list_rec(l);
  
}