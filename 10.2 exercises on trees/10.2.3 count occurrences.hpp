typedef int tree_t;

struct TreeNode{
  tree_t val;
  TreeNode* left;
  TreeNode* right;
};

int countOccurrences(tree_t e, TreeNode* t){
  if (t == nullptr){
    return 0;
  }

  else if (t->val == e){
    return 1 + countOccurrences(e, t->left) + countOccurrences(e, t->right);
  }

  else {
    return countOccurrences(e, t->left) + countOccurrences(e, t->right);
  }
}