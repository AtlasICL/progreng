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

class DerivedClass : BaseClass{

public:

    void b(){
        b_protected = 18;
    }

    void printDerived(){
        std::cout << "  -- DerivedClass --" << std::endl;
        std::cout << "b_protected = " << b_protected << std::endl;
    }
};

int main(){

    BaseClass Base;
    DerivedClass Derived;

    Base.b();
    Base.printBase();

    Derived.b();
    Derived.printDerived();

}