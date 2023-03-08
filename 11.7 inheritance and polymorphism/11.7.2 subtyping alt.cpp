#include <iostream>
 
class Base{
 
public:
    void b(){
        b_pro = 1;
        b_pri = 2;
        std::cout << "b (in Base): " << b_pro << " " << b_pri << std::endl;
    }
 
protected:
    int b_pro;
 
private:
    int b_pri;
};
 
class Derived : public Base {
 
public: 
 
    // redefinition of function b() in class Derived
    void b(){
        b_pro = 3;
 
        // b_pri = 4; 
        // won't work (b_pri private in Base)
 
        std::cout << "b (in Derived): " << b_pro << std::endl;
    }
 
    void d(){
        b_pro = 3;
        std::cout << "d: " << b_pro << std::endl;
    }
};

void fcopy(Base inb){
    inb.b();
}
 
void fref(Base& inb){
    inb.b();
}
 
int main(){
 
    Base ba;
    Derived de;
 
    fcopy(ba);
 
    fcopy(de);
    // we can pass an argument of type Derived
    // to a parameter of type Base
    // because since Derived inherits from Base
    // Derive is a subtype of Base
 
    fref(ba);
 
    fref(de);
    // same as above
 
    Base* bp;
 
    bp = &ba;
    bp->b();
 
    bp = &de;
    // for the same reason 
    // we can point to an object of type Derived
    // using a pointer to Base
 
    bp->b();
 
}