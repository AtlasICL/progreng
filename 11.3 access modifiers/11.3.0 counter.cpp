#include <iostream>

struct Counter{
 
    int c;
 
    Counter(){
        c = 0;
    }
 
    void inc(){
        c++;
    }
 
    int get_count() const {
        return c;
    }
 
};

int main(){
 
    Counter c1;
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
 
    std::cout << c1.get_count() << std::endl;
 
    c1.c = c1.c - 1;
 
    std::cout << c1.get_count() << std::endl;
 
    c1.c = -3;
 
    std::cout << c1.get_count() << std::endl;
 
} 