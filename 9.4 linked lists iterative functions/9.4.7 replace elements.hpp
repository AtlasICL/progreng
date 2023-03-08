bool replace_first_occurrence(list_t e, list_t n, listNode* l){
    while (l->next != NULL && l->val != e){
        l = l->next;
    }
    if (l->val == e){
        l->val = n;
        return true;
    }
    return false;
}

bool replace_all_occurrences(list_t e, list_t n, listNode* l){
    bool replaced = false;
    while (l->next != NULL){
        if (l->val == e){
            l->val = n;
            replaced = true;
        }
        l = l->next;
    }
    return replaced;
}

bool replace_list(list_t e, list_t n, listNode* l, bool all){
    bool out;
    if (all){
        out = replace_all_occurrences(e, n, l);
    }
    else{
        out = replace_first_occurrence(e, n, l);
    }
    return out;
}