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
 
int main(){
    TreeNode* t;
    t = NULL;
 
    t = ordered_insertion_tree(15, t);
    t = ordered_insertion_tree(20, t);
    t = ordered_insertion_tree(1, t);
    t = ordered_insertion_tree(6, t);
    t = ordered_insertion_tree(18, t);
    t = ordered_insertion_tree(4, t);
    t = ordered_insertion_tree(9, t);
 
    print_tree(t);


    bool test1, test2;

    test1 = searchTree(0, t);
    test2 = searchTree(1, t);

    std::cout << "test 1 :" << test1 << std::endl;
    std::cout << "test 2 :" << test2 << std::endl;
  
    deallocate_tree(t);
 
}