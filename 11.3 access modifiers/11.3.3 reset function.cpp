#include <iostream>

class Counter{

public:

  Counter() : c(0), initial_value(0) {
  }

  Counter(int inic) : c(inic), initial_value(inic) { 
  }

  void increment(){
    c++;
  }

  int getCount() const {
    return c;
  }

  int get_initial_value() const {
    return initial_value;
  }

  void reset() {
    c = 0;
  }

  void reset(int r) {
    c = r;
  }

  void reset_to_initial_value(){
    c = initial_value;
  }

private:

  int c;
  int initial_value;

};

int main(){

  Counter c1, c2(7), c3(4);
  std::cout << "c1 --> " << c1.getCount() << std::endl;
  std::cout << "c2 --> " << c2.getCount() << std::endl;
  std::cout << "c3 --> " << c3.getCount() << std::endl;

  std::cout << "--testing reset methods--\n";

  c1.reset(2);
  c2.reset();
  std::cout << "c1 --> " << c1.getCount() << std::endl;
  std::cout << "c2 --> " << c2.getCount() << std::endl;

  
  c3.increment();
  c3.increment();
  c3.increment();
  c3.increment(); 
  std::cout << "--testing reset to initial value on c3--\n";
  std::cout << "new c3 --> " << c3.getCount() << std::endl;
  c3.reset_to_initial_value();
  std::cout << "c3 after reset --> " << c3.getCount() << std::endl;
  
}