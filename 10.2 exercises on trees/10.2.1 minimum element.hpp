#include <iostream>
 
typedef int tree_t;
 
struct TreeNode{
  tree_t val;
  TreeNode* left;
  TreeNode* right;
};
 
TreeNode* cons_tree(tree_t e, TreeNode* l, TreeNode* r){
  TreeNode* tmp;
  tmp = new TreeNode;
  tmp->val = e;
  tmp->left = l;
  tmp->right = r;
  return tmp;
}
 
TreeNode* ordered_insertion_tree(tree_t e, TreeNode* t){
  if(t == NULL){
    return cons_tree(e, NULL, NULL);
  }
  
  else if(e < t->val){
    t->left = ordered_insertion_tree(e, t->left);
    return t;
  }
    
  else{
    t->right = ordered_insertion_tree(e, t->right);
    return t;
  }
}
 
void print_tree(TreeNode* t){
  if(t != NULL){
    print_tree(t->left);
    std::cout << t->val << std::endl;
    print_tree(t->right);
  }
}
 
void deallocate_tree(TreeNode* t){
  if(t != NULL){
    deallocate_tree(t->left);
    deallocate_tree(t->right);
    delete t;
  }
}

bool searchTree(tree_t e, TreeNode* t){
  
  if (t == NULL){
    return false;
  }

  else if (t->val == e){
    return true;
  }  

  else {
    
    if (e < t->val){
      return searchTree(e, t->left);
    }

    if (e > t->val){
      return searchTree(e, t->right);
    }
  }
}

 TreeNode* min_element_tree(TreeNode* t){

  if (t == NULL){
    std::cout << "tree is empty \n";
    return NULL;
  }

  while (t->left != NULL){
    t = t->left;
  }

  std::cout << "min node: " << t->val << std::endl;
  return t;   
   
 }

int countLeavesTree(TreeNode* t){

  if (t == NULL){
    return 0;
  }

  else if (t->left == NULL && t->right == NULL){
    return 1;
  }

  else {
    return countLeavesTree(t->left) + countLeavesTree(t->right);
  }
  
}

int countOccurrences(tree_t e, TreeNode* t){
  if (t == NULL){
    return 0;
  }

  else if (t->val == e){
    return 1 + countOccurrences(e, t->left) + countOccurrences(e, t->right);
  }

  else {
    return countOccurrences(e, t->left) + countOccurrences(e, t->right);
  }
}

int replace_tree(tree_t e, tree_t r, TreeNode* t, int n){
  
  int out = 0;
  
  if (t == NULL){
    return 0;
  }

  if (t->val == e && n > 0){
    t->val = r;
    n--;
    out += 1 + replace_tree(e, r, t->left, n) + replace_tree(e, r, t->right, n);
  }

  else {
    out += replace_tree(e, r, t->left, n) + replace_tree(e, r, t->right, n);
  }

  return out;
  
}
 
int main(){
  TreeNode* t;
  t = NULL;
 
  t = ordered_insertion_tree(15, t);
  t = ordered_insertion_tree(20, t);
  t = ordered_insertion_tree(6, t);
  t = ordered_insertion_tree(1, t);
  t = ordered_insertion_tree(4, t);
  t = ordered_insertion_tree(4, t);
  t = ordered_insertion_tree(4, t);
  t = ordered_insertion_tree(18, t);
  t = ordered_insertion_tree(9, t);
  
  std::cout << "initial tree: \n";
  print_tree(t);
  std::cout << std::endl;

  int testReplace = replace_tree(4, 787, t, 5);
  std::cout << "New tree, 4 --> 787: \n";
  print_tree(t);
  std::cout << "No replaced: " << testReplace;
  
  deallocate_tree(t);
 
}