#include <iostream>
 
class Base{
 
public:
    virtual void b(){  
        b_pro = 1;
        b_pri = 2;
        std::cout << "b (in Base): " << b_pro << " " << b_pri << std::endl;
    }
 
    // destructor (marked as virtual and with no instructions)
    virtual ~Base(){ }
 
protected:
    int b_pro;
 
private:
    int b_pri;
};
 
class Derived : public Base {
 
public: 
 
    void b(){
        b_pro = 3;
        std::cout << "b (in Derived): " << b_pro << std::endl;
    }
 
    void d(){
        b_pro = 3;
        std::cout << "d: " << b_pro << std::endl;
    }
};
 
int main(){
    Base* bp;
    bp = new Derived;
 
    bp->b();
 
    delete bp;
    // this deallocation works properly only if there is a virtual destructor in Base
}