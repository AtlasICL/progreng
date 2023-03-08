#include <iostream>

class BaseClass{

public:

    void b(){
        b_protected = 1;
        b_private = 2;
    }

    void printBase(){
        std::cout << "  -- BaseClass --" << std::endl;
        std::cout << "b_protected = " << b_protected << std::endl;
        std::cout << "b_private = " << b_private << std::endl;
    }

protected:

    int b_protected;

private:

    int b_private;

};

class DerivedClass : public BaseClass{

public:

    void b(){
        b_protected = 18;
    }

    void printDerived(){
        std::cout << "  -- DerivedClass --" << std::endl;
        std::cout << "b_protected = " << b_protected << std::endl;
    }
};

void fcopy(BaseClass inb){
    inb.b();
}

void fref(BaseClass& inb){
    inb.b();
}

int main(){
    BaseClass ba;
    DerivedClass de;
 
    fcopy(ba);
 
    fcopy(de);
    // we can pass an argument of type Derived
    // to a parameter of type Base
    // because since Derived inherits from Base
    // Derive is a subtype of Base
 
    fref(ba);
 
    fref(de);
    // same as above
 
    BaseClass* bp;
 
    bp = &ba;
    bp->b();
 
    bp = &de;
    // for the same reason 
    // we can point to an object of type Derived
    // using a pointer to Base
 
    bp->b();
}