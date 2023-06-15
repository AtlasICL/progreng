#include <iostream>

typedef int stack_t;

struct StackLayer{
    stack_t val;
    StackLayer* next;
};

class Stack{

public:

    // TODO: implement methods:
    // pop
    // push
    // top

    stack_t top(){
        return top_layer->val;
    }

    int size() const{
        return size_s;
    }

private:

    StackLayer* top_layer;
    int size_s;

};

// void test_stack(const Stack& s){
//     s.top();
//     s.size();
// }

int main(){
}