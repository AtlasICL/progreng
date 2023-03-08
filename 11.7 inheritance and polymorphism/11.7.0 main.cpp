#include <iostream>

class Base{

public:

    void b(){
        b_protected = 1;
        b_private = 2;
        std::cout << "b_protected = " << b_protected << std::endl;
        std::cout << "b_private = " << b_private << std::endl;
    }

    int get_protected(){
        return b_protected;
    }

protected:

    int b_protected;

private:

    int b_private;

};

class Derived : public Base {

public: 

    void d(){
        b_protected = 3;
        std::cout << "d: b_protected = " << b_protected << std::endl;
    }
    
};

int main(){

    Base baseClass;
    Derived derived;

    baseClass.b();
    derived.d();

    std::cout << "--after changing--" << std::endl;
    std::cout << "b_protected = " << baseClass.get_protected() << std::endl;

    // conclusion: changing variable in derived class does not change that variable in parent class
    // makes sense if we think about multiple child classes inheriting from one common parent class

}