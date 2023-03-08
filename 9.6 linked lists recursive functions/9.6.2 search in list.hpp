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

bool search_list_rec(list_t e, listNode* l){
  
  if (l == NULL){
    return false;
  }

  else {
    
    if (l->val == e){
      return true;
    }

    return search_list_rec(e, l->next);
    
  }
  
}

int main(){

  listNode* l;
  
  l = NULL;

  l = cons_list(2, l);
  l = cons_list(4, l);
  l = cons_list(6, l);
  l = cons_list(8, l);
  l = cons_list(9, l);
  l = cons_list(10, l);
  l = cons_list(12, l);

  print_list_rec(l);
  
  bool search = search_list_rec(1, l);
  std::cout << "--> " << search;
  
}