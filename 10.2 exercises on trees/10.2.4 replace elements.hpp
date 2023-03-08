#include <iostream>

int replace_tree(tree_t e, tree_t r, TreeNode* t, int n){

  if (t == NULL){
    return 0;
  }

  if (t->val == e){
    t->val = r;
    n--;
    out += 1 + replace_tree(e, r, t->left, n) + replace_tree(e, r, t->left, n);
  }

  return out;
  
}

