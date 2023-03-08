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