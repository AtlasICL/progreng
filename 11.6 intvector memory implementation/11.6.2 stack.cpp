#include <iostream>

typedef int stack_type;

struct StackLayer
{
    stack_type val;
    StackLayer* nextLayer;
};

class Stack
{
public:

    Stack() :
    top_layer(NULL),
    m_size(0)
    {}

    void push(const stack_type new_val)
    {
        StackLayer* tmp = new StackLayer;
        tmp->val = new_val;
        tmp->nextLayer = top_layer;
        top_layer = tmp;
        m_size++;
    }

    void pop()
    {
        StackLayer* tmp = top_layer->nextLayer;
        delete top_layer;
        top_layer = tmp;
        m_size--;
    }

    stack_type top() const
    {
        return top_layer->val;
    } 

    int size() const { return m_size; }

    bool empty() const
    {
        if (m_size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~Stack()
    {
        while (top_layer != NULL)
        {
            StackLayer* tmp = top_layer;
            top_layer = top_layer->nextLayer;
            delete tmp;
        }
    }

    void test_stack_const_correctness(const Stack& s){
        s.top();
        s.size();
    }

private:
    int m_size;
    StackLayer* top_layer;
};

int main(){
 
    Stack s1;
 
    s1.push(1);
    s1.push(2);
 
    std::cout << s1.top() << std::endl;
    // should print 2
 
    s1.pop();
 
    std::cout << s1.top() << std::endl;
    // should print 1
 
    Stack s2(s1);
 
    s2.push(3);
 
    std::cout << s2.top() << std::endl;
    // should print 3
 
    std::cout << s2.size() << std::endl;
    // should print 2
 
    std::cout << s1.top() << std::endl;
    // should print 1
 
    s1 = s2;
 
    std::cout << s1.top() << std::endl;
    // should print 3
 
}

