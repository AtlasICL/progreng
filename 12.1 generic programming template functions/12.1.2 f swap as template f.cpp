#include <iostream>
#include <string>
 
// you may see "class T" instead of "typename T", it's the same
template<typename T>
void mswap(T& a, T& b){
    T t;
    t = a; 
    a = b;
    b = t;
}
 
int main(){
 
    int i1 = 0, i2 = 2;
    mswap(i1, i2);
    std::cout << i1 << " " << i2 << std::endl;
 
    double d1 = 1.5, d2 = 2.5;
    mswap(d1, d2);
    std::cout << d1 << " " << d2 << std::endl;
 
    std::string s1 = "hi", s2 = "bye";
    mswap(s1, s2);
    std::cout << s1 << " " << s2 << std::endl;
 
}