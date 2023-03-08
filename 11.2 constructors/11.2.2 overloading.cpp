#include <iostream>

int f(){
  std::cout << "i got no params \n";
  return 0;
}

int f(int n){
  std::cout << "im a one int parammy papa flammy\n";
  return 0;
}

int f(double d){
  std::cout << "double ddddddddddouble\n";
  return 0;
}

int main(){
  int one = f(2.0);
}