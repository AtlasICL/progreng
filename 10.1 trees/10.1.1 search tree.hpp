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