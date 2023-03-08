typedef int tree_t;

struct TreeNode{
  tree_t val;
  TreeNode* left;
  TreeNode* right;
};

int countLeavesTree(TreeNode* t){

  if (t == nullptr){
    return 0;
  }

  else if (t->left == nullptr && t->right == nullptr){
    return 1;
  }

  else {
    return countLeavesTree(t->left) + countLeavesTree(t->right);
  }
  
}