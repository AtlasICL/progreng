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

bool search_ordered_rec(list_t e, listNode* l){

  if (l == NULL){
    return false;
  }

  if (l->val == e){
    return true;
  }

  if (l->val > e){
    return false;
  }

  else{
    return search_ordered_rec(e, l->next);
  }
  
}

int main(){
  
  listNode* l;
  
  l = NULL;

  l = cons_list(12, l);
  l = cons_list(10, l);
  l = cons_list(9, l);
  l = cons_list(5, l);
  l = cons_list(8, l);
  l = cons_list(6, l);
  l = cons_list(4, l);
  l = cons_list(2, l);  

  print_list_rec(l);

  bool search = search_ordered_rec(7, l);
  std::cout << "7, should be 0 -->" << search << std::endl;

  search = search_ordered_rec(8, l);
  std::cout << "8, should be 1 -->" << search << std::endl;

  search = search_ordered_rec(12, l);
  std::cout << "12, should be 1 -->" << search << std::endl;

  search = search_ordered_rec(4, l);
  std::cout << "4, should be 1 -->" << search << std::endl;

  search = search_ordered_rec(1, l);
  std::cout << "1, should be 0 -->" << search << std::endl;

  search = search_ordered_rec(0, l);
  std::cout << "0, should be 0 -->" << search << std::endl;

  search = search_ordered_rec(5, l);
  std::cout << "5, should be 0 -->" << search << std::endl;
}