#include <iostream>
#include <string>
 
void mswap(int& a, int& b){
    int t;
    t = a; 
    a = b;
    b = t;
}
 
void mswap(double& a, double& b){
    double t;
    t = a;
    a = b;
    b = t;
}
 
void mswap(std::string& a, std::string& b){
    std::string t;
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