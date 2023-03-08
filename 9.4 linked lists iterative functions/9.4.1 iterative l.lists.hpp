#include <iostream>
#include <vector>

typedef int list_t;

struct listNode{
    list_t val;
    listNode* next;
};

listNode* cons_list(list_t e, listNode* l){
    listNode* tmp; 
    tmp = new listNode;

    tmp->val = e;
    tmp->next = l;

    return tmp;
}

void print_list(listNode* l){
    std::cout << "( ";
    while(l != NULL){
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout << ")";
}
 
void deallocate_list(listNode* l){
    listNode* tmp;
 
    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

void printVectorInt(const std::vector<int> vin){
  std::cout << "[ ";
  for (int i = 0; i < vin.size(); i++)
    std::cout << vin[i] << " ";
  std::cout << "]" << std::endl;
}

int main(){

    int n;
    std::vector<int> input;
    std::cout << "How many elements? --> " << std::endl;
    std::cin >> n;
    std::cout << n << " elements to input: " << std::endl;
    int in;
    for (int i = 0; i < n; i++){
        std::cin >> in;
        input.push_back(in);
    }

    printVectorInt(input);


    listNode* l = NULL;

    int counter = 0;

    while (counter < input.size()){
        l = cons_list(input[counter], l);
        counter ++;
    }

    print_list(l);

}