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

int length_list_rec(listNode* l){
  if (l == NULL){
    return 0;
  }
  else {
    return 1 + length_list_rec(l->next);
  }
}

listNode* ordered_copy_list(listNode* l){

  listNode* lout = NULL;
  listNode* tmp = l;

  for (int i=0; i<length_list_rec(l); i++){
    lout = ordered_insertion_list(tmp->val, lout);
    tmp = tmp->next;
  }

  return lout;
  
}

int main(){

  listNode* l = NULL;

  l = cons_list(2, l);
  l = cons_list(7, l);
  l = cons_list(9, l);
  l = cons_list(8, l);
  l = cons_list(4, l);
  l = cons_list(6, l);
  l = cons_list(9, l);
  l = cons_list(11, l);  

  std::cout << "initial list: ";
  print_list_rec(l);
  std::cout << std::endl;

  listNode* reverseList = ordered_copy_list(l);

  print_list_rec(reverseList);

  return 0;
}