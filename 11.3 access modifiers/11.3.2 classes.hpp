#include <iostream>

class Counter{

public:

  Counter(){
    c = 0;
  }

  Counter(int inic) : c(inic) {
    
  }

  void inc(){
    c++;
  }

  int getCount() const {
    return c;
  }

private: 

  int c;

};

int main(){
  Counter count(2);
  std::cout << count.getCount() << std::endl;
}