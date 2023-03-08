#include <iostream>

typedef int tree_t;

struct TreeNode{
  tree_t val;
  TreeNode* left;
  TreeNode* right;
};

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
