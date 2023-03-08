#include<iostream>

struct Node{
  int val;
  Node* next;
};

int main(){

  Node* l;
  l = NULL;

  Node* tmp;
  tmp = new Node;
  (*tmp).val = 3;
  (*tmp).next = l;

  l = tmp;

  // we have now created a linked list with one node.
  // the address for the first (and, so far, only) node is contained in l.
  // this first node, at address l, contains the int value 3, and has a .next ptr value of NULL
  // this means that this node is the last node in the linked list.

  // we can now add a new node that comes before this one.

  tmp = new Node;
  (*tmp).val = 3;
  (*tmp).next = l;
  // the node we're creating now will point to l, which is the node we created before
  l = tmp;   
  // we make l the address for the first node of the list again

  //delete tmp;

  // now to print the linked list
  // we need an iterator, which we will call lit

  Node* lit;
  tmp = new Node;


  tmp = new Node;

  std::cout << tmp << std::endl;
  
  while (lit != NULL){
    std::cout << (*lit).val << ".";
    lit = (*lit).next;
  }

  
  
}  