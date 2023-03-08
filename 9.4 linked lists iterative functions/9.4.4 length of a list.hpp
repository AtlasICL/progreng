int length_list(listNode* l){
    int len = 1;
    while (l->next != NULL){
        l = l->next;
        len++; 
    }
    return len;
}