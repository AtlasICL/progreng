#include <iostream>
 
class BaseAbstract{
 
public:
    virtual void b() const = 0; 
    // = 0 is the syntax to indicate that the member function is pure virtual
    // (note that there is no implementation and not even { })
    // the function may or may not be const, in this case it is going to be
 
    virtual ~BaseAbstract(){ }
};
 
class DerivedFromAbstract : public BaseAbstract {
 
public: 
 
    void b() const {
        std::cout << "b in DFA" << std::endl;  
    }
 
};
 
void fref(const BaseAbstract& ba){// ok: we can have a reference to BaseAbstract
 
    ba.b();
}
 
int main(){
    // BaseAbstract ba; 
    // won't work: can't instantiate an object of type BaseAbstract
 
    DerivedFromAbstract dfa;
    dfa.b();
 
    fref(dfa);
 
    BaseAbstract* bp;
    // ok: we can declare a pointer to BaseAbstract
    bp = new DerivedFromAbstract;
 
    bp->b();
 
    delete bp;
}