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