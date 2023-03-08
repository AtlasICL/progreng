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
    std::cout << l->val << " ";
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

listNode* ordered_insertion_list(list_t e, listNode* l){
    if (l == NULL){
        return cons_list(e, l);
    }
    else if (e < l->val){
        return cons_list(e, l);
    }
    else{
        l->next=ordered_insertion_list(e, l->next);
        return l;
    }
}

int main(){

  listNode* l = NULL;

  l = cons_list(12, l);
  l = cons_list(10, l);
  l = cons_list(9, l);
  l = cons_list(8, l);
  l = cons_list(8, l);
  l = cons_list(6, l);
  l = cons_list(4, l);
  l = cons_list(2, l);  

  std::cout << "initial list: ";
  print_list_rec(l);
  std::cout << std::endl;

  ordered_insertion_list(3, l);
  std::cout << "inserting 3 --> ";
  print_list_rec(l);
  std::cout << std::endl;

  ordered_insertion_list(8, l);
  std::cout << "inserting 8 --> ";
  print_list_rec(l);
  std::cout << std::endl;

  ordered_insertion_list(1, l);
  std::cout << "inserting 1 --> ";
  print_list_rec(l);
  std::cout << std::endl;
  
  ordered_insertion_list(7, l);
  std::cout << "inserting 7 --> ";
  print_list_rec(l);
  std::cout << std::endl;
  
  ordered_insertion_list(15, l);
  std::cout << "inserting 15--> ";
  print_list_rec(l);
  std::cout << std::endl;
  
  ordered_insertion_list(0, l);
  std::cout << "inserting 0 --> ";
  print_list_rec(l);
  std::cout << std::endl;
  
  ordered_insertion_list(0, l);
  std::cout << "inserting 0 --> ";
  print_list_rec(l);
  std::cout << std::endl;
  
  ordered_insertion_list(1, l);
  std::cout << "inserting 1 --> ";
  print_list_rec(l);
  std::cout << std::endl;
}