bool search_ordered_list(list_t e, listNode* l){
    listNode* tmp = l;
    while (tmp->next != NULL && e >= tmp->val){
        if (tmp->val == e){
            return true;
        }
        else {
            tmp = tmp->next;
        }
    }
    return false;
}