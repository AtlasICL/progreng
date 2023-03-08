// when we have a pointer to a base
// BaseClass* bp;
// even if this pointer points to a DerivedClass,
// b() method from base will be called instead of 
// b() method from DerivedClass

#include <iostream>

class BaseClass{

public:

    virtual void b(){
        // virtual enables overriding of this function

        b_protected = 1;
        b_private = 2;

        std::cout << "--called base method--" << std::endl;
    }

protected:

    int b_protected;

private:

    int b_private;

};


class DerivedClass : public BaseClass{

public:

    void b(){
        b_protected = 7;
        std::cout << "--called derived method" << std::endl;
    }

};

int main(){

    BaseClass Base1, Base2;
    DerivedClass Derived;

    BaseClass* bp;
    bp = &Base2;

    Base1.b();

    bp->b();

    std::cout << "--changing bp to point to derived-- \n";

    bp = &Derived;

    bp->b();

}