bool search_list(const list_t e, listNode* l){
    listNode* tmp = l;

    while (tmp != NULL){
        if (tmp->val == e){
            return true;
        }
        else {
            tmp = tmp->next;
        }
    }

    return false;
}